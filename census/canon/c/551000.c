// ==== 0x551180 FUN_00551180

void * __thiscall FUN_00551180(void *param_1,byte param_2)

{
  FUN_005511a0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5511a0 FUN_005511a0

void FUN_005511a0(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bce70;
  pvVar2 = (void *)param_1[0x1e8];
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00550b40();
    _free(pvVar2);
  }
  param_1[0x1e8] = 0;
  pvVar2 = DAT_00734f6c;
  if (param_1[0x1e9] != 0) {
    if (DAT_00734f6c != (void *)0x0) {
      piVar1 = (int *)((int)DAT_00734f6c + 8);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        DAT_0073d8c8 = 0;
        DAT_0073d8c4 = 0;
        if (*(void **)((int)pvVar2 + 0x14) != (void *)0x0) {
          _free(*(void **)((int)pvVar2 + 0x14));
        }
        *(undefined4 *)((int)pvVar2 + 0x18) = 0;
        eh_vector_destructor_iterator((void *)((int)pvVar2 + 0x1c),0xc,0x20,WString_Free);
        _free(pvVar2);
        DAT_00734f6c = (void *)0x0;
      }
      else {
        *(undefined1 *)((int)pvVar2 + 5) = 0;
      }
    }
    param_1[0x1e9] = 0;
  }
  DAT_007363b3 = 0;
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x551280 FUN_00551280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00551280(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_768;
  undefined4 local_764;
  undefined4 local_75c;
  undefined4 local_758;
  undefined4 local_754;
  undefined4 local_750;
  undefined4 local_74c;
  undefined4 local_744;
  undefined4 local_740;
  undefined4 local_73c;
  undefined4 local_738;
  undefined1 local_730 [1836];
  
  if ((*(int *)(param_1 + 0x7a4) != 0) &&
     (cVar1 = FUN_00553b30(param_3,param_4,DAT_00734f68), cVar1 != '\0')) {
    DAT_007301c8 = 1;
    DAT_00734f68 = 0;
    return;
  }
  iVar2 = *(int *)(param_1 + 0x7a4);
  DAT_007301c8 = 0;
  if (((iVar2 != 0) && (*(char *)(iVar2 + 0x1c9) == '\x01')) &&
     ((param_2 == 0x406415e3 || ((0xdbb06160 < param_2 && (param_2 < 0xdbb06169)))))) {
    DAT_00734f68 = 1;
    return;
  }
  if (param_2 < 0xc519bfc0) {
    if (param_2 == 0xc519bfbf) {
      if (*(int *)(param_1 + 0x6c) != 1) {
        DAT_007301c8 = 0;
        return;
      }
      DAT_00777b58 = 0;
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 < 0x8d09b828) {
      if (param_2 == 0x8d09b827) {
        FUN_0054ad50(FUN_00554230);
        return;
      }
      if (0x68c137bd < param_2) {
        if (param_2 == 0x72619778) {
          FUN_00550ba0();
          return;
        }
        if (param_2 != 0x8463b1e0) {
          if (param_2 != 0x88b44b70) {
            DAT_007301c8 = 0;
            return;
          }
          Struct_InitHashPair();
          local_768 = 0;
          local_764 = 0x8d09b827;
          local_75c = 0xc33fc7d3;
          local_750 = 0x639;
          local_74c = 0;
          local_758 = 0xc3430cd9;
          local_754 = 0;
          FUN_004eb950();
          return;
        }
        FUN_0054ad20();
        _DAT_00777b5c = 2;
        uVar3 = *(undefined4 *)(param_1 + 0xc);
        goto LAB_0055186b;
      }
      if (param_2 == 0x68c137bd) {
        if (iVar2 == 0) {
          DAT_007301c8 = 0;
          return;
        }
        FUN_00553a90(&DAT_00777c90);
        return;
      }
      if (param_2 == 0x14de0507) {
        if (iVar2 == 0) {
          DAT_007301c8 = 0;
          return;
        }
        if (*(char *)(iVar2 + 0x1c9) != '\x01') {
          *(undefined1 *)(iVar2 + 0x1c9) = 1;
          DAT_00734f68 = 1;
          return;
        }
        *(undefined1 *)(iVar2 + 0x1c9) = 0;
        return;
      }
      if (param_2 != 0x3d981880) {
        if (param_2 != 0x5b884e10) {
          DAT_007301c8 = 0;
          return;
        }
        _DAT_00777b5c = 3;
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      RideInfo__Init();
      iVar2 = FUN_00549ea0(local_730);
      if (iVar2 != 0) {
        FUN_004b23b0(local_730,1);
        _DAT_00777b5c = 3;
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else {
      if (0x93ea5075 < param_2) {
        if (param_2 == 0xb5971bf1) {
          FUN_00551b90();
          *(undefined4 *)(param_1 + 0x7a8) = 0x9ccc9726;
          FUN_004c96c0(0xb3c3508e);
          return;
        }
        if (param_2 != 0xbde07ebd) {
          DAT_007301c8 = 0;
          return;
        }
        _DAT_00777b5c = 4;
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x93ea5075) {
        if (param_2 == 0x911ab364) {
          iVar2 = FEngFindPackage();
          if (iVar2 != 0) {
            *(undefined4 *)(iVar2 + 0x1c) = 0;
          }
          FUN_0054ac00(FUN_00554120);
          return;
        }
        if (param_2 != 0x911c0a4b) {
          if (param_2 != 0x9120409e) {
            DAT_007301c8 = 0;
            return;
          }
          FUN_00551b90();
          *(undefined4 *)(param_1 + 0x7a8) = 0x9d5e09c9;
          FUN_004c96c0(0xfc661e67);
          return;
        }
        FUN_00550ba0();
        return;
      }
    }
    FUN_0054bca0(&DAT_0073d868);
    return;
  }
  if (param_2 < 0xdbb06165) {
    if (param_2 == 0xdbb06164) {
      FUN_005519d0(param_1);
      return;
    }
    if (0xc98356ba < param_2) {
      if (param_2 == 0xdbb06161) {
        FUN_005519d0(param_1);
        return;
      }
      if (param_2 != 0xdbb06162) {
        if (param_2 != 0xdbb06163) {
          DAT_007301c8 = 0;
          return;
        }
        FUN_005519d0(param_1);
        return;
      }
      FUN_005519d0(param_1);
      return;
    }
    if (param_2 == 0xc98356ba) {
      if (*(int *)(param_1 + 0x6c) == 0) {
        FUN_00552610(param_1,0);
      }
      else {
        FUN_00552bb0(param_1,0);
      }
      iVar2 = *(int *)(param_1 + 0x7a4);
      if ((iVar2 != 0) && (*(char *)(iVar2 + 5) == '\0')) {
        FUN_005534a0(iVar2);
      }
      FUN_00551890();
      return;
    }
    if (param_2 != 0xc519bfc1) {
      if (param_2 == 0xc519bfc2) {
        FUN_00551b40(param_1);
        return;
      }
      if (param_2 != 0xc519bfc3) {
        DAT_007301c8 = 0;
        return;
      }
      GenericDialogData__GenericDialogData();
      local_764 = *(undefined4 *)(param_1 + 0x7a8);
      local_744 = 1;
      local_768 = 0x169268;
      local_73c = 0;
      local_738 = 0;
      local_740 = 0x639;
      FUN_004dcfd0(&local_768,*(undefined4 *)(param_1 + 0xc));
      return;
    }
    FUN_00551b40(param_1);
    return;
  }
  if (param_2 < 0xdbb06169) {
    if (param_2 == 0xdbb06168) {
      FUN_005519d0(param_1);
      return;
    }
    if (param_2 == 0xdbb06165) {
      FUN_005519d0(param_1);
      return;
    }
    if (param_2 == 0xdbb06166) {
      FUN_005519d0(param_1);
      return;
    }
    if (param_2 != 0xdbb06167) {
      DAT_007301c8 = 0;
      return;
    }
    FUN_005519d0(param_1);
    return;
  }
  if (param_2 != 0xdeaddead) {
    if (param_2 != 0xf5058ca7) {
      DAT_007301c8 = 0;
      return;
    }
    _DAT_00777b5c = 1;
    FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    DAT_007301c8 = 0;
    return;
  }
  cFrontendDatabase__SetString2ED20();
  DAT_00777b58 = 1;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
LAB_0055186b:
  FEngSwitchPackages(uVar3);
  return;
}


// ==== 0x551890 FUN_00551890

void FUN_00551890(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int *piVar5;
  undefined4 uVar6;
  
  piVar5 = (int *)(unaff_ESI + 0x40);
  iVar4 = 10;
  do {
    if ((*piVar5 != 0) && (DAT_007064b2 != '\0')) {
      cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar2 != '\0') {
        uVar1 = *(uint *)(*piVar5 + 0x10);
        if (uVar1 < 0xda928c88) {
          if (uVar1 == 0xda928c87) {
            iVar3 = FEPackageList__FindByName(&DAT_00746104);
            if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
               (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
              (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0xd9feec59,0,0,*(int *)(iVar3 + 0x18));
            }
            goto LAB_005519b9;
          }
          if (uVar1 < 0xaa68bfd5) {
            if (uVar1 == 0xaa68bfd4) {
              uVar6 = 0xb5971bf1;
            }
            else if (uVar1 == 0x925c868a) {
              uVar6 = 0xc519bfbf;
            }
            else {
              if (uVar1 != 0xaa68bfce) goto LAB_005519b9;
              uVar6 = 0x9120409e;
            }
          }
          else {
            if (uVar1 != 0xda928c86) goto LAB_005519b9;
            uVar6 = 0x911c0a4b;
          }
        }
        else if (uVar1 < 0xda9bdef8) {
          if (uVar1 == 0xda9bdef7) {
            uVar6 = 0x72619778;
          }
          else if (uVar1 == 0xda96ef8f) {
            uVar6 = 0xc519bfc1;
          }
          else {
            if (uVar1 != 0xda9a39d5) goto LAB_005519b9;
            uVar6 = 0xc519bfc2;
          }
        }
        else {
          if (uVar1 != 0xda9bdef8) goto LAB_005519b9;
          uVar6 = 0x5073ef13;
        }
        FUN_004c96c0(uVar6);
      }
    }
LAB_005519b9:
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x5519d0 FUN_005519d0

void FUN_005519d0(int param_1)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  char local_80 [128];
  
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x7a0) + 0x34 + in_EAX * 4) + 0x24) != '\0') {
    FUN_0059fb30(0x80);
    iVar3 = 0;
    do {
      cVar1 = local_80[iVar3];
      cVar2 = (&DAT_00734718)[iVar3];
      iVar3 = iVar3 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 != cVar2) {
      if (*(int *)(param_1 + 0x6c) == 0) {
        DAT_00777c90 = local_80[0];
        if (local_80[0] != '\0') {
          iVar3 = 0;
          do {
            cVar1 = local_80[iVar3 + 1];
            (&DAT_00777c91)[iVar3] = cVar1;
            iVar3 = iVar3 + 1;
          } while (cVar1 != '\0');
        }
        DAT_00777b54 = 0;
        DAT_00777b58 = 2;
        iVar3 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) {
          FEngQueuePackagePush(3);
          return;
        }
      }
      else {
        DAT_00777b54 = 1;
        if ((DAT_0073d8d0 == 0) ||
           (puVar4 = (undefined4 *)FUN_00666f30(DAT_0073d8dc,in_EAX + -1),
           puVar4 == (undefined4 *)0x0)) {
          DAT_00777cb0 = 0;
        }
        else {
          DAT_00777cb0 = *puVar4;
        }
        DAT_00777c90 = local_80[0];
        if (local_80[0] != '\0') {
          iVar3 = 0;
          do {
            cVar1 = local_80[iVar3 + 1];
            (&DAT_00777c91)[iVar3] = cVar1;
            iVar3 = iVar3 + 1;
          } while (cVar1 != '\0');
        }
        DAT_00777b58 = 1;
        iVar3 = FEngFindPackage();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0;
        }
        FUN_0054a700(FUN_00554180);
      }
    }
  }
  return;
}


// ==== 0x551b40 FUN_00551b40

void __thiscall FUN_00551b40(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 == 1;
  iVar1 = *(int *)(param_2 + 0x7a0);
  *(bool *)(param_2 + 0x70) = bVar2;
  FUN_00550780();
  if ((bool)*(char *)(iVar1 + 0xd) != bVar2) {
    *(bool *)(iVar1 + 0xd) = bVar2;
    *(undefined1 *)(iVar1 + 0xe) = 1;
  }
  if (*(int *)(param_2 + 0x6c) == 0) {
    FUN_00552610(param_2,1);
    return;
  }
  FUN_00552bb0(param_2,1);
  return;
}


// ==== 0x551b90 FUN_00551b90

void __fastcall FUN_00551b90(int param_1)

{
  int iVar1;
  int in_EAX;
  
  if (*(int *)(param_1 + 0x6c) != in_EAX) {
    iVar1 = *(int *)(param_1 + 0x7a0);
    *(int *)(param_1 + 0x6c) = in_EAX;
    FUN_00550730();
    if (*(int *)(iVar1 + 8) != in_EAX) {
      *(int *)(iVar1 + 8) = in_EAX;
      *(undefined1 *)(iVar1 + 0xc) = 1;
    }
    FUN_00553300();
    iVar1 = *(int *)(param_1 + 0x7a0);
    DAT_00777b54 = in_EAX;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    FUN_004f9f30();
    if (*(int *)(param_1 + 0x6c) == 0) {
      FUN_00552610(param_1,1);
      return;
    }
    FUN_00552bb0(param_1,1);
  }
  return;
}


// ==== 0x551c10 FUN_00551c10

void FUN_00551c10(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Rep_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00551c82;
    }
  }
  else {
LAB_00551c82:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 1;
      FEng__HashName(1);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  FUN_004f7f10(param_1);
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"PlayersName_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00551d13;
    }
  }
  else {
LAB_00551d13:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 1;
      FEng__HashName(1);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  FUN_004f7f10(param_1);
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"DISC_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00551da4;
    }
  }
  else {
LAB_00551da4:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 1;
      FEng__HashName(1);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  FUN_004f7f10(param_1);
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Ping_Group_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00551e35;
    }
  }
  else {
LAB_00551e35:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 1;
      FEng__HashName(1);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  FUN_004f7f10(param_1);
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"NumberOfPlayers_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) goto LAB_00551ee8;
    FUN_004ef050(uVar1);
  }
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar1 = 1;
    FEng__HashName(1);
    cFEng__SetButtonState(iVar2,uVar1);
  }
LAB_00551ee8:
  FUN_004f7f10(param_1);
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"HighLight_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      FUN_004f7f10(param_1);
      return;
    }
    FUN_004ef050(uVar1);
  }
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar1 = 1;
    FEng__HashName(1);
    cFEng__SetButtonState(iVar2,uVar1);
  }
  FUN_004f7f10(param_1);
  return;
}


// ==== 0x551fa0 FUN_00551fa0

void FUN_00551fa0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Rep_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00552012;
    }
  }
  else {
LAB_00552012:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 0;
      FEng__HashName(0);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"PlayersName_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00552095;
    }
  }
  else {
LAB_00552095:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 0;
      FEng__HashName(0);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"DISC_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_00552118;
    }
  }
  else {
LAB_00552118:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 0;
      FEng__HashName(0);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Ping_Group_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      FUN_004ef050(uVar1);
      goto LAB_0055219b;
    }
  }
  else {
LAB_0055219b:
    iVar2 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar1 = 0;
      FEng__HashName(0);
      cFEng__SetButtonState(iVar2,uVar1);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"NumberOfPlayers_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) goto LAB_0055223e;
    FUN_004ef050(uVar1);
  }
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar1 = 0;
    FEng__HashName(0);
    cFEng__SetButtonState(iVar2,uVar1);
  }
LAB_0055223e:
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"HighLight_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    FUN_004ef050(uVar1);
  }
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar1 = 0;
    FEng__HashName(0);
    cFEng__SetButtonState(iVar2,uVar1);
  }
  return;
}


// ==== 0x5522d0 FUN_005522d0

void FUN_005522d0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Rep_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      goto LAB_00552342;
    }
  }
  else {
LAB_00552342:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"PlayersName_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      goto LAB_005523c8;
    }
  }
  else {
LAB_005523c8:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"DISC_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      goto LAB_0055244e;
    }
  }
  else {
LAB_0055244e:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"Ping_Group_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      goto LAB_005524d4;
    }
  }
  else {
LAB_005524d4:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
    }
  }
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"NumberOfPlayers_DATA_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) goto LAB_0055257d;
    iVar2 = FUN_004ef050(uVar1);
  }
  if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
    FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
  }
LAB_0055257d:
  if (param_2 < 10) {
    pcVar3 = "%s0%d";
  }
  else {
    pcVar3 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar3,"HighLight_",param_2);
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(uVar1);
  }
  if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
    FUN_004f0700(0x55d1e635,iVar2,*(undefined4 *)(param_1 + 0x68),iVar2,0);
  }
  return;
}


// ==== 0x552610 FUN_00552610

void FUN_00552610(int param_1,char param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int local_848;
  int local_844;
  undefined4 local_840 [36];
  char local_7b0 [128];
  int local_730 [459];
  
  DAT_00777b54 = 0;
  if (DAT_0073d8d0 == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0064c660(DAT_0073d8d8);
    if (6 < iVar8) {
      iVar8 = 6;
    }
  }
  iVar3 = 0;
  if (0 < iVar8) {
    do {
      iVar3 = iVar3 + 1;
      FUN_00551c10(param_1,iVar3);
    } while (iVar3 < iVar8);
    if (5 < iVar3) goto LAB_00552685;
  }
  iVar3 = iVar3 + 1;
  do {
    FUN_00551fa0(param_1,iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
LAB_00552685:
  if (DAT_0073d8d0 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0064c660(DAT_0073d8d8);
  }
  FUN_00550bd0(*(undefined4 *)(param_1 + 0x7a0),uVar4);
  local_848 = *(int *)(*(int *)(param_1 + 0x7a0) + 0x2c);
  if (local_848 < *(int *)(*(int *)(param_1 + 0x7a0) + 0x30)) {
    local_844 = 0x38;
    do {
      FUN_0059fb30(0x80);
      if (*(char *)(param_1 + 0x70) == '\0') {
        iVar8 = FUN_00666f30(DAT_0073d8d8,local_848);
        iVar3 = -1;
        if ((DAT_0073d8d0 != 0) && (iVar8 != 0)) {
          iVar3 = FUN_00668b40(DAT_0073daf4,*(undefined4 *)(iVar8 + 0x30),0,0);
        }
        if ((((iVar3 < 0) &&
             (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x7a0) + local_844) + 0x10) + 0x10) < 0)
             ) && (iVar8 = FUN_00666f30(DAT_0073d8d8,local_848), DAT_0073d8d0 != 0)) && (iVar8 != 0)
           ) {
          _atoi((char *)(iVar8 + 0x28));
        }
        FUN_0055e980();
      }
      if (DAT_0073d8d0 == 0) {
LAB_005527bc:
        pcVar9 = "";
      }
      else {
        iVar8 = FUN_00666f30(DAT_0073d8d8,local_848);
        pcVar9 = (char *)(iVar8 + 8);
        if (iVar8 == 0) goto LAB_005527bc;
      }
      iVar8 = -(int)pcVar9;
      do {
        cVar1 = pcVar9[(int)(local_7b0 + iVar8)];
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if ((cVar1 != cVar2) || (param_2 != '\0')) {
        if ((DAT_0073d8d0 == 0) || (iVar8 = FUN_00666f30(DAT_0073d8d8,local_848), iVar8 == 0)) {
          puVar5 = &DAT_006b9172;
        }
        else {
          puVar5 = (undefined1 *)(iVar8 + 8);
        }
        FEngPrintf(puVar5);
        if (DAT_0073d8d0 == 0) {
          puVar6 = &DAT_006ca910;
        }
        else {
          FUN_00666f30(DAT_0073d8d8,local_848);
          puVar6 = (undefined *)FUN_00549dc0();
        }
        FEngPrintf(puVar6);
        FEngPrintf(&DAT_006b9172);
        if (*(char *)(param_1 + 0x70) == '\0') {
LAB_00552a30:
          FEngPrintf(&DAT_006b9172);
        }
        else {
          if ((DAT_0073d8d0 == 0) || (iVar8 = FUN_00666f30(DAT_0073d8d8,local_848), iVar8 == 0)) {
            puVar5 = &DAT_006b9172;
          }
          else {
            puVar5 = (undefined1 *)(iVar8 + 8);
          }
          iVar8 = FUN_0054b700(&DAT_0073d868,puVar5);
          puVar7 = local_840;
          for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if (iVar8 == 0) goto LAB_00552a30;
          pcVar9 = (char *)(iVar8 + 0x38);
          iVar8 = 0;
          if ((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) {
LAB_00552947:
            puVar7 = &DAT_006f3cd0;
            puVar10 = local_840;
            for (iVar8 = 0x23; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar10 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar10 = puVar10 + 1;
            }
          }
          else {
            do {
              iVar3 = iVar8 + 1;
              iVar8 = iVar8 + 1;
            } while (pcVar9[iVar3] != '\0');
            if (iVar8 < 1) goto LAB_00552947;
            FUN_006682f0(pcVar9,local_840,0x8c,&DAT_006bd444);
          }
          switch(DAT_00777cb4) {
          case 0:
            break;
          case 1:
            break;
          case 2:
            break;
          case 3:
          }
          uVar4 = _ftol_nocw();
          FEngPrintf(&DAT_006bcecc,uVar4);
        }
        RideInfo__Init();
        if (DAT_0073d8d0 != 0) {
          FUN_00666f30(DAT_0073d8d8,local_848);
          iVar8 = FUN_00549ed0(&DAT_0073d868,local_730);
          if ((iVar8 != 0) && (local_730[0] != -1)) {
            if (*(char *)(param_1 + 0x70) == '\0') {
              FEngPrintf(&DAT_006b9172);
              uVar4 = GetCarModelNameHash();
              FUN_00495f00(uVar4);
            }
            else {
              uVar4 = FUN_005808e0();
              switch(uVar4) {
              default:
                break;
              case 1:
                break;
              case 2:
                break;
              case 0xfffffffe:
                break;
              case 0xffffffff:
              }
              iVar8 = LanguageStrings__FindByHash();
              if (iVar8 == 0) {
                iVar8 = LanguageStrings__FindByHash();
              }
              FEngPrintf(iVar8);
            }
          }
        }
      }
      local_848 = local_848 + 1;
      local_844 = local_844 + 4;
    } while (local_848 < *(int *)(*(int *)(param_1 + 0x7a0) + 0x30));
  }
  return;
}


// ==== 0x552bb0 FUN_00552bb0

void FUN_00552bb0(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_7c4;
  undefined4 local_7c0 [36];
  int local_730 [459];
  
  if (DAT_0073d8d0 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_0064c660(DAT_0073d8dc);
    if (6 < iVar7) {
      iVar7 = 6;
    }
  }
  iVar2 = 0;
  if (0 < iVar7) {
    do {
      iVar2 = iVar2 + 1;
      FUN_00551c10(param_1,iVar2);
    } while (iVar2 < iVar7);
    if (5 < iVar2) goto LAB_00552c15;
  }
  iVar2 = iVar2 + 1;
  do {
    FUN_00551fa0(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
LAB_00552c15:
  iVar7 = **(int **)(param_1 + 0x7a0);
  if ((*(int **)(param_1 + 0x7a0))[9] != iVar7) {
    FUN_005522d0(param_1,iVar7 + 1);
  }
  if (DAT_0073d8d0 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0064c660(DAT_0073d8dc);
  }
  FUN_00550bd0(*(undefined4 *)(param_1 + 0x7a0),uVar3);
  iVar7 = *(int *)(*(int *)(param_1 + 0x7a0) + 0x2c);
  if (iVar7 < *(int *)(*(int *)(param_1 + 0x7a0) + 0x30)) {
    local_7c4 = 0x38;
    do {
      if ((DAT_0073d8d0 == 0) || (iVar2 = FUN_00666f30(DAT_0073d8dc,iVar7), iVar2 == 0)) {
        puVar4 = &DAT_006b9172;
      }
      else {
        puVar4 = (undefined1 *)(iVar2 + 9);
      }
      FEngPrintf(puVar4);
      if (*(char *)(param_1 + 0x70) == '\0') {
        if (((DAT_0073d8d0 == 0) || (iVar2 = FUN_00666f30(DAT_0073d8dc,iVar7), iVar2 == 0)) ||
           (iVar2 = FUN_0054b700(&DAT_0073d868,iVar2 + 0x44), iVar2 == 0)) {
LAB_00552d2c:
          if (((*(int *)(*(int *)(*(int *)(local_7c4 + *(int *)(param_1 + 0x7a0)) + 0x10) + 0x10) <
                0) && (DAT_0073d8d0 != 0)) &&
             ((iVar2 = FUN_00666f30(DAT_0073d8dc,iVar7), iVar2 != 0 &&
              ((iVar2 = FUN_0054b700(&DAT_0073d868,iVar2 + 0x44), iVar2 != 0 && (DAT_0073d8d0 != 0))
              )))) {
            _atoi((char *)(iVar2 + 0x28));
          }
        }
        else {
          iVar5 = -1;
          if (DAT_0073d8d0 != 0) {
            iVar5 = FUN_00668b40(DAT_0073daf4,*(undefined4 *)(iVar2 + 0x30),0,0);
          }
          if (iVar5 < 0) goto LAB_00552d2c;
        }
        FUN_0055e980();
      }
      iVar2 = FUN_00666f30(DAT_0073d8dc,iVar7);
      if (DAT_0073d8d0 == 0) {
        puVar4 = &DAT_006b9172;
      }
      else {
        DAT_0078ee28 = 0;
        if (iVar2 != 0) {
          FUN_00565da0(&DAT_006ca778,*(undefined4 *)(iVar2 + 0x24c));
        }
        puVar4 = &DAT_0078ee28;
      }
      FEngPrintf(puVar4);
      if (*(char *)(param_1 + 0x70) == '\0') {
LAB_00552fa2:
        FEngPrintf(&DAT_006b9172);
      }
      else {
        if ((DAT_0073d8d0 == 0) || (iVar2 = FUN_00666f30(DAT_0073d8d8,iVar7), iVar2 == 0)) {
          puVar4 = &DAT_006b9172;
        }
        else {
          puVar4 = (undefined1 *)(iVar2 + 8);
        }
        iVar2 = FUN_0054b700(&DAT_0073d868,puVar4);
        puVar6 = local_7c0;
        for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        if (iVar2 == 0) goto LAB_00552fa2;
        pcVar1 = (char *)(iVar2 + 0x38);
        iVar2 = 0;
        if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
LAB_00552eb9:
          puVar6 = &DAT_006f3cd0;
          puVar8 = local_7c0;
          for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        else {
          do {
            iVar5 = iVar2 + 1;
            iVar2 = iVar2 + 1;
          } while (pcVar1[iVar5] != '\0');
          if (iVar2 < 1) goto LAB_00552eb9;
          FUN_006682f0(pcVar1,local_7c0,0x8c,&DAT_006bd444);
        }
        switch(DAT_00777cb4) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
        }
        uVar3 = _ftol_nocw();
        FEngPrintf(&DAT_006bcecc,uVar3);
      }
      RideInfo__Init();
      if (DAT_0073d8d0 != 0) {
        FUN_00666f30(DAT_0073d8d8,iVar7);
        iVar2 = FUN_00549ed0(&DAT_0073d868,local_730);
        if (((iVar2 != 0) && (local_730[0] != -1)) && (*(char *)(param_1 + 0x70) != '\0')) {
          uVar3 = FUN_005808e0();
          switch(uVar3) {
          default:
            break;
          case 1:
            break;
          case 2:
            break;
          case 0xfffffffe:
            break;
          case 0xffffffff:
          }
          iVar2 = LanguageStrings__FindByHash();
          if (iVar2 == 0) {
            iVar2 = LanguageStrings__FindByHash();
          }
          FEngPrintf(iVar2);
        }
      }
      iVar7 = iVar7 + 1;
      local_7c4 = local_7c4 + 4;
    } while (iVar7 < *(int *)(*(int *)(param_1 + 0x7a0) + 0x30));
  }
  return;
}


// ==== 0x5530e0 FUN_005530e0

void FUN_005530e0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char local_a0 [32];
  char local_80 [64];
  char local_40;
  char local_3f [63];
  
  cVar1 = Obj_GetByte19();
  if (cVar1 == '\0') {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x40;
    pcVar3 = local_80;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_80];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  else {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x40;
    pcVar3 = local_80;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_80];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  FEngPrintf(&DAT_006cc568,local_80);
  pcVar3 = (char *)LanguageStrings_FindByRegionName(&DAT_00748f70);
  local_40 = *pcVar3;
  if (*pcVar3 != '\0') {
    pcVar4 = &local_40;
    do {
      cVar1 = pcVar4[(int)(pcVar3 + (1 - (int)&local_40))];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  if (DAT_00777cb4 == 0) {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x20;
    pcVar3 = local_a0;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_a0];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  else if (DAT_00777cb4 == 1) {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x20;
    pcVar3 = local_a0;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_a0];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  else if (DAT_00777cb4 == 2) {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x20;
    pcVar3 = local_a0;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_a0];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  else if (DAT_00777cb4 == 3) {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x20;
    pcVar3 = local_a0;
    do {
      cVar1 = pcVar3[iVar2 - (int)local_a0];
      iVar5 = iVar5 + -1;
      *pcVar3 = cVar1;
      if (cVar1 == '\0') break;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 != 0);
  }
  FEngPrintf("%s - %s",local_a0,&local_40);
  return;
}


// ==== 0x553300 FUN_00553300

void FUN_00553300(void)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == 0) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar1);
    return;
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x553360 FUN_00553360

void FUN_00553360(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  puVar1 = DAT_00734f6c;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  if (DAT_00734f6c != (undefined4 *)0x0) {
    DAT_00734f6c[2] = DAT_00734f6c[2] + 1;
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
    *(undefined1 *)((int)puVar1 + 5) = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[0x67] = 0;
    puVar1[0x68] = 0;
    puVar1[0x6f] = 0;
    *(undefined1 *)(puVar1 + 0x6e) = 0;
    puVar1[0x70] = 0;
    *(undefined1 *)(puVar1 + 0x69) = 0;
    return;
  }
  ExceptionList = &local_c;
  pvVar2 = _malloc(0x1cc);
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    DAT_00734f6c = (undefined4 *)FUN_00553420();
    ExceptionList = local_c;
    return;
  }
  DAT_00734f6c = (undefined4 *)0x0;
  ExceptionList = local_c;
  return;
}


// ==== 0x553420 FUN_00553420

void FUN_00553420(void)

{
  undefined4 *unaff_ESI;
  
  eh_vector_constructor_iterator(unaff_ESI + 7,0xc,0x20,FUN_0041f130,WString_Free);
  unaff_ESI[0x71] = 0;
  unaff_ESI[0x71] = DAT_0073ad3c;
  *(undefined1 *)((int)unaff_ESI + 0x1c9) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x1ca) = 0;
  *unaff_ESI = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *(undefined1 *)((int)unaff_ESI + 5) = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[0x67] = 0;
  unaff_ESI[0x68] = 0;
  unaff_ESI[0x6f] = 0;
  *(undefined1 *)(unaff_ESI + 0x6e) = 0;
  unaff_ESI[0x70] = 0;
  *(undefined1 *)(unaff_ESI + 0x69) = 0;
  *(undefined1 *)(unaff_ESI + 0x72) = 1;
  unaff_ESI[2] = 1;
  return;
}


// ==== 0x5534a0 FUN_005534a0

void __thiscall FUN_005534a0(undefined1 param_1,int *param_2)

{
  ushort uVar1;
  int in_EAX;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  int local_804;
  undefined4 local_800;
  
  *param_2 = in_EAX;
  *(undefined1 *)(param_2 + 1) = param_1;
  if ((void *)param_2[5] != (void *)0x0) {
    _free((void *)param_2[5]);
  }
  param_2[6] = 0;
  param_2[0x67] = 0;
  param_2[0x68] = 0;
  if (((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x5da51e8f);
    }
  }
  param_2[3] = iVar2;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0x6e2940ce), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  param_2[4] = iVar2;
  param_2[6] = 5;
  pvVar3 = _malloc(0x14);
  param_2[5] = (int)pvVar3;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0xfe840bf8), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  *(int *)param_2[5] = iVar2;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0xfe840bf9), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  *(int *)(param_2[5] + 4) = iVar2;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0xfe840bfa), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  *(int *)(param_2[5] + 8) = iVar2;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0xfe840bfb), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  *(int *)(param_2[5] + 0xc) = iVar2;
  if (((((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(0xfe840bfc), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  *(int *)(param_2[5] + 0x10) = iVar2;
  DAT_0073d8c8 = param_2;
  DAT_0073d8c4 = FUN_00553970;
  *(undefined1 *)((int)param_2 + 5) = 1;
  if (((*(int *)(*param_2 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xad66e6f1);
    }
  }
  param_2[0x6f] = iVar2;
  local_804 = 0;
  if (0 < param_2[6]) {
    do {
      iVar2 = *(int *)(param_2[5] + local_804 * 4);
      FUN_0059ff40(&local_800,0x800);
      iVar4 = 0;
      uVar1 = (ushort)local_800;
      while (uVar1 != 0) {
        iVar4 = iVar4 + 1;
        uVar1 = *(ushort *)((int)&local_800 + iVar4 * 2);
      }
      if (*(uint *)(iVar2 + 100) < iVar4 + 1U) {
        WString_Grow();
      }
      puVar6 = *(undefined2 **)(iVar2 + 0x60);
      puVar7 = (ushort *)&local_800;
      if (puVar6 != (undefined2 *)0x0) {
        uVar1 = (ushort)local_800;
        uVar5 = local_800;
        while (uVar1 != 0) {
          *puVar6 = (short)uVar5;
          puVar7 = puVar7 + 1;
          uVar1 = *puVar7;
          uVar5 = (uint)uVar1;
          puVar6 = puVar6 + 1;
        }
        *puVar6 = 0;
      }
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
      local_804 = local_804 + 1;
    } while (local_804 < param_2[6]);
  }
  *(undefined1 *)((int)param_2 + 0x1c9) = 0;
  return;
}


// ==== 0x553820 FUN_00553820

void FUN_00553820(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  undefined4 uVar9;
  
  iVar5 = param_1;
  piVar1 = (int *)(param_1 + 0x18);
  param_1 = 0;
  if (0 < *piVar1) {
    do {
      iVar6 = *(int *)(iVar5 + 0x1a0) + param_1;
      if (*(int *)(iVar5 + 0x19c) <= iVar6) {
        return;
      }
      iVar4 = *(int *)(*(int *)(iVar5 + 0x14) + param_1 * 4);
      puVar2 = (undefined4 *)(iVar5 + 0x1c + iVar6 * 0xc);
      if (*(char *)(puVar2 + 2) == '\0') {
        if (*(char *)((int)puVar2 + 9) == '\0') {
          if (*(char *)((int)puVar2 + 10) == '\0') {
            uVar9 = 0xffffffff;
          }
          else {
            uVar9 = 0xff00ff80;
          }
        }
        else {
          uVar9 = 0xffff8000;
        }
      }
      else {
        uVar9 = 0xffff80ff;
      }
      FUN_004f75b0(uVar9);
      psVar8 = (short *)*puVar2;
      if (psVar8 != (short *)0x0) {
        iVar6 = 0;
        sVar3 = *psVar8;
        while (sVar3 != 0) {
          iVar6 = iVar6 + 1;
          sVar3 = psVar8[iVar6];
        }
        if (*(uint *)(iVar4 + 100) < iVar6 + 1U) {
          WString_Grow();
        }
        psVar7 = *(short **)(iVar4 + 0x60);
        if (psVar7 != (short *)0x0) {
          sVar3 = *psVar8;
          while (sVar3 != 0) {
            *psVar7 = sVar3;
            psVar8 = psVar8 + 1;
            psVar7 = psVar7 + 1;
            sVar3 = *psVar8;
          }
          *psVar7 = 0;
        }
      }
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)(iVar5 + 0x18));
  }
  return;
}


// ==== 0x553920 FUN_00553920

undefined4 __fastcall FUN_00553920(int param_1)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x1a0);
  uVar2 = uVar1;
  if (*(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x19c)) {
    uVar2 = *(int *)(param_1 + 0x19c) - *(int *)(param_1 + 0x18);
    uVar3 = ((int)(uVar1 + in_EAX) < 1) - 1 & uVar1 + in_EAX;
    if ((int)uVar3 <= (int)uVar2) {
      uVar2 = uVar3;
    }
  }
  if (uVar2 == uVar1) {
    return 0;
  }
  *(uint *)(param_1 + 0x1a0) = uVar2;
  FUN_00553820(param_1);
  return 1;
}


// ==== 0x553970 FUN_00553970

void FUN_00553970(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  if ((*(char *)(param_1 + 4) == '\0') || ((param_5 == '\0' && ((char)param_3 != '\0')))) {
    FUN_005539a0(param_1,param_2,0,param_3,param_4);
  }
  return;
}


// ==== 0x5539a0 FUN_005539a0

void FUN_005539a0(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 local_800 [2048];
  
  if (*(int *)(param_1 + 0x19c) == 0x20) {
    puVar4 = (undefined1 *)(param_1 + 0x24);
    iVar3 = 0x1f;
    do {
      FUN_00504020();
      *puVar4 = puVar4[0xc];
      puVar4[1] = puVar4[0xd];
      puVar4[2] = puVar4[0xe];
      puVar4 = puVar4 + 0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + -1;
  }
  iVar3 = param_1 + 0x1c + *(int *)(param_1 + 0x19c) * 0xc;
  FUN_0059ff40(local_800,0x800);
  WString_Assign();
  *(undefined1 *)(iVar3 + 9) = param_3;
  *(undefined1 *)(iVar3 + 8) = param_4;
  *(undefined1 *)(iVar3 + 10) = param_5;
  iVar3 = *(int *)(param_1 + 0x19c) + 1;
  uVar2 = iVar3 - *(int *)(param_1 + 0x18);
  *(int *)(param_1 + 0x19c) = iVar3;
  uVar5 = *(uint *)(param_1 + 0x1a0);
  if ((*(int *)(param_1 + 0x18) < iVar3) &&
     (uVar1 = ((int)uVar2 < 1) - 1 & uVar2, uVar5 = uVar2, (int)uVar1 <= (int)uVar2)) {
    uVar5 = uVar1;
  }
  if (uVar5 != *(uint *)(param_1 + 0x1a0)) {
    *(uint *)(param_1 + 0x1a0) = uVar5;
  }
  FUN_00553820(param_1);
  return;
}


// ==== 0x553a90 FUN_00553a90

void FUN_00553a90(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int unaff_EDI;
  
  if (((*(char *)(unaff_EDI + 5) != '\0') && (*(char *)(unaff_EDI + 0x1b8) == '\0')) &&
     (*(int *)(unaff_EDI + 0x1c0) == 0)) {
    *(undefined1 *)(unaff_EDI + 0x1b8) = 1;
    pvVar1 = _malloc(0x21);
    *(void **)(unaff_EDI + 0x1c0) = pvVar1;
    bSPrintf_regdst(0x20,"/tell %s ",param_1);
    FUN_00411750(0);
    DAT_007363b3 = 1;
    iVar2 = FEngFindPackage();
    *(undefined4 *)(unaff_EDI + 0x1b4) = *(undefined4 *)(iVar2 + 0x1c);
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0;
    }
  }
  return;
}


// ==== 0x553b30 FUN_00553b30

undefined1 FUN_00553b30(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char cVar5;
  undefined4 *unaff_ESI;
  undefined1 local_45;
  undefined1 local_44 [68];
  
  if (*(char *)((int)unaff_ESI + 5) == '\0') {
    return 0;
  }
  if ((in_EAX == 0x5073ef13) || (in_EAX == -0x260113a7)) {
    FUN_00553920();
  }
  local_45 = *(undefined1 *)(unaff_ESI + 0x6e);
  cVar5 = '\0';
  if (in_EAX != -0x367ca946) {
    return local_45;
  }
  if (unaff_ESI[0x70] == 0) {
    cVar2 = FUN_004f7f10(*unaff_ESI);
    if ((cVar2 != '\0') || (param_3 == 1)) {
      if ((DAT_007064b2 != '\0') || (param_3 == 1)) {
        *(undefined1 *)(unaff_ESI + 0x6e) = 1;
        DAT_0073639c = _malloc(0x21);
        unaff_ESI[0x70] = DAT_0073639c;
        if ((DAT_007064b2 != '\0') || (DAT_007363b0 = 1, param_3 != 1)) {
          DAT_007363b0 = 0;
        }
        *DAT_0073639c = 0;
        DAT_007363ac = 0x20;
        DAT_007363a8 = 1;
        DAT_007363a0 = 0;
        DAT_007363a4 = 0;
        local_45 = 1;
        iVar3 = FEngFindPackage();
        unaff_ESI[0x6d] = *(undefined4 *)(iVar3 + 0x1c);
        iVar3 = FEngFindPackage();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0;
        }
      }
      cVar5 = '\x01';
    }
  }
  else {
    iVar3 = FUN_004117b0();
    if ((0 < iVar3) && (iVar4 = bStrLen(), 0 < iVar4)) {
      FUN_00553de0(unaff_ESI,extraout_ECX);
    }
    if (iVar3 == 0) {
      if (0.2 < (float)(DAT_0073ad3c - unaff_ESI[0x71]) * 0.00025) {
        unaff_ESI[0x71] = DAT_0073ad3c;
        *(byte *)(unaff_ESI + 0x72) = *(byte *)(unaff_ESI + 0x72) ^ 1;
      }
      bStrCpy();
      iVar3 = DAT_007363a4;
      FUN_00567d00();
      iVar4 = bStrLen();
      local_44[iVar4 + 1] = 0;
      if (*(char *)(unaff_ESI + 0x72) == '\0') {
        local_44[iVar3] = 0x20;
      }
      else {
        local_44[iVar3] = 0x7c;
      }
      iVar3 = bStrLen();
      uVar1 = unaff_ESI[4];
      local_44[iVar3 + 1] = 0;
      FUN_0041f060(uVar1,local_44);
      cVar2 = '\x01';
    }
    else {
      DAT_007363a8 = 0;
      DAT_0070108d = 1;
      _free((void *)unaff_ESI[0x70]);
      unaff_ESI[0x70] = 0;
      FUN_0041f060(unaff_ESI[4],&DAT_006b9172);
      uVar1 = unaff_ESI[0x6d];
      *(undefined1 *)(unaff_ESI + 0x6e) = 0;
      cVar5 = '\0';
      iVar3 = FEngFindPackage();
      cVar2 = '\0';
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x1c) = uVar1;
        local_45 = 1;
        goto LAB_00553d72;
      }
    }
    cVar5 = cVar2;
    local_45 = 1;
  }
LAB_00553d72:
  if ((*(char *)((int)unaff_ESI + 0x1ca) == '\x01') && (cVar5 == '\0')) {
    *(undefined1 *)((int)unaff_ESI + 0x1c9) = 0;
  }
  *(char *)((int)unaff_ESI + 0x1ca) = cVar5;
  if (unaff_ESI[3] != 0) {
    if ((cVar5 == '\0') && (*(char *)((int)unaff_ESI + 0x1c9) == '\0')) {
      FEObject__SetScript("UnHighlite",1);
      return local_45;
    }
    FEObject__SetScript("Highlite",1);
  }
  return local_45;
}


// ==== 0x553de0 FUN_00553de0

void FUN_00553de0(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char local_78 [16];
  char local_68 [36];
  undefined1 local_44 [68];
  
  pcVar10 = param_2;
  uVar7 = DAT_007363a4 - 1;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar4 = param_2;
  if (uVar7 < (uint)((int)pcVar3 - (int)(param_2 + 1))) {
    do {
      param_2[uVar7] = param_2[uVar7 + 1];
      uVar7 = uVar7 + 1;
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    } while (uVar7 < (uint)((int)pcVar3 - (int)(param_2 + 1)));
  }
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  *pcVar3 = '\0';
  pcVar4 = "/tell ";
  pcVar3 = param_2;
  iVar8 = 6;
  do {
    iVar9 = iVar8 + -1;
    if (((iVar8 == 0) || (cVar1 = *pcVar3, cVar1 == '\0')) || (cVar2 = *pcVar4, cVar2 == '\0'))
    break;
    pcVar4 = pcVar4 + 1;
    pcVar3 = pcVar3 + 1;
    iVar8 = iVar9;
  } while (cVar1 == cVar2);
  if ((iVar9 < 0) || (((*pcVar3 == '\0' && (*pcVar4 == '\0')) && (pcVar3[-1] == pcVar4[-1])))) {
    pcVar10 = local_68;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar10[0] = '\0';
      pcVar10[1] = '\0';
      pcVar10[2] = '\0';
      pcVar10[3] = '\0';
      pcVar10 = pcVar10 + 4;
    }
    *pcVar10 = '\0';
    local_78[0] = '\0';
    local_78[1] = '\0';
    local_78[2] = '\0';
    local_78[3] = '\0';
    local_78[4] = '\0';
    local_78[5] = '\0';
    local_78[6] = '\0';
    local_78[7] = '\0';
    local_78[8] = '\0';
    local_78[9] = '\0';
    local_78[10] = '\0';
    local_78[0xb] = '\0';
    param_2 = param_2 + 6;
    local_78[0xc] = 0;
    cVar1 = *param_2;
    pcVar10 = param_2;
    while (cVar1 != '\0') {
      if (cVar1 == ' ') goto LAB_00553ed5;
      pcVar3 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
      cVar1 = *pcVar3;
    }
    if (*pcVar10 != ' ') {
      return;
    }
LAB_00553ed5:
    iVar8 = (int)pcVar10 - (int)param_2;
    if (0xc < iVar8) {
      iVar8 = 0xc;
    }
    if (iVar8 != 0) {
      pcVar3 = local_78;
      do {
        cVar1 = pcVar3[(int)param_2 - (int)local_78];
        iVar8 = iVar8 + -1;
        *pcVar3 = cVar1;
        if (cVar1 == '\0') break;
        pcVar3 = pcVar3 + 1;
      } while (iVar8 != 0);
    }
    pcVar10 = pcVar10 + 1;
    iVar8 = 0;
    if ((pcVar10 != (char *)0x0) && (*pcVar10 != '\0')) {
      do {
        iVar9 = iVar8 + 1;
        iVar8 = iVar8 + 1;
      } while (pcVar10[iVar9] != '\0');
      if (0x20 < iVar8) {
        iVar8 = 0x20;
      }
    }
    if (iVar8 != 0) {
      pcVar3 = local_68;
      do {
        cVar1 = pcVar3[(int)pcVar10 - (int)local_68];
        iVar8 = iVar8 + -1;
        *pcVar3 = cVar1;
        if (cVar1 == '\0') break;
        pcVar3 = pcVar3 + 1;
      } while (iVar8 != 0);
    }
    if (*(char *)(param_1 + 4) != '\0') {
      bSPrintf_regdst(0x40,"%s: %s",&DAT_00734718,local_68);
      FUN_005539a0(param_1,local_44,0,1,0);
    }
  }
  else if (*(char *)(param_1 + 0x1a4) == '\0') {
    iVar8 = 0;
    if (*(char *)(param_1 + 4) != '\0') {
      param_2 = (char *)0x0;
      do {
        if (DAT_0073d8d0 == 0) {
LAB_0055404a:
          iVar9 = 0;
        }
        else {
          uVar5 = FUN_00664d40(DAT_0073d8d0,5,DAT_0073dafc);
          iVar9 = FUN_00666ea0(DAT_0073d8dc,uVar5);
          if (iVar9 == 0) goto LAB_0055404a;
          iVar9 = *(int *)(iVar9 + 0x24c);
        }
        if (iVar9 <= (int)param_2) {
          return;
        }
        if (DAT_0073d8d0 == 0) {
LAB_00554081:
          puVar6 = &DAT_006b9172;
        }
        else {
          uVar5 = FUN_00664d40(DAT_0073d8d0,5,DAT_0073dafc);
          iVar9 = FUN_00666ea0(DAT_0073d8dc,uVar5);
          puVar6 = (undefined1 *)(iVar8 + 0x84 + iVar9);
          if (iVar9 == 0) goto LAB_00554081;
        }
        FUN_005540b0(pcVar10,puVar6);
        param_2 = (char *)((int)param_2 + 1);
        iVar8 = iVar8 + 0x20;
      } while( true );
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x1a4) = 0;
    if ((*(char *)(param_1 + 4) != '\0') && (param_1 != -0x1a5)) {
      bSPrintf_regdst(0x40,"%s: %s",&DAT_00734718,param_2);
      FUN_005539a0(param_1,local_44,0,1,0);
    }
  }
  FUN_0054b0e0();
  return;
}


// ==== 0x5540b0 FUN_005540b0

void FUN_005540b0(undefined4 param_1,int param_2)

{
  char in_AL;
  int unaff_EDI;
  undefined1 local_44 [68];
  
  if (((in_AL != '\0') && (*(char *)(unaff_EDI + 4) != '\0')) && (param_2 != 0)) {
    bSPrintf_regdst(0x40,"%s: %s",&DAT_00734718,param_1);
    FUN_005539a0(unaff_EDI,local_44,0,1,0);
  }
  FUN_0054b0e0();
  return;
}


// ==== 0x554120 FUN_00554120

undefined4 FUN_00554120(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(DAT_00734f64 + 0xc);
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


// ==== 0x554180 FUN_00554180

undefined4 FUN_00554180(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_0073d8e0;
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  iVar1 = DAT_0073578c;
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(DAT_00734f64 + 0xc);
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      uVar3 = 0;
      if (iVar2 != 0) {
        uVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0) {
          uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
          return uVar3;
        }
      }
    }
  }
  else {
    if ((iVar2 != 0x74696d65) && (iVar2 != 0x7567616d)) {
      FUN_0054d4a0(&DAT_0073d868,iVar2);
    }
    uVar3 = FUN_004eba00(0,0);
  }
  return uVar3;
}


// ==== 0x554230 FUN_00554230

void FUN_00554230(void)

{
  if (DAT_0073d8e0 == 0) {
    return;
  }
  if (DAT_0073d8e0 < 0x73656c67) {
    if ((DAT_0073d8e0 == 0x73656c66) ||
       ((DAT_0073d8e0 == 0x64697361 || (DAT_0073d8e0 == 0x69706572)))) goto LAB_00554292;
  }
  else if ((DAT_0073d8e0 == 0x74696d65) || (DAT_0073d8e0 == 0x776f6c66)) goto LAB_00554292;
  FUN_0054d4a0(&DAT_0073d868,DAT_0073d8e0);
LAB_00554292:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x5542b0 FUN_005542b0

void FUN_005542b0(void)

{
  if (DAT_0073d8e0 == 0) {
    return;
  }
  if (DAT_0073d8e0 < 0x70726977) {
    if (((DAT_0073d8e0 == 0x70726976) || (DAT_0073d8e0 == 0x64657465)) ||
       ((DAT_0073d8e0 == 0x696e7670 || (DAT_0073d8e0 == 0x6e726f6d)))) goto LAB_00554332;
  }
  else if (((DAT_0073d8e0 == 0x73656c66) || (DAT_0073d8e0 == 0x74696d65)) ||
          (DAT_0073d8e0 == 0x75757372)) goto LAB_00554332;
  FUN_0054d4a0(&DAT_0073d868,DAT_0073d8e0);
LAB_00554332:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x554345 FUN_00554345

void FUN_00554345(void)

{
  FUN_004eba00();
  return;
}


// ==== 0x554350 FUN_00554350

undefined4 FUN_00554350(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x2ebe8);
}


// ==== 0x554360 FUN_00554360

void FUN_00554360(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  FUN_00556750();
  unaff_ESI[3] = param_1;
  *unaff_ESI = &PTR_FUN_006bcde8;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = param_2;
  return;
}


// ==== 0x554390 FUN_00554390

void __fastcall FUN_00554390(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcde8;
  RacerRecord___RacerRecord();
  return;
}


// ==== 0x5543a0 FUN_005543a0

void __fastcall FUN_005543a0(undefined1 param_1)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x10) = param_1;
  return;
}


// ==== 0x5543b0 FUN_005543b0

void * __thiscall FUN_005543b0(void *param_1,byte param_2)

{
  FUN_00554390();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5543d0 FUN_005543d0

undefined4 FUN_005543d0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x540);
}


// ==== 0x5543e0 FUN_005543e0

bool __fastcall FUN_005543e0(int param_1)

{
  return *(int *)(param_1 + 0x534) != -1;
}


// ==== 0x5543f0 FUN_005543f0

int FUN_005543f0(void)

{
  int in_EAX;
  
  return in_EAX + 0xd;
}


// ==== 0x554400 FUN_00554400

undefined1 FUN_00554400(void)

{
  return 1;
}


// ==== 0x554410 FUN_00554410

undefined1 FUN_00554410(void)

{
  int in_EAX;
  
  return *(undefined1 *)(in_EAX + 0x10);
}


// ==== 0x554420 FUN_00554420

undefined4 FUN_00554420(undefined4 param_1)

{
  int iVar1;
  undefined4 local_20;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006881d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = bMalloc_regarg("OnlineGameRoomChallenge",0);
  local_8 = 0;
  if (iVar1 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = FUN_005544a0(param_1);
  }
  ExceptionList = local_10;
  return local_20;
}


// ==== 0x554495 FUN_00554495

void FUN_00554495(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x5544a0 FUN_005544a0

undefined4 * __thiscall FUN_005544a0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_18;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006881b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006bcdec;
  FUN_00589260(param_1,param_1 + 0x16);
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[0x1a] = 0x33650b60;
  Ptr_SetNull();
  Ptr_SetNull();
  iVar2 = FUN_00549480();
  if (iVar2 == 0) {
    cVar1 = FUN_00452d10(&DAT_0078e948);
    if (cVar1 != '\0') {
      iVar2 = RaceOptions_Get();
      *(undefined4 *)(iVar2 + 0x10) = 1;
    }
  }
  FUN_00554730();
  FUN_00555720();
  FUN_004174a0();
  for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
    param_1[local_18 + 0x10] = 0;
  }
  FUN_005556e0(0xda9a39d5,0);
  FUN_005556e0(0xda9a39d4,1);
  FUN_005556e0(0xda96ef8f,2);
  FUN_005556e0(0xda96ef8e,3);
  FUN_004134c0();
  uVar3 = FEngFindPackage();
  DAT_00734f60 = param_1;
  DAT_00734f60[0x14] = uVar3;
  DAT_00734f5c = 0;
  puVar4 = DAT_00734f60;
  FUN_005647b0();
  *(undefined1 *)(puVar4 + 0x15) = 0;
  ExceptionList = local_10;
  return puVar4;
}


// ==== 0x554620 FUN_00554620

void * __thiscall FUN_00554620(void *param_1,uint param_2)

{
  FUN_00554650();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x554650 FUN_00554650

void __fastcall FUN_00554650(undefined4 *param_1)

{
  int iVar1;
  undefined4 *local_3c;
  void *local_10;
  code *pcStack_c;
  uint local_8;
  
  pcStack_c = FUN_00687833;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_006bcdec;
  local_8 = 1;
  while (iVar1 = bList__IsEmpty(), iVar1 == 0) {
    iVar1 = bList__RemoveHead();
    if (iVar1 == 0) {
      local_3c = (undefined4 *)0x0;
    }
    else {
      local_3c = (undefined4 *)(iVar1 + -4);
    }
    if (local_3c != (undefined4 *)0x0) {
      (**(code **)*local_3c)(1);
    }
  }
  FUN_005647c0();
  FUN_004134c0(0xff);
  FEngSetControlMask();
  local_8 = local_8 & 0xffffff00;
  FUN_005567f0();
  local_8 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_10;
  return;
}


// ==== 0x554730 FUN_00554730

/* WARNING: Removing unreachable block (ram,0x00554935) */

void __fastcall FUN_00554730(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  cVar1 = FUN_005494d0();
  if (cVar1 == '\0') {
    FUN_004134c0(0x6c3944c2);
    FUN_00495f00();
    FUN_004134c0(0x39f3f535);
    FUN_00495f00();
    FUN_004134c0(0xba2712ef);
    FUN_00495f00();
    *(undefined4 *)(param_1 + 0x68) = 0xba18ca6b;
  }
  else {
    FUN_004134c0(0xfa4a9656);
    FUN_00495f00();
    FUN_004134c0(0x7ac99493);
    FUN_00495f00();
    FUN_004134c0(0x49567ba9);
    FUN_00495f00();
    *(undefined4 *)(param_1 + 0x68) = 0x33650b60;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  FUN_00555dd0();
  FUN_004134c0(0x41a82386);
  FUN_00495f00();
  FUN_004134c0(0xfc6f0df2);
  FUN_00495f00();
  FUN_004134c0(0x8a50bb37);
  FUN_00495f00();
  puVar5 = (undefined4 *)(param_1 + 0x6c);
  for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)(param_1 + 0xf8) = 0;
  *(undefined1 *)(param_1 + 0x104) = 0;
  *(undefined1 *)(param_1 + 0x10c) = 0;
  *(undefined1 *)(param_1 + 0x118) = 0;
  *(undefined1 *)(param_1 + 0x120) = 0;
  *(undefined1 *)(param_1 + 300) = 0;
  *(undefined1 *)(param_1 + 0x134) = 0;
  *(undefined1 *)(param_1 + 0x140) = 0;
  *(undefined1 *)(param_1 + 0x148) = 0;
  uVar2 = FUN_005494e0();
  *(undefined1 *)(param_1 + 0x149) = uVar2;
  FUN_00424cc0();
  *(undefined1 *)(param_1 + 0x150) = 0;
  *(undefined1 *)(param_1 + 0x151) = 0;
  FUN_00424cc0();
  FUN_005500a0();
  iVar4 = FUN_0054a1b0();
  if (iVar4 == 0) {
    FUN_005500a0();
    FUN_00549fc0();
    uVar3 = FUN_0059fc40();
    FUN_00565da0(&DAT_006cc568,uVar3);
    iVar4 = FUN_00549480();
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x98) == 0) {
        local_30 = 100;
      }
      else {
        local_30 = *(undefined4 *)(param_1 + 0x98);
      }
      FUN_00565da0(&PTR_DAT_006bce54,local_30);
      FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0x88));
      uVar3 = FUN_0059fc40(*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90));
      FUN_00565da0(uVar3);
      FUN_00556220(*(undefined4 *)(param_1 + 0x8c),
                   *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x90));
      uVar3 = _ftol_nocw();
      FUN_00565da0("%d%%%%",uVar3);
      FUN_00556220(*(undefined4 *)(param_1 + 0x94),
                   *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x90));
      uVar3 = _ftol_nocw();
      FUN_00565da0("%d%%%%",uVar3);
      FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0x9c));
      FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xa0));
    }
    else {
      iVar4 = FUN_00549480();
      if (iVar4 == 1) {
        if (*(int *)(param_1 + 0xb4) == 0) {
          local_34 = 100;
        }
        else {
          local_34 = *(undefined4 *)(param_1 + 0xb4);
        }
        FUN_00565da0(&PTR_DAT_006bce54,local_34);
        FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xa4));
        uVar3 = FUN_0059fc40(*(undefined4 *)(param_1 + 0xa8),*(undefined4 *)(param_1 + 0xac));
        FUN_00565da0(uVar3);
        FUN_00556220(*(undefined4 *)(param_1 + 0xa8),
                     *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xac));
        uVar3 = _ftol_nocw();
        FUN_00565da0("%d%%%%",uVar3);
        FUN_00556220(*(undefined4 *)(param_1 + 0xb0),
                     *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xac));
        uVar3 = _ftol_nocw();
        FUN_00565da0("%d%%%%",uVar3);
        FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xb8));
        FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xbc));
      }
      else {
        iVar4 = FUN_00549480();
        if (iVar4 == 3) {
          if (*(int *)(param_1 + 0xd0) == 0) {
            local_38 = 100;
          }
          else {
            local_38 = *(undefined4 *)(param_1 + 0xd0);
          }
          FUN_00565da0(&PTR_DAT_006bce54,local_38);
          FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xc0));
          uVar3 = FUN_0059fc40(*(undefined4 *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 200));
          FUN_00565da0(uVar3);
          FUN_00556220(*(undefined4 *)(param_1 + 0xc4),
                       *(int *)(param_1 + 0xc4) + *(int *)(param_1 + 200));
          uVar3 = _ftol_nocw();
          FUN_00565da0("%d%%%%",uVar3);
          FUN_00556220(*(undefined4 *)(param_1 + 0xcc),
                       *(int *)(param_1 + 0xc4) + *(int *)(param_1 + 200));
          uVar3 = _ftol_nocw();
          FUN_00565da0("%d%%%%",uVar3);
          FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xd4));
          FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xd8));
        }
        else {
          iVar4 = FUN_00549480();
          if (iVar4 == 2) {
            if (*(int *)(param_1 + 0xec) == 0) {
              local_3c = 100;
            }
            else {
              local_3c = *(undefined4 *)(param_1 + 0xec);
            }
            FUN_00565da0(&PTR_DAT_006bce54,local_3c);
            FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xdc));
            uVar3 = FUN_0059fc40(*(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xe4));
            FUN_00565da0(uVar3);
            FUN_00556220(*(undefined4 *)(param_1 + 0xe0),
                         *(int *)(param_1 + 0xe0) + *(int *)(param_1 + 0xe4));
            uVar3 = _ftol_nocw();
            FUN_00565da0("%d%%%%",uVar3);
            FUN_00556220(*(undefined4 *)(param_1 + 0xe8),
                         *(int *)(param_1 + 0xe0) + *(int *)(param_1 + 0xe4));
            uVar3 = _ftol_nocw();
            FUN_00565da0("%d%%%%",uVar3);
            FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xf0));
            FUN_00565da0(&PTR_DAT_006bce54,*(undefined4 *)(param_1 + 0xf4));
          }
        }
      }
    }
  }
  return;
}


// ==== 0x554f60 FUN_00554f60

void __thiscall FUN_00554f60(int param_1,uint param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_c4 [132];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  if (param_2 == 0x406415e3) {
    FUN_004fa050();
    FUN_004b2b40();
  }
  local_8 = FUN_00554350();
  if (param_2 < 0xaabbccde) {
    if (param_2 == 0xaabbccdd) {
      cVar1 = FUN_005494f0();
      if (cVar1 == '\0') {
        return;
      }
      cVar1 = FUN_005494f0();
      if (cVar1 == '\0') {
        return;
      }
      iVar3 = FUN_005543d0();
      if (iVar3 != 0) {
        return;
      }
      FUN_0059fc00();
      uVar2 = FUN_005500a0();
      bSPrintf_regdst(0x80,local_c4,uVar2);
      FUN_004134c0(0x911ab364,0);
      FUN_004ee3a0();
      return;
    }
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        cVar1 = FUN_005494f0();
        if ((cVar1 == '\0') && (cVar1 = FUN_005543e0(), cVar1 == '\0')) {
          FUN_00555740();
          return;
        }
        *(undefined1 *)(param_1 + 0x149) = 0;
        FUN_00424cc0();
        iVar3 = FUN_005543d0();
        if (iVar3 != 0) {
          return;
        }
        FUN_004134c0(0);
        FEngSetControlMask();
        FUN_0054a7e0(0);
        return;
      }
      if (param_2 == 0xaffffa0) {
        FUN_0043a220(1);
        uVar2 = FUN_004134c0();
        FEngSwitchPackages(uVar2);
        return;
      }
      if (param_2 == 0x406415e3) {
        if (param_3 == 0) {
          return;
        }
        FUN_00555800();
        return;
      }
      if (param_2 != 0x72619778) {
        return;
      }
    }
    else if (param_2 != 0x911c0a4b) {
      if (param_2 != 0x9120409e) {
        return;
      }
      goto LAB_005550f7;
    }
    if (((param_3 != 0) && (*(int *)(param_3 + 0x10) == 0x6386b231)) && (DAT_00734f5c != '\0')) {
      uVar2 = FUN_004134c0();
      FEngSetCurrentButton(uVar2);
    }
  }
  else {
    if (0xc519bfc3 < param_2) {
      if (param_2 != 0xc98356ba) {
        if (param_2 != 0xfed0fed0) {
          return;
        }
        FUN_004134c0(0xff);
        FEngSetControlMask();
        return;
      }
      if ((*(char *)(param_1 + 0x149) == '\x01') && (cVar1 = FUN_005494e0(), cVar1 == '\0')) {
        *(undefined1 *)(param_1 + 0x149) = 0;
        FUN_004134c0(0x911ab364,0);
        FUN_004ee3a0();
        return;
      }
      cVar1 = FUN_005494d0();
      if ((cVar1 == '\x01') &&
         ((iVar3 = SpecialCamCooldown(), iVar3 != 0 && (iVar3 = int_Less(), iVar3 != 0)))) {
        iVar3 = FUN_005543d0();
        if (iVar3 != 0) {
          return;
        }
        FUN_00424cc0();
        *(undefined1 *)(param_1 + 0x150) = 1;
        FUN_004134c0(0);
        FEngSetControlMask();
        FUN_0054a7e0(0);
        return;
      }
      iVar3 = SpecialCamCooldown();
      if ((iVar3 != 0) &&
         ((iVar3 = int_Greater(), iVar3 != 0 && (iVar3 = FEngFindPackage(), iVar3 != 0)))) {
        FUN_00424cc0();
        FUN_004ec3c0();
        FUN_004134c0();
        FEngQueueMessageToPackage();
        return;
      }
      iVar3 = FUN_00421960();
      if (iVar3 == 2) {
        FUN_0043aba0();
      }
      FUN_00555720();
      FUN_005560b0();
      FUN_00555560();
      return;
    }
    if (param_2 == 0xc519bfc3) {
      GenericDialogData__GenericDialogData();
      local_3c = *(undefined4 *)(param_1 + 0x68);
      local_1c = 1;
      local_40 = 0x169268;
      local_14 = 0;
      local_10 = 0;
      local_18 = 0x639;
      uVar2 = FUN_004134c0();
      FUN_004dcfd0(&local_40,uVar2);
      return;
    }
    if (param_2 == 0xabddddba) {
      FUN_004134c0(0);
      FEngSetControlMask();
      uVar2 = FUN_005500a0();
      FUN_0054ac80(uVar2);
      return;
    }
    if (param_2 != 0xb5971bf1) {
      return;
    }
LAB_005550f7:
    if (param_3 != 0) {
      iVar3 = *(int *)(param_3 + 0x10);
      if (iVar3 == 0x75666f7) {
        if (((local_8 == 0) || (local_8 == 2)) && (cVar1 = FUN_005494f0(), cVar1 == '\0')) {
          FUN_00555a80(param_2);
        }
      }
      else if (iVar3 == 0x6386b231) {
        if (((local_8 == 0) || (local_8 == 2)) && (cVar1 = FUN_005494f0(), cVar1 == '\0')) {
          FUN_00555bf0(param_2);
        }
      }
      else if ((iVar3 == -0x7e2653f) && (DAT_00734f5c != '\0')) {
        uVar2 = FUN_004134c0();
        FEngSetCurrentButton(uVar2);
      }
    }
  }
  return;
}


// ==== 0x555560 FUN_00555560

void __fastcall FUN_00555560(int param_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if ((*(int *)(param_1 + 0x40 + local_8 * 4) != 0) &&
       (cVar2 = FUN_004f7eb0(param_1), cVar2 != '\0')) {
      uVar1 = *(uint *)(*(int *)(param_1 + 0x40 + local_8 * 4) + 0x10);
      if (uVar1 < 0xda9a39d5) {
        if (uVar1 == 0xda9a39d4) {
          FUN_004134c0();
          uVar3 = FEngFindObject();
          FEngSendMessageToObject(0xb5971bf1,uVar3);
        }
        else if (uVar1 == 0xda96ef8e) {
          FUN_004134c0();
          uVar3 = FEngFindObject();
          FEngSendMessageToObject(0x9120409e,uVar3);
        }
        else if (uVar1 == 0xda96ef8f) {
          FUN_004134c0();
          uVar3 = FEngFindObject();
          FEngSendMessageToObject(0x9120409e,uVar3);
        }
      }
      else if (uVar1 == 0xda9a39d5) {
        FUN_004134c0();
        uVar3 = FEngFindObject();
        FEngSendMessageToObject(0xb5971bf1,uVar3);
      }
    }
  }
  return;
}


// ==== 0x5556e0 FUN_005556e0

void __thiscall FUN_005556e0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((-1 < param_3) && (param_3 < 4)) {
    FUN_004134c0();
    uVar1 = FEngFindObject();
    *(undefined4 *)(param_1 + 0x40 + param_3 * 4) = uVar1;
  }
  return;
}


// ==== 0x555720 FUN_00555720

void __fastcall FUN_00555720(undefined4 param_1)

{
  FUN_005558d0(param_1);
  return;
}


// ==== 0x555740 FUN_00555740

void __fastcall FUN_00555740(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x54) == '\0') {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      FUN_004ec3c0();
    }
  }
  FUN_004134c0(0xff);
  FEngSetControlMask();
  uVar2 = FUN_004134c0();
  FEngSwitchPackages(uVar2);
  return;
}


// ==== 0x5557a0 FUN_005557a0

undefined4 FUN_005557a0(void)

{
  int iVar1;
  
  FUN_00424cc0();
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    FUN_004ec3c0();
    FUN_00424cc0();
  }
  FUN_004134c0(0xaffffa0,0);
  FUN_004ee3a0();
  return 0;
}


// ==== 0x555800 FUN_00555800

/* WARNING: Removing unreachable block (ram,0x00555848) */

void __fastcall FUN_00555800(int param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  
  if ((*(char *)(param_1 + 0x148) == '\0') && (iVar2 = FUN_005543d0(), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x148) = 1;
    FUN_004134c0(0);
    FEngSetControlMask();
    cVar1 = FUN_005494d0();
    if (cVar1 == '\0') {
      pcVar3 = FUN_00556580;
      FUN_005543f0(FUN_00556580);
      FUN_0054a4e0(pcVar3);
    }
    else {
      FUN_0054a370(&DAT_00734718,FUN_005563f0);
    }
  }
  return;
}


// ==== 0x5558d0 FUN_005558d0

void __fastcall FUN_005558d0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = RaceOptions_Get();
  iVar3 = FUN_00555ff0(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc));
  if ((iVar3 != 0) && (iVar3 != *(int *)(param_1 + 0x60))) {
    *(int *)(param_1 + 0x60) = iVar3;
  }
  uVar4 = FUN_0055ebb0();
  FUN_004134c0(uVar4);
  FUN_00495f00();
  bSPrintf_regdst(0x20,"LapsData");
  iVar3 = FUN_00549480();
  if ((iVar3 == 1) || (iVar3 = FUN_00549480(), iVar3 == 3)) {
    FUN_004134c0(&DAT_006ca778,0);
    FEngPrintf();
  }
  else {
    FUN_004134c0(&DAT_006ca778,*(undefined4 *)(iVar2 + 0x10));
    FEngPrintf();
  }
  iVar2 = FUN_00549480();
  if (((iVar2 == 1) || (iVar2 = FUN_00549480(), iVar2 == 3)) ||
     (cVar1 = FUN_005494f0(), cVar1 != '\0')) {
    FUN_004134c0("GreyOut",1);
    FEngSetScript();
    FUN_004134c0("GreyOut",1);
    FEngSetScript();
  }
  iVar2 = FUN_00554350();
  if ((iVar2 != 1) && (cVar1 = FUN_005494f0(), cVar1 == '\0')) {
    return;
  }
  FUN_004134c0("GreyOut",1);
  FEngSetScript();
  FUN_004134c0("GreyOut",1);
  FEngSetScript();
  return;
}


// ==== 0x555a80 FUN_00555a80

void __thiscall FUN_00555a80(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int local_34;
  int local_2c;
  int local_24;
  int local_1c;
  
  cVar2 = FUN_005494e0();
  if (cVar2 == '\0') {
    iVar1 = *(int *)(param_1 + 0x60);
    cVar2 = FUN_00452d10(&DAT_0078e948);
    if (cVar2 == '\0') {
      if (param_2 == -0x6edfbf62) {
        local_1c = FUN_00421960();
        if (local_1c == 0) {
          local_1c = 0;
        }
        else {
          local_1c = local_1c + -4;
        }
        if (*(int *)(param_1 + 0x60) != local_1c) {
          local_24 = FUN_00417490();
          if (local_24 == 0) {
            local_24 = 0;
          }
          else {
            local_24 = local_24 + -4;
          }
          *(int *)(param_1 + 0x60) = local_24;
        }
      }
      else if (param_2 == -0x4a68e40f) {
        local_2c = FUN_00417490();
        if (local_2c == 0) {
          local_2c = 0;
        }
        else {
          local_2c = local_2c + -4;
        }
        if (*(int *)(param_1 + 0x60) != local_2c) {
          local_34 = FUN_00421960();
          if (local_34 == 0) {
            local_34 = 0;
          }
          else {
            local_34 = local_34 + -4;
          }
          *(int *)(param_1 + 0x60) = local_34;
        }
      }
      if (*(int *)(param_1 + 0x60) != iVar1) {
        cVar2 = FUN_00554410(param_1);
        if (cVar2 == '\0') {
          FUN_00555fa0();
        }
        FUN_005558d0();
      }
      FUN_00555720();
    }
  }
  return;
}


// ==== 0x555bf0 FUN_00555bf0

void __thiscall FUN_00555bf0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_005494e0(param_1);
  if (cVar1 == '\0') {
    iVar2 = FUN_00549480();
    if ((iVar2 == 0) || (iVar2 = FUN_00549480(), iVar2 == 2)) {
      iVar2 = RaceOptions_Get();
      cVar1 = FUN_00452d10(&DAT_0078e948);
      if (cVar1 == '\0') {
        if (param_2 == -0x6edfbf62) {
          *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
          if (*(int *)(iVar2 + 0x10) < 2) {
            *(undefined4 *)(iVar2 + 0x10) = 2;
          }
          FUN_00555fa0();
        }
        else if (param_2 == -0x4a68e40f) {
          *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
          if (10 < *(int *)(iVar2 + 0x10)) {
            *(undefined4 *)(iVar2 + 0x10) = 10;
          }
          FUN_00555fa0();
        }
      }
      else {
        *(undefined4 *)(iVar2 + 0x10) = 1;
        FUN_00555fa0();
      }
    }
    FUN_00555720();
  }
  return;
}


// ==== 0x555ce0 FUN_00555ce0

void __thiscall FUN_00555ce0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00684cd3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = bMalloc_regarg("OnlineSelectableTrack",0);
  local_8 = 0;
  if (iVar1 != 0) {
    FUN_00554360(param_2,param_3);
  }
  local_8 = 0xffffffff;
  bList__AddTail();
  *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
  FUN_005543a0();
  ExceptionList = local_10;
  return;
}


// ==== 0x555dd0 FUN_00555dd0

void __fastcall FUN_00555dd0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_34;
  int local_2c;
  int local_1c;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    iVar2 = FUN_004a9950();
    if (iVar2 <= local_14) break;
    iVar2 = TrackInfo_GetRow();
    iVar3 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
    if (iVar3 != 0) {
      cVar1 = FUN_00554400(param_1,(int)*(short *)(iVar2 + 0x6c),0);
      if (cVar1 != '\0') {
        FUN_00555ce0(iVar2,0);
      }
    }
    local_14 = local_14 + 1;
  }
  iVar2 = FUN_00549480();
  if (iVar2 != 2) {
    local_1c = 0;
    while( true ) {
      iVar2 = FUN_004a9950();
      if (iVar2 <= local_1c) break;
      iVar2 = TrackInfo_GetRow();
      iVar3 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
      if (iVar3 != 0) {
        cVar1 = FUN_00554400(param_1,(int)*(short *)(iVar2 + 0x6c),1);
        if (cVar1 != '\0') {
          FUN_00555ce0(iVar2,1);
        }
      }
      local_1c = local_1c + 1;
    }
  }
  bList__IsEmpty();
  iVar2 = RaceOptions_Get();
  if (*(int *)(iVar2 + 8) == -1) {
    local_2c = FUN_00421960();
    if (local_2c == 0) {
      local_2c = 0;
    }
    else {
      local_2c = local_2c + -4;
    }
    *(int *)(param_1 + 0x60) = local_2c;
    *(int *)(iVar2 + 8) = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x6c);
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  else {
    uVar4 = FUN_00555ff0(*(int *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc));
    *(undefined4 *)(param_1 + 0x60) = uVar4;
    if (*(int *)(param_1 + 0x60) == 0) {
      local_34 = FUN_00421960();
      if (local_34 == 0) {
        local_34 = 0;
      }
      else {
        local_34 = local_34 + -4;
      }
      *(int *)(param_1 + 0x60) = local_34;
    }
  }
  return;
}


// ==== 0x555fa0 FUN_00555fa0

void __fastcall FUN_00555fa0(int param_1)

{
  int iVar1;
  
  iVar1 = RaceOptions_Get();
  *(int *)(iVar1 + 8) = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x6c);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x18);
  return;
}


// ==== 0x555ff0 FUN_00555ff0

int FUN_00555ff0(int param_1,int param_2)

{
  int local_24;
  int local_1c;
  int local_14;
  int local_8;
  
  local_14 = FUN_00421960();
  if (local_14 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = local_14 + -4;
  }
  local_8 = local_14;
  while( true ) {
    local_24 = NullUpdate_ret();
    if (local_24 == 0) {
      local_24 = 0;
    }
    else {
      local_24 = local_24 + -4;
    }
    if (local_8 == local_24) break;
    if ((*(short *)(*(int *)(local_8 + 0xc) + 0x6c) == param_1) &&
       (*(int *)(local_8 + 0x18) == param_2)) {
      return local_8;
    }
    local_1c = FUN_00421960();
    if (local_1c == 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_1c + -4;
    }
    local_8 = local_1c;
  }
  return 0;
}


// ==== 0x5560b0 FUN_005560b0

void __fastcall FUN_005560b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_005494d0();
  if (cVar1 == '\0') {
    uVar2 = NullUpdate_ret();
    FUN_004134c0(uVar2);
    FEngPrintf();
  }
  else {
    uVar2 = NullUpdate_ret();
    FUN_004134c0(uVar2);
    FEngPrintf();
  }
  FUN_004134c0(param_1 + 0xf8);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x104);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x10c);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x118);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x120);
  FEngPrintf();
  FUN_004134c0(param_1 + 300);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x134);
  FEngPrintf();
  FUN_004134c0(param_1 + 0x140);
  FEngPrintf();
  return;
}


// ==== 0x556210 FUN_00556210

undefined4 FUN_00556210(void)

{
  undefined4 in_stack_00000014;
  
  return in_stack_00000014;
}


// ==== 0x556220 FUN_00556220

float10 FUN_00556220(int param_1,int param_2)

{
  float10 fVar1;
  
  if (param_2 == 0) {
    fVar1 = (float10)0.0;
  }
  else {
    fVar1 = (float10)param_1 / (float10)param_2;
  }
  return fVar1;
}


// ==== 0x556250 FUN_00556250

void FUN_00556250(void)

{
  undefined4 uVar1;
  undefined1 local_94 [132];
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  local_8 = (int *)FUN_00549490();
  local_c = *local_8;
  FUN_004134c0();
  FEngQueueMessageToPackage();
  if ((local_c == 0) || (local_c == 0x75757372)) {
    if (*(char *)(DAT_00734f60 + 0x150) == '\x01') {
      FUN_0059fc00();
      uVar1 = FUN_005500a0();
      bSPrintf_regdst(0x80,local_94,uVar1);
      FUN_004134c0(0x911ab364,0);
      FUN_004ee3a0();
    }
    else {
      FUN_004134c0();
      FEngQueueMessageToPackage();
    }
    *(undefined1 *)(DAT_00734f60 + 0x149) = 0;
    *(undefined1 *)(DAT_00734f60 + 0x150) = 0;
    return;
  }
  local_10 = 0xe22c0b3a;
  if (local_c < 0x696e676e) {
    if (local_c == 0x696e676d) {
      return;
    }
    if (local_c == 0x61737461) {
      return;
    }
    if (local_c == 0x67687374) {
      local_10 = 0x6304ee20;
      goto LAB_005563c4;
    }
  }
  else {
    if (local_c == 0x74696d65) {
      local_10 = 0x9a4320bd;
      goto LAB_005563c4;
    }
    if (local_c == 0x7567616d) {
      local_10 = 0x48072fba;
      goto LAB_005563c4;
    }
  }
  FUN_0054d4a0(&DAT_0073d868,local_c);
LAB_005563c4:
  FUN_004134c0(0,0);
  FUN_004ee3a0();
  return;
}


// ==== 0x5563f0 FUN_005563f0

void FUN_005563f0(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00549490();
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    FUN_004134c0();
    FEngQueueMessageToPackage();
  }
  else {
    FUN_004134c0();
    FEngQueueMessageToPackage();
    FUN_0054d4a0(&DAT_0073d868,iVar1);
  }
  return;
}


// ==== 0x556460 FUN_00556460

void FUN_00556460(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  piVar2 = (int *)FUN_00549490();
  iVar1 = *piVar2;
  FUN_004134c0();
  FEngQueueMessageToPackage();
  if (iVar1 == 0) {
    FUN_004134c0(0xae8aa3b4);
    FUN_00495f00();
    FUN_004134c0(0xced06599);
    FUN_00495f00();
    DAT_00734f5c = 1;
    uVar3 = FUN_004134c0();
    FEngSetCurrentButton(uVar3);
    FUN_004134c0();
    FUN_00495f70();
    fVar4 = (float10)bTickerToSeconds();
    FUN_00424cd0(DAT_00734f60 + 0x14c,(float)(fVar4 + (float10)30.0));
  }
  else if (iVar1 == 0x696e676d) {
    FUN_004134c0();
    FEngQueueMessageToPackage();
  }
  else {
    FUN_0054d4a0(&DAT_0073d868,iVar1);
  }
  return;
}


// ==== 0x556580 FUN_00556580

void FUN_00556580(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00549490();
  iVar1 = *piVar2;
  FUN_004134c0();
  FEngQueueMessageToPackage();
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 < 0x696e676e) {
    if (((iVar1 == 0x696e676d) || (iVar1 == 0x616a6f69)) ||
       ((iVar1 == 0x61737461 || (iVar1 == 0x66756c6c)))) goto LAB_00556663;
  }
  else if (((iVar1 == 0x70617373) || (iVar1 == 0x74696d65)) || (iVar1 == 0x7567616d))
  goto LAB_00556663;
  FUN_0054d4a0(&DAT_0073d868,iVar1);
LAB_00556663:
  *(undefined1 *)(DAT_00734f60 + 0x149) = 0;
  FUN_004134c0(0x911ab364,0);
  FUN_004ee3a0();
  return;
}


// ==== 0x5566a0 FUN_005566a0

void FUN_005566a0(int param_1)

{
  float10 fVar1;
  
  if (param_1 == 0) {
    FUN_004134c0(0x911ab364,0);
    FUN_004ee3a0();
  }
  else if (param_1 == 1) {
    *(undefined1 *)(DAT_00734f60 + 0x149) = 0;
    FUN_004134c0(0);
    FEngSetControlMask();
    FUN_004134c0();
    FUN_004ebcb0();
    fVar1 = (float10)bTickerToSeconds();
    FUN_00424cd0(DAT_00734f60 + 0x154,(float)(fVar1 + (float10)15.0));
  }
  return;
}


// ==== 0x556750 FUN_00556750

undefined4 __fastcall FUN_00556750(undefined4 param_1)

{
  NullUpdate_ret();
  return param_1;
}


// ==== 0x556770 FUN_00556770

int FUN_00556770(void)

{
  undefined4 local_10;
  
  local_10 = FUN_00421960();
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -4;
  }
  return local_10;
}


// ==== 0x5567b0 FUN_005567b0

int FUN_005567b0(void)

{
  undefined4 local_10;
  
  local_10 = FUN_00417490();
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -4;
  }
  return local_10;
}


// ==== 0x5567e3 FUN_005567e3

void FUN_005567e3(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x5567f0 FUN_005567f0

void __fastcall FUN_005567f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_2c;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_006851aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  while (iVar1 = bList__IsEmpty(), iVar1 == 0) {
    iVar1 = bList__RemoveHead();
    if (iVar1 == 0) {
      local_2c = (undefined4 *)0x0;
    }
    else {
      local_2c = (undefined4 *)(iVar1 + -4);
    }
    if (local_2c != (undefined4 *)0x0) {
      (**(code **)*local_2c)(1);
    }
  }
  local_8 = 0xffffffff;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1);
  ExceptionList = local_10;
  return;
}


// ==== 0x556890 FUN_00556890

int FUN_00556890(void)

{
  undefined4 local_10;
  
  local_10 = NullUpdate_ret();
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -4;
  }
  return local_10;
}


// ==== 0x5568d0 FUN_005568d0

int FUN_005568d0(void)

{
  undefined4 local_18;
  
  local_18 = bList__AddTail();
  if (local_18 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = local_18 + -4;
  }
  return local_18;
}


// ==== 0x556910 FUN_00556910

int FUN_00556910(void)

{
  undefined4 local_18;
  
  local_18 = bList__RemoveHead();
  if (local_18 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = local_18 + -4;
  }
  return local_18;
}


// ==== 0x556950 FUN_00556950

void __fastcall FUN_00556950(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcda4;
  FUN_004f7b50();
  return;
}


// ==== 0x556960 FUN_00556960

void * __thiscall FUN_00556960(void *param_1,byte param_2)

{
  FUN_00556950();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x556980 FUN_00556980

undefined4 FUN_00556980(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688193;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005569e0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5569e0 FUN_005569e0

undefined4 * FUN_005569e0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006bcda4;
  local_4 = 0;
  if (DAT_00777b54 == 0) {
    FUN_00556d00();
  }
  else if (DAT_00777b54 == 1) {
    FUN_00556c10();
  }
  iVar1 = FEngFindPackage();
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x556a60 FUN_00556a60

void FUN_00556a60(int param_1,int param_2)

{
  if (param_1 == 0xc407210) {
    if (param_2 == 0) {
      return;
    }
    switch(*(undefined4 *)(param_2 + 0x10)) {
    case 0x81b573db:
      if (DAT_00777b54 != 0) {
        FEngQueueMessageToPackage();
        FUN_00556bc0();
        return;
      }
      break;
    case 0x81b573dc:
      if (DAT_00777b54 != 0) {
        FEngQueueMessageToPackage();
        FUN_00556bc0();
        return;
      }
      break;
    case 0x81b573dd:
      break;
    case 0x81b573de:
      if (DAT_00777b54 != 0) {
        FEngQueueMessageToPackage();
        FUN_00556bc0();
        return;
      }
      break;
    case 0x81b573df:
      break;
    case 0x81b573e0:
      break;
    default:
      goto switchD_00556ae5_default;
    }
    FEngQueueMessageToPackage();
  }
  else if (param_1 != -0x6ee54c9c) {
    if (param_1 != -0x367ca946) {
      return;
    }
    FEngQueueMessageToPackage();
    bSPrintf_regdst(0x20,"PlayersName_DATA");
    FEngPrintf("FOO-BAR",&DAT_00777c90);
    return;
  }
  FUN_00556bc0();
switchD_00556ae5_default:
  return;
}


// ==== 0x556bc0 FUN_00556bc0

void FUN_00556bc0(void)

{
  int iVar1;
  
  if (((DAT_0073578c != 0) && (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f09b0(*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEngFindPackage();
  *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  return;
}


// ==== 0x556c10 FUN_00556c10

void FUN_00556c10(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00777b58 == 0) {
    uVar1 = LanguageStrings_FindByRegionName(&DAT_00748f70);
    FEngPrintf(uVar1);
  }
  else {
    FEngPrintf(&DAT_00777c90);
  }
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  return;
}


// ==== 0x556d00 FUN_00556d00

void FUN_00556d00(void)

{
  int iVar1;
  
  if (DAT_00777b58 == 2) {
    FEngPrintf(&DAT_00777c90);
  }
  else {
    FEngPrintf(&DAT_00777c90);
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x556de0 FUN_00556de0

void __fastcall FUN_00556de0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcd68;
  FUN_004f7b50();
  return;
}


// ==== 0x556df0 FUN_00556df0

void * __thiscall FUN_00556df0(void *param_1,byte param_2)

{
  FUN_00556de0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x556e10 FUN_00556e10

undefined4 FUN_00556e10(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688da3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x4c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00556e70(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x556e70 FUN_00556e70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00556e70(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006bcd68;
  param_1[0x11] = 0;
  iVar2 = param_1[3];
  local_4 = 0;
  uVar1 = FEng__HashName();
  if (((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(uVar1), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  param_1[0x10] = iVar2;
  _DAT_00777cc0 = 4;
  iVar2 = RaceOptions_Get();
  if (*(int *)(iVar2 + 0x10) < 2) {
    *(undefined4 *)(iVar2 + 0x10) = 2;
  }
  if (10 < *(int *)(iVar2 + 0x10)) {
    *(undefined4 *)(iVar2 + 0x10) = 10;
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 &&
       (*(int *)(iVar3 + 0x18) != 0)))))) {
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
  if (DAT_0077b240 == 0) {
    FUN_004ebd60(0x6cfb8832);
    uVar1 = _ftol_nocw();
    param_1[0x11] = uVar1;
    param_1[0x12] = 0;
  }
  else {
    param_1[0x11] = 0;
    param_1[0x12] = 3;
  }
  DAT_00734f58 = param_1;
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x5570a0 FUN_005570a0

void __thiscall FUN_005570a0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(param_1 + 0x44);
  if ((iVar3 != 0) && (iVar3 != 0x7fffffff)) {
    if (DAT_0073ad3c < iVar3) {
      return;
    }
    *(undefined4 *)(param_1 + 0x48) = 1;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (param_2 < 0x911ab365) {
    if (param_2 == 0x911ab364) {
      local_8 = 0;
      local_4 = 0;
      local_24 = 0x7ab61b3f;
      local_20 = 0x639;
      local_1c = 0x22334455;
      local_18 = 0x541389e5;
      local_14 = 0;
      local_10 = 0;
      local_c = 0xb8a7c6cd;
      FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 == 0xc407210) {
      uVar1 = *(uint *)(param_3 + 0x10);
      if (uVar1 < 0x5932ca6a) {
        if (uVar1 == 0x5932ca69) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (uVar1 == 0x19de1c) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (uVar1 == 0x334e33af) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (uVar1 == 0x44172288) {
          DAT_0077b259 = 0;
          FUN_0054aa70();
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
      else {
        if ((uVar1 == 0x88e7a4ee) || (uVar1 == 0xd08e4c3a)) {
          DAT_0077b259 = 1;
          FUN_0054aa70();
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (uVar1 == 0xee360ed5) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
    }
    else {
      if (param_2 == 0x22334455) {
        FUN_0043a220(0);
        iVar3 = FEngFindPackage();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0xff;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x70d6a9cf) {
        cVar2 = FUN_004abf50();
        if (cVar2 != '\0') {
          FUN_00413520(*(undefined4 *)(param_1 + 0xc));
          FEngSetScript("Grayout",1);
          FEng__HashName();
          FEngSetCurrentButton(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        FEng__HashName();
        FEngSetCurrentButton(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
  }
  else if (param_2 == 0xabc08912) {
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0x5932ca6a) {
      if ((((uVar1 != 0x5932ca69) && (uVar1 != 0x19de1c)) && (uVar1 != 0x334e33af)) &&
         (uVar1 != 0x44172288)) {
        return;
      }
    }
    else if ((uVar1 != 0x88e7a4ee) && (uVar1 != 0xee360ed5)) {
      return;
    }
    FEString__SetLabelHash();
    FEObject__SetScript("FadeIn",1);
  }
  else if (param_2 == 0xc98356ba) {
    if (*(int *)(param_1 + 0x48) == 1) {
      if (DAT_0077b240 == 0) {
        FUN_0043ab70();
        if (DAT_0073d8d0 == 0) {
          FUN_00549700();
        }
        FUN_005498f0();
        return;
      }
    }
    else if ((*(int *)(param_1 + 0x48) == 2) && (iVar3 = FUN_005494b0(), 0 < iVar3)) {
      FUN_004ec3c0();
      FEngQueueMessageToPackage();
      *(undefined4 *)(param_1 + 0x48) = 3;
      return;
    }
  }
  return;
}


// ==== 0x557430 FUN_00557430

void FUN_00557430(void)

{
  if (DAT_0073d8e0 == 0) {
    *(undefined4 *)(DAT_00734f58 + 0x48) = 2;
    FUN_0054b310(&DAT_0073d868);
    return;
  }
  FUN_0054b1c0(&DAT_0073d868);
  return;
}


// ==== 0x557460 FUN_00557460

void __fastcall FUN_00557460(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcd44;
  FUN_004f7b50();
  return;
}


// ==== 0x557470 FUN_00557470

void FUN_00557470(void)

{
  return;
}


// ==== 0x557480 FUN_00557480

void * __thiscall FUN_00557480(void *param_1,byte param_2)

{
  FUN_00557460();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5574a0 FUN_005574a0

undefined4 * FUN_005574a0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687813;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006bcd44;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x557500 FUN_00557500

void __fastcall FUN_00557500(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcd20;
  FUN_004f7b50();
  return;
}


// ==== 0x557510 FUN_00557510

void * __thiscall FUN_00557510(void *param_1,byte param_2)

{
  FUN_00557500();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x557530 FUN_00557530

undefined4 FUN_00557530(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006877f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00557590(pvVar1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x557590 FUN_00557590

undefined4 * __thiscall FUN_00557590(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_2,param_1);
  *param_2 = &PTR_FUN_006bcd20;
  param_2[0x11] = 0;
  local_4 = 0;
  param_2[0x10] = *(undefined4 *)(param_1 + 4);
  if (param_2[3] != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_0055760d;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x8e801f01);
  }
LAB_0055760d:
  FEObject__SetInvisible(iVar1);
  uVar2 = _ftol_nocw();
  param_2[0x11] = uVar2;
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x557660 FUN_00557660

void FUN_00557660(int param_1)

{
  if ((param_1 == 0x406415e3) || (param_1 == -0x6ee54c9c)) {
    FEngQueueMessageToPackage();
  }
  return;
}


// ==== 0x557690 FUN_00557690

undefined4 FUN_00557690(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688173;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x54);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00557770(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5576f0 FUN_005576f0

void FUN_005576f0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_0054d590();
  iVar2 = FEngFindPackage();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0xff;
  }
  puVar3 = &DAT_00735468;
  for (iVar2 = 0x19; iVar1 = DAT_0073578c, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  DAT_007354cc = 0;
  if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x557760 FUN_00557760

void FUN_00557760(void)

{
  DAT_00734dbc = 0;
  FUN_005576f0();
  return;
}


// ==== 0x557770 FUN_00557770

undefined4 * FUN_00557770(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006bcae4;
  FUN_0054d590();
  pcVar2 = (char *)param_1[3];
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  iVar6 = param_1[3];
  uVar5 = FEng__HashName();
  if (((((iVar6 == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
       (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
      ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
     (*(int *)(iVar6 + 0x18) != 2)) {
    iVar6 = 0;
  }
  param_1[0x10] = iVar6;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  FUN_00495f00(0x353f3237);
  if (DAT_00734f54 == '\0') {
    uVar5 = 0x2c119933;
  }
  else {
    uVar5 = 0x6571a9e1;
  }
  FUN_00495f00(uVar5);
  if (DAT_0073578c != 0) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  FUN_00558000(param_1);
  FUN_00558000(param_1);
  FUN_00558000(param_1);
  if (DAT_007354cc == '\0') {
    puVar7 = &DAT_00735468;
    for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    ProBlob__Read(&DAT_0078a478,&DAT_00735468);
    FUN_00558080(param_1);
  }
  else if (DAT_00734fc4 < 1) {
    FUN_005580d0(param_1);
  }
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  if (((param_1[3] == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
     (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
    if (DAT_0073578c == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004ef050(0xaa68bfce);
    }
  }
  param_1[0x12] = iVar6;
  if (((param_1[3] == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
     (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
    if (DAT_0073578c == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004ef050(0xaa68bfd4);
    }
  }
  param_1[0x13] = iVar6;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
    if ((DAT_0073578c == 0) || (iVar3 = *(int *)(DAT_0073578c + 8), iVar3 == 0)) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004fd1e0(iVar3 + 0xdc);
      if (iVar6 == 0) {
        iVar6 = FUN_004fd1e0(iVar3 + 0xec);
      }
    }
  }
  param_1[0x14] = iVar6;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x557a00 FUN_00557a00

void * __thiscall FUN_00557a00(void *param_1,byte param_2)

{
  FUN_00557a20();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x557a20 FUN_00557a20

void __fastcall FUN_00557a20(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bcae4;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x557a40 FUN_00557a40

void __thiscall FUN_00557a40(int param_1,uint param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  HINSTANCE pHVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  undefined4 local_3f4;
  CHAR local_3f0;
  undefined4 local_3ef;
  
  if (param_2 < 0x26eadf70) {
    if (param_2 == 0x26eadf6f) {
      FUN_00558220();
      return;
    }
    if (param_2 < 0x12bd8a3) {
      if (param_2 == 0x12bd8a2) {
        local_3f0 = '\0';
        puVar10 = &local_3ef;
        for (iVar9 = 0xf9; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        *(undefined2 *)puVar10 = 0;
        *(undefined1 *)((int)puVar10 + 2) = 0;
        FUN_005582d0(1000);
        pHVar5 = ShellExecuteA((HWND)0x0,"open",&local_3f0,(LPCSTR)0x0,(LPCSTR)0x0,1);
        if ((int)pHVar5 < 0x21) {
          FUN_004ee3a0(100,0);
          return;
        }
        DAT_00736124 = 1;
        return;
      }
      if ((param_2 == 100) || (param_2 == 0x12bd766)) {
        DAT_00734dbc = 0;
LAB_00557a8d:
        FUN_005576f0();
        return;
      }
    }
    else if (param_2 == 0xc407210) {
      iVar9 = *(int *)(param_3 + 0x10);
      if (iVar9 == 0x448e93e0) {
        if (*(char *)(param_1 + 0x46) != '\0') {
          FUN_004ad730();
          FEngSwitchPackages(&DAT_00734bc8);
          return;
        }
      }
      else if (iVar9 == 0x5e4efa1b) {
        if ((*(char *)(param_1 + 0x44) != '\0') && (cVar3 = FUN_00558260(param_1), cVar3 != '\0')) {
          FUN_004ebcb0();
          FUN_0054d8b0(&DAT_007346d8,&DAT_007346f8,FUN_00558110);
          return;
        }
      }
      else if (((iVar9 == -0x4255a42e) && (*(char *)(param_1 + 0x45) != '\0')) &&
              (cVar3 = FUN_00558260(param_1), cVar3 != '\0')) {
        FEngSwitchPackages(&DAT_00734bc8);
        return;
      }
    }
    else if (param_2 == 0x1234babe) {
      FUN_005576f0();
      return;
    }
  }
  else if (param_2 < 0xabc08913) {
    if (param_2 == 0xabc08912) {
      if ((param_3 != 0) &&
         (((iVar9 = *(int *)(param_3 + 0x10), iVar9 == 0x448e93e0 || (iVar9 == 0x5e4efa1b)) ||
          (iVar9 == -0x4255a42e)))) {
        FEString__SetLabelHash();
        FEObject__SetScript("FadeIn",1);
        return;
      }
    }
    else {
      if (param_2 == 0x4c7b3797) {
        FUN_00558080(param_1);
        return;
      }
      if (param_2 == 0x911ab364) {
        if (0 < DAT_00734fc4) {
          local_3f8 = 0;
          local_3f4 = 0;
          local_404 = 0;
          local_400 = 0;
          local_414 = 0x7ab61b3f;
          local_410 = 0x639;
          local_40c = 0x1234babe;
          local_408 = 0x541389e5;
          local_3fc = 0xb8a7c6cd;
          FUN_004dc6e0(&local_414,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        goto LAB_00557a8d;
      }
    }
  }
  else if (param_2 == 0xc519bfc0) {
    pcVar1 = *(char **)(param_1 + 0xc);
    DAT_00777c30 = *pcVar1;
    if (DAT_00777c30 != '\0') {
      pcVar8 = &DAT_00777c30;
      do {
        cVar3 = (pcVar1 + -0x777c2f)[(int)pcVar8];
        pcVar8 = pcVar8 + 1;
        *pcVar8 = cVar3;
      } while (cVar3 != '\0');
    }
    FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
  }
  else if (param_2 == 0xc98356ba) {
    FUN_0054d630();
    iVar9 = DAT_00734fc4;
    if (((DAT_007354cc == '\0') || (DAT_00734fc4 < 1)) || (iVar6 = bStrLen(), iVar6 < 1)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    cVar2 = DAT_007354cc;
    bVar11 = DAT_007354cc == '\0';
    *(char *)(param_1 + 0x44) = cVar3;
    if ((bVar11) || (iVar9 < 1)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    *(undefined1 *)(param_1 + 0x45) = uVar4;
    if ((cVar2 == '\0') || (iVar9 < 1)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    *(undefined1 *)(param_1 + 0x46) = uVar4;
    if (cVar3 != '\0') {
      local_3f0 = '\0';
      puVar10 = &local_3ef;
      for (iVar9 = 0x7c; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined2 *)puVar10 = 0;
      *(undefined1 *)((int)puVar10 + 2) = 0;
      uVar7 = FUN_0059fc40(&DAT_007346d8);
      FUN_00565da0("%s %s",uVar7);
      FEngPrintf(&local_3f0);
    }
    FUN_00558000(param_1);
    FUN_00558000(param_1);
    FUN_00558000(param_1);
    iVar9 = FEngGetCurrentButton(&DAT_00734bc8);
    if ((((*(int *)(iVar9 + 0x10) == 0x5e4efa1b) && (*(char *)(param_1 + 0x44) == '\0')) &&
        (*(char *)(param_1 + 0x46) != '\0')) && (DAT_0073578c != 0)) {
      cFEng__SetCurrentButton(DAT_0073578c);
    }
    FUN_00557e90(param_1);
    return;
  }
  return;
}


// ==== 0x557e90 FUN_00557e90

void FUN_00557e90(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_1;
  piVar6 = (int *)(param_1 + 0x48);
  param_1 = 2;
  do {
    if ((*piVar6 != 0) && (DAT_007064b2 != '\0')) {
      cVar3 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar3 != '\0') &&
         ((*(int *)(*piVar6 + 0x10) == -0x55974032 || (*(int *)(*piVar6 + 0x10) == -0x5597402c)))) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          if (iVar4 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(iVar4 + 0x18);
          }
          iVar4 = 0;
          if (iVar5 != 0) {
            iVar4 = *(int *)(iVar5 + 0x80);
          }
        }
        if (*(int *)(iVar4 + 0x10) == -0x67f8bfae) {
          uVar1 = *(undefined4 *)(*piVar6 + 0x10);
          if (*(int *)(iVar2 + 0xc) == 0) {
LAB_00557f75:
            if (DAT_0073578c != 0) {
              iVar4 = FUN_004ef050(uVar1);
              goto LAB_00557f89;
            }
          }
          else {
            iVar4 = FEngFindPackage();
            if (iVar4 == 0) goto LAB_00557f75;
            iVar4 = FUN_004ffb70();
            if (iVar4 == 0) goto LAB_00557f75;
LAB_00557f89:
            if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
              FUN_004f0700(0xc407210,*piVar6,*(undefined4 *)(iVar2 + 0x50),iVar4,0);
            }
          }
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) &&
             (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
            (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x26eadf6f,0,0,*(int *)(iVar4 + 0x18));
          }
        }
      }
    }
    piVar6 = piVar6 + 1;
    param_1 = param_1 + -1;
    if (param_1 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x558000 FUN_00558000

void FUN_00558000(void)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 unaff_EBX;
  
  iVar2 = FEngFindPackage();
  if ((iVar2 == 0) || (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(in_EAX);
    }
  }
  iVar1 = DAT_0073578c;
  if ((char)unaff_EBX == '\0') {
    FEObject__SetInvisible(iVar2);
  }
  else {
    FEObject__SetVisible();
  }
  if (iVar1 != 0) {
    cFEng__SetButtonState(iVar1,unaff_EBX);
  }
  return;
}


// ==== 0x558080 FUN_00558080

void FUN_00558080(void)

{
  char cVar1;
  
  FUN_005491c0();
  cVar1 = FUN_0054d4e0();
  if (cVar1 != '\0') {
    FUN_004ebd60(0x6cfb8832);
    return;
  }
  FUN_004eba00(100,0);
  return;
}


// ==== 0x5580d0 FUN_005580d0

void FUN_005580d0(void)

{
  char cVar1;
  
  cVar1 = FUN_0054d4e0();
  if (cVar1 != '\0') {
    FUN_004ebd60(0x6cfb8832);
    return;
  }
  FUN_004eba00(100,0);
  return;
}


// ==== 0x558110 FUN_00558110

void FUN_00558110(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00735da4 != 0) {
    FUN_004ebdf0(DAT_00735da4,0);
  }
  iVar1 = DAT_0073578c;
  if (DAT_00734f84 == 0) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x18) == 0) {
      return;
    }
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    return;
  }
  if (DAT_00734f84 < 0x6c6f636c) {
    if (DAT_00734f84 == 0x6c6f636b) goto LAB_00558203;
    if (DAT_00734f84 < 0x66696c75) {
      if (((DAT_00734f84 == 0x66696c74) || (DAT_00734f84 == 0x626c616b)) ||
         (DAT_00734f84 == 0x64626572)) goto LAB_00558203;
    }
    else if (DAT_00734f84 == 0x696d7374) goto LAB_00558203;
  }
  else if (DAT_00734f84 < 0x72737277) {
    if (((DAT_00734f84 == 0x72737276) || (DAT_00734f84 == 0x6c6f676e)) ||
       (DAT_00734f84 == 0x70617373)) goto LAB_00558203;
  }
  else if (DAT_00734f84 == 0x74696d65) goto LAB_00558203;
  FUN_0054d4a0(&DAT_0073d868,DAT_00734f84);
LAB_00558203:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x558220 FUN_00558220

void FUN_00558220(void)

{
  DAT_00734f54 = DAT_00734f54 ^ 1;
  if (DAT_00734f54 != 0) {
    FUN_00495f00(0x6571a9e1);
    return;
  }
  FUN_00495f00(0x2c119933);
  return;
}


// ==== 0x558260 FUN_00558260

uint FUN_00558260(void)

{
  uint uVar1;
  
  if (DAT_00734f54 == '\0') {
    uVar1 = FUN_004eb950(0,0x18ed8cac,0x9c7511d8,0x8c35f7e5,0x4e2e9a00,0,0x639,0);
    return uVar1 & 0xffffff00;
  }
  return 1;
}


// ==== 0x5582d0 FUN_005582d0

void FUN_005582d0(void)

{
  switch(DAT_00734998) {
  case 0:
    bStrCpy();
    return;
  case 1:
    switch(DAT_006ee6f0) {
    case 0:
      bStrCpy();
      return;
    case 1:
      bStrCpy();
      return;
    case 2:
      bStrCpy();
      return;
    case 3:
      bStrCpy();
      return;
    case 4:
      bStrCpy();
      return;
    case 5:
      bStrCpy();
      return;
    case 6:
      bStrCpy();
      return;
    }
    break;
  case 2:
    bStrCpy();
    return;
  case 4:
    bStrCpy();
    return;
  }
  return;
}


// ==== 0x558390 FUN_00558390

undefined4 FUN_00558390(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006877d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005583f0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5583f0 FUN_005583f0

undefined4 * FUN_005583f0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006877ad;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  pcVar2 = (char *)param_1[3];
  *param_1 = &PTR_FUN_006bca48;
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  local_4 = 0;
  *param_1 = &PTR_FUN_006bcab4;
  FEMenuData__FEMenuData();
  local_4._0_1_ = 1;
  FEMenuData__FEMenuData();
  local_4._0_1_ = 2;
  FEMenuData__FEMenuData();
  local_4._0_1_ = 3;
  FEMenuData__FEMenuData();
  local_4 = CONCAT31(local_4._1_3_,4);
  param_1[0x10] = &DAT_007787b4;
  FUN_005591a0();
  pcVar2 = (char *)param_1[3];
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(param_1 + 8) = 1;
  piVar6 = param_1 + 0x11;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d5);
    }
  }
  param_1[0x11] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d4);
    }
  }
  param_1[0x12] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef8f);
    }
  }
  param_1[0x13] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef8e);
    }
  }
  param_1[0x14] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x70355aa6);
    }
  }
  param_1[0x15] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x70355aa7);
    }
  }
  param_1[0x16] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x70355aa8);
    }
  }
  param_1[0x17] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x70355aa9);
    }
  }
  param_1[0x18] = iVar5;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) &&
     (iVar5 = 0, DAT_0073578c != 0)) {
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
  param_1[0x19] = iVar5;
  FUN_0041f160(0x854bc1d8,0,0,0x10);
  FUN_0041f160(0x58f820ab,0,0,0x10);
  FUN_0041f160(0x917e8df9,0,0,0x10);
  FUN_0041f160(0x43225720,0,0,0x32);
  param_1[0x96] = 0x4c7b3797;
  param_1[0x98] = 0x1ff2aa3b;
  param_1[0x118] = 0x6659468a;
  param_1[0x11a] = 0x2ee3bb4c;
  param_1[0x19a] = 0xed17e1e5;
  param_1[0x19c] = 0x3dd4cc5d;
  param_1[0x21c] = 0x812d3edf;
  param_1[0x21e] = 0x4cc5dd6e;
  param_1[0x97] = 0xceffd44;
  param_1[0x119] = 0xceffd44;
  param_1[0x19b] = 0xceffd44;
  param_1[0x21d] = 0xceffd44;
  *(undefined1 *)((int)param_1 + 0x475) = 1;
  DAT_007363b2 = 1;
  *(undefined1 *)((int)param_1 + 0x67d) = 1;
  if (param_1[3] == 0) {
LAB_005588c3:
    if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0x854bc1d8), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) == 2)) {
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x20;
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00558887:
      local_4._0_1_ = 5;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,4);
      goto LAB_005588c3;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_005588c3;
      goto LAB_00558887;
    }
  }
  if (param_1[3] == 0) {
LAB_0055898c:
    if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0x58f820ab), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) == 2)) {
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x20;
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00558950:
      local_4._0_1_ = 6;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,4);
      goto LAB_0055898c;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_0055898c;
      goto LAB_00558950;
    }
  }
  if (param_1[3] == 0) {
LAB_00558a52:
    if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0x917e8df9), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) == 2)) {
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x20;
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00558a16:
      local_4._0_1_ = 7;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,4);
      goto LAB_00558a52;
    }
    if (DAT_0073578c != 0) {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00558a52;
      goto LAB_00558a16;
    }
  }
  if (param_1[3] != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
      if (DAT_0073578c == 0) goto LAB_00558b40;
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_00558b1a;
    }
    local_4._0_1_ = 8;
    FUN_004ffb00(iVar5);
    local_4 = CONCAT31(local_4._1_3_,4);
  }
LAB_00558b1a:
  if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0x43225720), iVar5 != 0)) &&
     (*(int *)(iVar5 + 0x18) == 2)) {
    *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x20;
  }
LAB_00558b40:
  *(undefined1 *)(param_1 + 0x222) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x558b60 FUN_00558b60

void * __thiscall FUN_00558b60(void *param_1,byte param_2)

{
  FUN_00558b80(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x558b80 FUN_00558b80

void FUN_00558b80(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0068773f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bcab4;
  local_4 = 3;
  DAT_00734bc8 = 0;
  eh_vector_destructor_iterator(param_1 + 0x1a4,0xc,0x20,WString_Free);
  local_4._0_1_ = 2;
  eh_vector_destructor_iterator(param_1 + 0x122,0xc,0x20,WString_Free);
  local_4._0_1_ = 1;
  eh_vector_destructor_iterator(param_1 + 0xa0,0xc,0x20,WString_Free);
  local_4 = (uint)local_4._1_3_ << 8;
  eh_vector_destructor_iterator(param_1 + 0x1e,0xc,0x20,WString_Free);
  *param_1 = &PTR_FUN_006bca48;
  local_4 = 0xffffffff;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x558c40 FUN_00558c40

void __thiscall
FUN_00558c40(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  cVar1 = FUN_0041f240(param_3,param_4,param_5);
  if ((((cVar1 == '\0') && (cVar1 = FUN_0041f240(param_3,param_4,param_5), cVar1 == '\0')) &&
      (cVar1 = FUN_0041f240(param_3,param_4,param_5), cVar1 == '\0')) &&
     (cVar1 = FUN_0041f240(param_3,param_4,param_5), cVar1 == '\0')) {
    if (param_2 < 0x4cc5dd6f) {
      if (param_2 == 0x4cc5dd6e) {
        puVar3 = (undefined4 *)(param_1[0x10] + 0x33);
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined2 *)puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 2) = 0;
        (**(code **)(*param_1 + 0x10))();
        return;
      }
      if (param_2 < 0x2ee3bb4d) {
        if (param_2 != 0x2ee3bb4c) {
          if (0x1ff2aa3b < param_2) {
            if (param_2 != 0x20dd363e) {
              return;
            }
            *(byte *)(param_1[0x10] + 0xcc) = *(byte *)(param_1[0x10] + 0xcc) ^ 1;
            (**(code **)(*param_1 + 0x10))();
            return;
          }
          if (param_2 == 0x1ff2aa3b) {
            puVar3 = (undefined4 *)param_1[0x10];
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = 0;
            *(undefined1 *)(puVar3 + 4) = 0;
            (**(code **)(*param_1 + 0x10))();
            return;
          }
          if (param_2 == 0xbc13539) {
            DAT_0070108e = 0;
            FUN_0041f4d0();
            return;
          }
          if (param_2 != 0xc5c60f9) {
            return;
          }
          *(byte *)(param_1[0x10] + 0xcd) = *(byte *)(param_1[0x10] + 0xcd) ^ 1;
          (**(code **)(*param_1 + 0x10))();
          return;
        }
        puVar3 = (undefined4 *)(param_1[0x10] + 0x11);
      }
      else {
        if (0x406415e3 < param_2) {
          if (param_2 != 0x4c7b3797) {
            return;
          }
          puVar3 = (undefined4 *)param_1[0x10];
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          *(undefined1 *)(puVar3 + 4) = 0;
          pcVar2 = (char *)param_1[0x10];
          iVar4 = 0x10;
          iVar5 = (int)&DAT_00777b74 - (int)pcVar2;
          do {
            cVar1 = pcVar2[iVar5];
            iVar4 = iVar4 + -1;
            *pcVar2 = cVar1;
            if (cVar1 == '\0') break;
            pcVar2 = pcVar2 + 1;
          } while (iVar4 != 0);
          (**(code **)(*param_1 + 0x10))();
          return;
        }
        if (param_2 == 0x406415e3) {
          cVar1 = FUN_005594b0();
          if (cVar1 == '\0') {
            return;
          }
          FEngSwitchPackages(param_1[3]);
          return;
        }
        if (param_2 == 0x35f8620b) {
          *(undefined1 *)(param_1 + 0x222) = 1;
          return;
        }
        if (param_2 != 0x3dd4cc5d) {
          return;
        }
        puVar3 = (undefined4 *)(param_1[0x10] + 0x22);
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      *(undefined1 *)(puVar3 + 4) = 0;
LAB_00558dc8:
      (**(code **)(*param_1 + 0x10))();
      return;
    }
    if (param_2 < 0xb944c7b2) {
      if (param_2 == 0xb944c7b1) {
        DAT_0070108e = 1;
        FUN_0041f4d0();
        return;
      }
      if (param_2 < 0x82b8e235) {
        if (param_2 == 0x82b8e234) {
          DAT_0070108e = 1;
          FUN_0041f4d0();
          return;
        }
        if (param_2 == 0x6659468a) {
          iVar4 = param_1[0x10];
          *(undefined4 *)(iVar4 + 0x11) = 0;
          *(undefined4 *)(iVar4 + 0x15) = 0;
          *(undefined4 *)(iVar4 + 0x19) = 0;
          *(undefined4 *)(iVar4 + 0x1d) = 0;
          *(undefined1 *)(iVar4 + 0x21) = 0;
          pcVar2 = (char *)(param_1[0x10] + 0x11);
          iVar4 = 0x10;
          iVar5 = (int)&DAT_00777b74 - (int)pcVar2;
          do {
            cVar1 = pcVar2[iVar5];
            iVar4 = iVar4 + -1;
            *pcVar2 = cVar1;
            if (cVar1 == '\0') break;
            pcVar2 = pcVar2 + 1;
          } while (iVar4 != 0);
          (**(code **)(*param_1 + 0x10))();
          return;
        }
        if (param_2 == 0x812d3edf) {
          puVar3 = (undefined4 *)(param_1[0x10] + 0x33);
          for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
          }
          *(undefined2 *)puVar3 = 0;
          *(undefined1 *)((int)puVar3 + 2) = 0;
          pcVar2 = (char *)(param_1[0x10] + 0x33);
          iVar4 = 0x32;
          iVar5 = (int)&DAT_00777b74 - (int)pcVar2;
          do {
            cVar1 = pcVar2[iVar5];
            iVar4 = iVar4 + -1;
            *pcVar2 = cVar1;
            if (cVar1 == '\0') break;
            pcVar2 = pcVar2 + 1;
          } while (iVar4 != 0);
          (**(code **)(*param_1 + 0x10))();
          return;
        }
      }
      else if (param_2 == 0x911ab364) {
        FEngSwitchPackages(param_1[3]);
        return;
      }
    }
    else {
      if (param_2 != 0xc98356ba) {
        if (param_2 == 0xd322d6a4) {
          DAT_0070108e = 1;
          FUN_0041f4d0();
          return;
        }
        if (param_2 != 0xed17e1e5) {
          return;
        }
        iVar4 = param_1[0x10];
        *(undefined4 *)(iVar4 + 0x22) = 0;
        *(undefined4 *)(iVar4 + 0x26) = 0;
        *(undefined4 *)(iVar4 + 0x2a) = 0;
        *(undefined4 *)(iVar4 + 0x2e) = 0;
        *(undefined1 *)(iVar4 + 0x32) = 0;
        pcVar2 = (char *)(param_1[0x10] + 0x22);
        iVar4 = 0x10;
        iVar5 = (int)&DAT_00777b74 - (int)pcVar2;
        while( true ) {
          cVar1 = pcVar2[iVar5];
          iVar4 = iVar4 + -1;
          *pcVar2 = cVar1;
          if (cVar1 == '\0') break;
          pcVar2 = pcVar2 + 1;
          if (iVar4 == 0) {
            (**(code **)(*param_1 + 0x10))();
            return;
          }
        }
        goto LAB_00558dc8;
      }
      FUN_00559030();
      FUN_0054d630();
    }
  }
  return;
}


// ==== 0x559030 FUN_00559030

void FUN_00559030(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int *piVar5;
  int local_8;
  
  if (*(char *)(unaff_EBX + 0x888) != '\0') {
    piVar5 = (int *)(unaff_EBX + 0x44);
    local_8 = 8;
    do {
      if ((*piVar5 != 0) && (cVar2 = FUN_004f7eb0(unaff_EBX), cVar2 != '\0')) {
        uVar1 = *(uint *)(*piVar5 + 0x10);
        if (uVar1 < 0xda96ef8f) {
          if (uVar1 == 0xda96ef8e) {
LAB_00559133:
            uVar3 = *(undefined4 *)(unaff_EBX + 100);
            uVar4 = FEngFindObject();
            if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
              FUN_004f0700(0x9120409e,*piVar5,uVar3,uVar4,0);
            }
          }
          else {
            switch(uVar1) {
            case 0x70355aa6:
              break;
            case 0x70355aa7:
              break;
            case 0x70355aa8:
              break;
            case 0x70355aa9:
              break;
            default:
              goto switchD_00559086_default;
            }
            uVar3 = FEngFindObject();
            FEngSendMessageToObject(0xc407210,uVar3);
          }
        }
        else {
          if (uVar1 == 0xda96ef8f) goto LAB_00559133;
          if (uVar1 == 0xda9a39d4) {
            uVar3 = FEngFindObject();
            FEngSendMessageToObject(0xb5971bf1,uVar3);
          }
          else if (uVar1 == 0xda9a39d5) {
            uVar3 = FEngFindObject();
            FEngSendMessageToObject(0xb5971bf1,uVar3);
          }
        }
      }
switchD_00559086_default:
      piVar5 = piVar5 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


// ==== 0x5591a0 FUN_005591a0

void __fastcall FUN_005591a0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char local_14 [20];
  
  pcVar3 = *(char **)(param_1 + 0x40);
  iVar2 = 0;
  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
LAB_005591c3:
    FUN_00495f00(0xceffd44);
  }
  else {
    do {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (pcVar3[iVar4] != '\0');
    if (iVar2 == 0) goto LAB_005591c3;
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x854bc1d8);
      }
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
    FUN_0041f060(iVar2,pcVar3);
  }
  local_14[0] = '\0';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[4] = '\0';
  local_14[5] = '\0';
  local_14[6] = '\0';
  local_14[7] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  local_14[0x10] = 0;
  pcVar3 = (char *)(*(int *)(param_1 + 0x40) + 0x11);
  iVar2 = 0;
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[iVar4];
    }
  }
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      if (iVar4 == 0xf) break;
      local_14[iVar4] = '*';
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  local_14[iVar4] = '\0';
  iVar2 = 0;
  if (local_14[0] == '\0') {
LAB_0055928d:
    FUN_00495f00(0xceffd44);
  }
  else {
    do {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (local_14[iVar4] != '\0');
    if (iVar2 == 0) goto LAB_0055928d;
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x58f820ab);
      }
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
    FUN_0041f060(iVar2,local_14);
  }
  pcVar3 = (char *)(*(int *)(param_1 + 0x40) + 0x22);
  local_14[0] = '\0';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[4] = '\0';
  local_14[5] = '\0';
  local_14[6] = '\0';
  local_14[7] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  local_14[0x10] = 0;
  iVar2 = 0;
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar3[iVar4];
    }
  }
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      if (iVar4 == 0xf) break;
      local_14[iVar4] = '*';
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  local_14[iVar4] = '\0';
  iVar2 = 0;
  if (local_14[0] == '\0') {
LAB_0055935d:
    FUN_00495f00(0xceffd44);
  }
  else {
    do {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (local_14[iVar4] != '\0');
    if (iVar2 == 0) goto LAB_0055935d;
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x917e8df9);
      }
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
    FUN_0041f060(iVar2,local_14);
  }
  pcVar3 = (char *)(*(int *)(param_1 + 0x40) + 0x33);
  iVar2 = 0;
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    do {
      iVar4 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (pcVar3[iVar4] != '\0');
    if (iVar2 != 0) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
         (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
        if (DAT_0073578c == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_004ef050(0x43225720);
        }
      }
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
      FUN_0041f060(iVar2,pcVar3);
      goto LAB_0055944a;
    }
  }
  FUN_00495f00(0xceffd44);
LAB_0055944a:
  if (*(char *)(*(int *)(param_1 + 0x40) + 0xcd) == '\0') {
    uVar5 = 0x61c;
  }
  else {
    uVar5 = 0xf770;
  }
  FUN_00495f00(uVar5);
  if (*(char *)(*(int *)(param_1 + 0x40) + 0xcc) == '\0') {
    FUN_00495f00(0x61c);
    return;
  }
  FUN_00495f00(0xf770);
  return;
}


// ==== 0x5594b0 FUN_005594b0

bool FUN_005594b0(void)

{
  char cVar1;
  undefined4 in_EAX;
  
  cVar1 = FUN_005594e0();
  if (cVar1 != '\0') {
    cVar1 = FUN_00559560();
    if (cVar1 != '\0') {
      cVar1 = FUN_005595f0(in_EAX);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== 0x5594e0 FUN_005594e0

uint FUN_005594e0(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  
  pcVar2 = *(char **)(unaff_ESI + 0x40);
  iVar3 = 0;
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    do {
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while (pcVar2[iVar1] != '\0');
    if ((3 < iVar3) && (iVar3 < 0x11)) {
      return CONCAT31((int3)((uint)iVar3 >> 8),1);
    }
  }
  uVar4 = FUN_004eb950();
  return uVar4 & 0xffffff00;
}


// ==== 0x559560 FUN_00559560

uint FUN_00559560(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  
  pcVar1 = (char *)(*(int *)(unaff_ESI + 0x40) + 0x11);
  iVar2 = 0;
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    do {
      iVar2 = iVar2 + 1;
    } while (pcVar1[iVar2] != '\0');
    if (((3 < iVar2) && (iVar2 < 0x11)) && (iVar2 = bStrCmp(), iVar2 == 0)) {
      return 1;
    }
  }
  uVar3 = FUN_004eb950();
  return uVar3 & 0xffffff00;
}


// ==== 0x5595f0 FUN_005595f0

uint FUN_005595f0(int param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  iVar2 = *(int *)(param_1 + 0x40);
  pcVar7 = (char *)(iVar2 + 0x33);
  iVar4 = 0;
  if (pcVar7 != (char *)0x0) {
    cVar1 = *pcVar7;
    while (cVar1 != '\0') {
      iVar6 = iVar4 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = pcVar7[iVar6];
    }
  }
  bVar3 = false;
  if ((iVar4 < 6) || (0x32 < iVar4)) goto LAB_00559683;
  iVar6 = 0;
  if (0 < iVar4) {
    pcVar7 = (char *)(iVar2 + 0x34);
    do {
      if ((((pcVar7[-1] == '@') && (iVar6 != 0)) && (iVar6 < iVar4 + -3)) && (*pcVar7 != '.')) {
        if (iVar6 < iVar4) {
          pcVar7 = (char *)(iVar2 + 0x33 + iVar6);
          goto LAB_00559658;
        }
        break;
      }
      iVar6 = iVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (iVar6 < iVar4);
  }
  goto LAB_00559672;
  while( true ) {
    iVar6 = iVar6 + 1;
    pcVar7 = pcVar7 + 1;
    if (iVar4 <= iVar6) break;
LAB_00559658:
    if ((*pcVar7 == '.') && (iVar6 < iVar4 + -1)) {
      bVar3 = true;
      break;
    }
  }
LAB_00559672:
  if (bVar3) {
    return CONCAT31((int3)((uint)iVar4 >> 8),1);
  }
LAB_00559683:
  uVar5 = FUN_004eb950();
  return uVar5 & 0xffffff00;
}


// ==== 0x5596e0 FUN_005596e0

undefined4 FUN_005596e0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688153;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x7c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00559740(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x559740 FUN_00559740

undefined4 * FUN_00559740(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688128;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  pcVar2 = (char *)param_1[3];
  *param_1 = &PTR_FUN_006bca48;
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  local_4 = 0;
  *param_1 = &PTR_FUN_006bca84;
  param_1[0x10] = &DAT_007787b4;
  FUN_0055a200();
  pcVar2 = (char *)param_1[3];
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  piVar6 = param_1 + 0x12;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  if (param_1[3] == 0) {
LAB_00559807:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef93);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559807;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559807;
  }
  param_1[0x12] = iVar5;
  if (param_1[3] == 0) {
LAB_00559848:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d9);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559848;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559848;
  }
  param_1[0x13] = iVar5;
  if (param_1[3] == 0) {
LAB_00559889:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef92);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559889;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559889;
  }
  param_1[0x14] = iVar5;
  if (param_1[3] == 0) {
LAB_005598ca:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d8);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_005598ca;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_005598ca;
  }
  param_1[0x15] = iVar5;
  if (param_1[3] == 0) {
LAB_0055990b:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef91);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_0055990b;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_0055990b;
  }
  param_1[0x16] = iVar5;
  if (param_1[3] == 0) {
LAB_0055994c:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d7);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_0055994c;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_0055994c;
  }
  param_1[0x17] = iVar5;
  if (param_1[3] == 0) {
LAB_0055998d:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef90);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_0055998d;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_0055998d;
  }
  param_1[0x18] = iVar5;
  if (param_1[3] == 0) {
LAB_005599ce:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d6);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_005599ce;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_005599ce;
  }
  param_1[0x19] = iVar5;
  if (param_1[3] == 0) {
LAB_00559a0f:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d5);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559a0f;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559a0f;
  }
  param_1[0x1a] = iVar5;
  if (param_1[3] == 0) {
LAB_00559a50:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda96ef8f);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559a50;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559a50;
  }
  param_1[0x1b] = iVar5;
  if (param_1[3] == 0) {
LAB_00559a91:
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xda9a39d4);
    }
  }
  else {
    iVar5 = FEngFindPackage();
    if (iVar5 == 0) goto LAB_00559a91;
    iVar5 = FUN_004ffb70();
    if (iVar5 == 0) goto LAB_00559a91;
  }
  param_1[0x1c] = iVar5;
  if (param_1[3] != 0) {
    iVar5 = FEngFindPackage();
    if (iVar5 != 0) {
      iVar5 = FUN_004ffb70();
      if (iVar5 != 0) goto LAB_00559aee;
    }
  }
  if (DAT_0073578c == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_004ef050(0xda96ef8e);
  }
LAB_00559aee:
  param_1[0x1d] = iVar5;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
    if ((DAT_0073578c == 0) || (iVar3 = *(int *)(DAT_0073578c + 8), iVar3 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004fd1e0(iVar3 + 0xdc);
      if (iVar5 == 0) {
        iVar5 = FUN_004fd1e0(iVar3 + 0xec);
      }
    }
  }
  param_1[0x1e] = iVar5;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x559b60 FUN_00559b60

void FUN_00559b60(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  int *piVar5;
  undefined4 uVar6;
  int local_8;
  
  piVar5 = (int *)(unaff_EBX + 0x48);
  local_8 = 0xc;
  do {
    if (((*piVar5 == 0) || (DAT_007064b2 == '\0')) ||
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 == '\0')) goto switchD_00559bee_default;
    uVar1 = *(uint *)(*piVar5 + 0x10);
    if (0xda9a39d4 < uVar1) {
      switch(uVar1) {
      case 0xda9a39d5:
        FUN_004c96c0(0x66601813);
        uVar3 = FEngFindObject();
        uVar6 = 0x66601813;
        break;
      case 0xda9a39d6:
        FUN_004c96c0(0x326eaca6);
        uVar3 = FEngFindObject();
        uVar6 = 0x326eaca6;
        break;
      case 0xda9a39d7:
switchD_00559bee_caseD_da96ef91:
        FUN_004c96c0(0x84e482d5);
        uVar3 = FEngFindObject();
        uVar6 = 0x84e482d5;
        break;
      case 0xda9a39d8:
        uVar3 = FEngFindObject();
        FEngSendMessageToObject(0xb5971bf1,uVar3);
        goto switchD_00559bee_default;
      case 0xda9a39d9:
        FUN_004c96c0(0x26eadf6f);
        uVar3 = FEngFindObject();
        uVar6 = 0x26eadf6f;
        break;
      default:
        goto switchD_00559bee_default;
      }
      goto LAB_00559e1c;
    }
    if (uVar1 == 0xda9a39d4) {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x7f70cefb,0,0,*(int *)(iVar4 + 0x18));
      }
      if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) goto switchD_00559bee_default;
        iVar4 = FUN_004ef050(0x91338b5e);
      }
      if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
        FUN_004f0700(0x7f70cefb,*piVar5,*(undefined4 *)(unaff_EBX + 0x78),iVar4,0);
      }
      goto switchD_00559bee_default;
    }
    switch(uVar1) {
    case 0xda96ef8e:
      FUN_004c96c0(0x7e092188);
      uVar3 = FEngFindObject();
      uVar6 = 0x7e092188;
      goto LAB_00559e1c;
    case 0xda96ef8f:
      FUN_004c96c0(0x2db86360);
      uVar3 = FEngFindObject();
      uVar6 = 0x2db86360;
      goto LAB_00559e1c;
    case 0xda96ef90:
      FUN_004c96c0(0xe4d06193);
      uVar3 = FEngFindObject();
      uVar6 = 0xe4d06193;
LAB_00559e1c:
      FEngSendMessageToObject(uVar6,uVar3);
      break;
    case 0xda96ef91:
      goto switchD_00559bee_caseD_da96ef91;
    case 0xda96ef92:
      uVar3 = FEngFindObject();
      FEngSendMessageToObject(0x9120409e,uVar3);
      break;
    case 0xda96ef93:
      uVar3 = FEngFindObject();
      FEngSendMessageToObject(0x26eadf6f,uVar3);
      FUN_004c96c0(0x26eadf6f);
    }
switchD_00559bee_default:
    piVar5 = piVar5 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x559e70 FUN_00559e70

void __thiscall FUN_00559e70(int *param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_2 < 0x7f70cefc) {
    if (param_2 == 0x7f70cefb) {
      FUN_0055a3e0();
      return;
    }
    if (param_2 < 0x326eaca7) {
      if (param_2 == 0x326eaca6) {
        FUN_0055a490();
        return;
      }
      if (param_2 < 0x26eadf70) {
        if (param_2 == 0x26eadf6f) {
          *(byte *)(param_1[0x10] + 0xdc) = *(byte *)(param_1[0x10] + 0xdc) ^ 1;
          (**(code **)(*param_1 + 0x10))();
          return;
        }
        if (param_2 == 2) {
          FUN_00549240();
          FUN_0055a550();
          return;
        }
        if (param_2 == 3) {
          FUN_004ec3c0();
          if (DAT_00734f84 == 0) {
            FUN_004eba00(2,0);
            bStrCpy();
            bStrCpy();
            return;
          }
          if (DAT_00734f84 == 0x746f6f79) {
            FEngSwitchPackages("MU_Online_CreateAccount_StepTwo.fng");
            return;
          }
          if (DAT_00734f84 == 0x706d616c) {
            FEngSwitchPackages("MU_Online_CreateAccount_StepTwo.fng");
            return;
          }
          FUN_004eba00(0,0);
          return;
        }
      }
      else if (param_2 == 0x2db86360) {
        FUN_0055a340(param_1,0xffffffff);
        return;
      }
    }
    else if (param_2 == 0x406415e3) {
      cVar2 = FUN_0055a2e0();
      if (cVar2 != '\0') {
        FUN_0055a190();
        return;
      }
    }
    else {
      if (param_2 == 0x66601813) {
        FUN_0055a340(param_1,1);
        return;
      }
      if (param_2 == 0x7e092188) {
        FUN_0055a3e0();
        return;
      }
    }
  }
  else if (param_2 < 0xc519bfc1) {
    if (param_2 == 0xc519bfc0) {
      pcVar1 = (char *)param_1[3];
      DAT_00777c30 = *pcVar1;
      if (DAT_00777c30 != '\0') {
        pcVar3 = &DAT_00777c30;
        do {
          cVar2 = (pcVar1 + -0x777c2f)[(int)pcVar3];
          pcVar3 = pcVar3 + 1;
          *pcVar3 = cVar2;
        } while (cVar2 != '\0');
      }
      FEngSwitchPackages(param_1[3]);
      return;
    }
    if (param_2 == 0x84e482d5) {
      FUN_0055a530();
      return;
    }
    if (param_2 == 0x911ab364) {
      FEngSwitchPackages(param_1[3]);
      return;
    }
    if (param_2 == 0xbabafafa) {
      FUN_0055a550();
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_0054d630();
    FUN_00559b60();
    if (DAT_00734e21 != '\0') {
      FUN_0055a190();
      DAT_00734e21 = '\0';
    }
  }
  else {
    if (param_2 == 0xe4d06193) {
      FUN_0055a490();
      return;
    }
    if (param_2 == 0xfafababa) {
      FUN_004c96c0(2);
      return;
    }
  }
  return;
}


// ==== 0x559f00 FUN_00559f00

void FUN_00559f00(void)

{
  int in_EAX;
  
  if (in_EAX == 0x746f6f79) {
    FEngSwitchPackages("MU_Online_CreateAccount_StepTwo.fng");
    return;
  }
  if (in_EAX == 0x706d616c) {
    FEngSwitchPackages("MU_Online_CreateAccount_StepTwo.fng");
    return;
  }
  FUN_004eba00(0,0);
  return;
}


// ==== 0x55a190 FUN_0055a190

void FUN_0055a190(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  FUN_004ebcb0();
  iVar2 = 0;
  if (DAT_00734e21 != '\0') {
    iVar2 = *(int *)(unaff_ESI + 0x40) + 0x66;
  }
  iVar1 = *(int *)(unaff_ESI + 0x40);
  FUN_0054d6b0(iVar1,iVar1 + 0x11,iVar1 + 0x33,iVar2,*(undefined4 *)(iVar1 + 0xd8),
               CONCAT31((int3)((uint)*(int *)(iVar1 + 0xe0) >> 8),*(int *)(iVar1 + 0xe0) == 0),
               *(undefined1 *)(iVar1 + 0xcc),*(undefined1 *)(iVar1 + 0xcd),FUN_0055a590);
  return;
}


// ==== 0x55a200 FUN_0055a200

void __fastcall FUN_0055a200(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0055b5d0();
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(*(int *)(param_1 + 0x40) + 0xd4));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(*(int *)(param_1 + 0x40) + 0xd8));
  if (*(int *)(*(int *)(param_1 + 0x40) + 0xe0) == 0) {
    uVar2 = 0x193f3e;
  }
  else {
    uVar2 = 0x5b5ad1c9;
  }
  FUN_00495f00(uVar2);
  if (*(char *)(*(int *)(param_1 + 0x40) + 0xdc) == '\0') {
    FUN_00495f00(0x2c119933);
  }
  else {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar1);
  }
  FUN_00495f00(0x353f3237);
  return;
}


// ==== 0x55a2e0 FUN_0055a2e0

undefined4 FUN_0055a2e0(void)

{
  int in_EAX;
  
  if (*(char *)(*(int *)(in_EAX + 0x40) + 0xdc) == '\0') {
    FUN_004eb950(0,0x18ed8cac,0x9c7511d8,0x8c35f7e5,0x4e2e9a00,0,0x639,0);
    return 0;
  }
  return 1;
}


// ==== 0x55a340 FUN_0055a340

void FUN_0055a340(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = param_1[0x10];
  iVar4 = *(int *)(&DAT_006b62b4 + *(int *)(iVar1 + 0xd0) * 4);
  uVar2 = *(uint *)(iVar1 + 0xd8);
  uVar3 = uVar2 & 0x80000003;
  bVar5 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar5 = (uVar3 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((((bVar5) && ((int)uVar2 % 100 != 0)) || ((int)uVar2 % 400 == 0)) &&
     (*(int *)(iVar1 + 0xd0) == 2)) {
    iVar4 = iVar4 + 1;
  }
  *(int *)(iVar1 + 0xd4) = *(int *)(iVar1 + 0xd4) + param_2;
  iVar1 = param_1[0x10];
  if (iVar4 < *(int *)(iVar1 + 0xd4)) {
    *(undefined4 *)(iVar1 + 0xd4) = 1;
    (**(code **)(*param_1 + 0x10))();
    return;
  }
  if (*(int *)(iVar1 + 0xd4) < 1) {
    *(int *)(iVar1 + 0xd4) = iVar4;
  }
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== 0x55a3e0 FUN_0055a3e0

void __fastcall FUN_0055a3e0(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  *(int *)(param_1[0x10] + 0xd0) = *(int *)(param_1[0x10] + 0xd0) + param_2;
  if (0xc < *(int *)(param_1[0x10] + 0xd0)) {
    *(undefined4 *)(param_1[0x10] + 0xd0) = 1;
  }
  if (*(int *)(param_1[0x10] + 0xd0) < 1) {
    *(undefined4 *)(param_1[0x10] + 0xd0) = 0xc;
  }
  iVar1 = param_1[0x10];
  uVar2 = *(uint *)(iVar1 + 0xd8);
  iVar4 = *(int *)(&DAT_006b62b4 + *(int *)(iVar1 + 0xd0) * 4);
  uVar3 = uVar2 & 0x80000003;
  bVar5 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar5 = (uVar3 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((((bVar5) && ((int)uVar2 % 100 != 0)) || ((int)uVar2 % 400 == 0)) &&
     (*(int *)(iVar1 + 0xd0) == 2)) {
    iVar4 = iVar4 + 1;
  }
  if (iVar4 < *(int *)(iVar1 + 0xd4)) {
    *(int *)(iVar1 + 0xd4) = iVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x0055a48b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== 0x55a490 FUN_0055a490

void __fastcall FUN_0055a490(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  *(int *)(param_1[0x10] + 0xd8) = *(int *)(param_1[0x10] + 0xd8) + param_2;
  iVar1 = param_1[0x10];
  if (*(int *)(iVar1 + 0xd8) < 0x7d4) {
    if (*(int *)(iVar1 + 0xd8) < 0x76c) {
      *(undefined4 *)(iVar1 + 0xd8) = 0x7d3;
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0xd8) = 0x76c;
  }
  iVar1 = param_1[0x10];
  uVar2 = *(uint *)(iVar1 + 0xd8);
  uVar3 = uVar2 & 0x80000003;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((((!bVar4) || ((int)uVar2 % 100 == 0)) && ((int)uVar2 % 400 != 0)) &&
     ((*(int *)(iVar1 + 0xd0) == 2 && (*(int *)(iVar1 + 0xd4) == 0x1d)))) {
    *(undefined4 *)(iVar1 + 0xd4) = 0x1c;
  }
                    /* WARNING: Could not recover jumptable at 0x0055a521. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== 0x55a530 FUN_0055a530

void __fastcall FUN_0055a530(int *param_1)

{
  *(uint *)(param_1[0x10] + 0xe0) = (uint)(*(int *)(param_1[0x10] + 0xe0) == 0);
                    /* WARNING: Could not recover jumptable at 0x0055a54a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== 0x55a550 FUN_0055a550

undefined4 FUN_0055a550(void)

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


// ==== 0x55a590 FUN_0055a590

void FUN_0055a590(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55a5b0 FUN_0055a5b0

undefined4 FUN_0055a5b0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687703;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x464);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0055a610(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x55a610 FUN_0055a610

undefined4 * FUN_0055a610(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined **local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined1 local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006876e1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006bca5c;
  FEMenuData__FEMenuData();
  local_4._0_1_ = 1;
  FEMenuData__FEMenuData();
  iVar4 = param_1[3];
  local_4 = CONCAT31(local_4._1_3_,2);
  uVar3 = FEng__HashName();
  if (((((iVar4 == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(uVar3), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 2)) {
    iVar4 = 0;
  }
  pcVar2 = (char *)param_1[3];
  param_1[0x118] = iVar4;
  *(undefined1 *)((int)param_1 + 0x45d) = 0;
  DAT_00734bc8 = *pcVar2;
  DAT_00734e1f = 0;
  DAT_00734e20 = 0;
  if (DAT_00734bc8 != '\0') {
    pcVar5 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar5];
      pcVar5 = pcVar5 + 1;
      *pcVar5 = cVar1;
    } while (cVar1 != '\0');
  }
  FUN_0055b500();
  iVar4 = 0;
  local_20 = (undefined **)0x0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  cVar1 = DAT_00734dd8;
  while (cVar1 != '\0') {
    pcVar2 = &DAT_00734dd9 + iVar4;
    iVar4 = iVar4 + 1;
    cVar1 = *pcVar2;
  }
  iVar6 = 0;
  if (0 < iVar4) {
    do {
      if (iVar6 == 0xf) break;
      *(undefined1 *)((int)&local_20 + iVar6) = 0x2a;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  *(undefined1 *)((int)&local_20 + iVar6) = 0;
  FUN_0055b500();
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (((param_1[3] == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x70355aa6);
    }
  }
  param_1[0x10] = iVar4;
  if (((param_1[3] == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x70355aa7);
    }
  }
  param_1[0x11] = iVar4;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) &&
     (iVar4 = 0, DAT_0073578c != 0)) {
    iVar6 = *(int *)(DAT_0073578c + 8);
    if (iVar6 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004fd1e0(iVar6 + 0xdc);
      if (iVar4 == 0) {
        iVar4 = FUN_004fd1e0(iVar6 + 0xec);
      }
    }
  }
  param_1[0x12] = iVar4;
  param_1[0x8f] = 1;
  param_1[0x91] = 0xe;
  FUN_0041f160(0x47af1aca,0,0,0x10);
  param_1[0x90] = 0xceffd44;
  param_1[0x111] = 2;
  param_1[0x113] = 0xf;
  FUN_0041f160(0xbda9eeb0,0,0,0x10);
  param_1[0x112] = 0xceffd44;
  if (param_1[3] == 0) {
LAB_0055a94b:
    if ((DAT_0073578c != 0) && (iVar4 = FUN_004ef050(0x47af1aca), iVar4 != 0)) {
LAB_0055a967:
      if (*(int *)(iVar4 + 0x18) == 2) {
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x20;
      }
    }
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0055a90f:
      local_20 = &PTR_FUN_006c1800;
      local_4._0_1_ = 3;
      local_1c = 0x47af1aca;
      local_18 = 0;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,2);
      local_20 = &PTR_FUN_006c2c5c;
      iVar4 = local_18;
      if (local_18 == 0) goto LAB_0055a94b;
      goto LAB_0055a967;
    }
    if (DAT_0073578c != 0) {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_0055a94b;
      goto LAB_0055a90f;
    }
  }
  if (param_1[3] == 0) {
LAB_0055aa11:
    if ((DAT_0073578c == 0) || (local_18 = FUN_004ef050(0xbda9eeb0), local_18 == 0))
    goto LAB_0055aa37;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
      if (DAT_0073578c == 0) goto LAB_0055aa37;
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_0055aa11;
    }
    local_20 = &PTR_FUN_006c1800;
    local_4._0_1_ = 4;
    local_1c = 0xbda9eeb0;
    local_18 = 0;
    FUN_004ffb00(iVar4);
    local_4 = CONCAT31(local_4._1_3_,2);
    local_20 = &PTR_FUN_006c2c5c;
    if (local_18 == 0) goto LAB_0055aa11;
  }
  if (*(int *)(local_18 + 0x18) == 2) {
    *(uint *)(local_18 + 0x1c) = *(uint *)(local_18 + 0x1c) | 0x20;
  }
LAB_0055aa37:
  *(undefined1 *)(param_1 + 0x117) = 0;
  *(undefined1 *)((int)param_1 + 0x45e) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x55aa60 FUN_0055aa60

void * __thiscall FUN_0055aa60(void *param_1,byte param_2)

{
  FUN_0055aa80(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55aa80 FUN_0055aa80

void FUN_0055aa80(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_006876a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bca5c;
  local_4 = 1;
  DAT_00734bc8 = 0;
  eh_vector_destructor_iterator(param_1 + 0x99,0xc,0x20,WString_Free);
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator(param_1 + 0x17,0xc,0x20,WString_Free);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x55ab00 FUN_0055ab00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0055ab00(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char acStack_14 [20];
  
  cVar3 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar3 != '\0') {
    return;
  }
  cVar3 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar3 != '\0') {
    return;
  }
  if (0xc407210 < param_2) {
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        if (*(char *)(param_1 + 0x45e) != '\0') {
          return;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x35f8620b) {
        *(undefined1 *)(param_1 + 0x45c) = 1;
        return;
      }
      if (param_2 != 0x406415e3) {
        return;
      }
      if (*(char *)(param_1 + 0x45e) != '\0') {
        return;
      }
      FUN_004ebcb0();
      FUN_0054d8b0(&DAT_00734dc4,&DAT_00734dd8,FUN_0055b410);
      return;
    }
    if (param_2 == 0xabc08912) {
      uVar1 = *(uint *)(param_3 + 0x10);
      if (uVar1 < 0x3eb860d3) {
        if (((uVar1 != 0x3eb860d2) && (uVar1 != 0xf33777d)) && (uVar1 != 0x3834fa1e)) {
          return;
        }
      }
      else if ((uVar1 != 0x740db178) && (uVar1 != 0x8ac75312)) {
        return;
      }
      FEString__SetLabelHash();
      FEObject__SetScript("FadeIn",1);
      return;
    }
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_0054d630();
    iVar4 = bStrLen();
    if (iVar4 < 1) {
      if (DAT_0073578c != 0) {
        cFEng__SetButtonState(DAT_0073578c,0);
      }
      FUN_00415510(0xff606060);
      uVar7 = 0xff606060;
    }
    else {
      if (DAT_0073578c != 0) {
        cFEng__SetButtonState(DAT_0073578c,1);
      }
      FUN_00415510(0xff549ac0);
      uVar7 = 0xff549ac0;
    }
    FUN_00415510(uVar7);
    FUN_0055b2b0(param_1);
    if (*(char *)(param_1 + 0x45d) == '\0') {
      return;
    }
    puVar6 = (undefined4 *)&DAT_00734dec;
    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = 0;
    *(undefined1 *)((int)puVar6 + 2) = 0;
    iVar5 = 0x32;
    iVar4 = 0;
    do {
      iVar5 = iVar5 + -1;
      (&DAT_00734dec)[iVar4] = (&DAT_00777b74)[iVar4];
      if ((&DAT_00777b74)[iVar4] == '\0') break;
      iVar4 = iVar4 + 1;
    } while (iVar5 != 0);
    iVar4 = bStrLen();
    bVar2 = false;
    if ((5 < iVar4) && (iVar4 < 0x33)) {
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          if ((((&DAT_00734dec)[iVar5] == '@') && (iVar5 != 0)) &&
             ((iVar5 < iVar4 + -3 && ((&DAT_00734ded)[iVar5] != '.')))) goto joined_r0x0055b159;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
LAB_0055b17b:
      if (bVar2) {
        FUN_0054db50(&DAT_00734dec,FUN_0055b3d0);
        FUN_004ebcb0();
        *(undefined1 *)(param_1 + 0x45d) = 0;
        return;
      }
    }
    cVar3 = FEngIsPackagePushed();
    if (cVar3 != '\0') {
      return;
    }
    FUN_004eba00(0,0);
    *(undefined1 *)(param_1 + 0x45d) = 0;
    return;
  }
  if (param_2 == 0xc407210) {
    if (*(char *)(param_1 + 0x45e) != '\0') {
      return;
    }
    uVar1 = *(uint *)(param_3 + 0x10);
    if (0x3eb860d2 < uVar1) {
      if (uVar1 != 0x740db178) {
        return;
      }
      *(undefined1 *)(param_1 + 0x459) = 1;
      DAT_0070108e = 1;
      DAT_007363b2 = 1;
      FUN_0041f4d0();
      return;
    }
    if (uVar1 == 0x3eb860d2) {
      DAT_0070108e = 1;
      FUN_0041f4d0();
      return;
    }
    if (uVar1 != 0xf33777d) {
      if (uVar1 != 0x3834fa1e) {
        return;
      }
      iVar4 = bStrLen();
      if (iVar4 < 1) {
        FUN_004eba00(0,0);
        return;
      }
      FUN_0054da90(extraout_ECX,FUN_0055b3f0);
      FUN_004ebcb0();
      return;
    }
    FUN_004ebac0(3,param_1);
    return;
  }
  switch(param_2) {
  case 1:
    acStack_14[0] = '\0';
    acStack_14[1] = '\0';
    acStack_14[2] = '\0';
    acStack_14[3] = '\0';
    acStack_14[4] = '\0';
    acStack_14[5] = '\0';
    acStack_14[6] = '\0';
    acStack_14[7] = '\0';
    acStack_14[8] = '\0';
    acStack_14[9] = '\0';
    acStack_14[10] = '\0';
    acStack_14[0xb] = '\0';
    acStack_14[0xc] = '\0';
    acStack_14[0xd] = '\0';
    acStack_14[0xe] = '\0';
    acStack_14[0xf] = '\0';
    acStack_14[0x10] = 0;
    iVar5 = 0x10;
    iVar4 = 0;
    do {
      cVar3 = (&DAT_00777b74)[iVar4];
      iVar5 = iVar5 + -1;
      acStack_14[iVar4] = cVar3;
      if (cVar3 == '\0') break;
      iVar4 = iVar4 + 1;
    } while (iVar5 != 0);
    iVar4 = bStrCmp();
    if (iVar4 != 0) {
      DAT_00734e1f = 1;
      bStrCpy();
      FUN_0055b500();
      return;
    }
    break;
  case 2:
    acStack_14[0] = '\0';
    acStack_14[1] = '\0';
    acStack_14[2] = '\0';
    acStack_14[3] = '\0';
    acStack_14[4] = '\0';
    acStack_14[5] = '\0';
    acStack_14[6] = '\0';
    acStack_14[7] = '\0';
    acStack_14[8] = '\0';
    acStack_14[9] = '\0';
    acStack_14[10] = '\0';
    acStack_14[0xb] = '\0';
    acStack_14[0xc] = '\0';
    acStack_14[0xd] = '\0';
    acStack_14[0xe] = '\0';
    acStack_14[0xf] = '\0';
    acStack_14[0x10] = 0;
    iVar5 = 0x10;
    iVar4 = 0;
    do {
      cVar3 = (&DAT_00777b74)[iVar4];
      iVar5 = iVar5 + -1;
      acStack_14[iVar4] = cVar3;
      if (cVar3 == '\0') break;
      iVar4 = iVar4 + 1;
    } while (iVar5 != 0);
    iVar4 = bStrCmp();
    if (iVar4 != 0) {
      DAT_00734e20 = 1;
      bStrCpy();
      acStack_14[0] = '\0';
      acStack_14[1] = '\0';
      acStack_14[2] = '\0';
      acStack_14[3] = '\0';
      acStack_14[4] = '\0';
      acStack_14[5] = '\0';
      acStack_14[6] = '\0';
      acStack_14[7] = '\0';
      acStack_14[8] = '\0';
      acStack_14[9] = '\0';
      acStack_14[10] = '\0';
      acStack_14[0xb] = '\0';
      acStack_14[0xc] = '\0';
      acStack_14[0xd] = '\0';
      acStack_14[0xe] = '\0';
      acStack_14[0xf] = '\0';
      acStack_14[0x10] = 0;
      FUN_004fa0b0(0x10);
      FUN_0055b500();
      return;
    }
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x45d) = 1;
    return;
  case 6:
  case 7:
    FUN_004ec3c0();
    if (DAT_00734f84 != 0) {
      FUN_0055b470();
      return;
    }
    FUN_004eba00(0,0);
    return;
  case 8:
    FUN_004ec3c0();
    if (DAT_00734f84 == 0) {
      if (DAT_00734e1f != '\0') {
        bStrCpy();
      }
      if (DAT_00734e20 != '\0') {
        bStrCpy();
      }
      FUN_00549240();
      FUN_0055b430();
      return;
    }
    if (DAT_00734f84 < 0x6c6f676f) {
      if (DAT_00734f84 == 0x6c6f676e) goto LAB_0055acaf;
      if (DAT_00734f84 < 0x66696c75) {
        if ((DAT_00734f84 == 0x66696c74) ||
           ((DAT_00734f84 == 0x626c616b || (DAT_00734f84 == 0x64626572)))) goto LAB_0055acaf;
      }
      else if ((DAT_00734f84 == 0x696d7374) || (DAT_00734f84 == 0x6c6f636b)) goto LAB_0055acaf;
    }
    else if (DAT_00734f84 < 0x72737277) {
      if (((DAT_00734f84 == 0x72737276) || (DAT_00734f84 == 0x6d697373)) ||
         (DAT_00734f84 == 0x70617373)) goto LAB_0055acaf;
    }
    else if (DAT_00734f84 == 0x74696d65) goto LAB_0055acaf;
    FUN_0054d4a0(&DAT_0073d868,DAT_00734f84);
LAB_0055acaf:
    FUN_004eba00(0,0);
    return;
  case 0xe:
    _DAT_00734dc4 = 0;
    _DAT_00734dc8 = 0;
    _DAT_00734dcc = 0;
    puVar6 = &DAT_007346d8;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    _DAT_00734dd0 = 0;
    DAT_00734dd4 = 0;
    FUN_0055b500();
    return;
  case 0xf:
    _DAT_00734dd8 = 0;
    _DAT_00734ddc = 0;
    _DAT_00734de0 = 0;
    _DAT_00734de4 = 0;
    puVar6 = &DAT_007346f8;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    DAT_00734de8 = 0;
    FUN_0055b500();
    return;
  }
  return;
joined_r0x0055b159:
  if (iVar4 <= iVar5) goto LAB_0055b17b;
  if (((&DAT_00734dec)[iVar5] == '.') && (iVar5 < iVar4 + -1)) {
    bVar2 = true;
    goto LAB_0055b17b;
  }
  iVar5 = iVar5 + 1;
  goto joined_r0x0055b159;
}


// ==== 0x55b1b5 FUN_0055b1b5

void FUN_0055b1b5(void)

{
  char cVar1;
  int unaff_EBP;
  
  cVar1 = FEngIsPackagePushed();
  if (cVar1 == '\0') {
    FUN_004eba00(0,0);
    *(undefined1 *)(unaff_EBP + 0x45d) = 0;
    return;
  }
  return;
}


// ==== 0x55b2b0 FUN_0055b2b0

void FUN_0055b2b0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar1 = param_1;
  if (*(char *)(param_1 + 0x45c) != '\0') {
    piVar4 = (int *)(param_1 + 0x40);
    param_1 = 2;
    do {
      if ((*piVar4 != 0) && (cVar2 = FUN_004f7eb0(iVar1), cVar2 != '\0')) {
        if (*(int *)(*piVar4 + 0x10) == 0x70355aa6) {
          if (((*(int *)(iVar1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
             (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
            if (DAT_0073578c == 0) goto LAB_0055b3b6;
            iVar3 = FUN_004ef050(0x3eb860d2);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            iVar5 = *piVar4;
            uVar6 = *(undefined4 *)(iVar1 + 0x48);
LAB_0055b3ac:
            FUN_004f0700(0xc407210,iVar5,uVar6,iVar3,0);
          }
        }
        else if (*(int *)(*piVar4 + 0x10) == 0x70355aa7) {
          if (((*(int *)(iVar1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
             (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
            if (DAT_0073578c == 0) goto LAB_0055b3b6;
            iVar3 = FUN_004ef050(0x740db178);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            uVar6 = *(undefined4 *)(iVar1 + 0x48);
            iVar5 = *piVar4;
            goto LAB_0055b3ac;
          }
        }
      }
LAB_0055b3b6:
      piVar4 = piVar4 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== 0x55b3d0 FUN_0055b3d0

void FUN_0055b3d0(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55b3f0 FUN_0055b3f0

void FUN_0055b3f0(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55b410 FUN_0055b410

void FUN_0055b410(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55b430 FUN_0055b430

undefined4 FUN_0055b430(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  iVar1 = DAT_0073578c;
  bVar4 = DAT_0073578c != 0;
  *(undefined1 *)(in_EAX + 0x45e) = 0;
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (bVar4) {
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


// ==== 0x55b470 FUN_0055b470

void FUN_0055b470(void)

{
  int in_EAX;
  
  if (in_EAX < 0x6d616e7a) {
    if (in_EAX == 0x6d616e79) goto LAB_0055b4db;
    if (in_EAX == 0) {
      return;
    }
    if ((in_EAX == 0x696d7374) || (in_EAX == 0x6d61696c)) goto LAB_0055b4db;
  }
  else if (((in_EAX == 0x6e656d6c) || (in_EAX == 0x74696d65)) || (in_EAX == 0x75757372))
  goto LAB_0055b4db;
  FUN_0054d4a0(&DAT_0073d868,in_EAX);
LAB_0055b4db:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x55b500 FUN_0055b500

void __fastcall FUN_0055b500(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  char *unaff_EBX;
  
  iVar2 = 0;
  if ((unaff_EBX != (char *)0x0) && (*unaff_EBX != '\0')) {
    do {
      iVar1 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (unaff_EBX[iVar1] != '\0');
    if (iVar2 != 0) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
         (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
        if (DAT_0073578c != 0) {
          iVar2 = FUN_004ef050(in_EAX);
          *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
          FUN_0041f060(iVar2,unaff_EBX);
          return;
        }
        iVar2 = 0;
      }
      *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 2;
      FUN_0041f060(iVar2,unaff_EBX);
      return;
    }
  }
  FUN_00495f00(0xceffd44);
  return;
}


// ==== 0x55b590 FUN_0055b590

void * __thiscall FUN_0055b590(void *param_1,byte param_2)

{
  FUN_0055b5b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55b5b0 FUN_0055b5b0

void __fastcall FUN_0055b5b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bca48;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x55b5d0 FUN_0055b5d0

void FUN_0055b5d0(void)

{
  int in_EAX;
  undefined4 local_34 [13];
  
  if (in_EAX < 1) {
    in_EAX = 1;
  }
  else if (0xc < in_EAX) {
    in_EAX = 0xc;
  }
  local_34[0] = 0xffffffff;
  local_34[1] = 0x1894d765;
  local_34[2] = 0x1894d766;
  local_34[3] = 0x1894d767;
  local_34[4] = 0x1894d768;
  local_34[5] = 0x1894d769;
  local_34[6] = 0x1894d76a;
  local_34[7] = 0x1894d76b;
  local_34[8] = 0x1894d76c;
  local_34[9] = 0x1894d76d;
  local_34[10] = 0x1894d785;
  local_34[0xb] = 0x1894d786;
  local_34[0xc] = 0x1894d787;
  FUN_00495f00(local_34[in_EAX]);
  return;
}


// ==== 0x55b670 FUN_0055b670

undefined4 FUN_0055b670(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688113;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x254);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0055b6d0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x55b6d0 FUN_0055b6d0

undefined4 * FUN_0055b6d0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006880eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  pcVar2 = (char *)param_1[3];
  *param_1 = &PTR_FUN_006bca48;
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  local_4 = 0;
  *param_1 = &PTR_FUN_006bca18;
  FEMenuData__FEMenuData();
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x10] = &DAT_007787b4;
  FUN_0055bb80();
  pcVar2 = (char *)param_1[3];
  DAT_00734bc8 = *pcVar2;
  if (DAT_00734bc8 != '\0') {
    pcVar4 = &DAT_00734bc8;
    do {
      cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x11] = 0;
  if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x70355aa6);
    }
  }
  param_1[0x11] = iVar5;
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
  param_1[0x12] = iVar5;
  param_1[0x8f] = 0xae83b9db;
  param_1[0x91] = 0;
  FUN_0041f160(0xd965a529,0x70355aa6,0,0x32);
  if (param_1[3] != 0) {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
      if (DAT_0073578c == 0) {
        ExceptionList = local_c;
        return param_1;
      }
      iVar3 = *(int *)(DAT_0073578c + 8);
      if ((iVar3 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar3 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar3 + 0xec), iVar5 == 0)))) goto LAB_0055b8de;
    }
    local_4._0_1_ = 2;
    FUN_004ffb00(iVar5);
    local_4 = CONCAT31(local_4._1_3_,1);
  }
LAB_0055b8de:
  if (((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(0xd965a529), iVar5 != 0)) &&
     (*(int *)(iVar5 + 0x18) == 2)) {
    *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x20;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x55b920 FUN_0055b920

void * __thiscall FUN_0055b920(void *param_1,byte param_2)

{
  FUN_0055b940(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55b940 FUN_0055b940

void FUN_0055b940(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688128;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bca18;
  local_4 = 0;
  DAT_00734bc8 = 0;
  eh_vector_destructor_iterator(param_1 + 0x17,0xc,0x20,WString_Free);
  *param_1 = &PTR_FUN_006bca48;
  local_4 = 0xffffffff;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x55b9b0 FUN_0055b9b0

void __thiscall
FUN_0055b9b0(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  cVar1 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar1 == '\0') {
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        FEngSwitchPackages(param_1[3]);
        return;
      }
      if (param_2 != 0xf6394c6) {
        if (param_2 != 0x406415e3) {
          return;
        }
        cVar1 = FUN_0055bd10(param_1);
        if (cVar1 == '\0') {
          return;
        }
        DAT_00734e21 = 1;
        FEngSwitchPackages(param_1[3]);
        return;
      }
      DAT_0070108e = 0;
      FUN_0041f4d0();
    }
    else if (param_2 != 0xae83b9db) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      FUN_0054d630();
      FUN_0055bab0();
      return;
    }
    puVar5 = (undefined4 *)(param_1[0x10] + 0x66);
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)puVar5 = 0;
    *(undefined1 *)((int)puVar5 + 2) = 0;
    pcVar2 = (char *)(param_1[0x10] + 0x66);
    iVar3 = 0x32;
    iVar4 = (int)&DAT_00777b74 - (int)pcVar2;
    do {
      cVar1 = pcVar2[iVar4];
      iVar3 = iVar3 + -1;
      *pcVar2 = cVar1;
      if (cVar1 == '\0') break;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 != 0);
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


// ==== 0x55bab0 FUN_0055bab0

void FUN_0055bab0(void)

{
  char cVar1;
  int iVar2;
  int unaff_EBX;
  
  if ((((*(int *)(unaff_EBX + 0x44) != 0) && (DAT_007064b2 != '\0')) &&
      (cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
      cVar1 != '\0')) && (*(int *)(*(int *)(unaff_EBX + 0x44) + 0x10) == 0x70355aa6)) {
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar2 = FUN_004ef050(0x7403711);
    }
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0xc407210,*(undefined4 *)(unaff_EBX + 0x44),*(undefined4 *)(unaff_EBX + 0x48),
                   iVar2,0);
    }
  }
  return;
}


// ==== 0x55bb80 FUN_0055bb80

void __fastcall FUN_0055bb80(int param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar6 = (char *)(*(int *)(param_1 + 0x40) + 0x66);
  iVar4 = 0;
  if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
LAB_0055bc8c:
    iVar4 = 0;
    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
LAB_0055bc1d:
      FUN_00495f00(0xceffd44);
      return;
    }
    do {
      iVar2 = iVar4 + 1;
      iVar4 = iVar4 + 1;
    } while (pcVar6[iVar2] != '\0');
    if (iVar4 == 0) goto LAB_0055bc1d;
    if (((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FEngFindPackage(), iVar4 != 0)) &&
       (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_0055bcf8;
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0xd965a529);
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 2;
      FUN_0041f060(iVar4,pcVar6);
      return;
    }
  }
  else {
    do {
      iVar2 = iVar4 + 1;
      iVar4 = iVar4 + 1;
    } while (pcVar6[iVar2] != '\0');
    if (iVar4 < 0x18) goto LAB_0055bc8c;
    pcVar1 = (char *)(*(int *)(param_1 + 0x40) + 0x99);
    *pcVar1 = *pcVar6;
    if (*pcVar6 != '\0') {
      pcVar5 = pcVar1;
      do {
        cVar3 = pcVar5[(int)(pcVar6 + (1 - (int)pcVar1))];
        pcVar5 = pcVar5 + 1;
        *pcVar5 = cVar3;
      } while (cVar3 != '\0');
    }
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xad) = 0x2e;
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xae) = 0x2e;
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xaf) = 0x2e;
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xb0) = 0;
    pcVar6 = (char *)(*(int *)(param_1 + 0x40) + 0x99);
    iVar4 = 0;
    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) goto LAB_0055bc1d;
    do {
      iVar2 = iVar4 + 1;
      iVar4 = iVar4 + 1;
    } while (pcVar6[iVar2] != '\0');
    if (iVar4 == 0) goto LAB_0055bc1d;
    if (((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FEngFindPackage(), iVar4 != 0)) &&
       (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_0055bcf8;
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0xd965a529);
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 2;
      FUN_0041f060(iVar4,pcVar6);
      return;
    }
  }
  iVar4 = 0;
LAB_0055bcf8:
  *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 2;
  FUN_0041f060(iVar4,pcVar6);
  return;
}


// ==== 0x55bd10 FUN_0055bd10

undefined4 FUN_0055bd10(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  iVar4 = *(int *)(param_1 + 0x40);
  pcVar6 = (char *)(iVar4 + 0x66);
  iVar3 = 0;
  if (pcVar6 != (char *)0x0) {
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      iVar5 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar1 = pcVar6[iVar5];
    }
  }
  bVar2 = false;
  if ((iVar3 < 6) || (0x32 < iVar3)) goto LAB_0055bde2;
  iVar5 = 0;
  if (0 < iVar3) {
    pcVar6 = (char *)(iVar4 + 0x67);
    do {
      if ((((pcVar6[-1] == '@') && (iVar5 != 0)) && (iVar5 < iVar3 + -3)) && (*pcVar6 != '.')) {
        if (iVar5 < iVar3) {
          pcVar6 = (char *)(iVar5 + 0x66 + iVar4);
          goto LAB_0055bd87;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (iVar5 < iVar3);
  }
  goto LAB_0055bda3;
  while( true ) {
    iVar5 = iVar5 + 1;
    pcVar6 = pcVar6 + 1;
    if (iVar3 <= iVar5) break;
LAB_0055bd87:
    if ((*pcVar6 == '.') && (iVar5 < iVar3 + -1)) {
      bVar2 = true;
      break;
    }
  }
LAB_0055bda3:
  if ((bVar2) && (iVar4 = bStrICmp(), iVar4 != 0)) {
    return 1;
  }
LAB_0055bde2:
  FUN_004eb950();
  return 0;
}


// ==== 0x55be30 FUN_0055be30

undefined4 * FUN_0055be30(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687683;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar3 = _malloc(0x40);
  local_4 = 0;
  if (puVar3 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar3,param_1);
    pcVar2 = (char *)puVar3[3];
    *puVar3 = &PTR_FUN_006bc9f8;
    DAT_00734bc8 = *pcVar2;
    if (DAT_00734bc8 != '\0') {
      pcVar4 = &DAT_00734bc8;
      do {
        cVar1 = (pcVar2 + -0x734bc7)[(int)pcVar4];
        pcVar4 = pcVar4 + 1;
        *pcVar4 = cVar1;
      } while (cVar1 != '\0');
    }
    ExceptionList = local_c;
    return puVar3;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x55bec0 FUN_0055bec0

void * __thiscall FUN_0055bec0(void *param_1,byte param_2)

{
  FUN_0055bee0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55bee0 FUN_0055bee0

void __fastcall FUN_0055bee0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc9f8;
  DAT_00734bc8 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x55bf00 FUN_0055bf00

int __thiscall FUN_0055bf00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((param_2 == 0x406415e3) || (param_2 == -0x6ee54c9c)) {
    param_2 = *(int *)(param_1 + 0xc);
    if (DAT_0073578c != 0) {
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
  else if (param_2 == -0x367ca946) {
    iVar1 = FUN_0054d630();
    return iVar1;
  }
  return param_2;
}


// ==== 0x55bf60 FUN_0055bf60

undefined4 FUN_0055bf60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006880c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x898);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0055bfc0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x55bfc0 FUN_0055bfc0

/* WARNING: Removing unreachable block (ram,0x0055c2f5) */

undefined4 * FUN_0055bfc0(undefined4 *param_1,int param_2)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int local_70;
  undefined4 *local_6c;
  int local_68;
  byte local_4c;
  byte local_4b [31];
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006880a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006bc99c;
  eh_vector_constructor_iterator(param_1 + 0x1e,0x208,4,FEMenuData__FEMenuData,FUN_0041f140);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0055c550(param_1);
  param_1[0x14] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x15) = 0;
  pcVar3 = (char *)param_1[3];
  DAT_00734bc8 = *pcVar3;
  if (DAT_00734bc8 != '\0') {
    pcVar6 = &DAT_00734bc8;
    do {
      cVar2 = (pcVar3 + -0x734bc7)[(int)pcVar6];
      pcVar6 = pcVar6 + 1;
      *pcVar6 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined1 *)((int)param_1 + 0x61) = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  if (((param_1[3] == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004ef050(0x70355aa9);
    }
  }
  param_1[0x19] = iVar7;
  if (((param_1[3] == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004ef050(0x70355aa8);
    }
  }
  param_1[0x1a] = iVar7;
  if (((param_1[3] == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004ef050(0x70355aa7);
    }
  }
  param_1[0x1b] = iVar7;
  if (((param_1[3] == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004ef050(0x70355aa6);
    }
  }
  param_1[0x1c] = iVar7;
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) &&
     (iVar7 = 0, DAT_0073578c != 0)) {
    iVar8 = *(int *)(DAT_0073578c + 8);
    if (iVar8 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
      if (iVar7 == 0) {
        iVar7 = FUN_004fd1e0(iVar8 + 0xec);
      }
    }
  }
  local_6c = param_1 + 0x9c;
  param_1[0x1d] = iVar7;
  param_2 = 1;
  local_68 = 4;
  do {
    local_4c = 0;
    pbVar9 = local_4b;
    for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
      pbVar9[0] = 0;
      pbVar9[1] = 0;
      pbVar9[2] = 0;
      pbVar9[3] = 0;
      pbVar9 = pbVar9 + 4;
    }
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    bSPrintf_regdst(0x20,"Player_DATA_%.2d",param_2);
    iVar7 = -1;
    pbVar9 = &local_4c;
    bVar5 = local_4c;
    while (bVar5 != 0) {
      if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
        bVar5 = bVar5 - 0x20;
      }
      iVar7 = iVar7 * 0x21 + (uint)bVar5;
      pbVar1 = pbVar9 + 1;
      pbVar9 = pbVar9 + 1;
      bVar5 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0055c302:
      if (DAT_0073578c == 0) goto LAB_0055c31c;
      local_70 = FUN_004ef050(iVar7);
    }
    else {
      iVar8 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_0055c2ba:
        local_4._0_1_ = 2;
        FUN_004ffb00(iVar8);
        local_4 = CONCAT31(local_4._1_3_,1);
        goto LAB_0055c302;
      }
      if (DAT_0073578c != 0) {
        iVar4 = *(int *)(DAT_0073578c + 8);
        if ((iVar4 == 0) ||
           (((iVar8 = FUN_004fd1e0(iVar4 + 0xdc), iVar8 == 0 &&
             (iVar8 = FUN_004fd1e0(iVar4 + 0xec), iVar8 == 0)) || (iVar8 == 0)))) goto LAB_0055c302;
        goto LAB_0055c2ba;
      }
LAB_0055c31c:
      local_70 = 0;
    }
    local_2c = 0;
    pbVar9 = local_2b;
    for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
      pbVar9[0] = 0;
      pbVar9[1] = 0;
      pbVar9[2] = 0;
      pbVar9[3] = 0;
      pbVar9 = pbVar9 + 4;
    }
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    bSPrintf_regdst(0x20,"TEXT_ENTRY%d",param_2);
    iVar7 = -1;
    pbVar9 = &local_2c;
    bVar5 = local_2c;
    while (bVar5 != 0) {
      if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
        bVar5 = bVar5 - 0x20;
      }
      iVar7 = iVar7 * 0x21 + (uint)bVar5;
      pbVar1 = pbVar9 + 1;
      pbVar9 = pbVar9 + 1;
      bVar5 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0055c428:
      if (DAT_0073578c != 0) {
        FUN_004ef050(iVar7);
      }
    }
    else {
      iVar8 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_0055c3ed:
        local_4._0_1_ = 3;
        FUN_004ffb00(iVar8);
        local_4 = CONCAT31(local_4._1_3_,1);
        goto LAB_0055c428;
      }
      if (DAT_0073578c != 0) {
        iVar4 = *(int *)(DAT_0073578c + 8);
        if ((iVar4 == 0) ||
           (((iVar8 = FUN_004fd1e0(iVar4 + 0xdc), iVar8 == 0 &&
             (iVar8 = FUN_004fd1e0(iVar4 + 0xec), iVar8 == 0)) || (iVar8 == 0)))) goto LAB_0055c428;
        goto LAB_0055c3ed;
      }
    }
    local_6c[-2] = 1;
    *local_6c = 0;
    FUN_0041f160(*(undefined4 *)(local_70 + 0x10),0,0,0xc);
    param_2 = param_2 + 1;
    local_6c = local_6c + 0x82;
    local_68 = local_68 + -1;
    *(uint *)(local_70 + 0x1c) = *(uint *)(local_70 + 0x1c) | 0x20;
    if (local_68 == 0) {
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x55c4c0 FUN_0055c4c0

void * __thiscall FUN_0055c4c0(void *param_1,byte param_2)

{
  FUN_0055c4e0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55c4e0 FUN_0055c4e0

void FUN_0055c4e0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bc99c;
  local_4 = 0;
  DAT_00734bc8 = 0;
  eh_vector_destructor_iterator(param_1 + 0x1e,0x208,4,FUN_0041f140);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x55c550 FUN_0055c550

void FUN_0055c550(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  char *local_2c;
  int *local_28;
  byte local_20;
  byte local_1f [31];
  
  iVar8 = 0;
  local_28 = (int *)(param_1 + 0x40);
  local_2c = &DAT_00734f90;
  do {
    local_20 = 0;
    pbVar7 = local_1f;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      pbVar7[0] = 0;
      pbVar7[1] = 0;
      pbVar7[2] = 0;
      pbVar7[3] = 0;
      pbVar7 = pbVar7 + 4;
    }
    iVar8 = iVar8 + 1;
    pbVar7[0] = 0;
    pbVar7[1] = 0;
    pbVar7[2] = 0;
    bSPrintf_regdst(0x20,"PLAYER_DATA_%.2d",iVar8);
    iVar6 = -1;
    pbVar7 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar7 + 1;
      iVar6 = iVar6 * 0x21 + (uint)bVar3;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0055c645:
      if (iVar9 == 0) {
LAB_0055c658:
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar6);
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_0055c645;
          goto LAB_0055c624;
        }
        goto LAB_0055c658;
      }
LAB_0055c624:
      if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar4 == 0))
      goto LAB_0055c645;
    }
    *local_28 = iVar4;
    iVar6 = 0;
    if ((local_2c == (char *)0x0) || (*local_2c == '\0')) {
LAB_0055c67d:
      pcVar5 = (char *)LanguageStrings__FindByHash();
      if (pcVar5 == (char *)0x0) {
        pcVar5 = (char *)LanguageStrings__FindByHash();
      }
    }
    else {
      do {
        iVar9 = iVar6 + 1;
        iVar6 = iVar6 + 1;
      } while (local_2c[iVar9] != '\0');
      pcVar5 = local_2c;
      if (iVar6 == 0) goto LAB_0055c67d;
    }
    FEngPrintf(pcVar5);
    local_2c = local_2c + 0xd;
    local_28 = local_28 + 1;
    if (0x734fc3 < (int)local_2c) {
      return;
    }
  } while( true );
}


// ==== 0x55c6e0 FUN_0055c6e0

void __fastcall FUN_0055c6e0(int param_1)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  *(undefined4 *)(in_EAX + 0x50) = 0;
  do {
    if (*(int *)(in_EAX + 0x40 + *(int *)(in_EAX + 0x50) * 4) == param_1) break;
    iVar3 = *(int *)(in_EAX + 0x50) + 1;
    *(int *)(in_EAX + 0x50) = iVar3;
  } while (iVar3 < 4);
  pcVar4 = &DAT_00734f90 + *(int *)(in_EAX + 0x50) * 0xd;
  iVar3 = 0;
  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
    do {
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while (pcVar4[iVar1] != '\0');
    if (iVar3 != 0) {
      FUN_004ebcb0();
      iVar3 = *(int *)(in_EAX + 0x50);
      cVar2 = (&DAT_00734f90)[iVar3 * 0xd];
      pcVar4 = (char *)(in_EAX + 0x54);
      *pcVar4 = cVar2;
      if (cVar2 != '\0') {
        pcVar5 = pcVar4;
        do {
          cVar2 = pcVar5[(int)(&DAT_00734f90 + iVar3 * 0xd + (1 - (int)pcVar4))];
          pcVar5 = pcVar5 + 1;
          *pcVar5 = cVar2;
        } while (cVar2 != '\0');
      }
      FUN_0054da00(pcVar4,FUN_0055ce00);
      return;
    }
  }
  DAT_0070108e = 1;
  FUN_0041f4d0();
  return;
}


// ==== 0x55c790 FUN_0055c790

void __fastcall FUN_0055c790(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  char *pcVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_EAX + 0x50) = 0;
  do {
    if (*(int *)(in_EAX + 0x40 + *(int *)(in_EAX + 0x50) * 4) == param_2) break;
    iVar1 = *(int *)(in_EAX + 0x50) + 1;
    *(int *)(in_EAX + 0x50) = iVar1;
  } while (iVar1 < 4);
  pcVar2 = &DAT_00734f90 + *(int *)(in_EAX + 0x50) * 0xd;
  iVar1 = 0;
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    do {
      iVar1 = iVar1 + 1;
    } while (pcVar2[iVar1] != '\0');
    if (0 < iVar1) {
      local_14 = 0x9c7511d8;
      local_10 = 0x9c7511d8;
      local_8 = 0;
      local_4 = 0;
      local_24 = 0x81900702;
      local_20 = 0x639;
      local_1c = 3;
      local_18 = 0x541389e5;
      local_c = 0xb8a7c6cd;
      FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(in_EAX + 0xc));
    }
  }
  return;
}


// ==== 0x55c840 FUN_0055c840

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
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
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
    FUN_0054d920(pcVar1,FUN_0055cdc0);
    return;
  case 2:
    if (DAT_00735da4 != 0) {
      FUN_004ebdf0(DAT_00735da4,0);
    }
    iVar7 = DAT_00734f84;
    if (DAT_00734f84 == 0) {
      FEngPrintf(param_1 + 0x54);
      FUN_0054dd10();
      FUN_004ebcb0();
      bStrCpy();
      FUN_0054da00(param_1 + 0x54,FUN_0055ce00);
      return;
    }
    iVar5 = LanguageStrings__FindByHash();
    if (iVar5 == 0) {
      iVar5 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar5);
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
    FUN_0054d990(uVar3,FUN_0055cde0);
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
      FEngPrintf(iVar7);
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


// ==== 0x55cd50 FUN_0055cd50

void FUN_0055cd50(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_EAX + 100);
  iVar2 = 4;
  do {
    if ((*piVar1 != 0) && (DAT_007064b2 != '\0')) {
      FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x55cdc0 FUN_0055cdc0

void FUN_0055cdc0(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55cde0 FUN_0055cde0

void FUN_0055cde0(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55ce00 FUN_0055ce00

void FUN_0055ce00(void)

{
  FEngQueueMessageToPackage();
  return;
}


// ==== 0x55ce20 FUN_0055ce20

void __thiscall FUN_0055ce20(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *unaff_EBX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f63;
  local_c = ExceptionList;
  param_2 = param_2 + 1;
  ExceptionList = &local_c;
  unaff_EBX[7] = param_1;
  bSPrintf_regdst(0x20,"PLAYERNAME%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_0055ce80:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055ce80;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055ce80;
  }
  unaff_EBX[1] = iVar2;
  bSPrintf_regdst(0x20,"REPDATA%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_0055ced6:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055ced6;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055ced6;
  }
  unaff_EBX[2] = iVar2;
  bSPrintf_regdst(0x20,"REPTITLE%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_0055cf2c:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055cf2c;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055cf2c;
  }
  unaff_EBX[3] = iVar2;
  bSPrintf_regdst(0x20,"PLAYERCARNAME%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_0055cf82:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055cf82;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055cf82;
  }
  unaff_EBX[4] = iVar2;
  bSPrintf_regdst(0x20,"CARTITLE%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_0055cfd8:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055cfd8;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055cfd8;
  }
  unaff_EBX[5] = iVar2;
  bSPrintf_regdst(0x20,"PING_GROUP_%.2d",param_2);
  pvVar3 = _malloc(0x18);
  uVar1 = 0;
  local_4 = 0;
  if (pvVar3 != (void *)0x0) {
    uVar1 = FUN_0055e900();
  }
  local_4 = 0xffffffff;
  *unaff_EBX = uVar1;
  bSPrintf_regdst(0x20,"PINGTITLE%.2d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_0055d084;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(uVar1);
  }
LAB_0055d084:
  unaff_EBX[6] = iVar2;
  ExceptionList = local_c;
  return;
}


// ==== 0x55d0a0 FUN_0055d0a0

void FUN_0055d0a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_ESI;
  
  FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 4));
  FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 8));
  FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x10));
  FEngPrintf(param_1);
  FEngPrintf(param_2);
  FEngPrintf(param_3);
  return;
}


// ==== 0x55d100 FUN_0055d100

undefined4 FUN_0055d100(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688773;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0055d160(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x55d160 FUN_0055d160

undefined4 * FUN_0055d160(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688753;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006bc8e0;
  FUN_00598420();
  param_1[0x1e] = 0x83015b7a;
  param_1[0x20] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x20] = 0;
  FUN_0055dc20(param_1);
  FUN_0055dcf0();
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  if (param_1[3] == 0) {
LAB_0055d1f8:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xda9a39d5);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055d1f8;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055d1f8;
  }
  param_1[0x15] = iVar2;
  if (param_1[3] == 0) {
LAB_0055d239:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xda9a39d4);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055d239;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055d239;
  }
  param_1[0x16] = iVar2;
  if (param_1[3] == 0) {
LAB_0055d27a:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xda96ef8f);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0055d27a;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0055d27a;
  }
  param_1[0x17] = iVar2;
  if (param_1[3] != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_0055d2d7;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(0xda96ef8e);
  }
LAB_0055d2d7:
  param_1[0x18] = iVar2;
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
  param_1[0x19] = iVar2;
  *(undefined1 *)(param_1 + 0x21) = 0;
  DAT_00734dc0 = param_1;
  DAT_00734dbd = 0;
  DAT_007301cc = FUN_0055dbc0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x55d370 FUN_0055d370

void * __thiscall FUN_0055d370(void *param_1,byte param_2)

{
  FUN_0055d390(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55d390 FUN_0055d390

void FUN_0055d390(undefined4 *param_1)

{
  undefined4 *_Memory;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00688753;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006bc8e0;
  local_4 = 1;
  puVar2 = param_1 + 0x11;
  iVar3 = 4;
  do {
    _Memory = (undefined4 *)*puVar2;
    if (_Memory != (undefined4 *)0x0) {
      if ((void *)*_Memory != (void *)0x0) {
        _free((void *)*_Memory);
      }
      _free(_Memory);
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  piVar1 = (int *)param_1[0x1a];
  while (piVar1 != param_1 + 0x1a) {
    puVar2 = (undefined4 *)FUN_00556910();
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    piVar1 = (int *)param_1[0x1a];
  }
  DAT_007301cc = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_005567f0();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x55d450 FUN_0055d450

void __thiscall FUN_0055d450(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (param_2 == 0x406415e3) {
    if ((param_4 & 1) != 0) {
      DAT_00748f78 = 0;
      FUN_0055da00();
      return;
    }
    if ((param_4 & 2) == 0) {
      if ((param_4 & 4) == 0) {
        DAT_00748f78 = (-(uint)((param_4 & 8) != 0) & 4) - 1;
        FUN_0055da00();
        return;
      }
      DAT_00748f78 = 2;
      FUN_0055da00();
      return;
    }
    DAT_00748f78 = 1;
    FUN_0055da00();
    return;
  }
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 < 0x911ab365) {
        if (param_2 == 0x911ab364) {
          DAT_00777cb0 = 0xffffffff;
          if (DAT_0073dafc == -1) {
            FUN_0055db70();
            return;
          }
          iVar1 = FEngFindPackage();
          if (iVar1 != 0) {
            *(undefined4 *)(iVar1 + 0x1c) = 0;
          }
          FUN_0054a7e0(0);
          return;
        }
        if (param_2 != 0xaffffa0) {
          if (param_2 != 0x406415e3) {
            return;
          }
          FUN_0055da00();
          return;
        }
        FUN_0043a220(1);
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x911c0a4b) {
        return;
      }
      if (param_3 == 0) {
        return;
      }
      if (*(int *)(param_3 + 0x10) != 0x6386b231) {
        return;
      }
      if (DAT_00734dbd == '\0') {
        return;
      }
      if (DAT_0073578c == 0) {
        return;
      }
      cFEng__SetCurrentButton(DAT_0073578c);
      return;
    }
  }
  else {
    if (0xc98356ba < param_2) {
      if (param_2 != 0xfed0fed0) {
        return;
      }
      iVar1 = FEngFindPackage();
      if (iVar1 == 0) {
        return;
      }
      *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      return;
    }
    if (param_2 == 0xc98356ba) {
      FUN_0055d7a0(param_1);
      FUN_0055dcf0();
      if (DAT_0077b240 == 2) {
        FUN_0043aba0();
      }
      iVar1 = *(int *)(param_1 + 0x80);
      if (iVar1 == 0) {
        return;
      }
      if (iVar1 == 0x7fffffff) {
        return;
      }
      if (DAT_0073ad3c <= iVar1) {
        return;
      }
      iVar1 = FEngFindPackage();
      if (iVar1 == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x80) = 0;
      FUN_004ec3c0();
      FEngQueueMessageToPackage();
      return;
    }
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc519bfc3) {
        return;
      }
      GenericDialogData__GenericDialogData();
      uStack_34 = *(undefined4 *)(param_1 + 0x78);
      uStack_14 = 1;
      uStack_38 = 0x169268;
      uStack_c = 0;
      uStack_8 = 0;
      uStack_10 = 0x639;
      FUN_004dcfd0(&uStack_38,*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  if (param_3 != 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0x75666f7) {
      if ((DAT_00777b58 == 0) && (DAT_0073dafc == -1)) {
        FUN_0055dfa0();
        return;
      }
    }
    else if (iVar1 == 0x6386b231) {
      if ((DAT_00777b58 == 0) && (DAT_0073dafc == -1)) {
        FUN_0055e030();
        return;
      }
    }
    else if (((iVar1 == -0x7e2653f) && (DAT_00734dbd != '\0')) && (DAT_0073578c != 0)) {
      cFEng__SetCurrentButton(DAT_0073578c);
      return;
    }
  }
  return;
}


// ==== 0x55d7a0 FUN_0055d7a0

void FUN_0055d7a0(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_8;
  
  piVar6 = (int *)(param_1 + 0x54);
  local_8 = 4;
  do {
    if (((*piVar6 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 != '\0')) {
      uVar4 = *(undefined4 *)(*piVar6 + 0x10);
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
         (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar3 = FUN_004ef050(uVar4);
          goto LAB_0055d850;
        }
      }
      else {
LAB_0055d850:
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,*piVar6,*(undefined4 *)(param_1 + 100),iVar3,0);
        }
      }
      uVar1 = *(uint *)(*piVar6 + 0x10);
      if (uVar1 < 0xda9a39d5) {
        if (uVar1 == 0xda9a39d4) {
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
             (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
            if (DAT_0073578c == 0) goto LAB_0055d8fb;
            iVar3 = FUN_004ef050(0x75666f7);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar6,*(undefined4 *)(param_1 + 100),iVar3,0);
          }
        }
        else if (uVar1 == 0xda96ef8e) {
          uVar4 = *(undefined4 *)(param_1 + 100);
          uVar5 = FEngFindObject();
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0x9120409e,*piVar6,uVar4,uVar5,0);
          }
        }
        else if (uVar1 == 0xda96ef8f) {
          uVar4 = FEngFindObject();
          FEngSendMessageToObject(0x9120409e,uVar4);
        }
      }
      else if (uVar1 == 0xda9a39d5) {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
           (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
          if (DAT_0073578c == 0) goto LAB_0055d8fb;
          iVar3 = FUN_004ef050(0x6386b231);
        }
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xb5971bf1,*piVar6,*(undefined4 *)(param_1 + 100),iVar3,0);
        }
      }
    }
LAB_0055d8fb:
    piVar6 = piVar6 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x55da00 FUN_0055da00

void FUN_0055da00(void)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_00777b58 != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    DAT_00734dbd = 1;
    if ((DAT_0073578c != 0) && (cFEng__SetCurrentButton(DAT_0073578c), DAT_0073578c != 0)) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
    if (((*(int *)(DAT_00734dc0 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
       (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0x2d865d6b);
      }
    }
    FEObject__SetInvisible(iVar1);
    FUN_0054a4e0(FUN_0055e5f0);
    *(undefined4 *)(in_EAX + 0x78) = 0xf3704876;
    return;
  }
  FUN_00495f00(0xa8f7bf1b);
  FUN_00495f00(0x4fc29dca);
  FUN_00495f00(0xced06599);
  if (DAT_0073dafc != -1) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    FUN_0054a660();
    return;
  }
  *(undefined1 *)(in_EAX + 0x7c) = 1;
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  FUN_0054a370(&DAT_00734718,FUN_0055e770);
  return;
}


// ==== 0x55db70 FUN_0055db70

undefined4 FUN_0055db70(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x55dbc0 FUN_0055dbc0

undefined4 FUN_0055dbc0(void)

{
  int iVar1;
  
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    if (DAT_00735da4 != 0) {
      FUN_004ebdf0(DAT_00735da4,0);
    }
    *(undefined4 *)(DAT_00734dc0 + 0x80) = 0;
  }
  FUN_004ee3a0(0xaffffa0,0);
  return 0;
}


// ==== 0x55dc20 FUN_0055dc20

void FUN_0055dc20(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685feb;
  local_c = ExceptionList;
  iVar3 = 0;
  puVar4 = (undefined4 *)(param_1 + 0x44);
  ExceptionList = &local_c;
  do {
    local_4 = 0xffffffff;
    pvVar1 = _malloc(0x20);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0055ce20(iVar3);
    }
    *puVar4 = uVar2;
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
    local_4 = 0xffffffff;
  } while (iVar3 < 4);
  if (DAT_00777b58 == 0) {
    FUN_00495f00(0xe08b290f);
    FUN_00495f00(0x72613f82);
    *(undefined4 *)(param_1 + 0x78) = 0x678fd4b9;
  }
  else {
    FUN_00495f00(0xcb006f6c);
    *(undefined4 *)(param_1 + 0x78) = 0x83015b7a;
  }
  *(undefined1 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  FUN_0055e170(param_1);
  ExceptionList = local_c;
  return;
}


// ==== 0x55dcf0 FUN_0055dcf0

void FUN_0055dcf0(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int extraout_EDX;
  int extraout_EDX_00;
  int *piVar10;
  char *pcVar11;
  undefined1 *puVar12;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char local_80 [128];
  
  FUN_0055e3b0(in_EAX);
  local_90 = -1;
  if (DAT_0073dafc == -1) {
    local_90 = DAT_00777cb0;
  }
  if (DAT_0073d8d0 != 0) {
    iVar5 = local_90;
    if (local_90 == -1) {
      iVar5 = DAT_0073dafc;
    }
    uVar4 = FUN_00664d40(DAT_0073d8d0,5,iVar5);
    iVar5 = FUN_00666ea0(DAT_0073d8dc,uVar4);
    if (iVar5 != 0) {
      local_88 = *(int *)(iVar5 + 0x24c);
      local_84 = 0;
      local_8c = 0;
      piVar10 = (int *)(in_EAX + 0x44);
      goto LAB_0055dd90;
    }
  }
  local_88 = 0;
  local_84 = 0;
  local_8c = 0;
  piVar10 = (int *)(in_EAX + 0x44);
LAB_0055dd90:
  do {
    iVar5 = DAT_0073d8d0;
    if (local_84 < local_88) {
      FUN_0059fb30(0x80);
      if (iVar5 == 0) {
LAB_0055ddf0:
        pcVar11 = "";
      }
      else {
        iVar8 = local_90;
        if (local_90 == -1) {
          iVar8 = DAT_0073dafc;
        }
        uVar4 = FUN_00664d40(iVar5,5,iVar8);
        iVar5 = FUN_00666ea0(DAT_0073d8dc,uVar4);
        if (iVar5 == 0) goto LAB_0055ddf0;
        pcVar11 = (char *)(local_8c + 0x84 + iVar5);
      }
      pcVar6 = pcVar11;
      do {
        cVar1 = pcVar6[(int)(local_80 + -(int)pcVar11)];
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 != cVar2) {
        iVar5 = FUN_0054b700(&DAT_0073d868,pcVar11);
        if ((iVar5 != 0) && (iVar5 = FUN_00549e50(&DAT_0073d868), iVar5 != 0)) {
          GetCarModelNameHash();
        }
        iVar5 = LanguageStrings__FindByHash();
        if (iVar5 == 0) {
          iVar5 = LanguageStrings__FindByHash();
        }
        uVar4 = DAT_00777cb4;
        if (DAT_0073d8d0 == 0) {
LAB_0055dead:
          puVar12 = &DAT_006b9172;
        }
        else {
          iVar8 = local_90;
          if (local_90 == -1) {
            iVar8 = DAT_0073dafc;
          }
          uVar7 = FUN_00664d40(DAT_0073d8d0,5,iVar8);
          iVar8 = FUN_00666ea0(DAT_0073d8dc,uVar7);
          if (iVar8 == 0) goto LAB_0055dead;
          puVar12 = (undefined1 *)(local_8c + 0x84 + iVar8);
        }
        uVar4 = FUN_0054a0c0(local_84,uVar4);
        FUN_0055d0a0(puVar12,uVar4,iVar5);
      }
      iVar5 = FUN_0054a1d0(local_84,0);
      if ((iVar5 < 0) && (*(int *)(*(int *)*piVar10 + 0x10) < 0)) {
        FUN_0054a1d0(local_84,1);
      }
      FEObject__SetVisible(*(undefined4 *)(*piVar10 + 4));
      FEObject__SetVisible(*(undefined4 *)(extraout_EDX + 8));
      FEObject__SetVisible(*(undefined4 *)(extraout_EDX_00 + 0x10));
      FUN_0055e980();
    }
    else {
      piVar3 = (int *)*piVar10;
      FEObject__SetInvisible(piVar3[1]);
      FEObject__SetInvisible(piVar3[2]);
      FEObject__SetInvisible(piVar3[4]);
      iVar5 = *piVar3;
      *(undefined4 *)(iVar5 + 0x10) = 0xffffffff;
      iVar8 = *(int *)(*(int *)(iVar5 + 0x14) + 0x5c);
      iVar9 = -1;
      if (iVar8 < -1) {
        iVar9 = iVar8;
      }
      if (*(int *)(iVar5 + 4) != iVar9) {
        *(int *)(iVar5 + 4) = iVar9;
        FUN_0055ea40(iVar5);
      }
    }
    local_8c = local_8c + 0x20;
    local_84 = local_84 + 1;
    piVar10 = piVar10 + 1;
    if (0x7f < local_8c) {
      return;
    }
  } while( true );
}


// ==== 0x55dfa0 FUN_0055dfa0

void FUN_0055dfa0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  iVar4 = *(int *)(unaff_ESI + 0x70);
  if (in_EAX == -0x6edfbf62) {
    iVar1 = FUN_00556770();
    if (iVar4 == iVar1) goto LAB_0055dfe5;
    uVar2 = FUN_005567b0();
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_0055dfe5;
    iVar1 = *(int *)(unaff_ESI + 0x70);
    iVar3 = FUN_005567b0();
    if (iVar1 == iVar3) goto LAB_0055dfe5;
    uVar2 = FUN_00556770();
  }
  *(undefined4 *)(unaff_ESI + 0x70) = uVar2;
LAB_0055dfe5:
  iVar1 = *(int *)(unaff_ESI + 0x70);
  if (iVar1 != iVar4) {
    if (*(char *)(iVar1 + 0x10) == '\0') {
      iVar4 = RaceOptions_Get();
      *(int *)(iVar4 + 8) = (int)*(short *)(*(int *)(iVar1 + 0xc) + 0x6c);
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(*(int *)(unaff_ESI + 0x70) + 0x18);
    }
    FUN_0055e3b0(unaff_ESI);
  }
  FUN_0055dcf0();
  return;
}


// ==== 0x55e030 FUN_0055e030

void __fastcall FUN_0055e030(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if ((DAT_00777cb4 == 0) || (DAT_00777cb4 == 2)) {
    iVar1 = RaceOptions_Get();
    if (in_EAX == -0x6edfbf62) {
      iVar2 = *(int *)(iVar1 + 0x10) + -1;
      *(int *)(iVar1 + 0x10) = iVar2;
      if (iVar2 < 2) {
        *(undefined4 *)(iVar1 + 0x10) = 2;
      }
      iVar1 = RaceOptions_Get();
      *(int *)(iVar1 + 8) = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x6c);
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0x70) + 0x18);
      FUN_0055dcf0();
      return;
    }
    if (in_EAX == -0x4a68e40f) {
      iVar2 = *(int *)(iVar1 + 0x10) + 1;
      *(int *)(iVar1 + 0x10) = iVar2;
      if (10 < iVar2) {
        *(undefined4 *)(iVar1 + 0x10) = 10;
      }
      FUN_0055e320();
    }
  }
  FUN_0055dcf0();
  return;
}


// ==== 0x55e0d0 FUN_0055e0d0

void FUN_0055e0d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685193;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x1c);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_00556750();
    *puVar1 = &PTR_FUN_006bcde8;
    puVar1[3] = param_1;
    puVar1[5] = 0;
    puVar1[6] = param_2;
  }
  local_4 = 0xffffffff;
  if (puVar1 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = puVar1 + 1;
  }
  FUN_005568d0(puVar2);
  *(int *)(unaff_EDI + 0x74) = *(int *)(unaff_EDI + 0x74) + 1;
  *(undefined1 *)(puVar1 + 4) = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x55e170 FUN_0055e170

void FUN_0055e170(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int local_4;
  
  iVar4 = 0;
  if (0 < DAT_0073616c) {
    local_4 = 0;
    do {
      if (((DAT_00736168 == 0) || (local_4 < 0)) || (DAT_0073616c <= iVar4)) {
        iVar3 = 0;
      }
      else {
        iVar3 = local_4 + DAT_00736168;
      }
      iVar1 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
      if (iVar1 != 0) {
        FUN_0055e0d0(iVar3,0);
      }
      iVar4 = iVar4 + 1;
      local_4 = local_4 + 0xfc;
    } while (iVar4 < DAT_0073616c);
  }
  if (DAT_00777cb4 != 2) {
    iVar4 = 0;
    local_4 = 0;
    if (0 < DAT_0073616c) {
      do {
        if (((DAT_00736168 == 0) || (iVar4 < 0)) || (DAT_0073616c <= local_4)) {
          iVar3 = 0;
        }
        else {
          iVar3 = DAT_00736168 + iVar4;
        }
        iVar1 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
        if (iVar1 != 0) {
          FUN_0055e0d0(iVar3,1);
        }
        local_4 = local_4 + 1;
        iVar4 = iVar4 + 0xfc;
      } while (local_4 < DAT_0073616c);
    }
  }
  puVar5 = (undefined *)0x0;
  switch(DAT_00777cc8) {
  case 0:
    puVar5 = &DAT_00758980;
    break;
  case 1:
    puVar5 = &DAT_007589a0;
    break;
  case 2:
    puVar5 = &DAT_007589c0;
    break;
  case 3:
    puVar5 = &DAT_007589e0;
    break;
  case 4:
    puVar5 = &DAT_00758a04;
    break;
  case 5:
    puVar5 = &DAT_00758a88;
    break;
  case 6:
    puVar5 = &DAT_00758ab4;
  }
  if (*(int *)(puVar5 + 8) != -1) {
    iVar4 = FUN_0055e350(*(int *)(puVar5 + 8));
    *(int *)(param_1 + 0x70) = iVar4;
    if (iVar4 == 0) {
      uVar2 = FUN_00556770();
      *(undefined4 *)(param_1 + 0x70) = uVar2;
    }
    return;
  }
  iVar4 = FUN_00556770();
  *(int *)(param_1 + 0x70) = iVar4;
  *(int *)(puVar5 + 8) = (int)*(short *)(*(int *)(iVar4 + 0xc) + 0x6c);
  *(undefined4 *)(puVar5 + 0xc) = 0;
  return;
}


// ==== 0x55e320 FUN_0055e320

void FUN_0055e320(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = RaceOptions_Get();
  *(int *)(iVar1 + 8) = (int)*(short *)(*(int *)(*(int *)(unaff_ESI + 0x70) + 0xc) + 0x6c);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(*(int *)(unaff_ESI + 0x70) + 0x18);
  return;
}


// ==== 0x55e350 FUN_0055e350

int FUN_0055e350(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  
  iVar1 = FUN_00556770();
  iVar2 = FUN_00556890();
  if (iVar1 != iVar2) {
    do {
      if ((*(short *)(*(int *)(iVar1 + 0xc) + 0x6c) == param_1) &&
         (*(int *)(iVar1 + 0x18) == unaff_EBX)) {
        return iVar1;
      }
      iVar1 = FUN_00556770();
      iVar2 = FUN_00556890();
    } while (iVar1 != iVar2);
  }
  return 0;
}


// ==== 0x55e3b0 FUN_0055e3b0

void FUN_0055e3b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = RaceOptions_Get();
  iVar2 = FUN_0055e350(*(undefined4 *)(iVar1 + 8));
  if ((iVar2 != 0) && (iVar2 != *(int *)(param_1 + 0x70))) {
    *(int *)(param_1 + 0x70) = iVar2;
  }
  uVar3 = FUN_004ad6d0(*(undefined4 *)(*(int *)(param_1 + 0x70) + 0x18));
  FUN_00495f00(uVar3);
  bSPrintf_regdst(0x20,"LapsData");
  if ((DAT_00777cb4 == 1) || (DAT_00777cb4 == 3)) {
    FEngPrintf(&DAT_006ca778,0);
  }
  else {
    FEngPrintf(&DAT_006ca778,*(undefined4 *)(iVar1 + 0x10));
  }
  if ((((DAT_00777cb4 != 1) && (DAT_00777cb4 != 3)) && (DAT_00777b58 != 1)) &&
     ((DAT_00777b58 != 4 && (DAT_0073dafc == -1)))) goto LAB_0055e594;
  iVar1 = *(int *)(param_1 + 0xc);
  uVar3 = FEng__HashName();
  if ((iVar1 == 0) ||
     ((iVar1 = FEngFindPackage(), iVar1 == 0 || (iVar1 = FUN_004ffb70(), iVar1 == 0)))) {
    if (DAT_0073578c != 0) {
      iVar1 = FUN_004ef050(uVar3);
      goto LAB_0055e4d5;
    }
  }
  else {
LAB_0055e4d5:
    if (iVar1 != 0) {
      for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        iVar4 = FEng__HashName();
        if (*(int *)(iVar2 + 0x30) == iVar4) {
          if (iVar2 != 0) {
            if (iVar2 != *(int *)(iVar1 + 0x54)) {
              *(int *)(iVar1 + 0x54) = iVar2;
              FUN_004ff030(iVar1);
              *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar2 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0xc);
  uVar3 = FEng__HashName();
  if (((iVar1 == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) goto LAB_0055e594;
    iVar1 = FUN_004ef050(uVar3);
  }
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar4 = FEng__HashName();
      if (*(int *)(iVar2 + 0x30) == iVar4) {
        if (iVar2 != 0) {
          if (iVar2 != *(int *)(iVar1 + 0x54)) {
            *(int *)(iVar1 + 0x54) = iVar2;
            FUN_004ff030(iVar1);
            *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar2 + 0x10) = 0;
        }
        break;
      }
    }
  }
LAB_0055e594:
  if (((DAT_00777b58 == 1) || (DAT_00777b58 == 4)) || (DAT_0073dafc != -1)) {
    FEngSetScript("GreyOut",1);
    FEngSetScript("GreyOut",1);
  }
  return;
}


// ==== 0x55e5f0 FUN_0055e5f0

void FUN_0055e5f0(void)

{
  int iVar1;
  
  iVar1 = DAT_0073d8e0;
  FEngQueueMessageToPackage();
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 < 0x696e676e) {
    if ((iVar1 == 0x696e676d) || (iVar1 == 0x616a6f69)) goto LAB_0055e6a1;
    if (iVar1 == 0x61737461) {
      FEngQueueMessageToPackage();
      goto LAB_0055e6a1;
    }
    if (iVar1 == 0x66756c6c) goto LAB_0055e6a1;
  }
  else if (((iVar1 == 0x70617373) || (iVar1 == 0x74696d65)) || (iVar1 == 0x7567616d))
  goto LAB_0055e6a1;
  FUN_0054d4a0(&DAT_0073d868,iVar1);
LAB_0055e6a1:
  FUN_004ee3a0(0,0);
  return;
}


// ==== 0x55e6d0 FUN_0055e6d0

void FUN_0055e6d0(void)

{
  int iVar1;
  
  iVar1 = DAT_0073d8e0;
  FEngQueueMessageToPackage();
  if (iVar1 == 0) {
    FEngQueueMessageToPackage();
    return;
  }
  if (iVar1 < 0x74696d66) {
    if (iVar1 == 0x74696d65) goto LAB_0055e74b;
    if (iVar1 == 0x61737461) {
      return;
    }
    if (iVar1 == 0x67687374) goto LAB_0055e74b;
  }
  else if (iVar1 == 0x7567616d) goto LAB_0055e74b;
  FUN_0054d4a0(&DAT_0073d868,iVar1);
LAB_0055e74b:
  FUN_004ee3a0(0,0);
  return;
}


// ==== 0x55e770 FUN_0055e770

void FUN_0055e770(void)

{
  int iVar1;
  char cStack_6;
  char cStack_5;
  
  iVar1 = DAT_0073d8e0;
  FEngQueueMessageToPackage();
  if (iVar1 != 0) {
    cStack_6 = (char)((uint)iVar1 >> 0x10);
    cStack_5 = (char)((uint)iVar1 >> 0x18);
    FUN_00565da0("%c%c%c%c",(int)cStack_5,(int)cStack_6,(int)(char)((uint)iVar1 >> 8),
                 (int)(char)iVar1);
  }
  return;
}


// ==== 0x55e7c0 FUN_0055e7c0

void FUN_0055e7c0(void)

{
  int iVar1;
  
  iVar1 = DAT_0073d8e0;
  if (DAT_0073d8e0 != 0) {
    FEngQueueMessageToPackage();
    if ((iVar1 != 0x6e65706c) && (iVar1 != 0x74696d65)) {
      FUN_0054d4a0(&DAT_0073d868,iVar1);
    }
    FUN_004ee3a0(0,0);
  }
  return;
}


// ==== 0x55e830 FUN_0055e830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055e830(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_004ee3a0(0x911ab364,0);
  }
  else if (param_1 == 1) {
    DAT_00777b58 = 4;
    _DAT_00777b5c = 4;
    DAT_00777b54 = 0;
    DAT_00777cb4 = 0;
    DAT_00777c30 = 0;
    DAT_00777c70 = 0;
    DAT_00777c90 = 0;
    DAT_00777cb0 = 0;
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    FUN_004ebcb0();
    uVar2 = _ftol_nocw();
    *(undefined4 *)(DAT_00734dc0 + 0x80) = uVar2;
    return;
  }
  return;
}


// ==== 0x55e900 FUN_0055e900

void FUN_0055e900(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = unaff_EDI;
  unaff_ESI[1] = in_EAX;
  uVar1 = FEng__HashName();
  if (((unaff_EDI == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  unaff_ESI[5] = iVar2;
  unaff_ESI[4] = -1;
  unaff_ESI[2] = *(uint *)(iVar2 + 0x5c) / 3;
  unaff_ESI[3] = (uint)(*(int *)(iVar2 + 0x5c) << 1) / 3;
  FUN_0055ea40(unaff_ESI);
  return;
}


// ==== 0x55e980 FUN_0055e980

void FUN_0055e980(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((*(int *)(unaff_ESI + 0x10) < 1) || (0 < unaff_EDI)) {
    *(int *)(unaff_ESI + 0x10) = unaff_EDI;
    if (unaff_EDI < 1) {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x5c);
      iVar3 = 1;
      if (iVar1 < 1) {
        iVar3 = iVar1;
      }
    }
    else {
      uVar2 = *(uint *)(*(int *)(unaff_ESI + 0x14) + 0x5c);
      iVar3 = uVar2 - unaff_EDI / (int)(300 / (ulonglong)uVar2);
      if (iVar3 < 1) {
        iVar3 = 1;
      }
      if (iVar3 < 0) {
        iVar3 = -1;
        *(undefined4 *)(unaff_ESI + 0x10) = 0xffffffff;
      }
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x5c);
      if (iVar1 < iVar3) {
        iVar3 = iVar1;
      }
    }
    if (*(int *)(unaff_ESI + 4) != iVar3) {
      *(int *)(unaff_ESI + 4) = iVar3;
      FUN_0055ea40(unaff_ESI);
    }
  }
  return;
}


// ==== 0x55e9f0 FUN_0055e9f0

int __fastcall FUN_0055e9f0(char *param_1)

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
  param_1 = param_1 + iVar3 + -2;
  iVar3 = 0;
  cVar2 = *param_1;
  while (((cVar2 != '\0' && ('/' < cVar2)) && (cVar2 < ':'))) {
    param_1 = param_1 + 1;
    iVar3 = cVar2 + -0x30 + iVar3 * 10;
    cVar2 = *param_1;
  }
  return iVar3;
}


// ==== 0x55ea40 FUN_0055ea40

void FUN_0055ea40(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int extraout_EDX;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x60);
  do {
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(param_1 + 4) == -1) {
      FEObject__SetInvisible();
    }
    else {
      FEObject__SetVisible(iVar1);
      iVar2 = *(int *)(extraout_EDX + 4);
      iVar4 = FUN_0055e9f0();
      if (iVar4 + -1 < iVar2) {
        if (*(int *)(param_1 + 8) < iVar2) {
          if (*(int *)(param_1 + 0xc) < iVar2) {
            if (*(int *)(iVar1 + 0x18) < 0x100) {
              cVar3 = FEColor_NearlyEqual();
              if (cVar3 == '\0') {
                *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
              }
              goto LAB_0055eb84;
            }
          }
          else if (*(int *)(iVar1 + 0x18) < 0x100) {
            cVar3 = FEColor_NearlyEqual();
            if (cVar3 == '\0') {
              *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
            }
LAB_0055eb84:
            FUN_004ff2f0(iVar1,0,0);
          }
        }
        else if (*(int *)(iVar1 + 0x18) < 0x100) {
          cVar3 = FEColor_NearlyEqual();
          if (cVar3 == '\0') {
            *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
          }
          goto LAB_0055eb84;
        }
      }
      else if (*(int *)(iVar1 + 0x18) < 0x100) {
        cVar3 = FEColor_NearlyEqual();
        if (cVar3 == '\0') {
          *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
        }
        goto LAB_0055eb84;
      }
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}


// ==== 0x55ebb0 FUN_0055ebb0

void FUN_0055ebb0(void)

{
  int in_EAX;
  
  FUN_004ad6d0(*(undefined4 *)(in_EAX + 0x18));
  return;
}


// ==== 0x55ebd0 FUN_0055ebd0

undefined4 FUN_0055ebd0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687663;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x138);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0055ec30(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x55ec30 FUN_0055ec30

undefined4 * FUN_0055ec30(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687643;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar4 = param_1 + 0x17;
  *param_1 = &PTR_FUN_006bc80c;
  puVar1 = param_1 + 0x19;
  *puVar4 = puVar4;
  param_1[0x18] = puVar4;
  *puVar1 = puVar1;
  param_1[0x1a] = puVar1;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 100;
  param_1[0x20] = 10;
  param_1[0x21] = 0xb;
  param_1[0x22] = 0;
  *(undefined1 *)(param_1 + 0x23) = 1;
  param_1[0x24] = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 1;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)((int)param_1 + 0x135) = 0;
  puVar4 = param_1 + 0x28;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_4 = 1;
  FUN_0054ae10(FUN_00560660,param_1);
  FUN_0054a2e0(FUN_005605f0,param_1);
  FUN_0055fd00();
  FUN_0055f2a0();
  *(undefined1 *)(param_1 + 8) = 1;
  piVar5 = param_1 + 0x10;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  if (param_1[3] == 0) {
LAB_0055ed5a:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda9a39d5);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0055ed5a;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0055ed5a;
  }
  param_1[0x10] = iVar3;
  if (param_1[3] == 0) {
LAB_0055ed9a:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda9a39d4);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0055ed9a;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0055ed9a;
  }
  param_1[0x11] = iVar3;
  if (param_1[3] == 0) {
LAB_0055eddb:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda96ef8f);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0055eddb;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0055eddb;
  }
  param_1[0x12] = iVar3;
  if (param_1[3] == 0) {
LAB_0055ee1c:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda96ef8e);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0055ee1c;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0055ee1c;
  }
  param_1[0x13] = iVar3;
  if (param_1[3] == 0) {
LAB_0055ee5d:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfd7);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_0055ee5d;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_0055ee5d;
  }
  param_1[0x14] = iVar3;
  if (param_1[3] != 0) {
    iVar3 = FEngFindPackage();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_0055eeba;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(0xaa68bfc6);
  }
LAB_0055eeba:
  param_1[0x15] = iVar3;
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
  param_1[0x16] = iVar3;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x55ef30 FUN_0055ef30

void * __thiscall FUN_0055ef30(void *param_1,byte param_2)

{
  FUN_0055ef50();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x55ef50 FUN_0055ef50

void __fastcall FUN_0055ef50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc80c;
  DAT_0073d898 = 0;
  DAT_0073d89c = 0;
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


// ==== 0x55efe0 FUN_0055efe0

void __thiscall FUN_0055efe0(int param_1,uint param_2)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 < 0x911ab365) {
        if (param_2 == 0x911ab364) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (param_2 == 0x5073ef13) goto LAB_0055f07a;
        if (param_2 != 0x72619778) {
          return;
        }
      }
      else if (param_2 != 0x911c0a4b) {
        return;
      }
      FUN_0055fc20();
      return;
    }
LAB_0055f05a:
    FUN_0055fb60();
    return;
  }
  if (param_2 < 0xc98356bb) {
    if (param_2 == 0xc98356ba) {
      FUN_0055f380();
      FUN_0055f090();
      return;
    }
    if (param_2 == 0xb5971bf1) goto LAB_0055f05a;
    if (param_2 < 0xc519bfc1) {
      return;
    }
    if (0xc519bfc2 < param_2) {
      return;
    }
  }
  else if (param_2 != 0xd9feec59) {
    return;
  }
LAB_0055f07a:
  FUN_0055fca0();
  return;
}


// ==== 0x55f000 FUN_0055f000

void FUN_0055f000(void)

{
  int in_EAX;
  
  if (in_EAX != 0x72619778) {
    return;
  }
  FUN_0055fc20();
  return;
}


// ==== 0x55f090 FUN_0055f090

void FUN_0055f090(void)

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
  local_8 = 6;
  do {
    if ((*piVar5 != 0) && (DAT_007064b2 != '\0')) {
      cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar2 != '\0') {
        uVar6 = *(undefined4 *)(*piVar5 + 0x10);
        if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_0055f11e:
          if (DAT_0073578c != 0) {
            iVar3 = FUN_004ef050(uVar6);
            goto LAB_0055f132;
          }
        }
        else {
          iVar3 = FEngFindPackage();
          if (iVar3 == 0) goto LAB_0055f11e;
          iVar3 = FUN_004ffb70();
          if (iVar3 == 0) goto LAB_0055f11e;
LAB_0055f132:
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xc407210,*piVar5,*(undefined4 *)(unaff_EBX + 0x58),iVar3,0);
          }
        }
        uVar1 = *(uint *)(*piVar5 + 0x10);
        if (uVar1 < 0xda96ef90) {
          if (uVar1 == 0xda96ef8f) {
            iVar3 = FEPackageList__FindByName(&DAT_00746104);
            if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
               (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
              (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x5073ef13,0,0,*(int *)(iVar3 + 0x18));
            }
            iVar3 = FEPackageList__FindByName(&DAT_00746104);
            if (((iVar3 != 0) && (iVar7 = *(int *)(iVar3 + 0x18), iVar7 != 0)) &&
               (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
              uVar6 = 0xc519bfc1;
LAB_0055f274:
              (**(code **)(*piVar4 + 8))(uVar6,0,0,iVar7);
            }
          }
          else if (uVar1 == 0xaa68bfc6) {
            FUN_004c96c0(0x911c0a4b);
          }
          else if (uVar1 == 0xaa68bfd7) {
            FUN_004c96c0(0x72619778);
          }
          else if (uVar1 == 0xda96ef8e) {
            FUN_004c96c0(0x9120409e);
          }
        }
        else if (uVar1 == 0xda9a39d4) {
          iVar3 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar3 != 0) && (iVar7 = *(int *)(iVar3 + 0x18), iVar7 != 0)) &&
             (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
            uVar6 = 0xb5971bf1;
            goto LAB_0055f274;
          }
        }
        else if (uVar1 == 0xda9a39d5) {
          FUN_004c96c0(0xd9feec59);
          FUN_004c96c0(0xc519bfc2);
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


// ==== 0x55f2a0 FUN_0055f2a0

void FUN_0055f2a0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  int in_EAX;
  int *piVar5;
  int iVar6;
  
  if (0 < *(int *)(in_EAX + 0x84)) {
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
      FUN_00562390(in_EAX,uVar3);
      FUN_00562390(in_EAX,uVar3);
      bVar4 = iVar6 < *(int *)(in_EAX + 0x84);
      iVar6 = iVar6 + 1;
    } while (bVar4);
  }
  FUN_004f9240(in_EAX + 0x5c);
  return;
}


// ==== 0x55f380 FUN_0055f380

void FUN_0055f380(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_EAX;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  undefined1 *puVar14;
  undefined4 *local_118;
  int local_114;
  undefined1 local_10c [8];
  undefined1 local_104 [8];
  undefined1 local_fc [8];
  undefined1 local_f4 [8];
  int local_ec;
  int local_e8;
  undefined4 *local_e4;
  int local_e0 [4];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [12];
  
  if (*(char *)(in_EAX + 0x8c) != '\0') {
    iVar1 = in_EAX + 0x5c;
    *(undefined1 *)(in_EAX + 0x8c) = 0;
    FUN_004f9340(iVar1);
    FUN_005603e0();
    local_114 = *(int *)(in_EAX + 0x90);
    local_e8 = *(int *)(in_EAX + 0x84) + local_114;
    if (local_114 < local_e8) {
      local_e4 = (undefined4 *)(in_EAX + 100);
      do {
        puVar6 = local_e4;
        local_118 = _malloc(0x10);
        if (local_118 == (undefined4 *)0x0) {
          local_118 = (undefined4 *)0x0;
        }
        else {
          puVar4 = local_118 + 2;
          *puVar4 = puVar4;
          local_118[3] = puVar4;
        }
        puVar4 = (undefined4 *)puVar6[1];
        *puVar4 = local_118;
        puVar6[1] = local_118;
        local_118[1] = puVar4;
        *local_118 = puVar6;
        if (*(int *)(in_EAX + 0x70) == 0) {
          *(undefined4 *)(in_EAX + 0x70) = *puVar6;
        }
        if (*(int *)(in_EAX + 0x6c) == 0) {
          *(undefined4 *)(in_EAX + 0x6c) = *puVar6;
        }
        if (DAT_0073d8d0 == 0) {
          iVar12 = 0;
        }
        else if (DAT_0073d8a8 == 0) {
          iVar12 = 0;
        }
        else {
          iVar12 = FUN_00666f30(DAT_0073d8a8,local_114);
        }
        if ((local_114 == *(int *)(in_EAX + 0x7c)) && (*(char *)(in_EAX + 0x135) == '\x01')) {
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          FUN_004f9240(iVar1);
          return;
        }
        local_ec = local_114 + 1;
        iVar9 = local_ec;
        if (((local_114 == *(int *)(in_EAX + 0x7c)) && (*(char *)(in_EAX + 0x135) == '\0')) &&
           (*(char *)(in_EAX + 0x134) == '\x01')) {
          iVar5 = *(int *)(in_EAX + 0x78);
          if (iVar5 == 0) {
            iVar9 = *(int *)(in_EAX + 0xa0);
          }
          else if (iVar5 == 1) {
            iVar9 = *(int *)(in_EAX + 0xbc);
          }
          else if (iVar5 == 2) {
            iVar9 = *(int *)(in_EAX + 0xd8);
          }
          else if (iVar5 == 3) {
            iVar9 = *(int *)(in_EAX + 0xf4);
          }
          else if (iVar5 == 4) {
            iVar9 = *(int *)(in_EAX + 0x110);
          }
        }
        bSPrintf_regdst(8,&DAT_006ca778,iVar9);
        StringList__AddEntry(local_118,local_10);
        if (iVar12 == 0) {
          if (*(int *)(in_EAX + 0x7c) <= local_114) {
            piVar10 = (int *)(in_EAX + 0xa0);
            piVar13 = local_e0;
            for (iVar12 = 0x23; iVar12 != 0; iVar12 = iVar12 + -1) {
              *piVar13 = *piVar10;
              piVar10 = piVar10 + 1;
              piVar13 = piVar13 + 1;
            }
            StringList__AddEntry(local_118,&DAT_00734718);
            local_50[0] = DAT_00734718;
            if (DAT_00734718 != '\0') {
              iVar12 = 0;
              do {
                cVar2 = (&DAT_00734719)[iVar12];
                local_50[iVar12 + 1] = cVar2;
                iVar12 = iVar12 + 1;
              } while (cVar2 != '\0');
            }
            goto LAB_0055f5e1;
          }
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
          StringList__AddEntry(local_118,&DAT_0078ea8d);
        }
        else {
          FUN_006682f0(iVar12 + 0x28,local_e0,0x8c,&DAT_006bd444);
          pcVar11 = (char *)(iVar12 + 8);
          StringList__AddEntry(local_118,pcVar11);
          local_50[0] = *pcVar11;
          if (*pcVar11 != '\0') {
            pcVar8 = local_50;
            do {
              cVar2 = pcVar11[1];
              pcVar11 = pcVar11 + 1;
              pcVar8 = pcVar8 + 1;
              *pcVar8 = cVar2;
            } while (cVar2 != '\0');
          }
LAB_0055f5e1:
          if (*(int *)(in_EAX + 0x88) == 0) {
            iVar12 = *(int *)(in_EAX + 0x78);
            if (iVar12 == 0) {
              FUN_00565da0(&DAT_006ca778,local_d0);
              FUN_00565da0(&DAT_006ca778,local_e0[1]);
              FUN_00565da0(&DAT_006ca778,local_e0[2]);
LAB_0055f823:
              uVar7 = _ftol_nocw();
              FUN_00565da0("%d%%%%",uVar7);
            }
            else {
              if (iVar12 == 1) {
                FUN_00565da0(&DAT_006ca778,local_b4);
                FUN_00565da0(&DAT_006ca778,local_c0);
                FUN_00565da0(&DAT_006ca778,local_bc);
                goto LAB_0055f823;
              }
              if (iVar12 == 2) {
                FUN_00565da0(&DAT_006ca778,local_98);
                FUN_00565da0(&DAT_006ca778,local_a4);
                FUN_00565da0(&DAT_006ca778,local_a0);
                goto LAB_0055f823;
              }
              if (iVar12 == 3) {
                FUN_00565da0(&DAT_006ca778,local_7c);
                FUN_00565da0(&DAT_006ca778,local_88);
                FUN_00565da0(&DAT_006ca778,local_84);
                iVar9 = local_84 + local_88;
                iVar12 = local_88;
LAB_0055f81c:
                FUN_005605d0(in_EAX,iVar12,iVar9);
                goto LAB_0055f823;
              }
              if (iVar12 == 4) {
                FUN_00565da0(&DAT_006ca778,local_60);
                FUN_00565da0(&DAT_006ca778,local_6c);
                FUN_00565da0(&DAT_006ca778,local_68);
                iVar9 = local_68 + local_6c;
                iVar12 = local_6c;
                goto LAB_0055f81c;
              }
            }
            StringList__AddEntry(local_118,local_30);
            StringList__AddEntry(local_118,local_f4);
            StringList__AddEntry(local_118,local_10c);
            puVar14 = local_fc;
LAB_0055fa8c:
            StringList__AddEntry(local_118,puVar14);
          }
          else if (*(int *)(in_EAX + 0x88) == 1) {
            iVar12 = *(int *)(in_EAX + 0x78);
            if (iVar12 == 0) {
              FUN_00565da0(&DAT_006ca778,local_cc);
              FUN_00565da0(&DAT_006ca778,local_c8);
LAB_0055fa43:
              uVar7 = _ftol_nocw();
              FUN_00565da0("%d%%%%",uVar7);
            }
            else {
              if (iVar12 == 1) {
                FUN_00565da0(&DAT_006ca778,local_b0);
                FUN_00565da0(&DAT_006ca778,local_ac);
                goto LAB_0055fa43;
              }
              if (iVar12 == 2) {
                FUN_00565da0(&DAT_006ca778,local_94);
                FUN_00565da0(&DAT_006ca778,local_90);
                iVar12 = local_a0 + local_a4;
                uVar7 = local_9c;
LAB_0055fa3d:
                FUN_005605d0(in_EAX,uVar7,iVar12);
                goto LAB_0055fa43;
              }
              if (iVar12 == 3) {
                FUN_00565da0(&DAT_006ca778,local_78);
                FUN_00565da0(&DAT_006ca778,local_74);
                iVar12 = local_84 + local_88;
                uVar7 = local_80;
                goto LAB_0055fa3d;
              }
              if (iVar12 == 4) {
                FUN_00565da0(&DAT_006ca778,local_5c);
                FUN_00565da0(&DAT_006ca778,local_58);
                iVar12 = local_68 + local_6c;
                uVar7 = local_64;
                goto LAB_0055fa3d;
              }
            }
            StringList__AddEntry(local_118,local_40);
            StringList__AddEntry(local_118,local_20);
            StringList__AddEntry(local_118,&DAT_0078ea8d);
            puVar14 = local_104;
            goto LAB_0055fa8c;
          }
          iVar12 = 0;
          do {
            cVar2 = local_50[iVar12];
            cVar3 = (&DAT_00734718)[iVar12];
            iVar12 = iVar12 + 1;
            if ((cVar2 == '\0') || (cVar3 == '\0')) break;
          } while (cVar2 == cVar3);
          if ((cVar2 == cVar3) && (*(int *)(in_EAX + 300) == *(int *)(in_EAX + 0x130))) {
            FUN_0055fe30((local_114 - *(int *)(in_EAX + 0x90)) + 1,0xffffffff);
          }
        }
        local_114 = local_ec;
      } while (local_ec < local_e8);
    }
    FUN_004f9240(iVar1);
  }
  return;
}


// ==== 0x55fb60 FUN_0055fb60

void FUN_0055fb60(void)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  
  FUN_005600c0(*(undefined4 *)(unaff_EBX + 0x98));
  *(undefined4 *)(unaff_EBX + 300) = 0;
  *(undefined4 *)(unaff_EBX + 0x130) = 1;
  *(undefined1 *)(unaff_EBX + 0x94) = 0;
  *(undefined1 *)(unaff_EBX + 0x8c) = 1;
  if (in_EAX == -0x6edfbf62) {
    iVar1 = *(int *)(unaff_EBX + 0x78) + -1;
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_0055fbae;
    iVar1 = *(int *)(unaff_EBX + 0x78) + 1;
  }
  *(int *)(unaff_EBX + 0x78) = iVar1;
LAB_0055fbae:
  iVar1 = *(int *)(unaff_EBX + 0x78);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (3 < iVar1) {
    iVar1 = 4;
  }
  *(int *)(unaff_EBX + 0x78) = iVar1;
  if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || ((iVar1 == 3 || (iVar1 == 4)))) {
    FUN_0054ae10(FUN_00560660,unaff_EBX);
  }
  FUN_0055fd00();
  return;
}


// ==== 0x55fc20 FUN_0055fc20

void FUN_0055fc20(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  
  FUN_005600c0(*(undefined4 *)(in_EAX + 0x98));
  *(undefined1 *)(in_EAX + 0x8c) = 1;
  if (unaff_ESI == 0x72619778) {
    uVar3 = *(int *)(in_EAX + 0x90) - *(int *)(in_EAX + 0x80);
    *(uint *)(in_EAX + 0x90) = uVar3;
    *(uint *)(in_EAX + 0x90) = uVar3 & ((int)uVar3 < 0) - 1;
    return;
  }
  if (unaff_ESI == -0x6ee3f5b5) {
    iVar1 = *(int *)(in_EAX + 0x90) + *(int *)(in_EAX + 0x80);
    *(int *)(in_EAX + 0x90) = iVar1;
    iVar2 = *(int *)(in_EAX + 0x7c) - *(int *)(in_EAX + 0x80);
    if (iVar1 <= iVar2) {
      iVar2 = iVar1;
    }
    *(int *)(in_EAX + 0x90) = iVar2;
  }
  return;
}


// ==== 0x55fca0 FUN_0055fca0

void __fastcall FUN_0055fca0(int param_1)

{
  uint in_EAX;
  
  if (in_EAX < 0xc519bfc3) {
    if (in_EAX != 0xc519bfc2) {
      if ((in_EAX != 0x5073ef13) && (in_EAX != 0xc519bfc1)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x88) = 0;
      FUN_0055fd00();
      *(undefined1 *)(param_1 + 0x8c) = 1;
      return;
    }
  }
  else if (in_EAX != 0xd9feec59) {
    return;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  FUN_0055fd00();
  *(undefined1 *)(param_1 + 0x8c) = 1;
  return;
}


// ==== 0x55fd00 FUN_0055fd00

void FUN_0055fd00(void)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_00495f00(*(undefined4 *)(&DAT_006b6280 + *(int *)(unaff_ESI + 0x78) * 4));
  FUN_00495f00(*(undefined4 *)(&DAT_006b6294 + *(int *)(unaff_ESI + 0x88) * 4));
  FUN_00495f00(*(undefined4 *)(&DAT_006b629c + *(int *)(unaff_ESI + 0x88) * 4));
  if (*(int *)(unaff_ESI + 0x88) != 0) {
    if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_0055fddf:
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0x9beafbec);
      }
    }
    else {
      iVar1 = FEngFindPackage();
      if (iVar1 == 0) goto LAB_0055fddf;
      iVar1 = FUN_004ffb70();
      if (iVar1 == 0) goto LAB_0055fddf;
    }
    FEObject__SetInvisible(iVar1);
    goto LAB_0055fe04;
  }
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_0055fd7e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x9beafbec);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_0055fd7e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_0055fd7e;
  }
  FEObject__SetVisible(iVar1);
  FUN_00495f00(*(undefined4 *)(&DAT_006b62a4 + *(int *)(unaff_ESI + 0x88) * 4));
LAB_0055fe04:
  FUN_00495f00(*(undefined4 *)(&DAT_006b62ac + *(int *)(unaff_ESI + 0x88) * 4));
  return;
}


// ==== 0x55fe30 FUN_0055fe30

void FUN_0055fe30(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  
  bSPrintf_regdst(0x20,"Rank_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  if (*(int *)(unaff_EBX + 0x98) == 0) {
    uVar1 = FUN_0049fc90();
    *(undefined4 *)(unaff_EBX + 0x9c) = uVar1;
  }
  FUN_004f75b0(param_2);
  bSPrintf_regdst(0x20,"PlayersName_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(param_2);
  bSPrintf_regdst(0x20,"Rep_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(param_2);
  bSPrintf_regdst(0x20,"Win_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(param_2);
  bSPrintf_regdst(0x20,"Losses_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(param_2);
  bSPrintf_regdst(0x20,"NumberOfPlayers_DATA_%02d",param_1);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(param_2);
  *(undefined4 *)(unaff_EBX + 0x98) = param_1;
  return;
}


// ==== 0x5600c0 FUN_005600c0

void FUN_005600c0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x98) != 0) {
    bSPrintf_regdst(0x20,"Rank_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    bSPrintf_regdst(0x20,"PlayersName_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    bSPrintf_regdst(0x20,"Rep_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    bSPrintf_regdst(0x20,"Win_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    bSPrintf_regdst(0x20,"Losses_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    bSPrintf_regdst(0x20,"NumberOfPlayers_DATA_%02d",param_1);
    iVar2 = *(int *)(unaff_EDI + 0xc);
    uVar1 = FEng__HashName();
    if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x9c));
    *(undefined4 *)(unaff_EDI + 0x98) = 0;
  }
  return;
}


// ==== 0x560350 FUN_00560350

void __fastcall FUN_00560350(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = param_2;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    *param_2 = 9999;
    param_2[5] = 0x65;
    param_2[4] = 100;
    param_2[6] = *(int *)(unaff_ESI + 0x7c) + 1;
    param_2[7] = 9999;
    param_2[0xc] = 0x65;
    param_2[0xb] = 100;
    param_2[0xd] = *(int *)(unaff_ESI + 0x7c) + 1;
    param_2[0xe] = 9999;
    param_2[0x13] = 0x65;
    param_2[0x12] = 100;
    param_2[0x14] = *(int *)(unaff_ESI + 0x7c) + 1;
    param_2[0x15] = 9999;
    param_2[0x1a] = 0x65;
    param_2[0x19] = 100;
    param_2[0x1b] = *(int *)(unaff_ESI + 0x7c) + 1;
    param_2[0x1c] = 9999;
    param_2[0x21] = 0x65;
    param_2[0x20] = 100;
    param_2[0x22] = *(int *)(unaff_ESI + 0x7c) + 1;
    *(undefined1 *)(unaff_ESI + 0x135) = 0;
  }
  return;
}


// ==== 0x5603e0 FUN_005603e0

void FUN_005603e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  char extraout_CL;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x94) != '\0') {
    return;
  }
  if ((((DAT_0073d8d0 != 0) && (DAT_0073d8a8 != 0)) &&
      (iVar1 = FUN_00664d00(DAT_0073d8d0,6,&DAT_00734718), iVar1 != 0)) &&
     (iVar1 = FUN_00666ea0(DAT_0073d8a8,iVar1), iVar1 != 0)) {
    FUN_0054a2a0();
    *(undefined1 *)(unaff_ESI + 0x94) = 1;
    *(undefined1 *)(unaff_ESI + 0x135) = 1;
  }
  cVar4 = '\x01';
  if (((*(char *)(unaff_ESI + 0x94) != '\0') ||
      (*(int *)(unaff_ESI + 300) != *(int *)(unaff_ESI + 0x130))) ||
     (*(char *)(unaff_ESI + 0x134) != '\x01')) goto LAB_0056057d;
  iVar1 = *(int *)(unaff_ESI + 0x78);
  if (iVar1 == 0) {
    iVar1 = *(int *)(unaff_ESI + 0xa8) + *(int *)(unaff_ESI + 0xa4);
    uVar2 = *(undefined4 *)(unaff_ESI + 0xac);
LAB_0056053c:
    FUN_005605d0(unaff_ESI,uVar2,iVar1);
    cVar4 = extraout_CL;
  }
  else {
    if (iVar1 == 1) {
      iVar1 = *(int *)(unaff_ESI + 0xc4) + *(int *)(unaff_ESI + 0xc0);
      uVar2 = *(undefined4 *)(unaff_ESI + 200);
      goto LAB_0056053c;
    }
    if (iVar1 == 2) {
      iVar1 = *(int *)(unaff_ESI + 0xe0) + *(int *)(unaff_ESI + 0xdc);
      uVar2 = *(undefined4 *)(unaff_ESI + 0xe4);
      goto LAB_0056053c;
    }
    if (iVar1 == 3) {
      iVar1 = *(int *)(unaff_ESI + 0xfc) + *(int *)(unaff_ESI + 0xf8);
      uVar2 = *(undefined4 *)(unaff_ESI + 0x100);
      goto LAB_0056053c;
    }
    cVar4 = '\x01';
    if (iVar1 == 4) {
      iVar1 = *(int *)(unaff_ESI + 0x118) + *(int *)(unaff_ESI + 0x114);
      uVar2 = *(undefined4 *)(unaff_ESI + 0x11c);
      goto LAB_0056053c;
    }
  }
  *(undefined1 *)(unaff_ESI + 0x135) = 0;
  *(char *)(unaff_ESI + 0x94) = cVar4;
LAB_0056057d:
  if (*(char *)(unaff_ESI + 0x94) == cVar4) {
    iVar1 = *(int *)(unaff_ESI + 0x80);
    iVar3 = _ftol_nocw();
    iVar1 = *(int *)(unaff_ESI + 0x7c) - iVar1;
    *(int *)(unaff_ESI + 0x90) = iVar3;
    if (iVar1 <= iVar3) {
      iVar3 = iVar1;
    }
    *(int *)(unaff_ESI + 0x90) = iVar3;
  }
  return;
}


// ==== 0x5605d0 FUN_005605d0

float10 FUN_005605d0(undefined4 param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    return (float10)0.0;
  }
  return (float10)param_2 / (float10)param_3;
}


// ==== 0x5605f0 FUN_005605f0

void FUN_005605f0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 != 0) {
    puVar3 = (undefined4 *)(param_3 + 0xa0);
    for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    uVar1 = FUN_00667530(param_1,&DAT_006bc81c,(undefined4 *)(param_3 + 0xa0),0x8c,&DAT_006bd444);
    FUN_006682f0(uVar1);
    if (*(int *)(param_3 + 0xa8) + *(int *)(param_3 + 0xa4) == 0) {
      FUN_00560350();
    }
    *(undefined1 *)(param_3 + 0x134) = 1;
    *(undefined1 *)(param_3 + 0x8c) = 1;
  }
  return;
}


// ==== 0x560660 FUN_00560660

void FUN_00560660(undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_3 + 300) = param_1;
  *(undefined4 *)(param_3 + 0x130) = param_2;
  *(undefined1 *)(param_3 + 0x8c) = 1;
  return;
}


// ==== 0x560680 FUN_00560680

void __fastcall FUN_00560680(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bc7e4;
  FUN_004f7b50();
  return;
}


// ==== 0x560690 FUN_00560690

void * __thiscall FUN_00560690(void *param_1,byte param_2)

{
  FUN_00560680();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5606b0 FUN_005606b0

undefined4 FUN_005606b0(undefined4 param_1)

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
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00560710(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x560710 FUN_00560710

undefined4 * FUN_00560710(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar2 = param_1[3];
  local_4 = 0;
  *param_1 = &PTR_FUN_006bc7e4;
  uVar1 = FEng__HashName();
  if (iVar2 == 0) {
LAB_00560770:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_00560788;
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00560770;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00560770;
LAB_00560788:
    if (*(int *)(iVar2 + 0x18) == 2) goto LAB_00560790;
  }
  iVar2 = 0;
LAB_00560790:
  param_1[0x10] = iVar2;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5607b0 FUN_005607b0

int __thiscall FUN_005607b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (param_2 == 0xc407210) {
    param_2 = param_3;
    if (param_3 != 0) {
      param_2 = *(int *)(param_3 + 0x10);
      if (param_2 == 0x97f4b79) {
        param_2 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      }
      else if (param_2 == -0x3c47dc1c) {
        iVar1 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return iVar1;
      }
    }
  }
  else if (param_2 == -0x6ee54c9c) {
    param_2 = *(int *)(param_1 + 0xc);
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
  else if (((param_2 == -0x543f76ee) && (param_2 = param_3, param_3 != 0)) &&
          ((param_2 = *(int *)(param_3 + 0x10), param_2 == 0x97f4b79 || (param_2 == -0x3c47dc1c))))
  {
    FEString__SetLabelHash();
    iVar1 = FEObject__SetScript("FadeIn",1);
    return iVar1;
  }
  return param_2;
}


// ==== 0x5608a0 FUN_005608a0

void FUN_005608a0(int param_1,uint param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    iVar2 = 200;
    puVar4 = (undefined4 *)(param_3 + 0xa4);
    do {
      if ((void *)*puVar4 != (void *)0x0) {
        _free((void *)*puVar4);
        *puVar4 = 0;
      }
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 0;
    *(undefined4 *)(param_3 + 0x3c4) = 0;
    pvVar1 = _malloc(0x51);
    *(undefined4 *)(param_3 + 0xa4) = pvVar1;
    uVar3 = 0;
    if (param_2 != 0) {
      do {
        if (*(char *)(param_1 + uVar3) == '\n') {
          *(undefined1 *)(iVar2 + *(int *)(param_3 + 0xa4 + *(int *)(param_3 + 0x3c4) * 4)) = 0;
          *(int *)(param_3 + 0x3c4) = *(int *)(param_3 + 0x3c4) + 1;
          pvVar1 = _malloc(0x51);
          *(void **)(param_3 + 0xa4 + *(int *)(param_3 + 0x3c4) * 4) = pvVar1;
          **(undefined1 **)(param_3 + 0xa4 + *(int *)(param_3 + 0x3c4) * 4) = 0;
          iVar2 = 0;
        }
        else if (iVar2 < 0x4f) {
          *(char *)(iVar2 + *(int *)(param_3 + 0xa4 + *(int *)(param_3 + 0x3c4) * 4)) =
               *(char *)(param_1 + uVar3);
          iVar2 = iVar2 + 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2);
    }
  }
  *(undefined1 *)(param_3 + 0x3c8) = 1;
  *(undefined1 *)(param_3 + 0x3c9) = 0;
  FUN_00561b50(param_3,0);
  return;
}


// ==== 0x560990 FUN_00560990

undefined4 FUN_00560990(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687603;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x3d0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005609f0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5609f0 FUN_005609f0

/* WARNING: Removing unreachable block (ram,0x00560b28) */

undefined4 * FUN_005609f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006875db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar6 = param_1 + 0x14;
  *param_1 = &PTR_FUN_006bc7c8;
  puVar1 = param_1 + 0x16;
  *puVar6 = puVar6;
  param_1[0x15] = puVar6;
  *puVar1 = puVar1;
  param_1[0x17] = puVar1;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  *(undefined1 *)(param_1 + 0xf2) = 0;
  *(undefined1 *)((int)param_1 + 0x3c9) = 0;
  param_1[0xf3] = 0;
  param_1[0xf1] = 0;
  puVar6 = param_1 + 0x29;
  for (iVar5 = 200; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  local_4 = 1;
  if (param_1[3] == 0) {
LAB_00560b2e:
    if (DAT_0073578c == 0) goto LAB_00560b48;
    uVar3 = FUN_004ef050(0xaa68bfd7);
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00560aec:
      local_4._0_1_ = 2;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      goto LAB_00560b2e;
    }
    if (DAT_0073578c != 0) {
      iVar4 = *(int *)(DAT_0073578c + 8);
      if ((iVar4 == 0) ||
         (((iVar5 = FUN_004fd1e0(iVar4 + 0xdc), iVar5 == 0 &&
           (iVar5 = FUN_004fd1e0(iVar4 + 0xec), iVar5 == 0)) || (iVar5 == 0)))) goto LAB_00560b2e;
      goto LAB_00560aec;
    }
LAB_00560b48:
    uVar3 = 0;
  }
  param_1[0x10] = uVar3;
  if (param_1[3] == 0) {
LAB_00560bee:
    if (DAT_0073578c == 0) goto LAB_00560c08;
    uVar3 = FUN_004ef050(0xaa68bfc6);
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00560bb2:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      goto LAB_00560bee;
    }
    if (DAT_0073578c != 0) {
      iVar4 = *(int *)(DAT_0073578c + 8);
      if ((iVar4 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar4 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar4 + 0xec), iVar5 == 0)))) goto LAB_00560bee;
      goto LAB_00560bb2;
    }
LAB_00560c08:
    uVar3 = 0;
  }
  param_1[0x11] = uVar3;
  iVar5 = DAT_0073578c;
  if (param_1[3] == 0) {
LAB_00560cb8:
    if (iVar5 == 0) goto LAB_00560ccd;
    uVar3 = FUN_004ef050(0xc87eef52);
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_00560c76:
      local_4._0_1_ = 4;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_00560cb8;
    }
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_00560cb8;
      goto LAB_00560c76;
    }
LAB_00560ccd:
    uVar3 = 0;
  }
  param_1[0x12] = uVar3;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  iVar5 = DAT_0073578c;
  if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if (iVar2 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004fd1e0(iVar2 + 0xdc);
        if (iVar4 == 0) {
          iVar4 = FUN_004fd1e0(iVar2 + 0xec);
        }
      }
    }
  }
  param_1[0x13] = iVar4;
  if (param_1[3] == 0) {
LAB_00560ddf:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbb0), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00560e0a;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_00560d9d:
      local_4._0_1_ = 5;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_00560ddf;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_00560ddf;
      goto LAB_00560d9d;
    }
LAB_00560e0a:
    iVar5 = 0;
  }
  param_1[0x1b] = iVar5;
  if (param_1[3] == 0) {
LAB_00560eba:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbb1), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_00560ee5;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00560e78:
      local_4._0_1_ = 6;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_00560eba;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_00560eba;
      goto LAB_00560e78;
    }
LAB_00560ee5:
    iVar4 = 0;
  }
  param_1[0x1c] = iVar4;
  if (param_1[3] == 0) {
LAB_00560f95:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbb2), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00560fc0;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_00560f53:
      local_4._0_1_ = 7;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_00560f95;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_00560f95;
      goto LAB_00560f53;
    }
LAB_00560fc0:
    iVar5 = 0;
  }
  param_1[0x1d] = iVar5;
  if (param_1[3] == 0) {
LAB_00561070:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbb3), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_0056109b;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0056102e:
      local_4._0_1_ = 8;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_00561070;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_00561070;
      goto LAB_0056102e;
    }
LAB_0056109b:
    iVar4 = 0;
  }
  param_1[0x1e] = iVar4;
  if (param_1[3] == 0) {
LAB_0056114b:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbb4), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00561176;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_00561109:
      local_4._0_1_ = 9;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_0056114b;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_0056114b;
      goto LAB_00561109;
    }
LAB_00561176:
    iVar5 = 0;
  }
  param_1[0x1f] = iVar5;
  if (param_1[3] == 0) {
LAB_00561226:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbb5), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_00561251;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005611e4:
      local_4._0_1_ = 10;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_00561226;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_00561226;
      goto LAB_005611e4;
    }
LAB_00561251:
    iVar4 = 0;
  }
  param_1[0x20] = iVar4;
  if (param_1[3] == 0) {
LAB_00561304:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbb6), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_0056132f;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_005612c2:
      local_4._0_1_ = 0xb;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_00561304;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_00561304;
      goto LAB_005612c2;
    }
LAB_0056132f:
    iVar5 = 0;
  }
  param_1[0x21] = iVar5;
  if (param_1[3] == 0) {
LAB_005613e2:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbb7), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_0056140d;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005613a0:
      local_4._0_1_ = 0xc;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_005613e2;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_005613e2;
      goto LAB_005613a0;
    }
LAB_0056140d:
    iVar4 = 0;
  }
  param_1[0x22] = iVar4;
  if (param_1[3] == 0) {
LAB_005614c0:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbb8), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_005614eb;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0056147e:
      local_4._0_1_ = 0xd;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_005614c0;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_005614c0;
      goto LAB_0056147e;
    }
LAB_005614eb:
    iVar5 = 0;
  }
  param_1[0x23] = iVar5;
  if (param_1[3] == 0) {
LAB_0056159e:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbd0), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_005615c9;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0056155c:
      local_4._0_1_ = 0xe;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_0056159e;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0056159e;
      goto LAB_0056155c;
    }
LAB_005615c9:
    iVar4 = 0;
  }
  param_1[0x24] = iVar4;
  if (param_1[3] == 0) {
LAB_0056167c:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbd1), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_005616a7;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0056163a:
      local_4._0_1_ = 0xf;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_0056167c;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_0056167c;
      goto LAB_0056163a;
    }
LAB_005616a7:
    iVar5 = 0;
  }
  param_1[0x25] = iVar5;
  if (param_1[3] == 0) {
LAB_0056175a:
    iVar5 = 0;
    if (((iVar4 == 0) || (iVar4 = FUN_004ef050(0x439ffbd2), iVar5 = DAT_0073578c, iVar4 == 0)) ||
       (*(int *)(iVar4 + 0x18) != 2)) goto LAB_00561785;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00561718:
      local_4._0_1_ = 0x10;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_0056175a;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0056175a;
      goto LAB_00561718;
    }
LAB_00561785:
    iVar4 = 0;
  }
  param_1[0x26] = iVar4;
  if (param_1[3] == 0) {
LAB_00561838:
    iVar4 = 0;
    if (((iVar5 == 0) || (iVar5 = FUN_004ef050(0x439ffbd3), iVar4 = DAT_0073578c, iVar5 == 0)) ||
       (*(int *)(iVar5 + 0x18) != 2)) goto LAB_00561863;
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_005617f6:
      local_4._0_1_ = 0x11;
      FUN_004ffb00(iVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar5 = DAT_0073578c;
      goto LAB_00561838;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_00561838;
      goto LAB_005617f6;
    }
LAB_00561863:
    iVar5 = 0;
  }
  param_1[0x27] = iVar5;
  if (param_1[3] == 0) {
LAB_00561916:
    if (((iVar4 != 0) && (iVar5 = FUN_004ef050(0x439ffbd4), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) == 2)) goto LAB_00561935;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005618d4:
      local_4._0_1_ = 0x12;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar4 = DAT_0073578c;
      goto LAB_00561916;
    }
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_00561916;
      goto LAB_005618d4;
    }
  }
  iVar5 = 0;
LAB_00561935:
  param_1[0x28] = iVar5;
  FUN_0054af80(param_1);
  FUN_00561b50(param_1,0);
  ExceptionList = local_c;
  return param_1;
}


