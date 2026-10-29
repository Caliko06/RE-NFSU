// ==== 0x4e1290 FUN_004e1290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e1290(int param_1,uint param_2,int param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  undefined1 extraout_CL;
  undefined4 extraout_ECX;
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (0x46671a09 < param_2) {
        if (param_2 != 0x911ab364) {
          return;
        }
        cVar1 = FUN_004e0bf0();
        if (((cVar1 != '\0') && (*(int *)(param_1 + 0xc0) == 0)) ||
           ((cVar1 = FUN_004e0bf0(), cVar1 != '\0' && (*(int *)(param_1 + 0xc0) == 1)))) {
          FEngQueuePackagePop("GarageMain_2p.fng");
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (*(char *)(param_1 + 200) != '\0') {
          return;
        }
        cVar1 = FUN_004e0bf0();
        if (cVar1 == '\0') {
          cVar1 = FUN_004e0bf0();
          if (cVar1 == '\0') {
            return;
          }
          if ((*(char *)(param_1 + 0xad) != '\0') && (DAT_00777cc8 != 5)) {
            *(undefined1 *)(param_1 + 0x7c) = 0;
            FUN_004e02d0(param_1 + 0xa4);
            return;
          }
          if ((*(char *)(param_1 + 0xac) != '\0') && (DAT_00777cc8 != 5)) {
            *(undefined1 *)(param_1 + 0xac) = 0;
            FUN_004e0270();
            FUN_00414a10();
            return;
          }
          FEngQueuePackagePop("GarageMain_2p.fng");
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if ((*(char *)(param_1 + 0x91) != '\0') && (DAT_00777cc8 != 5)) {
          *(undefined1 *)(param_1 + 0x58) = extraout_CL;
          FUN_004e02d0(param_1 + 0x88);
          return;
        }
        if ((*(char *)(param_1 + 0x90) != '\0') && (DAT_00777cc8 != 5)) {
          *(undefined1 *)(param_1 + 0x90) = 0;
          FUN_004e0270();
          FUN_00414a10();
          return;
        }
        FEngQueuePackagePop("GarageMain_2p.fng");
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x46671a09) {
        if (*(int *)(param_3 + 0x10) == -0x728cc398) {
          FEObject__SetScript("Highlight",1);
          return;
        }
        if (*(int *)(param_3 + 0x10) != -0x217fc917) {
          return;
        }
        FEObject__SetScript("Highlight",1);
        return;
      }
      if (param_2 == 0x12341110) {
        *(undefined1 *)(param_1 + 200) = 0;
        cVar1 = FUN_004e0bf0();
        if (cVar1 == '\0') {
          FUN_004e0d10(1);
          return;
        }
        FUN_004e0d10(extraout_ECX);
        return;
      }
      if (param_2 != 0x406415e3) {
        return;
      }
      if (*(char *)(param_1 + 200) != '\0') {
        return;
      }
      cVar1 = FUN_004e0bf0();
      if ((cVar1 != '\0') && (*(int *)(param_1 + 0xc0) == 0)) {
        return;
      }
      cVar1 = FUN_004e0bf0();
      if (cVar1 != '\0') {
        if (*(int *)(param_1 + 0xc0) == 1) {
          return;
        }
        if (*(int *)(param_1 + 0xc0) == 0) {
          return;
        }
      }
      cVar1 = FUN_004e0bf0();
      if (cVar1 == '\0') {
        cVar1 = FUN_004e0bf0();
        if (cVar1 == '\0') goto LAB_004e141a;
        if (*(char *)(param_1 + 0x7c) == '\0') {
          *(undefined1 *)(param_1 + 0x7c) = 1;
          if (DAT_00777cc8 == 5) {
            *(undefined1 *)(param_1 + 0xac) = 1;
            FUN_00414a60();
          }
          else {
            FUN_004e0270();
          }
          goto LAB_004e141a;
        }
        if (*(char *)(param_1 + 0xac) != '\0') goto LAB_004e141a;
        FUN_00414a60();
        *(undefined1 *)(param_1 + 0xac) = 1;
        if (DAT_00777cc8 == 5) goto LAB_004e141a;
        iVar2 = param_1 + 0xa4;
      }
      else {
        if (*(char *)(param_1 + 0x58) == '\0') {
          *(undefined1 *)(param_1 + 0x58) = 1;
          if (DAT_00777cc8 == 5) {
            *(undefined1 *)(param_1 + 0x90) = 1;
            FUN_00414a60();
          }
          else {
            FUN_004e0270();
          }
          goto LAB_004e141a;
        }
        if (*(char *)(param_1 + 0x90) != '\0') goto LAB_004e141a;
        FUN_00414a60();
        *(undefined1 *)(param_1 + 0x90) = 1;
        if (DAT_00777cc8 == 5) goto LAB_004e141a;
        iVar2 = param_1 + 0x88;
      }
      FUN_004e02d0(iVar2);
LAB_004e141a:
      if (*(char *)(param_1 + 0x58) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x7c) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x90) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0xac) == '\0') {
        return;
      }
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else {
    if (0xc519bfc0 < param_2) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      if (((DAT_00746968 != 0) && (DAT_00746968 != 0x7fffffff)) &&
         (_DAT_006faf00 <= (float)(DAT_0073ad3c - DAT_00746968) * 0.00025)) {
        FUN_004b23b0(*(int *)(param_1 + 0x4c) + 0x10,1);
        DAT_00746968 = 0;
      }
      if (((DAT_00746964 != 0) && (DAT_00746964 != 0x7fffffff)) &&
         (_DAT_006faf00 <= (float)(DAT_0073ad3c - DAT_00746964) * 0.00025)) {
        FUN_004b23b0(*(int *)(param_1 + 0x70) + 0x10,1);
        DAT_00746964 = 0;
      }
      iVar2 = *(int *)(param_1 + 0xc0);
      if (((iVar2 == 0) || (iVar2 == 1)) && (iVar2 != 1)) {
        return;
      }
      FEPackageList__FindByName(&DAT_00746104);
      return;
    }
    if (param_2 == 0xc519bfc0) {
      cVar1 = FUN_004e0bf0();
      if (((cVar1 == '\0') || (*(int *)(param_1 + 0xc0) == 0)) ||
         (*(char *)(param_1 + 0x58) != '\0')) {
        cVar1 = FUN_004e0bf0();
        if (cVar1 == '\0') {
          return;
        }
        if (*(int *)(param_1 + 0xc0) == 1) {
          return;
        }
        if (*(int *)(param_1 + 0xc0) == 0) {
          return;
        }
        if (*(char *)(param_1 + 0x7c) != '\0') {
          return;
        }
      }
      if (*(char *)(param_1 + 200) != '\0') {
        return;
      }
      *(uint *)(param_1 + 0xc4) = param_4;
      FUN_004e1b20(0xc519bfc0);
      return;
    }
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xb5af2461) {
        return;
      }
      if (*(int *)(param_1 + 0xc0) == 0) {
        FUN_004e0cb0(param_1);
        *(undefined4 *)(param_1 + 0xc0) = 1;
        FUN_00495fc0();
        FUN_00495f70();
        FUN_00495f70();
        return;
      }
      if (*(int *)(param_1 + 0xc0) != 1) {
        return;
      }
      if ((param_4 & 1) == 0) {
        if ((param_4 & 2) == 0) {
          if ((param_4 & 4) == 0) {
            iVar2 = (-(uint)((param_4 & 8) != 0) & 4) - 1;
          }
          else {
            iVar2 = 2;
          }
        }
        else {
          iVar2 = 1;
        }
      }
      else {
        iVar2 = 0;
      }
      if (DAT_00748f78 == iVar2) {
        return;
      }
      DAT_00748f7c = iVar2;
      FUN_00495f70();
      FUN_004e0c50();
      FUN_004b2220();
      return;
    }
  }
  if (*(char *)(param_1 + 200) == '\0') {
    cVar1 = FUN_004e0bf0();
    if ((cVar1 == '\0') || (*(int *)(param_1 + 0xc0) == 0)) {
      cVar1 = FUN_004e0bf0();
      if ((cVar1 != '\0') && ((*(int *)(param_1 + 0xc0) != 1 && (*(int *)(param_1 + 0xc0) != 0)))) {
        if (*(char *)(param_1 + 0x7c) == '\0') goto LAB_004e1807;
        if ((*(char *)(param_1 + 0xac) == '\0') && (DAT_00777cc8 != 5)) {
          FUN_004e0560();
          return;
        }
      }
    }
    else {
      if (*(char *)(param_1 + 0x58) == '\0') {
LAB_004e1807:
        FUN_004e1a10(param_2);
        return;
      }
      if ((*(char *)(param_1 + 0x90) == '\0') && (DAT_00777cc8 != 5)) {
        FUN_004e0560();
        return;
      }
    }
  }
  return;
}


// ==== 0x4e19a0 FUN_004e19a0

void __fastcall FUN_004e19a0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = GetCarModelNameHash();
    FUN_00495f00(uVar1);
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    uVar1 = GetCarModelNameHash();
    FUN_00495f00(uVar1);
  }
  return;
}


// ==== 0x4e1a10 FUN_004e1a10

void FUN_004e1a10(void)

{
  char cVar1;
  int iVar2;
  int unaff_EDI;
  
  cVar1 = FUN_004e0bf0();
  if (cVar1 == '\0') {
    cVar1 = FUN_004e0bf0();
    if (cVar1 == '\0') {
      return;
    }
    iVar2 = unaff_EDI + 100;
  }
  else {
    iVar2 = unaff_EDI + 0x40;
  }
  if (iVar2 != 0) {
    FUN_004e1a50();
  }
  return;
}


// ==== 0x4e1a50 FUN_004e1a50

void __fastcall FUN_004e1a50(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(char *)(in_EAX + 0x18) != '\0') {
    return;
  }
  puVar2 = *(undefined4 **)(in_EAX + 0xc);
  if (param_1 == -0x6edfbf62) {
    if (puVar2 == *(undefined4 **)(in_EAX + 4)) goto LAB_004e1a85;
    uVar3 = puVar2[1];
  }
  else {
    if ((param_1 != -0x4a68e40f) || (puVar2 == *(undefined4 **)(in_EAX + 8))) goto LAB_004e1a85;
    uVar3 = *puVar2;
  }
  *(undefined4 *)(in_EAX + 0xc) = uVar3;
LAB_004e1a85:
  if (puVar2 != *(undefined4 **)(in_EAX + 0xc)) {
    FUN_004f8340(*(undefined4 *)(in_EAX + 0x20));
    iVar1 = *(int *)(in_EAX + 0x14);
    if ((iVar1 < 0) || (1 < iVar1)) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = &DAT_00758c28 + iVar1 * 0x3e51;
    }
    uVar3 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 0x738);
    if (DAT_00777b4c == 8) {
      puVar2[1] = uVar3;
    }
    else {
      *puVar2 = uVar3;
    }
    FUN_004e19a0();
    FUN_004e1b90();
    if (*(int *)(in_EAX + 0x14) == 0) {
      DAT_00746968 = DAT_0073ad3c;
      return;
    }
    if (*(int *)(in_EAX + 0x14) == 1) {
      DAT_00746964 = DAT_0073ad3c;
    }
  }
  return;
}


// ==== 0x4e1b20 FUN_004e1b20

void FUN_004e1b20(void)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 200) = 1;
  cVar1 = FUN_004e0bf0();
  if (cVar1 == '\0') {
    cVar1 = FUN_004e0bf0();
    if (cVar1 == '\0') goto LAB_004e1b83;
    iVar2 = unaff_ESI + 100;
  }
  else {
    iVar2 = unaff_ESI + 0x40;
  }
  if (iVar2 != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x18) == 0) {
      return;
    }
    if (*(int **)(iVar2 + 0x14) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x12341110,0,0,*(int *)(iVar2 + 0x18));
    return;
  }
LAB_004e1b83:
  *(undefined1 *)(unaff_ESI + 200) = 0;
  return;
}


// ==== 0x4e1b90 FUN_004e1b90

void FUN_004e1b90(void)

{
  int iVar1;
  int unaff_EBX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  if (*(int *)(unaff_EBX + 0x14) == 0) {
    uVar3 = 0xa4c3d766;
    uVar2 = 0xd79b67f9;
  }
  else if (*(int *)(unaff_EBX + 0x14) == 1) {
    uVar3 = 0xa4c38ad8;
    uVar2 = 0xd79b1b6b;
  }
  if (((*(int *)(unaff_EBX + 0x20) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(uVar3);
    }
  }
  FEObject__SetVisible(iVar1);
  if (((*(int *)(unaff_EBX + 0x20) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(uVar2);
    }
  }
  FEObject__SetVisible(iVar1);
  if ((*(int *)(unaff_EBX + 0xc) == *(int *)(unaff_EBX + 4)) ||
     (*(int *)(unaff_EBX + 0xc) == *(int *)(unaff_EBX + 8))) {
    FUN_00495f70();
  }
  return;
}


// ==== 0x4e1c60 MPChooseGarageScreen::_MPChooseGarageScreen

/* [canon] canon med (ghidra+hopper) docs/re/tuning.md */

void __fastcall MPChooseGarageScreen___MPChooseGarageScreen(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3654;
  FUN_004f7b50();
  return;
}


// ==== 0x4e1c70 FUN_004e1c70

void * __thiscall FUN_004e1c70(void *param_1,byte param_2)

{
  MPChooseGarageScreen___MPChooseGarageScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e1c90 CreateMPChooseGarageScreen

/* [canon] online high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateMPChooseGarageScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687a83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x70);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = MPChooseGarageScreen__MPChooseGarageScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e1cf0 MPChooseGarageScreen::MPChooseGarageScreen

/* [canon] hud high (ghidra+hopper) docs/re/tuning.md */

undefined4 * MPChooseGarageScreen__MPChooseGarageScreen(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c3654;
  *(undefined1 *)(param_1 + 0x15) = 0;
  local_4 = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  FUN_004e1d70(param_1 + 0x10,"P1_CarPort_","Backing_P1");
  FUN_004e1d70(param_1 + 0x16,"P2_CarPort_","Backing_P2");
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e1d70 FUN_004e1d70

void FUN_004e1d70(int param_1,undefined4 param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int local_28;
  byte local_20;
  byte local_1f [31];
  
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = in_EAX;
  local_28 = 0;
  do {
    iVar3 = local_28 + 1;
    bSPrintf_regdst(0x20,&DAT_006c3664,param_2,iVar3);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar7 = DAT_0073578c;
    if (*(int *)(param_1 + 0x10) == 0) {
LAB_004e1e4a:
      iVar4 = 0;
      if ((iVar7 == 0) || (iVar5 = FUN_004ef050(iVar8), iVar4 = DAT_0073578c, iVar5 == 0))
      goto LAB_004e1e71;
LAB_004e1e5d:
      iVar4 = DAT_0073578c;
      if (*(int *)(iVar5 + 0x18) != 2) goto LAB_004e1e71;
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004e1e33:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar5 == 0))
        goto LAB_004e1e4a;
        goto LAB_004e1e5d;
      }
      iVar4 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        iVar5 = *(int *)(DAT_0073578c + 8);
        if ((iVar5 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004e1e4a;
        goto LAB_004e1e33;
      }
LAB_004e1e71:
      iVar5 = 0;
    }
    *(int *)(param_1 + local_28 * 4) = iVar5;
    local_28 = iVar3;
  } while (iVar3 < 3);
  iVar8 = -1;
  if (param_3 != (byte *)0x0) {
    bVar2 = *param_3;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar6 = param_3 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      param_3 = param_3 + 1;
      bVar2 = *pbVar6;
    }
  }
  if (*(int *)(param_1 + 0x10) == 0) {
LAB_004e1f26:
    if ((iVar4 == 0) || (iVar3 = FUN_004ef050(iVar8), iVar3 == 0)) goto LAB_004e1f50;
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
      if (DAT_0073578c == 0) goto LAB_004e1f50;
      iVar7 = *(int *)(DAT_0073578c + 8);
      if ((iVar7 == 0) ||
         ((iVar3 = FUN_004fd1e0(iVar7 + 0xdc), iVar3 == 0 &&
          (iVar3 = FUN_004fd1e0(iVar7 + 0xec), iVar3 == 0)))) goto LAB_004e1f26;
    }
    if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar3 == 0))
    goto LAB_004e1f26;
  }
  if (*(int *)(iVar3 + 0x18) == 1) {
    *(int *)(param_1 + 0xc) = iVar3;
    return;
  }
LAB_004e1f50:
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== 0x4e1f70 FUN_004e1f70

void FUN_004e1f70(void)

{
  int extraout_EDX;
  undefined4 uVar1;
  int extraout_EDX_00;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(unaff_EBX + 0x14) = 1;
  iVar3 = 0;
  do {
    iVar2 = *(int *)(unaff_EBX + iVar3 * 4);
    if ((iVar2 != 0) &&
       (*(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar2 + 0x18) == 5)) {
      uVar1 = *(undefined4 *)(iVar2 + 0x60);
      iVar2 = *(int *)(iVar2 + 0x5c);
      if (0 < iVar2) {
        do {
          FEObject__SetVisible(uVar1);
          uVar1 = *(undefined4 *)(extraout_EDX + 4);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  iVar3 = *(int *)(unaff_EBX + 0xc);
  if ((iVar3 != 0) &&
     (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar3 + 0x18) == 5)) {
    uVar1 = *(undefined4 *)(iVar3 + 0x60);
    iVar3 = *(int *)(iVar3 + 0x5c);
    if (0 < iVar3) {
      do {
        FEObject__SetVisible(uVar1);
        uVar1 = *(undefined4 *)(extraout_EDX_00 + 4);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}


// ==== 0x4e2000 FUN_004e2000

void FUN_004e2000(void)

{
  int iVar1;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 0x14) = 0;
  iVar1 = 0;
  do {
    FEObject__SetInvisible(*(undefined4 *)(unaff_EDI + iVar1 * 4));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  FEObject__SetInvisible(*(undefined4 *)(unaff_EDI + 0xc));
  return;
}


// ==== 0x4e2030 MPChooseGarageScreen::NotificationMessage

/* [canon] canon med (ghidra+hopper) docs/re/tuning.md */

void __thiscall
MPChooseGarageScreen__NotificationMessage(int param_1,uint param_2,undefined4 param_3,byte param_4)

{
  int iVar1;
  
  if (param_2 < 0x72619779) {
    if (param_2 != 0x72619778) {
      if (param_2 == 0x11111111) {
        FUN_004e1f70();
        if (*(char *)(param_1 + 0x6c) == '\0') {
          FUN_004e2000();
          return;
        }
      }
      else if (param_2 == 0x22222222) {
        FUN_004e1f70();
        if (*(char *)(param_1 + 0x54) == '\0') {
          FUN_004e2000();
          return;
        }
      }
    }
  }
  else if (param_2 == 0x911ab364) {
    if ((param_4 & 1) != 0) {
      if (*(char *)(param_1 + 0x6c) != '\0') {
        iVar1 = FEngFindPackage();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 1;
        }
        iVar1 = FEngFindPackage();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 2;
        }
        FUN_004e2000();
        return;
      }
      iVar1 = FEngFindPackage();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if ((param_4 & 2) != 0) {
      if (*(char *)(param_1 + 0x54) != '\0') {
        iVar1 = FEngFindPackage();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 2;
        }
        iVar1 = FEngFindPackage();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 1;
        }
        FUN_004e2000();
        return;
      }
      iVar1 = FEngFindPackage();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4e2170 FUN_004e2170

void __fastcall FUN_004e2170(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c3154;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x4e21c0 FUN_004e21c0

void * __thiscall FUN_004e21c0(void *param_1,byte param_2)

{
  FUN_004e2170();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e21e0 FUN_004e21e0

undefined4 * FUN_004e21e0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687073;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_FUN_006c3154;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_4 = 1;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e2250 FUN_004e2250

void FUN_004e2250(int param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int unaff_ESI;
  
  piVar3 = _malloc(0x18);
  piVar3[2] = param_2;
  piVar3[4] = param_3;
  piVar3[3] = param_1;
  *(undefined1 *)((int)piVar3 + 0x15) = param_4;
  *(undefined1 *)(piVar3 + 5) = param_5;
  puVar2 = *(undefined4 **)(in_EAX + 0x48);
  *puVar2 = piVar3;
  *(int **)(in_EAX + 0x48) = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = in_EAX + 0x44;
  iVar4 = FUN_004f8730(in_EAX + 0x4c,piVar3[2],CONCAT31((int3)((uint)puVar2 >> 8),unaff_ESI != 0),1)
  ;
  iVar5 = Texture_FindByHash();
  if (iVar5 == 0) {
    pcVar7 = "GENERICPLACEHOLDER";
    uVar6 = 0x47;
    iVar5 = -1;
    do {
      iVar5 = iVar5 * 0x21 + uVar6;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar6 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != iVar5)) {
      *(int *)(iVar4 + 0x24) = iVar5;
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    }
  }
  else if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != unaff_ESI)) {
    *(int *)(iVar4 + 0x24) = unaff_ESI;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    return;
  }
  return;
}


// ==== 0x4e2310 FUN_004e2310

void FUN_004e2310(void)

{
  int *piVar1;
  int in_EAX;
  int *unaff_EDI;
  
  piVar1 = (int *)unaff_EDI[0x10];
  if (in_EAX == -0x6edfbf62) {
    if ((piVar1 != (int *)unaff_EDI[0x11]) && ((int *)unaff_EDI[0x11] != unaff_EDI + 0x11)) {
      unaff_EDI[0x10] = piVar1[1];
    }
  }
  else if (((in_EAX == -0x4a68e40f) && ((int *)unaff_EDI[0x10] != (int *)unaff_EDI[0x12])) &&
          ((int *)unaff_EDI[0x11] != unaff_EDI + 0x11)) {
    unaff_EDI[0x10] = *(int *)unaff_EDI[0x10];
  }
  if (piVar1 != (int *)unaff_EDI[0x10]) {
    FUN_004f8910();
                    /* WARNING: Could not recover jumptable at 0x004e2368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*unaff_EDI + 0x10))();
    return;
  }
  return;
}


// ==== 0x4e2370 FUN_004e2370

int FUN_004e2370(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*in_EAX + 0x14))();
  if (((char)iVar2 != '\0') && (iVar2 = 0, *(int *)(in_EAX[0x10] + 0x10) != 0)) {
    GarageManager__PushScreen(in_EAX[3]);
    iVar1 = DAT_0073578c;
    iVar2 = in_EAX[3];
    if (DAT_0073578c != 0) {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar2 = 0;
      if ((iVar3 != 0) && (iVar2 = 0, *(int *)(iVar3 + 0x18) != 0)) {
        iVar2 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
      }
    }
  }
  return iVar2;
}


// ==== 0x4e23d0 FUN_004e23d0

void FUN_004e23d0(void)

{
  int in_EAX;
  int *piVar1;
  int *unaff_EDI;
  
  for (piVar1 = (int *)unaff_EDI[0x11]; piVar1 != unaff_EDI + 0x11; piVar1 = (int *)*piVar1) {
    if (piVar1[2] == in_EAX) {
      piVar1 = (int *)unaff_EDI[0x11];
      goto joined_r0x004e2411;
    }
  }
  piVar1 = (int *)unaff_EDI[0x11];
LAB_004e23ee:
  unaff_EDI[0x10] = (int)piVar1;
LAB_004e23f1:
  FUN_004f8960();
                    /* WARNING: Could not recover jumptable at 0x004e2404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_EDI + 0x10))();
  return;
joined_r0x004e2411:
  if (piVar1 == unaff_EDI + 0x11) goto LAB_004e241e;
  if (piVar1[2] == in_EAX) goto LAB_004e23ee;
  piVar1 = (int *)*piVar1;
  goto joined_r0x004e2411;
LAB_004e241e:
  unaff_EDI[0x10] = unaff_EDI[0x11];
  goto LAB_004e23f1;
}


// ==== 0x4e2430 FUN_004e2430

void __thiscall FUN_004e2430(undefined4 param_1,uint param_2)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        FUN_004e2370();
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageCategoryVisual__MoveBackPackage(param_1);
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
  FUN_004e2310();
  return;
}


// ==== 0x4e24a0 ComputeVinylIconHash

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

int ComputeVinylIconHash(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  
  pcVar4 = "CAR_THUMB";
  iVar3 = -1;
  uVar2 = 0x43;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  switch(param_1) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    goto switchD_004e24cc_default;
  }
  iVar3 = bStringHash();
switchD_004e24cc_default:
  if ((unaff_ESI != 0) && (*(byte *)(unaff_ESI + 0x12) < 0x13)) {
    iVar3 = *(int *)(&DAT_00746918 + (uint)*(byte *)(unaff_ESI + 0x12) * 4);
  }
  return iVar3;
}


// ==== 0x4e2520 FUN_004e2520

byte FUN_004e2520(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = FECarConfig__GetCarType();
  if (iVar3 * 0xc90 + DAT_00734588 == 0) {
    return 0;
  }
  puVar9 = &DAT_006c3454;
  iVar3 = bStringHash();
  uVar4 = 0x5f;
  do {
    iVar3 = iVar3 * 0x21 + uVar4;
    pbVar1 = puVar9 + 1;
    uVar4 = (uint)*pbVar1;
    puVar9 = puVar9 + 1;
  } while (*pbVar1 != 0);
  puVar9 = &DAT_006c344c;
  iVar5 = bStringHash();
  uVar4 = 0x5f;
  do {
    pbVar1 = puVar9 + 1;
    iVar5 = iVar5 * 0x21 + uVar4;
    puVar9 = puVar9 + 1;
    uVar4 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  puVar9 = &DAT_006c3444;
  iVar6 = bStringHash();
  uVar4 = 0x5f;
  do {
    iVar6 = iVar6 * 0x21 + uVar4;
    pbVar1 = puVar9 + 1;
    uVar4 = (uint)*pbVar1;
    puVar9 = puVar9 + 1;
  } while (*pbVar1 != 0);
  puVar9 = &DAT_006c343c;
  iVar7 = bStringHash();
  uVar4 = 0x5f;
  do {
    pbVar1 = puVar9 + 1;
    iVar7 = iVar7 * 0x21 + uVar4;
    puVar9 = puVar9 + 1;
    uVar4 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  puVar9 = &DAT_006c3434;
  iVar8 = bStringHash();
  uVar4 = 0x5f;
  do {
    pbVar1 = puVar9 + 1;
    iVar8 = iVar8 * 0x21 + uVar4;
    puVar9 = puVar9 + 1;
    uVar4 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 == iVar3) {
    return 1;
  }
  if (iVar2 == iVar5) {
    return 2;
  }
  if (iVar2 != iVar6) {
    if (iVar2 != iVar7) {
      return (iVar2 != iVar8) - 1U & 5;
    }
    return 4;
  }
  return 3;
}


// ==== 0x4e2680 IsHiddenUnique

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsHiddenUnique(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  
  pcVar5 = "SAMANTHA";
  iVar4 = -1;
  uVar3 = 0x53;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != iVar4) {
    puVar6 = &DAT_006c3420;
    iVar4 = -1;
    uVar3 = 0x45;
    do {
      iVar4 = iVar4 * 0x21 + uVar3;
      pbVar1 = puVar6 + 1;
      uVar3 = (uint)*pbVar1;
      puVar6 = puVar6 + 1;
    } while (*pbVar1 != 0);
    if (iVar2 != iVar4) {
      pcVar5 = "JUNKMAN";
      iVar4 = -1;
      uVar3 = 0x4a;
      do {
        iVar4 = iVar4 * 0x21 + uVar3;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar3 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      if (iVar2 != iVar4) {
        iVar4 = bStringHash();
        if (iVar2 != iVar4) {
          iVar4 = bStringHash();
          if (iVar2 != iVar4) {
            iVar4 = bStringHash();
            if (iVar2 != iVar4) {
              iVar4 = bStringHash();
              if (iVar2 != iVar4) {
                iVar4 = bStringHash();
                if (iVar2 != iVar4) {
                  iVar4 = bStringHash();
                  if (iVar2 != iVar4) {
                    iVar4 = bStringHash();
                    if (iVar2 != iVar4) {
                      iVar4 = bStringHash();
                      if (iVar2 != iVar4) {
                        iVar4 = bStringHash();
                        if (iVar2 != iVar4) {
                          iVar4 = bStringHash();
                          if (iVar2 != iVar4) {
                            iVar4 = bStringHash();
                            if (iVar2 != iVar4) {
                              iVar4 = bStringHash();
                              if (iVar2 != iVar4) {
                                iVar4 = bStringHash();
                                if (iVar2 != iVar4) {
                                  iVar4 = bStringHash();
                                  if (iVar2 != iVar4) {
                                    return 0;
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
        }
      }
    }
  }
  return 1;
}


// ==== 0x4e27e0 IsSamanthaUnique

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsSamanthaUnique(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  uVar3 = 0x43;
  iVar4 = -1;
  pcVar5 = "CUSTOM1";
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != iVar4) {
    uVar3 = 0x43;
    iVar4 = -1;
    pcVar5 = "CUSTOM3";
    do {
      iVar4 = iVar4 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    if (iVar2 != iVar4) {
      uVar3 = 0x43;
      iVar4 = -1;
      pcVar5 = "CUSTOM4";
      do {
        iVar4 = iVar4 * 0x21 + uVar3;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar3 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      if (((((iVar2 != iVar4) && (iVar4 = bStringHash(), iVar2 != iVar4)) &&
           (iVar4 = bStringHash(), iVar2 != iVar4)) &&
          ((iVar4 = bStringHash(), iVar2 != iVar4 && (iVar4 = bStringHash(), iVar2 != iVar4)))) &&
         ((iVar4 = bStringHash(), iVar2 != iVar4 &&
          ((iVar4 = bStringHash(), iVar2 != iVar4 && (iVar4 = bStringHash(), iVar2 != iVar4)))))) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x4e28d0 FilterVinylPart

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

uint FilterVinylPart(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  
  uVar2 = IsHiddenUnique();
  if ((char)uVar2 != '\0') {
    return uVar2 & 0xffffff00;
  }
  if ((DAT_00735de0 == 0x13f365) && (*(int *)(unaff_ESI + 0xc) == 0x13f365)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (DAT_00735de4 != 0x10) {
    if (DAT_00735de4 == 0x11) {
      iVar3 = FUN_004e2520();
      if ((0 < iVar3) && (iVar3 < 6)) {
        return 1;
      }
    }
    else if ((*(byte *)(unaff_ESI + 0x12) == DAT_00735de4) || (bVar1)) {
      return 1;
    }
    return 0;
  }
  return (uint)(*(char *)(unaff_ESI + 0x12) == '\x10');
}


// ==== 0x4e2940 FUN_004e2940

undefined4 FUN_004e2940(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylType.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylGroup.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylBrowser.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylLayerV2.fng");
  GarageManager__PopAllScreensOfCertainName("ColorPicker.fng");
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
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


// ==== 0x4e29d0 FUN_004e29d0

void __fastcall FUN_004e29d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c316c;
  FUN_004f7b50();
  return;
}


// ==== 0x4e29e0 FUN_004e29e0

void * __thiscall FUN_004e29e0(void *param_1,byte param_2)

{
  FUN_004e29d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e2a00 FUN_004e2a00

undefined4 * FUN_004e2a00(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c316c;
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  local_4 = 0;
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xda96ef8f);
    }
  }
  param_1[0x10] = iVar2;
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xda9a39d5);
    }
  }
  param_1[0x11] = iVar2;
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x80b4bcff);
    }
  }
  param_1[0x12] = iVar2;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if (iVar1 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004fd1e0(iVar1 + 0xdc);
        if (iVar3 == 0) {
          iVar3 = FUN_004fd1e0(iVar1 + 0xec);
        }
      }
    }
  }
  param_1[0x13] = iVar3;
  param_1[0x14] = 0;
  if (param_1[3] == 0) {
LAB_004e2c29:
    iVar3 = 0;
    if (iVar2 == 0) goto LAB_004e2c44;
    uVar4 = FUN_004ef050(0xa817ae3d);
    iVar3 = DAT_0073578c;
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar2 = DAT_0073578c;
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) {
LAB_004e2be1:
      local_4._0_1_ = 1;
      FUN_004ffb00(iVar3);
      local_4 = (uint)local_4._1_3_ << 8;
      iVar2 = DAT_0073578c;
      goto LAB_004e2c29;
    }
    iVar3 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         (((iVar3 = FUN_004fd1e0(iVar1 + 0xdc), iVar3 == 0 &&
           (iVar3 = FUN_004fd1e0(iVar1 + 0xec), iVar3 == 0)) || (iVar3 == 0)))) goto LAB_004e2c29;
      goto LAB_004e2be1;
    }
LAB_004e2c44:
    uVar4 = 0;
  }
  param_1[0x15] = uVar4;
  if (param_1[3] == 0) {
LAB_004e2cfe:
    iVar2 = 0;
    if (iVar3 == 0) goto LAB_004e2d19;
    uVar4 = FUN_004ef050(0xa817ae3e);
    iVar2 = DAT_0073578c;
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    iVar3 = DAT_0073578c;
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_004e2cb6:
      local_4._0_1_ = 2;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      iVar3 = DAT_0073578c;
      goto LAB_004e2cfe;
    }
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if (((iVar1 == 0) ||
          ((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
           (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)))) || (iVar2 == 0)) goto LAB_004e2cfe;
      goto LAB_004e2cb6;
    }
LAB_004e2d19:
    uVar4 = 0;
  }
  param_1[0x16] = uVar4;
  if (param_1[3] == 0) {
LAB_004e2dd3:
    iVar3 = 0;
    if (iVar2 == 0) goto LAB_004e2dee;
    uVar4 = FUN_004ef050(0xa817ae3f);
    iVar3 = DAT_0073578c;
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar2 = DAT_0073578c;
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) {
LAB_004e2d8b:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar3);
      local_4 = (uint)local_4._1_3_ << 8;
      iVar2 = DAT_0073578c;
      goto LAB_004e2dd3;
    }
    iVar3 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         (((iVar3 = FUN_004fd1e0(iVar1 + 0xdc), iVar3 == 0 &&
           (iVar3 = FUN_004fd1e0(iVar1 + 0xec), iVar3 == 0)) || (iVar3 == 0)))) goto LAB_004e2dd3;
      goto LAB_004e2d8b;
    }
LAB_004e2dee:
    uVar4 = 0;
  }
  param_1[0x17] = uVar4;
  if (param_1[3] == 0) {
LAB_004e2ea8:
    if (iVar3 != 0) {
      uVar4 = FUN_004ef050(0xa817ae40);
      goto LAB_004e2ebf;
    }
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    iVar3 = DAT_0073578c;
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_004e2e60:
      local_4._0_1_ = 4;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      iVar3 = DAT_0073578c;
      goto LAB_004e2ea8;
    }
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if (((iVar1 == 0) ||
          ((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
           (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)))) || (iVar2 == 0)) goto LAB_004e2ea8;
      goto LAB_004e2e60;
    }
  }
  uVar4 = 0;
LAB_004e2ebf:
  param_1[0x18] = uVar4;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) ||
     (((DAT_0073578c != 0 && (iVar3 = *(int *)(DAT_0073578c + 8), iVar3 != 0)) &&
      ((iVar2 = FUN_004fd1e0(iVar3 + 0xdc), iVar2 != 0 ||
       (iVar2 = FUN_004fd1e0(iVar3 + 0xec), iVar2 != 0)))))) {
    local_4._0_1_ = 5;
    FUN_004ffb00(iVar2);
    local_4 = (uint)local_4._1_3_ << 8;
  }
  iVar2 = 0;
  param_2 = param_1 + 0x19;
  do {
    iVar3 = param_1[3];
    iVar2 = iVar2 + 1;
    uVar4 = FUN_004f42f0("VINYL_THUMB_%d",iVar2);
    if (iVar3 == 0) {
LAB_004e2ffe:
      if (((DAT_0073578c == 0) || (iVar3 = FUN_004ef050(uVar4), iVar3 == 0)) ||
         (*(int *)(iVar3 + 0x18) != 1)) goto LAB_004e301c;
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) {
LAB_004e2fc6:
        local_4._0_1_ = 6;
        FUN_004ffb00(iVar3);
        local_4 = (uint)local_4._1_3_ << 8;
        goto LAB_004e2ffe;
      }
      if (DAT_0073578c != 0) {
        iVar1 = *(int *)(DAT_0073578c + 8);
        if ((iVar1 == 0) ||
           ((iVar3 = FUN_004fd1e0(iVar1 + 0xdc), iVar3 == 0 &&
            (iVar3 = FUN_004fd1e0(iVar1 + 0xec), iVar3 == 0)))) goto LAB_004e2ffe;
        goto LAB_004e2fc6;
      }
LAB_004e301c:
      iVar3 = 0;
    }
    *param_2 = iVar3;
    param_2 = param_2 + 1;
    if (3 < iVar2) {
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x4e3060 FUN_004e3060

void FUN_004e3060(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x9154922e);
    }
  }
  switch(DAT_00735dec) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_004e30ba_default;
  }
  iVar3 = FEngFindObject();
  if (iVar3 != 0) {
    local_c = *(undefined4 *)(*(int *)(iVar3 + 0x2c) + 0x1c);
    local_8 = *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 0x20);
    local_4 = *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 0x24);
    if (*(int *)(iVar2 + 0x18) < 0x100) {
      cVar1 = FEVector3__operator__();
      if (cVar1 == '\0') {
        *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
      }
      FUN_004ff1f0(iVar2,2,&local_c,0);
    }
  }
switchD_004e30ba_default:
  return;
}


// ==== 0x4e3160 FUN_004e3160

void FUN_004e3160(void)

{
  undefined4 uVar1;
  
  uVar1 = 0x109372ff;
  switch(DAT_00735dec) {
  case 0:
    uVar1 = 0x109372ff;
    break;
  case 1:
    uVar1 = 0x27b8f0de;
    break;
  case 2:
    uVar1 = 0x27b8f0df;
    break;
  case 3:
    uVar1 = 0xf76d07a1;
  }
  FUN_00495f00(uVar1);
  return;
}


// ==== 0x4e31c0 FUN_004e31c0

void FUN_004e31c0(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int unaff_EDI;
  
  pcVar4 = "CAR_THUMB";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  iVar3 = bStringHash();
  if ((DAT_007454d4 != 0) && (*(byte *)(DAT_007454d4 + 0x12) < 0x13)) {
    iVar3 = *(int *)(&DAT_00746918 + (uint)*(byte *)(DAT_007454d4 + 0x12) * 4);
  }
  iVar2 = *(int *)(unaff_EDI + 100);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != iVar3)) {
    *(int *)(iVar2 + 0x24) = iVar3;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  pcVar4 = "CAR_THUMB";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  iVar3 = bStringHash();
  if ((DAT_007454d0 != 0) && (*(byte *)(DAT_007454d0 + 0x12) < 0x13)) {
    iVar3 = *(int *)(&DAT_00746918 + (uint)*(byte *)(DAT_007454d0 + 0x12) * 4);
  }
  iVar2 = *(int *)(unaff_EDI + 0x68);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != iVar3)) {
    *(int *)(iVar2 + 0x24) = iVar3;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  pcVar4 = "CAR_THUMB";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  iVar3 = bStringHash();
  if ((DAT_007454cc != 0) && (*(byte *)(DAT_007454cc + 0x12) < 0x13)) {
    iVar3 = *(int *)(&DAT_00746918 + (uint)*(byte *)(DAT_007454cc + 0x12) * 4);
  }
  iVar2 = *(int *)(unaff_EDI + 0x6c);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != iVar3)) {
    *(int *)(iVar2 + 0x24) = iVar3;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  pcVar4 = "CAR_THUMB";
  do {
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  iVar3 = bStringHash();
  if ((DAT_007454c8 != 0) && (*(byte *)(DAT_007454c8 + 0x12) < 0x13)) {
    iVar3 = *(int *)(&DAT_00746918 + (uint)*(byte *)(DAT_007454c8 + 0x12) * 4);
  }
  iVar2 = *(int *)(unaff_EDI + 0x70);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != iVar3)) {
    *(int *)(iVar2 + 0x24) = iVar3;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x4e3320 FUN_004e3320

void __thiscall FUN_004e3320(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_2 < 0x9120409f) {
    if (param_2 == 0x9120409e) {
      DAT_00735dec = DAT_00735dec + -1;
      if (DAT_00735dec < 0) {
        DAT_00735dec = 0;
      }
      FUN_004e3060();
      FUN_004e3160(param_1);
      return;
    }
    if (param_2 < 0x7b8dd23f) {
      if (param_2 == 0x7b8dd23e) {
        switch(DAT_006fa1a0) {
        case 0x1f:
          break;
        case 0x20:
          break;
        case 0x21:
          break;
        case 0x22:
        }
        GarageManager__InstallPart(0,1);
        GarageManager__InstallPart(0,1);
        GarageManager__InstallPart(0,1);
        GarageManager__InstallPart(0,1);
        GarageManager__InstallPart(0,0);
        return;
      }
      if (param_2 == 0xc407210) {
        switch(DAT_00735dec) {
        case 0:
          DAT_006fa1a0 = 0x22;
          break;
        case 1:
          DAT_006fa1a0 = 0x21;
          break;
        case 2:
          DAT_006fa1a0 = 0x20;
          break;
        case 3:
          DAT_006fa1a0 = 0x1f;
        }
        if ((&DAT_00745b6c)[DAT_006fa1a0] == 0) {
          DAT_00735ddc = 0;
          GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        local_34 = 0;
        local_30 = 0;
        local_50 = 0x897dc3d1;
        local_48 = 0x4f022d6c;
        local_4c = 0x62ac06db;
        local_40 = 0x7b8dd23e;
        local_44 = 0x7758f62d;
        local_3c = 0xed716986;
        local_38 = 0xb8a7c6cc;
        FUN_004dc6e0(&local_50,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x4f022d6c) {
        DAT_00735ddc = 0;
        GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
        iVar2 = FEngFindPackage();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0xff;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else if (param_2 == 0x911ab364) {
      FEngSetAllObjectsInPackageVisibility("MU_HorizontalBrowserBack.fng",1);
      FUN_004e2940(param_1);
      return;
    }
  }
  else if (param_2 < 0xc519bfc3) {
    bVar4 = param_2 == 0xc519bfc1;
    if (param_2 < 0xc519bfc1) {
      if (param_2 == 0xb5971bf1) {
        DAT_00735dec = DAT_00735dec + 1;
        if (3 < DAT_00735dec) {
          DAT_00735dec = 3;
        }
        FUN_004e3060();
        FUN_004e3160(param_1);
        return;
      }
      if (param_2 == 0xc519bfc0) {
        switch(DAT_00735dec) {
        case 0:
          DAT_006fa1a0 = 0x22;
          break;
        case 1:
          DAT_006fa1a0 = 0x21;
          break;
        case 2:
          DAT_006fa1a0 = 0x20;
          break;
        case 3:
          DAT_006fa1a0 = 0x1f;
        }
        iVar2 = (&DAT_00745b6c)[DAT_006fa1a0];
        DAT_00735ddc = 3;
        if (iVar2 == 0) {
          if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
            return;
          }
        }
        else {
          uVar5 = 0;
          bStringHash(0);
          iVar3 = FUN_0057cc70(uVar5);
          if (0 < iVar3) {
            if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
              (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x16);
            }
            DAT_00735de8 = iVar2;
            GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
            return;
          }
        }
      }
    }
    else {
      FUN_004f6c30("LayerHighlight",1);
      iVar2 = 0;
      param_2 = 0;
      switch(DAT_00735dec) {
      case 0:
        param_2 = 0x22;
        iVar2 = 0x36;
        break;
      case 1:
        param_2 = 0x21;
        iVar2 = 0x32;
        break;
      case 2:
        param_2 = 0x20;
        iVar2 = 0x2e;
        break;
      case 3:
        param_2 = 0x1f;
        iVar2 = 0x2a;
      }
      if (bVar4) {
        local_8 = param_2 + 1;
        iVar3 = iVar2 + 4;
      }
      else {
        local_8 = param_2 + -1;
        iVar3 = iVar2 + -4;
      }
      if (local_8 < 0x1f) {
        local_8 = 0x22;
      }
      else if (0x22 < local_8) {
        local_8 = 0x1f;
      }
      if (iVar3 < 0x2a) {
        iVar3 = 0x36;
      }
      else if (0x36 < iVar3) {
        iVar3 = 0x2a;
      }
      local_18 = (&DAT_00745b6c)[param_2];
      local_2c = (&DAT_00745b6c)[local_8];
      if ((local_18 != 0) || (local_2c != 0)) {
        local_c = *(undefined4 *)(&DAT_00745b70 + iVar2 * 4);
        local_10 = (&DAT_00745b74)[iVar2];
        local_14 = *(undefined4 *)(&DAT_00745b78 + iVar2 * 4);
        local_1c = (&DAT_00745b6c)[iVar3];
        local_20 = *(undefined4 *)(&DAT_00745b70 + iVar3 * 4);
        local_28 = *(undefined4 *)(&DAT_00745b78 + iVar3 * 4);
        local_24 = (&DAT_00745b74)[iVar3];
        GarageManager__InstallPart((&DAT_00745b6c)[iVar2],1);
        GarageManager__InstallPart(local_c,1);
        GarageManager__InstallPart(local_10,1);
        GarageManager__InstallPart(local_14,1);
        GarageManager__InstallPart(local_18,0);
        GarageManager__InstallPart(local_1c,1);
        GarageManager__InstallPart(local_20,1);
        GarageManager__InstallPart(local_24,1);
        GarageManager__InstallPart(local_28,1);
        GarageManager__InstallPart(local_2c,0);
        return;
      }
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004e3060();
    FUN_004e3160(param_1);
    FUN_004e31c0();
    FUN_004f7d30();
    FUN_004e3960();
    iVar2 = 0;
    while (cVar1 = FUN_004f7f10(param_1), cVar1 == '\0') {
      iVar2 = iVar2 + 1;
      if (3 < iVar2) {
        return;
      }
    }
    if (iVar2 != *(int *)(param_1 + 0x50)) {
      DAT_00735dec = iVar2;
      FUN_004e3060();
      FUN_004e3160(param_1);
      *(int *)(param_1 + 0x50) = iVar2;
    }
  }
  return;
}


// ==== 0x4e3960 FUN_004e3960

void FUN_004e3960(void)

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
        if (iVar2 == -0x7f4b4301) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar7 = *(int *)(iVar2 + 0x18), iVar7 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar6 = 0xc519bfc0;
LAB_004e3a47:
            (**(code **)(*piVar3 + 8))(uVar6,0,0,iVar7);
          }
        }
        else if (iVar2 == -0x25691071) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar2 != 0) && (iVar7 = *(int *)(iVar2 + 0x18), iVar7 != 0)) &&
             (piVar3 = *(int **)(iVar2 + 0x14), piVar3 != (int *)0x0)) {
            uVar6 = 0xc519bfc1;
            goto LAB_004e3a47;
          }
        }
        else if (iVar2 == -0x2565c62b) {
          FUN_004c96c0(0xc519bfc2);
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


// ==== 0x4e3a60 FUN_004e3a60

undefined4 FUN_004e3a60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687a63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x74);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004e2a00(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e3ac0 FUN_004e3ac0

void __fastcall FUN_004e3ac0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c317c;
  FUN_004e2170();
  return;
}


// ==== 0x4e3ad0 FUN_004e3ad0

void * __thiscall FUN_004e3ad0(void *param_1,byte param_2)

{
  FUN_004e3ac0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e3af0 FUN_004e3af0

undefined4 FUN_004e3af0(void)

{
  char cVar1;
  
  if (DAT_00735ec1 == '\0') {
    cVar1 = PartStore__HasPart(&DAT_0075f344);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}


// ==== 0x4e3b10 FUN_004e3b10

uint FUN_004e3b10(char param_1)

{
  undefined4 *puVar1;
  char cVar2;
  char extraout_AL;
  char extraout_AL_00;
  char extraout_AL_01;
  undefined4 *puVar3;
  int iVar4;
  undefined3 uVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  undefined3 extraout_var_01;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint unaff_EDI;
  
  puVar1 = DAT_0073ad40;
  if (0xe < (int)unaff_EDI) {
    if ((int)unaff_EDI < 0x11) {
      puVar3 = (undefined4 *)NullUpdate_ret();
      cVar2 = DAT_00735ec1;
      for (; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
        uVar10 = puVar1[3];
        uVar8 = puVar1[4] * 0x30 + uVar10;
        for (; uVar10 < uVar8; uVar10 = uVar10 + 0x30) {
          if (*(char *)(uVar10 + 0x10) == '\x1f') goto LAB_004e3c4a;
        }
      }
      uVar10 = 0;
LAB_004e3c4a:
      if (uVar10 == 0) goto LAB_004e3c0a;
      while (((*(byte *)(uVar10 + 0x12) != unaff_EDI ||
              (((uVar5 = UserProfile__IsStyleRewardUnlocked
                                   (&DAT_007588c4,2,*(undefined4 *)(uVar10 + 8)),
                (char)uVar5 == '\0' && (cVar2 == '\0')) &&
               (uVar5 = PartStore__HasPart(&DAT_0075f344), (char)uVar5 == '\0')))) ||
             (((uVar6 = (undefined3)((uint)uVar5 >> 8), param_1 != '\0' && (cVar2 == '\0')) &&
              (PartStore__HasPart(&DAT_0075f344), uVar6 = extraout_var_00, extraout_AL_00 == '\0')))
             )) {
        uVar10 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar10,0xffffffff);
        if (uVar10 == 0) {
          return 0;
        }
      }
      goto LAB_004e3d64;
    }
    if (unaff_EDI == 0x11) {
      puVar3 = (undefined4 *)NullUpdate_ret();
      for (; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
        puVar9 = (undefined4 *)puVar1[3];
        puVar7 = puVar9 + puVar1[4] * 0xc;
        for (; puVar9 < puVar7; puVar9 = puVar9 + 0xc) {
          if (*(char *)(puVar9 + 4) == '\x1f') goto joined_r0x004e3b70;
        }
      }
      puVar9 = (undefined4 *)0x0;
joined_r0x004e3b70:
      do {
        if (puVar9 == (undefined4 *)0x0) goto LAB_004e3c0a;
        if ((*(char *)((int)puVar9 + 0x12) == '\x11') && (iVar4 = FUN_004e2520(puVar9), iVar4 != 0))
        {
          switch(iVar4) {
          case 1:
            break;
          case 2:
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          default:
            goto switchD_004e3b8e_default;
          }
          uVar5 = bStringHash();
          uVar5 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar5);
          uVar6 = (undefined3)((uint)uVar5 >> 8);
          if (((char)uVar5 != '\0') &&
             ((param_1 == '\0' || (FUN_004e3af0(), uVar6 = extraout_var, extraout_AL != '\0'))))
          goto LAB_004e3d64;
        }
switchD_004e3b8e_default:
        puVar3 = (undefined4 *)CarPartDatabase__GetCarPart(0,0x1f,0,puVar9,0xffffffff);
        puVar9 = puVar3;
      } while( true );
    }
  }
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
    uVar10 = puVar1[3];
    uVar8 = puVar1[4] * 0x30 + uVar10;
    for (; uVar10 < uVar8; uVar10 = uVar10 + 0x30) {
      if (*(char *)(uVar10 + 0x10) == '\x1f') goto LAB_004e3d07;
    }
  }
  uVar10 = 0;
LAB_004e3d07:
  if (uVar10 == 0) {
LAB_004e3c0a:
    return (uint)puVar3 & 0xffffff00;
  }
  while ((uVar5 = FUN_004e3d80(), (char)uVar5 == '\0' ||
         (((uVar6 = (undefined3)((uint)uVar5 >> 8), param_1 != '\0' && (DAT_00735ec1 == '\0')) &&
          (PartStore__HasPart(&DAT_0075f344), uVar6 = extraout_var_01, extraout_AL_01 == '\0'))))) {
    uVar10 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar10,0xffffffff);
    if (uVar10 == 0) {
      return 0;
    }
  }
LAB_004e3d64:
  return CONCAT31(uVar6,1);
}


// ==== 0x4e3d80 FUN_004e3d80

undefined4 FUN_004e3d80(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (param_2 < 1) {
    return 0;
  }
  if (3 < param_2) {
    return 0;
  }
  switch(param_1) {
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
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  default:
    goto switchD_004e3dd4_default;
  }
  bStrCpy();
  if (param_2 == 1) {
    puVar3 = &DAT_006c59e8;
LAB_004e3e69:
    bStrCat2(puVar3);
  }
  else {
    if (param_2 == 2) {
      puVar3 = &DAT_006c59e4;
      goto LAB_004e3e69;
    }
    if (param_2 == 3) {
      puVar3 = &DAT_006c59e0;
      goto LAB_004e3e69;
    }
  }
  uVar2 = bStringHash();
  cVar1 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,0,uVar2);
  if (cVar1 != '\0') {
    if ((char)param_3 != '\0') {
      uVar2 = FUN_004e3b10(param_3);
      return uVar2;
    }
    return 1;
  }
switchD_004e3dd4_default:
  return 0;
}


// ==== 0x4e3f00 FUN_004e3f00

undefined4 FUN_004e3f00(void)

{
  char cVar1;
  
  cVar1 = FUN_004e3d80();
  if (cVar1 == '\0') {
    cVar1 = FUN_004e3d80();
    if (cVar1 == '\0') {
      cVar1 = FUN_004e3d80();
      if (cVar1 == '\0') {
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x4e3f40 FUN_004e3f40

uint FUN_004e3f40(undefined4 param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  char extraout_AL;
  char extraout_AL_00;
  char cVar3;
  char extraout_AL_01;
  undefined4 *puVar4;
  int iVar5;
  undefined3 uVar7;
  undefined3 extraout_var;
  undefined4 uVar6;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar8;
  uint uVar9;
  char cVar10;
  
  puVar2 = DAT_0073ad40;
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; cVar10 = DAT_00735ec1, puVar2 != puVar4; puVar2 = (undefined4 *)*puVar2) {
    uVar9 = puVar2[3];
    uVar8 = puVar2[4] * 0x30 + uVar9;
    for (; uVar9 < uVar8; uVar9 = uVar9 + 0x30) {
      if (*(char *)(uVar9 + 0x10) == '\x1f') goto joined_r0x004e3f81;
    }
  }
  uVar9 = 0;
joined_r0x004e3f81:
  do {
    if (uVar9 == 0) {
      return (uint)puVar4 & 0xffffff00;
    }
    bVar1 = *(byte *)(uVar9 + 0x12);
    if (bVar1 < 0xf) {
LAB_004e4079:
      FUN_004e3d80(bVar1,*(undefined1 *)(uVar9 + 0x11),param_1);
      cVar10 = DAT_00735ec1;
      uVar7 = extraout_var_01;
      cVar3 = extraout_AL_01;
joined_r0x004e4075:
      if (cVar3 != '\0') {
LAB_004e402e:
        return CONCAT31(uVar7,1);
      }
    }
    else {
      if (bVar1 < 0x11) {
        uVar6 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,*(undefined4 *)(uVar9 + 8));
        if ((((char)uVar6 == '\0') && (cVar10 == '\0')) &&
           (uVar6 = PartStore__HasPart(&DAT_0075f344), (char)uVar6 == '\0'))
        goto switchD_004e3fca_default;
        uVar7 = (undefined3)((uint)uVar6 >> 8);
        if (((char)param_1 == '\0') || (cVar10 != '\0')) goto LAB_004e402e;
        PartStore__HasPart(&DAT_0075f344);
        uVar7 = extraout_var_00;
        cVar3 = extraout_AL_00;
        goto joined_r0x004e4075;
      }
      if (bVar1 != 0x11) goto LAB_004e4079;
      iVar5 = FUN_004e2520(uVar9);
      if (iVar5 != 0) {
        switch(iVar5) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        default:
          goto switchD_004e3fca_default;
        }
        uVar6 = bStringHash();
        uVar6 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar6);
        uVar7 = (undefined3)((uint)uVar6 >> 8);
        if ((char)uVar6 != '\0') {
          if (((char)param_1 == '\0') || (cVar10 != '\0')) goto LAB_004e402e;
          PartStore__HasPart(&DAT_0075f344);
          uVar7 = extraout_var;
          cVar3 = extraout_AL;
          goto joined_r0x004e4075;
        }
      }
    }
switchD_004e3fca_default:
    uVar9 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar9,0xffffffff);
    puVar4 = (undefined4 *)0x0;
  } while( true );
}


// ==== 0x4e40d0 GarageVinylTypeScreen::GarageVinylTypeScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageVinylTypeScreen__GarageVinylTypeScreen(undefined4 *param_1,uint param_2)

{
  char *pcVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688c18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004e21e0(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006c317c;
  FEngSetAllObjectsInPackageVisibility("MU_HorizontalBrowserBack.fng",1);
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (*(int **)(iVar5 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar5 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar5 + 0x18));
  }
  if (DAT_00745e40 == 1) {
    uVar2 = FUN_005a3710();
    pcVar6 = "VINYL_GROUP_MANUFACTURAR_NAME";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    FUN_004e2250(0xfe10f96,0,"MU_GarageVinylGroup.fng",uVar2,0);
    uVar2 = FUN_005a3730();
    pcVar6 = "VINYL_GROUP_MANUFACTURAR_HOOD_LOGO";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    FUN_004e2250(0xfdb225b,1,"MU_GarageVinylGroup.fng",uVar2,0);
    uVar10 = DAT_00760294 & 0x3fffffff;
    pcVar6 = "VINYL_GROUP_MANUFACTURAR_LOGO";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    cVar3 = FUN_004e3b10(0);
    FUN_004e2250(0xd3f477de,2,"MU_GarageVinylBrowser.fng",uVar10 != 0,'\x01' - (cVar3 != '\0'));
    bVar4 = (byte)DAT_00760290 & 0x3e;
    pcVar6 = "VINYL_GROUP_BODY_VINYL";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    cVar3 = FUN_004e3b10(0);
    FUN_004e2250(0xfd7d6bf,3,"MU_GarageVinylBrowser.fng",bVar4 != 0,'\x01' - (cVar3 != '\0'));
    bVar4 = FUN_005a36f0();
    param_2 = (uint)bVar4;
    pcVar6 = "VINYL_GROUP_UNIQUES";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    cVar3 = FUN_004e3b10(0);
    uVar10 = (uint)(byte)(1 - (cVar3 != '\0'));
    pcVar6 = "MU_GarageVinylBrowser.fng";
    uVar8 = 4;
    uVar7 = 0x916b1508;
  }
  else {
    if (DAT_00745e40 != 2) goto LAB_004e4582;
    cVar3 = FUN_004e3f00(0);
    if ((((cVar3 != '\0') || (cVar3 = FUN_004e3f00(0), cVar3 != '\0')) ||
        ((cVar3 = FUN_004e3f00(0), cVar3 != '\0' ||
         ((cVar3 = FUN_004e3f00(0), cVar3 != '\0' || (cVar3 = FUN_004e3f00(0), cVar3 != '\0'))))))
       || ((cVar3 = FUN_004e3f00(0), cVar3 != '\0' ||
           (((cVar3 = FUN_004e3f00(0), cVar3 != '\0' || (cVar3 = FUN_004e3f00(0), cVar3 != '\0')) ||
            (cVar3 = FUN_004e3f00(0), cVar3 != '\0')))))) {
      uVar2 = FUN_005a3710();
      pcVar6 = "VINYL_GROUP_MANUFACTURAR_NAME";
      do {
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar1 != '\0');
      FUN_004e2250(0xfe10f96,0,"MU_GarageVinylGroup.fng",uVar2,0);
    }
    cVar3 = FUN_004e3f00(0);
    if (((cVar3 != '\0') || (cVar3 = FUN_004e3f00(0), cVar3 != '\0')) ||
       (((cVar3 = FUN_004e3f00(0), cVar3 != '\0' ||
         ((cVar3 = FUN_004e3f00(0), cVar3 != '\0' || (cVar3 = FUN_004e3f00(0), cVar3 != '\0')))) ||
        (cVar3 = FUN_004e3f00(0), cVar3 != '\0')))) {
      uVar2 = FUN_005a3730();
      pcVar6 = "VINYL_GROUP_MANUFACTURAR_HOOD_LOGO";
      do {
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar1 != '\0');
      FUN_004e2250(0xfdb225b,1,"MU_GarageVinylGroup.fng",uVar2,0);
    }
    cVar3 = FUN_004e3b10(0);
    if (cVar3 != '\0') {
      param_2 = (uint)((DAT_00760294 & 0x3fffffff) != 0);
      uVar9 = 0;
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar8 = 2;
      uVar7 = 0xd3f477de;
      bStringHash(0xd3f477de,2,"MU_GarageVinylBrowser.fng",param_2,0);
      FUN_004e2250(uVar7,uVar8,pcVar6,param_2,uVar9);
    }
    cVar3 = FUN_004e3b10(0);
    if (cVar3 != '\0') {
      param_2 = (uint)(((byte)DAT_00760290 & 0x3e) != 0);
      uVar9 = 0;
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar8 = 3;
      uVar7 = 0xfd7d6bf;
      bStringHash(0xfd7d6bf,3,"MU_GarageVinylBrowser.fng",param_2,0);
      FUN_004e2250(uVar7,uVar8,pcVar6,param_2,uVar9);
    }
    cVar3 = FUN_004e3b10(0);
    if (cVar3 == '\0') goto LAB_004e4582;
    bVar4 = FUN_005a36f0();
    param_2 = (uint)bVar4;
    uVar10 = 0;
    pcVar6 = "MU_GarageVinylBrowser.fng";
    uVar8 = 4;
    uVar7 = 0x916b1508;
    bStringHash(0x916b1508,4,"MU_GarageVinylBrowser.fng",param_2,0);
  }
  FUN_004e2250(uVar7,uVar8,pcVar6,param_2,uVar10);
LAB_004e4582:
  FUN_004e23d0();
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4e45b0 GarageVinylTypeScreen::RedrawHeading

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageVinylTypeScreen__RedrawHeading(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  FUN_00495f00(*(undefined4 *)(iVar1 + 0xc));
  if (*(char *)(iVar1 + 0x14) != '\0') {
    FUN_00414a60();
    ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
    return;
  }
  FUN_00414a10();
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  return;
}


// ==== 0x4e4610 GarageVinylTypeScreen::OptionChosen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

bool __fastcall GarageVinylTypeScreen__OptionChosen(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  DAT_00735df0 = *(int *)(*(int *)(param_1 + 0x40) + 8);
  if (*(char *)(*(int *)(param_1 + 0x40) + 0x14) != '\0') {
    return false;
  }
  if (DAT_00735df0 == 1) {
    if (DAT_00745b8c != 0) {
      iVar2 = bStringHash();
      iVar3 = bStringHash();
      if (iVar2 != iVar3) {
        uStack_24 = 0x780885f9;
        uStack_1c = 0x780885f9;
        uStack_14 = 0xed716986;
        uStack_10 = 0xed716986;
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_20 = 0xf770;
        uStack_18 = 0x61c;
        uStack_c = 0xb8a7c6cc;
        FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return false;
      }
    }
  }
  else if (DAT_00735df0 == 3) {
    DAT_00735de4 = 0x11;
  }
  else {
    if (DAT_00735df0 == 4) {
      DAT_00735de4 = 0xf;
      bVar1 = DAT_00745bf0 == 0 && (DAT_00745bec == 0 && DAT_00745be8 == 0);
      if (DAT_00745bf4 == 0) {
        if (DAT_00745bf0 == 0 && (DAT_00745bec == 0 && DAT_00745be8 == 0)) {
          DAT_00735de4 = 0xf;
          return bVar1;
        }
      }
      else {
        bVar1 = false;
      }
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_14 = 0xed716986;
      uStack_10 = 0xed716986;
      uStack_24 = 0xae3397d2;
      uStack_1c = 0x423af469;
      uStack_20 = 0x639;
      uStack_18 = 0x541389e5;
      uStack_c = 0xb8a7c6cc;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return bVar1;
    }
    if (DAT_00735df0 == 2) {
      DAT_00735de4 = 0x10;
    }
  }
  bVar1 = false;
  if ((DAT_00745be8 != 0) && (*(char *)(DAT_00745be8 + 0x12) == '\x0f')) {
    bVar1 = true;
  }
  if ((DAT_00745bec != 0) && (*(char *)(DAT_00745bec + 0x12) == '\x0f')) {
    bVar1 = true;
  }
  if ((DAT_00745bf0 != 0) && (*(char *)(DAT_00745bf0 + 0x12) == '\x0f')) {
    bVar1 = true;
  }
  if (((DAT_00745bf4 == 0) || (*(char *)(DAT_00745bf4 + 0x12) != '\x0f')) && (!bVar1)) {
    return true;
  }
  uStack_8 = 0;
  uStack_4 = 0;
  uStack_24 = 0x36dd79f4;
  uStack_1c = 0x423af469;
  uStack_20 = 0x639;
  uStack_14 = 0xed716986;
  uStack_18 = 0x541389e5;
  uStack_10 = 0xed716986;
  uStack_c = 0xb8a7c6cc;
  FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  return false;
}


// ==== 0x4e4745 FUN_004e4745

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


// ==== 0x4e4840 GarageVinylTypeScreen::NotificationMessage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageVinylTypeScreen__NotificationMessage
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  char *pcVar10;
  byte *pbVar11;
  int *piVar12;
  int *local_8;
  
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  iVar7 = DAT_0073578c;
  if ((((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar6 = FEPackageList__FindByName(&DAT_00746104), iVar6 != 0 && (*(int *)(iVar6 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar7 + 8),*(int *)(iVar6 + 0x18));
  }
  if (param_1 == 0x423af469) {
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
  }
  else if (param_1 == 0x780885f9) {
    iVar7 = FECarConfig__GetCarType();
    iVar6 = 0;
    if (iVar7 != 0x23) {
      if (iVar7 * 0xc90 + DAT_00734588 == 0) goto LAB_004e4a53;
      iVar6 = bStringHash();
    }
    piVar9 = DAT_0073ad40;
    local_8 = DAT_0073ad40;
    piVar8 = (int *)NullUpdate_ret();
    if (piVar9 != piVar8) {
      while( true ) {
        piVar9 = (int *)local_8[3];
        piVar12 = piVar9 + local_8[4] * 0xc;
        if ((iVar6 != 0) &&
           (piVar9 = (int *)BinarySearch_Hash(iVar6,piVar9,4), piVar9 == (int *)0x0)) break;
        for (; piVar9 < piVar12; piVar9 = piVar9 + 0xc) {
          if ((iVar6 != 0) && (piVar9[1] != iVar6)) goto LAB_004e49a2;
          if ((char)piVar9[4] == '\b') goto LAB_004e49a4;
        }
        local_8 = (int *)*local_8;
        if (local_8 == piVar8) break;
      }
    }
LAB_004e49a2:
    piVar9 = (int *)0x0;
LAB_004e49a4:
    if (piVar9 != (int *)0x0) {
      bVar5 = true;
      do {
        if (!bVar5) break;
        pcVar10 = "STOCK";
        do {
          cVar2 = pcVar10[*piVar9 + -0x6c3200];
          cVar3 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          if ((cVar2 == '\0') || (cVar3 == '\0')) break;
        } while (cVar2 == cVar3);
        if (cVar2 == cVar3) {
          bVar5 = false;
        }
        else {
          iVar6 = FECarConfig__GetCarType();
          iVar7 = 0;
          if (iVar6 != 0x23) {
            iVar7 = iVar6 * 0xc90 + DAT_00734588;
            if (iVar7 == 0) {
              iVar7 = 0;
            }
            else {
              pbVar11 = (byte *)(iVar7 + 0x20);
              iVar7 = -1;
              bVar4 = *pbVar11;
              while (bVar4 != 0) {
                iVar7 = iVar7 * 0x21 + (uint)bVar4;
                pbVar1 = pbVar11 + 1;
                pbVar11 = pbVar11 + 1;
                bVar4 = *pbVar1;
              }
            }
          }
          piVar9 = (int *)CarPartDatabase__GetCarPart(iVar7,8,0,piVar9,0xffffffff);
        }
      } while (piVar9 != (int *)0x0);
      GarageManager__InstallPart(piVar9,0);
    }
  }
LAB_004e4a53:
  if (DAT_00735df4 != '\0') {
    ThresholdTable_MarkReached(&DAT_007588c4,DAT_00758ad4);
    DAT_00735df4 = '\0';
  }
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylGroup.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylLayerV2.fng");
  GarageManager__PopAllScreensOfCertainName("MU_GarageVinylBrowser.fng");
  GarageManager__PushScreen("MU_GarageVinylLayerV2.fng");
  FUN_004e2430(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x4e494d FUN_004e494d

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
    ThresholdTable_MarkReached(&DAT_007588c4);
    DAT_00735df4 = '\0';
  }
  GarageManager__PopAllScreensOfCertainName();
  GarageManager__PopAllScreensOfCertainName();
  GarageManager__PopAllScreensOfCertainName();
  GarageManager__PushScreen();
  FUN_004e2430(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  return;
}


// ==== 0x4e4ae0 CreateVinylTypeScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateVinylTypeScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006890f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageVinylTypeScreen__GarageVinylTypeScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e4b40 FUN_004e4b40

void __fastcall FUN_004e4b40(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c313c;
  FUN_004e2170();
  return;
}


// ==== 0x4e4b50 FUN_004e4b50

void * __thiscall FUN_004e4b50(void *param_1,byte param_2)

{
  FUN_004e4b40();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e4b70 FUN_004e4b70

undefined4 FUN_004e4b70(byte param_1)

{
  uint uVar1;
  
  if (param_1 < 0xb) {
    uVar1 = 1 << (param_1 * '\x03' + 1 & 0x1f) & DAT_00760288;
  }
  else {
    uVar1 = 1 << ((param_1 - 0xb) * '\x03' + 1 & 0x1f) & DAT_0076028c;
  }
  if (uVar1 == 0) {
    if (param_1 < 0xb) {
      uVar1 = 1 << (param_1 * '\x03' + 2 & 0x1f) & DAT_00760288;
    }
    else {
      uVar1 = 1 << ((param_1 - 0xb) * '\x03' + 2 & 0x1f) & DAT_0076028c;
    }
    if (uVar1 == 0) {
      if (param_1 != 10) {
        if (param_1 < 0xb) {
          uVar1 = 1 << ((param_1 + 1) * '\x03' & 0x1f) & DAT_00760288;
        }
        else {
          uVar1 = 1 << ((param_1 - 10) * '\x03' & 0x1f) & DAT_0076028c;
        }
        if (uVar1 != 0) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}


// ==== 0x4e4c40 GarageVinylGroupScreen::GarageVinylGroupScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageVinylGroupScreen__GarageVinylGroupScreen(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688c18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004e21e0(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006c313c;
  FEngSetAllObjectsInPackageVisibility("MU_HorizontalBrowserBack.fng",1);
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar2 + 0x18));
  }
  iVar2 = DAT_00745e40;
  if (DAT_00735df0 == 0) {
    if (DAT_00745e40 == 1) {
      if ((((DAT_00760288 & 2) == 0) && ((DAT_00760288 & 4) == 0)) && ((DAT_00760288 & 8) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 0;
      uVar4 = 0x695654a8;
      bStringHash(0x695654a8,0,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_00760288 & 0x80) == 0) && ((DAT_00760288 & 0x100) == 0)) &&
         ((DAT_00760288 & 0x200) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 2;
      uVar4 = 0x17019c53;
      bStringHash(0x17019c53,2,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_00760288 & 0x2000) == 0) && ((DAT_00760288 & 0x4000) == 0)) &&
         ((DAT_00760288 & 0x8000) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 4;
      uVar4 = 0x16b5ce67;
      bStringHash(0x16b5ce67,4,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_00760288 & 0x10000) == 0) && ((DAT_00760288 & 0x20000) == 0)) &&
         ((DAT_00760288 & 0x40000) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 5;
      uVar4 = 0x8a07001;
      bStringHash(0x8a07001,5,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_00760288 & 0x400000) == 0) && ((DAT_00760288 & 0x800000) == 0)) &&
         ((DAT_00760288 & 0x1000000) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 7;
      uVar4 = 0x932768e1;
      bStringHash(0x932768e1,7,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_00760288 & 0x10000000) == 0) && ((DAT_00760288 & 0x20000000) == 0)) &&
         ((DAT_00760288 & 0x40000000) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 9;
      uVar4 = 0xf2173020;
      bStringHash(0xf2173020,9,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_0076028c & 2) == 0) && ((DAT_0076028c & 4) == 0)) && ((DAT_0076028c & 8) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 0xb;
      uVar4 = 0x694ec516;
      bStringHash(0x694ec516,0xb,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_0076028c & 0x10) == 0) && ((DAT_0076028c & 0x20) == 0)) &&
         ((DAT_0076028c & 0x40) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 0xc;
      uVar4 = 0x192d84da;
      bStringHash(0x192d84da,0xc,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      if ((((DAT_0076028c & 0x400) == 0) && ((DAT_0076028c & 0x800) == 0)) &&
         ((DAT_0076028c & 0x1000) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
    }
    else {
      if (DAT_00745e40 != 2) goto LAB_004e5567;
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        if ((((DAT_00760288 & 2) == 0) && ((DAT_00760288 & 4) == 0)) && ((DAT_00760288 & 8) == 0)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        uVar7 = 0;
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 0;
        uVar4 = 0x695654a8;
        bStringHash(0x695654a8,0,"MU_GarageVinylBrowser.fng",uVar3,0);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        if ((((DAT_00760288 & 0x80) == 0) && ((DAT_00760288 & 0x100) == 0)) &&
           ((DAT_00760288 & 0x200) == 0)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        uVar7 = 0;
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 2;
        uVar4 = 0x17019c53;
        bStringHash(0x17019c53,2,"MU_GarageVinylBrowser.fng",uVar3,0);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        if ((((DAT_00760288 & 0x2000) == 0) && ((DAT_00760288 & 0x4000) == 0)) &&
           ((DAT_00760288 & 0x8000) == 0)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        uVar7 = 0;
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 4;
        uVar4 = 0x16b5ce67;
        bStringHash(0x16b5ce67,4,"MU_GarageVinylBrowser.fng",uVar3,0);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(5,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 5;
        uVar4 = 0x8a07001;
        bStringHash(0x8a07001,5,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(7,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 7;
        uVar4 = 0x932768e1;
        bStringHash(0x932768e1,7,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(9,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 9;
        uVar4 = 0xf2173020;
        bStringHash(0xf2173020,9,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(0xb,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 0xb;
        uVar4 = 0x694ec516;
        bStringHash(0x694ec516,0xb,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(0xc,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 0xc;
        uVar4 = 0x192d84da;
        bStringHash(0x192d84da,0xc,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 == '\0') goto LAB_004e5567;
      uVar8 = 0;
      uVar3 = FUN_004e4b70(0xe,0);
    }
    uVar5 = 0xe;
    uVar4 = 0x69580c2c;
  }
  else {
    if (DAT_00735df0 != 1) goto LAB_004e5567;
    if (DAT_00745e40 == 1) {
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      uVar3 = FUN_004e4b70(1,uVar8);
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar4 = 0x20693e72;
      bStringHash(0x20693e72,1,"MU_GarageVinylBrowser.fng",uVar3);
      FUN_004e2250(uVar4,iVar2,pcVar6,uVar3,uVar8);
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      uVar3 = FUN_004e4b70(3,uVar8);
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 3;
      uVar4 = 0xbc76639d;
      bStringHash(0xbc76639d,3,"MU_GarageVinylBrowser.fng",uVar3);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      uVar3 = FUN_004e4b70(6,uVar8);
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 6;
      uVar4 = 0x43935e4b;
      bStringHash(0x43935e4b,6,"MU_GarageVinylBrowser.fng",uVar3);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
      uVar3 = FUN_004e4b70(8,uVar8);
      pcVar6 = "MU_GarageVinylBrowser.fng";
      uVar5 = 8;
      uVar4 = 0x38abc72b;
      bStringHash(0x38abc72b,8,"MU_GarageVinylBrowser.fng",uVar3);
      FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
      cVar1 = FUN_004e3f00(0);
      uVar8 = (uint)(byte)(1 - (cVar1 != '\0'));
    }
    else {
      if (DAT_00745e40 != 2) goto LAB_004e5567;
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(1,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 1;
        uVar4 = 0x20693e72;
        bStringHash(0x20693e72,1,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(3,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 3;
        uVar4 = 0xbc76639d;
        bStringHash(0xbc76639d,3,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(6,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 6;
        uVar4 = 0x43935e4b;
        bStringHash(0x43935e4b,6,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 != '\0') {
        uVar7 = 0;
        uVar3 = FUN_004e4b70(8,0);
        pcVar6 = "MU_GarageVinylBrowser.fng";
        uVar5 = 8;
        uVar4 = 0x38abc72b;
        bStringHash(0x38abc72b,8,"MU_GarageVinylBrowser.fng",uVar3);
        FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar7);
      }
      cVar1 = FUN_004e3f00(0);
      if (cVar1 == '\0') goto LAB_004e5567;
      uVar8 = 0;
    }
    uVar3 = FUN_004e4b70(0xd,uVar8);
    uVar5 = 0xd;
    uVar4 = 0x4be137a4;
  }
  pcVar6 = "MU_GarageVinylBrowser.fng";
  bStringHash(uVar4,uVar5,"MU_GarageVinylBrowser.fng",uVar3,uVar8);
  FUN_004e2250(uVar4,uVar5,pcVar6,uVar3,uVar8);
LAB_004e5567:
  FUN_004e23d0();
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4e5590 GarageVinylGroupScreen::OptionChosen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall GarageVinylGroupScreen__OptionChosen(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  DAT_00735de4 = *(undefined4 *)(iVar1 + 8);
  return CONCAT31((int3)((uint)iVar1 >> 8),*(char *)(iVar1 + 0x14) == '\0');
}


// ==== 0x4e55b0 GarageVinylGroupScreen::NotificationMessage

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __thiscall
GarageVinylGroupScreen__NotificationMessage
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  (**(code **)(*param_1 + 0x10))();
  FUN_004e2430(param_2,param_3,param_4,param_5);
  return;
}


// ==== 0x4e5630 FUN_004e5630

undefined4 FUN_004e5630(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006890d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageVinylGroupScreen__GarageVinylGroupScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e5690 FUN_004e5690

int FUN_004e5690(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 == 3) || (in_stack_00000014 == 4)) {
    in_stack_00000014 = 0;
  }
  return in_stack_00000014;
}


// ==== 0x4e56b0 FUN_004e56b0

void FUN_004e56b0(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (((unaff_EDI != 0) && (0x1e < unaff_ESI)) && (unaff_ESI < 0x23)) {
    iVar1 = 0x1f;
    do {
      if (((iVar1 != unaff_ESI) && ((&DAT_00745b6c)[iVar1] != 0)) &&
         (*(int *)((&DAT_00745b6c)[iVar1] + 8) == *(int *)(unaff_EDI + 8))) {
        GarageManager__InstallPart(0,1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x23);
  }
  return;
}


// ==== 0x4e5700 GarageVinylBrowserScreen::GarageVinylBrowserScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 *
GarageVinylBrowserScreen__GarageVinylBrowserScreen(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  undefined1 local_11;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688c18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004e21e0(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006c3194;
  DAT_00735df5 = 0;
  DAT_00735df6 = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  FEngSetAllObjectsInPackageVisibility("MU_HorizontalBrowserBack.fng",1);
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 != 0) && (*(int *)(iVar7 + 0x18) != 0)) && (*(int **)(iVar7 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar7 + 0x14) + 8))(0x50fe5db4,0,0,*(int *)(iVar7 + 0x18));
  }
  puVar2 = DAT_0073ad40;
  puVar8 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar8; puVar2 = (undefined4 *)*puVar2) {
    local_28 = puVar2[3];
    uVar10 = puVar2[4] * 0x30 + local_28;
    for (; local_28 < uVar10; local_28 = local_28 + 0x30) {
      if (*(char *)(local_28 + 0x10) == '\x1f') goto LAB_004e57cc;
    }
  }
  local_28 = 0;
LAB_004e57cc:
  iVar7 = DAT_006fa1a0 + -0x1f;
  local_18 = local_28;
  switch(iVar7) {
  case 0:
    param_1[0x22] = DAT_00745c14;
    param_1[0x23] = DAT_00745c18;
    param_1[0x24] = DAT_00745c1c;
    uVar9 = DAT_00745c20;
    goto LAB_004e58a8;
  case 1:
    param_1[0x22] = DAT_00745c24;
    param_1[0x23] = DAT_00745c28;
    param_1[0x24] = DAT_00745c2c;
    param_1[0x25] = DAT_00745c30;
    break;
  case 2:
    param_1[0x22] = DAT_00745c34;
    param_1[0x23] = DAT_00745c38;
    param_1[0x24] = DAT_00745c3c;
    param_1[0x25] = DAT_00745c40;
    break;
  case 3:
    param_1[0x22] = DAT_00745c44;
    param_1[0x23] = DAT_00745c48;
    param_1[0x24] = DAT_00745c4c;
    uVar9 = DAT_00745c50;
LAB_004e58a8:
    param_1[0x25] = uVar9;
  }
  if (param_1[0x22] == 0) {
    GetDefaultVinylColors(&local_1c,&local_20,&local_24);
    switch(iVar7) {
    case 0:
      GarageManager__InstallPart(param_2,0);
      GarageManager__InstallPart(local_1c,0);
      GarageManager__InstallPart(local_20,0);
      break;
    case 1:
      GarageManager__InstallPart(param_2,0);
      GarageManager__InstallPart(local_1c,0);
      GarageManager__InstallPart(local_20,0);
      break;
    case 2:
      GarageManager__InstallPart(param_2,0);
      GarageManager__InstallPart(local_1c,0);
      GarageManager__InstallPart(local_20,0);
      break;
    case 3:
      GarageManager__InstallPart(param_2,0);
      GarageManager__InstallPart(local_1c,0);
      GarageManager__InstallPart(local_20,0);
      break;
    default:
      goto switchD_004e58dd_default;
    }
    GarageManager__InstallPart(local_24,0);
  }
switchD_004e58dd_default:
  switch(DAT_00735de4) {
  case 1:
  case 3:
  case 6:
  case 8:
  case 10:
  case 0xd:
    iVar7 = FUN_004b2330();
    break;
  default:
    iVar7 = FUN_004b2330();
  }
  uVar10 = local_18;
  if (iVar7 != 0) {
    FUN_004b0150();
    uVar10 = local_18;
  }
  do {
    local_18 = uVar10;
    if (local_28 == 0) {
      FUN_004e23d0();
      GarageManager__PreviewPart();
      ExceptionList = local_10;
      return param_1;
    }
    cVar4 = FilterVinylPart();
    if (cVar4 != '\0') {
      if (DAT_006fa1a0 == 0x22) {
        iVar7 = 1;
      }
      else if (DAT_006fa1a0 == 0x21) {
        iVar7 = 2;
      }
      else if (DAT_006fa1a0 == 0x20) {
        iVar7 = 3;
      }
      else {
        iVar7 = ((DAT_006fa1a0 != 0x1f) - 1 & 5) - 1;
      }
      local_24 = ComputeVinylIconHash(iVar7);
      if ((DAT_00735de4 == 0xf) || (DAT_00735de4 == 0x10)) {
        cVar4 = IsSamanthaUnique(uVar10);
        if (cVar4 == '\0') {
LAB_004e5c3c:
          bVar3 = false;
        }
        else {
          cVar4 = PartStore__HasPart(&DAT_0075f344);
          bVar3 = true;
          if (cVar4 != '\0') goto LAB_004e5c3c;
        }
        uVar9 = *(undefined4 *)(uVar10 + 8);
        cVar4 = FUN_005a3d50();
        if ((cVar4 == '\0') &&
           ((cVar4 = IsSamanthaUnique(local_18), cVar4 == '\0' ||
            (cVar4 = PartStore__HasPart(&DAT_0075f344), cVar4 == '\0')))) {
          local_20 = local_20 & 0xffffff00;
        }
        else {
          local_20 = CONCAT31(local_20._1_3_,1);
        }
        uVar10 = local_18;
        if (bVar3) goto LAB_004e5d19;
        if (DAT_00745e40 != 1) {
          if ((DAT_00745e40 != 2) ||
             (((cVar4 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar9),
               local_2c = local_20, cVar4 == '\0' && (DAT_00735ec1 == '\0')) &&
              (cVar4 = PartStore__HasPart(&DAT_0075f344), local_2c = local_20, uVar10 = local_18,
              cVar4 == '\0')))) goto LAB_004e5d19;
          goto LAB_004e5d03;
        }
        cVar4 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar9);
        if (((cVar4 == '\0') && (DAT_00735ec1 == '\0')) &&
           (cVar4 = PartStore__HasPart(&DAT_0075f344), uVar10 = local_18, cVar4 == '\0'))
        goto LAB_004e5d19;
        local_2c = local_20;
        uVar9 = 0;
      }
      else {
        if (DAT_00735de4 != 0x11) {
          if (DAT_00745e40 == 1) {
            uVar1 = *(undefined1 *)(uVar10 + 0x11);
            local_11 = *(undefined1 *)(uVar10 + 0x12);
            uVar6 = FUN_005a3eb0();
            cVar4 = FUN_004e3d80(local_11,uVar1,0);
            uVar11 = (uint)(byte)(1 - (cVar4 != '\0'));
          }
          else {
            if ((DAT_00745e40 != 2) ||
               (cVar4 = FUN_004e3d80(*(undefined1 *)(uVar10 + 0x12),*(undefined1 *)(uVar10 + 0x11),0
                                    ), cVar4 == '\0')) goto LAB_004e5d19;
            uVar11 = 0;
            uVar6 = FUN_005a3eb0(0);
          }
          FUN_004e2250(0,uVar10,0,uVar6,uVar11);
          goto LAB_004e5d19;
        }
        local_1c = CONCAT31(local_1c._1_3_,1);
        uVar9 = FUN_004e2520(uVar10);
        switch(uVar9) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        default:
          goto switchD_004e5afd_default;
        }
        uVar9 = bStringHash();
        cVar4 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar9);
        local_1c = CONCAT31(local_1c._1_3_,'\x01' - (cVar4 != '\0'));
switchD_004e5afd_default:
        bVar5 = FUN_005a3d50();
        local_2c = (uint)bVar5;
        uVar9 = local_1c;
        if (DAT_00745e40 != 1) {
          uVar10 = local_18;
          if ((DAT_00745e40 != 2) || ((char)local_1c != '\0')) goto LAB_004e5d19;
LAB_004e5d03:
          uVar9 = 0;
        }
      }
      FUN_004e2250(0,local_18,0,local_2c,uVar9);
      uVar10 = local_18;
    }
LAB_004e5d19:
    local_28 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar10,0xffffffff);
    uVar10 = local_28;
  } while( true );
}


// ==== 0x4e5dd0 FUN_004e5dd0

void * __thiscall FUN_004e5dd0(void *param_1,byte param_2)

{
  GarageVinylBrowserScreen___GarageVinylBrowserScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e5df0 GarageVinylBrowserScreen::_GarageVinylBrowserScreen

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageVinylBrowserScreen___GarageVinylBrowserScreen(undefined4 *param_1)

{
  int iVar1;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = _not_a_function__SEH_frame_handler_thunk_;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c3194;
  local_4 = 0;
  if (*(char *)(param_1 + 0x26) == '\0') {
    switch(DAT_006fa1a0) {
    case 0x1f:
      if (param_1[0x22] == 0) goto switchD_004e5e3c_default;
      GarageManager__InstallPart(param_1[0x22],0);
      GarageManager__InstallPart(param_1[0x23],0);
      GarageManager__InstallPart(param_1[0x24],0);
      break;
    case 0x20:
      if (param_1[0x22] == 0) goto switchD_004e5e3c_default;
      GarageManager__InstallPart(param_1[0x22],0);
      GarageManager__InstallPart(param_1[0x23],0);
      GarageManager__InstallPart(param_1[0x24],0);
      break;
    case 0x21:
      if (param_1[0x22] == 0) goto switchD_004e5e3c_default;
      GarageManager__InstallPart(param_1[0x22],0);
      GarageManager__InstallPart(param_1[0x23],0);
      GarageManager__InstallPart(param_1[0x24],0);
      break;
    case 0x22:
      if (param_1[0x22] == 0) goto switchD_004e5e3c_default;
      GarageManager__InstallPart(param_1[0x22],0);
      GarageManager__InstallPart(param_1[0x23],0);
      GarageManager__InstallPart(param_1[0x24],0);
      break;
    default:
      goto switchD_004e5e3c_default;
    }
    GarageManager__InstallPart(param_1[0x25],0);
  }
switchD_004e5e3c_default:
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  local_4 = 0xffffffff;
  FUN_004e2170();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4e6030 GarageVinylBrowserScreen::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __fastcall GarageVinylBrowserScreen__RedrawHeading(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 auStack_20 [8];
  
  iVar4 = *(int *)(param_1 + 0x40);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  puVar6 = auStack_20;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = *(undefined4 **)(iVar4 + 8);
  if ((undefined4 *)(&DAT_00745b6c)[DAT_006fa1a0] == puVar6) {
    FUN_00565da0(" (%s)",iVar1);
    puVar2 = auStack_20;
  }
  else {
    puVar2 = (undefined4 *)&DAT_006b9172;
  }
  FEngPrintf(&DAT_006cc578,*puVar6,puVar2);
  uVar3 = GarageManager__GetMsgForUpgradeLevel(&DAT_00744ff0);
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_004f7c00(uVar3,0,0,*(int *)(iVar1 + 0x18));
  }
  if (*(char *)(iVar4 + 0x14) == '\0') {
    FUN_00414a10();
  }
  else {
    FUN_00414a60();
  }
  if (DAT_00745e40 != 2) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004e618e:
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x7c5a7469);
      }
    }
    else {
      iVar4 = FEngFindPackage();
      if (iVar4 == 0) goto LAB_004e618e;
      iVar4 = FUN_004ffb70();
      if (iVar4 == 0) goto LAB_004e618e;
    }
    FEObject__SetVisible(iVar4);
    uVar3 = GetCarPartCost();
    FEngPrintf(&DAT_006ca778,uVar3);
    goto LAB_004e61cf;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004e613f:
    if (DAT_0073578c != 0) {
      uVar3 = FUN_004ef050(0x7c5a7469);
      FEObject__SetInvisible(uVar3);
      goto LAB_004e61cf;
    }
    iVar4 = 0;
  }
  else {
    iVar4 = FEngFindPackage();
    if (iVar4 == 0) goto LAB_004e613f;
    iVar4 = FUN_004ffb70();
    if (iVar4 == 0) goto LAB_004e613f;
  }
  FEObject__SetInvisible(iVar4);
LAB_004e61cf:
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  return;
}


// ==== 0x4e61f0 GarageVinylBrowserScreen::OptionChosen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall GarageVinylBrowserScreen__OptionChosen(int param_1)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  DAT_00735de8 = *(int *)(*(int *)(param_1 + 0x40) + 8);
  if ((*(char *)(*(int *)(param_1 + 0x40) + 0x14) == '\0') || (DAT_00735ec1 != '\0')) {
    if ((&DAT_00745b6c)[DAT_006fa1a0] != DAT_00735de8) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0x76d94941;
      uStack_1c = 0x5eb8a6c7;
      uStack_20 = 0x639;
      uStack_14 = 0;
      uStack_18 = 0x541389e5;
      uStack_10 = 0;
      uStack_c = 0xb8a7c6cc;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    uStack_30 = 0x639;
    uStack_34 = 0x368294c0;
    uStack_2c = 0;
    FUN_004dcbe0(&uStack_34,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x4e62b0 IsVinylUnlocked

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsVinylUnlocked(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  bVar1 = *(byte *)(unaff_ESI + 0x12);
  if (bVar1 < 0xf) {
LAB_004e635d:
    cVar2 = FUN_004e3d80(bVar1,*(undefined1 *)(unaff_ESI + 0x11),0);
  }
  else {
    if (bVar1 < 0x11) {
      cVar2 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,*(undefined4 *)(unaff_ESI + 8));
      if (((cVar2 == '\0') && (DAT_00735ec1 == '\0')) &&
         (cVar2 = PartStore__HasPart(&DAT_0075f344), cVar2 == '\0')) {
        return 0;
      }
      return 1;
    }
    if (bVar1 != 0x11) goto LAB_004e635d;
    iVar3 = FUN_004e2520();
    if (iVar3 == 0) {
      return 0;
    }
    switch(iVar3 + -1) {
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
      goto switchD_004e62e6_default;
    }
    uVar4 = bStringHash();
    cVar2 = UserProfile__IsStyleRewardUnlocked(&DAT_007588c4,2,uVar4);
  }
  if (cVar2 != '\0') {
    return 1;
  }
switchD_004e62e6_default:
  return 0;
}


// ==== 0x4e6390 GarageVinylBrowserScreen::NotificationMessage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __thiscall
GarageVinylBrowserScreen__NotificationMessage
          (int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_8 = param_1;
  if (param_2 == -0x367ca946) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar1 = DAT_0073578c;
    if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
       ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 &&
        (*(int *)(iVar3 + 0x18) != 0)))) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
    }
    iVar1 = DAT_0073578c;
    DAT_0078eb04 = DAT_0078eb04 + 1;
    if (((DAT_0078eafc != '\0') && (DAT_0078eafc = '\0', DAT_0073578c != 0)) &&
       ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 &&
        (*(int *)(iVar3 + 0x18) != 0)))) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
    }
    (**(code **)(*param_1 + 0x10))();
  }
  else if ((param_2 == 0x5eb8a6c7) || (param_2 == -0x3d132515)) {
    switch(DAT_006fa1a0) {
    case 0x1f:
      break;
    case 0x20:
      break;
    case 0x21:
      break;
    case 0x22:
    }
    GetDefaultVinylColors(&local_10,&local_14,&local_18);
    GarageManager__InstallPart(local_c,1);
    GarageManager__InstallPart(local_10,1);
    GarageManager__InstallPart(local_14,1);
    GarageManager__InstallPart(local_18,1);
    FUN_004e56b0();
    GarageManager__InstallPart(DAT_00735de8,0);
    if ((param_2 == -0x3d132515) && (DAT_00745e40 == 1)) {
      FUN_005a2620();
    }
    DAT_0078eafc = '\x01';
    *(undefined1 *)(local_8 + 0x26) = 1;
    param_1 = local_8;
  }
  iVar1 = *(int *)(param_1[0x10] + 8);
  FUN_004e2430(param_2,param_3,param_4,param_5);
  if (iVar1 == *(int *)(param_1[0x10] + 8)) {
    if ((DAT_0078eb00 != 0) && (0x1e < DAT_0078eb04)) {
      DAT_0078eb00 = 0;
      cVar2 = IsVinylUnlocked();
      if (cVar2 != '\0') {
        GarageManager__PreviewPart();
        return;
      }
      GarageManager__PreviewPart();
    }
    return;
  }
  DAT_0078eb04 = 0;
  DAT_0078eb00 = 1;
  return;
}


// ==== 0x4e6600 CreateGarageVinylBrowser

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageVinylBrowser(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006890b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x9c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageVinylBrowserScreen__GarageVinylBrowserScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e6660 FUN_004e6660

undefined4 FUN_004e6660(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(int *)(DAT_0073578c + 8) != 0) &&
     (iVar1 = *(int *)(*(int *)(DAT_0073578c + 8) + 0xe4), iVar1 != 0)) {
    do {
      if (*(int *)(iVar1 + 0x1c) != 0) {
        iVar2 = iVar1;
      }
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != 0);
    if (iVar2 != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar2 != 0) {
        return *(undefined4 *)(iVar2 + 0x14);
      }
    }
  }
  return 0;
}


// ==== 0x4e66b0 FUN_004e66b0

void __fastcall FUN_004e66b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3124;
  FUN_004f7b50();
  return;
}


// ==== 0x4e66c0 FUN_004e66c0

void * __thiscall FUN_004e66c0(void *param_1,byte param_2)

{
  FUN_004e66b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e66e0 Screen_PC_MenuBar::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_MenuBar__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687003;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x164);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_MenuBar__Screen_PC_MenuBar(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e6740 Screen_PC_MenuBar::Screen_PC_MenuBar

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PC_MenuBar__Screen_PC_MenuBar(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c3124;
  local_4 = 0;
  _DAT_00777cc0 = 4;
  FUN_004e6ac0();
  *(undefined1 *)(param_1 + 0x55) = 0;
  param_1[0x56] = 0;
  *(undefined1 *)(param_1 + 0x57) = 0;
  param_1[0x58] = 0;
  FUN_004e7860(0x9fe0ca88,0x7014dc91,0xad7303c0,0xad7303c0);
  DAT_007363b1 = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e67e0 FUN_004e67e0

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


// ==== 0x4e6ac0 FUN_004e6ac0

void FUN_004e6ac0(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  FUN_004e6cd0(unaff_ESI,1,0x46fce6dd,0x763dfa6,0x548f2015,0x9f23571f);
  FUN_004e6cd0(unaff_ESI,2,0x49885419,0x687acde2,0x571a8d51,0xf31c6bdb);
  FUN_004e6cd0(unaff_ESI,4,0xf17e2c46,0x39b2b1c6,0x55dafa35,0x4848c0fd);
  FUN_004e6cd0(unaff_ESI,8,0xf17e2c46,0x29d3c9aa,0xd2a19b19,0xc50f61e1);
  FUN_004e6cd0(unaff_ESI,0x10,0x1c7fcf8b,0xdc18c4d4,0x2a1208c3,0x2503558d);
  FUN_004e6cd0(unaff_ESI,0x100,0xf17e2c46,0x558adf75,0xc8754fa4,0xbae3166c);
  FUN_004e6cd0(unaff_ESI,0x40,0xf17e2c46,0x9a51a74,0xec0a4663,0xde780d2b);
  FUN_004e6cd0(unaff_ESI,0x200,0xf17e2c46,0xe252e7ee,0xa7615a5d,0x99cf2125);
  FUN_004e6cd0(unaff_ESI,0x400,0xf17e2c46,0x186f46db,0xd611288a,0xc87eef52);
  FUN_004e6cd0(unaff_ESI,0x800,0xf17e2c46,0x976bd787,0x6749436,0xf8e25afe);
  FUN_004e6cd0(unaff_ESI,0x1000,0xf17e2c46,0xfd6189db,0xbdd6aeea,0xb04475b2);
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    iVar1 = FUN_004ffb70();
    if (iVar1 != 0) goto LAB_004e6c47;
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0xfd6189dc);
  }
LAB_004e6c47:
  FEObject__SetInvisible(iVar1);
  FUN_004e6cd0(unaff_ESI,0x80,0x93d7df3f,0xf7015788,0xa16a1877,0x875d5bc1);
  FUN_004e6cd0(unaff_ESI,0x2000,0xf17e2c46,0x7014dc91,0xad7303c0,0x9fe0ca88);
  FUN_004e6cd0(unaff_ESI,0x4000,0xf17e2c46,0xc68d44c7,0x83a65176,0x7614183e);
  FUN_004e6cd0(unaff_ESI,0x8000,0xf17e2c46,0x68bc64c8,0x6e1d75b7,0x608b3c7f);
  return;
}


// ==== 0x4e6cd0 FUN_004e6cd0

void FUN_004e6cd0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  int iVar1;
  int iVar2;
  int local_8;
  int local_4;
  
  iVar1 = param_1;
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (param_1 = FUN_004ffb70(), param_1 == 0)) {
    if (DAT_0073578c == 0) {
      param_1 = 0;
    }
    else {
      param_1 = FUN_004ef050(param_3);
    }
  }
  if (((*(int *)(iVar1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (local_8 = FUN_004ffb70(), local_8 == 0)) {
    if (DAT_0073578c == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_004ef050(param_4);
    }
  }
  if (((*(int *)(iVar1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (local_4 = FUN_004ffb70(), local_4 == 0)) {
    if (DAT_0073578c == 0) {
      local_4 = 0;
    }
    else {
      local_4 = FUN_004ef050(param_5);
    }
  }
  if (((*(int *)(iVar1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(param_6);
    }
  }
  if (param_1 != 0) {
    if ((DAT_00735780 & param_2) != 0) {
      FUN_00495fc0();
      FUN_00495fc0();
      FUN_00495fc0();
      if (param_6 != 0) {
        FUN_00495fc0();
      }
      *(int *)(iVar1 + 0x44 + *(int *)(iVar1 + 0x40) * 4) = param_1;
      *(int *)(iVar1 + 0x84 + *(int *)(iVar1 + 0x40) * 4) = local_8;
      *(int *)(iVar1 + 0xc4 + *(int *)(iVar1 + 0x40) * 4) = local_4;
      *(int *)(iVar1 + 0x104 + *(int *)(iVar1 + 0x40) * 4) = iVar2;
      *(undefined1 *)(iVar1 + 0x144 + *(int *)(iVar1 + 0x40)) = 1;
      *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + 1;
      return;
    }
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    if (param_6 != 0) {
      FUN_00495f70();
    }
  }
  return;
}


// ==== 0x4e6ed0 FUN_004e6ed0

undefined4 FUN_004e6ed0(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)*(int *)(iVar1 + 0x18) >> 8),*(int *)(iVar1 + 0x18) != 0);
  }
  return 0;
}


// ==== 0x4e6f00 FUN_004e6f00

void FUN_004e6f00(int param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  undefined4 uVar9;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  cVar1 = DAT_007363b1;
  bVar8 = DAT_007363b1 == 't';
  DAT_007363b1 = 0;
  if ((((bVar8) || (cVar1 == 'T')) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)
      ) && ((*(int *)(iVar4 + 0x18) != 0 && (*(int **)(iVar4 + 0x14) != (int *)0x0)))) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0xc519bfc8,0,0,*(int *)(iVar4 + 0x18));
  }
  if (cVar1 == '\t') {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x14de0507,0,0,*(int *)(iVar4 + 0x18));
    }
  }
  else if (cVar1 == '\0') goto LAB_004e6f9f;
  FUN_0059e3b0(cVar1);
LAB_004e6f9f:
  piVar6 = (int *)(param_1 + 0x40);
  param_1 = 0;
  if (0 < *piVar6) {
    piVar6 = (int *)(iVar2 + 0x44);
    do {
      if ((*piVar6 != 0) && (*(char *)(param_1 + 0x144 + iVar2) == '\x01')) {
        uVar5 = *(uint *)(*piVar6 + 0x10);
        if (uVar5 == 0xf17e2c46) {
          uVar5 = *(uint *)(piVar6[0x30] + 0x10);
        }
        if (uVar5 < 0xb04475b3) {
          if (uVar5 == 0xb04475b2) {
            if ((((cVar1 == 'z') || (cVar1 == 'Z')) &&
                (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
               ((*(int *)(iVar4 + 0x18) != 0 && (*(int **)(iVar4 + 0x14) != (int *)0x0)))) {
              (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0xc519bfc0,0,0,*(int *)(iVar4 + 0x18));
            }
          }
          else if (uVar5 < 0x7614183f) {
            if (uVar5 == 0x7614183e) {
              if (((cVar1 == 'z') || (cVar1 == 'Z')) && (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0')
                 ) {
                uVar9 = 0xc519bfc0;
                goto LAB_004e71ae;
              }
            }
            else if (uVar5 == 0x46fce6dd) {
              if ((cVar1 == 'q') || (cVar1 == 'Q')) {
                uStack_8 = 0;
                uStack_4 = 0;
                uStack_24 = 0xfd61c7e0;
                uStack_1c = 0x3b4ff2d;
                uStack_20 = 0x639;
                uStack_14 = 0xcfadb8b4;
                uStack_18 = 0x541389e5;
                uStack_10 = 0xcfadb8b4;
                uStack_c = 0xb8a7c6cd;
                iVar7 = 0;
                iVar4 = FEngGetFirstPackage();
                if (iVar4 != 0) {
                  do {
                    if (*(int *)(iVar4 + 0x1c) != 0) {
                      iVar7 = iVar4;
                    }
                    iVar4 = *(int *)(iVar4 + 4);
                  } while (iVar4 != 0);
                  if (iVar7 != 0) {
                    cVar3 = FEngIsPackagePushed();
                    iVar4 = DAT_00735e0c;
                    if (cVar3 == '\0') {
                      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(iVar7 + 0xc));
                      *(undefined1 *)(iVar2 + 0x154) = 0;
                    }
                    else if ((DAT_00735e0c != 0) && (iVar7 = FUN_004f4070(), iVar7 != 0)) {
                      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(iVar4 + 0xc));
                      *(int *)(iVar2 + 0x158) = iVar4;
                      *(undefined1 *)(iVar2 + 0x154) = 1;
                    }
                  }
                }
              }
            }
            else if (uVar5 == 0x4848c0fd) {
              if (((cVar1 == 'c') || (cVar1 == 'C')) && (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0')
                 ) {
                uVar9 = 0xc519bfc0;
                goto LAB_004e71ae;
              }
            }
            else if ((uVar5 == 0x608b3c7f) && ((cVar1 == 'z' || (cVar1 == 'Z')))) {
              cVar3 = FUN_004e6ed0(iVar2);
              bVar8 = cVar3 == '\0';
              goto LAB_004e71a7;
            }
          }
          else if (uVar5 == 0x99cf2125) {
            if (((cVar1 == 'd') || (cVar1 == 'D')) && (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0'))
            {
              FUN_004e7720(iVar2,0xc519bfc0,param_1);
            }
          }
          else if (uVar5 == 0x9fe0ca88) goto LAB_004e7185;
        }
        else if (uVar5 < 0xc87eef53) {
          if (uVar5 == 0xc87eef52) {
            if (((cVar1 == 'a') || (cVar1 == 'A')) && (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0'))
            {
              FUN_004c96c0(0xc519bfc0);
              FUN_004c96c0(0xc519bfbf);
            }
          }
          else if (uVar5 == 0xbae3166c) {
            if (((cVar1 == 'p') || (cVar1 == 'P')) && (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0'))
            {
              uVar9 = 0xc519bfc0;
              goto LAB_004e71ae;
            }
          }
          else if (((uVar5 == 0xc50f61e1) && ((cVar1 == 'r' || (cVar1 == 'R')))) &&
                  (cVar3 = FUN_004e6ed0(iVar2), cVar3 == '\0')) {
            uVar9 = 0xc519bfc0;
LAB_004e71ae:
            FUN_004c96c0(uVar9);
          }
        }
        else if (uVar5 == 0xde780d2b) {
LAB_004e7185:
          if ((cVar1 == 'z') || (cVar1 == 'Z')) {
            iVar4 = FEPackageList__FindByName(&DAT_00746104);
            if (iVar4 != 0) {
              bVar8 = *(int *)(iVar4 + 0x18) == 0;
LAB_004e71a7:
              if (!bVar8) goto LAB_004e71bb;
            }
            uVar9 = 0xc519bfbf;
            goto LAB_004e71ae;
          }
        }
        else if ((uVar5 == 0xf8e25afe) && ((cVar1 == 'd' || (cVar1 == 'D')))) {
          uVar9 = 0x1234ddd0;
          goto LAB_004e71ae;
        }
      }
LAB_004e71bb:
      param_1 = param_1 + 1;
      piVar6 = piVar6 + 1;
    } while (param_1 < *(int *)(iVar2 + 0x40));
  }
  return;
}


// ==== 0x4e7320 FUN_004e7320

void FUN_004e7320(void)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int unaff_ESI;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = 0;
  if (*(int *)(unaff_ESI + 0x40) < 1) {
    return;
  }
  piVar3 = (int *)(unaff_ESI + 0x44);
  while (((*piVar3 == 0 || (*(char *)(iVar4 + 0x144 + unaff_ESI) != '\x01')) ||
         (cVar2 = FUN_004f7eb0(unaff_ESI), cVar2 == '\0'))) {
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
    if (*(int *)(unaff_ESI + 0x40) <= iVar4) {
      return;
    }
  }
  uVar1 = *(uint *)(*(int *)(unaff_ESI + 0x44 + iVar4 * 4) + 0x10);
  if (uVar1 < 0x4988541a) {
    if (uVar1 != 0x49885419) {
      if (uVar1 == 0x1c7fcf8b) {
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) &&
           (cVar2 = FEngIsPackagePushed(), cVar2 == '\0')) {
          FUN_004e77c0(unaff_ESI,0xf2d0d887);
          return;
        }
        FUN_004e77c0(unaff_ESI,0x911ab364);
        return;
      }
      if (uVar1 != 0x46fce6dd) {
        return;
      }
      local_8 = 0;
      local_4 = 0;
      local_24 = 0xfd61c7e0;
      local_1c = 0x3b4ff2d;
      local_20 = 0x639;
      local_14 = 0xcfadb8b4;
      local_18 = 0x541389e5;
      local_10 = 0xcfadb8b4;
      local_c = 0xb8a7c6cd;
      iVar5 = 0;
      iVar4 = FEngGetFirstPackage();
      if (iVar4 == 0) {
        return;
      }
      do {
        if (*(int *)(iVar4 + 0x1c) != 0) {
          iVar5 = iVar4;
        }
        iVar4 = *(int *)(iVar4 + 4);
      } while (iVar4 != 0);
      if (iVar5 == 0) {
        return;
      }
      cVar2 = FEngIsPackagePushed();
      iVar4 = DAT_00735e0c;
      if (cVar2 != '\0') {
        FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(DAT_00735e0c + 0xc));
        *(int *)(unaff_ESI + 0x158) = iVar4;
        *(undefined1 *)(unaff_ESI + 0x154) = 1;
        return;
      }
      FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(iVar5 + 0xc));
      *(undefined1 *)(unaff_ESI + 0x154) = 0;
      return;
    }
LAB_004e75d8:
    FUN_004e7720(unaff_ESI,0xc407210,iVar4);
    FUN_004e7720(unaff_ESI,0xc519bfc5,iVar4);
    return;
  }
  if (uVar1 == 0x93d7df3f) goto LAB_004e75d8;
  if (uVar1 != 0xf17e2c46) {
    return;
  }
  uVar1 = *(uint *)(*(int *)(unaff_ESI + 0x104 + iVar4 * 4) + 0x10);
  if (uVar1 < 0xb04475b3) {
    if (uVar1 != 0xb04475b2) {
      if (uVar1 < 0x7614183f) {
        if (uVar1 == 0x7614183e) {
LAB_004e7525:
          FUN_004c96c0(0xc519bfc0);
          return;
        }
        if (uVar1 == 0x4848c0fd) {
          cVar2 = FUN_004e6ed0(unaff_ESI);
          if (cVar2 != '\0') {
            return;
          }
          goto LAB_004e7525;
        }
        if (uVar1 != 0x608b3c7f) {
          return;
        }
        cVar2 = FUN_004e6ed0(unaff_ESI);
        bVar6 = cVar2 == '\0';
      }
      else {
        if (uVar1 == 0x99cf2125) {
          FUN_004e7720(unaff_ESI,0xc519bfc0,iVar4);
          return;
        }
        bVar6 = uVar1 == 0x9fe0ca88;
      }
      if (!bVar6) {
        return;
      }
LAB_004e74ff:
      FUN_004c96c0(0xc519bfbf);
      return;
    }
  }
  else {
    if (0xc87eef52 < uVar1) {
      if (uVar1 != 0xde780d2b) {
        if (uVar1 != 0xf8e25afe) {
          return;
        }
        FUN_004c96c0(0x1234ddd0);
        return;
      }
      goto LAB_004e74ff;
    }
    if (uVar1 == 0xc87eef52) goto LAB_004e7596;
    if (uVar1 != 0xbae3166c) {
      if (uVar1 != 0xc50f61e1) {
        return;
      }
      FUN_004c96c0(0xc519bfc0);
      return;
    }
  }
  cVar2 = FUN_004e6ed0(unaff_ESI);
  if (cVar2 != '\0') {
    return;
  }
LAB_004e7596:
  FUN_004c96c0(0xc519bfc0);
  return;
}


// ==== 0x4e7600 FUN_004e7600

void FUN_004e7600(void)

{
  int iVar1;
  bool bVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if ((((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) &&
      ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0 ||
       (*(int *)(iVar3 + 0x18) == 0)))) &&
     (((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0 ||
       (*(int *)(iVar3 + 0x18) == 0)) &&
      ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0 ||
       (*(int *)(iVar3 + 0x18) == 0)))))) {
    if (DAT_0078eaf8 != 0) {
      iVar3 = FUN_004e6660();
      if (iVar3 != 0) {
        FUN_004f8000(iVar3);
        FUN_004e6ac0();
      }
      DAT_0078eaf8 = 0;
    }
    bVar2 = true;
  }
  else {
    DAT_0078eaf8 = 1;
    bVar2 = false;
  }
  iVar3 = 0;
  if (0 < *(int *)(in_EAX + 0x40)) {
    piVar4 = (int *)(in_EAX + 0x44);
    do {
      if ((((*piVar4 != 0) && (iVar1 = *(int *)(*piVar4 + 0x10), iVar1 != 0x49885419)) &&
          (iVar1 != 0x1c7fcf8b)) && (iVar1 != 0x46fce6dd)) {
        if ((*(char *)(iVar3 + 0x144 + in_EAX) == '\0') || (!bVar2)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        FUN_004e7860(iVar1,iVar1,iVar1,iVar1);
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(in_EAX + 0x40));
  }
  return;
}


// ==== 0x4e7720 FUN_004e7720

int FUN_004e7720(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  if ((*(int *)(DAT_0073578c + 8) != 0) &&
     (iVar5 = *(int *)(*(int *)(DAT_0073578c + 8) + 0xe4), iVar2 = DAT_0073578c, iVar5 != 0)) {
    do {
      if (*(int *)(iVar5 + 0x1c) != 0) {
        iVar3 = iVar5;
        if (iVar2 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          if (iVar4 == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = *(int *)(iVar4 + 0x18);
          }
          iVar4 = 0;
          iVar2 = DAT_0073578c;
          if (iVar1 != 0) {
            iVar4 = *(int *)(iVar1 + 0x80);
          }
        }
      }
      iVar5 = *(int *)(iVar5 + 4);
    } while (iVar5 != 0);
    if ((((iVar4 != 0) && (iVar3 != 0)) && (iVar2 != 0)) && (*(int *)(iVar2 + 8) != 0)) {
      FUN_004f0700(param_2,*(undefined4 *)(param_1 + 0x44 + param_3 * 4),iVar3,iVar4,0);
    }
  }
  return iVar4;
}


// ==== 0x4e77c0 FUN_004e77c0

void FUN_004e77c0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(int *)(DAT_0073578c + 8) != 0) &&
     (iVar1 = *(int *)(*(int *)(DAT_0073578c + 8) + 0xe4), iVar1 != 0)) {
    do {
      if (*(int *)(iVar1 + 0x1c) != 0) {
        iVar2 = iVar1;
      }
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != 0);
    if (iVar2 != 0) {
      if (param_2 == -0xd2f2779) {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) &&
           (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
          (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0xf2d0d887,0,0,*(int *)(iVar2 + 0x18));
          return;
        }
      }
      else {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) &&
           (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
          (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x911ab364,0,0,*(int *)(iVar2 + 0x18));
        }
      }
    }
  }
  return;
}


// ==== 0x4e7860 FUN_004e7860

void FUN_004e7860(int param_1)

{
  int iVar1;
  int *piVar2;
  char unaff_BL;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = 0;
  if (*(int *)(unaff_EDI + 0x40) < 1) {
    return;
  }
  piVar2 = (int *)(unaff_EDI + 0x44);
  do {
    if (*piVar2 != 0) {
      iVar1 = *(int *)(*piVar2 + 0x10);
      if (iVar1 == -0xe81d3ba) {
        iVar1 = *(int *)(piVar2[0x30] + 0x10);
      }
      if (iVar1 == param_1) {
        *(char *)(iVar3 + 0x144 + unaff_EDI) = unaff_BL;
        if (unaff_BL == '\0') {
          FEObject__SetInvisible(*(undefined4 *)(unaff_EDI + 0x44 + iVar3 * 4));
        }
        else {
          FEObject__SetVisible();
        }
        iVar1 = *(int *)(unaff_EDI + 0x84 + iVar3 * 4);
        if (iVar1 != 0) {
          if (unaff_BL == '\0') {
            FEObject__SetInvisible(iVar1);
          }
          else {
            FEObject__SetVisible();
          }
        }
        iVar1 = *(int *)(unaff_EDI + 0xc4 + iVar3 * 4);
        if (iVar1 != 0) {
          if (unaff_BL == '\0') {
            FEObject__SetInvisible(iVar1);
          }
          else {
            FEObject__SetVisible();
          }
        }
        iVar3 = *(int *)(unaff_EDI + 0x104 + iVar3 * 4);
        if (iVar3 == 0) {
          return;
        }
        if (unaff_BL == '\0') {
          FEObject__SetInvisible(iVar3);
          return;
        }
        FEObject__SetVisible();
        return;
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
    if (*(int *)(unaff_EDI + 0x40) <= iVar3) {
      return;
    }
  } while( true );
}


// ==== 0x4e7930 FUN_004e7930

void __fastcall FUN_004e7930(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3108;
  FUN_004f7b50();
  return;
}


// ==== 0x4e7940 FUN_004e7940

int FUN_004e7940(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 == 3) || (in_stack_00000014 == 4)) {
    in_stack_00000014 = 0;
  }
  return in_stack_00000014;
}


// ==== 0x4e7960 FUN_004e7960

void * __thiscall FUN_004e7960(void *param_1,byte param_2)

{
  FUN_004e7930();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e7980 FUN_004e7980

undefined4 * FUN_004e7980(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c3108;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x4e79e0 GaragePresetsScreen::_GaragePresetsScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GaragePresetsScreen___GaragePresetsScreen(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 0x1f;
  *param_1 = &PTR_FUN_006c30d4;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  FUN_004f84d0();
  FUN_004f7b50();
  return;
}


// ==== 0x4e7a20 FUN_004e7a20

void * __thiscall FUN_004e7a20(void *param_1,byte param_2)

{
  GaragePresetsScreen___GaragePresetsScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e7a40 GaragePresetsScreen::GaragePresetsScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GaragePresetsScreen__GaragePresetsScreen(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688876;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar6 = 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c30d4;
  FUN_004f8370(param_1 + 0x10,"master_thumb","car_thumb");
  puVar1 = param_1 + 0x1f;
  *puVar1 = puVar1;
  param_1[0x20] = puVar1;
  local_4 = CONCAT31(local_4._1_3_,2);
  if (DAT_00735dd4 == 0) {
    param_1[0xf] = 0xd2236188;
  }
  do {
    pcVar5 = "GENERIC_STOCK";
    do {
      pcVar2 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar2 != '\0');
    FUN_004e7be0();
    iVar6 = iVar6 + 1;
  } while (iVar6 < 10);
  param_1[0x21] = *puVar1;
  FUN_004f8960();
  GaragePresetsScreen__Redraw();
  FUN_004e7cf0();
  *(undefined1 *)(param_1 + 8) = 1;
  if (param_1[3] == 0) {
LAB_004e7b9e:
    if (DAT_0073578c != 0) {
      uVar4 = FUN_004ef050(0xa8a3681a);
      goto LAB_004e7bba;
    }
  }
  else {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004e7b62:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar6);
      local_4 = CONCAT31(local_4._1_3_,2);
      goto LAB_004e7b9e;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar6 = FUN_004fd1e0(iVar3 + 0xdc), iVar6 == 0 &&
          (iVar6 = FUN_004fd1e0(iVar3 + 0xec), iVar6 == 0)))) goto LAB_004e7b9e;
      goto LAB_004e7b62;
    }
  }
  uVar4 = 0;
LAB_004e7bba:
  FEObject__SetInvisible(uVar4);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e7be0 FUN_004e7be0

void FUN_004e7be0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EBX + 0x40,unaff_EDI,0,1);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != in_EAX)) {
    *(int *)(iVar2 + 0x24) = in_EAX;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x740);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    RideInfo__Init();
  }
  piVar3[2] = unaff_EDI;
  puVar1 = *(undefined4 **)(unaff_EBX + 0x80);
  *puVar1 = piVar3;
  *(int **)(unaff_EBX + 0x80) = piVar3;
  *piVar3 = unaff_EBX + 0x7c;
  iVar2 = piVar3[2];
  piVar3[1] = (int)puVar1;
  if ((iVar2 < 0) || (9 < iVar2)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(&DAT_00758c30 + iVar2 * 0x338);
  }
  if (*piVar4 != 0) {
    FECarConfig__BuildRide(piVar4,0,piVar3 + 4);
    piVar3[0x1cc] = 1;
    return;
  }
  piVar3[0x1cc] = 0;
  return;
}


// ==== 0x4e7c80 GaragePresetsScreen::Redraw

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GaragePresetsScreen__Redraw(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (DAT_00735dd4 == 0) {
    uVar1 = 0xac20c713;
  }
  else {
    uVar1 = 0xd730ca44;
  }
  FUN_00495f00(uVar1);
  if (*(int *)(*(int *)(in_EAX + 0x84) + 0x730) == 0) {
    FUN_00495f00(0x2b70ace);
    return;
  }
  uVar1 = GetCarModelNameHash();
  FUN_00495f00(uVar1);
  return;
}


// ==== 0x4e7cf0 FUN_004e7cf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7cf0(void)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(*(int *)(in_EAX + 0x84) + 0x730) == 0) {
    iVar1 = FUN_004b2330();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x9c) = 1;
    }
  }
  else {
    RideInfo__operator_(&DAT_00745000,*(int *)(in_EAX + 0x84) + 0x10);
    iVar1 = FUN_004b2330();
    RideInfo__operator_(&DAT_00748850,&DAT_00745000);
    _DAT_0072cc80 = 2;
    if (iVar1 != 0) {
      GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
    }
    iVar1 = FUN_004b2330();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x9c) = 0;
      return;
    }
  }
  return;
}


// ==== 0x4e7d70 FUN_004e7d70

void __fastcall FUN_004e7d70(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x84);
  if (param_1 == -0x6edfbf62) {
    if (puVar1 == *(undefined4 **)(unaff_EDI + 0x7c)) goto LAB_004e7da0;
    uVar2 = puVar1[1];
  }
  else {
    if ((param_1 != -0x4a68e40f) || (puVar1 == *(undefined4 **)(unaff_EDI + 0x80)))
    goto LAB_004e7da0;
    uVar2 = *puVar1;
  }
  *(undefined4 *)(unaff_EDI + 0x84) = uVar2;
LAB_004e7da0:
  if (puVar1 != *(undefined4 **)(unaff_EDI + 0x84)) {
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
    FUN_004f8910();
    FUN_004e7cf0();
    GaragePresetsScreen__Redraw();
    return;
  }
  return;
}


// ==== 0x4e7e00 FUN_004e7e00

void FUN_004e7e00(void)

{
  int in_EAX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00735dd4 == 1) {
    if (*(int *)(*(int *)(in_EAX + 0x84) + 0x730) != 0) {
      local_24 = 0x86d59539;
      local_1c = 0x12346666;
LAB_004e7e31:
      local_8 = 0;
      local_4 = 0;
      local_14 = 0;
      local_10 = 0;
      local_20 = 0x639;
      local_18 = 0x541389e5;
      local_c = 0xb8a7c6cd;
      FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(in_EAX + 0xc));
      return;
    }
  }
  else if (DAT_00735dd4 == 0) {
    if (*(int *)(*(int *)(in_EAX + 0x84) + 0x730) != 0) {
      local_24 = 0x56f12f8f;
      local_1c = 0x12345555;
      goto LAB_004e7e31;
    }
    FUN_004e7eb0();
  }
  return;
}


// ==== 0x4e7eb0 FUN_004e7eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7eb0(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = *(int *)(unaff_EDI + 0x84);
  iVar1 = *(int *)(iVar3 + 8);
  if ((iVar1 < 0) || (9 < iVar1)) {
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = &DAT_00758c30 + iVar1 * 0x338;
  }
  FECarConfig__FillFromRide(puVar2,&DAT_00745720);
  RideInfo__operator_(iVar3 + 0x10,&DAT_00745720);
  *(undefined4 *)(iVar3 + 0x730) = 1;
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar3 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar3 != 0) {
    GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,2);
  }
  GaragePresetsScreen__Redraw();
  iVar3 = FUN_004b2330();
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x9c) = 0;
  }
  return;
}


// ==== 0x4e7f60 GaragePresetsScreen::LoadPreset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GaragePresetsScreen__LoadPreset(void)

{
  int iVar1;
  int unaff_EBX;
  
  cFrontendDatabase__SetCurrentCarFromRide();
  DAT_00744ff8 = FUN_004ac060();
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745000);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  FECarConfig__FillFromRide(DAT_00744ff8,*(int *)(unaff_EBX + 0x84) + 0x10);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar1 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,&DAT_00748850,2);
  }
  GaragePresetsScreen__Redraw();
  return;
}


// ==== 0x4e8020 FUN_004e8020

void FUN_004e8020(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x911ab365) {
    if (param_1 == 0x911ab364) {
      iVar1 = FUN_004b2330();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x9c) = 0;
      }
      GarageManager__SyncActualToEditing(0);
      GarageManager__PopScreen();
      iVar1 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
          FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
          return;
        }
      }
    }
    else {
      if (param_1 == 0xc407210) {
        FUN_004e7e00();
        return;
      }
      if (param_1 == 0x12345555) {
        FUN_004e7eb0();
        return;
      }
      if (param_1 == 0x12346666) {
        GaragePresetsScreen__LoadPreset();
        return;
      }
    }
  }
  else if ((param_1 == 0x9120409e) || (param_1 == 0xb5971bf1)) {
    FUN_004e7d70();
  }
  else if (param_1 == 0xc98356ba) {
    FUN_004f89d0();
    FUN_004f7d30();
    return;
  }
  return;
}


// ==== 0x4e8120 CreateGaragePresetsScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGaragePresetsScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688b83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GaragePresetsScreen__GaragePresetsScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e8180 Screen_MU_UG_NewCareerFMV::Screen_MU_UG_NewCareerFMV

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_NewCareerFMV__Screen_MU_UG_NewCareerFMV(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2d84;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0 && (*(int *)(iVar1 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0 &&
       (*(int *)(iVar1 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0 && (*(int *)(iVar1 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
  }
  iVar2 = FEngFindPackage();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0xff;
  }
  if (DAT_00735dc4 == '\0') {
    if (DAT_00735dc8 == 0) {
      pcVar3 = (char *)(DAT_007677a8 + 0x594c);
    }
    else {
      if (DAT_00735dc8 < 0x100) {
        iVar2 = (&DAT_00733ff8)[DAT_00735dc8];
      }
      else {
        iVar2 = 0;
      }
      pcVar3 = (char *)(iVar2 + 0xac);
      if (*(char *)(iVar2 + 0xac) == '\0') goto LAB_004e82f1;
    }
  }
  else {
    pcVar3 = "04_GUM_s";
  }
  FUN_004e8420(pcVar3);
LAB_004e82f1:
  *(undefined1 *)(param_1 + 0x10) = 0;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
    if ((DAT_0073578c != 0) &&
       ((iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0 &&
        (*(int *)(iVar1 + 0x18) != 0)))) {
      cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
    }
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e8360 FUN_004e8360

void * __thiscall FUN_004e8360(void *param_1,byte param_2)

{
  FUN_004e8380();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e8380 FUN_004e8380

void __fastcall FUN_004e8380(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c2d84;
  local_4 = 0;
  if ((*(char *)(param_1 + 0x10) != '\0') && (DAT_0073578c != 0)) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar1,"PC_MenuBar.fng",0x42,0);
    }
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4e8420 FUN_004e8420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e8420(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  if (((((*(int *)(unaff_EDI + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
       (iVar1 = FUN_004ffb70(), iVar1 == 0)) &&
      ((DAT_0073578c == 0 || (iVar1 = FUN_004ef050(0x58d36da2), iVar1 == 0)))) ||
     (*(int *)(iVar1 + 0x18) != 2)) {
    iVar1 = 0;
  }
  uVar2 = GetLocalizedLogoMovie(param_1);
  FUN_004c39d0(uVar2);
  if ((4 < DAT_006ee6f0) && (DAT_006ee6f0 < 9)) {
    if (((*(int *)(unaff_EDI + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x58d36da2);
      }
    }
    FEObject__SetVisible(iVar3);
    DAT_00733f2c = iVar1;
    DAT_00733f30 = MovieSubtitles__FindByName(param_1);
    DAT_00733f28 = 0xffffffff;
    _DAT_00733f40 = timeGetTime();
    FEObject__SetFormattedText(&DAT_006b9172);
    return;
  }
  if ((*(int *)(unaff_EDI + 0xc) == 0) ||
     ((iVar1 = FEngFindPackage(), iVar1 == 0 || (iVar1 = FUN_004ffb70(), iVar1 == 0)))) {
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0x58d36da2);
      FEObject__SetInvisible(uVar2);
      return;
    }
    iVar1 = 0;
  }
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4e8580 FUN_004e8580

void __thiscall FUN_004e8580(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0x406415e3) {
    if (DAT_00735dc4 != '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      goto LAB_004e85f2;
    }
  }
  else {
    if (param_2 != -0x3c69f147) {
      if (param_2 != -0x367ca946) {
        return;
      }
      if (DAT_006ee6f0 < 5) {
        return;
      }
      if (8 < DAT_006ee6f0) {
        return;
      }
      MovieSubtitles__Update();
      return;
    }
    if (DAT_00735dc4 != '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
LAB_004e85f2:
      LaunchPartsBrowserNoShowFlag(1,uVar1,"MU_Garage.fng","MU_UG_UndergroundMenu.fng");
      DAT_00735dc4 = 0;
      return;
    }
  }
  if (DAT_00735dc8 == 0) {
    Career__StartRaceFromEvent();
    return;
  }
  FUN_004c96c0(0xaabbddcc);
  DAT_00735dc8 = 0;
  return;
}


// ==== 0x4e8640 Screen_MU_UG_NewCareerFMV::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_NewCareerFMV__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687a43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_NewCareerFMV__Screen_MU_UG_NewCareerFMV(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e86a0 FUN_004e86a0

void __fastcall FUN_004e86a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2d64;
  FUN_004f7b50();
  return;
}


// ==== 0x4e86b0 FUN_004e86b0

void * __thiscall FUN_004e86b0(void *param_1,byte param_2)

{
  FUN_004e86a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e86d0 Screen_MU_UG_NewCareerExtroFMV::Screen_MU_UG_NewCareerExtroFMV

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_NewCareerExtroFMV__Screen_MU_UG_NewCareerExtroFMV
          (undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 local_4c [64];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2d64;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 &&
       (*(int *)(iVar2 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar4 = DAT_00777ccc;
  cVar1 = Race__DidPlayerWin(DAT_00777ccc,1);
  if (cVar1 == '\0') {
    cVar1 = Race__DidPlayerWin(iVar4,1);
    if (cVar1 != '\0') goto LAB_004e8848;
    iVar2 = iVar4 + 0x5958;
LAB_004e8839:
    puVar5 = &DAT_006cc568;
  }
  else {
    iVar2 = iVar4 + 0x5964;
    if (*(int *)(iVar4 + 0x58a0) != 0) goto LAB_004e8839;
    if (DAT_0076027c == 0) {
      puVar5 = &DAT_006c30b4;
    }
    else {
      puVar5 = &DAT_006c30ac;
    }
  }
  bSPrintf_regdst(0x40,puVar5,iVar2);
LAB_004e8848:
  uVar3 = GetLocalizedLogoMovie(local_4c);
  FUN_004c39d0(uVar3);
  if (((((param_1[3] == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(0x58d36da2), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 2)) {
    iVar4 = 0;
  }
  if ((DAT_006ee6f0 < 5) || (8 < DAT_006ee6f0)) {
    if ((param_1[3] == 0) ||
       ((iVar4 = FEngFindPackage(), iVar4 == 0 || (iVar4 = FUN_004ffb70(), iVar4 == 0)))) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x58d36da2);
      }
    }
    FEObject__SetInvisible(iVar4);
  }
  else {
    if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x58d36da2);
      }
    }
    FEObject__SetVisible(iVar2);
    DAT_00733f2c = iVar4;
    DAT_00733f30 = MovieSubtitles__FindByName(local_4c);
    DAT_00733f28 = 0xffffffff;
    _DAT_00733f40 = timeGetTime();
    FEObject__SetFormattedText(&DAT_006b9172);
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e89b0 FUN_004e89b0

int __thiscall FUN_004e89b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((param_2 == 0x406415e3) || (param_2 == -0x3c69f147)) {
    param_2 = *(int *)(param_1 + 0xc);
    if (*(int *)(DAT_00777ccc + 0x58a0) == 0) {
      if (DAT_0076027c == 0) {
        if (DAT_0073578c != 0) {
          iVar2 = FEPackageList__FindByName(&DAT_00746104);
          param_2 = 0;
          if (iVar2 != 0) {
            param_2 = 0;
            if (*(int *)(iVar2 + 0x18) != 0) {
              iVar1 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
              return iVar1;
            }
          }
        }
      }
      else if (DAT_0073578c != 0) {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        param_2 = 0;
        if (iVar2 != 0) {
          param_2 = 0;
          if (*(int *)(iVar2 + 0x18) != 0) {
            iVar1 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
            return iVar1;
          }
        }
      }
    }
    else if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      param_2 = 0;
      if (iVar2 != 0) {
        param_2 = 0;
        if (*(int *)(iVar2 + 0x18) != 0) {
          param_2 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
        }
      }
    }
  }
  else if (((param_2 == -0x367ca946) && (param_2 = DAT_006ee6f0, 4 < DAT_006ee6f0)) &&
          (DAT_006ee6f0 < 9)) {
    iVar1 = MovieSubtitles__Update();
    return iVar1;
  }
  return param_2;
}


// ==== 0x4e8ab0 Screen_MU_UG_NewCareerExtroFMV::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_NewCareerExtroFMV__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687a23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_NewCareerExtroFMV__Screen_MU_UG_NewCareerExtroFMV(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e8b10 FUN_004e8b10

void FUN_004e8b10(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI == 0) {
LAB_004e8b2f:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c7e);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8b2f;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8b2f;
  }
  if (unaff_EDI == 0) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8b7e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c7f);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8b7e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8b7e;
  }
  if (unaff_EDI == 1) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8bce:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c80);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8bce;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8bce;
  }
  if (unaff_EDI == 2) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8c1e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c81);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8c1e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8c1e;
  }
  if (unaff_EDI == 3) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8c6e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c82);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8c6e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8c6e;
  }
  if (unaff_EDI == 4) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8cbe:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c83);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8cbe;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8cbe;
  }
  if (unaff_EDI == 5) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI == 0) {
LAB_004e8d0e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5261c84);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e8d0e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e8d0e;
  }
  if (unaff_EDI == 6) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar1);
  }
  if (unaff_ESI != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004e8d7a;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0xb5261c85);
  }
LAB_004e8d7a:
  if (unaff_EDI == 7) {
    FEObject__SetVisible();
    return;
  }
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4e8d90 FUN_004e8d90

void FUN_004e8d90(void)

{
  byte bVar1;
  int iVar2;
  int unaff_EBX;
  undefined **ppuVar3;
  undefined4 uVar4;
  int local_10 [3];
  
  iVar2 = *(int *)(unaff_EBX + 0x44) + 1;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 2;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 3;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 4;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 5;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 6;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 7;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  iVar2 = *(int *)(unaff_EBX + 0x44) + 8;
  if (iVar2 < 10) {
    ppuVar3 = &PTR_FUN_006c7804;
  }
  else {
    ppuVar3 = (undefined **)&DAT_006ca778;
  }
  FUN_00565da0(ppuVar3,iVar2);
  FEngPrintf(local_10);
  if ((&DAT_007602a0)[(*(int *)(unaff_EBX + 0x40) + *(int *)(unaff_EBX + 0x44)) * 0x454] == '\0') {
    uVar4 = 0xd1431c0b;
  }
  else {
    bVar1 = *(char *)(unaff_EBX + 0x40) + (char)*(int *)(unaff_EBX + 0x44);
    if (bVar1 < 0x1b) {
      uVar4 = *(undefined4 *)(&DAT_006fa120 + (uint)bVar1 * 4);
    }
    else {
      uVar4 = 0;
    }
  }
  FUN_00495f00(uVar4);
  FUN_004e8b10();
  local_10[0] = *(int *)(unaff_EBX + 0x4c) + -7;
  if (((&DAT_007602a0)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_007442f0 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (((&DAT_007606f4)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_007442f4 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (((&DAT_00760b48)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_007442f8 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (((&DAT_00760f9c)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_007442fc + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (((&DAT_007613f0)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_00744300 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
  }
  FUN_00495f70();
  if (((&DAT_00761844)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_00744304 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (((&DAT_00761c98)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    FUN_00495f70();
    FUN_00495fc0();
  }
  else {
    FUN_004ad7b0(*(undefined4 *)(&DAT_00744308 + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
    FUN_00495f70();
  }
  if (*(int *)(unaff_EBX + 0x44) == local_10[0]) {
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
  }
  else {
    FUN_00495fc0();
    FUN_00495fc0();
    FUN_00495fc0();
    if (((&DAT_007620ec)[*(int *)(unaff_EBX + 0x44) * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
      FUN_00495f70();
      FUN_00495fc0();
      goto LAB_004e9363;
    }
    FUN_004ad7b0(*(undefined4 *)(&DAT_0074430c + *(int *)(unaff_EBX + 0x44) * 4));
    FUN_00495fc0();
  }
  FUN_00495f70();
LAB_004e9363:
  iVar2 = *(int *)(unaff_EBX + 0x40) + *(int *)(unaff_EBX + 0x44);
  if (((&DAT_007602a0)[iVar2 * 0x454] == '\0') && (DAT_00735dcc == '\0')) {
    uVar4 = 0x4207c198;
  }
  else {
    uVar4 = *(undefined4 *)(&DAT_006fa0b0 + iVar2 * 4);
  }
  FUN_00495f00(uVar4);
  return;
}


// ==== 0x4e93b0 FUN_004e93b0

undefined4 FUN_004e93b0(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  
  switch(in_EAX) {
  case 0:
    uVar1 = bStringHash();
    return uVar1;
  case 1:
    uVar1 = bStringHash();
    return uVar1;
  case 2:
    uVar1 = bStringHash();
    return uVar1;
  case 3:
    uVar1 = bStringHash();
    return uVar1;
  case 4:
    uVar1 = bStringHash();
    return uVar1;
  case 5:
    uVar1 = bStringHash();
    return uVar1;
  case 6:
    uVar1 = bStringHash();
    return uVar1;
  case 7:
    uVar1 = bStringHash();
    return uVar1;
  case 8:
    uVar1 = bStringHash();
    return uVar1;
  case 9:
    uVar1 = bStringHash();
    return uVar1;
  case 10:
    uVar1 = bStringHash();
    return uVar1;
  case 0xb:
    uVar1 = bStringHash();
    return uVar1;
  case 0xc:
    uVar1 = bStringHash();
    return uVar1;
  case 0xd:
    uVar1 = bStringHash();
    return uVar1;
  case 0xe:
    uVar1 = bStringHash();
    return uVar1;
  case 0xf:
    uVar1 = bStringHash();
    return uVar1;
  case 0x10:
    uVar1 = bStringHash();
    return uVar1;
  case 0x11:
    uVar1 = bStringHash();
    return uVar1;
  case 0x12:
    uVar1 = bStringHash();
    return uVar1;
  case 0x13:
    uVar1 = bStringHash();
    return uVar1;
  case 0x14:
    uVar1 = bStringHash();
    return uVar1;
  case 0x15:
    uVar1 = bStringHash();
    return uVar1;
  case 0x16:
    uVar1 = bStringHash();
    return uVar1;
  case 0x17:
    uVar1 = bStringHash();
    return uVar1;
  case 0x18:
    uVar1 = bStringHash();
    return uVar1;
  case 0x19:
    uVar1 = bStringHash();
    return uVar1;
  case 0x1a:
    uVar1 = bStringHash();
    return uVar1;
  default:
    return 0;
  }
}


// ==== 0x4e9540 FUN_004e9540

undefined4 * FUN_004e9540(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2d54;
  FUN_0051bad0(&DAT_007449c8);
  if (param_1[3] == 0) {
LAB_004e959f:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x17e83cc);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e959f;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e959f;
  }
  FEObject__SetInvisible(iVar1);
  if (param_1[3] == 0) {
LAB_004e95e6:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x98861bee);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004e95e6;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004e95e6;
  }
  FEObject__SetInvisible(iVar1);
  if (param_1[3] != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004e9649;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x98861bef);
  }
LAB_004e9649:
  FEObject__SetInvisible(iVar1);
  iVar1 = DAT_0073578c;
  bVar2 = DAT_0073578c != 0;
  param_1[0x14] = DAT_006fb038;
  DAT_006fb038 = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x13] = 0x1b;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (bVar2) {
    cFEng__SetCurrentButton(iVar1);
  }
  FUN_00414a10();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e96b0 FUN_004e96b0

void * __thiscall FUN_004e96b0(void *param_1,byte param_2)

{
  FUN_004e96d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e96d0 FUN_004e96d0

void __fastcall FUN_004e96d0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c2d54;
  DAT_006fb038 = param_1[0x14];
  local_4 = 0;
  FUN_0051bb50();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4e9730 FUN_004e9730

void __thiscall FUN_004e9730(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  
  if (param_2 < 0x9120409f) {
    if (param_2 == 0x9120409e) {
      if ((((*(uint *)(param_1 + 0x40) & 1) != 0) &&
          (*(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) - 1, DAT_006f1dd8 != 0)) &&
         (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
        (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(2);
        FUN_004e8d90();
        return;
      }
      goto LAB_004e9c0e;
    }
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
          (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(5);
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        FUN_004e8d90();
        return;
      }
      if (param_2 == 0xc407210) {
        DAT_00735770 = FUN_004e93b0();
        if (DAT_00735770 == 0) {
          return;
        }
        iVar4 = FUN_0051a8b0();
        if (((&DAT_007602a0)[iVar4 * 0x454] != '\0') || (DAT_00735dcc != '\0')) {
          if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(4);
          }
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          FUN_004e8d90();
          return;
        }
        if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
          (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
          FUN_004e8d90();
          return;
        }
        goto LAB_004e9c0e;
      }
      if (param_2 != 0x72619778) goto LAB_004e9c0e;
      uVar2 = *(uint *)(param_1 + 0x40);
      if (uVar2 < 2) {
        if (1 < *(uint *)(param_1 + 0x44)) {
          bVar7 = DAT_006f1dd8 != 0;
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) - 2;
          if ((bVar7) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(0);
            FUN_004e8d90();
            return;
          }
          goto LAB_004e9c0e;
        }
        if (1 < uVar2) goto LAB_004e97c2;
      }
      else {
LAB_004e97c2:
        *(uint *)(param_1 + 0x40) = uVar2 - 2;
        if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
          (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(0);
        }
      }
      FUN_00414a60();
      FUN_00414a60();
      if ((*(int *)(param_1 + 0x44) == 0) || (*(int *)(param_1 + 0x44) == 1)) {
        FUN_00414a10();
        FUN_004e8d90();
        return;
      }
      goto LAB_004e9c0e;
    }
    if (param_2 != 0x911c0a4b) goto LAB_004e9c0e;
    uVar2 = *(int *)(param_1 + 0x4c) - 7;
    uVar1 = *(int *)(param_1 + 0x4c) - 6;
    uVar3 = *(uint *)(param_1 + 0x40);
    if ((5 < uVar3) && (*(uint *)(param_1 + 0x44) < uVar2)) {
      uVar2 = *(uint *)(param_1 + 0x44) + 2;
      *(uint *)(param_1 + 0x44) = uVar2;
      if (uVar1 < uVar2) {
        *(uint *)(param_1 + 0x44) = uVar1;
        FUN_004e8d90();
        return;
      }
      if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
        (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(1);
        FUN_004e8d90();
        return;
      }
      goto LAB_004e9c0e;
    }
    if ((uVar3 == 5) && (*(uint *)(param_1 + 0x44) == uVar2)) {
      if ((DAT_006f1dd8 != 0) && (piVar5 = *(int **)(DAT_007356a8 + 0xc0), piVar5 != (int *)0x0)) {
        uVar8 = 7;
LAB_004e99d7:
        (**(code **)(*piVar5 + 0x14))(uVar8);
      }
    }
    else if (((uVar3 < 6) && (*(uint *)(param_1 + 0x40) = uVar3 + 2, DAT_006f1dd8 != 0)) &&
            (piVar5 = *(int **)(DAT_007356a8 + 0xc0), piVar5 != (int *)0x0)) {
      uVar8 = 1;
      goto LAB_004e99d7;
    }
    FUN_00414a60();
    FUN_00414a60();
    if ((*(uint *)(param_1 + 0x44) == uVar2) || (*(uint *)(param_1 + 0x44) == uVar1)) {
      FUN_00414a10();
      FUN_004e8d90();
      return;
    }
    goto LAB_004e9c0e;
  }
  if (param_2 != 0xabc08912) {
    if (param_2 == 0xb5971bf1) {
      uVar2 = *(uint *)(param_1 + 0x40);
      if ((uVar2 & 1) == 0) {
        if ((uVar2 == 6) && (*(int *)(param_1 + 0x44) == *(int *)(param_1 + 0x4c) + -7)) {
          if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(7);
            FUN_004e8d90();
            return;
          }
        }
        else {
          *(uint *)(param_1 + 0x40) = uVar2 + 1;
          if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)) {
            (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(3);
            FUN_004e8d90();
            return;
          }
        }
      }
    }
    else if (((param_2 == 0xc98356ba) && (FUN_004f7d30(), *(int *)(param_1 + 0x40) == 7)) &&
            (0x13 < *(uint *)(param_1 + 0x44))) {
      *(undefined4 *)(param_1 + 0x40) = 6;
      FUN_004e8d90();
      FUN_004e8d90();
      return;
    }
    goto LAB_004e9c0e;
  }
  if (DAT_0073578c == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar4 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar4 + 0x18);
    }
    iVar4 = 0;
    if (iVar6 != 0) {
      iVar4 = *(int *)(iVar6 + 0x80);
    }
  }
  uVar2 = *(uint *)(iVar4 + 0x10);
  if (uVar2 < 0xbbe88516) {
    if (uVar2 != 0xbbe88515) {
      switch(uVar2) {
      case 0x9db42df9:
        break;
      case 0x9db42dfa:
        goto switchD_004e9b8b_caseD_9db42dfa;
      case 0x9db42dfb:
        goto switchD_004e9b8b_caseD_9db42dfb;
      case 0x9db42dfc:
        goto switchD_004e9b8b_caseD_9db42dfc;
      case 0x9db42dfd:
        goto switchD_004e9b8b_caseD_9db42dfd;
      case 0x9db42dfe:
        goto switchD_004e9b8b_caseD_9db42dfe;
      case 0x9db42dff:
        goto switchD_004e9b8b_caseD_9db42dff;
      case 0x9db42e00:
        goto switchD_004e9b8b_caseD_9db42e00;
      default:
        goto switchD_004e9b8b_default;
      }
    }
switchD_004e9b8b_caseD_9db42df9:
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  else if (uVar2 < 0xf1e6ea38) {
    if (uVar2 == 0xf1e6ea37) goto switchD_004e9b8b_caseD_9db42df9;
    switch(uVar2) {
    case 0xbbe88516:
      goto switchD_004e9b8b_caseD_9db42dfa;
    case 0xbbe88517:
      goto switchD_004e9b8b_caseD_9db42dfb;
    case 0xbbe88518:
      goto switchD_004e9b8b_caseD_9db42dfc;
    case 0xbbe88519:
      goto switchD_004e9b8b_caseD_9db42dfd;
    case 0xbbe8851a:
      goto switchD_004e9b8b_caseD_9db42dfe;
    case 0xbbe8851b:
      goto switchD_004e9b8b_caseD_9db42dff;
    case 0xbbe8851c:
      goto switchD_004e9b8b_caseD_9db42e00;
    }
  }
  else {
    switch(uVar2) {
    case 0xf1e6ea38:
switchD_004e9b8b_caseD_9db42dfa:
      *(undefined4 *)(param_1 + 0x40) = 1;
      break;
    case 0xf1e6ea39:
switchD_004e9b8b_caseD_9db42dfb:
      *(undefined4 *)(param_1 + 0x40) = 2;
      break;
    case 0xf1e6ea3a:
switchD_004e9b8b_caseD_9db42dfc:
      *(undefined4 *)(param_1 + 0x40) = 3;
      break;
    case 0xf1e6ea3b:
switchD_004e9b8b_caseD_9db42dfd:
      *(undefined4 *)(param_1 + 0x40) = 4;
      break;
    case 0xf1e6ea3c:
switchD_004e9b8b_caseD_9db42dfe:
      *(undefined4 *)(param_1 + 0x40) = 5;
      break;
    case 0xf1e6ea3d:
switchD_004e9b8b_caseD_9db42dff:
      *(undefined4 *)(param_1 + 0x40) = 6;
      break;
    case 0xf1e6ea3e:
switchD_004e9b8b_caseD_9db42e00:
      *(undefined4 *)(param_1 + 0x40) = 7;
    }
  }
switchD_004e9b8b_default:
  FUN_004e8b10();
LAB_004e9c0e:
  FUN_004e8d90();
  return;
}


// ==== 0x4e9c80 FUN_004e9c80

undefined4 FUN_004e9c80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688233;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x54);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004e9540(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e9ce0 Screen_MU_UG_RankScreen::Screen_MU_UG_RankScreen

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_RankScreen__Screen_MU_UG_RankScreen(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar2 = DAT_0073578c;
  bVar3 = DAT_0073578c != 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2da4;
  if (bVar3) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
    }
  }
  param_1[0x13] = 0;
  FUN_00414a10();
  UrlRankScreen__Show(param_1);
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_1[3] == 0) {
LAB_004e9d90:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfd4);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_004e9d90;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_004e9d90;
  }
  param_1[0x10] = iVar2;
  if (param_1[3] != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_004e9dec;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(0xaa68bfce);
  }
LAB_004e9dec:
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


// ==== 0x4e9e60 FUN_004e9e60

void * __thiscall FUN_004e9e60(void *param_1,byte param_2)

{
  FUN_004e9e80();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e9e80 FUN_004e9e80

void __fastcall FUN_004e9e80(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2da4;
  FUN_004f7b50();
  return;
}


// ==== 0x4e9e90 UrlRankScreen::Show

/* [canon] canon med (ghidra) docs/re/canon.md */

void UrlRankScreen__Show(char *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int extraout_EDX;
  int iVar7;
  int local_8;
  
  iVar2 = (int)param_1;
  iVar7 = *(int *)((int)param_1 + 0x4c);
  iVar3 = Career__GetLastWonEventTextRow(iVar7);
  iVar4 = Career__GetUrlRank(iVar7);
  FUN_00495f00(*(undefined4 *)(&DAT_006fa18c + iVar7 * 4));
  param_1 = (char *)(iVar3 + 9);
  iVar7 = 1;
  local_8 = 10;
  do {
    FUN_004f42f0("RANK_DATA_%02d",iVar7);
    FUN_004f42f0("PLAYERNAME_DATA_%02d",iVar7);
    FUN_004f42f0("CARNAME_DATA_%02d",iVar7);
    FEngPrintf(&PTR_FUN_006c7968,iVar7);
    if (iVar7 == iVar4) {
      FEngPrintf(&DAT_007588c4);
    }
    else {
      piVar1 = (int *)(DAT_00734410 + *param_1 * 0xc);
      piVar5 = piVar1 + 1;
      if (*piVar1 != (int)*param_1) {
        piVar5 = (int *)&DAT_006b9172;
      }
      FEngPrintf(&DAT_006cc568,piVar5);
    }
    iVar7 = iVar7 + 1;
    param_1 = param_1 + -1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  if (iVar4 == -1) {
    if (((((*(int *)(iVar2 + 0xc) != 0) && (iVar7 = FEngFindPackage(), iVar7 != 0)) &&
         (iVar7 = FUN_004ffb70(), iVar7 != 0)) ||
        ((DAT_0073578c != 0 && (iVar7 = FUN_004ef050(0x212f91c3), iVar7 != 0)))) &&
       (*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar7 + 0x18) == 5)) {
      uVar6 = *(undefined4 *)(iVar7 + 0x60);
      iVar7 = *(int *)(iVar7 + 0x5c);
      if (0 < iVar7) {
        do {
          FEObject__SetVisible(uVar6);
          uVar6 = *(undefined4 *)(extraout_EDX + 4);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    FEngPrintf(&DAT_006cc568,&DAT_007588c4);
    return;
  }
  if (((*(int *)(iVar2 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      uVar6 = FUN_004ef050(0x212f91c3);
      FEObject__SetInvisible(uVar6);
      return;
    }
    iVar7 = 0;
  }
  FEObject__SetInvisible(iVar7);
  return;
}


// ==== 0x4ea090 FUN_004ea090

void FUN_004ea090(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x4c);
  if (param_1 == -0x6edfbf62) {
    if (iVar1 != 0) {
      *(int *)(unaff_ESI + 0x4c) = iVar1 + -1;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar1 != 3)) {
    *(int *)(unaff_ESI + 0x4c) = iVar1 + 1;
  }
  if (*(int *)(unaff_ESI + 0x4c) == 0) {
    FUN_00414a10();
  }
  else {
    FUN_00414a60();
  }
  if (*(int *)(unaff_ESI + 0x4c) == 3) {
    FUN_00414a10();
  }
  else {
    FUN_00414a60();
  }
  if (*(int *)(unaff_ESI + 0x4c) != iVar1) {
    UrlRankScreen__Show(unaff_ESI);
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
  }
  return;
}


// ==== 0x4ea150 FUN_004ea150

void __thiscall FUN_004ea150(int param_1,uint param_2)

{
  if (0xb5971bf1 < param_2) {
    if (param_2 == 0xc98356ba) {
      FUN_00563cb0();
    }
    return;
  }
  if (param_2 != 0xb5971bf1) {
    if (param_2 == 0x911ab364) {
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  FUN_004ea090(param_2);
  return;
}


// ==== 0x4ea1b0 Screen_MU_UG_RankScreen::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_RankScreen__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688213;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x50);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_RankScreen__Screen_MU_UG_RankScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ea210 Screen_MU_UG_StatsScreen::Screen_MU_UG_StatsScreen

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_StatsScreen__Screen_MU_UG_StatsScreen(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar2 = DAT_0073578c;
  bVar3 = DAT_0073578c != 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2d74;
  if (bVar3) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
    }
  }
  param_1[0x10] = 0;
  FUN_00414a10();
  FUN_004ea510();
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  if (param_1[3] == 0) {
LAB_004ea2c7:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfd4);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_004ea2c7;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_004ea2c7;
  }
  param_1[0x11] = iVar2;
  if (param_1[3] == 0) {
LAB_004ea307:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfce);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_004ea307;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_004ea307;
  }
  param_1[0x12] = iVar2;
  if (param_1[3] == 0) {
LAB_004ea348:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfd7);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_004ea348;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_004ea348;
  }
  param_1[0x13] = iVar2;
  if (param_1[3] != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_004ea3a5;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(0xaa68bfc6);
  }
LAB_004ea3a5:
  param_1[0x14] = iVar2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0)) &&
     (iVar2 = 0, DAT_0073578c != 0)) {
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
  param_1[0x15] = iVar2;
  if (DAT_00777b4c == 0x80) {
    param_1[0xf] = 0xc1703e7a;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4ea430 FUN_004ea430

void * __thiscall FUN_004ea430(void *param_1,byte param_2)

{
  FUN_004ea450();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ea450 FUN_004ea450

void __fastcall FUN_004ea450(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2d74;
  FUN_004f7b50();
  return;
}


// ==== 0x4ea460 FUN_004ea460

void FUN_004ea460(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x40);
  if (param_1 == -0x6edfbf62) {
    if (iVar1 != 0) {
      *(int *)(unaff_ESI + 0x40) = iVar1 + -1;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar1 != 4)) {
    *(int *)(unaff_ESI + 0x40) = iVar1 + 1;
  }
  if (*(int *)(unaff_ESI + 0x40) == 0) {
    FUN_00414a10();
  }
  else {
    FUN_00414a60();
  }
  if (*(int *)(unaff_ESI + 0x40) == 4) {
    FUN_00414a10();
  }
  else {
    FUN_00414a60();
  }
  if (iVar1 != *(int *)(unaff_ESI + 0x40)) {
    FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
    FUN_004ea510();
  }
  return;
}


// ==== 0x4ea510 FUN_004ea510

void FUN_004ea510(void)

{
  int in_EAX;
  
  switch(*(undefined4 *)(in_EAX + 0x40)) {
  case 0:
    FUN_004ea810();
    return;
  case 1:
    FUN_004ea6b0();
    return;
  case 2:
    FUN_004ea720();
    return;
  case 3:
    FUN_004ea7a0();
    return;
  case 4:
    FUN_004ea880();
  }
  return;
}


// ==== 0x4ea560 FUN_004ea560

void FUN_004ea560(void)

{
  int iVar1;
  int iStack00000004;
  
  iVar1 = 1;
  iStack00000004 = 10;
  do {
    FUN_004f42f0("STATSTYPE_DATA_%02d",iVar1,&DAT_006b9172);
    FEngPrintf();
    FUN_004f42f0("STATS_DATA_%02d",iVar1,&DAT_006b9172);
    FEngPrintf();
    iVar1 = iVar1 + 1;
    iStack00000004 = iStack00000004 + -1;
  } while (iStack00000004 != 0);
  return;
}


// ==== 0x4ea5d0 FUN_004ea5d0

void FUN_004ea5d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_20 [32];
  
  FUN_0059fc90(param_3);
  FUN_004f42f0("STATSTYPE_DATA_%02d",param_1 + 1,param_2);
  FUN_00495f00();
  FUN_004f42f0("STATS_DATA_%02d",param_1 + 1,&DAT_006cc568,local_20);
  FEngPrintf();
  return;
}


// ==== 0x4ea650 FUN_004ea650

void __fastcall FUN_004ea650(undefined4 param_1,int param_2,undefined4 param_3)

{
  FUN_004f42f0("STATSTYPE_DATA_%02d",param_2 + 1);
  FUN_00495f00();
  FUN_004f42f0("STATS_DATA_%02d",param_2 + 1,&DAT_006ca778,param_3);
  FEngPrintf();
  return;
}


// ==== 0x4ea6b0 FUN_004ea6b0

void FUN_004ea6b0(void)

{
  undefined4 unaff_ESI;
  
  FUN_00495f00(0x817e429a);
  FUN_004ea560(unaff_ESI);
  FUN_004ea650(DAT_007681c8);
  FUN_004ea650(DAT_007681cc);
  FUN_004ea650(DAT_007681d0);
  return;
}


// ==== 0x4ea720 FUN_004ea720

void FUN_004ea720(void)

{
  undefined4 unaff_ESI;
  
  FUN_00495f00(0x8d9a96d8);
  FUN_004ea560(unaff_ESI);
  FUN_004ea650(DAT_007681d4);
  FUN_004ea650(DAT_007681d8);
  FUN_004ea650(DAT_007681dc);
  FUN_004ea650(DAT_00768204);
  return;
}


// ==== 0x4ea7a0 FUN_004ea7a0

void FUN_004ea7a0(void)

{
  undefined4 unaff_ESI;
  
  FUN_00495f00(0x40ed9413);
  FUN_004ea560(unaff_ESI);
  FUN_004ea650(DAT_007681e0);
  FUN_004ea650(DAT_007681e4);
  FUN_004ea650(DAT_007681e8);
  return;
}


// ==== 0x4ea810 FUN_004ea810

void FUN_004ea810(void)

{
  undefined4 unaff_ESI;
  
  FUN_00495f00(0xd14b7fcd);
  FUN_004ea560(unaff_ESI);
  FUN_004ea650(DAT_007681ec);
  FUN_004ea650(DAT_007681f0);
  FUN_004ea650(DAT_007681f4);
  return;
}


// ==== 0x4ea880 FUN_004ea880

void FUN_004ea880(void)

{
  undefined4 uVar1;
  undefined4 unaff_ESI;
  float local_4;
  
  FUN_00495f00(0xdda5e29e);
  FUN_004ea560(unaff_ESI);
  FUN_004ea650(DAT_007681bc);
  FUN_004ea650(DAT_007681c0);
  FUN_004ea650(DAT_007681c4);
  uVar1 = _ftol_nocw();
  FUN_004ea650(uVar1);
  local_4 = DAT_007681b8;
  if (DAT_007588f0 == 0) {
    local_4 = DAT_007681b8 * 0.001 * 0.6213;
  }
  else if (DAT_007588f0 == 1) {
    local_4 = DAT_007681b8 * 0.001;
  }
  FUN_004ea5d0(4,0x78eff98f,local_4);
  FUN_004ea650(DAT_00758ad4);
  return;
}


// ==== 0x4ea990 FUN_004ea990

void __thiscall FUN_004ea990(int param_1,uint param_2)

{
  if (0xb5971bf1 < param_2) {
    if (param_2 == 0xc98356ba) {
      FUN_004eaa10();
    }
    return;
  }
  if (param_2 != 0xb5971bf1) {
    if (param_2 == 0x911ab364) {
      if (DAT_00777b4c != 0x80) {
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  FUN_004ea460(param_2);
  return;
}


// ==== 0x4eaa10 FUN_004eaa10

void FUN_004eaa10(void)

{
  char cVar1;
  int iVar2;
  int unaff_EBX;
  int *piVar3;
  undefined4 uVar4;
  int local_8;
  
  piVar3 = (int *)(unaff_EBX + 0x44);
  local_8 = 4;
  do {
    if (((*piVar3 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar1 != '\0')) {
      uVar4 = *(undefined4 *)(*piVar3 + 0x10);
      if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
         (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
        if (DAT_0073578c != 0) {
          iVar2 = FUN_004ef050(uVar4);
          goto LAB_004eaab2;
        }
      }
      else {
LAB_004eaab2:
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,*piVar3,*(undefined4 *)(unaff_EBX + 0x54),iVar2,0);
        }
      }
      switch(*(undefined4 *)(*piVar3 + 0x10)) {
      case 0xaa68bfc6:
        uVar4 = 0x911c0a4b;
        break;
      default:
        goto switchD_004eaaef_caseD_aa68bfc7;
      case 0xaa68bfce:
        uVar4 = 0x9120409e;
        break;
      case 0xaa68bfd4:
        uVar4 = 0xb5971bf1;
        break;
      case 0xaa68bfd7:
        uVar4 = 0x72619778;
      }
      FUN_004c96c0(uVar4);
    }
switchD_004eaaef_caseD_aa68bfc7:
    piVar3 = piVar3 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4eab60 Screen_MU_UG_StatsScreen::Create

/* [canon] canon med (capstone) docs/re/gameflow.md */

undefined4 Screen_MU_UG_StatsScreen__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688843;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x58);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_StatsScreen__Screen_MU_UG_StatsScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4eabc0 Screen_MU_UG_UndergroundMenu::Screen_MU_UG_UndergroundMenu

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_UndergroundMenu__Screen_MU_UG_UndergroundMenu(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 local_810 [1824];
  char local_f0 [128];
  undefined1 local_70 [64];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006887db;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FEScreen__FEScreen(param_1,param_2);
  local_14 = 0;
  *param_1 = &PTR_FUN_006c2d94;
  *(undefined1 *)(param_1 + 0x10) = 0;
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_810);
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,local_810);
  _DAT_0072cc80 = 1;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,1);
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 && (*(int *)(iVar3 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar2 + 0x18));
  }
  if (DAT_00777b4c == 4) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar2 + 0x18));
    }
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar2 + 0x18));
    }
  }
  FUN_004b2480();
  if ((DAT_007341bc == 0) &&
     (((DAT_007677a8 == 0 || ((int *)(DAT_007677a8 + 0x58a0) == (int *)0x0)) ||
      (*(int *)(DAT_007677a8 + 0x58a0) != 0x71)))) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = &DAT_0075f2b5;
  }
  if (*pcVar4 == '\x02') {
    if ((DAT_0073578c != 0) && (cFEng__SetButtonState(DAT_0073578c,0), DAT_0073578c != 0)) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
    if ((((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xd6d4315d);
    }
    iVar2 = DAT_0073578c;
    FUN_004f75b0(0x60606060);
    if ((((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar2 = DAT_0073578c, iVar3 == 0)) ||
        (iVar3 = FUN_004ffb70(), iVar2 = DAT_0073578c, iVar3 == 0)) && (iVar2 != 0)) {
      FUN_004ef050(0x1c8ace);
    }
    FUN_004f75b0(0x60606060);
    DAT_006fa19c = 0x74fd9de5;
    local_2c = 0x639;
    local_30 = 0xb0e803e8;
    local_28 = 0;
    if (DAT_00735dd0 == 0) {
      DAT_00735dd0 = 1;
      FUN_004dcbe0(&local_30,"GenericOKDialogMedium.fng",param_1[3]);
    }
  }
  else {
    DAT_00735dd0 = 0;
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
  }
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  iVar3 = 0x80;
  pcVar4 = local_f0;
  do {
    cVar1 = pcVar4[iVar2 - (int)local_f0];
    iVar3 = iVar3 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar3 != 0);
  if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
     (uVar5 = DAT_0076026c, DAT_0073440c != '\0')) {
    uVar5 = 1000000000;
  }
  bSPrintf_regdst(0x40,&DAT_006ca778,uVar5);
  FEngPrintf(local_f0,local_70);
  if (DAT_0073578c != 0) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x4eafc0 FUN_004eafc0

void * __thiscall FUN_004eafc0(void *param_1,byte param_2)

{
  FUN_004eafe0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4eafe0 FUN_004eafe0

void __fastcall FUN_004eafe0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2d94;
  FUN_004f7b50();
  return;
}


// ==== 0x4eaff0 FUN_004eaff0

undefined4 __fastcall FUN_004eaff0(uint param_1)

{
  int iVar1;
  int in_EAX;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = DAT_0073578c;
  if ((DAT_007341bc == 0) &&
     (((DAT_007677a8 == 0 || ((int *)(DAT_007677a8 + 0x58a0) == (int *)0x0)) ||
      (*(int *)(DAT_007677a8 + 0x58a0) != 0x71)))) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = &DAT_0075f2b5;
  }
  bVar5 = *pcVar2 == '\x02';
  uVar3 = CONCAT31((int3)((uint)pcVar2 >> 8),bVar5);
  if (param_1 < 0xd6d4315e) {
    if (param_1 == 0xd6d4315d) {
      if (!bVar5) {
        uVar3 = FEngSwitchPackages(*(undefined4 *)(in_EAX + 0xc));
        return uVar3;
      }
    }
    else if (param_1 == 0x1c8ace) {
      if (!bVar5) {
        DAT_00777b50 = 1;
        uVar3 = FEngSwitchPackages(*(undefined4 *)(in_EAX + 0xc));
        return uVar3;
      }
    }
    else {
      if (param_1 == 0x74fd9de5) {
        uVar3 = FEngSwitchPackages(*(undefined4 *)(in_EAX + 0xc));
        return uVar3;
      }
      if ((param_1 == 0xa936c3a2) && (!bVar5)) {
        if (DAT_0076027f == '\0') {
          DAT_0076027f = 1;
          DAT_00735dc4 = 1;
          uVar3 = FEngSwitchPackages(*(undefined4 *)(in_EAX + 0xc));
          return uVar3;
        }
        FUN_004c96c0(0x6c6603df);
        uVar3 = LaunchPartsBrowser(1,"MU_Garage.fng",0);
        return uVar3;
      }
    }
  }
  else if (param_1 == 0xf20e404a) {
    uVar3 = *(undefined4 *)(in_EAX + 0xc);
    if (DAT_0073578c != 0) {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      uVar3 = 0;
      if ((iVar4 != 0) && (uVar3 = 0, *(int *)(iVar4 + 0x18) != 0)) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar4 + 0x18));
      }
    }
  }
  else if (param_1 == 0xf9a69dbe) {
    uVar3 = FEngSwitchPackages(*(undefined4 *)(in_EAX + 0xc));
    return uVar3;
  }
  return uVar3;
}


// ==== 0x4eb170 FUN_004eb170

undefined4 FUN_004eb170(void)

{
  uint in_EAX;
  
  if (in_EAX < 0xd6d4315e) {
    if (in_EAX == 0xd6d4315d) {
      return 0x112356f6;
    }
    if (in_EAX == 0x1c8ace) {
      return 0xa52e8cc7;
    }
    if (in_EAX == 0x74fd9de5) {
      return 0xa52dff64;
    }
    if (in_EAX == 0xa936c3a2) {
      return 0xe385e93b;
    }
  }
  else {
    if (in_EAX == 0xf20e404a) {
      return 0x76421903;
    }
    if (in_EAX == 0xf9a69dbe) {
      return 0x33f5c357;
    }
  }
  return 0;
}


// ==== 0x4eb1e0 FUN_004eb1e0

void __thiscall FUN_004eb1e0(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x40) == '\0') {
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_24 = 0x798403a4;
        uStack_20 = 0x639;
        uStack_1c = 0x12345678;
        uStack_18 = 0x541389e5;
        uStack_14 = 0;
        uStack_10 = 0;
        uStack_c = 0xb8a7c6cd;
        FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xc407210) {
        DAT_006fa19c = *(undefined4 *)(param_3 + 0x10);
        FUN_004eaff0();
        return;
      }
      if (param_2 == 0x12345678) {
        iVar2 = FEngFindPackage();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0xff;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else if (param_2 == 0xabc08912) {
      cVar1 = Career__IsFinalEventWon();
      if (cVar1 != '\0') {
        FUN_00415510(0x60606060);
        FUN_00415510(0x60606060);
        FUN_00415510(0x60606060);
      }
      cVar1 = FUN_004f6ce0(&DAT_006c7a3c);
      if ((cVar1 == '\0') &&
         (iVar2 = FEngGetCurrentButton(*(undefined4 *)(param_1 + 0xc)), param_3 == iVar2)) {
        FEObject__SetScript("HighLight",1);
        uVar3 = FUN_004eb170(param_1);
        FUN_00416bb0(uVar3);
        FEngSetScript("FadeIn",1);
      }
    }
  }
  else if (param_2 == 0x12340220) {
    *(undefined1 *)(param_1 + 0x40) = 0;
    return;
  }
  return;
}


// ==== 0x4eb390 Screen_MU_UG_UndergroundMenu::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_UndergroundMenu__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689413;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_UndergroundMenu__Screen_MU_UG_UndergroundMenu(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4eb3f0 FUN_004eb3f0

void FUN_004eb3f0(void)

{
  while (DAT_006fa0a8 == '\0') {
    FUN_0063e5c0(1);
  }
  return;
}


// ==== 0x4eb420 FUN_004eb420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004eb420(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  pcVar3 = &DAT_0072cd50;
  DAT_00735dc0 = 0;
  iVar5 = 0x80;
  do {
    cVar1 = pcVar3[param_1 + -0x72cd50];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    iVar2 = DAT_0073578c;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735dac = param_2;
  _DAT_00735db0 = param_3;
  _DAT_00735da8 = 2;
  if (DAT_0073578c != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar5 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
  }
  return;
}


// ==== 0x4eb4b0 FUN_004eb4b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004eb4b0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  pcVar3 = &DAT_0072cd50;
  DAT_00735dc0 = 0;
  iVar5 = 0x80;
  do {
    cVar1 = pcVar3[param_2 + -0x72cd50];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735dac = param_3;
  pcVar3 = &DAT_0072cd10;
  iVar5 = 0x40;
  do {
    cVar1 = pcVar3[param_4 + -0x72cd10];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    iVar2 = DAT_0073578c;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735db4 = param_5;
  _DAT_00735db8 = param_6;
  _DAT_00735da8 = 4;
  if (DAT_0073578c != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar5 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
  }
  return;
}


// ==== 0x4eb560 FUN_004eb560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004eb560(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  pcVar3 = &DAT_0072cd50;
  DAT_00735dc0 = 0;
  iVar5 = 0x80;
  do {
    cVar1 = pcVar3[param_2 + -0x72cd50];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735dac = param_3;
  pcVar3 = &DAT_0072cd10;
  iVar5 = 0x40;
  do {
    cVar1 = pcVar3[param_4 + -0x72cd10];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    iVar2 = DAT_0073578c;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735db4 = param_5;
  _DAT_00735db8 = param_6;
  _DAT_00735da8 = 3;
  if (DAT_0073578c != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar5 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
  }
  return;
}


// ==== 0x4eb610 FUN_004eb610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004eb610(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  pcVar3 = &DAT_0072cd50;
  DAT_00735dc0 = 0;
  iVar5 = 0x80;
  do {
    cVar1 = pcVar3[param_2 + -0x72cd50];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735dac = param_3;
  pcVar3 = &DAT_0072cd10;
  iVar5 = 0x40;
  do {
    cVar1 = pcVar3[param_4 + -0x72cd10];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    iVar2 = DAT_0073578c;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735db4 = param_5;
  _DAT_00735db8 = param_6;
  _DAT_00735da8 = 5;
  if (DAT_0073578c != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar5 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
  }
  return;
}


// ==== 0x4eb6c0 FUN_004eb6c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004eb6c0(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  pcVar3 = &DAT_0072cd50;
  DAT_00735dc0 = 0;
  iVar5 = 0x80;
  do {
    cVar1 = pcVar3[param_1 + -0x72cd50];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735dac = param_2;
  pcVar3 = &DAT_0072cd10;
  iVar5 = 0x40;
  do {
    cVar1 = pcVar3[param_3 + -0x72cd10];
    iVar5 = iVar5 + -1;
    *pcVar3 = cVar1;
    iVar2 = DAT_0073578c;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar5 != 0);
  _DAT_00735da8 = 8;
  if (DAT_0073578c != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar5 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
  }
  return;
}


// ==== 0x4eb760 FUN_004eb760

undefined4 FUN_004eb760(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006879e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x254);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004eb7c0(pvVar1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4eb7c0 FUN_004eb7c0

undefined4 * __thiscall FUN_004eb7c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006879c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_2,param_1);
  local_4 = 0;
  *param_2 = &PTR_FUN_006c2d28;
  FEMenuData__FEMenuData();
  local_4 = CONCAT31(local_4._1_3_,1);
  param_2[0x11] = *(undefined4 *)(param_1 + 4);
  FUN_004ebf20(&DAT_00777c10);
  DAT_00735ba8 = 0;
  DAT_00735da4 = param_2;
  uVar1 = FEngFindPackage();
  param_2[0x94] = uVar1;
  FUN_0041f160(0x43225720,0x13bba3b,0,0x32);
  param_2[0x8e] = 0x406415e3;
  param_2[0x90] = 0;
  if (((param_2[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      ExceptionList = local_c;
      return param_2;
    }
    iVar2 = FUN_004ef050(0x43225720);
    if (iVar2 == 0) {
      ExceptionList = local_c;
      return param_2;
    }
  }
  if (*(int *)(iVar2 + 0x18) == 2) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x20;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x4eb8c0 FUN_004eb8c0

void * __thiscall FUN_004eb8c0(void *param_1,byte param_2)

{
  FUN_004eb8e0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4eb8e0 FUN_004eb8e0

void FUN_004eb8e0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c2d28;
  DAT_00735da0 = DAT_00735da0 + -1;
  local_4 = 0;
  if (DAT_00735da0 < 0) {
    DAT_00735da0 = 0;
  }
  eh_vector_destructor_iterator(param_1 + 0x16,0xc,0x20,WString_Free);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4eb950 FUN_004eb950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004eb950(undefined4 *param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0073578c;
  DAT_00735ba8 = 0;
  _DAT_00777c28 = param_1[6];
  _DAT_00777c2c = param_1[7];
  _DAT_00777c14 = param_1[1];
  _DAT_00777c18 = param_1[2];
  _DAT_00777c20 = param_1[4];
  _DAT_00777c24 = param_1[5];
  _DAT_00777c1c = param_1[3];
  _DAT_00777c10 = *param_1;
  DAT_00735da0 = DAT_00735da0 + 1;
  if (DAT_0073578c != 0) {
    if ((in_EAX == 0) || (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),uVar3,0xff);
    DAT_00735d9c = 0;
    DAT_00735d9d = 0;
    return;
  }
  DAT_00735ba8 = 0;
  DAT_00735d9c = 0;
  DAT_00735d9d = 0;
  return;
}


// ==== 0x4eba00 FUN_004eba00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004eba00(char *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  DAT_00735da0 = DAT_00735da0 + 1;
  if ((param_2 == 0) && (DAT_00735ba8 = *param_1, DAT_00735ba8 != '\0')) {
    pcVar5 = &DAT_00735ba8;
    do {
      cVar1 = (param_1 + -0x735ba7)[(int)pcVar5];
      pcVar5 = pcVar5 + 1;
      *pcVar5 = cVar1;
    } while (cVar1 != '\0');
  }
  iVar2 = DAT_0073578c;
  _DAT_00777c28 = 0x639;
  _DAT_00777c2c = 0;
  _DAT_00777c14 = param_3;
  _DAT_00777c18 = param_3;
  _DAT_00777c24 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c10 = 0;
  if (DAT_0073578c != 0) {
    _DAT_00777c20 = param_2;
    if ((in_EAX == 0) || (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
    DAT_00735d9c = 0;
    DAT_00735d9d = 0;
    return;
  }
  DAT_00735d9c = 0;
  DAT_00735d9d = 0;
  _DAT_00777c10 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c20 = param_2;
  _DAT_00777c24 = 0;
  _DAT_00777c28 = 0x639;
  _DAT_00777c2c = 0;
  return;
}


// ==== 0x4ebac0 FUN_004ebac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ebac0(char *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  DAT_00735da0 = DAT_00735da0 + 1;
  if ((param_2 == 0) && (DAT_00735ba8 = *param_1, DAT_00735ba8 != '\0')) {
    pcVar5 = &DAT_00735ba8;
    do {
      cVar1 = (param_1 + -0x735ba7)[(int)pcVar5];
      pcVar5 = pcVar5 + 1;
      *pcVar5 = cVar1;
    } while (cVar1 != '\0');
  }
  iVar2 = DAT_0073578c;
  _DAT_00777c28 = 0x639;
  _DAT_00777c2c = 0;
  _DAT_00777c14 = param_3;
  _DAT_00777c18 = param_3;
  _DAT_00777c24 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c10 = 0;
  if (DAT_0073578c != 0) {
    _DAT_00777c20 = param_2;
    if ((in_EAX == 0) || (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar3 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar4,0xff);
    DAT_00735d9c = 0;
    DAT_00735d9d = 1;
    return;
  }
  DAT_00735d9c = 0;
  DAT_00735d9d = 1;
  _DAT_00777c10 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c20 = param_2;
  _DAT_00777c24 = 0;
  _DAT_00777c28 = 0x639;
  _DAT_00777c2c = 0;
  return;
}


// ==== 0x4ebb80 FUN_004ebb80

void FUN_004ebb80(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004ebba3:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x43225720);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004ebba3;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004ebba3;
  }
  FEObject__SetVisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004ebbea:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x13bba3b);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004ebbea;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004ebbea;
  }
  FEObject__SetVisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004ebc31:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x13bba3c);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004ebc31;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004ebc31;
  }
  FEObject__SetVisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004ebc94;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0xe5dbc6d6);
  }
LAB_004ebc94:
  FEObject__SetVisible(iVar1);
  DAT_0070108e = 0;
  FUN_0041f4d0();
  return;
}


// ==== 0x4ebcb0 FUN_004ebcb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ebcb0(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  DAT_00735da0 = DAT_00735da0 + 1;
  uVar5 = 0;
  if ((param_2 == 0) && (DAT_00735ba8 = *param_1, DAT_00735ba8 != '\0')) {
    pcVar4 = &DAT_00735ba8;
    do {
      cVar1 = (param_1 + -0x735ba7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  iVar2 = DAT_0073578c;
  _DAT_00777c28 = 0;
  _DAT_00777c2c = 0;
  _DAT_00777c14 = 0;
  _DAT_00777c18 = 0;
  _DAT_00777c24 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c10 = 0;
  _DAT_00777c20 = param_2;
  if (DAT_0073578c != 0) {
    if (in_EAX != 0) {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar3 != 0) {
        uVar5 = *(undefined4 *)(iVar3 + 0x18);
      }
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar5,0xff);
  }
  DAT_00735d9c = 1;
  return;
}


// ==== 0x4ebd60 FUN_004ebd60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ebd60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0073578c;
  _DAT_00777c20 = param_2;
  DAT_00735da0 = DAT_00735da0 + 1;
  _DAT_00777c28 = 0x541389e5;
  _DAT_00777c2c = 0;
  _DAT_00777c24 = 0;
  _DAT_00777c1c = 0;
  _DAT_00777c10 = 0;
  if (DAT_0073578c != 0) {
    _DAT_00777c14 = param_1;
    _DAT_00777c18 = param_1;
    if ((in_EAX == 0) || (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),uVar3,0xff);
    DAT_00735d9c = 0;
    return;
  }
  DAT_00735d9c = 0;
  _DAT_00777c10 = 0;
  _DAT_00777c14 = param_1;
  _DAT_00777c18 = param_1;
  _DAT_00777c1c = 0;
  _DAT_00777c24 = 0;
  _DAT_00777c28 = 0x541389e5;
  _DAT_00777c2c = 0;
  return;
}


// ==== 0x4ebdf0 FUN_004ebdf0

void FUN_004ebdf0(void)

{
  int iVar1;
  
  if (((DAT_0073578c != 0) && (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f09b0(*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  iVar1 = FEngFindPackage();
  DAT_00735da4 = 0;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  return;
}


// ==== 0x4ebe60 FUN_004ebe60

void __thiscall
FUN_004ebe60(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  
  cVar1 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar1 != '\0') {
    return;
  }
  if (param_2 == 0xc407210) {
    if (DAT_00735d9c != '\0') {
      return;
    }
    FEngQueueMessageToPackage();
  }
  else {
    if (param_2 != -0x6ee54c9c) {
      if (param_2 != -0x367ca946) {
        return;
      }
      if (DAT_00735d9d == '\0') {
        return;
      }
      FUN_004ebb80();
      DAT_00735d9d = 0;
      return;
    }
    if (DAT_00735d9c != '\0') {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0x40) + 8) != 0) {
      FEngQueueMessageToPackage();
      FUN_004ebdf0(param_1,1);
      return;
    }
  }
  FUN_004ebdf0(param_1,1);
  return;
}


// ==== 0x4ebf20 FUN_004ebf20

void FUN_004ebf20(int *param_1)

{
  char *pcVar1;
  int iVar2;
  int unaff_EBX;
  
  *(int **)(unaff_EBX + 0x40) = param_1;
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x43225720);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x203c4ad7);
    }
  }
  FEObject__SetVisible(iVar2);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x203c4ad8);
    }
  }
  FEObject__SetVisible(iVar2);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x203c4ad9);
    }
  }
  FEObject__SetVisible(iVar2);
  if (param_1[3] == 0) {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x5caf80ed);
      }
    }
    FEObject__SetInvisible(iVar2);
  }
  else {
    FUN_00495f00(param_1[3]);
  }
  if (param_1[4] == 0) {
    iVar2 = 0;
    if (DAT_00735ba8 != '\0') {
      do {
        pcVar1 = &DAT_00735ba9 + iVar2;
        iVar2 = iVar2 + 1;
      } while (*pcVar1 != '\0');
      if (0 < iVar2) {
        FEngPrintf(&DAT_00735ba8);
        goto LAB_004ec103;
      }
    }
    FUN_00495f70();
  }
  else {
    FUN_00495f00(param_1[4]);
  }
LAB_004ec103:
  if (param_1[5] == 0) {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x749cbecd);
      }
    }
    FEObject__SetInvisible(iVar2);
  }
  else {
    FUN_00495f00(param_1[5]);
  }
  if (*param_1 == 0) {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0xed77e685);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (DAT_0073578c != 0) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0xd08f7531);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (DAT_0073578c != 0) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
    if (DAT_00735d9c == '\0') {
      if ((DAT_0073578c != 0) && (cFEng__SetButtonState(DAT_0073578c,1), DAT_0073578c != 0)) {
        cFEng__SetCurrentButton(DAT_0073578c);
      }
      FUN_00495f00(param_1[6]);
      return;
    }
    FUN_00495f70();
    if (DAT_0073578c != 0) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    return;
  }
  if (*param_1 == 1) {
    FUN_00495f70();
    FUN_00495fc0();
    FUN_00495fc0();
    if ((((DAT_0073578c != 0) && (cFEng__SetButtonState(DAT_0073578c,0), DAT_0073578c != 0)) &&
        (cFEng__SetButtonState(DAT_0073578c,1), DAT_0073578c != 0)) &&
       (cFEng__SetButtonState(DAT_0073578c,1), DAT_0073578c != 0)) {
      cFEng__SetCurrentButton(DAT_0073578c);
    }
    FUN_00495f00(param_1[6]);
    FUN_00495f00(param_1[7]);
    FUN_00495f70();
    FUN_004f6c30("UnhighLight",1);
    FUN_004f6c30("Highlight",1);
  }
  return;
}


// ==== 0x4ec3c0 FUN_004ec3c0

void FUN_004ec3c0(void)

{
  if (DAT_00735da4 != 0) {
    FUN_004ebdf0(DAT_00735da4,0);
  }
  return;
}


// ==== 0x4ec3e0 FUN_004ec3e0

void __fastcall FUN_004ec3e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2c8c;
  FUN_004f7b50();
  return;
}


// ==== 0x4ec3f0 FUN_004ec3f0

void * __thiscall FUN_004ec3f0(void *param_1,byte param_2)

{
  FUN_004ec3e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ec410 Screen_Keyboard::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_Keyboard__Create(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006879a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x210);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_Keyboard__Screen_Keyboard(pvVar1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ec470 Screen_Keyboard::Screen_Keyboard

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_Keyboard__Screen_Keyboard(undefined4 *param_1)

{
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,unaff_EDI);
  *param_1 = &PTR_FUN_006c2c8c;
  local_4 = 0;
  param_1[0x80] = *(undefined4 *)(unaff_EDI + 4);
  FUN_004ec990(param_1);
  FUN_004ed930(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4ec4d0 FUN_004ec4d0

void __fastcall FUN_004ec4d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  DAT_00777b64 = param_4;
  DAT_00777b70 = param_3;
  puVar3 = (undefined4 *)&DAT_00777b74;
  DAT_00777b60 = param_1;
  DAT_00777b6c = in_EAX;
  for (iVar2 = 0x27; iVar1 = DAT_0073578c, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (DAT_0073578c != 0) {
    if (param_2 != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar2 != 0) {
        UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar2 + 0x18),0xff);
        return;
      }
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),0,0xff);
  }
  return;
}


// ==== 0x4ec550 FUN_004ec550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004ec550(undefined4 param_1,char param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((*(char *)(param_3 + 0x50) != '\0') || (param_2 != '\0')) {
    puVar3 = *(undefined4 **)(param_3 + 0x1fc);
    for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  FEngQueueMessageToPackage();
  uVar1 = *(undefined4 *)(param_3 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar1 = FUN_004f09b0(*(int *)(iVar2 + 0x18));
      }
    }
  }
  DAT_007363a8 = 0;
  DAT_0070108d = 1;
  _DAT_00735ba4 = 0;
  return uVar1;
}


// ==== 0x4ec5f0 FUN_004ec5f0

void __thiscall FUN_004ec5f0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (0x9120409e < param_2) {
    if (0xc519bfc0 < param_2) {
      if (param_2 == 0xc98356ba) {
        iVar1 = FUN_004117b0();
        if (0 < iVar1) {
          if (DAT_0073578c != 0) {
            *(undefined1 *)(*(int *)(DAT_0073578c + 8) + 1) = 1;
          }
          FUN_004ec550(param_1);
        }
        iVar1 = FUN_004117b0();
        if (iVar1 < 0) {
          if (DAT_0073578c != 0) {
            *(undefined1 *)(*(int *)(DAT_0073578c + 8) + 1) = 1;
          }
          FUN_004ec550(param_1);
        }
        FUN_004ed930(param_1);
        return;
      }
      if (param_2 != 0xd9feec59) {
        return;
      }
      FUN_004ee160();
      return;
    }
    if (param_2 != 0xc519bfc0) {
      if (param_2 != 0xabc08912) {
        if (param_2 != 0xb5971bf1) {
          if (param_2 != 0xb5af2461) {
            return;
          }
          FUN_004ec550(param_1);
          return;
        }
        if (DAT_006f1dd8 == 0) {
          return;
        }
        if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
          return;
        }
        (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(3);
        return;
      }
      goto LAB_004ec639;
    }
    FUN_004edfb0();
    goto LAB_004ec76b;
  }
  if (param_2 == 0x9120409e) {
    if (DAT_006f1dd8 == 0) {
      return;
    }
    if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(2);
    return;
  }
  if (0x72619778 < param_2) {
    if (param_2 == 0x911ab364) {
      if (*(int *)(param_1 + 0x208) == -1) {
        return;
      }
      FUN_004ec550(param_1);
      return;
    }
    if (param_2 != 0x911c0a4b) {
      return;
    }
    if (DAT_006f1dd8 == 0) {
      return;
    }
    if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(1);
    return;
  }
  if (param_2 == 0x72619778) {
    if (DAT_006f1dd8 == 0) {
      return;
    }
    if (*(int **)(DAT_007356a8 + 0xc0) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(0);
    return;
  }
  if (param_2 != 0xc407210) {
    if (param_2 == 0x5073ef13) {
      if (DAT_006ee6f0 == 7) {
        return;
      }
      FUN_004ee210();
      return;
    }
    if (param_2 != 0x55d1e635) {
      return;
    }
LAB_004ec639:
    if (param_3 == 0) {
      return;
    }
    iVar1 = FUN_004edd90();
    if (iVar1 < 0) {
      iVar1 = FUN_004eddb0();
      if (iVar1 < 0) {
        return;
      }
      FUN_004edc10();
      return;
    }
    FUN_004edb30();
    return;
  }
  if (param_3 == 0) {
    return;
  }
  iVar1 = FUN_004edd90();
  if (-1 < iVar1) {
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x17);
    }
    uVar2 = FUN_004eddd0();
    FUN_004ee060(uVar2);
    return;
  }
  uVar2 = FUN_004eddb0();
  switch(uVar2) {
  case 0:
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x19);
    }
    FUN_004edfb0();
    return;
  case 1:
    iVar1 = bStrCmp();
    if ((iVar1 != 0) || (*(int *)(param_1 + 0x20c) != 3)) {
      if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
        (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x18);
      }
      FUN_004ec550(param_1);
      return;
    }
    break;
  case 2:
    FUN_004ee160();
    goto LAB_004ec76b;
  case 3:
    FUN_004ee1c0();
LAB_004ec76b:
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x19);
      return;
    }
    break;
  case 4:
    FUN_004eded0();
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x17);
      return;
    }
  }
  return;
}


// ==== 0x4ec990 FUN_004ec990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec990(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  bool bVar10;
  int local_2c;
  int *local_28;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  *(undefined1 **)(param_1 + 0x1fc) = &DAT_00777b74;
  _DAT_00735ba4 = 1;
  iVar4 = DAT_00777b6c;
  if (0x9c < DAT_00777b6c) {
    iVar4 = 0x9c;
  }
  *(int *)(param_1 + 0x4c) = iVar4;
  *(undefined4 *)(param_1 + 0x204) = DAT_00777b60;
  *(undefined4 *)(param_1 + 0x208) = DAT_00777b64;
  *(undefined4 *)(param_1 + 0x20c) = DAT_00777b70;
  iVar4 = DAT_006ee6f0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  switch(iVar4) {
  case 1:
    *(undefined4 *)(param_1 + 0x40) = 1;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x40) = 2;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x40) = 3;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x40) = 4;
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x40) = 5;
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x40) = 6;
    break;
  default:
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  *(undefined1 *)(param_1 + 0x50) = 1;
  iVar4 = DAT_0073578c;
  DAT_0073639c = &DAT_00777b74;
  DAT_007363ac = DAT_00777b6c;
  DAT_007363a8 = 1;
  DAT_007363b0 = 0;
  DAT_00777b74 = 0;
  DAT_007363a0 = 0;
  DAT_007363a4 = 0;
  if (DAT_0073578c != 0) {
    *(undefined1 *)(*(int *)(DAT_0073578c + 8) + 1) = 0;
  }
  *(undefined1 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)(param_1 + 0x52) = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (*(int *)(param_1 + 0x20c) == 3) {
    *(undefined1 *)(param_1 + 0x52) = 1;
  }
  if (((*(int *)(param_1 + 0xc) == 0) ||
      (iVar5 = FEngFindPackage(), iVar4 = DAT_0073578c, iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar5 == 0)) {
    if (iVar4 == 0) {
      iVar5 = 0;
      iVar4 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x5dfa6642);
      iVar4 = DAT_0073578c;
    }
  }
  *(int *)(param_1 + 0x54) = iVar5;
  if (((*(int *)(param_1 + 0xc) == 0) ||
      (iVar5 = FEngFindPackage(), iVar4 = DAT_0073578c, iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar5 == 0)) {
    if (iVar4 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xa036136a);
    }
  }
  *(int *)(param_1 + 0x58) = iVar5;
  local_28 = (int *)(param_1 + 0x118);
  local_2c = 1;
  local_24 = 0xd;
  do {
    bSPrintf_regdst(0x20,"KB_SYMBOL_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar9 + 1;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ecbf3:
      if (iVar5 == 0) {
LAB_004ecc04:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004ecbf3;
          goto LAB_004ecbdc;
        }
        goto LAB_004ecc04;
      }
LAB_004ecbdc:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ecbf3;
    }
    local_28[-0x2f] = iVar6;
    bSPrintf_regdst(0x20,"KB_SYMBOL_BUTTON_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar9 + 1;
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004eccc3:
      if (iVar5 == 0) {
LAB_004eccd4:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004eccc3;
          goto LAB_004eccac;
        }
        goto LAB_004eccd4;
      }
LAB_004eccac:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004eccc3;
    }
    *local_28 = iVar6;
    local_28 = local_28 + 1;
    local_2c = local_2c + 1;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  local_28 = (int *)(param_1 + 0x14c);
  local_2c = 1;
  local_24 = 0x22;
  do {
    bSPrintf_regdst(0x20,"KB_LETTER_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar9 + 1;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ecdd3:
      if (iVar5 == 0) {
LAB_004ecde4:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004ecdd3;
          goto LAB_004ecdbc;
        }
        goto LAB_004ecde4;
      }
LAB_004ecdbc:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ecdd3;
    }
    local_28[-0x2f] = iVar6;
    bSPrintf_regdst(0x20,"KB_LETTER_BUTTON_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar9 + 1;
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ecea3:
      if (iVar5 == 0) {
LAB_004eceb4:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004ecea3;
          goto LAB_004ece8c;
        }
        goto LAB_004eceb4;
      }
LAB_004ece8c:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ecea3;
    }
    *local_28 = iVar6;
    local_28 = local_28 + 1;
    local_2c = local_2c + 1;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  local_28 = (int *)(param_1 + 0x1e8);
  local_2c = 1;
  local_24 = 5;
  do {
    bSPrintf_regdst(0x20,"KB_CONTROL_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar9 + 1;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ecfb3:
      if (iVar5 == 0) {
LAB_004ecfc4:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004ecfb3;
          goto LAB_004ecf9c;
        }
        goto LAB_004ecfc4;
      }
LAB_004ecf9c:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ecfb3;
    }
    local_28[-5] = iVar6;
    bSPrintf_regdst(0x20,"KB_CONTROL_BUTTON_%.2d",local_2c);
    iVar4 = -1;
    pbVar9 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar9 + 1;
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar9 = pbVar9 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed08b:
      iVar6 = 0;
      if (iVar5 == 0) {
LAB_004ed0a2:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
        iVar6 = DAT_0073578c;
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        iVar6 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_004ed08b;
          goto LAB_004ed06c;
        }
        goto LAB_004ed0a2;
      }
LAB_004ed06c:
      if ((iVar6 == 0) ||
         (iVar7 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar5 = DAT_0073578c, iVar7 == 0))
      goto LAB_004ed08b;
    }
    *local_28 = iVar7;
    local_28 = local_28 + 1;
    local_2c = local_2c + 1;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  if ((*(int *)(param_1 + 0x20c) == 0) && (DAT_006ee6f0 != 7)) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed15b:
      iVar4 = 0;
      if (iVar6 == 0) goto LAB_004ed37d;
      iVar5 = FUN_004ef050(0xbf8ec481);
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar6 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c == 0) goto LAB_004ed37d;
        iVar5 = *(int *)(DAT_0073578c + 8);
        if ((iVar5 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004ed15b;
      }
      if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar5 == 0))
      goto LAB_004ed15b;
    }
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0x18) == 2)) {
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
      puVar2 = DAT_00735710;
      bVar10 = DAT_00735710 != (undefined4 *)0x0;
      *(undefined4 *)(iVar5 + 0x5c) = 0xfa4c00a9;
      if (bVar10) {
        (**(code **)*puVar2)(iVar5);
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffd | 0x400000;
      iVar4 = DAT_0073578c;
    }
  }
  else {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed228:
      iVar4 = 0;
      if (iVar6 == 0) {
LAB_004ed243:
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(0x4c913f7);
        iVar4 = DAT_0073578c;
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar6 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar5 = *(int *)(DAT_0073578c + 8);
          if ((iVar5 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004ed228;
          goto LAB_004ed20e;
        }
        goto LAB_004ed243;
      }
LAB_004ed20e:
      if ((iVar4 == 0) ||
         (iVar5 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar4 = DAT_0073578c, iVar5 == 0))
      goto LAB_004ed228;
    }
    FEObject__SetInvisible(iVar5);
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed2bd:
      iVar5 = 0;
      if (iVar4 == 0) {
LAB_004ed2d8:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(0xbf8ec481);
        iVar5 = DAT_0073578c;
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar4 = DAT_0073578c;
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
        iVar5 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar6 = *(int *)(DAT_0073578c + 8);
          if ((iVar6 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004ed2bd;
          goto LAB_004ed2a3;
        }
        goto LAB_004ed2d8;
      }
LAB_004ed2a3:
      if ((iVar5 == 0) ||
         (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed2bd;
    }
    FEObject__SetInvisible(iVar6);
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed352:
      iVar4 = 0;
      if (iVar5 == 0) {
LAB_004ed36d:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(0x261a66d0);
        iVar4 = DAT_0073578c;
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar6 = *(int *)(DAT_0073578c + 8);
          if ((iVar6 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004ed352;
          goto LAB_004ed338;
        }
        goto LAB_004ed36d;
      }
LAB_004ed338:
      if ((iVar4 == 0) ||
         (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed352;
    }
    FEObject__SetInvisible(iVar6);
  }
LAB_004ed37d:
  if (*(int *)(param_1 + 0x20c) == 3) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed3fd:
      iVar5 = 0;
      if (iVar4 == 0) {
LAB_004ed418:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(0x261a66ce);
        iVar5 = DAT_0073578c;
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar4 = DAT_0073578c;
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
        iVar5 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar6 = *(int *)(DAT_0073578c + 8);
          if ((iVar6 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004ed3fd;
          goto LAB_004ed3e3;
        }
        goto LAB_004ed418;
      }
LAB_004ed3e3:
      if ((iVar5 == 0) ||
         (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed3fd;
    }
    FEObject__SetInvisible(iVar6);
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed496:
      iVar4 = 0;
      if (iVar5 == 0) {
LAB_004ed4b1:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(0x261a66cf);
        iVar4 = DAT_0073578c;
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar6 = *(int *)(DAT_0073578c + 8);
          if ((iVar6 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004ed496;
          goto LAB_004ed47c;
        }
        goto LAB_004ed4b1;
      }
LAB_004ed47c:
      if ((iVar4 == 0) ||
         (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed496;
    }
    FEObject__SetInvisible(iVar6);
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed52f:
      iVar6 = 0;
      if (iVar4 == 0) {
LAB_004ed54a:
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(0x2a7d443d);
        iVar6 = DAT_0073578c;
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar4 = DAT_0073578c;
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
        iVar6 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar6 = *(int *)(DAT_0073578c + 8);
          if ((iVar6 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004ed52f;
          goto LAB_004ed515;
        }
        goto LAB_004ed54a;
      }
LAB_004ed515:
      if ((iVar5 == 0) ||
         (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 = DAT_0073578c, iVar5 == 0))
      goto LAB_004ed52f;
    }
    FEObject__SetInvisible(iVar5);
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed5c8:
      iVar5 = 0;
      if (iVar6 != 0) {
        uVar8 = FUN_004ef050(0xca67c5a7);
        iVar5 = DAT_0073578c;
        FEObject__SetInvisible(uVar8);
        goto LAB_004ed6be;
      }
LAB_004ed5ef:
      iVar4 = 0;
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar6 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar5 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar5 = *(int *)(DAT_0073578c + 8);
          if ((iVar5 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004ed5c8;
          goto LAB_004ed5ae;
        }
        goto LAB_004ed5ef;
      }
LAB_004ed5ae:
      if ((iVar4 == 0) ||
         (iVar4 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar5 = DAT_0073578c, iVar4 == 0))
      goto LAB_004ed5c8;
    }
    FEObject__SetInvisible(iVar4);
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed66f:
    iVar5 = 0;
    if (iVar4 != 0) {
      iVar6 = FUN_004ef050(0xca67c5a7);
LAB_004ed682:
      iVar5 = DAT_0073578c;
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) == 2)) {
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
        puVar2 = DAT_00735710;
        bVar10 = DAT_00735710 != (undefined4 *)0x0;
        *(undefined4 *)(iVar6 + 0x5c) = 0xe013d55;
        if (bVar10) {
          (**(code **)*puVar2)(iVar6);
        }
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
        iVar5 = DAT_0073578c;
      }
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004ed655:
      if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed66f;
      goto LAB_004ed682;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004ed66f;
      goto LAB_004ed655;
    }
  }
LAB_004ed6be:
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed735:
    iVar4 = 0;
    if (iVar5 != 0) {
      iVar6 = FUN_004ef050(0x59c69891);
LAB_004ed748:
      iVar4 = DAT_0073578c;
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) == 2)) {
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
        puVar2 = DAT_00735710;
        bVar10 = DAT_00735710 != (undefined4 *)0x0;
        *(undefined4 *)(iVar6 + 0x5c) = 0x7f042bcd;
        if (bVar10) {
          (**(code **)*puVar2)(iVar6);
        }
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
        iVar4 = DAT_0073578c;
      }
    }
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004ed71b:
      if ((iVar4 == 0) || (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed735;
      goto LAB_004ed748;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004ed735;
      goto LAB_004ed71b;
    }
  }
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ed7fb:
    iVar5 = 0;
    if (iVar4 != 0) {
      iVar6 = FUN_004ef050(0x64aff8d3);
LAB_004ed80e:
      iVar5 = DAT_0073578c;
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) == 2)) {
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
        puVar2 = DAT_00735710;
        bVar10 = DAT_00735710 != (undefined4 *)0x0;
        *(undefined4 *)(iVar6 + 0x5c) = 0x95e10f41;
        if (bVar10) {
          (**(code **)*puVar2)(iVar6);
        }
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
        iVar5 = DAT_0073578c;
      }
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004ed7e1:
      if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
      goto LAB_004ed7fb;
      goto LAB_004ed80e;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004ed7fb;
      goto LAB_004ed7e1;
    }
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004ed8c1;
    }
    if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 != 0))
    goto LAB_004ed8d4;
  }
LAB_004ed8c1:
  if (iVar5 == 0) {
    return;
  }
  iVar4 = FUN_004ef050(0x18985589);
LAB_004ed8d4:
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) == 2)) {
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar10 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar4 + 0x5c) = 0x169268;
    if (bVar10) {
      (**(code **)*puVar2)(iVar4);
    }
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x4ed930 FUN_004ed930

void FUN_004ed930(int param_1)

{
  uint *puVar1;
  ushort uVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  int *piVar8;
  ushort uVar9;
  int iVar10;
  short *psVar11;
  short local_840 [32];
  undefined4 local_800;
  
  iVar10 = 0;
  piVar8 = (int *)(param_1 + 0x5c);
  do {
    cVar4 = FUN_004eddd0();
    if (DAT_006ee6f0 == 7) {
      psVar11 = local_840;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        psVar11[0] = 0;
        psVar11[1] = 0;
        psVar11 = psVar11 + 2;
      }
      iVar5 = *piVar8;
      local_840[0] = (short)cVar4;
      WString_Assign();
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
    }
    else {
      FEObject__SetFormattedText(&DAT_006c7408,(int)cVar4);
    }
    iVar10 = iVar10 + 1;
    piVar8 = piVar8 + 1;
  } while (iVar10 < 0x2f);
  iVar10 = *(int *)(param_1 + 0x54);
  FUN_0059ff40(&local_800,0x800);
  iVar5 = 0;
  uVar9 = (ushort)local_800;
  uVar2 = uVar9;
  while (uVar2 != 0) {
    iVar5 = iVar5 + 1;
    uVar2 = *(ushort *)((int)&local_800 + iVar5 * 2);
  }
  if (*(uint *)(iVar10 + 100) < iVar5 + 1U) {
    WString_Grow();
  }
  puVar6 = *(undefined2 **)(iVar10 + 0x60);
  puVar7 = (ushort *)&local_800;
  if (puVar6 != (undefined2 *)0x0) {
    while (uVar9 != 0) {
      *puVar6 = (short)local_800;
      puVar7 = puVar7 + 1;
      uVar9 = *puVar7;
      local_800 = (uint)uVar9;
      puVar6 = puVar6 + 1;
    }
    *puVar6 = 0;
  }
  *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x400000;
  puVar1 = (uint *)(*(int *)(param_1 + 0x54) + 0x1c);
  *puVar1 = *puVar1 | 2;
  pcVar3 = *(char **)(param_1 + 0x1fc);
  if (*(int *)(param_1 + 0x20c) == 2) {
    iVar10 = 0;
    if (pcVar3 != (char *)0x0) {
      cVar4 = *pcVar3;
      while (cVar4 != '\0') {
        iVar5 = iVar10 + 1;
        iVar10 = iVar10 + 1;
        cVar4 = pcVar3[iVar5];
      }
    }
    iVar5 = 0;
    if (0 < iVar10) {
      do {
        if (iVar5 == 0x3f) break;
        *(undefined1 *)((int)local_840 + iVar5) = 0x2a;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar10);
    }
    *(undefined1 *)((int)local_840 + iVar5) = 0;
  }
  iVar10 = *(int *)(param_1 + 0x54);
  FUN_0059ff40(&local_800,0x800);
  WString_Assign();
  *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x400000;
  return;
}


// ==== 0x4edad0 FUN_004edad0

void FUN_004edad0(void)

{
  int unaff_ESI;
  undefined1 local_40 [64];
  
  *(uint *)(*(int *)(unaff_ESI + 0x54) + 0x1c) = *(uint *)(*(int *)(unaff_ESI + 0x54) + 0x1c) | 2;
  if (*(int *)(unaff_ESI + 0x20c) == 2) {
    FUN_004fa0b0(0x40);
    FUN_0041f060(*(undefined4 *)(unaff_ESI + 0x54),local_40);
    return;
  }
  FUN_0041f060(*(undefined4 *)(unaff_ESI + 0x54),*(undefined4 *)(unaff_ESI + 0x1fc));
  return;
}


// ==== 0x4edb30 FUN_004edb30

void FUN_004edb30(void)

{
  int iVar1;
  char in_AL;
  char cVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBX + 0x5c + unaff_EDI * 4);
  if (in_AL == '\0') {
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
    iVar1 = *(int *)(unaff_EBX + 0x118 + unaff_EDI * 4);
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
  }
  else {
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
    iVar1 = *(int *)(unaff_EBX + 0x118 + unaff_EDI * 4);
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
      return;
    }
  }
  return;
}


// ==== 0x4edc10 FUN_004edc10

void FUN_004edc10(void)

{
  int iVar1;
  char in_AL;
  char cVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBX + 0x1d4 + unaff_EDI * 4);
  if (in_AL == '\0') {
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
    iVar1 = *(int *)(unaff_EBX + 0x1e8 + unaff_EDI * 4);
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
  }
  else {
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
    iVar1 = *(int *)(unaff_EBX + 0x1e8 + unaff_EDI * 4);
    if (*(int *)(iVar1 + 0x18) < 0x100) {
      cVar2 = FEColor_NearlyEqual();
      if (cVar2 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
      return;
    }
  }
  return;
}


// ==== 0x4edd00 FUN_004edd00

void __fastcall FUN_004edd00(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int unaff_EBX;
  undefined1 local_800 [2048];
  
  pcVar3 = *(char **)(unaff_EBX + 0x1fc);
  iVar4 = 0x9c;
  param_1 = param_1 - (int)pcVar3;
  do {
    cVar1 = pcVar3[param_1];
    iVar4 = iVar4 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar4 != 0);
  *(undefined1 *)(*(int *)(unaff_EBX + 0x1fc) + 0x9c) = 0;
  FUN_0059ff40(local_800,0x800);
  WString_Assign();
  pcVar3 = *(char **)(unaff_EBX + 0x1fc);
  iVar4 = 0;
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      iVar2 = iVar4 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = pcVar3[iVar2];
    }
  }
  *(int *)(unaff_EBX + 0x48) = iVar4;
  return;
}


// ==== 0x4edd90 FUN_004edd90

int __fastcall FUN_004edd90(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x118);
  do {
    if (*piVar2 == param_2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x2f);
  return -1;
}


// ==== 0x4eddb0 FUN_004eddb0

int __fastcall FUN_004eddb0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x1e8);
  do {
    if (*piVar2 == param_2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 5);
  return -1;
}


// ==== 0x4eddd0 FUN_004eddd0

uint __fastcall FUN_004eddd0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint3 uVar5;
  int unaff_EDI;
  bool bVar6;
  
  if (unaff_EDI < 0xd) {
    if (*(char *)(param_1 + 0x51) == '\0') {
      bVar6 = *(char *)(param_1 + 0x52) != '\0';
    }
    else {
      bVar6 = *(char *)(param_1 + 0x52) == '\0';
    }
    iVar2 = *(int *)(param_1 + 0x20c);
    uVar4 = (uint)(byte)"`1234567890-=~!@#"[unaff_EDI + (uint)bVar6 * 0xd];
    if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 2)) {
      return (uint)(byte)(&DAT_006b6ab2)[unaff_EDI];
    }
    if (iVar2 == 4) {
      return (uint)(byte)(&DAT_006b6abf)[unaff_EDI];
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 0x52);
    if (*(char *)(param_1 + 0x51) == '\0') {
      bVar6 = cVar1 != '\0';
    }
    else {
      bVar6 = cVar1 == '\0';
    }
    iVar3 = *(int *)(param_1 + 0x40);
    iVar2 = (uint)bVar6 + iVar3 * 2;
    uVar5 = (uint3)((uint)iVar2 >> 8);
    uVar4 = CONCAT31(uVar5,(&DAT_006b675b)[unaff_EDI + (iVar3 + iVar2) * 0x22]);
    if (*(int *)(param_1 + 0x20c) == 0) {
      if (*(char *)(param_1 + 0x53) != '\0') {
        if (*(char *)(param_1 + 0x51) != '\0') {
          return (uint)(byte)(&DAT_006b6a25)[unaff_EDI + (uint)(cVar1 == '\0') * 0x22];
        }
        uVar4 = (uint)(byte)(&DAT_006b6a25)[unaff_EDI + (uint)(cVar1 != '\0') * 0x22];
      }
    }
    else {
      if ((&DAT_006b679f)[unaff_EDI + iVar3 * 0x66] == '\0') {
        return (uint)uVar5 << 8;
      }
      if ((&DAT_006b679f)[unaff_EDI + iVar3 * 0x66] == '\x02') {
        return (byte)((*(int *)(param_1 + 0x20c) != 4) - 1) & 0x2e;
      }
    }
  }
  return uVar4;
}


// ==== 0x4eded0 FUN_004eded0

void FUN_004eded0(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  
  if (*(int *)(in_EAX + 0x20c) == 0) {
    if (*(char *)(in_EAX + 0x50) != '\0') {
      *(undefined1 *)(in_EAX + 0x50) = 0;
      FUN_004edd00();
    }
    pcVar3 = *(char **)(in_EAX + 0x1fc);
    iVar4 = 0;
    if (pcVar3 != (char *)0x0) {
      cVar2 = *pcVar3;
      while (cVar2 != '\0') {
        iVar1 = iVar4 + 1;
        iVar4 = iVar4 + 1;
        cVar2 = pcVar3[iVar1];
      }
    }
    if (iVar4 < *(int *)(in_EAX + 0x4c)) {
      iVar4 = 0x9a;
      if (*(int *)(in_EAX + 0x48) < 0x9a) {
        do {
          *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + iVar4) =
               *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + -1 + iVar4);
          iVar4 = iVar4 + -1;
        } while (*(int *)(in_EAX + 0x48) < iVar4);
      }
      *(undefined1 *)(*(int *)(in_EAX + 0x48) + *(int *)(in_EAX + 0x1fc)) = 0x20;
      *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + 0x9b) = 0;
      iVar4 = *(int *)(in_EAX + 0x48) + 1;
      *(int *)(in_EAX + 0x48) = iVar4;
      if (*(int *)(in_EAX + 0x4c) < iVar4) {
        *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x4c);
      }
      FUN_004edad0();
      if (DAT_006f8ae0 != 0x13) {
        uVar5 = 0;
        do {
          if (*(int *)((int)&DAT_006f8a48 + uVar5) == 0x13) break;
          uVar5 = uVar5 + 8;
        } while (uVar5 < 0x70);
      }
      FUN_004cd180(0);
    }
  }
  return;
}


// ==== 0x4edfb0 FUN_004edfb0

void FUN_004edfb0(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (*(char *)(in_EAX + 0x50) != '\0') {
    *(undefined1 *)(in_EAX + 0x50) = 0;
    FUN_004edd00();
  }
  pcVar2 = *(char **)(in_EAX + 0x1fc);
  if ((pcVar2 != (char *)0x0) && (iVar4 = 0, *pcVar2 != '\0')) {
    do {
      iVar3 = iVar4;
      iVar4 = iVar3 + 1;
    } while (pcVar2[iVar3 + 1] != '\0');
    if ((0 < iVar4) && (0 < *(int *)(in_EAX + 0x48))) {
      for (iVar6 = *(int *)(in_EAX + 0x48) + -1; iVar6 < iVar4; iVar6 = iVar6 + 1) {
        puVar1 = (undefined1 *)(iVar6 + *(int *)(in_EAX + 0x1fc));
        *puVar1 = puVar1[1];
      }
      *(undefined1 *)(iVar3 + *(int *)(in_EAX + 0x1fc)) = 0;
      *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x48) + -1;
      FUN_004edad0();
      if (DAT_006f8ae8 != 0x14) {
        uVar5 = 0;
        do {
          if (*(int *)((int)&DAT_006f8a48 + uVar5) == 0x14) break;
          uVar5 = uVar5 + 8;
        } while (uVar5 < 0x70);
      }
      FUN_004cd180(0);
    }
  }
  return;
}


// ==== 0x4ee060 FUN_004ee060

void FUN_004ee060(char param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(in_EAX + 0x50) != '\0') {
    *(undefined1 *)(in_EAX + 0x50) = 0;
    FUN_004edd00();
  }
  pcVar3 = *(char **)(in_EAX + 0x1fc);
  iVar4 = 0;
  if (pcVar3 != (char *)0x0) {
    cVar2 = *pcVar3;
    while (cVar2 != '\0') {
      iVar1 = iVar4 + 1;
      iVar4 = iVar4 + 1;
      cVar2 = pcVar3[iVar1];
    }
  }
  if ((iVar4 < *(int *)(in_EAX + 0x4c)) && (param_1 != '\0')) {
    iVar4 = 0x9a;
    if (*(int *)(in_EAX + 0x48) < 0x9a) {
      do {
        *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + iVar4) =
             *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + -1 + iVar4);
        iVar4 = iVar4 + -1;
      } while (*(int *)(in_EAX + 0x48) < iVar4);
    }
    *(char *)(*(int *)(in_EAX + 0x48) + *(int *)(in_EAX + 0x1fc)) = param_1;
    *(undefined1 *)(*(int *)(in_EAX + 0x1fc) + 0x9b) = 0;
    iVar4 = *(int *)(in_EAX + 0x48) + 1;
    *(int *)(in_EAX + 0x48) = iVar4;
    if (*(int *)(in_EAX + 0x4c) < iVar4) {
      *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x4c);
    }
    FUN_004edad0();
    if (DAT_006f8ae0 != 0x13) {
      uVar5 = 0;
      do {
        if (*(int *)((int)&DAT_006f8a48 + uVar5) == 0x13) break;
        uVar5 = uVar5 + 8;
      } while (uVar5 < 0x70);
    }
    FUN_004cd180(0);
  }
  if ((*(char *)(in_EAX + 0x51) != '\0') && (param_1 != ' ')) {
    FUN_004ee1c0();
  }
  return;
}


// ==== 0x4ee160 FUN_004ee160

void FUN_004ee160(void)

{
  uint uVar1;
  int unaff_ESI;
  
  *(byte *)(unaff_ESI + 0x52) = *(byte *)(unaff_ESI + 0x52) ^ 1;
  *(undefined1 *)(unaff_ESI + 0x51) = 0;
  if (*(int *)(unaff_ESI + 0x20c) == 3) {
    *(undefined1 *)(unaff_ESI + 0x52) = 1;
    *(undefined1 *)(unaff_ESI + 0x51) = 0;
  }
  FUN_004ed930(unaff_ESI);
  if (DAT_006f8ae0 != 0x13) {
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar1) == 0x13) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4ee1c0 FUN_004ee1c0

void FUN_004ee1c0(void)

{
  uint uVar1;
  int unaff_ESI;
  
  *(byte *)(unaff_ESI + 0x51) = *(byte *)(unaff_ESI + 0x51) ^ 1;
  if (*(int *)(unaff_ESI + 0x20c) == 3) {
    *(undefined1 *)(unaff_ESI + 0x51) = 0;
  }
  FUN_004ed930(unaff_ESI);
  if (DAT_006f8ae0 != 0x13) {
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar1) == 0x13) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4ee210 FUN_004ee210

void FUN_004ee210(void)

{
  uint uVar1;
  int unaff_ESI;
  
  *(byte *)(unaff_ESI + 0x53) = *(byte *)(unaff_ESI + 0x53) ^ 1;
  if (*(int *)(unaff_ESI + 0x20c) != 0) {
    *(undefined1 *)(unaff_ESI + 0x53) = 0;
  }
  FUN_004ed930(unaff_ESI);
  if (DAT_006f8ae0 != 0x13) {
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar1) == 0x13) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4ee260 FUN_004ee260

undefined4 FUN_004ee260(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687983;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004ee2c0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ee2c0 FUN_004ee2c0

undefined4 * FUN_004ee2c0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar1 = DAT_0073578c;
  bVar2 = DAT_0073578c != 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c2c6c;
  if (bVar2) {
    cFEng__SetButtonState(iVar1,1);
    if (DAT_0073578c != 0) {
      cFEng__SetCurrentButton(DAT_0073578c);
    }
  }
  FUN_00495f00(0x639);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4ee350 FUN_004ee350

void * __thiscall FUN_004ee350(void *param_1,byte param_2)

{
  FUN_004ee370();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ee370 FUN_004ee370

void __fastcall FUN_004ee370(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2c6c;
  DAT_007357b0 = 0;
  DAT_007359a8 = 0;
  DAT_00735b9c = 0;
  DAT_00735ba0 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x4ee3a0 FUN_004ee3a0

void __fastcall FUN_004ee3a0(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar3 = 0;
  while (DAT_007359a8 != '\0') {
    pcVar4 = &DAT_007359a9 + iVar3;
    iVar3 = iVar3 + 1;
    DAT_007359a8 = *pcVar4;
  }
  DAT_007359a8 = *param_1;
  if (DAT_007359a8 != '\0') {
    pcVar4 = &DAT_007359a8;
    do {
      cVar1 = (param_1 + -0x7359a7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  if (in_EAX == 0) {
    DAT_007357b0 = *param_2;
    if (DAT_007357b0 != '\0') {
      pcVar4 = &DAT_007357b0;
      do {
        cVar1 = (param_2 + -0x7357af)[(int)pcVar4];
        pcVar4 = pcVar4 + 1;
        *pcVar4 = cVar1;
      } while (cVar1 != '\0');
    }
  }
  else {
    pcVar4 = (char *)LanguageStrings__FindByHash();
    if (pcVar4 == (char *)0x0) {
      pcVar4 = (char *)LanguageStrings__FindByHash();
    }
    DAT_007357b0 = *pcVar4;
    if (DAT_007357b0 != '\0') {
      pcVar6 = &DAT_007357b0;
      do {
        cVar1 = (pcVar4 + -0x7357af)[(int)pcVar6];
        pcVar6 = pcVar6 + 1;
        *pcVar6 = cVar1;
      } while (cVar1 != '\0');
    }
  }
  iVar2 = DAT_0073578c;
  DAT_00735b9c = param_3;
  DAT_00735ba0 = param_4;
  if ((iVar3 < 1) && (DAT_0073578c != 0)) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar3 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(iVar3 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar2 + 8),uVar5,0xff);
  }
  return;
}


// ==== 0x4ee490 FUN_004ee490

void FUN_004ee490(void)

{
  int iVar1;
  
  if (((DAT_0073578c != 0) && (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f09b0(*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  return;
}


// ==== 0x4ee4f0 FUN_004ee4f0

void __thiscall FUN_004ee4f0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 == 0xc407210) || (param_2 == -0x6ee54c9c)) {
    if (DAT_00735b9c != 0) {
      FEngQueueMessageToPackage();
    }
    if (DAT_00735ba0 != (code *)0x0) {
      (*DAT_00735ba0)();
    }
    FUN_004ee490(param_1);
  }
  else if (param_2 == -0x367ca946) {
    FEngPrintf(&DAT_007357b0);
    if (DAT_00734dbc != '\0') {
      iVar1 = FEngFindPackage();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        return;
      }
    }
  }
  return;
}


// ==== 0x4ee570 FUN_004ee570

undefined4 * __thiscall FUN_004ee570(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c2c50;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ee590 FUN_004ee590

void __fastcall FUN_004ee590(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 8);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 8) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 0xc) == iVar1) {
      *(int *)(param_2 + 0xc) = in_EAX;
    }
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
  }
  return;
}


// ==== 0x4ee5e0 FUN_004ee5e0

void FUN_004ee5e0(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)0x0;
  if (*(int *)(unaff_ESI + 8) != 0) {
    puVar1 = (undefined4 *)FUN_004ee670();
  }
  while (puVar1 != (undefined4 *)0x0) {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(unaff_ESI + 8);
    if (puVar1 != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_ESI + 8) = puVar1[1];
      if (puVar1 == *(undefined4 **)(unaff_ESI + 0xc)) {
        *(undefined4 *)(unaff_ESI + 0xc) = puVar1[2];
      }
      if (puVar1[2] != 0) {
        *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
      }
      if (puVar1[1] != 0) {
        *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
      }
      puVar1[1] = 0xabadcafe;
      puVar1[2] = 0xabadcafe;
      *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + -1;
    }
  }
  return;
}


// ==== 0x4ee650 FUN_004ee650

void __fastcall FUN_004ee650(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  return;
}


// ==== 0x4ee660 FUN_004ee660

undefined4 FUN_004ee660(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 8);
}


// ==== 0x4ee670 FUN_004ee670

void __fastcall FUN_004ee670(int param_1)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    if (in_EAX == *(int *)(param_1 + 8)) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_EAX + 4);
    }
    if (in_EAX == *(int *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(in_EAX + 8);
    }
    if (*(int *)(in_EAX + 8) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 4) = *(undefined4 *)(in_EAX + 4);
    }
    if (*(int *)(in_EAX + 4) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 4) + 8) = *(undefined4 *)(in_EAX + 8);
    }
    *(undefined4 *)(in_EAX + 4) = 0xabadcafe;
    *(undefined4 *)(in_EAX + 8) = 0xabadcafe;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  }
  return;
}


// ==== 0x4ee6c0 FUN_004ee6c0

void * __thiscall FUN_004ee6c0(void *param_1,byte param_2)

{
  FUN_004ee650();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ee6e0 FUN_004ee6e0

undefined4 * __thiscall FUN_004ee6e0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c2c5c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ee700 FEngine::FEngine

/* [canon] hud med (ghidra-canon+nfsug) docs/re/gameflow.md */

void FEngine__FEngine(void)

{
  int iVar1;
  undefined1 *unaff_ESI;
  undefined4 *puVar2;
  
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined2 *)(unaff_ESI + 0x1a) = 0;
  *(undefined2 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  *(undefined4 *)(unaff_ESI + 0xe4) = 0;
  *(undefined4 *)(unaff_ESI + 0xe8) = 0;
  *(undefined4 *)(unaff_ESI + 0xe0) = 0;
  *(undefined ***)(unaff_ESI + 0xdc) = &PTR_FUN_006c2c48;
  *(undefined ***)(unaff_ESI + 0xec) = &PTR_FUN_006c2c48;
  *(undefined4 *)(unaff_ESI + 0xf4) = 0;
  *(undefined4 *)(unaff_ESI + 0xf8) = 0;
  *(undefined4 *)(unaff_ESI + 0xf0) = 0;
  *(undefined ***)(unaff_ESI + 0xfc) = &PTR_FUN_006c2c48;
  *(undefined4 *)(unaff_ESI + 0x104) = 0;
  *(undefined4 *)(unaff_ESI + 0x108) = 0;
  *(undefined4 *)(unaff_ESI + 0x100) = 0;
  *(undefined4 *)(unaff_ESI + 0x110) = 0;
  *(undefined ***)(unaff_ESI + 0x4114) = &PTR_FUN_006c2c4c;
  *(undefined4 *)(unaff_ESI + 0x411c) = 0;
  *(undefined4 *)(unaff_ESI + 0x4120) = 0;
  *(undefined4 *)(unaff_ESI + 0x4118) = 0;
  *(undefined ***)(unaff_ESI + 0x4124) = &PTR_FUN_006c2c48;
  *(undefined4 *)(unaff_ESI + 0x412c) = 0;
  *(undefined4 *)(unaff_ESI + 0x4130) = 0;
  *(undefined4 *)(unaff_ESI + 0x4128) = 0;
  *(undefined ***)(unaff_ESI + 0x4134) = &PTR_FUN_006c2c48;
  *(undefined4 *)(unaff_ESI + 0x413c) = 0;
  *(undefined4 *)(unaff_ESI + 0x4140) = 0;
  *(undefined4 *)(unaff_ESI + 0x4138) = 0;
  unaff_ESI[0x4144] = 0;
  *unaff_ESI = 1;
  unaff_ESI[1] = 1;
  unaff_ESI[3] = 1;
  unaff_ESI[4] = 1;
  unaff_ESI[0x5250] = 0;
  *(undefined4 *)(unaff_ESI + 0xd4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0xd0) = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[0x5251] = 0;
  puVar2 = (undefined4 *)(unaff_ESI + 0x84);
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(unaff_ESI + 0x4148) = 0;
  puVar2 = (undefined4 *)(unaff_ESI + 0x414c);
  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(unaff_ESI + 0x514c) = 0;
  puVar2 = (undefined4 *)(unaff_ESI + 0x5150);
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_005037e0(unaff_ESI + 0x4134);
  return;
}


// ==== 0x4ee840 FUN_004ee840

void FUN_004ee840(int param_1)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00685952;
  local_c = ExceptionList;
  local_4 = 5;
  ExceptionList = &local_c;
  FUN_004ee910(param_1);
  local_4._0_1_ = 4;
  *(undefined ***)(param_1 + 0x4134) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4._0_1_ = 3;
  *(undefined ***)(param_1 + 0x4124) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4._0_1_ = 2;
  *(undefined ***)(param_1 + 0x4114) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4._0_1_ = 1;
  *(undefined ***)(param_1 + 0xfc) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined ***)(param_1 + 0xec) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = 0xffffffff;
  *(undefined ***)(param_1 + 0xdc) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  ExceptionList = local_c;
  return;
}


// ==== 0x4ee910 FUN_004ee910

void FUN_004ee910(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  do {
    while( true ) {
      puVar3 = *(undefined4 **)(param_1 + 0xe4);
      if (puVar3 == (undefined4 *)0x0) {
        FUN_004ee5e0();
        FUN_004ee5e0();
        FUN_004ee5e0();
        _free(*(void **)(param_1 + 8));
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0xd4) = 0;
        *(undefined1 *)(param_1 + 0x5250) = 0;
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined4 *)(param_1 + 0x2c) = 0;
        *(undefined4 *)(param_1 + 0x4148) = 0;
        puVar3 = (undefined4 *)(param_1 + 0x414c);
        for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined4 *)(param_1 + 0x514c) = 0;
        puVar3 = (undefined4 *)(param_1 + 0x5150);
        for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        FUN_004ee5e0();
        return;
      }
      puVar1 = puVar3;
      if (puVar3 != (undefined4 *)0x0) break;
LAB_004ee989:
      (**(code **)*puVar3)(1);
    }
    do {
      if (puVar1 == puVar3) {
        *(undefined4 *)(param_1 + 0xe4) = puVar3[1];
        if (puVar3 == *(undefined4 **)(param_1 + 0xe8)) {
          *(undefined4 *)(param_1 + 0xe8) = puVar3[2];
        }
        if (puVar3[2] != 0) {
          *(undefined4 *)(puVar3[2] + 4) = puVar3[1];
        }
        if (puVar3[1] != 0) {
          *(undefined4 *)(puVar3[1] + 8) = puVar3[2];
        }
        puVar3[1] = 0xabadcafe;
        puVar3[2] = 0xabadcafe;
        *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
        goto LAB_004ee989;
      }
      puVar1 = (undefined4 *)puVar1[1];
    } while (puVar1 != (undefined4 *)0x0);
    (**(code **)*puVar3)(1);
  } while( true );
}


// ==== 0x4eea10 FEObjectPool_Allocate

/* [canon] hud med (ghidra-canon+nfsug) docs/re/hud.md */

void FEObjectPool_Allocate(int param_1)

{
  void *pvVar1;
  int iVar2;
  byte unaff_BL;
  undefined4 *puVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  _free(*(void **)(param_1 + 8));
  if (unaff_BL != 0) {
    pvVar1 = _malloc((uint)unaff_BL * 0x88);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      CallNTimes(pvVar1,0x88,(uint)unaff_BL,FEJoyPad__FEJoyPad);
    }
    *(void **)(param_1 + 8) = pvVar1;
  }
  *(uint *)(param_1 + 0xd4) = (uint)unaff_BL;
  puVar3 = (undefined4 *)(param_1 + 0x38);
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4eeab0 FUN_004eeab0

void FUN_004eeab0(void)

{
  void **ppvVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  byte bVar6;
  int unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685398;
  iVar5 = *(int *)(unaff_ESI + 0xe4);
  local_4 = 0;
  ppvVar1 = &local_c;
  local_c = ExceptionList;
  while ((ExceptionList = ppvVar1, iVar5 != 0 && (cVar2 = FUN_004ffb00(iVar5), cVar2 != '\0'))) {
    iVar5 = *(int *)(iVar5 + 4);
    ppvVar1 = ExceptionList;
  }
  bVar6 = 0;
  if (*(int *)(unaff_ESI + 0xd4) != 0) {
    uVar3 = 0;
    do {
      puVar4 = (undefined4 *)(uVar3 * 0x88 + *(int *)(unaff_ESI + 8));
      puVar4[1] = 0;
      *puVar4 = 0;
      bVar6 = bVar6 + 1;
      puVar4 = puVar4 + 2;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      uVar3 = (uint)bVar6;
    } while (uVar3 < *(uint *)(unaff_ESI + 0xd4));
  }
  if (*(char *)(unaff_ESI + 2) != '\0') {
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
    *(undefined4 *)(unaff_ESI + 0x10) = 0;
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
    *(undefined2 *)(unaff_ESI + 0x1a) = 0;
    *(undefined2 *)(unaff_ESI + 0x18) = 0;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
    *(undefined1 *)(unaff_ESI + 0x28) = 0;
    *(undefined1 *)(unaff_ESI + 0x29) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4eeb70 FUN_004eeb70

void * __thiscall FUN_004eeb70(void *param_1,byte param_2)

{
  FUN_00500560();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4eeb90 FUN_004eeb90

void __thiscall FUN_004eeb90(int param_1,undefined4 param_2)

{
  FUN_00500d80(param_2,*(undefined4 *)(param_1 + 0x10c),param_1);
  return;
}


// ==== 0x4eebf0 cFEng::PopPackage

/* [canon] hud med (ghidra+hopper) docs/re/gameflow.md */

undefined4 cFEng__PopPackage(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar7 = *(undefined4 **)(param_1 + 0xe4);
  if (puVar7 == (undefined4 *)0x0) {
    return 0;
  }
  while (param_2 != puVar7) {
    puVar7 = (undefined4 *)puVar7[1];
    if (puVar7 == (undefined4 *)0x0) {
      return 0;
    }
  }
  if (*(int **)(param_1 + 0x10c) == (int *)0x0) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = (**(code **)(**(int **)(param_1 + 0x10c) + 0x10))(puVar7);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xe4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_004eec74:
      puVar1 = *(undefined4 **)(param_1 + 0x412c);
      while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)puVar3[1];
        if ((undefined4 *)puVar3[7] == param_2) {
          if (puVar3 == *(undefined4 **)(param_1 + 0x412c)) {
            *(undefined4 **)(param_1 + 0x412c) = puVar1;
          }
          if (puVar3 == *(undefined4 **)(param_1 + 0x4130)) {
            *(undefined4 *)(param_1 + 0x4130) = puVar3[2];
          }
          if (puVar3[2] != 0) {
            *(undefined4 *)(puVar3[2] + 4) = puVar3[1];
          }
          if (puVar3[1] != 0) {
            *(undefined4 *)(puVar3[1] + 8) = puVar3[2];
          }
          puVar3[1] = 0xabadcafe;
          puVar3[2] = 0xabadcafe;
          *(int *)(param_1 + 0x4128) = *(int *)(param_1 + 0x4128) + -1;
          (**(code **)*puVar3)(1);
        }
      }
      if (*(char *)((int)puVar7 + 0x15) != '\0') {
        FUN_004eef40();
        return 1;
      }
      for (iVar2 = puVar7[0x1c]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        iVar5 = UIList__FindNodeByNameHash();
        if (iVar5 != 0) {
          iVar6 = *(int *)(iVar5 + 0x18) + -1;
          if (iVar6 < 1) {
            FUN_004eed80();
          }
          else {
            *(int *)(iVar5 + 0x18) = iVar6;
          }
        }
      }
      if (*(int **)(param_1 + 0x10c) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x10c) + 8))(puVar7,puVar7[0x16],puVar7[0x17]);
      }
      if (cVar4 != '\0') {
        (**(code **)*puVar7)(1);
      }
      return 1;
    }
    if (puVar1 == param_2) {
      FUN_004ee670();
      goto LAB_004eec74;
    }
    puVar1 = (undefined4 *)puVar1[1];
  } while( true );
}


// ==== 0x4eed80 FUN_004eed80

void FUN_004eed80(void)

{
  char cVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x14))();
  if (cVar1 != '\0') {
    UIList__RemoveNode();
    if (*(int **)(unaff_EDI + 0x10c) == (int *)0x0) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x10))();
    }
    if (*(int **)(unaff_EDI + 0x10c) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0x10c) + 8))();
    }
    if ((cVar1 != '\0') && (unaff_ESI != (undefined4 *)0x0)) {
      (**(code **)*unaff_ESI)(1);
    }
  }
  return;
}


// ==== 0x4eede0 cFEng::PushPackage

/* [canon] hud med (ghidra) docs/re/gameflow.md */

int cFEng__PushPackage(undefined1 *param_1,char *param_2,byte param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  void *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcVar2 = param_2;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686c88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar4 = FUN_004fd1e0(param_1 + 0xec);
  if (iVar4 == 0) {
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    cVar3 = (char)pcVar5 - ((char)pcVar2 + '\x01');
    pcVar5 = pcVar2 + cVar3 + -1;
    cVar1 = *pcVar5;
    for (; ((cVar1 != '/' && (cVar1 != '\\')) && ('\0' < cVar3)); cVar3 = cVar3 + -1) {
      cVar1 = pcVar5[-1];
      pcVar5 = pcVar5 + -1;
    }
    iVar4 = FUN_004fd1e0(param_1 + 0xec);
    if (iVar4 == 0) {
      iVar4 = (**(code **)**(undefined4 **)(param_1 + 0x10c))(pcVar2,&local_10,&param_2);
      if (iVar4 == 0) {
        ExceptionList = pvStack_c;
        return 0;
      }
      iVar4 = FUN_004eeb90(iVar4,0);
      if ((char)param_2 != '\0') {
        _free(local_10);
      }
      if (iVar4 == 0) {
        ExceptionList = pvStack_c;
        return 0;
      }
      goto LAB_004eeea5;
    }
  }
  local_4 = 0;
  *(undefined1 *)(iVar4 + 0x15) = 1;
  FUN_004ffb00(iVar4);
  FUN_004ee670();
  local_4 = 0xffffffff;
LAB_004eeea5:
  *(undefined4 *)(iVar4 + 0x1c) = param_4;
  *(uint *)(iVar4 + 0x18) = (uint)param_3;
  *(undefined1 *)(iVar4 + 0x14) = *param_1;
  if (*(int **)(param_1 + 0x10c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x10c) + 0xc))(iVar4);
  }
  FUN_00500640();
  ExceptionList = pvStack_c;
  return iVar4;
}


// ==== 0x4eef40 FUN_004eef40

void __fastcall FUN_004eef40(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(param_2 + 0xf8);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 0xf4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 0xf4) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 0xf8) == iVar1) {
      *(int *)(param_2 + 0xf8) = in_EAX;
    }
    *(int *)(param_2 + 0xf0) = *(int *)(param_2 + 0xf0) + 1;
  }
  return;
}


// ==== 0x4eefa0 UIList::RemoveNode

/* [canon] hud med (ghidra-canon) docs/re/runtime.md */

void __fastcall UIList__RemoveNode(int param_1)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    if (in_EAX == *(int *)(param_1 + 0x104)) {
      *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(in_EAX + 4);
    }
    if (in_EAX == *(int *)(param_1 + 0x108)) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(in_EAX + 8);
    }
    if (*(int *)(in_EAX + 8) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 4) = *(undefined4 *)(in_EAX + 4);
    }
    if (*(int *)(in_EAX + 4) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 4) + 8) = *(undefined4 *)(in_EAX + 8);
    }
    *(undefined4 *)(in_EAX + 4) = 0xabadcafe;
    *(undefined4 *)(in_EAX + 8) = 0xabadcafe;
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + -1;
  }
  return;
}


// ==== 0x4ef000 UIList::FindNodeByNameHash

/* [canon] hud med (ghidra-canon) docs/re/runtime.md */

int UIList__FindNodeByNameHash(void)

{
  byte *pbVar1;
  int iVar2;
  int in_EAX;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  int unaff_EDI;
  
  iVar2 = *(int *)(in_EAX + 0x104);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    pbVar4 = (byte *)(*(int *)(iVar2 + 0x2c) + 2);
    iVar5 = -1;
    if (pbVar4 != (byte *)0x0) {
      bVar3 = *pbVar4;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar5 = iVar5 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar3 = *pbVar1;
      }
    }
    if (iVar5 == unaff_EDI) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  return iVar2;
}


// ==== 0x4ef050 FUN_004ef050

int __fastcall FUN_004ef050(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    for (iVar1 = *(int *)(in_EAX + 0xe4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  else {
    iVar1 = FUN_004fd1e0(in_EAX + 0xdc);
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      return iVar1;
    }
  }
  return 0;
}


// ==== 0x4ef0b0 FUN_004ef0b0

void FUN_004ef0b0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *in_EAX;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  byte bVar7;
  uint uVar8;
  uint *puVar9;
  uint uStack_c;
  int local_8 [2];
  
  if (in_EAX[0x5251] != '\0') {
    (**(code **)(**(int **)(in_EAX + 0x10c) + 0x5c))();
  }
  if (*in_EAX != '\0') {
    if (in_EAX[1] != '\0') {
      in_EAX[0x34] = '\0';
      in_EAX[0x35] = '\0';
      in_EAX[0x36] = '\0';
      in_EAX[0x37] = '\0';
      if (in_EAX[2] != '\0') {
        (**(code **)(**(int **)(in_EAX + 0x10c) + 0x44))(local_8);
        FUN_0051a6d0();
      }
      uStack_c = uStack_c & 0xffffff00;
      if (*(int *)(in_EAX + 0xd4) != 0) {
        bVar7 = 0;
        do {
          (**(code **)(**(int **)(in_EAX + 0x10c) + 0x40))(uStack_c);
          FUN_004fbdf0();
          bVar7 = bVar7 + 1;
          uStack_c = CONCAT31(uStack_c._1_3_,bVar7);
        } while ((uint)bVar7 < *(uint *)(in_EAX + 0xd4));
      }
      for (iVar5 = *(int *)(in_EAX + 0xe4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
        FUN_004ef330(in_EAX,iVar5);
        if (in_EAX[2] != '\0') {
          FUN_004eff20(iVar5);
        }
      }
      uVar8 = 1;
      puVar9 = (uint *)(in_EAX + 0x38);
      local_8[0] = 0x13;
      do {
        if (((*(uint *)(in_EAX + 0x34) & uVar8) != 0) && (bVar7 = 0, *(int *)(in_EAX + 0xd4) != 0))
        {
          uVar4 = 0;
          do {
            uVar1 = *puVar9;
            iVar5 = 0;
            puVar6 = (uint *)(uVar4 * 0x88 + *(int *)(in_EAX + 8) + 8);
            do {
              if ((uVar8 & 1 << ((byte)iVar5 & 0x1f)) != 0) {
                if (uVar1 < *puVar6) {
                  *puVar6 = *puVar6 - uVar1;
                }
                else {
                  *puVar6 = 0;
                }
              }
              iVar5 = iVar5 + 1;
              puVar6 = puVar6 + 1;
            } while (iVar5 < 0x20);
            bVar7 = bVar7 + 1;
            uVar4 = (uint)bVar7;
          } while (uVar4 < *(uint *)(in_EAX + 0xd4));
        }
        *puVar9 = 0;
        uVar8 = uVar8 << 1;
        puVar9 = puVar9 + 1;
        local_8[0] = local_8[0] + -1;
      } while (local_8[0] != 0);
      *(undefined4 *)(in_EAX + 0x2c) = *(undefined4 *)(in_EAX + 0x30);
      local_8[0] = 0;
    }
    if (*in_EAX != '\0') {
      do {
        iVar5 = param_1;
        if (0x14 < param_1) {
          iVar5 = 0x14;
        }
        DAT_006f89ec = (in_EAX[0x5250] != '\0') - 1;
        iVar3 = *(int *)(in_EAX + 0xe4);
        while (iVar3 != 0) {
          iVar2 = *(int *)(iVar3 + 0x40);
          local_8[0] = *(int *)(iVar3 + 4);
          *(char **)(iVar3 + 0x24) = in_EAX;
          *(int *)(iVar3 + 0x28) = iVar5;
          for (; iVar3 = local_8[0], iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
            FUN_004ffeb0(iVar2,iVar5);
          }
        }
        FUN_004f0b00(in_EAX);
        FUN_004f1430();
        if (*(int *)(in_EAX + 0x411c) != 0) {
          FUN_004f0b00(in_EAX);
        }
        param_1 = param_1 - iVar5;
        in_EAX[0x5250] = '\0';
      } while (param_1 != 0);
      goto LAB_004ef30c;
    }
  }
  for (iVar5 = *(int *)(in_EAX + 0xe4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
    iVar3 = *(int *)(iVar5 + 0x40);
    *(char **)(iVar5 + 0x24) = in_EAX;
    *(int *)(iVar5 + 0x28) = param_1;
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      FUN_004ffeb0(iVar3,param_1);
    }
  }
LAB_004ef30c:
  if (in_EAX[0x5251] != '\0') {
    (**(code **)(**(int **)(in_EAX + 0x10c) + 0x60))();
  }
  return;
}


// ==== 0x4ef330 FUN_004ef330

void FUN_004ef330(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  byte local_a1;
  uint local_a0;
  uint local_9c;
  int local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  byte local_88 [4];
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 local_78;
  undefined1 local_76;
  byte local_74 [20];
  byte local_60 [20];
  uint local_4c [4];
  uint local_3c;
  
  if (*(uint *)(param_2 + 0x1c) == 0) {
    return;
  }
  bVar4 = false;
  bVar5 = 0;
  if (*(int *)(param_1 + 0xd4) == 0) {
    return;
  }
  uVar6 = 0;
  do {
    if ((*(uint *)(param_2 + 0x1c) & 1 << ((byte)uVar6 & 0x1f)) != 0) {
      piVar7 = (int *)(uVar6 * 0x88 + *(int *)(param_1 + 8));
      bVar4 = (bool)(bVar4 | (piVar7[1] != 0 || *piVar7 != 0));
    }
    bVar5 = bVar5 + 1;
    uVar6 = (uint)bVar5;
  } while (uVar6 < *(uint *)(param_1 + 0xd4));
  if (!bVar4) {
    return;
  }
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  puVar13 = local_4c;
  for (iVar8 = 0x13; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  local_60[4] = 0;
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_74[0] = 0;
  local_74[1] = 0;
  local_74[2] = 0;
  local_74[3] = 0;
  local_60[8] = 0;
  local_60[9] = 0;
  local_60[10] = 0;
  local_60[0xb] = 0;
  local_84 = 0;
  local_74[4] = 0;
  local_74[5] = 0;
  local_74[6] = 0;
  local_74[7] = 0;
  local_60[0xc] = 0;
  local_60[0xd] = 0;
  local_60[0xe] = 0;
  local_60[0xf] = 0;
  local_80 = 0;
  local_74[8] = 0;
  local_74[9] = 0;
  local_74[10] = 0;
  local_74[0xb] = 0;
  local_60[0x10] = 0;
  local_60[0x11] = 0;
  local_7c = 0;
  local_74[0xc] = 0;
  local_74[0xd] = 0;
  local_74[0xe] = 0;
  local_74[0xf] = 0;
  local_60[0x12] = 0;
  local_78 = 0;
  local_74[0x10] = 0;
  local_74[0x11] = 0;
  local_76 = 0;
  local_74[0x12] = 0;
  local_9c = 4;
  do {
    if (*(char *)(param_1 + 1) == '\0') break;
    uVar9 = 0;
    uVar11 = 1 << ((byte)local_9c & 0x1f);
    uVar6 = *(uint *)(param_2 + 0x1c);
    local_a0 = 0;
    local_94 = 0;
    local_8c = 0;
    local_a1 = 0;
    if (*(int *)(param_1 + 0xd4) != 0) {
      do {
        bVar5 = (byte)uVar9;
        if ((uVar6 & 1 << (bVar5 & 0x1f)) != 0) {
          puVar13 = (uint *)(uVar9 * 0x88 + *(int *)(param_1 + 8));
          if (((puVar13[1] & uVar11) == uVar11) && ((*puVar13 & uVar11) != uVar11)) {
            local_8c = local_8c | uVar11;
            local_88[local_9c] = local_88[local_9c] | '\x01' << (bVar5 & 0x1f);
          }
          if (((puVar13[1] & uVar11) != uVar11) && ((*puVar13 & uVar11) == uVar11)) {
            local_94 = local_94 | uVar11;
            local_74[local_9c] = local_74[local_9c] | '\x01' << (bVar5 & 0x1f);
          }
          if (((puVar13[1] & uVar11) == uVar11) && ((uVar11 & *puVar13) == uVar11)) {
            local_a0 = local_a0 | uVar11;
            uVar9 = FUN_004fbe30();
            if (uVar9 < local_4c[local_9c]) {
              uVar9 = local_4c[local_9c];
            }
            else {
              uVar9 = FUN_004fbe30();
            }
            local_4c[local_9c] = uVar9;
            local_60[local_9c] = local_60[local_9c] | '\x01' << (bVar5 & 0x1f);
          }
        }
        local_a1 = local_a1 + 1;
        uVar9 = (uint)local_a1;
      } while (uVar9 < *(uint *)(param_1 + 0xd4));
    }
    if (((local_9c == 4) && (*(char *)(param_2 + 0x17) != '\0')) &&
       (local_a1 = 0, *(int *)(param_1 + 0xd4) != 0)) {
      local_90 = 0;
      do {
        bVar5 = (byte)local_90;
        if ((uVar6 & 1 << (bVar5 & 0x1f)) != 0) {
          pbVar1 = (byte *)(local_90 * 0x88 + *(int *)(param_1 + 8));
          if ((pbVar1[4] & 0x40) == 0) {
LAB_004ef5a9:
            if ((*pbVar1 & 0x40) != 0) {
              local_94 = local_94 | 0x10;
              local_74[4] = local_74[4] | '\x01' << (bVar5 & 0x1f);
            }
            if ((pbVar1[4] & 0x40) == 0) goto LAB_004ef609;
          }
          else {
            if ((*pbVar1 & 0x40) == 0) {
              local_8c = local_8c | 0x10;
              local_84 = CONCAT31(local_84._1_3_,(byte)local_84 | '\x01' << (bVar5 & 0x1f));
            }
            if ((pbVar1[4] & 0x40) == 0) goto LAB_004ef5a9;
          }
          if ((*pbVar1 & 0x40) != 0) {
            local_a0 = local_a0 | 0x10;
            uVar9 = FUN_004fbe30();
            if (local_3c <= uVar9) {
              local_3c = FUN_004fbe30();
            }
            local_60[4] = local_60[4] | '\x01' << (bVar5 & 0x1f);
          }
        }
LAB_004ef609:
        local_a1 = local_a1 + 1;
        local_90 = (uint)local_a1;
      } while (local_90 < *(uint *)(param_1 + 0xd4));
    }
    if ((local_a0 != 0 || local_94 != 0) || local_8c != 0) {
      iVar8 = *(int *)(param_2 + 0x80);
      switch(local_9c) {
      case 4:
        if ((local_8c & 0x10) != 0) {
          *(int *)(param_1 + 0x84 + local_9c * 4) = iVar8;
          if (iVar8 != 0) {
            for (iVar12 = *(int *)(iVar8 + 0x3c); iVar12 != 0; iVar12 = *(int *)(iVar12 + 4)) {
              if (*(int *)(iVar12 + 0xc) == 0xc407210) {
                FUN_004f0700(0xc407210,0,param_2,*(undefined4 *)(param_2 + 0x80),local_84 & 0xff);
                uVar6 = local_84 & 0xff;
                iVar14 = *(int *)(param_2 + 0x80);
                iVar12 = 0xc407210;
                goto LAB_004ef8d4;
              }
            }
          }
          iVar12 = *(int *)(param_2 + 0x50);
          if (iVar12 != 0) {
LAB_004ef6b3:
            if (*(int *)(iVar12 + 0xc) != 0x406415e3) goto code_r0x004ef6b8;
            FUN_004f0700(0x406415e3,0,param_2,0xfffffffd,local_84 & 0xff);
            uVar6 = local_84 & 0xff;
            iVar14 = 0;
            iVar12 = 0x406415e3;
LAB_004ef8d4:
            FUN_004f0700(iVar12,iVar14,param_2,0xfffffffb,uVar6);
            break;
          }
        }
        break;
      case 7:
      case 8:
        if ((local_a0 & uVar11) != 0) {
          bVar5 = local_88[local_9c];
          iVar12 = *(int *)(local_9c * 4 + 0x6fa030);
          if (iVar8 != 0) {
            for (iVar14 = *(int *)(iVar8 + 0x3c); iVar14 != 0; iVar14 = *(int *)(iVar14 + 4)) {
              if (*(int *)(iVar14 + 0xc) == iVar12) {
                FUN_004f0700(iVar12,0,param_2,iVar8,bVar5);
                iVar14 = iVar8;
                goto LAB_004ef804;
              }
            }
          }
          iVar14 = *(int *)(param_2 + 0x50);
          if (iVar14 != 0) {
LAB_004ef790:
            if (*(int *)(iVar14 + 0xc) != iVar12) goto code_r0x004ef795;
            FUN_004f0700(iVar12,0,param_2,0xfffffffd,bVar5);
            iVar14 = 0;
LAB_004ef804:
            FUN_004f0700(iVar12,iVar14,param_2,0xfffffffb,bVar5);
          }
        }
      case 5:
      case 6:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
switchD_004ef65e_caseD_5:
        if ((local_8c & uVar11) != 0) {
          uVar6 = (uint)local_88[local_9c];
          *(int *)(param_1 + 0x84 + local_9c * 4) = iVar8;
          iVar12 = *(int *)(local_9c * 4 + 0x6fa000);
          if (iVar8 != 0) {
            for (iVar14 = *(int *)(iVar8 + 0x3c); iVar14 != 0; iVar14 = *(int *)(iVar14 + 4)) {
              if (*(int *)(iVar14 + 0xc) == iVar12) {
                FUN_004f0700(iVar12,0,param_2,iVar8,uVar6);
                iVar14 = iVar8;
                goto LAB_004ef8d4;
              }
            }
          }
          for (iVar14 = *(int *)(param_2 + 0x50); iVar14 != 0; iVar14 = *(int *)(iVar14 + 4)) {
            if (*(int *)(iVar14 + 0xc) == iVar12) {
              FUN_004f0700(iVar12,0,param_2,0xfffffffd,uVar6);
              iVar14 = 0;
              goto LAB_004ef8d4;
            }
          }
        }
      }
switchD_004ef65e_default:
      if ((local_94 & uVar11) != 0) {
        bVar5 = local_74[local_9c];
        iVar12 = *(int *)(local_9c * 4 + 0x6fa058);
        if ((*(int *)(param_1 + 0x84 + local_9c * 4) == iVar8) && (iVar8 != 0)) {
          *(undefined4 *)(param_1 + 0x84 + local_9c * 4) = 0;
          if (local_9c == 4) {
            iVar12 = -0x6c959581;
          }
          for (iVar14 = *(int *)(iVar8 + 0x3c); iVar14 != 0; iVar14 = *(int *)(iVar14 + 4)) {
            if (*(int *)(iVar14 + 0xc) == iVar12) {
              FUN_004f0700(iVar12,0,param_2,iVar8,bVar5);
              FUN_004f0700(iVar12,iVar8,param_2,0xfffffffb,bVar5);
              break;
            }
          }
        }
        for (iVar8 = *(int *)(param_2 + 0x50); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
          if (*(int *)(iVar8 + 0xc) == iVar12) {
            FUN_004f0700(iVar12,0,param_2,0xfffffffd,bVar5);
            FUN_004f0700(iVar12,0,param_2,0xfffffffb,bVar5);
            break;
          }
        }
      }
      if (*(int *)(param_1 + 0x4118) != 0) {
        FUN_004f0b00(param_1);
      }
    }
    local_9c = local_9c + 1;
  } while (local_9c < 0x13);
  uVar6 = *(uint *)(param_2 + 0x1c);
  local_8c = 0;
  local_9c = 0;
  do {
    if (*(char *)(param_1 + 1) == '\0') break;
    uVar9 = 1 << ((byte)local_9c & 0x1f);
    local_a1 = 0;
    if (*(int *)(param_1 + 0xd4) != 0) {
      uVar11 = 0;
      do {
        bVar5 = (byte)uVar11;
        if ((uVar6 & 1 << (bVar5 & 0x1f)) != 0) {
          puVar13 = (uint *)(uVar11 * 0x88 + *(int *)(param_1 + 8));
          if (((puVar13[1] & uVar9) == uVar9) && ((*puVar13 & uVar9) != uVar9)) {
            local_8c = local_8c | uVar9;
            local_88[local_9c] = local_88[local_9c] | '\x01' << (bVar5 & 0x1f);
          }
          if (((puVar13[1] & uVar9) == uVar9) && ((*puVar13 & uVar9) == uVar9)) {
            uVar11 = FUN_004fbe30();
            if (uVar11 < local_4c[local_9c]) {
              uVar11 = local_4c[local_9c];
            }
            else {
              uVar11 = FUN_004fbe30();
            }
            local_4c[local_9c] = uVar11;
            local_60[local_9c] = local_60[local_9c] | '\x01' << (bVar5 & 0x1f);
          }
        }
        local_a1 = local_a1 + 1;
        uVar11 = (uint)local_a1;
      } while (uVar11 < *(uint *)(param_1 + 0xd4));
    }
    local_9c = local_9c + 1;
  } while (local_9c < 4);
  uVar6 = 0;
  while( true ) {
    if (*(char *)(param_1 + 1) == '\0') {
      return;
    }
    iVar8 = *(int *)(param_2 + 0x80);
    bVar5 = (&DAT_006f9fe1)[uVar6 * 4];
    if (bVar5 == 0xff) {
      bVar5 = (&DAT_006f9fe0)[uVar6 * 4];
      local_94 = local_4c[bVar5];
      bVar3 = local_88[bVar5];
      bVar2 = local_60[bVar5];
      uVar9 = local_8c >> (bVar5 & 0x1f);
    }
    else {
      bVar2 = (&DAT_006f9fe0)[uVar6 * 4];
      local_94 = local_4c[bVar2];
      if (local_4c[bVar5] <= local_4c[bVar2]) {
        local_94 = local_4c[bVar5];
      }
      uVar9 = local_8c >> (bVar2 & 0x1f) & local_8c >> (bVar5 & 0x1f);
      bVar3 = local_88[bVar5] & local_88[bVar2];
      bVar2 = local_60[bVar5] & local_60[bVar2];
    }
    bVar3 = bVar3 | bVar2;
    uVar10 = 1 << ((byte)uVar6 & 0x1f);
    uVar11 = (-(uint)((*(uint *)(param_1 + 0x2c) & uVar10) != 0) & 0xffffff38) + 0x140;
    if (uVar11 <= local_94) break;
    if ((uVar9 & 1) == 0) {
      if (local_94 == 0) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & ~uVar10;
      }
    }
    else if (local_94 == 0) goto LAB_004efbd0;
    if (*(int *)(param_1 + 0x4118) != 0) {
      FUN_004f0b00(param_1);
    }
    uVar6 = uVar6 + 1;
    if (7 < uVar6) {
      return;
    }
  }
  if (local_94 != 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1 << ((byte)uVar6 & 0x1f);
  }
LAB_004efbd0:
  *(uint *)(param_1 + 0x38 + (uint)(byte)(&DAT_006f9fe0)[uVar6 * 4] * 4) = uVar11;
  if ((&DAT_006f9fe1)[uVar6 * 4] != 0xff) {
    *(uint *)(param_1 + 0x38 + (uint)(byte)(&DAT_006f9fe1)[uVar6 * 4] * 4) = uVar11;
  }
  bVar5 = (&DAT_006f9fe0)[uVar6 * 4];
  bVar2 = (&DAT_006f9fe1)[uVar6 * 4];
  local_4c[bVar5] = 0;
  if (bVar2 == 0xff) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1 << (bVar5 & 0x1f);
  }
  else {
    local_4c[bVar2] = 0;
    *(uint *)(param_1 + 0x34) =
         *(uint *)(param_1 + 0x34) | 1 << (bVar5 & 0x1f) | 1 << (bVar2 & 0x1f);
  }
  if (iVar8 == 0) {
    iVar8 = *(int *)((uint)*(ushort *)(uVar6 * 4 + 0x6f9fe2) * 4 + 0x6f8a10);
    iVar12 = *(int *)(param_2 + 0x50);
    if (iVar12 == 0) {
      return;
    }
    do {
      if (*(int *)(iVar12 + 0xc) == iVar8) {
        FUN_004f0700(iVar8,0,param_2,0xfffffffd,bVar3);
        FUN_004f0700(iVar8,0,param_2,0xfffffffb,bVar3);
        return;
      }
      iVar12 = *(int *)(iVar12 + 4);
    } while (iVar12 != 0);
    return;
  }
  uVar9 = (uint)*(ushort *)(uVar6 * 4 + 0x6f9fe2);
  iVar12 = *(int *)(iVar8 + 0x3c);
  iVar14 = *(int *)(uVar9 * 4 + 0x6f8a10);
  local_98 = 0;
  for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 4)) {
    if (*(int *)(iVar12 + 0xc) == iVar14) {
      if (iVar12 != 0) {
        FUN_004f0700(iVar14,0,param_2,iVar8,bVar3);
        if ((*(uint *)(iVar8 + 0x1c) & 0x80000) != 0) goto LAB_004efccb;
        uVar9 = 0;
        if (*(uint *)(iVar12 + 0x10) == 0) goto LAB_004efdbb;
        piVar7 = *(int **)(iVar12 + 0x14);
        goto LAB_004efda0;
      }
      break;
    }
  }
  if ((*(uint *)(iVar8 + 0x1c) & 0x80000) == 0) {
    local_98 = FUN_004fa140(param_2 + 0x84,iVar8,uVar9,*(undefined4 *)(param_1 + 0x10c),
                            *(undefined4 *)(param_1 + 0xd0));
  }
  FUN_004f0700(iVar14,0,param_2,0xfffffffd,bVar3);
  goto LAB_004efccb;
code_r0x004ef795:
  iVar14 = *(int *)(iVar14 + 4);
  if (iVar14 == 0) goto switchD_004ef65e_caseD_5;
  goto LAB_004ef790;
code_r0x004ef6b8:
  iVar12 = *(int *)(iVar12 + 4);
  if (iVar12 == 0) goto switchD_004ef65e_default;
  goto LAB_004ef6b3;
  while( true ) {
    uVar9 = uVar9 + 1;
    piVar7 = piVar7 + 3;
    if (*(uint *)(iVar12 + 0x10) <= uVar9) break;
LAB_004efda0:
    if (*piVar7 == 0x104) {
      if (uVar9 != 0xffffffff) goto LAB_004efccb;
      break;
    }
  }
LAB_004efdbb:
  local_98 = FUN_004fa140(param_2 + 0x84,iVar8,*(undefined2 *)(uVar6 * 4 + 0x6f9fe2),
                          *(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0xd0));
LAB_004efccb:
  FUN_004f0700(iVar14,iVar8,param_2,0xfffffffb,bVar3);
  if (local_98 == 0) {
    return;
  }
  local_9c = 4;
  do {
    if (*(int *)(param_1 + 0x84 + local_9c * 4) != 0) {
      *(undefined4 *)(param_1 + 0x84 + local_9c * 4) = 0;
      iVar12 = *(int *)(local_9c * 4 + 0x6fa058);
      if (local_9c == 4) {
        iVar12 = -0x6c959581;
      }
      for (iVar14 = *(int *)(iVar8 + 0x3c); iVar14 != 0; iVar14 = *(int *)(iVar14 + 4)) {
        if (*(int *)(iVar14 + 0xc) == iVar12) {
          FUN_004f0700(iVar12,0,param_2,iVar8,local_74[local_9c]);
          FUN_004f0700(iVar12,iVar8,param_2,0xfffffffb,local_74[local_9c]);
          break;
        }
      }
    }
    local_9c = local_9c + 1;
    if (0x12 < local_9c) {
      if (*(int *)(param_2 + 0x80) != 0) {
        FUN_004f0700(0x55d1e635,0,param_2,*(int *)(param_2 + 0x80),0);
        FUN_004f0700(0x55d1e635,*(undefined4 *)(param_2 + 0x80),param_2,0xfffffffb,0);
      }
      FUN_004f0700(0xabc08912,0,param_2,local_98,0);
      FUN_004f0700(0xabc08912,local_98,param_2,0xfffffffb,0);
      *(int *)(param_2 + 0x80) = local_98;
      return;
    }
  } while( true );
}


// ==== 0x4eff20 FUN_004eff20

void FUN_004eff20(uint param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  uint uVar10;
  undefined4 unaff_EBP;
  int unaff_ESI;
  undefined4 uVar11;
  ushort local_10;
  ushort local_c;
  uint auStack_8 [2];
  
  iVar6 = param_1;
  if (((*(byte *)(param_1 + 0x1c) & 1) != 0) && (*(char *)(unaff_ESI + 1) != '\0')) {
    fVar3 = (float)*(int *)(unaff_ESI + 0xc);
    param_1 = 0;
    fVar4 = (float)*(int *)(unaff_ESI + 0x10);
    do {
      if (*(char *)(unaff_ESI + 1) == '\0') break;
      local_c = 0;
      local_10 = 0;
      uVar5 = (ushort)(1 << ((byte)param_1 & 0x1f));
      if (((*(ushort *)(unaff_ESI + 0x1a) & uVar5) == uVar5) &&
         ((*(ushort *)(unaff_ESI + 0x18) & uVar5) != uVar5)) {
        local_10 = uVar5;
      }
      if (((*(ushort *)(unaff_ESI + 0x1a) & uVar5) != uVar5) &&
         ((*(ushort *)(unaff_ESI + 0x18) & uVar5) == uVar5)) {
        local_c = uVar5;
      }
      if (((*(ushort *)(unaff_ESI + 0x1a) & uVar5) == uVar5) &&
         ((*(ushort *)(unaff_ESI + 0x18) & uVar5) == uVar5)) {
        uVar8 = FUN_0051a750();
        auStack_8[param_1] = uVar8;
      }
      iVar1 = *(int *)(iVar6 + 0x80);
      if ((local_10 & uVar5) != 0) {
        if (param_1 == 0) {
          *(int *)(unaff_ESI + 0x94) = iVar1;
          if (iVar1 != 0) {
            for (iVar9 = *(int *)(iVar1 + 0x3c); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
              if (*(int *)(iVar9 + 0xc) == 0xc407210) {
                cVar7 = (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x48))(fVar3,fVar4,iVar1);
                if (cVar7 == '\x01') {
                  FUN_004f0700(0xc407210,0,iVar6,*(undefined4 *)(iVar6 + 0x80),1);
                  iVar9 = *(int *)(iVar6 + 0x80);
                  uVar11 = 0xc407210;
                  goto LAB_004f0146;
                }
                break;
              }
            }
          }
          for (iVar9 = *(int *)(iVar6 + 0x50); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
            if (*(int *)(iVar9 + 0xc) == 0x406415e3) {
              FUN_004f0700(0x406415e3,0,iVar6,0xfffffffd,1);
              iVar9 = 0;
              uVar11 = 0x406415e3;
              goto LAB_004f0146;
            }
          }
        }
        else if (param_1 == 1) {
          if (iVar1 != 0) {
            for (iVar9 = *(int *)(iVar1 + 0x3c); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
              if (*(int *)(iVar9 + 0xc) == 0x14dd0705) {
                cVar7 = (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x48))(fVar3,fVar4,iVar1);
                if (cVar7 == '\x01') {
                  FUN_004f0700(0x14dd0705,0,iVar6,iVar1,1);
                  uVar11 = 0x14dd0705;
                  iVar9 = iVar1;
                  goto LAB_004f0146;
                }
                break;
              }
            }
          }
          iVar9 = *(int *)(iVar6 + 0x50);
          if (iVar9 != 0) {
LAB_004f0033:
            if (*(int *)(iVar9 + 0xc) != 0x14dd0705) goto code_r0x004f0038;
            FUN_004f0700(0x14dd0705,0,iVar6,0xfffffffd,1);
            uVar11 = 0x14dd0705;
            iVar9 = 0;
LAB_004f0146:
            FUN_004f0700(uVar11,iVar9,iVar6,0xfffffffb,1);
          }
        }
      }
LAB_004f0151:
      if (((local_c & uVar5) != 0) && (param_1 == 0)) {
        if ((*(int *)(unaff_ESI + 0x94) == iVar1) && (iVar1 != 0)) {
          *(undefined4 *)(unaff_ESI + 0x94) = 0;
          iVar9 = FEObject__FindResponse();
          if (iVar9 != 0) {
            FUN_004f0700(extraout_ECX,0,iVar6,iVar1,1);
            FUN_004f0700(0x936a6a7f,iVar1,iVar6,0xfffffffb,1);
          }
        }
        for (iVar1 = *(int *)(iVar6 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
          if (*(int *)(iVar1 + 0xc) == -0x6c959581) {
            FUN_004f0700(0x936a6a7f,0,iVar6,0xfffffffd,1);
            FUN_004f0700(0x936a6a7f,0,iVar6,0xfffffffb,1);
            break;
          }
        }
      }
      if (*(int *)(unaff_ESI + 0x4118) != 0) {
        FUN_004f0b00(unaff_ESI);
      }
      param_1 = param_1 + 1;
    } while (param_1 < 2);
    if (((*(char *)(unaff_ESI + 0x29) != '\0') && (*(int *)(iVar6 + 0x80) != 0)) &&
       (cVar7 = (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x48))
                          (fVar3,fVar4,*(int *)(iVar6 + 0x80)), cVar7 != '\x01')) {
      uVar8 = *(uint *)(iVar6 + 0x88);
      uVar10 = 0;
      auStack_8[0] = uVar8;
      if (uVar8 != 0) {
        while ((iVar1 = *(int *)(*(int *)(iVar6 + 0x84) + uVar10 * 4),
               (*(uint *)(iVar1 + 0x1c) & 0x4000000) != 0 ||
               (cVar7 = (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0x48))
                                  (unaff_EBP,unaff_EBX,iVar1), uVar8 = auStack_8[0], cVar7 == '\0'))
              ) {
          uVar10 = uVar10 + 1;
          if (uVar8 <= uVar10) {
            return;
          }
        }
        auStack_8[0] = 4;
        do {
          if (*(int *)(unaff_ESI + 0x84 + auStack_8[0] * 4) != 0) {
            *(undefined4 *)(unaff_ESI + 0x84 + auStack_8[0] * 4) = 0;
            iVar9 = *(int *)(auStack_8[0] * 4 + 0x6fa058);
            if (auStack_8[0] == 4) {
              iVar9 = -0x6c959581;
            }
            for (iVar2 = *(int *)((int)fVar4 + 0x3c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
              if (*(int *)(iVar2 + 0xc) == iVar9) {
                FUN_004f0700(iVar9,0,iVar6,fVar4,1);
                FUN_004f0700(iVar9,fVar4,iVar6,0xfffffffb,1);
                break;
              }
            }
          }
          auStack_8[0] = auStack_8[0] + 1;
        } while (auStack_8[0] < 0x13);
        if (*(int *)(iVar6 + 0x80) != 0) {
          FUN_004f0700(0x55d1e635,0,iVar6,*(int *)(iVar6 + 0x80),0);
          FUN_004f0700(0x55d1e635,*(undefined4 *)(iVar6 + 0x80),iVar6,0xfffffffb,0);
        }
        FUN_004f0700(0xabc08912,0,iVar6,iVar1,0);
        FUN_004f0700(0xabc08912,iVar1,iVar6,0xfffffffb,0);
        *(int *)(iVar6 + 0x80) = iVar1;
      }
    }
  }
  return;
code_r0x004f0038:
  iVar9 = *(int *)(iVar9 + 4);
  if (iVar9 == 0) goto LAB_004f0151;
  goto LAB_004f0033;
}


// ==== 0x4f0390 FUN_004f0390

void FUN_004f0390(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *in_EAX;
  int iVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  local_48 = 0;
  local_44 = 0x3f800000;
  (**(code **)(**(int **)(in_EAX + 0x10c) + 0x3c))(local_40);
  iVar3 = *(int *)(in_EAX + 0xe4);
  if (iVar3 == 0) {
    in_EAX[0x5250] = *in_EAX;
    return;
  }
  puVar1 = (undefined4 *)(in_EAX + 0x110);
  do {
    *(undefined2 *)(in_EAX + 0xd8) = 0;
    (**(code **)(**(int **)(in_EAX + 0x10c) + 0x20))(iVar3);
    *puVar1 = 0;
    for (iVar2 = *(int *)(iVar3 + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if (*(int *)(iVar2 + 0x18) == 5) {
        FUN_004f04e0(iVar2,&stack0xffffff78,&local_48,0);
      }
      else {
        FEObjectSorter__AddObject(0);
      }
    }
    FUN_004f16d0(puVar1);
    (**(code **)(**(int **)(in_EAX + 0x10c) + 0x30))(in_EAX + 0x114,*puVar1);
    (**(code **)(**(int **)(in_EAX + 0x10c) + 0x24))(iVar3);
    iVar3 = *(int *)(iVar3 + 4);
  } while (iVar3 != 0);
  in_EAX[0x5250] = *in_EAX;
  return;
}


// ==== 0x4f04e0 FUN_004f04e0

void __thiscall
FUN_004f04e0(char *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  float local_48 [18];
  
  iVar2 = *(int *)(param_2 + 0x2c);
  if ((*(int *)(iVar2 + 0xc) != 0) && ((*param_1 != '\0' || (-1 < *(int *)(param_2 + 0x1c))))) {
    FUN_004fde50();
    Mat4_TransformPoint();
    local_48[0] = *(float *)(iVar2 + 0x24) + *(float *)(iVar2 + 0x18) + 0.0;
    FUN_004fdf40();
    FUN_004fdf40();
    *(short *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) + 1;
    uVar1 = *(undefined2 *)(param_1 + 0xd8);
    *(undefined2 *)(param_2 + 0x20) = param_5;
    (**(code **)(**(int **)(param_1 + 0x10c) + 0x28))(uVar1,param_2);
    for (iVar2 = *(int *)(param_2 + 0x60); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if (*(int *)(iVar2 + 0x18) == 5) {
        FUN_004f04e0(iVar2,local_48,param_2,uVar1);
      }
      else {
        FEObjectSorter__AddObject(uVar1);
      }
    }
  }
  return;
}


// ==== 0x4f0660 FEObjectSorter::AddObject

/* [canon] hud med (ghidra-canon) docs/re/runtime.md */

void __fastcall FEObjectSorter__AddObject(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  float fVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(param_2 + 0x2c);
  if (*(int *)(iVar1 + 0xc) != 0) {
    fVar2 = (*(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x1c)) * *(float *)(param_1 + 8) +
            (*(float *)(iVar1 + 0x14) + *(float *)(iVar1 + 0x20)) * *(float *)(param_1 + 0x18) +
            (*(float *)(iVar1 + 0x18) + *(float *)(iVar1 + 0x24)) * *(float *)(param_1 + 0x28) +
            *(float *)(param_1 + 0x38);
    *(undefined2 *)(param_2 + 0x20) = param_3;
    if (fVar2 < 0.0 == (fVar2 == 0.0)) {
      *(int *)(unaff_ESI + 0x114 + *(int *)(unaff_ESI + 0x110) * 8) = param_2;
      *(float *)(unaff_ESI + 0x118 + *(int *)(unaff_ESI + 0x110) * 8) = fVar2;
      *(int *)(unaff_ESI + 0x110) = *(int *)(unaff_ESI + 0x110) + 1;
      return;
    }
  }
  return;
}


// ==== 0x4f0700 FUN_004f0700

void FUN_004f0700(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar3 = _malloc(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0xabadcafe;
    puVar3[2] = 0xabadcafe;
    *puVar3 = &PTR_FUN_006c2c68;
  }
  puVar3[6] = param_1;
  puVar3[3] = param_2;
  puVar3[5] = param_3;
  puVar3[4] = param_4;
  puVar3[7] = param_5;
  if (*(char *)(unaff_EDI + 0x5251) != '\0') {
    (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x54))(param_1,param_2,param_3,param_4,param_5);
  }
  iVar1 = *(int *)(unaff_EDI + 0x4120);
  if (iVar1 == 0) {
    iVar2 = *(int *)(unaff_EDI + 0x411c);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = 0;
    *(undefined4 **)(unaff_EDI + 0x411c) = puVar3;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = puVar3;
  }
  if (*(int *)(unaff_EDI + 0x4120) == iVar1) {
    *(undefined4 **)(unaff_EDI + 0x4120) = puVar3;
  }
  *(int *)(unaff_EDI + 0x4118) = *(int *)(unaff_EDI + 0x4118) + 1;
  return;
}


// ==== 0x4f07d0 FUN_004f07d0

void * __thiscall FUN_004f07d0(void *param_1,byte param_2)

{
  FUN_004f07f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f07f0 FUN_004f07f0

void FUN_004f07f0(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x4f0800 FUN_004f0800

void FUN_004f0800(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = _malloc(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0xabadcafe;
    puVar3[2] = 0xabadcafe;
    puVar3[3] = 0;
    puVar3[4] = 0;
    *puVar3 = &PTR_FUN_006c2c64;
  }
  puVar3[7] = param_2;
  puVar3[6] = *(undefined4 *)(param_2 + 0x1c);
  puVar3[5] = 3;
  FENode__SetName();
  iVar1 = *(int *)(param_1 + 0x4130);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x412c);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = 0;
    *(undefined4 **)(param_1 + 0x412c) = puVar3;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = puVar3;
  }
  if (*(int *)(param_1 + 0x4130) == iVar1) {
    *(undefined4 **)(param_1 + 0x4130) = puVar3;
  }
  *(int *)(param_1 + 0x4128) = *(int *)(param_1 + 0x4128) + 1;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}


// ==== 0x4f08b0 FUN_004f08b0

void * __thiscall FUN_004f08b0(void *param_1,byte param_2)

{
  FENode__DtorBody();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f08d0 FENode::DtorBody

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FENode__DtorBody(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c1828;
  if ((void *)unaff_ESI[3] != (void *)0x0) {
    _free((void *)unaff_ESI[3]);
  }
  *unaff_ESI = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x4f08f0 UIListNode_Alloc

/* [canon] canon med (hopper+capstone) docs/re/misc.md */

void UIListNode_Alloc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = _malloc(0x20);
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[1] = 0xabadcafe;
    puVar3[2] = 0xabadcafe;
    *puVar3 = &PTR_FUN_006c2c64;
    puVar4 = puVar3;
  }
  puVar4[7] = param_2;
  puVar4[6] = param_3;
  puVar4[5] = 2;
  FENode__SetName();
  iVar1 = *(int *)(param_1 + 0x4130);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x412c);
    puVar4[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar4;
    }
    puVar4[2] = 0;
    *(undefined4 **)(param_1 + 0x412c) = puVar4;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    puVar4[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar4;
    }
    puVar4[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = puVar4;
  }
  if (*(int *)(param_1 + 0x4130) == iVar1) {
    *(undefined4 **)(param_1 + 0x4130) = puVar4;
  }
  *(int *)(param_1 + 0x4128) = *(int *)(param_1 + 0x4128) + 1;
  if (param_2 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) & ~param_3;
  }
  return;
}


// ==== 0x4f09b0 FUN_004f09b0

void FUN_004f09b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  
  puVar3 = _malloc(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0xabadcafe;
    puVar3[2] = 0xabadcafe;
    puVar3[3] = 0;
    puVar3[4] = 0;
    *puVar3 = &PTR_FUN_006c2c64;
  }
  puVar3[7] = param_1;
  puVar3[6] = *(undefined4 *)(param_1 + 0x1c);
  puVar3[5] = 1;
  iVar1 = *(int *)(unaff_ESI + 0x4130);
  if (iVar1 == 0) {
    iVar2 = *(int *)(unaff_ESI + 0x412c);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = 0;
    *(undefined4 **)(unaff_ESI + 0x412c) = puVar3;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = puVar3;
  }
  if (*(int *)(unaff_ESI + 0x4130) == iVar1) {
    *(undefined4 **)(unaff_ESI + 0x4130) = puVar3;
  }
  *(int *)(unaff_ESI + 0x4128) = *(int *)(unaff_ESI + 0x4128) + 1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// ==== 0x4f0a50 FUN_004f0a50

void FUN_004f0a50(char param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar3 = _malloc(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0xabadcafe;
    puVar3[2] = 0xabadcafe;
    puVar3[3] = 0;
    puVar3[4] = 0;
    *puVar3 = &PTR_FUN_006c2c64;
  }
  puVar3[7] = unaff_EDI;
  puVar3[6] = *(uint *)(unaff_EDI + 0x1c) & param_2;
  puVar3[5] = (uint)(param_1 != '\0') * 4 + 4;
  iVar1 = *(int *)(unaff_ESI + 0x4130);
  if (iVar1 == 0) {
    iVar2 = *(int *)(unaff_ESI + 0x412c);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = 0;
    *(undefined4 **)(unaff_ESI + 0x412c) = puVar3;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    puVar3[1] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(iVar2 + 8) = puVar3;
    }
    puVar3[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = puVar3;
  }
  if (*(int *)(unaff_ESI + 0x4130) == iVar1) {
    *(undefined4 **)(unaff_ESI + 0x4130) = puVar3;
  }
  *(int *)(unaff_ESI + 0x4128) = *(int *)(unaff_ESI + 0x4128) + 1;
  return;
}


// ==== 0x4f0b00 FUN_004f0b00

void FUN_004f0b00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0x411c) != 0) {
    puVar2 = (undefined4 *)FUN_004ee670();
  }
joined_r0x004f0b22:
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(param_1 + 0x5251) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x10c) + 0x58))
              (puVar2[6],puVar2[4],puVar2[3],puVar2[5],puVar2[7]);
  }
  uVar3 = puVar2[4];
  if (uVar3 < 0xfffffffd) {
    if (uVar3 == 0xfffffffc) {
      iVar6 = *(int *)(param_1 + 0xe4);
      if (iVar6 != 0) {
        do {
          if (iVar6 == puVar2[5]) {
            if (iVar6 != 0) {
              iVar1 = *(int *)(iVar6 + 0x50);
              goto joined_r0x004f0d3b;
            }
            break;
          }
          iVar6 = *(int *)(iVar6 + 4);
        } while (iVar6 != 0);
      }
    }
    else if (uVar3 == 0) {
      for (iVar6 = *(int *)(param_1 + 0xe4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
        for (iVar1 = *(int *)(iVar6 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
          if (*(int *)(iVar1 + 0xc) == puVar2[6]) {
            if (iVar1 != 0) {
              FUN_004f1040(param_1,iVar1,0,iVar6,puVar2[7]);
            }
            break;
          }
        }
        uVar3 = 0;
        if (*(uint *)(iVar6 + 0x60) != 0) {
          piVar4 = *(int **)(iVar6 + 100);
          do {
            if (*piVar4 == puVar2[6]) {
              piVar4 = *(int **)(iVar6 + 100) + uVar3 * 4;
              if ((piVar4 != (int *)0x0) && (uVar3 = piVar4[2], uVar3 != 0)) {
                uVar5 = 0;
                do {
                  FUN_004f0fd0(param_1,iVar6,puVar2[7]);
                  uVar5 = uVar5 + 1;
                } while (uVar5 < uVar3);
              }
              break;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 4;
          } while (uVar3 < *(uint *)(iVar6 + 0x60));
        }
      }
    }
    else if (uVar3 == 0xfffffffa) {
      if (puVar2[6] == 0x59bed120) {
        *(undefined1 *)(param_1 + 1) = 1;
      }
      else if (puVar2[6] == 0x5d4ce32d) {
        *(undefined1 *)(param_1 + 1) = 0;
      }
    }
    else {
      if (uVar3 != 0xfffffffb) goto LAB_004f0de3;
      (**(code **)(**(int **)(param_1 + 0x10c) + 0x1c))(puVar2[6],puVar2[3],puVar2[7],puVar2[5]);
    }
  }
  else if (uVar3 == 0xfffffffd) {
    for (iVar6 = *(int *)(puVar2[5] + 0x50); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
      if (*(int *)(iVar6 + 0xc) == puVar2[6]) {
        if (iVar6 != 0) {
          FUN_004f1040(param_1,iVar6,0,puVar2[5],puVar2[7]);
        }
        break;
      }
    }
  }
  else if (uVar3 == 0xfffffffe) {
    for (iVar6 = *(int *)(param_1 + 0xe4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
      for (iVar1 = *(int *)(iVar6 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
        if (*(int *)(iVar1 + 0xc) == puVar2[6]) {
          if (iVar1 != 0) {
            FUN_004f1040(param_1,iVar1,0,iVar6,puVar2[7]);
          }
          break;
        }
      }
    }
  }
  else if (uVar3 == 0xffffffff) {
    (**(code **)(**(int **)(param_1 + 0x10c) + 0x18))(puVar2[6],puVar2[3],puVar2[7],puVar2[5]);
  }
  else {
LAB_004f0de3:
    FUN_004f0fd0(param_1,puVar2[5],puVar2[7]);
  }
  goto LAB_004f0c8d;
joined_r0x004f0d3b:
  if (iVar1 == 0) goto LAB_004f0d5d;
  if (*(int *)(iVar1 + 0xc) == puVar2[6]) {
    if (iVar1 != 0) {
      FUN_004f1040(param_1,iVar1,0,iVar6,puVar2[7]);
    }
    goto LAB_004f0d5d;
  }
  iVar1 = *(int *)(iVar1 + 4);
  goto joined_r0x004f0d3b;
LAB_004f0d5d:
  uVar3 = 0;
  if (*(uint *)(iVar6 + 0x60) != 0) {
    piVar4 = *(int **)(iVar6 + 100);
    do {
      if (*piVar4 == puVar2[6]) {
        piVar4 = *(int **)(iVar6 + 100) + uVar3 * 4;
        if (piVar4 != (int *)0x0) {
          uVar3 = piVar4[2];
          uVar5 = 0;
          if (uVar3 != 0) {
            do {
              FUN_004f0fd0(param_1,iVar6,puVar2[7]);
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar3);
          }
        }
        break;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 4;
    } while (uVar3 < *(uint *)(iVar6 + 0x60));
  }
LAB_004f0c8d:
  (**(code **)*puVar2)(1);
  puVar2 = *(undefined4 **)(param_1 + 0x411c);
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x411c) = puVar2[1];
  if (puVar2 == *(undefined4 **)(param_1 + 0x4120)) {
    *(undefined4 *)(param_1 + 0x4120) = puVar2[2];
  }
  if (puVar2[2] != 0) {
    *(undefined4 *)(puVar2[2] + 4) = puVar2[1];
  }
  if (puVar2[1] != 0) {
    *(undefined4 *)(puVar2[1] + 8) = puVar2[2];
  }
  puVar2[1] = 0xabadcafe;
  puVar2[2] = 0xabadcafe;
  *(int *)(param_1 + 0x4118) = *(int *)(param_1 + 0x4118) + -1;
  goto joined_r0x004f0b22;
}


// ==== 0x4f0eb0 FUN_004f0eb0

undefined4 FUN_004f0eb0(void)

{
  uint in_EAX;
  
  if (in_EAX < 0xe10c4afa) {
    if (in_EAX == 0xe10c4af9) {
      FUN_004fd880(0);
      return 1;
    }
    if (in_EAX == 0x30471ac) {
      FUN_004fd880(0);
      return 1;
    }
    if (in_EAX == 0xe10814a6) {
      FUN_004fd880(1);
      return 1;
    }
  }
  else if (in_EAX == 0xfb814f13) {
    FUN_004fd880(0xffffffff);
    return 1;
  }
  return 0;
}


// ==== 0x4f0f10 FUN_004f0f10

undefined4 __fastcall FUN_004f0f10(int param_1)

{
  uint in_EAX;
  
  if (in_EAX < 0xe10c4afa) {
    if (in_EAX == 0xe10c4af9) {
      FUN_004fb210(param_1,param_1 + 0x70,param_1 + 0x78,*(undefined4 *)(param_1 + 0x68),
                   *(undefined4 *)(param_1 + 0x5c),1);
      FUN_004fb210(param_1,param_1 + 0x74,param_1 + 0x7c,*(undefined4 *)(param_1 + 0x6c),
                   *(undefined4 *)(param_1 + 0x60),0);
      return 1;
    }
    if (in_EAX == 0x30471ac) {
      FUN_004faf30(1,0);
      return 1;
    }
    if (in_EAX == 0xe10814a6) {
      FUN_004faf30(0,1);
      return 1;
    }
  }
  else if (in_EAX == 0xfb814f13) {
    FUN_004fb210(param_1,param_1 + 0x70,param_1 + 0x78,*(undefined4 *)(param_1 + 0x68),
                 *(undefined4 *)(param_1 + 0x5c),1);
    FUN_004fb210(param_1,param_1 + 0x74,param_1 + 0x7c,*(undefined4 *)(param_1 + 0x6c),
                 *(undefined4 *)(param_1 + 0x60),0);
    return 1;
  }
  return 0;
}


// ==== 0x4f0fd0 FUN_004f0fd0

void FUN_004f0fd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((((*(int *)(unaff_ESI + 0x18) != 4) || (cVar1 = FUN_004f0eb0(param_1,param_2), cVar1 == '\0'))
      && ((*(int *)(unaff_ESI + 0x18) != 6 || (cVar1 = FUN_004f0f10(param_1,param_2), cVar1 == '\0')
          ))) && (iVar2 = *(int *)(unaff_ESI + 0x3c), iVar2 != 0)) {
    while (*(int *)(iVar2 + 0xc) != unaff_EDI) {
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        return;
      }
    }
    if (iVar2 != 0) {
      FUN_004f1040(param_1,iVar2,unaff_ESI,param_2,param_3);
    }
  }
  return;
}


