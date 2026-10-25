// 00573ab0 FUN_00573ab0

int FUN_00573ab0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined4 *puVar4;
  short sVar5;
  int in_EAX;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  puVar4 = param_1;
  piVar1 = param_1 + 0x5f;
  iVar9 = 0;
  param_1 = (undefined4 *)0x0;
  if (in_EAX == *piVar1) {
LAB_00573b61:
    if ((DAT_007345d0 == (int *)0x0) || (bVar3 = true, *DAT_007345d0 == 0)) {
      bVar3 = false;
    }
    puVar8 = (undefined4 *)*puVar4;
    puVar6 = (undefined4 *)FUN_0040a880();
    for (; puVar8 != puVar6; puVar8 = (undefined4 *)*puVar8) {
      iVar9 = puVar8[3];
      if ((((iVar9 != 0) && (*(code **)(iVar9 + 0xc) != (code *)0x0)) &&
          ((!bVar3 || (*(char *)(iVar9 + 0x16) != '\0')))) &&
         (sVar5 = (**(code **)(iVar9 + 0xc))(puVar8,param_2,param_3,iVar9,puVar4), sVar5 != 0)) {
        iVar9 = *param_4;
        uVar7 = puVar4[0x5e];
        if (iVar9 < 0x100) {
          piVar1 = param_4 + iVar9 * 3 + 1;
          *param_4 = iVar9 + 1;
          *(short *)piVar1 = sVar5;
          *(char *)((int)piVar1 + 2) = (char)uVar7;
          *(undefined1 *)((int)piVar1 + 3) = *(undefined1 *)(puVar8 + 2);
          piVar1[1] = puVar8[4];
          piVar1[2] = puVar8[5];
        }
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
    }
    return (int)param_1;
  }
  if (in_EAX == puVar4[0x60]) {
    iVar2 = puVar4[0x61];
    puVar4[0x61] = iVar2 + 1;
    if (0x1f < iVar2 + 1) {
      puVar4[0x5f] = in_EAX;
      puVar8 = puVar4 + 2;
      do {
        FUN_00574a70(puVar8);
        iVar9 = iVar9 + 1;
        puVar8 = puVar8 + 0xb;
      } while (iVar9 < 4);
      puVar8 = (undefined4 *)*puVar4;
      puVar6 = (undefined4 *)FUN_0040a880();
      for (; puVar8 != puVar6; puVar8 = (undefined4 *)*puVar8) {
        uVar7 = FUN_00574a00(puVar8[2]);
        puVar8[3] = uVar7;
        puVar8[7] = 1;
        puVar8[6] = 0;
      }
      goto LAB_00573b61;
    }
  }
  else {
    puVar4[0x61] = 0;
    puVar4[0x60] = in_EAX;
  }
  return 0;
}


// 00574350 FUN_00574350 (created here)

uint FUN_00574350(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  bVar1 = *(byte *)(param_1 + 0x12);
  uVar6 = 1;
  uVar4 = 1;
  if (bVar1 != 0) {
    uVar6 = (*(uint *)(param_2 + (uint)(bVar1 >> 5) * 4) >> (bVar1 & 0x1f) ^
            (uint)*(byte *)(param_1 + 0x10)) & 1;
  }
  bVar2 = *(byte *)(param_1 + 0x13);
  if (bVar2 != 0) {
    bVar3 = *(byte *)(param_1 + 0x11);
    iVar5 = (uint)(bVar2 >> 5) * 4;
    uVar4 = (*(uint *)(iVar5 + param_2) >> (bVar2 & 0x1f) ^ (uint)bVar3) & 1;
    if (bVar3 != 0) {
      uVar6 = uVar6 & ((*(uint *)(param_3 + (uint)(bVar1 >> 5) * 4) >> (bVar1 & 0x1f) ^
                       (uint)*(byte *)(param_1 + 0x10)) & 1 ^ uVar6);
      uVar4 = uVar4 & ((*(uint *)(iVar5 + param_3) >> (bVar2 & 0x1f) ^ (uint)bVar3) & 1) == uVar4;
    }
  }
  return uVar4 & uVar6;
}


// 00574410 FUN_00574410 (created here)

int FUN_00574410(int param_1)

{
  uint uVar1;
  int in_stack_00000014;
  
  uVar1 = (uint)*(byte *)(in_stack_00000014 + 0x17c);
  if ((uVar1 == *(uint *)(param_1 + 0x18)) && (*(int *)(param_1 + 0x1c) == 0)) {
    return 0;
  }
  *(uint *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return uVar1 * 0x100 + *(int *)(param_1 + 8);
}


// 00574450 FUN_00574450 (created here)

uint FUN_00574450(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = FUN_00574350(param_4,param_2,param_3);
  if ((uVar1 != 0) && (*(byte *)(param_4 + 0x14) != 0)) {
    uVar1 = (uint)*(byte *)(param_4 + 0x14);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(uint *)(param_1 + 0x18) = uVar1;
  }
  if ((uVar1 != *(uint *)(param_1 + 0x18)) && (*(uint *)(param_1 + 0x18) = uVar1, uVar1 != 0)) {
    return uVar1 * 0x100 + *(int *)(param_1 + 8);
  }
  return uVar1 & 0xffff0000;
}


// 005744b0 FUN_005744b0 (created here)

uint FUN_005744b0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = FUN_00574350(param_4,param_2,param_3);
  if ((uVar1 != 0) && (*(byte *)(param_4 + 0x14) != 0)) {
    uVar1 = (uint)*(byte *)(param_4 + 0x14);
  }
  if ((uVar1 == *(uint *)(param_1 + 0x18)) && (*(int *)(param_1 + 0x1c) == 0)) {
    return uVar1 & 0xffff0000;
  }
  *(uint *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return uVar1 * 0x100 + *(int *)(param_1 + 8);
}


// 00574500 FUN_00574500 (created here)

int FUN_00574500(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x80;
  uVar1 = (*(uint *)(param_2 + (uint)(*(byte *)(param_4 + 0x13) >> 5) * 4) >>
           (*(byte *)(param_4 + 0x13) & 0x1f) ^ (uint)*(byte *)(param_4 + 0x11)) & 1;
  if (((*(uint *)(param_2 + (uint)(*(byte *)(param_4 + 0x12) >> 5) * 4) >>
        (*(byte *)(param_4 + 0x12) & 0x1f) ^ (uint)*(byte *)(param_4 + 0x10)) & 1) == 0) {
    if (uVar1 != 0) {
      iVar2 = 0xff;
    }
  }
  else if (uVar1 == 0) {
    iVar2 = 0;
  }
  if ((*(int *)(param_1 + 0x18) == iVar2) && (*(int *)(param_1 + 0x1c) == 0)) {
    return 0;
  }
  *(int *)(param_1 + 0x18) = iVar2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return iVar2 * 0x100 + *(int *)(param_1 + 8);
}


// 00574590 FUN_00574590 (created here)

uint FUN_00574590(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 0x80;
  bVar1 = *(byte *)(param_4 + 0x13);
  uVar8 = (*(uint *)(param_2 + (uint)(*(byte *)(param_4 + 0x12) >> 5) * 4) >>
           (*(byte *)(param_4 + 0x12) & 0x1f) ^ (uint)*(byte *)(param_4 + 0x10)) & 0xff;
  if (bVar1 != 0) {
    uVar6 = (*(uint *)(param_2 + (uint)(bVar1 >> 5) * 4) >> (bVar1 & 0x1f) ^
            (uint)*(byte *)(param_4 + 0x11)) & 0xff;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(uint *)(param_1 + 0x18) = uVar6 << 8 | uVar8;
    return param_4 & 0xffff0000;
  }
  cVar2 = *(char *)(param_4 + 0x14);
  if (cVar2 == '\0') {
    uVar6 = (uint)DAT_0070387a;
    param_2 = *(uint *)(param_1 + 0x18) & 0xff;
    *(uint *)(param_1 + 0x18) = uVar8;
    if ((param_2 < uVar6) && (uVar6 < uVar8)) {
LAB_00574623:
      *(uint *)(param_1 + 0x20) = DAT_00734560 + 0x19;
      return *(int *)(param_1 + 8) + 0x100;
    }
    if ((uVar6 < param_2) && (uVar8 < uVar6)) {
LAB_00574644:
      return (uint)*(ushort *)(param_1 + 8);
    }
    if (((uVar6 < param_2) && (uVar6 < uVar8)) &&
       (param_2 = DAT_00734560, *(int *)(param_1 + 0x20) < (int)DAT_00734560)) {
      *(uint *)(param_1 + 0x20) = DAT_00734560 + 6;
      return *(int *)(param_1 + 8) + 0x100;
    }
  }
  else if ((cVar2 == '\x01') || (param_2 = param_4, cVar2 == '\x02')) {
    uVar3 = *(uint *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar6 << 8 | uVar8;
    param_2 = 0;
    do {
      uVar4 = uVar6;
      uVar7 = (uint)*(byte *)(param_1 + 0x19);
      if (param_2 == 0) {
        uVar4 = uVar8;
        uVar7 = uVar3 & 0xff;
      }
      if (*(char *)(param_4 + 0x14) == '\x01') {
        uVar5 = (uint)DAT_00703878;
        if (uVar5 <= uVar7) {
          if (uVar4 < uVar5) goto LAB_00574623;
          if (uVar5 < uVar7) goto LAB_00574755;
        }
        if (uVar5 < uVar4) goto LAB_00574644;
        if (((uVar7 <= uVar5) && (uVar4 < uVar5)) && (*(int *)(param_1 + 0x20) < (int)DAT_00734560))
        {
          *(uint *)(param_1 + 0x20) = DAT_00734560 + 6;
          return *(int *)(param_1 + 8) + 0x100;
        }
      }
      else if (*(char *)(param_4 + 0x14) == '\x02') {
        uVar5 = (uint)DAT_00703879;
        if (uVar7 <= uVar5) {
          if (uVar5 < uVar4) {
            *(uint *)(param_1 + 0x20) = DAT_00734560 + 0x19;
            return *(int *)(param_1 + 8) + 0x100;
          }
          if (uVar7 < uVar5) goto LAB_00574755;
        }
        if (uVar4 < uVar5) goto LAB_00574644;
        if (((uVar5 <= uVar7) && (uVar5 < uVar4)) && (*(int *)(param_1 + 0x20) < (int)DAT_00734560))
        {
          *(uint *)(param_1 + 0x20) = DAT_00734560 + 6;
          return *(int *)(param_1 + 8) + 0x100;
        }
      }
LAB_00574755:
      param_2 = param_2 + 1;
    } while ((int)param_2 < 2);
  }
  return param_2 & 0xffff0000;
}


// 005747b0 FUN_005747b0 (created here)

uint FUN_005747b0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = (uint)*(byte *)(param_4 + 0x15) * 0x2c;
  uVar4 = (uint)*(byte *)(iVar2 + 0x30 + param_5);
  FUN_00583f20(iVar2 + param_5 + 0x28,
               (float)(byte)((byte)(*(uint *)(param_2 + (uint)(*(byte *)(param_4 + 0x12) >> 5) * 4)
                                   >> (*(byte *)(param_4 + 0x12) & 0x1f)) ^
                            *(byte *)(param_4 + 0x10)));
  uVar3 = FUN_00674898();
  uVar3 = uVar3 & 0xff;
  if (*(char *)(param_4 + 0x14) == '\x01') {
    if (uVar3 < 0x7f) {
      uVar3 = (0x7f - uVar3) * 2;
    }
    else {
      uVar3 = 0;
    }
LAB_0057483b:
    if (uVar3 == 0xfe) {
      uVar3 = 0xff;
    }
  }
  else if (*(char *)(param_4 + 0x14) == '\x02') {
    if (uVar3 < 0x81) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar3 - 0x80;
    }
    uVar3 = iVar2 * 2;
    goto LAB_0057483b;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
LAB_00574859:
    *(uint *)(param_1 + 0x18) = uVar3;
    return uVar3 * 0x100 + *(int *)(param_1 + 8);
  }
  bVar1 = *(byte *)(param_4 + 0x13);
  if ((bVar1 == 0) ||
     (((*(uint *)(param_2 + (uint)(bVar1 >> 5) * 4) >> (bVar1 & 0x1f) ^
       (uint)*(byte *)(param_4 + 0x11)) & 1) != 0)) {
    if ((uVar3 == 0) || ((uVar3 == 0x80 || (uVar3 == 0xff)))) {
      uVar4 = 0;
    }
    if ((uVar3 + uVar4 < *(uint *)(param_1 + 0x18)) || (*(uint *)(param_1 + 0x18) + uVar4 < uVar3))
    goto LAB_00574859;
  }
  return uVar3 & 0xffff0000;
}


// 00594120 FUN_00594120

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


// 00594220 FUN_00594220

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


// 0057c5a0 FUN_0057c5a0

undefined4 __thiscall FUN_0057c5a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_0073459c == 0) {
    return 0;
  }
  uVar1 = FUN_0057c480(param_1,param_2);
  if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
    DAT_007345a4 = (int *)0x0;
    DAT_0073459c = 0;
  }
  return uVar1;
}


// 0057c480 FUN_0057c480

undefined4 __thiscall FUN_0057c480(int *param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  undefined4 local_4;
  
  if ((param_1[2] - *param_1 < 0x100) && (param_1[2] != param_1[4])) {
    FUN_0057c350();
  }
  iVar2 = FUN_0057c4f0(*param_1);
  *param_1 = iVar2;
  if (local_c != param_3) {
    FUN_0057c540();
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  return local_4;
}


