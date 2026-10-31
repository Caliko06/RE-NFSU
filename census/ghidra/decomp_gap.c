// Ghidra decompilation of 1241 functions that neither census/hopper/decomp.c nor the range exports had.
// Produced on the pod 2026-10-30 with tools/ghidra/DecompAt.java (creates the function when the analysis missed it)
// against the named project /root/ghidra_named. Pod recipe: /root/re/fill.sh. Same format as the range exports.

// 00401c79 FUN_00401c79

float10 __thiscall FUN_00401c79(float param_1,float param_2)

{
  float10 fVar1;
  float unaff_retaddr;
  
  func_0x00401e23();
  if (unaff_retaddr < param_1) {
    unaff_retaddr = param_1;
  }
  fVar1 = (float10)unaff_retaddr;
  if ((float10)param_2 < fVar1) {
    fVar1 = (float10)param_2;
  }
  return fVar1;
}


// 00410740 FUN_00410740

void __fastcall FUN_00410740(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = DAT_007363d4;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_0040ed10();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// 00414441 FUN_00414441

void FUN_00414441(void)

{
  undefined4 unaff_EBP;
  bool in_ZF;
  
  if (!in_ZF) {
    FUN_004145c0(unaff_EBP);
    FUN_004f66f0();
    FEObject__SetScript("FadeIn",1);
    return;
  }
  return;
}


// 00414f60 FUN_00414f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00414f60(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_2 < 0xb5971bf2) {
    if ((param_2 != 0xb5971bf1) && (param_2 != 0xc407210)) {
      if (param_2 == 0x911ab364) {
        DAT_00700e70 = *(undefined4 *)(param_1 + 0x7c);
        _DAT_00736394 = _ftol_nocw();
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x9120409e) {
        return;
      }
    }
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0xcbbd95e3) {
      if (uVar1 == 0xcbbd95e2) {
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_24 = 0xf581cb6d;
        uStack_1c = 0xe5707304;
        uStack_20 = 0x639;
        uStack_14 = 0x33120188;
        uStack_18 = 0x541389e5;
        uStack_10 = 1;
        uStack_c = 0xb8a7c6cc;
        FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (uVar1 == 0x823ce9ac) {
        FUN_00415120();
        return;
      }
      if ((uVar1 == 0xa936c3a2) && (param_2 == 0xc407210)) {
        FUN_004f63e0(0xff);
        return;
      }
    }
    else if (uVar1 == 0xf81c7981) {
      FUN_00415ba0();
      _ftol_nocw();
      GraphicsQuality_Set();
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
      FEManager__PushPackageChecked(0x32,0);
    }
    FUN_00415300(param_1);
  }
  else if (param_2 == 0xe5707304) {
    FUN_00410a00();
    FUN_00414f00();
    return;
  }
  return;
}


// 00415001 FUN_00415001

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415001(void)

{
  undefined4 in_EAX;
  
  _DAT_00736394 = in_EAX;
  FUN_004f6360();
  return;
}


// 00416c90 FUN_00416c90

void * __thiscall FUN_00416c90(void *param_1,byte param_2)

{
  FUN_00416c30(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00417373 FUN_00417373

void FUN_00417373(void)

{
  FUN_004171a0();
  return;
}


// 00420020 FUN_00420020

bool __fastcall FUN_00420020(int param_1,int param_2)

{
  undefined4 in_EAX;
  
  if ((POPCOUNT((byte)((uint)in_EAX >> 8) & 5) & 1U) != 0) {
    return true;
  }
  if (*(float *)(param_2 + 0x60) < *(float *)(param_1 + 0x60)) {
    return false;
  }
  return *(short *)(param_2 + 10) <= *(short *)(param_1 + 10);
}


// 00420031 FUN_00420031

bool __fastcall FUN_00420031(int param_1,int param_2)

{
  ushort in_FPUStatusWord;
  
  if ((in_FPUStatusWord & 0x4100) == 0) {
    return false;
  }
  return *(short *)(param_2 + 10) <= *(short *)(param_1 + 10);
}


// 00420041 FUN_00420041

bool __fastcall FUN_00420041(undefined4 param_1,int param_2)

{
  short in_AX;
  
  return *(short *)(param_2 + 10) <= in_AX;
}


// 00422c80 FUN_00422c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if (DAT_006f1df8 < (float)*(int *)(DAT_0073619c + 0x14) * _DAT_006cca38) {
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


// 00422d70 FUN_00422d70

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


// 004237a0 FUN_004237a0

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


// 00423870 FUN_00423870

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


// 004239c0 FUN_004239c0

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


// 00425270 FUN_00425270

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


// 0042d9a0 FUN_0042d9a0

void FUN_0042d9a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if ((param_2 == 0xab) && (*(int *)(param_4 + 0x58) == 0)) {
    FUN_00421c00(DAT_007361f0,5,param_1);
  }
  return;
}


// 0042d9d0 FUN_0042d9d0

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


// 0043db80 FUN_0043db80

int __fastcall FUN_0043db80(int param_1)

{
  FUN_00556750();
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined1 **)(param_1 + 0x18) = &DAT_006b9172;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 3;
  return param_1;
}


// 0044ac60 FUN_0044ac60

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


// 0044acb0 FUN_0044acb0

float10 __fastcall FUN_0044acb0(int param_1)

{
  float *pfVar1;
  float10 fVar2;
  
  if (**(int **)(param_1 + 0x3d8) == 0) {
    return (float10)DAT_006cc7a4;
  }
  pfVar1 = (float *)(*(int **)(param_1 + 0x3d8))[1];
  fVar2 = ((float10)*(float *)(*(int *)(param_1 + 4) + 0x60) - (float10)*pfVar1) *
          (float10)pfVar1[4] -
          ((float10)*(float *)(*(int *)(param_1 + 4) + 100) - (float10)pfVar1[1]) *
          (float10)pfVar1[3];
  if ((float10)DAT_006cc7a4 < fVar2) {
    return fVar2 - (float10)pfVar1[10];
  }
  return -(fVar2 + (float10)pfVar1[9]);
}


// 0044c8f0 FUN_0044c8f0

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


// 0044fd40 FUN_0044fd40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044fd40(void)

{
  int iVar1;
  bool bVar2;
  float fVar3;
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
  if ((cVar5 == '\0') && (iVar1 = *(int *)(unaff_EDI + 0x34), iVar1 != unaff_ESI)) {
    *unaff_EBP = 3;
    unaff_EBP[1] = iVar1;
    *(undefined1 *)(unaff_EBP + 3) = 0;
    unaff_EBP[2] = unaff_ESI;
  }
  uVar4 = DAT_007006ec;
  *(undefined1 *)(in_stack_00000014 + 0x218) = 0;
  uVar6 = FUN_0045b150(unaff_EBP,in_stack_00000014 + 0x20,unaff_EBX,uVar4,
                       (undefined1 *)(in_stack_00000014 + 0x218),1);
  *(undefined1 *)(in_stack_00000014 + 0x208) = uVar6;
  *(undefined4 *)(in_stack_00000014 + 0x20c) = DAT_0073ad34;
  if ((*(char *)(in_stack_00000014 + 0x208) != '\0') ||
     (_DAT_006b7610 < *(float *)(*unaff_EBX + 0x3d4))) {
    iVar1 = *unaff_EBP;
    iVar7 = unaff_ESI;
    if ((iVar1 != 1) && ((iVar7 = in_stack_0000001c, 1 < iVar1 && (iVar1 < 4)))) {
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
    if (in_stack_00000030 <= DAT_006cc7a4) goto LAB_00450049;
LAB_004500b5:
    bVar2 = true;
  }
  else {
    if (*(float *)(in_stack_00000020 + 0xc) * _DAT_006cc7dc <
        _DAT_006b7614 * *(float *)(in_stack_00000018 + 4) + in_stack_00000030) goto LAB_004500b5;
LAB_00450049:
    bVar2 = false;
  }
  if ((*(float *)(in_stack_00000018 + 8) + *(float *)(in_stack_00000020 + 8) + _DAT_006cc7bc <=
       ABS(in_stack_0000002c)) || (!bVar2)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
  }
  else {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
  }
  cVar5 = FUN_0057a720();
  if ((cVar5 != '\0') || (cVar5 = FUN_0057a760(), cVar5 != '\0')) {
    fVar3 = *(float *)(in_stack_00000014 + 0x1e4);
    if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
      fVar3 = _DAT_006b7610;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar3;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
LAB_00450123:
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 00450036 FUN_00450036

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450036(void)

{
  bool bVar1;
  float fVar2;
  char cVar3;
  int unaff_EBP;
  bool in_ZF;
  int in_stack_00000014;
  int in_stack_00000020;
  float in_stack_0000002c;
  float in_stack_00000030;
  char in_stack_00000038;
  
  if (in_ZF) {
    if (DAT_006cc7a4 < in_stack_00000030) {
LAB_004500b5:
      bVar1 = true;
      goto LAB_0045004b;
    }
  }
  else if (*(float *)(in_stack_00000020 + 0xc) * _DAT_006cc7dc <
           _DAT_006b7614 * *(float *)(unaff_EBP + 4) + in_stack_00000030) goto LAB_004500b5;
  bVar1 = false;
LAB_0045004b:
  if ((ABS(in_stack_0000002c) <
       *(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _DAT_006cc7bc) && (bVar1)) {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
    if (in_stack_00000038 == '\0') {
      FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
    fVar2 = *(float *)(in_stack_00000014 + 0x1e4);
    if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
      fVar2 = _DAT_006b7610;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar2;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 00450038 FUN_00450038

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
  
  if ((*(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _DAT_006cc7bc <=
       ABS(in_stack_0000002c)) || (in_stack_00000030 <= DAT_006cc7a4)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
  if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
    fVar1 = _DAT_006b7610;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 00450044 FUN_00450044

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
  
  if ((*(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _DAT_006cc7bc <=
       ABS(in_stack_0000002c)) || ((in_EAX & 0x4100) != 0)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
  if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
    fVar1 = _DAT_006b7610;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 00450053 FUN_00450053

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
       (float10)*(float *)(unaff_EBP + 8) + (float10)*(float *)(in_EAX + 8) + (float10)_DAT_006cc7bc
      ) && (param_1 != '\0')) {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
    if (in_stack_00000038 == '\0') {
      FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
    if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
      fVar1 = _DAT_006b7610;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 00450065 FUN_00450065

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
      FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
    if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
      fVar1 = _DAT_006b7610;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 0045006e FUN_0045006e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    FUN_0044e850(in_stack_00000014,DAT_006b7618,DAT_006b761c);
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
  if (*(float *)(in_stack_00000014 + 0x1e4) <= _DAT_006b7610) {
    fVar1 = _DAT_006b7610;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// 004500ed FUN_004500ed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004500ed(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x1e4);
  if (*(float *)(param_1 + 0x1e4) <= _DAT_006b7610) {
    fVar1 = _DAT_006b7610;
  }
  *(float *)(param_1 + 0x1e4) = fVar1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// 00450100 FUN_00450100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00450100(int param_1)

{
  *(undefined4 *)(param_1 + 0x1e4) = _DAT_006b7610;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// 00450d00 FUN_00450d00

void FUN_00450d00(void)

{
  int unaff_EBP;
  undefined4 uStack00000038;
  
  uStack00000038 = 0x47c34f80;
  FUN_0045b050();
  *(undefined1 *)(unaff_EBP + 0x1f0) = 1;
  return;
}


// 004512f0 FUN_004512f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004512f0(undefined4 param_1)

{
  float fVar1;
  int in_EAX;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar2;
  undefined4 uStack00000018;
  int *in_stack_0000002c;
  
  if (in_EAX < 0x11) {
    uStack00000018 = *(undefined4 *)(unaff_EBX + -0x14 + in_EAX * 4);
  }
  else {
    uStack00000018 = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x398) = 1;
  *(undefined4 *)(unaff_ESI + 0x39c) = param_1;
  *(undefined1 *)(unaff_ESI + 0x3a4) = 0;
  *(undefined4 *)(unaff_ESI + 0x3a0) = param_1;
  FUN_00458f10(param_1,param_1);
  fVar1 = *(float *)(unaff_EBX + 0x10) -
          *(float *)(*(char *)(unaff_ESI + 0x388) * 0x38 + 0x18 + unaff_ESI);
  if ((_DAT_006b764c <= fVar1) && (_DAT_006cc8bc < ABS(*(float *)(unaff_EBX + 4)))) {
    LinearTable__Lookup11(&PTR_DAT_007061f4,fVar1 / *(float *)(unaff_EBX + 4));
  }
  FUN_0045c370(unaff_EDI + 0x20);
  fVar2 = (float10)(**(code **)(*in_stack_0000002c + 0x5c))();
  *(float *)(unaff_EDI + 0x1e4) = (float)fVar2;
  *(undefined1 *)(unaff_EDI + 0x1f0) = 1;
  *(undefined4 *)(unaff_EDI + 0x1e8) = 0;
  *(undefined4 *)(unaff_EDI + 0x1ec) = 0x40000000;
  *(undefined1 *)(unaff_EDI + 0x1f1) = 1;
  *(undefined1 *)(unaff_EDI + 0x1f2) = 1;
  *(undefined1 *)(unaff_EDI + 0x1e0) = 1;
  return;
}


// 00453a60 FUN_00453a60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __thiscall FUN_00453a60(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  float fStack_4;
  
  iVar4 = 0;
  fStack_4 = 0.0;
  if (0 < *(int *)(param_2 + 4)) {
    piVar5 = (int *)(param_2 + 0x3c);
    do {
      if (*piVar5 == *(int *)(param_1 + 0x200)) {
        if (iVar4 == -1) {
          return '\x01';
        }
        iVar4 = iVar4 * 0x38 + 8 + param_2;
        if (iVar4 == 0) {
          return '\x01';
        }
        iVar1 = *(char *)(param_2 + 0x388) * 0x38 + param_2;
        if ((DAT_006cc7a4 <= *(float *)(iVar4 + 0x10) - *(float *)(iVar1 + 0x18)) &&
           (*(float *)(iVar4 + 4) <= _DAT_006cc954)) {
          return '\0';
        }
        iVar4 = *(int *)(param_2 + 0x394);
        if ((iVar4 < 0) || (4 < iVar4)) {
          if ((iVar4 < 0xb) || (0x10 < iVar4)) {
            param_2 = 0;
          }
          else {
            param_2 = *(undefined4 *)(iVar1 + -0xc + iVar4 * 4);
          }
        }
        else {
          param_2 = *(undefined4 *)(iVar1 + 0x1c);
        }
        iVar4 = FUN_0044f470(iVar4,param_2,*(undefined4 *)(param_1 + 0x208),&fStack_4,&param_2);
        if (iVar4 == 0) {
          return '\x01';
        }
        if (fStack_4 < _DAT_006b76d8 == (fStack_4 == _DAT_006b76d8)) {
          return '\x01';
        }
        cVar3 = TrafficCar_IsIntersectionObstacle(iVar4);
        uVar2 = DAT_006b76e0;
        cVar3 = '\x01' - (cVar3 != '\0');
        if ((cVar3 == '\0') && (*(int *)(param_1 + 0x200) != iVar4)) {
          *(int *)(param_1 + 0x200) = iVar4;
          *(undefined4 *)(param_1 + 0x208) = uVar2;
          *(float *)(param_1 + 0x204) = fStack_4;
          return '\0';
        }
        return cVar3;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0xe;
    } while (iVar4 < *(int *)(param_2 + 4));
  }
  return '\x01';
}


// 00453b80 FUN_00453b80

void __fastcall FUN_00453b80(undefined4 param_1,undefined4 param_2)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + 0x208) = param_2;
  *(undefined4 *)(unaff_EBP + 0x204) = param_1;
  return;
}


// 00454200 FUN_00454200

void FUN_00454200(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// 0045444f FUN_0045444f

undefined1 __fastcall FUN_0045444f(undefined4 param_1,char *param_2)

{
  char *in_EAX;
  undefined4 uVar1;
  undefined1 unaff_BL;
  int unaff_ESI;
  undefined1 in_stack_00000010;
  
  *param_2 = *param_2 + (char)in_EAX;
  *in_EAX = *in_EAX + (char)in_EAX;
  if (*in_EAX != '\0') {
    *(undefined1 *)(unaff_ESI + 0x204) = unaff_BL;
    *(char **)(unaff_ESI + 0x200) = in_EAX;
    uVar1 = FUN_00454330();
    *(undefined4 *)(unaff_ESI + 0x208) = uVar1;
    return in_stack_00000010;
  }
  return unaff_BL;
}


// 00454910 FUN_00454910

void FUN_00454910(int *param_1)

{
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// 004549d0 FUN_004549d0

undefined4 FUN_004549d0(void)

{
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    return 0;
  }
  return 1;
}


// 004549f0 FUN_004549f0

void __fastcall FUN_004549f0(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x14))();
  if (cVar1 != '\0') {
    FUN_0044f0d0();
    return;
  }
  FUN_0044f070();
  return;
}


// 00454c59 FUN_00454c59

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00454c59(int param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  undefined3 uVar4;
  
  fVar2 = (float)in_EAX * _DAT_006cca38;
  fVar1 = *(float *)(param_1 + 0xc);
  uVar3 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe);
  if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
    uVar4 = (undefined3)(uVar3 >> 8);
    uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 4));
    if (*(char *)(param_1 + 4) != '\0') {
      return CONCAT31(uVar4,1);
    }
  }
  return uVar3 & 0xffffff00;
}


// 00454d55 FUN_00454d55

void FUN_00454d55(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  float *extraout_EDX;
  int unaff_EBX;
  int unaff_EBP;
  float10 fVar3;
  undefined1 uStack00000013;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000028;
  char in_stack_00000030;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  iStack00000024 = *(int *)(unaff_EBX + 0x394);
  if ((iStack00000024 < 0) || (4 < iStack00000024)) {
    in_stack_00000018 = 0;
    in_stack_0000001c = 0x47c34f80;
    in_stack_00000020 = 0xbf800000;
    cVar1 = FUN_0045b050(in_stack_00000014,0,&stack0x00000020,&stack0x00000018,&stack0x0000001c,0,
                         DAT_007006ec);
    if (((cVar1 == '\0') &&
        (((in_stack_00000018 != 0 && (cVar1 = func_0x0057a6f0(), cVar1 != '\0')) &&
         (iVar2 = FUN_0057b520(), iVar2 != 0)))) &&
       ((DAT_006cc7a4 <
         *(float *)(iVar2 + 0x10) -
         *(float *)(*(char *)(unaff_EBX + 0x388) * 0x38 + 0x18 + unaff_EBX) &&
        (fVar3 = (float10)FUN_0057b480(),
        fVar3 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))))) {
      in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,1);
      if (*extraout_EDX <= DAT_006cc7a4) {
        in_stack_00000018 = (uint)in_stack_00000018._1_3_ << 8;
      }
      cVar1 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,in_stack_00000018);
      if (cVar1 == '\0') {
        FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
        goto LAB_00454dc4;
      }
    }
  }
  else {
    uStack00000013 = 0;
    cVar1 = FUN_0045b150(in_stack_00000014,unaff_EBP + 0x20,unaff_EBX,DAT_007006ec,&stack0x00000013,
                         1);
    if (cVar1 == '\0') goto LAB_00454dc4;
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// 0045504f FUN_0045504f

int __fastcall FUN_0045504f(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_2 + 0x24);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x40);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// 00455059 FUN_00455059

int __fastcall FUN_00455059(int param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_EDI;
  undefined4 *puVar2;
  
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *unaff_EDI = in_EAX;
    unaff_EDI = unaff_EDI + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x40);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = in_EAX;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// 00455070 FUN_00455070

void __thiscall FUN_00455070(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_006c8fc4;
  iVar2 = DAT_00733f60;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f60 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f60 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return;
}


// 004550d0 FUN_004550d0

float10 FUN_004550d0(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[3] +
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[4];
}


// 00455160 FUN_00455160

void FUN_00455160(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004422b0(param_3,param_4);
  return;
}


// 00455180 FUN_00455180

undefined4 * __thiscall FUN_00455180(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004550a0();
  iVar2 = DAT_00733f60;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f60 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f60 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// 004551e0 FUN_004551e0

void FUN_004551e0(float *param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = param_1[6];
  fVar3 = -param_1[5] * param_4 + param_1[1];
  fVar2 = *param_1;
  param_2[1] = fVar3;
  *param_2 = fVar1 * param_4 + fVar2;
  fVar1 = param_1[6];
  *param_2 = param_3 * param_1[5] + *param_2;
  param_2[1] = param_3 * fVar1 + fVar3;
  return;
}


// 00455360 FUN_00455360

undefined4 * __thiscall FUN_00455360(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004552a0();
  iVar2 = DAT_00733f64;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f64 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// 00455441 FUN_00455441

undefined4 * FUN_00455441(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    FUN_00455000();
    *unaff_ESI = &PTR_FUN_006c8f5c;
    return unaff_ESI;
  }
  return (undefined4 *)0x0;
}


// 00455449 FUN_00455449

void FUN_00455449(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00455000();
  *unaff_ESI = &PTR_FUN_006c8f5c;
  return;
}


// 00455490 FUN_00455490

float10 FUN_00455490(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[5] +
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[6];
}


// 004554e0 FUN_004554e0

undefined4 * __thiscall FUN_004554e0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004553c0();
  iVar2 = DAT_00733f64;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f64 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// 00458ac0 FUN_00458ac0

undefined4 * __thiscall FUN_00458ac0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c8f08;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00458b70 FUN_00458b70

void __fastcall FUN_00458b70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -0x40)) {
    *(undefined4 *)(iVar1 + 0x404) = 0x3f800000;
  }
  return;
}


// 0045d6f0 FUN_0045d6f0

void * __thiscall FUN_0045d6f0(void *param_1,byte param_2)

{
  FUN_0045d710(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00460fc0 FUN_00460fc0

void __thiscall FUN_00460fc0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"RealDriver");
  FUN_00571c20(param_2,param_1 + 0x270,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x278,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x27c,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x284,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x280,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x288,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x289,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x28c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x290,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x291,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x292,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x294,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x298,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x299,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x29a,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x29c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2a0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a1,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2a8,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a9,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2ac,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2b0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2b4,4,0xffffffff,0);
  FUN_00460890();
  FUN_004251a0(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// 004615e0 FUN_004615e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004615e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 0x2c) + 0x40))();
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x26c) + 0x10) + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if ((&DAT_007306c4)[*(int *)(param_1 + 0x270)] == -1) {
    FUN_004617d0();
  }
  if (*(int *)(param_1 + 0x27c) != 0) {
    *(undefined4 *)(param_1 + 0x294) = 0;
    *(undefined4 *)(param_1 + 0x29c) = 0x3f800000;
  }
  FUN_00461a60(param_1,param_2);
  if ((*(char *)(param_1 + 0x2b8) != '\0') &&
     (_DAT_0070031c < *(float *)(*(int *)(param_1 + 0x26c) + 0x3b8))) {
    uVar3 = FUN_00460930(*(undefined4 *)(param_1 + 0x28c),param_2,*(undefined4 *)(param_1 + 0x270));
    *(undefined2 *)(param_1 + 0x1d0) = uVar3;
  }
  if (*(int *)(param_1 + 0x278) != 0) {
    *(undefined4 *)(param_1 + 0x1d4) = 1;
    *(undefined4 *)(param_1 + 0x1e4) = 0x3f800000;
  }
  iVar1 = *(int *)(param_1 + 0x26c);
  if (*(int *)(iVar1 + 0x28) == 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0x34) + 0x4c);
    if (*(int *)(param_1 + 0x284) == 3) {
      if ((*(int *)(iVar1 + 0x3d8) != *(int *)(param_1 + 0x1d4)) &&
         ((*(int *)(iVar1 + 0x3d8) < 2 || (*(int *)(param_1 + 0x1d4) < 2)))) {
        *(undefined4 *)(param_1 + 0x284) = 4;
        *(undefined4 *)(iVar2 + 0x60) = 0;
      }
    }
    else if ((*(int *)(param_1 + 0x284) == 4) &&
            ((*(int *)(iVar1 + 0x28) != 1 ||
             (*(int *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x4c) + 0x48) == 0)))) {
      *(undefined4 *)(param_1 + 0x284) = 3;
      *(undefined4 *)(iVar2 + 0x60) = 3;
    }
    if (*(int *)(param_1 + 0x284) == 3) {
      *(undefined4 *)(iVar2 + 0x60) = 3;
      FUN_0046dac0(*(undefined4 *)(param_1 + 0x2b4));
      return;
    }
    if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
       ((DAT_00735fa0 != 0 || ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))))) {
      if (_DAT_006cca0c < *(float *)(param_1 + 0x1e0)) {
        *(undefined1 *)(iVar2 + 0x74) = 1;
        return;
      }
      *(undefined1 *)(iVar2 + 0x74) = 0;
    }
  }
  return;
}


// 00461f40 FUN_00461f40

void FUN_00461f40(undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  int iVar1;
  
  if (param_3 != '\0') {
    iVar1 = *(int *)(param_4 + 0x284);
    if (iVar1 == 3) {
      if (*(int *)(param_4 + 0x1d4) != 0) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x26c) + 0x3d8);
        if (1 < iVar1) {
          *(int *)(param_4 + 0x1d4) = iVar1 + -1;
          return;
        }
LAB_00461f93:
        *(int *)(param_4 + 0x1d4) = iVar1;
        return;
      }
    }
    else if (iVar1 == 1) {
      iVar1 = *(int *)(param_4 + 0x1d4);
      if ((iVar1 != 0) && (1 < iVar1)) {
        iVar1 = iVar1 + -1;
        goto LAB_00461f93;
      }
    }
    else if ((iVar1 == 2) && (*(int *)(*(int *)(param_4 + 0x26c) + 0x28) != 3)) {
      if (*(int *)(param_4 + 0x1d4) == -2) {
        iVar1 = *(int *)(param_4 + 0x1d8);
      }
      else {
        *(undefined4 *)(param_4 + 0x1d4) = 0xfffffffe;
        iVar1 = *(int *)(*(int *)(param_4 + 0x26c) + 0x3d8);
        if (iVar1 < 3) {
          *(int *)(param_4 + 0x1d8) = iVar1;
          return;
        }
      }
      *(int *)(param_4 + 0x1d8) = iVar1 + -1;
    }
  }
  return;
}


// 0046a240 FUN_0046a240

int __fastcall FUN_0046a240(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xc0;
  }
  return *(int *)(param_1 + 0x140) + 0xd0;
}


// 0046a640 FUN_0046a640

void __thiscall FUN_0046a640(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(param_1,"TrackPolygonCollisionBody");
  FUN_004684f0(param_2);
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0x24,8,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0x2c,8,0xffffffff,0);
  }
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// 00476f80 FUN_00476f80

void * __thiscall FUN_00476f80(void *param_1,byte param_2)

{
  FUN_00477250(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 0047dbf0 FUN_0047dbf0

void * __thiscall FUN_0047dbf0(void *param_1,byte param_2)

{
  FUN_0047dc10();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 0047ea20 FUN_0047ea20

void __fastcall FUN_0047ea20(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 auStack_a4 [164];
  
  if ((*(int *)(param_1 + 0x1c) == -1) || (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if (((*(int *)(param_1 + 0xc) != 0) && (*(int *)(*(int *)(param_1 + 0xc) + 0xc) == 9)) &&
          (iVar1 = func_0x00486c00(), iVar1 == 0)) {
    return;
  }
  if (DAT_00737074 <= *(int *)(param_1 + 0x20)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  FUN_0047f9e0();
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  pvVar2 = _malloc(0x19c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004864e0(pvVar2,auStack_a4,0);
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}


// 0047eca0 FUN_0047eca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047eca0(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 auStack_a4 [164];
  
  uVar3 = *(undefined4 *)(param_1 + 0x34 + *(int *)(param_1 + 0xb4) * 4);
  if ((*(int *)(param_1 + 0x1c) == -1) || (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = func_0x00484cd0(), iVar1 == 0)) {
    return;
  }
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if ((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x30)) && (DAT_00734690 == 0)) {
    *(undefined4 *)(param_1 + 0xb8) = 1;
    return;
  }
  iVar1 = *(int *)(param_1 + 0xb4) + 1;
  *(int *)(param_1 + 0xb4) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c) + 1;
  *(int *)(param_1 + 0x2c) = iVar1;
  if (_DAT_007370f8 <= iVar1) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  FUN_0047f9e0();
  pvVar2 = _malloc(0x45c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004848f0(pvVar2,uVar3,auStack_a4);
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  return;
}


// 00482850 FUN_00482850

void FUN_00482850(undefined4 param_1,undefined4 param_2)

{
  FUN_00482230(param_1,param_2);
  return;
}


// 0048485a FUN_0048485a

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


// 00492520 FUN_00492520

void __thiscall FUN_00492520(int param_1,undefined4 param_2)

{
  float fVar1;
  
  fVar1 = DAT_006b6be4 + *(float *)(param_1 + 0x50);
  if (*(float *)(param_1 + 0x48) <= fVar1) {
    FUN_00490770(param_1 + 0x13c,param_2,*(float *)(param_1 + 0x48) / fVar1,0);
    return;
  }
  return;
}


// 004b3800 FUN_004b3800

void FUN_004b3800(void)

{
  int in_EAX;
  int unaff_ESI;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(unaff_ESI + 8),*(int *)(in_EAX + 0x18));
  }
  return;
}


// 004b39b0 FUN_004b39b0

undefined4 * __thiscall FUN_004b39b0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c5fb8;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 004b9e60 FUN_004b9e60

void * __thiscall FUN_004b9e60(void *param_1,byte param_2)

{
  FUN_004b9e80(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 004bcb40 FUN_004bcb40

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
        cVar1 = FUN_004bcfd0();
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
      FUN_004dcfd0(&uStack_38,*(undefined4 *)(param_1 + 0xc));
    }
    else {
      if (param_2 == 0xc98356ba) {
        FUN_004f89d0();
        iVar2 = *(int *)(param_1 + 0x90);
        if (((iVar2 != 0) && (iVar2 != 0x7fffffff)) &&
           (_DAT_006faf00 <= (float)(DAT_0073ad3c - iVar2) * _DAT_006cca38)) {
          FUN_004b23b0(*(int *)(param_1 + 0x48) + 0x10,1);
          *(undefined4 *)(param_1 + 0x90) = 0;
        }
        FUN_004f7d30();
        return;
      }
      if (param_2 == 0xed5a2448) {
        FUN_00416f00();
        _DAT_0075895c = 3;
        iVar2 = FUN_004f65d0();
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
          FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        DAT_00758c2c = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x738);
        FUN_004b23b0(*(int *)(param_1 + 0x4c) + 0x10,1);
        if (*(int *)(param_1 + 0x9c) < 3) {
          DAT_00748f74 = 1;
        }
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
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
      iVar2 = FUN_004f65d0();
      bVar4 = iVar2 == 0;
    }
    else {
      DAT_00758954 = 1;
      iVar2 = FUN_004f65d0();
      bVar4 = iVar2 == 0;
    }
LAB_004bcede:
    if (!bVar4) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
    FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
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
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
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
    iVar2 = FUN_004f65d0();
    bVar4 = iVar2 == 0;
    goto LAB_004bcede;
  }
  if (DAT_00777b4c != 8) {
    if (DAT_00777cc8 != 5) {
      FUN_004bd000(param_1);
      return;
    }
    FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  auStack_34[6] = 0;
  auStack_34[7] = 0;
  cVar1 = FUN_004ac040();
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


// 004beec0 FUN_004beec0

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


// 004bf4a0 FUN_004bf4a0

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


// 004c0000 FUN_004c0000

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


// 004c005d FUN_004c005d

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


// 004c006c FUN_004c006c

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


// 004c2bc0 FUN_004c2bc0

bool FUN_004c2bc0(uint param_1,int param_2)

{
  float *pfVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x730);
  pfVar1 = (float *)(param_1 + 0x734);
  pcVar5 = *(char **)(param_2 + 0x730);
  param_1 = ((uint)(*(int *)(iVar6 + 0xc54) == 2) * 0x100 + (int)*(short *)(iVar6 + 0xc58)) *
            0x10000;
  uVar4 = ((uint)(*(int *)(pcVar5 + 0xc54) == 2) * 0x100 + (int)*(short *)(pcVar5 + 0xc58)) *
          0x10000;
  if (*pfVar1 <= *(float *)(param_2 + 0x734)) {
    if (*pfVar1 < *(float *)(param_2 + 0x734)) {
      uVar4 = uVar4 + 0x100;
    }
  }
  else {
    param_1 = param_1 + 0x100;
  }
  iVar6 = iVar6 - (int)pcVar5;
  do {
    cVar2 = pcVar5[iVar6];
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    if ((cVar2 == '\0') || (cVar3 == '\0')) break;
  } while (cVar2 == cVar3);
  if ((int)cVar2 != (int)cVar3 && -1 < (int)cVar2 - (int)cVar3) {
    param_1 = param_1 + 1;
  }
  return param_1 <= uVar4;
}


// 004c30b0 FUN_004c30b0

void * __thiscall FUN_004c30b0(void *param_1,byte param_2)

{
  FUN_004c30d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 004c3d00 FUN_004c3d00

void FUN_004c3d00(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FEPackageList__FindByName();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(unaff_ESI + 8),*(int *)(iVar1 + 0x18));
    return;
  }
  return;
}


// 004c4154 FUN_004c4154

void FUN_004c4154(void)

{
  int iVar1;
  int unaff_EBX;
  bool in_ZF;
  
  if (in_ZF) {
    FUN_004f89d0();
    FUN_004f7d30();
    if ((*(char *)(unaff_EBX + 0x88) != '\0') &&
       (iVar1 = *(int *)(unaff_EBX + 0x90) + 1, *(int *)(unaff_EBX + 0x90) = iVar1,
       *(int *)(unaff_EBX + 0x8c) < iVar1)) {
      iVar1 = FUN_0051c7f0();
      if (iVar1 == 0) {
        *(undefined1 *)(unaff_EBX + 0x94) = 1;
      }
    }
    if ((*(char *)(unaff_EBX + 0x94) != '\0') &&
       (*(int *)(unaff_EBX + 0x98) < *(int *)(unaff_EBX + 0x9c))) {
      FUN_005a2540();
      Ugd__Write(&DAT_0078a478,"auto");
      Settings__Save();
      FUN_004b2410();
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      FUN_004f6360(*(undefined4 *)(unaff_EBX + 0xc));
      return;
    }
    *(int *)(unaff_EBX + 0x9c) = *(int *)(unaff_EBX + 0x9c) + 1;
  }
  return;
}


// 004c8900 FUN_004c8900

void __thiscall FUN_004c8900(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (0xb5971bf1 < param_2) {
    if (param_2 != 0xc519bfc8) {
      if (param_2 == 0xc98356ba) {
        if (*(int *)(param_1 + 0x80) != param_1 + 0x80) {
          FUN_004f89d0();
        }
        FUN_004f7d30();
        return;
      }
      if (param_2 != 0xf0aadebb) {
        return;
      }
      FUN_004c8720();
      return;
    }
LAB_004c89d2:
    if ((*(char *)(param_1 + 0x7b0) == '\0') || (param_2 != 0xc519bfc8)) {
      if (*(char *)(param_1 + 0x88) == '\0') {
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_24 = 0x9da49222;
        uStack_1c = 0xf0aadebb;
        uStack_20 = 0x639;
        uStack_14 = 0;
        uStack_18 = 0x541389e5;
        uStack_10 = 0;
        uStack_c = 0xb8a7c6cc;
        FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      }
    }
    else {
      FUN_004c8810();
      iVar1 = DAT_0073578c;
      bVar2 = DAT_0073578c != 0;
      *(undefined1 *)(param_1 + 0x7b0) = 0;
      if (((bVar2) && (FUN_004f5f80(iVar1,1), DAT_0073578c != 0)) &&
         (FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0)) {
        FUN_004f5ed0(DAT_0073578c);
        return;
      }
    }
    return;
  }
  if (param_2 != 0xb5971bf1) {
    if (param_2 < 0x14141415) {
      if (param_2 == 0x14141414) {
        FUN_004c72d0();
        return;
      }
      if (param_2 != 0xc407210) {
        if (param_2 != 0x12121212) {
          return;
        }
        *(undefined1 *)(param_1 + 0x8a) = 0;
        FUN_004c96f0(0x14141414,2);
        return;
      }
      goto LAB_004c89d2;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  FUN_004c85b0(param_2);
  return;
}


// 004cb130 FUN_004cb130

void __thiscall FUN_004cb130(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined1 auStack_100 [256];
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      Player__Init(1);
      if (*(char *)(param_1 + 0xb4) == '\0') {
        if (DAT_007677b4 == '\x01') {
          *(undefined1 **)(param_1 + 0x40) = &LAB_004cb320;
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
      }
      else {
        DAT_007677b0 = 1;
      }
      *(undefined1 **)(param_1 + 0x40) = &LAB_004cb480;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else {
      if (param_2 == 0x12312311) {
        DAT_00735e4c = 0;
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        FUN_004c9650();
        return;
      }
      if (param_2 == 0x12312322) {
        DAT_00735e4c = 1;
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        FUN_004c9650();
        return;
      }
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    bSPrintf_regdst(0x100,iVar1,&DAT_00777b74);
    uStack_10c = 0xb8a7c6cd;
    uStack_114 = 0x12312311;
    uStack_118 = 0x61c;
    uStack_11c = 0x12312300;
    uStack_104 = 0;
    uStack_108 = 0;
    uStack_120 = 0xf770;
    uStack_124 = 0xf770;
    if (DAT_006fad58 != 2) {
      uStack_110 = 0x12312322;
      FUN_004dc6e0(&uStack_124,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      FUN_004dccc0(auStack_100);
      return;
    }
    uStack_110 = 0;
    FUN_004dc6e0(&uStack_124,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    FUN_004dccc0(auStack_100);
    return;
  }
  return;
}


// 004cb480 FUN_004cb480

void __thiscall FUN_004cb480(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  if (*(char *)(param_1 + 0x48) != '\0') {
    if (param_2 != -0x367ca946) {
      return;
    }
    *(undefined1 *)(param_1 + 0x48) = 0;
    uVar1 = FUN_00565b60(0xf660,0,0,0);
    *(undefined4 *)(param_1 + 0xb0) = uVar1;
    Ugd__PackBlock(&DAT_007588c4,0xf660);
    if (*(char *)(param_1 + 0xb5) != '\0') {
      FUN_004eb4b0(0x12312300,&DAT_00777b74,*(undefined4 *)(param_1 + 0xb0));
      return;
    }
    FUN_004eb560(0x12312300,&DAT_00777b74,*(undefined4 *)(param_1 + 0xb0),0xf660);
    return;
  }
  if (param_2 != 0x12312300) {
    return;
  }
  FUN_00565ce0();
  bVar3 = DAT_00735dc0 == 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  if (bVar3) {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
    DAT_007677b4 = '\0';
  }
  else {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
    if (DAT_00735dc0 == 9) {
      if ((*(char *)(param_1 + 0xb5) != '\0') && (DAT_007677b0 == 1)) {
        *(undefined1 *)(param_1 + 0x48) = 1;
        *(undefined1 **)(param_1 + 0x40) = &LAB_004cc1c0;
        return;
      }
LAB_004cb5aa:
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(undefined1 **)(param_1 + 0x40) = &LAB_004cb5f0;
      return;
    }
    if (DAT_00735dc0 != 6) {
      if (DAT_007677b4 == '\x01') {
        Player__Init(1);
      }
      goto LAB_004cb5aa;
    }
    if (DAT_007677b4 != '\x01') goto LAB_004cb5e2;
  }
  Player__Init(1);
LAB_004cb5e2:
  FUN_004c9650();
  return;
}


// 004cbe30 FUN_004cbe30

void __fastcall FUN_004cbe30(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0x9c;
  pcVar1 = &DAT_00777b74;
  do {
    iVar2 = iVar2 + -1;
    *pcVar1 = pcVar1[-0x1f2b0];
    if (pcVar1[-0x1f2b0] == '\0') break;
    pcVar1 = pcVar1 + 1;
  } while (iVar2 != 0);
  if ((DAT_007588d1 == '\0') || (DAT_007677b0 != 1)) {
    if ((DAT_00735dbd == '\0') || (DAT_007677b0 != 1)) {
      if (DAT_006fad58 == 2) {
        DAT_00735dbd = 0;
        *(undefined1 **)(param_1 + 0x40) = &LAB_004cafd0;
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
      *(undefined1 **)(param_1 + 0x40) = &LAB_004cbfd0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    }
  }
  else if (DAT_00735dbd == '\0') {
    *(code **)(param_1 + 0x40) = FUN_004cb480;
    *(undefined1 *)(param_1 + 0x48) = 1;
    return;
  }
  *(code **)(param_1 + 0x40) = FUN_004cbed0;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


// 004cc400 FUN_004cc400

void __thiscall FUN_004cc400(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(undefined1 **)(param_1 + 0x40) = &LAB_004cc580;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      FUN_004c9650();
      return;
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    bSPrintf_regdst(0x100,iVar1);
    if (DAT_00735e48 == 0) {
      iVar1 = LanguageStrings__FindByHash();
      if (iVar1 == 0) {
        iVar1 = LanguageStrings__FindByHash();
      }
    }
    else {
      iVar1 = LanguageStrings__FindByHash();
      if (iVar1 == 0) {
        iVar1 = LanguageStrings__FindByHash();
      }
    }
    bSPrintf_regdst(0x100,"%s^%s",iVar1,auStack_200);
    uStack_224 = 0xf770;
    uStack_220 = 0xf770;
    uStack_208 = 0;
    uStack_204 = 0;
    uStack_21c = 0x12312300;
    uStack_218 = 0x61c;
    uStack_214 = 0x12312311;
    uStack_210 = 0;
    uStack_20c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_224,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    FUN_004dccc0(auStack_100);
    return;
  }
  return;
}


// 004cdc40 FUN_004cdc40

void __fastcall FUN_004cdc40(int param_1)

{
  int iVar1;
  
  if (DAT_0078a320 == 2) {
    if (DAT_007361b4 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_007361b4 + 8);
    }
    if ((&DAT_007306c4)[iVar1] == -1) {
      return;
    }
    if (DAT_007361b8 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_007361b8 + 8);
    }
    if ((&DAT_007306c4)[iVar1] == -1) {
      return;
    }
  }
  iVar1 = FUN_00438840(&DAT_0073ad3c);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x6c) = 1;
  }
  return;
}


// 004cdca0 FUN_004cdca0

void __fastcall FUN_004cdca0(int param_1)

{
  int iVar1;
  
  if (DAT_0078a320 == 2) {
    if (DAT_007361b4 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_007361b4 + 8);
    }
    if ((&DAT_007306c4)[iVar1] == -1) {
      return;
    }
    if (DAT_007361b8 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_007361b8 + 8);
    }
    if ((&DAT_007306c4)[iVar1] == -1) {
      return;
    }
  }
  DAT_00777cb8 = 0xffffffff;
  *(undefined1 *)(param_1 + 0x6f) = 1;
  return;
}


// 004d5420 FUN_004d5420

void __thiscall FUN_004d5420(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 < 0x72619779) {
        if (param_2 != 0x72619778) {
          if (param_2 == 0x35f8620b) {
            if (*(int *)(param_1 + 0xb0) != 0) {
              FUN_004f8dd0(*(int *)(param_1 + 0xb0));
            }
            FUN_004d5da0(param_1);
            return;
          }
          if (param_2 != 0x5073ef13) {
            return;
          }
          goto LAB_004d5540;
        }
      }
      else {
        if (param_2 == 0x911ab364) {
          iVar1 = FUN_004f65d0();
          if (iVar1 != 0) {
            *(undefined4 *)(iVar1 + 0x1c) = 0xff;
          }
          FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (param_2 != 0x911c0a4b) {
          return;
        }
      }
      FUN_004d56a0(param_1);
      iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0x10);
      if ((DAT_00735e30 != iVar1) || (*(char *)(*(int *)(param_1 + 0xa8) + 0x14) != '\0')) {
        FUN_004d5da0(param_1);
      }
      DAT_00735e30 = iVar1;
      return;
    }
  }
  else {
    if (0xc98356ba < param_2) {
      if (param_2 != 0xd9feec59) {
        return;
      }
LAB_004d5540:
      FUN_004d5910(param_1);
      return;
    }
    if (param_2 == 0xc98356ba) {
      FUN_004f7d30();
      FUN_004d5120();
      return;
    }
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc519bfc0) {
        return;
      }
      if (*(char *)(param_1 + 0x94) != '\0') {
        FUN_004d5df0();
        return;
      }
      FUN_004d5d80();
      return;
    }
  }
  FUN_004d5580(param_1);
  return;
}


// 004d5447 FUN_004d5447

void FUN_004d5447(void)

{
  int in_EAX;
  int unaff_ESI;
  bool in_ZF;
  
  if (in_ZF) {
    if (*(int *)(unaff_ESI + 0xb0) != 0) {
      FUN_004f8dd0(*(int *)(unaff_ESI + 0xb0));
    }
    FUN_004d5da0(unaff_ESI);
    return;
  }
  if (in_EAX != 0x5073ef13) {
    return;
  }
  FUN_004d5910(unaff_ESI);
  return;
}


// 004d61c0 FUN_004d61c0

byte FUN_004d61c0(int param_1)

{
  return (param_1 != -0x6ee54c9c) - 1U & 6;
}


// 004e0120 FUN_004e0120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e0120(int param_1,int param_2)

{
  if ((param_2 == -0x367ca946) &&
     (_DAT_006fa5a8 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x40)) * _DAT_006cca38)) {
    FUN_004e00d0(param_1);
  }
  return;
}


// 004e4745 FUN_004e4745

uint FUN_004e4745(void)

{
  uint uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000024;
  undefined4 uStack00000030;
  
  uStack0000001c = 0x639;
  uStack00000024 = 0x541389e5;
  uStack00000030 = 0xb8a7c6cc;
  uVar1 = FUN_004dc6e0();
  return uVar1 & 0xffffff00;
}


// 004e494d FUN_004e494d

void __fastcall FUN_004e494d(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int *piVar11;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  do {
    piVar6 = (int *)unaff_EDI[3];
    piVar11 = piVar6 + unaff_EDI[4] * 0xc;
    if (unaff_ESI != 0) {
      piVar6 = (int *)BinarySearch_Hash();
      if (piVar6 == (int *)0x0) break;
      unaff_EDI = *(int **)(unaff_EBP + -4);
      param_2 = *(int *)(unaff_EBP + -8);
    }
    for (; piVar6 < piVar11; piVar6 = piVar6 + 0xc) {
      if ((unaff_ESI != 0) && (piVar6[1] != unaff_ESI)) goto LAB_004e49a2;
      if ((char)piVar6[4] == '\b') goto LAB_004e49a4;
    }
    iVar10 = *unaff_EDI;
    *(int *)(unaff_EBP + -4) = iVar10;
    if (iVar10 == param_2) break;
    unaff_EDI = *(int **)(unaff_EBP + -4);
  } while( true );
LAB_004e49a2:
  piVar6 = (int *)0x0;
LAB_004e49a4:
  if (piVar6 != (int *)0x0) {
    bVar5 = true;
    do {
      if (!bVar5) break;
      pcVar7 = "STOCK";
      do {
        cVar2 = pcVar7[*piVar6 + -0x6c3200];
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        if ((cVar2 == '\0') || (cVar3 == '\0')) break;
      } while (cVar2 == cVar3);
      if (cVar2 == cVar3) {
        bVar5 = false;
      }
      else {
        iVar8 = FECarConfig__GetCarType();
        iVar10 = 0;
        if (iVar8 != 0x23) {
          iVar10 = iVar8 * 0xc90 + DAT_00734588;
          if (iVar10 == 0) {
            iVar10 = 0;
          }
          else {
            pbVar9 = (byte *)(iVar10 + 0x20);
            iVar10 = -1;
            bVar4 = *pbVar9;
            while (bVar4 != 0) {
              iVar10 = iVar10 * 0x21 + (uint)bVar4;
              pbVar1 = pbVar9 + 1;
              pbVar9 = pbVar9 + 1;
              bVar4 = *pbVar1;
            }
          }
        }
        piVar6 = (int *)CarPartDatabase__GetCarPart(iVar10,8,0,piVar6,0xffffffff);
      }
    } while (piVar6 != (int *)0x0);
    GarageManager__InstallPart(piVar6,0);
  }
  if (DAT_00735df4 != '\0') {
    FUN_004aa970(&DAT_007588c4);
    DAT_00735df4 = '\0';
  }
  FUN_005043f0();
  FUN_005043f0();
  FUN_005043f0();
  GarageManager__PushScreen();
  FUN_004e2430(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  return;
}


// 004e67e0 FUN_004e67e0

void __thiscall FUN_004e67e0(undefined4 param_1,uint param_2)

{
  if (param_2 < 0x54c56cbf) {
    if (param_2 == 0x54c56cbe) {
      FUN_00495fc0();
      FUN_00495f70();
      return;
    }
    if (param_2 < 0x30e0e6c0) {
      if (param_2 == 0x30e0e6bf) {
        FUN_004e7860(0x4848c0fd,0x39b2b1c6,0x55dafa35,0x55dafa35);
        return;
      }
      if (param_2 == 0x3b4ff2d) {
        DAT_00736124 = 1;
        return;
      }
      if (param_2 == 0x1122aabb) {
        FUN_004e7860(0x49885419,0x687acde2,0x571a8d51,0x571a8d51);
        return;
      }
      if (param_2 == 0x1122aacc) {
        FUN_004e7860(0x49885419,0x687acde2,0x571a8d51,0x571a8d51);
        return;
      }
    }
    else {
      if (param_2 == 0x4c71900a) {
        FUN_004e7860(0xb04475b2,0xfd6189db,0xbdd6aeea,0xbdd6aeea);
        FUN_004e7860(0xb04475b2,0xfd6189dc,0xbdd6aeea,0xbdd6aeea);
        return;
      }
      if (param_2 == 0x4c71910b) {
        FUN_004e7860(0xb04475b2,0xfd6189db,0xbdd6aeea,0xbdd6aeea);
        FUN_004e7860(0xb04475b2,0xfd6189dc,0xbdd6aeea,0xbdd6aeea);
        return;
      }
      if (param_2 == 0x4c75717a) {
        FUN_00495f70();
        FUN_00495fc0();
        return;
      }
    }
  }
  else if (param_2 < 0xd0687427) {
    if (param_2 == 0xd0687426) {
      FUN_004e7860(0x7614183e,0xc68d44c7,0x83a65176,0x83a65176);
      return;
    }
    if (param_2 == 0x5a7b4438) {
      FUN_004e7860(0x4848c0fd,0x39b2b1c6,0x55dafa35,0x55dafa35);
      return;
    }
    if (param_2 == 0xb3c3508e) {
      FUN_004e7860(0x9fe0ca88,0x7014dc91,0xad7303c0,0xad7303c0);
      return;
    }
    if (param_2 == 0xc98356ba) {
      if (DAT_00735dd8 != 0) {
        if (DAT_0073578c != 0) {
          FUN_004f40c0(0);
          FEManager__RemoveJoyHandlers(DAT_0073578c);
        }
        FEManager__PushPackageChecked(0,0xff);
        return;
      }
      FUN_004e7600();
      FUN_004e7320();
      FUN_004e6f00(param_1);
      return;
    }
  }
  else if (param_2 == 0xddeeffaa) {
    FUN_004e7860(0x1c7fcf8b,0xdc18c4d4,0x2a1208c3,0x2503558d);
  }
  else if (param_2 == 0xfc661e67) {
    FUN_004e7860(0x9fe0ca88,0x7014dc91,0xad7303c0,0xad7303c0);
    return;
  }
  return;
}


// 004f9700 FUN_004f9700

void __thiscall FUN_004f9700(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x2cbd3c6c) {
    if (param_2 == 0x2cbd3c6b) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c != 0) {
          uVar2 = FUN_004ef050(0x12dfbc68);
          FEObject__SetVisible(uVar2);
          goto LAB_004f985f;
        }
        iVar1 = 0;
      }
      FEObject__SetVisible(iVar1);
      goto LAB_004f985f;
    }
    switch(param_2) {
    case 0x1c2d8258:
      FUN_004f9a60(param_1,0);
      return;
    case 0x1c2d8259:
      FUN_004f9a60(param_1,1);
      return;
    case 0x1c2d825a:
      FUN_004f9a60(param_1,2);
      return;
    case 0x1c2d825b:
      FUN_004f9a60(param_1,3);
      return;
    case 0x1c2d825c:
      FUN_004f9a60(param_1,4);
      return;
    case 0x1c2d825d:
      FUN_004f9a60(param_1,5);
      return;
    case 0x1c2d825e:
      FUN_004f9a60(param_1,6);
      return;
    }
  }
  else if (param_2 < 0x50fe8c16) {
    if (param_2 == 0x50fe8c15) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_004ef050(0x12dfbc68);
        }
      }
      FEObject__SetVisible(iVar1);
      FUN_00495f70();
      return;
    }
    if (param_2 < 0x2cbd3c8e) {
      if (param_2 == 0x2cbd3c8d) {
        FUN_004f9b70();
        return;
      }
      if (param_2 == 0x2cbd3c6c) {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
           (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
          if (DAT_0073578c != 0) {
            uVar2 = FUN_004ef050(0x12dfbc68);
            FEObject__SetVisible(uVar2);
            goto LAB_004f985f;
          }
          iVar1 = 0;
        }
        FEObject__SetVisible(iVar1);
      }
      else {
        if (param_2 != 0x2cbd3c6d) {
          return;
        }
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
           (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
          if (DAT_0073578c == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_004ef050(0x12dfbc68);
          }
        }
        FEObject__SetVisible(iVar1);
      }
LAB_004f985f:
      uVar2 = FUN_00567c70();
      FUN_004ad7b0(uVar2);
      return;
    }
    if (param_2 == 0x2cbd3c8f) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_004ef050(0x12dfbc68);
        }
      }
      FEObject__SetVisible(iVar1);
      uVar2 = FUN_00567c70();
      FUN_004ad7b0(uVar2);
      return;
    }
    if (param_2 == 0x50fe5db4) {
      FUN_004f9e60();
      return;
    }
  }
  else if (param_2 < 0xc98356bb) {
    if (param_2 == 0xc98356ba) {
      FUN_004f9dd0();
      return;
    }
    if (param_2 == 0xa1f0e37d) {
      FUN_004f9d10();
      return;
    }
    if (param_2 == 0xa310e4c9) {
      FUN_004f69c0(0);
      return;
    }
  }
  else if (param_2 == 0xe8e61aab) {
    FUN_004f9c50();
  }
  else if (param_2 == 0xf7fbf050) {
    FUN_004f69c0(1);
    return;
  }
  return;
}


// 004fa3a0 FUN_004fa3a0

void __fastcall FUN_004fa3a0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0xffffffff;
  return;
}


// 004ff5f0 FUN_004ff5f0

undefined4 __thiscall FUN_004ff5f0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00684ceb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x58);
  uStack_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004fec30(pvVar1,param_1,param_2);
    ExceptionList = pvStack_c;
    return uVar2;
  }
  ExceptionList = pvStack_c;
  return 0;
}


// 005135a0 FUN_005135a0

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


// 00522140 FUN_00522140

undefined4 FUN_00522140(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_006f870c;
  DAT_007356c0 = DAT_007356c0 + (param_3 - param_2);
  DAT_007356c4 = DAT_007356c4 + param_2;
  if (param_2 != param_3) {
    (&DAT_0072d190)[(&DAT_0072ce50)[DAT_006f870c * 3]] = 0xffffffff;
    uVar3 = FUN_00565b60(param_2,0,0,0);
    (&DAT_0072ce58)[iVar2 * 3] = 2;
    (&DAT_0072ce54)[iVar2 * 3] = 0xffffffff;
    iVar1 = (&DAT_0072ce50)[iVar2 * 3];
    (&DAT_0072d190)[(&DAT_0072ce50)[iVar2 * 3]] = uVar3;
    DAT_00735688 = 1;
    return (&DAT_0072d190)[iVar1];
  }
  iVar1 = (&DAT_0072ce50)[DAT_006f870c * 3];
  uVar3 = (&DAT_0072cfd8)[iVar1];
  (&DAT_0072ce58)[DAT_006f870c * 3] = 0;
  (&DAT_0072ce54)[iVar2 * 3] = 0xffffffff;
  iVar2 = (&DAT_0072ce50)[iVar2 * 3];
  (&DAT_0072d190)[iVar1] = uVar3;
  DAT_00735688 = 0;
  return (&DAT_0072d190)[iVar2];
}


// 00522400 FUN_00522400

undefined4 __thiscall FUN_00522400(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (DAT_006f1dd8 == 0) {
    return 0xffffffff;
  }
  uVar1 = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  if (param_2 != 0) {
    FUN_0064e520();
    SNDSYS_leavecritical();
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  return uVar1;
}


// 005227c0 FUN_005227c0

void __thiscall FUN_005227c0(int param_1,int *param_2)

{
  int *piVar1;
  
  if (DAT_006f1dd8 != 0) {
    if (param_2 == (int *)0x12) {
      piVar1 = *(int **)(param_1 + 0x290);
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_2);
        Mutex__Lock();
        (**(code **)(*param_2 + 4))(piVar1);
        Mutex__Unlock();
        *(undefined4 *)(param_1 + 0x290) = 0;
        return;
      }
    }
    else {
      piVar1 = *(int **)(param_1 + 0x28c);
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_2);
        Mutex__Lock();
        (**(code **)(*param_2 + 4))(piVar1);
        Mutex__Unlock();
        *(undefined4 *)(param_1 + 0x28c) = 0;
      }
    }
  }
  return;
}


// 00524148 FUN_00524148

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524148(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char in_AL;
  char cVar2;
  int unaff_ESI;
  
  if ((in_AL != '\0') && (*(char *)(*(int *)(unaff_ESI + 0x1274) + 0xc) != '\0')) {
    EAXTurbo__UpdateBlowOff(param_2);
    EAXTurbo__UpdateSpool(param_2);
    iVar1 = *(int *)(unaff_ESI + 0x12a4);
    if (iVar1 == 0) {
      if (_DAT_006f80ec < *(float *)(unaff_ESI + 0x1f8c)) {
        *(undefined4 *)(unaff_ESI + 0x12a4) = 1;
      }
    }
    else if (iVar1 == 1) {
      if (*(float *)(unaff_ESI + 0x1f8c) < _DAT_006f80ec) {
        *(undefined4 *)(unaff_ESI + 0x12a4) = 2;
        EAXTurbo__PlayBlowoff
                  (*(undefined4 *)(unaff_ESI + 0x1274),0,0,0xfff,*(undefined4 *)(unaff_ESI + 0x6c),
                   *(undefined4 *)(unaff_ESI + 0x2ac));
        *(undefined4 *)(*(int *)(unaff_ESI + 0x1274) + 0x2c0) = 0;
        EAXTurbo__UpdateSpool(param_2);
        return;
      }
    }
    else if ((iVar1 == 2) && (cVar2 = EAXTurbo__IsBlowOffDone(), cVar2 != '\0')) {
      *(undefined4 *)(unaff_ESI + 0x12a4) = 0;
      return;
    }
  }
  return;
}


// 00524200 FUN_00524200

void FUN_00524200(void)

{
  undefined4 unaff_EDI;
  
  EAXTurbo__UpdateSpool(unaff_EDI);
  return;
}


// 00525bc0 FUN_00525bc0

undefined4 * __thiscall FUN_00525bc0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006bef4c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00526aa0 FUN_00526aa0

void __thiscall FUN_00526aa0(int param_1,int *param_2)

{
  if ((DAT_007361f0 != (int *)0x0) && (*DAT_007361f0 == 8)) {
    *param_2 = 0;
    return;
  }
  *param_2 = *(int *)(param_1 + 0x70) * *param_2 >> 0xf;
  FUN_00536c20(DAT_007356ac);
  return;
}


// 00527220 FUN_00527220

void __thiscall FUN_00527220(int param_1,int param_2,int param_3)

{
  *(int *)(param_1 + 0x10) = param_3;
  *(int *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 0xc) = 1;
  *(int *)(param_1 + 8) = param_3 * 100 + *(int *)(param_2 + 0x1f08);
  return;
}


// 005319e0 FUN_005319e0

undefined4 __fastcall FUN_005319e0(int param_1)

{
  int iStack_4;
  
  if (*(int **)(param_1 + 0x328) == (int *)0x0) {
    return 0;
  }
  iStack_4 = 0;
  if ((**(int **)(param_1 + 0x328) != 0) && (Csis__Class__GetRefCount(&iStack_4), iStack_4 == 1)) {
    return 0;
  }
  return 1;
}


// 00534c45 FUN_00534c45

void __fastcall FUN_00534c45(char param_1)

{
  int unaff_EBP;
  
  *(char *)(unaff_EBP + 0x75) = *(char *)(unaff_EBP + 0x75) + param_1;
  return;
}


// 0053a110 FUN_0053a110

undefined4 __thiscall FUN_0053a110(int param_1,int param_2)

{
  return CONCAT31((int3)((uint)(param_2 * 0x2e0) >> 8),
                  *(int *)(param_2 * 0x2e0 + 0x40 + param_1) != 0);
}


// 0053a620 FUN_0053a620

void __fastcall FUN_0053a620(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar2 = param_1[param_1[8] + 0xb];
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if (*(int *)(param_1[1] + 0x10) == 5) {
    piVar3 = (int *)*piVar1;
    if (piVar3 != (int *)0x0) {
      piStack_4 = param_1;
      if (*piVar3 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_4);
      Mutex__Lock();
      (**(code **)(*piStack_4 + 4))(piVar3);
      Mutex__Unlock();
      *piVar1 = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      return;
    }
  }
  else if ((int *)*piVar1 != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (*(int *)*piVar1 != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    if ((int)piStack_4 < param_1[5]) {
      piVar3 = (int *)*piVar1;
      if (piVar3 != (int *)0x0) {
        if (*piVar3 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_4);
        Mutex__Lock();
        (**(code **)(*piStack_4 + 4))(piVar3);
        Mutex__Unlock();
      }
      *piVar1 = 0;
      *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
      *(undefined4 *)(piVar1[0xb4] + 8) = 0;
      return;
    }
    (**(code **)(piVar1[4] + 0x28))(param_1[1] + 0x80,0);
    EAXS_Streams__Update3DParams();
    (**(code **)(*param_1 + 200))();
  }
  return;
}


// 0053ab60 FUN_0053ab60

void __fastcall FUN_0053ab60(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x10];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x10] = 0;
  }
  piVar1 = (int *)param_1[200];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[200] = 0;
  }
  param_1[5] = 0;
  FUN_00539d80();
  FUN_00539d80();
  return;
}


// 0053b5e0 FUN_0053b5e0

void __fastcall FUN_0053b5e0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*(int *)(piVar1[0xb4] + 8) != 0) {
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(undefined4 *)(*piVar1 + 0xc) = 0;
      if (*(int *)*piVar1 != 0) {
        FUN_0064bc30((int *)*piVar1 + 1);
      }
    }
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 7;
  }
  return;
}


// 0053b780 FUN_0053b780

void __fastcall FUN_0053b780(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piStack_4;
  
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if ((int *)param_1[param_1[8] * 0xb8 + 0x10] == (int *)0x0) {
    *(undefined4 *)(piVar1[0xb4] + 8) = 0;
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  }
  else {
    piStack_4 = (int *)0x0;
    if (*(int *)param_1[param_1[8] * 0xb8 + 0x10] != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    iVar2 = param_1[8];
    uVar4 = iVar2 - 1U & 1;
    piVar3 = param_1 + uVar4 * 0xb8 + 0x10;
    param_1[6] = (int)piStack_4;
    if (param_1[5] <= (int)piStack_4) {
      (**(code **)(piVar1[4] + 0x28))(0,0);
      EAXS_Streams__Update3DParams();
      (**(code **)(*param_1 + 200))();
      return;
    }
    if (*(int *)(piVar1[0xb4] + 0x18) < 2) {
      if (iVar2 == param_1[7]) {
        if (*piVar3 == 0) {
          *(undefined4 *)(piVar1[0xb4] + 8) = 0;
          *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
          *(undefined4 *)(piVar1[0xb4] + 0x18) = 3;
          (**(code **)(*param_1 + 0xc0))();
          if (*(int *)(piVar3[0xb4] + 8) == 0) {
            *(undefined4 *)(piVar3[0xb4] + 0xc) = 2;
            return;
          }
        }
        else if (*(int *)(piVar3[0xb4] + 8) < 2) {
          param_1[8] = uVar4;
          *(undefined4 *)(piVar3[0xb4] + 8) = 0;
          *(undefined4 *)(piVar3[0xb4] + 0xc) = 0;
          (**(code **)(*param_1 + 0xc0))();
          param_1[8] = uVar4 - 1 & 1;
          param_1[5] = param_1[6];
          return;
        }
      }
    }
    else if (iVar2 == param_1[7]) {
      if ((*piVar3 != 0) && (*(int *)(piVar3[0xb4] + 8) < 2)) {
        param_1[8] = uVar4;
        *(undefined4 *)(piVar3[0xb4] + 8) = 0;
        *(undefined4 *)(piVar3[0xb4] + 0xc) = 0;
        (**(code **)(*param_1 + 0xc0))();
        param_1[8] = uVar4 - 1 & 1;
        param_1[5] = param_1[6];
        return;
      }
      if (param_1[5] < 2) {
        piVar3 = (int *)*piVar1;
        if (piVar3 != (int *)0x0) {
          if (*piVar3 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&piStack_4);
          Mutex__Lock();
          (**(code **)(*piStack_4 + 4))(piVar3);
          Mutex__Unlock();
        }
        *piVar1 = 0;
        *(undefined4 *)(piVar1[0xb4] + 0x50) = *(undefined4 *)(param_1[1] + 0x44);
        *(undefined4 *)(param_1[1] + 0x40) = *(undefined4 *)(param_1[1] + 0x44);
        *(undefined4 *)(piVar1[0xb4] + 0xc) = 2;
        return;
      }
    }
  }
  return;
}


// 0053bbb0 FUN_0053bbb0

void __fastcall FUN_0053bbb0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    if (4 < *(int *)(piVar1[0xb4] + 0x48)) {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        iVar2 = 0;
      }
      if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
        iVar2 = 0;
      }
      iVar2 = (*(int *)(DAT_007356ac + 0x36fc) * iVar2 >> 0xf) * *(int *)(DAT_007356ac + 0x3e18) >>
              0xf;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// 0053be20 FUN_0053be20

void __fastcall FUN_0053be20(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x14];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x14] = 0;
  }
  piVar1 = (int *)param_1[0xcc];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0xcc] = 0;
  }
  param_1[5] = 0;
  FUN_00539d80();
  FUN_00539d80();
  return;
}


// 0053c0a0 FUN_0053c0a0

void __fastcall FUN_0053c0a0(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x14];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x14] = 0;
    *(undefined4 *)(param_1[200] + 0xc) = 0;
    *(undefined4 *)(param_1[200] + 8) = 0;
  }
  piVar1 = (int *)param_1[0xcc];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0xcc] = 0;
    *(undefined4 *)(param_1[0x180] + 0xc) = 0;
    *(undefined4 *)(param_1[0x180] + 8) = 0;
  }
  return;
}


// 0053c8c0 FUN_0053c8c0

void __fastcall FUN_0053c8c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar1 = param_1[8];
  iVar2 = param_1[iVar1 + 0xb];
  piVar3 = (int *)param_1[iVar1 * 0xb8 + 0x14];
  if (piVar3 != (int *)0x0) {
    piStack_4 = param_1;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar3);
    Mutex__Unlock();
    param_1[iVar1 * 0xb8 + 0x14] = 0;
    if ((int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x14] != (int *)0x0) {
      if (*(int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x14] != 0) {
        Csis__Class__GetRefCount(&stack0xfffffff8);
      }
      param_1[5] = 0;
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    return;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  return;
}


// 0053cce0 FUN_0053cce0

undefined4 __fastcall FUN_0053cce0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + param_1 + 800);
  param_1 = (*(int *)(param_1 + 0x20) - 1U & 1) * 0x2e0 + 0x50 + param_1;
  iVar2 = *(int *)(iVar1 + 0xc);
  if ((iVar2 != 1) || (bVar4 = true, *(int *)(*(int *)(param_1 + 0x2d0) + 8) != 0)) {
    bVar4 = false;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x2d0) + 0xc);
  if ((iVar3 == 1) && (*(int *)(iVar1 + 8) == 0)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if ((((iVar2 != 2) && (!bVar4)) && (iVar3 != 2)) && (!bVar5)) {
    return 0;
  }
  return 1;
}


// 0053ce30 FUN_0053ce30

void __thiscall
FUN_0053ce30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 uVar3;
  
  *(int *)(param_1 + 0x5f0) = param_1 + 0x548;
  *(int *)(param_1 + 0x30) = param_1 + 0x548;
  *(int *)(param_1 + 0x310) = param_1 + 0x268;
  *(int *)(param_1 + 0x2c) = param_1 + 0x268;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x50);
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x330);
  *(undefined4 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x5f4) = 0;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x5f8) = 0;
  uVar3 = param_8;
  (**(code **)(*(int *)(param_1 + 0x50) + 0x2c))(param_2,param_3,1,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x330) + 0x2c))
            (param_7,uVar3,1,unaff_ESI,unaff_EBP,unaff_EBX,param_8);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = 0x7f73;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  iVar2 = DAT_007356a8;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = 0x7f73;
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  piVar1[0x2f] = (int)&DAT_006f4b20;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f4b90;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// 0053d040 FUN_0053d040

uint __thiscall FUN_0053d040(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar1 = (int *)((int)param_2 * 0x2e0 + 0x40 + param_1);
  uVar3 = 0;
  if ((int *)*piVar1 != (int *)0x0) {
    param_2 = (int *)0x0;
    if ((*(int *)*piVar1 != 0) && (Csis__Class__GetRefCount(&param_2), 1 < (int)param_2)) {
      return 1;
    }
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_2);
      Mutex__Lock();
      (**(code **)(*param_2 + 4))(piVar2);
      Mutex__Unlock();
    }
    *piVar1 = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0xc) = 0;
    uVar3 = *(int *)(param_1 + 0x20) * 0x2e0;
    *(undefined4 *)(*(int *)(uVar3 + 0x310 + param_1) + 8) = 0;
  }
  return uVar3 & 0xffffff00;
}


// 0053d220 FUN_0053d220

void __fastcall FUN_0053d220(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piStack_4 = param_1;
  if ((int *)param_1[param_1[8] * 0xb8 + 0x10] != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (*(int *)param_1[param_1[8] * 0xb8 + 0x10] != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    param_1[6] = (int)piStack_4;
    if ((int)piStack_4 < param_1[5]) {
      piVar1 = (int *)param_1[param_1[8] * 0xb8 + 0x10];
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_4);
        Mutex__Lock();
        (**(code **)(*piStack_4 + 4))(piVar1);
        Mutex__Unlock();
      }
      param_1[param_1[8] * 0xb8 + 0x10] = 0;
      param_1[5] = param_1[6];
    }
  }
  EAXS_StreamControl__UpdateStreams();
  return;
}


// 0053d2c0 FUN_0053d2c0

void __fastcall FUN_0053d2c0(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x78) = 0;
  }
  if (*(int *)(param_1 + 800) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x78) = 0;
  }
  if (*(char *)(DAT_007356a8 + 0x70) != '\0') {
    *(undefined1 *)(DAT_007356a8 + 0x72) = 1;
  }
  return;
}


// 0053d760 FUN_0053d760

void __fastcall FUN_0053d760(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(DAT_007356ac + 0x395c) * iVar2 >> 0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// 0053d8a0 FUN_0053d8a0

void __thiscall FUN_0053d8a0(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)((int)param_2 * 0x2e0 + 0x40 + param_1);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&param_2);
    Mutex__Lock();
    (**(code **)(*param_2 + 4))(piVar2);
    Mutex__Unlock();
    *piVar1 = 0;
    *(undefined4 *)(piVar1[0xb4] + 8) = 0;
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  }
  return;
}


// 0053de90 FUN_0053de90

void __fastcall FUN_0053de90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piStack_4;
  
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if ((int *)*piVar1 == (int *)0x0) {
    return;
  }
  piStack_4 = (int *)0x0;
  if ((*(int *)*piVar1 != 0) && (Csis__Class__GetRefCount(&piStack_4), 1 < (int)piStack_4)) {
    (**(code **)(piVar1[4] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
    (**(code **)(*param_1 + 200))();
    return;
  }
  param_1[5] = (int)piStack_4;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar2);
    Mutex__Unlock();
  }
  *piVar1 = 0;
  *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  *(undefined4 *)(piVar1[0xb4] + 8) = 0;
  return;
}


// 0053e9b0 FUN_0053e9b0

undefined4 FUN_0053e9b0(int param_1,int param_2)

{
  if ((*(uint *)(param_1 + 8) <= *(uint *)(param_2 + 8)) &&
     ((*(uint *)(param_2 + 8) != *(uint *)(param_1 + 8) ||
      (*(uint *)(param_1 + 0x10) <= *(uint *)(param_2 + 0x10))))) {
    return 1;
  }
  return 0;
}


// 0053f3a0 FUN_0053f3a0

void FUN_0053f3a0(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
  pcVar2 = *(code **)(*(int *)(param_1 + 0x8c) + 8);
  *(undefined4 *)(param_1 + 0x90) = 1;
  FUN_00565ce0();
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(uVar1);
  }
  return;
}


// 00540580 FUN_00540580

void FUN_00540580(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = Solid_FindInAllLists();
  if (iVar1 != 0) {
    SolidList_Release(param_1,*(undefined4 *)(param_3 + 0xb4));
  }
  return;
}


// 00546e60 FUN_00546e60

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


// 0054d020 FUN_0054d020

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


// 0054dc50 FUN_0054dc50

void FUN_0054dc50(undefined4 param_1,int param_2)

{
  DAT_00734f84 = *(undefined4 *)(param_2 + 8);
  (*DAT_00734fc8)();
  DAT_00734fc8 = (code *)0x0;
  return;
}


// 0054ee60 FUN_0054ee60

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
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xc407210) {
        iVar2 = FUN_004f65d0();
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
        FUN_0054ab80(&LAB_0054f860);
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
      iVar2 = FUN_004f65d0();
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
      uVar3 = FUN_004abd40(&DAT_00748f70);
      bSPrintf_regdst(0x40,&DAT_006cc578,uVar3,puVar7);
      FUN_0054a5e0(&LAB_0054f7a0);
      return;
    }
    if (DAT_00777cb4 < 3) {
      DAT_00777cb4 = DAT_00777cb4 + 1;
    }
  }
  DAT_00777cc8 = FUN_0054ee20();
  return;
}


// 0054fd00 FUN_0054fd00

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


// 00557760 FUN_00557760

void FUN_00557760(void)

{
  DAT_00734dbc = 0;
  FUN_005576f0();
  return;
}


// 0055c840 FUN_0055c840

void __thiscall
FUN_0055c840(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = 0;
  do {
    cVar2 = FUN_0041f240(param_3,param_4,param_5);
    iVar5 = DAT_0073578c;
    if (cVar2 != '\0') {
      return;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  if (0xc407210 < param_2) {
    if (param_2 == 0x911ab364) {
      if (((DAT_0073578c != 0) && (iVar7 = FEPackageList__FindByName(&DAT_00746104), iVar7 != 0)) &&
         (*(int *)(iVar7 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar5 + 8),*(int *)(iVar7 + 0x18));
      }
    }
    else if (param_2 == 0xc519bfc0) {
      if (param_3 != 0) {
        iVar7 = 0;
        piVar6 = (int *)(param_1 + 0x40);
        do {
          if (*piVar6 == param_3) {
            FUN_0055c790();
            return;
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar7 < 4);
        return;
      }
    }
    else if (param_2 == 0xc98356ba) {
      if ((DAT_00734998 == 1) || (DAT_00734998 == 2)) {
        FUN_00495f70();
      }
      if (*(char *)(param_1 + 0x61) != '\0') {
        FUN_0054d590();
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      }
      FUN_0055cd50();
      FUN_0054d630();
      return;
    }
switchD_0055c898_default:
    return;
  }
  if (param_2 == 0xc407210) {
    if (param_3 == 0) {
      return;
    }
    iVar7 = 0;
    piVar6 = (int *)(param_1 + 0x40);
    do {
      if (*piVar6 == param_3) {
        FUN_0055c6e0();
        return;
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar7 < 4);
    return;
  }
  switch(param_2) {
  case 1:
    pcVar1 = (char *)(param_1 + 0x54);
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined1 *)(param_1 + 0x60) = 0;
    iVar7 = 0xc;
    pcVar4 = pcVar1;
    do {
      cVar2 = pcVar4[(int)&DAT_00777b74 - (int)pcVar1];
      iVar7 = iVar7 + -1;
      *pcVar4 = cVar2;
      if (cVar2 == '\0') break;
      pcVar4 = pcVar4 + 1;
    } while (iVar7 != 0);
    FUN_004ebcb0();
    FUN_0054d920(pcVar1,&LAB_0055cdc0);
    return;
  case 2:
    if (DAT_00735da4 != 0) {
      FUN_004ebdf0(DAT_00735da4,0);
    }
    iVar7 = DAT_00734f84;
    if (DAT_00734f84 == 0) {
      FUN_004f6850(param_1 + 0x54);
      FUN_0054dd10();
      FUN_004ebcb0();
      bStrCpy();
      FUN_0054da00(param_1 + 0x54,&LAB_0055ce00);
      return;
    }
    iVar5 = LanguageStrings__FindByHash();
    if (iVar5 == 0) {
      iVar5 = LanguageStrings__FindByHash();
    }
    FUN_004f6850(iVar5);
    if (iVar7 < 0x69706573) {
      if (iVar7 == 0x69706572) goto LAB_0055cbfc;
      if (iVar7 < 0x66696c75) {
        if (((iVar7 == 0x66696c74) || (iVar7 == 0x64626572)) || (iVar7 == 0x6475706c))
        goto LAB_0055cbfc;
      }
      else if (iVar7 == 0x696e616d) goto LAB_0055cbfc;
    }
    else if (((iVar7 == 0x6d617574) || (iVar7 == 0x6d617870)) || (iVar7 == 0x74696d65))
    goto LAB_0055cbfc;
    FUN_0054d4a0(&DAT_0073d868,iVar7);
    goto LAB_0055cbfc;
  case 3:
    FUN_004ebcb0();
    uVar3 = bStrCpy();
    FUN_0054d990(uVar3,&LAB_0055cde0);
    return;
  case 4:
    if (DAT_00735da4 != 0) {
      FUN_004ebdf0(DAT_00735da4,0);
    }
    if (DAT_00734f84 == 0) {
      (&DAT_00734f90)[*(int *)(param_1 + 0x50) * 0xd] = 0;
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      return;
    }
    if (DAT_00734f84 < 0x6c6f676f) {
      if (((DAT_00734f84 == 0x6c6f676e) || (DAT_00734f84 == 0x64626572)) ||
         (DAT_00734f84 == 0x69706572)) goto LAB_0055cbfc;
    }
    else {
      if (DAT_00734f84 == 0x6d617574) goto LAB_0055cbfc;
LAB_0055cb3e:
      if (DAT_00734f84 == 0x74696d65) goto LAB_0055cbfc;
    }
    break;
  case 5:
    if (DAT_00735da4 != 0) {
      FUN_004ebdf0(DAT_00735da4,0);
    }
    if (DAT_00734f84 == 0) {
      bStrCpy();
      *(undefined1 *)(param_1 + 0x61) = 1;
      return;
    }
    if (0x6d617574 < DAT_00734f84) {
      if ((DAT_00734f84 == 0x6e6f776e) || (DAT_00734f84 == 0x70736574)) goto LAB_0055cbfc;
      goto LAB_0055cb3e;
    }
    if ((DAT_00734f84 == 0x6d617574) ||
       (((DAT_00734f84 == 0x64626572 || (DAT_00734f84 == 0x69706572)) ||
        (DAT_00734f84 == 0x6c6f636b)))) goto LAB_0055cbfc;
    break;
  default:
    goto switchD_0055c898_default;
  }
  FUN_0054d4a0(&DAT_0073d868,DAT_00734f84);
LAB_0055cbfc:
  FUN_004eba00(0,0);
  return;
}


// 0055cdc0 FUN_0055cdc0

void FUN_0055cdc0(void)

{
  FUN_004f6570();
  return;
}


// 0055cde0 FUN_0055cde0

void FUN_0055cde0(void)

{
  FUN_004f6570();
  return;
}


// 0055ce00 FUN_0055ce00

void FUN_0055ce00(void)

{
  FUN_004f6570();
  return;
}


// 005669d0 FUN_005669d0

void FUN_005669d0(undefined1 param_1,int *param_2)

{
  if (DAT_00730508 != (undefined1 *)0x0) {
    *DAT_00730508 = param_1;
    DAT_00730508 = DAT_00730508 + 1;
  }
  *param_2 = *param_2 + 1;
  return;
}


// 00567f80 FUN_00567f80

void __thiscall FUN_00567f80(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == 0xc407210) {
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0x8ff66b6e) {
      if (uVar1 == 0x8ff66b6d) {
        FUN_00568250(param_1);
        return;
      }
      if (uVar1 < 0x3c98f9fe) {
        if (uVar1 == 0x3c98f9fd) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0x1496bd) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0x29321f5) {
          FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (uVar1 == 0x2a79098) {
          FUN_00568250(param_1);
          return;
        }
      }
      else {
        if (uVar1 == 0x3c98f9fe) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0x7961bb6b) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0x7a77cfbf) {
          FUN_00568250(param_1);
          return;
        }
      }
    }
    else if (uVar1 < 0xbeb8147c) {
      if (uVar1 != 0xbeb8147b) {
        if (uVar1 == 0x8ff66b6e) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0x8ff66b6f) {
          FUN_00568250(param_1);
          return;
        }
        if (uVar1 == 0xa2a14134) {
          FUN_00568250(param_1);
          return;
        }
      }
    }
    else if (uVar1 == 0xd6d5fc16) {
      FUN_00568250(param_1);
    }
    else if (uVar1 == 0xe976b192) {
      FUN_00568250(param_1);
      return;
    }
  }
  else if (param_2 == -0x3ae64040) {
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0x8ff66b6e) {
      if (uVar1 == 0x8ff66b6d) {
        FUN_005682a0(param_1);
        return;
      }
      if (uVar1 < 0x3c98f9ff) {
        if (uVar1 == 0x3c98f9fe) {
          FUN_005682a0(param_1);
          return;
        }
        if (uVar1 == 0x1496bd) {
          FUN_005682a0(param_1);
          return;
        }
        if (uVar1 == 0x2a79098) {
          FUN_005682a0(param_1);
          return;
        }
        if (uVar1 == 0x3c98f9fd) {
          FUN_005682a0(param_1);
          return;
        }
      }
      else {
        if (uVar1 == 0x7961bb6b) {
          FUN_005682a0(param_1);
          return;
        }
        if (uVar1 == 0x7a77cfbf) {
          FUN_005682a0(param_1);
          return;
        }
      }
    }
    else if (uVar1 < 0xd6d5fc17) {
      if (uVar1 == 0xd6d5fc16) {
        FUN_005682a0(param_1);
        return;
      }
      if (uVar1 == 0x8ff66b6e) {
        FUN_005682a0(param_1);
        return;
      }
      if (uVar1 == 0x8ff66b6f) {
        FUN_005682a0(param_1);
        return;
      }
      if (uVar1 == 0xa2a14134) {
        FUN_005682a0(param_1);
        return;
      }
    }
    else {
      if (uVar1 == 0xda63d476) {
        DAT_00734978 = DAT_00734978 + 1;
        if (2 < DAT_00734978) {
          DAT_00734978 = 0;
        }
        FUN_005682d0();
        return;
      }
      if (uVar1 == 0xe976b192) {
        FUN_005682a0(param_1);
        return;
      }
    }
  }
  return;
}


// 00571560 FUN_00571560

void __fastcall FUN_00571560(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00734610;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    piVar1 = (int *)*param_1;
    *param_1 = *piVar1;
    if ((int *)param_1[1] == piVar1) {
      param_1[1] = (int)param_1;
    }
    iVar2 = *(int *)(iVar3 + 0x18);
    *piVar1 = *(undefined4 *)(iVar3 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(int **)(iVar3 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// 00574553 FUN_00574553

int FUN_00574553(void)

{
  int in_stack_00000010;
  
  if ((*(int *)(in_stack_00000010 + 0x18) == 0xff) && (*(int *)(in_stack_00000010 + 0x1c) == 0)) {
    return 0;
  }
  *(undefined4 *)(in_stack_00000010 + 0x18) = 0xff;
  *(undefined4 *)(in_stack_00000010 + 0x1c) = 0;
  return *(int *)(in_stack_00000010 + 8) + 0xff00;
}


// 00574852 FUN_00574852

int __fastcall FUN_00574852(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(int *)(param_2 + 0x18) = in_EAX;
  return in_EAX * 0x100 + *(int *)(param_2 + 8);
}


// 00577367 FUN_00577367

undefined4 FUN_00577367(void)

{
  int in_EAX;
  
  return CONCAT31((int3)((uint)(in_EAX + -1) >> 8),(char)(in_EAX + -1) + -0x18);
}


// 00578de0 FUN_00578de0

void * __thiscall FUN_00578de0(void *param_1,byte param_2)

{
  FUN_00578e00();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00583230 FUN_00583230

void FUN_00583230(void)

{
  AIGoal__Create(4);
  return;
}


// 00583c00 FUN_00583c00

void __fastcall FUN_00583c00(int param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x3fc) + 0xc))();
  if (cVar1 != '\0') {
    FUN_0044bcb0();
    (**(code **)(**(int **)(param_1 + 8) + 0x38))(0,0,0,1);
    *(undefined1 *)(param_1 + 0x410) = 1;
  }
  return;
}


// 00585353 FUN_00585353

/* WARNING: Control flow encountered bad instruction data */

void FUN_00585353(void)

{
  char *in_EAX;
  
  *in_EAX = *in_EAX + (char)in_EAX;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// 00588180 FUN_00588180

void __thiscall FUN_00588180(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  param_2[1] = *(undefined4 *)(param_1 + 0x20);
  return;
}


// 005881c0 FUN_005881c0

void __thiscall FUN_005881c0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TwoWheelAckermanSteering");
  FUN_00571d90();
  FUN_00571d90();
  FUN_00571c20(param_2,param_1 + 0x90,2,2,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// 00592850 FUN_00592850

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


// 005928c0 FUN_005928c0

undefined4 * __fastcall FUN_005928c0(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return (undefined4 *)(*(int *)(param_1 + 0x6c) + 0xb0);
  }
  return &DAT_007372a0;
}


// 005928e0 FUN_005928e0

int __fastcall FUN_005928e0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0x30;
  }
  iVar1 = FUN_00578730();
  return iVar1;
}


// 00594820 FUN_00594820

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


// 00595140 FUN_00595140

void __fastcall FUN_00595140(int param_1)

{
  if (*(char *)(param_1 + 0x4c2) != '\0') {
    FUN_00584e30();
  }
  return;
}


// 005951a0 FUN_005951a0

undefined4 * __fastcall FUN_005951a0(int param_1)

{
  int iVar1;
  
  if (*(float *)(param_1 + 0x15c) != DAT_006cc7a4) {
    return &DAT_00779c30;
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (*(int *)(iVar1 + 0x138) != 0) {
    return (undefined4 *)(iVar1 + 400);
  }
  return (undefined4 *)(iVar1 + 0x150);
}


// 005951e0 FUN_005951e0

undefined4 __fastcall FUN_005951e0(int param_1)

{
  if (*(float *)(param_1 + 0x15c) == DAT_006cc7a4) {
    return 1;
  }
  return 0;
}


// 005a2c00 FUN_005a2c00

undefined4 __fastcall FUN_005a2c00(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x5864) != 0) {
    uVar1 = *(int *)(param_1 + 0x5864) + 0xb0c;
    uVar1 = -(uint)(uVar1 < (uint)(*(int *)(param_1 + 0x5868) * 0xb0c + 4 + param_1)) & uVar1;
    return CONCAT31((int3)(uVar1 >> 8),uVar1 != 0);
  }
  return 0;
}


// 005a2ca0 FUN_005a2ca0

void __fastcall FUN_005a2ca0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = Race__DidPlayerWin(param_1,0);
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x59ec) = 1;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x5868)) {
    iVar3 = param_1 + 4;
    do {
      if ((((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0x5868))) && (iVar2 < 8)) && (iVar3 != 0)) {
        *(undefined4 *)(iVar3 + 0x14) = 1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xb0c;
    } while (iVar2 < *(int *)(param_1 + 0x5868));
  }
  if (*(int *)(param_1 + 0x5868) < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + 4;
  }
  *(int *)(param_1 + 0x5864) = iVar2;
  if (*(int *)(param_1 + 0x58a4) != 7) {
    return;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x589c)) {
    iVar3 = param_1 + 0x586c;
    do {
      if ((iVar2 < 0) || (iVar4 = iVar3, *(int *)(param_1 + 0x589c) <= iVar2)) {
        iVar4 = 0;
      }
      *(undefined4 *)(iVar4 + 8) = 1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < *(int *)(param_1 + 0x589c));
  }
  iVar2 = 0;
  if (0 < DAT_0078a41c) {
    iVar3 = 0;
    do {
      if ('\0' < *(char *)(DAT_0078a418 + iVar3)) {
        iVar4 = *(int *)((undefined1 *)(DAT_0078a418 + iVar3) + 4);
        if (iVar4 == 1) {
          DAT_0078a320 = DAT_0078a320 + 1;
        }
        else if (iVar4 == 2) {
          DAT_0078a324 = DAT_0078a324 + 1;
        }
        *(undefined1 *)(DAT_0078a418 + iVar3) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x750;
    } while (iVar2 < DAT_0078a41c);
  }
  return;
}


// 005a3280 FUN_005a3280

void __fastcall FUN_005a3280(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x5864);
  *(undefined4 *)(iVar1 + 0x14) = 3;
  FUN_0059ffd0(iVar1 + 0x28,&DAT_00777cd0);
  iVar1 = *(int *)(param_1 + 0x5864);
  iVar4 = iVar1 + 0x28;
  if (*(int *)(param_1 + 0x58a8) == 3) {
    puVar5 = (undefined4 *)(*(int *)(iVar1 + 0xb08) * 0x15c + iVar4);
    uVar2 = FUN_0043eaa0(100);
    *puVar5 = uVar2;
    puVar5[1] = 100;
    iVar3 = *(int *)(iVar1 + 0xb08) + 1;
    *(int *)(iVar1 + 0xb08) = iVar3;
    puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
    uVar2 = FUN_0043eaa0(0x65);
    *puVar5 = uVar2;
    puVar5[1] = 0x65;
    iVar3 = *(int *)(iVar1 + 0xb08) + 1;
    *(int *)(iVar1 + 0xb08) = iVar3;
    puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
    uVar2 = FUN_0043eaa0(0x66);
    *puVar5 = uVar2;
    puVar5[1] = 0x66;
    *(int *)(iVar1 + 0xb08) = *(int *)(iVar1 + 0xb08) + 1;
  }
  return;
}


// 005a4980 FUN_005a4980

uint FUN_005a4980(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = FUN_00565b60(param_2 + 0x100 + param_4,0,0,0x2008);
  uVar4 = iVar2 + 0x80U & 0xffffff80;
  if (param_4 != 0) {
    uVar4 = uVar4 + (0x80 - param_4);
  }
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[2] = iVar2;
    puVar3[3] = uVar4;
  }
  *DAT_007373a0 = puVar3;
  puVar1 = puVar3;
  puVar3[1] = DAT_007373a0;
  DAT_007373a0 = puVar1;
  *puVar3 = &DAT_0073739c;
  return uVar4;
}


// 005a6f80 FUN_005a6f80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005a6f80(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float unaff_retaddr;
  
  iVar4 = (**(code **)(*param_1 + 8))(param_3);
  fVar2 = _DAT_006b5934;
  if ((-1 < param_3) && (param_3 < 5)) {
    fVar2 = _DAT_006b5930;
  }
  fVar3 = (float)((int)*(short *)(param_3 + 0x3c + iVar4 * 2) << 8) * _DAT_006cc83c;
  fVar1 = fVar2 - (*(float *)(param_3 + 0x24) + fVar3);
  fVar2 = (*(float *)(param_3 + 0x28) - fVar3) - fVar2;
  if (fVar1 < unaff_retaddr) {
    fVar1 = unaff_retaddr;
  }
  if (fVar1 <= fVar2) {
    *param_2 = fVar1;
    return;
  }
  *param_2 = fVar2;
  return;
}


// 005a7960 FUN_005a7960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_005a7960(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float unaff_retaddr;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)DAT_006cc7a4;
  if ((cVar1 != -1) && (*(short *)((int)param_1 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    iVar2 = *(short *)((int)param_1 + 0x5e) * 0x88 + 0x27c + iVar2;
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*param_1 + 0x10))(param_2);
      fVar4 = -(float10)*(float *)(iVar2 + 0x24) -
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)_DAT_006cc83c +
              (float10)unaff_retaddr);
    }
  }
  return fVar4;
}


// 005ab766 FUN_005ab766

void FUN_005ab766(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab76d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba4)();
  return;
}


// 005ab802 FUN_005ab802

void FUN_005ab802(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab809. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba8)();
  return;
}


// 005ab8b4 FUN_005ab8b4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab8b4(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab8bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b78)();
  return;
}


// 005ac06e FUN_005ac06e

void FUN_005ac06e(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b00)();
  return;
}


// 005ac16b FUN_005ac16b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac16b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ae0)();
  return;
}


// 005ac5b8 FUN_005ac5b8

void FUN_005ac5b8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac5bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4aec)();
  return;
}


// 005ac8eb FUN_005ac8eb

void FUN_005ac8eb(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  param_1[1] = param_2[4];
  param_1[4] = uVar1;
  uVar1 = param_2[2];
  param_1[2] = param_2[8];
  param_1[8] = uVar1;
  uVar1 = param_2[3];
  param_1[3] = param_2[0xc];
  param_1[0xc] = uVar1;
  uVar1 = param_2[6];
  param_1[6] = param_2[9];
  param_1[9] = uVar1;
  uVar1 = param_2[7];
  param_1[7] = param_2[0xd];
  param_1[0xd] = uVar1;
  uVar1 = param_2[0xb];
  param_1[0xb] = param_2[0xe];
  param_1[0xe] = uVar1;
  if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[5] = param_2[5];
    param_1[10] = param_2[10];
    param_1[0xf] = param_2[0xf];
  }
  return;
}


// 005ac958 FUN_005ac958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac958(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac95f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad0)();
  return;
}


// 005acf7b FUN_005acf7b

void FUN_005acf7b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[0xe] = 0;
  *param_1 = param_2;
  param_1[0xd] = 0;
  param_1[5] = param_3;
  param_1[0xc] = 0;
  param_1[10] = param_4;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}


// 005ad005 FUN_005ad005

void FUN_005ad005(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[0xb] = 0;
  param_1[0xc] = param_2;
  param_1[9] = 0;
  param_1[0xd] = param_3;
  param_1[8] = 0;
  param_1[0xe] = param_4;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[10] = 0x3f800000;
  param_1[5] = 0x3f800000;
  *param_1 = 0x3f800000;
  return;
}


// 005ad589 FUN_005ad589

void FUN_005ad589(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b2c)();
  return;
}


// 005ad596 FUN_005ad596

void FUN_005ad596(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad59d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b30)();
  return;
}


// 005ad5a3 FUN_005ad5a3

void FUN_005ad5a3(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad5aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b1c)();
  return;
}


// 005ad5b0 FUN_005ad5b0

void FUN_005ad5b0(undefined4 *param_1,undefined4 *param_2,float *param_3)

{
  float10 fVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
  }
  if (param_3 != (float *)0x0) {
    fVar1 = (float10)FUN_00672e20();
    *param_3 = (float)(fVar1 + fVar1);
  }
  return;
}


// 005ad5e5 FUN_005ad5e5

void FUN_005ad5e5(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad5ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b20)();
  return;
}


// 005ad8c2 FUN_005ad8c2

float * FUN_005ad8c2(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[3];
  fVar2 = param_2[2];
  fVar3 = param_3[3];
  fVar4 = param_2[1];
  fVar5 = param_3[3];
  fVar6 = param_2[3];
  fVar7 = *param_3;
  fVar8 = param_2[1];
  fVar9 = *param_3;
  fVar10 = param_2[2];
  fVar11 = *param_3;
  fVar12 = *param_2;
  fVar13 = param_3[1];
  fVar14 = *param_2;
  fVar15 = param_3[1];
  fVar16 = param_2[3];
  fVar17 = param_3[1];
  fVar18 = param_2[1];
  fVar19 = param_3[2];
  fVar20 = param_2[3];
  fVar21 = param_3[2];
  fVar22 = *param_2;
  fVar23 = param_3[2];
  fVar24 = param_2[2];
  *param_1 = (param_3[1] * param_2[2] + *param_3 * param_2[3] + param_3[3] * *param_2) -
             param_3[2] * param_2[1];
  param_1[1] = fVar21 * fVar22 + fVar15 * fVar16 + (fVar3 * fVar4 - fVar9 * fVar10);
  param_1[2] = fVar19 * fVar20 + ((fVar7 * fVar8 + fVar1 * fVar2) - fVar13 * fVar14);
  param_1[3] = ((fVar5 * fVar6 - fVar11 * fVar12) - fVar17 * fVar18) - fVar23 * fVar24;
  return param_1;
}


// 005ad958 FUN_005ad958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad958(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad95f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b10)();
  return;
}


// 005adb00 FUN_005adb00

void FUN_005adb00(void)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  int iVar4;
  float *extraout_ECX;
  int unaff_EBP;
  float *unaff_ESI;
  float10 fVar5;
  float10 in_ST1;
  
  *(float *)(unaff_EBP + -4) = (float)in_ST1;
  pfVar1 = *(float **)(unaff_EBP + -8);
  fVar2 = (float10)fcos((float10)*(float *)(unaff_EBP + -4));
  fVar5 = (float10)fsin((float10)*(float *)(unaff_EBP + -4));
  **(float **)(unaff_EBP + 8) = (float)fVar2;
  *pfVar1 = (float)fVar5;
  iVar4 = FUN_005ab736(*(undefined4 *)(unaff_EBP + 0xc),0);
  if (iVar4 == 0) {
    fVar3 = *(float *)(unaff_EBP + 0xc) / *(float *)(unaff_EBP + -4);
    *unaff_ESI = fVar3 * *extraout_ECX;
    unaff_ESI[1] = fVar3 * extraout_ECX[1];
    unaff_ESI[2] = fVar3 * extraout_ECX[2];
  }
  else if (unaff_ESI != extraout_ECX) {
    *unaff_ESI = *extraout_ECX;
    unaff_ESI[1] = extraout_ECX[1];
    unaff_ESI[2] = extraout_ECX[2];
  }
  return;
}


// 005ade6c FUN_005ade6c

void FUN_005ade6c(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ade73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b18)();
  return;
}


// 005adf1b FUN_005adf1b

void FUN_005adf1b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005adf22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4af0)();
  return;
}


// 005adf28 FUN_005adf28

void FUN_005adf28(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  param_1[3] = -(*param_2 * *param_3 + param_2[2] * param_3[2] + param_2[1] * param_3[1]);
  return;
}


// 005ae00f FUN_005ae00f

void FUN_005ae00f(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ae016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b48)();
  return;
}


// 005af60b FUN_005af60b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af60b(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7)

{
  undefined1 auStack_a4 [16];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_84 = *param_4;
  fStack_80 = param_4[1];
  fStack_7c = param_4[2];
  fStack_78 = param_4[3];
  fStack_54 = *param_5;
  fStack_50 = param_5[1];
  fStack_4c = param_5[2];
  fStack_48 = param_5[3];
  fStack_24 = *param_6;
  fStack_20 = param_6[1];
  fStack_1c = param_6[2];
  fStack_18 = param_6[3];
  fStack_74 = *param_7;
  fStack_70 = param_7[1];
  fStack_6c = param_7[2];
  fStack_68 = param_7[3];
  if ((fStack_54 + fStack_84) * (fStack_54 + fStack_84) +
      (fStack_50 + fStack_80) * (fStack_50 + fStack_80) +
      (fStack_4c + fStack_7c) * (fStack_4c + fStack_7c) +
      (fStack_48 + fStack_78) * (fStack_48 + fStack_78) <
      (fStack_84 - fStack_54) * (fStack_84 - fStack_54) +
      (fStack_80 - fStack_50) * (fStack_80 - fStack_50) +
      (fStack_7c - fStack_4c) * (fStack_7c - fStack_4c) +
      (fStack_78 - fStack_48) * (fStack_78 - fStack_48)) {
    fStack_84 = -fStack_84;
    fStack_80 = -fStack_80;
    fStack_7c = -fStack_7c;
    fStack_78 = -fStack_78;
    fStack_34 = fStack_84;
    fStack_30 = fStack_80;
    fStack_2c = fStack_7c;
    fStack_28 = fStack_78;
  }
  if ((fStack_24 + fStack_54) * (fStack_24 + fStack_54) +
      (fStack_20 + fStack_50) * (fStack_20 + fStack_50) +
      (fStack_1c + fStack_4c) * (fStack_1c + fStack_4c) +
      (fStack_18 + fStack_48) * (fStack_18 + fStack_48) <
      (fStack_54 - fStack_24) * (fStack_54 - fStack_24) +
      (fStack_50 - fStack_20) * (fStack_50 - fStack_20) +
      (fStack_4c - fStack_1c) * (fStack_4c - fStack_1c) +
      (fStack_48 - fStack_18) * (fStack_48 - fStack_18)) {
    fStack_34 = -fStack_24;
    fStack_30 = -fStack_20;
    fStack_2c = -fStack_1c;
    fStack_28 = -fStack_18;
    fStack_24 = fStack_34;
    fStack_20 = fStack_30;
    fStack_1c = fStack_2c;
    fStack_18 = fStack_28;
  }
  fStack_10 = fStack_20 - fStack_70;
  fStack_c = fStack_1c - fStack_6c;
  fStack_8 = fStack_18 - fStack_68;
  if ((fStack_74 + fStack_24) * (fStack_74 + fStack_24) +
      (fStack_70 + fStack_20) * (fStack_70 + fStack_20) +
      (fStack_6c + fStack_1c) * (fStack_6c + fStack_1c) +
      (fStack_68 + fStack_18) * (fStack_68 + fStack_18) <
      (fStack_24 - fStack_74) * (fStack_24 - fStack_74) +
      fStack_10 * fStack_10 + fStack_c * fStack_c + fStack_8 * fStack_8) {
    fStack_74 = -fStack_74;
    fStack_70 = -fStack_70;
    fStack_6c = -fStack_6c;
    fStack_68 = -fStack_68;
    fStack_34 = fStack_74;
    fStack_30 = fStack_70;
    fStack_2c = fStack_6c;
    fStack_28 = fStack_68;
  }
  thunk_FUN_005ad965(&fStack_34,&fStack_54);
  thunk_FUN_005ad8af(&fStack_44,&fStack_34,&fStack_84);
  fStack_64 = fStack_44;
  fStack_60 = fStack_40;
  fStack_5c = fStack_3c;
  fStack_58 = fStack_38;
  thunk_FUN_005ada29(&fStack_94,&fStack_64);
  thunk_FUN_005ad8af(&fStack_44,&fStack_34,&fStack_24);
  fStack_64 = fStack_44;
  fStack_60 = fStack_40;
  fStack_5c = fStack_3c;
  fStack_58 = fStack_38;
  thunk_FUN_005ada29(&fStack_14,&fStack_64);
  fStack_40 = fStack_90 + fStack_10;
  fStack_3c = fStack_8c + fStack_c;
  fStack_64 = (fStack_94 + fStack_14) * _DAT_006ccb1c;
  fStack_60 = fStack_40 * _DAT_006ccb1c;
  fStack_5c = fStack_3c * _DAT_006ccb1c;
  fStack_58 = (fStack_88 + fStack_8) * _DAT_006ccb1c;
  thunk_FUN_005adab7(auStack_a4,&fStack_64);
  thunk_FUN_005ad8af(&fStack_44,&fStack_54,auStack_a4);
  *param_1 = fStack_44;
  param_1[1] = fStack_40;
  param_1[2] = fStack_3c;
  param_1[3] = fStack_38;
  thunk_FUN_005ad965(&fStack_34,&fStack_24);
  thunk_FUN_005ad8af(&fStack_44,&fStack_34,&fStack_54);
  fStack_64 = fStack_44;
  fStack_60 = fStack_40;
  fStack_5c = fStack_3c;
  fStack_58 = fStack_38;
  thunk_FUN_005ada29(&fStack_94,&fStack_64);
  thunk_FUN_005ad8af(&fStack_44,&fStack_34,&fStack_74);
  fStack_64 = fStack_44;
  fStack_60 = fStack_40;
  fStack_5c = fStack_3c;
  fStack_58 = fStack_38;
  thunk_FUN_005ada29(&fStack_14,&fStack_64);
  fStack_40 = fStack_90 + fStack_10;
  fStack_3c = fStack_8c + fStack_c;
  fStack_64 = (fStack_94 + fStack_14) * _DAT_006ccb1c;
  fStack_60 = fStack_40 * _DAT_006ccb1c;
  fStack_5c = fStack_3c * _DAT_006ccb1c;
  fStack_58 = (fStack_88 + fStack_8) * _DAT_006ccb1c;
  thunk_FUN_005adab7(auStack_a4,&fStack_64);
  thunk_FUN_005ad8af(&fStack_44,&fStack_24,auStack_a4);
  *param_2 = fStack_44;
  param_2[1] = fStack_40;
  param_2[2] = fStack_3c;
  param_2[3] = fStack_38;
  *param_3 = fStack_24;
  param_3[1] = fStack_20;
  param_3[2] = fStack_1c;
  param_3[3] = fStack_18;
  return;
}


// 005b0153 FUN_005b0153

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b0153(uint param_1,int param_2,uint param_3,float *param_4,float *param_5,float *param_6
                 ,float *param_7,uint param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  float afStack_1cc [68];
  float afStack_bc [10];
  float fStack_94;
  float fStack_90;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_7c = *param_5;
  fStack_78 = param_5[1];
  fStack_74 = param_5[2];
  fStack_34 = *param_6;
  fStack_30 = param_6[1];
  fStack_2c = param_6[2];
  fStack_10 = *param_7;
  fStack_c = param_7[1];
  fStack_8 = param_7[2];
  FUN_005b00b6(&fStack_34,&fStack_7c,param_1,_DAT_006cca58,&fStack_70);
  FUN_005b00b6(&fStack_10,&fStack_7c,param_1,_DAT_006cca58,&fStack_64);
  FUN_005b00b6(&fStack_7c,&fStack_34,param_1 + 0xc,_DAT_006cca58,&fStack_58);
  FUN_005b00b6(&fStack_7c,&fStack_10,param_1 + 0x18,_DAT_006cca58,&fStack_40);
  FUN_005b00b6(&fStack_10,&fStack_34,param_1 + 0xc,_DAT_006cca58,&fStack_28);
  FUN_005b00b6(&fStack_34,&fStack_10,param_1 + 0x18,_DAT_006cca58,&fStack_1c);
  fVar5 = _DAT_006cc7ac;
  fStack_94 = fStack_10 + fStack_34 + fStack_7c;
  fStack_90 = fStack_c + fStack_30 + fStack_78;
  param_1 = 0;
  fStack_80 = (fStack_8 + fStack_2c + fStack_74) * _DAT_00699490;
  fStack_4c = (fStack_1c + fStack_28 + fStack_40 + fStack_58 + fStack_70 + fStack_64) *
              _DAT_006cc90c - fStack_94 * _DAT_00699490;
  fStack_48 = (fStack_18 + fStack_24 + fStack_3c + fStack_54 + fStack_60 + fStack_6c) *
              _DAT_006cc90c - fStack_90 * _DAT_00699490;
  fStack_44 = (fStack_14 + fStack_20 + fStack_38 + fStack_50 + fStack_5c + fStack_68) *
              _DAT_006cc90c - fStack_80;
  if (param_3 != 0) {
    do {
      fVar1 = *(float *)(param_1 * 8 + param_2);
      uVar7 = 0;
      fVar2 = *(float *)(param_1 * 8 + 4 + param_2);
      fVar3 = (1.0 - fVar1) - fVar2;
      afStack_bc[0] = fVar2 * fVar2 * fVar2;
      afStack_bc[1] = fVar3 * fVar2 * fVar2 * fVar5;
      afStack_bc[2] = fVar2 * fVar2 * fVar1 * fVar5;
      fVar4 = fVar3 * fVar3;
      afStack_bc[3] = fVar4 * fVar2 * fVar5;
      afStack_bc[4] = fVar3 * fVar2 * fVar1 * _DAT_006cc7a8;
      afStack_bc[5] = fVar2 * fVar1 * fVar1 * fVar5;
      afStack_bc[6] = fVar4 * fVar3;
      afStack_bc[7] = fVar4 * fVar1 * fVar5;
      afStack_bc[8] = fVar3 * fVar1 * fVar1 * fVar5;
      afStack_bc[9] = fVar1 * fVar1 * fVar1;
      afStack_1cc[0] = 0.0;
      afStack_1cc[1] = 0.0;
      afStack_1cc[2] = 0.0;
      pfVar6 = &fStack_78;
      do {
        pfVar9 = afStack_bc + uVar7;
        uVar7 = uVar7 + 1;
        afStack_1cc[0] = pfVar6[-1] * *pfVar9 + afStack_1cc[0];
        afStack_1cc[1] = *pfVar9 * *pfVar6 + afStack_1cc[1];
        afStack_1cc[2] = pfVar6[1] * *pfVar9 + afStack_1cc[2];
        pfVar6 = pfVar6 + 3;
      } while (uVar7 < 10);
      if (3 < param_8) {
        pfVar6 = param_6 + 3;
        iVar8 = param_8 - 3;
        do {
          *(float *)((int)pfVar6 + ((int)afStack_1cc - (int)param_6)) =
               fVar3 * *pfVar6 +
               fVar2 * *(float *)((int)pfVar6 + ((int)param_5 - (int)param_6)) +
               fVar1 * *(float *)((int)pfVar6 + ((int)param_7 - (int)param_6));
          pfVar6 = pfVar6 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      pfVar6 = afStack_1cc;
      pfVar9 = param_4;
      for (uVar7 = param_8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pfVar9 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar9 = pfVar9 + 1;
      }
      param_1 = param_1 + 1;
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)pfVar9 = *(undefined1 *)pfVar6;
        pfVar6 = (float *)((int)pfVar6 + 1);
        pfVar9 = (float *)((int)pfVar9 + 1);
      }
      param_4 = param_4 + param_8;
    } while (param_1 < param_3);
  }
  return;
}


// 005b0171 FUN_005b0171

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b0171(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  float *unaff_EBX;
  float *unaff_EBP;
  undefined4 *unaff_ESI;
  float *pfVar12;
  undefined4 *unaff_EDI;
  float10 in_ST0;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  unaff_EBP[10] = *unaff_EBX;
  unaff_EBP[0xb] = unaff_EBX[1];
  unaff_EBP[0xc] = unaff_EBX[2];
  pfVar8 = (float *)unaff_EBP[0x1e];
  unaff_EBP[0x13] = *pfVar8;
  unaff_EBP[0x14] = pfVar8[1];
  unaff_EBP[0x15] = pfVar8[2];
  fVar7 = unaff_EBP[0x18];
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + -8,fVar7,(float)in_ST0,unaff_EBP + -5);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + -8,fVar7,_DAT_006cca58,unaff_EBP + -2);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 10,(int)fVar7 + 0xc,_DAT_006cca58,unaff_EBP + 1);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 0x13,(int)fVar7 + 0x18,_DAT_006cca58,unaff_EBP + 7);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + 10,(int)fVar7 + 0xc,_DAT_006cca58,unaff_EBP + 0xd);
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + 0x13,(int)fVar7 + 0x18,_DAT_006cca58,unaff_EBP + 0x10);
  unaff_EBP[4] = unaff_EBP[-5];
  unaff_EBP[5] = unaff_EBP[-4];
  unaff_EBP[6] = unaff_EBP[-3];
  unaff_EBP[6] = *unaff_EBP + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[1] + unaff_EBP[-5] + unaff_EBP[-2];
  unaff_EBP[4] = unaff_EBP[7] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[8] + unaff_EBP[2] + unaff_EBP[-1] + unaff_EBP[5];
  unaff_EBP[5] = unaff_EBP[0xe] + unaff_EBP[5];
  unaff_EBP[6] = unaff_EBP[0xf] + unaff_EBP[9] + unaff_EBP[3] + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[0x10] + unaff_EBP[0xd] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[0x11] + unaff_EBP[5];
  fVar2 = _DAT_006cc90c;
  unaff_EBP[4] = unaff_EBP[4] * _DAT_006cc90c;
  unaff_EBP[5] = unaff_EBP[5] * fVar2;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar7 = 0.0;
  unaff_EBP[0x18] = 0.0;
  fVar5 = unaff_EBP[-0xe] * _DAT_00699490;
  fVar1 = unaff_EBP[-0xd] * _DAT_00699490;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * _DAT_00699490;
  unaff_EBP[4] = unaff_EBP[4] - fVar5;
  unaff_EBP[5] = unaff_EBP[5] - fVar1;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * fVar2 - unaff_EBP[-9];
  fVar5 = _DAT_006cc7ac;
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar7 * 8 + (int)unaff_EBP[0x19]);
      uVar9 = 0;
      fVar7 = *(float *)((int)fVar7 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar6 = (1.0 - fVar1) - fVar7;
      unaff_EBP[-0x18] = fVar7 * fVar7 * fVar7;
      unaff_EBP[0x1d] = fVar6 * fVar7;
      unaff_EBP[-0x17] = fVar6 * fVar7 * fVar7 * fVar5;
      unaff_EBP[-0x16] = fVar7 * fVar7 * fVar1 * fVar5;
      fVar2 = fVar6 * fVar6;
      unaff_EBP[-0x15] = fVar2 * fVar7 * fVar5;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * _DAT_006cc7a8;
      unaff_EBP[-0x13] = fVar7 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0x12] = fVar2 * fVar6;
      unaff_EBP[-0x11] = fVar2 * fVar1 * fVar5;
      unaff_EBP[-0x10] = fVar6 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar4 = 0.0;
      pfVar8 = unaff_EBP + -7;
      do {
        pfVar12 = unaff_EBP + (uVar9 - 0x18);
        uVar9 = uVar9 + 1;
        fVar2 = pfVar8[-1] * *pfVar12 + fVar2;
        fVar3 = *pfVar12 * *pfVar8 + fVar3;
        fVar4 = pfVar8[1] * *pfVar12 + fVar4;
        pfVar8 = pfVar8 + 3;
      } while (uVar9 < 10);
      fVar11 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar4;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar11) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar8 = unaff_EBX + 3;
        iVar10 = (int)fVar11 + -3;
        do {
          *(float *)((int)pfVar8 + (int)unaff_EBP + (-0x170 - (int)unaff_EBX)) =
               fVar6 * *pfVar8 +
               fVar7 * *(float *)((int)pfVar8 + ((int)fVar2 - (int)unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar8 + ((int)fVar3 - (int)unaff_EBX));
          pfVar8 = pfVar8 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        fVar11 = unaff_EBP[0x1f];
      }
      pfVar8 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar11 * 4);
      fVar7 = unaff_EBP[0x18];
      pfVar12 = unaff_EBP + -0x5c;
      for (uVar9 = (uint)fVar11 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pfVar8 = *pfVar12;
        pfVar12 = pfVar12 + 1;
        pfVar8 = pfVar8 + 1;
      }
      fVar7 = (float)((int)fVar7 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)pfVar8 = *(undefined1 *)pfVar12;
        pfVar12 = (float *)((int)pfVar12 + 1);
        pfVar8 = (float *)((int)pfVar8 + 1);
      }
      unaff_EBP[0x18] = fVar7;
    } while ((uint)fVar7 < (uint)fVar1);
  }
  return;
}


// 005b0189 FUN_005b0189

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b0189(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  int unaff_EBX;
  float *unaff_EBP;
  float *pfVar12;
  
  fVar7 = unaff_EBP[0x18];
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + -8,fVar7);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + -8,fVar7);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 10,(int)fVar7 + 0xc);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 0x13,(int)fVar7 + 0x18);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + 10,(int)fVar7 + 0xc);
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + 0x13,(int)fVar7 + 0x18);
  unaff_EBP[4] = unaff_EBP[-5];
  unaff_EBP[5] = unaff_EBP[-4];
  unaff_EBP[6] = unaff_EBP[-3];
  unaff_EBP[6] = *unaff_EBP + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[1] + unaff_EBP[-5] + unaff_EBP[-2];
  unaff_EBP[4] = unaff_EBP[7] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[8] + unaff_EBP[2] + unaff_EBP[-1] + unaff_EBP[5];
  unaff_EBP[5] = unaff_EBP[0xe] + unaff_EBP[5];
  unaff_EBP[6] = unaff_EBP[0xf] + unaff_EBP[9] + unaff_EBP[3] + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[0x10] + unaff_EBP[0xd] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[0x11] + unaff_EBP[5];
  fVar2 = _DAT_006cc90c;
  unaff_EBP[4] = unaff_EBP[4] * _DAT_006cc90c;
  unaff_EBP[5] = unaff_EBP[5] * fVar2;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar7 = 0.0;
  unaff_EBP[0x18] = 0.0;
  fVar5 = unaff_EBP[-0xe] * _DAT_00699490;
  fVar1 = unaff_EBP[-0xd] * _DAT_00699490;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * _DAT_00699490;
  unaff_EBP[4] = unaff_EBP[4] - fVar5;
  unaff_EBP[5] = unaff_EBP[5] - fVar1;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * fVar2 - unaff_EBP[-9];
  fVar5 = _DAT_006cc7ac;
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar7 * 8 + (int)unaff_EBP[0x19]);
      uVar9 = 0;
      fVar7 = *(float *)((int)fVar7 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar6 = (1.0 - fVar1) - fVar7;
      unaff_EBP[-0x18] = fVar7 * fVar7 * fVar7;
      unaff_EBP[0x1d] = fVar6 * fVar7;
      unaff_EBP[-0x17] = fVar6 * fVar7 * fVar7 * fVar5;
      unaff_EBP[-0x16] = fVar7 * fVar7 * fVar1 * fVar5;
      fVar2 = fVar6 * fVar6;
      unaff_EBP[-0x15] = fVar2 * fVar7 * fVar5;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * _DAT_006cc7a8;
      unaff_EBP[-0x13] = fVar7 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0x12] = fVar2 * fVar6;
      unaff_EBP[-0x11] = fVar2 * fVar1 * fVar5;
      unaff_EBP[-0x10] = fVar6 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar4 = 0.0;
      pfVar8 = unaff_EBP + -7;
      do {
        pfVar12 = unaff_EBP + (uVar9 - 0x18);
        uVar9 = uVar9 + 1;
        fVar2 = pfVar8[-1] * *pfVar12 + fVar2;
        fVar3 = *pfVar12 * *pfVar8 + fVar3;
        fVar4 = pfVar8[1] * *pfVar12 + fVar4;
        pfVar8 = pfVar8 + 3;
      } while (uVar9 < 10);
      fVar11 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar4;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar11) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar8 = (float *)(unaff_EBX + 0xc);
        iVar10 = (int)fVar11 + -3;
        do {
          *(float *)((int)pfVar8 + (int)unaff_EBP + (-0x170 - unaff_EBX)) =
               fVar6 * *pfVar8 +
               fVar7 * *(float *)((int)pfVar8 + ((int)fVar2 - unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar8 + ((int)fVar3 - unaff_EBX));
          pfVar8 = pfVar8 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        fVar11 = unaff_EBP[0x1f];
      }
      pfVar8 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar11 * 4);
      fVar7 = unaff_EBP[0x18];
      pfVar12 = unaff_EBP + -0x5c;
      for (uVar9 = (uint)fVar11 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pfVar8 = *pfVar12;
        pfVar12 = pfVar12 + 1;
        pfVar8 = pfVar8 + 1;
      }
      fVar7 = (float)((int)fVar7 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)pfVar8 = *(undefined1 *)pfVar12;
        pfVar12 = (float *)((int)pfVar12 + 1);
        pfVar8 = (float *)((int)pfVar8 + 1);
      }
      unaff_EBP[0x18] = fVar7;
    } while ((uint)fVar7 < (uint)fVar1);
  }
  return;
}


// 005b01c7 FUN_005b01c7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b01c7(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  int unaff_EBX;
  float *unaff_EBP;
  int unaff_ESI;
  float *pfVar12;
  
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 10,unaff_ESI + 0xc);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 0x13,unaff_ESI + 0x18);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + 10,unaff_ESI + 0xc);
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + 0x13,unaff_ESI + 0x18);
  unaff_EBP[4] = unaff_EBP[-5];
  unaff_EBP[5] = unaff_EBP[-4];
  unaff_EBP[6] = unaff_EBP[-3];
  unaff_EBP[6] = *unaff_EBP + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[1] + unaff_EBP[-5] + unaff_EBP[-2];
  unaff_EBP[4] = unaff_EBP[7] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[8] + unaff_EBP[2] + unaff_EBP[-1] + unaff_EBP[5];
  unaff_EBP[5] = unaff_EBP[0xe] + unaff_EBP[5];
  unaff_EBP[6] = unaff_EBP[0xf] + unaff_EBP[9] + unaff_EBP[3] + unaff_EBP[6];
  unaff_EBP[4] = unaff_EBP[0x10] + unaff_EBP[0xd] + unaff_EBP[4];
  unaff_EBP[5] = unaff_EBP[0x11] + unaff_EBP[5];
  fVar2 = _DAT_006cc90c;
  unaff_EBP[4] = unaff_EBP[4] * _DAT_006cc90c;
  unaff_EBP[5] = unaff_EBP[5] * fVar2;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar7 = 0.0;
  unaff_EBP[0x18] = 0.0;
  fVar5 = unaff_EBP[-0xe] * _DAT_00699490;
  fVar1 = unaff_EBP[-0xd] * _DAT_00699490;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * _DAT_00699490;
  unaff_EBP[4] = unaff_EBP[4] - fVar5;
  unaff_EBP[5] = unaff_EBP[5] - fVar1;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * fVar2 - unaff_EBP[-9];
  fVar5 = _DAT_006cc7ac;
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar7 * 8 + (int)unaff_EBP[0x19]);
      uVar9 = 0;
      fVar7 = *(float *)((int)fVar7 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar6 = (1.0 - fVar1) - fVar7;
      unaff_EBP[-0x18] = fVar7 * fVar7 * fVar7;
      unaff_EBP[0x1d] = fVar6 * fVar7;
      unaff_EBP[-0x17] = fVar6 * fVar7 * fVar7 * fVar5;
      unaff_EBP[-0x16] = fVar7 * fVar7 * fVar1 * fVar5;
      fVar2 = fVar6 * fVar6;
      unaff_EBP[-0x15] = fVar2 * fVar7 * fVar5;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * _DAT_006cc7a8;
      unaff_EBP[-0x13] = fVar7 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0x12] = fVar2 * fVar6;
      unaff_EBP[-0x11] = fVar2 * fVar1 * fVar5;
      unaff_EBP[-0x10] = fVar6 * fVar1 * fVar1 * fVar5;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar4 = 0.0;
      pfVar8 = unaff_EBP + -7;
      do {
        pfVar12 = unaff_EBP + (uVar9 - 0x18);
        uVar9 = uVar9 + 1;
        fVar2 = pfVar8[-1] * *pfVar12 + fVar2;
        fVar3 = *pfVar12 * *pfVar8 + fVar3;
        fVar4 = pfVar8[1] * *pfVar12 + fVar4;
        pfVar8 = pfVar8 + 3;
      } while (uVar9 < 10);
      fVar11 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar4;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar11) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar8 = (float *)(unaff_EBX + 0xc);
        iVar10 = (int)fVar11 + -3;
        do {
          *(float *)((int)pfVar8 + (int)unaff_EBP + (-0x170 - unaff_EBX)) =
               fVar6 * *pfVar8 +
               fVar7 * *(float *)((int)pfVar8 + ((int)fVar2 - unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar8 + ((int)fVar3 - unaff_EBX));
          pfVar8 = pfVar8 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        fVar11 = unaff_EBP[0x1f];
      }
      pfVar8 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar11 * 4);
      fVar7 = unaff_EBP[0x18];
      pfVar12 = unaff_EBP + -0x5c;
      for (uVar9 = (uint)fVar11 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pfVar8 = *pfVar12;
        pfVar12 = pfVar12 + 1;
        pfVar8 = pfVar8 + 1;
      }
      fVar7 = (float)((int)fVar7 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined1 *)pfVar8 = *(undefined1 *)pfVar12;
        pfVar12 = (float *)((int)pfVar12 + 1);
        pfVar8 = (float *)((int)pfVar8 + 1);
      }
      unaff_EBP[0x18] = fVar7;
    } while ((uint)fVar7 < (uint)fVar1);
  }
  return;
}


// 005b0602 FUN_005b0602

undefined4 FUN_005b0602(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x3c);
}


// 005b173a FUN_005b173a

undefined4 FUN_005b173a(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_005b0a37(1);
    uVar2 = 0;
  }
  return uVar2;
}


// 005b2a87 FUN_005b2a87

void __fastcall FUN_005b2a87(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// 005b3187 FUN_005b3187

undefined4 FUN_005b3187(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


// 005b51a7 FUN_005b51a7

int FUN_005b51a7(int param_1,size_t param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 *puVar17;
  char *pcVar18;
  char acStack_a4 [116];
  int iStack_30;
  int *piStack_2c;
  undefined4 *puStack_28;
  int iStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int *piStack_14;
  uint uStack_10;
  int *piStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  piStack_c = (int *)0x0;
  piStack_20 = (int *)0x0;
  piStack_18 = (int *)0x0;
  puStack_28 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0xfc) == 0) {
    FUN_005b1f01(param_1 + 0xc,0,0,"ID3DXEffectCompiler: There were no techniques");
    iVar16 = -0x7fffbffb;
  }
  else {
    pvVar4 = _malloc(0x1c);
    if (pvVar4 == (void *)0x0) {
      iStack_8 = 0;
    }
    else {
      iStack_8 = FUN_005b2aff();
    }
    if (iStack_8 == 0) {
      iVar16 = -0x7ff8fff2;
    }
    else {
      iVar12 = *(int *)(param_1 + 0x120);
      uStack_1c = 0;
      for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
        iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
        if (iVar16 < 0) goto LAB_005b57b9;
        for (iVar6 = *(int *)(iVar12 + 0x30); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x34)) {
          iVar16 = FUN_005b4ef1(iVar6,iStack_8,&uStack_1c,param_2);
          if (iVar16 < 0) goto LAB_005b57b9;
        }
      }
      for (piVar5 = *(int **)(param_1 + 0x11c); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0xd]) {
        for (iVar12 = piVar5[0xc]; piVar9 = piVar5, iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
          iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
          if (iVar16 < 0) goto LAB_005b57b9;
        }
        while (piStack_14 = (int *)piVar9[0xb], piStack_14 != (int *)0x0) {
          for (iVar12 = piStack_14[10]; piVar9 = piStack_14, iVar12 != 0;
              iVar12 = *(int *)(iVar12 + 0x34)) {
            iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
            if (iVar16 < 0) goto LAB_005b57b9;
          }
        }
      }
      iStack_30 = 0;
      piStack_2c = *(int **)(param_1 + 0x128);
      while (piStack_2c != (int *)0x0) {
        FUN_005d9188();
        iVar12 = piStack_2c[4];
        if (((*(int *)(iVar12 + 0x1c) == 0x17) || (*(int *)(iVar12 + 0x1c) == 0x16)) &&
           (((&DAT_006d5674)[*piStack_2c * 7] == 0x6000000 ||
            ((&DAT_006d5674)[*piStack_2c * 7] == 0x6000001)))) {
          for (iVar16 = *(int *)(iVar12 + 0x20);
              (*(int *)(iVar16 + 4) == 0xc && (*(int *)(iVar16 + 0x1c) == 0));
              iVar16 = *(int *)(iVar16 + 0x20)) {
          }
          if (*(int *)(iVar16 + 4) == 1) {
            uVar14 = *(uint *)(iVar16 + 8);
            uStack_10 = uVar14;
            if (*(int *)(uVar14 + 0x10) == 6) {
              iVar16 = *(int *)(iVar12 + 0x24);
              for (iVar6 = iVar16; (*(int *)(iVar6 + 4) == 0xc && (*(int *)(iVar6 + 0x1c) == 0));
                  iVar6 = *(int *)(iVar6 + 0x20)) {
              }
              if (*(int *)(iVar6 + 4) == 0xd) {
                iVar12 = *(int *)(iVar6 + 0x20);
                if (1 < iVar12) {
                  if (iVar12 < 5) {
                    uVar10 = *(undefined4 *)(iVar6 + 0x28);
                  }
                  else {
                    if (8 < iVar12) goto LAB_005b584a;
                    uVar10 = __ftol();
                  }
                  _sprintf(acStack_a4,&DAT_006ca778,uVar10);
                  pcVar7 = *(char **)(uVar14 + 0x28);
                  pcVar18 = pcVar7 + 1;
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar1 != '\0');
                  pcVar8 = acStack_a4;
                  do {
                    cVar1 = *pcVar8;
                    pcVar8 = pcVar8 + 1;
                  } while (cVar1 != '\0');
                  iVar16 = thunk_FUN_005d65b0(pcVar7 + (int)(pcVar8 + ((3 - (int)(acStack_a4 + 1)) -
                                                                      (int)pcVar18)),&piStack_c);
                  if (-1 < iVar16) {
                    uVar10 = (**(code **)(*piStack_c + 0xc))
                                       (piStack_c,"%s[%s]",*(undefined4 *)(uStack_10 + 0x28),
                                        acStack_a4);
                    _sprintf(uVar10);
                    uStack_10 = 1;
                    goto LAB_005b55b9;
                  }
                  goto LAB_005b5868;
                }
LAB_005b584a:
                pcVar18 = 
                "ID3DXEffectCompiler::CompileEffect: Shader arrays index was not float or int";
              }
              else {
                if (*(int *)(iVar16 + 4) == 0xc) {
                  iVar16 = FUN_005e505d(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),iVar16,0,param_2
                                        ,&piStack_c,&piStack_14);
                  if (iVar16 < 0) goto LAB_005b5851;
                  pcVar7 = *(char **)(uStack_10 + 0x28);
                  pcVar18 = pcVar7 + 1;
                  pcVar8 = pcVar7;
                  do {
                    cVar1 = *pcVar8;
                    pcVar8 = pcVar8 + 1;
                  } while (cVar1 != '\0');
                  cVar1 = (char)pcVar7;
                  do {
                    cVar2 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar2 != '\0');
                  iVar12 = ((uint)((((char)pcVar7 - (cVar1 + '\x01')) + 1U & 3) != 0) +
                           ((uint)(pcVar8 + (1 - (int)pcVar18)) >> 2)) * 4;
                  iStack_24 = iVar12;
                  iVar16 = (**(code **)(*piStack_c + 0x10))(piStack_c);
                  uVar14 = iVar16 + 4 + iVar12;
                  iVar16 = thunk_FUN_005d65b0(uVar14,&piStack_20);
                  if (-1 < iVar16) {
                    piVar9 = (int *)(**(code **)(*piStack_20 + 0xc))(piStack_20);
                    piVar5 = piVar9;
                    for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *piVar5 = 0;
                      piVar5 = piVar5 + 1;
                    }
                    for (uVar13 = uVar14 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *(undefined1 *)piVar5 = 0;
                      piVar5 = (int *)((int)piVar5 + 1);
                    }
                    *piVar9 = iStack_24;
                    _strncpy((char *)(piVar9 + 1),*(char **)(uStack_10 + 0x28),uVar14 - 4);
                    uStack_10 = (**(code **)(*piStack_c + 0x10))(piStack_c);
                    pcVar18 = (char *)(**(code **)(*piStack_c + 0xc))(piStack_c);
                    pcVar7 = (char *)((int)(piVar9 + 1) + iStack_24);
                    for (uVar14 = uStack_10 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar18;
                      pcVar18 = pcVar18 + 4;
                      pcVar7 = pcVar7 + 4;
                    }
                    for (uVar14 = uStack_10 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
                      *pcVar7 = *pcVar18;
                      pcVar18 = pcVar18 + 1;
                      pcVar7 = pcVar7 + 1;
                    }
                    if (piStack_14 != (int *)0x0) {
                      (**(code **)(*piStack_14 + 8))(piStack_14);
                      piStack_14 = (int *)0x0;
                    }
                    if (piStack_c != (int *)0x0) {
                      (**(code **)(*piStack_c + 8))(piStack_c);
                    }
                    piStack_c = piStack_20;
                    piStack_20 = (int *)0x0;
                    uStack_10 = 2;
                    goto LAB_005b55b9;
                  }
                  goto LAB_005b5868;
                }
                pcVar18 = 
                "ID3DXEffectCompiler::CompileEffect: Could not compile expression containing shader array"
                ;
              }
            }
            else {
              pcVar18 = 
              "ID3DXEffectCompiler::CompileEffect: Shader arrays must be a previously defined parameter"
              ;
            }
            iVar12 = uVar14 + 0x20;
          }
          else {
            pcVar18 = "ID3DXEffectCompiler::CompileEffect: Only 1-d shader arrays allowed";
            iVar12 = iVar12 + 0x30;
          }
          FUN_005b1f01(param_1 + 0xc,iVar12,0,pcVar18);
          iVar16 = -0x7fffbffb;
          FUN_005d91a1();
          goto LAB_005b57b9;
        }
        iVar16 = FUN_005e505d(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),iVar12,0,param_2,
                              &piStack_c,&piStack_14);
        if (iVar16 < 0) {
LAB_005b5851:
          FUN_005b1f01(param_1 + 0xc,iVar12 + 0x30,0,
                       "ID3DXEffectCompiler::CompileEffect: There was an error compiling expression"
                      );
LAB_005b5868:
          FUN_005d91a1();
          goto LAB_005b579e;
        }
        uStack_10 = (uint)(piStack_14 == (int *)0x1);
        if ((piStack_14 != (int *)0x1) && (piStack_14 != (int *)0x0)) {
          (**(code **)(*piStack_14 + 8))(piStack_14);
          piStack_14 = (int *)0x0;
        }
LAB_005b55b9:
        uVar10 = (**(code **)(*piStack_c + 0xc))(piStack_c);
        iStack_24 = (**(code **)(*piStack_c + 0x10))(piStack_c);
        piVar5 = piStack_2c;
        iVar16 = FUN_005b2b74(piStack_2c + 1,4,0);
        if (((((iVar16 < 0) || (iVar16 = FUN_005b2b74(piVar5 + 2,4,0), iVar16 < 0)) ||
             (iVar16 = FUN_005b2b74(piVar5 + 3,4,0), iVar16 < 0)) ||
            ((iVar16 = FUN_005b2b74(&uStack_10,4,0), iVar16 < 0 ||
             (iVar16 = FUN_005b2b74(&iStack_24,4,0), iVar16 < 0)))) ||
           (iVar16 = FUN_005b2b74(uVar10,iStack_24,0), iVar16 < 0)) goto LAB_005b5868;
        iStack_30 = iStack_30 + 1;
        if (piStack_c != (int *)0x0) {
          (**(code **)(*piStack_c + 8))(piStack_c);
          piStack_c = (int *)0x0;
        }
        FUN_005d91a1();
        piStack_2c = (int *)piVar5[5];
      }
      param_2 = 0;
      iVar16 = FUN_005b2d1d(0,&param_2);
      sVar3 = param_2;
      if (-1 < iVar16) {
        puStack_28 = _malloc(param_2);
        if (puStack_28 != (undefined4 *)0x0) {
          iVar16 = FUN_005b2d1d(puStack_28,0);
          if ((iVar16 < 0) ||
             (iVar16 = thunk_FUN_005d65b0(*(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x114) +
                                          0x10 + sVar3,&piStack_18), iVar16 < 0)) goto LAB_005b57b9;
          puVar11 = (undefined4 *)(**(code **)(*piStack_18 + 0xc))(piStack_18);
          *puVar11 = 0xffffffff;
          puVar11[1] = *(undefined4 *)(param_1 + 0x114);
          uVar14 = *(uint *)(param_1 + 0x114);
          puVar15 = *(undefined4 **)(param_1 + 0x118);
          puVar17 = puVar11 + 2;
          for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          puVar11 = (undefined4 *)((int)(puVar11 + 2) + *(int *)(param_1 + 0x114));
          uVar14 = *(uint *)(param_1 + 0x10c);
          puVar15 = *(undefined4 **)(param_1 + 0x110);
          puVar17 = puVar11;
          for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          puVar11 = (undefined4 *)((int)puVar11 + *(int *)(param_1 + 0x10c));
          *puVar11 = uStack_1c;
          puVar11[1] = iStack_30;
          puVar15 = puStack_28;
          puVar17 = puVar11 + 2;
          for (uVar14 = param_2 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = param_2 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = piStack_18;
            (**(code **)(*piStack_18 + 4))(piStack_18);
          }
        }
LAB_005b579e:
        if (-1 < iVar16) {
          iVar12 = FUN_005b19e6();
          if (iVar12 != 0) {
            iVar16 = -0x7789f4a7;
          }
          if (-1 < iVar16) goto LAB_005b57ce;
        }
      }
    }
  }
LAB_005b57b9:
  FUN_005b1f01(param_1 + 0xc,0,0,"ID3DXEffectCompiler: Compilation failed");
LAB_005b57ce:
  if (param_4 != 0) {
    FUN_005b197d(param_4);
  }
  if (puStack_28 != (undefined4 *)0x0) {
    _free(puStack_28);
  }
  if (iStack_8 != 0) {
    FUN_005b2b58(1);
  }
  if (piStack_18 != (int *)0x0) {
    (**(code **)(*piStack_18 + 8))(piStack_18);
    piStack_18 = (int *)0x0;
  }
  if (piStack_c != (int *)0x0) {
    (**(code **)(*piStack_c + 8))(piStack_c);
    piStack_c = (int *)0x0;
  }
  if (piStack_20 != (int *)0x0) {
    (**(code **)(*piStack_20 + 8))(piStack_20);
  }
  return iVar16;
}


// 005b58a1 FUN_005b58a1

undefined4 FUN_005b58a1(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[1] = *(undefined4 *)(param_1 + 0x100);
    param_2[2] = *(undefined4 *)(param_1 + 0xfc);
    param_2[3] = *(undefined4 *)(param_1 + 0x104);
  }
  return uVar1;
}


// 005b58e2 FUN_005b58e2

undefined4 FUN_005b58e2(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 != (undefined4 *)0x0) && (iVar1 = FUN_005b4cdc(param_2), iVar1 != 0)) {
    *param_3 = 0;
    param_3[1] = 0;
    *param_3 = *(undefined4 *)(iVar1 + 0x20);
    param_3[1] = 0;
    return 0;
  }
  return 0x8876086c;
}


// 005b591f FUN_005b591f

undefined4 FUN_005b591f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 != (undefined4 *)0x0) && (iVar1 = FUN_005b4d58(param_2), iVar1 != 0)) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    *param_3 = *(undefined4 *)(iVar1 + 0x20);
    param_3[1] = *(undefined4 *)(iVar1 + 0x28);
    param_3[2] = *(undefined4 *)(iVar1 + 0x24);
    return 0;
  }
  return 0x8876086c;
}


// 005b5c9f FUN_005b5c9f

uint FUN_005b5c9f(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0xfc)) {
    uVar1 = *(uint *)(param_1 + 0x11c);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0xfc)) {
      uVar1 = *(uint *)(uVar1 + 0x34);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// 005b5cca FUN_005b5cca

uint FUN_005b5cca(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_005b4d58(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// 005b5d0d FUN_005b5d0d

uint FUN_005b5d0d(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = FUN_005b4d58(param_2);
  if (iVar2 != 0) {
    for (uVar5 = *(uint *)(iVar2 + 0x2c); uVar5 != 0; uVar5 = *(uint *)(uVar5 + 0x2c)) {
      if (param_3 == (byte *)0x0) {
        iVar2 = *(int *)(uVar5 + 0x20);
LAB_005b5d66:
        if (iVar2 == 0) {
          return ~uVar5;
        }
      }
      else {
        pbVar4 = *(byte **)(uVar5 + 0x20);
        pbVar3 = param_3;
        if (pbVar4 != (byte *)0x0) {
          do {
            bVar1 = *pbVar3;
            bVar6 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_005b5d5f:
              iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_005b5d66;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar6 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_005b5d5f;
            pbVar4 = pbVar4 + 2;
            pbVar3 = pbVar3 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
          goto LAB_005b5d66;
        }
      }
    }
  }
  return 0;
}


// 005b5d7c FUN_005b5d7c

uint FUN_005b5d7c(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x104)) {
    uVar1 = *(uint *)(param_1 + 0x124);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0x104)) {
      uVar1 = *(uint *)(uVar1 + 0x28);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// 005b5da7 FUN_005b5da7

uint FUN_005b5da7(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_005b4cdc(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// 005b6425 FUN_005b6425

void FUN_005b6425(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b59d1(param_2,param_3,0);
  return;
}


// 005b643b FUN_005b643b

void FUN_005b643b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b5b7e(param_2,param_3,0);
  return;
}


// 005b77f6 FUN_005b77f6

void FUN_005b77f6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b626c(param_2,param_3,0);
  return;
}


// 005b876a FUN_005b876a

undefined4 FUN_005b876a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar4 = 0x8876086c;
  }
  else {
    iVar1 = FUN_005b7369(param_2,1);
    if (((iVar1 == 0) ||
        (((piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                           *(int *)(iVar1 + 0x18)), piVar3[4] != 0 && (*(int *)(iVar1 + 0x10) == -1)
          ) || (piVar3[1] != 4)))) || (*piVar3 != 4)) {
      uVar4 = 0x8876086c;
    }
    else {
      iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
      *param_3 = 0;
      piVar3 = *(int **)(iVar1 + 0x18);
      if (piVar3 != (int *)0x0) {
        uVar2 = (**(code **)(*piVar3 + 0xc))(piVar3);
        *param_3 = uVar2;
      }
    }
  }
  return uVar4;
}


// 005c8f17 FUN_005c8f17

void __fastcall FUN_005c8f17(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// 005c8f5e FUN_005c8f5e

void __fastcall FUN_005c8f5e(undefined4 *param_1)

{
  param_1[2] = 0xffffffff;
  *param_1 = 0x7fffffff;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = 1;
  return;
}


// 005c9718 FUN_005c9718

int FUN_005c9718(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x84) == 3) {
    *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
    *(int *)(param_1 + 0x84) = 0;
    if ((*(byte *)(param_1 + 0x3c) & 2) == 0) {
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x84 + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x88 + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
    }
    if ((*(byte *)(param_1 + 0x3c) & 1) == 0) {
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x8c + *(int *)(param_1 + 0x1c));
      if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar2 < 0)) {
        return iVar2;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x34) * 0xac + 0x80 + *(int *)(param_1 + 0x1c));
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
      }
    }
  }
  else {
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}


// 005ca4de FUN_005ca4de

uint FUN_005ca4de(int param_1)

{
  return ~(*(int *)(param_1 + 0x34) * 0xac + *(int *)(param_1 + 0x1c));
}


// 005ca5e9 FUN_005ca5e9

uint FUN_005ca5e9(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x18)) {
    uVar1 = ~(param_2 * 0xac + *(int *)(param_1 + 0x1c));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// 005ca69c FUN_005ca69c

uint FUN_005ca69c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_005ca526(param_2,1);
  if ((iVar1 == 0) || (*(uint *)(iVar1 + 0x2c) <= param_3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(*(int *)(iVar1 + 0x30) + param_3 * 0x3c);
  }
  return uVar2;
}


// 005ca89e FUN_005ca89e

undefined4 FUN_005ca89e(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// 005ca8c9 FUN_005ca8c9

undefined4 FUN_005ca8c9(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    piVar1 = *(int **)(param_1 + 8);
    *param_2 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return uVar2;
}


// 005ca8f4 FUN_005ca8f4

undefined4 FUN_005ca8f4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *param_2 = PTR_s_D3DX9_Effect_Compiler_006db900;
    param_2[1] = *(undefined4 *)(param_1 + 0x10);
    param_2[2] = *(undefined4 *)(param_1 + 0x18);
    param_2[3] = 0;
  }
  return uVar1;
}


// 005cb552 FUN_005cb552

void FUN_005cb552(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005ca361(param_2,param_3,0);
  return;
}


// 005cb6f7 FUN_005cb6f7

undefined4 FUN_005cb6f7(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_ECX;
  
  if ((*(int *)(param_1 + 0x84) != 3) && (iVar1 = FUN_005ca526(param_2,1), iVar1 != 0)) {
    *(undefined4 *)(extraout_ECX + 0x34) = *(undefined4 *)(iVar1 + 4);
    return 0;
  }
  return 0x8876086c;
}


// 005cd2da FUN_005cd2da

void __fastcall FUN_005cd2da(undefined4 *param_1)

{
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 1;
  param_1[10] = 0;
  param_1[0xc] = 0;
  return;
}


// 005cd2f5 FUN_005cd2f5

void __fastcall FUN_005cd2f5(undefined4 *param_1)

{
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  return;
}


// 005d1c05 FUN_005d1c05

void FUN_005d1c05(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d07f5(param_2,param_3,0);
  return;
}


// 005d1f8b FUN_005d1f8b

void FUN_005d1f8b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d19ea(param_2,param_3,0);
  return;
}


// 005d2406 FUN_005d2406

undefined4 FUN_005d2406(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_005d1d24(1);
    uVar2 = 0;
  }
  return uVar2;
}


// 005d3f76 FUN_005d3f76

int FUN_005d3f76(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar2 + 4) = 4;
  *(undefined4 *)*piVar2 = 4;
  *(undefined4 *)(*piVar2 + 0x10) = 0;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar4 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar4 + 0x38) == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar2 = (int *)(*(int *)(iVar4 + 0x24) + *(int *)(iVar1 + 8) + iVar3);
    if ((((piVar2[4] == 0) || (*(int *)(iVar1 + 0x18) != -1)) && (piVar2[1] == 4)) && (*piVar2 == 4)
       ) {
      if (*(int *)(iVar4 + 0x38) == 0) {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar4 = FUN_005cabd8(param_3,*(undefined4 *)
                                    (*(int *)(iVar4 + 0x28) + *(int *)(iVar1 + 0xc) + iVar3),
                           *(int *)(iVar4 + 0x38));
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar1 = FUN_005d02d7(iVar1);
      return iVar1;
    }
  }
  return -0x7789f794;
}


// 005d64da FUN_005d64da

undefined4 __thiscall FUN_005d64da(int param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _malloc(param_2);
  *(void **)(param_1 + 0xc) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(size_t *)(param_1 + 8) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}


// 005d6501 FUN_005d6501

int FUN_005d6501(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  iVar1 = iVar2 + -1;
  param_1[1] = iVar1;
  if (iVar2 == 1) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return iVar1;
}


// 005d6521 FUN_005d6521

undefined4 FUN_005d6521(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// 005d652b FUN_005d652b

undefined4 FUN_005d652b(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// 005d6c72 FUN_005d6c72

float * FUN_005d6c72(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_3[0xd];
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xf];
  *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar13 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar15 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// 005d6cdb FUN_005d6cdb

float * FUN_005d6cdb(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = param_2[1];
  fVar4 = param_3[5];
  *param_1 = param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2;
  return param_1;
}


// 005d6d9b FUN_005d6d9b

float * FUN_005d6d9b(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = *param_2;
  fVar4 = param_3[2];
  fVar5 = param_2[1];
  fVar6 = param_3[5];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[2];
  fVar10 = param_3[9];
  fVar11 = param_2[2];
  fVar12 = param_3[10];
  *param_1 = param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  return param_1;
}


// 005d6dfa FUN_005d6dfa

float * FUN_005d6dfa(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_2[2];
  fVar14 = param_3[10];
  fVar15 = param_2[2];
  fVar16 = param_3[9];
  fVar17 = param_2[2];
  fVar18 = param_3[0xb];
  fVar19 = param_2[3];
  fVar20 = param_3[0xe];
  fVar21 = param_2[3];
  fVar22 = param_3[0xd];
  fVar23 = param_2[3];
  fVar24 = param_3[0xf];
  *param_1 = param_2[3] * param_3[0xc] +
             param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar21 * fVar22 + fVar15 * fVar16 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar19 * fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar23 * fVar24 + fVar17 * fVar18 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// 005d7846 FUN_005d7846

undefined4 __fastcall FUN_005d7846(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _malloc(0x10);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005d77e9(*(undefined4 *)(param_1 + 4));
    return uVar2;
  }
  return 0;
}


// 005d7aec FUN_005d7aec

bool FUN_005d7aec(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_005d7830(param_1);
  bVar2 = false;
  if (iVar1 != 0) {
    iVar1 = FUN_005d79dc();
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// 005d7b0e FUN_005d7b0e

void __fastcall FUN_005d7b0e(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar1 = _malloc(0x30);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005d7aaa();
  }
  if (iVar2 == 0) {
    return;
  }
  puVar4 = (undefined4 *)(param_1 + 0x10);
  puVar5 = (undefined4 *)(iVar2 + 0x10);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// 005d7bb5 FUN_005d7bb5

bool FUN_005d7bb5(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar1 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) ||
     (*(int *)(extraout_ECX + 0x18) != *(int *)(iVar1 + 0x18))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005d7866(*(undefined4 *)(extraout_ECX + 0x1c),*(undefined4 *)(iVar1 + 0x1c));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// 005d7bf3 FUN_005d7bf3

undefined4 * __fastcall FUN_005d7bf3(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x20);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7b3d();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[4] = *(undefined4 *)(param_1 + 0x10);
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    puVar2[6] = *(undefined4 *)(param_1 + 0x18);
    if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// 005d7ccf FUN_005d7ccf

undefined4 __thiscall FUN_005d7ccf(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
     ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
      iVar1 != 0 &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
      iVar1 != 0)))) {
    return 1;
  }
  return 0;
}


// 005d7d1b FUN_005d7d1b

undefined4 * __fastcall FUN_005d7d1b(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x20);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7c4a();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d7d6e;
  }
  if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
  puVar2[7] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d7d6e:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d7e2b FUN_005d7e2b

undefined4 __thiscall FUN_005d7e2b(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
        (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
       ((*(int *)(param_1 + 0x24) == *(int *)(param_2 + 0x24) &&
        (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))))) &&
      ((*(int *)(param_1 + 0x2c) == *(int *)(param_2 + 0x2c) &&
       ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
        iVar1 != 0 &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
        iVar1 != 0)))))) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// 005d7e9e FUN_005d7e9e

undefined4 * __fastcall FUN_005d7e9e(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x30);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7d7f();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[8] = *(undefined4 *)(param_1 + 0x20);
  puVar2[9] = *(undefined4 *)(param_1 + 0x24);
  puVar2[10] = *(undefined4 *)(param_1 + 0x28);
  puVar2[0xb] = *(undefined4 *)(param_1 + 0x2c);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d7f16;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d7f16;
  }
  if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
  puVar2[7] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d7f16:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d7fa2 FUN_005d7fa2

undefined4 __thiscall FUN_005d7fa2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// 005d7fe6 FUN_005d7fe6

undefined4 * __fastcall FUN_005d7fe6(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7f27();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d8033;
  }
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
  puVar2[6] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8033:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d80a8 FUN_005d80a8

bool FUN_005d80a8(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005d7866(*(undefined4 *)(extraout_ECX + 0x10),*(undefined4 *)(iVar1 + 0x10));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// 005d80d6 FUN_005d80d6

undefined4 * __fastcall FUN_005d80d6(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x18);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8044();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    if (*(int **)(param_1 + 0x10) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// 005d8193 FUN_005d8193

undefined4 FUN_005d8193(undefined4 param_1)

{
  undefined4 uVar1;
  int extraout_ECX;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar2 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar2 + 0x14))) ||
     (((*(int *)(extraout_ECX + 0x18) != *(int *)(iVar2 + 0x18) ||
       (*(int *)(extraout_ECX + 0x1c) != *(int *)(iVar2 + 0x1c))) ||
      (*(int *)(extraout_ECX + 0x20) != *(int *)(iVar2 + 0x20))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// 005d82b9 FUN_005d82b9

undefined4 __thiscall FUN_005d82b9(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if (((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
       (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
      (((*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18) &&
        (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38))) &&
       ((*(int *)(param_1 + 0x3c) == *(int *)(param_2 + 0x3c) &&
        ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
         iVar1 != 0 &&
         (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
         iVar1 != 0)))))))) &&
     ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
      iVar1 != 0 &&
      ((((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_2 + 0x28)),
         iVar1 != 0 &&
         (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x2c)),
         iVar1 != 0)) &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_2 + 0x30)),
        iVar1 != 0)) &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_2 + 0x34)),
       iVar1 != 0)))))) {
    return 1;
  }
  return 0;
}


// 005d8374 FUN_005d8374

undefined4 * __fastcall FUN_005d8374(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x40);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8213();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[0xe] = *(undefined4 *)(param_1 + 0x38);
  puVar2[0xf] = *(undefined4 *)(param_1 + 0x3c);
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    puVar2[9] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
    puVar2[0xb] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 8))();
    puVar2[0xc] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x34) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x34) + 8))();
  puVar2[0xd] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d843c:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d84e1 FUN_005d84e1

undefined1 __thiscall FUN_005d84e1(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  iVar3 = FUN_005d7830(param_2);
  if ((((((iVar3 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
        (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
       ((*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18) &&
        (*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c))))) &&
      ((*(int *)(param_1 + 0x34) == *(int *)(param_2 + 0x34) &&
       ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
        iVar3 != 0 &&
        (iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
        iVar3 != 0)))))) &&
     ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_2 + 0x28)),
      iVar3 != 0 &&
      ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x2c)),
       iVar3 != 0 &&
       (iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_2 + 0x30)),
       iVar3 != 0)))))) {
    iVar3 = *(int *)(param_1 + 0x34) << 2;
    pcVar4 = *(char **)(param_1 + 0x38);
    pcVar5 = *(char **)(param_2 + 0x38);
    do {
      if (iVar3 == 0) {
        return 1;
      }
      iVar3 = iVar3 + -1;
      cVar2 = *pcVar5;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 == cVar2);
  }
  return 0;
}


// 005d858a FUN_005d858a

undefined4 * __fastcall FUN_005d858a(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  pvVar1 = _malloc(0x3c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d844d();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
  puVar2[0xd] = *(undefined4 *)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    puVar2[9] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
    puVar2[0xb] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 8))();
    puVar2[0xc] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    return puVar2;
  }
  puVar4 = _malloc(*(int *)(param_1 + 0x34) << 2);
  puVar2[0xe] = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)(param_1 + 0x38);
    for (uVar5 = *(uint *)(param_1 + 0x34) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    return puVar2;
  }
LAB_005d8644:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d86ec FUN_005d86ec

undefined4 __thiscall FUN_005d86ec(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
       iVar1 != 0 &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
       iVar1 != 0)) &&
      ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
       iVar1 != 0 &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
       iVar1 != 0)))))) {
    return 1;
  }
  return 0;
}


// 005d875d FUN_005d875d

undefined4 * __fastcall FUN_005d875d(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x28);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8670();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x24) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
  puVar2[9] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d87e3:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d88ba FUN_005d88ba

undefined4 __thiscall FUN_005d88ba(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((((iVar1 != 0) && (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
        (*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18))) &&
       ((*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c) &&
        (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))))) &&
      ((iVar1 = FUN_005d79dc(), iVar1 != 0 &&
       ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
        iVar1 != 0 &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
        iVar1 != 0)))))) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// 005d8934 FUN_005d8934

undefined4 * __fastcall FUN_005d8934(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar1 = _malloc(0x50);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d87f4();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
  puVar2[10] = *(undefined4 *)(param_1 + 0x28);
  puVar4 = (undefined4 *)(param_1 + 0x30);
  puVar5 = puVar2 + 0xc;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d89b8;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d89b8;
  }
  if (*(int **)(param_1 + 0x24) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
  puVar2[9] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d89b8:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d8ce2 FUN_005d8ce2

undefined4 __thiscall FUN_005d8ce2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
       iVar1 != 0)) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// 005d8d2d FUN_005d8d2d

undefined4 * __fastcall FUN_005d8d2d(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8c5a();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d8d87;
  }
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d8d87;
  }
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
  puVar2[6] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8d87:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005d8e14 FUN_005d8e14

bool __thiscall FUN_005d8e14(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((iVar1 != 0) && (iVar1 = FUN_005d79dc(), iVar1 != 0)) {
    return *(int *)(param_2 + 0x30) == *(int *)(param_1 + 0x30);
  }
  return false;
}


// 005d8e49 FUN_005d8e49

int __fastcall FUN_005d8e49(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  pvVar2 = _malloc(0x38);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005d8d98();
  }
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0x10);
    puVar6 = (undefined4 *)(iVar3 + 0x10);
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(param_1 + 0x30);
    piVar1 = *(int **)(param_1 + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return iVar3;
}


// 005d8f06 FUN_005d8f06

undefined4 __thiscall FUN_005d8f06(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if (((iVar1 != 0) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// 005d8f42 FUN_005d8f42

undefined4 * __fastcall FUN_005d8f42(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x18);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8e95();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d8f89;
  }
  if (*(int **)(param_1 + 0x14) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
  puVar2[5] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8f89:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// 005e6a37 FUN_005e6a37

int FUN_005e6a37(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  pbVar8 = *(byte **)*param_1;
  if ((((DAT_006a3654 == *(short *)pbVar8) || (DAT_006a3650 == *(short *)pbVar8)) ||
      (pbVar6 = *(byte **)*param_2, DAT_006a3654 == *(short *)pbVar6)) ||
     (pbVar3 = pbVar8, pbVar4 = pbVar6, DAT_006a3650 == *(short *)pbVar6)) {
    pbVar6 = *(byte **)*param_2;
    do {
      bVar1 = *pbVar8;
      bVar9 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) goto LAB_005e6ab5;
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar9 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_005e6ab5;
      pbVar8 = pbVar8 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
  }
  else {
    do {
      bVar1 = pbVar3[2];
      bVar2 = pbVar4[2];
      bVar9 = bVar1 < bVar2;
      if (bVar1 != bVar2) {
LAB_005e6aa0:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_005e6aa5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[3];
      bVar9 = bVar1 < pbVar4[3];
      if (bVar1 != pbVar4[3]) goto LAB_005e6aa0;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_005e6aa5:
    if (iVar5 == 0) {
      iVar7 = 2;
      bVar9 = false;
      iVar5 = 0;
      bVar10 = true;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar9 = *pbVar8 < *pbVar6;
        bVar10 = *pbVar8 == *pbVar6;
        pbVar8 = pbVar8 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar10);
      if (!bVar10) {
LAB_005e6ab5:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
    }
  }
  return iVar5;
}


// 005eb185 FUN_005eb185

float * FUN_005eb185(float *param_1,float *param_2,float *param_3)

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
  
  fVar3 = param_3[1];
  fVar4 = param_3[2];
  fVar5 = param_3[3];
  fVar1 = *param_2;
  fVar6 = param_3[5];
  fVar7 = param_3[6];
  fVar8 = param_3[7];
  fVar2 = param_2[1];
  fVar9 = param_3[0xd];
  fVar10 = param_3[0xe];
  fVar11 = param_3[0xf];
  *param_1 = fVar1 * *param_3 + param_3[0xc] + fVar2 * param_3[4];
  param_1[1] = fVar1 * fVar3 + fVar9 + fVar2 * fVar6;
  param_1[2] = fVar1 * fVar4 + fVar10 + fVar2 * fVar7;
  param_1[3] = fVar1 * fVar5 + fVar11 + fVar2 * fVar8;
  return param_1;
}


// 005eb1c3 FUN_005eb1c3

undefined8 * FUN_005eb1c3(undefined8 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined1 in_XMM0 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar4 = fVar1 * *param_3 + param_3[0xc] + fVar2 * param_3[4];
  fVar5 = fVar1 * param_3[1] + param_3[0xd] + fVar2 * param_3[5];
  fVar6 = fVar1 * param_3[3] + param_3[0xf] + fVar2 * param_3[7];
  auVar3._4_4_ = fVar5;
  auVar3._0_4_ = fVar4;
  auVar3._8_4_ = fVar1 * param_3[2] + param_3[0xe] + fVar2 * param_3[6];
  auVar3._12_4_ = fVar6;
  auVar3 = rcpps(in_XMM0,auVar3);
  fVar6 = auVar3._12_4_ * auVar3._12_4_ * fVar6;
  *param_1 = CONCAT44(fVar5 * fVar6,fVar4 * fVar6);
  return param_1;
}


// 005eb21a FUN_005eb21a

undefined8 * FUN_005eb21a(undefined8 *param_1,float *param_2,float *param_3)

{
  *param_1 = CONCAT44(*param_2 * param_3[1] + param_2[1] * param_3[5],
                      *param_2 * *param_3 + param_2[1] * param_3[4]);
  return param_1;
}


// 005eb826 FUN_005eb826

undefined8 *
FUN_005eb826(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *(float *)(param_2 + 1);
  uVar2 = *param_3;
  fVar4 = (float)*param_2;
  fVar5 = (float)((ulonglong)*param_2 >> 0x20);
  uVar3 = *param_4;
  *(float *)(param_1 + 1) =
       (*(float *)(param_3 + 1) - fVar1) * param_5 + fVar1 +
       (*(float *)(param_4 + 1) - fVar1) * param_6;
  *param_1 = CONCAT44(((float)((ulonglong)uVar2 >> 0x20) - fVar5) * param_5 + fVar5 +
                      ((float)((ulonglong)uVar3 >> 0x20) - fVar5) * param_6,
                      ((float)uVar2 - fVar4) * param_5 + fVar4 + ((float)uVar3 - fVar4) * param_6);
  return param_1;
}


// 005eb883 FUN_005eb883

float * FUN_005eb883(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                    float param_6)

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
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar5 = param_3[1];
  fVar6 = param_3[2];
  fVar7 = param_3[3];
  fVar8 = param_4[1];
  fVar9 = param_4[2];
  fVar10 = param_4[3];
  *param_1 = (*param_3 - fVar1) * param_5 + fVar1 + (*param_4 - fVar1) * param_6;
  param_1[1] = (fVar5 - fVar2) * param_5 + fVar2 + (fVar8 - fVar2) * param_6;
  param_1[2] = (fVar6 - fVar3) * param_5 + fVar3 + (fVar9 - fVar3) * param_6;
  param_1[3] = (fVar7 - fVar4) * param_5 + fVar4 + (fVar10 - fVar4) * param_6;
  return param_1;
}


// 005eb8cc FUN_005eb8cc

undefined8 *
FUN_005eb8cc(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)*param_2;
  fVar2 = (float)((ulonglong)*param_2 >> 0x20);
  *param_1 = CONCAT44(((float)((ulonglong)*param_3 >> 0x20) - fVar2) * param_5 + fVar2 +
                      ((float)((ulonglong)*param_4 >> 0x20) - fVar2) * param_6,
                      ((float)*param_3 - fVar1) * param_5 + fVar1 +
                      ((float)*param_4 - fVar1) * param_6);
  return param_1;
}


// 005ece7a FUN_005ece7a

undefined8 * FUN_005ece7a(undefined8 *param_1,float *param_2,undefined8 *param_3)

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
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar17 = (float)*param_3;
  fVar18 = (float)((ulonglong)*param_3 >> 0x20);
  fVar19 = (float)param_3[1];
  fVar20 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar21 = (float)param_3[2];
  fVar22 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar23 = (float)param_3[3];
  fVar24 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar25 = (float)param_3[4];
  fVar26 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar27 = (float)param_3[5];
  fVar28 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar29 = (float)param_3[6];
  fVar30 = (float)((ulonglong)param_3[6] >> 0x20);
  fVar31 = (float)param_3[7];
  fVar32 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = param_2[8];
  fVar10 = param_2[9];
  fVar11 = param_2[10];
  fVar12 = param_2[0xb];
  fVar13 = param_2[0xc];
  fVar14 = param_2[0xd];
  fVar15 = param_2[0xe];
  fVar16 = param_2[0xf];
  *param_1 = CONCAT44(fVar1 * fVar18 + fVar2 * fVar22 + fVar3 * fVar26 + fVar4 * fVar30,
                      fVar1 * fVar17 + fVar2 * fVar21 + fVar3 * fVar25 + fVar4 * fVar29);
  param_1[1] = CONCAT44(fVar1 * fVar20 + fVar2 * fVar24 + fVar3 * fVar28 + fVar4 * fVar32,
                        fVar1 * fVar19 + fVar2 * fVar23 + fVar3 * fVar27 + fVar4 * fVar31);
  param_1[2] = CONCAT44(fVar5 * fVar18 + fVar6 * fVar22 + fVar7 * fVar26 + fVar8 * fVar30,
                        fVar5 * fVar17 + fVar6 * fVar21 + fVar7 * fVar25 + fVar8 * fVar29);
  param_1[3] = CONCAT44(fVar5 * fVar20 + fVar6 * fVar24 + fVar7 * fVar28 + fVar8 * fVar32,
                        fVar5 * fVar19 + fVar6 * fVar23 + fVar7 * fVar27 + fVar8 * fVar31);
  param_1[4] = CONCAT44(fVar9 * fVar18 + fVar10 * fVar22 + fVar11 * fVar26 + fVar12 * fVar30,
                        fVar9 * fVar17 + fVar10 * fVar21 + fVar11 * fVar25 + fVar12 * fVar29);
  param_1[5] = CONCAT44(fVar9 * fVar20 + fVar10 * fVar24 + fVar11 * fVar28 + fVar12 * fVar32,
                        fVar9 * fVar19 + fVar10 * fVar23 + fVar11 * fVar27 + fVar12 * fVar31);
  param_1[6] = CONCAT44(fVar18 * fVar13 + fVar22 * fVar14 + fVar26 * fVar15 + fVar30 * fVar16,
                        fVar17 * fVar13 + fVar21 * fVar14 + fVar25 * fVar15 + fVar29 * fVar16);
  param_1[7] = CONCAT44(fVar20 * fVar13 + fVar24 * fVar14 + fVar28 * fVar15 + fVar32 * fVar16,
                        fVar19 * fVar13 + fVar23 * fVar14 + fVar27 * fVar15 + fVar31 * fVar16);
  return param_1;
}


// 005ee000 FUN_005ee000

float * FUN_005ee000(float *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
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
  float *pfVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  
  pfVar14 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar23 = FUN_005f4cfb(pfVar14,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar23 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      pfVar14 = (float *)((int)uVar23 + param_2);
    }
  }
  else {
    fVar2 = *param_5;
    fVar3 = param_5[1];
    fVar4 = param_5[2];
    fVar5 = param_5[3];
    fVar6 = param_5[4];
    fVar7 = param_5[5];
    fVar8 = param_5[6];
    fVar9 = param_5[7];
    fVar10 = param_5[0xc];
    fVar11 = param_5[0xd];
    fVar12 = param_5[0xe];
    fVar13 = param_5[0xf];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar15 = (float)*param_3;
        fVar16 = (float)((ulonglong)*param_3 >> 0x20);
        fVar17 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar18 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar19 = (float)*param_3;
        fVar20 = (float)((ulonglong)*param_3 >> 0x20);
        fVar21 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar22 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        *pfVar14 = fVar15 * fVar2 + fVar16 * fVar6 + fVar10;
        pfVar14[1] = fVar15 * fVar3 + fVar16 * fVar7 + fVar11;
        pfVar14[2] = fVar15 * fVar4 + fVar16 * fVar8 + fVar12;
        pfVar14[3] = fVar15 * fVar5 + fVar16 * fVar9 + fVar13;
        pfVar1 = (float *)(param_2 + (int)pfVar14);
        *pfVar1 = fVar17 * fVar2 + fVar18 * fVar6 + fVar10;
        pfVar1[1] = fVar17 * fVar3 + fVar18 * fVar7 + fVar11;
        pfVar1[2] = fVar17 * fVar4 + fVar18 * fVar8 + fVar12;
        pfVar1[3] = fVar17 * fVar5 + fVar18 * fVar9 + fVar13;
        pfVar14 = (float *)((int)pfVar14 + param_2 * 2);
        *pfVar14 = fVar19 * fVar2 + fVar20 * fVar6 + fVar10;
        pfVar14[1] = fVar19 * fVar3 + fVar20 * fVar7 + fVar11;
        pfVar14[2] = fVar19 * fVar4 + fVar20 * fVar8 + fVar12;
        pfVar14[3] = fVar19 * fVar5 + fVar20 * fVar9 + fVar13;
        pfVar1 = (float *)(param_2 + (int)pfVar14);
        *pfVar1 = fVar21 * fVar2 + fVar22 * fVar6 + fVar10;
        pfVar1[1] = fVar21 * fVar3 + fVar22 * fVar7 + fVar11;
        pfVar1[2] = fVar21 * fVar4 + fVar22 * fVar8 + fVar12;
        pfVar1[3] = fVar21 * fVar5 + fVar22 * fVar9 + fVar13;
        pfVar14 = (float *)((int)pfVar14 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      pfVar14 = (float *)((int)pfVar14 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// 005ee4c0 FUN_005ee4c0

undefined8 *
FUN_005ee4c0(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  
  puVar5 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar14 = FUN_005f4d50(puVar5,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar14 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar5 = (undefined8 *)((int)uVar14 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[4];
    fVar4 = param_5[5];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar6 = (float)*param_3;
        fVar7 = (float)((ulonglong)*param_3 >> 0x20);
        fVar8 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar9 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar10 = (float)*param_3;
        fVar11 = (float)((ulonglong)*param_3 >> 0x20);
        fVar12 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar13 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        *puVar5 = CONCAT44(fVar6 * fVar2 + fVar7 * fVar4,fVar6 * fVar1 + fVar7 * fVar3);
        *(ulonglong *)(param_2 + (int)puVar5) =
             CONCAT44(fVar8 * fVar2 + fVar9 * fVar4,fVar8 * fVar1 + fVar9 * fVar3);
        puVar5 = (undefined8 *)((int)puVar5 + param_2 * 2);
        *puVar5 = CONCAT44(fVar10 * fVar2 + fVar11 * fVar4,fVar10 * fVar1 + fVar11 * fVar3);
        *(ulonglong *)(param_2 + (int)puVar5) =
             CONCAT44(fVar12 * fVar2 + fVar13 * fVar4,fVar12 * fVar1 + fVar13 * fVar3);
        puVar5 = (undefined8 *)((int)puVar5 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// 005ee720 FUN_005ee720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005ee720(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

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
  undefined8 *puVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar29;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  undefined8 uVar36;
  
  puVar21 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar36 = thunk_FUN_005f42ad(puVar21,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar36 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar21 = (undefined8 *)((int)uVar36 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[2];
    fVar4 = param_5[3];
    fVar5 = param_5[4];
    fVar6 = param_5[5];
    fVar7 = param_5[6];
    fVar8 = param_5[7];
    fVar9 = param_5[8];
    fVar10 = param_5[9];
    fVar11 = param_5[10];
    fVar12 = param_5[0xb];
    fVar13 = param_5[0xc];
    fVar14 = param_5[0xd];
    fVar15 = param_5[0xe];
    fVar16 = param_5[0xf];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar22 = (float)*param_3;
        fVar23 = (float)((ulonglong)*param_3 >> 0x20);
        fVar24 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar25 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar17 = *(float *)(param_3 + 1);
        fVar18 = *(float *)(param_4 + 8 + (int)param_3);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar30 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar32 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar19 = *(float *)(param_3 + 1);
        fVar20 = *(float *)(param_4 + 8 + (int)param_3);
        fVar29 = (float)((ulonglong)*param_3 >> 0x20);
        fVar26 = (float)*param_3;
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        auVar27._0_4_ = fVar17 * fVar10;
        auVar27._4_4_ = fVar18 * fVar10;
        auVar27._8_4_ = fVar19 * fVar10;
        auVar27._12_4_ = fVar20 * fVar10;
        fVar31 = fVar22 * fVar4 + fVar23 * fVar8 + fVar17 * fVar12 + fVar16;
        fVar33 = fVar24 * fVar4 + fVar25 * fVar8 + fVar18 * fVar12 + fVar16;
        fVar34 = fVar26 * fVar4 + fVar29 * fVar8 + fVar19 * fVar12 + fVar16;
        fVar35 = fVar30 * fVar4 + fVar32 * fVar8 + fVar20 * fVar12 + fVar16;
        auVar28._4_4_ = fVar33;
        auVar28._0_4_ = fVar31;
        auVar28._8_4_ = fVar34;
        auVar28._12_4_ = fVar35;
        auVar28 = rcpps(auVar27,auVar28);
        fVar31 = auVar28._0_4_ * (_DAT_006df380 - fVar31 * auVar28._0_4_);
        fVar33 = auVar28._4_4_ * (fRam006df384 - fVar33 * auVar28._4_4_);
        fVar34 = auVar28._8_4_ * (fRam006df388 - fVar34 * auVar28._8_4_);
        fVar35 = auVar28._12_4_ * (fRam006df38c - fVar35 * auVar28._12_4_);
        *puVar21 = CONCAT44((fVar22 * fVar2 + fVar23 * fVar6 + auVar27._0_4_ + fVar14) * fVar31,
                            (fVar22 * fVar1 + fVar23 * fVar5 + fVar17 * fVar9 + fVar13) * fVar31);
        *(float *)(puVar21 + 1) =
             (fVar22 * fVar3 + fVar23 * fVar7 + fVar17 * fVar11 + fVar15) * fVar31;
        *(ulonglong *)(param_2 + (int)puVar21) =
             CONCAT44((fVar24 * fVar2 + fVar25 * fVar6 + auVar27._4_4_ + fVar14) * fVar33,
                      (fVar24 * fVar1 + fVar25 * fVar5 + fVar18 * fVar9 + fVar13) * fVar33);
        *(float *)(param_2 + 8 + (int)puVar21) =
             (fVar24 * fVar3 + fVar25 * fVar7 + fVar18 * fVar11 + fVar15) * fVar33;
        puVar21 = (undefined8 *)((int)puVar21 + param_2 * 2);
        *puVar21 = CONCAT44((fVar26 * fVar2 + fVar29 * fVar6 + auVar27._8_4_ + fVar14) * fVar34,
                            (fVar26 * fVar1 + fVar29 * fVar5 + fVar19 * fVar9 + fVar13) * fVar34);
        *(float *)(puVar21 + 1) =
             (fVar26 * fVar3 + fVar29 * fVar7 + fVar19 * fVar11 + fVar15) * fVar34;
        *(ulonglong *)(param_2 + (int)puVar21) =
             CONCAT44((fVar30 * fVar2 + fVar32 * fVar6 + auVar27._12_4_ + fVar14) * fVar35,
                      (fVar30 * fVar1 + fVar32 * fVar5 + fVar20 * fVar9 + fVar13) * fVar35);
        *(float *)(param_2 + 8 + (int)puVar21) =
             (fVar30 * fVar3 + fVar32 * fVar7 + fVar20 * fVar11 + fVar15) * fVar35;
        puVar21 = (undefined8 *)((int)puVar21 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar21 = (undefined8 *)((int)puVar21 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// 005eecbc FUN_005eecbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eecbc(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar3 = *param_3;
  uVar5 = param_3[1];
  uVar8 = *param_2;
  uVar1 = param_2[1];
  uVar4 = CONCAT44((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar6 = CONCAT44((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  uVar2 = PackedFloatingMUL(uVar3,uVar1);
  uVar3 = PackedFloatingMUL(uVar5,uVar8);
  uVar7 = PackedFloatingMUL(uVar6 ^ _DAT_006a07a0,uVar8);
  uVar5 = PackedFloatingMUL(uVar4,uVar1);
  uVar3 = PackedFloatingADD(uVar2 ^ _DAT_006a07a0,uVar3);
  uVar5 = PackedFloatingSUB(uVar5,uVar7);
  uVar9 = PackedFloatingMUL(uVar6,uVar1);
  uVar5 = PackedFloatingAccumulate(uVar5,uVar3);
  uVar7 = PackedFloatingMUL(uVar4 ^ _DAT_006a07a0,uVar8);
  uVar2 = param_3[1] ^ _DAT_006a07a0;
  uVar3 = PackedFloatingMUL(*param_3,uVar8);
  *param_1 = uVar5;
  uVar5 = PackedFloatingMUL(uVar2,uVar1);
  uVar8 = PackedFloatingADD(uVar7,uVar9);
  uVar3 = PackedFloatingSUB(uVar5,uVar3);
  uVar3 = PackedFloatingAccumulate(uVar8,uVar3);
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// 005eed55 FUN_005eed55

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eed55(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar3);
  uVar6 = PackedFloatingCompareGT(uVar3,_DAT_006a07f8);
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


// 005eedf6 FUN_005eedf6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eedf6(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  
  uVar2 = *param_2;
  uVar8 = (ulonglong)*(uint *)((int)param_2 + 0x14);
  uVar1 = PackedFloatingADD(uVar2,uVar8);
  uVar10 = (ulonglong)*(uint *)(param_2 + 5);
  uVar3 = PackedFloatingSUB(uVar2,uVar8);
  uVar5 = PackedFloatingSUBR(uVar2,uVar8);
  uVar7 = PackedFloatingSUBR(uVar2,uVar10);
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  lVar4 = PackedFloatingSUB(uVar3,uVar10);
  uVar1 = PackedFloatingSUB(uVar5,uVar10);
  uVar3 = PackedFloatingSUB(uVar7,uVar8);
  uVar2 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar5 = PackedFloatingCompareGE(lVar4 << 0x20,uVar2);
  uVar7 = PackedFloatingCompareGE(CONCAT44((int)lVar4,(int)uVar1),uVar3);
  uVar5 = packssdw(uVar5,uVar7);
  uVar10 = packsswb(uVar5,uVar5);
  uVar9 = (undefined4)param_2[4];
  uVar6 = (undefined4)((ulonglong)lVar4 >> 0x20);
  uVar11 = (undefined4)((ulonglong)param_2[4] >> 0x20);
  if ((uVar10 & 1) == 0) {
    uVar2 = PackedFloatingADD(uVar2,_DAT_006a0778);
    uVar1 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar3 = PackedFloatingMUL(uVar1,uVar1);
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar3,uVar2);
    uVar3 = PackedFloatingSUB(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11));
    uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar1);
    uVar1 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar5,DAT_006a07f0);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    *param_1 = uVar3;
    param_1[1] = CONCAT44((int)uVar2,(int)uVar1);
    FastExitMediaState();
    return;
  }
  if (((uint)uVar10 & 0xff00ff00) == 0xff00ff00) {
    uVar2 = PackedFloatingADD(lVar4,_DAT_006a0778);
    uVar6 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar1 = PackedFloatingSUB((ulonglong)*(uint *)(param_2 + 2),CONCAT44(uVar6,uVar6));
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
    uVar3 = PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar3 = PackedFloatingMUL(uVar3,DAT_006a07f0);
    uVar2 = PackedFloatingMUL(uVar2,uVar3);
    uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                              CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)) ^ DAT_006a07a8);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar3 = PackedFloatingMUL(uVar5,uVar3);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  if ((uVar10 & 0x10000) != 0) {
    uVar2 = PackedFloatingADD(uVar1,_DAT_006a0778);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar1 = CONCAT44((int)uVar2,(int)uVar2);
    uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
    uVar3 = PackedFloatingReciprocalIter2(uVar2,uVar3);
    uVar2 = PackedFloatingADD(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar3,DAT_006a07f0);
    uVar3 = PackedFloatingADD(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11) ^ DAT_006a07a8);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  uVar3 = PackedFloatingADD(uVar3,_DAT_006a0778);
  uVar2 = PackedFloatingReciprocalSQRAprox(uVar1,uVar3);
  uVar1 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar1 = PackedFloatingReciprocalSQRIter1(uVar1,uVar3);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
  uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                            CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)));
  uVar1 = PackedFloatingMUL(uVar1,DAT_006a07f0);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar1 = PackedFloatingMUL(uVar5,uVar1);
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,(int)uVar3);
  FastExitMediaState();
  return;
}


// 005ef012 FUN_005ef012

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ef012(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  
  uVar2 = *param_2;
  uVar8 = (ulonglong)*(uint *)((int)param_2 + 0x14);
  uVar1 = PackedFloatingADD(uVar2,uVar8);
  uVar10 = (ulonglong)*(uint *)(param_2 + 5);
  uVar3 = PackedFloatingSUB(uVar2,uVar8);
  uVar5 = PackedFloatingSUBR(uVar2,uVar8);
  uVar7 = PackedFloatingSUBR(uVar2,uVar10);
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  lVar4 = PackedFloatingSUB(uVar3,uVar10);
  uVar1 = PackedFloatingSUB(uVar5,uVar10);
  uVar3 = PackedFloatingSUB(uVar7,uVar8);
  uVar2 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar5 = PackedFloatingCompareGE(lVar4 << 0x20,uVar2);
  uVar7 = PackedFloatingCompareGE(CONCAT44((int)lVar4,(int)uVar1),uVar3);
  uVar10 = packssdw(uVar5,uVar7);
  uVar9 = (undefined4)param_2[4];
  uVar6 = (undefined4)((ulonglong)lVar4 >> 0x20);
  uVar11 = (undefined4)((ulonglong)param_2[4] >> 0x20);
  if ((uVar10 >> 7 & 1) == 0) {
    uVar2 = PackedFloatingADD(uVar2,_DAT_006a0778);
    uVar1 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar3 = PackedFloatingMUL(uVar1,uVar1);
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar3,uVar2);
    uVar3 = PackedFloatingSUB(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11));
    uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar1);
    uVar1 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar5,DAT_006a07f0);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    *param_1 = uVar3;
    param_1[1] = CONCAT44((int)uVar2,(int)uVar1);
    FastExitMediaState();
    return;
  }
  if ((byte)(((byte)(uVar10 >> 0x17) & 1) << 2 | ((byte)(uVar10 >> 0x1f) & 1) << 3 |
             ((byte)(uVar10 >> 0x37) & 1) << 6 | (byte)(uVar10 >> 0x38) & 0x80) == 0xcc) {
    uVar2 = PackedFloatingADD(lVar4,_DAT_006a0778);
    uVar6 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar1 = PackedFloatingSUB((ulonglong)*(uint *)(param_2 + 2),CONCAT44(uVar6,uVar6));
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
    uVar3 = PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar3 = PackedFloatingMUL(uVar3,DAT_006a07f0);
    uVar2 = PackedFloatingMUL(uVar2,uVar3);
    uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                              CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)) ^ DAT_006a07a8);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar3 = PackedFloatingMUL(uVar5,uVar3);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  if ((uVar10 >> 0x27 & 1) != 0) {
    uVar2 = PackedFloatingADD(uVar1,_DAT_006a0778);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar1 = CONCAT44((int)uVar2,(int)uVar2);
    uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
    uVar3 = PackedFloatingReciprocalIter2(uVar2,uVar3);
    uVar2 = PackedFloatingADD(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar3,DAT_006a07f0);
    uVar3 = PackedFloatingADD(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11) ^ DAT_006a07a8);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  uVar3 = PackedFloatingADD(uVar3,_DAT_006a0778);
  uVar2 = PackedFloatingReciprocalSQRAprox(uVar1,uVar3);
  uVar1 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar1 = PackedFloatingReciprocalSQRIter1(uVar1,uVar3);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
  uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                            CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)));
  uVar1 = PackedFloatingMUL(uVar1,DAT_006a07f0);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar1 = PackedFloatingMUL(uVar5,uVar1);
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,(int)uVar3);
  FastExitMediaState();
  return;
}


// 005ef227 FUN_005ef227

void FUN_005ef227(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  
  FastExitMediaState();
  PackedFloatingMUL(DAT_006a0818,param_3);
  PackedFloatingMUL(DAT_006a0818,param_2);
  uVar2 = FUN_0061bee0();
  uVar3 = FUN_0061bee0();
  uVar4 = FUN_0061bee0();
  uVar1 = (undefined4)uVar4;
  uVar7 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar4 = CONCAT44((int)uVar3,(int)uVar3);
  uVar9 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar8 = CONCAT44(uVar9,uVar9);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1) ^ DAT_006a0808,uVar8);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar4);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar7,uVar7) ^ DAT_006a0808 >> 0x20,uVar8);
  uVar10 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar4 = PackedFloatingMUL(uVar5,uVar10);
  uVar5 = PackedFloatingMUL(uVar6,uVar10);
  uVar6 = PackedFloatingMUL(uVar8,uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingADD(uVar4,uVar6);
  *param_1 = uVar2;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// 005ef5ae FUN_005ef5ae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ef5ae(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  ulonglong uVar5;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar4 = FloatingReciprocalAprox(in_MM4,uVar3);
  uVar5 = PackedFloatingCompareGT(uVar3,_DAT_006a07f8);
  uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar4);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar4);
  uVar4 = PackedFloatingMUL((uVar1 ^ _DAT_006a0858) & uVar5,uVar3);
  uVar3 = PackedFloatingMUL((uVar2 ^ _DAT_006a07a0) & uVar5,uVar3);
  *param_1 = uVar4;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// 005ef6b9 FUN_005ef6b9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ef6b9(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 unaff_ESI;
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar1 = PackedFloatingMUL(*param_2,*param_2);
  uVar4 = PackedFloatingMUL((ulonglong)*(uint *)(param_2 + 1),(ulonglong)*(uint *)(param_2 + 1));
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar4 = PackedFloatingReciprocalSQRAprox(uVar4,uVar1);
  uVar5 = PackedFloatingMUL(uVar4,uVar4);
  uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
  uVar4 = PackedFloatingReciprocalIter2(uVar5,uVar4);
  PackedFloatingMUL(uVar1,uVar4);
  uVar2 = FUN_0061bee0();
  uVar3 = PackedFloatingCompareGE(uVar2 & _DAT_006a07c0,DAT_006a07d0);
  uVar1 = *param_2;
  uVar6 = (undefined4)(uVar2 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),CONCAT44(unaff_ESI,(int)uVar4));
  uVar7 = *(uint *)(param_2 + 1);
  if ((uVar3 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar5 = PackedFloatingMUL((ulonglong)uVar7,uVar4);
    uVar7 = (uint)uVar5;
    uVar1 = PackedFloatingMUL(uVar1,uVar4);
  }
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,uVar7);
  FastExitMediaState();
  return;
}


// 005f0197 FUN_005f0197

void FUN_005f0197(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

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
  undefined8 uVar17;
  undefined8 uVar18;
  
  FastExitMediaState();
  uVar3 = CONCAT44((int)param_3[2],(int)*param_3);
  uVar11 = CONCAT44((int)((ulonglong)param_3[2] >> 0x20),(int)((ulonglong)*param_3 >> 0x20));
  uVar7 = CONCAT44((int)param_3[7],(int)param_3[5]);
  uVar12 = CONCAT44((int)((ulonglong)param_3[7] >> 0x20),(int)((ulonglong)param_3[5] >> 0x20));
  uVar15 = CONCAT44((int)param_3[3],(int)param_3[1]);
  uVar17 = CONCAT44((int)((ulonglong)param_3[3] >> 0x20),(int)((ulonglong)param_3[1] >> 0x20));
  uVar9 = CONCAT44((int)((ulonglong)param_3[6] >> 0x20),(int)((ulonglong)param_3[4] >> 0x20));
  uVar14 = CONCAT44((int)param_3[6],(int)param_3[4]);
  uVar2 = *param_2;
  uVar5 = param_2[1];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  *param_1 = uVar2;
  param_1[1] = uVar5;
  uVar2 = param_2[2];
  uVar5 = param_2[3];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  param_1[2] = uVar2;
  param_1[3] = uVar5;
  uVar2 = param_2[4];
  uVar5 = param_2[5];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  param_1[4] = uVar2;
  param_1[5] = uVar5;
  uVar2 = param_2[6];
  uVar5 = param_2[7];
  uVar3 = PackedFloatingMUL(uVar2,uVar3);
  uVar1 = PackedFloatingMUL(uVar5,uVar14);
  uVar4 = PackedFloatingMUL(uVar2,uVar11);
  uVar9 = PackedFloatingMUL(uVar5,uVar9);
  uVar11 = PackedFloatingMUL(uVar2,uVar15);
  uVar14 = PackedFloatingMUL(uVar5,uVar7);
  uVar17 = PackedFloatingMUL(uVar2,uVar17);
  uVar6 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar3,uVar4);
  uVar5 = PackedFloatingAccumulate(uVar1,uVar9);
  uVar3 = PackedFloatingAccumulate(uVar11,uVar17);
  uVar9 = PackedFloatingAccumulate(uVar14,uVar6);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar3,uVar9);
  param_1[6] = uVar2;
  param_1[7] = uVar5;
  FastExitMediaState();
  return;
}


// 005f01b8 FUN_005f01b8

void __fastcall FUN_005f01b8(undefined4 param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int unaff_EBP;
  undefined8 in_MM0;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_MM1;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 in_MM3;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 in_MM4;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  uVar5 = CONCAT44((int)in_MM1,(int)in_MM0);
  uVar13 = CONCAT44((int)((ulonglong)in_MM1 >> 0x20),(int)((ulonglong)in_MM0 >> 0x20));
  uVar9 = CONCAT44((int)in_MM4,(int)in_MM3);
  uVar14 = CONCAT44((int)((ulonglong)in_MM4 >> 0x20),(int)((ulonglong)in_MM3 >> 0x20));
  puVar1 = *(undefined8 **)(unaff_EBP + 0x4c);
  uVar17 = CONCAT44((int)*(undefined8 *)(param_2 + 0x18),(int)*(undefined8 *)(param_2 + 8));
  uVar19 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x18) >> 0x20),
                    (int)((ulonglong)*(undefined8 *)(param_2 + 8) >> 0x20));
  uVar11 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x30) >> 0x20),
                    (int)((ulonglong)*(undefined8 *)(param_2 + 0x20) >> 0x20));
  uVar16 = CONCAT44((int)*(undefined8 *)(param_2 + 0x30),(int)*(undefined8 *)(param_2 + 0x20));
  puVar2 = *(undefined8 **)(unaff_EBP + 0x48);
  uVar4 = *puVar1;
  uVar7 = puVar1[1];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  *puVar2 = uVar4;
  puVar2[1] = uVar7;
  uVar4 = puVar1[2];
  uVar7 = puVar1[3];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  puVar2[2] = uVar4;
  puVar2[3] = uVar7;
  uVar4 = puVar1[4];
  uVar7 = puVar1[5];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  puVar2[4] = uVar4;
  puVar2[5] = uVar7;
  uVar4 = puVar1[6];
  uVar7 = puVar1[7];
  uVar5 = PackedFloatingMUL(uVar4,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,uVar16);
  uVar6 = PackedFloatingMUL(uVar4,uVar13);
  uVar11 = PackedFloatingMUL(uVar7,uVar11);
  uVar13 = PackedFloatingMUL(uVar4,uVar17);
  uVar16 = PackedFloatingMUL(uVar7,uVar9);
  uVar19 = PackedFloatingMUL(uVar4,uVar19);
  uVar8 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar5,uVar6);
  uVar7 = PackedFloatingAccumulate(uVar3,uVar11);
  uVar5 = PackedFloatingAccumulate(uVar13,uVar19);
  uVar11 = PackedFloatingAccumulate(uVar16,uVar8);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar5,uVar11);
  puVar2[6] = uVar4;
  puVar2[7] = uVar7;
  FastExitMediaState();
  return;
}


// 005f03c9 FUN_005f03c9

float10 FUN_005f03c9(undefined4 *param_1)

{
  undefined4 uVar2;
  undefined8 uVar1;
  undefined8 uVar3;
  undefined4 uVar7;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar8;
  
  uVar2 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 10) >> 0x20);
  uVar7 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0xe) >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),*(undefined8 *)(param_1 + 9));
  uVar1 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),*(undefined8 *)(param_1 + 0xd));
  uVar5 = PackedFloatingSUB(uVar4,uVar1);
  uVar1 = PackedFloatingMUL(CONCAT44((int)*(undefined8 *)(param_1 + 8),
                                     (int)*(undefined8 *)(param_1 + 8)),
                            *(undefined8 *)(param_1 + 0xe));
  uVar4 = PackedFloatingMUL(CONCAT44((int)*(undefined8 *)(param_1 + 0xc),
                                     (int)*(undefined8 *)(param_1 + 0xc)),
                            *(undefined8 *)(param_1 + 10));
  uVar4 = PackedFloatingSUB(uVar1,uVar4);
  uVar3 = PackedFloatingMUL(*(undefined8 *)(param_1 + 0xd),*(undefined8 *)(param_1 + 8));
  uVar1 = PackedFloatingMUL(*(undefined8 *)(param_1 + 9),*(undefined8 *)(param_1 + 0xc));
  uVar3 = PackedFloatingSUB(uVar3,uVar1);
  uVar2 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
  uVar6 = PackedFloatingMUL(uVar5,*(undefined8 *)(param_1 + 4));
  uVar1 = PackedFloatingMUL(uVar3,CONCAT44(uVar2,uVar2));
  uVar6 = PackedFloatingADD(uVar6,uVar1);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)((ulonglong)uVar4 >> 0x20)),
                            *(undefined8 *)(param_1 + 5));
  uVar1 = PackedFloatingSUB(uVar6,uVar1);
  uVar6 = PackedFloatingMUL(uVar1,CONCAT44(*param_1,(int)*(undefined8 *)(param_1 + 2)));
  uVar8 = PackedFloatingMUL(CONCAT44((int)uVar4,(int)uVar3),*(undefined8 *)(param_1 + 6));
  uVar4 = PackedFloatingMUL(uVar4,*(undefined8 *)(param_1 + 5));
  uVar1 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)((ulonglong)uVar3 >> 0x20)
                                    ),
                            CONCAT44((int)*(undefined8 *)(param_1 + 4),
                                     (int)*(undefined8 *)(param_1 + 4)));
  uVar1 = PackedFloatingADD(uVar1,uVar8);
  uVar1 = PackedFloatingSUB(uVar1,uVar4);
  uVar1 = PackedFloatingMUL(uVar1,CONCAT44(param_1[1],
                                           (int)((ulonglong)*(undefined8 *)(param_1 + 2) >> 0x20)));
  uVar1 = PackedFloatingSUB(uVar6,uVar1);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  FastExitMediaState();
  return (float10)(float)uVar1;
}


// 005f0498 FUN_005f0498

void FUN_005f0498(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar2 = DAT_006a0850;
  uVar1 = DAT_006a0848;
  FastExitMediaState();
  uVar3 = (undefined4)DAT_006a0850;
  *param_1 = DAT_006a0850;
  param_1[1] = 0;
  param_1[2] = uVar1;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = uVar2;
  param_1[6] = param_2;
  param_1[7] = CONCAT44(uVar3,param_3);
  FastExitMediaState();
  return;
}


// 005f04e8 FUN_005f04e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f04e8(undefined8 *param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  FastExitMediaState();
  FUN_005f55cb(&uStack_18,param_3);
  uVar5 = *param_2;
  uVar1 = PackedFloatingMUL(uVar5,uStack_18);
  uVar6 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar6,uStack_10);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uStack_18 = uStack_18 ^ _DAT_006a0858;
  uStack_10 = uStack_10 ^ _DAT_006a0858;
  uVar2 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar4 = (undefined4)uStack_18;
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar1 = PackedFloatingADD(uVar1,uVar2 & 0xffffffff);
  *param_1 = uVar1;
  param_1[1] = uVar3;
  uVar4 = (undefined4)(uStack_18 >> 0x20);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar1 = PackedFloatingADD(uVar1,uVar2 << 0x20);
  param_1[2] = uVar1;
  param_1[3] = uVar3;
  uVar4 = (undefined4)uStack_10;
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar3 = PackedFloatingADD(uVar3,uVar2 & 0xffffffff);
  param_1[4] = uVar1;
  param_1[5] = uVar3;
  uVar4 = (undefined4)(uStack_10 >> 0x20);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar6 = PackedFloatingADD(uVar6,uVar2 << 0x20);
  param_1[6] = uVar5;
  param_1[7] = uVar6;
  FastExitMediaState();
  return;
}


// 005f05d3 FUN_005f05d3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f05d3(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar6;
  undefined8 uVar5;
  undefined8 uVar7;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  FastExitMediaState();
  FUN_005f55cb(&uStack_18,param_2);
  uVar1 = PackedFloatingMUL(uStack_18,_DAT_006a0860);
  uVar2 = PackedFloatingMUL(uStack_10,_DAT_006a0868);
  uVar6 = (uint)(uStack_18 >> 0x20);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uStack_18,(int)uStack_18),uVar1);
  uVar4 = PackedFloatingMUL(uStack_18 & 0xffffffff,uVar2);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar1);
  uVar7 = PackedFloatingMUL((ulonglong)uVar6,uVar2);
  uVar3 = PackedFloatingADD(uVar3,DAT_006a0850);
  uVar5 = PackedFloatingADD(uVar5,DAT_006a0848);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  param_1[3] = uVar7;
  uVar6 = (uint)(uStack_10 >> 0x20);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uStack_10,(int)uStack_10),uVar1);
  uVar4 = PackedFloatingMUL(uStack_10 & 0xffffffff,uVar2);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar1);
  uVar2 = PackedFloatingMUL((ulonglong)uVar6,uVar2);
  uVar1 = PackedFloatingADD(uVar4,DAT_006a0850);
  uVar2 = PackedFloatingADD(uVar2,DAT_006a0848);
  param_1[4] = uVar3;
  param_1[5] = uVar1;
  param_1[6] = uVar5;
  param_1[7] = uVar2;
  FastExitMediaState();
  return;
}


// 005f06af FUN_005f06af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f06af(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  FastExitMediaState();
  uVar3 = FUN_0061bee0();
  uVar2 = DAT_006a0848;
  *param_1 = DAT_006a0850;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(int *)((int)param_1 + 0x14) = (int)uVar3;
  param_1[3] = uVar3 >> 0x20;
  uVar1 = (uint)_DAT_006a0800;
  param_1[6] = 0;
  param_1[7] = uVar2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(uint *)((int)param_1 + 0x24) = (uint)(uVar3 >> 0x20) ^ uVar1;
  *(int *)(param_1 + 5) = (int)uVar3;
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  FastExitMediaState();
  return;
}


// 005f0712 FUN_005f0712

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f0712(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  FastExitMediaState();
  uVar1 = FUN_0061bee0();
  uVar3 = DAT_006a0848;
  uVar2 = uVar1 & _DAT_006a07d8;
  param_1[2] = DAT_006a0848;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = uVar3;
  param_1[4] = uVar1 >> 0x20;
  uVar3 = uVar1 >> 0x20 ^ _DAT_006a0800;
  *param_1 = uVar2;
  param_1[5] = uVar2;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// 005f07c9 FUN_005f07c9

void FUN_005f07c9(ulonglong *param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = DAT_006a0848;
  FastExitMediaState();
  *param_1 = (ulonglong)param_2;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[2] = (ulonglong)param_3 << 0x20;
  param_1[5] = (ulonglong)param_4;
  param_1[7] = uVar1;
  FastExitMediaState();
  return;
}


// 005f08b8 FUN_005f08b8

void FUN_005f08b8(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar8;
  ulonglong uVar7;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar10 = *param_2;
  uVar3 = param_2[1];
  uVar1 = PackedFloatingADD(uVar10,uVar10);
  uVar2 = PackedFloatingADD(uVar3,uVar3);
  uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar11 = CONCAT44(uVar8,uVar8);
  uVar5 = PackedFloatingMUL(uVar10,uVar1);
  uVar10 = CONCAT44((int)uVar1,(int)uVar2);
  uVar9 = PackedFloatingMUL(uVar1,uVar11);
  uVar2 = PackedFloatingMUL(CONCAT44((int)uVar3,(int)uVar3),uVar10);
  uVar3 = PackedFloatingMUL(uVar10,CONCAT44(uVar4,uVar4));
  uVar10 = PackedFloatingMUL(uVar10,uVar11);
  uVar1 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[6] = 0;
  uVar11 = PackedFloatingADD(CONCAT44((int)uVar2,(int)uVar2),uVar5);
  uVar2 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar10 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),(int)uVar10);
  uVar6 = PackedFloatingSUBR(uVar2,CONCAT44(DAT_006a078c,DAT_006a0788));
  uVar5 = PackedFloatingSUBR(uVar11,CONCAT44(DAT_006a078c,DAT_006a0788));
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  param_1[5] = uVar6 & 0xffffffff;
  uVar7 = PackedFloatingSUB(uVar1,uVar10);
  uVar6 = PackedFloatingADD(uVar3,uVar9);
  uVar10 = PackedFloatingSUB(uVar3,uVar9);
  param_1[3] = uVar6 & 0xffffffff;
  uVar6 = (ulonglong)DAT_006a0788;
  param_1[1] = uVar7 >> 0x20;
  param_1[2] = CONCAT44((int)uVar5,(int)uVar7);
  *param_1 = CONCAT44((int)uVar2,(int)((ulonglong)uVar5 >> 0x20));
  param_1[4] = CONCAT44((int)uVar10,(int)((ulonglong)uVar2 >> 0x20));
  param_1[7] = uVar6 << 0x20;
  FastExitMediaState();
  return;
}


// 005f098a FUN_005f098a

void FUN_005f098a(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 in_MM3;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  
  uVar3 = *param_2;
  uVar10 = param_2[1];
  uVar7 = PackedSwapDWords(in_MM3,uVar3);
  uVar1 = PackedFloatingADD(uVar3,uVar3);
  uVar4 = PackedFloatingADD(uVar10,uVar10);
  uVar2 = PackedFloatingMUL(uVar1,uVar3);
  uVar5 = PackedFloatingMUL(uVar3,uVar4);
  uVar8 = PackedFloatingMUL(uVar7,uVar4);
  uVar7 = PackedFloatingMUL(uVar4,uVar10);
  uVar1 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar10 >> 0x20),
                                     (int)((ulonglong)uVar3 >> 0x20)),
                            CONCAT44((int)uVar4,(int)uVar1));
  uVar3 = PackedFloatingSUBR(uVar2,CONCAT44(DAT_006a078c,DAT_006a0788));
  uVar9 = PackedFloatingPosNegAccumulate(uVar8,uVar8);
  uVar10 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingPosNegAccumulate(uVar1,uVar1);
  uVar6 = PackedFloatingPosNegAccumulate(uVar5,uVar5);
  uVar3 = PackedFloatingSUB(uVar3,CONCAT44((int)uVar7,(int)uVar7));
  uVar1 = PackedSwapDWords(uVar7,uVar6);
  uVar11 = PackedFloatingSUBR(uVar10,CONCAT44(DAT_006a078c,DAT_006a0788));
  param_1[6] = 0;
  param_1[4] = CONCAT44((int)uVar9,(int)uVar1);
  param_1[1] = uVar6 & 0xffffffff;
  param_1[5] = uVar11 >> 0x20;
  uVar6 = (ulonglong)DAT_006a0788;
  *param_1 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[2] = CONCAT44((int)uVar3,(int)uVar2);
  param_1[3] = uVar9 >> 0x20;
  param_1[7] = uVar6 << 0x20;
  FastExitMediaState();
  return;
}


// 005f1d7c FUN_005f1d7c

void FUN_005f1d7c(ulonglong *param_1,uint param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar8;
  ulonglong uVar7;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 uVar13;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  
  uVar11 = DAT_006a0768;
  *param_1 = (ulonglong)param_2;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(uint *)((int)param_1 + 0x14) = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = (ulonglong)param_2;
  param_1[6] = 0;
  param_1[7] = uVar11;
  if (param_4 != (undefined8 *)0x0) {
    uVar16 = *param_4;
    uVar6 = param_4[1];
    uVar2 = PackedFloatingADD(uVar16,uVar16);
    uVar5 = PackedFloatingADD(uVar6,uVar6);
    uVar8 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar13 = (undefined4)((ulonglong)uVar6 >> 0x20);
    uVar17 = CONCAT44(uVar13,uVar13);
    uVar9 = PackedFloatingMUL(uVar16,uVar2);
    uVar16 = CONCAT44((int)uVar2,(int)uVar5);
    uVar14 = PackedFloatingMUL(uVar2,uVar17);
    uVar5 = PackedFloatingMUL(CONCAT44((int)uVar6,(int)uVar6),uVar16);
    uVar6 = PackedFloatingMUL(uVar16,CONCAT44(uVar8,uVar8));
    uVar16 = PackedFloatingMUL(uVar16,uVar17);
    uVar2 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)((ulonglong)uVar6 >> 0x20));
    uVar17 = PackedFloatingADD(CONCAT44((int)uVar5,(int)uVar5),uVar9);
    uVar5 = PackedFloatingAccumulate(uVar9,uVar9);
    uVar16 = CONCAT44((int)((ulonglong)uVar14 >> 0x20),(int)uVar16);
    uVar10 = PackedFloatingSUBR(uVar5,CONCAT44(DAT_006a078c,DAT_006a0788));
    uVar9 = PackedFloatingSUBR(uVar17,CONCAT44(DAT_006a078c,DAT_006a0788));
    uVar10 = uVar10 & 0xffffffff;
    uVar5 = PackedFloatingADD(uVar2,uVar16);
    uVar11 = PackedFloatingSUB(uVar2,uVar16);
    uVar7 = PackedFloatingADD(uVar6,uVar14);
    uVar6 = PackedFloatingSUB(uVar6,uVar14);
    uVar7 = uVar7 & 0xffffffff;
    uVar2 = CONCAT44((int)uVar9,(int)uVar11);
    uVar11 = uVar11 >> 0x20;
    lVar3 = (ulonglong)DAT_006a0788 << 0x20;
    uVar16 = CONCAT44((int)uVar5,(int)((ulonglong)uVar9 >> 0x20));
    uVar6 = CONCAT44((int)uVar6,(int)((ulonglong)uVar5 >> 0x20));
    if (param_3 == (undefined8 *)0x0) {
      uVar8 = (undefined4)(*param_1 >> 0x20);
      uVar13 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      *param_1 = uVar18;
      param_1[1] = uVar4;
      uVar8 = (undefined4)(param_1[2] >> 0x20);
      uVar13 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      param_1[2] = uVar18;
      param_1[3] = uVar4;
      uVar8 = (undefined4)(param_1[4] >> 0x20);
      uVar13 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      param_1[4] = uVar18;
      param_1[5] = uVar4;
      uVar8 = (undefined4)(param_1[6] >> 0x20);
      uVar13 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar5 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar17 = PackedFloatingMUL(uVar16,uVar5);
      uVar16 = CONCAT44(uVar8,uVar8);
      uVar5 = PackedFloatingMUL(uVar5,uVar11);
      uVar14 = PackedFloatingMUL(uVar2,uVar16);
      uVar2 = CONCAT44(uVar13,uVar13);
      uVar16 = PackedFloatingMUL(uVar16,uVar7);
      uVar17 = PackedFloatingADD(uVar14,uVar17);
      uVar14 = PackedFloatingMUL(uVar6,uVar9);
      uVar6 = PackedFloatingADD(uVar16,uVar5);
      uVar16 = PackedFloatingMUL(uVar9,uVar10);
      uVar5 = PackedFloatingADD(uVar14,uVar17);
      uVar9 = PackedFloatingMUL(0,uVar2);
      uVar16 = PackedFloatingADD(uVar6,uVar16);
      uVar6 = PackedFloatingMUL(uVar2,lVar3);
      uVar7 = PackedFloatingADD(uVar9,uVar5);
      uVar11 = PackedFloatingADD(uVar6,uVar16);
      param_1[6] = uVar7;
      param_1[7] = uVar11;
    }
    else {
      uVar4 = PackedFloatingSUB(param_1[6],*param_3);
      uVar5 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_3 + 1));
      param_1[6] = uVar4;
      *(int *)(param_1 + 7) = (int)uVar5;
      uVar8 = (undefined4)(*param_1 >> 0x20);
      uVar13 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      *param_1 = uVar18;
      param_1[1] = uVar4;
      uVar8 = (undefined4)(param_1[2] >> 0x20);
      uVar13 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      param_1[2] = uVar18;
      param_1[3] = uVar4;
      uVar8 = (undefined4)(param_1[4] >> 0x20);
      uVar13 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar14 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar16,uVar9);
      uVar5 = CONCAT44(uVar8,uVar8);
      uVar17 = PackedFloatingMUL(uVar9,uVar11);
      uVar15 = PackedFloatingMUL(uVar2,uVar5);
      uVar9 = CONCAT44(uVar13,uVar13);
      uVar5 = PackedFloatingMUL(uVar5,uVar7);
      uVar12 = PackedFloatingADD(uVar15,uVar12);
      uVar15 = PackedFloatingMUL(uVar6,uVar14);
      uVar17 = PackedFloatingADD(uVar5,uVar17);
      uVar5 = PackedFloatingMUL(uVar14,uVar10);
      uVar14 = PackedFloatingADD(uVar15,uVar12);
      uVar12 = PackedFloatingMUL(0,uVar9);
      uVar5 = PackedFloatingADD(uVar17,uVar5);
      uVar9 = PackedFloatingMUL(uVar9,lVar3);
      uVar18 = PackedFloatingADD(uVar12,uVar14);
      uVar4 = PackedFloatingADD(uVar9,uVar5);
      param_1[4] = uVar18;
      param_1[5] = uVar4;
      uVar8 = (undefined4)(param_1[6] >> 0x20);
      uVar13 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar5 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar9 = CONCAT44(uVar1,uVar1);
      uVar17 = PackedFloatingMUL(uVar16,uVar5);
      uVar16 = CONCAT44(uVar8,uVar8);
      uVar5 = PackedFloatingMUL(uVar5,uVar11);
      uVar14 = PackedFloatingMUL(uVar2,uVar16);
      uVar2 = CONCAT44(uVar13,uVar13);
      uVar16 = PackedFloatingMUL(uVar16,uVar7);
      uVar17 = PackedFloatingADD(uVar14,uVar17);
      uVar14 = PackedFloatingMUL(uVar6,uVar9);
      uVar6 = PackedFloatingADD(uVar16,uVar5);
      uVar16 = PackedFloatingMUL(uVar9,uVar10);
      uVar5 = PackedFloatingADD(uVar14,uVar17);
      uVar9 = PackedFloatingMUL(0,uVar2);
      uVar16 = PackedFloatingADD(uVar6,uVar16);
      uVar6 = PackedFloatingMUL(uVar2,lVar3);
      uVar7 = PackedFloatingADD(uVar9,uVar5);
      uVar11 = PackedFloatingADD(uVar6,uVar16);
      param_1[6] = uVar7;
      param_1[7] = uVar11;
      uVar11 = PackedFloatingADD(param_1[6],*param_3);
      uVar16 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_3 + 1));
      param_1[6] = uVar11;
      *(int *)(param_1 + 7) = (int)uVar16;
    }
  }
  if (param_5 != (undefined8 *)0x0) {
    uVar11 = PackedFloatingADD(*param_5,param_1[6]);
    uVar16 = PackedFloatingADD((ulonglong)*(uint *)(param_5 + 1),(ulonglong)(uint)param_1[7]);
    param_1[6] = uVar11;
    *(int *)(param_1 + 7) = (int)uVar16;
  }
  FastExitMediaState();
  return;
}


// 005f37ff FUN_005f37ff

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


// 005f3f2b FUN_005f3f2b

undefined4 FUN_005f3f2b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FastExitMediaState();
  FUN_005f3bf7(param_1,param_2,param_3);
  FastExitMediaState();
  return param_1;
}


// 005f3f47 FUN_005f3f47

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


// 005f407e FUN_005f407e

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


// 005f40ef FUN_005f40ef

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar5 = PackedFloatingMUL(uVar2,DAT_006a0820);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_006a0828);
  uVar4 = PackedFloatingMUL(uVar3,DAT_006a0820);
  uVar5 = PackedFloatingSUB(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(uVar2,uVar4);
  uVar5 = PackedFloatingADD(uVar5,uVar1);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar4 = PackedFloatingADD(uVar2,_DAT_006a0810);
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


// 005f41c3 FUN_005f41c3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  undefined8 uVar10;
  
  uVar9 = DAT_006a07f0;
  uVar1 = PackedFloatingMUL(CONCAT44(param_6,param_6),CONCAT44(param_6,param_6));
  uVar3 = CONCAT44(DAT_006a0788,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar3);
  uVar2 = PackedFloatingMUL(uVar1,_DAT_006a0798);
  uVar1 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),CONCAT44(param_6,param_6) ^ DAT_006a07a8
                           );
  uVar4 = PackedFloatingSUB(uVar3,uVar1);
  uVar1 = PackedFloatingSUB(uVar1,uVar2 >> 0x20);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar8 = CONCAT44(uVar5,uVar5);
  uVar3 = CONCAT44((int)uVar1,(int)uVar1);
  uVar10 = CONCAT44((int)uVar4,(int)uVar4);
  uVar4 = PackedFloatingMUL(uVar8,*param_2);
  uVar5 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar7 = CONCAT44(uVar5,uVar5);
  uVar1 = PackedFloatingMUL(uVar3,*param_3);
  uVar6 = PackedFloatingMUL(uVar10,*param_4);
  uVar8 = PackedFloatingMUL(uVar8,(ulonglong)*(uint *)(param_2 + 1));
  uVar3 = PackedFloatingMUL(uVar3,(ulonglong)*(uint *)(param_3 + 1));
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar10 = PackedFloatingMUL(uVar10,(ulonglong)*(uint *)(param_4 + 1));
  uVar4 = PackedFloatingADD(uVar8,uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar6);
  uVar3 = PackedFloatingMUL(uVar7,*param_5);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,(ulonglong)*(uint *)(param_5 + 1));
  uVar3 = PackedFloatingADD(uVar4,uVar10);
  uVar1 = PackedFloatingMUL(uVar1,DAT_006a07f0);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  *param_1 = uVar1;
  uVar9 = PackedFloatingMUL(uVar3,uVar9);
  *(int *)(param_1 + 1) = (int)uVar9;
  FastExitMediaState();
  return;
}


// 005f4ded FUN_005f4ded

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar5 = PackedFloatingMUL(uVar2,DAT_006a0820);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_006a0828);
  uVar4 = PackedFloatingMUL(uVar3,DAT_006a0820);
  uVar5 = PackedFloatingSUB(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(uVar2,uVar4);
  uVar5 = PackedFloatingADD(uVar5,uVar1);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingADD(uVar2,_DAT_006a0810);
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


// 005f4e85 FUN_005f4e85

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


// 005f4ece FUN_005f4ece

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar3 = PackedFloatingCompareGT(uVar2,_DAT_006a07f8);
  uVar5 = PackedFloatingMUL(uVar4,uVar4);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar2 = PackedFloatingMUL(uVar1 & uVar3,uVar2);
  *param_1 = uVar2;
  FastExitMediaState();
  return;
}


// 005f4f11 FUN_005f4f11

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar3 = CONCAT44(DAT_006a0788,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar4);
  uVar2 = PackedFloatingMUL(uVar1,_DAT_006a0798);
  uVar3 = CONCAT44((int)uVar1,(int)uVar2);
  uVar4 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),CONCAT44(param_6,param_6) ^ DAT_006a07a8
                           );
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
  uVar1 = PackedFloatingMUL(uVar1,DAT_006a07f0);
  *param_1 = uVar1;
  FastExitMediaState();
  return;
}


// 005f4fbc FUN_005f4fbc

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


// 005f503e FUN_005f503e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar6 = PackedFloatingCompareGT(uVar3,_DAT_006a07f8);
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


// 005f509d FUN_005f509d

void FUN_005f509d(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined4 uVar8;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 uVar10;
  undefined8 uVar9;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  ulonglong uVar16;
  
  uVar5 = DAT_006a0808;
  FastExitMediaState();
  uVar10 = (undefined4)((ulonglong)param_4[1] >> 0x20);
  uVar1 = (undefined4)((ulonglong)param_3[1] >> 0x20);
  uVar8 = (undefined4)param_3[1];
  uVar2 = (undefined4)((ulonglong)*param_3 >> 0x20);
  uVar15 = (undefined4)param_4[1];
  uVar4 = (undefined4)((ulonglong)*param_4 >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),CONCAT44(uVar2,uVar8));
  uVar12 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),CONCAT44(uVar4,uVar15));
  uVar12 = PackedFloatingSUB(uVar9,uVar12);
  uVar3 = (undefined4)*param_4;
  uVar9 = PackedFloatingMUL(CONCAT44(uVar1,uVar2),CONCAT44(uVar3,uVar15));
  uVar1 = (undefined4)*param_3;
  uVar13 = PackedFloatingMUL(CONCAT44(uVar10,uVar4),CONCAT44(uVar1,uVar8));
  uVar11 = PackedFloatingSUB(uVar9,uVar13);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar8));
  uVar9 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),CONCAT44(uVar4,uVar15));
  uVar14 = PackedFloatingSUB(uVar13,uVar9);
  uVar9 = param_2[1];
  uVar13 = PackedFloatingMUL(CONCAT44((int)uVar12,(int)uVar12) ^ DAT_006a0808,
                             CONCAT44((int)*param_2,(int)((ulonglong)*param_2 >> 0x20)));
  uVar8 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar1 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar6 = PackedFloatingMUL(CONCAT44((int)uVar11,uVar8),uVar9);
  uVar16 = PackedFloatingMUL(CONCAT44((int)uVar14,uVar1),uVar9);
  uVar7 = PackedFloatingAccumulate(uVar6 ^ DAT_006a0808,uVar16 ^ DAT_006a0808);
  uVar12 = *param_2;
  uVar13 = PackedFloatingSUB(uVar13,uVar7);
  *param_1 = uVar13;
  uVar16 = uVar5 >> 0x20;
  uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar1,uVar8) ^ uVar5,uVar12);
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar14,(int)uVar11) ^ uVar16,uVar12);
  uVar9 = PackedFloatingMUL(CONCAT44((int)uVar9,(int)((ulonglong)uVar9 >> 0x20)),
                            CONCAT44(uVar15,uVar15) ^ uVar16);
  uVar12 = PackedFloatingAccumulate(uVar6 ^ uVar16 << 0x20,uVar5 ^ uVar16 << 0x20);
  uVar9 = PackedFloatingADD(uVar9,uVar12);
  param_1[1] = uVar9;
  FastExitMediaState();
  return;
}


// 005f51cf FUN_005f51cf

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


// 005f5308 FUN_005f5308

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  undefined8 uVar10;
  
  uVar9 = DAT_006a07f0;
  uVar1 = PackedFloatingMUL(CONCAT44(param_6,param_6),CONCAT44(param_6,param_6));
  uVar3 = CONCAT44(DAT_006a0788,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar3);
  uVar2 = PackedFloatingMUL(uVar1,_DAT_006a0798);
  uVar1 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),CONCAT44(param_6,param_6) ^ DAT_006a07a8
                           );
  uVar4 = PackedFloatingSUB(uVar3,uVar1);
  uVar1 = PackedFloatingSUB(uVar1,uVar2 >> 0x20);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar8 = CONCAT44(uVar5,uVar5);
  uVar3 = CONCAT44((int)uVar1,(int)uVar1);
  uVar10 = CONCAT44((int)uVar4,(int)uVar4);
  uVar4 = PackedFloatingMUL(uVar8,*param_2);
  uVar5 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar7 = CONCAT44(uVar5,uVar5);
  uVar1 = PackedFloatingMUL(uVar3,*param_3);
  uVar6 = PackedFloatingMUL(uVar10,*param_4);
  uVar8 = PackedFloatingMUL(uVar8,param_2[1]);
  uVar3 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar10 = PackedFloatingMUL(uVar10,param_4[1]);
  uVar4 = PackedFloatingADD(uVar8,uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar6);
  uVar3 = PackedFloatingMUL(uVar7,*param_5);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,param_5[1]);
  uVar3 = PackedFloatingADD(uVar4,uVar10);
  uVar1 = PackedFloatingMUL(uVar1,DAT_006a07f0);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  *param_1 = uVar1;
  uVar9 = PackedFloatingMUL(uVar3,uVar9);
  param_1[1] = uVar9;
  FastExitMediaState();
  return;
}


// 005f53e6 FUN_005f53e6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f53e6(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  FastExitMediaState();
  uVar1 = *(uint *)(param_3 + 1);
  uVar3 = PackedFloatingMUL(*param_2,*param_3);
  uVar4 = PackedFloatingMUL((ulonglong)*(uint *)(param_2 + 1),(ulonglong)uVar1);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  *param_1 = *param_3;
  uVar2 = (uint)_DAT_006a0800;
  *(uint *)(param_1 + 1) = uVar1;
  *(uint *)((int)param_1 + 0xc) = (uint)uVar3 ^ uVar2;
  FastExitMediaState();
  return;
}


// 005f5429 FUN_005f5429

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uVar4 = uVar4 ^ DAT_006a0808;
  uVar2 = PackedFloatingMUL(CONCAT44(uVar9,(int)((ulonglong)uVar7 >> 0x20)),uVar2);
  uVar6 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingMUL(uVar6 << 0x20,uVar6 << 0x20);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingReciprocalSQRAprox(CONCAT44(uVar9,(int)uVar7),uVar3);
  uVar8 = PackedFloatingCompareGT(uVar3,_DAT_006a07f8);
  uVar5 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar2);
  uVar2 = PackedFloatingMUL(uVar4 & uVar8,uVar3);
  uVar5 = PackedFloatingMUL(uVar6 & uVar8,uVar3);
  uVar3 = PackedFloatingMUL(uVar2,*param_2);
  uVar7 = PackedFloatingMUL(uVar5,(ulonglong)uVar1);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar3 = PackedFloatingADD(uVar3,uVar7);
  uVar4 = CONCAT44((int)uVar3,(int)uVar5) ^ DAT_006a0808;
  *param_1 = uVar2;
  param_1[1] = uVar4;
  FastExitMediaState();
  return;
}


// 005f550d FUN_005f550d

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
  uVar7 = CONCAT44(DAT_006a0778,*(uint *)(param_3 + 1));
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


// 005f562f FUN_005f562f

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


// 005f655e FUN_005f655e

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


// 005f7dd2 FUN_005f7dd2

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


// 005f7de8 FUN_005f7de8

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


// 005f7fec FUN_005f7fec

undefined4 __fastcall FUN_005f7fec(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfffffffc;
  *(undefined4 *)(param_1 + 0x6c) = 0x40;
  *(undefined4 *)(param_1 + 0x70) = 0x40;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  return 0;
}


// 005f800a FUN_005f800a

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


// 006042f5 FUN_006042f5

undefined4 __fastcall FUN_006042f5(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x74) = 0;
  uVar2 = *(uint *)(param_1 + 0x30) & 0xffff;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(undefined4 *)(param_1 + 0x70) = 0x18;
  *(undefined4 *)(param_1 + 0x78) = 8;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(uint *)(param_1 + 0x90) = uVar1 & 0xffffffde | 0x738968a;
  if (uVar2 == 0x104) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 6;
    *(undefined4 *)(param_1 + 0x80) = 8;
    *(undefined4 *)(param_1 + 0x88) = 6;
    *(uint *)(param_1 + 0x90) = uVar1 & 0xffb8ffda | 0x738fe9a;
  }
  else {
    *(undefined4 *)(param_1 + 0x8c) = 2;
    *(undefined4 *)(param_1 + 0x7c) = 4;
    *(undefined4 *)(param_1 + 0x80) = 6;
    *(undefined4 *)(param_1 + 0x88) = 4;
    *(uint *)(param_1 + 0x90) =
         (uint)(uVar2 == 0x101) << 0x10 | uVar1 & 0xfffe97de | 0x738968a | 0x8460014;
  }
  return 0;
}


// 0060ad62 FUN_0060ad62

uint __thiscall FUN_0060ad62(int param_1,uint param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x98) + 0x24) == 1) {
    param_2 = param_2 | 0x40000000;
  }
  return param_2;
}


// 0060ad7a FUN_0060ad7a

undefined4 __thiscall FUN_0060ad7a(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x51);
  uVar1 = *(uint *)(param_2 + 0x50) & 0xff;
  if (uVar1 == 1) {
    if (*(uint *)(param_1 + 0x6c) <= uVar2) {
      return 0x80004005;
    }
  }
  else {
    if (uVar1 != 3) {
      if (uVar1 == 5) {
        *param_3 = 0xc;
        return 0;
      }
      return 0x80004005;
    }
    if (*(uint *)(param_1 + 0x7c) <= uVar2) {
      return 0x80004005;
    }
    uVar2 = uVar2 + 2;
  }
  *param_3 = uVar2;
  return 0;
}


// 0060adc6 FUN_0060adc6

undefined4 __thiscall FUN_0060adc6(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_2 + 0x50);
  bVar1 = *(byte *)(param_2 + 0x51);
  *param_3 = (uint)bVar1;
  uVar2 = uVar2 & 0xff;
  uVar3 = 1;
  if (uVar2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x6c);
  }
  else {
    uVar3 = 3;
    if (uVar2 != 3) {
      return 0x80004005;
    }
    uVar2 = *(uint *)(param_1 + 0x7c);
  }
  if (uVar2 <= bVar1) {
    return 0x80004005;
  }
  *param_4 = uVar3;
  return 0;
}


// 0060d4e8 FUN_0060d4e8

undefined4 __fastcall FUN_0060d4e8(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xac) * 4);
  *puVar1 = *puVar1 | ((*(int *)(param_1 + 0xa4) - *(int *)(param_1 + 0xac)) + -1) * 0x1000000;
  return 0;
}


// 0060d526 FUN_0060d526

int __thiscall FUN_0060d526(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0061a26f(0x200001f);
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_2 + 0x20);
    if (iVar1 == 0x100000) {
      uVar2 = 0x90000000;
    }
    else if (iVar1 == 0x200000) {
      uVar2 = 0xa0000000;
    }
    else {
      if (iVar1 != 0x400000) {
        FUN_005fbec8(param_1,0,0x12ce,"internal error: unexpected Alias on texture declaration");
        return -0x7fffbffb;
      }
      uVar2 = 0x98000000;
    }
    iVar1 = FUN_00618c39(uVar2);
    if (((-1 < iVar1) &&
        (iVar1 = (**(code **)(*param_1 + 0x54))(*(uint *)(param_2 + 8) & 0x7ff | 0xa0000800,0xf0000)
        , -1 < iVar1)) && (iVar1 = FUN_0061663f(), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// 0060d5c4 FUN_0060d5c4

undefined4 __fastcall FUN_0060d5c4(int param_1)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar3 = false;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar5;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar5 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[2] * 4);
      uVar4 = *puVar1 & 0xff000000;
      if ((((uVar4 == 0x44000000) || (uVar4 == 0x46000000)) || (uVar4 == 0x47000000)) ||
         (((uVar4 == 0x40000000 || (uVar4 == 0x42000000)) || (uVar4 == 0x43000000)))) {
        if ((*(byte *)(iVar2 + 0x22) & 0x60) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x100000;
      }
      else if (((uVar4 == 0x48000000) || (uVar4 == 0x4a000000)) || (uVar4 == 0x4b000000)) {
        if ((*(byte *)(iVar2 + 0x22) & 0x50) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x200000;
      }
      else if (((uVar4 == 0x4c000000) || (uVar4 == 0x4e000000)) || (uVar4 == 0x4f000000)) {
        if ((*(byte *)(iVar2 + 0x22) & 0x30) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x400000;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0xc));
    if (bVar3) {
      FUN_005fbec8(param_1,0,0x11bb,"sampler mismatch: sampler used inconsistently");
      return 0x80004005;
    }
  }
  return 0;
}


// 0060d851 FUN_0060d851

undefined4 __thiscall FUN_0060d851(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x50);
  uVar2 = (uint)*(byte *)(param_2 + 0x51);
  *param_3 = uVar2;
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    if (*(uint *)(param_1 + 0x6c) <= uVar2) {
      return 0x80004005;
    }
    *param_4 = 1;
  }
  else {
    if (uVar1 != 3) {
      return 0x80004005;
    }
    if (7 < uVar2) {
      return 0x80004005;
    }
    *param_4 = 3;
  }
  return 0;
}


// 0060f995 FUN_0060f995

int __fastcall FUN_0060f995(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  *(undefined4 *)(param_1 + 0x134) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  uVar8 = 0;
  iVar4 = param_1;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar8;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
        uVar3 = *puVar1 & 0xff000000;
        if (uVar3 < 0x24000001) {
          if (uVar3 == 0x24000000) {
            iVar4 = FUN_00618709();
          }
          else if (uVar3 == 0x11000000) {
            iVar4 = FUN_006178e1();
          }
          else if (uVar3 == 0x16000000) {
            iVar4 = FUN_00618431();
          }
          else {
            if ((uVar3 != 0x20000000) && (uVar3 != 0x21000000)) goto LAB_0060fa3c;
            iVar4 = FUN_006169a4();
          }
        }
        else if (uVar3 == 0x25000000) {
          iVar4 = FUN_00618a35();
        }
        else if (uVar3 == 0x30000000) {
          iVar4 = FUN_0060ed62();
        }
        else {
          if (uVar3 != 0x50000000) {
LAB_0060fa3c:
            iVar4 = 1;
            goto LAB_0060fa72;
          }
          iVar4 = FUN_006169a4();
          if (iVar4 == 1) {
            iVar4 = FUN_00614ca2();
          }
        }
        if (iVar4 < 0) {
          return iVar4;
        }
      }
LAB_0060fa72:
      *(uint *)(param_1 + 0x94) = uVar8;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if (((uVar3 == 0x23000000) || (uVar3 == 0x22000000)) && (*(int *)(param_1 + 0x134) == -1)) {
        uVar5 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
        uVar6 = FUN_005f74cf(uVar5,0,0,0);
        *(undefined4 *)(param_1 + 0x134) = uVar6;
        uVar5 = FUN_005f74cf(uVar5,0,1,0x3ff0000000000000);
        *(undefined4 *)(param_1 + 0x138) = uVar5;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        *(uint *)(param_1 + 0x94) = uVar8;
        puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
        *(uint **)(param_1 + 0x98) = puVar1;
        uVar3 = *puVar1 & 0xff000000;
        if (uVar3 == 0x24000000) {
          iVar4 = FUN_00617905();
LAB_0060fb49:
          if (iVar4 < 0) {
            return iVar4;
          }
        }
        else {
          if (uVar3 == 0x50000000) {
            iVar4 = FUN_006142b6();
            goto LAB_0060fb49;
          }
          iVar4 = 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 0xc));
    }
    uVar8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        *(uint *)(param_1 + 0x94) = uVar8;
        puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
        *(uint **)(param_1 + 0x98) = puVar1;
        uVar3 = *puVar1;
        uVar7 = uVar3 & 0xff000000;
        if (((uVar7 == 0x12000000) || (uVar7 == 0x14000000)) || (uVar7 == 0x15000000)) {
LAB_0060fbcc:
          iVar4 = FUN_00614682();
LAB_0060fbd5:
          if (iVar4 < 0) {
            return iVar4;
          }
        }
        else {
          if (uVar7 == 0x30000000) {
            if (2 < (uVar3 & 0xffffff)) goto LAB_0060fbcc;
            goto LAB_0060fbd5;
          }
          if ((uVar7 == 0xf3000000) || (uVar7 == 0xf4000000)) goto LAB_0060fbcc;
          if (uVar7 == 0xf5000000) {
            FUN_0061858f();
            iVar4 = FUN_006151a7();
            goto LAB_0060fbd5;
          }
          iVar4 = 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 0xc));
    }
  }
  FUN_0061674c();
  uVar8 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
      if ((((piVar2[0xe] == -1) &&
           ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x80) != 0)) &&
          (*(uint *)(param_1 + 0x138) != uVar8)) && (*(uint *)(param_1 + 0x134) != uVar8)) {
        *piVar2 = *(int *)(param_1 + 0x4c);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// 0060fc2c FUN_0060fc2c

undefined4 __fastcall FUN_0060fc2c(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x6c) = 0x10;
  *(undefined4 *)(param_1 + 0x80) = 0x10;
  uVar1 = *(uint *)(param_1 + 0x30) & 0xffff;
  if (uVar1 < 0x201) {
    *(undefined4 *)(param_1 + 0x70) = 0xc;
  }
  else {
    *(undefined4 *)(param_1 + 0x70) = 0x20;
  }
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (uVar1 < 0x200) {
    *(byte *)(param_1 + 0x92) = *(byte *)(param_1 + 0x92) | 0x80;
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  else {
    *(byte *)(param_1 + 0x92) = *(byte *)(param_1 + 0x92) & 0x7f;
    *(undefined4 *)(param_1 + 0x74) = 1;
  }
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfaaeffc0 | 0x40;
  return 0;
}


// 0060feb5 FUN_0060feb5

void __fastcall FUN_0060feb5(int param_1)

{
  *(uint *)(param_1 + 0xe8) = (uint)(0x100 < (*(uint *)(param_1 + 0x30) & 0xffff));
  FUN_00619954();
  return;
}


// 0060fed3 FUN_0060fed3

undefined4 __fastcall FUN_0060fed3(int param_1)

{
  uint *puVar1;
  
  if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
    puVar1 = (uint *)(*(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xac) * 4);
    *puVar1 = *puVar1 | ((*(int *)(param_1 + 0xa4) - *(int *)(param_1 + 0xac)) + -1) * 0x1000000;
  }
  return 0;
}


// 00611aad FUN_00611aad

int __fastcall FUN_00611aad(int param_1)

{
  if (*(int *)(param_1 + 0xec) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0x14c) + *(int *)(param_1 + 0x148) + *(int *)(param_1 + 0x128);
}


// 006124a9 FUN_006124a9

int __fastcall FUN_006124a9(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      iVar2 = FUN_00611eae();
      if (iVar2 == 0) {
        FUN_0061674c();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if (uVar3 == 0x11000000) {
        iVar2 = FUN_006178e1();
LAB_00612588:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        if (uVar3 == 0x16000000) {
          iVar2 = FUN_00618431();
          goto LAB_00612588;
        }
        if (uVar3 != 0x21000000) {
          if (uVar3 == 0x24000000) {
            if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
              FUN_00618709();
            }
            iVar2 = FUN_00617905();
          }
          else if (uVar3 == 0x25000000) {
            iVar2 = FUN_00618a35();
          }
          else {
            if (uVar3 != 0x30000000) goto LAB_00612590;
            iVar2 = FUN_0060ff02();
          }
          goto LAB_00612588;
        }
        if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
          iVar2 = FUN_00614bc0();
          goto LAB_00612588;
        }
      }
LAB_00612590:
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  FUN_00614972();
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if ((((uVar3 == 0x12000000) || (uVar3 == 0x14000000)) || (uVar3 == 0x15000000)) ||
         (((uVar3 == 0x30000000 || (uVar3 == 0xf3000000)) || (uVar3 == 0xf4000000)))) {
        iVar2 = FUN_00614682();
LAB_00612617:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else if (uVar3 == 0xf5000000) {
        if ((*(uint *)(param_1 + 0x30) & 0xffff) < 0x200) {
          iVar2 = 1;
        }
        else {
          iVar2 = FUN_0061858f();
        }
        goto LAB_00612617;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// 00612919 FUN_00612919

undefined4 __fastcall FUN_00612919(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0x40;
  *(undefined4 *)(param_1 + 0x70) = 0x40;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfffffffc | 0x100;
  return 0;
}


// 006135f7 FUN_006135f7

undefined4 * __fastcall FUN_006135f7(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x2c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00613560();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[4] = *(undefined4 *)(param_1 + 0x10);
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    puVar2[6] = *(undefined4 *)(param_1 + 0x18);
    puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
    puVar2[8] = *(undefined4 *)(param_1 + 0x20);
    puVar2[9] = *(undefined4 *)(param_1 + 0x24);
    if (*(int **)(param_1 + 0x28) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// 00613698 FUN_00613698

int FUN_00613698(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_1 * 4) + 8);
  uVar2 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_2 * 4) + 8);
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      return -1;
    }
    if (param_1 <= param_2) {
      return -(uint)(param_1 < param_2);
    }
  }
  return 1;
}


// 00616118 FUN_00616118

undefined4 __thiscall FUN_00616118(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  *param_4 = 1;
  uVar1 = *(uint *)(param_2 + 8);
  *param_3 = uVar1;
  if (uVar1 < *(uint *)(param_1 + 0x6c)) {
    uVar2 = 0;
  }
  else {
    FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x119a,
                 "maximum input register index exceeded");
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// 0061a37c FUN_0061a37c

int FUN_0061a37c(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_0061a36a(param_1 | param_2);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// 0061c450 FUN_0061c450

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0061d4c1) */
/* WARNING: Removing unreachable block (ram,0x0061d502) */
/* WARNING: Removing unreachable block (ram,0x0061d571) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0061c450(char *param_1,char *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  byte bVar11;
  char *in_EAX;
  char *pcVar6;
  char *pcVar7;
  undefined3 uVar12;
  int *piVar8;
  char *pcVar9;
  undefined1 *puVar10;
  char cVar13;
  char cVar14;
  uint extraout_ECX;
  byte bVar15;
  char cVar17;
  int iVar16;
  char cVar18;
  char *unaff_EBX;
  char *unaff_EBP;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar19;
  ushort in_CS;
  bool bVar20;
  ulonglong uVar21;
  
  cVar14 = (char)((uint)param_1 >> 8);
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar4 = (char)in_EAX;
  *in_EAX = *in_EAX + cVar4;
  *in_EAX = *in_EAX + cVar4;
  cVar13 = (char)param_1;
  *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar4;
  *in_EAX = *in_EAX + cVar4;
  param_1[(int)in_EAX] = param_1[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar4;
  *in_EAX = *in_EAX + cVar4;
  param_2[(int)in_EAX] = param_2[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar4;
  *in_EAX = *in_EAX + cVar4;
  unaff_EBX[(int)in_EAX] = unaff_EBX[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + cVar4;
  *in_EAX = *in_EAX + cVar4;
  pcVar6 = (char *)((uint)in_EAX | 4);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + (char)pcVar6;
  pcVar6 = pcVar6 + 0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)pcVar6] = unaff_ESI[(int)pcVar6] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)pcVar6] = unaff_EDI[(int)pcVar6] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)param_1] = pcVar6[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)param_1 * 2) = *(char *)((int)param_1 * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)param_1] = param_2[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)param_1] = unaff_EBX[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar7 = (char *)((uint)pcVar6 | 0xc);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar13;
  pcVar7 = (char *)((uint)pcVar6 | 0x800c);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_ESI[(int)param_1] = unaff_ESI[(int)param_1] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[(int)param_1] = unaff_EDI[(int)param_1] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar15 = (byte)param_2;
  *pcVar7 = *pcVar7 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7[(int)param_2] = pcVar7[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  param_1[(int)param_2] = param_1[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  *(char *)((int)param_2 * 2) = *(char *)((int)param_2 * 2) + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EBX[(int)param_2] = unaff_EBX[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x801c);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar20 = CARRY1(DAT_0c000000,bVar15);
  DAT_0c000000 = DAT_0c000000 + bVar15;
  pcVar6 = pcVar6 + bVar20 + 0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)param_2] = unaff_ESI[(int)param_2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)param_2] = unaff_EDI[(int)param_2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar11 = (byte)unaff_EBX;
  *pcVar6 = *pcVar6 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_EBX] = pcVar6[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_EBX] = param_1[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_EBX] = param_2[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)unaff_EBX * 2) = *(char *)((int)unaff_EBX * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x1c);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar20 = CARRY1(DAT_0c000000,bVar11);
  DAT_0c000000 = DAT_0c000000 + bVar11;
  pcVar6 = pcVar6 + (-0x8000 - (uint)bVar20);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)unaff_EBX] = unaff_ESI[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_EBX] = unaff_EDI[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar5 = (char)((uint)pcVar6 >> 8);
  *pcVar6 = *pcVar6 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *param_1 = *param_1 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *param_2 = *param_2 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar7 = (char *)((uint)pcVar6 | 0x24);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar5;
  pcVar6 = (char *)((uint)pcVar6 & 0x8000);
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar4 = (char)((uint)pcVar6 >> 8);
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar6 = *pcVar6;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar6 = *pcVar6;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar14;
  *pcVar6 = *pcVar6;
  pcVar6[(int)unaff_EBP] = pcVar6[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar14;
  *pcVar6 = *pcVar6;
  param_1[(int)unaff_EBP] = param_1[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar14;
  *pcVar6 = *pcVar6;
  param_2[(int)unaff_EBP] = param_2[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar14;
  *pcVar6 = *pcVar6;
  unaff_EBX[(int)unaff_EBP] = unaff_EBX[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar14;
  *pcVar6 = *pcVar6;
  pcVar6 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),0x2c);
  *pcVar6 = *pcVar6 + ',';
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar14;
  pcVar6 = pcVar6 + -0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)unaff_EBP] = unaff_ESI[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_EBP] = unaff_EDI[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar17 = (char)((uint)param_2 >> 8);
  *pcVar6 = *pcVar6 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_ESI] = pcVar6[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_ESI] = param_1[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_ESI] = param_2[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)unaff_ESI] = unaff_EBX[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x34);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar17;
  pcVar6 = (char *)((uint)pcVar6 ^ 0x8000);
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)unaff_ESI * 2) = *(char *)((int)unaff_ESI * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_ESI] = unaff_EDI[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar18 = (char)((uint)unaff_EBX >> 8);
  *pcVar6 = *pcVar6 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_EDI] = pcVar6[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_EDI] = param_1[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_EDI] = param_2[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)unaff_EDI] = unaff_EBX[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  uVar12 = (undefined3)((uint)pcVar6 >> 8);
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x3c);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_ESI[(int)unaff_EDI] = unaff_ESI[(int)unaff_EDI] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  *(char *)((int)unaff_EDI * 2) = *(char *)((int)unaff_EDI * 2) + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x40);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x41);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x42);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x43);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + cVar4;
  (&stack0x00000000)[(int)pcVar7 * 2] = (&stack0x00000000)[(int)pcVar7 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x45);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x46);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x47);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x48);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x49);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4a);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4b);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + cVar13;
  (&stack0x00000000)[(int)param_1 * 2] = (&stack0x00000000)[(int)param_1 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4d);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4e);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4f);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x50);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x51);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x52);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x53);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar15;
  (&stack0x00000000)[(int)param_2 * 2] = (&stack0x00000000)[(int)param_2 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x55);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x56);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x57);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x58);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x59);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5a);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5b);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar11;
  (&stack0x00000000)[(int)unaff_EBX * 2] = (&stack0x00000000)[(int)unaff_EBX * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5d);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5e);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5f);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar5 = (char)((uint)pcVar6 >> 8);
  *pcVar7 = *pcVar7 + cVar5;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x60);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x61);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x62);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 99);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x65);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x66);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x67);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x68);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x69);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6a);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6b);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar14;
  (&stack0x00000000)[(int)unaff_EBP * 2] = (&stack0x00000000)[(int)unaff_EBP * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6d);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6e);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6f);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x70);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x71);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x72);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x73);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar17;
  (&stack0x00000000)[(int)unaff_ESI * 2] = (&stack0x00000000)[(int)unaff_ESI * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x75);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x76);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x77);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x78);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x79);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7a);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7b);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar18;
  (&stack0x00000000)[(int)unaff_EDI * 2] = (&stack0x00000000)[(int)unaff_EDI * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7d);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7e);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  piVar8 = (int *)(CONCAT31(uVar12,cVar4) | 0x7f);
  cVar5 = (char)piVar8;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)(piVar8 + 0x3000000) = (char)piVar8[0x3000000] + cVar5;
  *(char *)piVar8 = (char)*piVar8 + -0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + cVar5;
  *piVar8 = *piVar8 + 0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  pcVar7 = unaff_ESI + 4;
  out(*(undefined4 *)unaff_ESI,(short)param_2);
  *(char *)piVar8 = (char)*piVar8;
  param_2[(int)piVar8 * 4] = param_2[(int)piVar8 * 4] + cVar13;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar5;
  *piVar8 = *piVar8 + -0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6 = (char *)((int)piVar8 * 2 + -0x7bf40000);
  *pcVar6 = *pcVar6 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar5;
  *(char *)piVar8 = (char)*piVar8;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar5;
  LOCK();
  cVar4 = (char)*piVar8;
  *(char *)piVar8 = cVar5;
  pcVar9 = (char *)CONCAT31(uVar12,cVar4);
  UNLOCK();
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar4;
  LOCK();
  pcVar6 = *(char **)pcVar9;
  *(char **)pcVar9 = pcVar9;
  UNLOCK();
  *pcVar6 = *pcVar6;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6[0xc000000] = pcVar6[0xc000000] + cVar13;
  *pcVar6 = cVar4;
  *pcVar6 = *pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + cVar13;
  *(char **)pcVar6 = pcVar6;
  *pcVar6 = *pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_2[0xc000000] = param_2[0xc000000] + cVar13;
  cVar4 = *pcVar6;
  pcVar9 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),cVar4);
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  pcVar9 = *(char **)pcVar9;
  *pcVar9 = *pcVar9;
  cVar4 = (char)pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x73f40000);
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar13;
  pcVar9[0] = '\0';
  pcVar9[1] = '\0';
  pcVar9[2] = '\0';
  pcVar9[3] = '\0';
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar9[0xc000000] = pcVar9[0xc000000] + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + bVar15;
  *param_1 = *param_1 + cVar13;
  cVar5 = (char)((uint)pcVar9 >> 8);
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  param_2[0xc000000] = param_2[0xc000000] + bVar15;
  *param_2 = *param_2 + bVar15;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  *unaff_EBX = *unaff_EBX + bVar11;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  pcVar6 = (char *)((int)unaff_EBX * 2 + -0x6bf40000);
  *pcVar6 = *pcVar6 + cVar13;
  *unaff_EBX = *unaff_EBX + bVar11;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar13;
  *unaff_EBP = *unaff_EBP + (char)unaff_EBP;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar13;
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar13;
  cVar4 = (char)unaff_EDI;
  *unaff_EDI = *unaff_EDI + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + bVar15;
  pcVar6 = (char *)(int)(short)unaff_EDI;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  pcVar9[0xc000000] = pcVar9[0xc000000] + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  pcVar6 = (char *)(((int)pcVar6 >> 0x1f) + 0xc000000);
  *pcVar6 = *pcVar6 + bVar15;
  uVar21 = func_0x00008000();
  iVar16 = (int)(uVar21 >> 0x20);
  pcVar9 = (char *)uVar21;
  cVar13 = (char)(extraout_ECX >> 8);
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + bVar15;
  cVar4 = (char)uVar21;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x63f40000);
  *pcVar6 = *pcVar6 + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + bVar15;
  bVar20 = (in_CS & 0x400) != 0;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pbVar1 = (byte *)(unaff_ESI + 0xc000004);
  bVar11 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar15;
  bVar11 = ((char)*pbVar1 < '\0') << 7 | (*pbVar1 == 0) << 6 |
           ((int)(uVar21 & 0xffff000000001000) != 0) << 4 | ((POPCOUNT(*pbVar1) & 1U) == 0) << 2 |
           2U | CARRY1(bVar11,bVar15);
  pcVar6 = (char *)CONCAT22((short)(uVar21 >> 0x10),CONCAT11(bVar11,cVar4));
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6[0xc000000] = pcVar6[0xc000000] + bVar11;
  pcVar6 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),SUB_00008000);
  *pcVar6 = *pcVar6 + SUB_00008000;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + bVar11;
  pcVar9 = _SUB_00008000;
  cVar4 = (char)_SUB_00008000;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  cVar5 = (char)((uint)_SUB_00008000 >> 8);
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar5;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar5;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x5bf40000);
  *pcVar6 = *pcVar6 + cVar5;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar5;
  *(undefined4 *)pcVar7 = *(undefined4 *)unaff_EBP;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[(uint)bVar20 * -8 + 0x72] = unaff_ESI[(uint)bVar20 * -8 + 0x72] + cVar13;
  unaff_EBP[(uint)bVar20 * -8 + 0xc000004] = unaff_EBP[(uint)bVar20 * -8 + 0xc000004] + cVar5;
  iVar2 = (uint)bVar20 * -2 + (uint)bVar20 * -8 + 9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[iVar2 + 0x6a] = unaff_ESI[iVar2 + 0x6a] + cVar13;
  unaff_ESI[iVar2 + 0xc000000] = unaff_ESI[iVar2 + 0xc000000] + cVar5;
  pcVar6 = unaff_ESI + (uint)bVar20 * -8 + iVar2 + 4;
  pcVar7 = unaff_EBP + (uint)bVar20 * -8 + (uint)bVar20 * -2 + (uint)bVar20 * -8 + 9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  pcVar9[0xc000000] = pcVar9[0xc000000] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar13;
  pcVar19 = pcVar6 + (uint)bVar20 * -2 + 1;
  *pcVar6 = cVar4;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[0x6a] = pcVar19[0x6a] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar13;
  iVar2 = (uint)bVar20 * -8;
  *(char **)pcVar19 = pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x53f40000);
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  iVar3 = (uint)bVar20 * -8;
  pcVar6 = *(char **)pcVar7;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + cVar13;
  iVar2 = (uint)bVar20 * -2 + iVar2 + 5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000] + cVar13;
  iVar2 = (uint)bVar20 * -8 + iVar2 + 4;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  cVar4 = (char)(uVar21 >> 0x28);
  pcVar6[0xc000000] = pcVar6[0xc000000] + cVar4;
  puVar10 = (undefined1 *)(((uint)pcVar6 >> 8) * 0x100);
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  pcVar6 = (char *)(((uint)pcVar6 >> 8) * 0x200 + -0x4bf40000);
  *pcVar6 = *pcVar6 + cVar4;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000];
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  puVar10[0xc000000] = puVar10[0xc000000];
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  puVar10 = (undefined1 *)((extraout_ECX & 0xffff0000) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  puVar10 = (undefined1 *)((int)((uVar21 & 0xffff000000001000) >> 0x20) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  puVar10 = (undefined1 *)(((uint)param_2 & 0xffff0000) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  cRambc0d0000 = cRambc0d0000 + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000] + -0x80;
  cRam00040080 = cRam00040080 + -0x80;
  cRam00008080 = cRam00008080 + -0x80;
  cRam00048000 = cRam00048000 + -0x80;
  _SUB_00008000 = (char *)CONCAT31(SUB_00008000_1,SUB_00008000 + -0x80);
  out((int)_SUB_00008000 + 1,0x8000);
  out(*(undefined4 *)((uint)bVar20 * -8 + 0x8004),0x8000);
  _SUB_00008000 = (char *)((int)_SUB_00008000 + 3);
  iVar2 = iRam000080ff + 1;
  iRam000080ff._0_1_ = (char)iVar2;
  iRam000080ff = CONCAT31((int3)((uint)iVar2 >> 8),(char)iRam000080ff + -4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// 0061d300 FUN_0061d300

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d300(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  char cVar9;
  char *in_EAX;
  undefined2 uVar11;
  byte *pbVar5;
  int *piVar6;
  char *pcVar7;
  undefined3 uVar10;
  char *pcVar8;
  char cVar12;
  char cVar13;
  byte bVar14;
  undefined2 uVar15;
  char cVar16;
  char cVar17;
  undefined2 uVar18;
  char cVar19;
  char cVar20;
  char cVar21;
  undefined4 unaff_EBX;
  undefined2 uVar22;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  cVar13 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar19 = (char)unaff_EBX + cVar13;
  cVar3 = (char)in_EAX;
  *in_EAX = *in_EAX + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)((uint)unaff_EBX >> 8),cVar19) + unaff_EBP * 8);
  cVar16 = (char)param_1;
  *pcVar8 = *pcVar8 + cVar16;
  *in_EAX = *in_EAX + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar11 = (undefined2)((uint)in_EAX >> 0x10);
  cVar9 = (char)((uint)in_EAX >> 8) + cVar13;
  pcVar7 = (char *)CONCAT22(uVar11,CONCAT11(cVar9,cVar3));
  *pcVar7 = *pcVar7 + cVar3;
  (&stack0x00000000)[unaff_EBP * 8] = (&stack0x00000000)[unaff_EBP * 8] + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar15 = (undefined2)((uint)param_1 >> 0x10);
  cVar13 = cVar13 * '\x02';
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EBP * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar18 = (undefined2)((uint)param_2 >> 0x10);
  cVar17 = (char)((uint)param_2 >> 8) + cVar13;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_ESI + unaff_EBP * 2) = *(char *)(unaff_ESI + unaff_EBP * 2) + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar22 = (undefined2)((uint)unaff_EBX >> 0x10);
  cVar21 = (char)((uint)unaff_EBX >> 8) + cVar13;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EDI + unaff_EBP * 8);
  *pcVar8 = *pcVar8 + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar3 = cVar3 + cVar17;
  pcVar7 = (char *)CONCAT31((int3)((uint)pcVar7 >> 8),cVar3);
  *pcVar7 = *pcVar7 + cVar3;
  pcVar7[(int)unaff_ESI * 8] = pcVar7[(int)unaff_ESI * 8] + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar12 = cVar16 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar15,CONCAT11(cVar13,cVar16)) >> 8),cVar12) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar16 = (char)param_2 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar18,CONCAT11(cVar17,(char)param_2)) >> 8),cVar16) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar20 = cVar19 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar22,CONCAT11(cVar21,cVar19)) >> 8),cVar20) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar9 = cVar9 + cVar17;
  pcVar7 = (char *)CONCAT22(uVar11,CONCAT11(cVar9,cVar3));
  *pcVar7 = *pcVar7 + cVar3;
  (&stack0x00000000)[(int)unaff_ESI * 8] = (&stack0x00000000)[(int)unaff_ESI * 8] + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar13 = cVar13 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)((int)unaff_ESI * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar17 = cVar17 * '\x02';
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)((int)unaff_ESI * 9) = *(char *)((int)unaff_ESI * 9) + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar21 = cVar21 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EDI + (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  bVar4 = cVar3 + cVar21;
  pcVar7 = (char *)CONCAT31((int3)((uint)pcVar7 >> 8),bVar4);
  *pcVar7 = *pcVar7 + bVar4;
  pcVar7[unaff_EDI * 8] = pcVar7[unaff_EDI * 8] + cVar12;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar3 = cVar12 + cVar21;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar15,CONCAT11(cVar13,cVar12)) >> 8),cVar3) +
                   unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar12 = cVar16 + cVar21;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar18,CONCAT11(cVar17,cVar16)) >> 8),cVar12) +
                   unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar22,CONCAT11(cVar21,cVar20)) >> 8),cVar20 + cVar21)
                   + unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  pbVar5 = (byte *)CONCAT22(uVar11,CONCAT11(cVar9 + cVar21,bVar4));
  *pbVar5 = *pbVar5 + bVar4;
  (&stack0x00000000)[unaff_EDI * 8] = (&stack0x00000000)[unaff_EDI * 8] + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  bVar14 = cVar13 + cVar21;
  *pbVar5 = *pbVar5 + bVar4;
  pcVar8 = (char *)(unaff_EDI * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + bVar14;
  uVar11 = CONCAT11(cVar17 + cVar21,cVar12);
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_ESI + unaff_EDI * 2) = *(char *)(unaff_ESI + unaff_EDI * 2) + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + bVar14;
  pcVar8 = (char *)CONCAT22(uVar22,CONCAT11(cVar21 * '\x02',cVar20 + cVar21));
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + cVar3;
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  uVar10 = (undefined3)((uint)pbVar5 >> 8);
  if (!SCARRY1(bVar1,bVar4)) {
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    out(*unaff_ESI,uVar11);
    pbVar5 = (byte *)CONCAT31(uVar10,bVar4);
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    out(unaff_ESI[1],uVar11);
    *pbVar5 = *pbVar5 | bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(char *)CONCAT31(uVar10,bVar4) = *(char *)CONCAT31(uVar10,bVar4) + bVar4;
    piVar6 = (int *)CONCAT31(uVar10,0xff);
    *piVar6 = *piVar6 + 1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar5 = *pbVar5 + bVar4;
  *pbVar5 = *pbVar5 + cVar12;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + cVar3;
  *(int *)pbVar5 = *(int *)pbVar5 + 1;
  *pbVar5 = *pbVar5 + bVar4;
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  *(byte **)pbVar5 = pbVar5 + (uint)CARRY1(bVar1,bVar4) + *(int *)pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar2 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  cVar13 = (char)*piVar6 + -1 + ((char)iVar2 != '\0');
  pcVar7 = (char *)CONCAT31(uVar10,cVar13);
  *pcVar7 = *pcVar7 + cVar13;
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar2 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  pcVar7 = (char *)((int)piVar6 + (uint)((char)iVar2 != '\0') + *piVar6);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  uVar10 = (undefined3)((uint)pcVar7 >> 8);
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  iVar2 = *piVar6;
  *piVar6 = *piVar6 + 1;
  if (!SCARRY4(iVar2,1)) {
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(*unaff_ESI,uVar11);
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(unaff_ESI[1],uVar11);
    *(char *)piVar6 = -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    pcVar7 = (char *)((int)piVar6 + 1);
    out(unaff_ESI[2],uVar11);
    cVar13 = (char)pcVar7;
    *pcVar7 = *pcVar7 + cVar13;
    *(int *)((int)piVar6 + 0x101) = *(int *)((int)piVar6 + 0x101) + 1;
    pbVar5 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar5 = *pbVar5 ^ bVar14;
    *pcVar7 = *pcVar7 + cVar12;
    *pcVar7 = *pcVar7 + cVar13;
    *pcVar8 = *pcVar8 + cVar13;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,uVar11);
  pcVar8 = (char *)CONCAT31(uVar10,0xff);
  *pcVar8 = *pcVar8 + -1;
  *(int *)(pcVar8 + 0x100) = *(int *)(pcVar8 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// 0061d450 FUN_0061d450

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d450(undefined4 param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  byte *in_EAX;
  int *piVar6;
  char *pcVar7;
  undefined3 uVar8;
  char *unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  bool in_OF;
  
  bVar4 = (byte)in_EAX;
  uVar8 = (undefined3)((uint)in_EAX >> 8);
  if (!in_OF) {
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    out(*unaff_ESI,param_2);
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    out(unaff_ESI[1],param_2);
    *in_EAX = *in_EAX | bVar4;
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    piVar6 = (int *)CONCAT31(uVar8,0xff);
    *piVar6 = *piVar6 + 1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *in_EAX = *in_EAX + bVar4;
  *in_EAX = *in_EAX + (char)param_2;
  *in_EAX = *in_EAX + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + (char)param_1;
  *(int *)in_EAX = *(int *)in_EAX + 1;
  *in_EAX = *in_EAX + bVar4;
  bVar2 = *in_EAX;
  *in_EAX = *in_EAX + bVar4;
  *(byte **)in_EAX = in_EAX + (uint)CARRY1(bVar2,bVar4) + *(int *)in_EAX;
  *in_EAX = *in_EAX + bVar4;
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar3 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  cVar5 = (char)*piVar6 + -1 + ((char)iVar3 != '\0');
  pcVar7 = (char *)CONCAT31(uVar8,cVar5);
  *pcVar7 = *pcVar7 + cVar5;
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar3 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  pcVar7 = (char *)((int)piVar6 + (uint)((char)iVar3 != '\0') + *piVar6);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  uVar8 = (undefined3)((uint)pcVar7 >> 8);
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  iVar3 = *piVar6;
  *piVar6 = *piVar6 + 1;
  if (!SCARRY4(iVar3,1)) {
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(*unaff_ESI,param_2);
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(unaff_ESI[1],param_2);
    *(char *)piVar6 = -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    pcVar7 = (char *)((int)piVar6 + 1);
    out(unaff_ESI[2],param_2);
    cVar5 = (char)pcVar7;
    *pcVar7 = *pcVar7 + cVar5;
    *(int *)((int)piVar6 + 0x101) = *(int *)((int)piVar6 + 0x101) + 1;
    pbVar1 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar1 = *pbVar1 ^ (byte)((uint)param_1 >> 8);
    *pcVar7 = *pcVar7 + (char)param_2;
    *pcVar7 = *pcVar7 + cVar5;
    *unaff_EBX = *unaff_EBX + cVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,param_2);
  pcVar7 = (char *)CONCAT31(uVar8,0xff);
  *pcVar7 = *pcVar7 + -1;
  *(int *)(pcVar7 + 0x100) = *(int *)(pcVar7 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// 0061d500 FUN_0061d500

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d500(undefined4 param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte *in_EAX;
  byte *pbVar4;
  char *pcVar5;
  char *unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  char in_CF;
  bool in_OF;
  
  bVar2 = (byte)in_EAX;
  if (!in_OF) {
    *in_EAX = *in_EAX + bVar2;
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    out(*unaff_ESI,param_2);
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    out(unaff_ESI[1],param_2);
    *in_EAX = *in_EAX | bVar2;
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    pbVar4 = in_EAX + 1;
    out(unaff_ESI[2],param_2);
    cVar3 = (char)pbVar4;
    *pbVar4 = *pbVar4 + cVar3;
    *(int *)(in_EAX + 0x101) = *(int *)(in_EAX + 0x101) + 1;
    pbVar1 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar1 = *pbVar1 ^ (byte)((uint)param_1 >> 8);
    *pbVar4 = *pbVar4 + (char)param_2;
    *pbVar4 = *pbVar4 + cVar3;
    *unaff_EBX = *unaff_EBX + cVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,param_2);
  pcVar5 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),bVar2 - in_CF);
  *pcVar5 = *pcVar5 + (bVar2 - in_CF);
  *(int *)(pcVar5 + 0x100) = *(int *)(pcVar5 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// 0061f620 FUN_0061f620

void __fastcall FUN_0061f620(undefined4 param_1)

{
  int iVar1;
  
  FUN_0061f040(param_1);
  FUN_0061f000(param_1);
  FUN_0061f040();
  iVar1 = PeekMessageA((LPMSG)&DAT_00709738,(HWND)0x0,0,0,1);
  while (iVar1 != 0) {
    TranslateMessage((MSG *)&DAT_00709738);
    DispatchMessageA((MSG *)&DAT_00709738);
    iVar1 = PeekMessageA((LPMSG)&DAT_00709738,(HWND)0x0,0,0,1);
  }
  return;
}


// 0061f690 FUN_0061f690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061f690(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = (float)*(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x4c) < 0) {
    fVar1 = fVar1 + _DAT_006cc858;
  }
  *param_2 = fVar1;
  fVar1 = (float)*(int *)(param_1 + 0x50);
  if (*(int *)(param_1 + 0x50) < 0) {
    fVar1 = fVar1 + _DAT_006cc858;
  }
  *param_3 = fVar1;
  return;
}


// 006203c0 FUN_006203c0

undefined4 * __thiscall FUN_006203c0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7818;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00620ba0 FUN_00620ba0

undefined4 * __thiscall FUN_00620ba0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7814;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 00621240 FUN_00621240

int __fastcall FUN_00621240(int param_1)

{
  int iVar1;
  int iVar2;
  
  Sleep(0);
  iVar1 = (**(code **)(*DAT_00709d80 + 0x3c))(DAT_00709d80,0,0,0,0);
  if (iVar1 == -0x7789f798) {
    FUN_00621160();
  }
  iVar2 = *(int *)(param_1 + 100) + 1;
  iVar1 = *(int *)(param_1 + 0xb4) + 1;
  *(int *)(param_1 + 0xb4) = iVar1 % iVar2;
  DAT_00709570 = DAT_00709570 + 1;
  return iVar1 / iVar2;
}


// 00624860 FUN_00624860

void FUN_00624860(void)

{
  FUN_00622720(*(undefined4 *)(DAT_00709df0 + 4),
               *(undefined4 *)(*(int *)(DAT_00709df0 + 0x10) + 4 + DAT_00709f70 * 8));
  return;
}


// 00624c80 FUN_00624c80

void FUN_00624c80(void)

{
  int iVar1;
  int iStack_4;
  
  FUN_00622770(DAT_0070ab50);
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar1 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar1,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,
                   (DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      iVar1 = iVar1 + 1;
    } while (iVar1 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// 006250a0 FUN_006250a0

void FUN_006250a0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x12,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// 00625100 FUN_00625100

void FUN_00625100(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x14,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// 00625160 FUN_00625160

void FUN_00625160(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x16,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// 006251c0 FUN_006251c0

void FUN_006251c0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,3,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  DAT_0070ab4c = 0;
  return;
}


// 00625260 FUN_00625260

void FUN_00625260(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,DAT_00709dfc);
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// 00625340 FUN_00625340

void FUN_00625340(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_00622770(DAT_0070ab50);
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,DAT_00709dfc);
      iVar3 = iVar3 + 1;
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// 00625400 FUN_00625400

void __fastcall FUN_00625400(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 unaff_EBX;
  int unaff_EDI;
  int in_stack_00000020;
  
  DAT_00709df0 = in_EAX;
  while( true ) {
    unaff_EDI = unaff_EDI + 1;
    DAT_00709df0 = DAT_00709df0 + (param_2 & 0xffff);
    if (in_stack_00000020 <= unaff_EDI) break;
    uVar1 = *DAT_00709df0;
    while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
      (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
      DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
      uVar1 = *DAT_00709df0;
    }
    FUN_00622770();
    FUN_006269d0();
    FUN_00622020();
    FUN_00622780();
    FUN_00622860();
    param_2 = *DAT_00709df0;
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)unaff_EBX;
  return;
}


// 00625440 FUN_00625440

void FUN_00625440(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,
                   (DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      iVar3 = iVar3 + 1;
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// 00625640 FUN_00625640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00625640(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  float *pfVar5;
  char cStack_39;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_28;
  float fStack_24;
  float afStack_20 [6];
  float fStack_8;
  float fStack_4;
  
  if (DAT_0070a4c8 != '\0') {
    DAT_0070a4c8 = '\0';
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x89,0);
  }
  DAT_0070ab48 = *(int *)(DAT_00709df0 + 4);
  cVar4 = '\x01';
  if (DAT_0070ab48 == 0) {
LAB_00625692:
    cVar2 = FUN_00620230();
    if (cVar2 == '\0') goto LAB_0062569d;
  }
  else {
    cVar2 = FUN_00620240();
    if (cVar2 == '\0') {
      if (DAT_0070ab48 != 0) goto LAB_0062569d;
      goto LAB_00625692;
    }
  }
  cVar4 = '\0';
LAB_0062569d:
  FUN_0061f7a0(cVar4);
  FUN_0061f040();
  FUN_0061efe0();
  FUN_006202f0(&cStack_39);
  if (cStack_39 != DAT_0070a4d0) {
    DAT_0070a4d0 = cStack_39;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x1c,cStack_39);
  }
  if (cStack_39 != '\0') {
    if (DAT_0070ab48 != 0) {
      iVar3 = EAGL__PC__GetDirectDraw();
      FUN_00620330(&iStack_28);
      FUN_00620310(&fStack_24);
      if (iStack_28 != DAT_0070a4d4) {
        DAT_0070a4d4 = iStack_28;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x8c,iStack_28);
      }
      if (fStack_24 != DAT_0070a4d8) {
        DAT_0070a4d8 = fStack_24;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x23,fStack_24);
      }
      if ((cVar4 == '\0') && ((*(uint *)(iVar3 + 0x248) & 0x100000) != 0)) {
        FUN_006202b0(&fStack_38);
        FUN_006202d0(&fStack_34);
        if (DAT_006e2b88 != fStack_38) {
          DAT_006e2b88 = fStack_38;
          (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x24,fStack_38);
        }
        if (DAT_006e2b8c != fStack_34) {
          DAT_006e2b8c = fStack_34;
          (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x25,fStack_34);
        }
        DAT_0070ab50 = 0;
        return;
      }
      iVar3 = FUN_0061f0d0();
      if (iVar3 == 0) {
        FUN_0061f040();
        FUN_0061eff0();
        FUN_0061f0d0();
      }
      FUN_006267a0(&fStack_38);
      FUN_006267c0(&fStack_34);
      FUN_00626800(&fStack_30);
      FUN_006267e0(&fStack_2c);
      pfVar5 = afStack_20;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = 0.0;
        pfVar5 = pfVar5 + 1;
      }
      FUN_006202b0(&DAT_0070ab34);
      FUN_006202d0(&DAT_0070ab38);
      if (((((fStack_38 != _DAT_0070ab24) || (fStack_34 != _DAT_0070ab28)) ||
           (fStack_30 != _DAT_0070ab2c)) ||
          ((fStack_2c != _DAT_0070ab30 || (afStack_20[2] != _DAT_0070ab34)))) ||
         (fStack_8 != _DAT_0070ab38)) {
        _DAT_0070ab24 = fStack_38;
        _DAT_0070ab28 = fStack_34;
        _DAT_0070ab30 = fStack_2c;
        _DAT_0070ab34 = afStack_20[2];
        _DAT_0070ab2c = fStack_30;
        _DAT_0070ab38 = fStack_8;
        fStack_4 = 1.0;
        afStack_20[3] = 1.0;
        afStack_20[2] = afStack_20[2] - fStack_38;
        fStack_8 = fStack_8 - fStack_38;
        FUN_00622690(2,afStack_20,afStack_20);
        fVar1 = afStack_20[2] / afStack_20[3];
        if (DAT_006e2b88 != fVar1) {
          DAT_006e2b88 = fVar1;
          (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x24,fVar1);
        }
        fVar1 = fStack_8 / fStack_4;
        if (DAT_006e2b8c != fVar1) {
          DAT_006e2b8c = fVar1;
          (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x25,fVar1);
          DAT_0070ab50 = 0;
          return;
        }
      }
      DAT_0070ab50 = 0;
      return;
    }
    FUN_006202b0(&fStack_24);
    FUN_006202d0(&fStack_2c);
    FUN_00620350(&fStack_30);
    _DAT_00709e64 = _DAT_006cc7bc / (fStack_2c - fStack_24);
    _DAT_00709e60 = _DAT_006cc8a8 * _DAT_00709e64;
    _DAT_00709e64 = _DAT_00709e64 * fStack_2c;
    FUN_0061f040();
    FUN_0061efe0();
    FUN_00620330(&iStack_28);
    fVar1 = _DAT_006a7a18;
    if ((iStack_28 == 1) || (fVar1 = _DAT_006a7a1c, iStack_28 == 2)) {
      _DAT_00709e6c = fVar1 * fStack_30;
    }
    if (DAT_0070a4d4 != 0) {
      DAT_0070a4d4 = 0;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x8c,0);
    }
    if (DAT_0070a4d8 != 0.0) {
      DAT_0070a4d8 = 0.0;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x23,0);
    }
  }
  DAT_0070ab50 = 0;
  return;
}


// 00625f60 FUN_00625f60

void FUN_00625f60(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar2) {
    iVar2 = DAT_0070a9c4;
  }
  FUN_00625db0(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  if (0 < iVar2) {
    puVar1 = &DAT_0070aba0;
    do {
      D3DXMatrixTranspose(puVar1,puVar1);
      puVar1 = puVar1 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// 00626d50 FUN_00626d50

void __thiscall FUN_00626d50(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x24))(param_2,param_3,param_4,0);
  return;
}


// 00626f20 FUN_00626f20

void __thiscall FUN_00626f20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar1 * 4) + 0xc))(param_2,param_3,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return;
}


// 006270a0 FUN_006270a0

undefined4 * __thiscall FUN_006270a0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_LAB_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x1c);
  }
  return param_1;
}


// 006273a0 FUN_006273a0

void FUN_006273a0(void)

{
  (*(code *)PTR_FUN_006dfaa0)(DAT_0070d35c,DAT_0070d358);
  return;
}


// 00627410 FUN_00627410

void FUN_00627410(undefined2 *param_1)

{
  switch(*param_1) {
  case 0:
    FUN_0062be20(param_1);
    return;
  case 0xf:
    FUN_0062b530(param_1);
    return;
  case 0x16:
    FUN_0062b950(param_1);
    return;
  case 0x17:
    FUN_0062b920(param_1);
  }
  return;
}


// 00627490 FUN_00627490

void FUN_00627490(ushort param_1,undefined4 *param_2)

{
  *param_2 = (&DAT_0070cef0)[param_1];
  (&DAT_0070cef0)[param_1] = param_2;
  return;
}


// 00627c00 FUN_00627c00

undefined4 * __thiscall FUN_00627c00(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7f5c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// 006313f0 FUN_006313f0

void __thiscall FUN_006313f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x48))(param_3,0,param_4);
  return;
}


// 00633063 FUN_00633063

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
  FID_conflict__wprintf
            ("currTime: %g  offset: %g   cycle: %g\n",(double)*(float *)(unaff_EBP + 8),
             (double)*(float *)(param_1 + 0x40),(double)(_DAT_006cc7bc / *(float *)(param_1 + 0x38))
            );
  FID_conflict__wprintf
            ("offset0: %g  offset1: %g\n",(double)*(float *)(param_1 + 0x30),
             (double)*(float *)(param_1 + 0x34));
  FID_conflict__wprintf
            ("cycle0: %g  cycle1: %g\n",(double)*(float *)(param_1 + 0x28),
             (double)*(float *)(param_1 + 0x2c));
  FID_conflict__wprintf
            ("before offset t0: %g  t1: %g\n",
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


// 00636564 FUN_00636564

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


// 00636974 FUN_00636974

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


// 00636ba0 FUN_00636ba0

void __thiscall FUN_00636ba0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x18))(param_3,param_4,0);
  return;
}


// 00639040 FUN_00639040

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


// 006390f0 FUN_006390f0

bool FUN_006390f0(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) == param_2;
}


// 00639690 FUN_00639690

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


// 0063aa63 FUN_0063aa63

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


// 0063b280 FUN_0063b280

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
  DAT_0070f468 = 1;
  FUN_00641a90(0x70f454);
  return;
}


// 0063b28a FUN_0063b28a

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
  DAT_0070f468 = 1;
  FUN_00641a90();
  return;
}


// 0064004b FUN_0064004b

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


// 0064010a FUN_0064010a

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
      in_EAX = func_0x00683ed0();
    }
  }
  CriticalSection__Leave();
  return unaff_EDI << 0x10 | in_EAX;
}


// 0064252b FUN_0064252b

void FUN_0064252b(void)

{
  undefined4 *unaff_ESI;
  char in_SF;
  char in_OF;
  
  while (in_OF == in_SF) {
    if ((code *)*unaff_ESI != (code *)0x0) {
      (*(code *)*unaff_ESI)();
    }
    *unaff_ESI = 0;
    in_SF = (int)(unaff_ESI + -0x1c3f8f) < 0;
    in_OF = SBORROW4((int)(unaff_ESI + -1),0x70fe38);
    unaff_ESI = unaff_ESI + -1;
  }
  return;
}


// 00643125 FUN_00643125

void FUN_00643125(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (in_EAX == 0) {
    func_0x00643090();
  }
  CriticalSection__Enter(0x70ff44);
  iVar2 = 0;
  iVar3 = -1;
  do {
    iVar1 = *(int *)(iVar2 * 4 + 0x70ff70);
    if (((iVar1 != 0) || (iVar4 = iVar2, -1 < iVar3)) && (iVar4 = iVar3, iVar1 == param_1))
    goto CriticalSection__Leave;
    iVar2 = iVar2 + 1;
    iVar3 = iVar4;
  } while (iVar2 < 8);
  if (iVar4 != -1) {
    *(int *)(iVar4 * 4 + 0x70ff70) = param_1;
  }
CriticalSection__Leave:
  LeaveCriticalSection((LPCRITICAL_SECTION)0x70ff48);
  return;
}


// 0064dbf0 FUN_0064dbf0

void FUN_0064dbf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (*(char *)(param_2 + 0x18) != '\0') {
    puVar2 = (undefined4 *)(param_2 + 0x1c);
    do {
      *puVar2 = *(undefined4 *)(param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(param_2 + 0x18));
  }
  *(undefined1 *)(param_2 + 0x19) = 1;
  return;
}


// 0064e9c0 Mutex__Lock

void Mutex__Lock(void)

{
  Mutex__Lock();
  return;
}


// 0064f0e0 FUN_0064f0e0

void FUN_0064f0e0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  DAT_00713c7a = 1;
  FUN_0064e520();
  for (puVar1 = DAT_00713c90; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if (*(char *)(puVar1 + 5) == '\0') {
      puVar1[7] = 0xffffffff;
      puVar1[8] = 0;
      if (*(char *)puVar1[9] == '\x01') {
        SNDSYS_leavecritical();
        FUN_006504b0(puVar1[6],0,puVar1[10],*(int *)(puVar1[9] + 4) + puVar1[0xb]);
      }
      else {
        SNDSYS_leavecritical();
        uVar2 = FUN_006504b0(puVar1[6],1000,puVar1[10],*(int *)(puVar1[9] + 4) + puVar1[0xb]);
        puVar1[7] = uVar2;
      }
      FUN_0064e520();
      *(undefined1 *)(puVar1 + 5) = 1;
    }
    if (((*(char *)(puVar1 + 5) == '\x01') && (*(char *)puVar1[9] == '\x02')) &&
       (iVar3 = FUN_00650020(puVar1[6]), 0 < *(int *)(iVar3 + 0x154))) {
      SNDSYS_leavecritical();
      FUN_006504b0(puVar1[6],0,puVar1[10],*(int *)(puVar1[9] + 8) + puVar1[0xb]);
      FUN_0064e520();
    }
  }
  DAT_00713c7a = 0;
  for (; '\0' < DAT_00713c79; DAT_00713c79 = DAT_00713c79 + -1) {
    FUN_00652960(DAT_00713c88);
  }
  SNDSYS_leavecritical();
  return;
}


// 006500a0 FUN_006500a0

void FUN_006500a0(int param_1)

{
  undefined4 uStack00000008;
  
  uStack00000008 = *(undefined4 *)(param_1 + -4);
  FUN_00412ee0();
  return;
}


// 006564f0 thunk_FUN_00650fd0

void thunk_FUN_00650fd0(void)

{
  FUN_00650fd0();
  return;
}


// 00657b20 FUN_00657b20

undefined4 FUN_00657b20(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00657b43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1 + 4))();
    return uVar1;
  }
  return 0xffffffff;
}


// 00659550 FUN_00659550

int FUN_00659550(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 *puStack_84;
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [112];
  
  iStack_90 = param_4;
  iVar5 = 0;
  if (*(int *)(param_1 + 0x30) < 2) {
    if (*(int *)(param_1 + 0x40) == 0) {
      iVar2 = *(int *)(param_1 + 0x44) / 0x1c;
      FUN_0065f610(*(undefined4 *)(param_1 + 0x34),iVar2 * 0x70,iVar2 * 0x1c);
      *(undefined4 *)(param_1 + 0x40) = 1;
    }
    if (param_2 != 0) {
      do {
        iVar2 = FUN_0065f640(&iStack_90,param_2);
        iStack_90 = iStack_90 + iVar2 * 4;
        iVar5 = iVar5 + iVar2;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar2;
        if (iVar2 < param_2) {
          iVar1 = *(int *)(param_1 + 0x44);
          param_2 = param_2 - iVar2;
          iVar4 = iVar1 % 0x1c;
          iVar2 = (*(int *)(param_1 + 0x48) - iVar1) + 1 + iVar4;
          *(int *)(param_1 + 0x20) = iVar1 - iVar4;
          FUN_0065f610(((iVar1 - iVar4) / 0x1c) * 0xf + *(int *)(param_1 + 0x34),iVar2 * 4,iVar2);
          if (*(int *)(param_1 + 0x3c) == 0) {
            puVar3 = (undefined4 *)FUN_0065f8e0(auStack_80);
            uStack_8c = *puVar3;
            uStack_88 = puVar3[1];
            *(undefined4 *)(param_1 + 0x50) = uStack_88;
            *(undefined4 *)(param_1 + 0x4c) = uStack_8c;
            iVar2 = FUN_0065f640(&iStack_90,param_2);
            iStack_90 = iStack_90 + iVar2 * 4;
            iVar5 = iVar5 + iVar2;
            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar2;
            *(undefined4 *)(param_1 + 0x3c) = 1;
            goto LAB_00659689;
          }
          uStack_88 = *(undefined4 *)(param_1 + 0x50);
          uStack_8c = *(undefined4 *)(param_1 + 0x4c);
          FUN_0065f910(&uStack_8c);
          puStack_84 = auStack_70;
          iVar2 = FUN_0065f640(&puStack_84,iVar4);
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar2;
        }
        else {
LAB_00659689:
          param_2 = param_2 - iVar2;
        }
        if (param_2 == 0) {
          return iVar5;
        }
      } while( true );
    }
  }
  else {
    while (0 < param_2) {
      iVar2 = FUN_0065f640(&iStack_90,param_2);
      param_2 = param_2 - iVar2;
      iVar5 = iVar5 + iVar2;
      iStack_90 = iStack_90 + iVar2 * 4;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar2;
      if (iVar2 < param_2) {
        iVar2 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x24);
        FUN_0065f610(*(undefined4 *)(param_1 + 0x2c),iVar2 * 4 + 4,iVar2 + 1);
      }
    }
  }
  return iVar5;
}


// 0065fd80 FUN_0065fd80

void FUN_0065fd80(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  for (iVar1 = param_2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_4 = *puVar2;
    puVar2 = puVar2 + 1;
    param_4 = param_4 + 1;
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + param_2 * 4;
  return;
}


// 00660000 FUN_00660000

void __fastcall FUN_00660000(int param_1,int param_2)

{
  int iVar1;
  float *in_EAX;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  float10 in_ST0;
  int in_stack_00000010;
  int in_stack_0000001c;
  int in_stack_00000024;
  
  for (; in_EAX[-3] = (float)in_ST0, param_1 < unaff_EDI; param_1 = param_1 + 4) {
    param_2 = param_2 + 4;
    unaff_EBX = unaff_EBX + 0x10;
    in_EAX[-2] = *(float *)((int)in_EAX + *(int *)(unaff_ESI + 0x1c) + in_stack_0000001c) +
                 in_EAX[-2];
    in_EAX[-1] = *(float *)((int)in_EAX + *(int *)(unaff_ESI + 0x1c) + in_stack_0000001c + 4) +
                 in_EAX[-1];
    *in_EAX = *(float *)(*(int *)(unaff_ESI + 0x1c) + -0x10 + unaff_EBX) + *in_EAX;
    in_ST0 = (float10)*(float *)(*(int *)(unaff_ESI + 0x1c) + in_stack_00000010 + -0x10 +
                                (int)(in_EAX + 4)) + (float10)in_EAX[1];
    in_EAX = in_EAX + 4;
  }
  while (param_2 < unaff_EDI) {
    iVar1 = param_2 * 4;
    param_2 = param_2 + 1;
    *(float *)(in_stack_00000024 + -4 + param_2 * 4) =
         *(float *)(*(int *)(unaff_ESI + 0x1c) + iVar1) +
         *(float *)(in_stack_00000024 + -4 + param_2 * 4);
  }
  return;
}


// 00660dd0 FUN_00660dd0

void FUN_00660dd0(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  *param_1 = &LAB_00660ce0;
  uVar2 = FUN_00659960(*(undefined4 *)(param_2 + 0x1c));
  uVar2 = FUN_00660820(uVar2);
  param_1[10] = uVar2;
  uVar1 = FUN_00659990(*(undefined4 *)(param_2 + 0x1c));
  *(undefined1 *)((int)param_1 + 0x31) = uVar1;
  param_1[7] = 0;
  param_1[8] = 0xffffffff;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_2 + 0x18);
  param_1[0xb] = 0;
  return;
}


// 00662b20 FUN_00662b20

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


// 00664600 FUN_00664600

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


// 00665240 FUN_00665240

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


// 0066ac00 FUN_0066ac00

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


// 0066ba10 FUN_0066ba10

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


// 0066d620 FUN_0066d620

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


// 0066fd80 FUN_0066fd80

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


// 00670000 FUN_00670000

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


// 00670067 FUN_00670067

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


// 006717f9 FUN_006717f9

undefined4 FUN_006717f9(void)

{
  size_t sVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  sVar1 = 0x14;
  if (DAT_00794360 == 0) {
    sVar1 = 0x200;
  }
  else if (0x13 < (int)DAT_00794360) goto LAB_00671818;
  DAT_00794360 = sVar1;
LAB_00671818:
  DAT_00793350 = _calloc(DAT_00794360,4);
  if (DAT_00793350 == (void *)0x0) {
    DAT_00794360 = 0x14;
    DAT_00793350 = _calloc(0x14,4);
    if (DAT_00793350 == (void *)0x0) {
      return 0x1a;
    }
  }
  iVar4 = 0;
  ppuVar2 = &PTR_DAT_006eb1c0;
  do {
    *(undefined ***)(iVar4 + (int)DAT_00793350) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar4 = iVar4 + 4;
  } while ((int)ppuVar2 < 0x6eb440);
  uVar3 = 0;
  puVar5 = &DAT_006eb1d0;
  do {
    iVar4 = *(int *)((&DAT_00793240)[(int)uVar3 >> 5] + (uVar3 & 0x1f) * 0x24);
    if ((iVar4 == -1) || (iVar4 == 0)) {
      *puVar5 = 0xffffffff;
    }
    puVar5 = puVar5 + 8;
    uVar3 = uVar3 + 1;
  } while ((int)puVar5 < 0x6eb230);
  return 0;
}


// 0067211b FUN_0067211b

void FUN_0067211b(void)

{
  __cexit_doexit(0,1,1);
  return;
}


// 00672159 FUN_00672159

undefined4 FUN_00672159(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + -0x1c);
  if (**(int **)(unaff_EBP + -0x20) != -0x1f928c9d) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    return *(undefined4 *)(unaff_EBP + -0x24);
  }
  terminate();
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}


// 00672626 FUN_00672626

void FUN_00672626(void)

{
  __amsg_exit(0x19);
  return;
}


// 006730ae FUN_006730ae

void FUN_006730ae(undefined4 param_1,int param_2,undefined4 param_3)

{
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),param_2,0);
  return;
}


// 00673374 FUN_00673374

undefined4 FUN_00673374(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// 00673824 FUN_00673824

float10 FUN_00673824(void)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  float10 in_ST1;
  float10 extraout_ST1;
  
  do {
    if (DAT_00717ad4 == 1) {
      in_ST1 = (float10)FUN_0067cc0c();
      in_ST0 = extraout_ST1;
    }
    else {
      in_ST1 = in_ST1 - (float10)(unkint10)(in_ST1 / in_ST0) * in_ST0;
    }
  } while ((in_FPUStatusWord & 0x400) != 0);
  return in_ST1;
}


// 00674a4e FUN_00674a4e

void FUN_00674a4e(void)

{
  ulong _ExceptionNum;
  int unaff_EBP;
  
  _ExceptionNum = (*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14))->ExceptionRecord->ExceptionCode;
  *(ulong *)(unaff_EBP + -0x1c) = _ExceptionNum;
  __XcptFilter(_ExceptionNum,*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14));
  return;
}


// 00674a62 FUN_00674a62

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00674a62(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x1c);
                    /* WARNING: Subroutine does not return */
  *(undefined **)(iVar1 + -8) = &UNK_00674a6d;
  __exit(*(int *)(iVar1 + -4));
}


// 00674eb2 FUN_00674eb2

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00674eb2(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 3;
                    /* WARNING: Subroutine does not return */
  *(undefined **)(iVar1 + -8) = &UNK_00674ec1;
  ExitProcess(*(UINT *)(iVar1 + -4));
}


// 00675843 FUN_00675843

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00675843(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (&UNK_006cce93 < *(undefined **)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x67583d;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x675855;
  return;
}


// 00675856 FUN_00675856

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_00675856(void)

{
  undefined4 *puStack_20;
  
  for (puStack_20 = &DAT_006cce9c; puStack_20 < &DAT_006cce9c; puStack_20 = puStack_20 + 1) {
    if ((code *)*puStack_20 != (code *)0x0) {
      (*(code *)*puStack_20)();
    }
  }
  return;
}


// 00675887 FUN_00675887

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00675887(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (&UNK_006cce9b < *(undefined **)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x675881;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x675899;
  return;
}


// 00676cd2 FUN_00676cd2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_00676cd2(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  void *pvVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  byte bVar16;
  uint uVar17;
  undefined1 *puVar18;
  byte *pbVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  int unaff_EBP;
  byte *pbVar23;
  char *pcVar24;
  char *pcVar25;
  byte *pbVar26;
  undefined8 uVar27;
  
  puVar21 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar21 + -4) = 0x676cda;
  FUN_0068041c();
  *(undefined4 *)(puVar21 + -4) = 0x20;
  *(undefined4 *)(puVar21 + -8) = 0x676ce1;
  pvVar12 = _malloc(*(size_t *)(puVar21 + -4));
  *(void **)(unaff_EBP + -0x20) = pvVar12;
  if (pvVar12 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00677266:
    if (*(int *)(unaff_EBP + -0x24) == 1) {
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(puVar21 + -8) = 0x677274;
      _free(*(void **)(puVar21 + -4));
    }
    iVar14 = *(int *)(unaff_EBP + -0x34);
    if (((*(int *)(unaff_EBP + -0x28) == -1) && (iVar14 == 0)) &&
       (*(char *)(unaff_EBP + -0x29) == '\0')) {
      iVar14 = -1;
    }
    *(undefined4 *)(unaff_EBP + -0x1e8) = 0x67729b;
    *(undefined4 *)(unaff_EBP + -0x1ec) = 0x6772a0;
    return iVar14;
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar26 = *(byte **)(unaff_EBP + -0x1cc);
  puVar18 = *(undefined1 **)(unaff_EBP + -0x20);
  puVar22 = puVar21;
LAB_00676d06:
  *(undefined4 *)(puVar22 + -4) = 0x20;
  *(undefined4 *)(puVar22 + -8) = 0;
  *(undefined1 **)(puVar22 + -0xc) = puVar18;
  *(undefined4 *)(puVar22 + -0x10) = 0x676d10;
  _memset(*(void **)(puVar22 + -0xc),*(int *)(puVar22 + -8),*(size_t *)(puVar22 + -4));
  if (*(int *)(unaff_EBP + -0x68) != 0x7b) goto LAB_00676d8d;
  if (*pbVar26 != 0x5d) goto LAB_00676d8d;
  bVar16 = 0x5d;
  pbVar26 = pbVar26 + 1;
  puVar18[0xb] = 0x20;
  while (bVar15 = *pbVar26, bVar15 != 0x5d) {
    if (((bVar15 == 0x2d) && (bVar16 != 0)) && (bVar4 = pbVar26[1], bVar4 != 0x5d)) {
      pbVar26 = pbVar26 + 2;
      bVar15 = bVar4;
      if (bVar16 < bVar4) {
        bVar15 = bVar16;
        bVar16 = bVar4;
      }
      if (bVar15 <= bVar16) {
        uVar17 = (uint)bVar15;
        *(uint *)(unaff_EBP + -0x1d0) = (uint)(byte)((bVar16 - bVar15) + 1);
        do {
          puVar18[uVar17 >> 3] = puVar18[uVar17 >> 3] | '\x01' << ((byte)uVar17 & 7);
          uVar17 = uVar17 + 1;
          piVar1 = (int *)(unaff_EBP + -0x1d0);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      bVar16 = 0;
    }
    else {
      *(byte *)(unaff_EBP + -0x39) = bVar15;
      puVar18[bVar15 >> 3] = puVar18[bVar15 >> 3] | '\x01' << (bVar15 & 7);
      pbVar26 = pbVar26 + 1;
LAB_00676d8d:
      bVar16 = *(byte *)(unaff_EBP + -0x39);
    }
  }
  pbVar19 = *(byte **)(unaff_EBP + -100);
  if (*(int *)(unaff_EBP + -0x68) == 0x7b) {
    *(byte **)(unaff_EBP + 0xc) = pbVar26;
  }
  uVar17 = *(uint *)(unaff_EBP + -0x68);
  puVar21 = puVar22;
LAB_00676dad:
  *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
  pbVar26 = pbVar19;
  if (*(int *)(unaff_EBP + -0x28) != -1) {
    *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(puVar21 + -0xc) = 0x676dc3;
    FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
  }
  do {
    if ((*(int *)(unaff_EBP + -0x44) != 0) &&
       (iVar14 = *(int *)(unaff_EBP + -0x48),
       *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar14 == 0))
    goto LAB_00676f6b;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    *(undefined4 *)(puVar21 + -4) = 0x676de4;
    uVar13 = __inc();
    *(uint *)(unaff_EBP + -0x28) = uVar13;
    if (uVar13 == 0xffffffff) break;
    bVar16 = (byte)uVar13;
    if ((uVar17 != 99) &&
       (((uVar17 != 0x73 || ((8 < (int)uVar13 && ((int)uVar13 < 0xe)))) || (uVar13 == 0x20)))) {
      if ((uVar17 != 0x7b) ||
         (((int)(char)(*(byte *)(((int)uVar13 >> 3) + *(int *)(unaff_EBP + -0x20)) ^
                      *(byte *)(unaff_EBP + -0x49)) & 1 << (bVar16 & 7)) == 0)) break;
      uVar17 = *(uint *)(unaff_EBP + -0x68);
    }
    if (*(char *)(unaff_EBP + -0x4b) == '\0') {
      if (*(char *)(unaff_EBP + -0x4d) == '\0') {
        *pbVar19 = bVar16;
        pbVar19 = pbVar19 + 1;
      }
      else {
        *(byte *)(unaff_EBP + -0x1d4) = bVar16;
        if ((PTR_DAT_006ec130[(uVar13 & 0xff) * 2 + 1] & 0x80) != 0) {
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676e6e;
          uVar8 = __inc();
          *(undefined1 *)(unaff_EBP + -0x1d3) = uVar8;
        }
        *(undefined4 *)(puVar21 + -4) = DAT_006ec180;
        *(int *)(puVar21 + -8) = unaff_EBP + -0x1d4;
        *(int *)(puVar21 + -0xc) = unaff_EBP + -0x1d8;
        *(undefined4 *)(puVar21 + -0x10) = 0x676e8d;
        _mbtowc(*(wchar_t **)(puVar21 + -0xc),*(char **)(puVar21 + -8),*(size_t *)(puVar21 + -4));
        *(undefined2 *)pbVar19 = *(undefined2 *)(unaff_EBP + -0x1d8);
        pbVar19 = pbVar19 + 2;
      }
      *(byte **)(unaff_EBP + -100) = pbVar19;
    }
    else {
      pbVar26 = pbVar26 + 1;
    }
  } while( true );
  *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
  if (uVar13 != 0xffffffff) {
    *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
    *(uint *)(puVar21 + -8) = uVar13;
    *(undefined4 *)(puVar21 + -0xc) = 0x676f69;
    FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
  }
LAB_00676f6b:
  if (pbVar26 == pbVar19) goto LAB_00677266;
  if ((*(char *)(unaff_EBP + -0x4b) == '\0') &&
     (*(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1,
     *(int *)(unaff_EBP + -0x68) != 99)) {
    if (*(char *)(unaff_EBP + -0x4d) == '\0') {
      *(undefined1 *)*(undefined2 **)(unaff_EBP + -100) = 0;
    }
    else {
      **(undefined2 **)(unaff_EBP + -100) = 0;
    }
  }
LAB_006771da:
  *(char *)(unaff_EBP + -0x29) = *(char *)(unaff_EBP + -0x29) + '\x01';
  *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
  while( true ) {
    if ((*(int *)(unaff_EBP + -0x28) == -1) &&
       ((**(char **)(unaff_EBP + 0xc) != '%' || ((*(char **)(unaff_EBP + 0xc))[1] != 'n'))))
    goto LAB_00677266;
    while( true ) {
      if (**(byte **)(unaff_EBP + 0xc) == 0) goto LAB_00677266;
      *(uint *)(puVar21 + -4) = (uint)**(byte **)(unaff_EBP + 0xc);
      *(undefined4 *)(puVar21 + -8) = 0x67683d;
      iVar14 = _isspace(*(int *)(puVar21 + -4));
      if (iVar14 == 0) break;
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      do {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676850;
        iVar14 = __inc();
        *(int *)(puVar21 + -4) = iVar14;
        *(undefined4 *)(puVar21 + -8) = 0x676858;
        iVar9 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar9 != 0);
      if (iVar14 != -1) {
        *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
        *(int *)(puVar21 + -8) = iVar14;
        *(undefined4 *)(puVar21 + -0xc) = 0x67686b;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      do {
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
        *(uint *)(puVar21 + -4) = (uint)**(byte **)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar21 + -8) = 0x67687c;
        iVar14 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar14 != 0);
    }
    pbVar26 = *(byte **)(unaff_EBP + 0xc);
    if (*pbVar26 == 0x25) break;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    *(undefined4 *)(puVar21 + -4) = 0x6771ed;
    uVar17 = __inc();
    *(uint *)(unaff_EBP + -0x28) = uVar17;
    bVar16 = *pbVar26;
    *(byte **)(unaff_EBP + 0xc) = pbVar26 + 1;
    if (bVar16 != uVar17) goto LAB_00677236;
    if ((PTR_DAT_006ec130[(uVar17 & 0xff) * 2 + 1] & 0x80) != 0) {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x677218;
      uVar13 = __inc();
      bVar16 = pbVar26[1];
      *(byte **)(unaff_EBP + 0xc) = pbVar26 + 2;
      if (bVar16 != uVar13) {
        if (uVar13 != 0xffffffff) {
          *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
          *(uint *)(puVar21 + -8) = uVar13;
          *(undefined4 *)(puVar21 + -0xc) = 0x677231;
          FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
        }
        goto LAB_00677236;
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
    }
  }
  iVar14 = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined1 *)(unaff_EBP + -0x39) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined1 *)(unaff_EBP + -0x49) = 0;
  *(undefined1 *)(unaff_EBP + -0x4a) = 0;
  *(undefined1 *)(unaff_EBP + -0x4b) = 0;
  *(undefined1 *)(unaff_EBP + -0x4c) = 0;
  *(undefined1 *)(unaff_EBP + -0x4d) = 0;
  *(undefined1 *)(unaff_EBP + -0x4e) = 0;
  *(undefined1 *)(unaff_EBP + -0x4f) = 1;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  do {
    pbVar19 = pbVar26 + 1;
    uVar17 = (uint)*pbVar19;
    *(uint *)(puVar21 + -4) = uVar17;
    *(undefined4 *)(puVar21 + -8) = 0x6768cd;
    iVar9 = _isdigit(*(int *)(puVar21 + -4));
    pbVar23 = pbVar19;
    if (iVar9 == 0) {
      if (uVar17 < 0x4f) {
        if (uVar17 != 0x4e) {
          if (uVar17 == 0x2a) {
            *(char *)(unaff_EBP + -0x4b) = *(char *)(unaff_EBP + -0x4b) + '\x01';
          }
          else if (uVar17 != 0x46) {
            if (uVar17 == 0x49) {
              bVar16 = pbVar26[2];
              if ((bVar16 == 0x36) && (pbVar26[3] == 0x34)) {
                *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x54) + 1;
                *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                *(undefined4 *)(unaff_EBP + -0x58) = 0;
                pbVar23 = pbVar26 + 3;
              }
              else if (((bVar16 != 0x33) || (pbVar23 = pbVar26 + 3, *pbVar23 != 0x32)) &&
                      ((((pbVar23 = pbVar19, bVar16 != 100 && (bVar16 != 0x69)) && (bVar16 != 0x6f))
                       && ((bVar16 != 0x78 && (bVar16 != 0x58)))))) goto LAB_00676968;
            }
            else if (uVar17 == 0x4c) {
              *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + '\x01';
            }
            else {
LAB_00676968:
              *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
              pbVar23 = pbVar19;
            }
          }
        }
      }
      else if (uVar17 == 0x68) {
        *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + -1;
        *(char *)(unaff_EBP + -0x4e) = *(char *)(unaff_EBP + -0x4e) + -1;
      }
      else {
        if (uVar17 == 0x6c) {
          *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + '\x01';
        }
        else if (uVar17 != 0x77) goto LAB_00676968;
        *(char *)(unaff_EBP + -0x4e) = *(char *)(unaff_EBP + -0x4e) + '\x01';
      }
    }
    else {
      *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + 1;
      iVar14 = (uVar17 - 0x30) + iVar14 * 10;
    }
    pbVar26 = pbVar23;
  } while (*(char *)(unaff_EBP + -0x4c) == '\0');
  *(int *)(unaff_EBP + -0x48) = iVar14;
  *(byte **)(unaff_EBP + 0xc) = pbVar23;
  if (*(char *)(unaff_EBP + -0x4b) == '\0') {
    puVar5 = *(undefined4 **)(unaff_EBP + 0x10);
    *(undefined4 **)(unaff_EBP + -0x60) = puVar5;
    *(undefined4 **)(unaff_EBP + 0x10) = puVar5 + 1;
    pbVar19 = (byte *)*puVar5;
    *(byte **)(unaff_EBP + -100) = pbVar19;
  }
  else {
    pbVar19 = *(byte **)(unaff_EBP + -100);
  }
  *(undefined1 *)(unaff_EBP + -0x4c) = 0;
  if (*(char *)(unaff_EBP + -0x4e) == '\0') {
    if ((*pbVar23 == 0x53) || (*pbVar23 == 0x43)) {
      *(undefined1 *)(unaff_EBP + -0x4e) = 1;
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x4e) = 0xff;
    }
  }
  uVar17 = *pbVar23 | 0x20;
  *(uint *)(unaff_EBP + -0x68) = uVar17;
  if (uVar17 == 0x6e) {
LAB_006769fd:
    uVar10 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    if ((uVar17 != 99) && (uVar17 != 0x7b)) {
      do {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x6769ed;
        uVar10 = __inc();
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(undefined4 *)(puVar21 + -8) = 0x6769f5;
        iVar14 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar14 != 0);
      *(undefined4 *)(unaff_EBP + -0x28) = uVar10;
      goto LAB_006769fd;
    }
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    uVar10 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(puVar21 + -4) = 0x676a6a;
    uVar11 = __inc();
    *(undefined4 *)(unaff_EBP + -0x28) = uVar11;
  }
  iVar14 = *(int *)(unaff_EBP + -0x44);
  if ((iVar14 != 0) && (*(int *)(unaff_EBP + -0x48) == 0)) {
LAB_00676c66:
    uVar17 = *(uint *)(unaff_EBP + -0x28);
LAB_00677236:
    if (uVar17 != 0xffffffff) {
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
      *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -0x28);
      *(undefined4 *)(puVar21 + -0xc) = 0x677243;
      FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
    }
    goto LAB_00677266;
  }
  if (0x6f < uVar17) {
    if (uVar17 == 0x70) {
      *(undefined1 *)(unaff_EBP + -0x4f) = 1;
      goto LAB_00676fa8;
    }
    if (uVar17 == 0x73) goto LAB_00676c22;
    if (uVar17 == 0x75) goto LAB_00676fa8;
    if (uVar17 != 0x78) {
      if (uVar17 != 0x7b) goto LAB_00676c5b;
      if ('\0' < *(char *)(unaff_EBP + -0x4e)) {
        *(undefined1 *)(unaff_EBP + -0x4d) = 1;
      }
      iVar14 = *(int *)(unaff_EBP + 0xc);
      pbVar26 = (byte *)(iVar14 + 1);
      *(byte **)(unaff_EBP + 0xc) = pbVar26;
      *(byte **)(unaff_EBP + -0x1cc) = pbVar26;
      if (*pbVar26 == 0x5e) {
        pbVar26 = (byte *)(iVar14 + 2);
        *(byte **)(unaff_EBP + -0x1cc) = pbVar26;
        *(undefined1 *)(unaff_EBP + -0x49) = 0xff;
      }
      puVar18 = *(undefined1 **)(unaff_EBP + -0x20);
      puVar22 = puVar21;
      if (puVar18 == (undefined1 *)0x0) {
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(puVar21 + -4) = 0x20;
        iVar14 = *(int *)(puVar21 + -4);
        *(undefined4 *)(puVar21 + -4) = 0x676cc0;
        iVar14 = -iVar14;
        puVar22 = puVar21 + iVar14;
        puVar18 = puVar21 + iVar14;
        *(int *)(unaff_EBP + -0x18) = (int)puVar21 + iVar14;
        *(int *)(unaff_EBP + -0x20) = (int)puVar21 + iVar14;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      goto LAB_00676d06;
    }
LAB_00676a72:
    uVar13 = *(uint *)(unaff_EBP + -0x28);
    if (uVar13 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x4a) = 1;
LAB_00676ea6:
      piVar1 = (int *)(unaff_EBP + -0x48);
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar14 != 0)) {
        *(undefined1 *)(unaff_EBP + -0x4c) = 1;
      }
      else {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676ebf;
        uVar13 = __inc();
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
    }
    else if (uVar13 == 0x2b) goto LAB_00676ea6;
    if (uVar13 == 0x30) {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x676ed7;
      uVar13 = __inc();
      *(uint *)(unaff_EBP + -0x28) = uVar13;
      if (((char)uVar13 == 'x') || ((char)uVar13 == 'X')) {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676f2b;
        uVar13 = __inc();
        *(uint *)(unaff_EBP + -0x28) = uVar13;
        if ((*(int *)(unaff_EBP + -0x44) != 0) &&
           (*(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -2,
           *(int *)(unaff_EBP + -0x48) < 1)) {
          *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
        }
        *(undefined4 *)(puVar21 + -4) = 0x78;
LAB_00676f02:
        uVar17 = *(uint *)(puVar21 + -4);
        goto LAB_00676fd9;
      }
      *(undefined4 *)(unaff_EBP + -0x40) = 1;
      if (uVar17 != 0x78) {
        if (*(int *)(unaff_EBP + -0x44) != 0) {
          piVar1 = (int *)(unaff_EBP + -0x48);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
        }
        *(undefined4 *)(puVar21 + -4) = 0x6f;
        goto LAB_00676f02;
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      if (uVar13 != 0xffffffff) {
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(uint *)(puVar21 + -8) = uVar13;
        *(undefined4 *)(puVar21 + -0xc) = 0x676f17;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      *(undefined4 *)(puVar21 + -4) = 0x30;
      uVar13 = *(uint *)(puVar21 + -4);
      goto LAB_00676fd6;
    }
LAB_00676fd9:
    if (*(int *)(unaff_EBP + -0x54) == 0) {
      if (*(char *)(unaff_EBP + -0x4c) == '\0') {
        do {
          if ((uVar17 == 0x78) || (uVar17 == 0x70)) {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x677120;
            iVar14 = _isxdigit(*(int *)(puVar21 + -4));
            if (iVar14 != 0) {
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) << 4;
              *(uint *)(puVar21 + -4) = uVar13;
              *(undefined4 *)(puVar21 + -8) = 0x67712f;
              iVar14 = _isdigit(*(int *)(puVar21 + -4));
              if (iVar14 == 0) {
                uVar13 = (uVar13 & 0xffffffdf) - 7;
              }
              goto LAB_0067713f;
            }
LAB_0067713c:
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
          else {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x6770f8;
            iVar14 = _isdigit(*(int *)(puVar21 + -4));
            if (iVar14 == 0) goto LAB_0067713c;
            if (uVar17 == 0x6f) {
              if (0x37 < (int)uVar13) goto LAB_0067713c;
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) << 3;
            }
            else {
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) * 10;
            }
          }
LAB_0067713f:
          if (*(char *)(unaff_EBP + -0x4c) == '\0') {
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
            *(uint *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + -0x30 + uVar13;
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x48);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x4c) = 1;
                goto LAB_00677182;
              }
            }
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(undefined4 *)(puVar21 + -4) = 0x67716d;
            uVar13 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
            if (uVar13 != 0xffffffff) {
              *(undefined4 *)(puVar21 + -4) = uVar10;
              *(uint *)(puVar21 + -8) = uVar13;
              *(undefined4 *)(puVar21 + -0xc) = 0x677180;
              FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
            }
          }
LAB_00677182:
        } while (*(char *)(unaff_EBP + -0x4c) == '\0');
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
      if (*(char *)(unaff_EBP + -0x4a) != '\0') {
        *(int *)(unaff_EBP + -0x38) = -*(int *)(unaff_EBP + -0x38);
      }
    }
    else {
      if (*(char *)(unaff_EBP + -0x4c) == '\0') {
        do {
          if ((uVar17 == 0x78) || (uVar17 == 0x70)) {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x67703e;
            iVar14 = _isxdigit(*(int *)(puVar21 + -4));
            if (iVar14 != 0) {
              uVar6 = *(uint *)(unaff_EBP + -0x5c);
              *(uint *)(unaff_EBP + -0x5c) = uVar6 << 4;
              *(uint *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) << 4 | uVar6 >> 0x1c;
              *(uint *)(puVar21 + -4) = uVar13;
              *(undefined4 *)(puVar21 + -8) = 0x67705c;
              iVar14 = _isdigit(*(int *)(puVar21 + -4));
              if (iVar14 == 0) {
                uVar13 = (uVar13 & 0xffffffdf) - 7;
              }
              goto LAB_0067706c;
            }
LAB_00677069:
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
          else {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x676ffd;
            iVar14 = _isdigit(*(int *)(puVar21 + -4));
            if (iVar14 == 0) goto LAB_00677069;
            if (uVar17 == 0x6f) {
              if (0x37 < (int)uVar13) goto LAB_00677069;
              uVar6 = *(uint *)(unaff_EBP + -0x5c);
              *(uint *)(unaff_EBP + -0x5c) = uVar6 << 3;
              *(uint *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) << 3 | uVar6 >> 0x1d;
            }
            else {
              *(undefined4 *)(puVar21 + -4) = 0;
              *(undefined4 *)(puVar21 + -8) = 10;
              *(undefined4 *)(puVar21 + -0xc) = *(undefined4 *)(unaff_EBP + -0x58);
              *(undefined4 *)(puVar21 + -0x10) = *(undefined4 *)(unaff_EBP + -0x5c);
              *(undefined4 *)(puVar21 + -0x14) = 0x677030;
              uVar27 = __allmul();
              *(undefined8 *)(unaff_EBP + -0x5c) = uVar27;
            }
          }
LAB_0067706c:
          if (*(char *)(unaff_EBP + -0x4c) == '\0') {
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
            uVar6 = uVar13 - 0x30;
            puVar2 = (uint *)(unaff_EBP + -0x5c);
            uVar3 = *puVar2;
            *puVar2 = *puVar2 + uVar6;
            *(int *)(unaff_EBP + -0x58) =
                 *(int *)(unaff_EBP + -0x58) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar3,uVar6);
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x48);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x4c) = 1;
                goto LAB_006770af;
              }
            }
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(undefined4 *)(puVar21 + -4) = 0x67709a;
            uVar13 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
            if (uVar13 != 0xffffffff) {
              *(undefined4 *)(puVar21 + -4) = uVar10;
              *(uint *)(puVar21 + -8) = uVar13;
              *(undefined4 *)(puVar21 + -0xc) = 0x6770ad;
              FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
            }
          }
LAB_006770af:
        } while (*(char *)(unaff_EBP + -0x4c) == '\0');
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
      if (*(char *)(unaff_EBP + -0x4a) != '\0') {
        iVar14 = *(int *)(unaff_EBP + -0x5c);
        *(int *)(unaff_EBP + -0x5c) = -iVar14;
        *(uint *)(unaff_EBP + -0x58) = -(*(int *)(unaff_EBP + -0x58) + (uint)(iVar14 != 0));
      }
    }
    if (uVar17 == 0x46) {
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
    }
    if (*(int *)(unaff_EBP + -0x40) == 0) goto LAB_00677266;
    if (*(char *)(unaff_EBP + -0x4b) == '\0') {
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1;
      pbVar19 = *(byte **)(unaff_EBP + -100);
      uVar10 = *(undefined4 *)(unaff_EBP + -0x38);
LAB_006771ba:
      if (*(int *)(unaff_EBP + -0x54) == 0) {
        if (*(char *)(unaff_EBP + -0x4f) == '\0') {
          *(short *)pbVar19 = (short)uVar10;
        }
        else {
          *(undefined4 *)pbVar19 = uVar10;
        }
      }
      else {
        *(undefined4 *)pbVar19 = *(undefined4 *)(unaff_EBP + -0x5c);
        *(undefined4 *)(pbVar19 + 4) = *(undefined4 *)(unaff_EBP + -0x58);
      }
    }
    goto LAB_006771da;
  }
  if (uVar17 == 0x6f) {
LAB_00676fa8:
    uVar13 = *(uint *)(unaff_EBP + -0x28);
    if (uVar13 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x4a) = 1;
    }
    else if (uVar13 != 0x2b) goto LAB_00676fd9;
    piVar1 = (int *)(unaff_EBP + -0x48);
    *piVar1 = *piVar1 + -1;
    if ((*piVar1 == 0) && (iVar14 != 0)) {
      *(undefined1 *)(unaff_EBP + -0x4c) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x676fd4;
      uVar13 = __inc();
LAB_00676fd6:
      *(uint *)(unaff_EBP + -0x28) = uVar13;
    }
    goto LAB_00676fd9;
  }
  if (uVar17 != 99) {
    if (uVar17 == 100) goto LAB_00676fa8;
    if (uVar17 < 0x65) {
LAB_00676c5b:
      if ((uint)**(byte **)(unaff_EBP + 0xc) != *(uint *)(unaff_EBP + -0x28)) goto LAB_00676c66;
      *(char *)(unaff_EBP + -0x29) = *(char *)(unaff_EBP + -0x29) + -1;
      if (*(char *)(unaff_EBP + -0x4b) == '\0') {
        *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(unaff_EBP + -0x60);
      }
    }
    else if (uVar17 < 0x68) {
      pcVar24 = (char *)(unaff_EBP + -0x1c8);
      iVar14 = *(int *)(unaff_EBP + -0x28);
      if (iVar14 == 0x2d) {
        *(undefined1 *)(unaff_EBP + -0x1c8) = 0x2d;
        pcVar24 = (char *)(unaff_EBP + -0x1c7);
LAB_00676aa8:
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        uVar10 = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(puVar21 + -4) = 0x676ab8;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
      }
      else {
        if (iVar14 == 0x2b) goto LAB_00676aa8;
        uVar10 = *(undefined4 *)(unaff_EBP + 8);
      }
      if ((*(int *)(unaff_EBP + -0x44) == 0) || (0x15d < *(int *)(unaff_EBP + -0x48))) {
        *(undefined4 *)(unaff_EBP + -0x48) = 0x15d;
      }
      while( true ) {
        *(int *)(puVar21 + -4) = iVar14;
        *(undefined4 *)(puVar21 + -8) = 0x676aff;
        iVar9 = _isdigit(*(int *)(puVar21 + -4));
        if ((iVar9 == 0) ||
           (iVar9 = *(int *)(unaff_EBP + -0x48),
           *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
        *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
        *pcVar24 = (char)iVar14;
        pcVar24 = pcVar24 + 1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676af4;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
      }
      if ((DAT_006ec184 == (char)iVar14) &&
         (iVar9 = *(int *)(unaff_EBP + -0x48),
         *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 != 0)) {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676b20;
        iVar14 = __inc();
        *pcVar24 = DAT_006ec184;
        while( true ) {
          pcVar24 = pcVar24 + 1;
          *(int *)(puVar21 + -4) = iVar14;
          *(int *)(unaff_EBP + -0x28) = iVar14;
          *(undefined4 *)(puVar21 + -8) = 0x676b51;
          iVar9 = _isdigit(*(int *)(puVar21 + -4));
          if ((iVar9 == 0) ||
             (iVar9 = *(int *)(unaff_EBP + -0x48),
             *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
          *pcVar24 = (char)iVar14;
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676b46;
          iVar14 = __inc();
        }
      }
      pcVar25 = pcVar24;
      if ((*(int *)(unaff_EBP + -0x40) != 0) &&
         (((iVar14 == 0x65 || (iVar14 == 0x45)) &&
          (iVar9 = *(int *)(unaff_EBP + -0x48),
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 != 0)))) {
        *pcVar24 = 'e';
        pcVar25 = pcVar24 + 1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676b7e;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
        if (iVar14 == 0x2d) {
          *pcVar25 = '-';
          pcVar25 = pcVar24 + 2;
LAB_00676b92:
          iVar9 = *(int *)(unaff_EBP + -0x48);
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1;
          if (iVar9 != 0) goto LAB_00676bb1;
          *(undefined4 *)(unaff_EBP + -0x48) = 0;
        }
        else if (iVar14 == 0x2b) goto LAB_00676b92;
        while( true ) {
          *(int *)(puVar21 + -4) = iVar14;
          *(undefined4 *)(puVar21 + -8) = 0x676bc6;
          iVar9 = _isdigit(*(int *)(puVar21 + -4));
          if ((iVar9 == 0) ||
             (iVar9 = *(int *)(unaff_EBP + -0x48),
             *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
          *pcVar25 = (char)iVar14;
          pcVar25 = pcVar25 + 1;
LAB_00676bb1:
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676bbb;
          iVar14 = __inc();
          *(int *)(unaff_EBP + -0x28) = iVar14;
        }
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      if (iVar14 != -1) {
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(int *)(puVar21 + -8) = iVar14;
        *(undefined4 *)(puVar21 + -0xc) = 0x676bda;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      if (*(int *)(unaff_EBP + -0x40) == 0) goto LAB_00677266;
      if (*(char *)(unaff_EBP + -0x4b) == '\0') {
        *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1;
        *pcVar25 = '\0';
        *(int *)(puVar21 + -4) = unaff_EBP + -0x1c8;
        *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -100);
        *(int *)(puVar21 + -0xc) = *(char *)(unaff_EBP + -0x4f) + -1;
        puVar7 = PTR_FUN_006ebcb8;
        puVar20 = puVar21 + -0x10;
        *(undefined4 *)(puVar21 + -0x10) = 0x676c0c;
        (*(code *)puVar7)();
        puVar21 = puVar20 + 0xc;
      }
    }
    else {
      if (uVar17 == 0x69) {
        *(undefined4 *)(puVar21 + -4) = 100;
        uVar17 = *(uint *)(puVar21 + -4);
        goto LAB_00676a72;
      }
      if (uVar17 != 0x6e) goto LAB_00676c5b;
      uVar10 = *(undefined4 *)(unaff_EBP + -0x30);
      if (*(char *)(unaff_EBP + -0x4b) == '\0') goto LAB_006771ba;
    }
    goto LAB_006771da;
  }
  if (iVar14 == 0) {
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + 1;
  }
LAB_00676c22:
  if ('\0' < *(char *)(unaff_EBP + -0x4e)) {
    *(undefined1 *)(unaff_EBP + -0x4d) = 1;
  }
  goto LAB_00676dad;
}


// 006783cd FUN_006783cd

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_006783cd(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x6783d5;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x1c);
  iVar1 = *(int *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x2c) == 0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x6783f2;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x2c) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar4 = 0;
      goto LAB_00678686;
    }
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(undefined4 *)(iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar5 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x67841a;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar9 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    *(int *)(puVar5 + -0xc) = iVar1;
    *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    puVar6 = puVar5 + -0x1c;
    *(undefined4 *)(puVar5 + -0x1c) = 0x678434;
    iVar4 = LCMapStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                         *(LPCWSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                         *(LPWSTR *)(puVar5 + -8),*(int *)(puVar5 + -4));
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    puVar9 = puVar6;
    if (iVar4 != 0) {
      if ((*(byte *)(unaff_EBP + 0xd) & 4) == 0) {
        *(undefined4 *)(unaff_EBP + -4) = 2;
        *(undefined4 *)(puVar6 + -4) = 0x678489;
        iVar3 = -(iVar4 * 2 + 3U & 0xfffffffc);
        *(int *)(unaff_EBP + -0x18) = (int)puVar6 + iVar3;
        *(int *)(unaff_EBP + -0x30) = (int)puVar6 + iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + -0x30) == 0) {
          *(int *)(puVar6 + iVar3 + -4) = iVar4 * 2;
          *(undefined4 *)(puVar6 + iVar3 + -8) = 0x6784c0;
          pvVar2 = _malloc(*(size_t *)(puVar6 + iVar3 + -4));
          *(void **)(unaff_EBP + -0x30) = pvVar2;
          puVar9 = puVar6 + iVar3;
          if (pvVar2 == (void *)0x0) goto LAB_00678508;
          *(undefined4 *)(unaff_EBP + -0x24) = 1;
        }
        *(int *)(puVar6 + iVar3 + -4) = iVar4;
        *(undefined4 *)(puVar6 + iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x30);
        *(int *)(puVar6 + iVar3 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(undefined4 *)(puVar6 + iVar3 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar8 = puVar6 + iVar3 + -0x1c;
        *(undefined4 *)(puVar6 + iVar3 + -0x1c) = 0x6784e3;
        iVar3 = LCMapStringW(*(LCID *)(puVar6 + iVar3 + -0x18),*(DWORD *)(puVar6 + iVar3 + -0x14),
                             *(LPCWSTR *)(puVar6 + iVar3 + -0x10),*(int *)(puVar6 + iVar3 + -0xc),
                             *(LPWSTR *)(puVar6 + iVar3 + -8),*(int *)(puVar6 + iVar3 + -4));
        puVar9 = puVar8;
        if (iVar3 != 0) {
          *(undefined4 *)(puVar8 + -4) = 0;
          *(undefined4 *)(puVar8 + -8) = 0;
          if (*(int *)(unaff_EBP + 0x1c) == 0) {
            *(undefined4 *)(puVar8 + -0xc) = 0;
            *(undefined4 *)(puVar8 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
            *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
          }
          *(int *)(puVar8 + -0x14) = iVar4;
          *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + -0x30);
          *(undefined4 *)(puVar8 + -0x1c) = 0;
          *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
          puVar9 = puVar8 + -0x24;
          *(undefined4 *)(puVar8 + -0x24) = 0x678506;
          iVar4 = WideCharToMultiByte(*(UINT *)(puVar8 + -0x20),*(DWORD *)(puVar8 + -0x1c),
                                      *(LPCWSTR *)(puVar8 + -0x18),*(int *)(puVar8 + -0x14),
                                      *(LPSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                      *(LPCSTR *)(puVar8 + -8),*(LPBOOL *)(puVar8 + -4));
        }
      }
      else if ((*(int *)(unaff_EBP + 0x1c) != 0) && (iVar4 <= *(int *)(unaff_EBP + 0x1c))) {
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + 0x1c);
        *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + 0x18);
        *(int *)(puVar6 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar7 = puVar6 + -0x1c;
        *(undefined4 *)(puVar6 + -0x1c) = 0x67846f;
        LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                     *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8),
                     *(int *)(puVar6 + -4));
        puVar9 = puVar7;
      }
    }
  }
LAB_00678508:
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar9 + -8) = 0x678515;
    _free(*(void **)(puVar9 + -4));
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar9 + -8) = 0x678523;
    _free(*(void **)(puVar9 + -4));
  }
LAB_00678686:
  *(undefined4 *)(unaff_EBP + -0x58) = 0x67868e;
  return iVar4;
}


// 0067849b FUN_0067849b

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_0067849b(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x6784a3;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x1c);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x30) == 0) {
    *(int *)(puVar6 + -4) = iVar4 * 2;
    *(undefined4 *)(puVar6 + -8) = 0x6784c0;
    pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
    *(void **)(unaff_EBP + -0x30) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_00678508;
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
  }
  *(int *)(puVar6 + -4) = iVar4;
  *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + -0x30);
  *(undefined4 *)(puVar6 + -0xc) = uVar1;
  *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = puVar6 + -0x1c;
  *(undefined4 *)(puVar6 + -0x1c) = 0x6784e3;
  iVar3 = LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                       *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8)
                       ,*(int *)(puVar6 + -4));
  puVar6 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    if (*(int *)(unaff_EBP + 0x1c) == 0) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
      *(undefined4 *)(puVar5 + -0x10) = 0;
    }
    else {
      *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    }
    *(int *)(puVar5 + -0x14) = iVar4;
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar5 + -0x1c) = 0;
    *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar6 = puVar5 + -0x24;
    *(undefined4 *)(puVar5 + -0x24) = 0x678506;
    iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
  }
LAB_00678508:
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar6 + -8) = 0x678515;
    _free(*(void **)(puVar6 + -4));
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar6 + -8) = 0x678523;
    _free(*(void **)(puVar6 + -4));
  }
  *(undefined4 *)(unaff_EBP + -0x58) = 0x67868e;
  return iVar4;
}


// 0067950d FUN_0067950d

void FUN_0067950d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0067fc40();
  return;
}


// 0067953a FUN_0067953a

void FUN_0067953a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  terminate();
  return;
}


// 00679fb1 FUN_00679fb1

void FUN_00679fb1(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; (*param_1 != '\0' && (*param_1 != DAT_006ec184)); param_1 = param_1 + 1) {
  }
  if (*param_1 != '\0') {
    do {
      param_1 = param_1 + 1;
      cVar1 = *param_1;
      pcVar2 = param_1;
      if ((cVar1 == '\0') || (cVar1 == 'e')) break;
    } while (cVar1 != 'E');
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + -1;
    } while (*pcVar2 == '0');
    if (*pcVar2 == DAT_006ec184) {
      pcVar2 = pcVar3 + -2;
    }
    do {
      cVar1 = *param_1;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// 00679ffc FUN_00679ffc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00679ffc(double *param_1)

{
  if (_DAT_006ccaf8 <= *param_1) {
    return 1;
  }
  return 0;
}


// 0067a512 FUN_0067a512

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0067a512(void)

{
  int unaff_EBP;
  unkbyte10 in_ST0;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
    return *(float10 *)(unaff_EBP + -0x9e);
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
  return *(float10 *)(unaff_EBP + -0x9e) + (float10)_DAT_006ebce4;
}


// 0067a53f FUN_0067a53f

float10 FUN_0067a53f(void)

{
  int unaff_EBP;
  unkbyte10 in_ST0;
  float10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) == 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
  }
  return *(float10 *)(unaff_EBP + -0x9e) + in_ST1;
}


// 0067a567 FUN_0067a567

float10 FUN_0067a567(void)

{
  float10 fVar1;
  int unaff_EBP;
  unkbyte10 in_ST0;
  float10 fVar2;
  float10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  fVar1 = *(float10 *)(unaff_EBP + -0x9e);
  fVar2 = fVar1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(float10 *)(unaff_EBP + -0x9e) = in_ST1;
    fVar2 = *(float10 *)(unaff_EBP + -0x9e);
    in_ST1 = fVar1;
    if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
      *(undefined1 *)(unaff_EBP + -0x90) = 7;
      goto LAB_0067a5a3;
    }
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
LAB_0067a5a3:
  return fVar2 + in_ST1;
}


// 0067a5a6 FUN_0067a5a6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

unkbyte10 FUN_0067a5a6(void)

{
  int unaff_EBP;
  unkbyte10 Var1;
  
  Var1 = _DAT_006ebcd0;
  if (*(char *)(unaff_EBP + -0x90) < '\x01') {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  return Var1;
}


// 0067b0ad FUN_0067b0ad

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */

undefined4 FUN_0067b0ad(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  _ptiddata p_Var2;
  
  if (*(int *)*in_EAX != -0x1f928c9d) {
    return 0;
  }
  p_Var2 = __getptd();
  p_Var2->_translator = (void *)0x0;
  p_Var2 = __getptd();
  if (p_Var2->ptlocinfo != (pthreadlocinfo)0x0) {
    p_Var2 = __getptd();
    (*(code *)p_Var2->ptlocinfo)();
  }
  uVar1 = FUN_0067fc40();
  return uVar1;
}


// 0067b13e FUN_0067b13e

void FUN_0067b13e(void)

{
  FUN_0067b0ad();
  return;
}


// 0067b147 FUN_0067b147

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067b147(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBP;
  int iVar6;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 0x10);
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar6 = *(int *)(unaff_EBP + -0x20);
  while (*(int *)(unaff_EBP + -0x1c) = iVar6, iVar6 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar6 < 0) || (*(int *)(iVar2 + 4) <= iVar6)) {
      *(undefined4 *)(iVar1 + -4) = 0x67b107;
      _inconsistency();
    }
    iVar4 = iVar6 * 8;
    piVar5 = (int *)(*(int *)(iVar2 + 8) + iVar4);
    iVar6 = *piVar5;
    *(int *)(unaff_EBP + -0x20) = iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (piVar5[1] != 0) {
      *(int *)(iVar3 + 8) = iVar6;
      *(undefined4 *)(iVar1 + -4) = 0x103;
      *(int *)(iVar1 + -8) = iVar3;
      *(undefined4 *)(iVar1 + -0xc) = *(undefined4 *)(*(int *)(iVar2 + 8) + 4 + iVar4);
      *(undefined4 *)(iVar1 + -0x10) = 0x67b138;
      __CallSettingFrame_12();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 0x67b165;
  FUN_0067b17e();
  if (iVar6 != *(int *)(unaff_EBP + 0x14)) {
    *(undefined4 *)(iVar1 + -4) = 0x67b16f;
    _inconsistency();
  }
  *(int *)(iVar3 + 8) = iVar6;
  *(undefined4 *)(iVar1 + -4) = 0x67b177;
  return;
}


// 0067b1cd FUN_0067b1cd

bool FUN_0067b1cd(void)

{
  int unaff_EBP;
  
  return *(char *)(unaff_EBP + 0xc) != '\0';
}


// 0067b2c3 FUN_0067b2c3

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0067b2c3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  iVar3 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar3 + 8);
  iVar4 = *(int *)(unaff_EBP + 0xc);
  iVar7 = *(int *)(iVar4 + 8);
  *(int *)(unaff_EBP + -0x48) = iVar7;
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar3 + 0x10);
  uVar8 = 0;
  do {
    *(uint *)(unaff_EBP + -0x50) = uVar8;
    if (*(uint *)(iVar3 + 0xc) <= uVar8) {
LAB_0067b30c:
      *(int *)(iVar2 + -4) = iVar7;
      *(int *)(iVar2 + -8) = iVar3;
      *(undefined4 *)(iVar2 + -0xc) = 0;
      *(int *)(iVar2 + -0x10) = iVar4;
      *(undefined4 *)(iVar2 + -0x14) = 0x67b317;
      ___FrameUnwindToState();
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(iVar2 + -4) = 0x67b32c;
      FUN_0067b33e();
      uVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
      *(undefined4 *)(iVar2 + -4) = 0x67b334;
      return uVar6;
    }
    iVar1 = *(int *)(unaff_EBP + -0x4c) + uVar8 * 0x14;
    iVar5 = *(int *)(iVar1 + 4);
    if ((iVar5 < iVar7) && (iVar7 <= *(int *)(iVar1 + 8))) {
      iVar5 = iVar5 + 1;
      *(int *)(unaff_EBP + -0x48) = iVar5;
      iVar7 = *(int *)(*(int *)(unaff_EBP + -0x44) + iVar5 * 8);
      *(int *)(unaff_EBP + -0x48) = iVar7;
      goto LAB_0067b30c;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}


// 0067b300 FUN_0067b300

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_0067b300(void)

{
  int in_EAX;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x48) = in_EAX;
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + in_EAX * 8);
  ___FrameUnwindToState();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0067b33e();
  return *(undefined4 *)(unaff_EBP + -0x1c);
}


// 0067e7bf FUN_0067e7bf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0067e7bf(void)

{
  undefined *_Memory;
  int iVar1;
  
  if (_DAT_00717e9c == 0) {
    PTR_PTR_006ec070 = (undefined *)&PTR_PTR_006ec078;
    DAT_00717e5c = (undefined *)0x0;
    return 0;
  }
  _Memory = _calloc(1,0xb8);
  if (_Memory != (undefined *)0x0) {
    iVar1 = __get_lc_time();
    if (iVar1 == 0) {
      PTR_PTR_006ec070 = _Memory;
      DAT_00717e5c = _Memory;
      return 0;
    }
    ___free_lc_time(_Memory);
    _free(_Memory);
  }
  return 1;
}


// 0067fb15 FUN_0067fb15

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0067fb15(void)

{
  void *pvVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar2 + -4) = 0x67fb1d;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(iVar2 + -4) = uVar4;
  *(undefined4 *)(iVar2 + -8) = 2;
  *(undefined4 *)(iVar2 + -0xc) = 0x67fb32;
  pvVar1 = _calloc(*(size_t *)(iVar2 + -8),*(size_t *)(iVar2 + -4));
  if (pvVar1 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(undefined4 *)(iVar2 + -4) = uVar4;
    *(void **)(iVar2 + -8) = pvVar1;
    *(undefined4 *)(iVar2 + -0xc) = *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar2 + -0x14) = 1;
    *(undefined4 *)(iVar2 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
    puVar5 = (undefined1 *)(iVar2 + -0x1c);
    *(undefined4 *)(iVar2 + -0x1c) = 0x67fb54;
    iVar2 = MultiByteToWideChar(*(UINT *)(iVar2 + -0x18),*(DWORD *)(iVar2 + -0x14),
                                *(LPCSTR *)(iVar2 + -0x10),*(int *)(iVar2 + -0xc),
                                *(LPWSTR *)(iVar2 + -8),*(int *)(iVar2 + -4));
    puVar6 = puVar5;
    if (iVar2 != 0) {
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
      *(int *)(puVar5 + -8) = iVar2;
      *(void **)(puVar5 + -0xc) = pvVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x14;
      *(undefined4 *)(puVar5 + -0x14) = 0x67fb66;
      BVar3 = GetStringTypeW(*(DWORD *)(puVar5 + -0x10),*(LPCWSTR *)(puVar5 + -0xc),
                             *(int *)(puVar5 + -8),*(LPWORD *)(puVar5 + -4));
      *(BOOL *)(unaff_EBP + -0x20) = BVar3;
    }
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      *(void **)(puVar6 + -4) = pvVar1;
      *(undefined4 *)(puVar6 + -8) = 0x67fb75;
      _free(*(void **)(puVar6 + -4));
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x67fbf1;
  return uVar4;
}


// 0068005e FUN_0068005e

void FUN_0068005e(void)

{
  LPCSTR unaff_ESI;
  
  _strcat();
  _strcat();
  _strcat();
  _strcat();
  ___crtMessageBoxA(unaff_ESI,"Microsoft Visual C++ Runtime Library",0x12010);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// 0068006b FUN_0068006b

void FUN_0068006b(void)

{
  LPCSTR unaff_ESI;
  
  _strcat();
  _strcat();
  ___crtMessageBoxA(unaff_ESI,"Microsoft Visual C++ Runtime Library",0x12010);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// 00680102 FUN_00680102

undefined4 FUN_00680102(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)**(undefined4 **)(unaff_EBP + -0x14);
  return 1;
}


// 00680fad FUN_00680fad

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

undefined4 FUN_00680fad(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x680fb5;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x40);
  pvVar2 = *(void **)(unaff_EBP + -0x44);
  if (pvVar2 == (void *)0x0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x680fd5;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x44) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      uVar7 = 0;
      goto LAB_00681174;
    }
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(void **)(iVar3 + -8) = pvVar2;
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar8 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x680ff6;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar11 = puVar8;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar8 + -4) = 0;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(puVar8 + -0x14) = 9;
    *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar9 = puVar8 + -0x1c;
    *(undefined4 *)(puVar8 + -0x1c) = 0x681013;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar8 + -0x18),*(DWORD *)(puVar8 + -0x14),
                                *(LPCSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                *(LPWSTR *)(puVar8 + -8),*(int *)(puVar8 + -4));
    *(int *)(unaff_EBP + -0x48) = iVar3;
    puVar11 = puVar9;
    if (iVar3 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 1;
      puVar4 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      *(undefined4 *)(puVar9 + -4) = 0x681035;
      iVar6 = -(int)puVar4;
      puVar5 = puVar9 + iVar6;
      puVar11 = puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x18) = (int)puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x4c) = (int)puVar9 + iVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (puVar9 == puVar4) {
        sRamfffffffc = iVar3 * 2;
        uRamfffffff8 = 0x681068;
        puVar5 = _malloc(sRamfffffffc);
        if (puVar5 == (undefined1 *)0x0) goto LAB_006810af;
        *(undefined4 *)(unaff_EBP + -0x24) = 1;
      }
      *(int *)(puVar9 + iVar6 + -4) = iVar3;
      *(undefined1 **)(puVar9 + iVar6 + -8) = puVar5;
      *(undefined4 *)(puVar9 + iVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar9 + iVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
      *(undefined4 *)(puVar9 + iVar6 + -0x14) = 1;
      *(undefined4 *)(puVar9 + iVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
      puVar10 = puVar9 + iVar6 + -0x1c;
      *(undefined4 *)(puVar9 + iVar6 + -0x1c) = 0x681089;
      iVar6 = MultiByteToWideChar(*(UINT *)(puVar9 + iVar6 + -0x18),
                                  *(DWORD *)(puVar9 + iVar6 + -0x14),
                                  *(LPCSTR *)(puVar9 + iVar6 + -0x10),
                                  *(int *)(puVar9 + iVar6 + -0xc),*(LPWSTR *)(puVar9 + iVar6 + -8),
                                  *(int *)(puVar9 + iVar6 + -4));
      puVar11 = puVar10;
      if (iVar6 != 0) {
        *(int *)(puVar10 + -4) = iVar3;
        *(undefined1 **)(puVar10 + -8) = puVar5;
        *(int *)(puVar10 + -0xc) = iVar1;
        *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(unaff_EBP + -0x44);
        *(undefined4 *)(puVar10 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar10 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar11 = puVar10 + -0x1c;
        *(undefined4 *)(puVar10 + -0x1c) = 0x68109f;
        iVar3 = CompareStringW(*(LCID *)(puVar10 + -0x18),*(DWORD *)(puVar10 + -0x14),
                               *(PCNZWCH *)(puVar10 + -0x10),*(int *)(puVar10 + -0xc),
                               *(PCNZWCH *)(puVar10 + -8),*(int *)(puVar10 + -4));
        *(int *)(unaff_EBP + -0x28) = iVar3;
      }
      if (*(int *)(unaff_EBP + -0x24) != 0) {
        *(undefined1 **)(puVar11 + -4) = puVar5;
        *(undefined4 *)(puVar11 + -8) = 0x6810ae;
        _free(*(void **)(puVar11 + -4));
      }
    }
  }
LAB_006810af:
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(unaff_EBP + -0x44);
    *(undefined4 *)(puVar11 + -8) = 0x6810bd;
    _free(*(void **)(puVar11 + -4));
  }
  uVar7 = *(undefined4 *)(unaff_EBP + -0x28);
LAB_00681174:
  *(undefined4 *)(unaff_EBP + -0x60) = 0x681182;
  *(undefined4 *)(unaff_EBP + -100) = 0x681187;
  return uVar7;
}


// 00681047 FUN_00681047

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00681047(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x68104f;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x40);
  iVar4 = *(int *)(unaff_EBP + -0x48);
  *(int *)(puVar6 + -4) = iVar4 * 2;
  *(undefined4 *)(puVar6 + -8) = 0x681068;
  pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(int *)(puVar6 + -4) = iVar4;
    *(void **)(puVar6 + -8) = pvVar2;
    *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(puVar6 + -0x14) = 1;
    *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar5 = puVar6 + -0x1c;
    *(undefined4 *)(puVar6 + -0x1c) = 0x681089;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                                *(LPCSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),
                                *(LPWSTR *)(puVar6 + -8),*(int *)(puVar6 + -4));
    puVar6 = puVar5;
    if (iVar3 != 0) {
      *(int *)(puVar5 + -4) = iVar4;
      *(void **)(puVar5 + -8) = pvVar2;
      *(undefined4 *)(puVar5 + -0xc) = uVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x44);
      *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x1c;
      *(undefined4 *)(puVar5 + -0x1c) = 0x68109f;
      iVar4 = CompareStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                             *(PCNZWCH *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                             *(PCNZWCH *)(puVar5 + -8),*(int *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x28) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      *(void **)(puVar6 + -4) = pvVar2;
      *(undefined4 *)(puVar6 + -8) = 0x6810ae;
      _free(*(void **)(puVar6 + -4));
    }
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x44);
    *(undefined4 *)(puVar6 + -8) = 0x6810bd;
    _free(*(void **)(puVar6 + -4));
  }
  *(undefined4 *)(unaff_EBP + -0x60) = 0x681182;
  *(undefined4 *)(unaff_EBP + -100) = 0x681187;
  return *(undefined4 *)(unaff_EBP + -0x28);
}


// 00681a85 FUN_00681a85

undefined4 FUN_00681a85(void)

{
  DAT_00717ef4 = SetUnhandledExceptionFilter(FUN_00681a3f);
  return 0;
}


// 00682a7a FUN_00682a7a

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00682a7a(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x682a82;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(iVar3 + -8) = 0x682a99;
  pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
    *(void **)(iVar3 + -8) = pvVar2;
    *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = (undefined1 *)(iVar3 + -0x14);
    *(undefined4 *)(iVar3 + -0x14) = 0x682ab3;
    iVar3 = GetLocaleInfoA(*(LCID *)(iVar3 + -0x10),*(LCTYPE *)(iVar3 + -0xc),*(LPSTR *)(iVar3 + -8)
                           ,*(int *)(iVar3 + -4));
    puVar5 = puVar4;
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar4 + -4) = 0;
        *(undefined4 *)(puVar4 + -8) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar4 + -0xc) = 0xffffffff;
      *(void **)(puVar4 + -0x10) = pvVar2;
      *(undefined4 *)(puVar4 + -0x14) = 1;
      *(undefined4 *)(puVar4 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar5 = puVar4 + -0x1c;
      *(undefined4 *)(puVar4 + -0x1c) = 0x682ad3;
      iVar3 = MultiByteToWideChar(*(UINT *)(puVar4 + -0x18),*(DWORD *)(puVar4 + -0x14),
                                  *(LPCSTR *)(puVar4 + -0x10),*(int *)(puVar4 + -0xc),
                                  *(LPWSTR *)(puVar4 + -8),*(int *)(puVar4 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar3;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(void **)(puVar5 + -4) = pvVar2;
      *(undefined4 *)(puVar5 + -8) = 0x682ae1;
      _free(*(void **)(puVar5 + -4));
    }
    uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x682aed;
  return uVar1;
}


// 00682ba1 FUN_00682ba1

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00682ba1(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar4 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar4 + -4) = 0x682ba9;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x24);
  *(int *)(iVar4 + -4) = iVar1 * 2;
  *(undefined4 *)(iVar4 + -8) = 0x682bc1;
  pvVar3 = _malloc(*(size_t *)(iVar4 + -4));
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(int *)(iVar4 + -4) = iVar1;
    *(void **)(iVar4 + -8) = pvVar3;
    *(undefined4 *)(iVar4 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar4 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar5 = (undefined1 *)(iVar4 + -0x14);
    *(undefined4 *)(iVar4 + -0x14) = 0x682bdd;
    iVar4 = GetLocaleInfoW(*(LCID *)(iVar4 + -0x10),*(LCTYPE *)(iVar4 + -0xc),
                           *(LPWSTR *)(iVar4 + -8),*(int *)(iVar4 + -4));
    puVar6 = puVar5;
    if (iVar4 != 0) {
      *(undefined4 *)(puVar5 + -4) = 0;
      *(undefined4 *)(puVar5 + -8) = 0;
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar5 + -0xc) = 0;
        *(undefined4 *)(puVar5 + -0x10) = 0;
      }
      else {
        *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar5 + -0x14) = 0xffffffff;
      *(void **)(puVar5 + -0x18) = pvVar3;
      *(undefined4 *)(puVar5 + -0x1c) = 0;
      *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar6 = puVar5 + -0x24;
      *(undefined4 *)(puVar5 + -0x24) = 0x682bff;
      iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                  *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                  *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                  *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(void **)(puVar6 + -4) = pvVar3;
      *(undefined4 *)(puVar6 + -8) = 0x682c0d;
      _free(*(void **)(puVar6 + -4));
    }
    uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x682c2d;
  return uVar2;
}


// 00684763 FUN_00684763

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Removing unreachable block (ram,0x00684796) */

undefined4 FUN_00684763(void)

{
  short *psVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  uint uVar6;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x68476b;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(iVar3 + -4) = *(int *)(unaff_EBP + -0x24) * 0x14;
  *(undefined4 *)(iVar3 + -8) = 0x684784;
  psVar1 = _malloc(*(size_t *)(iVar3 + -4));
  if (psVar1 == (short *)0x0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
    uVar4 = *(undefined4 *)(unaff_EBP + -0x24);
    *(int *)(iVar3 + -4) = unaff_EBP + -0x2c;
    *(undefined4 *)(iVar3 + -8) = uVar4;
    *(short **)(iVar3 + -0xc) = psVar1;
    *(undefined4 *)(iVar3 + -0x10) = DAT_006ee18c;
    puVar5 = (undefined1 *)(iVar3 + -0x14);
    *(undefined4 *)(iVar3 + -0x14) = 0x6847ab;
    BVar2 = PeekConsoleInputA(*(HANDLE *)(iVar3 + -0x10),*(PINPUT_RECORD *)(iVar3 + -0xc),
                              *(DWORD *)(iVar3 + -8),*(LPDWORD *)(iVar3 + -4));
    if (((BVar2 != 0) && (uVar6 = *(uint *)(unaff_EBP + -0x2c), uVar6 != 0)) &&
       (uVar6 <= *(uint *)(unaff_EBP + -0x24))) {
      while (uVar6 != 0) {
        if ((*psVar1 == 1) && (*(int *)(psVar1 + 2) != 0)) {
          if ((char)psVar1[7] == '\0') {
            *(short **)(puVar5 + -4) = psVar1 + 2;
            *(undefined4 *)(puVar5 + -8) = 0x6847d6;
            iVar3 = __getextendedkeycode();
            if (iVar3 == 0) goto LAB_006847de;
          }
          *(undefined4 *)(unaff_EBP + -0x20) = 1;
        }
LAB_006847de:
        uVar6 = uVar6 - 1;
        *(uint *)(unaff_EBP + -0x2c) = uVar6;
        psVar1 = psVar1 + 10;
      }
    }
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      *(short **)(puVar5 + -4) = psVar1;
      *(undefined4 *)(puVar5 + -8) = 0x6847f5;
      _free(*(void **)(puVar5 + -4));
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x684805;
  return uVar4;
}


// 0068487c FUN_0068487c

bool FUN_0068487c(void)

{
  int unaff_EBP;
  
  return *(int *)**(undefined4 **)(unaff_EBP + -0x14) == -0x3ffffffb;
}


// 006848a1 FUN_006848a1

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_006848a1(void)

{
  void *_File;
  int iVar1;
  int _Index;
  undefined4 uStack_20;
  
  uStack_20 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00794360; _Index = _Index + 1) {
    _File = *(void **)(DAT_00793350 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00793350 + _Index * 4);
      if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (*(int *)(iVar1 + 0x1c) != 0)) {
        __fclose_lk(iVar1);
        uStack_20 = uStack_20 + 1;
      }
      FUN_00684917();
    }
  }
  FUN_0068493a();
  return uStack_20;
}


// 00684962 FUN_00684962

void FUN_00684962(void)

{
  if ((DAT_006ee190 != (HANDLE)0xffffffff) && (DAT_006ee190 != (HANDLE)0xfffffffe)) {
    CloseHandle(DAT_006ee190);
  }
  if ((DAT_006ee18c != (HANDLE)0xffffffff) && (DAT_006ee18c != (HANDLE)0xfffffffe)) {
    CloseHandle(DAT_006ee18c);
  }
  return;
}


// 00684a08 FUN_00684a08

void FUN_00684a08(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684a4f FUN_00684a4f

void FUN_00684a4f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684a8f FUN_00684a8f

void FUN_00684a8f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ac8 FUN_00684ac8

void FUN_00684ac8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684b0f FUN_00684b0f

void FUN_00684b0f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684b33 FUN_00684b33

void FUN_00684b33(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684b48 FUN_00684b48

void FUN_00684b48(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684b68 FUN_00684b68

void FUN_00684b68(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684c88 FUN_00684c88

void FUN_00684c88(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684cab FUN_00684cab

void FUN_00684cab(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ceb FUN_00684ceb

void FUN_00684ceb(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684d08 FUN_00684d08

void FUN_00684d08(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684d28 FUN_00684d28

void FUN_00684d28(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684d4b FUN_00684d4b

void FUN_00684d4b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684d6b FUN_00684d6b

void FUN_00684d6b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684d8b FUN_00684d8b

void FUN_00684d8b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684db6 FUN_00684db6

void FUN_00684db6(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684dd6 FUN_00684dd6

void FUN_00684dd6(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684e0f FUN_00684e0f

void FUN_00684e0f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684e2b FUN_00684e2b

void FUN_00684e2b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684e53 FUN_00684e53

void FUN_00684e53(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684e6b FUN_00684e6b

void FUN_00684e6b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684e93 FUN_00684e93

void FUN_00684e93(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ec1 FUN_00684ec1

void FUN_00684ec1(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ed8 FUN_00684ed8

void FUN_00684ed8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ef8 FUN_00684ef8

void FUN_00684ef8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684f18 FUN_00684f18

void FUN_00684f18(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684f51 FUN_00684f51

void FUN_00684f51(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684f6e FUN_00684f6e

void FUN_00684f6e(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684f8b FUN_00684f8b

void FUN_00684f8b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684fab FUN_00684fab

void FUN_00684fab(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684fc8 FUN_00684fc8

void FUN_00684fc8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00684ff5 FUN_00684ff5

void FUN_00684ff5(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685013 FUN_00685013

void FUN_00685013(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685028 FUN_00685028

void FUN_00685028(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068504b FUN_0068504b

void FUN_0068504b(void)

{
  ___CxxFrameHandler();
  return;
}


// 006850ae FUN_006850ae

void FUN_006850ae(void)

{
  ___CxxFrameHandler();
  return;
}


// 006850e8 FUN_006850e8

void FUN_006850e8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685113 FUN_00685113

void FUN_00685113(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685136 FUN_00685136

void FUN_00685136(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068514b FUN_0068514b

void FUN_0068514b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685168 FUN_00685168

void FUN_00685168(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068521f FUN_0068521f

void FUN_0068521f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685249 FUN_00685249

void FUN_00685249(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068527b FUN_0068527b

void FUN_0068527b(void)

{
  ___CxxFrameHandler();
  return;
}


// 006852a9 FUN_006852a9

void FUN_006852a9(void)

{
  ___CxxFrameHandler();
  return;
}


// 006852c8 FUN_006852c8

void FUN_006852c8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006852e8 FUN_006852e8

void FUN_006852e8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685326 FUN_00685326

void FUN_00685326(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685343 FUN_00685343

void FUN_00685343(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068535e FUN_0068535e

void FUN_0068535e(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068537b FUN_0068537b

void FUN_0068537b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685398 FUN_00685398

void FUN_00685398(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068541e FUN_0068541e

void FUN_0068541e(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685438 FUN_00685438

void FUN_00685438(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685458 FUN_00685458

void FUN_00685458(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685478 FUN_00685478

void FUN_00685478(void)

{
  ___CxxFrameHandler();
  return;
}


// 006854a3 FUN_006854a3

void FUN_006854a3(void)

{
  ___CxxFrameHandler();
  return;
}


// 006854b8 FUN_006854b8

void FUN_006854b8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006854db FUN_006854db

void FUN_006854db(void)

{
  ___CxxFrameHandler();
  return;
}


// 006854f8 FUN_006854f8

void FUN_006854f8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685526 FUN_00685526

void FUN_00685526(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068553a FUN_0068553a

void FUN_0068553a(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685563 FUN_00685563

void FUN_00685563(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685583 FUN_00685583

void FUN_00685583(void)

{
  ___CxxFrameHandler();
  return;
}


// 006855a5 FUN_006855a5

void FUN_006855a5(void)

{
  ___CxxFrameHandler();
  return;
}


// 006855b8 FUN_006855b8

void FUN_006855b8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006855e8 FUN_006855e8

void FUN_006855e8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685608 FUN_00685608

void FUN_00685608(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068562e FUN_0068562e

void FUN_0068562e(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068564b FUN_0068564b

void FUN_0068564b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685668 FUN_00685668

void FUN_00685668(void)

{
  ___CxxFrameHandler();
  return;
}


// 006856fb FUN_006856fb

void FUN_006856fb(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068572c FUN_0068572c

void FUN_0068572c(void)

{
  ___CxxFrameHandler();
  return;
}


// 006857d4 FUN_006857d4

void FUN_006857d4(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685804 FUN_00685804

void FUN_00685804(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685836 FUN_00685836

void FUN_00685836(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685866 FUN_00685866

void FUN_00685866(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685883 FUN_00685883

void FUN_00685883(void)

{
  ___CxxFrameHandler();
  return;
}


// 006858a3 FUN_006858a3

void FUN_006858a3(void)

{
  ___CxxFrameHandler();
  return;
}


// 006858b8 FUN_006858b8

void FUN_006858b8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006858ee FUN_006858ee

void FUN_006858ee(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685952 FUN_00685952

void FUN_00685952(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685981 FUN_00685981

void FUN_00685981(void)

{
  ___CxxFrameHandler();
  return;
}


// 006859b6 FUN_006859b6

void FUN_006859b6(void)

{
  ___CxxFrameHandler();
  return;
}


// 006859c8 FUN_006859c8

void FUN_006859c8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006859e8 FUN_006859e8

void FUN_006859e8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685a08 FUN_00685a08

void FUN_00685a08(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685a36 FUN_00685a36

void FUN_00685a36(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685a5e FUN_00685a5e

void FUN_00685a5e(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685ab6 FUN_00685ab6

void FUN_00685ab6(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685ad3 FUN_00685ad3

void FUN_00685ad3(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685aeb FUN_00685aeb

void FUN_00685aeb(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685b0b FUN_00685b0b

void FUN_00685b0b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685b5d FUN_00685b5d

void FUN_00685b5d(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685b83 FUN_00685b83

void FUN_00685b83(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685b98 FUN_00685b98

void FUN_00685b98(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685bb8 FUN_00685bb8

void FUN_00685bb8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685bff FUN_00685bff

void FUN_00685bff(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685c3f FUN_00685c3f

void FUN_00685c3f(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685c58 FUN_00685c58

void FUN_00685c58(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685c78 FUN_00685c78

void FUN_00685c78(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685ca3 FUN_00685ca3

void FUN_00685ca3(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685cbb FUN_00685cbb

void FUN_00685cbb(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685d09 FUN_00685d09

void FUN_00685d09(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685d33 FUN_00685d33

void FUN_00685d33(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685d59 FUN_00685d59

void FUN_00685d59(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685d78 FUN_00685d78

void FUN_00685d78(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685e9e FUN_00685e9e

void FUN_00685e9e(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685ecb FUN_00685ecb

void FUN_00685ecb(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685ef5 FUN_00685ef5

void FUN_00685ef5(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685f13 FUN_00685f13

void FUN_00685f13(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685f33 FUN_00685f33

void FUN_00685f33(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685f71 FUN_00685f71

void FUN_00685f71(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685fb6 FUN_00685fb6

void FUN_00685fb6(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685fd3 FUN_00685fd3

void FUN_00685fd3(void)

{
  ___CxxFrameHandler();
  return;
}


// 00685feb FUN_00685feb

void FUN_00685feb(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068600b FUN_0068600b

void FUN_0068600b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068602b FUN_0068602b

void FUN_0068602b(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686048 FUN_00686048

void FUN_00686048(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068606d FUN_0068606d

void FUN_0068606d(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068608b FUN_0068608b

void FUN_0068608b(void)

{
  ___CxxFrameHandler();
  return;
}


// 006860b6 FUN_006860b6

void FUN_006860b6(void)

{
  ___CxxFrameHandler();
  return;
}


// 006860eb FUN_006860eb

void FUN_006860eb(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068610b FUN_0068610b

void FUN_0068610b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068612b FUN_0068612b

void FUN_0068612b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068614b FUN_0068614b

void FUN_0068614b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068618c FUN_0068618c

void FUN_0068618c(void)

{
  ___CxxFrameHandler();
  return;
}


// 006861ec FUN_006861ec

void FUN_006861ec(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686213 FUN_00686213

void FUN_00686213(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686233 FUN_00686233

void FUN_00686233(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068626c FUN_0068626c

void FUN_0068626c(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068628b FUN_0068628b

void FUN_0068628b(void)

{
  ___CxxFrameHandler();
  return;
}


// 006862b3 FUN_006862b3

void FUN_006862b3(void)

{
  ___CxxFrameHandler();
  return;
}


// 006862d3 FUN_006862d3

void FUN_006862d3(void)

{
  ___CxxFrameHandler();
  return;
}


// 006862ee FUN_006862ee

void FUN_006862ee(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068636d FUN_0068636d

void FUN_0068636d(void)

{
  ___CxxFrameHandler();
  return;
}


// 006863b7 FUN_006863b7

void FUN_006863b7(void)

{
  ___CxxFrameHandler();
  return;
}


// 006863e3 FUN_006863e3

void FUN_006863e3(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686403 FUN_00686403

void FUN_00686403(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686423 FUN_00686423

void FUN_00686423(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686443 FUN_00686443

void FUN_00686443(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068646b FUN_0068646b

void FUN_0068646b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068649b FUN_0068649b

void FUN_0068649b(void)

{
  ___CxxFrameHandler();
  return;
}


// 006864b8 FUN_006864b8

void FUN_006864b8(void)

{
  ___CxxFrameHandler();
  return;
}


// 006864db FUN_006864db

void FUN_006864db(void)

{
  ___CxxFrameHandler();
  return;
}


// 006864f8 FUN_006864f8

void FUN_006864f8(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686db3 FUN_00686db3

void FUN_00686db3(void)

{
  ___CxxFrameHandler();
  return;
}


// 00686e5b FUN_00686e5b

void FUN_00686e5b(void)

{
  ___CxxFrameHandler();
  return;
}


// 0068715c FUN_0068715c

void FUN_0068715c(void)

{
  ___CxxFrameHandler();
  return;
}


// 00688456 FUN_00688456

void FUN_00688456(void)

{
  ___CxxFrameHandler();
  return;
}


// 006888fc FUN_006888fc

void FUN_006888fc(void)

{
  ___CxxFrameHandler();
  return;
}


// 00689810 FUN_00689810

void FUN_00689810(void)

{
  FUN_00402b90();
  _atexit((_func_4879 *)&LAB_00696210);
  return;
}


// 00689880 FUN_00689880

void FUN_00689880(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696250);
  return;
}


// 006898a0 FUN_006898a0

void FUN_006898a0(void)

{
  FUN_0047cf30();
  return;
}


// 006898c0 FUN_006898c0

void FUN_006898c0(void)

{
  FUN_0047cf30();
  return;
}


// 006898d0 FUN_006898d0

void FUN_006898d0(void)

{
  FUN_0047cf30();
  return;
}


// 006898e0 FUN_006898e0

void FUN_006898e0(void)

{
  FUN_0047cf30();
  return;
}


// 006898f0 FUN_006898f0

void FUN_006898f0(void)

{
  int iVar1;
  
  iVar1 = 6;
  do {
    FUN_0047cf30();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// 00689920 FUN_00689920

void FUN_00689920(void)

{
  DAT_0078bd40 = 0x4000;
  return;
}


// 00689930 FUN_00689930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689930(void)

{
  _DAT_0078bca8 = _DAT_006cc7bc / _DAT_006b7c78;
  _DAT_0078bc48 = _DAT_006cca94 * _DAT_0078bca8;
  _DAT_0078bc4c = _DAT_006cce58 * _DAT_0078bca8;
  _DAT_0078bc50 = _DAT_006ccbb4 * _DAT_0078bca8;
  _DAT_0078bc54 = _DAT_006cce54 * _DAT_0078bca8;
  _DAT_0078bc58 = _DAT_006cce50 * _DAT_0078bca8;
  _DAT_0078bc5c = _DAT_006ccb8c * _DAT_0078bca8;
  _DAT_0078bc60 = _DAT_006cc8fc * _DAT_0078bca8;
  _DAT_0078bc64 = _DAT_006cce4c * _DAT_0078bca8;
  _DAT_0078bc68 = _DAT_006cccbc * _DAT_0078bca8;
  _DAT_0078bc6c = _DAT_006cce48 * _DAT_0078bca8;
  _DAT_0078bc70 = _DAT_006ccb4c * _DAT_0078bca8;
  _DAT_0078bc74 = _DAT_006cce40 * _DAT_0078bca8;
  _DAT_0078bc78 = _DAT_006cce44 * _DAT_0078bca8;
  _DAT_0078bc7c = _DAT_006ccd44 * _DAT_0078bca8;
  _DAT_0078bc80 = _DAT_006ccc30 * _DAT_0078bca8;
  _DAT_0078bc84 = _DAT_006ccb18 * _DAT_0078bca8;
  _DAT_0078bc88 = _DAT_006cc954 * _DAT_0078bca8;
  _DAT_0078bc8c = _DAT_0078bca8 * _DAT_006cc7a8;
  _DAT_0078bc90 = _DAT_0078bca8 * _DAT_006ccb94;
  _DAT_0078bc94 = _DAT_0078bca8 * _DAT_006cc7c0;
  _DAT_0078bc98 = _DAT_006cc954 * _DAT_0078bca8;
  _DAT_0078bc9c = _DAT_006cc908 * _DAT_0078bca8;
  _DAT_0078bca0 = _DAT_0078bca8 * _DAT_006cc7ac;
  _DAT_0078bca4 = _DAT_0078bca8 + _DAT_0078bca8;
  _DAT_0078bcac = _DAT_0078bca8;
  _DAT_0078bcb0 = _DAT_0078bca8 + _DAT_0078bca8;
  _DAT_0078bcb4 = _DAT_0078bca8 * _DAT_006cc7ac;
  _DAT_0078bcb8 = _DAT_006cc908 * _DAT_0078bca8;
  return;
}


// 00689ab0 FUN_00689ab0

void FUN_00689ab0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696260);
  return;
}


// 00689ad0 FUN_00689ad0

void FUN_00689ad0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "DEFAULTALPHA";
  DAT_0078a4e0 = -1;
  uVar2 = 0x44;
  do {
    DAT_0078a4e0 = DAT_0078a4e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 00689b60 FUN_00689b60

void FUN_00689b60(void)

{
  _atexit((_func_4879 *)&DAT_00696290);
  return;
}


// 00689b70 FUN_00689b70

void FUN_00689b70(void)

{
  _atexit((_func_4879 *)&DAT_006962a0);
  return;
}


// 00689b80 FUN_00689b80

void FUN_00689b80(void)

{
  FUN_004131f0();
  _atexit((_func_4879 *)&DAT_006962b0);
  return;
}


// 00689ba0 FUN_00689ba0

void FUN_00689ba0(void)

{
  _atexit((_func_4879 *)&DAT_006962c0);
  return;
}


// 00689bb0 FUN_00689bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bb0(void)

{
  _DAT_0078a46c = _DAT_006b7c40 + _DAT_006b7c40;
  return;
}


// 00689bc0 FUN_00689bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bc0(void)

{
  _DAT_0078a468 = _DAT_006b7c40 * _DAT_006cc7dc;
  return;
}


// 00689be0 FUN_00689be0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689be0(void)

{
  _DAT_0078a460 = _DAT_006b7c48 + _DAT_006b7c48;
  return;
}


// 00689bf0 FUN_00689bf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bf0(void)

{
  _DAT_0078a470 = _DAT_006b7c48 * _DAT_006cc850;
  return;
}


// 00689c10 FUN_00689c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c10(void)

{
  _DAT_0078a454 = _DAT_006b7c14 + _DAT_006b7c14;
  return;
}


// 00689c20 FUN_00689c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c20(void)

{
  _DAT_0078a450 = _DAT_006b7c14 * _DAT_006cc7dc;
  return;
}


// 00689c40 FUN_00689c40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c40(void)

{
  _DAT_0078a448 = _DAT_006b7c18 + _DAT_006b7c18;
  return;
}


// 00689c50 FUN_00689c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c50(void)

{
  _DAT_0078a458 = _DAT_006b7c18 * _DAT_006cc850;
  return;
}


// 00689c70 FUN_00689c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c70(void)

{
  _DAT_0078a444 = _DAT_006b7b38 + _DAT_006b7b38;
  return;
}


// 00689c80 FUN_00689c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c80(void)

{
  _DAT_0078a440 = _DAT_006b7b38 * _DAT_006cc7dc;
  return;
}


// 00689ca0 FUN_00689ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689ca0(void)

{
  _DAT_0078a438 = _DAT_006b7b40 + _DAT_006b7b40;
  return;
}


// 00689cb0 FUN_00689cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689cb0(void)

{
  _DAT_0078a430 = _DAT_006b7b40 * _DAT_006cc850;
  return;
}


// 00689cd0 FUN_00689cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689cd0(void)

{
  _DAT_0078a428 = _DAT_006cc7bc - _DAT_006b7be4;
  return;
}


// 00689d20 FUN_00689d20

void FUN_00689d20(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0077cec4;
  iVar2 = 0x1e;
  do {
    puVar1[-0x734] = 0;
    RideInfo__Init();
    *puVar1 = 0;
    puVar1 = puVar1 + 0x750;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// 00689e90 FUN_00689e90

void FUN_00689e90(void)

{
  FUN_00441270();
  _atexit((_func_4879 *)&LAB_00696320);
  return;
}


// 00689ed0 FUN_00689ed0

void FUN_00689ed0(void)

{
  _atexit((_func_4879 *)&LAB_00696340);
  return;
}


// 00689f00 FUN_00689f00

void FUN_00689f00(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696360);
  return;
}


// 00689f20 FUN_00689f20

void FUN_00689f20(void)

{
  FUN_00446900();
  _atexit((_func_4879 *)&LAB_00696370);
  return;
}


// 00689f60 FUN_00689f60

void FUN_00689f60(void)

{
  _atexit((_func_4879 *)&DAT_00696390);
  return;
}


// 00689f70 FUN_00689f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689f70(void)

{
  _DAT_0077a8fc = 0xc000;
  return;
}


// 00689f80 FUN_00689f80

void FUN_00689f80(void)

{
  FUN_004561a0();
  _atexit((_func_4879 *)&LAB_006963a0);
  return;
}


// 00689fa0 FUN_00689fa0

void FUN_00689fa0(void)

{
  FUN_004561a0();
  _atexit((_func_4879 *)&LAB_006963b0);
  return;
}


// 00689fd0 FUN_00689fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689fd0(void)

{
  _DAT_0077a4a8 = _DAT_0070067c * _DAT_0070067c;
  return;
}


// 00689ff0 FUN_00689ff0

void FUN_00689ff0(void)

{
  DAT_0077a4a4 = 0x3dd67750;
  return;
}


// 0068a020 FUN_0068a020

void FUN_0068a020(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006963e0);
  return;
}


// 0068a060 FUN_0068a060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a060(void)

{
  _DAT_00779bd4 = _DAT_006b718c + _DAT_006b718c;
  return;
}


// 0068a070 FUN_0068a070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a070(void)

{
  _DAT_00779bd0 = _DAT_006b718c * _DAT_006cc7dc;
  return;
}


// 0068a090 FUN_0068a090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a090(void)

{
  _DAT_00779bc8 = _DAT_006b7190 + _DAT_006b7190;
  return;
}


// 0068a0a0 FUN_0068a0a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0a0(void)

{
  _DAT_00779bc0 = _DAT_006b7190 * _DAT_006cc850;
  return;
}


// 0068a0c0 FUN_0068a0c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0c0(void)

{
  _DAT_00779ad4 = _DAT_006b70d4 + _DAT_006b70d4;
  return;
}


// 0068a0d0 FUN_0068a0d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0d0(void)

{
  _DAT_00779ad0 = _DAT_006b70d4 * _DAT_006cc7dc;
  return;
}


// 0068a0f0 FUN_0068a0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0f0(void)

{
  _DAT_00779ac8 = _DAT_006b70d8 + _DAT_006b70d8;
  return;
}


// 0068a100 FUN_0068a100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a100(void)

{
  _DAT_00779ac0 = _DAT_006b70d8 * _DAT_006cc850;
  return;
}


// 0068a120 FUN_0068a120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a120(void)

{
  _DAT_00779ab0 = 0x3db2b8c2;
  return;
}


// 0068a1a0 FUN_0068a1a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a1a0(void)

{
  _DAT_00779ab4 = &DAT_00779b70;
  _DAT_00779ab8 = 5;
  return;
}


// 0068a1c0 FUN_0068a1c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a1c0(void)

{
  _DAT_00779b98 = 0;
  _DAT_00779b9c = 0;
  _DAT_00779ba0 = 0x3f490fdb;
  _DAT_00779ba4 = 0x3e8ccccd;
  _DAT_00779ba8 = 0x3fa78d36;
  _DAT_00779bac = 0x3f800000;
  _DAT_00779bb0 = 0x3fc6d3f2;
  _DAT_00779bb4 = 0x3f800000;
  _DAT_00779bb8 = 0x3fc90fdb;
  _DAT_00779bbc = 0;
  return;
}


// 0068a230 FUN_0068a230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a230(void)

{
  _DAT_00779aa8 = &DAT_00779b98;
  _DAT_00779aac = 5;
  return;
}


// 0068a250 FUN_0068a250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a250(void)

{
  _DAT_00779aa4 = _DAT_006b70c0 + _DAT_006b70c0;
  return;
}


// 0068a260 FUN_0068a260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a260(void)

{
  _DAT_00779aa0 = _DAT_006b70c0 * _DAT_006cc7dc;
  return;
}


// 0068a280 FUN_0068a280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a280(void)

{
  _DAT_00779a98 = _DAT_006b70c8 + _DAT_006b70c8;
  return;
}


// 0068a290 FUN_0068a290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a290(void)

{
  _DAT_00779a90 = _DAT_006b70c8 * _DAT_006cc850;
  return;
}


// 0068a2b0 FUN_0068a2b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2b0(void)

{
  _DAT_00779a7c = _DAT_006b70b0 + _DAT_006b70b0;
  return;
}


// 0068a2c0 FUN_0068a2c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2c0(void)

{
  _DAT_00779a78 = _DAT_006b70b0 * _DAT_006cc7dc;
  return;
}


// 0068a2e0 FUN_0068a2e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2e0(void)

{
  _DAT_00779a70 = _DAT_006b70b8 + _DAT_006b70b8;
  return;
}


// 0068a2f0 FUN_0068a2f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2f0(void)

{
  _DAT_00779a68 = _DAT_006b70b8 * _DAT_006cc850;
  return;
}


// 0068a340 FUN_0068a340

void FUN_0068a340(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82e8;
  DAT_00779a58 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a58 = DAT_00779a58 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 0068a3a0 FUN_0068a3a0

void FUN_0068a3a0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82d8;
  DAT_00779a5c = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a5c = DAT_00779a5c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 0068a400 FUN_0068a400

void FUN_0068a400(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82c8;
  DAT_00779a84 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a84 = DAT_00779a84 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 0068a460 FUN_0068a460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a460(void)

{
  _DAT_00779a54 = _DAT_006b70a0 + _DAT_006b70a0;
  return;
}


// 0068a470 FUN_0068a470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a470(void)

{
  _DAT_00779a50 = _DAT_006b70a0 * _DAT_006cc7dc;
  return;
}


// 0068a490 FUN_0068a490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a490(void)

{
  _DAT_00779a48 = _DAT_006b70a8 + _DAT_006b70a8;
  return;
}


// 0068a4a0 FUN_0068a4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4a0(void)

{
  _DAT_00779a40 = _DAT_006b70a8 * _DAT_006cc850;
  return;
}


// 0068a4c0 FUN_0068a4c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4c0(void)

{
  _DAT_00779a3c = _DAT_006b7090 + _DAT_006b7090;
  return;
}


// 0068a4d0 FUN_0068a4d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4d0(void)

{
  _DAT_00779a38 = _DAT_006b7090 * _DAT_006cc7dc;
  return;
}


// 0068a4f0 FUN_0068a4f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4f0(void)

{
  _DAT_00779a30 = _DAT_006b7098 + _DAT_006b7098;
  return;
}


// 0068a500 FUN_0068a500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a500(void)

{
  _DAT_00779a28 = _DAT_006b7098 * _DAT_006cc850;
  return;
}


// 0068a520 FUN_0068a520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a520(void)

{
  _DAT_00779a24 = _DAT_006b7080 + _DAT_006b7080;
  return;
}


// 0068a530 FUN_0068a530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a530(void)

{
  _DAT_00779a20 = _DAT_006b7080 * _DAT_006cc7dc;
  return;
}


// 0068a550 FUN_0068a550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a550(void)

{
  _DAT_00779a18 = _DAT_006b7088 + _DAT_006b7088;
  return;
}


// 0068a560 FUN_0068a560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a560(void)

{
  _DAT_00779a10 = _DAT_006b7088 * _DAT_006cc850;
  return;
}


// 0068a580 FUN_0068a580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a580(void)

{
  _DAT_00779a0c = _DAT_006b7070 + _DAT_006b7070;
  return;
}


// 0068a590 FUN_0068a590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a590(void)

{
  _DAT_00779a08 = _DAT_006b7070 * _DAT_006cc7dc;
  return;
}


// 0068a5b0 FUN_0068a5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5b0(void)

{
  _DAT_00779a00 = _DAT_006b7078 + _DAT_006b7078;
  return;
}


// 0068a5c0 FUN_0068a5c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5c0(void)

{
  _DAT_007799f8 = _DAT_006b7078 * _DAT_006cc850;
  return;
}


// 0068a5e0 FUN_0068a5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5e0(void)

{
  _DAT_007799f4 = _DAT_006b7060 + _DAT_006b7060;
  return;
}


// 0068a5f0 FUN_0068a5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5f0(void)

{
  _DAT_007799f0 = _DAT_006b7060 * _DAT_006cc7dc;
  return;
}


// 0068a610 FUN_0068a610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a610(void)

{
  _DAT_007799e8 = _DAT_006b7068 + _DAT_006b7068;
  return;
}


// 0068a620 FUN_0068a620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a620(void)

{
  _DAT_007799e0 = _DAT_006b7068 * _DAT_006cc850;
  return;
}


// 0068a640 FUN_0068a640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a640(void)

{
  _DAT_007797ec = _DAT_006b7040 + _DAT_006b7040;
  return;
}


// 0068a650 FUN_0068a650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a650(void)

{
  _DAT_007797e8 = _DAT_006b7040 * _DAT_006cc7dc;
  return;
}


// 0068a670 FUN_0068a670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a670(void)

{
  _DAT_007797e0 = _DAT_006b7048 + _DAT_006b7048;
  return;
}


// 0068a680 FUN_0068a680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a680(void)

{
  _DAT_007797d8 = _DAT_006b7048 * _DAT_006cc850;
  return;
}


// 0068a6a0 FUN_0068a6a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a6a0(void)

{
  _DAT_007799b0 = 0x904;
  _DAT_007799b4 = 0x907;
  _DAT_007799b8 = 0x906;
  _DAT_007799bc = 0x905;
  _DAT_007799c0 = 0x90e;
  _DAT_007799c4 = 0x91a;
  _DAT_007799c8 = 0x90d;
  _DAT_007799cc = 0x90f;
  return;
}


// 0068a700 FUN_0068a700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a700(void)

{
  _DAT_00779980 = 0x904;
  _DAT_00779984 = 0x907;
  _DAT_00779988 = 0x906;
  _DAT_0077998c = 0x905;
  _DAT_00779990 = 0x90e;
  _DAT_00779994 = 0x91a;
  _DAT_00779998 = 0x90d;
  _DAT_0077999c = 0x90f;
  return;
}


// 0068a760 FUN_0068a760

void FUN_0068a760(void)

{
  DAT_007797f4 = 0x904;
  return;
}


// 0068a770 FUN_0068a770

void FUN_0068a770(void)

{
  DAT_00779958 = 0x922;
  return;
}


// 0068a780 FUN_0068a780

void FUN_0068a780(void)

{
  DAT_007797d4 = 0x920;
  return;
}


// 0068a790 FUN_0068a790

void FUN_0068a790(void)

{
  DAT_007797f0 = 0x921;
  return;
}


// 0068a7a0 FUN_0068a7a0

void FUN_0068a7a0(void)

{
  DAT_00779950 = 0x912;
  return;
}


// 0068a7b0 FUN_0068a7b0

void FUN_0068a7b0(void)

{
  DAT_0077995c = 0x912;
  return;
}


// 0068a7c0 FUN_0068a7c0

void FUN_0068a7c0(void)

{
  DAT_007797c8 = 0x912;
  return;
}


// 0068a7d0 FUN_0068a7d0

void FUN_0068a7d0(void)

{
  DAT_00779954 = 0x916;
  return;
}


// 0068a7e0 FUN_0068a7e0

void FUN_0068a7e0(void)

{
  DAT_007797cc = 0x912;
  return;
}


// 0068a7f0 FUN_0068a7f0

void FUN_0068a7f0(void)

{
  DAT_007797d0 = 0x913;
  return;
}


// 0068a840 FUN_0068a840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a840(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 *puVar3;
  
  DAT_007799d0 = -1;
  puVar3 = &DAT_006c8240;
  bVar2 = DAT_006c8240;
  while (bVar2 != 0) {
    DAT_007799d0 = DAT_007799d0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007799d4 = -1;
  puVar3 = &DAT_006c824c;
  bVar2 = DAT_006c824c;
  while (bVar2 != 0) {
    _DAT_007799d4 = _DAT_007799d4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007799d8 = -1;
  puVar3 = &DAT_006c8258;
  bVar2 = DAT_006c8258;
  while (bVar2 != 0) {
    _DAT_007799d8 = _DAT_007799d8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  puVar3 = &DAT_006c8264;
  _DAT_007799dc = -1;
  bVar2 = DAT_006c8264;
  while (bVar2 != 0) {
    _DAT_007799dc = _DAT_007799dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068a8f0 FUN_0068a8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a8f0(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 *puVar3;
  
  DAT_00779960 = -1;
  puVar3 = &DAT_006c8210;
  bVar2 = DAT_006c8210;
  while (bVar2 != 0) {
    DAT_00779960 = DAT_00779960 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00779964 = -1;
  puVar3 = &DAT_006c821c;
  bVar2 = DAT_006c821c;
  while (bVar2 != 0) {
    _DAT_00779964 = _DAT_00779964 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00779968 = -1;
  puVar3 = &DAT_006c8228;
  bVar2 = DAT_006c8228;
  while (bVar2 != 0) {
    _DAT_00779968 = _DAT_00779968 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  puVar3 = &DAT_006c8234;
  _DAT_0077996c = -1;
  bVar2 = DAT_006c8234;
  while (bVar2 != 0) {
    _DAT_0077996c = _DAT_0077996c * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068a9a0 FUN_0068a9a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a9a0(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 *puVar3;
  
  DAT_007799a0 = -1;
  puVar3 = &DAT_006c81e0;
  bVar2 = DAT_006c81e0;
  while (bVar2 != 0) {
    DAT_007799a0 = DAT_007799a0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007799a4 = -1;
  puVar3 = &DAT_006c81ec;
  bVar2 = DAT_006c81ec;
  while (bVar2 != 0) {
    _DAT_007799a4 = _DAT_007799a4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007799a8 = -1;
  puVar3 = &DAT_006c81f8;
  bVar2 = DAT_006c81f8;
  while (bVar2 != 0) {
    _DAT_007799a8 = _DAT_007799a8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  puVar3 = &DAT_006c8204;
  _DAT_007799ac = -1;
  bVar2 = DAT_006c8204;
  while (bVar2 != 0) {
    _DAT_007799ac = _DAT_007799ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068ab00 FUN_0068ab00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab00(void)

{
  _DAT_007797bc = _DAT_006b7030 + _DAT_006b7030;
  return;
}


// 0068ab10 FUN_0068ab10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab10(void)

{
  _DAT_007797b8 = _DAT_006b7030 * _DAT_006cc7dc;
  return;
}


// 0068ab30 FUN_0068ab30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab30(void)

{
  _DAT_007797b0 = _DAT_006b7038 + _DAT_006b7038;
  return;
}


// 0068ab40 FUN_0068ab40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab40(void)

{
  _DAT_007797a8 = _DAT_006b7038 * _DAT_006cc850;
  return;
}


// 0068ac00 FUN_0068ac00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac00(void)

{
  _DAT_00779790 = _DAT_006b7020 * _DAT_006cc7dc;
  return;
}


// 0068ac20 FUN_0068ac20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac20(void)

{
  _DAT_00779788 = _DAT_006b7028 + _DAT_006b7028;
  return;
}


// 0068ac30 FUN_0068ac30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac30(void)

{
  _DAT_00779780 = _DAT_006b7028 * _DAT_006cc850;
  return;
}


// 0068ac70 FUN_0068ac70

void FUN_0068ac70(void)

{
  DAT_00779720 = 0x2aaa;
  return;
}


// 0068ac80 FUN_0068ac80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac80(void)

{
  _DAT_0077971c = _DAT_006b7004 + _DAT_006b7004;
  return;
}


// 0068ac90 FUN_0068ac90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac90(void)

{
  _DAT_00779718 = _DAT_006b7004 * _DAT_006cc7dc;
  return;
}


// 0068acb0 FUN_0068acb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068acb0(void)

{
  _DAT_00779710 = _DAT_006b7008 + _DAT_006b7008;
  return;
}


// 0068acc0 FUN_0068acc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068acc0(void)

{
  _DAT_00779708 = _DAT_006b7008 * _DAT_006cc850;
  return;
}


// 0068ace0 FUN_0068ace0

void FUN_0068ace0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696450);
  return;
}


// 0068ad00 FUN_0068ad00

void FUN_0068ad00(void)

{
  FUN_0047ff30();
  _atexit((_func_4879 *)&LAB_00696460);
  return;
}


// 0068ad20 FUN_0068ad20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad20(void)

{
  _DAT_007788d4 = _DAT_006b6c4c + _DAT_006b6c4c;
  return;
}


// 0068ad30 FUN_0068ad30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad30(void)

{
  _DAT_007788d0 = _DAT_006b6c4c * _DAT_006cc7dc;
  return;
}


// 0068ad50 FUN_0068ad50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad50(void)

{
  _DAT_007788c8 = _DAT_006b6c50 + _DAT_006b6c50;
  return;
}


// 0068ad60 FUN_0068ad60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad60(void)

{
  _DAT_007788c0 = _DAT_006b6c50 * _DAT_006cc850;
  return;
}


// 0068adb0 FUN_0068adb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068adb0(void)

{
  _DAT_007788b8 = 0x38e;
  return;
}


// 0068adc0 FUN_0068adc0

void FUN_0068adc0(void)

{
  DAT_007789e4._0_2_ = 0xbbb;
  return;
}


// 0068add0 FUN_0068add0

void FUN_0068add0(void)

{
  DAT_007789e0._0_2_ = 0x3555;
  return;
}


// 0068ade0 FUN_0068ade0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ade0(void)

{
  _DAT_007789e8 = 0x38e;
  return;
}


// 0068adf0 FUN_0068adf0

void FUN_0068adf0(void)

{
  DAT_007788bc = 0x3555;
  return;
}


// 0068ae00 FUN_0068ae00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ae00(void)

{
  _DAT_00706788 = DAT_00700b64;
  _DAT_0070678c = 0x3e4ccccd;
  _DAT_00706794 = 0x3d4ccccd;
  _DAT_00706790 = DAT_00700b64 + _DAT_006cc79c;
  return;
}


// 0068ae40 FUN_0068ae40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ae40(void)

{
  _DAT_0077889c = &DAT_00706780;
  _DAT_007788a0 = 3;
  return;
}


// 0068ae60 FUN_0068ae60

void FUN_0068ae60(void)

{
  FUN_004a9bc0(&DAT_00748f70);
  _atexit((_func_4879 *)&LAB_00696480);
  return;
}


// 0068aea0 FUN_0068aea0

void FUN_0068aea0(void)

{
  RideInfo__Init();
  return;
}


// 0068aec0 FUN_0068aec0

void FUN_0068aec0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006964c0);
  return;
}


// 0068aee0 FUN_0068aee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068aee0(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  DAT_00746bf8 = -1;
  pcVar3 = "Keyboard.fng";
  bVar2 = s_Keyboard_fng_006c2498[0];
  while (bVar2 != 0) {
    DAT_00746bf8 = DAT_00746bf8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00746c14 = -1;
  _DAT_00746bfc = 2;
  _DAT_00746c00 = 3;
  _DAT_00746c04 = 0;
  _DAT_00746c08 = 1;
  _DAT_00746c0c = 0x29;
  _DAT_00746c10 = 0xffffffff;
  pcVar3 = "EA_TRAX_Jukebox.fng";
  bVar2 = s_EA_TRAX_Jukebox_fng_006c2418[0];
  while (bVar2 != 0) {
    DAT_00746c14 = DAT_00746c14 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746c24 = 1;
  _DAT_00746c30 = -1;
  _DAT_00746c18 = 0x4c;
  _DAT_00746c1c = 0x4c;
  _DAT_00746c20 = 0;
  _DAT_00746c28 = 0x29;
  _DAT_00746c2c = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Alpine.fng";
  bVar2 = s_EA_TRAX_Jukebox_Alpine_fng_006c23fc[0];
  while (bVar2 != 0) {
    _DAT_00746c30 = _DAT_00746c30 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746c4c = -1;
  _DAT_00746c34 = 0x4c;
  _DAT_00746c38 = 0x4c;
  _DAT_00746c3c = 0;
  _DAT_00746c40 = 1;
  _DAT_00746c44 = 0x29;
  _DAT_00746c48 = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Kenwood.fng";
  bVar2 = s_EA_TRAX_Jukebox_Kenwood_fng_006c23e0[0];
  while (bVar2 != 0) {
    _DAT_00746c4c = _DAT_00746c4c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746c68 = -1;
  _DAT_00746c50 = 0x4c;
  _DAT_00746c54 = 0x4c;
  _DAT_00746c58 = 0;
  _DAT_00746c5c = 1;
  _DAT_00746c60 = 0x29;
  _DAT_00746c64 = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Audiobahn.fng";
  bVar2 = s_EA_TRAX_Jukebox_Audiobahn_fng_006c23c0[0];
  while (bVar2 != 0) {
    _DAT_00746c68 = _DAT_00746c68 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746c6c = 0x4c;
  _DAT_00746c70 = 0x4c;
  _DAT_00746c80 = 0x4d;
  _DAT_00746c7c = 0x29;
  _DAT_00746c74 = 0;
  _DAT_00746c78 = 1;
  pcVar3 = "LS_Splash.fng";
  _DAT_00746c84 = -1;
  bVar2 = s_LS_Splash_fng_006c5124[0];
  while (bVar2 != 0) {
    _DAT_00746c84 = _DAT_00746c84 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746c88 = 0xffffffff;
  _DAT_00746c8c = 0xffffffff;
  _DAT_00746c90 = 0xffffffff;
  _DAT_00746c94 = 0xffffffff;
  _DAT_00746c9c = 0xffffffff;
  _DAT_00746c98 = 0x27;
  return;
}


// 0068be70 FUN_0068be70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068be70(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar4 = "GarageMain.fng";
  DAT_00746ca0 = -1;
  uVar3 = 0x47;
  do {
    DAT_00746ca0 = DAT_00746ca0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "GarageMain_2P.fng";
  DAT_00746ca4 = -1;
  uVar3 = 0x47;
  do {
    DAT_00746ca4 = DAT_00746ca4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_Garage.fng";
  _DAT_00746ca8 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746ca8 = _DAT_00746ca8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_GarageAccessoriesCategory.fng";
  _DAT_00746cac = -1;
  bVar2 = s_MU_GarageAccessoriesCategory_fng_006c2714[0];
  while (bVar2 != 0) {
    _DAT_00746cac = _DAT_00746cac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cb0 = -1;
  pcVar4 = "MU_GarageDecals.fng";
  bVar2 = s_MU_GarageDecals_fng_006c63c4[0];
  while (bVar2 != 0) {
    _DAT_00746cb0 = _DAT_00746cb0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cb4 = -1;
  pcVar4 = "MU_GarageDecals_Brand.fng";
  bVar2 = s_MU_GarageDecals_Brand_fng_006c2738[0];
  while (bVar2 != 0) {
    _DAT_00746cb4 = _DAT_00746cb4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cb8 = -1;
  pcVar4 = "MU_GarageDecals_ChooseDecal.fng";
  bVar2 = s_MU_GarageDecals_ChooseDecal_fng_006c63a4[0];
  while (bVar2 != 0) {
    _DAT_00746cb8 = _DAT_00746cb8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cbc = -1;
  pcVar4 = "MU_GarageDecals_Size.fng";
  bVar2 = s_MU_GarageDecals_Size_fng_006c2770[0];
  while (bVar2 != 0) {
    _DAT_00746cbc = _DAT_00746cbc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cc0 = -1;
  pcVar4 = "MU_GarageDecals_Slot.fng";
  bVar2 = s_MU_GarageDecals_Slot_fng_006c2754[0];
  while (bVar2 != 0) {
    _DAT_00746cc0 = _DAT_00746cc0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cc4 = -1;
  pcVar4 = "MU_GarageDecals_Zone.fng";
  bVar2 = s_MU_GarageDecals_Zone_fng_006c278c[0];
  while (bVar2 != 0) {
    _DAT_00746cc4 = _DAT_00746cc4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cc8 = -1;
  pcVar4 = "MU_GarageMenu.fng";
  bVar2 = s_MU_GarageMenu_fng_006c4e40[0];
  while (bVar2 != 0) {
    _DAT_00746cc8 = _DAT_00746cc8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746ccc = -1;
  pcVar4 = "MU_GaragePaintMod.fng";
  bVar2 = s_MU_GaragePaintMod_fng_006c2818[0];
  while (bVar2 != 0) {
    _DAT_00746ccc = _DAT_00746ccc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cd0 = -1;
  pcVar4 = "MU_GaragePartsBrowser.fng";
  bVar2 = s_MU_GaragePartsBrowser_fng_006c292c[0];
  while (bVar2 != 0) {
    _DAT_00746cd0 = _DAT_00746cd0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cd4 = -1;
  pcVar4 = "MU_GaragePartsCategory.fng";
  bVar2 = s_MU_GaragePartsCategory_fng_006c4e54[0];
  while (bVar2 != 0) {
    _DAT_00746cd4 = _DAT_00746cd4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cd8 = -1;
  pcVar4 = "MU_GaragePartsCategoryVisual.fng";
  bVar2 = s_MU_GaragePartsCategoryVisual_fng_006c28ac[0];
  while (bVar2 != 0) {
    _DAT_00746cd8 = _DAT_00746cd8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cdc = -1;
  pcVar4 = "MU_GaragePartsChooseVisual.fng";
  bVar2 = s_MU_GaragePartsChooseVisual_fng_006c2948[0];
  while (bVar2 != 0) {
    _DAT_00746cdc = _DAT_00746cdc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746ce0 = -1;
  pcVar4 = "MU_GaragePerformanceBrand.fng";
  bVar2 = s_MU_GaragePerformanceBrand_fng_006c2848[0];
  while (bVar2 != 0) {
    _DAT_00746ce0 = _DAT_00746ce0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746ce4 = -1;
  pcVar4 = "MU_GaragePerformanceTuner.fng";
  bVar2 = s_MU_GaragePerformanceTuner_fng_006c2868[0];
  while (bVar2 != 0) {
    _DAT_00746ce4 = _DAT_00746ce4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746ce8 = -1;
  pcVar4 = "MU_GaragePerformanceV2.fng";
  bVar2 = s_MU_GaragePerformanceV2_fng_006c4e70[0];
  while (bVar2 != 0) {
    _DAT_00746ce8 = _DAT_00746ce8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cec = -1;
  pcVar4 = "MU_GarageRimsBrandBrowser.fng";
  bVar2 = s_MU_GarageRimsBrandBrowser_fng_006c290c[0];
  while (bVar2 != 0) {
    _DAT_00746cec = _DAT_00746cec * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cf0 = -1;
  pcVar4 = "MU_GarageRimsBrowser.fng";
  bVar2 = s_MU_GarageRimsBrowser_fng_006c28d0[0];
  while (bVar2 != 0) {
    _DAT_00746cf0 = _DAT_00746cf0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cf4 = -1;
  pcVar4 = "MU_GarageRimsStyleBrowser.fng";
  bVar2 = s_MU_GarageRimsStyleBrowser_fng_006c28ec[0];
  while (bVar2 != 0) {
    _DAT_00746cf4 = _DAT_00746cf4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cf8 = -1;
  pcVar4 = "MU_GarageVinylBrand.fng";
  bVar2 = s_MU_GarageVinylBrand_fng_006c6370[0];
  while (bVar2 != 0) {
    _DAT_00746cf8 = _DAT_00746cf8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746cfc = -1;
  pcVar4 = "MU_GarageVinylBrowser.fng";
  bVar2 = s_MU_GarageVinylBrowser_fng_006c2968[0];
  while (bVar2 != 0) {
    _DAT_00746cfc = _DAT_00746cfc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d00 = -1;
  pcVar4 = "MU_GarageVinylGroup.fng";
  bVar2 = s_MU_GarageVinylGroup_fng_006c2984[0];
  while (bVar2 != 0) {
    _DAT_00746d00 = _DAT_00746d00 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d04 = -1;
  pcVar4 = "MU_GarageVinylLayerV2.fng";
  bVar2 = s_MU_GarageVinylLayerV2_fng_006c26d8[0];
  while (bVar2 != 0) {
    _DAT_00746d04 = _DAT_00746d04 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d08 = -1;
  pcVar4 = "MU_MainMenuCarCustomize.fng";
  bVar2 = s_MU_MainMenuCarCustomize_fng_006c27fc[0];
  while (bVar2 != 0) {
    _DAT_00746d08 = _DAT_00746d08 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746d0c = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746d0c = _DAT_00746d0c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_QuickRaceCarSelect.fng";
  _DAT_00746d10 = -1;
  bVar2 = s_MU_QuickRaceCarSelect_fng_006c27e0[0];
  while (bVar2 != 0) {
    _DAT_00746d10 = _DAT_00746d10 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d14 = -1;
  pcVar4 = "MU_QuickRaceLapPopup_PC.fng";
  bVar2 = s_MU_QuickRaceLapPopup_PC_fng_006c210c[0];
  while (bVar2 != 0) {
    _DAT_00746d14 = _DAT_00746d14 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d18 = -1;
  pcVar4 = "MU_GarageAudioCategory.fng";
  bVar2 = s_MU_GarageAudioCategory_fng_006c4ef0[0];
  while (bVar2 != 0) {
    _DAT_00746d18 = _DAT_00746d18 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d1c = -1;
  pcVar4 = "MU_GaragePartsCategoryVisual.fng";
  bVar2 = s_MU_GaragePartsCategoryVisual_fng_006c28ac[0];
  while (bVar2 != 0) {
    _DAT_00746d1c = _DAT_00746d1c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d20 = -1;
  pcVar4 = "MU_GarageRimsStyleBrowser.fng";
  bVar2 = s_MU_GarageRimsStyleBrowser_fng_006c28ec[0];
  while (bVar2 != 0) {
    _DAT_00746d20 = _DAT_00746d20 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d24 = -1;
  pcVar4 = "MU_GarageRimsBrowser.fng";
  bVar2 = s_MU_GarageRimsBrowser_fng_006c28d0[0];
  while (bVar2 != 0) {
    _DAT_00746d24 = _DAT_00746d24 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d28 = -1;
  pcVar4 = "MU_GaragePaintMod.fng";
  bVar2 = s_MU_GaragePaintMod_fng_006c2818[0];
  while (bVar2 != 0) {
    _DAT_00746d28 = _DAT_00746d28 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d2c = -1;
  pcVar4 = "MU_GarageVinylBrand.fng";
  bVar2 = s_MU_GarageVinylBrand_fng_006c6370[0];
  while (bVar2 != 0) {
    _DAT_00746d2c = _DAT_00746d2c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d30 = -1;
  pcVar4 = "MU_GarageVinylGroup.fng";
  bVar2 = s_MU_GarageVinylGroup_fng_006c2984[0];
  while (bVar2 != 0) {
    _DAT_00746d30 = _DAT_00746d30 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d34 = -1;
  pcVar4 = "MU_GarageVinylType.fng";
  bVar2 = s_MU_GarageVinylType_fng_006c26c0[0];
  while (bVar2 != 0) {
    _DAT_00746d34 = _DAT_00746d34 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d38 = -1;
  pcVar4 = "MU_GarageVinylBrowser.fng";
  bVar2 = s_MU_GarageVinylBrowser_fng_006c2968[0];
  while (bVar2 != 0) {
    _DAT_00746d38 = _DAT_00746d38 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d3c = -1;
  pcVar4 = "MU_GarageDecals.fng";
  bVar2 = s_MU_GarageDecals_fng_006c63c4[0];
  while (bVar2 != 0) {
    _DAT_00746d3c = _DAT_00746d3c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d40 = -1;
  pcVar4 = "MU_GaragePartsCategory.fng";
  bVar2 = s_MU_GaragePartsCategory_fng_006c4e54[0];
  while (bVar2 != 0) {
    _DAT_00746d40 = _DAT_00746d40 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d44 = -1;
  pcVar4 = "MU_GaragePartsChooseVisual.fng";
  bVar2 = s_MU_GaragePartsChooseVisual_fng_006c2948[0];
  while (bVar2 != 0) {
    _DAT_00746d44 = _DAT_00746d44 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d48 = -1;
  pcVar4 = "MU_GarageVinylLayerV2.fng";
  bVar2 = s_MU_GarageVinylLayerV2_fng_006c26d8[0];
  while (bVar2 != 0) {
    _DAT_00746d48 = _DAT_00746d48 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d4c = -1;
  pcVar4 = "MU_GarageDecals_Zone.fng";
  bVar2 = s_MU_GarageDecals_Zone_fng_006c278c[0];
  while (bVar2 != 0) {
    _DAT_00746d4c = _DAT_00746d4c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d50 = -1;
  pcVar4 = "MU_GarageDecals_Size.fng";
  bVar2 = s_MU_GarageDecals_Size_fng_006c2770[0];
  while (bVar2 != 0) {
    _DAT_00746d50 = _DAT_00746d50 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d54 = -1;
  pcVar4 = "MU_GarageDecals_Slot.fng";
  bVar2 = s_MU_GarageDecals_Slot_fng_006c2754[0];
  while (bVar2 != 0) {
    _DAT_00746d54 = _DAT_00746d54 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d58 = -1;
  pcVar4 = "MU_GarageDecals_Brand.fng";
  bVar2 = s_MU_GarageDecals_Brand_fng_006c2738[0];
  while (bVar2 != 0) {
    _DAT_00746d58 = _DAT_00746d58 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d5c = -1;
  pcVar4 = "MU_GarageDecals_ChooseDecal.fng";
  bVar2 = s_MU_GarageDecals_ChooseDecal_fng_006c63a4[0];
  while (bVar2 != 0) {
    _DAT_00746d5c = _DAT_00746d5c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d60 = -1;
  pcVar4 = "MU_GarageAccessoriesCategory.fng";
  bVar2 = s_MU_GarageAccessoriesCategory_fng_006c2714[0];
  while (bVar2 != 0) {
    _DAT_00746d60 = _DAT_00746d60 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "GarageMain.fng";
  _DAT_00746d64 = -1;
  uVar3 = 0x47;
  do {
    _DAT_00746d64 = _DAT_00746d64 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "GarageMain_2P.fng";
  _DAT_00746d68 = -1;
  uVar3 = 0x47;
  do {
    _DAT_00746d68 = _DAT_00746d68 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_Garage.fng";
  _DAT_00746d6c = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746d6c = _DAT_00746d6c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_GarageMenu.fng";
  _DAT_00746d70 = -1;
  bVar2 = s_MU_GarageMenu_fng_006c4e40[0];
  while (bVar2 != 0) {
    _DAT_00746d70 = _DAT_00746d70 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d74 = -1;
  pcVar4 = "MU_GaragePartsBrowser.fng";
  bVar2 = s_MU_GaragePartsBrowser_fng_006c292c[0];
  while (bVar2 != 0) {
    _DAT_00746d74 = _DAT_00746d74 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d78 = -1;
  pcVar4 = "MU_GarageRimsBrandBrowser.fng";
  bVar2 = s_MU_GarageRimsBrandBrowser_fng_006c290c[0];
  while (bVar2 != 0) {
    _DAT_00746d78 = _DAT_00746d78 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d7c = -1;
  pcVar4 = "MU_GaragePerformanceTuner.fng";
  bVar2 = s_MU_GaragePerformanceTuner_fng_006c2868[0];
  while (bVar2 != 0) {
    _DAT_00746d7c = _DAT_00746d7c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d80 = -1;
  pcVar4 = "MU_GaragePerformanceBrand.fng";
  bVar2 = s_MU_GaragePerformanceBrand_fng_006c2848[0];
  while (bVar2 != 0) {
    _DAT_00746d80 = _DAT_00746d80 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d84 = -1;
  pcVar4 = "MU_GaragePerformanceV2.fng";
  bVar2 = s_MU_GaragePerformanceV2_fng_006c4e70[0];
  while (bVar2 != 0) {
    _DAT_00746d84 = _DAT_00746d84 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746d88 = -1;
  pcVar4 = "MU_QRTransmissionSelect.fng";
  bVar2 = s_MU_QRTransmissionSelect_fng_006c2444[0];
  while (bVar2 != 0) {
    _DAT_00746d88 = _DAT_00746d88 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "MU_GaragePerformanceCategory.fng";
  _DAT_00746d8c = -1;
  bVar2 = s_MU_GaragePerformanceCategory_fng_006c2888[0];
  while (bVar2 != 0) {
    _DAT_00746d8c = _DAT_00746d8c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068c7c0 FUN_0068c7c0

void FUN_0068c7c0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "GenericDialog.fng";
  DAT_007469bc = -1;
  uVar2 = 0x47;
  do {
    DAT_007469bc = DAT_007469bc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 0068c800 FUN_0068c800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c800(void)

{
  _DAT_007469b0 = 0xffffffff;
  return;
}


// 0068c870 FUN_0068c870

void FUN_0068c870(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  DAT_00746dcc = -1;
  pcVar3 = "ColorPicker.fng";
  bVar2 = s_ColorPicker_fng_006c4e8c[0];
  while (bVar2 != 0) {
    DAT_00746dcc = DAT_00746dcc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068c8a0 FUN_0068c8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c8a0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  
  DAT_00746db4 = -1;
  pcVar4 = "MU_UG_ChooseCareerCar.fng";
  bVar2 = s_MU_UG_ChooseCareerCar_fng_006c27c4[0];
  while (bVar2 != 0) {
    DAT_00746db4 = DAT_00746db4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00746db8 = -1;
  pcVar4 = "MU_MainMenuCarCustomize.fng";
  bVar2 = s_MU_MainMenuCarCustomize_fng_006c27fc[0];
  while (bVar2 != 0) {
    DAT_00746db8 = DAT_00746db8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746dbc = -1;
  pcVar4 = "MU_QuickRaceCarSelect.fng";
  bVar2 = s_MU_QuickRaceCarSelect_fng_006c27e0[0];
  while (bVar2 != 0) {
    _DAT_00746dbc = _DAT_00746dbc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746dc0 = -1;
  pcVar4 = "MU_QuickRaceLapPopup_PC.fng";
  bVar2 = s_MU_QuickRaceLapPopup_PC_fng_006c210c[0];
  while (bVar2 != 0) {
    _DAT_00746dc0 = _DAT_00746dc0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746dc4 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746dc4 = _DAT_00746dc4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746dc8 = -1;
  pcVar4 = "MU_UG_ChooseCareerCar.fng";
  bVar2 = s_MU_UG_ChooseCareerCar_fng_006c27c4[0];
  while (bVar2 != 0) {
    _DAT_00746dc8 = _DAT_00746dc8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068c900 FUN_0068c900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0068c900(byte param_1)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  uint uVar3;
  char *pcVar4;
  byte unaff_BL;
  bool in_ZF;
  
  pcVar4 = "MU_QuickRaceCarSelect.fng";
  if (!in_ZF) {
    do {
      in_EAX = in_EAX * 0x21 + (uint)param_1;
      param_1 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
    } while (param_1 != 0);
  }
  _DAT_00746dbc = in_EAX;
  _DAT_00746dc0 = -1;
  pcVar4 = "MU_QuickRaceLapPopup_PC.fng";
  bVar2 = s_MU_QuickRaceLapPopup_PC_fng_006c210c[0];
  while (bVar2 != 0) {
    _DAT_00746dc0 = _DAT_00746dc0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746dc4 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746dc4 = _DAT_00746dc4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746dc8 = -1;
  pcVar4 = "MU_UG_ChooseCareerCar.fng";
  while (unaff_BL != 0) {
    _DAT_00746dc8 = _DAT_00746dc8 * 0x21 + (uint)unaff_BL;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    unaff_BL = *pbVar1;
  }
  return;
}


// 0068cec0 FUN_0068cec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068cec0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  
  DAT_00746d90 = -1;
  pcVar4 = "2CarImportDialogBot.fng";
  bVar2 = s_2CarImportDialogBot_fng_006c41f8[0];
  while (bVar2 != 0) {
    DAT_00746d90 = DAT_00746d90 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00746d94 = -1;
  pcVar4 = "2CarImportDialogTop.fng";
  bVar2 = s_2CarImportDialogTop_fng_006c4210[0];
  while (bVar2 != 0) {
    DAT_00746d94 = DAT_00746d94 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "GenericDialog.fng";
  _DAT_00746d98 = -1;
  uVar3 = 0x47;
  do {
    _DAT_00746d98 = _DAT_00746d98 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "MU_Online_WarningDialog.fng";
  _DAT_00746d9c = -1;
  bVar2 = s_MU_Online_WarningDialog_fng_006c247c[0];
  while (bVar2 != 0) {
    _DAT_00746d9c = _DAT_00746d9c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746da0 = -1;
  pcVar4 = "MU_Online4PlayerGameDialogueBox.fng";
  bVar2 = s_MU_Online4PlayerGameDialogueBox__006c22cc[0];
  while (bVar2 != 0) {
    _DAT_00746da0 = _DAT_00746da0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746da4 = -1;
  pcVar4 = "MU_OnlineChallengSettingsDialogueBox.fng";
  bVar2 = s_MU_OnlineChallengSettingsDialogu_006c4228[0];
  while (bVar2 != 0) {
    _DAT_00746da4 = _DAT_00746da4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746da8 = -1;
  pcVar4 = "MU_OnlineGamesRoomDialog.fng";
  bVar2 = s_MU_OnlineGamesRoomDialog_fng_006c2290[0];
  while (bVar2 != 0) {
    _DAT_00746da8 = _DAT_00746da8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746dac = -1;
  pcVar4 = "MU_OnlineGenericDialogueBox.fng";
  bVar2 = s_MU_OnlineGenericDialogueBox_fng_006c4fcc[0];
  while (bVar2 != 0) {
    _DAT_00746dac = _DAT_00746dac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "MU_UG_TradeCarConfirm.fng";
  _DAT_00746db0 = -1;
  bVar2 = s_MU_UG_TradeCarConfirm_fng_006c233c[0];
  while (bVar2 != 0) {
    _DAT_00746db0 = _DAT_00746db0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068d030 FUN_0068d030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d030(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  _DAT_00746974 = -1;
  pcVar3 = "GLOSS";
  bVar2 = s_GLOSS_006c3ce0[0];
  while (bVar2 != 0) {
    _DAT_00746974 = _DAT_00746974 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074697c = -1;
  _DAT_00746978 = 1;
  pcVar3 = "METAL";
  bVar2 = s_METAL_006b916c[0];
  while (bVar2 != 0) {
    _DAT_0074697c = _DAT_0074697c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746984 = -1;
  _DAT_00746980 = 2;
  pcVar3 = "PEARL";
  bVar2 = s_PEARL_006c3ce8[0];
  while (bVar2 != 0) {
    _DAT_00746984 = _DAT_00746984 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074698c = -1;
  _DAT_00746988 = 3;
  pcVar3 = "CALIPER";
  bVar2 = s_CALIPER_006c3cf0[0];
  while (bVar2 != 0) {
    _DAT_0074698c = _DAT_0074698c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746994 = -1;
  _DAT_00746990 = 4;
  puVar4 = &DAT_006c3cf8;
  bVar2 = DAT_006c3cf8;
  while (bVar2 != 0) {
    _DAT_00746994 = _DAT_00746994 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074699c = -1;
  _DAT_00746998 = 5;
  puVar4 = &DAT_006c3d00;
  bVar2 = DAT_006c3d00;
  while (bVar2 != 0) {
    _DAT_0074699c = _DAT_0074699c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007469a4 = -1;
  _DAT_007469a0 = 6;
  pcVar3 = "MUFFLER";
  bVar2 = s_MUFFLER_006c3d04[0];
  while (bVar2 != 0) {
    _DAT_007469a4 = _DAT_007469a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007469a8 = 7;
  puVar4 = &DAT_006c3d0c;
  _DAT_007469ac = -1;
  bVar2 = DAT_006c3d0c;
  while (bVar2 != 0) {
    _DAT_007469ac = _DAT_007469ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068d1c0 FUN_0068d1c0

void FUN_0068d1c0(void)

{
  _atexit((_func_4879 *)&DAT_006964d0);
  return;
}


// 0068d1d0 FUN_0068d1d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d1d0(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  _DAT_00746918 = -1;
  pcVar3 = "VINYL_GROUP_TEAR";
  bVar2 = s_VINYL_GROUP_TEAR_006c34a8[0];
  while (bVar2 != 0) {
    _DAT_00746918 = _DAT_00746918 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074691c = -1;
  pcVar3 = "VINYL_GROUP_TEAR_HOOD";
  bVar2 = s_VINYL_GROUP_TEAR_HOOD_006c34bc[0];
  while (bVar2 != 0) {
    _DAT_0074691c = _DAT_0074691c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746920 = -1;
  pcVar3 = "VINYL_GROUP_STRIPES";
  bVar2 = s_VINYL_GROUP_STRIPES_006c34d4[0];
  while (bVar2 != 0) {
    _DAT_00746920 = _DAT_00746920 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746924 = -1;
  pcVar3 = "VINYL_GROUP_STRIPES_HOOD";
  bVar2 = s_VINYL_GROUP_STRIPES_HOOD_006c34e8[0];
  while (bVar2 != 0) {
    _DAT_00746924 = _DAT_00746924 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746928 = -1;
  pcVar3 = "VINYL_GROUP_SPLASH";
  bVar2 = s_VINYL_GROUP_SPLASH_006c3504[0];
  while (bVar2 != 0) {
    _DAT_00746928 = _DAT_00746928 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074692c = -1;
  pcVar3 = "VINYL_GROUP_MODERN";
  bVar2 = s_VINYL_GROUP_MODERN_006c3518[0];
  while (bVar2 != 0) {
    _DAT_0074692c = _DAT_0074692c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746930 = -1;
  pcVar3 = "VINYL_GROUP_MODERN_HOOD";
  bVar2 = s_VINYL_GROUP_MODERN_HOOD_006c352c[0];
  while (bVar2 != 0) {
    _DAT_00746930 = _DAT_00746930 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746934 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES";
  bVar2 = s_VINYL_GROUP_FLAMES_006c3544[0];
  while (bVar2 != 0) {
    _DAT_00746934 = _DAT_00746934 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746938 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES_HOOD";
  bVar2 = s_VINYL_GROUP_FLAMES_HOOD_006c3558[0];
  while (bVar2 != 0) {
    _DAT_00746938 = _DAT_00746938 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074693c = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING";
  bVar2 = s_VINYL_GROUP_LIGHTNING_006c3570[0];
  while (bVar2 != 0) {
    _DAT_0074693c = _DAT_0074693c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746940 = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING_HOOD";
  bVar2 = s_VINYL_GROUP_LIGHTNING_HOOD_006c3588[0];
  while (bVar2 != 0) {
    _DAT_00746940 = _DAT_00746940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746944 = -1;
  pcVar3 = "VINYL_GROUP_FLAGS";
  bVar2 = s_VINYL_GROUP_FLAGS_006c35a4[0];
  while (bVar2 != 0) {
    _DAT_00746944 = _DAT_00746944 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746948 = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL";
  bVar2 = s_VINYL_GROUP_TRIBAL_006c35b8[0];
  while (bVar2 != 0) {
    _DAT_00746948 = _DAT_00746948 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074694c = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL_HOOD";
  bVar2 = s_VINYL_GROUP_TRIBAL_HOOD_006c35cc[0];
  while (bVar2 != 0) {
    _DAT_0074694c = _DAT_0074694c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746950 = -1;
  pcVar3 = "VINYL_GROUP_WILD";
  bVar2 = s_VINYL_GROUP_WILD_006c35e4[0];
  while (bVar2 != 0) {
    _DAT_00746950 = _DAT_00746950 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00746954 = -1;
  pcVar3 = "VINYL_GROUP_UNIQUES";
  bVar2 = s_VINYL_GROUP_UNIQUES_006c35f8[0];
  while (bVar2 != 0) {
    DAT_00746954 = DAT_00746954 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746958 = -1;
  pcVar3 = "VINYL_GROUP_AEM";
  bVar2 = s_VINYL_GROUP_AEM_006c360c[0];
  while (bVar2 != 0) {
    _DAT_00746958 = _DAT_00746958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074695c = -1;
  pcVar3 = "VINYL_GROUP_BODY_VINYL";
  bVar2 = s_VINYL_GROUP_BODY_VINYL_006c361c[0];
  while (bVar2 != 0) {
    _DAT_0074695c = _DAT_0074695c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "VINYL_GROUP_MANUFACTURAR_LOGO";
  _DAT_00746960 = -1;
  bVar2 = s_VINYL_GROUP_MANUFACTURAR_LOGO_006c3634[0];
  while (bVar2 != 0) {
    _DAT_00746960 = _DAT_00746960 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068d300 FUN_0068d300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0068d300(byte param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  char *pcVar3;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  _DAT_00746934 = in_EAX;
  _DAT_00746938 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES_HOOD";
  bVar2 = s_VINYL_GROUP_FLAMES_HOOD_006c3558[0];
  while (bVar2 != 0) {
    _DAT_00746938 = _DAT_00746938 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074693c = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING";
  bVar2 = s_VINYL_GROUP_LIGHTNING_006c3570[0];
  while (bVar2 != 0) {
    _DAT_0074693c = _DAT_0074693c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746940 = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING_HOOD";
  bVar2 = s_VINYL_GROUP_LIGHTNING_HOOD_006c3588[0];
  while (bVar2 != 0) {
    _DAT_00746940 = _DAT_00746940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746944 = -1;
  pcVar3 = "VINYL_GROUP_FLAGS";
  bVar2 = s_VINYL_GROUP_FLAGS_006c35a4[0];
  while (bVar2 != 0) {
    _DAT_00746944 = _DAT_00746944 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746948 = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL";
  bVar2 = s_VINYL_GROUP_TRIBAL_006c35b8[0];
  while (bVar2 != 0) {
    _DAT_00746948 = _DAT_00746948 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074694c = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL_HOOD";
  bVar2 = s_VINYL_GROUP_TRIBAL_HOOD_006c35cc[0];
  while (bVar2 != 0) {
    _DAT_0074694c = _DAT_0074694c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746950 = -1;
  pcVar3 = "VINYL_GROUP_WILD";
  bVar2 = s_VINYL_GROUP_WILD_006c35e4[0];
  while (bVar2 != 0) {
    _DAT_00746950 = _DAT_00746950 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00746954 = -1;
  pcVar3 = "VINYL_GROUP_UNIQUES";
  bVar2 = s_VINYL_GROUP_UNIQUES_006c35f8[0];
  while (bVar2 != 0) {
    DAT_00746954 = DAT_00746954 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746958 = -1;
  pcVar3 = "VINYL_GROUP_AEM";
  bVar2 = s_VINYL_GROUP_AEM_006c360c[0];
  while (bVar2 != 0) {
    _DAT_00746958 = _DAT_00746958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074695c = -1;
  pcVar3 = "VINYL_GROUP_BODY_VINYL";
  bVar2 = s_VINYL_GROUP_BODY_VINYL_006c361c[0];
  while (bVar2 != 0) {
    _DAT_0074695c = _DAT_0074695c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "VINYL_GROUP_MANUFACTURAR_LOGO";
  _DAT_00746960 = -1;
  bVar2 = s_VINYL_GROUP_MANUFACTURAR_LOGO_006c3634[0];
  while (bVar2 != 0) {
    _DAT_00746960 = _DAT_00746960 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068d4d0 FUN_0068d4d0

void FUN_0068d4d0(void)

{
  eh_vector_constructor_iterator
            (&DAT_00746118,8,0x100,(_func_void_void_ptr *)&LAB_0049fd90,
             (_func_void_void_ptr *)&LAB_0049fda0);
  _atexit((_func_4879 *)&LAB_006964e0);
  return;
}


// 0068d500 FUN_0068d500

void FUN_0068d500(void)

{
  FUN_004f3d30();
  _atexit((_func_4879 *)&LAB_00696500);
  return;
}


// 0068d520 FUN_0068d520

void FUN_0068d520(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696510);
  return;
}


// 0068d540 FUN_0068d540

void FUN_0068d540(void)

{
  FUN_004fcaf0();
  _atexit((_func_4879 *)&LAB_00696520);
  return;
}


// 0068d580 FUN_0068d580

void FUN_0068d580(void)

{
  FUN_004fcaf0();
  _atexit((_func_4879 *)&LAB_00696540);
  return;
}


// 0068d5a0 FUN_0068d5a0

void FUN_0068d5a0(void)

{
  FUN_004fcaf0();
  _atexit((_func_4879 *)&LAB_00696550);
  return;
}


// 0068d5c0 FUN_0068d5c0

void FUN_0068d5c0(void)

{
  FUN_00504220();
  _atexit((_func_4879 *)&LAB_00696560);
  return;
}


// 0068d5e0 FUN_0068d5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d5e0(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  _DAT_00706668 = -1;
  pcVar3 = "VISUAL_PART_MUFFLERTIP";
  bVar2 = s_VISUAL_PART_MUFFLERTIP_006c1500[0];
  while (bVar2 != 0) {
    _DAT_00706668 = _DAT_00706668 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00706670 = 0;
  _DAT_00706678 = 0;
  _DAT_0070668c = 0;
  _DAT_00706694 = 0;
  _DAT_00706698 = 0;
  _DAT_0070666c = "_KIT%02d_EXHAUST";
  _DAT_00706674 = 0xf;
  _DAT_0070667c = 0xa5b28001;
  _DAT_00706680 = 0xc;
  _DAT_00706684 = 0x945e9bc5;
  _DAT_00706688 = "_KIT%02d_WIDE_BODY";
  _DAT_00706690 = 6;
  return;
}


// 0068de40 FUN_0068de40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068de40(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  DAT_00745fc0 = -1;
  pcVar3 = "NEON_NONE";
  bVar2 = s_NEON_NONE_006c10c0[0];
  while (bVar2 != 0) {
    DAT_00745fc0 = DAT_00745fc0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_00745fc8 = -1;
  _DAT_00745fc4 = 0x3b83203;
  pcVar3 = "NEON_RED";
  bVar2 = s_NEON_RED_006c10cc[0];
  while (bVar2 != 0) {
    DAT_00745fc8 = DAT_00745fc8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745fd0 = -1;
  DAT_00745fcc = 0x5054a89;
  pcVar3 = "NEON_GREEN";
  bVar2 = s_NEON_GREEN_006c10d8[0];
  while (bVar2 != 0) {
    _DAT_00745fd0 = _DAT_00745fd0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745fd8 = -1;
  _DAT_00745fd4 = 0x5ac2319f;
  pcVar3 = "NEON_BLUE";
  bVar2 = s_NEON_BLUE_006c10e4[0];
  while (bVar2 != 0) {
    _DAT_00745fd8 = _DAT_00745fd8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745fe0 = -1;
  _DAT_00745fdc = 0xa5a5f5d6;
  pcVar3 = "NEON_ORANGE";
  bVar2 = s_NEON_ORANGE_006c10f0[0];
  while (bVar2 != 0) {
    _DAT_00745fe0 = _DAT_00745fe0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745fe8 = -1;
  _DAT_00745fe4 = 0xc5af9eaa;
  pcVar3 = "NEON_YELLOW";
  bVar2 = s_NEON_YELLOW_006c10fc[0];
  while (bVar2 != 0) {
    _DAT_00745fe8 = _DAT_00745fe8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745ff0 = -1;
  _DAT_00745fec = 0xdc1df72a;
  pcVar3 = "NEON_AQUA";
  bVar2 = s_NEON_AQUA_006c1108[0];
  while (bVar2 != 0) {
    _DAT_00745ff0 = _DAT_00745ff0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00745ff8 = -1;
  _DAT_00745ff4 = 0xa5a57eb6;
  pcVar3 = "NEON_WHITE";
  bVar2 = s_NEON_WHITE_006c1114[0];
  while (bVar2 != 0) {
    _DAT_00745ff8 = _DAT_00745ff8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746000 = -1;
  _DAT_00745ffc = 0x5bde50cf;
  pcVar3 = "NEON_GRAPE";
  bVar2 = s_NEON_GRAPE_006c1120[0];
  while (bVar2 != 0) {
    _DAT_00746000 = _DAT_00746000 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746008 = -1;
  _DAT_00746004 = 0x5ac221fd;
  pcVar3 = "NEON_PINK";
  bVar2 = s_NEON_PINK_006c112c[0];
  while (bVar2 != 0) {
    _DAT_00746008 = _DAT_00746008 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746010 = -1;
  _DAT_0074600c = 0xa5ad9580;
  pcVar3 = "NEON_LIME";
  bVar2 = s_NEON_LIME_006c1138[0];
  while (bVar2 != 0) {
    _DAT_00746010 = _DAT_00746010 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746018 = -1;
  _DAT_00746014 = 0xa5ab63d5;
  pcVar3 = "NEON_LAVENDER";
  bVar2 = s_NEON_LAVENDER_006c1144[0];
  while (bVar2 != 0) {
    _DAT_00746018 = _DAT_00746018 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746020 = -1;
  _DAT_0074601c = 0x3f0bbdff;
  pcVar3 = "NEON_GOLD";
  bVar2 = s_NEON_GOLD_006c1154[0];
  while (bVar2 != 0) {
    _DAT_00746020 = _DAT_00746020 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746028 = -1;
  _DAT_00746024 = 0xa5a8bf54;
  pcVar3 = "NEON_RED_PULSE";
  bVar2 = s_NEON_RED_PULSE_006c1160[0];
  while (bVar2 != 0) {
    _DAT_00746028 = _DAT_00746028 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746030 = -1;
  _DAT_0074602c = 0x5fb0f3d1;
  pcVar3 = "NEON_GREEN_PULSE";
  bVar2 = s_NEON_GREEN_PULSE_006c1170[0];
  while (bVar2 != 0) {
    _DAT_00746030 = _DAT_00746030 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746038 = -1;
  _DAT_00746034 = 0x7cc05367;
  pcVar3 = "NEON_BLUE_PULSE";
  bVar2 = s_NEON_BLUE_PULSE_006c1184[0];
  while (bVar2 != 0) {
    _DAT_00746038 = _DAT_00746038 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746040 = -1;
  _DAT_0074603c = 0x462a24de;
  pcVar3 = "NEON_ORANGE_PULSE";
  bVar2 = s_NEON_ORANGE_PULSE_006c1194[0];
  while (bVar2 != 0) {
    _DAT_00746040 = _DAT_00746040 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746048 = -1;
  _DAT_00746044 = 0x800c1cb2;
  pcVar3 = "NEON_YELLOW_PULSE";
  bVar2 = s_NEON_YELLOW_PULSE_006c11a8[0];
  while (bVar2 != 0) {
    _DAT_00746048 = _DAT_00746048 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746050 = -1;
  _DAT_0074604c = 0xb2fad532;
  pcVar3 = "NEON_AQUA_PULSE";
  bVar2 = s_NEON_AQUA_PULSE_006c11bc[0];
  while (bVar2 != 0) {
    _DAT_00746050 = _DAT_00746050 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746058 = -1;
  _DAT_00746054 = 0x54a4d5be;
  pcVar3 = "NEON_WHITE_PULSE";
  bVar2 = s_NEON_WHITE_PULSE_006c11cc[0];
  while (bVar2 != 0) {
    _DAT_00746058 = _DAT_00746058 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746060 = -1;
  _DAT_0074605c = 0x9f231697;
  pcVar3 = "NEON_GRAPE_PULSE";
  bVar2 = s_NEON_GRAPE_PULSE_006c11e0[0];
  while (bVar2 != 0) {
    _DAT_00746060 = _DAT_00746060 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746068 = -1;
  _DAT_00746064 = 0x1cd69245;
  pcVar3 = "NEON_PINK_PULSE";
  bVar2 = s_NEON_PINK_PULSE_006c11f4[0];
  while (bVar2 != 0) {
    _DAT_00746068 = _DAT_00746068 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746070 = -1;
  _DAT_0074606c = 0x79595c08;
  pcVar3 = "NEON_LIME_PULSE";
  bVar2 = s_NEON_LIME_PULSE_006c1204[0];
  while (bVar2 != 0) {
    _DAT_00746070 = _DAT_00746070 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746078 = -1;
  _DAT_00746074 = 0xaf0fd61d;
  pcVar3 = "NEON_LAVENDER_PULSE";
  bVar2 = s_NEON_LAVENDER_PULSE_006c1214[0];
  while (bVar2 != 0) {
    _DAT_00746078 = _DAT_00746078 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074607c = 0x6ad9a7c7;
  pcVar3 = "NEON_GOLD_PULSE";
  _DAT_00746080 = -1;
  bVar2 = s_NEON_GOLD_PULSE_006c1228[0];
  while (bVar2 != 0) {
    _DAT_00746080 = _DAT_00746080 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00746084 = 0x1c8994dc;
  return;
}


// 0068e430 FUN_0068e430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e430(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  _DAT_007460a0 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT1_WIDEBODY";
  bVar2 = s_DECAL_RIGHTDOOR_SLOT1_WIDEBODY_006c0668[0];
  while (bVar2 != 0) {
    _DAT_007460a0 = _DAT_007460a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007460a4 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT2_WIDEBODY";
  bVar2 = s_DECAL_RIGHTDOOR_SLOT2_WIDEBODY_006c0688[0];
  while (bVar2 != 0) {
    _DAT_007460a4 = _DAT_007460a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007460a8 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT3_WIDEBODY";
  bVar2 = s_DECAL_RIGHTDOOR_SLOT3_WIDEBODY_006c06a8[0];
  while (bVar2 != 0) {
    _DAT_007460a8 = _DAT_007460a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007460ac = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT4_WIDEBODY";
  bVar2 = s_DECAL_RIGHTDOOR_SLOT4_WIDEBODY_006c06c8[0];
  while (bVar2 != 0) {
    _DAT_007460ac = _DAT_007460ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007460b0 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT5_WIDEBODY";
  bVar2 = s_DECAL_RIGHTDOOR_SLOT5_WIDEBODY_006c06e8[0];
  while (bVar2 != 0) {
    _DAT_007460b0 = _DAT_007460b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "DECAL_RIGHTDOOR_SLOT6_WIDEBODY";
  _DAT_007460b4 = -1;
  bVar2 = s_DECAL_RIGHTDOOR_SLOT6_WIDEBODY_006c0708[0];
  while (bVar2 != 0) {
    _DAT_007460b4 = _DAT_007460b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 0068e560 FUN_0068e560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e560(void)

{
  DAT_007066c4 = 0x15;
  _DAT_007066c8 = 0x15;
  _DAT_007066d0 = PTR_s__s_DECAL_REAR_WINDOW_WIDE_MEDIUM_006f88b0;
  _DAT_007066f8 = PTR_s__s_WIDE1_DECAL_LEFT_DOOR_RECT_ME_006f88cc;
  _DAT_007066f0 = PTR_s__s_DECAL_LEFT_DOOR_RECT_MEDIUM_006f88b4;
  _DAT_00706710 = PTR_s__s_DECAL_RIGHT_DOOR_RECT_MEDIUM_006f88b8;
  _DAT_007066fc = PTR_s__s_WIDE2_DECAL_LEFT_DOOR_RECT_ME_006f88dc;
  _DAT_0070671c = PTR_s__s_WIDE2_DECAL_RIGHT_DOOR_RECT_M_006f88e0;
  _DAT_00706718 = PTR_s__s_WIDE1_DECAL_RIGHT_DOOR_RECT_M_006f88d0;
  _DAT_00706734 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_SMALL_006f88c0;
  _DAT_00706730 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_MEDIU_006f88bc;
  _DAT_0070673c = PTR_s__s_WIDE2_DECAL_LEFT_QUARTER_RECT_006f88e4;
  _DAT_00706738 = PTR_s__s_WIDE1_DECAL_LEFT_QUARTER_RECT_006f88d4;
  _DAT_00706754 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_SMAL_006f88c8;
  _DAT_00706750 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_MEDI_006f88c4;
  _DAT_0070675c = PTR_s__s_WIDE2_DECAL_RIGHT_QUARTER_REC_006f88e8;
  _DAT_007066b0 = PTR_s__s_DECAL_FRONT_WINDOW_WIDE_MEDIU_006f88ac;
  _DAT_00706758 = PTR_s__s_WIDE1_DECAL_RIGHT_QUARTER_REC_006f88d8;
  _DAT_00706764 = 0x13;
  _DAT_00706768 = 0x13;
  _DAT_007066b4 = 0;
  _DAT_007066b8 = 0;
  _DAT_007066bc = 0;
  DAT_007066c0 = 1;
  DAT_007066cc = 0x4b;
  _DAT_007066d4 = 0;
  _DAT_007066d8 = 0;
  _DAT_007066dc = 0;
  _DAT_007066e0 = 2;
  _DAT_007066e4 = 0x16;
  _DAT_007066e8 = 0x1a;
  _DAT_007066ec = 0x53;
  _DAT_007066f4 = 0;
  _DAT_00706700 = 3;
  _DAT_00706704 = 0x17;
  _DAT_00706708 = 0x1b;
  _DAT_0070670c = 0x5b;
  _DAT_00706714 = 0;
  _DAT_00706720 = 4;
  _DAT_00706724 = 0x18;
  _DAT_00706728 = 0x1c;
  _DAT_0070672c = 99;
  _DAT_00706740 = 5;
  _DAT_00706744 = 0x19;
  _DAT_00706748 = 0x1d;
  _DAT_0070674c = 0x6b;
  _DAT_00706760 = 6;
  _DAT_0070676c = 0x3b;
  _DAT_00706770 = PTR_s__s_DECAL_HOOD_RECT_MEDIUM_006f88ec;
  _DAT_00706774 = PTR_s__s_DECAL_HOOD_RECT_SMALL_006f88f0;
  _DAT_00706778 = 0;
  _DAT_0070677c = 0;
  return;
}


// 0068e760 FUN_0068e760

void FUN_0068e760(void)

{
  FUN_00504150();
  _atexit((_func_4879 *)&DAT_00696570);
  return;
}


// 0068e790 FUN_0068e790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e790(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "MAGAZINE_RACE_1";
  _DAT_007449dc = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449dc = _DAT_007449dc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  DAT_007449e0 = 1;
  pcVar3 = "MAGAZINE_RACE_2";
  DAT_007449e4 = -1;
  uVar2 = 0x4d;
  do {
    DAT_007449e4 = DAT_007449e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449e8 = 2;
  pcVar3 = "MAGAZINE_RACE_3";
  _DAT_007449ec = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449ec = _DAT_007449ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449f0 = 3;
  pcVar3 = "MAGAZINE_RACE_4";
  _DAT_007449f4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449f4 = _DAT_007449f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449f8 = 4;
  pcVar3 = "MAGAZINE_RACE_5";
  _DAT_007449fc = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449fc = _DAT_007449fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a00 = 5;
  pcVar3 = "MAGAZINE_RACE_6";
  _DAT_00744a04 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a04 = _DAT_00744a04 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a08 = 6;
  pcVar3 = "MAGAZINE_RACE_7";
  _DAT_00744a0c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a0c = _DAT_00744a0c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a10 = 7;
  pcVar3 = "MAGAZINE_RACE_8";
  _DAT_00744a14 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a14 = _DAT_00744a14 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a18 = 8;
  pcVar3 = "MAGAZINE_RACE_9";
  _DAT_00744a1c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a1c = _DAT_00744a1c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a20 = 9;
  pcVar3 = "MAGAZINE_RACE_10";
  _DAT_00744a24 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a24 = _DAT_00744a24 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a28 = 10;
  pcVar3 = "MAGAZINE_RACE_11";
  _DAT_00744a2c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a2c = _DAT_00744a2c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a30 = 0xb;
  pcVar3 = "MAGAZINE_TASK_1";
  _DAT_00744a34 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a34 = _DAT_00744a34 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a38 = 0xc;
  pcVar3 = "MAGAZINE_TASK_2";
  _DAT_00744a3c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a3c = _DAT_00744a3c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a40 = 0xd;
  pcVar3 = "MAGAZINE_TASK_3";
  _DAT_00744a44 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a44 = _DAT_00744a44 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a48 = 0xe;
  pcVar3 = "MAGAZINE_TASK_4";
  _DAT_00744a4c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a4c = _DAT_00744a4c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a50 = 0xf;
  pcVar3 = "MAGAZINE_TASK_5";
  _DAT_00744a54 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a54 = _DAT_00744a54 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a58 = 0x10;
  pcVar3 = "MAGAZINE_TASK_6";
  _DAT_00744a5c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a5c = _DAT_00744a5c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a60 = 0x11;
  pcVar3 = "MAGAZINE_TASK_7";
  _DAT_00744a64 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a64 = _DAT_00744a64 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a68 = 0x12;
  pcVar3 = "MAGAZINE_TASK_8";
  _DAT_00744a6c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a6c = _DAT_00744a6c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a70 = 0x13;
  pcVar3 = "MAGAZINE_TASK_9";
  _DAT_00744a74 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a74 = _DAT_00744a74 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a78 = 0x14;
  pcVar3 = "MAGAZINE_TASK_10";
  _DAT_00744a7c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a7c = _DAT_00744a7c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a80 = 0x15;
  pcVar3 = "MAGAZINE_TASK_11";
  _DAT_00744a84 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a84 = _DAT_00744a84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a88 = 0x16;
  pcVar3 = "MAGAZINE_TASK_12";
  _DAT_00744a8c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a8c = _DAT_00744a8c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a90 = 0x17;
  pcVar3 = "MAGAZINE_TASK_13";
  _DAT_00744a94 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a94 = _DAT_00744a94 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a98 = 0x18;
  pcVar3 = "MAGAZINE_TASK_14";
  _DAT_00744a9c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a9c = _DAT_00744a9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aa0 = 0x19;
  pcVar3 = "MAGAZINE_TASK_15";
  _DAT_00744aa4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744aa4 = _DAT_00744aa4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aa8 = 0x1a;
  pcVar3 = "MAGAZINE_TASK_16";
  _DAT_00744aac = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744aac = _DAT_00744aac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// 0068eca0 FUN_0068eca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068eca0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "MAGAZINE_RACE_1";
  DAT_00744ab0 = -1;
  uVar2 = 0x4d;
  do {
    DAT_00744ab0 = DAT_00744ab0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ab4 = 0;
  pcVar3 = "MAGAZINE_RACE_2";
  DAT_00744ab8 = -1;
  uVar2 = 0x4d;
  do {
    DAT_00744ab8 = DAT_00744ab8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  DAT_00744abc = 1;
  pcVar3 = "MAGAZINE_RACE_3";
  _DAT_00744ac0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ac0 = _DAT_00744ac0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ac4 = 2;
  pcVar3 = "MAGAZINE_RACE_4";
  _DAT_00744ac8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ac8 = _DAT_00744ac8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744acc = 3;
  pcVar3 = "MAGAZINE_RACE_5";
  _DAT_00744ad0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ad0 = _DAT_00744ad0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ad4 = 4;
  pcVar3 = "MAGAZINE_RACE_6";
  _DAT_00744ad8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ad8 = _DAT_00744ad8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744adc = 5;
  pcVar3 = "MAGAZINE_RACE_7";
  _DAT_00744ae0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ae0 = _DAT_00744ae0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ae4 = 6;
  pcVar3 = "MAGAZINE_RACE_8";
  _DAT_00744ae8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ae8 = _DAT_00744ae8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aec = 7;
  pcVar3 = "MAGAZINE_RACE_9";
  _DAT_00744af0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744af0 = _DAT_00744af0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744af4 = 8;
  pcVar3 = "MAGAZINE_RACE_10";
  _DAT_00744af8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744af8 = _DAT_00744af8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744afc = 9;
  pcVar3 = "MAGAZINE_RACE_11";
  _DAT_00744b00 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b00 = _DAT_00744b00 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b04 = 10;
  pcVar3 = "MAGAZINE_TASK_1";
  _DAT_00744b08 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b08 = _DAT_00744b08 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b0c = 0xb;
  pcVar3 = "MAGAZINE_TASK_2";
  _DAT_00744b10 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b10 = _DAT_00744b10 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b14 = 0xc;
  pcVar3 = "MAGAZINE_TASK_3";
  _DAT_00744b18 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b18 = _DAT_00744b18 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b1c = 0xd;
  pcVar3 = "MAGAZINE_TASK_4";
  _DAT_00744b20 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b20 = _DAT_00744b20 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b24 = 0xe;
  pcVar3 = "MAGAZINE_TASK_5";
  _DAT_00744b28 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b28 = _DAT_00744b28 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b2c = 0xf;
  pcVar3 = "MAGAZINE_TASK_6";
  _DAT_00744b30 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b30 = _DAT_00744b30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b34 = 0x10;
  pcVar3 = "MAGAZINE_TASK_7";
  _DAT_00744b38 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b38 = _DAT_00744b38 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b3c = 0x11;
  pcVar3 = "MAGAZINE_TASK_8";
  _DAT_00744b40 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b40 = _DAT_00744b40 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b44 = 0x12;
  pcVar3 = "MAGAZINE_TASK_9";
  _DAT_00744b48 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b48 = _DAT_00744b48 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b4c = 0x13;
  pcVar3 = "MAGAZINE_TASK_10";
  _DAT_00744b50 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b50 = _DAT_00744b50 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b54 = 0x14;
  pcVar3 = "MAGAZINE_TASK_11";
  _DAT_00744b58 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b58 = _DAT_00744b58 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b5c = 0x15;
  pcVar3 = "MAGAZINE_TASK_12";
  _DAT_00744b60 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b60 = _DAT_00744b60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b64 = 0x16;
  pcVar3 = "MAGAZINE_TASK_13";
  _DAT_00744b68 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b68 = _DAT_00744b68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b6c = 0x17;
  pcVar3 = "MAGAZINE_TASK_14";
  _DAT_00744b70 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b70 = _DAT_00744b70 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b74 = 0x18;
  pcVar3 = "MAGAZINE_TASK_15";
  _DAT_00744b78 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b78 = _DAT_00744b78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b7c = 0x19;
  pcVar3 = "MAGAZINE_TASK_16";
  _DAT_00744b80 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b80 = _DAT_00744b80 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b84 = 0x1a;
  return;
}


// 0068f1c0 FUN_0068f1c0

void FUN_0068f1c0(void)

{
  FUN_00589260();
  _atexit((_func_4879 *)&LAB_00696590);
  return;
}


// 0068f1f0 FUN_0068f1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068f1f0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined *puVar6;
  
  puVar4 = &DAT_006bf808;
  DAT_00744364 = -1;
  bVar2 = DAT_006bf808;
  while (bVar2 != 0) {
    DAT_00744364 = DAT_00744364 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bf810;
  DAT_00744368 = -1;
  bVar2 = DAT_006bf810;
  while (bVar2 != 0) {
    DAT_00744368 = DAT_00744368 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bf818;
  DAT_0074436c = -1;
  bVar2 = DAT_006bf818;
  while (bVar2 != 0) {
    DAT_0074436c = DAT_0074436c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_5ZIGEN";
  DAT_00744370 = -1;
  bVar2 = s_DECAL_ICON_5ZIGEN_006bf820[0];
  while (bVar2 != 0) {
    DAT_00744370 = DAT_00744370 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744374 = &DAT_006bf808;
  DAT_00744378 = 1;
  puVar6 = &DAT_006c8c9c;
  DAT_0074437c = -1;
  uVar3 = 0x41;
  do {
    DAT_0074437c = DAT_0074437c * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  pcVar5 = "ABS_DYNAMICS";
  DAT_00744380 = -1;
  bVar2 = s_ABS_DYNAMICS_006bf834[0];
  while (bVar2 != 0) {
    DAT_00744380 = DAT_00744380 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "ABSDYNAMICS";
  DAT_00744384 = -1;
  bVar2 = s_ABSDYNAMICS_006bf844[0];
  while (bVar2 != 0) {
    DAT_00744384 = DAT_00744384 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_ABS";
  DAT_00744388 = -1;
  bVar2 = s_DECAL_ICON_ABS_006bf850[0];
  while (bVar2 != 0) {
    DAT_00744388 = DAT_00744388 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074438c = "ABS DYNAMICS";
  _DAT_00744390 = 2;
  puVar4 = &DAT_006bf870;
  _DAT_00744394 = -1;
  bVar2 = DAT_006bf870;
  while (bVar2 != 0) {
    _DAT_00744394 = _DAT_00744394 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "ADVANCEDCLUTCH";
  _DAT_00744398 = -1;
  bVar2 = s_ADVANCEDCLUTCH_006bf874[0];
  while (bVar2 != 0) {
    _DAT_00744398 = _DAT_00744398 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074439c = 0xffffffff;
  pcVar5 = "DECAL_ICON_ACT";
  _DAT_007443a0 = -1;
  bVar2 = s_DECAL_ICON_ACT_006bf884[0];
  while (bVar2 != 0) {
    _DAT_007443a0 = _DAT_007443a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443a4 = &DAT_006bf870;
  _DAT_007443a8 = 3;
  puVar4 = &DAT_006bf894;
  _DAT_007443ac = -1;
  bVar2 = DAT_006bf894;
  while (bVar2 != 0) {
    _DAT_007443ac = _DAT_007443ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443b0 = 0xffffffff;
  _DAT_007443b4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_AEM";
  _DAT_007443b8 = -1;
  bVar2 = s_DECAL_ICON_AEM_006bf898[0];
  while (bVar2 != 0) {
    _DAT_007443b8 = _DAT_007443b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443bc = &DAT_006bf894;
  _DAT_007443c0 = 4;
  pcVar5 = "ALPINE";
  _DAT_007443c4 = -1;
  bVar2 = s_ALPINE_006bf8a8[0];
  while (bVar2 != 0) {
    _DAT_007443c4 = _DAT_007443c4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443c8 = 0xffffffff;
  _DAT_007443cc = 0xffffffff;
  pcVar5 = "DECAL_ICON_ALPINE";
  _DAT_007443d0 = -1;
  bVar2 = s_DECAL_ICON_ALPINE_006bf8b0[0];
  while (bVar2 != 0) {
    _DAT_007443d0 = _DAT_007443d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443d4 = "ALPINE";
  _DAT_007443d8 = 5;
  puVar4 = &DAT_006bf8c4;
  _DAT_007443dc = -1;
  bVar2 = DAT_006bf8c4;
  while (bVar2 != 0) {
    _DAT_007443dc = _DAT_007443dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443e0 = 0xffffffff;
  _DAT_007443e4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_APEX";
  _DAT_007443e8 = -1;
  bVar2 = s_DECAL_ICON_APEX_006bf8cc[0];
  while (bVar2 != 0) {
    _DAT_007443e8 = _DAT_007443e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443ec = &DAT_006bf8c4;
  _DAT_007443f0 = 6;
  puVar4 = &DAT_006bf8dc;
  _DAT_007443f4 = -1;
  bVar2 = DAT_006bf8dc;
  while (bVar2 != 0) {
    _DAT_007443f4 = _DAT_007443f4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007443f8 = 0xffffffff;
  _DAT_007443fc = 0xffffffff;
  pcVar5 = "DECAL_ICON_APEXI";
  _DAT_00744400 = -1;
  bVar2 = s_DECAL_ICON_APEXI_006bf8e4[0];
  while (bVar2 != 0) {
    _DAT_00744400 = _DAT_00744400 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744404 = &DAT_006bf8dc;
  _DAT_00744408 = 7;
  pcVar5 = "AROSPEED";
  _DAT_0074440c = -1;
  bVar2 = s_AROSPEED_006bf8f8[0];
  while (bVar2 != 0) {
    _DAT_0074440c = _DAT_0074440c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744410 = 0xffffffff;
  _DAT_00744414 = 0xffffffff;
  pcVar5 = "DECAL_ICON_AROSPEED";
  _DAT_00744418 = -1;
  bVar2 = s_DECAL_ICON_AROSPEED_006bf904[0];
  while (bVar2 != 0) {
    _DAT_00744418 = _DAT_00744418 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074441c = "AROSPEED";
  _DAT_00744420 = 8;
  pcVar5 = "AUDIOBAHN";
  _DAT_00744424 = -1;
  bVar2 = s_AUDIOBAHN_006bf918[0];
  while (bVar2 != 0) {
    _DAT_00744424 = _DAT_00744424 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744428 = 0xffffffff;
  _DAT_0074442c = 0xffffffff;
  pcVar5 = "DECAL_ICON_AUDIOBAHN";
  _DAT_00744430 = -1;
  bVar2 = s_DECAL_ICON_AUDIOBAHN_006bf924[0];
  while (bVar2 != 0) {
    _DAT_00744430 = _DAT_00744430 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744434 = "AUDIOBAHN";
  _DAT_00744438 = 9;
  puVar4 = &DAT_006bf93c;
  _DAT_0074443c = -1;
  bVar2 = DAT_006bf93c;
  while (bVar2 != 0) {
    _DAT_0074443c = _DAT_0074443c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744440 = 0xffffffff;
  _DAT_00744444 = 0xffffffff;
  pcVar5 = "DECAL_ICON_BBS";
  _DAT_00744448 = -1;
  bVar2 = s_DECAL_ICON_BBS_006bf940[0];
  while (bVar2 != 0) {
    _DAT_00744448 = _DAT_00744448 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074444c = &DAT_006bf93c;
  _DAT_00744450 = 10;
  pcVar5 = "BILSTEIN";
  _DAT_00744454 = -1;
  bVar2 = s_BILSTEIN_006bf950[0];
  while (bVar2 != 0) {
    _DAT_00744454 = _DAT_00744454 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744458 = 0xffffffff;
  _DAT_0074445c = 0xffffffff;
  pcVar5 = "DECAL_ICON_BILSTEIN";
  _DAT_00744460 = -1;
  bVar2 = s_DECAL_ICON_BILSTEIN_006bf95c[0];
  while (bVar2 != 0) {
    _DAT_00744460 = _DAT_00744460 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744464 = "BILSTEIN";
  _DAT_00744468 = 0xb;
  pcVar5 = "BORLA";
  _DAT_0074446c = -1;
  bVar2 = s_BORLA_006bf970[0];
  while (bVar2 != 0) {
    _DAT_0074446c = _DAT_0074446c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744470 = 0xffffffff;
  _DAT_00744474 = 0xffffffff;
  pcVar5 = "DECAL_ICON_BORLA";
  _DAT_00744478 = -1;
  bVar2 = s_DECAL_ICON_BORLA_006bf978[0];
  while (bVar2 != 0) {
    _DAT_00744478 = _DAT_00744478 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074447c = "BORLA";
  _DAT_00744480 = 0xc;
  pcVar5 = "BREMBO";
  _DAT_00744484 = -1;
  bVar2 = s_BREMBO_006bf98c[0];
  while (bVar2 != 0) {
    _DAT_00744484 = _DAT_00744484 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744488 = 0xffffffff;
  _DAT_0074448c = 0xffffffff;
  pcVar5 = "DECAL_ICON_BREMBO";
  _DAT_00744490 = -1;
  bVar2 = s_DECAL_ICON_BREMBO_006bf994[0];
  while (bVar2 != 0) {
    _DAT_00744490 = _DAT_00744490 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744494 = "BREMBO";
  _DAT_00744498 = 0xd;
  pcVar5 = "CLUTCHMASTERS";
  _DAT_0074449c = -1;
  bVar2 = s_CLUTCHMASTERS_006bf9a8[0];
  while (bVar2 != 0) {
    _DAT_0074449c = _DAT_0074449c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444a0 = 0xffffffff;
  _DAT_007444a4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_CLUTCHMASTERS";
  _DAT_007444a8 = -1;
  bVar2 = s_DECAL_ICON_CLUTCHMASTERS_006bf9b8[0];
  while (bVar2 != 0) {
    _DAT_007444a8 = _DAT_007444a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444ac = "CLUTCHMASTERS";
  _DAT_007444b0 = 0xe;
  pcVar5 = "RACINGHART";
  _DAT_007444b4 = -1;
  bVar2 = s_RACINGHART_006bf9d4[0];
  while (bVar2 != 0) {
    _DAT_007444b4 = _DAT_007444b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "RACING_HART";
  _DAT_007444b8 = -1;
  bVar2 = s_RACING_HART_006bf9e0[0];
  while (bVar2 != 0) {
    _DAT_007444b8 = _DAT_007444b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "RacingHart";
  _DAT_007444bc = -1;
  bVar2 = s_RacingHart_006bf9ec[0];
  while (bVar2 != 0) {
    _DAT_007444bc = _DAT_007444bc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_RACINGHART";
  _DAT_007444c0 = -1;
  bVar2 = s_DECAL_ICON_RACINGHART_006bf9f8[0];
  while (bVar2 != 0) {
    _DAT_007444c0 = _DAT_007444c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444c4 = "RACINGHART";
  _DAT_007444c8 = 0xf;
  puVar4 = &DAT_006bfa10;
  _DAT_007444cc = -1;
  bVar2 = DAT_006bfa10;
  while (bVar2 != 0) {
    _DAT_007444cc = _DAT_007444cc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DC_SPORTS";
  _DAT_007444d0 = -1;
  bVar2 = s_DC_SPORTS_006bfa14[0];
  while (bVar2 != 0) {
    _DAT_007444d0 = _DAT_007444d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DCSPORTS";
  _DAT_007444d4 = -1;
  bVar2 = s_DCSPORTS_006bfa20[0];
  while (bVar2 != 0) {
    _DAT_007444d4 = _DAT_007444d4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_DC";
  _DAT_007444d8 = -1;
  bVar2 = s_DECAL_ICON_DC_006bfa2c[0];
  while (bVar2 != 0) {
    _DAT_007444d8 = _DAT_007444d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444dc = "DCSPORTS";
  _DAT_007444e0 = 0x10;
  pcVar5 = "EIBACH";
  _DAT_007444e4 = -1;
  bVar2 = s_EIBACH_006bfa3c[0];
  while (bVar2 != 0) {
    _DAT_007444e4 = _DAT_007444e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "EIBACHSPRINGS";
  _DAT_007444e8 = -1;
  bVar2 = s_EIBACHSPRINGS_006bfa44[0];
  while (bVar2 != 0) {
    _DAT_007444e8 = _DAT_007444e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444ec = 0xffffffff;
  pcVar5 = "DECAL_ICON_EIBACH";
  _DAT_007444f0 = -1;
  bVar2 = s_DECAL_ICON_EIBACH_006bfa54[0];
  while (bVar2 != 0) {
    _DAT_007444f0 = _DAT_007444f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007444f4 = "EIBACH";
  _DAT_007444f8 = 0x11;
  puVar4 = &DAT_006bfa68;
  _DAT_007444fc = -1;
  bVar2 = DAT_006bfa68;
  while (bVar2 != 0) {
    _DAT_007444fc = _DAT_007444fc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744500 = 0xffffffff;
  _DAT_00744504 = 0xffffffff;
  pcVar5 = "DECAL_ICON_ENKEI";
  _DAT_00744508 = -1;
  bVar2 = s_DECAL_ICON_ENKEI_006bfa70[0];
  while (bVar2 != 0) {
    _DAT_00744508 = _DAT_00744508 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074450c = &DAT_006bfa68;
  _DAT_00744510 = 0x12;
  pcVar5 = "EXTREMEDIMENSIONS";
  _DAT_00744514 = -1;
  bVar2 = s_EXTREMEDIMENSIONS_006bfa84[0];
  while (bVar2 != 0) {
    _DAT_00744514 = _DAT_00744514 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "EXTRDIMENSION";
  _DAT_00744518 = -1;
  bVar2 = s_EXTRDIMENSION_006bfa98[0];
  while (bVar2 != 0) {
    _DAT_00744518 = _DAT_00744518 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "EXTREMEDIMENSION";
  _DAT_0074451c = -1;
  uVar3 = 0x45;
  do {
    _DAT_0074451c = _DAT_0074451c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  pcVar5 = "DECAL_ICON_EXTREMEDIMENSIONS";
  _DAT_00744520 = -1;
  bVar2 = s_DECAL_ICON_EXTREMEDIMENSIONS_006bfaa8[0];
  while (bVar2 != 0) {
    _DAT_00744520 = _DAT_00744520 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744524 = "EXTREMEDIMENSIONS";
  _DAT_00744528 = 0x13;
  pcVar5 = "GENERA";
  _DAT_0074452c = -1;
  bVar2 = s_GENERA_006bfac8[0];
  while (bVar2 != 0) {
    _DAT_0074452c = _DAT_0074452c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfad0;
  _DAT_00744530 = -1;
  bVar2 = DAT_006bfad0;
  while (bVar2 != 0) {
    _DAT_00744530 = _DAT_00744530 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744534 = 0xffffffff;
  pcVar5 = "DECAL_ICON_TYC";
  _DAT_00744538 = -1;
  bVar2 = s_DECAL_ICON_TYC_006bfad4[0];
  while (bVar2 != 0) {
    _DAT_00744538 = _DAT_00744538 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074453c = "GENERA (TYC)";
  _DAT_00744540 = 0x14;
  pcVar5 = "GREDDY";
  _DAT_00744544 = -1;
  bVar2 = s_GREDDY_006bfaf4[0];
  while (bVar2 != 0) {
    _DAT_00744544 = _DAT_00744544 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744548 = 0xffffffff;
  _DAT_0074454c = 0xffffffff;
  pcVar5 = "DECAL_ICON_GREDDY";
  _DAT_00744550 = -1;
  bVar2 = s_DECAL_ICON_GREDDY_006bfafc[0];
  while (bVar2 != 0) {
    _DAT_00744550 = _DAT_00744550 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744554 = "GREDDY";
  _DAT_00744558 = 0x15;
  pcVar5 = "HENSHIN";
  _DAT_0074455c = -1;
  bVar2 = s_HENSHIN_006bfb10[0];
  while (bVar2 != 0) {
    _DAT_0074455c = _DAT_0074455c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "HENSHINAUTO";
  _DAT_00744560 = -1;
  bVar2 = s_HENSHINAUTO_006bfb18[0];
  while (bVar2 != 0) {
    _DAT_00744560 = _DAT_00744560 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744564 = 0xffffffff;
  pcVar5 = "DECAL_ICON_HENSHIN";
  _DAT_00744568 = -1;
  bVar2 = s_DECAL_ICON_HENSHIN_006bfb24[0];
  while (bVar2 != 0) {
    _DAT_00744568 = _DAT_00744568 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074456c = "HENSHIN_AUTO";
  _DAT_00744570 = 0x16;
  puVar4 = &DAT_006bfb48;
  _DAT_00744574 = -1;
  bVar2 = DAT_006bfb48;
  while (bVar2 != 0) {
    _DAT_00744574 = _DAT_00744574 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744578 = 0xffffffff;
  _DAT_0074457c = 0xffffffff;
  pcVar5 = "DECAL_ICON_HKS";
  _DAT_00744580 = -1;
  bVar2 = s_DECAL_ICON_HKS_006bfb4c[0];
  while (bVar2 != 0) {
    _DAT_00744580 = _DAT_00744580 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744584 = &DAT_006bfb48;
  _DAT_00744588 = 0x17;
  pcVar5 = "HOLLEY";
  _DAT_0074458c = -1;
  bVar2 = s_HOLLEY_006bfb5c[0];
  while (bVar2 != 0) {
    _DAT_0074458c = _DAT_0074458c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006ba7a4;
  _DAT_00744590 = -1;
  bVar2 = DAT_006ba7a4;
  while (bVar2 != 0) {
    _DAT_00744590 = _DAT_00744590 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744594 = 0xffffffff;
  pcVar5 = "DECAL_ICON_NOS";
  _DAT_00744598 = -1;
  bVar2 = s_DECAL_ICON_NOS_006bfb64[0];
  while (bVar2 != 0) {
    _DAT_00744598 = _DAT_00744598 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074459c = "HOLLEY";
  _DAT_007445a0 = 0x18;
  puVar4 = &DAT_006bfb74;
  _DAT_007445a4 = -1;
  bVar2 = DAT_006bfb74;
  while (bVar2 != 0) {
    _DAT_007445a4 = _DAT_007445a4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "HPRACING";
  _DAT_007445a8 = -1;
  bVar2 = s_HPRACING_006bfb78[0];
  while (bVar2 != 0) {
    _DAT_007445a8 = _DAT_007445a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "HP_RACING";
  _DAT_007445ac = -1;
  bVar2 = s_HP_RACING_006bfb84[0];
  while (bVar2 != 0) {
    _DAT_007445ac = _DAT_007445ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_HPRACING";
  _DAT_007445b0 = -1;
  bVar2 = s_DECAL_ICON_HPRACING_006bfb90[0];
  while (bVar2 != 0) {
    _DAT_007445b0 = _DAT_007445b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445b4 = &DAT_006bfb74;
  _DAT_007445b8 = 0x19;
  puVar4 = &DAT_006bfba4;
  _DAT_007445bc = -1;
  bVar2 = DAT_006bfba4;
  while (bVar2 != 0) {
    _DAT_007445bc = _DAT_007445bc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445c0 = 0xffffffff;
  _DAT_007445c4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_HANDR";
  _DAT_007445c8 = -1;
  bVar2 = s_DECAL_ICON_HANDR_006bfba8[0];
  while (bVar2 != 0) {
    _DAT_007445c8 = _DAT_007445c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445cc = &DAT_006bfba4;
  _DAT_007445d0 = 0x1a;
  puVar4 = &DAT_006bfbbc;
  _DAT_007445d4 = -1;
  bVar2 = DAT_006bfbbc;
  while (bVar2 != 0) {
    _DAT_007445d4 = _DAT_007445d4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445d8 = 0xffffffff;
  _DAT_007445dc = 0xffffffff;
  pcVar5 = "DECAL_ICON_INJEN";
  _DAT_007445e0 = -1;
  bVar2 = s_DECAL_ICON_INJEN_006bfbc4[0];
  while (bVar2 != 0) {
    _DAT_007445e0 = _DAT_007445e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445e4 = &DAT_006bfbbc;
  _DAT_007445e8 = 0x1b;
  pcVar5 = "JACKSONRACING";
  _DAT_007445ec = -1;
  bVar2 = s_JACKSONRACING_006bfbd8[0];
  while (bVar2 != 0) {
    _DAT_007445ec = _DAT_007445ec * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "JACKSON_RACING";
  _DAT_007445f0 = -1;
  bVar2 = s_JACKSON_RACING_006bfbe8[0];
  while (bVar2 != 0) {
    _DAT_007445f0 = _DAT_007445f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "JACKSON";
  _DAT_007445f4 = -1;
  bVar2 = s_JACKSON_006bfbf8[0];
  while (bVar2 != 0) {
    _DAT_007445f4 = _DAT_007445f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = -1;
  bVar2 = s_DECAL_ICON_JACKSON_006bfc00[0];
  while (bVar2 != 0) {
    _DAT_007445f8 = _DAT_007445f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar4 = &DAT_006bfc14;
  _DAT_00744604 = -1;
  bVar2 = DAT_006bfc14;
  while (bVar2 != 0) {
    _DAT_00744604 = _DAT_00744604 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "JSPAMERICA";
  _DAT_00744608 = -1;
  bVar2 = s_JSPAMERICA_006bfc18[0];
  while (bVar2 != 0) {
    _DAT_00744608 = _DAT_00744608 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074460c = 0xffffffff;
  pcVar5 = "DECAL_ICON_JSP";
  _DAT_00744610 = -1;
  bVar2 = s_DECAL_ICON_JSP_006bfc24[0];
  while (bVar2 != 0) {
    _DAT_00744610 = _DAT_00744610 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar4 = &DAT_006bfc34;
  _DAT_0074461c = -1;
  bVar2 = DAT_006bfc34;
  while (bVar2 != 0) {
    _DAT_0074461c = _DAT_0074461c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744620 = 0xffffffff;
  _DAT_00744624 = 0xffffffff;
  _DAT_00744628 = 0xffffffff;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar5 = "KENWOOD";
  _DAT_00744634 = -1;
  bVar2 = s_KENWOOD_006bfc38[0];
  while (bVar2 != 0) {
    _DAT_00744634 = _DAT_00744634 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744638 = 0xffffffff;
  _DAT_0074463c = 0xffffffff;
  pcVar5 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = -1;
  bVar2 = s_DECAL_ICON_KENWOOD_006bfc40[0];
  while (bVar2 != 0) {
    _DAT_00744640 = _DAT_00744640 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar5 = "KEYSTONE";
  _DAT_0074464c = -1;
  bVar2 = s_KEYSTONE_006bfc54[0];
  while (bVar2 != 0) {
    _DAT_0074464c = _DAT_0074464c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744650 = 0xffffffff;
  _DAT_00744654 = 0xffffffff;
  _DAT_00744658 = 0xffffffff;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar4 = &DAT_006bfc60;
  _DAT_00744664 = -1;
  bVar2 = DAT_006bfc60;
  while (bVar2 != 0) {
    _DAT_00744664 = _DAT_00744664 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744668 = 0xffffffff;
  _DAT_0074466c = 0xffffffff;
  pcVar5 = "DECAL_ICON_KONI";
  _DAT_00744670 = -1;
  bVar2 = s_DECAL_ICON_KONI_006bfc68[0];
  while (bVar2 != 0) {
    _DAT_00744670 = _DAT_00744670 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar4 = &DAT_006bfc78;
  _DAT_0074467c = -1;
  bVar2 = DAT_006bfc78;
  while (bVar2 != 0) {
    _DAT_0074467c = _DAT_0074467c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744680 = 0xffffffff;
  _DAT_00744684 = 0xffffffff;
  pcVar5 = "DECAL_ICON_KONIG";
  _DAT_00744688 = -1;
  bVar2 = s_DECAL_ICON_KONIG_006bfc80[0];
  while (bVar2 != 0) {
    _DAT_00744688 = _DAT_00744688 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar4 = &DAT_006bfc94;
  _DAT_00744694 = -1;
  bVar2 = DAT_006bfc94;
  while (bVar2 != 0) {
    _DAT_00744694 = _DAT_00744694 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfc9c;
  _DAT_00744698 = -1;
  bVar2 = DAT_006bfc9c;
  while (bVar2 != 0) {
    _DAT_00744698 = _DAT_00744698 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074469c = 0xffffffff;
  _DAT_007446a0 = 0xffffffff;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar4 = &DAT_006bfca4;
  _DAT_007446ac = -1;
  bVar2 = DAT_006bfca4;
  while (bVar2 != 0) {
    _DAT_007446ac = _DAT_007446ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "KVRPERFORMANCE";
  _DAT_007446b0 = -1;
  bVar2 = s_KVRPERFORMANCE_006bfca8[0];
  while (bVar2 != 0) {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446b4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_KVR";
  _DAT_007446b8 = -1;
  bVar2 = s_DECAL_ICON_KVR_006bfcb8[0];
  while (bVar2 != 0) {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar4 = &DAT_006bfcc8;
  _DAT_007446c4 = -1;
  bVar2 = DAT_006bfcc8;
  while (bVar2 != 0) {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446c8 = 0xffffffff;
  _DAT_007446cc = 0xffffffff;
  pcVar5 = "DECAL_ICON_KYB";
  _DAT_007446d0 = -1;
  bVar2 = s_DECAL_ICON_KYB_006bfccc[0];
  while (bVar2 != 0) {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar4 = &DAT_006bfcdc;
  _DAT_007446dc = -1;
  bVar2 = DAT_006bfcdc;
  while (bVar2 != 0) {
    _DAT_007446dc = _DAT_007446dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446e0 = 0xffffffff;
  _DAT_007446e4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = -1;
  bVar2 = s_DECAL_ICON_MOMO_006bfce4[0];
  while (bVar2 != 0) {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar5 = "NEUSPEED";
  _DAT_007446f4 = -1;
  bVar2 = s_NEUSPEED_006bfcf4[0];
  while (bVar2 != 0) {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446f8 = 0xffffffff;
  _DAT_007446fc = 0xffffffff;
  pcVar5 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = -1;
  bVar2 = s_DECAL_ICON_NEUSPEED_006bfd00[0];
  while (bVar2 != 0) {
    _DAT_00744700 = _DAT_00744700 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar5 = "NITROUS_EXPRESS";
  _DAT_0074470c = -1;
  bVar2 = s_NITROUS_EXPRESS_006bfd14[0];
  while (bVar2 != 0) {
    _DAT_0074470c = _DAT_0074470c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfd24;
  _DAT_00744710 = -1;
  bVar2 = DAT_006bfd24;
  while (bVar2 != 0) {
    _DAT_00744710 = _DAT_00744710 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "NITROUSEXPRESS";
  _DAT_00744714 = -1;
  bVar2 = s_NITROUSEXPRESS_006bfd28[0];
  while (bVar2 != 0) {
    _DAT_00744714 = _DAT_00744714 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_NX";
  _DAT_00744718 = -1;
  bVar2 = s_DECAL_ICON_NX_006bfd38[0];
  while (bVar2 != 0) {
    _DAT_00744718 = _DAT_00744718 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar4 = &DAT_006bfd48;
  _DAT_00744724 = -1;
  bVar2 = DAT_006bfd48;
  while (bVar2 != 0) {
    _DAT_00744724 = _DAT_00744724 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744728 = 0xffffffff;
  _DAT_0074472c = 0xffffffff;
  pcVar5 = "DECAL_ICON_OZ";
  _DAT_00744730 = -1;
  bVar2 = s_DECAL_ICON_OZ_006bfd4c[0];
  while (bVar2 != 0) {
    _DAT_00744730 = _DAT_00744730 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar6 = &DAT_006c0ca0;
  _DAT_0074473c = -1;
  uVar3 = 0x50;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744740 = 0xffffffff;
  _DAT_00744744 = 0xffffffff;
  pcVar5 = "DECAL_ICON_PIAA";
  _DAT_00744748 = -1;
  bVar2 = s_DECAL_ICON_PIAA_006bfd5c[0];
  while (bVar2 != 0) {
    _DAT_00744748 = _DAT_00744748 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar5 = "PLASMAGLOW";
  _DAT_00744754 = -1;
  bVar2 = s_PLASMAGLOW_006bfd6c[0];
  while (bVar2 != 0) {
    _DAT_00744754 = _DAT_00744754 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "PLASMA_GLOW";
  _DAT_00744758 = -1;
  bVar2 = s_PLASMA_GLOW_006bfd78[0];
  while (bVar2 != 0) {
    _DAT_00744758 = _DAT_00744758 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074475c = 0xffffffff;
  pcVar5 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = -1;
  bVar2 = s_DECAL_ICON_PLASMAGLOW_006bfd84[0];
  while (bVar2 != 0) {
    _DAT_00744760 = _DAT_00744760 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar5 = "SCORPION";
  _DAT_0074476c = -1;
  bVar2 = s_SCORPION_006bfd9c[0];
  while (bVar2 != 0) {
    _DAT_0074476c = _DAT_0074476c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744770 = 0xffffffff;
  _DAT_00744774 = 0xffffffff;
  pcVar5 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = -1;
  bVar2 = s_DECAL_ICON_SCORPION_006bfda8[0];
  while (bVar2 != 0) {
    _DAT_00744778 = _DAT_00744778 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar4 = &DAT_006bfdbc;
  _DAT_00744784 = -1;
  bVar2 = DAT_006bfdbc;
  while (bVar2 != 0) {
    _DAT_00744784 = _DAT_00744784 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744788 = 0xffffffff;
  _DAT_0074478c = 0xffffffff;
  pcVar5 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = -1;
  bVar2 = s_DECAL_ICON_SKUNK2_006bfdc4[0];
  while (bVar2 != 0) {
    _DAT_00744790 = _DAT_00744790 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar5 = "SPARCO";
  _DAT_0074479c = -1;
  uVar3 = 0x53;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447a0 = 0xffffffff;
  _DAT_007447a4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = -1;
  bVar2 = s_DECAL_ICON_SPARCO_006bfdd8[0];
  while (bVar2 != 0) {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar5 = "STILLEN";
  _DAT_007447b4 = -1;
  bVar2 = s_STILLEN_006bfdec[0];
  while (bVar2 != 0) {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447b8 = 0xffffffff;
  _DAT_007447bc = 0xffffffff;
  pcVar5 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = -1;
  bVar2 = s_DECAL_ICON_STILLEN_006bfdf4[0];
  while (bVar2 != 0) {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar5 = "STREET_GLOW";
  _DAT_007447cc = -1;
  bVar2 = s_STREET_GLOW_006bfe08[0];
  while (bVar2 != 0) {
    _DAT_007447cc = _DAT_007447cc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "STREETGLOW";
  _DAT_007447d0 = -1;
  bVar2 = s_STREETGLOW_006bfe14[0];
  while (bVar2 != 0) {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447d4 = 0xffffffff;
  pcVar5 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = -1;
  bVar2 = s_DECAL_ICON_STREETGLOW_006bfe20[0];
  while (bVar2 != 0) {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar5 = "TOUCAN";
  _DAT_007447e4 = -1;
  bVar2 = s_TOUCAN_006bfe38[0];
  while (bVar2 != 0) {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447e8 = 0xffffffff;
  _DAT_007447ec = 0xffffffff;
  _DAT_007447f0 = 0xffffffff;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar5 = "TOYOTIRES";
  _DAT_007447fc = -1;
  bVar2 = s_TOYOTIRES_006bfe40[0];
  while (bVar2 != 0) {
    _DAT_007447fc = _DAT_007447fc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "TOYO_TIRES";
  _DAT_00744800 = -1;
  bVar2 = s_TOYO_TIRES_006bfe4c[0];
  while (bVar2 != 0) {
    _DAT_00744800 = _DAT_00744800 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfe58;
  _DAT_00744804 = -1;
  bVar2 = DAT_006bfe58;
  while (bVar2 != 0) {
    _DAT_00744804 = _DAT_00744804 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_TOYO";
  _DAT_00744808 = -1;
  bVar2 = s_DECAL_ICON_TOYO_006bfe60[0];
  while (bVar2 != 0) {
    _DAT_00744808 = _DAT_00744808 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar5 = "TURBONETICS";
  _DAT_00744814 = -1;
  bVar2 = s_TURBONETICS_006bfe70[0];
  while (bVar2 != 0) {
    _DAT_00744814 = _DAT_00744814 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744818 = 0xffffffff;
  _DAT_0074481c = 0xffffffff;
  pcVar5 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = -1;
  bVar2 = s_DECAL_ICON_TURBONETICS_006bfe7c[0];
  while (bVar2 != 0) {
    _DAT_00744820 = _DAT_00744820 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar5 = "VENOM";
  _DAT_0074482c = -1;
  bVar2 = s_VENOM_006bfe94[0];
  while (bVar2 != 0) {
    _DAT_0074482c = _DAT_0074482c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744830 = 0xffffffff;
  _DAT_00744834 = 0xffffffff;
  pcVar5 = "VINYL_ICON_VENOM";
  _DAT_00744838 = -1;
  bVar2 = s_VINYL_ICON_VENOM_006bfe9c[0];
  while (bVar2 != 0) {
    _DAT_00744838 = _DAT_00744838 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar5 = "WILWOOD";
  _DAT_00744844 = -1;
  bVar2 = s_WILWOOD_006bfeb0[0];
  while (bVar2 != 0) {
    _DAT_00744844 = _DAT_00744844 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "WILLWOOD";
  _DAT_00744848 = -1;
  bVar2 = s_WILLWOOD_006bfeb8[0];
  while (bVar2 != 0) {
    _DAT_00744848 = _DAT_00744848 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074484c = 0xffffffff;
  pcVar5 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = -1;
  bVar2 = s_DECAL_ICON_WILWOOD_006bfec4[0];
  while (bVar2 != 0) {
    _DAT_00744850 = _DAT_00744850 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar5 = "WOLFRACE";
  _DAT_0074485c = -1;
  bVar2 = s_WOLFRACE_006bfed8[0];
  while (bVar2 != 0) {
    _DAT_0074485c = _DAT_0074485c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "WOLFRACEWHEELS";
  _DAT_00744860 = -1;
  bVar2 = s_WOLFRACEWHEELS_006bfee4[0];
  while (bVar2 != 0) {
    _DAT_00744860 = _DAT_00744860 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744864 = 0xffffffff;
  _DAT_00744868 = 0xffffffff;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar5 = "YOKOHAMA";
  _DAT_00744874 = -1;
  bVar2 = s_YOKOHAMA_006bfef4[0];
  while (bVar2 != 0) {
    _DAT_00744874 = _DAT_00744874 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744878 = 0xffffffff;
  _DAT_0074487c = 0xffffffff;
  pcVar5 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = -1;
  bVar2 = s_DECAL_ICON_YOKOHAMA_006bff00[0];
  while (bVar2 != 0) {
    _DAT_00744880 = _DAT_00744880 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar5 = "ACURA";
  _DAT_0074488c = -1;
  bVar2 = s_ACURA_006bff14[0];
  while (bVar2 != 0) {
    _DAT_0074488c = _DAT_0074488c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744890 = 0xffffffff;
  _DAT_00744894 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_ACURA_006bff1c[0];
  while (bVar2 != 0) {
    _DAT_00744898 = _DAT_00744898 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar5 = "DODGE";
  _DAT_007448a4 = -1;
  bVar2 = s_DODGE_006bff3c[0];
  while (bVar2 != 0) {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448a8 = 0xffffffff;
  _DAT_007448ac = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_DODGE_006bff44[0];
  while (bVar2 != 0) {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar4 = &DAT_006bff64;
  _DAT_007448bc = -1;
  bVar2 = DAT_006bff64;
  while (bVar2 != 0) {
    _DAT_007448bc = _DAT_007448bc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448c0 = 0xffffffff;
  _DAT_007448c4 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_FORD_006bff6c[0];
  while (bVar2 != 0) {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar5 = "HONDA";
  _DAT_007448d4 = -1;
  uVar3 = 0x48;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448d8 = 0xffffffff;
  _DAT_007448dc = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_HONDA_006bff88[0];
  while (bVar2 != 0) {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar5 = "HYUNDAI";
  _DAT_007448ec = -1;
  uVar3 = 0x48;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448f0 = 0xffffffff;
  _DAT_007448f4 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_HYUNDAI_006bffa8[0];
  while (bVar2 != 0) {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar5 = "MITSUBISHI";
  _DAT_00744904 = -1;
  bVar2 = s_MITSUBISHI_006bffc8[0];
  while (bVar2 != 0) {
    _DAT_00744904 = _DAT_00744904 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744908 = 0xffffffff;
  _DAT_0074490c = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_MITSUBISH_006bffd4[0];
  while (bVar2 != 0) {
    _DAT_00744910 = _DAT_00744910 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar4 = &DAT_006bfff8;
  _DAT_0074491c = -1;
  bVar2 = DAT_006bfff8;
  while (bVar2 != 0) {
    _DAT_0074491c = _DAT_0074491c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744920 = 0xffffffff;
  _DAT_00744924 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_MAZDA_006c0000[0];
  while (bVar2 != 0) {
    _DAT_00744928 = _DAT_00744928 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar5 = "NISSAN";
  _DAT_00744934 = -1;
  bVar2 = s_NISSAN_006c0020[0];
  while (bVar2 != 0) {
    _DAT_00744934 = _DAT_00744934 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744938 = 0xffffffff;
  _DAT_0074493c = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_NISSAN_006c0028[0];
  while (bVar2 != 0) {
    _DAT_00744940 = _DAT_00744940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar5 = "PEUGEOT";
  _DAT_0074494c = -1;
  bVar2 = s_PEUGEOT_006c0048[0];
  while (bVar2 != 0) {
    _DAT_0074494c = _DAT_0074494c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744950 = 0xffffffff;
  _DAT_00744954 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_PEUGEOT_006c0050[0];
  while (bVar2 != 0) {
    _DAT_00744958 = _DAT_00744958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar4 = &DAT_006c0070;
  _DAT_00744964 = -1;
  bVar2 = DAT_006c0070;
  while (bVar2 != 0) {
    _DAT_00744964 = _DAT_00744964 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744968 = 0xffffffff;
  _DAT_0074496c = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_SUBARU_006c0078[0];
  while (bVar2 != 0) {
    _DAT_00744970 = _DAT_00744970 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar5 = "VOLKSWAGEN";
  _DAT_0074497c = -1;
  bVar2 = s_VOLKSWAGEN_006c0098[0];
  while (bVar2 != 0) {
    _DAT_0074497c = _DAT_0074497c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744980 = 0xffffffff;
  _DAT_00744984 = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_VOLKSWAGE_006c00a4[0];
  while (bVar2 != 0) {
    _DAT_00744988 = _DAT_00744988 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar4 = &DAT_006c00c8;
  _DAT_00744994 = -1;
  bVar2 = DAT_006c00c8;
  while (bVar2 != 0) {
    _DAT_00744994 = _DAT_00744994 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744998 = 0xffffffff;
  _DAT_0074499c = 0xffffffff;
  pcVar5 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = -1;
  bVar2 = s_CARSELECT_MANUFACTURER_TOYOTA_006c00d0[0];
  while (bVar2 != 0) {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar5 = "EUROLITE";
  _DAT_007449ac = -1;
  bVar2 = s_EUROLITE_006c00f0[0];
  while (bVar2 != 0) {
    _DAT_007449ac = _DAT_007449ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b0 = 0xffffffff;
  _DAT_007449b4 = 0xffffffff;
  _DAT_007449b8 = -1;
  pcVar5 = "DECAL_ICON_EUROLITE";
  bVar2 = s_DECAL_ICON_EUROLITE_006c00fc[0];
  while (bVar2 != 0) {
    _DAT_007449b8 = _DAT_007449b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449bc = "EUROLITE";
  return;
}


// 00690000 FUN_00690000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690000(byte param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  uint uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  int unaff_EDI;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  _DAT_007445ec = in_EAX;
  pcVar4 = "JACKSON_RACING";
  _DAT_007445f0 = unaff_EDI;
  bVar2 = s_JACKSON_RACING_006bfbe8[0];
  while (bVar2 != 0) {
    _DAT_007445f0 = _DAT_007445f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "JACKSON";
  _DAT_007445f4 = unaff_EDI;
  bVar2 = s_JACKSON_006bfbf8[0];
  while (bVar2 != 0) {
    _DAT_007445f4 = _DAT_007445f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_JACKSON_006bfc00[0];
  while (bVar2 != 0) {
    _DAT_007445f8 = _DAT_007445f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar5 = &DAT_006bfc14;
  _DAT_00744604 = unaff_EDI;
  bVar2 = DAT_006bfc14;
  while (bVar2 != 0) {
    _DAT_00744604 = _DAT_00744604 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "JSPAMERICA";
  _DAT_00744608 = unaff_EDI;
  bVar2 = s_JSPAMERICA_006bfc18[0];
  while (bVar2 != 0) {
    _DAT_00744608 = _DAT_00744608 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074460c = unaff_EDI;
  pcVar4 = "DECAL_ICON_JSP";
  _DAT_00744610 = unaff_EDI;
  bVar2 = s_DECAL_ICON_JSP_006bfc24[0];
  while (bVar2 != 0) {
    _DAT_00744610 = _DAT_00744610 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar5 = &DAT_006bfc34;
  _DAT_0074461c = unaff_EDI;
  bVar2 = DAT_006bfc34;
  while (bVar2 != 0) {
    _DAT_0074461c = _DAT_0074461c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744620 = unaff_EDI;
  _DAT_00744624 = unaff_EDI;
  _DAT_00744628 = unaff_EDI;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar4 = "KENWOOD";
  _DAT_00744634 = unaff_EDI;
  bVar2 = s_KENWOOD_006bfc38[0];
  while (bVar2 != 0) {
    _DAT_00744634 = _DAT_00744634 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744638 = unaff_EDI;
  _DAT_0074463c = unaff_EDI;
  pcVar4 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KENWOOD_006bfc40[0];
  while (bVar2 != 0) {
    _DAT_00744640 = _DAT_00744640 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar4 = "KEYSTONE";
  _DAT_0074464c = unaff_EDI;
  bVar2 = s_KEYSTONE_006bfc54[0];
  while (bVar2 != 0) {
    _DAT_0074464c = _DAT_0074464c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar5 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  bVar2 = DAT_006bfc60;
  while (bVar2 != 0) {
    _DAT_00744664 = _DAT_00744664 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONI_006bfc68[0];
  while (bVar2 != 0) {
    _DAT_00744670 = _DAT_00744670 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar5 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  bVar2 = DAT_006bfc78;
  while (bVar2 != 0) {
    _DAT_0074467c = _DAT_0074467c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONIG_006bfc80[0];
  while (bVar2 != 0) {
    _DAT_00744688 = _DAT_00744688 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar5 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  bVar2 = DAT_006bfc94;
  while (bVar2 != 0) {
    _DAT_00744694 = _DAT_00744694 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  bVar2 = DAT_006bfc9c;
  while (bVar2 != 0) {
    _DAT_00744698 = _DAT_00744698 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar5 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  bVar2 = DAT_006bfca4;
  while (bVar2 != 0) {
    _DAT_007446ac = _DAT_007446ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  bVar2 = s_KVRPERFORMANCE_006bfca8[0];
  while (bVar2 != 0) {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KVR_006bfcb8[0];
  while (bVar2 != 0) {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar5 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  bVar2 = DAT_006bfcc8;
  while (bVar2 != 0) {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar4 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KYB_006bfccc[0];
  while (bVar2 != 0) {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar5 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  bVar2 = DAT_006bfcdc;
  while (bVar2 != 0) {
    _DAT_007446dc = _DAT_007446dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_MOMO_006bfce4[0];
  while (bVar2 != 0) {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar4 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  bVar2 = s_NEUSPEED_006bfcf4[0];
  while (bVar2 != 0) {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar4 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NEUSPEED_006bfd00[0];
  while (bVar2 != 0) {
    _DAT_00744700 = _DAT_00744700 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar4 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  bVar2 = s_NITROUS_EXPRESS_006bfd14[0];
  while (bVar2 != 0) {
    _DAT_0074470c = _DAT_0074470c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  bVar2 = DAT_006bfd24;
  while (bVar2 != 0) {
    _DAT_00744710 = _DAT_00744710 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  bVar2 = s_NITROUSEXPRESS_006bfd28[0];
  while (bVar2 != 0) {
    _DAT_00744714 = _DAT_00744714 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NX_006bfd38[0];
  while (bVar2 != 0) {
    _DAT_00744718 = _DAT_00744718 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar5 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  bVar2 = DAT_006bfd48;
  while (bVar2 != 0) {
    _DAT_00744724 = _DAT_00744724 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar4 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  bVar2 = s_DECAL_ICON_OZ_006bfd4c[0];
  while (bVar2 != 0) {
    _DAT_00744730 = _DAT_00744730 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar6 = &DAT_006c0ca0;
  uVar3 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar4 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PIAA_006bfd5c[0];
  while (bVar2 != 0) {
    _DAT_00744748 = _DAT_00744748 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar4 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  bVar2 = s_PLASMAGLOW_006bfd6c[0];
  while (bVar2 != 0) {
    _DAT_00744754 = _DAT_00744754 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  bVar2 = s_PLASMA_GLOW_006bfd78[0];
  while (bVar2 != 0) {
    _DAT_00744758 = _DAT_00744758 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074475c = unaff_EDI;
  pcVar4 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PLASMAGLOW_006bfd84[0];
  while (bVar2 != 0) {
    _DAT_00744760 = _DAT_00744760 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar4 = "SCORPION";
  _DAT_0074476c = unaff_EDI;
  bVar2 = s_SCORPION_006bfd9c[0];
  while (bVar2 != 0) {
    _DAT_0074476c = _DAT_0074476c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SCORPION_006bfda8[0];
  while (bVar2 != 0) {
    _DAT_00744778 = _DAT_00744778 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar5 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  bVar2 = DAT_006bfdbc;
  while (bVar2 != 0) {
    _DAT_00744784 = _DAT_00744784 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar4 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SKUNK2_006bfdc4[0];
  while (bVar2 != 0) {
    _DAT_00744790 = _DAT_00744790 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar4 = "SPARCO";
  uVar3 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SPARCO_006bfdd8[0];
  while (bVar2 != 0) {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar4 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  bVar2 = s_STILLEN_006bfdec[0];
  while (bVar2 != 0) {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar4 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STILLEN_006bfdf4[0];
  while (bVar2 != 0) {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar4 = "STREET_GLOW";
  _DAT_007447cc = unaff_EDI;
  bVar2 = s_STREET_GLOW_006bfe08[0];
  while (bVar2 != 0) {
    _DAT_007447cc = _DAT_007447cc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  bVar2 = s_STREETGLOW_006bfe14[0];
  while (bVar2 != 0) {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447d4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STREETGLOW_006bfe20[0];
  while (bVar2 != 0) {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar4 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  bVar2 = s_TOUCAN_006bfe38[0];
  while (bVar2 != 0) {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar4 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  bVar2 = s_TOYOTIRES_006bfe40[0];
  while (bVar2 != 0) {
    _DAT_007447fc = _DAT_007447fc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  bVar2 = s_TOYO_TIRES_006bfe4c[0];
  while (bVar2 != 0) {
    _DAT_00744800 = _DAT_00744800 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  bVar2 = DAT_006bfe58;
  while (bVar2 != 0) {
    _DAT_00744804 = _DAT_00744804 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TOYO_006bfe60[0];
  while (bVar2 != 0) {
    _DAT_00744808 = _DAT_00744808 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar4 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  bVar2 = s_TURBONETICS_006bfe70[0];
  while (bVar2 != 0) {
    _DAT_00744814 = _DAT_00744814 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar4 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TURBONETICS_006bfe7c[0];
  while (bVar2 != 0) {
    _DAT_00744820 = _DAT_00744820 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar4 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  bVar2 = s_VENOM_006bfe94[0];
  while (bVar2 != 0) {
    _DAT_0074482c = _DAT_0074482c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar4 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  bVar2 = s_VINYL_ICON_VENOM_006bfe9c[0];
  while (bVar2 != 0) {
    _DAT_00744838 = _DAT_00744838 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar4 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  bVar2 = s_WILWOOD_006bfeb0[0];
  while (bVar2 != 0) {
    _DAT_00744844 = _DAT_00744844 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  bVar2 = s_WILLWOOD_006bfeb8[0];
  while (bVar2 != 0) {
    _DAT_00744848 = _DAT_00744848 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074484c = unaff_EDI;
  pcVar4 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  bVar2 = s_DECAL_ICON_WILWOOD_006bfec4[0];
  while (bVar2 != 0) {
    _DAT_00744850 = _DAT_00744850 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar4 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  bVar2 = s_WOLFRACE_006bfed8[0];
  while (bVar2 != 0) {
    _DAT_0074485c = _DAT_0074485c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  bVar2 = s_WOLFRACEWHEELS_006bfee4[0];
  while (bVar2 != 0) {
    _DAT_00744860 = _DAT_00744860 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar4 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  bVar2 = s_YOKOHAMA_006bfef4[0];
  while (bVar2 != 0) {
    _DAT_00744874 = _DAT_00744874 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar4 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  bVar2 = s_DECAL_ICON_YOKOHAMA_006bff00[0];
  while (bVar2 != 0) {
    _DAT_00744880 = _DAT_00744880 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar4 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  bVar2 = s_ACURA_006bff14[0];
  while (bVar2 != 0) {
    _DAT_0074488c = _DAT_0074488c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_ACURA_006bff1c[0];
  while (bVar2 != 0) {
    _DAT_00744898 = _DAT_00744898 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar4 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  bVar2 = s_DODGE_006bff3c[0];
  while (bVar2 != 0) {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_DODGE_006bff44[0];
  while (bVar2 != 0) {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar5 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  bVar2 = DAT_006bff64;
  while (bVar2 != 0) {
    _DAT_007448bc = _DAT_007448bc * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_FORD_006bff6c[0];
  while (bVar2 != 0) {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar4 = "HONDA";
  uVar3 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HONDA_006bff88[0];
  while (bVar2 != 0) {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar4 = "HYUNDAI";
  uVar3 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HYUNDAI_006bffa8[0];
  while (bVar2 != 0) {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar4 = "MITSUBISHI";
  _DAT_00744904 = unaff_EDI;
  bVar2 = s_MITSUBISHI_006bffc8[0];
  while (bVar2 != 0) {
    _DAT_00744904 = _DAT_00744904 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MITSUBISH_006bffd4[0];
  while (bVar2 != 0) {
    _DAT_00744910 = _DAT_00744910 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar5 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  bVar2 = DAT_006bfff8;
  while (bVar2 != 0) {
    _DAT_0074491c = _DAT_0074491c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MAZDA_006c0000[0];
  while (bVar2 != 0) {
    _DAT_00744928 = _DAT_00744928 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar4 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  bVar2 = s_NISSAN_006c0020[0];
  while (bVar2 != 0) {
    _DAT_00744934 = _DAT_00744934 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_NISSAN_006c0028[0];
  while (bVar2 != 0) {
    _DAT_00744940 = _DAT_00744940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar4 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  bVar2 = s_PEUGEOT_006c0048[0];
  while (bVar2 != 0) {
    _DAT_0074494c = _DAT_0074494c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_PEUGEOT_006c0050[0];
  while (bVar2 != 0) {
    _DAT_00744958 = _DAT_00744958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar5 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  bVar2 = DAT_006c0070;
  while (bVar2 != 0) {
    _DAT_00744964 = _DAT_00744964 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_SUBARU_006c0078[0];
  while (bVar2 != 0) {
    _DAT_00744970 = _DAT_00744970 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar4 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  bVar2 = s_VOLKSWAGEN_006c0098[0];
  while (bVar2 != 0) {
    _DAT_0074497c = _DAT_0074497c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_VOLKSWAGE_006c00a4[0];
  while (bVar2 != 0) {
    _DAT_00744988 = _DAT_00744988 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar5 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  bVar2 = DAT_006c00c8;
  while (bVar2 != 0) {
    _DAT_00744994 = _DAT_00744994 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_TOYOTA_006c00d0[0];
  while (bVar2 != 0) {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar4 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  bVar2 = s_EUROLITE_006c00f0[0];
  while (bVar2 != 0) {
    _DAT_007449ac = _DAT_007449ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_EUROLITE";
  bVar2 = s_DECAL_ICON_EUROLITE_006c00fc[0];
  while (bVar2 != 0) {
    unaff_EDI = unaff_EDI * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


// 00690068 FUN_00690068

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690068(byte param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_EAX;
  uint uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  int unaff_EDI;
  bool in_ZF;
  
  _DAT_007445f4 = in_EAX;
  pcVar4 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = unaff_EDI;
  if (!in_ZF) {
    do {
      _DAT_007445f8 = _DAT_007445f8 * 0x21 + (uint)param_1;
      param_1 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
    } while (param_1 != 0);
  }
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar5 = &DAT_006bfc14;
  _DAT_00744604 = unaff_EDI;
  bVar2 = DAT_006bfc14;
  while (bVar2 != 0) {
    _DAT_00744604 = _DAT_00744604 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "JSPAMERICA";
  _DAT_00744608 = unaff_EDI;
  bVar2 = s_JSPAMERICA_006bfc18[0];
  while (bVar2 != 0) {
    _DAT_00744608 = _DAT_00744608 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074460c = unaff_EDI;
  pcVar4 = "DECAL_ICON_JSP";
  _DAT_00744610 = unaff_EDI;
  bVar2 = s_DECAL_ICON_JSP_006bfc24[0];
  while (bVar2 != 0) {
    _DAT_00744610 = _DAT_00744610 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar5 = &DAT_006bfc34;
  _DAT_0074461c = unaff_EDI;
  bVar2 = DAT_006bfc34;
  while (bVar2 != 0) {
    _DAT_0074461c = _DAT_0074461c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744620 = unaff_EDI;
  _DAT_00744624 = unaff_EDI;
  _DAT_00744628 = unaff_EDI;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar4 = "KENWOOD";
  _DAT_00744634 = unaff_EDI;
  bVar2 = s_KENWOOD_006bfc38[0];
  while (bVar2 != 0) {
    _DAT_00744634 = _DAT_00744634 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744638 = unaff_EDI;
  _DAT_0074463c = unaff_EDI;
  pcVar4 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KENWOOD_006bfc40[0];
  while (bVar2 != 0) {
    _DAT_00744640 = _DAT_00744640 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar4 = "KEYSTONE";
  _DAT_0074464c = unaff_EDI;
  bVar2 = s_KEYSTONE_006bfc54[0];
  while (bVar2 != 0) {
    _DAT_0074464c = _DAT_0074464c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar5 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  bVar2 = DAT_006bfc60;
  while (bVar2 != 0) {
    _DAT_00744664 = _DAT_00744664 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONI_006bfc68[0];
  while (bVar2 != 0) {
    _DAT_00744670 = _DAT_00744670 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar5 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  bVar2 = DAT_006bfc78;
  while (bVar2 != 0) {
    _DAT_0074467c = _DAT_0074467c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONIG_006bfc80[0];
  while (bVar2 != 0) {
    _DAT_00744688 = _DAT_00744688 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar5 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  bVar2 = DAT_006bfc94;
  while (bVar2 != 0) {
    _DAT_00744694 = _DAT_00744694 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  bVar2 = DAT_006bfc9c;
  while (bVar2 != 0) {
    _DAT_00744698 = _DAT_00744698 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar5 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  bVar2 = DAT_006bfca4;
  while (bVar2 != 0) {
    _DAT_007446ac = _DAT_007446ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  bVar2 = s_KVRPERFORMANCE_006bfca8[0];
  while (bVar2 != 0) {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KVR_006bfcb8[0];
  while (bVar2 != 0) {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar5 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  bVar2 = DAT_006bfcc8;
  while (bVar2 != 0) {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar4 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KYB_006bfccc[0];
  while (bVar2 != 0) {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar5 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  bVar2 = DAT_006bfcdc;
  while (bVar2 != 0) {
    _DAT_007446dc = _DAT_007446dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_MOMO_006bfce4[0];
  while (bVar2 != 0) {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar4 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  bVar2 = s_NEUSPEED_006bfcf4[0];
  while (bVar2 != 0) {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar4 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NEUSPEED_006bfd00[0];
  while (bVar2 != 0) {
    _DAT_00744700 = _DAT_00744700 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar4 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  bVar2 = s_NITROUS_EXPRESS_006bfd14[0];
  while (bVar2 != 0) {
    _DAT_0074470c = _DAT_0074470c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  bVar2 = DAT_006bfd24;
  while (bVar2 != 0) {
    _DAT_00744710 = _DAT_00744710 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  bVar2 = s_NITROUSEXPRESS_006bfd28[0];
  while (bVar2 != 0) {
    _DAT_00744714 = _DAT_00744714 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NX_006bfd38[0];
  while (bVar2 != 0) {
    _DAT_00744718 = _DAT_00744718 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar5 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  bVar2 = DAT_006bfd48;
  while (bVar2 != 0) {
    _DAT_00744724 = _DAT_00744724 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar4 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  bVar2 = s_DECAL_ICON_OZ_006bfd4c[0];
  while (bVar2 != 0) {
    _DAT_00744730 = _DAT_00744730 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar6 = &DAT_006c0ca0;
  uVar3 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar4 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PIAA_006bfd5c[0];
  while (bVar2 != 0) {
    _DAT_00744748 = _DAT_00744748 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar4 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  bVar2 = s_PLASMAGLOW_006bfd6c[0];
  while (bVar2 != 0) {
    _DAT_00744754 = _DAT_00744754 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  bVar2 = s_PLASMA_GLOW_006bfd78[0];
  while (bVar2 != 0) {
    _DAT_00744758 = _DAT_00744758 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074475c = unaff_EDI;
  pcVar4 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PLASMAGLOW_006bfd84[0];
  while (bVar2 != 0) {
    _DAT_00744760 = _DAT_00744760 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar4 = "SCORPION";
  _DAT_0074476c = unaff_EDI;
  bVar2 = s_SCORPION_006bfd9c[0];
  while (bVar2 != 0) {
    _DAT_0074476c = _DAT_0074476c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SCORPION_006bfda8[0];
  while (bVar2 != 0) {
    _DAT_00744778 = _DAT_00744778 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar5 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  bVar2 = DAT_006bfdbc;
  while (bVar2 != 0) {
    _DAT_00744784 = _DAT_00744784 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar4 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SKUNK2_006bfdc4[0];
  while (bVar2 != 0) {
    _DAT_00744790 = _DAT_00744790 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar4 = "SPARCO";
  uVar3 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SPARCO_006bfdd8[0];
  while (bVar2 != 0) {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar4 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  bVar2 = s_STILLEN_006bfdec[0];
  while (bVar2 != 0) {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar4 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STILLEN_006bfdf4[0];
  while (bVar2 != 0) {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar4 = "STREET_GLOW";
  _DAT_007447cc = unaff_EDI;
  bVar2 = s_STREET_GLOW_006bfe08[0];
  while (bVar2 != 0) {
    _DAT_007447cc = _DAT_007447cc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  bVar2 = s_STREETGLOW_006bfe14[0];
  while (bVar2 != 0) {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447d4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STREETGLOW_006bfe20[0];
  while (bVar2 != 0) {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar4 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  bVar2 = s_TOUCAN_006bfe38[0];
  while (bVar2 != 0) {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar4 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  bVar2 = s_TOYOTIRES_006bfe40[0];
  while (bVar2 != 0) {
    _DAT_007447fc = _DAT_007447fc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  bVar2 = s_TOYO_TIRES_006bfe4c[0];
  while (bVar2 != 0) {
    _DAT_00744800 = _DAT_00744800 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar5 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  bVar2 = DAT_006bfe58;
  while (bVar2 != 0) {
    _DAT_00744804 = _DAT_00744804 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TOYO_006bfe60[0];
  while (bVar2 != 0) {
    _DAT_00744808 = _DAT_00744808 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar4 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  bVar2 = s_TURBONETICS_006bfe70[0];
  while (bVar2 != 0) {
    _DAT_00744814 = _DAT_00744814 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar4 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TURBONETICS_006bfe7c[0];
  while (bVar2 != 0) {
    _DAT_00744820 = _DAT_00744820 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar4 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  bVar2 = s_VENOM_006bfe94[0];
  while (bVar2 != 0) {
    _DAT_0074482c = _DAT_0074482c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar4 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  bVar2 = s_VINYL_ICON_VENOM_006bfe9c[0];
  while (bVar2 != 0) {
    _DAT_00744838 = _DAT_00744838 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar4 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  bVar2 = s_WILWOOD_006bfeb0[0];
  while (bVar2 != 0) {
    _DAT_00744844 = _DAT_00744844 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  bVar2 = s_WILLWOOD_006bfeb8[0];
  while (bVar2 != 0) {
    _DAT_00744848 = _DAT_00744848 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074484c = unaff_EDI;
  pcVar4 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  bVar2 = s_DECAL_ICON_WILWOOD_006bfec4[0];
  while (bVar2 != 0) {
    _DAT_00744850 = _DAT_00744850 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar4 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  bVar2 = s_WOLFRACE_006bfed8[0];
  while (bVar2 != 0) {
    _DAT_0074485c = _DAT_0074485c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar4 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  bVar2 = s_WOLFRACEWHEELS_006bfee4[0];
  while (bVar2 != 0) {
    _DAT_00744860 = _DAT_00744860 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar4 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  bVar2 = s_YOKOHAMA_006bfef4[0];
  while (bVar2 != 0) {
    _DAT_00744874 = _DAT_00744874 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar4 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  bVar2 = s_DECAL_ICON_YOKOHAMA_006bff00[0];
  while (bVar2 != 0) {
    _DAT_00744880 = _DAT_00744880 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar4 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  bVar2 = s_ACURA_006bff14[0];
  while (bVar2 != 0) {
    _DAT_0074488c = _DAT_0074488c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_ACURA_006bff1c[0];
  while (bVar2 != 0) {
    _DAT_00744898 = _DAT_00744898 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar4 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  bVar2 = s_DODGE_006bff3c[0];
  while (bVar2 != 0) {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_DODGE_006bff44[0];
  while (bVar2 != 0) {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar5 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  bVar2 = DAT_006bff64;
  while (bVar2 != 0) {
    _DAT_007448bc = _DAT_007448bc * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_FORD_006bff6c[0];
  while (bVar2 != 0) {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar4 = "HONDA";
  uVar3 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HONDA_006bff88[0];
  while (bVar2 != 0) {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar4 = "HYUNDAI";
  uVar3 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HYUNDAI_006bffa8[0];
  while (bVar2 != 0) {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar4 = "MITSUBISHI";
  _DAT_00744904 = unaff_EDI;
  bVar2 = s_MITSUBISHI_006bffc8[0];
  while (bVar2 != 0) {
    _DAT_00744904 = _DAT_00744904 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MITSUBISH_006bffd4[0];
  while (bVar2 != 0) {
    _DAT_00744910 = _DAT_00744910 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar5 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  bVar2 = DAT_006bfff8;
  while (bVar2 != 0) {
    _DAT_0074491c = _DAT_0074491c * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MAZDA_006c0000[0];
  while (bVar2 != 0) {
    _DAT_00744928 = _DAT_00744928 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar4 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  bVar2 = s_NISSAN_006c0020[0];
  while (bVar2 != 0) {
    _DAT_00744934 = _DAT_00744934 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_NISSAN_006c0028[0];
  while (bVar2 != 0) {
    _DAT_00744940 = _DAT_00744940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar4 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  bVar2 = s_PEUGEOT_006c0048[0];
  while (bVar2 != 0) {
    _DAT_0074494c = _DAT_0074494c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_PEUGEOT_006c0050[0];
  while (bVar2 != 0) {
    _DAT_00744958 = _DAT_00744958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar5 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  bVar2 = DAT_006c0070;
  while (bVar2 != 0) {
    _DAT_00744964 = _DAT_00744964 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_SUBARU_006c0078[0];
  while (bVar2 != 0) {
    _DAT_00744970 = _DAT_00744970 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar4 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  bVar2 = s_VOLKSWAGEN_006c0098[0];
  while (bVar2 != 0) {
    _DAT_0074497c = _DAT_0074497c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_VOLKSWAGE_006c00a4[0];
  while (bVar2 != 0) {
    _DAT_00744988 = _DAT_00744988 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar5 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  bVar2 = DAT_006c00c8;
  while (bVar2 != 0) {
    _DAT_00744994 = _DAT_00744994 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_TOYOTA_006c00d0[0];
  while (bVar2 != 0) {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar4 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  bVar2 = s_EUROLITE_006c00f0[0];
  while (bVar2 != 0) {
    _DAT_007449ac = _DAT_007449ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_EUROLITE";
  bVar2 = s_DECAL_ICON_EUROLITE_006c00fc[0];
  while (bVar2 != 0) {
    unaff_EDI = unaff_EDI * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


// 00690200 FUN_00690200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690200(byte param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  uint uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined *puVar6;
  int unaff_EDI;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  _DAT_0074464c = in_EAX;
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar4 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  bVar2 = DAT_006bfc60;
  while (bVar2 != 0) {
    _DAT_00744664 = _DAT_00744664 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar5 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONI_006bfc68[0];
  while (bVar2 != 0) {
    _DAT_00744670 = _DAT_00744670 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar4 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  bVar2 = DAT_006bfc78;
  while (bVar2 != 0) {
    _DAT_0074467c = _DAT_0074467c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar5 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KONIG_006bfc80[0];
  while (bVar2 != 0) {
    _DAT_00744688 = _DAT_00744688 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar4 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  bVar2 = DAT_006bfc94;
  while (bVar2 != 0) {
    _DAT_00744694 = _DAT_00744694 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  bVar2 = DAT_006bfc9c;
  while (bVar2 != 0) {
    _DAT_00744698 = _DAT_00744698 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar4 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  bVar2 = DAT_006bfca4;
  while (bVar2 != 0) {
    _DAT_007446ac = _DAT_007446ac * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  bVar2 = s_KVRPERFORMANCE_006bfca8[0];
  while (bVar2 != 0) {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446b4 = unaff_EDI;
  pcVar5 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KVR_006bfcb8[0];
  while (bVar2 != 0) {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar4 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  bVar2 = DAT_006bfcc8;
  while (bVar2 != 0) {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar5 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_KYB_006bfccc[0];
  while (bVar2 != 0) {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar4 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  bVar2 = DAT_006bfcdc;
  while (bVar2 != 0) {
    _DAT_007446dc = _DAT_007446dc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar5 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_MOMO_006bfce4[0];
  while (bVar2 != 0) {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar5 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  bVar2 = s_NEUSPEED_006bfcf4[0];
  while (bVar2 != 0) {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar5 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NEUSPEED_006bfd00[0];
  while (bVar2 != 0) {
    _DAT_00744700 = _DAT_00744700 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar5 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  bVar2 = s_NITROUS_EXPRESS_006bfd14[0];
  while (bVar2 != 0) {
    _DAT_0074470c = _DAT_0074470c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  bVar2 = DAT_006bfd24;
  while (bVar2 != 0) {
    _DAT_00744710 = _DAT_00744710 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  bVar2 = s_NITROUSEXPRESS_006bfd28[0];
  while (bVar2 != 0) {
    _DAT_00744714 = _DAT_00744714 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  bVar2 = s_DECAL_ICON_NX_006bfd38[0];
  while (bVar2 != 0) {
    _DAT_00744718 = _DAT_00744718 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar4 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  bVar2 = DAT_006bfd48;
  while (bVar2 != 0) {
    _DAT_00744724 = _DAT_00744724 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar5 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  bVar2 = s_DECAL_ICON_OZ_006bfd4c[0];
  while (bVar2 != 0) {
    _DAT_00744730 = _DAT_00744730 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar6 = &DAT_006c0ca0;
  uVar3 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar5 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PIAA_006bfd5c[0];
  while (bVar2 != 0) {
    _DAT_00744748 = _DAT_00744748 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar5 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  bVar2 = s_PLASMAGLOW_006bfd6c[0];
  while (bVar2 != 0) {
    _DAT_00744754 = _DAT_00744754 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  bVar2 = s_PLASMA_GLOW_006bfd78[0];
  while (bVar2 != 0) {
    _DAT_00744758 = _DAT_00744758 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074475c = unaff_EDI;
  pcVar5 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  bVar2 = s_DECAL_ICON_PLASMAGLOW_006bfd84[0];
  while (bVar2 != 0) {
    _DAT_00744760 = _DAT_00744760 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar5 = "SCORPION";
  _DAT_0074476c = unaff_EDI;
  bVar2 = s_SCORPION_006bfd9c[0];
  while (bVar2 != 0) {
    _DAT_0074476c = _DAT_0074476c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar5 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SCORPION_006bfda8[0];
  while (bVar2 != 0) {
    _DAT_00744778 = _DAT_00744778 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar4 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  bVar2 = DAT_006bfdbc;
  while (bVar2 != 0) {
    _DAT_00744784 = _DAT_00744784 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar5 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SKUNK2_006bfdc4[0];
  while (bVar2 != 0) {
    _DAT_00744790 = _DAT_00744790 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar5 = "SPARCO";
  uVar3 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar5 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_SPARCO_006bfdd8[0];
  while (bVar2 != 0) {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar5 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  bVar2 = s_STILLEN_006bfdec[0];
  while (bVar2 != 0) {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar5 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STILLEN_006bfdf4[0];
  while (bVar2 != 0) {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar5 = "STREET_GLOW";
  _DAT_007447cc = unaff_EDI;
  bVar2 = s_STREET_GLOW_006bfe08[0];
  while (bVar2 != 0) {
    _DAT_007447cc = _DAT_007447cc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  bVar2 = s_STREETGLOW_006bfe14[0];
  while (bVar2 != 0) {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447d4 = unaff_EDI;
  pcVar5 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  bVar2 = s_DECAL_ICON_STREETGLOW_006bfe20[0];
  while (bVar2 != 0) {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar5 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  bVar2 = s_TOUCAN_006bfe38[0];
  while (bVar2 != 0) {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar5 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  bVar2 = s_TOYOTIRES_006bfe40[0];
  while (bVar2 != 0) {
    _DAT_007447fc = _DAT_007447fc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  bVar2 = s_TOYO_TIRES_006bfe4c[0];
  while (bVar2 != 0) {
    _DAT_00744800 = _DAT_00744800 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  puVar4 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  bVar2 = DAT_006bfe58;
  while (bVar2 != 0) {
    _DAT_00744804 = _DAT_00744804 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TOYO_006bfe60[0];
  while (bVar2 != 0) {
    _DAT_00744808 = _DAT_00744808 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar5 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  bVar2 = s_TURBONETICS_006bfe70[0];
  while (bVar2 != 0) {
    _DAT_00744814 = _DAT_00744814 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar5 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  bVar2 = s_DECAL_ICON_TURBONETICS_006bfe7c[0];
  while (bVar2 != 0) {
    _DAT_00744820 = _DAT_00744820 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar5 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  bVar2 = s_VENOM_006bfe94[0];
  while (bVar2 != 0) {
    _DAT_0074482c = _DAT_0074482c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar5 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  bVar2 = s_VINYL_ICON_VENOM_006bfe9c[0];
  while (bVar2 != 0) {
    _DAT_00744838 = _DAT_00744838 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar5 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  bVar2 = s_WILWOOD_006bfeb0[0];
  while (bVar2 != 0) {
    _DAT_00744844 = _DAT_00744844 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  bVar2 = s_WILLWOOD_006bfeb8[0];
  while (bVar2 != 0) {
    _DAT_00744848 = _DAT_00744848 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074484c = unaff_EDI;
  pcVar5 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  bVar2 = s_DECAL_ICON_WILWOOD_006bfec4[0];
  while (bVar2 != 0) {
    _DAT_00744850 = _DAT_00744850 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar5 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  bVar2 = s_WOLFRACE_006bfed8[0];
  while (bVar2 != 0) {
    _DAT_0074485c = _DAT_0074485c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  pcVar5 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  bVar2 = s_WOLFRACEWHEELS_006bfee4[0];
  while (bVar2 != 0) {
    _DAT_00744860 = _DAT_00744860 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar5 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  bVar2 = s_YOKOHAMA_006bfef4[0];
  while (bVar2 != 0) {
    _DAT_00744874 = _DAT_00744874 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar5 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  bVar2 = s_DECAL_ICON_YOKOHAMA_006bff00[0];
  while (bVar2 != 0) {
    _DAT_00744880 = _DAT_00744880 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar5 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  bVar2 = s_ACURA_006bff14[0];
  while (bVar2 != 0) {
    _DAT_0074488c = _DAT_0074488c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_ACURA_006bff1c[0];
  while (bVar2 != 0) {
    _DAT_00744898 = _DAT_00744898 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar5 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  bVar2 = s_DODGE_006bff3c[0];
  while (bVar2 != 0) {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_DODGE_006bff44[0];
  while (bVar2 != 0) {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar4 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  bVar2 = DAT_006bff64;
  while (bVar2 != 0) {
    _DAT_007448bc = _DAT_007448bc * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_FORD_006bff6c[0];
  while (bVar2 != 0) {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar5 = "HONDA";
  uVar3 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HONDA_006bff88[0];
  while (bVar2 != 0) {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar5 = "HYUNDAI";
  uVar3 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_HYUNDAI_006bffa8[0];
  while (bVar2 != 0) {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar5 = "MITSUBISHI";
  _DAT_00744904 = unaff_EDI;
  bVar2 = s_MITSUBISHI_006bffc8[0];
  while (bVar2 != 0) {
    _DAT_00744904 = _DAT_00744904 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MITSUBISH_006bffd4[0];
  while (bVar2 != 0) {
    _DAT_00744910 = _DAT_00744910 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar4 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  bVar2 = DAT_006bfff8;
  while (bVar2 != 0) {
    _DAT_0074491c = _DAT_0074491c * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_MAZDA_006c0000[0];
  while (bVar2 != 0) {
    _DAT_00744928 = _DAT_00744928 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar5 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  bVar2 = s_NISSAN_006c0020[0];
  while (bVar2 != 0) {
    _DAT_00744934 = _DAT_00744934 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_NISSAN_006c0028[0];
  while (bVar2 != 0) {
    _DAT_00744940 = _DAT_00744940 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar5 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  bVar2 = s_PEUGEOT_006c0048[0];
  while (bVar2 != 0) {
    _DAT_0074494c = _DAT_0074494c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_PEUGEOT_006c0050[0];
  while (bVar2 != 0) {
    _DAT_00744958 = _DAT_00744958 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar4 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  bVar2 = DAT_006c0070;
  while (bVar2 != 0) {
    _DAT_00744964 = _DAT_00744964 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_SUBARU_006c0078[0];
  while (bVar2 != 0) {
    _DAT_00744970 = _DAT_00744970 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar5 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  bVar2 = s_VOLKSWAGEN_006c0098[0];
  while (bVar2 != 0) {
    _DAT_0074497c = _DAT_0074497c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_VOLKSWAGE_006c00a4[0];
  while (bVar2 != 0) {
    _DAT_00744988 = _DAT_00744988 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar4 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  bVar2 = DAT_006c00c8;
  while (bVar2 != 0) {
    _DAT_00744994 = _DAT_00744994 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar5 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  bVar2 = s_CARSELECT_MANUFACTURER_TOYOTA_006c00d0[0];
  while (bVar2 != 0) {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar5 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  bVar2 = s_EUROLITE_006c00f0[0];
  while (bVar2 != 0) {
    _DAT_007449ac = _DAT_007449ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar5 = "DECAL_ICON_EUROLITE";
  bVar2 = s_DECAL_ICON_EUROLITE_006c00fc[0];
  while (bVar2 != 0) {
    unaff_EDI = unaff_EDI * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    pcVar5 = pcVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


// 006912d0 FUN_006912d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006912d0(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  _DAT_00744280 = -1;
  pcVar3 = "AUTOPRESS";
  bVar2 = s_AUTOPRESS_006bf638[0];
  while (bVar2 != 0) {
    _DAT_00744280 = _DAT_00744280 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744284 = -1;
  pcVar3 = "MAG_ICONS_AUTOPRESS";
  bVar2 = s_MAG_ICONS_AUTOPRESS_006bf644[0];
  while (bVar2 != 0) {
    _DAT_00744284 = _DAT_00744284 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744288 = -1;
  pcVar3 = "CHROM_AND_FLAMMEN";
  bVar2 = s_CHROM_AND_FLAMMEN_006bf658[0];
  while (bVar2 != 0) {
    _DAT_00744288 = _DAT_00744288 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074428c = -1;
  pcVar3 = "MAG_ICONS_CHROM";
  bVar2 = s_MAG_ICONS_CHROM_006bf66c[0];
  while (bVar2 != 0) {
    _DAT_0074428c = _DAT_0074428c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744290 = -1;
  puVar4 = &DAT_006bf67c;
  bVar2 = DAT_006bf67c;
  while (bVar2 != 0) {
    _DAT_00744290 = _DAT_00744290 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744294 = -1;
  pcVar3 = "MAG_ICONS_DUB";
  bVar2 = s_MAG_ICONS_DUB_006bf680[0];
  while (bVar2 != 0) {
    _DAT_00744294 = _DAT_00744294 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744298 = -1;
  puVar4 = &DAT_006bf690;
  bVar2 = DAT_006bf690;
  while (bVar2 != 0) {
    _DAT_00744298 = _DAT_00744298 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074429c = -1;
  pcVar3 = "MAG_ICONS_HOT";
  bVar2 = s_MAG_ICONS_HOT_006bf698[0];
  while (bVar2 != 0) {
    _DAT_0074429c = _DAT_0074429c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442a0 = -1;
  pcVar3 = "IMPORT_RACER";
  bVar2 = s_IMPORT_RACER_006bf6a8[0];
  while (bVar2 != 0) {
    _DAT_007442a0 = _DAT_007442a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442a4 = -1;
  pcVar3 = "MAG_ICONS_IMPORTRACER";
  bVar2 = s_MAG_ICONS_IMPORTRACER_006bf6b8[0];
  while (bVar2 != 0) {
    _DAT_007442a4 = _DAT_007442a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442a8 = -1;
  pcVar3 = "IMPORT_TUNER";
  bVar2 = s_IMPORT_TUNER_006bf6d0[0];
  while (bVar2 != 0) {
    _DAT_007442a8 = _DAT_007442a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442ac = -1;
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_007442ac = _DAT_007442ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442b0 = -1;
  pcVar3 = "MAXI_TUNING";
  bVar2 = s_MAXI_TUNING_006bf6f8[0];
  while (bVar2 != 0) {
    _DAT_007442b0 = _DAT_007442b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442b4 = -1;
  pcVar3 = "MAG_ICONS_MAXI";
  bVar2 = s_MAG_ICONS_MAXI_006bf704[0];
  while (bVar2 != 0) {
    _DAT_007442b4 = _DAT_007442b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442b8 = -1;
  pcVar3 = "MODIFIED_MAG";
  bVar2 = s_MODIFIED_MAG_006bf714[0];
  while (bVar2 != 0) {
    _DAT_007442b8 = _DAT_007442b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442bc = -1;
  pcVar3 = "MAG_ICONS_MODIFIEDMAG";
  bVar2 = s_MAG_ICONS_MODIFIEDMAG_006bf724[0];
  while (bVar2 != 0) {
    _DAT_007442bc = _DAT_007442bc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442c0 = -1;
  pcVar3 = "OPTION";
  bVar2 = s_OPTION_006bf73c[0];
  while (bVar2 != 0) {
    _DAT_007442c0 = _DAT_007442c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442c4 = -1;
  pcVar3 = "MAG_ICONS_OPTION";
  bVar2 = s_MAG_ICONS_OPTION_006bf744[0];
  while (bVar2 != 0) {
    _DAT_007442c4 = _DAT_007442c4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442c8 = -1;
  pcVar3 = "SPORT_COMPACT_CAR";
  bVar2 = s_SPORT_COMPACT_CAR_006bf758[0];
  while (bVar2 != 0) {
    _DAT_007442c8 = _DAT_007442c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442cc = -1;
  pcVar3 = "MAG_ICONS_SPORTCOMPACTCAR";
  bVar2 = s_MAG_ICONS_SPORTCOMPACTCAR_006bf76c[0];
  while (bVar2 != 0) {
    _DAT_007442cc = _DAT_007442cc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442d0 = -1;
  pcVar3 = "STUFF";
  bVar2 = s_STUFF_006bf788[0];
  while (bVar2 != 0) {
    _DAT_007442d0 = _DAT_007442d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442d4 = -1;
  pcVar3 = "MAG_ICONS_STUFF";
  bVar2 = s_MAG_ICONS_STUFF_006bf790[0];
  while (bVar2 != 0) {
    _DAT_007442d4 = _DAT_007442d4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442d8 = -1;
  pcVar3 = "SUPER_STREET";
  bVar2 = s_SUPER_STREET_006bf7a0[0];
  while (bVar2 != 0) {
    _DAT_007442d8 = _DAT_007442d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442dc = -1;
  pcVar3 = "MAG_ICONS_SUPERSTREET";
  bVar2 = s_MAG_ICONS_SUPERSTREET_006bf7b0[0];
  while (bVar2 != 0) {
    _DAT_007442dc = _DAT_007442dc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e0 = -1;
  puVar4 = &DAT_006bf7c8;
  bVar2 = DAT_006bf7c8;
  while (bVar2 != 0) {
    _DAT_007442e0 = _DAT_007442e0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e4 = -1;
  pcVar3 = "MAG_ICONS_TURBOHIGHTECH";
  bVar2 = s_MAG_ICONS_TURBOHIGHTECH_006bf7d0[0];
  while (bVar2 != 0) {
    _DAT_007442e4 = _DAT_007442e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e8 = -1;
  pcVar3 = "ELABORARE";
  bVar2 = s_ELABORARE_006bf7e8[0];
  while (bVar2 != 0) {
    _DAT_007442e8 = _DAT_007442e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "MAG_ICONS_ELABORARE";
  _DAT_007442ec = -1;
  bVar2 = s_MAG_ICONS_ELABORARE_006bf7f4[0];
  while (bVar2 != 0) {
    _DAT_007442ec = _DAT_007442ec * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 00691600 FUN_00691600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00691600(byte param_1)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  char *pcVar3;
  undefined1 *puVar4;
  bool in_ZF;
  
  pcVar3 = "STUFF";
  if (!in_ZF) {
    do {
      in_EAX = in_EAX * 0x21 + (uint)param_1;
      param_1 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (param_1 != 0);
  }
  _DAT_007442d0 = in_EAX;
  _DAT_007442d4 = -1;
  pcVar3 = "MAG_ICONS_STUFF";
  bVar2 = s_MAG_ICONS_STUFF_006bf790[0];
  while (bVar2 != 0) {
    _DAT_007442d4 = _DAT_007442d4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442d8 = -1;
  pcVar3 = "SUPER_STREET";
  bVar2 = s_SUPER_STREET_006bf7a0[0];
  while (bVar2 != 0) {
    _DAT_007442d8 = _DAT_007442d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442dc = -1;
  pcVar3 = "MAG_ICONS_SUPERSTREET";
  bVar2 = s_MAG_ICONS_SUPERSTREET_006bf7b0[0];
  while (bVar2 != 0) {
    _DAT_007442dc = _DAT_007442dc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e0 = -1;
  puVar4 = &DAT_006bf7c8;
  bVar2 = DAT_006bf7c8;
  while (bVar2 != 0) {
    _DAT_007442e0 = _DAT_007442e0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e4 = -1;
  pcVar3 = "MAG_ICONS_TURBOHIGHTECH";
  bVar2 = s_MAG_ICONS_TURBOHIGHTECH_006bf7d0[0];
  while (bVar2 != 0) {
    _DAT_007442e4 = _DAT_007442e4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442e8 = -1;
  pcVar3 = "ELABORARE";
  bVar2 = s_ELABORARE_006bf7e8[0];
  while (bVar2 != 0) {
    _DAT_007442e8 = _DAT_007442e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "MAG_ICONS_ELABORARE";
  _DAT_007442ec = -1;
  bVar2 = s_MAG_ICONS_ELABORARE_006bf7f4[0];
  while (bVar2 != 0) {
    _DAT_007442ec = _DAT_007442ec * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 00691740 FUN_00691740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691740(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  _DAT_007442f0 = -1;
  pcVar3 = "MAG_ICONS_MODIFIEDMAG";
  bVar2 = s_MAG_ICONS_MODIFIEDMAG_006bf724[0];
  while (bVar2 != 0) {
    _DAT_007442f0 = _DAT_007442f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442f4 = -1;
  pcVar3 = "MAG_ICONS_SPORTCOMPACTCAR";
  bVar2 = s_MAG_ICONS_SPORTCOMPACTCAR_006bf76c[0];
  while (bVar2 != 0) {
    _DAT_007442f4 = _DAT_007442f4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442f8 = -1;
  pcVar3 = "MAG_ICONS_CHROM";
  bVar2 = s_MAG_ICONS_CHROM_006bf66c[0];
  while (bVar2 != 0) {
    _DAT_007442f8 = _DAT_007442f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007442fc = -1;
  pcVar3 = "MAG_ICONS_TURBOHIGHTECH";
  bVar2 = s_MAG_ICONS_TURBOHIGHTECH_006bf7d0[0];
  while (bVar2 != 0) {
    _DAT_007442fc = _DAT_007442fc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744300 = -1;
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_00744300 = _DAT_00744300 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744304 = -1;
  pcVar3 = "MAG_ICONS_IMPORTRACER";
  bVar2 = s_MAG_ICONS_IMPORTRACER_006bf6b8[0];
  while (bVar2 != 0) {
    _DAT_00744304 = _DAT_00744304 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744308 = -1;
  pcVar3 = "MAG_ICONS_SUPERSTREET";
  bVar2 = s_MAG_ICONS_SUPERSTREET_006bf7b0[0];
  while (bVar2 != 0) {
    _DAT_00744308 = _DAT_00744308 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074430c = -1;
  pcVar3 = "MAG_ICONS_SPORTCOMPACTCAR";
  bVar2 = s_MAG_ICONS_SPORTCOMPACTCAR_006bf76c[0];
  while (bVar2 != 0) {
    _DAT_0074430c = _DAT_0074430c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744310 = -1;
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_00744310 = _DAT_00744310 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744314 = -1;
  pcVar3 = "MAG_ICONS_HOT";
  bVar2 = s_MAG_ICONS_HOT_006bf698[0];
  while (bVar2 != 0) {
    pbVar1 = (byte *)(pcVar3 + 1);
    _DAT_00744314 = _DAT_00744314 * 0x21 + (uint)bVar2;
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744318 = -1;
  pcVar3 = "MAG_ICONS_STUFF";
  bVar2 = s_MAG_ICONS_STUFF_006bf790[0];
  while (bVar2 != 0) {
    _DAT_00744318 = _DAT_00744318 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074431c = -1;
  pcVar3 = "MAG_ICONS_AUTOPRESS";
  bVar2 = s_MAG_ICONS_AUTOPRESS_006bf644[0];
  while (bVar2 != 0) {
    pbVar1 = (byte *)(pcVar3 + 1);
    _DAT_0074431c = _DAT_0074431c * 0x21 + (uint)bVar2;
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744320 = -1;
  pcVar3 = "MAG_ICONS_SUPERSTREET";
  bVar2 = s_MAG_ICONS_SUPERSTREET_006bf7b0[0];
  while (bVar2 != 0) {
    _DAT_00744320 = _DAT_00744320 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744324 = -1;
  pcVar3 = "MAG_ICONS_MAXI";
  bVar2 = s_MAG_ICONS_MAXI_006bf704[0];
  while (bVar2 != 0) {
    _DAT_00744324 = _DAT_00744324 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744328 = -1;
  pcVar3 = "MAG_ICONS_OPTION";
  bVar2 = s_MAG_ICONS_OPTION_006bf744[0];
  while (bVar2 != 0) {
    _DAT_00744328 = _DAT_00744328 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074432c = -1;
  pcVar3 = "MAG_ICONS_ELABORARE";
  bVar2 = s_MAG_ICONS_ELABORARE_006bf7f4[0];
  while (bVar2 != 0) {
    _DAT_0074432c = _DAT_0074432c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744330 = -1;
  pcVar3 = "MAG_ICONS_MAXI";
  bVar2 = s_MAG_ICONS_MAXI_006bf704[0];
  while (bVar2 != 0) {
    pbVar1 = (byte *)(pcVar3 + 1);
    _DAT_00744330 = _DAT_00744330 * 0x21 + (uint)bVar2;
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744334 = -1;
  pcVar3 = "MAG_ICONS_HOT";
  bVar2 = s_MAG_ICONS_HOT_006bf698[0];
  while (bVar2 != 0) {
    _DAT_00744334 = _DAT_00744334 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744338 = -1;
  pcVar3 = "MAG_ICONS_DUB";
  bVar2 = s_MAG_ICONS_DUB_006bf680[0];
  while (bVar2 != 0) {
    _DAT_00744338 = _DAT_00744338 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074433c = -1;
  pcVar3 = "MAG_ICONS_TURBOHIGHTECH";
  bVar2 = s_MAG_ICONS_TURBOHIGHTECH_006bf7d0[0];
  while (bVar2 != 0) {
    _DAT_0074433c = _DAT_0074433c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744340 = -1;
  pcVar3 = "MAG_ICONS_IMPORTRACER";
  bVar2 = s_MAG_ICONS_IMPORTRACER_006bf6b8[0];
  while (bVar2 != 0) {
    _DAT_00744340 = _DAT_00744340 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744344 = -1;
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_00744344 = _DAT_00744344 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744348 = -1;
  pcVar3 = "MAG_ICONS_SPORTCOMPACTCAR";
  bVar2 = s_MAG_ICONS_SPORTCOMPACTCAR_006bf76c[0];
  while (bVar2 != 0) {
    _DAT_00744348 = _DAT_00744348 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0074434c = -1;
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_0074434c = _DAT_0074434c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744350 = -1;
  pcVar3 = "MAG_ICONS_HOT";
  bVar2 = s_MAG_ICONS_HOT_006bf698[0];
  while (bVar2 != 0) {
    _DAT_00744350 = _DAT_00744350 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00744354 = -1;
  pcVar3 = "MAG_ICONS_ELABORARE";
  bVar2 = s_MAG_ICONS_ELABORARE_006bf7f4[0];
  while (bVar2 != 0) {
    _DAT_00744354 = _DAT_00744354 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "MAG_ICONS_IMPORTTUNER";
  _DAT_00744358 = -1;
  bVar2 = s_MAG_ICONS_IMPORTTUNER_006bf6e0[0];
  while (bVar2 != 0) {
    _DAT_00744358 = _DAT_00744358 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 00691bc0 FUN_00691bc0

void FUN_00691bc0(void)

{
  DAT_0074421c = 0xfffffffd;
  return;
}


// 00691bd0 FUN_00691bd0

void FUN_00691bd0(void)

{
  DAT_00744214 = 0xfffffffd;
  return;
}


// 00691be0 FUN_00691be0

void FUN_00691be0(void)

{
  DAT_00744204 = 0xfffffffd;
  return;
}


// 00691bf0 FUN_00691bf0

void FUN_00691bf0(void)

{
  DAT_0074420c = 0xfffffffd;
  return;
}


// 00691c00 FUN_00691c00

void FUN_00691c00(void)

{
  DAT_007441fc = 0xfffffffd;
  return;
}


// 00691c10 FUN_00691c10

void FUN_00691c10(void)

{
  DAT_007441dc = 0xfffffffd;
  return;
}


// 00691c20 FUN_00691c20

void FUN_00691c20(void)

{
  DAT_007441ec = 0xfffffffd;
  return;
}


// 00691c30 FUN_00691c30

void FUN_00691c30(void)

{
  DAT_007441e4 = 0xfffffffd;
  return;
}


// 00691c40 FUN_00691c40

void FUN_00691c40(void)

{
  DAT_007441f4 = 0xfffffffd;
  return;
}


// 00691c60 FUN_00691c60

void FUN_00691c60(void)

{
  DAT_007441c4 = 0xfffffffd;
  return;
}


// 00691c70 FUN_00691c70

void FUN_00691c70(void)

{
  DAT_007441d4 = 0xfffffffd;
  return;
}


// 00691c80 FUN_00691c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691c80(void)

{
  if (ABS(_DAT_006cce30) < (double)_DAT_006ccae0) {
    _DAT_00705988 = 0x41c80001;
  }
  _atexit((_func_4879 *)&DAT_006965c0);
  return;
}


// 00691e40 FUN_00691e40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691e40(void)

{
  if (ABS(_DAT_006cce28) < (double)_DAT_006ccae0) {
    _DAT_0070596c = 0x432a0000;
  }
  _atexit((_func_4879 *)&DAT_00696640);
  return;
}


// 00691ec0 FUN_00691ec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691ec0(void)

{
  _DAT_00705870 = DAT_006b65c4;
  _DAT_0070586c = DAT_006b65b4;
  if (ABS(DAT_006b65c4 - DAT_006b65b4) < _DAT_006ccae0) {
    _DAT_00705870 = DAT_006b65c4 + _DAT_006ccae0;
  }
  _atexit((_func_4879 *)&DAT_00696660);
  return;
}


// 00691f10 FUN_00691f10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691f10(void)

{
  _DAT_0070588c = DAT_006b65b8;
  _DAT_00705888 = DAT_006b65a8;
  if (ABS(DAT_006b65b8 - DAT_006b65a8) < _DAT_006ccae0) {
    _DAT_0070588c = DAT_006b65b8 + _DAT_006ccae0;
  }
  _atexit((_func_4879 *)&DAT_00696670);
  return;
}


// 00691f60 FUN_00691f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691f60(void)

{
  _DAT_00736750 = DAT_006b63f0;
  _DAT_0073675c = DAT_006b63fc;
  _DAT_00736758 = DAT_006b63f8;
  _DAT_00736754 = DAT_006b63f4;
  if (ABS(DAT_006b63fc - DAT_006b63f8) < _DAT_006ccae0) {
    _DAT_0073675c = DAT_006b63fc + _DAT_006ccae0;
  }
  _DAT_00736764 = DAT_006b63f0;
  _atexit((_func_4879 *)&DAT_00696680);
  return;
}


// 00691fe0 FUN_00691fe0

void FUN_00691fe0(void)

{
  _atexit((_func_4879 *)&DAT_00696690);
  return;
}


// 00691ff0 FUN_00691ff0

void FUN_00691ff0(void)

{
  _atexit((_func_4879 *)&DAT_006966a0);
  return;
}


// 00692000 FUN_00692000

void FUN_00692000(void)

{
  _atexit((_func_4879 *)&DAT_006966b0);
  return;
}


// 00692010 FUN_00692010

void FUN_00692010(void)

{
  _atexit((_func_4879 *)&DAT_006966c0);
  return;
}


// 00692020 FUN_00692020

void FUN_00692020(void)

{
  _atexit((_func_4879 *)&DAT_006966d0);
  return;
}


// 00692030 FUN_00692030

void FUN_00692030(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006966e0);
  return;
}


// 00692050 FUN_00692050

void FUN_00692050(void)

{
  int iVar1;
  
  iVar1 = 0xc;
  do {
    FUN_00536d00();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// 00692080 FUN_00692080

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692080(void)

{
  _DAT_00743c98 = _DAT_006b6394 * _DAT_006cc7dc;
  return;
}


// 006920a0 FUN_006920a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006920a0(void)

{
  _DAT_00743c90 = _DAT_006b6398 + _DAT_006b6398;
  return;
}


// 006920b0 FUN_006920b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006920b0(void)

{
  _DAT_00743ca0 = _DAT_006b6398 * _DAT_006cc850;
  return;
}


// 006920d0 FUN_006920d0

void FUN_006920d0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006966f0);
  return;
}


// 006920f0 FUN_006920f0

void FUN_006920f0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696700);
  return;
}


// 00692110 FUN_00692110

void FUN_00692110(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696710);
  return;
}


// 00692130 FUN_00692130

void FUN_00692130(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696720);
  return;
}


// 00692150 FUN_00692150

void FUN_00692150(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696730);
  return;
}


// 00692170 FUN_00692170

void FUN_00692170(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696740);
  return;
}


// 00692190 FUN_00692190

void FUN_00692190(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696750);
  return;
}


// 006921b0 FUN_006921b0

void FUN_006921b0(void)

{
  FUN_0053e480(0x80,&LAB_00540580,FUN_005405b0,FUN_005405d0,&LAB_00540620);
  _atexit((_func_4879 *)&LAB_00696760);
  return;
}


// 006921f0 FUN_006921f0

void FUN_006921f0(void)

{
  FUN_00540c10();
  _atexit((_func_4879 *)&LAB_00696770);
  return;
}


// 00692210 FUN_00692210

void FUN_00692210(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696780);
  return;
}


// 00692250 FUN_00692250

void FUN_00692250(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006967a0);
  return;
}


// 00692270 FUN_00692270

void FUN_00692270(void)

{
  _atexit((_func_4879 *)&DAT_006967b0);
  return;
}


// 00692280 FUN_00692280

void FUN_00692280(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006967c0);
  return;
}


// 006922a0 FUN_006922a0

void FUN_006922a0(void)

{
  eh_vector_constructor_iterator
            (&DAT_00740460,0x60,0x10,FUN_005450f0,(_func_void_void_ptr *)&LAB_00545150);
  _atexit((_func_4879 *)&LAB_006967d0);
  return;
}


// 006922d0 FUN_006922d0

void FUN_006922d0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_006967f0);
  return;
}


// 006922f0 FUN_006922f0

void FUN_006922f0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696800);
  return;
}


// 00692310 FUN_00692310

void FUN_00692310(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696810);
  return;
}


// 00692330 FUN_00692330

void FUN_00692330(void)

{
  FUN_0053e480(0x80,&LAB_00546010,FUN_005405b0,&LAB_005460e0,&LAB_00546170);
  _atexit((_func_4879 *)&LAB_00696820);
  return;
}


// 00692370 FUN_00692370

void FUN_00692370(void)

{
  _atexit((_func_4879 *)&DAT_00696830);
  return;
}


// 006923b0 FUN_006923b0

void FUN_006923b0(void)

{
  _atexit((_func_4879 *)&DAT_00696840);
  return;
}


// 006923f0 FUN_006923f0

void FUN_006923f0(void)

{
  FUN_00549610();
  _atexit((_func_4879 *)&LAB_00696870);
  return;
}


// 00692410 FUN_00692410

void FUN_00692410(void)

{
  _atexit((_func_4879 *)&DAT_00696880);
  return;
}


// 00692420 FUN_00692420

void FUN_00692420(void)

{
  _atexit((_func_4879 *)&DAT_00696890);
  return;
}


// 00692430 FUN_00692430

void FUN_00692430(void)

{
  _atexit((_func_4879 *)&DAT_006968a0);
  return;
}


// 00692440 FUN_00692440

void FUN_00692440(void)

{
  _atexit((_func_4879 *)&DAT_006968b0);
  return;
}


// 00692450 FUN_00692450

void FUN_00692450(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0073d838;
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// 00692470 FUN_00692470

void FUN_00692470(void)

{
  FUN_00589260();
  _atexit((_func_4879 *)&DAT_006968c0);
  return;
}


// 00692490 FUN_00692490

void FUN_00692490(void)

{
  FUN_005671e0();
  _atexit((_func_4879 *)&LAB_006968d0);
  return;
}


// 006924b0 FUN_006924b0

void FUN_006924b0(void)

{
  DAT_0073d800 = 0xfffffffd;
  return;
}


// 006924c0 FUN_006924c0

void FUN_006924c0(void)

{
  DAT_0073d808 = 0xfffffffd;
  return;
}


// 006924d0 FUN_006924d0

void FUN_006924d0(void)

{
  DAT_0073d810 = 0xfffffffd;
  return;
}


// 006924e0 FUN_006924e0

void FUN_006924e0(void)

{
  DAT_0073d7f8 = 0xfffffffd;
  return;
}


// 006924f0 FUN_006924f0

void FUN_006924f0(void)

{
  DAT_0073d7d0 = 0xfffffffd;
  return;
}


// 00692500 FUN_00692500

void FUN_00692500(void)

{
  DAT_0073d7e0 = 0xfffffffd;
  return;
}


// 00692510 FUN_00692510

void FUN_00692510(void)

{
  DAT_0073d7e8 = 0xfffffffd;
  return;
}


// 00692520 FUN_00692520

void FUN_00692520(void)

{
  DAT_0073d7d8 = 0xfffffffd;
  return;
}


// 00692540 FUN_00692540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692540(void)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  
  DAT_0073d760 = -1;
  pcVar3 = "BOTTOM_DECAL";
  bVar2 = s_BOTTOM_DECAL_006bc038[0];
  while (bVar2 != 0) {
    DAT_0073d760 = DAT_0073d760 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d764 = -1;
  pcVar3 = "EXHAUST_TIP_DECAL";
  bVar2 = s_EXHAUST_TIP_DECAL_006bc048[0];
  while (bVar2 != 0) {
    DAT_0073d764 = DAT_0073d764 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d768 = -1;
  pcVar3 = "FRONT_BUMPER_DECAL";
  bVar2 = s_FRONT_BUMPER_DECAL_006bc05c[0];
  while (bVar2 != 0) {
    DAT_0073d768 = DAT_0073d768 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d76c = -1;
  pcVar3 = "FRONT_DECAL";
  bVar2 = s_FRONT_DECAL_006bc070[0];
  while (bVar2 != 0) {
    DAT_0073d76c = DAT_0073d76c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d770 = -1;
  pcVar3 = "GTWING_DECAL";
  bVar2 = s_GTWING_DECAL_006bc07c[0];
  while (bVar2 != 0) {
    DAT_0073d770 = DAT_0073d770 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d774 = -1;
  pcVar3 = "HOOD_DECAL";
  bVar2 = s_HOOD_DECAL_006bc08c[0];
  while (bVar2 != 0) {
    DAT_0073d774 = DAT_0073d774 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d778 = -1;
  pcVar3 = "LEFT_BRAKELIGHT_DECAL";
  bVar2 = s_LEFT_BRAKELIGHT_DECAL_006bc098[0];
  while (bVar2 != 0) {
    DAT_0073d778 = DAT_0073d778 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d77c = -1;
  pcVar3 = "LEFT_DOOR_DECAL";
  bVar2 = s_LEFT_DOOR_DECAL_006bc0b0[0];
  while (bVar2 != 0) {
    DAT_0073d77c = DAT_0073d77c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d780 = -1;
  pcVar3 = "LEFT_FENDER_DECAL";
  bVar2 = s_LEFT_FENDER_DECAL_006bc0c0[0];
  while (bVar2 != 0) {
    DAT_0073d780 = DAT_0073d780 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d784 = -1;
  pcVar3 = "LEFT_QUARTER_DECAL";
  bVar2 = s_LEFT_QUARTER_DECAL_006bc0d4[0];
  while (bVar2 != 0) {
    DAT_0073d784 = DAT_0073d784 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d788 = -1;
  pcVar3 = "LEFT_SIDE_MIRROR_DECAL";
  bVar2 = s_LEFT_SIDE_MIRROR_DECAL_006bc0e8[0];
  while (bVar2 != 0) {
    DAT_0073d788 = DAT_0073d788 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d78c = -1;
  pcVar3 = "LEFT_SKIRT_DECAL";
  bVar2 = s_LEFT_SKIRT_DECAL_006bc100[0];
  while (bVar2 != 0) {
    DAT_0073d78c = DAT_0073d78c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073d790 = -1;
  pcVar3 = "REAR_BUMPER_DECAL";
  bVar2 = s_REAR_BUMPER_DECAL_006bc114[0];
  while (bVar2 != 0) {
    DAT_0073d790 = DAT_0073d790 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d794 = -1;
  pcVar3 = "REAR_DECAL";
  bVar2 = s_REAR_DECAL_006bc128[0];
  while (bVar2 != 0) {
    _DAT_0073d794 = _DAT_0073d794 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d798 = -1;
  pcVar3 = "RIGHT_BRAKELIGHT_DECAL";
  bVar2 = s_RIGHT_BRAKELIGHT_DECAL_006bc134[0];
  while (bVar2 != 0) {
    _DAT_0073d798 = _DAT_0073d798 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d79c = -1;
  pcVar3 = "RIGHT_DOOR_DECAL";
  bVar2 = s_RIGHT_DOOR_DECAL_006bc14c[0];
  while (bVar2 != 0) {
    _DAT_0073d79c = _DAT_0073d79c * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7a0 = -1;
  pcVar3 = "RIGHT_FENDER_DECAL";
  bVar2 = s_RIGHT_FENDER_DECAL_006bc160[0];
  while (bVar2 != 0) {
    _DAT_0073d7a0 = _DAT_0073d7a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7a4 = -1;
  pcVar3 = "RIGHT_QUARTER_DECAL";
  bVar2 = s_RIGHT_QUARTER_DECAL_006bc174[0];
  while (bVar2 != 0) {
    _DAT_0073d7a4 = _DAT_0073d7a4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7a8 = -1;
  pcVar3 = "RIGHT_SIDE_MIRROR_DECAL";
  bVar2 = s_RIGHT_SIDE_MIRROR_DECAL_006bc188[0];
  while (bVar2 != 0) {
    _DAT_0073d7a8 = _DAT_0073d7a8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7ac = -1;
  pcVar3 = "RIGHT_SKIRT_DECAL";
  bVar2 = s_RIGHT_SKIRT_DECAL_006bc1a0[0];
  while (bVar2 != 0) {
    _DAT_0073d7ac = _DAT_0073d7ac * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7b0 = -1;
  pcVar3 = "TOP_DECAL";
  bVar2 = s_TOP_DECAL_006bc1b4[0];
  while (bVar2 != 0) {
    _DAT_0073d7b0 = _DAT_0073d7b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7b4 = -1;
  pcVar3 = "FRONT_WINDOW_DECAL";
  bVar2 = s_FRONT_WINDOW_DECAL_006bc1c0[0];
  while (bVar2 != 0) {
    _DAT_0073d7b4 = _DAT_0073d7b4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7b8 = -1;
  pcVar3 = "REAR_WINDOW_DECAL";
  bVar2 = s_REAR_WINDOW_DECAL_006bc1d4[0];
  while (bVar2 != 0) {
    _DAT_0073d7b8 = _DAT_0073d7b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7bc = -1;
  pcVar3 = "LEFT_FRONT_WINDOW_DECAL";
  bVar2 = s_LEFT_FRONT_WINDOW_DECAL_006bc1e8[0];
  while (bVar2 != 0) {
    _DAT_0073d7bc = _DAT_0073d7bc * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7c0 = -1;
  pcVar3 = "LEFT_REAR_WINDOW_DECAL";
  bVar2 = s_LEFT_REAR_WINDOW_DECAL_006bc200[0];
  while (bVar2 != 0) {
    _DAT_0073d7c0 = _DAT_0073d7c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_0073d7c4 = -1;
  pcVar3 = "RIGHT_FRONT_WINDOW_DECAL";
  bVar2 = s_RIGHT_FRONT_WINDOW_DECAL_006bc218[0];
  while (bVar2 != 0) {
    _DAT_0073d7c4 = _DAT_0073d7c4 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  pcVar3 = "RIGHT_REAR_WINDOW_DECAL";
  _DAT_0073d7c8 = -1;
  bVar2 = s_RIGHT_REAR_WINDOW_DECAL_006bc234[0];
  while (bVar2 != 0) {
    _DAT_0073d7c8 = _DAT_0073d7c8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// 00692980 FUN_00692980

void FUN_00692980(void)

{
  _atexit((_func_4879 *)&DAT_006968e0);
  return;
}


// 00692990 FUN_00692990

void FUN_00692990(void)

{
  FUN_0042ac70();
  _atexit((_func_4879 *)&LAB_006968f0);
  return;
}


// 006929b0 FUN_006929b0

void FUN_006929b0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696900);
  return;
}


// 006929d0 FUN_006929d0

void FUN_006929d0(void)

{
  FUN_0042ac70();
  _atexit((_func_4879 *)&LAB_00696910);
  return;
}


// 00692a10 FUN_00692a10

void FUN_00692a10(void)

{
  FUN_00573040();
  _atexit((_func_4879 *)&LAB_00696930);
  return;
}


// 00692a30 FUN_00692a30

void FUN_00692a30(void)

{
  eh_vector_constructor_iterator
            (&DAT_0073b260,0x18c,2,FUN_005739c0,(_func_void_void_ptr *)&LAB_00573aa0);
  _atexit((_func_4879 *)&LAB_00696940);
  return;
}


// 00692a60 FUN_00692a60

void FUN_00692a60(void)

{
  _atexit((_func_4879 *)&DAT_00696960);
  return;
}


// 00692a70 FUN_00692a70

void FUN_00692a70(void)

{
  _atexit((_func_4879 *)&DAT_00696970);
  return;
}


// 00692a90 FUN_00692a90

void FUN_00692a90(void)

{
  _atexit((_func_4879 *)&DAT_00696990);
  return;
}


// 00692aa0 FUN_00692aa0

void FUN_00692aa0(void)

{
  _atexit((_func_4879 *)&DAT_006969a0);
  return;
}


// 00692ab0 FUN_00692ab0

void FUN_00692ab0(void)

{
  _atexit((_func_4879 *)&DAT_006969b0);
  return;
}


// 00692ac0 FUN_00692ac0

void FUN_00692ac0(void)

{
  _atexit((_func_4879 *)&DAT_006969c0);
  return;
}


// 00692ad0 FUN_00692ad0

void FUN_00692ad0(void)

{
  _atexit((_func_4879 *)&DAT_006969d0);
  return;
}


// 00692ae0 FUN_00692ae0

void FUN_00692ae0(void)

{
  _atexit((_func_4879 *)&DAT_006969e0);
  return;
}


// 00692af0 FUN_00692af0

void FUN_00692af0(void)

{
  _atexit((_func_4879 *)&DAT_006969f0);
  return;
}


// 00692b00 FUN_00692b00

void FUN_00692b00(void)

{
  _atexit((_func_4879 *)&DAT_00696a00);
  return;
}


// 00692b10 FUN_00692b10

void FUN_00692b10(void)

{
  _atexit((_func_4879 *)&DAT_00696a10);
  return;
}


// 00692b20 FUN_00692b20

void FUN_00692b20(void)

{
  _atexit((_func_4879 *)&DAT_00696a20);
  return;
}


// 00692b30 FUN_00692b30

void FUN_00692b30(void)

{
  _atexit((_func_4879 *)&DAT_00696a30);
  return;
}


// 00692b40 FUN_00692b40

void FUN_00692b40(void)

{
  _atexit((_func_4879 *)&DAT_00696a40);
  return;
}


// 00692b80 FUN_00692b80

void FUN_00692b80(void)

{
  eh_vector_constructor_iterator
            (&DAT_0073b220,0x20,2,(_func_void_void_ptr *)&LAB_00574e30,NullUpdate_ret);
  _atexit((_func_4879 *)&LAB_00696a70);
  return;
}


// 00692bd0 FUN_00692bd0

void FUN_00692bd0(void)

{
  FUN_00577b00(&DAT_0073b118,0,0,1);
  _atexit((_func_4879 *)&LAB_00696aa0);
  return;
}


// 00692c30 FUN_00692c30

void FUN_00692c30(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696ac0);
  return;
}


// 00692c50 FUN_00692c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692c50(void)

{
  _DAT_0073b0d4 = _DAT_006b5c24 + _DAT_006b5c24;
  return;
}


// 00692c60 FUN_00692c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692c60(void)

{
  _DAT_0073b0d0 = _DAT_006b5c24 * _DAT_006cc7dc;
  return;
}


// 00692c80 FUN_00692c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692c80(void)

{
  _DAT_0073b0c8 = _DAT_006b5c28 + _DAT_006b5c28;
  return;
}


// 00692c90 FUN_00692c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00692c90(void)

{
  _DAT_0073b0c0 = _DAT_006b5c28 * _DAT_006cc850;
  return;
}


// 00692d40 FUN_00692d40

void FUN_00692d40(void)

{
  FUN_00577b00(&DAT_0073b084,"WorldObject",FUN_0057a1b0,1);
  _atexit((_func_4879 *)&LAB_00696ad0);
  return;
}


// 00692d90 FUN_00692d90

void FUN_00692d90(void)

{
  FUN_00577b00(&DAT_0073aea8,"WorldObject",FUN_0057b6d0,1);
  _atexit((_func_4879 *)&LAB_00696af0);
  return;
}


// 00692df0 FUN_00692df0

void FUN_00692df0(void)

{
  FUN_00577b00(&DAT_0073af10,"WorldObject",FUN_0057b960,1);
  _atexit((_func_4879 *)&LAB_00696b10);
  return;
}


// 00692e20 FUN_00692e20

void FUN_00692e20(void)

{
  FUN_00577b00(&DAT_0073ae74,"WorldObject",FUN_0057b740,1);
  _atexit((_func_4879 *)&LAB_00696b20);
  return;
}


// 00692e50 FUN_00692e50

void FUN_00692e50(void)

{
  FUN_00577b00(&DAT_0073af44,"WorldObject",FUN_00577f60,1);
  _atexit((_func_4879 *)&LAB_00696b30);
  return;
}


// 00692e80 FUN_00692e80

void FUN_00692e80(void)

{
  FUN_00577b00(&DAT_0073aedc,"WorldObject",FUN_0057b7b0,1);
  _atexit((_func_4879 *)&LAB_00696b40);
  return;
}


// 00692eb0 FUN_00692eb0

void FUN_00692eb0(void)

{
  FUN_00577b00(&DAT_0073afe0,"WorldObject",FUN_0057b810,1);
  _atexit((_func_4879 *)&LAB_00696b50);
  return;
}


// 00692ee0 FUN_00692ee0

void FUN_00692ee0(void)

{
  FUN_00577b00(&DAT_0073b014,"WorldObject",FUN_0057b880,1);
  _atexit((_func_4879 *)&LAB_00696b60);
  return;
}


// 00692f10 FUN_00692f10

void FUN_00692f10(void)

{
  FUN_00577b00(&DAT_0073afac,"WorldObject",FUN_0057b8f0,1);
  _atexit((_func_4879 *)&LAB_00696b70);
  return;
}


// 00692f40 FUN_00692f40

void FUN_00692f40(void)

{
  FUN_00577b00(&DAT_0073b048,"WorldObject",FUN_0057b5d0,1);
  _atexit((_func_4879 *)&LAB_00696b80);
  return;
}


// 00692f70 FUN_00692f70

void FUN_00692f70(void)

{
  FUN_0057c730();
  _atexit((_func_4879 *)&LAB_00696b90);
  return;
}


// 00692fb0 FUN_00692fb0

void FUN_00692fb0(void)

{
  DAT_0073ad30 = 0x3e64c388;
  return;
}


// 00692fe0 FUN_00692fe0

void FUN_00692fe0(void)

{
  eh_vector_constructor_iterator(&DAT_0073ad08,8,5,IList_InitEmpty_Thunk,FUN_00588de0);
  _atexit((_func_4879 *)&LAB_00696ba0);
  return;
}


// 00693030 FUN_00693030

void FUN_00693030(void)

{
  eh_vector_constructor_iterator(&DAT_0073ac70,0x18,5,FUN_0042ac70,FUN_0042ac80);
  _atexit((_func_4879 *)&LAB_00696bd0);
  return;
}


// 00693060 FUN_00693060

void FUN_00693060(void)

{
  FUN_004454d0();
  _atexit((_func_4879 *)&LAB_00696bf0);
  return;
}


// 00693080 FUN_00693080

void FUN_00693080(void)

{
  IList_InitEmpty_Thunk();
  _atexit((_func_4879 *)&LAB_00696c00);
  return;
}


// 006930a0 FUN_006930a0

void FUN_006930a0(void)

{
  FUN_00589260();
  _atexit((_func_4879 *)&LAB_00696c10);
  return;
}


// 006930c0 FUN_006930c0

void FUN_006930c0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c20);
  return;
}


// 006930e0 FUN_006930e0

void FUN_006930e0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c30);
  return;
}


// 00693100 FUN_00693100

void FUN_00693100(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c40);
  return;
}


// 00693120 FUN_00693120

void FUN_00693120(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c50);
  return;
}


// 00693140 FUN_00693140

void FUN_00693140(void)

{
  FUN_0058b2d0();
  _atexit((_func_4879 *)&LAB_00696c60);
  return;
}


// 00693180 FUN_00693180

void FUN_00693180(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c80);
  return;
}


// 006931a0 FUN_006931a0

void FUN_006931a0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696c90);
  return;
}


// 006931c0 FUN_006931c0

void FUN_006931c0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696ca0);
  return;
}


// 00693200 FUN_00693200

void FUN_00693200(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696cc0);
  return;
}


// 00693220 FUN_00693220

void FUN_00693220(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696cd0);
  return;
}


// 00693240 FUN_00693240

void FUN_00693240(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696ce0);
  return;
}


// 00693260 FUN_00693260

void FUN_00693260(void)

{
  SurfaceTable__Init(&DAT_00737818);
  return;
}


// 00693290 FUN_00693290

void FUN_00693290(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d00);
  return;
}


// 006932b0 FUN_006932b0

void FUN_006932b0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d10);
  return;
}


// 006932d0 FUN_006932d0

void FUN_006932d0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d20);
  return;
}


// 006932f0 FUN_006932f0

void FUN_006932f0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d30);
  return;
}


// 00693310 FUN_00693310

void FUN_00693310(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d40);
  return;
}


// 00693330 FUN_00693330

void FUN_00693330(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696d50);
  return;
}


// 00693350 FUN_00693350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00693350(void)

{
  _DAT_007377b0 = DAT_007043a0;
  _DAT_007377b4 = DAT_007043a4;
  _DAT_007377b8 = DAT_007043a8;
  _DAT_007377bc = DAT_007043ac;
  return;
}


// 006933a0 FUN_006933a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006933a0(void)

{
  _DAT_00737798 = -DAT_006b5a94;
  _DAT_007377a0 = _DAT_00737798;
  _DAT_00737790 = DAT_006b5a94;
  _DAT_007377a4 = _DAT_00737798;
  _DAT_00737794 = DAT_006b5a94;
  _DAT_007377ac = _DAT_00737798;
  _DAT_0073779c = DAT_006b5a94;
  _DAT_007377a8 = DAT_006b5a94;
  return;
}


// 006934c0 FUN_006934c0

void FUN_006934c0(void)

{
  FUN_0059e060(&DAT_0073765c);
  _atexit((_func_4879 *)&LAB_00696da0);
  return;
}


// 006934f0 FUN_006934f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006934f0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  
  DAT_007373a8 = -1;
  pcVar4 = "ALLCARS_BODY_1";
  uVar3 = 0x41;
  do {
    DAT_007373a8 = DAT_007373a8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007373ac = 0;
  DAT_007373ad = 1;
  pcVar4 = "ALLCARS_BODY_2";
  DAT_007373b0 = -1;
  uVar3 = 0x41;
  do {
    DAT_007373b0 = DAT_007373b0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007373b4 = 0;
  DAT_007373b5 = 2;
  pcVar4 = "ALLCARS_BODY_3";
  _DAT_007373b8 = -1;
  uVar3 = 0x41;
  do {
    _DAT_007373b8 = _DAT_007373b8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007373bc = 0;
  DAT_007373bd = 3;
  pcVar4 = "ALLCARS_BODY_4";
  _DAT_007373c0 = -1;
  uVar3 = 0x41;
  do {
    _DAT_007373c0 = _DAT_007373c0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007373c4 = 0;
  DAT_007373c5 = 4;
  pcVar4 = "ALLCARS_BODY_5";
  _DAT_007373c8 = -1;
  uVar3 = 0x41;
  do {
    _DAT_007373c8 = _DAT_007373c8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007373cc = 0;
  DAT_007373cd = 5;
  puVar5 = &DAT_006bf808;
  _DAT_007373d0 = -1;
  bVar2 = DAT_006bf808;
  while (bVar2 != 0) {
    _DAT_007373d0 = _DAT_007373d0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007373d8 = -1;
  DAT_007373d4 = 0;
  DAT_007373d5 = 6;
  pcVar4 = "ADVANCEDCLUTCH";
  bVar2 = s_ADVANCEDCLUTCH_006bf874[0];
  while (bVar2 != 0) {
    _DAT_007373d8 = _DAT_007373d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007373e0 = -1;
  DAT_007373dc = 0;
  DAT_007373dd = 7;
  puVar5 = &DAT_006bf894;
  bVar2 = DAT_006bf894;
  while (bVar2 != 0) {
    _DAT_007373e0 = _DAT_007373e0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007373e8 = -1;
  DAT_007373e4 = 0;
  DAT_007373e5 = 8;
  pcVar4 = "ALPINE";
  bVar2 = s_ALPINE_006bf8a8[0];
  while (bVar2 != 0) {
    _DAT_007373e8 = _DAT_007373e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007373f0 = -1;
  DAT_007373ec = 0;
  DAT_007373ed = 9;
  puVar5 = &DAT_006bf8c4;
  bVar2 = DAT_006bf8c4;
  while (bVar2 != 0) {
    _DAT_007373f0 = _DAT_007373f0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007373f8 = -1;
  DAT_007373f4 = 0;
  DAT_007373f5 = 10;
  puVar5 = &DAT_006bf8dc;
  bVar2 = DAT_006bf8dc;
  while (bVar2 != 0) {
    _DAT_007373f8 = _DAT_007373f8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737400 = -1;
  DAT_007373fc = 0;
  DAT_007373fd = 0xb;
  pcVar4 = "AROSPEED";
  bVar2 = s_AROSPEED_006bf8f8[0];
  while (bVar2 != 0) {
    _DAT_00737400 = _DAT_00737400 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737408 = -1;
  DAT_00737404 = 0;
  DAT_00737405 = 0xc;
  pcVar4 = "AUDIOBAHN";
  bVar2 = s_AUDIOBAHN_006bf918[0];
  while (bVar2 != 0) {
    _DAT_00737408 = _DAT_00737408 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737410 = -1;
  DAT_0073740c = 0;
  DAT_0073740d = 0xd;
  puVar5 = &DAT_006bf93c;
  bVar2 = DAT_006bf93c;
  while (bVar2 != 0) {
    _DAT_00737410 = _DAT_00737410 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737418 = -1;
  DAT_00737414 = 0;
  DAT_00737415 = 0xe;
  pcVar4 = "BILSTEIN";
  bVar2 = s_BILSTEIN_006bf950[0];
  while (bVar2 != 0) {
    _DAT_00737418 = _DAT_00737418 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737420 = -1;
  DAT_0073741c = 0;
  DAT_0073741d = 0xf;
  pcVar4 = "BORLA";
  bVar2 = s_BORLA_006bf970[0];
  while (bVar2 != 0) {
    _DAT_00737420 = _DAT_00737420 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737428 = -1;
  DAT_00737424 = 0;
  DAT_00737425 = 0x10;
  pcVar4 = "BREMBO";
  bVar2 = s_BREMBO_006bf98c[0];
  while (bVar2 != 0) {
    _DAT_00737428 = _DAT_00737428 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737430 = -1;
  DAT_0073742c = 0;
  DAT_0073742d = 0x11;
  pcVar4 = "DCSPORTS";
  bVar2 = s_DCSPORTS_006bfa20[0];
  while (bVar2 != 0) {
    _DAT_00737430 = _DAT_00737430 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737438 = -1;
  DAT_00737434 = 0;
  DAT_00737435 = 0x12;
  pcVar4 = "EIBACHSPRINGS";
  bVar2 = s_EIBACHSPRINGS_006bfa44[0];
  while (bVar2 != 0) {
    _DAT_00737438 = _DAT_00737438 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737440 = -1;
  DAT_0073743c = 0;
  DAT_0073743d = 0x13;
  puVar5 = &DAT_006bfa68;
  bVar2 = DAT_006bfa68;
  while (bVar2 != 0) {
    _DAT_00737440 = _DAT_00737440 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737448 = -1;
  DAT_00737444 = 0;
  DAT_00737445 = 0x14;
  pcVar4 = "GREDDY";
  bVar2 = s_GREDDY_006bfaf4[0];
  while (bVar2 != 0) {
    _DAT_00737448 = _DAT_00737448 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737450 = -1;
  DAT_0073744c = 0;
  DAT_0073744d = 0x15;
  puVar5 = &DAT_006b8158;
  bVar2 = DAT_006b8158;
  while (bVar2 != 0) {
    _DAT_00737450 = _DAT_00737450 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737458 = -1;
  DAT_00737454 = 0;
  DAT_00737455 = 0x16;
  puVar5 = &DAT_006bfb48;
  bVar2 = DAT_006bfb48;
  while (bVar2 != 0) {
    _DAT_00737458 = _DAT_00737458 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737460 = -1;
  DAT_0073745c = 0;
  DAT_0073745d = 0x17;
  pcVar4 = "HPRACING";
  bVar2 = s_HPRACING_006bfb78[0];
  while (bVar2 != 0) {
    _DAT_00737460 = _DAT_00737460 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737468 = -1;
  DAT_00737464 = 0;
  DAT_00737465 = 0x18;
  puVar5 = &DAT_006bfbbc;
  bVar2 = DAT_006bfbbc;
  while (bVar2 != 0) {
    _DAT_00737468 = _DAT_00737468 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737470 = -1;
  DAT_0073746c = 0;
  DAT_0073746d = 0x19;
  pcVar4 = "JACKSONRACING";
  bVar2 = s_JACKSONRACING_006bfbd8[0];
  while (bVar2 != 0) {
    _DAT_00737470 = _DAT_00737470 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737478 = -1;
  DAT_00737474 = 0;
  DAT_00737475 = 0x1a;
  pcVar4 = "KNENGINEERING";
  bVar2 = s_KNENGINEERING_006b815c[0];
  while (bVar2 != 0) {
    _DAT_00737478 = _DAT_00737478 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737480 = -1;
  DAT_0073747c = 0;
  DAT_0073747d = 0x1b;
  pcVar4 = "KENWOOD";
  bVar2 = s_KENWOOD_006bfc38[0];
  while (bVar2 != 0) {
    _DAT_00737480 = _DAT_00737480 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737488 = -1;
  DAT_00737484 = 0;
  DAT_00737485 = 0x1c;
  pcVar4 = "KEYSTONE";
  bVar2 = s_KEYSTONE_006bfc54[0];
  while (bVar2 != 0) {
    _DAT_00737488 = _DAT_00737488 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737490 = -1;
  DAT_0073748c = 0;
  DAT_0073748d = 0x1d;
  puVar5 = &DAT_006bfc60;
  bVar2 = DAT_006bfc60;
  while (bVar2 != 0) {
    _DAT_00737490 = _DAT_00737490 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737498 = -1;
  DAT_00737494 = 0;
  DAT_00737495 = 0x1e;
  puVar5 = &DAT_006bfc78;
  bVar2 = DAT_006bfc78;
  while (bVar2 != 0) {
    _DAT_00737498 = _DAT_00737498 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374a0 = -1;
  DAT_0073749c = 0;
  DAT_0073749d = 0x1f;
  pcVar4 = "KVRPERFORMANCE";
  bVar2 = s_KVRPERFORMANCE_006bfca8[0];
  while (bVar2 != 0) {
    _DAT_007374a0 = _DAT_007374a0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374a8 = -1;
  DAT_007374a4 = 1;
  DAT_007374a5 = 1;
  puVar5 = &DAT_006bfcc8;
  bVar2 = DAT_006bfcc8;
  while (bVar2 != 0) {
    _DAT_007374a8 = _DAT_007374a8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374b0 = -1;
  DAT_007374ac = 1;
  DAT_007374ad = 2;
  puVar5 = &DAT_006bfcdc;
  bVar2 = DAT_006bfcdc;
  while (bVar2 != 0) {
    _DAT_007374b0 = _DAT_007374b0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374b8 = -1;
  DAT_007374b4 = 1;
  DAT_007374b5 = 3;
  pcVar4 = "NEUSPEED";
  bVar2 = s_NEUSPEED_006bfcf4[0];
  while (bVar2 != 0) {
    _DAT_007374b8 = _DAT_007374b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374c0 = -1;
  DAT_007374bc = 1;
  DAT_007374bd = 4;
  pcVar4 = "NITROUSEXPRESS";
  bVar2 = s_NITROUSEXPRESS_006bfd28[0];
  while (bVar2 != 0) {
    _DAT_007374c0 = _DAT_007374c0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374c8 = -1;
  DAT_007374c4 = 1;
  DAT_007374c5 = 5;
  puVar5 = &DAT_006ba7a4;
  bVar2 = DAT_006ba7a4;
  while (bVar2 != 0) {
    _DAT_007374c8 = _DAT_007374c8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374d0 = -1;
  DAT_007374cc = 1;
  DAT_007374cd = 6;
  puVar5 = &DAT_006bfd48;
  bVar2 = DAT_006bfd48;
  while (bVar2 != 0) {
    _DAT_007374d0 = _DAT_007374d0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  DAT_007374d4 = 1;
  DAT_007374d5 = 7;
  puVar6 = &DAT_006c0ca0;
  _DAT_007374d8 = -1;
  uVar3 = 0x50;
  do {
    _DAT_007374d8 = _DAT_007374d8 * 0x21 + uVar3;
    pbVar1 = puVar6 + 1;
    uVar3 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  _DAT_007374e0 = -1;
  DAT_007374dc = 1;
  DAT_007374dd = 8;
  pcVar4 = "PLASMAGLOW";
  bVar2 = s_PLASMAGLOW_006bfd6c[0];
  while (bVar2 != 0) {
    _DAT_007374e0 = _DAT_007374e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374e8 = -1;
  DAT_007374e4 = 1;
  DAT_007374e5 = 9;
  pcVar4 = "RACINGHART";
  bVar2 = s_RACINGHART_006bf9d4[0];
  while (bVar2 != 0) {
    _DAT_007374e8 = _DAT_007374e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374f0 = -1;
  DAT_007374ec = 1;
  DAT_007374ed = 10;
  pcVar4 = "SCORPION";
  bVar2 = s_SCORPION_006bfd9c[0];
  while (bVar2 != 0) {
    _DAT_007374f0 = _DAT_007374f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007374f8 = -1;
  DAT_007374f4 = 1;
  DAT_007374f5 = 0xb;
  puVar5 = &DAT_006bfdbc;
  bVar2 = DAT_006bfdbc;
  while (bVar2 != 0) {
    _DAT_007374f8 = _DAT_007374f8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  DAT_007374fc = 1;
  DAT_007374fd = 0xc;
  pcVar4 = "SPARCO";
  _DAT_00737500 = -1;
  uVar3 = 0x53;
  do {
    _DAT_00737500 = _DAT_00737500 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00737508 = -1;
  DAT_00737504 = 1;
  DAT_00737505 = 0xd;
  pcVar4 = "STILLEN";
  bVar2 = s_STILLEN_006bfdec[0];
  while (bVar2 != 0) {
    _DAT_00737508 = _DAT_00737508 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737510 = -1;
  DAT_0073750c = 1;
  DAT_0073750d = 0xe;
  pcVar4 = "STREETGLOW";
  bVar2 = s_STREETGLOW_006bfe14[0];
  while (bVar2 != 0) {
    _DAT_00737510 = _DAT_00737510 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737518 = -1;
  DAT_00737514 = 1;
  DAT_00737515 = 0xf;
  pcVar4 = "EUROLITE";
  bVar2 = s_EUROLITE_006c00f0[0];
  while (bVar2 != 0) {
    _DAT_00737518 = _DAT_00737518 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737520 = -1;
  DAT_0073751c = 1;
  DAT_0073751d = 0x10;
  pcVar4 = "TOYOTIRES";
  bVar2 = s_TOYOTIRES_006bfe40[0];
  while (bVar2 != 0) {
    _DAT_00737520 = _DAT_00737520 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737528 = -1;
  DAT_00737524 = 1;
  DAT_00737525 = 0x11;
  pcVar4 = "TURBONETICS";
  bVar2 = s_TURBONETICS_006bfe70[0];
  while (bVar2 != 0) {
    _DAT_00737528 = _DAT_00737528 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737530 = -1;
  DAT_0073752c = 1;
  DAT_0073752d = 0x12;
  puVar5 = &DAT_006bfad0;
  bVar2 = DAT_006bfad0;
  while (bVar2 != 0) {
    _DAT_00737530 = _DAT_00737530 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737538 = -1;
  DAT_00737534 = 1;
  DAT_00737535 = 0x13;
  pcVar4 = "VENOM";
  bVar2 = s_VENOM_006bfe94[0];
  while (bVar2 != 0) {
    _DAT_00737538 = _DAT_00737538 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737540 = -1;
  DAT_0073753c = 1;
  DAT_0073753d = 0x14;
  pcVar4 = "WILLWOOD";
  bVar2 = s_WILLWOOD_006bfeb8[0];
  while (bVar2 != 0) {
    _DAT_00737540 = _DAT_00737540 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737548 = -1;
  DAT_00737544 = 1;
  DAT_00737545 = 0x15;
  pcVar4 = "WOLFRACEWHEELS";
  bVar2 = s_WOLFRACEWHEELS_006bfee4[0];
  while (bVar2 != 0) {
    _DAT_00737548 = _DAT_00737548 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737550 = -1;
  DAT_0073754c = 1;
  DAT_0073754d = 0x16;
  pcVar4 = "YOKOHAMA";
  bVar2 = s_YOKOHAMA_006bfef4[0];
  while (bVar2 != 0) {
    _DAT_00737550 = _DAT_00737550 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737558 = -1;
  DAT_00737554 = 1;
  DAT_00737555 = 0x17;
  pcVar4 = "ABSDYNAMICS";
  bVar2 = s_ABSDYNAMICS_006bf844[0];
  while (bVar2 != 0) {
    _DAT_00737558 = _DAT_00737558 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737560 = -1;
  DAT_0073755c = 1;
  DAT_0073755d = 0x18;
  pcVar4 = "CLUTCHMASTERS";
  bVar2 = s_CLUTCHMASTERS_006bf9a8[0];
  while (bVar2 != 0) {
    _DAT_00737560 = _DAT_00737560 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737568 = -1;
  DAT_00737564 = 1;
  DAT_00737565 = 0x19;
  pcVar4 = "HENSHINAUTO";
  bVar2 = s_HENSHINAUTO_006bfb18[0];
  while (bVar2 != 0) {
    _DAT_00737568 = _DAT_00737568 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737570 = -1;
  DAT_0073756c = 1;
  DAT_0073756d = 0x1a;
  pcVar4 = "JSPAMERICA";
  bVar2 = s_JSPAMERICA_006bfc18[0];
  while (bVar2 != 0) {
    _DAT_00737570 = _DAT_00737570 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737578 = -1;
  DAT_00737574 = 1;
  DAT_00737575 = 0x1b;
  pcVar4 = "EXTREMEDIMENSIONS";
  bVar2 = s_EXTREMEDIMENSIONS_006bfa84[0];
  while (bVar2 != 0) {
    _DAT_00737578 = _DAT_00737578 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737580 = -1;
  DAT_0073757c = 1;
  DAT_0073757d = 0x1c;
  pcVar4 = "KUMOTIRES";
  bVar2 = s_KUMOTIRES_006b816c[0];
  while (bVar2 != 0) {
    _DAT_00737580 = _DAT_00737580 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737588 = -1;
  DAT_00737584 = 1;
  DAT_00737585 = 0x1d;
  pcVar4 = "STUFF_VINYL";
  bVar2 = s_STUFF_VINYL_006b8178[0];
  while (bVar2 != 0) {
    _DAT_00737588 = _DAT_00737588 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737590 = -1;
  DAT_0073758c = 1;
  DAT_0073758d = 0x1e;
  pcVar4 = "AUTOZONE_VINYL";
  bVar2 = s_AUTOZONE_VINYL_006b8184[0];
  while (bVar2 != 0) {
    _DAT_00737590 = _DAT_00737590 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737598 = -1;
  DAT_00737594 = 1;
  DAT_00737595 = 0x1f;
  pcVar4 = "HEIRO_VINYL";
  bVar2 = s_HEIRO_VINYL_006b8194[0];
  while (bVar2 != 0) {
    _DAT_00737598 = _DAT_00737598 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375a0 = -1;
  DAT_0073759c = 2;
  DAT_0073759d = 1;
  puVar5 = &DAT_006b81a0;
  bVar2 = DAT_006b81a0;
  while (bVar2 != 0) {
    _DAT_007375a0 = _DAT_007375a0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375a8 = -1;
  DAT_007375a4 = 2;
  DAT_007375a5 = 2;
  puVar5 = &DAT_006b81a8;
  bVar2 = DAT_006b81a8;
  while (bVar2 != 0) {
    _DAT_007375a8 = _DAT_007375a8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375b0 = -1;
  DAT_007375ac = 2;
  DAT_007375ad = 3;
  pcVar4 = "CUSTOM10";
  bVar2 = s_CUSTOM10_006b81b0[0];
  while (bVar2 != 0) {
    _DAT_007375b0 = _DAT_007375b0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375b8 = -1;
  DAT_007375b4 = 2;
  DAT_007375b5 = 4;
  pcVar4 = "CUSTOM14";
  bVar2 = s_CUSTOM14_006b81bc[0];
  while (bVar2 != 0) {
    _DAT_007375b8 = _DAT_007375b8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375c0 = -1;
  DAT_007375bc = 2;
  DAT_007375bd = 5;
  puVar5 = &DAT_006b81c8;
  bVar2 = DAT_006b81c8;
  while (bVar2 != 0) {
    _DAT_007375c0 = _DAT_007375c0 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375c8 = -1;
  DAT_007375c4 = 2;
  DAT_007375c5 = 6;
  puVar5 = &DAT_006b81d0;
  bVar2 = DAT_006b81d0;
  while (bVar2 != 0) {
    _DAT_007375c8 = _DAT_007375c8 * 0x21 + (uint)bVar2;
    pbVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375d0 = -1;
  DAT_007375cc = 2;
  DAT_007375cd = 7;
  pcVar4 = "CUSTOM17";
  bVar2 = s_CUSTOM17_006b81d8[0];
  while (bVar2 != 0) {
    _DAT_007375d0 = _DAT_007375d0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375d8 = -1;
  DAT_007375d4 = 2;
  DAT_007375d5 = 8;
  pcVar4 = "CUSTOM20";
  bVar2 = s_CUSTOM20_006b81e4[0];
  while (bVar2 != 0) {
    _DAT_007375d8 = _DAT_007375d8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375e0 = -1;
  DAT_007375dc = 2;
  DAT_007375dd = 9;
  pcVar4 = "CUSTOM21";
  bVar2 = s_CUSTOM21_006b81f0[0];
  while (bVar2 != 0) {
    _DAT_007375e0 = _DAT_007375e0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375e8 = -1;
  DAT_007375e4 = 2;
  DAT_007375e5 = 10;
  pcVar4 = "CUSTOM22";
  bVar2 = s_CUSTOM22_006b81fc[0];
  while (bVar2 != 0) {
    _DAT_007375e8 = _DAT_007375e8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375f0 = -1;
  DAT_007375ec = 2;
  DAT_007375ed = 0xb;
  pcVar4 = "CUSTOM2";
  bVar2 = s_CUSTOM2_006b8208[0];
  while (bVar2 != 0) {
    _DAT_007375f0 = _DAT_007375f0 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_007375f8 = -1;
  DAT_007375f4 = 2;
  DAT_007375f5 = 0xc;
  pcVar4 = "CUSTOM1";
  bVar2 = s_CUSTOM1_006c5294[0];
  while (bVar2 != 0) {
    _DAT_007375f8 = _DAT_007375f8 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737600 = -1;
  DAT_007375fc = 2;
  DAT_007375fd = 0xd;
  pcVar4 = "CUSTOM3";
  bVar2 = s_CUSTOM3_006c528c[0];
  while (bVar2 != 0) {
    _DAT_00737600 = _DAT_00737600 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737608 = -1;
  DAT_00737604 = 2;
  DAT_00737605 = 0xe;
  pcVar4 = "CUSTOM4";
  bVar2 = s_CUSTOM4_006c5284[0];
  while (bVar2 != 0) {
    _DAT_00737608 = _DAT_00737608 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737610 = -1;
  DAT_0073760c = 2;
  DAT_0073760d = 0xf;
  pcVar4 = "CUSTOM8";
  bVar2 = s_CUSTOM8_006c527c[0];
  while (bVar2 != 0) {
    _DAT_00737610 = _DAT_00737610 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737618 = -1;
  DAT_00737614 = 2;
  DAT_00737615 = 0x10;
  pcVar4 = "CUSTOM12";
  bVar2 = s_CUSTOM12_006c5270[0];
  while (bVar2 != 0) {
    _DAT_00737618 = _DAT_00737618 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737620 = -1;
  DAT_0073761c = 2;
  DAT_0073761d = 0x11;
  pcVar4 = "CUSTOM13";
  bVar2 = s_CUSTOM13_006c5264[0];
  while (bVar2 != 0) {
    _DAT_00737620 = _DAT_00737620 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737628 = -1;
  DAT_00737624 = 2;
  DAT_00737625 = 0x12;
  pcVar4 = "CUSTOM15";
  bVar2 = s_CUSTOM15_006c5258[0];
  while (bVar2 != 0) {
    _DAT_00737628 = _DAT_00737628 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737630 = -1;
  DAT_0073762c = 2;
  DAT_0073762d = 0x13;
  pcVar4 = "CUSTOM16";
  bVar2 = s_CUSTOM16_006c524c[0];
  while (bVar2 != 0) {
    _DAT_00737630 = _DAT_00737630 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737638 = -1;
  DAT_00737634 = 2;
  DAT_00737635 = 0x14;
  pcVar4 = "CUSTOM18";
  bVar2 = s_CUSTOM18_006c5240[0];
  while (bVar2 != 0) {
    _DAT_00737638 = _DAT_00737638 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737640 = -1;
  DAT_0073763c = 2;
  DAT_0073763d = 0x15;
  pcVar4 = "CUSTOM19";
  bVar2 = s_CUSTOM19_006c5234[0];
  while (bVar2 != 0) {
    _DAT_00737640 = _DAT_00737640 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  _DAT_00737648 = -1;
  DAT_00737644 = 2;
  DAT_00737645 = 0x16;
  pcVar4 = "CUSTOM23";
  bVar2 = s_CUSTOM23_006b8210[0];
  while (bVar2 != 0) {
    _DAT_00737648 = _DAT_00737648 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + 1;
    bVar2 = *pbVar1;
  }
  DAT_0073764c = 2;
  DAT_0073764d = 0x17;
  return;
}


// 00694710 FUN_00694710

void FUN_00694710(void)

{
  _atexit((_func_4879 *)&DAT_00696dc0);
  return;
}


// 00694720 FUN_00694720

void FUN_00694720(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696dd0);
  return;
}


// 00694740 FUN_00694740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694740(void)

{
  _DAT_0073731c = _DAT_006b5938 + _DAT_006b5938;
  return;
}


// 00694750 FUN_00694750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694750(void)

{
  _DAT_00737318 = _DAT_006b5938 * _DAT_006cc7dc;
  return;
}


// 00694770 FUN_00694770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694770(void)

{
  _DAT_00737310 = _DAT_006b5940 + _DAT_006b5940;
  return;
}


// 00694780 FUN_00694780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694780(void)

{
  _DAT_00737308 = _DAT_006b5940 * _DAT_006cc850;
  return;
}


// 006947a0 FUN_006947a0

void FUN_006947a0(void)

{
  FUN_00445720();
  _atexit((_func_4879 *)&LAB_00696de0);
  return;
}


// 006947c0 FUN_006947c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006947c0(void)

{
  _DAT_007094e4 = _DAT_006a6fe8 + _DAT_006a6fe8;
  return;
}


// 006947d0 FUN_006947d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006947d0(void)

{
  _DAT_007094e0 = _DAT_006a6fe8 * _DAT_006cc7dc;
  return;
}


// 006947f0 FUN_006947f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006947f0(void)

{
  _DAT_007094d8 = _DAT_006a6ff0 + _DAT_006a6ff0;
  return;
}


// 00694800 FUN_00694800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694800(void)

{
  _DAT_007094d0 = _DAT_006a6ff0 * _DAT_006cc850;
  return;
}


// 00694820 FUN_00694820

void FUN_00694820(void)

{
  FUN_0061f160();
  _atexit((_func_4879 *)&LAB_00696df0);
  return;
}


// 00694840 FUN_00694840

void FUN_00694840(void)

{
  FUN_0061f160();
  FUN_0061f160();
  _atexit((_func_4879 *)&LAB_00696e00);
  return;
}


// 00694890 FUN_00694890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694890(void)

{
  _DAT_00709548 = _DAT_006a76e0 * _DAT_006cc7dc;
  return;
}


// 006948b0 FUN_006948b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006948b0(void)

{
  _DAT_00709540 = _DAT_006a76e8 + _DAT_006a76e8;
  return;
}


// 006948c0 FUN_006948c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006948c0(void)

{
  _DAT_00709538 = _DAT_006a76e8 * _DAT_006cc850;
  return;
}


// 006948e0 FUN_006948e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006948e0(void)

{
  _DAT_0070956c = _DAT_006a76f0 + _DAT_006a76f0;
  return;
}


// 006948f0 FUN_006948f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006948f0(void)

{
  _DAT_00709568 = _DAT_006a76f0 * _DAT_006cc7dc;
  return;
}


// 00694910 FUN_00694910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694910(void)

{
  _DAT_00709560 = _DAT_006a76f8 + _DAT_006a76f8;
  return;
}


// 00694920 FUN_00694920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694920(void)

{
  _DAT_00709558 = _DAT_006a76f8 * _DAT_006cc850;
  return;
}


// 00694940 FUN_00694940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694940(void)

{
  _DAT_0070958c = _DAT_006a7718 + _DAT_006a7718;
  return;
}


// 00694950 FUN_00694950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694950(void)

{
  _DAT_00709588 = _DAT_006a7718 * _DAT_006cc7dc;
  return;
}


// 00694970 FUN_00694970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694970(void)

{
  _DAT_00709580 = _DAT_006a7720 + _DAT_006a7720;
  return;
}


// 00694980 FUN_00694980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694980(void)

{
  _DAT_00709578 = _DAT_006a7720 * _DAT_006cc850;
  return;
}


// 006949a0 FUN_006949a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006949a0(void)

{
  _DAT_007095a4 = _DAT_006a7730 + _DAT_006a7730;
  return;
}


// 006949b0 FUN_006949b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006949b0(void)

{
  _DAT_007095a0 = _DAT_006a7730 * _DAT_006cc7dc;
  return;
}


// 006949d0 FUN_006949d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006949d0(void)

{
  _DAT_00709598 = _DAT_006a7738 + _DAT_006a7738;
  return;
}


// 006949e0 FUN_006949e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006949e0(void)

{
  _DAT_00709590 = _DAT_006a7738 * _DAT_006cc850;
  return;
}


// 00694a00 FUN_00694a00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a00(void)

{
  _DAT_007095c4 = _DAT_006a7778 + _DAT_006a7778;
  return;
}


// 00694a10 FUN_00694a10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a10(void)

{
  _DAT_007095c0 = _DAT_006a7778 * _DAT_006cc7dc;
  return;
}


// 00694a30 FUN_00694a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a30(void)

{
  _DAT_007095b8 = _DAT_006a7780 + _DAT_006a7780;
  return;
}


// 00694a40 FUN_00694a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a40(void)

{
  _DAT_007095b0 = _DAT_006a7780 * _DAT_006cc850;
  return;
}


// 00694a60 FUN_00694a60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a60(void)

{
  _DAT_007095dc = _DAT_006a7788 + _DAT_006a7788;
  return;
}


// 00694a70 FUN_00694a70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a70(void)

{
  _DAT_007095d8 = _DAT_006a7788 * _DAT_006cc7dc;
  return;
}


// 00694a90 FUN_00694a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694a90(void)

{
  _DAT_007095d0 = _DAT_006a7790 + _DAT_006a7790;
  return;
}


// 00694aa0 FUN_00694aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694aa0(void)

{
  _DAT_007095c8 = _DAT_006a7790 * _DAT_006cc850;
  return;
}


// 00694ac0 FUN_00694ac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ac0(void)

{
  _DAT_007096c4 = _DAT_006a7798 + _DAT_006a7798;
  return;
}


// 00694ad0 FUN_00694ad0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ad0(void)

{
  _DAT_007096c0 = _DAT_006a7798 * _DAT_006cc7dc;
  return;
}


// 00694af0 FUN_00694af0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694af0(void)

{
  _DAT_007096b8 = _DAT_006a77a0 + _DAT_006a77a0;
  return;
}


// 00694b00 FUN_00694b00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b00(void)

{
  _DAT_007096b0 = _DAT_006a77a0 * _DAT_006cc850;
  return;
}


// 00694b20 FUN_00694b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b20(void)

{
  _DAT_00709dbc = _DAT_006a77b0 + _DAT_006a77b0;
  return;
}


// 00694b30 FUN_00694b30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b30(void)

{
  _DAT_00709db8 = _DAT_006a77b0 * _DAT_006cc7dc;
  return;
}


// 00694b50 FUN_00694b50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b50(void)

{
  _DAT_00709db0 = _DAT_006a77b8 + _DAT_006a77b8;
  return;
}


// 00694b60 FUN_00694b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b60(void)

{
  _DAT_00709da8 = _DAT_006a77b8 * _DAT_006cc850;
  return;
}


// 00694b80 FUN_00694b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694b80(void)

{
  HMODULE hInstance;
  LPCSTR lpIconName;
  
  DAT_006dfb8c = GetModuleHandleA((LPCSTR)0x0);
  lpIconName = (LPCSTR)0x7f00;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  _DAT_006dfb90 = LoadIconA(hInstance,lpIconName);
  _DAT_006dfb94 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_006dfb98 = 0;
  _DAT_006dfb9c = 0;
  DAT_006dfba0 = &DAT_006a782c;
  _DAT_006dfba4 = 0;
  return;
}


// 00694c00 FUN_00694c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c00(void)

{
  _DAT_00709dd0 = _DAT_006a78a8 * _DAT_006cc7dc;
  return;
}


// 00694c20 FUN_00694c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c20(void)

{
  _DAT_00709dc8 = _DAT_006a78b0 + _DAT_006a78b0;
  return;
}


// 00694c30 FUN_00694c30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c30(void)

{
  _DAT_00709dc0 = _DAT_006a78b0 * _DAT_006cc850;
  return;
}


// 00694c50 FUN_00694c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c50(void)

{
  _DAT_00709dec = _DAT_006a78c0 + _DAT_006a78c0;
  return;
}


// 00694c60 FUN_00694c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c60(void)

{
  _DAT_00709de8 = _DAT_006a78c0 * _DAT_006cc7dc;
  return;
}


// 00694c80 FUN_00694c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c80(void)

{
  _DAT_00709de0 = _DAT_006a78c8 + _DAT_006a78c8;
  return;
}


// 00694c90 FUN_00694c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694c90(void)

{
  _DAT_00709dd8 = _DAT_006a78c8 * _DAT_006cc850;
  return;
}


// 00694cb0 FUN_00694cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694cb0(void)

{
  _DAT_00709e84 = _DAT_006a78d8 + _DAT_006a78d8;
  return;
}


// 00694cc0 FUN_00694cc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694cc0(void)

{
  _DAT_00709e80 = _DAT_006a78d8 * _DAT_006cc7dc;
  return;
}


// 00694ce0 FUN_00694ce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ce0(void)

{
  _DAT_00709e78 = _DAT_006a78e0 + _DAT_006a78e0;
  return;
}


// 00694cf0 FUN_00694cf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694cf0(void)

{
  _DAT_00709e70 = _DAT_006a78e0 * _DAT_006cc850;
  return;
}


// 00694d10 FUN_00694d10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d10(void)

{
  _DAT_00709e9c = _DAT_006a78e8 + _DAT_006a78e8;
  return;
}


// 00694d20 FUN_00694d20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d20(void)

{
  _DAT_00709e98 = _DAT_006a78e8 * _DAT_006cc7dc;
  return;
}


// 00694d40 FUN_00694d40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d40(void)

{
  _DAT_00709e90 = _DAT_006a78f0 + _DAT_006a78f0;
  return;
}


// 00694d50 FUN_00694d50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d50(void)

{
  _DAT_00709e88 = _DAT_006a78f0 * _DAT_006cc850;
  return;
}


// 00694d70 FUN_00694d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d70(void)

{
  _DAT_00709f0c = _DAT_006a78f8 + _DAT_006a78f8;
  return;
}


// 00694d80 FUN_00694d80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694d80(void)

{
  _DAT_00709f08 = _DAT_006a78f8 * _DAT_006cc7dc;
  return;
}


// 00694da0 FUN_00694da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694da0(void)

{
  _DAT_00709f00 = _DAT_006a7900 + _DAT_006a7900;
  return;
}


// 00694db0 FUN_00694db0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694db0(void)

{
  _DAT_00709ef8 = _DAT_006a7900 * _DAT_006cc850;
  return;
}


// 00694dd0 FUN_00694dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694dd0(void)

{
  _DAT_00709f6c = _DAT_006a7910 + _DAT_006a7910;
  return;
}


// 00694de0 FUN_00694de0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694de0(void)

{
  _DAT_00709f68 = _DAT_006a7910 * _DAT_006cc7dc;
  return;
}


// 00694e00 FUN_00694e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e00(void)

{
  _DAT_00709f60 = _DAT_006a7918 + _DAT_006a7918;
  return;
}


// 00694e10 FUN_00694e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e10(void)

{
  _DAT_00709f58 = _DAT_006a7918 * _DAT_006cc850;
  return;
}


// 00694e30 FUN_00694e30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e30(void)

{
  _DAT_00709f8c = _DAT_006a7928 + _DAT_006a7928;
  return;
}


// 00694e40 FUN_00694e40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e40(void)

{
  _DAT_00709f88 = _DAT_006a7928 * _DAT_006cc7dc;
  return;
}


// 00694e60 FUN_00694e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e60(void)

{
  _DAT_00709f80 = _DAT_006a7930 + _DAT_006a7930;
  return;
}


// 00694e70 FUN_00694e70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e70(void)

{
  _DAT_00709f78 = _DAT_006a7930 * _DAT_006cc850;
  return;
}


// 00694e90 FUN_00694e90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694e90(void)

{
  _DAT_00709fa4 = _DAT_006a7940 + _DAT_006a7940;
  return;
}


// 00694ea0 FUN_00694ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ea0(void)

{
  _DAT_00709fa0 = _DAT_006a7940 * _DAT_006cc7dc;
  return;
}


// 00694ec0 FUN_00694ec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ec0(void)

{
  _DAT_00709f98 = _DAT_006a7948 + _DAT_006a7948;
  return;
}


// 00694ed0 FUN_00694ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ed0(void)

{
  _DAT_00709f90 = _DAT_006a7948 * _DAT_006cc850;
  return;
}


// 00694ef0 FUN_00694ef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ef0(void)

{
  _DAT_0070a1e4 = _DAT_006a7950 + _DAT_006a7950;
  return;
}


// 00694f00 FUN_00694f00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694f00(void)

{
  _DAT_0070a1e0 = _DAT_006a7950 * _DAT_006cc7dc;
  return;
}


// 00694f20 FUN_00694f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694f20(void)

{
  _DAT_0070a1d8 = _DAT_006a7958 + _DAT_006a7958;
  return;
}


// 00694f30 FUN_00694f30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694f30(void)

{
  _DAT_0070a1d0 = _DAT_006a7958 * _DAT_006cc850;
  return;
}


// 00694f90 FUN_00694f90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694f90(void)

{
  _DAT_0070a484 = _DAT_006a7970 + _DAT_006a7970;
  return;
}


// 00694fa0 FUN_00694fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694fa0(void)

{
  _DAT_0070a480 = _DAT_006a7970 * _DAT_006cc7dc;
  return;
}


// 00694fc0 FUN_00694fc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694fc0(void)

{
  _DAT_0070a478 = _DAT_006a7978 + _DAT_006a7978;
  return;
}


// 00694fd0 FUN_00694fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694fd0(void)

{
  _DAT_0070a470 = _DAT_006a7978 * _DAT_006cc850;
  return;
}


// 00694ff0 FUN_00694ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00694ff0(void)

{
  _DAT_0070a4c4 = _DAT_006a7980 + _DAT_006a7980;
  return;
}


// 00695000 FUN_00695000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695000(void)

{
  _DAT_0070a4c0 = _DAT_006a7980 * _DAT_006cc7dc;
  return;
}


// 00695020 FUN_00695020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695020(void)

{
  _DAT_0070a4b8 = _DAT_006a7988 + _DAT_006a7988;
  return;
}


// 00695030 FUN_00695030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695030(void)

{
  _DAT_0070a4b0 = _DAT_006a7988 * _DAT_006cc850;
  return;
}


// 00695050 FUN_00695050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695050(void)

{
  _DAT_0070a4f4 = _DAT_006a79d0 + _DAT_006a79d0;
  return;
}


// 00695060 FUN_00695060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695060(void)

{
  _DAT_0070a4f0 = _DAT_006a79d0 * _DAT_006cc7dc;
  return;
}


// 00695080 FUN_00695080

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695080(void)

{
  _DAT_0070a4e8 = _DAT_006a79d8 + _DAT_006a79d8;
  return;
}


// 00695090 FUN_00695090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695090(void)

{
  _DAT_0070a4e0 = _DAT_006a79d8 * _DAT_006cc850;
  return;
}


// 006950b0 FUN_006950b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006950b0(void)

{
  _DAT_0070a514 = _DAT_006a79e0 + _DAT_006a79e0;
  return;
}


// 006950c0 FUN_006950c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006950c0(void)

{
  _DAT_0070a510 = _DAT_006a79e0 * _DAT_006cc7dc;
  return;
}


// 006950e0 FUN_006950e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006950e0(void)

{
  _DAT_0070a508 = _DAT_006a79e8 + _DAT_006a79e8;
  return;
}


// 006950f0 FUN_006950f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006950f0(void)

{
  _DAT_0070a500 = _DAT_006a79e8 * _DAT_006cc850;
  return;
}


// 00695110 FUN_00695110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695110(void)

{
  _DAT_0070a754 = _DAT_006a79f8 + _DAT_006a79f8;
  return;
}


// 00695120 FUN_00695120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695120(void)

{
  _DAT_0070a750 = _DAT_006a79f8 * _DAT_006cc7dc;
  return;
}


// 00695140 FUN_00695140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695140(void)

{
  _DAT_0070a748 = _DAT_006a7a00 + _DAT_006a7a00;
  return;
}


// 00695150 FUN_00695150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695150(void)

{
  _DAT_0070a740 = _DAT_006a7a00 * _DAT_006cc850;
  return;
}


// 00695170 FUN_00695170

void FUN_00695170(void)

{
  FUN_006236d0();
  _atexit((_func_4879 *)&DAT_00696e40);
  return;
}


// 00695190 FUN_00695190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695190(void)

{
  _DAT_0070cbf4 = _DAT_006a7a08 + _DAT_006a7a08;
  return;
}


// 006951a0 FUN_006951a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006951a0(void)

{
  _DAT_0070cbf0 = _DAT_006a7a08 * _DAT_006cc7dc;
  return;
}


// 006951c0 FUN_006951c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006951c0(void)

{
  _DAT_0070cbe8 = _DAT_006a7a10 + _DAT_006a7a10;
  return;
}


// 006951d0 FUN_006951d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006951d0(void)

{
  _DAT_0070cbe0 = _DAT_006a7a10 * _DAT_006cc850;
  return;
}


// 00695210 FUN_00695210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695210(void)

{
  _DAT_0070cddc = _DAT_006a7a20 + _DAT_006a7a20;
  return;
}


// 00695220 FUN_00695220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695220(void)

{
  _DAT_0070cdd8 = _DAT_006a7a20 * _DAT_006cc7dc;
  return;
}


// 00695240 FUN_00695240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695240(void)

{
  _DAT_0070cdd0 = _DAT_006a7a28 + _DAT_006a7a28;
  return;
}


// 00695250 FUN_00695250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695250(void)

{
  _DAT_0070cdc8 = _DAT_006a7a28 * _DAT_006cc850;
  return;
}


// 00695270 FUN_00695270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695270(void)

{
  _DAT_0070cecc = _DAT_006a7a38 + _DAT_006a7a38;
  return;
}


// 00695280 FUN_00695280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695280(void)

{
  _DAT_0070cec8 = _DAT_006a7a38 * _DAT_006cc7dc;
  return;
}


// 006952a0 FUN_006952a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006952a0(void)

{
  _DAT_0070cec0 = _DAT_006a7a40 + _DAT_006a7a40;
  return;
}


// 006952b0 FUN_006952b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006952b0(void)

{
  _DAT_0070ceb8 = _DAT_006a7a40 * _DAT_006cc850;
  return;
}


// 006952d0 FUN_006952d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006952d0(void)

{
  _DAT_0070cee4 = _DAT_006a7a48 + _DAT_006a7a48;
  return;
}


// 006952e0 FUN_006952e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006952e0(void)

{
  _DAT_0070cee0 = _DAT_006a7a48 * _DAT_006cc7dc;
  return;
}


// 00695300 FUN_00695300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695300(void)

{
  _DAT_0070ced8 = _DAT_006a7a50 + _DAT_006a7a50;
  return;
}


// 00695310 FUN_00695310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695310(void)

{
  _DAT_0070ced0 = _DAT_006a7a50 * _DAT_006cc850;
  return;
}


// 00695330 FUN_00695330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695330(void)

{
  _DAT_0070d38c = _DAT_006a7a58 + _DAT_006a7a58;
  return;
}


// 00695340 FUN_00695340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695340(void)

{
  _DAT_0070d388 = _DAT_006a7a58 * _DAT_006cc7dc;
  return;
}


// 00695360 FUN_00695360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695360(void)

{
  _DAT_0070d380 = _DAT_006a7a60 + _DAT_006a7a60;
  return;
}


// 00695370 FUN_00695370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695370(void)

{
  _DAT_0070d378 = _DAT_006a7a60 * _DAT_006cc850;
  return;
}


// 00695390 FUN_00695390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695390(void)

{
  _DAT_0070d36c = _DAT_006a7a84 - _DAT_006a7a80;
  return;
}


// 006953b0 FUN_006953b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006953b0(void)

{
  _DAT_0070d370 = _DAT_006a7a7c + _DAT_006a7a7c;
  return;
}


// 006953c0 FUN_006953c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006953c0(void)

{
  _DAT_0070d390 = _DAT_006a7a70 + _DAT_006a7a70;
  return;
}


// 006953d0 FUN_006953d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006953d0(void)

{
  _DAT_0070d368 = _DAT_006a7a78 + _DAT_006a7a78;
  return;
}


// 006953e0 FUN_006953e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006953e0(void)

{
  _DAT_0070d3ac = _DAT_006a7f48 + _DAT_006a7f48;
  return;
}


// 006953f0 FUN_006953f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006953f0(void)

{
  _DAT_0070d3a8 = _DAT_006a7f48 * _DAT_006cc7dc;
  return;
}


// 00695410 FUN_00695410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695410(void)

{
  _DAT_0070d3a0 = _DAT_006a7f50 + _DAT_006a7f50;
  return;
}


// 00695420 FUN_00695420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695420(void)

{
  _DAT_0070d398 = _DAT_006a7f50 * _DAT_006cc850;
  return;
}


// 00695440 FUN_00695440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695440(void)

{
  _DAT_0070d3c4 = _DAT_006a7fb0 + _DAT_006a7fb0;
  return;
}


// 00695450 FUN_00695450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695450(void)

{
  _DAT_0070d3c0 = _DAT_006a7fb0 * _DAT_006cc7dc;
  return;
}


// 00695470 FUN_00695470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695470(void)

{
  _DAT_0070d3b8 = _DAT_006a7fb8 + _DAT_006a7fb8;
  return;
}


// 00695480 FUN_00695480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695480(void)

{
  _DAT_0070d3b0 = _DAT_006a7fb8 * _DAT_006cc850;
  return;
}


// 006954a0 FUN_006954a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006954a0(void)

{
  _DAT_0070d3e4 = _DAT_006a7fc8 + _DAT_006a7fc8;
  return;
}


// 006954b0 FUN_006954b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006954b0(void)

{
  _DAT_0070d3e0 = _DAT_006a7fc8 * _DAT_006cc7dc;
  return;
}


// 006954d0 FUN_006954d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006954d0(void)

{
  _DAT_0070d3d8 = _DAT_006a7fd0 + _DAT_006a7fd0;
  return;
}


// 006954e0 FUN_006954e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006954e0(void)

{
  _DAT_0070d3d0 = _DAT_006a7fd0 * _DAT_006cc850;
  return;
}


// 00695500 FUN_00695500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695500(void)

{
  _DAT_0070d3fc = _DAT_006a7fd8 + _DAT_006a7fd8;
  return;
}


// 00695510 FUN_00695510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695510(void)

{
  _DAT_0070d3f8 = _DAT_006a7fd8 * _DAT_006cc7dc;
  return;
}


// 00695530 FUN_00695530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695530(void)

{
  _DAT_0070d3f0 = _DAT_006a7fe0 + _DAT_006a7fe0;
  return;
}


// 00695540 FUN_00695540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695540(void)

{
  _DAT_0070d3e8 = _DAT_006a7fe0 * _DAT_006cc850;
  return;
}


// 00695560 FUN_00695560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695560(void)

{
  _DAT_0070d414 = _DAT_006a7ff0 + _DAT_006a7ff0;
  return;
}


// 00695570 FUN_00695570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695570(void)

{
  _DAT_0070d410 = _DAT_006a7ff0 * _DAT_006cc7dc;
  return;
}


// 00695590 FUN_00695590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695590(void)

{
  _DAT_0070d408 = _DAT_006a7ff8 + _DAT_006a7ff8;
  return;
}


// 006955a0 FUN_006955a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006955a0(void)

{
  _DAT_0070d400 = _DAT_006a7ff8 * _DAT_006cc850;
  return;
}


// 006955c0 FUN_006955c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006955c0(void)

{
  _DAT_0070d42c = _DAT_006a8000 + _DAT_006a8000;
  return;
}


// 006955d0 FUN_006955d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006955d0(void)

{
  _DAT_0070d428 = _DAT_006a8000 * _DAT_006cc7dc;
  return;
}


// 006955f0 FUN_006955f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006955f0(void)

{
  _DAT_0070d420 = _DAT_006a8008 + _DAT_006a8008;
  return;
}


// 00695600 FUN_00695600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695600(void)

{
  _DAT_0070d418 = _DAT_006a8008 * _DAT_006cc850;
  return;
}


// 00695620 FUN_00695620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695620(void)

{
  _DAT_0070d444 = _DAT_006a8058 + _DAT_006a8058;
  return;
}


// 00695630 FUN_00695630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695630(void)

{
  _DAT_0070d440 = _DAT_006a8058 * _DAT_006cc7dc;
  return;
}


// 00695650 FUN_00695650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695650(void)

{
  _DAT_0070d438 = _DAT_006a8060 + _DAT_006a8060;
  return;
}


// 00695660 FUN_00695660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695660(void)

{
  _DAT_0070d430 = _DAT_006a8060 * _DAT_006cc850;
  return;
}


// 00695680 FUN_00695680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695680(void)

{
  _DAT_0070d45c = _DAT_006a8070 + _DAT_006a8070;
  return;
}


// 00695690 FUN_00695690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695690(void)

{
  _DAT_0070d458 = _DAT_006a8070 * _DAT_006cc7dc;
  return;
}


// 006956b0 FUN_006956b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006956b0(void)

{
  _DAT_0070d450 = _DAT_006a8078 + _DAT_006a8078;
  return;
}


// 006956c0 FUN_006956c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006956c0(void)

{
  _DAT_0070d448 = _DAT_006a8078 * _DAT_006cc850;
  return;
}


// 006956e0 FUN_006956e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006956e0(void)

{
  _DAT_0070d474 = _DAT_006a8080 + _DAT_006a8080;
  return;
}


// 006956f0 FUN_006956f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006956f0(void)

{
  _DAT_0070d470 = _DAT_006a8080 * _DAT_006cc7dc;
  return;
}


// 00695710 FUN_00695710

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695710(void)

{
  _DAT_0070d468 = _DAT_006a8088 + _DAT_006a8088;
  return;
}


// 00695720 FUN_00695720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695720(void)

{
  _DAT_0070d460 = _DAT_006a8088 * _DAT_006cc850;
  return;
}


// 00695740 FUN_00695740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695740(void)

{
  _DAT_0070d48c = _DAT_006a8098 + _DAT_006a8098;
  return;
}


// 00695750 FUN_00695750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695750(void)

{
  _DAT_0070d488 = _DAT_006a8098 * _DAT_006cc7dc;
  return;
}


// 00695770 FUN_00695770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695770(void)

{
  _DAT_0070d480 = _DAT_006a80a0 + _DAT_006a80a0;
  return;
}


// 00695780 FUN_00695780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695780(void)

{
  _DAT_0070d478 = _DAT_006a80a0 * _DAT_006cc850;
  return;
}


// 006957a0 FUN_006957a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006957a0(void)

{
  _DAT_0070d4a4 = _DAT_006a80b0 + _DAT_006a80b0;
  return;
}


// 006957b0 FUN_006957b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006957b0(void)

{
  _DAT_0070d4a0 = _DAT_006a80b0 * _DAT_006cc7dc;
  return;
}


// 006957d0 FUN_006957d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006957d0(void)

{
  _DAT_0070d498 = _DAT_006a80b8 + _DAT_006a80b8;
  return;
}


// 006957e0 FUN_006957e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006957e0(void)

{
  _DAT_0070d490 = _DAT_006a80b8 * _DAT_006cc850;
  return;
}


// 00695800 FUN_00695800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695800(void)

{
  _DAT_0070d4bc = _DAT_006a80c0 + _DAT_006a80c0;
  return;
}


// 00695810 FUN_00695810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695810(void)

{
  _DAT_0070d4b8 = _DAT_006a80c0 * _DAT_006cc7dc;
  return;
}


// 00695830 FUN_00695830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695830(void)

{
  _DAT_0070d4b0 = _DAT_006a80c8 + _DAT_006a80c8;
  return;
}


// 00695840 FUN_00695840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695840(void)

{
  _DAT_0070d4a8 = _DAT_006a80c8 * _DAT_006cc850;
  return;
}


// 00695860 FUN_00695860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695860(void)

{
  _DAT_0070d4d4 = _DAT_006a80d8 + _DAT_006a80d8;
  return;
}


// 00695870 FUN_00695870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695870(void)

{
  _DAT_0070d4d0 = _DAT_006a80d8 * _DAT_006cc7dc;
  return;
}


// 00695890 FUN_00695890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695890(void)

{
  _DAT_0070d4c8 = _DAT_006a80e0 + _DAT_006a80e0;
  return;
}


// 006958a0 FUN_006958a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006958a0(void)

{
  _DAT_0070d4c0 = _DAT_006a80e0 * _DAT_006cc850;
  return;
}


// 006958c0 FUN_006958c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006958c0(void)

{
  _DAT_0070d4ec = _DAT_006a80f0 + _DAT_006a80f0;
  return;
}


// 006958d0 FUN_006958d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006958d0(void)

{
  _DAT_0070d4e8 = _DAT_006a80f0 * _DAT_006cc7dc;
  return;
}


// 006958f0 FUN_006958f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006958f0(void)

{
  _DAT_0070d4e0 = _DAT_006a80f8 + _DAT_006a80f8;
  return;
}


// 00695900 FUN_00695900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695900(void)

{
  _DAT_0070d4d8 = _DAT_006a80f8 * _DAT_006cc850;
  return;
}


// 00695920 FUN_00695920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695920(void)

{
  _DAT_0070d504 = _DAT_006a8108 + _DAT_006a8108;
  return;
}


// 00695930 FUN_00695930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695930(void)

{
  _DAT_0070d500 = _DAT_006a8108 * _DAT_006cc7dc;
  return;
}


// 00695950 FUN_00695950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695950(void)

{
  _DAT_0070d4f8 = _DAT_006a8110 + _DAT_006a8110;
  return;
}


// 00695960 FUN_00695960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695960(void)

{
  _DAT_0070d4f0 = _DAT_006a8110 * _DAT_006cc850;
  return;
}


// 00695980 FUN_00695980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695980(void)

{
  _DAT_0070d51c = _DAT_006a8120 + _DAT_006a8120;
  return;
}


// 00695990 FUN_00695990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695990(void)

{
  _DAT_0070d518 = _DAT_006a8120 * _DAT_006cc7dc;
  return;
}


// 006959b0 FUN_006959b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006959b0(void)

{
  _DAT_0070d510 = _DAT_006a8128 + _DAT_006a8128;
  return;
}


// 006959c0 FUN_006959c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006959c0(void)

{
  _DAT_0070d508 = _DAT_006a8128 * _DAT_006cc850;
  return;
}


// 006959e0 FUN_006959e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006959e0(void)

{
  _DAT_0070d554 = _DAT_006a8138 + _DAT_006a8138;
  return;
}


// 006959f0 FUN_006959f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006959f0(void)

{
  _DAT_0070d550 = _DAT_006a8138 * _DAT_006cc7dc;
  return;
}


// 00695a10 FUN_00695a10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a10(void)

{
  _DAT_0070d548 = _DAT_006a8140 + _DAT_006a8140;
  return;
}


// 00695a20 FUN_00695a20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a20(void)

{
  _DAT_0070d540 = _DAT_006a8140 * _DAT_006cc850;
  return;
}


// 00695a40 FUN_00695a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a40(void)

{
  _DAT_0070d574 = _DAT_006a8168 + _DAT_006a8168;
  return;
}


// 00695a50 FUN_00695a50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a50(void)

{
  _DAT_0070d570 = _DAT_006a8168 * _DAT_006cc7dc;
  return;
}


// 00695a70 FUN_00695a70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a70(void)

{
  _DAT_0070d568 = _DAT_006a8170 + _DAT_006a8170;
  return;
}


// 00695a80 FUN_00695a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695a80(void)

{
  _DAT_0070d560 = _DAT_006a8170 * _DAT_006cc850;
  return;
}


// 00695aa0 FUN_00695aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695aa0(void)

{
  _DAT_0070d558 = _DAT_006a8194 - _DAT_006a8190;
  return;
}


// 00695ac0 FUN_00695ac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ac0(void)

{
  _DAT_0070d59c = _DAT_006a81e0 + _DAT_006a81e0;
  return;
}


// 00695ad0 FUN_00695ad0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ad0(void)

{
  _DAT_0070d598 = _DAT_006a81e0 * _DAT_006cc7dc;
  return;
}


// 00695af0 FUN_00695af0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695af0(void)

{
  _DAT_0070d590 = _DAT_006a81e8 + _DAT_006a81e8;
  return;
}


// 00695b00 FUN_00695b00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b00(void)

{
  _DAT_0070d588 = _DAT_006a81e8 * _DAT_006cc850;
  return;
}


// 00695b20 FUN_00695b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b20(void)

{
  _DAT_0070d57c = _DAT_006a820c - _DAT_006a8208;
  return;
}


// 00695b40 FUN_00695b40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b40(void)

{
  _DAT_0070d580 = _DAT_006a8204 + _DAT_006a8204;
  return;
}


// 00695b50 FUN_00695b50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b50(void)

{
  _DAT_0070d5a0 = _DAT_006a81f8 + _DAT_006a81f8;
  return;
}


// 00695b60 FUN_00695b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b60(void)

{
  _DAT_0070d578 = _DAT_006a8200 + _DAT_006a8200;
  return;
}


// 00695b70 FUN_00695b70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b70(void)

{
  _DAT_0070d5c4 = _DAT_006a8258 + _DAT_006a8258;
  return;
}


// 00695b80 FUN_00695b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695b80(void)

{
  _DAT_0070d5c0 = _DAT_006a8258 * _DAT_006cc7dc;
  return;
}


// 00695ba0 FUN_00695ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ba0(void)

{
  _DAT_0070d5b8 = _DAT_006a8260 + _DAT_006a8260;
  return;
}


// 00695bb0 FUN_00695bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695bb0(void)

{
  _DAT_0070d5b0 = _DAT_006a8260 * _DAT_006cc850;
  return;
}


// 00695bd0 FUN_00695bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695bd0(void)

{
  _DAT_0070d5a8 = _DAT_006a8284 - _DAT_006a8280;
  return;
}


// 00695bf0 FUN_00695bf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695bf0(void)

{
  _DAT_0070d5e4 = _DAT_006a82d8 + _DAT_006a82d8;
  return;
}


// 00695c00 FUN_00695c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c00(void)

{
  _DAT_0070d5e0 = _DAT_006a82d8 * _DAT_006cc7dc;
  return;
}


// 00695c20 FUN_00695c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c20(void)

{
  _DAT_0070d5d8 = _DAT_006a82e0 + _DAT_006a82e0;
  return;
}


// 00695c30 FUN_00695c30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c30(void)

{
  _DAT_0070d5d0 = _DAT_006a82e0 * _DAT_006cc850;
  return;
}


// 00695c50 FUN_00695c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c50(void)

{
  _DAT_0070d5c8 = _DAT_006a8304 - _DAT_006a8300;
  return;
}


// 00695c70 FUN_00695c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c70(void)

{
  _DAT_0070d5fc = _DAT_006a8360 + _DAT_006a8360;
  return;
}


// 00695c80 FUN_00695c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695c80(void)

{
  _DAT_0070d5f8 = _DAT_006a8360 * _DAT_006cc7dc;
  return;
}


// 00695ca0 FUN_00695ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ca0(void)

{
  _DAT_0070d5f0 = _DAT_006a8368 + _DAT_006a8368;
  return;
}


// 00695cb0 FUN_00695cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695cb0(void)

{
  _DAT_0070d5e8 = _DAT_006a8368 * _DAT_006cc850;
  return;
}


// 00695cd0 FUN_00695cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695cd0(void)

{
  _DAT_0070d61c = _DAT_006a83d8 + _DAT_006a83d8;
  return;
}


// 00695ce0 FUN_00695ce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ce0(void)

{
  _DAT_0070d618 = _DAT_006a83d8 * _DAT_006cc7dc;
  return;
}


// 00695d00 FUN_00695d00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d00(void)

{
  _DAT_0070d610 = _DAT_006a83e0 + _DAT_006a83e0;
  return;
}


// 00695d10 FUN_00695d10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d10(void)

{
  _DAT_0070d608 = _DAT_006a83e0 * _DAT_006cc850;
  return;
}


// 00695d30 FUN_00695d30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d30(void)

{
  _DAT_0070d634 = _DAT_006a84d8 + _DAT_006a84d8;
  return;
}


// 00695d40 FUN_00695d40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d40(void)

{
  _DAT_0070d630 = _DAT_006a84d8 * _DAT_006cc7dc;
  return;
}


// 00695d60 FUN_00695d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d60(void)

{
  _DAT_0070d628 = _DAT_006a84e0 + _DAT_006a84e0;
  return;
}


// 00695d70 FUN_00695d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d70(void)

{
  _DAT_0070d620 = _DAT_006a84e0 * _DAT_006cc850;
  return;
}


// 00695d90 FUN_00695d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695d90(void)

{
  _DAT_0070d674 = _DAT_006a8528 + _DAT_006a8528;
  return;
}


// 00695da0 FUN_00695da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695da0(void)

{
  _DAT_0070d670 = _DAT_006a8528 * _DAT_006cc7dc;
  return;
}


// 00695dc0 FUN_00695dc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695dc0(void)

{
  _DAT_0070d668 = _DAT_006a8530 + _DAT_006a8530;
  return;
}


// 00695dd0 FUN_00695dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695dd0(void)

{
  _DAT_0070d660 = _DAT_006a8530 * _DAT_006cc850;
  return;
}


// 00695e10 FUN_00695e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e10(void)

{
  _DAT_0070d68c = _DAT_006a8538 + _DAT_006a8538;
  return;
}


// 00695e20 FUN_00695e20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e20(void)

{
  _DAT_0070d688 = _DAT_006a8538 * _DAT_006cc7dc;
  return;
}


// 00695e40 FUN_00695e40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e40(void)

{
  _DAT_0070d680 = _DAT_006a8540 + _DAT_006a8540;
  return;
}


// 00695e50 FUN_00695e50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e50(void)

{
  _DAT_0070d678 = _DAT_006a8540 * _DAT_006cc850;
  return;
}


// 00695e70 FUN_00695e70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e70(void)

{
  _DAT_0070d6a4 = _DAT_006a8548 + _DAT_006a8548;
  return;
}


// 00695e80 FUN_00695e80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695e80(void)

{
  _DAT_0070d6a0 = _DAT_006a8548 * _DAT_006cc7dc;
  return;
}


// 00695ea0 FUN_00695ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ea0(void)

{
  _DAT_0070d698 = _DAT_006a8550 + _DAT_006a8550;
  return;
}


// 00695eb0 FUN_00695eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695eb0(void)

{
  _DAT_0070d690 = _DAT_006a8550 * _DAT_006cc850;
  return;
}


// 00695ed0 FUN_00695ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ed0(void)

{
  _DAT_0070d6bc = _DAT_006a8558 + _DAT_006a8558;
  return;
}


// 00695ee0 FUN_00695ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ee0(void)

{
  _DAT_0070d6b8 = _DAT_006a8558 * _DAT_006cc7dc;
  return;
}


// 00695f00 FUN_00695f00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f00(void)

{
  _DAT_0070d6b0 = _DAT_006a8560 + _DAT_006a8560;
  return;
}


// 00695f10 FUN_00695f10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f10(void)

{
  _DAT_0070d6a8 = _DAT_006a8560 * _DAT_006cc850;
  return;
}


// 00695f30 FUN_00695f30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f30(void)

{
  _DAT_0070d6d4 = _DAT_006a8568 + _DAT_006a8568;
  return;
}


// 00695f40 FUN_00695f40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f40(void)

{
  _DAT_0070d6d0 = _DAT_006a8568 * _DAT_006cc7dc;
  return;
}


// 00695f60 FUN_00695f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f60(void)

{
  _DAT_0070d6c8 = _DAT_006a8570 + _DAT_006a8570;
  return;
}


// 00695f70 FUN_00695f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f70(void)

{
  _DAT_0070d6c0 = _DAT_006a8570 * _DAT_006cc850;
  return;
}


// 00695f90 FUN_00695f90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695f90(void)

{
  _DAT_0070d6ec = _DAT_006a8578 + _DAT_006a8578;
  return;
}


// 00695fa0 FUN_00695fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695fa0(void)

{
  _DAT_0070d6e8 = _DAT_006a8578 * _DAT_006cc7dc;
  return;
}


// 00695fc0 FUN_00695fc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695fc0(void)

{
  _DAT_0070d6e0 = _DAT_006a8580 + _DAT_006a8580;
  return;
}


// 00695fd0 FUN_00695fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695fd0(void)

{
  _DAT_0070d6d8 = _DAT_006a8580 * _DAT_006cc850;
  return;
}


// 00695ff0 FUN_00695ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695ff0(void)

{
  _DAT_0070d704 = _DAT_006a85d8 + _DAT_006a85d8;
  return;
}


// 00696000 FUN_00696000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696000(void)

{
  _DAT_0070d700 = _DAT_006a85d8 * _DAT_006cc7dc;
  return;
}


// 00696020 FUN_00696020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696020(void)

{
  _DAT_0070d6f8 = _DAT_006a85e0 + _DAT_006a85e0;
  return;
}


// 00696030 FUN_00696030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696030(void)

{
  _DAT_0070d6f0 = _DAT_006a85e0 * _DAT_006cc850;
  return;
}


// 00696050 FUN_00696050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696050(void)

{
  _DAT_0070d754 = _DAT_006a8638 + _DAT_006a8638;
  return;
}


// 00696060 FUN_00696060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696060(void)

{
  _DAT_0070d750 = _DAT_006a8638 * _DAT_006cc7dc;
  return;
}


// 00696080 FUN_00696080

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696080(void)

{
  _DAT_0070d748 = _DAT_006a8640 + _DAT_006a8640;
  return;
}


// 00696090 FUN_00696090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696090(void)

{
  _DAT_0070d740 = _DAT_006a8640 * _DAT_006cc850;
  return;
}


// 006960e0 FUN_006960e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006960e0(void)

{
  _DAT_0070d7a4 = _DAT_006a8650 + _DAT_006a8650;
  return;
}


// 006960f0 FUN_006960f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006960f0(void)

{
  _DAT_0070d7a0 = _DAT_006a8650 * _DAT_006cc7dc;
  return;
}


// 00696110 FUN_00696110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696110(void)

{
  _DAT_0070d798 = _DAT_006a8658 + _DAT_006a8658;
  return;
}


// 00696120 FUN_00696120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696120(void)

{
  _DAT_0070d790 = _DAT_006a8658 * _DAT_006cc850;
  return;
}


// 00696140 FUN_00696140

void FUN_00696140(void)

{
  FUN_006218b0(&DAT_006e6fc8,&DAT_006e5fd0,0,&PTR_s_Parameters_006e7484,1,"Texture");
  _atexit((_func_4879 *)&LAB_00696e70);
  return;
}


// 00696180 FUN_00696180

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696180(void)

{
  _DAT_0070f348 = _DAT_006a8660 * _DAT_006cc7dc;
  return;
}


// 006961a0 FUN_006961a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006961a0(void)

{
  _DAT_0070f340 = _DAT_006a8668 + _DAT_006a8668;
  return;
}


// 006961b0 FUN_006961b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006961b0(void)

{
  _DAT_0070f338 = _DAT_006a8668 * _DAT_006cc850;
  return;
}


// 006963b0 FUN_006963b0

void FUN_006963b0(void)

{
  FUN_00455ae0(&DAT_0077a6d8);
  return;
}


// 006963d0 FUN_006963d0

void FUN_006963d0(void)

{
  FUN_00577f30();
  return;
}


// 006963e0 FUN_006963e0

void FUN_006963e0(void)

{
  FUN_0046a930();
  return;
}


// 00696400 FUN_00696400

void FUN_00696400(void)

{
  FUN_0045da90();
  return;
}


// 00696410 FUN_00696410

void FUN_00696410(void)

{
  FUN_005841f0();
  return;
}


// 00696420 FUN_00696420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696420(void)

{
  _DAT_00779800 = &PTR_LAB_006c81ac;
  return;
}


// 00696430 FUN_00696430

void FUN_00696430(void)

{
  FUN_0047cd70();
  return;
}


// 00696450 FUN_00696450

void FUN_00696450(void)

{
  FUN_00577f30();
  return;
}


// 00696460 FUN_00696460

void FUN_00696460(void)

{
  FUN_00481ab0(0);
  return;
}


// 00696470 FUN_00696470

void FUN_00696470(void)

{
  FUN_0048ea80();
  return;
}


// 00696480 FUN_00696480

void FUN_00696480(void)

{
  FUN_004a9d00(&DAT_00748f70);
  return;
}


// 00696490 FUN_00696490

void FUN_00696490(void)

{
  FUN_004ad990(&DAT_00746dd0);
  return;
}


// 006964c0 FUN_006964c0

void FUN_006964c0(void)

{
  FUN_00436d40();
  return;
}


// 006964e0 FUN_006964e0

void FUN_006964e0(void)

{
  eh_vector_destructor_iterator(&DAT_00746118,8,0x100,(_func_void_void_ptr *)&LAB_0049fda0);
  return;
}


// 00696500 FUN_00696500

void FUN_00696500(void)

{
  FUN_004f3d00();
  return;
}


// 00696520 FUN_00696520

void FUN_00696520(void)

{
  FUN_004fcb10();
  return;
}


// 00696530 FUN_00696530

void FUN_00696530(void)

{
  FUN_004fcb10();
  return;
}


// 00696540 FUN_00696540

void FUN_00696540(void)

{
  FUN_004fcb10();
  return;
}


// 00696550 FUN_00696550

void FUN_00696550(void)

{
  FUN_004fcb10();
  return;
}


// 00696590 FUN_00696590

void FUN_00696590(void)

{
  FUN_00436d40();
  return;
}


// 006966e0 FUN_006966e0

void FUN_006966e0(void)

{
  FUN_00533940();
  return;
}


// 006966f0 FUN_006966f0

void FUN_006966f0(void)

{
  FUN_0053e3c0();
  return;
}


// 00696700 FUN_00696700

void FUN_00696700(void)

{
  FUN_0053e3c0();
  return;
}


// 00696710 FUN_00696710

void FUN_00696710(void)

{
  FUN_0053e3c0();
  return;
}


// 00696720 FUN_00696720

void FUN_00696720(void)

{
  FUN_0053f970();
  return;
}


// 00696730 FUN_00696730

void FUN_00696730(void)

{
  FUN_00436d40();
  return;
}


// 00696740 FUN_00696740

void FUN_00696740(void)

{
  FUN_005407f0();
  return;
}


// 00696750 FUN_00696750

void FUN_00696750(void)

{
  FUN_005407f0();
  return;
}


// 00696760 FUN_00696760

void FUN_00696760(void)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  if ((int **)DAT_00743c38 != &DAT_00743c38) {
    do {
      _Memory = DAT_00743c38;
      iVar1 = *DAT_00743c38;
      piVar2 = (int *)DAT_00743c38[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      _free(_Memory);
    } while ((int **)DAT_00743c38 != &DAT_00743c38);
  }
  return;
}


// 00696770 FUN_00696770

void FUN_00696770(void)

{
  FUN_00540c20();
  return;
}


// 00696780 FUN_00696780

void FUN_00696780(void)

{
  FUN_00545060();
  return;
}


// 006967a0 FUN_006967a0

void FUN_006967a0(void)

{
  FUN_00545090();
  return;
}


// 006967c0 FUN_006967c0

void FUN_006967c0(void)

{
  FUN_005450c0();
  return;
}


// 006967d0 FUN_006967d0

void FUN_006967d0(void)

{
  eh_vector_destructor_iterator(&DAT_00740460,0x60,0x10,(_func_void_void_ptr *)&LAB_00545150);
  return;
}


// 00696800 FUN_00696800

void FUN_00696800(void)

{
  FUN_005462a0();
  return;
}


// 00696810 FUN_00696810

void FUN_00696810(void)

{
  FUN_00436d40();
  return;
}


// 00696820 FUN_00696820

void FUN_00696820(void)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  if ((int **)DAT_00740438 != &DAT_00740438) {
    do {
      _Memory = DAT_00740438;
      iVar1 = *DAT_00740438;
      piVar2 = (int *)DAT_00740438[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      _free(_Memory);
    } while ((int **)DAT_00740438 != &DAT_00740438);
  }
  return;
}


// 00696850 FUN_00696850

void FUN_00696850(void)

{
  eh_vector_destructor_iterator(&DAT_0073ddc0,0x20,3,NullUpdate_ret);
  return;
}


// 00696900 FUN_00696900

void FUN_00696900(void)

{
  FUN_005715a0();
  return;
}


// 00696910 FUN_00696910

void FUN_00696910(void)

{
  FUN_0042ac80();
  return;
}


// 00696920 FUN_00696920

void FUN_00696920(void)

{
  FUN_0042ac80();
  return;
}


// 00696930 FUN_00696930

void FUN_00696930(void)

{
  FUN_004ad8a0();
  return;
}


// 00696940 FUN_00696940

void FUN_00696940(void)

{
  eh_vector_destructor_iterator(&DAT_0073b260,0x18c,2,(_func_void_void_ptr *)&LAB_00573aa0);
  return;
}


// 00696a50 FUN_00696a50

void FUN_00696a50(void)

{
  eh_vector_destructor_iterator(&DAT_0073b158,0x30,4,NullUpdate_ret);
  return;
}


// 00696a90 FUN_00696a90

void FUN_00696a90(void)

{
  FUN_00577f30();
  return;
}


// 00696aa0 FUN_00696aa0

void FUN_00696aa0(void)

{
  FUN_00577810();
  return;
}


// 00696ab0 FUN_00696ab0

void FUN_00696ab0(void)

{
  FUN_00577810();
  return;
}


// 00696ac0 FUN_00696ac0

void FUN_00696ac0(void)

{
  FUN_00579480();
  return;
}


// 00696ad0 FUN_00696ad0

void FUN_00696ad0(void)

{
  FUN_00577810();
  return;
}


// 00696ae0 FUN_00696ae0

void FUN_00696ae0(void)

{
  FUN_0057b590();
  return;
}


// 00696af0 FUN_00696af0

void FUN_00696af0(void)

{
  FUN_00577810();
  return;
}


// 00696b00 FUN_00696b00

void FUN_00696b00(void)

{
  FUN_00577810();
  return;
}


// 00696b10 FUN_00696b10

void FUN_00696b10(void)

{
  FUN_00577810();
  return;
}


// 00696b20 FUN_00696b20

void FUN_00696b20(void)

{
  FUN_00577810();
  return;
}


// 00696b30 FUN_00696b30

void FUN_00696b30(void)

{
  FUN_00577810();
  return;
}


// 00696b40 FUN_00696b40

void FUN_00696b40(void)

{
  FUN_00577810();
  return;
}


// 00696b50 FUN_00696b50

void FUN_00696b50(void)

{
  FUN_00577810();
  return;
}


// 00696b60 FUN_00696b60

void FUN_00696b60(void)

{
  FUN_00577810();
  return;
}


// 00696b70 FUN_00696b70

void FUN_00696b70(void)

{
  FUN_00577810();
  return;
}


// 00696b80 FUN_00696b80

void FUN_00696b80(void)

{
  FUN_00577810();
  return;
}


// 00696b90 FUN_00696b90

void FUN_00696b90(void)

{
  FUN_00436d40();
  return;
}


// 00696ba0 FUN_00696ba0

void FUN_00696ba0(void)

{
  eh_vector_destructor_iterator(&DAT_0073ad08,8,5,FUN_00588de0);
  return;
}


// 00696bd0 FUN_00696bd0

void FUN_00696bd0(void)

{
  eh_vector_destructor_iterator(&DAT_0073ac70,0x18,5,FUN_0042ac80);
  return;
}


// 00696c00 FUN_00696c00

void FUN_00696c00(void)

{
  FUN_004049f0();
  return;
}


// 00696c10 FUN_00696c10

void FUN_00696c10(void)

{
  thunk_FUN_00421900();
  return;
}


// 00696c20 FUN_00696c20

void FUN_00696c20(void)

{
  FUN_00589fc0();
  return;
}


// 00696c30 FUN_00696c30

void FUN_00696c30(void)

{
  FUN_0058a400();
  return;
}


// 00696c40 FUN_00696c40

void FUN_00696c40(void)

{
  FUN_0058acb0();
  return;
}


// 00696c50 FUN_00696c50

void FUN_00696c50(void)

{
  FUN_0058acb0();
  return;
}


// 00696c60 FUN_00696c60

void FUN_00696c60(void)

{
  FUN_0058acf0(&DAT_00737b58);
  return;
}


// 00696c80 FUN_00696c80

void FUN_00696c80(void)

{
  FUN_00436d40();
  return;
}


// 00696c90 FUN_00696c90

void FUN_00696c90(void)

{
  FUN_0058d720();
  return;
}


// 00696ca0 FUN_00696ca0

void FUN_00696ca0(void)

{
  FUN_00436d40();
  return;
}


// 00696cc0 FUN_00696cc0

void FUN_00696cc0(void)

{
  FUN_0058e4c0();
  return;
}


// 00696cd0 FUN_00696cd0

void FUN_00696cd0(void)

{
  FUN_0058e500();
  return;
}


// 00696ce0 FUN_00696ce0

void FUN_00696ce0(void)

{
  FUN_005921f0();
  return;
}


// 00696cf0 FUN_00696cf0

void FUN_00696cf0(void)

{
  FUN_00592b20();
  return;
}


// 00696d00 FUN_00696d00

void FUN_00696d00(void)

{
  FUN_00593740();
  return;
}


// 00696d10 FUN_00696d10

void FUN_00696d10(void)

{
  FUN_00593b40();
  return;
}


// 00696d20 FUN_00696d20

void FUN_00696d20(void)

{
  FUN_00593b80();
  return;
}


// 00696d30 FUN_00696d30

void FUN_00696d30(void)

{
  FUN_00594f40();
  return;
}


// 00696d40 FUN_00696d40

void FUN_00696d40(void)

{
  FUN_00594f80();
  return;
}


// 00696d50 FUN_00696d50

void FUN_00696d50(void)

{
  FUN_00594f80();
  return;
}


// 00696d60 FUN_00696d60

void FUN_00696d60(void)

{
  FUN_00595050();
  return;
}


// 00696d70 FUN_00696d70

void FUN_00696d70(void)

{
  FUN_00598130();
  return;
}


// 00696e60 FUN_00696e60

void FUN_00696e60(void)

{
  if ((DAT_0070d724 != 0) && (DAT_0070d708 != 0)) {
    FUN_00621910(&DAT_0070d708);
  }
  return;
}


// 00696e70 FUN_00696e70

void FUN_00696e70(void)

{
  if ((DAT_0070d774 != 0) && (DAT_0070d758 != 0)) {
    FUN_00621910(&DAT_0070d758);
  }
  return;
}


