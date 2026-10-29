// ==== 0x5910f0 FUN_005910f0

undefined4 FUN_005910f0(float *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  float *unaff_EDI;
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
  undefined1 auStack_50 [76];
  
  puVar3 = (undefined4 *)(&DAT_007404a4)[*(int *)((int)param_1[0x28] + 0x18) * 0x18];
  if ((((puVar3 == &DAT_007404a4 + *(int *)((int)param_1[0x28] + 0x18) * 0x18) ||
       (puVar3 == (undefined4 *)0x0)) || (puVar3 + -1 == (int *)0x0)) ||
     ((puVar3[2] != 1 && (puVar3[2] != 0x11)))) {
    if (*DAT_0073619c == 4) {
      *unaff_EDI = *param_1;
      unaff_EDI[1] = param_1[1];
      return 1;
    }
    *unaff_EDI = *(float *)((int)param_1[0x27] + 0x90);
    unaff_EDI[1] = *(float *)((int)param_1[0x27] + 0x94);
  }
  else {
    iVar4 = puVar3[6];
    fVar1 = *(float *)(iVar4 + 0x54);
    fVar2 = *(float *)(iVar4 + 0x58);
    *unaff_EDI = *(float *)(iVar4 + 0x50);
    unaff_EDI[1] = fVar1;
    local_90 = 0x3f800000;
    local_8c = 0;
    unaff_EDI[2] = fVar2;
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
    (**(code **)(puVar3[-1] + 0x30))();
    FUN_0040b930();
    D3DXMatrixMultiply(&local_90,&local_90,auStack_50);
    D3DXVec3Transform();
    if ((ABS(*param_1) < 0.001 != (ABS(*param_1) == 0.001)) &&
       (ABS(param_1[1]) < 0.001 != (ABS(param_1[1]) == 0.001))) {
      *param_1 = *unaff_EDI;
      param_1[1] = unaff_EDI[1];
      param_1[4] = DAT_0073ad34;
      return 1;
    }
  }
  return 1;
}


// ==== 0x5912b0 TrackMap::InitModeTable

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void TrackMap__InitModeTable(void)

{
  _DAT_0073788c = 0xd57a;
  _DAT_00737890 = 0x43480000;
  _DAT_00737894 = 0;
  _DAT_00737898 = 0xc1a00000;
  _DAT_0073789c = 0x42140000;
  _DAT_007378a0 = 0x42960000;
  _DAT_007378a4 = 0x3f106339;
  _DAT_007378a8 = 0x3e9145fa;
  DAT_007378ac = 0;
  _DAT_007378b0 = 0x3dc461fa;
  _DAT_007378b4 = 0x3ccccab4;
  _DAT_007378b8 = 0x3e0a3c21;
  DAT_007378bc = 1;
  DAT_007378bd = 1;
  DAT_007378be = 1;
  _DAT_007378c0 = 0x3e4ccccd;
  DAT_007378c4 = 1;
  DAT_007378c5 = 0;
  _DAT_007378c8 = 0xd5da;
  _DAT_007378cc = 0x43480000;
  _DAT_007378d0 = 0;
  _DAT_007378d4 = 0xc1400000;
  _DAT_007378d8 = 0x41cc0000;
  _DAT_007378dc = 0x42456d5d;
  _DAT_007378e0 = 0x3ee2311f;
  _DAT_007378e4 = 0x3e4ee782;
  DAT_007378e8 = 0;
  _DAT_007378ec = 0x3dc461fa;
  _DAT_007378f0 = 0x3d0f51ad;
  _DAT_007378f4 = 0x3e2e1112;
  DAT_007378f8 = 0;
  DAT_007378f9 = 1;
  DAT_007378fa = 1;
  _DAT_007378fc = 0x3e4ccccd;
  DAT_00737900 = 1;
  DAT_00737901 = 0;
  _DAT_00737904 = 0xffff;
  _DAT_00737908 = 0x43480000;
  _DAT_0073790c = 0;
  _DAT_00737910 = 0;
  _DAT_00737914 = 0x41f00000;
  _DAT_00737918 = 0x41f00000;
  _DAT_0073791c = 0x3ea8f5c3;
  _DAT_00737920 = 0x3ea8f5c3;
  DAT_00737924 = 0;
  _DAT_00737928 = 0x3dcccccd;
  _DAT_0073792c = 0x3d23c42a;
  _DAT_00737930 = 0x3e3d6b66;
  DAT_00737934 = 1;
  DAT_00737935 = 1;
  DAT_00737936 = 1;
  _DAT_00737938 = 0x3e4ccccd;
  DAT_0073793c = 1;
  DAT_0073793d = 0;
  _DAT_00737940 = 0xffff;
  _DAT_00737944 = 0x43480000;
  _DAT_00737948 = 0;
  _DAT_0073794c = 0;
  _DAT_00737950 = 0x41700000;
  _DAT_00737954 = 0x41700000;
  _DAT_00737958 = 0x3ea8f5c3;
  _DAT_0073795c = 0x3ea8f5c3;
  DAT_00737960 = 0;
  _DAT_00737964 = 0x3dcccccd;
  _DAT_00737968 = 0x3d23c212;
  _DAT_0073796c = 0x3e47a850;
  DAT_00737970 = 0;
  DAT_00737971 = 1;
  DAT_00737972 = 1;
  _DAT_00737974 = 0x3e4ccccd;
  DAT_00737978 = 1;
  DAT_00737979 = 0;
  _DAT_00737850 = 0xffff;
  _DAT_00737854 = 0x43480000;
  _DAT_00737858 = 0;
  _DAT_0073785c = 0;
  _DAT_00737860 = 0x43160000;
  _DAT_00737864 = 0;
  _DAT_00737868 = 0x3f800000;
  _DAT_0073786c = 0x3f800000;
  DAT_00737870 = 0;
  _DAT_00737874 = 0x3d8f5c29;
  _DAT_00737878 = 0x3d3839ce;
  _DAT_0073787c = 0x3e199243;
  DAT_00737880 = 0;
  DAT_00737881 = 0;
  DAT_00737882 = 0;
  _DAT_00737884 = 0x3f800000;
  DAT_00737888 = 1;
  DAT_00737889 = 0;
  _DAT_0073797c = 0xffff;
  _DAT_00737980 = 0x43480000;
  _DAT_00737984 = 0;
  _DAT_00737988 = 0;
  _DAT_0073798c = 0;
  _DAT_00737990 = 0;
  _DAT_00737994 = 0x3f800000;
  _DAT_00737998 = 0x3f800000;
  DAT_0073799c = 0;
  _DAT_007379a0 = 0x3d75c28f;
  _DAT_007379a4 = 0x3cf5c28f;
  _DAT_007379a8 = 0x3dc28f5c;
  DAT_007379ac = 0;
  DAT_007379ad = 0;
  DAT_007379ae = 1;
  _DAT_007379b0 = 0x3e947ae1;
  DAT_007379b4 = 1;
  DAT_007379b5 = 0;
  _DAT_007379f4 = 0xffff;
  _DAT_007379f8 = 0x43480000;
  _DAT_007379fc = 0;
  _DAT_00737a00 = 0;
  _DAT_00737a04 = 0;
  _DAT_00737a08 = 0;
  _DAT_00737a0c = 0x3f800000;
  _DAT_00737a10 = 0x3f800000;
  DAT_00737a14 = 0;
  _DAT_00737a18 = 0x3d8f5c29;
  _DAT_00737a1c = 0x3d3839ce;
  _DAT_00737a20 = 0x3e199243;
  DAT_00737a24 = 0;
  DAT_00737a25 = 0;
  DAT_00737a26 = 0;
  _DAT_00737a28 = 0x3e4ccccd;
  DAT_00737a2c = 1;
  DAT_00737a2d = 0;
  _DAT_00737a30 = 0xffff;
  _DAT_00737a34 = 0x43480000;
  _DAT_00737a38 = 0;
  _DAT_00737a3c = 0;
  _DAT_00737a40 = 0;
  _DAT_00737a44 = 0;
  _DAT_00737a48 = 0x3f800000;
  _DAT_00737a4c = 0x3f800000;
  DAT_00737a50 = 0;
  _DAT_00737a54 = 0x3d8f5c29;
  _DAT_00737a58 = 0x3d3839ce;
  _DAT_00737a5c = 0x3e199243;
  DAT_00737a60 = 0;
  DAT_00737a61 = 0;
  DAT_00737a62 = 0;
  _DAT_00737a64 = 0x3e4ccccd;
  DAT_00737a68 = 1;
  DAT_00737a69 = 0;
  _DAT_00737a6c = 0xffff;
  _DAT_00737a70 = 0x43480000;
  _DAT_00737a74 = 0;
  _DAT_00737a78 = 0;
  _DAT_00737a7c = 0;
  _DAT_00737a80 = 0;
  _DAT_00737a84 = 0x3f800000;
  _DAT_00737a88 = 0x3f800000;
  DAT_00737a8c = 0;
  _DAT_00737a90 = 0x3d75c28f;
  _DAT_00737a94 = 0x3cf5c28f;
  _DAT_00737a98 = 0x3dc28f5c;
  DAT_00737a9c = 0;
  DAT_00737a9d = 0;
  DAT_00737a9e = 1;
  DAT_00737aa4 = 1;
  DAT_00737ac8 = 1;
  DAT_00737ad8 = 1;
  DAT_00737ad9 = 1;
  DAT_00737ada = 1;
  DAT_00737ae0 = 1;
  DAT_00737b16 = 1;
  DAT_00737b1c = 1;
  _DAT_00737aa8 = 0xffff;
  _DAT_00737ae4 = 0xffff;
  DAT_007313d9 = 0xff;
  DAT_007313f1 = 0xff;
  DAT_007313dc = 0xff;
  DAT_007313df = 0xff;
  _DAT_00737aa0 = 0x3e947ae1;
  DAT_00737aa5 = 0;
  _DAT_00737aac = 0x43480000;
  _DAT_00737ab0 = 0;
  _DAT_00737ab4 = 0;
  _DAT_00737ab8 = 0x41f00000;
  _DAT_00737abc = 0x41f00000;
  _DAT_00737ac0 = 0x3ea8f5c3;
  _DAT_00737ac4 = 0x3ea8f5c3;
  _DAT_00737acc = 0x3dcccccd;
  _DAT_00737ad0 = 0x3d23c42a;
  _DAT_00737ad4 = 0x3e3d6b66;
  _DAT_00737adc = 0x3e4ccccd;
  DAT_00737ae1 = 0;
  _DAT_00737ae8 = 0x43480000;
  _DAT_00737aec = 0;
  _DAT_00737af0 = 0;
  _DAT_00737af4 = 0x42c80000;
  _DAT_00737af8 = 0;
  _DAT_00737afc = 0;
  _DAT_00737b00 = 0;
  DAT_00737b04 = 0;
  _DAT_00737b08 = 0x3d75c28f;
  _DAT_00737b0c = 0x3d23c42a;
  _DAT_00737b10 = 0x3e3d6b66;
  DAT_00737b14 = 0;
  DAT_00737b15 = 0;
  _DAT_00737b18 = 0x3f800000;
  DAT_00737b1d = 0;
  _DAT_007379b8 = 0;
  _DAT_007379bc = 0;
  _DAT_007379c0 = 0;
  _DAT_007379c4 = 0;
  _DAT_007379c8 = 0;
  _DAT_007379cc = 0;
  _DAT_007379d0 = 0;
  _DAT_007379d4 = 0;
  DAT_007379d8 = 0;
  _DAT_007379dc = 0;
  _DAT_007379e0 = 0;
  _DAT_007379e4 = 0;
  DAT_007379e8 = 0;
  DAT_007379e9 = 0;
  DAT_007379ea = 0;
  _DAT_007379ec = 0;
  DAT_007379f0 = 0;
  DAT_007379f1 = 0;
  DAT_007313d4 = 0xac;
  DAT_007313d5 = 0x35;
  DAT_007313d6 = 0;
  DAT_007313d7 = 0x4b;
  DAT_007313d8 = 0x55;
  DAT_007313ef = 0x4b;
  DAT_007313f0 = 0x55;
  DAT_007313da = 0;
  DAT_007313db = 0;
  DAT_007313dd = 0;
  DAT_007313de = 0x42;
  DAT_007313e0 = 0;
  DAT_007313e1 = 0;
  DAT_007313e2 = 0x80;
  DAT_007313ec = 0;
  DAT_007313ed = 0;
  DAT_007313ee = 0xc0;
  DAT_007313e3 = 0x80;
  DAT_007313e4 = 0x80;
  DAT_007313e5 = 0;
  DAT_007313e6 = 0x84;
  DAT_007313e7 = 0xa9;
  DAT_007313e8 = 0xeb;
  DAT_007313e9 = 0;
  DAT_007313ea = 0x40;
  DAT_007313eb = 0x7a;
  return;
}


// ==== 0x5919b0 FUN_005919b0

int __fastcall FUN_005919b0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_006f03e8)[iVar1] == param_1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return -1;
}


// ==== 0x5919d0 FUN_005919d0

void __thiscall FUN_005919d0(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar1 = *in_EAX;
  param_2 = param_2 - *param_1;
  fVar3 = (fVar1 - param_2) - param_2;
  fVar2 = (param_2 * 3.0 - fVar1) - fVar1;
  *param_1 = ((fVar3 * param_3 + fVar2) * param_3 + fVar1) * param_3 + *param_1;
  *in_EAX = (fVar2 + fVar2 + fVar3 * 3.0 * param_3) * param_3 + fVar1;
  return;
}


// ==== 0x591a40 FUN_00591a40

void FUN_00591a40(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  FUN_005740b0(0x74);
  if ((*(int *)(unaff_ESI + 0x208c) != 0) || (*(int *)(unaff_ESI + 0x2090) != 0)) {
    iVar1 = *(int *)(unaff_ESI + 0x2084);
    piVar2 = *(int **)(unaff_ESI + 0x2088);
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x208c) = 0;
  *(undefined4 *)(unaff_ESI + 0x2090) = 0;
  *(undefined4 *)(unaff_ESI + 0x2094) = 0;
  *(undefined4 *)(unaff_ESI + 0x2098) = 0;
  if ((*(int *)(unaff_ESI + 0x20a4) != 0) || (*(int *)(unaff_ESI + 0x20a8) != 0)) {
    iVar1 = *(int *)(unaff_ESI + 0x209c);
    piVar2 = *(int **)(unaff_ESI + 0x20a0);
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x20a4) = 0;
  *(undefined4 *)(unaff_ESI + 0x20a8) = 0;
  *(undefined4 *)(unaff_ESI + 0x20ac) = 0;
  *(undefined4 *)(unaff_ESI + 0x20b0) = 0;
  if ((*(int *)(unaff_ESI + 0x20bc) != 0) || (*(int *)(unaff_ESI + 0x20c0) != 0)) {
    iVar1 = *(int *)(unaff_ESI + 0x20b4);
    piVar2 = *(int **)(unaff_ESI + 0x20b8);
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x20bc) = 0;
  *(undefined4 *)(unaff_ESI + 0x20c0) = 0;
  *(undefined4 *)(unaff_ESI + 0x20c4) = 0;
  *(undefined4 *)(unaff_ESI + 0x20c8) = 0;
  if ((*(int *)(unaff_ESI + 0x20d4) != 0) || (*(int *)(unaff_ESI + 0x20d8) != 0)) {
    iVar1 = *(int *)(unaff_ESI + 0x20cc);
    piVar2 = *(int **)(unaff_ESI + 0x20d0);
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x20d8) = 0;
  *(undefined4 *)(unaff_ESI + 0x20d4) = 0;
  *(undefined4 *)(unaff_ESI + 0x20dc) = 0;
  *(undefined4 *)(unaff_ESI + 0x20e0) = 0;
  eh_vector_destructor_iterator((int *)(unaff_ESI + 0x2084),0x18,4,ListRef_Release);
  return;
}


// ==== 0x591b40 FUN_00591b40

bool FUN_00591b40(undefined4 param_1)

{
  int iVar1;
  
  Solid_GetBounds();
  iVar1 = AABB_ClassifyAgainstFrustum(param_1);
  return iVar1 != 0;
}


// ==== 0x591b80 FUN_00591b80

void FUN_00591b80(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  iVar2 = FUN_00567160();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004454d0();
  }
  unaff_ESI[2] = uVar3;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 1;
  unaff_ESI[5] = 1;
  unaff_ESI[6] = 0;
  unaff_ESI[0x18] = unaff_EBX;
  *(int *)(unaff_EBX + 0xd8) = *(int *)(unaff_EBX + 0xd8) + 1;
  *DAT_00737820 = unaff_ESI;
  puVar1 = unaff_ESI;
  unaff_ESI[1] = DAT_00737820;
  DAT_00737820 = puVar1;
  *(undefined1 *)(unaff_ESI + 7) = param_2;
  *unaff_ESI = &DAT_0073781c;
  return;
}


// ==== 0x591bf0 FUN_00591bf0

void FUN_00591bf0(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  
  iVar2 = FUN_00567160();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004454d0();
  }
  unaff_ESI[2] = uVar3;
  unaff_ESI[3] = 0;
  if (*(int *)(param_2 + 0xc) != 0) {
    iVar2 = FUN_00567160();
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004454d0();
    }
    unaff_ESI[3] = uVar3;
  }
  unaff_ESI[0x18] = param_1;
  unaff_ESI[4] = 1;
  unaff_ESI[5] = 1;
  unaff_ESI[6] = 0;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
  *DAT_00737820 = unaff_ESI;
  puVar1 = unaff_ESI;
  unaff_ESI[1] = DAT_00737820;
  DAT_00737820 = puVar1;
  *(undefined1 *)(unaff_ESI + 7) = param_3;
  *unaff_ESI = &DAT_0073781c;
  return;
}


// ==== 0x591c90 FUN_00591c90

void FUN_00591c90(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_0073557c;
  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 != (undefined4 *)0x0) {
    ListRef_Release();
    iVar2 = *(int *)(iVar3 + 0x18);
    *puVar1 = *(undefined4 *)(iVar3 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar1;
  }
  puVar1 = (undefined4 *)param_1[3];
  if (puVar1 != (undefined4 *)0x0) {
    ListRef_Release();
    iVar2 = *(int *)(iVar3 + 0x18);
    *puVar1 = *(undefined4 *)(iVar3 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar1;
  }
  if (param_1[0x18] != 0) {
    FUN_00579140();
  }
  iVar3 = *param_1;
  piVar4 = (int *)param_1[1];
  *piVar4 = iVar3;
  *(int **)(iVar3 + 4) = piVar4;
  return;
}


// ==== 0x591d00 FUN_00591d00

bool __fastcall FUN_00591d00(int param_1)

{
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (param_1 != 0) {
    *DAT_00743c74 = &local_18;
    local_14 = DAT_00743c74;
    local_18 = &DAT_00743c70;
    DAT_00743c74 = &local_18;
    if (param_1 != 0) {
      DAT_00743c74 = &local_18;
      local_10 = param_1;
      Solid_FindInAllLists();
      FUN_0053f4b0();
      param_1 = local_10;
    }
  }
  if ((param_1 != 0) || (local_c != 0)) {
    *local_14 = local_18;
    local_18[1] = local_14;
  }
  return local_c != 0;
}


// ==== 0x591d90 FUN_00591d90

void FUN_00591d90(void)

{
  undefined4 *puVar1;
  
  DAT_007344c8 = (undefined4 *)FUN_00566dc0(0x70,"WorldModelSlotPool",0);
  if (DAT_007344c8 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007344c8;
    puVar1 = DAT_007344c8;
    DAT_007344c8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344c8 = &DAT_0073d818;
  }
  return;
}


// ==== 0x591de0 FUN_00591de0

void FUN_00591de0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = DAT_007344c8;
  puVar3 = DAT_0073781c;
  if ((undefined4 **)DAT_0073781c != &DAT_0073781c) {
    do {
      if (puVar3 != (undefined4 *)0x0) {
        FUN_00591c90(puVar3);
        iVar1 = *(int *)(iVar2 + 0x18);
        *puVar3 = *(undefined4 *)(iVar2 + 0x10);
        *(int *)(iVar2 + 0x18) = iVar1 + -1;
        *(undefined4 **)(iVar2 + 0x10) = puVar3;
        puVar3 = DAT_0073781c;
      }
    } while ((undefined4 **)puVar3 != &DAT_0073781c);
  }
  SlotPool__Destroy();
  DAT_007344c8 = 0;
  return;
}


// ==== 0x591e40 FUN_00591e40

void FUN_00591e40(int param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  float *local_cc;
  float *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 auStack_90 [48];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 local_50 [76];
  
  iVar4 = *(int *)(param_1 + 8);
  iVar5 = 0;
  local_a4 = in_EAX & 0x800;
  local_c8 = (float *)0x0;
  local_cc = (float *)0x0;
  if ((local_a4 != 0) && (iVar4 = *(int *)(param_1 + 0xc), iVar4 == 0)) {
    return;
  }
  if (iVar4 == 0) {
    return;
  }
  if (*(int *)(iVar4 + 0xc) == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0xe4) != 0) {
      FUN_005791c0();
    }
    iVar5 = *(int *)(*(int *)(param_1 + 0x60) + 0xe8);
    if (DAT_00700e8c == 0) {
      if (iVar5 != 0) {
        return;
      }
    }
    else if (iVar5 != 0) {
      D3DXMatrixMultiply(local_50,iVar5 + 0x40,iVar2 + 0x10);
      goto LAB_00591ef7;
    }
  }
  bMatrixCopy_b();
LAB_00591ef7:
  iVar2 = eView__CalcSphereScreenSize(0x420c0000);
  if ((1 < iVar2) && (iVar2 = FUN_00591b40(param_2,local_50), iVar2 != 0)) {
    if (iVar5 != 0) {
      iVar2 = *(int *)(iVar4 + 0xc);
      local_c8 = (float *)(iVar2 + 0x20);
      local_cc = (float *)(iVar2 + 0x30);
      *local_c8 = *(float *)(iVar2 + 0x20) + *(float *)(iVar5 + 0x70);
      *local_cc = *local_cc + *(float *)(iVar5 + 0x70);
      *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x24) + *(float *)(iVar5 + 0x74);
      *(float *)(iVar2 + 0x34) = *(float *)(iVar5 + 0x74) + *(float *)(iVar2 + 0x34);
      *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) + *(float *)(iVar5 + 0x78);
      *(float *)(iVar2 + 0x38) = *(float *)(iVar5 + 0x78) + *(float *)(iVar2 + 0x38);
    }
    puVar3 = (undefined1 *)ScratchAlloc16();
    if (puVar3 != (undefined1 *)0x0) {
      bMatrixCopy_b();
      if (local_a4 != 0) {
        *(float *)(puVar3 + 0x28) = -*(float *)(puVar3 + 0x28);
      }
      if (*(char *)(param_1 + 0x1c) == '\0') {
        iVar2 = 0;
      }
      else {
        iVar2 = ScratchAlloc16();
        if (iVar2 == 0) {
          return;
        }
        iVar1 = *(int *)(param_2 + 0x40);
        local_a0 = *(undefined4 *)(iVar1 + 0x40);
        local_9c = *(undefined4 *)(iVar1 + 0x44);
        local_98 = *(undefined4 *)(iVar1 + 0x48);
        local_94 = 0x3f800000;
        puVar6 = puVar3;
        if (iVar5 != 0) {
          local_bc = *(undefined4 *)(iVar5 + 0x74);
          local_c0 = *(undefined4 *)(iVar5 + 0x70);
          local_b8 = *(undefined4 *)(iVar5 + 0x78);
          local_b4 = *(undefined4 *)(iVar5 + 0x7c);
          thunk_FUN_005ac436(&local_c0,&local_c0,puVar3);
          bMatrixCopy_b();
          uStack_5c = local_bc;
          uStack_60 = local_c0;
          uStack_58 = local_b8;
          uStack_54 = local_b4;
          puVar6 = auStack_90;
        }
        CarRender_LitBodyPathA(iVar2,puVar6,iVar1,&local_a0,param_2);
      }
      FUN_0040c910(param_2,iVar4,puVar3,iVar2,iVar5);
    }
    if (iVar5 != 0) {
      *local_c8 = *local_c8 - *(float *)(iVar5 + 0x70);
      *local_cc = *local_cc - *(float *)(iVar5 + 0x70);
      local_c8[1] = local_c8[1] - *(float *)(iVar5 + 0x74);
      local_cc[1] = local_cc[1] - *(float *)(iVar5 + 0x74);
      local_c8[2] = local_c8[2] - *(float *)(iVar5 + 0x78);
      local_cc[2] = local_cc[2] - *(float *)(iVar5 + 0x78);
    }
  }
  return;
}


// ==== 0x592100 RenderWorldModels

/* [canon] render V (G+C) docs/re/blur.md */

void RenderWorldModels(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  undefined1 local_80 [48];
  undefined1 local_50 [76];
  
  puVar1 = DAT_0073781c;
  bVar4 = DAT_007364a0 != 3;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return;
    }
    if ((puVar1[4] != 0) && ((bVar4 || (puVar1[5] != 0)))) {
      if (puVar1[6] != 0) {
        bMatrix4_SetRotationAndTranslation();
        Matrix_InvertRigid();
        Solid_GetBounds();
        D3DXVec3Transform(local_80,*(int *)(param_1 + 0x40) + 0x40,local_50);
        iVar3 = FUN_00567940(0);
        if (iVar3 != 0) goto LAB_005921d4;
      }
      FUN_00591e40(puVar1,param_1);
    }
LAB_005921d4:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x5921f0 FUN_005921f0

void FUN_005921f0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_007344c8;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00591c90(piVar1);
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x592230 SurfaceTable::Init

/* [canon] props med (hopper+ghidra) docs/re/props.md */

undefined4 SurfaceTable__Init(undefined4 param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = &DAT_006ef2d4;
  do {
    pbVar3 = (byte *)piVar5[-1];
    iVar4 = -1;
    bVar2 = *pbVar3;
    while (bVar2 != 0) {
      iVar4 = iVar4 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar3 + 1;
      pbVar3 = pbVar3 + 1;
      bVar2 = *pbVar1;
    }
    *piVar5 = iVar4;
    piVar5 = piVar5 + 0x25;
  } while ((int)piVar5 < 0x6f0398);
  return param_1;
}


// ==== 0x592270 FUN_00592270

void __fastcall FUN_00592270(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00592278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x140) + 0x10))();
  return;
}


// ==== 0x592280 WorldObject_ctor

/* [canon] props med (hopper+capstone) docs/re/misc.md */

undefined4 * WorldObject_ctor(undefined4 *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685ef5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CollisionBody__CollisionBody(param_1,4);
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  param_1[0x19] = param_1 + 0x51;
  DAT_00736010 = DAT_00736010 + 1;
  if (DAT_00736038 < DAT_00736010) {
    DAT_00736038 = DAT_00736010;
  }
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 1;
  param_1[0x18] = 0;
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_006b8d88;
  local_4 = 0;
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  param_1[0xfb] = 0;
  param_1[0xfc] = 0;
  param_1[0xfe] = 0;
  param_1[0xff] = 0;
  param_1[0x100] = 0;
  FUN_00440740();
  DAT_0073601c = DAT_0073601c + 1;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (DAT_00736044 < DAT_0073601c) {
    DAT_00736044 = DAT_0073601c;
  }
  pcVar3 = (char *)(param_1 + 0xd);
  param_1[0x50] = param_2;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  param_1[0x102] = 0;
  iVar7 = 0x28;
  iVar8 = (int)"World Object" - (int)pcVar3;
  do {
    cVar1 = pcVar3[iVar8];
    iVar7 = iVar7 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar7 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  puVar2 = DAT_00779bd8;
  puVar4 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar4) {
      param_1[0x101] = 1;
      pvVar5 = _malloc(0x40);
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        *(code **)((int)pvVar5 + 8) = FUN_00473dd0;
        *(code **)((int)pvVar5 + 0xc) = FUN_00473d60;
        *(undefined4 *)((int)pvVar5 + 0x10) = 3;
        *(undefined4 *)((int)pvVar5 + 0x14) = 8;
        uVar6 = CollisionShapes__DefaultBox
                          (0xc00de354,0xbf789375,0xbe4ccccd,0x400a8f5c,0x3f789375,0x3f1fbe77);
      }
      param_1[4] = uVar6;
LAB_00592414:
      DynamicCollisionBody__BuildBoundingVolumes();
      DynamicCollisionBody__UpdatePosition();
      ExceptionList = local_c;
      return param_1;
    }
    if (puVar2[6] == param_3) {
      param_1[0x101] = 0;
      param_1[4] = puVar2;
      goto LAB_00592414;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// ==== 0x592440 FUN_00592440

undefined4 * __thiscall FUN_00592440(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00592610();
  iVar2 = DAT_0072cbf8;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_0072cbf8 + 0x18);
    *param_1 = *(undefined4 *)(DAT_0072cbf8 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x592470 FUN_00592470

undefined4 * FUN_00592470(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00685ecb;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CollisionBody__CollisionBody(param_1,4);
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  param_1[0x19] = param_1 + 0x51;
  DAT_00736010 = DAT_00736010 + 1;
  if (DAT_00736038 < DAT_00736010) {
    DAT_00736038 = DAT_00736010;
  }
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 1;
  param_1[0x18] = 0;
  param_1[0x4c] = 0;
  *param_1 = &PTR_FUN_006b8d88;
  local_14 = 0;
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  param_1[0xfb] = 0;
  param_1[0xfc] = 0;
  param_1[0xfe] = 0;
  param_1[0xff] = 0;
  param_1[0x100] = 0;
  FUN_00440740();
  DAT_0073601c = DAT_0073601c + 1;
  local_14 = CONCAT31(local_14._1_3_,1);
  if (DAT_00736044 < DAT_0073601c) {
    DAT_00736044 = DAT_0073601c;
  }
  param_1[0x50] = param_2;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x102] = 0;
  pcVar2 = (char *)(param_1 + 0xd);
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  iVar6 = 0x28;
  iVar5 = (int)"World Object" - (int)pcVar2;
  do {
    cVar1 = pcVar2[iVar5];
    iVar6 = iVar6 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
  } while (iVar6 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  Solid_GetBounds();
  pvVar3 = _malloc(0x40);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    *(code **)((int)pvVar3 + 8) = FUN_00473dd0;
    *(code **)((int)pvVar3 + 0xc) = FUN_00473d60;
    *(undefined4 *)((int)pvVar3 + 0x10) = 3;
    *(undefined4 *)((int)pvVar3 + 0x14) = 8;
    uVar4 = CollisionShapes__DefaultBox(local_40,local_3c,local_38,local_30,local_2c,local_28);
  }
  param_1[4] = uVar4;
  DynamicCollisionBody__BuildBoundingVolumes();
  DynamicCollisionBody__UpdatePosition();
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x592610 FUN_00592610

void FUN_00592610(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006b8d88;
  DAT_0073601c = DAT_0073601c + -1;
  if ((unaff_ESI[0x101] != 0) && ((void *)unaff_ESI[4] != (void *)0x0)) {
    _free((void *)unaff_ESI[4]);
  }
  iVar3 = unaff_ESI[0xf9];
  if (0 < iVar3) {
    piVar2 = unaff_ESI + 0x59;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  *unaff_ESI = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  DAT_00736010 = DAT_00736010 + -1;
  CollisionBody___CollisionBody();
  return;
}


// ==== 0x592670 FUN_00592670

void __thiscall FUN_00592670(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = param_2;
  FUN_00571ea0(param_1,"WorldObjectCollisionBody");
  DynamicCollisionBody__DoSnapshot(iVar2);
  param_2 = *(undefined4 *)(*(int *)(param_1 + 0x140) + 0x10);
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,&param_2,4,4,1);
  }
  if (*(char *)(iVar2 + 0x3d) != '\0') {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    if (*(int *)(param_1 + 0x60) != 0) {
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
  }
  if (*(char *)(iVar2 + 0x3c) != '\0' || *(char *)(iVar2 + 0x3d) != '\0') {
    DynamicCollisionBody__UpdatePosition();
  }
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,param_1 + 0x24,8,0xffffffff,0);
  }
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,param_1 + 0x2c,8,0xffffffff,0);
  }
  iVar1 = *(char *)(iVar2 + 0x40) * 0x10 + 0x4c + iVar2;
  *(int *)(iVar1 + 0xc) = *(int *)(iVar2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar3 = *(char *)(iVar2 + 0x40) + -1;
  *(char *)(iVar2 + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(iVar2 + 0x44)) {
    *(undefined4 *)(iVar2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x592750 FUN_00592750

void __fastcall FUN_00592750(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00592758. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x140) + 0x1c))();
  return;
}


// ==== 0x592760 FUN_00592760

void __fastcall FUN_00592760(int param_1)

{
  *(undefined1 *)(param_1 + 0x1d) = 1;
  return;
}


// ==== 0x592770 FUN_00592770

void __thiscall FUN_00592770(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  DynamicCollisionBody__BeginMove(param_2);
  if (*(int *)(param_1 + 0x408) == 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x140) + 0x20);
    if (piVar1 == (int *)0x0) goto LAB_005927b0;
  }
  else {
    *(undefined4 *)(param_1 + 0x408) = 0;
    piVar1 = *(int **)(*(int *)(param_1 + 0x140) + 0x20);
    if (piVar1 == (int *)0x0) goto LAB_005927b0;
    param_2 = 0;
  }
  (**(code **)(*piVar1 + 4))(param_2);
LAB_005927b0:
  if (DAT_00736200 == 0) {
    DynamicCollisionBody__UpdatePosition();
  }
  return;
}


// ==== 0x5927d0 WorldObject::CanCollide

/* [canon] props med (capstone) docs/re/props.md */

bool __fastcall WorldObject__CanCollide(int param_1)

{
  return *(char *)(param_1 + 0x1b) == '\0';
}


// ==== 0x5927e0 FUN_005927e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_005927e0(int param_1)

{
  float10 fVar1;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    return (float10)0.0;
  }
  fVar1 = (float10)*(float *)(*(int *)(param_1 + 0x6c) + 0x148);
  if ((float10)(_K_ONE / 0.3) < fVar1) {
    fVar1 = (float10)(_K_ONE / 0.3);
  }
  return fVar1;
}


// ==== 0x592820 FUN_00592820

undefined4 * __fastcall FUN_00592820(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    return &DAT_00779c30;
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (*(int *)(iVar1 + 0x138) != 0) {
    return (undefined4 *)(iVar1 + 400);
  }
  return (undefined4 *)(iVar1 + 0x150);
}


// ==== 0x592850 FUN_00592850

int __fastcall FUN_00592850(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0x20;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x140) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return iVar1 + 0x40;
}


// ==== 0x592880 FUN_00592880

int __fastcall FUN_00592880(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xa0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x140) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return iVar1 + 0x90;
}


// ==== 0x5928c0 FUN_005928c0

undefined4 * __fastcall FUN_005928c0(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return (undefined4 *)(*(int *)(param_1 + 0x6c) + 0xb0);
  }
  return &DAT_007372a0;
}


// ==== 0x5928e0 FUN_005928e0

int __fastcall FUN_005928e0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0x30;
  }
  iVar1 = FUN_00578730();
  return iVar1;
}


// ==== 0x592900 FUN_00592900

int __fastcall FUN_00592900(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xc0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x140) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return iVar1 + 0xb0;
}


// ==== 0x592940 FUN_00592940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00592940(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    FUN_00584e30();
  }
  return;
}


// ==== 0x5929c0 FUN_005929c0

void __thiscall
FUN_005929c0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_50 [48];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  *(undefined4 *)(param_1 + 0x408) = 1;
  bMatrixCopy_b();
  local_20 = *param_3;
  local_1c = param_3[1];
  local_18 = param_3[2];
  FUN_00579310(local_50);
  iVar3 = *(int *)(*(int *)(param_1 + 0x140) + 0x1c);
  uVar1 = param_5[1];
  uVar2 = param_5[2];
  *(undefined4 *)(iVar3 + 0x90) = *param_5;
  *(undefined4 *)(iVar3 + 0x94) = uVar1;
  *(undefined4 *)(iVar3 + 0x98) = uVar2;
  if (*(int *)(iVar3 + 0xe4) == 0) {
    FUN_00579190();
  }
  return;
}


// ==== 0x592a50 Table34300::Loader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_592a50 + Ghidra make FUN_00592a50: H+G agree) docs/re/assets.md
    */

undefined4 Table34300__Loader(int *param_1)

{
  if (*param_1 == 0x34301) {
    _DAT_007344b8 = param_1 + 2;
    _DAT_007344bc = (uint)param_1[1] / 0xb4;
    return 1;
  }
  if (*param_1 == 0x34300) {
    _DAT_007344c0 = param_1 + 2;
    _DAT_007344c4 = (uint)param_1[1] / 0x44;
    return 1;
  }
  return 0;
}


// ==== 0x592ab0 Table34300::Unloader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_592ab0 + Ghidra make: H+G agree) docs/re/assets.md */

undefined4 Table34300__Unloader(int *param_1)

{
  if (*param_1 == 0x34301) {
    _DAT_007344b8 = 0;
    _DAT_007344bc = 0;
    return 1;
  }
  if (*param_1 == 0x34300) {
    _DAT_007344c0 = 0;
    _DAT_007344c4 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x592af0 FUN_00592af0

void FUN_00592af0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = in_EAX + 0x1c;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x20) = iVar1;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0xbf800000;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined1 *)(in_EAX + 0x24) = 0;
  return;
}


// ==== 0x592b20 FUN_00592b20

void FUN_00592b20(void)

{
  FUN_00593700();
  return;
}


// ==== 0x592b30 FUN_00592b30

void FUN_00592b30(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)param_1[7];
  iVar4 = DAT_0072cc04;
  if (piVar6 != param_1 + 7) {
    do {
      piVar1 = (int *)*piVar6;
      if ((char)piVar6[3] == '\0') {
        puVar3 = (undefined4 *)piVar6[2];
        if (puVar3[0x99] == 0) {
          piVar2 = (int *)puVar3[0x96];
          iVar4 = puVar3[0x97];
          if ((((((float)piVar2[9] < *(float *)(iVar4 + 0x2c) ==
                  ((float)piVar2[9] == *(float *)(iVar4 + 0x2c))) ||
                ((float)piVar2[0xb] < *(float *)(iVar4 + 0x24))) ||
               ((float)piVar2[10] < *(float *)(iVar4 + 0x30) ==
                ((float)piVar2[10] == *(float *)(iVar4 + 0x30)))) ||
              (((float)piVar2[0xc] < *(float *)(iVar4 + 0x28) ||
               ((*(char *)((int)piVar2 + 0x1d) == '\0' && (*(char *)(iVar4 + 0x1d) == '\0')))))) ||
             ((iVar4 = (**(code **)(*piVar2 + 0x50))(), iVar4 == 0 ||
              (iVar5 = (**(code **)(*(int *)puVar3[0x97] + 0x50))(), iVar4 = DAT_0072cc04,
              iVar5 == 0)))) {
            iVar4 = *piVar6;
            piVar2 = (int *)piVar6[1];
            *piVar2 = iVar4;
            *(int **)(iVar4 + 4) = piVar2;
            puVar3[0x9c] = 0;
            (**(code **)*puVar3)(1);
            iVar4 = DAT_0072cc04;
            goto LAB_00592c03;
          }
        }
        puVar3[0x98] = 0;
      }
      else {
        piVar2 = (int *)piVar6[1];
        *piVar2 = (int)piVar1;
        piVar1[1] = (int)piVar2;
LAB_00592c03:
        iVar5 = *(int *)(iVar4 + 0x18);
        *piVar6 = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x18) = iVar5 + -1;
        *(int **)(iVar4 + 0x10) = piVar6;
      }
      piVar6 = piVar1;
    } while (piVar1 != param_1 + 7);
  }
  if ((int *)param_1[7] == param_1 + 7) {
    iVar4 = *param_1;
    piVar6 = (int *)param_1[1];
    *piVar6 = iVar4;
    *(int **)(iVar4 + 4) = piVar6;
    FUN_00592b20();
    iVar5 = DAT_0072cc08;
    iVar4 = *(int *)(DAT_0072cc08 + 0x18);
    *param_1 = *(int *)(DAT_0072cc08 + 0x10);
    *(int *)(iVar5 + 0x18) = iVar4 + -1;
    *(int **)(iVar5 + 0x10) = param_1;
  }
  return;
}


// ==== 0x592c50 FUN_00592c50

void FUN_00592c50(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 8);
  if (DAT_00779c70 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00779c70 + -4;
  }
  iVar1 = Ptr_BaseAdjustMinus4();
  while (iVar2 != iVar1) {
    if ((*(char *)(iVar2 + 0x16) != '\0') && (*(char *)(iVar2 + 0x1d) != '\0')) {
      FUN_00593170(unaff_EDI,iVar2,0);
    }
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x592cb0 FUN_00592cb0

void FUN_00592cb0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char local_e8 [228];
  
  pcVar6 = local_e8;
  for (iVar5 = 0x37; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  pcVar6[0] = '\0';
  pcVar6[1] = '\0';
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar4 = puVar1, puVar4 != (undefined4 *)(param_1 + 0x1c)) {
    puVar1 = (undefined4 *)*puVar4;
    if (*(char *)(puVar4 + 3) == '\0') {
      piVar2 = *(int **)(puVar4[2] + 600);
      piVar3 = *(int **)(puVar4[2] + 0x25c);
      if ((*(char *)((int)piVar2 + 0x16) != '\0') && (local_e8[(short)piVar2[6]] == '\0')) {
        local_e8[(short)piVar2[6]] = '\x01';
        (**(code **)(*piVar2 + 0x28))(param_2);
      }
      if ((*(char *)((int)piVar3 + 0x16) != '\0') && (local_e8[(short)piVar3[6]] == '\0')) {
        iVar5 = *piVar3;
        local_e8[(short)piVar3[6]] = '\x01';
        (**(code **)(iVar5 + 0x28))(param_2);
      }
    }
  }
  return;
}


// ==== 0x592d50 FUN_00592d50

float10 FUN_00592d50(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *unaff_ESI;
  int *piVar5;
  float local_4;
  
  local_4 = (float)unaff_ESI[4] - (float)unaff_ESI[3];
  if ((local_4 < DAT_006ef2c8) &&
     (local_4 = (float)unaff_ESI[2] - (float)unaff_ESI[3], DAT_006ef2c8 <= local_4)) {
    local_4 = DAT_006ef2c8;
  }
  unaff_ESI[3] = (int)(local_4 + (float)unaff_ESI[3]);
  if (unaff_ESI[5] == 1) {
    FUN_00592cb0(unaff_ESI,local_4);
    if ((unaff_ESI[6] != 0) && (FUN_00592fd0(), (char)unaff_ESI[9] != '\0')) {
      iVar1 = *unaff_ESI;
      piVar5 = (int *)unaff_ESI[1];
      *piVar5 = iVar1;
      *(int **)(iVar1 + 4) = piVar5;
      FUN_00592b20();
      iVar3 = DAT_0072cc08;
      iVar1 = *(int *)(DAT_0072cc08 + 0x18);
      *unaff_ESI = *(int *)(DAT_0072cc08 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = unaff_ESI;
      return (float10)-1.0;
    }
    if ((float)unaff_ESI[3] == (float)unaff_ESI[2]) {
      iVar1 = *unaff_ESI;
      piVar5 = (int *)unaff_ESI[1];
      *piVar5 = iVar1;
      *(int **)(iVar1 + 4) = piVar5;
      *DAT_007377ec = (int)unaff_ESI;
      piVar5 = unaff_ESI;
      unaff_ESI[1] = (int)DAT_007377ec;
      DAT_007377ec = piVar5;
      *unaff_ESI = (int)&DAT_007377e8;
      return (float10)(float)unaff_ESI[3];
    }
  }
  else {
    if (DAT_00779c70 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(DAT_00779c70 + -4);
    }
    piVar4 = (int *)Ptr_BaseAdjustMinus4();
    while (piVar2 = piVar5, piVar2 != piVar4) {
      if (piVar2[1] == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)(piVar2[1] + -4);
      }
      if (((int *)piVar2[3] == unaff_ESI) && (*(char *)((int)piVar2 + 0x16) != '\0')) {
        (**(code **)(*piVar2 + 0x28))(local_4);
      }
    }
  }
  return (float10)(float)unaff_ESI[3];
}


// ==== 0x592e80 FUN_00592e80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592e80(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int unaff_EBX;
  int unaff_EDI;
  float10 fVar5;
  
  iVar3 = DAT_007313f4;
  *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 8);
  iVar2 = DAT_00700e5c;
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  if (iVar3 < iVar2) {
    for (puVar1 = *(undefined4 **)(unaff_EDI + 0x1c); puVar1 != (undefined4 *)(unaff_EDI + 0x1c);
        puVar1 = (undefined4 *)*puVar1) {
      if ((*(char *)(puVar1 + 3) == '\0') &&
         (iVar2 = puVar1[2], *(int *)(iVar2 + 0x260) < DAT_00700e60)) {
        if (unaff_EBX == 0) {
          fVar5 = (float10)*(float *)(iVar2 + 0x26c);
          if ((float10)-1.0 == fVar5) goto LAB_00592f33;
          if (fVar5 <= (float10)*(float *)(unaff_EDI + 8)) {
            *(undefined4 *)(iVar2 + 0x26c) = 0xbf800000;
            goto LAB_00592f99;
          }
          *(float *)(iVar2 + 0x26c) = (float)(fVar5 - (float10)*(float *)(unaff_EDI + 8));
        }
        else {
          iVar3 = *(int *)(unaff_EBX + 600);
          if (((*(char *)(iVar3 + 0x16) == '\0') ||
              ((iVar3 != *(int *)(iVar2 + 600) && (iVar3 != *(int *)(iVar2 + 0x25c))))) &&
             ((iVar3 = *(int *)(unaff_EBX + 0x25c), *(char *)(iVar3 + 0x16) == '\0' ||
              ((iVar3 != *(int *)(iVar2 + 600) && (iVar3 != *(int *)(iVar2 + 0x25c))))))) {
            fVar5 = (float10)CollisionBodyWitness__GetTOI(0xbf800000);
          }
          else {
LAB_00592f33:
            fVar4 = *(float *)(unaff_EDI + 8) - *(float *)(unaff_EDI + 0xc);
            fVar5 = (float10)CollisionBodyWitness__GetTOI(fVar4);
            if (((float10)fVar4 < fVar5) &&
               (fVar5 < (float10)_DAT_006ef2cc * (float10)5.0 !=
                (fVar5 == (float10)_DAT_006ef2cc * (float10)5.0))) {
              *(float *)(puVar1[2] + 0x26c) = (float)(fVar5 - (float10)fVar4);
              goto LAB_00592fc0;
            }
          }
LAB_00592f99:
          if ((fVar5 != (float10)-1.0) &&
             (fVar5 = fVar5 + (float10)*(float *)(unaff_EDI + 0xc),
             fVar5 < (float10)*(float *)(unaff_EDI + 0x10))) {
            *(float *)(unaff_EDI + 0x10) = (float)fVar5;
            *(undefined4 *)(unaff_EDI + 0x18) = puVar1[2];
          }
        }
      }
LAB_00592fc0:
    }
  }
  return;
}


// ==== 0x592fd0 FUN_00592fd0

void FUN_00592fd0(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int in_EAX;
  undefined4 *puVar4;
  float10 fVar5;
  
  puVar4 = (undefined4 *)CollisionBodyWitness__TestForContact();
  if (puVar4 == (undefined4 *)0x0) {
    fVar2 = *(float *)(in_EAX + 8) - *(float *)(in_EAX + 0xc);
    fVar5 = (float10)CollisionBodyWitness__GetTOI(fVar2);
    if ((fVar5 != (float10)-1.0) && ((float)fVar5 <= fVar2)) {
      *(float *)(in_EAX + 0x10) = (float)fVar5 + *(float *)(in_EAX + 0xc);
      FUN_00593100();
      return;
    }
  }
  else {
    DAT_007313f4 = DAT_007313f4 + 1;
    *(int *)(*(int *)(in_EAX + 0x18) + 0x260) = *(int *)(*(int *)(in_EAX + 0x18) + 0x260) + 1;
    FUN_0046b790();
    iVar3 = DAT_00735fe4;
    iVar1 = *(int *)(DAT_00735fe4 + 0x18);
    *puVar4 = *(undefined4 *)(DAT_00735fe4 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar4;
    iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 600);
    if ((*(char *)(iVar1 + 0x16) != '\0') && (*(char *)(iVar1 + 0x1d) != '\0')) {
      DynamicCollisionBody__UpdateProjectedBBox(*(float *)(in_EAX + 8) - *(float *)(in_EAX + 0xc));
      FUN_00593170(in_EAX,*(undefined4 *)(*(int *)(in_EAX + 0x18) + 600),1);
    }
    iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + 0x25c);
    if ((*(char *)(iVar1 + 0x16) != '\0') && (*(char *)(iVar1 + 0x1d) != '\0')) {
      DynamicCollisionBody__UpdateProjectedBBox(*(float *)(in_EAX + 8) - *(float *)(in_EAX + 0xc));
      FUN_00593170(in_EAX,*(undefined4 *)(*(int *)(in_EAX + 0x18) + 0x25c),1);
    }
    if (*(char *)(in_EAX + 0x24) != '\0') {
      return;
    }
  }
  FUN_00592e80();
  FUN_00593100();
  return;
}


// ==== 0x593100 FUN_00593100

void FUN_00593100(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *unaff_ESI;
  
  piVar1 = DAT_007377e8;
  piVar4 = (int *)NullUpdate_ret();
  while( true ) {
    if (piVar1 == piVar4) {
      iVar2 = *unaff_ESI;
      piVar1 = (int *)unaff_ESI[1];
      *piVar1 = iVar2;
      *(int **)(iVar2 + 4) = piVar1;
      puVar3 = DAT_007377ec;
      *DAT_007377ec = (int)unaff_ESI;
      DAT_007377ec = unaff_ESI;
      *unaff_ESI = (int)&DAT_007377e8;
      unaff_ESI[1] = (int)puVar3;
      return;
    }
    if ((piVar1 != unaff_ESI) &&
       ((float)unaff_ESI[4] < (float)piVar1[4] != ((float)unaff_ESI[4] == (float)piVar1[4]))) break;
    piVar1 = (int *)*piVar1;
  }
  iVar2 = *unaff_ESI;
  piVar4 = (int *)unaff_ESI[1];
  *piVar4 = iVar2;
  *(int **)(iVar2 + 4) = piVar4;
  puVar3 = (undefined4 *)piVar1[1];
  *puVar3 = unaff_ESI;
  piVar1[1] = (int)unaff_ESI;
  *unaff_ESI = (int)piVar1;
  unaff_ESI[1] = (int)puVar3;
  return;
}


// ==== 0x593170 FUN_00593170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00593170(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  bool bVar11;
  int *piStack_8c;
  int *piStack_88;
  undefined4 auStack_80 [32];
  
  iVar5 = (**(code **)(*param_2 + 0x50))();
  if (iVar5 == 0) {
    return;
  }
  iVar5 = 0;
  DynamicCollisionBody__CreateTrackPolygonCollisionBodies();
  fVar3 = DAT_007344b4;
  fVar2 = (float)param_2[9] - DAT_007344b4;
  if (param_2[2] == 0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(param_2[2] + -4);
  }
  piVar6 = (int *)Ptr_BaseAdjustMinus4();
  while ((piVar9 != piVar6 && (fVar2 <= (float)piVar9[0xb]))) {
    if (piVar9[2] == 0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)(piVar9[2] + -4);
    }
  }
  fVar3 = _DAT_00736054 + (float)param_2[0xb] + fVar3;
  if (param_2[1] == 0) {
    piStack_8c = (int *)0x0;
  }
  else {
    piStack_8c = (int *)(param_2[1] + -4);
  }
  while ((piStack_8c != piVar6 &&
         ((float)piStack_8c[0xb] < fVar3 != ((float)piStack_8c[0xb] == fVar3)))) {
    if (piStack_8c[1] == 0) {
      piStack_8c = (int *)0x0;
    }
    else {
      piStack_8c = (int *)(piStack_8c[1] + -4);
    }
  }
  if (piVar9 == (int *)0x779c6c) {
    if (DAT_00779c70 != 0) {
      piVar9 = (int *)(DAT_00779c70 + -4);
      goto LAB_00593274;
    }
  }
  else if (piVar9[1] != 0) {
    piVar9 = (int *)(piVar9[1] + -4);
    goto LAB_00593274;
  }
  piVar9 = (int *)0x0;
LAB_00593274:
  do {
    while( true ) {
      do {
        if (piVar9 == piStack_8c) {
          if ((char)param_3 != '\0') {
            iVar10 = 0;
            if (0 < iVar5) {
              do {
                FUN_00592e80();
                iVar10 = iVar10 + 1;
              } while (iVar10 < iVar5);
            }
            iVar10 = 0;
            if (0 < iVar5) {
              do {
                FUN_00593100();
                iVar10 = iVar10 + 1;
              } while (iVar10 < iVar5);
            }
          }
          return;
        }
        if (piVar9[1] == 0) {
          piStack_88 = (int *)0x0;
        }
        else {
          piStack_88 = (int *)(piVar9[1] + -4);
        }
        bVar11 = piVar9 == param_2;
        iVar10 = piVar9[3];
        iVar4 = param_2[3];
        piVar9 = piStack_88;
      } while ((bVar11) || (iVar7 = DynamicCollisionBody__MaybeCreateWitness(), iVar7 == 0));
      if (*(int *)(iVar4 + 0x14) == 0) break;
      if (iVar10 != iVar4) {
        if (*(int *)(iVar10 + 0x14) == 1) {
          fVar2 = *(float *)(iVar4 + 0xc);
          fVar3 = *(float *)(iVar10 + 0xc);
          if (fVar2 < fVar3 == 0 && (fVar2 == fVar3) == 0) {
            FUN_005934a0(iVar10,1);
          }
          else {
            FUN_005934a0(iVar4,CONCAT31((int3)(CONCAT22((short)((uint)*(int *)(iVar4 + 0x14) >> 0x10
                                                               ),(ushort)(fVar2 < fVar3) << 8 |
                                                                 (ushort)(NAN(fVar2) || NAN(fVar3))
                                                                 << 10 | (ushort)(fVar2 == fVar3) <<
                                                                         0xe) >> 8),
                                        (char)param_3 == '\0'));
          }
        }
        else if ((*(char *)((int)*(int **)(iVar7 + 0x25c) + 0x16) != '\0') &&
                (0.0 < *(float *)(iVar4 + 0xc))) {
          (**(code **)(**(int **)(iVar7 + 0x25c) + 0x28))(*(undefined4 *)(iVar4 + 0xc));
        }
      }
LAB_005933f0:
      FUN_00593570(param_3);
    }
    if (*(int *)(iVar10 + 0x14) != 0) {
      if (0.0 < *(float *)(iVar10 + 0xc)) {
        (**(code **)(*param_2 + 0x28))(*(undefined4 *)(iVar10 + 0xc));
      }
      goto LAB_005933f0;
    }
    piVar6 = (int *)FUN_00567160();
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar8 = piVar6 + 7;
      *piVar8 = (int)piVar8;
      piVar6[8] = (int)piVar8;
      piVar6[5] = 1;
      piVar6[6] = 0;
      piVar6[4] = -0x40800000;
      piVar6[2] = 0;
      piVar6[3] = 0;
      *(undefined1 *)(piVar6 + 9) = 0;
    }
    piVar8 = (int *)FUN_00567160();
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8[2] = iVar7;
      *(undefined1 *)(piVar8 + 3) = 0;
    }
    *(int **)(iVar7 + 0x270) = piVar6;
    *(int **)(*(int *)(iVar7 + 600) + 0xc) = piVar6;
    *(int **)(*(int *)(iVar7 + 0x25c) + 0xc) = piVar6;
    iVar10 = piVar6[7];
    piVar6[7] = (int)piVar8;
    *(int **)(iVar10 + 4) = piVar8;
    piVar8[1] = (int)(piVar6 + 7);
    *piVar8 = iVar10;
    piVar6[2] = *(int *)(param_1 + 8);
    piVar6[3] = 0;
    piVar6[4] = -0x40800000;
    piVar8 = DAT_007377e8;
    if (piVar6[5] == 0) {
      DAT_007313f4 = 0;
    }
    piVar1 = DAT_007377e8 + 1;
    DAT_007377e8 = piVar6;
    *piVar1 = (int)piVar6;
    *piVar6 = (int)piVar8;
    auStack_80[iVar5] = piVar6;
    iVar5 = iVar5 + 1;
    piVar6[1] = (int)&DAT_007377e8;
  } while( true );
}


// ==== 0x5934a0 FUN_005934a0

void FUN_005934a0(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  
  if (*(float *)(in_EAX + 0xc) < (float)param_1[3]) {
    FUN_005936d0();
  }
  fVar4 = *(float *)(in_EAX + 0xc) - (float)param_1[3];
  if (0.0 < fVar4) {
    FUN_00592cb0(param_1,fVar4);
  }
  piVar6 = (int *)param_1[7];
  iVar5 = DAT_0072cc04;
  if (piVar6 != param_1 + 7) {
    do {
      piVar1 = (int *)*piVar6;
      if ((char)piVar6[3] == '\0') {
        FUN_00593570(1);
        iVar5 = DAT_0072cc04;
      }
      iVar2 = *piVar6;
      piVar3 = (int *)piVar6[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      iVar2 = *(int *)(iVar5 + 0x18);
      *piVar6 = *(int *)(iVar5 + 0x10);
      *(int *)(iVar5 + 0x18) = iVar2 + -1;
      *(int **)(iVar5 + 0x10) = piVar6;
      piVar6 = piVar1;
    } while (piVar1 != param_1 + 7);
  }
  if (param_2 == '\0') {
    *(undefined1 *)(param_1 + 9) = 1;
    return;
  }
  iVar5 = *param_1;
  piVar6 = (int *)param_1[1];
  *piVar6 = iVar5;
  *(int **)(iVar5 + 4) = piVar6;
  FUN_00592b20();
  iVar2 = DAT_0072cc08;
  iVar5 = *(int *)(DAT_0072cc08 + 0x18);
  *param_1 = *(int *)(DAT_0072cc08 + 0x10);
  *(int **)(iVar2 + 0x10) = param_1;
  *(int *)(iVar2 + 0x18) = iVar5 + -1;
  return;
}


// ==== 0x593570 FUN_00593570

void FUN_00593570(char param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  piVar2 = (int *)FUN_00567160();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = unaff_EDI;
    *(undefined1 *)(piVar2 + 3) = 0;
  }
  *(int *)(unaff_EDI + 0x270) = unaff_EBX;
  *(int *)(*(int *)(unaff_EDI + 600) + 0xc) = unaff_EBX;
  *(int *)(*(int *)(unaff_EDI + 0x25c) + 0xc) = unaff_EBX;
  if (param_1 != '\0') {
    CollisionBodyWitness__GetTOI(*(float *)(unaff_EBX + 8) - *(float *)(unaff_EBX + 0xc));
  }
  iVar1 = *(int *)(unaff_EBX + 0x1c);
  *(undefined4 *)(unaff_EBX + 0x1c) = piVar2;
  *(int **)(iVar1 + 4) = piVar2;
  piVar2[1] = unaff_EBX + 0x1c;
  *piVar2 = iVar1;
  return;
}


// ==== 0x5935e0 FUN_005935e0

void __fastcall FUN_005935e0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(param_2 + 0x1c);
  do {
    if (puVar1 == (undefined4 *)(param_2 + 0x1c)) {
LAB_00593609:
      if (unaff_ESI == *(int *)(param_2 + 0x18)) {
        *(undefined4 *)(param_2 + 0x18) = 0;
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 8);
      }
      return;
    }
    if ((*(char *)(puVar1 + 3) == '\0') && (puVar1[2] == unaff_ESI)) {
      *(undefined1 *)(puVar1 + 3) = 1;
      goto LAB_00593609;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x593620 FUN_00593620

void FUN_00593620(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  
  piVar7 = DAT_007377e8;
  piVar9 = (int *)NullUpdate_ret();
  iVar8 = DAT_0072cc04;
  iVar4 = DAT_0072cc08;
  while (piVar7 != piVar9) {
    piVar1 = (int *)*piVar7;
    piVar6 = (int *)piVar7[7];
    while (piVar6 != piVar7 + 7) {
      piVar2 = (int *)*piVar6;
      puVar3 = (undefined4 *)piVar6[1];
      *puVar3 = piVar2;
      piVar2[1] = (int)puVar3;
      *(undefined4 *)(piVar6[2] + 0x270) = 0;
      iVar4 = *(int *)(iVar8 + 0x18);
      *piVar6 = *(int *)(iVar8 + 0x10);
      *(int **)(iVar8 + 0x10) = piVar6;
      *(int *)(iVar8 + 0x18) = iVar4 + -1;
      piVar6 = piVar2;
      iVar4 = DAT_0072cc08;
    }
    iVar5 = *piVar7;
    piVar6 = (int *)piVar7[1];
    *piVar6 = iVar5;
    *(int **)(iVar5 + 4) = piVar6;
    FUN_00592b20();
    iVar5 = *(int *)(iVar4 + 0x18);
    *piVar7 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar5 + -1;
    *(int **)(iVar4 + 0x10) = piVar7;
    piVar7 = piVar1;
  }
  CollisionBodyWitness__EliminateAllWitnesses();
  return;
}


// ==== 0x5936d0 FUN_005936d0

void FUN_005936d0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = DAT_007377e8;
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    for (puVar1 = (undefined4 *)puVar2[7]; puVar1 != puVar2 + 7; puVar1 = (undefined4 *)*puVar1) {
    }
  }
  return;
}


// ==== 0x593700 FUN_00593700

void FUN_00593700(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_0072cc04;
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


// ==== 0x593740 FUN_00593740

void FUN_00593740(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_0072cc08;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00592b20();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x593780 FUN_00593780

void FUN_00593780(void)

{
  SceneryInstance__SetTransform();
  return;
}


// ==== 0x593790 FUN_00593790

void FUN_00593790(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_007344a4;
  if ((int **)DAT_007377e0 != &DAT_007377e0) {
    do {
      piVar4 = DAT_007377e0;
      iVar1 = *DAT_007377e0;
      piVar2 = (int *)DAT_007377e0[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      FUN_00593780();
      iVar1 = *(int *)(iVar3 + 0x18);
      *piVar4 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar4;
    } while ((int **)DAT_007377e0 != &DAT_007377e0);
  }
  if (iVar3 != 0) {
    SlotPool__Destroy();
    DAT_007344a4 = 0;
  }
  return;
}


// ==== 0x5937f0 FUN_005937f0

void __fastcall FUN_005937f0(int *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte *in_EAX;
  int iVar3;
  
  iVar3 = -1;
  bVar2 = *in_EAX;
  while (bVar2 != 0) {
    iVar3 = iVar3 * 0x21 + (uint)bVar2;
    pbVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    bVar2 = *pbVar1;
  }
  *param_1 = iVar3;
  iVar3 = -1;
  bVar2 = *param_2;
  while (bVar2 != 0) {
    iVar3 = iVar3 * 0x21 + (uint)bVar2;
    pbVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  param_1[1] = iVar3;
  FUN_00402ad0(iVar3);
  return;
}


// ==== 0x593850 FUN_00593850

void __fastcall FUN_00593850(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    pbVar1 = (byte *)(*(int *)(param_1 + 0x10) + 0xe);
    *pbVar1 = *pbVar1 & 0xef;
    puVar2 = *(undefined4 **)(param_1 + 0x14);
    if (puVar2 != (undefined4 *)0x0) {
      FUN_00591c90(puVar2);
      iVar4 = DAT_007344c8;
      iVar3 = *(int *)(DAT_007344c8 + 0x18);
      *puVar2 = *(undefined4 *)(DAT_007344c8 + 0x10);
      *(int *)(iVar4 + 0x18) = iVar3 + -1;
      *(undefined4 **)(iVar4 + 0x10) = puVar2;
    }
  }
  return;
}


// ==== 0x593880 FUN_00593880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00593880(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686233;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DAT_007344b0 = (undefined4 *)FUN_00566dc0(0x1c,"FernShakerSlotPool",0);
  if ((DAT_007344b0 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344b0;
    puVar1 = DAT_007344b0;
    DAT_007344b0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344b0 = &DAT_0073d818;
  }
  _DAT_007344ac = 2;
  puVar1 = _malloc(0x24);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = puVar1 + 1;
    *puVar1 = 2;
    eh_vector_constructor_iterator(puVar2,0x10,2,FUN_00593960,FUN_00593970);
  }
  DAT_007344a8 = puVar2;
  FUN_005937f0(puVar1);
  FUN_005937f0();
  ExceptionList = local_c;
  return;
}


// ==== 0x593960 FUN_00593960

void __fastcall FUN_00593960(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0xc) = iVar1;
  return;
}


// ==== 0x593970 FUN_00593970

void FUN_00593970(void)

{
  List_DeleteAllNodes();
  return;
}


// ==== 0x593980 FUN_00593980

void FUN_00593980(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_007344b0;
  if ((int **)DAT_007377d8 != &DAT_007377d8) {
    do {
      piVar4 = DAT_007377d8;
      iVar1 = *DAT_007377d8;
      piVar2 = (int *)DAT_007377d8[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      FUN_00593850();
      iVar1 = *(int *)(iVar3 + 0x18);
      *piVar4 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar4;
    } while ((int **)DAT_007377d8 != &DAT_007377d8);
  }
  return;
}


// ==== 0x5939d0 FUN_005939d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005939d0(void)

{
  void *_Memory;
  
  if (DAT_007344a8 != (void *)0x0) {
    _Memory = (void *)((int)DAT_007344a8 + -4);
    eh_vector_destructor_iterator(DAT_007344a8,0x10,*(int *)((int)DAT_007344a8 + -4),FUN_00593970);
    _free(_Memory);
  }
  DAT_007344a8 = (void *)0x0;
  _DAT_007344ac = 0;
  FUN_00593980();
  SlotPool__Destroy();
  DAT_007344b0 = 0;
  return;
}


// ==== 0x593a30 FUN_00593a30

void FUN_00593a30(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  puVar8 = DAT_007377d8;
  puVar7 = (undefined4 *)NullUpdate_ret();
  iVar5 = DAT_007344b0;
  while (puVar4 = puVar8, puVar8 = DAT_007377d8, puVar4 != puVar7) {
    puVar8 = (undefined4 *)*puVar4;
    if (0xf0 < DAT_006f08a0 - puVar4[3]) {
      puVar2 = (undefined4 *)puVar4[1];
      *puVar2 = puVar8;
      puVar8[1] = puVar2;
      if (puVar4[4] != 0) {
        pbVar1 = (byte *)(puVar4[4] + 0xe);
        *pbVar1 = *pbVar1 & 0xef;
        puVar2 = (undefined4 *)puVar4[5];
        if (puVar2 != (undefined4 *)0x0) {
          FUN_00591c90(puVar2);
          iVar6 = DAT_007344c8;
          iVar9 = *(int *)(DAT_007344c8 + 0x18);
          *puVar2 = *(undefined4 *)(DAT_007344c8 + 0x10);
          *(int *)(iVar6 + 0x18) = iVar9 + -1;
          *(undefined4 **)(iVar6 + 0x10) = puVar2;
        }
      }
      iVar9 = *(int *)(iVar5 + 0x18);
      *puVar4 = *(undefined4 *)(iVar5 + 0x10);
      *(int *)(iVar5 + 0x18) = iVar9 + -1;
      *(undefined4 **)(iVar5 + 0x10) = puVar4;
    }
  }
  for (; (puVar8 != puVar7 && (puVar8[2] != param_1)); puVar8 = (undefined4 *)*puVar8) {
  }
  if (((undefined4 **)puVar8 == &DAT_007377d8) && (*(int *)(iVar5 + 0x18) != *(int *)(iVar5 + 0x2c))
     ) {
    puVar8 = *(undefined4 **)(iVar5 + 0x10);
    iVar9 = *(int *)(iVar5 + 0x18) + 1;
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      uVar3 = *puVar8;
      if (*(int *)(iVar5 + 0x1c) < iVar9) {
        *(int *)(iVar5 + 0x1c) = iVar9;
      }
      *(int *)(iVar5 + 0x18) = iVar9;
      *(undefined4 *)(iVar5 + 0x10) = uVar3;
      puVar8[2] = param_1;
      puVar8[3] = DAT_006f08a0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[6] = 0;
    }
    *DAT_007377dc = puVar8;
    puVar7 = puVar8;
    puVar8[1] = DAT_007377dc;
    DAT_007377dc = puVar7;
    *puVar8 = &DAT_007377d8;
  }
  return;
}


// ==== 0x593b40 FUN_00593b40

void FUN_00593b40(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_007344a4;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00593780();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x593b80 FUN_00593b80

void FUN_00593b80(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_007344b0;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    piVar2 = (int *)piVar1[1];
    iVar3 = *piVar1;
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    FUN_00593850();
    iVar3 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar3 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x593bc0 FUN_00593bc0

void __thiscall FUN_00593bc0(int param_1,float param_2,float param_3,float param_4)

{
  *(float *)(param_1 + 4) = param_2;
  if (param_2 != *(float *)(param_1 + 0xc)) {
    *(undefined2 *)(param_1 + 0x2c) = 2;
  }
  *(float *)(param_1 + 0x34) = param_3;
  if (param_3 != *(float *)(param_1 + 0x3c)) {
    *(undefined2 *)(param_1 + 0x5c) = 2;
  }
  *(float *)(param_1 + 100) = param_4;
  if (param_4 != *(float *)(param_1 + 0x6c)) {
    *(undefined2 *)(param_1 + 0x8c) = 2;
  }
  return;
}


// ==== 0x593c20 FUN_00593c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00593c20(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = _K_ONE / *(float *)(param_1 + 0x24);
  fVar2 = fVar1 * *(float *)(param_1 + 0x24);
  fVar1 = ((*(float *)(param_1 + 0x14) + *(float *)(param_1 + 0x14) +
           fVar2 * *(float *)(param_1 + 0x10) * 3.0) * fVar2 + *(float *)(param_1 + 0x18)) * fVar1;
  fVar2 = ABS(fVar1);
  if (param_2 < fVar2) {
    *(float *)(param_1 + 0xc) = (fVar2 / fVar1) * param_2 * *(float *)(param_1 + 0x24);
    return;
  }
  return;
}


// ==== 0x593c70 FUN_00593c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00593c70(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_c;
  
  fVar3 = _K_ONE / *(float *)(param_1 + 0x24);
  fVar1 = *(float *)(param_1 + 0x14) + *(float *)(param_1 + 0x14);
  local_c = (fVar3 * 0.0 * *(float *)(param_1 + 0x10) * 6.0 + fVar1) * fVar3 * fVar3;
  fVar2 = ABS(local_c);
  fVar3 = (fVar3 * *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x10) * 6.0 + fVar1) * fVar3 *
          fVar3;
  if (param_2 < fVar2) {
    local_c = (fVar2 / local_c) * param_2;
  }
  if (ABS(fVar3) <= param_2) {
    if (fVar2 <= param_2) {
      return;
    }
  }
  else {
    fVar3 = (ABS(fVar3) / fVar3) * param_2;
  }
  fVar1 = *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x24);
  local_c = local_c * fVar1;
  *(float *)(param_1 + 0x14) = _K_HALF * local_c;
  *(float *)(param_1 + 0x10) = (fVar1 * fVar3 - local_c) * 0.16666667;
  return;
}


// ==== 0x593d40 FUN_00593d40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00593d40(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  short sVar2;
  float *extraout_ECX;
  float *extraout_ECX_00;
  float extraout_EDX;
  
  sVar2 = *(short *)(param_1 + 0xb);
  if (sVar2 != 0) {
    if (sVar2 != 1) {
      if (sVar2 != 2) {
        return;
      }
      param_1[8] = 0.0;
      if (*(short *)((int)param_1 + 0x2e) == 0) {
        *(undefined2 *)(param_1 + 0xb) = 1;
      }
      if (0.0 < param_3) {
        FUN_00593c20(param_3);
        param_1 = extraout_ECX;
        param_3 = extraout_EDX;
      }
      fVar1 = param_1[2] - *param_1;
      param_1[6] = param_1[1];
      param_1[7] = *param_1;
      param_1[4] = (param_1[3] + param_1[1]) - (fVar1 + fVar1);
      param_1[5] = (fVar1 * 3.0 - param_1[3]) - (param_1[1] + param_1[1]);
      if (0.0 < param_4) {
        FUN_00593c70(param_3);
        param_1 = extraout_ECX_00;
      }
    }
    if (param_1[9] <= _K_EPS_SPEED) {
      param_1[8] = 1.0;
    }
    else {
      param_1[8] = param_2 / param_1[9] + param_1[8];
    }
    if (param_1[8] < param_1[10]) {
      fVar1 = param_1[8];
      *param_1 = ((fVar1 * param_1[4] + param_1[5]) * fVar1 + param_1[6]) * fVar1 + param_1[7];
      param_1[1] = (param_1[5] + param_1[5] + fVar1 * param_1[4] * 3.0) * fVar1 + param_1[6];
    }
    else {
      *(undefined2 *)(param_1 + 0xb) = 0;
      if (_K_ONE <= param_1[10]) {
        *param_1 = param_1[2];
        param_1[1] = param_1[3];
        return;
      }
    }
  }
  return;
}


// ==== 0x593e60 FUN_00593e60

void __thiscall FUN_00593e60(float *param_1,float param_2)

{
  int in_EAX;
  
  *param_1 = ((param_2 * *(float *)(in_EAX + 0x10) + *(float *)(in_EAX + 0x14)) * param_2 +
             *(float *)(in_EAX + 0x18)) * param_2 + *(float *)(in_EAX + 0x1c);
  param_1[1] = ((param_2 * *(float *)(in_EAX + 0x40) + *(float *)(in_EAX + 0x44)) * param_2 +
               *(float *)(in_EAX + 0x48)) * param_2 + *(float *)(in_EAX + 0x4c);
  param_1[2] = ((param_2 * *(float *)(in_EAX + 0x70) + *(float *)(in_EAX + 0x74)) * param_2 +
               *(float *)(in_EAX + 0x78)) * param_2 + *(float *)(in_EAX + 0x7c);
  return;
}


// ==== 0x593ec0 FUN_00593ec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00593ec0(float *param_1,float param_2,float param_3,float param_4)

{
  short sVar1;
  float fVar2;
  float *extraout_ECX;
  float *extraout_ECX_00;
  float extraout_EDX;
  
  sVar1 = *(short *)(param_1 + 0xb);
  if (sVar1 != 0) {
    if (sVar1 != 1) {
      if (sVar1 != 2) {
        return;
      }
      param_1[8] = 0.0;
      if (*(short *)((int)param_1 + 0x2e) == 0) {
        *(undefined2 *)(param_1 + 0xb) = 1;
      }
      if (0.0 < param_3) {
        FUN_00593c20(param_3);
        param_1 = extraout_ECX;
        param_3 = extraout_EDX;
      }
      fVar2 = param_1[2] - *param_1;
      param_1[6] = param_1[1];
      param_1[7] = *param_1;
      param_1[4] = (param_1[3] + param_1[1]) - (fVar2 + fVar2);
      param_1[5] = (fVar2 * 3.0 - param_1[3]) - (param_1[1] + param_1[1]);
      if (0.0 < param_4) {
        FUN_00593c70(param_3);
        param_1 = extraout_ECX_00;
      }
    }
    fVar2 = param_2 / param_1[9] + param_1[8];
    param_1[8] = fVar2;
    if (fVar2 < param_1[10]) {
      *param_1 = ((fVar2 * param_1[4] + param_1[5]) * fVar2 + param_1[6]) * fVar2 + param_1[7];
      param_1[1] = (param_1[5] + param_1[5] + fVar2 * param_1[4] * 3.0) * fVar2 + param_1[6];
    }
    else {
      *(undefined2 *)(param_1 + 0xb) = 0;
      if (_K_ONE <= param_1[10]) {
        *param_1 = param_1[2];
        param_1[1] = param_1[3];
        return;
      }
    }
  }
  return;
}


// ==== 0x593fc0 FUN_00593fc0

void FUN_00593fc0(undefined4 param_1)

{
  FUN_00593ec0(param_1,0,0);
  FUN_00593ec0(param_1,0,0);
  FUN_00593ec0(param_1,0,0);
  return;
}


// ==== 0x593ff0 FUN_00593ff0

void FUN_00593ff0(int param_1,int param_2,int param_3)

{
  uint in_EAX;
  sbyte sVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  pbVar3 = (byte *)(((int)(in_EAX + ((int)in_EAX >> 0x1f & 7U)) >> 3) + param_1);
  uVar4 = in_EAX & 7;
  iVar2 = 0;
  if (0 < param_3) {
    do {
      sVar1 = (sbyte)uVar4;
      uVar4 = uVar4 + 1 & 7;
      *pbVar3 = ((byte)(param_2 >> ((byte)iVar2 & 0x1f)) & 1) << sVar1 |
                ~('\x01' << sVar1) & *pbVar3;
      if (uVar4 == 0) {
        pbVar3 = pbVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return;
}


// ==== 0x594050 FUN_00594050

uint FUN_00594050(int param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int unaff_EDI;
  
  pbVar2 = (byte *)(((int)(((int)param_2 >> 0x1f & 7U) + param_2) >> 3) + param_1);
  param_2 = param_2 & 7;
  uVar1 = 0;
  iVar3 = 0;
  if (0 < unaff_EDI) {
    do {
      uVar1 = uVar1 | (*pbVar2 >> (sbyte)param_2 & 1) << ((byte)iVar3 & 0x1f);
      param_2 = param_2 + 1 & 7;
      if (param_2 == 0) {
        pbVar2 = pbVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < unaff_EDI);
  }
  return uVar1;
}


// ==== 0x5940a0 FUN_005940a0

void FUN_005940a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int unaff_ESI;
  
  uVar5 = *(uint *)(unaff_ESI + 8) & 0xfffffff8;
  iVar6 = *(int *)(unaff_ESI + 0xc) * 8;
  for (iVar2 = iVar6; iVar2 < (int)uVar5; iVar2 = iVar2 + iVar1 * 8) {
    iVar1 = (int)((uVar5 - iVar2) + ((int)(uVar5 - iVar2) >> 0x1f & 7U)) >> 3;
    if (0x7e0 < iVar1) {
      iVar1 = 0x7e0;
    }
  }
  iVar2 = 0;
  if (0 < *(int *)(unaff_ESI + 0x18)) {
    puVar4 = (undefined4 *)(unaff_ESI + 0x40);
    do {
      *puVar4 = 0;
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 9;
    } while (iVar2 < *(int *)(unaff_ESI + 0x18));
  }
  iVar2 = *(int *)(unaff_ESI + 8) - uVar5;
  if (iVar2 != 0) {
    iVar1 = iVar2;
    uVar3 = FUN_00594050(unaff_ESI,*(int *)(unaff_ESI + 8) - iVar2);
    FUN_00593ff0(unaff_ESI,uVar3,iVar1);
  }
  *(int *)(unaff_ESI + 8) = iVar2 + iVar6;
  return;
}


// ==== 0x594120 FUN_00594120

undefined4 __fastcall FUN_00594120(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  
  if ((in_EAX == 0) || (*(int *)(in_EAX + 0x14) * 8 + -0x44 <= *(int *)(in_EAX + 8))) {
    return 0;
  }
  *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + 1;
  piVar1 = (int *)(in_EAX + 0x30 + param_2 * 0x24);
  if ((piVar1[4] != 0) && (piVar1[2] == param_4)) {
    if ((piVar1[3] != (1 << ((byte)*piVar1 & 0x1f)) + -1) && (piVar1[5] == param_3)) {
      iVar2 = piVar1[3] + 1;
      piVar1[3] = iVar2;
      FUN_00593ff0(in_EAX,iVar2,*piVar1);
      goto LAB_005941e3;
    }
  }
  FUN_00593ff0(in_EAX,param_2,4);
  iVar2 = *(int *)(in_EAX + 8) + 4;
  *(int *)(in_EAX + 8) = iVar2;
  piVar1[4] = iVar2;
  FUN_00593ff0(in_EAX,0,*piVar1);
  piVar1[3] = 0;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + *piVar1;
  piVar1[5] = param_3;
  FUN_00593ff0(in_EAX,param_3,param_4);
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + param_4;
  piVar1[2] = param_4;
LAB_005941e3:
  if (*(int *)(in_EAX + 0x1c) != 0) {
    *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + 1;
  }
  if ((*(int *)(in_EAX + 0x14) * 8 + -0x44 <= *(int *)(in_EAX + 8)) &&
     (*(int *)(in_EAX + 0x1c) != 0)) {
    FUN_005940a0();
  }
  return 1;
}


// ==== 0x594220 FUN_00594220

int FUN_00594220(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar1 = (int *)(unaff_ESI + 0x30 + param_2 * 0x24);
  if (piVar1[7] != 0) {
    iVar3 = piVar1[6];
    iVar2 = FUN_00594050(unaff_ESI,piVar1[7]);
    if (iVar3 < iVar2) {
      iVar2 = piVar1[8];
      piVar1[6] = iVar3 + 1;
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
      return iVar2;
    }
  }
  if (*(int *)(unaff_ESI + 0x24) < *(int *)(unaff_ESI + 0x20)) {
    iVar3 = *(int *)(unaff_ESI + 0x10);
    iVar2 = FUN_00594050(unaff_ESI,iVar3);
    iVar3 = iVar3 + 4;
    *(int *)(unaff_ESI + 0x10) = iVar3;
    if (iVar2 == param_2) {
      piVar1[7] = iVar3;
      piVar1[6] = 0;
      iVar3 = *(int *)(unaff_ESI + 0x10) + *piVar1;
      *(int *)(unaff_ESI + 0x10) = iVar3;
      iVar3 = FUN_00594050(unaff_ESI,iVar3);
      piVar1[8] = iVar3;
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + param_1;
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
      return iVar3;
    }
  }
  iVar3 = piVar1[1];
  *(undefined4 *)(unaff_ESI + 0x28) = 1;
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
  return iVar3;
}


// ==== 0x5942d0 FUN_005942d0

void __fastcall FUN_005942d0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  
  DAT_00734488 = DAT_00734488 + 1;
  *(undefined4 *)(in_EAX + 0xc) = param_3;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0x10) = param_2;
  cVar2 = *param_1;
  pcVar1 = (char *)(in_EAX + 0x14);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  return;
}


// ==== 0x594310 FUN_00594310

void FUN_00594310(void)

{
  int in_EAX;
  
  DAT_00734488 = DAT_00734488 + -1;
  FUN_0063c2c0(*(undefined4 *)(in_EAX + 0xc),100);
  return;
}


// ==== 0x594330 FUN_00594330

int * FUN_00594330(char *param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  
  piVar3 = DAT_007377c8;
  piVar5 = (int *)NullUpdate_ret();
  do {
    if (piVar3 == piVar5) {
      return (int *)0x0;
    }
    pcVar6 = param_1;
    do {
      cVar1 = pcVar6[(int)piVar3 + (0x14 - (int)param_1)];
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      iVar4 = *piVar3;
      piVar5 = (int *)piVar3[1];
      *piVar5 = iVar4;
      *(int **)(iVar4 + 4) = piVar5;
      *DAT_007377cc = (int)piVar3;
      piVar5 = piVar3;
      piVar3[1] = (int)DAT_007377cc;
      DAT_007377cc = piVar5;
      *piVar3 = (int)&DAT_007377c8;
      return piVar3;
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


// ==== 0x5943b0 FUN_005943b0

void FUN_005943b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  while ((piVar6 = DAT_007377c8, 3 < DAT_00734488 &&
         (piVar3 = (int *)NullUpdate_ret(), piVar6 != piVar3))) {
    while (piVar6[2] != 0) {
      piVar6 = (int *)*piVar6;
      if (piVar6 == piVar3) goto LAB_005943ed;
    }
    iVar4 = *piVar6;
    piVar3 = (int *)piVar6[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    DAT_00734488 = DAT_00734488 + -1;
    FUN_0063c2c0(piVar6[3],100);
    iVar1 = DAT_00734484;
    iVar4 = *(int *)(DAT_00734484 + 0x18);
    *piVar6 = *(int *)(DAT_00734484 + 0x10);
    *(int *)(iVar1 + 0x18) = iVar4 + -1;
    *(int **)(iVar1 + 0x10) = piVar6;
  }
LAB_005943ed:
  iVar4 = FUN_00567160();
  if (iVar4 == 0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_005942d0(param_2);
  }
  *DAT_007377cc = puVar5;
  puVar2 = puVar5;
  puVar5[1] = DAT_007377cc;
  DAT_007377cc = puVar2;
  *puVar5 = &DAT_007377c8;
  return;
}


// ==== 0x594470 FUN_00594470

void FUN_00594470(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)NullUpdate_ret();
  do {
    piVar5 = DAT_007377c8;
    if (DAT_007377c8 == piVar4) {
      return;
    }
    while (piVar5[2] != 0) {
      piVar5 = (int *)*piVar5;
      if (piVar5 == piVar4) {
        return;
      }
    }
    iVar1 = *piVar5;
    piVar2 = (int *)piVar5[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    FUN_00594310();
    iVar3 = DAT_00734484;
    iVar1 = *(int *)(DAT_00734484 + 0x18);
    *piVar5 = *(int *)(DAT_00734484 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(int **)(iVar3 + 0x10) = piVar5;
  } while( true );
}


// ==== 0x5944d0 FUN_005944d0

void __fastcall FUN_005944d0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00734484;
  iVar1 = *(int *)(DAT_00734484 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00734484 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x5944f0 FUN_005944f0

void FUN_005944f0(char *param_1,uint param_2)

{
  uint *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint *unaff_ESI;
  bool bVar7;
  undefined4 local_cc;
  char local_c8 [200];
  
  cVar2 = *param_1;
  puVar1 = unaff_ESI + 8;
  *(char *)puVar1 = cVar2;
  if (cVar2 != '\0') {
    puVar3 = puVar1;
    do {
      cVar2 = (param_1 + (1 - (int)puVar1))[(int)puVar3];
      puVar3 = (uint *)((int)puVar3 + 1);
      *(char *)puVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  bVar7 = DAT_00734494 != 0;
  *unaff_ESI = param_2;
  unaff_ESI[1] = 0xffffffff;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  if ((bVar7) && ((param_2 & 1) != 0)) {
    uVar4 = FUN_00594a40();
    unaff_ESI[6] = uVar4;
    if (uVar4 != 0) {
      param_1 = &DAT_007313f8 + *(int *)(uVar4 + 4) * 0x40;
    }
  }
  if ((param_2 & 6) != 0) {
    FUN_00594470(0);
  }
  if ((param_2 == 2) && (cVar2 = FUN_0063c200(param_1,1,100,&local_cc), cVar2 != '\0')) {
    param_2 = 0;
    FUN_0063c2c0(local_cc,100);
  }
  uVar4 = FUN_00594330(param_1);
  if ((uVar4 != 0) && (param_2 == 1)) {
    *(int *)(uVar4 + 8) = *(int *)(uVar4 + 8) + 1;
    unaff_ESI[3] = *(uint *)(uVar4 + 0xc);
    unaff_ESI[1] = *(uint *)(uVar4 + 0x10);
    unaff_ESI[4] = uVar4;
    goto LAB_0059471f;
  }
  if ((param_2 & 0x100) != 0) {
    unaff_ESI[1] = (DAT_0073448c != 0) - 2;
    return;
  }
  uVar5 = FUN_0063a5d0(param_1,param_2,100,0);
  iVar6 = FUN_00639d70(uVar5);
  uVar4 = FUN_00639c00(uVar5);
  if (iVar6 == 1) {
LAB_005946cc:
    unaff_ESI[3] = uVar4;
  }
  else if (DAT_0070108f != '\0') {
    local_c8[0] = DAT_0070108f;
    local_c8[1] = 0x3a;
    local_c8[2] = 0x5c;
    local_c8[3] = 0;
    bStrCat2(param_1);
    uVar5 = FUN_0063a5d0(local_c8,param_2,100,0);
    iVar6 = FUN_00639d70(uVar5);
    uVar4 = FUN_00639c00(uVar5);
    if (iVar6 == 1) {
      unaff_ESI[3] = uVar4;
    }
    if (unaff_ESI[3] == 0) {
      DiscCheck_ModalFrameLoop(iVar6);
      uVar5 = FUN_0063a5d0(local_c8,param_2,100,0);
      iVar6 = FUN_00639d70(uVar5);
      uVar4 = FUN_00639c00(uVar5);
      if (iVar6 == 1) goto LAB_005946cc;
    }
  }
  if (unaff_ESI[3] != 0) {
    uVar5 = FUN_0063a800(unaff_ESI[3],100,0);
    iVar6 = FUN_00639d70(uVar5);
    uVar4 = FUN_00639c00(uVar5);
    if ((iVar6 == 1) && (unaff_ESI[1] = uVar4, param_2 == 1)) {
      uVar4 = FUN_005943b0(param_1,unaff_ESI[3],uVar4);
      *(int *)(uVar4 + 8) = *(int *)(uVar4 + 8) + 1;
      unaff_ESI[4] = uVar4;
    }
  }
LAB_0059471f:
  if (-1 < (int)unaff_ESI[1]) {
    if (unaff_ESI[6] != 0) {
      unaff_ESI[1] = *(uint *)(unaff_ESI[6] + 0x10);
    }
    if ((param_2 & 5) == 0) {
      unaff_ESI[2] = unaff_ESI[1];
    }
  }
  return;
}


// ==== 0x594750 FUN_00594750

void FUN_00594750(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  CriticalSection__Enter(&DAT_007315f8);
  if (*(int *)(unaff_ESI + 4) < *(int *)(unaff_ESI + 8) + param_2) {
    param_2 = *(int *)(unaff_ESI + 4) - *(int *)(unaff_ESI + 8);
  }
  puVar2 = (undefined4 *)FUN_00567160();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[2] = unaff_ESI;
    puVar2[3] = param_3;
    puVar2[4] = param_4;
    puVar2[5] = 0;
  }
  *DAT_007377c4 = puVar2;
  puVar1 = puVar2;
  puVar2[1] = DAT_007377c4;
  DAT_007377c4 = puVar1;
  *puVar2 = &DAT_007377c0;
  DAT_0073448c = DAT_0073448c + 1;
  iVar3 = *(int *)(unaff_ESI + 8);
  *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + 1;
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    iVar3 = iVar3 + *(int *)(*(int *)(unaff_ESI + 0x18) + 8) * 0x800;
  }
  uVar4 = FUN_0063a700(*(undefined4 *)(unaff_ESI + 0xc),iVar3,param_1,param_2,100,puVar2);
  puVar2[5] = uVar4;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + param_2;
  CriticalSection__Leave(&DAT_007315f8);
  FUN_00639f20(uVar4,FUN_00594820);
  return;
}


// ==== 0x594820 FUN_00594820

void FUN_00594820(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  CriticalSection__Enter(&DAT_007315f8);
  FUN_00639c00(param_1);
  iVar1 = *param_3;
  piVar2 = (int *)param_3[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  puVar3 = DAT_007377d4;
  *DAT_007377d4 = (int)param_3;
  DAT_007377d4 = param_3;
  param_3[1] = (int)puVar3;
  *param_3 = (int)&DAT_007377d0;
  CriticalSection__Leave(&DAT_007315f8);
  return;
}


// ==== 0x594870 FUN_00594870

void FUN_00594870(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  
  CriticalSection__Enter(&DAT_007315f8);
  iVar6 = DAT_00734484;
  if ((int **)DAT_007377d0 != &DAT_007377d0) {
    do {
      piVar5 = DAT_007377d0;
      iVar1 = *DAT_007377d0;
      piVar2 = (int *)DAT_007377d0[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      puVar3 = (undefined4 *)piVar5[2];
      iVar1 = puVar3[7];
      DAT_0073448c = DAT_0073448c + -1;
      bVar4 = false;
      puVar3[7] = iVar1 + -1;
      if ((puVar3[5] != 0) && (iVar1 + -1 == 0)) {
        bVar4 = true;
      }
      if (piVar5[3] != 0) {
        CriticalSection__Leave(&DAT_007315f8);
        (*(code *)piVar5[3])(puVar3,piVar5[4]);
        CriticalSection__Enter(&DAT_007315f8);
        iVar6 = DAT_00734484;
      }
      iVar1 = *(int *)(iVar6 + 0x18);
      *piVar5 = *(int *)(iVar6 + 0x10);
      *(int *)(iVar6 + 0x18) = iVar1 + -1;
      *(int **)(iVar6 + 0x10) = piVar5;
      if (bVar4) {
        if (-1 < (int)puVar3[1]) {
          if (puVar3[4] == 0) {
            FUN_0063c2c0(puVar3[3],100);
            iVar6 = DAT_00734484;
          }
          else {
            piVar2 = (int *)(puVar3[4] + 8);
            *piVar2 = *piVar2 + -1;
          }
          puVar3[1] = 0xffffffff;
        }
        iVar1 = *(int *)(iVar6 + 0x18);
        *puVar3 = *(undefined4 *)(iVar6 + 0x10);
        *(int *)(iVar6 + 0x18) = iVar1 + -1;
        *(undefined4 **)(iVar6 + 0x10) = puVar3;
      }
    } while ((int **)DAT_007377d0 != &DAT_007377d0);
  }
  CriticalSection__Leave(&DAT_007315f8);
  return;
}


// ==== 0x594970 FUN_00594970

void FUN_00594970(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined *puVar4;
  uint uVar5;
  
  iVar2 = bOpenFile();
  if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 4), FUN_00594d40(), iVar2 != -1)) {
    iVar2 = bOpenFile();
    uVar1 = *(uint *)(iVar2 + 4);
    uVar5 = uVar1 / 0x18;
    pvVar3 = _malloc(uVar5 * 0x18);
    FUN_00594750(pvVar3,uVar1,0,0);
    do {
      if (DAT_0073448c != 0) {
        FUN_0063f0a0(0);
        FUN_00594870();
      }
    } while (*(int *)(iVar2 + 0x1c) != 0);
    FUN_00594d40();
    iVar2 = 0;
    puVar4 = &DAT_007313f8;
    DAT_00734490 = pvVar3;
    DAT_00734494 = uVar5;
    do {
      FUN_00565da0("%s%d.BIN",param_1,iVar2);
      puVar4 = puVar4 + 0x40;
      iVar2 = iVar2 + 1;
    } while ((int)puVar4 < 0x7315f8);
  }
  return;
}


// ==== 0x594a40 FUN_00594a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00594a40(undefined4 param_1,char *param_2)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint *puVar11;
  byte local_80 [128];
  
  if (DAT_00734494 == 0) {
    return 0;
  }
  iVar8 = 0;
  while( true ) {
    iVar5 = 0;
    if (param_2 != (char *)0x0) {
      cVar2 = *param_2;
      while (cVar2 != '\0') {
        iVar6 = iVar5 + 1;
        iVar5 = iVar5 + 1;
        cVar2 = param_2[iVar6];
      }
    }
    if (iVar5 <= iVar8) break;
    bVar4 = param_2[iVar8];
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 & 0x5f;
    }
    if (bVar4 == 0x2f) {
      bVar4 = 0x5c;
    }
    local_80[iVar8] = bVar4;
    iVar8 = iVar8 + 1;
  }
  local_80[iVar8] = 0;
  uVar9 = 0xffffffff;
  pbVar10 = local_80;
  while (local_80[0] != 0) {
    uVar9 = uVar9 * 0x21 + (uint)local_80[0];
    pbVar1 = pbVar10 + 1;
    pbVar10 = pbVar10 + 1;
    local_80[0] = *pbVar1;
  }
  iVar5 = 0;
  iVar8 = DAT_00734494;
  if (-1 < DAT_00734494) {
    while( true ) {
      iVar6 = iVar5 + iVar8 >> 1;
      uVar3 = *(uint *)(DAT_00734490 + iVar6 * 0x18);
      if ((uVar3 == uVar9) &&
         ((iVar6 == 0 || (*(uint *)(DAT_00734490 + iVar6 * 0x18 + -0x18) != uVar9)))) break;
      if (uVar3 < uVar9) {
        iVar5 = iVar6 + 1;
      }
      else {
        iVar8 = iVar6 + -1;
      }
      if (iVar8 < iVar5) {
        return 0;
      }
    }
    if (-1 < iVar6) {
      puVar11 = (uint *)(DAT_00734490 + iVar6 * 0x18);
      iVar5 = 0x7fffffff;
      uVar3 = *(uint *)(DAT_00734490 + iVar6 * 0x18);
      iVar8 = iVar6;
      while (uVar3 == uVar9) {
        iVar7 = puVar11[3] - _DAT_00734498;
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        if (iVar7 < iVar5) {
          iVar8 = iVar6;
          iVar5 = iVar7;
        }
        puVar11 = puVar11 + 6;
        iVar6 = iVar6 + 1;
        uVar3 = *puVar11;
      }
      return DAT_00734490 + iVar8 * 0x18;
    }
  }
  return 0;
}


// ==== 0x594b70 FUN_00594b70

void FUN_00594b70(void)

{
  undefined4 *puVar1;
  
  if (DAT_00734484 == (undefined4 *)0x0) {
    CriticalSection__Init(&DAT_007315f8);
    DAT_00734484 = (undefined4 *)FUN_00566dc0(0xe8,"bFile System",0);
    if (DAT_00734484 == (undefined4 *)0x0) {
      return;
    }
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = DAT_00734484;
      puVar1 = DAT_00734484;
      DAT_00734484[1] = DAT_0073d81c;
      DAT_0073d81c = puVar1;
      *DAT_00734484 = &DAT_0073d818;
    }
  }
  return;
}


// ==== 0x594bd0 FUN_00594bd0

void FUN_00594bd0(void)

{
  int iVar1;
  
  iVar1 = DAT_0073448c;
  if (DAT_00734484 != 0) {
    do {
      if (iVar1 != 0) {
        FUN_0063f0a0(0);
        FUN_00594870();
        iVar1 = DAT_0073448c;
      }
    } while (iVar1 != 0);
    FUN_00594470(1);
    if (DAT_00734490 != (void *)0x0) {
      _free(DAT_00734490);
      DAT_00734490 = (void *)0x0;
      DAT_00734494 = 0;
    }
    SlotPool__Destroy();
    DAT_00734484 = 0;
    FUN_0063f170(&DAT_007315f8);
  }
  return;
}


// ==== 0x594c60 bOpenFile

/* [canon] assets low (ghidra) docs/re/assets.md */

undefined4 * bOpenFile(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689608;
  local_c = ExceptionList;
  iVar3 = 0;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    do {
      iVar2 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while (param_1[iVar2] != '\0');
    if (199 < iVar3) {
      return (undefined4 *)0x0;
    }
  }
  ExceptionList = &local_c;
  if (DAT_00734484 == 0) {
    ExceptionList = &local_c;
    FUN_00594b70();
  }
  iVar3 = FUN_00567160();
  local_4 = 0;
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_005944f0(param_1,param_3);
  }
  if ((int)puVar4[1] < 0) {
    if (-1 < (int)puVar4[1]) {
      if (puVar4[4] == 0) {
        FUN_0063c2c0(puVar4[3],100);
      }
      else {
        piVar1 = (int *)(puVar4[4] + 8);
        *piVar1 = *piVar1 + -1;
      }
      puVar4[1] = 0xffffffff;
    }
    iVar2 = DAT_00734484;
    iVar3 = *(int *)(DAT_00734484 + 0x18);
    *puVar4 = *(undefined4 *)(DAT_00734484 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar3 + -1;
    *(undefined4 **)(iVar2 + 0x10) = puVar4;
    ExceptionList = local_c;
    return (undefined4 *)0x0;
  }
  ExceptionList = local_c;
  return puVar4;
}


// ==== 0x594d40 FUN_00594d40

void FUN_00594d40(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    if (0 < (int)unaff_ESI[7]) {
      unaff_ESI[5] = 1;
      return;
    }
    if (-1 < (int)unaff_ESI[1]) {
      if (unaff_ESI[4] == 0) {
        FUN_0063c2c0(unaff_ESI[3],100);
      }
      else {
        piVar1 = (int *)(unaff_ESI[4] + 8);
        *piVar1 = *piVar1 + -1;
      }
      unaff_ESI[1] = 0xffffffff;
    }
    iVar3 = DAT_00734484;
    iVar2 = *(int *)(DAT_00734484 + 0x18);
    *unaff_ESI = *(undefined4 *)(DAT_00734484 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar3 + 0x10) = unaff_ESI;
  }
  return;
}


// ==== 0x594d90 FUN_00594d90

uint FUN_00594d90(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = bOpenFile();
  if (iVar2 != 0) {
    uVar1 = *(uint *)(iVar2 + 4);
    FUN_00594d40();
    return ((int)uVar1 < 0) - 1 & uVar1;
  }
  return 0xffffffff;
}


// ==== 0x594dd0 FUN_00594dd0

void __thiscall FUN_00594dd0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar2 = DAT_0073448c;
  if ((in_EAX != 0) && (-1 < *(int *)(in_EAX + 4))) {
    FUN_00594750(param_1,param_2,0,0);
    iVar2 = DAT_0073448c;
  }
  do {
    if (iVar2 != 0) {
      FUN_0063f0a0(0);
      FUN_00594870();
      iVar2 = DAT_0073448c;
    }
    iVar1 = iVar2;
    if (in_EAX != 0) {
      iVar1 = *(int *)(in_EAX + 0x1c);
    }
  } while (iVar1 != 0);
  return;
}


// ==== 0x594e30 FUN_00594e30

undefined4 __fastcall FUN_00594e30(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bOpenFile();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 != (uint *)0x0) {
    *param_1 = *(uint *)(iVar1 + 4) & ((int)*(uint *)(iVar1 + 4) < 0) - 1;
  }
  uVar2 = FUN_00565b60(*(uint *)(iVar1 + 4) & ((int)*(uint *)(iVar1 + 4) < 0) - 1,0,0,0x2000);
  FUN_00594dd0(*(uint *)(iVar1 + 4) & ((int)*(uint *)(iVar1 + 4) < 0) - 1);
  FUN_00594d40();
  return uVar2;
}


// ==== 0x594ea0 FUN_00594ea0

void FUN_00594ea0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = bOpenFile();
  if (iVar1 != 0) {
    FUN_0063c290(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8),param_1);
    iVar2 = *(int *)(iVar1 + 8) + unaff_EDI;
    *(int *)(iVar1 + 8) = iVar2;
    if (*(int *)(iVar1 + 4) < iVar2) {
      *(int *)(iVar1 + 4) = iVar2;
    }
    FUN_00594d40();
  }
  return;
}


// ==== 0x594ef0 FUN_00594ef0

void FUN_00594ef0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = bOpenFile();
  if (iVar1 != 0) {
    FUN_0063c290(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8),param_1);
    iVar2 = *(int *)(iVar1 + 8) + unaff_EDI;
    *(int *)(iVar1 + 8) = iVar2;
    if (*(int *)(iVar1 + 4) < iVar2) {
      *(int *)(iVar1 + 4) = iVar2;
    }
    FUN_00594d40();
  }
  return;
}


// ==== 0x594f40 FUN_00594f40

void FUN_00594f40(void)

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
    FUN_00594310();
    iVar4 = DAT_00734484;
    iVar2 = *(int *)(DAT_00734484 + 0x18);
    *piVar1 = *(int *)(DAT_00734484 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x594f80 FUN_00594f80

void FUN_00594f80(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00734484;
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


// ==== 0x594fc0 _malloc

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00717d74);
  return pvVar1;
}


// ==== 0x594fd0 _free

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void __cdecl _free(void *_Memory)

{
  int iVar1;
  
  if (_Memory != (void *)0x0) {
    if (DAT_00793220 == 3) {
      __lock(4);
      iVar1 = ___sbh_find_block(_Memory);
      if (iVar1 != 0) {
        ___sbh_free_block(iVar1,_Memory);
      }
      FUN_00671155();
      if (iVar1 != 0) {
        return;
      }
    }
    HeapFree(DAT_0079321c,0,_Memory);
  }
  return;
}


// ==== 0x594fe0 FUN_00594fe0

void FUN_00594fe0(void)

{
  void *in_EAX;
  
  _free(in_EAX);
  return;
}


// ==== 0x594ff0 FUN_00594ff0

void FUN_00594ff0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_00734478;
  if ((int **)DAT_00737780 != &DAT_00737780) {
    do {
      piVar4 = DAT_00737780;
      iVar1 = *DAT_00737780;
      piVar2 = (int *)DAT_00737780[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      iVar1 = *(int *)(iVar3 + 0x18);
      *piVar4 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar4;
    } while ((int **)DAT_00737780 != &DAT_00737780);
  }
  if (iVar3 != 0) {
    SlotPool__Destroy();
    DAT_00734478 = 0;
  }
  return;
}


// ==== 0x595050 FUN_00595050

void FUN_00595050(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00734478;
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


// ==== 0x595090 FUN_00595090

void __fastcall FUN_00595090(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00734464;
  iVar1 = *(int *)(DAT_00734464 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00734464 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x5950b0 FUN_005950b0

undefined4 __fastcall FUN_005950b0(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 100) + 0xd0);
}


// ==== 0x5950c0 FUN_005950c0

void __fastcall FUN_005950c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00734468;
  iVar1 = *(int *)(DAT_00734468 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00734468 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x5950e0 FUN_005950e0

int __fastcall FUN_005950e0(int param_1)

{
  return *(int *)(param_1 + 0x6c) + 0x20;
}


// ==== 0x5950f0 FUN_005950f0

int __fastcall FUN_005950f0(int param_1)

{
  return *(int *)(param_1 + 0x6c) + 0xa0;
}


// ==== 0x595100 FUN_00595100

int __fastcall FUN_00595100(int param_1)

{
  return *(int *)(param_1 + 0x6c) + 0xb0;
}


// ==== 0x595110 FUN_00595110

int __fastcall FUN_00595110(int param_1)

{
  return *(int *)(param_1 + 0x6c) + 0x30;
}


// ==== 0x595120 FUN_00595120

int __fastcall FUN_00595120(int param_1)

{
  return *(int *)(param_1 + 0x6c) + 0xc0;
}


// ==== 0x595130 FUN_00595130

float10 __fastcall FUN_00595130(int param_1)

{
  return (float10)*(float *)(param_1 + 0xec);
}


// ==== 0x595140 FUN_00595140

void __fastcall FUN_00595140(int param_1)

{
  if (*(char *)(param_1 + 0x4c2) != '\0') {
    FUN_00584e30();
  }
  return;
}


// ==== 0x595160 FUN_00595160

int __fastcall FUN_00595160(int param_1)

{
  return (int)*(char *)(param_1 + 0x4c3);
}


// ==== 0x595170 FUN_00595170

float10 __fastcall FUN_00595170(int param_1)

{
  if (*(float *)(param_1 + 0x15c) == 0.0) {
    return (float10)*(float *)(*(int *)(param_1 + 0x6c) + 0x148);
  }
  return (float10)0.0;
}


// ==== 0x5951a0 FUN_005951a0

undefined4 * __fastcall FUN_005951a0(int param_1)

{
  int iVar1;
  
  if (*(float *)(param_1 + 0x15c) != 0.0) {
    return &DAT_00779c30;
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (*(int *)(iVar1 + 0x138) != 0) {
    return (undefined4 *)(iVar1 + 400);
  }
  return (undefined4 *)(iVar1 + 0x150);
}


// ==== 0x5951e0 FUN_005951e0

undefined4 __fastcall FUN_005951e0(int param_1)

{
  if (*(float *)(param_1 + 0x15c) == 0.0) {
    return 1;
  }
  return 0;
}


// ==== 0x595200 FUN_00595200

undefined4 __fastcall FUN_00595200(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x158) + 0xd0);
}


// ==== 0x595210 FUN_00595210

float10 __fastcall FUN_00595210(int param_1)

{
  return (float10)*(float *)(*(int *)(param_1 + 0x158) + 0xcc);
}


// ==== 0x595220 FUN_00595220

float10 __fastcall FUN_00595220(int param_1)

{
  return (float10)*(float *)(*(int *)(param_1 + 0x158) + 0xe0);
}


// ==== 0x595230 Smackables::Factory

/* [canon] props high (hopper+ghidra) docs/re/props.md */

undefined4 __thiscall
Smackables__Factory(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686af8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00567160(param_1);
  local_4 = 0;
  if (iVar1 != 0) {
    uVar2 = Smokeable__Smokeable(iVar1,param_2,param_3,param_4);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5952a0 Smackable::Loader

/* [canon] assets high (Hopper sub_5952a0 + Ghidra export FUN_005952a0: H+G agree) docs/re/assets.md
    */

undefined4 Smackable__Loader(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int iVar10;
  
  if (*param_1 != 0x34026) {
    if (*param_1 != 0x34027) {
      return 0;
    }
    DAT_00734470 = (int)param_1 + 0x17U & 0xfffffff0;
    uVar4 = ((param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1) / 0x70;
    DAT_00734474 = uVar4;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      bMatrixCopy_b();
      eOrthonormalizeMatrix();
      bMatrixCopy_b();
    }
    return 1;
  }
  uVar4 = (param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1 >> 8;
  puVar6 = (undefined4 *)((int)param_1 + 0x17U & 0xfffffff0);
  puVar3 = DAT_00737778;
  do {
    DAT_00737778 = puVar3;
    if (uVar4 == 0) {
      puVar6 = (undefined4 *)NullUpdate_ret();
      do {
        if (puVar3 == puVar6) {
          return 1;
        }
        piVar5 = puVar3 + 0x28;
        iVar7 = 4;
        do {
          puVar9 = DAT_00737778;
          if (*piVar5 != 0) {
            for (; puVar9 != puVar6; puVar9 = (undefined4 *)*puVar9) {
              if (puVar9[0x20] == *piVar5) goto LAB_005953d0;
            }
            puVar9 = (undefined4 *)0x0;
LAB_005953d0:
            piVar5[-4] = (int)puVar9;
          }
          piVar5 = piVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        puVar3 = (undefined4 *)*puVar3;
      } while( true );
    }
    *DAT_0073777c = puVar6;
    puVar3 = puVar6;
    puVar6[1] = DAT_0073777c;
    DAT_0073777c = puVar3;
    *puVar6 = &DAT_00737778;
    iVar7 = 0;
    piVar5 = &DAT_006ef2d4;
    do {
      if (*piVar5 == puVar6[0x35]) goto LAB_00595318;
      piVar5 = piVar5 + 0x25;
      iVar7 = iVar7 + 1;
    } while ((int)piVar5 < 0x6f0398);
    iVar7 = 0;
LAB_00595318:
    puVar6[0x34] = iVar7;
    iVar7 = 0;
    do {
      pbVar8 = (&PTR_DAT_006ef240)[iVar7];
      iVar10 = -1;
      bVar2 = *pbVar8;
      while (bVar2 != 0) {
        iVar10 = iVar10 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar8 + 1;
        pbVar8 = pbVar8 + 1;
        bVar2 = *pbVar1;
      }
      if (iVar10 == puVar6[0x37]) goto LAB_0059535c;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x11);
    iVar7 = 0;
LAB_0059535c:
    puVar6[0x36] = iVar7;
    puVar3 = puVar6 + 0x3e;
    *puVar3 = puVar3;
    puVar6[0x3f] = puVar3;
    puVar3 = puVar6 + 0x3c;
    *puVar3 = puVar3;
    puVar6[0x3d] = puVar3;
    puVar6 = puVar6 + 0x40;
    uVar4 = uVar4 - 1;
    puVar3 = DAT_00737778;
  } while( true );
}


// ==== 0x5954c0 Smackable::Unloader

/* [canon] assets high (Ghidra make FUN_005954c0 (Hopper export lacks it)) docs/re/assets.md */

undefined4 Smackable__Unloader(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  
  if (*param_1 == 0x34026) {
    piVar3 = (int *)((int)param_1 + 0x17U & 0xfffffff0);
    for (uVar4 = (param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1 >> 8;
        uVar4 != 0; uVar4 = uVar4 - 1) {
      iVar1 = *piVar3;
      piVar2 = (int *)piVar3[1];
      piVar3 = piVar3 + 0x40;
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    return 1;
  }
  if (*param_1 == 0x34027) {
    DAT_00734470 = 0;
    DAT_00734474 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x595530 FUN_00595530

void FUN_00595530(void)

{
  int ****ppppiVar1;
  int ***pppiVar2;
  int ***pppiVar3;
  int ***pppiVar4;
  int ****ppppiVar5;
  int ****ppppiVar6;
  int ****ppppiVar7;
  int ****ppppiVar8;
  int ***local_20;
  int ***local_1c;
  void *pvStack_14;
  code *pcStack_10;
  undefined4 local_c;
  
  pcStack_10 = FUN_006855b8;
  pvStack_14 = ExceptionList;
  ppppiVar6 = &local_20;
  local_1c = (int ***)&local_20;
  ppppiVar8 = (int ****)0x0;
  local_c = 0;
  if (DAT_00779c70 != (int ****)0x0) {
    ppppiVar8 = DAT_00779c70 + -1;
  }
  ExceptionList = &pvStack_14;
  local_20 = (int ***)ppppiVar6;
  ppppiVar5 = (int ****)Ptr_BaseAdjustMinus4();
  if (ppppiVar8 != ppppiVar5) {
    do {
      pppiVar4 = local_1c;
      ppppiVar1 = ppppiVar8 + 1;
      if (ppppiVar8[1] == (int ***)0x0) {
        ppppiVar7 = (int ****)0x0;
      }
      else {
        ppppiVar7 = (int ****)(ppppiVar8[1] + -1);
      }
      if ((*(char *)((int)ppppiVar8 + 0x15) == '\x02') ||
         (*(char *)((int)ppppiVar8 + 0x15) == '\x01')) {
        pppiVar2 = *ppppiVar1;
        pppiVar3 = ppppiVar8[2];
        *pppiVar3 = (int **)pppiVar2;
        pppiVar2[1] = (int **)pppiVar3;
        *local_1c = (int **)ppppiVar1;
        local_1c = (int ***)ppppiVar1;
        ppppiVar8[2] = pppiVar4;
        *ppppiVar1 = (int ***)&local_20;
        ppppiVar6 = (int ****)local_20;
      }
      ppppiVar8 = ppppiVar7;
    } while (ppppiVar7 != ppppiVar5);
    if (ppppiVar6 != &local_20) {
      do {
        pppiVar4 = *ppppiVar6;
        pppiVar2 = ppppiVar6[1];
        ppppiVar8 = ppppiVar6 + -1;
        *pppiVar2 = (int **)pppiVar4;
        pppiVar4[1] = (int **)pppiVar2;
        if (ppppiVar8 == (int ****)0x0) {
          ppppiVar6 = (int ****)0x0;
        }
        DAT_00779c70[1] = (int ***)ppppiVar6;
        ppppiVar6[1] = (int ***)&DAT_00779c70;
        *ppppiVar6 = (int ***)DAT_00779c70;
        DAT_00779c70 = ppppiVar6;
        if (ppppiVar8 != (int ****)0x0) {
          (*(code *)**ppppiVar8)(1);
        }
        ppppiVar6 = (int ****)local_20;
      } while ((int ****)local_20 != &local_20);
    }
  }
  local_c = 0xffffffff;
  if (ppppiVar6 != &local_20) {
    do {
      pppiVar4 = *ppppiVar6;
      pppiVar2 = ppppiVar6[1];
      *pppiVar2 = (int **)pppiVar4;
      pppiVar4[1] = (int **)pppiVar2;
      if (ppppiVar6 + -1 != (int ****)0x0) {
        (*(code *)*ppppiVar6[-1])(1);
      }
      ppppiVar6 = (int ****)local_20;
    } while ((int ****)local_20 != &local_20);
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== 0x595670 Smackables::CleanupPool

/* [canon] props high (hopper+ghidra) docs/re/props.md */

void Smackables__CleanupPool(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int aiStack_80 [32];
  
  if (DAT_00736200 != 0) {
    iVar4 = 0;
    if (DAT_00779c70 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = DAT_00779c70 + -4;
    }
    iVar2 = Ptr_BaseAdjustMinus4();
    while (iVar1 = iVar5, iVar1 != iVar2) {
      if (*(int *)(iVar1 + 4) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar1 + 4) + -4;
      }
      if (*(char *)(iVar1 + 0x15) == '\x01') {
        if (*(short *)(iVar1 + 0x18) < 0) {
          Smokeable__RespawnOrExpire();
        }
        else {
          aiStack_80[iVar4] = (int)*(short *)(iVar1 + 0x18);
          iVar4 = iVar4 + 1;
        }
      }
    }
    if (0 < iVar4) {
      iVar5 = 0;
      do {
        if (*(int *)(DAT_00736050 + aiStack_80[iVar5] * 4) != 0) {
          Smokeable__RespawnOrExpire();
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
  }
  if (*(int *)(DAT_00734468 + 0x2c) - *(int *)(DAT_00734468 + 0x18) < 4) {
    Smackables__ForceCleanup(1);
    return;
  }
  uVar3 = DAT_006f08a4 + 0x4dU & 0x8000007f;
  bVar6 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar6 = (uVar3 - 1 | 0xffffff80) == 0xffffffff;
  }
  if (bVar6) {
    Smackables__ForceCleanup(0);
  }
  return;
}


// ==== 0x595750 Smackables::ForceCleanup

/* WARNING: Type propagation algorithm not settling */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

void Smackables__ForceCleanup(char param_1)

{
  int *******pppppppiVar1;
  int *******pppppppiVar2;
  int ******ppppppiVar3;
  int ******ppppppiVar4;
  float fVar5;
  int *******pppppppiVar6;
  int *******pppppppiVar7;
  int iVar8;
  int *******pppppppiVar9;
  float *pfVar10;
  int *******pppppppiVar11;
  float10 fVar12;
  float10 fVar13;
  int *******local_34;
  int *******pppppppiStack_24;
  int *******local_20;
  int *******local_1c;
  void *local_14;
  code *pcStack_10;
  undefined4 local_c;
  
  pcStack_10 = FUN_006855b8;
  local_14 = ExceptionList;
  if (DAT_00734468 != 0) {
    pppppppiVar11 = (int *******)&local_20;
    local_20 = pppppppiVar11;
    local_1c = (int *******)&local_20;
    local_c = 0;
    ExceptionList = &local_14;
    if (param_1 == '\0') {
      if (DAT_006ef284 == 0) {
        if (DAT_00779c70 == (int *******)0x0) {
          pppppppiVar7 = (int *******)0x0;
        }
        else {
          pppppppiVar7 = DAT_00779c70 + -1;
        }
        ExceptionList = &local_14;
        pppppppiVar9 = (int *******)Ptr_BaseAdjustMinus4();
        while (pppppppiVar1 = pppppppiVar7, pppppppiVar1 != pppppppiVar9) {
          pppppppiVar2 = pppppppiVar1 + 1;
          if (pppppppiVar1[1] == (int ******)0x0) {
            pppppppiVar7 = (int *******)0x0;
          }
          else {
            pppppppiVar7 = (int *******)(pppppppiVar1[1] + -1);
          }
          pppppppiVar11 = local_20;
          if (*(char *)((int)pppppppiVar1 + 0x15) == '\x01') {
            pfVar10 = (float *)(*(code *)(*pppppppiVar1)[3])();
            if ((1000.0 < SQRT(pfVar10[2] * pfVar10[2] +
                               pfVar10[1] * pfVar10[1] + *pfVar10 * *pfVar10)) &&
               (pppppppiVar1[0x56][0x39] == (int *****)0x0)) {
              ppppppiVar3 = *pppppppiVar2;
              ppppppiVar4 = pppppppiVar1[2];
              *ppppppiVar4 = (int *****)ppppppiVar3;
              ppppppiVar3[1] = (int *****)ppppppiVar4;
              *local_1c = (int ******)pppppppiVar2;
              pppppppiVar1[2] = (int ******)local_1c;
              *pppppppiVar2 = (int ******)&local_20;
              local_1c = pppppppiVar2;
            }
            pfVar10 = (float *)(*(code *)(*pppppppiVar1)[5])();
            pppppppiVar6 = local_1c;
            pppppppiVar11 = local_20;
            if (50.0 < ABS(*pfVar10)) {
              ppppppiVar3 = *pppppppiVar2;
              ppppppiVar4 = pppppppiVar1[2];
              *ppppppiVar4 = (int *****)ppppppiVar3;
              ppppppiVar3[1] = (int *****)ppppppiVar4;
              *local_1c = (int ******)pppppppiVar2;
              local_1c = pppppppiVar2;
              pppppppiVar1[2] = (int ******)pppppppiVar6;
              *pppppppiVar2 = (int ******)&local_20;
              pppppppiVar11 = local_20;
            }
          }
        }
      }
      else {
        if (DAT_00779c70 == (int *******)0x0) {
          local_34 = (int *******)0x0;
        }
        else {
          local_34 = DAT_00779c70 + -1;
        }
        ExceptionList = &local_14;
        pppppppiVar7 = (int *******)Ptr_BaseAdjustMinus4();
        while (pppppppiVar9 = local_34, pppppppiVar9 != pppppppiVar7) {
          pppppppiVar1 = pppppppiVar9 + 1;
          if (pppppppiVar9[1] == (int ******)0x0) {
            local_34 = (int *******)0x0;
          }
          else {
            local_34 = (int *******)(pppppppiVar9[1] + -1);
          }
          if (((*(char *)((int)pppppppiVar9 + 0x15) == '\x01') &&
              (*(char *)((int)pppppppiVar9 + 0x16) != '\0')) &&
             (pppppppiVar9[0x56][0x39] == (int *****)0x0)) {
            iVar8 = (*(code *)(*pppppppiVar9)[2])();
            fVar12 = (float10)GroundQuery__FindSurfaceBelow(pppppppiVar9[0x19],iVar8,0,0,0);
            fVar13 = (float10)(*(code *)(*pppppppiVar9)[8])();
            pppppppiVar2 = local_1c;
            pppppppiVar11 = local_20;
            if (fVar13 + (float10)*(float *)(iVar8 + 8) < (float10)(float)fVar12) {
              ppppppiVar3 = *pppppppiVar1;
              ppppppiVar4 = pppppppiVar9[2];
              *ppppppiVar4 = (int *****)ppppppiVar3;
              ppppppiVar3[1] = (int *****)ppppppiVar4;
              *local_1c = (int ******)pppppppiVar1;
              local_1c = pppppppiVar1;
              pppppppiVar9[2] = (int ******)pppppppiVar2;
              *pppppppiVar1 = (int ******)&local_20;
              pppppppiVar11 = local_20;
            }
          }
        }
      }
    }
    iVar8 = *(int *)(DAT_00734468 + 0x2c) - *(int *)(DAT_00734468 + 0x18);
    if (iVar8 < 10) {
      if (DAT_00779c70 == (int *******)0x0) {
        local_34 = (int *******)0x0;
      }
      else {
        local_34 = DAT_00779c70 + -1;
      }
      pppppppiVar7 = (int *******)Ptr_BaseAdjustMinus4();
      while (pppppppiVar9 = local_34, pppppppiVar9 != pppppppiVar7) {
        pppppppiVar1 = pppppppiVar9 + 1;
        if (pppppppiVar9[1] == (int ******)0x0) {
          pppppppiStack_24 = (int *******)0x0;
        }
        else {
          pppppppiStack_24 = (int *******)(pppppppiVar9[1] + -1);
        }
        pppppppiVar11 = local_20;
        local_34 = pppppppiStack_24;
        if (*(char *)((int)pppppppiVar9 + 0x15) == '\x01') {
          (*(code *)(*pppppppiVar9)[2])();
          fVar12 = (float10)FUN_00421400();
          pppppppiVar2 = local_1c;
          if (iVar8 < 4) {
            fVar5 = 20.0;
          }
          else {
            fVar5 = 300.0;
          }
          pppppppiVar11 = local_20;
          local_34 = pppppppiStack_24;
          if ((*(char *)((int)pppppppiVar9 + 0x4c2) == '\0') &&
             (((fVar5 < (float)fVar12 ||
               (((local_34 = pppppppiStack_24, pppppppiVar9[0x5a] != (int ******)0x0 &&
                 (local_34 = pppppppiStack_24, pppppppiVar9[0x5a] != (int ******)0x7fffffff)) &&
                ((local_34 = pppppppiStack_24,
                 15.0 < (float)(DAT_0073ad34 - (int)pppppppiVar9[0x5a]) * 0.00025 &&
                 (local_34 = pppppppiStack_24, 120.0 < (float)fVar12)))))) &&
              (local_34 = pppppppiStack_24, pppppppiVar9[0x56][0x39] == (int *****)0x0)))) {
            ppppppiVar3 = *pppppppiVar1;
            ppppppiVar4 = pppppppiVar9[2];
            *ppppppiVar4 = (int *****)ppppppiVar3;
            ppppppiVar3[1] = (int *****)ppppppiVar4;
            *local_1c = (int ******)pppppppiVar1;
            local_1c = pppppppiVar1;
            pppppppiVar9[2] = (int ******)pppppppiVar2;
            *pppppppiVar1 = (int ******)&local_20;
            pppppppiVar11 = local_20;
            local_34 = pppppppiStack_24;
          }
        }
      }
    }
    if ((int ********)pppppppiVar11 != &local_20) {
      do {
        ppppppiVar3 = pppppppiVar11[1];
        ppppppiVar4 = *pppppppiVar11;
        *ppppppiVar3 = (int *****)ppppppiVar4;
        ppppppiVar4[1] = (int *****)ppppppiVar3;
        pppppppiVar7 = pppppppiVar11 + -1;
        if (pppppppiVar7 == (int *******)0x0) {
          pppppppiVar11 = (int *******)0x0;
        }
        DAT_00779c70[1] = (int ******)pppppppiVar11;
        pppppppiVar11[1] = (int ******)&DAT_00779c70;
        *pppppppiVar11 = (int ******)DAT_00779c70;
        DAT_00779c70 = pppppppiVar11;
        if (pppppppiVar7 != (int *******)0x0) {
          (*(code *)**pppppppiVar7)(1);
        }
        pppppppiVar11 = local_20;
      } while ((int ********)local_20 != &local_20);
    }
    local_c = 0xffffffff;
    if ((int ********)pppppppiVar11 != &local_20) {
      do {
        ppppppiVar3 = pppppppiVar11[1];
        ppppppiVar4 = *pppppppiVar11;
        *ppppppiVar3 = (int *****)ppppppiVar4;
        ppppppiVar4[1] = (int *****)ppppppiVar3;
        if (pppppppiVar11 + -1 != (int *******)0x0) {
          (*(code *)*pppppppiVar11[-1])(1);
        }
        pppppppiVar11 = local_20;
      } while ((int ********)local_20 != &local_20);
    }
  }
  ExceptionList = local_14;
  return;
}


// ==== 0x595b70 Smackables::IsExcluded

/* [canon] props high (hopper+ghidra) docs/re/props.md */

uint Smackables__IsExcluded(void)

{
  byte *pbVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  char *pcVar7;
  int unaff_EDI;
  
  if ((DAT_0078a2f0 != 0x4b1) || (DAT_0078a2fc != 1)) {
    return DAT_0078a2f0 & 0xffffff00;
  }
  pcVar7 = "XO_CONSTRUCSIGNA_1B_00";
  uVar6 = 0xffffffff;
  uVar3 = 0x58;
  do {
    uVar6 = uVar6 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  uVar3 = *(uint *)(unaff_EDI + 8);
  uVar4 = 0;
  if (uVar3 != uVar6) {
    uVar4 = bStringHash();
    if (uVar3 != uVar4) goto LAB_00595beb;
  }
  fVar2 = ABS(*(float *)(unaff_EDI + 0x60) - 660.0);
  uVar5 = (undefined2)(uVar4 >> 0x10);
  uVar4 = CONCAT22(uVar5,(ushort)(fVar2 < 20.0) << 8 | (ushort)NAN(fVar2) << 10 |
                         (ushort)(fVar2 == 20.0) << 0xe);
  if (fVar2 < 20.0 != (fVar2 == 20.0)) {
    fVar2 = ABS(*(float *)(unaff_EDI + 100));
    uVar4 = CONCAT22(uVar5,(ushort)(fVar2 < 20.0) << 8 | (ushort)NAN(fVar2) << 10 |
                           (ushort)(fVar2 == 20.0) << 0xe);
    if (fVar2 < 20.0 != (fVar2 == 20.0)) {
      return CONCAT31((int3)(uVar4 >> 8),1);
    }
  }
LAB_00595beb:
  return uVar4 & 0xffffff00;
}


// ==== 0x595bf0 Smackables::Init

/* [canon] props high (hopper+ghidra) docs/re/props.md */

void Smackables__Init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  puVar7 = DAT_00737778;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686bf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar6 = (undefined4 *)NullUpdate_ret();
  for (; puVar7 != puVar6; puVar7 = (undefined4 *)*puVar7) {
    FUN_00402ad0(puVar7[0x21]);
    FUN_00402ad0(puVar7[0x22]);
  }
  iVar9 = DAT_00734474;
  if (DAT_00734474 < 1) {
    iVar9 = 1;
  }
  puVar7 = (undefined4 *)FUN_00565b60(iVar9 * 0x68 + 0x30,0,0,0);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7[9] = iVar9;
    puVar7[10] = 0x68;
    puVar7[5] = 0xb;
    puVar7[4] = 0;
    puVar7[2] = 0;
    puVar7[8] = 0;
    puVar7[3] = "VirginSmokeableSlotPool";
    puVar7[0xb] = iVar9;
    puVar7[6] = 0;
    puVar7[7] = 0;
    SlotPool__BuildFreeList();
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = puVar7;
      puVar4 = puVar7;
      puVar7[1] = DAT_0073d81c;
      DAT_0073d81c = puVar4;
      *puVar7 = &DAT_0073d818;
    }
  }
  DAT_00734464 = puVar7;
  puVar7 = (undefined4 *)FUN_00565b60(0x9a30,0,0,0);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7[9] = 0x20;
    puVar7[10] = 0x4d0;
    puVar7[5] = 0xb;
    puVar7[4] = 0;
    puVar7[2] = 0;
    puVar7[8] = 0;
    puVar7[3] = "SmokeableSlotPool";
    puVar7[0xb] = 0x20;
    puVar7[6] = 0;
    puVar7[7] = 0;
    SlotPool__BuildFreeList();
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = puVar7;
      puVar4 = puVar7;
      puVar7[1] = DAT_0073d81c;
      DAT_0073d81c = puVar4;
      *puVar7 = &DAT_0073d818;
    }
  }
  DAT_0073168c = Smackables__Factory;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  DAT_00734468 = puVar7;
  if (0 < DAT_00734474) {
    local_18 = 0;
    do {
      piVar8 = (int *)(local_18 + DAT_00734470);
      if (DAT_00737778 != puVar6) {
        puVar7 = DAT_00737778;
        do {
          if (puVar7[0x20] == *piVar8) {
            cVar5 = Smackables__IsExcluded();
            puVar7 = DAT_00734464;
            if (cVar5 == '\0') {
              puVar4 = DAT_00734464 + 4;
              if ((DAT_00734464[4] == 0) && ((*(byte *)(DAT_00734464 + 5) & 1) != 0)) {
                FUN_00566e60();
              }
              puVar2 = (undefined4 *)*puVar4;
              iVar9 = puVar7[6] + 1;
              if (puVar2 != (undefined4 *)0x0) {
                uVar3 = *puVar2;
                if ((int)puVar7[7] < iVar9) {
                  puVar7[7] = iVar9;
                }
                puVar7[6] = iVar9;
                bVar1 = *(byte *)(puVar7 + 5);
                *puVar4 = uVar3;
                if (((bVar1 & 2) != 0) && (iVar9 = (int)puVar7[10] >> 2, puVar7 = puVar2, 0 < iVar9)
                   ) {
                  for (; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                  }
                }
              }
              local_4 = 0;
              if (puVar2 != (undefined4 *)0x0) {
                VirginSmokeable__VirginSmokeable(puVar2,piVar8);
              }
              local_4 = 0xffffffff;
            }
            goto LAB_00595e60;
          }
          puVar7 = (undefined4 *)*puVar7;
        } while (puVar7 != puVar6);
      }
      if ((*piVar8 != local_20) && (local_24 = local_24 + 1, local_24 < 4)) {
        local_20 = *piVar8;
      }
LAB_00595e60:
      local_1c = local_1c + 1;
      local_18 = local_18 + 0x70;
    } while (local_1c < DAT_00734474);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x595ea0 FUN_00595ea0

void FUN_00595ea0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_00595530();
  if (DAT_00734464 != 0) {
    SlotPool__Destroy();
    DAT_00734464 = 0;
  }
  if (DAT_00734468 != 0) {
    SlotPool__Destroy();
    DAT_00734468 = 0;
  }
  puVar4 = DAT_00737778;
  puVar5 = (undefined4 *)NullUpdate_ret();
  for (; puVar4 != puVar5; puVar4 = (undefined4 *)*puVar4) {
    piVar1 = (int *)puVar4[0x3e];
    while (piVar1 != puVar4 + 0x3e) {
      piVar2 = (int *)piVar1[1];
      iVar3 = *piVar1;
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
      FUN_00401db0();
      _free(piVar1);
      piVar1 = (int *)puVar4[0x3e];
    }
    piVar1 = (int *)puVar4[0x3c];
    while (piVar1 != puVar4 + 0x3c) {
      piVar2 = (int *)piVar1[1];
      iVar3 = *piVar1;
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
      FUN_00401db0();
      _free(piVar1);
      piVar1 = (int *)puVar4[0x3c];
    }
  }
  return;
}


// ==== 0x595f70 Smackables::SaveState

/* [canon] props high (hopper+ghidra) docs/re/props.md */

void Smackables__SaveState(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uVar1 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686bf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00571ea0(0,"AllSmokeables");
  FUN_00571c20(uVar1,&DAT_0073446c,4,4,1);
  if (*(char *)(uVar1 + 0x3d) == '\0') {
    if (DAT_00779c70 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(DAT_00779c70 + -4);
    }
    piVar5 = (int *)Ptr_BaseAdjustMinus4();
    while (piVar3 != piVar5) {
      if (*(char *)((int)piVar3 + 0x15) == '\x02') {
        param_1 = (piVar3[0x18] - DAT_00734470) / 0x70;
        FUN_00571c20(uVar1,&param_1,2,2,1);
        (**(code **)(*piVar3 + 4))(uVar1);
      }
      if (piVar3[1] == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(piVar3[1] + -4);
      }
    }
    local_28 = (undefined4 *)0xffffffff;
    FUN_00571c20(uVar1,&local_28,2,2,1);
    if (DAT_00779c70 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(DAT_00779c70 + -4);
    }
    while (piVar3 != piVar5) {
      if (*(char *)((int)piVar3 + 0x15) == '\x01') {
        iVar9 = piVar3[0x56];
        uStack_18 = (uint)*(ushort *)(piVar3 + 6);
        uStack_14 = *(undefined4 *)(piVar3[0x112] + 8);
        local_10 = (undefined4 *)(**(code **)(*piVar3 + 0x78))();
        FUN_00571c20(uVar1,&uStack_18,2,2,0);
        FUN_00571c20(uVar1,iVar9 + 0x80,4,4,0);
        FUN_00571c20(uVar1,&uStack_14,4,4,0);
        FUN_00571c20(uVar1,&local_10,1,4,1);
        (**(code **)(*piVar3 + 4))(uVar1);
      }
      if (piVar3[1] == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(piVar3[1] + -4);
      }
    }
    FUN_00571c20(uVar1,&local_28,2,2,1);
  }
  else {
    FUN_00595530();
    while( true ) {
      FUN_00571c20(uVar1,&param_1,2,2,0);
      iVar9 = DAT_00734464;
      if ((short)param_1 == -1) break;
      iVar7 = (param_1 & 0xffff) * 0x70 + DAT_00734470;
      local_28 = (undefined4 *)(DAT_00734464 + 0x10);
      if ((*(int *)(DAT_00734464 + 0x10) == 0) && ((*(byte *)(DAT_00734464 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      local_10 = (undefined4 *)*local_28;
      iVar2 = *(int *)(iVar9 + 0x18) + 1;
      if (local_10 != (undefined4 *)0x0) {
        puVar8 = (undefined4 *)*local_10;
        if (*(int *)(iVar9 + 0x1c) < iVar2) {
          *(int *)(iVar9 + 0x1c) = iVar2;
        }
        *(int *)(iVar9 + 0x18) = iVar2;
        *local_28 = puVar8;
        local_28 = puVar8;
        if (((*(byte *)(iVar9 + 0x14) & 2) != 0) &&
           (iVar9 = *(int *)(iVar9 + 0x28) >> 2, puVar8 = local_10, 0 < iVar9)) {
          for (; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
          }
        }
      }
      piVar3 = (int *)0x0;
      local_4 = 0;
      if (local_10 != (undefined4 *)0x0) {
        piVar3 = (int *)VirginSmokeable__VirginSmokeable(local_10,iVar7);
      }
      local_4 = 0xffffffff;
      (**(code **)(*piVar3 + 4))(uVar1);
    }
    while( true ) {
      FUN_00571c20(uVar1,&param_1,2,2,0);
      if ((short)param_1 == -1) break;
      FUN_00571c20(uVar1,&local_24,4,4,0);
      FUN_00571c20(uVar1,&local_20,4,4,0);
      FUN_00571c20(uVar1,&local_1c,1,4,1);
      puVar8 = DAT_00737778;
      puVar4 = (undefined4 *)NullUpdate_ret();
      for (; puVar8 != puVar4; puVar8 = (undefined4 *)*puVar8) {
        if (puVar8[0x20] == local_24) goto LAB_00596100;
      }
      puVar8 = (undefined4 *)0x0;
LAB_00596100:
      piVar3 = (int *)(*(code *)(&DAT_0073168c)[local_1c])(param_1 & 0xffff,puVar8,local_20);
      (**(code **)(*piVar3 + 4))(uVar1);
    }
  }
  iVar9 = *(char *)(uVar1 + 0x40) * 0x10 + 0x4c + uVar1;
  *(int *)(iVar9 + 0xc) = *(int *)(uVar1 + 0x150) - *(int *)(iVar9 + 0xc);
  cVar6 = *(char *)(uVar1 + 0x40) + -1;
  *(char *)(uVar1 + 0x40) = cVar6;
  if ((int)cVar6 < *(int *)(uVar1 + 0x44)) {
    *(undefined4 *)(uVar1 + 0x44) = 0xffffffff;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x5962c0 FUN_005962c0

undefined4 FUN_005962c0(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  
  uVar1 = VirginSmokeable__Wake();
  if (in_EAX != (undefined4 *)0x0) {
    (**(code **)*in_EAX)(1);
  }
  return uVar1;
}


// ==== 0x5962e0 VirginSmokeable::VirginSmokeable

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

undefined4 * VirginSmokeable__VirginSmokeable(undefined4 *param_1,int *param_2)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  char *pcVar8;
  int *piVar9;
  int iVar10;
  char local_50 [48];
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00685cbb;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CollisionBody__CollisionBody(param_1,2);
  *param_1 = &PTR_FUN_006c8720;
  DAT_0073600c = DAT_0073600c + 1;
  if (DAT_00736034 < DAT_0073600c) {
    DAT_00736034 = DAT_0073600c;
  }
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *param_1 = &PTR_FUN_006b8a90;
  local_14 = 0;
  DAT_00736020 = DAT_00736020 + 1;
  if (DAT_00736048 < DAT_00736020) {
    DAT_00736048 = DAT_00736020;
  }
  param_1[0x18] = param_2;
  piVar9 = DAT_00737778;
  piVar7 = (int *)NullUpdate_ret();
  if (piVar9 != piVar7) {
    do {
      if (piVar9[0x20] == *param_2) goto LAB_005963b5;
      piVar9 = (int *)*piVar9;
    } while (piVar9 != piVar7);
  }
  piVar9 = (int *)0x0;
LAB_005963b5:
  param_1[0x19] = piVar9;
  param_2[3] = (int)param_1;
  if (*(int *)(&DAT_0072a008 + *(short *)(param_1[0x18] + 4) * 4) != 0) {
    pbVar1 = (byte *)(*(short *)(param_1[0x18] + 6) * 0x30 +
                      *(int *)(*(int *)(&DAT_0072a008 + *(short *)(param_1[0x18] + 4) * 4) + 0x20) +
                     0xe);
    *pbVar1 = *pbVar1 & 0xef;
  }
  FUN_00565da0("VirginSmokeable%s",param_1[0x19] + 8);
  pcVar8 = (char *)(param_1 + 0xd);
  iVar10 = 0x28;
  iVar3 = -(int)pcVar8;
  do {
    cVar2 = pcVar8[(int)(local_50 + iVar3)];
    iVar10 = iVar10 + -1;
    *pcVar8 = cVar2;
    if (cVar2 == '\0') break;
    pcVar8 = pcVar8 + 1;
  } while (iVar10 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  param_1[4] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  CollisionBody__SetBBoxMinMax(param_1,param_1[0x18] + 0x10);
  iVar3 = param_1[0x18];
  fVar4 = *(float *)(iVar3 + 0x20) - *(float *)(iVar3 + 0x10);
  fVar5 = *(float *)(iVar3 + 0x24) - *(float *)(iVar3 + 0x14);
  fVar6 = *(float *)(iVar3 + 0x28) - *(float *)(iVar3 + 0x18);
  param_1[8] = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5) * _K_HALF;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x596490 FUN_00596490

undefined4 * __thiscall FUN_00596490(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  VirginSmokeable___VirginSmokeable();
  iVar2 = DAT_00734464;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00734464 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00734464 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x5964c0 VirginSmokeable::_VirginSmokeable

/* [canon] props high (hopper+ghidra) docs/re/props.md */

void __fastcall VirginSmokeable___VirginSmokeable(undefined4 *param_1)

{
  byte *pbVar1;
  
  *param_1 = &PTR_FUN_006b8a90;
  if (*(int *)(&DAT_0072a008 + *(short *)(param_1[0x18] + 4) * 4) != 0) {
    pbVar1 = (byte *)(*(short *)(param_1[0x18] + 6) * 0x30 +
                      *(int *)(*(int *)(&DAT_0072a008 + *(short *)(param_1[0x18] + 4) * 4) + 0x20) +
                     0xe);
    *pbVar1 = *pbVar1 | 0x10;
  }
  *(undefined4 *)(param_1[0x18] + 0xc) = 0;
  DAT_00736020 = DAT_00736020 + -1;
  *param_1 = &PTR_FUN_006c8720;
  DAT_0073600c = DAT_0073600c + -1;
  CollisionBody___CollisionBody();
  return;
}


// ==== 0x596510 FUN_00596510

void FUN_00596510(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"VirginSmokeable");
  CollisionBody__DoSnapshot(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x596570 VirginSmokeable::Wake

/* [canon] props high (hopper+ghidra) docs/re/props.md */

int * VirginSmokeable__Wake(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  float10 fVar4;
  char cStack_345;
  float fStack_344;
  undefined1 auStack_340 [8];
  float fStack_338;
  float fStack_328;
  undefined1 local_320 [48];
  undefined1 auStack_2f0 [8];
  float fStack_2e8;
  undefined1 auStack_2d0 [32];
  int aiStack_2b0 [160];
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(int *)(DAT_00734468 + 0x18) != *(int *)(DAT_00734468 + 0x2c)) {
    bMatrixCopy_b();
    piVar2 = (int *)(*DAT_0073168c)(*(uint *)(DAT_00736070 + 8) & 0xffff,
                                    *(undefined4 *)(unaff_EDI + 100),
                                    *(undefined4 *)(*(int *)(unaff_EDI + 0x60) + 8));
    iVar3 = (**(code **)(*piVar2 + 0x78))();
    if (iVar3 == 0) {
      iStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      FUN_00440740();
      fVar4 = (float10)GroundQuery__FindSurfaceBelow
                                 (auStack_2d0,auStack_2f0,0,auStack_340,&cStack_345);
      fStack_344 = (float)fVar4;
      if (cStack_345 != '\0') {
        Car__GetMatrixRows01();
        fVar1 = (fStack_344 -
                ((fStack_328 + *(float *)(piVar2[0x56] + 0xb8)) * fStack_338 + fStack_2e8)) + 0.05;
        if (0.0 < fVar1) {
          piVar2[0x5d] = (int)fVar1;
          fStack_2e8 = fVar1 + fStack_2e8;
        }
      }
      iVar3 = 0;
      if (0 < iStack_30) {
        do {
          *(char *)(aiStack_2b0[iVar3] + 8) = *(char *)(aiStack_2b0[iVar3] + 8) + -1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iStack_30);
      }
    }
    piVar2[0x5c] = *(int *)(unaff_EDI + 0x60);
    FUN_00597140(local_320,0);
    return piVar2;
  }
  return (int *)0x0;
}


// ==== 0x5966d0 Smokeable::Smokeable

/* [canon] props high (hopper+ghidra) docs/re/props.md */

undefined4 * Smokeable__Smokeable(undefined4 *param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  void *pvVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  byte *pbVar15;
  undefined4 *puVar16;
  int *piVar17;
  bool bVar18;
  char local_3c [48];
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686ade;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CollisionBody__CollisionBody(param_1,1);
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  param_1[0x19] = param_1 + 0x5e;
  DAT_00736010 = DAT_00736010 + 1;
  if (DAT_00736038 < DAT_00736010) {
    DAT_00736038 = DAT_00736010;
  }
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 1;
  param_1[0x18] = 0;
  param_1[0x4c] = 0;
  puVar16 = param_1 + 0x53;
  param_1[0x50] = &PTR_FUN_006c85a8;
  *puVar16 = puVar16;
  param_1[0x54] = puVar16;
  local_4 = 0;
  param_1[0x55] = 0;
  *param_1 = &PTR_FUN_006b8b18;
  param_1[0x50] = &PTR_FUN_006b8b08;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x106] = 0;
  param_1[0x107] = 0;
  param_1[0x108] = 0;
  param_1[0x109] = 0;
  param_1[0x10b] = 0;
  param_1[0x10c] = 0;
  param_1[0x10d] = 0;
  FUN_00440740();
  local_4 = CONCAT31(local_4._1_3_,2);
  puVar16 = param_1 + 0x110;
  iVar7 = FUN_00567160();
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004454d0();
  }
  param_1[0x112] = uVar8;
  param_1[0x113] = 0;
  param_1[0x115] = 1;
  param_1[0x116] = 0;
  param_1[0x114] = 0;
  param_1[0x128] = 0;
  *DAT_00737820 = puVar16;
  puVar6 = puVar16;
  param_1[0x111] = DAT_00737820;
  DAT_00737820 = puVar6;
  *puVar16 = &DAT_0073781c;
  *(undefined1 *)(param_1 + 0x117) = 0;
  puVar16 = param_1 + 300;
  *puVar16 = puVar16;
  param_1[0x12d] = puVar16;
  puVar16 = param_1 + 0x12e;
  *puVar16 = puVar16;
  param_1[0x12f] = puVar16;
  DAT_00736024 = DAT_00736024 + 1;
  local_4 = CONCAT31(local_4._1_3_,5);
  if (DAT_0073604c < DAT_00736024) {
    DAT_0073604c = DAT_00736024;
  }
  pcVar10 = (char *)(param_1 + 0x51);
  *pcVar10 = 'S';
  pcVar9 = pcVar10;
  do {
    cVar3 = pcVar9[(int)("Smokabl" + (1 - (int)pcVar10))];
    pcVar9 = pcVar9 + 1;
    *pcVar9 = cVar3;
  } while (cVar3 != '\0');
  iVar7 = FUN_00567160();
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00584800();
  }
  param_1[0x1b] = uVar8;
  param_1[0x1a] = param_1 + 0x50;
  param_1[0x18] = 1;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  param_1[0x131] = 0;
  *(undefined1 *)(param_1 + 0x132) = 0;
  param_1[0x59] = DAT_0073ad34;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  FUN_00565da0("Smokeable%s",param_3 + 8);
  pcVar10 = (char *)(param_1 + 0xd);
  iVar14 = 0x28;
  iVar7 = -(int)pcVar10;
  do {
    cVar3 = pcVar10[(int)(local_3c + iVar7)];
    iVar14 = iVar14 + -1;
    *pcVar10 = cVar3;
    if (cVar3 == '\0') break;
    pcVar10 = pcVar10 + 1;
  } while (iVar14 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  iVar7 = CarShape_Find(param_3 + 0xb0);
  if (iVar7 == 0) {
    pvVar11 = _malloc(0x40);
    if (pvVar11 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      *(code **)((int)pvVar11 + 8) = FUN_00473dd0;
      *(code **)((int)pvVar11 + 0xc) = FUN_00473d60;
      *(undefined4 *)((int)pvVar11 + 0x10) = 3;
      *(undefined4 *)((int)pvVar11 + 0x14) = 8;
      iVar7 = CollisionShapes__DefaultBox
                        (0xbfc00000,0xbfc00000,0xbfc00000,0x3fc00000,0x3fc00000,0x3fc00000);
    }
  }
  param_1[4] = iVar7;
  DynamicCollisionBody__BuildBoundingVolumes();
  piVar12 = (int *)param_1[0x1b];
  if (piVar12 == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = piVar12 + 1;
  }
  puVar16 = (undefined4 *)param_1[0x54];
  *puVar16 = piVar13;
  param_1[0x54] = piVar13;
  piVar13[1] = (int)puVar16;
  *piVar13 = (int)(param_1 + 0x53);
  iVar7 = (**(code **)(*piVar12 + 4))();
  param_1[0x55] = param_1[0x55] + iVar7;
  param_1[0x56] = param_3;
  param_1[0x5c] = 0;
  *(undefined1 *)((int)param_1 + 0x4c2) = 0;
  *(undefined1 *)((int)param_1 + 0x4c3) = 0;
  param_1[0x57] = *(undefined4 *)(param_3 + 0xc4);
  param_1[0x58] = *(undefined4 *)(param_3 + 200);
  param_1[0x5d] = 0;
  iVar7 = Smokeable__BuildChildPart();
  if (iVar7 == 0) {
    param_1[0x58] = 0;
  }
  RigidBody__SetMassInertia();
  *(undefined1 *)(param_1 + 0x130) = 0;
  *(undefined1 *)((int)param_1 + 0x4c1) = 0;
  if ((*(int *)(param_3 + 0x84) != 0) &&
     (param_2 = *(int **)(param_1[0x56] + 0xf8), param_2 != (int *)(param_1[0x56] + 0xf8))) {
    do {
      pvVar11 = _malloc(0xc0);
      if (pvVar11 != (void *)0x0) {
        puVar16 = (undefined4 *)((int)pvVar11 + 8);
        for (iVar7 = 0x2e; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        DAT_00736538 = DAT_00736538 + 1;
        Node_SetNameAndHash();
        if (param_2[7] != 0) {
          *(int *)((int)pvVar11 + 0x1c) = param_2[7];
        }
        bMatrixCopy_b();
        bVar18 = DAT_007349b4 == 0;
        *(undefined4 *)((int)pvVar11 + 0x10) = 1;
        if (bVar18) {
          FUN_005649f0();
        }
        piVar12 = (int *)FUN_00567160();
        if (piVar12 == (int *)0x0) {
          piVar12 = (int *)0x0;
        }
        else {
          piVar12[2] = (int)pvVar11;
        }
        iVar7 = param_1[300];
        param_1[300] = piVar12;
        *(int **)(iVar7 + 4) = piVar12;
        piVar12[1] = (int)(param_1 + 300);
        *piVar12 = iVar7;
      }
      param_2 = (int *)*param_2;
    } while (param_2 != (int *)(param_1[0x56] + 0xf8));
  }
  if ((*(int *)(param_3 + 0x88) != 0) &&
     (piVar12 = *(int **)(param_1[0x56] + 0xf0), piVar12 != (int *)(param_1[0x56] + 0xf0))) {
    do {
      pvVar11 = _malloc(0xc0);
      if (pvVar11 != (void *)0x0) {
        piVar13 = (int *)((int)pvVar11 + 8);
        for (iVar7 = 0x2e; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
        DAT_00736538 = DAT_00736538 + 1;
        pbVar2 = (byte *)(piVar12 + 0x20);
        iVar7 = -1;
        bVar4 = *pbVar2;
        pbVar15 = pbVar2;
        while (bVar4 != 0) {
          iVar7 = iVar7 * 0x21 + (uint)bVar4;
          pbVar1 = pbVar15 + 1;
          pbVar15 = pbVar15 + 1;
          bVar4 = *pbVar1;
        }
        pcVar10 = (char *)((int)pvVar11 + 0x80);
        *(int *)((int)pvVar11 + 8) = iVar7;
        iVar14 = 0x3f;
        iVar7 = (int)pbVar2 - (int)pcVar10;
        do {
          cVar3 = pcVar10[iVar7];
          iVar14 = iVar14 + -1;
          *pcVar10 = cVar3;
          if (cVar3 == '\0') break;
          pcVar10 = pcVar10 + 1;
        } while (iVar14 != 0);
        *(undefined1 *)((int)pvVar11 + 0xbf) = 0;
        if (piVar12[7] != 0) {
          *(int *)((int)pvVar11 + 0x1c) = piVar12[7];
        }
        bMatrixCopy_b();
        iVar7 = DAT_007349b4;
        bVar18 = DAT_007349b4 == 0;
        *(undefined4 *)((int)pvVar11 + 0x10) = 1;
        if (bVar18) {
          FUN_005649f0();
          iVar7 = DAT_007349b4;
        }
        if ((*(int *)(iVar7 + 0x10) == 0) && ((*(byte *)(iVar7 + 0x14) & 1) != 0)) {
          FUN_00566e60();
        }
        piVar13 = *(int **)(iVar7 + 0x10);
        iVar14 = *(int *)(iVar7 + 0x18) + 1;
        if (piVar13 == (int *)0x0) {
          piVar13 = (int *)0x0;
        }
        else {
          iVar5 = *piVar13;
          if (*(int *)(iVar7 + 0x1c) < iVar14) {
            *(int *)(iVar7 + 0x1c) = iVar14;
          }
          *(int *)(iVar7 + 0x18) = iVar14;
          *(int *)(iVar7 + 0x10) = iVar5;
          if (((*(byte *)(iVar7 + 0x14) & 2) != 0) &&
             (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar17 = piVar13, 0 < iVar7)) {
            for (; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar17 = 0;
              piVar17 = piVar17 + 1;
            }
          }
          piVar13[2] = (int)pvVar11;
        }
        iVar7 = param_1[0x12e];
        param_1[0x12e] = piVar13;
        *(int **)(iVar7 + 4) = piVar13;
        piVar13[1] = (int)(param_1 + 0x12e);
        *piVar13 = iVar7;
      }
      piVar12 = (int *)*piVar12;
    } while (piVar12 != (int *)(param_1[0x56] + 0xf0));
  }
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x596c90 FUN_00596c90

undefined4 * __thiscall FUN_00596c90(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00596cc0();
  iVar2 = DAT_00734468;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00734468 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00734468 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x596cc0 FUN_00596cc0

void __fastcall FUN_00596cc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *_Memory;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00686a79;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006b8b18;
  param_1[0x50] = &PTR_FUN_006b8b08;
  puVar1 = DAT_00779bd8;
  DAT_00736024 = DAT_00736024 + -1;
  iVar4 = *(int *)(param_1[0x56] + 0x80);
  local_4 = 5;
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[6] == iVar4) goto LAB_00596d41;
  }
  if ((void *)param_1[4] != (void *)0x0) {
    _free((void *)param_1[4]);
  }
LAB_00596d41:
  iVar4 = DAT_007349b4;
  if ((undefined4 *)param_1[300] != param_1 + 300) {
    do {
      piVar5 = (int *)param_1[300];
      iVar6 = *piVar5;
      piVar7 = (int *)piVar5[1];
      piVar2 = (int *)piVar5[2];
      *piVar7 = iVar6;
      *(int **)(iVar6 + 4) = piVar7;
      iVar6 = *(int *)(iVar4 + 0x18);
      *piVar5 = *(int *)(iVar4 + 0x10);
      *(int **)(iVar4 + 0x10) = piVar5;
      iVar6 = iVar6 + -1;
      bVar8 = DAT_007349b8 != 0;
      *(int *)(iVar4 + 0x18) = iVar6;
      if (bVar8) {
        if (iVar6 == 0) {
          SlotPool__Destroy();
          iVar4 = 0;
          DAT_007349b4 = 0;
        }
        else {
          DAT_007349b8 = 1;
        }
      }
      if (*(char *)(param_1 + 0x130) != '\0') {
        iVar6 = *piVar2;
        piVar5 = (int *)piVar2[1];
        *piVar5 = iVar6;
        *(int **)(iVar6 + 4) = piVar5;
        DAT_0078ea30 = DAT_0078ea30 + -1;
      }
      if (piVar2 != (int *)0x0) {
        DAT_00736538 = DAT_00736538 + -1;
        _free(piVar2);
        iVar4 = DAT_007349b4;
      }
    } while ((undefined4 *)param_1[300] != param_1 + 300);
  }
  piVar7 = param_1 + 0x12e;
  piVar5 = (int *)param_1[0x12e];
  while (piVar5 != piVar7) {
    piVar5 = (int *)*piVar7;
    iVar6 = *piVar5;
    piVar2 = (int *)piVar5[1];
    _Memory = (int *)piVar5[2];
    *piVar2 = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    iVar6 = *(int *)(iVar4 + 0x18);
    *piVar5 = *(int *)(iVar4 + 0x10);
    *(int **)(iVar4 + 0x10) = piVar5;
    iVar6 = iVar6 + -1;
    bVar8 = DAT_007349b8 != 0;
    *(int *)(iVar4 + 0x18) = iVar6;
    if (bVar8) {
      if (iVar6 == 0) {
        SlotPool__Destroy();
        iVar4 = 0;
        DAT_007349b4 = 0;
      }
      else {
        DAT_007349b8 = 1;
      }
    }
    if (*(char *)((int)param_1 + 0x4c1) != '\0') {
      iVar6 = *_Memory;
      piVar5 = (int *)_Memory[1];
      *piVar5 = iVar6;
      *(int **)(iVar6 + 4) = piVar5;
      DAT_0078ea30 = DAT_0078ea30 + -1;
    }
    if (_Memory != (int *)0x0) {
      DAT_00736538 = DAT_00736538 + -1;
      _free(_Memory);
      iVar4 = DAT_007349b4;
    }
    piVar5 = (int *)*piVar7;
  }
  local_4._1_3_ = (uint3)((uint)local_4 >> 8);
  local_4._0_1_ = 4;
  FUN_00421900();
  local_4._0_1_ = 3;
  FUN_00421900();
  local_4._0_1_ = 2;
  FUN_00591c90(param_1 + 0x110);
  iVar4 = param_1[0x106];
  if (0 < iVar4) {
    piVar5 = param_1 + 0x66;
    do {
      iVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
      *(char *)(iVar6 + 8) = *(char *)(iVar6 + 8) + -1;
    } while (iVar4 != 0);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  PhysicsSystem___PhysicsSystem();
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  DAT_00736010 = DAT_00736010 + -1;
  local_4 = 0xffffffff;
  CollisionBody___CollisionBody();
  ExceptionList = local_c;
  return;
}


// ==== 0x596f50 Smackables::RestoreState

/* [canon] props high (hopper+ghidra) docs/re/props.md */

void __thiscall Smackables__RestoreState(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = param_2;
  FUN_00571ea0(param_1,"Smokeable");
  DynamicCollisionBody__DoSnapshot(iVar1);
  FUN_00571c20(iVar1,param_1 + 0x4c2,1,1,1);
  FUN_00571c20(iVar1,param_1 + 0x4c3,1,1,1);
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,*(int *)(param_1 + 0x158) + 0x80,4,4,0);
  }
  FUN_00571c20(iVar1,param_1 + 0x15c,4,0xffffffff,0);
  FUN_00571c20(iVar1,param_1 + 0x160,4,0xffffffff,0);
  FUN_00571c20(iVar1,param_1 + 0x168,4,0xffffffff,0);
  FUN_00571c20(iVar1,param_1 + 0x164,4,0xffffffff,0);
  FUN_00571c20(iVar1,param_1 + 0x16c,4,0xffffffff,0);
  FUN_00571c20(iVar1,param_1 + 0x174,4,0xffffffff,0);
  if (*(char *)(iVar1 + 0x3d) == '\0') {
    if (*(int *)(param_1 + 0x170) == 0) {
      param_2 = -1;
    }
    else {
      param_2 = (*(int *)(param_1 + 0x170) - DAT_00734470) / 0x70;
    }
    FUN_00571c20(iVar1,&param_2,2,2,1);
  }
  else {
    FUN_00571c20(iVar1,&param_2,2,2,1);
    if ((short)param_2 < 0) {
      *(undefined4 *)(param_1 + 0x170) = 0;
    }
    else {
      *(int *)(param_1 + 0x170) = (short)param_2 * 0x70 + DAT_00734470;
    }
  }
  FUN_00584960();
  if (*(char *)(iVar1 + 0x3c) != '\0' || *(char *)(iVar1 + 0x3d) != '\0') {
    DynamicCollisionBody__UpdatePosition();
  }
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,param_1 + 0x24,8,0xffffffff,0);
  }
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,param_1 + 0x2c,8,0xffffffff,0);
  }
  iVar2 = *(char *)(iVar1 + 0x40) * 0x10;
  *(int *)(iVar2 + iVar1 + 0x58) = *(int *)(iVar1 + 0x150) - *(int *)(iVar2 + 0x58 + iVar1);
  cVar3 = *(char *)(iVar1 + 0x40) + -1;
  *(char *)(iVar1 + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(iVar1 + 0x44)) {
    *(undefined4 *)(iVar1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x597140 FUN_00597140

void __thiscall FUN_00597140(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  undefined4 *in_EAX;
  float unaff_EBX;
  float unaff_ESI;
  int *piVar5;
  float fStack_e4;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  float fStack_b4;
  undefined1 local_b0 [16];
  undefined1 local_a0 [48];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float fStack_24;
  
  local_dc = *(undefined4 *)(param_2 + 0x34);
  local_d8 = *(undefined4 *)(param_2 + 0x38);
  bMatrixCopy_b();
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 1.0;
  local_c0 = 0;
  local_bc = 0.0;
  local_b8 = 0.0;
  if (in_EAX != (undefined4 *)0x0) {
    local_bc = (float)in_EAX[1];
    local_c0 = *in_EAX;
    local_b8 = (float)in_EAX[2];
  }
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  if (param_3 != (undefined4 *)0x0) {
    local_cc = param_3[1];
    local_d0 = *param_3;
    local_c8 = param_3[2];
  }
  D3DXVec3Transform(local_b0,*(int *)(param_1 + 0x158) + 0xb0,local_a0);
  fVar3 = local_bc + unaff_ESI;
  fVar4 = local_b8 + unaff_EBX;
  local_64 = fStack_b4 + fStack_e4;
  FUN_00584b80(&local_cc,&local_dc);
  bMatrixCopy_b();
  fStack_24 = fStack_24 - *(float *)(param_1 + 0x174);
  iVar1 = *(int *)(param_1 + 0x4a0);
  *(undefined4 *)(param_1 + 0x450) = 1;
  if (iVar1 == 0) {
    bMatrixCopy_b();
  }
  else {
    bMatrixCopy_b();
    if (*(int *)(iVar1 + 0xe4) == 0) {
      FUN_00579190();
    }
  }
  *(float *)(param_1 + 0xc0) = fVar3;
  *(float *)(param_1 + 0xc4) = fVar4;
  *(float *)(param_1 + 200) = fStack_b4 + fStack_e4;
  bMatrixCopy_b();
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0x459c4000;
  (**(code **)(*(int *)(param_1 + 0x140) + 4))();
  DynamicCollisionBody__UpdatePosition();
  piVar5 = *(int **)(param_1 + 0x4b0);
  if (piVar5 != (int *)(param_1 + 0x4b0)) {
    do {
      bMatrixCopy_b();
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)(param_1 + 0x4b0));
  }
  for (puVar2 = *(undefined4 **)(param_1 + 0x4b8); puVar2 != (undefined4 *)(param_1 + 0x4b8);
      puVar2 = (undefined4 *)*puVar2) {
    bMatrixCopy_b();
  }
  return;
}


// ==== 0x597390 FUN_00597390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597390(void)

{
  FUN_00584cd0();
  return;
}


// ==== 0x597420 Smokeable::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

void __thiscall Smokeable__Update(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float fStack_7c;
  float local_78;
  float local_74;
  undefined1 local_70 [12];
  float fStack_64;
  undefined1 auStack_5c [48];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  
  DynamicCollisionBody__BeginMove(param_2);
  if (*(char *)((int)param_1 + 0x4c2) != '\0') {
    RigidBody__SetMassInertia();
    *(undefined4 *)(param_1[0x1b] + 0x130) = 1;
    local_78 = 0.0;
    if ((*(int *)(param_1[0x112] + 8) == -0x6739fdc4) ||
       (*(int *)(param_1[0x112] + 8) == -0x7538f18a)) {
      local_78 = 1.4013e-45;
    }
    iVar2 = _ftol_nocw();
    iVar2 = iVar2 + 1;
    local_74 = param_2 / (float)iVar2;
    if (0 < iVar2) {
      do {
        if (local_78 != 0.0) {
          FUN_00597390();
        }
        FUN_0046aa40(param_1 + 0x50,local_74);
        eOrthonormalizeMatrix();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00597b80();
    FUN_00597670();
    iVar2 = FUN_005980d0();
    if (iVar2 != 0) {
      param_1[0x5b] = DAT_0073ad34;
    }
  }
  D3DXVec3Transform(local_70,param_1[0x56] + 0xb0,param_1[0x1b] + 0x30);
  bMatrixCopy_b();
  iVar2 = param_1[0x1b];
  fStack_2c = *(float *)(iVar2 + 0x20) - fStack_7c;
  uStack_20 = 0x3f800000;
  fStack_28 = *(float *)(iVar2 + 0x24) - local_78;
  fStack_64 = *(float *)(iVar2 + 0x28) - local_74;
  fStack_24 = fStack_64 - (float)param_1[0x5d];
  iVar2 = (**(code **)(*param_1 + 0x68))();
  if ((iVar2 == 0) || (((byte)DAT_006f08a4 & 1) != 0)) {
    iVar2 = param_1[0x128];
    param_1[0x114] = 1;
    if (iVar2 == 0) {
      bMatrixCopy_b();
    }
    else {
      bMatrixCopy_b();
      if (*(int *)(iVar2 + 0xe4) == 0) {
        FUN_00579190();
      }
    }
  }
  else {
    param_1[0x114] = 0;
  }
  fStack_2c = fStack_7c + fStack_2c;
  uStack_20 = 0x3f800000;
  fStack_28 = fStack_28 + local_78;
  fStack_24 = local_74 + fStack_24;
  FUN_00597730(param_1,auStack_5c);
  if (DAT_00736200 == 0) {
    Smokeable__RespawnOrExpire();
  }
  if (((*(char *)((int)param_1 + 0x4c2) != '\0') && ((float)param_1[0x57] == 0.0)) &&
     (fVar1 = (float)param_1[0x5d] - _DAT_006ef290 * param_2, param_1[0x5d] = (int)fVar1,
     fVar1 < 0.0)) {
    param_1[0x5d] = 0;
  }
  return;
}


// ==== 0x597670 FUN_00597670

void FUN_00597670(void)

{
  int *in_EAX;
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fStack_8;
  float local_4;
  
  if ((float)in_EAX[0x38] <= (float)in_EAX[0x3a]) {
    local_4 = (float)in_EAX[0x38];
  }
  else {
    local_4 = (float)in_EAX[0x3a];
  }
  pfVar1 = (float *)(**(code **)(*in_EAX + 0xc))();
  fStack_8 = SQRT(pfVar1[2] * pfVar1[2] + pfVar1[1] * pfVar1[1] + *pfVar1 * *pfVar1) * 0.05;
  if (6.0 <= fStack_8) {
    fStack_8 = 6.0;
  }
  uVar2 = (**(code **)(*in_EAX + 0xc))();
  uVar3 = (**(code **)(*in_EAX + 8))();
  GroundQuery__RefillCache(uVar3,fStack_8 + local_4,uVar2);
  if (DAT_00736200 == 0) {
    DynamicCollisionBody__UpdatePosition();
  }
  return;
}


// ==== 0x597730 FUN_00597730

void FUN_00597730(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (*(char *)((int)param_1 + 0x4c2) != '\0') {
    puVar5 = (undefined4 *)(**(code **)(*param_1 + 0xc))();
    for (piVar2 = (int *)param_1[0x12e]; piVar2 != param_1 + 0x12e; piVar2 = (int *)*piVar2) {
      iVar3 = piVar2[2];
      bMatrixCopy_b();
      uVar1 = puVar5[2];
      uVar4 = *puVar5;
      *(undefined4 *)(iVar3 + 0x74) = puVar5[1];
      *(undefined4 *)(iVar3 + 0x70) = uVar4;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
      *(undefined4 *)(iVar3 + 0x78) = uVar1;
    }
    if ((char)param_1[0x130] == '\x01') {
      for (piVar2 = (int *)param_1[300]; piVar2 != param_1 + 300; piVar2 = (int *)*piVar2) {
        iVar3 = piVar2[2];
        uVar1 = puVar5[2];
        uVar4 = *puVar5;
        *(undefined4 *)(iVar3 + 0x74) = puVar5[1];
        *(undefined4 *)(iVar3 + 0x70) = uVar4;
        *(undefined4 *)(iVar3 + 0x7c) = 0;
        *(undefined4 *)(iVar3 + 0x78) = uVar1;
      }
      *(undefined1 *)(param_1 + 0x130) = 2;
    }
  }
  return;
}


// ==== 0x5977f0 Smokeable::RespawnOrExpire

/* [canon] props high (hopper+ghidra) docs/re/props.md */

undefined4 Smokeable__RespawnOrExpire(void)

{
  void *pvVar1;
  int *unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686bf8;
  local_c = ExceptionList;
  if (((unaff_ESI[0x5c] != 0) &&
      (((unaff_ESI[0x5a] == 0 || (unaff_ESI[0x5a] == 0x7fffffff)) &&
       (*(char *)((int)unaff_ESI + 0x1a) == '\0')))) &&
     (2.0 < (float)(DAT_0073ad34 - unaff_ESI[0x59]) * 0.00025)) {
    ExceptionList = &local_c;
    pvVar1 = (void *)FUN_00567160();
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      VirginSmokeable__VirginSmokeable(pvVar1,unaff_ESI[0x5c]);
    }
    local_4 = 0xffffffff;
    (**(code **)*unaff_ESI)(1);
    ExceptionList = pvVar1;
    return 1;
  }
  if ((unaff_ESI[0x5a] != 0) && (unaff_ESI[0x5a] != 0x7fffffff)) {
    if (*(float *)(unaff_ESI[0x56] + 0xc0) != 0.0) {
      pvVar1 = (void *)(DAT_0073ad34 - unaff_ESI[0x5a]);
      if (*(float *)(unaff_ESI[0x56] + 0xc0) <= (float)(int)pvVar1 * 0.00025) {
        ExceptionList = &local_c;
        (**(code **)(*unaff_ESI + 0x7c))();
        (**(code **)*unaff_ESI)(1);
        ExceptionList = pvVar1;
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x597920 FUN_00597920

void FUN_00597920(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x4b0);
  if (piVar1 == (int *)(param_1 + 0x4b0)) {
    *(undefined1 *)(param_1 + 0x4c0) = 1;
    return;
  }
  do {
    ParticleEmitter_Queue();
    piVar1 = (int *)*piVar1;
  } while (piVar1 != (int *)(param_1 + 0x4b0));
  *(undefined1 *)(param_1 + 0x4c0) = 1;
  return;
}


// ==== 0x597980 Smokeable::OnHit

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

float10 __thiscall Smokeable__OnHit(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_38 = 1.0;
  if (*(char *)((int)param_1 + 0x4c2) == '\0') {
    if ((float)param_1[0x57] == 0.0) {
      Smokeable__Release(param_1);
    }
    else {
      iVar2 = param_1[0x56];
      fVar3 = *(float *)(iVar2 + 0xb0) + *param_3;
      fVar5 = *(float *)(iVar2 + 0xb4) + param_3[1];
      fVar4 = *(float *)(iVar2 + 0xb8) + param_3[2];
      fVar1 = fVar5 * param_2[2] - fVar4 * param_2[1];
      fVar4 = fVar4 * *param_2 - fVar3 * param_2[2];
      fVar3 = fVar3 * param_2[1] - fVar5 * *param_2;
      local_38 = SQRT(fVar1 * fVar1 + fVar4 * fVar4 + fVar3 * fVar3);
      fVar3 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
      if (local_38 < fVar3) {
        local_38 = fVar3;
      }
      if (local_38 < (float)param_1[0x57]) {
        return (float10)_K_ONE;
      }
      local_38 = (float)param_1[0x57] / local_38;
      local_18 = -local_38;
      local_20 = local_18 * *param_2;
      local_1c = local_18 * param_2[1];
      local_18 = local_18 * param_2[2];
      local_30 = -*(float *)(iVar2 + 0xb0);
      local_2c = -*(float *)(iVar2 + 0xb4);
      local_28 = -*(float *)(iVar2 + 0xb8);
      Smokeable__Release(param_1);
      param_1[0x57] = 0;
      (**(code **)(*param_1 + 0x4c))(&local_20,&local_30);
      FUN_00597920(param_1);
    }
  }
  if ((float)param_1[0x58] != 0.0) {
    fVar3 = (ABS(*param_2) + ABS(param_2[1]) + ABS(param_2[2])) * local_38;
    if ((float)param_1[0x58] <= fVar3) {
      fVar1 = (float)param_1[0x58];
      param_1[0x58] = -0x40800000;
      return (float10)-((local_38 / fVar3) * fVar1);
    }
    param_1[0x58] = (int)((float)param_1[0x58] - fVar3 * _K_HALF);
  }
  return (float10)local_38;
}


// ==== 0x597b80 FUN_00597b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597b80(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = DAT_0073ad34;
  if ((0.1 < (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x16c)) * 0.00025) &&
     (*(char *)(in_EAX + 0x1c) != '\0')) {
    iVar2 = CollisionBody__GetCollision(0);
    if ((0.025 < (float)(iVar1 - *(int *)(iVar2 + 8)) * 0.00025) &&
       ((iVar1 = *(int *)(in_EAX + 0x6c),
        SQRT(*(float *)(iVar1 + 0xa8) * *(float *)(iVar1 + 0xa8) +
             *(float *)(iVar1 + 0xa4) * *(float *)(iVar1 + 0xa4) +
             *(float *)(iVar1 + 0xa0) * *(float *)(iVar1 + 0xa0)) < 0.1 &&
        (SQRT(*(float *)(iVar1 + 200) * *(float *)(iVar1 + 200) +
              *(float *)(iVar1 + 0xc4) * *(float *)(iVar1 + 0xc4) +
              *(float *)(iVar1 + 0xc0) * *(float *)(iVar1 + 0xc0)) < 0.1)))) {
      *(undefined1 *)(in_EAX + 0x4c2) = 0;
      *(undefined1 *)(in_EAX + 0x1d) = 0;
      _DAT_0073446c = _DAT_0073446c + -1;
      FUN_00440740();
      return;
    }
  }
  return;
}


// ==== 0x597c90 Smokeable::Release

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props med (ghidra) docs/re/props.md */

void Smokeable__Release(int param_1)

{
  int *piVar1;
  
  *(undefined1 *)(param_1 + 0x4c2) = 1;
  *(undefined1 *)(param_1 + 0x1d) = 1;
  _DAT_0073446c = _DAT_0073446c + 1;
  if (*(char *)(param_1 + 0x4c1) == '\0') {
    piVar1 = *(int **)(param_1 + 0x4b8);
    if (piVar1 != (int *)(param_1 + 0x4b8)) {
      do {
        ParticleEmitter_Queue();
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)(param_1 + 0x4b8));
    }
    *(undefined1 *)(param_1 + 0x4c1) = 1;
  }
  if ((*(int *)(param_1 + 0x168) == 0) || (*(int *)(param_1 + 0x168) == 0x7fffffff)) {
    *(undefined4 *)(param_1 + 0x168) = DAT_0073ad34;
  }
  return;
}


// ==== 0x597d10 Smokeable::BuildChildren

/* [canon] props med (hopper+ghidra) docs/re/props.md */

int Smokeable__BuildChildren(undefined4 *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(unaff_EDI[0x56] + 0x8c);
  iVar8 = 0;
  local_8 = 0x4948435f;
  local_4 = &DAT_0078444c;
  if (0 < iVar3) {
    iVar4 = 0x90 - (int)param_1;
    do {
      iVar5 = *(int *)(unaff_EDI[0x112] + 8);
      local_4._0_3_ = CONCAT12((char)iVar8 + '1',(undefined2)local_4);
      puVar7 = &local_8;
      bVar2 = (byte)local_8;
      while (bVar2 != 0) {
        iVar5 = iVar5 * 0x21 + (uint)bVar2;
        pbVar1 = (byte *)((int)puVar7 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        bVar2 = *pbVar1;
      }
      uVar6 = (*DAT_0073168c)(*(undefined2 *)(DAT_00736070 + 8),
                              *(undefined4 *)((int)param_1 + unaff_EDI[0x56] + iVar4),iVar5);
      if (unaff_EDI[0x128] == 0) {
        puVar7 = unaff_EDI + 0x118;
      }
      else {
        puVar7 = (undefined4 *)(unaff_EDI[0x128] + 0x50);
      }
      FUN_00597140(puVar7,0);
      Smokeable__Release(uVar6);
      *param_1 = uVar6;
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 < iVar3);
  }
  (**(code **)*unaff_EDI)(1);
  return iVar3;
}


// ==== 0x597e10 Smokeable::BuildChildPart

/* [canon] props low (hopper+ghidra) docs/re/props.md */

undefined4 Smokeable__BuildChildPart(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_ESI;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(*(int *)(unaff_ESI + 0x158) + 0x8c);
  iVar6 = 0;
  local_8 = 0x4948435f;
  local_4 = &DAT_0078444c;
  if (0 < iVar3) {
    do {
      local_4._0_3_ = CONCAT12((char)iVar6 + '1',(undefined2)local_4);
      puVar5 = &local_8;
      cVar2 = (char)local_8;
      while (cVar2 != '\0') {
        pcVar1 = (char *)((int)puVar5 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        cVar2 = *pcVar1;
      }
      iVar4 = FUN_00591d00();
      if (iVar4 == 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
  }
  return 1;
}


// ==== 0x597ea0 FUN_00597ea0

undefined4 __fastcall FUN_00597ea0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  fVar2 = SQRT(*(float *)(iVar1 + 0xa8) * *(float *)(iVar1 + 0xa8) +
               *(float *)(iVar1 + 0xa4) * *(float *)(iVar1 + 0xa4) +
               *(float *)(iVar1 + 0xa0) * *(float *)(iVar1 + 0xa0));
  fVar3 = SQRT(*(float *)(iVar1 + 200) * *(float *)(iVar1 + 200) +
               *(float *)(iVar1 + 0xc4) * *(float *)(iVar1 + 0xc4) +
               *(float *)(iVar1 + 0xc0) * *(float *)(iVar1 + 0xc0));
  if (((fVar2 <= 2.0) && (fVar3 <= 2.0)) &&
     ((*(char *)(param_1 + 0x1c) != '\0' || (*(int *)(param_1 + 0x4c4) == 2)))) {
    if (((fVar2 <= 0.8) && (fVar3 <= 0.8)) &&
       (0.1 <= (float)(DAT_0073ad34 - *(int *)(param_1 + 0x16c)) * 0.00025)) {
      return 2;
    }
    return 1;
  }
  return 0;
}


// ==== 0x597fa0 FUN_00597fa0

void __fastcall FUN_00597fa0(int param_1)

{
  int iVar1;
  
  PhysicsSystem__ComputeAuxiliaries();
  iVar1 = FUN_00597ea0();
  *(int *)(param_1 + 900) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + -0xd4) + 0x140) = 1;
    *(undefined1 *)(param_1 + -0x123) = 1;
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      iVar1 = *(int *)(param_1 + -0xd4);
      *(undefined4 *)(iVar1 + 0x70) = 0;
      *(undefined4 *)(iVar1 + 0x74) = 0;
      *(undefined4 *)(iVar1 + 0x78) = 0;
      iVar1 = *(int *)(param_1 + -0xd4);
      *(undefined4 *)(iVar1 + 0x80) = 0;
      *(undefined4 *)(iVar1 + 0x84) = 0;
      *(undefined4 *)(iVar1 + 0x88) = 0;
      *(undefined4 *)(*(int *)(param_1 + -0xd4) + 0x140) = 0;
      *(undefined1 *)(param_1 + -0x123) = 0;
      PhysicsSystem__ComputeAuxiliaries();
    }
    return;
  }
  iVar1 = *(int *)(param_1 + -0xd4);
  *(float *)(iVar1 + 0x78) = *(float *)(iVar1 + 0x78) * 0.95;
  *(float *)(iVar1 + 0x70) = *(float *)(iVar1 + 0x70) * 0.95;
  *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x74) * 0.95;
  iVar1 = *(int *)(param_1 + -0xd4);
  *(float *)(iVar1 + 0x88) = *(float *)(iVar1 + 0x88) * 0.95;
  *(float *)(iVar1 + 0x80) = *(float *)(iVar1 + 0x80) * 0.95;
  *(float *)(iVar1 + 0x84) = *(float *)(iVar1 + 0x84) * 0.95;
  *(undefined4 *)(*(int *)(param_1 + -0xd4) + 0x140) = 1;
  *(undefined1 *)(param_1 + -0x123) = 1;
  PhysicsSystem__ComputeAuxiliaries();
  return;
}


// ==== 0x5980d0 FUN_005980d0

undefined4 FUN_005980d0(void)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(in_EAX + 0x1c);
  iVar6 = 0;
  if (0 < cVar1) {
    do {
      iVar3 = CollisionBody__GetCollision(iVar6);
      iVar2 = *(int *)(*(int *)(iVar3 + 100) + 600);
      iVar5 = 0;
      iVar4 = 0;
      if (*(char *)(iVar2 + 0x15) == '\0') {
        iVar4 = *(int *)(iVar2 + 0x140);
      }
      iVar2 = *(int *)(*(int *)(iVar3 + 100) + 0x25c);
      if (*(char *)(iVar2 + 0x15) == '\0') {
        iVar5 = *(int *)(iVar2 + 0x140);
      }
      if ((iVar4 != 0) || (iVar5 != 0)) {
        return 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < cVar1);
  }
  return 0;
}


// ==== 0x598130 FUN_00598130

void FUN_00598130(void)

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
    FUN_00598160();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x598160 FUN_00598160

void FUN_00598160(void)

{
  List_DeleteAllNodes();
  List_DeleteAllNodes();
  return;
}


// ==== 0x598180 FUN_00598180

void FUN_00598180(void)

{
  FUN_00596c90();
  return;
}


// ==== 0x598190 FUN_00598190

void * FUN_00598190(void *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined **ppuVar5;
  
  eh_vector_constructor_iterator(param_1,8,0xcb,IList_InitEmpty_Thunk,List_DeleteAllNodes);
  ppuVar5 = &PTR_DAT_006ef2d0;
  do {
    iVar4 = 0;
    do {
      switch(iVar4) {
      case 0:
        pbVar3 = ppuVar5[0x10];
        break;
      case 1:
        pbVar3 = ppuVar5[0x13];
        break;
      case 2:
        pbVar3 = ppuVar5[0x16];
        break;
      case 3:
        pbVar3 = ppuVar5[0x19];
        break;
      case 4:
        pbVar3 = ppuVar5[0x1c];
        break;
      case 5:
        pbVar3 = ppuVar5[0x1f];
        break;
      case 6:
        pbVar3 = ppuVar5[0x22];
        break;
      default:
        goto switchD_005981bd_default;
      }
      if ((pbVar3 != (byte *)0x0) && (bVar1 = *pbVar3, bVar1 != 0)) {
        iVar2 = -1;
        do {
          iVar2 = iVar2 * 0x21 + (uint)bVar1;
          bVar1 = pbVar3[1];
          pbVar3 = pbVar3 + 1;
        } while (bVar1 != 0);
        FUN_00402ad0(iVar2);
      }
switchD_005981bd_default:
      iVar4 = iVar4 + 1;
    } while (iVar4 < 7);
    ppuVar5 = ppuVar5 + 0x25;
    if (0x6f0393 < (int)ppuVar5) {
      return param_1;
    }
  } while( true );
}


// ==== 0x598260 FUN_00598260

void __fastcall FUN_00598260(undefined4 param_1,int param_2,int param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int *piVar4;
  int *unaff_EDI;
  
  param_3 = in_EAX * 0x1d + param_3;
  piVar4 = *(int **)(param_2 + param_3 * 8);
  if (piVar4 != (int *)(param_2 + param_3 * 8)) {
    piVar3 = (int *)NullUpdate_ret();
    if (piVar4 != piVar3) {
      do {
        bMatrixCopy_b();
        iVar1 = unaff_EDI[2];
        iVar2 = *unaff_EDI;
        piVar4[0x1d] = unaff_EDI[1];
        piVar4[0x1e] = iVar1;
        piVar4[0x1c] = iVar2;
        piVar4[0x1f] = 0;
        FUN_00402d30(&DAT_0078e9e0,piVar4,-param_4,0);
        piVar4 = (int *)*piVar4;
      } while (piVar4 != piVar3);
    }
  }
  return;
}


// ==== 0x598360 FUN_00598360

void FUN_00598360(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686213;
  local_c = ExceptionList;
  if (DAT_00734460 == 0) {
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x658);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_00734460 = FUN_00598190(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_00734460 = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x5983d0 SpawnRecord_Allowed

/* [canon] traffic high (G+H) docs/re/traffic.md */

undefined1 __thiscall SpawnRecord_Allowed(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 local_c;
  
  if ((*(short *)(param_1 + 4 + param_2 * 2) == -1) ||
     (*(char *)(param_1 + 0xd0 + param_4 + param_3 * 4 + param_2 * 2) == '\0')) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}


// ==== 0x598420 FUN_00598420

undefined4 __fastcall FUN_00598420(undefined4 param_1)

{
  FUN_00589260();
  return param_1;
}


// ==== 0x598440 FUN_00598440

float * __fastcall FUN_00598440(float *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  FUN_0059af20(param_1 + 4,0,1);
  Teleporter_ReloadTimer();
  if (*param_1 < 0.0) {
    *param_1 = 0.0;
  }
  param_1[1] = 0.0;
  *(undefined1 *)(param_1 + 2) = 1;
  local_8 = 0;
  while( true ) {
    iVar1 = SpawnRecord_Count();
    if (iVar1 <= local_8) break;
    uVar2 = SpawnRecord_Get();
    FUN_005ab080(param_1,uVar2);
    local_8 = local_8 + 1;
  }
  return param_1;
}


// ==== 0x5984d0 FUN_005984d0

void __fastcall FUN_005984d0(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = SpawnRecord_Count(param_1);
    if (iVar1 <= local_8) break;
    SpawnRecord_Get();
    local_8 = local_8 + 1;
  }
  return;
}


// ==== 0x598510 Teleporter_RestoreState

/* [canon] traffic med (H) docs/re/traffic.md */

void Teleporter_RestoreState(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 local_8;
  
  FUN_0041f650();
  FUN_0041f660();
  FUN_0041f670();
  local_8 = 0;
  while( true ) {
    iVar1 = SpawnRecord_Count();
    if (iVar1 <= local_8) break;
    SpawnRecord_Get();
    FUN_005ab010();
    local_8 = local_8 + 1;
  }
  FUN_00425140();
  iVar1 = FUN_0041f640();
  if (iVar1 != 0) {
    local_10 = 0;
    while( true ) {
      iVar1 = FUN_0041f680();
      if (iVar1 <= local_10) break;
      FUN_0041f690();
      piVar2 = (int *)FUN_00424dc0();
      uVar3 = (**(code **)(*piVar2 + 0x50))();
      FUN_00432d30(uVar3);
      local_10 = local_10 + 1;
    }
  }
  FUN_00571f20();
  return;
}


// ==== 0x598600 TrafficTeleporter::DoTimestep

/* WARNING: Removing unreachable block (ram,0x005987e4) */
/* WARNING: Removing unreachable block (ram,0x0059884c) */
/* WARNING: Removing unreachable block (ram,0x0059886e) */
/* WARNING: Removing unreachable block (ram,0x00598797) */
/* [canon] traffic high (H+G) docs/re/traffic.md */

void __thiscall TrafficTeleporter__DoTimestep(float *param_1,float param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  int local_28;
  int local_24;
  float local_20 [5];
  int local_c;
  float local_8;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_("TrafficTeleporter::DoTimestep()");
  if (DAT_00734458 != 0) {
    if (*(char *)(param_1 + 2) == '\0') {
      Teleporter_Enable();
    }
    else {
      Teleporter_Disable();
    }
    DAT_00734458 = 0;
    NullUpdate_ret();
  }
  FUN_006497d0();
  FUN_006497d0();
  Intersections_UpdateAll();
  if (((((DAT_0078a300 != 0) && (iVar2 = FUN_0041f680(), iVar2 != 0)) &&
       (iVar2 = FUN_00424ea0(), iVar2 != 0)) &&
      ((iVar2 = FUN_00408200(), iVar2 != 0 && (*(char *)(param_1 + 2) != '\0')))) &&
     (*param_1 = *param_1 - param_2, *param_1 <= 0.0)) {
    Teleporter_ReloadTimer();
    local_8 = param_1[1];
    local_20[3] = 0.0;
    local_24 = 0;
    cVar1 = FUN_00421a50();
    local_c = (-(uint)(cVar1 != '\0') & 0x15) + 1;
    local_20[0] = 999999.0;
    local_20[1] = 999999.0;
    local_20[2] = 0.0;
    for (local_28 = 0; iVar2 = FUN_00408200(), local_28 < iVar2; local_28 = local_28 + 1) {
      GetPlayerObject();
      uVar3 = FUN_00417490();
      fVar4 = (float10)Teleporter_Spacing(uVar3);
      iVar2 = FUN_0041e4c0();
      local_20[iVar2] = (float)fVar4;
    }
    do {
      local_8 = (float)((int)local_8 + 1);
      iVar2 = FUN_0041f680();
      if (iVar2 <= (int)local_8) {
        local_8 = 0.0;
      }
      local_20[3] = (float)FUN_0041f690();
      cVar1 = Teleporter_NeedsMove(local_20[3]);
      if (cVar1 != '\0') {
        cVar1 = Teleporter_MoveCar(local_20[3],local_20);
        if (cVar1 == '\0') {
          iVar2 = FUN_0041f5d0();
          TrafficCar_Park();
          *(undefined1 *)(iVar2 + 0x4d1) = 1;
        }
        local_24 = local_24 + 1;
      }
    } while ((local_24 < local_c) && (local_8 != param_1[1]));
    param_1[1] = local_8;
  }
  return;
}


// ==== 0x5988c0 Teleporter_NeedsMove

/* WARNING: Removing unreachable block (ram,0x00598a29) */
/* WARNING: Removing unreachable block (ram,0x00598a3a) */
/* WARNING: Removing unreachable block (ram,0x00598a31) */
/* WARNING: Removing unreachable block (ram,0x005989d3) */
/* WARNING: Removing unreachable block (ram,0x005989ec) */
/* WARNING: Removing unreachable block (ram,0x005989e3) */
/* WARNING: Removing unreachable block (ram,0x005989f3) */
/* WARNING: Removing unreachable block (ram,0x00598a04) */
/* WARNING: Removing unreachable block (ram,0x005989fb) */
/* WARNING: Removing unreachable block (ram,0x00598a0b) */
/* WARNING: Removing unreachable block (ram,0x00598a1c) */
/* WARNING: Removing unreachable block (ram,0x00598a13) */
/* WARNING: Removing unreachable block (ram,0x005988de) */
/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined1 Teleporter_NeedsMove(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  undefined1 local_20;
  undefined1 local_1c;
  
  iVar4 = FUN_0041f5d0();
  cVar1 = FUN_0044d650();
  if (cVar1 == '\0') {
    cVar1 = *(char *)(iVar4 + 0x4d1);
    cVar2 = Teleporter_IsPassed(param_1);
    cVar3 = Teleporter_NearPlayerRoute(param_1);
    if ((cVar1 == '\0') && ((cVar2 == '\0' || (cVar3 != '\0')))) {
      local_20 = 0;
    }
    else {
      local_20 = 1;
    }
    return local_20;
  }
  if (*(char *)(iVar4 + 0x4d0) != '\0') {
    fVar5 = (float10)FUN_0041f5f0();
    cVar1 = TrafficTeleporter__IsPrimaryTeleportationSpotAllowed((float)fVar5);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  if ((*(char *)(iVar4 + 0x4d1) == '\0') && (cVar1 = Teleporter_CarInRange(param_1), cVar1 != '\0'))
  {
    local_1c = 0;
  }
  else {
    local_1c = 1;
  }
  return local_1c;
}


// ==== 0x598a50 Teleporter_IsPassed

/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined1 Teleporter_IsPassed(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float fVar8;
  undefined1 local_28;
  undefined1 local_24;
  
  piVar1 = (int *)FUN_0041f5d0();
  NearestPlayer(param_1);
  piVar2 = (int *)FUN_0041f5d0();
  fVar5 = (float10)FUN_0041f5f0();
  fVar8 = (float)fVar5;
  fVar5 = (float10)FUN_0041f5f0(fVar8);
  fVar5 = (float10)TrackPath__WrapDistance((float)fVar5,fVar8);
  fVar6 = (float10)FUN_00424e10();
  fVar7 = (float10)FUN_00424e10();
  if (0.0 < (float)fVar5) {
    iVar3 = (**(code **)(*piVar1 + 0x40))();
    iVar4 = (**(code **)(*piVar2 + 0x40))();
    if ((iVar3 != iVar4) || ((float)((float10)(float)fVar6 - fVar7) <= 0.0)) {
      local_24 = 0;
    }
    else {
      local_24 = 1;
    }
    return local_24;
  }
  iVar3 = (**(code **)(*piVar1 + 0x40))();
  iVar4 = (**(code **)(*piVar2 + 0x40))();
  if ((iVar3 != iVar4) || ((float)((float10)(float)fVar6 - fVar7) < 0.0)) {
    local_28 = 1;
  }
  else {
    local_28 = 0;
  }
  return local_28;
}


// ==== 0x598b60 TrafficTeleporter::IsPrimaryTeleportationSpotAllowed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic high (G+file) docs/re/traffic.md */

undefined4 TrafficTeleporter__IsPrimaryTeleportationSpotAllowed(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  int local_8;
  
  local_8 = 0;
  do {
    iVar1 = FUN_00408200();
    if (iVar1 <= local_8) {
      return 1;
    }
    uVar2 = GetPlayerObject();
    uVar3 = FUN_00417490();
    fVar4 = (float10)FUN_00424e00(uVar3,uVar2);
    if (fVar4 < (float10)_TeleportSlowPlayerSpeed) {
      uVar2 = param_1;
      fVar4 = (float10)FUN_0041f5f0(param_1);
      fVar4 = (float10)TrackPath__WrapDistance((float)fVar4,uVar2);
      fVar4 = (float10)FUN_00405600((float)fVar4);
      if (fVar4 < (float10)fRam006b5a54) {
        return 0;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== 0x598bf0 TrafficTeleporter::PlaceCar

/* [canon] traffic high (H+G) docs/re/traffic.md */

int __thiscall TrafficTeleporter__PlaceCar(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int local_8;
  
  local_8 = 0;
  cVar1 = FUN_00421a50(param_1);
  if (cVar1 != '\0') {
    local_8 = PlaceCar_Route(param_2);
  }
  if (local_8 == 0) {
    local_8 = PlaceCar_SpawnRecord(param_2);
  }
  if ((local_8 == 0) && (cVar1 = FUN_00421a50(param_1), cVar1 == '\0')) {
    local_8 = PlaceCar_RandomNode(param_2);
  }
  return local_8;
}


// ==== 0x598c80 PlaceCar_SpawnRecord

/* WARNING: Removing unreachable block (ram,0x00598ec5) */
/* WARNING: Removing unreachable block (ram,0x00598de8) */
/* WARNING: Removing unreachable block (ram,0x00598c9a) */
/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 PlaceCar_SpawnRecord(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 local_38 [8];
  float local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  byte local_19;
  int local_18;
  int local_14;
  float local_10;
  int local_c;
  undefined4 local_8;
  
  iVar2 = SpawnRecord_Count();
  if (iVar2 != 0) {
    local_8 = 0;
    fVar3 = (float10)FUN_00432d00();
    fVar3 = (float10)FUN_00432d20((float)fVar3);
    local_10 = (float)fVar3;
    local_c = DAT_0078a300;
    for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
      fVar3 = (float10)Random_NextFloat(0x3f800000);
      local_19 = fVar3 < (float10)0.5;
      uVar7 = (uint)local_19;
      local_20 = (uint)local_19;
      uVar8 = 1;
      uVar6 = 0;
      fVar5 = local_10;
      iVar2 = DAT_0078a2fc;
      local_24 = uVar7;
      fVar3 = (float10)FUN_00424c30(local_10,0,uVar7,1,DAT_0078a2fc);
      fVar4 = (float)fVar3;
      fVar3 = (float10)FUN_00424c30(fVar4);
      local_18 = SpawnRecord_Find((float)-fVar3,fVar4,fVar5,uVar6,uVar7,uVar8,iVar2);
      if (local_18 != 0) {
        local_28 = SpawnRecord_GetNode(1);
        local_2c = PickLane(local_28,CONCAT31((int3)(-(uint)local_19 >> 8),'\x01' - (local_19 != 0))
                           );
        if (local_2c != -1) {
          uVar8 = FUN_00598f00(local_28);
          iVar2 = TrackRow_Current();
          uVar6 = *(undefined4 *)(iVar2 + 0xd4 + DAT_0078a2fc * 4);
          fVar3 = (float10)FUN_00442590();
          local_30 = (float)fVar3;
          FUN_004ad8d0();
          FUN_00432d60(0,local_30);
          cVar1 = FUN_0059b130(local_38,uVar6,0,1);
          if (cVar1 == '\0') {
            fVar4 = *(float *)(local_18 + 0xb0 + local_c * 8 + DAT_0078a2fc * 4);
            fVar3 = (float10)RoadNode_GetLaneSpeedCap();
            fVar3 = (float10)bMin(fVar4 * 0.44702727,(float)fVar3);
            uVar6 = TrafficCar_Place(param_1,uVar8,local_2c,(float)fVar3,local_18);
            return uVar6;
          }
        }
      }
    }
  }
  return 0;
}


// ==== 0x598f00 FUN_00598f00

void FUN_00598f00(void)

{
  undefined4 uVar1;
  
  FUN_0044d3e0();
  FUN_00432e00();
  FUN_004420e0();
  uVar1 = FUN_004109f0();
  FUN_004216b0(uVar1);
  FUN_00432df0();
  return;
}


// ==== 0x598fb0 PlaceCar_RandomNode

/* WARNING: Removing unreachable block (ram,0x00599070) */
/* WARNING: Removing unreachable block (ram,0x00599089) */
/* WARNING: Removing unreachable block (ram,0x005990b3) */
/* [canon] traffic med (H+G) docs/re/traffic.md */

undefined4 __thiscall PlaceCar_RandomNode(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  undefined4 uVar6;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    for (local_10 = 0; local_10 < 100; local_10 = local_10 + 1) {
      uVar1 = PickTravelSide();
      PickRandomSection(&local_c,uVar1);
      cVar2 = FUN_00456c90();
      if (((cVar2 != '\0') && (iVar3 = FUN_004420a0(), iVar3 != 0)) &&
         (iVar3 = FUN_004420d0(), iVar3 != 0)) {
        iVar3 = FUN_004420e0();
        iVar4 = FUN_00432e00();
        if (iVar3 <= iVar4 + -2) {
          iVar3 = TrackRow_Current();
          cVar2 = Spot_IsClear(&local_c,*(undefined4 *)(iVar3 + 0xd4 + DAT_0078a2fc * 4),0,1);
          if ((cVar2 != '\0') && (iVar3 = PickLaneEitherSide(local_8,uVar1), iVar3 != -1)) {
            uVar6 = 0;
            fVar5 = (float10)RoadNode_GetLaneSpeedCap(0);
            uVar6 = TrafficCar_Place(param_2,local_8,iVar3,(float)fVar5,uVar6);
            return uVar6;
          }
        }
      }
    }
  }
  return 0;
}


// ==== 0x5991a0 PlaceCar_Route

/* WARNING: Removing unreachable block (ram,0x00599205) */
/* WARNING: Removing unreachable block (ram,0x00599216) */
/* WARNING: Removing unreachable block (ram,0x0059920d) */
/* WARNING: Removing unreachable block (ram,0x0059924b) */
/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 PlaceCar_Route(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    if (99 < local_8) {
      return 0;
    }
    iVar3 = TrackRow_Current();
    fVar1 = *(float *)(iVar3 + 0xd4 + DAT_0078a2fc * 4);
    cVar2 = *(char *)(param_1 + 1);
    iVar3 = local_8 + -0x32;
    uVar4 = PickTravelSide();
    iVar3 = FindNodeAtRoute(0,0,DAT_0078a2fc,(float)(iVar3 + cVar2) * fVar1,uVar4);
    if ((iVar3 != 0) && (iVar5 = PickLaneEitherSide(iVar3,uVar4 & 0xff), iVar5 != -1)) {
      local_10 = FUN_0044d3e0();
      local_c = iVar3;
      cVar2 = Spot_IsClear(&local_10,fVar1,0,1);
      if (cVar2 != '\0') {
        uVar7 = 0;
        fVar6 = (float10)RoadNode_GetLaneSpeedCap(0);
        uVar7 = TrafficCar_Place(param_1,iVar3,iVar5,(float)fVar6,uVar7);
        return uVar7;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== 0x5992f0 TrafficCar_Place

/* WARNING: Removing unreachable block (ram,0x005994a4) */
/* WARNING: Removing unreachable block (ram,0x0059957d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 TrafficCar_Place(int param_1,undefined4 param_2,int param_3,float param_4,int param_5)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 extraout_var;
  float10 fVar6;
  undefined4 local_78;
  undefined1 local_60 [24];
  undefined4 local_48;
  int local_44;
  int local_40;
  float local_3c;
  undefined2 local_38;
  undefined4 *local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00686a03;
  local_1c = ExceptionList;
  local_28 = 0;
  ExceptionList = &local_1c;
  cVar1 = IsForwardsTrafficLane();
  local_2c = (uint)(cVar1 == '\0');
  local_30 = FUN_0044d3e0();
  local_34 = (undefined4 *)0x0;
  local_38 = 0;
  fVar6 = (float10)FUN_00442590();
  local_3c = (float)fVar6;
  if (local_2c == 0) {
    local_40 = param_3;
  }
  else {
    local_40 = param_3 + -6;
  }
  local_44 = local_40;
  local_48 = TrafficDriverMode_Map();
  FUN_004ad8d0();
  FUN_004ad8d0();
  if (local_2c == 0) {
    local_34 = (undefined4 *)FUN_00424f40();
    local_38 = Atan2ToAngle16(*local_34,local_34[1]);
  }
  else {
    local_34 = (undefined4 *)FUN_00421a90();
    local_38 = Atan2ToAngle16(*local_34,local_34[1]);
  }
  FUN_00424f30(0,local_3c);
  FUN_0041e4c0();
  uVar3 = TrafficCar_AtIndex();
  uVar2 = TrafficCar_PickPaint(uVar3);
  *(undefined1 *)(param_1 + 0x17) = uVar2;
  iVar4 = bMalloc_regarg(&PTR_DAT_006cae38,0);
  local_14 = 0;
  if (iVar4 == 0) {
    local_78 = 0;
  }
  else {
    fVar6 = (float10)TrackRoutePoint__GetDistanceAroundTrack();
    local_78 = FUN_00425350(iVar4,param_1,local_60,CONCAT22(extraout_var,local_38),(float)fVar6);
  }
  local_14 = 0xffffffff;
  local_28 = local_78;
  Car_SetMode();
  FUN_00425fe0();
  piVar5 = (int *)FUN_0041f5d0();
  (**(code **)(*piVar5 + 0x10))(local_30,param_2,local_44);
  FUN_00583250();
  *(undefined1 *)(piVar5 + 0x136) = (undefined1)local_48;
  FUN_00583270();
  if (param_5 == 0) {
    AIGoal__Create(4);
  }
  else {
    AIGoal__Create(5);
  }
  if (_K_EPS_SPEED < param_4) {
    FUN_004081f0(param_4);
    FUN_005673e0();
  }
  FUN_00424dd0();
  RigidBody__SetVelocity();
  FUN_00432d30(0);
  Car_SetMode();
  ExceptionList = local_1c;
  return local_28;
}


// ==== 0x5995e0 PickLaneEitherSide

/* WARNING: Removing unreachable block (ram,0x00599628) */
/* [canon] traffic med (G) docs/re/traffic.md */

int PickLaneEitherSide(undefined4 param_1,byte param_2)

{
  int local_8;
  
  local_8 = PickLane(param_1,param_2);
  if (local_8 == -1) {
    local_8 = PickLane(param_1,CONCAT31((int3)(-(uint)param_2 >> 8),'\x01' - (param_2 != 0)));
  }
  return local_8;
}


// ==== 0x599660 PickLane

/* [canon] traffic med (G) docs/re/traffic.md */

int PickLane(undefined4 param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  float10 fVar7;
  int local_1c;
  int local_c;
  
  FUN_00424f50();
  PtrArray_GetOrNull();
  iVar2 = (-(uint)(param_2 != '\0') & 0xfffffffa) + 0x11;
  cVar1 = FUN_00421a50();
  if (((cVar1 != '\0') && (iVar3 = FUN_00408200(), 0 < iVar3)) &&
     (fVar7 = (float10)Random_NextFloat(0x3f800000), fVar7 < (float10)0.5)) {
    iVar3 = FUN_00408200();
    FUN_004216b0(iVar3 * 100000);
    GetPlayerObject();
    FUN_00417490();
    piVar4 = (int *)FUN_0041f5d0();
    local_1c = (**(code **)(*piVar4 + 0x1c))(0);
    cVar1 = FUN_00457000();
    if (cVar1 != '\0') {
      cVar1 = IsForwardsTrafficLane();
      if (cVar1 == '\0') {
        local_1c = local_1c + -0x11;
      }
      else {
        local_1c = local_1c + -0xb;
      }
      pcVar5 = (char *)FUN_00454ff0();
      if (*pcVar5 != '\0') {
        return local_1c + iVar2;
      }
    }
  }
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    uVar6 = FUN_004216b0(600000);
    pcVar5 = (char *)FUN_00454ff0();
    if (*pcVar5 != '\0') {
      return uVar6 / 100000 + iVar2;
    }
  }
  local_c = 0;
  while( true ) {
    if (5 < local_c) {
      return -1;
    }
    pcVar5 = (char *)FUN_00454ff0();
    if (*pcVar5 != '\0') break;
    local_c = local_c + 1;
  }
  return local_c + iVar2;
}


// ==== 0x599830 Teleporter_MoveCar

/* WARNING: Removing unreachable block (ram,0x00599840) */
/* WARNING: Removing unreachable block (ram,0x00599857) */
/* WARNING: Removing unreachable block (ram,0x0059985e) */
/* WARNING: Removing unreachable block (ram,0x00599884) */
/* WARNING: Removing unreachable block (ram,0x0059987d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined4 Teleporter_MoveCar(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  float local_1c;
  float local_14;
  
  uVar2 = Teleporter_PickPlayer();
  local_14 = 1.0;
  fVar4 = (float10)FUN_00424e00();
  if (fVar4 < (float10)_TeleportSpawnObjSpeed) {
    local_14 = 0.35;
  }
  fVar4 = (float10)Random_NextFloat(0x3f800000);
  if (((float10)local_14 <= fVar4) ||
     (cVar1 = Teleporter_MoveToSpawnRecord(param_1,uVar2), cVar1 == '\0')) {
    iVar3 = RacerNode__IsPlayerKind();
    if (iVar3 == 0) {
      fVar4 = (float10)Teleporter_Spacing(uVar2);
      local_1c = (float)fVar4;
    }
    else {
      FUN_00424db0();
      iVar3 = FUN_0041e4c0();
      local_1c = *(float *)(param_2 + iVar3 * 4);
    }
    cVar1 = FUN_00421a50();
    if (cVar1 != '\0') {
      uVar2 = Teleporter_MoveRoute(param_1,uVar2,local_1c);
      return uVar2;
    }
    cVar1 = FUN_00421a50();
    if (cVar1 == '\0') {
      uVar2 = Teleporter_MoveFreeRun(param_1,uVar2,local_1c);
      return uVar2;
    }
  }
  return 1;
}


// ==== 0x5999c0 Teleporter_MoveRoute

/* WARNING: Removing unreachable block (ram,0x00599a1f) */
/* WARNING: Removing unreachable block (ram,0x00599a30) */
/* WARNING: Removing unreachable block (ram,0x00599a27) */
/* WARNING: Removing unreachable block (ram,0x00599a75) */
/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 Teleporter_MoveRoute(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  fVar9 = (float10)FUN_0041f5f0();
  fVar10 = (float)fVar9;
  fVar9 = (float10)FUN_0041f5f0(fVar10);
  TrackPath__WrapDistance((float)fVar9,fVar10);
  bVar1 = PickTravelSide();
  piVar3 = (int *)FUN_0041f5d0();
  uVar4 = (**(code **)(*piVar3 + 0x40))();
  uVar8 = (uint)bVar1;
  uVar11 = 0x437a0000;
  local_8 = uVar4;
  fVar9 = (float10)FUN_0041f5f0(uVar4,0x437a0000,uVar8);
  fVar10 = (float)fVar9;
  uVar5 = FUN_0041f5e0(fVar10);
  iVar6 = FindNodeAtRoute(uVar5,fVar10,uVar4,uVar11,uVar8);
  if ((iVar6 != 0) && (iVar7 = PickLaneEitherSide(iVar6,bVar1), iVar7 != -1)) {
    local_10 = FUN_0044d3e0();
    local_c = iVar6;
    cVar2 = Spot_IsClear(&local_10,param_3,param_1,0);
    if (cVar2 != '\0') {
      uVar4 = 0;
      fVar9 = (float10)RoadNode_GetLaneSpeedCap(0);
      TrafficCar_Move(param_1,local_c,0,iVar7,0x41c4b127,(float)fVar9,uVar4);
      return 1;
    }
  }
  return 0;
}


// ==== 0x599b20 FindNodeAtRoute

/* WARNING: Removing unreachable block (ram,0x00599bf5) */
/* [canon] traffic med (G) docs/re/traffic.md */

int FindNodeAtRoute(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined1 param_5)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined4 uVar7;
  int local_10;
  int local_c;
  float local_8;
  
  local_c = 0;
  local_8 = 999999.0;
  for (local_10 = 0; local_10 < 99; local_10 = local_10 + 1) {
    iVar3 = PtrArray_GetOrNull();
    if ((iVar3 != 0) && (iVar4 = Section_HasLane(), iVar4 != 0)) {
      iVar4 = FUN_00442820(iVar3,param_2,param_4,param_3,0);
      if ((iVar4 != 0) && (iVar5 = FUN_004420b0(), iVar5 != 0)) {
        cVar2 = FUN_00599c40(iVar4,iVar3,param_5);
        if (cVar2 != '\0') {
          uVar7 = param_2;
          fVar6 = (float10)TrackRoutePoint__GetDistanceAroundTrack(param_2);
          fVar6 = (float10)TrackPath__WrapDistance((float)fVar6,uVar7);
          fVar1 = (float)fVar6;
          if ((0.0 < fVar1) && (fVar1 < local_8)) {
            local_c = iVar4;
            local_8 = fVar1;
          }
        }
      }
    }
  }
  return local_c;
}


// ==== 0x599c40 FUN_00599c40

uint __thiscall FUN_00599c40(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_004420e0(param_1);
  if (param_4 == '\0') {
    uVar3 = (uint)(9 < iVar1);
  }
  else {
    iVar2 = FUN_00432e00();
    uVar3 = CONCAT31((int3)((uint)(iVar2 + -10) >> 8),iVar1 < iVar2 + -10);
  }
  return uVar3;
}


// ==== 0x599c80 Teleporter_MoveToSpawnRecord

/* WARNING: Removing unreachable block (ram,0x00599e2b) */
/* WARNING: Removing unreachable block (ram,0x00599d8c) */
/* WARNING: Removing unreachable block (ram,0x00599f6b) */
/* WARNING: Removing unreachable block (ram,0x00599fa2) */
/* WARNING: Removing unreachable block (ram,0x00599f99) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined4 Teleporter_MoveToSpawnRecord(undefined4 param_1)

{
  bool bVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float fVar12;
  undefined4 local_70;
  uint local_6c;
  float local_24;
  bool local_15;
  float local_14;
  
  iVar4 = SpawnRecord_Count();
  if (0 < iVar4) {
    FUN_0041f5d0();
    FUN_0044d660();
    FUN_00583270();
    fVar10 = (float10)Random_NextFloat(0x3f800000);
    iVar4 = DAT_0078a300;
    bVar1 = fVar10 < (float10)0.5;
    local_6c = (uint)bVar1;
    fVar10 = (float10)FUN_0041f5f0();
    fVar12 = (float)fVar10;
    fVar10 = (float10)FUN_00424e00();
    piVar5 = (int *)FUN_0041f5d0();
    iVar6 = (**(code **)(*piVar5 + 0x40))();
    cVar3 = TrafficTeleporter__IsPrimaryTeleportationSpotAllowed(fVar12);
    local_24 = fVar12;
    local_14 = fVar12;
    if (cVar3 == '\0') {
      local_24 = fVar12 + _SpawnRecordWindow;
      local_14 = fVar12 - _SpawnRecordWindow;
    }
    local_15 = cVar3 != '\0';
    iVar7 = SpawnRecord_Find(local_14,local_24,fVar12,(float)fVar10,(uint)bVar1,local_15,iVar6);
    if (iVar7 != 0) {
      uVar8 = SpawnRecord_GetNode(local_15);
      fVar10 = (float10)TrackRoutePoint__GetDistanceAroundTrack(fVar12);
      TrackPath__WrapDistance((float)fVar10,fVar12);
      iVar9 = PickLane(uVar8,CONCAT31((int3)(-local_6c >> 8),'\x01' - bVar1));
      if (iVar9 != -1) {
        fVar12 = *(float *)(iVar7 + 0x70 + iVar4 * 8 + iVar6 * 4);
        fVar10 = (float10)Random_NextFloat(*(float *)(iVar7 + 0x90 + iVar4 * 8 + iVar6 * 4) -
                                           *(float *)(iVar7 + 0x70 + iVar4 * 8 + iVar6 * 4));
        if (local_15) {
          local_70 = *(undefined4 *)(iVar7 + 8 + (uint)bVar1 * 4);
        }
        else {
          local_70 = 0;
        }
        fVar2 = *(float *)(iVar7 + 0xb0 + DAT_0078a300 * 8 + iVar6 * 4) * 0.44702727;
        fVar11 = (float10)RoadNode_GetLaneSpeedCap();
        fVar11 = (float10)bMin(fVar2,(float)fVar11);
        cVar3 = FUN_0059afa0(uVar8,iVar9,local_70,(float)(fVar10 + (float10)fVar12),param_1,0);
        if (cVar3 == '\0') {
          TrafficCar_Move(param_1,uVar8,local_70,iVar9,fVar2,(float)fVar11,iVar7);
          return 1;
        }
      }
    }
    FUN_00583270();
  }
  return 0;
}


// ==== 0x599fc0 SpawnRecord_Find

/* WARNING: Removing unreachable block (ram,0x0059a17e) */
/* WARNING: Removing unreachable block (ram,0x0059a231) */
/* WARNING: Removing unreachable block (ram,0x00599ff3) */
/* WARNING: Removing unreachable block (ram,0x0059a205) */
/* WARNING: Removing unreachable block (ram,0x0059a298) */
/* [canon] traffic high (H+G) docs/re/traffic.md */

int SpawnRecord_Find(float param_1,float param_2,undefined4 param_3,float param_4,int param_5,
                    char param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float fVar5;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_6c;
  int local_68;
  int local_5c;
  int aiStack_54 [20];
  
  iVar3 = DAT_0078a300;
  local_5c = 0;
  for (local_6c = 0; iVar2 = SpawnRecord_Count(), local_6c < iVar2; local_6c = local_6c + 1) {
    iVar2 = SpawnRecord_Get();
    if (*(char *)(iVar2 + 0x100) < '\x06') {
      if ((*(short *)(iVar2 + 4 + param_5 * 2) == -1) ||
         (*(char *)(iVar2 + 0xd0 + param_7 + iVar3 * 4 + param_5 * 2) == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_78 = 0.0;
        local_80 = 0.0;
        if (param_6 != '\0') {
          fVar4 = (float10)bMax_float(param_4 * *(float *)(iVar2 + 0x10 + iVar3 * 8 + param_7 * 4),
                                      0x41a00000);
          local_78 = (float)fVar4;
          fVar4 = (float10)bMax_float(param_4 * *(float *)(iVar2 + 0xe0 + iVar3 * 8 + param_7 * 4),
                                      0x42f00000);
          local_80 = (float)fVar4;
        }
        fVar5 = param_1;
        fVar4 = (float10)FUN_005ab160(param_1);
        fVar4 = (float10)TrackPath__WrapDistance((float)fVar4,fVar5);
        local_84 = (float)fVar4;
        if (param_7 == DAT_0078a2fc) {
          local_74 = param_1 + local_78;
          local_7c = param_2 + local_80;
        }
        else {
          local_84 = -local_84;
          local_74 = param_1 - local_80;
          local_7c = param_2 - local_78;
        }
        if ((0.0 < local_84) && (local_84 < local_7c - local_74)) {
          aiStack_54[local_5c] = iVar2;
          local_5c = local_5c + 1;
        }
      }
    }
  }
  local_68 = 0;
  if (0 < local_5c) {
    iVar3 = FUN_004216b0(local_5c);
    local_68 = aiStack_54[iVar3];
  }
  return local_68;
}


// ==== 0x59a2c0 Teleporter_MoveFreeRun

/* WARNING: Removing unreachable block (ram,0x0059a6da) */
/* WARNING: Removing unreachable block (ram,0x0059a77e) */
/* WARNING: Removing unreachable block (ram,0x0059a78f) */
/* WARNING: Removing unreachable block (ram,0x0059a786) */
/* WARNING: Removing unreachable block (ram,0x0059a796) */
/* WARNING: Removing unreachable block (ram,0x0059a7a8) */
/* WARNING: Removing unreachable block (ram,0x0059a79f) */
/* WARNING: Removing unreachable block (ram,0x0059a578) */
/* WARNING: Removing unreachable block (ram,0x0059a4c9) */
/* WARNING: Removing unreachable block (ram,0x0059a4da) */
/* WARNING: Removing unreachable block (ram,0x0059a4d1) */
/* WARNING: Removing unreachable block (ram,0x0059a4e1) */
/* WARNING: Removing unreachable block (ram,0x0059a4f3) */
/* WARNING: Removing unreachable block (ram,0x0059a4ea) */
/* WARNING: Removing unreachable block (ram,0x0059a396) */
/* WARNING: Removing unreachable block (ram,0x0059a345) */
/* WARNING: Removing unreachable block (ram,0x0059a372) */
/* WARNING: Removing unreachable block (ram,0x0059a383) */
/* WARNING: Removing unreachable block (ram,0x0059a37a) */
/* WARNING: Removing unreachable block (ram,0x0059a3d4) */
/* WARNING: Removing unreachable block (ram,0x0059a53b) */
/* WARNING: Removing unreachable block (ram,0x0059a6f5) */
/* WARNING: Removing unreachable block (ram,0x0059a554) */
/* WARNING: Removing unreachable block (ram,0x0059a678) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic high (G+C+H) docs/re/traffic.md */

undefined2 Teleporter_MoveFreeRun(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  char local_6d;
  float local_3c;
  char local_22;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  uVar1 = PickTravelSide();
  fVar6 = (float10)FUN_0041f5f0();
  fVar9 = (float)fVar6;
  fVar6 = (float10)FUN_0041f5f0(fVar9);
  fVar6 = (float10)TrackPath__WrapDistance((float)fVar6,fVar9);
  fVar9 = (float)fVar6;
  iVar3 = FUN_0041f5d0();
  local_c = FUN_00428150(0);
  local_8 = FUN_00428160(0);
  cVar2 = FUN_00456c90();
  if (cVar2 != '\0') {
    local_22 = DAT_0078a2fc == 0;
    iVar4 = FUN_00424db0();
    if (iVar4 == 0) {
      local_6d = '\0';
    }
    else {
      FUN_00424db0();
      local_6d = FUN_00424f20();
    }
    fVar6 = (float10)FUN_00424e10();
    if ((float10)_TeleportSpeedFlip <= fVar6) {
      if (local_6d != '\0') {
        local_22 = '\x01' - local_22;
      }
    }
    else {
      fVar6 = (float10)Random_NextFloat(0x3f800000);
      if (fVar6 < (float10)_K_HALF) {
        local_22 = !(bool)local_22;
      }
    }
    local_14 = 0;
    local_10 = RoadGraph_Walk(&local_c,1,0x437a0000,local_22,0);
    while ((local_10 == 1 && (local_14 != local_8))) {
      fVar6 = (float10)FUN_0041f5f0();
      fVar7 = (float)fVar6;
      fVar6 = (float10)TrackRoutePoint__GetDistanceAroundTrack(fVar7);
      fVar6 = (float10)TrackPath__WrapDistance((float)fVar6,fVar7);
      fVar7 = (float)fVar6;
      if (_TeleportRouteLimit < fVar7) {
        return 0;
      }
      iVar4 = PickLaneEitherSide(local_8,uVar1);
      if (((iVar4 != -1) && (iVar5 = FUN_004420b0(), iVar5 != 0)) &&
         (cVar2 = Spot_IsClear(&local_c,param_3,param_1,0), cVar2 != '\0')) {
        if (*(char *)(iVar3 + 0x4d1) == '\0') {
          if (local_22 == '\0') {
            if ((fVar9 < 0.0) && (fVar7 < fVar9)) {
              return 0;
            }
          }
          else if ((0.0 < fVar9) && (fVar9 < fVar7)) {
            return 0;
          }
        }
        FUN_004420b0();
        uVar8 = 0;
        fVar6 = (float10)RoadNode_GetLaneSpeedCap(0);
        TrafficCar_Move(param_1,local_8,0,iVar4,0x41c4b127,(float)fVar6,uVar8);
        return 1;
      }
      fVar6 = (float10)FUN_00449fe0();
      fVar6 = (float10)bMax_float(param_3,(float)fVar6);
      iVar4 = local_8;
      local_3c = (float)fVar6;
      while (((iVar4 == local_8 || (local_10 == 0)) && (local_14 != local_8))) {
        local_14 = local_8;
        local_10 = RoadGraph_Walk(&local_c,1,local_3c,local_22,0);
        local_3c = local_3c + local_3c;
      }
    }
  }
  return 0;
}


// ==== 0x59a7c0 TrafficCar_Move

/* WARNING: Removing unreachable block (ram,0x0059a913) */
/* WARNING: Removing unreachable block (ram,0x0059a939) */
/* [canon] traffic med (G) docs/re/traffic.md */

void TrafficCar_Move(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                    undefined4 param_5,undefined4 param_6,int param_7)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_30;
  undefined4 local_2c;
  
  cVar1 = IsForwardsTrafficLane();
  uVar3 = FUN_0044d3e0();
  uVar2 = TrafficDriverMode_Map();
  iVar4 = FUN_0041f5d0();
  fVar5 = (float10)FUN_00442590();
  if (cVar1 == '\0') {
    local_2c = 0xbf800000;
    local_30 = param_4 + -6;
  }
  else {
    local_2c = 0x3f800000;
    local_30 = param_4;
  }
  uVar7 = 0;
  uVar6 = 0;
  FUN_0045ac50(0,0);
  FUN_0045ace0(uVar6,uVar7);
  FUN_0044d640(local_30);
  FUN_0059ba00(local_30);
  FUN_00583250();
  *(undefined1 *)(iVar4 + 0x4d8) = uVar2;
  *(undefined4 *)(iVar4 + 0x4dc) = param_5;
  FUN_00583270();
  FUN_00583d70();
  if (param_7 == 0) {
    AIGoal__Create(4);
  }
  else {
    AIGoal__Create(5);
  }
  FUN_00427f70(param_1,uVar3,param_2,param_6,0,local_2c,0,param_3,(float)fVar5);
  Car__SetArtificialColour();
  Car_SetMode();
  FUN_0059b5d0(param_1);
  return;
}


// ==== 0x59a960 FUN_0059a960

/* WARNING: Removing unreachable block (ram,0x0059a995) */

void FUN_0059a960(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  float10 fVar7;
  undefined4 local_34;
  
  piVar2 = (int *)FUN_0041f5d0();
  FUN_0044d640();
  cVar1 = FUN_0059ba10();
  if (cVar1 == '\0') {
    FUN_004ee660();
    iVar3 = (**(code **)(*piVar2 + 0x40))();
    uVar4 = FUN_00421960();
    uVar5 = FUN_00417490();
    fVar6 = (float10)(**(code **)(*piVar2 + 0x5c))();
    fVar7 = (float10)FUN_00442590();
    if (iVar3 == 0) {
      local_34 = 0x3f800000;
    }
    else {
      local_34 = 0xbf800000;
    }
    FUN_00427f70(param_1,uVar4,uVar5,(float)fVar6,0,local_34,0,(float)fVar7,0);
    Car_SetMode();
    Car__SetModeViaDriver();
  }
  return;
}


// ==== 0x59aa60 Spot_IsClear

/* WARNING: Removing unreachable block (ram,0x0059ab7b) */
/* WARNING: Removing unreachable block (ram,0x0059ab9a) */
/* WARNING: Removing unreachable block (ram,0x0059abcb) */
/* [canon] traffic high (H+G+file) docs/re/traffic.md */

undefined1 Spot_IsClear(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  float fVar6;
  undefined1 local_18;
  char local_7;
  char local_6;
  
  local_7 = '\0';
  local_6 = '\0';
  bVar2 = false;
  iVar3 = TrackRow_FindById();
  if ((*(char *)(iVar3 + 200 + DAT_0078a2fc) == '\0') &&
     ((DAT_0073619c == 0 || (fVar5 = (float10)FUN_00432c90(), fVar5 < (float10)0.0)))) {
    iVar3 = TrackRow_Current();
    fVar1 = *(float *)(iVar3 + 0xcc + DAT_0078a2fc * 4);
    fVar5 = (float10)FUN_00432d00();
    fVar5 = (float10)FUN_00432d20((float)fVar5);
    fVar6 = (float)fVar5;
    fVar5 = (float10)TrackRoutePoint__GetDistanceAroundTrack(fVar6);
    fVar5 = (float10)TrackPath__WrapDistance((float)fVar5,fVar6);
    fVar5 = (float10)FUN_00405600((float)fVar5);
    if (fVar5 < (float10)fVar1) {
      bVar2 = true;
    }
  }
  if (!bVar2) {
    fVar5 = (float10)TrackRoutePoint__GetDistanceAroundTrack();
    local_7 = Spot_NearPlayerRoute((float)fVar5);
    if (local_7 == '\0') {
      uVar4 = (uint)param_4;
      fVar5 = (float10)TrackRoutePoint__GetDistanceAroundTrack(param_2,param_3,uVar4);
      local_6 = Spot_NearOtherCar((float)fVar5,param_2,param_3,uVar4);
    }
  }
  if (((local_7 != '\0') || (local_6 != '\0')) || (bVar2)) {
    local_18 = 0;
  }
  else {
    local_18 = 1;
  }
  return local_18;
}


// ==== 0x59ac20 Teleporter_NearPlayerRoute

/* WARNING: Removing unreachable block (ram,0x0059ac5e) */
/* [canon] traffic med (H+G) docs/re/traffic.md */

undefined1 __fastcall Teleporter_NearPlayerRoute(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_5;
  
  local_5 = 0;
  iVar1 = FUN_00421960(param_1);
  if (iVar1 == 4) {
    fVar2 = (float10)FUN_0041f5f0();
    local_5 = Spot_NearPlayerRoute((float)fVar2);
  }
  return local_5;
}


// ==== 0x59ac80 Teleporter_CarInRange

/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 Teleporter_CarInRange(void)

{
  undefined2 extraout_var;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_0041f5f0();
  fVar2 = (float10)FUN_00421550((float)fVar1);
  fVar1 = (float10)250.0;
  return CONCAT31((int3)(CONCAT22(extraout_var,
                                  (ushort)(fVar2 < fVar1) << 8 |
                                  (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar2 == fVar1) << 0xe) >> 8),fVar2 < fVar1);
}


// ==== 0x59acd0 FUN_0059acd0

uint FUN_0059acd0(void)

{
  float10 fVar1;
  uint uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  float10 fVar4;
  
  uVar2 = FUN_00421960();
  if (uVar2 == 4) {
    if (((DAT_00734454 == 0) || (DAT_006fbf14 != 0)) ||
       (iVar3 = RaceManager__FindRacerByIdIn(), iVar3 == 0)) {
      fVar4 = (float10)FUN_004212f0();
      fVar1 = (float10)250.0;
      uVar2 = CONCAT31((int3)(CONCAT22(extraout_var_00,
                                       (ushort)(fVar4 < fVar1) << 8 |
                                       (ushort)(NAN(fVar4) || NAN(fVar1)) << 10 |
                                       (ushort)(fVar4 == fVar1) << 0xe) >> 8),fVar4 < fVar1);
    }
    else {
      FUN_0041f5e0();
      fVar4 = (float10)FUN_0041f550();
      fVar1 = (float10)150.0;
      uVar2 = CONCAT31((int3)(CONCAT22(extraout_var,
                                       (ushort)(fVar4 < fVar1) << 8 |
                                       (ushort)(NAN(fVar4) || NAN(fVar1)) << 10 |
                                       (ushort)(fVar4 == fVar1) << 0xe) >> 8),fVar4 < fVar1);
    }
  }
  else {
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}


// ==== 0x59ad90 Spot_NearPlayerRoute

/* [canon] traffic high (H+G) docs/re/traffic.md */

uint Spot_NearPlayerRoute(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  float10 fVar3;
  float10 fVar4;
  
  uVar1 = FUN_00421960();
  if (uVar1 == 4) {
    if (((DAT_00734454 != 0) && (DAT_006fbf14 == 0)) &&
       (iVar2 = RaceManager__FindRacerByIdIn(), iVar2 != 0)) {
      fVar3 = (float10)FUN_0041f5f0();
      fVar3 = (float10)TrackPath__WrapDistance(param_1,(float)fVar3);
      fVar4 = (float10)FUN_00405600((float)fVar3);
      fVar3 = (float10)250.0;
      if (fVar4 < fVar3) {
        return CONCAT31((int3)(CONCAT22(extraout_var,
                                        (ushort)(fVar4 < fVar3) << 8 |
                                        (ushort)(NAN(fVar4) || NAN(fVar3)) << 10 |
                                        (ushort)(fVar4 == fVar3) << 0xe) >> 8),1);
      }
    }
    fVar3 = (float10)FUN_00421550(param_1);
    fVar4 = (float10)FUN_00405600((float)fVar3);
    fVar3 = (float10)250.0;
    uVar1 = CONCAT31((int3)(CONCAT22(extraout_var_00,
                                     (ushort)(fVar4 < fVar3) << 8 |
                                     (ushort)(NAN(fVar4) || NAN(fVar3)) << 10 |
                                     (ushort)(fVar4 == fVar3) << 0xe) >> 8),fVar4 < fVar3);
  }
  else {
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}


// ==== 0x59ae60 Teleporter_ReloadTimer

/* [canon] traffic high (H+G) docs/re/traffic.md */

void __fastcall Teleporter_ReloadTimer(undefined4 *param_1)

{
  char cVar1;
  undefined4 local_c;
  
  cVar1 = FUN_00421a50();
  if (cVar1 == '\0') {
    local_c = 0x3f800000;
  }
  else {
    local_c = 0x3e99999a;
  }
  *param_1 = local_c;
  return;
}


// ==== 0x59aea0 PickTravelSide

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (G) docs/re/traffic.md */

bool PickTravelSide(void)

{
  float10 fVar1;
  undefined4 local_8;
  
  fVar1 = (float10)Random_NextFloat(0x3f800000);
  if ((float10)_TrafficSameSideProb <= fVar1) {
    if (DAT_0078a2fc == 0) {
      local_8 = 1;
    }
    else {
      local_8 = 0;
    }
  }
  else {
    local_8 = DAT_0078a2fc;
  }
  return local_8 == 0;
}


// ==== 0x59af20 FUN_0059af20

void __thiscall FUN_0059af20(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_8;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    iVar1 = PtrArray_GetOrNull();
    if (iVar1 != 0) {
      iVar1 = Section_HasLane();
      if (iVar1 != 0) {
        iVar1 = FUN_00432e00();
        *(int *)(param_1 + 0xc) = iVar1 + *(int *)(param_1 + 0xc);
      }
    }
    *(undefined4 *)(param_2 + local_8 * 4) = *(undefined4 *)(param_1 + 0xc);
  }
  return;
}


// ==== 0x59afa0 FUN_0059afa0

/* WARNING: Removing unreachable block (ram,0x0059afee) */
/* WARNING: Removing unreachable block (ram,0x0059b0d0) */

uint FUN_0059afa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,int param_5
                 ,char param_6)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  int local_18;
  
  cVar1 = FUN_00457020();
  fVar7 = (float10)FUN_00442590();
  FUN_004ad8d0();
  FUN_00432d60(param_3,(float)fVar7);
  local_18 = 0;
  do {
    uVar3 = FUN_0041f680();
    if ((int)uVar3 <= local_18) {
      return uVar3 & 0xffffff00;
    }
    iVar4 = FUN_0041f690();
    if (((iVar4 != param_5) && (cVar2 = FUN_004280f0(), cVar2 == '\0')) &&
       ((param_6 != '\0' || (iVar4 = FUN_00424e70(), iVar4 != 0)))) {
      piVar5 = (int *)FUN_0041f5d0();
      FUN_0044d640();
      iVar4 = FUN_00449ff0();
      iVar6 = FUN_00424f50();
      if ((iVar4 == iVar6) && (uVar3 = (**(code **)(*piVar5 + 0x40))(), uVar3 == (cVar1 == '\0'))) {
        FUN_0041f5e0();
        fVar7 = (float10)FUN_0041f550();
        if (fVar7 < (float10)param_4) {
          return 1;
        }
      }
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== 0x59b130 FUN_0059b130

/* WARNING: Removing unreachable block (ram,0x0059b1ad) */

uint __thiscall
FUN_0059b130(undefined4 param_1,undefined4 param_2,float param_3,uint param_4,char param_5)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  uint local_8;
  
  local_8 = FUN_00421960(param_1);
  do {
    uVar2 = NullUpdate_ret();
    if (local_8 == uVar2) {
      return uVar2 & 0xffffff00;
    }
    if (((local_8 != param_4) && (cVar1 = FUN_004280f0(), cVar1 == '\0')) &&
       ((param_5 != '\0' || (iVar3 = FUN_00424e70(), iVar3 != 0)))) {
      FUN_0041f5e0();
      fVar4 = (float10)FUN_0041f550();
      if (fVar4 < (float10)param_3) {
        return 1;
      }
    }
    local_8 = FUN_00421960(param_1);
  } while( true );
}


// ==== 0x59b1e0 Spot_NearOtherCar

/* [canon] traffic high (H+G) docs/re/traffic.md */

uint __thiscall
Spot_NearOtherCar(undefined4 param_1,undefined4 param_2,float param_3,uint param_4,char param_5)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined2 extraout_var;
  float10 fVar5;
  float10 fVar6;
  uint local_8;
  
  local_8 = FUN_00421960(param_1);
  do {
    uVar3 = NullUpdate_ret();
    if (local_8 == uVar3) {
      return uVar3 & 0xffffff00;
    }
    if (((local_8 != param_4) && (cVar2 = FUN_004280f0(), cVar2 == '\0')) &&
       ((param_5 != '\0' || (iVar4 = FUN_00424e70(), iVar4 != 0)))) {
      fVar5 = (float10)FUN_0041f5f0();
      fVar5 = (float10)TrackPath__WrapDistance(param_2,(float)fVar5);
      fVar1 = (float)fVar5;
      uVar3 = FUN_00424da0();
      if ((uVar3 & 0xff) == 0) {
        if ((fVar1 < param_3) && (fVar1 < 0.0 == 0 && (fVar1 == 0.0) == 0)) {
          return CONCAT31((int3)(CONCAT22((short)(uVar3 >> 0x10),
                                          (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                                          (ushort)(fVar1 == 0.0) << 0xe) >> 8),1);
        }
      }
      else {
        fVar6 = (float10)FUN_00405600(fVar1);
        fVar5 = (float10)param_3;
        if (fVar6 < fVar5) {
          return CONCAT31((int3)(CONCAT22(extraout_var,
                                          (ushort)(fVar6 < fVar5) << 8 |
                                          (ushort)(NAN(fVar6) || NAN(fVar5)) << 10 |
                                          (ushort)(fVar6 == fVar5) << 0xe) >> 8),1);
        }
      }
    }
    local_8 = FUN_00421960(param_1);
  } while( true );
}


// ==== 0x59b2c0 PickRandomSection

/* [canon] traffic med (G) docs/re/traffic.md */

void __thiscall PickRandomSection(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_10;
  int local_c;
  
  iVar1 = FUN_004216b0(*(undefined4 *)(param_1 + 0xc));
  local_c = 0;
  local_10 = 0;
  do {
    if (99 < local_10) {
      return;
    }
    iVar2 = PtrArray_GetOrNull();
    if ((iVar2 != 0) && (iVar2 = Section_HasLane(), iVar2 != 0)) {
      iVar2 = FUN_00432e00();
      local_c = local_c + iVar2;
      if (iVar1 < local_c) {
        uVar3 = PtrArray_GetOrNull();
        *param_2 = uVar3;
        uVar3 = FUN_00432df0();
        param_2[1] = uVar3;
        return;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


// ==== 0x59b370 Teleporter_PickPlayer

/* [canon] traffic med (G) docs/re/traffic.md */

int Teleporter_PickPlayer(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((DAT_00734454 == 0) || (DAT_006fbf14 != 0)) ||
     (iVar1 = RaceManager__FindRacerByIdIn(), iVar1 == 0)) {
    uVar2 = FUN_00408200();
    FUN_004216b0(uVar2);
    GetPlayerObject();
    iVar1 = FUN_00417490();
  }
  return iVar1;
}


// ==== 0x59b3e0 Teleporter_Spacing

/* WARNING: Removing unreachable block (ram,0x0059b479) */
/* [canon] traffic high (H+G+file) docs/re/traffic.md */

float10 Teleporter_Spacing(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float local_8;
  
  local_8 = 99999.0;
  FUN_00424e60();
  iVar2 = Zone_FindTrafficDensity();
  if ((iVar2 != 0) && (cVar1 = Teleporter_SlowCarNear(param_1), cVar1 == '\0')) {
    fVar3 = (float10)Zone_SpacingMin(iVar2,DAT_0078a300);
    fVar4 = (float10)Zone_SpacingMax(iVar2,DAT_0078a300);
    fVar4 = (float10)Random_NextFloat((float)(fVar4 - (float10)(float)fVar3));
    local_8 = (float)(fVar4 + (float10)(float)fVar3);
  }
  return (float10)local_8;
}


// ==== 0x59b490 NearestPlayer

/* [canon] traffic med (G) docs/re/traffic.md */

int NearestPlayer(void)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  int local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_8 = 0;
  if (((DAT_00734454 == 0) || (DAT_006fbf14 != 0)) ||
     (local_8 = RaceManager__FindRacerByIdIn(), local_8 == 0)) {
    local_c = 99999.0;
    local_10 = 0;
    for (local_14 = 0; iVar1 = FUN_00408200(), local_14 < iVar1; local_14 = local_14 + 1) {
      iVar1 = GetPlayerObject();
      FUN_00417490();
      fVar2 = (float10)FUN_0041f5f0();
      fVar5 = (float)fVar2;
      fVar2 = (float10)FUN_0041f5f0(fVar5);
      fVar2 = (float10)TrackPath__WrapDistance((float)fVar2,fVar5);
      fVar3 = (float10)FUN_00405600((float)fVar2);
      fVar4 = (float10)FUN_00405600(local_c);
      if ((float10)(float)fVar3 < fVar4) {
        local_10 = iVar1;
        local_c = (float)fVar2;
      }
    }
    if (local_10 != 0) {
      local_8 = FUN_00417490();
    }
  }
  return local_8;
}


// ==== 0x59b590 TrafficCar_PickPaint

/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 TrafficCar_PickPaint(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0057d100();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004216b0(iVar1);
    uVar2 = FUN_0057d120(uVar2);
  }
  return uVar2;
}


// ==== 0x59b5d0 FUN_0059b5d0

void __fastcall FUN_0059b5d0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_004134c0(param_1);
  iVar2 = TrafficCar_PickPaint(uVar1);
  iVar3 = FUN_0041e4c0();
  if (iVar2 != *(char *)(iVar3 + 7)) {
    FUN_00569c30(iVar2);
  }
  return;
}


// ==== 0x59b620 TrafficDriverMode_Map

/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 TrafficDriverMode_Map(void)

{
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  if (DAT_0078a3fc == 0) {
    local_8 = 9;
  }
  else if (DAT_0078a3fc == 1) {
    local_8 = 4;
  }
  else if (DAT_0078a3fc == 2) {
    local_8 = 0;
  }
  return local_8;
}


// ==== 0x59b670 Zone_SpacingMin

/* [canon] traffic high (C+G) docs/re/traffic.md */

float10 Zone_SpacingMin(void)

{
  int iVar1;
  
  iVar1 = FUN_00444260();
  return (float10)iVar1;
}


// ==== 0x59b6a0 Zone_SpacingMax

/* [canon] traffic high (C+G) docs/re/traffic.md */

float10 Zone_SpacingMax(void)

{
  int iVar1;
  
  iVar1 = FUN_00444260();
  return (float10)iVar1;
}


// ==== 0x59b6d0 Intersections_UpdateAll

/* [canon] traffic high (H+G) docs/re/traffic.md */

void Intersections_UpdateAll(void)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_0044a320();
    if (iVar1 <= local_8) break;
    RoadIntersection_Get();
    Intersection_Update();
    local_8 = local_8 + 1;
  }
  return;
}


// ==== 0x59b710 Teleporter_Disable

/* [canon] traffic med (G) docs/re/traffic.md */

void __fastcall Teleporter_Disable(int param_1)

{
  int iVar1;
  int local_8;
  
  if (DAT_007361f8 != 0) {
    for (local_8 = 0; iVar1 = FUN_0041f680(), local_8 < iVar1; local_8 = local_8 + 1) {
      FUN_0041f690();
      FUN_00432d30(0);
      FUN_00424dc0();
      CarBody_DisableCountInc();
      Car_SetMode();
    }
    *(undefined1 *)(param_1 + 8) = 0;
  }
  return;
}


// ==== 0x59b790 Teleporter_Enable

/* [canon] traffic med (G) docs/re/traffic.md */

void __fastcall Teleporter_Enable(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  if (DAT_007361f8 != 0) {
    for (local_8 = 0; iVar1 = FUN_0041f680(), local_8 < iVar1; local_8 = local_8 + 1) {
      FUN_0041f690();
      piVar2 = (int *)FUN_00424dc0();
      CollisionBody__EnableCollisions();
      iVar1 = (**(code **)(*piVar2 + 0x50))();
      if (iVar1 == 0) {
        FUN_00432d30(0);
        Car_SetMode();
      }
      else {
        FUN_00432d30(1);
        Car_SetMode();
      }
    }
    *(undefined1 *)(param_1 + 8) = 1;
  }
  return;
}


// ==== 0x59b840 FUN_0059b840

void FUN_0059b840(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = -1;
  if (*param_2 != 0) {
    local_8 = FUN_00421960();
  }
  FUN_0041f670();
  iVar1 = FUN_0041f640();
  if ((iVar1 != 0) && (*param_2 = 0, -1 < local_8)) {
    local_c = 0;
    while( true ) {
      iVar1 = SpawnRecord_Count();
      if (iVar1 <= local_c) break;
      iVar1 = SpawnRecord_Get();
      iVar2 = FUN_00421960();
      if (iVar2 == local_8) {
        *param_2 = iVar1;
      }
      local_c = local_c + 1;
    }
  }
  return;
}


// ==== 0x59b8d0 Teleporter_SlowCarNear

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (G) docs/re/traffic.md */

uint __fastcall Teleporter_SlowCarNear(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined2 extraout_var;
  float10 fVar4;
  float10 fVar5;
  float fVar6;
  char local_11;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  do {
    uVar2 = FUN_0041f680(param_1);
    if ((int)uVar2 <= local_c) {
      return uVar2 & 0xffffff00;
    }
    FUN_0041f690();
    fVar4 = (float10)FUN_00424e10();
    if (fVar4 < (float10)SpawnRecordWindow) {
      local_11 = '\0';
      cVar1 = FUN_00424da0();
      if (cVar1 != '\0') {
        iVar3 = FUN_0041f5d0();
        local_11 = *(char *)(iVar3 + 0x4d1);
      }
      if (local_11 == '\0') {
        fVar4 = (float10)FUN_0041f5f0();
        fVar6 = (float)fVar4;
        fVar4 = (float10)FUN_0041f5f0(fVar6);
        fVar4 = (float10)TrackPath__WrapDistance((float)fVar4,fVar6);
        fVar5 = (float10)FUN_00405600((float)fVar4);
        fVar4 = (float10)250.0;
        if ((fVar5 < fVar4) && (local_8 = local_8 + 1, 0 < local_8)) {
          return CONCAT31((int3)(CONCAT22(extraout_var,
                                          (ushort)(fVar5 < fVar4) << 8 |
                                          (ushort)(NAN(fVar5) || NAN(fVar4)) << 10 |
                                          (ushort)(fVar5 == fVar4) << 0xe) >> 8),1);
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== 0x59b9c0 FUN_0059b9c0

void __fastcall FUN_0059b9c0(undefined4 param_1)

{
  int iVar1;
  void *_Memory;
  
  while( true ) {
    iVar1 = bList__IsEmpty(param_1);
    if (iVar1 != 0) break;
    _Memory = (void *)bList__RemoveHead();
    _free(_Memory);
  }
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1);
  return;
}


// ==== 0x59ba00 FUN_0059ba00

void __fastcall FUN_0059ba00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  
  *in_EAX = param_1;
  in_EAX[1] = param_2;
  in_EAX[2] = param_3;
  return;
}


// ==== 0x59ba10 FUN_0059ba10

bool __fastcall FUN_0059ba10(int *param_1)

{
  return *param_1 == 0;
}


// ==== 0x59ba20 FUN_0059ba20

void FUN_0059ba20(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"DrivingLocation");
  FUN_00442c20(&DAT_0077af20);
  FUN_00442c80(&DAT_0077af20);
  FUN_00571c20(param_2,param_1 + 8,1,4,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x59bab0 FUN_0059bab0

float10 FUN_0059bab0(void)

{
  int *in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)50.0;
  if (*in_EAX != 0) {
    fVar1 = (float10)((uint)*(byte *)(in_EAX[2] + 0x6a + in_EAX[1]) << 0x10) *
            (float10)1.5258789e-05;
  }
  return fVar1;
}


// ==== 0x59bae0 FUN_0059bae0

undefined4 FUN_0059bae0(int *param_1,int *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (iVar4 == 0) {
    sVar2 = -1;
  }
  else {
    sVar2 = *(short *)(iVar4 + 10);
  }
  iVar3 = *param_2;
  if (iVar3 == 0) {
    sVar1 = -1;
  }
  else {
    sVar1 = *(short *)(iVar3 + 10);
  }
  if (sVar2 == sVar1) {
    if (iVar4 == 0) {
      iVar4 = -1;
    }
    else {
      iVar4 = ((param_1[1] - iVar4) + -0x27c) / 0x88;
    }
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = ((param_2[1] - iVar3) + -0x27c) / 0x88;
    }
    if ((iVar4 == iVar3) && (param_1[2] == param_2[2])) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x59bb80 FUN_0059bb80

int __fastcall FUN_0059bb80(int *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  if (*unaff_ESI == 0) {
    iVar2 = -1;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x40))();
    iVar2 = unaff_ESI[2];
    if (iVar1 != 0) {
      if (iVar2 < 5) {
        return iVar2 + 5;
      }
      if ((10 < iVar2) && (iVar2 < 0x11)) {
        return iVar2 + 6;
      }
    }
  }
  return iVar2;
}


// ==== 0x59bbb0 FUN_0059bbb0

undefined4 __fastcall FUN_0059bbb0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}


// ==== 0x59bbc0 FUN_0059bbc0

undefined4 * FUN_0059bbc0(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00458a50(param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006b89c0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  FUN_0059bd90(1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x59bc20 FUN_0059bc20

void * __thiscall FUN_0059bc20(void *param_1,byte param_2)

{
  FUN_0059bc40();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x59bc40 FUN_0059bc40

void __fastcall FUN_0059bc40(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c8f08;
  return;
}


// ==== 0x59bc50 FUN_0059bc50

void __thiscall FUN_0059bc50(int *param_1,float param_2)

{
  param_2 = (float)param_1[0xc] - param_2;
  param_1[0xc] = (int)param_2;
  if (param_2 <= 0.0) {
    param_1[0xd] = (int)((*(float *)(param_1[1] + 0x3d4) - (float)param_1[0xe]) / (0.1 - param_2));
                    /* WARNING: Could not recover jumptable at 0x0059bc8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2c))();
    return;
  }
  return;
}


// ==== 0x59bca0 FUN_0059bca0

void __thiscall FUN_0059bca0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TrackedController");
  (**(code **)(**(int **)(param_1 + 8) + 8))(param_2);
  FUN_00571c20(param_2,param_1 + 0xc,0x20,0xffffffff,0);
  FUN_00442d10();
  FUN_00571c20(param_2,param_1 + 0x30,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x34,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x38,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x59bd50 FUN_0059bd50

void __thiscall FUN_0059bd50(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  *(undefined4 *)(param_1 + 0x30) = 0x3dcccccd;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3d4);
  return;
}


// ==== 0x59bd70 FUN_0059bd70

undefined4 __fastcall FUN_0059bd70(int param_1)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    return (&DAT_0077af30)[*(byte *)(*(int *)(param_1 + 0x2c) + 0x83)];
  }
  return 0;
}


// ==== 0x59bd90 FUN_0059bd90

void __thiscall FUN_0059bd90(int *param_1,char param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_8 [4];
  int iStack_4;
  
  param_1[5] = param_1[5] & 0xfffffffe;
  param_1[3] = param_1[3] & 0xfffffffe;
  param_1[4] = param_1[4] & 0xfffffffe;
  param_1[10] = param_1[10] & 0xfffffffe;
  param_1[6] = param_1[6] & 0xfffffffe;
  param_1[7] = param_1[7] & 0xfffffffe;
  param_1[8] = param_1[8] & 0xfffffffe;
  param_1[9] = param_1[9] & 0xfffffffe;
  iVar1 = param_1[1];
  if (param_1[0xb] != 0) {
    iVar5 = FUN_00442690((&DAT_0077af30)[*(byte *)(param_1[0xb] + 0x83)],0x41c00000,0x24,
                         *(undefined4 *)(iVar1 + 0x814));
    param_1[0xb] = iVar5;
    if (iVar5 != 0) {
      iVar5 = (**(code **)(*param_1 + 0x40))();
      pfVar2 = (float *)param_1[0xb];
      fVar3 = *(float *)(iVar1 + 0x60) - *pfVar2;
      if (iVar5 == 0) {
        fVar3 = fVar3 * pfVar2[4] - (*(float *)(iVar1 + 100) - pfVar2[1]) * pfVar2[3];
        if (fVar3 <= 0.0) {
          fVar3 = -(fVar3 + pfVar2[9]);
        }
        else {
          fVar3 = fVar3 - pfVar2[10];
        }
      }
      else {
        fVar3 = fVar3 * pfVar2[6] - (*(float *)(iVar1 + 100) - pfVar2[1]) * pfVar2[5];
        if (0.0 <= fVar3) {
          fVar3 = fVar3 - pfVar2[9];
        }
        else {
          fVar3 = -(fVar3 + pfVar2[10]);
        }
      }
      if (5.0 < fVar3) {
        param_1[0xb] = 0;
      }
    }
  }
  if (param_1[0xb] == 0) {
    uVar6 = 0x24;
    if (param_2 == '\0') {
      uVar6 = 100;
    }
    iVar1 = param_1[1];
    cVar4 = FUN_004561d0(local_8,uVar6 | 0x8c0,*(undefined4 *)(iVar1 + 0x814));
    if (cVar4 == '\0') {
      cVar4 = FUN_004561d0(local_8,uVar6,*(undefined4 *)(iVar1 + 0x814));
      if (cVar4 == '\0') goto LAB_0059bef4;
    }
    param_1[0xb] = iStack_4;
  }
LAB_0059bef4:
  param_1[0xc] = 0x3dcccccd;
  param_1[0xe] = *(int *)(param_1[1] + 0x3d4);
  return;
}


// ==== 0x59bf20 FUN_0059bf20

float10 __fastcall FUN_0059bf20(int *param_1)

{
  float *pfVar1;
  float unaff_ESI;
  float10 fVar2;
  
  pfVar1 = (float *)(**(code **)(*param_1 + 0x18))(1);
  if (pfVar1 == (float *)0x0) {
    return (float10)unaff_ESI;
  }
  fVar2 = ((float10)*(float *)(param_1[1] + 0x60) - (float10)*pfVar1) * (float10)pfVar1[4] -
          ((float10)*(float *)(param_1[1] + 100) - (float10)pfVar1[1]) * (float10)pfVar1[3];
  if ((float10)0.0 < fVar2) {
    return fVar2 - (float10)pfVar1[10];
  }
  return -(fVar2 + (float10)pfVar1[9]);
}


// ==== 0x59bf80 FUN_0059bf80

undefined4 __fastcall FUN_0059bf80(int param_1)

{
  return *(undefined4 *)(param_1 + 0x48);
}


// ==== 0x59bf90 FUN_0059bf90

undefined4 __fastcall FUN_0059bf90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}


// ==== 0x59bfa0 FUN_0059bfa0

undefined4 __fastcall FUN_0059bfa0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}


// ==== 0x59bfb0 FUN_0059bfb0

undefined4 __fastcall FUN_0059bfb0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}


// ==== 0x59bfc0 FUN_0059bfc0

undefined4 * __thiscall FUN_0059bfc0(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0059bbc0(param_2,param_1);
  *param_2 = &PTR_FUN_006b8968;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0xffffffff;
  local_4 = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0xffffffff;
  pvVar1 = _malloc(0x2c0);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00460e70();
  }
  param_2[2] = uVar2;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x15] = DAT_0078a2fc;
  param_2[0x11] = 0;
  FUN_00457060(param_2 + 0x11);
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0xffffffff;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0xffffffff;
  FUN_005a5340();
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x59c080 FUN_0059c080

void * __thiscall FUN_0059c080(void *param_1,byte param_2)

{
  FUN_0059c0a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x59c0a0 FUN_0059c0a0

void __fastcall FUN_0059c0a0(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684c88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006b8968;
  local_4 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x11])(1);
  }
  *param_1 = &PTR_FUN_006c8f08;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x59c100 FUN_0059c100

void __thiscall FUN_0059c100(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"RealController");
  FUN_0059ba20(param_1 + 0x48,param_2);
  FUN_0059ba20(param_1 + 0x60,param_2);
  FUN_005a4f90();
  FUN_0059bca0(param_2);
  FUN_00571c20(param_2,param_1 + 0x58,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x5c,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x59c1a0 FUN_0059c1a0

float10 FUN_0059c1a0(void)

{
  return (float10)2.0;
}


// ==== 0x59c1b0 FUN_0059c1b0

int FUN_0059c1b0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) &&
     (iVar1 = GetNearestTrafficLane(*(undefined4 *)(unaff_ESI + 4),DAT_0078a2fc,0xff,0xff),
     iVar1 != -1)) {
    return iVar1;
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + 0x10);
  if (*(char *)(iVar1 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  return (int)*(char *)(iVar1 + 0x424);
}


// ==== 0x59c210 FUN_0059c210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0059c210(int *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  undefined4 uStack_1d4;
  undefined4 auStack_1d0 [105];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iVar3 = (**(code **)(*param_1 + 0x40))();
  if (iVar3 != param_1[0x15]) {
    FUN_00457060(param_1 + 0x11);
    FUN_005a5340();
    param_1[3] = param_1[3] & 0xfffffffe;
    param_1[4] = param_1[4] & 0xfffffffe;
    param_1[5] = param_1[5] & 0xfffffffe;
    param_1[6] = param_1[6] & 0xfffffffe;
    param_1[7] = param_1[7] & 0xfffffffe;
    param_1[8] = param_1[8] & 0xfffffffe;
    param_1[9] = param_1[9] & 0xfffffffe;
    param_1[10] = param_1[10] & 0xfffffffe;
  }
  param_1[0x15] = iVar3;
  FUN_00458cc0(iVar3);
  FUN_0059c460();
  uStack_2c = 0;
  uStack_28 = 0;
  puVar4 = auStack_1d0;
  for (iVar3 = 0x70; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  FUN_00458f10(0,0);
  uStack_1e0 = 0;
  if (*(int *)(param_1[0x11] + 4) == 0) {
    if (*(float *)(param_1[1] + 0x3d0) < 10.0) {
      fVar5 = (float10)FUN_00458b90(*(undefined2 *)(param_1[1] + 0x3b4));
      FUN_00456de0((float)fVar5);
    }
    else {
      FUN_0045a1e0(auStack_1d0);
    }
  }
  else {
    fStack_1dc = 0.0;
    uStack_1d4 = FUN_0059c1b0(param_1[0x13]);
    fStack_1d8 = 0.0;
    uStack_1e0 = FUN_005a6700(&uStack_1e0,&fStack_1dc,uStack_1d4);
    cVar2 = FUN_0059bae0(param_1 + 0x12,param_1 + 0x18);
    if (cVar2 == '\0') {
      fStack_1d8 = (float)param_1[0x17];
    }
    else if (0.0001 < param_2) {
      fStack_1d8 = (fStack_1dc - (float)param_1[0x16]) / param_2;
    }
    fVar1 = _K_ONE - 0.05;
    param_1[0x18] = param_1[0x12];
    param_1[0x16] = (int)fStack_1dc;
    param_1[0x19] = param_1[0x13];
    param_1[0x1a] = param_1[0x14];
    fStack_1d8 = fStack_1d8 * 0.05 + fVar1 * (float)param_1[0x17];
    param_1[0x17] = (int)fStack_1d8;
    if (*(float *)(param_1[1] + 0x3d0) < 10.0) {
      FUN_00456ce0(auStack_1d0);
    }
    else {
      FUN_0059c600(param_1,auStack_1d0,fStack_1d8,fStack_1dc,uStack_1d4);
      FUN_0045a4c0();
    }
  }
  (**(code **)(*(int *)param_1[2] + 0x3c))(auStack_1d0);
  if (DAT_006fbf18 == *(short *)(param_1[1] + 10)) {
    FUN_00455c50(&DAT_0077a4b0,&uStack_1d4);
    FUN_00455d60(&DAT_0077a6d8,param_1[0x11],uStack_1e4);
  }
  return;
}


// ==== 0x59c460 FUN_0059c460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059c460(void)

{
  int *in_EAX;
  int iVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float local_20;
  undefined4 local_1c;
  int local_18;
  float local_14;
  
  local_14 = (*(float *)(*(int *)(in_EAX[1] + 0x3c) + 0x104) -
             *(float *)(*(int *)(in_EAX[1] + 0x3c) + 0xf4)) * _K_HALF;
  if (*(int *)(in_EAX[0x11] + 4) == 0) {
LAB_0059c57d:
    (**(code **)(*in_EAX + 0x2c))(1);
    iVar1 = in_EAX[0xb];
    fVar2 = 0.0;
    if (iVar1 == 0) {
      local_20 = 0.0;
    }
    else {
      local_20 = (float)(&DAT_0077af30)[*(byte *)(iVar1 + 0x83)];
    }
    if ((local_20 != 0.0) && (iVar1 != 0)) {
      iVar3 = FUN_0059c1b0(iVar1);
      in_EAX[0x12] = (int)local_20;
      in_EAX[0x13] = iVar1;
      in_EAX[0x14] = iVar3;
      goto LAB_0059c5d7;
    }
    in_EAX[0x12] = 0;
    in_EAX[0x14] = -1;
  }
  else {
    local_18 = FUN_0059c1b0(in_EAX[0x13]);
    local_20 = 0.0;
    local_1c = 0;
    FUN_005a6700(&local_20,&local_1c,local_18);
    iVar1 = in_EAX[0x11];
    FUN_005a67d0(local_20,0);
    if (*(int *)(iVar1 + 4) == 0) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = *(float *)(*(int *)(iVar1 + 8) + 0x58);
    }
    if (local_20 < fVar2 - 24.0) goto LAB_0059c57d;
    if (*(int *)(iVar1 + 4) == 0) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = *(float *)(*(int *)(iVar1 + 4 + *(int *)(iVar1 + 4) * 4) + 0x58);
    }
    if (local_20 < fVar2 == (local_20 == fVar2)) goto LAB_0059c57d;
    fVar4 = (float10)FUN_005a71f0(local_1c);
    if (fVar4 < (float10)local_14 == (fVar4 == (float10)local_14)) goto LAB_0059c57d;
    local_18 = in_EAX[0x14];
    local_14 = (float)FUN_0044a2c0();
    iVar1 = FUN_0044a2a0();
    in_EAX[0x12] = iVar1;
    in_EAX[0x14] = local_18;
    fVar2 = local_14;
  }
  in_EAX[0x13] = (int)fVar2;
LAB_0059c5d7:
  if (in_EAX[0x12] != 0) {
    FUN_005a5730(in_EAX + 0x12,in_EAX[1]);
    return;
  }
  FUN_005a5340();
  return;
}


// ==== 0x59c600 FUN_0059c600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_0059c600(undefined4 param_1,int param_2,int param_3,char *param_4,float param_5,float param_6,
            int param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float local_3c;
  float local_38;
  int local_34;
  int local_28;
  undefined1 local_20 [28];
  
  local_3c = param_6;
  fVar2 = *(float *)(*(int *)(param_3 + 4) + 0x3d4);
  iVar7 = *(int *)(*(int *)(param_3 + 4) + 0x3c);
  iVar6 = *(int *)(param_3 + 0x44);
  fVar5 = (*(float *)(iVar7 + 0x104) - *(float *)(iVar7 + 0xf4)) * _K_HALF;
  local_34 = param_2 * 4 + 8;
  iVar7 = *(int *)(local_34 + iVar6);
  local_28 = param_2;
  if (param_2 < *(int *)(iVar6 + 4)) {
    do {
      if ('\x13' < *param_4) {
        return;
      }
      pfVar1 = (float *)(iVar7 + 0x58);
      iVar7 = *(int *)(local_34 + iVar6);
      fVar3 = (*(float *)(iVar7 + 0x58) - *pfVar1) / fVar2;
      fVar4 = fVar3 * 0.7;
      if (local_3c <= 0.0) {
        param_5 = fVar4 + param_5;
      }
      else {
        param_5 = param_5 - fVar4;
      }
      fVar3 = fVar3 * param_5 + local_3c;
      if ((param_7 < 0) || (4 < param_7)) {
        if ((param_7 < 0xb) || (0x10 < param_7)) {
          local_38 = 0.0;
        }
        else {
          local_38 = *(float *)(iVar7 + 0x14 + param_7 * 4);
        }
      }
      else {
        local_38 = *(float *)(iVar7 + 0x3c);
      }
      if ((param_7 < 0) || (4 < param_7)) {
        if ((param_7 < 0xb) || (0x10 < param_7)) {
          local_3c = 0.0;
        }
        else {
          local_3c = *(float *)(iVar7 + -8 + param_7 * 4);
        }
      }
      else {
        local_3c = *(float *)(iVar7 + 0x20);
      }
      local_38 = local_38 - fVar5;
      local_3c = local_3c + fVar5;
      if (local_3c < fVar3) {
        local_3c = fVar3;
      }
      if (local_38 < local_3c) {
        local_3c = local_38;
      }
      FUN_005a7270(local_20,*(undefined4 *)(iVar7 + 0x58),local_3c,param_7);
      FUN_004594d0(*(undefined1 *)(iVar7 + 0x5c),*(undefined2 *)(iVar7 + 0x5e),param_7,1);
      iVar6 = *(int *)(param_3 + 0x44);
      local_28 = local_28 + 1;
      local_34 = local_34 + 4;
    } while (local_28 < *(int *)(iVar6 + 4));
  }
  return;
}


// ==== 0x59c7b0 FUN_0059c7b0

uint __fastcall FUN_0059c7b0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (*(float *)(iVar3 + 0x3d4) * 2.237 <= 10.0) {
    fVar1 = *(float *)(iVar3 + 0x90);
    fVar2 = *(float *)(iVar3 + 0x94);
  }
  else {
    fVar1 = *(float *)(iVar3 + 0x70);
    fVar2 = *(float *)(iVar3 + 0x74);
  }
  if (0.0 < fVar2 * *(float *)(iVar3 + 0x81c) + fVar1 * *(float *)(iVar3 + 0x818)) {
    return DAT_0078a2fc;
  }
  return (uint)(DAT_0078a2fc == 0);
}


// ==== 0x59c820 FUN_0059c820

undefined1 FUN_0059c820(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = *(char *)(param_1 + 0xb);
  uVar2 = 0;
  if ((cVar1 == '\b') || (cVar1 == '\x02')) {
    uVar2 = 1;
  }
  else if (((cVar1 == '\x05') || (cVar1 == '\a')) || (cVar1 == '\0')) {
    return 0;
  }
  return uVar2;
}


// ==== 0x59c850 Spline::InitBasis

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Ghidra make FUN_0059c850) docs/re/assets.md */

void Spline__InitBasis(void)

{
  if (DAT_00734448 == 0) {
    _DAT_007376b0 = 0;
    _DAT_007376b4 = 0xbf000000;
    _DAT_007376b8 = 0x3f800000;
    _DAT_007376bc = 0xbf000000;
    _DAT_007376c0 = 0x3f800000;
    _DAT_007376c4 = 0;
    _DAT_007376c8 = 0xc0200000;
    _DAT_007376cc = 0x3fc00000;
    _DAT_007376d0 = 0;
    _DAT_007376d4 = 0x3f000000;
    _DAT_007376d8 = 0x40000000;
    _DAT_007376dc = 0xbfc00000;
    _DAT_007376e0 = 0;
    _DAT_007376e4 = 0;
    _DAT_007376e8 = 0xbf000000;
    _DAT_007376ec = 0x3f000000;
    _DAT_007376f0 = 0xbf000000;
    _DAT_007376f4 = 0x40000000;
    _DAT_007376f8 = 0xbfc00000;
    _DAT_007376fc = 0;
    _DAT_00737700 = 0;
    _DAT_00737704 = 0xc0a00000;
    _DAT_00737708 = 0x40900000;
    _DAT_0073770c = 0;
    _DAT_00737710 = 0x3f000000;
    _DAT_00737714 = 0x40800000;
    _DAT_00737718 = 0xc0900000;
    _DAT_0073771c = 0;
    _DAT_00737720 = 0;
    _DAT_00737724 = 0xbf800000;
    _DAT_00737728 = 0x3fc00000;
    _DAT_0073772c = 0;
    _DAT_00737730 = 0x40000000;
    _DAT_00737734 = 0xc0400000;
    _DAT_00737738 = 0;
    _DAT_0073773c = 0;
    _DAT_00737740 = 0xc0a00000;
    _DAT_00737744 = 0x41100000;
    _DAT_00737748 = 0;
    _DAT_0073774c = 0;
    _DAT_00737750 = 0x40800000;
    _DAT_00737754 = 0xc1100000;
    _DAT_00737758 = 0;
    _DAT_0073775c = 0;
    _DAT_00737760 = 0xbf800000;
    _DAT_00737764 = 0x40400000;
    _DAT_00737768 = 0;
    _DAT_0073776c = 0;
    bMatrixCopy();
    bMatrixCopy();
    bMatrixCopy();
    DAT_00734448 = 1;
  }
  return;
}


// ==== 0x59ca70 FUN_0059ca70

void FUN_0059ca70(int param_1,int param_2)

{
  ushort *puVar1;
  char cVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  
  FUN_00571ea0(0,"QuickSpline");
  puVar1 = (ushort *)(param_1 + 0x1e);
  FUN_00571c20(unaff_ESI,puVar1,2,2,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0' || *(char *)(unaff_ESI + 0x3c) != '\0') {
    FUN_0059cb20();
  }
  iVar3 = 0;
  if (*puVar1 != 0) {
    iVar4 = 0;
    do {
      FUN_00571c20(unaff_ESI,*(int *)(param_1 + 0x24) + iVar4,param_2 * 4,0xffffffff,0);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < (int)(uint)*puVar1);
  }
  iVar3 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar3 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar3 + 0x58 + unaff_ESI);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x59cb20 FUN_0059cb20

void __fastcall FUN_0059cb20(ushort param_1)

{
  int iVar1;
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x18) = 1;
  *(ushort *)(in_EAX + 0x1e) = param_1;
  if (param_1 == 0) {
    *(undefined4 *)(in_EAX + 0xc) = 0;
    *(undefined4 *)(in_EAX + 0x10) = 0;
  }
  else {
    iVar1 = *(int *)(in_EAX + 4);
    if (iVar1 == 0) {
      *(undefined4 *)(in_EAX + 0x10) = 0;
      *(float *)(in_EAX + 0xc) = (float)param_1;
      return;
    }
    if (iVar1 == 1) {
      *(undefined4 *)(in_EAX + 0x10) = 0;
      *(float *)(in_EAX + 0xc) = (float)(int)(param_1 - 1);
      return;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(in_EAX + 0x10) = 0xcb18967f;
      *(undefined4 *)(in_EAX + 0xc) = 0x4b18967f;
      return;
    }
  }
  return;
}


// ==== 0x59cb90 FUN_0059cb90

void FUN_0059cb90(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int unaff_EDI;
  
  if (*(ushort *)(unaff_EDI + 0x1e) != 0) {
    puVar3 = *(undefined4 **)(unaff_EDI + 0x24);
    uVar7 = (uint)*(ushort *)(unaff_EDI + 0x1e);
    iVar4 = *(int *)(unaff_EDI + 4);
    if (iVar4 == 0) {
      uVar5 = puVar3[uVar7 * 4 + -1];
      uVar2 = puVar3[uVar7 * 4 + -2];
      uVar6 = puVar3[uVar7 * 4 + -4];
      puVar1 = puVar3 + uVar7 * 4;
      puVar3[-3] = puVar3[uVar7 * 4 + -3];
      puVar3[-1] = uVar5;
      puVar3[-4] = uVar6;
      puVar3[-2] = uVar2;
      uVar6 = puVar3[3];
      uVar2 = puVar3[1];
      uVar5 = puVar3[2];
      *puVar1 = *puVar3;
      puVar1[1] = uVar2;
      puVar1[3] = uVar6;
      puVar1[2] = uVar5;
      uVar2 = puVar3[5];
      uVar6 = puVar3[4];
      uVar5 = puVar3[6];
      puVar1[7] = puVar3[7];
      puVar1[4] = uVar6;
      puVar1[5] = uVar2;
      puVar1[6] = uVar5;
      if (*(float *)(unaff_EDI + 0x14) != 0.0) {
        puVar3[-1] = (float)puVar1[-1] - *(float *)(unaff_EDI + 0x14);
        puVar1[3] = *(float *)(unaff_EDI + 0x14) + (float)puVar3[3];
        puVar1[7] = (float)puVar3[7] + *(float *)(unaff_EDI + 0x14);
      }
    }
    else if (iVar4 == 1) {
      puVar3[-4] = *puVar3;
      puVar3[-3] = puVar3[1];
      puVar3[-1] = puVar3[3];
      puVar3[-2] = puVar3[2];
      uVar5 = puVar3[uVar7 * 4 + -4];
      uVar2 = puVar3[uVar7 * 4 + -2];
      puVar1 = puVar3 + uVar7 * 4;
      puVar1[1] = puVar3[uVar7 * 4 + -3];
      *puVar1 = uVar5;
      puVar1[2] = uVar2;
      puVar1[3] = puVar1[-1];
      if (*(float *)(unaff_EDI + 0x14) != 0.0) {
        puVar3[-1] = -(float)puVar3[7];
        puVar1[3] = (*(float *)(unaff_EDI + 0x14) + *(float *)(unaff_EDI + 0x14)) -
                    (float)puVar1[-1];
        return;
      }
    }
    else if (iVar4 == 2) {
      FUN_00567500(0xbf800000);
      FUN_00567500(0x3f800000);
      if (*(float *)(unaff_EDI + 0x14) != 0.0) {
        puVar3[-1] = -(float)puVar3[7];
        puVar3[uVar7 * 4 + 3] =
             (*(float *)(unaff_EDI + 0x14) + *(float *)(unaff_EDI + 0x14)) -
             (float)puVar3[uVar7 * 4 + -1];
        return;
      }
    }
  }
  return;
}


// ==== 0x59cdb0 FUN_0059cdb0

void __fastcall
FUN_0059cdb0(undefined4 param_1,int param_2,undefined4 param_3,float param_4,undefined4 param_5)

{
  int in_EAX;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined1 local_20 [28];
  
  local_28 = param_4 * param_4;
  local_2c = param_4;
  local_24 = local_28 * param_4;
  local_30 = 0x3f800000;
  thunk_FUN_005ac436(local_20,&local_30,in_EAX * 0x40 + *(int *)(param_2 + 0x28));
  thunk_FUN_005ac436(param_3,&local_2c,param_5);
  return;
}


// ==== 0x59ce10 FUN_0059ce10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0059ce10(int param_1,float param_2)

{
  float fVar1;
  float10 fVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    fVar1 = *(float *)(param_1 + 0xc);
    param_2 = param_2 / ABS(fVar1);
    fVar2 = (float10)Float_Truncate(param_2);
    if ((float10)param_2 < fVar2) {
      fVar2 = fVar2 - (float10)_K_ONE;
    }
    return ((float10)param_2 - fVar2) * (float10)ABS(fVar1);
  }
  if (*(int *)(param_1 + 4) == 1) {
    fVar1 = *(float *)(param_1 + 0xc) - 1e-07;
    fVar2 = (float10)*(float *)(param_1 + 0x10);
    if (fVar2 < (float10)param_2) {
      fVar2 = (float10)param_2;
    }
    if ((float10)fVar1 < fVar2) {
      return (float10)fVar1;
    }
  }
  else {
    fVar2 = (float10)param_2;
  }
  return fVar2;
}


// ==== 0x59cea0 FUN_0059cea0

void __fastcall FUN_0059cea0(float *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  float fVar14;
  int in_EAX;
  float *pfVar15;
  float fVar16;
  float *pfVar17;
  uint uVar18;
  
  iVar1 = param_2 + 2;
  pfVar13 = *(float **)(in_EAX + 0x24);
  uVar18 = (uint)*(ushort *)(in_EAX + 0x1e);
  iVar2 = param_2 + 3;
  iVar3 = param_2 + 1;
  if (param_2 < -1) {
    fVar7 = (float)-param_2;
    fVar5 = (pfVar13[1] - pfVar13[5]) * fVar7 + pfVar13[1];
    fVar6 = (pfVar13[2] - pfVar13[6]) * fVar7 + pfVar13[2];
    fVar16 = (pfVar13[3] - pfVar13[7]) * fVar7 + pfVar13[3];
    *param_1 = (*pfVar13 - pfVar13[4]) * fVar7 + *pfVar13;
  }
  else if ((int)uVar18 < param_2) {
    pfVar15 = pfVar13 + uVar18 * 4 + -4;
    pfVar17 = pfVar13 + (uVar18 - 2) * 4;
    fVar7 = (float)(int)((param_2 - uVar18) + 1);
    fVar5 = (pfVar15[1] - pfVar17[1]) * fVar7 + pfVar15[1];
    fVar6 = (pfVar15[2] - pfVar17[2]) * fVar7 + pfVar15[2];
    fVar16 = (pfVar15[3] - pfVar17[3]) * fVar7 + pfVar15[3];
    *param_1 = (*pfVar15 - *pfVar17) * fVar7 + *pfVar15;
  }
  else {
    fVar5 = pfVar13[param_2 * 4 + 1];
    pfVar15 = pfVar13 + param_2 * 4;
    fVar6 = pfVar15[2];
    fVar16 = pfVar15[3];
    *param_1 = *pfVar15;
  }
  param_1[1] = fVar5;
  param_1[2] = fVar6;
  param_1[3] = fVar16;
  if (iVar3 < -1) {
    fVar7 = (float)-iVar3;
    fVar5 = (pfVar13[1] - pfVar13[5]) * fVar7 + pfVar13[1];
    fVar6 = (pfVar13[2] - pfVar13[6]) * fVar7 + pfVar13[2];
    fVar16 = (pfVar13[3] - pfVar13[7]) * fVar7 + pfVar13[3];
    param_1[4] = (*pfVar13 - pfVar13[4]) * fVar7 + *pfVar13;
  }
  else if ((int)uVar18 < iVar3) {
    pfVar15 = pfVar13 + uVar18 * 4 + -4;
    iVar4 = uVar18 - 2;
    fVar7 = (float)(int)((iVar3 - uVar18) + 1);
    fVar5 = (pfVar15[1] - pfVar13[iVar4 * 4 + 1]) * fVar7 + pfVar15[1];
    fVar6 = (pfVar15[2] - pfVar13[iVar4 * 4 + 2]) * fVar7 + pfVar15[2];
    fVar16 = (pfVar15[3] - pfVar13[iVar4 * 4 + 3]) * fVar7 + pfVar15[3];
    param_1[4] = (pfVar13[uVar18 * 4 + -4] - pfVar13[iVar4 * 4]) * fVar7 + *pfVar15;
  }
  else {
    fVar16 = pfVar13[iVar3 * 4 + 3];
    fVar5 = pfVar13[iVar3 * 4 + 1];
    fVar6 = pfVar13[iVar3 * 4 + 2];
    param_1[4] = pfVar13[iVar3 * 4];
  }
  param_1[5] = fVar5;
  param_1[6] = fVar6;
  param_1[7] = fVar16;
  if (iVar1 < -1) {
    fVar7 = (float)-iVar1;
    fVar5 = (pfVar13[1] - pfVar13[5]) * fVar7 + pfVar13[1];
    fVar6 = (pfVar13[2] - pfVar13[6]) * fVar7 + pfVar13[2];
    fVar16 = (pfVar13[3] - pfVar13[7]) * fVar7 + pfVar13[3];
    param_1[8] = (*pfVar13 - pfVar13[4]) * fVar7 + *pfVar13;
  }
  else if ((int)uVar18 < iVar1) {
    pfVar15 = pfVar13 + uVar18 * 4 + -4;
    iVar3 = uVar18 - 2;
    fVar7 = (float)(int)((iVar1 - uVar18) + 1);
    fVar5 = (pfVar15[1] - pfVar13[iVar3 * 4 + 1]) * fVar7 + pfVar15[1];
    fVar6 = (pfVar15[2] - pfVar13[iVar3 * 4 + 2]) * fVar7 + pfVar15[2];
    fVar16 = (pfVar15[3] - pfVar13[iVar3 * 4 + 3]) * fVar7 + pfVar15[3];
    param_1[8] = (pfVar13[uVar18 * 4 + -4] - pfVar13[iVar3 * 4]) * fVar7 + *pfVar15;
  }
  else {
    fVar16 = pfVar13[iVar1 * 4 + 3];
    fVar5 = pfVar13[iVar1 * 4 + 1];
    fVar6 = pfVar13[iVar1 * 4 + 2];
    param_1[8] = pfVar13[iVar1 * 4];
  }
  param_1[9] = fVar5;
  param_1[10] = fVar6;
  param_1[0xb] = fVar16;
  if (iVar2 < -1) {
    fVar5 = *pfVar13;
    fVar6 = pfVar13[4];
    fVar16 = pfVar13[5];
    fVar7 = pfVar13[1];
    fVar8 = pfVar13[6];
    fVar9 = pfVar13[2];
    fVar14 = (float)-iVar2;
    fVar10 = pfVar13[1];
    fVar11 = pfVar13[2];
    fVar12 = *pfVar13;
    param_1[0xf] = (pfVar13[3] - pfVar13[7]) * fVar14 + pfVar13[3];
    param_1[0xc] = (fVar5 - fVar6) * fVar14 + fVar12;
    param_1[0xd] = (fVar7 - fVar16) * fVar14 + fVar10;
    param_1[0xe] = (fVar9 - fVar8) * fVar14 + fVar11;
    return;
  }
  if ((int)uVar18 < iVar2) {
    fVar5 = pfVar13[uVar18 * 4 + -4];
    pfVar15 = pfVar13 + uVar18 * 4 + -4;
    iVar1 = uVar18 - 2;
    fVar6 = pfVar13[iVar1 * 4];
    fVar16 = pfVar15[1];
    fVar7 = pfVar13[iVar1 * 4 + 1];
    fVar8 = pfVar15[2];
    fVar9 = pfVar13[iVar1 * 4 + 2];
    fVar14 = (float)(int)((iVar2 - uVar18) + 1);
    fVar10 = pfVar15[1];
    fVar11 = pfVar15[2];
    fVar12 = *pfVar15;
    param_1[0xf] = (pfVar15[3] - pfVar13[iVar1 * 4 + 3]) * fVar14 + pfVar15[3];
    param_1[0xc] = (fVar5 - fVar6) * fVar14 + fVar12;
    param_1[0xd] = (fVar16 - fVar7) * fVar14 + fVar10;
    param_1[0xe] = (fVar8 - fVar9) * fVar14 + fVar11;
    return;
  }
  fVar5 = pfVar13[iVar2 * 4 + 1];
  fVar16 = pfVar13[iVar2 * 4 + 3];
  fVar6 = pfVar13[iVar2 * 4 + 2];
  param_1[0xc] = pfVar13[iVar2 * 4];
  param_1[0xf] = fVar16;
  param_1[0xd] = fVar5;
  param_1[0xe] = fVar6;
  return;
}


// ==== 0x59d350 FUN_0059d350

undefined4 * FUN_0059d350(undefined4 *param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  undefined1 *puVar2;
  float10 fVar3;
  float10 extraout_ST0;
  undefined1 local_50 [76];
  
  if (*(char *)(in_EAX + 0x18) != '\0') {
    FUN_0059cb90();
    *(undefined1 *)(in_EAX + 0x18) = 0;
  }
  if (*(short *)(in_EAX + 0x1e) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    return param_1;
  }
  fVar3 = (float10)FUN_0059ce10(param_2);
  Float_Truncate((float)fVar3);
  iVar1 = _ftol_nocw();
  if ((*(int *)(in_EAX + 4) == 2) &&
     ((iVar1 < 0 || ((int)(*(ushort *)(in_EAX + 0x1e) - 1) <= iVar1)))) {
    CallNTimes(local_50,0x10,4,FUN_004ad8d0);
    FUN_0059cea0();
    puVar2 = local_50;
  }
  else {
    puVar2 = (undefined1 *)(iVar1 * 0x10 + -0x10 + *(int *)(in_EAX + 0x24));
  }
  FUN_0059cdb0(param_1,(float)((float10)(float)fVar3 - extraout_ST0),puVar2);
  return param_1;
}


// ==== 0x59d430 FUN_0059d430

int __fastcall FUN_0059d430(undefined4 param_1,float *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  
  iVar1 = *(int *)(in_EAX + 0x24);
  fVar2 = *param_2 - *(float *)(param_3 * 0x10 + iVar1);
  iVar5 = param_3 * 0x10 + iVar1;
  fVar4 = param_2[1] - *(float *)(iVar5 + 4);
  iVar8 = param_3 + 1;
  fVar3 = param_2[2] - *(float *)(iVar5 + 8);
  fVar2 = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
  iVar5 = param_3;
  if (iVar8 < (int)(uint)*(ushort *)(in_EAX + 0x1e)) {
    pfVar7 = (float *)(iVar8 * 0x10 + iVar1);
    do {
      iVar6 = iVar8;
      fVar3 = SQRT((*param_2 - *pfVar7) * (*param_2 - *pfVar7) +
                   (param_2[1] - pfVar7[1]) * (param_2[1] - pfVar7[1]) +
                   (param_2[2] - pfVar7[2]) * (param_2[2] - pfVar7[2]));
      if (fVar2 <= fVar3) break;
      pfVar7 = pfVar7 + 4;
      iVar8 = iVar6 + 1;
      iVar5 = iVar6;
      fVar2 = fVar3;
    } while (iVar6 + 1 < (int)(uint)*(ushort *)(in_EAX + 0x1e));
  }
  param_3 = param_3 + -1;
  if (-1 < param_3) {
    pfVar7 = (float *)(param_3 * 0x10 + iVar1);
    iVar8 = iVar5;
    do {
      iVar5 = param_3;
      fVar3 = SQRT((*param_2 - *pfVar7) * (*param_2 - *pfVar7) +
                   (param_2[1] - pfVar7[1]) * (param_2[1] - pfVar7[1]) +
                   (param_2[2] - pfVar7[2]) * (param_2[2] - pfVar7[2]));
      if (fVar2 <= fVar3) {
        return iVar8;
      }
      pfVar7 = pfVar7 + -4;
      param_3 = iVar5 + -1;
      iVar8 = iVar5;
      fVar2 = fVar3;
    } while (-1 < iVar5 + -1);
  }
  return iVar5;
}


// ==== 0x59d540 FUN_0059d540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0059d540(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  float10 fVar5;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_48;
  int local_44;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  if (*(char *)(in_EAX + 0x18) != '\0') {
    FUN_0059cb90();
    *(undefined1 *)(in_EAX + 0x18) = 0;
  }
  if (*(short *)(in_EAX + 0x1e) != 0) {
    local_50 = param_2;
    local_60 = 1.0;
    local_58 = 0.0;
    local_48 = 0.0;
    local_44 = 0x3e6;
    do {
      FUN_0059d350(&local_30,local_50,0);
      fVar4 = local_28;
      fVar3 = local_2c;
      fVar1 = local_30;
      FUN_0059d350(&local_20,local_50,1);
      fVar2 = SQRT(local_20 * local_20 + local_1c * local_1c + local_18 * local_18);
      if (((fVar2 == 0.0) ||
          (fVar1 = ((*param_1 - fVar1) * local_20 +
                   (param_1[1] - fVar3) * local_1c + (param_1[2] - fVar4) * local_18) / fVar2,
          ABS(fVar1) < param_3)) ||
         ((local_58 != 0.0 && (fVar2 = -((fVar1 - local_48) / local_58), fVar2 == 0.0)))) {
        return (float10)local_50;
      }
      local_5c = fVar1 / fVar2;
      if (fVar1 / fVar2 <= -local_60) {
        local_5c = -local_60;
      }
      if (local_60 < local_5c) {
        local_5c = local_60;
      }
      fVar5 = (float10)FUN_0059ce10(local_5c + local_50);
      local_50 = (float)fVar5;
      if (local_5c * local_58 < 0.0) {
        local_60 = local_60 * _K_HALF;
      }
      local_58 = local_5c;
      local_44 = local_44 + -1;
      local_48 = fVar1;
    } while (local_44 != 0);
    return (float10)local_50;
  }
  return (float10)0.0;
}


// ==== 0x59d740 FUN_0059d740

float10 FUN_0059d740(undefined4 param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 in_EAX;
  float *unaff_ESI;
  float10 fVar9;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar9 = (float10)FUN_0059d540(unaff_ESI,param_1,param_3,in_EAX);
  fVar1 = (float)fVar9;
  FUN_0059d350(&local_20,fVar1,0);
  fVar8 = local_18;
  fVar7 = local_1c;
  fVar6 = local_20;
  FUN_0059d350(&local_20,fVar1,1);
  fVar4 = local_18 * 0.0 - local_1c;
  fVar5 = local_20 - local_18 * 0.0;
  fVar3 = local_1c * 0.0;
  fVar2 = local_20 * 0.0;
  local_20 = *unaff_ESI - fVar6;
  local_1c = unaff_ESI[1] - fVar7;
  local_18 = unaff_ESI[2] - fVar8;
  bNormalize3();
  if (param_2 != (float *)0x0) {
    *param_2 = fVar1;
  }
  return (float10)local_20 * (float10)fVar4 +
         (float10)fVar5 * (float10)local_1c + (float10)(fVar3 - fVar2) * (float10)local_18;
}


// ==== 0x59d830 FUN_0059d830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0059d830(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int unaff_EDI;
  float local_44;
  float local_40;
  float local_38;
  float local_34;
  undefined1 local_30 [12];
  float local_24;
  undefined1 local_20 [12];
  float local_14;
  
  local_40 = *(float *)(unaff_EDI + 0x10);
  local_44 = *(float *)(unaff_EDI + 0xc);
  if (*(int *)(unaff_EDI + 4) == 0) {
    local_44 = local_44 - 0.001;
  }
  else if (*(int *)(unaff_EDI + 4) == 2) {
    local_40 = (float)(int)-(uint)*(ushort *)(unaff_EDI + 0x1e);
    local_44 = (float)*(ushort *)(unaff_EDI + 0x1e);
    local_44 = local_44 + local_44;
  }
  if (local_40 < local_44) {
    FUN_0059d350(local_30,local_40,0);
    local_38 = local_24;
    FUN_0059d350(local_20,local_44,0);
    local_34 = local_14;
    if ((local_14 != local_24) && (param_1 < local_24 == (param_1 == local_24))) {
      if (local_14 <= param_1) {
        return (float10)local_44;
      }
      iVar3 = 0;
      do {
        fVar1 = (param_1 - local_38) / (local_34 - local_38);
        fVar1 = fVar1 * local_44 + (_K_ONE - fVar1) * local_40;
        FUN_0059d350(local_30,fVar1,0);
        iVar3 = iVar3 + 1;
        fVar2 = ABS(param_1 - local_24);
        if (fVar2 < 0.001 != (fVar2 == 0.001)) break;
        if (param_1 < local_24) {
          local_34 = local_24;
          local_44 = fVar1;
        }
        if (local_24 < param_1) {
          local_38 = local_24;
          local_40 = fVar1;
        }
      } while (iVar3 < 0x28);
      if (iVar3 < DAT_0073444c) {
        iVar3 = DAT_0073444c;
      }
      DAT_0073444c = iVar3;
      if (fVar2 < _DAT_00734450) {
        fVar2 = _DAT_00734450;
      }
      _DAT_00734450 = fVar2;
      return (float10)fVar1;
    }
  }
  return (float10)local_40;
}


// ==== 0x59d9f0 FUN_0059d9f0

void FUN_0059d9f0(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  int in_EAX;
  undefined4 *puVar3;
  float local_78;
  int local_74;
  int local_70;
  int local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_28;
  undefined4 local_18;
  
  local_78 = 0.0;
  local_74 = 0;
  if (*(short *)(in_EAX + 0x1e) != 0) {
    local_70 = 0;
    do {
      uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x24) + local_70);
      puVar3 = (undefined4 *)(*(int *)(in_EAX + 0x24) + local_70);
      local_18 = puVar3[2];
      puVar3[3] = local_78;
      *puVar3 = uVar1;
      puVar3[2] = local_18;
      puVar3[1] = puVar3[1];
      *(undefined1 *)(in_EAX + 0x18) = 1;
      fVar2 = (float)local_74;
      if (fVar2 < *(float *)(in_EAX + 0xc)) {
        FUN_0059d350(&local_50,fVar2,0);
        local_60 = local_50;
        local_5c = local_4c;
        local_58 = local_48;
        local_68 = 1;
        if (0 < param_1) {
          do {
            FUN_0059d350(&local_40,(float)local_68 / (float)param_1 + fVar2,0);
            local_28 = local_38;
            local_68 = local_68 + 1;
            local_78 = SQRT((local_40 - local_60) * (local_40 - local_60) +
                            (local_3c - local_5c) * (local_3c - local_5c) +
                            (local_38 - local_58) * (local_38 - local_58)) + local_78;
            local_60 = local_40;
            local_5c = local_3c;
            local_58 = local_28;
          } while (local_68 <= param_1);
        }
      }
      local_74 = local_74 + 1;
      local_70 = local_70 + 0x10;
    } while (local_74 < (int)(uint)*(ushort *)(in_EAX + 0x1e));
  }
  *(float *)(in_EAX + 0x14) = local_78;
  FUN_0059cb90();
  *(undefined1 *)(in_EAX + 0x18) = 0;
  return;
}


// ==== 0x59db60 Spline::Finalize

/* [canon] assets med (Ghidra make FUN_0059db60) docs/re/assets.md */

int Spline__Finalize(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  uint3 uVar4;
  uint3 extraout_var;
  uint uVar3;
  float *pfVar5;
  uint uVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  
  uVar4 = (uint3)((uint)in_EAX >> 8);
  uVar7 = 0;
  if (*(char *)(in_EAX + 0x18) != '\0') {
    FUN_0059cb90();
    *(undefined1 *)(in_EAX + 0x18) = 0;
    uVar4 = extraout_var;
  }
  uVar6 = *(ushort *)(in_EAX + 0x1e) + 3;
  if (2 < uVar6) {
    uVar3 = *(ushort *)(in_EAX + 0x1e) + 1;
    iVar8 = 2;
    if (3 < uVar3) {
      iVar9 = 5;
      pfVar5 = (float *)(*(int *)(in_EAX + 0x20) + 0x14);
      do {
        if ((pfVar5[4] - *pfVar5) * (*pfVar5 - pfVar5[-4]) +
            (pfVar5[3] - pfVar5[-1]) * (pfVar5[-1] - pfVar5[-5]) +
            (pfVar5[1] - pfVar5[-3]) * (pfVar5[5] - pfVar5[1]) < 0.0) {
          uVar7 = 1;
        }
        fVar1 = pfVar5[9] - pfVar5[5];
        if ((pfVar5[8] - pfVar5[4]) * (pfVar5[4] - *pfVar5) +
            (pfVar5[7] - pfVar5[3]) * (pfVar5[3] - pfVar5[-1]) + (pfVar5[5] - pfVar5[1]) * fVar1 <
            0.0) {
          uVar7 = 1;
        }
        if ((pfVar5[0xc] - pfVar5[8]) * (pfVar5[8] - pfVar5[4]) +
            (pfVar5[0xb] - pfVar5[7]) * (pfVar5[7] - pfVar5[3]) + fVar1 * (pfVar5[0xd] - pfVar5[9])
            < 0.0) {
          uVar7 = 1;
        }
        fVar2 = (pfVar5[0x10] - pfVar5[0xc]) * (pfVar5[0xc] - pfVar5[8]) +
                (pfVar5[0xf] - pfVar5[0xb]) * (pfVar5[0xb] - pfVar5[7]) +
                (pfVar5[0x11] - pfVar5[0xd]) * (pfVar5[0xd] - pfVar5[9]);
        uVar3 = CONCAT22((short)((uint)fVar1 >> 0x10),
                         (ushort)(fVar2 < 0.0) << 8 | (ushort)NAN(fVar2) << 10 |
                         (ushort)(fVar2 == 0.0) << 0xe);
        if (fVar2 < 0.0) {
          uVar7 = 1;
        }
        iVar9 = iVar9 + 4;
        iVar8 = iVar8 + 4;
        pfVar5 = pfVar5 + 0x10;
      } while (iVar9 < (int)uVar6);
    }
    if (iVar8 < (int)uVar6) {
      uVar3 = iVar8 * 0x10;
      pfVar5 = (float *)((uVar3 - 0xc) + *(int *)(in_EAX + 0x20));
      iVar8 = uVar6 - iVar8;
      do {
        fVar1 = (pfVar5[4] - *pfVar5) * (*pfVar5 - pfVar5[-4]) +
                (pfVar5[3] - pfVar5[-1]) * (pfVar5[-1] - pfVar5[-5]) +
                (pfVar5[5] - pfVar5[1]) * (pfVar5[1] - pfVar5[-3]);
        uVar3 = CONCAT22((short)(uVar3 >> 0x10),
                         (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                         (ushort)(fVar1 == 0.0) << 0xe);
        if (fVar1 < 0.0) {
          uVar7 = 1;
        }
        pfVar5 = pfVar5 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    return CONCAT31((int3)(uVar3 >> 8),uVar7);
  }
  return (uint)uVar4 << 8;
}


// ==== 0x59dd90 SplineSet::Loader

/* [canon] assets high (Hopper sub_59dd90 + Ghidra export FUN_0059dd90: H+G agree) docs/re/assets.md
    */

undefined4 SplineSet__Loader(int *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  
  if (*param_1 != -0x7ffc5000) {
    return 0;
  }
  piVar2 = param_1 + 2;
  if (piVar2 < (int *)((int)param_1 + param_1[1] + 8)) {
    do {
      uVar1 = (int)piVar2 + piVar2[3] + 0x27 & 0xfffffff0;
      uVar3 = (int)piVar2 + 0x1fU & 0xfffffff0;
      *(uint *)(uVar3 + 0x20) = uVar1;
      *(uint *)(uVar3 + 0x24) = uVar1 + 0x10;
      *(undefined1 *)(uVar3 + 0x18) = 0;
      *(undefined4 *)(uVar3 + 0x28) = 0;
      if (*(int *)(uVar3 + 8) == 0) {
        *(undefined **)(uVar3 + 0x28) = &DAT_007376b0;
      }
      Spline__InitBasis();
      HudWidget__RegisterObject(uVar3);
      Spline__Finalize();
      piVar2 = (int *)((int)piVar2 + piVar2[1] + 8);
    } while (piVar2 < (int *)((int)param_1 + param_1[1] + 8));
  }
  return 1;
}


// ==== 0x59de20 SplineSet::Unloader

/* [canon] assets high (Hopper sub_59de20 + Ghidra export FUN_0059de20: H+G agree) docs/re/assets.md
    */

undefined4 SplineSet__Unloader(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  
  if (*param_1 != -0x7ffc5000) {
    return 0;
  }
  piVar6 = param_1 + 2;
  if (piVar6 < (int *)(param_1[1] + 8 + (int)param_1)) {
    piVar3 = (int *)NullUpdate_ret();
    iVar4 = DAT_007349b4;
    do {
      for (piVar1 = DAT_0073769c; piVar1 != piVar3; piVar1 = (int *)*piVar1) {
        if (*(int *)((int)piVar6 + 0x1fU & 0xfffffff0) == *(int *)piVar1[2]) {
          iVar5 = *piVar1;
          piVar2 = (int *)piVar1[1];
          *piVar2 = iVar5;
          *(int **)(iVar5 + 4) = piVar2;
          iVar5 = *(int *)(iVar4 + 0x18);
          *piVar1 = *(int *)(iVar4 + 0x10);
          *(int **)(iVar4 + 0x10) = piVar1;
          iVar5 = iVar5 + -1;
          bVar7 = DAT_007349b8 != 0;
          *(int *)(iVar4 + 0x18) = iVar5;
          if (bVar7) {
            if (iVar5 == 0) {
              SlotPool__Destroy();
              iVar4 = 0;
              DAT_007349b4 = 0;
            }
            else {
              DAT_007349b8 = 1;
            }
          }
          break;
        }
      }
      piVar6 = (int *)((int)piVar6 + piVar6[1] + 8);
    } while (piVar6 < (int *)(param_1[1] + 8 + (int)param_1));
  }
  return 1;
}


// ==== 0x59def0 FUN_0059def0

int * FUN_0059def0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = DAT_0073769c;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return (int *)0x0;
    }
    if (unaff_EDI == *(int *)puVar1[2]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return (int *)puVar1[2];
}


// ==== 0x59df20 FUN_0059df20

undefined4 * __thiscall FUN_0059df20(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  
  switch(*param_1) {
  case 0:
    *(undefined1 *)param_1[1] = *(undefined1 *)param_2;
    return param_2 + 1;
  case 1:
    *(undefined2 *)param_1[1] = *(undefined2 *)param_2;
    return param_2 + 1;
  case 2:
  case 3:
    *(undefined4 *)param_1[1] = *param_2;
    return param_2 + 1;
  case 4:
    (*(code *)param_1[1])(0,*param_2);
    return param_2 + 1;
  case 5:
    (*(code *)param_1[1])(0,*param_2);
    return param_2 + 1;
  case 6:
    piVar2 = (int *)param_1[1];
    if (*piVar2 != 7) {
      do {
        param_2 = (undefined4 *)FUN_0059df20(param_2);
        piVar1 = piVar2 + 3;
        piVar2 = piVar2 + 3;
      } while (*piVar1 != 7);
      return param_2;
    }
  }
  return param_2;
}


// ==== 0x59dfe0 FUN_0059dfe0

void FUN_0059dfe0(void)

{
  undefined1 *puVar1;
  void *pvVar2;
  
  puVar1 = _malloc(0xc);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 1;
    pvVar2 = _malloc(0x400);
    *(void **)(puVar1 + 4) = pvVar2;
    *(undefined4 *)(puVar1 + 8) = 0;
    DAT_00734440 = puVar1;
    return;
  }
  DAT_00734440 = (undefined1 *)0x0;
  return;
}


// ==== 0x59e020 FUN_0059e020

void FUN_0059e020(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_EDI + 8);
  if ((0 < iVar2) && (iVar2 < 0xb)) {
    piVar4 = *(int **)(&DAT_006ef214 + iVar2 * 4);
    uVar3 = *(undefined4 *)(unaff_EDI + 4);
    iVar2 = *piVar4;
    while (iVar2 != 7) {
      uVar3 = FUN_0059df20(uVar3);
      piVar1 = piVar4 + 3;
      piVar4 = piVar4 + 3;
      iVar2 = *piVar1;
    }
  }
  *(undefined4 *)(unaff_EDI + 8) = 0;
  return;
}


// ==== 0x59e060 FUN_0059e060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0059e060(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = _DAT_0078ee24 & 1;
  *param_1 = &PTR_FUN_006b88c8;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  if (uVar2 == 0) {
    _DAT_0078ee24 = _DAT_0078ee24 | 1;
    _DAT_00706eec = -1;
    pcVar3 = "NISMO_PRESET";
    uVar2 = 0x4e;
    do {
      pbVar1 = (byte *)(pcVar3 + 1);
      _DAT_00706eec = _DAT_00706eec * 0x21 + uVar2;
      pcVar3 = pcVar3 + 1;
      uVar2 = (uint)*pbVar1;
    } while (*pbVar1 != 0);
    uVar2 = 0x50;
    _DAT_00706efc = 0x6d6d6967;
    _DAT_00706f00 = 0x61707065;
    _DAT_00706f04 = &DAT_006f6c62;
    _DAT_00706f08 = 0;
    _DAT_00706f0c = 0;
    _DAT_00706f10 = 0;
    _DAT_00706f14 = 0;
    _DAT_00706f18 = 0;
    _DAT_00706f20 = -1;
    _DAT_00706ef0 = 0;
    _DAT_00706ef4 = 0;
    DAT_00706ef8 = 0;
    DAT_00706ef9 = 1;
    _DAT_00706f1c = 6;
    pcVar3 = "PETEY_PABLO";
    do {
      _DAT_00706f20 = _DAT_00706f20 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar3 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar3 = pcVar3 + 1;
    } while (*pbVar1 != 0);
    uVar2 = 0x52;
    DAT_00706f30 = 'g';
    DAT_00706f30_1._0_1_ = 'o';
    DAT_00706f30_1._1_1_ = 't';
    DAT_00706f30_1._2_1_ = 'c';
    DAT_00706f34 = 'h';
    DAT_00706f34_1._0_1_ = 'a';
    DAT_00706f34_1._1_1_ = 'r';
    DAT_00706f34_1._2_1_ = 'o';
    DAT_00706f38 = 'b';
    DAT_00706f38_1._0_1_ = 'z';
    DAT_00706f38_1._1_1_ = 'o';
    DAT_00706f38_1._2_1_ = 'm';
    DAT_00706f3c = 'b';
    DAT_00706f3c_1._0_1_ = 'i';
    DAT_00706f3c_1._1_1_ = 'e';
    DAT_00706f3c_1._2_1_ = '\0';
    _DAT_00706f40 = 0;
    _DAT_00706f44 = 0;
    _DAT_00706f48 = 0;
    _DAT_00706f4c = 0;
    _DAT_00706f54 = -1;
    _DAT_00706f24 = 0;
    _DAT_00706f28 = 0;
    DAT_00706f2c = 0;
    DAT_00706f2d = 1;
    _DAT_00706f50 = 6;
    pcVar3 = "ROBZOMBIE_PRESET";
    do {
      _DAT_00706f54 = _DAT_00706f54 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar3 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar3 = pcVar3 + 1;
    } while (*pbVar1 != 0);
    uVar2 = 0x4d;
    DAT_00706f64 = 'h';
    DAT_00706f64_1._0_1_ = 'a';
    DAT_00706f64_1._1_1_ = 'v';
    DAT_00706f64_1._2_1_ = 'y';
    DAT_00706f68 = 'a';
    DAT_00706f68_1._0_1_ = 'm';
    DAT_00706f68_1._1_1_ = 'y';
    DAT_00706f68_1._2_1_ = 's';
    DAT_00706f6c = 't';
    DAT_00706f6c_1._0_1_ = 'i';
    DAT_00706f6c_1._1_1_ = 'k';
    DAT_00706f6c_1._2_1_ = 'a';
    DAT_00706f70 = 'l';
    DAT_00706f70_1 = '\0';
    _DAT_00706f72 = 0;
    _DAT_00706f76 = 0;
    _DAT_00706f7a = 0;
    _DAT_00706f7e = 0;
    _DAT_00706f82 = 0;
    _DAT_00706f88 = -1;
    _DAT_00706f58 = 0;
    _DAT_00706f5c = 0;
    DAT_00706f60 = 0;
    DAT_00706f61 = 1;
    _DAT_00706f84 = 6;
    pcVar3 = "MYSTIKAL_PRESET";
    do {
      _DAT_00706f88 = _DAT_00706f88 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar3 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar3 = pcVar3 + 1;
    } while (*pbVar1 != 0);
    DAT_00706f98 = 'n';
    DAT_00706f98_1._0_1_ = 'e';
    DAT_00706f98_1._1_1_ = 'e';
    DAT_00706f98_1._2_1_ = 'd';
    DAT_00706f9c = 'm';
    DAT_00706f9c_1._0_1_ = 'y';
    DAT_00706f9c_1._1_1_ = 'l';
    DAT_00706f9c_1._2_1_ = 'o';
    DAT_00706fa0 = 's';
    DAT_00706fa0_1._0_1_ = 't';
    DAT_00706fa0_1._1_1_ = 'p';
    DAT_00706fa0_1._2_1_ = 'r';
    DAT_00706fa4 = 'o';
    DAT_00706fa4_1._0_1_ = 'p';
    DAT_00706fa4_1._1_1_ = 'h';
    DAT_00706fa4_1._2_1_ = 'e';
    DAT_00706fa8 = 't';
    DAT_00706fa8_1 = 's';
    DAT_00706faa = 0;
    _DAT_00706fab = 0;
    _DAT_00706faf = 0;
    _DAT_00706fb3 = 0;
    DAT_00706fb7 = 0;
    _DAT_00706fbc = -1;
    _DAT_00706f8c = 0;
    _DAT_00706f90 = 0;
    DAT_00706f94 = 0;
    DAT_00706f95 = 1;
    _DAT_00706fb8 = 6;
    pcVar3 = "LOSTPRO_PRESET";
    uVar2 = 0x4c;
    do {
      pbVar1 = (byte *)(pcVar3 + 1);
      _DAT_00706fbc = _DAT_00706fbc * 0x21 + uVar2;
      pcVar3 = pcVar3 + 1;
      uVar2 = (uint)*pbVar1;
    } while (*pbVar1 != 0);
    _DAT_00706fc0 = 0;
    _DAT_00706fc4 = 0;
    DAT_00706fc8 = 0;
    DAT_00706fc9 = 1;
  }
  param_1[3] = s_119focus_00706918;
  param_1[4] = 0x21;
  return param_1;
}


// ==== 0x59e360 FUN_0059e360

undefined4 * __thiscall FUN_0059e360(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006b88c8;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x59e380 FUN_0059e380

void __fastcall FUN_0059e380(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_2 + 0x10) != 0) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(param_2 + 0xc) + iVar2;
      if (*(char *)(iVar1 + 0x31) == '\0') {
        *(undefined1 *)(iVar1 + 0x30) = 0;
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x34;
    } while (uVar3 < *(uint *)(param_2 + 0x10));
  }
  return;
}


// ==== 0x59e3b0 FUN_0059e3b0

void FUN_0059e3b0(undefined1 param_1)

{
  int in_EAX;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  if (*(char *)(in_EAX + 4) != '\0') {
    *(undefined1 *)((*(uint *)(in_EAX + 0x34) & 0x1f) + 0x14 + in_EAX) = param_1;
    *(int *)(in_EAX + 0x34) = *(int *)(in_EAX + 0x34) + 1;
    _param_1 = 0;
    if (*(int *)(in_EAX + 0x10) != 0) {
      local_4 = 0;
      do {
        pcVar2 = (char *)(*(int *)(in_EAX + 0xc) + local_4);
        uVar1 = 0;
        if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
LAB_0059e40e:
          iVar3 = 0;
          if (0 < (int)uVar1) {
            iVar4 = (*(int *)(in_EAX + 0x34) - uVar1) - (int)pcVar2;
            do {
              if (*pcVar2 != *(char *)(((uint)(pcVar2 + iVar4) & 0x1f) + 0x14 + in_EAX))
              goto LAB_0059e43d;
              iVar3 = iVar3 + 1;
              pcVar2 = pcVar2 + 1;
            } while (iVar3 < (int)uVar1);
          }
          in_EAX = FUN_0059e460();
        }
        else {
          do {
            iVar3 = uVar1 + 1;
            uVar1 = uVar1 + 1;
          } while (pcVar2[iVar3] != '\0');
          if (uVar1 <= *(uint *)(in_EAX + 0x34)) goto LAB_0059e40e;
        }
LAB_0059e43d:
        _param_1 = _param_1 + 1;
        local_4 = local_4 + 0x34;
      } while (_param_1 < *(uint *)(in_EAX + 0x10));
    }
  }
  return;
}


// ==== 0x59e460 FUN_0059e460

void __fastcall FUN_0059e460(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  
  param_1 = param_1 * 0x34;
  iVar1 = *(int *)(*(int *)(in_EAX + 0xc) + 0x28 + param_1);
  if ((iVar1 != 0) && (uVar3 = 0, *(int *)(in_EAX + 0x10) != 0)) {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(in_EAX + 0xc) + 0x28 + iVar2) == iVar1) {
        *(undefined1 *)(*(int *)(in_EAX + 0xc) + iVar2 + 0x30) = 0;
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x34;
    } while (uVar3 < *(uint *)(in_EAX + 0x10));
  }
  *(undefined1 *)(*(int *)(in_EAX + 0xc) + 0x30 + param_1) = 1;
  iVar1 = *(int *)(in_EAX + 0xc) + param_1;
  if (*(int *)(*(int *)(in_EAX + 0xc) + 0x20 + param_1) == 5) {
    if (*(int *)(iVar1 + 0x24) == 0) {
      DAT_00734424 = 1;
    }
    else if (*(int *)(iVar1 + 0x24) == 3) {
      *(undefined1 *)(in_EAX + 5) = 1;
      *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(iVar1 + 0x2c);
      *(undefined4 *)(in_EAX + 0x34) = 0;
      DAT_00735fa0 = (uint)(DAT_00735fa0 == 0);
      return;
    }
  }
  *(undefined1 *)(in_EAX + 5) = 1;
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(in_EAX + 0x34) = 0;
  return;
}


// ==== 0x59e510 FUN_0059e510

uint __fastcall FUN_0059e510(int param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == in_EAX) goto LAB_0059e545;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_0059e545:
  uVar2 = *(uint *)(iVar3 + 0x74);
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      if ((uVar2 & 8) == 0) {
        if ((uVar2 & 4) == 0) {
          return uVar2 & 0xffffff00;
        }
        iVar3 = 4;
      }
      else {
        iVar3 = 8;
      }
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 1;
  }
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    piVar4 = (int *)(*(int *)(param_1 + 0xc) + 0x24);
    do {
      if ((piVar4[-1] == 4) && (*piVar4 == iVar3)) {
        return CONCAT31((int3)(uVar2 * 0x34 >> 8),
                        *(undefined1 *)(uVar2 * 0x34 + 0x30 + *(int *)(param_1 + 0xc)));
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 0xd;
    } while (uVar2 < *(uint *)(param_1 + 0x10));
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x59e5c0 EasterEggs::IsPartUnlocked

/* [canon] car low (ghidra+hopper) docs/re/tuning.md */

uint __fastcall EasterEggs__IsPartUnlocked(int param_1)

{
  uint uVar1;
  int *piVar2;
  int unaff_EBX;
  
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    piVar2 = (int *)(*(int *)(param_1 + 0xc) + 0x24);
    do {
      if ((piVar2[-1] == 1) && (*piVar2 == unaff_EBX)) {
        return CONCAT31((int3)(uVar1 * 0x34 >> 8),
                        *(undefined1 *)(uVar1 * 0x34 + 0x30 + *(int *)(param_1 + 0xc)));
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 0xd;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x59e5f0 FUN_0059e5f0

uint __fastcall FUN_0059e5f0(int param_1)

{
  uint uVar1;
  int *piVar2;
  int unaff_EBX;
  
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    piVar2 = (int *)(*(int *)(param_1 + 0xc) + 0x24);
    do {
      if ((piVar2[-1] == 2) && (*piVar2 == unaff_EBX)) {
        return CONCAT31((int3)(uVar1 * 0x34 >> 8),
                        *(undefined1 *)(uVar1 * 0x34 + 0x30 + *(int *)(param_1 + 0xc)));
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 0xd;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x59e620 Table3A000::Loader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_59e620 + Ghidra make FUN_0059e620: H+G agree) docs/re/assets.md
    */

undefined4 Table3A000__Loader(int *param_1)

{
  if (*param_1 == 0x3a000) {
    _DAT_00737650 = param_1 + 3;
    _DAT_00737654 = (int)(short)param_1[2];
    _DAT_00737658 = (int)*(short *)((int)param_1 + 10);
    return 1;
  }
  return 0;
}


// ==== 0x59e660 Table3A000::Unloader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Ghidra make FUN_0059e660 (Hopper export lacks it)) docs/re/assets.md */

bool Table3A000__Unloader(int *param_1)

{
  if (*param_1 == 0x3a000) {
    _DAT_00737650 = 0;
    _DAT_00737654 = 0;
    _DAT_00737658 = 0;
  }
  return *param_1 == 0x3a000;
}


// ==== 0x59e690 FUN_0059e690

void __thiscall FUN_0059e690(int *param_1,int param_2)

{
  float fVar1;
  
  if (param_2 == -0x6edfbf62) {
    fVar1 = (float)param_1[7];
    param_1[7] = (int)(fVar1 - (float)param_1[9]);
    if (fVar1 - (float)param_1[9] < (float)param_1[6]) {
      param_1[7] = param_1[6];
    }
  }
  else if ((param_2 == -0x4a68e40f) &&
          (fVar1 = (float)param_1[7], param_1[7] = (int)((float)param_1[9] + fVar1),
          (float)param_1[5] < (float)param_1[9] + fVar1)) {
    param_1[7] = param_1[5];
    (**(code **)(*param_1 + 0x10))();
    return;
  }
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== 0x59e6f0 FUN_0059e6f0

void __thiscall FUN_0059e6f0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int local_4;
  
  piVar1 = param_2;
  if (*param_2 != 0) {
    *(int *)(param_1 + 4) = *param_2;
  }
  local_4 = param_1;
  if (param_2[1] != 0) {
    uVar2 = FEng__HashName();
    if (*(int *)(param_1 + 4) == 0) {
LAB_0059e735:
      if (DAT_0073578c != 0) {
        iVar3 = FUN_004ef050(uVar2);
        if (iVar3 != 0) goto LAB_0059e74d;
      }
LAB_0059e753:
      iVar3 = 0;
    }
    else {
      iVar3 = FEngFindPackage();
      if (iVar3 == 0) goto LAB_0059e735;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_0059e735;
LAB_0059e74d:
      if (*(int *)(iVar3 + 0x18) != 1) goto LAB_0059e753;
    }
    *(int *)(param_1 + 0xc) = iVar3;
  }
  if (piVar1[1] != 0) {
    uVar2 = FEng__HashName();
    if (*(int *)(param_1 + 4) == 0) {
LAB_0059e785:
      if (DAT_0073578c != 0) {
        iVar3 = FUN_004ef050(uVar2);
        if (iVar3 != 0) goto LAB_0059e79d;
      }
LAB_0059e7a3:
      iVar3 = 0;
    }
    else {
      iVar3 = FEngFindPackage();
      if (iVar3 == 0) goto LAB_0059e785;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_0059e785;
LAB_0059e79d:
      if (*(int *)(iVar3 + 0x18) != 1) goto LAB_0059e7a3;
    }
    *(int *)(param_1 + 8) = iVar3;
  }
  if (piVar1[3] == 0) goto LAB_0059e7f8;
  uVar2 = FEng__HashName();
  if (*(int *)(param_1 + 4) == 0) {
LAB_0059e7d5:
    if (DAT_0073578c != 0) {
      iVar3 = FUN_004ef050(uVar2);
      if (iVar3 != 0) goto LAB_0059e7ed;
    }
LAB_0059e7f3:
    iVar3 = 0;
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0059e7d5;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0059e7d5;
LAB_0059e7ed:
    if (*(int *)(iVar3 + 0x18) != 2) goto LAB_0059e7f3;
  }
  *(int *)(param_1 + 0x10) = iVar3;
LAB_0059e7f8:
  *(int *)(param_1 + 0x14) = piVar1[5];
  *(int *)(param_1 + 0x18) = piVar1[4];
  iVar3 = piVar1[6];
  *(int *)(param_1 + 0x1c) = iVar3;
  *(int *)(param_1 + 0x20) = iVar3;
  *(int *)(param_1 + 0x24) = piVar1[7];
  *(int *)(param_1 + 0x2c) = piVar1[8];
  FUN_004f7350(&param_2,&local_4);
  *(float *)(param_1 + 0x28) =
       (float)param_2 - (*(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x2c));
  return;
}


// ==== 0x59e850 FUN_0059e850

void __thiscall FUN_0059e850(int param_1,int *param_2)

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
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687528;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*param_2 != 0) {
    ExceptionList = &local_c;
    *(int *)(param_1 + 4) = *param_2;
  }
  if (param_2[1] != 0) {
    uVar5 = FEng__HashName();
    if (((((*(int *)(param_1 + 4) == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
         (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
        ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
       (*(int *)(iVar6 + 0x18) != 1)) {
      iVar6 = 0;
    }
    *(int *)(param_1 + 8) = iVar6;
  }
  if (param_2[3] != 0) {
    uVar5 = FEng__HashName();
    if (((((*(int *)(param_1 + 4) == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
         (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
        ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
       (*(int *)(iVar6 + 0x18) != 2)) {
      iVar6 = 0;
    }
    *(int *)(param_1 + 0x10) = iVar6;
  }
  iVar6 = param_2[4];
  iVar7 = 0;
  *(int *)(param_1 + 0x38) = iVar6;
  if (0 < iVar6) {
    do {
      iVar7 = iVar7 + 1;
      bSPrintf_regdst(0x20,&DAT_006c3eb4,param_2[2],iVar7);
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
      if (*(int *)(param_1 + 4) == 0) {
LAB_0059ea25:
        if (((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar6), iVar6 == 0)) ||
           (*(int *)(iVar6 + 0x18) != 1)) goto LAB_0059ea4f;
      }
      else {
        iVar8 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_0059e9df:
          if (iVar8 != 0) {
            local_4 = 0;
            FUN_004ffb00(iVar8);
            local_4 = 0xffffffff;
          }
          goto LAB_0059ea25;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar8 = FUN_004fd1e0(iVar2 + 0xdc), iVar8 == 0 &&
              (iVar8 = FUN_004fd1e0(iVar2 + 0xec), iVar8 == 0)))) goto LAB_0059ea25;
          goto LAB_0059e9df;
        }
LAB_0059ea4f:
        iVar6 = 0;
      }
      piVar9 = _malloc(0xc);
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9[2] = iVar6;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x34);
      *puVar3 = piVar9;
      *(int **)(param_1 + 0x34) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1 + 0x30;
    } while (iVar7 < *(int *)(param_1 + 0x38));
  }
  *(int *)(param_1 + 0x14) = param_2[6];
  *(int *)(param_1 + 0x18) = param_2[5];
  iVar6 = param_2[7];
  *(int *)(param_1 + 0x1c) = iVar6;
  *(int *)(param_1 + 0x20) = iVar6;
  *(int *)(param_1 + 0x24) = param_2[8];
  ExceptionList = local_c;
  return;
}


// ==== 0x59eac0 FUN_0059eac0

void __thiscall FUN_0059eac0(int param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int local_48;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687510;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*param_2 != 0) {
    ExceptionList = &local_c;
    *(int *)(param_1 + 4) = *param_2;
  }
  if (param_2[3] != 0) {
    uVar6 = FEng__HashName();
    if (((((*(int *)(param_1 + 4) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
         (iVar7 = FUN_004ffb70(), iVar7 == 0)) &&
        ((DAT_0073578c == 0 || (iVar7 = FUN_004ef050(uVar6), iVar7 == 0)))) ||
       (*(int *)(iVar7 + 0x18) != 2)) {
      iVar7 = 0;
    }
    *(int *)(param_1 + 0x10) = iVar7;
  }
  if (param_2[4] != 0) {
    uVar6 = FEng__HashName();
    if (((((*(int *)(param_1 + 4) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
         (iVar7 = FUN_004ffb70(), iVar7 == 0)) &&
        ((DAT_0073578c == 0 || (iVar7 = FUN_004ef050(uVar6), iVar7 == 0)))) ||
       (*(int *)(iVar7 + 0x18) != 1)) {
      iVar7 = 0;
    }
    *(int *)(param_1 + 0x48) = iVar7;
  }
  iVar7 = param_2[5];
  *(int *)(param_1 + 0x38) = iVar7;
  if (0 < iVar7) {
    local_48 = 1;
    do {
      bSPrintf_regdst(0x20,&DAT_006c3eb4,param_2[1],local_48);
      iVar7 = -1;
      pbVar10 = &local_2c;
      bVar5 = local_2c;
      while (bVar5 != 0) {
        if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
          bVar5 = bVar5 - 0x20;
        }
        iVar7 = iVar7 * 0x21 + (uint)bVar5;
        pbVar1 = pbVar10 + 1;
        pbVar10 = pbVar10 + 1;
        bVar5 = *pbVar1;
      }
      if (*(int *)(param_1 + 4) == 0) {
LAB_0059eca7:
        if (((DAT_0073578c == 0) || (iVar7 = FUN_004ef050(iVar7), iVar7 == 0)) ||
           (*(int *)(iVar7 + 0x18) != 1)) goto LAB_0059ecc9;
      }
      else {
        iVar8 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_0059ec61:
          if (iVar8 != 0) {
            local_4 = 0;
            FUN_004ffb00(iVar8);
            local_4 = 0xffffffff;
          }
          goto LAB_0059eca7;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar8 = FUN_004fd1e0(iVar2 + 0xdc), iVar8 == 0 &&
              (iVar8 = FUN_004fd1e0(iVar2 + 0xec), iVar8 == 0)))) goto LAB_0059eca7;
          goto LAB_0059ec61;
        }
LAB_0059ecc9:
        iVar7 = 0;
      }
      piVar9 = _malloc(0xc);
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9[2] = iVar7;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x40);
      *puVar3 = piVar9;
      *(int **)(param_1 + 0x40) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1 + 0x3c;
      bSPrintf_regdst(0x20,&DAT_006c3eb4,param_2[2],local_48);
      iVar7 = -1;
      pbVar10 = &local_2c;
      bVar5 = local_2c;
      while (bVar5 != 0) {
        if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
          bVar5 = bVar5 - 0x20;
        }
        pbVar1 = pbVar10 + 1;
        iVar7 = iVar7 * 0x21 + (uint)bVar5;
        pbVar10 = pbVar10 + 1;
        bVar5 = *pbVar1;
      }
      if (*(int *)(param_1 + 4) == 0) {
LAB_0059eddb:
        if (((DAT_0073578c == 0) || (iVar7 = FUN_004ef050(iVar7), iVar7 == 0)) ||
           (*(int *)(iVar7 + 0x18) != 1)) goto LAB_0059edfd;
      }
      else {
        iVar8 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_0059ed9d:
          local_4 = 1;
          FUN_004ffb00(iVar8);
          local_4 = 0xffffffff;
          goto LAB_0059eddb;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar8 = FUN_004fd1e0(iVar2 + 0xdc), iVar8 == 0 &&
              (iVar8 = FUN_004fd1e0(iVar2 + 0xec), iVar8 == 0)))) goto LAB_0059eddb;
          goto LAB_0059ed9d;
        }
LAB_0059edfd:
        iVar7 = 0;
      }
      piVar9 = _malloc(0xc);
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9[2] = iVar7;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x34);
      *puVar3 = piVar9;
      *(int **)(param_1 + 0x34) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1 + 0x30;
      bVar4 = local_48 < *(int *)(param_1 + 0x38);
      local_48 = local_48 + 1;
    } while (bVar4);
  }
  *(int *)(param_1 + 0x14) = param_2[7];
  *(int *)(param_1 + 0x44) = param_2[8];
  *(int *)(param_1 + 0x18) = param_2[6];
  iVar7 = param_2[9];
  *(int *)(param_1 + 0x1c) = iVar7;
  *(int *)(param_1 + 0x20) = iVar7;
  *(int *)(param_1 + 0x24) = param_2[10];
  *(int *)(param_1 + 0x50) = param_2[0xb];
  *(int *)(param_1 + 0x54) = param_2[0xc];
  ExceptionList = local_c;
  return;
}


// ==== 0x59ee90 FUN_0059ee90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0059ee90(int param_1)

{
  undefined4 uVar1;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined1 local_4 [4];
  
  FUN_004f7350(&local_14,&local_8);
  FUN_004f6d10(&local_10,&local_c);
  local_14 = (((*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x18)) /
              (*(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18))) *
              *(float *)(param_1 + 0x28) - local_14 * _K_HALF) + *(float *)(param_1 + 0x2c) +
             local_10;
  FUN_004f7350(local_4,&local_10);
  FUN_004f7000(local_14,(local_10 * _K_HALF + local_c) - local_8 * _K_HALF);
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar1 = _ftol_nocw();
    FEObject__SetFormattedText(&DAT_006ca778,uVar1);
  }
  return;
}


// ==== 0x59ef50 FUN_0059ef50

void __fastcall FUN_0059ef50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_EDX;
  undefined4 *puVar3;
  int iVar4;
  int local_8;
  
  iVar1 = _ftol_nocw();
  puVar3 = *(undefined4 **)(param_1 + 0x30);
  iVar4 = 0;
  local_8 = iVar1;
  if (0 < iVar1) {
    do {
      if (puVar3 != (undefined4 *)0x0) {
        iVar4 = puVar3[2];
        if ((iVar4 != 0) &&
           (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar4 + 0x18) == 5)) {
          uVar2 = *(undefined4 *)(iVar4 + 0x60);
          iVar4 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar4) {
            do {
              FEObject__SetVisible(uVar2);
              uVar2 = *(undefined4 *)(extraout_EDX + 4);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        if (puVar3 != (undefined4 *)(param_1 + 0x30)) {
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      local_8 = local_8 + -1;
      iVar4 = iVar1;
    } while (local_8 != 0);
  }
  if (iVar4 < *(int *)(param_1 + 0x38)) {
    do {
      if ((puVar3 != (undefined4 *)0x0) &&
         (FEObject__SetInvisible(puVar3[2]), puVar3 != (undefined4 *)(param_1 + 0x30))) {
        puVar3 = (undefined4 *)*puVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar2 = _ftol_nocw();
    FEObject__SetFormattedText(&DAT_006ca778,uVar2);
  }
  return;
}


// ==== 0x59f030 FUN_0059f030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0059f030(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iStack_10;
  int iStack_8;
  
  iVar7 = *(int *)(param_1 + 0x38);
  iVar3 = _ftol_nocw();
  if (iVar7 < iVar3) {
    iVar3 = iVar7;
  }
  iStack_8 = _ftol_nocw();
  if (iVar7 < iStack_8) {
    iStack_8 = iVar7;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x30);
  iVar7 = 0;
  iStack_10 = iVar3;
  if (0 < iVar3) {
    do {
      if (puVar5 != (undefined4 *)0x0) {
        iVar7 = puVar5[2];
        if ((iVar7 != 0) &&
           (*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar7 + 0x18) == 5)) {
          uVar4 = *(undefined4 *)(iVar7 + 0x60);
          iVar7 = *(int *)(iVar7 + 0x5c);
          if (0 < iVar7) {
            do {
              FEObject__SetVisible(uVar4);
              uVar4 = *(undefined4 *)(extraout_EDX + 4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        if (puVar5 != (undefined4 *)(param_1 + 0x30)) {
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      iStack_10 = iStack_10 + -1;
      iVar7 = iVar3;
    } while (iStack_10 != 0);
  }
  if (iVar7 < *(int *)(param_1 + 0x38)) {
    do {
      if ((puVar5 != (undefined4 *)0x0) &&
         (FEObject__SetInvisible(puVar5[2]), puVar5 != (undefined4 *)(param_1 + 0x30))) {
        puVar5 = (undefined4 *)*puVar5;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x38));
  }
  puVar5 = *(undefined4 **)(param_1 + 0x3c);
  iStack_10 = 0;
  if (0 < iStack_8) {
    iStack_10 = iStack_8;
    do {
      if (puVar5 != (undefined4 *)0x0) {
        iVar7 = puVar5[2];
        if ((iVar7 != 0) &&
           (*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar7 + 0x18) == 5)) {
          uVar4 = *(undefined4 *)(iVar7 + 0x60);
          iVar7 = *(int *)(iVar7 + 0x5c);
          if (0 < iVar7) {
            do {
              FEObject__SetVisible(uVar4);
              uVar4 = *(undefined4 *)(extraout_EDX_00 + 4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        if (puVar5 != (undefined4 *)(param_1 + 0x3c)) {
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
  }
  iVar7 = DAT_00735704;
  if (iStack_10 < *(int *)(param_1 + 0x38)) {
    do {
      if (puVar5 != (undefined4 *)0x0) {
        iVar3 = puVar5[2];
        if (iVar3 != 0) {
          *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400001;
          if (*(int *)(iVar3 + 0x18) == 5) {
            iVar6 = *(int *)(iVar3 + 0x60);
            iVar3 = *(int *)(iVar3 + 0x5c);
            if (0 < iVar3) {
              do {
                FEObject__SetInvisible(iVar6);
                iVar6 = *(int *)(iVar6 + 4);
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
          }
          else if (DAT_0073578c != 0) {
            for (piVar1 = *(int **)(*(int *)(DAT_0073578c + 0xc) + 0x10);
                piVar1 != (int *)(*(int *)(DAT_0073578c + 0xc) + 0x10); piVar1 = (int *)*piVar1) {
              if (piVar1[2] == iVar3) {
                iVar3 = *piVar1;
                piVar2 = (int *)piVar1[1];
                *piVar2 = iVar3;
                *(int **)(iVar3 + 4) = piVar2;
                FUN_00514510();
                iVar3 = *(int *)(iVar7 + 0x18);
                *piVar1 = *(int *)(iVar7 + 0x10);
                *(int *)(iVar7 + 0x18) = iVar3 + -1;
                *(int **)(iVar7 + 0x10) = piVar1;
                break;
              }
            }
          }
        }
        if (puVar5 != (undefined4 *)(param_1 + 0x3c)) {
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      iStack_10 = iStack_10 + 1;
    } while (iStack_10 < *(int *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar4 = _ftol_nocw();
    FEObject__SetFormattedText(&DAT_006ca778,uVar4);
  }
  return;
}


// ==== 0x59f2b0 FUN_0059f2b0

void __thiscall FUN_0059f2b0(int param_1,char param_2)

{
  if (param_2 != '\0') {
    FEObject__SetVisible(*(undefined4 *)(param_1 + 8));
    FEObject__SetVisible(*(undefined4 *)(param_1 + 0xc));
    FEObject__SetVisible(*(undefined4 *)(param_1 + 0x10));
    return;
  }
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x10));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 8));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x59f300 FUN_0059f300

void __thiscall FUN_0059f300(int param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_EDX;
  int iVar3;
  int *piVar4;
  
  if (param_2 == '\0') {
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 8));
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x10));
    for (puVar1 = *(undefined4 **)(param_1 + 0x30); puVar1 != (undefined4 *)(param_1 + 0x30);
        puVar1 = (undefined4 *)*puVar1) {
      FEObject__SetInvisible(puVar1[2]);
    }
  }
  else {
    FEObject__SetVisible();
    FEObject__SetVisible(*(undefined4 *)(param_1 + 0x10));
    piVar4 = *(int **)(param_1 + 0x30);
    if (piVar4 != (int *)(param_1 + 0x30)) {
      do {
        iVar3 = piVar4[2];
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
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)(param_1 + 0x30));
      return;
    }
  }
  return;
}


// ==== 0x59f3b0 FUN_0059f3b0

void __thiscall FUN_0059f3b0(int param_1,char param_2)

{
  undefined4 *puVar1;
  int extraout_EDX;
  undefined4 uVar2;
  int extraout_EDX_00;
  int iVar3;
  int *piVar4;
  
  if (param_2 == '\0') {
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 8));
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x10));
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x48));
    for (puVar1 = *(undefined4 **)(param_1 + 0x30); puVar1 != (undefined4 *)(param_1 + 0x30);
        puVar1 = (undefined4 *)*puVar1) {
      FEObject__SetInvisible(puVar1[2]);
    }
    for (puVar1 = *(undefined4 **)(param_1 + 0x3c); puVar1 != (undefined4 *)(param_1 + 0x3c);
        puVar1 = (undefined4 *)*puVar1) {
      FEObject__SetInvisible(puVar1[2]);
    }
  }
  else {
    FEObject__SetVisible(*(undefined4 *)(param_1 + 8));
    FEObject__SetVisible(*(undefined4 *)(param_1 + 0x10));
    FEObject__SetVisible(*(undefined4 *)(param_1 + 0x48));
    for (puVar1 = *(undefined4 **)(param_1 + 0x30); puVar1 != (undefined4 *)(param_1 + 0x30);
        puVar1 = (undefined4 *)*puVar1) {
      iVar3 = puVar1[2];
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
    }
    piVar4 = *(int **)(param_1 + 0x3c);
    if (piVar4 != (int *)(param_1 + 0x3c)) {
      do {
        iVar3 = piVar4[2];
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
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)(param_1 + 0x3c));
      return;
    }
  }
  return;
}


// ==== 0x59f4f0 FUN_0059f4f0

void __thiscall FUN_0059f4f0(int param_1,float param_2,float param_3)

{
  float fVar1;
  undefined4 *puVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  *(undefined1 *)(param_1 + 0x4c) = param_2._0_1_;
  *(float *)(param_1 + 0x58) = param_3;
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x48));
  if (*(char *)(param_1 + 0x4c) != '\0') {
    fVar1 = *(float *)(param_1 + 0x38);
    param_2 = fVar1;
    fVar3 = (float)_ftol_nocw();
    if ((int)fVar1 < (int)fVar3) {
      fVar3 = fVar1;
    }
    iVar4 = (int)fVar3 + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    puVar2 = *(undefined4 **)(param_1 + 0x30);
    for (iVar5 = 0; (puVar2 != (undefined4 *)(param_1 + 0x30) && (iVar5 != iVar4));
        iVar5 = iVar5 + 1) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2[2] != 0) {
      FUN_004f6d10(&param_3,&param_2);
      FUN_004f7000(param_3 + *(float *)(param_1 + 0x50),param_2 + *(float *)(param_1 + 0x54));
      FUN_004f75b0(0xffb7bf00);
      FEObject__SetVisible(*(undefined4 *)(param_1 + 0x48));
    }
  }
  return;
}


// ==== 0x59f5b0 FUN_0059f5b0

void FUN_0059f5b0(undefined4 param_1,undefined4 param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((DAT_00734424 != 0) && (iVar5 = DAT_006ee6f0, param_3 != '\0')) {
    while( true ) {
      iVar5 = iVar5 + 1;
      if (0xb < iVar5) {
        iVar5 = 0;
      }
      if (iVar5 == DAT_006ee6f0) break;
      bVar1 = false;
      uVar2 = 0;
      piVar4 = &DAT_006ee650;
      do {
        if (*piVar4 == iVar5) {
          if ((((uVar2 & 0xfffffff) != 0xff9119b) &&
              (iVar3 = bOpenFile((&PTR_s_LANGUAGES_ENGLISH_BIN_006ee658)[uVar2 * 4],0,1), iVar3 != 0
              )) && (iVar3 = *(int *)(iVar3 + 4), FUN_00594d40(), iVar3 != -1)) goto LAB_0059f635;
          break;
        }
        piVar4 = piVar4 + 4;
        uVar2 = uVar2 + 1;
      } while ((int)piVar4 < 0x6ee6f0);
      bVar1 = true;
LAB_0059f635:
      if ((iVar5 != DAT_006ee6f4) && (!bVar1)) {
        EAXSound__ChangeLanguage();
        return;
      }
    }
  }
  return;
}


// ==== 0x59f660 FUN_0059f660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059f660(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar4 = 0;
  piVar2 = &DAT_006ee650;
  if (DAT_00734998 == 2) {
    do {
      if (*piVar2 == 7) goto LAB_0059f6b9;
      piVar2 = piVar2 + 4;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6ee6f0);
  }
  else {
    do {
      if (*piVar2 == 0) goto LAB_0059f6b9;
      piVar2 = piVar2 + 4;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6ee6f0);
  }
  puVar5 = (undefined4 *)0x0;
LAB_0059f688:
  piVar2 = (int *)puVar5[3];
  iVar4 = *piVar2;
  iVar6 = 0;
  do {
    if (iVar4 == 0) {
      DAT_00734420 = iVar6 + 0x333f8U & 0xffffffc0;
      if (DAT_006ee4a4 != 0) {
        _DAT_0073441c = FUN_00565b60(DAT_00734420,0,0,0);
        uVar1 = DAT_00734420;
        iVar6 = DAT_006ee4a4 * 0x58;
        puVar5 = (undefined4 *)(&DAT_007301f8 + iVar6);
        (&DAT_007301d4)[DAT_006ee4a4] = puVar5;
        iVar4 = iVar6 + 0x7301fc;
        *(int *)iVar4 = iVar4;
        *(int *)(iVar6 + 0x730200) = iVar4;
        iVar4 = iVar6 + 0x730204;
        *(int *)iVar4 = iVar4;
        *(int *)(iVar6 + 0x730208) = iVar4;
        iVar4 = iVar6 + 0x73020c;
        *(int *)iVar4 = iVar4;
        *(int *)(iVar6 + 0x730210) = iVar4;
        *(undefined4 *)(iVar6 + 0x730214) = 0;
        *(undefined4 *)(iVar6 + 0x730218) = 0;
        *(undefined4 *)(iVar6 + 0x73021c) = 0;
        *(undefined4 *)(iVar6 + 0x730220) = 0;
        *(undefined4 *)(iVar6 + 0x730224) = 0;
        *(undefined4 *)(iVar6 + 0x730228) = 0;
        *(undefined4 *)(iVar6 + 0x73022c) = 0;
        CriticalSection__Init(iVar6 + 0x730234);
        iVar4 = *(int *)(iVar6 + 0x73021c);
        *(undefined1 *)(iVar6 + 0x730230) = 1;
        *(undefined1 *)(iVar6 + 0x730231) = 1;
        *puVar5 = "LanguageMemoryPool";
        *(uint *)(iVar6 + 0x73021c) = iVar4 + uVar1;
        FUN_00565410(puVar5,uVar1);
      }
      FUN_0053eed0(&DAT_00740420,"LANGUAGES\\LANGUAGETEXTURES.BIN",0,0,0);
      iVar4 = ResourceFileList_IsLoadedByName(&DAT_00740420,"LANGUAGES\\LANGUAGETEXTURES.BIN");
      while (iVar4 != 0) {
        ServiceResourceLoading();
        iVar4 = ResourceFileList_IsLoadedByName(&DAT_00740420,"LANGUAGES\\LANGUAGETEXTURES.BIN");
      }
      return;
    }
    iVar3 = 0;
    do {
      if ((&DAT_006ee4a8)[iVar3 * 2] == iVar4) {
        if (-1 < (int)(&DAT_006ee4ac)[iVar3 * 2]) {
          iVar6 = iVar6 + (&DAT_006ee4ac)[iVar3 * 2];
        }
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xb);
    iVar4 = piVar2[1];
    piVar2 = piVar2 + 1;
  } while( true );
LAB_0059f6b9:
  puVar5 = &DAT_006ee650 + iVar4 * 4;
  goto LAB_0059f688;
}


// ==== 0x59f7c0 FUN_0059f7c0

void FUN_0059f7c0(char param_1,char param_2,char param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  piVar1 = &DAT_006ee650;
  do {
    if (*piVar1 == DAT_006ee6f0) {
      puVar3 = &DAT_006ee650 + iVar2 * 4;
      goto LAB_0059f7eb;
    }
    piVar1 = piVar1 + 4;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x6ee6f0);
  puVar3 = (undefined4 *)0x0;
LAB_0059f7eb:
  if (param_1 == '\0') {
    UnloadResourceFile();
    DAT_00734428 = 0;
    if (*(int *)(puVar3[3] + 0x60) != 0) {
      FUN_0053ec90(&DAT_00740420,puVar3[3],8);
      *(undefined4 *)(puVar3[3] + 0x60) = 0;
    }
  }
  if ((param_2 == '\0') && (*(int *)(puVar3[3] + 0x68) != 0)) {
    FUN_0053ec90(&DAT_00740420,puVar3[3] + 0x40,8);
    *(undefined4 *)(puVar3[3] + 0x68) = 0;
  }
  if ((param_3 == '\0') && (*(int *)(puVar3[3] + 100) != 0)) {
    FUN_0053ec90(&DAT_00740420,puVar3[3] + 0x20,8);
    *(undefined4 *)(puVar3[3] + 100) = 0;
  }
  if (param_1 != '\0') {
    if (DAT_00734428 == 0) {
      DAT_00734428 = CreateResourceFile(puVar3[2],7,0,0,0);
      iVar2 = bOpenFile(puVar3[2],1,1);
      if (iVar2 != 0) {
        FUN_00594d40();
      }
      if (((&DAT_007301d4)[DAT_006ee4a4] != 0) && (DAT_006ee4a4 != 0)) {
        FUN_00565810();
      }
      ResourceFile__SetPoolInfo(puVar3[2]);
      ResourceFile__BeginLoading();
      if (param_4 != '\0') {
        while (DAT_007360e8 != 0) {
          ServiceResourceLoading();
        }
      }
    }
    if (*(int *)(puVar3[3] + 0x60) == 0) {
      FUN_0053e9e0(&DAT_00740420,puVar3[3],8,0,0,DAT_006ee4a4);
      *(undefined4 *)(puVar3[3] + 0x60) = 1;
    }
  }
  if ((param_2 != '\0') && (*(int *)(puVar3[3] + 0x68) == 0)) {
    FUN_0053e9e0(&DAT_00740420,puVar3[3] + 0x40,8,0,0,DAT_006ee4a4);
    *(undefined4 *)(puVar3[3] + 0x68) = 1;
  }
  if ((param_3 != '\0') && (*(int *)(puVar3[3] + 100) == 0)) {
    FUN_0053e9e0(&DAT_00740420,puVar3[3] + 0x20,8,0,0,DAT_006ee4a4);
    *(undefined4 *)(puVar3[3] + 100) = 1;
  }
  if (param_4 != '\0') {
    iVar2 = ResourceFileList_IsLoadedByName(&DAT_00740420,"LANGUAGES\\LANGUAGETEXTURES.BIN");
    while (iVar2 != 0) {
      ServiceResourceLoading();
      iVar2 = ResourceFileList_IsLoadedByName(&DAT_00740420,"LANGUAGES\\LANGUAGETEXTURES.BIN");
    }
  }
  return;
}


// ==== 0x59fa20 EAXSound::ChangeLanguage

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__ChangeLanguage(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (in_EAX != DAT_006ee6f0) {
    if (DAT_006ee6f0 != -1) {
      iVar2 = 0;
      piVar1 = &DAT_006ee650;
      do {
        if (*piVar1 == DAT_006ee6f0) {
          puVar3 = &DAT_006ee650 + iVar2 * 4;
          goto LAB_0059fa5a;
        }
        piVar1 = piVar1 + 4;
        iVar2 = iVar2 + 1;
      } while ((int)piVar1 < 0x6ee6f0);
      puVar3 = (undefined4 *)0x0;
LAB_0059fa5a:
      UnloadResourceFile();
      DAT_00734428 = 0;
      if (*(int *)(puVar3[3] + 0x60) != 0) {
        FUN_0053ec90(&DAT_00740420,puVar3[3],8);
        *(undefined4 *)(puVar3[3] + 0x60) = 0;
      }
      if (*(int *)(puVar3[3] + 0x68) != 0) {
        FUN_0053ec90(&DAT_00740420,puVar3[3] + 0x40,8);
        *(undefined4 *)(puVar3[3] + 0x68) = 0;
      }
      if (*(int *)(puVar3[3] + 100) != 0) {
        FUN_0053ec90(&DAT_00740420,puVar3[3] + 0x20,8);
        *(undefined4 *)(puVar3[3] + 100) = 0;
      }
    }
    DAT_006ee6f0 = in_EAX;
    if (in_EAX != -1) {
      FUN_0059f7c0(1,DAT_0077a920 == 3,DAT_0077a920 == 6,1);
      EAXSound__ReloadLanguageSpeechBank__called_by_ChangeLanguage_0x59fa20_(DAT_006ee6f0);
      DAT_007588f0 = (uint)(DAT_006ee6f0 != 0);
      if (DAT_0073578c != 0) {
        cFEng__MakeLoadedPackagesDirty(DAT_0073578c);
      }
    }
  }
  return;
}


// ==== 0x59fb30 FUN_0059fb30

void __fastcall FUN_0059fb30(short *param_1,undefined1 *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  
  if ((param_2 != (undefined1 *)0x0) && (param_1 != (short *)0x0)) {
    sVar1 = *param_1;
    uVar2 = 0;
    if (sVar1 != 0) {
      do {
        if (param_3 - 1U <= uVar2) break;
        if ((-0x81 < sVar1) && (sVar1 < 0x80)) {
          *param_2 = (char)*param_1;
          param_2 = param_2 + 1;
          uVar2 = uVar2 + 1;
        }
        param_1 = param_1 + 1;
        sVar1 = *param_1;
      } while (sVar1 != 0);
    }
    *param_2 = 0;
  }
  return;
}


// ==== 0x59fb80 LanguageStrings::FindByHash

/* [canon] assets high (Hopper sub_59fb80) docs/re/assets.md */

undefined4 __fastcall LanguageStrings__FindByHash(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = DAT_0073442c - 1;
  uVar1 = uVar3 >> 1;
  uVar2 = *(uint *)(DAT_00734434 + uVar1 * 8);
  if (uVar2 != param_2) {
    uVar4 = 0;
    do {
      if (uVar3 - uVar4 < 3) {
        if (*(uint *)(DAT_00734434 + uVar4 * 8) == param_2) {
          return *(undefined4 *)(DAT_00734434 + 4 + uVar4 * 8);
        }
        if (uVar2 == param_2) break;
        if (*(uint *)(DAT_00734434 + uVar3 * 8) == param_2) {
          return *(undefined4 *)(DAT_00734434 + 4 + uVar3 * 8);
        }
      }
      if (uVar1 == uVar4) {
        return 0;
      }
      if (param_2 < uVar2) {
        uVar3 = uVar1;
      }
      if (uVar2 < param_2) {
        uVar4 = uVar1;
      }
      uVar1 = uVar3 + uVar4 >> 1;
      uVar2 = *(uint *)(DAT_00734434 + uVar1 * 8);
    } while (uVar2 != param_2);
  }
  return *(undefined4 *)(DAT_00734434 + 4 + uVar1 * 8);
}


// ==== 0x59fc00 FUN_0059fc00

void FUN_0059fc00(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  char *unaff_EDI;
  
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  if (in_EAX != 0) {
    iVar2 = iVar2 - (int)unaff_EDI;
    do {
      cVar1 = unaff_EDI[iVar2];
      in_EAX = in_EAX + -1;
      *unaff_EDI = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      unaff_EDI = unaff_EDI + 1;
    } while (in_EAX != 0);
  }
  return;
}


// ==== 0x59fc40 FUN_0059fc40

void FUN_0059fc40(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    LanguageStrings__FindByHash();
    return;
  }
  return;
}


// ==== 0x59fc60 FUN_0059fc60

undefined4 FUN_0059fc60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 != 0) {
    FUN_0059ff40(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== 0x59fc90 FUN_0059fc90

void __fastcall FUN_0059fc90(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  
  bSPrintf_regdst(param_1);
  if ((DAT_006ee6f0 != 0) && (DAT_006ee6f0 != 7)) {
    cVar2 = *param_2;
    while (cVar2 != '\0') {
      if (*param_2 == '.') {
        *param_2 = ',';
      }
      pcVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      cVar2 = *pcVar1;
    }
  }
  return;
}


// ==== 0x59fce0 LanguageStrings::Loader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_59fce0 + Ghidra make FUN_0059fce0: H+G agree) docs/re/assets.md
    */

undefined4 LanguageStrings__Loader(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*param_1 == 0x39000) {
    DAT_00734438 = (int)param_1 + param_1[2] + 8;
    iVar3 = param_1[3];
    DAT_00734434 = (int)param_1 + param_1[4] + 8;
    iVar2 = (int)param_1 + param_1[5] + 8;
    DAT_0073442c = iVar3;
    _DAT_00734430 = iVar2;
    if (iVar3 != 0) {
      piVar1 = (int *)(DAT_00734434 + 4);
      do {
        *piVar1 = *piVar1 + iVar2;
        piVar1 = piVar1 + 2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    return 1;
  }
  return 0;
}


// ==== 0x59fd40 LanguageStrings::Unloader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Ghidra make FUN_0059fd40 (Hopper export lacks it)) docs/re/assets.md */

bool LanguageStrings__Unloader(int *param_1)

{
  if (*param_1 == 0x39000) {
    DAT_0073442c = 0;
    _DAT_00734430 = 0;
    DAT_00734434 = 0;
    DAT_00734438 = 0;
  }
  return *param_1 == 0x39000;
}


// ==== 0x59fd70 GetLocalizedLogoMovie

/* [canon] canon low (hopper) docs/re/canon.md */

byte * GetLocalizedLogoMovie(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  iVar6 = 0;
  piVar5 = &DAT_006ee720;
  do {
    pbVar8 = (byte *)piVar5[1];
    pbVar7 = param_1;
    do {
      bVar3 = *pbVar8;
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 & 0x5f;
      }
      bVar1 = *pbVar7;
      pbVar8 = pbVar8 + 1;
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 & 0x5f;
      }
      pbVar7 = pbVar7 + 1;
    } while (((bVar3 != 0) && (bVar1 != 0)) && (bVar3 == bVar1));
    if (bVar3 == bVar1) {
      iVar2 = 0;
      piVar4 = piVar5;
      do {
        if (*piVar4 == DAT_006ee6f0) {
          bSPrintf_regdst(0x20,&DAT_006cc568,(&PTR_s_logo_eng_006ee724)[(iVar2 + iVar6 * 0xc) * 2]);
          return &DAT_0078ef80;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 2;
      } while (iVar2 < 0xc);
    }
    piVar5 = piVar5 + 0x18;
    iVar6 = iVar6 + 1;
  } while ((int)piVar5 < 0x6eef60);
  return param_1;
}


// ==== 0x59fe10 FUN_0059fe10

bool FUN_0059fe10(int param_1,char *param_2)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_EDI;
  
  iVar6 = 0;
  iVar5 = 0;
  bVar3 = false;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    do {
      iVar7 = iVar5 + 1;
      iVar5 = iVar5 + 1;
    } while (param_2[iVar7] != '\0');
    if (0 < iVar5) {
      iVar7 = 0;
      bVar3 = false;
      do {
        if (param_1 + -1 <= iVar6) break;
        bVar2 = param_2[iVar7];
        iVar8 = iVar7 + 1;
        if ((char)bVar2 < '\0') {
          if ((bVar2 & 0xe0) == 0xc0) {
            pbVar1 = (byte *)(param_2 + iVar8);
            iVar8 = iVar7 + 2;
            if ((*pbVar1 & 0xc0) == 0x80) {
              uVar4 = (ushort)(bVar2 & 0x1f) * 0x40 + (ushort)(*pbVar1 & 0x3f);
            }
            else {
LAB_0059fe81:
              iVar8 = iVar7 + 1;
              uVar4 = (ushort)bVar2;
              bVar3 = true;
            }
            *(ushort *)(unaff_EDI + iVar6 * 2) = uVar4;
          }
          else {
            if ((bVar2 & 0xf0) != 0xe0) goto LAB_0059fe81;
            pbVar1 = (byte *)(param_2 + iVar8);
            iVar8 = iVar7 + 3;
            if (((*pbVar1 & 0xc0) == 0x80) && ((param_2[iVar7 + 2] & 0xc0U) == 0x80)) {
              uVar4 = ((ushort)(*pbVar1 & 0x3f) + (ushort)bVar2 * 0x40) * 0x40 +
                      (ushort)(param_2[iVar7 + 2] & 0x3f);
              if (0xff7f < uVar4) {
                uVar4 = uVar4 & 0xff;
              }
              *(ushort *)(unaff_EDI + iVar6 * 2) = uVar4;
            }
            else {
              bVar3 = true;
              iVar8 = iVar7 + 1;
              *(ushort *)(unaff_EDI + iVar6 * 2) = (ushort)bVar2;
            }
          }
        }
        else {
          *(ushort *)(unaff_EDI + iVar6 * 2) = (ushort)bVar2;
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar8;
      } while (iVar8 < iVar5);
    }
  }
  *(undefined2 *)(unaff_EDI + iVar6 * 2) = 0;
  return !bVar3;
}


// ==== 0x59ff40 FUN_0059ff40

bool FUN_0059ff40(int param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  byte *in_EAX;
  int iVar5;
  byte *pbVar6;
  int unaff_EDI;
  
  bVar2 = false;
  iVar5 = 0;
  bVar3 = false;
  if (0 < param_2) {
    do {
      bVar2 = bVar3;
      bVar1 = *in_EAX;
      pbVar6 = in_EAX + 1;
      if (bVar1 < 0x80) {
        uVar4 = (ushort)bVar1;
      }
      else if (DAT_00734418 == 0) {
        uVar4 = *(ushort *)(unaff_EDI + 4 + (uint)bVar1 * 2);
        if (uVar4 < 0x80) {
          if (uVar4 == 0) {
            uVar4 = (ushort)bVar1;
            goto LAB_0059ffa2;
          }
          bVar1 = *pbVar6;
          pbVar6 = in_EAX + 2;
          if (0x7f < bVar1) {
            uVar4 = *(ushort *)(unaff_EDI + -0xfc + ((uint)uVar4 * 0x80 + (uint)bVar1) * 2);
            goto LAB_0059ffa2;
          }
        }
        else {
LAB_0059ffa2:
          if (uVar4 != 0) goto LAB_0059ffae;
        }
        bVar2 = true;
        uVar4 = 0x5f;
      }
      else {
        uVar4 = (ushort)bVar1;
      }
LAB_0059ffae:
      *(ushort *)(param_1 + iVar5 * 2) = uVar4;
      iVar5 = iVar5 + 1;
    } while ((uVar4 != 0) && (in_EAX = pbVar6, bVar3 = bVar2, iVar5 < param_2));
  }
  return !bVar2;
}


// ==== 0x59ffd0 FUN_0059ffd0

int FUN_0059ffd0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 8;
  do {
    FinishedRaceStatsEntry__operator_();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0xae0) = *(undefined4 *)(param_2 + 0xae0);
  return param_1;
}


// ==== 0x5a0020 FUN_005a0020

void __fastcall FUN_005a0020(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006b7f7c;
  eh_vector_destructor_iterator(param_1 + 0x161b,0xc,4,FUN_004b39a0);
  return;
}


// ==== 0x5a0040 FUN_005a0040

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005a0040(undefined4 param_1,byte param_2)

{
  FUN_005a0020();
  if ((param_2 & 1) != 0) {
    _DAT_00735ec8 = 0;
  }
  return param_1;
}


// ==== 0x5a005f FUN_005a005f

void FUN_005a005f(uint *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_2 = param_2 / 0x14c;
  puVar2 = &DAT_00733ff8;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (; param_2 != 0; param_2 = param_2 - 1) {
    if (*param_1 < 0x100) {
      (&DAT_00733ff8)[*param_1] = param_1;
    }
    param_1 = param_1 + 0x53;
  }
  return;
}


// ==== 0x5a0060 CareerEvents::IndexEventDesc

/* [canon] assets high (Hopper sub_5a0060) docs/re/assets.md */

void CareerEvents__IndexEventDesc(uint *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_2 = param_2 / 0x14c;
  puVar2 = &DAT_00733ff8;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (; param_2 != 0; param_2 = param_2 - 1) {
    if (*param_1 < 0x100) {
      (&DAT_00733ff8)[*param_1] = param_1;
    }
    param_1 = param_1 + 0x53;
  }
  return;
}


// ==== 0x5a00a0 CareerEvents::Loader

/* [canon] assets high (Hopper sub_5a00a0 + Ghidra make FUN_005a00a0: H+G agree) docs/re/assets.md
    */

undefined4 CareerEvents__Loader(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  if (*param_1 != -0x7ffcb600) {
    return 0;
  }
  iVar2 = param_1[1];
  for (piVar1 = param_1 + 2; piVar1 != (int *)(iVar2 + 8 + (int)param_1);
      piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
    if (*piVar1 == 0x34a01) {
      uVar5 = (uint)piVar1[1] >> 5;
      puVar3 = (uint *)(piVar1 + 2);
      puVar6 = &DAT_00733f78;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        if (*puVar3 < 0x20) {
          (&DAT_00733f78)[*puVar3] = puVar3;
        }
        puVar3 = puVar3 + 8;
      }
    }
    else if (*piVar1 == 0x34a02) {
      CareerEvents__IndexEventDesc(piVar1 + 2,piVar1[1]);
    }
  }
  return 1;
}


// ==== 0x5a0130 CareerEvents::Unloader

/* [canon] assets high (Hopper sub_5a0130 + Ghidra make FUN_005a0130: H+G agree) docs/re/assets.md
    */

undefined4 CareerEvents__Unloader(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  if (*param_1 == -0x7ffcb600) {
    puVar3 = &DAT_00733ff8;
    for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar3 = &DAT_00733f78;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== 0x5a0160 FUN_005a0160

void FUN_005a0160(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 *unaff_EBX;
  uint *puVar4;
  uint *puVar5;
  
  puVar2 = param_2;
  puVar5 = (uint *)0x0;
  puVar4 = (uint *)0x0;
  if (0 < DAT_007343fc) {
    param_2 = (undefined4 *)DAT_007343fc;
    puVar5 = (uint *)0x0;
    puVar3 = DAT_007343f8;
    do {
      uVar1 = *puVar3;
      if ((int)(uVar1 - param_1) < 0) {
        if ((puVar5 == (uint *)0x0) || (*puVar5 < uVar1)) {
          puVar5 = puVar3;
        }
      }
      else if (uVar1 == param_1 || (int)(uVar1 - param_1) < 0) {
        *puVar2 = puVar3;
        *unaff_EBX = puVar3;
      }
      else if ((puVar4 == (uint *)0x0) || (uVar1 < *puVar4)) {
        puVar4 = puVar3;
      }
      puVar3 = puVar3 + 8;
      param_2 = (undefined4 *)((int)param_2 + -1);
    } while (param_2 != (undefined4 *)0x0);
  }
  *puVar2 = puVar4;
  *unaff_EBX = puVar5;
  return;
}


// ==== 0x5a01d0 Table34A08::Loader

/* [canon] assets high (Hopper sub_5a01d0 + Ghidra make FUN_005a01d0: H+G agree) docs/re/assets.md
    */

undefined4 Table34A08__Loader(int *param_1)

{
  if (*param_1 == 0x34a08) {
    DAT_007343f8 = (int)param_1 + 0x17U & 0xfffffff0;
    DAT_007343fc = (uint)param_1[1] >> 5;
    return 1;
  }
  return 0;
}


// ==== 0x5a0200 Table34A08::Unloader

/* [canon] assets high (Hopper sub_5a0200 + Ghidra make: H+G agree) docs/re/assets.md */

bool Table34A08__Unloader(int *param_1)

{
  return *param_1 == 0x34a08;
}


// ==== 0x5a0220 Table34A0A::Find

/* [canon] assets high (Ghidra make FUN_005a0220) docs/re/assets.md */

int Table34A0A__Find(uint param_1)

{
  uint uVar1;
  short *psVar2;
  uint unaff_ESI;
  short unaff_DI;
  
  uVar1 = 0;
  if (DAT_00734408 != 0) {
    psVar2 = (short *)(DAT_00734404 + 2);
    do {
      if ((((ushort)psVar2[-1] == param_1) && ((ushort)psVar2[1] == unaff_ESI)) &&
         (unaff_DI == *psVar2)) {
        return uVar1 * 0x10 + DAT_00734404;
      }
      uVar1 = uVar1 + 1;
      psVar2 = psVar2 + 8;
    } while (uVar1 < DAT_00734408);
  }
  return 0;
}


// ==== 0x5a0270 Table34A09::Loader

/* [canon] assets high (Hopper sub_5a0270 + Ghidra make FUN_005a0270: H+G agree) docs/re/assets.md
    */

undefined4 Table34A09__Loader(int *param_1)

{
  if (*param_1 == 0x34a09) {
    DAT_00734400 = (int)param_1 + 0x17U & 0xfffffff0;
    return 1;
  }
  return 0;
}


// ==== 0x5a0290 Table34A09::Unloader

/* [canon] assets high (Hopper sub_5a0290 + Ghidra make FUN_005a0290: H+G agree) docs/re/assets.md
    */

undefined4 Table34A09__Unloader(int *param_1)

{
  if (*param_1 == 0x34a09) {
    *DAT_00734400 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x5a02c0 Table34A0A::Loader

/* [canon] assets high (Ghidra make FUN_005a02c0 (Hopper export lacks it)) docs/re/assets.md */

undefined4 Table34A0A__Loader(int *param_1)

{
  if (*param_1 == 0x34a0a) {
    DAT_00734404 = (int)param_1 + 0x17U & 0xfffffff0;
    DAT_00734408 = (uint)param_1[1] >> 4;
    return 1;
  }
  return 0;
}


// ==== 0x5a02f0 Table34A0A::Unloader

/* [canon] assets high (Hopper sub_5a02f0 + Ghidra make: H+G agree) docs/re/assets.md */

undefined4 Table34A0A__Unloader(int *param_1)

{
  if (*param_1 == 0x34a0a) {
    *DAT_00734404 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x5a0320 Career::EventGivesLevel4Part

/* [canon] canon med (ghidra) docs/re/canon.md */

uint Career__EventGivesLevel4Part(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  
  piVar1 = in_EAX + 0x1d;
  iVar2 = 0;
  if (0 < *piVar1) {
    in_EAX = in_EAX + 0xe;
    do {
      if ((*in_EAX == 0) && (in_EAX[2] == 4)) {
        return CONCAT31((int3)((uint)in_EAX >> 8),1);
      }
      iVar2 = iVar2 + 1;
      in_EAX = in_EAX + 3;
    } while (iVar2 < *piVar1);
  }
  return (uint)in_EAX & 0xffffff00;
}


// ==== 0x5a0350 FUN_005a0350

undefined4 FUN_005a0350(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0x10;
  case 1:
    return 0x15;
  case 2:
    return 0x12;
  case 3:
    return 0x16;
  case 4:
    return 0x18;
  case 5:
    return 0x17;
  case 6:
    return 0x13;
  case 7:
    return 0x14;
  case 8:
    return 0x11;
  case 9:
    return 8;
  case 10:
    return 5;
  default:
    return 0xffffffff;
  }
}


// ==== 0x5a03d0 MapCarPartIDToCareerUpgrade

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 MapCarPartIDToCareerUpgrade(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
    return 9;
  case 2:
    return 0xb;
  default:
    return 0xffffffff;
  case 6:
    return 0xf;
  case 7:
    return 0xd;
  case 8:
    return 0xc;
  case 10:
    return 5;
  case 0xb:
    return 8;
  case 0xd:
    return 6;
  case 0xe:
    return 10;
  case 0xf:
    return 2;
  case 0x11:
    return 3;
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    return 0;
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
    return 7;
  case 0x3a:
    return 1;
  case 0x73:
    return 4;
  case 0x74:
    return 0xe;
  }
}


// ==== 0x5a0500 FUN_005a0500

undefined4 FUN_005a0500(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0x1e;
  default:
    return 0xffffffff;
  case 2:
    return 0xf;
  case 3:
    return 0x11;
  case 4:
    return 0x73;
  case 5:
    return 10;
  case 6:
    return 0xd;
  case 7:
    return 0x1f;
  case 8:
    return 0xb;
  case 9:
    return 1;
  case 10:
    return 0xe;
  case 0xb:
    return 2;
  case 0xc:
    return 8;
  case 0xd:
    return 7;
  case 0xe:
    return 0x74;
  case 0xf:
    return 6;
  }
}


// ==== 0x5a05b0 CalculateRideReputationPoints

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

float10 CalculateRideReputationPoints(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int iVar9;
  int unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  int local_8;
  float local_4;
  
  fVar10 = (float10)0.0;
  fVar11 = (float10)0.0;
  fVar12 = (float10)0.0;
  local_4 = 0.0;
  fVar13 = (float10)0.0;
  if (DAT_006ee3d8 != 0xffffffff) {
    puVar8 = &DAT_006ee3e0;
    uVar2 = DAT_006ee3d8;
    do {
      if (uVar2 < 0x20) {
        iVar9 = (&DAT_00733f78)[uVar2];
      }
      else {
        iVar9 = 0;
      }
      uVar2 = *puVar8;
      if ((uVar2 & 1) != 0) {
        fVar13 = fVar13 + (float10)*(int *)(iVar9 + 0x10);
      }
      if ((uVar2 & 2) != 0) {
        fVar11 = (float10)*(int *)(iVar9 + 0x14) + fVar11;
      }
      if ((uVar2 & 4) != 0) {
        fVar12 = (float10)*(int *)(iVar9 + 0x18) + fVar12;
      }
      uVar2 = puVar8[1];
      puVar8 = puVar8 + 3;
    } while (uVar2 != 0xffffffff);
    local_4 = (float)fVar13;
    if (DAT_006ee3d8 != 0xffffffff) {
      puVar7 = &DAT_006ee3d8;
      uVar2 = DAT_006ee3d8;
LAB_005a0652:
      if (uVar2 == 7) {
        bVar5 = 0;
        piVar6 = (int *)(unaff_EDI + 0x4c8);
        iVar9 = 4;
        do {
          if ((*piVar6 != 0) && (bVar1 = *(byte *)(*piVar6 + 0x11), bVar5 < bVar1)) {
            bVar5 = bVar1;
          }
          piVar6 = piVar6 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (bVar5 == 0) goto LAB_005a07eb;
        switch(bVar5) {
        case 1:
          local_8 = *(int *)(DAT_00733f94 + 0x10);
          break;
        case 2:
          local_8 = *(int *)(DAT_00733f94 + 0x14);
          break;
        case 3:
          iVar4 = DAT_00733f94;
switchD_005a07bf_caseD_3:
          local_8 = *(int *)(iVar4 + 0x18);
          break;
        case 4:
          local_8 = *(int *)(DAT_00733f94 + 0x1c);
          break;
        default:
          goto switchD_005a068f_default;
        }
        goto LAB_005a07e5;
      }
      if (uVar2 == 1) {
        iVar9 = 0x3b;
        piVar6 = (int *)(unaff_EDI + 0x538);
        do {
          if (*piVar6 != 0) {
            uVar3 = 3;
            goto LAB_005a074d;
          }
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar9 < 0x41);
        iVar9 = 0x53;
        piVar6 = (int *)(unaff_EDI + 0x598);
        do {
          if (*piVar6 != 0) {
            uVar3 = 2;
            goto LAB_005a074d;
          }
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar9 < 0x71);
        iVar9 = 0x43;
        piVar6 = (int *)(unaff_EDI + 0x558);
        do {
          if (*piVar6 != 0) {
            uVar3 = 1;
            goto LAB_005a074d;
          }
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar9 < 0x51);
      }
      else {
        iVar9 = *(int *)(unaff_EDI + 0x44c + puVar7[1] * 4);
        if (iVar9 != 0) {
          if (uVar2 < 0x20) {
            iVar4 = (&DAT_00733f78)[uVar2];
          }
          else {
            iVar4 = 0;
          }
          switch(*(undefined1 *)(iVar9 + 0x11)) {
          default:
            goto switchD_005a068f_default;
          case 1:
            local_8 = *(int *)(iVar4 + 0x10);
            break;
          case 2:
            local_8 = *(int *)(iVar4 + 0x14);
            break;
          case 3:
            goto switchD_005a07bf_caseD_3;
          case 4:
            local_8 = *(int *)(iVar4 + 0x1c);
          }
          goto LAB_005a07e5;
        }
      }
      goto LAB_005a07eb;
    }
  }
LAB_005a07fa:
  if (fVar13 <= fVar10) {
    if (fVar11 <= fVar10) {
      fVar10 = (fVar10 - fVar11) / (fVar12 - fVar11) + (float10)4.0;
    }
    else {
      fVar10 = (fVar10 - (float10)local_4) / (fVar11 - (float10)local_4) + (float10)_K_ONE;
      fVar10 = fVar10 + fVar10;
    }
  }
  else {
    fVar10 = fVar10 / (float10)local_4 + fVar10 / (float10)local_4;
  }
  if ((float10)5.0 < fVar10) {
    fVar10 = (float10)5.0;
  }
  return fVar10;
LAB_005a074d:
  switch(uVar3) {
  default:
switchD_005a068f_default:
    local_8 = 0;
    break;
  case 1:
    local_8 = *(int *)(DAT_00733f7c + 0x10);
    break;
  case 2:
    local_8 = *(int *)(DAT_00733f7c + 0x14);
    break;
  case 3:
    local_8 = *(int *)(DAT_00733f7c + 0x18);
  }
LAB_005a07e5:
  fVar10 = (float10)local_8 + fVar10;
LAB_005a07eb:
  uVar2 = puVar7[3];
  puVar7 = puVar7 + 3;
  if (uVar2 == 0xffffffff) goto LAB_005a07fa;
  goto LAB_005a0652;
}


// ==== 0x5a08b0 FUN_005a08b0

undefined4 __fastcall FUN_005a08b0(undefined4 param_1)

{
  uint in_EAX;
  int iVar1;
  
  if (in_EAX < 0x20) {
    iVar1 = (&DAT_00733f78)[in_EAX];
  }
  else {
    iVar1 = 0;
  }
  switch(param_1) {
  default:
    return 0;
  case 1:
    return *(undefined4 *)(iVar1 + 4);
  case 2:
    return *(undefined4 *)(iVar1 + 8);
  case 3:
    return *(undefined4 *)(iVar1 + 0xc);
  }
}


// ==== 0x5a08f0 GetCarPartCost

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall GetCarPartCost(int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_ECX;
  
  if (((param_1 != 0) && (uVar2 = MapCarPartIDToCareerUpgrade(), uVar2 < 0x20)) &&
     (iVar1 = (&DAT_00733f78)[uVar2], iVar1 != 0)) {
    switch(*(undefined1 *)(extraout_ECX + 0x11)) {
    case 1:
      return *(undefined4 *)(iVar1 + 4);
    case 2:
      return *(undefined4 *)(iVar1 + 8);
    case 3:
      return *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return 0;
}


// ==== 0x5a0940 FUN_005a0940

undefined4 * FUN_005a0940(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684f6e;
  local_c = ExceptionList;
  iVar1 = 0;
  ExceptionList = &local_c;
  do {
    param_1[iVar1 + 0xb8] = 0;
    param_1[iVar1 + 0xc3] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  *param_1 = 0;
  param_1[0x113] = &PTR_CareerMenuScreen___CareerMenuScreen_006c6434;
  puVar2 = param_1 + 0x114;
  for (iVar1 = 900; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x498;
  for (iVar1 = 0x44; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x4dc) = 0;
  *(undefined1 *)((int)param_1 + 0x1371) = 0;
  puVar2 = param_1 + 0x498;
  for (iVar1 = 0x44; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_4 = 0;
  eh_vector_constructor_iterator(param_1 + 0x4ea,0x454,0x1b,FUN_00504150,NullUpdate_ret);
  param_1[0x222c] = 0;
  *(undefined1 *)((int)param_1 + 0x889f) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5a0a00 Career::Reset

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Career__Reset(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  
  *(undefined4 *)(unaff_ESI + 0x13a4) = 0;
  FUN_004f42f0("CAREER_CAR");
  FUN_004acb90();
  puVar3 = (undefined4 *)(unaff_ESI + 0x34c);
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(unaff_ESI + 0x1374) = 0;
  *(undefined4 *)(unaff_ESI + 0x1378) = 0;
  *(undefined4 *)(unaff_ESI + 0x137c) = 0;
  *(undefined4 *)(unaff_ESI + 0x1380) = 0;
  if (*(undefined4 **)(unaff_ESI + 0x88b0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x88b0))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x88b0) = 0;
  *(undefined4 *)(unaff_ESI + 0x348) = 1;
  *(undefined2 *)(unaff_ESI + 0x1384) = 0;
  *(undefined1 *)(unaff_ESI + 0x1386) = 0;
  *(undefined1 *)(unaff_ESI + 4999) = 0;
  puVar1 = (undefined1 *)(unaff_ESI + 0x13a9);
  iVar2 = 0x1b;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 0x454;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(unaff_ESI + 0x88a0) = 0;
  *(undefined4 *)(unaff_ESI + 0x88a4) = 0;
  *(undefined4 *)(unaff_ESI + 0x88a8) = 0;
  *(undefined4 *)(unaff_ESI + 0x88ac) = 0;
  *(undefined1 *)(unaff_ESI + 0x889f) = 0;
  puVar3 = (undefined4 *)(unaff_ESI + 0x8884);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  *(undefined4 *)(unaff_ESI + 0x138c) = 0;
  *(undefined4 *)(unaff_ESI + 5000) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1390) = 0;
  *(undefined4 *)(unaff_ESI + 0x1394) = 0;
  *(undefined4 *)(unaff_ESI + 0x1398) = 0;
  *(undefined4 *)(unaff_ESI + 0x139c) = 0;
  *(undefined4 *)(unaff_ESI + 0x13a0) = 0;
  puVar3 = (undefined4 *)(unaff_ESI + 0x450);
  for (iVar2 = 900; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)(unaff_ESI + 0x1260);
  for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(unaff_ESI + 0x1370) = 0;
  *(undefined1 *)(unaff_ESI + 0x1371) = 0;
  puVar3 = (undefined4 *)(unaff_ESI + 0x1260);
  for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ==== 0x5a0b40 FUN_005a0b40

void FUN_005a0b40(int param_1)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar6 = "MAGAZINE_TASK_1";
  uVar2 = 0x4d;
  iVar5 = -1;
  do {
    iVar5 = iVar5 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  iVar3 = 0;
  do {
    if ((&DAT_00744ab0)[iVar3 * 2] == iVar5) {
      iVar5 = *(int *)(&DAT_00744ab4 + iVar3 * 8);
      goto LAB_005a0b73;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1b);
  iVar5 = 0;
LAB_005a0b73:
  param_1 = (iVar5 + in_EAX) * 0x454 + param_1;
  *(undefined1 *)(param_1 + 0x13a9) = 1;
  if ((((in_EAX == 0xf) || (in_EAX == 0xe)) || (in_EAX == 0xd)) || (in_EAX == 0xc)) {
    uVar4 = FUN_004f42f0("MAGAZINE_TASK_%d",in_EAX + 1,param_1 + 0x13a8);
    Career__AnnounceReward(uVar4);
  }
  return;
}


// ==== 0x5a0bd0 FUN_005a0bd0

void FUN_005a0bd0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(unaff_ESI + 0x358) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(unaff_ESI + 0x35c) = *(undefined4 *)(iVar1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(unaff_ESI + 0x344) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(unaff_ESI + 0x34c) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(unaff_ESI + 0x348) = *(undefined4 *)(iVar1 + 0xc);
  FUN_004c94b0();
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_ESI + 0x368) = 0;
    *(undefined4 *)(unaff_ESI + 0x36c) = 0;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x368) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(unaff_ESI + 0x36c) = *(undefined4 *)(iVar1 + 0xc);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(unaff_ESI + 0x378) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(unaff_ESI + 0x37c) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(unaff_ESI + 0x380) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(unaff_ESI + 900) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(unaff_ESI + 0x388) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(unaff_ESI + 0x38c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(unaff_ESI + 0x390) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(unaff_ESI + 0x394) = *(undefined4 *)(iVar1 + 0x24);
  *(undefined4 *)(unaff_ESI + 0x398) = *(undefined4 *)(iVar1 + 0x28);
  *(undefined4 *)(unaff_ESI + 0x39c) = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(unaff_ESI + 0x3a0) = *(undefined4 *)(iVar1 + 0x30);
  *(undefined4 *)(unaff_ESI + 0x3a4) = *(undefined4 *)(iVar1 + 0x34);
  if (*(int *)(param_1 + 0x24) != 0) {
    *(undefined4 *)(unaff_ESI + 0x450) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x450) = 0;
  return;
}


// ==== 0x5a0ce0 Career::StartEvent

/* [canon] canon high (hopper+ghidra) docs/re/canon.md */

void Career__StartEvent(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int unaff_ESI;
  uint unaff_EDI;
  
  if (((unaff_EDI < 0x100) && ((&DAT_00733ff8)[unaff_EDI] != 0)) ||
     ((*(int *)(unaff_ESI + 0x88b0) != 0 &&
      ((puVar1 = (uint *)(*(int *)(unaff_ESI + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
       (unaff_EDI == *puVar1)))))) {
    puVar4 = (undefined1 *)(unaff_EDI + 0x34c + unaff_ESI);
  }
  else {
    puVar4 = (undefined1 *)0x0;
  }
  iVar2 = _ftol_nocw();
  *(int *)(unaff_ESI + 0x1374) = *(int *)(unaff_ESI + 0x1374) - iVar2;
  *(int *)(unaff_ESI + 0x137c) = *(int *)(unaff_ESI + 0x137c) + iVar2;
  if (unaff_EDI == 0) {
    *puVar4 = 1;
  }
  *puVar4 = 3;
  uVar3 = Career__CreateRaceObject(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x88b0) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x138c) = 0;
  *(undefined4 *)(unaff_ESI + 5000) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1390) = 0;
  *(undefined4 *)(unaff_ESI + 0x1394) = 0;
  *(undefined4 *)(unaff_ESI + 0x1398) = 0;
  *(undefined4 *)(unaff_ESI + 0x139c) = 0;
  *(undefined4 *)(unaff_ESI + 0x13a0) = 0;
  return;
}


// ==== 0x5a0dc0 Career::WinEvent

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

void Career__WinEvent(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  uint *puVar7;
  int unaff_EDI;
  
  if (((param_1 < 0x100) && ((&DAT_00733ff8)[param_1] != 0)) ||
     ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
      ((puVar1 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
       (param_1 == *puVar1)))))) {
    puVar6 = (undefined1 *)(param_1 + 0x34c + unaff_EDI);
  }
  else {
    puVar6 = (undefined1 *)0x0;
  }
  if (((0xff < param_1) || (puVar1 = (uint *)(&DAT_00733ff8)[param_1], puVar1 == (uint *)0x0)) &&
     ((*(int *)(unaff_EDI + 0x88b0) == 0 ||
      ((puVar1 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar1 == (uint *)0x0 ||
       (param_1 != *puVar1)))))) {
    puVar1 = (uint *)0x0;
  }
  Career__BuildRewardSummary(puVar1);
  iVar2 = _ftol_nocw();
  *(int *)(unaff_EDI + 0x1374) = *(int *)(unaff_EDI + 0x1374) + iVar2;
  *(int *)(unaff_EDI + 0x1378) = *(int *)(unaff_EDI + 0x1378) + iVar2;
  *puVar6 = 2;
  iVar2 = 0;
  if (0 < (int)puVar1[0x1d]) {
    puVar7 = puVar1 + 0xe;
    do {
      if (*puVar7 == 1) {
        iVar3 = 0;
        do {
          if ((&DAT_00744ab0)[iVar3 * 2] == puVar7[1]) {
            iVar3 = *(int *)(&DAT_00744ab4 + iVar3 * 8);
            goto LAB_005a0e91;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x1b);
        iVar3 = 0;
LAB_005a0e91:
        Career__AnnounceReward(puVar7[1],iVar3 * 0x454 + 0x13a8 + unaff_EDI);
      }
      iVar2 = iVar2 + 1;
      puVar7 = puVar7 + 3;
    } while (iVar2 < (int)puVar1[0x1d]);
  }
  iVar2 = 0xb;
  pcVar4 = &DAT_0076323d;
  while ((*pcVar4 == '\0' || ((&DAT_0076777c)[iVar2] != '\0'))) {
    pcVar4 = pcVar4 + 0x454;
    iVar2 = iVar2 + 1;
    if (0x76777c < (int)pcVar4) goto LAB_005a0f27;
  }
  iVar2 = 0xb;
  pcVar4 = (char *)(unaff_EDI + 0x4344);
  do {
    if (((*pcVar4 == '\0') && (pcVar4[1] != '\0')) &&
       (*(char *)(iVar2 + 0x8884 + unaff_EDI) == '\0')) {
      uVar5 = FUN_004e93b0(pcVar4);
      Career__AnnounceReward(uVar5);
    }
    iVar2 = iVar2 + 1;
    pcVar4 = pcVar4 + 0x454;
  } while (iVar2 < 0x1b);
LAB_005a0f27:
  if (param_1 == 0x71) {
    DAT_007677ac = 1;
  }
  if (*(undefined4 **)(unaff_EDI + 0x88b0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x88b0))(1);
  }
  *(undefined4 *)(unaff_EDI + 0x88b0) = 0;
  return;
}


// ==== 0x5a0f60 Career::QuitEvent

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

void __fastcall Career__QuitEvent(uint param_1)

{
  uint *puVar1;
  undefined1 *puVar2;
  int unaff_ESI;
  
  if (((param_1 < 0x100) && ((&DAT_00733ff8)[param_1] != 0)) ||
     ((*(int *)(unaff_ESI + 0x88b0) != 0 &&
      ((puVar1 = (uint *)(*(int *)(unaff_ESI + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
       (param_1 == *puVar1)))))) {
    puVar2 = (undefined1 *)(param_1 + 0x34c + unaff_ESI);
  }
  else {
    puVar2 = (undefined1 *)0x0;
  }
  *puVar2 = 5;
  if (*(undefined4 **)(unaff_ESI + 0x88b0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x88b0))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x88b0) = 0;
  return;
}


// ==== 0x5a0fc0 Career::ArePrerequisitesDone

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

uint __fastcall Career__ArePrerequisitesDone(uint *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  uint *puVar11;
  undefined8 uVar12;
  
  uVar6 = *param_1;
  if (uVar6 == 0) {
    return 0;
  }
  if (((uVar6 < 0x100) && ((&DAT_00733ff8)[uVar6] != 0)) ||
     ((*(int *)(param_2 + 0x88b0) != 0 &&
      ((puVar11 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar11 != (uint *)0x0 &&
       (uVar6 == *puVar11)))))) {
    pcVar5 = (char *)(uVar6 + 0x34c + param_2);
  }
  else {
    pcVar5 = (char *)0x0;
  }
  cVar9 = *pcVar5;
  uVar6 = CONCAT31((int3)((uint)pcVar5 >> 8),cVar9);
  if (((cVar9 != '\x02') && (cVar9 != '\x04')) && (param_1[1] != 8)) {
    sVar2 = (short)param_1[0x2a];
    uVar6 = CONCAT22((short)((uint)pcVar5 >> 0x10),sVar2);
    if (sVar2 == 0) {
      iVar7 = (int)*(short *)((int)param_1 + 0xaa);
      bVar3 = true;
      iVar10 = iVar7;
      if (0 < iVar7) {
        do {
          iVar8 = FUN_005a1810(param_2);
          uVar12 = FUN_005a17d0();
          param_2 = (int)((ulonglong)uVar12 >> 0x20);
          cVar9 = *(char *)uVar12;
          iVar7 = CONCAT31((int3)((ulonglong)uVar12 >> 8),cVar9);
          bVar4 = false;
          if ((cVar9 == '\x02') ||
             (((cVar9 == '\x04' || (cVar9 == '\x05')) &&
              ((*(int *)(iVar8 + 4) == 2 || (*(int *)(iVar8 + 4) == 3)))))) {
            bVar4 = true;
          }
          if ((bVar3) && (bVar4)) {
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      return CONCAT31((int3)((uint)iVar7 >> 8),bVar3);
    }
    if (sVar2 == 1) {
      iVar7 = (int)*(short *)((int)param_1 + 0xaa);
      cVar9 = '\0';
      iVar10 = iVar7;
      if (0 < iVar7) {
        do {
          iVar8 = FUN_005a1810(param_2);
          uVar12 = FUN_005a17d0();
          param_2 = (int)((ulonglong)uVar12 >> 0x20);
          cVar1 = *(char *)uVar12;
          iVar7 = CONCAT31((int3)((ulonglong)uVar12 >> 8),cVar1);
          bVar3 = false;
          if ((cVar1 == '\x02') ||
             (((cVar1 == '\x04' || (cVar1 == '\x05')) &&
              ((*(int *)(iVar8 + 4) == 2 || (*(int *)(iVar8 + 4) == 3)))))) {
            bVar3 = true;
          }
          if ((cVar9 != '\0') || (bVar3)) {
            cVar9 = '\x01';
          }
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      return CONCAT31((int3)((uint)iVar7 >> 8),cVar9);
    }
  }
  return uVar6 & 0xffffff00;
}


