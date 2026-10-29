// ==== 0x4c13b0 FUN_004c13b0

void FUN_004c13b0(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  bSPrintf_regdst(0x20,"OptionNameText_%d",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"OptionName_%d",param_1);
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar2 = 1;
    FEng__HashName(1);
    FUN_004f5f80(iVar1,uVar2);
  }
  FUN_00414a60();
  bSPrintf_regdst(0x20,"OptionText_%d",param_1);
  FUN_00414a60();
  if (param_2 != '\0') {
    bSPrintf_regdst(0x20,"OptionData_%d",param_1);
    FUN_00414a60();
  }
  return;
}


// ==== 0x4c1470 FUN_004c1470

void FUN_004c1470(void)

{
  bSPrintf_regdst(0x20,"LeftArrow_%d");
  FUN_00414a60();
  bSPrintf_regdst(0x20,"RightArrow_%d");
  FUN_00414a60();
  bSPrintf_regdst(0x20,"option_buttonL_0%d");
  FUN_00414a60();
  bSPrintf_regdst(0x20,"option_buttonR_0%d");
  FUN_00414a60();
  return;
}


// ==== 0x4c1500 FUN_004c1500

void FUN_004c1500(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1524:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b7f);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1524;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1524;
  }
  *(int *)(unaff_ESI + 0x234) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x274) = 0x1aec7d09;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1573:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c5);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1573;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1573;
  }
  *(int *)(unaff_ESI + 0x238) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x278) = 0x1aec7d09;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c15bd:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b80);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c15bd;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c15bd;
  }
  *(int *)(unaff_ESI + 0x23c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x27c) = 0x1aec7d0a;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c160c:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c6);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c160c;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c160c;
  }
  *(int *)(unaff_ESI + 0x240) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x280) = 0x1aec7d0a;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1656:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b81);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1656;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1656;
  }
  *(int *)(unaff_ESI + 0x244) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x284) = 0x1aec7d0b;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c16a5:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c7);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c16a5;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c16a5;
  }
  *(int *)(unaff_ESI + 0x248) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x288) = 0x1aec7d0b;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c16ef:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b82);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c16ef;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c16ef;
  }
  *(int *)(unaff_ESI + 0x24c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x28c) = 0x1aec7d0c;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c173e:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c8);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c173e;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c173e;
  }
  *(int *)(unaff_ESI + 0x250) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x290) = 0x1aec7d0c;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1788:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b83);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1788;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1788;
  }
  *(int *)(unaff_ESI + 0x254) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x294) = 0x1aec7d0d;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c17d7:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5c9);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c17d7;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c17d7;
  }
  *(int *)(unaff_ESI + 600) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x298) = 0x1aec7d0d;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1821:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b84);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1821;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1821;
  }
  *(int *)(unaff_ESI + 0x25c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x29c) = 0x1aec7d0e;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1870:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5ca);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1870;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1870;
  }
  *(int *)(unaff_ESI + 0x260) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x2a0) = 0x1aec7d0e;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c18ba:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b85);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c18ba;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c18ba;
  }
  *(int *)(unaff_ESI + 0x264) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x2a4) = 0x1aec7d0f;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1909:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01ed5cb);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1909;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1909;
  }
  *(int *)(unaff_ESI + 0x268) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x2a8) = 0x1aec7d0f;
  if (*(int *)(unaff_ESI + 0xc) == 0) {
LAB_004c1953:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xd01b8b86);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c1953;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c1953;
  }
  *(int *)(unaff_ESI + 0x26c) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x2ac) = 0x1aec7d10;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004c19cb;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xd01ed5cc);
    *(undefined4 *)(unaff_ESI + 0x2b0) = 0x1aec7d10;
    *(undefined4 *)(unaff_ESI + 0x270) = uVar2;
    return;
  }
  iVar1 = 0;
LAB_004c19cb:
  *(undefined4 *)(unaff_ESI + 0x2b0) = 0x1aec7d10;
  *(int *)(unaff_ESI + 0x270) = iVar1;
  return;
}


// ==== 0x4c19e0 FUN_004c19e0

void FUN_004c19e0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int local_8;
  
  piVar7 = (int *)(param_1 + 0x234);
  local_8 = 0x10;
  do {
    if (((*piVar7 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar4 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar4 != '\0')) {
      uVar1 = *(uint *)(*piVar7 + 0x10);
      if (uVar1 < 0xd01ed5cd) {
        if (uVar1 < 0xd01ed5c5) {
          if ((uVar1 < 0xd01b8b87) &&
             ((0xd01b8b7e < uVar1 || ((0x4acf8b8a < uVar1 && (uVar1 < 0x4acf8b8e)))))) {
            uVar2 = *(undefined4 *)(param_1 + 0x2b4);
            uVar5 = FUN_004f6670();
            if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
              FUN_004f0700(0x9120409e,*piVar7,uVar2,uVar5,0);
            }
          }
        }
        else {
LAB_004c1ae6:
          iVar3 = piVar7[0x10];
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
             (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
            if (DAT_0073578c == 0) goto LAB_004c1abc;
            iVar6 = FUN_004ef050(iVar3);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar7,*(undefined4 *)(param_1 + 0x2b4),iVar6,0);
          }
        }
      }
      else if ((0xd96a7802 < uVar1) && (uVar1 < 0xd96a7806)) goto LAB_004c1ae6;
    }
LAB_004c1abc:
    piVar7 = piVar7 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4c1b50 FUN_004c1b50

void FUN_004c1b50(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  DAT_00777cb8 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,0);
  } while (iVar1 < 3);
  (**(code **)(*(int *)(in_EAX + 0x100) + 0xc))(1);
  (**(code **)(*(int *)(in_EAX + 0xd0) + 0xc))(1);
  (**(code **)(*(int *)(in_EAX + 0x130) + 0xc))(1);
  *(undefined4 *)(in_EAX + 0x168) = 1;
  *(code **)(in_EAX + 0x48) = FUN_004be230;
  FUN_004bdfb0();
  *(undefined4 *)(in_EAX + 0x164) = 2;
  *(code **)(in_EAX + 0x4c) = FUN_004be0c0;
  FUN_004bdf40();
  *(undefined4 *)(in_EAX + 0x178) = 3;
  *(code **)(in_EAX + 0x50) = FUN_004be3a0;
  FUN_004be020();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  *(undefined4 *)(in_EAX + 0x160) = 1;
  *(undefined1 *)(in_EAX + 0x21c) = 0;
  return;
}


// ==== 0x4c1ca0 FUN_004c1ca0

void FUN_004c1ca0(void)

{
  int in_EAX;
  int iVar1;
  
  DAT_00777cb8 = 1;
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,0);
  } while (iVar1 < 2);
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004c1d02;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x39cac62);
  }
LAB_004c1d02:
  FEObject__SetVisible(iVar1);
  (**(code **)(*(int *)(in_EAX + 0x70) + 0xc))(1);
  *(undefined4 *)(in_EAX + 0x180) = 1;
  *(code **)(in_EAX + 0x48) = OptionsCameraUI;
  FUN_004be510();
  *(undefined4 *)(in_EAX + 0x184) = 2;
  *(code **)(in_EAX + 0x4c) = FUN_004be860;
  FUN_004be660();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  FUN_00414a60();
  *(undefined4 *)(in_EAX + 0x160) = 2;
  return;
}


// ==== 0x4c1dc0 FUN_004c1dc0

void FUN_004c1dc0(void)

{
  int iVar1;
  int unaff_ESI;
  
  DAT_00777cb8 = 2;
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      FUN_004c13b0(iVar1,1);
    } while (iVar1 < 2);
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      FUN_004c1470(unaff_ESI);
    } while (iVar1 < 2);
    *(undefined4 *)(unaff_ESI + 400) = 1;
    *(code **)(unaff_ESI + 0x48) = FUN_004beca0;
    FUN_004be9a0();
    *(undefined4 *)(unaff_ESI + 0x198) = 2;
    *(code **)(unaff_ESI + 0x4c) = FUN_004beec0;
    FUN_004beb80();
    *(undefined4 *)(unaff_ESI + 0x160) = 2;
    return;
  }
  FUN_004c13b0(1,1);
  FUN_004c1470(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x194) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bedb0;
  FUN_004bead0();
  *(undefined4 *)(unaff_ESI + 0x160) = 2;
  return;
}


// ==== 0x4c1e80 FUN_004c1e80

void FUN_004c1e80(void)

{
  int unaff_ESI;
  
  DAT_00777cb8 = 3;
  FUN_004c13b0(1,1);
  FUN_004c1470(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x19c) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bf0c0;
  FUN_004befd0();
  *(undefined4 *)(unaff_ESI + 0x160) = 4;
  return;
}


// ==== 0x4c1ed0 FUN_004c1ed0

void FUN_004c1ed0(void)

{
  int iVar1;
  int unaff_ESI;
  
  DAT_00777cb8 = 4;
  FUN_004c13b0(1,1);
  FUN_004c13b0(2,0);
  FUN_004c1470(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x1a4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bf4a0;
  FUN_004bf180();
  *(undefined4 *)(unaff_ESI + 0x1a8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bf770;
  FUN_004bf270();
  if (DAT_007361c4 == 1) {
    iVar1 = FUN_004cd610();
    if (((&DAT_007361b4)[iVar1] == 0) || (*(char *)((&DAT_007361b4)[iVar1] + 0x24) != '\x02'))
    goto LAB_004c1fa6;
    FUN_004c13b0(3,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1b0) = 3;
    *(code **)(unaff_ESI + 0x50) = FUN_004bf580;
    FUN_004bf2d0();
    if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) goto LAB_004c1fe2;
    FUN_004c13b0(4,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1b4) = 4;
    *(code **)(unaff_ESI + 0x54) = FUN_004bf610;
  }
  else {
LAB_004c1fa6:
    if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) goto LAB_004c1fe2;
    FUN_004c13b0(3,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1b4) = 3;
    *(code **)(unaff_ESI + 0x50) = FUN_004bf610;
  }
  FUN_004bf380();
LAB_004c1fe2:
  *(undefined4 *)(unaff_ESI + 0x160) = 5;
  *(undefined1 *)(unaff_ESI + 0x21c) = 0;
  return;
}


// ==== 0x4c2000 FUN_004c2000

void FUN_004c2000(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  DAT_00777cb8 = 5;
  iVar2 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar2 + 0x6c) == DAT_0078a2f0) goto LAB_004c203c;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  iVar2 = 0;
LAB_004c203c:
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
      if (((DAT_0078a30c == 1) && (DAT_0078a31c == 0)) && (DAT_0078a368 == 0)) {
        FUN_004c2230();
      }
      else if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0x74) & 4) == 0)) {
        if ((DAT_0078a310 == 0) || (DAT_0078a310 == 0x7fffffff)) {
          FUN_004c22c0();
        }
        else {
          FUN_004c2440();
        }
      }
      else {
        FUN_004c2390();
      }
    }
    else {
      FUN_004c20e0();
    }
  }
  else {
    FUN_004c2190();
  }
  *(undefined4 *)(in_EAX + 0x160) = 6;
  *(undefined1 *)(in_EAX + 0x21c) = 0;
  return;
}


// ==== 0x4c20e0 FUN_004c20e0

void FUN_004c20e0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 5);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c1470(unaff_ESI);
  } while (iVar1 < 5);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  *(undefined4 *)(unaff_ESI + 0x1b8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bfcb0;
  FUN_004bf7d0();
  *(undefined4 *)(unaff_ESI + 0x1c0) = 3;
  *(code **)(unaff_ESI + 0x50) = FUN_004bfe70;
  FUN_004bf9b0();
  *(undefined4 *)(unaff_ESI + 0x1bc) = 4;
  *(code **)(unaff_ESI + 0x54) = FUN_004bfd90;
  FUN_004bf8c0();
  *(undefined4 *)(unaff_ESI + 0x1c8) = 5;
  *(code **)(unaff_ESI + 0x58) = FUN_004c0090;
  FUN_004bfbc0();
  return;
}


// ==== 0x4c2190 FUN_004c2190

void FUN_004c2190(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 2);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c1470(unaff_ESI);
  } while (iVar1 < 2);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  *(undefined4 *)(unaff_ESI + 0x1b8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bfcb0;
  FUN_004bf7d0();
  if (DAT_0078a320 == 1) {
    FUN_004c13b0(3,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1c8) = 3;
    *(code **)(unaff_ESI + 0x50) = FUN_004c0090;
    FUN_004bfbc0();
    return;
  }
  return;
}


// ==== 0x4c2230 FUN_004c2230

void FUN_004c2230(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  FUN_004c13b0(1,1);
  FUN_004c1470(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  iVar1 = 0;
  iVar2 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar2 + 0x6c) == DAT_0078a2f0) {
        if ((*(byte *)(iVar2 + 0x74) & 4) != 0) {
          return;
        }
        FUN_004c13b0(2,1);
        FUN_004c1470(unaff_ESI);
        *(undefined4 *)(unaff_ESI + 0x1bc) = 2;
        *(code **)(unaff_ESI + 0x4c) = FUN_004bfd90;
        FUN_004bf8c0();
        return;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  return;
}


// ==== 0x4c22c0 FUN_004c22c0

void FUN_004c22c0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 4);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c1470(unaff_ESI);
  } while (iVar1 < 4);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  *(undefined4 *)(unaff_ESI + 0x1b8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bfcb0;
  FUN_004bf7d0();
  *(undefined4 *)(unaff_ESI + 0x1c0) = 3;
  *(code **)(unaff_ESI + 0x50) = FUN_004bfe70;
  FUN_004bf9b0();
  *(undefined4 *)(unaff_ESI + 0x1bc) = 4;
  *(code **)(unaff_ESI + 0x54) = FUN_004bfd90;
  FUN_004bf8c0();
  if (DAT_0078a320 == 1) {
    FUN_004c13b0(5,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1c8) = 5;
    *(code **)(unaff_ESI + 0x58) = FUN_004c0090;
    FUN_004bfbc0();
    return;
  }
  return;
}


// ==== 0x4c2390 FUN_004c2390

void FUN_004c2390(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 3);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c1470(unaff_ESI);
  } while (iVar1 < 3);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  *(undefined4 *)(unaff_ESI + 0x1b8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bfcb0;
  FUN_004bf7d0();
  *(undefined4 *)(unaff_ESI + 0x1c0) = 3;
  *(code **)(unaff_ESI + 0x50) = FUN_004bfe70;
  FUN_004bf9b0();
  if (DAT_0078a320 == 1) {
    FUN_004c13b0(4,1);
    FUN_004c1470(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1c8) = 4;
    *(code **)(unaff_ESI + 0x54) = FUN_004c0090;
    FUN_004bfbc0();
    return;
  }
  return;
}


// ==== 0x4c2440 FUN_004c2440

void FUN_004c2440(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 3);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c1470(unaff_ESI);
  } while (iVar1 < 3);
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004bff40;
  FUN_004bfaa0();
  *(undefined4 *)(unaff_ESI + 0x1b8) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004bfcb0;
  FUN_004bf7d0();
  *(undefined4 *)(unaff_ESI + 0x1c8) = 3;
  *(code **)(unaff_ESI + 0x50) = FUN_004c0090;
  FUN_004bfbc0();
  return;
}


// ==== 0x4c24c0 FUN_004c24c0

void FUN_004c24c0(void)

{
  int iVar1;
  int unaff_ESI;
  
  DAT_00777cb8 = 7;
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004c13b0(iVar1,1);
  } while (iVar1 < 7);
  *(undefined4 *)(unaff_ESI + 0x1cc) = 1;
  *(code **)(unaff_ESI + 0x48) = FUN_004c0600;
  FUN_004c0180();
  *(undefined4 *)(unaff_ESI + 0x1b4) = 2;
  *(code **)(unaff_ESI + 0x4c) = FUN_004c06b0;
  FUN_004c0270();
  *(undefined4 *)(unaff_ESI + 0x1d4) = 3;
  *(code **)(unaff_ESI + 0x50) = FUN_004c09b0;
  FUN_004c0300();
  *(undefined4 *)(unaff_ESI + 0x1d8) = 4;
  *(code **)(unaff_ESI + 0x54) = FUN_004c0740;
  FUN_004c03b0();
  *(undefined4 *)(unaff_ESI + 0x1dc) = 5;
  *(code **)(unaff_ESI + 0x58) = FUN_004c07c0;
  FUN_004c0420();
  *(undefined4 *)(unaff_ESI + 0x1e0) = 6;
  *(code **)(unaff_ESI + 0x5c) = FUN_004c0840;
  FUN_004c0490();
  *(undefined4 *)(unaff_ESI + 0x1e4) = 7;
  *(code **)(unaff_ESI + 0x60) = FUN_004c08c0;
  FUN_004c0500();
  *(undefined4 *)(unaff_ESI + 0x160) = 6;
  *(undefined1 *)(unaff_ESI + 0x21c) = 0;
  return;
}


// ==== 0x4c25a0 FUN_004c25a0

void __fastcall FUN_004c25a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c56b8;
  FUN_004f7b50();
  return;
}


// ==== 0x4c25b0 FUN_004c25b0

void * __thiscall FUN_004c25b0(void *param_1,byte param_2)

{
  FUN_004c25a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c25d0 Screen_MU_PauseOptionsSelector::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_PauseOptionsSelector__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687c93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_PauseOptionsSelector__Screen_MU_PauseOptionsSelector(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c2630 Screen_MU_PauseOptionsSelector::Screen_MU_PauseOptionsSelector

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_PauseOptionsSelector__Screen_MU_PauseOptionsSelector
          (undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_EDX;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar1 = DAT_007361f0;
  *param_1 = &PTR_FUN_006c56b8;
  param_1[0x10] = 0;
  iVar1 = *(int *)(iVar1 + 0x1c);
  local_4 = 0;
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else if (iVar1 == 1) {
    uVar2 = 2;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else {
    uVar2 = (iVar1 != 3) - 1 & 8;
  }
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = uVar2;
  }
  iVar1 = DAT_0073578c;
  bVar3 = DAT_0073578c != 0;
  DAT_00777cb8 = 0xffffffff;
  param_1[0x10] = DAT_0073ad3c;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  if (bVar3) {
    uVar4 = 0;
    FEng__HashName(0);
    FUN_004f5f80(iVar1,uVar4);
  }
  FUN_00414a10();
  FUN_00414a10();
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    if (((param_1[3] == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
       (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
      if (DAT_0073578c == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004ef050(0xcda0a66d);
      }
    }
    FEObject__SetVisible(iVar1);
    if (extraout_EDX == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    uVar4 = 1;
    iVar1 = extraout_EDX;
  }
  else {
    iVar1 = param_1[3];
    uVar4 = FEng__HashName();
    if (((iVar1 == 0) ||
        ((iVar1 = FUN_004f65d0(), iVar1 == 0 || (iVar1 = FUN_004ffb70(), iVar1 == 0)))) &&
       (DAT_0073578c != 0)) {
      FUN_004ef050(uVar4);
    }
    iVar1 = DAT_0073578c;
    FUN_004f75b0(0xff404040);
    if (iVar1 == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    uVar4 = 0;
    FEng__HashName(0);
    FUN_004f5f80(iVar1,uVar4);
    if (DAT_0073578c == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    uVar4 = 0;
    iVar1 = DAT_0073578c;
  }
  FUN_004f5f80(iVar1,uVar4);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4c2830 FUN_004c2830

void __thiscall FUN_004c2830(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 < 0xb5af2462) {
    if (param_2 == 0xb5af2461) {
      if ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1) {
        *(undefined1 *)(param_1 + 0x45) = 1;
        return;
      }
    }
    else if ((param_2 == 0xc407210) || (param_2 == 0x406415e3)) {
      if ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1) {
        uVar1 = *(uint *)(param_3 + 0x10);
        if (uVar1 < 0x2a053c7) {
          if (uVar1 == 0x2a053c6) {
            DAT_00777cb8 = 7;
          }
          else if (uVar1 == 0x9955) {
            DAT_00777cb8 = 2;
          }
          else if (uVar1 == 0xb120) {
            DAT_00777cb8 = 5;
          }
          else {
            if (uVar1 != 0x272d751) {
              return;
            }
            DAT_00777cb8 = 0;
          }
        }
        else if (uVar1 == 0x368a0075) {
          DAT_00777cb8 = 4;
        }
        else if (uVar1 == 0x541307a8) {
          DAT_00777cb8 = 1;
        }
        else {
          if (uVar1 != 0x7f007e43) {
            return;
          }
          DAT_00777cb8 = 3;
        }
        uVar3 = FUN_004fa080();
        FEManager__PushPackageChecked(0x14,uVar3);
        iVar2 = FUN_004f65d0();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0;
          return;
        }
      }
    }
    else if (((param_2 == 0x911ab364) && (iVar2 = int_NotEqual(&DAT_0073ad3c), iVar2 != 0)) &&
            ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1)) {
      *(undefined1 *)(param_1 + 0x44) = 1;
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
      FEManager__PushPackageChecked(0x32,0);
    }
    if (*(char *)(param_1 + 0x44) != '\0') {
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
    }
    if (*(char *)(param_1 + 0x45) != '\0') {
      FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
      FUN_00421c00(DAT_007361f0,6,1);
    }
  }
  else if (param_2 == 0xf2d0d887) {
    uVar3 = FUN_004fa080();
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = uVar3;
    }
    *(undefined4 *)(param_1 + 0x40) = DAT_0073ad3c;
    return;
  }
  return;
}


// ==== 0x4c2a50 GetCarModelNameHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GetCarModelNameHash(void)

{
  int in_EAX;
  undefined *puVar1;
  
  puVar1 = (undefined *)(in_EAX * 0xc90 + DAT_00734588);
  if (*(int *)(puVar1 + 0xc50) == 0xf) {
    if (DAT_00734998 == 0) {
      FUN_004f42f0("CAR_MODEL_NAME_%s%s",puVar1,&DAT_006c7680);
      return;
    }
    if (DAT_00734998 == 2) {
      FUN_004f42f0("CAR_MODEL_NAME_%s%s",puVar1,"_KOREA");
      return;
    }
    if (((DAT_00734998 == 1) || (DAT_00734998 == 5)) || (DAT_00734998 == 4)) {
      FUN_004f42f0("CAR_MODEL_NAME_%s%s",puVar1,"_EUROPE");
      return;
    }
  }
  else if ((*(int *)(puVar1 + 0xc50) == 2) &&
          ((((DAT_00734998 == 1 || (DAT_00734998 == 2)) || (DAT_00734998 == 5)) ||
           (DAT_00734998 == 4)))) {
    puVar1 = &DAT_006c5680;
  }
  FUN_004f42f0("CAR_MODEL_NAME_%s%s",puVar1,&DAT_006b9172);
  return;
}


// ==== 0x4c2b00 GetSecondaryLogoHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void __fastcall GetSecondaryLogoHash(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(param_2 * 0xc90 + DAT_00734588);
  if (DAT_00734998 != 0) {
    if (param_2 == 0xe) {
      FUN_004f42f0("SECONDARY_LOGO_%s%s",puVar1,"_HONDA");
      return;
    }
    if (param_2 == 0xf) {
      if (DAT_00734998 == 2) {
        FUN_004f42f0("SECONDARY_LOGO_%s%s","TUSCANI",&DAT_006b9172);
        return;
      }
      if (((DAT_00734998 == 1) || (DAT_00734998 == 5)) || (DAT_00734998 == 4)) {
        FUN_004f42f0("SECONDARY_LOGO_%s%s","COUPE",&DAT_006b9172);
        return;
      }
    }
    else if ((param_2 == 2) &&
            ((((DAT_00734998 == 2 || (DAT_00734998 == 1)) || (DAT_00734998 == 5)) ||
             (DAT_00734998 == 4)))) {
      puVar1 = &DAT_006c5680;
    }
  }
  FUN_004f42f0("SECONDARY_LOGO_%s%s",puVar1,&DAT_006b9172);
  return;
}


// ==== 0x4c2bc0 FUN_004c2bc0

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


// ==== 0x4c2c90 FUN_004c2c90

void FUN_004c2c90(undefined4 param_1)

{
  int unaff_ESI;
  
  RideInfo__Init();
  *(undefined4 *)(unaff_ESI + 0x734) = 0;
  *(undefined4 *)(unaff_ESI + 0x738) = 0;
  *(undefined4 *)(unaff_ESI + 0x730) = param_1;
  return;
}


// ==== 0x4c2cc0 FUN_004c2cc0

int __fastcall FUN_004c2cc0(int param_1)

{
  undefined4 in_EAX;
  
  FUN_004c2c90(in_EAX);
  RideInfo__Init();
  *(undefined1 *)(param_1 + 0xe60) = 0;
  *(undefined4 *)(param_1 + 0xe64) = 0;
  return param_1;
}


// ==== 0x4c2cf0 FUN_004c2cf0

int FUN_004c2cf0(undefined4 param_1)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0xe60) == '\0') {
    FUN_004c2d20(param_1);
    *(undefined1 *)(in_EAX + 0xe60) = 1;
  }
  return in_EAX + 0x740;
}


// ==== 0x4c2d20 FUN_004c2d20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c2d20(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int unaff_EBX;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte local_20;
  byte local_1f [31];
  
  iVar2 = unaff_EBX + 0x740;
  Ride_Init(1,0,0);
  FUN_00565da0("DUMMY_SKIN%d",1);
  iVar6 = -1;
  pbVar7 = &local_20;
  bVar3 = local_20;
  while (bVar3 != 0) {
    iVar6 = iVar6 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    bVar3 = *pbVar1;
  }
  *(int *)(unaff_EBX + 0xb84) = iVar6;
  FUN_00565da0("DUMMY_WHEEL%d",1);
  iVar6 = -1;
  pbVar7 = &local_20;
  while (local_20 != 0) {
    pbVar1 = pbVar7 + 1;
    iVar6 = iVar6 * 0x21 + (uint)local_20;
    pbVar7 = pbVar7 + 1;
    local_20 = *pbVar1;
  }
  *(int *)(unaff_EBX + 0xb88) = iVar6;
  FUN_0057d340(iVar2);
  FUN_0057e9a0(iVar2);
  iVar6 = CarPartDatabase__GetCarPart
                    (0,0x1e,*(undefined4 *)(*(int *)(unaff_EBX + 0x730) + 0xc5c),0,0xffffffff);
  if (iVar6 != 0) {
    *(int *)(unaff_EBX + 0xc04) = iVar6;
    *(char *)(unaff_EBX + 0xd8a) = *(char *)(unaff_EBX + 0xd8a) + '\x01';
    RideInfo__UpdatePartsEnabled(iVar2);
  }
  if (*(char *)(unaff_EBX + 0xb64) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  *(undefined4 *)(unaff_EBX + 0x734) = *(undefined4 *)(unaff_EBX + 0xb68);
  puVar8 = (undefined4 *)(param_1 + 8);
  puVar9 = (undefined4 *)(unaff_EBX + 0x748);
  for (iVar6 = 0x16; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  RideInfo__RebuildPhysicsInfo(1);
  FUN_0057fb80(iVar2,param_1);
  if (*(char *)(param_1 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar4 = *(float *)(param_1 + 0x428) - _DAT_006f0d58;
  fVar5 = _DAT_006f0d5c - _DAT_006f0d58;
  if (*(char *)(unaff_EBX + 0xb64) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  *(float *)(unaff_EBX + 0xe64) =
       ((fVar4 * 10.0) / fVar5 -
       ((*(float *)(unaff_EBX + 0xb68) - _DAT_006f0d58) * 10.0) / (_DAT_006f0d5c - _DAT_006f0d58)) *
       3500.0;
  return;
}


// ==== 0x4c2ed0 FUN_004c2ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c2ed0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688a8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c55dc;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,param_1 + 0x24);
  bVar3 = false;
  if (DAT_00735e6c == (void *)0x0) {
    pvVar4 = _malloc(0xe40);
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)0x0;
    }
    else {
      RideInfo__Init();
      RideInfo__Init();
    }
    bVar3 = true;
    DAT_00735e6c = pvVar4;
  }
  FUN_004c3240(param_1);
  if (bVar3) {
    param_1[0x12] = *puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
    puVar6 = puVar2;
    if (puVar2 != puVar1) {
      puVar5 = puVar2;
      do {
        puVar6 = puVar5;
        if (*(int *)(puVar5[0x1cc] + 0xc50) == *(int *)((int)DAT_00735e6c + 0x720)) break;
        puVar5 = (undefined4 *)*puVar5;
        puVar6 = puVar2;
      } while (puVar5 != puVar1);
    }
    param_1[0x12] = puVar6;
  }
  iVar7 = param_1[0x12];
  if (*(char *)(iVar7 + 0xe60) == '\0') {
    FUN_004c2d20(param_1 + 0x24);
    *(undefined1 *)(iVar7 + 0xe60) = 1;
  }
  RideInfo__operator_(&DAT_00745000,iVar7 + 0x740);
  iVar7 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745000);
  _DAT_0072cc80 = 2;
  if (iVar7 != 0) {
    GarageMainScreen__SetRideInfo(iVar7,&DAT_00748850,2);
  }
  FUN_004c3120();
  FUN_004f8960();
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 == 0) || (*(int *)(iVar7 + 0x18) == 0)) && (DAT_00777b4c != 4)) {
    FEngPushGarageMainPackage();
  }
  FUN_004b2480();
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_10;
  return;
}


// ==== 0x4c30b0 FUN_004c30b0

void * __thiscall FUN_004c30b0(void *param_1,byte param_2)

{
  FUN_004c30d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c30d0 FUN_004c30d0

void __fastcall FUN_004c30d0(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c55dc;
  FUN_004f84d0();
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


// ==== 0x4c3120 FUN_004c3120

void FUN_004c3120(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EBX;
  char local_100 [256];
  
  uVar2 = FUN_004f42f0("BRAND_NAME_%s",*(int *)(*(int *)(unaff_EBX + 0x48) + 0x730) + 0xc0);
  FUN_00495f00(uVar2);
  uVar2 = GetSecondaryLogoHash();
  FUN_004ad7b0(uVar2);
  if (0.0 <= *(float *)(*(int *)(unaff_EBX + 0x48) + 0xe64)) {
    iVar3 = LanguageStrings__FindByHash();
    if (iVar3 == 0) {
      iVar3 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x100;
    pcVar4 = local_100;
    do {
      cVar1 = pcVar4[iVar3 - (int)local_100];
      iVar5 = iVar5 + -1;
      *pcVar4 = cVar1;
      if (cVar1 == '\0') break;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 != 0);
    iVar3 = _ftol_nocw();
  }
  else {
    iVar3 = LanguageStrings__FindByHash();
    if (iVar3 == 0) {
      iVar3 = LanguageStrings__FindByHash();
    }
    iVar5 = 0x100;
    pcVar4 = local_100;
    do {
      cVar1 = pcVar4[iVar3 - (int)local_100];
      iVar5 = iVar5 + -1;
      *pcVar4 = cVar1;
      if (cVar1 == '\0') break;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 != 0);
    iVar3 = _ftol_nocw();
    iVar3 = -iVar3;
  }
  FUN_004f6850(local_100,iVar3);
  return;
}


// ==== 0x4c3230 FUN_004c3230

bool FUN_004c3230(uint param_1,uint param_2)

{
  return param_1 <= param_2;
}


// ==== 0x4c3240 FUN_004c3240

void FUN_004c3240(int param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  
  iVar7 = 0;
  do {
    iVar5 = DAT_00734588 + iVar7;
    if ((((iVar5 != 0) && (*(char *)(iVar5 + 0x40) != '\0')) && (*(int *)(iVar5 + 0xc54) == 0)) &&
       ((cVar2 = Career__IsCarUnlocked(), cVar2 != '\0' &&
        (iVar3 = FECarConfig__GetCarType(), iVar3 != *(int *)(iVar5 + 0xc50))))) {
      pvVar4 = _malloc(0xe70);
      if (pvVar4 != (void *)0x0) {
        FUN_004c2cc0();
      }
      FUN_00564940(param_1 + 0x40,FUN_004c3230);
    }
    iVar7 = iVar7 + 0xc90;
  } while (iVar7 < 0x1b7b0);
  piVar8 = *(int **)(param_1 + 0x40);
  if (piVar8 != (int *)(param_1 + 0x40)) {
    do {
      iVar7 = *(int *)(piVar8[0x1cc] + 0xc50);
      if (((iVar7 == 0x13) || (iVar7 == 0x11)) || ((iVar7 == 0x12 || (iVar7 == 0x10)))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      iVar7 = FUN_004f8730(param_1 + 0x4c,iVar7,0,!bVar1);
      iVar5 = *(int *)(piVar8[0x1cc] + 0xc50) * 0xc90 + DAT_00734588;
      pcVar6 = (char *)(iVar5 + 0xc0);
      if ((DAT_00734998 != 0) && (*(int *)(iVar5 + 0xc50) == 0xe)) {
        pcVar6 = "HONDA";
      }
      iVar5 = FUN_004f42f0("CARSELECT_MANUFACTURER_%s",pcVar6);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != iVar5)) {
        *(int *)(iVar7 + 0x24) = iVar5;
        *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
      }
      piVar8 = (int *)*piVar8;
    } while (piVar8 != (int *)(param_1 + 0x40));
  }
  return;
}


// ==== 0x4c3390 FUN_004c3390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c3390(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x48);
  if (param_1 == -0x6edfbf62) {
    if (puVar1 == *(undefined4 **)(unaff_EDI + 0x40)) goto LAB_004c33b7;
    uVar3 = puVar1[1];
  }
  else {
    if ((param_1 != -0x4a68e40f) || (puVar1 == *(undefined4 **)(unaff_EDI + 0x44)))
    goto LAB_004c33b7;
    uVar3 = *puVar1;
  }
  *(undefined4 *)(unaff_EDI + 0x48) = uVar3;
LAB_004c33b7:
  if (puVar1 != *(undefined4 **)(unaff_EDI + 0x48)) {
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
    iVar2 = *(int *)(unaff_EDI + 0x48);
    if (*(char *)(iVar2 + 0xe60) == '\0') {
      FUN_004c2d20(unaff_EDI + 0x90);
      *(undefined1 *)(iVar2 + 0xe60) = 1;
    }
    RideInfo__operator_(&DAT_00745000,iVar2 + 0x740);
    iVar2 = FUN_004b2330();
    RideInfo__operator_(&DAT_00748850,&DAT_00745000);
    _DAT_0072cc80 = 2;
    if (iVar2 != 0) {
      GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
    }
    FUN_004c3120();
    FUN_004f8910();
  }
  return;
}


// ==== 0x4c3480 FUN_004c3480

void __thiscall FUN_004c3480(int param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  float10 extraout_ST0;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 != 0xc407210) {
        if (param_2 != 0x911ab364) {
          return;
        }
        _free(DAT_00735e6c);
        DAT_00735e6c = (void *)0x0;
        GarageManager__SyncActualToEditing(0);
        GarageManager__PopScreen();
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if ((*(float *)(*(int *)(param_1 + 0x48) + 0xe64) < 0.0) &&
         (iVar2 = Career__GetCash(&DAT_0075eef8), (float10)iVar2 < extraout_ST0)) {
        local_10 = 0x639;
        local_14 = 0x444ad5e4;
        local_c = 0;
        FUN_004dcbe0(&local_14,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      uVar3 = FUN_004c2cf0(param_1 + 0x90);
      pvVar1 = DAT_00735e6c;
      RideInfo__operator_((int)DAT_00735e6c + 0x720,uVar3);
      RideInfo__operator_(pvVar1,param_1 + 0x90);
      DAT_00745e4c = 1;
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    if (-1 < DAT_006f0fb8) {
      DAT_006f0fb8 = -1;
      FUN_005824b0(&DAT_00748850);
    }
    FUN_004f89d0();
    FUN_004f7d30();
    return;
  }
  FUN_004c3390();
  return;
}


// ==== 0x4c3610 FUN_004c3610

undefined4 FUN_004c3610(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688ba3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x7b0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004c2ed0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c3670 FUN_004c3670

undefined4 * FUN_004c3670(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = &PTR_FUN_006c55cc;
  FUN_00495f00(0x14012d64);
  FUN_00495f00(0x639);
  FUN_00495f00(0x541389e5);
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4c3700 FUN_004c3700

void * __thiscall FUN_004c3700(void *param_1,byte param_2)

{
  FUN_004c3720();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c3720 FUN_004c3720

void __fastcall FUN_004c3720(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c55cc;
  FUN_004f7b50();
  return;
}


// ==== 0x4c3730 FUN_004c3730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c3730(void)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(DAT_00735e6c + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if (*(char *)(DAT_00735e6c + 0xb44) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar2 = DAT_00735e6c + 0x720;
  FECarConfig__FillFromRide(&DAT_0075eef8,iVar2);
  iVar1 = _ftol_nocw();
  DAT_0076026c = DAT_0076026c - iVar1;
  DAT_00760274 = DAT_00760274 + iVar1;
  FECarConfig__FillFromRide(DAT_00744ff8,iVar2);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
  }
  return;
}


// ==== 0x4c3860 FUN_004c3860

int __thiscall FUN_004c3860(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0xc407210) {
    param_2 = 0;
    if (param_3 != 0) {
      if (*(int *)(param_3 + 0x10) == -0x47583934) {
        FUN_004c3730(param_1);
        _free(DAT_00735e6c);
        DAT_00735e6c = (void *)0x0;
        GarageManager__PopScreen();
        GarageManager__PopScreen();
        GarageManager__PopScreen();
        iVar1 = FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return iVar1;
      }
      GarageManager__PopScreen();
      GarageManager__PopScreen();
      param_2 = FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
    }
  }
  else if (param_2 == -0x6ee54c9c) {
    GarageManager__PopScreen();
    iVar1 = DAT_0073578c;
    param_2 = *(int *)(param_1 + 0xc);
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      param_2 = 0;
      if ((iVar2 != 0) && (param_2 = 0, *(int *)(iVar2 + 0x18) != 0)) {
        iVar1 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
        return iVar1;
      }
    }
  }
  else if (param_2 == -0x367ca946) {
    iVar1 = FUN_004f7d30();
    return iVar1;
  }
  return param_2;
}


// ==== 0x4c388e FUN_004c388e

undefined4 FUN_004c388e(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  uVar3 = *(undefined4 *)(unaff_ESI + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if ((iVar2 != 0) && (uVar3 = 0, *(int *)(iVar2 + 0x18) != 0)) {
      uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      return uVar3;
    }
  }
  return uVar3;
}


// ==== 0x4c393b FUN_004c393b

void FUN_004c393b(void)

{
  int unaff_ESI;
  
  GarageManager__PopScreen();
  GarageManager__PopScreen();
  FUN_004f6360(*(undefined4 *)(unaff_ESI + 0xc));
  return;
}


// ==== 0x4c3970 FUN_004c3970

undefined4 FUN_004c3970(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006882d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004c3670(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c39d0 FUN_004c39d0

void __thiscall FUN_004c39d0(int param_1,int param_2)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if (((param_1 == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(in_EAX);
    if (iVar2 == 0) {
      return;
    }
  }
  pcVar3 = *(char **)(iVar2 + 0x24);
  iVar4 = 0x100;
  param_2 = param_2 - (int)pcVar3;
  do {
    cVar1 = pcVar3[param_2];
    iVar4 = iVar4 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar4 != 0);
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  return;
}


// ==== 0x4c3a40 Screen_MU_UG_MovieTheaterViewer::Screen_MU_UG_MovieTheaterViewer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_MovieTheaterViewer__Screen_MU_UG_MovieTheaterViewer
          (undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c5488;
  *(undefined1 *)(param_1 + 0x10) = 0;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  iVar3 = DAT_0073578c;
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) &&
      (bVar5 = DAT_0073578c != 0, *(undefined1 *)(param_1 + 0x10) = 1, bVar5)) &&
     ((iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0 && (*(int *)(iVar1 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar3 + 8),*(int *)(iVar1 + 0x18));
  }
  pcVar4 = "";
  if (DAT_006faefc == 6) {
    pcVar4 = "DRIFT";
  }
  else if (DAT_006faefc == 5) {
    pcVar4 = "ENG_DRAG";
  }
  uVar2 = GetLocalizedLogoMovie(pcVar4);
  FUN_004c39d0(uVar2);
  if ((4 < DAT_006ee6f0) && (DAT_006ee6f0 < 9)) {
    if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x58d36da2);
      }
    }
    FEObject__SetVisible(iVar3);
    if (((((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
         (iVar3 = FUN_004ffb70(), iVar3 == 0)) &&
        ((DAT_0073578c == 0 || (iVar3 = FUN_004ef050(0x58d36da2), iVar3 == 0)))) ||
       (*(int *)(iVar3 + 0x18) != 2)) {
      iVar3 = 0;
    }
    DAT_00733f2c = iVar3;
    DAT_00733f30 = MovieSubtitles__FindByName(pcVar4);
    DAT_00733f28 = 0xffffffff;
    _DAT_00733f40 = timeGetTime();
    FEObject__SetFormattedText(&DAT_006b9172);
    ExceptionList = local_c;
    return param_1;
  }
  if ((param_1[3] == 0) ||
     ((iVar3 = FUN_004f65d0(), iVar3 == 0 || (iVar3 = FUN_004ffb70(), iVar3 == 0)))) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x58d36da2);
    }
  }
  FEObject__SetInvisible(iVar3);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4c3c40 FUN_004c3c40

void * __thiscall FUN_004c3c40(void *param_1,byte param_2)

{
  FUN_004c3c60();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c3c60 FUN_004c3c60

void __fastcall FUN_004c3c60(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c5488;
  local_4 = 0;
  if (*(char *)(param_1 + 0x10) != '\0') {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) {
      FEngPushGarageMainPackage();
    }
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4c3cd0 Screen_MU_UG_MovieTheaterViewer::NotificationMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __thiscall Screen_MU_UG_MovieTheaterViewer__NotificationMessage(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_0073578c;
  if (param_2 < 0xc3960eba) {
    if (((param_2 == 0xc3960eb9) || (param_2 == 0x406415e3)) || (param_2 == 0x911ab364)) {
      param_2 = *(uint *)(param_1 + 0xc);
      if (DAT_0073578c != 0) {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        param_2 = 0;
        if ((iVar2 != 0) && (param_2 = 0, *(int *)(iVar2 + 0x18) != 0)) {
          uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
          return uVar3;
        }
      }
    }
  }
  else if (((param_2 == 0xc98356ba) && (param_2 = DAT_006ee6f0, 4 < (int)DAT_006ee6f0)) &&
          ((int)DAT_006ee6f0 < 9)) {
    param_2 = MovieSubtitles__Update();
  }
  return param_2;
}


// ==== 0x4c3d00 FUN_004c3d00

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


// ==== 0x4c3d50 Screen_MU_UG_MovieTheaterViewer::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_MovieTheaterViewer__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687c73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_MovieTheaterViewer__Screen_MU_UG_MovieTheaterViewer(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c3db0 Screen_MU_UG_ChooseCareerCar::Screen_MU_UG_ChooseCareerCar

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_ChooseCareerCar__Screen_MU_UG_ChooseCareerCar(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688a8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c5460;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)(param_1 + 0x22) = 0;
  param_1[0x24] = 0;
  param_1[0x23] = 0x78;
  *(undefined1 *)(param_1 + 0x25) = 0;
  param_1[0x26] = 0x3c;
  param_1[0x27] = 0;
  FUN_004c42d0(param_1);
  iVar3 = param_1[0x12];
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,iVar3 + 0x10);
  _DAT_0072cc80 = 2;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  if (DAT_00777b4c == 4) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
    }
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
    }
  }
  FUN_004b2480();
  FUN_004c44c0();
  *(undefined1 *)(param_1 + 8) = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x56aa7e46,0,0,*(int *)(iVar3 + 0x18));
  }
  if ((DAT_0076029c & 0x200000) == 0) {
    iVar3 = 0;
    do {
      if ((&DAT_006fa7f0)[iVar3 * 2] == 0x200000) {
        if (*(int *)(iVar3 * 8 + 0x6fa7f4) == -1) {
          ExceptionList = local_10;
          return param_1;
        }
        EAXSound__PlaySpeechStream(0xffffffff);
        DAT_0076029c = DAT_0076029c | 0x200000;
        ExceptionList = local_10;
        return param_1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x19);
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4c3fd0 FUN_004c3fd0

void * __thiscall FUN_004c3fd0(void *param_1,byte param_2)

{
  FUN_004c3ff0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c3ff0 FUN_004c3ff0

void __fastcall FUN_004c3ff0(undefined4 *param_1)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688cbe;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c5460;
  local_4 = 2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x645e01df,0,0,*(int *)(iVar2 + 0x18));
  }
  FUN_004f84d0();
  _Memory = (int *)param_1[0x10];
  while (_Memory != param_1 + 0x10) {
    iVar2 = *_Memory;
    piVar1 = (int *)_Memory[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(_Memory);
    _Memory = (int *)param_1[0x10];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c40a0 _unknown_garage_screen_::NotificationMessage

/* [canon] car low (ghidra+hopper) docs/re/tuning.md */

void __thiscall _unknown_garage_screen___NotificationMessage(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0xb5971bf2) {
    if (param_2 == 0xb5971bf1) {
LAB_004c40c6:
      FUN_004c4560(param_2);
      return;
    }
    if (param_2 == 0xc407210) {
      if (((DAT_0076029c & 0x200000) != 0) && ((DAT_0076029c & 0x400000) == 0)) {
        iVar1 = EAXSound__UpdateSongInfo();
        if (iVar1 == 0) {
          iVar1 = FUN_004cd440();
          if (iVar1 != -1) {
            EAXSound__PlaySpeechStream(0xffffffff);
            DAT_0076029c = DAT_0076029c | 0x400000;
            *(undefined1 *)(param_1 + 0x88) = 1;
            iVar1 = FUN_004f65d0();
            if (iVar1 != 0) {
              *(undefined4 *)(iVar1 + 0x1c) = 0;
              return;
            }
          }
        }
      }
    }
    else if (param_2 == 0x9120409e) goto LAB_004c40c6;
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004f89d0();
    FUN_004f7d30();
    if ((*(char *)(param_1 + 0x88) != '\0') &&
       (iVar1 = *(int *)(param_1 + 0x90) + 1, *(int *)(param_1 + 0x90) = iVar1,
       *(int *)(param_1 + 0x8c) < iVar1)) {
      iVar1 = EAXSound__UpdateSongInfo();
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x94) = 1;
      }
    }
    if ((*(char *)(param_1 + 0x94) != '\0') && (*(int *)(param_1 + 0x98) < *(int *)(param_1 + 0x9c))
       ) {
      FUN_005a2540();
      Ugd__Write(&DAT_0078a478,"auto");
      Settings__Save();
      FUN_004b2410();
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 1;
  }
  return;
}


// ==== 0x4c4154 FUN_004c4154

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
      iVar1 = EAXSound__UpdateSongInfo();
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


// ==== 0x4c4230 FUN_004c4230

void FUN_004c4230(void)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EDI;
  
  iVar5 = in_EAX * 0xc90 + DAT_00734588;
  Ride_Init(1,0,0);
  pcVar4 = "DUMMY_SKIN1";
  iVar3 = -1;
  uVar2 = 0x44;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  *(int *)(unaff_EDI + 0x444) = iVar3;
  pcVar4 = "DUMMY_WHEEL1";
  iVar3 = -1;
  uVar2 = 0x44;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  *(int *)(unaff_EDI + 0x448) = iVar3;
  FUN_0057d340(unaff_EDI);
  iVar3 = CarPartDatabase__GetCarPart(0,0x1e,*(undefined4 *)(iVar5 + 0xc5c),0,0xffffffff);
  if (iVar3 != 0) {
    *(int *)(unaff_EDI + 0x4c4) = iVar3;
    *(char *)(unaff_EDI + 0x64a) = *(char *)(unaff_EDI + 0x64a) + '\x01';
    RideInfo__UpdatePartsEnabled();
    return;
  }
  return;
}


// ==== 0x4c42d0 FUN_004c42d0

void FUN_004c42d0(int param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int *piVar10;
  int local_4;
  
  local_4 = 0;
  do {
    pcVar9 = (char *)(local_4 + DAT_00734588);
    if (((pcVar9 != (char *)0x0) && (pcVar9[0x40] != '\0')) && (*(int *)(pcVar9 + 0xc54) == 0)) {
      cVar4 = *pcVar9;
      pcVar8 = pcVar9;
      while (cVar4 != '\0') {
        pcVar1 = pcVar8 + 1;
        pcVar8 = pcVar8 + 1;
        cVar4 = *pcVar1;
      }
      cVar4 = Career__IsCarUnlocked();
      if (cVar4 != '\0') {
        piVar5 = _malloc(0x740);
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          RideInfo__Init();
          piVar5[0x1cc] = (int)pcVar9;
          piVar5[0x1cd] = 0;
          piVar5[0x1ce] = 0;
        }
        FUN_004c4230(param_1);
        if ((char)piVar5[0x10d] == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        piVar5[0x1cd] = piVar5[0x10e];
        puVar2 = *(undefined4 **)(param_1 + 0x44);
        *puVar2 = piVar5;
        *(int **)(param_1 + 0x44) = piVar5;
        piVar5[1] = (int)puVar2;
        *piVar5 = param_1 + 0x40;
      }
    }
    local_4 = local_4 + 0xc90;
  } while (local_4 < 0x1b7b0);
  piVar5 = (int *)(param_1 + 0x40);
  bList__Sort(piVar5,FUN_004c2bc0);
  piVar10 = (int *)*piVar5;
  if (piVar10 != piVar5) {
    do {
      iVar6 = *(int *)(piVar10[0x1cc] + 0xc50);
      if (((iVar6 == 0x13) || (iVar6 == 0x11)) || ((iVar6 == 0x12 || (iVar6 == 0x10)))) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      iVar6 = FUN_004f8730(param_1 + 0x4c,iVar6,0,!bVar3);
      iVar7 = *(int *)(piVar10[0x1cc] + 0xc50) * 0xc90 + DAT_00734588;
      pcVar9 = (char *)(iVar7 + 0xc0);
      if ((DAT_00734998 != 0) && (*(int *)(iVar7 + 0xc50) == 0xe)) {
        pcVar9 = "HONDA";
      }
      iVar7 = FUN_004f42f0("CARSELECT_MANUFACTURER_%s",pcVar9);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != iVar7)) {
        *(int *)(iVar6 + 0x24) = iVar7;
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
      piVar10 = (int *)*piVar10;
    } while (piVar10 != (int *)(param_1 + 0x40));
  }
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x40);
  FUN_004f8960();
  return;
}


// ==== 0x4c44c0 FUN_004c44c0

void FUN_004c44c0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EBX;
  char local_20 [32];
  
  pcVar4 = local_20;
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  iVar5 = 0x20;
  do {
    cVar1 = pcVar4[iVar2 - (int)local_20];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  FUN_004f6850("%s %d",local_20,
               *(undefined4 *)(*(int *)(*(int *)(unaff_EBX + 0x48) + 0x730) + 0xc7c));
  uVar3 = GetSecondaryLogoHash();
  FUN_004ad7b0(uVar3);
  return;
}


// ==== 0x4c4556 FUN_004c4556

/* WARNING: Control flow encountered bad instruction data */

void FUN_004c4556(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x4c4558 FUN_004c4558

/* WARNING: Control flow encountered bad instruction data */

void FUN_004c4558(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x4c4560 FUN_004c4560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c4560(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  if (param_1 == -0x6edfbf62) {
    if (puVar1 != *(undefined4 **)(in_EAX + 0x40)) {
      *(undefined4 *)(in_EAX + 0x48) = puVar1[1];
    }
  }
  else if ((param_1 == -0x4a68e40f) && (puVar1 != *(undefined4 **)(in_EAX + 0x44))) {
    *(undefined4 *)(in_EAX + 0x48) = *puVar1;
  }
  puVar2 = *(undefined4 **)(in_EAX + 0x48);
  if (puVar2 != puVar1) {
    iVar3 = FUN_004b2330();
    RideInfo__operator_(&DAT_00748850,puVar2 + 4);
    _DAT_0072cc80 = 1;
    if (iVar3 != 0) {
      GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,1);
    }
    FUN_004f8910();
    FUN_004c44c0();
    if (param_1 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x4c4640 Screen_MU_UG_ChooseCareerCar::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_ChooseCareerCar__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006894b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_ChooseCareerCar__Screen_MU_UG_ChooseCareerCar(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c46a0 Screen_MU_UG_MapScreen::Screen_MU_UG_MapScreen

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_UG_MapScreen__Screen_MU_UG_MapScreen(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006891f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_FUN_006c52f0;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_4 = 1;
  *(undefined1 *)(param_1 + 0x14) = 0;
  FUN_004b2410();
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar3 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar3 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar3 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar3 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar2 = *(int *)(DAT_0073578c + 8);
    iVar3 = iVar2 + 0xdc;
    if (iVar3 != 0) {
      iVar3 = FUN_004fd1e0(iVar3);
      if (iVar3 != 0) goto LAB_004c47d3;
    }
    cFEng__PushPackage(iVar2,"MU_TrackMapScroller.fng",0xf,0);
  }
LAB_004c47d3:
  param_1[0x10] = 0;
  FUN_004c4a60(param_1);
  *(undefined1 *)(param_1 + 8) = 1;
  DAT_0073570c = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4c4810 FUN_004c4810

void * __thiscall FUN_004c4810(void *param_1,byte param_2)

{
  FUN_004c4830();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c4830 FUN_004c4830

void __fastcall FUN_004c4830(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687343;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c52f0;
  local_4 = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 && (*(int *)(iVar3 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
  }
  DAT_0073570c = 0;
  if (DAT_0073578c != 0) {
    FUN_004f6010(DAT_0073578c);
  }
  FUN_00567000(DAT_00735708);
  if ((undefined4 *)param_1[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10])(1);
  }
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c4920 EventMap::SetModeIcon

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

void EventMap__SetModeIcon(void)

{
  int in_EAX;
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = "";
  pcVar2 = "";
  if (*(int *)(*(int *)(in_EAX + 8) + 4) == 1) {
    pcVar2 = "_TOURNAMENT";
  }
  switch(*(undefined4 *)(*(int *)(in_EAX + 8) + 8)) {
  case 0:
    FUN_004f42f0("MODE_ICON_%s%s","CIRCUIT",pcVar2);
    return;
  case 1:
    FUN_004f42f0("MODE_ICON_%s%s",&DAT_006c6544,pcVar2);
    return;
  case 2:
    FUN_004f42f0("MODE_ICON_%s%s","SPRINT",pcVar2);
    return;
  case 3:
    FUN_004f42f0("MODE_ICON_%s%s","DRIFT",pcVar2);
    return;
  case 4:
    pcVar1 = "TIME_TRIAL";
    break;
  case 5:
    FUN_004f42f0("MODE_ICON_%s%s","LAP_KNOCKOUT",pcVar2);
    return;
  }
  FUN_004f42f0("MODE_ICON_%s%s",pcVar1,pcVar2);
  return;
}


// ==== 0x4c49f0 EventMap::GetModeLabelHash

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

undefined4 EventMap__GetModeLabelHash(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 4) != 1) {
    switch(*(undefined4 *)(in_EAX + 8)) {
    case 0:
      return 0xe8e55af1;
    case 1:
      return 0x7a19a47c;
    case 2:
      return 0x89f7493e;
    case 3:
      return 0xbd4e5637;
    case 4:
      return 0x61cffe8;
    case 5:
      return 0x789301b4;
    default:
      return 0;
    }
  }
  return 0xe2c9114b;
}


// ==== 0x4c4a60 FUN_004c4a60

void FUN_004c4a60(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int *piStack_40;
  uint auStack_3c [12];
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar5 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00688a63;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)(param_1 + 0x40))(1);
  }
  pvVar6 = _malloc(0x3c);
  uStack_4 = 0;
  if (pvVar6 == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_004f8370(pvVar6,"master_thumb","thumb");
  }
  piVar1 = (int *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x40) = uVar7;
  piVar8 = (int *)*piVar1;
  uStack_4 = 0xffffffff;
  while (piVar8 != piVar1) {
    piVar8 = (int *)*piVar1;
    iVar10 = *piVar8;
    piVar2 = (int *)piVar8[1];
    *piVar2 = iVar10;
    *(int **)(iVar10 + 4) = piVar2;
    _free(piVar8);
    piVar8 = (int *)*piVar1;
  }
  puVar11 = auStack_3c;
  for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar11 = 0xffffffff;
    puVar11 = puVar11 + 1;
  }
  Career__RefreshOpenEvents(auStack_3c);
  piStack_40 = (int *)0x0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  param_1 = 0;
  do {
    uVar3 = auStack_3c[param_1];
    if (((0 < (int)uVar3) && (uVar3 < 0x100)) && (iVar10 = (&DAT_00733ff8)[uVar3], iVar10 != 0)) {
      piVar8 = _malloc(0xc);
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8[2] = iVar10;
      }
      if (*(int *)(iVar10 + 4) == 8) {
        piStack_40 = piVar8;
      }
      puVar4 = *(undefined4 **)(iVar5 + 0x48);
      *puVar4 = piVar8;
      *(int **)(iVar5 + 0x48) = piVar8;
      piVar8[1] = (int)puVar4;
      *piVar8 = (int)piVar1;
      iVar10 = FUN_004f8730(*(undefined4 *)(iVar5 + 0x40),piVar8,0,1);
      iVar9 = EventMap__SetModeIcon(iVar5);
      if ((iVar10 != 0) && (*(int *)(iVar10 + 0x24) != iVar9)) {
        *(int *)(iVar10 + 0x24) = iVar9;
        *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x400000;
      }
    }
    param_1 = param_1 + 1;
  } while (param_1 < 0xc);
  if (piStack_40 == (int *)0x0) {
    piStack_40 = (int *)*piVar1;
  }
  else {
    *(undefined1 *)(iVar5 + 0x50) = 1;
  }
  *(int **)(iVar5 + 0x4c) = piStack_40;
  FUN_004f8960();
  EventMap__ShowEventSummary(iVar5);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c4be0 FUN_004c4be0

void FUN_004c4be0(void)

{
  undefined4 *puVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x4c);
  if (unaff_EBX == -0x6edfbf62) {
    if (puVar1 != *(undefined4 **)(unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x4c) = puVar1[1];
    }
  }
  else if ((unaff_EBX == -0x4a68e40f) && (puVar1 != *(undefined4 **)(unaff_EDI + 0x48))) {
    *(undefined4 *)(unaff_EDI + 0x4c) = *puVar1;
  }
  if (*(undefined4 **)(unaff_EDI + 0x4c) != puVar1) {
    FUN_004f8910();
    EventMap__ShowEventSummary(unaff_EDI);
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
  }
  return;
}


// ==== 0x4c4c60 EventMap::ShowEventSummary

/* [canon] canon med (ghidra) docs/re/canon.md */

void EventMap__ShowEventSummary(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char local_180 [128];
  char local_100 [256];
  
  iVar4 = *(int *)(param_1 + 0x4c);
  uVar3 = EventMap__GetModeLabelHash(param_1);
  FUN_00495f00(uVar3);
  FUN_004bbc90((int)*(char *)(*(int *)(iVar4 + 8) + 0x7b));
  if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
     (uVar3 = DAT_0076026c, DAT_0073440c != '\0')) {
    uVar3 = 1000000000;
  }
  FUN_004f6850("Cash: %d",uVar3);
  uVar3 = _ftol_nocw();
  FUN_004f6850("Entry Fee: %d",uVar3);
  uVar3 = FUN_004f42f0("EVENT_%d_TITLE",**(undefined4 **)(iVar4 + 8));
  FUN_00495f00(uVar3);
  iVar6 = *(int *)(*(int *)(iVar4 + 8) + 8);
  if (((iVar6 != 0) && (iVar6 != 3)) && (iVar6 != 5)) {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c4df0:
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(0xc73329b8);
      }
    }
    else {
      iVar4 = FUN_004f65d0();
      if (iVar4 == 0) goto LAB_004c4df0;
      iVar4 = FUN_004ffb70();
      if (iVar4 == 0) goto LAB_004c4df0;
    }
    FEObject__SetInvisible(iVar4);
    goto LAB_004c4e12;
  }
  cVar1 = *(char *)(*(int *)(iVar4 + 8) + 0x7a);
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x80;
  pcVar5 = local_180;
  do {
    cVar2 = pcVar5[iVar4 - (int)local_180];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar2;
    if (cVar2 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  FUN_004f6850(local_180,(int)cVar1);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c4da4:
    if (DAT_0073578c != 0) {
      uVar3 = FUN_004ef050(0xc73329b8);
      FEObject__SetVisible(uVar3);
      goto LAB_004c4e12;
    }
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_004f65d0();
    if (iVar4 == 0) goto LAB_004c4da4;
    iVar4 = FUN_004ffb70();
    if (iVar4 == 0) goto LAB_004c4da4;
  }
  FEObject__SetVisible(iVar4);
LAB_004c4e12:
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x100;
  pcVar5 = local_100;
  do {
    cVar1 = pcVar5[iVar4 - (int)local_100];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  uVar3 = Career__CountFinishedEvents(0x6f);
  FUN_004f6850(local_100,uVar3);
  return;
}


// ==== 0x4c4e90 Screen_MU_UG_MapScreen::SummonEventBriefing

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Screen_MU_UG_MapScreen__SummonEventBriefing(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    if ((*(int *)(in_EAX + 0xc) == 0) ||
       (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),uVar3,0xff);
    return;
  }
  return;
}


// ==== 0x4c4ee0 Screen_MU_UG_MapScreen::EventHasFMV

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined4 Screen_MU_UG_MapScreen__EventHasFMV(void)

{
  int in_EAX;
  
  if (((in_EAX != 7) && (in_EAX != 0xf)) && (in_EAX != 0x5c)) {
    return 0;
  }
  return 1;
}


// ==== 0x4c4f00 Screen_MU_UG_MapScreen::SummonNewCareerFMV

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Screen_MU_UG_MapScreen__SummonNewCareerFMV(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0073578c;
  DAT_00735dc8 = **(undefined4 **)(*(int *)(in_EAX + 0x4c) + 8);
  if (DAT_0073578c != 0) {
    if ((*(int *)(in_EAX + 0xc) == 0) ||
       (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x18);
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),uVar3,0xff);
    return;
  }
  return;
}


// ==== 0x4c4f50 FUN_004c4f50

void __thiscall FUN_004c4f50(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  
  if (param_2 < 0x9795550f) {
    if (param_2 == 0x9795550e) {
      FUN_00414a60();
      FUN_004f6bd0(&DAT_006c7a3c,1);
      FUN_004f6bd0(&DAT_006c7a3c,1);
      FUN_004f6bd0(&DAT_006c7a3c,1);
      return;
    }
    if (0x911ab364 < param_2) {
      if (param_2 != 0x9120409e) {
        return;
      }
LAB_004c501a:
      FUN_004c4be0();
      return;
    }
    if (param_2 == 0x911ab364) {
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0xc407210) {
      if (param_2 != 0x12344321) {
        return;
      }
      FUN_004c4a60(param_1);
      return;
    }
    FUN_00414a10();
    FUN_004f6bd0(&DAT_006c619c,1);
    FUN_004f6bd0(&DAT_006c619c,1);
    cVar1 = Screen_MU_UG_MapScreen__EventHasFMV();
    if (cVar1 != '\0') {
      Screen_MU_UG_MapScreen__SummonNewCareerFMV();
      return;
    }
  }
  else {
    if (param_2 != 0xaabbddcc) {
      if (param_2 != 0xb5971bf1) {
        if (param_2 != 0xc98356ba) {
          return;
        }
        FUN_004f89d0();
        FUN_004f7d30();
        return;
      }
      goto LAB_004c501a;
    }
    FEManager__PushPackageChecked(1,0);
    if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
       (*(int *)(iVar2 + 0x18) != 0)) {
      FUN_004f09b0(*(int *)(iVar2 + 0x18));
    }
  }
  Screen_MU_UG_MapScreen__SummonEventBriefing();
  return;
}


// ==== 0x4c5100 Screen_MU_UG_MapScreen::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_MapScreen__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689493;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x54);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_MapScreen__Screen_MU_UG_MapScreen(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c5160 FUN_004c5160

void __fastcall FUN_004c5160(undefined4 *param_1)

{
  int *piVar1;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c52e0;
  local_4 = 0;
  if (DAT_0073578c != 0) {
    *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xd0) = 2;
  }
  if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0xa0))();
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c51e0 FUN_004c51e0

void * __thiscall FUN_004c51e0(void *param_1,byte param_2)

{
  FUN_004c5160();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c5200 FUN_004c5200

undefined4 FUN_004c5200(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x13:
    return 0xb;
  default:
    return 0;
  case 0x19:
    return 2;
  case 0x25:
    return 0x23;
  case 0x28:
  case 0x56:
    return 0xd;
  case 0x37:
    return 0x22;
  case 0x3b:
    return 0xc;
  case 0x66:
    return 0x25;
  case 0x70:
    return 0x11;
  }
}


// ==== 0x4c52d0 FUN_004c52d0

undefined4 FUN_004c52d0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 6:
    return 0x2e;
  case 7:
    return 0x17;
  default:
    return 0xffffffff;
  case 0xf:
    return 0x2f;
  case 0x1a:
    return 0x19;
  case 0x2f:
  case 0x44:
    return 0x34;
  case 0x4d:
    return 0x3b;
  case 0x55:
    return 0x1d;
  case 0x61:
    return 0x1f;
  case 0x70:
    return 0x3d;
  }
}


// ==== 0x4c53c0 Screen_MU_UG_EventBriefing::Screen_MU_UG_EventBriefing

/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_EventBriefing__Screen_MU_UG_EventBriefing(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined *puVar7;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar4 = DAT_007356a8;
  *param_1 = &PTR_FUN_006c52e0;
  local_4 = 0;
  if ((*(int *)(iVar4 + 0x104) != 0) &&
     (piVar6 = *(int **)(*(int *)(iVar4 + 0x104) + 0x24), piVar6 != (int *)0x0)) {
    (**(code **)(*piVar6 + 0xa0))();
  }
  if (DAT_0073578c != 0) {
    *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xd0) = 0;
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x14);
  }
  iVar1 = *(int *)(iVar4 + 0x4c);
  param_1[0x10] = iVar1;
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(iVar4 + 0x50);
  iVar4 = *(int *)(*(int *)(iVar1 + 8) + 0x74);
  iVar5 = 0;
  if (0 < iVar4) {
    piVar6 = (int *)(*(int *)(iVar1 + 8) + 0x38);
    do {
      if (*piVar6 == 1) {
        uVar2 = 1;
        goto LAB_004c546f;
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 3;
    } while (iVar5 < iVar4);
  }
  uVar2 = 0;
LAB_004c546f:
  *(undefined1 *)(param_1 + 0x13) = uVar2;
  *(undefined1 *)((int)param_1 + 0x4e) = 0;
  *(undefined1 *)((int)param_1 + 0x4d) = 0;
  iVar4 = *(int *)(*(int *)(iVar1 + 8) + 4);
  if ((iVar4 == 3) || (iVar4 == 2)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  *(char *)(param_1 + 0x11) = cVar3;
  param_1[0x12] = (cVar3 == '\0') + 1;
  if (0 < **(int **)(iVar1 + 8)) {
    iVar4 = 0;
    do {
      if ((&DAT_006fa5d0)[iVar4 * 2] == **(int **)(iVar1 + 8)) {
        if (*(int *)(iVar4 * 8 + 0x6fa5d4) != -1) {
          EAXSound__PlaySpeechStream(0xffffffff);
          cVar3 = '\x01';
          goto LAB_004c54c1;
        }
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2d);
  }
  cVar3 = '\0';
LAB_004c54c1:
  *(char *)((int)param_1 + 0x4f) = cVar3;
  if (cVar3 == '\0') {
    if (*(char *)(param_1 + 0x13) == '\0') {
      if (*(char *)((int)param_1 + 0x4d) == '\0') goto LAB_004c55c1;
      iVar4 = FUN_004c52d0();
      if (iVar4 != -1) {
        EAXSound__PlaySpeechStream(0xffffffff);
      }
    }
    else {
      iVar4 = FUN_004c5200();
      if ((0 < iVar4) && (*(int *)(DAT_007356a8 + 0x104) != 0)) {
        puVar7 = (undefined *)0x0;
        if (0 < iVar4) {
          puVar7 = (&PTR_s_Fabolous_006f8728)[iVar4 * 2];
        }
        piVar6 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24);
        if (puVar7 == (undefined *)0xffffffff) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(*piVar6 + 0x90))(0x59);
          }
        }
        else if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 0x98))(0x59,puVar7);
        }
        if ((0.2 < *(float *)(*(int *)(DAT_007356a8 + 8) + 4)) && (DAT_007356ac != 0)) {
          EAXMix_SetupAllTypes(0xbf800000);
        }
      }
    }
    *(undefined1 *)((int)param_1 + 0x4e) = 1;
  }
LAB_004c55c1:
  DAT_00735e60 = 0;
  Briefing__Build();
  param_1[0x15] = 0;
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4c55f0 Briefing::GetHostName

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

char * Briefing__GetHostName(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x9db972a4) {
    if (in_EAX == 0x9db972a3) {
      return "Dirt";
    }
    if (in_EAX < 0x4fdc36fe) {
      if (in_EAX == 0x4fdc36fd) {
        return "Samantha";
      }
      if (in_EAX == 0x26cbb5b) {
        return "Klutch";
      }
      if (in_EAX == 0x1784e6a4) {
        return "TJ";
      }
    }
    else {
      if (in_EAX == 0x54f6e4eb) {
        return "Eddie";
      }
      if (in_EAX == 0x9db8dfc0) {
        return "Chad";
      }
    }
  }
  else if (in_EAX < 0x9dc2505c) {
    if (in_EAX == 0x9dc2505b) {
      return "Todd";
    }
    if (in_EAX == 0x9dbcd681) {
      return "Jose";
    }
    if (in_EAX == 0x9dbd7c56) {
      return "Kurt";
    }
  }
  else if (in_EAX == 0xd8fbe4de) {
    return "Melissa";
  }
  return "";
}


// ==== 0x4c5680 Briefing::Build

/* [canon] canon med (ghidra) docs/re/canon.md */

void Briefing__Build(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(char *)(in_EAX + 0x44) == '\0') || (*(int *)(in_EAX + 0x48) != 1)) {
    if (DAT_0073578c != 0) {
      FUN_004f5f80(DAT_0073578c,0);
      if (DAT_0073578c != 0) {
        FUN_004f5f80(DAT_0073578c,0);
      }
    }
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c57d9:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x4f876b6f);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c57d9;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c57d9;
    }
    FEObject__SetInvisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5820:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x2c119933);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5820;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5820;
    }
    FEObject__SetInvisible(iVar3);
    if (DAT_0073578c != 0) {
      FUN_004f5f80(DAT_0073578c,1);
      if (DAT_0073578c != 0) {
        FUN_004f5f80(DAT_0073578c,1);
        if (DAT_0073578c != 0) {
          FUN_004f5f80(DAT_0073578c,1);
        }
      }
    }
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c58b2:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x14dd31);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c58b2;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c58b2;
    }
    FEObject__SetVisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c58f9:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x6baa2200);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c58f9;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c58f9;
    }
    FEObject__SetVisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5940:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x16821e);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5940;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5940;
    }
    FEObject__SetVisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5987:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x64ddfdff);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5987;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5987;
    }
    FEObject__SetVisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c59ce:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x22ad620e);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c59ce;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c59ce;
    }
    FEObject__SetVisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5a15:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x3434e0ac);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5a15;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5a15;
    }
    FEObject__SetVisible(iVar3);
  }
  else {
    if (DAT_0073578c != 0) {
      FUN_004f5f80(DAT_0073578c,1);
      if (DAT_0073578c != 0) {
        FUN_004f5f80(DAT_0073578c,1);
      }
    }
    FUN_00495fc0();
    FUN_00495fc0();
    if (DAT_0073578c != 0) {
      FUN_004f5f80(DAT_0073578c,0);
      if (DAT_0073578c != 0) {
        FUN_004f5f80(DAT_0073578c,0);
        if (DAT_0073578c != 0) {
          FUN_004f5f80(DAT_0073578c,0);
        }
      }
    }
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
    FUN_00495f70();
  }
  puVar1 = *(undefined4 **)(*(int *)(in_EAX + 0x40) + 8);
  FUN_004f6850("Event %d",*puVar1);
  uVar2 = _ftol_nocw();
  FUN_004f6850(&DAT_006ca778,uVar2);
  uVar2 = _ftol_nocw();
  FUN_004f6850(&DAT_006ca778,uVar2);
  uVar2 = _ftol_nocw();
  FUN_004f6850(&DAT_006ca778,uVar2);
  uVar2 = FUN_004ad6d0((int)*(char *)((int)puVar1 + 0x7b));
  FUN_00495f00(uVar2);
  if (puVar1[0x4c] == 0) {
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5bb3:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x4e31ee9f);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5bb3;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5bb3;
    }
    FEObject__SetInvisible(iVar3);
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5bfa:
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x2e8af64);
      }
    }
    else {
      iVar3 = FUN_004f65d0();
      if (iVar3 == 0) goto LAB_004c5bfa;
      iVar3 = FUN_004ffb70();
      if (iVar3 == 0) goto LAB_004c5bfa;
    }
    FEObject__SetInvisible(iVar3);
    goto LAB_004c5c1f;
  }
  if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5af6:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x2e8af64);
    }
  }
  else {
    iVar3 = FUN_004f65d0();
    if (iVar3 == 0) goto LAB_004c5af6;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004c5af6;
  }
  FEObject__SetVisible(iVar3);
  if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004c5b3d:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x4e31ee9f);
    }
  }
  else {
    iVar3 = FUN_004f65d0();
    if (iVar3 == 0) goto LAB_004c5b3d;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004c5b3d;
  }
  FEObject__SetVisible(iVar3);
  FUN_004ad7b0(puVar1[0x4c]);
  uVar2 = Briefing__GetHostName();
  FUN_004f6850(uVar2);
LAB_004c5c1f:
  Briefing__ShowDescription(in_EAX,DAT_0075f240);
  uVar2 = FUN_004f42f0("EVENT_%d_REWARD_BLURB",*puVar1);
  FUN_00495f00(uVar2);
  return;
}


// ==== 0x4c5c60 FUN_004c5c60

void __fastcall FUN_004c5c60(undefined4 param_1,int param_2)

{
  if ((*(char *)(param_2 + 0x44) == '\0') || (*(int *)(param_2 + 0x48) != 1)) {
    if (DAT_0075f240 == 0) {
      if (DAT_0073578c != 0) {
        FUN_004f5ed0(DAT_0073578c);
      }
    }
    else if ((DAT_0075f240 == 1) || (DAT_0075f240 != 2)) {
      if (DAT_0073578c != 0) {
        FUN_004f5ed0(DAT_0073578c);
        return;
      }
    }
    else if (DAT_0073578c != 0) {
      FUN_004f5ed0(DAT_0073578c);
      return;
    }
  }
  else if (DAT_0073578c != 0) {
    FUN_004f5ed0(DAT_0073578c);
    return;
  }
  return;
}


// ==== 0x4c5ce0 Briefing::ShowDescription

/* [canon] canon med (ghidra) docs/re/canon.md */

void Briefing__ShowDescription(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined1 local_220 [32];
  char local_200 [512];
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x40) + 8);
  uVar3 = FUN_004f42f0("EVENT_%d_DESCRIPTION",*puVar2);
  if (puVar2[2] != 4) {
    FUN_00495f00(uVar3);
    return;
  }
  _ftol_nocw();
  FUN_00586690(0x3f800000);
  _ftol_nocw();
  FUN_00586580(local_220);
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x200;
  pcVar5 = local_200;
  do {
    cVar1 = pcVar5[iVar4 - (int)local_200];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  FUN_004f6850(local_200,local_220);
  return;
}


// ==== 0x4c5df0 FUN_004c5df0

undefined4 __thiscall FUN_004c5df0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  DAT_0075f240 = 0;
  if (iVar2 == 0x14dd31) {
    DAT_0075f240 = 0;
  }
  else if (iVar2 == 0x16821e) {
    DAT_0075f240 = 2;
  }
  else if (iVar2 == 0x6baa2200) {
    DAT_0075f240 = 1;
  }
  piVar1 = *(int **)(*(int *)(param_2 + 0x40) + 8);
  iVar2 = *piVar1;
  Career__StartEvent();
  FUN_004dfa10();
  if (((((char)piVar1[0x2b] == '\0') || (iVar2 == 7)) || (iVar2 == 0xf)) || (iVar2 == 0x5c)) {
    uVar4 = Career__StartRaceFromEvent();
  }
  else {
    uVar4 = *(undefined4 *)(param_2 + 0xc);
    if (DAT_0073578c != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
        FUN_004f09b0(*(int *)(iVar2 + 0x18));
      }
      iVar2 = DAT_0073578c;
      uVar4 = 0;
      if (DAT_0073578c != 0) {
        iVar3 = FEPackageList__FindByName(&DAT_00746104);
        uVar4 = 0;
        if ((iVar3 != 0) && (uVar4 = 0, *(int *)(iVar3 + 0x18) != 0)) {
          uVar4 = FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
          return uVar4;
        }
      }
    }
  }
  return uVar4;
}


// ==== 0x4c5ee0 FUN_004c5ee0

void FUN_004c5ee0(void)

{
  uint uVar1;
  int in_EAX;
  
  uVar1 = **(uint **)(*(int *)(in_EAX + 0x40) + 8);
  if (((0xff < uVar1) || ((&DAT_00733ff8)[uVar1] == 0)) &&
     ((DAT_007677a8 == 0 ||
      (((uint *)(DAT_007677a8 + 0x58a0) == (uint *)0x0 ||
       (uVar1 != *(uint *)(DAT_007677a8 + 0x58a0))))))) {
    uRam00000000 = 4;
    return;
  }
  (&DAT_0075f244)[uVar1] = 4;
  return;
}


// ==== 0x4c5f20 Briefing::HasRequiredRideRating

/* [canon] canon high (capstone+ghidra+hopper) docs/re/canon.md */

int Briefing__HasRequiredRideRating(void)

{
  int iVar1;
  int in_EAX;
  undefined2 extraout_var;
  uint3 uVar2;
  float10 fVar3;
  float10 fVar4;
  undefined1 local_730 [1836];
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x40) + 8);
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_730);
  fVar3 = (float10)CalculateRideReputationPoints();
  fVar4 = (float10)*(int *)(iVar1 + 0x18);
  uVar2 = (uint3)(CONCAT22(extraout_var,
                           (ushort)(fVar4 < fVar3) << 8 | (ushort)(NAN(fVar4) || NAN(fVar3)) << 10 |
                           (ushort)(fVar4 == fVar3) << 0xe) >> 8);
  if (fVar4 >= fVar3 && (fVar4 == fVar3) == 0) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}


// ==== 0x4c5f80 FUN_004c5f80

undefined4 FUN_004c5f80(void)

{
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x50) != '\0') &&
     (*(int *)(*(int *)(*(int *)(in_EAX + 0x40) + 8) + 4) != 8)) {
    return 1;
  }
  return 0;
}


// ==== 0x4c5fa0 FUN_004c5fa0

void __thiscall FUN_004c5fa0(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_100 [256];
  
  if (param_2 < 0xaaddddab) {
    if (param_2 == 0xaaddddaa) {
      FUN_004c5df0(param_1);
      return;
    }
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        if ((*(char *)(param_1 + 0x44) != '\0') && (*(int *)(param_1 + 0x48) == 2)) {
          *(undefined4 *)(param_1 + 0x48) = 1;
          Briefing__Build();
          FUN_004c5c60();
          return;
        }
        FUN_004c96c0(0x9795550e);
        FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xc407210) {
        if ((*(char *)(param_1 + 0x44) != '\0') && (*(int *)(param_1 + 0x48) == 1)) {
          if (*(int *)(param_3 + 0x10) == 0x4f876b6f) {
            *(undefined4 *)(param_1 + 0x48) = 2;
            Briefing__Build();
            FUN_004c5c60();
            return;
          }
          if (*(int *)(param_3 + 0x10) == 0x2c119933) {
            FUN_004c5ee0();
            FUN_004c96c0(0x12344321);
            iVar2 = FUN_004f4270();
            *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar2 + 0x4c);
            FUN_004c96c0(0x9795550e);
            FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
          }
          Briefing__Build();
          FUN_004c5c60();
          return;
        }
        cVar1 = Briefing__HasRequiredRideRating(param_3);
        if (cVar1 == '\0') {
          uStack_10c = 0x639;
          uStack_110 = 0x92ca3bd9;
          uStack_108 = 0;
          FUN_004dcbe0(&uStack_110,"GenericOKDialogMedium.fng",*(undefined4 *)(param_1 + 0xc));
          uVar3 = FUN_0059fc40(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 8) + 0x18));
          bSPrintf_regdst(0x100,uVar3);
          FUN_004dccc0(auStack_100);
          return;
        }
        cVar1 = FUN_004c5f80();
        if (cVar1 != '\0') {
          uStack_10c = 0x639;
          uStack_110 = 0x9837c6f6;
          uStack_108 = 0;
          FUN_004dcbe0(&uStack_110,"GenericOKDialogMedium.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 8) + 4) == 1) &&
           (cVar1 = FECareerManager__AreAllUnlockedPhysicsUpgradesPurchased(), cVar1 == '\0')) {
          uStack_10c = 0x639;
          uStack_110 = 0xc00999e5;
          uStack_108 = 0;
          FUN_004dcbe0(&uStack_110,"GenericOKDialogMedium.fng",*(undefined4 *)(param_1 + 0xc));
          return;
        }
        DAT_00748f78 = FUN_004fa050();
        FUN_004c5df0(param_1);
        return;
      }
      if (param_2 == 0x70d6a9cf) {
        FUN_004c5c60();
        return;
      }
    }
    else if (param_2 == 0x9120409e) {
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (param_2 == 0xabc08912) {
    iVar2 = *(int *)(param_3 + 0x10);
    if (iVar2 != 0x14dd31) {
      if (iVar2 == 0x16821e) {
        Briefing__ShowDescription(param_1,2);
        return;
      }
      if (iVar2 == 0x6baa2200) {
        Briefing__ShowDescription(param_1,1);
        return;
      }
    }
    Briefing__ShowDescription(param_1,0);
  }
  else {
    if (param_2 == 0xb5971bf1) {
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if ((((((param_2 == 0xc98356ba) &&
           (DAT_00735e60 = DAT_00735e60 + 1, DAT_006fae28 < DAT_00735e60)) &&
          (*(char *)(param_1 + 0x4e) == '\0')) &&
         ((iVar2 = EAXSound__UpdateSongInfo(), *(char *)(param_1 + 0x4f) != '\0' &&
          (*(char *)(param_1 + 0x4e) == '\0')))) &&
        ((*(char *)(param_1 + 0x4c) != '\0' || (*(char *)(param_1 + 0x4d) != '\0')))) &&
       (iVar2 == 0)) {
      if (*(char *)(param_1 + 0x4c) == '\0') {
        iVar2 = FUN_004c52d0();
        if (iVar2 != -1) {
          EAXSound__PlaySpeechStream(0xffffffff);
        }
      }
      else {
        iVar2 = FUN_004c5200();
        if (0 < iVar2) {
          EAXSound__PlaySpeechStream(iVar2);
          *(undefined1 *)(param_1 + 0x4e) = 1;
          return;
        }
      }
      *(undefined1 *)(param_1 + 0x4e) = 1;
      return;
    }
  }
  return;
}


// ==== 0x4c6400 Screen_MU_UG_EventBriefing::Create

/* [canon] canon med (capstone) docs/re/gameflow.md */

undefined4 Screen_MU_UG_EventBriefing__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006882b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x58);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_EventBriefing__Screen_MU_UG_EventBriefing(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c6460 FUN_004c6460

void __fastcall FUN_004c6460(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c52b8;
  FUN_004f84d0();
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


// ==== 0x4c64b0 FUN_004c64b0

void * __thiscall FUN_004c64b0(void *param_1,byte param_2)

{
  FUN_004c6460();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c64d0 FUN_004c64d0

undefined4 FUN_004c64d0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006891d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004c6530(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c6530 FUN_004c6530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004c6530(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688a8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c52b8;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"car_thumb3","car_thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  param_1[0x22] = 0;
  FUN_004c66d0(param_1);
  iVar3 = param_1[0x12];
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,iVar3 + 0x10);
  _DAT_0072cc80 = 1;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,1);
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) {
    if (DAT_00777b4c != 4) {
      FEngPushGarageMainPackage();
      goto LAB_004c65f5;
    }
  }
  else {
LAB_004c65f5:
    if (DAT_00777b4c != 4) {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
      }
      goto LAB_004c6661;
    }
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
  }
LAB_004c6661:
  FUN_004b2480();
  GetCarManufacturerNameHash();
  param_1[0x22] = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar3 + 0x18));
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4c66d0 FUN_004c66d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c66d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  int *piVar10;
  undefined *local_10;
  int local_c;
  undefined *local_8;
  
  local_c = 0;
  if (0 < DAT_0075ee00) {
    local_8 = &DAT_0075ac60;
    iVar7 = DAT_00734588;
    do {
      if (((int)local_8 < 0x75ac60) || (local_10 = local_8, 0x75edff < (int)local_8)) {
        local_10 = (undefined *)0x0;
      }
      iVar5 = 0;
      piVar8 = (int *)(iVar7 + 0xd0);
      do {
        if (*piVar8 == *(int *)(local_10 + 8)) {
          iVar5 = iVar5 * 0xc90 + iVar7;
          goto LAB_004c6742;
        }
        iVar5 = iVar5 + 1;
        piVar8 = piVar8 + 0x324;
      } while (iVar5 < 0x23);
      iVar5 = 0;
LAB_004c6742:
      iVar5 = *(int *)(iVar5 + 0xc50) * 0xc90 + iVar7;
      if (iVar5 != 0) {
        uVar6 = 0;
        _DAT_00735e70 = 0;
        if (*(short *)(iVar5 + 0xc58) != 0) {
          if (DAT_0073766c != 0) {
            piVar8 = (int *)(DAT_00737668 + 0x24);
            do {
              if ((piVar8[-1] == 0) && (*piVar8 == *(int *)(iVar5 + 0xc50))) {
                if (*(char *)(uVar6 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_004c67ce;
                break;
              }
              uVar6 = uVar6 + 1;
              piVar8 = piVar8 + 0xd;
            } while (uVar6 < DAT_0073766c);
          }
          cVar4 = Career__IsCarUnlocked();
          if (cVar4 == '\0') goto LAB_004c6839;
        }
LAB_004c67ce:
        piVar8 = _malloc(0x740);
        if (piVar8 == (int *)0x0) {
          piVar8 = (int *)0x0;
        }
        else {
          iVar7 = *(int *)(local_10 + 0x338);
          iVar1 = *(int *)(local_10 + 0x344);
          RideInfo__Init();
          piVar8[0x1cc] = iVar5;
          piVar8[0x1cd] = iVar7;
          piVar8[0x1ce] = iVar1;
        }
        FECarConfig__BuildRide(local_10,0,piVar8 + 4);
        puVar2 = *(undefined4 **)(param_1 + 0x44);
        *puVar2 = piVar8;
        *(int **)(param_1 + 0x44) = piVar8;
        piVar8[1] = (int)puVar2;
        *piVar8 = param_1 + 0x40;
        iVar7 = DAT_00734588;
      }
LAB_004c6839:
      local_c = local_c + 1;
      local_8 = local_8 + 0x348;
    } while (local_c < DAT_0075ee00);
  }
  piVar8 = (int *)(param_1 + 0x40);
  bList__Sort(piVar8,FUN_004c2bc0);
  piVar10 = (int *)*piVar8;
  if (piVar10 != piVar8) {
    do {
      iVar7 = *(int *)(piVar10[0x1cc] + 0xc50);
      if ((((iVar7 == 0x13) || (iVar7 == 0x11)) || (iVar7 == 0x12)) || (iVar7 == 0x10)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      iVar7 = FUN_004f8730(param_1 + 0x4c,piVar10[0x1ce],0,!bVar3);
      iVar5 = *(int *)(piVar10[0x1cc] + 0xc50) * 0xc90 + DAT_00734588;
      pcVar9 = (char *)(iVar5 + 0xc0);
      if ((DAT_00734998 != 0) && (*(int *)(iVar5 + 0xc50) == 0xe)) {
        pcVar9 = "HONDA";
      }
      iVar5 = FUN_004f42f0("CARSELECT_MANUFACTURER_%s",pcVar9);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != iVar5)) {
        *(int *)(iVar7 + 0x24) = iVar5;
        *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
      }
      piVar10 = (int *)*piVar10;
    } while (piVar10 != piVar8);
  }
  piVar10 = (int *)*piVar8;
  *(int **)(param_1 + 0x48) = piVar10;
  for (; piVar10 != piVar8; piVar10 = (int *)*piVar10) {
    if (piVar10[0x1ce] == DAT_00758c28) {
      *(int **)(param_1 + 0x48) = piVar10;
    }
  }
  DAT_00758c28 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x738);
  FUN_004f8960();
  return;
}


// ==== 0x4c6970 GetCarManufacturerNameHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GetCarManufacturerNameHash(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_EAX + 0x48) + 0x730) + 0xc50) * 0xc90 + DAT_00734588;
  pcVar3 = (char *)(iVar1 + 0xc0);
  if ((DAT_00734998 != 0) && (*(int *)(iVar1 + 0xc50) == 0xe)) {
    pcVar3 = "HONDA";
  }
  uVar2 = FUN_004f42f0("BRAND_NAME_%s",pcVar3);
  FUN_00495f00(uVar2);
  uVar2 = GetSecondaryLogoHash();
  FUN_004ad7b0(uVar2);
  return;
}


// ==== 0x4c69f0 FUN_004c69f0

void __fastcall FUN_004c69f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x48);
  if (param_1 == -0x6edfbf62) {
    if (puVar1 == *(undefined4 **)(unaff_EDI + 0x40)) goto LAB_004c6a17;
    uVar3 = puVar1[1];
  }
  else {
    if ((param_1 != -0x4a68e40f) || (puVar1 == *(undefined4 **)(unaff_EDI + 0x44)))
    goto LAB_004c6a17;
    uVar3 = *puVar1;
  }
  *(undefined4 *)(unaff_EDI + 0x48) = uVar3;
LAB_004c6a17:
  if (puVar1 != *(undefined4 **)(unaff_EDI + 0x48)) {
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
    DAT_00758c28 = *(undefined4 *)(*(int *)(unaff_EDI + 0x48) + 0x738);
    iVar2 = FUN_004b2330();
    if (iVar2 != 0) {
      GarageMainScreen__SetCarType(iVar2);
    }
    FUN_004f8910();
    GetCarManufacturerNameHash();
    *(undefined4 *)(unaff_EDI + 0x88) = DAT_0073ad3c;
  }
  return;
}


// ==== 0x4c6ab0 FUN_004c6ab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c6ab0(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        if ((*(int *)(param_1 + 0x88) != 0) && (*(int *)(param_1 + 0x88) != 0x7fffffff)) {
          FUN_004b23b0(*(int *)(param_1 + 0x48) + 0x10,1);
        }
        FUN_004ac060("MU_Garage.fng",0);
        LaunchPartsBrowser(2);
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    FUN_004f7d30();
    iVar1 = *(int *)(param_1 + 0x88);
    if (iVar1 == 0) {
      return;
    }
    if (iVar1 == 0x7fffffff) {
      return;
    }
    if ((float)(DAT_0073ad3c - iVar1) * 0.00025 < _DAT_006faf00) {
      return;
    }
    FUN_004b23b0(*(int *)(param_1 + 0x48) + 0x10,1);
    *(undefined4 *)(param_1 + 0x88) = 0;
    return;
  }
  FUN_004c69f0();
  return;
}


// ==== 0x4c6bc0 UndergroundJunkmanGiveth::vslot3__swallow_input_filter_

/* [canon] car low (ghidra+hopper) docs/re/tuning.md */

undefined4 __thiscall UndergroundJunkmanGiveth__vslot3__swallow_input_filter_(int param_1)

{
  undefined4 in_stack_00000014;
  
  if (*(char *)(param_1 + 0x8a) == '\0') {
    switch(in_stack_00000014) {
    case 1:
    case 2:
    case 3:
    case 4:
      break;
    default:
      return in_stack_00000014;
    }
  }
  return 0;
}


// ==== 0x4c6c00 GetJunkmanRewardSpeech

/* [canon] car low (ghidra+hopper) docs/re/tuning.md */

undefined4 GetJunkmanRewardSpeech(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 7:
    return 0x18;
  default:
    return 0xffffffff;
  case 0x1a:
    return 0x1a;
  case 0x44:
    return 0x1c;
  case 0x55:
    return 0x1e;
  case 0x61:
    return 0x20;
  }
}


// ==== 0x4c6cb0 UndergroundJunkmanGiveth::UndergroundJunkmanGiveth

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * UndergroundJunkmanGiveth__UndergroundJunkmanGiveth(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x11;
  *param_1 = &PTR_FUN_006c51b4;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","car_thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined1 *)((int)param_1 + 0x8b) = 1;
  uVar2 = FUN_0051ba80();
  *(undefined1 *)((int)param_1 + 0x89) = uVar2;
  *(undefined1 *)((int)param_1 + 0x8a) = 0;
  param_2 = &DAT_006fad68;
  do {
    iVar6 = param_2[-2];
    cVar3 = Career__IsUpgradeUnlocked(&DAT_0075eef8,iVar6);
    if ((cVar3 != '\0') && (*(int *)(&DAT_0075f204 + param_2[-1] * 4) == 0)) {
      iVar7 = *param_2;
      iVar8 = param_2[1];
      iVar4 = FUN_004f8730(param_1 + 0x13,iVar6,0,1);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x24) != iVar7)) {
        *(int *)(iVar4 + 0x24) = iVar7;
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      }
      piVar5 = _malloc(0x14);
      piVar5[4] = iVar8;
      piVar5[2] = iVar6;
      piVar5[3] = iVar6;
      puVar1 = (undefined4 *)param_1[0x12];
      *puVar1 = piVar5;
      param_1[0x12] = piVar5;
      piVar5[1] = (int)puVar1;
      *piVar5 = (int)(param_1 + 0x11);
    }
    param_2 = param_2 + 4;
  } while ((int)param_2 < 0x6fadf8);
  *(undefined1 *)(param_1 + 0x22) = 0;
  param_1[0x10] = param_1[0x11];
  FUN_004f8960();
  FUN_00495f00(*(undefined4 *)(param_1[0x10] + 0x10));
  *(undefined1 *)(param_1 + 8) = 1;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 == 0) || (*(int *)(iVar6 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar7 = *(int *)(DAT_0073578c + 8);
    iVar6 = iVar7 + 0xdc;
    if (iVar6 != 0) {
      iVar6 = FUN_004fd1e0(iVar6);
      if (iVar6 != 0) goto LAB_004c6e58;
    }
    cFEng__PushPackage(iVar7,"MU_HorizontalBrowserBack.fng",0x10,0);
  }
LAB_004c6e58:
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 == 0) || (*(int *)(iVar6 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar7 = *(int *)(DAT_0073578c + 8);
    iVar6 = iVar7 + 0xdc;
    if (iVar6 != 0) {
      iVar6 = FUN_004fd1e0(iVar6);
      if (iVar6 != 0) goto LAB_004c6eae;
    }
    cFEng__PushPackage(iVar7,"GarageMain.fng",0x10,0);
  }
LAB_004c6eae:
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar6 + 0x18));
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0xb7fc3e,0,0,*(int *)(iVar6 + 0x18));
  }
  if (DAT_00777b4c == 4) {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar6 + 0x18));
    }
  }
  else {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar6 != 0) && (*(int *)(iVar6 + 0x18) != 0)) && (*(int **)(iVar6 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar6 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar6 + 0x18));
    }
  }
  FUN_004b2480();
  iVar6 = GetJunkmanRewardSpeech();
  if (iVar6 != -1) {
    EAXSound__PlaySpeechStream(0xffffffff);
  }
  if (DAT_0073578c != 0) {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
      iVar7 = *(int *)(iVar6 + 0x88);
      iVar8 = 0;
      if (iVar7 != 0) {
        piVar5 = *(int **)(iVar6 + 0x84);
        do {
          if (*(int *)(*piVar5 + 0x10) == -0x15619cfe) {
            iVar8 = *piVar5;
          }
          piVar5 = piVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (iVar8 != 0) {
          *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x4000000;
        }
      }
    }
  }
  DAT_00744ff8 = &DAT_0075eef8;
  FECarConfig__BuildRide(&DAT_0075eef8,0,&DAT_00745000);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  UndergroundJunkmanGiveth__ApplyJunkmanPartToEditingRide();
  DAT_00745e40 = 1;
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4c7060 FUN_004c7060

void * __thiscall FUN_004c7060(void *param_1,byte param_2)

{
  FUN_004c70b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c7080 FUN_004c7080

void FUN_004c7080(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  
  _Memory = *(int **)(in_EAX + 4);
  while (_Memory != (int *)(in_EAX + 4)) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = *(int **)(in_EAX + 4);
  }
  return;
}


// ==== 0x4c70b0 FUN_004c70b0

void __fastcall FUN_004c70b0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068731e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c51b4;
  local_4 = 2;
  if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0xa0))();
  }
  FUN_004f84d0();
  piVar1 = (int *)param_1[0x11];
  while (piVar1 != param_1 + 0x11) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c7150 UndergroundJunkmanGiveth::ApplyJunkmanPartToEditingRide

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void UndergroundJunkmanGiveth__ApplyJunkmanPartToEditingRide(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_730 [52];
  undefined4 auStack_6fc [446];
  
  iVar2 = *(int *)(in_EAX + 0x40);
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_730);
  iVar3 = 0;
  piVar1 = &DAT_006fad60;
  do {
    if (*piVar1 == *(int *)(iVar2 + 8)) {
      puVar4 = &DAT_006fad60 + iVar3 * 4;
      goto LAB_004c7196;
    }
    piVar1 = piVar1 + 4;
    iVar3 = iVar3 + 1;
  } while ((int)piVar1 < 0x6fadf0);
  puVar4 = (undefined4 *)0x0;
LAB_004c7196:
  auStack_6fc[puVar4[1]] = 1;
  RideInfo__RebuildPhysicsInfo(1);
  RideInfo__operator_(&DAT_00745000,local_730);
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745000);
  _DAT_0072cc80 = 2;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
  }
  return;
}


// ==== 0x4c7200 FUN_004c7200

void FUN_004c7200(int param_1)

{
  int iVar1;
  int unaff_EBX;
  
  if (*(char *)(unaff_EBX + 0x8b) == '\0') {
    iVar1 = *(int *)(unaff_EBX + 0x40);
    if (param_1 == -0x6edfbf62) {
      if ((iVar1 != *(int *)(unaff_EBX + 0x44)) && (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44))
      {
        *(undefined4 *)(unaff_EBX + 0x40) = *(undefined4 *)(iVar1 + 4);
      }
    }
    else if (((param_1 == -0x4a68e40f) &&
             (*(undefined4 **)(unaff_EBX + 0x40) != *(undefined4 **)(unaff_EBX + 0x48))) &&
            (*(int *)(unaff_EBX + 0x44) != unaff_EBX + 0x44)) {
      *(undefined4 *)(unaff_EBX + 0x40) = **(undefined4 **)(unaff_EBX + 0x40);
    }
    if (iVar1 != *(int *)(unaff_EBX + 0x40)) {
      FUN_004f8910();
      FUN_00495f00(*(undefined4 *)(*(int *)(unaff_EBX + 0x40) + 0x10));
      UndergroundJunkmanGiveth__ApplyJunkmanPartToEditingRide();
      if (param_1 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
    }
  }
  return;
}


// ==== 0x4c72d0 FUN_004c72d0

void FUN_004c72d0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (((*(char *)(DAT_00777ccc + 0x5964) == '\0') && (*(char *)(DAT_00777ccc + 0x5958) == '\0')) &&
     (cVar1 = FUN_0051ba80(), cVar1 != '\0')) {
    bStrCmp();
  }
  iVar3 = DAT_0073578c;
  if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar2 + 0x18));
  }
  iVar3 = FUN_004f65d0();
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x1c) = 0xff;
  }
  return;
}


// ==== 0x4c7360 FUN_004c7360

void __fastcall FUN_004c7360(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  piVar1 = &DAT_006fad60;
  do {
    if (*piVar1 == *(int *)(*(int *)(param_2 + 0x40) + 8)) {
      puVar3 = &DAT_006fad60 + iVar2 * 4;
      goto LAB_004c7381;
    }
    piVar1 = piVar1 + 4;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x6fadf0);
  puVar3 = (undefined4 *)0x0;
LAB_004c7381:
  *(undefined4 *)(&DAT_0075f204 + puVar3[1] * 4) = 1;
  *(undefined1 *)(param_2 + 0x88) = 1;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x12121212,0,0,*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4c73e0 FUN_004c73e0

void FUN_004c73e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 0x8b) = 0;
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c740a:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x3e3934ad);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c740a;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c740a;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c7451:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xe65a5489);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c7451;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c7451;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004c74bd;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x532bdf3b);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004c74bd:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4c74d0 FUN_004c74d0

void __thiscall FUN_004c74d0(int param_1,uint param_2)

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
        FUN_004f89d0();
        FUN_004f7d30();
        return;
      }
      if (param_2 != 0xf0aadebb) {
        return;
      }
      FUN_004c7360();
      return;
    }
LAB_004c7592:
    if ((*(char *)(param_1 + 0x8b) == '\0') || (param_2 != 0xc519bfc8)) {
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
      FUN_004c73e0();
      iVar1 = DAT_0073578c;
      bVar2 = DAT_0073578c != 0;
      *(undefined1 *)(param_1 + 0x8b) = 0;
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
      goto LAB_004c7592;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  FUN_004c7200(param_2);
  return;
}


// ==== 0x4c7670 CreateUndergroundJunkmanGiveth

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateUndergroundJunkmanGiveth(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689473;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = UndergroundJunkmanGiveth__UndergroundJunkmanGiveth(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c76d0 FUN_004c76d0

undefined4 FUN_004c76d0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0xf:
    return 0x30;
  default:
    return 0xffffffff;
  case 0x2f:
  case 0x44:
    return 0x35;
  case 0x4d:
    return 0x3c;
  }
}


// ==== 0x4c7750 FUN_004c7750

int FUN_004c7750(void)

{
  byte bVar1;
  uint in_EAX;
  uint3 uVar2;
  byte *pbVar3;
  int iVar4;
  undefined **ppuVar5;
  int unaff_EDI;
  
  ppuVar5 = &PTR_s_CUSTOM1_006fadf0;
  while( true ) {
    pbVar3 = *ppuVar5;
    bVar1 = *pbVar3;
    in_EAX = CONCAT31((int3)(in_EAX >> 8),bVar1);
    iVar4 = -1;
    while (bVar1 != 0) {
      iVar4 = iVar4 * 0x21 + (in_EAX & 0xff);
      bVar1 = pbVar3[1];
      in_EAX = (uint)bVar1;
      pbVar3 = pbVar3 + 1;
    }
    uVar2 = (uint3)(in_EAX >> 8);
    if (unaff_EDI == iVar4) break;
    ppuVar5 = ppuVar5 + 1;
    if (0x6fae17 < (int)ppuVar5) {
      return (uint)uVar2 << 8;
    }
  }
  return CONCAT31(uVar2,1);
}


// ==== 0x4c7790 FUN_004c7790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004c7790(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 uVar6;
  char cVar7;
  undefined4 *puVar8;
  int iVar9;
  int ******ppppppiVar10;
  undefined4 uVar11;
  int *****pppppiVar12;
  int *****pppppiVar13;
  int *******pppppppiVar14;
  int *******pppppppiVar15;
  int ******ppppppiVar16;
  int *******pppppppiVar17;
  undefined4 *puVar18;
  int iVar19;
  uint uVar20;
  byte *pbVar21;
  char *pcVar22;
  int *piVar23;
  int iVar24;
  int ****ppppiVar25;
  undefined1 *puVar26;
  int ******local_4c;
  int ******local_48;
  int ******local_44;
  int ******local_40;
  int ******local_3c;
  int ******local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  int *local_2c;
  int *local_28;
  int ******local_24;
  int local_20;
  int ******local_1c;
  int ******local_18;
  char local_12;
  char local_11;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006891b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  local_30 = param_1 + 0x10;
  local_8 = 0;
  *param_1 = &PTR_FUN_006c51a4;
  FUN_004f8370(local_30,"master_thumb","car_thumb");
  local_28 = param_1 + 0x1f;
  puVar8 = param_1 + 0x20;
  *puVar8 = puVar8;
  param_1[0x21] = puVar8;
  local_34 = param_1 + 0x24;
  RideInfo__Init();
  *(undefined1 *)(param_1 + 0x1ec) = 1;
  *(undefined1 *)((int)param_1 + 0x8a) = 0;
  uVar6 = FUN_0051ba80();
  *(undefined1 *)((int)param_1 + 0x89) = uVar6;
  *(undefined1 *)(param_1 + 0x22) = 0;
  iVar9 = FUN_005a0500();
  local_20 = iVar9;
  local_24 = (int ******)FECarConfig__GetCarType();
  piVar23 = DAT_0073ad40;
  bVar5 = false;
  local_1c = (int ******)0x0;
  if (iVar9 == 0x11) {
    bVar5 = true;
    pcVar22 = "WHEELS";
    local_1c = (int ******)0xffffffff;
    uVar20 = 0x57;
    do {
      local_1c = (int ******)((int)local_1c * 0x21 + uVar20);
      pbVar21 = (byte *)(pcVar22 + 1);
      uVar20 = (uint)*pbVar21;
      pcVar22 = pcVar22 + 1;
    } while (*pbVar21 != 0);
  }
  local_11 = iVar9 == 0x1f;
  if ((((int *******)local_24 == (int *******)0x0) || ((int *******)local_24 == (int *******)0x1))
     || (local_12 = '\0', (int *******)local_24 == (int *******)0x5)) {
    local_12 = '\x01';
  }
  if (bVar5) {
    local_2c = (int *)NullUpdate_ret();
    pppppppiVar14 = (int *******)local_1c;
    if (piVar23 == local_2c) {
LAB_004c78f7:
      ppppppiVar10 = (int ******)0x0;
    }
    else {
      do {
        ppppppiVar10 = (int ******)piVar23[3];
        ppppppiVar16 = ppppppiVar10 + piVar23[4] * 0xc;
        if ((pppppppiVar14 != (int *******)0x0) &&
           (ppppppiVar10 = (int ******)BinarySearch_Hash(local_1c,ppppppiVar10,4),
           pppppppiVar14 = (int *******)local_1c, ppppppiVar10 == (int ******)0x0))
        goto LAB_004c78f7;
        if (ppppppiVar10 < ppppppiVar16) {
          if ((pppppppiVar14 == (int *******)0x0) || ((int *******)ppppppiVar10[1] == pppppppiVar14)
             ) goto LAB_004c7938;
          goto LAB_004c78f7;
        }
        piVar23 = (int *)*piVar23;
      } while (piVar23 != local_2c);
      ppppppiVar10 = (int ******)0x0;
    }
  }
  else {
    pppppppiVar14 = (int *******)0x23;
    if (!(bool)local_11) {
      pppppppiVar14 = (int *******)local_24;
    }
    uVar11 = 0;
    if (pppppppiVar14 != (int *******)0x23) {
      if ((int)pppppppiVar14 * 0xc90 + DAT_00734588 == 0) {
        ppppppiVar10 = (int ******)0x0;
        goto LAB_004c7938;
      }
      uVar11 = bStringHash();
    }
    ppppppiVar10 = (int ******)CarPartDatabase__GetCarPart(uVar11,iVar9,0,0,0xffffffff);
  }
LAB_004c7938:
  local_44 = (int ******)&local_44;
  local_40 = (int ******)&local_44;
  piVar23 = (int *)((int)local_24 * 0xc90 + DAT_00734588);
  local_8._0_1_ = 3;
  local_2c = piVar23;
  while (local_18 = ppppppiVar10, ppppppiVar10 != (int ******)0x0) {
    if (bVar5) {
      pppppiVar12 = ppppppiVar10[5];
      pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
      if (pppppiVar12 != (int *****)0x0) {
        for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
          if (*pppppiVar12 == (int ****)0xce7d8db5) {
            if (pppppiVar12 != (int *****)0x0) {
              cVar7 = (char)pppppiVar12[1];
              goto LAB_004c79a1;
            }
            break;
          }
        }
      }
      cVar7 = '\0';
LAB_004c79a1:
      if (cVar7 == *(char *)((int)piVar23 + 0xdc)) goto LAB_004c79b6;
      bVar4 = false;
    }
    else {
LAB_004c79b6:
      bVar4 = true;
    }
    if ((local_20 == 0x1f) && (local_11 != '\0')) {
      if ((*(char *)((int)ppppppiVar10 + 0x12) == '\x0f') && (cVar7 = FUN_004c7750(), cVar7 != '\0')
         ) {
        pcVar22 = "CAR_THUMB";
        do {
          pcVar1 = pcVar22 + 1;
          pcVar22 = pcVar22 + 1;
        } while (*pcVar1 != '\0');
        FUN_004c8560();
        ppppppiVar10 = local_18;
        piVar23 = local_2c;
      }
LAB_004c7af6:
      if (bVar5) {
        pppppppiVar17 = (int *******)local_1c;
        iVar9 = -1;
      }
      else {
LAB_004c7aa4:
        pppppppiVar14 = (int *******)0x23;
        if (local_11 == '\0') {
          pppppppiVar14 = (int *******)local_24;
        }
        pppppppiVar17 = (int *******)0x0;
        iVar9 = local_20;
        if (pppppppiVar14 != (int *******)0x23) {
          iVar19 = (int)pppppppiVar14 * 0xc90 + DAT_00734588;
          if (iVar19 == 0) {
            pppppppiVar17 = (int *******)0x0;
          }
          else {
            pbVar21 = (byte *)(iVar19 + 0x20);
            pppppppiVar17 = (int *******)0xffffffff;
            bVar3 = *pbVar21;
            while (bVar3 != 0) {
              pppppppiVar17 = (int *******)((int)pppppppiVar17 * 0x21 + (uint)bVar3);
              pbVar2 = pbVar21 + 1;
              pbVar21 = pbVar21 + 1;
              bVar3 = *pbVar2;
            }
          }
        }
      }
      ppppppiVar10 = (int ******)
                     CarPartDatabase__GetCarPart(pppppppiVar17,iVar9,0,ppppppiVar10,0xffffffff);
    }
    else {
      if ((*(char *)((int)ppppppiVar10 + 0x11) != '\x04') || (!bVar4)) goto LAB_004c7af6;
      if (bVar5) {
        pppppppiVar14 = _malloc(0xc);
        pppppppiVar14[2] = ppppppiVar10;
        *local_40 = (int *****)pppppppiVar14;
        pppppppiVar14[1] = local_40;
        *pppppppiVar14 = (int ******)&local_44;
        local_40 = (int ******)pppppppiVar14;
        goto LAB_004c7af6;
      }
      if (((local_20 != 0xb) || (local_12 == '\0')) ||
         (pppppiVar13 = (int *****)bStringHash(), ppppppiVar10[3] != pppppiVar13)) {
        piVar23 = &DAT_00706540;
        do {
          if (*piVar23 == (int)*(char *)(ppppppiVar10 + 4)) break;
          piVar23 = piVar23 + 7;
        } while ((int)piVar23 < 0x7066ac);
        FUN_004c8560();
        ppppppiVar10 = local_18;
        piVar23 = local_2c;
        goto LAB_004c7aa4;
      }
      ppppppiVar10 = (int ******)FUN_004b3940(&DAT_0073ad40,ppppppiVar10,0xb,0,0xffffffff);
    }
  }
  local_4c = (int ******)&local_4c;
  local_48 = (int ******)&local_4c;
  local_3c = (int ******)&local_3c;
  local_38 = (int ******)&local_3c;
  local_8 = CONCAT31(local_8._1_3_,5);
  local_18 = (int ******)0x0;
  if (bVar5) {
    local_18 = ppppppiVar10;
    FUN_004c9470();
    pppppppiVar14 = (int *******)local_44;
    local_2c = (int *)(int)*(char *)((int)piVar23 + 0xdc);
    local_18 = (int ******)NullUpdate_ret();
    pppppppiVar17 = pppppppiVar14;
    if (pppppppiVar14 != (int *******)local_18) {
      pppppppiVar15 = (int *******)NullUpdate_ret();
      do {
        bVar5 = false;
        pppppppiVar17 = (int *******)local_3c;
        if ((int *******)local_3c == pppppppiVar15) {
LAB_004c7c64:
          pppppppiVar17 = _malloc(0x10);
          pppppiVar12 = pppppppiVar14[2][5];
          pppppiVar13 = pppppiVar12 + *(short *)(pppppppiVar14[2] + 7) * 2;
          if (pppppiVar12 != (int *****)0x0) {
            for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
              if (*pppppiVar12 == (int ****)0x10c98090) {
                if (pppppiVar12 != (int *****)0x0) {
                  ppppppiVar10 = (int ******)pppppiVar12[1];
                  goto LAB_004c7c98;
                }
                break;
              }
            }
          }
          ppppppiVar10 = (int ******)0x0;
LAB_004c7c98:
          pppppppiVar17[2] = ppppppiVar10;
          pppppiVar12 = pppppppiVar14[2][5];
          pppppiVar13 = pppppiVar12 + *(short *)(pppppppiVar14[2] + 7) * 2;
          if (pppppiVar12 != (int *****)0x0) {
            for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
              if (*pppppiVar12 == (int ****)0xeb0101e2) {
                if (pppppiVar12 != (int *****)0x0) {
                  cVar7 = (char)pppppiVar12[1];
                  goto LAB_004c7cc5;
                }
                break;
              }
            }
          }
          cVar7 = '\0';
LAB_004c7cc5:
          pppppppiVar17[3] = (int ******)(int)cVar7;
          *local_38 = (int *****)pppppppiVar17;
          pppppppiVar17[1] = local_38;
          *pppppppiVar17 = (int ******)&local_3c;
          local_38 = (int ******)pppppppiVar17;
        }
        else {
          do {
            ppppppiVar10 = pppppppiVar14[2];
            pppppiVar12 = ppppppiVar10[5];
            pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
            if (pppppiVar12 != (int *****)0x0) {
              for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                if (*pppppiVar12 == (int ****)0x10c98090) {
                  if (pppppiVar12 != (int *****)0x0) {
                    ppppppiVar16 = (int ******)pppppiVar12[1];
                    goto LAB_004c7be5;
                  }
                  break;
                }
              }
            }
            ppppppiVar16 = (int ******)0x0;
LAB_004c7be5:
            if (pppppppiVar17[2] == ppppppiVar16) {
              pppppiVar12 = ppppppiVar10[5];
              pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
              if (pppppiVar12 != (int *****)0x0) {
                for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                  if (*pppppiVar12 == (int ****)0xce7d8db5) {
                    if (pppppiVar12 != (int *****)0x0) {
                      cVar7 = (char)pppppiVar12[1];
                      goto LAB_004c7c15;
                    }
                    break;
                  }
                }
              }
              cVar7 = '\0';
LAB_004c7c15:
              if (local_2c == (int *)(int)cVar7) {
                pppppiVar12 = ppppppiVar10[5];
                pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
                if (pppppiVar12 != (int *****)0x0) {
                  for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                    if (*pppppiVar12 == (int ****)0xeb0101e2) {
                      if (pppppiVar12 != (int *****)0x0) {
                        cVar7 = (char)pppppiVar12[1];
                        goto LAB_004c7c46;
                      }
                      break;
                    }
                  }
                }
                cVar7 = '\0';
LAB_004c7c46:
                bVar5 = true;
                if ((int)pppppppiVar17[3] < (int)cVar7) {
                  pppppppiVar17[3] = (int ******)(int)cVar7;
                }
              }
            }
            pppppppiVar17 = (int *******)*pppppppiVar17;
          } while (pppppppiVar17 != pppppppiVar15);
          if (!bVar5) goto LAB_004c7c64;
        }
        pppppppiVar14 = (int *******)*pppppppiVar14;
        pppppppiVar17 = (int *******)local_44;
      } while (pppppppiVar14 != (int *******)local_18);
    }
    local_1c = (int ******)pppppppiVar17;
    if (pppppppiVar17 != (int *******)local_18) {
      pppppppiVar17 = (int *******)NullUpdate_ret();
      pppppppiVar14 = (int *******)local_3c;
      do {
        while (local_24 = (int ******)pppppppiVar14, (int *******)local_24 != pppppppiVar17) {
          ppppppiVar10 = (int ******)local_1c[2];
          pppppiVar12 = ppppppiVar10[5];
          pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
          if (pppppiVar12 != (int *****)0x0) {
            for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
              if (*pppppiVar12 == (int ****)0x10c98090) {
                if (pppppiVar12 != (int *****)0x0) {
                  ppppppiVar16 = (int ******)pppppiVar12[1];
                  goto LAB_004c7d45;
                }
                break;
              }
            }
          }
          ppppppiVar16 = (int ******)0x0;
LAB_004c7d45:
          if (ppppppiVar16 == (int ******)local_24[2]) {
            pppppiVar12 = ppppppiVar10[5];
            pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
            if (pppppiVar12 != (int *****)0x0) {
              for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                if (*pppppiVar12 == (int ****)0xeb0101e2) {
                  if (pppppiVar12 != (int *****)0x0) {
                    cVar7 = (char)pppppiVar12[1];
                    goto LAB_004c7d75;
                  }
                  break;
                }
              }
            }
            cVar7 = '\0';
LAB_004c7d75:
            if ((int ******)(int)cVar7 == (int ******)local_24[3]) {
              pppppiVar12 = ppppppiVar10[5];
              pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
              if (pppppiVar12 != (int *****)0x0) {
                for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                  if (*pppppiVar12 == (int ****)0xce7d8db5) {
                    if (pppppiVar12 != (int *****)0x0) {
                      cVar7 = (char)pppppiVar12[1];
                      goto LAB_004c7db5;
                    }
                    break;
                  }
                }
              }
              cVar7 = '\0';
LAB_004c7db5:
              if ((int *)(int)cVar7 == local_2c) {
                pppppiVar12 = ppppppiVar10[5];
                pppppiVar13 = pppppiVar12 + *(short *)(ppppppiVar10 + 7) * 2;
                if (pppppiVar12 != (int *****)0x0) {
                  for (; pppppiVar12 < pppppiVar13; pppppiVar12 = pppppiVar12 + 2) {
                    if (*pppppiVar12 == (int ****)0x10c98090) {
                      if (pppppiVar12 != (int *****)0x0) {
                        ppppiVar25 = pppppiVar12[1];
                        goto LAB_004c7df5;
                      }
                      break;
                    }
                  }
                }
                ppppiVar25 = (int ****)0x0;
LAB_004c7df5:
                iVar9 = FUN_004f8730(local_30,ppppppiVar10,0,1);
                if (((ppppiVar25 != (int ****)0x0) && (iVar9 != 0)) &&
                   (*(int *****)(iVar9 + 0x24) != ppppiVar25)) {
                  *(int *****)(iVar9 + 0x24) = ppppiVar25;
                  *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
                }
                puVar18 = _malloc(0x10);
                puVar18[2] = ppppppiVar10;
                puVar8 = (undefined4 *)param_1[0x21];
                *puVar8 = puVar18;
                param_1[0x21] = puVar18;
                puVar18[1] = puVar8;
                *puVar18 = param_1 + 0x20;
              }
            }
          }
          pppppppiVar14 = (int *******)*local_24;
        }
        local_1c = (int ******)*local_1c;
        pppppppiVar14 = (int *******)local_3c;
      } while (local_1c != local_18);
    }
  }
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 != 0) && (*(int *)(iVar9 + 0x18) != 0)) && (*(int **)(iVar9 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar9 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar9 + 0x18));
  }
  FUN_004b2480();
  puVar8 = local_34;
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_34);
  if (local_20 == 0x1f) {
    puVar8[0x132] = 0;
    *(char *)((int)puVar8 + 0x64b) = *(char *)((int)puVar8 + 0x64b) + '\x01';
    RideInfo__UpdatePartsEnabled(puVar8);
    puVar8[0x133] = 0;
    *(char *)(puVar8 + 0x193) = *(char *)(puVar8 + 0x193) + '\x01';
    RideInfo__UpdatePartsEnabled(puVar8);
    puVar8[0x134] = 0;
    *(char *)((int)puVar8 + 0x64d) = *(char *)((int)puVar8 + 0x64d) + '\x01';
    RideInfo__UpdatePartsEnabled(puVar8);
LAB_004c80b2:
    *(char *)((int)puVar8 + 0x64e) = *(char *)((int)puVar8 + 0x64e) + '\x01';
    puVar8[0x135] = 0;
    RideInfo__UpdatePartsEnabled(puVar8);
  }
  else if (local_20 == 8) {
    iVar9 = param_1[0x156];
    if (((iVar9 != 0) && (*(char *)(iVar9 + 0x10) == '\x1f')) &&
       ((((cVar7 = *(char *)(iVar9 + 0x12), cVar7 == '\b' || ((cVar7 == '\n' || (cVar7 == '\x06'))))
         || (cVar7 == '\x03')) || ((cVar7 == '\x01' || (cVar7 == '\r')))))) {
      puVar8[0x132] = 0;
      *(char *)((int)puVar8 + 0x64b) = *(char *)((int)puVar8 + 0x64b) + '\x01';
      RideInfo__UpdatePartsEnabled(puVar8);
    }
    iVar9 = param_1[0x157];
    if (((iVar9 != 0) && (*(char *)(iVar9 + 0x10) == '\x1f')) &&
       ((cVar7 = *(char *)(iVar9 + 0x12), cVar7 == '\b' ||
        ((((cVar7 == '\n' || (cVar7 == '\x06')) || (cVar7 == '\x03')) ||
         ((cVar7 == '\x01' || (cVar7 == '\r')))))))) {
      puVar8[0x133] = 0;
      *(char *)(puVar8 + 0x193) = *(char *)(puVar8 + 0x193) + '\x01';
      RideInfo__UpdatePartsEnabled(puVar8);
    }
    iVar9 = param_1[0x158];
    if (((iVar9 != 0) && (*(char *)(iVar9 + 0x10) == '\x1f')) &&
       (((cVar7 = *(char *)(iVar9 + 0x12), cVar7 == '\b' ||
         (((cVar7 == '\n' || (cVar7 == '\x06')) || (cVar7 == '\x03')))) ||
        ((cVar7 == '\x01' || (cVar7 == '\r')))))) {
      puVar8[0x134] = 0;
      *(char *)((int)puVar8 + 0x64d) = *(char *)((int)puVar8 + 0x64d) + '\x01';
      RideInfo__UpdatePartsEnabled(puVar8);
    }
    iVar9 = param_1[0x159];
    if (((iVar9 != 0) && (*(char *)(iVar9 + 0x10) == '\x1f')) &&
       (((cVar7 = *(char *)(iVar9 + 0x12), cVar7 == '\b' ||
         (((cVar7 == '\n' || (cVar7 == '\x06')) || (cVar7 == '\x03')))) ||
        ((cVar7 == '\x01' || (cVar7 == '\r')))))) goto LAB_004c80b2;
  }
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 == 0) || (*(int *)(iVar9 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar19 = *(int *)(DAT_0073578c + 8);
    iVar9 = iVar19 + 0xdc;
    if ((iVar9 == 0) || (iVar9 = FUN_004fd1e0(iVar9), iVar9 == 0)) {
      cFEng__PushPackage(iVar19,"MU_HorizontalBrowserBack.fng",0x10,0xff);
    }
  }
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 == 0) || (*(int *)(iVar9 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar19 = *(int *)(DAT_0073578c + 8);
    iVar9 = iVar19 + 0xdc;
    if ((iVar9 == 0) || (iVar9 = FUN_004fd1e0(iVar9), iVar9 == 0)) {
      cFEng__PushPackage(iVar19,"GarageMain.fng",0x10,0);
    }
  }
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 != 0) && (*(int *)(iVar9 + 0x18) != 0)) && (*(int **)(iVar9 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar9 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar9 + 0x18));
  }
  DAT_00744ff8 = &DAT_0075eef8;
  FECarConfig__BuildRide(&DAT_0075eef8,0,&DAT_00745000);
  FECarConfig__BuildRide(DAT_00744ff8,0,&DAT_00745720);
  piVar23 = param_1 + 0x20;
  DAT_00745e40 = 1;
  if ((int *)*piVar23 != piVar23) {
    *local_28 = local_28[1];
    iVar9 = *(int *)(local_28[1] + 8);
    FUN_004f8960();
    puVar8 = local_34;
    iVar19 = (int)*(char *)(iVar9 + 0x10);
    local_34[iVar19 + 0x113] = iVar9;
    *(char *)(iVar19 + 0x62c + (int)local_34) = *(char *)(iVar19 + 0x62c + (int)local_34) + '\x01';
    RideInfo__UpdatePartsEnabled(local_34);
    iVar9 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar9 == 0) || (*(int *)(iVar9 + 0x18) == 0)) {
      iVar9 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar9 == 0) ||
         (((*(int *)(iVar9 + 0x18) == 0 ||
           (iVar9 = FEPackageList__FindByName(&DAT_00746104), iVar9 == 0)) ||
          (*(int *)(iVar9 + 0x14) == 0)))) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(*(int *)(iVar9 + 0x14) + 0x40);
      }
    }
    else {
      iVar9 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0x14);
      }
    }
    RideInfo__operator_(&DAT_00748850,puVar8);
    _DAT_0072cc80 = 2;
    if (iVar9 != 0) {
      GarageMainScreen__SetRideInfo(iVar9,&DAT_00748850,2);
    }
    iVar9 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar9 == 0) || (*(int *)(iVar9 + 0x18) == 0)) {
      iVar9 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar9 == 0) ||
          ((*(int *)(iVar9 + 0x18) == 0 ||
           (iVar9 = FEPackageList__FindByName(&DAT_00746104), iVar9 == 0)))) ||
         (*(int *)(iVar9 + 0x14) == 0)) goto LAB_004c833a;
      iVar9 = *(int *)(*(int *)(iVar9 + 0x14) + 0x40);
    }
    else {
      iVar9 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0x14);
      }
    }
    if (iVar9 != 0) {
      FUN_004b0150();
    }
  }
LAB_004c833a:
  if ((int *)*piVar23 == piVar23) {
    puVar26 = &DAT_006b9172;
  }
  else {
    puVar26 = (undefined1 *)**(undefined4 **)(*local_28 + 8);
  }
  FUN_004f6850(puVar26);
  *(undefined1 *)(param_1 + 8) = 1;
  iVar9 = FUN_004c76d0();
  if (iVar9 != -1) {
    EAXSound__PlaySpeechStream(0xffffffff);
  }
  if (((DAT_0073578c != 0) && (iVar9 = FEPackageList__FindByName(&DAT_00746104), iVar9 != 0)) &&
     (iVar9 = *(int *)(iVar9 + 0x18), iVar9 != 0)) {
    iVar19 = *(int *)(iVar9 + 0x88);
    iVar24 = 0;
    if (iVar19 != 0) {
      piVar23 = *(int **)(iVar9 + 0x84);
      do {
        if (*(int *)(*piVar23 + 0x10) == -0x15619cfe) {
          iVar24 = *piVar23;
        }
        piVar23 = piVar23 + 1;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
      if (iVar24 != 0) {
        *(uint *)(iVar24 + 0x1c) = *(uint *)(iVar24 + 0x1c) | 0x4000000;
      }
    }
  }
  if ((int *******)local_3c != &local_3c) {
    do {
      ppppppiVar10 = (int ******)*local_3c;
      ppppppiVar16 = (int ******)local_3c[1];
      *ppppppiVar16 = (int *****)ppppppiVar10;
      ppppppiVar10[1] = (int *****)ppppppiVar16;
      _free(local_3c);
    } while ((int *******)local_3c != &local_3c);
  }
  if ((int *******)local_4c != &local_4c) {
    do {
      ppppppiVar10 = (int ******)*local_4c;
      ppppppiVar16 = (int ******)local_4c[1];
      *ppppppiVar16 = (int *****)ppppppiVar10;
      ppppppiVar10[1] = (int *****)ppppppiVar16;
      _free(local_4c);
    } while ((int *******)local_4c != &local_4c);
  }
  if ((int *******)local_44 != &local_44) {
    do {
      ppppppiVar10 = (int ******)*local_44;
      ppppppiVar16 = (int ******)local_44[1];
      *ppppppiVar16 = (int *****)ppppppiVar10;
      ppppppiVar10[1] = (int *****)ppppppiVar16;
      _free(local_44);
    } while ((int *******)local_44 != &local_44);
  }
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4c8490 FUN_004c8490

void * __thiscall FUN_004c8490(void *param_1,byte param_2)

{
  FUN_004c84b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c84b0 FUN_004c84b0

void __fastcall FUN_004c84b0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006872ee;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c51a4;
  local_4 = 2;
  if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0xa0))();
  }
  piVar1 = (int *)param_1[0x20];
  while (piVar1 != param_1 + 0x20) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)param_1[0x20];
  }
  FUN_004f84d0();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4c8560 FUN_004c8560

void FUN_004c8560(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EBX + 0x40,unaff_EDI,0,1);
  if (((unaff_ESI != 0) && (iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != unaff_ESI)) {
    *(int *)(iVar2 + 0x24) = unaff_ESI;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x10);
  piVar3[2] = unaff_EDI;
  puVar1 = *(undefined4 **)(unaff_EBX + 0x84);
  *puVar1 = piVar3;
  *(int **)(unaff_EBX + 0x84) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_EBX + 0x80;
  return;
}


// ==== 0x4c85b0 FUN_004c85b0

void FUN_004c85b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  
  if ((*(char *)(unaff_EBX + 0x7b0) == '\0') && (*(int *)(unaff_EBX + 0x80) != unaff_EBX + 0x80)) {
    iVar3 = *(int *)(unaff_EBX + 0x7c);
    if (param_1 == -0x6edfbf62) {
      if ((iVar3 != *(int *)(unaff_EBX + 0x80)) && (*(int *)(unaff_EBX + 0x80) != unaff_EBX + 0x80))
      {
        *(undefined4 *)(unaff_EBX + 0x7c) = *(undefined4 *)(iVar3 + 4);
      }
    }
    else if (((param_1 == -0x4a68e40f) &&
             (*(undefined4 **)(unaff_EBX + 0x7c) != *(undefined4 **)(unaff_EBX + 0x84))) &&
            (*(int *)(unaff_EBX + 0x80) != unaff_EBX + 0x80)) {
      *(undefined4 *)(unaff_EBX + 0x7c) = **(undefined4 **)(unaff_EBX + 0x7c);
    }
    if (iVar3 != *(int *)(unaff_EBX + 0x7c)) {
      FUN_004f8910();
      FUN_004c86e0();
      iVar1 = *(int *)(*(int *)(unaff_EBX + 0x7c) + 8);
      iVar2 = (int)*(char *)(iVar1 + 0x10);
      iVar3 = unaff_EBX + 0x90;
      *(int *)(unaff_EBX + 0x4dc + iVar2 * 4) = iVar1;
      *(char *)(iVar2 + 0x62c + iVar3) = *(char *)(iVar2 + 0x62c + iVar3) + '\x01';
      RideInfo__UpdatePartsEnabled(iVar3);
      FUN_004b23b0(iVar3,2);
      iVar3 = FUN_004b2330();
      if (iVar3 != 0) {
        FUN_004b0150();
      }
      if (param_1 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
    }
  }
  return;
}


// ==== 0x4c86e0 FUN_004c86e0

void __fastcall FUN_004c86e0(int param_1)

{
  if (*(int *)(param_1 + 0x80) != param_1 + 0x80) {
    FUN_004f6850(**(undefined4 **)(*(int *)(param_1 + 0x7c) + 8));
    return;
  }
  FUN_004f6850(&DAT_006b9172);
  return;
}


// ==== 0x4c8720 FUN_004c8720

void FUN_004c8720(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int unaff_EBX;
  
  iVar3 = *(int *)(*(int *)(unaff_EBX + 0x7c) + 8);
  if (*(char *)(iVar3 + 0x10) == '\v') {
    pcVar5 = "NOHATCHBACK";
    iVar4 = -1;
    uVar2 = 0x4e;
    do {
      iVar4 = iVar4 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    if (*(int *)(iVar3 + 0xc) == iVar4) {
      FECarConfig__GetCarType();
      pcVar5 = "_STYLE03_SPOILER";
      iVar4 = bStringHash();
      uVar2 = 0x5f;
      do {
        iVar4 = iVar4 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      CarPartDatabase__GetCarPart(0,0xb,iVar4,0,0xffffffff);
      FUN_005a2620();
    }
  }
  FUN_005a2620();
  if (*(char *)(iVar3 + 0x10) == '\x1f') {
    UnlockTeller__SetSingleVinylNewlyStyleUnlocked();
  }
  FECarConfig__FillFromRide(&DAT_0075eef8,unaff_EBX + 0x90);
  *(undefined1 *)(unaff_EBX + 0x88) = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x12121212,0,0,*(int *)(iVar3 + 0x18));
  }
  return;
}


// ==== 0x4c8810 FUN_004c8810

void FUN_004c8810(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 0x7b0) = 0;
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c883a:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x3e3934ad);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c883a;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c883a;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c8881:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xe65a5489);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c8881;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c8881;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004c88ed;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x532bdf3b);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004c88ed:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4c8900 FUN_004c8900

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


// ==== 0x4c8ab0 FUN_004c8ab0

undefined4 FUN_004c8ab0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689453;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x7c0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004c7790(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c8b10 FUN_004c8b10

void __fastcall FUN_004c8b10(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 0x20;
  *param_1 = &PTR_FUN_006c5194;
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


// ==== 0x4c8b50 FUN_004c8b50

void * __thiscall FUN_004c8b50(void *param_1,byte param_2)

{
  FUN_004c8b10();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c8b70 FUN_004c8b70

undefined4 * FUN_004c8b70(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_1c;
  char *local_18;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068916e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c5194;
  FUN_004f8370(param_1 + 0x10,"master_thumb","car_thumb");
  puVar3 = param_1 + 0x20;
  *puVar3 = puVar3;
  param_1[0x21] = puVar3;
  iVar11 = DAT_00735e58;
  *(undefined1 *)(param_1 + 0x22) = 1;
  iVar6 = DAT_00777ccc;
  bVar13 = iVar11 == 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  cVar5 = FUN_0051ba80();
  if (cVar5 != '\0') {
    local_1c = 0xb;
    local_18 = &DAT_0076323d;
    do {
      if ((*local_18 != '\0') && ((&DAT_0076777c)[local_1c] == '\0')) {
        if (bVar13) {
          (&DAT_006fae18)[iVar11] = (char)local_1c;
          DAT_00735e58 = iVar11 + 1;
        }
        pcVar9 = "STATUS_MAGAZINES_ICON";
        do {
          pcVar1 = pcVar9 + 1;
          pcVar9 = pcVar9 + 1;
        } while (*pcVar1 != '\0');
        FUN_004e93b0();
        FUN_004c8fd0(local_1c);
        iVar11 = DAT_00735e58;
      }
      local_18 = local_18 + 0x454;
      local_1c = local_1c + 1;
    } while ((int)local_18 < 0x76777d);
  }
  iVar12 = 0;
  iVar10 = *(int *)(iVar6 + 0x5914);
  if (0 < iVar10) {
    piVar8 = (int *)(iVar6 + 0x58d8);
    do {
      if (*piVar8 == 1) {
        iVar12 = piVar8[1];
      }
      piVar8 = piVar8 + 3;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    if (iVar12 != 0) {
      iVar6 = 0;
      do {
        if ((&DAT_00744ab0)[iVar6 * 2] == iVar12) {
          iVar6 = *(int *)(&DAT_00744ab4 + iVar6 * 8);
          goto LAB_004c8cd5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x1b);
      iVar6 = 0;
LAB_004c8cd5:
      if (bVar13) {
        (&DAT_006fae18)[iVar11] = (char)iVar6;
        DAT_00735e58 = iVar11 + 1;
      }
      pcVar9 = "STATUS_MAGAZINES_ICON";
      iVar11 = -1;
      uVar7 = 0x53;
      do {
        iVar11 = iVar11 * 0x21 + uVar7;
        pbVar2 = (byte *)(pcVar9 + 1);
        uVar7 = (uint)*pbVar2;
        pcVar9 = pcVar9 + 1;
      } while (*pbVar2 != 0);
      iVar10 = FUN_004f8730(param_1 + 0x10,iVar12,0,1);
      if (((iVar11 != 0) && (iVar10 != 0)) && (*(int *)(iVar10 + 0x24) != iVar11)) {
        *(int *)(iVar10 + 0x24) = iVar11;
        *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x400000;
      }
      piVar8 = _malloc(0x10);
      piVar8[2] = iVar12;
      piVar8[3] = iVar6;
      puVar3 = (undefined4 *)param_1[0x21];
      *puVar3 = piVar8;
      param_1[0x21] = piVar8;
      piVar8[1] = (int)puVar3;
      *piVar8 = (int)(param_1 + 0x20);
    }
  }
  puVar3 = param_1 + 0x20;
  iVar11 = 0;
  for (puVar4 = (undefined4 *)param_1[0x20];
      (puVar4 != puVar3 && (iVar11 = iVar11 + 1, puVar4 != (undefined4 *)0x0));
      puVar4 = (undefined4 *)*puVar4) {
  }
  DAT_00735e54 = 1 < iVar11;
  FUN_0051bad0(&DAT_007449c8);
  if (DAT_00777b4c == 4) {
    iVar11 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar11 != 0) && (*(int *)(iVar11 + 0x18) != 0)) &&
       (*(int **)(iVar11 + 0x14) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar11 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar11 + 0x18));
    }
  }
  else {
    iVar11 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar11 != 0) && (*(int *)(iVar11 + 0x18) != 0)) &&
       (*(int **)(iVar11 + 0x14) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar11 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar11 + 0x18));
    }
  }
  FUN_004b2480();
  if ((undefined4 *)*puVar3 != puVar3) {
    param_1[0x1f] = param_1[0x20];
    FUN_004f8960();
  }
  FUN_004c90c0();
  *(undefined1 *)(param_1 + 8) = 1;
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 == 0) || (*(int *)(iVar11 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar6 = *(int *)(DAT_0073578c + 8);
    iVar11 = iVar6 + 0xdc;
    if ((iVar11 == 0) || (iVar11 = FUN_004fd1e0(iVar11), iVar11 == 0)) {
      cFEng__PushPackage(iVar6,"MU_HorizontalBrowserBack.fng",0x10,0xff);
    }
  }
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 == 0) || (*(int *)(iVar11 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar6 = *(int *)(DAT_0073578c + 8);
    iVar11 = iVar6 + 0xdc;
    if ((iVar11 == 0) || (iVar11 = FUN_004fd1e0(iVar11), iVar11 == 0)) {
      cFEng__PushPackage(iVar6,"GarageMain.fng",0x10,0);
    }
  }
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 != 0) && (*(int *)(iVar11 + 0x18) != 0)) && (*(int **)(iVar11 + 0x14) != (int *)0x0))
  {
    (**(code **)(**(int **)(iVar11 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar11 + 0x18));
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  iVar11 = DAT_0073578c;
  if (((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) ||
     (((DAT_0073578c != 0 && (iVar10 = *(int *)(DAT_0073578c + 8), iVar10 != 0)) &&
      ((iVar6 = FUN_004fd1e0(iVar10 + 0xdc), iVar6 != 0 ||
       (iVar6 = FUN_004fd1e0(iVar10 + 0xec), iVar6 != 0)))))) {
    *(undefined4 *)(iVar6 + 0x1c) = 0xff;
  }
  if (((iVar11 != 0) && (iVar11 = FEPackageList__FindByName(&DAT_00746104), iVar11 != 0)) &&
     (iVar11 = *(int *)(iVar11 + 0x18), iVar11 != 0)) {
    iVar6 = *(int *)(iVar11 + 0x88);
    iVar10 = 0;
    if (iVar6 != 0) {
      piVar8 = *(int **)(iVar11 + 0x84);
      do {
        if (*(int *)(*piVar8 + 0x10) == -0x15619cfe) {
          iVar10 = *piVar8;
        }
        piVar8 = piVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (iVar10 != 0) {
        *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x4000000;
      }
    }
  }
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4c8fd0 FUN_004c8fd0

void FUN_004c8fd0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EBX + 0x40,unaff_EDI,0,1);
  if (((unaff_ESI != 0) && (iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != unaff_ESI)) {
    *(int *)(iVar2 + 0x24) = unaff_ESI;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x10);
  piVar3[3] = param_1;
  piVar3[2] = unaff_EDI;
  puVar1 = *(undefined4 **)(unaff_EBX + 0x84);
  *puVar1 = piVar3;
  *(int **)(unaff_EBX + 0x84) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_EBX + 0x80;
  return;
}


// ==== 0x4c9030 FUN_004c9030

void __fastcall FUN_004c9030(int param_1)

{
  int iVar1;
  int unaff_EDI;
  
  if ((*(char *)(unaff_EDI + 0x88) == '\0') && (*(int *)(unaff_EDI + 0x80) != unaff_EDI + 0x80)) {
    iVar1 = *(int *)(unaff_EDI + 0x7c);
    if (param_1 == -0x6edfbf62) {
      if ((iVar1 != *(int *)(unaff_EDI + 0x80)) && (*(int *)(unaff_EDI + 0x80) != unaff_EDI + 0x80))
      {
        *(undefined4 *)(unaff_EDI + 0x7c) = *(undefined4 *)(iVar1 + 4);
      }
    }
    else if (((param_1 == -0x4a68e40f) &&
             (*(undefined4 **)(unaff_EDI + 0x7c) != *(undefined4 **)(unaff_EDI + 0x84))) &&
            (*(int *)(unaff_EDI + 0x80) != unaff_EDI + 0x80)) {
      *(undefined4 *)(unaff_EDI + 0x7c) = **(undefined4 **)(unaff_EDI + 0x7c);
    }
    if (iVar1 != *(int *)(unaff_EDI + 0x7c)) {
      FUN_004f8910();
      FUN_004c90c0();
    }
  }
  return;
}


// ==== 0x4c90c0 FUN_004c90c0

void FUN_004c90c0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  FUN_00495f00(0x731eeb7b);
  if (*(int *)(unaff_ESI + 0x80) != unaff_ESI + 0x80) {
    uVar1 = *(uint *)(*(int *)(unaff_ESI + 0x7c) + 0xc);
    uVar2 = *(undefined4 *)(&DAT_006fa0b0 + uVar1 * 4);
    if ((byte)uVar1 < 0x1b) {
      uVar3 = *(undefined4 *)(&DAT_006fa120 + (uVar1 & 0xff) * 4);
    }
    else {
      uVar3 = 0;
    }
    FUN_00495f00(uVar3);
    FUN_00495f00(uVar2);
    return;
  }
  FUN_004f6850(&DAT_006b9172);
  return;
}


// ==== 0x4c9150 FUN_004c9150

void FUN_004c9150(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 0x88) = 0;
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c917a:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x3e3934ad);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c917a;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c917a;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) == 0) {
LAB_004c91c1:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xe65a5489);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004c91c1;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004c91c1;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EDI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004c922d;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x532bdf3b);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004c922d:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4c9240 FUN_004c9240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c9240(int param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (param_2 < 0x9120409f) {
    if (param_2 == 0x9120409e) {
LAB_004c9404:
      FUN_004c9030();
      return;
    }
    if (param_2 != 0xc407210) {
      if (param_2 == 0x14141414) {
        FUN_0051bb50();
        FUN_004c72d0();
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      iVar3 = 0;
      if (0 < DAT_00735e58) {
        do {
          pcVar1 = &DAT_006fae18 + iVar3;
          iVar3 = iVar3 + 1;
          (&DAT_0076777c)[*pcVar1] = 1;
        } while (iVar3 < DAT_00735e58);
      }
      _DAT_006fae18 = 0xffffffff;
      _DAT_006fae1c = 0xffffffff;
      _DAT_006fae20 = 0xffffffff;
      _DAT_006fae24 = 0xffffffff;
      DAT_00735e58 = 0;
      FUN_004c96f0(0x14141414,2);
      return;
    }
  }
  else {
    if (param_2 == 0xb5971bf1) goto LAB_004c9404;
    if (param_2 != 0xc519bfc8) {
      if (param_2 != 0xc98356ba) {
        return;
      }
      FUN_004c90c0();
      if (*(int *)(param_1 + 0x80) != param_1 + 0x80) {
        FUN_004f89d0();
      }
      FUN_004f7d30();
      return;
    }
  }
  if ((*(char *)(param_1 + 0x88) == '\0') || (param_2 != 0xc519bfc8)) {
    iVar3 = *(int *)(param_1 + 0x7c);
    (&DAT_0076777c)[*(int *)(iVar3 + 0xc)] = 1;
    iVar2 = DAT_0073578c;
    DAT_00735e50 = *(undefined4 *)(iVar3 + 8);
    DAT_00735e5c = 1;
    if ((DAT_0073578c != 0) &&
       ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 &&
        (*(int *)(iVar3 + 0x18) != 0)))) {
      FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
      return;
    }
  }
  else {
    FUN_004c9150();
    iVar3 = DAT_0073578c;
    bVar4 = DAT_0073578c != 0;
    *(undefined1 *)(param_1 + 0x88) = 0;
    if (((bVar4) && (FUN_004f5f80(iVar3,1), DAT_0073578c != 0)) &&
       (FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0)) {
      FUN_004f5ed0(DAT_0073578c);
      return;
    }
  }
  return;
}


// ==== 0x4c9410 FUN_004c9410

undefined4 FUN_004c9410(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689433;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004c8b70(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c9470 FUN_004c9470

void FUN_004c9470(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *_Memory;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_EDI;
  
  puVar1 = unaff_EDI + 1;
  puVar2 = (undefined4 *)unaff_EDI[1];
  while (puVar2 != puVar1) {
    _Memory = (int *)*puVar1;
    iVar3 = *_Memory;
    piVar4 = (int *)_Memory[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    _free(_Memory);
    puVar2 = (undefined4 *)*puVar1;
  }
  *unaff_EDI = 0;
  return;
}


// ==== 0x4c94b0 FUN_004c94b0

void FUN_004c94b0(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  char *pcVar3;
  int unaff_EDI;
  
  cVar1 = *(char *)(unaff_EDI + 8);
  iVar2 = unaff_EDI + 8;
  pcVar3 = (char *)(in_EAX + 8);
  *pcVar3 = cVar1;
  while (cVar1 != '\0') {
    cVar1 = *(char *)(iVar2 + 1);
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar1;
  }
  cVar1 = *(char *)(unaff_EDI + 0x48);
  iVar2 = unaff_EDI + 0x48;
  pcVar3 = (char *)(in_EAX + 0x48);
  *pcVar3 = cVar1;
  while (cVar1 != '\0') {
    cVar1 = *(char *)(iVar2 + 1);
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar1;
  }
  *(undefined4 *)(in_EAX + 0x88) = *(undefined4 *)(unaff_EDI + 0x88);
  *(undefined4 *)(in_EAX + 0x8c) = *(undefined4 *)(unaff_EDI + 0x8c);
  *(undefined4 *)(in_EAX + 0x90) = *(undefined4 *)(unaff_EDI + 0x90);
  *(undefined4 *)(in_EAX + 0x94) = *(undefined4 *)(unaff_EDI + 0x94);
  *(undefined4 *)(in_EAX + 0x98) = *(undefined4 *)(unaff_EDI + 0x98);
  *(undefined4 *)(in_EAX + 0x9c) = *(undefined4 *)(unaff_EDI + 0x9c);
  *(undefined4 *)(in_EAX + 0xa0) = *(undefined4 *)(unaff_EDI + 0xa0);
  *(undefined1 *)(in_EAX + 0xa4) = *(undefined1 *)(unaff_EDI + 0xa4);
  *(undefined1 *)(in_EAX + 0xa5) = *(undefined1 *)(unaff_EDI + 0xa5);
  *(undefined1 *)(in_EAX + 0xa6) = *(undefined1 *)(unaff_EDI + 0xa6);
  return;
}


// ==== 0x4c9570 FUN_004c9570

undefined1 FUN_004c9570(void)

{
  char *pcVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (DAT_00735e38 == 0) {
    return 1;
  }
  pcVar1 = (char *)FUN_00565b60(0xf660,0,0,0);
  Ugd__PackBlock(&DAT_007588c4,0xf660);
  uVar3 = 0;
  iVar2 = 0;
  iVar4 = DAT_00735e38 - (int)pcVar1;
  do {
    if (*pcVar1 != pcVar1[iVar4]) {
      uVar3 = 1;
      break;
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (iVar2 < 0xf660);
  FUN_00565ce0();
  if (DAT_00735e38 != 0) {
    FUN_00565ce0();
    DAT_00735e38 = 0;
  }
  return uVar3;
}


// ==== 0x4c957c FUN_004c957c

undefined1 FUN_004c957c(void)

{
  char *pcVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_00565b60(0xf660,0,0,0);
  Ugd__PackBlock(&DAT_007588c4,0xf660);
  uVar3 = 0;
  iVar2 = 0;
  iVar4 = DAT_00735e38 - (int)pcVar1;
  do {
    if (*pcVar1 != pcVar1[iVar4]) {
      uVar3 = 1;
      break;
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (iVar2 < 0xf660);
  FUN_00565ce0();
  if (DAT_00735e38 != 0) {
    FUN_00565ce0();
    DAT_00735e38 = 0;
  }
  return uVar3;
}


// ==== 0x4c95f0 Screen_MU_PlayerLogin::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_PlayerLogin__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006895d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xbc);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_PlayerLogin__Screen_MU_PlayerLogin(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4c9650 FUN_004c9650

undefined4 FUN_004c9650(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  uVar2 = DAT_00735e44;
  *(code **)(unaff_EDI + 0x40) = FUN_00557470;
  *(undefined1 *)(unaff_EDI + 0x48) = 1;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_004f7c00(uVar2,0,0,*(int *)(iVar1 + 0x18));
  }
  uVar2 = *(undefined4 *)(unaff_EDI + 0xc);
  if (DAT_0073578c != 0) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    uVar2 = 0;
    if ((iVar1 != 0) && (uVar2 = 0, *(int *)(iVar1 + 0x18) != 0)) {
      uVar2 = FUN_004f09b0(*(int *)(iVar1 + 0x18));
    }
  }
  return uVar2;
}


// ==== 0x4c96c0 FUN_004c96c0

void FUN_004c96c0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_004f7c00(param_1,0,0,*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4c96f0 FUN_004c96f0

void FUN_004c96f0(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  
  Ugd__Write(&DAT_0078a478,"auto");
  Settings__Save();
  if (in_EAX != 0) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int *)(iVar1 + 0x14) != 0)) {
      FUN_004f7c00(param_1,0,0,*(int *)(iVar1 + 0x18));
    }
  }
  return;
}


// ==== 0x4c9740 Screen_MU_PlayerLogin::Screen_MU_PlayerLogin

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_PlayerLogin__Screen_MU_PlayerLogin(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006895b6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar2 = param_1 + 0x23;
  *param_1 = &PTR_FUN_006c5134;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  puVar1 = param_1 + 0x25;
  *puVar2 = puVar2;
  param_1[0x24] = puVar2;
  *puVar1 = puVar1;
  param_1[0x26] = puVar1;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  local_4 = 1;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined1 *)((int)param_1 + 0xb5) = 0;
  *(undefined1 *)((int)param_1 + 0xb6) = 0;
  *(undefined1 *)((int)param_1 + 0xb7) = 1;
  DAT_00735e4c = 0;
  FUN_004c98e0(param_1);
  FUN_004c9bd0();
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar3);
  param_1[0x10] = FUN_004ca360;
  *(undefined1 *)(param_1 + 0x12) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4c9830 FUN_004c9830

void * __thiscall FUN_004c9830(void *param_1,byte param_2)

{
  FUN_004c9850();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4c9850 FUN_004c9850

void __fastcall FUN_004c9850(undefined4 *param_1)

{
  void *_Memory;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006872c6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c5134;
  _Memory = (void *)param_1[0x2b];
  local_4 = 1;
  DAT_006fad58 = 0xffffffff;
  if (_Memory != (void *)0x0) {
    if (*(int *)((int)_Memory + 0xc) != 0) {
      FUN_00565ce0();
    }
    _free(_Memory);
  }
  FUN_00494890();
  FUN_00494890();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4c98e0 FUN_004c98e0

/* WARNING: Removing unreachable block (ram,0x004c9a47) */

void FUN_004c98e0(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  byte *pbVar10;
  int iVar11;
  int local_50;
  int local_48;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687510;
  local_c = ExceptionList;
  local_50 = 1;
  local_48 = 5;
  ExceptionList = &local_c;
  do {
    piVar7 = _malloc(0x14);
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar1 = piVar7 + 2;
      *piVar1 = (int)piVar1;
      piVar7[3] = (int)piVar1;
      piVar7[4] = 0;
    }
    puVar3 = *(undefined4 **)(param_1 + 0x90);
    *puVar3 = piVar7;
    *(int **)(param_1 + 0x90) = piVar7;
    piVar7[1] = (int)puVar3;
    *piVar7 = param_1 + 0x8c;
    if (*(int *)(param_1 + 0xa4) == 0) {
      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x8c);
    }
    iVar4 = *(int *)(param_1 + 0x90);
    bSPrintf_regdst(0x20,"Player_DATA_0%d",local_50);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar6 = local_2c;
    while (bVar6 != 0) {
      if (('`' < (char)bVar6) && ((char)bVar6 < '{')) {
        bVar6 = bVar6 - 0x20;
      }
      iVar11 = iVar11 * 0x21 + (uint)bVar6;
      pbVar2 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar6 = *pbVar2;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c9a4b:
      if (DAT_0073578c == 0) goto LAB_004c9a63;
      iVar11 = FUN_004ef050(iVar11);
    }
    else {
      iVar8 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_004c9a0b:
        if (iVar8 != 0) {
          local_4 = 0;
          FUN_004ffb00(iVar8);
          local_4 = 0xffffffff;
        }
        goto LAB_004c9a4b;
      }
      if (DAT_0073578c != 0) {
        iVar5 = *(int *)(DAT_0073578c + 8);
        if ((iVar5 == 0) ||
           ((iVar8 = FUN_004fd1e0(iVar5 + 0xdc), iVar8 == 0 &&
            (iVar8 = FUN_004fd1e0(iVar5 + 0xec), iVar8 == 0)))) goto LAB_004c9a4b;
        goto LAB_004c9a0b;
      }
LAB_004c9a63:
      iVar11 = 0;
    }
    piVar7 = _malloc(0xc);
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7[2] = iVar11;
    }
    puVar3 = *(undefined4 **)(iVar4 + 0xc);
    *puVar3 = piVar7;
    *(int **)(iVar4 + 0xc) = piVar7;
    *piVar7 = iVar4 + 8;
    piVar7[1] = (int)puVar3;
    bSPrintf_regdst(0x20,"HighLight0%d",local_50);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar6 = local_2c;
    while (bVar6 != 0) {
      if (('`' < (char)bVar6) && ((char)bVar6 < '{')) {
        bVar6 = bVar6 - 0x20;
      }
      iVar11 = iVar11 * 0x21 + (uint)bVar6;
      pbVar2 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar6 = *pbVar2;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c9b79:
      if (DAT_0073578c == 0) goto LAB_004c9b8f;
      uVar9 = FUN_004ef050(iVar11);
    }
    else {
      iVar8 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_004c9b3b:
        local_4 = 1;
        FUN_004ffb00(iVar8);
        local_4 = 0xffffffff;
        goto LAB_004c9b79;
      }
      if (DAT_0073578c != 0) {
        iVar5 = *(int *)(DAT_0073578c + 8);
        if ((iVar5 == 0) ||
           ((iVar8 = FUN_004fd1e0(iVar5 + 0xdc), iVar8 == 0 &&
            (iVar8 = FUN_004fd1e0(iVar5 + 0xec), iVar8 == 0)))) goto LAB_004c9b79;
        goto LAB_004c9b3b;
      }
LAB_004c9b8f:
      uVar9 = 0;
    }
    *(undefined4 *)(iVar4 + 0x10) = uVar9;
    local_50 = local_50 + 1;
    local_48 = local_48 + -1;
    if (local_48 == 0) {
      ExceptionList = local_c;
      return;
    }
  } while( true );
}


// ==== 0x4c9bd0 FUN_004c9bd0

void FUN_004c9bd0(void)

{
  int unaff_EBX;
  int iVar1;
  
  FUN_004f9340(unaff_EBX + 0x8c);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    bSPrintf_regdst(0x20,"Player_DATA_0%d",iVar1);
    FUN_004f67f0(&DAT_006b9172);
  } while (iVar1 < 5);
  return;
}


// ==== 0x4c9c20 FUN_004c9c20

void FUN_004c9c20(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int in_EAX;
  int *piVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int local_24;
  char local_20 [32];
  
  FUN_004c9bd0();
  local_24 = 0;
  if (0 < *(int *)(*(int *)(in_EAX + 0xac) + 8)) {
    puVar1 = (undefined4 *)(in_EAX + 0x94);
    do {
      piVar6 = _malloc(0x10);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar4 = piVar6 + 2;
        *piVar4 = (int)piVar4;
        piVar6[3] = (int)piVar4;
      }
      puVar3 = *(undefined4 **)(in_EAX + 0x98);
      *puVar3 = piVar6;
      *(int **)(in_EAX + 0x98) = piVar6;
      piVar6[1] = (int)puVar3;
      *piVar6 = (int)puVar1;
      if (*(int *)(in_EAX + 0xa0) == 0) {
        *(undefined4 *)(in_EAX + 0xa0) = *puVar1;
      }
      if (*(int *)(in_EAX + 0x9c) == 0) {
        *(undefined4 *)(in_EAX + 0x9c) = *puVar1;
      }
      piVar4 = *(int **)(in_EAX + 0xac);
      if (local_24 < piVar4[1]) {
        iVar8 = *piVar4;
        iVar7 = iVar8 * local_24;
        iVar5 = piVar4[3];
        if (iVar8 != 0) {
          pcVar9 = local_20;
          do {
            cVar2 = pcVar9[(iVar7 + iVar5) - (int)local_20];
            iVar8 = iVar8 + -1;
            *pcVar9 = cVar2;
            if (cVar2 == '\0') break;
            pcVar9 = pcVar9 + 1;
          } while (iVar8 != 0);
        }
      }
      StringList__AddEntry(piVar6,local_20);
      local_24 = local_24 + 1;
    } while (local_24 < *(int *)(*(int *)(in_EAX + 0xac) + 8));
  }
  FUN_004f9240(in_EAX + 0x8c);
  if (*(int *)(in_EAX + 0xa4) != 0) {
    FUN_004f8dd0(*(int *)(in_EAX + 0xa4));
  }
  return;
}


// ==== 0x4c9d20 FUN_004c9d20

void FUN_004c9d20(int param_1,char param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  int extraout_EDX;
  int iVar8;
  int local_48;
  int local_44;
  byte local_40;
  byte local_3f [31];
  byte local_20;
  byte local_1f [31];
  
  if (param_2 == '\0') {
    bSPrintf_regdst(0x20,&DAT_006c5c64);
    if (*(int *)(param_1 + 0xa4) != 0) {
      FUN_004f8ec0(*(int *)(param_1 + 0xa4));
    }
    *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x8c);
  }
  else {
    bSPrintf_regdst(0x20,&DAT_006c515c);
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0x65d269c2);
      goto LAB_004c9daf;
    }
  }
  else {
LAB_004c9daf:
    if (iVar4 != 0) {
      for (iVar8 = *(int *)(iVar4 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar5 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar5) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar4 + 0x54)) {
              *(int *)(iVar4 + 0x54) = iVar8;
              FUN_004ff030(iVar4);
              *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0x31042d5);
      goto LAB_004c9e2c;
    }
  }
  else {
LAB_004c9e2c:
    if (iVar4 != 0) {
      for (iVar8 = *(int *)(iVar4 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar5 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar5) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar4 + 0x54)) {
              *(int *)(iVar4 + 0x54) = iVar8;
              FUN_004ff030(iVar4);
              *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0xfd9bc293);
      goto LAB_004c9eac;
    }
  }
  else {
LAB_004c9eac:
    if (iVar4 != 0) {
      for (iVar8 = *(int *)(iVar4 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar5 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar5) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar4 + 0x54)) {
              *(int *)(iVar4 + 0x54) = iVar8;
              FUN_004ff030(iVar4);
              *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c != 0) {
      iVar4 = FUN_004ef050(0xfbcca3da);
      goto LAB_004c9f2c;
    }
  }
  else {
LAB_004c9f2c:
    if (iVar4 != 0) {
      for (iVar8 = *(int *)(iVar4 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar5 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar5) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar4 + 0x54)) {
              *(int *)(iVar4 + 0x54) = iVar8;
              FUN_004ff030(iVar4);
              *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004c9ff2;
    iVar4 = FUN_004ef050(0xdfe06fad);
  }
  if (iVar4 != 0) {
    for (iVar8 = *(int *)(iVar4 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
      iVar5 = FEng__HashName();
      if (*(int *)(iVar8 + 0x30) == iVar5) {
        if (iVar8 != 0) {
          if (iVar8 != *(int *)(iVar4 + 0x54)) {
            *(int *)(iVar4 + 0x54) = iVar8;
            FUN_004ff030(iVar4);
            *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar8 + 0x10) = 0;
        }
        break;
      }
    }
  }
LAB_004c9ff2:
  local_48 = 1;
  local_44 = 5;
  do {
    bSPrintf_regdst(0x20,"Player_DATA_0%d",local_48);
    iVar4 = -1;
    pbVar6 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    iVar8 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ca0b7:
      if (iVar8 != 0) {
        iVar5 = FUN_004ef050(iVar4);
LAB_004ca0c6:
        if (iVar5 != 0) {
          iVar4 = -1;
          pbVar6 = &local_40;
          bVar3 = local_40;
          while (bVar3 != 0) {
            if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
              bVar3 = bVar3 - 0x20;
            }
            iVar4 = iVar4 * 0x21 + (uint)bVar3;
            pbVar1 = pbVar6 + 1;
            pbVar6 = pbVar6 + 1;
            bVar3 = *pbVar1;
          }
          for (iVar8 = *(int *)(iVar5 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
            if (*(int *)(iVar8 + 0x30) == iVar4) {
              if (iVar8 != 0) {
                if (iVar8 != *(int *)(iVar5 + 0x54)) {
                  *(int *)(iVar5 + 0x54) = iVar8;
                  FUN_004ff030(iVar5);
                  *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x10) = 0;
                }
                *(undefined4 *)(iVar8 + 0x10) = 0;
              }
              break;
            }
          }
        }
      }
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar8 = DAT_0073578c;
      if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004ca0a0:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar8 = DAT_0073578c, iVar5 == 0))
        goto LAB_004ca0b7;
        goto LAB_004ca0c6;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
            (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_004ca0b7;
        goto LAB_004ca0a0;
      }
    }
    bSPrintf_regdst(0x20,"HighLight0%d",local_48);
    iVar4 = -1;
    pbVar6 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    iVar8 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004ca1e7:
      if (iVar8 != 0) {
        iVar5 = FUN_004ef050(iVar4);
        goto LAB_004ca1f6;
      }
LAB_004ca23f:
      iVar5 = 0;
    }
    else {
      iVar5 = FEPackageList__FindByName(&DAT_00746104);
      iVar8 = DAT_0073578c;
      if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_004ca1e7;
          goto LAB_004ca1d0;
        }
        goto LAB_004ca23f;
      }
LAB_004ca1d0:
      if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar8 = DAT_0073578c, iVar5 == 0))
      goto LAB_004ca1e7;
LAB_004ca1f6:
      if (iVar5 != 0) {
        iVar4 = -1;
        pbVar6 = &local_40;
        bVar3 = local_40;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar4 = iVar4 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar6 + 1;
          pbVar6 = pbVar6 + 1;
          bVar3 = *pbVar1;
        }
        for (iVar8 = *(int *)(iVar5 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
          if (*(int *)(iVar8 + 0x30) == iVar4) {
            if (iVar8 != 0) {
              if (iVar8 != *(int *)(iVar5 + 0x54)) {
                *(int *)(iVar5 + 0x54) = iVar8;
                FUN_004ff030(iVar5);
                *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x10) = 0;
              }
              *(undefined4 *)(iVar8 + 0x10) = 0;
            }
            break;
          }
        }
      }
    }
    if (param_2 == '\0') {
      FEObject__SetInvisible(iVar5);
    }
    else if ((iVar5 != 0) &&
            (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
            *(int *)(iVar5 + 0x18) == 5)) {
      uVar7 = *(undefined4 *)(iVar5 + 0x60);
      iVar4 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar4) {
        do {
          FEObject__SetVisible(uVar7);
          uVar7 = *(undefined4 *)(extraout_EDX + 4);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    local_48 = local_48 + 1;
    local_44 = local_44 + -1;
    if (local_44 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4ca2d0 FUN_004ca2d0

bool FUN_004ca2d0(void)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = (char *)FUN_00565b60(0xf660,0,0,0);
  Ugd__PackBlock(&DAT_00748f80,0xf660);
  iVar3 = FUN_00565b60(0xf660,0,0,0);
  Ugd__PackBlock(&DAT_007588c4,0xf660);
  bVar1 = false;
  iVar4 = 0;
  iVar3 = iVar3 - (int)pcVar2;
  do {
    if (*pcVar2 != pcVar2[iVar3]) {
      bVar1 = true;
      break;
    }
    iVar4 = iVar4 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar4 < 0xf660);
  FUN_00565ce0();
  FUN_00565ce0();
  return !bVar1;
}


// ==== 0x4ca360 FUN_004ca360

void __thiscall FUN_004ca360(int param_1,int param_2)

{
  if (param_2 == 0x35f8620b) {
    switch(DAT_00735e3c) {
    case 1:
      DAT_00735dbd = 0;
      *(code **)(param_1 + 0x40) = FUN_004cab00;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 2:
      DAT_00735dbd = 0;
      *(code **)(param_1 + 0x40) = FUN_004cafd0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 3:
      *(code **)(param_1 + 0x40) = FUN_004cb740;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 4:
      *(code **)(param_1 + 0x40) = FUN_004cbad0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 5:
      DAT_00735dbd = 0;
      *(undefined1 *)(param_1 + 0xb4) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cbd20;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 6:
      *(undefined1 *)(param_1 + 0xb5) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cbe30;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    case 7:
      *(code **)(param_1 + 0x40) = FUN_004cc400;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
  }
  return;
}


// ==== 0x4ca430 FUN_004ca430

void __thiscall FUN_004ca430(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x44);
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
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0xd36620fe;
    uStack_20 = 0xf770;
    uStack_1c = 0x12312300;
    uStack_18 = 0x61c;
    uStack_14 = 0x12312311;
    uStack_10 = 0;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4ca500 FUN_004ca500

void __thiscall FUN_004ca500(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      iVar2 = 0;
      if (DAT_00777b74 != '\0') {
        do {
          pcVar1 = &DAT_00777b75 + iVar2;
          iVar2 = iVar2 + 1;
        } while (*pcVar1 != '\0');
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x44);
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
      }
    }
    else {
      if (param_2 != 0x12312311) {
        return;
      }
      DAT_00735e4c = 1;
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
    }
    FUN_004c9650();
    return;
  }
  if (param_2 != -0x367ca946) {
    return;
  }
  bVar3 = DAT_006fad58 != 2;
  *(undefined1 *)(param_1 + 0x48) = 0;
  if (bVar3) {
    FUN_004ec4d0(3,0x12312311,0xceffd44);
    return;
  }
  FUN_004ec4d0(3,0xffffffff,0xceffd44);
  return;
}


// ==== 0x4ca5e0 FUN_004ca5e0

void __thiscall FUN_004ca5e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004ca670;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
  }
  else if (param_2 == -0x367ca946) {
    uStack_8 = 0x12312300;
    uStack_4 = 0x12312300;
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_10 = 0xa40797c9;
    uStack_c = 0x639;
    FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4ca670 FUN_004ca670

void __thiscall FUN_004ca670(int param_1,int param_2)

{
  void *_Memory;
  undefined4 *puVar1;
  int iVar2;
  
  DAT_00735dbd = '\0';
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      if (DAT_00735dc0 != 0) {
        _Memory = *(void **)(param_1 + 0xac);
        if (DAT_00735dc0 == 2) {
          if (_Memory != (void *)0x0) {
            if (*(int *)((int)_Memory + 0xc) != 0) {
              FUN_00565ce0();
            }
            _free(_Memory);
          }
          *(undefined4 *)(param_1 + 0xac) = 0;
          *(undefined1 *)(param_1 + 0xb9) = 1;
          *(code **)(param_1 + 0x40) = FUN_004ca670;
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
        if (_Memory != (void *)0x0) {
          if (*(int *)((int)_Memory + 0xc) != 0) {
            FUN_00565ce0();
          }
          _free(_Memory);
        }
        *(undefined4 *)(param_1 + 0xac) = 0;
        if (*(char *)(param_1 + 0xb9) != '\0') {
          DAT_00735dbd = *(char *)(param_1 + 0xb9);
        }
        FUN_004c9650();
        return;
      }
      *(code **)(param_1 + 0x40) = FUN_004ca790;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    puVar1 = _malloc(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0x20;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
    }
    *(undefined4 **)(param_1 + 0xac) = puVar1;
    FUN_004eb420(0x12312300,puVar1);
    return;
  }
  return;
}


// ==== 0x4ca790 FUN_004ca790

void __thiscall FUN_004ca790(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      pvVar1 = *(void **)(param_1 + 0xac);
      if (pvVar1 != (void *)0x0) {
        if (*(int *)((int)pvVar1 + 0xc) != 0) {
          FUN_00565ce0();
        }
        _free(pvVar1);
      }
      *(undefined4 *)(param_1 + 0xac) = 0;
      *(code **)(param_1 + 0x40) = FUN_004ca670;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      pvVar1 = *(void **)(param_1 + 0xac);
      if (pvVar1 != (void *)0x0) {
        if (*(int *)((int)pvVar1 + 0xc) != 0) {
          FUN_00565ce0();
        }
        _free(pvVar1);
      }
      *(undefined4 *)(param_1 + 0xac) = 0;
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
      }
      FUN_004c9650();
      return;
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    if (*(int *)(*(int *)(param_1 + 0xac) + 8) != 0) {
      *(code **)(param_1 + 0x40) = FUN_004ca8f0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    }
    local_8 = 0;
    local_4 = 0;
    local_24 = 0xab1f0e92;
    local_20 = 0x39df715;
    local_1c = 0x12312300;
    local_18 = 0x541389e5;
    local_14 = 0x12312311;
    local_10 = 0;
    local_c = 0xb8a7c6cd;
    FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4ca8f0 FUN_004ca8f0

void __thiscall FUN_004ca8f0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 < 0x911ab365) {
      if (param_2 == 0x911ab364) {
        pvVar4 = *(void **)(param_1 + 0xac);
        if (pvVar4 != (void *)0x0) {
          if (*(int *)((int)pvVar4 + 0xc) != 0) {
            FUN_00565ce0();
          }
          _free(pvVar4);
        }
        *(undefined4 *)(param_1 + 0xac) = 0;
        FUN_004c9d20(param_1,0);
        if (*(char *)(param_1 + 0xb9) != '\0') {
          DAT_00735dbd = *(char *)(param_1 + 0xb9);
        }
        FUN_004c9650();
        return;
      }
      if (param_2 == 0x406415e3) {
        iVar8 = StringList__GetSelectedString();
        pcVar10 = (char *)(param_1 + 0x69);
        iVar11 = 0x20;
        iVar8 = iVar8 - (int)pcVar10;
        do {
          cVar3 = pcVar10[iVar8];
          iVar11 = iVar11 + -1;
          *pcVar10 = cVar3;
          if (cVar3 == '\0') break;
          pcVar10 = pcVar10 + 1;
        } while (iVar11 != 0);
        pvVar4 = *(void **)(param_1 + 0xac);
        if (pvVar4 != (void *)0x0) {
          if (*(int *)((int)pvVar4 + 0xc) != 0) {
            FUN_00565ce0();
          }
          _free(pvVar4);
        }
        *(undefined4 *)(param_1 + 0xac) = 0;
        FUN_004c9d20(param_1,0);
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x44);
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
      if (param_2 == 0x72619778) {
        FUN_004f9060();
        return;
      }
    }
    else if (param_2 == 0x911c0a4b) {
      piVar9 = *(int **)(param_1 + 0x8c);
      piVar2 = (int *)(param_1 + 0x8c);
      if (((piVar9 != piVar2) &&
          (puVar1 = (undefined4 *)(param_1 + 0x94), *(undefined4 **)(param_1 + 0x94) != puVar1)) &&
         (puVar5 = (undefined4 *)**(int **)(param_1 + 0x9c), puVar5 != puVar1)) {
        iVar8 = 0;
        *(undefined4 **)(param_1 + 0x9c) = puVar5;
        for (puVar6 = *(undefined4 **)(param_1 + 0xa0);
            (puVar6 != puVar1 && (iVar8 = iVar8 + 1, puVar6 != puVar5));
            puVar6 = (undefined4 *)*puVar6) {
        }
        iVar11 = 0;
        do {
          iVar11 = iVar11 + 1;
          if (piVar9 == (int *)0x0) break;
          piVar9 = (int *)*piVar9;
        } while (piVar9 != piVar2);
        if (iVar11 < iVar8) {
          *(undefined4 *)(param_1 + 0xa0) = **(undefined4 **)(param_1 + 0xa0);
        }
        if (*(int *)(param_1 + 0xa4) != *(int *)(param_1 + 0x90)) {
          FUN_004f8ec0(*(int *)(param_1 + 0xa4));
          uVar7 = **(undefined4 **)(param_1 + 0xa4);
          *(undefined4 *)(param_1 + 0xa4) = uVar7;
          FUN_004f8dd0(uVar7);
        }
        FUN_004f9240(piVar2);
      }
    }
    else if ((param_2 == 0xc98356ba) && (DAT_00735dbd != '\0')) {
      pvVar4 = *(void **)(param_1 + 0xac);
      if (pvVar4 != (void *)0x0) {
        if (*(int *)((int)pvVar4 + 0xc) != 0) {
          FUN_00565ce0();
        }
        _free(pvVar4);
      }
      *(undefined4 *)(param_1 + 0xac) = 0;
      FUN_004c9d20(param_1,0);
      *(undefined1 *)(param_1 + 0xb9) = 1;
      *(code **)(param_1 + 0x40) = FUN_004ca5e0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    FUN_004c9d20(param_1,1);
    FUN_004c9c20();
    return;
  }
  return;
}


// ==== 0x4cab00 FUN_004cab00

void __fastcall FUN_004cab00(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_004ca2d0(param_1);
  if ((cVar1 == '\0') && (DAT_00748f75 == '\0')) {
    *(code **)(param_1 + 0x40) = FUN_004cab40;
    *(undefined1 *)(param_1 + 0x48) = 1;
    return;
  }
  *(code **)(param_1 + 0x40) = FUN_004cab60;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


// ==== 0x4cab40 FUN_004cab40

void __fastcall FUN_004cab40(int param_1)

{
  *(code **)(param_1 + 0x40) = FUN_004ca430;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cab60;
  return;
}


// ==== 0x4cab60 FUN_004cab60

void __fastcall FUN_004cab60(int param_1)

{
  *(code **)(param_1 + 0x40) = FUN_004ca500;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cab80;
  return;
}


// ==== 0x4cab80 FUN_004cab80

void __thiscall FUN_004cab80(int param_1,int param_2)

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
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004caca0;
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
    bSPrintf_regdst(0x100,iVar1,&DAT_00777b74);
    uStack_124 = 0xf770;
    uStack_120 = 0xf770;
    uStack_108 = 0;
    uStack_104 = 0;
    uStack_11c = 0x12312300;
    uStack_118 = 0x61c;
    uStack_114 = 0x12312311;
    uStack_110 = 0;
    uStack_10c = 0xb8a7c6cc;
    FUN_004dc6e0(&uStack_124,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    FUN_004dccc0(auStack_100);
    return;
  }
  return;
}


// ==== 0x4caca0 FUN_004caca0

void __thiscall FUN_004caca0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(undefined1 *)(param_1 + 0xb6) = 1;
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cadc0;
    }
    else {
      if (param_2 == 0x12312311) {
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        *(undefined1 *)(param_1 + 0xb6) = 0;
        *(undefined1 *)(param_1 + 0x48) = 1;
        *(code **)(param_1 + 0x40) = FUN_004cadc0;
        return;
      }
      if (param_2 == 0x12312322) {
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        *(code **)(param_1 + 0x40) = FUN_004cab80;
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0xf3568b86;
    uStack_20 = 0xf770;
    uStack_1c = 0x12312300;
    uStack_18 = 0x61c;
    uStack_14 = 0x12312311;
    uStack_10 = 0x12312322;
    uStack_c = 0xb8a7c6cc;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cadc0 FUN_004cadc0

void __thiscall FUN_004cadc0(int param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00689593;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      ExceptionList = &pvStack_c;
      FUN_00565ce0();
      bVar5 = DAT_00735dc0 == 0;
      *(undefined4 *)(param_1 + 0xb0) = 0;
      if (bVar5) {
        iVar3 = FUN_004f65d0();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0xff;
        }
        FUN_004aa5e0(1);
        DAT_007677b0 = (uint)(*(char *)(param_1 + 0xb6) != '\0');
        DAT_007677b4 = 0;
        Player__Init(1);
      }
      else {
        iVar3 = FUN_004f65d0();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0xff;
        }
        if (DAT_00735dc0 == 9) {
          DAT_00735dbd = 1;
          *(code **)(param_1 + 0x40) = FUN_004cb5f0;
          *(undefined1 *)(param_1 + 0x48) = 1;
          ExceptionList = pvStack_c;
          return;
        }
        if (DAT_00735dc0 != 6) {
          *(code **)(param_1 + 0x40) = FUN_004cb5f0;
          *(undefined1 *)(param_1 + 0x48) = 1;
          ExceptionList = pvStack_c;
          return;
        }
      }
      FUN_004c9650();
    }
  }
  else if (param_2 == -0x367ca946) {
    ExceptionList = &pvStack_c;
    *(undefined1 *)(param_1 + 0x48) = 0;
    pvVar1 = _malloc(0xf944);
    uStack_4 = 0;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = (void *)FUN_004aa200();
    }
    uStack_4 = 0xffffffff;
    Player__Init(1);
    *(undefined4 *)((int)pvVar1 + 0xeeec) = 0;
    *(undefined4 *)((int)pvVar1 + 0x210) = 0;
    *(undefined1 *)((int)pvVar1 + 0xeef0) = 1;
    puVar4 = (undefined4 *)((int)pvVar1 + 0x214);
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    CustomizationDB__Init((int)pvVar1 + 0x364,DAT_006f1da4);
    FUN_004ac220();
    Career__Reset();
    puVar4 = (undefined4 *)((int)pvVar1 + 0xeef4);
    for (iVar3 = 0x294; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)((int)pvVar1 + 0xeee8) = 0;
    Player__Init(1);
    *(uint *)((int)pvVar1 + 0xeeec) = (uint)(*(char *)(param_1 + 0xb6) != '\0');
    uVar2 = FUN_00565b60(0xf660,0,0,0);
    *(undefined4 *)(param_1 + 0xb0) = uVar2;
    Ugd__PackBlock(pvVar1,0xf660);
    Career___Career((int)pvVar1 + 0x6634);
    _free(pvVar1);
    FUN_004eb560(0x12312300,&DAT_00777b74,*(undefined4 *)(param_1 + 0xb0),0xf660);
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4cafd0 FUN_004cafd0

void __fastcall FUN_004cafd0(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (DAT_007588d1 == '\0') {
    *(undefined1 *)(param_1 + 0xb5) = 0;
    *(code **)(param_1 + 0x40) = FUN_004cb030;
    *(undefined1 *)(param_1 + 0x48) = 1;
    return;
  }
  iVar2 = 0x9c;
  pcVar1 = &DAT_00777b74;
  do {
    iVar2 = iVar2 + -1;
    *pcVar1 = pcVar1[-0x1f2b0];
    if (pcVar1[-0x1f2b0] == '\0') break;
    pcVar1 = pcVar1 + 1;
  } while (iVar2 != 0);
  *(code **)(param_1 + 0x40) = FUN_004cb130;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


// ==== 0x4cb030 FUN_004cb030

void __thiscall FUN_004cb030(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004cb110;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      DAT_00735e4c = 0;
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
    local_8 = 0;
    local_4 = 0;
    local_24 = 0xd84fe2eb;
    local_20 = 0x639;
    local_1c = 0x12312300;
    local_18 = 0x541389e5;
    local_14 = 0x12312311;
    local_10 = 0;
    local_c = 0xb8a7c6cd;
    FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cb110 FUN_004cb110

void __fastcall FUN_004cb110(int param_1)

{
  *(code **)(param_1 + 0x40) = FUN_004ca500;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cb130;
  return;
}


// ==== 0x4cb130 FUN_004cb130

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
          *(code **)(param_1 + 0x40) = FUN_004cb320;
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
      }
      else {
        DAT_007677b0 = 1;
      }
      *(code **)(param_1 + 0x40) = FUN_004cb480;
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


// ==== 0x4cb320 FUN_004cb320

void __thiscall FUN_004cb320(int param_1,int param_2)

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
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_007677b0 = 1;
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cb480;
    }
    else {
      if (param_2 == 0x12312311) {
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        DAT_007677b0 = 0;
        *(undefined1 *)(param_1 + 0x48) = 1;
        *(code **)(param_1 + 0x40) = FUN_004cb480;
        return;
      }
      if (param_2 == 0x12312322) {
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        *(code **)(param_1 + 0x40) = FUN_004cb130;
        *(undefined1 *)(param_1 + 0x48) = 1;
        DAT_00735e4c = 1;
        FUN_004c9650();
        return;
      }
    }
  }
  else if (param_2 == -0x367ca946) {
    bVar2 = DAT_006fad58 == 2;
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_c = 0xb8a7c6cc;
    uStack_14 = 0x12312311;
    uStack_18 = 0x61c;
    uStack_1c = 0x12312300;
    uStack_20 = 0xf770;
    uStack_24 = 0xf3568b86;
    uStack_4 = 0;
    uStack_8 = 0;
    if (bVar2) {
      uStack_10 = 0;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    uStack_10 = 0x12312322;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cb480 FUN_004cb480

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
        *(code **)(param_1 + 0x40) = FUN_004cc1c0;
        return;
      }
LAB_004cb5aa:
      *(undefined1 *)(param_1 + 0x48) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cb5f0;
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


// ==== 0x4cb5f0 FUN_004cb5f0

void __thiscall FUN_004cb5f0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_007677b0 = 0;
      FUN_004c9650();
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_c = 0x639;
    uStack_4 = 0x12312300;
    uStack_8 = 0x12312300;
    if (DAT_007677b0 == 1) {
      uStack_10 = 0xd183936b;
      FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    uStack_10 = 0xa959b6be;
    FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cb6b0 FUN_004cb6b0

void __thiscall FUN_004cb6b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
      }
      FUN_004c9650();
    }
  }
  else if (param_2 == -0x367ca946) {
    local_8 = 0x12312300;
    local_4 = 0x12312300;
    *(undefined1 *)(param_1 + 0x48) = 0;
    local_10 = 0xf6aef38f;
    local_c = 0x639;
    FUN_004dcbe0(&local_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cb740 FUN_004cb740

void __fastcall FUN_004cb740(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_004ca2d0(param_1);
  if ((cVar1 == '\0') && (DAT_00748f75 == '\0')) {
    *(code **)(param_1 + 0x40) = FUN_004cb780;
    *(undefined1 *)(param_1 + 0x48) = 1;
    return;
  }
  *(code **)(param_1 + 0x40) = FUN_004cb7a0;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


// ==== 0x4cb780 FUN_004cb780

void __fastcall FUN_004cb780(int param_1)

{
  *(code **)(param_1 + 0x40) = FUN_004ca430;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cb7a0;
  return;
}


// ==== 0x4cb7a0 FUN_004cb7a0

void __fastcall FUN_004cb7a0(int param_1)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  *(undefined1 *)(param_1 + 0xb9) = DAT_00735dbd;
  *(code **)(param_1 + 0x40) = FUN_004ca670;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cb7f0;
  return;
}


// ==== 0x4cb7f0 FUN_004cb7f0

void __thiscall FUN_004cb7f0(int param_1,int param_2)

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
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004cb920;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
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
    bSPrintf_regdst(0x100,iVar1,param_1 + 0x69);
    uStack_108 = 0;
    uStack_104 = 0;
    uStack_124 = 0xf770;
    uStack_120 = 0xf770;
    uStack_11c = 0x12312300;
    uStack_118 = 0x61c;
    uStack_114 = 0x12312311;
    uStack_110 = 0;
    uStack_10c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_124,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    FUN_004dccc0(auStack_100);
    return;
  }
  return;
}


// ==== 0x4cb920 FUN_004cb920

void __thiscall FUN_004cb920(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x48) != '\0') {
    if (param_2 != -0x367ca946) {
      return;
    }
    *(undefined1 *)(param_1 + 0x48) = 0;
    FUN_004eb3f0();
    if (DAT_00735dbd != '\0') {
      *(code **)(param_1 + 0x40) = FUN_004cb6b0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    }
    uVar1 = FUN_00565b60(0xf660,0,0,0);
    *(undefined4 *)(param_1 + 0xb0) = uVar1;
    FUN_004eb610(0x12312300,param_1 + 0x69,uVar1,0xf660);
    return;
  }
  if (param_2 != 0x12312300) {
    return;
  }
  iVar2 = FUN_004f65d0();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0xff;
  }
  if (DAT_00735dc0 == 0) {
    DAT_00735dbd = '\0';
    Ugd__UnpackBlock(1);
    DAT_007677b4 = 0;
  }
  else {
    if (DAT_00735dc0 == 9) {
      *(undefined1 *)(param_1 + 0xb9) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cb6b0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      goto LAB_004cba20;
    }
    if (DAT_00735dc0 == 2) {
      *(undefined1 *)(param_1 + 0xb9) = 1;
      *(code **)(param_1 + 0x40) = FUN_004cb7a0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      goto LAB_004cba20;
    }
    if (*(char *)(param_1 + 0xb9) != '\0') {
      DAT_00735dbd = *(char *)(param_1 + 0xb9);
    }
  }
  FUN_004c9650();
LAB_004cba20:
  FUN_00565ce0();
  *(undefined4 *)(param_1 + 0xb0) = 0;
  return;
}


// ==== 0x4cba40 FUN_004cba40

void __thiscall FUN_004cba40(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
      }
      FUN_004c9650();
    }
  }
  else if (param_2 == -0x367ca946) {
    uStack_8 = 0x12312300;
    uStack_4 = 0x12312300;
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_10 = 0xd01259a2;
    uStack_c = 0x639;
    FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cbad0 FUN_004cbad0

void __fastcall FUN_004cbad0(int param_1)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  *(undefined1 *)(param_1 + 0xb9) = DAT_00735dbd;
  *(code **)(param_1 + 0x40) = FUN_004ca670;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cbb20;
  return;
}


// ==== 0x4cbb20 FUN_004cbb20

void __thiscall FUN_004cbb20(int param_1,int param_2)

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
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004cbc50;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
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
    bSPrintf_regdst(0x100,iVar1,param_1 + 0x69);
    uStack_108 = 0;
    uStack_104 = 0;
    uStack_124 = 0x639;
    uStack_120 = 0x639;
    uStack_11c = 0x12312300;
    uStack_118 = 0x541389e5;
    uStack_114 = 0x12312311;
    uStack_110 = 0;
    uStack_10c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_124,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    FUN_004dccc0(auStack_100);
    return;
  }
  return;
}


// ==== 0x4cbc50 FUN_004cbc50

void __thiscall FUN_004cbc50(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (DAT_00735dc0 != 0) {
        if (DAT_00735dc0 == 9) {
          *(undefined1 *)(param_1 + 0xb9) = 1;
          *(code **)(param_1 + 0x40) = FUN_004cba40;
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
        if (DAT_00735dc0 == 2) {
          *(undefined1 *)(param_1 + 0xb9) = 1;
          *(code **)(param_1 + 0x40) = FUN_004cbad0;
          *(undefined1 *)(param_1 + 0x48) = 1;
          return;
        }
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
      }
      FUN_004c9650();
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    FUN_004eb3f0();
    if (DAT_00735dbd == '\0') {
      FUN_004eb6c0(0x12312300,param_1 + 0x69);
      return;
    }
    *(code **)(param_1 + 0x40) = FUN_004cba40;
    *(undefined1 *)(param_1 + 0x48) = 1;
    return;
  }
  return;
}


// ==== 0x4cbd20 FUN_004cbd20

void __fastcall FUN_004cbd20(int param_1)

{
  if (DAT_007588d1 != '\0') {
    DAT_007677b0 = 1;
    FUN_004c9650();
    return;
  }
  *(code **)(param_1 + 0x40) = FUN_004cbd50;
  *(undefined1 *)(param_1 + 0x48) = 1;
  return;
}


// ==== 0x4cbd50 FUN_004cbd50

void __thiscall FUN_004cbd50(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004cb110;
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
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0x609e0bf8;
    uStack_20 = 0x639;
    uStack_1c = 0x12312300;
    uStack_18 = 0x541389e5;
    uStack_14 = 0x12312311;
    uStack_10 = 0;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cbe30 FUN_004cbe30

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
        *(code **)(param_1 + 0x40) = FUN_004cafd0;
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
      *(code **)(param_1 + 0x40) = FUN_004cbfd0;
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


// ==== 0x4cbed0 FUN_004cbed0

void __thiscall FUN_004cbed0(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 != 0x12312300) {
      if (param_2 == 0x12312311) {
        DAT_00735e4c = 0;
      }
      else {
        if (param_2 != 0x12312322) {
          return;
        }
        DAT_00735e4c = 1;
      }
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_007677b0 = 0;
      *(code **)(param_1 + 0x40) = FUN_004cbfd0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      return;
    }
    DAT_00735e4c = 0;
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0xff;
    }
    *(code **)(param_1 + 0x40) = FUN_004cafd0;
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    local_8 = 0;
    local_4 = 0;
    local_24 = 0x8f1436a4;
    local_20 = 0xf770;
    local_1c = 0x12312300;
    local_18 = 0x61c;
    local_14 = 0x12312311;
    local_10 = 0x12312322;
    local_c = 0xb8a7c6cd;
    FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cbfd0 FUN_004cbfd0

void __thiscall FUN_004cbfd0(int param_1,int param_2)

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
  
  iVar1 = DAT_006fad58;
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_00735dbd = 0;
      *(code **)(param_1 + 0x40) = FUN_004cafd0;
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
    bVar2 = DAT_006fad58 == 0;
    *(undefined1 *)(param_1 + 0x48) = 0;
    if (bVar2) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0xec7626d4;
      uStack_20 = 0xf770;
      uStack_1c = 0x12312300;
      uStack_18 = 0x61c;
      uStack_14 = 0x12312311;
      uStack_10 = 0x12312322;
      uStack_c = 0xb8a7c6cd;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (iVar1 == 1) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0x63c53643;
      uStack_20 = 0xf770;
      uStack_1c = 0x12312300;
      uStack_18 = 0x61c;
      uStack_14 = 0x12312311;
      uStack_10 = 0x12312322;
      uStack_c = 0xb8a7c6cd;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (iVar1 == 2) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0x73e322fd;
      uStack_20 = 0xf770;
      uStack_1c = 0x12312300;
      uStack_18 = 0x61c;
      uStack_14 = 0x12312311;
      uStack_10 = 0;
      uStack_c = 0xb8a7c6cd;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  return;
}


// ==== 0x4cc1c0 FUN_004cc1c0

void __thiscall FUN_004cc1c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(code **)(param_1 + 0x40) = FUN_004cc300;
      DAT_00735dbd = 0;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else {
      if (param_2 == 0x12312311) {
        DAT_00735e4c = 0;
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        DAT_007677b0 = 0;
        *(code **)(param_1 + 0x40) = FUN_004cafd0;
        *(undefined1 *)(param_1 + 0x48) = 1;
        DAT_00735dbd = 0;
        return;
      }
      if (param_2 == 0x12312322) {
        DAT_00735e4c = 1;
        iVar1 = FUN_004f65d0();
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0xff;
        }
        DAT_00735dbd = 0;
        DAT_007677b0 = 0;
        FUN_004c9650();
        return;
      }
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0x8f1436a4;
    uStack_20 = 0xf770;
    uStack_1c = 0x12312300;
    uStack_18 = 0x61c;
    uStack_14 = 0x12312311;
    uStack_10 = 0x12312322;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cc300 FUN_004cc300

void __thiscall FUN_004cc300(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      DAT_00735e4c = 0;
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_00735dbd = 0;
      *(code **)(param_1 + 0x40) = FUN_004cb480;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      DAT_007677b0 = 0;
      DAT_00735e4c = 1;
      DAT_00735dbd = 0;
      *(code **)(param_1 + 0x40) = FUN_004cafd0;
      *(undefined1 *)(param_1 + 0x48) = 1;
      FUN_004c9650();
      return;
    }
  }
  else if (param_2 == -0x367ca946) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0x3f7c1b01;
    uStack_20 = 0xf770;
    uStack_1c = 0x12312300;
    uStack_18 = 0x61c;
    uStack_14 = 0x12312311;
    uStack_10 = 0;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}


// ==== 0x4cc400 FUN_004cc400

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
      *(code **)(param_1 + 0x40) = FUN_004cc580;
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


// ==== 0x4cc580 FUN_004cc580

void __fastcall FUN_004cc580(int param_1)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f6850(iVar1);
  *(undefined1 *)(param_1 + 0xb9) = DAT_00735dbd;
  *(code **)(param_1 + 0x40) = FUN_004ca670;
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 0x44) = FUN_004cc5d0;
  return;
}


// ==== 0x4cc5d0 FUN_004cc5d0

void __thiscall FUN_004cc5d0(int param_1,int param_2)

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
      *(code **)(param_1 + 0x40) = FUN_004ccab0;
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    else if (param_2 == 0x12312311) {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      if (*(char *)(param_1 + 0xb9) != '\0') {
        DAT_00735dbd = *(char *)(param_1 + 0xb9);
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
    bSPrintf_regdst(0x100,iVar1,param_1 + 0x69);
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
    uStack_208 = 0;
    uStack_204 = 0;
    uStack_224 = 0xf770;
    uStack_220 = 0xf770;
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


// ==== 0x4cc770 FUN_004cc770

void __fastcall FUN_004cc770(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((in_EAX < 0) || (1 < in_EAX)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = &DAT_00758c28 + in_EAX * 0x3e51;
  }
  puVar2 = (undefined4 *)(param_2 + 0x364);
  for (iVar1 = 0x18b4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004cc7c0(&DAT_0075eef8 + in_EAX * 0x3e51,param_2 + 0x6634);
  return;
}


// ==== 0x4cc7c0 FUN_004cc7c0

undefined4 * FUN_004cc7c0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_4;
  
  puVar2 = param_2;
  puVar4 = param_1;
  for (iVar1 = 0xd2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar1 = (int)param_2 - (int)param_1;
  param_1[0xd2] = param_2[0xd2];
  puVar2 = param_1 + 0xd3;
  iVar3 = 0x100;
  do {
    *(undefined1 *)puVar2 = *(undefined1 *)(iVar1 + (int)puVar2);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = param_1 + 0x114;
  iVar3 = (int)param_2 + (0x44c - (int)(param_1 + 0x113));
  local_4 = 900;
  do {
    *puVar2 = *(undefined4 *)(iVar3 + (int)puVar2);
    puVar2 = puVar2 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  puVar2 = param_1 + 0x498;
  local_4 = 0x44;
  do {
    *puVar2 = *(undefined4 *)((int)puVar2 + iVar3);
    puVar2 = puVar2 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  *(undefined1 *)(param_1 + 0x4dc) = *(undefined1 *)(param_2 + 0x4dc);
  *(undefined1 *)((int)param_1 + 0x1371) = *(undefined1 *)((int)param_2 + 0x1371);
  param_1[0x4dd] = param_2[0x4dd];
  param_1[0x4de] = param_2[0x4de];
  param_1[0x4df] = param_2[0x4df];
  param_1[0x4e0] = param_2[0x4e0];
  *(undefined2 *)(param_1 + 0x4e1) = *(undefined2 *)(param_2 + 0x4e1);
  *(undefined1 *)((int)param_1 + 0x1386) = *(undefined1 *)((int)param_2 + 0x1386);
  *(undefined1 *)((int)param_1 + 4999) = *(undefined1 *)((int)param_2 + 4999);
  puVar2 = param_2 + 0x4e2;
  puVar4 = param_1 + 0x4e2;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x4e9] = param_2[0x4e9];
  puVar2 = param_1 + 0x4ea;
  iVar3 = 0x1b;
  do {
    FUN_004cc970((int)puVar2 + iVar1);
    puVar2 = puVar2 + 0x115;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = param_1 + 0x2221;
  iVar3 = 0x1b;
  do {
    *(undefined1 *)puVar2 = *(undefined1 *)((int)puVar2 + iVar1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)((int)param_1 + 0x889f) = *(undefined1 *)((int)param_2 + 0x889f);
  puVar2 = param_1 + 0x2228;
  iVar3 = 0x10;
  do {
    *(undefined1 *)puVar2 = *(undefined1 *)((int)puVar2 + iVar1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_1[0x222c] = param_2[0x222c];
  return param_1;
}


// ==== 0x4cc970 FUN_004cc970

void FUN_004cc970(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined1 *)unaff_EBX = *(undefined1 *)param_1;
  *(undefined1 *)((int)unaff_EBX + 1) = *(undefined1 *)((int)param_1 + 1);
  *(undefined1 *)((int)unaff_EBX + 2) = *(undefined1 *)((int)param_1 + 2);
  *(undefined1 *)((int)unaff_EBX + 3) = *(undefined1 *)((int)param_1 + 3);
  iVar1 = 0xce;
  puVar2 = param_1;
  puVar3 = unaff_EBX;
  while( true ) {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar3 = *puVar2;
  }
  unaff_EBX[0xd1] = param_1[0xd1];
  unaff_EBX[0xd3] = param_1[0xd3];
  unaff_EBX[0xd2] = param_1[0xd2];
  unaff_EBX[0xd6] = param_1[0xd6];
  unaff_EBX[0xd7] = param_1[0xd7];
  unaff_EBX[0xda] = param_1[0xda];
  unaff_EBX[0xdb] = param_1[0xdb];
  unaff_EBX[0xde] = param_1[0xde];
  unaff_EBX[0xdf] = param_1[0xdf];
  unaff_EBX[0xe0] = param_1[0xe0];
  unaff_EBX[0xe1] = param_1[0xe1];
  unaff_EBX[0xe2] = param_1[0xe2];
  unaff_EBX[0xe3] = param_1[0xe3];
  unaff_EBX[0xe4] = param_1[0xe4];
  unaff_EBX[0xe5] = param_1[0xe5];
  unaff_EBX[0xe6] = param_1[0xe6];
  unaff_EBX[0xe7] = param_1[0xe7];
  unaff_EBX[0xe8] = param_1[0xe8];
  unaff_EBX[0xe9] = param_1[0xe9];
  FUN_004c94b0();
  unaff_EBX[0x114] = param_1[0x114];
  return;
}


// ==== 0x4ccab0 FUN_004ccab0

void __thiscall FUN_004ccab0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00689593;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (param_2 == 0x12312300) {
      ExceptionList = &pvStack_c;
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      if (DAT_00735dc0 == 0) {
        pvVar3 = _malloc(0xf944);
        uStack_4 = 0;
        if (pvVar3 == (void *)0x0) {
          pvVar3 = (void *)0x0;
        }
        else {
          pvVar3 = (void *)FUN_004aa200();
        }
        uStack_4 = 0xffffffff;
        Ugd__UnpackBlock(0);
        FUN_004cc770();
        if (pvVar3 != (void *)0x0) {
          Career___Career((int)pvVar3 + 0x6634);
          _free(pvVar3);
        }
        *(code **)(param_1 + 0x40) = FUN_004ccc40;
        *(undefined1 *)(param_1 + 0x48) = 1;
      }
      else if (DAT_00735dc0 == 9) {
        *(undefined1 *)(param_1 + 0xb9) = 1;
        *(code **)(param_1 + 0x40) = FUN_004cb6b0;
        *(undefined1 *)(param_1 + 0x48) = 1;
      }
      else if (DAT_00735dc0 == 2) {
        *(undefined1 *)(param_1 + 0xb9) = 1;
        *(code **)(param_1 + 0x40) = FUN_004cc580;
        *(undefined1 *)(param_1 + 0x48) = 1;
      }
      else {
        if (*(char *)(param_1 + 0xb9) != '\0') {
          DAT_00735dbd = *(char *)(param_1 + 0xb9);
        }
        FUN_004c9650();
      }
      FUN_00565ce0();
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
  }
  else if (param_2 == -0x367ca946) {
    ExceptionList = &pvStack_c;
    *(undefined1 *)(param_1 + 0x48) = 0;
    uVar1 = FUN_00565b60(0xf660,0,0,0);
    *(undefined4 *)(param_1 + 0xb0) = uVar1;
    FUN_004eb610(0x12312300,param_1 + 0x69,uVar1,0xf660);
    ExceptionList = pvStack_c;
    return;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4ccc40 FUN_004ccc40

void __fastcall FUN_004ccc40(int param_1)

{
  if (*(char *)(param_1 + 0xb9) != '\0') {
    DAT_00735dbd = *(char *)(param_1 + 0xb9);
  }
  FUN_004c9650();
  return;
}


// ==== 0x4ccc60 FUN_004ccc60

void __fastcall FUN_004ccc60(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004ccc60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x40))();
  return;
}


// ==== 0x4ccc70 FEScreenSound_FindScreenRow

/* [canon] hud med (ghidra-canon) docs/re/hud_input.md */

int __fastcall FEScreenSound_FindScreenRow(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_00746bf8;
  do {
    if (*piVar2 == param_2) {
      return iVar1;
    }
    piVar2 = piVar2 + 7;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x746ca0);
  return -1;
}


// ==== 0x4ccc90 FEScreenSound_MapEventFromRow

/* [canon] hud med (ghidra-canon) docs/re/hud_input.md */

undefined4 __fastcall FEScreenSound_MapEventFromRow(undefined4 param_1)

{
  int in_EAX;
  
  switch(param_1) {
  case 1:
  case 8:
    return *(undefined4 *)(&DAT_00746bfc + in_EAX * 0x1c);
  case 2:
  case 9:
    return *(undefined4 *)(&DAT_00746c00 + in_EAX * 0x1c);
  case 3:
    return *(undefined4 *)(&DAT_00746c04 + in_EAX * 0x1c);
  case 4:
    return *(undefined4 *)(&DAT_00746c08 + in_EAX * 0x1c);
  case 5:
  case 7:
    return *(undefined4 *)(&DAT_00746c0c + in_EAX * 0x1c);
  case 6:
    return 5;
  case 10:
    return 9;
  case 0xb:
    return 8;
  case 0xc:
  case 0xd:
    return 10;
  default:
    return 0xffffffff;
  }
}


// ==== 0x4ccd20 FEScreenSound_MapEventDefault

/* [canon] hud med (ghidra-canon) docs/re/hud_input.md */

undefined4 FEScreenSound_MapEventDefault(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 2;
  case 2:
  case 9:
    return 3;
  case 3:
    return 0;
  case 4:
    return 1;
  case 5:
  case 7:
    return 4;
  case 6:
    return 5;
  case 10:
    return 9;
  case 0xb:
    return 8;
  case 0xc:
  case 0xd:
    return 10;
  default:
    return 0xffffffff;
  }
}


// ==== 0x4ccda0 FUN_004ccda0

undefined4 FUN_004ccda0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 0x37;
  case 2:
  case 9:
    return 0x38;
  case 3:
    return 0x39;
  case 4:
    return 0x3a;
  case 5:
  case 7:
    return 0x36;
  case 6:
    return 5;
  default:
    return 0xffffffff;
  case 0xc:
  case 0xd:
    return 10;
  }
}


// ==== 0x4cce10 PostRaceSpeech_MapRewardType2

/* [canon] hud med (ghidra-canon+hopper) docs/re/runtime.md */

undefined4 PostRaceSpeech_MapRewardType2(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 0x2c;
  case 2:
  case 9:
    return 0x2d;
  default:
    return 0xffffffff;
  case 5:
  case 7:
    return 0x28;
  case 6:
    return 5;
  case 0xc:
  case 0xd:
    return 10;
  }
}


// ==== 0x4cce70 FUN_004cce70

undefined4 FUN_004cce70(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 0x30;
  case 2:
  case 9:
    return 0x31;
  default:
    return 0xffffffff;
  case 5:
  case 7:
    return 4;
  case 6:
    return 5;
  case 0xe:
    return 0x28;
  }
}


// ==== 0x4cced0 FUN_004cced0

undefined4 __fastcall FUN_004cced0(undefined4 param_1)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 0x30;
  case 2:
  case 9:
    return 0x31;
  default:
    return 0xffffffff;
  case 5:
  case 7:
    switch(param_1) {
    case 0:
      return 0x33;
    case 1:
      return 0x34;
    case 2:
      return 0x35;
    case 3:
      return 0x36;
    case 4:
      return 0x3d;
    case 5:
      return 0x3e;
    }
switchD_004cced6_caseD_6:
    return 5;
  case 6:
    goto switchD_004cced6_caseD_6;
  case 10:
    return 9;
  case 0xb:
    return 8;
  case 0xc:
  case 0xd:
    return 10;
  }
}


// ==== 0x4ccf90 FUN_004ccf90

undefined4 __fastcall FUN_004ccf90(undefined4 param_1)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 8:
    return 0x30;
  case 2:
  case 9:
    return 0x31;
  default:
    return 0xffffffff;
  case 5:
  case 7:
    switch(param_1) {
    case 0:
      return 0x41;
    case 1:
      return 0x49;
    case 2:
      return 0x42;
    case 3:
      return 0x43;
    case 4:
      return 0x44;
    case 5:
      return 0x48;
    case 6:
      return 0x45;
    case 7:
      return 0x46;
    case 8:
      return 0x47;
    }
switchD_004ccf96_caseD_6:
    return 5;
  case 6:
    goto switchD_004ccf96_caseD_6;
  case 10:
    return 9;
  case 0xb:
    return 8;
  case 0xc:
  case 0xd:
    return 10;
  }
}


// ==== 0x4cd060 FUN_004cd060

uint __fastcall FUN_004cd060(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  
  bVar1 = false;
  piVar2 = &DAT_007469bc;
  do {
    if (0x7469bf < (int)piVar2) {
      if (!bVar1) goto LAB_004cd092;
      break;
    }
    if (*piVar2 == param_2) {
      bVar1 = true;
    }
    piVar2 = piVar2 + 1;
  } while (!bVar1);
  if (param_3 == 5) {
    return (uint)((DAT_00735e34 & 4) != 0);
  }
  if (param_3 == 6) {
    return (uint)((DAT_00735e34 & 8) != 0);
  }
  piVar2 = (int *)(param_3 + -0xc);
  if (piVar2 == (int *)0x0) {
    return (uint)((DAT_00735e34 & 1) != 0);
  }
LAB_004cd092:
  return (uint)piVar2 & 0xffffff00;
}


// ==== 0x4cd0d0 FUN_004cd0d0

undefined4 __fastcall FUN_004cd0d0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00746bf8;
  do {
    if (*piVar1 == param_2) {
      if (iVar2 != -1) {
        return 6;
      }
      break;
    }
    piVar1 = piVar1 + 7;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x746ca0);
  piVar1 = &DAT_00746dcc;
  do {
    if (*piVar1 == param_2) {
      return 7;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x746dd0);
  piVar1 = &DAT_00746ca0;
  do {
    if (*piVar1 == param_2) {
      return 3;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x746d90);
  piVar1 = &DAT_00746db4;
  do {
    if (*piVar1 == param_2) {
      return 2;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x746dcc);
  piVar1 = &DAT_00746dcc;
  do {
    if (*piVar1 == param_2) {
      return 2;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x746dd0);
  piVar1 = &DAT_00746a98;
  do {
    if (*piVar1 == param_2) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x746bf8);
  return 1;
}


// ==== 0x4cd180 FUN_004cd180

void __fastcall FUN_004cd180(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int unaff_EDI;
  
  iVar9 = -1;
  bVar2 = *param_1;
  while (bVar2 != 0) {
    iVar9 = iVar9 * 0x21 + (uint)bVar2;
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    bVar2 = *pbVar1;
  }
  piVar4 = &DAT_007469b4;
  do {
    if (iVar9 == *piVar4) {
      if (unaff_EDI == 7) {
        return;
      }
      if (unaff_EDI == 5) {
        return;
      }
      break;
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x7469bc);
  cVar3 = FUN_004cd060();
  if (cVar3 == '\0') {
    pcVar8 = "HELP_Generic.fng";
    iVar7 = -1;
    uVar5 = 0x48;
    do {
      iVar7 = iVar7 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar8 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar8 = pcVar8 + 1;
    } while (*pbVar1 != 0);
    if ((iVar9 != iVar7) || ((unaff_EDI != 1 && (unaff_EDI != 2)))) {
      uVar6 = FUN_004cd0d0();
      switch(uVar6) {
      case 1:
        iVar9 = FEScreenSound_MapEventDefault();
        break;
      case 2:
        iVar9 = PostRaceSpeech_MapRewardType2();
        break;
      case 3:
        iVar9 = FUN_004cce70();
        break;
      case 4:
        iVar9 = FUN_004cced0();
        break;
      case 5:
        iVar9 = FUN_004ccf90();
        break;
      case 6:
        iVar9 = FEScreenSound_FindScreenRow();
        if (iVar9 == -1) {
          return;
        }
        iVar9 = FEScreenSound_MapEventFromRow();
        break;
      case 7:
        iVar9 = FUN_004ccda0();
        break;
      default:
        goto switchD_004cd213_default;
      }
      if (iVar9 != -1) {
        EAXSound__PlayUISoundFX();
        return;
      }
    }
  }
switchD_004cd213_default:
  return;
}


// ==== 0x4cd2a0 FEScreenBase::FEScreenBase

/* [canon] hud med (ghidra) docs/re/gameflow.md */

void __fastcall FEScreenBase__FEScreenBase(undefined4 param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  undefined4 *in_EAX;
  int *piVar4;
  int iVar5;
  
  *in_EAX = &PTR_FUN_006c41f4;
  iVar5 = -1;
  bVar2 = *param_2;
  while (bVar2 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar2;
    pbVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  in_EAX[2] = iVar5;
  *(undefined1 *)(in_EAX + 1) = 0;
  if ((DAT_00745e40 == 1) || (DAT_00777b4c == 1)) {
    piVar4 = &DAT_00746a8c;
    do {
      if (*piVar4 == iVar5) goto LAB_004cd31c;
      piVar4 = piVar4 + 1;
    } while ((int)piVar4 < 0x746a94);
    cVar3 = FUN_004cd460();
    if (((cVar3 != '\0') && (DAT_006f1dd8 != 0)) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0))
    {
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(10);
    }
  }
LAB_004cd31c:
  FUN_004cd490(0);
  return;
}


// ==== 0x4cd330 FUN_004cd330

void * __thiscall FUN_004cd330(void *param_1,byte param_2)

{
  FUN_004cd350();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4cd350 FUN_004cd350

void __fastcall FUN_004cd350(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c41f4;
  if ((DAT_00745e40 == 1) || (DAT_00777b4c == 1)) {
    piVar2 = &DAT_00746a8c;
    do {
      if (*piVar2 == param_1[2]) goto LAB_004cd3ae;
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x746a94);
    cVar1 = FUN_004cd460();
    if (((cVar1 != '\0') && (DAT_006f1dd8 != 0)) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0))
    {
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(0xb);
    }
  }
LAB_004cd3ae:
  if (((*(char *)(param_1 + 1) != '\0') && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
     (piVar2 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar2 != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x004cd3d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0xa0))();
    return;
  }
  return;
}


// ==== 0x4cd3e0 FUN_004cd3e0

void __fastcall FUN_004cd3e0(int param_1)

{
  int iVar1;
  
  if (0 < param_1) {
    iVar1 = 0;
    while ((&DAT_006fa738)[iVar1 * 2] != param_1) {
      iVar1 = iVar1 + 1;
      if (0xe < iVar1) {
        return;
      }
    }
    if (*(int *)(iVar1 * 8 + 0x6fa73c) != -1) {
      EAXSound__PlaySpeechStream(0xffffffff);
    }
  }
  return;
}


// ==== 0x4cd420 FUN_004cd420

undefined4 __fastcall FUN_004cd420(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (param_1 == (&DAT_007469c0)[iVar1 * 2]) {
      return *(undefined4 *)(&DAT_007469c4 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x19);
  return 0;
}


// ==== 0x4cd440 FUN_004cd440

undefined4 __fastcall FUN_004cd440(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (param_1 == (&DAT_006fa7f0)[iVar1 * 2]) {
      return *(undefined4 *)(iVar1 * 8 + 0x6fa7f4);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x19);
  return 0xffffffff;
}


// ==== 0x4cd460 FUN_004cd460

uint __fastcall FUN_004cd460(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_00746d90)[uVar1]) {
      return CONCAT31((int3)(uVar1 >> 8),(&DAT_00746d90)[uVar1] != 0);
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 9);
  return uVar1 & 0xffffff00;
}


// ==== 0x4cd490 FUN_004cd490

void FUN_004cd490(int param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int unaff_EDI;
  
  if ((DAT_00745e40 == 1) || (DAT_00777b4c == 1)) {
    piVar2 = &DAT_00746a8c;
    do {
      if (*piVar2 == *(int *)(unaff_EDI + 8)) {
        return;
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x746a94);
    if (param_1 == 0) {
      uVar3 = FUN_004cd420();
      if (((uVar3 != 0) && ((DAT_0076029c & uVar3) == 0)) && (iVar4 = FUN_004cd440(), iVar4 != -1))
      {
        EAXSound__PlaySpeechStream(0xffffffff);
        *(undefined1 *)(unaff_EDI + 4) = 1;
        DAT_0076029c = DAT_0076029c | uVar3;
      }
    }
    else if (param_1 == 1) {
      cVar1 = FUN_004cd460();
      if (((cVar1 != '\0') && (DAT_006f1dd8 != 0)) && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)
         ) {
        (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(10);
        return;
      }
    }
    else if (((param_1 == 2) && (cVar1 = FUN_004cd460(), cVar1 != '\0')) &&
            ((DAT_006f1dd8 != 0 && (*(int **)(DAT_007356a8 + 0xc0) != (int *)0x0)))) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xc0) + 0x14))(0xb);
      return;
    }
  }
  return;
}


// ==== 0x4cd580 FUN_004cd580

void __fastcall FUN_004cd580(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c41c8;
  FUN_004f7b50();
  return;
}


// ==== 0x4cd590 FUN_004cd590

void * __thiscall FUN_004cd590(void *param_1,byte param_2)

{
  FUN_004cd580();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4cd5b0 Screen_MU_Pause_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_Pause_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688a43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x74);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_Pause_PC__Screen_MU_Pause_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4cd610 FUN_004cd610

bool FUN_004cd610(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(DAT_007361f0 + 0x1c);
  if (DAT_007361b4 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(DAT_007361b4 + 8);
  }
  if (iVar1 == iVar2) {
    return false;
  }
  if (DAT_007361b8 != 0) {
    return iVar1 == *(int *)(DAT_007361b8 + 8);
  }
  return iVar1 == -1;
}


// ==== 0x4cd660 Screen_MU_Pause_PC::Screen_MU_Pause_PC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_Pause_PC__Screen_MU_Pause_PC(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar1 = DAT_007361f0;
  *param_1 = &PTR_FUN_006c41c8;
  param_1[0x10] = 0;
  iVar1 = *(int *)(iVar1 + 0x1c);
  local_4 = 0;
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else if (iVar1 == 1) {
    uVar2 = 2;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else {
    uVar2 = (iVar1 != 3) - 1 & 8;
  }
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = uVar2;
  }
  if (param_1[3] == 0) {
LAB_004cd701:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xa9464188);
    }
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_004cd701;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004cd701;
  }
  FEObject__SetInvisible(iVar1);
  if (param_1[3] != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004cd764;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x13dccc51);
  }
LAB_004cd764:
  FEObject__SetInvisible(iVar1);
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)((int)param_1 + 0x6e) = 0;
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  param_1[0x10] = DAT_0073ad3c;
  FUN_004cdea0();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4cd7b0 FUN_004cd7b0

void __thiscall FUN_004cd7b0(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  if (param_2 < 0xb5af2462) {
    if (param_2 == 0xb5af2461) {
      iVar2 = int_NotEqual(&DAT_0073ad3c);
      if ((iVar2 != 0) && ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1)) {
        *(undefined1 *)(param_1 + 0x6c) = 1;
        return;
      }
    }
    else if (param_2 == 0xc407210) {
      if ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1) {
        switch(*(undefined4 *)(param_3 + 0x10)) {
        case 0x1aec7d09:
          (**(code **)(param_1 + 0x44))();
          return;
        case 0x1aec7d0a:
          (**(code **)(param_1 + 0x48))();
          return;
        case 0x1aec7d0b:
          (**(code **)(param_1 + 0x4c))();
          return;
        case 0x1aec7d0c:
          (**(code **)(param_1 + 0x50))();
          return;
        case 0x1aec7d0d:
          (**(code **)(param_1 + 0x54))();
          return;
        }
      }
    }
    else if (param_2 == 0x35f8620b) {
      iVar2 = FUN_004f64d0(*(undefined4 *)(param_1 + 0xc));
      if (param_3 == iVar2) {
        FEObject__SetScript("Highlight",1);
        return;
      }
    }
    else if ((param_2 == 0x7e9ccc8f) && ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1)) {
      *(undefined1 *)(param_1 + 0x6e) = 1;
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
      FEManager__PushPackageChecked(0x32,0);
    }
    if (*(char *)(param_1 + 0x6c) != '\0') {
      if (*(char *)(param_1 + 0x70) == '\0') {
        iVar2 = FUN_004f65d0();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0;
        }
        FUN_004ce5f0(param_1);
      }
      else {
        cVar1 = FUN_004f6c80("FadeOut");
        iVar2 = DAT_007361f0;
        if (cVar1 == '\0') {
          *(undefined1 *)(param_1 + 0x70) = 0;
          FUN_00421c00(iVar2,6,1);
        }
      }
    }
    if (*(char *)(param_1 + 0x6d) != '\0') {
      if (*(char *)(param_1 + 0x70) == '\0') {
        iVar2 = FUN_004f65d0();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0;
        }
        FUN_004ce5f0(param_1);
      }
      else {
        cVar1 = FUN_004f6c80("FadeOut");
        iVar2 = DAT_007361f0;
        if (cVar1 == '\0') {
          *(undefined1 *)(param_1 + 0x70) = 0;
          FUN_00421c00(iVar2,6,2);
        }
      }
    }
    if (*(char *)(param_1 + 0x6e) != '\0') {
      if (*(char *)(param_1 + 0x70) == '\0') {
        iVar2 = FUN_004f65d0();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0;
        }
        FUN_004ce5f0(param_1);
      }
      else {
        cVar1 = FUN_004f6c80("FadeOut");
        if (cVar1 == '\0') {
          *(undefined1 *)(param_1 + 0x70) = 0;
          FUN_004cda50(param_1);
        }
      }
    }
    if (*(char *)(param_1 + 0x6f) != '\0') {
      if (*(char *)(param_1 + 0x70) == '\0') {
        FUN_004ce5f0(param_1);
        return;
      }
      cVar1 = FUN_004f6c80("FadeOut");
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0x70) = 0;
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      }
    }
  }
  else if ((param_2 == 0xe1a57d51) && ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1)) {
    *(undefined1 *)(param_1 + 0x6d) = 1;
    return;
  }
  return;
}


// ==== 0x4cda50 FUN_004cda50

void FUN_004cda50(void)

{
  DAT_00735790 = FUN_004ab670(&DAT_00748f70);
  FUN_00421c00(DAT_007361f0,6,3);
  return;
}


// ==== 0x4cda80 FUN_004cda80

void FUN_004cda80(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bSPrintf_regdst(0x20,"OptionName_%1d",*(undefined4 *)(param_1 + 0x60));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  if (DAT_007361b4 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar1) {
    uVar2 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_007361b8 + 8);
    }
    uVar2 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar1);
  }
  if (((&DAT_007361b4)[uVar2] != 0) && (*(int *)((&DAT_007361b4)[uVar2] + 0x58) != 0)) {
    FEng__HashName(0xff606060);
    FUN_00415510();
    iVar1 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      uVar3 = 0;
      FEng__HashName(0);
      FUN_004f5f80(iVar1,uVar3);
    }
  }
  return;
}


// ==== 0x4cdb60 FUN_004cdb60

void FUN_004cdb60(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = FUN_0043a2e0();
  if (cVar2 != '\0') {
    uVar1 = (&DAT_006fa5b4)[*(int *)(param_1 + 100)];
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
        (iVar3 = FUN_004ffb70(), iVar3 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar1);
    }
    iVar3 = DAT_0073578c;
    FUN_004f75b0(0xff606060);
    if (iVar3 != 0) {
      FUN_004f5f80(iVar3,0);
    }
  }
  bSPrintf_regdst(0x20,"OptionName_%1d",*(undefined4 *)(param_1 + 100));
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar3);
  return;
}


// ==== 0x4cdc40 FUN_004cdc40

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
  iVar1 = int_NotEqual(&DAT_0073ad3c);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x6c) = 1;
  }
  return;
}


// ==== 0x4cdca0 FUN_004cdca0

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


// ==== 0x4cdcf0 FUN_004cdcf0

void __fastcall FUN_004cdcf0(int param_1)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
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
  uStack_24 = 0xe1a57d51;
  if (DAT_0078a320 == 2) {
    uStack_24 = 0xb6583410;
  }
  uStack_8 = 0;
  uStack_4 = 0;
  uStack_1c = 0xe1a57d51;
  uStack_20 = 0x639;
  uStack_14 = 0;
  uStack_18 = 0x541389e5;
  uStack_10 = 0x7f9ccc8f;
  uStack_c = 0xb8a7c6cd;
  FUN_004dc6e0(&uStack_24,"MU_PauseConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4cddb0 FUN_004cddb0

void __fastcall FUN_004cddb0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = 0;
  uStack_4 = 0;
  uVar2 = 0x7d11e4d1;
  if (DAT_00777b4c == 8) {
    cVar1 = Obj_GetByte19();
    if (cVar1 == '\0') {
      uVar2 = 0x7e9ccc8f;
    }
  }
  if (DAT_00777b4c == 1) {
    if ((DAT_00777ccc != 0) && (*(int *)(DAT_00777ccc + 0x58a4) == 1)) {
      cVar1 = Race__DidPlayerWin(DAT_00777ccc,0);
      if (cVar1 == '\0') {
        uVar2 = 0xa1048ab;
      }
    }
  }
  else if (DAT_00777cc8 == 4) {
    uVar2 = 0x5fca71b2;
  }
  else if (((DAT_0078a30c == 1) && (DAT_0078a31c == 0)) && (DAT_0078a368 == 0)) {
    uVar2 = 0x7e9ccc8f;
  }
  uStack_1c = 0x7e9ccc8f;
  uStack_20 = 0x639;
  uStack_14 = 0;
  uStack_18 = 0x541389e5;
  uStack_10 = 1;
  uStack_c = 0xb8a7c6cd;
  uStack_24 = uVar2;
  FUN_004dc6e0(&uStack_24,"MU_PauseConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4cdea0 FUN_004cdea0

void FUN_004cdea0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((DAT_0073578c != 0) && (FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0)) &&
      (FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0)) &&
     ((FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0 &&
      (FUN_004f5f80(DAT_0073578c,0), DAT_0073578c != 0)))) {
    FUN_004f5f80(DAT_0073578c,0);
  }
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x1aec7d09);
    }
  }
  iVar3 = DAT_0073578c;
  FEObject__SetInvisible(iVar1);
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar3 = DAT_0073578c, iVar1 == 0))
     || (iVar2 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar3 = DAT_0073578c, iVar2 == 0)) {
    if (iVar3 == 0) {
      iVar2 = 0;
      iVar1 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0a);
      iVar1 = DAT_0073578c;
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar3 == 0))
     || (iVar3 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar3 == 0)) {
    if (iVar1 == 0) {
      iVar3 = 0;
      iVar1 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x1aec7d0b);
      iVar1 = DAT_0073578c;
    }
  }
  FEObject__SetInvisible(iVar3);
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar3 == 0))
     || (iVar3 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar3 == 0)) {
    if (iVar1 == 0) {
      iVar3 = 0;
      iVar1 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x1aec7d0c);
      iVar1 = DAT_0073578c;
    }
  }
  FEObject__SetInvisible(iVar3);
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar3 == 0))
     || (iVar3 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar3 == 0)) {
    if (iVar1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x1aec7d0d);
    }
  }
  FEObject__SetInvisible(iVar3);
  switch(DAT_0078a30c) {
  case 1:
    FUN_004ce120();
    return;
  case 2:
    FUN_004ce370();
    return;
  case 3:
    FUN_004ce370();
    return;
  case 5:
    FUN_004ce370();
  }
  return;
}


// ==== 0x4ce120 FUN_004ce120

void FUN_004ce120(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  
  if ((((DAT_0073578c != 0) && (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) &&
      (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) &&
     (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) {
    FUN_004f5f80(DAT_0073578c,1);
  }
  iVar2 = DAT_0073578c;
  *(code **)(unaff_EBX + 0x4c) = FUN_004cdca0;
  if (((*(int *)(unaff_EBX + 0xc) == 0) ||
      (iVar1 = FUN_004f65d0(), iVar2 = DAT_0073578c, iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar2 = DAT_0073578c, iVar1 == 0)) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x1aec7d0c);
    }
  }
  FEObject__SetVisible(iVar1);
  *(undefined4 *)(unaff_EBX + 0x60) = 3;
  FUN_004cda80(unaff_EBX);
  *(undefined4 *)(unaff_EBX + 0x68) = 4;
  *(code **)(unaff_EBX + 0x50) = FUN_004cddb0;
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d09);
    }
  }
  FEObject__SetVisible(iVar2);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0a);
    }
  }
  FEObject__SetVisible(iVar2);
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0b);
    }
  }
  FEObject__SetVisible(iVar2);
  *(code **)(unaff_EBX + 0x44) = FUN_004cdc40;
  *(code **)(unaff_EBX + 0x48) = FUN_004cdcf0;
  *(undefined4 *)(unaff_EBX + 0x58) = 1;
  *(undefined4 *)(unaff_EBX + 100) = 2;
  bSPrintf_regdst(0x20,"OptionName_%1d",1);
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar2);
  FUN_004cdb60(unaff_EBX);
  bSPrintf_regdst(0x20,"OptionName_%1d",*(undefined4 *)(unaff_EBX + 0x68));
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar2);
  return;
}


// ==== 0x4ce370 FUN_004ce370

void FUN_004ce370(void)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int unaff_EBX;
  
  if ((((DAT_0073578c != 0) && (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) &&
      (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) &&
     (FUN_004f5f80(DAT_0073578c,1), DAT_0073578c != 0)) {
    FUN_004f5f80(DAT_0073578c,1);
  }
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x1aec7d09);
    }
  }
  FEObject__SetVisible(iVar1);
  iVar1 = extraout_EDX;
  if (((*(int *)(unaff_EBX + 0xc) == 0) ||
      (iVar2 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar2 == 0)) {
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0a);
    }
  }
  FEObject__SetVisible(iVar2);
  iVar1 = extraout_EDX_00;
  if (((*(int *)(unaff_EBX + 0xc) == 0) ||
      (iVar2 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar2 == 0)) {
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0b);
    }
  }
  FEObject__SetVisible(iVar2);
  iVar1 = extraout_EDX_01;
  if (((*(int *)(unaff_EBX + 0xc) == 0) ||
      (iVar2 = FUN_004f65d0(), iVar1 = DAT_0073578c, iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar1 = DAT_0073578c, iVar2 == 0)) {
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x1aec7d0c);
    }
  }
  FEObject__SetVisible(iVar2);
  *(code **)(unaff_EBX + 0x44) = FUN_004cdc40;
  *(code **)(unaff_EBX + 0x48) = FUN_004cdcf0;
  *(code **)(unaff_EBX + 0x4c) = FUN_004cdca0;
  *(code **)(unaff_EBX + 0x50) = FUN_004cddb0;
  *(undefined4 *)(unaff_EBX + 0x58) = 1;
  *(undefined4 *)(unaff_EBX + 100) = 2;
  *(undefined4 *)(unaff_EBX + 0x60) = 3;
  *(undefined4 *)(unaff_EBX + 0x68) = 4;
  bSPrintf_regdst(0x20,"OptionName_%1d",1);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  FUN_004cda80(unaff_EBX);
  FUN_004cdb60(unaff_EBX);
  bSPrintf_regdst(0x20,"OptionName_%1d",*(undefined4 *)(unaff_EBX + 0x68));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4ce5f0 FUN_004ce5f0

void FUN_004ce5f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004ce683;
    iVar1 = FUN_004ef050(0x798c7eff);
  }
  if ((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x4c), iVar3 != 0)) {
    while (iVar2 = FEng__HashName(), *(int *)(iVar3 + 0x30) != iVar2) {
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        *(undefined1 *)(param_1 + 0x70) = 1;
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
LAB_004ce683:
  *(undefined1 *)(param_1 + 0x70) = 1;
  return;
}


// ==== 0x4ce690 FUN_004ce690

void FUN_004ce690(int param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  uVar2 = FEng__HashName();
  if (((in_EAX == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar3 = FUN_004ef050(uVar2);
    if (iVar3 == 0) {
      return;
    }
  }
  pcVar4 = *(char **)(iVar3 + 0x24);
  iVar5 = 0x100;
  param_1 = param_1 - (int)pcVar4;
  do {
    cVar1 = pcVar4[param_1];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  return;
}


// ==== 0x4ce700 Screen_MU_Options_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_Options_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688a23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x4ec);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_Options_PC__Screen_MU_Options_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ce760 Screen_MU_Options_PC::Screen_MU_Options_PC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_Options_PC__Screen_MU_Options_PC(undefined4 *param_1,char **param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  char **ppcStack_88;
  char *local_74;
  char *pcStack_70;
  char *pcStack_6c;
  char *pcStack_68;
  char *pcStack_64;
  char *pcStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  void *local_44;
  undefined1 local_40 [4];
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  undefined *local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006889f9;
  local_c = ExceptionList;
  ppcStack_88 = param_2;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1);
  *param_1 = &PTR_FUN_006c3e3c;
  param_1[0x1b] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x1c] = &DAT_006b9172;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x28] = &DAT_006b9172;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x34] = &DAT_006b9172;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x40] = &DAT_006b9172;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x4c] = &DAT_006b9172;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x58] = &DAT_006b9172;
  puVar6 = param_1 + 99;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[0x57] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[100] = puVar6;
  param_1[0x65] = 0;
  puVar6 = param_1 + 0x72;
  param_1[0x67] = &DAT_006b9172;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x66] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0x73] = puVar6;
  param_1[0x74] = 0;
  puVar6 = param_1 + 0x81;
  param_1[0x76] = &DAT_006b9172;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x75] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0x82] = puVar6;
  param_1[0x83] = 0;
  puVar6 = param_1 + 0x90;
  param_1[0x85] = &DAT_006b9172;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x84] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0x91] = puVar6;
  param_1[0x92] = 0;
  param_1[0x94] = &DAT_006b9172;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x93] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  puVar6 = param_1 + 0x9f;
  *puVar6 = puVar6;
  param_1[0xa0] = puVar6;
  param_1[0xa1] = 0;
  puVar6 = param_1 + 0xae;
  param_1[0xa3] = &DAT_006b9172;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xab] = 0;
  param_1[0xac] = 0;
  param_1[0xad] = 0;
  param_1[0xa2] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0xaf] = puVar6;
  param_1[0xb0] = 0;
  puVar6 = param_1 + 0xbd;
  param_1[0xb2] = &DAT_006b9172;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb6] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xb1] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0xbe] = puVar6;
  param_1[0xbf] = 0;
  puVar6 = param_1 + 0xcc;
  param_1[0xc1] = &DAT_006b9172;
  param_1[0xc2] = 0;
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0xc5] = 0;
  param_1[0xc6] = 0;
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[0xcb] = 0;
  param_1[0xc0] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0xcd] = puVar6;
  param_1[0xce] = 0;
  param_1[0xd0] = &DAT_006b9172;
  puVar6 = param_1 + 0xdb;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd5] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xcf] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar6 = puVar6;
  param_1[0xdc] = puVar6;
  param_1[0xdd] = 0;
  ppcStack_88 = (char **)&DAT_00746104;
  local_4 = 0xe;
  *(undefined1 *)(param_1 + 0x139) = 0;
  *(undefined1 *)((int)param_1 + 0x4e5) = 0;
  *(undefined1 *)((int)param_1 + 0x4e6) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x69) = 0;
  iVar4 = FEPackageList__FindByName();
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x18) == 0)) {
    ppcStack_88 = (char **)0x4cec48;
    FEngPushGarageMainPackage();
  }
  local_30 = (char *)param_1[3];
  local_18 = (float)DAT_00758952;
  ppcStack_88 = &local_30;
  local_2c = "SliderBase_2";
  local_28 = "Slider_2";
  local_24 = &DAT_006c41b4;
  local_14 = 0x42800000;
  local_10 = 0x41200000;
  local_1c = 255.0;
  local_20 = 0.0;
  (**(code **)(param_1[0x27] + 8))();
  local_1c = (float)DAT_00758951;
  local_30 = "SliderBase_1";
  local_2c = "Slider_1";
  (**(code **)(param_1[0x1b] + 8))(&local_34);
  local_24 = (undefined *)(float)DAT_006fa5b4;
  local_20 = (float)_DAT_007588f4;
  local_1c = 1.0;
  local_18 = 10.0;
  local_28 = (char *)0x0;
  local_34 = "SliderBase_3";
  local_30 = "Slider_3";
  (**(code **)(param_1[0x33] + 8))(&local_38);
  local_24 = (undefined *)(float)_DAT_007588f8;
  local_38 = "SliderBase_4";
  local_34 = "Slider_4";
  (**(code **)(param_1[0x3f] + 8))(&local_3c);
  local_28 = (char *)DAT_007588e0;
  local_3c = "SliderBase_5";
  local_38 = "Slider_5";
  local_24 = (undefined *)0x3dcccccd;
  local_20 = 10.0;
  local_2c = (char *)0x3f800000;
  local_30 = (char *)0x0;
  (**(code **)(param_1[0x4b] + 8))(local_40);
  pcStack_68 = (char *)param_1[3];
  pcStack_64 = "VolSliderBase_1";
  puStack_5c = &DAT_006b9172;
  pcStack_60 = "VolSlider_1_";
  uStack_58 = 10;
  local_48 = 0x3dcccccd;
  local_4c = DAT_007588fc;
  local_54 = 0;
  local_50 = 0x3f800000;
  (**(code **)(param_1[0x57] + 0x14))(&pcStack_68);
  pcStack_68 = "VolSliderBase_2";
  pcStack_64 = "VolSlider_2_";
  local_50 = DAT_00758900;
  (**(code **)(param_1[0x66] + 0x14))(&pcStack_6c);
  local_54 = DAT_00758904;
  pcStack_6c = "VolSliderBase_3";
  pcStack_68 = "VolSlider_3_";
  (**(code **)(param_1[0x75] + 0x14))(&pcStack_70);
  uStack_58 = DAT_00758908;
  pcStack_70 = "VolSliderBase_4";
  pcStack_6c = "VolSlider_4_";
  (**(code **)(param_1[0x84] + 0x14))(&local_74);
  puStack_5c = (undefined1 *)DAT_0075890c;
  local_74 = "VolSliderBase_5";
  pcStack_70 = "VolSlider_5_";
  (**(code **)(param_1[0x93] + 0x14))(&stack0xffffff88);
  pcStack_60 = (char *)DAT_00758910;
  local_74 = "VolSlider_6_";
  (**(code **)(param_1[0xa2] + 0x14))(&stack0xffffff84);
  pcStack_64 = (char *)DAT_00758914;
  (**(code **)(param_1[0xb1] + 0x14))(&stack0xffffff80);
  pcStack_68 = DAT_00758918;
  (**(code **)(param_1[0xc0] + 0x14))(&stack0xffffff7c);
  pcStack_6c = DAT_0075891c;
  (**(code **)(param_1[0xcf] + 0x14))(&ppcStack_88);
  pcVar1 = (char *)(param_1 + 0x10b);
  *pcVar1 = 'O';
  pcVar5 = pcVar1;
  do {
    cVar2 = pcVar5[(int)("OptionNametext_" + (1 - (int)pcVar1))];
    pcVar5 = pcVar5 + 1;
    *pcVar5 = cVar2;
  } while (cVar2 != '\0');
  iVar4 = DAT_00777cc4;
  if (DAT_00777cc4 == 0) {
    iVar4 = 1;
  }
  bSPrintf_regdst(0x20,"OptionName_%d",iVar4);
  iVar4 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    FEng__HashName();
    FUN_004f5ed0(iVar4);
  }
  puVar6 = param_1 + 0x110;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
    }
    else {
      iVar3 = *(int *)(DAT_0073578c + 8);
      if (iVar3 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004fd1e0(iVar3 + 0xdc);
        if (iVar4 == 0) {
          iVar4 = FUN_004fd1e0(iVar3 + 0xec);
        }
      }
    }
  }
  param_1[0x138] = iVar4;
  iVar4 = DAT_007356a8;
  bVar7 = DAT_007356a8 != 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  if (bVar7) {
    *(undefined4 **)(iVar4 + 8) = &DAT_007588fc;
    FUN_0051cc10(iVar4);
    _DAT_006f8718 = DAT_00758914;
    _DAT_006f871c = _ftol_nocw();
  }
  FUN_004d0b70(param_1);
  iVar4 = DAT_007356a8;
  if (DAT_007356a8 != 0) {
    *(undefined4 **)(DAT_007356a8 + 8) = &DAT_007588fc;
    FUN_0051cc10(iVar4);
    _DAT_006f8718 = DAT_00758914;
    _DAT_006f871c = _ftol_nocw();
  }
  param_1[0x13a] = DAT_00758904;
  ExceptionList = local_44;
  return param_1;
}


// ==== 0x4cf0f0 FUN_004cf0f0

void * __thiscall FUN_004cf0f0(void *param_1,byte param_2)

{
  FUN_004cf110();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4cf110 FUN_004cf110

void __fastcall FUN_004cf110(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687299;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c3e3c;
  iVar2 = DAT_007356a8;
  local_4 = 0xe;
  if (((((float)param_1[0x13a] == 0.0) && (0.0 < DAT_00758904)) &&
      (EAXSound__InitEATraxMasks(DAT_007356a8,0,1), DAT_006f1dd8 != 0)) &&
     ((*(int *)(iVar2 + 0x104) != 0 &&
      (piVar1 = *(int **)(*(int *)(iVar2 + 0x104) + 0x14), piVar1 != (int *)0x0)))) {
    (**(code **)(*piVar1 + 0x98))(0,0xfffffffe);
  }
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  param_1[0x4b] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x3f] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x33] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x27] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x1b] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4cf240 FUN_004cf240

void __thiscall FUN_004cf240(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(char *)(param_1 + 0x4e4) == '\0') {
    if (*(char *)(param_1 + 0x4e5) == '\0') {
      if ((*(char *)(param_1 + 0x4e6) != '\0') && (param_2 == 0x23453330)) {
        FUN_004d0980();
        *(undefined1 *)(param_1 + 0x4e6) = 0;
        return;
      }
      if (param_2 < 0xb5971bf2) {
        if ((param_2 != 0xb5971bf1) && (param_2 != 0xc407210)) {
          if (param_2 == 0x911ab364) {
            iVar2 = FUN_004f65d0();
            if (iVar2 != 0) {
              *(undefined4 *)(iVar2 + 0x1c) = 0xff;
            }
            FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (param_2 != 0x9120409e) {
            return;
          }
        }
        DAT_00735e28 = param_4;
        uVar1 = *(uint *)(param_3 + 0x10);
        if (uVar1 < 0x787c1e5a) {
          if (uVar1 == 0x787c1e59) {
            if (*(code **)(param_1 + 100) != (code *)0x0) {
              (**(code **)(param_1 + 100))(param_2);
              return;
            }
          }
          else {
            switch(uVar1) {
            case 0x1aec7d09:
              if (*(code **)(param_1 + 0x40) != (code *)0x0) {
                (**(code **)(param_1 + 0x40))(param_2);
                return;
              }
              break;
            case 0x1aec7d0a:
              if (*(code **)(param_1 + 0x44) != (code *)0x0) {
                (**(code **)(param_1 + 0x44))(param_2);
                return;
              }
              break;
            case 0x1aec7d0b:
              if (*(code **)(param_1 + 0x48) != (code *)0x0) {
                (**(code **)(param_1 + 0x48))(param_2);
                return;
              }
              break;
            case 0x1aec7d0c:
              if (*(code **)(param_1 + 0x4c) != (code *)0x0) {
                (**(code **)(param_1 + 0x4c))(param_2);
                return;
              }
              break;
            case 0x1aec7d0d:
              if (*(code **)(param_1 + 0x50) != (code *)0x0) {
                (**(code **)(param_1 + 0x50))(param_2);
                return;
              }
              break;
            case 0x1aec7d0e:
              if (*(code **)(param_1 + 0x54) != (code *)0x0) {
                (**(code **)(param_1 + 0x54))(param_2);
                return;
              }
              break;
            case 0x1aec7d0f:
              if (*(code **)(param_1 + 0x58) != (code *)0x0) {
                (**(code **)(param_1 + 0x58))(param_2);
                return;
              }
              break;
            case 0x1aec7d10:
              if (*(code **)(param_1 + 0x5c) != (code *)0x0) {
                (**(code **)(param_1 + 0x5c))(param_2);
                return;
              }
              break;
            case 0x1aec7d11:
              if (*(code **)(param_1 + 0x60) != (code *)0x0) {
                (**(code **)(param_1 + 0x60))(param_2);
                return;
              }
            }
          }
        }
      }
      else if (param_2 == 0xc519bfc3) {
        switch(DAT_00735e20) {
        default:
          uVar3 = 0x995ebae4;
          break;
        case 1:
          uVar3 = 0x7f81eb3b;
          break;
        case 3:
          uVar3 = 0x2770d6;
          break;
        case 4:
          uVar3 = 0x77331a08;
          break;
        case 8:
          uVar3 = 0x6580b9b5;
          break;
        case 10:
          uVar3 = 0x7a340c18;
        }
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        GenericDialogData__GenericDialogData();
        uStack_14 = 1;
        uStack_38 = 0x169268;
        uStack_c = 0;
        uStack_8 = 0;
        uStack_10 = 0x639;
        uStack_34 = uVar3;
        FUN_004dcfd0(&uStack_38,*(undefined4 *)(param_1 + 0xc));
      }
      else if (param_2 == 0xc98356ba) {
        FUN_004d1da0(param_1);
        return;
      }
    }
    else if (param_2 == 0x23452220) {
      FUN_004d0980();
      *(undefined1 *)(param_1 + 0x4e5) = 0;
      return;
    }
  }
  else if (param_2 == 0x23451110) {
    FUN_004d0980();
    *(undefined1 *)(param_1 + 0x4e4) = 0;
    return;
  }
  return;
}


// ==== 0x4cf550 FUN_004cf550

int FUN_004cf550(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 1) && (in_stack_00000014 != 1)) && (in_stack_00000014 != 2)) {
    return in_stack_00000014;
  }
  return 0;
}


// ==== 0x4cf570 FUN_004cf570

void __fastcall FUN_004cf570(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x378));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x15c) + 0x10))();
  return;
}


// ==== 0x4cf5e0 FUN_004cf5e0

void __fastcall FUN_004cf5e0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x37c));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x198) + 0x10))();
  return;
}


// ==== 0x4cf650 FUN_004cf650

void __fastcall FUN_004cf650(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x380));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x1d4) + 0x10))();
  return;
}


// ==== 0x4cf6c0 FUN_004cf6c0

void __fastcall FUN_004cf6c0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 900));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x210) + 0x10))();
  return;
}


// ==== 0x4cf730 FUN_004cf730

void __fastcall FUN_004cf730(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x388));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x24c) + 0x10))();
  return;
}


// ==== 0x4cf7a0 FUN_004cf7a0

void __fastcall FUN_004cf7a0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x38c));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x288) + 0x10))();
  return;
}


// ==== 0x4cf810 FUN_004cf810

void __thiscall FUN_004cf810(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x178);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_007588fc = *(undefined4 *)(param_1 + 0x178);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf570();
    if (fVar1 != *(float *)(param_1 + 0x178)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cf8e0 FUN_004cf8e0

void __thiscall FUN_004cf8e0(int param_1,int param_2)

{
  float fVar1;
  
  if (((param_2 != 0xc407210) && (param_2 != 0x406415e3)) && (*(char *)(param_1 + 0x69) == '\0')) {
    fVar1 = *(float *)(param_1 + 0x1b4);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_00758900 = *(undefined4 *)(param_1 + 0x1b4);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf5e0();
    if (fVar1 != *(float *)(param_1 + 0x1b4)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cf9c0 FUN_004cf9c0

void __thiscall FUN_004cf9c0(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x1f0);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_00758904 = *(undefined4 *)(param_1 + 0x1f0);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf650();
    if (fVar1 != *(float *)(param_1 + 0x1f0)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cfa90 FUN_004cfa90

void __thiscall FUN_004cfa90(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x22c);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_00758908 = *(undefined4 *)(param_1 + 0x22c);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf6c0();
    if (fVar1 != *(float *)(param_1 + 0x22c)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cfb60 FUN_004cfb60

void __thiscall FUN_004cfb60(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x268);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_0075890c = *(undefined4 *)(param_1 + 0x268);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf730();
    if (fVar1 != *(float *)(param_1 + 0x268)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cfc30 FUN_004cfc30

void __thiscall FUN_004cfc30(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x2a4);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_00758910 = *(undefined4 *)(param_1 + 0x2a4);
    if (DAT_007356a8 != 0) {
      FUN_0051ccf0();
    }
    FUN_004cf7a0();
    if (fVar1 != *(float *)(param_1 + 0x2a4)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cfd00 FUN_004cfd00

void FUN_004cfd00(void)

{
  int iVar1;
  int unaff_EBX;
  
  bSPrintf_regdst(0x20,"%s%1d",unaff_EBX + 0x42c);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d");
  iVar1 = *(int *)(&DAT_00758938 + DAT_00758948 * 4);
  if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_004f67f0(iVar1);
  }
  return;
}


// ==== 0x4cfdb0 FUN_004cfdb0

void __fastcall FUN_004cfdb0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3ac));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  (**(code **)(*(int *)(param_1 + 0x6c) + 0x10))();
  return;
}


// ==== 0x4cfe10 FUN_004cfe10

void __thiscall FUN_004cfe10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00758948;
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    if (param_2 == -0x6edfbf62) {
      iVar2 = DAT_00758948 + -1;
      if (DAT_00758948 + -1 < 0) {
        iVar2 = 2;
      }
    }
    else {
      iVar2 = DAT_00758948;
      if ((param_2 == -0x4a68e40f) && (iVar2 = DAT_00758948 + 1, 2 < iVar2)) {
        iVar2 = 0;
      }
    }
    DAT_00758948 = iVar2;
    FUN_004cfd00(iVar2);
    if (iVar1 != iVar2) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cfec0 FUN_004cfec0

void __thiscall FUN_004cfec0(int param_1,int param_2)

{
  float fVar1;
  
  if ((param_2 != 0xc407210) && (param_2 != 0x406415e3)) {
    fVar1 = *(float *)(param_1 + 0x88);
    if (param_2 == -0x6edfbf62) {
      Slider__StepDown();
    }
    else if (param_2 == -0x4a68e40f) {
      Slider__StepUp();
    }
    DAT_00758951 = _ftol_nocw();
    FUN_004cfdb0();
    if (fVar1 != *(float *)(param_1 + 0x88)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4cff80 FUN_004cff80

void __fastcall FUN_004cff80(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3b8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x3b8));
  if ((DAT_00758954 == 1) || (DAT_00758954 == 0)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_004f67f0(iVar1);
  }
  return;
}


// ==== 0x4d0030 FUN_004d0030

void __fastcall FUN_004d0030(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3c0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x3c0));
  if ((DAT_00758964 == 0) || (DAT_00758964 == 1)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_004f67f0(iVar1);
  }
  return;
}


// ==== 0x4d00e0 FUN_004d00e0

void __thiscall FUN_004d00e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00758954;
  if (((param_2 != 0xc407210) && (param_2 != 0x406415e3)) &&
     ((param_2 == -0x6edfbf62 || (param_2 == -0x4a68e40f)))) {
    if (DAT_00758954 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = DAT_00758954;
      if (DAT_00758954 == 1) {
        iVar2 = 0;
      }
    }
    DAT_00758954 = iVar2;
    FUN_004cff80();
    if (iVar1 != iVar2) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4d0180 FUN_004d0180

void __thiscall FUN_004d0180(int param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = DAT_00758964;
  if (((param_2 != 0xc407210) && (param_2 != 0x406415e3)) &&
     ((param_2 == -0x6edfbf62 || (param_2 == -0x4a68e40f)))) {
    bVar2 = DAT_00758964 == 0;
    DAT_00758964 = (uint)bVar2;
    FUN_004d0030();
    if (bVar2 != uVar1) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4d0210 FUN_004d0210

void FUN_004d0210(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c);
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d");
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d02c0 FUN_004d02c0

void __thiscall FUN_004d02c0(int param_1,int param_2)

{
  if ((((param_2 != 0xc407210) && (param_2 != 0x406415e3)) && (*(char *)(param_1 + 0x68) != '\0'))
     && ((param_2 == -0x6edfbf62 || (param_2 == -0x4a68e40f)))) {
    DAT_00758970 = DAT_00758970 == '\0';
    FUN_004d0210(param_1);
    if (param_2 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4d0350 FUN_004d0350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d0350(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (param_2 == 0xc407210) {
    if ((DAT_00735e28 & 1) == 0) {
      if ((DAT_00735e28 & 2) == 0) {
        if ((DAT_00735e28 & 4) == 0) {
          _DAT_00735e2c = (-(uint)((DAT_00735e28 & 8) != 0) & 4) - 1;
        }
        else {
          _DAT_00735e2c = 2;
        }
      }
      else {
        _DAT_00735e2c = 1;
      }
    }
    else {
      _DAT_00735e2c = 0;
    }
    DAT_00777cc4 = *(undefined4 *)(param_1 + 0x3d0);
    DAT_0072cd08 = 0;
    DAT_00736344 = 0;
    if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
       (*(int *)(iVar2 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return;
}


// ==== 0x4d0400 FUN_004d0400

void __fastcall FUN_004d0400(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3e4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x3e4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d04b0 FUN_004d04b0

void __fastcall FUN_004d04b0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3ec));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x3ec));
  if (((DAT_007588ec == 1) || (DAT_007588ec == 3)) || (DAT_007588ec == 6)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FUN_004f67f0(iVar1);
  }
  return;
}


// ==== 0x4d0570 FUN_004d0570

void __fastcall FUN_004d0570(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x404));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x404));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d0620 FUN_004d0620

void __fastcall FUN_004d0620(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3f0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d0680 FUN_004d0680

void __fastcall FUN_004d0680(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x3f4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d06e0 FUN_004d06e0

void __thiscall FUN_004d06e0(int param_1,int param_2)

{
  if (((param_2 != 0xc407210) && (param_2 != 0x406415e3)) &&
     ((param_2 == -0x6edfbf62 || (param_2 == -0x4a68e40f)))) {
    DAT_007588f0 = (uint)(DAT_007588f0 == 0);
    FUN_004d0400();
    if (param_2 == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4d0760 FUN_004d0760

void __thiscall FUN_004d0760(int param_1,int param_2)

{
  if (param_2 == 0xc407210) {
    return;
  }
  if (param_2 == 0x406415e3) {
    return;
  }
  if (param_2 == -0x6edfbf62) {
    if (DAT_007588ec == 1) {
      DAT_007588ec = 3;
      goto LAB_004d07d3;
    }
    if (DAT_007588ec == 3) {
      DAT_007588ec = 6;
      goto LAB_004d07d3;
    }
  }
  else {
    if (param_2 != -0x4a68e40f) goto LAB_004d07d3;
    if (DAT_007588ec == 1) {
      DAT_007588ec = 6;
      goto LAB_004d07d3;
    }
    if (DAT_007588ec != 3) {
      DAT_007588ec = (uint)(DAT_007588ec == 6) * 2 + 1;
      goto LAB_004d07d3;
    }
  }
  DAT_007588ec = 1;
LAB_004d07d3:
  FUN_004d04b0();
  if (param_2 != -0x6edfbf62) {
    FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4d0820 FUN_004d0820

void FUN_004d0820(int param_1)

{
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    DAT_007588d5 = DAT_007588d5 == '\0';
    FUN_004d0570();
  }
  return;
}


// ==== 0x4d0850 FUN_004d0850

void __thiscall FUN_004d0850(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (param_2 == 0xc407210) {
    DAT_00777cc4 = *(undefined4 *)(param_1 + 0x3f0);
    DAT_0072cd08 = 0;
    if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
       (*(int *)(iVar2 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  return;
}


// ==== 0x4d08b0 FUN_004d08b0

void __thiscall FUN_004d08b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_2 == 0xc407210) &&
       (DAT_00777cc4 = *(undefined4 *)(param_1 + 0x3f4), DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d0900 FUN_004d0900

void __fastcall FUN_004d0900(int param_1)

{
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x40c));
  FUN_00416bb0(0xa8f5ef7a);
  return;
}


// ==== 0x4d0940 FUN_004d0940

void __fastcall FUN_004d0940(int param_1)

{
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x410));
  FUN_00416bb0(0xc73ca184);
  return;
}


// ==== 0x4d0980 FUN_004d0980

void FUN_004d0980(void)

{
  int iVar1;
  int unaff_EDI;
  
  bSPrintf_regdst(0x20,"%s%1d",unaff_EDI + 0x42c,*(undefined4 *)(unaff_EDI + 0x414));
  FUN_00416bb0(0x6c1a2ad3);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(unaff_EDI + 0x414));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d0a10 FUN_004d0a10

void FUN_004d0a10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_1 == 0xc407210) && (DAT_00777b50 = 1, DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d0a60 FUN_004d0a60

void FUN_004d0a60(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_1 == 0xc407210) && (DAT_00777b50 = 0, DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d0ab0 FUN_004d0ab0

void __fastcall FUN_004d0ab0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x42c,*(undefined4 *)(param_1 + 0x420));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FUN_004f67f0(iVar1);
  return;
}


// ==== 0x4d0b20 FUN_004d0b20

void FUN_004d0b20(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((param_1 == 0xc407210) && (DAT_00735e24 = 0, DAT_0073578c != 0)) &&
      (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4d0b70 FUN_004d0b70

void FUN_004d0b70(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  local_24 = 1;
  do {
    bSPrintf_regdst(0x20,"OptionData_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d0c33:
      if (iVar5 == 0) {
LAB_004d0c44:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d0c33;
          goto LAB_004d0c1c;
        }
        goto LAB_004d0c44;
      }
LAB_004d0c1c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d0c33;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"OptionName_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d0d0b:
      iVar3 = 0;
      if (iVar5 == 0) {
LAB_004d0d22:
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar8);
        iVar3 = DAT_0073578c;
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        iVar3 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d0d0b;
          goto LAB_004d0cec;
        }
        goto LAB_004d0d22;
      }
LAB_004d0cec:
      if ((iVar3 == 0) ||
         (iVar4 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar5 = DAT_0073578c, iVar4 == 0))
      goto LAB_004d0d0b;
    }
    FEObject__SetInvisible(iVar4);
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
    if (((iVar3 != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar3 = *(int *)(iVar5 + 0x88);
      iVar4 = 0;
      if (iVar3 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar8) {
            iVar4 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        if (iVar4 != 0) {
          *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x4000000;
        }
      }
    }
    bSPrintf_regdst(0x20,"SelectButton_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d0e57:
      if (iVar5 == 0) {
LAB_004d0e68:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d0e57;
          goto LAB_004d0e40;
        }
        goto LAB_004d0e68;
      }
LAB_004d0e40:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d0e57;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"LeftArrow_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d0f23:
      if (iVar5 == 0) {
LAB_004d0f34:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d0f23;
          goto LAB_004d0f0c;
        }
        goto LAB_004d0f34;
      }
LAB_004d0f0c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d0f23;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"RightArrow_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d0ff3:
      if (iVar5 == 0) {
LAB_004d1004:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d0ff3;
          goto LAB_004d0fdc;
        }
        goto LAB_004d1004;
      }
LAB_004d0fdc:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d0ff3;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"OptionNametext_%d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d10c3:
      if (iVar5 == 0) {
LAB_004d10d4:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d10c3;
          goto LAB_004d10ac;
        }
        goto LAB_004d10d4;
      }
LAB_004d10ac:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d10c3;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"option_buttonR_%02d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d1193:
      if (iVar5 == 0) {
LAB_004d11a4:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d1193;
          goto LAB_004d117c;
        }
        goto LAB_004d11a4;
      }
LAB_004d117c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d1193;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"option_buttonL_%02d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d1263:
      if (iVar5 == 0) {
LAB_004d1274:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d1263;
          goto LAB_004d124c;
        }
        goto LAB_004d1274;
      }
LAB_004d124c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d1263;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"minus_%02d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d1333:
      if (iVar5 == 0) {
LAB_004d1344:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d1333;
          goto LAB_004d131c;
        }
        goto LAB_004d1344;
      }
LAB_004d131c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d1333;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"plus_%02d",local_24);
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
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004d1406:
      if (iVar5 == 0) {
LAB_004d1417:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004d1406;
          goto LAB_004d13ef;
        }
        goto LAB_004d1417;
      }
LAB_004d13ef:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004d1406;
    }
    FEObject__SetInvisible(iVar3);
    local_24 = local_24 + 1;
    if (10 < local_24) {
      (**(code **)(*(int *)(param_1 + 0x6c) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x9c) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x15c) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x198) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x1d4) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x210) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x24c) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x288) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x2c4) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x300) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x33c) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0xcc) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0xfc) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 300) + 0xc))(0);
      switch(DAT_00735e20) {
      case 0:
        FUN_004d1f30(param_1);
        FUN_004d1790();
        return;
      case 1:
        FUN_004d2700(param_1);
        FUN_004d1790();
        return;
      case 2:
        FUN_004d2820(param_1);
        FUN_004d1790();
        return;
      case 3:
        FUN_004d2f60(param_1);
        FUN_004d1790();
        return;
      case 4:
        FUN_004d32e0(param_1);
        FUN_004d1790();
        return;
      case 8:
        FUN_004d3b60(param_1);
        FUN_004d1790();
        return;
      case 10:
        FUN_004d3f30(param_1);
      }
      FUN_004d1790();
      return;
    }
  } while( true );
}


