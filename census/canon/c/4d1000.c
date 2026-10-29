// ==== 0x4d1600 FUN_004d1600

void FUN_004d1600(undefined4 param_1,char param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  bSPrintf_regdst(0x20,"OptionName_%d",param_1);
  FUN_00414a60();
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar2 = 1;
    FEng__HashName(1);
    FUN_004f5f80(iVar1,uVar2);
  }
  bSPrintf_regdst(0x20,"OptionNametext_%d",param_1);
  FUN_00414a60();
  if (param_2 != '\0') {
    bSPrintf_regdst(0x20,"OptionData_%d",param_1);
    FUN_00414a60();
  }
  if (param_3 != '\0') {
    bSPrintf_regdst(0x20,"SelectButton_%d",param_1);
    FUN_00414a60();
  }
  return;
}


// ==== 0x4d16d0 FUN_004d16d0

void FUN_004d16d0(undefined4 param_1,char param_2)

{
  char *pcVar1;
  
  bSPrintf_regdst(0x20,"option_buttonR_%02d");
  FUN_00414a60();
  bSPrintf_regdst(0x20,"option_buttonL_%02d");
  FUN_00414a60();
  if (param_2 == '\0') {
    bSPrintf_regdst(0x20,"LeftArrow_%d");
    FUN_00414a60();
    pcVar1 = "RightArrow_%d";
  }
  else {
    bSPrintf_regdst(0x20,"minus_%02d");
    FUN_00414a60();
    pcVar1 = "plus_%02d";
  }
  bSPrintf_regdst(0x20,pcVar1);
  FUN_00414a60();
  return;
}


// ==== 0x4d1790 FUN_004d1790

void FUN_004d1790(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d17b4:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b7f);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d17b4;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d17b4;
  }
  *(int *)(unaff_ESI + 0x440) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x490) = 0x1aec7d09;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1803:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c5);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1803;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1803;
  }
  *(int *)(unaff_ESI + 0x444) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x494) = 0x1aec7d09;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d184d:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b80);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d184d;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d184d;
  }
  *(int *)(unaff_ESI + 0x448) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x498) = 0x1aec7d0a;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d189c:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c6);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d189c;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d189c;
  }
  *(int *)(unaff_ESI + 0x44c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x49c) = 0x1aec7d0a;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d18e6:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b81);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d18e6;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d18e6;
  }
  *(int *)(unaff_ESI + 0x450) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4a0) = 0x1aec7d0b;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1935:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c7);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1935;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1935;
  }
  *(int *)(unaff_ESI + 0x454) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4a4) = 0x1aec7d0b;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d197f:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b82);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d197f;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d197f;
  }
  *(int *)(unaff_ESI + 0x458) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4a8) = 0x1aec7d0c;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d19ce:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c8);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d19ce;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d19ce;
  }
  *(int *)(unaff_ESI + 0x45c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4ac) = 0x1aec7d0c;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1a18:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b83);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1a18;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1a18;
  }
  *(int *)(unaff_ESI + 0x460) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4b0) = 0x1aec7d0d;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1a67:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c9);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1a67;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1a67;
  }
  *(int *)(unaff_ESI + 0x464) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4b4) = 0x1aec7d0d;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1ab1:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b84);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1ab1;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1ab1;
  }
  *(int *)(unaff_ESI + 0x468) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4b8) = 0x1aec7d0e;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1b00:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5ca);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1b00;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1b00;
  }
  *(int *)(unaff_ESI + 0x46c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4bc) = 0x1aec7d0e;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1b4a:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b85);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1b4a;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1b4a;
  }
  *(int *)(unaff_ESI + 0x470) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4c0) = 0x1aec7d0f;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1b99:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5cb);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1b99;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1b99;
  }
  *(int *)(unaff_ESI + 0x474) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4c4) = 0x1aec7d0f;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1be3:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b86);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1be3;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1be3;
  }
  *(int *)(unaff_ESI + 0x478) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4c8) = 0x1aec7d10;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1c32:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5cc);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1c32;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1c32;
  }
  *(int *)(unaff_ESI + 0x47c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4cc) = 0x1aec7d10;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1c7c:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b87);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1c7c;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1c7c;
  }
  *(int *)(unaff_ESI + 0x480) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4d0) = 0x1aec7d11;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1ccb:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5cd);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1ccb;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1ccb;
  }
  *(int *)(unaff_ESI + 0x484) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4d4) = 0x1aec7d11;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d1d15:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b9f);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d1d15;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d1d15;
  }
  *(int *)(unaff_ESI + 0x488) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x4d8) = 0x787c1e59;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004d1d8d;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xd01ed5e5);
    *(undefined4 *)(unaff_ESI + 0x4dc) = 0x787c1e59;
    *(undefined4 *)(unaff_ESI + 0x48c) = uVar2;
    return;
  }
  iVar1 = 0;
LAB_004d1d8d:
  *(undefined4 *)(unaff_ESI + 0x4dc) = 0x787c1e59;
  *(int *)(unaff_ESI + 0x48c) = iVar1;
  return;
}


// ==== 0x4d1da0 FUN_004d1da0

void FUN_004d1da0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int local_8;
  
  piVar7 = (int *)(param_1 + 0x440);
  local_8 = 0x14;
  do {
    if (((*piVar7 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar4 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar4 != '\0')) {
      uVar1 = *(uint *)(*piVar7 + 0x10);
      if (uVar1 < 0xd01ed5ce) {
        if (uVar1 < 0xd01ed5c5) {
          if (uVar1 < 0xd01b8b88) {
            if ((0xd01b8b7e < uVar1) || ((0x4acf8b8a < uVar1 && (uVar1 < 0x4acf8b90)))) {
LAB_004d1e55:
              uVar2 = *(undefined4 *)(param_1 + 0x4e0);
              uVar5 = FUN_004f6670();
              if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
                FUN_004f0700(0x9120409e,*piVar7,uVar2,uVar5,0);
              }
            }
          }
          else if (uVar1 == 0xd01b8b9f) goto LAB_004d1e55;
        }
        else {
LAB_004d1ebe:
          iVar3 = piVar7[0x14];
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
             (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
            if (DAT_0073578c == 0) goto LAB_004d1e8d;
            iVar6 = FUN_004ef050(iVar3);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar7,*(undefined4 *)(param_1 + 0x4e0),iVar6,0);
          }
        }
      }
      else if ((uVar1 == 0xd01ed5e5) || ((0xd96a7802 < uVar1 && (uVar1 < 0xd96a7808))))
      goto LAB_004d1ebe;
    }
LAB_004d1e8d:
    piVar7 = piVar7 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4d1f30 FUN_004d1f30

void FUN_004d1f30(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 uVar8;
  int extraout_EDX_04;
  int iVar9;
  int local_28;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  local_28 = 1;
  local_24 = 6;
  do {
    bSPrintf_regdst(0x20,"OptionName_%d",local_28);
    iVar3 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d202f;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d201e;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d202f:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar3), iVar5 == 0)) goto LAB_004d2077;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d202f;
        }
LAB_004d201e:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d202f;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar3 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar3) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX + 4);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
    }
LAB_004d2077:
    iVar3 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar4 = *(int *)(iVar5 + 0x88);
      iVar9 = 0;
      if (iVar4 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar3) {
            iVar9 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar9 != 0) {
          *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) & 0xfbffffff;
        }
      }
    }
    bSPrintf_regdst(0x20,"OptionNametext_%d",local_28);
    iVar3 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d21ad;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d219c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d21ad:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar3), iVar5 == 0)) goto LAB_004d21f5;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d21ad;
        }
LAB_004d219c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d21ad;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar3 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar3) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
    }
LAB_004d21f5:
    local_28 = local_28 + 1;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"option_buttonR_%02d",iVar3);
    iVar5 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d22da;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d22c3;
    if (DAT_0073578c != 0) {
      iVar9 = *(int *)(DAT_0073578c + 8);
      if (iVar9 == 0) {
LAB_004d22da:
        if (DAT_0073578c == 0) goto LAB_004d2324;
        iVar4 = FUN_004ef050(iVar5);
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar9 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar9 + 0xec);
          if (iVar4 == 0) goto LAB_004d22da;
        }
LAB_004d22c3:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar4 == 0)) goto LAB_004d22da;
      }
      if ((iVar4 != 0) &&
         (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar4 + 0x18) == 5)) {
        uVar8 = *(undefined4 *)(iVar4 + 0x60);
        iVar5 = *(int *)(iVar4 + 0x5c);
        if (0 < iVar5) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_01 + 4);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
    }
LAB_004d2324:
    bSPrintf_regdst(0x20,"option_buttonL_%02d",iVar3);
    iVar5 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d23e9;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d23d3;
    if (DAT_0073578c != 0) {
      iVar9 = *(int *)(DAT_0073578c + 8);
      if (iVar9 == 0) {
LAB_004d23e9:
        if ((DAT_0073578c == 0) || (iVar4 = FUN_004ef050(iVar5), iVar4 == 0)) goto LAB_004d2436;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar9 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar9 + 0xec);
          if (iVar4 == 0) goto LAB_004d23e9;
        }
LAB_004d23d3:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar4 == 0)) goto LAB_004d23e9;
      }
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar4 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar4 + 0x60);
        iVar5 = *(int *)(iVar4 + 0x5c);
        if (0 < iVar5) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_02 + 4);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
    }
LAB_004d2436:
    bSPrintf_regdst(0x20,"minus_%02d",iVar3);
    iVar5 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
         (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
        ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(iVar5), iVar4 != 0)))) &&
       (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar4 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar4 + 0x60);
      iVar5 = *(int *)(iVar4 + 0x5c);
      if (0 < iVar5) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_03 + 4);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    bSPrintf_regdst(0x20,"plus_%02d",iVar3);
    iVar5 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
         (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
        ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(iVar5), iVar4 != 0)))) &&
       (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar4 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar4 + 0x60);
      iVar5 = *(int *)(iVar4 + 0x5c);
      if (0 < iVar5) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_04 + 4);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    if (5 < iVar3) {
      (**(code **)(*(int *)(param_1 + 0x15c) + 0xc))(1);
      (**(code **)(*(int *)(param_1 + 0x198) + 0xc))(1);
      (**(code **)(*(int *)(param_1 + 0x1d4) + 0xc))(1);
      (**(code **)(*(int *)(param_1 + 0x210) + 0xc))(1);
      (**(code **)(*(int *)(param_1 + 0x24c) + 0xc))(1);
      (**(code **)(*(int *)(param_1 + 0x288) + 0xc))(1);
      *(undefined4 *)(param_1 + 0x378) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cf810;
      FUN_004cf570();
      *(undefined4 *)(param_1 + 0x37c) = 2;
      *(code **)(param_1 + 0x44) = FUN_004cf8e0;
      FUN_004cf5e0();
      *(undefined4 *)(param_1 + 0x380) = 3;
      *(code **)(param_1 + 0x48) = FUN_004cf9c0;
      FUN_004cf650();
      *(undefined4 *)(param_1 + 900) = 4;
      *(code **)(param_1 + 0x4c) = FUN_004cfa90;
      FUN_004cf6c0();
      *(undefined4 *)(param_1 + 0x388) = 5;
      *(code **)(param_1 + 0x50) = FUN_004cfb60;
      FUN_004cf730();
      *(undefined4 *)(param_1 + 0x38c) = 6;
      *(code **)(param_1 + 0x54) = FUN_004cfc30;
      FUN_004cf7a0();
      FUN_00414a10();
      FUN_00414a10();
      FUN_00414a10();
      FUN_00414a10();
      return;
    }
  } while( true );
}


// ==== 0x4d2700 FUN_004d2700

void FUN_004d2700(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  FUN_004d1600(1,1,0);
  bSPrintf_regdst(0x20,"OptionName_%d",2);
  FUN_00414a60();
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar2 = 1;
    FEng__HashName(1);
    FUN_004f5f80(iVar1,uVar2);
  }
  bSPrintf_regdst(0x20,"OptionNametext_%d",2);
  FUN_00414a60();
  FUN_004d16d0(param_1,0);
  FUN_004d16d0(param_1,1);
  (**(code **)(*(int *)(param_1 + 0x6c) + 0xc))(1);
  *(undefined4 *)(param_1 + 0x3ac) = 2;
  *(code **)(param_1 + 0x44) = FUN_004cfec0;
  FUN_004cfdb0();
  *(code **)(param_1 + 0x40) = FUN_004cfe10;
  *(undefined4 *)(param_1 + 0x3a0) = 1;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  FUN_004cfd00(1);
  return;
}


// ==== 0x4d2820 FUN_004d2820

void FUN_004d2820(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  undefined4 uVar8;
  int extraout_EDX_05;
  int iVar9;
  int iVar10;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"OptionName_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d2912;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d2901;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d2912:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d295f;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d2912;
        }
LAB_004d2901:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d2912;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d295f:
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar4 = *(int *)(iVar5 + 0x88);
      iVar10 = 0;
      if (iVar4 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar9) {
            iVar10 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar10 != 0) {
          *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) & 0xfbffffff;
        }
      }
    }
    bSPrintf_regdst(0x20,"OptionNametext_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d2a9d;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d2a8c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d2a9d:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d2ae5;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d2a9d;
        }
LAB_004d2a8c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d2a9d;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d2ae5:
    bSPrintf_regdst(0x20,"OptionData_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar9), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar5 + 0x60);
      iVar9 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar9) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
  } while (iVar3 < 2);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"option_buttonR_%02d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d2c5d;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d2c4c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d2c5d:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d2ca5;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d2c5d;
        }
LAB_004d2c4c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d2c5d;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_02 + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d2ca5:
    bSPrintf_regdst(0x20,"option_buttonL_%02d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d2d64;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = FUN_00424db0(), iVar5 != 0)) goto LAB_004d2d4e;
    if (DAT_0073578c != 0) {
      iVar4 = *(int *)(DAT_0073578c + 8);
      if (iVar4 == 0) {
LAB_004d2d64:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d2da7;
      }
      else {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar4 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar4 + 0xec);
          if (iVar5 == 0) goto LAB_004d2d64;
        }
LAB_004d2d4e:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d2d64;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_03 + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d2da7:
    bSPrintf_regdst(0x20,"LeftArrow_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar9), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar5 + 0x60);
      iVar9 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar9) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_04 + 4);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    bSPrintf_regdst(0x20,"RightArrow_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar9), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar5 + 0x60);
      iVar9 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar9) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_05 + 4);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    if (1 < iVar3) {
      *(undefined4 *)(param_1 + 0x3b8) = 1;
      *(code **)(param_1 + 0x40) = FUN_004d00e0;
      FUN_004cff80();
      *(undefined4 *)(param_1 + 0x3c0) = 2;
      *(code **)(param_1 + 0x44) = FUN_004d0180;
      FUN_004d0030();
      return;
    }
  } while( true );
}


// ==== 0x4d2f60 FUN_004d2f60

void FUN_004d2f60(int param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar2);
  bSPrintf_regdst(0x20,"OptionName_%d",1);
  FUN_00414a60();
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar8 = 1;
    FEng__HashName(1);
    FUN_004f5f80(iVar2,uVar8);
  }
  bSPrintf_regdst(0x20,"OptionNametext_%d",1);
  FUN_00414a60();
  FUN_004d1600(2,1,0);
  FUN_004d16d0(param_1,0);
  *(undefined4 *)(param_1 + 0x3d0) = 1;
  *(code **)(param_1 + 0x40) = FUN_004d0350;
  *(undefined4 *)(param_1 + 0x3c8) = 2;
  *(code **)(param_1 + 0x44) = FUN_004d02c0;
  FUN_004d0210(param_1);
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3d0));
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar2);
  *(undefined1 *)(param_1 + 0x68) = 0;
  piVar3 = &DAT_0071d89c;
  do {
    if (*piVar3 != 0) {
      *(undefined1 *)(param_1 + 0x68) = 1;
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x71d8a4);
  if (*(char *)(param_1 + 0x68) == '\0') {
    pcVar5 = "OptionName_2";
    iVar2 = -1;
    bVar1 = 0x4f;
    do {
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 - 0x20;
      }
      uVar6 = (uint)bVar1;
      bVar1 = pcVar5[1];
      iVar2 = iVar2 * 0x21 + uVar6;
      pcVar5 = pcVar5 + 1;
    } while (bVar1 != 0);
    if ((((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
        (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) &&
       (iVar7 = *(int *)(iVar4 + 0x88), iVar7 != 0)) {
      piVar3 = *(int **)(iVar4 + 0x84);
      iVar4 = 0;
      do {
        if (*(int *)(*piVar3 + 0x10) == iVar2) {
          iVar4 = *piVar3;
        }
        piVar3 = piVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      if (iVar4 != 0) {
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x4000000;
      }
    }
    pcVar5 = "OptionNametext_2";
    iVar2 = -1;
    bVar1 = 0x4f;
    do {
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 - 0x20;
      }
      iVar2 = iVar2 * 0x21 + (uint)bVar1;
      bVar1 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (bVar1 != 0);
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
        (iVar4 = FUN_004ffb70(), iVar4 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(iVar2);
    }
    FUN_004f75b0(0xff606060);
    pcVar5 = "OptionData_2";
    iVar2 = -1;
    bVar1 = 0x4f;
    do {
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 - 0x20;
      }
      uVar6 = (uint)bVar1;
      bVar1 = pcVar5[1];
      iVar2 = iVar2 * 0x21 + uVar6;
      pcVar5 = pcVar5 + 1;
    } while (bVar1 != 0);
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
        (iVar4 = FUN_004ffb70(), iVar4 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(iVar2);
    }
    FUN_004f75b0(0xff606060);
    pcVar5 = "LeftArrow_2";
    iVar2 = -1;
    bVar1 = 0x4c;
    do {
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 - 0x20;
      }
      iVar2 = iVar2 * 0x21 + (uint)bVar1;
      bVar1 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (bVar1 != 0);
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
        (iVar4 = FUN_004ffb70(), iVar4 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(iVar2);
    }
    FUN_004f75b0(0xff606060);
    pcVar5 = "RightArrow_2";
    iVar2 = -1;
    bVar1 = 0x52;
    do {
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 - 0x20;
      }
      uVar6 = (uint)bVar1;
      bVar1 = pcVar5[1];
      iVar2 = iVar2 * 0x21 + uVar6;
      pcVar5 = pcVar5 + 1;
    } while (bVar1 != 0);
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
        (iVar4 = FUN_004ffb70(), iVar4 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(iVar2);
    }
    FUN_004f75b0(0xff606060);
  }
  return;
}


// ==== 0x4d32e0 FUN_004d32e0

void FUN_004d32e0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int extraout_EDX_05;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"OptionName_%d",iVar3);
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
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d33d2;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d33c1;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d33d2:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar8), iVar5 == 0)) goto LAB_004d341f;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d33d2;
        }
LAB_004d33c1:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d33d2;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar10 = *(undefined4 *)(iVar5 + 0x60);
        iVar8 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar8) {
          do {
            FEObject__SetVisible(uVar10);
            uVar10 = *(undefined4 *)(extraout_EDX + 4);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
    }
LAB_004d341f:
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
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar4 = *(int *)(iVar5 + 0x88);
      iVar9 = 0;
      if (iVar4 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar8) {
            iVar9 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar9 != 0) {
          *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) & 0xfbffffff;
        }
      }
    }
    bSPrintf_regdst(0x20,"OptionNametext_%d",iVar3);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d355d;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d354c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d355d:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar8), iVar5 == 0)) goto LAB_004d35a5;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d355d;
        }
LAB_004d354c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d355d;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar10 = *(undefined4 *)(iVar5 + 0x60);
        iVar8 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar8) {
          do {
            FEObject__SetVisible(uVar10);
            uVar10 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
    }
LAB_004d35a5:
    bSPrintf_regdst(0x20,"OptionData_%d",iVar3);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar8), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar5 + 0x60);
      iVar8 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar8) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
  } while (iVar3 < 2);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"option_buttonR_%02d",iVar3);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d371d;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d370c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d371d:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar8), iVar5 == 0)) goto LAB_004d3765;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d371d;
        }
LAB_004d370c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d371d;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar10 = *(undefined4 *)(iVar5 + 0x60);
        iVar8 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar8) {
          do {
            FEObject__SetVisible(uVar10);
            uVar10 = *(undefined4 *)(extraout_EDX_02 + 4);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
    }
LAB_004d3765:
    bSPrintf_regdst(0x20,"option_buttonL_%02d",iVar3);
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
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d3824;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = FUN_00424db0(), iVar5 != 0)) goto LAB_004d380e;
    if (DAT_0073578c != 0) {
      iVar4 = *(int *)(DAT_0073578c + 8);
      if (iVar4 == 0) {
LAB_004d3824:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar8), iVar5 == 0)) goto LAB_004d3867;
      }
      else {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar4 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar4 + 0xec);
          if (iVar5 == 0) goto LAB_004d3824;
        }
LAB_004d380e:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d3824;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar10 = *(undefined4 *)(iVar5 + 0x60);
        iVar8 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar8) {
          do {
            FEObject__SetVisible(uVar10);
            uVar10 = *(undefined4 *)(extraout_EDX_03 + 4);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
    }
LAB_004d3867:
    bSPrintf_regdst(0x20,"LeftArrow_%d",iVar3);
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
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar8), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar5 + 0x60);
      iVar8 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar8) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_04 + 4);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    bSPrintf_regdst(0x20,"RightArrow_%d",iVar3);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar8), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar5 + 0x60);
      iVar8 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar8) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_05 + 4);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    if (1 < iVar3) {
      bSPrintf_regdst(0x20,"OptionName_%d",3);
      FUN_00414a60();
      iVar3 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        uVar10 = 1;
        FEng__HashName(1);
        FUN_004f5f80(iVar3,uVar10);
      }
      bSPrintf_regdst(0x20,"OptionNametext_%d",3);
      FUN_00414a60();
      bSPrintf_regdst(0x20,"OptionName_%d",4);
      FUN_00414a60();
      iVar3 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        uVar10 = 1;
        FEng__HashName(1);
        FUN_004f5f80(iVar3,uVar10);
      }
      bSPrintf_regdst(0x20,"OptionNametext_%d",4);
      FUN_00414a60();
      FUN_004d1600(5,1,0);
      FUN_004d16d0(param_1,0);
      *(undefined4 *)(param_1 + 0x3ec) = 1;
      *(code **)(param_1 + 0x40) = FUN_004d0760;
      FUN_004d04b0();
      *(undefined4 *)(param_1 + 0x3e4) = 2;
      *(code **)(param_1 + 0x44) = FUN_004d06e0;
      FUN_004d0400();
      *(undefined4 *)(param_1 + 0x3f0) = 3;
      *(code **)(param_1 + 0x48) = FUN_004d0850;
      FUN_004d0620();
      *(undefined4 *)(param_1 + 0x3f4) = 4;
      *(code **)(param_1 + 0x4c) = FUN_004d08b0;
      FUN_004d0680();
      *(undefined4 *)(param_1 + 0x404) = 5;
      *(code **)(param_1 + 0x50) = FUN_004d0820;
      FUN_004d0570();
      return;
    }
  } while( true );
}


// ==== 0x4d3b60 FUN_004d3b60

void FUN_004d3b60(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 uVar8;
  int extraout_EDX_01;
  int iVar9;
  int iVar10;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"OptionName_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d3c52;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d3c41;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d3c52:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d3c9f;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d3c52;
        }
LAB_004d3c41:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d3c52;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d3c9f:
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar4 = *(int *)(iVar5 + 0x88);
      iVar10 = 0;
      if (iVar4 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar9) {
            iVar10 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar10 != 0) {
          *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) & 0xfbffffff;
        }
      }
    }
    bSPrintf_regdst(0x20,"OptionNametext_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d3ddd;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d3dcc;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d3ddd:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d3e25;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d3ddd;
        }
LAB_004d3dcc:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d3ddd;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d3e25:
    bSPrintf_regdst(0x20,"SelectButton_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar9), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar5 + 0x60);
      iVar9 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar9) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    if (1 < iVar3) {
      *(undefined4 *)(param_1 + 0x40c) = 1;
      *(code **)(param_1 + 0x40) = FUN_004d0a10;
      FUN_004d0900();
      *(undefined4 *)(param_1 + 0x410) = 2;
      *(code **)(param_1 + 0x44) = FUN_004d0a60;
      FUN_004d0940();
      return;
    }
  } while( true );
}


// ==== 0x4d3f30 FUN_004d3f30

void FUN_004d3f30(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 uVar8;
  int extraout_EDX_01;
  int iVar9;
  int iVar10;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"OptionName_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d4022;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d4011;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d4022:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d406f;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d4022;
        }
LAB_004d4011:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d4022;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d406f:
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar4 = *(int *)(iVar5 + 0x88);
      iVar10 = 0;
      if (iVar4 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar9) {
            iVar10 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar10 != 0) {
          *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) & 0xfbffffff;
        }
      }
    }
    bSPrintf_regdst(0x20,"OptionNametext_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) goto LAB_004d41ad;
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = FUN_00424db0(), iVar4 != 0)) goto LAB_004d419c;
    if (iVar5 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      if (iVar5 == 0) {
LAB_004d41ad:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar9), iVar5 == 0)) goto LAB_004d41f5;
      }
      else {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
        if (iVar4 == 0) {
          FUN_004ee660();
          iVar4 = FUN_004fd1e0(iVar5 + 0xec);
          if (iVar4 == 0) goto LAB_004d41ad;
        }
LAB_004d419c:
        if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004d41ad;
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar8 = *(undefined4 *)(iVar5 + 0x60);
        iVar9 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar9) {
          do {
            FEObject__SetVisible(uVar8);
            uVar8 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
LAB_004d41f5:
    bSPrintf_regdst(0x20,"SelectButton_%d",iVar3);
    iVar9 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar5 = FUN_004f65d0(), iVar5 != 0)) &&
         (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
        ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar9), iVar5 != 0)))) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar8 = *(undefined4 *)(iVar5 + 0x60);
      iVar9 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar9) {
        do {
          FEObject__SetVisible(uVar8);
          uVar8 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    if (0 < iVar3) {
      *(undefined4 *)(param_1 + 0x420) = 1;
      *(code **)(param_1 + 0x40) = FUN_004d0b20;
      FUN_004d0ab0();
      FUN_004b2480();
      return;
    }
  } while( true );
}


// ==== 0x4d42e0 FUN_004d42e0

void __fastcall FUN_004d42e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3e4c;
  FUN_004f7b50();
  return;
}


// ==== 0x4d42f0 FUN_004d42f0

void * __thiscall FUN_004d42f0(void *param_1,byte param_2)

{
  FUN_004d42e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d4310 Screen_MU_OptionsSelector_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_OptionsSelector_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687c53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_OptionsSelector_PC__Screen_MU_OptionsSelector_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d4370 Screen_MU_OptionsSelector_PC::Screen_MU_OptionsSelector_PC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_OptionsSelector_PC__Screen_MU_OptionsSelector_PC(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = &PTR_FUN_006c3e4c;
  uVar1 = FEng__HashName();
  if (((((iVar2 == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
      ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(uVar1), iVar2 == 0)))) ||
     (*(int *)(iVar2 + 0x18) != 2)) {
    iVar2 = 0;
  }
  param_1[0x10] = iVar2;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  DAT_00777cc4 = 0;
  OptionsSelectorScreen__ResetItemScripts(param_1);
  if (DAT_00735e38 == 0) {
    DAT_00735e38 = FUN_00565b60(0xf660,0,0,0);
    Ugd__PackBlock(&DAT_007588c4,0xf660);
  }
  if (((DAT_00734998 == 1) || (DAT_00734998 == 5)) ||
     ((DAT_00734998 == 3 || ((DAT_00734998 == 4 || (DAT_00734998 == 2)))))) {
    if (DAT_0073578c != 0) {
      FUN_004f5f80(DAT_0073578c,0);
    }
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x8816789f);
      }
    }
    FEObject__SetInvisible(iVar2);
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4d44d0 FUN_004d44d0

undefined4 FUN_004d44d0(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x58c164c5) {
    if (in_EAX == 0x58c164c4) {
      return 0x5c5dbd35;
    }
    if (in_EAX < 0x368a0076) {
      if (in_EAX == 0x368a0075) {
        return 0xadb16706;
      }
      if (in_EAX == 0x9955) {
        return 0xf7015f66;
      }
      if (in_EAX == 0x272d751) {
        return 0xbcbd65a2;
      }
    }
    else if (in_EAX == 0x541307a8) {
      return 0x57af6019;
    }
  }
  else if (in_EAX < 0x881678a0) {
    if (in_EAX == 0x8816789f) {
      return 0xb24c4236;
    }
    if (in_EAX == 0x689e2e13) {
      return 0xda207fff;
    }
    if (in_EAX == 0x7f007e43) {
      return 0x3105a734;
    }
  }
  else if (in_EAX == 0xfd8a3b6d) {
    return 0x74b1a1fe;
  }
  return 0;
}


// ==== 0x4d4570 FUN_004d4570

undefined4 FUN_004d4570(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  iVar1 = DAT_0073578c;
  if (DAT_00777b4c == 8) {
    if (DAT_0073578c == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return *(undefined4 *)(in_EAX + 0xc);
    }
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x18);
    if (iVar2 == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    if (DAT_0073578c == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return *(undefined4 *)(in_EAX + 0xc);
    }
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x18);
    if (iVar2 == 0) {
      DAT_00735e20 = 0;
      DAT_00777cc4 = 0;
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  uVar3 = FUN_004f0800(uVar3,iVar2);
  DAT_00735e20 = 0;
  DAT_00777cc4 = 0;
  return uVar3;
}


// ==== 0x4d4610 OptionsSelectorScreen::NotificationMessage

/* [canon] hud med (capstone) docs/re/gameflow.md */

void __thiscall OptionsSelectorScreen__NotificationMessage(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  
  if (0x35f8620b < param_2) {
    if (param_2 == 0x911ab364) {
      *(undefined1 *)(param_1 + 0x44) = 1;
    }
    else {
      if (param_2 == 0xabc08912) {
        FUN_004d44d0(param_1);
        FEString__SetLabelHash();
        FEObject__SetScript("FadeIn",1);
        return;
      }
      if (param_2 == 0xc98356ba) {
        if (*(char *)(param_1 + 0x46) == '\0') {
          if (*(char *)(param_1 + 0x44) != '\0') {
            *(undefined1 *)(param_1 + 0x44) = 0;
            cVar2 = FUN_004c9570();
            if (cVar2 != '\0') {
              FUN_004c96f0(0x12343330,0);
              return;
            }
            goto LAB_004d4641;
          }
        }
        else {
          cVar2 = FUN_004f6650();
          if (cVar2 == '\0') {
            FUN_004d4570();
            *(undefined1 *)(param_1 + 0x46) = 0;
            return;
          }
        }
      }
    }
    return;
  }
  if (param_2 == 0x35f8620b) {
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    if (DAT_0073578c != 0) {
      FEPackageList__FindByName(&DAT_00746104);
    }
    FEObject__SetScript("Highlight",1);
    return;
  }
  if (param_2 != 0xc407210) {
    if ((param_2 != 0x12342220) && (param_2 != 0x12343330)) {
      return;
    }
LAB_004d4641:
    *(undefined1 *)(param_1 + 0x46) = 1;
    return;
  }
  uVar1 = *(uint *)(param_3 + 0x10);
  if (uVar1 < 0x58c164c5) {
    if (uVar1 == 0x58c164c4) {
      DAT_00735e20 = 6;
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (uVar1 < 0x368a0076) {
      if (uVar1 == 0x368a0075) {
        DAT_00735e20 = 4;
        goto LAB_004d4677;
      }
      if (uVar1 == 0x9955) {
        DAT_00735e20 = 2;
        goto LAB_004d4677;
      }
    }
    else if (uVar1 == 0x541307a8) {
      DAT_00735e20 = 1;
      goto LAB_004d4677;
    }
  }
  else if (uVar1 < 0x881678a0) {
    if (uVar1 == 0x8816789f) {
      DAT_00735e20 = 10;
      goto LAB_004d4677;
    }
    if (uVar1 == 0x689e2e13) {
      DAT_00735e20 = 8;
      goto LAB_004d4677;
    }
    if (uVar1 == 0x7f007e43) {
      DAT_00735e20 = 3;
      goto LAB_004d4677;
    }
  }
  else if (uVar1 == 0xfd8a3b6d) {
    DAT_00735e20 = 9;
    FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  DAT_00735e20 = 0;
LAB_004d4677:
  FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4d4900 OptionsSelectorScreen::ResetItemScripts

/* [canon] hud low (capstone) docs/re/gameflow.md */

void OptionsSelectorScreen__ResetItemScripts(void)

{
  int iVar1;
  char *pcVar2;
  
  switch(DAT_00735e20) {
  case 0:
    pcVar2 = "Audio";
    break;
  case 1:
    pcVar2 = "Camera";
    break;
  case 2:
    pcVar2 = (char *)&PTR_DAT_006cae38;
    break;
  case 3:
    pcVar2 = "Controller";
    break;
  case 4:
    pcVar2 = "Display";
    break;
  default:
    goto switchD_004d490e_caseD_5;
  case 6:
    pcVar2 = "EATrax";
    break;
  case 8:
    pcVar2 = "SavingOptions";
    break;
  case 9:
    pcVar2 = "Credits";
    break;
  case 10:
    pcVar2 = "GameTrailers";
  }
  bSPrintf_regdst(0x20,pcVar2);
switchD_004d490e_caseD_5:
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    FEng__HashName();
    FUN_004f5ed0(iVar1);
  }
  return;
}


// ==== 0x4d49c0 Screen_EA_TRAX_Jukebox::Create

/* [canon] canon med (capstone) docs/re/gameflow.md */

undefined4 Screen_EA_TRAX_Jukebox__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688293;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xb4);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_EA_TRAX_Jukebox__Screen_EA_TRAX_Jukebox(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d4a20 FUN_004d4a20

void FUN_004d4a20(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688276;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c3e2c;
  iVar2 = DAT_007356a8;
  local_4 = 1;
  EAXSound__InitEATraxMasks(DAT_007356a8,0,1);
  if (DAT_006f1dd8 != 0) {
    if ((*(int *)(iVar2 + 0x104) != 0) &&
       (piVar1 = *(int **)(*(int *)(iVar2 + 0x104) + 0x14), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xa0))();
      iVar2 = DAT_007356a8;
    }
    if (((DAT_006f1dd8 != 0) && (*(int *)(iVar2 + 0x104) != 0)) &&
       (piVar1 = *(int **)(*(int *)(iVar2 + 0x104) + 0x14), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x98))(0,0xfffffffe);
    }
  }
  FUN_00494890();
  FUN_00494890();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4d4af0 FUN_004d4af0

void * __thiscall FUN_004d4af0(void *param_1,byte param_2)

{
  FUN_004d4a20(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d4b10 Screen_EA_TRAX_Jukebox::Screen_EA_TRAX_Jukebox

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_EA_TRAX_Jukebox__Screen_EA_TRAX_Jukebox(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688276;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x26;
  *param_1 = &PTR_FUN_006c3e2c;
  puVar5 = param_1 + 0x28;
  *puVar1 = puVar1;
  param_1[0x27] = puVar1;
  *puVar5 = puVar5;
  param_1[0x29] = puVar5;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  uVar3 = 0;
  local_4 = 1;
  if (DAT_0075892c == 0) {
    uVar3 = 0x197392b;
  }
  else if (DAT_0075892c == 1) {
    uVar3 = 0x1a4e8ad1;
  }
  FUN_00416bb0(uVar3);
  FUN_004d5970(param_1);
  puVar5 = param_1 + 0x10;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)(param_1 + 8) = 1;
  FUN_004d4bf0();
  if (((DAT_006f1dd8 != 0) && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
     (piVar2 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0x98))(0,0xffffffff);
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4d4bf0 FUN_004d4bf0

void FUN_004d4bf0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4c13:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b078);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4c13;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4c13;
  }
  *(int *)(unaff_ESI + 0x40) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4c54:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fe5);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4c54;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4c54;
  }
  *(int *)(unaff_ESI + 0x44) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4c95:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fe6);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4c95;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4c95;
  }
  *(int *)(unaff_ESI + 0x48) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4cd6:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07a);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4cd6;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4cd6;
  }
  *(int *)(unaff_ESI + 0x4c) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4d17:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fe7);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4d17;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4d17;
  }
  *(int *)(unaff_ESI + 0x50) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4d58:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07b);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4d58;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4d58;
  }
  *(int *)(unaff_ESI + 0x54) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4d99:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fe8);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4d99;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4d99;
  }
  *(int *)(unaff_ESI + 0x58) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4dda:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07c);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4dda;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4dda;
  }
  *(int *)(unaff_ESI + 0x5c) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4e1b:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fe9);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4e1b;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4e1b;
  }
  *(int *)(unaff_ESI + 0x60) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4e5c:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07d);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4e5c;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4e5c;
  }
  *(int *)(unaff_ESI + 100) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4e9d:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fea);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4e9d;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4e9d;
  }
  *(int *)(unaff_ESI + 0x68) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4ede:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07e);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4ede;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4ede;
  }
  *(int *)(unaff_ESI + 0x6c) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4f1f:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1feb);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4f1f;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4f1f;
  }
  *(int *)(unaff_ESI + 0x70) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4f60:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xb5e1b07f);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4f60;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4f60;
  }
  *(int *)(unaff_ESI + 0x74) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4fa1:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x830a1fec);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4fa1;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4fa1;
  }
  *(int *)(unaff_ESI + 0x78) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d4fe2:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xdfe06fad);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d4fe2;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d4fe2;
  }
  *(int *)(unaff_ESI + 0x7c) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d5023:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xfbcca3da);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d5023;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d5023;
  }
  *(int *)(unaff_ESI + 0x80) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d5067:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x59bb154e);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d5067;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d5067;
  }
  *(int *)(unaff_ESI + 0x84) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004d50ab:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x218508bb);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004d50ab;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004d50ab;
  }
  *(int *)(unaff_ESI + 0x88) = iVar1;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004d5111;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xa57fe72a);
    *(undefined4 *)(unaff_ESI + 0x8c) = uVar2;
    return;
  }
  iVar1 = 0;
LAB_004d5111:
  *(int *)(unaff_ESI + 0x8c) = iVar1;
  return;
}


// ==== 0x4d5120 FUN_004d5120

void FUN_004d5120(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int unaff_ESI;
  undefined4 uVar6;
  int local_8;
  
  piVar5 = (int *)(unaff_ESI + 0x40);
  local_8 = 0x14;
  do {
    if (((*piVar5 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 != '\0')) {
      uVar6 = *(undefined4 *)(*piVar5 + 0x10);
      if (((*(int *)(unaff_ESI + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
         (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar3 = FUN_004ef050(uVar6);
          goto LAB_004d51c2;
        }
      }
      else {
LAB_004d51c2:
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,*piVar5,*(undefined4 *)(unaff_ESI + 0x90),iVar3,0);
        }
      }
      uVar1 = *(uint *)(*piVar5 + 0x10);
      if (uVar1 < 0x830a1feb) {
        if (uVar1 == 0x830a1fea) {
          puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
          for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 3));
              iVar3 = iVar3 + 1) {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          if (uVar1 < 0x830a1fe7) {
            if (uVar1 == 0x830a1fe6) {
              uVar6 = 0xc519bfbf;
              goto LAB_004d53dd;
            }
            if (uVar1 == 0x218508bb) {
              FUN_004d5790(unaff_ESI,0);
            }
            else if (uVar1 == 0x59bb154e) {
              FUN_004d5790(unaff_ESI,0);
            }
            else if (uVar1 == 0x830a1fe5) {
              uVar6 = 0x5073ef13;
              goto LAB_004d53dd;
            }
            goto switchD_004d5327_caseD_b5e1b079;
          }
          if (uVar1 == 0x830a1fe7) {
            puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
            for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 0));
                iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)*puVar4;
            }
          }
          else if (uVar1 == 0x830a1fe8) {
            puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
            for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 1));
                iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)*puVar4;
            }
          }
          else {
            if (uVar1 != 0x830a1fe9) goto switchD_004d5327_caseD_b5e1b079;
            puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
            for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 2));
                iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)*puVar4;
            }
          }
        }
        if (puVar4 == *(undefined4 **)(unaff_ESI + 0xb0)) {
          uVar6 = 0x9120409e;
          goto LAB_004d53dd;
        }
      }
      else {
        if (uVar1 < 0xdfe06fae) {
          if (uVar1 == 0xdfe06fad) {
            uVar6 = 0x911c0a4b;
          }
          else {
            switch(uVar1) {
            case 0xb5e1b078:
              uVar6 = 0xd9feec59;
              goto LAB_004d53dd;
            default:
              goto switchD_004d5327_caseD_b5e1b079;
            case 0xb5e1b07a:
              puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
              for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 0));
                  iVar3 = iVar3 + 1) {
                puVar4 = (undefined4 *)*puVar4;
              }
              break;
            case 0xb5e1b07b:
              puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
              for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 1));
                  iVar3 = iVar3 + 1) {
                puVar4 = (undefined4 *)*puVar4;
              }
              break;
            case 0xb5e1b07c:
              puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
              for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 2));
                  iVar3 = iVar3 + 1) {
                puVar4 = (undefined4 *)*puVar4;
              }
              break;
            case 0xb5e1b07d:
              puVar4 = *(undefined4 **)(unaff_ESI + 0x98);
              for (iVar3 = 0; (puVar4 != (undefined4 *)(unaff_ESI + 0x98) && (iVar3 != 3));
                  iVar3 = iVar3 + 1) {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            if (puVar4 != *(undefined4 **)(unaff_ESI + 0xb0)) goto switchD_004d5327_caseD_b5e1b079;
            uVar6 = 0xb5971bf1;
          }
        }
        else {
          if (uVar1 != 0xfbcca3da) goto switchD_004d5327_caseD_b5e1b079;
          uVar6 = 0x72619778;
        }
LAB_004d53dd:
        FUN_004c96c0(uVar6);
      }
    }
switchD_004d5327_caseD_b5e1b079:
    piVar5 = piVar5 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4d5420 FUN_004d5420

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


// ==== 0x4d5447 FUN_004d5447

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


// ==== 0x4d5549 FUN_004d5549

void FUN_004d5549(void)

{
  return;
}


// ==== 0x4d554e FUN_004d554e

undefined4 FUN_004d554e(int param_1)

{
  undefined4 uVar1;
  undefined4 in_stack_00000014;
  
  if (param_1 == 0x5073ef13) {
    return 1;
  }
  uVar1 = 2;
  if (param_1 != -0x260113a7) {
    uVar1 = in_stack_00000014;
  }
  return uVar1;
}


// ==== 0x4d5550 FUN_004d5550

undefined4 FUN_004d5550(int param_1)

{
  undefined4 uVar1;
  undefined4 in_stack_00000014;
  
  if (param_1 == 0x5073ef13) {
    return 1;
  }
  uVar1 = 2;
  if (param_1 != -0x260113a7) {
    uVar1 = in_stack_00000014;
  }
  return uVar1;
}


// ==== 0x4d5580 FUN_004d5580

void FUN_004d5580(int param_1)

{
  char cVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char local_10 [16];
  
  iVar3 = *(int *)(param_1 + 0xa8);
  iVar7 = *(int *)(iVar3 + 0x10);
  piVar2 = &DAT_00758b58;
  uVar6 = 0;
  do {
    piVar4 = piVar2;
    if ((*piVar2 == iVar7) || (piVar4 = piVar2 + 2, piVar2[2] == iVar7)) break;
    uVar6 = uVar6 + 0x10;
    piVar2 = piVar2 + 4;
  } while (uVar6 < 0xd0);
  uVar6 = (uint)*(byte *)(piVar4 + 1);
  if (in_EAX == -0x6edfbf62) {
    uVar6 = uVar6 - 1;
    if ((int)uVar6 < 0) {
      uVar6 = 3;
    }
  }
  else if ((in_EAX == -0x4a68e40f) && (uVar6 = uVar6 + 1, 3 < uVar6)) {
    uVar6 = 0;
  }
  *(char *)(piVar4 + 1) = (char)uVar6;
  *(char *)(iVar3 + 0x14) = (char)uVar6;
  switch((char)piVar4[1]) {
  case '\0':
    break;
  case '\x01':
    break;
  case '\x02':
    break;
  case '\x03':
  }
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x10;
  pcVar5 = local_10;
  do {
    cVar1 = pcVar5[iVar3 - (int)local_10];
    iVar7 = iVar7 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar7 != 0);
  bSPrintf_regdst(0x80,local_10);
  FUN_004f9240(param_1 + 0x98);
  EAXSound__InitEATraxMasks(DAT_007356a8,0,1);
  return;
}


// ==== 0x4d56a0 FUN_004d56a0

void FUN_004d56a0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_EAX;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  if (*(char *)(param_1 + 0x94) == '\0') {
    if (in_EAX == 0x72619778) {
      FUN_004f9060();
    }
    else if (in_EAX == -0x6ee3f5b5) {
      piVar6 = *(int **)(param_1 + 0x98);
      piVar2 = (int *)(param_1 + 0x98);
      if (((piVar6 != piVar2) &&
          (puVar1 = (undefined4 *)(param_1 + 0xa0), *(undefined4 **)(param_1 + 0xa0) != puVar1)) &&
         (puVar3 = (undefined4 *)**(int **)(param_1 + 0xa8), puVar3 != puVar1)) {
        iVar8 = 0;
        *(undefined4 **)(param_1 + 0xa8) = puVar3;
        for (puVar4 = *(undefined4 **)(param_1 + 0xac);
            (puVar4 != puVar1 && (iVar8 = iVar8 + 1, puVar4 != puVar3));
            puVar4 = (undefined4 *)*puVar4) {
        }
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          if (piVar6 == (int *)0x0) break;
          piVar6 = (int *)*piVar6;
        } while (piVar6 != piVar2);
        if (iVar7 < iVar8) {
          *(undefined4 *)(param_1 + 0xac) = **(undefined4 **)(param_1 + 0xac);
        }
        if (*(int *)(param_1 + 0xb0) != *(int *)(param_1 + 0x9c)) {
          FUN_004f8ec0(*(int *)(param_1 + 0xb0));
          uVar5 = **(undefined4 **)(param_1 + 0xb0);
          *(undefined4 *)(param_1 + 0xb0) = uVar5;
          FUN_004f8dd0(uVar5);
        }
        FUN_004f9240(piVar2);
      }
    }
  }
  else {
    FUN_004d5790(param_1,1);
  }
  FUN_00414a60();
  FUN_00414a60();
  return;
}


// ==== 0x4d5790 FUN_004d5790

void FUN_004d5790(int param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_EAX;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined **ppuVar11;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if (in_EAX == 0x72619778) {
    FUN_004f9130(0);
  }
  else if (((in_EAX == -0x6ee3f5b5) &&
           (puVar1 = (undefined4 *)(param_1 + 0x98), *(undefined4 **)(param_1 + 0x98) != puVar1)) &&
          (piVar9 = (int *)(param_1 + 0xa0), *(int **)(param_1 + 0xa0) != piVar9)) {
    piVar3 = (int *)**(int **)(param_1 + 0xa8);
    if (piVar3 != piVar9) {
      piVar4 = (int *)(*(int **)(param_1 + 0xa8))[1];
      *piVar4 = (int)piVar3;
      piVar3[1] = (int)piVar4;
      iVar10 = *piVar3;
      piVar4 = *(int **)(param_1 + 0xa8);
      *piVar3 = (int)piVar4;
      *(int **)(iVar10 + 4) = piVar4;
      piVar4[1] = (int)piVar3;
      *piVar4 = iVar10;
      piVar3 = *(int **)(param_1 + 0xac);
      piVar4 = *(int **)(param_1 + 0xa8);
      if (piVar3 == piVar4) {
        *(int *)(param_1 + 0xac) = piVar4[1];
      }
      else {
        iVar10 = 0;
        for (piVar5 = piVar3; (piVar5 != piVar9 && (iVar10 = iVar10 + 1, piVar5 != piVar4));
            piVar5 = (int *)*piVar5) {
        }
        iVar8 = 0;
        for (puVar6 = (undefined4 *)*puVar1;
            (puVar6 != puVar1 && (iVar8 = iVar8 + 1, puVar6 != (undefined4 *)0x0));
            puVar6 = (undefined4 *)*puVar6) {
        }
        if (iVar8 < iVar10) {
          *(int *)(param_1 + 0xac) = *piVar3;
        }
      }
      if (*(int *)(param_1 + 0xb0) != *(int *)(param_1 + 0x9c)) {
        FUN_004f8ec0(*(int *)(param_1 + 0xb0));
        uVar7 = **(undefined4 **)(param_1 + 0xb0);
        *(undefined4 *)(param_1 + 0xb0) = uVar7;
        FUN_004f8dd0(uVar7);
      }
    }
  }
  piVar9 = *(int **)(param_1 + 0xa0);
  if (piVar9 != (int *)(param_1 + 0xa0)) {
    iVar10 = 1;
    do {
      if (piVar9[2] != 0) {
        if (iVar10 + -1 < 9) {
          ppuVar11 = &PTR_FUN_006c7804;
        }
        else {
          ppuVar11 = (undefined **)&DAT_006ca778;
        }
        bSPrintf_regdst(0x20,ppuVar11,iVar10);
        iVar10 = iVar10 + 1;
      }
      piVar9 = (int *)*piVar9;
    } while (piVar9 != (int *)(param_1 + 0xa0));
  }
  FUN_004f9240(param_1 + 0x98);
  if ((iVar2 != *(int *)(param_1 + 0xb0)) && (param_2 != '\0')) {
    FUN_004d5e70(param_1,*(int *)(param_1 + 0xb0),"Grabbed");
  }
  FUN_004d5df0();
  return;
}


// ==== 0x4d5910 FUN_004d5910

void __fastcall FUN_004d5910(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x5073ef13) {
    DAT_0075892c = DAT_0075892c + -1;
    if (DAT_0075892c < 0) {
      DAT_0075892c = 1;
    }
  }
  else if ((param_1 == -0x260113a7) && (DAT_0075892c = DAT_0075892c + 1, 1 < DAT_0075892c)) {
    DAT_0075892c = 0;
  }
  uVar1 = 0;
  if (DAT_0075892c == 0) {
    uVar1 = 0x197392b;
  }
  else if (DAT_0075892c == 1) {
    uVar1 = 0x1a4e8ad1;
  }
  FUN_00416bb0(uVar1);
  return;
}


// ==== 0x4d5970 FUN_004d5970

void FUN_004d5970(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  byte bVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  byte *pbVar14;
  char *pcVar15;
  int iVar16;
  undefined **ppuVar17;
  int local_4c;
  char local_3c [16];
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar8 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006871b8;
  local_c = ExceptionList;
  puVar3 = (undefined4 *)(param_1 + 0x98);
  param_1 = 1;
  local_4c = 4;
  ExceptionList = &local_c;
  do {
    piVar10 = _malloc(0x14);
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar1 = piVar10 + 2;
      *piVar1 = (int)piVar1;
      piVar10[3] = (int)piVar1;
      piVar10[4] = 0;
    }
    puVar6 = *(undefined4 **)(iVar8 + 0x9c);
    *puVar6 = piVar10;
    *(int **)(iVar8 + 0x9c) = piVar10;
    piVar10[1] = (int)puVar6;
    *piVar10 = (int)puVar3;
    if (*(int *)(iVar8 + 0xb0) == 0) {
      *(undefined4 *)(iVar8 + 0xb0) = *puVar3;
    }
    iVar13 = *(int *)(iVar8 + 0x9c);
    FUN_004d5cf0(iVar8,iVar13);
    FUN_004d5cf0(iVar8,iVar13);
    FUN_004d5cf0(iVar8,iVar13);
    FUN_004d5cf0(iVar8,iVar13);
    FUN_004d5cf0(iVar8,iVar13);
    bSPrintf_regdst(0x20,"trax_backing_0%d",param_1);
    iVar16 = -1;
    pbVar14 = &local_2c;
    bVar9 = local_2c;
    while (bVar9 != 0) {
      if (('`' < (char)bVar9) && ((char)bVar9 < '{')) {
        bVar9 = bVar9 - 0x20;
      }
      iVar16 = iVar16 * 0x21 + (uint)bVar9;
      pbVar2 = pbVar14 + 1;
      pbVar14 = pbVar14 + 1;
      bVar9 = *pbVar2;
    }
    if (*(int *)(iVar8 + 0xc) == 0) {
LAB_004d5b2a:
      if (DAT_0073578c == 0) goto LAB_004d5b42;
      uVar12 = FUN_004ef050(iVar16);
    }
    else {
      iVar11 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar11 != 0) && (iVar11 = *(int *)(iVar11 + 0x18), iVar11 != 0)) {
LAB_004d5ae4:
        if (iVar11 != 0) {
          local_4 = 0;
          FUN_004ffb00(iVar11);
          local_4 = 0xffffffff;
        }
        goto LAB_004d5b2a;
      }
      if (DAT_0073578c != 0) {
        if ((*(int *)(DAT_0073578c + 8) == 0) ||
           ((iVar11 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xdc), iVar11 == 0 &&
            (iVar11 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xec), iVar11 == 0))))
        goto LAB_004d5b2a;
        goto LAB_004d5ae4;
      }
LAB_004d5b42:
      uVar12 = 0;
    }
    *(undefined4 *)(iVar13 + 0x10) = uVar12;
    param_1 = param_1 + 1;
    local_4c = local_4c + -1;
    if (local_4c == 0) {
      iVar13 = 0;
      do {
        piVar10 = _malloc(0x18);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          piVar1 = piVar10 + 2;
          *piVar1 = (int)piVar1;
          piVar10[3] = (int)piVar1;
          piVar10[4] = 0;
          *(undefined1 *)(piVar10 + 5) = 0;
        }
        puVar7 = *(undefined4 **)(iVar8 + 0xa4);
        puVar6 = (undefined4 *)(iVar8 + 0xa0);
        *puVar7 = piVar10;
        *(int **)(iVar8 + 0xa4) = piVar10;
        piVar10[1] = (int)puVar7;
        *piVar10 = (int)puVar6;
        if (*(int *)(iVar8 + 0xac) == 0) {
          *(undefined4 *)(iVar8 + 0xac) = *puVar6;
        }
        if (*(int *)(iVar8 + 0xa8) == 0) {
          *(undefined4 *)(iVar8 + 0xa8) = *puVar6;
        }
        iVar16 = iVar13 + 1;
        if (iVar13 < 9) {
          ppuVar17 = &PTR_FUN_006c7804;
        }
        else {
          ppuVar17 = (undefined **)&DAT_006ca778;
        }
        bSPrintf_regdst(0x20,ppuVar17,iVar16);
        StringList__AddEntry(piVar10,&local_2c);
        StringList__AddEntry(piVar10,(&PTR_s_Overseer_006f4d0c)[(&DAT_00758b58)[iVar13 * 2] * 4]);
        StringList__AddEntry(piVar10,(&PTR_s__Doomsday__006f4d08)[(&DAT_00758b58)[iVar13 * 2] * 4]);
        StringList__AddEntry(piVar10,(&PTR_s_Wreckage_006f4d10)[(&DAT_00758b58)[iVar13 * 2] * 4]);
        piVar10[4] = (&DAT_00758b58)[iVar13 * 2];
        uVar4 = (&DAT_00758b5c)[iVar13 * 8];
        *(undefined1 *)(piVar10 + 5) = uVar4;
        switch(uVar4) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
        }
        iVar13 = LanguageStrings__FindByHash();
        if (iVar13 == 0) {
          iVar13 = LanguageStrings__FindByHash();
        }
        iVar11 = 0x10;
        pcVar15 = local_3c;
        do {
          cVar5 = pcVar15[iVar13 - (int)local_3c];
          iVar11 = iVar11 + -1;
          *pcVar15 = cVar5;
          if (cVar5 == '\0') break;
          pcVar15 = pcVar15 + 1;
        } while (iVar11 != 0);
        StringList__AddEntry(piVar10,local_3c);
        iVar13 = iVar16;
        if (0x19 < iVar16) {
          FUN_004f9240(puVar3);
          ExceptionList = local_c;
          return;
        }
      } while( true );
    }
  } while( true );
}


// ==== 0x4d5cf0 FUN_004d5cf0

void __thiscall FUN_004d5cf0(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  bSPrintf_regdst(0x20,&DAT_006c3eb4,param_1);
  iVar2 = *(int *)(param_2 + 0xc);
  uVar1 = FEng__HashName();
  if (iVar2 != 0) {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_004d5d61;
    }
  }
  if (DAT_0073578c != 0) {
    uVar1 = FUN_004ef050(uVar1);
    FUN_00417530(param_3,uVar1);
    return;
  }
  iVar2 = 0;
LAB_004d5d61:
  FUN_00417530(param_3,iVar2);
  return;
}


// ==== 0x4d5d80 FUN_004d5d80

void FUN_004d5d80(void)

{
  int unaff_ESI;
  
  FUN_004d5e70(unaff_ESI,*(undefined4 *)(unaff_ESI + 0xb0),&DAT_006c3eac);
  *(undefined1 *)(unaff_ESI + 0x94) = 1;
  return;
}


// ==== 0x4d5da0 FUN_004d5da0

void FUN_004d5da0(void)

{
  int *piVar1;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x14) != '\0') {
    if (((DAT_006f1dd8 != 0) && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
       (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xa0))();
    }
    FUN_0051c720();
    return;
  }
  return;
}


// ==== 0x4d5df0 FUN_004d5df0

void __fastcall FUN_004d5df0(int param_1)

{
  undefined4 *puVar1;
  char in_AL;
  int iVar2;
  int iVar3;
  
  if (in_AL != '\0') {
    FUN_004d5e70(param_1,*(undefined4 *)(param_1 + 0xb0),"Release");
  }
  *(undefined1 *)(param_1 + 0x94) = 0;
  iVar3 = 0;
  do {
    puVar1 = *(undefined4 **)(param_1 + 0xa0);
    for (iVar2 = 0; (puVar1 != (undefined4 *)(param_1 + 0xa0) && (iVar2 != iVar3));
        iVar2 = iVar2 + 1) {
      puVar1 = (undefined4 *)*puVar1;
    }
    (&DAT_00758b58)[iVar3 * 2] = puVar1[4];
    (&DAT_00758b5c)[iVar3 * 8] = *(undefined1 *)(puVar1 + 5);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1a);
  EAXSound__InitEATraxMasks(DAT_007356a8,0,1);
  return;
}


// ==== 0x4d5e70 FUN_004d5e70

void FUN_004d5e70(undefined4 param_1,int param_2,byte *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(param_2 + 8);
  if (piVar5 != (int *)(param_2 + 8)) {
    do {
      iVar1 = piVar5[2];
      if (iVar1 != 0) {
        iVar3 = -1;
        if ((param_3 != (byte *)0x0) && (bVar2 = *param_3, bVar2 != 0)) {
          iVar3 = -1;
          pbVar4 = param_3;
          do {
            if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
              bVar2 = bVar2 - 0x20;
            }
            iVar3 = iVar3 * 0x21 + (uint)bVar2;
            bVar2 = pbVar4[1];
            pbVar4 = pbVar4 + 1;
          } while (bVar2 != 0);
        }
        for (iVar6 = *(int *)(iVar1 + 0x4c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
          if (*(int *)(iVar6 + 0x30) == iVar3) {
            if (iVar6 != 0) {
              if (iVar6 != *(int *)(iVar1 + 0x54)) {
                *(int *)(iVar1 + 0x54) = iVar6;
                FUN_004ff030(iVar1);
                *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
              }
              *(undefined4 *)(iVar6 + 0x10) = 0;
            }
            break;
          }
        }
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)(param_2 + 8));
  }
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 != 0) {
    iVar3 = -1;
    if (param_3 != (byte *)0x0) {
      bVar2 = *param_3;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar3 = iVar3 * 0x21 + (uint)bVar2;
        pbVar4 = param_3 + 1;
        param_3 = param_3 + 1;
        bVar2 = *pbVar4;
      }
    }
    iVar6 = *(int *)(iVar1 + 0x4c);
    if (iVar6 != 0) {
      while (*(int *)(iVar6 + 0x30) != iVar3) {
        iVar6 = *(int *)(iVar6 + 4);
        if (iVar6 == 0) {
          return;
        }
      }
      if (iVar6 != 0) {
        if (iVar6 != *(int *)(iVar1 + 0x54)) {
          *(int *)(iVar1 + 0x54) = iVar6;
          FUN_004ff030(iVar1);
          *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
        }
        *(undefined4 *)(iVar6 + 0x10) = 0;
      }
    }
  }
  return;
}


// ==== 0x4d5f80 FUN_004d5f80

void __fastcall FUN_004d5f80(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3e5c;
  FUN_004f7b50();
  return;
}


// ==== 0x4d5f90 FUN_004d5f90

void * __thiscall FUN_004d5f90(void *param_1,byte param_2)

{
  FUN_004d5f80();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d5fb0 Screen_TrailerMovie::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_TrailerMovie__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687c33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_TrailerMovie__Screen_TrailerMovie(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d6010 Screen_TrailerMovie::Screen_TrailerMovie

/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 * Screen_TrailerMovie__Screen_TrailerMovie(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
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
  *param_1 = &PTR_FUN_006c3e5c;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  if (DAT_00735e24 == 0) {
    if (DAT_00734998 != 0) {
      ppuVar3 = (undefined **)"intSSX";
      goto LAB_004d6120;
    }
  }
  else {
    if (DAT_00735e24 == 1) {
      if (DAT_00734998 == 0) {
        ppuVar3 = (undefined **)&DAT_006c3e80;
      }
      else {
        ppuVar3 = (undefined **)"intNFL";
      }
      goto LAB_004d6120;
    }
    if (DAT_00735e24 != 2) {
      ppuVar3 = &PTR_FUN_006c3e74;
      goto LAB_004d6120;
    }
  }
  ppuVar3 = (undefined **)"NASCAR";
LAB_004d6120:
  bSPrintf_regdst(0x40,ppuVar3);
  FUN_004ce690(local_4c);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4d6160 FUN_004d6160

int __thiscall FUN_004d6160(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_2 == 0x406415e3) || (param_2 == -0x6ee54c9c)) || (param_2 == -0x3c69f147)) &&
     (param_2 = *(int *)(param_1 + 0xc), DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    param_2 = 0;
    if (iVar2 != 0) {
      param_2 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        param_2 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return param_2;
}


// ==== 0x4d61c0 FUN_004d61c0

byte FUN_004d61c0(int param_1)

{
  return (param_1 != -0x6ee54c9c) - 1U & 6;
}


// ==== 0x4d61e0 FUN_004d61e0

void __fastcall FUN_004d61e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3dc0;
  FUN_004f7b50();
  return;
}


// ==== 0x4d61f0 FUN_004d61f0

void * __thiscall FUN_004d61f0(void *param_1,byte param_2)

{
  FUN_004d61e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d6210 Screen_MU_OptionsHUD::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_OptionsHUD__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688c93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x68);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_OptionsHUD__Screen_MU_OptionsHUD(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d6270 Screen_MU_OptionsHUD::Screen_MU_OptionsHUD

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 * Screen_MU_OptionsHUD__Screen_MU_OptionsHUD(undefined4 *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *local_4c;
  int local_48;
  byte local_2c;
  byte local_2b [31];
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688c68;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4c = param_1 + 0x15;
  *param_1 = &PTR_FUN_006c3dc0;
  local_4 = 0;
  _DAT_00777cc0 = 4;
  param_2 = 1;
  local_48 = 5;
  do {
    bSPrintf_regdst(0x20,"arrow_l_button_option%d",param_2);
    iVar7 = -1;
    pbVar6 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar7 = iVar7 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004d63b3:
      if (DAT_0073578c == 0) goto LAB_004d63c9;
      uVar5 = FUN_004ef050(iVar7);
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004d637b:
        local_4._0_1_ = 1;
        FUN_004ffb00(iVar4);
        local_4 = (uint)local_4._1_3_ << 8;
        goto LAB_004d63b3;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_004d63b3;
        goto LAB_004d637b;
      }
LAB_004d63c9:
      uVar5 = 0;
    }
    local_4c[-5] = uVar5;
    bSPrintf_regdst(0x20,"arrow_r_button_option%d",param_2);
    iVar7 = -1;
    pbVar6 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar7 = iVar7 * 0x21 + (uint)bVar3;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004d64b3:
      if (DAT_0073578c == 0) goto LAB_004d64c9;
      uVar5 = FUN_004ef050(iVar7);
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004d647b:
        local_4._0_1_ = 2;
        FUN_004ffb00(iVar4);
        local_4 = (uint)local_4._1_3_ << 8;
        goto LAB_004d64b3;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar4 = FUN_004fd1e0(iVar2 + 0xdc), iVar4 == 0 &&
            (iVar4 = FUN_004fd1e0(iVar2 + 0xec), iVar4 == 0)))) goto LAB_004d64b3;
        goto LAB_004d647b;
      }
LAB_004d64c9:
      uVar5 = 0;
    }
    *local_4c = uVar5;
    local_4c = local_4c + 1;
    param_2 = param_2 + 1;
    local_48 = local_48 + -1;
    if (local_48 == 0) {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar7 != 0) && (*(int *)(iVar7 + 0x18) != 0)) && (*(int **)(iVar7 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar7 + 0x14) + 8))(0x1122aacc,0,0,*(int *)(iVar7 + 0x18));
      }
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      FUN_004d6960();
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      FUN_004f6850(iVar7);
      ExceptionList = pvStack_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x4d6690 FUN_004d6690

void FUN_004d6690(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x54);
  iVar3 = 5;
  do {
    if ((piVar4[-5] != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar1 != '\0') && ((*(byte *)(piVar4[-5] + 0x1c) & 1) == 0)) {
        uVar2 = FUN_004f65d0();
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,piVar4[-5],uVar2,piVar4[-5],0);
        }
      }
    }
    if ((*piVar4 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar1 != '\0') && ((*(byte *)(*piVar4 + 0x1c) & 1) == 0)) {
        uVar2 = FUN_004f65d0();
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,*piVar4,uVar2,*piVar4,0);
        }
      }
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x4d67b0 FUN_004d67b0

void __thiscall FUN_004d67b0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 < 0xb5971bf2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 == 0x911ab364) {
        FUN_004c96c0(0x1122aabb);
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x9120409e) {
        return;
      }
    }
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0x9f6a8ddd) {
      if (uVar1 == 0x9f6a8ddc) {
        FUN_004d6a30(param_2);
        return;
      }
      if (uVar1 == 0x1b150b3c) {
        FUN_004d6b40(param_2);
        return;
      }
      if (uVar1 == 0x503362a9) {
        FUN_004d6ab0(param_2);
        return;
      }
    }
    else {
      if (uVar1 == 0xe21f6cf5) {
        FUN_004d6a70(param_2);
        return;
      }
      if (uVar1 == 0xf59a33db) {
        FUN_004d6af0();
        return;
      }
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004d6690(param_1);
  }
  return;
}


// ==== 0x4d6870 FUN_004d6870

void FUN_004d6870(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  return;
}


// ==== 0x4d68c0 FUN_004d68c0

void FUN_004d68c0(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  return;
}


// ==== 0x4d6910 FUN_004d6910

void FUN_004d6910(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  return;
}


// ==== 0x4d6960 FUN_004d6960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d6960(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _DAT_007588e4;
  if (DAT_0072cd08 == 1) {
    uVar1 = _DAT_007588e8;
  }
  switch(uVar1) {
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
    goto switchD_004d6979_default;
  }
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar2);
switchD_004d6979_default:
  return;
}


// ==== 0x4d69e0 FUN_004d69e0

void FUN_004d69e0(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  return;
}


// ==== 0x4d6a30 FUN_004d6a30

void FUN_004d6a30(void)

{
  if (DAT_0072cd08 == 0) {
    DAT_007588d6 = DAT_007588d6 == '\0';
    FUN_004d6870();
    return;
  }
  if (DAT_0072cd08 == 1) {
    DAT_007588d7 = DAT_007588d7 == '\0';
  }
  FUN_004d6870();
  return;
}


// ==== 0x4d6a70 FUN_004d6a70

void FUN_004d6a70(void)

{
  if (DAT_0072cd08 == 0) {
    DAT_007588d8 = DAT_007588d8 == '\0';
    FUN_004d68c0();
    return;
  }
  if (DAT_0072cd08 == 1) {
    DAT_007588d9 = DAT_007588d9 == '\0';
  }
  FUN_004d68c0();
  return;
}


// ==== 0x4d6ab0 FUN_004d6ab0

void FUN_004d6ab0(void)

{
  if (DAT_0072cd08 == 0) {
    DAT_007588da = DAT_007588da == '\0';
    FUN_004d6910();
    return;
  }
  if (DAT_0072cd08 == 1) {
    DAT_007588db = DAT_007588db == '\0';
  }
  FUN_004d6910();
  return;
}


// ==== 0x4d6af0 FUN_004d6af0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d6af0(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_007588e4;
  if (DAT_0072cd08 == 1) {
    iVar1 = _DAT_007588e8;
  }
  if (param_1 == -0x6edfbf62) {
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      iVar1 = 0;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar1 = iVar1 + -1, iVar1 < 0)) {
    iVar1 = 4;
  }
  if (DAT_0072cd08 == 0) {
    _DAT_007588e4 = iVar1;
    FUN_004d6960();
    return;
  }
  _DAT_007588e8 = iVar1;
  FUN_004d6960();
  return;
}


// ==== 0x4d6b40 FUN_004d6b40

void FUN_004d6b40(void)

{
  if (DAT_0072cd08 == 0) {
    DAT_007588dc = DAT_007588dc == '\0';
    FUN_004d69e0();
    return;
  }
  if (DAT_0072cd08 == 1) {
    DAT_007588dd = DAT_007588dd == '\0';
  }
  FUN_004d69e0();
  return;
}


// ==== 0x4d6b80 FUN_004d6b80

undefined4 FUN_004d6b80(void)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int unaff_EDI;
  char local_100 [256];
  
  pcVar6 = local_100;
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x100;
  do {
    cVar2 = pcVar6[iVar3 - (int)local_100];
    iVar7 = iVar7 + -1;
    *pcVar6 = cVar2;
    if (cVar2 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar7 != 0);
  if (local_100[0] == '$') {
    iVar3 = 0;
    do {
      iVar7 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while ("$HEADERBIG$"[iVar7] != '\0');
    iVar7 = FUN_00567d50();
    iVar3 = 0;
    if (iVar7 == 0) {
      do {
        iVar7 = iVar3;
        iVar3 = iVar7 + 1;
      } while ("$HEADERBIG$"[iVar7 + 1] != '\0');
      pcVar6 = "CONDUITMDITC_TT21I";
      iVar3 = -1;
      uVar4 = 0x43;
      do {
        iVar3 = iVar3 * 0x21 + uVar4;
        pbVar1 = (byte *)(pcVar6 + 1);
        uVar4 = (uint)*pbVar1;
        pcVar6 = pcVar6 + 1;
      } while (*pbVar1 != 0);
      iVar5 = *(int *)(unaff_EDI + 8);
      if ((iVar5 != 0) && (*(int *)(iVar5 + 0x24) != iVar3)) {
        *(int *)(iVar5 + 0x24) = iVar3;
        *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
      }
      FUN_004f75b0(0xa0cfe9f2);
      FEObject__SetFormattedText(&DAT_006cc568,local_100 + iVar7 + 1);
      iVar3 = *(int *)(unaff_EDI + 8);
      if (iVar3 != 0) {
        iVar7 = *(int *)(iVar3 + 0x18);
        iVar5 = *(int *)(iVar3 + 0x2c);
        if (((iVar7 == 1) || (iVar7 == 7)) || (iVar7 == 9)) {
          *(undefined4 *)(iVar5 + 0x38) = 0x3f933333;
          *(undefined4 *)(iVar5 + 0x3c) = 0x3f933333;
        }
        *(undefined4 *)(iVar5 + 0x38) = 0x3f933333;
        *(undefined4 *)(iVar5 + 0x3c) = 0x3f933333;
        *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
      }
      return 1;
    }
    iVar3 = 0;
    do {
      iVar7 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while ("$HEADERSMALL$"[iVar7] != '\0');
    iVar7 = FUN_00567d50();
    iVar3 = 0;
    if (iVar7 == 0) {
      do {
        iVar7 = iVar3;
        iVar3 = iVar7 + 1;
      } while ("$HEADERSMALL$"[iVar7 + 1] != '\0');
      iVar5 = FUN_00567c70();
      iVar3 = *(int *)(unaff_EDI + 8);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x24) != iVar5)) {
        *(int *)(iVar3 + 0x24) = iVar5;
        *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
      }
      FUN_004f75b0(0xa0cfe9f2);
      FEObject__SetFormattedText(&DAT_006cc568,local_100 + iVar7 + 1);
      FUN_004f73f0(0x3f733333,0x3f733333);
      return 1;
    }
  }
  pcVar6 = "CONDUITMDITC_TT21I";
  iVar3 = -1;
  uVar4 = 0x43;
  do {
    iVar3 = iVar3 * 0x21 + uVar4;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar4 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  iVar7 = *(int *)(unaff_EDI + 8);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != iVar3)) {
    *(int *)(iVar7 + 0x24) = iVar3;
    *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
  }
  FUN_004f75b0(0xc8549ab4);
  iVar3 = *(int *)(unaff_EDI + 8);
  if (iVar3 != 0) {
    iVar7 = *(int *)(iVar3 + 0x18);
    iVar5 = *(int *)(iVar3 + 0x2c);
    if (((iVar7 == 1) || (iVar7 == 7)) || (iVar7 == 9)) {
      *(undefined4 *)(iVar5 + 0x38) = 0x3f3ae148;
      *(undefined4 *)(iVar5 + 0x3c) = 0x3f3ae148;
    }
    *(undefined4 *)(iVar5 + 0x38) = 0x3f3ae148;
    *(undefined4 *)(iVar5 + 0x3c) = 0x3f3ae148;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return 0;
}


// ==== 0x4d6da0 FUN_004d6da0

float10 FUN_004d6da0(float param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_EAX;
  undefined4 unaff_EBX;
  bool bVar4;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  cVar3 = FUN_004d6b80();
  if ((cVar3 == '\0') && (iVar1 = *(int *)(in_EAX + 8), iVar1 != 0)) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = unaff_EBX;
    if (bVar4) {
      (**(code **)*puVar2)(iVar1);
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FUN_004f6d10(&local_8,local_4);
  FUN_004f7000(local_8,param_1);
  FEObject__SetInvisible(*(undefined4 *)(in_EAX + 8));
  FEObject__SetVisible(*(undefined4 *)(in_EAX + 8));
  FUN_004f7350(local_4,&param_1);
  return (float10)param_1;
}


// ==== 0x4d6e40 FUN_004d6e40

undefined4 * FUN_004d6e40(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068612b;
  local_c = ExceptionList;
  puVar1 = param_1 + 3;
  ExceptionList = &local_c;
  *puVar1 = puVar1;
  param_1[4] = puVar1;
  local_4 = 0;
  param_1[5] = param_2;
  param_1[1] = 0;
  pvVar2 = _malloc(40000);
  *param_1 = pvVar2;
  param_1[7] = 0;
  FUN_004d6f40();
  param_1[6] = 0;
  DAT_0073570c = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4d6eb0 FUN_004d6eb0

void FUN_004d6eb0(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068612b;
  local_c = ExceptionList;
  local_4 = 0;
  DAT_0073570c = 0;
  ExceptionList = &local_c;
  _free((void *)*param_1);
  if (DAT_0073578c != 0) {
    FUN_004f6010(DAT_0073578c);
  }
  FUN_00567000(DAT_00735708);
  _Memory = (int *)param_1[3];
  while (_Memory != param_1 + 3) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[3];
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4d6f40 FUN_004d6f40

void FUN_004d6f40(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *unaff_EDI;
  float10 fVar6;
  undefined8 uVar7;
  float local_4;
  
  iVar2 = FUN_004f65d0();
  iVar5 = *(int *)(iVar2 + 0x44);
  iVar2 = *(int *)(iVar2 + 0x40);
  iVar3 = FEng__HashName();
  while( true ) {
    if (*(int *)(iVar2 + 0x10) == iVar3) {
      piVar4 = _malloc(0xc);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4[2] = iVar2;
      }
      puVar1 = (undefined4 *)unaff_EDI[4];
      *puVar1 = piVar4;
      unaff_EDI[4] = (int)piVar4;
      piVar4[1] = (int)puVar1;
      *piVar4 = (int)(unaff_EDI + 3);
    }
    if (iVar2 == iVar5) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  iVar5 = 0;
  do {
    if ((iVar5 < 0x2fe) || (0x30d < iVar5)) {
      FUN_004f42f0("CREDITS_LINE_%05d",iVar5);
      uVar7 = LanguageStrings__FindByHash();
      if ((int)uVar7 != 0) {
        *(int *)(*unaff_EDI + unaff_EDI[1] * 4) = (int)((ulonglong)uVar7 >> 0x20);
        unaff_EDI[1] = unaff_EDI[1] + 1;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1000);
  piVar4 = (int *)unaff_EDI[3];
  local_4 = 240.0;
  for (; piVar4 != unaff_EDI + 3; piVar4 = (int *)*piVar4) {
    unaff_EDI[7] = unaff_EDI[7] + 1;
    fVar6 = (float10)FUN_004d6da0(local_4);
    local_4 = (float)(fVar6 + (float10)local_4);
  }
  return;
}


// ==== 0x4d7010 FUN_004d7010

float10 FUN_004d7010(void)

{
  undefined4 *puVar1;
  int in_EAX;
  float local_10;
  float local_c;
  float local_8;
  undefined1 local_4 [4];
  
  puVar1 = *(undefined4 **)(in_EAX + 0xc);
  local_10 = -250.0;
  for (; puVar1 != (undefined4 *)(in_EAX + 0xc); puVar1 = (undefined4 *)*puVar1) {
    FUN_004f6e10(puVar1[2],local_4,&local_c);
    if (local_10 < local_c) {
      FUN_004f6e10(puVar1[2],local_4,&local_8);
      local_10 = local_8;
    }
  }
  return (float10)local_10;
}


// ==== 0x4d7090 FUN_004d7090

void FUN_004d7090(float param_1)

{
  int *piVar1;
  int unaff_EDI;
  float10 fVar2;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  piVar1 = *(int **)(unaff_EDI + 0xc);
  if (piVar1 != (int *)(unaff_EDI + 0xc)) {
    do {
      FUN_004f6d10(&local_c,&local_14);
      if (-250.0 <= local_14) {
        FUN_004f6d10(&local_c,&local_10);
        local_c = local_10 - param_1 * 30.0;
        FUN_004f6d10(&local_8,local_4);
        FUN_004f7000(local_8,local_c);
      }
      else {
        *(int *)(unaff_EDI + 0x1c) = *(int *)(unaff_EDI + 0x1c) + 1;
        fVar2 = (float10)FUN_004d7010();
        FUN_004d6da0((float)fVar2);
        if (*(int *)(unaff_EDI + 4) <= *(int *)(unaff_EDI + 0x1c)) {
          *(undefined4 *)(unaff_EDI + 0x1c) = 0;
        }
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x4d7160 FUN_004d7160

void FUN_004d7160(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3d50;
  local_4 = 0;
  FUN_004d6eb0(param_1 + 0x10);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4d71c0 FUN_004d71c0

void * __thiscall FUN_004d71c0(void *param_1,byte param_2)

{
  FUN_004d7160(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d71e0 Screen_Credits::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_Credits__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006871a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x60);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_Credits__Screen_Credits(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d7240 Screen_Credits::Screen_Credits

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_Credits__Screen_Credits(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = &PTR_FUN_006c3d50;
  FUN_004d6e40(param_1 + 0x10,param_1[3]);
  _DAT_00777cc0 = 9;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4d72a0 FUN_004d72a0

void __thiscall FUN_004d72a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 0x72619778) || (param_2 == -0x6ee3f5b5)) {
    FUN_004d7090(0x3f800000);
  }
  else if (param_2 == -0x367ca946) {
    if (*(int *)(param_1 + 0x58) != 0) {
      return;
    }
    FUN_004d7090(DAT_0073ad38);
    return;
  }
  iVar1 = DAT_0073578c;
  if ((((param_2 == -0x6ee54c9c) && (DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d7330 FUN_004d7330

void __fastcall FUN_004d7330(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3d30;
  FUN_004f7b50();
  return;
}


// ==== 0x4d7340 FUN_004d7340

byte FUN_004d7340(void)

{
  int in_stack_00000014;
  
  return (in_stack_00000014 != 6) - 1U & 6;
}


// ==== 0x4d7360 FUN_004d7360

void * __thiscall FUN_004d7360(void *param_1,byte param_2)

{
  FUN_004d7330();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d7380 Screen_MU_ScreenPos::Create

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_ScreenPos__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687183;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c3d30;
    _DAT_00777cc0 = 4;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x4d73e0 FUN_004d73e0

void FUN_004d73e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_1 == -0x6ee54c9c) && (DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d7430 FUN_004d7430

void __fastcall FUN_004d7430(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3d14;
  FUN_004f7b50();
  return;
}


// ==== 0x4d7440 FUN_004d7440

undefined4 __fastcall FUN_004d7440(undefined4 param_1)

{
  FUN_004d7430();
  return param_1;
}


// ==== 0x4d7450 Screen_Chyron::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_Chyron__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  puVar1 = DAT_00735e18;
  pcStack_8 = FUN_00687c0b;
  local_c = ExceptionList;
  local_4 = 0;
  if (DAT_00735e18 != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    FEScreen__FEScreen(DAT_00735e18,param_1);
    *puVar1 = &PTR_FUN_006c3d14;
    puVar1[0x10] = 0;
    *(undefined1 *)(puVar1 + 0x11) = 0;
    *(undefined1 *)((int)puVar1 + 0x45) = 0;
    ExceptionList = local_c;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== 0x4d74c0 FUN_004d74c0

void __thiscall FUN_004d74c0(int param_1,int param_2)

{
  float fVar1;
  
  if (param_2 == 0x69696969) {
    *(undefined1 *)(param_1 + 0x45) = 1;
    *(int *)(param_1 + 0x40) = DAT_0073ad3c;
    DAT_00735e1c = 1;
    FUN_004f6bd0(&DAT_006c515c,1);
  }
  else if (param_2 == -0x367ca946) {
    fVar1 = (float)(DAT_0073ad3c - *(int *)(param_1 + 0x40)) * 0.00025;
    if ((5.2 < fVar1) && (*(char *)(param_1 + 0x45) != '\0')) {
      if (*(char *)(param_1 + 0x44) == '\0') {
        FUN_004d7610();
        *(undefined1 *)(param_1 + 0x44) = 1;
        return;
      }
      if (6.2 < fVar1) {
        *(undefined1 *)(param_1 + 0x45) = 0;
        FUN_004f63a0(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
  }
  return;
}


// ==== 0x4d7580 FUN_004d7580

void FUN_004d7580(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_004f6850();
  FUN_004f6850(param_2);
  FUN_004f6850(param_1);
  if (DAT_00735e1c == '\0') {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      return;
    }
    *(undefined1 *)(unaff_ESI + 0x45) = 1;
    *(undefined4 *)(unaff_ESI + 0x40) = DAT_0073ad3c;
  }
  else {
    *(undefined1 *)(unaff_ESI + 0x45) = 1;
    *(undefined4 *)(unaff_ESI + 0x40) = DAT_0073ad3c;
  }
  FUN_004f6bd0(&DAT_006c515c,1);
  return;
}


// ==== 0x4d7610 FUN_004d7610

void FUN_004d7610(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(in_EAX + 0xc);
  uVar1 = FEng__HashName();
  if (((iVar2 == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) || (iVar2 = FUN_004ffb70(), iVar2 == 0)
     ) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(uVar1);
  }
  if ((iVar2 != 0) && (iVar4 = *(int *)(iVar2 + 0x4c), iVar4 != 0)) {
    while (iVar3 = FEng__HashName(), *(int *)(iVar4 + 0x30) != iVar3) {
      iVar4 = *(int *)(iVar4 + 4);
      if (iVar4 == 0) {
        return;
      }
    }
    if (iVar4 != 0) {
      if (iVar4 != *(int *)(iVar2 + 0x54)) {
        *(int *)(iVar2 + 0x54) = iVar4;
        FUN_004ff030(iVar2);
        *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar4 + 0x10) = 0;
    }
  }
  return;
}


// ==== 0x4d76a0 FUN_004d76a0

void FUN_004d76a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if (DAT_00758928 == 1) {
    pcVar3 = "Chyron_alpine.fng";
  }
  else if (DAT_00758928 == 2) {
    pcVar3 = "Chyron_kenwood.fng";
  }
  else if (DAT_00758928 == 3) {
    pcVar3 = "Chyron_audiobahn.fng";
  }
  else {
    pcVar3 = "Chyron.fng";
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if (iVar2 != 0) {
      iVar2 = FUN_004fd1e0(iVar2);
      if (iVar2 != 0) goto LAB_004d7717;
    }
    cFEng__PushPackage(iVar1,pcVar3,0xff,0);
  }
LAB_004d7717:
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x14) != 0)) {
    FUN_004d7580(param_1,param_3,param_4);
  }
  return;
}


// ==== 0x4d7750 FUN_004d7750

void __fastcall FUN_004d7750(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3c10;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x4d7770 FUN_004d7770

void __fastcall FUN_004d7770(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3c10;
  return;
}


// ==== 0x4d7780 FUN_004d7780

void * __thiscall FUN_004d7780(void *param_1,byte param_2)

{
  FUN_004d7770();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4d77a0 GetPartColor

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall GetPartColor(undefined4 param_1,int param_2)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 == 0) {
    in_EAX[3] = 0;
    in_EAX[2] = 0;
    in_EAX[1] = 0;
    *in_EAX = 0;
    return;
  }
  piVar1 = *(int **)(param_2 + 0x14);
  iVar5 = (int)*(short *)(param_2 + 0x1c);
  piVar4 = piVar1;
  if (piVar1 != (int *)0x0) {
    for (; piVar4 < piVar1 + iVar5 * 2; piVar4 = piVar4 + 2) {
      if (*piVar4 == 0x368a1a6a) {
        piVar4 = piVar1;
        if (piVar1 != (int *)0x0) goto joined_r0x004d786e;
        break;
      }
    }
  }
LAB_004d77d5:
  piVar4 = piVar1;
  if (piVar1 != (int *)0x0) {
    for (; piVar4 < piVar1 + iVar5 * 2; piVar4 = piVar4 + 2) {
      if (*piVar4 == 0xd99a) {
        if (piVar4 != (int *)0x0) {
          iVar2 = piVar4[1];
          goto LAB_004d77f7;
        }
        break;
      }
    }
  }
  iVar2 = 0;
LAB_004d77f7:
  piVar4 = piVar1;
  if (piVar1 != (int *)0x0) {
    for (; piVar4 < piVar1 + iVar5 * 2; piVar4 = piVar4 + 2) {
      if (*piVar4 == 0x2ddc8f0) {
        if (piVar4 != (int *)0x0) {
          iVar3 = piVar4[1];
          goto LAB_004d7825;
        }
        break;
      }
    }
  }
  iVar3 = 0;
LAB_004d7825:
  piVar4 = piVar1 + iVar5 * 2;
  if (piVar1 != (int *)0x0) {
    for (; piVar1 < piVar4; piVar1 = piVar1 + 2) {
      if (*piVar1 == 0x136707) goto LAB_004d792d;
    }
  }
LAB_004d7845:
  iVar5 = 0;
LAB_004d7847:
  *in_EAX = iVar5;
  in_EAX[1] = iVar3;
  in_EAX[2] = iVar2;
  in_EAX[3] = 0xff;
  return;
joined_r0x004d786e:
  if (piVar1 + iVar5 * 2 <= piVar4) goto LAB_004d77d5;
  if (*piVar4 == 0xba7dc0) {
    piVar4 = piVar1;
    if (piVar1 != (int *)0x0) goto joined_r0x004d7897;
    goto LAB_004d77d5;
  }
  piVar4 = piVar4 + 2;
  goto joined_r0x004d786e;
joined_r0x004d7897:
  if (piVar1 + iVar5 * 2 <= piVar4) goto LAB_004d77d5;
  if (*piVar4 == 0x7c4c1d7) {
    if ((piVar1 == (int *)0x0) || (piVar4 = piVar1, piVar1 + iVar5 * 2 <= piVar1))
    goto LAB_004d78d0;
    goto LAB_004d78c1;
  }
  piVar4 = piVar4 + 2;
  goto joined_r0x004d7897;
  while (piVar4 = piVar4 + 2, piVar4 < piVar1 + iVar5 * 2) {
LAB_004d78c1:
    if (*piVar4 == 0x368a1a6a) {
      if (piVar4 != (int *)0x0) {
        iVar2 = piVar4[1];
        goto LAB_004d78d2;
      }
      break;
    }
  }
LAB_004d78d0:
  iVar2 = 0;
LAB_004d78d2:
  piVar4 = piVar1;
  if (piVar1 != (int *)0x0) {
    for (; piVar4 < piVar1 + iVar5 * 2; piVar4 = piVar4 + 2) {
      if (*piVar4 == 0xba7dc0) {
        if (piVar4 != (int *)0x0) {
          iVar3 = piVar4[1];
          goto LAB_004d78f2;
        }
        break;
      }
    }
  }
  iVar3 = 0;
LAB_004d78f2:
  piVar4 = piVar1 + iVar5 * 2;
  if (piVar1 != (int *)0x0) {
    for (; piVar1 < piVar4; piVar1 = piVar1 + 2) {
      if (*piVar1 == 0x7c4c1d7) goto LAB_004d792d;
    }
  }
  goto LAB_004d7845;
LAB_004d792d:
  if (piVar1 != (int *)0x0) {
    iVar5 = piVar1[1];
    goto LAB_004d7847;
  }
  goto LAB_004d7845;
}


// ==== 0x4d7980 ColorElement::SetPart

/* [canon] hud med (ghidra+hopper) docs/re/tuning.md */

void __fastcall ColorElement__SetPart(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  *(int *)(in_EAX + 0x10) = param_2;
  if (param_2 == 0) {
    *(undefined4 *)(in_EAX + 0x1c) = 0;
    *(undefined4 *)(in_EAX + 0x18) = 0;
    *(undefined4 *)(in_EAX + 0x14) = 0;
  }
  else {
    puVar3 = (undefined4 *)GetPartColor();
    *(undefined4 *)(in_EAX + 0x20) = puVar3[3];
    *(undefined4 *)(in_EAX + 0x1c) = puVar3[2];
    *(undefined4 *)(in_EAX + 0x18) = puVar3[1];
    *(undefined4 *)(in_EAX + 0x14) = *puVar3;
    uVar4 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x1c) = uVar4;
    uVar4 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x18) = uVar4;
    uVar4 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x14) = uVar4;
  }
  iVar1 = *(int *)(in_EAX + 0xc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) < 0x100)) {
    cVar2 = FEColor_NearlyEqual();
    if (cVar2 == '\0') {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    }
    FUN_004ff2f0(iVar1,0,0);
  }
  return;
}


// ==== 0x4d7a30 FUN_004d7a30

uint __fastcall FUN_004d7a30(int param_1)

{
  int in_EAX;
  int iVar1;
  
  if (-1 < in_EAX) {
    if (in_EAX < 6) {
      iVar1 = 1;
      goto LAB_004d7a4f;
    }
    if (in_EAX == 6) {
      iVar1 = 4;
      goto LAB_004d7a4f;
    }
  }
  iVar1 = -1;
LAB_004d7a4f:
  if ((-1 < param_1) && (param_1 < iVar1)) {
    switch(in_EAX) {
    case 0:
      return 0xdc339c44;
    case 1:
      return 0xf1bd5749;
    case 2:
      return 0x343216e4;
    case 3:
      return 0xdb8099eb;
    case 4:
      return 0x9374c3e5;
    case 5:
      return 0xa6343aec;
    case 6:
      if (param_1 == 0) {
        return 0x92af441f;
      }
      if (param_1 != 1) {
        if (param_1 != 2) {
          return (param_1 != 3) - 1 & 0x92af4422;
        }
        return 0x92af4421;
      }
      return 0x92af4420;
    }
  }
  return 0;
}


// ==== 0x4d7af0 FUN_004d7af0

undefined4 FUN_004d7af0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0xd63e2bb0;
  case 1:
    return 0xa687aa13;
  case 2:
    return 0xd604bd5e;
  case 3:
    return 0x92be98c0;
  case 4:
    return 0xd651f88a;
  case 5:
    return 0x2d4daee3;
  case 6:
    return 0x40a99fd9;
  case 7:
    return 0x3abf7e22;
  default:
    return 0;
  }
}


// ==== 0x4d7b70 FUN_004d7b70

int FUN_004d7b70(void)

{
  int *_Memory;
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *unaff_ESI;
  undefined4 unaff_EDI;
  
  puVar8 = (undefined4 *)*unaff_ESI;
  while (puVar8 != unaff_ESI) {
    _Memory = (int *)*unaff_ESI;
    iVar9 = *_Memory;
    piVar1 = (int *)_Memory[1];
    *piVar1 = iVar9;
    *(int **)(iVar9 + 4) = piVar1;
    _free(_Memory);
    puVar8 = (undefined4 *)*unaff_ESI;
  }
  switch(unaff_EDI) {
  case 0:
    cVar5 = FUN_005142e0();
    cVar6 = IsLevel3PaintsOwned();
    if (cVar5 == '\0') {
      cVar7 = IsLevel2PaintsOwned();
      if (cVar7 == '\0') goto LAB_004d7bf1;
LAB_004d7bbe:
      bVar4 = false;
    }
    else {
      cVar7 = FUN_004d8040();
      if (cVar7 != '\0') goto LAB_004d7bbe;
LAB_004d7bf1:
      bVar4 = true;
    }
    if (cVar5 == '\0') {
      if (cVar6 == '\0') goto LAB_004d7c01;
LAB_004d7bcf:
      bVar3 = false;
    }
    else {
      cVar5 = FUN_004d80e0();
      if (cVar5 != '\0') goto LAB_004d7bcf;
LAB_004d7c01:
      bVar3 = true;
    }
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8[2] = 0;
    }
    puVar2 = (undefined4 *)unaff_ESI[1];
    *puVar2 = puVar8;
    unaff_ESI[1] = puVar8;
    puVar8[1] = puVar2;
    *puVar8 = unaff_ESI;
    goto LAB_004d7c14;
  case 1:
    puVar8 = _malloc(0xc);
    if (puVar8 != (undefined4 *)0x0) {
      puVar8[2] = 5;
      break;
    }
    goto LAB_004d7d64;
  case 2:
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) goto LAB_004d7d64;
    puVar8[2] = 4;
    break;
  case 3:
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8[2] = 0;
    }
    puVar2 = (undefined4 *)unaff_ESI[1];
    *puVar2 = puVar8;
    unaff_ESI[1] = puVar8;
    puVar8[1] = puVar2;
    *puVar8 = unaff_ESI;
    cVar5 = FUN_005142e0();
    cVar6 = IsLevel3PaintsOwned();
    if (cVar5 == '\0') {
      cVar7 = IsLevel2PaintsOwned();
      if (cVar7 == '\0') goto LAB_004d7cde;
LAB_004d7cbd:
      bVar4 = false;
    }
    else {
      cVar7 = FUN_004d8040();
      if (cVar7 != '\0') goto LAB_004d7cbd;
LAB_004d7cde:
      bVar4 = true;
    }
    if (cVar5 == '\0') {
      if (cVar6 == '\0') goto LAB_004d7cee;
LAB_004d7cce:
      bVar3 = false;
    }
    else {
      cVar5 = FUN_004d80e0();
      if (cVar5 != '\0') goto LAB_004d7cce;
LAB_004d7cee:
      bVar3 = true;
    }
LAB_004d7c14:
    if (!bVar4) {
      puVar8 = _malloc(0xc);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        puVar8[2] = 1;
      }
      puVar2 = (undefined4 *)unaff_ESI[1];
      *puVar2 = puVar8;
      unaff_ESI[1] = puVar8;
      puVar8[1] = puVar2;
      *puVar8 = unaff_ESI;
    }
    if (bVar3) goto switchD_004d7b9a_default;
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) {
LAB_004d7d64:
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8[2] = 2;
    }
    break;
  case 4:
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) goto LAB_004d7d64;
    puVar8[2] = 3;
    break;
  case 5:
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) goto LAB_004d7d64;
    puVar8[2] = 6;
    break;
  case 6:
    puVar8 = _malloc(0xc);
    if (puVar8 == (undefined4 *)0x0) goto LAB_004d7d64;
    puVar8[2] = 7;
    break;
  default:
    goto switchD_004d7b9a_default;
  }
  puVar2 = (undefined4 *)unaff_ESI[1];
  *puVar2 = puVar8;
  unaff_ESI[1] = puVar8;
  puVar8[1] = puVar2;
  *puVar8 = unaff_ESI;
switchD_004d7b9a_default:
  iVar9 = 0;
  for (puVar8 = (undefined4 *)*unaff_ESI;
      (puVar8 != unaff_ESI && (iVar9 = iVar9 + 1, puVar8 != (undefined4 *)0x0));
      puVar8 = (undefined4 *)*puVar8) {
  }
  return iVar9;
}


// ==== 0x4d7db0 FUN_004d7db0

int FUN_004d7db0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *_Memory;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *unaff_EDI;
  
  puVar3 = (undefined4 *)*unaff_EDI;
  puVar2 = DAT_0073ad40;
  while (DAT_0073ad40 = puVar2, puVar3 != unaff_EDI) {
    _Memory = (int *)*unaff_EDI;
    iVar4 = *_Memory;
    piVar1 = (int *)_Memory[1];
    *piVar1 = iVar4;
    *(int **)(iVar4 + 4) = piVar1;
    _free(_Memory);
    puVar2 = DAT_0073ad40;
    puVar3 = (undefined4 *)*unaff_EDI;
  }
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    uVar6 = puVar2[3];
    uVar5 = puVar2[4] * 0x30 + uVar6;
    for (; uVar6 < uVar5; uVar6 = uVar6 + 0x30) {
      if (*(char *)(uVar6 + 0x10) == '\x1e') goto joined_r0x004d7e0f;
    }
  }
  uVar6 = 0;
joined_r0x004d7e0f:
  do {
    if (uVar6 == 0) {
      iVar4 = 0;
      for (puVar3 = (undefined4 *)*unaff_EDI;
          (puVar3 != unaff_EDI && (iVar4 = iVar4 + 1, puVar3 != (undefined4 *)0x0));
          puVar3 = (undefined4 *)*puVar3) {
      }
      return iVar4;
    }
    if (*(int *)(uVar6 + 0xc) == *(int *)(&DAT_00746974 + param_2 * 8)) {
      switch(param_3) {
      case 0:
      case 1:
        if (1 < *(byte *)(uVar6 + 0x11)) goto LAB_004d7e70;
        break;
      case 2:
        if (*(char *)(uVar6 + 0x11) != '\x02') goto LAB_004d7e70;
        break;
      case 3:
        if (*(char *)(uVar6 + 0x11) != '\x03') goto LAB_004d7e70;
      }
      puVar3 = _malloc(0xc);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[2] = 0;
      }
      puVar3[2] = uVar6;
      puVar2 = (undefined4 *)unaff_EDI[1];
      *puVar2 = puVar3;
      unaff_EDI[1] = puVar3;
      puVar3[1] = puVar2;
      *puVar3 = unaff_EDI;
    }
LAB_004d7e70:
    uVar6 = CarPartDatabase__GetCarPart(0,0x1e,0,uVar6,0xffffffff);
  } while( true );
}


// ==== 0x4d7eb0 IsPaintLocked

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsPaintLocked(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint local_1c [5];
  byte local_5;
  
  if ((((DAT_007677ac == 0) && (DAT_00735ec1 == '\0')) && (in_EAX != 0)) &&
     (local_5 = *(byte *)(in_EAX + 0x11), 1 < local_5)) {
    uVar3 = (uint)local_5;
    cVar1 = EasterEggs__IsPartUnlocked();
    if (cVar1 == '\0') {
      iVar2 = MapCarPartIDToCareerUpgrade();
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar2);
      local_1c[0] = (uint)(cVar1 != '\0');
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar2);
      local_1c[1] = (uint)(cVar1 != '\0');
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar2);
      local_1c[2] = (uint)(cVar1 != '\0');
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar2);
      local_1c[3] = (uint)(cVar1 != '\0');
      cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar2);
      local_1c[4] = (uint)(cVar1 != '\0');
      if ((local_1c[uVar3] == 0) &&
         ((iVar2 != 0 ||
          (((2 < local_5 || (cVar1 = FUN_004d8040(), cVar1 == '\0')) &&
           (cVar1 = FUN_004d80e0(), cVar1 == '\0')))))) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x4d7fe0 FUN_004d7fe0

undefined4 FUN_004d7fe0(void)

{
  char cVar1;
  int in_EAX;
  
  cVar1 = IsPaintLocked();
  if (cVar1 == '\0') {
    if (DAT_00745e40 == 1) {
      if (*(char *)(in_EAX + 0x10) == '\x1e') {
        if (*(byte *)(in_EAX + 0x11) < 2) {
          return 1;
        }
        if (((*(byte *)(in_EAX + 0x11) < 3) && (cVar1 = FUN_004d8040(), cVar1 != '\0')) &&
           (cVar1 = FUN_004d8370(), cVar1 != '\0')) {
          return 1;
        }
        cVar1 = FUN_004d80e0();
        if ((cVar1 != '\0') && (cVar1 = FUN_004d8370(), cVar1 != '\0')) {
          return 1;
        }
      }
    }
    else if (DAT_00745e40 == 2) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x4d8040 FUN_004d8040

undefined4 FUN_004d8040(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = 0;
  if (DAT_0073766c != 0) {
    piVar4 = (int *)(DAT_00737668 + 0x24);
    do {
      if ((piVar4[-1] == 1) && (*piVar4 == 2)) {
        iVar3 = uVar2 * 0x34;
        if (*(char *)(iVar3 + 0x30 + DAT_00737668) != '\0') goto LAB_004d80cf;
        break;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  iVar3 = DAT_007677ac;
  if ((DAT_007677ac == 0) && (iVar3 = 0, DAT_00735ec1 == '\0')) {
    if ((DAT_00735e12 == '\0') &&
       (((cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0), cVar1 == '\0' &&
         (cVar1 = EasterEggs__IsPartUnlocked(), cVar1 == '\0')) && (DAT_00735e10 == '\0')))) {
      return 0;
    }
    return 1;
  }
LAB_004d80cf:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


// ==== 0x4d80e0 FUN_004d80e0

undefined4 FUN_004d80e0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = 0;
  if (DAT_0073766c != 0) {
    piVar4 = (int *)(DAT_00737668 + 0x24);
    do {
      if ((piVar4[-1] == 1) && (*piVar4 == 3)) {
        iVar3 = uVar2 * 0x34;
        if (*(char *)(iVar3 + 0x30 + DAT_00737668) != '\0') goto LAB_004d816f;
        break;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  iVar3 = DAT_007677ac;
  if ((DAT_007677ac == 0) && (iVar3 = 0, DAT_00735ec1 == '\0')) {
    if ((DAT_00735e12 == '\0') &&
       (((cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0), cVar1 == '\0' &&
         (cVar1 = EasterEggs__IsPartUnlocked(), cVar1 == '\0')) && (DAT_00735e11 == '\0')))) {
      return 0;
    }
    return 1;
  }
LAB_004d816f:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


// ==== 0x4d8180 IsPaintOwned

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

bool IsPaintOwned(void)

{
  undefined1 uVar1;
  char cVar2;
  int in_EAX;
  uint uVar3;
  uint *puVar4;
  undefined1 uVar5;
  undefined1 auStack_4 [2];
  undefined2 local_2;
  
  uVar3 = 0;
  if (DAT_0073766c != 0) {
    puVar4 = (uint *)(DAT_00737668 + 0x24);
    do {
      if ((puVar4[-1] == 1) && (*puVar4 == (uint)*(byte *)(in_EAX + 0x11))) {
        if (*(char *)(uVar3 * 0x34 + 0x30 + DAT_00737668) != '\0') {
          return true;
        }
        break;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 0xd;
    } while (uVar3 < DAT_0073766c);
  }
  if (DAT_007677ac != 0) {
    return true;
  }
  if (DAT_00735e12 != '\0') {
    return true;
  }
  if (DAT_00735ec1 != '\0') {
    return true;
  }
  uVar1 = *(undefined1 *)(in_EAX + 0x11);
  uVar5 = 3;
  _auStack_4 = CONCAT13(uVar1,0x10000);
  cVar2 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0);
  if (((cVar2 == '\0') && (cVar2 = EasterEggs__IsPartUnlocked(), cVar2 == '\0')) &&
     (DAT_00735e11 == '\0')) {
    uVar5 = 2;
    cVar2 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0);
    if (((cVar2 == '\0') && (cVar2 = EasterEggs__IsPartUnlocked(), cVar2 == '\0')) &&
       (DAT_00735e10 == '\0')) goto LAB_004d8258;
  }
  local_2 = CONCAT11(uVar1,uVar5);
LAB_004d8258:
  return local_2._1_1_ <= (byte)local_2;
}


// ==== 0x4d8270 IsLevel2PaintsOwned

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsLevel2PaintsOwned(void)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar1 = 1;
  if ((DAT_00745e40 == 2) && (uVar2 = 0, DAT_0073766c != 0)) {
    piVar3 = (int *)(DAT_00737668 + 0x24);
    do {
      if ((piVar3[-1] == 1) && (*piVar3 == 2)) {
        if (*(char *)(uVar2 * 0x34 + 0x30 + DAT_00737668) != '\0') {
          return 1;
        }
        break;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  if ((((DAT_007677ac == 0) && (DAT_00735e12 == '\0')) && (DAT_00760268 == '\0')) &&
     (DAT_00735ec1 == '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x4d82f0 IsLevel3PaintsOwned

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 IsLevel3PaintsOwned(void)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar1 = 1;
  if ((DAT_00745e40 == 2) && (uVar2 = 0, DAT_0073766c != 0)) {
    piVar3 = (int *)(DAT_00737668 + 0x24);
    do {
      if ((piVar3[-1] == 1) && (*piVar3 == 3)) {
        if (*(char *)(uVar2 * 0x34 + 0x30 + DAT_00737668) != '\0') {
          return 1;
        }
        break;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  if ((((DAT_007677ac == 0) && (DAT_00735e12 == '\0')) && (DAT_00760269 == '\0')) &&
     (DAT_00735ec1 == '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x4d8370 FUN_004d8370

undefined4 FUN_004d8370(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int unaff_EDI;
  
  if ((DAT_00745e40 == 2) && (uVar2 = 0, DAT_0073766c != 0)) {
    puVar4 = (uint *)(DAT_00737668 + 0x24);
    do {
      if ((puVar4[-1] == 1) && (*puVar4 == (uint)*(byte *)(unaff_EDI + 0x11))) {
        iVar3 = uVar2 * 0x34;
        if (*(char *)(iVar3 + 0x30 + DAT_00737668) != '\0') goto LAB_004d840c;
        break;
      }
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 0xd;
    } while (uVar2 < DAT_0073766c);
  }
  iVar3 = DAT_007677ac;
  if ((DAT_007677ac == 0) && (iVar3 = 0, DAT_00735ec1 == '\0')) {
    cVar1 = *(char *)(unaff_EDI + 0x11);
    iVar3 = 0;
    if ((cVar1 != '\0') && (cVar1 != '\x01')) {
      if (cVar1 == '\x02') {
        if (DAT_00735e12 != '\0') {
          return 1;
        }
        cVar1 = IsLevel2PaintsOwned();
      }
      else {
        if (cVar1 != '\x03') {
          return 0;
        }
        if (DAT_00735e12 != '\0') {
          return 1;
        }
        cVar1 = IsLevel3PaintsOwned();
      }
      if (cVar1 != '\0') {
        return 1;
      }
      return 0;
    }
  }
LAB_004d840c:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


// ==== 0x4d8420 FUN_004d8420

void FUN_004d8420(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x11) == '\x02') {
    DAT_00760268 = 1;
    return;
  }
  if (*(char *)(in_EAX + 0x11) == '\x03') {
    DAT_00760269 = 1;
  }
  return;
}


// ==== 0x4d8440 ColorPicker::GetHighestUpgradeLevel

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 ColorPicker__GetHighestUpgradeLevel(void)

{
  char cVar1;
  char local_1;
  
  if (DAT_00745e40 == 1) {
    local_1 = '\x01';
  }
  else {
    local_1 = IsLevel2PaintsOwned();
    cVar1 = IsLevel3PaintsOwned();
    if (cVar1 == '\0') goto LAB_004d84b0;
  }
  cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0);
  if (cVar1 != '\0') {
    return 3;
  }
  cVar1 = EasterEggs__IsPartUnlocked();
  if (cVar1 != '\0') {
    return 3;
  }
  if (DAT_00735e12 != '\0') {
    return 3;
  }
  if (DAT_00735e11 != '\0') {
    return 3;
  }
LAB_004d84b0:
  if (local_1 == '\0') {
    return 1;
  }
  cVar1 = EasterEggs__IsPartUnlocked();
  if (((cVar1 == '\0') && (cVar1 = Career__IsUpgradeUnlocked(&DAT_0075eef8,0), cVar1 == '\0')) &&
     (DAT_00735e10 == '\0')) {
    return 1;
  }
  return 2;
}


// ==== 0x4d8500 FUN_004d8500

void FUN_004d8500(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0x6c);
  do {
    if (*piVar2 == 0) {
LAB_004d8541:
      *(undefined1 *)(iVar3 + 0xaac + param_1) = 0;
    }
    else {
      cVar1 = IsPaintOwned();
      if (cVar1 == '\0') goto LAB_004d8541;
      cVar1 = IsPaintOwned();
      if (cVar1 != '\0') {
        cVar1 = FUN_004d8370();
        *(char *)(iVar3 + 0xaac + param_1) = (cVar1 != '\0') + '\x01';
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 0xb;
  } while (iVar3 < 10);
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0x224);
  do {
    if (*piVar2 == 0) {
LAB_004d8591:
      *(undefined1 *)(iVar3 + 0xab6 + param_1) = 0;
    }
    else {
      cVar1 = IsPaintOwned();
      if (cVar1 == '\0') goto LAB_004d8591;
      cVar1 = IsPaintOwned();
      if (cVar1 != '\0') {
        cVar1 = FUN_004d8370();
        *(char *)(iVar3 + 0xab6 + param_1) = (cVar1 != '\0') + '\x01';
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 0xb;
  } while (iVar3 < 0x14);
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0x594);
  do {
    if (*piVar2 == 0) {
LAB_004d85e1:
      *(undefined1 *)(iVar3 + 0xaca + param_1) = 0;
    }
    else {
      cVar1 = IsPaintOwned();
      if (cVar1 == '\0') goto LAB_004d85e1;
      cVar1 = IsPaintOwned();
      if (cVar1 != '\0') {
        cVar1 = FUN_004d8370();
        *(char *)(iVar3 + 0xaca + param_1) = (cVar1 != '\0') + '\x01';
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 0xb;
    if (0x1d < iVar3) {
      return;
    }
  } while( true );
}


// ==== 0x4d8600 FUN_004d8600

void FUN_004d8600(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int local_18;
  int local_10;
  char *local_c;
  char *local_8;
  
  if (DAT_00745e40 == 1) {
    cVar1 = IsLevel2PaintsOwned();
    if (cVar1 == '\0') {
      FUN_00495fc0();
    }
    else {
      FUN_00495f70();
    }
    cVar1 = IsLevel3PaintsOwned();
    if (cVar1 == '\0') {
      FUN_00495fc0();
      FUN_00495fc0();
      FUN_00495fc0();
      FUN_00495fc0();
    }
    else {
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
    }
    local_8 = (char *)(param_1 + 0xaac);
    local_c = (char *)0x1;
    local_10 = 10;
    do {
      FUN_00565da0("locked_icon_%d",local_c);
      FUN_00565da0("LOCKED_ICON_%d",local_c);
      uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_c);
      uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_c);
      cVar1 = *local_8;
      if (cVar1 == '\0') {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004ef050(uVar2);
          }
        }
        FEObject__SetInvisible(iVar4);
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            uVar2 = FUN_004ef050(uVar3);
            FEObject__SetInvisible(uVar2);
            goto LAB_004d8877;
          }
          iVar4 = 0;
        }
        FEObject__SetInvisible(iVar4);
      }
      else if (cVar1 == '\x01') {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004ef050(uVar3);
          }
        }
        FEObject__SetVisible(iVar4);
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            uVar2 = FUN_004ef050(uVar2);
            FEObject__SetVisible(uVar2);
            goto LAB_004d8877;
          }
          iVar4 = 0;
        }
        FEObject__SetVisible(iVar4);
      }
      else if (cVar1 == '\x02') {
        FUN_00495fc0();
        FUN_00495f70();
      }
LAB_004d8877:
      local_c = (char *)((int)local_c + 1);
      local_8 = local_8 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    local_c = (char *)(param_1 + 0xab6);
    local_18 = 0x14;
    do {
      uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_c + (-0xaab - param_1));
      uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_c + (-0xaab - param_1));
      cVar1 = *local_c;
      if (cVar1 == '\0') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8961:
          iVar5 = 0;
          if (iVar4 == 0) {
LAB_004d897b:
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_004ef050(uVar2);
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
                  (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d8961;
              goto LAB_004d8941;
            }
            goto LAB_004d897b;
          }
LAB_004d8941:
          if ((iVar5 == 0) ||
             (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
          goto LAB_004d8961;
        }
        FEObject__SetInvisible(iVar6);
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d89fe:
          if (iVar5 == 0) goto LAB_004d8b97;
          iVar4 = FUN_004ef050(uVar3);
        }
        else {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          iVar5 = DAT_0073578c;
          if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004d89e2:
            if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 != 0))
            goto LAB_004d8b99;
            goto LAB_004d89fe;
          }
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d89fe;
            goto LAB_004d89e2;
          }
LAB_004d8b97:
          iVar4 = 0;
        }
LAB_004d8b99:
        FEObject__SetInvisible(iVar4);
      }
      else if (cVar1 == '\x01') {
        if (((((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
             (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
            ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(uVar3), iVar4 != 0)))) &&
           (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar4 + 0x18) == 5)) {
          uVar3 = *(undefined4 *)(iVar4 + 0x60);
          iVar4 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar4) {
            do {
              FEObject__SetVisible(uVar3);
              uVar3 = *(undefined4 *)(extraout_EDX + 4);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        if (((((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
             (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
            ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(uVar2), iVar4 != 0)))) &&
           (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar4 + 0x18) == 5)) {
          uVar2 = *(undefined4 *)(iVar4 + 0x60);
          iVar4 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar4) {
            do {
              FEObject__SetVisible(uVar2);
              uVar2 = *(undefined4 *)(extraout_EDX_00 + 4);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
      }
      else if (cVar1 == '\x02') {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004ef050(uVar3);
          }
        }
        FEObject__SetVisible(iVar4);
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            iVar4 = FUN_004ef050(uVar2);
            goto LAB_004d8b99;
          }
          goto LAB_004d8b97;
        }
        goto LAB_004d8b99;
      }
      local_c = local_c + 1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
    local_10 = 0;
    do {
      uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_10 + 0x1f);
      uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_10 + 0x1f);
      cVar1 = *(char *)(param_1 + 0xaca + local_10);
      if (cVar1 == '\0') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8c6b:
          iVar5 = 0;
          if (iVar4 == 0) {
LAB_004d8c85:
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_004ef050(uVar2);
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
                  (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d8c6b;
              goto LAB_004d8c4b;
            }
            goto LAB_004d8c85;
          }
LAB_004d8c4b:
          if ((iVar5 == 0) ||
             (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
          goto LAB_004d8c6b;
        }
        FEObject__SetInvisible(iVar6);
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8d08:
          if (iVar5 == 0) goto LAB_004d9019;
          iVar4 = FUN_004ef050(uVar3);
        }
        else {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          iVar5 = DAT_0073578c;
          if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_004d8cec:
            if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 != 0))
            goto LAB_004d901b;
            goto LAB_004d8d08;
          }
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d8d08;
            goto LAB_004d8cec;
          }
LAB_004d9019:
          iVar4 = 0;
        }
LAB_004d901b:
        FEObject__SetInvisible(iVar4);
      }
      else if (cVar1 == '\x01') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8d9f:
          iVar5 = 0;
          if ((iVar4 != 0) && (iVar6 = FUN_004ef050(uVar3), iVar5 = DAT_0073578c, iVar6 != 0)) {
LAB_004d8db5:
            *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
            iVar5 = DAT_0073578c;
            if (*(int *)(iVar6 + 0x18) == 5) {
              uVar3 = *(undefined4 *)(iVar6 + 0x60);
              iVar4 = *(int *)(iVar6 + 0x5c);
              if (0 < iVar4) {
                do {
                  FEObject__SetVisible(uVar3);
                  uVar3 = *(undefined4 *)(extraout_EDX_01 + 4);
                  iVar4 = iVar4 + -1;
                  iVar5 = DAT_0073578c;
                } while (iVar4 != 0);
              }
            }
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          iVar4 = DAT_0073578c;
          if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004d8d87:
            if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
            goto LAB_004d8d9f;
            goto LAB_004d8db5;
          }
          iVar5 = DAT_0073578c;
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d8d9f;
            goto LAB_004d8d87;
          }
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8e61:
          if ((iVar5 == 0) || (iVar4 = FUN_004ef050(uVar2), iVar4 == 0)) goto LAB_004d9024;
        }
        else {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          iVar5 = DAT_0073578c;
          if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
            if (DAT_0073578c == 0) goto LAB_004d9024;
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d8e61;
          }
          if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
          goto LAB_004d8e61;
        }
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000;
        if (*(int *)(iVar4 + 0x18) == 5) {
          uVar2 = *(undefined4 *)(iVar4 + 0x60);
          iVar4 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar4) {
            do {
              FEObject__SetVisible(uVar2);
              uVar2 = *(undefined4 *)(extraout_EDX_02 + 4);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
      }
      else if (cVar1 == '\x02') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d8f40:
          iVar5 = 0;
          if ((iVar4 != 0) && (iVar6 = FUN_004ef050(uVar3), iVar5 = DAT_0073578c, iVar6 != 0)) {
LAB_004d8f56:
            *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
            iVar5 = DAT_0073578c;
            if (*(int *)(iVar6 + 0x18) == 5) {
              uVar3 = *(undefined4 *)(iVar6 + 0x60);
              iVar4 = *(int *)(iVar6 + 0x5c);
              if (0 < iVar4) {
                do {
                  FEObject__SetVisible(uVar3);
                  uVar3 = *(undefined4 *)(extraout_EDX_03 + 4);
                  iVar4 = iVar4 + -1;
                  iVar5 = DAT_0073578c;
                } while (iVar4 != 0);
              }
            }
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          iVar4 = DAT_0073578c;
          if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004d8f28:
            if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
            goto LAB_004d8f40;
            goto LAB_004d8f56;
          }
          iVar5 = DAT_0073578c;
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d8f40;
            goto LAB_004d8f28;
          }
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d9005:
          if (iVar5 != 0) {
            iVar4 = FUN_004ef050(uVar2);
            goto LAB_004d901b;
          }
          goto LAB_004d9019;
        }
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        iVar5 = DAT_0073578c;
        if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d9005;
            goto LAB_004d8fed;
          }
          goto LAB_004d9019;
        }
LAB_004d8fed:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
        goto LAB_004d9005;
        goto LAB_004d901b;
      }
LAB_004d9024:
      local_10 = local_10 + 1;
      if (0x1d < local_10) {
        return;
      }
    } while( true );
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0xa16f9ec5);
    }
  }
  FEObject__SetInvisible(iVar4);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0xa3c4c766);
    }
  }
  FEObject__SetInvisible(iVar4);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x9db42e6c);
    }
  }
  FEObject__SetInvisible(iVar4);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x9db42e6d);
    }
  }
  FEObject__SetInvisible(iVar4);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x9db42e6e);
    }
  }
  FEObject__SetInvisible(iVar4);
  local_c = (char *)(param_1 + 0xaac);
  local_18 = 10;
  do {
    uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_c + (-0xaab - param_1));
    uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_c + (-0xaab - param_1));
    cVar1 = *local_c;
    if (cVar1 == '\0') {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(uVar2);
        }
      }
      FEObject__SetInvisible(iVar4);
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c != 0) {
          uVar2 = FUN_004ef050(uVar3);
          FEObject__SetInvisible(uVar2);
          goto LAB_004d933a;
        }
LAB_004d927c:
        iVar4 = 0;
      }
LAB_004d927e:
      FEObject__SetInvisible(iVar4);
    }
    else if (cVar1 == '\x01') {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(uVar3);
        }
      }
      FEObject__SetInvisible(iVar4);
      if (((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
         (iVar4 = FUN_004ffb70(), iVar4 != 0)) goto LAB_004d927e;
      if (DAT_0073578c == 0) goto LAB_004d927c;
      uVar2 = FUN_004ef050(uVar2);
      FEObject__SetInvisible(uVar2);
    }
    else if (cVar1 == '\x02') {
      FUN_00495fc0();
      FUN_00495f70();
    }
LAB_004d933a:
    local_c = local_c + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  local_c = (char *)(param_1 + 0xab6);
  local_10 = 0x14;
  do {
    uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_c + (-0xaab - param_1));
    uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_c + (-0xaab - param_1));
    cVar1 = *local_c;
    if (cVar1 == '\0') {
      iVar4 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d9411:
        iVar5 = 0;
        if (iVar4 == 0) {
LAB_004d942b:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(uVar2);
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
                (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d9411;
            goto LAB_004d93f1;
          }
          goto LAB_004d942b;
        }
LAB_004d93f1:
        if ((iVar5 == 0) ||
           (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
        goto LAB_004d9411;
      }
      FEObject__SetInvisible(iVar6);
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d94ae:
        if (iVar5 == 0) {
LAB_004d95a3:
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(uVar3);
        }
      }
      else {
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        iVar5 = DAT_0073578c;
        if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d94ae;
            goto LAB_004d9492;
          }
          goto LAB_004d95a3;
        }
LAB_004d9492:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
        goto LAB_004d94ae;
      }
LAB_004d95a5:
      FEObject__SetInvisible(iVar4);
    }
    else {
      if (cVar1 == '\x01') {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004ef050(uVar3);
          }
        }
        FEObject__SetInvisible(iVar4);
        iVar4 = *(int *)(param_1 + 0xc);
LAB_004d9513:
        if (((iVar4 == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) goto LAB_004d95a3;
          iVar4 = FUN_004ef050(uVar2);
        }
        goto LAB_004d95a5;
      }
      if (cVar1 == '\x02') {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            uVar3 = FUN_004ef050(uVar3);
            FEObject__SetVisible(uVar3);
            iVar4 = *(int *)(param_1 + 0xc);
            goto LAB_004d9513;
          }
          iVar4 = 0;
        }
        FEObject__SetVisible(iVar4);
        iVar4 = *(int *)(param_1 + 0xc);
        goto LAB_004d9513;
      }
    }
    local_c = local_c + 1;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_18 = 0;
  do {
    uVar2 = FUN_004f42f0("LOCKED_ICON_%d",local_18 + 0x1f);
    uVar3 = FUN_004f42f0("COLORELEMENT_%d",local_18 + 0x1f);
    cVar1 = *(char *)(param_1 + 0xaca + local_18);
    if (cVar1 == '\0') {
      iVar4 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d9672:
        iVar5 = 0;
        if (iVar4 == 0) {
LAB_004d968c:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(uVar2);
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
                (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d9672;
            goto LAB_004d9652;
          }
          goto LAB_004d968c;
        }
LAB_004d9652:
        if ((iVar5 == 0) ||
           (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
        goto LAB_004d9672;
      }
      FEObject__SetInvisible(iVar6);
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d970f:
        if (iVar5 == 0) {
LAB_004d993a:
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(uVar3);
        }
      }
      else {
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        iVar5 = DAT_0073578c;
        if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d970f;
            goto LAB_004d96f3;
          }
          goto LAB_004d993a;
        }
LAB_004d96f3:
        if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 == 0))
        goto LAB_004d970f;
      }
LAB_004d993c:
      FEObject__SetInvisible(iVar4);
    }
    else {
      if (cVar1 == '\x01') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d97aa:
          iVar5 = 0;
          if (iVar4 == 0) {
LAB_004d97c4:
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_004ef050(uVar3);
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
                  (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d97aa;
              goto LAB_004d978a;
            }
            goto LAB_004d97c4;
          }
LAB_004d978a:
          if ((iVar5 == 0) ||
             (iVar6 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 = DAT_0073578c, iVar6 == 0))
          goto LAB_004d97aa;
        }
        FEObject__SetInvisible(iVar6);
LAB_004d97cf:
        if (*(int *)(param_1 + 0xc) != 0) {
          iVar4 = FEPackageList__FindByName(&DAT_00746104);
          iVar5 = DAT_0073578c;
          if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
            if (DAT_0073578c == 0) goto LAB_004d993a;
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar4 = FUN_004fd1e0(iVar6 + 0xdc), iVar4 == 0 &&
                (iVar4 = FUN_004fd1e0(iVar6 + 0xec), iVar4 == 0)))) goto LAB_004d9847;
          }
          if ((iVar4 != 0) && (iVar4 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar4 != 0))
          goto LAB_004d993c;
        }
LAB_004d9847:
        if (iVar5 == 0) goto LAB_004d993a;
        iVar4 = FUN_004ef050(uVar2);
        goto LAB_004d993c;
      }
      if (cVar1 == '\x02') {
        iVar4 = DAT_0073578c;
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d98de:
          iVar5 = 0;
          if ((iVar4 != 0) && (iVar6 = FUN_004ef050(uVar3), iVar5 = DAT_0073578c, iVar6 != 0)) {
LAB_004d98f8:
            *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
            iVar5 = DAT_0073578c;
            if (*(int *)(iVar6 + 0x18) == 5) {
              uVar3 = *(undefined4 *)(iVar6 + 0x60);
              iVar4 = *(int *)(iVar6 + 0x5c);
              if (0 < iVar4) {
                do {
                  FEObject__SetVisible(uVar3);
                  uVar3 = *(undefined4 *)(extraout_EDX_04 + 4);
                  iVar4 = iVar4 + -1;
                  iVar5 = DAT_0073578c;
                } while (iVar4 != 0);
              }
            }
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          iVar4 = DAT_0073578c;
          if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004d98c6:
            if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
            goto LAB_004d98de;
            goto LAB_004d98f8;
          }
          iVar5 = DAT_0073578c;
          if (DAT_0073578c != 0) {
            iVar6 = *(int *)(DAT_0073578c + 8);
            if ((iVar6 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004d98de;
            goto LAB_004d98c6;
          }
        }
        goto LAB_004d97cf;
      }
    }
    local_18 = local_18 + 1;
    if (0x1d < local_18) {
      return;
    }
  } while( true );
}


// ==== 0x4d9960 Screen_PC_ColorPicker::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_ColorPicker__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688923;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xbd8);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_ColorPicker__Screen_PC_ColorPicker(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4d99c0 FUN_004d99c0

undefined4 FUN_004d99c0(int param_1,undefined4 *param_2)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar2 = 0;
  uVar1 = ColorPicker__GetHighestUpgradeLevel(in_EAX);
  switch(uVar1) {
  case 0:
  case 1:
    iVar2 = 0;
    break;
  case 2:
    iVar2 = 1;
    break;
  case 3:
    iVar2 = 3;
  }
  *unaff_EDI = iVar2;
  *param_2 = 0;
  if (param_1 == 1) {
    uVar1 = 1;
    if (*unaff_EDI == 0) {
      *unaff_EDI = 1;
      return uVar1;
    }
  }
  else if (param_1 + -2 == 0) {
    uVar1 = 1;
    if (*unaff_EDI < 3) {
      *unaff_EDI = 3;
      return uVar1;
    }
  }
  else {
    uVar1 = CONCAT31((int3)((uint)(param_1 + -2) >> 8),1);
  }
  return uVar1;
}


// ==== 0x4d9a40 ColorPicker_BindElements

/* [canon] car med (hopper+capstone) docs/re/misc.md */

void ColorPicker_BindElements(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_c;
  
  *(undefined4 *)(param_1 + 0xaf0) = 0;
  *(undefined4 *)(param_1 + 0xaec) = 0;
  *(undefined4 *)(param_1 + 0xae8) = 0;
  local_c = 0;
  puVar9 = (undefined4 *)(param_1 + 0x70);
  do {
    iVar6 = *(int *)(param_1 + 0xc);
    iVar4 = local_c + 1;
    uVar5 = FUN_004f42f0("COLORELEMENT_%d",iVar4);
    iVar7 = DAT_0073578c;
    if (iVar6 == 0) {
LAB_004d9b03:
      if ((iVar7 == 0) || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)) goto LAB_004d9b20;
LAB_004d9b1a:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004d9b20;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004d9ae6:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar6 == 0))
        goto LAB_004d9b03;
        goto LAB_004d9b1a;
      }
      if (DAT_0073578c != 0) {
        iVar1 = *(int *)(DAT_0073578c + 8);
        if ((iVar1 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar1 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar1 + 0xec), iVar6 == 0)))) goto LAB_004d9b03;
        goto LAB_004d9ae6;
      }
LAB_004d9b20:
      iVar6 = 0;
    }
    puVar9[-2] = iVar6;
    puVar9[4] = 0;
    puVar9[5] = local_c;
    iVar6 = puVar9[-2];
    puVar9[-1] = 0;
    puVar9[2] = 0;
    puVar9[1] = 0;
    *puVar9 = 0;
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) < 0x100)) {
      cVar3 = FEColor_NearlyEqual();
      if (cVar3 == '\0') {
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar6,0,0);
    }
    puVar9 = puVar9 + 0xb;
    local_c = iVar4;
  } while (iVar4 < 10);
  local_c = 0;
  puVar9 = (undefined4 *)(param_1 + 0x228);
  do {
    iVar6 = *(int *)(param_1 + 0xc);
    uVar5 = FUN_004f42f0("COLORELEMENT_%d",local_c + 0xb);
    iVar7 = DAT_0073578c;
    if (iVar6 == 0) {
LAB_004d9c1b:
      if ((iVar7 == 0) || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)) goto LAB_004d9c38;
LAB_004d9c32:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004d9c38;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004d9c02:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar6 == 0))
        goto LAB_004d9c1b;
        goto LAB_004d9c32;
      }
      if (DAT_0073578c != 0) {
        iVar4 = *(int *)(DAT_0073578c + 8);
        if ((iVar4 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar4 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar4 + 0xec), iVar6 == 0)))) goto LAB_004d9c1b;
        goto LAB_004d9c02;
      }
LAB_004d9c38:
      iVar6 = 0;
    }
    puVar9[-2] = iVar6;
    iVar6 = local_c + -10;
    if (local_c < 10) {
      iVar6 = local_c;
    }
    puVar9[4] = (9 < local_c) + 1;
    puVar9[5] = iVar6;
    iVar6 = puVar9[-2];
    puVar9[-1] = 0;
    puVar9[2] = 0;
    puVar9[1] = 0;
    *puVar9 = 0;
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) < 0x100)) {
      cVar3 = FEColor_NearlyEqual();
      if (cVar3 == '\0') {
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar6,0,0);
    }
    local_c = local_c + 1;
    puVar9 = puVar9 + 0xb;
  } while (local_c < 0x14);
  local_c = 0;
  piVar8 = (int *)(param_1 + 0x59c);
  do {
    iVar6 = *(int *)(param_1 + 0xc);
    uVar5 = FUN_004f42f0("COLORELEMENT_%d",local_c + 0x1f);
    iVar7 = DAT_0073578c;
    if (iVar6 == 0) {
LAB_004d9d4b:
      if ((iVar7 == 0) || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)) goto LAB_004d9d68;
LAB_004d9d62:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004d9d68;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004d9d32:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar6 == 0))
        goto LAB_004d9d4b;
        goto LAB_004d9d62;
      }
      if (DAT_0073578c != 0) {
        iVar4 = *(int *)(DAT_0073578c + 8);
        if ((iVar4 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar4 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar4 + 0xec), iVar6 == 0)))) goto LAB_004d9d4b;
        goto LAB_004d9d32;
      }
LAB_004d9d68:
      iVar6 = 0;
    }
    piVar8[-3] = iVar6;
    if (local_c < 0x14) {
      iVar6 = (9 < local_c) + 3;
      iVar7 = local_c;
      if (9 < local_c) {
        iVar7 = local_c + -10;
      }
    }
    else {
      iVar6 = 5;
      iVar7 = local_c + -0x14;
    }
    piVar8[4] = iVar7;
    piVar8[3] = iVar6;
    iVar6 = piVar8[-3];
    piVar8[-2] = 0;
    piVar8[1] = 0;
    *piVar8 = 0;
    piVar8[-1] = 0;
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) < 0x100)) {
      piVar2 = *(int **)(iVar6 + 0x2c);
      if ((piVar8[1] + 1 < piVar2[2]) || (piVar2[2] < piVar8[1] + -1)) {
LAB_004d9e07:
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
      else {
        if ((*piVar8 + 1 < piVar2[1]) || (piVar2[1] < *piVar8 + -1)) goto LAB_004d9e07;
        iVar7 = piVar8[-1];
        if ((iVar7 + 1 < *piVar2) || (*piVar2 < iVar7 + -1)) goto LAB_004d9e07;
        if ((piVar8[2] + 1 < piVar2[3]) || (piVar2[3] < piVar8[2] + -1)) goto LAB_004d9e07;
      }
      FUN_004ff2f0(iVar6,0,0);
    }
    local_c = local_c + 1;
    piVar8 = piVar8 + 0xb;
    if (0x1d < local_c) {
      return;
    }
  } while( true );
}


// ==== 0x4d9e40 FUN_004d9e40

void FUN_004d9e40(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_4;
  
  *(undefined4 *)(param_1 + 0xaf0) = 0;
  *(undefined4 *)(param_1 + 0xaec) = 0;
  *(undefined4 *)(param_1 + 0xae8) = 0;
  puVar5 = (undefined4 *)(param_1 + 0x70);
  local_4 = 10;
  do {
    iVar4 = puVar5[-2];
    puVar5[-1] = 0;
    puVar5[2] = 0;
    puVar5[1] = 0;
    *puVar5 = 0;
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) < 0x100)) {
      cVar3 = FEColor_NearlyEqual();
      if (cVar3 == '\0') {
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar4,0,0);
    }
    puVar5 = puVar5 + 0xb;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  puVar5 = (undefined4 *)(param_1 + 0x228);
  iVar4 = 0x14;
  do {
    iVar1 = puVar5[-2];
    puVar5[-1] = 0;
    puVar5[2] = 0;
    puVar5[1] = 0;
    *puVar5 = 0;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) < 0x100)) {
      cVar3 = FEColor_NearlyEqual();
      if (cVar3 == '\0') {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar1,0,0);
    }
    puVar5 = puVar5 + 0xb;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar6 = (int *)(param_1 + 0x59c);
  param_1 = 0x1e;
  do {
    iVar4 = piVar6[-3];
    piVar6[-2] = 0;
    piVar6[1] = 0;
    *piVar6 = 0;
    piVar6[-1] = 0;
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) < 0x100)) {
      piVar2 = *(int **)(iVar4 + 0x2c);
      if ((piVar2[2] < 2) && (-2 < piVar2[2])) {
        if ((*piVar6 + 1 < piVar2[1]) || (piVar2[1] < *piVar6 + -1)) goto LAB_004d9f74;
        iVar1 = piVar6[-1];
        if ((iVar1 + 1 < *piVar2) || (*piVar2 < iVar1 + -1)) goto LAB_004d9f74;
        if ((piVar6[2] + 1 < piVar2[3]) || (piVar2[3] < piVar6[2] + -1)) goto LAB_004d9f74;
      }
      else {
LAB_004d9f74:
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(iVar4,0,0);
    }
    piVar6 = piVar6 + 0xb;
    param_1 = param_1 + -1;
    if (param_1 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4d9fa0 GetDefaultVinylColors

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 GetDefaultVinylColors(uint *param_1,uint *param_2,uint *param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint *unaff_EDI;
  
  puVar2 = DAT_0073ad40;
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    uVar5 = puVar2[3];
    uVar4 = puVar2[4] * 0x30 + uVar5;
    for (; uVar5 < uVar4; uVar5 = uVar5 + 0x30) {
      if (*(char *)(uVar5 + 0x10) == '\x1e') goto joined_r0x004d9fea;
    }
  }
  uVar5 = 0;
joined_r0x004d9fea:
  for (; uVar5 != 0; uVar5 = CarPartDatabase__GetCarPart(0,0x1e,0,uVar5,0xffffffff)) {
    pcVar7 = "VINYL_L1_COLOR02";
    iVar6 = -1;
    uVar4 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if (*(int *)(uVar5 + 8) == iVar6) {
      *unaff_EDI = uVar5;
    }
    pcVar7 = "VINYL_L1_COLOR01";
    iVar6 = -1;
    uVar4 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if (*(int *)(uVar5 + 8) == iVar6) {
      *param_1 = uVar5;
    }
    pcVar7 = "VINYL_L1_COLOR03";
    iVar6 = -1;
    uVar4 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if (*(int *)(uVar5 + 8) == iVar6) {
      *param_2 = uVar5;
    }
    pcVar7 = "VINYL_L1_COLOR04";
    iVar6 = -1;
    uVar4 = 0x56;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    if (*(int *)(uVar5 + 8) == iVar6) {
      *param_3 = uVar5;
    }
  }
  if ((((*unaff_EDI != 0) && (*param_1 != 0)) && (*param_2 != 0)) && (*param_3 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x4da0d0 FUN_004da0d0

void FUN_004da0d0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  undefined4 local_8;
  undefined4 *local_4;
  
  iVar4 = 0;
  if (0 < *(int *)(unaff_ESI + 0xb34)) {
    local_4 = (undefined4 *)NullUpdate_ret();
    iVar2 = *(int *)(unaff_ESI + 0xb20);
    do {
      iVar3 = 0;
      for (puVar1 = *(undefined4 **)(unaff_ESI + 0xb2c); puVar1 != local_4;
          puVar1 = (undefined4 *)*puVar1) {
        if (iVar4 == iVar3) goto LAB_004da12d;
        iVar3 = iVar3 + 1;
      }
      puVar1 = (undefined4 *)0x0;
LAB_004da12d:
      local_8 = 0;
      FUN_004d99c0(puVar1[2],&local_8);
      iVar3 = *(int *)(unaff_ESI + 0xb24);
      if (iVar3 < iVar2) {
        do {
          iVar2 = iVar2 * iVar4 + iVar3;
          *(undefined4 *)(unaff_ESI + 0xb78 + iVar2 * 4) = 0;
          *(undefined4 *)(unaff_ESI + 0xb38 + iVar2 * 4) = local_8;
          iVar2 = *(int *)(unaff_ESI + 0xb20);
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0xb34));
  }
  return;
}


// ==== 0x4da1a0 FUN_004da1a0

void FUN_004da1a0(void)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int extraout_ECX;
  char *pcVar7;
  uint uVar8;
  int extraout_EDX;
  int iVar9;
  undefined4 *puVar10;
  bool bVar11;
  char local_28 [32];
  int local_8;
  
  ColorPicker_BindElements(in_EAX);
  *(undefined4 *)(in_EAX + 0x40) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined4 *)(in_EAX + 0x48) = 0;
  *(undefined4 *)(in_EAX + 0x4c) = 0;
  *(undefined1 *)(in_EAX + 3000) = 0;
  FUN_004f6a10("MU_HorizontalBrowserBack.fng",0);
  iVar4 = *(int *)(in_EAX + 0xc);
  *(undefined4 *)(in_EAX + 0xb04) = 6;
  *(undefined4 *)(in_EAX + 0xb08) = 10;
  uVar3 = FEng__HashName();
  if (((((iVar4 == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(uVar3), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 1)) {
    iVar4 = 0;
  }
  iVar9 = *(int *)(in_EAX + 0xc);
  *(int *)(in_EAX + 0xaf4) = iVar4;
  uVar3 = FEng__HashName();
  if (((((iVar9 == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(uVar3), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 1)) {
    iVar4 = 0;
  }
  uVar3 = 0;
  bVar11 = DAT_00735718 == 3;
  *(int *)(in_EAX + 0xaf8) = iVar4;
  *(undefined4 *)(in_EAX + 0xb0c) = 0;
  *(undefined4 *)(in_EAX + 0xb10) = 0;
  *(undefined4 *)(in_EAX + 0xafc) = 0;
  *(undefined1 *)(in_EAX + 0xb00) = 1;
  local_8 = 0x1e;
  if (bVar11) {
    if (DAT_006f88a4 == 0) {
      FUN_00495f00(0xa3b76154);
      *(undefined4 *)(in_EAX + 0xb1c) = 0;
      local_8 = 0x1e;
    }
    else if (DAT_006f88a4 == 2) {
      FUN_00495f00(0xa8d7e6ed);
      *(undefined4 *)(in_EAX + 0xb1c) = 3;
      local_8 = 0x26;
    }
    else if (DAT_006f88a4 == 4) {
      FUN_00495f00(0xd223f84a);
      *(undefined4 *)(in_EAX + 0xb1c) = 1;
      local_8 = 0x29;
    }
    else {
      if (DAT_006f88a4 != 5) goto LAB_004da37d;
      FUN_00495f00(0xa6343aec);
      *(undefined4 *)(in_EAX + 0xb1c) = 5;
      local_8 = 0x28;
    }
  }
  else {
LAB_004da37d:
    cVar2 = FUN_0050f9f0();
    if (cVar2 == '\0') {
      cVar2 = FUN_0050fa10();
      uVar5 = DAT_006fa1a0;
      if (cVar2 == '\0') {
        if ((extraout_EDX == 5) && (DAT_00735ddc == 3)) {
          *(undefined4 *)(in_EAX + 0xb1c) = 6;
          iVar4 = extraout_ECX;
          switch(uVar5) {
          case 0x1f:
            uVar3 = 4;
            local_8 = 0x2a;
            iVar4 = local_8;
            break;
          case 0x20:
            uVar3 = 3;
            local_8 = 0x2e;
            iVar4 = local_8;
            break;
          case 0x21:
            uVar3 = 2;
            local_8 = 0x32;
            iVar4 = local_8;
            break;
          case 0x22:
            uVar3 = 1;
            local_8 = 0x36;
            iVar4 = local_8;
          }
          *(int *)(in_EAX + 0x50) = iVar4;
          *(undefined4 *)(in_EAX + 0x40) = (&DAT_00745b6c)[iVar4];
          *(undefined4 *)(in_EAX + 0x44) = *(undefined4 *)(&DAT_00745b70 + iVar4 * 4);
          *(undefined4 *)(in_EAX + 0x48) = (&DAT_00745b74)[iVar4];
          *(undefined4 *)(in_EAX + 0x4c) = *(undefined4 *)(&DAT_00745b78 + iVar4 * 4);
        }
      }
      else {
        FUN_00495f00(0x87b7eb73);
        *(undefined4 *)(in_EAX + 0xb1c) = 4;
        local_8 = 0x27;
      }
    }
    else {
      FUN_00495f00(0x4e875a92);
      *(undefined4 *)(in_EAX + 0xb1c) = 2;
      local_8 = 0x25;
    }
  }
  iVar4 = *(int *)(in_EAX + 0xb1c);
  *(undefined4 *)(in_EAX + 0xafc) = 0;
  *(undefined1 *)(in_EAX + 0xb00) = 1;
  if ((iVar4 == 6) && (DAT_00735de8 != 0)) {
    pcVar7 = "NUMREMAPCOLOURS";
    do {
      pcVar1 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    uVar5 = FUN_0057cc70(0);
    *(undefined4 *)(in_EAX + 0xb20) = uVar5;
    uVar3 = ComputeVinylIconHash(uVar3);
    FUN_004ad7b0(uVar3);
  }
  else {
    if (iVar4 < 0) {
LAB_004da506:
      uVar3 = 0xffffffff;
    }
    else if (iVar4 < 6) {
      uVar3 = 1;
    }
    else {
      if (iVar4 != 6) goto LAB_004da506;
      uVar3 = 4;
    }
    *(undefined4 *)(in_EAX + 0xb20) = uVar3;
  }
  iVar4 = FUN_004d7b70(&DAT_0074696c);
  *(int *)(in_EAX + 0xb34) = iVar4;
  if (iVar4 == 1) {
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x5a418323);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x718751d6);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xdfb9b476);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xc31fb618);
      }
    }
    FEObject__SetInvisible(iVar4);
  }
  *(undefined4 *)(in_EAX + 0xb24) = 0;
  *(undefined4 *)(in_EAX + 0xb28) = 0;
  *(undefined4 *)(in_EAX + 0xaac) = 0;
  *(undefined4 *)(in_EAX + 0xab0) = 0;
  *(undefined2 *)(in_EAX + 0xab4) = 0;
  *(undefined4 *)(in_EAX + 0xab6) = 0;
  *(undefined4 *)(in_EAX + 0xaba) = 0;
  *(undefined4 *)(in_EAX + 0xabe) = 0;
  *(undefined4 *)(in_EAX + 0xac2) = 0;
  *(undefined4 *)(in_EAX + 0xac6) = 0;
  puVar10 = (undefined4 *)(in_EAX + 0xaca);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  FUN_004dbc70(in_EAX,0x1e,local_8);
  uVar3 = FUN_004d7af0(&DAT_0074696c);
  uVar5 = FUN_004d7a30(&DAT_0074696c);
  FUN_00495f00(uVar5);
  FUN_00495f00(uVar3);
  if (*(int *)(in_EAX + 0xb1c) == 6) {
    switch(DAT_006fa1a0) {
    case 0x1f:
      uVar3 = 4;
      break;
    case 0x20:
      uVar3 = 3;
      break;
    case 0x21:
      uVar3 = 2;
      break;
    case 0x22:
      uVar3 = 1;
      break;
    default:
      uVar3 = 0xffffffff;
    }
    iVar4 = LanguageStrings__FindByHash();
    if (iVar4 == 0) {
      iVar4 = LanguageStrings__FindByHash();
    }
    iVar9 = 0x20;
    pcVar7 = local_28;
    do {
      cVar2 = pcVar7[iVar4 - (int)local_28];
      iVar9 = iVar9 + -1;
      *pcVar7 = cVar2;
      if (cVar2 == '\0') break;
      pcVar7 = pcVar7 + 1;
    } while (iVar9 != 0);
    FUN_004f6850("%s %i",local_28,uVar3);
  }
  else {
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xfac7f39a);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x841b49f1);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0x86ae47d7);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c != 0) {
        uVar3 = FUN_004ef050(0x7f52f045);
        FEObject__SetInvisible(uVar3);
        goto LAB_004da8af;
      }
      iVar4 = 0;
    }
    FEObject__SetInvisible(iVar4);
  }
LAB_004da8af:
  if (*(int *)(in_EAX + 0xb34) < 2) {
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xdfb9b476);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xc31fb618);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xd0440103);
      }
    }
    FEObject__SetInvisible(iVar4);
    if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xecda84a5);
      }
    }
    FEObject__SetInvisible(iVar4);
  }
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x8a3840b9);
    }
  }
  FEObject__SetInvisible(iVar4);
  uVar6 = *(int *)(in_EAX + 0xb20) * *(int *)(in_EAX + 0xb34);
  if (1 < (int)uVar6) {
    puVar10 = (undefined4 *)(in_EAX + 0xb78);
    for (uVar8 = uVar6 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar10 = (undefined4 *)(in_EAX + 0xb38);
    for (uVar6 = uVar6 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    FUN_004da0d0();
  }
  if ((&DAT_00745b6c)[*(int *)(in_EAX + 0xb18)] == 0) {
    *(undefined4 *)(in_EAX + 0xb10) = 0;
    *(undefined4 *)(in_EAX + 0xb0c) = 0;
  }
  else {
    iVar4 = FUN_004dbb40();
    if (iVar4 == 0) {
      *(undefined4 *)(in_EAX + 0xb10) = 0;
      *(undefined4 *)(in_EAX + 0xb0c) = 0;
    }
    else {
      *(undefined4 *)(in_EAX + 0xb0c) = *(undefined4 *)(iVar4 + 0x24);
      *(undefined4 *)(in_EAX + 0xb10) = *(undefined4 *)(iVar4 + 0x28);
    }
  }
  FUN_004dbf90();
  FUN_004db8a0();
  *(undefined1 *)(in_EAX + 0x54) = 0;
  iVar4 = FUN_004b2330();
  if (iVar4 != 0) {
    FUN_004b0150();
  }
  return;
}


// ==== 0x4dab10 Screen_PC_ColorPicker::Screen_PC_ColorPicker

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PC_ColorPicker__Screen_PC_ColorPicker(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006888fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006c3c14;
  eh_vector_constructor_iterator(param_1 + 0x17,0x2c,10,FUN_004d7750,FUN_004d7770);
  local_8._0_1_ = 1;
  eh_vector_constructor_iterator(param_1 + 0x85,0x2c,0x14,FUN_004d7750,FUN_004d7770);
  local_8._0_1_ = 2;
  eh_vector_constructor_iterator(param_1 + 0x161,0x2c,0x1e,FUN_004d7750,FUN_004d7770);
  puVar1 = param_1 + 0x2cb;
  param_1[0x2bf] = 0;
  *puVar1 = puVar1;
  param_1[0x2cc] = puVar1;
  local_8 = CONCAT31(local_8._1_3_,4);
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x16] = 0xffffffff;
  FUN_004da1a0();
  if ((DAT_00735718 == 3) && (DAT_006f88a4 == 4)) {
    _DAT_00746de0 = 0x3f800000;
  }
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xb64d16e6);
    }
  }
  param_1[0x2ef] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x6b20c153);
    }
  }
  param_1[0x2f0] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xf3bb2c9a);
    }
  }
  param_1[0x2f1] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0xf3bb2ca0);
    }
  }
  param_1[0x2f2] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x4603fd50);
    }
  }
  param_1[0x2f3] = iVar5;
  if (((param_1[3] == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(0x770c7ae9);
    }
  }
  param_1[0x2f4] = iVar5;
  uVar6 = FUN_004f65d0();
  param_1[0x2f5] = uVar6;
  iVar5 = FUN_004dbad0();
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x10) != 0)) {
    cVar4 = *(char *)(*(int *)(iVar5 + 0x10) + 0x11);
    bVar2 = true;
    if ((cVar4 == '\x02') && (cVar3 = IsLevel2PaintsOwned(), cVar3 == '\0')) {
      bVar2 = false;
    }
    if ((cVar4 == '\x03') && (cVar4 = IsLevel3PaintsOwned(), cVar4 == '\0')) {
      ExceptionList = local_10;
      return param_1;
    }
    if (bVar2) {
      GarageManager__PreviewPart();
    }
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4dae00 FUN_004dae00

void * __thiscall FUN_004dae00(void *param_1,byte param_2)

{
  FUN_004dae20(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4dae20 FUN_004dae20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dae20(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0068715c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3c14;
  local_4 = 4;
  DAT_00735e14 = 0;
  _DAT_00746de0 = 0x41a00000;
  FUN_004f6a10("MU_HorizontalBrowserBack.fng",1);
  _Memory = (int *)param_1[0x2cb];
  while (_Memory != param_1 + 0x2cb) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x2cb];
  }
  local_4._1_3_ = (uint3)((uint)local_4 >> 8);
  local_4._0_1_ = 2;
  eh_vector_destructor_iterator(param_1 + 0x161,0x2c,0x1e,FUN_004d7770);
  local_4._0_1_ = 1;
  eh_vector_destructor_iterator(param_1 + 0x85,0x2c,0x14,FUN_004d7770);
  local_4 = (uint)local_4._1_3_ << 8;
  eh_vector_destructor_iterator(param_1 + 0x17,0x2c,10,FUN_004d7770);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4daf10 FUN_004daf10

void FUN_004daf10(void)

{
  bool bVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = FUN_004dbad0();
  if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x10), iVar3 != 0)) {
    if (in_EAX == 0x65) {
      GarageManager__InstallPart(iVar3,0);
      *(undefined1 *)(unaff_ESI + 3000) = 1;
    }
    else if (in_EAX == 100) {
      bVar1 = true;
      if ((*(char *)(iVar3 + 0x11) == '\x02') && (cVar2 = IsLevel2PaintsOwned(), cVar2 == '\0')) {
        bVar1 = false;
      }
      if (((*(char *)(iVar3 + 0x11) != '\x03') || (cVar2 = IsLevel3PaintsOwned(), cVar2 != '\0')) &&
         (bVar1)) {
        GarageManager__PreviewPart();
        return;
      }
    }
  }
  return;
}


// ==== 0x4dafa0 FUN_004dafa0

void __thiscall FUN_004dafa0(int param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = param_1;
  if (0x911ab364 < param_2) {
    if (0xb5971bf1 < param_2) {
      if (param_2 < 0xc519bfc1) {
        return;
      }
      if (0xc519bfc2 < param_2) {
        if (param_2 != 0xc98356ba) {
          return;
        }
        if ((0.33 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0xafc)) * 0.00025) &&
           (*(char *)(param_1 + 0xb00) == '\0')) {
          FUN_004daf10();
          *(undefined1 *)(local_8 + 0xb00) = 1;
        }
        FUN_004dc3f0();
        iVar10 = local_8;
        if (*(int *)(local_8 + 0xb28) != *(int *)(local_8 + 0x58)) {
          uVar6 = FUN_004d7a30(&DAT_0074696c);
          FUN_00495f00(uVar6);
          iVar7 = *(int *)(iVar10 + 0xb28);
          if (((-1 < iVar7) && (iVar8 = FUN_00401bf0(), iVar7 < iVar8)) &&
             (iVar7 = FUN_004dc550(), iVar10 = local_8, iVar7 != 0)) {
            uVar6 = FUN_004d7af0(&DAT_0074696c);
            FUN_00495f00(uVar6);
            iVar10 = local_8;
          }
          *(undefined4 *)(iVar10 + 0x58) = *(undefined4 *)(iVar10 + 0xb28);
        }
        cVar5 = IsLevel2PaintsOwned();
        if (cVar5 == '\0') {
          FUN_00495fc0();
        }
        else {
          FUN_00495f70();
        }
        cVar5 = IsLevel3PaintsOwned();
        if (cVar5 == '\0') {
          FUN_00495fc0();
        }
        else {
          FUN_00495f70();
        }
        if (*(char *)(iVar10 + 0x54) == '\0') {
          return;
        }
        FUN_004dba50();
        return;
      }
      iVar10 = *(int *)(param_1 + 0xb34);
      if (*(int *)(param_1 + 0xb20) * iVar10 == 1) {
        return;
      }
      if (DAT_00735e14 != '\0') {
        return;
      }
      iVar7 = *(int *)(param_1 + 0xb28);
      DAT_00735e14 = 1;
      if (param_2 == 0xc519bfc1) {
        *(int *)(param_1 + 0xb28) = iVar7 + -1;
        if (iVar7 + -1 < 0) {
          *(int *)(param_1 + 0xb28) = iVar10 + -1;
        }
      }
      else {
        *(int *)(param_1 + 0xb28) = iVar7 + 1;
        if (iVar10 <= iVar7 + 1) {
          *(undefined4 *)(param_1 + 0xb28) = 0;
        }
      }
      puVar9 = *(undefined4 **)(param_1 + 0xb2c);
      iVar10 = 0;
      if (*(int *)(param_1 + 0xb28) != 0) {
        do {
          if (puVar9 == (undefined4 *)(param_1 + 0xb2c)) break;
          puVar9 = (undefined4 *)*puVar9;
          iVar10 = iVar10 + 1;
        } while (iVar10 != *(int *)(param_1 + 0xb28));
      }
      *(undefined4 *)
       (param_1 + 0xb78 + (*(int *)(param_1 + 0xb20) * iVar7 + *(int *)(param_1 + 0xb24)) * 4) =
           *(undefined4 *)(param_1 + 0xb0c);
      *(undefined4 *)
       (param_1 + 0xb38 + (*(int *)(param_1 + 0xb20) * iVar7 + *(int *)(param_1 + 0xb24)) * 4) =
           *(undefined4 *)(param_1 + 0xb10);
      iVar10 = *(int *)(param_1 + 0xb24) + *(int *)(param_1 + 0xb28) * *(int *)(param_1 + 0xb20);
      *(undefined4 *)(param_1 + 0xb0c) = *(undefined4 *)(param_1 + 0xb78 + iVar10 * 4);
      *(undefined4 *)(param_1 + 0xb10) = *(undefined4 *)(param_1 + 0xb38 + iVar10 * 4);
      FUN_004dbc70(param_1,*(undefined4 *)(param_1 + 0xb14),*(undefined4 *)(param_1 + 0xb18));
      FUN_004dbf90();
      *(undefined1 *)(param_1 + 0xb00) = 0;
      *(int *)(param_1 + 0xafc) = DAT_0073ad3c;
      FUN_004db8a0();
      DAT_00735e14 = 0;
      FUN_0051c770();
      return;
    }
    if (((param_2 != 0xb5971bf1) && (param_2 != 0x911c0a4b)) && (param_2 != 0x9120409e)) {
      return;
    }
LAB_004db5d2:
    FUN_004dc280(param_3);
    *(undefined1 *)(local_8 + 0xb00) = 0;
    *(int *)(local_8 + 0xafc) = DAT_0073ad3c;
    FUN_004db8a0();
    return;
  }
  if (param_2 == 0x911ab364) {
    iVar10 = *(int *)(param_1 + 0xb24) + -1;
    if (-1 < iVar10) {
      *(undefined4 *)
       (param_1 + 0xb78 +
       (*(int *)(param_1 + 0xb28) * *(int *)(param_1 + 0xb20) + *(int *)(param_1 + 0xb24)) * 4) =
           *(undefined4 *)(param_1 + 0xb0c);
      *(undefined4 *)
       (param_1 + 0xb38 +
       (*(int *)(param_1 + 0xb28) * *(int *)(param_1 + 0xb20) + *(int *)(param_1 + 0xb24)) * 4) =
           *(undefined4 *)(param_1 + 0xb10);
      iVar10 = *(int *)(param_1 + 0xb28) * *(int *)(param_1 + 0xb20) + iVar10;
      *(undefined4 *)(param_1 + 0xb0c) = *(undefined4 *)(param_1 + 0xb78 + iVar10 * 4);
      *(undefined4 *)(param_1 + 0xb10) = *(undefined4 *)(param_1 + 0xb38 + iVar10 * 4);
      *(int *)(param_1 + 0xb24) = *(int *)(param_1 + 0xb24) + -1;
      FUN_004dbf90();
      *(undefined1 *)(param_1 + 0xb00) = 0;
      *(int *)(param_1 + 0xafc) = DAT_0073ad3c;
      FUN_004db8a0();
      return;
    }
    GarageManager__SyncActualToEditing(0);
    FUN_004dba50();
    return;
  }
  if (0x565ae191 < param_2) {
    if (param_2 != 0x72619778) {
      if (param_2 != 0x80154340) {
        return;
      }
      if (*(int *)(param_1 + 0xb1c) != 6) {
        return;
      }
      *(int *)(param_1 + 0xb18) = *(int *)(param_1 + 0xb18) + -1;
      return;
    }
    goto LAB_004db5d2;
  }
  if (param_2 == 0x565ae191) {
    if ((*(int *)(param_1 + 0xb1c) == 6) && (DAT_00735ddc == 3)) {
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x40),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x44),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x48),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x4c),0);
      iVar10 = *(int *)(param_1 + 0xb24) + 1;
      *(int *)(param_1 + 0xb24) = iVar10;
      if (iVar10 < *(int *)(param_1 + 0xb20)) {
        uVar6 = FUN_004d7a30(&DAT_0074696c);
        FUN_00495f00(uVar6);
        return;
      }
      *(undefined1 *)(param_1 + 0x54) = 1;
      return;
    }
    FUN_004daf10();
    *(undefined1 *)(local_8 + 0x54) = 1;
    return;
  }
  if (param_2 != 0xc407210) {
    if (param_2 == 0x12345678) {
      if ((*(int *)(param_1 + 0xb1c) == 6) && (DAT_00735ddc == 3)) {
        GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x40),1);
        GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x44),1);
        GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x48),1);
        GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x4c),0);
      }
      else {
        FUN_004daf10();
      }
      iVar10 = FUN_004f65d0();
      if (iVar10 != 0) {
        *(undefined4 *)(iVar10 + 0x1c) = 0xff;
      }
      FUN_004dba50();
      return;
    }
    if (param_2 != 0x1c4c008a) {
      return;
    }
    if ((*(int *)(param_1 + 0xb1c) == 6) && (DAT_00735ddc == 3)) {
      FUN_004d8420();
      FUN_004d8420();
      FUN_004d8420();
      FUN_004d8420();
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x40),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x44),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x48),1);
      GarageManager__InstallPart(*(undefined4 *)(param_1 + 0x4c),0);
      iVar10 = *(int *)(param_1 + 0xb24) + 1;
      *(int *)(param_1 + 0xb24) = iVar10;
      if (iVar10 < *(int *)(param_1 + 0xb20)) {
        uVar6 = FUN_004d7a30(&DAT_0074696c);
        FUN_00495f00(uVar6);
      }
    }
    else {
      FUN_004dbad0();
      FUN_004d8420();
      FUN_004daf10();
      param_1 = local_8;
    }
    FUN_004d8500(param_1);
    FUN_004d8600(param_1);
    FUN_004dbf90();
    return;
  }
  iVar10 = *(int *)(param_1 + 0xb24);
  iVar7 = FUN_004dbad0();
  if (iVar10 + 1 < *(int *)(param_1 + 0xb20)) {
    *(undefined4 *)(param_1 + 0x40 + iVar10 * 4) = *(undefined4 *)(iVar7 + 0x10);
    FUN_004daf10();
    iVar8 = local_8;
    *(undefined4 *)
     (local_8 + 0xb78 +
     (*(int *)(local_8 + 0xb28) * *(int *)(local_8 + 0xb20) + *(int *)(local_8 + 0xb24)) * 4) =
         *(undefined4 *)(local_8 + 0xb0c);
    *(undefined4 *)
     (local_8 + 0xb38 +
     (*(int *)(local_8 + 0xb28) * *(int *)(local_8 + 0xb20) + *(int *)(local_8 + 0xb24)) * 4) =
         *(undefined4 *)(local_8 + 0xb10);
    iVar10 = *(int *)(local_8 + 0xb28) * *(int *)(local_8 + 0xb20) + iVar10 + 1;
    *(undefined4 *)(local_8 + 0xb0c) = *(undefined4 *)(local_8 + 0xb78 + iVar10 * 4);
    *(undefined4 *)(local_8 + 0xb10) = *(undefined4 *)(local_8 + 0xb38 + iVar10 * 4);
    FUN_004dbf90();
    *(undefined1 *)(iVar8 + 0xb00) = 0;
    *(int *)(iVar8 + 0xafc) = DAT_0073ad3c;
    FUN_004db8a0();
    if ((DAT_00735718 == 5) && (DAT_00735ddc == 3)) {
      iVar10 = *(int *)(iVar8 + 0xb18) + 1;
      *(int *)(iVar8 + 0xb18) = iVar10;
      FUN_004dbc70(iVar8,*(undefined4 *)(iVar8 + 0xb14),iVar10);
    }
    FUN_004dc3a0();
    FUN_004dbf90();
    param_1 = local_8;
  }
  else {
    *(undefined4 *)(param_1 + 0x40 + iVar10 * 4) = *(undefined4 *)(iVar7 + 0x10);
    if ((DAT_00735718 == 5) && (DAT_00735ddc == 3)) {
      *(int *)(param_1 + 0xb18) = *(int *)(param_1 + 0xb18) + 1;
    }
  }
  cVar4 = DAT_00735e12;
  cVar5 = *(char *)(*(int *)(iVar7 + 0x10) + 0x11);
  if ((DAT_00735e12 == '\0') && (cVar3 = FUN_004d7fe0(), cVar3 == '\0')) {
    bVar2 = false;
LAB_004db2f2:
    cVar4 = FUN_004d8370();
    if ((cVar4 == '\0') && (DAT_00745e40 == 1)) {
      bVar1 = true;
      goto LAB_004db30a;
    }
  }
  else {
    bVar2 = true;
    if (cVar4 == '\0') goto LAB_004db2f2;
  }
  bVar1 = false;
LAB_004db30a:
  if (bVar2) {
    local_10 = 0;
    local_c = 0;
    local_1c = 0x80154340;
    local_18 = 0x80154340;
    local_2c = 0x1a99a17f;
    local_24 = 0x565ae191;
    local_28 = 0x639;
    local_20 = 0x541389e5;
    local_14 = 0xb8a7c6cc;
    FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  if (!bVar1) {
    return;
  }
  local_10 = 0;
  local_c = 0;
  local_2c = 0x39223856;
  if (cVar5 == '\x02') {
    local_2c = 0x8b02a985;
  }
  else if (cVar5 == '\x03') {
    local_2c = 0x77447e66;
  }
  local_1c = 0x80154340;
  local_18 = 0x80154340;
  local_24 = 0x1c4c008a;
  local_28 = 0x639;
  local_20 = 0x541389e5;
  local_14 = 0xb8a7c6cc;
  FUN_004dc6e0(&local_2c,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4db496 FUN_004db496

void FUN_004db496(void)

{
  int unaff_EBP;
  
  FUN_004daf10();
  *(undefined1 *)(*(int *)(unaff_EBP + -4) + 0x54) = 1;
  return;
}


// ==== 0x4db8a0 FUN_004db8a0

void FUN_004db8a0(void)

{
  byte *pbVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  int unaff_EBX;
  undefined *puVar9;
  
  iVar4 = FUN_004dbad0();
  puVar9 = &DAT_006c7a38;
  iVar7 = -1;
  uVar5 = 0x52;
  do {
    iVar7 = iVar7 * 0x21 + uVar5;
    pbVar1 = puVar9 + 1;
    uVar5 = (uint)*pbVar1;
    puVar9 = puVar9 + 1;
  } while (*pbVar1 != 0);
  piVar6 = *(int **)(*(int *)(iVar4 + 0x10) + 0x14);
  iVar4 = (int)*(short *)(*(int *)(iVar4 + 0x10) + 0x1c);
  piVar2 = piVar6;
  if (piVar6 != (int *)0x0) {
    for (; ((piVar2 < piVar6 + iVar4 * 2 && (iVar7 != 0)) && (*piVar2 != iVar7));
        piVar2 = piVar2 + 2) {
    }
  }
  pcVar8 = "GREEN";
  iVar7 = -1;
  uVar5 = 0x47;
  do {
    iVar7 = iVar7 * 0x21 + uVar5;
    pbVar1 = (byte *)(pcVar8 + 1);
    uVar5 = (uint)*pbVar1;
    pcVar8 = pcVar8 + 1;
  } while (*pbVar1 != 0);
  piVar2 = piVar6;
  if (piVar6 != (int *)0x0) {
    for (; ((piVar2 < piVar6 + iVar4 * 2 && (iVar7 != 0)) && (*piVar2 != iVar7));
        piVar2 = piVar2 + 2) {
    }
  }
  puVar9 = &DAT_006c7a28;
  iVar7 = -1;
  uVar5 = 0x42;
  do {
    iVar7 = iVar7 * 0x21 + uVar5;
    pbVar1 = puVar9 + 1;
    uVar5 = (uint)*pbVar1;
    puVar9 = puVar9 + 1;
  } while (*pbVar1 != 0);
  piVar2 = piVar6 + iVar4 * 2;
  if (piVar6 != (int *)0x0) {
    for (; ((piVar6 < piVar2 && (iVar7 != 0)) && (*piVar6 != iVar7)); piVar6 = piVar6 + 2) {
    }
  }
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004ef050(0x3a26931c);
    }
  }
  FEObject__SetInvisible(iVar4);
  iVar4 = *(int *)(unaff_EBX + 0xaf8);
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) < 0x100)) {
    cVar3 = FEColor_NearlyEqual();
    if (cVar3 == '\0') {
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    }
    FUN_004ff2f0(iVar4,0,0);
  }
  return;
}


// ==== 0x4dba50 FUN_004dba50

undefined4 FUN_004dba50(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(in_EAX + 0xc);
  if (*(int *)(in_EAX + 0xb1c) == 6) {
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      uVar3 = 0;
      if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
        return uVar3;
      }
    }
  }
  else if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return uVar3;
}


// ==== 0x4dbad0 FUN_004dbad0

int __fastcall FUN_004dbad0(int param_1,undefined4 param_2)

{
  int in_EAX;
  
  switch(param_2) {
  case 0:
    return in_EAX * 0x2c + 0x5c + param_1;
  case 1:
    return in_EAX * 0x2c + 0x214 + param_1;
  case 2:
    return in_EAX * 0x2c + 0x3cc + param_1;
  case 3:
    return in_EAX * 0x2c + 0x584 + param_1;
  case 4:
    return in_EAX * 0x2c + 0x73c + param_1;
  case 5:
    return in_EAX * 0x2c + 0x8f4 + param_1;
  default:
    return 0;
  }
}


// ==== 0x4dbb40 FUN_004dbb40

int FUN_004dbb40(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  iVar1 = in_EAX + 0x5c;
  while (((iVar1 == 0 || (*(int *)(iVar1 + 0x10) == 0)) ||
         (*(int *)(*(int *)(iVar1 + 0x10) + 8) != unaff_EDI))) {
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x2c;
    if (9 < iVar2) {
      iVar2 = 0;
      iVar1 = in_EAX + 0x214;
      while (((iVar1 == 0 || (*(int *)(iVar1 + 0x10) == 0)) ||
             (*(int *)(*(int *)(iVar1 + 0x10) + 8) != unaff_EDI))) {
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x2c;
        if (0x13 < iVar2) {
          iVar2 = 0;
          iVar1 = in_EAX + 0x584;
          while (((iVar1 == 0 || (*(int *)(iVar1 + 0x10) == 0)) ||
                 (*(int *)(*(int *)(iVar1 + 0x10) + 8) != unaff_EDI))) {
            iVar2 = iVar2 + 1;
            iVar1 = iVar1 + 0x2c;
            if (0x1d < iVar2) {
              return 0;
            }
          }
          return iVar1;
        }
      }
      return iVar1;
    }
  }
  return iVar1;
}


// ==== 0x4dbbb0 FUN_004dbbb0

void FUN_004dbbb0(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)*in_EAX;
  iVar3 = 0;
  puVar1 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar1) {
      return;
    }
    ColorElement__SetPart();
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  return;
}


// ==== 0x4dbbf0 FUN_004dbbf0

void FUN_004dbbf0(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)*in_EAX;
  iVar3 = 0;
  puVar1 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar1) {
      return;
    }
    ColorElement__SetPart();
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  return;
}


// ==== 0x4dbc30 FUN_004dbc30

void FUN_004dbc30(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)*in_EAX;
  iVar3 = 0;
  puVar1 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar1) {
      return;
    }
    ColorElement__SetPart();
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1e);
  return;
}


// ==== 0x4dbc70 FUN_004dbc70

void FUN_004dbc70(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int ******ppppppiVar4;
  int ******ppppppiVar5;
  int *****pppppiVar6;
  int *****pppppiVar7;
  int *piVar8;
  int iVar9;
  int *****local_30;
  int *****local_2c;
  int *****local_28;
  int *****local_24;
  int *****local_20;
  int *****local_1c;
  void *local_14;
  code *pcStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  pcStack_10 = FUN_00687be8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_004d9e40(param_1);
  *(undefined4 *)(param_1 + 0xb14) = param_2;
  *(undefined4 *)(param_1 + 0xb18) = param_3;
  piVar8 = *(int **)(param_1 + 0xb2c);
  iVar9 = 0;
  piVar2 = (int *)NullUpdate_ret();
  if (piVar8 != piVar2) {
    do {
      if (*(int *)(param_1 + 0xb28) == iVar9) goto LAB_004dbcd2;
      piVar8 = (int *)*piVar8;
      iVar9 = iVar9 + 1;
    } while (piVar8 != piVar2);
  }
  piVar8 = (int *)0x0;
LAB_004dbcd2:
  iVar9 = ColorPicker__GetHighestUpgradeLevel(param_1);
  local_28 = (int *****)&local_28;
  local_24 = (int *****)&local_28;
  local_20 = (int *****)&local_20;
  local_1c = (int *****)&local_20;
  local_30 = (int *****)&local_30;
  local_2c = (int *****)&local_30;
  local_c = 2;
  if (iVar9 == 2) {
    if (piVar8 != (int *)0x0) {
      FUN_004d7db0(&DAT_0074696c,piVar8[2],1);
      FUN_004d7db0(&DAT_0074696c,piVar8[2],2);
    }
    FUN_004dbbb0(param_1);
    FUN_004dbbf0(param_1);
  }
  else if (iVar9 == 3) {
    if (piVar8 != (int *)0x0) {
      FUN_004d7db0(&DAT_0074696c,piVar8[2],1);
      FUN_004d7db0(&DAT_0074696c,piVar8[2],2);
      iVar9 = piVar8[2];
      if ((int ******)local_30 != &local_30) {
        do {
          pppppiVar7 = (int *****)*local_30;
          pppppiVar6 = (int *****)local_30[1];
          *pppppiVar6 = (int ****)pppppiVar7;
          pppppiVar7[1] = (int ****)pppppiVar6;
          _free(local_30);
        } while ((int ******)local_30 != &local_30);
      }
      ppppppiVar5 = (int ******)local_30;
      puVar1 = DAT_0073ad40;
      puVar3 = (undefined4 *)NullUpdate_ret();
      for (; puVar1 != puVar3; puVar1 = (undefined4 *)*puVar1) {
        pppppiVar7 = (int *****)puVar1[3];
        pppppiVar6 = pppppiVar7 + puVar1[4] * 0xc;
        for (; pppppiVar7 < pppppiVar6; pppppiVar7 = pppppiVar7 + 0xc) {
          if (*(char *)(pppppiVar7 + 4) == '\x1e') goto joined_r0x004dbdf0;
        }
      }
      pppppiVar7 = (int *****)0x0;
joined_r0x004dbdf0:
      for (; pppppiVar7 != (int *****)0x0;
          pppppiVar7 = (int *****)CarPartDatabase__GetCarPart(0,0x1e,0,pppppiVar7,0xffffffff)) {
        if ((pppppiVar7[3] == *(int *****)(&DAT_00746974 + iVar9 * 8)) &&
           (*(char *)((int)pppppiVar7 + 0x11) == '\x03')) {
          ppppppiVar4 = _malloc(0xc);
          if (ppppppiVar4 == (int ******)0x0) {
            ppppppiVar4 = (int ******)0x0;
          }
          else {
            ppppppiVar4[2] = (int *****)0x0;
          }
          ppppppiVar4[2] = pppppiVar7;
          *local_2c = (int ****)ppppppiVar4;
          ppppppiVar4[1] = local_2c;
          *ppppppiVar4 = (int *****)&local_30;
          ppppppiVar5 = (int ******)local_30;
          local_2c = (int *****)ppppppiVar4;
        }
      }
      if (ppppppiVar5 != &local_30) {
        do {
          if (ppppppiVar5 == (int ******)0x0) break;
          ppppppiVar5 = (int ******)*ppppppiVar5;
        } while (ppppppiVar5 != &local_30);
      }
    }
    FUN_004dbbb0(param_1);
    FUN_004dbbf0(param_1);
    FUN_004dbc30(param_1);
  }
  else {
    if (piVar8 != (int *)0x0) {
      FUN_004d7db0(&DAT_0074696c,piVar8[2],1);
    }
    FUN_004dbbb0(param_1);
  }
  FUN_004d8500(param_1);
  FUN_004d8600(param_1);
  if ((int ******)local_30 != &local_30) {
    do {
      pppppiVar7 = (int *****)*local_30;
      pppppiVar6 = (int *****)local_30[1];
      *pppppiVar6 = (int ****)pppppiVar7;
      pppppiVar7[1] = (int ****)pppppiVar6;
      _free(local_30);
    } while ((int ******)local_30 != &local_30);
  }
  if ((int ******)local_20 != &local_20) {
    do {
      pppppiVar7 = (int *****)*local_20;
      pppppiVar6 = (int *****)local_20[1];
      *pppppiVar6 = (int ****)pppppiVar7;
      pppppiVar7[1] = (int ****)pppppiVar6;
      _free(local_20);
    } while ((int ******)local_20 != &local_20);
  }
  if ((int ******)local_28 != &local_28) {
    do {
      pppppiVar7 = (int *****)*local_28;
      pppppiVar6 = (int *****)local_28[1];
      *pppppiVar6 = (int ****)pppppiVar7;
      pppppiVar7[1] = (int ****)pppppiVar6;
      _free(local_28);
    } while ((int ******)local_28 != &local_28);
  }
  ExceptionList = local_14;
  return;
}


// ==== 0x4dbf90 FUN_004dbf90

void FUN_004dbf90(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = FUN_004dbad0();
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) && (*(int *)(unaff_EBX + 0xaf4) != 0)) {
    FUN_004f7260(&local_14,&local_18);
    FUN_004f7140(local_14,local_18);
    local_10 = *(undefined4 *)(iVar2 + 0x14);
    local_c = *(undefined4 *)(iVar2 + 0x18);
    local_8 = *(undefined4 *)(iVar2 + 0x1c);
    local_4 = *(undefined4 *)(iVar2 + 0x20);
    local_8 = _ftol_nocw();
    local_c = _ftol_nocw();
    local_10 = _ftol_nocw();
    FUN_004f7620();
    switch(*(undefined4 *)(iVar2 + 0x24)) {
    case 0:
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      return;
    case 1:
    case 2:
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      cVar1 = IsLevel2PaintsOwned();
      if ((cVar1 == '\0') && (DAT_00735e12 == '\0')) {
        FUN_00495fc0();
        FUN_00495fc0();
        uVar3 = GetCarPartCost();
        FUN_004f6850(&DAT_006ca778,uVar3);
        return;
      }
      FUN_00495f70();
      FUN_00495f70();
      return;
    case 3:
    case 4:
    case 5:
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      FUN_00495f70();
      cVar1 = IsLevel3PaintsOwned();
      if ((cVar1 == '\0') && (DAT_00735e12 == '\0')) {
        FUN_00495fc0();
        FUN_00495fc0();
        uVar3 = GetCarPartCost();
        FUN_004f6850(&DAT_006ca778,uVar3);
        return;
      }
      FUN_00495f70();
      FUN_00495f70();
    }
  }
  return;
}


// ==== 0x4dc230 FUN_004dc230

void FUN_004dc230(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xb0c) < 0) {
    *(undefined4 *)(in_EAX + 0xb0c) = 0;
  }
  if (*(int *)(in_EAX + 0xb04) <= *(int *)(in_EAX + 0xb0c)) {
    *(int *)(in_EAX + 0xb0c) = *(int *)(in_EAX + 0xb04) + -1;
  }
  if (*(int *)(in_EAX + 0xb10) < 0) {
    *(undefined4 *)(in_EAX + 0xb10) = 0;
  }
  if (*(int *)(in_EAX + 0xb08) <= *(int *)(in_EAX + 0xb10)) {
    *(int *)(in_EAX + 0xb10) = *(int *)(in_EAX + 0xb08) + -1;
  }
  return;
}


// ==== 0x4dc280 FUN_004dc280

void FUN_004dc280(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  uint unaff_EDI;
  undefined8 uVar6;
  
  iVar1 = *(int *)(unaff_ESI + 0xb0c);
  iVar2 = *(int *)(unaff_ESI + 0xb10);
  bVar3 = false;
  if (unaff_EDI < 0x9120409f) {
    if (unaff_EDI == 0x9120409e) {
      iVar4 = iVar2 + -1;
LAB_004dc2d4:
      *(int *)(unaff_ESI + 0xb10) = iVar4;
    }
    else if (unaff_EDI == 0x72619778) {
      *(int *)(unaff_ESI + 0xb0c) = iVar1 + -1;
    }
    else {
      if (unaff_EDI != 0x911c0a4b) goto LAB_004dc2df;
      *(int *)(unaff_ESI + 0xb0c) = iVar1 + 1;
    }
    bVar3 = true;
  }
  else if (unaff_EDI == 0xb5971bf1) {
    iVar4 = iVar2 + 1;
    goto LAB_004dc2d4;
  }
LAB_004dc2df:
  FUN_004dc230();
  iVar4 = *(int *)(unaff_ESI + 0xb10);
  uVar6 = FUN_004dbad0();
  iVar5 = (int)((ulonglong)uVar6 >> 0x20);
  if (((int)uVar6 != 0) && (*(int *)((int)uVar6 + 0x10) != 0)) goto LAB_004dc37e;
  if (unaff_EDI < 0x9120409f) {
    if (unaff_EDI == 0x9120409e) {
      iVar4 = iVar4 + -1;
LAB_004dc33f:
      *(int *)(unaff_ESI + 0xb10) = iVar4;
    }
    else if (unaff_EDI == 0x72619778) {
      *(int *)(unaff_ESI + 0xb0c) = iVar5 + -1;
    }
    else if (unaff_EDI == 0x911c0a4b) {
      *(int *)(unaff_ESI + 0xb0c) = iVar5 + 1;
    }
  }
  else if (unaff_EDI == 0xb5971bf1) {
    iVar4 = iVar4 + 1;
    goto LAB_004dc33f;
  }
  FUN_004dc230();
  iVar4 = FUN_004dbad0();
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x10) == 0)) {
    *(int *)(unaff_ESI + 0xb0c) = iVar1;
    *(int *)(unaff_ESI + 0xb10) = iVar2;
  }
LAB_004dc37e:
  if (bVar3) {
    FUN_004dbf90();
  }
  return;
}


// ==== 0x4dc3a0 FUN_004dc3a0

void FUN_004dc3a0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if ((&DAT_00745b6c)[*(int *)(unaff_ESI + 0xb18)] != 0) {
    iVar1 = FUN_004dbb40();
    if (iVar1 != 0) {
      *(undefined4 *)(unaff_ESI + 0xb0c) = *(undefined4 *)(iVar1 + 0x24);
      *(undefined4 *)(unaff_ESI + 0xb10) = *(undefined4 *)(iVar1 + 0x28);
      return;
    }
  }
  *(undefined4 *)(unaff_ESI + 0xb10) = 0;
  *(undefined4 *)(unaff_ESI + 0xb0c) = 0;
  return;
}


// ==== 0x4dc3f0 FUN_004dc3f0

void FUN_004dc3f0(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_ESI;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  piVar6 = (int *)(unaff_ESI + 0xbbc);
  iVar5 = 6;
  do {
    if ((*piVar6 != 0) && (DAT_007064b2 != '\0')) {
      cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar2 != '\0') {
        uVar1 = *(uint *)(*piVar6 + 0x10);
        if (uVar1 < 0xb64d16e7) {
          if (uVar1 == 0xb64d16e6) {
            iVar3 = FEPackageList__FindByName(&DAT_00746104);
            if (((iVar3 != 0) && (iVar8 = *(int *)(iVar3 + 0x18), iVar8 != 0)) &&
               (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
              uVar7 = 0x911c0a4b;
LAB_004dc532:
              (**(code **)(*piVar4 + 8))(uVar7,0,0,iVar8);
            }
          }
          else if (uVar1 == 0x4603fd50) {
            FUN_004c96c0(0xc519bfc2);
          }
          else if (uVar1 == 0x6b20c153) {
            FUN_004c96c0(0x72619778);
          }
          else if (uVar1 == 0x770c7ae9) {
            FUN_004c96c0(0xc519bfc1);
          }
        }
        else if (uVar1 == 0xf3bb2c9a) {
          iVar3 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar3 != 0) && (iVar8 = *(int *)(iVar3 + 0x18), iVar8 != 0)) &&
             (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
            uVar7 = 0x9120409e;
            goto LAB_004dc532;
          }
        }
        else if (uVar1 == 0xf3bb2ca0) {
          FUN_004c96c0(0xb5971bf1);
        }
      }
    }
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4dc550 FUN_004dc550

undefined4 * FUN_004dc550(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EBX;
  int iVar3;
  
  puVar1 = (undefined4 *)*in_EAX;
  iVar3 = 0;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return (undefined4 *)0x0;
    }
    if (unaff_EBX == iVar3) break;
    puVar1 = (undefined4 *)*puVar1;
    iVar3 = iVar3 + 1;
  }
  return puVar1;
}


// ==== 0x4dc580 FUN_004dc580

void FUN_004dc580(void)

{
  int iVar1;
  undefined4 in_EAX;
  undefined4 *unaff_ESI;
  bool bVar2;
  
  FEScreen__FEScreen(unaff_ESI,in_EAX);
  *unaff_ESI = &PTR_FUN_006c3be0;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x10] = DAT_0073ad3c;
  iVar1 = DAT_0073578c;
  bVar2 = DAT_0073578c != 0;
  unaff_ESI[0x11] = 0;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  if (bVar2) {
    *(undefined4 *)(*(int *)(iVar1 + 8) + 0xd0) = 0;
  }
  unaff_ESI[0x1b] = 0;
  return;
}


// ==== 0x4dc5e0 FUN_004dc5e0

void * __thiscall FUN_004dc5e0(void *param_1,byte param_2)

{
  FUN_004dc600();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4dc600 FUN_004dc600

void __fastcall FUN_004dc600(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3be0;
  local_4 = 0;
  if (param_1[0x11] != 0) {
    FUN_00565ce0();
  }
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  if (DAT_0073578c != 0) {
    *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xd0) = 2;
  }
  FEScreenRegistry__SetFactory(param_1[3],0);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4dc690 FUN_004dc690

void FUN_004dc690(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687bc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x74);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004dc580();
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4dc6e0 FUN_004dc6e0

int FUN_004dc6e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FEScreenRegistry__SetFactory(param_2,FUN_004dc690);
  iVar2 = FUN_004f65d0();
  iVar4 = *(int *)(iVar2 + 0x18);
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar3 = iVar1 + 0xdc;
    if (iVar3 != 0) {
      iVar3 = FUN_004fd1e0(iVar3);
      if (iVar3 != 0) goto LAB_004dc73f;
    }
    cFEng__PushPackage(iVar1,param_2,iVar4 + 1,0xff);
  }
LAB_004dc73f:
  iVar4 = FUN_004f65d0();
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x1c) = 0;
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x14);
    if (iVar4 != 0) {
      FUN_004dc7c0();
    }
  }
  if (DAT_006f8aa8 != 0xc) {
    uVar5 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar5) == 0xc) break;
      uVar5 = uVar5 + 8;
    } while (uVar5 < 0x70);
  }
  DAT_00735e0c = iVar2;
  FUN_004cd180(0);
  return iVar4;
}


// ==== 0x4dc7c0 FUN_004dc7c0

void __fastcall FUN_004dc7c0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  
  *(undefined4 *)(unaff_EBX + 0x4c) = in_EAX;
  puVar2 = (undefined4 *)(unaff_EBX + 0x50);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(unaff_EBX + 0x44) == 0) {
    FUN_00495f00(*(undefined4 *)(unaff_EBX + 0x50));
  }
  else {
    FUN_004f6850(*(int *)(unaff_EBX + 0x44));
  }
  FUN_00495f00(*(undefined4 *)(unaff_EBX + 0x54));
  FUN_00495f00(*(undefined4 *)(unaff_EBX + 0x5c));
  if (DAT_0073578c != 0) {
    FUN_004f5ed0(DAT_0073578c);
  }
  return;
}


// ==== 0x4dc840 FUN_004dc840

void __thiscall FUN_004dc840(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x40) != DAT_0073ad3c) {
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        if (*(int *)(param_1 + 100) != 0) {
          FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
          FUN_004c96c0(*(undefined4 *)(param_1 + 100));
          FUN_004c96c0(0x7f6c5142);
          FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
      else if (param_2 == 0xc407210) {
        if (*(int *)(param_3 + 0x10) == -0x47583934) {
          FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
          FUN_004c96c0(*(undefined4 *)(param_1 + 0x58));
          FUN_004c96c0(*(undefined4 *)(param_1 + 0x58));
          FUN_004c96c0(0x7f6c5142);
          FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (*(int *)(param_3 + 0x10) == -0x47583933) {
          FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
          FUN_004c96c0(*(undefined4 *)(param_1 + 0x60));
          *(undefined4 *)(param_1 + 0x6c) = 1;
          FUN_004c96c0(*(undefined4 *)(param_1 + 0x60));
          FUN_004c96c0(0x7f6c5142);
          FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
          return;
        }
      }
      else if ((param_2 == 0x35f8620b) &&
              (iVar1 = FUN_004f64d0(*(undefined4 *)(param_1 + 0xc)), param_3 == iVar1)) {
        FEObject__SetScript("Highlight",1);
        if (*(int *)(param_3 + 0x10) == -0x47583934) {
          FUN_004f6c30("UnHighlight",1);
          return;
        }
        if (*(int *)(param_3 + 0x10) == -0x47583933) {
          FUN_004f6c30("UnHighlight",1);
          return;
        }
      }
    }
    else if ((param_2 == 0xc98356ba) && (*(int *)(param_1 + 0x70) != 0)) {
      if (DAT_007361b4 == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = *(int *)(DAT_007361b4 + 8);
      }
      if ((&DAT_007306c4)[iVar1] != -1) {
        if (DAT_007361b8 == 0) {
          iVar1 = -1;
        }
        else {
          iVar1 = *(int *)(DAT_007361b8 + 8);
        }
        if ((&DAT_007306c4)[iVar1] != -1) {
          return;
        }
      }
      FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
      FUN_004c96c0(*(undefined4 *)(param_1 + 0x58));
    }
  }
  return;
}


// ==== 0x4dca50 FUN_004dca50

undefined4 FUN_004dca50(int param_1,int param_2)

{
  if (param_1 == -0x6edfbf62) {
    if (*(int *)(param_2 + 0x10) == -0x47583933) {
      return 1;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (*(int *)(param_2 + 0x10) == -0x47583934)) {
    return 2;
  }
  return 0;
}


// ==== 0x4dcaa0 FUN_004dcaa0

void * __thiscall FUN_004dcaa0(void *param_1,byte param_2)

{
  FUN_004dcac0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4dcac0 FUN_004dcac0

void __fastcall FUN_004dcac0(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3bc4;
  local_4 = 0;
  if (param_1[0x11] != 0) {
    FUN_00565ce0();
  }
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  if (DAT_0073578c != 0) {
    *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xd0) = 2;
  }
  FEScreenRegistry__SetFactory(param_1[3],0);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4dcb50 FUN_004dcb50

undefined4 * FUN_004dcb50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687ba3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = _malloc(0x60);
  local_4 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar2,param_1);
    iVar1 = DAT_0073578c;
    bVar3 = DAT_0073578c != 0;
    *puVar2 = &PTR_FUN_006c3bc4;
    puVar2[0x10] = 0;
    puVar2[0x10] = DAT_0073ad3c;
    puVar2[0x11] = 0;
    *(undefined1 *)(puVar2 + 0x12) = 0;
    if (bVar3) {
      *(undefined4 *)(*(int *)(iVar1 + 8) + 0xd0) = 0;
    }
    ExceptionList = local_c;
    return puVar2;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x4dcbe0 FUN_004dcbe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004dcbe0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FEScreenRegistry__SetFactory(param_2,FUN_004dcb50);
  iVar2 = FUN_004f65d0();
  iVar4 = *(int *)(iVar2 + 0x18);
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar3 = iVar1 + 0xdc;
    if ((iVar3 == 0) || (iVar3 = FUN_004fd1e0(iVar3), iVar3 == 0)) {
      cFEng__PushPackage(iVar1,param_2,iVar4 + 1,0xff);
    }
  }
  iVar4 = FUN_004f65d0();
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x1c) = 0;
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x14);
    if (iVar4 != 0) {
      FUN_004dcd30();
    }
  }
  if (DAT_006f8aa8 != 0xc) {
    uVar5 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar5) == 0xc) break;
      uVar5 = uVar5 + 8;
    } while (uVar5 < 0x70);
  }
  _DAT_00735e08 = iVar2;
  FUN_004cd180(0);
  return iVar4;
}


// ==== 0x4dccc0 FUN_004dccc0

void FUN_004dccc0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int unaff_EBX;
  
  if (*(int *)(unaff_EBX + 0x44) == 0) {
    uVar2 = FUN_00565b60(0x100,0,0,0);
    *(undefined4 *)(unaff_EBX + 0x44) = uVar2;
  }
  pcVar3 = *(char **)(unaff_EBX + 0x44);
  iVar4 = 0x100;
  param_1 = param_1 - (int)pcVar3;
  do {
    cVar1 = pcVar3[param_1];
    iVar4 = iVar4 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar4 != 0);
  if (*(int *)(unaff_EBX + 0x44) == 0) {
    FUN_00495f00(*(undefined4 *)(unaff_EBX + 0x50));
    return;
  }
  FUN_004f6850(*(int *)(unaff_EBX + 0x44));
  return;
}


// ==== 0x4dcd30 FUN_004dcd30

void __fastcall FUN_004dcd30(undefined4 param_1)

{
  undefined4 *in_EAX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x4c) = param_1;
  *(undefined4 *)(unaff_ESI + 0x50) = *in_EAX;
  *(undefined4 *)(unaff_ESI + 0x54) = in_EAX[1];
  *(undefined4 *)(unaff_ESI + 0x58) = in_EAX[2];
  *(undefined4 *)(unaff_ESI + 0x5c) = in_EAX[3];
  if (*(int *)(unaff_ESI + 0x44) == 0) {
    FUN_00495f00(*(undefined4 *)(unaff_ESI + 0x50));
  }
  else {
    FUN_004f6850(*(int *)(unaff_ESI + 0x44));
  }
  FUN_00495f00(*(undefined4 *)(unaff_ESI + 0x54));
  if (DAT_0073578c != 0) {
    FUN_004f5ed0(DAT_0073578c);
  }
  return;
}


// ==== 0x4dcdb0 FUN_004dcdb0

void __thiscall FUN_004dcdb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x40) != DAT_0073ad3c) {
    if (param_2 == 0xc407210) {
      if (*(int *)(param_3 + 0x10) == -0x47583934) {
        FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
        FUN_004c96c0(*(undefined4 *)(param_1 + 0x58));
        FUN_004c96c0(*(undefined4 *)(param_1 + 0x58));
        FUN_004c96c0(0x7f6c5142);
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      }
    }
    else if (param_2 == 0x35f8620b) {
      iVar1 = FUN_004f64d0(*(undefined4 *)(param_1 + 0xc));
      if (param_3 == iVar1) {
        FEObject__SetScript("Highlight",1);
        return;
      }
    }
    else if (param_2 == -0x6ee54c9c) {
      FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
      FUN_004c96c0(*(undefined4 *)(param_1 + 0x5c));
      FUN_004c96c0(0x7f6c5142);
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  return;
}


// ==== 0x4dcea0 FUN_004dcea0

void FUN_004dcea0(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  FEScreen__FEScreen(unaff_ESI,in_EAX);
  *unaff_ESI = &PTR_FUN_006c3ba8;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x14] = 0;
  puVar2 = unaff_ESI + 0x15;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  unaff_ESI[0x1d] = 1;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = 0;
  *(undefined1 *)(unaff_ESI + 0x21) = 0;
  unaff_ESI[0x10] = DAT_0073ad3c;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  unaff_ESI[0x11] = 0;
  return;
}


// ==== 0x4dcef0 FUN_004dcef0

void * __thiscall FUN_004dcef0(void *param_1,byte param_2)

{
  FUN_004dcf10();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4dcf10 FUN_004dcf10

void __fastcall FUN_004dcf10(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3ba8;
  local_4 = 0;
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0xff;
  }
  FEScreenRegistry__SetFactory(param_1[3],0);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4dcf80 FUN_004dcf80

void FUN_004dcf80(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687b83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x88);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004dcea0();
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4dcfd0 FUN_004dcfd0

int FUN_004dcfd0(void)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  
  FEScreenRegistry__SetFactory();
  iVar3 = 1;
  iVar2 = FUN_004f65d0();
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0x18) + 1;
  }
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if (iVar2 != 0) {
      iVar2 = FUN_004fd1e0(iVar2);
      if (iVar2 != 0) goto LAB_004dd034;
    }
    cFEng__PushPackage(iVar1,in_EAX,iVar3 + 0x10,0xff);
  }
LAB_004dd034:
  iVar2 = FUN_004f65d0();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0;
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x14);
    if (iVar2 != 0) {
      FUN_004dd080(iVar2);
    }
    return iVar2;
  }
  return 0;
}


// ==== 0x4dd080 FUN_004dd080

void __fastcall FUN_004dd080(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_3 + 0x4c) = in_EAX;
  *(undefined1 *)(param_3 + 0x84) = 0;
  puVar2 = (undefined4 *)(param_3 + 0x50);
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_00495f00(*(undefined4 *)(param_3 + 0x50));
  if (*(char *)(param_3 + 0x84) == '\0') {
    FUN_00495f00(*(undefined4 *)(param_3 + 0x54));
  }
  else {
    FUN_004f6850(*(undefined4 *)(param_3 + 0x54));
  }
  FUN_00495f00(*(undefined4 *)(param_3 + 0x78));
  return;
}


// ==== 0x4dd100 FUN_004dd100

void __thiscall FUN_004dd100(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x40) != DAT_0073ad3c) {
    if (param_2 == 0x406415e3) {
      if (*(int *)(param_1 + 0x44) < *(int *)(param_1 + 0x74) + -1) {
        iVar2 = *(int *)(param_1 + 0x44) + 1;
        *(int *)(param_1 + 0x44) = iVar2;
        if (8 < iVar2) {
          *(undefined4 *)(param_1 + 0x44) = 8;
        }
        cVar1 = *(char *)(param_1 + 0x84);
        goto joined_r0x004dd1e5;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0x4c));
      FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
      FUN_004c96c0(*(undefined4 *)(param_1 + 0x7c));
    }
    else {
      if (param_2 == -0x6ee54c9c) {
        if (*(int *)(param_1 + 0x44) < 1) {
          FUN_004f8340(*(undefined4 *)(param_1 + 0x4c));
          FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
          FUN_004c96c0(*(undefined4 *)(param_1 + 0x80));
          return;
        }
        iVar2 = *(int *)(param_1 + 0x44) + -1;
        *(int *)(param_1 + 0x44) = iVar2;
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x44) = 0;
        }
        cVar1 = *(char *)(param_1 + 0x84);
joined_r0x004dd1e5:
        if (cVar1 == '\0') {
          FUN_00495f00(*(undefined4 *)(param_1 + 0x54 + *(int *)(param_1 + 0x44) * 4));
          return;
        }
        FUN_004f6850(*(undefined4 *)(param_1 + 0x54 + *(int *)(param_1 + 0x44) * 4));
        return;
      }
      if ((param_2 == -0x367ca946) && (DAT_00734dbc != '\0')) {
        FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
  }
  return;
}


// ==== 0x4dd230 Screen_PC_Loading::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_Loading__Create(undefined4 param_1)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688c42;
  local_c = ExceptionList;
  local_4 = 0;
  if (DAT_00735dfc != 0) {
    ExceptionList = &local_c;
    uVar1 = Screen_PC_Loading__Screen_PC_Loading(DAT_00735dfc,param_1);
    ExceptionList = local_c;
    return uVar1;
  }
  return 0;
}


// ==== 0x4dd290 Screen_PC_Loading::Screen_PC_Loading

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PC_Loading__Screen_PC_Loading(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  bVar1 = false;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c3778;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x8cb1da82);
    }
  }
  FEObject__SetInvisible(iVar2);
  switch(DAT_0077a920) {
  case 1:
  case 7:
  case 8:
    FUN_00495fc0();
    FUN_00495fc0();
    bVar1 = true;
    break;
  case 2:
  case 4:
  case 5:
    bVar1 = true;
    iVar2 = FUN_004df710();
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x1c) = (*(int *)(iVar2 + 0x1c) + 1) % 0xff;
    }
    param_1[0x11] = iVar2;
    break;
  case 6:
    bVar1 = true;
  }
  FUN_004ddfa0(param_1[0x11]);
  if (bVar1) {
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0xa96c3902);
      }
    }
    FEObject__SetVisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x8cb1da82);
      }
    }
    FEObject__SetVisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x2716e8a);
      }
    }
    FEObject__SetVisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x6d91704);
      }
    }
    FEObject__SetVisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c != 0) {
        uVar3 = FUN_004ef050(0xa962466e);
        FEObject__SetVisible(uVar3);
        ExceptionList = local_c;
        return param_1;
      }
      iVar2 = 0;
    }
    FEObject__SetVisible(iVar2);
  }
  else {
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0xa96c3902);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x8cb1da82);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x2716e8a);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0x6d91704);
      }
    }
    FEObject__SetInvisible(iVar2);
    if (((param_1[3] == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
       (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
      if (DAT_0073578c == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004ef050(0xa962466e);
      }
    }
    FEObject__SetInvisible(iVar2);
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4dd690 FUN_004dd690

undefined4 __fastcall FUN_004dd690(undefined4 param_1)

{
  FUN_004dd6a0(param_1);
  return param_1;
}


// ==== 0x4dd6a0 FUN_004dd6a0

void FUN_004dd6a0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c3778;
  local_4 = 0;
  if (param_1[0x12] != 0) {
    FUN_00546060();
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4dd700 FUN_004dd700

void FUN_004dd700(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int extraout_EDX;
  int iVar7;
  int iVar8;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = 0;
  iVar7 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"CButton_%d",iVar3);
    iVar8 = -1;
    if (*(int *)(&DAT_006f8ff8 + (iVar7 + DAT_00758974) * 4) == 0) {
      pbVar5 = &local_20;
      bVar2 = local_20;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        pbVar1 = pbVar5 + 1;
        iVar8 = iVar8 * 0x21 + (uint)bVar2;
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar8);
        }
      }
      FEObject__SetInvisible(iVar4);
    }
    else {
      pbVar5 = &local_20;
      bVar2 = local_20;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar8 = iVar8 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar1;
      }
      if (((((*(int *)(param_1 + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
           (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
          ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(iVar8), iVar4 != 0)))) &&
         (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar4 + 0x18) == 5)) {
        uVar6 = *(undefined4 *)(iVar4 + 0x60);
        iVar8 = *(int *)(iVar4 + 0x5c);
        if (0 < iVar8) {
          do {
            FEObject__SetVisible(uVar6);
            uVar6 = *(undefined4 *)(extraout_EDX + 4);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
      FUN_00416bb0(*(undefined4 *)(&DAT_006f8ff8 + (iVar7 + DAT_00758974) * 4));
    }
    iVar7 = iVar7 + 5;
  } while (iVar7 < 0x37);
  return;
}


// ==== 0x4dd880 FUN_004dd880

void FUN_004dd880(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  FUN_004ddbb0(in_EAX);
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004dd8d0;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x164e7598);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004dd8d0:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4dd8e0 FUN_004dd8e0

void FUN_004dd8e0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar8;
  int iVar9;
  byte local_20;
  byte local_1f [31];
  
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x922a39c4);
    }
  }
  FEObject__SetVisible(iVar3);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x8cb1da82);
    }
  }
  FEObject__SetVisible(iVar3);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
      goto LAB_004dd9c2;
    }
    uVar4 = FUN_004ef050(0x530464ea);
    FEObject__SetVisible(uVar4);
    iVar3 = 0;
  }
  else {
LAB_004dd9c2:
    FEObject__SetVisible(iVar3);
    iVar3 = 0;
  }
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"CButton_%d",iVar3);
    iVar9 = -1;
    pbVar7 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    iVar8 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004dda8a:
      iVar5 = 0;
      if ((iVar8 != 0) && (iVar6 = FUN_004ef050(iVar9), iVar5 = DAT_0073578c, iVar6 != 0)) {
LAB_004dda9d:
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
        iVar5 = DAT_0073578c;
        if (*(int *)(iVar6 + 0x18) == 5) {
          uVar4 = *(undefined4 *)(iVar6 + 0x60);
          iVar9 = *(int *)(iVar6 + 0x5c);
          if (0 < iVar9) {
            do {
              FEObject__SetVisible(uVar4);
              uVar4 = *(undefined4 *)(extraout_EDX + 4);
              iVar9 = iVar9 + -1;
              iVar5 = DAT_0073578c;
            } while (iVar9 != 0);
          }
        }
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar8 = DAT_0073578c;
      if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004dda73:
        if ((iVar5 == 0) || (iVar6 = FUN_004ffb70(), iVar8 = DAT_0073578c, iVar6 == 0))
        goto LAB_004dda8a;
        goto LAB_004dda9d;
      }
      iVar5 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        iVar6 = *(int *)(DAT_0073578c + 8);
        if ((iVar6 == 0) ||
           ((iVar5 = FUN_004fd1e0(iVar6 + 0xdc), iVar5 == 0 &&
            (iVar5 = FUN_004fd1e0(iVar6 + 0xec), iVar5 == 0)))) goto LAB_004dda8a;
        goto LAB_004dda73;
      }
    }
  } while (iVar3 < 0xb);
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar9 = *(int *)(DAT_0073578c + 8);
      if ((iVar9 == 0) ||
         ((iVar3 = FUN_004fd1e0(iVar9 + 0xdc), iVar3 == 0 &&
          (iVar3 = FUN_004fd1e0(iVar9 + 0xec), iVar3 == 0)))) goto LAB_004ddb59;
    }
    if ((iVar3 != 0) && (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 != 0))
    goto LAB_004ddb70;
  }
LAB_004ddb59:
  if (iVar5 == 0) {
    return;
  }
  iVar3 = FUN_004ef050(0xbe813131);
  if (iVar3 == 0) {
    return;
  }
LAB_004ddb70:
  *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000;
  if (*(int *)(iVar3 + 0x18) == 5) {
    uVar4 = *(undefined4 *)(iVar3 + 0x60);
    iVar3 = *(int *)(iVar3 + 0x5c);
    if (0 < iVar3) {
      do {
        FEObject__SetVisible(uVar4);
        uVar4 = *(undefined4 *)(extraout_EDX_00 + 4);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}


// ==== 0x4ddbb0 FUN_004ddbb0

void FUN_004ddbb0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte local_20;
  byte local_1f [31];
  
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x922a39c4);
    }
  }
  FEObject__SetInvisible(iVar3);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x8cb1da82);
    }
  }
  FEObject__SetInvisible(iVar3);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x530464ea);
    }
  }
  FEObject__SetInvisible(iVar3);
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"CButton_%d",iVar3);
    iVar8 = -1;
    pbVar7 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    iVar6 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ddd58:
      iVar4 = 0;
      if (iVar6 == 0) {
LAB_004ddd6f:
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(iVar8);
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
              (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004ddd58;
          goto LAB_004ddd33;
        }
        goto LAB_004ddd6f;
      }
LAB_004ddd33:
      if ((iVar4 == 0) ||
         (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 = DAT_0073578c, iVar5 == 0))
      goto LAB_004ddd58;
    }
    FEObject__SetInvisible(iVar5);
  } while (iVar3 < 0xb);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004dddf6:
    iVar3 = 0;
    if (iVar4 == 0) {
LAB_004dde11:
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_004ef050(0xf274b80);
      iVar3 = DAT_0073578c;
    }
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
      iVar3 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        iVar8 = *(int *)(DAT_0073578c + 8);
        if ((iVar8 == 0) ||
           ((iVar3 = FUN_004fd1e0(iVar8 + 0xdc), iVar3 == 0 &&
            (iVar3 = FUN_004fd1e0(iVar8 + 0xec), iVar3 == 0)))) goto LAB_004dddf6;
        goto LAB_004ddddc;
      }
      goto LAB_004dde11;
    }
LAB_004ddddc:
    if ((iVar3 == 0) ||
       (iVar8 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar3 = DAT_0073578c, iVar8 == 0))
    goto LAB_004dddf6;
  }
  FEObject__SetInvisible(iVar8);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004dde8b:
    iVar8 = 0;
    if (iVar3 == 0) {
LAB_004ddea6:
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004ef050(0xf274b81);
      iVar8 = DAT_0073578c;
    }
  }
  else {
    iVar8 = FEPackageList__FindByName(&DAT_00746104);
    iVar3 = DAT_0073578c;
    if ((iVar8 == 0) || (iVar8 = *(int *)(iVar8 + 0x18), iVar8 == 0)) {
      iVar8 = DAT_0073578c;
      if (DAT_0073578c != 0) {
        iVar6 = *(int *)(DAT_0073578c + 8);
        if ((iVar6 == 0) ||
           ((iVar8 = FUN_004fd1e0(iVar6 + 0xdc), iVar8 == 0 &&
            (iVar8 = FUN_004fd1e0(iVar6 + 0xec), iVar8 == 0)))) goto LAB_004dde8b;
        goto LAB_004dde71;
      }
      goto LAB_004ddea6;
    }
LAB_004dde71:
    if ((iVar8 == 0) ||
       (iVar6 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar8 = DAT_0073578c, iVar6 == 0))
    goto LAB_004dde8b;
  }
  FEObject__SetInvisible(iVar6);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ddf20:
    if (iVar8 != 0) {
      iVar3 = FUN_004ef050(0xbe813131);
      goto LAB_004ddf37;
    }
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    iVar8 = DAT_0073578c;
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) {
LAB_004ddf06:
      if ((iVar3 != 0) && (iVar3 = FUN_004ffb70(), iVar8 = DAT_0073578c, iVar3 != 0))
      goto LAB_004ddf37;
      goto LAB_004ddf20;
    }
    if (DAT_0073578c != 0) {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if ((iVar6 == 0) ||
         ((iVar3 = FUN_004fd1e0(iVar6 + 0xdc), iVar3 == 0 &&
          (iVar3 = FUN_004fd1e0(iVar6 + 0xec), iVar3 == 0)))) goto LAB_004ddf20;
      goto LAB_004ddf06;
    }
  }
  iVar3 = 0;
LAB_004ddf37:
  FEObject__SetInvisible(iVar3);
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}


// ==== 0x4ddf60 FUN_004ddf60

void FUN_004ddf60(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x44) != 0)) {
    if (*(int *)(*(int *)(param_1 + 0x44) + 8) == 0) {
      FUN_004dd700(param_1);
      FUN_004dd8e0(param_1);
      return;
    }
    FUN_00495fc0();
  }
  return;
}


// ==== 0x4ddfa0 FUN_004ddfa0

void FUN_004ddfa0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  FUN_004dd880();
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_004de0e0();
  }
  else {
    *(int *)(in_EAX + 0x48) = *(int *)(iVar1 + 8);
    FUN_004ad7b0(*(undefined4 *)(iVar1 + 8));
    param_1 = *(int *)(iVar1 + 8);
    FUN_0053e9e0(&DAT_00740420,&param_1,1,FUN_004ddf60,in_EAX,0);
  }
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xbe813131);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_00495fc0();
    FUN_00495f00(*(undefined4 *)(iVar1 + 0xc));
    return;
  }
  FUN_00495fc0();
  FUN_00495fc0();
  uVar3 = *(undefined4 *)(iVar1 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x10);
  if (*(int *)(iVar1 + 4) == 4) {
    uVar3 = 0x70c47a47;
    iVar2 = 0;
  }
  FUN_00495f00(uVar3);
  if (iVar2 == 0) {
    FUN_004f6850(&DAT_006b9172);
    return;
  }
  FUN_00495f00(iVar2);
  return;
}


// ==== 0x4de0e0 FUN_004de0e0

void FUN_004de0e0(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  undefined4 local_4;
  
  uVar1 = FUN_00567c70();
  *(undefined4 *)(unaff_EBX + 0x48) = uVar1;
  FUN_004ad7b0(uVar1);
  local_4 = *(undefined4 *)(unaff_EBX + 0x48);
  FUN_0053e9e0(&DAT_00740420,&local_4,1,FUN_004ddf60,unaff_EBX,0);
  return;
}


// ==== 0x4de130 FUN_004de130

void FUN_004de130(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x40) = 1;
  }
  return;
}


// ==== 0x4de160 FUN_004de160

void __fastcall FUN_004de160(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3744;
  return;
}


// ==== 0x4de170 FUN_004de170

void * __thiscall FUN_004de170(void *param_1,byte param_2)

{
  FUN_004de160();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de190 FUN_004de190

void __fastcall FUN_004de190(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c37f8;
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2 + -1 != (int *)0x0) {
      (**(code **)piVar2[-1])(1);
    }
    piVar2 = (int *)*piVar1;
  }
  return;
}


// ==== 0x4de1c0 FUN_004de1c0

void * __thiscall FUN_004de1c0(void *param_1,byte param_2)

{
  FUN_004de190();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de1e0 FUN_004de1e0

undefined4 * FUN_004de1e0(undefined4 *param_1)

{
  int *piVar1;
  undefined *puVar2;
  byte bVar3;
  char cVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined **ppuVar11;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068683b;
  local_c = ExceptionList;
  piVar1 = param_1 + 1;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c37f8;
  *piVar1 = (int)piVar1;
  param_1[2] = piVar1;
  local_4 = 0;
  if ((DAT_00734998 == 5) || (DAT_00734998 == 0)) {
    ppuVar11 = &PTR_s_DiscErrorPC_fng_006fa1a4;
    do {
      puVar5 = _malloc(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        puVar2 = *ppuVar11;
        *puVar5 = &PTR_FUN_006c3744;
        puVar5[3] = puVar2;
        piVar6 = puVar5 + 1;
      }
      puVar5 = (undefined4 *)param_1[2];
      *puVar5 = piVar6;
      ppuVar11 = ppuVar11 + 1;
      param_1[2] = piVar6;
      piVar6[1] = (int)puVar5;
      *piVar6 = (int)piVar1;
    } while ((int)ppuVar11 < 0x6fa1bc);
  }
  else {
    ppuVar11 = &PTR_s_DiscErrorPC_fng_006fa1bc;
    do {
      puVar5 = _malloc(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        puVar2 = *ppuVar11;
        *puVar5 = &PTR_FUN_006c3744;
        puVar5[3] = puVar2;
        piVar6 = puVar5 + 1;
      }
      puVar5 = (undefined4 *)param_1[2];
      *puVar5 = piVar6;
      ppuVar11 = ppuVar11 + 1;
      param_1[2] = piVar6;
      piVar6[1] = (int)puVar5;
      *piVar6 = (int)piVar1;
    } while ((int)ppuVar11 < 0x6fa1d8);
  }
  if (*piVar1 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *piVar1 + -4;
  }
  param_1[3] = iVar7;
  pbVar9 = *(byte **)(iVar7 + 0xc);
  pcVar10 = "DiscErrorPC.fng";
  do {
    bVar8 = *pcVar10;
    if (('`' < (char)bVar8) && ((char)bVar8 < '{')) {
      bVar8 = bVar8 & 0x5f;
    }
    bVar3 = *pbVar9;
    pcVar10 = pcVar10 + 1;
    if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
      bVar3 = bVar3 & 0x5f;
    }
    pbVar9 = pbVar9 + 1;
  } while (((bVar8 != 0) && (bVar3 != 0)) && (bVar8 == bVar3));
  if (bVar8 == bVar3) {
    if (DAT_007070bc == 0) {
      cVar4 = FUN_00411910(DAT_0070108f);
      if (cVar4 == '\0') {
        DAT_007070bc = 1;
      }
      else {
        DAT_007070bc = 0;
      }
    }
    else {
      cVar4 = FUN_004119d0();
      DAT_007070bc = 1;
    }
    iVar7 = bOpenFile("foobar",0,1);
    if (((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 4), FUN_00594d40(), iVar7 != -1)) ||
       (cVar4 != '\0')) {
      if (*(int *)(param_1[3] + 4) == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(param_1[3] + 4) + -4;
      }
      param_1[3] = iVar7;
    }
  }
  DAT_00735790 = *(undefined4 *)(param_1[3] + 0xc);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4de3c0 FUN_004de3c0

int FUN_004de3c0(byte *param_1)

{
  int in_EAX;
  int iVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  iVar1 = *(int *)(in_EAX + 4);
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + -4;
    }
    iVar3 = in_EAX;
    if (in_EAX == -4) {
      iVar3 = 0;
    }
    if (iVar1 == iVar3) {
      return 0;
    }
    pbVar5 = *(byte **)(iVar1 + 0xc);
    pbVar6 = param_1;
    do {
      bVar4 = *pbVar6;
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 & 0x5f;
      }
      bVar2 = *pbVar5;
      pbVar6 = pbVar6 + 1;
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 & 0x5f;
      }
      pbVar5 = pbVar5 + 1;
    } while (((bVar4 != 0) && (bVar2 != 0)) && (bVar4 == bVar2));
    if (bVar4 == bVar2) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}


// ==== 0x4de440 FUN_004de440

void FUN_004de440(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686bc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x10);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    DAT_00735e00 = FUN_004de1e0(pvVar1);
    ExceptionList = local_c;
    return;
  }
  DAT_00735e00 = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x4de4a0 FUN_004de4a0

void FUN_004de4a0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = DAT_00735e00;
  if (DAT_00735e00 != (undefined4 *)0x0) {
    if (*(int *)(DAT_00735e00[3] + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(DAT_00735e00[3] + 4) + -4;
    }
    DAT_00735e00[3] = iVar2;
    if (puVar1[2] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = puVar1[2] + -4;
    }
    if (iVar2 == puVar1[3]) {
      (**(code **)*puVar1)(1);
      DAT_00735e00 = (undefined4 *)0x0;
    }
    iVar2 = DAT_0073578c;
    if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
       (*(int *)(iVar3 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
    }
  }
  return;
}


// ==== 0x4de520 FUN_004de520

void FUN_004de520(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_00735e00;
  if (DAT_00735e00 != 0) {
    if (in_EAX != 0) {
      uVar2 = FUN_004de3c0(in_EAX);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
    }
    iVar1 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
      }
    }
  }
  return;
}


// ==== 0x4de570 FUN_004de570

void __fastcall FUN_004de570(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c37e8;
  FUN_004f7b50();
  return;
}


// ==== 0x4de580 FUN_004de580

void * __thiscall FUN_004de580(void *param_1,byte param_2)

{
  FUN_004de570();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de5a0 Screen_LS_Disclaimer_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_Disclaimer_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006870f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_LS_Disclaimer_PC__Screen_LS_Disclaimer_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4de600 Screen_LS_Disclaimer_PC::Screen_LS_Disclaimer_PC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_LS_Disclaimer_PC__Screen_LS_Disclaimer_PC(undefined4 *param_1,undefined4 param_2)

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
  bVar2 = DAT_00734998 == 1;
  *param_1 = &PTR_FUN_006c37e8;
  param_1[0x10] = 0;
  local_4 = 0;
  param_1[0x10] = DAT_0073ad3c;
  if (bVar2) {
    if (((param_1[3] == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
       (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0x981e196f);
      }
    }
    FEObject__SetInvisible(iVar1);
    ExceptionList = local_c;
    return param_1;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4de6b0 FUN_004de6b0

void __fastcall FUN_004de6b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c37b8;
  FUN_004f7b50();
  return;
}


// ==== 0x4de6c0 FUN_004de6c0

void * __thiscall FUN_004de6c0(void *param_1,byte param_2)

{
  FUN_004de6b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de6e0 Screen_LS_Demo_Legal::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_Demo_Legal__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006870d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x48);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c37b8;
    puVar1[0x10] = 0;
    puVar1[0x10] = DAT_0073ad3c;
    *(undefined1 *)(puVar1 + 0x11) = 1;
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x4de760 FUN_004de760

void __thiscall FUN_004de760(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 == -0x367ca946) &&
     (fVar1 = (float)(DAT_0073ad3c - *(int *)(param_1 + 0x40)) * 0.00025, 7.0 < fVar1)) {
    if (14.0 <= fVar1) {
      FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    FUN_00495f00(0x393cad4b);
    return;
  }
  return;
}


// ==== 0x4de7d0 FUN_004de7d0

void __fastcall FUN_004de7d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3788;
  FUN_004f7b50();
  return;
}


// ==== 0x4de7e0 FUN_004de7e0

void * __thiscall FUN_004de7e0(void *param_1,byte param_2)

{
  FUN_004de7d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de800 Screen_LS_Demo_Disclaimer::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_Demo_Disclaimer__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006870b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x44);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c3788;
    puVar1[0x10] = 0;
    puVar1[0x10] = DAT_0073ad3c;
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x4de880 FUN_004de880

void __thiscall FUN_004de880(int param_1,int param_2)

{
  if ((param_2 == -0x367ca946) && (7.0 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x40)) * 0.00025)
     ) {
    FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4de8c0 FUN_004de8c0

void __fastcall FUN_004de8c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3768;
  FUN_004f7b50();
  return;
}


// ==== 0x4de8d0 FUN_004de8d0

void * __thiscall FUN_004de8d0(void *param_1,byte param_2)

{
  FUN_004de8c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4de8f0 Screen_LS_IntroFMV::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_IntroFMV__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687093;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_LS_IntroFMV__Screen_LS_IntroFMV(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4de950 Screen_LS_IntroFMV::Screen_LS_IntroFMV

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_IntroFMV__Screen_LS_IntroFMV(undefined4 *param_1,undefined4 param_2)

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
  bVar3 = DAT_00735e04 != 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c3768;
  if (bVar3) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    iVar1 = DAT_0073578c;
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
        cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4de9f0 FUN_004de9f0

int __thiscall FUN_004de9f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0073578c;
  if ((param_2 != 0x406415e3) && (param_2 != -0x4a50db9f)) {
    if (param_2 != -0x3c69f147) {
      return param_2;
    }
    DAT_00733f70 = 1;
  }
  if (DAT_00735e04 == 0) {
    iVar3 = FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
    if (DAT_0073578c != 0) {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      iVar3 = 0;
      if (iVar1 != 0) {
        iVar3 = 0;
        if (*(int *)(iVar1 + 0x18) != 0) {
          iVar2 = FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
          return iVar2;
        }
      }
    }
  }
  return iVar3;
}


// ==== 0x4dea70 FUN_004dea70

void __fastcall FUN_004dea70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3758;
  FUN_004f7b50();
  return;
}


// ==== 0x4dea80 FUN_004dea80

void * __thiscall FUN_004dea80(void *param_1,byte param_2)

{
  FUN_004dea70();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4deaa0 BootMovieScreen::BootMovieScreen

/* [canon] canon med (hopper) docs/re/canon.md */

undefined4 * BootMovieScreen__BootMovieScreen(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar1 = DAT_00734998;
  bVar3 = DAT_00734998 == 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c3758;
  if ((bVar3) || (iVar1 == 5)) {
    pcVar2 = "na_boot";
  }
  else {
    pcVar2 = (char *)GetLocalizedLogoMovie("logo_eng");
  }
  FUN_004c39d0(pcVar2);
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4deb30 FUN_004deb30

void __thiscall FUN_004deb30(int param_1,int param_2)

{
  if (param_2 == -0x3c69f147) {
    DAT_00733f70 = 1;
    FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4deb60 Screen_LS_EAlogo::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_EAlogo__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687b63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = BootMovieScreen__BootMovieScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4debc0 FUN_004debc0

void __fastcall FUN_004debc0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c37a8;
  FUN_004f7b50();
  return;
}


// ==== 0x4debd0 FUN_004debd0

void * __thiscall FUN_004debd0(void *param_1,byte param_2)

{
  FUN_004debc0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4debf0 Screen_LS_PSAMovie::Screen_LS_PSAMovie

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_PSAMovie__Screen_LS_PSAMovie(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = &PTR_FUN_006c37a8;
  FUN_004c39d0(&PTR_LAB_0041534f_1_006c3afc);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4dec50 FUN_004dec50

void __thiscall FUN_004dec50(int param_1,int param_2)

{
  if ((param_2 == 0x406415e3) || (param_2 == -0x4a50db9f)) {
    FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
  }
  else if (param_2 == -0x3c69f147) {
    DAT_00733f70 = 1;
    FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4dec90 Screen_LS_PSAMovie::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_PSAMovie__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687b43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_LS_PSAMovie__Screen_LS_PSAMovie(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4decf0 FUN_004decf0

void __fastcall FUN_004decf0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c380c;
  FUN_004f7b50();
  return;
}


// ==== 0x4ded00 FUN_004ded00

void * __thiscall FUN_004ded00(void *param_1,byte param_2)

{
  FUN_004decf0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ded20 Screen_LS_THXMovie::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_THXMovie__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687b23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c380c;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x4ded80 FUN_004ded80

void __fastcall FUN_004ded80(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c37c8;
  DAT_007588f0 = (uint)(**(int **)(param_1[0x12] + 8) != 0);
  Player__Init(1);
  Player__Init(1);
  _Memory = (int *)param_1[0x10];
  while (_Memory != param_1 + 0x10) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x10];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x4dedf0 FUN_004dedf0

int FUN_004dedf0(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 == 1) || (in_stack_00000014 == 2)) {
    in_stack_00000014 = 0;
  }
  return in_stack_00000014;
}


// ==== 0x4dee10 FUN_004dee10

void * __thiscall FUN_004dee10(void *param_1,byte param_2)

{
  FUN_004ded80();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4dee30 Screen_LS_LangSelect::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_LangSelect__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687b03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x4c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_LS_LangSelect__Screen_LS_LangSelect(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4dee90 Screen_LS_LangSelect::Screen_LS_LangSelect

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_LangSelect__Screen_LS_LangSelect(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688473;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c37c8;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_4 = 1;
  if (DAT_00734998 == 2) {
    piVar3 = _malloc(0xc);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      iVar5 = 0;
      piVar4 = &DAT_006fa210;
      do {
        if (*piVar4 == 0) {
          piVar3[2] = (int)(&DAT_006fa210 + iVar5 * 4);
          goto LAB_004def1d;
        }
        piVar4 = piVar4 + 4;
        iVar5 = iVar5 + 1;
      } while ((int)piVar4 < 0x6fa290);
      piVar3[2] = 0;
    }
LAB_004def1d:
    puVar6 = (undefined4 *)param_1[0x11];
    *puVar6 = piVar3;
    param_1[0x11] = piVar3;
    piVar3[1] = (int)puVar6;
    *piVar3 = (int)puVar1;
    piVar3 = _malloc(0xc);
    if (piVar3 == (int *)0x0) {
      puRam00000004 = (undefined4 *)param_1[0x11];
      *puRam00000004 = 0;
      param_1[0x11] = 0;
      puRam00000000 = puVar1;
    }
    else {
      iVar5 = 0;
      piVar4 = &DAT_006fa210;
      do {
        if (*piVar4 == 7) {
          puVar6 = &DAT_006fa210 + iVar5 * 4;
          goto LAB_004def53;
        }
        piVar4 = piVar4 + 4;
        iVar5 = iVar5 + 1;
      } while ((int)piVar4 < 0x6fa290);
      puVar6 = (undefined4 *)0x0;
LAB_004def53:
      piVar3[2] = (int)puVar6;
      puVar6 = (undefined4 *)param_1[0x11];
      *puVar6 = piVar3;
      param_1[0x11] = piVar3;
      piVar3[1] = (int)puVar6;
      *piVar3 = (int)puVar1;
    }
  }
  else {
    puVar6 = &DAT_006fa210;
    do {
      if ((*(byte *)(puVar6 + 3) & 1) != 0) {
        piVar3 = _malloc(0xc);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3[2] = (int)puVar6;
        }
        puVar2 = (undefined4 *)param_1[0x11];
        *puVar2 = piVar3;
        param_1[0x11] = piVar3;
        piVar3[1] = (int)puVar2;
        *piVar3 = (int)puVar1;
      }
      puVar6 = puVar6 + 4;
    } while ((int)puVar6 < 0x6fa290);
  }
  for (puVar6 = (undefined4 *)*puVar1; puVar6 != puVar1; puVar6 = (undefined4 *)*puVar6) {
    if (*(int *)puVar6[2] == DAT_006ee6f0) goto LAB_004defd4;
  }
  puVar6 = (undefined4 *)0x0;
LAB_004defd4:
  param_1[0x12] = puVar6;
  FUN_004df080();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4df000 FUN_004df000

void FUN_004df000(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_ESI + 0x48);
  if (unaff_EDI == -0x6edfbf62) {
    piVar2 = (int *)puVar1[1];
    if (piVar2 == (int *)(unaff_ESI + 0x40)) {
      piVar2 = *(int **)(unaff_ESI + 0x44);
    }
  }
  else {
    if (unaff_EDI != -0x4a68e40f) goto LAB_004df030;
    piVar2 = (int *)*puVar1;
    if (piVar2 == (int *)(unaff_ESI + 0x40)) {
      piVar2 = *(int **)(unaff_ESI + 0x40);
    }
  }
  *(int **)(unaff_ESI + 0x48) = piVar2;
LAB_004df030:
  if (puVar1 != *(undefined4 **)(unaff_ESI + 0x48)) {
    FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
    EAXSound__ChangeLanguage();
    FUN_004df080();
    return;
  }
  return;
}


// ==== 0x4df080 FUN_004df080

void FUN_004df080(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  
  for (puVar1 = *(undefined4 **)(in_EAX + 0x40); puVar1 != (undefined4 *)(in_EAX + 0x40);
      puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)puVar1[2] == DAT_006ee6f0) goto LAB_004df0a3;
  }
  puVar1 = (undefined4 *)0x0;
LAB_004df0a3:
  FUN_00495f00(*(undefined4 *)(puVar1[2] + 4));
  uVar2 = FUN_004df120();
  FUN_004ad7b0(uVar2);
  return;
}


// ==== 0x4df0e0 FUN_004df0e0

void __thiscall FUN_004df0e0(int param_1,int param_2)

{
  if (param_2 == 0xc407210) {
    FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
  }
  else if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    FUN_004df000();
    return;
  }
  return;
}


// ==== 0x4df100 FUN_004df100

void FUN_004df100(void)

{
  FUN_004df000();
  return;
}


// ==== 0x4df120 FUN_004df120

int __fastcall FUN_004df120(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  
  for (puVar3 = *(undefined4 **)(param_1 + 0x40); puVar3 != (undefined4 *)(param_1 + 0x40);
      puVar3 = (undefined4 *)*puVar3) {
    if (*(int *)puVar3[2] == param_2) goto LAB_004df13f;
  }
  puVar3 = (undefined4 *)0x0;
LAB_004df13f:
  pbVar5 = *(byte **)(puVar3[2] + 8);
  iVar4 = -1;
  bVar2 = *pbVar5;
  while (bVar2 != 0) {
    iVar4 = iVar4 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  return iVar4;
}


// ==== 0x4df170 Screen_LS_Splash_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_LS_Splash_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688253;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_LS_Splash_PC__Screen_LS_Splash_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4df1d0 Screen_LS_Splash_PC::Screen_LS_Splash_PC

/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 * Screen_LS_Splash_PC__Screen_LS_Splash_PC(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 local_2c [32];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  bVar2 = DAT_006f0880 == 0;
  *param_1 = &PTR_FUN_006c3748;
  param_1[0x10] = 0;
  local_4 = 0;
  param_1[0x11] = 0;
  if (bVar2) {
    if (param_1[3] == 0) {
LAB_004df239:
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0x43d41f73);
      }
    }
    else {
      iVar1 = FUN_004f65d0();
      if (iVar1 == 0) goto LAB_004df239;
      iVar1 = FUN_004ffb70();
      if (iVar1 == 0) goto LAB_004df239;
    }
    FEObject__SetInvisible(iVar1);
  }
  if (param_1[3] == 0) {
LAB_004df280:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xc4df3ff2);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004df280;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004df280;
  }
  FEObject__SetInvisible(iVar1);
  if (param_1[3] == 0) {
LAB_004df2c7:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x13cf446d);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004df2c7;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004df2c7;
  }
  FEObject__SetVisible(iVar1);
  if (param_1[3] != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004df32a;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x8c0bd743);
  }
LAB_004df32a:
  FEObject__SetVisible(iVar1);
  if (DAT_0073578c != 0) {
    FUN_004f5f80(DAT_0073578c,1);
    if (DAT_0073578c != 0) {
      FUN_004f5ed0(DAT_0073578c);
    }
  }
  FUN_00449f20(0x20);
  FUN_004f6850(local_2c);
  FUN_00414a10();
  FUN_00416bb0(0xeeeb248e);
  param_1[0x11] = DAT_0073ad3c;
  param_1[0x10] = DAT_0073ad3c;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4df3d0 FUN_004df3d0

void * __thiscall FUN_004df3d0(void *param_1,byte param_2)

{
  FUN_004df3f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4df3f0 FUN_004df3f0

void __fastcall FUN_004df3f0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3748;
  FUN_004f7b50();
  return;
}


// ==== 0x4df400 FUN_004df400

void __thiscall FUN_004df400(int param_1,uint param_2)

{
  if (param_2 < 0x406415e4) {
    if ((param_2 == 0x406415e3) || (param_2 == 0xc407210)) {
      FUN_0041e4d0();
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 == 0x35f8620b) {
      FUN_004c96c0(0x69696969);
      return;
    }
  }
  else if ((param_2 == 0xc98356ba) &&
          (30.0 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x44)) * 0.00025)) {
    FUN_004de520(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4df4a0 FUN_004df4a0

void __fastcall FUN_004df4a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c37fc;
  FUN_004f7b50();
  return;
}


// ==== 0x4df4b0 FUN_004df4b0

void * __thiscall FUN_004df4b0(void *param_1,byte param_2)

{
  FUN_004df4a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4df4d0 Screen_DiscErrorPC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_DiscErrorPC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687ae3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_DiscErrorPC__Screen_DiscErrorPC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4df530 FUN_004df530

void FUN_004df530(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_004df630(param_1);
  }
  return;
}


// ==== 0x4df560 Screen_DiscErrorPC::Screen_DiscErrorPC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_DiscErrorPC__Screen_DiscErrorPC(undefined4 *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c37fc;
  local_4 = 0;
  param_1[0x10] = 0;
  pcVar4 = "DEMO_DISC_MARKETING_BLURB";
  param_2 = -1;
  uVar2 = 0x44;
  do {
    param_2 = param_2 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_004df530,0,0);
  if (param_1[3] != 0) {
    iVar3 = FUN_004f65d0();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_004df611;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(0x505e82bf);
  }
LAB_004df611:
  FEObject__SetInvisible(iVar3);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4df630 FUN_004df630

void FUN_004df630(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004df67a;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x505e82bf);
    FEObject__SetVisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004df67a:
  FEObject__SetVisible(iVar1);
  return;
}


// ==== 0x4df690 FUN_004df690

void __thiscall FUN_004df690(int param_1,int param_2,int param_3)

{
  char cVar1;
  
  if ((param_2 == 0xc407210) && (param_3 != 0)) {
    if (*(int *)(param_3 + 0x10) == 0x4f876b6f) {
      cVar1 = FUN_00411ab0();
      if (cVar1 != '\0') {
        FUN_004de4a0(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else {
      DAT_00736124 = 1;
    }
  }
  return;
}


// ==== 0x4df6e0 FUN_004df6e0

void __fastcall FUN_004df6e0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_006fa294;
  do {
    if (*piVar1 == param_2) {
      if (iVar2 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar2 * 0x24] = 1;
      }
      return;
    }
    piVar1 = piVar1 + 9;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x6fa5ac);
  return;
}


// ==== 0x4df710 FUN_004df710

int * FUN_004df710(void)

{
  float fVar1;
  int *piVar2;
  int *piVar3;
  float local_8;
  
  local_8 = 0.0;
  piVar3 = (int *)0x0;
  piVar2 = (int *)&DAT_006fa2a8;
  do {
    if ((char)piVar2[2] == '\0') {
      fVar1 = 0.0;
    }
    else if ((*piVar2 == 0) || (piVar2[1] < *piVar2)) {
      fVar1 = (float)(int)(0xffU - piVar2[1] | piVar2[-1] << 8);
    }
    else {
      fVar1 = 0.0;
    }
    if (local_8 < fVar1) {
      piVar3 = piVar2 + -6;
      local_8 = fVar1;
    }
    piVar2 = piVar2 + 9;
  } while ((int)piVar2 < 0x6fa5c0);
  return piVar3;
}


// ==== 0x4df790 FUN_004df790

void FUN_004df790(void)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  puVar1 = &DAT_006fa2b0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x24;
  } while ((int)puVar1 < 0x6fa5c8);
  if (unaff_EDI == 6) {
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 3) {
        if (iVar3 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 0x14) goto LAB_004df862;
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  else if (unaff_EDI == 5) {
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 4) {
        if (iVar3 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 0x14) goto LAB_004df862;
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  else if (unaff_EDI == 2) {
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 7) goto LAB_004df862;
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
LAB_004df873:
  iVar3 = DAT_00758c2c;
  if (DAT_00777b4c != 8) {
    iVar3 = DAT_00758c28;
  }
  piVar2 = &DAT_0075afa4;
  do {
    if (iVar3 == *piVar2) {
      iVar3 = FUN_004ac060();
      iVar3 = *(int *)(iVar3 + 0x2f0);
      if (DAT_0078eb08 < iVar3) {
        iVar4 = 0;
        piVar2 = &DAT_006fa294;
        goto LAB_004df8c8;
      }
      break;
    }
    piVar2 = piVar2 + 0xd2;
  } while ((int)piVar2 < 0x75f144);
LAB_004df8eb:
  if (unaff_EDI == 4) {
    iVar3 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 9) {
        if (iVar3 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0xe) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0xf) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x10) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x11) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x12) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      return;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  return;
LAB_004df862:
  if (iVar3 * 0x24 != -0x6fa290) {
    (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
  }
  goto LAB_004df873;
  while( true ) {
    piVar2 = piVar2 + 9;
    iVar4 = iVar4 + 1;
    if (0x6fa5ab < (int)piVar2) break;
LAB_004df8c8:
    DAT_0078eb08 = iVar3;
    if (*piVar2 == 8) {
      if (iVar4 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
      }
      break;
    }
  }
  goto LAB_004df8eb;
}


// ==== 0x4dfa10 FUN_004dfa10

void FUN_004dfa10(void)

{
  int in_EAX;
  undefined1 *puVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = &DAT_006fa2b0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x24;
  } while ((int)puVar1 < 0x6fa5c8);
  if (*(int *)(in_EAX + 8) == 3) {
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 3) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 0x14) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  if (*(int *)(in_EAX + 8) == 1) {
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 4) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 0x14) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  if (*(int *)(in_EAX + 4) == 2) {
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 6) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  if ((*(int *)(in_EAX + 4) == 3) && (*(int *)(in_EAX + 8) == 2)) {
    FUN_004df6e0();
  }
  if (*(int *)(in_EAX + 8) == 5) {
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 7) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  if (*(int *)(in_EAX + 4) == 1) {
    iVar4 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 9) {
        if (iVar4 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar4 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  iVar4 = DAT_007677a8;
  if ((DAT_00734010 == 0) &&
     (((DAT_007677a8 == 0 || ((int *)(DAT_007677a8 + 0x58a0) == (int *)0x0)) ||
      (*(int *)(DAT_007677a8 + 0x58a0) != 6)))) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = &DAT_0075f24a;
  }
  if (*pcVar3 == '\x02') {
    iVar5 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 0xb) {
        if (iVar5 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar5 = iVar5 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  if (DAT_0078eb0c < DAT_0075f1e8) {
    DAT_0078eb0c = DAT_0075f1e8;
    iVar5 = 0;
    piVar2 = &DAT_006fa294;
    do {
      if (*piVar2 == 8) {
        if (iVar5 * 0x24 != -0x6fa290) {
          (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
        }
        break;
      }
      piVar2 = piVar2 + 9;
      iVar5 = iVar5 + 1;
    } while ((int)piVar2 < 0x6fa5ac);
  }
  iVar5 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0xe) {
      if (iVar5 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar5 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0xf) {
      if (iVar5 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar5 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x10) {
      if (iVar5 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar5 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x11) {
      if (iVar5 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  iVar5 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 0x12) {
      if (iVar5 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar5 * 0x24] = 1;
      }
      break;
    }
    piVar2 = piVar2 + 9;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  if ((DAT_0073400c == 0) &&
     (((iVar4 == 0 || (piVar2 = (int *)(iVar4 + 0x58a0), piVar2 == (int *)0x0)) || (*piVar2 != 5))))
  {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = &DAT_0075f249;
  }
  if ((*pcVar3 == '\x02') && (DAT_0076027e == '\0')) {
    FUN_004df6e0();
    return;
  }
  return;
}


// ==== 0x4dfd70 FUN_004dfd70

void FUN_004dfd70(void)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = &DAT_006fa2b0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x24;
  } while ((int)puVar1 < 0x6fa5c8);
  iVar3 = 0;
  piVar2 = &DAT_006fa294;
  do {
    if (*piVar2 == 2) {
      if (iVar3 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar3 * 0x24] = 1;
      }
      return;
    }
    piVar2 = piVar2 + 9;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x6fa5ac);
  return;
}


// ==== 0x4dfdc0 FUN_004dfdc0

void FUN_004dfdc0(void)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  puVar4 = &DAT_006fa2b0;
  do {
    *puVar4 = 0;
    iVar7 = DAT_007677a8;
    puVar4 = puVar4 + 0x24;
  } while ((int)puVar4 < 0x6fa5c8);
  if ((DAT_00777b4c == 1) && (cVar3 = Race__DidPlayerWin(DAT_007677a8,0), cVar3 != '\0')) {
    iVar1 = *(int *)(iVar7 + 0x58a4);
    iVar5 = 0;
    bVar2 = false;
    if (0 < *(int *)(iVar7 + 0x5914)) {
      piVar6 = (int *)(iVar7 + 0x58d8);
      do {
        if (*piVar6 == 2) {
          bVar2 = true;
          break;
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 3;
        bVar2 = false;
      } while (iVar5 < *(int *)(iVar7 + 0x5914));
    }
    if (*(int *)(iVar7 + 0x58a0) == 0) {
      iVar7 = 0;
      piVar6 = &DAT_006fa294;
      do {
        if (*piVar6 == 10) {
          if (iVar7 * 0x24 != -0x6fa290) {
            (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
          }
          break;
        }
        piVar6 = piVar6 + 9;
        iVar7 = iVar7 + 1;
      } while ((int)piVar6 < 0x6fa5ac);
    }
    if ((iVar1 == 2) || (iVar1 == 3)) {
      iVar7 = 0;
      piVar6 = &DAT_006fa294;
      do {
        if (*piVar6 == 0xd) {
          if (iVar7 * 0x24 != -0x6fa290) {
            (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
          }
          break;
        }
        piVar6 = piVar6 + 9;
        iVar7 = iVar7 + 1;
      } while ((int)piVar6 < 0x6fa5ac);
    }
    if (bVar2) {
      iVar7 = 0;
      piVar6 = &DAT_006fa294;
      do {
        if (*piVar6 == 0xc) {
          if (iVar7 * 0x24 != -0x6fa290) {
            (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
          }
          break;
        }
        piVar6 = piVar6 + 9;
        iVar7 = iVar7 + 1;
      } while ((int)piVar6 < 0x6fa5ac);
    }
  }
  iVar7 = 0;
  piVar6 = &DAT_006fa294;
  do {
    if (*piVar6 == 0xe) {
      if (iVar7 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
      }
      break;
    }
    piVar6 = piVar6 + 9;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0x6fa5ac);
  iVar7 = 0;
  piVar6 = &DAT_006fa294;
  do {
    if (*piVar6 == 0xf) {
      if (iVar7 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
      }
      break;
    }
    piVar6 = piVar6 + 9;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0x6fa5ac);
  iVar7 = 0;
  piVar6 = &DAT_006fa294;
  do {
    if (*piVar6 == 0x10) {
      if (iVar7 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
      }
      break;
    }
    piVar6 = piVar6 + 9;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0x6fa5ac);
  iVar7 = 0;
  piVar6 = &DAT_006fa294;
  do {
    if (*piVar6 == 0x11) {
      if (iVar7 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
      }
      break;
    }
    piVar6 = piVar6 + 9;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0x6fa5ac);
  iVar7 = 0;
  piVar6 = &DAT_006fa294;
  do {
    if (*piVar6 == 0x12) {
      if (iVar7 * 0x24 != -0x6fa290) {
        (&DAT_006fa2b0)[iVar7 * 0x24] = 1;
      }
      return;
    }
    piVar6 = piVar6 + 9;
    iVar7 = iVar7 + 1;
  } while ((int)piVar6 < 0x6fa5ac);
  return;
}


// ==== 0x4dffff FUN_004dffff

/* WARNING: Instruction at (ram,0x004e000b) overlaps instruction at (ram,0x004e000a)
    */

void * __fastcall FUN_004dffff(undefined4 param_1,undefined2 param_2,byte param_3)

{
  char *pcVar1;
  undefined1 uVar2;
  byte bVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  void *_Memory;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  byte in_AF;
  
  iVar4 = in_EAX + unaff_EBX;
  bVar3 = 9 < ((byte)iVar4 & 0xf) | in_AF;
  uVar5 = CONCAT31((int3)((uint)iVar4 >> 8),(byte)iVar4 + bVar3 * '\x06') & 0xffffff0f;
  uVar2 = in(param_2);
  *(undefined1 *)(unaff_EDI + 1) = uVar2;
  _Memory = (void *)CONCAT31((int3)((uint)param_1 >> 8),(char)param_1 + (char)((uint)param_1 >> 8));
  if ((POPCOUNT(unaff_EBP + 1U & 0xff) & 1U) == 0) {
    pcVar1 = (char *)(CONCAT22((short)(uVar5 >> 0x10),
                               CONCAT11((char)((uint)iVar4 >> 8) + bVar3,(char)uVar5)) + -0x6f6f6f70
                     );
    *pcVar1 = *pcVar1 + (char)param_2;
  }
  FUN_004e0000();
  if ((param_3 & 1) != 0) {
    _free(_Memory);
  }
  return _Memory;
}


// ==== 0x4e0000 FUN_004e0000

void __fastcall FUN_004e0000(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c37d8;
  FUN_004f7b50();
  return;
}


// ==== 0x4e0010 FUN_004e0010

void * __thiscall FUN_004e0010(void *param_1,byte param_2)

{
  FUN_004e0000();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e0030 Screen_DemoDisc_Marketing::Screen_DemoDisc_Marketing

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_DemoDisc_Marketing__Screen_DemoDisc_Marketing(undefined4 *param_1,undefined4 param_2)

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
  iVar1 = DAT_0073578c;
  bVar3 = DAT_0073578c == 0;
  *param_1 = &PTR_FUN_006c37d8;
  local_4 = 0;
  param_1[0x10] = 0;
  if (bVar3) {
    param_1[0x10] = DAT_0073ad3c;
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x18) == 0) {
        param_1[0x10] = DAT_0073ad3c;
        ExceptionList = local_c;
        return param_1;
      }
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
    param_1[0x10] = DAT_0073ad3c;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4e00d0 FUN_004e00d0

void FUN_004e00d0(void)

{
  int iVar1;
  
  if (DAT_00735dd8 != 0) {
    DAT_00736124 = 1;
    return;
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x12347780,0,0,*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4e0120 FUN_004e0120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e0120(int param_1,int param_2)

{
  if ((param_2 == -0x367ca946) &&
     (_DAT_006fa5a8 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x40)) * 0.00025)) {
    FUN_004e00d0(param_1);
  }
  return;
}


// ==== 0x4e0160 Screen_DemoDisc_Marketing::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_DemoDisc_Marketing__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687ac3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_DemoDisc_Marketing__Screen_DemoDisc_Marketing(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e01c0 FUN_004e01c0

void __fastcall FUN_004e01c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c3798;
  FUN_004f7b50();
  return;
}


// ==== 0x4e01d0 FUN_004e01d0

void * __thiscall FUN_004e01d0(void *param_1,byte param_2)

{
  FUN_004e01c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e01f0 Screen_LS_ESRB_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_LS_ESRB_PC__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687aa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x44);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c3798;
    puVar1[0x10] = 0;
    puVar1[0x10] = DAT_0073ad3c;
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x4e0270 FUN_004e0270

void FUN_004e0270(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(in_EAX + 0xc);
  *(undefined1 *)(in_EAX + 9) = 1;
  if ((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x4c), iVar3 != 0)) {
    while (iVar2 = FEng__HashName(), *(int *)(iVar3 + 0x30) != iVar2) {
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        return;
      }
    }
    if (iVar3 != 0) {
      if (iVar3 != *(int *)(iVar1 + 0x54)) {
        *(int *)(iVar1 + 0x54) = iVar3;
        FUN_004ff030(iVar1);
        *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
    }
  }
  return;
}


// ==== 0x4e02d0 FUN_004e02d0

void FUN_004e02d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined1 *)(param_1 + 9) = 0;
  if (iVar1 != 0) {
    for (iVar3 = *(int *)(iVar1 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      iVar2 = FEng__HashName();
      if (*(int *)(iVar3 + 0x30) == iVar2) {
        if (iVar3 != 0) {
          if (iVar3 != *(int *)(iVar1 + 0x54)) {
            *(int *)(iVar1 + 0x54) = iVar3;
            FUN_004ff030(iVar1);
            *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar3 + 0x10) = 0;
        }
        break;
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4);
  if ((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x4c), iVar3 != 0)) {
    while (iVar2 = FEng__HashName(), *(int *)(iVar3 + 0x30) != iVar2) {
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        return;
      }
    }
    if (iVar3 != 0) {
      if (iVar3 != *(int *)(iVar1 + 0x54)) {
        *(int *)(iVar1 + 0x54) = iVar3;
        FUN_004ff030(iVar1);
        *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
    }
  }
  return;
}


// ==== 0x4e0380 FUN_004e0380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004e0380(int *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int *local_2c;
  byte local_20;
  byte local_1f [31];
  
  *param_1 = in_EAX;
  param_1[1] = 1;
  param_1[6] = param_2;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  bSPrintf_regdst(0x20,"P%d_Transmission_select",in_EAX + 1);
  uVar4 = FEng__HashName();
  if (((param_2 == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
     (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c != 0) {
      iVar5 = FUN_004ef050(uVar4);
      local_2c = param_1 + 4;
      param_1[3] = iVar5;
      iVar5 = 0;
      goto LAB_004e0420;
    }
    iVar5 = 0;
  }
  local_2c = param_1 + 4;
  param_1[3] = iVar5;
  iVar5 = 0;
LAB_004e0420:
  do {
    iVar5 = iVar5 + 1;
    bSPrintf_regdst(0x20,"button_%d_p%d",iVar5,in_EAX + 1);
    iVar9 = -1;
    pbVar7 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar7 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar3;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    iVar8 = DAT_0073578c;
    if (param_2 == 0) {
LAB_004e04e9:
      if (iVar8 == 0) {
LAB_004e04fa:
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar8 = DAT_0073578c;
      if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_004e04e9;
          goto LAB_004e04c8;
        }
        goto LAB_004e04fa;
      }
LAB_004e04c8:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar8 = DAT_0073578c, iVar6 == 0))
      goto LAB_004e04e9;
    }
    *local_2c = iVar6;
    local_2c = local_2c + 1;
    if (1 < iVar5) {
      iVar5 = DAT_00758954;
      if (((*param_1 == 0) || (iVar5 = _DAT_00758958, *param_1 == 1)) && (iVar5 != 0)) {
        if (iVar5 == 1) {
          param_1[1] = 2;
        }
        return param_1;
      }
      param_1[1] = 1;
      return param_1;
    }
  } while( true );
}


// ==== 0x4e0560 FUN_004e0560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e0560(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *unaff_EBX;
  
  iVar1 = unaff_EBX[1];
  if (in_EAX == -0x6edfbf62) {
    unaff_EBX[1] = 1;
  }
  else if (in_EAX == -0x4a68e40f) {
    unaff_EBX[1] = 2;
  }
  if (iVar1 != unaff_EBX[1]) {
    FUN_004f65d0();
    iVar1 = unaff_EBX[iVar1 + 3];
    if (iVar1 != 0) {
      for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        iVar3 = FEng__HashName();
        if (*(int *)(iVar2 + 0x30) == iVar3) {
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
    iVar1 = unaff_EBX[unaff_EBX[1] + 3];
    if (iVar1 != 0) {
      for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        iVar3 = FEng__HashName();
        if (*(int *)(iVar2 + 0x30) == iVar3) {
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
    if (*unaff_EBX == 0) {
      DAT_00758954 = (uint)(unaff_EBX[1] != 1);
      return;
    }
    if (*unaff_EBX == 1) {
      _DAT_00758958 = (uint)(unaff_EBX[1] != 1);
    }
  }
  return;
}


// ==== 0x4e0650 FUN_004e0650

void __fastcall FUN_004e0650(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c36c4;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  return;
}


// ==== 0x4e0680 FUN_004e0680

void * __thiscall FUN_004e0680(void *param_1,byte param_2)

{
  FUN_004e0650();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e06a0 FUN_004e06a0

void __fastcall FUN_004e06a0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  *param_1 = &PTR_FUN_006c36b4;
  piVar1 = param_1 + 0x1a;
  param_1[0x19] = &PTR_FUN_006c36c4;
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    _free(piVar2);
    piVar2 = (int *)*piVar1;
  }
  piVar1 = param_1 + 0x11;
  param_1[0x10] = &PTR_FUN_006c36c4;
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    _free(piVar2);
    piVar2 = (int *)*piVar1;
  }
  FUN_004f7b50();
  return;
}


// ==== 0x4e0720 FUN_004e0720

void * __thiscall FUN_004e0720(void *param_1,byte param_2)

{
  FUN_004e06a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4e0740 Screen_MU_MultiplayerCarSelect::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_MultiplayerCarSelect__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689143;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xcc);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_MultiplayerCarSelect__Screen_MU_MultiplayerCarSelect(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4e07a0 Screen_MU_MultiplayerCarSelect::Screen_MU_MultiplayerCarSelect

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_MultiplayerCarSelect__Screen_MU_MultiplayerCarSelect
          (undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068911e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c36b4;
  puVar3 = param_1 + 0x11;
  param_1[0x10] = &PTR_FUN_006c36c4;
  *puVar3 = puVar3;
  param_1[0x12] = puVar3;
  param_1[0x18] = param_1[3];
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  puVar3 = param_1 + 0x1a;
  param_1[0x19] = &PTR_FUN_006c36c4;
  *puVar3 = puVar3;
  param_1[0x1b] = puVar3;
  param_1[0x21] = param_1[3];
  param_1[0x1e] = 1;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  local_4 = 2;
  FUN_004e0380(param_1 + 0x22,param_1[3]);
  FUN_004e0380(param_1 + 0x29,param_1[3]);
  DAT_00746968 = 0;
  DAT_00746964 = 0;
  if (((param_1[3] == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xa9464188);
    }
  }
  FEObject__SetInvisible(iVar1);
  if (((param_1[3] == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x13dccc51);
    }
  }
  FEObject__SetInvisible(iVar1);
  DAT_00748f78 = 0;
  DAT_00748f7c = 1;
  if (DAT_0070701c != 0) {
    DAT_0070701c = 0;
    if (DAT_00777b4c == 8) {
      param_2 = DAT_00768570;
    }
    else {
      param_2 = DAT_0076856c;
    }
    puVar3 = &DAT_00758c28;
    puVar4 = &DAT_0076856c;
    for (iVar1 = 0x18b4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_004cc7c0(&DAT_0076e83c,&DAT_0075eef8);
    Player__Init(1);
    Player__Init(0);
    if (DAT_00777b4c == 8) {
      DAT_00768570 = param_2;
    }
    else {
      DAT_0076856c = param_2;
    }
    FUN_004ab570();
  }
  FUN_004e0d90(param_1,param_1 + 0x10,0);
  FUN_004e0d90(param_1,param_1 + 0x19,1);
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 &&
       (*(int *)(iVar2 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar1 = iVar2 + 0xdc;
    if ((iVar1 == 0) || (iVar1 = FUN_004fd1e0(iVar1), iVar1 == 0)) {
      cFEng__PushPackage(iVar2,"GarageMain_2P.fng",0x10,0);
    }
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar1 = iVar2 + 0xdc;
    if ((iVar1 == 0) || (iVar1 = FUN_004fd1e0(iVar1), iVar1 == 0)) {
      cFEng__PushPackage(iVar2,"MU_MPBackground.fng",0x10,0);
    }
  }
  FUN_00414a10();
  FUN_00414a10();
  FUN_004e19a0();
  FUN_004e19a0();
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar1 + 0x18));
  }
  FUN_004b2480();
  param_1[0x30] = 0xffffffff;
  if (((param_1[3] == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x7af8fe3f);
    }
  }
  FEObject__SetInvisible(iVar1);
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar1 + 0x18));
  }
  FUN_004e1b90();
  FUN_004e1b90();
  *(undefined1 *)(param_1 + 0x32) = 0;
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4e0bf0 FUN_004e0bf0

uint __fastcall FUN_004e0bf0(int param_1)

{
  uint in_EAX;
  int iVar1;
  
  if ((in_EAX & 1) != 0) {
    return (uint)((&DAT_00748f78)[param_1] == 0);
  }
  if ((in_EAX & 2) != 0) {
    return (uint)((&DAT_00748f78)[param_1] == 1);
  }
  if ((in_EAX & 4) != 0) {
    return (uint)((&DAT_00748f78)[param_1] == 2);
  }
  iVar1 = (-(uint)((in_EAX & 8) != 0) & 4) - 1;
  return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == (&DAT_00748f78)[param_1]);
}


// ==== 0x4e0c50 FUN_004e0c50

void FUN_004e0c50(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(in_EAX + 0xc0) = 0xffffffff;
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004e0ca2;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x7af8fe3f);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004e0ca2:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4e0cb0 FUN_004e0cb0

undefined4 __fastcall FUN_004e0cb0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  int iVar2;
  
  if ((in_EAX & 1) == 0) {
    if ((in_EAX & 2) == 0) {
      if ((in_EAX & 4) == 0) {
        iVar2 = (-(uint)((in_EAX & 8) != 0) & 4) - 1;
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
  if (param_2 != 0) {
    iVar1 = DAT_00748f7c;
    if ((param_2 == 1) && (iVar1 = iVar2, DAT_00748f78 == iVar2)) {
      return 0;
    }
    DAT_00748f7c = iVar1;
    return 1;
  }
  DAT_00748f78 = iVar2;
  return 1;
}


// ==== 0x4e0d10 FUN_004e0d10

void FUN_004e0d10(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int unaff_EDI;
  
  if (param_1 == 0) {
    piVar1 = (int *)(unaff_EDI + 0x44);
    piVar2 = *(int **)(unaff_EDI + 0x44);
    while (piVar2 != piVar1) {
      piVar2 = (int *)*piVar1;
      iVar4 = *piVar2;
      piVar3 = (int *)piVar2[1];
      *piVar3 = iVar4;
      *(int **)(iVar4 + 4) = piVar3;
      _free(piVar2);
      piVar2 = (int *)*piVar1;
    }
    iVar4 = unaff_EDI + 0x40;
    param_1 = 0;
  }
  else {
    piVar1 = (int *)(unaff_EDI + 0x68);
    piVar2 = *(int **)(unaff_EDI + 0x68);
    while (piVar2 != piVar1) {
      piVar2 = (int *)*piVar1;
      iVar4 = *piVar2;
      piVar3 = (int *)piVar2[1];
      *piVar3 = iVar4;
      *(int **)(iVar4 + 4) = piVar3;
      _free(piVar2);
      piVar2 = (int *)*piVar1;
    }
    iVar4 = unaff_EDI + 100;
  }
  FUN_004e0d90(unaff_EDI,iVar4,param_1);
  FUN_004e19a0();
  FUN_004e1b90();
  return;
}


// ==== 0x4e0d90 FUN_004e0d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e0d90(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 *puVar12;
  float10 fVar13;
  int *local_14;
  int local_10;
  
  if ((param_3 < 0) || (1 < param_3)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = &DAT_00758c28 + param_3 * 0x3e51;
  }
  local_10 = 0;
  if (0 < piVar4[0x1876]) {
    local_14 = piVar4 + 0x80e;
    do {
      if ((local_10 < 0) || (piVar9 = local_14, 0x13 < local_10)) {
        piVar9 = (int *)0x0;
      }
      iVar5 = 0;
      piVar7 = (int *)(DAT_00734588 + 0xd0);
      do {
        if (*piVar7 == piVar9[2]) {
          iVar5 = iVar5 * 0xc90 + DAT_00734588;
          goto LAB_004e0e12;
        }
        iVar5 = iVar5 + 1;
        piVar7 = piVar7 + 0x324;
      } while (iVar5 < 0x23);
      iVar5 = 0;
LAB_004e0e12:
      iVar5 = *(int *)(iVar5 + 0xc50) * 0xc90 + DAT_00734588;
      if (iVar5 != 0) {
        _DAT_00735e70 = 0;
        if (*(short *)(iVar5 + 0xc58) != 0) {
          uVar6 = 0;
          if (DAT_0073766c != 0) {
            piVar7 = (int *)(DAT_00737668 + 0x24);
            do {
              if ((piVar7[-1] == 0) && (*piVar7 == *(int *)(iVar5 + 0xc50))) {
                if (*(char *)(uVar6 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_004e0e94;
                break;
              }
              uVar6 = uVar6 + 1;
              piVar7 = piVar7 + 0xd;
            } while (uVar6 < DAT_0073766c);
          }
          cVar3 = Career__IsCarUnlocked();
          if (cVar3 == '\0') goto LAB_004e0f01;
        }
LAB_004e0e94:
        piVar7 = _malloc(0x740);
        if (piVar7 == (int *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          iVar8 = piVar9[0xce];
          iVar11 = piVar9[0xd1];
          RideInfo__Init();
          piVar7[0x1cc] = iVar5;
          piVar7[0x1cd] = iVar8;
          piVar7[0x1ce] = iVar11;
        }
        FECarConfig__BuildRide(piVar9,param_3,piVar7 + 4);
        puVar12 = *(undefined4 **)(param_2 + 8);
        *puVar12 = piVar7;
        *(int **)(param_2 + 8) = piVar7;
        piVar7[1] = (int)puVar12;
        *piVar7 = param_2 + 4;
      }
LAB_004e0f01:
      local_10 = local_10 + 1;
      local_14 = local_14 + 0xd2;
    } while (local_10 < piVar4[0x1876]);
  }
  bList__Sort(param_2 + 4,FUN_004c2bc0);
  local_10 = 0;
  iVar5 = DAT_00734588;
  if (0 < piVar4[0x18b3]) {
    piVar9 = piVar4 + 0x187a;
    do {
      iVar8 = *piVar9;
      _DAT_00735e70 = 0;
      if (iVar8 < 1) {
        if ((piVar9[-1] & DAT_00777b4c) != 0) {
LAB_004e1002:
          iVar8 = PresetRide__FindByKeyHash(piVar9[-2]);
          if (iVar8 != 0) {
            pbVar10 = (byte *)(iVar8 + 8);
            iVar8 = -1;
            bVar2 = *pbVar10;
            while (bVar2 != 0) {
              iVar8 = iVar8 * 0x21 + (uint)bVar2;
              pbVar1 = pbVar10 + 1;
              pbVar10 = pbVar10 + 1;
              bVar2 = *pbVar1;
            }
            iVar11 = 0;
            piVar7 = (int *)(iVar5 + 0xd0);
            do {
              if (*piVar7 == iVar8) {
                iVar8 = iVar11 * 0xc90 + iVar5;
                goto LAB_004e1052;
              }
              iVar11 = iVar11 + 1;
              piVar7 = piVar7 + 0x324;
            } while (iVar11 < 0x23);
            iVar8 = 0;
LAB_004e1052:
            iVar8 = *(int *)(iVar8 + 0xc50);
            if (iVar8 != -1) {
              piVar7 = _malloc(0x740);
              if (piVar7 == (int *)0x0) {
                piVar7 = (int *)0x0;
              }
              else {
                iVar11 = piVar9[-3];
                fVar13 = (float10)GetStockPerformanceMeasure();
                RideInfo__Init();
                piVar7[0x1ce] = iVar11;
                piVar7[0x1cc] = iVar8 * 0xc90 + iVar5;
                piVar7[0x1cd] = (int)(float)fVar13;
              }
              cFrontendDatabase__BuildRideForCarHandle(piVar7 + 4);
              puVar12 = *(undefined4 **)(param_2 + 8);
              *puVar12 = piVar7;
              *(int **)(param_2 + 8) = piVar7;
              piVar7[1] = (int)puVar12;
              *piVar7 = param_2 + 4;
              iVar5 = DAT_00734588;
            }
          }
        }
      }
      else if ((piVar9[-1] & DAT_00777b4c) != 0) {
        if ((iVar8 < 0) || (DAT_007343fc <= iVar8)) {
          iVar11 = 0;
        }
        else {
          iVar11 = iVar8 * 0x20 + DAT_007343f8;
        }
        if (*(char *)((int)&DAT_00758ad8 + iVar8) != '\0') goto LAB_004e1002;
        uVar6 = 0;
        if (DAT_0073766c != 0) {
          piVar7 = (int *)(DAT_00737668 + 0x24);
          do {
            if ((piVar7[-1] == 6) && (*piVar7 == *(int *)(iVar11 + 8))) {
              if (*(char *)(uVar6 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_004e1002;
              break;
            }
            uVar6 = uVar6 + 1;
            piVar7 = piVar7 + 0xd;
          } while (uVar6 < DAT_0073766c);
        }
      }
      local_10 = local_10 + 1;
      piVar9 = piVar9 + 4;
    } while (local_10 < piVar4[0x18b3]);
  }
  if ((&DAT_0076027c)[param_3 * 0x7ca2] != 0) {
    iVar8 = 0;
    piVar9 = (int *)(iVar5 + 0xd0);
    do {
      if (*piVar9 == (&DAT_0075ef00)[param_3 * 0x3e51]) {
        iVar8 = iVar8 * 0xc90 + iVar5;
        goto LAB_004e114a;
      }
      iVar8 = iVar8 + 1;
      piVar9 = piVar9 + 0x324;
    } while (iVar8 < 0x23);
    iVar8 = 0;
LAB_004e114a:
    iVar8 = *(int *)(iVar8 + 0xc50);
    piVar9 = _malloc(0x740);
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar11 = (&DAT_0075f23c)[param_3 * 0x3e51];
      fVar13 = (float10)GetStockPerformanceMeasure();
      RideInfo__Init();
      piVar9[0x1cc] = iVar8 * 0xc90 + iVar5;
      piVar9[0x1cd] = (int)(float)fVar13;
      piVar9[0x1ce] = iVar11;
    }
    FECarConfig__BuildRide(&DAT_0075eef8 + param_3 * 0x3e51,param_3,piVar9 + 4);
    puVar12 = *(undefined4 **)(param_2 + 8);
    *puVar12 = piVar9;
    *(int **)(param_2 + 8) = piVar9;
    piVar9[1] = (int)puVar12;
    *piVar9 = param_2 + 4;
  }
  if (DAT_00777b4c == 8) {
    iVar5 = piVar4[1];
  }
  else {
    iVar5 = *piVar4;
  }
  puVar12 = *(undefined4 **)(param_2 + 4);
  *(undefined4 **)(param_2 + 0xc) = puVar12;
  for (; puVar12 != (undefined4 *)(param_2 + 4); puVar12 = (undefined4 *)*puVar12) {
    if (puVar12[0x1ce] == iVar5) {
      *(undefined4 **)(param_2 + 0xc) = puVar12;
    }
  }
  iVar5 = *(int *)(*(int *)(param_2 + 0xc) + 0x738);
  if (DAT_00777b4c == 8) {
    piVar4[1] = iVar5;
  }
  else {
    *piVar4 = iVar5;
  }
  iVar5 = *(int *)(param_2 + 0xc);
  iVar8 = *(int *)(param_2 + 0x14);
  iVar11 = FUN_004b2330();
  puVar12 = (undefined4 *)&DAT_00748120;
  if (iVar8 != 1) {
    puVar12 = &DAT_00748850;
  }
  RideInfo__operator_(puVar12,iVar5 + 0x10);
  if (puVar12 == &DAT_00748850) {
    _DAT_0072cc80 = 1;
  }
  else if (puVar12 == (undefined4 *)&DAT_00748120) {
    _DAT_0072cc7c = 1;
  }
  if (iVar11 != 0) {
    GarageMainScreen__SetRideInfo(iVar11,puVar12,1);
  }
  return;
}


