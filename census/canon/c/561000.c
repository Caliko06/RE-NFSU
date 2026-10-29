// ==== 0x561970 FUN_00561970

void * __thiscall FUN_00561970(void *param_1,byte param_2)

{
  FUN_00561990(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x561990 FUN_00561990

void FUN_00561990(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  
  *param_1 = &PTR_FUN_006bc7c8;
  DAT_0073d8a0 = 0;
  DAT_0073d8a4 = 0;
  puVar6 = param_1 + 0x29;
  iVar7 = 200;
  do {
    if ((void *)*puVar6 != (void *)0x0) {
      _free((void *)*puVar6);
      *puVar6 = 0;
    }
    puVar6 = puVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  piVar5 = param_1 + 0x14;
  piVar2 = (int *)param_1[0x16];
  while (piVar2 != param_1 + 0x16) {
    iVar7 = *piVar2;
    piVar3 = (int *)piVar2[1];
    *piVar3 = iVar7;
    piVar1 = piVar2 + 2;
    *(int **)(iVar7 + 4) = piVar3;
    piVar3 = (int *)*piVar1;
    while (piVar3 != piVar1) {
      piVar4 = (int *)FUN_00421960();
      iVar7 = *piVar4;
      piVar3 = (int *)piVar4[1];
      *piVar3 = iVar7;
      *(int **)(iVar7 + 4) = piVar3;
      _free(piVar4);
      piVar3 = (int *)*piVar1;
    }
    _free(piVar2);
    piVar2 = (int *)param_1[0x16];
  }
  piVar2 = (int *)*piVar5;
  while (piVar2 != piVar5) {
    iVar7 = *piVar2;
    piVar3 = (int *)piVar2[1];
    *piVar3 = iVar7;
    piVar1 = piVar2 + 2;
    *(int **)(iVar7 + 4) = piVar3;
    piVar3 = (int *)*piVar1;
    while (piVar3 != piVar1) {
      piVar4 = (int *)FUN_00421960();
      iVar7 = *piVar4;
      piVar3 = (int *)piVar4[1];
      *piVar3 = iVar7;
      *(int **)(iVar7 + 4) = piVar3;
      _free(piVar4);
      piVar3 = (int *)*piVar1;
    }
    _free(piVar2);
    piVar2 = (int *)*piVar5;
  }
  FUN_004f7b50();
  return;
}


// ==== 0x561a80 FUN_00561a80

uint __thiscall FUN_00561a80(int param_1,uint param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_2 < 0x911c0a4c) {
    if (param_2 == 0x911c0a4b) {
      uVar4 = FUN_00561b50(param_1,1);
      return uVar4;
    }
    if (param_2 == 0x72619778) {
      uVar4 = FUN_00561b50(param_1,0xffffffff);
      return uVar4;
    }
    if (param_2 == 0x911ab364) {
      uVar4 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return uVar4;
    }
  }
  else if (param_2 == 0xc519bfc0) {
    pcVar2 = *(char **)(param_1 + 0xc);
    DAT_00777c30 = *pcVar2;
    if (DAT_00777c30 != '\0') {
      pcVar5 = &DAT_00777c30;
      do {
        cVar1 = (pcVar2 + -0x777c2f)[(int)pcVar5];
        pcVar5 = pcVar5 + 1;
        *pcVar5 = cVar1;
      } while (cVar1 != '\0');
    }
    iVar3 = DAT_0073578c;
    param_2 = *(uint *)(param_1 + 0xc);
    if (DAT_0073578c != 0) {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      param_2 = 0;
      if ((iVar6 != 0) && (param_2 = 0, *(int *)(iVar6 + 0x18) != 0)) {
        param_2 = FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar6 + 0x18));
      }
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004f7d30();
    uVar4 = FUN_00561c50();
    return uVar4;
  }
  return param_2;
}


// ==== 0x561b50 FUN_00561b50

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00561b50(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_1004;
  undefined1 local_1000 [2048];
  undefined1 local_800 [2044];
  undefined4 uStack_4;
  
  uStack_4 = 0x561b5a;
  param_2 = *(int *)(param_1 + 0x3cc) + param_2;
  iVar1 = *(int *)(param_1 + 0x3c4) + -0xe;
  *(int *)(param_1 + 0x3cc) = param_2;
  if (iVar1 < param_2) {
    *(int *)(param_1 + 0x3cc) = iVar1;
  }
  if (*(int *)(param_1 + 0x3cc) < 0) {
    *(undefined4 *)(param_1 + 0x3cc) = 0;
  }
  piVar2 = (int *)(param_1 + 0x6c);
  local_1004 = 0;
  do {
    iVar1 = *piVar2;
    if (*(int *)(param_1 + 0xa4 + (*(int *)(param_1 + 0x3cc) + local_1004) * 4) == 0) {
      FUN_0059ff40(local_800,0x800);
    }
    else {
      FUN_0059ff40(local_1000,0x800);
    }
    WString_Assign();
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    local_1004 = local_1004 + 1;
    piVar2 = piVar2 + 1;
  } while (local_1004 < 0xe);
  return;
}


// ==== 0x561c50 FUN_00561c50

void FUN_00561c50(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  piVar5 = (int *)(unaff_ESI + 0x40);
  iVar4 = 3;
  do {
    if ((*piVar5 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar1 != '\0') {
        iVar2 = *(int *)(*piVar5 + 0x10);
        if (iVar2 == -0x5597403a) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar7 = *(int *)(iVar2 + 0x18), iVar7 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar6 = 0x911c0a4b;
LAB_00561d37:
            (**(code **)(*piVar3 + 8))(uVar6,0,0,iVar7);
          }
        }
        else if (iVar2 == -0x55974029) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar7 = *(int *)(iVar2 + 0x18), iVar7 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar6 = 0x72619778;
            goto LAB_00561d37;
          }
        }
        else if (iVar2 == -0x378110ae) {
          FUN_004c96c0(0xc519bfc0);
        }
      }
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x561d50 FUN_00561d50

undefined4 FUN_00561d50(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687623;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x188);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00561db0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x561db0 FUN_00561db0

undefined4 * FUN_00561db0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687643;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x17;
  *param_1 = &PTR_FUN_006bc74c;
  puVar2 = param_1 + 0x19;
  *puVar1 = puVar1;
  param_1[0x18] = puVar1;
  *puVar2 = puVar2;
  param_1[0x1a] = puVar2;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  local_4 = 1;
  param_1[0x1e] = 10;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  *(undefined1 *)(param_1 + 0x24) = 1;
  param_1[0x61] = 0;
  FUN_005627e0();
  FUN_005622d0();
  *(undefined1 *)(param_1 + 8) = 1;
  piVar5 = param_1 + 0x10;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  if (param_1[3] == 0) {
LAB_00561e63:
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0xda9a39d5);
    }
  }
  else {
    iVar4 = FEngFindPackage();
    if (iVar4 == 0) goto LAB_00561e63;
    iVar4 = FUN_004ffb70();
    if (iVar4 == 0) goto LAB_00561e63;
  }
  param_1[0x10] = iVar4;
  if (param_1[3] == 0) {
LAB_00561ea3:
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0xda9a39d4);
    }
  }
  else {
    iVar4 = FEngFindPackage();
    if (iVar4 == 0) goto LAB_00561ea3;
    iVar4 = FUN_004ffb70();
    if (iVar4 == 0) goto LAB_00561ea3;
  }
  param_1[0x11] = iVar4;
  if (param_1[3] == 0) {
LAB_00561ee4:
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0xda96ef8f);
    }
  }
  else {
    iVar4 = FEngFindPackage();
    if (iVar4 == 0) goto LAB_00561ee4;
    iVar4 = FUN_004ffb70();
    if (iVar4 == 0) goto LAB_00561ee4;
  }
  param_1[0x12] = iVar4;
  if (param_1[3] != 0) {
    iVar4 = FEngFindPackage();
    if (iVar4 != 0) {
      iVar4 = FUN_004ffb70();
      if (iVar4 != 0) goto LAB_00561f41;
    }
  }
  if (DAT_0073578c == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_004ef050(0xda96ef8e);
  }
LAB_00561f41:
  param_1[0x13] = iVar4;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
    if ((DAT_0073578c == 0) || (iVar3 = *(int *)(DAT_0073578c + 8), iVar3 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004fd1e0(iVar3 + 0xdc);
      if (iVar4 == 0) {
        iVar4 = FUN_004fd1e0(iVar3 + 0xec);
      }
    }
  }
  param_1[0x16] = iVar4;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x561fb0 FUN_00561fb0

void * __thiscall FUN_00561fb0(void *param_1,byte param_2)

{
  FUN_00561fd0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x561fd0 FUN_00561fd0

void __fastcall FUN_00561fd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc74c;
  if (DAT_0073d8d0 != 0) {
    if (DAT_0073d8a8 != 0) {
      FUN_00664c70(DAT_0073d8d0,6,DAT_0073d8a8);
      DAT_0073d8a8 = 0;
    }
    DAT_0073d8bc = 0xffffffff;
    DAT_0073d8c0 = 0;
    DAT_0073d8ac = 0;
    DAT_0073d8b0 = 0;
    DAT_0073d8b4 = 0;
    DAT_0073d8b8 = 0;
  }
  FUN_00494890();
  FUN_00494890();
  FUN_004f7b50();
  return;
}


// ==== 0x562050 FUN_00562050

void __thiscall FUN_00562050(int param_1,uint param_2,int param_3)

{
  if (param_2 < 0xb5971bf2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 == 0x911ab364) {
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x9120409e) {
        return;
      }
    }
    if (param_3 != 0) {
      if (*(int *)(param_3 + 0x10) == 0x14986350) {
        FUN_00562630();
        return;
      }
      if (*(int *)(param_3 + 0x10) == 0x6578fb3f) {
        FUN_00562660();
        return;
      }
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_00562420(param_1);
    FUN_005620d0(param_1);
  }
  return;
}


// ==== 0x5620d0 FUN_005620d0

void FUN_005620d0(int param_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int local_8;
  
  piVar6 = (int *)(param_1 + 0x40);
  local_8 = 6;
  do {
    if (((*piVar6 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 != '\0')) {
      uVar1 = *(uint *)(*piVar6 + 0x10);
      if (uVar1 < 0xda9a39d5) {
        if (uVar1 == 0xda9a39d4) {
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
             (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
            if (DAT_0073578c == 0) goto LAB_005621c7;
            iVar5 = FUN_004ef050(0x6578fb3f);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar6,*(undefined4 *)(param_1 + 0x58),iVar5,0);
          }
        }
        else if (uVar1 == 0xda96ef8e) {
          uVar3 = *(undefined4 *)(param_1 + 0x58);
          uVar4 = FEngFindObject();
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0x9120409e,*piVar6,uVar3,uVar4,0);
          }
        }
        else if (uVar1 == 0xda96ef8f) {
          uVar3 = FEngFindObject();
          FEngSendMessageToObject(0x9120409e,uVar3);
        }
      }
      else if (uVar1 == 0xda9a39d5) {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c == 0) goto LAB_005621c7;
          iVar5 = FUN_004ef050(0x14986350);
        }
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xb5971bf1,*piVar6,*(undefined4 *)(param_1 + 0x58),iVar5,0);
        }
      }
    }
LAB_005621c7:
    piVar6 = piVar6 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x5622d0 FUN_005622d0

void FUN_005622d0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  int in_EAX;
  int *piVar5;
  int iVar6;
  
  if (0 < *(int *)(in_EAX + 0x78)) {
    iVar6 = 1;
    do {
      piVar5 = _malloc(0x14);
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar1 = piVar5 + 2;
        *piVar1 = (int)piVar1;
        piVar5[3] = (int)piVar1;
        piVar5[4] = 0;
      }
      puVar2 = *(undefined4 **)(in_EAX + 0x60);
      *puVar2 = piVar5;
      *(int **)(in_EAX + 0x60) = piVar5;
      piVar5[1] = (int)puVar2;
      *piVar5 = in_EAX + 0x5c;
      if (*(int *)(in_EAX + 0x74) == 0) {
        *(undefined4 *)(in_EAX + 0x74) = *(undefined4 *)(in_EAX + 0x5c);
      }
      uVar3 = *(undefined4 *)(in_EAX + 0x60);
      FUN_00562390(in_EAX,uVar3);
      FUN_00562390(in_EAX,uVar3);
      FUN_00562390(in_EAX,uVar3);
      FUN_00562390(in_EAX,uVar3);
      bVar4 = iVar6 < *(int *)(in_EAX + 0x78);
      iVar6 = iVar6 + 1;
    } while (bVar4);
  }
  FUN_004f9240(in_EAX + 0x5c);
  return;
}


// ==== 0x562390 FUN_00562390

void __thiscall FUN_00562390(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  bSPrintf_regdst(0x20,"%s%02d",param_1);
  iVar2 = *(int *)(param_2 + 0xc);
  uVar1 = FEng__HashName();
  if (iVar2 != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_00562401;
    }
  }
  if (DAT_0073578c != 0) {
    uVar1 = FUN_004ef050(uVar1);
    PtrList__PushBack(param_3,uVar1);
    return;
  }
  iVar2 = 0;
LAB_00562401:
  PtrList__PushBack(param_3,iVar2);
  return;
}


// ==== 0x562420 FUN_00562420

void FUN_00562420(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 local_35;
  int local_34;
  int local_30;
  uint local_2c [3];
  undefined1 auStack_20 [32];
  
  if (*(char *)(param_1 + 0x90) != '\0') {
    iVar7 = param_1 + 0x5c;
    *(undefined1 *)(param_1 + 0x90) = 0;
    local_30 = iVar7;
    FUN_004f9340(iVar7);
    local_34 = 0;
    if (0 < *(int *)(param_1 + 0x78)) {
      puVar1 = (undefined4 *)(param_1 + 100);
      do {
        iVar5 = local_34;
        piVar4 = _malloc(0x10);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar2 = piVar4 + 2;
          *piVar2 = (int)piVar2;
          piVar4[3] = (int)piVar2;
        }
        puVar3 = *(undefined4 **)(param_1 + 0x68);
        *puVar3 = piVar4;
        *(int **)(param_1 + 0x68) = piVar4;
        piVar4[1] = (int)puVar3;
        *piVar4 = (int)puVar1;
        if (*(int *)(iVar7 + 0x14) == 0) {
          *(undefined4 *)(iVar7 + 0x14) = *puVar1;
        }
        if (*(int *)(iVar7 + 0x10) == 0) {
          *(undefined4 *)(iVar7 + 0x10) = *puVar1;
        }
        if (((DAT_0073d8d0 == 0) || (DAT_0073d8a8 == 0)) ||
           (iVar5 = FUN_00666f30(DAT_0073d8a8,iVar5), iVar5 == 0)) {
          local_35 = 0;
          StringList__AddEntry(piVar4,&local_35);
          StringList__AddEntry(piVar4,&local_35);
          StringList__AddEntry(piVar4,&local_35);
          puVar6 = &local_35;
        }
        else {
          FUN_006682f0(iVar5 + 0x28,local_2c,0xc,&DAT_006bc79c);
          StringList__AddEntry(piVar4,iVar5 + 8);
          if (*(int *)(param_1 + 0x84) == 3) {
            FUN_00565da0(&DAT_006ca778,local_2c[0]);
          }
          else {
            FUN_00565da0("%02d:%02d:%02d",local_2c[0] / 60000,(local_2c[0] % 60000) / 1000,
                         ((local_2c[0] % 60000) % 1000) / 10);
            iVar7 = local_30;
          }
          StringList__AddEntry(piVar4,auStack_20);
          GetCarModelNameHash();
          iVar5 = LanguageStrings__FindByHash();
          if (iVar5 == 0) {
            iVar5 = LanguageStrings__FindByHash();
          }
          StringList__AddEntry(piVar4,iVar5);
          puVar6 = (undefined1 *)LanguageStrings__FindByHash();
          if (puVar6 == (undefined1 *)0x0) {
            puVar6 = (undefined1 *)LanguageStrings__FindByHash();
          }
        }
        StringList__AddEntry(piVar4,puVar6);
        local_34 = local_34 + 1;
      } while (local_34 < *(int *)(param_1 + 0x78));
    }
    if (*(int *)(iVar7 + 0x18) != 0) {
      FUN_004f8dd0(*(int *)(iVar7 + 0x18));
    }
    FUN_004f9240(iVar7);
  }
  return;
}


// ==== 0x562630 FUN_00562630

void FUN_00562630(void)

{
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    FUN_00562690();
    return;
  }
  if (in_EAX == -0x4a68e40f) {
    FUN_00562690();
    return;
  }
  return;
}


// ==== 0x562660 FUN_00562660

void FUN_00562660(void)

{
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    FUN_005627e0();
    return;
  }
  if (in_EAX == -0x4a68e40f) {
    FUN_005627e0();
  }
  return;
}


// ==== 0x562690 FUN_00562690

void __fastcall FUN_00562690(int param_1)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x88) + in_EAX;
  iVar2 = *(int *)(param_1 + 0x184) + -1;
  *(int *)(param_1 + 0x88) = iVar4;
  if (iVar2 <= iVar4) {
    *(int *)(param_1 + 0x88) = iVar2;
  }
  iVar2 = 0;
  if (*(int *)(param_1 + 0x88) < 1) {
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  iVar4 = *(int *)(param_1 + 0x94 + *(int *)(param_1 + 0x88) * 4);
  if (((DAT_00736168 != 0) && (-1 < iVar4)) && (iVar4 < DAT_0073616c)) {
    iVar2 = iVar4 * 0xfc + DAT_00736168;
  }
  uVar3 = FUN_004f42f0("TRACK_NAME_%d",(int)*(short *)(iVar2 + 0x6c));
  FUN_00495f00(uVar3);
  sVar1 = *(short *)(iVar2 + 0x6c);
  if (((1099 < sVar1) && (0x4af < sVar1)) && (sVar1 < 0x514)) {
    switch(sVar1) {
    case 0x4b1:
      break;
    case 0x4b2:
      break;
    case 0x4b6:
      break;
    case 0x4b7:
      break;
    case 0x4ba:
      break;
    case 0x4be:
    }
  }
  *(undefined1 *)(param_1 + 0x90) = 1;
  FUN_0054ae10(FUN_00562910,param_1);
  return;
}


// ==== 0x5627e0 FUN_005627e0

void FUN_005627e0(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x84) + in_EAX;
  *(int *)(unaff_ESI + 0x84) = iVar1;
  if (2 < iVar1) {
    *(undefined4 *)(unaff_ESI + 0x84) = 3;
  }
  if (*(int *)(unaff_ESI + 0x84) < 1) {
    *(undefined4 *)(unaff_ESI + 0x84) = 0;
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  *(undefined4 *)(unaff_ESI + 0x8c) =
       *(undefined4 *)(&UNK_006bc76c + *(int *)(unaff_ESI + 0x84) * 4);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  FUN_005628a0();
  FUN_00562690();
  return;
}


// ==== 0x5628a0 FUN_005628a0

void __fastcall FUN_005628a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_0073616c;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  iVar1 = DAT_00736168;
  iVar5 = DAT_00736168;
  if (0 < iVar2) {
    do {
      if (((iVar1 == 0) || (iVar3 < 0)) || (iVar4 = iVar5, iVar2 <= iVar3)) {
        iVar4 = 0;
      }
      if (((*(uint *)(param_1 + 0x8c) & *(uint *)(iVar4 + 0x74)) != 0) &&
         (*(int *)(param_1 + 0x184) < 0x3c)) {
        *(int *)(param_1 + 0x94 + *(int *)(param_1 + 0x184) * 4) = iVar3;
        *(int *)(param_1 + 0x184) = *(int *)(param_1 + 0x184) + 1;
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0xfc;
    } while (iVar3 < iVar2);
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}


// ==== 0x562910 FUN_00562910

void FUN_00562910(undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined1 *)(param_3 + 0x90) = 1;
  return;
}


// ==== 0x562920 FUN_00562920

void FUN_00562920(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = &PTR_FUN_006bc72c;
  FUN_004f84d0();
  _Memory = (int *)unaff_EDI[0x10];
  while (_Memory != unaff_EDI + 0x10) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)unaff_EDI[0x10];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x562970 FUN_00562970

void * __thiscall FUN_00562970(void *param_1,byte param_2)

{
  FUN_00562920();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x562990 FUN_00562990

undefined4 FUN_00562990(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688d83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005629f0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5629f0 FUN_005629f0

undefined4 * FUN_005629f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688d5e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006bc72c;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"car_thumb3","car_thumb");
  local_4 = CONCAT31(local_4._1_3_,2);
  param_1[0x22] = 0;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  FUN_00562b50();
  FUN_004b2480();
  *(undefined1 *)(param_1 + 8) = 1;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar2 + 0x18));
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x562ad0 FUN_00562ad0

void FUN_00562ad0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == -0x6ee54c9c) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar1 + 0x18));
    }
    iVar1 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return;
}


// ==== 0x562b50 FUN_00562b50

void FUN_00562b50(void)

{
  undefined4 uVar1;
  
  if (DAT_00748850 != -1) {
    bSPrintf_regdst(0x20,"BRAND_NAME_%s",DAT_00748850 * 0xc90 + 0xc0 + DAT_00734588);
    uVar1 = FEng__HashName();
    FUN_00495f00(uVar1);
    uVar1 = GetSecondaryLogoHash();
    FUN_004ad7b0(uVar1);
  }
  return;
}


// ==== 0x562bc0 FUN_00562bc0

undefined4 FUN_00562bc0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006896b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x2ee7c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00562c20(pvVar1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x562c20 FUN_00562c20

undefined4 * __thiscall FUN_00562c20(int param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689690;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_2,param_1);
  pcVar2 = (char *)param_2[3];
  *param_2 = &PTR_FUN_006bc640;
  param_2[0x13] = *(undefined4 *)(param_1 + 4);
  DAT_00734bc8 = *pcVar2;
  local_4 = 0;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  FUN_00563550();
  *(undefined1 *)(param_2 + 8) = 1;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  if (((param_2[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xaa68bfd7);
    }
  }
  param_2[0x10] = iVar5;
  if (((param_2[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xaa68bfc6);
    }
  }
  param_2[0x11] = iVar5;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if (iVar3 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004fd1e0(iVar3 + 0xdc);
        if (iVar5 == 0) {
          iVar5 = FUN_004fd1e0(iVar3 + 0xec);
        }
      }
    }
  }
  param_2[0x12] = iVar5;
  if (param_2[3] == 0) {
LAB_00562e11:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246a), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00562e33;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00562dda:
      local_4._0_1_ = 1;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_00562e11;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00562e11;
      goto LAB_00562dda;
    }
LAB_00562e33:
    iVar5 = 0;
  }
  param_2[0x14] = iVar5;
  if (param_2[3] == 0) {
LAB_00562ed9:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246b), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00562efb;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00562ea2:
      local_4._0_1_ = 2;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_00562ed9;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00562ed9;
      goto LAB_00562ea2;
    }
LAB_00562efb:
    iVar5 = 0;
  }
  param_2[0x15] = iVar5;
  if (param_2[3] == 0) {
LAB_00562fa1:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246c), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00562fc3;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00562f6a:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_00562fa1;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00562fa1;
      goto LAB_00562f6a;
    }
LAB_00562fc3:
    iVar5 = 0;
  }
  param_2[0x16] = iVar5;
  if (param_2[3] == 0) {
LAB_00563067:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246d), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00563089;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00563030:
      local_4._0_1_ = 4;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_00563067;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00563067;
      goto LAB_00563030;
    }
LAB_00563089:
    iVar5 = 0;
  }
  param_2[0x17] = iVar5;
  if (param_2[3] == 0) {
LAB_0056312f:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246e), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00563151;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005630f8:
      local_4._0_1_ = 5;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0056312f;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_0056312f;
      goto LAB_005630f8;
    }
LAB_00563151:
    iVar5 = 0;
  }
  param_2[0x18] = iVar5;
  if (param_2[3] == 0) {
LAB_005631f7:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a246f), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00563219;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005631c0:
      local_4._0_1_ = 6;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_005631f7;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_005631f7;
      goto LAB_005631c0;
    }
LAB_00563219:
    iVar5 = 0;
  }
  param_2[0x19] = iVar5;
  if (param_2[3] == 0) {
LAB_005632bd:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a2470), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_005632df;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00563286:
      local_4._0_1_ = 7;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_005632bd;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_005632bd;
      goto LAB_00563286;
    }
LAB_005632df:
    iVar5 = 0;
  }
  param_2[0x1a] = iVar5;
  if (param_2[3] == 0) {
LAB_00563385:
    if (((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(0x334a2471), iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_005633a7;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0056334e:
      local_4._0_1_ = 8;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_00563385;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00563385;
      goto LAB_0056334e;
    }
LAB_005633a7:
    iVar5 = 0;
  }
  param_2[0x1b] = iVar5;
  if (param_2[3] == 0) {
LAB_0056344d:
    if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0x334a2472), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) == 2)) goto LAB_00563471;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00563416:
      local_4._0_1_ = 9;
      FUN_004ffb00(iVar5);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0056344d;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_0056344d;
      goto LAB_00563416;
    }
  }
  iVar5 = 0;
LAB_00563471:
  param_2[0x1c] = iVar5;
  FUN_005637a0();
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x5634a0 FUN_005634a0

void * __thiscall FUN_005634a0(void *param_1,byte param_2)

{
  FUN_005634c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5634c0 FUN_005634c0

void __fastcall FUN_005634c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc640;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x5634e0 FUN_005634e0

void __thiscall FUN_005634e0(int param_1,uint param_2)

{
  if (param_2 < 0x911c0a4c) {
    if (param_2 == 0x911c0a4b) {
      FUN_005637a0();
      return;
    }
    if (param_2 == 0x72619778) {
      FUN_005637a0();
      return;
    }
    if (param_2 == 0x911ab364) {
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_0054d630();
    FUN_005638d0();
  }
  return;
}


// ==== 0x563515 FUN_00563515

void FUN_00563515(void)

{
  FUN_005637a0();
  return;
}


// ==== 0x563523 FUN_00563523

void FUN_00563523(void)

{
  FUN_005637a0();
  return;
}


// ==== 0x563550 FUN_00563550

void FUN_00563550(void)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  void *_Memory;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x2ee78) = 0;
  *(undefined4 *)(unaff_EDI + 0x2ee74) = 0;
  puVar3 = (undefined1 *)(unaff_EDI + 0x74);
  iVar6 = 0x5dc;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 0x80;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  switch(DAT_006ee6f0) {
  case 1:
    pcVar8 = "LANGUAGES\\agree.fre";
    break;
  case 2:
    pcVar8 = "LANGUAGES\\agree.ger";
    break;
  case 3:
    pcVar8 = "LANGUAGES\\agree.ita";
    break;
  case 4:
    pcVar8 = "LANGUAGES\\agree.spa";
    break;
  case 5:
    pcVar8 = "LANGUAGES\\agree.dut";
    break;
  case 6:
    pcVar8 = "LANGUAGES\\agree.swe";
    break;
  case 7:
    pcVar8 = "LANGUAGES\\agree.kor";
    break;
  case 8:
    pcVar8 = "LANGUAGES\\agree.chi";
    break;
  default:
    pcVar8 = "LANGUAGES\\agree.eng";
  }
  if (DAT_00734998 == 0) {
    pcVar8 = "LANGUAGES\\agree.usa";
  }
  puVar4 = (undefined4 *)bOpenFile(pcVar8,0,1);
  if (puVar4 != (undefined4 *)0x0) {
    iVar6 = puVar4[1];
    if ((int)puVar4[7] < 1) {
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
      iVar7 = DAT_00734484;
      iVar5 = *(int *)(DAT_00734484 + 0x18);
      *puVar4 = *(undefined4 *)(DAT_00734484 + 0x10);
      *(int *)(iVar7 + 0x18) = iVar5 + -1;
      *(undefined4 **)(iVar7 + 0x10) = puVar4;
    }
    else {
      puVar4[5] = 1;
    }
    if (iVar6 != -1) {
      puVar4 = (undefined4 *)bOpenFile(pcVar8,1,1);
      if ((puVar4 == (undefined4 *)0x0) || (iVar6 = puVar4[1], iVar6 < 0)) {
        iVar6 = 0;
      }
      _Memory = _malloc(iVar6 + 1);
      FUN_00594dd0(iVar6);
      if (puVar4 != (undefined4 *)0x0) {
        if ((int)puVar4[7] < 1) {
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
          iVar7 = DAT_00734484;
          iVar5 = *(int *)(DAT_00734484 + 0x18);
          *puVar4 = *(undefined4 *)(DAT_00734484 + 0x10);
          *(int *)(iVar7 + 0x18) = iVar5 + -1;
          *(undefined4 **)(iVar7 + 0x10) = puVar4;
        }
        else {
          puVar4[5] = 1;
        }
      }
      iVar5 = 0;
      iVar7 = 0;
      if (0 < iVar6) {
        do {
          cVar2 = *(char *)(iVar7 + (int)_Memory);
          if (cVar2 == '\n') {
            *(undefined1 *)(*(int *)(unaff_EDI + 0x2ee74) * 0x80 + iVar5 + 0x74 + unaff_EDI) = 0;
            *(int *)(unaff_EDI + 0x2ee74) = *(int *)(unaff_EDI + 0x2ee74) + 1;
            iVar5 = 0;
          }
          else if (cVar2 != '\r') {
            if (cVar2 == '\0') {
              *(undefined1 *)(*(int *)(unaff_EDI + 0x2ee74) * 0x80 + iVar5 + 0x74 + unaff_EDI) = 0;
              *(int *)(unaff_EDI + 0x2ee74) = *(int *)(unaff_EDI + 0x2ee74) + 1;
              iVar5 = 0;
              break;
            }
            if (iVar5 < 0x7f) {
              *(char *)(*(int *)(unaff_EDI + 0x2ee74) * 0x80 + iVar5 + 0x74 + unaff_EDI) = cVar2;
              iVar5 = iVar5 + 1;
            }
            else {
              *(undefined1 *)(*(int *)(unaff_EDI + 0x2ee74) * 0x80 + iVar5 + 0x74 + unaff_EDI) = 0;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      *(undefined1 *)(*(int *)(unaff_EDI + 0x2ee74) * 0x80 + iVar5 + 0x74 + unaff_EDI) = 0;
      *(int *)(unaff_EDI + 0x2ee74) = *(int *)(unaff_EDI + 0x2ee74) + 1;
      _free(_Memory);
    }
  }
  return;
}


// ==== 0x5637a0 FUN_005637a0

void FUN_005637a0(void)

{
  ushort uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  int *piVar6;
  ushort uVar7;
  int unaff_ESI;
  int iVar8;
  int local_104;
  undefined4 local_100;
  
  iVar8 = *(int *)(unaff_ESI + 0x2ee78) + in_EAX;
  iVar2 = *(int *)(unaff_ESI + 0x2ee74) + -9;
  *(int *)(unaff_ESI + 0x2ee78) = iVar8;
  if (iVar2 < iVar8) {
    *(int *)(unaff_ESI + 0x2ee78) = iVar2;
  }
  if (*(int *)(unaff_ESI + 0x2ee78) < 0) {
    *(undefined4 *)(unaff_ESI + 0x2ee78) = 0;
  }
  piVar6 = (int *)(unaff_ESI + 0x50);
  local_104 = 0;
  do {
    if ((DAT_006ee6f0 == 8) || (DAT_006ee6f0 == 7)) {
      FUN_0059fe10(0x100,(*(int *)(unaff_ESI + 0x2ee78) + local_104) * 0x80 + 0x74 + unaff_ESI);
      uVar3 = local_100;
      iVar2 = *piVar6;
      iVar8 = 0;
      uVar7 = (ushort)local_100;
      uVar1 = uVar7;
      while (uVar1 != 0) {
        iVar8 = iVar8 + 1;
        uVar1 = *(ushort *)((int)&local_100 + iVar8 * 2);
      }
      if (*(uint *)(iVar2 + 100) < iVar8 + 1U) {
        WString_Grow();
      }
      puVar4 = *(undefined2 **)(iVar2 + 0x60);
      puVar5 = (ushort *)&local_100;
      if (puVar4 != (undefined2 *)0x0) {
        while (uVar7 != 0) {
          *puVar4 = (short)uVar3;
          puVar5 = puVar5 + 1;
          uVar7 = *puVar5;
          uVar3 = (uint)uVar7;
          puVar4 = puVar4 + 1;
        }
        *puVar4 = 0;
      }
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    }
    else {
      FUN_0041f060(*piVar6,(*(int *)(unaff_ESI + 0x2ee78) + local_104) * 0x80 + 0x74 + unaff_ESI);
    }
    local_104 = local_104 + 1;
    piVar6 = piVar6 + 1;
  } while (local_104 < 9);
  return;
}


// ==== 0x5638d0 FUN_005638d0

void FUN_005638d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int local_8;
  
  piVar4 = (int *)(unaff_EBX + 0x40);
  local_8 = 2;
  do {
    if ((*piVar4 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar1 != '\0') {
        uVar5 = *(undefined4 *)(*piVar4 + 0x10);
        if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_0056395e:
          if (DAT_0073578c != 0) {
            iVar2 = FUN_004ef050(uVar5);
            goto LAB_00563972;
          }
        }
        else {
          iVar2 = FEngFindPackage();
          if (iVar2 == 0) goto LAB_0056395e;
          iVar2 = FUN_004ffb70();
          if (iVar2 == 0) goto LAB_0056395e;
LAB_00563972:
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xc407210,*piVar4,*(undefined4 *)(unaff_EBX + 0x48),iVar2,0);
          }
        }
        if (*(int *)(*piVar4 + 0x10) == -0x5597403a) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar6 = *(int *)(iVar2 + 0x18), iVar6 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar5 = 0x911c0a4b;
LAB_00563a00:
            (**(code **)(*piVar3 + 8))(uVar5,0,0,iVar6);
          }
        }
        else if (*(int *)(*piVar4 + 0x10) == -0x55974029) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar6 = *(int *)(iVar2 + 0x18), iVar6 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar5 = 0x72619778;
            goto LAB_00563a00;
          }
        }
      }
    }
    piVar4 = piVar4 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x563a20 FUN_00563a20

undefined4 FUN_00563a20(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688063;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xe0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00563a80(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x563a80 FUN_00563a80

undefined4 * FUN_00563a80(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = &PTR_FUN_006bc618;
  local_4 = 0;
  param_1[0x13] = DAT_00777cb4;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x17) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0x31) = 0;
  *(undefined1 *)(param_1 + 0x33) = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  FUN_00563f70();
  FUN_00564110();
  FUN_00563e40();
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_1[3] == 0) {
LAB_00563b49:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfd4);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00563b49;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00563b49;
  }
  param_1[0x10] = iVar2;
  if (param_1[3] != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_00563ba5;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(0xaa68bfce);
  }
LAB_00563ba5:
  param_1[0x11] = iVar2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0)) {
    if ((DAT_0073578c == 0) || (iVar1 = *(int *)(DAT_0073578c + 8), iVar1 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004fd1e0(iVar1 + 0xdc);
      if (iVar2 == 0) {
        iVar2 = FUN_004fd1e0(iVar1 + 0xec);
      }
    }
  }
  param_1[0x12] = iVar2;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x563c20 FUN_00563c20

void * __thiscall FUN_00563c20(void *param_1,byte param_2)

{
  FUN_00563c40();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x563c40 FUN_00563c40

void __fastcall FUN_00563c40(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc618;
  FUN_004f7b50();
  return;
}


// ==== 0x563c50 FUN_00563c50

void FUN_00563c50(uint param_1)

{
  if (0xb5971bf1 < param_1) {
    if (param_1 == 0xc98356ba) {
      FUN_00563e40();
      FUN_00563cb0();
    }
    return;
  }
  if (param_1 != 0xb5971bf1) {
    if (param_1 == 0x911ab364) {
      FUN_00563e00();
      return;
    }
    if (param_1 != 0x9120409e) {
      return;
    }
  }
  FUN_00564510();
  return;
}


// ==== 0x563cb0 FUN_00563cb0

void FUN_00563cb0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int local_8;
  
  piVar4 = (int *)(unaff_EBX + 0x40);
  local_8 = 2;
  do {
    if ((*piVar4 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar1 != '\0') {
        uVar5 = *(undefined4 *)(*piVar4 + 0x10);
        if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_00563d3e:
          if (DAT_0073578c != 0) {
            iVar2 = FUN_004ef050(uVar5);
            goto LAB_00563d52;
          }
        }
        else {
          iVar2 = FEngFindPackage();
          if (iVar2 == 0) goto LAB_00563d3e;
          iVar2 = FUN_004ffb70();
          if (iVar2 == 0) goto LAB_00563d3e;
LAB_00563d52:
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xc407210,*piVar4,*(undefined4 *)(unaff_EBX + 0x48),iVar2,0);
          }
        }
        if (*(int *)(*piVar4 + 0x10) == -0x55974032) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar6 = *(int *)(iVar2 + 0x18), iVar6 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar5 = 0x9120409e;
LAB_00563de0:
            (**(code **)(*piVar3 + 8))(uVar5,0,0,iVar6);
          }
        }
        else if (*(int *)(*piVar4 + 0x10) == -0x5597402c) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar6 = *(int *)(iVar2 + 0x18), iVar6 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar5 = 0xb5971bf1;
            goto LAB_00563de0;
          }
        }
      }
    }
    piVar4 = piVar4 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x563e00 FUN_00563e00

undefined4 FUN_00563e00(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
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


// ==== 0x563e40 FUN_00563e40

void FUN_00563e40(void)

{
  int unaff_ESI;
  
  FEngPrintf(&DAT_00777c90);
  FEngPrintf(unaff_ESI + 0x50);
  FEngPrintf(unaff_ESI + 0x5c);
  FEngPrintf(unaff_ESI + 100);
  FEngPrintf(unaff_ESI + 0x70);
  FEngPrintf(unaff_ESI + 0x78);
  FEngPrintf(unaff_ESI + 0x88);
  FEngPrintf(unaff_ESI + 0x90);
  FEngPrintf(unaff_ESI + 0x9c);
  FEngPrintf(unaff_ESI + 0xa4);
  FEngPrintf(unaff_ESI + 0xb0);
  FEngPrintf(unaff_ESI + 0xb8);
  FEngPrintf(unaff_ESI + 0xc4);
  FEngPrintf(unaff_ESI + 0xcc);
  FEngPrintf(unaff_ESI + 0xd8);
  return;
}


// ==== 0x563f70 FUN_00563f70

void FUN_00563f70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  puVar3 = &local_8c;
  FUN_0054b700(&DAT_0073d868,&DAT_00777c90);
  FUN_0054a140(&DAT_0073d868,puVar3);
  if (local_7c == 0) {
    local_7c = 100;
  }
  FUN_00565da0(&PTR_DAT_006bce54,local_7c);
  FUN_00565da0(&PTR_DAT_006bce54,local_8c);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_00565da0(iVar1,local_88,local_84);
  uVar2 = _ftol_nocw();
  FUN_00565da0("%d%%%%",uVar2);
  uVar2 = _ftol_nocw();
  FUN_00565da0("%d%%%%",uVar2);
  FUN_00565da0(&PTR_DAT_006bce54,local_78);
  FUN_00565da0(&PTR_DAT_006bce54,local_74);
  iVar1 = FUN_0054b700(&DAT_0073d868,&DAT_00777c90);
  if ((iVar1 != 0) && (iVar1 = FUN_00549e50(&DAT_0073d868), iVar1 != 0)) {
    GetCarModelNameHash();
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_00565da0(&DAT_006cc568,iVar1);
  return;
}


// ==== 0x564110 FUN_00564110

void FUN_00564110(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 local_8c [28];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar3 = local_8c;
  FUN_0054b700(&DAT_0073d868,&DAT_00777c90);
  FUN_0054a140(&DAT_0073d868,puVar3);
  if (in_EAX == 0) {
    if (local_60 == 0) {
      local_60 = 100;
    }
    FUN_00565da0(&PTR_DAT_006bce54,local_60);
    FUN_00565da0(&PTR_DAT_006bce54,local_70);
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_00565da0(iVar1,local_6c,local_68);
    FUN_00565da0(&PTR_DAT_006bce54,local_5c);
    FUN_00565da0(&PTR_DAT_006bce54,local_58);
    uVar2 = _ftol_nocw();
    FUN_00565da0("%d%%%%",uVar2);
    uVar2 = 0x8717dbd6;
  }
  else if (in_EAX == 2) {
    if (local_c == 0) {
      local_c = 100;
    }
    FUN_00565da0(&PTR_DAT_006bce54,local_c);
    FUN_00565da0(&PTR_DAT_006bce54,local_1c);
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_00565da0(iVar1,local_18,local_14);
    FUN_00565da0(&PTR_DAT_006bce54,local_8);
    FUN_00565da0(&PTR_DAT_006bce54,local_4);
    uVar2 = _ftol_nocw();
    FUN_00565da0("%d%%%%",uVar2);
    uVar2 = 0x76b159dc;
  }
  else if (in_EAX == 1) {
    if (local_44 == 0) {
      local_44 = 100;
    }
    FUN_00565da0(&PTR_DAT_006bce54,local_44);
    FUN_00565da0(&PTR_DAT_006bce54,local_54);
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_00565da0(iVar1,local_50,local_4c);
    FUN_00565da0(&PTR_DAT_006bce54,local_40);
    FUN_00565da0(&PTR_DAT_006bce54,local_3c);
    uVar2 = _ftol_nocw();
    FUN_00565da0("%d%%%%",uVar2);
    uVar2 = 0x6fbac183;
  }
  else {
    if (in_EAX != 3) {
      return;
    }
    if (local_28 == 0) {
      local_28 = 100;
    }
    FUN_00565da0(&PTR_DAT_006bce54,local_28);
    FUN_00565da0(&PTR_DAT_006bce54,local_38);
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_00565da0(iVar1,local_34,local_30);
    FUN_00565da0(&PTR_DAT_006bce54,local_24);
    FUN_00565da0(&PTR_DAT_006bce54,local_20);
    uVar2 = _ftol_nocw();
    FUN_00565da0("%d%%%%",uVar2);
    uVar2 = 0x41a84781;
  }
  FUN_00495f00(uVar2);
  return;
}


// ==== 0x564510 FUN_00564510

void __fastcall FUN_00564510(int param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = *(int *)(in_EAX + 0x4c);
  if (param_1 == -0x6edfbf62) {
    iVar1 = iVar1 + -1;
  }
  else if (param_1 == -0x4a68e40f) {
    iVar1 = iVar1 + 1;
  }
  if (iVar1 < 0) {
    *(undefined4 *)(in_EAX + 0x4c) = 0;
    FUN_00564110();
    return;
  }
  if (2 < iVar1) {
    iVar1 = 3;
  }
  *(int *)(in_EAX + 0x4c) = iVar1;
  FUN_00564110();
  return;
}


// ==== 0x564550 FUN_00564550

void FUN_00564550(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  char local_3f8;
  char local_3f7 [503];
  undefined1 local_200;
  undefined4 local_1ff;
  
  if (DAT_00735da4 != 0) {
    FUN_004ebdf0(DAT_00735da4,0);
  }
  iVar6 = DAT_00734f8c;
  if ((DAT_00734f84 != 0) || (DAT_00734f88 != 0)) {
    local_3f8 = '\0';
    pcVar3 = local_3f7;
    for (iVar4 = 0x7c; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    iVar4 = 0;
    DAT_00734dbc = 1;
    pcVar3[2] = '\0';
    if (DAT_00734f88 == 1) {
      pcVar3 = (char *)LanguageStrings__FindByHash();
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)LanguageStrings__FindByHash();
      }
      local_3f8 = *pcVar3;
      if (*pcVar3 != '\0') {
        pcVar5 = &local_3f8;
        do {
          cVar1 = pcVar5[(int)(pcVar3 + (1 - (int)&local_3f8))];
          pcVar5 = pcVar5 + 1;
          *pcVar5 = cVar1;
        } while (cVar1 != '\0');
      }
    }
    else if (DAT_00734f88 == 2) {
      if ((DAT_00734f8c == 0) || (iVar4 = LanguageStrings__FindByHash(), iVar4 == 0)) {
        iVar6 = 0x451c4ac6;
      }
      pcVar3 = (char *)LanguageStrings__FindByHash();
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)LanguageStrings__FindByHash();
      }
      local_3f8 = *pcVar3;
      iVar4 = iVar6;
      if (*pcVar3 != '\0') {
        pcVar5 = &local_3f8;
        do {
          cVar1 = pcVar5[(int)(pcVar3 + (1 - (int)&local_3f8))];
          pcVar5 = pcVar5 + 1;
          *pcVar5 = cVar1;
        } while (cVar1 != '\0');
      }
    }
    else {
      pcVar3 = (char *)LanguageStrings__FindByHash();
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)LanguageStrings__FindByHash();
      }
      local_3f8 = *pcVar3;
      if (*pcVar3 != '\0') {
        pcVar5 = &local_3f8;
        do {
          cVar1 = pcVar5[(int)(pcVar3 + (1 - (int)&local_3f8))];
          pcVar5 = pcVar5 + 1;
          *pcVar5 = cVar1;
        } while (cVar1 != '\0');
      }
    }
    local_200 = 0;
    puVar7 = &local_1ff;
    for (iVar6 = 0x7c; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = 0;
    *(undefined1 *)((int)puVar7 + 2) = 0;
    if (DAT_00734fc4 < 1) {
      iVar6 = LanguageStrings__FindByHash();
      if (iVar6 == 0) {
        iVar6 = LanguageStrings__FindByHash();
      }
    }
    else {
      iVar6 = LanguageStrings__FindByHash();
      if (iVar6 == 0) {
        iVar6 = LanguageStrings__FindByHash();
      }
    }
    FUN_00565da0("%s %s.",iVar6,&local_3f8);
    if (iVar4 == -0x70ee3d9f) {
      iVar6 = 0;
      do {
        cVar1 = (&DAT_00734bc8)[iVar6];
        cVar2 = "MU_Online_NetworkLogin.fng"[iVar6];
        iVar6 = iVar6 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 == cVar2) {
        FUN_004eb950();
        return;
      }
    }
    FUN_004ee3a0(0,FUN_00557760);
  }
  return;
}


// ==== 0x5647b0 FUN_005647b0

void FUN_005647b0(void)

{
  undefined4 in_EAX;
  
  DAT_007301cc = in_EAX;
  return;
}


// ==== 0x5647c0 FUN_005647c0

void FUN_005647c0(void)

{
  DAT_007301cc = 0;
  return;
}


// ==== 0x5647d0 FUN_005647d0

uint __fastcall FUN_005647d0(uint param_1,byte *param_2)

{
  byte bVar1;
  uint in_EAX;
  uint uVar2;
  
  uVar2 = param_1;
  if (0 < (int)param_1) {
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      in_EAX = in_EAX << 8 ^ *(uint *)(&DAT_006b5e80 + (in_EAX >> 0x18 ^ (uint)bVar1) * 4);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    for (; 0 < (int)param_1; param_1 = (int)param_1 >> 8) {
      in_EAX = in_EAX << 8 ^ *(uint *)(&DAT_006b5e80 + ((in_EAX >> 0x18 ^ param_1) & 0xff) * 4);
    }
  }
  return ~in_EAX;
}


// ==== 0x564830 FUN_00564830

undefined4 FUN_00564830(void)

{
  BOOL BVar1;
  void *unaff_ESI;
  
  BVar1 = IsBadReadPtr(unaff_ESI,1);
  if (BVar1 != 0) {
    BVar1 = IsBadWritePtr(unaff_ESI,1);
    if (BVar1 != 0) {
      return 0;
    }
  }
  return 1;
}


// ==== 0x564860 FUN_00564860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00564860(void)

{
  float fVar1;
  LARGE_INTEGER local_8;
  
  QueryPerformanceFrequency(&local_8);
  DAT_007349c8 = 0;
  _DAT_007301d0 = 1000.0 / (float)(longlong)local_8;
  for (fVar1 = (1000.0 / (float)(longlong)local_8) * 2.1474836e+09; fVar1 < 60000.0;
      fVar1 = fVar1 + fVar1) {
    DAT_007349c8 = DAT_007349c8 + 1;
  }
  return;
}


// ==== 0x5648c0 FUN_005648c0

void FUN_005648c0(void)

{
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  __allshr();
  return;
}


// ==== 0x5648f0 FUN_005648f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_005648f0(int param_1)

{
  int in_EAX;
  undefined4 local_8;
  
  local_8 = in_EAX - param_1;
  if (local_8 < 0) {
    local_8 = 0;
  }
  return (float10)(1 << ((byte)DAT_007349c8 & 0x1f)) * (float10)local_8 * (float10)_DAT_007301d0;
}


// ==== 0x564930 FUN_00564930

bool __fastcall FUN_00564930(int param_1)

{
  return *(int *)(param_1 + 0x18) == 0;
}


// ==== 0x564940 FUN_00564940

void FUN_00564940(undefined4 *param_1,code *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  
  puVar1 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      puVar1 = (undefined4 *)param_1[1];
      *puVar1 = unaff_EDI;
      param_1[1] = unaff_EDI;
      *unaff_EDI = param_1;
      unaff_EDI[1] = puVar1;
      return;
    }
    iVar3 = (*param_2)();
    if (iVar3 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  puVar2 = (undefined4 *)puVar1[1];
  *puVar2 = unaff_EDI;
  puVar1[1] = unaff_EDI;
  *unaff_EDI = puVar1;
  unaff_EDI[1] = puVar2;
  return;
}


// ==== 0x564990 bList::Sort

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void bList__Sort(int *param_1,code *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  do {
    piVar6 = (int *)*param_1;
    iVar3 = 0;
    piVar4 = (int *)*piVar6;
    if (piVar6 == param_1) {
      return;
    }
    do {
      if (piVar4 == param_1) break;
      iVar2 = (*param_2)(piVar6,piVar4);
      if (iVar2 == 0) {
        iVar2 = *piVar4;
        piVar5 = (int *)piVar4[1];
        *piVar5 = iVar2;
        *(int **)(iVar2 + 4) = piVar5;
        puVar1 = (undefined4 *)piVar6[1];
        *puVar1 = piVar4;
        piVar6[1] = (int)piVar4;
        piVar4[1] = (int)puVar1;
        *piVar4 = (int)piVar6;
        piVar5 = (int *)*piVar6;
        iVar3 = iVar3 + 1;
      }
      else {
        piVar5 = (int *)*piVar4;
        piVar6 = piVar4;
      }
      piVar4 = piVar5;
    } while (piVar6 != param_1);
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x5649f0 FUN_005649f0

void FUN_005649f0(void)

{
  undefined4 *puVar1;
  
  if (DAT_007349b4 == (undefined4 *)0x0) {
    DAT_007349b4 = (undefined4 *)FUN_00566dc0(0xc,"bPNode SlotPool",0);
    if (DAT_007349b4 == (undefined4 *)0x0) {
      DAT_007349b8 = DAT_007349b4;
      return;
    }
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = DAT_007349b4;
      puVar1 = DAT_007349b4;
      DAT_007349b4[1] = DAT_0073d81c;
      DAT_0073d81c = puVar1;
      *DAT_007349b4 = &DAT_0073d818;
    }
    DAT_007349b8 = (undefined4 *)0x0;
  }
  return;
}


// ==== 0x564a50 RandomInt

/* [canon] runtime high (hopper+capstone) docs/re/misc.md */

uint RandomInt(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = DAT_006f227c % param_1;
  uVar1 = DAT_006f227c ^ 0x1d872b41;
  uVar2 = uVar1 >> 5 ^ uVar1;
  DAT_006f227c = uVar2 << 0x1b ^ uVar2 ^ uVar1;
  return param_1;
}


// ==== 0x564a80 FUN_00564a80

/* WARNING: Removing unreachable block (ram,0x00564abb) */

float10 FUN_00564a80(float param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_006f227c % 0x7fffffff;
  uVar2 = DAT_006f227c ^ 0x1d872b41;
  uVar1 = uVar2 >> 5 ^ uVar2;
  DAT_006f227c = uVar1 << 0x1b ^ uVar1 ^ uVar2;
  return (float10)uVar3 * (float10)4.656613e-10 * (float10)param_1;
}


// ==== 0x564ad0 FUN_00564ad0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00564ad0(float param_1,float param_2)

{
  float10 fVar1;
  
  param_1 = param_1 / ABS(param_2);
  fVar1 = (float10)FUN_004387e0(param_1);
  if ((float10)param_1 < fVar1) {
    fVar1 = fVar1 - (float10)_K_ONE;
  }
  return ((float10)param_1 - fVar1) * (float10)ABS(param_2);
}


// ==== 0x564b10 FUN_00564b10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00564b10(void)

{
  ushort in_AX;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar1 = (float10)in_AX * (float10)9.58738e-05;
  fVar2 = (float10)_K_ONE;
  if (fVar1 < (float10)4.712389) {
    if ((float10)1.5707964 <= fVar1) {
      fVar1 = fVar1 - (float10)3.1415927;
      fVar2 = (float10)-1.0;
    }
  }
  else {
    fVar1 = fVar1 - (float10)6.2831855;
  }
  fVar3 = fVar1 * fVar1;
  fVar4 = fVar3 * fVar1 * fVar3;
  fVar5 = fVar4 * fVar3;
  return (fVar5 * fVar3 * (float10)2.7557319e-06 +
         ((fVar4 * (float10)0.008333334 + (fVar1 - fVar3 * fVar1 * (float10)0.16666667)) -
         fVar5 * (float10)0.0001984127)) * fVar2;
}


// ==== 0x564bb0 FUN_00564bb0

void FUN_00564bb0(void)

{
  _ftol_nocw();
  FUN_00564b10();
  return;
}


// ==== 0x564bd0 Angle16SinCos

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void __fastcall Angle16SinCos(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  ushort in_AX;
  undefined4 local_10;
  
  local_10 = 1.0;
  fVar1 = (float)in_AX * 9.58738e-05;
  if (fVar1 < 4.712389) {
    if (1.5707964 <= fVar1) {
      fVar1 = fVar1 - 3.1415927;
      local_10 = -1.0;
    }
  }
  else {
    fVar1 = fVar1 - 6.2831855;
  }
  fVar2 = fVar1 * fVar1;
  fVar3 = fVar2 * fVar1 * fVar2;
  fVar5 = fVar2 * fVar2 * fVar2;
  fVar4 = fVar3 * fVar2;
  fVar6 = fVar5 * fVar2;
  *param_1 = (fVar4 * fVar2 * 2.7557319e-06 +
             ((fVar3 * 0.008333334 + (fVar1 - fVar2 * fVar1 * 0.16666667)) - fVar4 * 0.0001984127))
             * local_10;
  *param_2 = ((fVar6 * 2.4801588e-05 +
              ((fVar2 * fVar2 * 0.041666668 + (_K_ONE - _K_HALF * fVar2)) - fVar5 * 0.0013888889)) -
             fVar6 * fVar2 * 2.755732e-07) * local_10;
  return;
}


// ==== 0x564cd0 FUN_00564cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_00564cd0(float param_1)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = param_1 < 0.0;
  if (bVar1) {
    param_1 = -param_1;
  }
  if (_K_ONE <= param_1) {
    return (-(ushort)bVar1 & 0x8000) + 0x4000;
  }
  iVar3 = _ftol_nocw();
  iVar5 = 0x8000;
  iVar6 = 0;
  iVar4 = 0x8000;
  if (0x7fff < iVar3) {
    do {
      if (10 < iVar6) break;
      iVar5 = iVar5 >> 1;
      iVar4 = iVar4 + iVar5;
      iVar6 = iVar6 + 1;
    } while (iVar4 <= iVar3);
  }
  sVar2 = _ftol_nocw();
  if (bVar1) {
    return -(*(short *)(&DAT_006f2280 +
                       (iVar6 * 0x10 + (iVar3 - (iVar4 - iVar5) >> (0xbU - (char)iVar6 & 0x1f))) * 8
                       ) - sVar2);
  }
  return *(short *)(&DAT_006f2280 +
                   (iVar6 * 0x10 + (iVar3 - (iVar4 - iVar5) >> (0xbU - (char)iVar6 & 0x1f))) * 8) -
         sVar2;
}


// ==== 0x564db0 Atan2ToAngle16

/* [canon] track med (hopper+ghidra) docs/re/track.md */

short Atan2ToAngle16(float param_1,float param_2)

{
  float fVar1;
  short sVar2;
  byte bVar3;
  float local_c;
  
  bVar3 = param_1 < 0.0;
  if (param_2 < 0.0) {
    bVar3 = bVar3 ^ 3;
  }
  local_c = 0.0;
  fVar1 = param_2 * param_2 + param_1 * param_1;
  if (ABS(param_1) <= ABS(param_2)) {
    if (0.0001 < fVar1) {
      if (param_1 == 0.0) {
        local_c = 0.0;
      }
      else {
        local_c = ABS(param_1) / SQRT(fVar1);
      }
    }
    sVar2 = FUN_00564cd0(local_c);
    sVar2 = 0x4000 - sVar2;
  }
  else {
    if (0.0001 < fVar1) {
      if (param_2 == 0.0) {
        local_c = 0.0;
      }
      else {
        local_c = ABS(param_2) / SQRT(fVar1);
      }
    }
    sVar2 = FUN_00564cd0(local_c);
  }
  if (bVar3 == 0) {
    return sVar2;
  }
  if (bVar3 == 3) {
    return -sVar2;
  }
  if (bVar3 == 1) {
    return -0x8000 - sVar2;
  }
  return sVar2 + -0x8000;
}


// ==== 0x564f00 FUN_00564f00

int FUN_00564f00(void)

{
  uint in_EAX;
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  
  bVar4 = (int)in_EAX < 0;
  if (bVar4) {
    in_EAX = -in_EAX;
  }
  if ((int)in_EAX < 0x200000) {
    if ((int)in_EAX < 0x40000) {
      iVar1 = ((int)in_EAX >> 0xb) * 2;
      uVar2 = *(ushort *)(&DAT_006f2d10 + iVar1);
      uVar3 = *(ushort *)(&DAT_006f2d12 + iVar1);
      iVar1 = (in_EAX & 0x7ff) << 5;
    }
    else {
      uVar2 = *(ushort *)(&DAT_006f2e18 + ((int)in_EAX >> 0xe) * 2);
      uVar3 = *(ushort *)(&DAT_006f2e1a + ((int)in_EAX >> 0xe) * 2);
      iVar1 = (in_EAX & 0x3fff) << 2;
    }
  }
  else if ((int)in_EAX < 0x1000000) {
    iVar1 = (int)in_EAX >> 8;
    uVar2 = 0x3eba;
    uVar3 = 0x3fd7;
  }
  else {
    uVar2 = 0x3fff;
    uVar3 = 0x3fff;
    iVar1 = 0;
  }
  iVar1 = ((int)(((uint)uVar3 - (uint)uVar2) * iVar1) >> 0x10) + (uint)uVar2;
  if (bVar4) {
    iVar1 = -iVar1;
  }
  return iVar1;
}


// ==== 0x564fa0 FUN_00564fa0

uint __fastcall FUN_00564fa0(int param_1)

{
  int in_EAX;
  uint uVar1;
  byte bVar2;
  
  bVar2 = in_EAX < 0;
  if ((bool)bVar2) {
    in_EAX = -in_EAX;
  }
  if (param_1 < 0) {
    bVar2 = bVar2 ^ 3;
    param_1 = -param_1;
  }
  if (param_1 >> 0xe < in_EAX) {
    if (in_EAX != 0) {
      __allshr();
    }
    uVar1 = FUN_00564f00();
    uVar1 = uVar1 & 0xffff;
  }
  else {
    uVar1 = 0x4000;
  }
  if (bVar2 == 0) {
    return uVar1;
  }
  if (bVar2 == 1) {
    return 0x8000 - uVar1;
  }
  if (bVar2 != 2) {
    return -uVar1;
  }
  return uVar1 - 0x8000;
}


// ==== 0x565020 eIdentity

/* [canon] render high (ghidra-canon+nfsug) docs/re/canon.md */

void eIdentity(void)

{
  undefined4 *in_EAX;
  
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
  return;
}


// ==== 0x565060 FUN_00565060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00565060(float *param_1)

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
  float *in_EAX;
  
  fVar6 = param_1[4];
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar7 = param_1[5];
  fVar3 = param_1[2];
  fVar4 = param_1[6];
  fVar8 = param_1[8];
  fVar5 = param_1[10];
  fVar9 = param_1[9];
  fVar10 = param_1[0xc];
  fVar11 = param_1[0xd];
  fVar12 = param_1[0xe];
  fVar17 = fVar7 * fVar5 - fVar9 * fVar4;
  in_EAX[3] = 0.0;
  fVar14 = fVar5 * fVar6 - fVar8 * fVar4;
  fVar13 = fVar9 * fVar6 - fVar8 * fVar7;
  fVar18 = _K_ONE / (fVar13 * fVar3 + (fVar17 * fVar1 - fVar14 * fVar2));
  fVar17 = fVar17 * fVar18;
  *in_EAX = fVar17;
  fVar16 = -((fVar5 * fVar2 - fVar9 * fVar3) * fVar18);
  in_EAX[1] = fVar16;
  fVar15 = (fVar4 * fVar2 - fVar7 * fVar3) * fVar18;
  in_EAX[2] = fVar15;
  fVar14 = -(fVar14 * fVar18);
  in_EAX[4] = fVar14;
  fVar5 = (fVar5 * fVar1 - fVar8 * fVar3) * fVar18;
  in_EAX[7] = 0.0;
  in_EAX[0xb] = 0.0;
  in_EAX[0xf] = 1.0;
  in_EAX[5] = fVar5;
  fVar3 = -((fVar4 * fVar1 - fVar6 * fVar3) * fVar18);
  in_EAX[6] = fVar3;
  fVar13 = fVar13 * fVar18;
  in_EAX[8] = fVar13;
  fVar4 = -((fVar9 * fVar1 - fVar8 * fVar2) * fVar18);
  in_EAX[9] = fVar4;
  fVar18 = (fVar7 * fVar1 - fVar6 * fVar2) * fVar18;
  in_EAX[10] = fVar18;
  in_EAX[0xc] = -(fVar17 * fVar10 + fVar14 * fVar11 + fVar13 * fVar12);
  in_EAX[0xd] = -(fVar16 * fVar10 + fVar5 * fVar11 + fVar4 * fVar12);
  in_EAX[0xe] = -(fVar15 * fVar10 + fVar3 * fVar11 + fVar18 * fVar12);
  return;
}


// ==== 0x565230 bMatrixCopy

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __fastcall bMatrixCopy(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *in_EAX;
  
  uVar2 = param_1[3];
  uVar1 = param_1[2];
  uVar3 = param_1[4];
  uVar4 = param_1[5];
  uVar5 = param_1[6];
  uVar6 = param_1[7];
  uVar7 = param_1[8];
  uVar8 = param_1[9];
  uVar9 = param_1[10];
  uVar10 = param_1[0xb];
  uVar11 = param_1[0xc];
  uVar12 = param_1[0xd];
  uVar13 = param_1[0xe];
  uVar14 = param_1[0xf];
  uVar15 = *param_1;
  in_EAX[4] = param_1[1];
  in_EAX[8] = uVar1;
  *in_EAX = uVar15;
  in_EAX[0xc] = uVar2;
  in_EAX[1] = uVar3;
  in_EAX[5] = uVar4;
  in_EAX[9] = uVar5;
  in_EAX[0xd] = uVar6;
  in_EAX[2] = uVar7;
  in_EAX[6] = uVar8;
  in_EAX[10] = uVar9;
  in_EAX[0xe] = uVar10;
  in_EAX[3] = uVar11;
  in_EAX[7] = uVar12;
  in_EAX[0xb] = uVar13;
  in_EAX[0xf] = uVar14;
  return;
}


// ==== 0x565300 FUN_00565300

void FUN_00565300(void)

{
  int in_EAX;
  
  _free(*(void **)(in_EAX + 8));
  return;
}


// ==== 0x565310 bInitMemoryPool

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void bInitMemoryPool(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  puVar1 = unaff_ESI + 1;
  *puVar1 = puVar1;
  unaff_ESI[2] = puVar1;
  puVar1 = unaff_ESI + 3;
  *puVar1 = puVar1;
  unaff_ESI[4] = puVar1;
  puVar1 = unaff_ESI + 5;
  *puVar1 = puVar1;
  unaff_ESI[6] = puVar1;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  CriticalSection__Init(unaff_ESI + 0xf);
  *(undefined1 *)(unaff_ESI + 0xe) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x39) = 1;
  *unaff_ESI = param_2;
  unaff_ESI[9] = unaff_ESI[9] + unaff_EDI;
  FUN_00565410(unaff_ESI,unaff_EDI);
  return;
}


// ==== 0x565370 FUN_00565370

void FUN_00565370(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)(param_1 + 0x14);
  piVar2 = *(int **)(param_1 + 0x14);
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    FUN_00565300();
    _free(piVar2);
    piVar2 = (int *)*piVar1;
  }
  FUN_0063f170(param_1 + 0x3c);
  return;
}


// ==== 0x5653c0 FUN_005653c0

void FUN_005653c0(undefined4 param_1,int param_2)

{
  int unaff_ESI;
  
  CriticalSection__Enter(unaff_ESI + 0x3c);
  FUN_00565410(unaff_ESI,param_2);
  param_2 = *(int *)(unaff_ESI + 0x28) - param_2;
  *(int *)(unaff_ESI + 0x28) = param_2;
  *(int *)(unaff_ESI + 0x30) = *(int *)(unaff_ESI + 0x24) - param_2;
  *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
  CriticalSection__Leave(unaff_ESI + 0x3c);
  return;
}


// ==== 0x565410 FUN_00565410

void FUN_00565410(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_EAX;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (param_2 != 0) {
    iVar1 = param_1 + 0x3c;
    CriticalSection__Enter(iVar1);
    in_EAX[2] = param_2;
    in_EAX[3] = 0x44443333;
    for (piVar7 = *(int **)(param_1 + 4); (piVar7 != (int *)(param_1 + 4) && (piVar7 <= in_EAX));
        piVar7 = (int *)*piVar7) {
    }
    puVar2 = (undefined4 *)piVar7[1];
    *puVar2 = in_EAX;
    piVar7[1] = (int)in_EAX;
    in_EAX[1] = (int)puVar2;
    piVar4 = (int *)(in_EAX[2] + (int)in_EAX);
    *in_EAX = (int)piVar7;
    if (piVar4 == piVar7) {
      in_EAX[2] = piVar7[2] + in_EAX[2];
      iVar3 = *piVar7;
      piVar4 = piVar7 + 4;
      piVar7 = (int *)piVar7[1];
      *piVar7 = iVar3;
      *(int **)(iVar3 + 4) = piVar7;
    }
    piVar7 = (int *)in_EAX[1];
    piVar6 = in_EAX;
    piVar8 = in_EAX + 4;
    if ((int *)(piVar7[2] + (int)piVar7) == in_EAX) {
      piVar7[2] = in_EAX[2] + piVar7[2];
      iVar3 = *in_EAX;
      piVar6 = (int *)in_EAX[1];
      *piVar6 = iVar3;
      *(int **)(iVar3 + 4) = piVar6;
      piVar6 = piVar7;
      piVar8 = in_EAX;
    }
    if (*(char *)(param_1 + 0x38) != '\0') {
      piVar7 = piVar8;
      for (uVar5 = (uint)((int)piVar4 - (int)piVar8) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar7 = -0x11111112;
        piVar7 = piVar7 + 1;
      }
      for (uVar5 = (int)piVar4 - (int)piVar8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)piVar7 = 0xee;
        piVar7 = (int *)((int)piVar7 + 1);
      }
    }
    if (DAT_006f2270 != 0) {
      piVar7 = *(int **)(param_1 + 0x14);
      if (piVar7 != (int *)(param_1 + 0x14)) {
        while (((int *)piVar7[2] != piVar6 || (piVar7[3] != piVar6[2]))) {
          piVar7 = (int *)*piVar7;
          if (piVar7 == (int *)(param_1 + 0x14)) {
            CriticalSection__Leave(iVar1);
            return;
          }
        }
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - piVar7[3];
        iVar3 = *piVar6;
        piVar4 = (int *)piVar6[1];
        *piVar4 = iVar3;
        *(int **)(iVar3 + 4) = piVar4;
        iVar3 = *piVar7;
        piVar4 = (int *)piVar7[1];
        *piVar4 = iVar3;
        *(int **)(iVar3 + 4) = piVar4;
        FUN_00565300();
        _free(piVar7);
      }
    }
    CriticalSection__Leave(iVar1);
  }
  return;
}


// ==== 0x565550 FUN_00565550

int * FUN_00565550(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                  uint *param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  size_t _Size;
  
  iVar1 = param_1 + 0x3c;
  uVar9 = param_2;
  do {
    CriticalSection__Enter(iVar1);
    uVar9 = uVar9 + 3 & 0xfffffffc;
    if ((int)uVar9 < 0x10) {
      uVar9 = 0x10;
    }
    piVar11 = (int *)0x0;
    param_2 = 0;
    iVar10 = 0x7fffffff;
    if (param_5 == 0) {
      piVar6 = *(int **)(param_1 + 8);
      if (piVar6 != (int *)(param_1 + 4)) {
        piVar11 = (int *)0x0;
        do {
          iVar8 = (int)((int)piVar6 + param_4 + (piVar6[2] - uVar9) & param_3 - 1U) % param_3;
          iVar4 = (piVar6[2] - iVar8) - uVar9;
          if ((((iVar4 == 0) || (0xf < iVar4)) && (iVar4 < iVar10)) &&
             (iVar10 = iVar4, piVar11 = piVar6, param_2 = iVar8, param_6 == 0)) break;
          piVar6 = (int *)piVar6[1];
        } while (piVar6 != (int *)(param_1 + 4));
        goto LAB_00565659;
      }
    }
    else {
      piVar6 = *(int **)(param_1 + 4);
      if (piVar6 != (int *)(param_1 + 4)) {
        do {
          iVar8 = (int)(param_3 - (param_4 + (int)piVar6 & param_3 - 1U)) % param_3;
          iVar4 = (piVar6[2] - iVar8) - uVar9;
          if (((iVar4 == 0) || (0xf < iVar4)) &&
             ((iVar4 < iVar10 && (iVar10 = iVar4, piVar11 = piVar6, param_2 = iVar8, param_6 == 0)))
             ) break;
          piVar6 = (int *)*piVar6;
        } while (piVar6 != (int *)(param_1 + 4));
LAB_00565659:
        if (piVar11 != (int *)0x0) {
          uVar9 = uVar9 + param_2;
          if (param_5 == 0) {
            iVar10 = piVar11[2] - uVar9;
            piVar11[2] = iVar10;
            piVar6 = (int *)(iVar10 + (int)piVar11);
            if (iVar10 == 0) {
              iVar10 = *piVar11;
              piVar2 = (int *)piVar11[1];
              *piVar2 = iVar10;
              *(int **)(iVar10 + 4) = piVar2;
            }
          }
          else {
            if (piVar11[2] - uVar9 != 0) {
              piVar6 = (int *)((int)piVar11 + uVar9);
              piVar6[2] = piVar11[2] - uVar9;
              piVar6[3] = 0x44443333;
              iVar10 = *piVar11;
              *piVar11 = (int)piVar6;
              *(int **)(iVar10 + 4) = piVar6;
              piVar6[1] = (int)piVar11;
              *piVar6 = iVar10;
            }
            iVar10 = *piVar11;
            piVar6 = (int *)piVar11[1];
            *piVar6 = iVar10;
            *(int **)(iVar10 + 4) = piVar6;
            piVar6 = piVar11;
          }
          if (*(char *)(param_1 + 0x38) != '\0') {
            piVar11 = piVar6;
            for (uVar7 = uVar9 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *piVar11 = -0x55555556;
              piVar11 = piVar11 + 1;
            }
            for (uVar7 = uVar9 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined1 *)piVar11 = 0xaa;
              piVar11 = (int *)((int)piVar11 + 1);
            }
          }
          iVar10 = *(int *)(param_1 + 0x28) + uVar9;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
          *(int *)(param_1 + 0x28) = iVar10;
          if (*(int *)(param_1 + 0x2c) < iVar10) {
            *(int *)(param_1 + 0x2c) = iVar10;
          }
          *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x24) - iVar10;
          *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x2c);
          CriticalSection__Leave(iVar1);
          *param_7 = uVar9;
          return piVar6;
        }
      }
    }
    CriticalSection__Leave(iVar1);
    _Size = uVar9 + 0x10 + param_3;
    if ((int)_Size < (int)DAT_006f2274) {
      _Size = DAT_006f2274;
    }
    piVar11 = _malloc(0x10);
    if (piVar11 == (int *)0x0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11[3] = _Size;
      pvVar5 = _malloc(_Size);
      piVar11[2] = (int)pvVar5;
    }
    if (piVar11[2] == 0) {
      _free((void *)piVar11[2]);
      _free(piVar11);
      return (int *)0x0;
    }
    iVar10 = piVar11[3];
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + iVar10;
    FUN_00565410(param_1,iVar10);
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    *puVar3 = piVar11;
    *(int **)(param_1 + 0x18) = piVar11;
    piVar11[1] = (int)puVar3;
    *piVar11 = param_1 + 0x14;
  } while( true );
}


// ==== 0x5657d0 bMemoryPool_TotalAllocated

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int bMemoryPool_TotalAllocated(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  
  CriticalSection__Enter(in_EAX + 0x3c);
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(in_EAX + 4); puVar1 != (undefined4 *)(in_EAX + 4);
      puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + puVar1[2];
  }
  CriticalSection__Leave(in_EAX + 0x3c);
  return iVar2;
}


// ==== 0x565810 FUN_00565810

int FUN_00565810(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  
  CriticalSection__Enter(unaff_EDI + 0x3c);
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(unaff_EDI + 4); puVar1 != (undefined4 *)(unaff_EDI + 4);
      puVar1 = (undefined4 *)*puVar1) {
    if (iVar2 < (int)puVar1[2]) {
      iVar2 = puVar1[2];
    }
  }
  CriticalSection__Leave(unaff_EDI + 0x3c);
  return iVar2;
}


// ==== 0x565850 bMemoryPool_Validate

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void bMemoryPool_Validate(int param_1,char param_2)

{
  void *pvVar1;
  code *pcVar2;
  BOOL BVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_4;
  
  CriticalSection__Enter(param_1 + 0x3c);
  puVar7 = *(undefined4 **)(param_1 + 4);
  local_4 = 0;
  if (puVar7 != (undefined4 *)(param_1 + 4)) {
    do {
      BVar3 = IsBadReadPtr(puVar7,1);
      if ((BVar3 != 0) && (BVar3 = IsBadWritePtr(puVar7,1), BVar3 != 0)) {
LAB_005659e4:
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      pvVar1 = (void *)*puVar7;
      BVar3 = IsBadReadPtr(pvVar1,1);
      if ((BVar3 != 0) && (BVar3 = IsBadWritePtr(pvVar1,1), BVar3 != 0)) goto LAB_005659e4;
      pvVar1 = (void *)puVar7[1];
      BVar3 = IsBadReadPtr(pvVar1,1);
      if (((BVar3 != 0) && (BVar3 = IsBadWritePtr(pvVar1,1), BVar3 != 0)) ||
         (puVar7[3] != 0x44443333)) goto LAB_005659e4;
      if (DAT_0078ea8c != '\0') break;
      if ((param_2 != '\0') && (*(char *)(param_1 + 0x38) != '\0')) {
        for (pcVar4 = (char *)(puVar7 + 4); pcVar4 != (char *)(puVar7[2] + (int)puVar7);
            pcVar4 = pcVar4 + 1) {
          if (*pcVar4 != -0x12) {
            DAT_0078ea8c = '\x01';
            goto LAB_005659e4;
          }
        }
      }
      puVar7 = (undefined4 *)*puVar7;
    } while (puVar7 != (undefined4 *)(param_1 + 4));
  }
  puVar7 = *(undefined4 **)(param_1 + 0xc);
  if (puVar7 == (undefined4 *)(param_1 + 0xc)) {
    CriticalSection__Leave(param_1 + 0x3c);
    return;
  }
  while ((BVar3 = IsBadReadPtr(puVar7,1), BVar3 == 0 ||
         (BVar3 = IsBadWritePtr(puVar7,1), BVar3 == 0))) {
    pvVar1 = (void *)*puVar7;
    BVar3 = IsBadReadPtr(pvVar1,1);
    if ((BVar3 != 0) && (BVar3 = IsBadWritePtr(pvVar1,1), BVar3 != 0)) break;
    pvVar1 = (void *)puVar7[1];
    BVar3 = IsBadReadPtr(pvVar1,1);
    if (((BVar3 != 0) && (BVar3 = IsBadWritePtr(pvVar1,1), BVar3 != 0)) ||
       (*(short *)((int)puVar7 + 10) != 0x2222)) break;
    uVar6 = (uint)*(byte *)((int)puVar7 + 9);
    iVar5 = 0;
    if (uVar6 != 0) {
      do {
        if (*(char *)((int)puVar7 + (iVar5 - uVar6)) != -0x23) {
          local_4 = local_4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar6);
      if (local_4 != 0) break;
    }
    puVar7 = (undefined4 *)*puVar7;
    if (puVar7 == (undefined4 *)(param_1 + 0xc)) {
      CriticalSection__Leave(param_1 + 0x3c);
      return;
    }
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


// ==== 0x565a40 FUN_00565a40

int FUN_00565a40(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *unaff_EDI;
  
  CriticalSection__Enter(param_1 + 0x3c);
  iVar3 = 0;
  if (unaff_EDI != (char *)0x0) {
    cVar1 = *unaff_EDI;
    while (cVar1 != '\0') {
      iVar4 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar1 = unaff_EDI[iVar4];
    }
  }
  iVar3 = 0;
  for (puVar2 = *(undefined4 **)(param_1 + 0xc); puVar2 != (undefined4 *)(param_1 + 0xc);
      puVar2 = (undefined4 *)*puVar2) {
    iVar4 = FUN_00567d50();
    if (iVar4 == 0) {
      iVar3 = iVar3 + puVar2[3];
    }
  }
  CriticalSection__Leave(param_1 + 0x3c);
  return iVar3;
}


// ==== 0x565af0 FUN_00565af0

void __fastcall FUN_00565af0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  
  (&DAT_007301d4)[in_EAX] = &DAT_007301f8 + in_EAX * 0x58;
  bInitMemoryPool(param_3,param_2);
  return;
}


// ==== 0x565b10 FUN_00565b10

void FUN_00565b10(void)

{
  int unaff_ESI;
  
  FUN_00565370((&DAT_007301d4)[unaff_ESI]);
  (&DAT_007301d4)[unaff_ESI] = 0;
  return;
}


// ==== 0x565b30 FUN_00565b30

void FUN_00565b30(void)

{
  if (DAT_007349b0 != 0) {
    FUN_00565370(DAT_007301d4);
    DAT_007301d4 = 0;
    DAT_007349b0 = 0;
  }
  return;
}


// ==== 0x565b60 FUN_00565b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00565b60(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  uVar6 = param_4;
  _DAT_007349a8 = param_2;
  _DAT_007349ac = param_3;
  if (DAT_007349b0 == 0) {
    DAT_007301d4 = &DAT_007301f8;
    bInitMemoryPool(0,"Main Pool");
    DAT_007349b0 = 1;
  }
  if (((DAT_007349a0 != 0) && (DAT_007349a4 % DAT_007349a0 == 0)) &&
     ((&DAT_007301d4)[uVar6 & 7] != (undefined *)0x0)) {
    bMemoryPool_Validate((&DAT_007301d4)[uVar6 & 7],1);
  }
  uVar9 = (int)uVar6 >> 6 & 0x3fc;
  if (uVar9 == 0) {
    uVar9 = 0x40;
  }
  iVar8 = (int)(&DAT_007301d4)[uVar6 & 7];
  iVar4 = FUN_00565550(iVar8,param_1 + 0x18,uVar9,0x18,uVar6 & 8,uVar6 & 0x10,&param_4);
  if (iVar4 == 0) {
    pcVar3 = (code *)swi(3);
    piVar10 = (int *)(*pcVar3)();
    return piVar10;
  }
  iVar7 = 0;
  if ((uVar6 & 8) != 0) {
    iVar7 = (int)(uVar9 - (uVar9 - 1 & iVar4 + 0x18U)) % (int)uVar9;
  }
  puVar11 = *(undefined4 **)(iVar8 + 0x10);
  piVar10 = (int *)(iVar4 + iVar7);
  *puVar11 = piVar10;
  *(int **)(iVar8 + 0x10) = piVar10;
  *(char *)((int)piVar10 + 9) = (char)iVar7;
  piVar10[1] = (int)puVar11;
  *piVar10 = iVar8 + 0xc;
  *(byte *)(piVar10 + 2) = (byte)uVar6 & 7;
  *(undefined2 *)((int)piVar10 + 10) = 0x2222;
  piVar10[3] = param_4;
  *(undefined1 *)(piVar10 + 5) = (undefined1)param_3;
  pcVar5 = (char *)((int)piVar10 + 0x15);
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  *(undefined1 *)((int)piVar10 + 0x17) = 0;
  if (param_2 != 0) {
    iVar8 = 2;
    param_2 = param_2 - (int)pcVar5;
    do {
      cVar1 = pcVar5[param_2];
      iVar8 = iVar8 + -1;
      *pcVar5 = cVar1;
      if (cVar1 == '\0') break;
      pcVar5 = pcVar5 + 1;
    } while (iVar8 != 0);
  }
  bVar2 = *(byte *)((int)piVar10 + 9);
  puVar11 = (undefined4 *)((int)piVar10 - (uint)bVar2);
  for (uVar6 = (uint)(bVar2 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar11 = 0xdddddddd;
    puVar11 = puVar11 + 1;
  }
  for (uVar6 = bVar2 & 3; iVar8 = DAT_007349a4, uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar11 = 0xdd;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
  }
  bVar12 = DAT_007349a4 == DAT_006f2278;
  piVar10[4] = DAT_007349a4;
  if (bVar12) {
    pcVar3 = (code *)swi(3);
    piVar10 = (int *)(*pcVar3)();
    return piVar10;
  }
  DAT_007349a4 = iVar8 + 1;
  return piVar10 + 6;
}


// ==== 0x565ce0 FUN_00565ce0

void FUN_00565ce0(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int in_EAX;
  
  if (in_EAX != 0) {
    if (((DAT_007349a0 != 0) && (DAT_007349a4 % DAT_007349a0 == 0)) &&
       ((&DAT_007301d4)[*(byte *)(in_EAX + -0x10)] != 0)) {
      bMemoryPool_Validate((&DAT_007301d4)[*(byte *)(in_EAX + -0x10)],1);
    }
    if (*(short *)(in_EAX + -0xe) != 0x2222) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    bVar1 = *(byte *)(in_EAX + -0xf);
    piVar2 = *(int **)(in_EAX + -0x14);
    *(undefined2 *)(in_EAX + -0xe) = 0;
    iVar3 = *(int *)(in_EAX + -0x18);
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    FUN_005653c0((in_EAX + -0x18) - (uint)bVar1,*(undefined4 *)(in_EAX + -0xc));
    if ((DAT_007349b0 == 0) || (*(int *)(DAT_007301d4 + 0x1c) == 0)) {
      FUN_00565b30();
      return;
    }
  }
  return;
}


// ==== 0x565d70 bLargestFreeBlock

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int bLargestFreeBlock(void)

{
  int in_EAX;
  int iVar1;
  
  if ((&DAT_007301d4)[in_EAX] != 0) {
    if (in_EAX == 0) {
      return 0x6300000;
    }
    iVar1 = FUN_00565810();
    if (-1 < iVar1 + -0x58) {
      return iVar1 + -0x58;
    }
  }
  return 0;
}


// ==== 0x565da0 FUN_00565da0

void FUN_00565da0(undefined4 param_1)

{
  int iVar1;
  undefined1 *unaff_ESI;
  
  DAT_007304b8 = FUN_005669d0;
  DAT_007304bc = FUN_005669f0;
  DAT_00730508 = unaff_ESI;
  iVar1 = bVPrintf(0,param_1,&stack0x00000008);
  if ((unaff_ESI != (undefined1 *)0x0) && (iVar1 != -1)) {
    *DAT_00730508 = 0;
  }
  return;
}


// ==== 0x565df0 bVPrintf

/* WARNING: Removing unreachable block (ram,0x00566061) */
/* WARNING: Removing unreachable block (ram,0x0056602b) */
/* WARNING: Removing unreachable block (ram,0x0056612b) */
/* WARNING: Removing unreachable block (ram,0x0056612f) */
/* WARNING: Removing unreachable block (ram,0x00566135) */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 bVPrintf(char param_1,char *param_2,double *param_3)

{
  float *pfVar1;
  ulonglong uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  code *pcVar10;
  code *pcVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  byte bVar18;
  char cVar19;
  int iVar20;
  byte *pbVar21;
  uint uVar22;
  int iVar23;
  char *pcVar24;
  int iVar25;
  uint uVar26;
  double *pdVar27;
  bool bVar28;
  float10 fVar29;
  float10 fVar30;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  uint local_6c;
  uint local_68;
  byte *local_64;
  byte *local_60;
  int local_5c;
  int local_58;
  uint uStack_44;
  undefined1 local_40 [64];
  
  iVar20 = 0;
  DAT_00730507 = 0;
  cVar12 = *param_2;
  iVar23 = 0;
  local_6c = 0;
  bVar9 = false;
  bVar8 = false;
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  local_5c = 0;
  local_68 = 0;
  local_64 = (byte *)0x0;
  local_58 = 0;
  DAT_007304c0 = param_1;
  pdVar27 = param_3;
  iVar25 = DAT_00730508;
  pcVar10 = DAT_007304bc;
  pcVar11 = DAT_007304b8;
  pbVar21 = PTR_DAT_006f2268;
  do {
    PTR_DAT_006f2268 = pbVar21;
    DAT_007304b8 = pcVar11;
    DAT_007304bc = pcVar10;
    DAT_00730508 = iVar25;
    if (cVar12 == '\0') {
      if (DAT_0073499c == 0) {
        return 0;
      }
      (&DAT_00730510)[DAT_0073499c] = 0;
      _printf_67147f("%s",&DAT_00730510);
      OutputDebugStringA(&DAT_00730510);
      DAT_0073499c = 0;
      return 0;
    }
    param_2 = param_2 + 1;
    if ((cVar12 < ' ') || ('z' < cVar12)) {
      uVar16 = 0;
    }
    else {
      uVar16 = (byte)(&DAT_006b5e00)[cVar12] & 0xf;
    }
    iVar23 = (int)(char)(&DAT_006b5e20)[uVar16 * 8 + iVar23] >> 4;
    switch(iVar23) {
    case 0:
      (*pcVar11)(cVar12);
      break;
    case 1:
      local_6c = 0;
      bVar9 = false;
      bVar8 = false;
      bVar7 = false;
      bVar6 = false;
      bVar5 = false;
      bVar4 = false;
      bVar3 = false;
      local_5c = 0;
      local_58 = 0;
      local_64 = &DAT_007304c8;
      local_68 = 0xffffffff;
      iVar20 = 0;
      break;
    case 2:
      switch(cVar12) {
      case ' ':
        bVar8 = true;
        break;
      case '#':
        break;
      case '+':
        bVar7 = true;
        break;
      case '-':
        local_6c = local_6c | 4;
        break;
      case '0':
        local_6c = local_6c | 8;
      }
      break;
    case 3:
      if (cVar12 == '*') {
        local_5c = *(int *)pdVar27;
        param_3 = (double *)((int)pdVar27 + 4);
        iVar20 = local_5c;
        pdVar27 = param_3;
        if (local_5c < 0) {
          local_6c = local_6c | 4;
          local_5c = -local_5c;
          iVar20 = local_5c;
        }
      }
      else {
        local_5c = cVar12 + -0x30 + iVar20 * 10;
        iVar20 = local_5c;
      }
      break;
    case 4:
      local_68 = 0;
      break;
    case 5:
      if (cVar12 == '*') {
        local_68 = *(uint *)pdVar27;
        param_3 = (double *)((int)pdVar27 + 4);
        pdVar27 = param_3;
        if ((int)local_68 < 0) {
          local_68 = 0xffffffff;
        }
      }
      else {
        local_68 = cVar12 + -0x30 + local_68 * 10;
      }
      break;
    case 6:
      if (cVar12 == 'h') {
        bVar9 = true;
      }
      break;
    case 7:
      cVar19 = '\0';
      switch(cVar12) {
      case 'E':
      case 'G':
        param_1 = 'E';
        goto LAB_0056615b;
      case 'X':
        goto switchD_00565fe9_caseD_58;
      case 'b':
        uVar16 = 2;
        goto LAB_00566085;
      case 'c':
        DAT_007304c8 = *(undefined1 *)pdVar27;
        param_3 = (double *)((int)pdVar27 + 4);
        local_60 = (byte *)0x1;
        break;
      case 'd':
      case 'i':
        uVar16 = 10;
        bVar4 = true;
        goto LAB_00566085;
      case 'e':
      case 'g':
        param_1 = 'e';
LAB_0056615b:
        bVar3 = true;
switchD_00565fe9_caseD_66:
        fVar29 = (float10)*pdVar27;
        param_3 = pdVar27 + 1;
        uStack_44 = (uint)((ulonglong)*pdVar27 >> 0x20);
        bVar4 = true;
        if ((uStack_44 & 0x7ff00000) == 0x7ff00000) {
          local_64 = PTR_s__1__INF_006f2258;
          if ((uStack_44 != 0xfff00000) &&
             (local_64 = PTR_s_1__INF_006f225c, uStack_44 != 0x7ff00000)) {
            local_64 = PTR_s_1__QNAN_006f2260;
          }
          local_60 = (byte *)0x7;
          if (local_64 != (byte *)0x0) break;
        }
        pcVar24 = &DAT_007304c9;
        DAT_007304c8 = 0x30;
        local_64 = &DAT_007304c9;
        if (fVar29 < (float10)0.0) {
          bVar6 = true;
          fVar29 = -fVar29;
        }
        bVar4 = true;
        if (local_68 == 0xffffffff) {
          local_68 = 3;
        }
        uVar16 = local_68;
        iVar20 = 0;
        if ((bVar3) && (fVar29 != (float10)0.0)) {
          if ((float10)1.0 <= fVar29) {
            do {
              iVar20 = iVar20 + 1;
              fVar29 = fVar29 * (float10)0.1;
            } while ((float10)1.0 <= fVar29);
          }
          do {
            iVar20 = iVar20 + -1;
            fVar29 = fVar29 * (float10)10.0;
          } while (fVar29 < (float10)1.0);
LAB_005662c0:
          do {
            cVar12 = _ftol_nocw();
            *pcVar24 = cVar12 + '0';
            pcVar24 = pcVar24 + 1;
            fVar29 = extraout_ST1 - (float10)(int)cVar12 * extraout_ST0;
          } while ((float10)1.0 <= extraout_ST0 * (float10)0.1);
          if (pcVar24 == &DAT_007304c9) goto LAB_005662fe;
        }
        else {
          for (fVar30 = (float10)1.0; fVar30 < fVar29; fVar30 = fVar30 * (float10)10.0) {
          }
          if (fVar29 < fVar30) {
            fVar30 = fVar30 * (float10)0.1;
          }
          if ((float10)1.0 <= fVar30) goto LAB_005662c0;
LAB_005662fe:
          DAT_007304c9 = 0x30;
          pcVar24 = &DAT_007304ca;
        }
        if (local_68 != 0) {
          *pcVar24 = '.';
          pcVar24 = pcVar24 + 1;
          if (local_68 != 0) {
            local_68 = 0;
            do {
              cVar12 = _ftol_nocw();
              *pcVar24 = cVar12 + '0';
              pcVar24 = pcVar24 + 1;
              uVar16 = uVar16 - 1;
              fVar29 = extraout_ST0_00 - (float10)(int)cVar12;
            } while (uVar16 != 0);
          }
        }
        local_68 = local_68 - 1;
        if ((float10)5.0 <= (float10)10.0 * fVar29) {
          pcVar15 = pcVar24 + -1;
          while( true ) {
            for (; *pcVar15 == '9'; pcVar15 = pcVar15 + -1) {
              *pcVar15 = '0';
            }
            if (*pcVar15 != '.') break;
            pcVar15 = pcVar15 + -1;
          }
          *pcVar15 = *pcVar15 + '\x01';
          if (pcVar15 < &DAT_007304c9) {
            local_64 = &DAT_007304c8;
          }
        }
        if (bVar3) {
          *pcVar24 = param_1;
          if (iVar20 < 0) {
            iVar20 = -iVar20;
            pcVar24[1] = '-';
          }
          else {
            pcVar24[1] = '+';
          }
          cVar12 = ((char)(iVar20 / 100) + (char)(iVar20 >> 0x1f)) -
                   (char)((longlong)iVar20 * 0x51eb851f >> 0x3f);
          pcVar24[2] = cVar12 + '0';
          iVar20 = iVar20 + cVar12 * -100;
          cVar12 = ((char)(iVar20 / 10) + (char)(iVar20 >> 0x1f)) -
                   (char)((longlong)iVar20 * 0x66666667 >> 0x3f);
          pcVar24[3] = cVar12 + '0';
          local_58 = 0;
          pcVar24[4] = (char)((iVar20 + cVar12 * -10) % 10) + '0';
          pcVar24 = pcVar24 + 5;
        }
        local_60 = (byte *)(pcVar24 + -(int)local_64);
        break;
      case 'f':
        goto switchD_00565fe9_caseD_66;
      case 'n':
        param_3 = (double *)((int)pdVar27 + 4);
        **(undefined4 **)pdVar27 = 0;
        bVar5 = true;
        break;
      case 'o':
        uVar16 = 8;
        goto LAB_00566085;
      case 'p':
        local_68 = 8;
        goto switchD_00565fe9_caseD_58;
      case 's':
        local_64 = *(byte **)pdVar27;
        param_3 = (double *)((int)pdVar27 + 4);
        if ((local_64 == (byte *)0x0) ||
           (iVar20 = FUN_00564830(), pbVar21 = PTR_s__badptr__006f226c, iVar20 == 0)) {
          local_64 = pbVar21;
        }
        pbVar21 = local_64;
        uVar16 = local_68;
        if ((int)local_68 < 0) {
          uVar16 = 0x7fffffff;
        }
        do {
          bVar18 = *pbVar21;
          pbVar21 = pbVar21 + 1;
          if (bVar18 == 0) break;
          bVar28 = uVar16 != 0;
          uVar16 = uVar16 - 1;
        } while (bVar28);
        if (pbVar21 != local_64) {
          local_60 = pbVar21 + (-1 - (int)local_64);
        }
        break;
      case 'u':
        uVar16 = 10;
LAB_00566085:
        param_3 = (double *)((int)pdVar27 + 4);
        pbVar21 = (byte *)&DAT_00730506;
        if (bVar9) {
          if (bVar4) {
            uVar22 = (uint)*(short *)pdVar27;
          }
          else {
            uVar22 = (uint)*(ushort *)pdVar27;
          }
        }
        else {
          uVar22 = *(uint *)pdVar27;
        }
        if ((bVar4) && ((int)uVar22 < 0)) {
          uVar22 = -uVar22;
          bVar6 = true;
        }
        if ((int)local_68 < 0) {
          local_68 = 1;
        }
        else {
          local_6c = local_6c & 0xfffffff7;
        }
        uVar13 = local_68;
        if (uVar22 == 0) {
          local_58 = 0;
        }
        while ((local_68 = uVar13 - 1, 0 < (int)uVar13 || (uVar22 != 0))) {
          bVar18 = (char)(uVar22 % uVar16) + 0x30;
          if (0x39 < bVar18) {
            bVar18 = bVar18 + cVar19;
          }
          *pbVar21 = bVar18;
          pbVar21 = pbVar21 + -1;
          uVar22 = uVar22 / uVar16;
          uVar13 = local_68;
        }
        local_60 = (byte *)(&DAT_00730506 + -(int)pbVar21);
        local_64 = pbVar21 + 1;
        break;
      case 'v':
        iVar20 = 0;
        if (*param_2 == '2') {
          param_3 = (double *)((int)param_3 + 4);
          iVar20 = FUN_00564830();
          if (iVar20 != 0) {
            iVar20 = FUN_00565da0();
            goto LAB_0056662b;
          }
          local_64 = (byte *)0x6bc594;
          pcVar24 = "bPrintf:invalid pointer";
        }
        else {
          if (*param_2 == '3') {
            pfVar1 = *(float **)param_3;
            param_3 = (double *)((int)param_3 + 4);
            iVar14 = FUN_00564830();
            if (iVar14 != 0) {
              iVar20 = FUN_00565da0("[%*.*f,%*.*f,%*.*f]",local_5c,local_68,(double)*pfVar1,local_5c
                                    ,local_68,(double)pfVar1[1],local_5c,local_68,(double)pfVar1[2])
              ;
            }
LAB_0056662b:
            local_60 = (byte *)0x0;
            DAT_007304b8 = pcVar11;
            DAT_007304bc = pcVar10;
            DAT_00730508 = iVar25;
            (*pcVar10)(local_40,iVar20 + 1);
            if (0 < DAT_0073499c) {
              DAT_0073499c = DAT_0073499c + -1;
            }
            bVar5 = true;
            param_2 = param_2 + 1;
            DAT_00730508 = DAT_00730508 + -1;
            break;
          }
          pcVar24 = "bPrintf:invalid bVector";
          local_64 = (byte *)0x6bc568;
        }
        pcVar15 = pcVar24;
        uVar16 = local_68;
        if ((int)local_68 < 0) {
          uVar16 = 0x7fffffff;
        }
        do {
          cVar12 = *pcVar15;
          pcVar15 = pcVar15 + 1;
          if (cVar12 == '\0') break;
          bVar28 = uVar16 != 0;
          uVar16 = uVar16 - 1;
        } while (bVar28);
        if (pcVar15 != pcVar24) {
          local_60 = (byte *)(pcVar15 + (-1 - (int)local_64));
        }
        break;
      case 'x':
        cVar19 = '\'';
        goto LAB_00566023;
      case 'z':
        param_3 = (double *)((int)pdVar27 + 4);
        uVar16 = *(uint *)pdVar27;
        local_64 = (byte *)&DAT_00730506;
        if (0x7ffffffe < uVar16) {
          uVar16 = ~uVar16 + 1;
          bVar6 = true;
        }
        bVar4 = true;
        uVar22 = uVar16 >> 0x10;
        uVar16 = uVar16 & 0xffff;
        if ((int)local_68 < 0) {
          local_68 = 2;
        }
        uVar13 = local_68;
        if ((uVar16 != 0) || (local_68 != 0)) {
          pcVar24 = &DAT_00730507 + -local_68;
          if (0 < (int)local_68) {
            local_68 = 0;
            uVar26 = uVar13;
            do {
              if (uVar16 < 0x10000) {
                uVar16 = uVar16 * 10;
              }
              uVar17 = 0;
              iVar20 = 0;
              do {
                iVar25 = iVar20;
                uVar17 = uVar17 + 0x10000;
                iVar20 = iVar25 + 1;
              } while (uVar17 <= uVar16);
              *pcVar24 = (char)iVar25 + '0';
              pcVar24 = pcVar24 + 1;
              uVar16 = uVar16 + iVar25 * -0x10000;
              uVar26 = uVar26 - 1;
            } while (uVar26 != 0);
          }
          if ((uVar16 == 0) && (0 < (int)local_68)) {
            uVar26 = local_68 >> 2;
            pcVar15 = pcVar24;
            while (uVar26 != 0) {
              uVar26 = uVar26 - 1;
              builtin_strncpy(pcVar15,"0000",4);
              pcVar15 = pcVar15 + 4;
            }
            for (uVar26 = local_68 & 3; uVar26 != 0; uVar26 = uVar26 - 1) {
              *pcVar15 = '0';
              pcVar15 = pcVar15 + 1;
            }
            pcVar24 = pcVar24 + local_68;
            local_68 = 0;
          }
          *pcVar24 = '\0';
          pcVar24[-1 - uVar13] = '.';
          local_64 = (byte *)(pcVar24 + (-1 - uVar13) + -1);
          if (uVar16 != 0) {
            if (uVar16 < 0x10000) {
              uVar16 = uVar16 * 10;
            }
            uVar13 = 0;
            iVar20 = 0;
            do {
              iVar25 = iVar20;
              uVar13 = uVar13 + 0x10000;
              iVar20 = iVar25 + 1;
            } while (uVar13 <= uVar16);
            if (4 < iVar25) {
              pcVar24 = &DAT_00730506;
              cVar12 = DAT_00730506;
              while (cVar12 == '9') {
                *pcVar24 = '0';
                if (pcVar24[-1] == '.') {
                  uVar22 = uVar22 + 1;
                  goto LAB_00566554;
                }
                pcVar15 = pcVar24 + -1;
                pcVar24 = pcVar24 + -1;
                cVar12 = *pcVar15;
              }
              *pcVar24 = *pcVar24 + '\x01';
            }
          }
        }
LAB_00566554:
        if (uVar22 == 0) {
          *local_64 = '0';
          local_64 = local_64 + -1;
        }
        else {
          do {
            uVar2 = (ulonglong)uVar22;
            uVar22 = uVar22 / 10;
            *local_64 = (char)(uVar2 % 10) + '0';
            local_64 = local_64 + -1;
          } while (uVar22 != 0);
        }
        local_60 = (byte *)(&DAT_00730506 + -(int)local_64);
        local_64 = local_64 + 1;
      }
      iVar20 = local_5c;
      pdVar27 = param_3;
      if (!bVar5) {
        if (bVar4) {
          if (bVar6) {
            param_1 = '-';
          }
          else if (bVar7) {
            param_1 = '+';
          }
          else {
            if (!bVar8) goto LAB_005667dd;
            param_1 = ' ';
          }
          local_58 = 1;
        }
LAB_005667dd:
        iVar25 = (local_5c - (int)local_60) - local_58;
        if (iVar25 < 0) {
          iVar25 = 0;
        }
        else if ((iVar25 != 0) && (local_6c == 0)) {
          do {
            (*DAT_007304b8)(0x20);
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
          iVar25 = -1;
        }
        if (local_58 != 0) {
          (*DAT_007304bc)(&param_1,local_58);
        }
        if ((0 < iVar25) && ((local_6c & 4) == 0)) {
          do {
            (*DAT_007304b8)(0x30);
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
          iVar25 = -1;
        }
        (*DAT_007304bc)(local_64,local_60);
        pdVar27 = param_3;
        if (0 < iVar25) {
          do {
            (*DAT_007304b8)(0x20);
            iVar25 = iVar25 + -1;
            pdVar27 = param_3;
          } while (iVar25 != 0);
        }
      }
    }
    cVar12 = *param_2;
    iVar25 = DAT_00730508;
    pcVar10 = DAT_007304bc;
    pcVar11 = DAT_007304b8;
    pbVar21 = PTR_DAT_006f2268;
  } while( true );
switchD_00565fe9_caseD_58:
  cVar19 = '\a';
LAB_00566023:
  uVar16 = 0x10;
  goto LAB_00566085;
}


// ==== 0x5669d0 FUN_005669d0

void FUN_005669d0(undefined1 param_1,int *param_2)

{
  if (DAT_00730508 != (undefined1 *)0x0) {
    *DAT_00730508 = param_1;
    DAT_00730508 = DAT_00730508 + 1;
  }
  *param_2 = *param_2 + 1;
  return;
}


// ==== 0x5669f0 FUN_005669f0

void FUN_005669f0(undefined1 *param_1,int param_2,int *param_3)

{
  *param_3 = *param_3 + param_2;
  if (DAT_00730508 != (undefined1 *)0x0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *DAT_00730508 = *param_1;
      DAT_00730508 = DAT_00730508 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== 0x566a20 FUN_00566a20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00566a20(float *param_1)

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
  float *in_EAX;
  
  fVar8 = *param_1 + *param_1;
  fVar10 = param_1[1] + param_1[1];
  fVar11 = param_1[2] + param_1[2];
  fVar9 = fVar8 * *param_1;
  fVar1 = *param_1;
  fVar2 = *param_1;
  fVar3 = param_1[1];
  fVar4 = param_1[1];
  fVar5 = param_1[2];
  fVar8 = fVar8 * param_1[3];
  fVar6 = param_1[3];
  fVar7 = param_1[3];
  in_EAX[3] = 0.0;
  in_EAX[7] = 0.0;
  in_EAX[0xb] = 0.0;
  in_EAX[0xc] = 0.0;
  fVar12 = _K_ONE - (fVar11 * fVar5 + fVar10 * fVar3);
  in_EAX[0xd] = 0.0;
  in_EAX[0xe] = 0.0;
  *in_EAX = fVar12;
  in_EAX[0xf] = 1.0;
  in_EAX[1] = fVar10 * fVar1 - fVar11 * fVar7;
  in_EAX[2] = fVar10 * fVar6 + fVar11 * fVar2;
  in_EAX[4] = fVar11 * fVar7 + fVar10 * fVar1;
  in_EAX[5] = _K_ONE - (fVar11 * fVar5 + fVar9);
  in_EAX[6] = fVar11 * fVar4 - fVar8;
  in_EAX[8] = fVar11 * fVar2 - fVar10 * fVar6;
  in_EAX[9] = fVar8 + fVar11 * fVar4;
  in_EAX[10] = _K_ONE - (fVar10 * fVar3 + fVar9);
  return;
}


// ==== 0x566b10 FUN_00566b10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00566b10(float *param_1)

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
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  fVar4 = param_1[3];
  in_EAX[3] = 0.0;
  in_EAX[7] = 0.0;
  fVar7 = fVar2 * fVar2 + fVar2 * fVar2;
  in_EAX[0xb] = 0.0;
  in_EAX[0xc] = 0.0;
  in_EAX[0xd] = 0.0;
  in_EAX[0xe] = 0.0;
  in_EAX[0xf] = 1.0;
  fVar10 = fVar3 * fVar3 + fVar3 * fVar3;
  *in_EAX = (_K_ONE - fVar7) - fVar10;
  fVar9 = fVar2 * fVar1 + fVar2 * fVar1;
  fVar8 = fVar4 * fVar3 + fVar4 * fVar3;
  in_EAX[1] = fVar9 - fVar8;
  fVar6 = fVar4 * fVar2 + fVar4 * fVar2;
  fVar5 = fVar3 * fVar1 + fVar3 * fVar1;
  in_EAX[2] = fVar5 + fVar6;
  in_EAX[4] = fVar8 + fVar9;
  fVar8 = _K_ONE - (fVar1 * fVar1 + fVar1 * fVar1);
  in_EAX[5] = fVar8 - fVar10;
  fVar2 = fVar3 * fVar2 + fVar3 * fVar2;
  fVar1 = fVar4 * fVar1 + fVar4 * fVar1;
  in_EAX[6] = fVar2 - fVar1;
  in_EAX[8] = fVar5 - fVar6;
  in_EAX[9] = fVar1 + fVar2;
  in_EAX[10] = fVar8 - fVar7;
  return;
}


// ==== 0x566bf0 FUN_00566bf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00566bf0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  uint uVar4;
  float *unaff_EDI;
  float local_50 [4];
  float local_40 [11];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_40[0] = *in_EAX;
  local_40[1] = in_EAX[1];
  local_40[2] = in_EAX[2];
  local_40[4] = in_EAX[4];
  local_40[6] = in_EAX[6];
  local_40[8] = in_EAX[8];
  local_40[3] = in_EAX[3];
  local_40[5] = in_EAX[5];
  local_40[10] = in_EAX[10];
  local_40[7] = in_EAX[7];
  local_40[9] = in_EAX[9];
  fVar1 = local_40[10] + local_40[5] + local_40[0];
  local_14 = in_EAX[0xb];
  local_10 = in_EAX[0xc];
  local_c = in_EAX[0xd];
  local_8 = in_EAX[0xe];
  local_4 = in_EAX[0xf];
  local_50[0] = 1.4013e-45;
  local_50[1] = 2.8026e-45;
  local_50[2] = 0.0;
  if (0.0 < fVar1) {
    fVar1 = SQRT(fVar1 + _K_ONE);
    unaff_EDI[3] = _K_HALF * fVar1;
    fVar1 = _K_HALF / fVar1;
    *unaff_EDI = (local_40[6] - local_40[9]) * fVar1;
    unaff_EDI[1] = (local_40[8] - local_40[2]) * fVar1;
    unaff_EDI[2] = (local_40[1] - local_40[4]) * fVar1;
    return;
  }
  uVar4 = (uint)(local_40[0] < local_40[5]);
  if (local_40[uVar4 * 5] < local_40[10]) {
    uVar4 = 2;
  }
  fVar1 = local_50[uVar4];
  fVar2 = local_50[(int)fVar1];
  fVar3 = SQRT((local_40[uVar4 * 5] - (local_40[(int)fVar2 * 5] + local_40[(int)fVar1 * 5])) +
               _K_ONE);
  local_50[uVar4] = _K_HALF * fVar3;
  if (fVar3 != 0.0) {
    fVar3 = _K_HALF / fVar3;
  }
  local_50[3] = (local_40[(int)fVar2 + (int)fVar1 * 4] - local_40[(int)fVar1 + (int)fVar2 * 4]) *
                fVar3;
  local_50[(int)fVar1] =
       (local_40[uVar4 + (int)fVar1 * 4] + local_40[(int)fVar1 + uVar4 * 4]) * fVar3;
  local_50[(int)fVar2] =
       (local_40[uVar4 + (int)fVar2 * 4] + local_40[(int)fVar2 + uVar4 * 4]) * fVar3;
  *unaff_EDI = local_50[0];
  unaff_EDI[1] = local_50[1];
  unaff_EDI[2] = local_50[2];
  unaff_EDI[3] = local_50[3];
  return;
}


// ==== 0x566db0 FUN_00566db0

void FUN_00566db0(void)

{
  SlotPool__Destroy();
  return;
}


// ==== 0x566dc0 FUN_00566dc0

int FUN_00566dc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = FUN_00565b60(param_1 * unaff_EDI + 0x30,0,0,param_3);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x24) = unaff_EDI;
    *(int *)(iVar1 + 0x28) = param_1;
    *(undefined4 *)(iVar1 + 0x14) = 0xb;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0x20) = param_3;
    *(undefined4 *)(iVar1 + 0xc) = param_2;
    *(int *)(iVar1 + 0x2c) = unaff_EDI;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    SlotPool__BuildFreeList();
  }
  return iVar1;
}


// ==== 0x566e20 SlotPool::BuildFreeList

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __fastcall SlotPool__BuildFreeList(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  for (; param_2 != 0; param_2 = *(int *)(param_2 + 8)) {
    iVar1 = *(int *)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x10) = 0;
    if (*(int *)(param_2 + 0x24) != 0) {
      iVar4 = *(int *)(param_2 + 0x24) + -1;
      puVar3 = (undefined4 *)(param_2 + 0x30);
      *(undefined4 **)(param_2 + 0x10) = puVar3;
      puVar2 = puVar3;
      if (0 < iVar4) {
        do {
          iVar4 = iVar4 + -1;
          puVar3 = (undefined4 *)((int)puVar2 + iVar1);
          *puVar2 = puVar3;
          puVar2 = puVar3;
        } while (iVar4 != 0);
      }
      *puVar3 = 0;
    }
  }
  return;
}


// ==== 0x566e60 FUN_00566e60

void FUN_00566e60(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar2 = FUN_00566dc0(*(undefined4 *)(unaff_ESI + 0x28),*(undefined4 *)(unaff_ESI + 0xc),
                       *(undefined4 *)(unaff_ESI + 0x20));
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_ESI + 0x14);
  iVar3 = *(int *)(unaff_ESI + 8);
  iVar1 = unaff_ESI;
  while (iVar3 != 0) {
    iVar1 = *(int *)(iVar1 + 8);
    iVar3 = *(int *)(iVar1 + 8);
  }
  *(int *)(iVar1 + 8) = iVar2;
  iVar3 = (in_EAX + -1) * *(int *)(unaff_ESI + 0x28);
  *(undefined4 *)(iVar2 + 0x30 + ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2) * 4) =
       *(undefined4 *)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(int *)(unaff_ESI + 0x2c) = *(int *)(unaff_ESI + 0x2c) + in_EAX;
  return;
}


// ==== 0x566ed0 SlotPool::IndexOfSlot

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int __thiscall SlotPool__IndexOfSlot(int param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    puVar1 = (uint *)(param_1 + 0x28);
    do {
      uVar3 = ((param_2 - param_1) - 0x30U) / *puVar1;
      if ((-1 < (int)uVar3) && ((int)uVar3 < *(int *)(param_1 + 0x24))) {
        return uVar3 + iVar4;
      }
      piVar2 = (int *)(param_1 + 0x24);
      param_1 = *(int *)(param_1 + 8);
      iVar4 = iVar4 + *piVar2;
    } while (param_1 != 0);
  }
  return -1;
}


// ==== 0x566f20 FUN_00566f20

int FUN_00566f20(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  puVar3 = (undefined4 *)FUN_00565b60(*(undefined4 *)(param_1 + 0x2c),0,0,0);
  uVar7 = *(uint *)(param_1 + 0x2c);
  puVar8 = puVar3;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar8 = 0x1010101;
    puVar8 = puVar8 + 1;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined1 *)puVar8 = 1;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  for (puVar8 = *(undefined4 **)(param_1 + 0x10); puVar8 != (undefined4 *)0x0;
      puVar8 = (undefined4 *)*puVar8) {
    iVar4 = SlotPool__IndexOfSlot(puVar8);
    *(undefined1 *)(iVar4 + (int)puVar3) = 0;
  }
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar4 = 0;
    do {
      if (*(char *)(iVar4 + (int)puVar3) != '\0') {
        iVar5 = param_1;
        if (param_2 == 0) goto LAB_00566fb0;
        param_2 = param_2 + -1;
      }
      iVar4 = iVar4 + 1;
      if (*(int *)(param_1 + 0x2c) <= iVar4) {
        FUN_00565ce0();
        return 0;
      }
    } while( true );
  }
LAB_00566fc7:
  FUN_00565ce0();
  return 0;
LAB_00566fb0:
  do {
    if ((-1 < iVar4) && (iVar4 < *(int *)(iVar5 + 0x24))) {
      iVar2 = *(int *)(param_1 + 0x28);
      FUN_00565ce0();
      return iVar2 * iVar4 + 0x30 + iVar5;
    }
    piVar1 = (int *)(iVar5 + 8);
    iVar4 = iVar4 - *(int *)(iVar5 + 0x24);
    iVar5 = *piVar1;
  } while (*piVar1 != 0);
  goto LAB_00566fc7;
}


// ==== 0x567000 FUN_00567000

void FUN_00567000(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar5 = *(int *)(param_1 + 8);
  if (iVar5 != 0) {
    do {
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x24);
      iVar5 = *(int *)(iVar5 + 8);
    } while (iVar5 != 0);
    for (puVar2 = *(undefined4 **)(param_1 + 0x10); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      for (iVar5 = *(int *)(param_1 + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
        iVar9 = 0;
        if (iVar5 != 0) {
          iVar7 = iVar5;
          do {
            uVar6 = (uint)((int)puVar2 + (-0x30 - iVar7)) / *(uint *)(iVar5 + 0x28);
            if ((-1 < (int)uVar6) && ((int)uVar6 < *(int *)(iVar7 + 0x24))) {
              if ((-1 < (int)(uVar6 + iVar9)) && ((int)(uVar6 + iVar9) < *(int *)(iVar5 + 0x24))) {
                *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + -1;
                goto LAB_0056707b;
              }
              break;
            }
            piVar1 = (int *)(iVar7 + 0x24);
            iVar7 = *(int *)(iVar7 + 8);
            iVar9 = iVar9 + *piVar1;
          } while (iVar7 != 0);
        }
      }
LAB_0056707b:
    }
    iVar5 = *(int *)(param_1 + 8);
    iVar9 = param_1;
    while (iVar7 = iVar9, iVar9 = iVar5, iVar9 != 0) {
      iVar5 = *(int *)(iVar9 + 8);
      if (*(int *)(iVar9 + 0x18) == 0) {
        puVar2 = *(undefined4 **)(param_1 + 0x10);
        puVar4 = (undefined4 *)(param_1 + 0x10);
joined_r0x005670be:
        puVar3 = puVar4;
        puVar4 = puVar2;
        if (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          iVar10 = 0;
          iVar8 = iVar9;
          do {
            uVar6 = (uint)((int)puVar4 + (-0x30 - iVar8)) / *(uint *)(iVar9 + 0x28);
            if ((-1 < (int)uVar6) && ((int)uVar6 < *(int *)(iVar8 + 0x24))) {
              if ((-1 < (int)(uVar6 + iVar10)) && ((int)(uVar6 + iVar10) < *(int *)(iVar9 + 0x24)))
              {
                *puVar3 = puVar2;
                puVar4 = puVar3;
              }
              break;
            }
            piVar1 = (int *)(iVar8 + 0x24);
            iVar8 = *(int *)(iVar8 + 8);
            iVar10 = iVar10 + *piVar1;
          } while (iVar8 != 0);
          goto joined_r0x005670be;
        }
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(iVar9 + 0x24);
        *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar9 + 8);
        FUN_00565ce0();
        iVar9 = iVar7;
      }
    }
  }
  return;
}


// ==== 0x567160 FUN_00567160

undefined4 * FUN_00567160(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  
  if ((*(int *)(in_EAX + 0x10) == 0) && ((*(byte *)(in_EAX + 0x14) & 1) != 0)) {
    FUN_00566e60();
  }
  puVar1 = *(undefined4 **)(in_EAX + 0x10);
  iVar3 = *(int *)(in_EAX + 0x18) + 1;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *puVar1;
    if (*(int *)(in_EAX + 0x1c) < iVar3) {
      *(int *)(in_EAX + 0x1c) = iVar3;
    }
    *(int *)(in_EAX + 0x18) = iVar3;
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
    if (((*(byte *)(in_EAX + 0x14) & 2) != 0) &&
       (iVar3 = *(int *)(in_EAX + 0x28) >> 2, puVar4 = puVar1, 0 < iVar3)) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return puVar1;
}


// ==== 0x5671c0 FUN_005671c0

void __fastcall FUN_005671c0(undefined4 *param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x18);
  *param_1 = *(undefined4 *)(in_EAX + 0x10);
  *(int *)(in_EAX + 0x18) = iVar1 + -1;
  *(undefined4 **)(in_EAX + 0x10) = param_1;
  return;
}


// ==== 0x5671e0 FUN_005671e0

void FUN_005671e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 1;
  *puVar1 = puVar1;
  in_EAX[2] = puVar1;
  *in_EAX = 1;
  return;
}


// ==== 0x567220 SlotPool::Destroy

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __fastcall SlotPool__Destroy(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  if (param_1 != (int *)0x0) {
    if (*in_EAX != 0) {
      iVar1 = *param_1;
      piVar2 = (int *)param_1[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    if (((*(byte *)(param_1 + 5) & 8) != 0) && (0 < param_1[6])) {
      FUN_00566f20(param_1,0);
    }
    do {
      param_1 = (int *)param_1[2];
      FUN_00565ce0();
    } while (param_1 != (int *)0x0);
  }
  return;
}


// ==== 0x567270 bList::AddTail

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __fastcall bList__AddTail(int param_1)

{
  int *piVar1;
  int *in_EAX;
  
  piVar1 = *(int **)(param_1 + 4);
  *piVar1 = (int)in_EAX;
  *(int **)(param_1 + 4) = in_EAX;
  in_EAX[1] = (int)piVar1;
  *in_EAX = param_1;
  return;
}


// ==== 0x567280 bDistance3

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

float10 __fastcall bDistance3(float *param_1)

{
  float *in_EAX;
  
  return SQRT(((float10)*param_1 - (float10)*in_EAX) * ((float10)*param_1 - (float10)*in_EAX) +
              ((float10)param_1[1] - (float10)in_EAX[1]) *
              ((float10)param_1[1] - (float10)in_EAX[1]) +
              ((float10)param_1[2] - (float10)in_EAX[2]) *
              ((float10)param_1[2] - (float10)in_EAX[2]));
}


// ==== 0x5672b0 bNormalize2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

float * __fastcall bNormalize2(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar2 = SQRT(*param_2 * *param_2 + param_2[1] * param_2[1]);
  if (fVar2 != 0.0) {
    fVar1 = param_2[1];
    fVar2 = _K_ONE / fVar2;
    *param_1 = fVar2 * *param_2;
    param_1[1] = fVar2 * fVar1;
    return param_1;
  }
  *param_1 = 1.0;
  param_1[1] = 0.0;
  return param_1;
}


// ==== 0x567310 bScaleToLength2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

float * __fastcall bScaleToLength2(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  
  param_3 = SQRT(*param_2 * *param_2 + param_2[1] * param_2[1]) / param_3;
  if (param_3 != 0.0) {
    fVar1 = param_2[1];
    param_3 = _K_ONE / param_3;
    *param_1 = param_3 * *param_2;
    param_1[1] = param_3 * fVar1;
    return param_1;
  }
  *param_1 = 1.0;
  param_1[1] = 0.0;
  return param_1;
}


// ==== 0x567370 bNormalize3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

float * __fastcall bNormalize3(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  if (fVar3 != 0.0) {
    fVar3 = _K_ONE / fVar3;
    fVar2 = param_2[2];
    fVar1 = param_2[1];
    *param_1 = fVar3 * *param_2;
    param_1[1] = fVar1 * fVar3;
    param_1[2] = fVar2 * fVar3;
    return param_1;
  }
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  *param_1 = 1.0;
  return param_1;
}


// ==== 0x5673e0 FUN_005673e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __fastcall FUN_005673e0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2) / param_3;
  if (fVar3 != 0.0) {
    fVar3 = _K_ONE / fVar3;
    fVar2 = param_2[2];
    fVar1 = param_2[1];
    *param_1 = fVar3 * *param_2;
    param_1[1] = fVar1 * fVar3;
    param_1[2] = fVar2 * fVar3;
    return param_1;
  }
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  *param_1 = param_3;
  return param_1;
}


// ==== 0x567450 Vec3Normalize

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render I (C) docs/re/blur.md */

float * __fastcall Vec3Normalize(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1 + param_1[3]
               + param_1[3]);
  if (fVar3 != 0.0) {
    fVar3 = _K_ONE / fVar3;
    fVar2 = param_1[2];
    fVar1 = param_1[1];
    *param_2 = fVar3 * *param_1;
    param_2[1] = fVar1 * fVar3;
    param_2[2] = fVar2 * fVar3;
    return param_2;
  }
  param_2[1] = 0.0;
  param_2[2] = 0.0;
  *param_2 = 1.0;
  return param_2;
}


// ==== 0x5674d0 FUN_005674d0

void __fastcall FUN_005674d0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  fVar1 = param_1[1];
  fVar2 = param_2[1];
  fVar3 = param_1[2];
  fVar4 = param_2[2];
  *in_EAX = param_3 * *param_1 + *param_2;
  in_EAX[1] = param_3 * fVar1 + fVar2;
  in_EAX[2] = param_3 * fVar3 + fVar4;
  return;
}


// ==== 0x567500 FUN_00567500

void __fastcall FUN_00567500(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar1 = param_1[1];
  fVar2 = param_2[1];
  fVar3 = param_1[2];
  fVar4 = param_2[2];
  fVar5 = *param_1;
  fVar6 = *param_2;
  in_EAX[3] = param_3 * param_1[3] + param_2[3];
  *in_EAX = param_3 * fVar5 + fVar6;
  in_EAX[1] = param_3 * fVar1 + fVar2;
  in_EAX[2] = param_3 * fVar3 + fVar4;
  return;
}


// ==== 0x567540 FUN_00567540

void __fastcall FUN_00567540(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *in_EAX;
  
  fVar1 = *param_1;
  fVar2 = param_2[2];
  fVar3 = param_1[2];
  fVar4 = *param_2;
  fVar5 = param_1[1];
  fVar6 = *param_2;
  fVar7 = param_2[1];
  fVar8 = *param_1;
  *in_EAX = param_1[2] * param_2[1] - param_1[1] * param_2[2];
  in_EAX[1] = fVar1 * fVar2 - fVar3 * fVar4;
  in_EAX[2] = fVar5 * fVar6 - fVar7 * fVar8;
  return;
}


// ==== 0x567580 FUN_00567580

void __fastcall FUN_00567580(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *unaff_ESI;
  
  fVar1 = *param_1;
  if (*unaff_ESI < *param_1) {
    fVar1 = *unaff_ESI;
  }
  fVar2 = param_1[1];
  if (unaff_ESI[1] < param_1[1]) {
    fVar2 = unaff_ESI[1];
  }
  fVar3 = *param_1;
  if (*param_1 < *param_2) {
    fVar3 = *param_2;
  }
  fVar4 = param_1[1];
  if (param_1[1] < param_2[1]) {
    fVar4 = param_2[1];
  }
  *unaff_ESI = fVar1;
  unaff_ESI[1] = fVar2;
  *param_2 = fVar3;
  param_2[1] = fVar4;
  return;
}


// ==== 0x567600 Aabb2D::GrowByCircle

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall Aabb2D__GrowByCircle(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *unaff_ESI;
  
  fVar1 = *param_1 - param_3;
  if (*unaff_ESI < *param_1 - param_3) {
    fVar1 = *unaff_ESI;
  }
  fVar2 = param_1[1] - param_3;
  if (unaff_ESI[1] < param_1[1] - param_3) {
    fVar2 = unaff_ESI[1];
  }
  fVar3 = param_3 + *param_1;
  if (param_3 + *param_1 < *param_2) {
    fVar3 = *param_2;
  }
  fVar4 = param_3 + param_1[1];
  if (param_3 + param_1[1] < param_2[1]) {
    fVar4 = param_2[1];
  }
  *unaff_ESI = fVar1;
  unaff_ESI[1] = fVar2;
  *param_2 = fVar3;
  param_2[1] = fVar4;
  return;
}


// ==== 0x567690 FUN_00567690

void __fastcall FUN_00567690(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  
  fVar1 = *unaff_ESI;
  if (*param_1 < *unaff_ESI) {
    fVar1 = *param_1;
  }
  fVar2 = unaff_ESI[1];
  if (param_1[1] < unaff_ESI[1]) {
    fVar2 = param_1[1];
  }
  fVar3 = *unaff_EDI;
  if (*unaff_EDI < *param_2) {
    fVar3 = *param_2;
  }
  fVar4 = unaff_EDI[1];
  if (unaff_EDI[1] < param_2[1]) {
    fVar4 = param_2[1];
  }
  *param_1 = fVar1;
  param_1[1] = fVar2;
  *param_2 = fVar3;
  param_2[1] = fVar4;
  return;
}


// ==== 0x567710 FUN_00567710

void __fastcall FUN_00567710(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar1 = *in_EAX;
  uVar2 = in_EAX[1];
  uVar3 = in_EAX[2];
  *param_2 = uVar1;
  param_2[1] = uVar2;
  param_2[2] = uVar3;
  param_1[2] = uVar3;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return;
}


// ==== 0x567740 FUN_00567740

void __fastcall FUN_00567740(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar1 = *in_EAX;
  fVar2 = in_EAX[1];
  fVar3 = in_EAX[2];
  if (fVar1 < *param_1) {
    *param_1 = fVar1;
  }
  if (fVar2 < param_1[1]) {
    param_1[1] = fVar2;
  }
  if (fVar3 < param_1[2]) {
    param_1[2] = fVar3;
  }
  if (*param_2 < fVar1) {
    *param_2 = fVar1;
  }
  if (param_2[1] < fVar2) {
    param_2[1] = fVar2;
  }
  if (param_2[2] < fVar3) {
    param_2[2] = fVar3;
  }
  return;
}


// ==== 0x5677d0 FUN_005677d0

void __fastcall FUN_005677d0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_EAX;
  
  fVar1 = in_EAX[1];
  fVar2 = in_EAX[2];
  fVar3 = *in_EAX;
  fVar4 = in_EAX[1];
  fVar5 = in_EAX[2];
  if (*in_EAX - param_3 < *param_1) {
    *param_1 = *in_EAX - param_3;
  }
  if (fVar1 - param_3 < param_1[1]) {
    param_1[1] = fVar1 - param_3;
  }
  if (fVar2 - param_3 < param_1[2]) {
    param_1[2] = fVar2 - param_3;
  }
  if (*param_2 < param_3 + fVar3) {
    *param_2 = param_3 + fVar3;
  }
  if (param_2[1] < param_3 + fVar4) {
    param_2[1] = param_3 + fVar4;
  }
  if (param_2[2] < param_3 + fVar5) {
    param_2[2] = param_3 + fVar5;
  }
  return;
}


// ==== 0x567890 FUN_00567890

void __fastcall FUN_00567890(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_EAX;
  float *unaff_ESI;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  fVar3 = *in_EAX;
  fVar4 = in_EAX[1];
  fVar5 = in_EAX[2];
  if (*param_1 < *param_2) {
    *param_2 = *param_1;
  }
  if (fVar1 < param_2[1]) {
    param_2[1] = fVar1;
  }
  if (fVar2 < param_2[2]) {
    param_2[2] = fVar2;
  }
  if (*unaff_ESI < fVar3) {
    *unaff_ESI = fVar3;
  }
  if (unaff_ESI[1] < fVar4) {
    unaff_ESI[1] = fVar4;
  }
  if (unaff_ESI[2] < fVar5) {
    unaff_ESI[2] = fVar5;
  }
  return;
}


// ==== 0x567940 FUN_00567940

undefined4 __fastcall FUN_00567940(float *param_1,float *param_2,float param_3)

{
  float *unaff_ESI;
  
  if ((((*param_2 - param_3 <= *param_1) && (*param_1 <= param_3 + *unaff_ESI)) &&
      (param_2[1] - param_3 <= param_1[1])) &&
     (((param_1[1] <= param_3 + unaff_ESI[1] && (param_2[2] - param_3 <= param_1[2])) &&
      (param_1[2] <= param_3 + unaff_ESI[2])))) {
    return 1;
  }
  return 0;
}


// ==== 0x5679b0 PointInPolygon2D

/* [canon] track high (hopper+ghidra) docs/re/track.md */

undefined4 PointInPolygon2D(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *in_EAX;
  ushort uVar6;
  int iVar5;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  bool bVar11;
  int local_8;
  
  fVar2 = *in_EAX;
  fVar3 = in_EAX[1];
  iVar9 = 0;
  bVar11 = false;
  iVar5 = param_2 + -1;
  local_8 = 0;
  if (3 < param_2) {
    iVar8 = iVar5 * 8;
    pfVar7 = (float *)(param_1 + 4);
    iVar4 = 3;
    do {
      iVar5 = iVar4;
      if ((((*pfVar7 < fVar3 != (*pfVar7 == fVar3)) &&
           (pfVar10 = (float *)(iVar8 + 4 + param_1), fVar3 < *pfVar10)) ||
          ((fVar1 = *(float *)(iVar8 + 4 + param_1), pfVar10 = (float *)(iVar8 + 4 + param_1),
           fVar1 < fVar3 != (fVar1 == fVar3) && (fVar3 < *pfVar7)))) &&
         (fVar2 < ((*(float *)(iVar8 + param_1) - pfVar7[-1]) * (fVar3 - *pfVar7)) /
                  (*pfVar10 - *pfVar7) + pfVar7[-1])) {
        bVar11 = bVar11 == false;
      }
      if (pfVar7[2] < fVar3 == (pfVar7[2] == fVar3)) {
        if (*pfVar7 < fVar3 != (*pfVar7 == fVar3)) goto LAB_00567a94;
      }
      else {
        if (*pfVar7 <= fVar3) {
LAB_00567a94:
          if (pfVar7[2] <= fVar3) goto LAB_00567ad3;
        }
        if (fVar2 < ((fVar3 - pfVar7[2]) * (pfVar7[-1] - pfVar7[1])) / (*pfVar7 - pfVar7[2]) +
                    pfVar7[1]) {
          bVar11 = bVar11 == false;
        }
      }
LAB_00567ad3:
      if ((((pfVar7[4] < fVar3 != (pfVar7[4] == fVar3)) && (fVar3 < pfVar7[2])) ||
          ((pfVar7[2] < fVar3 != (pfVar7[2] == fVar3) && (fVar3 < pfVar7[4])))) &&
         (fVar2 < ((fVar3 - pfVar7[4]) * (pfVar7[1] - pfVar7[3])) / (pfVar7[2] - pfVar7[4]) +
                  pfVar7[3])) {
        bVar11 = bVar11 == false;
      }
      if ((((pfVar7[6] < fVar3 != (pfVar7[6] == fVar3)) && (fVar3 < pfVar7[4])) ||
          ((pfVar7[4] < fVar3 != (pfVar7[4] == fVar3) && (fVar3 < pfVar7[6])))) &&
         (fVar2 < ((fVar3 - pfVar7[6]) * (pfVar7[3] - pfVar7[5])) / (pfVar7[4] - pfVar7[6]) +
                  pfVar7[5])) {
        bVar11 = bVar11 == false;
      }
      iVar8 = (0x14 - param_1) + (int)pfVar7;
      iVar9 = local_8 + 4;
      pfVar7 = pfVar7 + 8;
      iVar4 = iVar5 + 4;
      local_8 = iVar9;
    } while (iVar5 + 4 < param_2);
  }
  if (iVar9 < param_2) {
    iVar8 = iVar5 * 8;
    pfVar7 = (float *)(param_1 + 4 + iVar9 * 8);
    param_2 = param_2 - iVar9;
    do {
      uVar6 = (ushort)((uint)iVar5 >> 0x10);
      if (*pfVar7 < fVar3 == (*pfVar7 == fVar3)) {
LAB_00567c02:
        fVar1 = *(float *)(iVar8 + 4 + param_1);
        pfVar10 = (float *)(iVar8 + 4 + param_1);
        iVar5 = CONCAT22(uVar6,(ushort)(fVar1 < fVar3) << 8 |
                               (ushort)(NAN(fVar1) || NAN(fVar3)) << 10 |
                               (ushort)(fVar1 == fVar3) << 0xe);
        if (fVar1 < fVar3 != (fVar1 == fVar3)) {
          fVar1 = *pfVar7;
          iVar5 = CONCAT22(uVar6,(ushort)(fVar3 < fVar1) << 8 |
                                 (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                                 (ushort)(fVar3 == fVar1) << 0xe);
          if (fVar3 < fVar1) goto LAB_00567c22;
        }
      }
      else {
        pfVar10 = (float *)(iVar8 + 4 + param_1);
        iVar5 = (uint)uVar6 << 0x10;
        if (*pfVar10 <= fVar3) goto LAB_00567c02;
LAB_00567c22:
        fVar1 = ((fVar3 - *pfVar7) * (*(float *)(iVar8 + param_1) - pfVar7[-1])) /
                (*pfVar10 - *pfVar7) + pfVar7[-1];
        iVar5 = CONCAT22((short)((uint)iVar5 >> 0x10),
                         (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                         (ushort)(fVar1 == fVar2) << 0xe);
        if (fVar1 < fVar2 == 0 && (fVar1 == fVar2) == 0) {
          bVar11 = bVar11 == false;
          iVar5 = CONCAT31((int3)((uint)iVar5 >> 8),bVar11);
        }
      }
      iVar8 = (-4 - param_1) + (int)pfVar7;
      pfVar7 = pfVar7 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),bVar11);
}


// ==== 0x567c70 bStringHash

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

int __fastcall bStringHash(undefined4 param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = -1;
  bVar2 = *param_2;
  while (bVar2 != 0) {
    iVar3 = iVar3 * 0x21 + (uint)bVar2;
    pbVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  return iVar3;
}


// ==== 0x567ca0 bStringHashSeeded

/* [canon] runtime high (hopper+capstone) docs/re/misc.md */

void __fastcall bStringHashSeeded(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    pcVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  return;
}


// ==== 0x567cc0 bStrLen

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __fastcall bStrLen(char *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != (char *)0x0) {
    cVar2 = *param_1;
    while (cVar2 != '\0') {
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar2 = param_1[iVar1];
    }
  }
  return;
}


// ==== 0x567ce0 bStrCpy

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __fastcall bStrCpy(char *param_1)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  
  cVar1 = *param_1;
  *in_EAX = cVar1;
  if (cVar1 != '\0') {
    pcVar2 = in_EAX;
    do {
      cVar1 = pcVar2[(int)(param_1 + (1 - (int)in_EAX))];
      pcVar2 = pcVar2 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x567d00 FUN_00567d00

void __fastcall FUN_00567d00(int param_1,int param_2)

{
  char cVar1;
  char *in_EAX;
  
  if (param_1 != 0) {
    param_2 = param_2 - (int)in_EAX;
    do {
      cVar1 = in_EAX[param_2];
      param_1 = param_1 + -1;
      *in_EAX = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      in_EAX = in_EAX + 1;
    } while (param_1 != 0);
  }
  return;
}


// ==== 0x567d30 bStrCmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __fastcall bStrCmp(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *in_EAX;
  
  do {
    cVar1 = *param_2;
    cVar2 = *in_EAX;
    param_2 = param_2 + 1;
    in_EAX = in_EAX + 1;
    if ((cVar1 == '\0') || (cVar2 == '\0')) break;
  } while (cVar1 == cVar2);
  return (int)cVar1 - (int)cVar2;
}


// ==== 0x567d50 FUN_00567d50

int __fastcall FUN_00567d50(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  
  do {
    iVar3 = in_EAX + -1;
    if (((in_EAX == 0) || (cVar1 = *param_1, cVar1 == '\0')) || (cVar2 = *param_2, cVar2 == '\0'))
    break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    in_EAX = iVar3;
  } while (cVar1 == cVar2);
  if (iVar3 < 0) {
    return 0;
  }
  if (*param_1 != '\0') {
    return 1;
  }
  if (*param_2 != '\0') {
    return -1;
  }
  return (int)param_1[-1] - (int)param_2[-1];
}


// ==== 0x567da0 bStrICmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __fastcall bStrICmp(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte *in_EAX;
  byte bVar2;
  
  do {
    bVar2 = *in_EAX;
    if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
      bVar2 = bVar2 & 0x5f;
    }
    bVar1 = *param_2;
    in_EAX = in_EAX + 1;
    if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
      bVar1 = bVar1 & 0x5f;
    }
    param_2 = param_2 + 1;
  } while (((bVar2 != 0) && (bVar1 != 0)) && (bVar2 == bVar1));
  return (int)(char)bVar2 - (int)(char)bVar1;
}


// ==== 0x567de0 bStrCat2

/* [canon] runtime low (ghidra+hopper) docs/re/runtime.md */

void __thiscall bStrCat2(char *param_1,char *param_2)

{
  char *pcVar1;
  int in_EAX;
  char cVar2;
  int iVar3;
  int iVar4;
  
  cVar2 = *param_1;
  iVar3 = 0;
  if (cVar2 != '\0') {
    iVar4 = in_EAX - (int)param_1;
    do {
      param_1[iVar4] = cVar2;
      cVar2 = param_1[1];
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
    } while (cVar2 != '\0');
  }
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    *(char *)(iVar3 + in_EAX) = cVar2;
    pcVar1 = param_2 + 1;
    iVar3 = iVar3 + 1;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  *(undefined1 *)(iVar3 + in_EAX) = 0;
  return;
}


// ==== 0x567e20 FUN_00567e20

void __fastcall FUN_00567e20(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc3fc;
  FUN_004f7b50();
  return;
}


// ==== 0x567e30 FUN_00567e30

undefined4 FUN_00567e30(void)

{
  return 0;
}


// ==== 0x567e40 FUN_00567e40

void * __thiscall FUN_00567e40(void *param_1,byte param_2)

{
  FUN_00567e20();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x567e60 FUN_00567e60

undefined4 * FUN_00567e60(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006bc3fc;
  FUN_005682d0();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x567eb0 FUN_00567eb0

void FUN_00567eb0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint local_64 [12];
  undefined4 local_34 [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar6 = local_64;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0xffffffff;
    puVar6 = puVar6 + 1;
  }
  Career__RefreshOpenEvents(local_64);
  puVar5 = local_34;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
  }
  iVar3 = 0;
  puVar5 = local_34;
  puVar4 = local_34 + 3;
  do {
    if ((local_64[iVar3] < 0x100) &&
       (puVar1 = (undefined4 *)(&DAT_00733ff8)[local_64[iVar3]], puVar1 != (undefined4 *)0x0)) {
      iVar2 = puVar1[1];
      local_8 = *puVar1;
      if (iVar2 == 0) {
        *puVar5 = local_8;
        puVar5 = puVar5 + 1;
      }
      else if (iVar2 == 1) {
        *puVar4 = local_8;
        puVar4 = puVar4 + 1;
      }
      else if (iVar2 == 6) {
        switch(*(undefined2 *)(puVar1 + 0xd)) {
        case 0:
          local_14 = local_8;
          break;
        case 1:
          local_10 = local_8;
          break;
        case 2:
          local_c = local_8;
          break;
        case 3:
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  puVar5 = local_34;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *puVar5;
    puVar5 = puVar5 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ==== 0x567f80 FUN_00567f80

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
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
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


// ==== 0x568200 FUN_00568200

uint FUN_00568200(void)

{
  uint in_EAX;
  uint uVar1;
  
  if (in_EAX < 0x100) {
    uVar1 = (&DAT_00733ff8)[in_EAX];
  }
  else {
    uVar1 = 0;
  }
  if ((*(int *)(uVar1 + 4) != 1) && (*(int *)(uVar1 + 4) != 7)) {
    uVar1 = *(uint *)(uVar1 + 8);
    switch(uVar1) {
    default:
      return CONCAT31((int3)(uVar1 >> 8),1);
    case 4:
      break;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x568250 FUN_00568250

void FUN_00568250(void)

{
  char cVar1;
  int in_EAX;
  
  if ((-1 < in_EAX) && (in_EAX < 0x100)) {
    Career__StartEvent();
    cVar1 = FUN_00568200();
    if (cVar1 != '\0') {
      Career__StartRaceFromEvent();
      return;
    }
    Career__WinEvent(in_EAX);
    FUN_005682d0();
  }
  return;
}


// ==== 0x5682a0 FUN_005682a0

void FUN_005682a0(void)

{
  int in_EAX;
  
  if ((-1 < in_EAX) && (in_EAX < 0x100)) {
    Career__StartEvent();
    Career__QuitEvent();
  }
  FUN_005682d0();
  return;
}


// ==== 0x5682d0 FUN_005682d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005682d0(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  undefined *puVar3;
  undefined8 uVar4;
  
  FUN_00567eb0(unaff_ESI,(undefined4 *)(unaff_ESI + 0x40));
  uVar4 = CONCAT44(0x20,*(undefined4 *)(unaff_ESI + 0x40));
  puVar3 = &DAT_006bc43c;
  FEngPrintf();
  FEngPrintf(&DAT_006bc43c,*(undefined4 *)(unaff_ESI + 0x44),0x20,puVar3,uVar4);
  FEngPrintf(&DAT_006bc43c,*(undefined4 *)(unaff_ESI + 0x48),0x20);
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x4c));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x50));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x58));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x5c));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x60));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 100));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x68));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x6c));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_ESI + 0x70));
  FEngPrintf("%.1f -- %.1f",(double)_DAT_0073498c,(double)_DAT_00734990);
  if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
     (uVar1 = DAT_0076026c, DAT_0073440c != '\0')) {
    uVar1 = 1000000000;
  }
  FEngPrintf(&DAT_006ca778,uVar1);
  FEngPrintf(&DAT_006ca778,DAT_00760270);
  FEngPrintf(&DAT_006ca778,DAT_00760274);
  FEngPrintf(&DAT_006ca778,DAT_00760278);
  uVar1 = FUN_005685d0();
  FEngPrintf(&DAT_006ca778,uVar1);
  iVar2 = FUN_005685d0();
  FEngPrintf(&DAT_006ca778,iVar2 + DAT_00760278);
  uVar1 = Career__GetUrlRank();
  FEngPrintf(&DAT_006ca778,uVar1);
  uVar1 = Career__GetUrlRank();
  FEngPrintf(&DAT_006ca778,uVar1);
  uVar1 = Career__GetUrlRank();
  FEngPrintf(&DAT_006ca778,uVar1);
  uVar1 = Career__GetUrlRank();
  FEngPrintf(&DAT_006ca778,uVar1);
  FEngPrintf(&DAT_006cc568,(&PTR_DAT_006f1fa0)[DAT_00734978]);
  return;
}


// ==== 0x568570 FUN_00568570

undefined4 FUN_00568570(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688733;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x74);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00567e60(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5685d0 FUN_005685d0

int FUN_005685d0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = 0;
  puVar3 = &DAT_006f1fb4;
  do {
    if ((uint)puVar3[3] < 0x20) {
      iVar2 = (&DAT_00733f78)[puVar3[3]];
    }
    else {
      iVar2 = 0;
    }
    switch(*puVar3) {
    default:
      iVar2 = 0;
      break;
    case 1:
      iVar2 = *(int *)(iVar2 + 0x10);
      break;
    case 2:
      iVar2 = *(int *)(iVar2 + 0x14);
      break;
    case 3:
      iVar2 = *(int *)(iVar2 + 0x18);
      break;
    case 4:
      iVar2 = *(int *)(iVar2 + 0x1c);
    }
    puVar3 = puVar3 + 5;
    iVar1 = iVar1 + iVar2;
  } while ((int)puVar3 < 0x6f21a8);
  return iVar1;
}


// ==== 0x568640 FUN_00568640

void __fastcall FUN_00568640(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc3ec;
  FUN_004f7b50();
  return;
}


// ==== 0x568650 FUN_00568650

void * __thiscall FUN_00568650(void *param_1,byte param_2)

{
  FUN_00568640();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x568670 FUN_00568670

void __thiscall FUN_00568670(undefined4 param_1,int param_2)

{
  if (param_2 == 0xc407210) {
    FUN_00568690(param_1);
  }
  return;
}


// ==== 0x568690 FUN_00568690

void __fastcall FUN_00568690(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  piVar3 = &DAT_006f1fb8;
  do {
    if (*piVar3 == param_2) {
      puVar1 = (undefined4 *)(iVar5 * 0x14 + 0x6f1fb0);
      if (puVar1 != (undefined4 *)0x0) {
        if ((uint)(&DAT_006f1fc0)[iVar5 * 5] < 0x20) {
          iVar4 = (&DAT_00733f78)[(&DAT_006f1fc0)[iVar5 * 5]];
        }
        else {
          iVar4 = 0;
        }
        uVar2 = *puVar1;
        switch(uVar2) {
        default:
          iVar4 = 0;
          break;
        case 1:
          iVar4 = *(int *)(iVar4 + 4);
          break;
        case 2:
          iVar4 = *(int *)(iVar4 + 8);
          break;
        case 3:
          iVar4 = *(int *)(iVar4 + 0xc);
        }
        if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
           (iVar6 = DAT_0076026c, DAT_0073440c != '\0')) {
          iVar6 = 1000000000;
        }
        if (iVar4 <= iVar6) {
          (&DAT_006f1fb4)[iVar5 * 5] = uVar2;
          DAT_0073497c = DAT_0073497c - iVar4;
          DAT_00734984 = DAT_00734984 + iVar4;
        }
      }
      return;
    }
    piVar3 = piVar3 + 5;
    iVar5 = iVar5 + 1;
  } while ((int)piVar3 < 0x6f21ac);
  return;
}


// ==== 0x568750 FUN_00568750

undefined4 * FUN_00568750(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006bc3ec;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x5687b0 FUN_005687b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005687b0(void)

{
  int iVar1;
  
  if (DAT_0073459c == 0) {
    DAT_0073465c = 0;
  }
  else {
    DAT_0073465c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d48 = 0;
  }
  else {
    DAT_006f1d48 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734660 = 0;
  }
  else {
    DAT_00734660 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d4c = 0;
  }
  else {
    DAT_006f1d4c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734664 = 0;
  }
  else {
    DAT_00734664 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d7c = 0;
  }
  else {
    DAT_006f1d7c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734668 = 0;
  }
  else {
    DAT_00734668 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  _DAT_006f1d50 = (float)iVar1;
  if (iVar1 < 0) {
    _DAT_006f1d50 = _DAT_006f1d50 + 4.2949673e+09;
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d54 = 0;
  }
  else {
    DAT_006f1d54 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d58 = 0;
  }
  else {
    DAT_006f1d58 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d64 = 0;
  }
  else {
    DAT_006f1d64 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_0073466c = 0;
  }
  else {
    DAT_0073466c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734674 = 0;
  }
  else {
    DAT_00734674 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d78 = 0;
  }
  else {
    DAT_006f1d78 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d84 = 0;
  }
  else {
    DAT_006f1d84 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d88 = 0;
  }
  else {
    DAT_006f1d88 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1d8c = 0;
  }
  else {
    DAT_006f1d8c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1da4 = 0;
  }
  else {
    DAT_006f1da4 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1da8 = 0;
  }
  else {
    DAT_006f1da8 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1dac = 0;
  }
  else {
    DAT_006f1dac = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1db0 = 0;
  }
  else {
    DAT_006f1db0 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_0073468c = 0;
  }
  else {
    DAT_0073468c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1db4 = 0;
  }
  else {
    DAT_006f1db4 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734690 = 0;
  }
  else {
    DAT_00734690 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_00734694 = 0;
  }
  else {
    DAT_00734694 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1df4 = 0;
  }
  else {
    DAT_006f1df4 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1df8 = 0;
  }
  else {
    DAT_006f1df8 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_0073495c = 0;
  }
  else {
    DAT_0073495c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1dd8 = 0;
  }
  else {
    DAT_006f1dd8 = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_006f1dec = 0;
  }
  else {
    DAT_006f1dec = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c == 0) {
    DAT_0073496c = 0;
  }
  else {
    DAT_0073496c = FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  if (DAT_0073459c != 0) {
    FUN_0057c480(0x20,1);
    if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
      DAT_007345a4 = (int *)0x0;
      DAT_0073459c = 0;
    }
  }
  return;
}


// ==== 0x568f70 FUN_00568f70

void FUN_00568f70(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(DAT_0073465c,0x20,1);
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(DAT_006f1d48,0x20,1);
      if (DAT_007345a0 != 0) {
        FUN_0057c3b0(DAT_00734660,0x20,1);
        if (DAT_007345a0 != 0) {
          FUN_0057c3b0(DAT_006f1d4c,0x20,1);
          if (DAT_007345a0 != 0) {
            FUN_0057c3b0(DAT_00734664,0x20,1);
            if (DAT_007345a0 != 0) {
              FUN_0057c3b0(DAT_006f1d7c,0x20,1);
              if (DAT_007345a0 != 0) {
                FUN_0057c3b0(DAT_00734668,0x20,1);
                if (DAT_007345a0 != 0) {
                  uVar3 = 1;
                  uVar2 = 0x20;
                  uVar1 = _ftol_nocw(0x20,1);
                  FUN_0057c3b0(uVar1,uVar2,uVar3);
                  if (DAT_007345a0 != 0) {
                    FUN_0057c3b0(DAT_006f1d54,0x20,1);
                    if (DAT_007345a0 != 0) {
                      FUN_0057c3b0(DAT_006f1d58,0x20,1);
                      if (DAT_007345a0 != 0) {
                        FUN_0057c3b0(DAT_006f1d64,0x20,1);
                        if (DAT_007345a0 != 0) {
                          FUN_0057c3b0(DAT_0073466c,0x20,1);
                          if (DAT_007345a0 != 0) {
                            FUN_0057c3b0(DAT_00734674,0x20,1);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(DAT_006f1d78,0x20,1);
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(DAT_006f1d84,0x20,1);
      if (DAT_007345a0 != 0) {
        FUN_0057c3b0(DAT_006f1d88,0x20,1);
        if (DAT_007345a0 != 0) {
          FUN_0057c3b0(DAT_006f1d8c,0x20,1);
          if (DAT_007345a0 != 0) {
            FUN_0057c3b0(DAT_006f1da4,0x20,1);
            if (DAT_007345a0 != 0) {
              FUN_0057c3b0(DAT_006f1da8,0x20,1);
              if (DAT_007345a0 != 0) {
                FUN_0057c3b0(DAT_006f1dac,0x20,1);
                if (DAT_007345a0 != 0) {
                  FUN_0057c3b0(DAT_006f1db0,0x20,1);
                  if (DAT_007345a0 != 0) {
                    FUN_0057c3b0(DAT_0073468c,0x20,1);
                    if (DAT_007345a0 != 0) {
                      FUN_0057c3b0(DAT_006f1db4,0x20,1);
                      if (DAT_007345a0 != 0) {
                        FUN_0057c3b0(DAT_00734690,0x20,1);
                        if (DAT_007345a0 != 0) {
                          FUN_0057c3b0(DAT_00734694,0x20,1);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(DAT_006f1df4,0x20,1);
  }
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(DAT_006f1df8,0x20,1);
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(DAT_0073495c,0x20,1);
      if (DAT_007345a0 != 0) {
        FUN_0057c3b0(DAT_006f1dd8,0x20,1);
        if (DAT_007345a0 != 0) {
          FUN_0057c3b0(DAT_006f1dec,0x20,1);
          if (DAT_007345a0 != 0) {
            FUN_0057c3b0(DAT_0073496c,0x20,1);
            if (DAT_007345a0 != 0) {
              FUN_0057c3b0(0x12341111,0x20,1);
            }
          }
        }
      }
    }
  }
  return;
}


// ==== 0x5693b0 FUN_005693b0

undefined1 FUN_005693b0(void)

{
  int in_EAX;
  
  if (*(int *)(*(int *)(in_EAX + 0x14) + 4) == 3) {
    return 1;
  }
  return *(undefined1 *)(in_EAX + 0x855);
}


// ==== 0x5693d0 FUN_005693d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005693d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  float *extraout_EDX;
  float *pfVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)(in_EAX * 0x20 + param_1);
  iVar5 = 0;
  if (0 < (int)(&DAT_0070467c)[in_EAX * 0x14]) {
    pfVar4 = (float *)(&DAT_00704680 + in_EAX * 0x14);
    do {
      if (0.01 < ABS(_K_ONE - SQRT(pfVar4[2] * pfVar4[2] + pfVar4[1] * pfVar4[1] + *pfVar4 * *pfVar4
                                  ))) {
        bNormalize3();
        pfVar4 = extraout_EDX;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
    } while (iVar5 < (int)(&DAT_0070467c)[in_EAX * 0x14]);
  }
  uVar1 = param_2[2];
  uVar2 = *param_2;
  puVar3[1] = param_2[1];
  *puVar3 = uVar2;
  puVar3[2] = uVar1;
  return;
}


// ==== 0x569460 CarPartCuller::CullParts

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime low (ghidra+hopper) docs/re/tuning.md */

void CarPartCuller__CullParts(float *param_1,ushort param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  undefined4 *in_EAX;
  uint uVar12;
  float *pfVar13;
  int iVar14;
  int *piVar15;
  undefined4 uVar16;
  float *pfVar18;
  float *pfStack_bc;
  float afStack_b8 [3];
  undefined1 auStack_ac [12];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
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
  undefined1 local_50 [76];
  char cVar17;
  
  local_9c = in_EAX[1];
  local_a0 = *in_EAX;
  local_98 = in_EAX[2];
  local_90 = 0x3f800000;
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
  FUN_0040b930();
  D3DXMatrixMultiply(&local_90,&local_90,local_50);
  D3DXVec3Transform(auStack_ac);
  uVar12 = DAT_007355b4 + 0x10;
  piVar15 = &DAT_0070467c;
  do {
    iVar9 = piVar15[0xd];
    pfVar18 = (float *)(piVar15 + 0xd);
    if (uVar12 < DAT_007355b8) {
      DAT_007355b4 = DAT_007355b4 + 0x10;
      uVar12 = uVar12 + 0x10;
    }
    else {
      DAT_007355c8 = DAT_007355c8 + 0x10;
      DAT_007355c4 = 1;
    }
    if (((int)piVar15 < 0x70485c) || (pfVar13 = afStack_b8, 0x7048ac < (int)piVar15)) {
      pfVar13 = pfStack_bc;
    }
    if ((int)piVar15 < 0x7046cd) {
      if (0x8000 < param_2) {
        param_2 = -param_2;
      }
      *pfVar18 = (float)param_2 / _DAT_006f1a7c + *pfVar18;
    }
    iVar10 = *piVar15;
    uVar16 = 0x1000000;
    cVar17 = '\x01';
    if (0 < iVar10) {
      fVar1 = *pfVar13;
      fVar2 = *param_1;
      fVar3 = pfVar13[1];
      fVar4 = param_1[1];
      fVar5 = pfVar13[2];
      fVar6 = param_1[2];
      if (piVar15[-1] == 0) {
        iVar14 = 0;
        cVar17 = '\x01';
        if (0 < iVar10) {
          pfVar13 = (float *)(piVar15 + 3);
          do {
            fVar7 = pfVar13[-2];
            fVar11 = *pfVar13;
            fVar8 = pfVar13[-1];
            if (DAT_007345d4 != 0) {
              bNormalize3();
            }
            cVar17 = (char)((uint)uVar16 >> 0x18);
            if ((fVar7 * (fVar1 - fVar2) + fVar8 * (fVar3 - fVar4) + fVar11 * (fVar5 - fVar6)) -
                *pfVar18 < 0.0) break;
            pfVar18 = pfVar18 + 1;
            iVar14 = iVar14 + 1;
            pfVar13 = pfVar13 + 4;
          } while (iVar14 < *piVar15);
        }
        if (iVar14 == *piVar15) {
LAB_005696e0:
          cVar17 = '\0';
        }
      }
      else if ((piVar15[-1] == 1) && (iVar14 = 0, 0 < iVar10)) {
        pfVar13 = (float *)(piVar15 + 3);
        do {
          fVar7 = pfVar13[-2];
          fVar11 = *pfVar13;
          fVar8 = pfVar13[-1];
          if (DAT_007345d4 != 0) {
            bNormalize3();
          }
          cVar17 = (char)((uint)uVar16 >> 0x18);
          if (0.0 <= (fVar7 * (fVar1 - fVar2) + fVar8 * (fVar3 - fVar4) + fVar11 * (fVar5 - fVar6))
                     - *pfVar18) goto LAB_005696e0;
          pfVar18 = pfVar18 + 1;
          iVar14 = iVar14 + 1;
          pfVar13 = pfVar13 + 4;
        } while (iVar14 < *piVar15);
      }
    }
    *(char *)(param_1 + 6) = cVar17;
    piVar15[0xd] = iVar9;
    if (cVar17 == '\0') {
      param_1[4] = (float)((int)param_1[4] + 1);
    }
    else {
      param_1[5] = (float)((int)param_1[5] + 1);
    }
    piVar15 = piVar15 + 0x14;
    param_1 = param_1 + 8;
    if (0x704adb < (int)piVar15) {
      return;
    }
  } while( true );
}


// ==== 0x5697b0 FUN_005697b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005697b0(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  
  DAT_00734610 = (undefined4 *)FUN_00566dc0(0x14,"CarEmitterPositionSlotPool",0);
  if ((DAT_00734610 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00734610;
    puVar3 = DAT_00734610;
    DAT_00734610[1] = DAT_0073d81c;
    DAT_0073d81c = puVar3;
    *DAT_00734610 = &DAT_0073d818;
  }
  piVar6 = &DAT_006f1bcc;
  do {
    pbVar4 = (byte *)piVar6[-1];
    iVar5 = -1;
    bVar2 = *pbVar4;
    while (bVar2 != 0) {
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar4 + 1;
      pbVar4 = pbVar4 + 1;
      bVar2 = *pbVar1;
    }
    *piVar6 = iVar5;
    piVar6 = piVar6 + 2;
  } while ((int)piVar6 < 0x6f1cb4);
  _DAT_0073d720 = 0x3f800000;
  _DAT_0073d724 = 0;
  _DAT_0073d728 = 0;
  _DAT_0073d72c = 0;
  _DAT_0073d730 = 0;
  _DAT_0073d734 = 0x3f800000;
  _DAT_0073d738 = 0;
  _DAT_0073d73c = 0;
  _DAT_0073d740 = 0;
  _DAT_0073d744 = 0;
  _DAT_0073d748 = 0x3f800000;
  _DAT_0073d74c = 0;
  _DAT_0073d750 = 0;
  _DAT_0073d754 = 0;
  _DAT_0073d758 = 0;
  _DAT_0073d75c = 0x3f800000;
  _DAT_0073ca80 = 0;
  _DAT_0073ca84 = 0;
  _DAT_0073ca88 = 0;
  _DAT_0073ca8c = 0x3f800000;
  _DAT_0073ca98 = 0;
  _DAT_0073ca9c = 0;
  _DAT_0073ca90 = 0x3f800000;
  _DAT_0073ca94 = 0x3f800000;
  _DAT_0073caa8 = 0x3f800000;
  _DAT_0073caac = 0;
  _DAT_0073caa0 = 0x80808080;
  return;
}


// ==== 0x569930 FUN_00569930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00569930(void)

{
  _DAT_0073d6c4 = DAT_00743c74;
  DAT_0073d6c8 = 0xc7395a8;
  _DAT_0073d6d0 = 0;
  _DAT_0073d6d4 = 0;
  *DAT_00743c74 = &DAT_0073d6c0;
  DAT_00743c74 = (undefined4 *)&DAT_0073d6c0;
  _DAT_0073d6c0 = &DAT_00743c70;
  if (DAT_0073d6c8 != 0) {
    Solid_FindInAllLists();
    FUN_0053f4b0();
  }
  return;
}


// ==== 0x569990 Car::InitRenderInfo

/* [canon] render med (ghidra+hopper) docs/re/tuning.md */

void Car__InitRenderInfo(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686823;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x1dc0);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = CarRenderInfo__CarRenderInfo(pvVar1,param_1);
  }
  *(undefined4 *)(unaff_ESI + 0x4d4) = uVar2;
  FUN_005712a0(uVar2,unaff_ESI);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x569a00 FUN_00569a00

void __thiscall FUN_00569a00(int param_1,int param_2,float param_3,uint param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *local_e8;
  int local_e4;
  int local_e0;
  undefined1 local_d0 [48];
  int local_a0;
  int local_9c;
  int local_98;
  undefined4 local_94;
  undefined1 local_90 [48];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [76];
  
  iVar2 = *(int *)(param_2 + 0x4d4);
  if ((((iVar2 != 0) && (param_3 != 0.0)) && (param_1 != 0)) && (*(int *)(param_2 + 0x530) == 0)) {
    local_e8 = (undefined4 *)(iVar2 + 0x544 + param_1 * 8);
    if (((0 < param_1) && (param_1 < 6)) && (DAT_00734460 != 0)) {
      local_e8 = (undefined4 *)(DAT_00734460 + -0xe8 + (param_1 * 0x1d + (param_4 & 0xffff)) * 8);
    }
    local_e4 = 0;
    if ((((param_1 != 3) && (param_1 != 4)) && ((param_1 != 8 && (param_1 != 9)))) ||
       ((local_e4 = (int)param_4 >> 0x10, local_e4 < 1 ||
        (puVar7 = (undefined4 *)(param_2 + 0x60), 8 < local_e4)))) {
      puVar7 = (undefined4 *)(param_2 + 0x50);
    }
    bMatrixCopy_b();
    local_5c = puVar7[1];
    local_60 = *puVar7;
    local_58 = puVar7[2];
    local_54 = 0x3f800000;
    puVar7 = (undefined4 *)(param_2 + 0x70);
    if (param_5 != (undefined4 *)0x0) {
      puVar7 = param_5;
    }
    local_e8 = (undefined4 *)*local_e8;
    puVar5 = (undefined4 *)NullUpdate_ret();
    for (; local_e8 != puVar5; local_e8 = (undefined4 *)*local_e8) {
      bMatrixCopy_b();
      piVar6 = (int *)(iVar2 + 0x62c + *(int *)(local_e8[7] + 0x58) * 8);
      if (local_e4 != 0) {
        piVar6 = (int *)(iVar2 + 0x62c + local_e4 * 8);
      }
      piVar8 = (int *)*piVar6;
      if (piVar8 != piVar6) {
        do {
          iVar3 = piVar8[4];
          if (iVar3 == 0) {
            local_e0 = piVar8[3];
            local_a0 = piVar8[1];
            local_9c = piVar8[2];
          }
          else {
            local_e0 = *(int *)(iVar3 + 0x48);
            local_a0 = *(int *)(iVar3 + 0x40);
            local_9c = *(int *)(iVar3 + 0x44);
          }
          local_98 = local_e0;
          local_94 = 0x3f800000;
          D3DXMatrixMultiply(local_50,local_d0,local_90);
          bMatrixCopy_b();
          uVar1 = puVar7[2];
          uVar4 = *puVar7;
          local_e8[0x1d] = puVar7[1];
          local_e8[0x1e] = uVar1;
          local_e8[0x1c] = uVar4;
          local_e8[0x1f] = 0;
          FUN_00402d30(&DAT_0078e9e0,local_e8,-param_3,param_2);
          piVar8 = (int *)*piVar8;
        } while (piVar8 != piVar6);
      }
      bMatrixCopy_b();
    }
  }
  return;
}


// ==== 0x569c30 FUN_00569c30

void __thiscall FUN_00569c30(int param_1,undefined1 param_2)

{
  *(undefined1 *)(*(int *)(param_1 + 0x10) + 7) = param_2;
  FUN_0056c310();
  return;
}


// ==== 0x569c50 FrontEndRenderingCar::FrontEndRenderingCar

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void FrontEndRenderingCar__FrontEndRenderingCar(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  RideInfo__Init();
  in_EAX[2] = 0;
  FrontEndRenderingCar__ReInit(param_1);
  in_EAX[0x1cc] = param_2;
  in_EAX[0x1d0] = 0;
  in_EAX[0x1d1] = 0;
  in_EAX[0x1d2] = 0;
  in_EAX[0x1d5] = 0;
  in_EAX[0x1d6] = 0;
  in_EAX[0x1d7] = 0;
  in_EAX[0x1d8] = 0;
  in_EAX[0x1da] = 0;
  in_EAX[0x1db] = 0;
  in_EAX[0x1dc] = 0;
  in_EAX[0x1dd] = 0;
  in_EAX[0x1df] = 0;
  in_EAX[0x1e0] = 0;
  in_EAX[0x1e1] = 0;
  in_EAX[0x1e2] = 0;
  in_EAX[0x1d4] = 0x3f800000;
  in_EAX[0x1d9] = 0x3f800000;
  in_EAX[0x1de] = 0x3f800000;
  in_EAX[0x1e3] = 0x3f800000;
  in_EAX[0x1e4] = 0x3f800000;
  in_EAX[0x1e5] = 0;
  in_EAX[0x1e6] = 0;
  in_EAX[0x1e7] = 0;
  in_EAX[0x1e8] = 0;
  in_EAX[0x1e9] = 0x3f800000;
  in_EAX[0x1ea] = 0;
  in_EAX[0x1eb] = 0;
  in_EAX[0x1ec] = 0;
  in_EAX[0x1ed] = 0;
  in_EAX[0x1ee] = 0x3f800000;
  in_EAX[0x1ef] = 0;
  in_EAX[0x1f0] = 0;
  in_EAX[0x1f1] = 0;
  in_EAX[0x1f2] = 0;
  in_EAX[499] = 0x3f800000;
  in_EAX[500] = 0x3f800000;
  in_EAX[0x1f5] = 0;
  in_EAX[0x1f6] = 0;
  in_EAX[0x1f7] = 0;
  in_EAX[0x1f8] = 0;
  in_EAX[0x1f9] = 0x3f800000;
  in_EAX[0x1fa] = 0;
  in_EAX[0x1fb] = 0;
  in_EAX[0x1fc] = 0;
  in_EAX[0x1fd] = 0;
  in_EAX[0x1fe] = 0x3f800000;
  in_EAX[0x1ff] = 0;
  in_EAX[0x200] = 0;
  in_EAX[0x201] = 0;
  in_EAX[0x202] = 0;
  in_EAX[0x203] = 0x3f800000;
  in_EAX[0x204] = 0x3f800000;
  in_EAX[0x205] = 0;
  in_EAX[0x206] = 0;
  in_EAX[0x207] = 0;
  in_EAX[0x208] = 0;
  in_EAX[0x209] = 0x3f800000;
  in_EAX[0x20a] = 0;
  in_EAX[0x20b] = 0;
  in_EAX[0x20c] = 0;
  in_EAX[0x20d] = 0;
  in_EAX[0x20e] = 0x3f800000;
  in_EAX[0x20f] = 0;
  in_EAX[0x210] = 0;
  in_EAX[0x211] = 0;
  in_EAX[0x212] = 0;
  in_EAX[0x213] = 0x3f800000;
  in_EAX[0x214] = 0x3f800000;
  in_EAX[0x219] = 0x3f800000;
  in_EAX[0x21e] = 0x3f800000;
  in_EAX[0x223] = 0x3f800000;
  in_EAX[0x215] = 0;
  in_EAX[0x216] = 0;
  in_EAX[0x217] = 0;
  in_EAX[0x218] = 0;
  in_EAX[0x21a] = 0;
  in_EAX[0x21b] = 0;
  in_EAX[0x21c] = 0;
  in_EAX[0x21d] = 0;
  in_EAX[0x21f] = 0;
  in_EAX[0x220] = 0;
  in_EAX[0x221] = 0;
  in_EAX[0x222] = 0;
  in_EAX[0x224] = 0x3f800000;
  in_EAX[0x229] = 0x3f800000;
  in_EAX[0x22e] = 0x3f800000;
  in_EAX[0x233] = 0x3f800000;
  in_EAX[0x225] = 0;
  in_EAX[0x226] = 0;
  in_EAX[0x227] = 0;
  in_EAX[0x228] = 0;
  in_EAX[0x22a] = 0;
  in_EAX[0x22b] = 0;
  in_EAX[0x22c] = 0;
  in_EAX[0x22d] = 0;
  in_EAX[0x22f] = 0;
  in_EAX[0x230] = 0;
  in_EAX[0x231] = 0;
  in_EAX[0x232] = 0;
  in_EAX[0x234] = 0x3f800000;
  in_EAX[0x239] = 0x3f800000;
  in_EAX[0x23e] = 0x3f800000;
  in_EAX[0x243] = 0x3f800000;
  in_EAX[0x235] = 0;
  in_EAX[0x236] = 0;
  in_EAX[0x237] = 0;
  in_EAX[0x238] = 0;
  in_EAX[0x23a] = 0;
  in_EAX[0x23b] = 0;
  in_EAX[0x23c] = 0;
  in_EAX[0x23d] = 0;
  in_EAX[0x23f] = 0;
  in_EAX[0x240] = 0;
  in_EAX[0x241] = 0;
  in_EAX[0x242] = 0;
  in_EAX[0x244] = 0x3f800000;
  in_EAX[0x249] = 0x3f800000;
  in_EAX[0x24e] = 0x3f800000;
  in_EAX[0x253] = 0x3f800000;
  in_EAX[0x245] = 0;
  in_EAX[0x246] = 0;
  in_EAX[0x247] = 0;
  in_EAX[0x248] = 0;
  in_EAX[0x24a] = 0;
  in_EAX[0x24b] = 0;
  in_EAX[0x24c] = 0;
  in_EAX[0x24d] = 0;
  in_EAX[0x24f] = 0;
  in_EAX[0x250] = 0;
  in_EAX[0x251] = 0;
  in_EAX[0x252] = 0;
  in_EAX[0x254] = 0x3f800000;
  in_EAX[0x259] = 0x3f800000;
  in_EAX[0x25e] = 0x3f800000;
  in_EAX[0x263] = 0x3f800000;
  in_EAX[0x255] = 0;
  in_EAX[0x256] = 0;
  in_EAX[599] = 0;
  in_EAX[600] = 0;
  in_EAX[0x25a] = 0;
  in_EAX[0x25b] = 0;
  in_EAX[0x25c] = 0;
  in_EAX[0x25d] = 0;
  in_EAX[0x25f] = 0;
  in_EAX[0x260] = 0;
  in_EAX[0x261] = 0;
  in_EAX[0x262] = 0;
  in_EAX[0x264] = 0;
  in_EAX[0x265] = 1;
  in_EAX[0x266] = 1;
  in_EAX[0x267] = 0;
  in_EAX[0x268] = 0;
  in_EAX[0x269] = 0;
  *DAT_0073d6dc = in_EAX;
  puVar1 = in_EAX;
  in_EAX[1] = DAT_0073d6dc;
  DAT_0073d6dc = puVar1;
  *in_EAX = &DAT_0073d6d8;
  return;
}


// ==== 0x56a040 FrontEndRenderingCar::ReInit

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void FrontEndRenderingCar__ReInit(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685feb;
  local_c = ExceptionList;
  pvVar1 = *(void **)(unaff_EDI + 8);
  ExceptionList = &local_c;
  if (pvVar1 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_0056c140(pvVar1);
    _free(pvVar1);
    *(undefined4 *)(unaff_EDI + 8) = 0;
  }
  if (param_1 != 0) {
    RideInfo__operator_(unaff_EDI + 0x10,param_1);
    pvVar1 = _malloc(0x1dc0);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = CarRenderInfo__CarRenderInfo(pvVar1,unaff_EDI + 0x10,0);
    }
    *(undefined4 *)(unaff_EDI + 8) = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x56a0d0 FUN_0056a0d0

void FUN_0056a0d0(void)

{
  void *_Memory;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *in_EAX;
  
  _Memory = (void *)in_EAX[2];
  if (_Memory != (void *)0x0) {
    FUN_0056c140(_Memory);
    _free(_Memory);
    in_EAX[2] = 0;
  }
  puVar1 = (undefined4 *)in_EAX[0x264];
  if (puVar1 != (undefined4 *)0x0) {
    ListRef_Release();
    iVar4 = DAT_0073557c;
    iVar2 = *(int *)(DAT_0073557c + 0x18);
    *puVar1 = *(undefined4 *)(DAT_0073557c + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar4 + 0x10) = puVar1;
    in_EAX[0x264] = 0;
  }
  iVar2 = *in_EAX;
  piVar3 = (int *)in_EAX[1];
  *piVar3 = iVar2;
  *(int **)(iVar2 + 4) = piVar3;
  return;
}


// ==== 0x56a130 CarRenderInfo::CarRenderInfo

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (ghidra+hopper) docs/re/tuning.md */

int * CarRenderInfo__CarRenderInfo(int *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  int iVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  char cVar10;
  ushort uVar11;
  ushort uVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  undefined4 *puVar19;
  int iVar20;
  uint uVar21;
  byte *pbVar22;
  int *piVar23;
  char *pcVar24;
  int iVar25;
  int extraout_EDX;
  int *piVar26;
  undefined *puVar27;
  float *pfVar28;
  uint *puVar29;
  int local_570 [256];
  byte local_170;
  byte local_16f [63];
  int aiStack_130 [32];
  int *local_b0;
  int *local_ac;
  int *local_a8;
  uint local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  uint local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  int *local_44;
  int *local_40;
  uint local_3c;
  int *local_38;
  uint *local_34;
  uint *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  pcStack_18 = FUN_006867fb;
  local_1c = ExceptionList;
  piVar17 = param_1 + 0x140;
  ExceptionList = &local_1c;
  *piVar17 = (int)piVar17;
  param_1[0x141] = (int)piVar17;
  local_b0 = param_1 + 0x151;
  local_14 = 0;
  eh_vector_constructor_iterator(local_b0,8,0x1d,IList_InitEmpty_Thunk,List_DeleteAllNodes);
  local_40 = param_1 + 0x18b;
  local_14._0_1_ = 1;
  eh_vector_constructor_iterator(local_40,8,0x1c,FUN_0049fd90,FUN_00571560);
  local_44 = param_1 + 0x1c3;
  local_14._0_1_ = 2;
  iVar20 = 0x3a;
  piVar17 = local_44;
  do {
    *piVar17 = 0;
    piVar17[1] = 0;
    piVar17[2] = 0;
    piVar17[3] = 0;
    piVar17 = piVar17 + 4;
    iVar20 = iVar20 + -1;
  } while (iVar20 != 0);
  piVar17 = param_1 + 0x2ab;
  iVar20 = 0x38;
  do {
    *piVar17 = 0;
    piVar17[1] = 0;
    piVar17[2] = 0;
    piVar17[3] = 0;
    piVar17 = piVar17 + 4;
    iVar20 = iVar20 + -1;
  } while (iVar20 != 0);
  piVar17 = param_1 + 0x38b;
  iVar20 = 2;
  do {
    *piVar17 = 0;
    piVar17[1] = 0;
    piVar17[2] = 0;
    piVar17[3] = 0;
    piVar17 = piVar17 + 4;
    iVar20 = iVar20 + -1;
  } while (iVar20 != 0);
  piVar17 = param_1 + 0x393;
  iVar20 = 2;
  do {
    *piVar17 = 0;
    piVar17[1] = 0;
    piVar17[2] = 0;
    piVar17[3] = 0;
    piVar17 = piVar17 + 4;
    iVar20 = iVar20 + -1;
  } while (iVar20 != 0);
  local_a8 = param_1 + 0x39b;
  eh_vector_constructor_iterator(local_a8,0x18,0x78,ListRef_Init,ListRef_Release);
  piVar17 = param_1 + 0x676;
  *piVar17 = (int)piVar17;
  param_1[0x677] = (int)piVar17;
  param_1[0x675] = 1;
  *(undefined1 *)(param_1 + 0x66d) = 0;
  local_14._0_1_ = 4;
  eh_vector_constructor_iterator(param_1 + 0x678,0x68,2,FUN_004ad8d0,NullUpdate_ret);
  local_14._0_1_ = 5;
  eh_vector_constructor_iterator(param_1 + 0x6b0,0xa0,2,ePoly__ePoly,NullUpdate_ret);
  local_2c = param_1 + 0x700;
  piVar17 = local_2c;
  for (iVar20 = 0x70; iVar20 != 0; iVar20 = iVar20 + -1) {
    *piVar17 = 0;
    piVar17 = piVar17 + 1;
  }
  param_1[1] = param_2;
  *param_1 = param_3;
  *(undefined2 *)(param_1 + 3) = 0xffff;
  iVar20 = DAT_00734594;
  uVar14 = DAT_006f227c ^ 0x1d872b41;
  uVar15 = uVar14 >> 5 ^ uVar14;
  uVar21 = DAT_006f227c & 7;
  DAT_006f227c = uVar15 << 0x1b ^ uVar15 ^ uVar14;
  param_1[0x142] = uVar21;
  piVar17 = (int *)param_1[1];
  iVar16 = *piVar17 * 0xc90 + DAT_00734588;
  local_14 = CONCAT31(local_14._1_3_,6);
  local_24 = (int *)0x0;
  piVar18 = DAT_00734590;
  if (0 < iVar20) {
    do {
      if ((*piVar18 == *piVar17) && (piVar18[1] == (int)*(char *)((int)piVar17 + 7))) break;
      piVar18 = piVar18 + 0x10;
      local_24 = (int *)((int)local_24 + 1);
    } while ((int)local_24 < DAT_00734594);
  }
  param_1[2] = iVar16;
  local_38 = (int *)(iVar16 + 0x20);
  piVar18 = *(int **)(piVar17[0x124] + 0x14);
  piVar17 = piVar18 + *(short *)(piVar17[0x124] + 0x1c) * 2;
  if (piVar18 != (int *)0x0) {
    for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
      if (*piVar18 == -0x14fefe1e) {
        if (piVar18 != (int *)0x0) {
          cVar10 = (char)piVar18[1];
          goto LAB_0056a396;
        }
        break;
      }
    }
  }
  cVar10 = '\0';
LAB_0056a396:
  local_3c = (uint)cVar10;
  pcVar24 = "BLURTEST";
  iVar20 = -1;
  uVar14 = 0x42;
  local_28 = (int *)((float)(int)local_3c * 1.27 * 0.01);
  do {
    iVar20 = iVar20 * 0x21 + uVar14;
    pbVar22 = (byte *)(pcVar24 + 1);
    uVar14 = (uint)*pbVar22;
    pcVar24 = pcVar24 + 1;
  } while (*pbVar22 != 0);
  iVar20 = Texture_FindByHash(iVar20,1,0);
  local_30 = (uint *)-(float)local_28;
  param_1[0x6ac] = iVar20;
  local_34 = (uint *)0x0;
  do {
    puVar29 = local_34;
    *(undefined1 *)(param_1 + (int)local_34 * 0x28 + 0x6d0) = 0x80;
    *(undefined1 *)(param_1 + (int)local_34 * 0x28 + 0x6d1) = 0x80;
    *(undefined1 *)(param_1 + (int)local_34 * 0x28 + 0x6d2) = 0x80;
    *(undefined1 *)(param_1 + (int)local_34 * 0x28 + 0x6d3) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b41) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b45) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b49) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b4d) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b42) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b46) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b4a) = 0x80;
    *(undefined1 *)((int)param_1 + (int)local_34 * 0xa0 + 0x1b4e) = 0x80;
    param_1[(int)local_34 * 0x28 + 0x6c4] = 0;
    param_1[(int)local_34 * 0x28 + 0x6c5] = 0;
    param_1[(int)local_34 * 0x28 + 0x6c6] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6c7] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6c8] = 0;
    param_1[(int)local_34 * 0x28 + 0x6c9] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6cd] = 0;
    param_1[(int)local_34 * 0x28 + 0x6ce] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6cf] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6ca] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6cb] = 0x3f800000;
    param_1[(int)local_34 * 0x28 + 0x6cc] = 0x3f800000;
    aiStack_130[0xc] = 0x3f800000;
    aiStack_130[0xd] = 0;
    aiStack_130[0xe] = 0;
    aiStack_130[0xf] = 0;
    aiStack_130[0x10] = 0;
    aiStack_130[0x11] = 0x3f800000;
    aiStack_130[0x12] = 0;
    aiStack_130[0x13] = 0;
    aiStack_130[0x14] = 0;
    aiStack_130[0x15] = 0;
    aiStack_130[0x16] = 0x3f800000;
    aiStack_130[0x17] = 0;
    aiStack_130[0x18] = 0;
    aiStack_130[0x19] = 0;
    aiStack_130[0x1a] = 0;
    aiStack_130[0x1b] = 0x3f800000;
    if (local_34 == (uint *)0x0) {
      FUN_0040ba40(aiStack_130 + 0xc,aiStack_130 + 0xc);
    }
    local_a0 = (float)local_30;
    local_98 = (float)local_30;
    local_68 = (float)local_30;
    local_80 = (float)local_30;
    local_70 = (float)local_28;
    local_78 = (float)local_28;
    local_60 = (float)local_28;
    local_58 = (float)local_28;
    local_9c = -0.015;
    local_94 = 0x3f800000;
    local_6c = -0.015;
    local_64 = 0x3f800000;
    local_7c = -0.015;
    local_74 = 0x3f800000;
    local_5c = -0.015;
    local_54 = 0x3f800000;
    thunk_FUN_005ac436(&local_a0,&local_a0,aiStack_130 + 0xc);
    thunk_FUN_005ac436(&local_70,&local_70,aiStack_130 + 0xc);
    thunk_FUN_005ac436(&local_80,&local_80,aiStack_130 + 0xc);
    thunk_FUN_005ac436(&local_60,&local_60,aiStack_130 + 0xc);
    param_1[((int)local_34 * 5 + 0xd7) * 8] = (int)local_70;
    param_1[(int)puVar29 * 0x28 + 0x6b4] = (int)local_a0;
    param_1[(int)puVar29 * 0x28 + 0x6c0] = (int)local_80;
    param_1[(int)puVar29 * 0x28 + 0x6bc] = (int)local_60;
    param_1[(int)puVar29 * 0x28 + 0x6b5] = (int)local_9c;
    param_1[(int)puVar29 * 0x28 + 0x6b9] = (int)local_6c;
    param_1[(int)puVar29 * 0x28 + 0x6c1] = (int)local_7c;
    param_1[(int)puVar29 * 0x28 + 0x6bd] = (int)local_5c;
    local_34 = (uint *)((int)local_34 + 1);
    param_1[(int)puVar29 * 0x28 + 0x6b6] = (int)local_98;
    param_1[(int)puVar29 * 0x28 + 0x6ba] = (int)local_68;
    param_1[(int)puVar29 * 0x28 + 0x6c2] = (int)local_78;
    param_1[(int)puVar29 * 0x28 + 0x6be] = (int)local_58;
  } while ((int)local_34 < 2);
  GetUsedCarTextureInfo(param_1 + 0x10,param_1[1],0);
  iVar20 = param_1[0x103];
  *local_44 = param_1[0x102];
  param_1[0x1cb] = param_1[0x104];
  param_1[0x1c7] = iVar20;
  param_1[0x1d7] = param_1[0x107];
  param_1[0x1d3] = param_1[0x105];
  param_1[0x1cf] = param_1[0x106];
  param_1[0x217] = param_1[0x108];
  param_1[0x1e3] = param_1[0x114];
  param_1[0x1df] = param_1[0x113];
  param_1[0x223] = param_1[0x10b];
  param_1[0x21f] = param_1[0x10a];
  param_1[0x21b] = param_1[0x109];
  param_1[0x22f] = param_1[0x10e];
  param_1[0x22b] = param_1[0x10d];
  param_1[0x227] = param_1[0x10c];
  param_1[0x23b] = param_1[0x111];
  param_1[0x237] = param_1[0x110];
  param_1[0x1db] = 0x5799e60b;
  param_1[0x1e7] = 0x7b220ddf;
  param_1[0x1eb] = 0x1b0763a0;
  param_1[0x1ef] = -0x181b10b7;
  param_1[499] = 0x4cdebfca;
  param_1[0x1f7] = 0x60f8b13c;
  param_1[0x1fb] = 0xab88f5d;
  param_1[0x1ff] = -0x6f1f698f;
  param_1[0x203] = 0x13ee21f2;
  param_1[0x207] = -0x29765ce5;
  param_1[0x20b] = -0x470cbea4;
  param_1[0x20f] = 0x2433df4e;
  param_1[0x213] = -0x6a2bcd1;
  param_1[0x233] = param_1[0x10f];
  param_1[0x38b] = 0x17f9f794;
  if (param_1[0x38c] != -0x7a163862) {
    param_1[0x38c] = -0x7a163862;
    param_1[0x38d] = -1;
  }
  param_1[0x38f] = param_1[0x104];
  param_1[0x393] = 0x17f9f794;
  if (param_1[0x394] != 0x17f9f794) {
    param_1[0x394] = 0x17f9f794;
    param_1[0x395] = -1;
  }
  local_ac = param_1 + 0x397;
  *local_ac = param_1[0x104];
  FUN_0056c310();
  local_34 = (uint *)param_1[0x106];
  pbVar22 = *(byte **)(&DAT_006f21bc + DAT_00734998 * 0x10);
  if (pbVar22 != (byte *)0x0) {
    bVar5 = *pbVar22;
    puVar29 = local_34;
    while (bVar5 != 0) {
      puVar29 = (uint *)((int)puVar29 * 0x21 + (uint)bVar5);
      pbVar1 = pbVar22 + 1;
      pbVar22 = pbVar22 + 1;
      bVar5 = *pbVar1;
    }
    iVar20 = Texture_FindByHash(puVar29,0,0);
    if (iVar20 != 0) {
      local_34 = puVar29;
    }
  }
  iVar20 = Texture_FindByHash(local_34,0,0);
  if (iVar20 != 0) {
    *(undefined1 *)(iVar20 + 0x54) = 0;
  }
  if (local_34 != (uint *)param_1[0x1d0]) {
    param_1[0x1d0] = (int)local_34;
    param_1[0x1d1] = -1;
  }
  FUN_0056ca60(param_1);
  CarRenderInfo__UpdateDecalTextures(param_1,param_2);
  if (param_1[0x1dc] != -0x5dbb2b77) {
    param_1[0x1dc] = -0x5dbb2b77;
    param_1[0x1dd] = -1;
  }
  param_1[4] = 0x7f7fffff;
  param_1[5] = 0x7f7fffff;
  param_1[6] = 0x7f7fffff;
  local_30 = (uint *)(param_2 + 0x44c);
  param_1[8] = -0x800001;
  param_1[9] = -0x800001;
  param_1[10] = -0x800001;
  local_24 = param_1 + 0x39e;
  local_28 = (int *)0x0;
  do {
    uVar14 = *local_30;
    if (uVar14 != 0) {
      local_84 = *(uint *)(uVar14 + 0x24);
      local_34 = (uint *)(uVar14 + 0x20);
      piVar17 = local_24 + -2;
      local_3c = 4;
      do {
        local_a4 = *local_34;
        if (local_a4 != 0) {
          piVar17[1] = local_a4;
          piVar17[3] = 0;
          piVar17[4] = 0;
          piVar18 = piVar17 + -1;
          *DAT_00743c74 = (int)piVar18;
          piVar26 = piVar18;
          *piVar17 = (int)DAT_00743c74;
          DAT_00743c74 = piVar26;
          *piVar18 = (int)&DAT_00743c70;
          if (((piVar17[1] != 0) && (iVar20 = Solid_FindInAllLists(), piVar17[1] != 0)) &&
             (iVar20 != piVar17[2])) {
            iVar16 = *piVar18;
            piVar26 = (int *)*piVar17;
            *piVar26 = iVar16;
            *(int **)(iVar16 + 4) = piVar26;
            if (iVar20 == 0) {
              *DAT_00743c74 = (int)piVar18;
              piVar26 = piVar18;
              *piVar17 = (int)DAT_00743c74;
              DAT_00743c74 = piVar26;
              *piVar18 = (int)&DAT_00743c70;
            }
            else {
              puVar19 = *(undefined4 **)(iVar20 + 0x8c);
              *puVar19 = piVar18;
              *(int **)(iVar20 + 0x8c) = piVar18;
              *piVar17 = (int)puVar19;
              *piVar18 = iVar20 + 0x88;
            }
            piVar17[2] = iVar20;
          }
          if (piVar17[2] == 0) {
            if (piVar17[1] != 0) {
              iVar20 = *piVar18;
              piVar26 = (int *)*piVar17;
              *piVar26 = iVar20;
              *(int **)(iVar20 + 4) = piVar26;
            }
            piVar17[2] = 0;
            piVar17[1] = local_84;
            piVar17[3] = 0;
            piVar17[4] = 0;
            if (local_84 != 0) {
              *DAT_00743c74 = (int)piVar18;
              piVar26 = piVar18;
              *piVar17 = (int)DAT_00743c74;
              DAT_00743c74 = piVar26;
              *piVar18 = (int)&DAT_00743c70;
            }
            if (((piVar17[1] != 0) && (iVar20 = Solid_FindInAllLists(), piVar17[1] != 0)) &&
               (iVar20 != piVar17[2])) {
              iVar16 = *piVar18;
              piVar26 = (int *)*piVar17;
              *piVar26 = iVar16;
              *(int **)(iVar16 + 4) = piVar26;
              if (iVar20 == 0) {
                *DAT_00743c74 = (int)piVar18;
                piVar26 = piVar18;
                *piVar17 = (int)DAT_00743c74;
                DAT_00743c74 = piVar26;
                *piVar18 = (int)&DAT_00743c70;
              }
              else {
                puVar19 = *(undefined4 **)(iVar20 + 0x8c);
                *puVar19 = piVar18;
                *(int **)(iVar20 + 0x8c) = piVar18;
                *piVar17 = (int)puVar19;
                *piVar18 = iVar20 + 0x88;
              }
              piVar17[2] = iVar20;
            }
          }
          else {
            local_84 = local_a4;
          }
        }
        if (((int)local_28 < 0x13) || (0x1d < (int)local_28)) {
          piVar17[3] = (int)local_44;
          piVar17[4] = 0x3a;
        }
        else {
          iVar20 = (int)local_28 + -0x13;
          if (0x19 < (int)local_28) {
            iVar20 = (int)local_28 + -0x17;
          }
          piVar17[3] = (int)(param_1 + iVar20 * 0x20 + 0x2ab);
          piVar17[4] = 8;
        }
        local_34 = local_34 + 1;
        piVar17 = piVar17 + 6;
        local_3c = local_3c - 1;
      } while (local_3c != 0);
      if ((-1 < (int)local_28) && ((int)local_28 < 0xc)) {
        iVar20 = *local_24;
        if (iVar20 == 0) {
          local_80 = 0.0;
          local_7c = 0.0;
          local_78 = 0.0;
          local_60 = 0.0;
          local_5c = 0.0;
          local_58 = 0.0;
        }
        else {
          local_80 = *(float *)(iVar20 + 0x20);
          local_7c = *(float *)(iVar20 + 0x24);
          local_78 = *(float *)(iVar20 + 0x28);
          local_60 = *(float *)(iVar20 + 0x30);
          local_5c = *(float *)(iVar20 + 0x34);
          local_58 = *(float *)(iVar20 + 0x38);
        }
        FUN_00567890();
      }
    }
    piVar17 = local_38;
    local_28 = (int *)((int)local_28 + 1);
    local_30 = local_30 + 1;
    local_24 = local_24 + 0x18;
  } while ((int)local_28 < 0x1e);
  param_1[4] = (int)((float)param_1[4] - 0.1);
  param_1[5] = (int)((float)param_1[5] - 0.1);
  param_1[6] = (int)((float)param_1[6] - 0.1);
  param_1[8] = (int)((float)param_1[8] + 0.1);
  param_1[9] = (int)((float)param_1[9] + 0.1);
  param_1[10] = (int)((float)param_1[10] + 0.1);
  if (DAT_0077a920 == 3) {
    FUN_00565da0("%s_SHADOWFE",local_38);
    iVar20 = -1;
    pbVar22 = &local_170;
    bVar5 = local_170;
    while (bVar5 != 0) {
      pbVar1 = pbVar22 + 1;
      iVar20 = iVar20 * 0x21 + (uint)bVar5;
      pbVar22 = pbVar22 + 1;
      bVar5 = *pbVar1;
    }
  }
  else {
    FUN_00565da0("%s_SHADOWIG",local_38);
    iVar20 = -1;
    pbVar22 = &local_170;
    bVar5 = local_170;
    while (bVar5 != 0) {
      pbVar1 = pbVar22 + 1;
      iVar20 = iVar20 * 0x21 + (uint)bVar5;
      pbVar22 = pbVar22 + 1;
      bVar5 = *pbVar1;
    }
  }
  iVar20 = Texture_FindByHash(iVar20,0,0);
  param_1[0x12d] = iVar20;
  FUN_00565da0("%s_NEON",piVar17);
  iVar20 = -1;
  pbVar22 = &local_170;
  while (local_170 != 0) {
    pbVar1 = pbVar22 + 1;
    iVar20 = iVar20 * 0x21 + (uint)local_170;
    pbVar22 = pbVar22 + 1;
    local_170 = *pbVar1;
  }
  iVar20 = Texture_FindByHash(iVar20,1,0);
  param_1[0x12f] = iVar20;
  iVar20 = *(int *)(param_1[1] + 0x61c);
  sVar13 = 0;
  if (iVar20 == 0) {
    *(undefined2 *)(param_1 + 0x130) = 0;
    *(undefined2 *)((int)param_1 + 0x4c2) = 0;
    *(undefined2 *)(param_1 + 0x131) = 0;
    *(undefined2 *)((int)param_1 + 0x4c6) = 0;
    *(undefined2 *)(param_1 + 0x132) = 0;
    *(undefined2 *)((int)param_1 + 0x4ca) = 0;
    *(undefined2 *)(param_1 + 0x133) = 0;
  }
  else {
    puVar27 = &DAT_006c7a38;
    iVar16 = -1;
    uVar14 = 0x52;
    do {
      iVar16 = iVar16 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    local_28 = *(int **)(iVar20 + 0x14);
    local_30 = (uint *)(*(short *)(iVar20 + 0x1c) * 8);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar16 == 0) || (*piVar17 == iVar16)) {
          if (piVar17 != (int *)0x0) {
            local_a4 = piVar17[1];
            goto LAB_0056ad29;
          }
          break;
        }
      }
    }
    local_a4 = 0;
LAB_0056ad29:
    local_a4 = local_a4 & 0xff;
    pcVar24 = "GREEN";
    iVar20 = -1;
    uVar14 = 0x47;
    do {
      pbVar22 = (byte *)(pcVar24 + 1);
      iVar20 = iVar20 * 0x21 + uVar14;
      pcVar24 = pcVar24 + 1;
      uVar14 = (uint)*pbVar22;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            local_3c = piVar17[1];
            goto LAB_0056ad79;
          }
          break;
        }
      }
    }
    local_3c = 0;
LAB_0056ad79:
    local_3c = local_3c & 0xff;
    puVar27 = &DAT_006c7a28;
    iVar20 = -1;
    uVar14 = 0x42;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            uVar14 = piVar17[1];
            goto LAB_0056adc9;
          }
          break;
        }
      }
    }
    uVar14 = 0;
LAB_0056adc9:
    local_44 = (int *)(uVar14 & 0xff);
    pcVar24 = "ALPHA";
    iVar20 = -1;
    uVar14 = 0x41;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = (byte *)(pcVar24 + 1);
      uVar14 = (uint)*pbVar22;
      pcVar24 = pcVar24 + 1;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            local_84 = piVar17[1];
            goto LAB_0056ae19;
          }
          break;
        }
      }
    }
    local_84 = 0;
LAB_0056ae19:
    local_84 = local_84 & 0xff;
    puVar27 = &DAT_006bbcfc;
    iVar20 = -1;
    uVar14 = 0x52;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            uVar14 = piVar17[1];
            goto LAB_0056ae69;
          }
          break;
        }
      }
    }
    uVar14 = 0;
LAB_0056ae69:
    local_24 = (int *)(uVar14 & 0xff);
    puVar27 = &DAT_006bbcf4;
    iVar20 = -1;
    uVar14 = 0x47;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            uVar14 = piVar17[1];
            goto LAB_0056aeb9;
          }
          break;
        }
      }
    }
    uVar14 = 0;
LAB_0056aeb9:
    local_34 = (uint *)(uVar14 & 0xff);
    puVar27 = &DAT_006bbcec;
    iVar20 = -1;
    uVar14 = 0x42;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < (int *)((int)local_30 + (int)local_28); piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            uVar11 = (ushort)piVar17[1];
            goto LAB_0056af09;
          }
          break;
        }
      }
    }
    uVar11 = 0;
LAB_0056af09:
    puVar27 = &DAT_006bbce4;
    iVar20 = -1;
    uVar14 = 0x41;
    do {
      iVar20 = iVar20 * 0x21 + uVar14;
      pbVar22 = puVar27 + 1;
      uVar14 = (uint)*pbVar22;
      puVar27 = puVar27 + 1;
    } while (*pbVar22 != 0);
    local_38 = (int *)((int)local_30 + (int)local_28);
    piVar17 = local_28;
    if (local_28 != (int *)0x0) {
      for (; piVar17 < local_38; piVar17 = piVar17 + 2) {
        if ((iVar20 == 0) || (*piVar17 == iVar20)) {
          if (piVar17 != (int *)0x0) {
            uVar12 = (ushort)piVar17[1];
            goto LAB_0056af5c;
          }
          break;
        }
      }
    }
    uVar12 = 0;
LAB_0056af5c:
    *(short *)((int)param_1 + 0x4c2) = (short)local_3c;
    *(short *)(param_1 + 0x131) = (short)local_44;
    *(short *)((int)param_1 + 0x4c6) = (short)local_84;
    *(short *)(param_1 + 0x132) = (short)local_24 - (short)local_a4;
    *(short *)(param_1 + 0x130) = (short)local_a4;
    *(short *)((int)param_1 + 0x4ca) = (short)local_34 - (short)local_3c;
    *(ushort *)(param_1 + 0x133) = (uVar11 & 0xff) - (short)local_44;
    sVar13 = (uVar12 & 0xff) - (short)local_84;
  }
  *(short *)((int)param_1 + 0x4ce) = sVar13;
  iVar20 = Texture_FindByHash(0xbadb4475,0,0);
  param_1[0x12e] = iVar20;
  if (param_1[0x12d] != 0) {
    *(undefined1 *)(param_1[0x12d] + 0x54) = 0;
    *(undefined1 *)(param_1[0x12d] + 0x51) = 2;
  }
  if (param_1[0x12e] != 0) {
    *(undefined1 *)(param_1[0x12e] + 0x54) = 0;
    *(undefined1 *)(param_1[0x12e] + 0x51) = 3;
  }
  if (param_1[0x12f] != 0) {
    *(undefined1 *)(param_1[0x12f] + 0x54) = 0;
    *(undefined1 *)(param_1[0x12f] + 0x51) = 4;
  }
  if (*param_1 == 0) {
    iVar20 = 0;
  }
  else {
    iVar20 = *(int *)(*param_1 + 0x868);
  }
  if (iVar20 != 0) {
    iVar16 = param_1[9];
    iVar25 = param_1[8];
    iVar6 = param_1[4];
    *(int *)(iVar20 + 0x5c) = param_1[5];
    *(int *)(iVar20 + 0x58) = iVar6;
    local_38 = (int *)0x1e;
    *(int *)(iVar20 + 0x60) = iVar25;
    *(int *)(iVar20 + 100) = iVar16;
    piVar17 = local_a8;
    do {
      FUN_0058d800(iVar20,piVar17);
      piVar17 = piVar17 + 0x18;
      local_38 = (int *)((int)local_38 + -1);
    } while (local_38 != (int *)0x0);
    local_38 = (int *)0x0;
  }
  if (param_1[0x416] == 0) {
    piVar17 = (int *)0x0;
  }
  else {
    piVar17 = (int *)(param_1[0x416] + 0x70);
    if (piVar17 != (int *)0x0) {
      iVar20 = *piVar17;
      goto LAB_0056b145;
    }
  }
  iVar20 = 0;
LAB_0056b145:
  param_1[0xc] = iVar20;
  if (piVar17 == (int *)0x0) {
    iVar20 = 0;
  }
  else {
    iVar20 = piVar17[1];
  }
  param_1[0xd] = iVar20;
  if (piVar17 == (int *)0x0) {
    iVar20 = 0;
  }
  else {
    iVar20 = piVar17[2];
  }
  param_1[0xe] = iVar20;
  FUN_0056cc40(param_1);
  if (*(char *)(param_2 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  pfVar2 = (float *)(param_2 + 0x70);
  FUN_005693d0(pfVar2);
  pfVar28 = (float *)(param_2 + 0xa0);
  FUN_005693d0(pfVar28);
  FUN_005693d0(param_2 + 0xd0);
  FUN_005693d0(param_2 + 0x100);
  local_80 = (*(float *)(param_2 + 0x100) + *pfVar2) * _K_HALF;
  local_7c = (*(float *)(param_2 + 0x104) + *(float *)(param_2 + 0x74)) * _K_HALF;
  local_78 = (*(float *)(param_2 + 0x108) + *(float *)(param_2 + 0x78)) * _K_HALF;
  FUN_005693d0(&local_80);
  local_60 = (*(float *)(param_2 + 0xd0) + *pfVar28) * _K_HALF;
  local_5c = (*(float *)(param_2 + 0xd4) + *(float *)(param_2 + 0xa4)) * _K_HALF;
  local_58 = (*(float *)(param_2 + 0xd8) + *(float *)(param_2 + 0xa8)) * _K_HALF;
  FUN_005693d0(&local_60);
  FUN_005693d0(pfVar2);
  FUN_005693d0(pfVar28);
  FUN_005693d0(param_2 + 0xd0);
  FUN_005693d0(param_2 + 0x100);
  FUN_005693d0(pfVar2);
  FUN_005693d0(param_2 + 0xd0);
  local_a0 = (local_60 + local_80) * _K_HALF;
  local_9c = (local_5c + local_7c) * _K_HALF;
  local_98 = (local_58 + local_78) * _K_HALF;
  FUN_005693d0(&local_a0);
  fVar9 = *(float *)(param_2 + 0x74) - *(float *)(param_2 + 0xa4);
  fVar4 = *(float *)(param_2 + 0x78) - *(float *)(param_2 + 0xa8);
  local_60 = *pfVar28 - *(float *)(param_2 + 0xd0);
  local_5c = *(float *)(param_2 + 0xa4) - *(float *)(param_2 + 0xd4);
  fVar8 = *(float *)(param_2 + 0xa8) - *(float *)(param_2 + 0xd8);
  fVar3 = fVar8 * fVar9 - local_5c * fVar4;
  local_6c = fVar4 * local_60 - fVar8 * (*pfVar2 - *pfVar28);
  local_68 = local_5c * (*pfVar2 - *pfVar28) - fVar9 * local_60;
  fVar4 = SQRT(fVar3 * fVar3 + local_6c * local_6c + local_68 * local_68);
  if (fVar4 == 0.0) {
    local_68 = 0.0;
    fVar8 = 0.0;
    local_70 = _K_ONE;
  }
  else {
    fVar4 = _K_ONE / fVar4;
    fVar8 = local_6c * fVar4;
    local_68 = local_68 * fVar4;
    local_70 = fVar3 * fVar4;
  }
  local_24 = *(int **)(param_2 + 0x80);
  local_70 = (float)local_24 * local_70;
  local_a0 = local_70 + local_a0;
  local_9c = fVar8 * (float)local_24 + local_9c;
  local_98 = local_68 * (float)local_24 + local_98;
  FUN_005693d0(&local_a0);
  iVar20 = 0;
  local_24 = local_ac;
  do {
    iVar16 = 0;
    piVar17 = local_24;
    do {
      switch(iVar16) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
        if ((iVar20 == 0) || ((0 < iVar20 && (*piVar17 != piVar17[6])))) {
          aiStack_130[iVar16] = (int)(piVar17 + 4);
        }
        break;
      default:
        aiStack_130[iVar16] = 0;
      }
      iVar16 = iVar16 + 1;
      piVar17 = piVar17 + 0x18;
    } while (iVar16 < 0x1e);
    iVar25 = 0;
    iVar16 = 0;
    do {
      if (((aiStack_130[iVar16] != 0) && (iVar6 = *(int *)(aiStack_130[iVar16] + 0xc), iVar6 != 0))
         && (*(int *)(iVar6 + 0x84) != 0)) {
        local_570[iVar25] = iVar6;
        iVar25 = iVar25 + 1;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < 0x1e);
    FUN_0053fd70(local_570,iVar25);
    iVar20 = iVar20 + 1;
    piVar17 = (int *)0x0;
    local_24 = local_24 + 6;
  } while (iVar20 < 4);
  iVar20 = *(int *)(param_2 + 0x4c4);
  local_38 = (int *)0x0;
  if (iVar20 != 0) {
    piVar26 = *(int **)(iVar20 + 0x14);
    piVar18 = piVar26 + *(short *)(iVar20 + 0x1c) * 2;
    if (piVar26 != (int *)0x0) {
      for (; piVar26 < piVar18; piVar26 = piVar26 + 2) {
        if (*piVar26 == 0x6ba02c05) {
          if (piVar26 != (int *)0x0) {
            local_38 = (int *)piVar26[1];
            goto LAB_0056b528;
          }
          break;
        }
      }
    }
    local_38 = (int *)0x0;
  }
LAB_0056b528:
  if (DAT_00743c18 != 0) {
    piVar17 = (int *)(DAT_00743c18 + -4);
  }
  local_28 = (int *)Ptr_BaseAdjustMinus4();
  while ((piVar18 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
         (piVar18 = piVar17, (int *)piVar17[3] != local_38))) {
    if (piVar17[1] == 0) {
      piVar17 = (int *)0x0;
    }
    else {
      piVar17 = (int *)(piVar17[1] + -4);
    }
  }
  param_1[0x134] = (int)piVar18;
  iVar20 = *(int *)(param_2 + 0x618);
  iVar16 = 0x471a1dca;
  if (iVar20 != 0) {
    piVar18 = *(int **)(iVar20 + 0x14);
    piVar17 = piVar18 + *(short *)(iVar20 + 0x1c) * 2;
    if (piVar18 != (int *)0x0) {
      for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
        if (*piVar18 == 0x6ba02c05) {
          if (piVar18 != (int *)0x0) {
            iVar16 = piVar18[1];
            goto LAB_0056b5ab;
          }
          break;
        }
      }
    }
    iVar16 = 0;
  }
LAB_0056b5ab:
  if (DAT_00743c18 == 0) {
    piVar17 = (int *)0x0;
  }
  else {
    piVar17 = (int *)(DAT_00743c18 + -4);
  }
  while ((piVar18 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
         (piVar18 = piVar17, piVar17[3] != iVar16))) {
    if (piVar17[1] == 0) {
      piVar17 = (int *)0x0;
    }
    else {
      piVar17 = (int *)(piVar17[1] + -4);
    }
  }
  param_1[0x135] = (int)piVar18;
  local_ac = *(int **)(param_2 + 0x4e8);
  local_24 = *(int **)(param_2 + 0x4ec);
  local_a8 = *(int **)(param_2 + 0x4e4);
  iVar20 = *(int *)(param_2 + 0x4f0);
  if ((*(int *)(param_2 + 0x490) == 0) || (*(char *)(*(int *)(param_2 + 0x490) + 0x11) == '\0')) {
    iVar20 = 0;
  }
  if ((*(int *)(param_2 + 0x488) == 0) || (*(char *)(*(int *)(param_2 + 0x488) + 0x11) == '\0')) {
    local_24 = (int *)0x0;
  }
  if ((*(int *)(param_2 + 0x48c) == 0) ||
     (iVar16 = (int)local_ac, *(char *)(*(int *)(param_2 + 0x48c) + 0x11) == '\0')) {
    iVar16 = 0;
  }
  if ((*(int *)(param_2 + 0x478) == 0) ||
     (iVar25 = (int)local_a8, *(char *)(*(int *)(param_2 + 0x478) + 0x11) == '\0')) {
    iVar25 = 0;
  }
  local_34 = (uint *)0x0;
  local_38 = (int *)0x0;
  local_3c = 0;
  local_44 = (int *)0x0;
  if (iVar20 != 0) {
    piVar18 = *(int **)(iVar20 + 0x14);
    piVar17 = piVar18 + *(short *)(iVar20 + 0x1c) * 2;
    if (piVar18 != (int *)0x0) {
      for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
        if (*piVar18 == 0x6ba02c05) {
          if (piVar18 != (int *)0x0) {
            local_34 = (uint *)piVar18[1];
            goto LAB_0056b6cb;
          }
          break;
        }
      }
    }
    local_34 = (uint *)0x0;
  }
LAB_0056b6cb:
  if (local_24 != (int *)0x0) {
    piVar18 = *(int **)((int)local_24 + 0x14);
    piVar17 = piVar18 + *(short *)((int)local_24 + 0x1c) * 2;
    if (piVar18 != (int *)0x0) {
      for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
        if (*piVar18 == 0x6ba02c05) {
          if (piVar18 != (int *)0x0) {
            local_38 = (int *)piVar18[1];
            goto LAB_0056b6f9;
          }
          break;
        }
      }
    }
    local_38 = (int *)0x0;
  }
LAB_0056b6f9:
  if (iVar16 != 0) {
    piVar18 = *(int **)(iVar16 + 0x14);
    piVar17 = piVar18 + *(short *)(iVar16 + 0x1c) * 2;
    if (piVar18 != (int *)0x0) {
      for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
        if (*piVar18 == 0x6ba02c05) {
          if (piVar18 != (int *)0x0) {
            local_3c = piVar18[1];
            goto LAB_0056b724;
          }
          break;
        }
      }
    }
    local_3c = 0;
  }
LAB_0056b724:
  if (iVar25 != 0) {
    piVar18 = *(int **)(iVar25 + 0x14);
    piVar17 = piVar18 + *(short *)(iVar25 + 0x1c) * 2;
    if (piVar18 != (int *)0x0) {
      for (; piVar18 < piVar17; piVar18 = piVar18 + 2) {
        if (*piVar18 == 0x6ba02c05) {
          if (piVar18 != (int *)0x0) {
            local_44 = (int *)piVar18[1];
            goto LAB_0056b754;
          }
          break;
        }
      }
    }
    local_44 = (int *)0x0;
  }
LAB_0056b754:
  local_24 = (int *)0x0;
  if (local_34 != (uint *)0x0) {
    piVar17 = local_24;
    if (DAT_00743c18 != 0) {
      piVar17 = (int *)(DAT_00743c18 + -4);
    }
    while ((local_24 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
           (local_24 = piVar17, (uint *)piVar17[3] != local_34))) {
      if (piVar17[1] == 0) {
        piVar17 = (int *)0x0;
      }
      else {
        piVar17 = (int *)(piVar17[1] + -4);
      }
    }
  }
  if (local_38 == (int *)0x0) {
    piVar18 = (int *)0x0;
  }
  else {
    if (DAT_00743c18 == 0) {
      piVar17 = (int *)0x0;
    }
    else {
      piVar17 = (int *)(DAT_00743c18 + -4);
    }
    while ((piVar18 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
           (piVar18 = piVar17, (int *)piVar17[3] != local_38))) {
      if (piVar17[1] == 0) {
        piVar17 = (int *)0x0;
      }
      else {
        piVar17 = (int *)(piVar17[1] + -4);
      }
    }
  }
  if (local_3c == 0) {
    piVar26 = (int *)0x0;
  }
  else {
    if (DAT_00743c18 == 0) {
      piVar17 = (int *)0x0;
    }
    else {
      piVar17 = (int *)(DAT_00743c18 + -4);
    }
    while ((piVar26 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
           (piVar26 = piVar17, piVar17[3] != local_3c))) {
      if (piVar17[1] == 0) {
        piVar17 = (int *)0x0;
      }
      else {
        piVar17 = (int *)(piVar17[1] + -4);
      }
    }
  }
  if (local_44 == (int *)0x0) {
    piVar23 = (int *)0x0;
  }
  else {
    if (DAT_00743c18 == 0) {
      piVar17 = (int *)0x0;
    }
    else {
      piVar17 = (int *)(DAT_00743c18 + -4);
    }
    while ((piVar23 = (int *)PTR_DAT_006f3df0, piVar17 != local_28 &&
           (piVar23 = piVar17, (int *)piVar17[3] != local_44))) {
      if (piVar17[1] == 0) {
        piVar17 = (int *)0x0;
      }
      else {
        piVar17 = (int *)(piVar17[1] + -4);
      }
    }
  }
  param_1[0x136] = (int)local_24;
  param_1[0x137] = (int)piVar18;
  param_1[0x138] = (int)piVar26;
  param_1[0x139] = (int)piVar23;
  FUN_0056c250();
  piVar17 = DAT_00734610;
  iVar20 = 0;
  iVar16 = *(int *)(extraout_EDX + 0x14d8);
  piVar18 = (int *)0x0;
  while (iVar16 != 0) {
    piVar26 = *(int **)(iVar16 + 0x80);
    if ((piVar26 == (int *)0x0) || (*(char *)(iVar16 + 0x1b) == 0)) {
LAB_0056b8f2:
      piVar26 = (int *)0x0;
    }
    else if (piVar18 != (int *)0x0) {
      if ((piVar18 < piVar26) || (piVar26 + (*(char *)(iVar16 + 0x1b) * 5 + -5) * 4 <= piVar18))
      goto LAB_0056b8f2;
      piVar26 = piVar18 + 0x14;
    }
    if (piVar26 == (int *)0x0) break;
    piVar18 = piVar26;
    if (*piVar26 == -0x157204fb) {
      iVar20 = piVar26[0x11];
    }
  }
  *(int *)(extraout_EDX + 0x540) = iVar20;
  local_2c = piVar17 + 4;
  piVar18 = piVar17;
  if ((piVar17[4] == 0) && ((*(byte *)(piVar17 + 5) & 1) != 0)) {
    FUN_00566e60();
    piVar18 = DAT_00734610;
  }
  piVar26 = (int *)*local_2c;
  iVar20 = piVar17[6] + 1;
  if (piVar26 == (int *)0x0) {
    piVar26 = (int *)0x0;
  }
  else {
    iVar16 = *piVar26;
    if (piVar17[7] < iVar20) {
      piVar17[7] = iVar20;
    }
    piVar17[6] = iVar20;
    bVar5 = *(byte *)(piVar17 + 5);
    *local_2c = iVar16;
    if (((bVar5 & 2) != 0) && (iVar20 = piVar17[10] >> 2, piVar17 = piVar26, 0 < iVar20)) {
      for (; iVar20 != 0; iVar20 = iVar20 + -1) {
        *piVar17 = 0;
        piVar17 = piVar17 + 1;
      }
    }
    piVar18 = DAT_00734610;
    piVar26[4] = 0;
    piVar26[1] = 0;
    piVar26[2] = 0;
    piVar26[3] = 0;
  }
  puVar19 = (undefined4 *)local_40[1];
  local_40[1] = (int)piVar26;
  *puVar19 = piVar26;
  *piVar26 = (int)local_40;
  if (*param_1 != 0) {
    piVar17 = *(int **)(*param_1 + 0x20);
    local_2c = piVar18 + 4;
    local_40 = piVar18;
    local_24 = piVar17;
    if ((piVar18[4] == 0) && ((*(byte *)(piVar18 + 5) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar18 = (int *)*local_2c;
    iVar20 = local_40[6] + 1;
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      iVar16 = *piVar18;
      if (local_40[7] < iVar20) {
        local_40[7] = iVar20;
      }
      local_40[6] = iVar20;
      *local_2c = iVar16;
      if (((*(byte *)(local_40 + 5) & 2) != 0) &&
         (iVar20 = local_40[10] >> 2, piVar26 = piVar18, 0 < iVar20)) {
        for (; piVar17 = local_24, iVar20 != 0; iVar20 = iVar20 + -1) {
          *piVar26 = 0;
          piVar26 = piVar26 + 1;
        }
      }
      fVar8 = ((float)piVar17[0x12] + (float)piVar17[6]) * _K_HALF;
      fVar9 = ((float)piVar17[0x11] + (float)piVar17[5]) * _K_HALF;
      fVar3 = (float)piVar17[4];
      fVar4 = (float)piVar17[0x10];
      piVar18[4] = 0;
      piVar18[1] = (int)((fVar3 + fVar4) * _K_HALF);
      piVar18[2] = (int)fVar9;
      piVar18[3] = (int)fVar8;
    }
    puVar19 = (undefined4 *)param_1[0x18e];
    param_1[0x18e] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x18d);
    piVar18 = DAT_00734610;
    local_2c = DAT_00734610 + 4;
    local_40 = DAT_00734610;
    if ((DAT_00734610[4] == 0) && ((*(byte *)(DAT_00734610 + 5) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar26 = (int *)*local_2c;
    iVar20 = piVar18[6] + 1;
    if (piVar26 == (int *)0x0) {
      piVar26 = (int *)0x0;
    }
    else {
      iVar16 = *piVar26;
      if (piVar18[7] < iVar20) {
        piVar18[7] = iVar20;
      }
      piVar18[6] = iVar20;
      *local_2c = iVar16;
      if (((*(byte *)(piVar18 + 5) & 2) != 0) &&
         (iVar20 = piVar18[10] >> 2, piVar18 = piVar26, 0 < iVar20)) {
        for (; piVar17 = local_24, iVar20 != 0; iVar20 = iVar20 + -1) {
          *piVar18 = 0;
          piVar18 = piVar18 + 1;
        }
      }
      fVar8 = ((float)piVar17[0x2a] + (float)piVar17[0x1e]) * _K_HALF;
      fVar9 = ((float)piVar17[0x29] + (float)piVar17[0x1d]) * _K_HALF;
      fVar3 = (float)piVar17[0x28];
      fVar4 = (float)piVar17[0x1c];
      piVar26[4] = 0;
      piVar26[1] = (int)((fVar3 + fVar4) * _K_HALF);
      piVar26[2] = (int)fVar9;
      piVar26[3] = (int)fVar8;
    }
    puVar19 = (undefined4 *)param_1[400];
    param_1[400] = (int)piVar26;
    *puVar19 = piVar26;
    *piVar26 = (int)(param_1 + 399);
    piVar18 = DAT_00734610;
    local_2c = DAT_00734610 + 4;
    local_40 = DAT_00734610;
    if ((DAT_00734610[4] == 0) && ((*(byte *)(DAT_00734610 + 5) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar26 = (int *)*local_2c;
    iVar20 = piVar18[6] + 1;
    if (piVar26 == (int *)0x0) {
      piVar26 = (int *)0x0;
    }
    else {
      iVar16 = *piVar26;
      if (piVar18[7] < iVar20) {
        piVar18[7] = iVar20;
      }
      piVar18[6] = iVar20;
      *local_2c = iVar16;
      if (((*(byte *)(piVar18 + 5) & 2) != 0) &&
         (iVar20 = piVar18[10] >> 2, piVar18 = piVar26, 0 < iVar20)) {
        for (; piVar17 = local_24, iVar20 != 0; iVar20 = iVar20 + -1) {
          *piVar18 = 0;
          piVar18 = piVar18 + 1;
        }
      }
      fVar8 = ((float)piVar17[0x2a] + (float)piVar17[6]) * _K_HALF;
      fVar9 = ((float)piVar17[0x29] + (float)piVar17[5]) * _K_HALF;
      fVar3 = (float)piVar17[4];
      fVar4 = (float)piVar17[0x28];
      piVar26[4] = 0;
      piVar26[1] = (int)((fVar3 + fVar4) * _K_HALF);
      piVar26[2] = (int)fVar9;
      piVar26[3] = (int)fVar8;
    }
    puVar19 = (undefined4 *)param_1[0x192];
    param_1[0x192] = (int)piVar26;
    *puVar19 = piVar26;
    *piVar26 = (int)(param_1 + 0x191);
    piVar18 = (int *)FUN_00567160();
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      fVar8 = ((float)piVar17[0x1e] + (float)piVar17[0x12]) * _K_HALF;
      fVar9 = ((float)piVar17[0x1d] + (float)piVar17[0x11]) * _K_HALF;
      fVar3 = (float)piVar17[0x1c];
      fVar4 = (float)piVar17[0x10];
      piVar18[4] = 0;
      piVar18[1] = (int)((fVar3 + fVar4) * _K_HALF);
      piVar18[2] = (int)fVar9;
      piVar18[3] = (int)fVar8;
    }
    puVar19 = (undefined4 *)param_1[0x194];
    param_1[0x194] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x193);
    piVar18 = (int *)FUN_00567160();
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      iVar20 = piVar17[6];
      iVar16 = piVar17[5];
      iVar25 = piVar17[4];
      piVar18[4] = 0;
      piVar18[1] = iVar25;
      piVar18[2] = iVar16;
      piVar18[3] = iVar20;
    }
    puVar19 = (undefined4 *)param_1[0x196];
    param_1[0x196] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x195);
    piVar18 = (int *)FUN_00567160();
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      iVar20 = piVar17[0x12];
      iVar16 = piVar17[0x11];
      iVar25 = piVar17[0x10];
      piVar18[4] = 0;
      piVar18[1] = iVar25;
      piVar18[2] = iVar16;
      piVar18[3] = iVar20;
    }
    puVar19 = (undefined4 *)param_1[0x198];
    param_1[0x198] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x197);
    piVar18 = (int *)FUN_00567160();
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      iVar20 = piVar17[0x1e];
      iVar16 = piVar17[0x1d];
      iVar25 = piVar17[0x1c];
      piVar18[4] = 0;
      piVar18[1] = iVar25;
      piVar18[2] = iVar16;
      piVar18[3] = iVar20;
    }
    puVar19 = (undefined4 *)param_1[0x19a];
    param_1[0x19a] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x199);
    piVar18 = (int *)FUN_00567160();
    if (piVar18 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      iVar20 = piVar17[0x2a];
      iVar16 = piVar17[0x29];
      iVar25 = piVar17[0x28];
      piVar18[4] = 0;
      piVar18[1] = iVar25;
      piVar18[2] = iVar16;
      piVar18[3] = iVar20;
    }
    puVar19 = (undefined4 *)param_1[0x19c];
    param_1[0x19c] = (int)piVar18;
    *puVar19 = piVar18;
    *piVar18 = (int)(param_1 + 0x19b);
  }
  local_2c = (int *)0x0;
  do {
    if (*(char *)((int)local_2c + 0x6a4 + param_1[1]) != '\0') {
      local_40 = param_1 + (int)local_2c * 0x18 + 0x39b;
      iVar20 = local_40[3];
      if (iVar20 != 0) {
        local_30 = *(uint **)(iVar20 + 0x80);
        if ((local_30 == (uint *)0x0) || (*(char *)(iVar20 + 0x1b) == '\0')) {
          local_30 = (uint *)0x0;
        }
        while (local_30 != (uint *)0x0) {
          uVar14 = *local_30;
          local_28 = (int *)0x0;
          if (uVar14 < 0x9db90134) {
            if (uVar14 == 0x9db90133) {
LAB_0056bf45:
              local_28 = param_1 + 0x1b3;
              piVar17 = param_1 + 0x1af;
            }
            else if (uVar14 < 0x494ed281) {
              if (uVar14 != 0x494ed280) {
                if (uVar14 < 0x1b0763a1) {
                  if (uVar14 == 0x1b0763a0) {
LAB_0056be62:
                    piVar17 = param_1 + 0x1a5;
                    goto LAB_0056c015;
                  }
                  if (uVar14 < 0xab88f5e) {
                    if (uVar14 == 0xab88f5d) {
LAB_0056be4c:
                      piVar17 = param_1 + 0x1ad;
                      goto LAB_0056c015;
                    }
                    if (uVar14 == 0x2b52399) goto LAB_0056bf85;
                    if (uVar14 == 0x5f63788) goto LAB_0056be07;
                  }
                  else if (uVar14 == 0xbea251b) goto LAB_0056be1d;
                }
                else if (uVar14 < 0x3df28f6a) {
                  if (uVar14 == 0x3df28f69) goto LAB_0056c00f;
                  if (uVar14 == 0x2f96d0fd) goto LAB_0056be4c;
                  if (uVar14 == 0x31a66786) goto LAB_0056bfd5;
                }
                else if (uVar14 == 0x3f68f920) goto LAB_0056be62;
                goto LAB_0056c091;
              }
LAB_0056bfc2:
              piVar17 = param_1 + 0x1c1;
            }
            else if (uVar14 < 0x68100816) {
              if (uVar14 != 0x68100815) {
                if (uVar14 < 0x60f8b13d) {
                  if (uVar14 == 0x60f8b13c) {
LAB_0056beab:
                    piVar17 = param_1 + 0x1ab;
                    goto LAB_0056c015;
                  }
                  if (uVar14 == 0x4cdebfca) goto LAB_0056c007;
                  if (uVar14 == 0x59a55db5) {
                    piVar17 = param_1 + 0x19d;
                    goto LAB_0056c015;
                  }
                }
                else if (uVar14 == 0x64b0bb1c) goto LAB_0056beab;
                goto LAB_0056c091;
              }
              piVar17 = param_1 + 0x1a1;
            }
            else {
              if (uVar14 != 0x6ec7e79f) {
                if (uVar14 == 0x725758bf) goto LAB_0056bf59;
                if (uVar14 != 0x7b220ddf) goto LAB_0056c091;
              }
              piVar17 = param_1 + 0x1a3;
            }
LAB_0056c015:
            if (piVar17 != (int *)0x0) {
              puVar19 = (undefined4 *)FUN_00567160();
              if (puVar19 == (undefined4 *)0x0) {
                puVar19 = (undefined4 *)0x0;
              }
              else {
                puVar19[4] = local_30;
                puVar19[1] = local_30[0x10];
                puVar19[2] = local_30[0x11];
                puVar19[3] = local_30[0x12];
              }
              puVar7 = (undefined4 *)piVar17[1];
              piVar17[1] = (int)puVar19;
              *puVar7 = puVar19;
              *puVar19 = piVar17;
            }
            if (local_28 != (int *)0x0) {
              puVar19 = (undefined4 *)FUN_00567160();
              if (puVar19 == (undefined4 *)0x0) {
                puVar19 = (undefined4 *)0x0;
              }
              else {
                puVar19[4] = local_30;
                puVar19[1] = local_30[0x10];
                puVar19[2] = local_30[0x11];
                puVar19[3] = local_30[0x12];
              }
              puVar7 = (undefined4 *)local_28[1];
              local_28[1] = (int)puVar19;
              *puVar7 = puVar19;
              *puVar19 = local_28;
            }
          }
          else {
            if (0xc4ec23c8 < uVar14) {
              if (uVar14 < 0xdf066a42) {
                if (uVar14 == 0xdf066a41) {
LAB_0056bfff:
                  piVar17 = param_1 + 0x19f;
                }
                else if (uVar14 < 0xd09091c7) {
                  if (uVar14 == 0xd09091c6) {
LAB_0056bf26:
                    local_28 = param_1 + 0x1b5;
                    piVar17 = param_1 + 0x1af;
                  }
                  else {
                    if (uVar14 != 0xc52bf01b) {
                      if (uVar14 == 0xc805f7e0) goto LAB_0056bfc2;
                      goto LAB_0056c091;
                    }
LAB_0056be1d:
                    piVar17 = param_1 + 0x1bd;
                  }
                }
                else {
                  if (uVar14 != 0xd947f346) goto LAB_0056c091;
LAB_0056bfd5:
                  local_28 = param_1 + 0x1b7;
                  piVar17 = param_1 + 0x1b1;
                }
              }
              else if (uVar14 == 0xe7e4ef49) {
LAB_0056c00f:
                piVar17 = param_1 + 0x1a7;
              }
              else {
                if (uVar14 != 0xe898cfaa) {
                  if (uVar14 != 0xf21be91e) goto LAB_0056c091;
                  goto LAB_0056bfff;
                }
LAB_0056c007:
                piVar17 = param_1 + 0x1a9;
              }
              goto LAB_0056c015;
            }
            if (uVar14 == 0xc4ec23c8) {
LAB_0056be07:
              piVar17 = param_1 + 0x1bb;
              goto LAB_0056c015;
            }
            if (uVar14 < 0xaa35c180) {
              if (uVar14 == 0xaa35c17f) {
LAB_0056bf59:
                piVar17 = param_1 + 0x1bf;
                goto LAB_0056c015;
              }
              if (uVar14 < 0xa5b28002) {
                if ((uVar14 == 0xa5b28001) || (uVar14 == 0xa2799c2b)) goto LAB_0056bfff;
                if (uVar14 == 0xa532fc46) goto LAB_0056bf26;
              }
              else if (uVar14 == 0xa7e6ea53) goto LAB_0056bf45;
            }
            else {
              if ((uVar14 == 0xbcf8a18b) || (uVar14 == 0xbd7cf15e)) goto LAB_0056bfff;
              if (uVar14 == 0xbf700a79) {
LAB_0056bf85:
                local_28 = param_1 + 0x1b9;
                piVar17 = param_1 + 0x1b1;
                goto LAB_0056c015;
              }
            }
          }
LAB_0056c091:
          iVar20 = local_40[3];
          if (iVar20 == 0) break;
          puVar29 = *(uint **)(iVar20 + 0x80);
          if ((((puVar29 == (uint *)0x0) || (*(char *)(iVar20 + 0x1b) == 0)) || (local_30 < puVar29)
              ) || (puVar29 + (*(char *)(iVar20 + 0x1b) * 5 + -5) * 4 <= local_30)) {
            local_30 = (uint *)0x0;
          }
          else {
            local_30 = local_30 + 0x14;
          }
        }
      }
    }
    local_2c = (int *)((int)local_2c + 1);
    if (0x1d < (int)local_2c) {
      puVar19 = &DAT_006f1bcc;
      do {
        FUN_00402ad0(*puVar19);
        puVar19 = puVar19 + 2;
      } while ((int)puVar19 < 0x6f1cb4);
      ExceptionList = local_1c;
      return param_1;
    }
  } while( true );
}


// ==== 0x56c140 FUN_0056c140

void FUN_0056c140(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_006856fb;
  local_c = ExceptionList;
  local_4 = 5;
  ExceptionList = &local_c;
  eh_vector_destructor_iterator((void *)(param_1 + 0x1ac0),0xa0,2,NullUpdate_ret);
  local_4 = CONCAT31(local_4._1_3_,4);
  eh_vector_destructor_iterator((void *)(param_1 + 0x19e0),0x68,2,NullUpdate_ret);
  piVar1 = *(int **)(param_1 + 0x19d8);
  while (piVar1 != (int *)(param_1 + 0x19d8)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = *(int **)(param_1 + 0x19d8);
  }
  local_4._1_3_ = (uint3)((uint)local_4 >> 8);
  local_4._0_1_ = 2;
  eh_vector_destructor_iterator((void *)(param_1 + 0xe6c),0x18,0x78,ListRef_Release);
  local_4._0_1_ = 1;
  eh_vector_destructor_iterator((void *)(param_1 + 0x62c),8,0x1c,FUN_00571560);
  local_4 = (uint)local_4._1_3_ << 8;
  eh_vector_destructor_iterator((void *)(param_1 + 0x544),8,0x1d,List_DeleteAllNodes);
  piVar1 = *(int **)(param_1 + 0x500);
  while (piVar1 != (int *)(param_1 + 0x500)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = *(int **)(param_1 + 0x500);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x56c250 FUN_0056c250

void __fastcall FUN_0056c250(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)(param_2 + 0x510);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return;
  }
  *(float *)(param_2 + 0x510) = -*(float *)(iVar1 + 0x13c);
  *(float *)(param_2 + 0x514) = -*(float *)(iVar1 + 0x140);
  *(undefined4 *)(param_2 + 0x530) = *(undefined4 *)(iVar1 + 0x134);
  iVar1 = *(int *)(param_2 + 8);
  *(float *)(param_2 + 0x518) = -*(float *)(iVar1 + 0x16c);
  *(float *)(param_2 + 0x51c) = -*(float *)(iVar1 + 0x170);
  *(undefined4 *)(param_2 + 0x534) = *(undefined4 *)(iVar1 + 0x164);
  iVar1 = *(int *)(param_2 + 8);
  *(float *)(param_2 + 0x520) = -*(float *)(iVar1 + 0x19c);
  *(float *)(param_2 + 0x524) = -*(float *)(iVar1 + 0x1a0);
  *(undefined4 *)(param_2 + 0x538) = *(undefined4 *)(iVar1 + 0x194);
  iVar1 = *(int *)(param_2 + 8);
  *(float *)(param_2 + 0x528) = -*(float *)(iVar1 + 0x1cc);
  *(float *)(param_2 + 0x52c) = -*(float *)(iVar1 + 0x1d0);
  *(undefined4 *)(param_2 + 0x53c) = *(undefined4 *)(iVar1 + 0x1c4);
  return;
}


// ==== 0x56c310 FUN_0056c310

void FUN_0056c310(void)

{
  undefined4 in_EAX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 4) = in_EAX;
  GetUsedCarTextureInfo(unaff_ESI + 0x40);
  if (*(int *)(unaff_ESI + 0x458) != *(int *)(unaff_ESI + 0x710)) {
    *(int *)(unaff_ESI + 0x710) = *(int *)(unaff_ESI + 0x458);
    *(undefined4 *)(unaff_ESI + 0x714) = 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x45c) != *(int *)(unaff_ESI + 0x720)) {
    *(int *)(unaff_ESI + 0x720) = *(int *)(unaff_ESI + 0x45c);
    *(undefined4 *)(unaff_ESI + 0x724) = 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x464) != *(int *)(unaff_ESI + 0x750)) {
    *(int *)(unaff_ESI + 0x750) = *(int *)(unaff_ESI + 0x464);
    *(undefined4 *)(unaff_ESI + 0x754) = 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x460) != *(int *)(unaff_ESI + 0x730)) {
    *(int *)(unaff_ESI + 0x730) = *(int *)(unaff_ESI + 0x460);
    *(undefined4 *)(unaff_ESI + 0x734) = 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x460) != *(int *)(unaff_ESI + 0xe40)) {
    *(int *)(unaff_ESI + 0xe40) = *(int *)(unaff_ESI + 0x460);
    *(undefined4 *)(unaff_ESI + 0xe44) = 0xffffffff;
  }
  if (*(int *)(unaff_ESI + 0x460) != *(int *)(unaff_ESI + 0xe60)) {
    *(int *)(unaff_ESI + 0xe60) = *(int *)(unaff_ESI + 0x460);
    *(undefined4 *)(unaff_ESI + 0xe64) = 0xffffffff;
  }
  return;
}


// ==== 0x56c3d0 CarRenderInfo::UpdateDecalTextures

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void CarRenderInfo__UpdateDecalTextures(int param_1,int param_2)

{
  char *pcVar1;
  byte *pbVar2;
  int *piVar3;
  byte bVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  char *pcVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  byte *pbVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int local_c0;
  int local_bc;
  int local_a4 [4];
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  byte local_80;
  byte local_7f [127];
  
  pcVar11 = "DEFAULTALPHA";
  uVar5 = 0x44;
  iVar8 = -1;
  do {
    iVar8 = iVar8 * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  piVar12 = &DAT_0073d764;
  piVar6 = (int *)(param_1 + 0x900);
  do {
    piVar6[-1] = piVar12[-1];
    if (iVar8 != *piVar6) {
      *piVar6 = iVar8;
      piVar6[1] = -1;
    }
    piVar6[3] = *piVar12;
    if (iVar8 != piVar6[4]) {
      piVar6[4] = iVar8;
      piVar6[5] = -1;
    }
    piVar6[7] = piVar12[1];
    if (iVar8 != piVar6[8]) {
      piVar6[8] = iVar8;
      piVar6[9] = -1;
    }
    piVar6[0xb] = piVar12[2];
    if (iVar8 != piVar6[0xc]) {
      piVar6[0xc] = iVar8;
      piVar6[0xd] = -1;
    }
    piVar6[0xf] = piVar12[3];
    if (iVar8 != piVar6[0x10]) {
      piVar6[0x10] = iVar8;
      piVar6[0x11] = -1;
    }
    piVar6[0x13] = piVar12[4];
    if (iVar8 != piVar6[0x14]) {
      piVar6[0x14] = iVar8;
      piVar6[0x15] = -1;
    }
    piVar6[0x17] = piVar12[5];
    if (iVar8 != piVar6[0x18]) {
      piVar6[0x18] = iVar8;
      piVar6[0x19] = -1;
    }
    piVar6[0x1b] = piVar12[6];
    if (iVar8 != piVar6[0x1c]) {
      piVar6[0x1c] = iVar8;
      piVar6[0x1d] = -1;
    }
    piVar6[0x1f] = piVar12[7];
    if (iVar8 != piVar6[0x20]) {
      piVar6[0x20] = iVar8;
      piVar6[0x21] = -1;
    }
    piVar12 = piVar12 + 9;
    piVar6 = piVar6 + 0x24;
  } while ((int)piVar12 < 0x73d7cd);
  pcVar11 = "DUMMY_DECAL1";
  local_a4[0] = -1;
  uVar5 = 0x44;
  do {
    local_a4[0] = local_a4[0] * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL2";
  local_a4[1] = -1;
  uVar5 = 0x44;
  do {
    local_a4[1] = local_a4[1] * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL3";
  local_a4[2] = -1;
  uVar5 = 0x44;
  do {
    local_a4[2] = local_a4[2] * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL4";
  local_a4[3] = -1;
  uVar5 = 0x44;
  do {
    local_a4[3] = local_a4[3] * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL5";
  local_94 = -1;
  uVar5 = 0x44;
  do {
    local_94 = local_94 * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL6";
  local_90 = -1;
  uVar5 = 0x44;
  do {
    local_90 = local_90 * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL7";
  local_8c = -1;
  uVar5 = 0x44;
  do {
    local_8c = local_8c * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  pcVar11 = "DUMMY_DECAL8";
  local_88 = -1;
  uVar5 = 0x44;
  do {
    local_88 = local_88 * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  piVar6 = (int *)(param_1 + 0xab0);
  uVar5 = 2;
  do {
    uVar19 = uVar5 - 2 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[-1] = local_a4[uVar19];
    if (iVar8 != *piVar6) {
      *piVar6 = iVar8;
      piVar6[1] = -1;
    }
    uVar19 = uVar5 - 1 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[3] = local_a4[uVar19];
    if (iVar8 != piVar6[4]) {
      piVar6[4] = iVar8;
      piVar6[5] = -1;
    }
    uVar19 = uVar5 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[7] = local_a4[uVar19];
    if (iVar8 != piVar6[8]) {
      piVar6[8] = iVar8;
      piVar6[9] = -1;
    }
    uVar19 = uVar5 + 1 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[0xb] = local_a4[uVar19];
    if (iVar8 != piVar6[0xc]) {
      piVar6[0xc] = iVar8;
      piVar6[0xd] = -1;
    }
    uVar19 = uVar5 + 2 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[0xf] = local_a4[uVar19];
    if (iVar8 != piVar6[0x10]) {
      piVar6[0x10] = iVar8;
      piVar6[0x11] = -1;
    }
    uVar19 = uVar5 + 3 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[0x13] = local_a4[uVar19];
    if (iVar8 != piVar6[0x14]) {
      piVar6[0x14] = iVar8;
      piVar6[0x15] = -1;
    }
    uVar19 = uVar5 + 4 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[0x17] = local_a4[uVar19];
    if (iVar8 != piVar6[0x18]) {
      piVar6[0x18] = iVar8;
      piVar6[0x19] = -1;
    }
    uVar19 = uVar5 + 5 & 0x80000007;
    if ((int)uVar19 < 0) {
      uVar19 = (uVar19 - 1 | 0xfffffff8) + 1;
    }
    piVar6[0x1b] = local_a4[uVar19];
    if (iVar8 != piVar6[0x1c]) {
      piVar6[0x1c] = iVar8;
      piVar6[0x1d] = -1;
    }
    iVar13 = uVar5 + 6;
    piVar6 = piVar6 + 0x20;
    uVar5 = uVar5 + 8;
  } while (iVar13 < 0x38);
  iVar8 = *(int *)(param_2 + 0x46c);
  puVar9 = &DAT_006bbc5c;
  iVar13 = -1;
  uVar5 = 0x53;
  do {
    iVar13 = iVar13 * 0x21 + uVar5;
    pbVar17 = puVar9 + 1;
    uVar5 = (uint)*pbVar17;
    puVar9 = puVar9 + 1;
  } while (*pbVar17 != 0);
  iVar14 = -1;
  uVar5 = 0x53;
  puVar9 = &DAT_006bbc54;
  do {
    iVar14 = iVar14 * 0x21 + uVar5;
    pbVar17 = puVar9 + 1;
    uVar5 = (uint)*pbVar17;
    puVar9 = puVar9 + 1;
  } while (*pbVar17 != 0);
  puVar9 = &DAT_006bbc4c;
  do {
    pcVar11 = puVar9 + 1;
    puVar9 = puVar9 + 1;
  } while (*pcVar11 != '\0');
  pcVar11 = "MEDIUM";
  do {
    pcVar1 = pcVar11 + 1;
    pcVar11 = pcVar11 + 1;
  } while (*pcVar1 != '\0');
  pcVar11 = "LARGE";
  do {
    pcVar1 = pcVar11 + 1;
    pcVar11 = pcVar11 + 1;
  } while (*pcVar1 != '\0');
  uVar5 = 0x53;
  iVar15 = -1;
  pcVar11 = "SQUARE";
  do {
    iVar15 = iVar15 * 0x21 + uVar5;
    pbVar17 = (byte *)(pcVar11 + 1);
    uVar5 = (uint)*pbVar17;
    pcVar11 = pcVar11 + 1;
  } while (*pbVar17 != 0);
  iVar16 = -1;
  uVar5 = 0x52;
  puVar9 = &DAT_006bbc3c;
  do {
    iVar16 = iVar16 * 0x21 + uVar5;
    pbVar17 = puVar9 + 1;
    uVar5 = (uint)*pbVar17;
    puVar9 = puVar9 + 1;
  } while (*pbVar17 != 0);
  local_84 = -1;
  uVar5 = 0x57;
  puVar9 = &DAT_006bbc34;
  do {
    local_84 = local_84 * 0x21 + uVar5;
    pbVar17 = puVar9 + 1;
    uVar5 = (uint)*pbVar17;
    puVar9 = puVar9 + 1;
  } while (*pbVar17 != 0);
  local_c0 = 0x13;
  do {
    iVar18 = *(int *)(param_2 + 0x44c + local_c0 * 4);
    if ((iVar18 != 0) && ((local_c0 != 0x13 || (iVar8 != 0)))) {
      iVar20 = (int)*(short *)(iVar18 + 0x1c);
      piVar6 = *(int **)(iVar18 + 0x14);
      piVar12 = piVar6;
      if (piVar6 != (int *)0x0) {
        for (; piVar12 < piVar6 + iVar20 * 2; piVar12 = piVar12 + 2) {
          if ((iVar13 == 0) || (*piVar12 == iVar13)) {
            if ((piVar12 != (int *)0x0) && (piVar12 = piVar6, piVar6 != (int *)0x0))
            goto joined_r0x0056c88b;
            break;
          }
        }
      }
    }
LAB_0056ca3a:
    local_c0 = local_c0 + 1;
    if (0x19 < local_c0) {
      return;
    }
  } while( true );
joined_r0x0056c88b:
  if (piVar12 < piVar6 + iVar20 * 2) {
    if ((iVar14 != 0) && (*piVar12 != iVar14)) goto code_r0x0056c89d;
    if (piVar12 != (int *)0x0) {
      piVar12 = piVar6;
      if (piVar6 != (int *)0x0) {
        for (; ((piVar12 < piVar6 + iVar20 * 2 && (iVar13 != 0)) && (*piVar12 != iVar13));
            piVar12 = piVar12 + 2) {
        }
      }
      piVar12 = piVar6 + iVar20 * 2;
      if (piVar6 == (int *)0x0) {
LAB_0056c8f7:
        local_bc = 0;
      }
      else {
        while( true ) {
          if (piVar12 <= piVar6) goto LAB_0056c8f7;
          if ((iVar14 == 0) || (*piVar6 == iVar14)) break;
          piVar6 = piVar6 + 2;
        }
        if (piVar6 == (int *)0x0) goto LAB_0056c8f7;
        local_bc = piVar6[1];
      }
      piVar6 = (int *)((local_c0 + -0x13) * 0x80 + param_1 + 0xab0);
      piVar12 = (int *)(param_2 + 0x44c + ((local_c0 + -0x13) * 8 + 0x3b) * 4);
      iVar18 = 8;
      do {
        iVar20 = *piVar12;
        if (iVar20 != 0) {
          puVar9 = &DAT_006bd3bc;
          iVar10 = -1;
          uVar5 = 0x4e;
          do {
            iVar10 = iVar10 * 0x21 + uVar5;
            pbVar17 = puVar9 + 1;
            uVar5 = (uint)*pbVar17;
            puVar9 = puVar9 + 1;
          } while (*pbVar17 != 0);
          piVar7 = *(int **)(iVar20 + 0x14);
          piVar3 = piVar7 + *(short *)(iVar20 + 0x1c) * 2;
          if (piVar7 != (int *)0x0) {
            for (; piVar7 < piVar3; piVar7 = piVar7 + 2) {
              if ((iVar10 == 0) || (*piVar7 == iVar10)) {
                if (piVar7 != (int *)0x0) {
                  iVar20 = piVar7[1];
                  goto LAB_0056c978;
                }
                break;
              }
            }
          }
          iVar20 = 0;
LAB_0056c978:
          if (local_bc == iVar15) {
            local_80 = 0x5f;
            iVar10 = 0;
            do {
              bVar4 = "_SQUARE"[iVar10 + 1];
              local_7f[iVar10] = bVar4;
              iVar10 = iVar10 + 1;
            } while (bVar4 != 0);
          }
          else if (local_bc == iVar16) {
            local_80 = 0x5f;
            iVar10 = 0;
            do {
              bVar4 = "_RECT"[iVar10 + 1];
              local_7f[iVar10] = bVar4;
              iVar10 = iVar10 + 1;
            } while (bVar4 != 0);
          }
          else if (local_bc == local_84) {
            local_80 = 0x5f;
            iVar10 = 0;
            do {
              bVar4 = (&DAT_006bbc1d)[iVar10];
              local_7f[iVar10] = bVar4;
              iVar10 = iVar10 + 1;
            } while (bVar4 != 0);
          }
          pbVar17 = &local_80;
          bVar4 = local_80;
          while (bVar4 != 0) {
            iVar20 = iVar20 * 0x21 + (uint)bVar4;
            pbVar2 = pbVar17 + 1;
            pbVar17 = pbVar17 + 1;
            bVar4 = *pbVar2;
          }
          if (iVar20 != *piVar6) {
            *piVar6 = iVar20;
            piVar6[1] = -1;
          }
        }
        piVar12 = piVar12 + 1;
        piVar6 = piVar6 + 4;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
    }
  }
  goto LAB_0056ca3a;
code_r0x0056c89d:
  piVar12 = piVar12 + 2;
  goto joined_r0x0056c88b;
}


// ==== 0x56ca60 FUN_0056ca60

void FUN_0056ca60(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*param_1 + 0x868);
  }
  iVar2 = 0x10;
  piVar3 = param_1 + 0x1e8;
  do {
    uVar1 = 0;
    if (iVar4 != 0) {
      uVar1 = *(uint *)(iVar4 + 0xe0) >> ((byte)iVar2 & 0x1f) & 3;
    }
    if ((&DAT_006f1b48)[uVar1] != *piVar3) {
      *piVar3 = (&DAT_006f1b48)[uVar1];
      piVar3[1] = -1;
    }
    if ((&DAT_006f1b58)[uVar1] != piVar3[0x18]) {
      piVar3[0x18] = (&DAT_006f1b58)[uVar1];
      piVar3[0x19] = -1;
    }
    iVar2 = iVar2 + 2;
    piVar3 = piVar3 + 4;
  } while (iVar2 < 0x1c);
  param_1[0x143] = 0;
  return;
}


// ==== 0x56cae0 FUN_0056cae0

void __fastcall FUN_0056cae0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1[0x11c];
  iVar3 = param_1[0x11f];
  if (iVar2 != param_1[0x218]) {
    param_1[0x218] = iVar2;
    param_1[0x219] = -1;
  }
  if (iVar2 != param_1[0x21c]) {
    param_1[0x21c] = iVar2;
    param_1[0x21d] = -1;
  }
  if (iVar3 != param_1[0x22c]) {
    param_1[0x22c] = iVar3;
    param_1[0x22d] = -1;
  }
  if (iVar3 != param_1[0x230]) {
    param_1[0x230] = iVar3;
    param_1[0x231] = -1;
  }
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*param_1 + 0x30);
  }
  iVar3 = 0;
  iVar4 = 0;
  if ((iVar2 != 0) && (0.05 < *(float *)(iVar2 + 0x1e4))) {
    iVar3 = 1;
    iVar4 = 1;
  }
  if (DAT_007345e8 != 0) {
    iVar3 = 1;
    iVar4 = 1;
  }
  iVar2 = param_1[iVar4 + 0x121];
  iVar1 = param_1[iVar3 + 0x124];
  iVar4 = param_1[iVar4 + 0x124];
  if (param_1[iVar3 + 0x121] != param_1[0x220]) {
    param_1[0x220] = param_1[iVar3 + 0x121];
    param_1[0x221] = -1;
  }
  if (iVar2 != param_1[0x224]) {
    param_1[0x224] = iVar2;
    param_1[0x225] = -1;
  }
  if (param_1[0x121] != param_1[0x228]) {
    param_1[0x228] = param_1[0x121];
    param_1[0x229] = -1;
  }
  if (iVar1 != param_1[0x234]) {
    param_1[0x234] = iVar1;
    param_1[0x235] = -1;
  }
  if (iVar4 != param_1[0x238]) {
    param_1[0x238] = iVar4;
    param_1[0x239] = -1;
  }
  if (param_1[0x124] != param_1[0x23c]) {
    param_1[0x23c] = param_1[0x124];
    param_1[0x23d] = -1;
  }
  return;
}


// ==== 0x56cc40 FUN_0056cc40

void FUN_0056cc40(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  undefined1 uVar10;
  bool bVar11;
  int local_8;
  
  iVar7 = (int)param_1;
  if (*(int *)((int)param_1 + 8) != 0) {
    param_1 = (int *)((int)param_1 + 0xe78);
    local_8 = 0x1e;
    do {
      puVar9 = (uint *)0x0;
      while (iVar3 = *param_1, iVar3 != 0) {
        puVar4 = *(uint **)(iVar3 + 0x80);
        if ((puVar4 == (uint *)0x0) || (*(char *)(iVar3 + 0x1b) == 0)) {
LAB_0056ccac:
          puVar4 = (uint *)0x0;
        }
        else if (puVar9 != (uint *)0x0) {
          if ((puVar9 < puVar4) || (puVar4 + (*(char *)(iVar3 + 0x1b) * 5 + -5) * 4 <= puVar9))
          goto LAB_0056ccac;
          puVar4 = puVar9 + 0x14;
        }
        puVar9 = puVar4;
        if (puVar9 == (uint *)0x0) break;
        uVar5 = *puVar9;
        if (uVar5 < 0xa2a2fc7d) {
          if ((uVar5 == 0xa2a2fc7c) || (uVar5 == 0x31a66786)) goto LAB_0056ccf4;
          if (uVar5 != 0x7a5bcf69) {
            bVar11 = uVar5 == 0x9db90133;
            goto LAB_0056ccee;
          }
          goto LAB_0056ccf0;
        }
        if (uVar5 == 0xbf700a79) {
LAB_0056ccf4:
          uVar10 = 1;
          goto LAB_0056ccf9;
        }
        bVar11 = uVar5 == 0xd09091c6;
LAB_0056ccee:
        if (bVar11) {
LAB_0056ccf0:
          uVar10 = 0;
LAB_0056ccf9:
          piVar8 = _malloc(0x50);
          *(undefined1 *)((int)piVar8 + 0x2e) = 0;
          piVar8[2] = uVar5;
          *(undefined1 *)(piVar8 + 3) = 1;
          *(undefined1 *)((int)piVar8 + 0xd) = uVar10;
          *(undefined2 *)((int)piVar8 + 0xe) = 0;
          piVar8[4] = (int)((float)puVar9[0x10] - *(float *)(iVar7 + 0x30));
          piVar8[5] = (int)((float)puVar9[0x11] - *(float *)(iVar7 + 0x34));
          fVar1 = (float)puVar9[0x12];
          fVar2 = *(float *)(iVar7 + 0x38);
          piVar8[7] = 0;
          piVar8[6] = (int)(fVar1 - fVar2);
          piVar8[8] = puVar9[0xc];
          piVar8[9] = puVar9[0xd];
          piVar8[10] = puVar9[0xe];
          puVar6 = *(undefined4 **)(iVar7 + 0x504);
          *puVar6 = piVar8;
          *(int **)(iVar7 + 0x504) = piVar8;
          piVar8[1] = (int)puVar6;
          *piVar8 = iVar7 + 0x500;
        }
      }
      param_1 = param_1 + 0x18;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


// ==== 0x56cd90 FUN_0056cd90

undefined4 FUN_0056cd90(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  
  fVar1 = *(float *)*param_1 - *(float *)*param_2;
  if (0.0 < fVar1) {
    return 1;
  }
  if (0.0 <= fVar1) {
    fVar1 = ((float *)*param_2)[1] - ((float *)*param_1)[1];
    if (0.0 < fVar1) {
      return 1;
    }
    if (0.0 <= fVar1) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ==== 0x56cdf0 FUN_0056cdf0

void FUN_0056cdf0(undefined4 param_1,undefined4 param_2)

{
  FUN_0056cd90(param_2,param_1);
  return;
}


// ==== 0x56ce10 FUN_0056ce10

int FUN_0056ce10(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  int unaff_ESI;
  int iVar7;
  
  iVar7 = 1;
  _qsort();
  iVar6 = 2;
  if (2 < param_1) {
    do {
      if (0 < iVar7) {
        pfVar1 = *(float **)(unaff_ESI + iVar6 * 4);
        do {
          pfVar2 = *(float **)(unaff_ESI + iVar7 * 4);
          pfVar3 = *(float **)(unaff_ESI + -4 + iVar7 * 4);
          fVar5 = (*pfVar1 - *pfVar2) * (pfVar3[1] - pfVar2[1]) -
                  (*pfVar3 - *pfVar2) * (pfVar1[1] - pfVar2[1]);
          if (fVar5 < 0.0 == (fVar5 == 0.0)) break;
          iVar7 = iVar7 + -1;
        } while (0 < iVar7);
      }
      uVar4 = *(undefined4 *)(unaff_ESI + 4 + iVar7 * 4);
      iVar7 = iVar7 + 1;
      *(undefined4 *)(unaff_ESI + iVar7 * 4) = *(undefined4 *)(unaff_ESI + iVar6 * 4);
      *(undefined4 *)(unaff_ESI + iVar6 * 4) = uVar4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1);
  }
  return iVar7;
}


// ==== 0x56ce90 FUN_0056ce90

undefined4 FUN_0056ce90(float param_1,float param_2)

{
  if (ABS(param_1 - param_2) < 4.0 != (ABS(param_1 - param_2) == 4.0)) {
    return 1;
  }
  return 0;
}


// ==== 0x56ceb0 FUN_0056ceb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056ceb0(void)

{
  float fVar1;
  float *in_EAX;
  
  fVar1 = _DAT_0073c664 * (in_EAX[1] - _DAT_0073cab4) +
          _DAT_0073c668 * (in_EAX[2] - DAT_0073cab8) + _DAT_0073c660 * (*in_EAX - _DAT_0073cab0);
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if (fVar1 < 1.5) {
    return 1;
  }
  return 0;
}


// ==== 0x56cf10 FUN_0056cf10

void FUN_0056cf10(int param_1,int *param_2,undefined4 param_3,float param_4,float param_5,
                 int param_6)

{
  undefined4 uVar1;
  float fVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  
  piVar3 = param_2;
  iVar5 = 0;
  if (0 < *param_2) {
    do {
      (&DAT_007305b0)[iVar5] = (undefined4 *)param_1;
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 0x10;
    } while (iVar5 < *param_2);
  }
  iVar5 = *param_2;
  param_2 = (int *)FUN_0056ce10(iVar5);
  (&DAT_007305b0)[iVar5] = DAT_007305b0;
  iVar5 = FUN_0056ce10((iVar5 - (int)param_2) + 1);
  *piVar3 = iVar5 + (int)param_2;
  puVar6 = &DAT_0073c680;
  if (param_6 != 0) {
    DAT_0073c684 = DAT_007305b0[1];
    DAT_0073c680 = *DAT_007305b0;
    DAT_0073c688 = param_4;
    fVar8 = (float10)GroundQuery__FindSurfaceBelow(param_3,&DAT_0073c680,0,0,(int)&param_2 + 3);
    fVar9 = (float10)param_5;
    iVar7 = 0;
    param_6 = 0;
    iVar5 = 0;
    if (0 < *piVar3) {
      do {
        uVar1 = *(&DAT_007305b0)[iVar7];
        puVar6[1] = (&DAT_007305b0)[iVar7][1];
        *puVar6 = uVar1;
        puVar6[2] = (float)(fVar8 + fVar9);
        if (((param_2._3_1_ == '\0') ||
            (fVar2 = ABS((float)(fVar8 + fVar9) - param_4), fVar2 < 4.0 == (fVar2 == 4.0))) ||
           (cVar4 = FUN_0056ceb0(), cVar4 == '\0')) {
          param_6 = param_6 + 1;
        }
        else {
          puVar6 = puVar6 + 4;
        }
        iVar7 = iVar7 + 1;
        iVar5 = param_6;
      } while (iVar7 < *piVar3);
    }
    *piVar3 = *piVar3 - iVar5;
    return;
  }
  iVar7 = 0;
  param_6 = 0;
  if (0 < iVar5 + (int)param_2) {
    do {
      uVar1 = *(&DAT_007305b0)[iVar7];
      puVar6[1] = (&DAT_007305b0)[iVar7][1];
      *puVar6 = uVar1;
      puVar6[2] = param_4;
      fVar9 = (float10)GroundQuery__FindSurfaceBelow(param_3,puVar6,0,0,(int)&param_2 + 3);
      puVar6[2] = (float)(fVar9 + (float10)param_5);
      if (((param_2._3_1_ == '\0') ||
          (fVar9 = ABS((fVar9 + (float10)param_5) - (float10)param_4),
          fVar9 < (float10)4.0 == (fVar9 == (float10)4.0))) ||
         (cVar4 = FUN_0056ceb0(), cVar4 == '\0')) {
        param_6 = param_6 + 1;
      }
      else {
        puVar6 = puVar6 + 4;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *piVar3);
    *piVar3 = *piVar3 - param_6;
    return;
  }
  *piVar3 = *piVar3;
  return;
}


// ==== 0x56d0c0 FUN_0056d0c0

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe0 : 0x0056d1c4 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_0056d0c0(uint param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  float *pfVar11;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int local_7c;
  uint local_74;
  float local_30 [4];
  float local_20;
  float local_1c;
  float local_18;
  
  iVar9 = param_1 * 0x10;
  fVar7 = (DAT_0073c680 - *(float *)(&DAT_0073c670 + iVar9)) * 0.333;
  local_7c = 0;
  local_74 = 0;
  local_20 = fVar7;
  fVar8 = (DAT_0073c684 - *(float *)(&DAT_0073c674 + iVar9)) * 0.333;
  local_1c = fVar8;
  fVar6 = (DAT_0073c688 - *(float *)(&DAT_0073c678 + iVar9)) * 0.333;
  local_18 = fVar6;
  if (3 < (int)param_1) {
    pfVar11 = &DAT_0073c688;
    pfVar12 = (float *)&DAT_0073cac8;
    uVar15 = 2;
    do {
      uVar13 = uVar15 - 1;
      if (uVar13 == param_1) {
        uVar13 = 0;
      }
      local_30[0] = ((&DAT_0073c680)[uVar13 * 4] - pfVar11[-2]) * 0.333;
      local_30[1] = ((&DAT_0073c684)[uVar13 * 4] - pfVar11[-1]) * 0.333;
      local_30[2] = ((&DAT_0073c688)[uVar13 * 4] - *pfVar11) * 0.333;
      fVar2 = pfVar11[-1];
      fVar3 = *pfVar11;
      pfVar12[-2] = pfVar11[-2] - fVar7;
      *pfVar12 = fVar3 - fVar6;
      pfVar12[-1] = fVar2 - fVar8;
      fVar2 = pfVar11[-1];
      fVar3 = *pfVar11;
      pfVar12[6] = pfVar11[-2] + local_30[0];
      pfVar12[8] = local_30[2] + fVar3;
      pfVar12[7] = local_30[1] + fVar2;
      uVar14 = uVar15 - 1 & 1;
      uVar10 = uVar14 ^ 1;
      pfVar12[2] = (local_30[0] - fVar7) * 0.333 + pfVar11[-2];
      pfVar12[3] = (local_30[1] - fVar8) * 0.333 + pfVar11[-1];
      pfVar12[4] = (local_30[2] - fVar6) * 0.333 + *pfVar11;
      uVar13 = uVar15;
      if (uVar15 == param_1) {
        uVar13 = 0;
      }
      fVar2 = (&DAT_0073c684)[uVar13 * 4];
      fVar3 = pfVar11[3];
      fVar4 = (&DAT_0073c688)[uVar13 * 4];
      pfVar1 = local_30 + uVar14 * 4;
      fVar5 = pfVar11[4];
      *pfVar1 = (&DAT_0073c680)[uVar13 * 4] - pfVar11[2];
      local_30[uVar14 * 4 + 2] = fVar4 - fVar5;
      local_30[uVar14 * 4 + 1] = fVar2 - fVar3;
      *pfVar1 = *pfVar1 * 0.333;
      local_30[uVar14 * 4 + 1] = local_30[uVar14 * 4 + 1] * 0.333;
      local_30[uVar14 * 4 + 2] = local_30[uVar14 * 4 + 2] * 0.333;
      fVar2 = local_30[uVar10 * 4 + 1];
      fVar3 = pfVar11[3];
      fVar4 = local_30[uVar10 * 4 + 2];
      fVar5 = pfVar11[4];
      pfVar12[10] = pfVar11[2] - local_30[uVar10 * 4];
      pfVar12[0xc] = fVar5 - fVar4;
      pfVar12[0xb] = fVar3 - fVar2;
      fVar2 = local_30[uVar14 * 4 + 1];
      fVar3 = pfVar11[3];
      fVar4 = local_30[uVar14 * 4 + 2];
      fVar5 = pfVar11[4];
      pfVar12[0x12] = pfVar11[2] + *pfVar1;
      pfVar12[0x14] = fVar4 + fVar5;
      pfVar12[0x13] = fVar2 + fVar3;
      fVar2 = local_30[uVar14 * 4 + 1];
      fVar3 = local_30[uVar10 * 4 + 1];
      fVar4 = local_30[uVar14 * 4 + 2];
      fVar5 = local_30[uVar10 * 4 + 2];
      uVar13 = uVar15 + 1;
      pfVar12[0xe] = (*pfVar1 - local_30[uVar10 * 4]) * 0.333 + pfVar11[2];
      pfVar12[0xf] = (fVar2 - fVar3) * 0.333 + pfVar11[3];
      pfVar12[0x10] = (fVar4 - fVar5) * 0.333 + pfVar11[4];
      if (uVar13 == param_1) {
        uVar13 = 0;
      }
      local_30[0] = ((&DAT_0073c680)[uVar13 * 4] - pfVar11[6]) * 0.333;
      local_30[1] = ((&DAT_0073c684)[uVar13 * 4] - pfVar11[7]) * 0.333;
      local_30[2] = ((&DAT_0073c688)[uVar13 * 4] - pfVar11[8]) * 0.333;
      fVar2 = pfVar11[7];
      fVar3 = pfVar11[8];
      pfVar12[0x16] = pfVar11[6] - fVar7;
      pfVar12[0x18] = fVar3 - fVar6;
      pfVar12[0x17] = fVar2 - fVar8;
      fVar2 = pfVar11[7];
      fVar3 = pfVar11[8];
      pfVar12[0x1e] = pfVar11[6] + local_30[0];
      pfVar12[0x20] = local_30[2] + fVar3;
      pfVar12[0x1f] = local_30[1] + fVar2;
      uVar10 = uVar14 ^ 1;
      uVar13 = uVar15 + 2;
      pfVar12[0x1a] = (local_30[0] - fVar7) * 0.333 + pfVar11[6];
      pfVar12[0x1b] = (local_30[1] - fVar8) * 0.333 + pfVar11[7];
      pfVar12[0x1c] = (local_30[2] - fVar6) * 0.333 + pfVar11[8];
      if (uVar13 == param_1) {
        uVar13 = 0;
      }
      pfVar1 = local_30 + uVar14 * 4;
      fVar2 = (&DAT_0073c684)[uVar13 * 4];
      fVar3 = pfVar11[0xb];
      fVar4 = (&DAT_0073c688)[uVar13 * 4];
      fVar5 = pfVar11[0xc];
      *pfVar1 = (&DAT_0073c680)[uVar13 * 4] - pfVar11[10];
      local_30[uVar14 * 4 + 2] = fVar4 - fVar5;
      local_30[uVar14 * 4 + 1] = fVar2 - fVar3;
      *pfVar1 = *pfVar1 * 0.333;
      local_30[uVar14 * 4 + 1] = local_30[uVar14 * 4 + 1] * 0.333;
      local_30[uVar14 * 4 + 2] = local_30[uVar14 * 4 + 2] * 0.333;
      fVar2 = local_30[uVar10 * 4 + 1];
      fVar3 = pfVar11[0xb];
      fVar4 = local_30[uVar10 * 4 + 2];
      fVar5 = pfVar11[0xc];
      pfVar12[0x22] = pfVar11[10] - local_30[uVar10 * 4];
      pfVar12[0x24] = fVar5 - fVar4;
      pfVar12[0x23] = fVar3 - fVar2;
      fVar2 = local_30[uVar14 * 4 + 1];
      fVar3 = pfVar11[0xb];
      fVar4 = local_30[uVar14 * 4 + 2];
      fVar5 = pfVar11[0xc];
      pfVar12[0x2a] = pfVar11[10] + *pfVar1;
      pfVar12[0x2c] = fVar4 + fVar5;
      pfVar12[0x2b] = fVar2 + fVar3;
      fVar2 = local_30[uVar14 * 4 + 1];
      fVar3 = local_30[uVar10 * 4 + 1];
      fVar4 = local_30[uVar14 * 4 + 2];
      fVar5 = local_30[uVar10 * 4 + 2];
      local_7c = local_7c + 0xc;
      local_74 = local_74 + 4;
      pfVar12[0x26] = (*pfVar1 - local_30[uVar10 * 4]) * 0.333 + pfVar11[10];
      iVar9 = uVar15 + 5;
      pfVar12[0x27] = (fVar2 - fVar3) * 0.333 + pfVar11[0xb];
      pfVar12[0x28] = (fVar4 - fVar5) * 0.333 + pfVar11[0xc];
      pfVar11 = pfVar11 + 0x10;
      pfVar12 = pfVar12 + 0x30;
      uVar15 = uVar15 + 4;
    } while (iVar9 < (int)param_1);
  }
  if ((int)param_1 <= (int)local_74) {
    return local_7c;
  }
  iVar9 = param_1 - local_74;
  pfVar11 = &DAT_0073c688 + local_74 * 4;
  pfVar12 = (float *)(&DAT_0073cac8 + local_7c * 4);
  uVar15 = local_74;
  do {
    uVar15 = uVar15 + 1;
    uVar10 = local_74 & 1;
    uVar14 = uVar10 ^ 1;
    uVar13 = uVar15;
    if (uVar15 == param_1) {
      uVar13 = 0;
    }
    pfVar1 = local_30 + uVar10 * 4;
    fVar6 = (&DAT_0073c684)[uVar13 * 4];
    fVar7 = pfVar11[-1];
    fVar8 = (&DAT_0073c688)[uVar13 * 4];
    fVar2 = *pfVar11;
    *pfVar1 = (&DAT_0073c680)[uVar13 * 4] - pfVar11[-2];
    local_30[uVar10 * 4 + 2] = fVar8 - fVar2;
    local_30[uVar10 * 4 + 1] = fVar6 - fVar7;
    *pfVar1 = *pfVar1 * 0.333;
    local_30[uVar10 * 4 + 1] = local_30[uVar10 * 4 + 1] * 0.333;
    local_30[uVar10 * 4 + 2] = local_30[uVar10 * 4 + 2] * 0.333;
    fVar6 = local_30[uVar14 * 4 + 1];
    fVar7 = pfVar11[-1];
    fVar8 = local_30[uVar14 * 4 + 2];
    fVar2 = *pfVar11;
    pfVar12[-2] = pfVar11[-2] - local_30[uVar14 * 4];
    *pfVar12 = fVar2 - fVar8;
    pfVar12[-1] = fVar7 - fVar6;
    fVar6 = local_30[uVar10 * 4 + 1];
    fVar7 = pfVar11[-1];
    fVar8 = local_30[uVar10 * 4 + 2];
    fVar2 = *pfVar11;
    pfVar12[6] = pfVar11[-2] + *pfVar1;
    pfVar12[8] = fVar8 + fVar2;
    pfVar12[7] = fVar6 + fVar7;
    fVar6 = local_30[uVar10 * 4 + 1];
    fVar7 = local_30[uVar14 * 4 + 1];
    fVar8 = local_30[uVar10 * 4 + 2];
    fVar2 = local_30[uVar14 * 4 + 2];
    local_74 = local_74 + 1;
    pfVar12[2] = (*pfVar1 - local_30[uVar14 * 4]) * 0.333 + pfVar11[-2];
    pfVar12[3] = (fVar6 - fVar7) * 0.333 + pfVar11[-1];
    pfVar12[4] = (fVar8 - fVar2) * 0.333 + *pfVar11;
    pfVar11 = pfVar11 + 4;
    pfVar12 = pfVar12 + 0xc;
  } while ((int)local_74 < (int)param_1);
  return local_7c + iVar9 * 3;
}


// ==== 0x56d700 FUN_0056d700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056d700(void)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  float *in_EAX;
  float local_38;
  float local_34;
  float local_28;
  
  if (DAT_00735518 == 0) {
    local_28 = 7000.0;
    _DAT_0073c670 = -16384.0;
    _DAT_0073c674 = 0.0;
  }
  else {
    _DAT_0073c670 = *(float *)(DAT_00735518 + 0x2c);
    _DAT_0073c674 = *(float *)(DAT_00735518 + 0x30);
    local_28 = *(float *)(DAT_00735518 + 0x34) + 0.0;
  }
  _DAT_0073c670 = *in_EAX - _DAT_0073c670;
  _DAT_0073c674 = in_EAX[1] - _DAT_0073c674;
  _DAT_0073c678 = in_EAX[2] - local_28;
  uVar3 = Atan2ToAngle16(SQRT(_DAT_0073c670 * _DAT_0073c670 + _DAT_0073c674 * _DAT_0073c674),
                         -_DAT_0073c678);
  if (uVar3 < 0x1a90) {
    Angle16SinCos();
    fVar1 = SQRT(_DAT_0073c670 * _DAT_0073c670 +
                 _DAT_0073c674 * _DAT_0073c674 + _DAT_0073c678 * _DAT_0073c678);
    _DAT_0073c678 = -(local_34 * fVar1);
    fVar2 = _K_ONE / (ABS(_DAT_0073c670) + ABS(_DAT_0073c674));
    _DAT_0073c670 = _DAT_0073c670 * fVar2 * fVar1 * local_38;
    _DAT_0073c674 = fVar2 * _DAT_0073c674 * fVar1 * local_38;
  }
  if (_DAT_0073c678 == 0.0) {
    DAT_007306b4 = 0.0;
    return;
  }
  DAT_007306b4 = _K_ONE / _DAT_0073c678;
  return;
}


// ==== 0x56d870 FUN_0056d870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0056d870(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar3 = (param_2[1] - param_1[1]) * _DAT_006f1acc;
  fVar1 = param_1[1];
  fVar2 = param_2[2];
  *in_EAX = (*param_2 - *param_1) * _DAT_006f1acc + *param_1;
  in_EAX[1] = fVar3 + fVar1;
  in_EAX[2] = fVar2;
  return;
}


// ==== 0x56d8b0 FUN_0056d8b0

undefined4 FUN_0056d8b0(void)

{
  int in_EAX;
  
  if (in_EAX == 0) {
    return 0;
  }
  if ((2 < *(int *)(in_EAX + 4)) && (*(int *)(in_EAX + 4) < 4)) {
    return 1;
  }
  return 0;
}


// ==== 0x56d8d0 FUN_0056d8d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056d8d0(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  char cVar7;
  undefined4 *in_EAX;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fVar11;
  float local_44;
  float local_40;
  float local_38;
  float local_2c;
  int local_28;
  int local_20;
  int local_1c;
  float local_18;
  
  iVar6 = DAT_007355b4;
  iVar2 = *param_1;
  if (iVar2 == 0) {
    local_28 = 0;
  }
  else {
    local_28 = *(int *)(iVar2 + 0x30);
  }
  uVar1 = DAT_007355b4 + 0x40;
  if (DAT_007355b8 <= uVar1) {
    DAT_007355c4 = 1;
    DAT_007355c8 = DAT_007355c8 + 0x40;
    return;
  }
  if (DAT_007355b4 == 0) {
    DAT_007355b4 = uVar1;
    return;
  }
  DAT_007355b4 = uVar1;
  bMatrixCopy_b();
  *(undefined4 *)(iVar6 + 0x30) = *in_EAX;
  *(undefined4 *)(iVar6 + 0x34) = in_EAX[1];
  *(undefined4 *)(iVar6 + 0x38) = in_EAX[2];
  *(undefined4 *)(iVar6 + 0x3c) = 0x3f800000;
  iVar8 = eView__CalcSphereScreenSize(0x40400000);
  if (DAT_007364a0 == 3) {
    iVar8 = _ftol_nocw();
  }
  if (iVar8 < 4) {
    return;
  }
  iVar8 = AABB_ClassifyAgainstFrustum(param_2);
  if (iVar8 == 0) {
    return;
  }
  local_40 = 0.0;
  if ((iVar2 == 0) || (*(int *)(*(int *)(iVar2 + 0x14) + 4) != 3)) {
    local_2c = 0.7;
    local_40 = 1.0;
  }
  else {
    local_2c = 0.85;
  }
  local_38 = local_40;
  if (DAT_007345e4 != 0) {
    param_4 = param_4 | 1;
  }
  if (DAT_007345e8 != 0) {
    param_4 = param_4 | 2;
  }
  if (((param_4 & 1) != 0) || ((iVar2 != 0 && (cVar7 = FUN_005693b0(), cVar7 != '\0')))) {
    local_38 = local_40 + _K_ONE;
  }
  fVar11 = _K_ONE;
  if ((param_4 & 2) == 0) {
    if ((local_28 == 0) || (*(float *)(local_28 + 0x1e4) <= 0.05)) goto LAB_0056daa5;
    fVar11 = *(float *)(local_28 + 0x1e4) * 16.0;
  }
  local_2c = local_2c + fVar11;
LAB_0056daa5:
  if (param_1[1] == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(param_1[1] + 0x71c);
  }
  if (iVar8 == 0) {
    cVar7 = 'x';
  }
  else {
    cVar7 = *(char *)(iVar8 + 0x10);
  }
  piVar3 = (int *)param_1[0x140];
  do {
    if (piVar3 == param_1 + 0x140) {
      return;
    }
    iVar8 = piVar3[2];
    bVar5 = false;
    bVar4 = false;
    local_44 = 0.0;
    if (iVar8 == -0x6246fecd) {
      local_44 = local_38;
      bVar5 = true;
    }
    else if (iVar8 == -0x2f6f6e3a) {
      local_44 = local_38;
      bVar5 = true;
    }
    else {
      fVar11 = local_2c;
      if (iVar8 != 0x31a66786) {
        if (iVar8 == -0x5d5d0384) {
          local_44 = local_2c;
          fVar11 = local_44;
        }
        else {
          fVar11 = local_2c;
          if (iVar8 != -0x408ff587) goto LAB_0056db4c;
        }
      }
      local_44 = fVar11;
      bVar4 = true;
    }
LAB_0056db4c:
    if ((((cVar7 != '\x0e') && (bVar4 = bVar5, cVar7 != '\r')) || (!bVar4)) && (0.0 < local_44)) {
      if (_K_ONE < local_44) {
        local_44 = 1.0;
      }
      if (param_5 == 0) {
        fVar11 = 0.0;
        uVar10 = 0;
        uVar9 = 0;
      }
      else {
        if ((iVar2 == 0) || (2 < *(int *)(iVar2 + 0x3cc))) {
          local_1c = piVar3[5];
          local_20 = piVar3[4];
          local_18 = -(float)piVar3[6];
          D3DXVec3Transform(&local_20,&local_20,iVar6);
          uVar9 = 2;
          fVar11 = local_18;
        }
        else {
          uVar9 = 1;
          fVar11 = 0.0;
        }
        uVar10 = 2;
      }
      FUN_005447c0(param_2,piVar3,local_44,uVar9,uVar10,fVar11);
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


// ==== 0x56dc30 CarRenderInfo::Render

/* WARNING: Removing unreachable block (ram,0x0056f96c) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void CarRenderInfo__Render
               (undefined4 *param_1,int param_2,float *param_3,undefined4 param_4,int param_5,
               int param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10,
               float *param_11)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  undefined2 uVar10;
  int iVar11;
  float *pfVar12;
  uint *puVar13;
  int *piVar14;
  float *pfVar15;
  uint uVar16;
  float *pfVar17;
  undefined4 *puVar18;
  uint uVar19;
  undefined4 *puVar20;
  int unaff_EBX;
  float *pfVar21;
  float *unaff_ESI;
  int iVar22;
  uint uVar23;
  float *pfVar24;
  undefined1 *puVar25;
  float *pfVar26;
  float10 fVar27;
  float fVar28;
  float *pfStack_99c;
  float *pfStack_998;
  int *piStack_994;
  int *piStack_990;
  float *pfStack_98c;
  float *pfStack_988;
  float *pfStack_984;
  undefined4 uStack_974;
  int local_970;
  uint local_96c;
  int iStack_964;
  undefined4 uStack_95c;
  float local_958;
  float *pfStack_954;
  float *local_950 [2];
  float local_948;
  float *local_944;
  float *local_940;
  float *pfStack_93c;
  float *local_938;
  undefined4 uStack_934;
  undefined4 uStack_930;
  undefined4 uStack_92c;
  undefined4 uStack_928;
  undefined4 uStack_924;
  undefined4 uStack_920;
  undefined4 uStack_91c;
  undefined4 uStack_918;
  undefined4 uStack_914;
  int *piStack_90c;
  int iStack_908;
  uint uStack_904;
  float *pfStack_900;
  float *pfStack_8fc;
  float fStack_8f8;
  undefined4 auStack_8f4 [2];
  undefined4 uStack_8ec;
  float fStack_8e0;
  int iStack_8dc;
  float local_8d8;
  undefined4 uStack_8d4;
  undefined1 auStack_8d0 [16];
  float fStack_8c0;
  float fStack_8bc;
  float fStack_8b8;
  undefined4 uStack_8ac;
  undefined4 uStack_8a8;
  int iStack_8a4;
  float fStack_8a0;
  float fStack_89c;
  float fStack_898;
  float fStack_894;
  float afStack_890 [4];
  int iStack_880;
  undefined1 auStack_854 [12];
  undefined1 auStack_848 [8];
  undefined1 auStack_840 [4];
  float fStack_83c;
  float fStack_838;
  undefined4 uStack_834;
  float afStack_830 [6];
  undefined1 auStack_818 [48];
  float fStack_7e8;
  float fStack_7e4;
  float fStack_7e0;
  float afStack_7d0 [16];
  undefined1 auStack_790 [64];
  undefined1 auStack_750 [64];
  undefined1 auStack_710 [52];
  undefined1 auStack_6dc [12];
  float afStack_6d0 [16];
  undefined1 auStack_690 [64];
  undefined1 auStack_650 [52];
  undefined1 auStack_61c [52];
  undefined1 auStack_5e8 [24];
  float afStack_5d0 [29];
  undefined1 auStack_55c [52];
  undefined1 auStack_528 [104];
  float afStack_4c0 [8];
  float afStack_4a0 [33];
  int aiStack_41c [7];
  float afStack_400 [16];
  float afStack_3c0 [39];
  undefined1 auStack_324 [36];
  undefined1 auStack_300 [36];
  float afStack_2dc [182];
  
  pfStack_984 = (float *)0x40400000;
  pfStack_988 = (float *)0x56dc56;
  local_970 = eView__CalcSphereScreenSize();
  if ((DAT_007364a0 == 3) && (DAT_0077a920 != 3)) {
    pfStack_984 = (float *)0x56dc7b;
    local_970 = _ftol_nocw();
    param_11 = (float *)0x1;
    param_10 = 1;
  }
  if (local_970 < 4) {
    return;
  }
  local_948 = (float)*param_1;
  local_958 = *(float *)(param_2 + 0x40);
  local_8d8 = (float)(uint)(DAT_0077a920 == 3);
  if (param_1[2] == 0) {
    local_96c = 0;
  }
  else {
    local_96c = (uint)(*(int *)(param_1[2] + 0xc54) == 2);
  }
  if (DAT_007355b4 + 0x70 < DAT_007355b8) {
    local_940 = DAT_007355b4;
    DAT_007355b4 = DAT_007355b4 + 0x70;
  }
  else {
    DAT_007355c8 = DAT_007355c8 + 0x1c0;
    DAT_007355c4 = 1;
    local_940 = (float *)0x0;
  }
  pfVar15 = DAT_007355b4 + 0x10;
  local_950[0] = DAT_007355b4;
  if (DAT_007355b8 <= DAT_007355b4 + 0x10) {
    DAT_007355c8 = DAT_007355c8 + 0x40;
    DAT_007355c4 = 1;
    local_950[0] = (float *)0x0;
    pfVar15 = DAT_007355b4;
  }
  DAT_007355b4 = pfVar15;
  pfVar15 = local_950[0];
  pfVar12 = DAT_007355b4;
  pfVar17 = DAT_007355b4 + 0x10;
  if (DAT_007355b8 <= DAT_007355b4 + 0x10) {
    DAT_007355c8 = DAT_007355c8 + 0x40;
    DAT_007355c4 = 1;
    pfVar12 = (float *)0x0;
    pfVar17 = DAT_007355b4;
  }
  DAT_007355b4 = pfVar17;
  pfVar17 = DAT_007355b4 + 0x10;
  local_944 = DAT_007355b4;
  if (DAT_007355b8 <= DAT_007355b4 + 0x10) {
    DAT_007355c8 = DAT_007355c8 + 0x40;
    DAT_007355c4 = 1;
    local_944 = (float *)0x0;
    pfVar17 = DAT_007355b4;
  }
  DAT_007355b4 = pfVar17;
  local_938 = DAT_007355b4;
  pfVar17 = DAT_007355b4 + 0x10;
  if (DAT_007355b8 <= DAT_007355b4 + 0x10) {
    DAT_007355c8 = DAT_007355c8 + 0x40;
    DAT_007355c4 = 1;
    local_938 = (float *)0x0;
    pfVar17 = DAT_007355b4;
  }
  DAT_007355b4 = pfVar17;
  if (local_940 == (float *)0x0) {
    return;
  }
  if (local_950[0] == (float *)0x0) {
    return;
  }
  if (local_944 == (float *)0x0) {
    return;
  }
  if (local_938 == (float *)0x0) {
    return;
  }
  pfStack_984 = (float *)0x56de2d;
  bMatrixCopy_b();
  pfStack_988 = (float *)&DAT_0073d720;
  piStack_990 = (int *)0x56de39;
  pfStack_98c = pfVar15;
  pfStack_984 = pfVar15;
  D3DXMatrixMultiply();
  if (param_9 == 0) {
    pfVar15[0xc] = *param_3;
    pfVar15[0xd] = param_3[1];
    pfVar15[0xe] = param_3[2];
    pfVar15[0xf] = 1.0;
  }
  else {
    piStack_990 = (int *)0x56de4c;
    FUN_004406d0();
    fStack_89c = *param_3;
    fStack_898 = param_3[1];
    fStack_894 = param_3[2];
    piStack_990 = (int *)0x0;
    piStack_994 = (int *)0x0;
    pfStack_998 = (float *)0x0;
    pfStack_99c = &fStack_89c;
    fVar27 = (float10)GroundQuery__FindSurfaceBelow(afStack_2dc);
    pfVar15[0xe] = (float)(fVar27 - ((float10)fStack_894 - fVar27));
    pfVar15[0xc] = *param_3;
    pfVar15[0xd] = param_3[1];
    pfVar15[0xf] = 1.0;
    piStack_990 = (int *)0x56deb2;
    RefArray_DecrementAll();
  }
  puVar18 = param_1 + 4;
  piStack_990 = (int *)param_2;
  piStack_994 = (int *)0x56dee8;
  iVar11 = AABB_ClassifyAgainstFrustum();
  if (iVar11 == 0) {
    return;
  }
  uStack_8ac = *(undefined4 *)(iStack_964 + 0x40);
  uStack_8a8 = *(undefined4 *)(iStack_964 + 0x44);
  iStack_8a4 = *(int *)(iStack_964 + 0x48);
  fStack_8a0 = 1.0;
  if (DAT_007345f8 != 0) {
    _DAT_00735544 = 1;
  }
  if (pfStack_954 != (float *)0x0) {
    piStack_990 = (int *)0x56df4a;
    eView__GetMatrixForPlayer();
  }
  piStack_990 = (int *)0x56df58;
  bMatrixCopy_b();
  pfVar12[0xc] = *param_3;
  pfVar12[0xd] = param_3[1];
  pfVar12[0xe] = param_3[2];
  pfVar12[0xf] = 1.0;
  piStack_990 = (int *)0x56df75;
  cVar9 = FUN_004081c0();
  if (cVar9 != '\0') {
    piStack_990 = (int *)0x56df87;
    FUN_00541190();
  }
  piStack_990 = (int *)&DAT_0078ea40;
  piStack_994 = (int *)0x0;
  pfVar15 = afStack_2dc;
  for (iVar11 = 0x70; iVar11 != 0; iVar11 = iVar11 + -1) {
    *pfVar15 = 0.0;
    pfVar15 = pfVar15 + 1;
  }
  pfStack_99c = afStack_2dc;
  pfStack_998 = param_3;
  CarRender_LitBodyPathB();
  FUN_00544390(&DAT_0078ea40,&uStack_8ac,param_2,afStack_2dc);
  param_1[0x13b] = DAT_007364dc;
  piStack_990 = (int *)0x56dff3;
  bVector4Copy();
  piStack_990 = (int *)0x56dff8;
  cVar9 = FUN_004081c0();
  if (cVar9 != '\0') {
    piStack_990 = (int *)0x56e009;
    FUN_00541160();
  }
  if (DAT_007345f8 != 0) {
    _DAT_00735544 = 0;
  }
  piStack_990 = (int *)0x56e024;
  FUN_0056cae0();
  local_948 = 0.0;
  if (pfStack_954 != (float *)0x0) {
    local_948 = pfStack_954[0x21a];
  }
  iVar11 = 0;
  piVar14 = DAT_00734590;
  if (0 < DAT_00734594) {
    do {
      if ((*piVar14 == *(int *)(param_1[2] + 0xc50)) &&
         (piVar14[1] == (int)*(char *)(param_1[1] + 7))) break;
      iVar11 = iVar11 + 1;
      piVar14 = piVar14 + 0x10;
    } while (iVar11 < DAT_00734594);
  }
  uStack_8ec = 0;
  fStack_8c0 = 0.0;
  if ((DAT_00702c84 == 0) || ((float)(int)unaff_ESI < 18.0)) {
    uStack_8ec = 1;
    fStack_8c0 = 1.4013e-45;
  }
  local_958 = (float)(int)unaff_ESI;
  fVar28 = *(float *)(&UNK_006b5dec + (int)param_11 * 4);
  iStack_880 = param_10;
  pfStack_93c = param_11;
  while (local_958 < fVar28) {
    pfStack_93c = (float *)((int)pfStack_93c + 1);
    iStack_880 = iStack_880 + 1;
    fVar28 = *(float *)(&UNK_006b5dec + (int)pfStack_93c * 4);
  }
  if ((int)pfStack_93c < 4) {
    if (2 < (int)pfStack_93c) goto LAB_0056e108;
  }
  else {
    pfStack_93c = (float *)0x3;
LAB_0056e108:
    if (((pfStack_954 != (float *)0x0) && (pfStack_954[0xf3] == 0.0)) &&
       (*(char *)(param_1 + 0x766) != '\0')) {
      pfStack_93c = (float *)0x2;
    }
  }
  if (DAT_006f1b30 != (float *)0xffffffff) {
    pfStack_93c = DAT_006f1b30;
  }
  pfVar15 = pfStack_93c;
  if (DAT_006f1b34 != -1) {
    iStack_880 = DAT_006f1b34;
  }
  if ((pfStack_93c == (float *)0xffffffff) && (iStack_880 == -1)) {
    return;
  }
  piStack_990 = (int *)0x56e197;
  FUN_00565060();
  piStack_990 = aiStack_41c;
  pfStack_998 = afStack_830 + 1;
  pfStack_99c = (float *)0x56e1b1;
  piStack_994 = (int *)(iStack_964 + 0x40);
  D3DXVec3Transform();
  pfStack_99c = (float *)0x56e1bf;
  fVar27 = (float10)bDistance3();
  fVar28 = (float)fVar27;
  if (((pfVar15 == (float *)0x0) && (fVar28 < 4.0)) && (*(int *)(param_2 + 4) == 1)) {
    afStack_830[0] = afStack_830[0] + _K_HALF;
    pfStack_99c = pfVar15;
    iVar11 = FUN_00567940();
    if (iVar11 != 0) {
      return;
    }
    afStack_830[0] = afStack_830[0] - _K_HALF;
  }
  iVar11 = uStack_95c;
  pfStack_99c = (float *)0x56e238;
  bMatrixCopy_b();
  pfVar12 = local_950[0];
  pfStack_99c = (float *)0x56e24a;
  bMatrix4_SetRotationAndTranslation();
  *(float *)(iVar11 + 0x38) = *(float *)(iVar11 + 0x38) + 0.01;
  pfVar15 = (float *)((fVar28 - 0.0) / fVar28);
  pfStack_99c = pfVar15;
  Car_ScaleMatrixTowardCamera();
  pfStack_99c = pfVar15;
  Car_ScaleMatrixTowardCamera();
  pfStack_99c = (float *)0x56e293;
  eIdentity();
  fStack_7e8 = -*param_3;
  pfStack_99c = pfVar12;
  fStack_7e4 = -param_3[1];
  fStack_7e0 = -param_3[2];
  D3DXMatrixMultiply(pfVar12,auStack_818);
  uVar10 = 0;
  if (pfStack_984 != (float *)0x0) {
    uVar10 = *(undefined2 *)(pfStack_984 + 0x74);
  }
  CarPartCuller__CullParts(param_1 + 0x700,uVar10);
  _DAT_0073cab4 = param_3[1];
  DAT_0073cab8 = param_3[2];
  pfStack_988 = (float *)(uint)(param_1[0x416] != 0);
  _DAT_0073cab0 = *param_3;
  local_948 = (float)(uint)(0 < (int)pfStack_954);
  if (local_96c == 0) {
    pfVar12 = (float *)0x0;
    pfStack_984 = (float *)0x0;
  }
  else {
    pfVar12 = (float *)(local_96c + 0x540);
    pfStack_984 = pfVar12;
    if (pfVar12 != (float *)0x0) {
      fVar27 = (float10)GroundQuery__FindSurfaceBelow(pfVar12,&DAT_0073cab0,0,&DAT_0073c660,0);
      DAT_0073cab8 = (float)fVar27;
    }
  }
  uStack_834 = 0;
  afStack_830[0] = 0.0;
  afStack_830[1] = 0.0;
  D3DXVec3Transform(&uStack_834,&uStack_834,uStack_974);
  iVar11 = iStack_908;
  fVar27 = (float10)0.0;
  if (iStack_908 == 0) {
    fVar27 = (float10)GroundQuery__FindSurfaceBelow(pfVar12,auStack_840,0,0,0);
    fVar27 = (float10)fStack_838 - fVar27;
  }
  fVar28 = 0.0;
  if ((fVar27 <= (float10)0.0) || ((float10)3.0 <= fVar27)) {
    if ((float10)3.0 < fVar27) {
      fVar28 = 1.0;
    }
  }
  else {
    fVar28 = (float)((fVar27 - (float10)0.0) / ((float10)3.0 - (float10)0.0));
  }
  fVar27 = (float10)bClampF(fVar28,0,0x3f800000);
  fVar28 = (float)fVar27;
  if (DAT_007345e0 != 0.0) {
    fVar28 = DAT_007345e0;
  }
  if (local_96c == 0) {
    iVar22 = 0;
  }
  else {
    iVar22 = *(int *)(local_96c + 0x3c);
  }
  if (((((param_9 == 0) && ((int)puVar18 < 3)) && (iVar11 == 0)) &&
      ((iVar22 != 0 && (DAT_006f1ac8 != 0)))) &&
     (((1 < DAT_00700e7c && ((param_1[0x12e] != 0 && (pfStack_99c == (float *)0x0)))) &&
      (cVar9 = FUN_0056d8b0(), cVar9 == '\0')))) {
    fStack_8bc = pfStack_984[1];
    fStack_8c0 = *pfStack_984;
    fStack_8b8 = pfStack_984[2];
    fStack_8a0 = *pfStack_98c;
    fStack_89c = pfStack_98c[1];
    fStack_898 = pfStack_98c[2];
    D3DXVec3Transform(&fStack_8c0,&fStack_8c0,pfVar15);
    D3DXVec3Transform(&uStack_8ac,&uStack_8ac,pfVar15);
    pfStack_988 = *(float **)(iVar22 + 0x10);
    pfVar12 = *(float **)((int)pfStack_988 + 0x14);
    pfStack_99c = pfVar12;
    FUN_0056d700();
    FUN_00540b40();
    Struct_ClearHeader();
    fVar3 = param_3[2];
    iVar11 = 0;
    piStack_90c = DAT_007306b4;
    pfVar17 = (float *)&DAT_0073c260;
    if (0 < (int)pfVar12) {
      do {
        (**(code **)((int)pfStack_988 + 0xc))(pfStack_988,iVar11,local_950);
        fStack_8f8 = (float)local_938 + 0.275;
        pfStack_900 = local_940;
        pfStack_8fc = pfStack_93c;
        FUN_00540ae0(local_940,pfStack_93c,fStack_8f8,auStack_8f4[0]);
        iVar22 = FUN_00540990();
        pfStack_998 = (float *)-((*(float *)(iVar22 + 8) - fVar3) * (float)piStack_90c);
        pfVar12 = (float *)FUN_00540930();
        *pfVar17 = (float)pfStack_998 * _DAT_0073c670 + *pfVar12;
        iVar22 = FUN_00540960();
        iVar11 = iVar11 + 1;
        pfVar17[1] = (float)pfStack_998 * _DAT_0073c674 + *(float *)(iVar22 + 4);
        pfVar17 = pfVar17 + 4;
      } while (iVar11 < (int)pfStack_99c);
    }
    FUN_0056cf10(&DAT_0073c260,&pfStack_99c,piStack_990,DAT_0073cab8 + 0.06,0x3d75c28f,pfStack_954);
    if ((puVar18 == (undefined4 *)0x0) || (DAT_00734644 == 0)) {
      pfStack_99c = (float *)FUN_0056d0c0(pfStack_99c);
      pfVar12 = (float *)&DAT_0073cac0;
    }
    else {
      pfVar12 = (float *)&DAT_0073c680;
    }
    pfStack_988 = pfVar12;
    if (2 < (int)pfStack_99c) {
      pfVar17 = pfVar12 + ((int)pfStack_99c / 2) * 4;
      fStack_8f8 = pfVar12[2] + pfVar17[2];
      fStack_8e0 = (*pfVar12 + *pfVar17) * _K_HALF;
      iStack_8dc = (int)((pfVar12[1] + pfVar17[1]) * _K_HALF);
      local_8d8 = fStack_8f8 * _K_HALF;
      _DAT_006f1acc = fVar28 * -0.29999995 + 1.4;
      iVar11 = _ftol_nocw();
      if (iVar11 < 1) {
        iVar11 = 0;
      }
      else if (0xfe < iVar11) {
        iVar11 = 0xfe;
      }
      uVar23 = iVar11 << 0x18 | 0x808080;
      if (DAT_006f1d08 != 0) {
        pfVar17 = (float *)(((uint)pfStack_99c & 0xfffffffe) - 1);
        pfStack_998 = (float *)0x0;
        pfStack_954 = pfVar17;
        if (0 < (int)pfVar17) {
          do {
            cVar9 = FUN_004107e0(param_1[0x12e],4);
            if (cVar9 != '\0') {
              ImmBuf_PushPosition();
              ImmBuf_PushPosition();
              ImmBuf_PushPosition();
              ImmBuf_PushPosition();
              ImmBuf_PushColor(uVar23);
              ImmBuf_PushColor(uVar23);
              ImmBuf_PushColor(uVar23);
              ImmBuf_PushColor(uVar23);
              ImmBuf_PushTexCoord(0x3e1eb852,0);
              ImmBuf_PushTexCoord(0,0);
              ImmBuf_PushTexCoord(0x3e1eb852,0);
              ImmBuf_PushTexCoord(0x3e1eb852,0);
              RenderQueue_SelectDefaultBucket(param_2);
              pfVar17 = pfStack_954;
            }
            pfStack_998 = (float *)((int)pfStack_998 + 2);
          } while ((int)pfStack_998 < (int)pfVar17);
        }
        if ((((uint)pfStack_99c & 1) != 0) &&
           (cVar9 = FUN_004107e0(param_1[0x12e],3), cVar9 != '\0')) {
          ImmBuf_PushPosition();
          ImmBuf_PushPosition();
          ImmBuf_PushPosition();
          ImmBuf_PushColor(uVar23);
          ImmBuf_PushColor(uVar23);
          ImmBuf_PushColor(uVar23);
          ImmBuf_PushTexCoord(0x3e1eb852,0);
          ImmBuf_PushTexCoord(0,0);
          ImmBuf_PushTexCoord(0x3e1eb852,0);
          RenderQueue_SelectDefaultBucket(param_2);
        }
        pfVar17 = (float *)((int)pfStack_99c / 3);
        uStack_904 = (int)pfVar17 * 0x10;
        local_958 = 0.0;
        piStack_90c = (int *)-(int)pfVar17;
        piStack_990 = (int *)0x0;
        pfStack_998 = pfStack_99c;
        unaff_ESI = pfVar12;
        pfStack_954 = pfVar17;
        do {
          local_958 = (float)((int)local_958 + 1);
          pfVar12 = pfStack_998;
          if ((int)local_958 < 3) {
            pfVar12 = pfVar17;
          }
          cVar9 = FUN_004107e0(param_1[0x12e],(int)pfVar12 * 2 + 2);
          if (cVar9 != '\0') {
            if ((int)piStack_990 < (int)pfVar12 + (int)piStack_990) {
              iStack_964 = ((int)pfVar12 + (int)piStack_990) - (int)piStack_990;
              do {
                puVar13 = (uint *)FUN_0056d870();
                pfStack_8fc = (float *)puVar13[1];
                pfStack_900 = (float *)*puVar13;
                fStack_8f8 = (float)puVar13[2];
                ImmBuf_PushPosition();
                ImmBuf_PushPosition();
                ImmBuf_PushColor2(uVar23);
                ImmBuf_PushColor2(uVar23);
                ImmBuf_PushTexCoord(0x3e1eb852,0);
                ImmBuf_PushTexCoord(0x3f800000,0);
                iStack_964 = iStack_964 + -1;
              } while (iStack_964 != 0);
            }
            puVar13 = (uint *)FUN_0056d870();
            pfStack_8fc = (float *)puVar13[1];
            pfStack_900 = (float *)*puVar13;
            fStack_8f8 = (float)puVar13[2];
            ImmBuf_PushPosition();
            ImmBuf_PushPosition();
            ImmBuf_PushColor2(uVar23);
            ImmBuf_PushColor2(uVar23);
            ImmBuf_PushTexCoord(0x3e1eb852,0);
            ImmBuf_PushTexCoord(0x3f800000,0);
            RenderQueue_SelectDefaultBucket(param_2);
            pfVar17 = pfStack_954;
          }
          piStack_990 = (int *)((int)piStack_990 + (int)pfVar17);
          unaff_ESI = (float *)((int)unaff_ESI + uStack_904);
          pfStack_998 = (float *)((int)pfStack_998 + (int)piStack_90c);
        } while ((int)local_958 < 3);
      }
    }
  }
  if (((DAT_00700e7c == 0) || (piStack_994 == (int *)0x0)) || (param_9 != 0)) goto LAB_0056f475;
  if (iStack_908 == 0) {
    fStack_89c = 1.05;
    fStack_8a0 = 1.05;
  }
  else {
    fStack_89c = 1.0;
    fStack_8a0 = 1.115;
  }
  piStack_990 = (int *)(fVar28 * 0.75 + _K_ONE);
  fStack_8bc = pfStack_984[1] * (float)piStack_990 * fStack_89c;
  fStack_89c = pfStack_98c[1] * (float)piStack_990 * fStack_89c;
  fStack_8c0 = *pfStack_984 * (float)piStack_990 * fStack_8a0;
  fStack_8a0 = *pfStack_98c * (float)piStack_990 * fStack_8a0;
  CallNTimes(afStack_400,0x10,0x10,FUN_004ad8d0);
  CallNTimes(afStack_4c0,8,0x10,FUN_004ad8d0);
  local_950[0] = (float *)0x2;
  local_958 = (fStack_89c - fStack_8bc) * 0.33333334;
  local_950[1] = (float *)0x2;
  local_940 = (float *)0x2;
  pfStack_93c = (float *)0x2;
  iStack_8dc = 0;
  local_8d8 = 0.0;
  piStack_994 = (int *)((fStack_8a0 - fStack_8c0) * 0.33333334);
  uStack_930 = 3;
  uStack_92c = 3;
  uStack_920 = 3;
  uStack_91c = 3;
  fStack_8e0 = 0.0;
  uStack_928 = 0;
  uStack_924 = 0;
  uStack_918 = 0;
  uStack_914 = 0;
  uStack_8d4 = 0;
  local_948 = 1.4013e-45;
  local_944 = (float *)0x1;
  local_938 = (float *)0x1;
  uStack_934 = 1;
  pfStack_984 = (float *)fStack_8bc;
  pfStack_998 = (float *)0x0;
  pfVar12 = afStack_400;
  pfVar17 = afStack_4c0;
  iStack_964 = 4;
  do {
    pfStack_98c = (float *)0x0;
    iVar11 = 4;
    pfStack_988 = (float *)fStack_8c0;
    do {
      *pfVar12 = (float)pfStack_988;
      pfVar12[1] = (float)pfStack_984;
      pfVar12[2] = 0.0;
      *pfVar17 = (float)pfStack_98c;
      pfVar17[1] = (float)pfStack_998;
      D3DXVec3Transform(pfVar12,pfVar12,pfVar15);
      pfStack_988 = (float *)((float)pfStack_988 + (float)piStack_994);
      pfVar12[2] = param_3[2];
      pfVar12 = pfVar12 + 4;
      pfVar17 = pfVar17 + 2;
      iVar11 = iVar11 + -1;
      pfStack_98c = (float *)((float)pfStack_98c + 0.33333334);
    } while (iVar11 != 0);
    iStack_964 = iStack_964 + -1;
    pfStack_984 = (float *)((float)pfStack_984 + local_958);
    pfStack_998 = (float *)((float)pfStack_998 + 0.33333334);
  } while (iStack_964 != 0);
  pfStack_900 = (float *)0x0;
  pfStack_8fc = (float *)0x0;
  fStack_8f8 = 0.0;
  D3DXVec3Transform(&pfStack_900,&pfStack_900,pfVar15);
  iVar11 = 0;
  if (unaff_EBX == 0) {
    pfStack_998 = (float *)0x0;
  }
  else {
    pfStack_998 = (float *)(unaff_EBX + 0x540);
  }
  if ((iStack_908 == 0) && (pfStack_998 != (float *)0x0)) {
    CallNTimes(afStack_890,0x10,4,FUN_004ad8d0);
    CallNTimes(afStack_830,0x10,4,FUN_004ad8d0);
    pfStack_98c = (float *)0x0;
    pfStack_984 = (float *)0x0;
    do {
      iVar22 = FUN_0057f130();
      D3DXVec3Transform((int)afStack_890 + iVar11,(int)pfStack_984 + 0x10 + iVar22,pfVar15);
      fVar27 = (float10)GroundQuery__FindSurfaceBelow
                                  (pfStack_998,(int)afStack_890 + iVar11,0,(int)afStack_830 + iVar11
                                   ,(int)&piStack_994 + (int)pfStack_98c);
      *(float *)((int)afStack_890 + iVar11 + 8) = (float)fVar27;
      Vec3_Scale(-1.0 / *(float *)((int)afStack_830 + iVar11 + 8));
      pfStack_984 = (float *)((int)pfStack_984 + 0x30);
      pfStack_98c = (float *)((int)pfStack_98c + 1);
      iVar11 = iVar11 + 0x10;
    } while ((int)pfStack_984 < 0xc0);
    iVar11 = 0;
    pfVar12 = afStack_400 + 2;
    do {
      fVar27 = (float10)GroundQuery__FindSurfaceBelow
                                  (pfStack_998,pfVar12 + -2,0,0,(int)&uStack_95c + 3);
      *pfVar12 = (float)fVar27;
      cVar9 = uStack_95c._3_1_;
      if ((uStack_95c._3_1_ == '\0') &&
         (pfVar17 = local_950[iVar11], *(char *)((int)&piStack_994 + (int)pfVar17) != '\0')) {
        cVar9 = '\x01';
        uStack_95c = CONCAT13(1,(undefined3)uStack_95c);
        *pfVar12 = (pfVar12[-2] - afStack_890[(int)pfVar17 * 4]) * afStack_830[(int)pfVar17 * 4] +
                   (pfVar12[-1] - afStack_890[(int)pfVar17 * 4 + 1]) *
                   afStack_830[(int)pfVar17 * 4 + 1] + afStack_890[(int)pfVar17 * 4 + 2];
      }
      if ((((byte)(iVar11 >> 1) ^ (byte)iVar11) & 5) == 5) {
        *pfVar12 = *pfVar12 + 0.08;
      }
      if (((cVar9 == '\0') || (cVar9 = FUN_0056ce90(*pfVar12,DAT_0073cab8), cVar9 == '\0')) ||
         (cVar9 = FUN_0056ceb0(), cVar9 == '\0')) {
        iVar22 = (int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2;
        (&fStack_8e0)[iVar22] = (float)((int)(&fStack_8e0)[iVar22] + 1);
        fVar3 = fStack_8f8;
      }
      else {
        fStack_8f8 = *pfVar12;
        fVar3 = *pfVar12;
      }
      *pfVar12 = fVar3 + 0.04;
      iVar11 = iVar11 + 1;
      pfVar12 = pfVar12 + 4;
    } while (iVar11 < 0x10);
  }
  else {
    iVar11 = 0;
    pfVar12 = afStack_400 + 2;
    do {
      *pfVar12 = DAT_006f1ad4;
      if ((((byte)(iVar11 >> 1) ^ (byte)iVar11) & 5) == 5) {
        *pfVar12 = *pfVar12 + 0.08;
      }
      iVar11 = iVar11 + 1;
      pfVar12 = pfVar12 + 4;
    } while (iVar11 < 0x10);
  }
  iVar11 = iStack_908;
  pfStack_988 = (float *)(_K_ONE - fVar28);
  fVar27 = (float10)bClampF(pfVar15[10],0,0x3f800000);
  local_958 = (float)(fVar27 * (float10)(float)pfStack_988);
  piStack_994 = (int *)((-(uint)(iVar11 != 0) & 0xffffffea) + 0x72);
  iVar11 = _ftol_nocw();
  if (iVar11 < 1) {
    iVar11 = 0;
  }
  else if (0xfe < iVar11) {
    iVar11 = 0xfe;
  }
  piStack_90c = (int *)(iVar11 << 0x18 | 0x808080);
  iVar11 = DAT_0073ad34;
  if (DAT_0077a920 == 3) {
    iVar11 = DAT_0073ad3c;
  }
  piStack_990 = (int *)((float)iVar11 * 0.00025);
  FUN_00564bb0((float)piStack_990 * 4.7);
  piStack_994 = (int *)(int)*(short *)(param_1 + 0x132);
  iVar11 = _ftol_nocw();
  piStack_994 = (int *)(int)*(short *)((int)param_1 + 0x4ca);
  uVar23 = iVar11 + *(short *)(param_1 + 0x130);
  iVar11 = _ftol_nocw();
  uStack_904 = iVar11 + *(short *)((int)param_1 + 0x4c2);
  piStack_994 = (int *)(int)*(short *)(param_1 + 0x133);
  iVar11 = _ftol_nocw();
  pfStack_954 = (float *)(iVar11 + *(short *)(param_1 + 0x131));
  fVar27 = (float10)FUN_00564bb0((float)piStack_990 * 7.2);
  piStack_994 = (int *)(float)ABS(fVar27);
  FUN_00564bb0((float)piStack_990 * 6.1);
  iVar11 = _ftol_nocw();
  piStack_994 = (int *)(int)*(short *)((int)param_1 + 0x4ce);
  iVar22 = _ftol_nocw();
  piStack_994 = (int *)(iVar11 + iVar22 + (int)*(short *)((int)param_1 + 0x4c6));
  iVar11 = _ftol_nocw();
  if ((int)uVar23 < 1) {
    uVar23 = 0;
  }
  else if (0xfe < (int)uVar23) {
    uVar23 = 0xfe;
  }
  if ((int)uStack_904 < 1) {
    uVar16 = 0;
LAB_0056f1b0:
    uVar19 = uVar16;
  }
  else {
    uVar19 = 0xfe;
    uVar16 = uStack_904;
    if ((int)uStack_904 < 0xff) goto LAB_0056f1b0;
  }
  if ((int)pfStack_954 < 1) {
    pfVar12 = (float *)0x0;
  }
  else {
    pfVar12 = pfStack_954;
    if (0xfe < (int)pfStack_954) {
      pfVar12 = (float *)0xfe;
    }
  }
  if (iVar11 < 1) {
    iVar11 = 0;
  }
  else if (0xfe < iVar11) {
    iVar11 = 0xfe;
  }
  piStack_994 = (int *)(((iVar11 << 8 | (uint)pfVar12) << 8 | uVar19) << 8 | uVar23);
  pfStack_984 = (float *)0x0;
  do {
    if (pfStack_984 == (float *)0x0) {
      pfStack_988 = (float *)param_1[0x12d];
      piStack_990 = piStack_90c;
    }
    else {
      pfStack_988 = (float *)param_1[0x12f];
      piStack_990 = piStack_994;
    }
    if ((pfStack_988 != (float *)0x0) && (((uint)piStack_990 & 0xff000000) != 0)) {
      pfVar12 = afStack_400;
      pfVar15 = afStack_3c0;
      pfStack_99c = afStack_4c0;
      pfStack_998 = afStack_4a0;
      pfStack_98c = (float *)0x0;
      do {
        if ((&iStack_8dc)[(int)pfStack_98c] + (int)(&fStack_8e0)[(int)pfStack_98c] < 4) {
          cVar9 = FUN_004107e0(pfStack_988,8);
          if (cVar9 != '\0') {
            pfVar17 = (float *)(DAT_007363bc + DAT_007363cc * 6 + 6);
            unaff_ESI = (float *)(DAT_007363bc + DAT_007363cc * 6 + 5);
            pfVar21 = (float *)(DAT_007363bc + DAT_007363c8 * 6 + 3);
            pfVar26 = (float *)(DAT_007363bc + DAT_007363c8 * 6 + 2);
            pfVar24 = (float *)(DAT_007363bc + DAT_007363c8 * 6 + 1);
            iStack_964 = 4;
            do {
              *pfVar24 = *pfVar12;
              *pfVar26 = pfVar12[1];
              *pfVar21 = pfVar12[2];
              DAT_007363c8 = DAT_007363c8 + 1;
              ImmBuf_PushColor2(piStack_990);
              fVar28 = pfStack_99c[1];
              *unaff_ESI = *pfStack_99c;
              *pfVar17 = fVar28;
              DAT_007363cc = DAT_007363cc + 1;
              pfVar24[6] = *pfVar15;
              pfVar26[6] = pfVar15[1];
              pfVar21[6] = pfVar15[2];
              DAT_007363c8 = DAT_007363c8 + 1;
              pfVar24 = pfVar24 + 0xc;
              pfVar26 = pfVar26 + 0xc;
              pfVar21 = pfVar21 + 0xc;
              ImmBuf_PushColor2(piStack_990);
              fVar28 = pfStack_998[1];
              unaff_ESI[6] = *pfStack_998;
              pfVar17[6] = fVar28;
              piVar14 = DAT_007363bc;
              unaff_ESI = unaff_ESI + 0xc;
              DAT_007363cc = DAT_007363cc + 1;
              pfVar17 = pfVar17 + 0xc;
              pfVar12 = pfVar12 + 4;
              pfVar15 = pfVar15 + 4;
              pfStack_998 = pfStack_998 + 2;
              pfStack_99c = pfStack_99c + 2;
              iStack_964 = iStack_964 + -1;
            } while (iStack_964 != 0);
            *DAT_007363bc = DAT_007363c8;
            RenderQueue_GetBucket(piVar14,0,&DAT_0078a4a0,0,0);
          }
        }
        else {
          pfVar12 = pfVar12 + 0x10;
          pfVar15 = pfVar15 + 0x10;
          pfStack_99c = pfStack_99c + 8;
          pfStack_998 = pfStack_998 + 8;
        }
        pfStack_98c = (float *)((int)pfStack_98c + 1);
      } while ((int)pfStack_98c < 3);
    }
    pfStack_984 = (float *)((int)pfStack_984 + 1);
  } while ((int)pfStack_984 < 2);
LAB_0056f475:
  pfStack_988 = (float *)param_1[0x139];
  piStack_994 = (int *)param_1[0x134];
  if (pfStack_988 == (float *)0x0) {
    pfStack_988 = (float *)piStack_994;
  }
  local_958 = (float)param_1[0x135];
  iStack_964 = 0;
  do {
    switch(iStack_964) {
    case 3:
    case 4:
      if (((param_9 == 0) && ((int)puVar18 < 2)) &&
         ((local_96c == 0 || ((*(uint *)(local_96c + 0xe0) >> ((iStack_964 != 3) << 1) & 3) < 2))))
      {
        Solid_ReplaceTextureForHash();
        FUN_0040c910(param_2,param_1 + iStack_964 * 0x18 + (int)puVar18 * 6 + 0x39b,uStack_974,
                     local_970,0);
      }
      break;
    default:
      if ((*(byte *)(iStack_964 + 0x6a4 + param_1[1]) & 1) != 0) {
        pfVar12 = pfStack_988;
        if (iStack_964 != 0xb) {
          pfVar12 = (float *)piStack_994;
        }
        puVar20 = param_1 + iStack_964 * 0x18 + (int)puVar18 * 6 + 0x39b;
        iVar11 = puVar20[3];
        if ((iVar11 != 0) && (pfVar12 != (float *)0x0)) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == -0x2929f7f6) {
                piVar14[1] = (int)pfVar12;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if ((iVar11 != 0) && (local_958 != 0.0)) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == 0x471a1dca) {
                piVar14[1] = (int)local_958;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        FUN_0040c910(param_2,puVar20,uStack_974,local_970,0);
      }
      break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
      break;
    }
    iStack_964 = iStack_964 + 1;
  } while (iStack_964 < 0x1e);
  if (((int)puVar18 < 2) || (param_9 != 0)) {
    local_950[0] = (float *)0x3f800000;
    local_950[1] = (float *)0x0;
    local_948 = 0.0;
    local_944 = (float *)0x0;
    local_940 = (float *)0x0;
    pfStack_93c = (float *)0x3f800000;
    local_938 = (float *)0x0;
    uStack_934 = 0;
    uStack_930 = 0;
    uStack_92c = 0;
    uStack_928 = 0x3f800000;
    uStack_924 = 0;
    uStack_920 = 0;
    uStack_91c = 0;
    uStack_918 = 0;
    uStack_914 = 0x3f800000;
    FUN_0040ba40(local_950,local_950);
    iVar11 = param_1[0x137];
    if ((iVar11 != 0) && (iVar22 = param_1[0x506], iVar22 != 0)) {
      piVar14 = *(int **)(iVar22 + 0x3c);
      iVar22 = (int)*(char *)(iVar22 + 0x1a);
      if (0 < iVar22) {
        do {
          if (*piVar14 == 0x3b3a1f8d) {
            piVar14[1] = iVar11;
          }
          piVar14 = piVar14 + 2;
          iVar22 = iVar22 + -1;
        } while (iVar22 != 0);
      }
    }
    puVar20 = (undefined4 *)param_1[0x19f];
    pfVar12 = DAT_007355b4;
    if (puVar20 != param_1 + 0x19f) {
      do {
        pfVar17 = pfVar12 + 0x10;
        if (pfVar17 < DAT_007355b8) {
          DAT_007355b4 = pfVar17;
          if (pfVar12 != (float *)0x0) {
            D3DXMatrixMultiply(pfVar12,local_950,puVar20[4] + 0x10);
            D3DXMatrixMultiply(pfVar12,pfVar12,pfVar15);
            FUN_0040c910(param_2,param_1 + 0x503,pfVar12,local_970,0);
            pfVar17 = DAT_007355b4;
          }
        }
        else {
          DAT_007355c8 = DAT_007355c8 + 0x40;
          DAT_007355c4 = 1;
          pfVar17 = pfVar12;
        }
        puVar20 = (undefined4 *)*puVar20;
        pfVar12 = pfVar17;
      } while (puVar20 != param_1 + 0x19f);
    }
  }
  if (((int)puVar18 < 3) || (param_9 != 0)) {
    local_950[0] = (float *)0x3f800000;
    local_950[1] = (float *)0x0;
    local_948 = 0.0;
    local_944 = (float *)0x0;
    local_940 = (float *)0x0;
    pfStack_93c = (float *)0x3f800000;
    local_938 = (float *)0x0;
    uStack_934 = 0;
    uStack_930 = 0;
    uStack_92c = 0;
    uStack_928 = 0x3f800000;
    uStack_924 = 0;
    uStack_920 = 0;
    uStack_91c = 0;
    uStack_918 = 0;
    uStack_914 = 0x3f800000;
    FUN_0040ba40(local_950,local_950);
    piVar14 = (int *)param_1[0x1c1];
    piStack_994 = param_1 + 0x1c1;
    pfVar12 = DAT_007355b4;
    if (piVar14 != piStack_994) {
      do {
        if ((local_96c == 0) || (pfVar17 = pfVar12, (*(uint *)(local_96c + 0xe0) >> 6 & 3) < 2)) {
          pfVar17 = pfVar12 + 0x10;
          if (pfVar17 < DAT_007355b8) {
            DAT_007355b4 = pfVar17;
            if (pfVar12 != (float *)0x0) {
              D3DXMatrixMultiply(pfVar12,local_950,piVar14[4] + 0x10);
              D3DXMatrixMultiply(pfVar12,pfVar12,pfVar15);
              FUN_0040c910(param_2,param_1 + 0x54b,pfVar12,local_970,0);
              pfVar17 = DAT_007355b4;
            }
          }
          else {
            DAT_007355c8 = DAT_007355c8 + 0x40;
            DAT_007355c4 = 1;
            pfVar17 = pfVar12;
          }
        }
        piVar14 = (int *)*piVar14;
        pfVar12 = pfVar17;
      } while (piVar14 != piStack_994);
    }
  }
  fVar8 = _DAT_006f1ccc;
  fVar7 = _DAT_006f1cc8;
  fVar28 = (float)param_1[0x150];
  fVar3 = _K_ONE / _DAT_006f1ccc;
  pfVar12 = (float *)(param_1 + 0x14c);
  pfStack_98c = (float *)(param_1 + (*(int *)(param_1[1] + 0x464) != 0) + 0x144);
  iVar11 = 0;
  puVar20 = (undefined4 *)(param_6 + 0x34);
  do {
    fVar1 = *pfVar12;
    fVar4 = *pfStack_98c;
    fVar6 = fVar1 * fVar7;
    if (fVar1 == 0.0) {
      fVar1 = fVar8;
    }
    fVar1 = fVar1 * fVar3;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 4) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 8) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0xc) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x10) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x18) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x1c) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x20) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x24) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x2c) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x30) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x34) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x38) = 0;
    *(undefined4 *)((int)afStack_7d0 + iVar11) = 0x3f800000;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x14) = 0x3f800000;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x28) = 0x3f800000;
    *(undefined4 *)((int)afStack_7d0 + iVar11 + 0x3c) = 0x3f800000;
    *(float *)((int)afStack_7d0 + iVar11 + 0x14) = fVar1;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 4) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 8) = 0;
    *(float *)((int)afStack_7d0 + iVar11 + 0x34) = -fVar6;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0xc) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x10) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x18) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x1c) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x20) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x24) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x2c) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x30) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x34) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x38) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 4) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 8) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0xc) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x10) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x18) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x1c) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x20) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x24) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x2c) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x30) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x34) = 0;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x38) = 0;
    *(undefined4 *)((int)afStack_5d0 + iVar11) = 0x3f800000;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x14) = 0x3f800000;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x28) = 0x3f800000;
    *(undefined4 *)((int)afStack_5d0 + iVar11 + 0x3c) = 0x3f800000;
    *(undefined4 *)((int)afStack_6d0 + iVar11) = 0x3f800000;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x14) = 0x3f800000;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x28) = 0x3f800000;
    *(undefined4 *)((int)afStack_6d0 + iVar11 + 0x3c) = 0x3f800000;
    if (0.0 <= fVar4) {
      fVar5 = fVar4 - fVar6;
    }
    else {
      fVar5 = fVar6 + fVar4;
    }
    *(float *)((int)afStack_5d0 + iVar11 + 0x34) = -fVar5;
    fVar1 = fVar28 * fVar1;
    if (fVar28 == 0.0) {
      fVar1 = fVar6;
    }
    if (0.0 <= fVar4) {
      fVar1 = fVar4 - fVar1;
    }
    else {
      fVar1 = fVar1 + fVar4;
    }
    *(undefined4 *)((int)puVar20 + (param_5 - param_6)) = 0;
    *(float *)((int)afStack_6d0 + iVar11 + 0x34) = -fVar1;
    *puVar20 = 0;
    pfStack_98c = pfStack_98c + 2;
    iVar11 = iVar11 + 0x40;
    pfVar12 = pfVar12 + 1;
    puVar20 = puVar20 + 0x10;
  } while (iVar11 < 0x100);
  pfStack_988 = (float *)0x0;
  pfStack_98c = (float *)0x0;
  pfStack_984 = (float *)0x0;
  pfStack_998 = (float *)0x0;
  pfStack_99c = (float *)0x0;
  if ((*(char *)(param_1[1] + 0x6b5) != '\0') && ((int)puVar18 < 3)) {
    pfVar12 = DAT_007355b4 + 0x40;
    pfVar17 = DAT_007355b4;
    if (DAT_007355b8 <= DAT_007355b4 + 0x40) {
      DAT_007355c8 = DAT_007355c8 + 0x100;
      DAT_007355c4 = 1;
      pfVar12 = DAT_007355b4;
      pfVar17 = (float *)0x0;
    }
    DAT_007355b4 = pfVar12;
    pfVar12 = DAT_007355b4 + 0x1c0;
    pfStack_99c = DAT_007355b4;
    if (DAT_007355b8 <= DAT_007355b4 + 0x1c0) {
      DAT_007355c8 = DAT_007355c8 + 0x700;
      DAT_007355c4 = 1;
      pfStack_99c = (float *)0x0;
      pfVar12 = DAT_007355b4;
    }
    DAT_007355b4 = pfVar12;
    if ((pfVar17 != (float *)0x0) && (pfStack_99c != (float *)0x0)) {
      pfStack_98c = (float *)(uint)*(byte *)(param_1 + 0x70e);
      bVar2 = *(byte *)(param_1 + 0x706);
      pfStack_984 = (float *)(uint)*(byte *)(param_1 + 0x716);
      pfStack_998 = (float *)(uint)*(byte *)(param_1 + 0x71e);
      iVar11 = iStack_8a4;
      if (2 < iStack_8a4) {
        iVar11 = 2;
      }
      local_950[0] = (float *)0x3f800000;
      local_950[1] = (float *)0x0;
      local_948 = 0.0;
      local_944 = (float *)0x0;
      local_940 = (float *)0x0;
      pfStack_93c = (float *)0x3f800000;
      local_938 = (float *)0x0;
      uStack_934 = 0;
      uStack_930 = 0;
      uStack_92c = 0;
      uStack_928 = 0x3f800000;
      uStack_924 = 0;
      uStack_920 = 0;
      uStack_91c = 0;
      uStack_918 = 0;
      uStack_914 = 0x3f800000;
      pfStack_988 = (float *)(uint)bVar2;
      FUN_0040b930();
      D3DXMatrixMultiply(local_950,local_950,afStack_890);
      iVar22 = param_1[0x136];
      puVar20 = param_1 + iVar11 * 6 + 0x533;
      if (iVar22 != 0) {
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == 0x22719fa9) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == -0x2efd56e) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == 0x12049251) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == 0x22719fa9) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == -0x2efd56e) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        iVar11 = puVar20[3];
        if (iVar11 != 0) {
          piVar14 = *(int **)(iVar11 + 0x3c);
          iVar11 = (int)*(char *)(iVar11 + 0x1a);
          if (0 < iVar11) {
            do {
              if (*piVar14 == 0x12049251) {
                piVar14[1] = iVar22;
              }
              piVar14 = piVar14 + 2;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
      }
      if (bVar2 != 0) {
        D3DXMatrixMultiply(afStack_830,afStack_7d0,local_950);
        pfVar12 = &fStack_83c;
        D3DXMatrixMultiply(&fStack_83c,pfVar12,param_5);
        D3DXMatrixMultiply(auStack_848,auStack_848,auStack_5e8);
        D3DXMatrixMultiply(pfVar12,auStack_854,pfStack_998);
        if (DAT_0073554c == 0) {
          pfVar12 = pfVar17;
          FUN_00542400(pfVar17);
          FUN_00542c20(pfVar17,&DAT_0078ea40);
        }
        else {
          CarRender_LitBodyPathA(pfStack_99c,pfVar12,&DAT_0078ea40,auStack_8d0,param_2);
        }
        FUN_0040c910(param_2,puVar20,pfVar12,pfStack_99c,0);
      }
      if (pfStack_98c != (float *)0x0) {
        puVar25 = auStack_790;
        D3DXMatrixMultiply(afStack_890,puVar25,param_5 + 0x40);
        D3DXMatrixMultiply(&fStack_89c,&fStack_89c,afStack_5d0 + 0xd);
        puVar25 = puVar25 + 0x40;
        D3DXMatrixMultiply(puVar25,&uStack_8a8,pfStack_98c);
        pfVar12 = pfStack_99c + 0x70;
        if (DAT_0073554c == 0) {
          FUN_00542400(puVar25);
          FUN_00542c20(puVar25,&DAT_0078ea40);
        }
        else {
          CarRender_LitBodyPathA(pfVar12,puVar25,&DAT_0078ea40,auStack_8d0,param_2);
        }
        FUN_0040c910(param_2,puVar20,puVar25,pfVar12,0);
      }
      if (pfStack_984 != (float *)0x0) {
        puVar25 = auStack_750;
        D3DXMatrixMultiply(afStack_890,puVar25,param_5 + 0x80);
        D3DXMatrixMultiply(&fStack_89c,&fStack_89c,auStack_55c);
        puVar25 = puVar25 + 0x80;
        D3DXMatrixMultiply(puVar25,&uStack_8a8,pfStack_98c);
        pfVar12 = pfStack_99c + 0xe0;
        if (DAT_0073554c == 0) {
          FUN_00542400(puVar25);
          FUN_00542c20(puVar25,&DAT_0078ea40);
        }
        else {
          CarRender_LitBodyPathA(pfVar12,puVar25,&DAT_0078ea40,auStack_8d0,param_2);
        }
        FUN_0040c910(param_2,puVar20,puVar25,pfVar12,0);
      }
      if (pfStack_998 != (float *)0x0) {
        D3DXMatrixMultiply(afStack_830,auStack_710,local_950);
        pfVar12 = &fStack_83c;
        D3DXMatrixMultiply(&fStack_83c,pfVar12,param_5 + 0xc0);
        D3DXMatrixMultiply(auStack_848,auStack_848,auStack_528);
        pfVar12 = pfVar12 + 0x30;
        D3DXMatrixMultiply(pfVar12,auStack_854,pfStack_998);
        pfVar17 = pfStack_99c + 0x150;
        if (DAT_0073554c == 0) {
          FUN_00542400(pfVar12);
          FUN_00542c20(pfVar12,&DAT_0078ea40);
        }
        else {
          CarRender_LitBodyPathA(pfVar17,pfVar12,&DAT_0078ea40,auStack_8d0,param_2);
        }
        FUN_0040c910(param_2,puVar20,pfVar12,pfVar17,0);
      }
    }
  }
  if (((int)puVar18 < 2) && (param_1[0x51e] != 0)) {
    uStack_904 = (uint)*(byte *)(param_1 + 0x74e);
    local_958 = (float)(uint)*(byte *)(param_1 + 0x746);
    piStack_994 = (int *)(uint)*(byte *)(param_1 + 0x73e);
    cVar9 = *(char *)(param_1 + 0x736);
    if (((*(byte *)(param_1 + 0x74e) != 0 || *(byte *)(param_1 + 0x746) != 0) ||
        *(byte *)(param_1 + 0x73e) != 0) || cVar9 != '\0') {
      pfVar12 = DAT_007355b4;
      pfVar17 = DAT_007355b4 + 0x40;
      if (DAT_007355b8 <= DAT_007355b4 + 0x40) {
        DAT_007355c8 = DAT_007355c8 + 0x100;
        DAT_007355c4 = 1;
        pfVar12 = (float *)0x0;
        pfVar17 = DAT_007355b4;
      }
      DAT_007355b4 = pfVar17;
      pfVar17 = DAT_007355b4;
      pfVar21 = DAT_007355b4 + 0x1c0;
      if (DAT_007355b8 <= DAT_007355b4 + 0x1c0) {
        DAT_007355c8 = DAT_007355c8 + 0x700;
        DAT_007355c4 = 1;
        pfVar17 = (float *)0x0;
        pfVar21 = DAT_007355b4;
      }
      DAT_007355b4 = pfVar21;
      if ((pfVar12 != (float *)0x0) && (pfVar17 != (float *)0x0)) {
        puVar18 = param_1 + (uint)(iStack_908 == 0) * 6 + 0x51b;
        iVar11 = param_1[0x138];
        if (iVar11 != 0) {
          iVar22 = puVar18[3];
          if (iVar22 != 0) {
            piVar14 = *(int **)(iVar22 + 0x3c);
            iVar22 = (int)*(char *)(iVar22 + 0x1a);
            if (0 < iVar22) {
              do {
                if (*piVar14 == -0x5ce791d5) {
                  piVar14[1] = iVar11;
                }
                piVar14 = piVar14 + 2;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
          iVar22 = puVar18[3];
          if (iVar22 != 0) {
            piVar14 = *(int **)(iVar22 + 0x3c);
            iVar22 = (int)*(char *)(iVar22 + 0x1a);
            if (0 < iVar22) {
              do {
                if (*piVar14 == -0x299bf201) {
                  piVar14[1] = iVar11;
                }
                piVar14 = piVar14 + 2;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
          iVar22 = puVar18[3];
          if (iVar22 != 0) {
            piVar14 = *(int **)(iVar22 + 0x3c);
            iVar22 = (int)*(char *)(iVar22 + 0x1a);
            if (0 < iVar22) {
              do {
                if (*piVar14 == -0x5ce791d5) {
                  piVar14[1] = iVar11;
                }
                piVar14 = piVar14 + 2;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
          iVar22 = puVar18[3];
          if (iVar22 != 0) {
            piVar14 = *(int **)(iVar22 + 0x3c);
            iVar22 = (int)*(char *)(iVar22 + 0x1a);
            if (0 < iVar22) {
              do {
                if (*piVar14 == -0x5ce791d5) {
                  piVar14[1] = iVar11;
                }
                piVar14 = piVar14 + 2;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
          }
        }
        local_950[1] = (float *)0x0;
        local_948 = 0.0;
        local_944 = (float *)0x0;
        local_940 = (float *)0x0;
        local_938 = (float *)0x0;
        uStack_934 = 0;
        uStack_930 = 0;
        uStack_92c = 0;
        uStack_924 = 0;
        uStack_920 = 0;
        uStack_91c = 0;
        uStack_918 = 0;
        uStack_914 = 0x3f800000;
        local_950[0] = (float *)0x3f800000;
        pfStack_93c = (float *)0xbf800000;
        uStack_928 = 0x3f800000;
        if (cVar9 != '\0') {
          D3DXMatrixMultiply(afStack_890,local_950,param_6);
          D3DXMatrixMultiply(&fStack_89c,&fStack_89c,auStack_6dc);
          D3DXMatrixMultiply(pfVar12,&uStack_8a8,pfStack_98c);
          puVar18[4] = param_1 + 0x38b;
          puVar18[5] = 2;
          if (((pfStack_988 == (float *)0x0) || (DAT_0077a920 != 6)) || (*DAT_007361f0 == 1)) {
            FUN_00544390(&DAT_0078ea40,auStack_8d0,param_2,auStack_300);
            FUN_0040c910(param_2,puVar18,pfVar12,pfVar17,0);
          }
          else {
            FUN_0040c910(param_2,puVar18,pfVar12,pfStack_99c,0);
          }
        }
        if (piStack_994 != (int *)0x0) {
          D3DXMatrixMultiply(afStack_890,param_6 + 0x40,auStack_690);
          D3DXMatrixMultiply(unaff_ESI + 0x10,&fStack_89c,pfVar15);
          puVar18[4] = param_1 + 0x393;
          puVar18[5] = 2;
          if (((pfStack_98c == (float *)0x0) || (DAT_0077a920 != 6)) ||
             (pfVar12 = pfStack_99c, *DAT_007361f0 == 1)) {
            FUN_00544390(&DAT_0078ea40,auStack_8d0,param_2,auStack_300);
            pfVar12 = pfVar17;
          }
          FUN_0040c910(param_2,puVar18,unaff_ESI + 0x10,pfVar12 + 0x70,0);
        }
        if (local_958 != 0.0) {
          D3DXMatrixMultiply(afStack_890,param_6 + 0x80,auStack_650);
          D3DXMatrixMultiply(unaff_ESI + 0x20,&fStack_89c,pfVar15);
          puVar18[4] = param_1 + 0x393;
          puVar18[5] = 2;
          if (((pfStack_984 == (float *)0x0) || (DAT_0077a920 != 6)) ||
             (pfVar15 = pfStack_99c, *DAT_007361f0 == 1)) {
            FUN_00544390(&DAT_0078ea40,auStack_8d0,param_2,auStack_300);
            pfVar15 = pfVar17;
          }
          FUN_0040c910(param_2,puVar18,unaff_ESI + 0x20,pfVar15 + 0xe0,0);
        }
        if (uStack_904 != 0) {
          pfVar15 = afStack_890;
          D3DXMatrixMultiply(pfVar15,local_950,param_6 + 0xc0);
          puVar25 = auStack_61c;
          pfVar12 = &fStack_89c;
          D3DXMatrixMultiply(&fStack_89c,pfVar12,puVar25);
          iVar11 = (int)pfStack_988 + 0xc0;
          D3DXMatrixMultiply(iVar11,&uStack_8a8,pfStack_98c);
          puVar18[4] = param_1 + 0x38b;
          puVar18[5] = 2;
          if (((pfVar15 != (float *)0x0) && (DAT_0077a920 == 6)) && (*DAT_007361f0 != 1)) {
            FUN_0040c910(param_2,puVar18,iVar11,puVar25 + 0x540,0);
            return;
          }
          pfVar12 = pfVar12 + 0x150;
          FUN_00544390(&DAT_0078ea40,auStack_8f4,param_2,auStack_324);
          FUN_0040c910(param_2,puVar18,iVar11,pfVar12,0);
        }
      }
    }
  }
  return;
}


// ==== 0x5707b0 Views_UpdatePerFrame

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render low (hopper+ghidra) docs/re/render.md */

void Views_UpdatePerFrame(void)

{
  float *pfVar1;
  int iVar2;
  int *piVar3;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  pfVar1 = (float *)0x0;
  if (DAT_007361f8 == (int *)0x0) goto LAB_00570822;
  if ((((undefined4 **)DAT_00740504 == &DAT_00740504) || (DAT_00740504 == (undefined4 *)0x0)) ||
     (DAT_00740504 == (undefined4 *)0x4)) {
LAB_0057080c:
    piVar3 = DAT_007361f8;
    iVar2 = RaceManager__FindRacerByIdIn();
    if (iVar2 == 0) {
      iVar2 = *piVar3;
    }
  }
  else {
    if (((undefined4 **)DAT_00740504 == &DAT_00740504) || (DAT_00740504 == (undefined4 *)0x0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = DAT_00740504 + -1;
    }
    iVar2 = (**(code **)(*piVar3 + 0x40))();
    if (DAT_0078f5d8 != iVar2) {
      DAT_0078f5d8 = iVar2;
    }
    if (iVar2 == 0) goto LAB_0057080c;
  }
  pfVar1 = (float *)(iVar2 + 0x50);
LAB_00570822:
  if ((DAT_0077a920 == 3) && (DAT_007364a0 == 3)) {
    local_30 = DAT_007365a0;
    local_2c = (float)DAT_007365a4;
    local_28 = (float)DAT_007365a8;
    SelectCarCameraMover__GetDefaultEye();
    View_BuildMatrices(&DAT_0078bd50,&local_20,&local_30);
    return;
  }
  if ((pfVar1 != (float *)0x0) ||
     (((undefined4 **)DAT_0073d6d8 != &DAT_0073d6d8 &&
      (pfVar1 = (float *)(DAT_0073d6d8 + 0x1d0), pfVar1 != (float *)0x0)))) {
    uStack_1c = *(undefined4 *)(DAT_00740500 + 0x44);
    local_20 = *(undefined4 *)(DAT_00740500 + 0x40);
    uStack_18 = *(undefined4 *)(DAT_00740500 + 0x48);
    local_30 = _DAT_00704ad0 + *pfVar1;
    local_2c = pfVar1[1] + _DAT_00704ad4;
    local_28 = pfVar1[2] + _DAT_00704ad8;
    View_BuildMatrices(&DAT_0078bd50,&local_20,&local_30);
  }
  return;
}


// ==== 0x5708f0 FUN_005708f0

void __thiscall
FUN_005708f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(&DAT_006f1b38 + param_1 * 4);
  if (*(int *)(&DAT_006f1b38 + param_1 * 4) < DAT_00734608) {
    iVar1 = DAT_00734608;
  }
  iVar2 = *(int *)(&DAT_006f1b40 + param_1 * 4);
  if (*(int *)(&DAT_006f1b40 + param_1 * 4) < DAT_0073460c) {
    iVar2 = DAT_0073460c;
  }
  CarRenderInfo__Render
            (param_2,param_3,param_4,param_5,param_6,param_7,param_9,param_10,0,iVar2,iVar1,param_11
            );
  return;
}


// ==== 0x570950 DrawShowcaseCarList

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render I (C) docs/re/blur.md */

void DrawShowcaseCarList(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined1 local_210 [256];
  undefined1 local_110 [268];
  
  puVar3 = DAT_0073d6d8;
  iVar4 = DAT_007364a0;
  puVar6 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar3 == puVar6) {
      return;
    }
    iVar1 = puVar3[2];
    if (((iVar1 != 0) && (puVar3[0x265] != 0)) &&
       ((puVar3[0x1cc] == *(int *)(param_1 + 4) ||
        ((puVar3[0x267] != 0 && (*(int *)(param_1 + 4) == 4)))))) {
      iVar2 = puVar3[0x267];
      if (iVar2 == 0) {
LAB_005709de:
        iVar7 = param_2;
      }
      else {
        if (2 < iVar4) goto LAB_00570b78;
        iVar7 = param_3;
        if (iVar2 == 0) goto LAB_005709de;
      }
      if (iVar7 != 0) {
        uVar8 = 0;
        if (iVar2 != 0) {
          uVar8 = 0x41;
        }
        if (param_4 == 0) {
          uVar8 = uVar8 | 0x20;
        }
        if (param_5 == 0) {
          uVar8 = uVar8 | 0x40;
        }
        if (DAT_0073464c != 0) {
          uVar8 = uVar8 | 0x20;
        }
        if (DAT_00734648 != 0) {
          uVar8 = uVar8 | 0x40;
        }
        if (puVar3[0x264] == 0) {
          local_21c = puVar3[0x1d1];
          local_220 = puVar3[0x1d0];
          local_218 = puVar3[0x1d2];
          CallNTimes(local_110,0x40,4,FUN_004ad8d0);
          bMatrixCopy_b();
          bMatrixCopy_b();
          bMatrixCopy_b();
          bMatrixCopy_b();
          CallNTimes(local_210,0x40,4,FUN_004ad8d0);
          bMatrixCopy_b();
          bMatrixCopy_b();
          bMatrixCopy_b();
          bMatrixCopy_b();
          _DAT_0073462c = puVar3[0x267];
          bVar5 = 0;
          if (_DAT_0073462c == 0) {
            bVar5 = -(puVar3[0x269] != 0) & 8U | -(puVar3[0x268] != 0) & 3U;
          }
          FUN_005708f0(iVar1,param_1,&local_220,puVar3 + 0x1d4,local_110,local_210,puVar3[0x266],
                       uVar8,bVar5,puVar3[0x26a]);
        }
        else {
          FUN_0040c910(param_1,puVar3[0x264],puVar3 + 0x1d4,0,0);
        }
      }
    }
LAB_00570b78:
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x570b90 FUN_00570b90

uint FUN_00570b90(int param_1)

{
  int iVar1;
  char cVar2;
  uint extraout_EDX;
  uint uVar3;
  int unaff_EDI;
  
  iVar1 = *(int *)(DAT_007361f0 + 0x3c);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) || (*(int *)(iVar1 + 0x1c) == 0)) &&
     ((*(int *)(DAT_007361f0 + 0x40) == 0 || (*(int *)(*(int *)(DAT_007361f0 + 0x40) + 0x1c) == 0)))
     ) {
    uVar3 = (uint)*(byte *)(unaff_EDI + 0x8a8);
    if ((1 << ((byte)*(undefined4 *)(param_1 + 4) & 0x1f) & *(uint *)(unaff_EDI + 0x530)) == 0) {
      cVar2 = Car__IsResetGraceActive();
      if (((cVar2 != '\0') || ((*(uint *)(unaff_EDI + 0x538) & extraout_EDX) != 0)) &&
         (ABS(DAT_0073457c) < 0.001 == (ABS(DAT_0073457c) == 0.001))) {
        uVar3 = DAT_007364dc & 1;
      }
    }
    return uVar3;
  }
  return 0;
}


// ==== 0x570c20 FUN_00570c20

undefined4 __fastcall FUN_00570c20(int param_1)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if ((*(int *)(in_EAX + 0x280) != param_1) && (*(char *)(param_1 + 0x4d0) != '\0')) {
    iVar1 = FUN_00570b90();
    if ((iVar1 == 0) &&
       ((*(uint *)(param_1 + 0x534) & 1 << ((byte)*(undefined4 *)(unaff_ESI + 4) & 0x1f)) != 0)) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x570c70 FUN_00570c70

void FUN_00570c70(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = DAT_0073d6d8;
  if ((((unaff_EDI != 0) && (DAT_006f41a0 != 0)) && (DAT_00700ea0 != 0)) && (DAT_006fb038 != 0)) {
    puVar2 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
      if (((puVar1[0x265] != 0) && (puVar1[0x267] == 0)) &&
         ((puVar1[0x1cc] == *(int *)(unaff_EDI + 4) && (puVar1[2] != 0)))) {
        FUN_0056d8d0(puVar1[2],unaff_EDI,puVar1 + 0x1d4,0,param_1);
      }
    }
  }
  return;
}


// ==== 0x570d00 FUN_00570d00

void FUN_00570d00(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (((DAT_006f41a0 != 0) && (DAT_00700ea0 != 0)) && (DAT_007361f8 != (int *)0x0)) {
    piVar4 = (int *)*DAT_007361f8;
    iVar3 = 99;
    piVar2 = DAT_007361f8;
    if (piVar4 != DAT_007361f8) {
      do {
        iVar1 = FUN_00570c20();
        if ((iVar1 != 0) && (0 < iVar3)) {
          iVar3 = iVar3 + -1;
          piVar2 = piVar4 + 0x138;
          if ((1 << ((byte)*(undefined4 *)(in_EAX + 4) & 0x1f) & piVar4[0x14c]) == 0) {
            piVar2 = piVar4 + 0x24;
          }
          FUN_0056d8d0(piVar4[0x135],in_EAX,piVar2,0,param_1);
          piVar2 = DAT_007361f8;
        }
        piVar4 = (int *)*piVar4;
      } while (piVar4 != piVar2);
    }
  }
  return;
}


// ==== 0x570db0 RenderFrame_DrawCars

/* [canon] render med (hopper+capstone) docs/re/misc.md */

void RenderFrame_DrawCars(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  int local_2a8;
  undefined1 local_290 [32];
  float local_270;
  float local_26c;
  float local_268;
  undefined1 local_250 [40];
  float local_228;
  undefined1 local_210 [256];
  undefined1 local_110 [268];
  
  if (((DAT_006f1ad0 != 0) && (DAT_0077a920 == 6)) && (*DAT_007361f0 != 1)) {
    iVar6 = (&DAT_007361bc)[*(int *)(unaff_ESI + 4) != 4];
    iVar3 = RaceManager__FindRacerByIdIn();
    local_2a8 = (int)*(short *)(iVar3 + 8);
    iVar3 = *(int *)(iVar6 + 0x27c);
    iVar4 = FUN_00421c40();
    if (((iVar4 == 0) && (*(int *)(iVar6 + 0x60) == 0)) &&
       ((iVar3 == 0 || ((iVar6 = *(int *)(iVar3 + 0xc), iVar6 != 2 && (iVar6 != 4)))))) {
      iVar6 = local_2a8 + 1;
    }
    else {
      iVar6 = *(int *)(DAT_007361f8 + 0x20);
      local_2a8 = 0;
    }
    iVar3 = *(int *)(unaff_ESI + 0x40);
    if (local_2a8 < iVar6) {
      iVar4 = local_2a8 * 4 + 0x28;
      do {
        iVar1 = *(int *)(iVar4 + DAT_007361f8);
        if ((((*(int *)(iVar3 + 0x280) != iVar1) && (*(char *)(iVar1 + 0x4d0) != '\0')) &&
            (iVar5 = FUN_00570b90(), iVar5 == 0)) &&
           ((*(uint *)(iVar1 + 0x534) & 1 << ((byte)*(undefined4 *)(unaff_ESI + 4) & 0x1f)) != 0)) {
          CallNTimes(local_110,0x40,4,FUN_004ad8d0);
          CallNTimes(local_210,0x40,4,FUN_004ad8d0);
          Car__GetRenderingWheelAndBrakeMatrices(iVar1);
          uVar2 = *(undefined4 *)(iVar1 + 0x4d4);
          bMatrixCopy_b();
          if (*(int *)(iVar1 + 0x3cc) < 3) {
            eIdentity();
            local_228 = -local_228;
            D3DXMatrixMultiply(local_290,local_290,local_250);
          }
          else {
            local_270 = -local_270;
            local_26c = -local_26c;
            local_268 = -local_268;
          }
          CarRenderInfo__Render(uVar2);
        }
        local_2a8 = local_2a8 + 1;
        iVar4 = iVar4 + 4;
      } while (local_2a8 < iVar6);
    }
  }
  return;
}


