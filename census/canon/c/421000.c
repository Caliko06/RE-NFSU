// ==== 0x421170 FUN_00421170

int FUN_00421170(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int local_4;
  
  local_4 = 0;
  uVar5 = DAT_0073ad34;
  if (0 < *(int *)(param_1 + 0x18)) {
    piVar6 = (int *)(param_1 + 0x28);
    puVar7 = (undefined4 *)(param_1 + 0xa8);
    do {
      iVar3 = *piVar6;
      iVar4 = _ftol_nocw();
      uVar1 = *(undefined4 *)(iVar3 + 100);
      uVar2 = *(undefined4 *)(iVar3 + 0x68);
      uVar5 = uVar5 * 0x21 - iVar4;
      puVar7[-2] = *(undefined4 *)(iVar3 + 0x60);
      puVar7[-1] = uVar1;
      local_4 = local_4 + 1;
      *puVar7 = uVar2;
      piVar6 = piVar6 + 1;
      puVar7 = puVar7 + 4;
    } while (local_4 < *(int *)(param_1 + 0x18));
  }
  return (uVar5 >> 0x10) + uVar5;
}


// ==== 0x4211f0 FUN_004211f0

void FUN_004211f0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int in_EAX;
  uint uVar5;
  char local_4;
  
  uVar5 = FUN_00421170(in_EAX);
  if (DAT_0073459c == 0) {
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(uVar5 & 0xffff,0x10,4);
    }
  }
  else {
    FUN_0057c5a0(4);
  }
  piVar2 = DAT_007345d0;
  local_4 = (char)uVar5;
  local_4 = (char)(uVar5 >> 8) + *(char *)(in_EAX + 0x2d0) + local_4;
  if (DAT_007345d0[1] == 0) {
    if (*DAT_007345d0 != 0) {
      if ((*DAT_007345d0 == 0) || (DAT_007345d0[2] != 0)) {
        cVar4 = '\0';
      }
      else {
        cVar4 = FUN_00594220(8,2);
        if (*(int *)(piVar2[0x19] + 0x28) != 0) {
          piVar2[2] = 1;
        }
      }
      uVar3 = DAT_007361f0;
      if (cVar4 != local_4) {
        piVar2[3] = 1;
        FUN_00421c00(uVar3,0xb,0);
      }
    }
  }
  else if (DAT_007345d0[1] != 0) {
    piVar1 = DAT_007345d0 + 0x19;
    FUN_00594120(local_4,8);
    if (*(int *)(*piVar1 + 0x14) * 8 + -0x44 <= *(int *)(*piVar1 + 8)) {
      piVar2[1] = 0;
      return;
    }
  }
  return;
}


// ==== 0x4212f0 FUN_004212f0

float10 FUN_004212f0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int unaff_ESI;
  float *unaff_EDI;
  float10 fVar6;
  float10 fVar7;
  
  fVar1 = *unaff_EDI - *(float *)(unaff_ESI + 0x280);
  fVar2 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x284);
  fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2);
  fVar2 = *unaff_EDI - *(float *)(unaff_ESI + 0x290);
  fVar3 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x294);
  fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3);
  cVar5 = FUN_0043a2e0();
  if ((cVar5 == '\0') || (*(int *)(unaff_ESI + 0x1c) < 3)) {
    if (fVar2 <= fVar1) {
      return (float10)fVar2;
    }
  }
  else {
    fVar6 = (float10)*unaff_EDI - (float10)*(float *)(unaff_ESI + 0x2a0);
    fVar7 = (float10)unaff_EDI[1] - (float10)*(float *)(unaff_ESI + 0x2a4);
    fVar6 = SQRT(fVar6 * fVar6 + fVar7 * fVar7);
    fVar3 = *unaff_EDI - *(float *)(unaff_ESI + 0x2b0);
    fVar4 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x2b4);
    fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
    if ((float10)fVar3 <= fVar6) {
      fVar6 = (float10)fVar3;
    }
    if ((float10)fVar2 < fVar6) {
      fVar6 = (float10)fVar2;
    }
    if (fVar6 <= (float10)fVar1) {
      return fVar6;
    }
  }
  return (float10)fVar1;
}


// ==== 0x421400 FUN_00421400

float10 FUN_00421400(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int unaff_ESI;
  float *unaff_EDI;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  fVar1 = *unaff_EDI - *(float *)(unaff_ESI + 0x280);
  fVar3 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x284);
  fVar2 = unaff_EDI[2] - *(float *)(unaff_ESI + 0x288);
  fVar1 = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);
  fVar2 = *unaff_EDI - *(float *)(unaff_ESI + 0x290);
  fVar4 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x294);
  fVar3 = unaff_EDI[2] - *(float *)(unaff_ESI + 0x298);
  fVar2 = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
  cVar6 = FUN_0043a2e0();
  if ((cVar6 == '\0') || (*(int *)(unaff_ESI + 0x1c) < 3)) {
    if (fVar2 <= fVar1) {
      return (float10)fVar2;
    }
  }
  else {
    fVar7 = (float10)*unaff_EDI - (float10)*(float *)(unaff_ESI + 0x2a0);
    fVar8 = (float10)unaff_EDI[1] - (float10)*(float *)(unaff_ESI + 0x2a4);
    fVar9 = (float10)unaff_EDI[2] - (float10)*(float *)(unaff_ESI + 0x2a8);
    fVar7 = SQRT(fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9);
    fVar3 = *unaff_EDI - *(float *)(unaff_ESI + 0x2b0);
    fVar5 = unaff_EDI[1] - *(float *)(unaff_ESI + 0x2b4);
    fVar4 = unaff_EDI[2] - *(float *)(unaff_ESI + 0x2b8);
    fVar3 = SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4);
    if ((float10)fVar3 <= fVar7) {
      fVar7 = (float10)fVar3;
    }
    if ((float10)fVar2 < fVar7) {
      fVar7 = (float10)fVar2;
    }
    if (fVar7 <= (float10)fVar1) {
      return fVar7;
    }
  }
  return (float10)fVar1;
}


// ==== 0x421550 FUN_00421550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00421550(float param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int unaff_ESI;
  float10 fVar4;
  float10 fVar5;
  
  fVar1 = *(float *)(unaff_ESI + 0x2c0) - param_1;
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
  fVar1 = ABS(fVar1);
  fVar2 = *(float *)(unaff_ESI + 0x2c4) - param_1;
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if (DAT_007372b0 * -0.5 <= fVar2) {
      if (DAT_007372b0 * _K_HALF < fVar2) {
        fVar2 = fVar2 - DAT_007372b0;
      }
    }
    else {
      fVar2 = fVar2 + DAT_007372b0;
    }
  }
  fVar2 = ABS(fVar2);
  cVar3 = FUN_0043a2e0();
  if ((cVar3 == '\0') || (*(int *)(unaff_ESI + 0x1c) < 3)) {
    if (fVar2 <= fVar1) {
      return (float10)fVar2;
    }
  }
  else {
    fVar4 = (float10)TrackPath__WrapDistance(*(undefined4 *)(unaff_ESI + 0x2c8),param_1);
    fVar5 = (float10)TrackPath__WrapDistance(*(undefined4 *)(unaff_ESI + 0x2cc),param_1);
    fVar5 = ABS(fVar5);
    if ((float10)(float)ABS(fVar4) < fVar5) {
      fVar5 = (float10)(float)ABS(fVar4);
    }
    if ((float10)fVar2 < fVar5) {
      fVar5 = (float10)fVar2;
    }
    if (fVar5 <= (float10)fVar1) {
      return fVar5;
    }
  }
  return (float10)fVar1;
}


// ==== 0x4216b0 FUN_004216b0

uint FUN_004216b0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EDI;
  
  uVar1 = *(uint *)(unaff_EDI + 0x2d0);
  uVar2 = uVar1 ^ 0x1d872b41;
  uVar3 = uVar2 >> 5 ^ uVar2;
  *(uint *)(unaff_EDI + 0x2d0) = uVar3 << 0x1b ^ uVar3 ^ uVar2;
  return uVar1 % param_1;
}


// ==== 0x4216f0 FUN_004216f0

/* WARNING: Removing unreachable block (ram,0x0042172b) */

float10 FUN_004216f0(float param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 0x2d0);
  uVar3 = uVar1 ^ 0x1d872b41;
  uVar2 = uVar3 >> 5 ^ uVar3;
  *(uint *)(unaff_ESI + 0x2d0) = uVar2 << 0x1b ^ uVar2 ^ uVar3;
  return (float10)(uVar1 % 0x7fffffff) * (float10)4.656613e-10 * (float10)param_1;
}


// ==== 0x421740 FUN_00421740

void FUN_00421740(void)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  iVar4 = DAT_00700e64;
  if (DAT_007361fc != 0) {
    if (-1 < DAT_00700e64) {
      piVar3 = (int *)(in_EAX + 0x98c);
      iVar5 = 0x14;
      do {
        if (piVar3[-400] != 0) {
          *(undefined4 *)(piVar3[-400] + 0x10) = 0;
        }
        if (*piVar3 != 0) {
          *(undefined4 *)(*piVar3 + 0x10) = 0;
        }
        piVar3 = piVar3 + 0x14;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (iVar4 <= *(int *)(in_EAX + 0x1790)) {
        cVar1 = *(char *)(iVar4 + 0x1228 + in_EAX);
        cVar2 = *(char *)(iVar4 + 0x1200 + in_EAX);
        FUN_00455760(local_30);
        FUN_00455760(local_20);
        FUN_0045a930(cVar2 * 0x50 + 0x300 + in_EAX);
        FUN_0045a930(cVar1 * 0x50 + 0x940 + in_EAX);
      }
    }
    if (DAT_00736210 != 0) {
      FUN_00455c50(&DAT_0077a4b0,in_EAX + 0x15d0);
      return;
    }
    if (DAT_00736214 != 0) {
      FUN_00455c50(&DAT_0077a4b0,in_EAX + 0x1250);
      return;
    }
    if (DAT_00736218 != 0) {
      FUN_00455c50(&DAT_0077a4b0,in_EAX + 0x1410);
      return;
    }
    if (DAT_00700e68 != -1) {
      iVar4 = FUN_0041ffe0();
      FUN_00455c50(&DAT_0077a4b0,*(int *)(iVar4 + 0x30) + 0x10);
    }
  }
  return;
}


// ==== 0x4218a0 FUN_004218a0

void FUN_004218a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((DAT_007361f8 != 0) && (iVar3 = 0, 0 < *(int *)(DAT_007361f8 + 0x18))) {
    iVar4 = 0x28;
    iVar2 = DAT_007361f8;
    do {
      if ((*(int *)(*(int *)(iVar4 + iVar2) + 0x24) == 1) &&
         (iVar1 = (**(code **)(**(int **)(*(int *)(iVar4 + iVar2) + 0x30) + 0xc))(),
         iVar2 = DAT_007361f8, iVar1 == param_1)) {
        FUN_004617d0();
        iVar2 = DAT_007361f8;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < *(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x421900 FUN_00421900

void FUN_00421900(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  bool bVar5;
  
  piVar1 = (int *)*unaff_EDI;
  iVar3 = DAT_007349b4;
  while (piVar1 != unaff_EDI) {
    iVar4 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    iVar4 = *(int *)(iVar3 + 0x18);
    *piVar1 = *(int *)(iVar3 + 0x10);
    *(int **)(iVar3 + 0x10) = piVar1;
    iVar4 = iVar4 + -1;
    bVar5 = DAT_007349b8 != 0;
    *(int *)(iVar3 + 0x18) = iVar4;
    if (bVar5) {
      if (iVar4 == 0) {
        SlotPool__Destroy();
        iVar3 = 0;
        DAT_007349b4 = 0;
      }
      else {
        DAT_007349b8 = 1;
      }
    }
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x421960 FUN_00421960

undefined4 FUN_00421960(void)

{
  undefined4 *in_EAX;
  
  return *in_EAX;
}


// ==== 0x421970 FUN_00421970

int FUN_00421970(void)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    return in_EAX + -0x250;
  }
  return 0;
}


// ==== 0x421980 FUN_00421980

void FUN_00421980(void)

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
    FUN_00425990(_Memory);
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4219b0 FUN_004219b0

void FUN_004219b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = DAT_00736088;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00465700();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x4219f0 FUN_004219f0

void FUN_004219f0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00735fe4;
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


// ==== 0x421a30 SpecialCamCooldown

/* [canon] camera I (C) docs/re/camera.md */

undefined4 SpecialCamCooldown(void)

{
  int *in_EAX;
  
  if ((*in_EAX != 0) && (*in_EAX != 0x7fffffff)) {
    return 1;
  }
  return 0;
}


// ==== 0x421a50 FUN_00421a50

undefined4 FUN_00421a50(void)

{
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x54) == '\0') && (DAT_007361a8 == 0)) {
    return 0;
  }
  return 1;
}


// ==== 0x421a70 FUN_00421a70

int FUN_00421a70(void)

{
  int in_EAX;
  
  return in_EAX + 0x10;
}


// ==== 0x421a80 FUN_00421a80

bool FUN_00421a80(void)

{
  int in_EAX;
  
  return *(char *)(in_EAX + 0x734) != '\0';
}


// ==== 0x421a90 FUN_00421a90

int FUN_00421a90(void)

{
  int in_EAX;
  
  return in_EAX + 0x14;
}


// ==== 0x421aa0 FUN_00421aa0

undefined4 FUN_00421aa0(void)

{
  int in_EAX;
  
  if (*(float *)(in_EAX + 0x24) <= *(float *)(in_EAX + 0x2c)) {
    return 1;
  }
  return 0;
}


// ==== 0x421ac0 FUN_00421ac0

undefined4 FUN_00421ac0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00439930();
  return *(undefined4 *)(param_1 + 0x18c + iVar1 * 4);
}


// ==== 0x421ae0 FUN_00421ae0

void FUN_00421ae0(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_00421bc0(2,*in_EAX);
  FUN_00421bc0(1,param_1);
  FUN_00421bc0(3,0);
  return;
}


// ==== 0x421b10 FUN_00421b10

void FUN_00421b10(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((int *)param_1[2] != param_1 + 2) {
    do {
      piVar1 = (int *)param_1[2];
      iVar2 = *piVar1;
      piVar3 = (int *)piVar1[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      param_1[4] = 1;
      if (piVar1[2] == 1) {
        *param_1 = piVar1[3];
        param_1[1] = DAT_0073ad3c;
      }
      (*(code *)(&PTR_Race__OnFlowMessage_00700db8)[*param_1])(piVar1[2],piVar1[3]);
      if (piVar1[2] == 2) {
        *param_1 = 0;
      }
      iVar4 = DAT_007361f4;
      param_1[4] = 0;
      iVar2 = *(int *)(iVar4 + 0x18);
      *piVar1 = *(int *)(iVar4 + 0x10);
      *(int *)(iVar4 + 0x18) = iVar2 + -1;
      *(int **)(iVar4 + 0x10) = piVar1;
    } while ((int *)param_1[2] != param_1 + 2);
  }
  return;
}


// ==== 0x421bc0 FUN_00421bc0

void FUN_00421bc0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar2 = (int *)FUN_00567160();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = param_1;
    piVar2[3] = param_2;
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 0xc);
  *puVar1 = piVar2;
  *(int **)(unaff_ESI + 0xc) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = unaff_ESI + 8;
  if (*(int *)(unaff_ESI + 0x10) == 0) {
    FUN_00421b10(unaff_ESI);
  }
  return;
}


// ==== 0x421c00 FUN_00421c00

void FUN_00421c00(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00567160();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = param_2;
    piVar2[3] = param_3;
  }
  piVar1 = *(int **)(param_1 + 0xc);
  *piVar1 = (int)piVar2;
  *(int **)(param_1 + 0xc) = piVar2;
  piVar2[1] = (int)piVar1;
  *piVar2 = param_1 + 8;
  return;
}


// ==== 0x421c40 FUN_00421c40

undefined4 __fastcall FUN_00421c40(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) || (*(int *)(iVar1 + 0x1c) == 0)) &&
     ((*(int *)(param_1 + 0x40) == 0 || (*(int *)(*(int *)(param_1 + 0x40) + 0x1c) == 0)))) {
    return 0;
  }
  return 1;
}


// ==== 0x421c70 FUN_00421c70

undefined4 * FUN_00421c70(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006896cb;
  local_c = ExceptionList;
  puVar1 = param_1 + 2;
  ExceptionList = &local_c;
  param_1[1] = 0;
  *puVar1 = puVar1;
  param_1[3] = puVar1;
  local_4 = 0;
  param_1[4] = 0;
  *param_1 = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  DAT_007361f4 = (undefined4 *)FUN_00566dc0(0x10,"RCQueuedMessageSlotPool",0);
  if (DAT_007361f4 == (undefined4 *)0x0) {
    DAT_007361f4 = (undefined4 *)0x0;
  }
  else if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007361f4;
    puVar1 = DAT_007361f4;
    DAT_007361f4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007361f4 = &DAT_0073d818;
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 1;
  param_1[0x12] = 0;
  param_1[7] = 0xffffffff;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  FUN_00421f00(param_1);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x26] = 0;
  param_1[0x2a] = 0;
  param_1[0x25] = 0;
  param_1[0x24] = 0;
  param_1[0x2b] = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x421d60 FUN_00421d60

void FUN_00421d60(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006896cb;
  local_c = ExceptionList;
  iVar2 = *param_1;
  local_4 = 0;
  ExceptionList = &local_c;
  if (iVar2 != 0) {
    ExceptionList = &local_c;
    piVar4 = (int *)FUN_00567160();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[2] = 2;
      piVar4[3] = iVar2;
    }
    puVar3 = (undefined4 *)param_1[3];
    piVar1 = param_1 + 2;
    *puVar3 = piVar4;
    param_1[3] = (int)piVar4;
    piVar4[1] = (int)puVar3;
    *piVar4 = (int)piVar1;
    if (param_1[4] == 0) {
      FUN_00421b10(param_1);
    }
    piVar4 = (int *)FUN_00567160();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[2] = 1;
      piVar4[3] = 0;
    }
    puVar3 = (undefined4 *)param_1[3];
    *puVar3 = piVar4;
    param_1[3] = (int)piVar4;
    piVar4[1] = (int)puVar3;
    *piVar4 = (int)piVar1;
    if (param_1[4] == 0) {
      FUN_00421b10(param_1);
    }
    piVar4 = (int *)FUN_00567160();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[2] = 3;
      piVar4[3] = 0;
    }
    puVar3 = (undefined4 *)param_1[3];
    *puVar3 = piVar4;
    param_1[3] = (int)piVar4;
    piVar4[1] = (int)puVar3;
    *piVar4 = (int)piVar1;
    if (param_1[4] == 0) {
      FUN_00421b10(param_1);
    }
  }
  FUN_00422130();
  FUN_004244b0();
  SlotPool__Destroy();
  FUN_00424b10();
  ExceptionList = local_c;
  return;
}


// ==== 0x421e80 FUN_00421e80

void FUN_00421e80(void)

{
  char cVar1;
  int unaff_ESI;
  int iVar2;
  
  FUN_00571ea0(0,"RaceCoordinator");
  FUN_0041fc00(DAT_007361f8);
  FUN_004343f0();
  iVar2 = 0;
  if (0 < DAT_007361c4) {
    do {
      FUN_0042bd60((&DAT_007361bc)[iVar2],unaff_ESI);
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_007361c4);
  }
  iVar2 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar2 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar2 + 0xc);
  cVar1 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x421f00 FUN_00421f00

void FUN_00421f00(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  undefined4 *puVar7;
  short *psVar8;
  int iVar9;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006897a6;
  local_c = ExceptionList;
  iVar4 = 0;
  if (0 < DAT_0073616c) {
    psVar8 = (short *)(DAT_00736168 + 0x6c);
    do {
      if (*psVar8 == DAT_0078a2f0) break;
      iVar4 = iVar4 + 1;
      psVar8 = psVar8 + 0x7e;
    } while (iVar4 < DAT_0073616c);
  }
  ExceptionList = &local_c;
  pvVar5 = _malloc(0x50b8);
  if (pvVar5 == (void *)0x0) {
    DAT_007345d0 = 0;
  }
  else {
    DAT_007345d0 = FUN_00571fa0();
  }
  pvVar5 = _malloc(0x568);
  local_4 = 0;
  if (pvVar5 == (void *)0x0) {
    DAT_0073619c = 0;
  }
  else {
    DAT_0073619c = FUN_00434270();
  }
  pvVar5 = _malloc(0x17a0);
  iVar4 = 1;
  local_4 = 1;
  if (pvVar5 != (void *)0x0) {
    FUN_0041f6e0(pvVar5);
  }
  local_4 = 0xffffffff;
  Grid__PlaceAllRacers(param_1);
  FUN_004222a0(param_1);
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  puVar3 = DAT_00734440;
  if (DAT_0078a308 == '\0') {
    if (DAT_0078a309 == '\0') {
      if ((DAT_0073465c == 0) && (param_1[0x11] == 0)) {
        iVar9 = 4;
        iVar4 = 3;
      }
      else {
        iVar9 = 2;
      }
    }
    else {
      iVar9 = 10;
      iVar4 = 4;
    }
  }
  else {
    iVar9 = 9;
    iVar4 = 4;
    if (DAT_00734440 != (undefined1 *)0x0) {
      FUN_0059e020();
      *puVar3 = 0;
    }
  }
  param_1[6] = iVar4;
  FUN_00434590(0);
  FUN_00456ba0();
  FUN_0051f8a0(DAT_007356a8,iVar9);
  DAT_007361f0 = param_1;
  FUN_004abaa0();
  iVar4 = *param_1;
  param_1[0x11] = 0;
  param_1[5] = iVar9;
  piVar6 = (int *)FUN_00567160();
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6[2] = 2;
    piVar6[3] = iVar4;
  }
  puVar7 = (undefined4 *)param_1[3];
  piVar1 = param_1 + 2;
  *puVar7 = piVar6;
  param_1[3] = (int)piVar6;
  piVar6[1] = (int)puVar7;
  *piVar6 = (int)piVar1;
  if (param_1[4] == 0) {
    FUN_00421b10(param_1);
  }
  puVar7 = (undefined4 *)FUN_00567160();
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7[2] = 1;
    puVar7[3] = 1;
  }
  puVar2 = (undefined4 *)param_1[3];
  *puVar2 = puVar7;
  param_1[3] = (int)puVar7;
  puVar7[1] = puVar2;
  *puVar7 = piVar1;
  if (param_1[4] == 0) {
    FUN_00421b10(param_1);
  }
  puVar7 = (undefined4 *)FUN_00567160();
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7[2] = 3;
    puVar7[3] = 0;
  }
  puVar2 = (undefined4 *)param_1[3];
  *puVar2 = puVar7;
  param_1[3] = (int)puVar7;
  puVar7[1] = puVar2;
  *puVar7 = piVar1;
  if (param_1[4] == 0) {
    FUN_00421b10(param_1);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x422130 FUN_00422130

void FUN_00422130(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_EDI;
  int local_8;
  
  if (*(undefined4 **)(unaff_EDI + 0x38) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x38))(1);
    *(undefined4 *)(unaff_EDI + 0x38) = 0;
  }
  if (*(undefined4 **)(unaff_EDI + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x34))(1);
    *(undefined4 *)(unaff_EDI + 0x34) = 0;
  }
  if (*(undefined4 **)(unaff_EDI + 0x3c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x3c))(1);
    *(undefined4 *)(unaff_EDI + 0x3c) = 0;
  }
  if (*(undefined4 **)(unaff_EDI + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x40))(1);
    *(undefined4 *)(unaff_EDI + 0x40) = 0;
  }
  local_8 = 0;
  if (0 < DAT_007361c4) {
    do {
      FUN_00431100();
      local_8 = local_8 + 1;
    } while (local_8 < DAT_007361c4);
  }
  FUN_00422b70(unaff_EDI);
  FUN_00402cf0(&DAT_0078e9e0);
  pvVar1 = DAT_0073619c;
  if (DAT_0073619c != (void *)0x0) {
    if (*(void **)((int)DAT_0073619c + 0x564) != (void *)0x0) {
      _free(*(void **)((int)DAT_0073619c + 0x564));
    }
    DAT_0073619c = (void *)0x0;
    _free(pvVar1);
  }
  pvVar1 = DAT_007361f8;
  DAT_0073619c = (void *)0x0;
  if (DAT_007361f8 != (void *)0x0) {
    FUN_0041f9b0(DAT_007361f8);
    _free(pvVar1);
  }
  pvVar1 = DAT_007345d0;
  DAT_007361f8 = (void *)0x0;
  if (DAT_007345d0 != (void *)0x0) {
    FUN_005720f0(DAT_007345d0);
    _free(pvVar1);
  }
  pvVar1 = *(void **)(unaff_EDI + 0x48);
  DAT_007345d0 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    if (DAT_00735ed0 != (undefined4 *)0x0) {
      (**(code **)*DAT_00735ed0)(1);
    }
    DAT_00735ed0 = (undefined4 *)0x0;
    _free(pvVar1);
  }
  iVar2 = DAT_007361c4;
  *(undefined4 *)(unaff_EDI + 0x48) = 0;
  while (iVar2 != 0) {
    pvVar1 = (void *)(&DAT_007361b8)[iVar2];
    if (pvVar1 != (void *)0x0) {
      FUN_0042bb60(pvVar1);
      _free(pvVar1);
      iVar2 = DAT_007361c4;
    }
  }
  FUN_00444590();
  return;
}


// ==== 0x4222a0 FUN_004222a0

void FUN_004222a0(void)

{
  undefined4 uVar1;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688666;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (((((-1 < DAT_0078a410) &&
        (ExceptionList = &local_c, pcVar2 = (char *)FUN_004327d0(), pcVar2 != (char *)0x0)) &&
       (*(int *)(pcVar2 + 4) == 1)) && (*pcVar2 < '\x01')) || (DAT_0078a308 != '\0')) {
    uVar1 = DAT_0078a348;
    pvVar3 = _malloc(0xa70);
    local_4 = 0;
    if (pvVar3 != (void *)0x0) {
      FUN_0042b0d0(pvVar3,uVar1,0);
    }
    local_4 = 0xffffffff;
  }
  if (((-1 < DAT_0078a414) &&
      (pcVar2 = (char *)FUN_004327d0(), uVar1 = DAT_0078a34c, pcVar2 != (char *)0x0)) &&
     ((*(int *)(pcVar2 + 4) == 1 && (*pcVar2 < '\x01')))) {
    pvVar3 = _malloc(0xa70);
    local_4 = 1;
    if (pvVar3 != (void *)0x0) {
      FUN_0042b0d0(pvVar3,uVar1,1);
    }
    local_4 = 0xffffffff;
  }
  local_14 = 0;
  iVar6 = DAT_007361f8;
  if (0 < DAT_007361c4) {
    do {
      if (DAT_0078a308 == '\0') {
        iVar4 = 0;
        if (0 < *(int *)(iVar6 + 0x18)) {
          piVar5 = (int *)(iVar6 + 0x28);
          do {
            if ((int)*(short *)(*piVar5 + 10) ==
                (&DAT_0078a410)[*(int *)((&DAT_007361bc)[local_14] + 0x10)]) goto LAB_0042239c;
            iVar4 = iVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar4 < *(int *)(iVar6 + 0x18));
        }
      }
      else {
LAB_0042239c:
        FUN_00431020((&DAT_007361bc)[local_14]);
        iVar6 = DAT_007361f8;
      }
      local_14 = local_14 + 1;
    } while (local_14 < DAT_007361c4);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x422410 Grid::BuildRacerCar

/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void Grid__BuildRacerCar(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006869e3;
  local_c = ExceptionList;
  uVar1 = *(undefined2 *)(param_2 + 0x10);
  ExceptionList = &local_c;
  RideInfo__RebuildPhysicsInfo(1);
  iVar3 = FindPartWithLevel(0xc,*(undefined4 *)(param_1 + 0x20));
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x48c) = iVar3;
    *(char *)(param_1 + 0x648) = *(char *)(param_1 + 0x648) + '\x01';
    RideInfo__UpdatePartsEnabled(param_1 + 0x10);
  }
  TrackPath__UpdateCursor(&DAT_007372b0,param_2);
  pvVar4 = _malloc(0x8f0);
  local_4 = 0;
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00425350(pvVar4,param_1,param_2,uVar1,0);
  }
  local_4 = 0xffffffff;
  FUN_00425fe0();
  if (param_3 == 3) {
    FUN_00425150();
    Car_SetMode();
    *(undefined4 *)(piVar5[0xc] + 0x1fc) = *(undefined4 *)(&DAT_006b7c20 + DAT_0078a40c * 4);
  }
  else {
    Car_SetMode();
  }
  iVar3 = DAT_007361f8;
  puVar2 = *(undefined4 **)(DAT_007361f8 + 4);
  *puVar2 = piVar5;
  *(int **)(iVar3 + 4) = piVar5;
  piVar5[1] = (int)puVar2;
  *piVar5 = iVar3;
  if (param_3 == 3) {
    HudWidget__RegisterObject(piVar5);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x422580 Grid::GetStartPositions

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals V (Ghidra+capstone) docs/re/rivals.md */

void Grid__GetStartPositions(int param_1,int param_2)

{
  byte *pbVar1;
  float *pfVar2;
  int *piVar3;
  float fVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  float *pfVar16;
  bool bVar17;
  float10 fVar18;
  undefined4 uVar19;
  int local_32c;
  float local_324 [17];
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
  iVar9 = -1;
  if (DAT_0078a2fc == 0) {
    pcVar11 = "ForwardStartingPosition";
    uVar15 = 0x46;
    do {
      iVar9 = iVar9 * 0x21 + uVar15;
      pbVar1 = (byte *)(pcVar11 + 1);
      uVar15 = (uint)*pbVar1;
      pcVar11 = pcVar11 + 1;
    } while (*pbVar1 != 0);
  }
  else {
    pcVar11 = "BackwardStartingPosition";
    uVar15 = 0x42;
    do {
      iVar9 = iVar9 * 0x21 + uVar15;
      pbVar1 = (byte *)(pcVar11 + 1);
      uVar15 = (uint)*pbVar1;
      pcVar11 = pcVar11 + 1;
    } while (*pbVar1 != 0);
  }
  ExceptionList = &local_1c;
  iVar6 = TrackMarker_Count(iVar9);
  if (iVar6 < param_1) {
LAB_00422675:
    local_324[7] = 0.0;
    local_324[8] = 0.0;
    fVar4 = 0.0;
    local_324[9] = 0.0;
    local_324[10] = 0.0;
    local_324[0xb] = 0.0;
    local_324[0xc] = 0.0;
    local_324[0xd] = 1.0;
    local_324[0xe] = 0.0;
    local_324[0xf] = 0.0;
    local_324[0x10] = 0.0;
    do {
      fVar4 = fVar4 + 10.0;
      FUN_00443c90(&DAT_007372b0,fVar4,0);
    } while (fVar4 < 100.0);
    uVar15 = 0;
    if (0 < param_1) {
      puVar14 = (undefined4 *)(param_2 + 8);
      do {
        uVar8 = uVar15 & 0x80000001;
        bVar17 = uVar8 == 0;
        if ((int)uVar8 < 0) {
          bVar17 = (uVar8 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (bVar17) {
          uVar19 = 0x40400000;
        }
        else {
          local_324[0] = -3.0;
          uVar19 = 0xc0400000;
        }
        FUN_00443c90(&DAT_007372b0,(float)((int)uVar15 / 2) * 17.0 + 100.0,uVar19);
        puVar14[-2] = local_324[7];
        puVar14[-1] = local_324[8];
        *puVar14 = 0;
        uVar5 = Atan2ToAngle16(local_324[0xd],local_324[0xe]);
        *(undefined2 *)(puVar14 + 2) = uVar5;
        uVar15 = uVar15 + 1;
        puVar14 = puVar14 + 8;
      } while ((int)uVar15 < param_1);
    }
  }
  else {
    local_324[0] = 0.0;
    if (0 < param_1) {
      puVar14 = (undefined4 *)(param_2 + 8);
LAB_00422620:
      iVar13 = 0;
      if (0 < iVar6) {
        puVar7 = (undefined4 *)NullUpdate_ret();
        do {
          iVar12 = 0;
          for (puVar10 = DAT_0077b190; puVar10 != puVar7; puVar10 = (undefined4 *)*puVar10) {
            if (puVar10[2] == iVar9) {
              if (iVar12 == iVar13) goto LAB_0042265d;
              iVar12 = iVar12 + 1;
            }
          }
          puVar10 = (undefined4 *)0x0;
LAB_0042265d:
          if ((float)puVar10[3] == local_324[0]) goto LAB_0042275a;
          iVar13 = iVar13 + 1;
          if (iVar6 <= iVar13) break;
        } while( true );
      }
      goto LAB_00422675;
    }
  }
LAB_00422808:
  if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
    local_324[1] = 0.0;
    local_324[2] = 0.0;
    local_324[3] = 0.0;
    local_324[4] = 0.0;
    local_324[DAT_0078a334] = _DAT_0078a3b8;
    if (1 < DAT_0078a320) {
      local_324[DAT_0078a335] = _DAT_0078a3f0;
    }
    fVar4 = 0.0;
    iVar9 = 0;
    if (3 < param_1) {
      iVar6 = 3;
      do {
        if (fVar4 <= local_324[iVar9 + 1]) {
          fVar4 = local_324[iVar9 + 1];
        }
        if (fVar4 <= local_324[iVar9 + 2]) {
          fVar4 = local_324[iVar9 + 2];
        }
        if (fVar4 <= local_324[iVar9 + 3]) {
          fVar4 = local_324[iVar9 + 3];
        }
        if (fVar4 <= local_324[iVar9 + 4]) {
          fVar4 = local_324[iVar9 + 4];
        }
        iVar6 = iVar6 + 4;
        iVar9 = iVar9 + 4;
      } while (iVar6 < param_1);
    }
    for (; iVar9 < param_1; iVar9 = iVar9 + 1) {
      if (fVar4 <= local_324[iVar9 + 1]) {
        fVar4 = local_324[iVar9 + 1];
      }
    }
    iVar9 = 0;
    if (0 < param_1) {
      do {
        iVar6 = iVar9 + 1;
        iVar9 = iVar9 + 1;
        local_324[iVar9] = local_324[iVar6] - fVar4;
      } while (iVar9 < param_1);
    }
    local_32c = 0;
    if (0 < param_1) {
      pfVar16 = (float *)(param_2 + 8);
      do {
        pfVar2 = pfVar16 + -2;
        local_324[9] = 0.0;
        local_324[0xf] = 0.0;
        local_324[0x10] = 0.0;
        local_324[7] = 0.0;
        local_324[8] = 0.0;
        local_324[10] = 0.0;
        local_324[0xb] = 0.0;
        local_324[0xc] = 0.0;
        local_324[0xd] = 1.0;
        local_324[0xe] = 0.0;
        TrackPath__UpdateCursor(&DAT_007372b0,pfVar2);
        fVar4 = local_324[local_32c + 1];
        local_32c = local_32c + 1;
        *pfVar2 = local_324[0xd] * fVar4 + *pfVar2;
        *pfVar16 = local_324[3] * fVar4 + *pfVar16;
        pfVar16[-1] = local_324[0xe] * fVar4 + pfVar16[-1];
        pfVar16 = pfVar16 + 8;
      } while (local_32c < param_1);
    }
  }
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  FUN_00440740();
  if (0 < param_1) {
    do {
      fVar18 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,param_2,0,0,0);
      *(float *)(param_2 + 8) = (float)fVar18;
      param_2 = param_2 + 0x20;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  iVar9 = 0;
  if (0 < local_40) {
    do {
      piVar3 = aiStack_2c0 + iVar9;
      iVar9 = iVar9 + 1;
      *(char *)(*piVar3 + 8) = *(char *)(*piVar3 + 8) + -1;
    } while (iVar9 < local_40);
  }
  ExceptionList = local_1c;
  return;
LAB_0042275a:
  puVar14[-2] = puVar10[4];
  puVar14[-1] = puVar10[5];
  *puVar14 = puVar10[6];
  local_324[0] = (float)((int)local_324[0] + 1);
  *(undefined2 *)(puVar14 + 2) = *(undefined2 *)(puVar10 + 8);
  puVar14 = puVar14 + 8;
  if (param_1 <= (int)local_324[0]) goto LAB_00422808;
  goto LAB_00422620;
}


// ==== 0x422a70 Grid::PlaceAllRacers

/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void Grid__PlaceAllRacers(void)

{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 local_90 [140];
  
  Grid__GetStartPositions(4,local_90);
  iVar7 = 1;
  puVar5 = local_90;
  do {
    iVar4 = 0;
    pcVar2 = DAT_0078a418;
    if (0 < DAT_0078a41c) {
      do {
        if ((*pcVar2 < '\x01') && (pcVar2[3] == iVar7)) {
          if (pcVar2[0x734] == '\0') {
            if (*(int *)(pcVar2 + 4) == 1) {
              uVar9 = 1;
            }
            else {
              if (*(int *)(pcVar2 + 4) != 2) break;
              uVar9 = 3;
            }
          }
          else {
            uVar9 = 0;
          }
          Grid__BuildRacerCar(pcVar2,puVar5,uVar9);
          break;
        }
        iVar4 = iVar4 + 1;
        pcVar2 = pcVar2 + 0x750;
      } while (iVar4 < DAT_0078a41c);
    }
    iVar4 = DAT_007361f8;
    iVar7 = iVar7 + 1;
    puVar5 = puVar5 + 0x20;
    if (4 < iVar7) {
      FUN_0041fe50();
      iVar7 = 0;
      if (0 < DAT_0078a41c) {
        iVar8 = 0;
        do {
          iVar6 = iVar4;
          if ((*(int *)(DAT_0078a418 + iVar8 + 4) == 3) &&
             (piVar3 = (int *)TrafficTeleporter__PlaceCar(DAT_0078a418 + iVar8),
             iVar6 = DAT_007361f8, piVar3 != (int *)0x0)) {
            piVar1 = *(int **)(iVar4 + 4);
            *piVar1 = (int)piVar3;
            *(int **)(iVar4 + 4) = piVar3;
            piVar3[1] = (int)piVar1;
            *piVar3 = iVar4;
            iVar6 = DAT_007361f8;
          }
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x750;
          iVar4 = iVar6;
        } while (iVar7 < DAT_0078a41c);
      }
      FUN_0041fe50();
      return;
    }
  } while( true );
}


// ==== 0x422b70 FUN_00422b70

void FUN_00422b70(void)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  _Memory = (int *)*DAT_007361f8;
  if (_Memory != DAT_007361f8) {
    do {
      iVar1 = *_Memory;
      piVar2 = (int *)_Memory[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      FUN_00425990(_Memory);
      _free(_Memory);
      _Memory = (int *)*DAT_007361f8;
    } while (_Memory != DAT_007361f8);
  }
  return;
}


// ==== 0x422bb0 Race::OnFlowMessage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone) docs/re/gameflow.md */

undefined4 __thiscall Race__OnFlowMessage(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 1:
  case 2:
  case 3:
    return 1;
  default:
    return 0;
  case 8:
    FUN_00422130();
    FUN_00421f00(param_1);
    return 1;
  case 9:
    break;
  case 10:
    FUN_00495e90();
  }
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  DAT_0077a904 = GameFlow__UnloadingTrackSpecific;
  _DAT_0077a90c = "BeginGameFlowUnloadingTrackSpecific";
  return 1;
}


// ==== 0x422c40 FUN_00422c40

void FUN_00422c40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x30) == 0) {
    pvVar1 = _malloc(0x34);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0047e270(*(undefined4 *)(DAT_007361bc + 4));
      *(undefined4 *)(unaff_ESI + 0x30) = uVar2;
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
  }
  return;
}


// ==== 0x422c80 FUN_00422c80

undefined4 __thiscall FUN_00422c80(undefined4 *param_1,undefined4 param_2)

{
  switch(param_2) {
  case 1:
    FUN_00422c40();
switchD_00422c98_caseD_d:
    return 1;
  case 2:
    if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xc])(1);
    }
    param_1[0xc] = 0;
    return 1;
  case 3:
    if (DAT_006f1df8 < (float)*(int *)(DAT_0073619c + 0x14) * 0.00025) {
      FUN_00421ae0(0);
      FUN_00421bc0(10,0);
    }
    return 1;
  case 4:
  case 10:
    FUN_00421bc0(2,*param_1);
    FUN_00421bc0(1,0);
    FUN_00421bc0(3,0);
    FUN_00421bc0(10,0);
    return 1;
  default:
    return 0;
  case 0xd:
    goto switchD_00422c98_caseD_d;
  }
}


// ==== 0x422d70 FUN_00422d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00422d70(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  
  switch(param_2) {
  case 1:
    FUN_005732e0(&DAT_0073c17c);
    FUN_00422c40();
    return 1;
  case 2:
    if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xc])(1);
    }
    param_1[0xc] = 0;
    DAT_0073c17c = 0;
    _DAT_0073c18c = 0;
    _DAT_0073c190 = 0;
    FUN_00574190();
    return 1;
  case 3:
    cVar1 = FUN_00573370();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_00421ae0(0);
    break;
  case 4:
  case 10:
  case 0xb:
    FUN_00421bc0(2,*param_1);
    FUN_00421bc0(1,0);
    FUN_00421bc0(3,0);
    break;
  default:
    return 0;
  case 0xd:
    return 1;
  case 0xe:
    FUN_00573010();
    if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xc])(1);
      param_1[0xc] = 0;
    }
    FUN_00422c40();
    return 1;
  }
  FUN_00421bc0(10,0);
  return 1;
}


// ==== 0x422eb0 FUN_00422eb0

undefined4 __thiscall FUN_00422eb0(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  switch(param_2) {
  case 1:
    FUN_00444ab0();
    if (*(int *)(param_1 + 0x14) == 8) {
      if (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x3c))(1);
        *(undefined4 *)(param_1 + 0x3c) = 0;
      }
      iVar1 = *(int *)(DAT_007361f8 + 0x28);
      local_1c = *(undefined4 *)(iVar1 + 100);
      local_20 = *(undefined4 *)(iVar1 + 0x60);
      local_18 = *(undefined4 *)(iVar1 + 0x68);
      FUN_0047cac0(&DAT_00779800,&local_24);
      FUN_00427e60(0,0);
      StreamSections__SeedViewer();
      FUN_0047bed0(DAT_0078a2f0);
    }
    else {
      StreamSections__SeedViewer();
      FUN_0047bb10(&DAT_00779800,DAT_0078a2f0);
    }
    if ((DAT_006fb988 != '\0') && (cVar2 = FUN_004f6650(), cVar2 == '\0')) {
      FEManager__ShowPackage();
    }
switchD_00422eca_caseD_4:
    return 1;
  case 2:
    if (DAT_006fb988 != '\0') {
      FUN_004f6240();
    }
    DAT_006fb988 = 1;
    FUN_00434b50(DAT_0073619c,*(undefined4 *)(param_1 + 0x18));
    return 1;
  case 3:
    local_24 = DAT_0073ad3c - *(int *)(param_1 + 4);
    if ((2.0 < (float)local_24 * 0.00025) &&
       (cVar2 = StreamSections__WaitUntilIdle(&DAT_0077a980), cVar2 == '\0')) {
      FUN_004de130();
      FUN_00421ae0(*(undefined4 *)(param_1 + 0x14));
    }
    return 1;
  case 4:
  case 5:
  case 10:
    goto switchD_00422eca_caseD_4;
  default:
    return 0;
  }
}


// ==== 0x423070 FUN_00423070

undefined4 __thiscall FUN_00423070(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  bool bVar9;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar4 = DAT_0073619c;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006869c0;
  local_c = ExceptionList;
  switch(param_2) {
  case 1:
    if (param_1[0xd] == 0) {
      ExceptionList = &local_c;
      pvVar5 = _malloc(0x28);
      if (pvVar5 != (void *)0x0) {
        uVar6 = FUN_0047e9d0();
        param_1[0xd] = uVar6;
        ExceptionList = local_c;
        return 1;
      }
      param_1[0xd] = 0;
    }
    break;
  case 2:
    break;
  case 3:
    if (DAT_00737074 == 0) goto switchD_00423098_caseD_4;
    break;
  case 4:
switchD_00423098_caseD_4:
    iVar7 = 0;
    bVar9 = DAT_0078a368 == 0;
    piVar8 = DAT_0073619c + 9;
    piVar1 = DAT_0073619c + 9;
    ExceptionList = &local_c;
    *DAT_0073619c = 2;
    if (bVar9) {
      if (0 < *piVar8) {
        piVar8 = piVar4 + 0x148;
        do {
          iVar2 = *(int *)*piVar8;
          iVar3 = *(int *)(iVar2 + 0x24);
          if (0 < iVar3) {
            if (iVar3 < 3) {
LAB_004231da:
              if (*piVar4 == 4) {
                (**(code **)(**(int **)(iVar2 + 0x30) + 0x20))();
              }
              else {
LAB_004231ea:
                (**(code **)(**(int **)(iVar2 + 0x30) + 0x1c))();
              }
            }
            else if (iVar3 == 3) {
              iVar3 = *(int *)(iVar2 + 0x30);
              if (*piVar4 == 4) {
                *(undefined4 *)(iVar3 + 0x1e0) = 0;
                *(undefined4 *)(iVar3 + 0x1e4) = 0;
                *(undefined4 *)(iVar3 + 0x1dc) = 0x3f800000;
                goto LAB_004231da;
              }
              goto LAB_004231ea;
            }
          }
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar7 < *piVar1);
      }
    }
    else if (0 < *piVar8) {
      piVar8 = piVar4 + 0x148;
      do {
        iVar2 = *(int *)*piVar8;
        iVar3 = *(int *)(iVar2 + 0x24);
        if (0 < iVar3) {
          if (iVar3 < 3) {
LAB_00423174:
            if (*piVar4 == 4) {
              (**(code **)(**(int **)(iVar2 + 0x30) + 0x20))();
            }
            else {
LAB_00423184:
              (**(code **)(**(int **)(iVar2 + 0x30) + 0x1c))();
            }
          }
          else if (iVar3 == 3) {
            iVar3 = *(int *)(iVar2 + 0x30);
            if (*piVar4 == 4) {
              *(undefined4 *)(iVar3 + 0x1e0) = 0;
              *(undefined4 *)(iVar3 + 0x1e4) = 0;
              *(undefined4 *)(iVar3 + 0x1dc) = 0x3f800000;
              goto LAB_00423174;
            }
            goto LAB_00423184;
          }
        }
        iVar7 = iVar7 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar7 < *piVar1);
    }
    FUN_00421ae0(3);
    ExceptionList = local_c;
    return 1;
  case 5:
    ExceptionList = &local_c;
    param_1[7] = param_3;
    param_1[8] = *param_1;
    FUN_00421ae0(7);
    ExceptionList = local_c;
    return 1;
  default:
    return 0;
  }
  ExceptionList = local_c;
  return 1;
}


// ==== 0x423280 FUN_00423280

undefined4 __thiscall FUN_00423280(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  piVar4 = DAT_0073619c;
  local_8 = 0xffffffff;
  pcStack_c = FUN_006896eb;
  local_10 = ExceptionList;
  switch(param_2) {
  case 1:
    ExceptionList = &local_10;
    if (*(undefined4 **)(param_1 + 0x34) != (undefined4 *)0x0) {
      ExceptionList = &local_10;
      (**(code **)**(undefined4 **)(param_1 + 0x34))(1);
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x40))(1);
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    FUN_0047bae0();
    if (*(int *)(param_1 + 0x3c) == 0) {
      pvVar1 = _malloc(0x30);
      local_8 = 0;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = IntroNisCoordinator(pvVar1,1);
      }
      local_8 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
    }
    if ((*(int *)(*(int *)(param_1 + 0x3c) + 0x20) == 0) ||
       (*(int *)(*(int *)(param_1 + 0x3c) + 0x1c) == 0)) {
      if (*(int *)(param_1 + 0x38) == 0) {
        iVar3 = FindResourceFile("GLOBAL\\PRERACEANIM.LZC");
        if (iVar3 == 0) {
          FUN_00434b50(DAT_0073619c,3);
          FUN_00421ae0(4);
          FUN_00495e20();
          ExceptionList = local_10;
          return 1;
        }
        pvVar1 = _malloc(0xbc);
        if (pvVar1 == (void *)0x0) {
          *(undefined4 *)(param_1 + 0x38) = 0;
          FUN_00495e20();
          ExceptionList = local_10;
          return 1;
        }
        uVar2 = FUN_0047eae0();
        *(undefined4 *)(param_1 + 0x38) = uVar2;
        FUN_00495e20();
        ExceptionList = local_10;
        return 1;
      }
    }
    else if (*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x38))(1);
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    FUN_00495e20();
    ExceptionList = local_10;
    return 1;
  case 2:
    ExceptionList = &local_10;
    if (*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) {
      ExceptionList = &local_10;
      (**(code **)**(undefined4 **)(param_1 + 0x38))(1);
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    iVar3 = FindResourceFile("GLOBAL\\PRERACEANIM.LZC");
    if (iVar3 != 0) {
      UnloadResourceFile();
    }
    ExceptionList = local_10;
    return 1;
  case 3:
    break;
  case 4:
    ExceptionList = &local_10;
    if (DAT_0078a320 == 1) {
      ExceptionList = &local_10;
      FUN_00495ec0();
      piVar4 = DAT_0073619c;
    }
    goto LAB_0042347b;
  case 5:
    *(undefined4 *)(param_1 + 0x1c) = param_3;
    *(undefined1 *)(param_1 + 0x25) = 1;
    return 1;
  default:
    return 0;
  case 10:
    ExceptionList = &local_10;
    FUN_00421ae0(0);
    FUN_00421bc0(10,0);
    ExceptionList = local_10;
    return 1;
  }
  if (*DAT_0073619c != 2) {
    return 1;
  }
  if (*(int *)(param_1 + 0x3c) == 0) {
    return 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x3c) + 0x1c) == 0) {
    ExceptionList = &local_10;
    if (*(int *)(param_1 + 0x38) != 0) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x38) + 0xb8);
      ExceptionList = &local_10;
      goto LAB_00423468;
    }
  }
  else {
    ExceptionList = &local_10;
    iVar3 = FUN_00421aa0();
LAB_00423468:
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return 1;
    }
  }
  if (DAT_0078a320 == 1) {
    FUN_00495ec0();
  }
LAB_0042347b:
  FUN_00434b50(piVar4,3);
  FUN_00421ae0(4);
  ExceptionList = local_10;
  return 1;
}


// ==== 0x423530 FUN_00423530

undefined4 __thiscall FUN_00423530(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068972b;
  local_10 = ExceptionList;
  switch(param_2) {
  case 1:
    if ((undefined4 *)param_1[0xe] != (undefined4 *)0x0) {
      ExceptionList = &local_10;
      (*(code *)**(undefined4 **)param_1[0xe])(1);
      param_1[0xe] = 0;
    }
    break;
  case 2:
  case 0xd:
  case 0xf:
    break;
  case 3:
    ExceptionList = &local_10;
    if (*DAT_0073619c != 4) {
      ExceptionList = &local_10;
      if (param_1[0xf] == 0) {
        ExceptionList = &local_10;
        FUN_0047bae0();
        pvVar1 = _malloc(0x30);
        local_8 = 0;
        if (pvVar1 == (void *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = IntroNisCoordinator(pvVar1,1);
        }
        param_1[0xf] = uVar2;
      }
      local_8 = 0xffffffff;
      if (param_1[0xf] != 0) {
        FUN_0047f310(param_1[0xf]);
      }
      if (*(char *)((int)param_1 + 0x25) != '\0') {
        *(undefined1 *)((int)param_1 + 0x25) = 0;
        param_1[8] = *param_1;
        EAXSound__EnterPauseMenu();
        FUN_00421ae0(7);
      }
    }
    if (param_1[0xf] != 0) {
      uVar4 = FUN_0047f4c0();
      if ((int)uVar4 != 0) {
        (**(code **)*(undefined4 *)((ulonglong)uVar4 >> 0x20))(1);
        param_1[0xf] = 0;
      }
    }
    iVar3 = FUN_00435b30(DAT_0073619c);
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return 1;
    }
    iVar3 = FUN_00435b90(DAT_0073619c);
    if (DAT_006f08a0 <= *(int *)(iVar3 + 0x5c) + *(int *)(iVar3 + 0x58)) {
      ExceptionList = local_10;
      return 1;
    }
    FUN_00423f20();
    ExceptionList = local_10;
    return 1;
  case 4:
    ExceptionList = &local_10;
    iVar3 = FUN_00435b30(DAT_0073619c);
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return 1;
    }
    FUN_00423f20();
    ExceptionList = local_10;
    return 1;
  case 5:
    ExceptionList = &local_10;
    param_1[7] = param_3;
    if (*(char *)(param_1 + 9) == '\0') {
      *(undefined1 *)(param_1 + 9) = 1;
      param_1[8] = *param_1;
      EAXSound__EnterPauseMenu();
      FUN_00421ae0(7);
      ExceptionList = local_10;
      return 1;
    }
  default:
    ExceptionList = pvVar1;
    return 0;
  case 7:
    ExceptionList = &local_10;
    FUN_00421ae0(6);
    ExceptionList = local_10;
    return 1;
  case 9:
    ExceptionList = &local_10;
    FUN_00421ae0(0);
    FUN_00421bc0(9,param_3);
    ExceptionList = local_10;
    return 1;
  case 10:
    ExceptionList = &local_10;
    FUN_00421ae0(0);
    FUN_00421bc0(10,0);
  }
  ExceptionList = local_10;
  return 1;
}


// ==== 0x4237a0 FUN_004237a0

undefined4 __thiscall FUN_004237a0(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  switch(param_2) {
  case 1:
    FEManager__ShowPackage();
    FUN_00416bb0(*(undefined4 *)(param_1 + 0x2c));
switchD_004237b8_caseD_3:
    return 1;
  case 2:
    FUN_004f6240();
    FUN_00431190();
    return 1;
  case 3:
    goto switchD_004237b8_caseD_3;
  default:
    return 0;
  case 0x10:
    FUN_00421ae0(*(undefined4 *)(param_1 + 0x28));
    if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
       (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xa0))();
    }
    FUN_0051eee0(DAT_007356a8);
    return 1;
  }
}


// ==== 0x4237e8 caseD_2

undefined4 switchD_004237b8::caseD_2(void)

{
  FUN_004f6240();
  FUN_00431190();
  return 1;
}


// ==== 0x423870 FUN_00423870

undefined4 __thiscall FUN_00423870(int param_1,undefined4 param_2,int param_3)

{
  switch(param_2) {
  case 1:
    FEManager__ShowPackage();
    return 1;
  case 2:
    FUN_004f6240();
    FUN_00431190();
    return 1;
  case 3:
    return 1;
  default:
    return 0;
  case 6:
    break;
  case 10:
    FUN_00421ae0(0);
    FUN_00421bc0(10,0);
    return 1;
  }
  FUN_0051eee0(DAT_007356a8);
  if (param_3 == 1) {
    FUN_00421ae0(*(undefined4 *)(param_1 + 0x20));
    *(undefined1 *)(param_1 + 0x24) = 0;
    return 1;
  }
  if (param_3 != 4) {
    if (param_3 != 3) {
      if (param_3 == 2) {
        FUN_004aba80();
        FUN_00495e20();
        if (DAT_0078a320 == 1) {
          FUN_00495ec0();
        }
        FUN_00421ae0(0);
        FUN_00421bc0(8,0);
      }
      *(undefined1 *)(param_1 + 0x24) = 0;
      return 1;
    }
    FUN_004abb50(0);
    FUN_00421ae0(0);
    FUN_00421bc0(10,0);
    *(undefined1 *)(param_1 + 0x24) = 0;
    return 1;
  }
  FUN_00421ae0(5);
  *(undefined1 *)(param_1 + 0x24) = 0;
  return 1;
}


// ==== 0x42389b caseD_2

undefined4 switchD_00423881::caseD_2(void)

{
  FUN_004f6240();
  FUN_00431190();
  return 1;
}


// ==== 0x4239c0 FUN_004239c0

undefined4 __thiscall FUN_004239c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  switch(param_2) {
  case 1:
    if (*(int *)(param_1 + 0x48) != 0) {
      iVar1 = FUN_00572cd0();
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x14) = 8;
        FUN_00421ae0(1);
      }
LAB_00423a3b:
      iVar1 = 0;
      if (0 < DAT_007361c4) {
        do {
          FUN_0042d3e0();
          iVar1 = iVar1 + 1;
        } while (iVar1 < DAT_007361c4);
      }
      return 1;
    }
    iVar1 = FUN_00572f20("THE_PRESENT");
    if ((iVar1 != 0) && (iVar1 = FUN_00572cd0(), iVar1 != 0)) goto LAB_00423a3b;
    break;
  case 2:
    iVar1 = 0;
    if (0 < DAT_007361c4) {
      do {
        FUN_0042d350();
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_007361c4);
    }
    FUN_00574190();
    return 1;
  case 3:
  case 0xd:
    goto switchD_004239da_caseD_3;
  default:
    return 0;
  case 0xb:
    if (*(int *)(param_1 + 0x48) != 0) {
      *(undefined4 *)(param_1 + 0x14) = 8;
      *(undefined4 *)(param_1 + 0x18) = 0;
      FUN_00421ae0(1);
      return 1;
    }
    FUN_00572cd0();
    FUN_00572d20();
    break;
  case 0xe:
    FUN_00573010();
    return 1;
  }
  FUN_00421ae0(7);
switchD_004239da_caseD_3:
  return 1;
}


// ==== 0x423b50 FUN_00423b50

undefined4 __thiscall FUN_00423b50(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_258;
  int local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  float fStack_248;
  undefined4 auStack_240 [10];
  undefined4 uStack_218;
  
  switch(param_2) {
  case 1:
    iVar7 = FUN_00572f20("THE_PRESENT");
    if (iVar7 != 0) {
      iVar7 = *(int *)(param_1 + 0x9c);
      uVar1 = *(undefined4 *)(iVar7 + 0x60);
      uVar6 = *(undefined4 *)(iVar7 + 0x68);
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(param_1 + 0x70) = uVar1;
      *(undefined4 *)(param_1 + 0x78) = uVar6;
      iVar7 = FUN_00572cd0();
      if ((iVar7 != 0) && (iVar7 = FUN_00572cd0(), iVar7 != 0)) {
        iVar7 = *(int *)(param_1 + 0x9c);
        uVar1 = *(undefined4 *)(iVar7 + 0x60);
        uVar6 = *(undefined4 *)(iVar7 + 0x68);
        *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar7 + 100);
        *(undefined4 *)(param_1 + 0x80) = uVar1;
        *(undefined4 *)(param_1 + 0x88) = uVar6;
        cVar3 = FUN_00424550();
        iVar7 = DAT_007361c4;
        if (cVar3 != '\0') {
          iVar8 = 0;
          *(undefined4 *)(param_1 + 0x50) = 0;
          if (0 < iVar7) {
            do {
              FUN_0042d3e0();
              iVar8 = iVar8 + 1;
            } while (iVar8 < DAT_007361c4);
          }
          FUN_00424680(param_1);
          return 1;
        }
      }
    }
  case 4:
    FUN_00421ae0(4);
    return 1;
  case 2:
    FUN_00572cd0();
    FUN_00572d20();
    FUN_004244b0();
    iVar7 = 0;
    if (0 < DAT_007361c4) {
      do {
        FUN_0042d350();
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_007361c4);
    }
    FUN_00574190();
    return 1;
  case 3:
    break;
  default:
    return 0;
  case 0xd:
    return 1;
  }
  if (*(int *)(DAT_007345d0 + 0x54) - DAT_006f08a4 < 1) {
    iVar7 = *(int *)(param_1 + 0x50) + 1;
    *(int *)(param_1 + 0x50) = iVar7;
    if (2 < iVar7) {
      FUN_00421bc0(4,0);
      return 1;
    }
    if (iVar7 == 1) {
      FUN_00572cd0();
      if (*(undefined4 **)(param_1 + 0x54) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x54))(1);
      }
      iVar7 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0xa8) + 4)) {
        iVar8 = 0;
        local_254 = 0;
        do {
          iVar2 = *(int *)(**(int **)(param_1 + 0xa8) + local_254 + 4);
          if (iVar2 == 0) {
            local_258 = 0.0;
          }
          else {
            local_258 = -*(float *)(iVar2 + 0x24);
          }
          FUN_004422b0(0,local_258);
          fStack_248 = fStack_248 + 5.0;
          puVar4 = (undefined4 *)(*(int *)(param_1 + 0x94) + iVar8);
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          iVar2 = *(int *)(param_1 + 0x90);
          *(float *)(iVar2 + 8 + iVar8) = fStack_248;
          puVar4 = (undefined4 *)(iVar2 + iVar8);
          *puVar4 = uStack_250;
          puVar4[1] = uStack_24c;
          local_254 = local_254 + 0x18;
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x10;
        } while (iVar7 < *(int *)(*(int *)(param_1 + 0xa8) + 4));
      }
      *(float *)(*(int *)(param_1 + 0x58) + 0x88) = -*(float *)(*(int *)(param_1 + 0x58) + 0x88);
    }
    else {
      FUN_00572cd0();
      if (*(undefined4 **)(param_1 + 0x54) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x54))(1);
      }
      local_258 = 0.0;
      if (0 < *(int *)(*(int *)(param_1 + 0xa8) + 4)) {
        iVar7 = 0;
        do {
          FUN_004422b0(0,0);
          fStack_248 = fStack_248 + 5.0;
          puVar4 = (undefined4 *)(*(int *)(param_1 + 0x94) + iVar7);
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          iVar8 = *(int *)(param_1 + 0x90);
          *(float *)(iVar8 + 8 + iVar7) = fStack_248;
          puVar4 = (undefined4 *)(iVar8 + iVar7);
          *puVar4 = uStack_250;
          puVar4[1] = uStack_24c;
          local_258 = (float)((int)local_258 + 1);
          iVar7 = iVar7 + 0x10;
        } while ((int)local_258 < *(int *)(*(int *)(param_1 + 0xa8) + 4));
      }
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x88) = 0;
    }
    puVar4 = auStack_240;
    for (iVar7 = 0x8c; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    uStack_218 = 2;
    pvVar5 = _malloc(0x470);
    if (pvVar5 != (void *)0x0) {
      uVar6 = TrackCarCameraMover__ctor
                        (pvVar5,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0x58),
                         auStack_240,1);
      *(undefined4 *)(param_1 + 0x54) = uVar6;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return 1;
}


// ==== 0x423e23 FUN_00423e23

undefined4 FUN_00423e23(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  int iVar5;
  int iStack00000018;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  float in_stack_00000028;
  undefined4 in_stack_00000058;
  
  FUN_00572cd0();
  if (*(undefined4 **)(unaff_EBX + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EBX + 0x54))(1);
  }
  iStack00000018 = 0;
  if (0 < *(int *)(*(int *)(unaff_EBX + 0xa8) + 4)) {
    iVar5 = 0;
    do {
      FUN_004422b0(0,0);
      in_stack_00000028 = in_stack_00000028 + 5.0;
      puVar4 = (undefined4 *)(*(int *)(unaff_EBX + 0x94) + iVar5);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      iVar1 = *(int *)(unaff_EBX + 0x90);
      *(float *)(iVar1 + 8 + iVar5) = in_stack_00000028;
      puVar4 = (undefined4 *)(iVar1 + iVar5);
      *puVar4 = in_stack_00000020;
      puVar4[1] = in_stack_00000024;
      iStack00000018 = iStack00000018 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iStack00000018 < *(int *)(*(int *)(unaff_EBX + 0xa8) + 4));
  }
  *(undefined4 *)(*(int *)(unaff_EBX + 0x58) + 0x88) = 0;
  puVar4 = (undefined4 *)&stack0x00000030;
  for (iVar5 = 0x8c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  in_stack_00000058 = 2;
  pvVar2 = _malloc(0x470);
  if (pvVar2 != (void *)0x0) {
    uVar3 = TrackCarCameraMover__ctor
                      (pvVar2,*(undefined4 *)(unaff_EBX + 0xa0),*(undefined4 *)(unaff_EBX + 0x58),
                       &stack0x00000030,1);
    *(undefined4 *)(unaff_EBX + 0x54) = uVar3;
    return 1;
  }
  *(undefined4 *)(unaff_EBX + 0x54) = 0;
  return 1;
}


// ==== 0x423f20 FUN_00423f20

void FUN_00423f20(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int iVar8;
  int *unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689713;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00435a70();
  iVar8 = DAT_0073619c;
  *(undefined4 *)(DAT_0073619c + 0x20) = 0;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  FUN_004ab900(iVar8);
  cVar3 = FUN_0043a2e0();
  iVar8 = DAT_0077b244;
  if ((cVar3 != '\0') && (DAT_0077b244 != 0)) {
    iVar4 = FUN_004390f0();
    if (*(short *)(iVar4 + 0x10) != 10) {
      iVar4 = FUN_00439930(4);
      if (*(int *)(iVar8 + 0x18c + iVar4 * 4) < 1) goto LAB_0042406f;
    }
    DAT_00735790 = FUN_004ab670(&DAT_00748f70);
    iVar8 = *unaff_EDI;
    piVar5 = (int *)FUN_00567160();
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5[2] = 2;
      piVar5[3] = iVar8;
    }
    puVar6 = (undefined4 *)unaff_EDI[3];
    piVar1 = unaff_EDI + 2;
    *puVar6 = piVar5;
    unaff_EDI[3] = (int)piVar5;
    piVar5[1] = (int)puVar6;
    *piVar5 = (int)piVar1;
    if (unaff_EDI[4] == 0) {
      FUN_00421b10(unaff_EDI);
    }
    puVar6 = (undefined4 *)FUN_00567160();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6[2] = 1;
      puVar6[3] = 0;
    }
    puVar2 = (undefined4 *)unaff_EDI[3];
    *puVar2 = puVar6;
    unaff_EDI[3] = (int)puVar6;
    puVar6[1] = puVar2;
    *puVar6 = piVar1;
    if (unaff_EDI[4] == 0) {
      FUN_00421b10(unaff_EDI);
    }
    puVar6 = (undefined4 *)FUN_00567160();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6[2] = 3;
      puVar6[3] = 0;
    }
    puVar2 = (undefined4 *)unaff_EDI[3];
    *puVar2 = puVar6;
    unaff_EDI[3] = (int)puVar6;
    puVar6[1] = puVar2;
    *puVar6 = piVar1;
    if (unaff_EDI[4] == 0) {
      FUN_00421b10(unaff_EDI);
    }
    FUN_00421bc0(10,0);
    ExceptionList = local_c;
    return;
  }
LAB_0042406f:
  pvVar7 = _malloc(1);
  local_4 = 0;
  if (pvVar7 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0049e390();
  }
  iVar4 = *unaff_EDI;
  unaff_EDI[0x12] = iVar8;
  local_4 = 0xffffffff;
  unaff_EDI[5] = 8;
  unaff_EDI[6] = 0;
  puVar6 = (undefined4 *)FUN_00567160();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[2] = 2;
    puVar6[3] = iVar4;
  }
  puVar2 = (undefined4 *)unaff_EDI[3];
  piVar5 = unaff_EDI + 2;
  *puVar2 = puVar6;
  unaff_EDI[3] = (int)puVar6;
  puVar6[1] = puVar2;
  *puVar6 = piVar5;
  if (unaff_EDI[4] == 0) {
    FUN_00421b10(unaff_EDI);
  }
  puVar6 = (undefined4 *)FUN_00567160();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[2] = 1;
    puVar6[3] = 1;
  }
  puVar2 = (undefined4 *)unaff_EDI[3];
  *puVar2 = puVar6;
  unaff_EDI[3] = (int)puVar6;
  puVar6[1] = puVar2;
  *puVar6 = piVar5;
  if (unaff_EDI[4] == 0) {
    FUN_00421b10(unaff_EDI);
  }
  puVar6 = (undefined4 *)FUN_00567160();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[2] = 3;
    puVar6[3] = 0;
  }
  puVar2 = (undefined4 *)unaff_EDI[3];
  *puVar2 = puVar6;
  unaff_EDI[3] = (int)puVar6;
  puVar6[1] = puVar2;
  *puVar6 = piVar5;
  if (unaff_EDI[4] == 0) {
    FUN_00421b10(unaff_EDI);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x424160 CameraMover_CreateByType

/* [canon] camera med (hopper+capstone) docs/re/misc.md */

undefined4 __thiscall CameraMover_CreateByType(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006896eb;
  local_10 = ExceptionList;
  switch(param_2) {
  case 1:
    break;
  case 2:
    ExceptionList = &local_10;
    FUN_0049e3e0(*(undefined4 *)(param_1 + 0x48));
    if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x40))(1);
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    if (*(undefined4 **)(param_1 + 0x30) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x30))(1);
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
    FUN_00574190();
    ExceptionList = local_10;
    return 1;
  case 3:
    if (DAT_006f08a4 < *(int *)(DAT_007345d0 + 0xa0)) {
      return 1;
    }
  case 0xb:
    ExceptionList = &local_10;
    if (*(undefined4 **)(param_1 + 0x30) != (undefined4 *)0x0) {
      ExceptionList = &local_10;
      (**(code **)**(undefined4 **)(param_1 + 0x30))(1);
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    cVar2 = FUN_005729d0();
    if (cVar2 != '\0') {
      pvVar3 = _malloc(0x34);
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_0047e270(*(undefined4 *)(DAT_007361f8 + 0x28 + *(int *)(param_1 + 0xac) * 4));
        *(undefined4 *)(param_1 + 0x30) = uVar4;
        ExceptionList = local_10;
        return 1;
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    ExceptionList = local_10;
    return 1;
  default:
    return 0;
  case 8:
    ExceptionList = &local_10;
    FUN_00495e20();
    if (DAT_0078a320 == 1) {
      FUN_00495ec0();
    }
    FUN_00421ae0(0);
    FUN_00421bc0(8,0);
    ExceptionList = local_10;
    return 1;
  case 9:
    ExceptionList = &local_10;
    FUN_00421ae0(0);
    FUN_00421bc0(9,param_3);
    ExceptionList = local_10;
    return 1;
  case 10:
    ExceptionList = &local_10;
    FUN_00421ae0(0);
    FUN_00421bc0(10,0);
    ExceptionList = local_10;
    return 1;
  case 0xc:
    ExceptionList = &local_10;
    FUN_00421ae0(5);
    ExceptionList = local_10;
    return 1;
  case 0xd:
    return 1;
  }
  param_2 = 0;
  ExceptionList = &local_10;
  if (0 < *(int *)(DAT_007361f8 + 0x18)) {
    iVar5 = 0x28;
    ExceptionList = &local_10;
    do {
      iVar1 = *(int *)(*(int *)(iVar5 + DAT_007361f8) + 0x868);
      if ((iVar1 != 0) && (FUN_0058dc10(), *(char *)(iVar1 + 8) != '\0')) {
        *(undefined1 *)(iVar1 + 8) = 0;
      }
      param_2 = param_2 + 1;
      iVar5 = iVar5 + 4;
    } while (param_2 < *(int *)(DAT_007361f8 + 0x18));
  }
  iVar5 = 0;
  if (0 < DAT_007361c4) {
    do {
      Player__ChangeCameraMover((&DAT_007361bc)[iVar5],0,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_007361c4);
  }
  if (DAT_00735ed0 != 0) {
    FEManager__ShowPackage();
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x3c))(1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (DAT_0077981c == 0) {
    FUN_00444590();
  }
  else {
    DAT_00779818 = DAT_0077981c;
    FUN_0047ba30(DAT_0077981c);
  }
  pvVar3 = _malloc(0x2c);
  local_8 = 0;
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    ExceptionList = local_10;
    return 1;
  }
  uVar4 = FUN_0047f680(pvVar3,1);
  *(undefined4 *)(param_1 + 0x40) = uVar4;
  ExceptionList = local_10;
  return 1;
}


// ==== 0x4244b0 FUN_004244b0

void FUN_004244b0(void)

{
  int *_Memory;
  int unaff_ESI;
  
  if (*(undefined4 **)(unaff_ESI + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x54))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  if (*(void **)(unaff_ESI + 0x58) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x58));
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  if (*(void **)(unaff_ESI + 0x98) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x98));
  }
  _Memory = *(int **)(unaff_ESI + 0xa8);
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  if (_Memory != (int *)0x0) {
    if (*_Memory != 0) {
      FUN_00565ce0();
    }
    _free(_Memory);
  }
  *(undefined4 *)(unaff_ESI + 0xa8) = 0;
  if (*(int *)(unaff_ESI + 0x94) != 0) {
    FUN_00565ce0();
  }
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  if (*(int *)(unaff_ESI + 0x90) != 0) {
    FUN_00565ce0();
  }
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  return;
}


// ==== 0x424550 FUN_00424550

undefined4 FUN_00424550(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068608b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004244b0();
  TrackPath__UpdateCursor(&DAT_007372b0,unaff_EDI + 0x70);
  TrackPath__UpdateCursor(&DAT_007372b0,unaff_EDI + 0x80);
  pvVar1 = _malloc(0x18);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00492e70(pvVar1,0x42c80000,0);
  }
  local_4 = 0xffffffff;
  *(int *)(unaff_EDI + 0xa8) = iVar2;
  if ((iVar2 != 0) && (4 < *(int *)(iVar2 + 4))) {
    ExceptionList = local_c;
    return 1;
  }
  FUN_004244b0();
  ExceptionList = local_c;
  return 0;
}


// ==== 0x424680 FUN_00424680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424680(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_2dc;
  int local_2d8;
  undefined4 local_2d4;
  undefined4 local_280;
  undefined4 local_27c;
  float local_278;
  undefined4 local_240 [10];
  undefined4 local_218;
  
  pvVar4 = _malloc(0xa4);
  *(void **)(param_1 + 0x58) = pvVar4;
  pvVar4 = _malloc(0x200);
  *(void **)(param_1 + 0x98) = pvVar4;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 8) = 0;
  TrackPath__UpdateCursor(&DAT_007372b0,param_1 + 0x70);
  TrackPath__UpdateCursor(&DAT_007372b0,param_1 + 0x80);
  TrackPath__UpdateCursor(&DAT_007372b0,param_1 + 0x5c);
  uVar5 = FUN_00565b60(*(int *)(*(int *)(param_1 + 0xa8) + 4) << 4,0,0,0);
  *(undefined4 *)(param_1 + 0x94) = uVar5;
  uVar5 = FUN_00565b60(*(int *)(*(int *)(param_1 + 0xa8) + 4) << 4,0,0,0);
  *(undefined4 *)(param_1 + 0x90) = uVar5;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x50) = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 4);
  local_2d8 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0xa8) + 4)) {
    iVar7 = 0;
    local_2dc = 0;
    do {
      iVar1 = *(int *)(**(int **)(param_1 + 0xa8) + local_2dc + 4);
      if (iVar1 == 0) {
        local_2d4 = 0;
      }
      else {
        local_2d4 = *(undefined4 *)(iVar1 + 0x28);
      }
      FUN_004422b0(0,local_2d4);
      local_278 = local_278 + 5.0;
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0x94) + iVar7);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      iVar1 = *(int *)(param_1 + 0x90);
      *(float *)(iVar1 + 8 + iVar7) = local_278;
      puVar6 = (undefined4 *)(iVar1 + iVar7);
      puVar6[1] = local_27c;
      *puVar6 = local_280;
      local_2dc = local_2dc + 0x18;
      local_2d8 = local_2d8 + 1;
      iVar7 = iVar7 + 0x10;
    } while (local_2d8 < *(int *)(*(int *)(param_1 + 0xa8) + 4));
  }
  if (DAT_0078a2fc == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x28) =
         *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xc);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10) = 0;
  }
  else {
    *(float *)(*(int *)(param_1 + 0x58) + 0xc) = _K_ONE - 0.0;
    fVar3 = _K_ONE - 0.0;
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x28) =
         *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xc);
    *(float *)(*(int *)(param_1 + 0x58) + 0x10) = fVar3;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x2c) =
       *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10);
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x20) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x24) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x30) = 0x3f000000;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x34) = 0x459c4000;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x38) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x3c) = *(undefined4 *)(param_1 + 0x98);
  iVar7 = 0x30;
  do {
    iVar2 = *(int *)(param_1 + 0x98);
    iVar1 = iVar7 + -0x30;
    *(undefined4 *)(iVar2 + iVar1) = 0x42200000;
    *(undefined4 *)(iVar2 + 4 + iVar1) = 0;
    *(undefined4 *)(iVar2 + 8 + iVar1) = 0;
    iVar2 = *(int *)(param_1 + 0x98);
    *(undefined4 *)(iVar2 + 0x10 + iVar1) = 0x42200000;
    *(undefined4 *)(iVar2 + 0x14 + iVar1) = 0;
    *(undefined4 *)(iVar2 + 0x18 + iVar1) = 0;
    iVar1 = *(int *)(param_1 + 0x98);
    *(undefined4 *)(iVar1 + -0x10 + iVar7) = 0x42200000;
    *(undefined4 *)(iVar1 + -0xc + iVar7) = 0;
    *(undefined4 *)(iVar1 + -8 + iVar7) = 0;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x98) + iVar7);
    *puVar6 = 0x42200000;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x98) + 0x10 + iVar7);
    *puVar6 = 0x42200000;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x98) + 0x20 + iVar7);
    *puVar6 = 0x42200000;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x98) + 0x30 + iVar7);
    *puVar6 = 0x42200000;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x98) + 0x40 + iVar7);
    iVar7 = iVar7 + 0x80;
    *puVar6 = 0x42200000;
    puVar6[1] = 0;
    puVar6[2] = 0;
  } while (iVar7 < 0x230);
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x54) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x58) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x5c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x60) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 100) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x68) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x6c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x70) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x74) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x78) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x7c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x80) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x84) = 0x3e4ccccd;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x8c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x90) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x94) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x98) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x9c) = 0;
  puVar6 = local_240;
  for (iVar7 = 0x8c; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_218 = 2;
  pvVar4 = _malloc(0x470);
  if (pvVar4 != (void *)0x0) {
    uVar5 = TrackCarCameraMover__ctor
                      (pvVar4,*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0x58),
                       local_240,1);
    *(undefined4 *)(param_1 + 0x54) = uVar5;
    return;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return;
}


// ==== 0x424b10 FUN_00424b10

void FUN_00424b10(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007361f4;
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


// ==== 0x424b50 FUN_00424b50

undefined4 FUN_00424b50(float param_1,float param_2,float param_3)

{
  if (ABS(param_1 - param_2) < param_3 != (ABS(param_1 - param_2) == param_3)) {
    return 1;
  }
  return 0;
}


// ==== 0x424b70 FUN_00424b70

void __fastcall FUN_00424b70(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar4 = param_1[2];
  fVar3 = param_1[1];
  *in_EAX = *param_2 - *param_1;
  in_EAX[1] = fVar1 - fVar3;
  in_EAX[2] = fVar2 - fVar4;
  return;
}


// ==== 0x424ba0 FUN_00424ba0

void __fastcall FUN_00424ba0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar2 = param_1[3];
  uVar1 = param_1[2];
  uVar3 = *param_1;
  in_EAX[1] = param_1[1];
  *in_EAX = uVar3;
  in_EAX[2] = uVar1;
  in_EAX[3] = uVar2;
  uVar2 = param_1[7];
  uVar1 = param_1[6];
  uVar3 = param_1[4];
  in_EAX[5] = param_1[5];
  in_EAX[4] = uVar3;
  in_EAX[6] = uVar1;
  in_EAX[7] = uVar2;
  uVar2 = param_1[0xb];
  uVar1 = param_1[10];
  uVar3 = param_1[8];
  in_EAX[9] = param_1[9];
  in_EAX[8] = uVar3;
  in_EAX[10] = uVar1;
  in_EAX[0xb] = uVar2;
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  in_EAX[0xc] = *param_2;
  in_EAX[0xd] = uVar1;
  in_EAX[0xf] = 0x3f800000;
  in_EAX[0xe] = uVar2;
  return;
}


// ==== 0x424c30 FUN_00424c30

float10 FUN_00424c30(void)

{
  float *in_EAX;
  
  return (float10)*in_EAX;
}


// ==== 0x424c40 FUN_00424c40

undefined4 __fastcall FUN_00424c40(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x2c + param_1 * 4);
}


// ==== 0x424c4e FUN_00424c4e

int FUN_00424c4e(void)

{
  int in_EAX;
  
  return in_EAX * 0xc90 + DAT_00734588;
}


// ==== 0x424c50 TrafficCar_AtIndex

/* [canon] traffic med (hopper+capstone) docs/re/misc.md */

int TrafficCar_AtIndex(void)

{
  int in_EAX;
  
  return in_EAX * 0xc90 + DAT_00734588;
}


// ==== 0x424c60 FUN_00424c60

int FUN_00424c60(void)

{
  int in_EAX;
  
  return in_EAX + 8;
}


// ==== 0x424c70 FUN_00424c70

bool __fastcall FUN_00424c70(int param_1)

{
  return *(int *)(param_1 + 4) == 1;
}


// ==== 0x424c80 FUN_00424c80

bool __fastcall FUN_00424c80(int param_1)

{
  return *(int *)(param_1 + 4) == 2;
}


// ==== 0x424c90 FUN_00424c90

void FUN_00424c90(void)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  
  uVar1 = _ftol_nocw();
  *unaff_ESI = uVar1;
  return;
}


// ==== 0x424cb0 FUN_00424cb0

void __fastcall FUN_00424cb0(int *param_1)

{
  int *in_EAX;
  
  *in_EAX = *in_EAX + *param_1;
  return;
}


// ==== 0x424cc0 FUN_00424cc0

void FUN_00424cc0(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  return;
}


// ==== 0x424cd0 FUN_00424cd0

void FUN_00424cd0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _ftol_nocw();
  *param_1 = uVar1;
  return;
}


// ==== 0x424cf0 FUN_00424cf0

void __fastcall FUN_00424cf0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar1 = in_EAX[1];
  fVar2 = in_EAX[2];
  *(float *)(param_1 + 0x30) = *in_EAX;
  *(float *)(param_1 + 0x34) = fVar1;
  *(float *)(param_1 + 0x38) = fVar2;
  fVar1 = in_EAX[2];
  fVar2 = in_EAX[1];
  fVar3 = *in_EAX;
  *(undefined1 *)(param_1 + 0x420) = 0;
  *(float *)(param_1 + 0x394) = SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3);
  return;
}


// ==== 0x424d40 FUN_00424d40

undefined4 __fastcall FUN_00424d40(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x314 + param_1 * 4);
}


// ==== 0x424d50 FUN_00424d50

bool FUN_00424d50(void)

{
  int in_EAX;
  
  return *(int *)(*(int *)(in_EAX + 0x14) + 4) == 1;
}


// ==== 0x424d5f FUN_00424d5f

undefined4 FUN_00424d5f(void)

{
  int in_EAX;
  
  if ((*(int *)(*(int *)(in_EAX + 0x14) + 4) == 1) &&
     (*(char *)(*(int *)(in_EAX + 0x14) + 0x734) == '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x424d60 FUN_00424d60

undefined4 FUN_00424d60(void)

{
  int in_EAX;
  
  if ((*(int *)(*(int *)(in_EAX + 0x14) + 4) == 1) &&
     (*(char *)(*(int *)(in_EAX + 0x14) + 0x734) == '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x424d80 FUN_00424d80

bool FUN_00424d80(void)

{
  int in_EAX;
  
  return *(char *)(*(int *)(in_EAX + 0x14) + 0x734) != '\0';
}


// ==== 0x424da0 FUN_00424da0

bool FUN_00424da0(void)

{
  int in_EAX;
  
  return *(int *)(*(int *)(in_EAX + 0x14) + 4) == 3;
}


// ==== 0x424db0 FUN_00424db0

undefined4 FUN_00424db0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x18);
}


// ==== 0x424dc0 FUN_00424dc0

undefined4 FUN_00424dc0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x3c);
}


// ==== 0x424dd0 FUN_00424dd0

int FUN_00424dd0(void)

{
  int in_EAX;
  
  return in_EAX + 0x40;
}


// ==== 0x424de0 FUN_00424de0

int FUN_00424de0(void)

{
  int in_EAX;
  
  return in_EAX + 0xd0;
}


// ==== 0x424df0 FUN_00424df0

int FUN_00424df0(void)

{
  int in_EAX;
  
  return in_EAX + 0x70;
}


// ==== 0x424e00 FUN_00424e00

float10 FUN_00424e00(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x3d0);
}


// ==== 0x424e10 FUN_00424e10

float10 FUN_00424e10(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x3d4);
}


// ==== 0x424e20 FUN_00424e20

float10 FUN_00424e20(int param_1)

{
  if (DAT_007000e4 != 100.0) {
    return (float10)DAT_007000e4;
  }
  return (float10)*(float *)(param_1 + 0x3e0);
}


// ==== 0x424e50 FUN_00424e50

int __fastcall FUN_00424e50(int param_1)

{
  int in_EAX;
  
  return in_EAX * 0x40 + 0xf0 + param_1;
}


// ==== 0x424e60 FUN_00424e60

int FUN_00424e60(void)

{
  int in_EAX;
  
  return in_EAX + 0x800;
}


// ==== 0x424e70 FUN_00424e70

int FUN_00424e70(void)

{
  int in_EAX;
  
  return (int)*(char *)(in_EAX + 0x4d0);
}


// ==== 0x424e80 FUN_00424e80

float10 FUN_00424e80(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x14);
}


// ==== 0x424e90 FUN_00424e90

bool __fastcall FUN_00424e90(int param_1)

{
  return *(short *)(param_1 + 0x10) != 0;
}


// ==== 0x424ea0 FUN_00424ea0

bool __fastcall FUN_00424ea0(int *param_1)

{
  return *param_1 == 4;
}


// ==== 0x424eb0 FUN_00424eb0

void __fastcall FUN_00424eb0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0xf4);
  uVar2 = *(undefined4 *)(in_EAX + 0xf8);
  *param_2 = *(undefined4 *)(in_EAX + 0xf0);
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = *(undefined4 *)(in_EAX + 0x104);
  uVar2 = *(undefined4 *)(in_EAX + 0x108);
  *param_1 = *(undefined4 *)(in_EAX + 0x100);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}


// ==== 0x424ef0 FUN_00424ef0

void __fastcall FUN_00424ef0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0072cbf0;
  iVar1 = *(int *)(DAT_0072cbf0 + 0x18);
  *param_1 = *(undefined4 *)(DAT_0072cbf0 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x424f10 FUN_00424f10

undefined4 FUN_00424f10(void)

{
  int in_EAX;
  
  return (&DAT_007361b4)[in_EAX];
}


// ==== 0x424f20 FUN_00424f20

undefined1 FUN_00424f20(void)

{
  int in_EAX;
  
  return *(undefined1 *)(in_EAX + 0x4ac);
}


// ==== 0x424f30 FUN_00424f30

void __fastcall FUN_00424f30(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_004422b0();
    return;
  }
  FUN_00442330();
  return;
}


// ==== 0x424f40 FUN_00424f40

int __fastcall FUN_00424f40(int param_1)

{
  int in_EAX;
  
  if (param_1 == 0) {
    return in_EAX + 0xc;
  }
  return in_EAX + 0x14;
}


// ==== 0x424f50 FUN_00424f50

undefined1 FUN_00424f50(void)

{
  int in_EAX;
  
  return *(undefined1 *)(in_EAX + 0x83);
}


// ==== 0x424f60 FUN_00424f60

void FUN_00424f60(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  *unaff_ESI = &PTR_FUN_006caa58;
  unaff_ESI[0x6d] = 0;
  unaff_ESI[0x6e] = 0;
  puVar2 = unaff_ESI + 4;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00458f10(0,0);
  unaff_ESI[0x75] = 1;
  unaff_ESI[0x76] = 1;
  *(undefined2 *)(unaff_ESI + 0x74) = 0;
  unaff_ESI[0x77] = 0;
  unaff_ESI[0x78] = 0;
  unaff_ESI[0x79] = 0;
  FUN_00458f10(0,0);
  return;
}


// ==== 0x424fd0 FUN_00424fd0

void __fastcall FUN_00424fd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006caa58;
  return;
}


// ==== 0x424fe0 FUN_00424fe0

undefined4 FUN_00424fe0(void)

{
  return 0xffffffff;
}


// ==== 0x424ff0 FUN_00424ff0

undefined4 __fastcall FUN_00424ff0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1d4);
}


// ==== 0x425000 FUN_00425000

undefined4 __fastcall FUN_00425000(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1d8);
}


// ==== 0x425010 FUN_00425010

void __thiscall FUN_00425010(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1d4) = param_2;
  return;
}


// ==== 0x425020 FUN_00425020

void __thiscall FUN_00425020(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1d8) = param_2;
  return;
}


// ==== 0x425030 FUN_00425030

void __thiscall FUN_00425030(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x10);
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x425050 FUN_00425050

undefined2 FUN_00425050(void)

{
  return 0;
}


// ==== 0x425060 FUN_00425060

void * __thiscall FUN_00425060(void *param_1,byte param_2)

{
  FUN_00424fd0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x425080 FUN_00425080

void FUN_00425080(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006caa58;
  return;
}


// ==== 0x425090 FUN_00425090

undefined4 FUN_00425090(void)

{
  return 0xfffe7961;
}


// ==== 0x4250a0 FUN_004250a0

void * __thiscall FUN_004250a0(void *param_1,byte param_2)

{
  FUN_00425080();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4250c0 FUN_004250c0

void __fastcall FUN_004250c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006caadc;
  return;
}


// ==== 0x4250d0 FUN_004250d0

undefined4 * __thiscall FUN_004250d0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006caadc;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4250f0 FUN_004250f0

undefined4 * __thiscall FUN_004250f0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00575390();
  iVar2 = DAT_00735f90;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f90 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f90 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x425120 FUN_00425120

void __fastcall FUN_00425120(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00735f8c;
  iVar1 = *(int *)(DAT_00735f8c + 0x18);
  *param_1 = *(undefined4 *)(DAT_00735f8c + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x425140 FUN_00425140

void __fastcall FUN_00425140(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  
  FUN_00571c20(param_2,param_1,in_EAX,1,0);
  return;
}


// ==== 0x425150 FUN_00425150

undefined4 FUN_00425150(void)

{
  bool bVar1;
  int in_EAX;
  undefined4 uVar2;
  
  if (((*(int *)(*(int *)(in_EAX + 0x14) + 4) == 1) &&
      (*(char *)(*(int *)(in_EAX + 0x14) + 0x734) == '\0')) && (DAT_00736208 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) || (uVar2 = 3, bVar1)) {
    uVar2 = 1;
  }
  return uVar2;
}


// ==== 0x4251a0 FUN_004251a0

void __thiscall FUN_004251a0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"CarDriver");
  FUN_00571c20(param_2,param_1 + 0x1d0,2,2,0);
  FUN_00571c20(param_2,param_1 + 0x1dc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1e4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1e0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1d4,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x1d8,1,4,1);
  FUN_00458dc0();
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x425270 FUN_00425270

float10 __thiscall FUN_00425270(int param_1,float param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  iVar2 = 0;
  do {
    FUN_00465150(uVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return (float10)param_2;
}


// ==== 0x425290 FUN_00425290

void FUN_00425290(void)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  undefined4 *unaff_EDI;
  
  FUN_00458a50(in_EAX);
  *unaff_EDI = &PTR_FUN_006cab08;
  puVar1 = _malloc(0x1f0);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00424f60();
    *puVar1 = &PTR_FUN_006cab60;
    unaff_EDI[2] = puVar1;
    return;
  }
  unaff_EDI[2] = 0;
  return;
}


// ==== 0x4252d0 FUN_004252d0

void FUN_004252d0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006cab08;
  local_4 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  *param_1 = &PTR_FUN_006c8f08;
  ExceptionList = local_c;
  return;
}


// ==== 0x425320 FUN_00425320

undefined4 FUN_00425320(void)

{
  return 0xffffffff;
}


// ==== 0x425330 FUN_00425330

void * __thiscall FUN_00425330(void *param_1,byte param_2)

{
  FUN_004252d0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x425350 FUN_00425350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00425350(int param_1,int param_2,undefined4 *param_3,undefined2 param_4,float param_5)

{
  byte *pbVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  void *pvVar9;
  char *pcVar10;
  bool bVar11;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006869a8;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  if (*(char *)(param_2 + 0x434) == -1) {
    ExceptionList = &pvStack_1c;
    RideInfo__RebuildPhysicsInfo(1);
  }
  FUN_00464860(param_2 + 0x70);
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x530) = 0;
  *(undefined4 *)(param_1 + 0x534) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x538) = 0;
  *(undefined4 *)(param_1 + 0x7e0) = 0;
  *(undefined4 *)(param_1 + 0x7e4) = 0;
  *(undefined4 *)(param_1 + 0x7e8) = 0;
  *(undefined4 *)(param_1 + 0x7ec) = 0;
  *(undefined4 *)(param_1 + 0x7f4) = 0;
  *(undefined4 *)(param_1 + 0x7f8) = 0;
  *(undefined4 *)(param_1 + 0x7fc) = 0;
  FUN_00440740();
  *(undefined4 *)(param_1 + 0x800) = 0;
  *(undefined4 *)(param_1 + 0x804) = 0;
  *(undefined4 *)(param_1 + 0x808) = 0;
  *(undefined4 *)(param_1 + 0x80c) = 0;
  *(undefined4 *)(param_1 + 0x810) = 0;
  *(undefined4 *)(param_1 + 0x814) = 0;
  *(undefined4 *)(param_1 + 0x818) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x81c) = 0;
  *(undefined4 *)(param_1 + 0x820) = 0;
  *(undefined4 *)(param_1 + 0x824) = 0;
  *(undefined1 *)(param_1 + 0x828) = 0;
  *(undefined4 *)(param_1 + 0x844) = 0;
  *(undefined4 *)(param_1 + 0x870) = 0;
  *(undefined4 *)(param_1 + 0x884) = 0;
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  *(undefined4 *)(param_1 + 0x8e0) = 0;
  *(undefined4 *)(param_1 + 0x8ec) = 0;
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  local_14 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  if (param_3 != (undefined4 *)0x0) {
    local_30 = *param_3;
    local_28 = param_3[2];
    local_2c = param_3[1];
    uVar5 = param_3[1];
    *(undefined4 *)(param_1 + 0x490) = *param_3;
    *(undefined4 *)(param_1 + 0x498) = local_28;
    *(undefined4 *)(param_1 + 0x494) = uVar5;
  }
  *(undefined4 *)(param_1 + 0x808) = 0;
  if ((0.0 <= param_5) && (iVar4 = FUN_004437e0(&local_30,param_5), iVar4 != 0)) {
    TrackPath__UpdateCursor(&DAT_007372b0,iVar4);
  }
  TrackPath__UpdateCursor(&DAT_007372b0,&local_30);
  *(undefined4 *)(param_1 + 0x60) = local_30;
  *(undefined4 *)(param_1 + 100) = local_2c;
  *(undefined4 *)(param_1 + 0x68) = local_28;
  *(undefined2 *)(param_1 + 0x3b4) = param_4;
  *(undefined1 *)(param_1 + 0x86c) = 0;
  *(undefined1 *)(param_1 + 0x86d) = 0;
  *(undefined4 *)(param_1 + 0x478) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(int *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x484) = 0;
  *(undefined1 *)(param_1 + 0x874) = 0;
  *(short *)(param_1 + 10) = (short)*(char *)(param_2 + 1);
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(int *)(param_1 + 0x10) = param_2 + 0x10;
  if (*(char *)(param_2 + 0x434) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  piVar2 = *(int **)(param_1 + 0x10);
  *(int *)(param_1 + 0x20) = param_2 + 0x70;
  iVar4 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0xc) = *piVar2 * 0xc90 + DAT_00734588;
  if ((*(int *)(iVar4 + 4) == 1) && (*(char *)(iVar4 + 0x734) == '\0')) {
    _DAT_00700d54 = *piVar2;
    _DAT_007361d8 = piVar2 + 2;
  }
  bVar11 = DAT_006f1dd8 == 0;
  *(undefined4 *)(param_1 + 0x878) = 0;
  if (bVar11) goto LAB_00425665;
  if (*(int *)(iVar4 + 4) == 1) {
    if (*(char *)(iVar4 + 0x734) == '\0') {
      uVar5 = FUN_0051d510();
    }
    else {
LAB_00425651:
      uVar5 = FUN_0051d6b0(param_1);
    }
  }
  else {
    if ((*(char *)(iVar4 + 0x734) != '\0') || (*(int *)(iVar4 + 4) == 2)) goto LAB_00425651;
    if (*(int *)(iVar4 + 4) != 3) goto LAB_00425665;
    uVar5 = FUN_0051d8c0(DAT_007356a8,param_1);
  }
  *(undefined4 *)(param_1 + 0x878) = uVar5;
LAB_00425665:
  puVar6 = _malloc(0x2c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_00458a50(param_1);
    *puVar6 = &PTR_FUN_006cab08;
    puVar7 = _malloc(0x1f0);
    if (puVar7 == (undefined4 *)0x0) {
      puVar6[2] = 0;
    }
    else {
      FUN_00424f60();
      *puVar7 = &PTR_FUN_006cab60;
      puVar6[2] = puVar7;
    }
  }
  *(undefined4 **)(param_1 + 0x2c) = puVar6;
  *(undefined4 *)(param_1 + 0x30) = puVar6[2];
  puVar6 = (undefined4 *)FUN_00567160();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[1] = 0;
    *puVar6 = &PTR_FUN_006caaf0;
    puVar6[2] = param_1 + 0x40;
  }
  *(undefined4 **)(param_1 + 0x34) = puVar6;
  pcVar10 = "CarWorldObject";
  iVar4 = -1;
  uVar8 = 0x43;
  do {
    iVar4 = iVar4 * 0x21 + uVar8;
    pbVar1 = (byte *)(pcVar10 + 1);
    uVar8 = (uint)*pbVar1;
    pcVar10 = pcVar10 + 1;
  } while (*pbVar1 != 0);
  iVar4 = FUN_00577d10(iVar4);
  uVar5 = (**(code **)(iVar4 + 8))(param_1,0);
  *(undefined4 *)(param_1 + 0x82c) = uVar5;
  *(undefined4 *)(param_1 + 0x868) = 0;
  if (*(int *)(*(int *)(param_1 + 0xc) + 0xc54) == 0) {
    pvVar9 = _malloc(0xf8);
    if (pvVar9 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0058d750(param_1);
    }
    *(undefined4 *)(param_1 + 0x868) = uVar5;
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar4 = FUN_00567160();
  local_14._0_1_ = 1;
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00469b00(iVar4,param_1);
  }
  local_14._0_1_ = 0;
  *(undefined4 *)(param_1 + 0x3c) = uVar5;
  *(undefined4 *)(param_1 + 0x8d0) = 0;
  *(undefined4 *)(param_1 + 0x8dc) = 0;
  *(undefined4 *)(param_1 + 0x8d4) = 0;
  *(undefined4 *)(param_1 + 0x8d8) = 0;
  FUN_004278d0();
  *(undefined4 *)(param_1 + 0x3d8) = 1;
  *(undefined4 *)(param_1 + 0x470) = 1;
  *(undefined4 *)(param_1 + 0x474) = 0;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  Car__InitRenderInfo(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x87c) = 0;
  *(undefined4 *)(param_1 + 0x880) = 0;
  *(undefined4 *)(param_1 + 0x8a0) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 100);
  *(undefined1 *)(param_1 + 0x4d0) = 1;
  *(undefined1 *)(param_1 + 0x4d1) = 1;
  FUN_0058df00(0x10000);
  *(undefined4 *)(param_1 + 0x858) = 0;
  *(undefined4 *)(param_1 + 0x834) = 0;
  *(undefined4 *)(param_1 + 0x85c) = 0;
  *(undefined4 *)(param_1 + 0x860) = 0;
  *(undefined4 *)(param_1 + 0x864) = 0;
  *(undefined4 *)(param_1 + 0x844) = DAT_0073ad34;
  *(undefined4 *)(param_1 + 0x848) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x84c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x850) = 0xbf800000;
  *(undefined1 *)(param_1 + 0x855) = 0;
  *(undefined1 *)(param_1 + 0x854) = 0;
  *(undefined1 *)(param_1 + 0x83e) = 0;
  *(undefined1 *)(param_1 + 0x83f) = 0;
  *(undefined1 *)(param_1 + 0x840) = 0;
  *(undefined4 *)(param_1 + 0x838) = 0;
  *(undefined4 *)(param_1 + 0x884) = 0;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x8e0) = uVar5;
  *(undefined4 *)(param_1 + 0x4c4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined1 *)(param_1 + 0x8a8) = 0;
  *(undefined4 *)(param_1 + 0x888) = 0x40000000;
  *(undefined1 *)(param_1 + 0x8a9) = 1;
  *(undefined4 *)(param_1 + 0x8ac) = 0;
  *(undefined4 *)(param_1 + 0x8b0) = 0;
  *(undefined4 *)(param_1 + 0x8b4) = 0;
  *(undefined4 *)(param_1 + 0x8b8) = 0;
  *(undefined4 *)(param_1 + 0x8bc) = 0;
  *(undefined1 *)(param_1 + 0x8c0) = 0;
  *(undefined1 *)(param_1 + 0x83c) = 0;
  *(undefined1 *)(param_1 + 0x83d) = 1;
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  *(undefined4 *)(param_1 + 0x8c4) = 0;
  *(undefined4 *)(param_1 + 0x8cc) = 0;
  *(undefined1 *)(param_1 + 0x88c) = 0;
  *(undefined4 *)(param_1 + 0x890) = 0;
  *(undefined4 *)(param_1 + 0x894) = 0;
  *(undefined4 *)(param_1 + 0x898) = 0;
  *(undefined4 *)(param_1 + 0x89c) = 0;
  *(undefined1 *)(param_1 + 0x8e8) = 0;
  *(undefined4 *)(param_1 + 0x830) = 0;
  cVar3 = FUN_0043a2e0();
  if (cVar3 != '\0') {
    pvVar9 = _malloc(0x2a0);
    local_14 = CONCAT31(local_14._1_3_,2);
    if (pvVar9 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00436ff0(pvVar9,param_1);
    }
    *(undefined4 *)(param_1 + 0x830) = uVar5;
  }
  *(undefined4 *)(param_1 + 0x8ec) = 0;
  ExceptionList = pvStack_1c;
  return param_1;
}


// ==== 0x425990 FUN_00425990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00425990(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_0068606d;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  if (*(undefined4 **)(param_1 + 0x830) != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    (**(code **)**(undefined4 **)(param_1 + 0x830))(1);
  }
  if ((*(int *)(*(int *)(param_1 + 0x14) + 4) == 1) &&
     (*(char *)(*(int *)(param_1 + 0x14) + 0x734) == '\0')) {
    _DAT_00700d54 = 0xffffffff;
    _DAT_007361d8 = 0;
  }
  if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x2c))(1);
  }
  if (*(undefined4 **)(param_1 + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x34))(1);
  }
  if (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x3c))(1);
  }
  if (*(undefined4 **)(param_1 + 0x82c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x82c))(1);
  }
  pvVar1 = *(void **)(param_1 + 0x868);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0xe0) = 0;
    FUN_0058db20();
    FUN_0058d520();
    _free(pvVar1);
    *(undefined4 *)(param_1 + 0x868) = 0;
  }
  FUN_00571250(*(undefined4 *)(param_1 + 0x4d4));
  pvVar1 = *(void **)(param_1 + 0x4d4);
  if (pvVar1 != (void *)0x0) {
    FUN_0056c140(pvVar1);
    _free(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  if (*(int *)(param_1 + 0x878) != 0) {
    FUN_0051d950(param_1);
    *(undefined4 *)(param_1 + 0x878) = 0;
  }
  FUN_0058dfa0();
  iVar3 = *(int *)(param_1 + 0x7e0);
  if (0 < iVar3) {
    piVar2 = (int *)(param_1 + 0x560);
    do {
      *(char *)(*piVar2 + 8) = *(char *)(*piVar2 + 8) + -1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x425af0 Car_SerializeFields

/* [canon] car med (hopper+capstone) docs/re/misc.md */

void Car_SerializeFields(int param_1)

{
  int iVar1;
  char cVar2;
  int unaff_EDI;
  undefined1 local_c [4];
  byte abStack_8 [8];
  
  FUN_00565da0("Car%d",(int)*(short *)(param_1 + 8));
  FUN_00571ea0(0,local_c);
  FUN_00571c20(unaff_EDI,param_1 + 0x834,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x838,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x844,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x848,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x84c,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x850,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x855,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x854,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x83e,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x83f,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x840,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x858,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x85c,4,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x860,4,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x864,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x86c,1,1,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x86d,1,1,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x874,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x870,4,0xffffffff,0);
  if (*(int *)(param_1 + 0x868) != 0) {
    FUN_0058d8a0(*(int *)(param_1 + 0x868));
  }
  FUN_00571c20(unaff_EDI,param_1 + 0x24,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x28,1,4,1);
  cVar2 = *(char *)(*(int *)(param_1 + 0x10) + 7);
  FUN_00571c20(unaff_EDI,*(int *)(param_1 + 0x10) + 7,1,1,1);
  if (*(char *)(unaff_EDI + 0x3d) != '\0') {
    FUN_00425fe0();
    Car_SetMode();
    FUN_00425fe0();
    Car_SetMode();
    if (cVar2 != *(char *)(*(int *)(param_1 + 0x10) + 7)) {
      FUN_0056c310();
    }
  }
  (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
  (**(code **)(**(int **)(param_1 + 0x34) + 8))();
  FUN_004648c0();
  (**(code **)(**(int **)(param_1 + 0x3c) + 4))();
  FUN_00571c20(unaff_EDI,param_1 + 0x4c0,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x470,1,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x474,4,4,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x478,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x4d0,1,1,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x4d1,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x4c4,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x4c8,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x4cc,4,0xffffffff,0);
  FUN_00444100(param_1 + 0x800,unaff_EDI);
  if (*(char *)(unaff_EDI + 0x3d) == '\0') {
    abStack_8[0] = *(char *)(param_1 + 0x880) * '\x10' + *(char *)(param_1 + 0x87c);
    FUN_00571c20(unaff_EDI,abStack_8,1,1,0);
  }
  else {
    FUN_00571c20(unaff_EDI,abStack_8,1,1,0);
    *(uint *)(param_1 + 0x880) = (uint)(abStack_8[0] >> 4);
    *(uint *)(param_1 + 0x87c) = abStack_8[0] & 0xf;
  }
  FUN_00571c20(unaff_EDI,param_1 + 0x8a8,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8a9,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x884,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x888,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8a0,8,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8ac,0x10,0x10,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8bc,4,0xffffffff,0);
  if (*(char *)(unaff_EDI + 0x3c) != '\0' || *(char *)(unaff_EDI + 0x3d) != '\0') {
    *(undefined4 *)(param_1 + 0x47c) = 0;
  }
  FUN_00571c20(unaff_EDI,param_1 + 0x83c,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x83d,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x480,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x484,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8c8,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8c4,4,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8cc,4,4,1);
  FUN_00571c20(unaff_EDI,param_1 + 0x88c,1,1,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x890,0x10,0xffffffff,0);
  FUN_00571c20(unaff_EDI,param_1 + 0x8ec,4,0xffffffff,0);
  iVar1 = *(char *)(unaff_EDI + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_EDI + 0x58) =
       *(int *)(unaff_EDI + 0x150) - *(int *)(iVar1 + 0x58 + unaff_EDI);
  cVar2 = *(char *)(unaff_EDI + 0x40) + -1;
  *(char *)(unaff_EDI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x425fe0 FUN_00425fe0

void __fastcall FUN_00425fe0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0068696c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)(unaff_ESI + 0x2c) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)(unaff_ESI + 0x2c))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x24) = param_1;
  switch(param_1) {
  case 0:
    pvVar1 = _malloc(0x2c);
    if (pvVar1 == (void *)0x0) {
LAB_004260d2:
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00425290();
    }
    break;
  case 1:
    pvVar1 = _malloc(0x6c);
    uStack_4 = 0;
    if (pvVar1 == (void *)0x0) goto LAB_004260d2;
    uVar2 = FUN_0059bfc0(pvVar1);
    break;
  case 2:
    pvVar1 = _malloc(0x510);
    uStack_4 = 1;
    if (pvVar1 == (void *)0x0) goto LAB_004260d2;
    uVar2 = FUN_0045d660(pvVar1);
    break;
  case 3:
    pvVar1 = _malloc(0x500);
    uStack_4 = 2;
    if (pvVar1 == (void *)0x0) goto LAB_004260d2;
    uVar2 = FUN_004620c0(pvVar1);
    break;
  case 4:
    pvVar1 = _malloc(0x4f0);
    uStack_4 = 3;
    if (pvVar1 == (void *)0x0) goto LAB_004260d2;
    uVar2 = TrafficAI__ctor(pvVar1);
    break;
  default:
    goto switchD_00426012_default;
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = uVar2;
switchD_00426012_default:
  uVar2 = *(undefined4 *)(*(int *)(unaff_ESI + 0x2c) + 8);
  *(undefined4 *)(unaff_ESI + 0x30) = uVar2;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x34) + 4) = uVar2;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x426110 Car_SetMode

/* [canon] traffic low (H+G) docs/re/traffic.md */

void __fastcall Car_SetMode(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0068668e;
  local_c = ExceptionList;
  if (param_1 == *(int *)(unaff_ESI + 0x28)) {
    return;
  }
  ExceptionList = &local_c;
  if (*(undefined4 **)(unaff_ESI + 0x34) != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    (**(code **)**(undefined4 **)(unaff_ESI + 0x34))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(int *)(unaff_ESI + 0x28) = param_1;
  switch(param_1) {
  case 0:
    puVar1 = (undefined4 *)FUN_00567160();
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *puVar1 = &PTR_FUN_006caaf0;
      puVar1[2] = unaff_ESI + 0x40;
      *(undefined4 **)(unaff_ESI + 0x34) = puVar1;
      *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 0;
      break;
    }
    goto LAB_004261fd;
  case 1:
    pvVar4 = _malloc(0x90);
    uStack_4 = 0;
    if (pvVar4 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(unaff_ESI + 0xc);
      iVar3 = unaff_ESI;
      uVar2 = FUN_0057f130(uVar5);
      iVar3 = PhysicsMover__PhysicsMover(pvVar4,uVar2,uVar5,iVar3);
    }
    *(int *)(unaff_ESI + 0x34) = iVar3;
    *(undefined4 *)(iVar3 + 0x78) = *(undefined4 *)(unaff_ESI + 0x478);
    *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 1;
    break;
  case 2:
    pvVar4 = _malloc(0x24);
    if (pvVar4 != (void *)0x0) {
      uVar5 = FUN_005753c0();
      *(undefined4 *)(unaff_ESI + 0x34) = uVar5;
      *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 0;
      break;
    }
LAB_004261fd:
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 0;
    break;
  case 3:
    iVar3 = FUN_00567160();
    uStack_4 = 1;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_ESI + 0x34) = 0;
      *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 1;
    }
    else {
      uVar5 = MellowMover__MellowMover(iVar3,unaff_ESI,*(undefined4 *)(unaff_ESI + 0x20));
      *(undefined4 *)(unaff_ESI + 0x34) = uVar5;
      *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 1;
    }
    break;
  case 4:
    pvVar4 = _malloc(0x48);
    uStack_4 = 2;
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00463260(pvVar4);
    }
    *(undefined4 *)(unaff_ESI + 0x34) = uVar5;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x60) = 0;
  }
  FUN_00469f30();
  *(undefined4 *)(*(int *)(unaff_ESI + 0x34) + 4) = *(undefined4 *)(unaff_ESI + 0x30);
  ExceptionList = local_c;
  return;
}


// ==== 0x4262c0 FUN_004262c0

void __fastcall FUN_004262c0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  if (*(int **)(in_EAX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x2c) + 0x34))(param_2,0);
    return;
  }
  if ((*(int *)(in_EAX + 0x28) != 1) && (*(int *)(in_EAX + 0x28) != 3)) {
    Car_SetMode();
  }
  return;
}


// ==== 0x426300 FUN_00426300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00426300(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar1 = *(float *)(param_1 + 0x3d4);
  if (_DAT_00706288 <= fVar1) {
    fVar2 = *(float *)(param_1 + 0x60) - *(float *)(param_2 + 0x60);
    fVar3 = *(float *)(param_1 + 100) - *(float *)(param_2 + 100);
    fVar4 = *(float *)(param_1 + 0x68) - *(float *)(param_2 + 0x68);
    fVar5 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
    fVar6 = _K_EPS_SPEED;
    if (_K_EPS_SPEED < fVar5) {
      fVar6 = fVar5;
    }
    if (_DAT_0070629c < fVar6) {
      fVar6 = _DAT_0070629c;
    }
    if (fVar5 == fVar6) {
      bNormalize3();
      fVar2 = ((fVar2 * local_20 + local_1c * fVar3 + local_18 * fVar4) / fVar5 - 0.95) /
              (_K_ONE - 0.95);
      if (0.0 <= fVar2) {
        fVar7 = (float10)LinearTable__Lookup11(&PTR_DAT_007062b4,fVar1);
        fVar7 = fVar7 * (float10)fVar2;
        if ((float10)_K_EPS_SPEED <= fVar7) {
          fVar7 = (float10)FUN_00401c80((float)((float10)fVar5 / fVar7),0,0x3f800000);
          fVar7 = (float10)FUN_00583ea0((float)fVar7);
          return fVar7;
        }
      }
    }
  }
  return (float10)0.0;
}


// ==== 0x426450 FUN_00426450

float10 FUN_00426450(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined4 local_4;
  
  iVar3 = 0;
  local_4 = 0.0;
  if (0 < *(int *)(DAT_007361f8 + 0x18)) {
    iVar2 = 0x28;
    iVar1 = DAT_007361f8;
    do {
      if (*(int *)(iVar2 + iVar1) != unaff_EBX) {
        fVar4 = (float10)FUN_00426300();
        local_4 = (float)(fVar4 + (float10)local_4);
        iVar1 = DAT_007361f8;
      }
      if (0.9 <= local_4) goto LAB_004264c1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(iVar1 + 0x18));
  }
  if (local_4 < 0.9) {
    return (float10)local_4;
  }
LAB_004264c1:
  return (float10)0.9;
}


// ==== 0x4264d0 Car::ServiceResetRequest

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

float10 Car__ServiceResetRequest(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int extraout_EDX;
  float10 fVar8;
  int unaff_retaddr;
  float fVar9;
  float fVar10;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  FUN_0042a530();
  Racer__UpdateTwoHumanCatchUp();
  fVar8 = (float10)(**(code **)(**(int **)(param_1 + 0x34) + 4))();
  fVar1 = (float)fVar8;
  FUN_00427930();
  FUN_0042a4d0();
  if (*(int *)(unaff_retaddr + 0x87c) != 0) {
    iVar5 = *(int *)(*(int *)(unaff_retaddr + 0x14) + 4);
    if ((iVar5 == 1) && (*(char *)(*(int *)(unaff_retaddr + 0x14) + 0x734) == '\0')) {
      Player__ResetToRoute();
      *(undefined4 *)(unaff_retaddr + 0x87c) = 0;
      return (float10)fVar1;
    }
    if (iVar5 != 3) {
      uVar4 = (**(code **)(**(int **)(unaff_retaddr + 0x2c) + 0x14))(1);
      iVar5 = (**(code **)(**(int **)(iStack_4 + 0x2c) + 0x18))(1);
      fVar1 = *(float *)(iStack_8 + 0x3d0);
      fVar10 = 0.0;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      fVar2 = *(float *)(iStack_8 + 0x818) * *(float *)(iStack_8 + 0x90) +
              *(float *)(iStack_8 + 0x81c) * *(float *)(iStack_8 + 0x94);
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      fVar9 = fVar2 * fVar1;
      if (DAT_00700d58 <= fVar2 * fVar1) {
        fVar9 = DAT_00700d58;
      }
      uStack_10 = 0x3f800000;
      if ((*(int *)(*(int *)(iStack_8 + 0x14) + 4) == 2) &&
         (iVar6 = (**(code **)(**(int **)(iStack_8 + 0x2c) + 0x40))(), iVar6 == 1)) {
        uStack_10 = 0xbf800000;
      }
      if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
        iVar6 = (**(code **)(**(int **)(iStack_8 + 0x2c) + 0x1c))(1);
        iVar7 = (**(code **)(**(int **)(iStack_c + 0x2c) + 0x40))();
        if (iVar7 == 1) {
          iVar6 = FUN_00457040();
        }
        if ((iVar5 != 0) && (iVar6 != -1)) {
          fVar8 = (float10)FUN_00442590();
          fVar10 = (float)fVar8;
        }
      }
      FUN_00427f70(iStack_8,uVar4,iVar5,fVar9,1,uStack_10,0,0,fVar10);
      *(undefined4 *)(iStack_8 + 0x87c) = 0;
      return (float10)param_2;
    }
    FUN_0059a960(unaff_retaddr);
    *(undefined4 *)(unaff_retaddr + 0x87c) = 0;
    return (float10)fVar1;
  }
  cVar3 = FUN_004280a0();
  if (((((cVar3 != '\0') && (extraout_EDX != 0)) && (extraout_EDX != 0x7fffffff)) &&
      ((iVar5 = *(int *)(unaff_retaddr + 0x884),
       *(float *)(unaff_retaddr + 0x888) - _DAT_00700d5c < (float)(DAT_0073ad34 - iVar5) * 0.00025
       && (fVar10 = (float)(DAT_0073ad34 - extraout_EDX) * 0.00025, fVar10 < _DAT_00700d5c)))) &&
     (0.0 <= fVar10)) {
    iVar6 = _ftol_nocw();
    *(int *)(unaff_retaddr + 0x884) = iVar5 + iVar6;
    return (float10)fVar1;
  }
  return (float10)fVar1;
}


// ==== 0x4267a0 FUN_004267a0

void FUN_004267a0(float param_1)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  int unaff_ESI;
  char local_21;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (0.0 < param_1) {
    *(undefined4 *)(unaff_ESI + 0x490) = *(undefined4 *)(unaff_ESI + 0x60);
    *(undefined4 *)(unaff_ESI + 0x494) = *(undefined4 *)(unaff_ESI + 100);
    *(undefined4 *)(unaff_ESI + 0x498) = *(undefined4 *)(unaff_ESI + 0x68);
    *(undefined4 *)(unaff_ESI + 0x4a0) = *(undefined4 *)(unaff_ESI + 0x70);
    *(undefined4 *)(unaff_ESI + 0x4a4) = *(undefined4 *)(unaff_ESI + 0x74);
    *(undefined4 *)(unaff_ESI + 0x4a8) = *(undefined4 *)(unaff_ESI + 0x78);
    *(undefined4 *)(unaff_ESI + 0x4b0) = *(undefined4 *)(unaff_ESI + 0xd0);
    *(undefined4 *)(unaff_ESI + 0x4b4) = *(undefined4 *)(unaff_ESI + 0xd4);
    *(undefined4 *)(unaff_ESI + 0x4b8) = *(undefined4 *)(unaff_ESI + 0xd8);
  }
  fVar2 = *(float *)(unaff_ESI + 0x70);
  puVar1 = (undefined4 *)(unaff_ESI + 0x60);
  GroundQuery__RefillCache
            (puVar1,SQRT(*(float *)(unaff_ESI + 0x74) * *(float *)(unaff_ESI + 0x74) +
                         fVar2 * fVar2 + *(float *)(unaff_ESI + 0x78) * *(float *)(unaff_ESI + 0x78)
                        ) * 0.05 + 3.0,(float *)(unaff_ESI + 0x70));
  local_20 = *puVar1;
  local_1c = *(undefined4 *)(unaff_ESI + 100);
  local_18 = 0x47c34f8d;
  GroundQuery__FindSurfaceBelow(unaff_ESI + 0x540,&local_20,0,0,&local_21);
  if ((local_21 != '\0') && (1 < *(int *)(unaff_ESI + 0x3cc))) {
    *(undefined4 *)(unaff_ESI + 0x8a4) = *(undefined4 *)(unaff_ESI + 100);
    *(undefined4 *)(unaff_ESI + 0x8a0) = *puVar1;
  }
  if (((*(char *)(*(int *)(unaff_ESI + 0x14) + 0x734) != '\0') && (*(int *)(unaff_ESI + 0x830) != 0)
      ) && (*DAT_0073619c == 4)) {
    iVar3 = FUN_00435b30(DAT_0073619c);
    if (iVar3 == 0) {
      FUN_00437fa0(*(undefined4 *)(unaff_ESI + 0x830),param_1);
    }
  }
  iVar3 = DAT_006f0fb8;
  *(undefined4 *)(unaff_ESI + 0x364) = 1;
  *(undefined4 *)(unaff_ESI + 0x368) = 1;
  *(undefined4 *)(unaff_ESI + 0x36c) = 1;
  *(undefined4 *)(unaff_ESI + 0x370) = 1;
  if (iVar3 == *(short *)(unaff_ESI + 8)) {
    DAT_006f0fb8 = -1;
    FUN_005824b0(*(undefined4 *)(unaff_ESI + 0x10));
  }
  return;
}


// ==== 0x426930 JumpCamTrigger

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

void JumpCamTrigger(float param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  short sVar7;
  int in_EAX;
  int iVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  int *piVar12;
  bool bVar13;
  float10 fVar14;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_1c;
  float local_18;
  
  if (((*(int *)(in_EAX + 0x830) != 0) && (*DAT_0073619c == 4)) &&
     (iVar8 = FUN_00435b30(DAT_0073619c), iVar8 == 0)) {
    if (*(char *)(*(int *)(in_EAX + 0x14) + 0x734) != '\0') {
      FUN_00438030(param_1);
    }
    FUN_00438440(param_1);
  }
  if (0.0 < param_1) {
    fVar2 = _K_ONE / param_1;
    local_1c = *(float *)(in_EAX + 0x74) - *(float *)(in_EAX + 0x4a4);
    local_18 = (*(float *)(in_EAX + 0x78) - *(float *)(in_EAX + 0x4a8)) * fVar2;
    *(float *)(in_EAX + 0x88) = local_18;
    local_30 = (*(float *)(in_EAX + 0xd0) - *(float *)(in_EAX + 0x4b0)) * fVar2;
    local_2c = (*(float *)(in_EAX + 0xd4) - *(float *)(in_EAX + 0x4b4)) * fVar2;
    local_28 = (*(float *)(in_EAX + 0xd8) - *(float *)(in_EAX + 0x4b8)) * fVar2;
    *(float *)(in_EAX + 0x80) = (*(float *)(in_EAX + 0x70) - *(float *)(in_EAX + 0x4a0)) * fVar2;
    *(float *)(in_EAX + 0x84) = local_1c * fVar2;
    *(float *)(in_EAX + 0xe0) = local_30;
    *(float *)(in_EAX + 0xe4) = local_2c;
    *(float *)(in_EAX + 0xe8) = local_28;
  }
  if ((0.0 <= *(float *)(in_EAX + 0x3d4)) && (*(float *)(in_EAX + 0x3d4) <= 1000.0)) {
    *(float *)(in_EAX + 0x3b8) = param_1 * *(float *)(in_EAX + 0x3d4) + *(float *)(in_EAX + 0x3b8);
  }
  pfVar11 = (float *)(in_EAX + 0x60);
  fVar2 = *(float *)(in_EAX + 0x490) - *pfVar11;
  fVar4 = *(float *)(in_EAX + 0x494) - *(float *)(in_EAX + 100);
  fVar3 = *(float *)(in_EAX + 0x498) - *(float *)(in_EAX + 0x68);
  *(float *)(in_EAX + 0x3bc) =
       SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2) + *(float *)(in_EAX + 0x3bc);
  *(float *)(in_EAX + 0x490) = *pfVar11;
  *(undefined4 *)(in_EAX + 0x494) = *(undefined4 *)(in_EAX + 100);
  *(undefined4 *)(in_EAX + 0x498) = *(undefined4 *)(in_EAX + 0x68);
  TrackPath__UpdateCursor(&DAT_007372b0,pfVar11);
  uVar9 = DAT_006f08a4 + 7U & 0x8000001f;
  bVar13 = uVar9 == 0;
  if ((int)uVar9 < 0) {
    bVar13 = (uVar9 - 1 | 0xffffffe0) == 0xffffffff;
  }
  if (((bVar13) && (*(int *)(in_EAX + 0x28) != 0)) &&
     (iVar8 = GroundQuery__HasGroundAt(in_EAX + 0x540), iVar8 == 0)) {
    local_30 = *pfVar11 + _K_ONE;
    local_2c = *(float *)(in_EAX + 100);
    iVar8 = GroundQuery__HasGroundAt(in_EAX + 0x540);
    if (iVar8 == 0) {
      *(undefined4 *)(in_EAX + 0x87c) = 1;
    }
  }
  pfVar1 = *(float **)(in_EAX + 0x808);
  if (pfVar1 == (float *)0x0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = *(float *)(in_EAX + 0x800) - *pfVar1;
    fVar3 = *(float *)(in_EAX + 0x804) - pfVar1[1];
    fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3);
  }
  if (fVar2 <= 5000.0) {
    pfVar1 = *(float **)(in_EAX + 0x808);
    if ((((pfVar1 != (float *)0x0) &&
         (fVar2 = *(float *)(in_EAX + 0x800) - *pfVar1,
         fVar3 = *(float *)(in_EAX + 0x804) - pfVar1[1], 300.0 < SQRT(fVar2 * fVar2 + fVar3 * fVar3)
         )) && (DAT_006f08a4 % 0x3c == 0)) && (*(int *)(in_EAX + 0x28) != 0)) {
      *(undefined4 *)(in_EAX + 0x808) = 0;
      TrackPath__UpdateCursor(&DAT_007372b0,pfVar11);
    }
  }
  else if (DAT_00736090 == 0) {
    *(undefined4 *)(in_EAX + 0x87c) = 1;
  }
  FUN_00429190();
  iVar8 = *(int *)(in_EAX + 0x18);
  if (iVar8 == 0) {
    return;
  }
  local_34 = *(float *)(in_EAX + 0x3cc);
  if ((*(int *)(iVar8 + 0x60) == 6) || (*(int *)(iVar8 + 0x60) == 7)) {
    if (*(int *)(in_EAX + 0x38) == 1) {
      if ((local_34 == 5.60519e-45) &&
         (0.5 < (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x4c8)) * 0.00025)) {
LAB_00426c65:
        Player__EndSpecialCamera(1);
      }
    }
    else if (0 < (int)local_34) goto LAB_00426c65;
  }
  uVar9 = DAT_006f08a4 + 3U & 0x80000007;
  bVar13 = uVar9 == 0;
  if ((int)uVar9 < 0) {
    bVar13 = (uVar9 - 1 | 0xfffffff8) == 0xffffffff;
  }
  if (!bVar13) {
    return;
  }
  fVar2 = *(float *)(in_EAX + 0x3d4);
  fVar3 = (float)DAT_0078a3fa;
  local_30 = fVar3;
  fVar14 = (float10)LinearTable__Lookup11(&PTR_DAT_007062fc,fVar3);
  if (((fVar14 < (float10)fVar2) && ((int)local_34 < 4)) &&
     (fVar14 = (float10)FUN_00464ea0(), ABS(fVar14) < (float10)0.098125)) {
    FUN_00572970(0x40000000,"CarInAir");
  }
  if ((((DAT_007361e8 == 0) && (*(int *)(iVar8 + 0x60) != 6)) &&
      ((*(int *)(iVar8 + 0x60) != 7 &&
       ((local_34 == 0.0 && (*(char *)(*(int *)(in_EAX + 0x18) + 0x4ac) == '\0')))))) &&
     (fVar14 = (float10)LinearTable__Lookup11(&PTR_DAT_007062fc,fVar3), fVar14 < (float10)fVar2)) {
    fVar14 = (float10)LinearTable__Lookup11(&PTR_DAT_00706314,fVar3);
    local_34 = (float)fVar14;
    JumpCamPredict(local_34,&local_30,&local_34,1);
    if (0.9 <= local_34) {
      fVar4 = local_34 * 0.5;
    }
    else {
      fVar4 = 5.0;
    }
    *(float *)(in_EAX + 0x4c4) = (float)DAT_0073ad34 * 0.00025 + fVar4;
    fVar14 = (float10)LinearTable__Lookup11(&PTR_DAT_007062cc,fVar3);
    if ((((fVar14 < (float10)local_30) &&
         (fVar14 = (float10)LinearTable__Lookup11(&PTR_DAT_007062e4,fVar3),
         fVar14 < (float10)local_34)) && (cVar6 = JumpCamBuildSpline(), cVar6 != '\0')) &&
       (cVar6 = Player__StartSpecialCamera(6,0,1,1), cVar6 == '\0')) {
      FUN_0042c640();
    }
  }
  if (((*(int *)(iVar8 + 0x60) == 6) && (*(float *)(in_EAX + 0x78) < 0.0)) &&
     (*(float *)(iVar8 + 0x588) < *(float *)(in_EAX + 0x68))) {
    *(undefined4 *)(iVar8 + 0x588) = *(undefined4 *)(in_EAX + 0x68);
  }
  if (*(int *)(iVar8 + 0x60) != 6) goto LAB_004270d9;
  if (*(int *)(in_EAX + 0x38) == 1) {
    local_30 = (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x4c8));
    if ((((((float)(int)local_30 * 0.00025 <= 3.0) ||
          (Player__EndSpecialCamera(0), DAT_0078a345 != '\0')) || (DAT_007361a4 != 0)) ||
        ((DAT_0078a346 != '\0' || (DAT_007361a0 != 0)))) || (*DAT_007361f0 == 9)) goto LAB_004270d9;
    iVar10 = SpecialCamCooldown();
    if (((iVar10 != 0) &&
        (local_30 = (float)(DAT_0073ad34 - *(int *)(iVar8 + 0x8c)),
        (float)(int)local_30 * 0.00025 < 5.0)) ||
       ((*DAT_0073619c != 4 || ((DAT_007361c4 == 2 || (DAT_0078a3fa == 0)))))) goto LAB_004270d9;
    if (SpecialCamTable3[*(int *)(iVar8 + 0x60)] != (code)0x0) {
      Player__EndSpecialCamera(0);
    }
    iVar10 = 0;
    if (0 < DAT_007361c4) {
      do {
        if (SpecialCamModeTable__flags__0_0_0_1_1_1_1_1___5_readers__recheck__0x42da40_refuses_a_new_special_camera_when_a_player_s_byte_is_non_zero__so__busy__not__enable___I_
            [*(int *)((&DAT_007361bc)[iVar10] + 0x60)] != (code)0x0) goto LAB_004270d9;
        iVar10 = iVar10 + 1;
      } while (iVar10 < DAT_007361c4);
    }
  }
  else {
    if ((((float)DAT_0073ad34 * 0.00025 <= *(float *)(in_EAX + 0x4c4)) ||
        (Player__EndSpecialCamera(0), DAT_0078a345 != '\0')) ||
       ((DAT_007361a4 != 0 ||
        (((DAT_0078a346 != '\0' || (DAT_007361a0 != 0)) || (*DAT_007361f0 == 9))))))
    goto LAB_004270d9;
    iVar10 = SpecialCamCooldown();
    if (((iVar10 != 0) &&
        (local_30 = (float)(DAT_0073ad34 - *(int *)(iVar8 + 0x8c)),
        (float)(int)local_30 * 0.00025 < 5.0)) ||
       ((*DAT_0073619c != 4 || ((DAT_007361c4 == 2 || (DAT_0078a3fa == 0)))))) goto LAB_004270d9;
    if (SpecialCamTable3[*(int *)(iVar8 + 0x60)] != (code)0x0) {
      Player__EndSpecialCamera(0);
    }
    iVar10 = 0;
    if (0 < DAT_007361c4) {
      do {
        if (SpecialCamModeTable__flags__0_0_0_1_1_1_1_1___5_readers__recheck__0x42da40_refuses_a_new_special_camera_when_a_player_s_byte_is_non_zero__so__busy__not__enable___I_
            [*(int *)((&DAT_007361bc)[iVar10] + 0x60)] != (code)0x0) goto LAB_004270d9;
        iVar10 = iVar10 + 1;
      } while (iVar10 < DAT_007361c4);
    }
  }
  *(undefined4 *)(iVar8 + 0xa0) = DAT_0073ad3c;
  *(int *)(iVar8 + 0x8c) = DAT_0073ad34;
  SlowMoStart(0x3ecccccd,0x41000000,FUN_0042da30,iVar8);
  iVar10 = FUN_0041f6a0();
  if (iVar10 == 0) {
    Player__ChangeCameraMover(iVar8,0x10,1);
  }
  _gSpecialCameraActive = 1;
  *(undefined1 *)(iVar8 + 0x270) = 1;
  *(undefined4 *)(iVar8 + 0x60) = 7;
  *(undefined1 *)(iVar8 + 0x98) = 1;
  *(undefined4 *)(iVar8 + 0x9c) = 0;
LAB_004270d9:
  if ((fVar2 < 5.0) && (*(int *)(iVar8 + 0x58) == 0)) {
    FUN_00572970(0xc1200000,"GoingSlow");
  }
  if (40.0 < fVar2) {
    iVar8 = *(int *)(DAT_007361f8 + 0x1c);
    iVar10 = *(int *)(DAT_007361f8 + 0x20) - iVar8;
    local_34 = 0.0;
    if (0 < iVar10) {
      pfVar11 = (float *)FUN_0041f5e0();
      piVar12 = (int *)(DAT_007361f8 + 0x28 + iVar8 * 4);
      do {
        iVar8 = *piVar12;
        fVar3 = *(float *)(iVar8 + 0x60) - *pfVar11;
        fVar5 = *(float *)(iVar8 + 100) - pfVar11[1];
        fVar4 = *(float *)(iVar8 + 0x68) - pfVar11[2];
        if (SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4) < 40.0) {
          local_34 = (float)((int)local_34 + 1);
        }
        piVar12 = piVar12 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      if (0 < (int)local_34) {
        FUN_00572970((float)(int)local_34 * 0.5,"CloseCars");
      }
    }
    iVar8 = *(int *)(DAT_007361f8 + 0x20);
    iVar10 = *(int *)(DAT_007361f8 + 0x24) - iVar8;
    local_34 = 0.0;
    if (0 < iVar10) {
      pfVar11 = (float *)FUN_0041f5e0();
      piVar12 = (int *)(DAT_007361f8 + 0x28 + iVar8 * 4);
      do {
        iVar8 = *piVar12;
        fVar3 = *(float *)(iVar8 + 0x60) - *pfVar11;
        fVar5 = *(float *)(iVar8 + 100) - pfVar11[1];
        fVar4 = *(float *)(iVar8 + 0x68) - pfVar11[2];
        if (SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4) < 40.0) {
          local_34 = (float)((int)local_34 + 1);
        }
        piVar12 = piVar12 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      if (0 < (int)local_34) {
        FUN_00572970((float)(int)local_34 * 0.05,"CloseCops");
      }
    }
  }
  FUN_00572970(fVar2 / 150.0,"Speed");
  if (30.0 < fVar2) {
    if (1.0 <= *(float *)(in_EAX + 0x3d0)) {
      sVar7 = Atan2ToAngle16(*(undefined4 *)(in_EAX + 0x70),*(undefined4 *)(in_EAX + 0x74));
      local_30 = (float)(uint)(ushort)(*(short *)(in_EAX + 0x3b4) - sVar7);
      fVar3 = (float)(int)local_30 * 9.58738e-05;
      if (3.14159 < fVar3) {
        fVar3 = fVar3 - 6.28318;
      }
    }
    else {
      fVar3 = 0.0;
    }
    if (0.3925 < ABS(fVar3)) {
      FUN_00572970(0x3f800000,"CarSlidingSideways");
    }
    iVar8 = FUN_00468820(0);
    if (((iVar8 != 0) && (cVar6 = FUN_004664b0(), cVar6 != '\0')) &&
       (local_30 = (float)(DAT_0073ad34 - *(int *)(iVar8 + 0xc)),
       (float)(int)local_30 * 0.00025 < 0.5)) {
      iVar8 = *(int *)(iVar8 + 100);
      cVar6 = *(char *)(*(int *)(iVar8 + 600) + 0x15);
      if (((cVar6 == '\0') && (*(char *)(*(int *)(iVar8 + 0x25c) + 0x15) == '\0')) && (40.0 < fVar2)
         ) {
        FUN_00572970(0x40400000,"CarCollision");
        return;
      }
      if ((cVar6 == '\x01') || (*(char *)(*(int *)(iVar8 + 0x25c) + 0x15) == '\x01')) {
        FUN_00572970(0x40200000,"SmokeableCollision");
      }
    }
  }
  return;
}


// ==== 0x4273d0 FUN_004273d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004273d0(int param_1,float *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  byte bStack_161;
  float fStack_160;
  float fStack_158;
  float fStack_154;
  float fStack_14c;
  float fStack_148;
  float fStack_144;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  undefined4 local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  undefined4 local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  float local_cc;
  float local_c8;
  float local_c4 [4];
  float fStack_b4;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  undefined1 local_50 [76];
  
  local_100 = 0x3f800000;
  local_fc = 0.0;
  local_f8 = 0.0;
  local_f4 = 0.0;
  local_f0 = 0;
  local_ec = 1.0;
  local_e8 = 0.0;
  local_e4 = 0.0;
  local_e0 = 0;
  local_dc = 0;
  local_d8 = 0x3f800000;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0.0;
  local_c8 = 0.0;
  local_c4[0] = 1.0;
  FUN_0040b930();
  D3DXMatrixMultiply(&local_100,&local_100,local_50);
  local_d8 = param_3[1];
  local_dc = *param_3;
  local_d4 = param_3[2];
  local_d0 = 0x3f800000;
  iVar5 = 0;
  pfVar6 = &local_cc;
  do {
    D3DXVec3Transform(pfVar6,*(int *)(param_1 + 0x20) + 0x10 + iVar5,&fStack_10c);
    iVar5 = iVar5 + 0x30;
    pfVar6 = pfVar6 + 4;
  } while (iVar5 < 0xc0);
  bVar4 = 1;
  fStack_134 = 0.0;
  fStack_130 = 0.0;
  iVar5 = 0;
  pfVar6 = &local_cc;
  do {
    fVar7 = (float10)GroundQuery__FindSurfaceBelow(param_4,pfVar6,0,0,&bStack_161);
    fStack_160 = (float)fVar7;
    fVar7 = (float10)FUN_00577060(param_1 + 0x828,param_4,fStack_160,pfVar6,0,0,&bStack_161);
    pfVar2 = (float *)(*(int *)(param_1 + 0x20) + 0x20 + iVar5);
    iVar1 = *(int *)(param_1 + 0x20) + iVar5;
    iVar5 = iVar5 + 0x30;
    fStack_134 = (*pfVar2 - *(float *)(iVar1 + 0x18)) + fStack_134;
    bVar4 = bVar4 & bStack_161;
    pfVar6[2] = (float)fVar7;
    fStack_130 = (float)(fVar7 + (float10)fStack_130);
    pfVar6 = pfVar6 + 4;
  } while (iVar5 < 0xc0);
  fStack_14c = fStack_10c;
  fStack_148 = fStack_108;
  fStack_144 = fStack_104;
  fStack_158 = local_f8;
  fStack_154 = local_f4;
  fStack_12c = local_ec;
  fStack_128 = local_e8;
  fStack_124 = local_e4;
  if (bVar4 != 0) {
    fStack_14c = (local_c4[2] - fStack_ac) + (local_cc - fStack_9c);
    fStack_148 = (local_c4[3] - fStack_a8) + (local_c8 - fStack_98);
    fStack_144 = (fStack_b4 - fStack_a4) + (local_c4[0] - fStack_94);
    local_fc = (fStack_9c - fStack_ac) + (local_cc - local_c4[2]);
    fStack_158 = (fStack_98 - fStack_a8) + (local_c8 - local_c4[3]);
    fStack_154 = (fStack_94 - fStack_a4) + (local_c4[0] - fStack_b4);
    fVar3 = SQRT(fStack_14c * fStack_14c + fStack_148 * fStack_148 + fStack_144 * fStack_144);
    if (fVar3 == 0.0) {
      fStack_14c = 1.0;
      fStack_148 = 0.0;
      fStack_144 = 0.0;
    }
    else {
      fVar3 = _K_ONE / fVar3;
      fStack_14c = fStack_14c * fVar3;
      fStack_148 = fStack_148 * fVar3;
      fStack_144 = fStack_144 * fVar3;
    }
    fVar3 = SQRT(local_fc * local_fc + fStack_158 * fStack_158 + fStack_154 * fStack_154);
    if (fVar3 == 0.0) {
      fStack_158 = 0.0;
      fStack_154 = 0.0;
      local_fc = _K_ONE;
    }
    else {
      fVar3 = _K_ONE / fVar3;
      local_fc = fVar3 * local_fc;
      fStack_158 = fStack_158 * fVar3;
      fStack_154 = fStack_154 * fVar3;
    }
    fStack_12c = fStack_154 * fStack_148 - fStack_158 * fStack_144;
    fStack_128 = fStack_144 * local_fc - fStack_154 * fStack_14c;
    fStack_124 = fStack_158 * fStack_14c - fStack_148 * local_fc;
    param_3[2] = fStack_130 * 0.25 +
                 (fStack_134 * 0.25 + *(float *)(*(int *)(param_1 + 0x20) + 8)) / fStack_124;
  }
  *param_2 = fStack_14c;
  param_2[2] = fStack_144;
  param_2[1] = fStack_148;
  param_2[3] = 0.0;
  param_2[4] = local_fc;
  param_2[5] = fStack_158;
  param_2[6] = fStack_154;
  param_2[7] = 0.0;
  param_2[8] = fStack_12c;
  param_2[9] = fStack_128;
  param_2[10] = fStack_124;
  param_2[0xb] = 0.0;
  return;
}


// ==== 0x4278d0 FUN_004278d0

void FUN_004278d0(void)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int unaff_ESI;
  
  FUN_004273d0(unaff_ESI,unaff_ESI + 0x90,(float *)(unaff_ESI + 0x60),unaff_ESI + 0x540);
  pfVar3 = *(float **)(unaff_ESI + 0x20);
  fVar1 = pfVar3[1];
  fVar2 = pfVar3[2];
  *(float *)(unaff_ESI + 0x50) = *(float *)(unaff_ESI + 0x60) - *pfVar3;
  *(float *)(unaff_ESI + 0x58) = *(float *)(unaff_ESI + 0x68) - fVar2;
  *(float *)(unaff_ESI + 0x54) = *(float *)(unaff_ESI + 100) - fVar1;
  return;
}


// ==== 0x427930 FUN_00427930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00427930(undefined4 param_1)

{
  float fVar1;
  bool bVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  bVar2 = false;
  if (unaff_EDI != *(int *)(unaff_ESI + 0x470)) {
    if (*(int **)(unaff_ESI + 0x878) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_ESI + 0x878) + 0x5c))(1,0,0,param_1);
    }
    *(int *)(unaff_ESI + 0x470) = unaff_EDI;
    if ((*(int *)(unaff_ESI + 0x28) == 1) ||
       (0.5 < (float)(DAT_0073ad34 - *(int *)(unaff_ESI + 0x8ec)) * 0.00025)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    *(int *)(unaff_ESI + 0x8ec) = DAT_0073ad34;
  }
  if (*(int *)(unaff_ESI + 0x28) == 1) {
    if ((*(int *)(unaff_ESI + 0x474) == 0) && (*(int *)(unaff_ESI + 1000) != 0)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  fVar1 = (float)*(int *)(*(int *)(unaff_ESI + 0x10) + 0x14);
  if (*(int *)(*(int *)(unaff_ESI + 0x10) + 0x40) != 0) {
    fVar1 = fVar1 + _K_HALF;
  }
  if (bVar2) {
    if (2.0 <= fVar1) {
      FUN_00569a00(unaff_ESI,fVar1 * 0.2857143,*(undefined4 *)(unaff_ESI + 0x3d8),0);
      *(undefined4 *)(unaff_ESI + 0x474) = *(undefined4 *)(unaff_ESI + 1000);
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x474) = *(undefined4 *)(unaff_ESI + 1000);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x474) = *(undefined4 *)(unaff_ESI + 1000);
  return;
}


// ==== 0x427a30 FUN_00427a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427a30(void)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  float local_20;
  float local_1c [7];
  
  fVar3 = _DAT_007361ec;
  if (_DAT_007361ec <= 0.0) {
    fVar3 = *(float *)(unaff_ESI + 0x3d4);
  }
  if (DAT_00700da8 <= fVar3) {
    fVar3 = DAT_00700da8 - 0.01;
  }
  fVar4 = _DAT_00700db0 + *(float *)(unaff_ESI + 0x4c0);
  if ((fVar3 <= fVar4) &&
     (fVar5 = *(float *)(unaff_ESI + 0x4c0) - _DAT_00700db0, fVar4 = fVar3, fVar3 < fVar5)) {
    fVar4 = fVar5;
  }
  bVar2 = DAT_00700d94 <= fVar4;
  local_20 = 0.0;
  *(float *)(unaff_ESI + 0x4c0) = fVar4;
  fVar3 = DAT_007000e4;
  if (bVar2) {
    local_1c[2] = (float)DAT_00700d98;
    local_1c[1] = DAT_00700d94;
    local_1c[4] = (float)DAT_00700da0;
    local_1c[3] = (float)DAT_00700d9c;
    local_1c[6] = DAT_00700da8;
    local_1c[5] = (float)DAT_00700da4;
    iVar6 = 1;
    do {
      if (fVar4 < local_1c[iVar6 + 1]) {
        iVar7 = iVar6 + 2;
        if (6 < iVar7) {
          iVar7 = 6;
        }
        pfVar1 = (float *)(iVar6 * 8 + 0x700d68);
        local_20 = (*(float *)(iVar6 * 8 + 0x700d6c) - *pfVar1) *
                   ((fVar4 - local_1c[iVar6]) / (local_1c[iVar6 + 1] - local_1c[iVar6])) + *pfVar1;
        break;
      }
      iVar6 = iVar6 + 1;
      iVar7 = *(int *)(unaff_ESI + 0x3d8);
    } while (iVar6 < 6);
  }
  else {
    if (_DAT_00700d90 <= fVar4) {
      iVar7 = 2;
    }
    else {
      iVar7 = 0;
    }
    fVar5 = ABS(fVar4);
    if (DAT_00700d94 < ABS(fVar4)) {
      fVar5 = DAT_00700d94;
    }
    local_20 = (fVar5 / DAT_00700d94) * (_DAT_00700d64 - _DAT_00700d60) + _DAT_00700d60;
  }
  if (*(int *)(unaff_ESI + 0x3d8) == iVar7) {
    fVar4 = DAT_007000e4;
    if (DAT_007000e4 == 100.0) {
      fVar4 = *(float *)(unaff_ESI + 0x3e0);
    }
    fVar5 = _DAT_00700dac + fVar4;
    if ((fVar5 < local_20) || (fVar5 = fVar4 - _DAT_00700dac, local_20 < fVar4 - _DAT_00700dac))
    goto LAB_00427c0d;
  }
  fVar5 = local_20;
LAB_00427c0d:
  *(int *)(unaff_ESI + 0x3d8) = iVar7;
  if (fVar3 == 100.0) {
    *(float *)(unaff_ESI + 0x3e0) = fVar5;
    return;
  }
  *(float *)(unaff_ESI + 0x3e0) = DAT_007000e4;
  return;
}


// ==== 0x427c50 FUN_00427c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427c50(undefined4 *param_1,float param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  float local_20;
  float local_1c;
  float local_18;
  
  if (DAT_007798e0 == 0) {
    Car_SetMode();
    FUN_00464c80();
  }
  TrackPath__UpdateCursor(&DAT_007372b0,param_1);
  *(undefined2 *)(unaff_EDI + 0x3b4) = param_3;
  *(undefined2 *)(unaff_EDI + 0x3b6) = 0;
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *(undefined4 *)(unaff_EDI + 0x60) = *param_1;
  *(undefined4 *)(unaff_EDI + 100) = uVar1;
  *(undefined4 *)(unaff_EDI + 0x68) = uVar2;
  *(float *)(unaff_EDI + 0x3d0) = param_2;
  FUN_00440740();
  FUN_004278d0();
  FUN_005673e0(param_2 + 0.1);
  *(float *)(unaff_EDI + 0x70) = local_20;
  *(float *)(unaff_EDI + 0x74) = local_1c;
  *(float *)(unaff_EDI + 0x78) = local_18;
  *(undefined1 *)(unaff_EDI + 0x460) = 0;
  iVar4 = 0;
  *(float *)(unaff_EDI + 0x3d4) =
       SQRT(local_20 * local_20 + local_1c * local_1c + local_18 * local_18);
  *(float *)(unaff_EDI + 0x2f0) =
       *(float *)(unaff_EDI + 0x3d0) / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x20);
  *(float *)(unaff_EDI + 0x2f4) =
       *(float *)(unaff_EDI + 0x3d0) / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x50);
  *(float *)(unaff_EDI + 0x2f8) =
       *(float *)(unaff_EDI + 0x3d0) / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x80);
  *(float *)(unaff_EDI + 0x2fc) =
       *(float *)(unaff_EDI + 0x3d0) / *(float *)(*(int *)(unaff_EDI + 0x20) + 0xb0);
  *(undefined2 *)(*(int *)(unaff_EDI + 0x30) + 0x1d0) = 0;
  (**(code **)(**(int **)(unaff_EDI + 0x30) + 0x58))();
  (**(code **)(**(int **)(unaff_EDI + 0x30) + 0x68))();
  do {
    FUN_00465150(unaff_EDI + 0x40);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  (**(code **)(**(int **)(unaff_EDI + 0x30) + 0x34))();
  if (DAT_007798e0 == 0) {
    Car_SetMode();
  }
  if ((*(int *)(*(int *)(unaff_EDI + 0x14) + 4) == 1) &&
     (*(char *)(*(int *)(unaff_EDI + 0x14) + 0x734) == '\0')) {
    FUN_00572970(0xc2c60000,"Invalidate");
    iVar4 = *(int *)(unaff_EDI + 0x18);
    _gSpecialCameraActive = 0;
    *(undefined1 *)(iVar4 + 0x270) = 0;
    *(undefined4 *)(iVar4 + 0xb8) = 0;
    *(undefined4 *)(iVar4 + 0xb4) = 0;
    if (*(int **)(iVar4 + 0x27c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x27c) + 0x34))();
      iVar3 = (*(int **)(iVar4 + 0x27c))[3];
      if ((iVar3 == 1) || (iVar3 == 0x11)) {
        (**(code **)(**(int **)(iVar4 + 0x27c) + 0x14))(*(undefined1 *)(iVar4 + 0x4ad));
      }
    }
    *(undefined4 *)(iVar4 + 0x520) = 0;
  }
  FUN_0057a380();
  return;
}


// ==== 0x427e60 FUN_00427e60

void __fastcall FUN_00427e60(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_EAX;
  
  FUN_00427c50(param_2,param_3,in_EAX);
  TrackPath__UpdateCursor(&DAT_007372b0,param_1 + 0x60);
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x30))();
  if ((char)param_3 != '\0') {
    *(undefined4 *)(param_1 + 0x884) = DAT_0073ad34;
    *(undefined4 *)(param_1 + 0x888) = 0x40000000;
    return;
  }
  *(undefined4 *)(param_1 + 0x884) = 0;
  return;
}


// ==== 0x427ed0 Car::ApplyResetZone

/* [canon] track high (hopper+ghidra) docs/re/track.md */

undefined4 __fastcall Car__ApplyResetZone(int *param_1)

{
  int unaff_ESI;
  
  if ((float)param_1[5] != 0.0) {
    if ((float)param_1[5] <= *(float *)(unaff_ESI + 0x68)) {
      return 0;
    }
  }
  if (*param_1 == 3) {
    Atan2ToAngle16(param_1[3],param_1[4],param_1[1],param_1[2],0);
    FUN_00427e60(DAT_00700d58,1);
    return 1;
  }
  if ((DAT_0078a368 == 0) || (*(int *)(*(int *)(unaff_ESI + 0x14) + 4) != 2)) {
    *(undefined4 *)(unaff_ESI + 0x87c) = 1;
  }
  return 1;
}


// ==== 0x427f70 FUN_00427f70

void FUN_00427f70(int param_1,int param_2,int param_3,undefined4 param_4,char param_5,float param_6,
                 char param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  float local_24;
  undefined1 local_20 [8];
  undefined4 local_18;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if (DAT_007372b4 == 0) {
      local_24 = *(float *)(param_3 + 0x38);
    }
    else {
      local_24 = DAT_007372b0 - *(float *)(param_3 + 0x38);
    }
    FUN_004422b0(param_8,param_9);
    local_18 = *(undefined4 *)(param_3 + 8);
    FUN_004441b0(param_3,local_24);
    uVar1 = Atan2ToAngle16(param_6 * *(float *)(param_3 + 0xc),param_6 * *(float *)(param_3 + 0x10))
    ;
    FUN_00427c50(local_20,param_4,uVar1);
    TrackPath__UpdateCursor(&DAT_007372b0,param_1 + 0x60);
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x10))(param_2,param_3,0xffffffff);
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x30))();
    if (param_5 == '\0') {
      *(undefined4 *)(param_1 + 0x884) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x884) = DAT_0073ad34;
      *(undefined4 *)(param_1 + 0x888) = 0x40000000;
    }
    if (param_7 != '\0') {
      *(undefined4 *)(param_1 + 0x880) = 2;
    }
  }
  return;
}


// ==== 0x428080 FUN_00428080

void FUN_00428080(void)

{
  int in_EAX;
  
  if ((DAT_0078a368 == 0) || (*(int *)(*(int *)(in_EAX + 0x14) + 4) != 2)) {
    *(undefined4 *)(in_EAX + 0x87c) = 1;
  }
  return;
}


// ==== 0x4280a0 FUN_004280a0

undefined4 __fastcall FUN_004280a0(int param_1)

{
  if (((*(int *)(param_1 + 0x884) != 0) && (*(int *)(param_1 + 0x884) != 0x7fffffff)) &&
     ((float)(DAT_0073ad34 - *(int *)(param_1 + 0x884)) * 0.00025 < *(float *)(param_1 + 0x888))) {
    return 1;
  }
  return 0;
}


// ==== 0x4280f0 FUN_004280f0

undefined1 FUN_004280f0(void)

{
  int in_EAX;
  
  return *(undefined1 *)(in_EAX + 0x8a8);
}


// ==== 0x428100 FUN_00428100

float10 __fastcall FUN_00428100(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (((iVar1 != 3) && (iVar1 != 2)) && (iVar1 != 4)) {
    return (float10)0.0;
  }
  piVar2 = *(int **)(*(int *)(param_1 + 0x2c) + 0x3d8);
  if (*piVar2 != 0) {
    return (float10)((uint)*(byte *)(piVar2[2] + 0x6a + piVar2[1]) << 0x10) * (float10)1.5258789e-05
    ;
  }
  return (float10)0.0;
}


// ==== 0x428150 FUN_00428150

void FUN_00428150(void)

{
  int in_EAX;
  
                    /* WARNING: Could not recover jumptable at 0x00428155. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_EAX + 0x2c) + 0x14))();
  return;
}


// ==== 0x428160 FUN_00428160

void FUN_00428160(void)

{
  int in_EAX;
  
                    /* WARNING: Could not recover jumptable at 0x00428165. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_EAX + 0x2c) + 0x18))();
  return;
}


// ==== 0x428170 FUN_00428170

void __fastcall FUN_00428170(int param_1)

{
  int in_EAX;
  int unaff_EDI;
  
  if (*(int *)(param_1 + 0x864) != 0) {
    return;
  }
  if (*(int *)(param_1 + 0x85c) < DAT_006f08a0) {
    if (DAT_006f08a0 < *(int *)(param_1 + 0x860)) goto LAB_004281a1;
  }
  else if (*(int *)(param_1 + 0x85c) <= in_EAX) goto LAB_004281a1;
  *(int *)(param_1 + 0x85c) = in_EAX;
LAB_004281a1:
  if (*(int *)(param_1 + 0x860) < unaff_EDI) {
    *(int *)(param_1 + 0x860) = unaff_EDI;
  }
  *(int *)(param_1 + 0x860) =
       (((*(int *)(param_1 + 0x860) - *(int *)(param_1 + 0x85c)) + 0x51) / 0x52) * 0x52 +
       *(int *)(param_1 + 0x85c);
  return;
}


// ==== 0x4281e0 FUN_004281e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004281e0(void)

{
  char *pcVar1;
  uint *puVar2;
  float fVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  char cVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  int unaff_EDI;
  bool bVar15;
  float10 fVar16;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  
  FUN_00401cd0();
  piVar8 = (int *)WorldZone_Query(DAT_0078a2fc);
  do {
    if ((piVar8 == (int *)0x0) || (piVar4 = (int *)*piVar8, piVar4 == (int *)0x0)) {
      return;
    }
    switch(piVar4[3]) {
    case 0x10003:
      uVar11 = *(undefined4 *)(piVar4[4] + 8);
      NullUpdate_ret(uVar11);
      uVar9 = FUN_00424df0();
      FUN_00593a30(uVar11,uVar9);
      if ((*(int *)(*(int *)(unaff_EDI + 0x14) + 4) == 1) &&
         (*(char *)(*(int *)(unaff_EDI + 0x14) + 0x734) == '\0')) {
        uVar13 = DAT_006f08a4 + 3U & 0x80000003;
        bVar15 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar15 = (uVar13 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if ((bVar15) && (30.0 < *(float *)(unaff_EDI + 0x3d4))) {
          FUN_00572970(0x40000000,"FlattenFern");
        }
      }
      break;
    default:
      if (piVar4 != DAT_007344dc) {
        iVar10 = *piVar4;
        piVar6 = (int *)piVar4[1];
        *piVar6 = iVar10;
        *(int **)(iVar10 + 4) = piVar6;
        iVar12 = DAT_007344d4;
        iVar10 = *(int *)(DAT_007344d4 + 0x18);
        *piVar4 = *(int *)(DAT_007344d4 + 0x10);
        *(int **)(iVar12 + 0x10) = piVar4;
        *(int *)(iVar12 + 0x18) = iVar10 + -1;
        _DAT_00731318 = _DAT_00731318 + -1;
      }
      break;
    case 0x10005:
      if (*(int *)(unaff_EDI + 0x18) != 0) {
        iVar10 = piVar4[4];
        uVar13 = *(uint *)(iVar10 + 8) & 0xff;
        if (DAT_0078a2fc == 0) {
          if (uVar13 == 0) {
LAB_00428354:
            if ((40.0 < *(float *)(unaff_EDI + 0x3d4)) &&
               (*(char *)(*(int *)(unaff_EDI + 0x18) + 0x4ac) == '\0')) {
              FUN_0042eda0(*(undefined2 *)(iVar10 + 10),(float)*(byte *)(iVar10 + 9));
            }
          }
        }
        else if ((DAT_0078a2fc == 1) && (uVar13 != 0)) goto LAB_00428354;
      }
      break;
    case 0x10006:
      cVar7 = FUN_0043a2e0();
      if ((cVar7 == '\0') || (cVar7 = FUN_0043a340(), cVar7 != '\0')) {
        if (DAT_006fbf14 == 0) {
          if (DAT_006fbf18 == *(short *)(unaff_EDI + 10)) goto LAB_00428427;
        }
        else if (*(int *)(*(int *)(unaff_EDI + 0x14) + 4) == 1) {
LAB_00428427:
          uVar11 = FUN_00567c70();
          iVar10 = FUN_00577d10(uVar11);
          if (iVar10 == 0) {
LAB_00428440:
            iVar12 = 0;
          }
          else {
            iVar12 = *(int *)(iVar10 + 0x2c);
            if (iVar12 == iVar10 + 0x2c) {
              iVar12 = FUN_00577e60(0);
            }
            else {
              if (iVar12 == 0) goto LAB_00428440;
              iVar12 = iVar12 + -4;
            }
          }
          local_78 = -1.0;
          local_74 = -1.0;
          local_6c = 999999.0;
          local_70 = 0.0;
          if (iVar12 != 0) {
            local_70 = *(float *)(iVar12 + 0x90);
            fVar16 = (float10)TrackPath__WrapDistance(local_70,*(undefined4 *)(unaff_EDI + 0x814));
            local_6c = (float)fVar16;
            fVar16 = (float10)FUN_004570d0(local_6c);
            local_78 = (float)fVar16;
          }
          iVar10 = (**(code **)(**(int **)(unaff_EDI + 0x2c) + 0x1c))(0);
          if (((iVar10 < 0xb) || (0x10 < iVar10)) &&
             (iVar12 = (**(code **)(**(int **)(unaff_EDI + 0x2c) + 0x18))(0), iVar12 != 0)) {
            iVar10 = FUN_00456e90();
          }
          if ((10 < iVar10) && (iVar10 < 0x11)) {
            local_74 = (float)(iVar10 + -0xb) * 0.14999998 + 1.2;
          }
          if (0.0 <= local_78) {
            iVar10 = FUN_00577d10(0x24cebc53);
            if (iVar10 == 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = *(int *)(iVar10 + 0x2c);
              if (iVar12 == iVar10 + 0x2c) {
                iVar12 = FUN_00577e60(0);
              }
              else if (iVar12 == 0) {
                iVar12 = 0;
              }
              else {
                iVar12 = iVar12 + -4;
              }
            }
            iVar10 = *(int *)(iVar12 + 0x20);
            *(float *)(iVar10 + 0x60) = local_78 - local_74;
            fVar3 = *(float *)(unaff_EDI + 0x3d4);
            *(undefined1 *)(iVar10 + 0x70) = 1;
            *(float *)(iVar10 + 100) = local_70 - fVar3 * local_74;
            if ((local_78 < local_74 != (local_78 == local_74)) || (local_6c < 50.0)) {
              FUN_0057c110(iVar12);
              cVar7 = FUN_0043a2e0();
              if (cVar7 != '\0') {
                FUN_0043cef0();
              }
            }
          }
        }
      }
      break;
    case 0x10007:
      if (((*(int *)(*(int *)(unaff_EDI + 0x14) + 4) == 1) &&
          (*(char *)(*(int *)(unaff_EDI + 0x14) + 0x734) == '\0')) &&
         (*(int **)(unaff_EDI + 0x878) != (int *)0x0)) {
        puVar5 = (undefined4 *)piVar4[4];
        iVar10 = **(int **)(unaff_EDI + 0x878);
        if (puVar5 == (undefined4 *)0x0) {
          (**(code **)(iVar10 + 0x3c))(0,0xffffffff,0,0xbf800000);
        }
        else {
          (**(code **)(iVar10 + 0x3c))(*puVar5,puVar5[2],puVar5 + 4,puVar5[7]);
        }
      }
      break;
    case 0x10008:
      break;
    case 0x10009:
      pcVar14 = "WorldObject";
      do {
        pcVar1 = pcVar14 + 1;
        pcVar14 = pcVar14 + 1;
      } while (*pcVar1 != '\0');
      pcVar14 = "XO_PlaneA_1b_01";
      do {
        pcVar1 = pcVar14 + 1;
        pcVar14 = pcVar14 + 1;
      } while (*pcVar1 != '\0');
      iVar10 = FUN_00578010();
      if (iVar10 != 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(iVar10 + 0x20) + 0x14) + 0x34);
        *puVar2 = *puVar2 & 0xffffff7f;
      }
    }
    piVar8 = piVar8 + 1;
  } while( true );
}


// ==== 0x4286a0 FUN_004286a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004286a0(float param_1)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  int iVar6;
  float fVar7;
  bool bVar8;
  float10 fVar9;
  float *local_70;
  float local_6c;
  int local_64;
  float *local_60;
  int *local_58;
  int local_54;
  float local_50;
  uint local_4c;
  float local_48;
  float local_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float fStack_18;
  
  if (*(float *)(unaff_EBX + 0x8bc) == 0.0) {
    *(float *)(unaff_EBX + 0x8bc) = (float)DAT_0073ad34 * 0.00025;
  }
  local_44 = *(float *)(unaff_EBX + 0x3d4) * 2.237;
  local_4c = 0;
  bVar2 = false;
  local_50 = 0.0;
  local_64 = 0;
  local_54 = unaff_EBX + 0xf0;
  local_60 = (float *)(unaff_EBX + 0x8ac);
  local_70 = (float *)(unaff_EBX + 0x374);
  local_58 = (int *)(unaff_EBX + 0x354);
  local_6c = 4.59177e-40;
  do {
    if (*(char *)(unaff_EBX + 0x350 + local_64) != '\0') {
      local_50 = (float)((int)local_50 + 1);
      iVar5 = *local_58;
      iVar6 = iVar5 * 0x94;
      if ((iVar5 == 0xd) || (iVar5 == 0xe)) {
        local_4c = local_4c | 1 << ((byte)local_64 & 0x1f);
        bVar2 = (bool)(bVar2 | iVar5 == 0xe);
      }
      local_48 = SQRT(*local_70 * *local_70 + local_70[1] * local_70[1]);
      if ((150.0 <= param_1) || (local_48 <= *(float *)(&DAT_006ef32c + iVar6))) {
        *local_60 = 0.0;
      }
      else {
        fVar7 = ((float)DAT_0073ad34 * 0.00025 - *(float *)(unaff_EBX + 0x8bc)) + *local_60;
        *local_60 = fVar7;
        if (((&PTR_DAT_006ef328)[iVar5 * 0x25] != (char *)0x0) &&
           (*(&PTR_DAT_006ef328)[iVar5 * 0x25] != '\0')) {
          local_48 = (local_48 - *(float *)(&DAT_006ef32c + iVar6)) /
                     (*(float *)(&DAT_006ef330 + iVar6) - *(float *)(&DAT_006ef32c + iVar6));
          if (0.15 <= fVar7) {
            if (0.7 <= fVar7) {
              if (2.0 <= fVar7) {
                if (fVar7 < 4.0) {
                  local_48 = local_48 * 0.75;
                }
              }
              else {
                local_48 = local_48 * _K_HALF;
              }
            }
            else {
              local_48 = local_48 * 0.25;
            }
          }
          else {
            local_48 = local_48 * 0.0;
          }
          if (local_48 <= 0.0) {
            local_48 = 0.0;
          }
          else if (_K_ONE < local_48) {
            local_48 = _K_ONE;
          }
          local_60[-0x142] = local_48;
          if (0.0 < local_48) {
            FUN_00569a00(unaff_EBX,local_48,(int)local_6c + iVar5,0);
          }
        }
      }
      if ((((param_1 < 40.0) && (local_6c != 4.59177e-40)) && (local_6c != 5.51013e-40)) &&
         (((*(float *)(&DAT_006ef338 + iVar6) < *local_70 &&
           ((&PTR_DAT_006ef334)[iVar5 * 0x25] != (char *)0x0)) &&
          (*(&PTR_DAT_006ef334)[iVar5 * 0x25] != '\0')))) {
        fVar9 = (float10)FUN_00401c80((*local_70 - *(float *)(&DAT_006ef338 + iVar6)) /
                                      (*(float *)(&DAT_006ef33c + iVar6) -
                                      *(float *)(&DAT_006ef338 + iVar6)),0,0x3f800000);
        local_48 = (float)fVar9;
        if ((float10)0.0 < fVar9) {
          local_30 = *local_70;
          local_2c = local_70[1];
          local_28 = 0;
          D3DXVec3Transform(&local_40,&local_30,local_54);
          local_40 = local_40 + *(float *)(unaff_EBX + 0x70);
          fStack_3c = *(float *)(unaff_EBX + 0x74) + fStack_3c;
          fStack_38 = *(float *)(unaff_EBX + 0x78) + fStack_38;
          fStack_18 = fStack_38;
          FUN_00569a00(unaff_EBX,local_48,(int)local_6c + iVar5,&local_40);
        }
      }
    }
    local_58 = local_58 + 1;
    local_64 = local_64 + 1;
    local_60 = local_60 + 1;
    local_6c = (float)((int)local_6c + 0x10000);
    local_70 = local_70 + 2;
    local_54 = local_54 + 0x40;
  } while ((int)local_6c < 0x90000);
  if (2 < (int)local_50) {
    GroundQuery__FindSurfaceBelow(unaff_EBX + 0x540,unaff_EBX + 0x60,&local_48,0,0);
    fVar7 = local_48;
    iVar5 = (int)local_48 * 0x94;
    local_6c = 0.0;
    if (*(&PTR_DAT_006ef310)[(int)local_48 * 0x25] != '\0') {
      local_6c = (local_44 - *(float *)(&DAT_006ef314 + iVar5)) /
                 (*(float *)(&DAT_006ef318 + iVar5) - *(float *)(&DAT_006ef314 + iVar5));
      if (local_6c <= 0.0) {
        local_6c = 0.0;
      }
      else if (_K_ONE < local_6c) {
        local_6c = _K_ONE;
      }
    }
    local_70 = (float *)0x0;
    if (*(&PTR_DAT_006ef31c)[(int)local_48 * 0x25] != '\0') {
      local_70 = (float *)((local_44 - *(float *)(&DAT_006ef320 + iVar5)) /
                          (*(float *)(&DAT_006ef324 + iVar5) - *(float *)(&DAT_006ef320 + iVar5)));
      if ((float)local_70 <= 0.0) {
        local_70 = (float *)0x0;
      }
      else if (_K_ONE < (float)local_70) {
        local_70 = (float *)_K_ONE;
      }
    }
    if (0.0 < (float)local_70 + local_6c) {
      fVar1 = ((float)local_70 + local_6c) - _K_ONE;
      if (fVar1 <= 0.0) {
LAB_00428b95:
        if (0.0 < local_6c) {
          FUN_00569a00(unaff_EBX,local_6c,local_48,0);
        }
      }
      else {
        if (*(float *)(&DAT_006ef320 + iVar5) <= *(float *)(&DAT_006ef314 + iVar5)) {
          local_70 = (float *)((float)local_70 - (fVar1 + fVar1));
          if ((float)local_70 <= 0.0) {
            local_70 = (float *)0x0;
          }
          goto LAB_00428b95;
        }
        local_6c = local_6c - (fVar1 + fVar1);
        if (0.0 < local_6c) goto LAB_00428b95;
      }
      if (0.0 < (float)local_70) {
        FUN_00569a00(unaff_EBX,local_70,fVar7,0);
      }
    }
    local_50 = ((*(float *)(unaff_EBX + 0x330) + *(float *)(unaff_EBX + 0x334) +
                 *(float *)(unaff_EBX + 0x338) + *(float *)(unaff_EBX + 0x33c)) -
               *(float *)(&DAT_006ef344 + iVar5)) /
               (*(float *)(&DAT_006ef348 + iVar5) - *(float *)(&DAT_006ef344 + iVar5));
    if (local_50 <= 0.0) {
      local_50 = 0.0;
LAB_00428c3c:
      if (local_50 <= 0.0) goto LAB_00428c89;
    }
    else {
      if (local_50 <= _K_ONE) goto LAB_00428c3c;
      local_50 = 1.0;
    }
    if (*(int **)(unaff_EBX + 0x878) != (int *)0x0) {
      iVar5 = **(int **)(unaff_EBX + 0x878);
      uVar3 = _ftol_nocw(0);
      (**(code **)(iVar5 + 0x5c))(5,uVar3);
      fVar7 = local_48;
    }
    FUN_00569a00(unaff_EBX,local_50,fVar7,0);
  }
LAB_00428c89:
  if (((60.0 <= param_1) || ((int)local_4c < 1)) || (*(float *)(unaff_EBX + 0x3d4) <= 10.0)) {
LAB_00428d42:
    if (!bVar2) goto LAB_00428d4a;
  }
  else {
    FUN_00428170();
    if ((*(int *)(*(int *)(unaff_EBX + 0x14) + 4) != 1) ||
       (*(char *)(*(int *)(unaff_EBX + 0x14) + 0x734) != '\0')) goto LAB_00428d42;
    uVar4 = DAT_006f08a4 + 3U & 0x80000003;
    bVar8 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar8 = (uVar4 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if ((!bVar8) || (*(float *)(unaff_EBX + 0x3d4) <= 30.0)) goto LAB_00428d42;
    if (bVar2) {
      if (*(char *)(unaff_EBX + 0x8e8) == '\0') {
        FUN_00572970(0x41200000,"InDeepWater");
        *(undefined1 *)(unaff_EBX + 0x8e8) = 1;
      }
      goto LAB_00428d42;
    }
    FUN_00572970(0x3fa00000,"InShallowWater");
LAB_00428d4a:
    *(undefined1 *)(unaff_EBX + 0x8e8) = 0;
  }
  iVar5 = *(int *)(unaff_EBX + 0x868);
  if (iVar5 != 0) {
    if (DAT_0078a336 == '\0') {
      fVar7 = 0.0;
    }
    else {
      local_44 = (float)(uint)*(ushort *)(iVar5 + 0x34);
      fVar7 = (float)(int)local_44 * 0.00024414062;
    }
    if (fVar7 <= 0.9) {
      if ((*(uint *)(iVar5 + 0xe0) & 0x30000000) == 0x30000000) {
        if (DAT_0078a336 == '\0') {
          fVar7 = 0.0;
        }
        else {
          local_44 = (float)(uint)*(ushort *)(iVar5 + 0x34);
          fVar7 = (float)(int)local_44 * 0.00024414062;
        }
        if (0.65 < fVar7) goto LAB_00428df0;
      }
    }
    else {
LAB_00428df0:
      FUN_00569a00(unaff_EBX,0x3f800000,0,0);
    }
  }
  if (*(char *)(unaff_EBX + 0x83c) == '\0') {
    iVar5 = *(int *)(unaff_EBX + 0x3fc);
    if ((iVar5 == 0) || (iVar5 == 0x7fffffff)) goto LAB_00428e63;
    local_44 = (float)(DAT_0073ad34 - iVar5);
    if ((float)*(int *)(unaff_EBX + 0x3f8) * 0.00025 < (float)(int)local_44 * 0.00025) {
      FUN_00465530();
      goto LAB_00428e63;
    }
  }
  FUN_00569a00(unaff_EBX,0x3f800000,0,0);
LAB_00428e63:
  if (*(int *)(unaff_EBX + 0x3d8) == 1) {
    iVar5 = *(int *)(*(int *)(unaff_EBX + 0x10) + 0x14);
    local_44 = (float)iVar5;
    if (*(int *)(*(int *)(unaff_EBX + 0x10) + 0x40) != 0) {
      local_44 = (float)iVar5 + _K_HALF;
    }
    if (2.0 <= local_44) {
      fVar7 = *(float *)(*(int *)(unaff_EBX + 0x20) + 0x1f8) -
              *(float *)(*(int *)(unaff_EBX + 0x20) + 0x1f0);
      if (*(char *)(unaff_EBX + 0x83d) == '\0') {
        fVar1 = DAT_007000e4;
        if (DAT_007000e4 == 100.0) {
          fVar1 = *(float *)(unaff_EBX + 0x3e0);
        }
        fVar7 = fVar7 * 0.5;
        if (fVar1 < fVar7 != (fVar1 == fVar7)) {
          *(undefined1 *)(unaff_EBX + 0x83d) = 1;
        }
      }
      else {
        fVar1 = DAT_007000e4;
        if (DAT_007000e4 == 100.0) {
          fVar1 = *(float *)(unaff_EBX + 0x3e0);
        }
        if (fVar7 * 0.75 <= fVar1) {
          FUN_00569a00(unaff_EBX,local_44 * 0.2857143,1,0);
          *(undefined1 *)(unaff_EBX + 0x83d) = 0;
        }
      }
    }
  }
  if ((*(int *)(unaff_EBX + 0x3fc) != 0) && (*(int *)(unaff_EBX + 0x3fc) != 0x7fffffff)) {
    local_44 = (float)(DAT_0073ad34 - *(int *)(unaff_EBX + 0x3fc));
    if ((float)(int)local_44 * 0.00025 <= (float)*(int *)(unaff_EBX + 0x3f8) * 0.00025) {
      iVar5 = *DAT_0073619c;
      if ((((iVar5 == 0) || (iVar5 == 1)) || (iVar5 == 2)) || (iVar5 == 3)) {
        FUN_00569a00(unaff_EBX,0x3f800000,0,0);
      }
    }
    else {
      FUN_00465530();
    }
  }
  if (*(char *)(unaff_EBX + 0x86d) != '\0') {
    iVar6 = 0;
    iVar5 = 0x50000;
    do {
      if ((*(char *)(unaff_EBX + 0x350 + iVar6) != '\0') &&
         ((1 << ((byte)iVar6 & 0x1f) & (int)*(char *)(unaff_EBX + 0x86c)) != 0)) {
        local_44 = (*(float *)(unaff_EBX + 0x3d4) * 2.237 - 4.4702725) / 22.351364;
        if (local_44 <= 0.0) {
          local_44 = 0.0;
        }
        else if (1.0 < local_44) {
          local_44 = 1.0;
        }
        FUN_00569a00(unaff_EBX,local_44,iVar5,0);
      }
      iVar5 = iVar5 + 0x10000;
      iVar6 = iVar6 + 1;
    } while (iVar5 < 0x90000);
  }
  if (*(int *)(unaff_EBX + 0x28) == 1) {
    iVar5 = *(int *)(*(int *)(unaff_EBX + 0x34) + 0x48);
    if (_DAT_006ffff0 < *(float *)(iVar5 + 0x8c)) {
      FUN_00569a00(unaff_EBX,(*(float *)(iVar5 + 0x8c) - _DAT_006ffff0) / (1.0 - _DAT_006ffff0),0,0)
      ;
    }
    if (*(int *)(iVar5 + 0x94) != 0) {
      FUN_00569a00(unaff_EBX,0x3f800000,0,0);
    }
  }
  *(float *)(unaff_EBX + 0x8bc) = (float)DAT_0073ad34 * 0.00025;
  return;
}


// ==== 0x429100 FUN_00429100

void __thiscall
FUN_00429100(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5
            ,undefined1 param_6,undefined1 param_7)

{
  if (*(float *)(param_1 + 0x84c) + *(float *)(param_1 + 0x848) + *(float *)(param_1 + 0x850) <
      (float)(DAT_0073ad34 - *(int *)(param_1 + 0x844)) * 0.00025) {
    *(int *)(param_1 + 0x844) = DAT_0073ad34;
    *(undefined4 *)(param_1 + 0x848) = param_2;
    *(undefined4 *)(param_1 + 0x850) = param_3;
    *(undefined4 *)(param_1 + 0x84c) = param_4;
    *(undefined1 *)(param_1 + 0x83e) = param_5;
    *(undefined1 *)(param_1 + 0x83f) = param_6;
    *(undefined1 *)(param_1 + 0x840) = param_7;
  }
  return;
}


// ==== 0x429190 FUN_00429190

void FUN_00429190(void)

{
  float fVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  int unaff_ESI;
  
  if (*(int *)(*(int *)(unaff_ESI + 0x14) + 4) == 1) {
    return;
  }
  bVar2 = false;
  fVar1 = (float)(DAT_0073ad34 - *(int *)(unaff_ESI + 0x844)) * 0.00025;
  if (*(float *)(unaff_ESI + 0x848) <= fVar1) {
    fVar1 = fVar1 - *(float *)(unaff_ESI + 0x848);
    if (*(float *)(unaff_ESI + 0x848) <= fVar1) {
      if (fVar1 - *(float *)(unaff_ESI + 0x850) < *(float *)(unaff_ESI + 0x84c)) goto LAB_00429203;
    }
    else {
      if (*(char *)(unaff_ESI + 0x840) == '\0') goto LAB_00429203;
      bVar2 = false;
    }
LAB_0042920f:
    if (*(char *)(unaff_ESI + 0x854) == '\0') {
      uVar3 = 0;
      goto LAB_00429222;
    }
  }
  else {
LAB_00429203:
    bVar2 = true;
    if (*(char *)(unaff_ESI + 0x83e) == '\0') goto LAB_0042920f;
  }
  uVar3 = 1;
LAB_00429222:
  *(undefined1 *)(unaff_ESI + 0x855) = uVar3;
  if ((bVar2) && (*(char *)(unaff_ESI + 0x83f) != '\0')) {
    cVar4 = (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x50))();
    if (cVar4 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0042924a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x48))();
      return;
    }
  }
  else {
    cVar4 = (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x50))();
    if (cVar4 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00429261. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x4c))();
      return;
    }
  }
  return;
}


// ==== 0x429270 FUN_00429270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429270(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  float *pfVar6;
  undefined **ppuVar7;
  int iVar8;
  int unaff_EDI;
  bool bVar9;
  byte bVar10;
  float10 fVar11;
  float fVar12;
  
  iVar8 = *(int *)(unaff_EDI + 0x18);
  if (iVar8 == 0) {
    return;
  }
  if ((*(int *)(unaff_EDI + 0x1c) != 0) && (*(short *)(*(int *)(unaff_EDI + 0x1c) + 0x10) != 0)) {
    return;
  }
  iVar5 = *(int *)(iVar8 + 8);
  bVar9 = *(char *)(iVar8 + 0x21) != '\0';
  if (*(int *)(unaff_EDI + 0x3cc) == 4) {
    if (bVar9) {
      FUN_00574d90(ABS(*(float *)(unaff_EDI + 0x88)) +
                   SQRT(*(float *)(unaff_EDI + 0xe0) * *(float *)(unaff_EDI + 0xe0) +
                        *(float *)(unaff_EDI + 0xe4) * *(float *)(unaff_EDI + 0xe4)));
      fVar11 = (float10)FUN_00464ea0();
      FUN_00574d90((float)(ABS(fVar11) * (float10)*(float *)(unaff_EDI + 0x3d4)));
    }
    if (*(int *)(unaff_EDI + 0x408) != 0) {
      fVar12 = 0.0;
      iVar8 = 4;
      pfVar6 = (float *)(unaff_EDI + 0x374);
      do {
        iVar8 = iVar8 + -1;
        fVar12 = SQRT(*pfVar6 * *pfVar6 + pfVar6[1] * pfVar6[1]) + fVar12;
        pfVar6 = pfVar6 + 2;
      } while (iVar8 != 0);
      if (bVar9) {
        FUN_00574d90(ABS(fVar12 * 0.25));
      }
    }
  }
  fVar12 = *(float *)(unaff_EDI + 800);
  fVar1 = *(float *)(unaff_EDI + 0x324);
  fVar2 = *(float *)(unaff_EDI + 0x328);
  fVar3 = *(float *)(unaff_EDI + 0x32c);
  fVar11 = (float10)LinearTable__Lookup11(&PTR_DAT_0070632c,*(undefined4 *)(unaff_EDI + 0x3d4));
  fVar12 = (float)(fVar11 * (float10)(fVar12 + fVar1 + fVar2 + fVar3));
  if (bVar9) {
    ppuVar7 = &PTR_DAT_00704548;
    if (iVar5 != 0) {
      ppuVar7 = &PTR_DAT_00704550;
    }
    PTR_PTR_007045c0 = (undefined *)ppuVar7;
    *(float *)(*ppuVar7 + 4) =
         (*(float *)(PTR_DAT_007045c4 + 0x14) - *(float *)(PTR_DAT_007045c4 + 0x10)) *
         ((fVar12 - *(float *)PTR_DAT_007045c4) /
         (*(float *)(PTR_DAT_007045c4 + 4) - *(float *)PTR_DAT_007045c4)) +
         *(float *)(PTR_DAT_007045c4 + 0x10);
    FUN_00574d90(fVar12);
  }
  if (bVar9) {
    FUN_00574d90((*(float *)(unaff_EDI + 0x330) + *(float *)(unaff_EDI + 0x334) +
                  *(float *)(unaff_EDI + 0x338) + *(float *)(unaff_EDI + 0x33c)) * 0.25);
  }
  if ('\0' < *(char *)(unaff_EDI + 0x86d)) {
    iVar8 = 0;
    do {
      if ((*(char *)(unaff_EDI + 0x350 + iVar8) != '\0') &&
         ((1 << ((byte)iVar8 & 0x1f) & (int)*(char *)(unaff_EDI + 0x86c)) != 0)) break;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  bVar10 = *(int *)(unaff_EDI + 0x364) == 0x19;
  if (*(int *)(unaff_EDI + 0x368) == 0x19) {
    bVar10 = bVar10 | 2;
  }
  if (*(int *)(unaff_EDI + 0x36c) == 0x19) {
    bVar10 = bVar10 | 4;
  }
  if (*(int *)(unaff_EDI + 0x370) == 0x19) {
    bVar10 = bVar10 | 8;
  }
  bVar4 = *(byte *)(unaff_EDI + 0x8c0);
  if ((bVar4 | bVar10) != bVar4) {
    if (*(float *)(unaff_EDI + 0x3d4) <= 13.0) {
      if (5.0 < *(float *)(unaff_EDI + 0x3d4)) goto joined_r0x004294f1;
    }
    else if ((((bVar4 | bVar10) ^ bVar4) & 3) != 0) {
joined_r0x004294f1:
      if (bVar9) {
        FUN_00574d90(0x3f800000);
      }
    }
  }
  *(byte *)(unaff_EDI + 0x8c0) = bVar10;
  if (*(int *)(unaff_EDI + 0x28) == 1) {
    if (*(float *)(*(int *)(*(int *)(unaff_EDI + 0x34) + 0x4c) + 0x5c) <= 0.0) {
      fVar12 = *(float *)(*(int *)(*(int *)(unaff_EDI + 0x34) + 0x48) + 0x8c);
      goto LAB_00429569;
    }
    if (!bVar9) goto LAB_004295c1;
    fVar12 = 1.0;
  }
  else {
    fVar12 = 0.0;
LAB_00429569:
    if (fVar12 <= _DAT_006ffff0) goto LAB_004295c1;
    if (*(int *)(unaff_EDI + 0x28) == 1) {
      fVar12 = *(float *)(*(int *)(*(int *)(unaff_EDI + 0x34) + 0x48) + 0x8c);
    }
    else {
      fVar12 = 0.0;
    }
    fVar12 = (fVar12 - _DAT_006ffff0) / (_K_ONE - _DAT_006ffff0);
    if (!bVar9) goto LAB_004295c1;
  }
  FUN_00574d90(fVar12);
LAB_004295c1:
  if ((*DAT_0073619c == 3) && (bVar9)) {
    fVar12 = DAT_007000e4;
    if (DAT_007000e4 == 100.0) {
      fVar12 = *(float *)(unaff_EDI + 0x3e0);
    }
    FUN_00574d90(fVar12 / *(float *)(*(int *)(unaff_EDI + 0x20) + 0x1f8));
  }
  return;
}


// ==== 0x429620 FUN_00429620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429620(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  float10 fVar8;
  
  if (*(int *)(param_1 + 0x28) != 1) {
    return;
  }
  if (DAT_00736500 == 0) {
    return;
  }
  if ((&DAT_0071d89c)[in_EAX] == 0) {
    return;
  }
  if (DAT_007361f0 == (int *)0x0) {
    return;
  }
  if (*DAT_007361f0 != 4) {
    return;
  }
  if (*(char *)(*(int *)(param_1 + 0x18) + 0x21) == '\0') {
    FUN_0041a680();
    FUN_0041b5f0();
    FUN_0041a8a0(DAT_00736500);
    FUN_0041b830(DAT_00736500);
    FUN_0041b150(DAT_00736500);
    FUN_0041a250(DAT_00736500,0x1b92,0x1b92);
    return;
  }
  FUN_0041a450(DAT_00736500);
  fVar8 = (float10)FUN_00436d60();
  fVar1 = (float)fVar8;
  FUN_00401c60(0x3f800000,(float)(fVar8 * (float10)0.07692308));
  FUN_00587de0();
  FUN_00587de0();
  if (ABS(fVar1) <= _K_ONE) {
    iVar4 = 0;
  }
  else {
    iVar4 = _ftol_nocw();
    if (iVar4 < 0x21b4) {
      if (iVar4 < -0x21b3) {
        iVar4 = -0x21b3;
      }
    }
    else {
      iVar4 = 0x21b3;
    }
  }
  FUN_0041a640(in_EAX,iVar4);
  _ftol_nocw();
  FUN_0041a6c0(DAT_00736500);
  if ((*(char *)(param_1 + 0x350) == '\0') && (*(char *)(param_1 + 0x351) == '\0')) {
    if (*(char *)(DAT_00736500 + 0x2220 + in_EAX) != '\x01') {
      FUN_0041b670(DAT_00736500);
    }
  }
  else if (*(char *)(DAT_00736500 + 0x2220 + in_EAX) == '\x01') {
    FUN_0041b830(DAT_00736500);
  }
  if (4.0 < ABS(*(float *)(&DAT_0078eb6c + in_EAX * 4) - fVar1)) {
    fVar3 = (float)DAT_0073ad34 * 0.00025 - *(float *)(&DAT_0078eb64 + in_EAX * 4);
    if (0.0 <= fVar3) {
      if (0.15 <= fVar3) {
        *(float *)(&DAT_0078eb64 + in_EAX * 4) = (float)DAT_0073ad34 * 0.00025;
        FUN_00401c60(0x3f800000,
                     ((*(float *)(&DAT_0078eb6c + in_EAX * 4) - fVar1) - 4.0) * 0.06666667);
        uVar5 = _ftol_nocw();
        FUN_0041a8c0(uVar5);
      }
    }
    else {
      *(undefined4 *)(&DAT_0078eb64 + in_EAX * 4) = 0;
    }
  }
  fVar3 = *(float *)(param_1 + 0x330) + *(float *)(param_1 + 0x334) + *(float *)(param_1 + 0x338) +
          *(float *)(param_1 + 0x33c);
  if (0.05 < fVar3) {
    FUN_00401c60(0x3f800000,fVar3 / 4.0);
    fVar3 = (float)DAT_0073ad34 * 0.00025 - *(float *)(&DAT_0078eb64 + in_EAX * 4);
    if (0.0 <= fVar3) {
      if (fVar3 < 0.15) goto LAB_0042993e;
      *(float *)(&DAT_0078eb64 + in_EAX * 4) = (float)DAT_0073ad34 * 0.00025;
    }
    else {
      *(undefined4 *)(&DAT_0078eb64 + in_EAX * 4) = 0;
    }
    uVar5 = _ftol_nocw();
    FUN_0041a8c0(uVar5);
  }
LAB_0042993e:
  iVar4 = *(int *)(param_1 + 0x354);
  iVar2 = *(int *)(param_1 + 0x358);
  switch(iVar4) {
  case 8:
    uVar6 = 0x50;
    break;
  case 9:
    uVar6 = 0x50;
    break;
  case 10:
    uVar6 = 0x5a;
    break;
  case 0xb:
    uVar6 = 100;
    break;
  default:
    uVar6 = 0;
    break;
  case 0xf:
    uVar6 = 0x28;
  }
  switch(iVar2) {
  case 8:
    uVar5 = 0;
    uVar6 = uVar6 + 0x50;
    break;
  case 9:
    uVar5 = 0;
    uVar6 = uVar6 + 0x50;
    break;
  case 10:
    uVar5 = 1;
    uVar6 = uVar6 + 0x5a;
    break;
  case 0xb:
    uVar5 = 1;
    uVar6 = uVar6 + 100;
    break;
  default:
    uVar5 = 0;
    break;
  case 0xf:
    uVar5 = 2;
    uVar6 = uVar6 + 0x28;
  }
  uVar6 = uVar6 / 2;
  uVar7 = _ftol_nocw(uVar6);
  FUN_0041b210(DAT_00736500,uVar5,uVar7,uVar6);
  if (((iVar4 == 0xd) || (iVar2 == 0xd)) && (23.0 < fVar1)) {
    FUN_0041af40(DAT_00736500,10000);
    *(float *)(&DAT_0078eb6c + in_EAX * 4) = fVar1;
    return;
  }
  FUN_0041b150(DAT_00736500);
  *(float *)(&DAT_0078eb6c + in_EAX * 4) = fVar1;
  return;
}


// ==== 0x429ac0 FUN_00429ac0

float10 FUN_00429ac0(void)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)0.0;
  if (*(char *)(in_EAX + 0x350) != '\0') {
    fVar1 = (float10)0.25;
  }
  if (*(char *)(in_EAX + 0x351) != '\0') {
    fVar1 = fVar1 + (float10)0.25;
  }
  if (*(char *)(in_EAX + 0x352) != '\0') {
    fVar1 = fVar1 + (float10)0.25;
  }
  if (*(char *)(in_EAX + 0x353) != '\0') {
    fVar1 = fVar1 + (float10)0.25;
  }
  return fVar1;
}


// ==== 0x429b10 Racer::UpdateTwoHumanCatchUp

/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void Racer__UpdateTwoHumanCatchUp(void)

{
  int iVar1;
  int unaff_ESI;
  float10 fVar2;
  undefined *local_8;
  undefined4 local_4;
  
  if ((((*(int *)(*(int *)(unaff_ESI + 0x14) + 4) == 1) &&
       (*(char *)(*(int *)(unaff_ESI + 0x14) + 0x734) == '\0')) && (DAT_0078a400 != 0)) &&
     (DAT_007361c4 == 2)) {
    iVar1 = DAT_007361b8;
    if (*(int *)(*(int *)(unaff_ESI + 0x18) + 0x10) != 0) {
      iVar1 = DAT_007361b4;
    }
    local_8 = &DAT_0077a478;
    local_4 = 4;
    fVar2 = (float10)LinearTable__Lookup11
                               (&local_8,*(float *)(*(int *)(unaff_ESI + 0x1c) + 0x14) *
                                         DAT_007372b0 -
                                         *(float *)(*(int *)(*(int *)(iVar1 + 4) + 0x1c) + 0x14) *
                                         DAT_007372b0);
    *(float *)(unaff_ESI + 0x404) = (float)fVar2;
  }
  return;
}


// ==== 0x429ba0 FUN_00429ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429ba0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  fVar1 = *param_2 - *(float *)(param_1 + 0x60);
  fVar2 = param_2[1] - *(float *)(param_1 + 100);
  fVar4 = param_2[2] - *(float *)(param_1 + 0x68);
  fVar3 = _K_ONE / SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar4 * fVar4);
  fVar4 = (fVar3 * fVar2 * in_EAX[1] + fVar1 * fVar3 * *in_EAX + fVar4 * fVar3 * in_EAX[2] + _K_ONE)
          * _K_HALF;
  if (0.0 <= fVar3 * fVar2 * *in_EAX - fVar1 * fVar3 * in_EAX[1]) {
    fVar4 = fVar4 * -1.0;
  }
  *(float *)(param_1 + 0x8e4) = fVar4;
  return;
}


// ==== 0x429c50 FUN_00429c50

float10 FUN_00429c50(float param_1)

{
  float *unaff_ESI;
  float local_20;
  float local_1c;
  float local_18;
  
  if (param_1 < 0.1) {
    return SQRT((float10)unaff_ESI[2] * (float10)unaff_ESI[2] +
                (float10)unaff_ESI[1] * (float10)unaff_ESI[1] +
                (float10)*unaff_ESI * (float10)*unaff_ESI);
  }
  bNormalize3();
  return (float10)local_20 * (float10)*unaff_ESI +
         (float10)local_18 * (float10)unaff_ESI[2] + (float10)local_1c * (float10)unaff_ESI[1];
}


// ==== 0x429cc0 FUN_00429cc0

float10 FUN_00429cc0(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x80) * (float10)*(float *)(in_EAX + 0x90) +
         (float10)*(float *)(in_EAX + 0x84) * (float10)*(float *)(in_EAX + 0x94) +
         (float10)*(float *)(in_EAX + 0x88) * (float10)*(float *)(in_EAX + 0x98);
}


// ==== 0x429cf0 JumpCamPredict

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (C) docs/re/camera.md */

float10 JumpCamPredict(float param_1,float *param_2,float *param_3,char param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  undefined4 uVar5;
  float fVar6;
  int iVar7;
  float10 fVar8;
  float fStack_d4;
  int iStack_d0;
  float local_cc;
  float fStack_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b0;
  float local_ac;
  float local_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_8c;
  float local_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_64;
  undefined1 auStack_5c [4];
  float fStack_58;
  
  local_88 = *(float *)(in_EAX + 0x3d4);
  local_c4 = (float)(in_EAX + 0x540);
  iVar7 = *(int *)(in_EAX + 0x20);
  local_cc = ((*(float *)(iVar7 + 0x268) + *(float *)(iVar7 + 0x264)) * 0.3 * local_88) /
             *(float *)(iVar7 + 0x110) + _DAT_007000ac;
  FUN_00424ba0();
  local_b0 = 0.0;
  local_ac = 0.0;
  local_a8 = 0.0;
  uVar5 = FUN_00424e50();
  iVar7 = 0;
  do {
    local_b8 = -*(float *)(iVar7 + 0x20 + *(int *)(in_EAX + 0x20));
    local_c0 = 0.0;
    local_bc = 0.0;
    D3DXVec3Transform(&local_c0,&local_c0,uVar5);
    D3DXVec3Transform(&local_cc,&local_cc,auStack_5c);
    iVar7 = iVar7 + 0x30;
    local_b0 = local_c0 * 0.25 + local_b0;
    local_ac = local_bc * 0.25 + local_ac;
    local_a8 = local_b8 * 0.25 + local_a8;
  } while (iVar7 < 0xc0);
  fStack_9c = *(float *)(in_EAX + 0x74);
  fStack_a0 = *(float *)(in_EAX + 0x70);
  fStack_98 = *(float *)(in_EAX + 0x78);
  fStack_58 = -local_cc;
  fVar6 = (float)_ftol_nocw();
  fVar4 = local_c4;
  fStack_64 = (float)(int)fVar6;
  fVar1 = fStack_64 * param_1;
  local_cc = fVar6;
  fVar8 = (float10)GroundQuery__FindSurfaceBelow(local_c4,&local_b0,0,0,0);
  if ((float10)0.0 <= (float10)local_a8 - fVar8) {
    fStack_d4 = (float)((float10)local_a8 - fVar8);
  }
  else {
    fStack_d4 = 0.0;
  }
  local_c4 = fStack_d4;
  if (fStack_d4 <= 0.0) {
    fStack_c8 = 0.0;
    fStack_84 = 0.0;
  }
  else {
    fStack_84 = -fVar1;
    fStack_c8 = fVar1;
  }
  iStack_d0 = 1;
  fVar1 = fStack_c8;
  if (1 < (int)fVar6) {
    do {
      local_cc = ((float)iStack_d0 * param_1) / fStack_64;
      fVar1 = local_cc - fStack_84;
      fVar2 = fVar1 * _K_HALF * 0.0;
      local_c0 = (fStack_a0 + fVar2) * fVar1 + local_b0;
      local_bc = (fVar2 + fStack_9c) * fVar1 + local_ac;
      local_b8 = (fStack_58 * fVar1 * _K_HALF + fStack_98) * fVar1 + local_a8;
      fVar8 = (float10)GroundQuery__FindSurfaceBelow(fVar4,&local_c0,0,&fStack_80,0);
      fStack_8c = (float)((float10)local_b8 - fVar8);
      if ((float10)local_b8 - fVar8 <= (float10)0.0) {
        if (param_4 != '\0') break;
        local_a8 = (float)fVar8;
        local_ac = local_bc;
        local_b0 = local_c0;
        fVar1 = fStack_7c * fStack_98 - fStack_78 * fStack_9c;
        fVar3 = fStack_78 * fStack_a0 - fStack_98 * fStack_80;
        fVar2 = fStack_9c * fStack_80 - fStack_7c * fStack_a0;
        fStack_a0 = fVar3 * fStack_78 - fVar2 * fStack_7c;
        fStack_9c = fVar2 * fStack_80 - fStack_78 * fVar1;
        fStack_98 = fStack_7c * fVar1 - fVar3 * fStack_80;
        FUN_005673e0(local_88);
        fStack_84 = local_cc;
      }
      else {
        fStack_d4 = fStack_8c + fStack_d4;
        if (local_c4 <= fStack_8c) {
          local_c4 = fStack_8c;
        }
        if (fStack_c8 <= fVar1) {
          fStack_c8 = fVar1;
        }
      }
      iStack_d0 = iStack_d0 + 1;
      fVar1 = fStack_c8;
    } while (iStack_d0 < (int)fVar6);
  }
  fStack_c8 = fVar1;
  if (param_2 != (float *)0x0) {
    *param_2 = local_c4;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fStack_c8;
  }
  return (float10)fStack_d4 / (float10)iStack_d0;
}


// ==== 0x42a0c0 FUN_0042a0c0

float10 FUN_0042a0c0(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x3c) + 0x14c);
  if ((iVar1 != 0) && (iVar1 != 0x7fffffff)) {
    fVar2 = (float)(DAT_0073ad34 - iVar1) * 0.00025;
    if (fVar2 < 4.0) {
      fVar3 = (float10)LinearTable__Lookup11(&PTR_DAT_00706470,fVar2);
      return fVar3;
    }
  }
  return (float10)0.0;
}


// ==== 0x42a120 FUN_0042a120

void __fastcall FUN_0042a120(byte param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  int iVar4;
  
  if ((1 << (param_1 & 0x1f) & *(uint *)(param_3 + 0x530)) != 0) {
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[0xb] = 0;
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    *param_2 = 0x3f800000;
    param_2[5] = 0x3f800000;
    param_2[10] = 0x3f800000;
    param_2[0xf] = 0x3f800000;
    *in_EAX = 0x3f800000;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    in_EAX[4] = 0;
    in_EAX[5] = 0x3f800000;
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    in_EAX[8] = 0;
    in_EAX[9] = 0;
    in_EAX[10] = 0x3f800000;
    in_EAX[0xb] = 0;
    in_EAX[0xc] = 0;
    in_EAX[0xd] = 0;
    in_EAX[0xe] = 0;
    in_EAX[0xf] = 0x3f800000;
    iVar4 = *(int *)(param_3 + 0x20);
    uVar1 = *(undefined4 *)(iVar4 + 0x14);
    uVar2 = *(undefined4 *)(iVar4 + 0x18);
    param_2[0xc] = *(undefined4 *)(iVar4 + 0x10);
    param_2[0xf] = 0x3f800000;
    param_2[0xd] = uVar1;
    param_2[0xe] = uVar2;
    uVar1 = *(undefined4 *)(iVar4 + 0x14);
    uVar2 = *(undefined4 *)(iVar4 + 0x18);
    in_EAX[0xc] = *(undefined4 *)(iVar4 + 0x10);
    in_EAX[0xd] = uVar1;
    in_EAX[0xf] = 0x3f800000;
    in_EAX[0xe] = uVar2;
    param_2[0x10] = 0x3f800000;
    param_2[0x11] = 0;
    param_2[0x12] = 0;
    param_2[0x13] = 0;
    param_2[0x14] = 0;
    param_2[0x15] = 0x3f800000;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    param_2[0x1a] = 0x3f800000;
    param_2[0x1b] = 0;
    param_2[0x1c] = 0;
    param_2[0x1d] = 0;
    param_2[0x1e] = 0;
    param_2[0x1f] = 0x3f800000;
    in_EAX[0x10] = 0x3f800000;
    in_EAX[0x11] = 0;
    in_EAX[0x12] = 0;
    in_EAX[0x13] = 0;
    in_EAX[0x14] = 0;
    in_EAX[0x15] = 0x3f800000;
    in_EAX[0x16] = 0;
    in_EAX[0x17] = 0;
    in_EAX[0x18] = 0;
    in_EAX[0x19] = 0;
    in_EAX[0x1a] = 0x3f800000;
    in_EAX[0x1b] = 0;
    in_EAX[0x1c] = 0;
    in_EAX[0x1d] = 0;
    in_EAX[0x1e] = 0;
    in_EAX[0x1f] = 0x3f800000;
    iVar4 = *(int *)(param_3 + 0x20);
    uVar1 = *(undefined4 *)(iVar4 + 0x44);
    uVar2 = *(undefined4 *)(iVar4 + 0x48);
    param_2[0x1c] = *(undefined4 *)(iVar4 + 0x40);
    param_2[0x1f] = 0x3f800000;
    param_2[0x1d] = uVar1;
    param_2[0x1e] = uVar2;
    uVar1 = *(undefined4 *)(iVar4 + 0x44);
    uVar2 = *(undefined4 *)(iVar4 + 0x48);
    in_EAX[0x1c] = *(undefined4 *)(iVar4 + 0x40);
    in_EAX[0x1d] = uVar1;
    in_EAX[0x1f] = 0x3f800000;
    in_EAX[0x1e] = uVar2;
    param_2[0x20] = 0x3f800000;
    param_2[0x21] = 0;
    param_2[0x22] = 0;
    param_2[0x23] = 0;
    param_2[0x24] = 0;
    param_2[0x25] = 0x3f800000;
    param_2[0x26] = 0;
    param_2[0x27] = 0;
    param_2[0x28] = 0;
    param_2[0x29] = 0;
    param_2[0x2a] = 0x3f800000;
    param_2[0x2b] = 0;
    param_2[0x2c] = 0;
    param_2[0x2d] = 0;
    param_2[0x2e] = 0;
    param_2[0x2f] = 0x3f800000;
    in_EAX[0x20] = 0x3f800000;
    in_EAX[0x21] = 0;
    in_EAX[0x22] = 0;
    in_EAX[0x23] = 0;
    in_EAX[0x24] = 0;
    in_EAX[0x25] = 0x3f800000;
    in_EAX[0x26] = 0;
    in_EAX[0x27] = 0;
    in_EAX[0x28] = 0;
    in_EAX[0x29] = 0;
    in_EAX[0x2a] = 0x3f800000;
    in_EAX[0x2b] = 0;
    in_EAX[0x2c] = 0;
    in_EAX[0x2d] = 0;
    in_EAX[0x2e] = 0;
    in_EAX[0x2f] = 0x3f800000;
    iVar4 = *(int *)(param_3 + 0x20);
    uVar1 = *(undefined4 *)(iVar4 + 0x74);
    uVar2 = *(undefined4 *)(iVar4 + 0x78);
    param_2[0x2c] = *(undefined4 *)(iVar4 + 0x70);
    param_2[0x2f] = 0x3f800000;
    param_2[0x2d] = uVar1;
    param_2[0x2e] = uVar2;
    uVar1 = *(undefined4 *)(iVar4 + 0x74);
    uVar2 = *(undefined4 *)(iVar4 + 0x78);
    in_EAX[0x2c] = *(undefined4 *)(iVar4 + 0x70);
    in_EAX[0x2d] = uVar1;
    in_EAX[0x2f] = 0x3f800000;
    in_EAX[0x2e] = uVar2;
    param_2[0x30] = 0x3f800000;
    param_2[0x31] = 0;
    param_2[0x32] = 0;
    param_2[0x33] = 0;
    param_2[0x34] = 0;
    param_2[0x35] = 0x3f800000;
    param_2[0x36] = 0;
    param_2[0x37] = 0;
    param_2[0x38] = 0;
    param_2[0x39] = 0;
    param_2[0x3a] = 0x3f800000;
    param_2[0x3b] = 0;
    param_2[0x3c] = 0;
    param_2[0x3d] = 0;
    param_2[0x3e] = 0;
    param_2[0x3f] = 0x3f800000;
    in_EAX[0x30] = 0x3f800000;
    in_EAX[0x31] = 0;
    in_EAX[0x32] = 0;
    in_EAX[0x33] = 0;
    in_EAX[0x34] = 0;
    in_EAX[0x35] = 0x3f800000;
    in_EAX[0x36] = 0;
    in_EAX[0x37] = 0;
    in_EAX[0x38] = 0;
    in_EAX[0x39] = 0;
    in_EAX[0x3a] = 0x3f800000;
    in_EAX[0x3b] = 0;
    in_EAX[0x3c] = 0;
    in_EAX[0x3d] = 0;
    in_EAX[0x3e] = 0;
    in_EAX[0x3f] = 0x3f800000;
    iVar4 = *(int *)(param_3 + 0x20);
    uVar1 = *(undefined4 *)(iVar4 + 0xa4);
    uVar2 = *(undefined4 *)(iVar4 + 0xa8);
    param_2[0x3c] = *(undefined4 *)(iVar4 + 0xa0);
    param_2[0x3d] = uVar1;
    param_2[0x3f] = 0x3f800000;
    param_2[0x3e] = uVar2;
    uVar1 = *(undefined4 *)(iVar4 + 0xa4);
    uVar2 = *(undefined4 *)(iVar4 + 0xa8);
    uVar3 = *(undefined4 *)(iVar4 + 0xa0);
    in_EAX[0x3f] = 0x3f800000;
    in_EAX[0x3d] = uVar1;
    in_EAX[0x3e] = uVar2;
    in_EAX[0x3c] = uVar3;
    return;
  }
  iVar4 = 4;
  do {
    FUN_00401cd0();
    FUN_00401cd0();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


// ==== 0x42a4d0 FUN_0042a4d0

void FUN_0042a4d0(void)

{
  int unaff_ESI;
  float10 fVar1;
  char local_1;
  
  if ((((*(char *)(*(int *)(unaff_ESI + 0x3c) + 0x1c) != '\0') && (*(int *)(unaff_ESI + 0x3cc) == 4)
       ) && (fVar1 = (float10)GroundQuery__FindSurfaceBelow
                                        (unaff_ESI + 0x540,unaff_ESI + 0x60,0,0,&local_1),
            local_1 != '\0')) && ((float10)*(float *)(unaff_ESI + 0x68) + (float10)0.25 < fVar1)) {
    FUN_00428080();
    return;
  }
  return;
}


// ==== 0x42a530 FUN_0042a530

void __fastcall FUN_0042a530(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 0) {
    if ('\0' < *(char *)(*(int *)(param_1 + 0x3c) + 0x1c)) {
      *(undefined4 *)(param_1 + 0x38) = 2;
    }
    return;
  }
  if (iVar1 == 1) {
    if ((*(char *)(*(int *)(param_1 + 0x3c) + 0x1c) != '\0') || (*(int *)(param_1 + 0x3cc) != 4)) {
      *(undefined4 *)(param_1 + 0x4cc) = 0;
      return;
    }
    if (*(float *)(param_1 + 0x4cc) == 0.0) {
      *(float *)(param_1 + 0x4cc) = (float)DAT_0073ad34 * 0.00025;
      return;
    }
    if ((float)DAT_0073ad34 * 0.00025 - *(float *)(param_1 + 0x4cc) < 0.1) {
      return;
    }
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x3c) + 0x1c) != '\0') {
      return;
    }
    if (*(int *)(param_1 + 0x3cc) != 4) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}


// ==== 0x42a5c0 FUN_0042a5c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042a5c0(undefined4 param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *extraout_EDX;
  int unaff_ESI;
  
  param_2[1] = 0.0;
  param_2[2] = 0.0;
  param_2[3] = 0.0;
  param_2[4] = 0.0;
  param_2[6] = 0.0;
  param_2[7] = 0.0;
  param_2[8] = 0.0;
  param_2[9] = 0.0;
  param_2[0xb] = 0.0;
  param_2[0xc] = 0.0;
  param_2[0xd] = 0.0;
  param_2[0xe] = 0.0;
  *param_2 = 1.0;
  param_2[5] = 1.0;
  param_2[0xf] = 1.0;
  param_2[10] = 1.0;
  fVar1 = ABS(_K_ONE - *(float *)(unaff_ESI + 0x98));
  if (fVar1 < 0.001 == (fVar1 == 0.001)) {
    *param_2 = *(float *)(unaff_ESI + 0x90);
    param_2[1] = *(float *)(unaff_ESI + 0x94);
  }
  else {
    *param_2 = -*(float *)(unaff_ESI + 0xb0);
    param_2[1] = -*(float *)(unaff_ESI + 0xb4);
  }
  bNormalize2();
  extraout_EDX[4] = extraout_EDX[2] * extraout_EDX[9] - extraout_EDX[1] * extraout_EDX[10];
  extraout_EDX[5] = *extraout_EDX * extraout_EDX[10] - extraout_EDX[2] * extraout_EDX[8];
  extraout_EDX[6] = extraout_EDX[8] * extraout_EDX[1] - *extraout_EDX * extraout_EDX[9];
  fVar3 = *(float *)(unaff_ESI + 0x60);
  fVar1 = *(float *)(unaff_ESI + 100);
  fVar2 = *(float *)(unaff_ESI + 0x68);
  extraout_EDX[0xf] = 1.0;
  extraout_EDX[0xc] = fVar3;
  extraout_EDX[0xd] = fVar1;
  extraout_EDX[0xe] = fVar2;
  return;
}


// ==== 0x42a690 FUN_0042a690

uint FUN_0042a690(void)

{
  uint in_EAX;
  
  if (*(int *)(in_EAX + 0x28) == 1) {
    return (uint)(*(int *)(*(int *)(*(int *)(in_EAX + 0x34) + 0x48) + 0x94) != 0);
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x42a6b0 FUN_0042a6b0

float10 __fastcall FUN_0042a6b0(undefined1 *param_1)

{
  int iVar1;
  int in_EAX;
  
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 0;
  }
  if (*(int *)(in_EAX + 0x28) == 1) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x34) + 0x48);
    if (param_1 != (undefined1 *)0x0) {
      if (0.0 < *(float *)(iVar1 + 0xa8)) {
        *param_1 = 1;
        return (float10)*(float *)(iVar1 + 0xa4);
      }
      *param_1 = 0;
    }
    return (float10)*(float *)(iVar1 + 0xa4);
  }
  return (float10)0.0;
}


// ==== 0x42a710 FUN_0042a710

void FUN_0042a710(undefined4 *param_1)

{
  int in_EAX;
  int unaff_ESI;
  undefined1 local_90 [48];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [36];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  FUN_00401cd0();
  local_5c = *(undefined4 *)(unaff_ESI + 100);
  local_60 = *(undefined4 *)(unaff_ESI + 0x60);
  local_58 = *(undefined4 *)(unaff_ESI + 0x68);
  local_54 = 0x3f800000;
  D3DXMatrixMultiply(local_50,in_EAX * 0x40 + 0xf0 + unaff_ESI,local_90);
  *param_1 = uStack_2c;
  param_1[1] = uStack_28;
  param_1[2] = uStack_24;
  return;
}


// ==== 0x42a790 FUN_0042a790

void FUN_0042a790(void)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0073458c != 0) {
    DAT_0073458c = 0;
    piVar2 = (int *)*DAT_007361f8;
    if (piVar2 != DAT_007361f8) {
      do {
        RideInfo__RebuildPhysicsInfo(1);
        if (piVar2[10] == 1) {
          iVar1 = *(int *)(piVar2[0xd] + 0x4c);
          FUN_0046d1c0(*(undefined4 *)(iVar1 + 0x18),iVar1 + 0x80);
          *(float *)(iVar1 + 0x84) =
               *(float *)(*(int *)(iVar1 + 0x1c) + 0x5c) * *(float *)(iVar1 + 0x84);
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != DAT_007361f8);
    }
  }
  return;
}


// ==== 0x42a810 FUN_0042a810

void __fastcall FUN_0042a810(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  if ((in_EAX != (undefined4 *)0x0) && (param_2 != 0)) {
    *(undefined1 *)(param_1 + 0x88c) = 1;
    uVar1 = in_EAX[2];
    uVar2 = in_EAX[3];
    uVar3 = *in_EAX;
    *(undefined4 *)(param_1 + 0x894) = in_EAX[1];
    *(undefined4 *)(param_1 + 0x890) = uVar3;
    *(undefined4 *)(param_1 + 0x898) = uVar1;
    *(undefined4 *)(param_1 + 0x89c) = uVar2;
    return;
  }
  *(undefined1 *)(param_1 + 0x88c) = 0;
  return;
}


// ==== 0x42a860 FUN_0042a860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042a860(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  int unaff_ESI;
  float10 fVar7;
  float fStack_34;
  undefined1 auStack_30 [8];
  undefined4 uStack_28;
  
  if (((*(int **)(unaff_ESI + 0x34) != (int *)0x0) && (*(int *)(unaff_ESI + 0x30) != 0)) &&
     (*(int *)(unaff_ESI + 0x1c) != 0)) {
    iVar6 = (**(code **)(**(int **)(unaff_ESI + 0x34) + 0xc))();
    if (iVar6 != 0) {
      fVar3 = *(float *)(unaff_ESI + 0x3d4);
      fVar7 = (float10)FUN_00401c80(fVar3,0x3f800000,0x41f00000);
      if (((fVar7 == (float10)fVar3) && (0.1 <= *(float *)(unaff_ESI + 0xb8))) &&
         (2 < *(int *)(unaff_ESI + 0x3cc))) {
        sVar5 = (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x80))();
        if (sVar5 != 0) {
          fVar7 = (float10)FUN_00436d60();
          fVar7 = (float10)LinearTable__Lookup11(&PTR_DAT_00706490,(float)fVar7);
          fVar7 = -(fVar7 * (float10)*(float *)(iVar6 + 0x144));
          fVar3 = *(float *)(iVar6 + 0xc4);
          fVar1 = *(float *)(iVar6 + 200);
          FUN_00584e00();
          Angle16SinCos();
          uStack_28 = 0;
          D3DXVec3Transform(auStack_30,auStack_30,unaff_ESI + 0x90);
          fVar2 = *(float *)(unaff_ESI + 0x74);
          fVar4 = *(float *)(unaff_ESI + 0x70);
          bNormalize3();
          FUN_00567540();
          FUN_005673e0(((fStack_34 * 0.0 +
                        fVar4 * (float)((float10)fVar3 * fVar7) +
                        (float)((float10)fVar1 * fVar7) * fVar2) - _K_ONE) *
                       *(float *)(iVar6 + 0x144) * 50.0);
          FUN_00584e00();
        }
      }
    }
  }
  return;
}


// ==== 0x42aa10 FUN_0042aa10

undefined4 __fastcall FUN_0042aa10(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 0;
  do {
    if (*(char *)(param_2 + 0x350 + iVar2) != '\0') {
      fVar1 = *(float *)(*(int *)(param_2 + 0x40) + 0x1c0);
      if (fVar1 <= 0.9) {
        if (0.1 <= fVar1) {
          return 0;
        }
        if (iVar2 == 1) {
          return 0;
        }
        bVar3 = iVar2 == 0;
      }
      else {
        if (iVar2 == 2) {
          return 0;
        }
        bVar3 = iVar2 == 3;
      }
      if (bVar3) {
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
    if (3 < iVar2) {
      return 1;
    }
  } while( true );
}


// ==== 0x42aa70 FUN_0042aa70

undefined4 FUN_0042aa70(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < *(int *)(in_EAX + 0x3cc)) {
    return 1;
  }
  iVar3 = (int)*(char *)(*(int *)(in_EAX + 0x3c) + 0x1c);
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = FUN_00468820(iVar4);
      iVar1 = *(int *)(*(int *)(iVar2 + 100) + 600);
      if (((*(char *)(iVar1 + 0x15) == '\x03') &&
          (0.7 < ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)))) ||
         ((iVar1 = *(int *)(*(int *)(iVar2 + 100) + 0x25c), *(char *)(iVar1 + 0x15) == '\x03' &&
          (0.7 < ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)))))) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return 0;
}


// ==== 0x42ab00 FUN_0042ab00

bool __fastcall FUN_0042ab00(undefined4 param_1,int *param_2)

{
  int *in_EAX;
  
  return *param_2 < *in_EAX;
}


// ==== 0x42ab10 FUN_0042ab10

bool __fastcall FUN_0042ab10(undefined4 param_1,int *param_2)

{
  int *in_EAX;
  
  return *in_EAX < *param_2;
}


// ==== 0x42ab20 FUN_0042ab20

int __fastcall FUN_0042ab20(int param_1)

{
  return *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x34) +
         *(int *)(param_1 + 0x30);
}


// ==== 0x42ab30 FUN_0042ab30

undefined4 FUN_0042ab30(void)

{
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x56) == '\0') && (DAT_007361a0 == 0)) {
    return 0;
  }
  return 1;
}


// ==== 0x42ab50 IsCar1099InMode4

/* [canon] camera low (ghidra+hopper) docs/re/tuning.md */

undefined4 IsCar1099InMode4(void)

{
  int *in_EAX;
  
  if (((*in_EAX == 1099) && (DAT_00735fb0 != 0)) && (DAT_00735fb8 == 4)) {
    return 1;
  }
  return 0;
}


// ==== 0x42ab80 FUN_0042ab80

float10 __fastcall FUN_0042ab80(int param_1)

{
  if ((*(int *)(param_1 + 0x3b8) != 0) && (*(int *)(param_1 + 0x3b8) != 0x7fffffff)) {
    return (float10)*(int *)(param_1 + 0x3b8) * (float10)0.00025;
  }
  return (float10)0.0;
}


// ==== 0x42abb0 FUN_0042abb0

void FUN_0042abb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  SpecialCamCaller_431960(param_1,param_3);
  return;
}


// ==== 0x42abd0 FUN_0042abd0

void FUN_0042abd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0042deb0(param_1,param_2,param_3);
  return;
}


// ==== 0x42abf0 FUN_0042abf0

void FUN_0042abf0(void)

{
  int in_EAX;
  
  if (*(char *)(*(int *)(in_EAX + 0x998) + 0x14) != '\0') {
    FUN_00436230(0x3f800000);
  }
  return;
}


// ==== 0x42ac10 FUN_0042ac10

undefined4 FUN_0042ac10(void)

{
  int *in_EAX;
  
  if ((*in_EAX != 7) && (*in_EAX != 0xb)) {
    return 0;
  }
  return 1;
}


// ==== 0x42ac30 FUN_0042ac30

undefined4 __fastcall FUN_0042ac30(int *param_1)

{
  if (((*param_1 == 7) || (*param_1 == 0xb)) && ((param_1[8] == 2 || (param_1[8] == 3)))) {
    return 1;
  }
  return 0;
}


// ==== 0x42ac60 FUN_0042ac60

int FUN_0042ac60(void)

{
  int in_EAX;
  
  return (int)*(char *)(in_EAX + 9);
}


// ==== 0x42ac70 FUN_0042ac70

void __fastcall FUN_0042ac70(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== 0x42ac80 FUN_0042ac80

void __fastcall FUN_0042ac80(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[2] != 0) || (param_1[3] != 0)) {
    iVar1 = *param_1;
    piVar2 = (int *)param_1[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x42acb0 FUN_0042acb0

void FUN_0042acb0(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 *unaff_ESI;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_0059d350(&local_20,param_2,in_EAX);
  *unaff_ESI = local_20;
  unaff_ESI[1] = local_1c;
  unaff_ESI[2] = local_18;
  return;
}


// ==== 0x42acf0 FUN_0042acf0

void __thiscall FUN_0042acf0(float *param_1,float param_2)

{
  param_1[2] = param_2;
  if (param_2 != *param_1) {
    *(undefined2 *)(param_1 + 0xb) = 2;
  }
  return;
}


// ==== 0x42ad10 CameraMoverBase_InitFields

/* [canon] camera high (hopper+capstone) docs/re/misc.md */

void __fastcall
CameraMoverBase_InitFields
          (undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  *(undefined2 *)(in_EAX + 0xb) = 0;
  *(undefined2 *)((int)in_EAX + 0x2e) = param_2;
  in_EAX[9] = param_3;
  in_EAX[10] = param_4;
  in_EAX[0x15] = param_3;
  in_EAX[0x16] = param_4;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0xf] = 0;
  *(undefined2 *)(in_EAX + 0x17) = 0;
  *(undefined2 *)((int)in_EAX + 0x5e) = param_2;
  in_EAX[0x21] = param_3;
  in_EAX[0x22] = param_4;
  in_EAX[0x18] = 0;
  in_EAX[0x19] = 0;
  in_EAX[0x1a] = 0;
  in_EAX[0x1b] = 0;
  *(undefined2 *)(in_EAX + 0x23) = 0;
  *(undefined2 *)((int)in_EAX + 0x8e) = param_2;
  return;
}


// ==== 0x42ad90 FUN_0042ad90

void FUN_0042ad90(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = in_EAX[2];
  in_EAX[1] = in_EAX[3];
  *(undefined2 *)(in_EAX + 0xb) = 0;
  in_EAX[0xc] = in_EAX[0xe];
  in_EAX[0xd] = in_EAX[0xf];
  *(undefined2 *)(in_EAX + 0x17) = 0;
  in_EAX[0x18] = in_EAX[0x1a];
  in_EAX[0x19] = in_EAX[0x1b];
  *(undefined2 *)(in_EAX + 0x23) = 0;
  return;
}


// ==== 0x42add0 FUN_0042add0

undefined4 FUN_0042add0(void)

{
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0xc) != 1) && (*(int *)(in_EAX + 0xc) != 0x11)) {
    return 0;
  }
  return 1;
}


// ==== 0x42adf0 FUN_0042adf0

float10 __fastcall FUN_0042adf0(int param_1)

{
  int in_EAX;
  
  return (float10)((uint)*(byte *)(param_1 + 0x6a + in_EAX) << 0x10) * (float10)1.5258789e-05;
}


// ==== 0x42ae10 TrackRow_Current

/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined4 TrackRow_Current(void)

{
  return DAT_00736174;
}


// ==== 0x42ae20 SpawnRecord_Get

/* [canon] traffic high (H+G) docs/re/traffic.md */

int SpawnRecord_Get(void)

{
  int in_EAX;
  
  return in_EAX * 0x108 + DAT_00736160;
}


// ==== 0x42ae30 SpawnRecord_Count

/* [canon] traffic high (H+G) docs/re/traffic.md */

undefined4 SpawnRecord_Count(void)

{
  return DAT_00736164;
}


// ==== 0x42ae40 FUN_0042ae40

int FUN_0042ae40(void)

{
  int in_EAX;
  
  return in_EAX + 0x19;
}


// ==== 0x42ae50 FUN_0042ae50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0042ae50(int *param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined *puVar4;
  void *pvVar5;
  int iVar6;
  undefined1 local_2d0 [32];
  int aiStack_2b0 [160];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_006861ec;
  local_10 = ExceptionList;
  piVar1 = param_1 + 3;
  ExceptionList = &local_10;
  param_1[2] = 0;
  param_1[8] = 1;
  param_1[5] = 2;
  *piVar1 = 100;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0;
  param_1[9] = 0x4000;
  param_1[0xe] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  local_8 = 0;
  if (param_3 < 1) {
    param_3 = 0;
  }
  else if (2 < param_3) {
    param_3 = 2;
  }
  puVar4 = (&PTR_PTR_006fbddc)[param_3];
  iVar6 = *(int *)(puVar4 + 0x20);
  param_1[0x16] = (int)(puVar4 + 0x24);
  param_1[0x17] = iVar6;
  iVar6 = *(int *)(puVar4 + 0x4c);
  param_1[0x18] = (int)(puVar4 + 0x50);
  param_1[0x19] = iVar6;
  iVar6 = *(int *)(puVar4 + 0x78);
  param_1[0x1a] = (int)(puVar4 + 0x7c);
  param_1[0x1b] = iVar6;
  param_1[0xf] = (int)piVar1;
  param_1[0x10] = 0;
  FUN_00490560(param_1 + 0xf,puVar4);
  fVar3 = _K_ONE;
  *param_1 = param_2;
  fVar2 = _K_ONE;
  if ((fVar3 < (float)param_4) && (fVar2 = (float)param_4, 20.0 < (float)param_4)) {
    fVar2 = 20.0;
  }
  param_1[1] = (int)fVar2;
  param_1[2] = DAT_0073ad34;
  fVar2 = *(float *)(*(int *)(param_2 + 4) + 0x3d4);
  fVar3 = (float)param_1[1];
  pvVar5 = _malloc(0x18);
  local_8._0_1_ = 2;
  if (pvVar5 == (void *)0x0) {
    param_4 = (int *)0x0;
  }
  else {
    param_4 = (int *)FUN_00492e70(pvVar5,0x42200000,fVar2 * fVar3 + 100.0);
  }
  local_8._0_1_ = 1;
  if ((*param_4 != 0) && (3 < param_4[1])) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_00440740();
    local_8._0_1_ = 3;
    FUN_00494180(local_2d0,piVar1,0,0,0);
    iVar6 = 0;
    local_8._0_1_ = 1;
    if (0 < local_30) {
      do {
        *(char *)(aiStack_2b0[iVar6] + 8) = *(char *)(aiStack_2b0[iVar6] + 8) + -1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < local_30);
    }
  }
  local_8._0_1_ = 1;
  if (*param_4 != 0) {
    FUN_00565ce0();
  }
  _free(param_4);
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x42b040 FUN_0042b040

void FUN_0042b040(int param_1)

{
  void *pvVar1;
  int extraout_EDX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068504b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00490730();
  pvVar1 = *(void **)(extraout_EDX + 0xc);
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0xc0,*(int *)((int)pvVar1 + -0x10),FUN_00401db0);
    _free((void *)((int)pvVar1 + -0x10));
  }
  if (*(void **)(param_1 + 0x1c) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x1c));
  }
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x38));
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x42b0d0 FUN_0042b0d0

undefined4 * FUN_0042b0d0(undefined4 *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  undefined1 local_40 [36];
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00688629;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  puVar5 = param_1 + 0x1c;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  param_1[0x28] = 0;
  param_1[0x2b] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x45] = 0;
  param_1[0x12f] = 0;
  param_1[0x21c] = 0;
  param_1[0x21d] = 0;
  param_1[0x21e] = 0;
  param_1[0x21f] = 0;
  param_1[0x221] = 0;
  param_1[0x222] = 0;
  param_1[0x223] = 0;
  FUN_00440740();
  local_14 = 0;
  FUN_00431810();
  param_1[0x245] = 0;
  local_14._0_1_ = 1;
  param_1[0x255] = 0;
  FUN_004367e0(param_1 + 600);
  local_14._0_1_ = 2;
  FUN_0043dc40();
  param_1[0x299] = 0;
  param_1[0x291] = param_1 + 600;
  param_1[0x290] = param_1;
  param_1[0x299] = 0;
  param_1[0x29a] = 0;
  *(undefined1 *)((int)param_1 + 0xa4b) = 0;
  *(undefined1 *)(param_1 + 0x293) = 0;
  *(undefined1 *)((int)param_1 + 0xa4d) = 0;
  *(undefined1 *)(param_1 + 0x292) = 1;
  *(undefined1 *)((int)param_1 + 0xa49) = 1;
  *(undefined1 *)((int)param_1 + 0xa4a) = 1;
  *(undefined1 *)((int)param_1 + 0xa4e) = 0;
  *(undefined1 *)(param_1 + 0x295) = 0;
  param_1[0x29b] = 0xffffffff;
  (&DAT_007361bc)[DAT_007361c4] = (int)param_1;
  DAT_007361c4 = DAT_007361c4 + 1;
  local_14._0_1_ = 3;
  (&DAT_007361b4)[param_3] = param_1;
  FUN_0042bac0();
  iVar7 = 0xf;
  pcVar8 = (char *)(param_1 + 0xd);
  pcVar2 = &DAT_007588c4 + param_3 * 0xf944;
  do {
    iVar7 = iVar7 + -1;
    cVar1 = *pcVar2;
    *pcVar8 = cVar1;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  } while (iVar7 != 0);
  bVar9 = DAT_007361c4 == 2;
  param_1[5] = 0;
  if (bVar9) {
    *(int *)(DAT_007361bc + 0x14) = DAT_007361c0;
    *(int *)(DAT_007361c0 + 0x14) = DAT_007361bc;
  }
  param_1[2] = param_2;
  param_1[3] = (uint)(byte)(&DAT_007306c4)[param_2];
  param_1[4] = param_3;
  param_1[0x9e] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x236] = 0;
  param_1[0x237] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  param_1[0x27] = 0;
  param_1[0x29] = 0;
  iVar7 = 0;
  puVar5 = param_1 + 0x1c;
  do {
    *puVar5 = 0;
    *(undefined1 *)((int)param_1 + iVar7 + 0x68) = 0;
    iVar7 = iVar7 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar7 < 8);
  if (DAT_0078a320 == 2) {
    param_1[7] = 0;
    param_1[6] = (param_3 != 0) + 1;
  }
  else {
    param_1[6] = 1;
    param_1[7] = 3;
  }
  param_1[0x24] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[599] = 0;
  if (DAT_0078a320 == 2) {
    if (param_3 == 0) {
      pvVar3 = _malloc(0x60);
      local_14 = CONCAT31(local_14._1_3_,4);
      if (pvVar3 == (void *)0x0) goto LAB_0042b481;
      uVar4 = HudManager__HudManager(0);
    }
    else {
      if (param_3 != 1) goto LAB_0042b48e;
      pvVar3 = _malloc(0x60);
      local_14 = CONCAT31(local_14._1_3_,5);
      if (pvVar3 == (void *)0x0) goto LAB_0042b481;
      uVar4 = HudManager__HudManager(1);
    }
  }
  else {
    if (DAT_0078a320 != 1) goto LAB_0042b48e;
    if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
      if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
        pvVar3 = _malloc(0x60);
        local_14 = CONCAT31(local_14._1_3_,8);
        if (pvVar3 == (void *)0x0) {
LAB_0042b481:
          uVar4 = 0;
        }
        else {
          uVar4 = HudManager__HudManager(param_3);
        }
      }
      else {
        pvVar3 = _malloc(0x60);
        local_14 = CONCAT31(local_14._1_3_,7);
        if (pvVar3 == (void *)0x0) goto LAB_0042b481;
        uVar4 = HudManager__HudManager(param_3);
      }
    }
    else {
      pvVar3 = _malloc(0x60);
      local_14 = CONCAT31(local_14._1_3_,6);
      if (pvVar3 == (void *)0x0) goto LAB_0042b481;
      uVar4 = HudManager__HudManager(param_3);
    }
  }
  local_14._0_1_ = 3;
  param_1[599] = uVar4;
LAB_0042b48e:
  param_1[0x14b] = 0;
  param_1[0x14a] = 0;
  param_1[0x148] = 0;
  param_1[0x14c] = 0;
  param_1[0x153] = 0;
  *(undefined1 *)(param_1 + 0x154) = 0;
  param_1[0x156] = 0;
  param_1[0x14f] = 0;
  param_1[1] = 0;
  param_1[0x14d] = 0;
  param_1[0x14e] = 0;
  FUN_00565da0("Player%d",1 - param_3);
  pvVar3 = _malloc(0x140);
  local_14._0_1_ = 9;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0058d010(pvVar3,local_40,param_3);
  }
  param_1[0xaa] = uVar4;
  param_1[0xa8] = 0xffffffff;
  param_1[0xa7] = 0xffffffff;
  local_14 = CONCAT31(local_14._1_3_,3);
  *param_1 = 0;
  param_1[0xa9] = 0;
  puVar5 = param_1 + 0xcb;
  iVar7 = 0x20;
  do {
    puVar5[-0x20] = 0;
    *puVar5 = 0;
    puVar5[0x20] = 0;
    puVar5[0x40] = 0;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  param_1[0x9d] = 0;
  puVar5 = _malloc(0x28);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar5 + 1) = 4;
    *(undefined1 *)((int)puVar5 + 5) = 10;
    *(undefined1 *)((int)puVar5 + 6) = 0;
    *(undefined1 *)((int)puVar5 + 7) = 0;
    *puVar5 = &PTR_FUN_006b9694;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = puVar5 + 5;
    puVar6 = _malloc(0x28);
    puVar5[4] = puVar6;
    for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
  }
  param_1[0x2a] = puVar5;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x150] = 0;
  *(undefined1 *)((int)param_1 + 0x8d5) = 0;
  param_1[0x2f] = 0;
  pvVar3 = _malloc(0xa4);
  param_1[0x157] = pvVar3;
  pvVar3 = _malloc(0x200);
  param_1[0x170] = pvVar3;
  param_1[0x171] = 0;
  param_1[0x172] = 0xffffffff;
  param_1[0x173] = 0xffffffff;
  *(undefined1 *)(param_1 + 299) = 0;
  *(undefined1 *)((int)param_1 + 0x4ad) = 0;
  *(undefined1 *)((int)param_1 + 0x4ae) = 0;
  *(undefined1 *)((int)param_1 + 0x4af) = 0;
  param_1[0x226] = 0;
  param_1[0x225] = 0;
  FUN_00565da0(&DAT_006ca910);
  FUN_00565da0(&DAT_006ca910);
  uVar4 = DAT_00700ae8;
  *(undefined1 *)((int)param_1 + 0x8d6) = 0;
  param_1[0x12e] = 0;
  param_1[0x12f] = 0;
  param_1[0x155] = uVar4;
  param_1[0x151] = 0;
  param_1[0x152] = 0;
  *(undefined1 *)((int)param_1 + 0x551) = 1;
  param_1[0x244] = 0;
  *(undefined1 *)(param_1 + 0x246) = 0;
  uVar4 = _ftol_nocw();
  param_1[0x245] = uVar4;
  *(undefined1 *)((int)param_1 + 0x921) = 0;
  param_1[0x249] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x24a) = 0;
  param_1[0x24b] = 0;
  *(undefined1 *)(param_1 + 0x24c) = 0;
  param_1[0x24d] = 0;
  *(undefined1 *)(param_1 + 0x235) = 1;
  param_1[0x24f] = 0;
  *(undefined1 *)(param_1 + 0x250) = 0;
  *(undefined1 *)((int)param_1 + 0x941) = 0;
  param_1[0x255] = 0x7fffffff;
  *(undefined1 *)(param_1 + 0x256) = 0;
  param_1[0x70] = param_1[0x70] & 0xffffffe0;
  param_1[0x6b] = 0x40a00000;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6c] = 0x3f800000;
  *(undefined2 *)(param_1 + 0x71) = 0;
  *(undefined2 *)((int)param_1 + 0x1c6) = 0;
  *(undefined2 *)(param_1 + 0x72) = 0x32dc;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  puVar5 = _malloc(0x90);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[9] = 0x3f800000;
    puVar5[10] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0xb) = 0;
    *(undefined2 *)((int)puVar5 + 0x2e) = 1;
    puVar5[0xc] = 0;
    puVar5[0xd] = 0;
    puVar5[0xe] = 0;
    puVar5[0xf] = 0;
    puVar5[0x15] = 0x3f800000;
    puVar5[0x16] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0x17) = 0;
    *(undefined2 *)((int)puVar5 + 0x5e) = 1;
    puVar5[0x18] = 0;
    puVar5[0x19] = 0;
    puVar5[0x1a] = 0;
    puVar5[0x1b] = 0;
    puVar5[0x21] = 0x3f800000;
    puVar5[0x22] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0x23) = 0;
    *(undefined2 *)((int)puVar5 + 0x8e) = 1;
  }
  param_1[0x78] = puVar5;
  *(undefined2 *)((int)puVar5 + 0x2e) = 1;
  *(undefined2 *)((int)puVar5 + 0x5e) = 1;
  *(undefined2 *)((int)puVar5 + 0x8e) = 1;
  iVar7 = param_1[0x78];
  *(undefined4 *)(iVar7 + 0x58) = 0x41200000;
  *(undefined4 *)(iVar7 + 0x28) = 0x41200000;
  *(undefined4 *)(iVar7 + 0x88) = 0x41200000;
  iVar7 = param_1[0x78];
  *(undefined4 *)(iVar7 + 0x24) = 0x3f000000;
  *(undefined4 *)(iVar7 + 0x54) = 0x3f000000;
  *(undefined4 *)(iVar7 + 0x84) = 0x3f000000;
  puVar5 = _malloc(0x90);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[9] = 0x3f800000;
    puVar5[10] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0xb) = 0;
    *(undefined2 *)((int)puVar5 + 0x2e) = 1;
    puVar5[0xc] = 0;
    puVar5[0xd] = 0;
    puVar5[0xe] = 0;
    puVar5[0xf] = 0;
    puVar5[0x15] = 0x3f800000;
    puVar5[0x16] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0x17) = 0;
    *(undefined2 *)((int)puVar5 + 0x5e) = 1;
    puVar5[0x18] = 0;
    puVar5[0x19] = 0;
    puVar5[0x1a] = 0;
    puVar5[0x1b] = 0;
    puVar5[0x21] = 0x3f800000;
    puVar5[0x22] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0x23) = 0;
    *(undefined2 *)((int)puVar5 + 0x8e) = 1;
  }
  param_1[0x79] = puVar5;
  *(undefined2 *)((int)puVar5 + 0x2e) = 1;
  *(undefined2 *)((int)puVar5 + 0x5e) = 1;
  *(undefined2 *)((int)puVar5 + 0x8e) = 1;
  iVar7 = param_1[0x79];
  *(undefined4 *)(iVar7 + 0x28) = 0x41200000;
  *(undefined4 *)(iVar7 + 0x88) = 0x41200000;
  *(undefined4 *)(iVar7 + 0x58) = 0x41200000;
  iVar7 = param_1[0x79];
  *(undefined4 *)(iVar7 + 0x24) = 0x3f000000;
  *(undefined4 *)(iVar7 + 0x84) = 0x3f000000;
  *(undefined4 *)(iVar7 + 0x54) = 0x3f000000;
  *(ushort *)(param_1 + 0x31) = *(ushort *)(param_1 + 0x31) & 0xfe00;
  *(undefined1 *)((int)param_1 + 0xc6) = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  *(undefined1 *)(param_1 + 0x3f) = 1;
  *(undefined1 *)((int)param_1 + 199) = 1;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x40] = 0;
  param_1[0x50] = 0x3f800000;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0x3f800000;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0x3f800000;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0x3f800000;
  param_1[0x41] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  *(undefined1 *)(param_1 + 0x49) = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0xffffffff;
  puVar5 = _malloc(0x30);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[9] = 0x3f800000;
    puVar5[10] = 0x3f800000;
    *(undefined2 *)(puVar5 + 0xb) = 0;
    *(undefined2 *)((int)puVar5 + 0x2e) = 1;
  }
  param_1[0x42] = puVar5;
  *puVar5 = 0;
  if ((float)puVar5[2] != 0.0) {
    *(undefined2 *)(puVar5 + 0xb) = 2;
  }
  iVar7 = param_1[0x42];
  *(undefined4 *)(iVar7 + 4) = 0;
  if (*(float *)(iVar7 + 0xc) != 0.0) {
    *(undefined2 *)(iVar7 + 0x2c) = 2;
  }
  param_1[0x45] = 0;
  param_1[100] = 0;
  *(undefined1 *)(param_1 + 0x9c) = 0;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x42bac0 FUN_0042bac0

void __fastcall FUN_0042bac0(undefined1 *param_1)

{
  undefined1 *in_EAX;
  int iVar1;
  undefined1 *puVar2;
  
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  in_EAX[3] = param_1[3];
  in_EAX[4] = param_1[4];
  in_EAX[5] = param_1[5];
  in_EAX[6] = param_1[6];
  in_EAX[7] = param_1[7];
  in_EAX[8] = param_1[8];
  in_EAX[9] = param_1[9];
  in_EAX[10] = param_1[10];
  in_EAX[0xb] = param_1[0xb];
  in_EAX[0xc] = param_1[0xc];
  in_EAX[0xd] = param_1[0xd];
  in_EAX[0xe] = param_1[0xe];
  in_EAX[0xf] = param_1[0xf];
  *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  puVar2 = in_EAX + 0x14;
  iVar1 = 0x10;
  do {
    *puVar2 = puVar2[(int)param_1 - (int)in_EAX];
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_EAX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  return;
}


// ==== 0x42bb60 FUN_0042bb60

void FUN_0042bb60(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00688b57;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  Player__SetHudFlags(0,0);
  if (*(undefined4 **)(param_1 + 0x95c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x95c))(1);
  }
  piVar3 = *(int **)(param_1 + 0x90);
  if (piVar3 != (int *)0x0) {
    if (*piVar3 != 0) {
      FUN_00565ce0();
    }
    _free(piVar3);
  }
  if (*(void **)(param_1 + 0x55c) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x55c));
  }
  if (*(void **)(param_1 + 0x5c0) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x5c0));
  }
  if (*(undefined4 **)(param_1 + 0x5c4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x5c4))(1);
  }
  pvVar1 = *(void **)(param_1 + 0x298);
  *(undefined4 *)(param_1 + 0x5c4) = 0;
  *(undefined4 *)(param_1 + 0x5c8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5cc) = 0xffffffff;
  if (pvVar1 != (void *)0x0) {
    FUN_0042b040(pvVar1);
    _free(pvVar1);
    *(undefined4 *)(param_1 + 0x298) = 0;
  }
  pvVar1 = *(void **)(param_1 + 0x2a8);
  if (pvVar1 != (void *)0x0) {
    FUN_0058d0d0(pvVar1);
    _free(pvVar1);
  }
  if (*(undefined4 **)(param_1 + 0xa8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xa8))(1);
  }
  DAT_007361c4 = DAT_007361c4 + -1;
  *(undefined4 *)(param_1 + 0x544) = 0;
  *(undefined4 *)(param_1 + 0x548) = 0;
  (&DAT_007361bc)[DAT_007361c4] = 0;
  (&DAT_007361b4)[*(int *)(param_1 + 0x10)] = 0;
  DAT_007183b4 = 1;
  _free(*(void **)(param_1 + 0x1e0));
  _free(*(void **)(param_1 + 0x1e4));
  pvVar1 = *(void **)(param_1 + 0x130);
  if (pvVar1 != (void *)0x0) {
    FUN_00490730();
    pvVar2 = *(void **)((int)pvVar1 + 0xc);
    if (pvVar2 != (void *)0x0) {
      eh_vector_destructor_iterator(pvVar2,0xc0,*(int *)((int)pvVar2 + -0x10),FUN_00401db0);
      _free((int *)((int)pvVar2 + -0x10));
    }
    _free(pvVar1);
  }
  _free(*(void **)(param_1 + 0x108));
  local_8._0_1_ = 2;
  FUN_0043dd10();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004368e0();
  _free(*(void **)(param_1 + 0x8ec));
  _free(*(void **)(param_1 + 0x8f0));
  iVar4 = *(int *)(param_1 + 0x870);
  if (0 < iVar4) {
    piVar3 = (int *)(param_1 + 0x5f0);
    do {
      *(char *)(*piVar3 + 8) = *(char *)(*piVar3 + 8) + -1;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x42bd60 FUN_0042bd60

void FUN_0042bd60(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  FUN_00571ea0(0,"Player");
  FUN_00571c20(param_2,param_1 + 0x58,4,4,1);
  FUN_00571c20(param_2,param_1 + 0x5c,2,4,1);
  FUN_00571c20(param_2,param_1 + 0x60,1,4,0);
  FUN_00571c20(param_2,param_1 + 0x68,8,8,0);
  FUN_00571c20(param_2,param_1 + 0x70,0x20,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x274,1,4,0);
  FUN_005840c0(*(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x10));
  FUN_00571c20(param_2,param_1 + 0xac,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xb0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xb4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xb8,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xbc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xc0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1c0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x29c,4,4,1);
  FUN_00571c20(param_2,param_1 + 0x2a0,4,4,1);
  FUN_00571c20(param_2,param_1,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2a4,4,4,1);
  FUN_00571c20(param_2,param_1 + 0x4ac,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4ad,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4ae,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4af,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x98,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x1c4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1cc,8,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1d4,8,0xffffffff,0);
  FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x1e0),0x90,0xffffffff,0);
  FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x1e4),0x90,0xffffffff,0);
  FUN_0041ff80(DAT_007361f8);
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    FUN_00571c20(param_2,param_1 + 0xc4,2,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0xc6,1,1,0);
    FUN_00571c20(param_2,param_1 + 0xcc,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0xd0,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0xd4,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 199,1,1,0);
    FUN_00571c20(param_2,param_1 + 0xdc,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0xe0,4,0xffffffff,0);
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    iVar1 = *(int *)(param_1 + 300);
    FUN_00571c20(param_2,(int *)(param_1 + 300),4,4,0);
    iVar2 = *(int *)(param_1 + 300);
    if (iVar1 != iVar2) {
      FUN_0042fee0(iVar2);
    }
    FUN_00571c20(param_2,param_1 + 0x128,4,4,1);
    FUN_00571c20(param_2,param_1 + 0x104,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x10c,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x110,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x118,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x11c,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x120,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x124,1,1,0);
    FUN_00571c20(param_2,param_1 + 0x180,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x184,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x188,4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x18c,4,4,1);
    FUN_00571d90();
    FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x108),4,0xffffffff,0);
    FUN_00571c20(param_2,param_1 + 0x114,4,0xffffffff,0);
  }
  if (*(char *)(param_2 + 0x3d) != '\0') {
    Player__SetInputMode(0);
  }
  FUN_00571c20(param_2,param_1 + 0xa4,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar3 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x42c1f0 FUN_0042c1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c1f0(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int in_EAX;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int local_4;
  
  iVar10 = 0;
  if (*(int *)(in_EAX + 0x58) == 0) {
    *(undefined4 *)(in_EAX + 0x58) = DAT_006f08a0;
    if (((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) && (*(int *)(in_EAX + 0x130) != 0)) {
      *(undefined4 *)(in_EAX + 0x104) = 0;
      fVar1 = *(float *)(in_EAX + 0x118);
      *(undefined4 *)(in_EAX + 0x118) = 0;
      *(float *)(in_EAX + 0x11c) = *(float *)(in_EAX + 0x11c) + fVar1;
    }
    iVar7 = DAT_0073619c;
    piVar2 = *(int **)(*(int *)(in_EAX + 4) + 0x1c);
    if ((int)*(char *)((int)piVar2 + 9) == *(int *)(DAT_0073619c + 0x530)) {
      if (DAT_0078a368 == 0) {
        iVar11 = *(int *)(DAT_0073619c + 0x24);
        local_4 = 0;
        if (0 < iVar11) {
          iVar3 = *piVar2;
          puVar9 = (undefined4 *)(DAT_0073619c + 0x520);
          do {
            iVar4 = *(int *)*puVar9;
            fVar1 = *(float *)(iVar3 + 0x60) - *(float *)(iVar4 + 0x60);
            fVar6 = *(float *)(iVar3 + 100) - *(float *)(iVar4 + 100);
            fVar5 = *(float *)(iVar3 + 0x68) - *(float *)(iVar4 + 0x68);
            if (SQRT(fVar1 * fVar1 + fVar6 * fVar6 + fVar5 * fVar5) < 30.0) {
              iVar10 = iVar10 + 1;
            }
            puVar9 = puVar9 + 1;
            iVar11 = iVar11 + -1;
            local_4 = iVar10;
          } while (iVar11 != 0);
        }
        FUN_00572970(((float)local_4 - _K_ONE) * 7.5 + 10.0,"CrossFinishLine");
      }
      FUN_00435b30(iVar7);
    }
    uVar8 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x5c) = uVar8;
    if (*(int *)(in_EAX + 4) != 0) {
      FUN_00465530();
    }
  }
  return;
}


// ==== 0x42c340 FUN_0042c340

void FUN_0042c340(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    if (*(undefined4 **)(unaff_ESI + 0x288) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_ESI + 0x288))(1);
      *(undefined4 *)(unaff_ESI + 0x288) = 0;
    }
    puVar1 = (undefined4 *)(&DAT_007404a4)[*(int *)(unaff_ESI + 0x1c) * 0x18];
    if ((((puVar1 != &DAT_007404a4 + *(int *)(unaff_ESI + 0x1c) * 0x18) &&
         (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x4)) &&
       (((puVar1 != &DAT_007404a4 + *(int *)(unaff_ESI + 0x1c) * 0x18 &&
         (puVar1 != (undefined4 *)0x0)) && (puVar1 + -1 != (undefined4 *)0x0)))) {
      (**(code **)puVar1[-1])(1);
    }
    if (param_1 != 0) {
      pvVar2 = _malloc(0x30);
      if (pvVar2 != (void *)0x0) {
        uVar3 = RearViewMirrorCameraMover__ctor();
        *(undefined4 *)(unaff_ESI + 0x288) = uVar3;
        return;
      }
      *(undefined4 *)(unaff_ESI + 0x288) = 0;
    }
  }
  return;
}


// ==== 0x42c3e0 FUN_0042c3e0

void FUN_0042c3e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686db3;
  local_c = ExceptionList;
  if (*(int *)(unaff_ESI + 0x290) == 0) {
    ExceptionList = &local_c;
    Player__ChangeCameraMover(unaff_ESI,0,0);
    pvVar1 = _malloc(0x24);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = CountdownCameraCoordinator__ctor(pvVar1,*(undefined4 *)(unaff_ESI + 0x18),unaff_ESI);
    }
    *(undefined4 *)(unaff_ESI + 0x290) = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x42c450 FUN_0042c450

void FUN_0042c450(void)

{
  int *piVar1;
  int unaff_ESI;
  
  if (*(undefined4 **)(unaff_ESI + 0x27c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x27c))(1);
  }
  piVar1 = *(int **)(unaff_ESI + 0x280);
  *(int **)(unaff_ESI + 0x27c) = piVar1;
  *(undefined4 *)(unaff_ESI + 0x280) = *(undefined4 *)(unaff_ESI + 0x284);
  *(undefined4 *)(unaff_ESI + 0x284) = 0;
  if ((piVar1 != (int *)0x0) && ((piVar1[3] == 1 || (piVar1[3] == 0x11)))) {
    (**(code **)(*piVar1 + 0x14))(*(undefined1 *)(unaff_ESI + 0x4ad));
  }
                    /* WARNING: Could not recover jumptable at 0x0042c4a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x27c) + 0x38))();
  return;
}


// ==== 0x42c4b0 JumpCamBuildSpline

/* [canon] camera I (C) docs/re/camera.md */

undefined4 __fastcall JumpCamBuildSpline(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int unaff_ESI;
  
  if (*(undefined4 **)(unaff_ESI + 0x5c4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x5c4))(1,param_1);
  }
  *(undefined4 *)(unaff_ESI + 0x5c4) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c8) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5cc) = 0xffffffff;
  if (DAT_0078a2f0 == 0x3e9) {
    fVar1 = *(float *)(*(int *)(unaff_ESI + 4) + 0x60) - 1415.0;
    fVar2 = *(float *)(*(int *)(unaff_ESI + 4) + 100) - -920.0;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
  }
  else {
    if (DAT_0078a2f0 != 0x3ea) goto LAB_0042c524;
    fVar1 = *(float *)(*(int *)(unaff_ESI + 4) + 0x60) - 1290.9;
    fVar2 = *(float *)(*(int *)(unaff_ESI + 4) + 100) - -905.0;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
  }
  if (SQRT(fVar1) < 40.0) {
    return 0;
  }
LAB_0042c524:
  iVar3 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + 0x2c) + 0x20))();
  if ((iVar3 != 0) && (iVar4 = FUN_005a6150(iVar3,*(int *)(unaff_ESI + 4) + 0x60,1), iVar4 != -1)) {
    piVar7 = (int *)(iVar3 + 8 + iVar4 * 4);
    for (iVar6 = iVar4; iVar6 < *(int *)(iVar3 + 4); iVar6 = iVar6 + 1) {
      if (75.0 <= *(float *)(*piVar7 + 0x58) - *(float *)(*(int *)(iVar3 + 8 + iVar4 * 4) + 0x58)) {
        if ((iVar6 != -1) && (4 < iVar6 + (1 - iVar4))) {
          *(int *)(unaff_ESI + 0x5c8) = iVar4;
          *(int *)(unaff_ESI + 0x5cc) = iVar6;
          uVar5 = FUN_005a51f0(iVar3);
          *(undefined4 *)(unaff_ESI + 0x5c4) = uVar5;
          return 1;
        }
        break;
      }
      piVar7 = piVar7 + 1;
    }
  }
  if (*(undefined4 **)(unaff_ESI + 0x5c4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x5c4))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x5c8) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5cc) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5c4) = 0;
  return 0;
}


// ==== 0x42c640 FUN_0042c640

void FUN_0042c640(void)

{
  int unaff_ESI;
  
  if (*(undefined4 **)(unaff_ESI + 0x5c4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x5c4))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x5c4) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c8) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5cc) = 0xffffffff;
  return;
}


// ==== 0x42c670 Player::DefaultDriveCamera

/* [canon] camera V (G+C) docs/re/camera.md */

void Player__DefaultDriveCamera(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(DAT_007361f0 + 0x3c);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) || (*(int *)(iVar1 + 0x1c) == 0)) &&
     ((*(int *)(DAT_007361f0 + 0x40) == 0 || (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0)))
     ) {
    Player__ChangeCameraMover(unaff_ESI,(-(DAT_00700aa4 != 0) & 0x10U) + 1,0);
    if ((param_1 != 0) && (*(int **)(unaff_ESI + 0x27c) != (int *)0x0)) {
      (**(code **)(**(int **)(unaff_ESI + 0x27c) + 0x34))();
    }
  }
  return;
}


// ==== 0x42c6d0 Player::ChangeCameraMover

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

void Player__ChangeCameraMover(int param_1,int param_2,char param_3)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  float *pfVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  bool bVar12;
  float10 fVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uStack_5d4;
  float fStack_5cc;
  float fStack_5c8;
  float fStack_5c4;
  undefined4 uStack_5c0;
  float fStack_5bc;
  float fStack_5b8;
  int iStack_5b0;
  float fStack_5ac;
  float fStack_5a8;
  float fStack_5a4;
  undefined4 uStack_5a0;
  float fStack_59c;
  float fStack_598;
  float fStack_594;
  undefined4 uStack_590;
  float fStack_58c;
  float fStack_588;
  float fStack_584;
  undefined4 uStack_580;
  float fStack_57c;
  float fStack_578;
  float fStack_574;
  undefined4 uStack_570;
  float fStack_56c;
  float fStack_568;
  float fStack_554;
  undefined4 uStack_52c;
  undefined1 auStack_510 [32];
  int aiStack_4f0 [160];
  int iStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 auStack_250 [10];
  undefined4 uStack_228;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_00686d8e;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  if (*(undefined4 **)(param_1 + 0x28c) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_1c;
    (**(code **)**(undefined4 **)(param_1 + 0x28c))(1);
    *(undefined4 *)(param_1 + 0x28c) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x290) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x290))(1);
    *(undefined4 *)(param_1 + 0x290) = 0;
  }
  if (*(int *)(param_1 + 0x294) != 0) {
    *(undefined4 *)(param_1 + 0x294) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x27c);
  if (((piVar2 != (int *)0x0) && (piVar2[3] == param_2)) && (piVar2[3] != 0x14)) {
    ExceptionList = pvStack_1c;
    return;
  }
  iVar11 = *DAT_007361f0;
  if ((((iVar11 == 5) || (iVar11 == 6)) || (iVar11 == 10)) && (0x11 < param_2)) {
    if (param_2 < 0x14) {
      ExceptionList = pvStack_1c;
      return;
    }
    if (param_2 == 0x15) {
      ExceptionList = pvStack_1c;
      return;
    }
  }
  iVar11 = *(int *)(param_1 + 4);
  if (iVar11 == 0) {
    iVar11 = *DAT_007361f8;
  }
  fStack_5a4 = (float)iVar11;
  if (piVar2 != (int *)0x0) {
    if (param_3 == '\0') {
      (**(code **)*piVar2)(1);
    }
    else {
      *(undefined4 *)(param_1 + 0x284) = *(undefined4 *)(param_1 + 0x280);
      *(int **)(param_1 + 0x280) = piVar2;
      (**(code **)(*piVar2 + 0x3c))();
    }
    *(undefined4 *)(param_1 + 0x27c) = 0;
  }
  switch(param_2) {
  case 0:
    goto switchD_0042c7d7_caseD_0;
  case 1:
    pvVar8 = _malloc(0x3a0);
    if (pvVar8 == (void *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = DriveCameraMover__ctor
                        (iVar11,(int)*(char *)(param_1 + 0x24),0x43967333,
                         (int)*(char *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x4ad),1);
    }
    *(undefined4 *)(param_1 + 0x27c) = uVar9;
    uVar4 = Player__CyclePOV();
    *(undefined1 *)(param_1 + 0x24) = uVar4;
    goto switchD_0042c7d7_caseD_0;
  case 2:
    uStack_580 = *(undefined4 *)(iVar11 + 0x60);
    fStack_5c4 = *(float *)(iVar11 + 0x68);
    fStack_57c = *(float *)(iVar11 + 100);
    uStack_590 = 0;
    fStack_58c = 0.0;
    fStack_588 = 1.0;
    fStack_578 = fStack_5c4 + 4.0;
    pvVar8 = _malloc(0x4c);
    uStack_14 = 0;
    if (pvVar8 == (void *)0x0) {
LAB_0042d2c5:
      uVar9 = 0;
    }
    else {
      uVar9 = DebugWorldCameraMover__ctor(pvVar8,*(undefined4 *)(param_1 + 0x18),&uStack_580,1);
    }
    break;
  case 3:
    pvVar8 = _malloc(0x2c);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = NullCameraMover__ctor(1);
    break;
  default:
    pvVar8 = _malloc(0xd0);
    uStack_14 = 4;
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = OrbitCarCameraMover__ctor(pvVar8,*(undefined4 *)(param_1 + 0x18),iVar11,1);
    break;
  case 0xd:
    pvVar8 = _malloc(0x368);
    uStack_14 = 1;
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = ZoneFreezeCameraMover__ctor
                      (pvVar8,*(undefined4 *)(param_1 + 0x18),iVar11,
                       *(undefined4 *)(param_1 + 0x280));
    break;
  case 0xe:
    pvVar8 = _malloc(0x450);
    uStack_14 = 2;
    if (pvVar8 == (void *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = ZonePreviewCameraMover__ctor
                        (pvVar8,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x90),
                         iVar11 + 0x60);
    }
    piVar2 = *(int **)(param_1 + 0x90);
    uStack_14 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x27c) = uVar9;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_00565ce0();
      }
      _free(piVar2);
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
    goto switchD_0042c7d7_caseD_0;
  case 0xf:
    fStack_5c4 = *(float *)(param_1 + 0x5cc);
    if (4 < (int)fStack_5c4 - *(int *)(param_1 + 0x5c8)) {
      fStack_5c4 = (float)((int)fStack_5c4 + -2);
    }
    **(undefined4 **)(param_1 + 0x55c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 4) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 8) = 0;
    iVar11 = *(int *)(*(int *)(param_1 + 0x5c4) + 8 + (int)fStack_5c4 * 4);
    uVar15 = 0;
    uVar6 = (**(code **)(**(int **)((int)fStack_5a4 + 0x2c) + 0x1c))(0);
    uVar9 = *(undefined4 *)(iVar11 + 0x58);
    uVar6 = ((int)uVar6 < 1) - 1 & uVar6;
    uVar14 = uVar6;
    fVar13 = (float10)FUN_005a7450(uVar6);
    FUN_005a7270(&fStack_5c4,uVar9,(float)fVar13,uVar14);
    FUN_004440c0(&fStack_5c4);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 4) + 0x810);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x28) =
         *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0xc);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x10) = uStack_52c;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x2c) =
         *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x10);
    iVar11 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x14) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x18) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x1c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x20) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x24) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x30) = 0x3f000000;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x34) = 0x461c4000;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x38) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x3c) = *(undefined4 *)(param_1 + 0x5c0);
    do {
      pfVar7 = (float *)(*(int *)(param_1 + 0x5c0) + iVar11);
      iVar11 = iVar11 + 0x10;
      *pfVar7 = DAT_00700b14;
      pfVar7[1] = 0.0;
      pfVar7[2] = 0.0;
    } while (iVar11 < 0x200);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x50) = 2;
    *(int *)(*(int *)(param_1 + 0x55c) + 0x54) = param_1 + 0x560;
    *(int *)(*(int *)(param_1 + 0x55c) + 0x58) = param_1 + 0x590;
    puVar10 = (undefined4 *)(param_1 + 0x598);
    iVar11 = 3;
    do {
      puVar10[-2] = 0;
      puVar10[-1] = 0;
      *puVar10 = 0;
      puVar10 = puVar10 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x5c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x60) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 100) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x68) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x6c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x70) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x74) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x78) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x7c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x80) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x84) = 0x3e4ccccd;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x90) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x94) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x98) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x9c) = 0;
    uStack_5c0 = *(undefined4 *)((int)fStack_5a8 + 100);
    fStack_5c4 = *(float *)((int)fStack_5a8 + 0x60);
    fStack_5bc = *(float *)((int)fStack_5a8 + 0x68);
    piVar2 = *(int **)(*(int *)(param_1 + 0x5c4) + 8 + (int)fStack_5c8 * 4);
    fVar1 = (float)piVar2[0x16];
    uVar14 = uVar6;
    fVar13 = (float10)(**(code **)(*piVar2 + 0xc))(uVar6,uVar6);
    FUN_005a7270(&fStack_598,(int)fStack_5a8 + 0x60,(float)(fVar13 - (float10)_JumpCam_EdgeOffset),
                 uVar14);
    uVar14 = uVar6;
    fVar13 = (float10)(**(code **)(*piVar2 + 8))(uVar6,uVar6);
    FUN_005a7270(&fStack_57c,uStack_5d4,(float)(fVar13 + (float10)_JumpCam_EdgeOffset),uVar14);
    fVar3 = fStack_598;
    fStack_5ac = fStack_59c;
    fStack_5a8 = fStack_598;
    fStack_5a4 = fStack_594;
    fStack_584 = fStack_574;
    fStack_588 = fStack_578;
    piVar2 = *(int **)(*(int *)(param_1 + 0x5c4) + 0x10 + *(int *)(param_1 + 0x5c8) * 4);
    fStack_56c = fStack_57c - fVar1;
    fStack_554 = fStack_574 - fStack_5c4;
    bVar12 = (fStack_59c - fVar1) * *(float *)(iStack_5b0 + 0x70) +
             (fStack_598 - fStack_5c8) * *(float *)(iStack_5b0 + 0x74) +
             (fStack_594 - fStack_5c4) * *(float *)(iStack_5b0 + 0x78) <=
             fStack_56c * *(float *)(iStack_5b0 + 0x70) +
             (fStack_578 - fStack_5c8) * *(float *)(iStack_5b0 + 0x74) +
             fStack_554 * *(float *)(iStack_5b0 + 0x78);
    if (bVar12) {
      fStack_5cc = fStack_59c;
      fStack_5c4 = fStack_594;
      fVar13 = (float10)(**(code **)(*piVar2 + 8))(uVar6,uVar6);
      FUN_005a7270(&uStack_5a0,fVar3,(float)(fVar13 + (float10)_JumpCam_EdgeOffset),uVar15);
      *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x88) = 0xbecccccd;
    }
    else {
      fStack_5cc = fStack_57c;
      fStack_5c4 = fStack_574;
      fVar13 = (float10)(**(code **)(*piVar2 + 0xc))();
      FUN_005a7270(&uStack_5a0,fStack_578,(float)(fVar13 - (float10)_JumpCam_EdgeOffset),uVar15);
      *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x88) = 0x3ecccccd;
    }
    cVar5 = FUN_00457300(fStack_5cc,&uStack_5c0,(int)fStack_5c4 + -1);
    if (cVar5 == '\0') {
      if (bVar12) {
        fStack_5bc = fStack_56c;
        uStack_5c0 = uStack_570;
        fStack_5b8 = fStack_568;
        iVar11 = piVar2[0x16];
        fVar13 = (float10)(**(code **)(*piVar2 + 0xc))();
        FUN_005a7270(&uStack_5a0,iVar11,(float)(fVar13 - (float10)_JumpCam_EdgeOffset),uVar6);
        *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x88) = 0x3ecccccd;
      }
      else {
        fStack_5bc = fStack_58c;
        uStack_5c0 = uStack_590;
        fStack_5b8 = fStack_588;
        iVar11 = piVar2[0x16];
        fVar13 = (float10)(**(code **)(*piVar2 + 8))(uVar6,uVar6);
        FUN_005a7270(&uStack_5a0,iVar11,(float)(fVar13 + (float10)_JumpCam_EdgeOffset),uVar6);
        *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x88) = 0xbecccccd;
      }
    }
    fStack_5b8 = fStack_5b8 + _K_ONE;
    iStack_270 = 0;
    uStack_26c = 0;
    uStack_268 = 0;
    uStack_264 = 0;
    fStack_598 = fStack_598 + _K_ONE;
    uStack_25c = 0;
    uStack_258 = 0;
    uStack_254 = 0;
    FUN_00440740();
    fVar13 = (float10)GroundQuery__FindSurfaceBelow(auStack_510,&uStack_5c0,0,0,0);
    if ((float10)fStack_5b8 < fVar13) {
      fStack_5b8 = (float)(fVar13 + (float10)_K_ONE);
    }
    *(float *)(param_1 + 0x568) = fStack_5b8;
    *(float *)(param_1 + 0x564) = fStack_5bc;
    *(undefined4 *)(param_1 + 0x560) = uStack_5c0;
    *(float *)(param_1 + 0x578) = fStack_5b8;
    *(float *)(param_1 + 0x574) = fStack_5bc;
    *(undefined4 *)(param_1 + 0x570) = uStack_5c0;
    *(float *)(param_1 + 0x588) = fStack_598;
    *(float *)(param_1 + 0x584) = fStack_59c;
    puVar10 = auStack_250;
    for (iVar11 = 0x8c; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined4 *)(param_1 + 0x580) = uStack_5a0;
    uStack_228 = 2;
    pvVar8 = _malloc(0x470);
    if (pvVar8 == (void *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = TrackCarCameraMover__ctor
                        (pvVar8,fStack_5a4,*(undefined4 *)(param_1 + 0x55c),auStack_250,0);
    }
    *(undefined4 *)(param_1 + 0x27c) = uVar9;
    iVar11 = 0;
    if (0 < iStack_270) {
      do {
        *(char *)(aiStack_4f0[iVar11] + 8) = *(char *)(aiStack_4f0[iVar11] + 8) + -1;
        iVar11 = iVar11 + 1;
      } while (iVar11 < iStack_270);
    }
    goto switchD_0042c7d7_caseD_0;
  case 0x10:
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 4) + 0x810);
    *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0x28) =
         *(undefined4 *)(*(int *)(param_1 + 0x55c) + 0xc);
    fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x68);
    if (*(float *)(param_1 + 0x588) < fVar1) {
      *(float *)(param_1 + 0x588) = fVar1;
    }
    FUN_004406d0();
    puVar10 = (undefined4 *)(param_1 + 0x580);
    fVar13 = (float10)GroundQuery__FindSurfaceBelow(auStack_510,puVar10,0,0,0);
    if ((float10)*(float *)(param_1 + 0x588) < fVar13) {
      *(float *)(param_1 + 0x588) = (float)(fVar13 + (float10)_K_ONE);
    }
    *(undefined4 *)(param_1 + 0x560) = *puVar10;
    iVar11 = 0;
    *(undefined4 *)(param_1 + 0x564) = *(undefined4 *)(param_1 + 0x584);
    *(undefined4 *)(param_1 + 0x568) = *(undefined4 *)(param_1 + 0x588);
    *(undefined4 *)(param_1 + 0x570) = *puVar10;
    *(undefined4 *)(param_1 + 0x574) = *(undefined4 *)(param_1 + 0x584);
    *(undefined4 *)(param_1 + 0x578) = *(undefined4 *)(param_1 + 0x588);
    *(float *)(*(int *)(param_1 + 0x55c) + 0x88) = -*(float *)(*(int *)(param_1 + 0x55c) + 0x88);
    fVar1 = 0.0;
    do {
      pfVar7 = (float *)(*(int *)(param_1 + 0x5c0) + iVar11);
      iVar11 = iVar11 + 0x10;
      fVar3 = DAT_00700b14 - _DAT_00700b18 * fVar1;
      pfVar7[1] = 0.0;
      pfVar7[2] = 0.0;
      *pfVar7 = fVar3;
      fVar1 = fVar1 + _K_ONE;
    } while (iVar11 < 0x200);
    puVar10 = auStack_250;
    for (iVar11 = 0x8c; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    uStack_228 = 2;
    pvVar8 = _malloc(0x470);
    if (pvVar8 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0x27c) = 0;
      FUN_00440710();
    }
    else {
      uVar9 = TrackCarCameraMover__ctor
                        (pvVar8,fStack_5a4,*(undefined4 *)(param_1 + 0x55c),auStack_250,1);
      *(undefined4 *)(param_1 + 0x27c) = uVar9;
      FUN_00440710();
    }
    goto switchD_0042c7d7_caseD_0;
  case 0x11:
    pvVar8 = _malloc(0x54);
    uStack_14 = 3;
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    fStack_5c4 = (float)CONCAT31(fStack_5c4._1_3_,*(undefined1 *)(param_1 + 0x4ad));
    uVar9 = CubicCameraMover__ctor
                      (pvVar8,*(undefined4 *)(param_1 + 0x18),iVar11,(int)*(char *)(param_1 + 0x24),
                       *(char *)(param_1 + 0x28) != '\0',fStack_5c4,1);
    break;
  case 0x12:
    pvVar8 = _malloc(0x2c);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = CameraMover_Type12__ctor();
    break;
  case 0x13:
    pvVar8 = _malloc(0x38);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = DragRaceCameraMover__ctor();
    break;
  case 0x14:
    pvVar8 = _malloc(0x58);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = DragRaceLeaderCameraMover__ctor(*(undefined4 *)(param_1 + 4));
    break;
  case 0x15:
    pvVar8 = _malloc(0xa0);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    if (*(int *)(DAT_0073619c + 0x24) < 1) {
      puVar10 = (undefined4 *)0x0;
    }
    else {
      puVar10 = *(undefined4 **)(DAT_0073619c + 0x520);
    }
    uVar9 = DragRaceAheadCameraMover__ctor(pvVar8,*puVar10,(int)*(char *)(param_1 + 0x24));
    break;
  case 0x16:
    pvVar8 = _malloc(0x310);
    if (pvVar8 == (void *)0x0) goto LAB_0042d2c5;
    uVar9 = AnimationControllerCameraMover__ctor(pvVar8,&DAT_007797f8);
  }
  *(undefined4 *)(param_1 + 0x27c) = uVar9;
switchD_0042c7d7_caseD_0:
  if (*(int *)(param_1 + 0x27c) != 0) {
    *(int *)(*(int *)(param_1 + 0x27c) + 0x20) = param_1;
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== 0x42d350 FUN_0042d350

void FUN_0042d350(void)

{
  int iVar1;
  int in_EAX;
  
  if (*(int **)(in_EAX + 0x27c) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x27c) + 0x38))();
  }
  if (*(int **)(in_EAX + 0x288) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x288) + 0x38))();
  }
  iVar1 = *(int *)(in_EAX + 0x28c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (*(int **)(iVar1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xc) + 0x38))();
    }
  }
  iVar1 = *(int *)(in_EAX + 0x290);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (*(int **)(iVar1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xc) + 0x38))();
    }
  }
  if (*(int *)(in_EAX + 0x298) != 0) {
    FUN_004906d0(*(int *)(in_EAX + 0x298) + 0x3c);
  }
  return;
}


// ==== 0x42d3e0 FUN_0042d3e0

void FUN_0042d3e0(void)

{
  int iVar1;
  int in_EAX;
  
  if (*(int **)(in_EAX + 0x27c) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x27c) + 0x3c))();
  }
  if (*(int **)(in_EAX + 0x288) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x288) + 0x3c))();
  }
  iVar1 = *(int *)(in_EAX + 0x28c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) == 0)) {
    *(undefined4 *)(iVar1 + 0x10) = 1;
    if (*(int **)(iVar1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xc) + 0x3c))();
    }
  }
  iVar1 = *(int *)(in_EAX + 0x290);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) == 0)) {
    *(undefined4 *)(iVar1 + 0x10) = 1;
    if (*(int **)(iVar1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0xc) + 0x3c))();
    }
  }
  if (*(int *)(in_EAX + 0x298) != 0) {
    FUN_00490730();
    return;
  }
  return;
}


// ==== 0x42d470 FUN_0042d470

void FUN_0042d470(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  switch(*DAT_007361f0) {
  case 0:
    iVar1 = 0;
    break;
  case 2:
  case 3:
    iVar1 = 7;
    break;
  case 4:
  case 5:
  case 6:
  case 8:
  case 10:
    if (*(char *)(in_EAX + 0x4af) == '\0') {
      iVar1 = (uint)(*(char *)(in_EAX + 0x4ae) != '\0') * 2 + 2;
    }
    else {
      iVar1 = 3;
    }
    break;
  case 7:
    iVar1 = 1;
    break;
  case 9:
    iVar1 = 6;
  }
  if (*(int *)(in_EAX + 0x58) != 0) {
    iVar1 = 8;
  }
  if (SpecialCamTable3[*(int *)(in_EAX + 0x60)] != (code)0x0) {
    iVar1 = 5;
  }
  if (*(int *)(in_EAX + 0x278) != iVar1) {
    Player__SetInputMode(iVar1);
  }
  return;
}


// ==== 0x42d520 Player::SetInputMode

/* [canon] camera I (C) docs/re/camera.md */

void Player__SetInputMode(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  
  switch(*(undefined4 *)(in_EAX + 0x278)) {
  case 2:
  case 3:
  case 4:
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xab);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0x75);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xaa);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0x76);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xa3);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xa0);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xa1);
    }
    iVar3 = FUN_00574120();
    if (iVar3 != 0) {
      FUN_005740b0(0xa2);
    }
    FUN_005740b0(0x9a);
    FUN_005740b0(0x99);
    FUN_005740b0(0x9b);
    FUN_005740b0(0x9c);
    FUN_005740b0(0x77);
    FUN_005740b0(0x78);
    FUN_005740b0(0x79);
    FUN_005740b0(0x7a);
    if (*(int *)(in_EAX + 0x278) == 3) {
      FUN_0042e1e0();
    }
    else if (*(int *)(in_EAX + 0x278) == 4) {
      FUN_0042e400();
    }
    else if ((*(int *)(in_EAX + 4) != 0) &&
            (piVar1 = *(int **)(*(int *)(in_EAX + 4) + 0x30), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x18))();
    }
    break;
  case 5:
    FUN_005740b0(0xab);
    break;
  case 7:
  case 8:
    FUN_005740b0(0xac);
    FUN_005740b0(0xab);
  }
  puVar2 = DAT_0073b3ec;
  if (*(int *)(in_EAX + 0x10) == 0) {
    puVar4 = (undefined4 *)NullUpdate_ret();
    for (; puVar2 != puVar4; puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[2] == 0x44) {
        FUN_005740b0(0x44);
        break;
      }
    }
  }
  *(undefined4 *)(in_EAX + 0x278) = param_1;
  switch(param_1) {
  case 2:
  case 3:
  case 4:
    if (*DAT_007361f0 == 4) {
      InputEvents__AddSource(0xab,FUN_0042abb0);
      InputEvents__AddSource(0x75,FUN_0042abb0);
      InputEvents__AddSource(0xaa,FUN_0042abb0);
    }
    InputEvents__AddSource(0x76,FUN_0042abb0);
    InputEvents__AddSource(0x9a,FUN_0042abb0);
    InputEvents__AddSource(0x99,FUN_0042abb0);
    InputEvents__AddSource(0x9b,FUN_0042abb0);
    InputEvents__AddSource(0x9c,FUN_0042abb0);
    InputEvents__AddSource(0x77,FUN_0042abb0);
    InputEvents__AddSource(0x78,FUN_0042abb0);
    InputEvents__AddSource(0x79,FUN_0042abb0);
    InputEvents__AddSource(0x7a,FUN_0042abb0);
    if (*(int *)(in_EAX + 0x278) == 4) {
      InputEvents__AddSource(0xa0,FUN_0042abb0);
      InputEvents__AddSource(0xa1,FUN_0042abb0);
      InputEvents__AddSource(0xa2,0,0);
      FUN_0042e230(in_EAX);
      Player__ChangeCameraMover(in_EAX,0x12,0);
    }
    else {
      if (*(int *)(in_EAX + 0x278) == 3) {
        FUN_0042e190();
      }
      else {
        Player__DefaultDriveCamera(0);
      }
      if ((*(int *)(in_EAX + 4) != 0) &&
         (piVar1 = *(int **)(*(int *)(in_EAX + 4) + 0x30), piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(in_EAX + 8));
        (**(code **)(*piVar1 + 0x14))();
      }
    }
    break;
  case 5:
    InputEvents__AddSource(0xab,FUN_0042abb0);
    break;
  case 7:
    InputEvents__AddSource(0xac,FUN_0042d9a0);
    pcVar5 = FUN_0042d9a0;
    goto LAB_0042d90e;
  case 8:
    InputEvents__AddSource(0xac,FUN_0042d9d0);
    pcVar5 = FUN_0042d9d0;
LAB_0042d90e:
    InputEvents__AddSource(0xab,pcVar5);
  }
  iVar3 = *(int *)(in_EAX + 0x278);
  if (((1 < iVar3) && (((iVar3 < 5 || (iVar3 == 6)) && (DAT_007361c4 < 2)))) &&
     (*(int *)(in_EAX + 0x10) == 0)) {
    InputEvents__AddSource(0x44,FUN_0042abd0);
  }
  return;
}


// ==== 0x42d9a0 FUN_0042d9a0

void FUN_0042d9a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if ((param_2 == 0xab) && (*(int *)(param_4 + 0x58) == 0)) {
    FUN_00421c00(DAT_007361f0,5,param_1);
  }
  return;
}


// ==== 0x42d9d0 FUN_0042d9d0

void FUN_0042d9d0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if ((((param_2 == 0xab) && (iVar2 = *DAT_007361f0, iVar2 != 5)) && (iVar2 != 6)) && (iVar2 != 10))
  {
    iVar2 = FUN_00435b30(DAT_0073619c);
    if ((iVar2 == 0) && (cVar1 = FUN_0043a2e0(), cVar1 == '\0')) {
      return;
    }
    FUN_00421c00(DAT_007361f0,5,param_1);
  }
  return;
}


// ==== 0x42da30 FUN_0042da30

void FUN_0042da30(void)

{
  Player__EndSpecialCamera(1);
  return;
}


// ==== 0x42da40 Player::StartSpecialCamera

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 __thiscall
Player__StartSpecialCamera(int param_1,int param_2,char param_3,undefined4 param_4,char param_5)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  if ((((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) || (DAT_0078a346 != '\0')) ||
     ((DAT_007361a0 != 0 || (*DAT_007361f0 == 9)))) {
    return 0;
  }
  if (param_3 == '\0') {
    iVar2 = SpecialCamCooldown();
    if ((iVar2 != 0) &&
       ((float)(DAT_0073ad34 - *(int *)(param_1 + 0x70 + param_2 * 4)) * 0.00025 < 5.0)) {
      return 0;
    }
  }
  else {
    iVar2 = SpecialCamCooldown();
    if ((iVar2 != 0) && ((float)(DAT_0073ad34 - *(int *)(param_1 + 0x70)) * 0.00025 < 0.1)) {
      return 0;
    }
  }
  if (*DAT_0073619c != 4) {
    return 0;
  }
  if (param_2 < 0) {
    return 0;
  }
  if (7 < param_2) {
    return 0;
  }
  if (DAT_007361c4 == 2) {
    return 0;
  }
  if (((param_2 == 6) || (param_2 == 7)) && (DAT_0078a3fa == '\0')) {
    return 0;
  }
  if ((((param_2 == 1) || (param_2 == 2)) || ((param_2 == 3 || ((param_2 == 4 || (param_2 == 5))))))
     && (DAT_0078a3fb == '\0')) {
    return 0;
  }
  if (SpecialCamTable3[*(int *)(param_1 + 0x60)] != (code)0x0) {
    Player__EndSpecialCamera(0);
  }
  iVar2 = 0;
  if (0 < DAT_007361c4) {
    do {
      if (SpecialCamModeTable__flags__0_0_0_1_1_1_1_1___5_readers__recheck__0x42da40_refuses_a_new_special_camera_when_a_player_s_byte_is_non_zero__so__busy__not__enable___I_
          [*(int *)((&DAT_007361bc)[iVar2] + 0x60)] != (code)0x0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_007361c4);
  }
  *(undefined4 *)(param_1 + 0xa0) = DAT_0073ad3c;
  if (param_3 == '\0') {
    *(int *)(param_1 + 0x70 + param_2 * 4) = DAT_0073ad34;
  }
  switch(param_2 + -1) {
  case 0:
    iVar2 = FUN_0041f6a0();
    if (iVar2 != 0) {
      return 0;
    }
    Player__ChangeCameraMover(param_1,0xd,1);
    fVar3 = (float10)0.6 + (float10)2.0 + (float10)0.4;
    goto LAB_0042dc52;
  case 1:
    iVar2 = FUN_0041f6a0();
    if (iVar2 != 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x4ac) != '\0') {
      return 0;
    }
    iVar2 = FUN_00492470(*(undefined4 *)(param_1 + 4));
    *(int *)(param_1 + 0x90) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
    Player__ChangeCameraMover(param_1,0xe,1);
    cVar1 = FUN_00492c00();
    if (cVar1 != '\0') {
      FUN_0042c450();
      return 0;
    }
    fVar3 = (float10)FUN_00492560();
LAB_0042dc52:
    iVar2 = DAT_007361f8;
    *(float *)(DAT_007361f8 + 0x2d4) = (float)(fVar3 - (float10)DAT_0073457c);
    *(code **)(iVar2 + 0x2e8) = FUN_0042da30;
    *(int *)(iVar2 + 0x2ec) = param_1;
    break;
  case 2:
    SlowMoStart(0x3eaa7efa,0x41000000,FUN_0042da30,param_1);
    break;
  case 3:
    SlowMoStart(0x3eaa7efa,0x40000000,FUN_0042da30,param_1);
    break;
  case 4:
    SlowMoStart(0x40000000,0x40800000,FUN_0042da30,param_1);
    break;
  case 5:
    SlowMoStart(0x3ecccccd,0x41000000,FUN_0042da30,param_1);
    iVar2 = FUN_0041f6a0();
    if (iVar2 == 0) {
      Player__ChangeCameraMover(param_1,0xf,1);
    }
    FUN_0042c640();
    break;
  case 6:
    SlowMoStart(0x3ecccccd,0x41000000,FUN_0042da30,param_1);
    iVar2 = FUN_0041f6a0();
    if (iVar2 == 0) {
      Player__ChangeCameraMover(param_1,0x10,1);
    }
  }
  _gSpecialCameraActive = 1;
  *(undefined1 *)(param_1 + 0x270) = 1;
  *(int *)(param_1 + 0x60) = param_2;
  *(char *)(param_1 + 0x98) = param_5;
  if (param_5 != '\0') {
    *(undefined4 *)(param_1 + 0x9c) = 0;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x9c) = _K_ONE;
  return 1;
}


// ==== 0x42ddc0 Player::EndSpecialCamera

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

void __thiscall Player__EndSpecialCamera(int param_1,char param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    _gSpecialCameraActive = 0;
    *(undefined1 *)(param_1 + 0x270) = 0;
    switch(*(int *)(param_1 + 0x60)) {
    case 1:
    case 2:
      if (DAT_007361fc == 0) {
        *(undefined4 *)(param_1 + 0x70) = DAT_0073ad34;
      }
    case 6:
    case 7:
      iVar1 = *DAT_007361f0;
      if (((iVar1 != 5) && (iVar1 != 6)) && (iVar1 != 10)) {
        FUN_0042c450();
      }
      if (((param_2 != '\0') && (*(char *)(*(int *)(param_1 + 4) + 0x874) == '\0')) &&
         ((iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x868), iVar1 != 0 &&
          (FUN_0058dc10(), *(char *)(iVar1 + 8) != '\0')))) {
        *(undefined1 *)(iVar1 + 8) = 0;
      }
    default:
      iVar1 = DAT_007361f8;
      *(undefined4 *)(DAT_007361f8 + 0x2e0) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x2e4) = 0;
      *(undefined4 *)(iVar1 + 0x2d4) = 0;
      *(undefined4 *)(iVar1 + 0x2e8) = 0;
      *(undefined4 *)(iVar1 + 0x2ec) = 0;
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined1 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x9c) = 0;
      FUN_0042d470();
    }
  }
  return;
}


// ==== 0x42deb0 FUN_0042deb0

uint FUN_0042deb0(void)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_c [3];
  
  uVar2 = *(uint *)(DAT_007361f0 + 0x3c);
  if ((((uVar2 == 0) || (*(int *)(uVar2 + 0x20) == 0)) || (*(int *)(uVar2 + 0x1c) == 0)) &&
     (((uVar2 = *(uint *)(DAT_007361f0 + 0x40), uVar2 == 0 || (*(int *)(uVar2 + 0x1c) == 0)) &&
      (uVar2 = 0, DAT_0073495c != 0)))) {
    iVar3 = 0;
    if (*(int *)(in_EAX + 0x27c) != 0) {
      iVar3 = *(int *)(*(int *)(in_EAX + 0x27c) + 0xc);
    }
    if (*(int *)(in_EAX + 0x278) == 6) {
      local_c[0] = 0;
      local_c[1] = 4;
      local_c[2] = 2;
      uVar2 = 0;
      while (piVar1 = local_c + uVar2, uVar2 = uVar2 + 1, iVar3 != *piVar1) {
        if (2 < (int)uVar2) {
          return uVar2;
        }
      }
      iVar3 = local_c[uVar2 % 3];
      if (iVar3 != 0) {
        puVar4 = (undefined4 *)(DAT_007361f0 + 0x30);
        if (*(undefined4 **)(DAT_007361f0 + 0x30) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(DAT_007361f0 + 0x30))(1);
          *puVar4 = 0;
        }
      }
      uVar2 = Player__ChangeCameraMover(in_EAX,iVar3,0);
      if (iVar3 == 0) {
        uVar2 = FUN_00422c40();
        return uVar2;
      }
    }
    else {
      if (0 < DAT_007796a8) {
        FUN_00480000();
        uVar2 = Player__DefaultDriveCamera(0);
        return uVar2;
      }
      if (iVar3 != 2) {
        if (iVar3 == 3) {
          FUN_0047ffe0();
          uVar2 = Player__DefaultDriveCamera(0);
          return uVar2;
        }
        if (iVar3 == 4) {
          uVar2 = Player__ChangeCameraMover(in_EAX,2,0);
          return uVar2;
        }
        uVar2 = Player__ChangeCameraMover(in_EAX,4,0);
        return uVar2;
      }
      uVar2 = Player__ChangeCameraMover(in_EAX,3,0);
    }
  }
  return uVar2;
}


// ==== 0x42e020 Player::CyclePOV

/* [canon] camera V (G+C) docs/re/camera.md */

int Player__CyclePOV(void)

{
  int in_EAX;
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int unaff_ESI;
  int local_4;
  
  iVar3 = in_EAX % 5;
  iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + 0xc);
  local_4 = -1;
  if (*(char *)(unaff_ESI + 0x2c) == iVar3) {
    local_4 = 0;
  }
  if (*(char *)(unaff_ESI + 0x2d) == iVar3) {
    local_4 = 1;
  }
  if (*(char *)(unaff_ESI + 0x2e) == iVar3) {
    local_4 = 2;
  }
  if (*(char *)(unaff_ESI + 0x2f) == iVar3) {
    local_4 = 3;
  }
  local_4 = local_4 + 1;
  if (3 < local_4) {
    local_4 = 0;
  }
  if (((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) && (local_4 == 3)) {
    local_4 = 0;
  }
  iVar3 = (int)*(char *)(local_4 + 0x2c + unaff_ESI);
  if (((5 < iVar3) || (iVar3 < 0)) || (iVar3 == 3)) {
    iVar3 = 0;
  }
  if (DAT_007364a0 == 3) {
    iVar4 = *(int *)(iVar1 + 0xb54);
    psVar5 = (short *)(iVar1 + 0xbb0);
  }
  else {
    iVar4 = *(int *)(iVar1 + 0xb50);
    psVar5 = (short *)(iVar1 + 0xb60);
  }
  iVar1 = 0;
  psVar2 = psVar5;
  if (0 < iVar4) {
    do {
      if (iVar3 == *psVar2) {
        if (psVar5 + iVar1 * 8 != (short *)0x0) {
          if (*(int **)(unaff_ESI + 0x27c) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_ESI + 0x27c) + 0x20))(iVar3);
          }
          if (*(int **)(unaff_ESI + 0x280) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_ESI + 0x280) + 0x20))(iVar3);
          }
          if (*(int **)(unaff_ESI + 0x284) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_ESI + 0x284) + 0x20))(iVar3);
          }
        }
        break;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 8;
    } while (iVar1 < iVar4);
  }
  (&DAT_00758948)[*(int *)(unaff_ESI + 0x10)] = local_4;
  (&DAT_0078a388)[*(int *)(unaff_ESI + 0x10) * 0x38] =
       (&DAT_00758938)[(&DAT_00758948)[*(int *)(unaff_ESI + 0x10)] * 4];
  return iVar3;
}


// ==== 0x42e150 FUN_0042e150

void FUN_0042e150(void)

{
  int unaff_ESI;
  
  if (*(int **)(unaff_ESI + 0x27c) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x27c) + 0x20))();
  }
  if (*(int **)(unaff_ESI + 0x280) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x280) + 0x20))();
  }
  if (*(int **)(unaff_ESI + 0x284) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x284) + 0x20))();
  }
  return;
}


// ==== 0x42e190 FUN_0042e190

void FUN_0042e190(void)

{
  int *piVar1;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 4) != 0) && (*(int *)(*(int *)(unaff_EDI + 4) + 0x24) != 2)) {
    FUN_00425fe0();
    piVar1 = *(int **)(*(int *)(unaff_EDI + 4) + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(unaff_EDI + 8));
      (**(code **)(*piVar1 + 0x20))();
      FUN_00461520();
      return;
    }
  }
  return;
}


// ==== 0x42e1e0 FUN_0042e1e0

void FUN_0042e1e0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 4) != 0) && (*(int *)(*(int *)(unaff_EDI + 4) + 0x24) != 1)) {
    FUN_00425fe0();
    piVar1 = *(int **)(*(int *)(unaff_EDI + 4) + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(unaff_EDI + 8));
      (**(code **)(*piVar1 + 0x20))();
      FUN_00461520();
      return;
    }
  }
  return;
}


// ==== 0x42e230 FUN_0042e230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e230(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_50 [76];
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(*(int *)(param_1 + 4) + 0x24) != 3)) {
    FUN_00425fe0();
    Car_SetMode();
    iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x3c);
    if (iVar7 != 0) {
      *(undefined1 *)(iVar7 + 0x1d) = 1;
    }
    *(undefined4 *)(param_1 + 0x1dc) = 0;
    if ((*(int *)(param_1 + 0x27c) != 0) && (*(int *)(*(int *)(param_1 + 0x27c) + 0xc) != 0x12)) {
      FUN_0042a5c0();
      FUN_0040bc10();
      local_60 = 1.0;
      local_5c = 0.0;
      local_58 = 0.0;
      if (*(int *)(param_1 + 0x1dc) != 0) {
        D3DXVec3Transform(&local_60,*(int *)(param_1 + 0x1dc) + 0x60,local_50);
        local_60 = local_60 - _DAT_00706230;
        local_5c = local_5c - _DAT_00706234;
        local_58 = local_58 - _DAT_00706238;
      }
      fVar3 = local_5c * local_5c;
      fVar4 = local_60 * local_60;
      uVar5 = Atan2ToAngle16(local_60,local_5c);
      *(undefined2 *)(param_1 + 0x1c4) = uVar5;
      uVar6 = Atan2ToAngle16(SQRT(fVar4 + fVar3),local_58,0xc57a0000,0x457a0000);
      FUN_00401c80((float)uVar6);
      uVar5 = _ftol_nocw();
      *(undefined2 *)(param_1 + 0x1c6) = uVar5;
      uVar2 = *(undefined4 *)(param_1 + 0x1e0);
      iVar7 = *(int *)(param_1 + 4) + 0x70;
      FUN_00483ea0(*(undefined4 *)(param_1 + 0x1e4),iVar7);
      FUN_00483fb0(uVar2,iVar7);
      cVar1 = *(char *)(param_1 + 0x24);
      if (((cVar1 != '\x01') && (cVar1 != '\0')) && (cVar1 != '\x04')) {
        FUN_0042ad90();
        FUN_0042ad90();
      }
    }
  }
  return;
}


// ==== 0x42e400 FUN_0042e400

void FUN_0042e400(void)

{
  int *piVar1;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 4) != 0) && (*(int *)(*(int *)(unaff_EDI + 4) + 0x24) != 1)) {
    FUN_00425fe0();
    Car_SetMode();
    piVar1 = *(int **)(*(int *)(unaff_EDI + 4) + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(unaff_EDI + 8));
      (**(code **)(*piVar1 + 0x20))();
      FUN_00461520();
      return;
    }
  }
  return;
}


// ==== 0x42e450 Player::LookBackToggle

/* [canon] camera I (C) docs/re/camera.md */

void Player__LookBackToggle(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0;
  local_c = 1;
  local_8 = 3;
  local_4 = 2;
  local_1c = 0;
  local_18 = 3;
  local_14 = 2;
  puVar3 = &local_10;
  iVar2 = 4;
  if (DAT_007361c4 == 2) {
    puVar3 = &local_1c;
    iVar2 = 3;
  }
  iVar4 = 0;
  iVar1 = 0;
  if (iVar2 != 0) {
    do {
      if (puVar3[iVar1] == (int)*(char *)(param_1 + 0x20)) {
        iVar4 = iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  iVar4 = iVar4 + param_2;
  if (iVar4 < 0) {
    iVar4 = iVar2 + -1;
  }
  if (iVar2 <= iVar4) {
    *(undefined1 *)(param_1 + 0x20) = *(undefined1 *)puVar3;
    return;
  }
  *(undefined1 *)(param_1 + 0x20) = *(undefined1 *)(puVar3 + iVar4);
  return;
}


// ==== 0x42e4f0 TrackMap::SelectMode

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void TrackMap__SelectMode(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if ((in_EAX == 1) && (DAT_00701084 == 0)) {
    in_EAX = 3;
  }
  if (DAT_0078a368 == 0) {
    if (DAT_007361c4 == 2) {
      if (*(int *)(unaff_ESI + 0x10) < 1) {
        if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
          iVar1 = FUN_005919b0();
          if (iVar1 == -1) {
            in_EAX = DAT_006f03e8;
          }
        }
        else {
          FUN_00414a10();
          FUN_00414a10();
          in_EAX = 6;
        }
      }
      else {
        in_EAX = 6;
      }
      if (DAT_0078a3f7 != in_EAX) {
        DAT_0078a3f7 = (char)in_EAX;
        *(undefined4 *)(unaff_ESI + 0x538) = DAT_006f0888;
      }
    }
    else {
      iVar1 = 0;
      do {
        if ((&DAT_006f03d4)[iVar1] == in_EAX) {
          if (iVar1 != -1) goto LAB_0042e5ec;
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 5);
      in_EAX = DAT_006f03d4;
LAB_0042e5ec:
      if (DAT_0078a3f6 != in_EAX) {
        DAT_0078a3f6 = (char)in_EAX;
        *(undefined4 *)(unaff_ESI + 0x538) = DAT_006f0888;
      }
    }
  }
  else {
    iVar1 = 0;
    do {
      if ((&DAT_006f03f0)[iVar1] == in_EAX) {
        if (iVar1 != -1) goto LAB_0042e52d;
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    in_EAX = DAT_006f03f0;
LAB_0042e52d:
    if (DAT_0078a3f8 != in_EAX) {
      DAT_0078a3f8 = (char)in_EAX;
      *(undefined4 *)(unaff_ESI + 0x538) = DAT_006f0888;
    }
  }
  if (*(int *)(unaff_ESI + 0x534) != 0) {
    *(int *)(*(int *)(unaff_ESI + 0x534) + 0xc0) = in_EAX;
  }
  return;
}


// ==== 0x42e620 Player::ComputeHudFlags

/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

undefined8 Player__ComputeHudFlags(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if ((*(int *)(param_1 + 4) == 0) ||
     ((((*(int *)(param_1 + 0x27c) != 0 &&
        (iVar3 = *(int *)(*(int *)(param_1 + 0x27c) + 0xc), 1 < iVar3)) && (iVar3 < 5)) ||
      (0 < DAT_007796a8)))) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x60);
  uVar6 = 0;
  uVar7 = 0x40000;
  if (((iVar3 != 0) && (iVar3 != 6)) && (iVar3 != 7)) goto LAB_0042eb7d;
  iVar4 = *DAT_007361f0;
  if ((iVar4 == 9) || (iVar4 == 10)) {
    uVar7 = 0;
LAB_0042eb7b:
    uVar6 = 0;
    goto LAB_0042eb7d;
  }
  if (iVar4 == 5) {
    uVar7 = 0;
    goto LAB_0042eb7b;
  }
  if (iVar4 == 1) {
    uVar7 = 0;
    goto LAB_0042eb7b;
  }
  if (iVar4 == 8) {
    uVar7 = 0;
    goto LAB_0042eb7b;
  }
  iVar1 = *DAT_0073619c;
  if ((iVar1 == 1) || (iVar1 == 2)) {
    uVar7 = 0x2000000;
    goto LAB_0042eb7b;
  }
  if ((iVar1 == 3) && (DAT_007361c4 == 1)) {
    uVar7 = 0x2040000;
    uVar6 = 0;
    iVar3 = FUN_0042ac10();
    if (iVar3 == 0) {
      if ((*(byte *)(param_1 + 0x30) & 0x40) != 0) {
        uVar6 = FUN_0042ebb0();
        uVar7 = uVar6 | 0x2040000;
        uVar6 = (int)uVar6 >> 0x1f | 0x40000;
      }
      cVar2 = FUN_00421a50();
      if ((cVar2 != '\0') && ((*(byte *)(param_1 + 0x30) & 0x40) != 0)) {
        uVar7 = uVar7 | 0x20000000;
      }
    }
    goto LAB_0042eb7d;
  }
  iVar1 = *(int *)(param_1 + 0x58);
  if ((iVar1 != 0) && (iVar4 == 4)) {
    uVar6 = 0;
    uVar7 = 0x40004;
    if ((DAT_007361c4 != 2) ||
       (((*(int *)(param_1 + 0x10) != 0 || (*(int *)(DAT_007361b8 + 0x58) != 0)) ||
        (DAT_0078a3f7 == '\x06')))) goto LAB_0042eb7d;
    uVar7 = 0x40005;
    goto LAB_0042eb7b;
  }
  iVar4 = FUN_0042ac10();
  if (iVar4 != 0) {
    cVar2 = FUN_0042ac30();
    if (cVar2 != '\0') {
      uVar7 = 0x2040000;
    }
    uVar6 = 0;
    if (*(int *)(param_1 + 0x538) != 0) {
      if (DAT_006f0888 - *(int *)(param_1 + 0x538) < 0x3c) {
        uVar7 = uVar7 | 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x538) = 0;
      }
    }
    cVar2 = FUN_0043a2e0();
    if (cVar2 != '\0') {
      uVar7 = uVar7 | 0x4000;
    }
    goto LAB_0042eb7d;
  }
  if ((iVar3 == 1) || (iVar3 == 2)) {
    uVar7 = 0x42000;
    goto LAB_0042eb7b;
  }
  switch(*(undefined1 *)(param_1 + 0x20)) {
  case 0:
    uVar6 = 0x140000;
    if ((*(int *)(param_1 + 0x27c) != 0) &&
       (cVar2 = (**(code **)(**(int **)(param_1 + 0x27c) + 0x28))(), cVar2 != '\0')) {
      uVar6 = 0x40000;
    }
    cVar2 = DAT_0078a3f8;
    if ((DAT_0078a368 == 0) && (cVar2 = DAT_0078a3f7, DAT_007361c4 != 2)) {
      cVar2 = DAT_0078a3f6;
    }
    if (cVar2 != '\x06') {
      uVar6 = uVar6 | 1;
    }
    uVar8 = *(uint *)(param_1 + 0x30);
    if ((uVar8 & 0x100) != 0) {
      uVar6 = uVar6 | 0x508;
    }
    if (((uVar8 & 4) != 0) && ((DAT_007361c4 != 2 || (cVar2 = FUN_0041f600(), cVar2 == '\0')))) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x10) != 0) {
      uVar6 = uVar6 | 0x200;
    }
    if (((((uVar8 & 0x200) != 0) && (DAT_0078a368 == 0)) &&
        (iVar3 = SpecialCamCooldown(), iVar3 == 0)) &&
       (((cVar2 = FUN_00432a10(), cVar2 == '\0' && (DAT_0078a3f9 != '\0')) &&
        (cVar2 = FUN_00421a50(), cVar2 == '\0')))) {
      uVar6 = uVar6 | 0x800000;
    }
    uVar7 = uVar6;
    if ((DAT_0078a3f4 != '\0') && (uVar7 = uVar6 | 0x1000, *(char *)(param_1 + 0x4ad) != '\0')) {
      uVar7 = uVar6;
    }
    if ((DAT_0078a30c == 2) && (DAT_0078a318 == 0)) {
      uVar7 = uVar7 & 0xfffffdff;
    }
    if (((DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320 == 1) ||
        (cVar2 = FUN_00432a10(), cVar2 != '\0')) && (cVar2 = FUN_0041f600(), cVar2 == '\0')) {
      uVar7 = uVar7 & 0xfffffdff;
    }
    if ((uVar8 & 0x400) != 0) {
      uVar7 = uVar7 | 0x20000;
    }
    cVar2 = FUN_00432a10();
    if ((((cVar2 != '\0') || ((DAT_0078a368 != 0 && (DAT_007361c4 == 2)))) ||
        (*(int *)(param_1 + 0x50) == 0)) ||
       ((cVar2 = FUN_0041f600(), cVar2 == '\0' && (DAT_007361c4 == 2)))) {
      uVar7 = uVar7 & 0xfffdffff;
    }
    uVar5 = FUN_0042ebb0();
    if ((uVar8 & 0x40) == 0) {
      uVar7 = uVar7 & ~uVar5;
      uVar6 = 0;
      cVar2 = FUN_00421a50();
      if ((cVar2 == '\0') && (cVar2 = FUN_0041f600(), cVar2 == '\0')) {
        FUN_0042ab30();
      }
    }
    else {
      uVar6 = (int)uVar5 >> 0x1f | 0x40000;
      uVar7 = uVar7 | uVar5;
      cVar2 = FUN_00421a50();
      if (cVar2 == '\0') {
        cVar2 = FUN_0041f600();
        if (cVar2 == '\0') {
          cVar2 = FUN_0042ab30();
          if (cVar2 != '\0') {
            uVar7 = uVar7 | 0x10000;
          }
        }
        else {
          uVar7 = uVar7 | 0x80000000;
        }
      }
      else {
        uVar7 = uVar7 | 0x20000000;
      }
    }
    cVar2 = FUN_0042ab30();
    if (cVar2 != '\0') {
      uVar7 = uVar7 & 0xffffefff;
    }
    break;
  case 1:
    if ((DAT_0078a350 != 0) && (DAT_0078a368 == 0)) {
      uVar7 = 0x4040000;
    }
    uVar6 = 0;
    if (DAT_007361c4 == 1) {
      uVar7 = uVar7 | 1;
    }
    break;
  case 2:
    if (DAT_0078a350 == 0) break;
    if (DAT_0078a368 != 0) goto LAB_0042eb1d;
    if (iVar1 == 0) {
      uVar7 = 0x4040000;
      uVar6 = 0;
    }
    goto LAB_0042eb34;
  case 3:
    if ((DAT_0078a350 != 0) && (DAT_0078a368 == 0)) {
      uVar7 = 0x4040000;
    }
    uVar8 = FUN_0042ebb0();
    uVar6 = (int)uVar8 >> 0x1f;
    uVar7 = uVar7 | uVar8;
  }
  if (DAT_0078a368 != 0) {
LAB_0042eb1d:
    uVar7 = uVar7 & 0xfbff7dff;
    if (*(int *)(param_1 + 0x278) == 4) {
      uVar7 = uVar7 | 0x400000;
    }
  }
LAB_0042eb34:
  if (DAT_007361c4 == 2) {
    uVar8 = uVar7;
    if ((uVar7 & 0x4000000) != 0) {
      uVar8 = uVar7 & 0xfbffffff | 0x8000;
    }
    uVar7 = uVar8 & 0xffefffff;
    if (*(int *)(param_1 + 0x10) == 1) {
      uVar7 = uVar8 & 0xffeffffe;
    }
  }
  uVar7 = uVar7 | 0x4000;
LAB_0042eb7d:
  if (DAT_00700e8c == 0) {
    uVar6 = uVar6 | 0x20000;
  }
  return CONCAT44(uVar6,uVar7);
}


// ==== 0x42ebb0 FUN_0042ebb0

undefined4 __fastcall FUN_0042ebb0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x27c);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    if ((((*(int *)(iVar1 + 0xc) == 1) ||
         (((*(int *)(iVar1 + 0xc) == 0x11 || (*(int *)(param_2 + 0x60) == 6)) ||
          (*(int *)(param_2 + 0x60) == 7)))) ||
        (((iVar1 = *(int *)(iVar1 + 0xc), iVar1 == 0x13 || (iVar1 == 0x14)) || (iVar1 == 0x15)))) ||
       (iVar1 == 0x16)) {
      return 0x40;
    }
    if (DAT_0078eb60 == '\0') {
      DAT_0078eb60 = '\x01';
    }
  }
  return 0;
}


// ==== 0x42ec10 FUN_0042ec10

void __thiscall FUN_0042ec10(int param_1,uint param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688573;
  local_c = ExceptionList;
  if (((*(uint *)(param_1 + 0x4b0) ^ param_2) & 1) != 0) {
    if ((param_2 & 1) != 0) {
      ExceptionList = &local_c;
      pvVar1 = _malloc(0xd0);
      local_4 = 0;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = TrackMap__TrackMap(DAT_00736174,*(undefined4 *)(param_1 + 4),param_1);
      }
      *(undefined4 *)(param_1 + 0x534) = uVar2;
      local_4 = 0xffffffff;
      if (DAT_0078a368 == 0) {
        TrackMap__SelectMode();
        ExceptionList = local_c;
        return;
      }
      TrackMap__SelectMode();
      ExceptionList = local_c;
      return;
    }
    if (*(void **)(param_1 + 0x534) != (void *)0x0) {
      ExceptionList = &local_c;
      _free(*(void **)(param_1 + 0x534));
    }
    *(undefined4 *)(param_1 + 0x534) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x42ed40 Player::SetHudFlags

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void Player__SetHudFlags(undefined4 param_1,undefined4 param_2)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x95c) != 0) {
    HudManager__SetFlags(*(int *)(unaff_ESI + 0x95c),param_1,param_2);
  }
  *(uint *)(unaff_ESI + 0x4b0) = *(uint *)(unaff_ESI + 0x4b0) & 0xffffff9f;
  *(undefined4 *)(unaff_ESI + 0x4b4) = *(undefined4 *)(unaff_ESI + 0x4b4);
  FUN_0042ec10(param_1,param_2);
  *(undefined4 *)(unaff_ESI + 0x4b4) = param_2;
  *(undefined4 *)(unaff_ESI + 0x4b0) = param_1;
  return;
}


// ==== 0x42eda0 FUN_0042eda0

void FUN_0042eda0(undefined4 param_1,float param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006863e3;
  local_c = ExceptionList;
  if (((DAT_0078a337 != '\0') && (*DAT_007361f0 == 4)) && (*(int *)(unaff_ESI + 0x298) == 0)) {
    if (param_2 == 0.0) {
      param_2 = 5.0;
    }
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x70);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0042ae50(pvVar1,unaff_ESI,param_1,param_2);
    }
    *(undefined4 *)(unaff_ESI + 0x298) = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x42ee40 FUN_0042ee40

undefined4 __fastcall FUN_0042ee40(int param_1)

{
  float fVar1;
  
  if (*(int *)(param_1 + 0x1dc) != 0) {
    fVar1 = -0.3;
    if (-0.3 < *(float *)(param_1 + 0x1cc)) {
      fVar1 = *(float *)(param_1 + 0x1cc);
    }
    if (0.3 < fVar1) {
      fVar1 = 0.3;
    }
    if (fVar1 == *(float *)(param_1 + 0x1cc)) {
      fVar1 = -0.3;
      if (-0.3 < *(float *)(param_1 + 0x1d0)) {
        fVar1 = *(float *)(param_1 + 0x1d0);
      }
      if (0.3 < fVar1) {
        fVar1 = 0.3;
      }
      if (fVar1 == *(float *)(param_1 + 0x1d0)) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x42eee0 FUN_0042eee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0042eee0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *piVar8;
  float *unaff_ESI;
  float *unaff_EDI;
  int local_1c;
  
  iVar7 = *(int *)(DAT_007361f8 + 0x20) - *(int *)(DAT_007361f8 + 0x1c);
  local_1c = 0;
  if (0 < iVar7) {
    piVar8 = (int *)(DAT_007361f8 + 0x28 + *(int *)(DAT_007361f8 + 0x1c) * 4);
    fVar6 = _K_ONE;
    do {
      iVar1 = *piVar8;
      fVar2 = *(float *)(iVar1 + 0x60) - *unaff_EDI;
      fVar5 = *(float *)(iVar1 + 100) - unaff_EDI[1];
      fVar4 = *(float *)(iVar1 + 0x68) - unaff_EDI[2];
      fVar3 = SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar2 * fVar2);
      fVar2 = fVar5 * unaff_ESI[1] + fVar4 * unaff_ESI[2] + fVar2 * *unaff_ESI;
      fVar4 = (_K_ONE / 300.0) * fVar2;
      fVar2 = SQRT(fVar3 * fVar3 - fVar2 * fVar2) * (_K_ONE / 5.0);
      if (fVar4 <= 0.0) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = fVar4;
        if (_K_ONE < fVar4) {
          fVar3 = _K_ONE;
        }
      }
      if (((fVar4 == fVar3) && (fVar2 < _K_ONE != (fVar2 == _K_ONE))) && (fVar2 < fVar6)) {
        local_1c = iVar1;
        fVar6 = fVar2;
      }
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    return local_1c;
  }
  return 0;
}


// ==== 0x42f020 FUN_0042f020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042f020(undefined4 param_1)

{
  float *unaff_ESI;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined1 local_20 [28];
  
  D3DXVec3Transform(local_20,param_1);
  if (fStack_24 == 0.0) {
    *unaff_ESI = 0.0;
    unaff_ESI[1] = 0.0;
    return;
  }
  fVar1 = (float10)FUN_00564b10();
  fVar2 = (float10)FUN_00564b10();
  fVar3 = (float10)_K_ONE;
  *unaff_ESI = (float)(((float10)fStack_2c * (fVar3 / (float10)ABS(fStack_24))) /
                      ((float10)(float)fVar1 / fVar2));
  unaff_ESI[1] = (float)(((fVar3 / (float10)ABS(fStack_24)) * (float10)fStack_28) /
                        (((float10)DAT_00701038 * ((float10)(float)fVar1 / fVar2)) /
                        (float10)DAT_00701034));
  return;
}


// ==== 0x42f0c0 FUN_0042f0c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f0c0(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  uint3 uVar5;
  char cVar6;
  undefined2 uVar7;
  short sVar8;
  short sVar9;
  undefined4 uVar10;
  int unaff_EBX;
  float unaff_ESI;
  int iVar11;
  undefined4 unaff_EDI;
  float *pfVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 uStack_104;
  float local_100;
  float local_fc;
  float local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined4 *puStack_e8;
  int iStack_e4;
  undefined2 uStack_e0;
  undefined2 uStack_de;
  undefined4 uStack_dc;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 auStack_ac [4];
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [12];
  undefined1 local_90 [64];
  undefined1 local_50 [76];
  
  uVar5 = (uint3)uStack_104;
  FUN_0042a5c0();
  FUN_0040bc10();
  cVar6 = FUN_0042ee40();
  if (cVar6 == '\0') {
    sVar9 = *(short *)(unaff_EBX + 0x1c6);
    uVar7 = _ftol_nocw();
    *(undefined2 *)(unaff_EBX + 0x1c6) = uVar7;
    sVar8 = _ftol_nocw();
    *(short *)(unaff_EBX + 0x1c4) = *(short *)(unaff_EBX + 0x1c4) + sVar8;
    Angle16SinCos();
    Angle16SinCos();
    local_100 = (float)(int)sVar9 * local_100;
    local_fc = (float)(int)sVar9 * local_fc;
  }
  else {
    D3DXVec3Transform(&local_100,*(int *)(unaff_EBX + 0x1dc) + 0x60,local_50);
    local_100 = local_100 - _DAT_00706230;
    local_fc = local_fc - _DAT_00706234;
    local_f8 = local_f8 - _DAT_00706238;
    bNormalize3();
    fVar3 = local_fc * local_fc;
    fVar1 = local_100 * local_100;
    uVar7 = Atan2ToAngle16(local_100,local_fc);
    *(undefined2 *)(unaff_EBX + 0x1c4) = uVar7;
    uVar7 = Atan2ToAngle16(SQRT(fVar1 + fVar3),local_f8);
    *(undefined2 *)(unaff_EBX + 0x1c6) = uVar7;
  }
  iVar11 = *(int *)(unaff_EBX + 0x1dc);
  if (iVar11 == 0) {
    fVar3 = 0.0;
  }
  else {
    iVar2 = *(int *)(unaff_EBX + 4);
    fVar3 = *(float *)(iVar2 + 0x60) - *(float *)(iVar11 + 0x60);
    fVar1 = *(float *)(iVar2 + 100) - *(float *)(iVar11 + 100);
    fVar4 = *(float *)(iVar2 + 0x68) - *(float *)(iVar11 + 0x68);
    fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
  }
  *(float *)(unaff_EBX + 0x238) = fVar3;
  uStack_104 = (float)(uint)(uint3)uStack_104;
  cVar6 = FUN_0042ee40();
  if ((cVar6 == '\0') || ((&DAT_0073b3ba)[*(int *)(unaff_EBX + 8) * 0x18c] == '\0')) {
    *(undefined2 *)(unaff_EBX + 0x1c8) = 0x32dc;
  }
  else {
    sVar9 = Atan2ToAngle16(fVar3,0x40200000);
    uStack_104 = (float)CONCAT13(1,uVar5);
    *(short *)(unaff_EBX + 0x1c8) = sVar9 << 1;
  }
  fStack_f0 = local_100 * -4.0 + _DAT_00706230;
  fStack_ec = local_fc * -4.0 + _DAT_00706234;
  puStack_e8 = (undefined4 *)(local_f8 * -4.0 + _DAT_00706238);
  FUN_004831c0(fStack_f0,fStack_ec,puStack_e8);
  FUN_00593d40(param_1,0,0);
  FUN_00593d40(param_1,0,0);
  FUN_00593d40(param_1,0,0);
  puVar14 = *(undefined4 **)(unaff_EBX + 0x1e4);
  uStack_b8 = puVar14[0x18];
  uStack_c0 = *puVar14;
  uStack_bc = puVar14[0xc];
  puVar14 = &uStack_c0;
  puVar13 = &uStack_c0;
  D3DXVec3Transform(puVar13,puVar14,local_90);
  local_fc = unaff_ESI * 20.0 + _DAT_00706230;
  local_f8 = fVar3 * 20.0 + _DAT_00706234;
  fStack_f4 = uStack_104 * 20.0 + _DAT_00706238;
  FUN_004831c0(local_fc,local_f8,fStack_f4);
  FUN_00593d40(param_1,0,0);
  FUN_00593d40(param_1,0,0);
  FUN_00593d40(param_1,0,0);
  if ((char)((uint)unaff_EDI >> 0x18) == '\0') {
    pfVar12 = *(float **)(unaff_EBX + 0x1e0);
    fStack_f4 = pfVar12[0x18];
    local_f8 = pfVar12[0xc];
    local_fc = *pfVar12;
    D3DXVec3Transform(&uStack_bc,&local_fc,auStack_9c);
  }
  else {
    iVar11 = *(int *)(unaff_EBX + 0x1dc);
    uStack_b8 = *(undefined4 *)(iVar11 + 100);
    uStack_bc = *(undefined4 *)(iVar11 + 0x60);
    uStack_b4 = *(undefined4 *)(iVar11 + 0x68);
  }
  local_fc = 0.0;
  local_f8 = 0.0;
  fStack_f4 = 1.0;
  FUN_0040b780(&local_fc);
  CameraMover_ClipAgainstWorld
            (*(undefined4 *)(unaff_EBX + 0x27c),unaff_EBX + 0x1f0,*(undefined4 *)(unaff_EBX + 4));
  iVar11 = unaff_EBX + 0x230;
  _uStack_e0 = CONCAT22(uStack_de,
                        *(undefined2 *)(*(int *)(*(int *)(unaff_EBX + 0x27c) + 0x1c) + 0xc4));
  pfVar12 = (float *)&DAT_006b7a40;
  do {
    fVar1 = *pfVar12;
    local_fc = unaff_ESI * fVar1 + _DAT_00706230;
    local_f8 = fVar3 * fVar1 + _DAT_00706234;
    fStack_f4 = fVar1 * uStack_104 + _DAT_00706238;
    D3DXVec3Transform(&local_fc,&local_fc,auStack_9c,puVar13,puVar14,iVar11);
    FUN_0042f020();
    iVar11 = iVar11 + 0x10;
    pfVar12 = pfVar12 + 1;
  } while ((int)pfVar12 < 0x6b7a4c);
  D3DXVec3Transform(auStack_ac,&DAT_00706230,auStack_9c,puVar13,puVar14,iVar11);
  uStack_dc = 0;
  puStack_e8 = puVar14;
  iStack_e4 = iVar11;
  thunk_FUN_005ac436(&puStack_e8,&puStack_e8,auStack_a8);
  uVar10 = FUN_0042eee0(unaff_EBX);
  *(undefined4 *)(unaff_EBX + 0x1dc) = uVar10;
  *(undefined4 *)(unaff_EBX + 0x1d8) = *(undefined4 *)(unaff_EBX + 0x1d0);
  *(undefined4 *)(unaff_EBX + 0x1d4) = *(undefined4 *)(unaff_EBX + 0x1cc);
  return;
}


// ==== 0x42f5f0 FUN_0042f5f0

void __thiscall FUN_0042f5f0(int param_1,float param_2)

{
  int iVar1;
  
  *(float *)(param_1 + 200) = param_2;
  if ((((*(ushort *)(param_1 + 0xc4) & 1) != 0) && ((*(ushort *)(param_1 + 0xc4) & 2) == 0)) &&
     ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))) {
    iVar1 = *(byte *)(param_1 + 199) - 1;
    *(float *)(param_1 + 0xcc) = param_2 + *(float *)(param_1 + 0xcc);
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    *(char *)(param_1 + 199) = (char)iVar1;
  }
  return;
}


// ==== 0x42f650 FUN_0042f650

void FUN_0042f650(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  ushort uVar11;
  short sVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 4);
  if (iVar2 == 0) {
    return;
  }
  uVar11 = *(ushort *)(unaff_ESI + 0xc4);
  iVar17 = 0;
  uVar15 = ((byte)~(byte)uVar11 & 1) << 1 | 1;
  uVar14 = *(uint *)(iVar2 + 0x354);
  if ((int)uVar14 < 4) {
    uVar11 = uVar11 & 0xffdf;
  }
  else {
    if ((uVar11 & 0x20) != 0) goto LAB_0042f6ac;
    iVar17 = 1;
    uVar11 = uVar11 | 0x20;
  }
  *(ushort *)(unaff_ESI + 0xc4) = uVar11;
LAB_0042f6ac:
  uVar3 = *(uint *)(iVar2 + 0x358);
  if ((int)uVar3 < 4) {
    *(byte *)(unaff_ESI + 0xc4) = *(byte *)(unaff_ESI + 0xc4) & 0xbf;
  }
  else if ((*(ushort *)(unaff_ESI + 0xc4) & 0x40) == 0) {
    iVar17 = iVar17 + 1;
    *(ushort *)(unaff_ESI + 0xc4) = *(ushort *)(unaff_ESI + 0xc4) | 0x40;
  }
  uVar4 = *(uint *)(iVar2 + 0x35c);
  if ((int)uVar4 < 4) {
    *(byte *)(unaff_ESI + 0xc4) = *(byte *)(unaff_ESI + 0xc4) & 0x7f;
  }
  else if (-1 < (char)*(ushort *)(unaff_ESI + 0xc4)) {
    iVar17 = iVar17 + 1;
    *(ushort *)(unaff_ESI + 0xc4) = *(ushort *)(unaff_ESI + 0xc4) | 0x80;
  }
  uVar5 = *(uint *)(iVar2 + 0x360);
  if ((int)uVar5 < 4) {
    *(byte *)(unaff_ESI + 0xc5) = *(byte *)(unaff_ESI + 0xc5) & 0xfe;
  }
  else if ((*(ushort *)(unaff_ESI + 0xc4) & 0x100) == 0) {
    iVar17 = iVar17 + 1;
    *(ushort *)(unaff_ESI + 0xc4) = *(ushort *)(unaff_ESI + 0xc4) | 0x100;
  }
  if (iVar17 != 0) {
    iVar13 = (uint)*(byte *)(unaff_ESI + 199) - iVar17;
    if (iVar13 < 1) {
      iVar13 = 1;
    }
    *(char *)(unaff_ESI + 199) = (char)iVar13;
  }
  if ((*(int *)(unaff_ESI + 0x58) == 0) &&
     ((bool)(*(byte *)(unaff_ESI + 0xc4) & 1) !=
      (((uVar15 == uVar14 && uVar15 == uVar3) && uVar15 == uVar4) && uVar15 == uVar5))) {
    bVar16 = 1;
  }
  else {
    bVar16 = 0;
  }
  *(byte *)(unaff_ESI + 0xc4) = *(byte *)(unaff_ESI + 0xc4) & 0xe7;
  fVar8 = (float)*(byte *)(unaff_ESI + 199) *
          (*(float *)(unaff_ESI + 0xcc) * 10.0 + (float)*(byte *)(unaff_ESI + 0xc6) * 100.0);
  *(float *)(unaff_ESI + 0xd8) = fVar8;
  uVar11 = *(ushort *)(unaff_ESI + 0xc4);
  if (((uVar11 & 1) == 0) || (bVar16 != 0)) {
    if (((uVar11 & 1) == 0) && (bVar16 != 0)) {
      *(undefined4 *)(unaff_ESI + 0xd4) = 0;
      *(undefined4 *)(unaff_ESI + 0xd8) = 0;
      *(undefined4 *)(unaff_ESI + 0xcc) = 0;
      *(undefined1 *)(unaff_ESI + 0xc6) = 0;
    }
  }
  else if ((uVar11 & 2) == 0) {
    if ((0.0 < *(float *)(unaff_ESI + 0xd4)) && (fVar8 == 0.0)) {
      uVar14 = *(byte *)(unaff_ESI + 199) + 1;
      if (5 < uVar14) {
        uVar14 = 5;
      }
      *(char *)(unaff_ESI + 199) = (char)uVar14;
    }
    fVar8 = (*(float *)(unaff_ESI + 0xd4) + *(float *)(unaff_ESI + 0xd0)) -
            *(float *)(unaff_ESI + 0xd8);
    if (fVar8 < 0.0) {
      fVar8 = 0.0;
    }
    *(float *)(unaff_ESI + 0xd0) = fVar8;
    *(ushort *)(unaff_ESI + 0xc4) = uVar11 | 0x10;
  }
  else {
    *(ushort *)(unaff_ESI + 0xc4) = uVar11 & 0xfffd | 8;
  }
  *(ushort *)(unaff_ESI + 0xc4) = (ushort)bVar16 | *(ushort *)(unaff_ESI + 0xc4) & 0xfffe;
  if (1.0 <= *(float *)(iVar2 + 0x3d0)) {
    sVar12 = Atan2ToAngle16(*(undefined4 *)(iVar2 + 0x70),*(undefined4 *)(iVar2 + 0x74));
    fVar8 = (float)(ushort)(*(short *)(iVar2 + 0x3b4) - sVar12) * 9.58738e-05;
    if (3.14159 < fVar8) {
      fVar8 = fVar8 - 6.28318;
    }
  }
  else {
    fVar8 = 0.0;
  }
  fVar8 = ABS(fVar8);
  bVar7 = 0.08726646 <= fVar8;
  if (bVar7) {
    *(int *)(unaff_ESI + 0xdc) = DAT_0073ad34;
  }
  else {
    fVar8 = 0.0;
  }
  iVar2 = *(int *)(unaff_ESI + 0xdc);
  if (((iVar2 != 0) && (iVar2 != 0x7fffffff)) && (2.0 < (float)(DAT_0073ad34 - iVar2) * 0.00025)) {
    *(undefined1 *)(unaff_ESI + 199) = 1;
    *(undefined4 *)(unaff_ESI + 0xdc) = 0;
  }
  fVar6 = *(float *)(*(int *)(unaff_ESI + 4) + 0x3d4);
  if ((*(char *)(unaff_ESI + 0x4ac) == '\0') && (1.0 <= fVar6)) {
    *(int *)(unaff_ESI + 0xe0) = DAT_0073ad34;
  }
  uVar11 = *(ushort *)(unaff_ESI + 0xc4);
  if ((((uVar11 & 1) != 0) && ((uVar11 & 2) == 0)) &&
     (1.0 < (float)(DAT_0073ad34 - *(int *)(unaff_ESI + 0xe0)) * 0.00025)) {
    *(ushort *)(unaff_ESI + 0xc4) = uVar11 | 2;
    *(undefined1 *)(unaff_ESI + 0xc6) = 0;
    *(undefined4 *)(unaff_ESI + 0xcc) = 0;
    *(undefined4 *)(unaff_ESI + 0xd4) = 0;
    *(undefined1 *)(unaff_ESI + 199) = 1;
  }
  if (bVar7) {
    if (DAT_00734964 != 0) {
      if (*(char *)(unaff_ESI + 0xfc) != '\0') {
        *(undefined4 *)(unaff_ESI + 0xf0) = 0;
        *(undefined4 *)(unaff_ESI + 0xf4) = 0;
        *(undefined4 *)(unaff_ESI + 0xe4) = 0;
        *(undefined1 *)(unaff_ESI + 0xfc) = 0;
      }
      iVar2 = *(int *)(unaff_ESI + 0xf8);
      iVar13 = iVar2 + 1;
      *(int *)(unaff_ESI + 0xf8) = iVar13;
      *(float *)(unaff_ESI + 0xe8) = fVar8 * 57.295776;
      *(float *)(unaff_ESI + 0xec) = fVar6 * 2.237;
      fVar10 = (float)iVar2;
      fVar9 = (float)iVar13;
      *(float *)(unaff_ESI + 0xf0) =
           (fVar10 * *(float *)(unaff_ESI + 0xf0) + fVar8 * 57.295776) / fVar9;
      *(float *)(unaff_ESI + 0xf4) = (fVar10 * *(float *)(unaff_ESI + 0xf4) + fVar6 * 2.237) / fVar9
      ;
      *(float *)(unaff_ESI + 0xe4) = DAT_0073457c + *(float *)(unaff_ESI + 0xe4);
    }
  }
  else if (DAT_00734964 != 0) {
    *(undefined1 *)(unaff_ESI + 0xfc) = 1;
    *(undefined4 *)(unaff_ESI + 0xf8) = 0;
  }
  uVar11 = *(ushort *)(unaff_ESI + 0xc4);
  if (((uVar11 & 1) != 0) && ((uVar11 & 2) == 0)) {
    fVar9 = (float)*(byte *)(unaff_ESI + 199) * 25.0 * DAT_0073457c;
    *(char *)(unaff_ESI + 0xc6) = *(char *)(unaff_ESI + 0xc6) + (char)iVar17;
    *(float *)(unaff_ESI + 0xd4) = fVar9 * fVar6 * fVar8 + *(float *)(unaff_ESI + 0xd4);
  }
  if ((*(int *)(unaff_ESI + 0x58) != 0) && ((uVar11 & 4) == 0)) {
    *(ushort *)(unaff_ESI + 0xc4) = uVar11 | 4;
    sVar12 = *(short *)(DAT_00736174 + 0xba);
    sVar1 = *(short *)(DAT_00736174 + 0xbc);
    *(undefined4 *)(unaff_ESI + 0xd4) = 0;
    fVar8 = (float)*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + 0x1c) + 0x110) * 0.00025;
    if (fVar8 < (float)(int)sVar12 == (fVar8 == (float)(int)sVar12)) {
      if (fVar8 < (float)(int)sVar1 != (fVar8 == (float)(int)sVar1)) {
        *(undefined4 *)(unaff_ESI + 0xd4) = 0x42c80000;
      }
    }
    else {
      *(undefined4 *)(unaff_ESI + 0xd4) = 0x43fa0000;
    }
    if (*(char *)(unaff_ESI + 0x8d4) == '\0') {
      fVar8 = 0.0;
    }
    else {
      fVar8 = 100.0;
    }
    *(float *)(unaff_ESI + 0xcc) = fVar8;
    *(float *)(unaff_ESI + 0xd0) =
         *(float *)(unaff_ESI + 0xd4) + *(float *)(unaff_ESI + 0xd0) + fVar8;
  }
  return;
}


// ==== 0x42fc00 FUN_0042fc00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042fc00(void)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  byte bVar4;
  float *pfVar5;
  int iVar6;
  
  iVar2 = *(int *)(in_EAX + 0x27c);
  if (iVar2 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(iVar2 + 0xc);
  }
  iVar3 = *(int *)(DAT_007361f0 + 0x3c);
  if (((((iVar3 == 0) || (*(int *)(iVar3 + 0x20) == 0)) || (*(int *)(iVar3 + 0x1c) == 0)) &&
      ((*(int *)(DAT_007361f0 + 0x40) == 0 || (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0))
      )) && ((iVar6 < 2 || (4 < iVar6)))) {
    fVar1 = _DAT_007796b0;
    if (DAT_007796a8 < 1) {
      fVar1 = *(float *)(*(int *)(in_EAX + 4) + 0x814);
    }
    iVar3 = DAT_007796a0 + -1;
    if (0 < iVar3) {
      pfVar5 = (float *)(&DAT_00778ac8 + iVar3 * 0x4c);
      do {
        if (*pfVar5 <= fVar1) break;
        iVar3 = iVar3 + -1;
        pfVar5 = pfVar5 + -0x13;
      } while (0 < iVar3);
    }
    if (&DAT_00778ac0 + iVar3 * 0x4c == (byte *)0x0) {
      bVar4 = 0;
    }
    else {
      bVar4 = (&DAT_00778ac0)[iVar3 * 0x4c];
    }
    if (((DAT_00700b5c != 0) || (*(float *)(*(int *)(in_EAX + 4) + 0x3d4) < 0.0)) ||
       ((bVar4 < 2 || (bVar4 == 0x11)))) {
      if (((iVar2 == 0) || (iVar6 == 0x14)) &&
         (Player__DefaultDriveCamera(0), (&DAT_00778ac1)[iVar3 * 0x4c] == '\0')) {
        (**(code **)(**(int **)(in_EAX + 0x27c) + 0x34))();
      }
    }
    else if ((iVar2 == 0) || (iVar6 != 0x14)) {
      Player__ChangeCameraMover(in_EAX,0x14,0);
    }
  }
  if (((DAT_0078a2f0 == 1099) && (DAT_00735fb0 != 0)) && (DAT_00735fb8 == 4)) {
    *(undefined1 *)(in_EAX + 0x4af) = 1;
    return;
  }
  iVar2 = DAT_007361ac;
  if (DAT_007361ac == 3) {
    iVar2 = (int)*(char *)(in_EAX + 0x2a);
  }
  *(bool *)(in_EAX + 0x4af) = iVar2 == 0;
  *(bool *)(in_EAX + 0x4af) = iVar2 == 0 && 1.0 < *(float *)(*(int *)(in_EAX + 4) + 0x3d0);
  iVar2 = (**(code **)(**(int **)(*(int *)(in_EAX + 4) + 0x2c) + 0x40))();
  if ((iVar2 == DAT_0078a2fc) && (*(char *)(in_EAX + 0x4ac) == '\0')) {
    bVar4 = 1;
  }
  else {
    bVar4 = 0;
  }
  bVar4 = *(byte *)(in_EAX + 0x4af) & bVar4;
  *(byte *)(in_EAX + 0x4af) = bVar4;
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    *(undefined1 *)(in_EAX + 0x4af) = 0;
    return;
  }
  *(byte *)(in_EAX + 0x4af) = bVar4;
  return;
}


// ==== 0x42fdf0 FUN_0042fdf0

void FUN_0042fdf0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x140) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x144) = 0;
  *(undefined4 *)(in_EAX + 0x148) = 0;
  *(undefined4 *)(in_EAX + 0x14c) = 0;
  *(undefined4 *)(in_EAX + 0x150) = 0;
  *(undefined4 *)(in_EAX + 0x154) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x158) = 0;
  *(undefined4 *)(in_EAX + 0x15c) = 0;
  *(undefined4 *)(in_EAX + 0x160) = 0;
  *(undefined4 *)(in_EAX + 0x164) = 0;
  *(undefined4 *)(in_EAX + 0x168) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x16c) = 0;
  *(undefined4 *)(in_EAX + 0x170) = 0;
  *(undefined4 *)(in_EAX + 0x174) = 0;
  *(undefined4 *)(in_EAX + 0x178) = 0;
  *(undefined4 *)(in_EAX + 0x17c) = 0x3f800000;
  return;
}


// ==== 0x42fe60 FUN_0042fe60

void __fastcall FUN_0042fe60(undefined4 param_1,int param_2)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  
  *(undefined4 *)(in_EAX + 0x10) = 0x40a00000;
  *(undefined4 *)(in_EAX + 0x18) = 0x3dcccccd;
  fVar1 = *(float *)(param_2 + 0x14);
  iVar2 = 0;
  if (0 < *(int *)(in_EAX + 0x4c)) {
    do {
      iVar2 = iVar2 + 1;
      *(float *)(in_EAX + 0x4c + iVar2 * 8) = 22.0 / fVar1 + *(float *)(in_EAX + 0x48 + iVar2 * 8);
    } while (iVar2 < *(int *)(in_EAX + 0x4c));
  }
  iVar2 = 0;
  fVar1 = *(float *)(param_2 + 0x14);
  if (0 < *(int *)(in_EAX + 0x4c)) {
    do {
      iVar2 = iVar2 + 1;
      *(float *)(in_EAX + 0x78 + iVar2 * 8) = -6.0 / fVar1 + *(float *)(in_EAX + 0x74 + iVar2 * 8);
    } while (iVar2 < *(int *)(in_EAX + 0x4c));
  }
  return;
}


// ==== 0x42fee0 FUN_0042fee0

void FUN_0042fee0(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685563;
  local_c = ExceptionList;
  pvVar4 = *(void **)(unaff_EDI + 0x130);
  ExceptionList = &local_c;
  if (pvVar4 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_00490730();
    pvVar1 = *(void **)((int)pvVar4 + 0xc);
    if (pvVar1 != (void *)0x0) {
      eh_vector_destructor_iterator(pvVar1,0xc0,*(int *)((int)pvVar1 + -0x10),FUN_00401db0);
      _free((void *)((int)pvVar1 + -0x10));
    }
    _free(pvVar4);
    *(undefined4 *)(unaff_EDI + 0x130) = 0;
  }
  puVar2 = DAT_0073769c;
  if (param_1 == 0) {
    *(undefined4 *)(unaff_EDI + 300) = 0;
    ExceptionList = local_c;
    return;
  }
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    piVar6 = (int *)puVar2[2];
    if (param_1 == *piVar6) goto LAB_0042ff72;
  }
  piVar6 = (int *)0x0;
LAB_0042ff72:
  if (piVar6 != (int *)0x0) {
    pvVar4 = _malloc(0x34);
    local_4 = 0;
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_004904f0(piVar6);
    }
    *(undefined4 *)(unaff_EDI + 0x130) = uVar5;
  }
  FUN_0042fdf0();
  *(undefined4 *)(unaff_EDI + 0x184) = 0;
  *(undefined4 *)(unaff_EDI + 0x18c) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x104) = 0;
  *(undefined4 *)(unaff_EDI + 0x118) = 0;
  FUN_0042fe60();
  *(int *)(unaff_EDI + 300) = param_1;
  ExceptionList = local_c;
  return;
}


// ==== 0x430020 FUN_00430020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00430020(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  
  fVar1 = ((float10)param_2 - (float10)param_1) / (float10)param_3;
  if (fVar1 < (float10)_K_HALF) {
    fVar1 = fVar1 + (float10)_K_ONE;
  }
  if ((float10)_K_HALF < fVar1) {
    fVar1 = fVar1 - (float10)_K_ONE;
  }
  return fVar1;
}


// ==== 0x430060 FUN_00430060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00430060(int param_1)

{
  float local_8;
  
  if (*(int *)(param_1 + 0x130) == 0) {
    return (float10)0.0;
  }
  local_8 = (*(float *)(param_1 + 0x184) - *(float *)(param_1 + 0x188)) /
            *(float *)(*(int *)(*(int *)(param_1 + 0x130) + 4) + 0xc);
  if (local_8 < _K_HALF) {
    local_8 = local_8 + _K_ONE;
  }
  if (_K_HALF < local_8) {
    local_8 = local_8 - _K_ONE;
  }
  if (local_8 < 0.0) {
    local_8 = local_8 + _K_ONE;
  }
  return (float10)(int)(((int)*(uint *)(param_1 + 0x18c) < 0) - 1 & *(uint *)(param_1 + 0x18c)) +
         (float10)local_8;
}


// ==== 0x4300f0 FUN_004300f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004300f0(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar9;
  undefined4 extraout_EDX;
  int unaff_EBX;
  float *pfVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST1;
  int local_98;
  float local_94 [9];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  if (*(int *)(unaff_EBX + 4) != 0) {
    if ((*(int *)(unaff_EBX + 0x130) == 0) && (*(int *)(unaff_EBX + 0x128) < 5)) {
      uVar2 = *(undefined4 *)(&DAT_00700d1c + *(int *)(unaff_EBX + 0x128) * 4);
      iVar8 = FUN_0059def0();
      if (iVar8 != 0) {
        FUN_0042acb0(iVar8,0);
        fVar11 = (float10)bDistance3();
        if (fVar11 < (float10)5.0 != (fVar11 == (float10)5.0)) {
          FUN_0042fee0(uVar2);
        }
      }
    }
    local_94[5] = 9999.0;
    local_94[6] = 9999.0;
    local_94[7] = 9999.0;
    local_94[8] = 9999.0;
    local_94[1] = 0.0;
    local_94[2] = 0.0;
    local_94[3] = 0.0;
    local_94[4] = 0.0;
    if (*(int *)(unaff_EBX + 0x130) != 0) {
      local_94[0] = *(float *)(unaff_EBX + 0x184);
      FUN_0040bc10();
      D3DXVec3Transform(local_60,*(int *)(unaff_EBX + 4) + 0x60,local_50);
      iVar8 = *(int *)(*(int *)(unaff_EBX + 0x130) + 4);
      fVar11 = (float10)FUN_0059d740(*(undefined4 *)(unaff_EBX + 0x184),unaff_EBX + 0x184,0x3ba3d70a
                                    );
      *(float *)(unaff_EBX + 0x180) = (float)fVar11;
      local_98 = 0;
      do {
        FUN_0042a710(local_70);
        D3DXVec3Transform(local_70,local_70,local_50);
        fVar11 = (float10)FUN_0059d740(*(undefined4 *)(unaff_EBX + 0x184),0,0x3ba3d70a);
        local_94[local_98 + 5] = (float)fVar11;
        fVar11 = (float10)_K_ONE / (fVar11 + (float10)0.001);
        fVar1 = (float)fVar11;
        if (fVar11 <= (float10)-1.0) {
          fVar1 = -1.0;
        }
        else if (_K_ONE < fVar1) {
          fVar1 = _K_ONE;
        }
        local_98 = local_98 + 1;
        local_94[local_98] = fVar1 * fVar1;
      } while (local_98 < 4);
      if ((*(int *)(unaff_EBX + 0x128) < 5) &&
         (*(int *)(unaff_EBX + 300) == *(int *)(&DAT_00700d1c + *(int *)(unaff_EBX + 0x128) * 4))) {
        iVar9 = *(int *)(unaff_EBX + 0x18c);
        if (iVar9 == -1) {
          *(undefined4 *)(unaff_EBX + 0x188) = *(undefined4 *)(unaff_EBX + 0x184);
          *(undefined4 *)(unaff_EBX + 0x18c) = 0;
        }
        else {
          FUN_00430020(local_94[0],*(undefined4 *)(unaff_EBX + 0x188),*(undefined4 *)(iVar8 + 0xc));
          fVar11 = (float10)FUN_00430020(*(undefined4 *)(unaff_EBX + 0x188),
                                         *(undefined4 *)(unaff_EBX + 0x184),extraout_ECX);
          fVar12 = (float10)FUN_00430020(extraout_EDX,*(undefined4 *)(unaff_EBX + 0x184),
                                         extraout_ECX_00);
          if (((fVar12 <= (float10)0.0) || (extraout_ST1 <= (float10)0.0)) || ((float)fVar11 < 0.0))
          {
            if (((fVar12 < (float10)0.0) &&
                (extraout_ST1 < (float10)0.0 != (extraout_ST1 == (float10)0.0))) &&
               ((float)fVar11 < 0.0)) {
              *(int *)(unaff_EBX + 0x18c) = iVar9 + -1;
            }
          }
          else {
            *(int *)(unaff_EBX + 0x18c) = iVar9 + 1;
          }
        }
        fVar11 = (float10)FUN_00430060();
        if ((float10)_K_ONE <= fVar11) {
          *(undefined4 *)(unaff_EBX + 0x104) = 0;
          *(float *)(unaff_EBX + 0x11c) =
               *(float *)(unaff_EBX + 0x11c) + *(float *)(unaff_EBX + 0x118);
          *(undefined4 *)(unaff_EBX + 0x118) = 0;
          FUN_0042fee0(0);
          *(int *)(unaff_EBX + 0x128) = (*(int *)(unaff_EBX + 0x128) + 1) % 5;
        }
      }
    }
    iVar8 = *(int *)(unaff_EBX + 4);
    fVar1 = local_94[1] * 10.0;
    fVar5 = local_94[2] * 10.0;
    fVar4 = local_94[3] * 10.0;
    fVar3 = local_94[4] * 10.0;
    if (1.0 <= *(float *)(iVar8 + 0x3d0)) {
      sVar7 = Atan2ToAngle16(*(undefined4 *)(iVar8 + 0x70),*(undefined4 *)(iVar8 + 0x74));
      local_94[0] = (float)(uint)(ushort)(*(short *)(iVar8 + 0x3b4) - sVar7);
      fVar6 = (float)(int)local_94[0] * 9.58738e-05;
      if (3.14159 < fVar6) {
        fVar6 = fVar6 - 6.28318;
      }
    }
    else {
      fVar6 = 0.0;
    }
    *(float *)(unaff_EBX + 0x10c) =
         *(float *)(*(int *)(unaff_EBX + 4) + 0x3d4) * 0.4 * ABS(fVar6) * 2.4 *
         (fVar3 + fVar4 + fVar5 + fVar1) * DAT_0073457c + 0.0;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x108) + 0x24) = 0x40333333;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x108) + 0x28) = 0x3f800000;
    fVar1 = *(float *)(unaff_EBX + 0x10c);
    pfVar10 = *(float **)(unaff_EBX + 0x108);
    pfVar10[2] = fVar1;
    if (fVar1 != *pfVar10) {
      *(undefined2 *)(pfVar10 + 0xb) = 2;
    }
    iVar8 = 0;
    FUN_00593d40(DAT_0073457c,0,0);
    fVar1 = **(float **)(unaff_EBX + 0x108);
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    *(float *)(unaff_EBX + 0x110) = fVar1;
    if (fVar1 < 2.5) {
      *(undefined4 *)(unaff_EBX + 0x114) = 0;
    }
    else if ((*(int *)(unaff_EBX + 0x114) == 0) || (*(int *)(unaff_EBX + 0x114) == 0x7fffffff)) {
      *(undefined4 *)(unaff_EBX + 0x114) = DAT_0073ad34;
    }
    if (*(int *)(unaff_EBX + 0x130) != 0) {
      fVar1 = 0.0;
      if (0.1 < *(float *)(*(int *)(unaff_EBX + 4) + 0x3d4)) {
        iVar9 = 0;
        pfVar10 = (float *)(*(int *)(unaff_EBX + 4) + 0x3a4);
        do {
          if (ABS(local_94[iVar9 + 5]) < _K_HALF * 5.0 !=
              (ABS(local_94[iVar9 + 5]) == _K_HALF * 5.0)) {
            *(undefined1 *)((int)local_94 + iVar9) = 1;
            fVar1 = fVar1 + *pfVar10;
            iVar8 = iVar8 + 1;
          }
          iVar9 = iVar9 + 1;
          pfVar10 = pfVar10 + 1;
        } while (iVar9 < 4);
        if (0 < iVar8) {
          fVar1 = fVar1 * 15.0 * DAT_0073457c + *(float *)(unaff_EBX + 0x104);
          *(float *)(unaff_EBX + 0x104) = fVar1;
          *(float *)(unaff_EBX + 0x118) =
               fVar1 * *(float *)(unaff_EBX + 0x110) * 1.0 * DAT_0073457c +
               *(float *)(unaff_EBX + 0x118);
        }
      }
      fVar1 = *(float *)(unaff_EBX + 0x118);
      if (*(float *)(unaff_EBX + 0x118) < *(float *)(unaff_EBX + 0x120)) {
        fVar1 = *(float *)(unaff_EBX + 0x120);
      }
      *(float *)(unaff_EBX + 0x120) = fVar1;
    }
  }
  return;
}


// ==== 0x430650 FUN_00430650

float10 __fastcall FUN_00430650(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)-1.0;
  if ((((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) && (*(int *)(param_1 + 0x114) != 0)) &&
     (*(int *)(param_1 + 0x114) != 0x7fffffff)) {
    fVar1 = (float10)DAT_00700b64 -
            (float10)(DAT_0073ad34 - *(int *)(param_1 + 0x114)) * (float10)0.00025;
    if (fVar1 <= (float10)0.0) {
      fVar1 = (float10)0.0;
    }
  }
  return fVar1;
}


// ==== 0x4306c0 FUN_004306c0

undefined4 __fastcall FUN_004306c0(int param_1)

{
  if (*(char *)(param_1 + 0x124) != '\0') {
    return 1;
  }
  if ((DAT_0078a346 == '\0') && (DAT_007361a0 == 0)) {
    return 0;
  }
  if (((*(int *)(param_1 + 0x114) != 0) && (*(int *)(param_1 + 0x114) != 0x7fffffff)) &&
     (DAT_00700b64 <= (float)(DAT_0073ad34 - *(int *)(param_1 + 0x114)) * 0.00025)) {
    return 1;
  }
  return 0;
}


// ==== 0x430730 Player::StartRaceCameras

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (C) docs/re/camera.md */

void Player__StartRaceCameras(void)

{
  float fVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float fStack_8;
  
  iVar3 = Player__WrongWayAndZoneTest(in_EAX,*(undefined1 *)(in_EAX + 0x4ac));
  *(bool *)(in_EAX + 0x4ac) = iVar3 != 0;
  FUN_004312a0();
  iVar3 = *DAT_007361f0;
  if ((((iVar3 == 4) || (iVar3 == 5)) || (iVar3 == 6)) || (iVar3 == 10)) {
    iVar3 = _ftol_nocw();
    *(int *)(in_EAX + 0xac) = *(int *)(in_EAX + 0xac) - iVar3;
    if ((float)*(int *)(in_EAX + 0xac) * 0.00025 < 0.0) {
      iVar3 = (**(code **)(**(int **)(*(int *)(in_EAX + 4) + 0x2c) + 0x14))(1);
      if (iVar3 != 0) {
        iVar4 = *(int *)(*(int *)(in_EAX + 4) + 0x10);
        if (*(char *)(iVar4 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        iVar7 = (int)*(char *)(iVar4 + 0x424);
        iVar4 = (**(code **)(**(int **)(*(int *)(in_EAX + 4) + 0x2c) + 0x18))(1);
        fStack_8 = 1.0;
        if ((iVar4 != 0) &&
           ((iVar6 = iVar7 * 0x34, *(char *)(iVar6 + 0x34 + iVar3) != '\0' ||
            (*(char *)(iVar6 + iVar3 + 0x35) != '\0')))) {
          fStack_8 = (float)((uint)*(byte *)(iVar4 + 0x6a + iVar7) << 0x10) * 1.5258789e-05;
          if (fStack_8 <= 0.0) {
            fStack_8 = 0.0;
            if (0.01 <= *(float *)(*(int *)(in_EAX + 4) + 0x3d4)) {
              fStack_8 = 1.0;
            }
          }
          else {
            fStack_8 = *(float *)(*(int *)(in_EAX + 4) + 0x3d4) / fStack_8;
          }
        }
        FUN_00584270(fStack_8);
        fVar1 = *(float *)(*(int *)(in_EAX + 0xa8) + 0xc);
        if (fVar1 < *(float *)(in_EAX + 0xb0)) {
          fVar1 = *(float *)(in_EAX + 0xb0);
        }
        *(float *)(in_EAX + 0xb0) = fVar1;
      }
      uVar5 = _ftol_nocw();
      *(undefined4 *)(in_EAX + 0xac) = uVar5;
    }
  }
  if (0.0 < *(float *)(in_EAX + 0xa4)) {
    fVar1 = *(float *)(in_EAX + 0xa4) - DAT_0073457c;
    *(float *)(in_EAX + 0xa4) = fVar1;
    if (((fVar1 < 0.0 != (fVar1 == 0.0)) &&
        (*(undefined4 *)(in_EAX + 0xa4) = 0, DAT_0078a345 == '\0')) &&
       ((DAT_007361a4 == 0 &&
        (((DAT_0078a346 == '\0' && (DAT_007361a0 == 0)) && (*DAT_007361f0 != 9)))))) {
      iVar3 = SpecialCamCooldown();
      if (((iVar3 == 0) || (5.0 <= (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x74)) * 0.00025)) &&
         ((*DAT_0073619c == 4 && ((DAT_007361c4 != 2 && (DAT_0078a3fb != '\0')))))) {
        if (SpecialCamTable3[*(int *)(in_EAX + 0x60)] != (code)0x0) {
          Player__EndSpecialCamera(0);
        }
        iVar3 = 0;
        if (0 < DAT_007361c4) {
          do {
            if (SpecialCamModeTable__flags__0_0_0_1_1_1_1_1___5_readers__recheck__0x42da40_refuses_a_new_special_camera_when_a_player_s_byte_is_non_zero__so__busy__not__enable___I_
                [*(int *)((&DAT_007361bc)[iVar3] + 0x60)] != (code)0x0) goto LAB_00430a7a;
            iVar3 = iVar3 + 1;
          } while (iVar3 < DAT_007361c4);
        }
        *(undefined4 *)(in_EAX + 0xa0) = DAT_0073ad3c;
        *(int *)(in_EAX + 0x74) = DAT_0073ad34;
        iVar3 = FUN_0041f6a0();
        if (iVar3 == 0) {
          Player__ChangeCameraMover(in_EAX,0xd,1);
          iVar3 = DAT_007361f8;
          _gSpecialCameraActive = 1;
          fVar1 = 3.0 - DAT_0073457c;
          *(code **)(DAT_007361f8 + 0x2e8) = FUN_0042da30;
          *(int *)(iVar3 + 0x2ec) = in_EAX;
          *(float *)(iVar3 + 0x2d4) = fVar1;
          *(undefined1 *)(in_EAX + 0x270) = 1;
          *(undefined4 *)(in_EAX + 0x60) = 1;
          *(undefined1 *)(in_EAX + 0x98) = 1;
          *(undefined4 *)(in_EAX + 0x9c) = 0;
        }
      }
    }
  }
LAB_00430a7a:
  if ((((*(int *)(in_EAX + 4) == 0) || (*(int *)(in_EAX + 4) == -0x40)) ||
      (cVar2 = FUN_00465430(), cVar2 == '\0')) && (*(char *)(in_EAX + 0x270) != '\0')) {
    _gSpecialCameraActive = 0;
    *(undefined1 *)(in_EAX + 0x270) = 0;
  }
  if (((*(int *)(in_EAX + 0x278) == 4) && (*(int *)(in_EAX + 0x27c) != 0)) &&
     (*(int *)(*(int *)(in_EAX + 0x27c) + 0xc) == 0x12)) {
    FUN_0042f0c0(DAT_0073457c);
  }
  if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
     (((DAT_0078a2f0 != 1099 || ((DAT_00735fb0 == 0 || (DAT_00735fb8 != 4)))) && (DAT_007796a8 < 1))
     )) {
    *(undefined1 *)(in_EAX + 0x4af) = 0;
  }
  else {
    FUN_0042fc00();
  }
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    FUN_0042f650();
  }
  FUN_0043f240(DAT_0073457c);
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    FUN_0043e310(DAT_0073457c);
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    FUN_004300f0();
  }
  FUN_00436940(in_EAX + 0x960,in_EAX,DAT_0073457c);
  return;
}


// ==== 0x430b90 Player::UpdateFrame

/* [canon] hud low (ghidra) docs/re/hud_input.md */

void Player__UpdateFrame(void)

{
  void *_Memory;
  int in_EAX;
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  piVar2 = DAT_007361f0;
  iVar1 = *DAT_007361f0;
  if ((((iVar1 == 4) || (iVar1 == 0)) || (iVar1 == 2)) || (iVar1 == 3)) {
    if (((&DAT_007306c4)[*(int *)(in_EAX + 8)] == 0xff) ||
       ((uint)(byte)(&DAT_007306c4)[*(int *)(in_EAX + 8)] != *(uint *)(in_EAX + 0xc))) {
      if (DAT_007361c8 == 0) {
        if (((iVar1 == 0) || (iVar1 == 2)) || (iVar1 == 3)) {
          FUN_00421c00(DAT_007361f0,4,0);
        }
        FUN_00421c00(DAT_007361f0,5,*(undefined4 *)(in_EAX + 8));
      }
      DAT_007361c8 = DAT_007361c8 + 1;
      piVar2 = DAT_007361f0;
    }
  }
  else {
    *(uint *)(in_EAX + 0xc) = (uint)(byte)(&DAT_007306c4)[*(int *)(in_EAX + 8)];
  }
  if (*piVar2 != 4) goto LAB_00430dbc;
  _Memory = *(void **)(in_EAX + 0x298);
  if ((_Memory != (void *)0x0) &&
     (*(float *)((int)_Memory + 4) < (float)(DAT_0073ad34 - *(int *)((int)_Memory + 8)) * 0.00025))
  {
    FUN_0042b040(_Memory);
    _free(_Memory);
    piVar2 = DAT_007361f0;
    *(undefined4 *)(in_EAX + 0x298) = 0;
  }
  if (*piVar2 != 4) goto LAB_00430dbc;
  iVar1 = DAT_007361b4;
  if (DAT_007361b4 == in_EAX) {
    iVar1 = DAT_007361b8;
  }
  if (((((*(int *)(in_EAX + 0x27c) == 0) && (*(int *)(in_EAX + 0x288) == 0)) &&
       (*(int *)(in_EAX + 0x28c) == 0)) &&
      ((*(int *)(in_EAX + 0x290) == 0 && (*(int *)(in_EAX + 0x294) == 0)))) &&
     (*(int *)(*(int *)(in_EAX + 0x2a8) + 0x44) == 0)) {
    if (*DAT_0073619c == 3) {
      if (DAT_0078a368 == 0) {
        FUN_0042c3e0();
        piVar2 = DAT_007361f0;
      }
      else {
LAB_00430ce2:
        if (((iVar1 == 0) || (*(int *)(iVar1 + 0x2a8) == 0)) ||
           (*(int *)(*(int *)(iVar1 + 0x2a8) + 0x44) == 0)) goto LAB_00430cf7;
      }
    }
    else {
      if (DAT_0078a368 != 0) goto LAB_00430ce2;
LAB_00430cf7:
      Player__DefaultDriveCamera(0);
      piVar2 = DAT_007361f0;
    }
  }
  if ((((*(int *)(in_EAX + 0x290) != 0) && (*(int *)(*(int *)(in_EAX + 0x290) + 0xc) == 0)) &&
      ((iVar1 = piVar2[0xf], iVar1 == 0 ||
       ((*(int *)(iVar1 + 0x20) == 0 || (*(int *)(iVar1 + 0x1c) == 0)))))) &&
     ((piVar2[0x10] == 0 || (*(int *)(piVar2[0x10] + 0x1c) == 0)))) {
    Player__ChangeCameraMover(in_EAX,(-(DAT_00700aa4 != 0) & 0x10U) + 1,0);
  }
  if (DAT_00700aa4 != 0) {
    if ((*(int *)(in_EAX + 0x27c) != 0) && (*(int *)(*(int *)(in_EAX + 0x27c) + 0xc) == 1)) {
      Player__ChangeCameraMover(in_EAX,0x11,0);
      (**(code **)(**(int **)(in_EAX + 0x27c) + 0x14))(*(undefined1 *)(in_EAX + 0x4ad));
    }
    if (DAT_00700aa4 != 0) goto LAB_00430dbc;
  }
  if ((*(int *)(in_EAX + 0x27c) != 0) && (*(int *)(*(int *)(in_EAX + 0x27c) + 0xc) == 0x11)) {
    Player__ChangeCameraMover(in_EAX,1,0);
    (**(code **)(**(int **)(in_EAX + 0x27c) + 0x14))(*(undefined1 *)(in_EAX + 0x4ad));
  }
LAB_00430dbc:
  uVar3 = Player__ComputeHudFlags(in_EAX);
  if (((int)uVar3 != *(int *)(in_EAX + 0x4b0)) ||
     ((int)((ulonglong)uVar3 >> 0x20) != *(int *)(in_EAX + 0x4b4))) {
    Player__SetHudFlags(uVar3);
  }
  if (*(int *)(in_EAX + 0x95c) != 0) {
    HudManager__Update(*(int *)(in_EAX + 0x95c),in_EAX,*(undefined4 *)(in_EAX + 4));
  }
  return;
}


// ==== 0x430e00 Player::WrongWayAndZoneTest

/* [canon] track high (hopper+ghidra) docs/re/track.md */

undefined4 Player__WrongWayAndZoneTest(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  ushort uVar8;
  
  iVar2 = param_1;
  iVar7 = *(int *)(param_1 + 4);
  sVar5 = *(short *)(iVar7 + 0x3b4);
  sVar4 = Atan2ToAngle16(*(undefined4 *)(iVar7 + 0x818),*(undefined4 *)(iVar7 + 0x81c));
  *(undefined4 *)(param_1 + 0x100) = 0;
  uVar1 = DAT_0078a2fc;
  piVar6 = (int *)Zone_Find(DAT_0078a2fc);
  if ((((piVar6 != (int *)0x0) || (piVar6 = (int *)Zone_Find(uVar1), piVar6 != (int *)0x0)) ||
      (piVar6 = (int *)Zone_Find(uVar1), piVar6 != (int *)0x0)) ||
     (piVar6 = (int *)Zone_Find(uVar1), piVar6 != (int *)0x0)) {
    iVar7 = *piVar6;
    if (iVar7 == 0) {
      return 0;
    }
    if (iVar7 == 1) {
      sVar4 = Atan2ToAngle16(piVar6[3],piVar6[4]);
      *(undefined4 *)(param_1 + 0x100) = 1;
    }
    else if (((iVar7 == 2) || (iVar7 == 3)) && (cVar3 = Car__ApplyResetZone(), cVar3 != '\0')) {
      return 0;
    }
  }
  param_1._0_2_ = sVar4;
  uVar8 = (short)param_1 - sVar5;
  if (0x8000 < uVar8) {
    uVar8 = -uVar8;
  }
  if (param_2 != 0) {
    iVar7 = _ftol_nocw();
    uVar8 = uVar8 + (short)(iVar7 / 0x168);
  }
  iVar7 = _ftol_nocw();
  if (uVar8 < (ushort)((short)((ulonglong)((longlong)iVar7 * 0xb60b60b7) >> 0x28) -
                      ((short)(char)((char)(iVar7 / 0x1680000) + (char)(iVar7 >> 0x1f)) >> 0xf))) {
    return 0;
  }
  iVar7 = *(int *)(iVar2 + 4);
  if (ABS(*(float *)(iVar7 + 0x3d0) * 2.237) <= 10.0) {
    if (param_2 == 0) {
      return 0;
    }
  }
  else {
    sVar5 = Atan2ToAngle16(*(undefined4 *)(iVar7 + 0x70),*(undefined4 *)(iVar7 + 0x74));
    uVar8 = (short)param_1 - sVar5;
    if (0x8000 < uVar8) {
      uVar8 = -uVar8;
    }
    if (param_2 != 0) {
      iVar7 = _ftol_nocw();
      uVar8 = uVar8 + (short)(iVar7 / 0x168);
    }
    iVar7 = _ftol_nocw();
    if (uVar8 < (ushort)((short)((ulonglong)((longlong)iVar7 * 0xb60b60b7) >> 0x28) -
                        ((short)(char)((char)(iVar7 / 0x1680000) + (char)(iVar7 >> 0x1f)) >> 0xf)))
    {
      return 0;
    }
    if ((param_2 == 0) && (*(int *)(*(int *)(iVar2 + 4) + 0x3cc) < 4)) {
      return 0;
    }
  }
  return 1;
}


