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


// 00573cb0 FUN_00573cb0

void FUN_00573cb0(void)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 uVar7;
  uint3 *puVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int local_8;
  undefined4 local_4;
  
  DAT_0073b578 = 0;
  if (DAT_0073459c == 0) {
    iVar4 = DAT_0073b578;
    if ((DAT_007345d0 == (int *)0x0) || (piVar13 = DAT_007345d0, DAT_007345d0[8] == 0)) {
      while (DAT_0073b578 = iVar4, DAT_0073650c != 0) {
        DAT_0073650c = 0;
        iVar11 = 0;
        puVar9 = &DAT_0073b260;
        do {
          local_8 = 0;
          uVar5 = FUN_00405980(iVar11,&local_8);
          iVar4 = FUN_00573ab0(puVar9,uVar5,local_8,&DAT_0073b578);
          if ((iVar4 != 0) && (DAT_0078e954 < DAT_0073ad3c)) {
            DAT_0078e954 = DAT_0073ad3c;
          }
          puVar9 = puVar9 + 0x18c;
          iVar11 = iVar11 + 1;
          iVar4 = DAT_0073b578;
        } while ((int)puVar9 < 0x73b578);
      }
      DAT_0073650c = 0;
      if (DAT_007345a0 != 0) {
        FUN_0057c3b0(iVar4,8,2);
      }
      piVar13 = DAT_007345d0;
      if (0 < iVar4) {
        puVar8 = (uint3 *)&DAT_0073b57c;
        do {
          if (DAT_007345a0 != 0) {
            FUN_0057c3b0((uint)*puVar8,0x13,2);
            piVar13 = DAT_007345d0;
          }
          puVar8 = puVar8 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  else {
    iVar4 = FUN_0057c5a0(2);
    piVar13 = DAT_007345d0;
    if (0 < iVar4) {
      do {
        if (DAT_0073459c == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_0057c480(0x13,2);
          if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
            DAT_007345a4 = (int *)0x0;
            DAT_0073459c = 0;
          }
        }
        FUN_00573c30(uVar5,&DAT_0073b578,1);
        if (DAT_0078e954 < DAT_0073ad3c) {
          DAT_0078e954 = DAT_0073ad3c;
        }
        iVar4 = iVar4 + -1;
        piVar13 = DAT_007345d0;
      } while (iVar4 != 0);
    }
  }
  if (piVar13 != (int *)0x0) {
    iVar4 = piVar13[9];
    if (iVar4 < piVar13[10]) {
      bVar2 = *(byte *)(iVar4 + 0x2c + (int)piVar13);
      piVar13[9] = iVar4 + 1;
      uVar6 = (uint)bVar2;
      if (uVar6 != 0) {
        FUN_00573c30(uVar6 + 0x100,&DAT_0073b578,1);
      }
    }
    iVar4 = DAT_0073b578;
    if ((*piVar13 == 0) || (piVar13[6] != 0)) {
      piVar1 = piVar13 + 1;
      if ((piVar13[1] != 0) &&
         (piVar12 = piVar13 + 0x19, FUN_00594120(DAT_0073b578,8), piVar13 = DAT_007345d0,
         *(int *)(*piVar12 + 0x14) * 8 + -0x44 <= *(int *)(*piVar12 + 8))) {
        *piVar1 = 0;
      }
      if (0 < iVar4) {
        puVar8 = (uint3 *)&DAT_0073b57c;
        local_8 = iVar4;
        do {
          piVar1 = piVar13 + 1;
          if ((piVar13[1] != 0) &&
             (piVar12 = piVar13 + 0x19, FUN_00594120((uint)*puVar8,0x13), piVar13 = DAT_007345d0,
             *(int *)(*piVar12 + 0x14) * 8 + -0x44 <= *(int *)(*piVar12 + 8))) {
            *piVar1 = 0;
          }
          puVar8 = puVar8 + 3;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        local_8 = 0;
      }
    }
    else {
      if ((*piVar13 == 0) || (piVar13[2] != 0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00594220(8,0);
        if (*(int *)(piVar13[0x19] + 0x28) != 0) {
          piVar13[2] = 1;
        }
      }
      if (0 < iVar4) {
        do {
          if ((*piVar13 == 0) || (piVar13[2] != 0)) {
            uVar5 = 0;
          }
          else {
            uVar5 = FUN_00594220(0x13,0);
            if (*(int *)(piVar13[0x19] + 0x28) != 0) {
              piVar13[2] = 1;
            }
          }
          FUN_00573c30(uVar5,&DAT_0073b578,0);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  iVar4 = 0;
  if (0 < DAT_0073b578) {
    puVar10 = &DAT_0073b580;
    do {
      bVar2 = *(byte *)((int)puVar10 + -2);
      uVar3 = *(ushort *)(puVar10 + -1);
      if ((uVar3 & 0xff) != 0) {
        uVar7 = (undefined1)(uVar3 >> 8);
        local_4 = CONCAT31(local_4._1_3_,uVar7);
        (&DAT_0073b318)[(uVar3 & 0xff) + (uint)bVar2 * 0x18c] = uVar7;
        if ((code *)*puVar10 != (code *)0x0) {
          (*(code *)*puVar10)((uint)bVar2,uVar3 & 0xff,local_4,puVar10[1]);
        }
      }
      iVar4 = iVar4 + 1;
      puVar10 = puVar10 + 3;
    } while (iVar4 < DAT_0073b578);
  }
  return;
}


// 00573c30 FUN_00573c30

void FUN_00573c30(uint param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(&DAT_0073b260 + (param_1 >> 0x10) * 0x18c);
  piVar2 = (int *)FUN_0040a880();
  if (piVar3 != piVar2) {
    while (piVar3[2] != (param_1 & 0xff)) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == piVar2) {
        return;
      }
    }
    iVar1 = *param_2;
    if (iVar1 < 0x100) {
      piVar2 = param_2 + iVar1 * 3 + 1;
      *param_2 = iVar1 + 1;
      *(short *)piVar2 = (short)param_1;
      *(char *)((int)piVar2 + 2) = (char)(param_1 >> 0x10);
      *(char *)((int)piVar2 + 3) = (char)piVar3[2];
      piVar2[1] = piVar3[4];
      piVar2[2] = piVar3[5];
    }
  }
  return;
}


// 004070a0 FUN_004070a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004070a0(void)

{
  float fVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  char *pcVar6;
  short *psVar7;
  int unaff_ESI;
  int *piVar8;
  float10 fVar9;
  undefined8 uVar10;
  int local_148;
  float local_144 [81];
  
  if (*(int *)(unaff_ESI + 0x134) == 0x13) {
    (**(code **)(*DAT_007187c8 + 100))(DAT_007187c8);
    pfVar5 = local_144;
    iVar4 = (**(code **)(*DAT_007187c8 + 0x28))(DAT_007187c8,0x14,pfVar5,&stack0xfffffeb0,0);
    if (iVar4 < 0) {
      if ((iVar4 == -0x7ff8fff4) || (iVar4 == -0x7ff8ffe2)) {
        (**(code **)(*DAT_007187c8 + 0x1c))(DAT_007187c8);
        return;
      }
    }
    else {
      if (DAT_00736508 != '\0') {
        *(undefined4 *)(unaff_ESI + 8) = 0xffffffff;
        *(undefined4 *)(unaff_ESI + 0xc) = 0xffffffff;
        return;
      }
      if (pfVar5 != (float *)0x0) {
        piVar8 = &local_148;
        do {
          if (piVar8[-3] == 0) {
            uVar10 = __allshl();
            *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) | (uint)uVar10;
            *(uint *)(unaff_ESI + 0xc) =
                 *(uint *)(unaff_ESI + 0xc) | (uint)((ulonglong)uVar10 >> 0x20);
          }
          else {
            if ((*piVar8 == 3) || (*piVar8 == 4)) {
              DAT_00736515 = 1;
              DAT_00736514 = 0;
            }
            uVar10 = __allshl();
            *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
            *(uint *)(unaff_ESI + 0xc) =
                 *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
          }
          piVar8 = piVar8 + 5;
          pfVar5 = (float *)((int)pfVar5 + -1);
        } while (pfVar5 != (float *)0x0);
        return;
      }
    }
  }
  else if ((DAT_00736508 == '\0') && ((&DAT_0071d89c)[*(int *)(unaff_ESI + 0x130)] != 0)) {
    local_148 = *(int *)(unaff_ESI + 0x130) * 0x110;
    *(undefined4 *)(unaff_ESI + 8) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0xc) = 0xffffffff;
    pcVar6 = &DAT_0071d8d8 + local_148;
    iVar4 = 0x10;
    do {
      if (*pcVar6 < '\0') {
        uVar10 = __allshl();
        *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
        *(uint *)(unaff_ESI + 0xc) =
             *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        uVar10 = __allshl();
        *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
        *(uint *)(unaff_ESI + 0xc) =
             *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
      }
      pcVar6 = pcVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    psVar7 = (short *)(local_148 + 0x20 + DAT_00736500);
    iVar4 = 4;
    do {
      if (*psVar7 != -1) {
        FUN_00674898();
        fVar9 = (float10)FUN_00564b10();
        local_144[0] = (float)fVar9;
        FUN_00674898();
        fVar9 = (float10)FUN_00564b10();
        fVar1 = (float)fVar9;
        if (local_144[0] < _DAT_006ccc3c) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (_DAT_006cc7b8 < local_144[0]) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (fVar1 < _DAT_006ccc3c) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (_DAT_006cc7b8 < fVar1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (local_144[0] < _DAT_006ccc3c) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (_DAT_006cc7b8 < local_144[0]) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (fVar1 < _DAT_006ccc3c) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (_DAT_006cc7b8 < fVar1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
      }
      psVar7 = psVar7 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    cVar2 = -0x80;
    if (*(char *)(unaff_ESI + 0x264) != '\0') {
      cVar2 = FUN_00674898();
      cVar2 = -0x80 - cVar2 * *(char *)(unaff_ESI + 0x254);
    }
    *(char *)(unaff_ESI + 0x12) = cVar2;
    if ((*(char *)(unaff_ESI + 0x268) != '\0') && (*(char *)(unaff_ESI + 0x267) != '\0')) {
      cVar2 = FUN_00674898();
      *(char *)(unaff_ESI + 0x13) = '\x7f' - cVar2 * *(char *)(unaff_ESI + 0x260);
      *(undefined1 *)(unaff_ESI + 0x11) = 0;
      *(undefined1 *)(unaff_ESI + 0x10) = 0;
      return;
    }
    cVar2 = '\0';
    if (*(char *)(unaff_ESI + 0x266) != '\0') {
      cVar2 = FUN_00674898();
      cVar2 = '\x7f' - cVar2 * *(char *)(unaff_ESI + 0x25c);
    }
    cVar3 = '\0';
    if (*(char *)(unaff_ESI + 0x265) != '\0') {
      cVar3 = FUN_00674898();
      cVar3 = '\x7f' - cVar3 * *(char *)(unaff_ESI + 600);
    }
    *(char *)(unaff_ESI + 0x11) = cVar2;
    *(char *)(unaff_ESI + 0x10) = cVar3;
    *(undefined1 *)(unaff_ESI + 0x13) = 0x80;
  }
  return;
}


// 00405980 FUN_00405980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00405980(int *param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = DAT_00736504;
  if (DAT_00736504 == 0) {
    iVar2 = -1;
  }
  *param_1 = iVar2;
  if (param_2 != 0) {
    *param_3 = &DAT_007187b8;
    return &DAT_00719780;
  }
  _DAT_007187bc = DAT_00719784;
  _DAT_007187b8 = DAT_00719780;
  _DAT_007187c0 = DAT_00719788;
  _DAT_007187c4 = DAT_0071978c;
  DAT_00719780 = 0xffffffff;
  DAT_00719784 = 0xffffffff;
  DAT_00719788 = 0x80800000;
  if (DAT_00736378 != 0) {
    puVar3 = &DAT_0078daa8;
    do {
      if (*(int *)(puVar3 + 0x130) != -1) {
        FUN_00406580();
      }
      puVar3 = puVar3 + 0x270;
    } while ((int)puVar3 < 0x78e948);
  }
  if ((DAT_007361f0 != (int *)0x0) && (*DAT_007361f0 == 4)) {
    *param_3 = &DAT_007187b8;
    return &DAT_00719780;
  }
  iVar2 = 0;
  do {
    if ((&DAT_0071d89c)[iVar2] != 0) {
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x24e8);
      if ((cVar1 != '\0') && ((&DAT_0071d890)[iVar2] != 0)) {
        cVar1 = FUN_0041bc20(DAT_00736500 + 0x24e8);
        if (cVar1 != '\0') {
          FUN_0041bb30(iVar2);
        }
      }
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x2538);
      if ((cVar1 != '\0') && ((&DAT_0071d890)[iVar2] != 0)) {
        cVar1 = FUN_0041bc20(DAT_00736500 + 0x2538);
        if (cVar1 != '\0') {
          FUN_0041bb30(iVar2);
        }
      }
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x2498);
      if ((cVar1 != '\0') && ((&DAT_0071d890)[iVar2] != 0)) {
        cVar1 = FUN_0041bc20(DAT_00736500 + 0x2498);
        if (cVar1 != '\0') {
          FUN_0041bb30(iVar2);
        }
      }
      if (*(char *)(DAT_00736500 + 0x2220 + iVar2) == '\x01') {
        FUN_0041b830(DAT_00736500);
      }
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x2498);
      if (cVar1 != '\0') {
        FUN_0041b150(DAT_00736500);
      }
      FUN_0041a250(DAT_00736500,7000,7000);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  *param_3 = &DAT_007187b8;
  return &DAT_00719780;
}


// 00406580 FUN_00406580

void FUN_00406580(void)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (*(int *)(in_EAX + 0x23c) == 0) {
    FUN_004070a0();
  }
  else if (*(int *)(in_EAX + 0x134) == 0x13) {
    FUN_00406b10(in_EAX);
  }
  else {
    FUN_004067d0();
  }
  DAT_00719780 = DAT_00719780 & *(uint *)(in_EAX + 8);
  DAT_00719784 = DAT_00719784 & *(uint *)(in_EAX + 0xc);
  if (*(int *)(in_EAX + 0x134) != 0x13) {
    if ((byte)DAT_00719788 < *(byte *)(in_EAX + 0x10)) {
      DAT_00719788._0_1_ = *(byte *)(in_EAX + 0x10);
    }
    if (DAT_00719788._1_1_ < *(byte *)(in_EAX + 0x11)) {
      DAT_00719788._1_1_ = *(byte *)(in_EAX + 0x11);
    }
    bVar1 = *(byte *)(in_EAX + 0x12);
    iVar2 = bVar1 - 0x80;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar3 = DAT_00719788._2_1_ - 0x80;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if ((((iVar3 < iVar2) && (DAT_00719788._2_1_ = bVar1, DAT_00736515 == '\0')) &&
        ((&DAT_0071d89c)[*(int *)(in_EAX + 0x130)] != 0)) &&
       ((&DAT_0071d888)[*(int *)(in_EAX + 0x130)] != '\0')) {
      DAT_00736514 = 1;
    }
    iVar2 = *(byte *)(in_EAX + 0x13) - 0x80;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar3 = DAT_00719788._3_1_ - 0x80;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < iVar2) {
      DAT_00719788._3_1_ = *(byte *)(in_EAX + 0x13);
    }
  }
  return;
}


// 00405860 FUN_00405860

void FUN_00405860(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = &DAT_0078dab8;
  iVar3 = DAT_00736504;
  do {
    iVar1 = *(int *)(puVar4 + 0x120);
    if (iVar1 != -1) {
      cVar2 = FUN_00405570();
      if ((cVar2 == '\0') && ((&DAT_0071d89c)[iVar1] == 0)) {
        *(undefined4 *)(puVar4 + 0x120) = 0xffffffff;
        *(undefined4 *)(puVar4 + -8) = 0xffffffff;
        *(undefined4 *)(puVar4 + -4) = 0xffffffff;
        puVar4[1] = 0;
        *puVar4 = 0;
        puVar4[3] = 0x80;
        puVar4[2] = 0x80;
        iVar3 = iVar3 + -1;
      }
    }
    puVar4 = puVar4 + 0x270;
  } while ((int)puVar4 < 0x78e958);
  DAT_00736504 = iVar3;
  return;
}


// 004063a0 FUN_004063a0

void FUN_004063a0(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 *puVar3;
  int unaff_EDI;
  
  if (-1 < in_EAX) {
    *(int *)(unaff_EDI + 0x130) = in_EAX;
    *(undefined4 *)(unaff_EDI + 0x254) = 1;
    *(undefined4 *)(unaff_EDI + 0x260) = 1;
    *(undefined1 *)(unaff_EDI + 0x268) = 1;
    *(undefined1 *)(unaff_EDI + 0x264) = 0;
    *(undefined1 *)(unaff_EDI + 0x265) = 0;
    *(undefined1 *)(unaff_EDI + 0x266) = 0;
    *(undefined1 *)(unaff_EDI + 0x267) = 0;
    *(undefined4 *)(unaff_EDI + 600) = 0xffffffff;
    *(undefined4 *)(unaff_EDI + 0x25c) = 0xffffffff;
    *(undefined4 *)(unaff_EDI + 0x244) = 0;
    *(undefined4 *)(unaff_EDI + 0x250) = 4;
    puVar3 = (undefined4 *)FUN_00405fa0();
    cVar2 = FUN_0041cda0(*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    if (cVar2 == '\0') {
      FUN_004060a0(unaff_EDI);
    }
    iVar1 = *(int *)(unaff_EDI + 0x130);
    if ((&DAT_0071d89c)[iVar1] != 0) {
      if ((&DAT_0071d888)[iVar1] != '\0') {
        *(undefined4 *)(unaff_EDI + 0x134) = 0x16;
        DAT_00736504 = DAT_00736504 + 1;
        return;
      }
      if ((&DAT_0071d89c)[iVar1] != 0) {
        if ((&DAT_0071d898)[iVar1] != '\0') {
          *(undefined4 *)(unaff_EDI + 0x134) = 0x14;
          DAT_00736504 = DAT_00736504 + 1;
          return;
        }
        if (((&DAT_0071d89c)[iVar1] != 0) && ((&DAT_0071d88c)[iVar1] != '\0')) {
          DAT_00736504 = DAT_00736504 + 1;
          *(undefined4 *)(unaff_EDI + 0x134) = 0x15;
        }
      }
    }
  }
  return;
}


// 00405c60 FUN_00405c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00405c60(int param_1)

{
  char cVar1;
  int *in_EAX;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  DAT_007187c8 = in_EAX;
  (**(code **)(*in_EAX + 4))();
  pcVar2 = (char *)(param_1 + 300);
  *(undefined4 *)(unaff_EDI + 0x130) = 0;
  *(undefined4 *)(unaff_EDI + 0x134) = 0x13;
  iVar3 = (unaff_EDI + 0x138) - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar3] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(unaff_EDI + 0x23c) = 0;
  *(undefined4 *)(unaff_EDI + 0x11c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(unaff_EDI + 0x120) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(unaff_EDI + 0x124) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(unaff_EDI + 0x128) = *(undefined4 *)(param_1 + 0x10);
  FUN_00407ca0(unaff_EDI);
  _DAT_007187d8 = 4;
  puVar4 = &DAT_00719798;
  do {
    (**(code **)(*DAT_007187c8 + 0x74))(DAT_007187c8,puVar4,0,2);
    puVar4 = puVar4 + 0x52;
  } while ((int)puVar4 < 0x719a28);
  (**(code **)(*DAT_007187c8 + 0x74))(DAT_007187c8,&DAT_00719dc8,0,0);
  (**(code **)(*DAT_007187c8 + 0x78))(DAT_007187c8,&DAT_007198e0,0,0);
  *(undefined4 *)(unaff_EDI + 8) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0xc) = 0xffffffff;
  DAT_00736504 = DAT_00736504 + 1;
  return;
}


// 00405570 FUN_00405570

undefined4 FUN_00405570(void)

{
  int in_EAX;
  
  switch(*(undefined1 *)(in_EAX + 0x134)) {
  case 0x13:
    return 1;
  case 0x14:
  case 0x15:
    return 0;
  case 0x16:
    return 0;
  default:
    return 0;
  }
}


// 00406b10 FUN_00406b10

void FUN_00406b10(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int **ppiVar5;
  int *apiStack_2a0 [2];
  undefined4 uStack_288;
  int iStack_160;
  char acStack_15c [16];
  undefined1 auStack_14c [328];
  
  if (DAT_007187c8 != (int *)0x0) {
    apiStack_2a0[1] = DAT_007187c8;
    apiStack_2a0[0] = (int *)0x406b3a;
    (**(code **)(*DAT_007187c8 + 100))();
    apiStack_2a0[0] = (int *)0x0;
    iVar2 = (**(code **)(*DAT_007187c8 + 0x28))(DAT_007187c8,0x14,auStack_14c);
    if (iVar2 < 0) {
      if ((iVar2 == -0x7ff8fff4) || (iVar2 == -0x7ff8ffe2)) {
        (**(code **)(*DAT_007187c8 + 0x1c))(DAT_007187c8);
        return;
      }
    }
    else {
      puVar3 = (undefined1 *)0x0;
      if (&stack0x00000000 != (undefined1 *)0x290) {
        pcVar4 = acStack_15c;
        while( true ) {
          uVar1 = *(undefined4 *)(pcVar4 + -4);
          ppiVar5 = apiStack_2a0;
          for (iVar2 = 0x4f; iVar2 != 0; iVar2 = iVar2 + -1) {
            *ppiVar5 = (int *)0x0;
            ppiVar5 = ppiVar5 + 1;
          }
          apiStack_2a0[0] = (int *)0x13c;
          iVar2 = (**(code **)(*DAT_007187c8 + 0x38))(DAT_007187c8,apiStack_2a0,uVar1,1);
          if ((-1 < iVar2) && (*pcVar4 < '\0')) break;
          puVar3 = puVar3 + 1;
          pcVar4 = pcVar4 + 0x14;
          if (&stack0xfffffd70 <= puVar3) {
            return;
          }
        }
        if ((&iStack_160)[(int)puVar3 * 5] != 1) {
          FUN_00406f00(param_1,uStack_288);
          return;
        }
        *(undefined4 *)(param_1 + 0x23c) = 0;
        DAT_00736508 = 0;
        FUN_00407760(0);
        FUN_00407760(1);
      }
    }
  }
  return;
}


// 00407760 FUN_00407760

void __thiscall FUN_00407760(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int unaff_retaddr;
  
  piVar1 = DAT_007187c8;
  if (*(int *)(param_1 + 0x130) == -1) {
    *(undefined4 *)(param_1 + 0x118) = param_2;
    return;
  }
  if (DAT_007187c8 != (int *)0x0) {
    if (*(int *)(param_1 + 0x134) == 0x13) {
      *(undefined4 *)(param_1 + 8) = 0xffffffff;
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
      (**(code **)(*piVar1 + 0x20))(piVar1);
      iVar2 = (**(code **)(*DAT_007187c8 + 0x78))
                        (DAT_007187c8,&DAT_00719798 + unaff_retaddr * 0x52,0,2);
      if (iVar2 < 0) {
        FUN_00406580();
      }
      *(int *)(param_1 + 0x118) = unaff_retaddr;
      return;
    }
    *(undefined4 *)(param_1 + 0x118) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x118) = param_2;
  return;
}


// 004079f0 FUN_004079f0

undefined1 * FUN_004079f0(undefined4 param_1,int param_2,int param_3)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = &DAT_0078eba8;
  for (iVar3 = 0x4f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  uVar6 = 0;
  DAT_0078eba8 = 0x13c;
  bVar2 = true;
  if (DAT_007197a4 != 0) {
    piVar4 = &DAT_007187f0;
    do {
      if (piVar4[-8] == param_2) {
        if ((param_3 == 1) && (bVar2)) {
          bVar2 = false;
        }
        else if ((*piVar4 != 0) &&
                (iVar3 = (**(code **)(*DAT_007187c8 + 0x38))(DAT_007187c8,&DAT_0078eba8,*piVar4,2),
                -1 < iVar3)) {
          iVar3 = 0;
          if (DAT_0078ebc8 != '\0') {
            do {
              pcVar1 = &DAT_0078ebc9 + iVar3;
              iVar3 = iVar3 + 1;
            } while (*pcVar1 != '\0');
            if (0x40 < iVar3) {
              DAT_0078ebc9 = 0;
            }
          }
          return &DAT_0078ebc8;
        }
      }
      uVar6 = uVar6 + 1;
      piVar4 = piVar4 + 10;
    } while (uVar6 < DAT_007197a4);
  }
  return &DAT_006b9172;
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


// 00574a00 FUN_00574a00

undefined * FUN_00574a00(int param_1)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  iVar2 = FUN_005749b0();
  iVar5 = 0;
  if (0 < DAT_00704140) {
    puVar3 = &DAT_00703880;
    do {
      if (*(int *)(puVar3 + 8) == param_1) {
        iVar4 = 0;
        do {
          if (iVar2 == 0) {
            bVar6 = param_1 == 1;
LAB_00574a4a:
            if (bVar6) {
              return puVar3;
            }
          }
          else {
            cVar1 = puVar3[iVar4];
            if (cVar1 != '\0') {
              if (cVar1 == -1) {
                return puVar3;
              }
              bVar6 = cVar1 == iVar2;
              goto LAB_00574a4a;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 8);
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 0x20;
    } while (iVar5 < DAT_00704140);
  }
  return (undefined *)0x0;
}


// 00574a70 FUN_00574a70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574a70(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 uVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar3 = 0xc;
  bVar1 = 0x20;
  if (0 < DAT_007041c0) {
    puVar2 = &DAT_00704158;
    iVar4 = DAT_007041c0;
    do {
      if (*(int *)(puVar2 + -0x10) == unaff_EDI) {
        if (unaff_ESI == 1) {
          bVar1 = puVar2[-1];
LAB_00574aa4:
          uVar3 = puVar2[-2];
        }
        else if (unaff_ESI == 2) {
          bVar1 = puVar2[1];
          uVar3 = *puVar2;
        }
        else {
          if (unaff_ESI != 3) goto LAB_00574aa4;
          bVar1 = puVar2[3];
          uVar3 = puVar2[2];
        }
      }
      puVar2 = puVar2 + 0x14;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(undefined1 *)(param_1 + 0x28) = uVar3;
  *(float *)(param_1 + 8) = _DAT_006cc7c4 - (float)bVar1;
  *(float *)(param_1 + 0x10) = (float)bVar1 + _DAT_006cc7c4;
  return;
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


// 0057c3b0 FUN_0057c3b0

void FUN_0057c3b0(uint param_1,int param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  
  iVar4 = param_2 + 7 >> 3;
  if ((param_1 == unaff_ESI[7]) && (param_3 == unaff_ESI[5])) {
    iVar2 = unaff_ESI[8];
    unaff_ESI[8] = iVar2 + 1;
    if ((*(int *)(&DAT_006f1110 + param_3 * 0xc) != 0) &&
       (*(int *)(&DAT_006f1110 + param_3 * 0xc) < iVar2 + 1)) {
      FUN_0063e5c0(1);
    }
  }
  else {
    unaff_ESI[7] = param_1;
    unaff_ESI[5] = param_3;
  }
  iVar2 = *unaff_ESI;
  pcVar1 = (char *)((iVar2 - unaff_ESI[3]) + 100 + (int)unaff_ESI);
  *pcVar1 = (char)iVar4 * '\x10' + (char)param_3;
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      pcVar1[iVar3 + 1] = (char)param_1;
      param_1 = param_1 >> 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  iVar2 = iVar4 + 1 + iVar2;
  iVar4 = iVar2 - unaff_ESI[3];
  *unaff_ESI = iVar2;
  unaff_ESI[1] = iVar4;
  unaff_ESI[4] = iVar2;
  if (((unaff_ESI[3] - iVar2) + 0x4000 < 0x100) && (0 < iVar4)) {
    FUN_00594ef0(unaff_ESI + 0x19);
    unaff_ESI[3] = *unaff_ESI;
    unaff_ESI[1] = 0;
  }
  return;
}


// 0040a880 FUN_0040a880

void FUN_0040a880(void)

{
  return;
}


