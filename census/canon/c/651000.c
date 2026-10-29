// ==== 0x6510d0 FUN_006510d0

void FUN_006510d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = DAT_00713f78[5];
  iVar3 = 0;
  if (iVar2 < 0) {
    piVar4 = (int *)DAT_00713f78[1];
    while (*piVar4 != param_1 - *DAT_00713f78) {
      iVar3 = iVar3 + -1;
      piVar4 = piVar4 + -2;
      if (iVar3 <= iVar2) {
        return;
      }
    }
    DAT_00713f78[5] = iVar2 + 1;
    DAT_00713f78[3] = DAT_00713f78[3] + 8;
    if (DAT_00713f78[5] < iVar3) {
      do {
        puVar1 = (undefined4 *)(DAT_00713f78[1] + iVar3 * 8);
        *puVar1 = *(undefined4 *)(DAT_00713f78[1] + -8 + iVar3 * 8);
        puVar1[1] = puVar1[-1];
        iVar3 = iVar3 + -1;
      } while (DAT_00713f78[5] < iVar3);
    }
  }
  return;
}


// ==== 0x651150 FUN_00651150

void FUN_00651150(int param_1)

{
  DAT_00713fcc = DAT_006e9bcc + param_1;
  DAT_00713fd0 = DAT_006e9bd0 + param_1;
  DAT_00713fd4 = DAT_006e9bd4 + param_1;
  DAT_00713fd8 = DAT_006e9bd8 + param_1;
  DAT_00713fdc = DAT_006e9bdc + param_1;
  DAT_00713fe0 = DAT_006e9be0 + param_1;
  return;
}


// ==== 0x6511b0 iSNDrandom

/* [canon] audio med (ghidra) docs/re/sound.md */

void iSNDrandom(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = DAT_00713fdc + DAT_00713fe0;
  if ((uVar1 < DAT_00713fe0) || (uVar1 < DAT_00713fdc)) {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
  }
  uVar2 = uVar1 + iVar5 + DAT_00713fd8;
  uVar3 = uVar2 + (uVar2 < DAT_00713fd8) + DAT_00713fd4;
  uVar4 = uVar3 + (uVar3 < DAT_00713fd4) + DAT_00713fd0;
  DAT_00713fcc = DAT_00713fcc + uVar4 + (uVar4 < DAT_00713fd0);
  DAT_00713fe0 = DAT_00713fe0 + 1;
  DAT_00713fd0 = uVar4;
  DAT_00713fd4 = uVar3;
  DAT_00713fd8 = uVar2;
  DAT_00713fdc = uVar1;
  if ((((DAT_00713fe0 == 0) && (DAT_00713fdc = uVar1 + 1, DAT_00713fdc == 0)) &&
      (DAT_00713fd8 = uVar2 + 1, DAT_00713fd8 == 0)) &&
     ((DAT_00713fd4 = uVar3 + 1, DAT_00713fd4 == 0 && (DAT_00713fd0 = uVar4 + 1, DAT_00713fd0 == 0))
     )) {
    DAT_00713fcc = DAT_00713fcc + 1;
  }
  return;
}


// ==== 0x651260 SNDPLATFORM_setpitch

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 SNDPLATFORM_setpitch(int param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  
  iVar1 = param_1 * 0x8c + DAT_00713f48;
  iVar2 = param_1 * 0x110 + DAT_0071400c;
  uVar3 = *(ushort *)(iVar1 + 0x8a);
  if (((*(byte *)(iVar1 + 0x24) & 2) != 0) && (0x2000 < uVar3)) {
    uVar3 = 0x2000;
  }
  (**(code **)(iVar2 + 0xec))(*(undefined4 *)(iVar2 + 200),uVar3);
  return 0;
}


// ==== 0x6512c0 FUN_006512c0

undefined4 FUN_006512c0(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x110 + DAT_0071400c;
  pcVar1 = *(code **)(iVar2 + 0xf0);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(*(undefined4 *)(iVar2 + 0xcc),param_2);
  }
  return 0;
}


// ==== 0x6512f0 Snd::Hal::SetVol__SNDPLATFORM_setvol_

/* [canon] audio high (ghidra) docs/re/sound.md */

void Snd__Hal__SetVol__SNDPLATFORM_setvol_(int param_1)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 * 0x8c + DAT_00713f48;
  iVar6 = param_1 * 0x110 + DAT_0071400c;
  if ((*(byte *)(param_1 * 0x8c + 0x24 + DAT_00713f48) & 4) == 0) {
    piVar3 = *(int **)(*(int *)(iVar6 + 0xc0) + 0x3c);
    (**(code **)(*piVar3 + 0x3c))
              (piVar3,(int)*(short *)(&DAT_006e9be8 +
                                     (int)ROUND(*(float *)(iVar4 + 0x48) * 127.0) * 2));
  }
  else {
    cVar2 = *(char *)(iVar4 + 0x5f);
    iVar5 = 0;
    fVar1 = *(float *)(iVar4 + 0x48);
    if (DAT_00713cdc != 0) {
      do {
        FUN_00656870(param_1,iVar5,
                     (float)(int)cVar2 * fVar1 * 0.007874016 * *(float *)(iVar6 + iVar5 * 4));
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)DAT_00713cdc);
      return;
    }
  }
  return;
}


// ==== 0x6513b0 FUN_006513b0

void FUN_006513b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x8c + DAT_00713f48;
  iVar2 = param_1 * 0x110 + DAT_0071400c;
  if (*(char *)(param_1 * 0x8c + 0x4e + DAT_00713f48) == '\0') {
    FUN_006533c0(*(undefined2 *)(iVar3 + 0x1c),iVar2);
  }
  else {
    iVar1 = 0;
    if (DAT_00713cdc != 0) {
      do {
        *(undefined4 *)(iVar2 + iVar1 * 4) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)DAT_00713cdc);
    }
    *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;
  }
  if ((*(byte *)(iVar3 + 0x24) & 0x44) == 0) {
    FUN_00656f20(*(undefined4 *)(iVar2 + 0xbc),*(undefined2 *)(iVar3 + 0x1c),
                 (int)*(short *)(iVar3 + 0x1e));
  }
  Snd__Hal__SetVol__SNDPLATFORM_setvol_(param_1);
  return;
}


// ==== 0x651450 SNDPLATFORM_setfxlevel__map:_SNDstop_

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDPLATFORM_setfxlevel__map__SNDstop_(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x110 + DAT_0071400c;
  (**(code **)(iVar1 + 0xf4))
            (*(undefined4 *)(iVar1 + 0xc4),
             (int)*(short *)(DAT_00713f48 + 0x62 + (param_1 * 0x46 + param_2) * 2));
  return 0;
}


// ==== 0x651490 SNDI_calcfxlevel

/* [canon] audio high (ghidra) docs/re/sound.md */

void SNDI_calcfxlevel(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 * 0x8c + DAT_00713f48;
  iVar1 = SNDCTRLI_getfxbus(param_1,*(undefined2 *)(iVar2 + 0x24));
  *(short *)(iVar2 + 0x62 + param_1 * 2) =
       (short)((int)*(char *)(iVar2 + 0x61 + param_1) * (int)*(char *)(iVar2 + 0x60 + param_1) *
               (int)*(char *)(iVar1 + 2) >> 6);
  return;
}


// ==== 0x6514e0 FUN_006514e0

void FUN_006514e0(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 * 0x110 + DAT_0071400c + 0xf8);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00651506. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// ==== 0x651510 FUN_00651510

void FUN_00651510(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 * 0x110 + DAT_0071400c + 0xfc);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00651536. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// ==== 0x651540 FUN_00651540

int FUN_00651540(short *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 *param_8,int param_9,
                undefined4 *param_10,int param_11,undefined1 param_12)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [6];
  undefined4 local_3c [6];
  undefined4 auStack_24 [9];
  
  iVar4 = (int)param_1 * 0x110 + DAT_0071400c;
  iVar5 = (int)param_1 * 0x8c;
  iVar3 = iVar4 + 0x2c;
  iVar6 = iVar5 + DAT_00713f48;
  *(undefined4 *)(iVar4 + 0x10c) = 0;
  *(int *)(iVar4 + 0xbc) = iVar3;
  *(int *)(iVar4 + 0xc0) = iVar3;
  *(int *)(iVar4 + 0xc4) = iVar3;
  *(int *)(iVar4 + 200) = iVar3;
  *(int *)(iVar4 + 0xcc) = iVar3;
  *(int *)(iVar4 + 0xd0) = iVar3;
  *(int *)(iVar4 + 0xd4) = iVar3;
  *(int *)(iVar4 + 0xd8) = iVar3;
  *(int *)(iVar4 + 0xdc) = iVar3;
  *(int *)(iVar4 + 0xe0) = iVar3;
  uVar1 = *(ushort *)(iVar6 + 0x24);
  if ((uVar1 & 0x10) == 0) {
    if ((uVar1 & 4) != 0) {
      local_64._0_3_ =
           CONCAT12(param_12,CONCAT11(*(undefined1 *)(iVar6 + 0x22),*(undefined1 *)(iVar6 + 0x23)));
      local_60 = param_2;
      local_68 = CONCAT22((short)param_1,*(undefined2 *)(iVar6 + 0x20));
      local_5c = param_3;
      local_58 = *(undefined4 *)(iVar6 + 0x14);
      *(code **)(iVar4 + 0xec) = FUN_00657540;
      *(code **)(iVar4 + 0xf8) = FUN_006575d0;
      *(code **)(iVar4 + 0xfc) = FUN_00657630;
      *(code **)(iVar4 + 0xf0) = FUN_00657590;
      *(code **)(iVar4 + 0x108) = FUN_00657670;
      *(undefined4 *)(iVar4 + 0x100) = 0;
      *(undefined4 *)(iVar4 + 0x104) = 0;
      *(code **)(iVar4 + 0xe8) = FUN_006577a0;
      *(code **)(iVar4 + 0xf4) = FUN_006574d0;
      iVar2 = 0;
      if (*(char *)(iVar6 + 0x23) != '\0') {
        do {
          local_3c[iVar2] = *(undefined4 *)(param_9 + iVar2 * 4);
          local_54[iVar2] = param_8[iVar2];
          auStack_24[iVar2] = param_10[iVar2];
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)*(byte *)(iVar6 + 0x23));
      }
      FUN_00657690(iVar3,&local_68);
    }
  }
  else {
    if (1 < *(byte *)(iVar6 + 0x23)) {
      return -7;
    }
    if ((uVar1 & 1) == 0) {
      local_54[0] = *param_8;
      local_54[1] = *param_10;
      local_68 = CONCAT22((short)param_1,*(undefined2 *)(iVar6 + 0x20));
      local_5c = param_3;
      local_60 = param_2;
      local_58 = *(undefined4 *)(iVar6 + 0x14);
      iVar2 = iVar4 + 0x74;
      local_64._0_3_ =
           CONCAT12(param_12,CONCAT11(*(undefined1 *)(iVar6 + 0x22),*(undefined1 *)(iVar6 + 0x23)));
      FUN_00657b50(iVar2,&local_68);
      *(int *)(iVar4 + 0xcc) = iVar2;
      *(int *)(iVar4 + 0xd0) = iVar2;
      *(int *)(iVar4 + 0xd4) = iVar2;
      *(int *)(iVar4 + 0xd8) = iVar2;
      *(code **)(iVar4 + 0xf8) = FUN_00657940;
      *(code **)(iVar4 + 0xfc) = FUN_00657a40;
      *(code **)(iVar4 + 0xf0) = FUN_00657910;
      *(code **)(iVar4 + 0x108) = FUN_00657b20;
      local_64 = 0;
    }
    else {
      if (param_11 == 0) {
        return -0xf;
      }
      iVar2 = FUN_00654010(param_11);
      if (iVar2 == 0) {
        return -9;
      }
      local_64 = *(undefined4 *)(&DAT_00714094 + *(int *)(iVar2 + 4) * 0x20);
      *(undefined4 *)(iVar4 + 0xf8) = 0;
      *(undefined4 *)(iVar4 + 0xfc) = 0;
      *(undefined4 *)(iVar4 + 0xf0) = 0;
      *(code **)(iVar4 + 0x108) = FUN_00657040;
    }
    local_68 = DAT_00714068;
    local_60 = CONCAT31(local_60._1_3_,param_12);
    local_60 = CONCAT22(*(undefined2 *)(iVar6 + 0x20),(undefined2)local_60);
    local_5c._0_2_ = CONCAT11(DAT_00714075,0 < param_3);
    iVar2 = FUN_00657220(iVar3,&local_68);
    if (iVar2 == 0) {
      if ((*(byte *)(iVar6 + 0x24) & 2) != 0) {
        FUN_00657c50(iVar4 + 0x74);
      }
      return -9;
    }
    *(code **)(iVar4 + 0xec) = FUN_00656fd0;
    *(code **)(iVar4 + 0x100) = FUN_00656ef0;
    *(code **)(iVar4 + 0x104) = FUN_00657080;
    *(code **)(iVar4 + 0xe8) = FUN_006571e0;
    *(code **)(iVar4 + 0xf4) = FUN_00656f90;
    if ((*(byte *)(iVar6 + 0x24) & 2) != 0) {
      *(undefined2 *)(iVar4 + 0x44) = 0;
      FUN_006577e0(iVar4 + 0xe4,iVar3);
    }
  }
  (**(code **)(iVar4 + 0xec))(*(undefined4 *)(iVar4 + 200),*(undefined2 *)(iVar6 + 0x8a));
  if (*(char *)(iVar6 + 0x23) != '\0') {
    param_1 = (short *)(iVar6 + 4);
    iVar2 = 0;
    do {
      FUN_006513b0((int)*param_1);
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(iVar6 + 0x23));
  }
  if (*(code **)(iVar4 + 0xf8) != (code *)0x0) {
    (**(code **)(iVar4 + 0xf8))(*(undefined4 *)(iVar4 + 0xd0),param_6);
  }
  if (*(code **)(iVar4 + 0xfc) != (code *)0x0) {
    (**(code **)(iVar4 + 0xfc))(*(undefined4 *)(iVar4 + 0xd0),param_7);
  }
  if (*(code **)(iVar4 + 0xf0) != (code *)0x0) {
    (**(code **)(iVar4 + 0xf0))
              (*(undefined4 *)(iVar4 + 0xcc),*(undefined2 *)(iVar5 + 0x6a + DAT_00713f48));
  }
  if (*(code **)(iVar4 + 0x100) != (code *)0x0) {
    (**(code **)(iVar4 + 0x100))(*(undefined4 *)(iVar4 + 0xe0),100);
  }
  if ((*(byte *)(iVar6 + 0x24) & 0x10) == 0) {
    iVar3 = FUN_00657770(iVar3);
  }
  else {
    iVar3 = FUN_00657410();
  }
  if (-1 < iVar3) {
    (**(code **)(iVar4 + 0xf4))(*(undefined4 *)(iVar4 + 0xc4),(int)*(short *)(iVar6 + 0x62));
    if ((*(byte *)(iVar6 + 0x24) & 1) != 0) {
      *(code **)(iVar4 + 0x10c) = FUN_00657060;
    }
    return 0;
  }
  if ((*(byte *)(iVar6 + 0x24) & 2) != 0) {
    FUN_00657c50(iVar4 + 0x74);
  }
  return iVar3;
}


// ==== 0x651a00 FUN_00651a00

void FUN_00651a00(byte param_1,uint *param_2,uint *param_3)

{
  if ((param_1 & 4) != 0) {
    *param_2 = 0;
    *param_3 = (uint)DAT_00713d9e;
    return;
  }
  if ((param_1 & 0x10) != 0) {
    *param_2 = (uint)DAT_00713d9e;
    *param_3 = (int)DAT_00713ee8;
  }
  return;
}


// ==== 0x651a40 FUN_00651a40

undefined4 FUN_00651a40(void)

{
  return DAT_00714018;
}


// ==== 0x651a50 FUN_00651a50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00651a50(undefined1 *param_1)

{
  int iVar1;
  char local_8 [4];
  undefined1 local_4 [4];
  
  if (DAT_00714018 == 0) {
    _DAT_00713fe4 = 0;
    _DAT_00713fe8 = 0;
    DAT_00714018 = 1;
    DAT_00713fec = 0;
    iVar1 = FUN_00654880(local_8,local_4,&DAT_00713d75,&DAT_00713fe4);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_1 != (undefined1 *)0x0) {
      *param_1 = DAT_00713fe4;
      param_1[1] = DAT_00713fe5;
      param_1[2] = DAT_00713fe6;
      param_1[3] = DAT_00713fe7;
      param_1[4] = DAT_00713fe8;
      param_1[5] = DAT_00713fe9;
      param_1[6] = DAT_00713fea;
      param_1[7] = DAT_00713feb;
      param_1[8] = DAT_00713fec;
    }
  }
  else {
    *param_1 = DAT_00713fe4;
    param_1[1] = DAT_00713fe5;
    param_1[2] = DAT_00713fe6;
    param_1[3] = DAT_00713fe7;
    param_1[4] = DAT_00713fe8;
    param_1[5] = DAT_00713fe9;
    param_1[6] = DAT_00713fea;
    param_1[7] = DAT_00713feb;
    param_1[8] = DAT_00713fec;
  }
  DAT_00713d7c = local_4[0];
  DAT_00713dae = local_4[0];
  DAT_00713d7a = local_8[0];
  DAT_00713d76 = 0x80;
  DAT_00713d70 = 0x2b11;
  DAT_00713d72 = 48000;
  DAT_00713d74 = 1;
  DAT_00713dad = 1;
  DAT_00713d83 = 1;
  _DAT_00713d84 = 0x24;
  if (local_8[0] != '\0') {
    DAT_00713d83 = 3;
    _DAT_00713d86 = 0x91;
    _DAT_00713d88 = 0x92;
  }
  DAT_00713dbc = 1;
  _DAT_00713dbe = 0x24;
  DAT_00713d9e = 0x20;
  DAT_00713da1 = 0;
  DAT_00713db6 = 0x10;
  DAT_00713d9a = 0xac44;
  DAT_00713db7 = 2;
  DAT_00713db0 = 0x19;
  DAT_00713eeb = FUN_00657cd0();
  return 0;
}


// ==== 0x651c10 FUN_00651c10

uint FUN_00651c10(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  *(undefined1 *)(param_2 + 2) = 0;
  uVar1 = FUN_00651a50(param_2);
  return uVar1 & (-1 < (int)uVar1) - 1;
}


// ==== 0x651c40 FUN_00651c40

uint FUN_00651c40(void)

{
  uint uVar1;
  
  uVar1 = FUN_00651a50(0);
  return uVar1 & (-1 < (int)uVar1) - 1;
}


// ==== 0x651c60 FUN_00651c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00651c60(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_006565c0(DAT_00713db0);
  if (DAT_00713ee4 != '\0') {
    puVar5 = &DAT_00713e44;
    puVar6 = &DAT_00713d90;
    for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    return 0;
  }
  DAT_00713ff3 = '\0';
  DAT_00713ff4 = 0;
  DAT_00713ff5 = 0;
  if (DAT_00713db7 < DAT_00713d74) {
    DAT_00713db7 = DAT_00713d74;
  }
  if (DAT_00713d75 < DAT_00713db7) {
    DAT_00713db7 = DAT_00713d75;
  }
  if (DAT_00713d9a < DAT_00713d70) {
    DAT_00713d9a = DAT_00713d70;
  }
  if (DAT_00713d72 < DAT_00713d9a) {
    DAT_00713d9a = DAT_00713d72;
  }
  if (DAT_00713d76 < DAT_00713d9e) {
    DAT_00713d9e = DAT_00713d76;
  }
  if (DAT_00713d7a < DAT_00713da1) {
    DAT_00713da1 = DAT_00713d7a;
  }
  if (0x20 < DAT_00713db6) {
    DAT_00713db6 = 0x20;
  }
  if ((DAT_00713dae != '\0') && (DAT_00713d7c == '\0')) {
    DAT_00713dae = '\0';
  }
  if (DAT_00713db7 == 4) {
    if (DAT_00713db8 != '\0') {
      DAT_00713db8 = '\0';
    }
  }
  else if (DAT_00713db7 == 2) {
    if (DAT_00713db8 != '\0') {
      DAT_00713db8 = '\0';
    }
  }
  else if ((DAT_00713db7 == 6) && (DAT_00713db8 == '\0')) {
    DAT_00713db7 = 5;
    DAT_00713db8 = '\x01';
  }
  DAT_00713ee8 = (ushort)DAT_00713da1 + (ushort)DAT_00713d9e;
  if (0x100 < DAT_00713ee8) {
    DAT_00713da1 = DAT_00713da1 - (char)DAT_00713ee8;
    DAT_00713ee8 = 0x100;
  }
  do {
    iVar3 = 0;
    bVar4 = DAT_00713dbc;
    while( true ) {
      if ((int)(uint)bVar4 <= iVar3) {
        if (DAT_00713ff3 == '\0') {
          DAT_00713da1 = 0;
        }
        if (_DAT_00713da4 == -1.0) {
          _DAT_00713ca0 = 20.0;
        }
        else if (10.0 <= _DAT_00713da4) {
          _DAT_00713ca0 = _DAT_00713da4;
          if (100.0 < _DAT_00713da4) {
            _DAT_00713ca0 = 100.0;
          }
        }
        else {
          _DAT_00713ca0 = 10.0;
        }
        _DAT_00713ff8 = 10.0 / _DAT_00713ca0;
        if ((DAT_00713dad != '\0') && (uVar2 = FUN_00657cd0(), (uVar2 & 2) != 0)) {
          DAT_00713eeb = DAT_00713eeb | 2;
          return 0;
        }
        DAT_00713eeb = DAT_00713eeb & 0xfd;
        DAT_00713dad = 0;
        return 0;
      }
      if ((DAT_00713da1 == 0) && (((&DAT_00713dbe)[iVar3 * 2] & 0x10) != 0)) {
        *(undefined2 *)(&DAT_00713dbe + iVar3 * 2) = 0;
        bVar4 = DAT_00713dbc;
      }
      uVar1 = *(ushort *)(&DAT_00713dbe + iVar3 * 2);
      if ((uVar1 & 0x10) != 0) {
        DAT_00713ff3 = '\x01';
        if ((uVar1 & 1) == 0) {
          if ((uVar1 & 2) != 0) {
            DAT_00713ff4 = 1;
          }
        }
        else {
          DAT_00713ff5 = 1;
        }
      }
      if (uVar1 == 0) break;
      iVar3 = iVar3 + 1;
    }
    DAT_00713dbc = bVar4 - 1;
    if (iVar3 < (int)(uint)DAT_00713dbc) {
      do {
        *(undefined2 *)(&DAT_00713dbe + iVar3 * 2) = *(undefined2 *)(&DAT_00713dc0 + iVar3 * 2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)DAT_00713dbc);
    }
  } while( true );
}


// ==== 0x651f30 FUN_00651f30

undefined4 FUN_00651f30(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x8c + DAT_00713f48;
  iVar2 = param_1 * 0x110 + DAT_0071400c;
  (**(code **)(iVar2 + 0xe8))(iVar2 + 0x2c);
  uVar1 = *(ushort *)(iVar3 + 0x24);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) != 0) {
      FUN_00657c50(iVar2 + 0x74);
    }
  }
  else {
    *(undefined4 *)(iVar2 + 0x10c) = 0;
  }
  if ((*(byte *)(iVar3 + 0x24) & 0x10) != 0) {
    SNDVOICEI_free(param_1);
  }
  return 0;
}


// ==== 0x651fa0 FUN_00651fa0

void FUN_00651fa0(int param_1)

{
  if ((*(byte *)(param_1 * 0x8c + 0x24 + DAT_00713f48) & 4) != 0) {
    Snd__Hal__SetVol__SNDPLATFORM_setvol_();
    return;
  }
  return;
}


// ==== 0x651fd0 FUN_00651fd0

undefined4 FUN_00651fd0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_006584a0(param_1);
  if (-1 < iVar1) {
    iVar1 = *(int *)(DAT_00713f4c + param_1 * 8);
    if ((-1 < param_2) && (param_2 < (int)(uint)*(ushort *)(iVar1 + 6))) {
      uVar2 = FUN_00658470(iVar1,param_2,param_1,param_2,param_3);
      uVar2 = SNDBANKI_playpatch(iVar1,uVar2);
      return uVar2;
    }
  }
  return 0xfffffff8;
}


// ==== 0x652030 SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map:_SNDSYS_entercritical_

/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
              (undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if (DAT_00713ee4 != '\0') {
    iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
    if (-1 < iVar1) {
      local_4 = 0xffffffff;
      iVar2 = iSNDpatchkey(iVar1,&local_4);
      while (iVar2 != 0) {
        FUN_00651f30(local_4);
        iVar2 = iSNDpatchkey(iVar1,&local_4);
      }
    }
    return iVar1;
  }
  return -10;
}


// ==== 0x6520a0 SNDpitchmult

/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDpitchmult(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = -1;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      iVar2 = local_4 * 0x8c + DAT_00713f48;
      if (*(ushort *)(iVar2 + 0x88) == param_2) {
        return 0;
      }
      *(short *)(iVar2 + 0x88) = (short)param_2;
      iSNDcalcpitch(local_4);
      SNDPLATFORM_setpitch(local_4);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x652150 SNDvol__map:_SNDSYSI_100hzserver_

/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDvol__map__SNDSYSI_100hzserver_(undefined4 param_1,int param_2)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  float fStack_8;
  int iStack_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar3 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar3) {
    fStack_8 = (float)param_2 * 0.007874016;
    iStack_c = -1;
    iStack_4 = iVar3;
    iVar4 = iSNDpatchkey(iVar3,&iStack_c);
    while (iVar4 != 0) {
      iVar7 = iStack_c * 0x8c + DAT_00713f48;
      iVar4 = 0;
      bVar2 = false;
      if (*(char *)(iStack_c * 0x8c + 0x23 + DAT_00713f48) != '\0') {
        psVar5 = (short *)(iVar7 + 4);
        do {
          iVar6 = (int)*psVar5;
          fVar1 = *(float *)(iVar6 * 0x8c + 0x38 + DAT_00713f48);
          iVar3 = iVar6 * 0x8c + DAT_00713f48;
          *(undefined4 *)(iVar3 + 0x30) = 0;
          if (fVar1 != fStack_8) {
            bVar2 = true;
            *(float *)(iVar3 + 0x38) = fStack_8;
            iSNDcalcvol(iVar6);
            Snd__Hal__SetVol__SNDPLATFORM_setvol_(iVar6);
          }
          iVar4 = iVar4 + 1;
          psVar5 = psVar5 + 1;
        } while (iVar4 < (int)(uint)*(byte *)(iVar7 + 0x23));
        iVar3 = iStack_4;
        if ((bVar2) && (0 < *(short *)(iVar7 + 0x62))) {
          SNDPLATFORM_setfxlevel__map__SNDstop_(iStack_c,0);
          iVar3 = iStack_4;
        }
      }
      iVar4 = iSNDpatchkey(iVar3,&iStack_c);
    }
  }
  return iVar3;
}


// ==== 0x652270 FUN_00652270

int FUN_00652270(uint param_1,uint param_2,uint *param_3,int param_4,int param_5)

{
  short *psVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  uint local_c;
  undefined2 *local_8;
  uint local_4;
  
  local_c = 0;
  if (0 < (int)param_1) {
    puVar13 = (undefined4 *)&DAT_0071401c;
    for (uVar6 = param_1 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar13 = 0xffffffff;
      puVar13 = puVar13 + 1;
    }
    for (uVar6 = (uint)((param_1 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined2 *)puVar13 = 0xffff;
      puVar13 = (undefined4 *)((int)puVar13 + 2);
    }
  }
  DAT_00714028 = DAT_00714028 + 0x100;
  if ((int)DAT_00714028 < 0) {
    DAT_00714028 = 0;
  }
  if (0 < (int)param_1) {
    local_8 = &DAT_0071401c;
    local_4 = param_1;
    do {
      iVar14 = -1;
      uVar6 = 0xffffffff;
      if (param_4 < param_5) {
        iVar8 = param_4 * 0x8c + DAT_00713f48;
        iVar7 = param_4;
        do {
          if (*(char *)(iVar8 + 0x69) == '\0') {
            iVar4 = 0;
            if (0x71401c < (int)local_8) {
              do {
                if ((&DAT_0071401c)[iVar4] == iVar7) goto LAB_00652320;
                iVar4 = iVar4 + 1;
              } while (iVar4 < (int)local_c);
            }
            if (*(uint *)(iVar8 + 0x2c) < uVar6) {
              uVar6 = *(uint *)(iVar8 + 0x2c);
              iVar14 = iVar7;
            }
          }
LAB_00652320:
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x8c;
        } while (iVar7 < param_5);
        if (-1 < iVar14) {
          local_c = local_c + 1;
          *local_8 = (short)iVar14;
          local_8 = local_8 + 1;
        }
      }
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  if ((int)local_c < (int)param_1) {
    local_8 = &DAT_0071401c + local_c;
    local_4 = local_c;
    do {
      uVar6 = param_2;
      if (DAT_00713dac == '\0') {
        uVar6 = param_2 - 1;
      }
      iVar14 = -1;
      uVar10 = 0xffffffff;
      if (param_4 < param_5) {
        pbVar9 = (byte *)(param_4 * 0x8c + 0x2a + DAT_00713f48);
        iVar7 = param_4;
        do {
          iVar8 = 0;
          if (0x71401c < (int)local_8) {
            do {
              if ((&DAT_0071401c)[iVar8] == iVar7) goto LAB_006523f6;
              iVar8 = iVar8 + 1;
            } while (iVar8 < (int)local_c);
          }
          if (*pbVar9 < 0x65) {
            uVar5 = (uint)*pbVar9;
            if ((int)uVar5 < (int)uVar6) {
              uVar11 = *(uint *)(pbVar9 + 2);
              uVar6 = uVar5;
            }
            else if ((uVar5 != uVar6) || (uVar11 = *(uint *)(pbVar9 + 2), uVar10 <= uVar11))
            goto LAB_006523f6;
            uVar10 = uVar11;
            iVar14 = iVar7;
          }
LAB_006523f6:
          iVar7 = iVar7 + 1;
          pbVar9 = pbVar9 + 0x8c;
        } while (iVar7 < param_5);
        if (-1 < iVar14) {
          *local_8 = (short)iVar14;
          local_8 = local_8 + 1;
          local_c = local_c + 1;
          if ((int)param_1 <= (int)local_c) break;
        }
      }
      local_4 = local_4 + 1;
    } while ((int)local_4 < (int)param_1);
  }
  if (local_c != param_1) {
    return -9;
  }
  do {
    iVar14 = 0;
    bVar3 = true;
    if ((int)(param_1 - 1) < 1) break;
    do {
      sVar2 = (&DAT_0071401c)[iVar14];
      if ((short)(&DAT_0071401e)[iVar14] < sVar2) {
        (&DAT_0071401c)[iVar14] = (&DAT_0071401e)[iVar14];
        (&DAT_0071401e)[iVar14] = sVar2;
        bVar3 = false;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < (int)(param_1 - 1));
  } while (!bVar3);
  *param_3 = (int)DAT_0071401c | DAT_00714028;
  iVar14 = (int)DAT_0071401c;
  if (0 < (int)local_c) {
    iVar7 = 0;
    do {
      iVar4 = (&DAT_0071401c)[iVar7] * 0x8c;
      iVar8 = *(int *)(iVar4 + DAT_00713f48);
      iVar12 = iVar4 + DAT_00713f48;
      if (*(char *)(iVar4 + 0x69 + DAT_00713f48) != '\0') {
        if (iVar8 < 0) {
          iVar8 = *(int *)(*(short *)(iVar12 + 0x28) * 0x8c + DAT_00713f48);
        }
        SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
                  (iVar8);
      }
      *(undefined1 *)(iVar12 + 0x69) = 1;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar12 + 0x2c) = DAT_00713eec;
      *(undefined1 *)(iVar12 + 0x2a) = (undefined1)param_2;
    } while (iVar7 < (int)local_c);
  }
  *(uint *)(DAT_0071401c * 0x8c + DAT_00713f48) = *param_3;
  *(short *)(DAT_0071401c * 0x8c + 4 + DAT_00713f48) = DAT_0071401c;
  *(undefined2 *)(DAT_0071401c * 0x8c + 0x28 + DAT_00713f48) = 0xffff;
  iVar7 = 1;
  if (1 < (int)local_c) {
    do {
      *(short *)(DAT_00713f48 + 4 + (DAT_0071401c * 0x46 + iVar7) * 2) = (&DAT_0071401c)[iVar7];
      *(undefined4 *)((&DAT_0071401c)[iVar7] * 0x8c + DAT_00713f48) = 0xffffffff;
      psVar1 = &DAT_0071401c + iVar7;
      iVar7 = iVar7 + 1;
      *(short *)(*psVar1 * 0x8c + 0x28 + DAT_00713f48) = DAT_0071401c;
    } while (iVar7 < (int)local_c);
  }
  return iVar14;
}


// ==== 0x6525f0 SNDVOICEI_free

/* [canon] audio med (ghidra) docs/re/sound.md */

void SNDVOICEI_free(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = DAT_00713f48 + param_1 * 0x8c;
  iVar5 = 0;
  iVar6 = -1;
  if (*(char *)(iVar3 + 0x26) == '\0') {
    *(undefined1 *)(iVar3 + 0x69) = 0;
    *(undefined1 *)(iVar3 + 0x26) = 0;
    *(undefined1 *)(iVar3 + 0x27) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = DAT_00713eec;
    return;
  }
  iVar4 = 0;
  if (0 < DAT_00713ee8) {
    pcVar2 = (char *)(DAT_00713f48 + 0x69);
    do {
      if ((((pcVar2[-0x43] == *(char *)(iVar3 + 0x26)) && (-1 < *(int *)(pcVar2 + -0x69))) &&
          (*pcVar2 != '\0')) && (iVar5 = iVar5 + 1, pcVar2[-0x42] != '\0')) {
        iVar6 = iVar4;
      }
      iVar4 = iVar4 + 1;
      pcVar2 = pcVar2 + 0x8c;
    } while (iVar4 < DAT_00713ee8);
  }
  if (iVar5 != 1) {
    iVar4 = iVar6 * 0x8c;
    cVar1 = *(char *)(iVar4 + 0x69 + DAT_00713f48);
    if (((cVar1 == '\x02') && (param_1 != iVar6)) && (iVar5 == 2)) {
      *(undefined1 *)(iVar3 + 0x69) = 0;
      *(undefined1 *)(iVar3 + 0x26) = 0;
      *(undefined1 *)(iVar3 + 0x27) = 0;
      *(undefined4 *)(iVar3 + 0x2c) = DAT_00713eec;
      *(undefined1 *)(iVar4 + 0x69 + DAT_00713f48) = 0;
      *(undefined1 *)(iVar4 + 0x26 + DAT_00713f48) = 0;
      *(undefined1 *)(iVar4 + 0x27 + DAT_00713f48) = 0;
      *(undefined4 *)(iVar4 + 0x2c + DAT_00713f48) = DAT_00713eec;
      return;
    }
    if ((cVar1 == '\x01') && (param_1 == iVar6)) {
      *(undefined1 *)(iVar4 + 0x69 + DAT_00713f48) = 2;
      return;
    }
  }
  *(undefined1 *)(iVar3 + 0x69) = 0;
  *(undefined1 *)(iVar3 + 0x26) = 0;
  *(undefined1 *)(iVar3 + 0x27) = 0;
  *(undefined4 *)(iVar3 + 0x2c) = DAT_00713eec;
  return;
}


// ==== 0x652720 SNDVOICEI_get__validate_handle____voice_index_

/* [canon] audio med (ghidra) docs/re/sound.md */

uint SNDVOICEI_get__validate_handle____voice_index_(uint param_1)

{
  uint uVar1;
  
  if ((-1 < (int)param_1) && (uVar1 = param_1 & 0xff, (int)uVar1 < (int)DAT_00713ee8)) {
    if ((*(char *)(uVar1 * 0x8c + 0x69 + DAT_00713f48) == '\0') ||
       (*(uint *)(uVar1 * 0x8c + DAT_00713f48) != param_1)) {
      uVar1 = 0xfffffff8;
    }
    return uVar1;
  }
  return 0xfffffff8;
}


// ==== 0x652770 FUN_00652770

void FUN_00652770(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0065278c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 * 0x110 + DAT_0071400c + 0x108))();
  return;
}


// ==== 0x6527a0 FUN_006527a0

uint FUN_006527a0(uint param_1)

{
  uint uVar1;
  
  uVar1 = (int)param_1 >> 8 & 3;
  param_1 = param_1 & 0xff;
  if (uVar1 == 0) {
    return (uint)*(ushort *)(&DAT_006e9ce8 + param_1 * 2);
  }
  if (uVar1 == 1) {
    return (uint)*(ushort *)(&DAT_006e9ee8 + param_1 * -2);
  }
  if (uVar1 == 2) {
    return -(uint)*(ushort *)(&DAT_006e9ce8 + param_1 * 2);
  }
  return -(uint)*(ushort *)(&DAT_006e9ee8 + param_1 * -2);
}


// ==== 0x652800 SNDbankremove

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDbankremove(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_d0;
  undefined1 local_cc [204];
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  if (param_1 == -1) {
    iVar2 = 0;
    if (DAT_00713d98 != 0) {
      do {
        SNDbankremove(iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)DAT_00713d98);
      return 0;
    }
  }
  else {
    iVar2 = FUN_006584a0(param_1);
    if (iVar2 != 0) {
      return 0xfffffff8;
    }
    FUN_0064e520();
    iVar2 = *(int *)(DAT_00713f4c + param_1 * 8);
    iVar4 = 0;
    if (0 < DAT_00713ee8) {
      iVar3 = 0;
      iVar1 = DAT_00713f48;
      do {
        if (*(short *)(iVar3 + 0x12 + iVar1) == param_1) {
          SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
                    (*(undefined4 *)(iVar3 + iVar1));
          iVar1 = DAT_00713f48;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x8c;
      } while (iVar4 < DAT_00713ee8);
    }
    iVar4 = 0;
    if (*(short *)(iVar2 + 6) != 0) {
      do {
        local_d0 = FUN_00658470(iVar2,iVar4);
        if (local_d0 != 0) {
          local_d0 = local_d0 + 4;
          do {
            iVar1 = SNDI_parsetimbre(&local_d0,local_cc);
            FUN_00658660(local_cc);
            SNDBANKI_userdatacallback(local_cc,2);
          } while (iVar1 != 0);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(ushort *)(iVar2 + 6));
    }
    *(undefined4 *)(DAT_00713f4c + param_1 * 8) = 0;
    *(undefined1 *)(DAT_00713f4c + 4 + param_1 * 8) = 0;
    SNDSYS_leavecritical();
  }
  return 0;
}


// ==== 0x652960 FUN_00652960

void FUN_00652960(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (DAT_00713c7a != '\0') {
    DAT_00713c79 = DAT_00713c79 + '\x01';
    return;
  }
  DAT_00713c7a = 0;
  puVar2 = DAT_00713c70;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    (*(code *)puVar2[2])(puVar2[3]);
    puVar2 = puVar1;
  }
  return;
}


// ==== 0x6529a0 FUN_006529a0

size_t FUN_006529a0(void *param_1,int param_2)

{
  size_t _Size;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  _Size = FUN_00652a00(param_2);
  if ((int)_Size < 0) {
    return _Size;
  }
  _memmove(param_1,*(void **)(DAT_00713f4c + param_2 * 8),_Size);
  *(void **)(DAT_00713f4c + param_2 * 8) = param_1;
  return 0;
}


// ==== 0x652a00 FUN_00652a00

int FUN_00652a00(int param_1)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = *(int *)(DAT_00713f4c + param_1 * 8);
  return *(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 8);
}


// ==== 0x652a30 SNDBANKI_userdatacallback

/* [canon] audio med (ghidra) docs/re/sound.md */

void SNDBANKI_userdatacallback(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  cVar1 = *(char *)(param_1 + 0x17);
  while ('\0' < cVar1) {
    cVar1 = *(char *)(param_1 + 0x17) + -1;
    *(char *)(param_1 + 0x17) = cVar1;
    local_14 = param_2;
    local_10 = *(undefined4 *)(param_1 + 0x34 + cVar1 * 4);
    local_c = *(undefined4 *)(param_1 + 0x44 + cVar1 * 4);
    iVar2 = 0;
    if ('\0' < DAT_00713eea) {
      do {
        (*(code *)(&DAT_00713f20)[iVar2])(&local_14);
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_00713eea);
    }
    cVar1 = *(char *)(param_1 + 0x17);
  }
  return;
}


// ==== 0x652aa0 SNDbankadd

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 SNDbankadd(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_d0;
  undefined1 local_cc [204];
  
  if (DAT_00713ee4 != '\0') {
    DAT_00713f3c = SNDbankremove;
    iVar2 = FUN_00658440();
    *param_1 = iVar2;
    piVar1 = (int *)(DAT_00713f4c + iVar2 * 8);
    iVar2 = 0;
    *piVar1 = param_2;
    *(undefined1 *)(piVar1 + 1) = 1;
    if (*(short *)(param_2 + 6) != 0) {
      do {
        local_d0 = FUN_00658470(param_2,iVar2);
        if (local_d0 != 0) {
          local_d0 = local_d0 + 4;
          do {
            iVar3 = SNDI_parsetimbre(&local_d0,local_cc);
            FUN_00658570(local_cc,param_2);
            SNDBANKI_userdatacallback(local_cc,0);
          } while (iVar3 != 0);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 6));
    }
    *(undefined1 *)(piVar1 + 1) = 0;
    return 8;
  }
  return 0xfffffff6;
}


// ==== 0x652b60 iSNDcalcvol

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void iSNDcalcvol(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x8c + DAT_00713f48;
  fVar1 = (float)(int)*(short *)(iVar2 + 0x42) *
          (float)(int)*(char *)(param_1 * 0x8c + 0x2b + DAT_00713f48) * *(float *)(iVar2 + 0x38) *
          6.200012e-05;
  *(float *)(iVar2 + 0x48) = fVar1;
  if (*(int *)(iVar2 + 0x78) != 0) {
    *(float *)(iVar2 + 0x48) =
         (float)(int)*(char *)((uint)*(byte *)(iVar2 + 0x67) + *(int *)(iVar2 + 0x78)) * fVar1 *
         0.007874016;
  }
  if (*(int *)(iVar2 + 0x70) != 0) {
    *(float *)(iVar2 + 0x48) =
         (float)(int)*(char *)(*(int *)(iVar2 + 0x70) + (int)ROUND(*(float *)(iVar2 + 0x48) * 127.0)
                              );
  }
  *(float *)(iVar2 + 0x48) = _DAT_006e9bc8 * *(float *)(iVar2 + 0x48);
  return;
}


// ==== 0x652c00 FUN_00652c00

int FUN_00652c00(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x1000;
  if (0x4af < (int)param_1) {
    uVar1 = param_1 / 0x4b0;
    param_1 = param_1 % 0x4b0;
    do {
      iVar3 = iVar3 << 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if ((int)param_1 < -0x4af) {
    iVar2 = (-param_1 - 0x4b0) / 0x4b0 + 1;
    param_1 = param_1 + iVar2 * 0x4b0;
    do {
      iVar3 = iVar3 >> 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)(param_1 * 0x369d) >> 0x10;
  if (iVar2 < -0xff) {
    iVar2 = -0xff;
  }
  else if (-1 < iVar2) {
    return (int)(((byte)(&DAT_006e9ef0)[iVar2] + 0x100) * iVar3) >> 8;
  }
  return (int)(((byte)(&DAT_006e9ff0)[iVar2] + 0x100) * iVar3) >> 9;
}


// ==== 0x652ca0 iSNDcalcpitch

/* [canon] audio high (ghidra) docs/re/sound.md */

void iSNDcalcpitch(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x8c + DAT_00713f48;
  if (*(short *)(iVar4 + 0x86) == 0) {
    iVar3 = (int)*(short *)(iVar4 + 0x84);
    if (*(short *)(iVar4 + 0x82) != 0) {
      if (*(int *)(iVar4 + 0x74) == 0) {
        cVar1 = *(char *)(iVar4 + 100);
      }
      else {
        cVar1 = *(char *)((int)*(char *)(iVar4 + 100) + *(int *)(iVar4 + 0x74));
      }
      iVar3 = iVar3 + ((cVar1 + -0x40) * (int)*(short *)(iVar4 + 0x82) >> 6);
    }
    if (*(int *)(iVar4 + 0x7c) != 0) {
      iVar3 = iVar3 + ((*(char *)((uint)*(byte *)(iVar4 + 0x68) + *(int *)(iVar4 + 0x7c)) + -0x40) *
                       (int)*(short *)(iVar4 + 0x80) >> 6);
    }
    uVar2 = FUN_00652c00(iVar3);
    *(undefined2 *)(iVar4 + 0x86) = uVar2;
  }
  *(short *)(iVar4 + 0x8a) =
       (short)((int)((uint)*(ushort *)(iVar4 + 0x88) * (uint)*(ushort *)(iVar4 + 0x86)) >> 0xc);
  return;
}


// ==== 0x652d50 FUN_00652d50

void FUN_00652d50(void)

{
  DAT_0071402c = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  return;
}


// ==== 0x652d70 FUN_00652d70

void FUN_00652d70(void)

{
  CloseHandle(DAT_0071402c);
  return;
}


// ==== 0x652d80 FUN_00652d80

void FUN_00652d80(void)

{
  WaitForSingleObject(DAT_0071402c,0xffffffff);
  return;
}


// ==== 0x652d90 FUN_00652d90

void FUN_00652d90(void)

{
  ReleaseMutex(DAT_0071402c);
  return;
}


// ==== 0x652da0 FUN_00652da0

undefined4 FUN_00652da0(void)

{
  FUN_0064c620();
  return 0;
}


// ==== 0x652db0 FUN_00652db0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00652db0(void)

{
  _DAT_00713e38 = NullUpdate_ret;
  if (DAT_00714030 == 0) {
    FUN_0063eea0(FUN_00652da0,0,1);
    DAT_00714030 = 1;
  }
  FUN_00642570(thunk_FUN_0064e8e0);
  return 0;
}


// ==== 0x652df0 FUN_00652df0

undefined4 FUN_00652df0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(short *)(iVar1 + 0x11e) = (short)param_2;
  FUN_00658cf0(*(undefined4 *)(iVar1 + 4),param_2);
  return 0;
}


// ==== 0x652e40 FUN_00652e40

undefined4 FUN_00652e40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(short *)(iVar1 + 0x118) = (short)param_2;
  *(undefined1 *)(iVar1 + 0x13) = 0;
  *(short *)(iVar1 + 0x11a) = (short)param_3;
  *(undefined1 *)(iVar1 + 0x12) = 1;
  FUN_00658d80(*(undefined4 *)(iVar1 + 4),param_2,param_3);
  return 0;
}


// ==== 0x652ea0 FUN_00652ea0

undefined4 FUN_00652ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(char *)(iVar1 + 0x115) = (char)param_3;
  FUN_00658e60(*(undefined4 *)(iVar1 + 4),param_2,param_3);
  return 0;
}


// ==== 0x652ef0 FUN_00652ef0

undefined4 FUN_00652ef0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(short *)(iVar1 + 0x124) = (short)param_2;
  FUN_00658f00(*(undefined4 *)(iVar1 + 4),param_2);
  return 0;
}


// ==== 0x652f40 FUN_00652f40

undefined4 FUN_00652f40(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(short *)(iVar1 + 0x126) = (short)param_2;
  FUN_00658f70(*(undefined4 *)(iVar1 + 4),param_2);
  return 0;
}


// ==== 0x652f90 FUN_00652f90

undefined4 FUN_00652f90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  *(char *)(iVar1 + 0x114) = (char)param_2;
  FUN_00658fe0(*(undefined4 *)(iVar1 + 4),param_2);
  return 0;
}


// ==== 0x652fd0 FUN_00652fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652fd0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  float10 fVar8;
  float10 fVar9;
  undefined1 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_10;
  undefined1 uStack_c;
  
  FUN_0064e520();
  DAT_0071404c = FUN_00650fd0((uint)DAT_00713db7 << 8);
  SNDSYS_leavecritical();
  bVar5 = DAT_00713db7;
  uVar6 = (uint)DAT_00713db7;
  iVar3 = 0;
  iVar4 = DAT_0071404c;
  if (uVar6 != 0) {
    do {
      (&DAT_00714034)[iVar3] = iVar4;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x100;
    } while (iVar3 < (int)uVar6);
  }
  uVar6 = 0;
  do {
    fVar1 = (float)((uVar6 & 0xff) << 8) * 0.005493164;
    if (bVar5 == 1) {
      *(undefined1 *)(DAT_00714034 + uVar6) = 0x7f;
      bVar5 = DAT_00713db7;
    }
    else {
      iVar4 = 0;
      if (bVar5 != 0) {
        do {
          *(undefined1 *)(uVar6 + (&DAT_00714034)[iVar4]) = 0;
          iVar4 = iVar4 + 1;
          bVar5 = DAT_00713db7;
        } while (iVar4 < (int)(uint)DAT_00713db7);
      }
      if (fVar1 < DAT_00713cc8 == (fVar1 == DAT_00713cc8)) {
        uVar7 = (uint)bVar5;
        if (fVar1 < (float)(&DAT_00713cc4)[uVar7]) {
          iVar4 = 0;
          if (uVar7 != 0) {
            do {
              if (((&DAT_00713cc8)[iVar4] <= fVar1) &&
                 (fVar1 < (&DAT_00713ccc)[iVar4] != (fVar1 == (&DAT_00713ccc)[iVar4]))) {
                fVar2 = ((fVar1 * 0.017453294 - (&DAT_00713ccc)[iVar4] * 0.017453294) /
                        ((&DAT_00713cc8)[iVar4] * 0.017453294 - (&DAT_00713ccc)[iVar4] * 0.017453294
                        )) * 1.5707964;
                fVar8 = (float10)SNDI_sin(fVar2);
                fVar9 = (float10)FUN_006590b0(fVar2);
                fVar2 = (float)fVar9 * K_BLUR_MIN_T;
                uStack_10 = (undefined1)(int)ROUND((float)fVar8 * K_BLUR_MIN_T);
                *(undefined1 *)(uVar6 + (&DAT_00714034)[iVar4]) = uStack_10;
                uStack_c = (undefined1)(int)ROUND(fVar2);
                *(undefined1 *)(uVar6 + (&DAT_00714038)[iVar4]) = uStack_c;
                bVar5 = DAT_00713db7;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)(uint)bVar5);
          }
        }
        else {
          fVar2 = (360.0 - (float)(&DAT_00713cc4)[uVar7]) * -1.0 * 0.017453294;
          fVar1 = (((360.0 - fVar1) * -1.0 * 0.017453294 - fVar2) /
                  (DAT_00713cc8 * 0.017453294 - fVar2)) * 1.5707964;
          fVar8 = (float10)SNDI_sin(fVar1);
          fVar9 = (float10)FUN_006590b0(fVar1);
          fVar1 = (float)fVar9 * K_BLUR_MIN_T;
          uStack_1c = (undefined1)(int)ROUND((float)fVar8 * K_BLUR_MIN_T);
          *(undefined1 *)(DAT_00714034 + uVar6) = uStack_1c;
          uStack_18 = (undefined1)(int)ROUND(fVar1);
          *(undefined1 *)(uVar6 + (&DAT_00714030)[DAT_00713db7]) = uStack_18;
          bVar5 = DAT_00713db7;
        }
      }
      else if (bVar5 < 5) {
        fVar2 = (360.0 - (float)(&DAT_00713cc4)[bVar5]) * -1.0 * 0.017453294;
        fVar1 = ((fVar1 * 0.017453294 - fVar2) / (DAT_00713cc8 * 0.017453294 - fVar2)) * 1.5707964;
        fVar8 = (float10)SNDI_sin(fVar1);
        fVar9 = (float10)FUN_006590b0(fVar1);
        uStack_24 = (undefined1)(int)ROUND((float)fVar8 * K_BLUR_MIN_T);
        fVar1 = (float)fVar9 * K_BLUR_MIN_T;
        *(undefined1 *)(DAT_00714034 + uVar6) = uStack_24;
        uStack_20 = (undefined1)(int)ROUND(fVar1);
        *(undefined1 *)(uVar6 + (&DAT_00714030)[DAT_00713db7]) = uStack_20;
        bVar5 = DAT_00713db7;
      }
      else {
        fVar1 = ((fVar1 * 0.017453294 - DAT_00713ccc * 0.017453294) /
                (DAT_00713cc8 * 0.017453294 - DAT_00713ccc * 0.017453294)) * 1.5707964;
        fVar8 = (float10)SNDI_sin(fVar1);
        fVar9 = (float10)FUN_006590b0(fVar1);
        uStack_2c = (undefined1)(int)ROUND((float)fVar8 * K_BLUR_MIN_T);
        fVar1 = (float)fVar9 * K_BLUR_MIN_T;
        *(undefined1 *)(DAT_00714034 + uVar6) = uStack_2c;
        uStack_28 = (undefined1)(int)ROUND(fVar1);
        *(undefined1 *)(DAT_00714038 + uVar6) = uStack_28;
        bVar5 = DAT_00713db7;
      }
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0x100);
  return;
}


// ==== 0x6533c0 FUN_006533c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006533c0(uint param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_00713db7 != 0) {
    pfVar1 = param_2;
    do {
      iVar2 = iVar2 + 1;
      *pfVar1 = (float)*(byte *)(*(int *)(((int)&DAT_00714034 - (int)param_2) + (int)pfVar1) +
                                (param_1 >> 8 & 0xff)) * _K_BLUR_MIN_T;
      pfVar1 = pfVar1 + 1;
    } while (iVar2 < (int)(uint)DAT_00713db7);
  }
  if (DAT_00713ce0 == 3) {
    param_2[5] = 0.0;
  }
  return;
}


// ==== 0x653420 FUN_00653420

void FUN_00653420(void)

{
  FUN_0064e520();
  FUN_006510d0(DAT_0071404c);
  SNDSYS_leavecritical();
  return;
}


// ==== 0x653440 FUN_00653440

undefined4
FUN_00653440(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
            undefined4 param_6,int param_7,int param_8,int param_9)

{
  undefined2 uVar1;
  LPVOID lpAddress;
  int iVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  uint local_c;
  undefined4 local_8;
  
  puVar4 = (undefined4 *)0x0;
  lpAddress = VirtualAlloc((LPVOID)0x0,param_7 * 4 + 20000,0x3000,4);
  local_c = (uint)DAT_00713eeb;
  local_28 = param_2;
  local_2c = param_1;
  local_20 = param_7;
  local_24 = 1;
  local_1c = param_4;
  local_18 = param_5;
  local_8 = param_6;
  if (param_3 == 8) {
    FUN_0064e520();
    puVar4 = (undefined4 *)FUN_00650fd0(0x2c);
    local_14 = 1;
    puVar4[1] = 0;
    FUN_006598a0(puVar4,&local_2c);
    SNDSYS_leavecritical();
    (*(code *)*puVar4)(puVar4,param_7,0,lpAddress,0);
  }
  else if (param_3 == 9) {
    FUN_0064e520();
    puVar4 = (undefined4 *)FUN_00650fd0(0x2c);
    local_14 = 0;
    puVar4[1] = 0;
    FUN_006598a0(puVar4,&local_2c);
    SNDSYS_leavecritical();
    (*(code *)*puVar4)(puVar4,param_7,0,lpAddress,0);
  }
  else if (param_3 == 10) {
    FUN_0064e520();
    if (param_5 < 1) {
      puVar4 = (undefined4 *)FUN_00650fd0(0x2c);
      puVar4[1] = 0;
      FUN_006594e0(puVar4,&local_2c);
    }
    else {
      puVar4 = (undefined4 *)FUN_00650fd0(0x54);
      puVar4[1] = 0;
      FUN_00659740(puVar4,&local_2c);
    }
    lpAddress = (LPVOID)((int)lpAddress + 8);
    SNDSYS_leavecritical();
    (*(code *)*puVar4)(puVar4,param_7,0,lpAddress,0);
  }
  else if ((param_3 == 4) || (param_3 == 0x16)) {
    FUN_0064e520();
    if (param_5 < 1) {
      puVar4 = (undefined4 *)FUN_00650fd0(0x2c);
      puVar4[1] = 0;
      FUN_00659250(puVar4,&local_2c);
    }
    else {
      puVar4 = (undefined4 *)FUN_00650fd0(0x30);
      puVar4[1] = 0;
      FUN_006593b0(puVar4,&local_2c);
    }
    SNDSYS_leavecritical();
    (*(code *)*puVar4)(puVar4,param_7,0,lpAddress,0);
  }
  else if (param_3 == 0x17) {
    FUN_0064e520();
    if (param_5 < 1) {
      puVar4 = (undefined4 *)FUN_00650fd0(0x24);
      puVar4[1] = 0;
      *(undefined1 *)((int)puVar4 + 0x1a) = 0;
      (*DAT_007164bc)(puVar4,&local_2c);
    }
    else {
      puVar4 = (undefined4 *)FUN_00650fd0(0x38);
      puVar4[1] = 0;
      *(undefined1 *)((int)puVar4 + 0x1a) = 0;
      (*DAT_007164c0)(puVar4,&local_2c);
    }
    SNDSYS_leavecritical();
    iVar5 = 0;
    pvVar3 = lpAddress;
    if (0 < param_7) {
      do {
        iVar2 = 0x800;
        if (iVar5 < 0x801) {
          iVar2 = iVar5;
        }
        (*(code *)*puVar4)(puVar4,iVar2,0,pvVar3,0);
        iVar5 = iVar5 + 0x800;
        pvVar3 = (LPVOID)((int)pvVar3 + 0x2000);
      } while (iVar5 < param_7);
    }
  }
  FUN_0064e520();
  if ((code *)puVar4[1] != (code *)0x0) {
    (*(code *)puVar4[1])(puVar4);
  }
  FUN_006510d0(puVar4);
  SNDSYS_leavecritical();
  if (0 < param_5) {
    lpAddress = (LPVOID)((int)lpAddress + param_4 * 4);
    param_7 = (param_5 - param_4) + 1;
  }
  if ((param_9 == 8) && (iVar5 = 0, 0 < param_7)) {
    do {
      if (*(float *)((int)lpAddress + iVar5 * 4) <= 32767.0) {
        if (-32768.0 <= *(float *)((int)lpAddress + iVar5 * 4)) {
          uVar1 = _ftol_nocw();
          *(undefined2 *)(param_8 + iVar5 * 2) = uVar1;
        }
        else {
          *(undefined2 *)(param_8 + iVar5 * 2) = 0x8000;
        }
      }
      else {
        *(undefined2 *)(param_8 + iVar5 * 2) = 0x7fff;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_7);
  }
  if (param_3 == 10) {
    lpAddress = (LPVOID)((int)lpAddress + -8);
  }
  VirtualFree(lpAddress,0,0x8000);
  return 0;
}


// ==== 0x653760 FUN_00653760

undefined4 FUN_00653760(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStack_4c [4];
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined2 local_38;
  undefined2 local_36;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined2 *local_14;
  
  iVar5 = param_1 * 0x20;
  local_40 = *(int *)(&DAT_0071408c + iVar5);
  if (local_40 == 0) {
    return 0;
  }
  local_44 = *(undefined4 *)(&DAT_00714090 + iVar5);
  local_48 = *(int *)(&DAT_00714098 + iVar5);
  iVar3 = 0x10;
  if ((&DAT_007140ab)[iVar5] != '\b') {
    iVar3 = param_1;
  }
  iVar2 = local_48;
  if (0 < *(int *)(&DAT_007140a0 + iVar5)) {
    iVar2 = (*(int *)(&DAT_007140a0 + iVar5) - *(int *)(&DAT_0071409c + iVar5)) + 1;
  }
  iVar4 = iVar3 >> 3;
  iVar2 = iVar4 * iVar2;
  FUN_00654cd0(&local_24,0x24);
  local_38 = 1;
  local_36 = 1;
  local_34 = (uint)*(ushort *)(&DAT_007140a8 + iVar5);
  local_30 = local_34 * iVar4;
  local_14 = &local_38;
  puVar1 = (undefined4 *)(&DAT_00714094 + iVar5);
  local_24 = 0x24;
  local_20 = 0x480b0;
  local_2c = CONCAT22((short)iVar3,(short)iVar4);
  local_28 = 0;
  local_1c = iVar2;
  iVar3 = (**(code **)(*DAT_00714068 + 0xc))(DAT_00714068,&local_24,puVar1,0);
  if (iVar3 == 0) {
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    puVar6 = auStack_4c;
    iVar3 = (**(code **)(*(int *)*puVar1 + 0x2c))
                      ((int *)*puVar1,0,iVar2,&stack0xffffffa4,puVar6,0,0,0);
    if (iVar3 == 0) {
      FUN_00653440(uVar9,uVar8,(int)(char)(&DAT_007140aa)[iVar5],
                   *(undefined4 *)(&DAT_0071409c + iVar5),*(undefined4 *)(&DAT_007140a0 + iVar5),
                   *(undefined4 *)(&DAT_007140a4 + iVar5),uVar7,puVar6,
                   (int)(char)(&DAT_007140ab)[iVar5]);
      iVar5 = (**(code **)(*(int *)*puVar1 + 0x4c))((int *)*puVar1,puVar6,iVar2,0,0);
      if (iVar5 != 0) {
        return 0;
      }
    }
    return local_2c;
  }
  return 0;
}


// ==== 0x6538b0 FUN_006538b0

void FUN_006538b0(ushort param_1,uint param_2)

{
  int iVar1;
  undefined2 *puStack_54;
  int iStack_2c;
  undefined2 local_28;
  ushort local_26;
  uint local_24;
  int local_20;
  ushort local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_1c = param_1 * 2;
  DAT_00714054 = (undefined1)local_1c;
  local_20 = local_1c * param_2;
  local_24 = param_2;
  local_1a = 0x10;
  local_16 = 0x10;
  local_10 = 1;
  local_c = 0x100000;
  local_26 = param_1;
  local_28 = 0xfffe;
  local_18 = 0x16;
  local_8 = 0xaa000080;
  local_4 = 0x719b3800;
  if (param_1 == 6) {
    local_14 = 0x3f;
  }
  else if (param_1 == 4) {
    local_14 = 0x33;
  }
  else if (param_1 < 3) {
    local_28 = 1;
    local_18 = 0;
  }
  puStack_54 = &local_28;
  iVar1 = (**(code **)(*DAT_0071406c + 0x38))(DAT_0071406c);
  if (-1 < iVar1) {
    if (DAT_00714070 != (int *)0x0) {
      (**(code **)(*DAT_00714070 + 8))(DAT_00714070);
      DAT_00714070 = (int *)0x0;
    }
    FUN_00654cd0(&puStack_54,0x24);
    DAT_0071407c = (uint)(iStack_2c * 500) / 1000 & 0xfffffff0;
    DAT_00714050 = (int)DAT_0071407c >> 1;
    DAT_00714078 = (local_24 & 0xffff) * DAT_0071407c;
    puStack_54 = (undefined2 *)0x24;
    DAT_00714084 = 0;
    DAT_00714088 = 0;
    DAT_00714080 = 0;
    (**(code **)(*DAT_00714068 + 0xc))(DAT_00714068,&puStack_54,&DAT_00714070,0);
  }
  return;
}


// ==== 0x653a20 FUN_00653a20

undefined4 FUN_00653a20(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fStack_3c;
  undefined4 *puStack_38;
  float fStack_34;
  int *piStack_30;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int *piStack_1c;
  undefined4 uStack_18;
  int local_c [3];
  
  local_c[1] = 0x3f800000;
  local_c[0] = 9;
  DAT_007160b8 = param_1;
  DAT_007160bc = param_2;
  DAT_007160c0 = param_3;
  if (DAT_00714075 == '\0') {
    return 0xffffffff;
  }
  if ((param_1 == 0) || (param_1 == 1)) {
    param_2 = -1;
    param_3 = -1;
    local_c[1] = 0;
  }
  else if (param_1 != 2) {
    if (param_1 == 3) {
      local_c[0] = 0xb;
    }
    else if (param_1 == 5) {
      local_c[0] = 4;
    }
    else if (param_1 == 10) {
      local_c[0] = 2;
    }
    else if (param_1 == 0xd) {
      local_c[0] = 0x13;
    }
    else if (param_1 == 0xf) {
      local_c[0] = param_1;
    }
    else if (param_1 == 0x11) {
      local_c[0] = param_1;
    }
    else if (param_1 == 0x14) {
      local_c[0] = 0x10;
    }
    else if (param_1 == 0x17) {
      local_c[0] = 0x14;
    }
    else if (param_1 == 0x19) {
      local_c[0] = 0xc;
    }
    else if (param_1 == 0x1b) {
      local_c[0] = 0xe;
    }
    else if (param_1 == 0x1e) {
      local_c[0] = 0;
    }
    else if (param_1 == 0x20) {
      local_c[0] = 5;
    }
    else if (param_1 == 0x21) {
      local_c[0] = 3;
    }
    else if (param_1 == 0x22) {
      local_c[0] = 0x12;
    }
    else if (param_1 == 0x23) {
      local_c[0] = 0x15;
    }
    else if (param_1 == 0x24) {
      local_c[0] = 8;
    }
    else if (param_1 == 0x25) {
      local_c[0] = 0xd;
    }
    else if (param_1 == 0x26) {
      local_c[0] = 6;
    }
    else if (param_1 == 0x28) {
      local_c[0] = 7;
    }
    else if (param_1 == 0x32) {
      local_c[0] = 9;
    }
    else if (param_1 == 0x37) {
      local_c[0] = 10;
    }
    else if (param_1 == 0x3c) {
      local_c[0] = 0x16;
    }
    else if (param_1 == 0x46) {
      local_c[0] = 0x18;
    }
    else if (param_1 == 0x49) {
      local_c[0] = 0x17;
    }
    else if (param_1 == 0x4c) {
      local_c[0] = 0x19;
    }
    else if ((99 < param_1) && (param_1 < 0x79)) {
      local_c[0] = 10;
    }
    goto LAB_00653c4d;
  }
  local_c[0] = 1;
LAB_00653c4d:
  uStack_18 = 4;
  piStack_1c = local_c;
  uStack_20 = 0;
  uStack_24 = 0;
  uStack_28 = 1;
  puStack_2c = &DAT_006aab58;
  piStack_30 = DAT_007160b0;
  fStack_34 = 9.297058e-39;
  iVar1 = (**(code **)(*DAT_007160b0 + 0x10))();
  if (iVar1 == 0) {
    fStack_34 = 5.60519e-45;
    puStack_38 = &uStack_24;
    fStack_3c = 0.0;
    iVar1 = (**(code **)(*DAT_007160b0 + 0x10))(DAT_007160b0,&DAT_006aab58,2,0);
    if (iVar1 == 0) {
      if (param_2 != -1) {
        fStack_34 = (float)(int)piStack_30 * 5.9604645e-06;
        iVar1 = (**(code **)(*DAT_007160b0 + 0x10))(DAT_007160b0,&DAT_006aab58,3,0,0,&fStack_34,4);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
      }
      if (param_3 != -1) {
        fStack_3c = (float)(int)puStack_2c * 5.960465e-08;
        iVar1 = (**(code **)(*DAT_007160b0 + 0x10))(DAT_007160b0,&DAT_006aab58,4,0,0,&fStack_3c,4);
        if (iVar1 != 0) {
          return 0xffffffff;
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}


// ==== 0x653d10 FUN_00653d10

void FUN_00653d10(void)

{
  if (DAT_007160b0 != (int *)0x0) {
    (**(code **)(*DAT_007160b0 + 8))(DAT_007160b0);
    DAT_007160b0 = (int *)0x0;
  }
  if (DAT_007160b4 != (int *)0x0) {
    (**(code **)(*DAT_007160b4 + 8))(DAT_007160b4);
    DAT_007160b4 = (int *)0x0;
  }
  DAT_00714075 = 0;
  return;
}


// ==== 0x653d50 FUN_00653d50

undefined4 FUN_00653d50(void)

{
  if (DAT_007160b0 != (int *)0x0) {
    (**(code **)(*DAT_007160b0 + 8))(DAT_007160b0);
    DAT_007160b0 = (int *)0x0;
  }
  if (DAT_007160b4 != (int *)0x0) {
    (**(code **)(*DAT_007160b4 + 8))(DAT_007160b4);
    DAT_007160b4 = (int *)0x0;
  }
  DAT_00714075 = 0;
  if (DAT_00714068 != (int *)0x0) {
    (**(code **)(*DAT_00714068 + 8))(DAT_00714068);
    DAT_00714068 = (int *)0x0;
  }
  FUN_00656510();
  return 0;
}


// ==== 0x653db0 FUN_00653db0

undefined4 FUN_00653db0(int param_1)

{
  if (DAT_00714068 != 0) {
    (**(code **)(**(int **)(&DAT_00714094 + param_1 * 0x20) + 8))
              (*(int **)(&DAT_00714094 + param_1 * 0x20));
  }
  *(undefined4 *)(&DAT_0071408c + param_1 * 0x20) = 0;
  return 0;
}


// ==== 0x653de0 FUN_00653de0

int FUN_00653de0(void)

{
  int iVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  if (DAT_00714068 != 0) {
    piVar2 = DAT_00714070;
    iVar1 = (**(code **)(*DAT_00714070 + 0x10))(DAT_00714070,local_4,0);
    if (iVar1 == 0) {
      iVar1 = DAT_00714060 - ((uint)piVar2 >> 1) / ((uint)DAT_00713db8 + (uint)DAT_00713db7);
      if (iVar1 < 0) {
        iVar1 = iVar1 + DAT_0071407c;
      }
      return (iVar1 * 1000) / (int)(uint)DAT_00713d9a;
    }
  }
  return 0;
}


// ==== 0x653e50 FUN_00653e50

void FUN_00653e50(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  DAT_007160cc = DAT_007160cc + 1;
  if (((DAT_007160cc & 3) == 0) && (uVar4 = (uint)DAT_00713d9e, (int)uVar4 < (int)DAT_00713ee8)) {
    iVar3 = uVar4 * 0x110;
    do {
      pcVar1 = *(code **)(iVar3 + 0x10c + DAT_0071400c);
      if ((pcVar1 != (code *)0x0) && (iVar2 = (*pcVar1)(iVar3 + 0x2c + DAT_0071400c), iVar2 != 0)) {
        FUN_00651f30(uVar4);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x110;
    } while ((int)uVar4 < (int)DAT_00713ee8);
  }
  return;
}


// ==== 0x653ec0 FUN_00653ec0

void FUN_00653ec0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_8;
  
  local_8 = (uint)DAT_00713d9e;
  if ((int)local_8 < (int)DAT_00713ee8) {
    iVar7 = local_8 * 0x110;
    iVar6 = DAT_0071400c;
    do {
      iVar1 = iVar6 + 0xe4;
      if (*(int *)(iVar6 + 0xe4 + iVar7) != 0) {
        iVar2 = iVar6 + 0x104;
        iVar3 = iVar6 + 0xdc;
        do {
          iVar5 = (**(code **)(iVar2 + iVar7))(*(undefined4 *)(iVar3 + iVar7));
          iVar6 = 0x100;
          if (iVar5 < 0x101) {
            iVar6 = iVar5;
          }
          puVar4 = *(undefined4 **)(iVar1 + iVar7);
          iVar6 = (*(code *)*puVar4)(puVar4,iVar6,DAT_00714004,DAT_00714008,0);
          if (iVar6 < 0) {
            FUN_00651f30(local_8);
            iVar6 = DAT_0071400c;
            break;
          }
          FUN_00655880();
          iVar6 = DAT_0071400c;
        } while (iVar5 != 0x100 && -1 < iVar5 + -0x100);
      }
      local_8 = local_8 + 1;
      iVar7 = iVar7 + 0x110;
    } while ((int)local_8 < (int)DAT_00713ee8);
  }
  return;
}


// ==== 0x653fa0 FUN_00653fa0

int FUN_00653fa0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00714010 != 0) {
    do {
      if (*(int *)(DAT_00714014 + iVar1 * 8) == 0) {
        *(undefined4 *)(DAT_00714014 + iVar1 * 8) = param_1;
        return DAT_00714014 + iVar1 * 8;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)DAT_00714010);
  }
  return 0;
}


// ==== 0x653fe0 FUN_00653fe0

void FUN_00653fe0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00714010 != 0) {
    while (*(int *)(DAT_00714014 + iVar1 * 8) != param_1) {
      iVar1 = iVar1 + 1;
      if ((int)(uint)DAT_00714010 <= iVar1) {
        return;
      }
    }
    *(undefined4 *)(DAT_00714014 + iVar1 * 8) = 0;
  }
  return;
}


// ==== 0x654010 FUN_00654010

int FUN_00654010(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((DAT_00714014 != 0) && (DAT_00714010 != 0)) {
    do {
      if (*(int *)(DAT_00714014 + iVar1 * 8) == param_1) {
        return DAT_00714014 + iVar1 * 8;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)DAT_00714010);
  }
  return 0;
}


// ==== 0x654050 FUN_00654050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00654050(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = (int *)*param_1;
  for (uVar2 = param_2; 0 < (int)uVar2; uVar2 = uVar2 - uVar1) {
    if ((int)DAT_00714080 < 1) {
      DAT_00714084 = DAT_00714084 + 1;
      SNDSYSI_100hzserver__map_name_SNDvol_is_wrong_();
      _DAT_006ea004 = _DAT_00713ff8 + _DAT_006ea004;
      DAT_00713ca4 = (uint)ROUND(_DAT_006ea004);
      if (30.0 < _DAT_006ea004) {
        _DAT_006ea004 = _DAT_006ea004 - 30.0;
      }
      param_2 = DAT_00713ca4;
      FUN_0064e2f0();
      DAT_00714080 = (int)((uint)DAT_00713d9a * DAT_00714084) / 100 - DAT_00714088 & 0xffffff0;
      DAT_00714088 = DAT_00714088 + DAT_00714080;
      if (30000 < DAT_00714084) {
        DAT_00714084 = 0;
        DAT_00714088 = 0;
      }
    }
    uVar1 = DAT_00714080;
    if ((int)uVar2 <= (int)DAT_00714080) {
      uVar1 = uVar2;
    }
    DAT_00714080 = DAT_00714080 - uVar1;
    FUN_00656d70(&param_1,uVar1);
    FUN_00655880();
    param_1 = (int *)((int)param_1 + ((uint)DAT_00713db8 + (uint)DAT_00713db7) * uVar1 * 2);
  }
  return;
}


// ==== 0x654180 FUN_00654180

undefined4 FUN_00654180(void)

{
  int *piVar1;
  
  DAT_00713ff1 = 0;
  while (DAT_00713ff0 != '\0') {
    Sleep(0);
  }
  FUN_00653d50();
  FUN_0064e520();
  FUN_006510d0(DAT_0071400c);
  if (DAT_00714014 != 0) {
    FUN_006510d0(DAT_00714014);
  }
  if (DAT_00713ff4 != '\0') {
    piVar1 = &DAT_00713ffc;
    do {
      if (*piVar1 != 0) {
        FUN_006510d0(*piVar1);
      }
      piVar1 = piVar1 + 1;
    } while ((int)piVar1 < 0x714004);
  }
  SNDSYS_leavecritical();
  return 0;
}


// ==== 0x654210 FUN_00654210

void FUN_00654210(void)

{
  int iVar1;
  undefined *puStack_58;
  undefined4 *puStack_54;
  int *piStack_50;
  undefined4 *puStack_4c;
  undefined4 *puStack_48;
  int *piStack_44;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined2 *puStack_14;
  
  if (DAT_007160b0 != (int *)0x0) {
    piStack_44 = DAT_007160b0;
    puStack_48 = (undefined4 *)0x654225;
    (**(code **)(*DAT_007160b0 + 8))();
    DAT_007160b0 = (int *)0x0;
  }
  if (DAT_007160b4 != (int *)0x0) {
    piStack_44 = DAT_007160b4;
    puStack_48 = (undefined4 *)0x65423a;
    (**(code **)(*DAT_007160b4 + 8))();
    DAT_007160b4 = (int *)0x0;
  }
  puStack_48 = &uStack_24;
  piStack_44 = (int *)0x24;
  DAT_00714075 = '\0';
  puStack_4c = (undefined4 *)0x654252;
  FUN_00654cd0();
  piStack_44 = (int *)0x0;
  puStack_14 = &uStack_38;
  puStack_48 = &DAT_007160b4;
  uStack_38 = 1;
  uStack_36 = 1;
  puStack_4c = &uStack_24;
  uStack_34 = 0x2b11;
  uStack_30 = 0x5622;
  uStack_2c = 2;
  uStack_2a = 0x10;
  uStack_28 = 0;
  uStack_24 = 0x24;
  uStack_20 = 0x8014;
  uStack_1c = 0x80;
  piStack_50 = DAT_00714068;
  puStack_54 = (undefined4 *)0x6542bd;
  iVar1 = (**(code **)(*DAT_00714068 + 0xc))();
  if (iVar1 == 0) {
    puStack_54 = &DAT_007160b0;
    puStack_58 = &DAT_006a6e30;
    iVar1 = (**(code **)*DAT_007160b4)(DAT_007160b4);
    if (iVar1 == 0) {
      if (iStack_18 != 0) {
        iVar1 = (**(code **)(*DAT_007160b0 + 0x14))(DAT_007160b0,&DAT_006aab58,0,&puStack_58);
        if ((iVar1 == 0) && (((byte)puStack_58 & 3) == 3)) {
          DAT_00714075 = 1;
          return;
        }
      }
      if (DAT_00714075 == '\0') {
        FUN_00653d10();
        return;
      }
    }
    else {
      (**(code **)(*DAT_007160b4 + 8))(DAT_007160b4);
      DAT_007160b4 = (int *)0x0;
    }
  }
  return;
}


// ==== 0x654340 FUN_00654340

int FUN_00654340(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puStack_60;
  undefined4 *puStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  HWND pHStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 *puStack_44;
  uint *puStack_40;
  uint local_30;
  undefined1 local_2c;
  byte local_2b;
  undefined1 local_2a;
  code *local_28;
  
  local_2c = DAT_00713d9e;
  local_2b = DAT_00713db8 + DAT_00713db7;
  local_30 = (uint)DAT_00713d9a;
  puStack_40 = &local_30;
  local_2a = 1 < local_2b;
  local_28 = SNDVOICEI_free;
  puStack_44 = (undefined4 *)0x654387;
  FUN_006568d0();
  puStack_40 = (uint *)0x0;
  puStack_44 = &DAT_00714068;
  uStack_48 = 0;
  DAT_0071406c = 0;
  DAT_00714070 = (int *)0x0;
  uStack_4c = 0x6543ac;
  iVar1 = Ordinal_1();
  if (iVar1 != 0) {
    if (iVar1 == -0x7787fff6) {
      DAT_00714068 = (int *)0x0;
      uStack_4c = 0x6543cb;
      FUN_00653d50();
      return -0x12;
    }
    DAT_00714068 = (int *)0x0;
    uStack_4c = 0x6543f2;
    FUN_00653d50();
    return ((iVar1 != -0x7787ff88) - 1 & 0xfffffff7) - 1;
  }
  uStack_4c = 0x6543ff;
  pHStack_50 = GetForegroundWindow();
  if (pHStack_50 == (HWND)0x0) {
    uStack_4c = 0x654409;
    pHStack_50 = GetDesktopWindow();
  }
  uStack_4c = 2;
  piStack_54 = DAT_00714068;
  uStack_58 = 0x654418;
  (**(code **)(*DAT_00714068 + 0x18))();
  puStack_5c = (undefined4 *)&stack0xffffffc4;
  uStack_58 = 0x24;
  puStack_60 = (undefined1 *)0x654424;
  FUN_00654cd0();
  uStack_58 = 0;
  puStack_5c = &DAT_0071406c;
  puStack_60 = &stack0xffffffc4;
  iVar1 = (**(code **)(*DAT_00714068 + 0xc))(DAT_00714068);
  if ((-1 < iVar1) &&
     (iVar1 = FUN_006538b0((uint)DAT_00713db8 + (uint)DAT_00713db7,DAT_00713d9a), -1 < iVar1)) {
    if (DAT_00713ff3 != '\0') {
      FUN_00654210(DAT_00713dae);
      FUN_00653a20(DAT_007160b8,DAT_007160bc,DAT_007160c0);
    }
    uVar2 = 0;
    iVar1 = (**(code **)(*DAT_00714070 + 0x2c))
                      (DAT_00714070,0,DAT_00714078,&puStack_60,&puStack_5c,0,0,0);
    if (-1 < iVar1) {
      FUN_00654cd0(uVar2,DAT_00714078);
      (**(code **)(*DAT_00714070 + 0x4c))(DAT_00714070,uVar2,DAT_00714078,0,0);
    }
    iVar1 = (**(code **)(*DAT_00714070 + 0x30))(DAT_00714070,0,0,1);
    if (-1 < iVar1) {
      return 0;
    }
  }
  FUN_00653d50();
  return -1;
}


// ==== 0x654540 FUN_00654540

int FUN_00654540(undefined1 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00714068 != 0) {
    iVar2 = 1;
    piVar1 = &DAT_007140ac;
    while (*piVar1 != 0) {
      piVar1 = piVar1 + 8;
      iVar2 = iVar2 + 1;
      if (0x71608b < (int)piVar1) {
        return 0;
      }
    }
    if (0 < iVar2) {
      iVar3 = iVar2 * 0x20;
      (&DAT_007140aa)[iVar3] = param_1;
      *(undefined2 *)(&DAT_007140a8 + iVar3) = param_2;
      *(undefined4 *)(&DAT_00714098 + iVar3) = param_3;
      *(undefined4 *)(&DAT_0071409c + iVar3) = param_4;
      *(undefined4 *)(&DAT_007140a0 + iVar3) = param_5;
      *(undefined4 *)(&DAT_007140a4 + iVar3) = param_6;
      (&DAT_007140ab)[iVar3] = 8;
      *(undefined4 *)(&DAT_0071408c + iVar3) = param_7;
      *(undefined4 *)(&DAT_00714090 + iVar3) = param_8;
      iVar2 = FUN_00653760(iVar2);
      if (iVar2 < 1) {
        *(undefined4 *)(&DAT_0071408c + iVar3) = 0;
      }
      return iVar2;
    }
  }
  return 0;
}


// ==== 0x6545d0 FUN_006545d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006545d0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_2c;
  int iStack_1c;
  uint uStack_18;
  undefined1 local_10 [16];
  
  piVar2 = DAT_00714070;
  if (DAT_00714068 != 0) {
    puStack_2c = local_10;
    (**(code **)(*DAT_00714070 + 0x24))();
    if ((((byte)uStack_18 & 2) == 0) && (DAT_007160d0 < 0x65)) {
      if (((byte)uStack_18 & 1) == 0) {
        uStack_44 = 0x654849;
        (**(code **)(*DAT_00714070 + 0x30))();
        DAT_007160d0 = 0;
        return;
      }
      iVar3 = (**(code **)(*DAT_00714070 + 0x10))();
      if (iVar3 == 0) {
        uVar7 = (uint)DAT_00714054;
        iVar3 = _ftol_nocw();
        uVar7 = iVar3 + (uint)piVar2 / uVar7 & 0xffffff0;
        if (DAT_0071407c <= (int)uVar7) {
          uVar7 = uVar7 - DAT_0071407c;
        }
        iStack_1c = uVar7 - DAT_00714060;
        if (((-1 < iStack_1c) || (iStack_1c <= -DAT_00714050)) && (iStack_1c <= DAT_00714050)) {
          if (iStack_1c < 0) {
            iStack_1c = DAT_0071407c - DAT_00714060;
            uStack_18 = uVar7;
          }
          else {
            uStack_18 = 0;
          }
          iVar8 = 0;
          iVar3 = DAT_00714060;
          do {
            iVar1 = (&iStack_1c)[iVar8];
            if (iVar1 != 0) {
              uStack_44 = 0;
              uStack_48 = 0;
              uStack_4c = 0;
              (**(code **)(*DAT_00714070 + 0x2c))
                        (DAT_00714070,((uint)DAT_00713db8 + (uint)DAT_00713db7) * iVar3 * 2,
                         ((uint)DAT_00713db8 + (uint)DAT_00713db7) * iVar1 * 2,&puStack_2c,
                         &stack0xffffffe0);
              FUN_00654050(&uStack_4c,iVar1);
              (**(code **)(*DAT_00714070 + 0x4c))
                        (DAT_00714070,uStack_4c,
                         ((uint)DAT_00713db8 + (uint)DAT_00713db7) * iVar1 * 2,0,0);
              iVar3 = 0;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < 2);
          uStack_44 = 0x654760;
          DVar4 = timeGetTime();
          uVar5 = DVar4 - _DAT_00714058;
          uVar6 = DAT_006ea008;
          if ((uVar5 < 0x12d) && (uVar6 = uVar5, DAT_006ea008 < uVar5)) {
            DAT_006ea008 = uVar5;
          }
          if (DAT_006e9ff4 < uVar6) {
            DAT_006e9ff4 = (ushort)uVar6;
            _DAT_006ea000 = (float)(int)uVar6;
            if ((int)uVar6 < 0) {
              _DAT_006ea000 = _DAT_006ea000 + 4.2949673e+09;
            }
          }
          DAT_006e9ff8 = DAT_006e9ff8 + -1;
          if (DAT_006e9ff8 < 1) {
            if (DAT_006ea008 < DAT_006e9ff4) {
              DAT_006e9ff4 = (ushort)DAT_006ea008;
            }
            DAT_006e9ff8 = 3000;
            _DAT_006ea000 = (float)DAT_006e9ff4;
            DAT_006ea008 = 10;
            if (_DAT_006ea000 < 10.0) {
              _DAT_006ea000 = 10.0;
            }
          }
          if (DAT_006e9ffc < _DAT_006ea000) {
            _DAT_006ea000 = DAT_006e9ffc;
          }
          DAT_00714060 = uVar7;
          return;
        }
      }
    }
    else {
      (**(code **)(*DAT_00714070 + 0x50))();
      DAT_007160d0 = 0;
    }
  }
  return;
}


// ==== 0x654880 FUN_00654880

int FUN_00654880(undefined1 *param_1,undefined4 *param_2)

{
  int iVar1;
  HWND pHVar2;
  int iVar3;
  uint uVar4;
  undefined1 *unaff_retaddr;
  undefined4 uStack_90;
  undefined4 auStack_78 [4];
  byte bStack_68;
  uint uStack_60;
  undefined4 uStack_40;
  undefined4 *puStack_8;
  int *piStack_4;
  
  uStack_90 = 0;
  *param_2 = 0;
  DAT_0071406c = (int *)0x0;
  DAT_00714070 = (int *)0x0;
  iVar1 = Ordinal_1(0,&DAT_00714068);
  if (iVar1 == 0) {
    pHVar2 = GetForegroundWindow();
    if (pHVar2 == (HWND)0x0) {
      pHVar2 = GetDesktopWindow();
    }
    (**(code **)(*DAT_00714068 + 0x18))(DAT_00714068,pHVar2,2);
    auStack_78[0] = 0x60;
    iVar1 = (**(code **)(*DAT_00714068 + 0x10))(DAT_00714068,auStack_78);
    if (iVar1 == 0) {
      *puStack_8 = uStack_40;
      DAT_00714074 = bStack_68 >> 5 & 1;
      FUN_00654cd0(&uStack_90,0x24);
      uStack_90 = 0x24;
      iVar1 = (**(code **)(*DAT_00714068 + 0xc))(DAT_00714068,&uStack_90,&DAT_0071406c,0);
      if (-1 < iVar1) {
        if (uStack_60 < 0xac45) {
          uVar4 = uStack_60;
          if (uStack_60 == 0) {
            uVar4 = 0x2b11;
          }
        }
        else {
          uVar4 = 0xac44;
        }
        *unaff_retaddr = 0;
        iVar3 = FUN_006538b0(1,uVar4);
        if (-1 < iVar3) {
          if (param_1 != (undefined1 *)0x0) {
            *param_1 = 1;
          }
          *unaff_retaddr = 1;
        }
        iVar3 = FUN_006538b0(2,uVar4);
        if (-1 < iVar3) {
          if (param_1 != (undefined1 *)0x0) {
            param_1[1] = 1;
          }
          *unaff_retaddr = 2;
        }
        iVar3 = FUN_006538b0(4,uVar4);
        if (-1 < iVar3) {
          if (param_1 != (undefined1 *)0x0) {
            param_1[2] = 1;
          }
          *unaff_retaddr = 4;
        }
        iVar3 = FUN_006538b0(6,uVar4);
        if (-1 < iVar3) {
          if (param_1 != (undefined1 *)0x0) {
            param_1[3] = 1;
          }
          *unaff_retaddr = 5;
        }
        FUN_00654210(1);
        *piStack_4 = (int)DAT_00714075;
        FUN_00653d10();
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else if (iVar1 == -0x7787fff6) {
    iVar1 = -0x12;
    DAT_00714068 = (int *)0x0;
  }
  else {
    DAT_00714068 = (int *)0x0;
    iVar1 = ((iVar1 != -0x7787ff88) - 1 & 0xfffffff7) - 1;
  }
  if (DAT_00714070 != (int *)0x0) {
    (**(code **)(*DAT_00714070 + 8))(DAT_00714070);
    DAT_00714070 = (int *)0x0;
  }
  if (DAT_0071406c != (int *)0x0) {
    (**(code **)(*DAT_0071406c + 8))(DAT_0071406c);
    DAT_0071406c = (int *)0x0;
  }
  if (DAT_00714068 != (int *)0x0) {
    (**(code **)(*DAT_00714068 + 8))(DAT_00714068);
  }
  DAT_00714068 = (int *)0x0;
  return iVar1;
}


// ==== 0x654a90 FUN_00654a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00654a90(void)

{
  DWORD DVar1;
  DWORD DVar2;
  
  timeBeginPeriod(1);
  DVar1 = timeGetTime();
  DAT_0071405c = DVar1;
  while (DAT_00713ff1 != '\0') {
    if (DAT_00713fc4 != (code *)0x0) {
      (*DAT_00713fc4)();
    }
    _DAT_00714058 = DAT_0071405c;
    DAT_0071405c = timeGetTime();
    (*(code *)PTR_thunk_FUN_00652d80_006e9b8c)();
    FUN_006545d0();
    if (DAT_00713ff5 != '\0') {
      FUN_00653e50();
    }
    if (DAT_00713ff4 != '\0') {
      FUN_00653ec0();
    }
    (*(code *)PTR_thunk_FUN_00652d90_006e9b90)();
    DVar1 = DVar1 + 10;
    DVar2 = timeGetTime();
    DVar2 = DVar1 - DVar2;
    if (((int)DVar2 < 0) || (200 < (int)DVar2)) {
      DVar2 = 1;
    }
    if (DAT_00713fc8 != (code *)0x0) {
      (*DAT_00713fc8)();
    }
    Sleep(DVar2);
  }
  timeEndPeriod(1);
  DAT_00713ff0 = 0;
  return 0;
}


// ==== 0x654b50 FUN_00654b50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00654b50(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  DAT_00714010 = 0x100;
  FUN_0064e520();
  iVar1 = 0;
  if (DAT_00713dbc != 0) {
    do {
      if (((&DAT_00713dbe)[iVar1 * 2] & 0x11) == 0x11) {
        DAT_00714014 = FUN_00650fd0((uint)DAT_00714010 << 3);
        break;
      }
      iVar1 = iVar1 + 1;
      DAT_00714014 = 0;
    } while (iVar1 < (int)(uint)DAT_00713dbc);
  }
  DAT_0071400c = FUN_00650fd0(DAT_00713ee8 * 0x110);
  FUN_00654cd0(DAT_0071400c,DAT_00713ee8 * 0x110);
  if (DAT_00713ff4 != '\0') {
    puVar3 = &DAT_00714004;
    do {
      uVar2 = FUN_00650fd0(0x2020);
      puVar3[-2] = uVar2;
      uVar2 = uVar2 + 8;
      *puVar3 = uVar2;
      while ((uVar2 & 0xf) != 0) {
        uVar2 = *puVar3 + 4;
        *puVar3 = uVar2;
      }
      puVar3 = puVar3 + 1;
    } while ((int)puVar3 < 0x71400c);
  }
  SNDSYS_leavecritical();
  if (DAT_00713da8 == -1) {
    _DAT_006e9ff0 = _DAT_006e9ff0 - 10.0;
  }
  else if (DAT_00713da8 == '\x01') {
    _DAT_006e9ff0 = _DAT_006e9ff0 + 20.0;
  }
  else if (DAT_00713da8 == '\x02') {
    _DAT_006e9ff0 = _DAT_006e9ff0 + 50.0;
  }
  if (DAT_00713ff2 == '\0') {
    _atexit(thunk_FUN_0064e8e0);
    DAT_00713ff2 = '\x01';
  }
  iVar1 = FUN_00654340();
  if (-1 < iVar1) {
    DAT_00714060 = 0;
    DAT_006e9ff8 = 0;
    DAT_00713ff0 = 1;
    DAT_00713ff1 = 1;
    _DAT_007160c4 =
         CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00654a90,(LPVOID)0x0,0,(LPDWORD)&DAT_007160c8
                     );
    SetThreadPriority(_DAT_007160c4,0xf);
  }
  return iVar1;
}


// ==== 0x654cd0 FUN_00654cd0

undefined8 __fastcall
FUN_00654cd0(undefined4 param_1,undefined4 param_2,undefined8 *param_3,uint param_4)

{
  undefined4 in_EAX;
  
  if (((uint)param_3 & 7) != 0) {
    if ((((uint)param_3 & 1) != 0) && (0 < (int)param_4)) {
      *(undefined1 *)param_3 = 0;
      param_3 = (undefined8 *)((int)param_3 + 1);
      param_4 = param_4 - 1;
    }
    if ((((uint)param_3 & 2) != 0) && (1 < (int)param_4)) {
      *(undefined2 *)param_3 = 0;
      param_3 = (undefined8 *)((int)param_3 + 2);
      param_4 = param_4 - 2;
    }
    if ((((uint)param_3 & 4) != 0) && (3 < (int)param_4)) {
      *(undefined4 *)param_3 = 0;
      param_3 = (undefined8 *)((int)param_3 + 4);
      param_4 = param_4 - 4;
    }
  }
  if (-1 < (int)param_4) {
    while (-1 < (int)(param_4 - 0x20)) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3 = param_3 + 4;
      param_4 = param_4 - 0x20;
    }
    while (-1 < (int)(param_4 - 8)) {
      *param_3 = 0;
      param_3 = param_3 + 1;
      param_4 = param_4 - 8;
    }
    if (param_4 != 0) {
      if ((param_4 & 4) != 0) {
        *(undefined4 *)param_3 = 0;
        param_3 = (undefined8 *)((int)param_3 + 4);
      }
      if ((param_4 & 2) != 0) {
        *(undefined2 *)param_3 = 0;
        param_3 = (undefined8 *)((int)param_3 + 2);
      }
      if ((param_4 & 1) != 0) {
        *(undefined1 *)param_3 = 0;
      }
      return CONCAT44(param_2,in_EAX);
    }
  }
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x654de0 FUN_00654de0

void FUN_00654de0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_0064e520();
  iVar2 = 0;
  if (0 < DAT_00713ee8) {
    iVar1 = 0;
    do {
      SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
                (*(undefined4 *)(iVar1 + DAT_00713f48));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x8c;
    } while (iVar2 < DAT_00713ee8);
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x654e20 SNDCTRLI_getfxbus

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined2 * SNDCTRLI_getfxbus(int param_1,uint param_2)

{
  if ((param_2 & 0x71c) == 4) {
    return &DAT_00713f50 + param_1 * 10;
  }
  if ((param_2 & 0x71c) != 0x10) {
    return (undefined2 *)0x0;
  }
  return &DAT_00713f64 + param_1 * 10;
}


// ==== 0x654e60 FUN_00654e60

undefined4 FUN_00654e60(uint param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_00713ee4 != '\0') {
    uVar2 = param_1 & 0xfffffe07;
    if ((param_1 & 0x1f8) == 0) {
      param_1 = param_1 | 0x1f8;
    }
    if ((param_1 & 0x10) != 0) {
      (&DAT_00713f52)[uVar2 * 0x14] = param_2;
    }
    if ((param_1 & 0x180) != 0) {
      (&DAT_00713f66)[uVar2 * 0x14] = param_2;
    }
    FUN_0064e520();
    iVar1 = 0;
    if (0 < DAT_00713ee8) {
      iVar3 = 0;
      do {
        FUN_00658e60(*(undefined4 *)(iVar3 + DAT_00713f48),uVar2,
                     (int)*(char *)(uVar2 + 0x61 + iVar3 + DAT_00713f48));
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x8c;
      } while (iVar1 < DAT_00713ee8);
    }
    SNDSYS_leavecritical();
    return 0;
  }
  return 0xfffffff6;
}


// ==== 0x654f00 FUN_00654f00

undefined4
FUN_00654f00(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  if ((param_1 & 0x1f8) == 0) {
    param_1 = param_1 | 0x1f8;
  }
  uVar1 = 0;
  if ((param_1 & 0x10) != 0) {
    uVar1 = 4;
  }
  if ((char)param_1 < '\0') {
    uVar1 = uVar1 | 0x10;
  }
  uVar4 = param_1 & 0xfffffe07;
  uVar3 = 4;
  while (uVar1 != 0) {
    if ((uVar1 & uVar3) != 0) {
      if ((uVar3 & 0x71c) == 4) {
        puVar2 = &DAT_00713f50 + uVar4 * 10;
      }
      else if ((uVar3 & 0x71c) == 0x10) {
        puVar2 = &DAT_00713f64 + uVar4 * 10;
      }
      else {
        puVar2 = (undefined2 *)0x0;
      }
      *puVar2 = (short)param_3;
      *(undefined4 *)(puVar2 + 2) = param_4;
      *(undefined4 *)(puVar2 + 4) = param_5;
      FUN_00659950(uVar4,uVar3);
      uVar1 = uVar1 & ~uVar3;
    }
    uVar3 = uVar3 << 1;
  }
  if (param_3 != 0) {
    FUN_00654e60(param_1,param_2);
    return 0;
  }
  FUN_00654e60(param_1,0);
  return 0;
}


// ==== 0x654fe0 FUN_00654fe0

undefined4 FUN_00654fe0(void)

{
  undefined4 uVar1;
  
  FUN_0064e520();
  uVar1 = FUN_00653de0();
  SNDSYS_leavecritical();
  return uVar1;
}


// ==== 0x655000 FUN_00655000

undefined4 * FUN_00655000(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((-1 < (int)param_1) && (iVar2 = FUN_00650020(param_1 & 0xff), iVar2 != 0)) {
    for (puVar1 = *(undefined4 **)(iVar2 + 0x140);
        (puVar1 != (undefined4 *)0x0 && (puVar1[3] != param_1)); puVar1 = (undefined4 *)*puVar1) {
    }
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== 0x655040 FUN_00655040

int FUN_00655040(int param_1)

{
  int iVar1;
  
  iVar1 = NullChunk__Loader();
  return iVar1 + 0x9c + param_1 * 0x20;
}


// ==== 0x655060 FUN_00655060

int FUN_00655060(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  FUN_0064e520();
  iVar3 = 0;
  if (DAT_00713db6 != 0) {
    do {
      if ((&DAT_007163dc)[iVar3] == 0) {
        iVar1 = NullChunk__Loader(iVar3,param_4);
        if (iVar1 < 0) {
          SNDSYS_leavecritical();
          return -6;
        }
        iVar1 = NullChunk__Loader();
        puVar2 = (undefined4 *)(param_4 + iVar1);
        iVar1 = NullChunk__Loader();
        *(short *)(puVar2 + 0x10) = (short)((param_5 - iVar1) - 0x9cU >> 5);
        puVar2[0x14] = param_4;
        puVar2[0x15] = param_1;
        puVar2[0x16] = param_2;
        puVar2[0x17] = param_3;
        *puVar2 = 0xffffffff;
        (&DAT_007163dc)[iVar3] = puVar2;
        SNDSYS_leavecritical();
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)DAT_00713db6);
  }
  SNDSYS_leavecritical();
  return -9;
}


// ==== 0x655120 SNDPKTPLAY_start

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDPKTPLAY_start(int param_1,int *param_2,undefined2 *param_3,char *param_4)

{
  short *psVar1;
  char cVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  short sVar15;
  int *piVar16;
  short *local_f8;
  uint local_f4;
  undefined2 local_f0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0;
  undefined1 local_cc [3];
  byte local_c9;
  undefined2 local_b4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  piVar3 = (int *)(&DAT_007163dc)[param_1];
  local_c9 = *(byte *)((int)param_2 + 2);
  iVar6 = *param_2;
  uVar10 = (uint)local_c9;
  local_dc = 0;
  local_b4 = param_3[4];
  piVar3[1] = 0;
  piVar3[0x12] = 0;
  piVar3[0x18] = iVar6;
  piVar3[0x13] = 0;
  piVar3[3] = 0;
  piVar3[2] = 0;
  *(undefined2 *)((int)piVar3 + 0x46) = 0;
  *(undefined2 *)(piVar3 + 0x11) = 0;
  local_f8 = (short *)0x0;
  if (*(char *)((int)piVar3 + 0x62) != '\0') {
    piVar16 = (int *)(param_3 + 0xc);
    piVar11 = piVar3 + 0x19;
    piVar5 = piVar3 + 10;
    do {
      piVar11[-0x15] = 0;
      *(undefined2 *)(piVar5 + 3) = 0;
      *(undefined2 *)piVar5 = 0;
      *piVar11 = *piVar16;
      local_f8 = (short *)((int)local_f8 + 1);
      piVar5 = (int *)((int)piVar5 + 2);
      piVar16 = piVar16 + 1;
      piVar11 = piVar11 + 1;
    } while ((int)local_f8 < (int)(uint)*(byte *)((int)piVar3 + 0x62));
  }
  while (iVar6 = FUN_00659a70(&local_dc,local_cc), iVar6 != 0) {
    FUN_00651a00(iVar6,&local_d4,&local_d8);
    iVar7 = FUN_00652270(uVar10,0x65,&local_d0,local_d4,local_d8);
    if (iVar7 < 0) {
      *piVar3 = -9;
    }
    else {
      *piVar3 = local_d0;
      local_f4 = -1;
      local_f4._0_1_ = 0xff;
      iVar12 = 0;
      if (*(char *)((int)param_2 + 2) != '\0') {
        local_f8 = (short *)(iVar7 * 0x8c + 4 + DAT_00713f48);
        sVar15 = -1;
        do {
          if (sVar15 < *local_f8) {
            local_f4 = iVar12;
            sVar15 = *local_f8;
          }
          local_f8 = local_f8 + 1;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)(uint)*(byte *)((int)param_2 + 2));
      }
      *(undefined1 *)((int)piVar3 + 0x42) = (undefined1)local_f4;
      iVar12 = iVar7 * 0x8c + DAT_00713f48;
      *(undefined4 *)(iVar12 + 0x18) = 0xffffffff;
      *(undefined4 *)(iVar12 + 0x14) = 0;
      *(short *)(iVar12 + 0x20) = (short)*param_2;
      *(undefined1 *)(iVar12 + 0x22) = *(undefined1 *)((int)param_2 + 3);
      *(undefined1 *)(iVar12 + 0x23) = *(undefined1 *)((int)param_2 + 2);
      if (*(char *)((int)param_2 + 2) == '\x01') {
        *(undefined2 *)(iVar12 + 0x1c) = *(undefined2 *)(param_4 + 8);
      }
      else {
        FUN_00655a40(iVar12);
      }
      *(undefined2 *)(iVar12 + 0x4c) = 0;
      *(undefined2 *)(iVar12 + 0x12) = 0xffff;
      *(undefined2 *)(iVar12 + 0x84) = *param_3;
      *(undefined2 *)(iVar12 + 0x88) = *(undefined2 *)(param_4 + 0xc);
      *(char *)(iVar12 + 100) = param_4[1];
      *(undefined1 *)(iVar12 + 0x60) = *(undefined1 *)((int)param_3 + 5);
      *(char *)(iVar12 + 0x61) = param_4[5];
      cVar2 = *(char *)(param_3 + 3);
      *(undefined1 *)(iVar12 + 0x26) = 0;
      *(undefined1 *)(iVar12 + 0x27) = 0;
      *(undefined4 *)(iVar12 + 0x74) = 0;
      *(undefined4 *)(iVar12 + 0x7c) = 0;
      *(short *)(iVar12 + 0x82) = cVar2 * 100;
      iVar13 = 0;
      *(float *)(iVar12 + 0x38) = (float)(int)*param_4 * 0.007874016;
      uVar8 = (uint)*(byte *)((int)param_2 + 2);
      if (uVar8 != 0) {
        do {
          *(short *)(iVar12 + 0x50 + iVar13 * 2) =
               param_3[iVar13 + 6] - *(short *)(&DAT_00713f70 + (iVar13 + uVar8 * 6) * 2);
          iVar9 = *(short *)(iVar12 + 4 + iVar13 * 2) * 0x8c + DAT_00713f48;
          local_f0 = (undefined2)iVar6;
          *(undefined2 *)(iVar9 + 0x24) = local_f0;
          *(char *)(iVar9 + 0x5f) = param_4[4];
          *(undefined1 *)(iVar9 + 0x2b) = *(undefined1 *)((int)param_3 + 3);
          *(undefined4 *)(iVar9 + 0x38) = *(undefined4 *)(iVar12 + 0x38);
          *(undefined4 *)(iVar9 + 0x70) = 0;
          *(undefined4 *)(iVar9 + 0x30) = 0;
          *(undefined1 *)(iVar9 + 0x5c) = 1;
          *(undefined1 *)(iVar9 + 0x5e) = 0;
          *(undefined1 *)(iVar9 + 0x5d) = 0;
          *(undefined4 *)(iVar9 + 0x40) = 0x7f0000;
          *(undefined4 *)(iVar9 + 0x44) = 0x7fffffff;
          *(undefined4 *)(iVar9 + 0x3c) = 0;
          *(undefined4 *)(iVar9 + 0x6c) = 0;
          *(undefined4 *)(iVar9 + 0x78) = 0;
          fVar4 = _DAT_006e9bc8 * *(float *)(iVar9 + 0x38);
          *(bool *)(iVar9 + 0x4e) = iVar13 == 5;
          *(undefined2 *)(iVar9 + 0x1e) = 0;
          iVar13 = iVar13 + 1;
          *(float *)(iVar9 + 0x48) = fVar4;
          uVar8 = (uint)*(byte *)((int)param_2 + 2);
        } while (iVar13 < (int)uVar8);
      }
      if (*(char *)((int)param_2 + 2) == '\x01') {
        *(undefined2 *)(iVar12 + 0x1e) = *(undefined2 *)(param_4 + 10);
      }
      local_f8 = (short *)0x0;
      if (*(char *)((int)param_2 + 2) != '\0') {
        psVar14 = (short *)(iVar12 + 0x50);
        do {
          psVar1 = (short *)(psVar14[-0x26] * 0x8c + DAT_00713f48 + 0x1c);
          *psVar1 = *psVar1 + *psVar14;
          local_f8 = (short *)((int)local_f8 + 1);
          psVar14 = psVar14 + 1;
        } while ((int)local_f8 < (int)(uint)*(byte *)((int)param_2 + 2));
      }
      *(undefined2 *)(iVar12 + 0x86) = 0;
      iSNDcalcpitch(iVar7);
      SNDI_calcfxlevel(0,iVar7);
      iVar6 = SNDPLATFORM_packetplay
                        (param_1,iVar7,*(undefined2 *)(param_4 + 0xe),
                         *(undefined2 *)(param_4 + 0x12),*(undefined2 *)(param_4 + 0x14),
                         *(undefined2 *)(param_4 + 0x16),param_2,param_3);
      if (-1 < iVar6) break;
      if (uVar10 != 0) {
        iVar7 = iVar7 * 0x8c + 4;
        local_f4 = uVar10;
        do {
          SNDVOICEI_free((int)*(short *)(DAT_00713f48 + iVar7));
          iVar7 = iVar7 + 2;
          local_f4 = local_f4 - 1;
        } while (local_f4 != 0);
      }
      *piVar3 = iVar6;
    }
  }
  return *piVar3;
}


// ==== 0x655500 FUN_00655500

undefined4 FUN_00655500(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = (&DAT_007163dc)[param_1];
  iVar3 = 0;
  if (*(char *)(iVar1 + 0x62) != '\0') {
    psVar5 = (short *)(iVar1 + 0x34);
    do {
      if (*(short *)(iVar1 + 0x40) + -1 <= (int)*psVar5) {
        return 0xfffffff3;
      }
      iVar3 = iVar3 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(iVar1 + 0x62));
  }
  iVar3 = *(short *)(iVar1 + 0x46) * 0x20;
  puVar7 = (undefined4 *)(iVar3 + 0x7c + iVar1);
  uVar6 = *(uint *)(iVar3 + 0x80 + iVar1) ^ (puVar7[1] ^ *(uint *)(param_2 + 4)) & 0x7fffffff;
  puVar7[1] = uVar6;
  puVar7[1] = *(uint *)(param_2 + 4) & 0x80000000 | uVar6 & 0x7fffffff;
  *puVar7 = *(undefined4 *)(iVar1 + 4);
  iVar3 = 0;
  if (*(char *)(iVar1 + 0x62) != '\0') {
    puVar7 = puVar7 + 2;
    puVar4 = (undefined4 *)(param_2 + 0xc);
    psVar5 = (short *)(iVar1 + 0x34);
    do {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
      *psVar5 = *psVar5 + 1;
      iVar3 = iVar3 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(iVar1 + 0x62));
  }
  *(uint *)(iVar1 + 0x48) = (*(uint *)(param_2 + 4) & 0x7fffffff) + *(int *)(iVar1 + 0x48);
  uVar2 = *(undefined4 *)(iVar1 + 4);
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  *(short *)(iVar1 + 0x46) = *(short *)(iVar1 + 0x46) + 1;
  if (*(short *)(iVar1 + 0x40) <= *(short *)(iVar1 + 0x46)) {
    *(undefined2 *)(iVar1 + 0x46) = 0;
  }
  return uVar2;
}


// ==== 0x655610 FUN_00655610

int FUN_00655610(int param_1)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (DAT_00713ee4 != '\0') {
    iVar1 = (&DAT_007163dc)[param_1];
    uVar3 = (uint)*(byte *)(iVar1 + 0x62);
    if (uVar3 != 0) {
      psVar2 = (short *)(iVar1 + 0x34);
      do {
        if (iVar4 <= *psVar2) {
          iVar4 = (int)*psVar2;
        }
        psVar2 = psVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    return (*(short *)(iVar1 + 0x40) - iVar4) + -1;
  }
  return -10;
}


// ==== 0x655660 FUN_00655660

int FUN_00655660(int param_1)

{
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  return *(int *)((&DAT_007163dc)[param_1] + 0x4c) + *(int *)((&DAT_007163dc)[param_1] + 0x48);
}


// ==== 0x655690 FUN_00655690

undefined4 FUN_00655690(int param_1)

{
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  FUN_0064e520();
  NullChunk__Loader(param_1);
  (&DAT_007163dc)[param_1] = 0;
  SNDSYS_leavecritical();
  return 0;
}


// ==== 0x6556d0 FUN_006556d0

int FUN_006556d0(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = DAT_007160d8;
  iVar5 = (&DAT_007163dc)[param_1];
  bVar3 = true;
  bVar4 = true;
  if (*(char *)(iVar5 + 0x62) != '\0') {
    uVar8 = (uint)*(byte *)(iVar5 + 0x62);
    puVar6 = (uint *)(iVar5 + 0x10);
    do {
      if (*puVar6 <= *(uint *)(iVar5 + 8)) {
        bVar3 = false;
      }
      puVar6 = puVar6 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
    if (!bVar3) goto LAB_0065575d;
  }
  sVar2 = *(short *)(iVar5 + 0x44);
  if (*(int *)(iVar5 + 0x54) != 0) {
    (&DAT_007160dc)[DAT_007160d8 * 4] = 1;
    (&DAT_007160de)[iVar1 * 4] = (short)param_1;
    (&DAT_007160e0)[iVar1 * 2] = *(undefined4 *)(sVar2 * 0x20 + iVar5 + 0x84);
    DAT_007160d8 = DAT_007160d8 + 1;
  }
  *(short *)(iVar5 + 0x44) = *(short *)(iVar5 + 0x44) + 1;
  *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
  if (*(short *)(iVar5 + 0x40) <= *(short *)(iVar5 + 0x44)) {
    *(undefined2 *)(iVar5 + 0x44) = 0;
  }
LAB_0065575d:
  if (*(short *)(iVar5 + 0x34 + param_2 * 2) == 0) {
    return 0;
  }
  iVar1 = *(short *)(iVar5 + 0x28 + param_2 * 2) * 0x20 + 0x7c + iVar5;
  *param_3 = (*(int *)(iVar1 + 4) << 1) >> 1;
  *param_4 = *(int *)(iVar1 + 4) >> 0x1f;
  puVar6 = (uint *)(iVar5 + 0x10);
  *(short *)(iVar5 + 0x28 + param_2 * 2) = *(short *)(iVar5 + 0x28 + param_2 * 2) + 1;
  *(int *)(iVar5 + 0x10 + param_2 * 4) = *(int *)(iVar5 + 0x10 + param_2 * 4) + 1;
  iVar7 = 0;
  while( true ) {
    if (*puVar6 <= *(uint *)(iVar5 + 0xc)) {
      bVar4 = false;
    }
    iVar7 = iVar7 + 1;
    puVar6 = puVar6 + 1;
    if (!bVar4) break;
    if ((int)(uint)*(byte *)(iVar5 + 0x62) <= iVar7) {
LAB_006557d0:
      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;
      *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) - ((*(int *)(iVar1 + 4) << 1) >> 1);
      *(int *)(iVar5 + 0x4c) = ((*(int *)(iVar1 + 4) << 1) >> 1) + *(int *)(iVar5 + 0x4c);
LAB_006557f5:
      if (*(short *)(iVar5 + 0x40) <= *(short *)(iVar5 + 0x28 + param_2 * 2)) {
        *(undefined2 *)(iVar5 + 0x28 + param_2 * 2) = 0;
      }
      *(short *)(iVar5 + 0x34 + param_2 * 2) = *(short *)(iVar5 + 0x34 + param_2 * 2) + -1;
      iVar5 = *(int *)(iVar1 + 8 + param_2 * 4);
      if (iVar5 == 0) {
        iVar5 = -1;
      }
      return iVar5;
    }
  }
  if (!bVar4) goto LAB_006557f5;
  goto LAB_006557d0;
}


// ==== 0x655830 FUN_00655830

void FUN_00655830(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_007163dc)[param_1];
  if (param_2 == *(char *)(iVar1 + 0x42)) {
    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) - param_3;
    iVar2 = DAT_007160d8;
    if (*(int *)(iVar1 + 0x58) != 0) {
      (&DAT_007160dc)[DAT_007160d8 * 4] = 0;
      (&DAT_007160de)[iVar2 * 4] = (short)param_1;
      (&DAT_007160e0)[iVar2 * 2] = param_3;
      DAT_007160d8 = DAT_007160d8 + 1;
    }
  }
  return;
}


// ==== 0x655880 FUN_00655880

void FUN_00655880(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_007160d8) {
    puVar2 = &DAT_007160e0;
    do {
      iVar1 = (&DAT_007163dc)[*(ushort *)((int)puVar2 + -2)];
      if (*(short *)(puVar2 + -1) == 0) {
        (**(code **)(iVar1 + 0x58))
                  ((uint)*(ushort *)((int)puVar2 + -2),*puVar2,*(undefined4 *)(iVar1 + 0x5c));
      }
      else {
        (**(code **)(iVar1 + 0x54))(*puVar2,*(undefined4 *)(iVar1 + 0x5c));
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 2;
    } while (iVar3 < DAT_007160d8);
  }
  DAT_007160d8 = 0;
  return;
}


// ==== 0x6558f0 FUN_006558f0

undefined4 FUN_006558f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_00713ee4 != '\0') {
    puVar1 = (undefined4 *)(&DAT_007163dc)[param_1];
    SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
              (*puVar1);
    FUN_00655880();
    iVar2 = 0;
    *puVar1 = 0xffffffff;
    if (*(char *)((int)puVar1 + 0x62) != '\0') {
      piVar3 = puVar1 + 0x19;
      do {
        if (*piVar3 != 0) {
          FUN_006510d0(*piVar3);
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < (int)(uint)*(byte *)((int)puVar1 + 0x62));
    }
    return 0;
  }
  return 0xfffffff6;
}


// ==== 0x655960 FUN_00655960

int FUN_00655960(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = 0xffffffff;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      FUN_00659b40(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x6559d0 FUN_006559d0

int FUN_006559d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = 0xffffffff;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      FUN_00659c20(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x655a40 FUN_00655a40

void FUN_00655a40(int param_1)

{
  int iVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  bVar2 = *(byte *)(param_1 + 0x23);
  iVar1 = DAT_00713ce0 * 6;
  iVar5 = 0;
  if (bVar2 != 0) {
    psVar6 = (short *)(param_1 + 4);
    do {
      sVar3 = *psVar6;
      iVar4 = iVar5 + ((uint)bVar2 + iVar1) * 6;
      iVar5 = iVar5 + 1;
      psVar6 = psVar6 + 1;
      *(ushort *)(sVar3 * 0x8c + 0x1c + DAT_00713f48) = (ushort)(byte)(&DAT_006aaa32)[iVar4] << 8;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x23));
  }
  return;
}


// ==== 0x655aa0 FUN_00655aa0

void FUN_00655aa0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== 0x655ab0 FUN_00655ab0

void FUN_00655ab0(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  param_2[1] = 0;
  if (*param_1 != 0) {
    *(int **)(*param_1 + 4) = param_2;
    *param_1 = (int)param_2;
    param_1[2] = param_1[2] + 1;
    return;
  }
  param_1[1] = (int)param_2;
  *param_1 = (int)param_2;
  param_1[2] = param_1[2] + 1;
  return;
}


// ==== 0x655ae0 FUN_00655ae0

void FUN_00655ae0(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = param_1[1];
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = param_2;
    param_1[1] = param_2;
    param_1[2] = param_1[2] + 1;
    return;
  }
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_1[2] + 1;
  return;
}


// ==== 0x655b10 FUN_00655b10

void FUN_00655b10(int *param_1)

{
  int iVar1;
  
  if ((int *)*param_1 != (int *)0x0) {
    iVar1 = *(int *)*param_1;
    *param_1 = iVar1;
    if (iVar1 == 0) {
      param_1[1] = 0;
      param_1[2] = param_1[2] + -1;
      return;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    param_1[2] = param_1[2] + -1;
  }
  return;
}


// ==== 0x655b40 FUN_00655b40

void FUN_00655b40(int *param_1,int *param_2)

{
  if (param_2 == (int *)*param_1) {
    *param_1 = *(int *)*param_1;
  }
  if (param_2 == (int *)param_1[1]) {
    param_1[1] = ((int *)param_1[1])[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 != 0) {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  param_1[2] = param_1[2] + -1;
  return;
}


// ==== 0x655b80 SNDI_patchtohdr

/* [canon] audio high (ghidra) docs/re/sound.md */

void SNDI_patchtohdr(int param_1,uint *param_2,undefined2 *param_3,int param_4,undefined4 *param_5,
                    undefined1 *param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  short *psVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 local_18;
  char *local_14;
  int local_10;
  undefined4 local_c;
  undefined4 *local_8;
  uint local_4;
  
  local_18 = 0;
  local_18._0_2_ = 0;
  FUN_00654cd0(param_3,4);
  FUN_00654cd0(param_4,0x68);
  FUN_00654cd0(param_5,0x1c);
  if (((((*(char *)param_2 == 'P') && (*(char *)((int)param_2 + 1) == 'T')) ||
       (*(char *)param_2 != 'G')) ||
      ((*(char *)((int)param_2 + 1) != 'S' || (*(char *)((int)param_2 + 2) != 'T')))) ||
     (*(char *)((int)param_2 + 3) != 'R')) {
    if (param_6 != (undefined1 *)0x0) {
      *param_6 = 0;
    }
    FUN_00659d20(param_4);
    local_14 = (char *)((int)param_2 + 4);
    *param_3 = 0x5622;
    *(undefined1 *)(param_3 + 1) = 1;
    *(undefined1 *)((int)param_3 + 3) = 10;
    *param_5 = 0;
    iVar2 = SNDI_gettag(&local_14);
    if (iVar2 != 0) {
      param_2 = (uint *)(param_4 + 0x58);
      do {
        uVar1 = (undefined1)local_c;
        if (local_10 == 0xa0) {
          *(undefined1 *)((int)param_3 + 3) = (undefined1)local_c;
        }
        else if (local_10 == 0x9c) {
          *(undefined2 *)(param_4 + 0xc) = (undefined2)local_c;
        }
        else if (local_10 == 0x9d) {
          *(undefined2 *)(param_4 + 0xe) = (undefined2)local_c;
        }
        else if (local_10 == 0x9e) {
          *(undefined2 *)(param_4 + 0x10) = (undefined2)local_c;
        }
        else if (local_10 == 0x9f) {
          *(undefined2 *)(param_4 + 0x12) = (undefined2)local_c;
        }
        else if (local_10 == 0xa6) {
          *(undefined2 *)(param_4 + 0x14) = (undefined2)local_c;
        }
        else if (local_10 == 0xa7) {
          *(undefined2 *)(param_4 + 0x16) = (undefined2)local_c;
        }
        else if (local_10 == 0x98) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x18) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x30) = local_4;
        }
        else if (local_10 == 0x99) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x1c) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x34) = local_4;
        }
        else if (local_10 == 0x9a) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x20) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x38) = local_4;
        }
        else if (local_10 == 0x9b) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x24) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x3c) = local_4;
        }
        else if (local_10 == 0xa4) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x28) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x40) = local_4;
        }
        else if (local_10 == 0xa5) {
          puVar3 = (undefined4 *)FUN_00650fd0(local_4);
          *(undefined4 **)(param_4 + 0x2c) = puVar3;
          puVar6 = local_8;
          for (uVar4 = local_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar3 = puVar3 + 1;
          }
          for (uVar4 = local_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 1);
          }
          *(uint *)(param_4 + 0x44) = local_4;
        }
        else if (local_10 == 0x80) {
          *(undefined1 *)(param_4 + 7) = uVar1;
        }
        else if (local_10 == 0x82) {
          *(undefined1 *)(param_3 + 1) = uVar1;
        }
        else if (local_10 == 0x84) {
          *param_3 = (undefined2)local_c;
        }
        else if (local_10 == 0x85) {
          *param_5 = local_c;
        }
        else if (local_10 != 0x8a) {
          if (local_10 == 0x13) {
            *(undefined1 *)(param_4 + 5) = uVar1;
          }
          else if (local_10 == 10) {
            *(undefined1 *)(param_4 + 6) = uVar1;
          }
          else if (local_10 == 6) {
            *(undefined1 *)(param_4 + 2) = uVar1;
          }
          else if (local_10 == 0x8c) {
            local_18 = local_c;
          }
          else if (local_10 == 0x88) {
            param_5[1] = local_c;
          }
          else if (local_10 == 0x89) {
            param_5[2] = local_c;
          }
          else if (local_10 == 0x94) {
            param_5[3] = local_c;
          }
          else if (local_10 == 0x95) {
            param_5[4] = local_c;
          }
          else if (local_10 == 0xa2) {
            param_5[5] = local_c;
          }
          else if (local_10 == 0xa3) {
            param_5[6] = local_c;
          }
          else if (local_10 == 0x14) {
            param_2[-4] = (uint)local_8;
            *param_2 = local_4;
            param_2 = param_2 + 1;
          }
        }
        iVar2 = SNDI_gettag(&local_14);
      } while (iVar2 != 0);
    }
    *(undefined2 *)(param_4 + 8) = (undefined2)local_18;
    iVar2 = *(byte *)(param_3 + 1) - 1;
    if (-1 < iVar2) {
      piVar7 = param_5 + *(byte *)(param_3 + 1);
      psVar5 = (short *)(param_4 + 0xc + iVar2 * 2);
      do {
        if ((DAT_00713ce0 == 1) && (*(char *)(param_3 + 1) == '\x02')) {
          *psVar5 = 0;
        }
        *psVar5 = *psVar5 + *(short *)(&DAT_00713f70 +
                                      (iVar2 + (uint)*(byte *)(param_3 + 1) * 6) * 2);
        if (((*(ushort *)(param_4 + 8) & 0x14) != 0) || (*(ushort *)(param_4 + 8) == 0)) {
          *piVar7 = *piVar7 + param_1;
        }
        iVar2 = iVar2 + -1;
        psVar5 = psVar5 + -1;
        piVar7 = piVar7 + -1;
      } while (-1 < iVar2);
    }
  }
  else {
    SNDI_patchtohdrgen(0,param_2,param_3,param_4,param_5);
    if (param_6 != (undefined1 *)0x0) {
      *param_6 = 1;
      return;
    }
  }
  return;
}


// ==== 0x656000 FUN_00656000

undefined4 FUN_00656000(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  puVar1 = (undefined4 *)FUN_00650020(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0xfffffff8;
  }
  FUN_00412890(*puVar1,param_2);
  return 0;
}


// ==== 0x656040 SNDMEMI_usage_percent__map:_SNDMEMI_restore_

/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDMEMI_usage_percent__map__SNDMEMI_restore_(void)

{
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  return ((*(int *)(DAT_00713f78 + 8) - *(int *)(DAT_00713f78 + 0x10)) * 100) /
         *(int *)(DAT_00713f78 + 8);
}


// ==== 0x656070 FUN_00656070

void FUN_00656070(float *param_1,float *param_2)

{
  *param_2 = *param_1 * 0.9411765 + *param_2;
  param_2[1] = *param_1 * 0.88235295 + param_2[1];
  param_2[2] = *param_1 * 0.8235294 + param_2[2];
  param_2[3] = *param_1 * 0.7647059 + param_2[3];
  param_2[4] = *param_1 * 0.7058824 + param_2[4];
  param_2[5] = *param_1 * 0.64705884 + param_2[5];
  param_2[6] = *param_1 * 0.5882353 + param_2[6];
  param_2[7] = *param_1 * 0.5294118 + param_2[7];
  param_2[8] = *param_1 * 0.47058824 + param_2[8];
  param_2[9] = *param_1 * 0.4117647 + param_2[9];
  param_2[10] = *param_1 * 0.3529412 + param_2[10];
  param_2[0xb] = *param_1 * 0.29411766 + param_2[0xb];
  param_2[0xc] = *param_1 * 0.23529412 + param_2[0xc];
  param_2[0xd] = *param_1 * 0.1764706 + param_2[0xd];
  param_2[0xe] = *param_1 * 0.11764706 + param_2[0xe];
  param_2[0xf] = *param_1 * 0.05882353 + param_2[0xf];
  *param_1 = 0.0;
  return;
}


// ==== 0x656160 FUN_00656160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00656160(float param_1,float param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  fVar1 = (param_2 - param_1) * 0.05882353;
  *param_4 = (param_1 + fVar1) * *param_3 + *param_4;
  param_4[1] = (fVar1 + fVar1 + param_1) * param_3[1] + param_4[1];
  param_4[2] = (fVar1 * 3.0 + param_1) * param_3[2] + param_4[2];
  param_4[3] = (fVar1 * 4.0 + param_1) * param_3[3] + param_4[3];
  param_4[4] = (fVar1 * 5.0 + param_1) * param_3[4] + param_4[4];
  param_4[5] = (fVar1 * 6.0 + param_1) * param_3[5] + param_4[5];
  param_4[6] = (fVar1 * 7.0 + param_1) * param_3[6] + param_4[6];
  param_4[7] = (K_ONE * fVar1 + param_1) * param_3[7] + param_4[7];
  param_4[8] = (fVar1 * 9.0 + param_1) * param_3[8] + param_4[8];
  param_4[9] = (fVar1 * 10.0 + param_1) * param_3[9] + param_4[9];
  param_4[10] = (fVar1 * 11.0 + param_1) * param_3[10] + param_4[10];
  param_4[0xb] = (fVar1 * 12.0 + param_1) * param_3[0xb] + param_4[0xb];
  param_4[0xc] = (fVar1 * 13.0 + param_1) * param_3[0xc] + param_4[0xc];
  param_4[0xd] = (fVar1 * 14.0 + param_1) * param_3[0xd] + param_4[0xd];
  param_4[0xe] = (fVar1 * 15.0 + param_1) * param_3[0xe] + param_4[0xe];
  param_4[0xf] = (fVar1 * 16.0 + param_1) * param_3[0xf] + param_4[0xf];
  return;
}


// ==== 0x6562c0 FUN_006562c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006562c0(float param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  iVar2 = 0;
  local_c = 0;
  if (DAT_00716465 != 0) {
    do {
      if (_K_ONE <= param_1) {
        if ((&DAT_007165ac)[iVar2] != 0) {
          FUN_006510d0((&DAT_007165ac)[iVar2]);
          (&DAT_007165ac)[iVar2] = 0;
        }
      }
      else {
        if ((&DAT_007165ac)[iVar2] == 0) {
          uVar1 = FUN_00650fd0(0x28);
          (&DAT_007165ac)[iVar2] = uVar1;
          FUN_00659f30(uVar1);
          *(undefined4 *)((&DAT_007165ac)[iVar2] + 8) = 0;
        }
        local_8 = (uint)DAT_00713d9a << 8;
        local_c = (int)ROUND((float)DAT_00713d9a * param_1) << 7;
        local_4 = 0x100;
        FUN_00659f60((&DAT_007165ac)[iVar2],&local_c);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)DAT_00716465);
  }
  return;
}


// ==== 0x6563a0 SNDMIXI_volramp

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDMIXI_volramp(undefined4 *param_1)

{
  int iVar1;
  float *pfVar2;
  
  iVar1 = (**(code **)param_1[0x10])((undefined4 *)param_1[0x10],0x10,DAT_0071653c,DAT_00716540,0);
  if (0 < iVar1) {
    param_1[0xf] = *(undefined4 *)(DAT_00716540 + 0x3c);
    if (DAT_0071646f != '\0') {
      if ((float)param_1[0xd] == (float)param_1[0xe]) {
        if ((float)param_1[0xe] != 0.0) {
          (*DAT_00716670)(0x10,param_1[0xe],DAT_00716540,&DAT_00716688);
        }
      }
      else {
        FUN_00656160(param_1[0xd],param_1[0xe],DAT_00716540,&DAT_00716688);
        param_1[0xd] = param_1[0xe];
      }
    }
    iVar1 = 0;
    if (DAT_00716465 != 0) {
      pfVar2 = (float *)(param_1 + 7);
      do {
        if (pfVar2[-6] == *pfVar2) {
          if (*pfVar2 != 0.0) {
            (*DAT_00716670)(0x10,*pfVar2,DAT_00716540,
                            *(undefined4 *)(((int)&DAT_00716540 - (int)param_1) + (int)pfVar2));
          }
        }
        else {
          FUN_00656160(pfVar2[-6],*pfVar2,DAT_00716540,
                       *(undefined4 *)(((int)&DAT_00716540 - (int)param_1) + (int)pfVar2));
          pfVar2[-6] = *pfVar2;
        }
        iVar1 = iVar1 + 1;
        pfVar2 = pfVar2 + 1;
      } while (iVar1 < (int)(uint)DAT_00716465);
    }
    return 0x10;
  }
  param_1[0xd] = param_1[0xe];
  iVar1 = 0;
  if (DAT_00716465 != 0) {
    do {
      param_1[1] = param_1[7];
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 1;
    } while (iVar1 < (int)(uint)DAT_00716465);
  }
  return 0;
}


// ==== 0x6564f0 thunk_FUN_00650fd0

void thunk_FUN_00650fd0(void)

{
  FUN_00650fd0();
  return;
}


// ==== 0x656500 thunk_FUN_006510d0

void thunk_FUN_006510d0(void)

{
  FUN_006510d0();
  return;
}


// ==== 0x656510 FUN_00656510

void FUN_00656510(void)

{
  int *piVar1;
  int iVar2;
  
  FUN_0064e520();
  if (DAT_00716574 != 0) {
    FUN_006510d0(DAT_00716574);
    DAT_00716574 = 0;
  }
  if (DAT_0071666c != 0) {
    FUN_006510d0(DAT_0071666c);
    DAT_0071666c = 0;
  }
  piVar1 = &DAT_00716534;
  do {
    if (*piVar1 != 0) {
      FUN_006510d0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x71653c);
  iVar2 = 0;
  if (DAT_00716465 != 0) {
    do {
      if ((&DAT_00716544)[iVar2] != 0) {
        FUN_006510d0((&DAT_00716544)[iVar2]);
        (&DAT_00716544)[iVar2] = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)DAT_00716465);
  }
  FUN_006562c0(0x40000000);
  SNDSYS_leavecritical();
  return;
}


// ==== 0x6565c0 FUN_006565c0

void FUN_006565c0(undefined1 param_1)

{
  DAT_0071646e = param_1;
  return;
}


// ==== 0x6565d0 FUN_006565d0

void FUN_006565d0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10,
                 undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined1 param_14)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar4 = (undefined1 *)(param_1 * 0x60 + DAT_0071666c);
  iVar1 = -1;
  iVar3 = 0;
  *(undefined4 *)(puVar4 + 0x40) = 0;
  *(undefined4 *)(puVar4 + 0x48) = 0;
  *(undefined4 *)(puVar4 + 0x50) = 0;
  *(undefined4 *)(puVar4 + 0x58) = 0;
  *(undefined4 *)(puVar4 + 0x5c) = 0;
  *(undefined4 *)(puVar4 + 0x4c) = 0;
  local_14 = 1;
  local_4 = 0;
  if (param_2 == 8) {
    iVar1 = 1;
  }
  else if (param_2 == 9) {
    iVar1 = 0;
    local_14 = 0;
  }
  else if (param_2 == 10) {
    iVar1 = 2;
  }
  else if (param_2 == 4) {
    iVar1 = 3;
  }
  else if (param_2 == 0x16) {
    iVar1 = 4;
  }
  else if (param_2 == 0x10) {
    iVar1 = 5;
  }
  else if (param_2 == 0x17) {
    iVar1 = 6;
  }
  if (param_3 == 1) {
    if (0 < param_10) {
      iVar3 = 1;
    }
  }
  else if (param_3 == 0) {
    iVar3 = 2;
  }
  iVar3 = (iVar3 + iVar1 * 3) * 4;
  if (*(int *)(&DAT_00716474 + iVar3) != 0) {
    uVar2 = FUN_00650fd0(*(undefined4 *)(&DAT_007164d4 + iVar3));
    *(undefined4 *)(puVar4 + 0x48) = uVar2;
    local_28 = param_5;
    local_2c = param_4;
    local_20 = param_8;
    local_c = (uint)DAT_00713eeb;
    local_24 = param_7;
    local_8 = param_13;
    local_1c = param_9;
    local_18 = param_10;
    local_10 = param_1;
    *(undefined4 *)(*(int *)(puVar4 + 0x48) + 4) = 0;
    *(undefined2 *)(*(int *)(puVar4 + 0x48) + 0x18) = 0xf0;
    *(undefined1 *)(*(int *)(puVar4 + 0x48) + 0x1a) = param_14;
    (**(code **)(&DAT_00716474 + iVar3))(*(undefined4 *)(puVar4 + 0x48),&local_2c);
    *(undefined4 *)(puVar4 + 0x44) = local_4;
    FUN_006577e0(puVar4 + 0x40,*(undefined4 *)(puVar4 + 0x48));
  }
  if (param_6 != 0) {
    if (param_3 != 0) {
      param_1 = -1;
    }
    iVar3 = FUN_00650fd0(0x1828);
    *(int *)(puVar4 + 0x4c) = iVar3;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined2 *)(*(int *)(puVar4 + 0x4c) + 0x18) = 200;
    *(undefined1 *)(*(int *)(puVar4 + 0x4c) + 0x1a) = param_14;
    FUN_0065b380(*(undefined4 *)(puVar4 + 0x4c),param_6,param_1);
    FUN_006577e0(puVar4 + 0x40,*(undefined4 *)(puVar4 + 0x4c));
  }
  *puVar4 = 1;
  return;
}


// ==== 0x656790 FUN_00656790

void FUN_00656790(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(param_1 * 0x60 + DAT_0071666c);
  iVar3 = 0;
  puVar2[0xf] = 0;
  *(undefined1 *)((int)puVar2 + 1) = 0;
  puVar2[0xd] = puVar2[0xe];
  puVar1 = puVar2;
  if (DAT_00716465 != 0) {
    do {
      puVar1[1] = puVar1[7];
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar3 < (int)(uint)DAT_00716465);
  }
  *(undefined1 *)puVar2 = 2;
  return;
}


// ==== 0x6567e0 FUN_006567e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006567e0(int param_1)

{
  code *pcVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  
  pfVar5 = (float *)(param_1 * 0x60 + DAT_0071666c);
  iVar4 = 0;
  _DAT_00716590 = *(float *)(param_1 * 0x60 + 0x34 + DAT_0071666c) * pfVar5[0xf] + _DAT_00716590;
  pfVar3 = pfVar5;
  if (DAT_00716465 != 0) {
    do {
      iVar4 = iVar4 + 1;
      (&DAT_00716574)[iVar4] = pfVar3[1] * pfVar5[0xf] + (float)(&DAT_00716574)[iVar4];
      pfVar3 = pfVar3 + 1;
    } while (iVar4 < (int)(uint)DAT_00716465);
  }
  do {
    pcVar1 = *(code **)((int)pfVar5[0x10] + 4);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(pfVar5[0x10]);
    }
    fVar2 = *(float *)((int)pfVar5[0x10] + 8);
    FUN_006510d0(pfVar5[0x10]);
    pfVar5[0x10] = fVar2;
  } while (fVar2 != 0.0);
  *(undefined1 *)pfVar5 = 0;
  return;
}


// ==== 0x656870 FUN_00656870

void FUN_00656870(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(DAT_0071666c + 0x1c + (param_2 + param_1 * 0x18) * 4) = param_3;
  *(undefined1 *)(param_1 * 0x60 + 1 + DAT_0071666c) = 1;
  return;
}


// ==== 0x6568a0 FUN_006568a0

void FUN_006568a0(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(DAT_0071666c + 0x38 + (param_2 + param_1 * 0x18) * 4) = param_3;
  *(undefined1 *)(param_1 * 0x60 + 1 + DAT_0071666c) = 1;
  return;
}


// ==== 0x6568d0 FUN_006568d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006568d0(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  
  FUN_0065b5d0(thunk_FUN_00650fd0);
  FUN_0065b5e0(thunk_FUN_006510d0);
  DAT_0071646f = 0;
  _DAT_00716460 = *param_1;
  _DAT_00716464 = param_1[1];
  DAT_00716468 = param_1[2];
  FUN_0064e520();
  puVar3 = &DAT_0071653c;
  do {
    uVar1 = FUN_00650fd0(0x20bc);
    puVar3[-2] = uVar1;
    uVar1 = uVar1 + 8;
    *puVar3 = uVar1;
    uVar2 = _DAT_00716464;
    while (_DAT_00716464 = uVar2, (uVar1 & 0x3f) != 0) {
      uVar1 = *puVar3 + 4;
      *puVar3 = uVar1;
      uVar2 = _DAT_00716464;
    }
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < 0x716544);
  DAT_00716466 = (char)(uVar2 >> 0x10);
  bVar7 = DAT_00716466 != '\0';
  if (bVar7) {
    DAT_00716574 = FUN_00650fd0((uVar2 >> 8 & 0xff) << 9);
  }
  iVar5 = 0;
  if (DAT_00716465 != '\0') {
    puVar3 = &DAT_0071655c;
    do {
      uVar2 = FUN_00650fd0(0x440);
      puVar3[-6] = uVar2;
      *puVar3 = uVar2;
      while ((uVar2 & 0x3f) != 0) {
        uVar2 = *puVar3 + 4;
        *puVar3 = uVar2;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar5 < (int)(_DAT_00716464 >> 8 & 0xff));
  }
  if (DAT_00716464 != '\0') {
    DAT_0071666c = FUN_00650fd0((_DAT_00716464 & 0xff) * 0x60);
    FUN_00654cd0(DAT_0071666c,(_DAT_00716464 & 0xff) * 0x60);
  }
  SNDSYS_leavecritical();
  FUN_0065b580();
  FUN_0065b540();
  FUN_0065b500();
  FUN_0065b490();
  if ((DAT_00713eeb & 4) == 0) {
    DAT_00716674 = FUN_0065a9a0;
    DAT_00716670 = FUN_0065a900;
    if ((DAT_00713eeb & 2) == 0) {
      DAT_00716670 = FUN_0065a880;
    }
  }
  else {
    DAT_00716670 = FUN_0065aad0;
    DAT_00716674 = FUN_0065aa20;
  }
  DAT_0071646c = 0x200;
  if (DAT_00716466 != '\0') {
    DAT_0071646c = (ushort)DAT_00716465 << 9;
  }
  iVar5 = 0;
  if (DAT_00716465 != 0) {
    puVar6 = &DAT_00716594;
    puVar4 = &DAT_007165c4;
    do {
      *puVar6 = 0;
      FUN_0065b470(puVar4);
      *(undefined2 *)(puVar4 + 0x18) = 0;
      puVar4[0x1a] = 0;
      FUN_006577e0(puVar6,puVar4);
      FUN_00654cd0(puVar6[-0xe],0x400);
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x1c;
      puVar6 = puVar6 + 1;
    } while (iVar5 < (int)(_DAT_00716464 >> 8 & 0xff));
  }
  return;
}


// ==== 0x656ad0 FUN_00656ad0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00656ad0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  char *pcVar7;
  int iStack_10;
  int local_c;
  int local_8;
  
  if ((DAT_0071646f != '\0') && (_DAT_00716590 != 0.0)) {
    FUN_00656070(&DAT_00716590,&DAT_00716688);
  }
  iVar4 = 0;
  if (DAT_00716465 != 0) {
    pfVar6 = (float *)&DAT_00716578;
    do {
      FUN_00654cd0(pfVar6[-7],param_2 * 4);
      if (*pfVar6 != 0.0) {
        FUN_00656070(pfVar6,pfVar6[-7]);
      }
      iVar4 = iVar4 + 1;
      pfVar6 = pfVar6 + 1;
    } while (iVar4 < (int)(uint)DAT_00716465);
  }
  local_c = 0;
  if (DAT_00716464 != 0) {
    local_8 = 0;
    do {
      pcVar7 = (char *)(local_8 + DAT_0071666c);
      if (*pcVar7 == '\x02') {
        if (pcVar7[1] == '\0') {
          iVar3 = 0;
          iVar4 = param_2;
        }
        else {
          iVar3 = SNDMIXI_volramp(pcVar7);
          pcVar7[1] = '\0';
          iVar4 = param_2 - iVar3;
        }
        if (iVar4 != 0) {
          iVar4 = (*(code *)**(undefined4 **)(pcVar7 + 0x40))
                            (*(undefined4 **)(pcVar7 + 0x40),iVar4,DAT_0071653c,DAT_00716540,0);
          if (iVar4 < 0) {
            FUN_006567e0(local_c);
            (*DAT_00716468)(local_c);
          }
          else if (iVar4 != 0) {
            *(undefined4 *)(pcVar7 + 0x3c) = *(undefined4 *)(DAT_00716540 + -4 + iVar4 * 4);
            iStack_10 = 0;
            if (DAT_00716465 != 0) {
              pfVar6 = (float *)(pcVar7 + 0x1c);
              do {
                if (*pfVar6 != 0.0) {
                  (*DAT_00716670)(iVar4,*pfVar6,DAT_00716540,
                                  *(int *)(((int)&DAT_00716540 - (int)pcVar7) + (int)pfVar6) +
                                  iVar3 * 4);
                }
                iStack_10 = iStack_10 + 1;
                pfVar6 = pfVar6 + 1;
              } while (iStack_10 < (int)(uint)DAT_00716465);
            }
            if ((DAT_0071646f != '\0') && (*(float *)(pcVar7 + 0x38) != 0.0)) {
              (*DAT_00716670)(iVar4,*(undefined4 *)(pcVar7 + 0x38),DAT_00716540,
                              &DAT_00716688 + iVar3 * 4);
              DAT_00717288 = 0;
            }
          }
        }
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x60;
    } while (local_c < (int)(uint)DAT_00716464);
  }
  if (DAT_00716470 != (code *)0x0) {
    (*DAT_00716470)(param_2);
  }
  iStack_10 = 0;
  if (DAT_00716465 != 0) {
    iVar4 = (int)&DAT_007165ac - (int)param_1;
    iVar3 = (int)&DAT_0071655c - (int)param_1;
    iVar5 = (int)&DAT_00716594 - (int)param_1;
    do {
      puVar1 = *(undefined4 **)(iVar4 + (int)param_1);
      uVar2 = *(undefined4 *)(iVar3 + (int)param_1);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = *(undefined4 **)((int)param_1 + iVar5);
        (*(code *)*puVar1)(puVar1,param_2,uVar2,*param_1,0);
      }
      else {
        (*(code *)*puVar1)(puVar1,param_2,uVar2,DAT_0071653c);
        puVar1 = *(undefined4 **)((int)param_1 + iVar5);
        (*(code *)*puVar1)(puVar1,param_2,DAT_0071653c,*param_1,0);
      }
      iStack_10 = iStack_10 + 1;
      param_1 = param_1 + 1;
    } while (iStack_10 < (int)(uint)DAT_00716465);
  }
  return;
}


// ==== 0x656d69 FUN_00656d69

void FUN_00656d69(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 uStack_20;
  uint uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  int aiStack_18 [6];
  
  uStack_1f = 0;
  uStack_1b = 0;
  uStack_19 = 0;
  uStack_20 = 1;
  if (DAT_00716466 == '\0') {
    uVar4 = (uint)DAT_00716465;
    if (uVar4 != 0) {
      piVar6 = aiStack_18;
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar6 = *param_1;
        param_1 = param_1 + 1;
        piVar6 = piVar6 + 1;
      }
    }
    for (; 0 < param_2; param_2 = param_2 + -0x100) {
      iVar2 = 0x100;
      if (param_2 < 0x101) {
        iVar2 = param_2;
      }
      FUN_00656ad0(aiStack_18,iVar2);
      iVar2 = 0;
      if (DAT_00716465 != 0) {
        do {
          aiStack_18[iVar2] = aiStack_18[iVar2] + (uint)DAT_0071646c;
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)DAT_00716465);
      }
    }
  }
  else {
    iVar2 = *param_1;
    if (0 < param_2) {
      do {
        iVar5 = 0x100;
        if (param_2 < 0x101) {
          iVar5 = param_2;
        }
        iVar1 = 0;
        if (DAT_00716465 != 0) {
          iVar3 = DAT_00716574;
          do {
            aiStack_18[iVar1] = iVar3;
            iVar1 = iVar1 + 1;
            iVar3 = iVar3 + iVar5 * 2;
          } while (iVar1 < (int)(uint)DAT_00716465);
        }
        FUN_00656ad0(aiStack_18,iVar5);
        if (DAT_00716465 == 2) {
          uStack_20 = 1;
          uStack_1f = uStack_1f & 0xffffff00;
        }
        else if (DAT_00716465 == 4) {
          uStack_20 = 3;
          uStack_1f = CONCAT13(uStack_1f._3_1_,0x10200);
        }
        else if (DAT_00716465 == 6) {
          uStack_20 = 4;
          uStack_1f = 0x3050001;
          uStack_1b = CONCAT11(uStack_1b._1_1_,2);
        }
        FUN_0065b730(iVar5,DAT_00716465,&uStack_20,aiStack_18[0],iVar2);
        param_2 = param_2 + -0x100;
        iVar2 = iVar2 + (uint)DAT_00716465 * iVar5 * 2;
      } while (0 < param_2);
      return;
    }
  }
  return;
}


// ==== 0x656d70 FUN_00656d70

void FUN_00656d70(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 local_20;
  uint local_1f;
  undefined2 local_1b;
  undefined1 local_19;
  int local_18 [6];
  
  local_1f = 0;
  local_1b = 0;
  local_19 = 0;
  local_20 = 1;
  if (DAT_00716466 == '\0') {
    uVar4 = (uint)DAT_00716465;
    if (uVar4 != 0) {
      piVar6 = local_18;
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar6 = *param_1;
        param_1 = param_1 + 1;
        piVar6 = piVar6 + 1;
      }
    }
    for (; 0 < param_2; param_2 = param_2 + -0x100) {
      iVar2 = 0x100;
      if (param_2 < 0x101) {
        iVar2 = param_2;
      }
      FUN_00656ad0(local_18,iVar2);
      iVar2 = 0;
      if (DAT_00716465 != 0) {
        do {
          local_18[iVar2] = local_18[iVar2] + (uint)DAT_0071646c;
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)DAT_00716465);
      }
    }
  }
  else {
    iVar2 = *param_1;
    if (0 < param_2) {
      do {
        iVar5 = 0x100;
        if (param_2 < 0x101) {
          iVar5 = param_2;
        }
        iVar1 = 0;
        if (DAT_00716465 != 0) {
          iVar3 = DAT_00716574;
          do {
            local_18[iVar1] = iVar3;
            iVar1 = iVar1 + 1;
            iVar3 = iVar3 + iVar5 * 2;
          } while (iVar1 < (int)(uint)DAT_00716465);
        }
        FUN_00656ad0(local_18,iVar5);
        if (DAT_00716465 == 2) {
          local_20 = 1;
          local_1f = local_1f & 0xffffff00;
        }
        else if (DAT_00716465 == 4) {
          local_20 = 3;
          local_1f = CONCAT13(local_1f._3_1_,0x10200);
        }
        else if (DAT_00716465 == 6) {
          local_20 = 4;
          local_1f = 0x3050001;
          local_1b = CONCAT11(local_1b._1_1_,2);
        }
        FUN_0065b730(iVar5,DAT_00716465,&local_20,local_18[0],iVar2);
        param_2 = param_2 + -0x100;
        iVar2 = iVar2 + (uint)DAT_00716465 * iVar5 * 2;
      } while (0 < param_2);
      return;
    }
  }
  return;
}


// ==== 0x656ef0 FUN_00656ef0

void FUN_00656ef0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x2c) = param_2;
  *(uint *)(param_1 + 0x30) = (*(int *)(param_1 + 0x28) * param_2) / 1000 & 0xfffff0;
  return;
}


// ==== 0x656f20 FUN_00656f20

void FUN_00656f20(int param_1,undefined4 param_2,undefined4 param_3)

{
  float local_c;
  float local_8;
  float local_4;
  
  FUN_0065ba20(param_2,param_3,&local_c);
  local_c = local_c * 1.5258789e-05;
  local_8 = local_8 * 1.5258789e-05;
  local_4 = local_4 * 1.5258789e-05;
  (**(code **)(**(int **)(param_1 + 0x40) + 0x4c))
            (*(int **)(param_1 + 0x40),local_c,local_8,local_4,0);
  return;
}


// ==== 0x656f90 FUN_00656f90

void FUN_00656f90(float param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)param_1 + 0x44);
  if (piVar1 != (int *)0x0) {
    param_1 = (float)param_2 * 3.051851e-05;
    (**(code **)(*piVar1 + 0x10))(piVar1,&DAT_006aab48,1,0,0,&param_1,4);
  }
  return;
}


// ==== 0x656fc2 FUN_00656fc2

void __fastcall FUN_00656fc2(int param_1)

{
  (**(code **)(param_1 + 0x4c))();
  return;
}


// ==== 0x656fd0 FUN_00656fd0

void FUN_00656fd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)ROUND((float)param_2 * *(float *)(param_1 + 0x1c));
  iVar1 = (int)DAT_0071667a;
  if ((iVar2 < DAT_0071667a) || (iVar1 = DAT_0071667c, DAT_0071667c < iVar2)) {
    iVar2 = iVar1;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x44))(*(int **)(param_1 + 0x3c),iVar2);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x28) = iVar2;
    *(int *)(param_1 + 0x30) = (*(int *)(param_1 + 0x2c) * iVar2) / 1000;
  }
  return;
}


// ==== 0x657040 FUN_00657040

uint FUN_00657040(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &param_1;
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x10))(*(int **)(param_1 + 0x3c),puVar1,0);
  return (uint)puVar1 >> 1;
}


// ==== 0x657060 FUN_00657060

undefined4 FUN_00657060(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x24))(*(int **)(param_1 + 0x3c));
  return 1;
}


// ==== 0x657080 FUN_00657080

int FUN_00657080(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x10))(*(int **)(param_1 + 0x3c),0);
  iVar1 = (*(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x34)) + ((uint)&param_1 >> 1 & 0xffffff0);
  if (0x3fff < iVar1) {
    iVar1 = iVar1 + -0x4000;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x6570c0 FUN_006570c0

undefined1 * FUN_006570c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_EBX;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 **appuStack_30 [4];
  undefined4 *puStack_10;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  if (param_2 < 1) {
    return (undefined1 *)0x1;
  }
  if ((-1 < *(int *)(param_1 + 0x38)) &&
     (iVar1 = *(int *)(param_1 + 0x38) - param_2, *(int *)(param_1 + 0x38) = iVar1, iVar1 < 1)) {
    return (undefined1 *)0xffffffff;
  }
  appuStack_30[3] = (undefined4 **)0x0;
  appuStack_30[2] = (undefined4 **)auStack_c;
  appuStack_30[1] = (undefined4 **)auStack_4;
  appuStack_30[0] = &puStack_10;
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x2c))
            (*(int **)(param_1 + 0x3c),*(int *)(param_1 + 0x34) << 1,param_2 * 2,auStack_8);
  iVar1 = 0;
  do {
    puVar5 = puStack_10;
    if (*(int *)((int)appuStack_30 + iVar1 + 8) != 0) {
      puVar7 = *(undefined4 **)(param_1 + 8);
      if (puVar7 != (undefined4 *)0x0) {
        iVar2 = (*(code *)*puVar7)(puVar7,*(uint *)((int)appuStack_30 + iVar1) >> 1,unaff_EBX,
                                   puStack_10,*(undefined1 *)(param_1 + 0x1a));
        puVar7 = *(undefined4 **)((int)appuStack_30 + iVar1 + 8);
        uVar4 = *(uint *)((int)appuStack_30 + iVar1);
        if (iVar2 < 2) {
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar7 = 0;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
        }
        else {
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
        }
        if ((iVar2 < 0) && (*(int *)(param_1 + 0x38) < 0)) {
          *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x30);
        }
      }
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 8);
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x4c))
            (*(int **)(param_1 + 0x3c),appuStack_30[2],appuStack_30[0],appuStack_30[3],
             appuStack_30[1]);
  puVar6 = (undefined1 *)((int)appuStack_30[1] + *(int *)(param_1 + 0x34));
  *(undefined1 **)(param_1 + 0x34) = puVar6;
  if (0x3fff < (int)puVar6) {
    *(undefined1 **)(param_1 + 0x34) = puVar6 + -0x4000;
  }
  return (undefined1 *)appuStack_30[1];
}


// ==== 0x6571e0 FUN_006571e0

void FUN_006571e0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x44);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


// ==== 0x657220 FUN_00657220

undefined4 FUN_00657220(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EBP;
  int *unaff_ESI;
  undefined4 *puVar4;
  undefined2 uStack_98;
  undefined2 uStack_96;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined2 uStack_8c;
  undefined2 uStack_8a;
  undefined2 uStack_88;
  undefined4 auStack_84 [4];
  undefined2 *puStack_74;
  undefined4 local_60 [2];
  undefined2 uStack_58;
  undefined4 uStack_54;
  
  piVar1 = param_1 + 0x11;
  piVar2 = param_1 + 0xf;
  *piVar2 = 0;
  param_1[0x10] = 0;
  *piVar1 = 0;
  if (DAT_00716678 == 0) {
    local_60[0] = 0x60;
    (**(code **)(*(int *)*param_2 + 0x10))((int *)*param_2,local_60);
    DAT_0071667a = uStack_58;
    DAT_0071667c = uStack_54;
    DAT_00716678 = 1;
  }
  if (param_2[1] == 0) {
    puVar4 = auStack_84;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puStack_74 = &uStack_98;
    param_1[8] = 1;
    *param_1 = FUN_006570c0;
    param_1[0xe] = 0xffffffff;
    uStack_98 = 1;
    uStack_96 = 1;
    auStack_84[0] = 0x24;
    auStack_84[1] = 0x80b4;
    auStack_84[2] = 0x8000;
    uStack_94 = 0x5622;
    uStack_90 = 0xac44;
    uStack_8c = 2;
    uStack_8a = 0x10;
    uStack_88 = 0;
    iVar3 = (**(code **)(*(int *)*param_2 + 0xc))((int *)*param_2,auStack_84,piVar2,0);
    if (iVar3 != 0) {
      *piVar2 = 0;
      goto LAB_006573a6;
    }
  }
  else {
    param_1[8] = 0;
    param_1[9] = (int)*(char *)(param_2 + 3);
    iVar3 = (**(code **)(*(int *)*param_2 + 0x14))((int *)*param_2,param_2[1],piVar2);
    unaff_ESI = piVar1;
    if (iVar3 != 0) {
      *piVar2 = 0;
      goto LAB_006573a6;
    }
  }
  iVar3 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_006a6e40,unaff_EBP);
  if (iVar3 != 0) {
    *unaff_EBP = 0;
LAB_006573a6:
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
    }
    piVar1 = (int *)*unaff_ESI;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)*unaff_EBP;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar2 = (int *)*piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    return 0;
  }
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    iVar3 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_006a6e30,unaff_ESI);
    if (iVar3 != 0) {
      *unaff_ESI = 0;
      goto LAB_006573a6;
    }
  }
  param_1[7] = (float)*(ushort *)((int)param_2 + 10) * 0.00024414062;
  return 1;
}


// ==== 0x657410 FUN_00657410

undefined4 FUN_00657410(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 local_4 [4];
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar4 = 2;
  }
  else {
    uVar6 = 0;
    puVar5 = local_4;
    (**(code **)(**(int **)(param_1 + 0x3c) + 0x2c))
              (*(int **)(param_1 + 0x3c),0,*(int *)(param_1 + 0x30) << 1,puVar5,&param_1,0,0,0);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar2 + 0x30);
    uVar4 = 1;
    (**(code **)(**(int **)(iVar2 + 0x3c) + 0x4c))(*(int **)(iVar2 + 0x3c),puVar5,uVar6,0,0);
  }
  if (*(int *)(iVar2 + 0x24) != 0) {
    uVar4 = uVar4 | 1;
  }
  iVar3 = (**(code **)(**(int **)(iVar2 + 0x3c) + 0x30))(*(int **)(iVar2 + 0x3c),0,0,uVar4);
  if (iVar3 != 0) {
    piVar1 = *(int **)(iVar2 + 0x3c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
    }
    piVar1 = *(int **)(iVar2 + 0x44);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(iVar2 + 0x40);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(iVar2 + 0x3c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    return 0xffffffff;
  }
  return 0;
}


// ==== 0x6574d0 FUN_006574d0

void FUN_006574d0(int param_1)

{
  float fVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(short *)(param_1 + 4) * 0x8c;
  iVar5 = iVar4 + DAT_00713f48;
  sVar2 = *(short *)(iVar5 + 0x62);
  iVar6 = 0;
  fVar1 = *(float *)(iVar5 + 0x48);
  if (*(char *)(iVar4 + 0x23 + DAT_00713f48) != '\0') {
    psVar3 = (short *)(iVar5 + 4);
    do {
      FUN_006568a0((int)*psVar3,0,(float)(int)sVar2 * fVar1 * 3.051851e-05);
      iVar6 = iVar6 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar6 < (int)(uint)*(byte *)(iVar5 + 0x23));
  }
  return;
}


// ==== 0x657540 FUN_00657540

void FUN_00657540(byte *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  byte *pbVar3;
  
  fVar1 = *(float *)(param_1 + 0x1c);
  iVar2 = 0;
  if (*param_1 != 0) {
    pbVar3 = param_1 + 4;
    do {
      FUN_0065bab0((int)*(short *)pbVar3,(int)ROUND((float)param_2 * fVar1));
      iVar2 = iVar2 + 1;
      pbVar3 = pbVar3 + 2;
    } while (iVar2 < (int)(uint)*param_1);
  }
  return;
}


// ==== 0x657590 FUN_00657590

void FUN_00657590(byte *param_1,undefined4 param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    pbVar2 = param_1 + 4;
    do {
      FUN_0065bb50((int)*(short *)pbVar2,param_2);
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar2 + 2;
    } while (iVar1 < (int)(uint)*param_1);
  }
  return;
}


// ==== 0x6575d0 FUN_006575d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006575d0(byte *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = 0;
  fVar1 = (float)DAT_00713d9a * _K_HALF;
  if (*param_1 != 0) {
    pbVar3 = param_1 + 4;
    do {
      FUN_0065bb80((int)*(short *)pbVar3,(float)param_2 / fVar1);
      iVar2 = iVar2 + 1;
      pbVar3 = pbVar3 + 2;
    } while (iVar2 < (int)(uint)*param_1);
  }
  return;
}


// ==== 0x657630 FUN_00657630

void FUN_00657630(byte *param_1,undefined4 param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    pbVar2 = param_1 + 4;
    do {
      FUN_0065bc70((int)*(short *)pbVar2,param_2);
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar2 + 2;
    } while (iVar1 < (int)(uint)*param_1);
  }
  return;
}


// ==== 0x657669 FUN_00657669

uint __fastcall FUN_00657669(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint in_EAX;
  int unaff_EBX;
  char in_SF;
  char in_OF;
  
  if (in_OF == in_SF) {
    return in_EAX;
  }
  uVar1 = *(uint *)(unaff_EBX + -0x7cb9f73c);
  *param_2 = 0xe87cf13b;
  return in_EAX | uVar1;
}


// ==== 0x657670 FUN_00657670

void FUN_00657670(void)

{
  FUN_0065bd30();
  return;
}


// ==== 0x657690 FUN_00657690

undefined4 FUN_00657690(byte *param_1,ushort *param_2)

{
  short sVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  byte *pbVar5;
  ushort *puVar6;
  
  puVar3 = param_2;
  uVar2 = param_2[2];
  *param_1 = (byte)uVar2;
  iVar4 = 0;
  *(float *)(param_1 + 0x1c) = ((float)*param_2 * 16.0) / (float)DAT_00713d9a;
  if ((byte)uVar2 != 0) {
    puVar6 = param_2 + 0x16;
    pbVar5 = param_1 + 4;
    param_2 = param_2 + 0x2e;
    do {
      *(ushort *)(pbVar5 + 0xc) = *param_2;
      sVar1 = *(short *)(DAT_00713f48 + 4 + ((short)puVar3[1] * 0x46 + iVar4) * 2);
      *(short *)pbVar5 = sVar1;
      FUN_006565d0((int)sVar1,*(undefined1 *)((int)puVar3 + 5),*(int *)(puVar3 + 8) != 0,
                   *(undefined4 *)(puVar6 + -0xc),*(undefined4 *)puVar6,
                   *(undefined4 *)(puVar6 + 0xc),(char)puVar3[2],*(int *)(puVar3 + 8),
                   *(undefined4 *)(puVar3 + 4),*(undefined4 *)(puVar3 + 6),0,0,(char)puVar3[3],iVar4
                  );
      param_2 = param_2 + 1;
      iVar4 = iVar4 + 1;
      pbVar5 = pbVar5 + 2;
      puVar6 = puVar6 + 2;
    } while (iVar4 < (int)(uint)*param_1);
  }
  return 1;
}


// ==== 0x657770 FUN_00657770

undefined4 FUN_00657770(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    pbVar2 = param_1 + 4;
    do {
      FUN_00656790((int)*(short *)pbVar2);
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar2 + 2;
    } while (iVar1 < (int)(uint)*param_1);
  }
  return 0;
}


// ==== 0x6577a0 FUN_006577a0

void FUN_006577a0(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*param_1 != 0) {
    pbVar1 = param_1 + 4;
    do {
      FUN_006567e0((int)*(short *)pbVar1);
      SNDVOICEI_free((int)*(short *)pbVar1);
      iVar2 = iVar2 + 1;
      pbVar1 = pbVar1 + 2;
    } while (iVar2 < (int)(uint)*param_1);
  }
  return;
}


// ==== 0x6577e0 FUN_006577e0

void FUN_006577e0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar3 = 0;
  if (iVar2 != 0) {
    do {
      iVar1 = iVar2;
      iVar2 = iVar1;
      if (*(ushort *)(param_2 + 0x18) <= *(ushort *)(iVar1 + 0x18)) break;
      iVar2 = *(int *)(iVar1 + 8);
      iVar3 = iVar1;
    } while (iVar2 != 0);
  }
  *(int *)(param_2 + 8) = iVar2;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x10) = param_2;
  }
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = param_2;
    *(int *)(param_2 + 0x10) = iVar3;
    return;
  }
  *param_1 = param_2;
  return;
}


// ==== 0x657820 FUN_00657820

void FUN_00657820(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (param_2 != iVar1) {
    iVar2 = *(int *)(iVar1 + 8);
    while ((iVar2 != 0 && (iVar3 = *(int *)(iVar1 + 8), iVar3 != param_2))) {
      iVar2 = *(int *)(iVar3 + 8);
      iVar1 = iVar3;
    }
    iVar2 = *(int *)(iVar1 + 8);
    if ((iVar2 != 0) && (iVar2 == param_2)) {
      if (*(int *)(iVar2 + 8) != 0) {
        *(int *)(*(int *)(iVar2 + 8) + 0x10) = iVar1;
      }
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*(int *)(iVar1 + 8) + 8);
    }
    return;
  }
  *param_1 = *(int *)(iVar1 + 8);
  return;
}


// ==== 0x657870 FUN_00657870

undefined4 FUN_00657870(int param_1,int param_2,int param_3,int param_4)

{
  if (param_3 == 1) {
    if (param_4 == 1) {
      if (*(int *)(param_2 + 8) == 0) {
        *(int *)(param_1 + 0x10) = param_2;
        *(int *)(param_2 + 8) = param_1;
        *(undefined1 *)(param_2 + 0x1a) = 1;
        return 0;
      }
    }
    else if ((param_4 == 2) && (*(int *)(param_2 + 0xc) == 0)) {
      *(int *)(param_1 + 0x10) = param_2;
      *(int *)(param_2 + 0xc) = param_1;
      *(undefined1 *)(param_2 + 0x1a) = 1;
      return 0;
    }
  }
  else if (param_3 == 2) {
    if (param_4 == 1) {
      if (*(int *)(param_2 + 8) == 0) {
        *(int *)(param_1 + 0x14) = param_2;
        *(int *)(param_2 + 8) = param_1;
        *(undefined1 *)(param_2 + 0x1a) = 2;
        return 0;
      }
    }
    else if ((param_4 == 2) && (*(int *)(param_2 + 0xc) == 0)) {
      *(int *)(param_1 + 0x14) = param_2;
      *(int *)(param_2 + 0xc) = param_1;
      *(undefined1 *)(param_2 + 0x1a) = 2;
      return 0;
    }
  }
  return 0xffffffff;
}


// ==== 0x657910 FUN_00657910

void FUN_00657910(int param_1)

{
  if (*(int *)(*(short *)(param_1 + 2) * 0x110 + DAT_0071400c + 0x20) != 0) {
    FUN_0065b290();
    return;
  }
  return;
}


// ==== 0x657940 FUN_00657940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00657940(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  iStack_8 = 0;
  uStack_4 = 0;
  iVar3 = *(short *)(param_1 + 2) * 0x8c + DAT_00713f48;
  iStack_c = 0;
  iVar1 = *(short *)(param_1 + 2) * 0x110 + DAT_0071400c;
  if ((float)param_2 / ((float)*(ushort *)(iVar3 + 0x20) * _K_HALF) < _K_ONE) {
    if (*(int *)(iVar1 + 0x24) == 0) {
      uVar2 = FUN_00650fd0(0x28);
      *(undefined4 *)(iVar1 + 0x24) = uVar2;
      FUN_00659f30(uVar2);
      *(undefined2 *)(*(int *)(iVar1 + 0x24) + 0x18) = 2;
      FUN_006577e0(iVar1 + 0xe4,*(undefined4 *)(iVar1 + 0x24));
    }
    iStack_c = param_2 << 8;
    iStack_8 = (uint)*(ushort *)(iVar3 + 0x20) << 8;
    uStack_4 = 0x100;
    FUN_00659f60(*(undefined4 *)(iVar1 + 0x24),&iStack_c);
    return;
  }
  if (*(int *)(iVar1 + 0x24) != 0) {
    FUN_00657820(iVar1 + 0xe4,*(int *)(iVar1 + 0x24));
    FUN_006510d0(*(undefined4 *)(iVar1 + 0x24));
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  return;
}


// ==== 0x657a40 FUN_00657a40

void FUN_00657a40(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_8;
  int iStack_4;
  
  iVar1 = *(short *)(param_1 + 2) * 0x110 + DAT_0071400c;
  iVar3 = *(short *)(param_1 + 2) * 0x8c + DAT_00713f48;
  iStack_8 = 0;
  iStack_4 = 0;
  if (0 < param_2) {
    if (*(int *)(iVar1 + 0x28) == 0) {
      uVar2 = FUN_00650fd0(0x58);
      *(undefined4 *)(iVar1 + 0x28) = uVar2;
      FUN_0065bdb0(uVar2);
      *(undefined2 *)(*(int *)(iVar1 + 0x28) + 0x18) = 3;
      FUN_006577e0(iVar1 + 0xe4,*(undefined4 *)(iVar1 + 0x28));
    }
    iStack_8 = param_2 << 8;
    iStack_4 = (uint)*(ushort *)(iVar3 + 0x20) << 8;
    FUN_0065bde0(*(undefined4 *)(iVar1 + 0x28),&iStack_8);
    return;
  }
  if (*(int *)(iVar1 + 0x28) != 0) {
    FUN_00657820(iVar1 + 0xe4,*(int *)(iVar1 + 0x28));
    FUN_006510d0(*(undefined4 *)(iVar1 + 0x28));
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  return;
}


// ==== 0x657b20 FUN_00657b20

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


// ==== 0x657b50 FUN_00657b50

undefined4 FUN_00657b50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  iVar5 = *(short *)(param_2 + 2) * 0x110 + DAT_0071400c;
  *(undefined4 *)(iVar5 + 0xe4) = 0;
  *(undefined4 *)(iVar5 + 0x18) = 0;
  *(undefined4 *)(iVar5 + 0x1c) = 0;
  *(undefined4 *)(iVar5 + 0x20) = 0;
  *(undefined4 *)(iVar5 + 0x24) = 0;
  *(undefined4 *)(iVar5 + 0x28) = 0;
  iVar4 = (int)*(short *)(param_2 + 2);
  iVar1 = iVar5 + 0xe4;
  iVar2 = FUN_0065be20(*(undefined4 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 5),
                       *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                       *(undefined1 *)(param_2 + 4),*(undefined4 *)(param_2 + 0x10),iVar4,
                       *(undefined1 *)(param_2 + 6),param_1 + 4);
  *(int *)(iVar5 + 0x18) = iVar2;
  *(undefined2 *)(iVar2 + 0x18) = 5;
  FUN_006577e0(iVar1,*(undefined4 *)(iVar5 + 0x18));
  uVar3 = FUN_00650fd0(0x1c);
  *(undefined4 *)(iVar5 + 0x1c) = uVar3;
  FUN_0065b470(uVar3);
  *(undefined2 *)(*(int *)(iVar5 + 0x1c) + 0x18) = 1;
  FUN_006577e0(iVar1,*(undefined4 *)(iVar5 + 0x1c));
  if (*(int *)(param_2 + 0x18) != 0) {
    if (*(int *)(param_2 + 0x10) != 0) {
      iVar4 = -1;
    }
    uVar3 = FUN_00650fd0(0x1828);
    *(undefined4 *)(iVar5 + 0x20) = uVar3;
    FUN_0065b380(uVar3,*(undefined4 *)(param_2 + 0x18),iVar4);
    *(undefined2 *)(*(int *)(iVar5 + 0x20) + 0x18) = 4;
    FUN_006577e0(iVar1,*(undefined4 *)(iVar5 + 0x20));
  }
  return 1;
}


// ==== 0x657c50 FUN_00657c50

void FUN_00657c50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(short *)(param_1 + 2) * 0x110;
  iVar3 = iVar2 + DAT_0071400c;
  if (*(int *)(iVar2 + 0xe4 + DAT_0071400c) != 0) {
    do {
      iVar2 = *(int *)(iVar3 + 0xe4);
      iVar1 = *(int *)(iVar2 + 8);
      if ((iVar2 != iVar3 + 0x2c) && (iVar2 != iVar3 + 0x74)) {
        if (*(code **)(iVar2 + 4) != (code *)0x0) {
          (**(code **)(iVar2 + 4))(iVar2);
        }
        FUN_006510d0(*(undefined4 *)(iVar3 + 0xe4));
        *(undefined4 *)(iVar3 + 0xe4) = 0;
      }
      *(int *)(iVar3 + 0xe4) = iVar1;
    } while (iVar1 != 0);
  }
  *(undefined4 *)(iVar3 + 0xe4) = 0;
  return;
}


// ==== 0x657cd0 FUN_00657cd0

uint FUN_00657cd0(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int local_a4 [3];
  uint local_98;
  _OSVERSIONINFOA local_94;
  
  bVar1 = false;
  local_94.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_94);
  uVar3 = 1;
  if ((local_94.dwPlatformId == 1) && (local_94.dwMinorVersion == 0)) {
    bVar1 = true;
  }
  iVar2 = FUN_0065bf50();
  if (iVar2 != 0) {
    FUN_0065bf6d(local_a4,0);
    if (local_a4[0] != 0) {
      FUN_0065bf6d(local_a4,1);
      if (((local_98 & 0x2000000) != 0) && (!bVar1)) {
        uVar3 = 3;
      }
      FUN_0065bf6d(local_a4,0x80000001);
      if ((int)local_98 < 0) {
        uVar3 = uVar3 | 4;
      }
    }
  }
  return uVar3;
}


// ==== 0x657d70 SNDBANKI_findfreekey

/* [canon] audio high (ghidra) docs/re/sound.md */

char SNDBANKI_findfreekey(void)

{
  char *pcVar1;
  int iVar2;
  
  do {
    DAT_00716680 = DAT_00716680 + '\x01';
    if (DAT_00716680 == '\0') {
      DAT_00716680 = '\x01';
    }
    iVar2 = 0;
    pcVar1 = (char *)(DAT_00713f48 + 0x26);
    while( true ) {
      if (DAT_00713ee8 <= iVar2) {
        return DAT_00716680;
      }
      if ((pcVar1[0x43] != '\0') && (*pcVar1 == DAT_00716680)) break;
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0x8c;
    }
  } while( true );
}


// ==== 0x657dd0 SNDBANKI_playtimbre

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4
SNDBANKI_playtimbre(undefined2 param_1,undefined2 param_2,undefined4 param_3,char *param_4,
                   int param_5,short param_6,int param_7,int param_8)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  float fStack_14;
  int iStack_10;
  undefined *puStack_c;
  int iStack_8;
  int iStack_4;
  
  iStack_18 = (int)param_4[1];
  iStack_8 = (int)param_4[5];
  uStack_24 = 0;
  while( true ) {
    uStack_2c = 0xfffffff7;
    do {
      iStack_10 = FUN_00659a70(&uStack_24,param_5);
      if (iStack_10 == 0) {
        return uStack_2c;
      }
      FUN_00651a00(iStack_10,&uStack_1c,&uStack_20);
      iStack_28 = FUN_00652270((int)*(char *)(param_5 + 3),(int)*(char *)(param_5 + 0xc),&uStack_2c,
                               uStack_1c,uStack_20);
    } while (iStack_28 < 0);
    iVar8 = (int)*(char *)(param_5 + 0x11);
    iStack_4 = iStack_28 * 0x8c;
    iVar11 = iStack_4 + DAT_00713f48;
    if (*(char *)(param_5 + 0x12) != '\0') {
      iVar6 = FUN_0065c070((int)*(char *)(param_5 + 0x12));
      iVar8 = iVar8 + iVar6;
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (0x7f < iVar8) {
        iVar8 = 0x7f;
      }
    }
    uVar4 = SNDI_pantoazimuth(iVar8);
    *(undefined2 *)(iVar11 + 0x4c) = uVar4;
    sVar5 = *(short *)(param_5 + 4);
    *(short *)(iVar11 + 0x84) = sVar5;
    sVar5 = sVar5 + (param_6 - *(char *)(param_5 + 0xd)) * 100;
    *(short *)(iVar11 + 0x84) = sVar5;
    if (param_8 != 0) {
      *(short *)(iVar11 + 0x84) = sVar5 + (short)param_8;
    }
    if (*(short *)(param_5 + 6) != 0) {
      sVar5 = FUN_0065c070((int)*(short *)(param_5 + 6));
      *(short *)(iVar11 + 0x84) = *(short *)(iVar11 + 0x84) + sVar5;
    }
    *(undefined4 *)(iVar11 + 0x74) = *(undefined4 *)(param_5 + 0x24);
    iVar8 = (int)*(char *)(param_5 + 0x14);
    if (*(char *)(param_5 + 0x15) != '\0') {
      iVar6 = FUN_0065c070((int)*(char *)(param_5 + 0x15));
      iVar8 = iVar8 + iVar6;
    }
    if (iVar8 < 0x80) {
      if (iVar8 < 0) {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 0x7f;
    }
    puStack_c = (undefined *)((iVar8 * param_7) / 0x7f);
    *(short *)(iVar11 + 0x82) = *(char *)(param_5 + 0x10) * 100;
    *(undefined1 *)(iVar11 + 100) = (undefined1)iStack_18;
    piVar3 = *(int **)(param_5 + 0x28);
    *(int **)(iVar11 + 0x6c) = piVar3;
    *(int *)(iVar11 + 0x40) = (int)*(char *)(param_5 + 0x1a) << 0x10;
    iVar8 = *piVar3;
    iVar6 = 0;
    *(int *)(iVar11 + 0x44) = iVar8;
    if (iVar8 < 0) {
      *(undefined4 *)(iVar11 + 0x44) = 0x7fffffff;
    }
    *(int *)(iVar11 + 0x3c) =
         (piVar3[1] * 0x10000 - *(int *)(iVar11 + 0x40)) / *(int *)(iVar11 + 0x44);
    *(undefined4 *)(iVar11 + 0x7c) = *(undefined4 *)(param_5 + 0x30);
    *(undefined1 *)(iVar11 + 0x66) = *(undefined1 *)(param_5 + 0x1d);
    *(undefined2 *)(iVar11 + 0x80) = *(undefined2 *)(param_5 + 0x54);
    if (*(char *)(param_5 + 0x1c) == '\0') {
      *(undefined1 *)(iVar11 + 0x67) = 0;
    }
    else {
      uVar7 = iSNDrandom();
      *(char *)(iVar11 + 0x67) = (char)(uVar7 % (uint)(int)*(char *)(param_5 + 0x1c));
    }
    if (*(char *)(param_5 + 0x1e) == '\0') {
      *(undefined1 *)(iVar11 + 0x68) = 0;
    }
    else {
      uVar7 = iSNDrandom();
      *(char *)(iVar11 + 0x68) = (char)(uVar7 % (uint)*(byte *)(param_5 + 0x1d));
    }
    *(undefined2 *)(iVar11 + 0x6a) = *(undefined2 *)(param_4 + 0xe);
    *(undefined2 *)(iVar11 + 0x88) = *(undefined2 *)(param_4 + 0xc);
    *(undefined2 *)(iVar11 + 0x86) = 0;
    iSNDcalcpitch(iStack_28);
    *(undefined2 *)(iVar11 + 0x12) = param_1;
    *(undefined2 *)(iVar11 + 0x10) = param_2;
    *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(param_5 + 0x60);
    *(undefined4 *)(iVar11 + 0x14) = *(undefined4 *)(param_5 + 0x58);
    *(undefined2 *)(iVar11 + 0x20) = *(undefined2 *)(param_5 + 0x56);
    *(undefined1 *)(iVar11 + 0x22) = *(undefined1 *)(param_5 + 0x13);
    *(undefined1 *)(iVar11 + 0x23) = *(undefined1 *)(param_5 + 3);
    iVar8 = (int)*(char *)(param_5 + 3);
    fStack_14 = (float)(int)*param_4 * 0.007874016;
    if (0 < iVar8) {
      do {
        *(short *)(iVar11 + 0x50 + iVar6 * 2) =
             *(short *)(param_5 + 0xbc + iVar6 * 2) -
             *(short *)(&DAT_00713f70 + (iVar6 + iVar8 * 6) * 2);
        iVar8 = (int)*(short *)(iVar11 + 4 + iVar6 * 2);
        iVar10 = iVar8 * 0x8c + DAT_00713f48;
        *(undefined2 *)(iVar10 + 0x24) = (undefined2)iStack_10;
        *(undefined1 *)(iVar10 + 0x2b) = puStack_c._0_1_;
        *(char *)(iVar10 + 0x5f) = param_4[4];
        *(float *)(iVar10 + 0x38) = fStack_14;
        *(undefined4 *)(iVar10 + 0x70) = *(undefined4 *)(param_5 + 0x20);
        *(undefined4 *)(iVar10 + 0x30) = 0;
        *(undefined1 *)(iVar10 + 0x5c) = *(undefined1 *)(param_5 + 0xf);
        *(undefined1 *)(iVar10 + 0x5e) = *(undefined1 *)(param_5 + 0xe);
        *(undefined1 *)(iVar10 + 0x5d) = 0;
        *(undefined4 *)(iVar10 + 0x40) = *(undefined4 *)(iVar11 + 0x40);
        *(undefined4 *)(iVar10 + 0x44) = *(undefined4 *)(iVar11 + 0x44);
        *(undefined4 *)(iVar10 + 0x3c) = *(undefined4 *)(iVar11 + 0x3c);
        *(undefined4 *)(iVar10 + 0x6c) = *(undefined4 *)(iVar11 + 0x6c);
        *(undefined1 *)(iVar10 + 0x65) = *(undefined1 *)(param_5 + 0x1b);
        *(undefined1 *)(iVar10 + 0x67) = *(undefined1 *)(iVar11 + 0x67);
        *(undefined4 *)(iVar10 + 0x78) = *(undefined4 *)(param_5 + 0x2c);
        iSNDcalcvol(iVar8);
        *(bool *)(iVar10 + 0x4e) = iVar6 == 5;
        iVar8 = (int)*(char *)(param_5 + 3);
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar8);
    }
    iVar8 = iStack_28;
    cVar1 = *(char *)(param_5 + 3);
    if (cVar1 == '\x01') {
      *(short *)(iVar11 + 0x1c) =
           *(short *)(iVar11 + 0x50) + *(short *)(param_4 + 8) + *(short *)(iVar11 + 0x4c);
      *(undefined2 *)(iVar11 + 0x1e) = *(undefined2 *)(param_4 + 10);
    }
    else {
      puStack_c = &DAT_006aaa32 + ((int)cVar1 + DAT_00713ce0 * 6) * 6;
      iVar6 = 0;
      if (0 < cVar1) {
        psVar9 = (short *)(iVar11 + 0x50);
        do {
          iVar10 = psVar9[-0x26] * 0x8c + DAT_00713f48;
          bVar2 = puStack_c[iVar6];
          *(ushort *)(iVar10 + 0x1c) = (ushort)bVar2 * 0x100;
          *(ushort *)(iVar10 + 0x1c) = *psVar9 + (ushort)bVar2 * 0x100;
          *(undefined2 *)(iVar10 + 0x1e) = 0;
          iVar6 = iVar6 + 1;
          psVar9 = psVar9 + 1;
        } while (iVar6 < *(char *)(param_5 + 3));
      }
    }
    *(undefined1 *)(iVar11 + 0x60) = *(undefined1 *)(param_5 + 0x16);
    *(undefined1 *)(iVar11 + 0x61) = (undefined1)iStack_8;
    SNDI_calcfxlevel(0,iStack_28);
    iVar8 = SNDPLATFORM_playtimbre
                      (param_5,param_3,iVar8,*(undefined2 *)(param_4 + 0xe),
                       *(undefined2 *)(param_4 + 0x12),*(undefined2 *)(param_4 + 0x14),
                       *(undefined2 *)(param_4 + 0x16));
    if (-1 < iVar8) break;
    iVar8 = 0;
    if ('\0' < *(char *)(param_5 + 3)) {
      iVar11 = iStack_4 + 4;
      do {
        SNDVOICEI_free((int)*(short *)(iVar11 + DAT_00713f48));
        iVar8 = iVar8 + 1;
        iVar11 = iVar11 + 2;
      } while (iVar8 < *(char *)(param_5 + 3));
    }
  }
  return uStack_2c;
}


// ==== 0x658230 SNDBANKI_playpatch

/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDBANKI_playpatch(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_114;
  int iStack_110;
  undefined4 uStack_10c;
  int aiStack_fc [12];
  short asStack_cc [4];
  char cStack_c4;
  char cStack_c3;
  char cStack_c2;
  char cStack_c1;
  
  iVar6 = param_5;
  iVar7 = 0;
  iStack_110 = 0;
  bVar1 = false;
  uStack_10c = 0;
  iStack_114 = -9;
  if (param_2 == 0) {
    return -8;
  }
  if (param_1 == 0) {
    param_1 = param_2;
  }
  iVar4 = (int)*(char *)(param_5 + 3);
  param_2 = param_2 + 4;
  iVar5 = (int)*(char *)(param_5 + 2);
  uVar2 = SNDBANKI_findfreekey();
  do {
    iVar3 = SNDI_parsetimbre(&param_2,asStack_cc);
    if (!bVar1) {
      if (asStack_cc[0] != 0) {
        uStack_10c = FUN_0065c070((int)asStack_cc[0]);
      }
      bVar1 = true;
    }
    if ((((cStack_c4 <= iVar4) && (iVar4 <= cStack_c3)) && (cStack_c2 <= iVar5)) &&
       (iVar5 <= cStack_c1)) {
      iStack_114 = SNDBANKI_playtimbre(param_3,param_4,param_1,iVar6,asStack_cc,iVar5,iVar4,
                                       uStack_10c);
      if (iStack_114 < 0) goto LAB_00658389;
      aiStack_fc[iVar7] = iStack_114;
      iVar7 = iVar7 + 1;
      SNDBANKI_userdatacallback(asStack_cc,1);
    }
  } while (iVar3 != 0);
  iVar4 = 0;
  iVar6 = 0;
  if (0 < iVar7) {
    do {
      iVar5 = aiStack_fc[iVar6];
      iVar3 = SNDover__is_sound_finished_(iVar5);
      if (iVar3 == 0) {
        aiStack_fc[iVar4] = iVar5;
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar7);
    if (iVar4 != 0) {
      if (iVar4 != 1) {
        iVar6 = 0;
        if (0 < iVar4) {
          do {
            iVar7 = SNDVOICEI_get__validate_handle____voice_index_(aiStack_fc[iVar6]);
            if (-1 < iVar7) {
              iStack_110 = iVar7 * 0x8c + DAT_00713f48;
              *(undefined1 *)(iStack_110 + 0x26) = uVar2;
              *(undefined1 *)(iStack_110 + 0x27) = 0;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar4);
        }
        *(undefined1 *)(iStack_110 + 0x27) = 1;
        return iStack_114;
      }
      iVar6 = SNDVOICEI_get__validate_handle____voice_index_(aiStack_fc[0]);
      if (iVar6 < 0) {
        return iStack_114;
      }
      iVar6 = iVar6 * 0x8c + DAT_00713f48;
      *(undefined1 *)(iVar6 + 0x26) = 0;
      *(undefined1 *)(iVar6 + 0x27) = 0;
      return iStack_114;
    }
  }
  iVar7 = 0;
LAB_00658389:
  iVar6 = 0;
  if (iVar7 < 1) {
    return iStack_114;
  }
  do {
    SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
              (aiStack_fc[iVar6]);
    iVar6 = iVar6 + 1;
  } while (iVar6 < iVar7);
  return iStack_114;
}


// ==== 0x658440 FUN_00658440

int FUN_00658440(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00713d98 != 0) {
    do {
      if (*(int *)(DAT_00713f4c + iVar1 * 8) == 0) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)DAT_00713d98);
  }
  return -9;
}


// ==== 0x658470 FUN_00658470

int FUN_00658470(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < (int)(uint)*(ushort *)(param_1 + 6)) &&
     (iVar1 = *(int *)(param_1 + 0x14 + param_2 * 4), iVar1 != 0)) {
    return iVar1 + 0x14 + param_2 * 4 + param_1;
  }
  return 0;
}


// ==== 0x6584a0 FUN_006584a0

uint FUN_006584a0(int param_1)

{
  if (((-1 < param_1) && (param_1 < (int)(uint)DAT_00713d98)) &&
     (*(int *)(DAT_00713f4c + param_1 * 8) != 0)) {
    return -(uint)(*(char *)(DAT_00713f4c + 4 + param_1 * 8) != '\0') & 0xffffffee;
  }
  return 0xfffffff8;
}


// ==== 0x6584e0 iSNDpatchkey

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 iSNDpatchkey(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  cVar1 = *(char *)(param_1 * 0x8c + 0x26 + DAT_00713f48);
  if (cVar1 == '\0') {
    if (*param_2 < 0) {
      *param_2 = param_1;
      return 1;
    }
  }
  else {
    iVar2 = *param_2;
    *param_2 = iVar2 + 1;
    if (iVar2 + 1 < (int)DAT_00713ee8) {
      do {
        piVar3 = (int *)(*param_2 * 0x8c + DAT_00713f48);
        if (((*(char *)((int)piVar3 + 0x26) == cVar1) && (*(char *)((int)piVar3 + 0x69) == '\x01'))
           && (-1 < *piVar3)) {
          return 1;
        }
        iVar2 = *param_2;
        *param_2 = iVar2 + 1;
      } while (iVar2 + 1 < (int)DAT_00713ee8);
    }
  }
  return 0;
}


// ==== 0x658570 FUN_00658570

undefined4 FUN_00658570(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_30 [6];
  int local_18 [6];
  
  iVar2 = param_1;
  cVar1 = *(char *)(param_1 + 3);
  iVar3 = 0;
  if (0 < cVar1) {
    piVar6 = (int *)(param_1 + 0x80);
    do {
      local_18[iVar3] = piVar6[-6] + param_2;
      if (*piVar6 == 0) {
        local_30[iVar3] = 0;
      }
      else {
        local_30[iVar3] = *(int *)(param_1 + 0x68) + *piVar6 + param_2;
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < cVar1);
  }
  param_1 = 0;
  uVar4 = FUN_00659a70(&param_1,iVar2);
  while (uVar4 != 0) {
    if (((uVar4 & 1) != 0) && (*(char *)(iVar2 + 3) == '\x01')) {
      iVar3 = FUN_00653fa0(*(undefined4 *)(iVar2 + 200));
      iVar5 = FUN_00654540(*(undefined1 *)(iVar2 + 0x13),*(undefined2 *)(iVar2 + 0x56),
                           *(undefined4 *)(iVar2 + 0x58),*(undefined4 *)(iVar2 + 0x5c),
                           *(undefined4 *)(iVar2 + 0x60),(int)*(char *)(iVar2 + 2),local_18[0],
                           local_30[0]);
      *(int *)(iVar3 + 4) = iVar5;
      if (iVar5 == 0) {
        FUN_00653fe0(*(undefined4 *)(iVar2 + 200));
      }
    }
    uVar4 = FUN_00659a70(&param_1,iVar2);
  }
  return 8;
}


// ==== 0x658660 FUN_00658660

undefined4 FUN_00658660(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00654010(*(undefined4 *)(param_1 + 200));
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    FUN_00653fe0(*(undefined4 *)(param_1 + 200));
    uVar2 = FUN_00653db0();
    return uVar2;
  }
  return 0;
}


// ==== 0x6586b0 SNDI_parsetimbre

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDI_parsetimbre(undefined4 *param_1,undefined2 *param_2)

{
  short *psVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  short *psVar7;
  undefined4 uVar8;
  undefined4 auStack_41c [68];
  undefined4 uStack_30c;
  undefined4 *puStack_308;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0 [7];
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8 [2];
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  int local_280;
  undefined4 local_27c;
  int local_26c;
  undefined *local_264;
  undefined4 local_260;
  undefined4 local_258;
  int local_254;
  undefined4 local_250;
  undefined4 local_24c;
  int local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_214;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1ec;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_164 [18];
  int local_11c;
  int local_108;
  int local_100;
  int local_f0;
  int local_e4;
  undefined4 local_b8 [10];
  undefined4 local_90;
  
  local_2e0[1] = 0;
  local_2e0[2] = 0;
  local_2e0[3] = 0;
  local_2e0[4] = 0;
  local_2e0[5] = 0;
  local_2f4 = *param_1;
  *(undefined4 *)(param_2 + 100) = local_2f4;
  puVar3 = local_164;
  for (iVar5 = 0x2b; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = local_b8;
  for (iVar5 = 0x2e; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar5 = 6;
  puVar3 = (undefined4 *)(param_2 + 0x4c);
  puVar6 = param_2 + 0x58;
  do {
    *puVar3 = 0;
    *puVar6 = 0;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar8 = 0;
  local_2c0 = 0x7f;
  local_2b8[0] = 0x7f;
  local_290 = 0x7f;
  local_258 = 0x7f;
  puStack_308 = &local_2f4;
  local_2c4 = 0;
  local_2bc = 0;
  local_2b0 = 0;
  local_2ac = 0x3c;
  local_2a8 = 0xffffffff;
  local_2a4 = 1;
  local_2a0 = 0;
  local_298 = 0x40;
  local_294 = 0;
  local_28c = 0;
  local_288 = 0;
  local_284 = 0;
  local_280 = 0;
  local_27c = 0;
  *(undefined1 *)((int)param_2 + 0x17) = 0;
  local_26c = 0;
  local_264 = &DAT_006ea050;
  local_260 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  local_220 = 0;
  local_254 = 0;
  local_250 = 0;
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  local_238 = 0;
  local_234 = 1;
  local_21c = 0;
  local_214 = 1;
  local_20c = 0x5622;
  local_208 = 0;
  local_204 = 0xffffffff;
  local_200 = 0xffffffff;
  local_1fc = 0;
  local_1ac = 0;
  local_1f8 = 0;
  local_1a8 = 0;
  local_1cc = 0;
  local_1a4 = 0;
  local_1c8 = 0;
  local_1a0 = 0;
  local_194 = 0;
  local_184 = 0;
  local_190 = 0;
  local_180 = 0;
  local_19c = 10;
  local_1ec = 0;
  uStack_30c = 0x6588be;
  iVar4 = SNDI_gettag();
  iVar5 = local_2f0;
  uVar2 = local_2e8;
  do {
    if (iVar4 == 0) {
LAB_00658a04:
      *(undefined1 *)(param_2 + 4) = (undefined1)local_2c4;
      *(undefined1 *)((int)param_2 + 9) = (undefined1)local_2c0;
      *(undefined1 *)((int)param_2 + 0xb) = (undefined1)local_2b8[0];
      *(undefined1 *)(param_2 + 6) = (undefined1)local_2b0;
      *(undefined1 *)(param_2 + 7) = (undefined1)local_2a8;
      *(undefined1 *)(param_2 + 5) = (undefined1)local_2bc;
      *(undefined1 *)((int)param_2 + 0xf) = (undefined1)local_2a4;
      *(undefined1 *)((int)param_2 + 0x11) = (undefined1)local_298;
      *(undefined1 *)((int)param_2 + 0xd) = (undefined1)local_2ac;
      *(undefined1 *)(param_2 + 9) = (undefined1)local_294;
      *(undefined1 *)((int)param_2 + 0x15) = (undefined1)local_28c;
      *(undefined1 *)(param_2 + 8) = (undefined1)local_2a0;
      param_2[2] = (undefined2)local_288;
      *(undefined1 *)(param_2 + 10) = (undefined1)local_290;
      *(int *)(param_2 + 0x10) = local_11c + local_280;
      param_2[3] = (undefined2)local_284;
      *(undefined1 *)(param_2 + 0xb) = (undefined1)local_27c;
      *(int *)(param_2 + 0x12) = local_108 + local_26c;
      *(undefined **)(param_2 + 0x14) = local_264 + local_100;
      *(undefined4 *)(param_2 + 0x40) = local_260;
      *(undefined4 *)(param_2 + 0x42) = local_230;
      *(undefined4 *)(param_2 + 0x44) = local_22c;
      *(undefined4 *)(param_2 + 0x46) = local_228;
      *(undefined4 *)(param_2 + 0x48) = local_224;
      *(undefined4 *)(param_2 + 0x4a) = local_220;
      *(undefined1 *)(param_2 + 0xd) = (undefined1)local_258;
      *(undefined1 *)((int)param_2 + 0x1b) = (undefined1)local_250;
      *(int *)(param_2 + 0x16) = local_f0 + local_254;
      *(undefined1 *)(param_2 + 0xe) = (undefined1)local_24c;
      *(int *)(param_2 + 0x18) = local_e4 + local_248;
      *(undefined1 *)((int)param_2 + 0x1d) = (undefined1)local_244;
      param_2[0x2a] = (undefined2)local_240;
      *(undefined1 *)(param_2 + 0xf) = (undefined1)local_23c;
      *param_2 = (undefined2)local_238;
      *(undefined1 *)((int)param_2 + 0x1f) = (undefined1)local_234;
      *(undefined1 *)((int)param_2 + 0x13) = (undefined1)local_19c;
      *(undefined1 *)(param_2 + 1) = (undefined1)local_21c;
      *(undefined4 *)(param_2 + 0x2c) = local_208;
      param_2[0x2b] = (undefined2)local_20c;
      *(undefined4 *)(param_2 + 0x30) = local_200;
      *(undefined4 *)(param_2 + 0x2e) = local_204;
      *(undefined4 *)(param_2 + 0x32) = local_90;
      param_2[0xc] = (undefined2)local_1ec;
      local_2e0[0] = local_1ac;
      *(undefined4 *)(param_2 + 0x34) = local_1fc;
      local_2e0[1] = local_1a8;
      *(undefined4 *)(param_2 + 0x36) = local_1f8;
      local_2e0[2] = local_1a4;
      *(undefined4 *)(param_2 + 0x38) = local_1cc;
      local_2e0[3] = local_1a0;
      *(undefined4 *)(param_2 + 0x3a) = local_1c8;
      local_2e0[4] = local_184;
      *(undefined4 *)(param_2 + 0x3c) = local_194;
      local_2e0[5] = local_180;
      iVar5 = 0;
      *(char *)((int)param_2 + 3) = (char)local_214;
      *(undefined4 *)(param_2 + 0x3e) = local_190;
      if ('\0' < (char)local_214) {
        psVar7 = param_2 + 0x5e;
        do {
          if ((DAT_00713ce0 == 1) && (*(char *)((int)param_2 + 3) == '\x02')) {
            local_2e0[iVar5] = 0;
          }
          iVar4 = iVar5 + *(char *)((int)param_2 + 3) * 6;
          psVar1 = (short *)(local_2e0 + iVar5);
          iVar5 = iVar5 + 1;
          *psVar7 = *(short *)(&DAT_00713f70 + iVar4 * 2) + *psVar1;
          psVar7 = psVar7 + 1;
        } while (iVar5 < *(char *)((int)param_2 + 3));
        *param_1 = local_2f4;
        return uVar8;
      }
      *param_1 = local_2f4;
      return uVar8;
    }
    local_2f0 = iVar5;
    local_2e8 = uVar2;
    if (iVar5 < 0x2b) {
      local_2e0[iVar5 + 6] = local_2ec;
      local_164[iVar5] = uVar2;
      if (iVar5 == 0x14) {
        *(undefined4 *)(param_2 + *(char *)((int)param_2 + 0x17) * 2 + 0x1a) = uVar2;
        *(undefined4 *)(param_2 + *(char *)((int)param_2 + 0x17) * 2 + 0x22) = local_2e4;
        *(char *)((int)param_2 + 0x17) = *(char *)((int)param_2 + 0x17) + '\x01';
      }
    }
    else if ((iVar5 < 0x80) || (0xad < iVar5)) {
      if (iVar5 == 0xfe) {
        uVar8 = 1;
        goto LAB_00658a04;
      }
    }
    else {
      auStack_41c[iVar5] = local_2ec;
      local_2b8[iVar5] = uVar2;
      if (iVar5 == 0x98) {
        *(undefined4 *)(param_2 + 0x4c) = uVar2;
        param_2[0x58] = (undefined2)local_2e4;
      }
      else if (iVar5 == 0x99) {
        *(undefined4 *)(param_2 + 0x4e) = uVar2;
        param_2[0x59] = (undefined2)local_2e4;
      }
      else if (iVar5 == 0x9a) {
        *(undefined4 *)(param_2 + 0x50) = uVar2;
        param_2[0x5a] = (undefined2)local_2e4;
      }
      else if (iVar5 == 0x9b) {
        *(undefined4 *)(param_2 + 0x52) = uVar2;
        param_2[0x5b] = (undefined2)local_2e4;
      }
      else if (iVar5 == 0xa4) {
        *(undefined4 *)(param_2 + 0x54) = uVar2;
        param_2[0x5c] = (undefined2)local_2e4;
      }
      else if (iVar5 == 0xa5) {
        *(undefined4 *)(param_2 + 0x56) = uVar2;
        param_2[0x5d] = (undefined2)local_2e4;
      }
    }
    puStack_308 = &local_2f4;
    uStack_30c = 0x6589f2;
    iVar4 = SNDI_gettag();
    iVar5 = local_2f0;
    uVar2 = local_2e8;
  } while( true );
}


// ==== 0x658ce0 thunk_FUN_0064e8e0

void thunk_FUN_0064e8e0(void)

{
  FUN_0064e8e0();
  return;
}


// ==== 0x658cf0 FUN_00658cf0

undefined4 FUN_00658cf0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = -1;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      *(short *)(local_4 * 0x8c + 0x6a + DAT_00713f48) = (short)param_2;
      FUN_006512c0(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return 0;
}


// ==== 0x658d80 FUN_00658d80

int FUN_00658d80(undefined4 param_1,short param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  if (param_3 < -0x4000) {
    param_3 = -0x4000;
  }
  else if (0x3fff < param_3) {
    param_3 = 0x3fff;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = -1;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      iVar2 = local_4 * 0x8c + DAT_00713f48;
      if (*(char *)(local_4 * 0x8c + 0x23 + DAT_00713f48) == '\x01') {
        *(short *)(iVar2 + 0x1e) = (short)param_3;
        *(short *)(iVar2 + 0x1c) = *(short *)(iVar2 + 0x50) + *(short *)(iVar2 + 0x4c) + param_2;
        if (DAT_00713ce0 == 0) {
          *(undefined2 *)(iVar2 + 0x1c) = 0;
        }
        FUN_006513b0(local_4);
      }
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x658e60 FUN_00658e60

int FUN_00658e60(undefined4 param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = -1;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      *(undefined1 *)(local_4 * 0x8c + DAT_00713f48 + 0x61 + param_2) = param_3;
      SNDI_calcfxlevel(param_2,local_4);
      SNDPLATFORM_setfxlevel__map__SNDstop_(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x658f00 FUN_00658f00

int FUN_00658f00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = 0xffffffff;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      FUN_006514e0(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x658f70 FUN_00658f70

int FUN_00658f70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar1) {
    local_4 = 0xffffffff;
    iVar2 = iSNDpatchkey(iVar1,&local_4);
    while (iVar2 != 0) {
      FUN_00651510(local_4,param_2);
      iVar2 = iSNDpatchkey(iVar1,&local_4);
    }
  }
  return iVar1;
}


// ==== 0x658fe0 FUN_00658fe0

int FUN_00658fe0(undefined4 param_1,undefined1 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int local_8;
  int local_4;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  iVar2 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  if (-1 < iVar2) {
    local_8 = -1;
    local_4 = iVar2;
    iVar3 = iSNDpatchkey(iVar2,&local_8);
    while (iVar3 != 0) {
      iVar3 = local_8 * 0x8c + DAT_00713f48;
      iVar5 = 0;
      if (*(char *)(local_8 * 0x8c + 0x23 + DAT_00713f48) != '\0') {
        psVar4 = (short *)(iVar3 + 4);
        do {
          sVar1 = *psVar4;
          *(undefined1 *)(sVar1 * 0x8c + 0x5f + DAT_00713f48) = param_2;
          FUN_00651fa0((int)sVar1);
          iVar5 = iVar5 + 1;
          psVar4 = psVar4 + 1;
          iVar2 = local_4;
        } while (iVar5 < (int)(uint)*(byte *)(iVar3 + 0x23));
      }
      iVar3 = iSNDpatchkey(iVar2,&local_8);
    }
  }
  return iVar2;
}


// ==== 0x6590b0 FUN_006590b0

void FUN_006590b0(float param_1)

{
  for (; 6.2831855 < param_1; param_1 = param_1 - 6.2831855) {
  }
  return;
}


// ==== 0x659130 SNDI_sin

/* [canon] audio high (ghidra) docs/re/sound.md */

float10 SNDI_sin(float param_1)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar2 = (float10)param_1;
  if ((float10)6.2831855 < fVar2) {
    do {
      fVar2 = fVar2 - (float10)6.2831855;
    } while ((float10)6.2831855 < fVar2);
  }
  fVar3 = fVar2 * fVar2;
  fVar4 = fVar3 * fVar2 * fVar3;
  fVar5 = fVar4 * fVar3;
  fVar6 = fVar5 * fVar3;
  fVar1 = (float)(fVar6 * fVar3);
  return (float10)fVar1 * fVar3 * (float10)1.6059e-10 +
         ((fVar6 * (float10)2.7557319e-06 +
          ((fVar4 * (float10)0.00833333 + (fVar2 - fVar3 * fVar2 * (float10)0.16666667)) -
          fVar5 * (float10)0.0001984127)) - (float10)fVar1 * (float10)2.5052108e-08);
}


// ==== 0x6591c0 FUN_006591c0

undefined4 FUN_006591c0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}


// ==== 0x6591d0 FUN_006591d0

undefined4 FUN_006591d0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 0x1c) <= *(uint *)(param_1 + 0x20)) {
    return 0xffffffff;
  }
  iVar1 = FUN_0065f430(&param_4,param_2);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar1;
  param_4 = param_4 + iVar1 * 4;
  if (iVar1 < param_2) {
    FUN_00654cd0(param_4,(param_2 - iVar1) * 4);
  }
  return 1;
}


// ==== 0x659230 FUN_00659230

void FUN_00659230(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_0065f600();
    return;
  }
  return;
}


// ==== 0x659250 FUN_00659250

void FUN_00659250(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  *param_1 = FUN_006591d0;
  param_1[7] = param_2[3];
  param_1[8] = 0;
  param_1[9] = param_2[9];
  param_2[10] = FUN_006591c0;
  param_1[1] = FUN_00659230;
  iVar1 = FUN_0065f5f0(0xd68);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0065f310();
  }
  param_1[10] = uVar2;
  puVar3 = (undefined4 *)FUN_0065f3d0(auStack_c);
  uStack_18 = *puVar3;
  uStack_14 = puVar3[1];
  uStack_10 = 1;
  FUN_0065f400(&uStack_18,0);
  FUN_0065f420(1 < (int)param_1[9]);
  FUN_0065f350(*param_2,param_1[7] * 4,param_1[7]);
  return;
}


// ==== 0x659310 FUN_00659310

undefined4 FUN_00659310(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  while (0 < param_2) {
    iVar1 = FUN_0065f430(&param_4,param_2);
    param_4 = param_4 + iVar1 * 4;
    param_2 = param_2 - iVar1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar1;
    if (iVar1 < param_2) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
      uStack_8 = 0;
      uStack_c = 0;
      uStack_4 = 1;
      FUN_0065f400(&uStack_c,0);
      iVar1 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
      FUN_0065f350(*(undefined4 *)(param_1 + 0x2c),iVar1 * 4 + 4,iVar1 + 1);
    }
  }
  return 1;
}


// ==== 0x6593b0 FUN_006593b0

void FUN_006593b0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  *param_1 = FUN_00659310;
  param_1[1] = FUN_00660c40;
  param_1[0xb] = param_2[1];
  param_1[8] = 0;
  param_1[9] = param_2[4];
  param_1[10] = param_2[5];
  iVar1 = FUN_0065f5f0(0xd68);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0065f310();
  }
  param_1[7] = uVar2;
  puVar3 = (undefined4 *)FUN_0065f3d0(auStack_c);
  uStack_18 = *puVar3;
  uStack_14 = puVar3[1];
  uStack_10 = 1;
  FUN_0065f400(&uStack_18,0);
  FUN_0065f350(*param_2,param_1[9] * 4,param_1[9]);
  param_2[10] = FUN_006591c0;
  return;
}


// ==== 0x659460 FUN_00659460

int FUN_00659460(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x24) <= *(int *)(param_1 + 0x28)) {
    return -1;
  }
  iVar1 = FUN_0065f640(&param_4,param_2);
  param_4 = param_4 + iVar1 * 4;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar1;
  if (iVar1 < param_2) {
    FUN_00654cd0(param_4,(param_2 - iVar1) * 4);
    iVar1 = iVar1 + (param_2 - iVar1);
  }
  return iVar1;
}


// ==== 0x6594d0 FUN_006594d0

undefined4 FUN_006594d0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}


// ==== 0x6594e0 FUN_006594e0

void FUN_006594e0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = FUN_00659460;
  param_1[1] = FUN_00660c40;
  param_1[8] = *param_2;
  param_1[9] = param_2[3];
  param_1[10] = 0;
  iVar1 = FUN_0065f5f0(0xa8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0065fbd0();
  }
  param_1[7] = uVar2;
  param_2[10] = FUN_006594d0;
  FUN_0065f610(param_1[8],param_1[9] * 4,param_1[9]);
  return;
}


// ==== 0x659550 FUN_00659550

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


// ==== 0x659740 FUN_00659740

void FUN_00659740(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = FUN_00659550;
  param_1[1] = FUN_00660c40;
  param_1[0xb] = param_2[1];
  param_1[8] = 0;
  param_1[0xc] = param_2[9];
  param_1[9] = param_2[4];
  param_1[10] = param_2[5];
  iVar1 = FUN_0065f5f0(0xa8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0065fbd0();
  }
  param_1[7] = uVar2;
  param_2[10] = FUN_006591c0;
  if ((int)param_1[0xc] < 2) {
    param_1[0xd] = *param_2;
    param_1[0xe] = param_2[3];
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = param_2[4];
    param_1[0x12] = param_2[5];
    return;
  }
  FUN_0065f610(*param_2,param_1[9] * 4,param_1[9]);
  return;
}


// ==== 0x6597f0 FUN_006597f0

undefined4 FUN_006597f0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  uVar2 = *(uint *)(param_1 + 0x24);
  if (uVar2 <= uVar1) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x20) = uVar1 + param_2;
  if (uVar1 + param_2 < uVar2) {
    if (*(int *)(param_1 + 0x28) != 0) {
      (*DAT_00716674)(param_2,*(int *)(param_1 + 0x1c) + uVar1 * 2);
      return 1;
    }
    FUN_0065fc00(param_2,*(int *)(param_1 + 0x1c) + uVar1,param_4);
    return 1;
  }
  iVar3 = uVar2 - uVar1;
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_0065fc00(iVar3,*(int *)(param_1 + 0x1c) + uVar1,param_4);
  }
  else {
    (*DAT_00716674)(iVar3,*(int *)(param_1 + 0x1c) + uVar1 * 2);
  }
  FUN_00654cd0(param_4 + iVar3 * 4,(param_2 - iVar3) * 4);
  return 1;
}


// ==== 0x6598a0 FUN_006598a0

void FUN_006598a0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = FUN_006597f0;
  param_1[7] = *param_2;
  param_1[8] = 0;
  param_1[9] = param_2[3];
  param_1[10] = param_2[6];
  param_2[10] = FUN_006591c0;
  param_1[1] = 0;
  return;
}


// ==== 0x6598e0 FUN_006598e0

void FUN_006598e0(byte param_1)

{
  FUN_0064e520();
  if ((param_1 & 0x10) != 0) {
    FUN_00653a20((int)DAT_00713f64,DAT_00713f68,DAT_00713f6c);
    SNDSYS_leavecritical();
    return;
  }
  if ((param_1 & 4) != 0) {
    if (DAT_00713f50 == 1) {
      FUN_0065a740(DAT_00713d9a,DAT_00713f54);
      SNDSYS_leavecritical();
      return;
    }
    FUN_0065a720();
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x659950 FUN_00659950

undefined4 FUN_00659950(undefined4 param_1,undefined4 param_2)

{
  FUN_006598e0(param_2);
  return 0;
}


// ==== 0x659960 FUN_00659960

int FUN_00659960(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 * 0x8c + DAT_00713f48 + 0x28);
  if (sVar1 != -1) {
    param_1 = (int)sVar1;
  }
  return param_1;
}


// ==== 0x659990 FUN_00659990

int FUN_00659990(int param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  sVar1 = *(short *)(param_1 * 0x8c + DAT_00713f48 + 0x28);
  if (sVar1 != -1) {
    iVar2 = 1;
    psVar3 = (short *)(sVar1 * 0x8c + DAT_00713f48 + 6);
    do {
      if (*psVar3 == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar2 < 6);
  }
  return 0;
}


// ==== 0x6599e0 SNDPLATFORM_packetplay

/* [canon] audio med (ghidra) docs/re/sound.md */

void SNDPLATFORM_packetplay
               (undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = 0;
  local_28 = 0;
  local_14 = 0;
  local_24 = 0;
  local_10 = 0;
  local_20 = 0;
  local_c = 0;
  local_1c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_30 = 0;
  *(undefined2 *)(param_2 * 0x8c + 0x6a + DAT_00713f48) = param_3;
  FUN_00651540(param_2,0xffffffff,0xffffffff,0,0,param_5,param_6,&local_18,&local_30,param_8 + 0x18,
               0,*(undefined1 *)(param_8 + 7));
  return;
}


// ==== 0x659a70 FUN_00659a70

ushort FUN_00659a70(int *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort uVar5;
  
  if ((int)(uint)DAT_00713dbc <= *param_1) {
    return 0;
  }
  do {
    uVar1 = *(ushort *)(&DAT_00713dbe + *param_1 * 2);
    uVar2 = *(ushort *)(param_2 + 0x18);
    uVar3 = uVar1 & 0x71c;
    if ((((uVar2 & 0x71c) == 0) || (uVar3 = uVar2 & uVar3, uVar3 != 0)) &&
       ((uVar5 = uVar1 & 0xe0, (uVar2 & 0xe0) == 0 || (uVar5 = uVar2 & uVar5, uVar5 != 0)))) {
      uVar3 = uVar3 | uVar5;
      if ((uVar1 & 0x10) != 0) {
        if ((uVar2 & 3) == 0) {
          uVar3 = uVar3 | uVar1 & 3;
        }
        else {
          uVar2 = uVar2 & uVar1 & 3;
          uVar3 = uVar3 | uVar2;
          if (uVar2 == 0) goto LAB_00659b17;
        }
      }
      if (((*(char *)(param_2 + 3) == '\x01') || (-1 < (char)uVar3)) && (uVar3 != 0)) {
        *param_1 = *param_1 + 1;
        return uVar3;
      }
    }
LAB_00659b17:
    iVar4 = *param_1 + 1;
    *param_1 = iVar4;
    if ((int)(uint)DAT_00713dbc <= iVar4) {
      return 0;
    }
  } while( true );
}


// ==== 0x659b40 FUN_00659b40

void FUN_00659b40(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = param_1 * 0x8c + DAT_00713f48;
  if ((*(byte *)(param_1 * 0x8c + 0x24 + DAT_00713f48) & 4) != 0) {
    cVar2 = *(char *)(iVar5 + 0x5f);
    param_1 = 0;
    fVar1 = *(float *)(iVar5 + 0x48);
    if (*(char *)(iVar5 + 0x23) != '\0') {
      uVar4 = (uint)DAT_00713db7;
      psVar6 = (short *)(iVar5 + 4);
      do {
        iVar8 = *psVar6 * 0x110 + DAT_0071400c;
        iVar7 = 0;
        if (uVar4 != 0) {
          do {
            fVar3 = (float)(int)*(char *)(iVar7 + param_2) * 0.007874016;
            *(float *)(iVar8 + iVar7 * 4) = fVar3;
            FUN_00656870((int)*psVar6,iVar7,fVar3 * (float)(int)cVar2 * fVar1 * 0.007874016);
            uVar4 = (uint)DAT_00713db7;
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)uVar4);
        }
        param_1 = param_1 + 1;
        psVar6 = psVar6 + 1;
        param_2 = param_2 + 6;
      } while (param_1 < (int)(uint)*(byte *)(iVar5 + 0x23));
    }
  }
  return;
}


// ==== 0x659c20 FUN_00659c20

undefined4 FUN_00659c20(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  iVar1 = param_1 * 0x8c + DAT_00713f48;
  if ((*(byte *)(param_1 * 0x8c + 0x24 + DAT_00713f48) & 4) == 0) {
    return 0xfffffff9;
  }
  iVar2 = 0;
  if (*(char *)(iVar1 + 0x23) != '\0') {
    psVar3 = (short *)(iVar1 + 4);
    do {
      FUN_0065fc80((int)*psVar3,iVar2,param_2);
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(iVar1 + 0x23));
  }
  return 0;
}


// ==== 0x659c80 SNDI_gettag

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 SNDI_gettag(int *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  cVar1 = *(char *)*param_1;
  while (cVar1 == -4) {
    iVar4 = *param_1;
    *param_1 = iVar4 + 1;
    cVar1 = *(char *)(iVar4 + 1);
  }
  pbVar3 = (byte *)*param_1;
  bVar2 = *pbVar3;
  param_1[1] = (uint)bVar2;
  if (bVar2 == 0xff) {
    return 0;
  }
  *param_1 = (int)(pbVar3 + 1);
  if ((param_1[1] != 0xfd) && (param_1[1] != 0xfe)) {
    uVar5 = (uint)pbVar3[1];
    param_1[4] = uVar5;
    if (uVar5 == 0xff) {
      iVar4 = SNDI_getb(pbVar3 + 2,4);
      param_1[4] = iVar4;
      *param_1 = *param_1 + 4;
    }
    iVar4 = *param_1 + 1;
    *param_1 = iVar4;
    param_1[3] = iVar4;
    if ((uint)param_1[4] < 5) {
      iVar4 = SNDI_getb(iVar4,param_1[4]);
      param_1[2] = iVar4;
    }
    *param_1 = *param_1 + param_1[4];
  }
  return 1;
}


// ==== 0x659d20 FUN_00659d20

undefined4 FUN_00659d20(undefined2 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 3) = 0x7f;
  *(undefined1 *)(param_1 + 2) = 0x40;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  param_1[4] = 0;
  puVar1 = (undefined4 *)(param_1 + 0x2c);
  iVar2 = 4;
  do {
    puVar1[-4] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(param_1 + 0xc);
  param_1 = param_1 + 6;
  iVar2 = 6;
  do {
    *param_1 = 0;
    *puVar1 = 0;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}


// ==== 0x659d80 SNDI_patchtohdrgen

/* [canon] audio med (ghidra) docs/re/sound.md */

void SNDI_patchtohdrgen(undefined4 param_1,int param_2,undefined2 *param_3,int param_4,
                       undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_41c [46];
  undefined4 auStack_364 [65];
  undefined4 uStack_260;
  int *piStack_25c;
  int iStack_258;
  undefined4 *puStack_254;
  undefined4 uStack_250;
  int iStack_24c;
  undefined4 uStack_248;
  int *piStack_244;
  int local_230;
  int local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_214;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_19c;
  undefined4 auStack_164 [46];
  undefined4 auStack_ac [43];
  
  piStack_244 = (int *)param_3;
  uStack_248 = 0x659d98;
  FUN_00654cd0();
  uStack_248 = 0x68;
  iStack_24c = param_4;
  uStack_250 = 0x659da7;
  FUN_00654cd0();
  uStack_250 = 0x1c;
  puStack_254 = param_5;
  iStack_258 = 0x659db6;
  FUN_00654cd0();
  iStack_258 = param_4;
  piStack_25c = (int *)0x659dbc;
  FUN_00659d20();
  piStack_25c = &local_230;
  local_230 = param_2 + 8;
  local_214 = 1;
  local_20c = 48000;
  local_208 = 0;
  local_19c = 10;
  uStack_260 = 0x659df7;
  iVar2 = SNDI_gettag();
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(param_4 + 0x58);
    do {
      uVar1 = local_224;
      iVar2 = local_22c;
      if (local_22c < 0x2b) {
        auStack_ac[local_22c] = local_228;
        auStack_164[local_22c] = local_224;
        if (local_22c == 0x14) {
          puVar4[-4] = local_224;
          *puVar4 = local_220;
          puVar4 = puVar4 + 1;
        }
      }
      else if ((local_22c < 0x80) || (0xad < local_22c)) {
        if (local_22c == 0xfe) break;
      }
      else {
        auStack_41c[local_22c] = local_228;
        auStack_364[iVar2] = uVar1;
      }
      piStack_244 = &local_230;
      uStack_248 = 0x659e6b;
      iVar2 = SNDI_gettag();
    } while (iVar2 != 0);
  }
  *(undefined1 *)(param_3 + 1) = (undefined1)local_214;
  *param_3 = (undefined2)local_20c;
  *(undefined1 *)((int)param_3 + 3) = (undefined1)local_19c;
  *param_5 = local_208;
  *(undefined2 *)(param_4 + 8) = 4;
  *(undefined1 *)(param_4 + 7) = 2;
  iVar2 = 0;
  if (*(char *)(param_3 + 1) != '\0') {
    puVar3 = (undefined2 *)(param_4 + 0xc);
    do {
      *puVar3 = *(undefined2 *)(&DAT_00713f70 + (iVar2 + (uint)*(byte *)(param_3 + 1) * 6) * 2);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(param_3 + 1));
  }
  return;
}


// ==== 0x659ee0 FUN_00659ee0

int FUN_00659ee0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 != (undefined4 *)0x0) &&
     (iVar2 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     iVar2 < 1)) {
    return iVar2;
  }
  FUN_0065fd40(param_1 + 0x1c,param_2,param_3,param_4);
  return param_2;
}


// ==== 0x659f30 FUN_00659f30

undefined4 FUN_00659f30(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = 0;
  *param_1 = FUN_00659ee0;
  param_1[7] = 0;
  return 0;
}


// ==== 0x659f60 FUN_00659f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00659f60(int param_1,int *param_2)

{
  float fVar1;
  
  fVar1 = ((float)*param_2 + (float)*param_2) / (float)param_2[1];
  *(float *)(param_1 + 0x24) = fVar1;
  *(float *)(param_1 + 0x20) = _K_ONE - fVar1;
  *(float *)(param_1 + 0x24) = (float)param_2[2] * *(float *)(param_1 + 0x24) * 0.00390625;
  *(float *)(param_1 + 0x20) = (float)param_2[2] * *(float *)(param_1 + 0x20) * 0.00390625;
  return;
}


// ==== 0x659fa0 FUN_00659fa0

void FUN_00659fa0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  int iStack_20;
  int aiStack_18 [6];
  
  uVar3 = DAT_00716540;
  uVar2 = DAT_0071653c;
  aiStack_18[1] = 0;
  aiStack_18[2] = 0;
  aiStack_18[3] = 0;
  aiStack_18[4] = 0;
  aiStack_18[5] = 0;
  iVar6 = 0;
  DAT_00717288 = DAT_00717288 + 1;
  aiStack_18[0] = 0;
  if (DAT_00717288 < 3000) {
    iVar4 = SNDI_getb(DAT_00717290 + 4 + DAT_0071729c * 4,4);
    if ((iVar4 != 0) &&
       (FUN_0065fdb0(*(undefined4 *)(DAT_0071728c + DAT_00717298 * 4),&DAT_00716688),
       bVar5 = DAT_00716465, DAT_00716465 != 0)) {
      do {
        if ((aiStack_18[iVar6] == 0) &&
           (puVar1 = *(undefined4 **)(DAT_00717294 + 4 + iVar6 * 4), puVar1 != (undefined4 *)0x0)) {
          (*(code *)*puVar1)(puVar1,param_1,uVar2,uVar3,iVar6 + 1);
          (*DAT_00716670)(param_1,0x3f800000,uVar3,(&DAT_0071655c)[iVar6]);
          aiStack_18[iVar6] = 1;
          pcVar7 = &DAT_006ea058 + (iVar6 + ((DAT_00716465 - 7) + DAT_0071729c * 6) * 6) * 6;
          iStack_20 = 0;
          bVar5 = DAT_00716465;
          if (DAT_00716465 != 0) {
            do {
              if (-1 < *pcVar7) {
                (*DAT_00716670)(param_1,0x3f800000,uVar3,(&DAT_0071655c)[*pcVar7]);
                aiStack_18[*pcVar7] = 1;
                bVar5 = DAT_00716465;
              }
              pcVar7 = pcVar7 + 1;
              iStack_20 = iStack_20 + 1;
            } while (iStack_20 < (int)(uint)bVar5);
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)(uint)bVar5);
    }
    FUN_00654cd0(&DAT_00716688,param_1 * 4);
  }
  return;
}


// ==== 0x65a130 FUN_0065a130

void FUN_0065a130(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_007172ec != 0) {
    iVar3 = SNDI_getb(DAT_00717290 + 4 + DAT_007172e8 * 4,4);
    if ((iVar3 != 0) && (iVar4 = 0, 0 < iVar3)) {
      do {
        iVar1 = *(int *)(DAT_0071728c + iVar4 * 4);
        pcVar2 = *(code **)(iVar1 + 4);
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(iVar1);
          *(undefined4 *)(*(int *)(DAT_0071728c + iVar4 * 4) + 4) = 0;
        }
        iVar1 = *(int *)(DAT_0071728c + iVar4 * 4);
        if (iVar1 != 0) {
          FUN_006510d0(iVar1);
          *(undefined4 *)(DAT_0071728c + iVar4 * 4) = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
    }
    if (DAT_0071728c != 0) {
      FUN_006510d0(DAT_0071728c);
      DAT_0071728c = 0;
    }
    iVar4 = 0;
    iVar3 = DAT_00717294;
    do {
      if (*(int *)(iVar4 + iVar3) != 0) {
        *(undefined4 *)(iVar4 + iVar3) = 0;
        iVar3 = DAT_00717294;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x18);
    if (iVar3 != 0) {
      FUN_006510d0(iVar3);
      DAT_00717294 = 0;
    }
    DAT_007172a4 = 0;
    DAT_007172a0 = 0;
    DAT_007172a8 = 0;
    DAT_007172e4 = 0;
    DAT_007172ec = 0;
    FUN_00654cd0(&DAT_00716688,0x400);
  }
  return;
}


// ==== 0x65a240 FUN_0065a240

void FUN_0065a240(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  DAT_00717290 = &DAT_007172ac;
  DAT_00717294 = FUN_00650fd0(0x1c);
  FUN_00654cd0(DAT_00717294,0x1c);
  iVar3 = DAT_0071729c;
  DAT_007172e4 = DAT_007172a4;
  DAT_007172a8 = DAT_007172a0;
  iVar4 = SNDI_getb(DAT_00717290 + DAT_0071729c + 1,4);
  DAT_0071728c = FUN_00650fd0(iVar4 * 4);
  iVar7 = 0;
  pbVar6 = DAT_007172e4;
  if (0 < iVar4) {
    do {
      uVar5 = FUN_00650fd0(*(undefined4 *)(&DAT_006ea640 + (uint)*pbVar6 * 4));
      *(undefined4 *)(DAT_0071728c + iVar7 * 4) = uVar5;
      FUN_00654cd0(*(undefined4 *)(DAT_0071728c + iVar7 * 4),
                   *(undefined4 *)(&DAT_006ea640 + (uint)*pbVar6 * 4));
      FUN_00654cd0(&local_10,0x10);
      switch(*pbVar6) {
      case 0:
        FUN_0065fdd0(*(undefined4 *)(DAT_0071728c + iVar7 * 4));
        break;
      case 1:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 4,2);
        local_10 = local_10 << 8;
        local_c = param_1 << 8;
        local_8 = SNDI_getb(pbVar6 + 6,2);
        FUN_00659f30(uVar5);
        FUN_00659f60(uVar5,&local_10);
        break;
      case 2:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 2,2);
        local_10 = local_10 << 8;
        local_c = param_1 << 8;
        FUN_006607b0(uVar5);
        FUN_006607e0(uVar5,&local_10);
        break;
      case 3:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 2,2);
        local_10 = local_10 << 8;
        local_c = param_1 << 8;
        FUN_0065bdb0(uVar5);
        FUN_0065bde0(uVar5,&local_10);
        break;
      case 4:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 4,2);
        local_10 = local_10 << 8;
        local_c = SNDI_getb(pbVar6 + 6,2);
        local_c = local_c << 8;
        local_8 = param_1 << 8;
        FUN_0065bdb0(uVar5);
        FUN_00660700(uVar5,&local_10);
        break;
      case 5:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 2,2);
        local_10 = local_10 << 8;
        local_c = param_1 << 8;
        local_8 = SNDI_getb(pbVar6 + 4,2);
        local_8 = local_8 << 8;
        local_4 = SNDI_getb(pbVar6 + 6,2);
        FUN_00660610(uVar5);
        FUN_00660640(uVar5,&local_10);
        break;
      case 6:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 2,2);
        FUN_00660390(uVar5);
        FUN_006603c0(uVar5,&local_10);
        break;
      case 7:
        uVar5 = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        local_10 = SNDI_getb(pbVar6 + 2,2);
        local_c = param_1 << 8;
        local_8 = SNDI_getb(pbVar6 + 4,2);
        local_8 = local_8 << 8;
        FUN_00660220(uVar5);
        FUN_00660250(uVar5,&local_10);
        break;
      case 8:
        FUN_00660050(*(undefined4 *)(DAT_0071728c + iVar7 * 4));
        break;
      case 9:
        FUN_0065fed0(*(undefined4 *)(DAT_0071728c + iVar7 * 4));
      }
      bVar2 = pbVar6[1];
      if (bVar2 != 0) {
        if ((*pbVar6 == 9) && (10 < *(byte *)((int)DAT_00717290 + 2))) {
          *(undefined4 *)
           (DAT_00717294 +
           (uint)(byte)(&DAT_006ea53d)[((uint)DAT_00716465 + DAT_0071729c * 6) * 6 + (bVar2 & 0xf)]
           * 4) = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
          *(undefined4 *)
           (DAT_00717294 +
           (uint)(byte)(&DAT_006ea53d)
                       [((uint)DAT_00716465 + DAT_0071729c * 6) * 6 + (uint)(bVar2 >> 4)] * 4) =
               *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        }
        else {
          *(undefined4 *)
           (DAT_00717294 +
           (uint)(byte)(&DAT_006ea53d)[((uint)DAT_00716465 + DAT_0071729c * 6) * 6 + (uint)bVar2] *
           4) = *(undefined4 *)(DAT_0071728c + iVar7 * 4);
        }
      }
      iVar7 = iVar7 + 1;
      pbVar6 = pbVar6 + *(int *)(&DAT_006ea668 + (uint)*pbVar6 * 4);
    } while (iVar7 < iVar4);
  }
  iVar4 = DAT_007172a8;
  iVar8 = 0;
  iVar7 = SNDI_getb(DAT_00717290 + iVar3 + 7,4);
  if (0 < iVar7) {
    do {
      iVar7 = SNDI_getb(iVar4 + 4,4,*(undefined1 *)(iVar4 + 8),*(undefined1 *)(iVar4 + 9));
      iVar7 = SNDI_getb(iVar4,4,*(undefined4 *)(DAT_0071728c + iVar7 * 4));
      FUN_00657870(*(undefined4 *)(DAT_0071728c + iVar7 * 4));
      iVar4 = iVar4 + 0xc;
      iVar8 = iVar8 + 1;
      iVar7 = SNDI_getb(DAT_00717290 + iVar3 + 7,4);
    } while (iVar8 < iVar7);
  }
  DAT_00717288 = 3000;
  FUN_00654cd0(&DAT_00716688,0x400);
  DAT_00717298 = 0;
  bVar2 = *DAT_007172e4;
  pbVar6 = DAT_007172e4;
  while (bVar2 != 0) {
    pbVar1 = pbVar6 + *(int *)(&DAT_006ea668 + (uint)bVar2 * 4);
    pbVar6 = pbVar6 + *(int *)(&DAT_006ea668 + (uint)bVar2 * 4);
    DAT_00717298 = DAT_00717298 + 1;
    bVar2 = *pbVar1;
  }
  return;
}


// ==== 0x65a720 FUN_0065a720

void FUN_0065a720(void)

{
  DAT_00716470 = 0;
  FUN_0065a130();
  DAT_0071646f = 0;
  return;
}


// ==== 0x65a740 FUN_0065a740

void FUN_0065a740(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  
  DAT_00716470 = (code *)0x0;
  FUN_0065a130();
  DAT_0071646f = 0;
  DAT_007172ec = 1;
  puVar5 = param_2;
  puVar7 = &DAT_007172ac;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar3 = DAT_00716465 - 1;
  puVar4 = &DAT_007172b4 + iVar3 * 4;
  pbVar6 = (byte *)(param_2 + 0xe);
  iVar1 = SNDI_getb(puVar4,4);
  if (iVar1 == 0) {
    iVar1 = SNDI_getb(puVar4,4);
    while (iVar1 == 0) {
      puVar4 = puVar4 + -4;
      iVar3 = iVar3 + -1;
      iVar1 = SNDI_getb(puVar4,4);
    }
    DAT_0071729c = iVar3 + 1;
  }
  else {
    DAT_0071729c = (uint)DAT_00716465;
  }
  DAT_007172e8 = DAT_0071729c;
  if (0 < iVar3) {
    puVar4 = &DAT_007172cc;
    iVar1 = iVar3;
    do {
      iVar2 = SNDI_getb(puVar4 + -0x18,4);
      if (0 < iVar2) {
        do {
          pbVar6 = pbVar6 + *(int *)(&DAT_006ea668 + (uint)*pbVar6 * 4);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar2 = SNDI_getb(puVar4,4);
      puVar4 = puVar4 + 4;
      iVar1 = iVar1 + -1;
      pbVar6 = pbVar6 + iVar2 * 0xc;
    } while (iVar1 != 0);
  }
  DAT_007172a4 = pbVar6;
  iVar3 = SNDI_getb(&DAT_007172b4 + iVar3 * 4,4);
  if (0 < iVar3) {
    do {
      pbVar6 = pbVar6 + *(int *)(&DAT_006ea668 + (uint)*pbVar6 * 4);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  DAT_007172a0 = pbVar6;
  FUN_0065a240(param_1,param_2);
  DAT_00716470 = FUN_00659fa0;
  DAT_0071646f = 1;
  return;
}


// ==== 0x65a880 FUN_0065a880

void FUN_0065a880(uint param_1,float param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  
  do {
    if ((param_1 & 3) == 0) {
      do {
        fVar1 = *(float *)(param_3 + -0xc + param_1 * 4);
        fVar2 = *(float *)(param_3 + -8 + param_1 * 4);
        fVar3 = *(float *)(param_3 + -4 + param_1 * 4);
        *(float *)(param_4 + -0x10 + param_1 * 4) =
             *(float *)(param_3 + -0x10 + param_1 * 4) * param_2 +
             *(float *)(param_4 + -0x10 + param_1 * 4);
        *(float *)(param_4 + -0xc + param_1 * 4) =
             fVar1 * param_2 + *(float *)(param_4 + -0xc + param_1 * 4);
        *(float *)(param_4 + -4 + param_1 * 4) =
             fVar3 * param_2 + *(float *)(param_4 + -4 + param_1 * 4);
        *(float *)(param_4 + -8 + param_1 * 4) =
             fVar2 * param_2 + *(float *)(param_4 + -8 + param_1 * 4);
        uVar5 = param_1 - 4;
        bVar4 = 3 < (int)param_1;
        param_1 = uVar5;
      } while (uVar5 != 0 && bVar4);
      return;
    }
    *(float *)(param_4 + -4 + param_1 * 4) =
         *(float *)(param_3 + -4 + param_1 * 4) * param_2 + *(float *)(param_4 + -4 + param_1 * 4);
    param_1 = param_1 - 1;
  } while (param_1 != 0);
  return;
}


// ==== 0x65a900 FUN_0065a900

void FUN_0065a900(uint param_1,float param_2,uint param_3,uint param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
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
  float fVar33;
  float fVar34;
  uint uVar35;
  
  while ((((param_1 & 0xf) != 0 || ((param_3 & 0xf) != 0)) || ((param_4 & 0xf) != 0))) {
    *(float *)((param_4 - 4) + param_1 * 4) =
         *(float *)((param_3 - 4) + param_1 * 4) * param_2 + *(float *)((param_4 - 4) + param_1 * 4)
    ;
    param_1 = param_1 - 1;
    if (param_1 == 0) {
      return;
    }
  }
  do {
    pfVar1 = (float *)((param_3 - 0x40) + param_1 * 4);
    fVar5 = pfVar1[1];
    fVar6 = pfVar1[2];
    fVar7 = pfVar1[3];
    pfVar2 = (float *)((param_3 - 0x30) + param_1 * 4);
    fVar8 = *pfVar2;
    fVar9 = pfVar2[1];
    fVar10 = pfVar2[2];
    fVar11 = pfVar2[3];
    pfVar2 = (float *)((param_3 - 0x20) + param_1 * 4);
    fVar12 = *pfVar2;
    fVar13 = pfVar2[1];
    fVar14 = pfVar2[2];
    fVar15 = pfVar2[3];
    pfVar2 = (float *)((param_3 - 0x10) + param_1 * 4);
    fVar16 = *pfVar2;
    fVar17 = pfVar2[1];
    fVar18 = pfVar2[2];
    fVar19 = pfVar2[3];
    pfVar2 = (float *)((param_4 - 0x40) + param_1 * 4);
    fVar20 = pfVar2[1];
    fVar21 = pfVar2[2];
    fVar22 = pfVar2[3];
    pfVar3 = (float *)((param_4 - 0x30) + param_1 * 4);
    fVar23 = *pfVar3;
    fVar24 = pfVar3[1];
    fVar25 = pfVar3[2];
    fVar26 = pfVar3[3];
    pfVar3 = (float *)((param_4 - 0x20) + param_1 * 4);
    fVar27 = *pfVar3;
    fVar28 = pfVar3[1];
    fVar29 = pfVar3[2];
    fVar30 = pfVar3[3];
    pfVar3 = (float *)((param_4 - 0x10) + param_1 * 4);
    fVar31 = *pfVar3;
    fVar32 = pfVar3[1];
    fVar33 = pfVar3[2];
    fVar34 = pfVar3[3];
    pfVar3 = (float *)((param_4 - 0x40) + param_1 * 4);
    *pfVar3 = *pfVar1 * param_2 + *pfVar2;
    pfVar3[1] = fVar5 * param_2 + fVar20;
    pfVar3[2] = fVar6 * param_2 + fVar21;
    pfVar3[3] = fVar7 * param_2 + fVar22;
    pfVar1 = (float *)((param_4 - 0x30) + param_1 * 4);
    *pfVar1 = fVar8 * param_2 + fVar23;
    pfVar1[1] = fVar9 * param_2 + fVar24;
    pfVar1[2] = fVar10 * param_2 + fVar25;
    pfVar1[3] = fVar11 * param_2 + fVar26;
    pfVar1 = (float *)((param_4 - 0x20) + param_1 * 4);
    *pfVar1 = fVar12 * param_2 + fVar27;
    pfVar1[1] = fVar13 * param_2 + fVar28;
    pfVar1[2] = fVar14 * param_2 + fVar29;
    pfVar1[3] = fVar15 * param_2 + fVar30;
    pfVar1 = (float *)((param_4 - 0x10) + param_1 * 4);
    *pfVar1 = fVar16 * param_2 + fVar31;
    pfVar1[1] = fVar17 * param_2 + fVar32;
    pfVar1[2] = fVar18 * param_2 + fVar33;
    pfVar1[3] = fVar19 * param_2 + fVar34;
    uVar35 = param_1 - 0x10;
    bVar4 = 0xf < (int)param_1;
    param_1 = uVar35;
  } while (uVar35 != 0 && bVar4);
  return;
}


// ==== 0x65a9a0 FUN_0065a9a0

void FUN_0065a9a0(uint param_1,int param_2,int param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  bool bVar8;
  uint uVar9;
  
  do {
    if ((param_1 & 7) == 0) {
      do {
        sVar1 = *(short *)(param_2 + -0xe + param_1 * 2);
        sVar2 = *(short *)(param_2 + -0xc + param_1 * 2);
        sVar3 = *(short *)(param_2 + -10 + param_1 * 2);
        sVar4 = *(short *)(param_2 + -8 + param_1 * 2);
        sVar5 = *(short *)(param_2 + -6 + param_1 * 2);
        sVar6 = *(short *)(param_2 + -4 + param_1 * 2);
        sVar7 = *(short *)(param_2 + -2 + param_1 * 2);
        *(float *)(param_3 + -0x20 + param_1 * 4) = (float)*(short *)(param_2 + -0x10 + param_1 * 2)
        ;
        *(float *)(param_3 + -8 + param_1 * 4) = (float)sVar6;
        *(float *)(param_3 + -0xc + param_1 * 4) = (float)sVar5;
        *(float *)(param_3 + -0x10 + param_1 * 4) = (float)sVar4;
        *(float *)(param_3 + -0x14 + param_1 * 4) = (float)sVar3;
        *(float *)(param_3 + -0x18 + param_1 * 4) = (float)sVar2;
        *(float *)(param_3 + -0x1c + param_1 * 4) = (float)sVar1;
        *(float *)(param_3 + -4 + param_1 * 4) = (float)sVar7;
        uVar9 = param_1 - 8;
        bVar8 = 7 < (int)param_1;
        param_1 = uVar9;
      } while (uVar9 != 0 && bVar8);
      return;
    }
    *(float *)(param_3 + -4 + param_1 * 4) = (float)*(short *)(param_2 + -2 + param_1 * 2);
    param_1 = param_1 - 1;
  } while (param_1 != 0);
  return;
}


// ==== 0x65aa20 FUN_0065aa20

void FUN_0065aa20(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  do {
    if ((param_1 & 7) == 0) goto LAB_0065aa57;
    uVar3 = (ulonglong)(uint)(int)(short)*(undefined4 *)(param_2 + -2 + param_1 * 2);
    uVar4 = PackedIntToFloatingDwordConv(uVar3,uVar3);
    *(int *)(param_3 + -4 + param_1 * 4) = (int)uVar4;
    param_1 = param_1 - 1;
  } while (param_1 != 0);
LAB_0065aabc:
  FastExitMediaState();
  return;
LAB_0065aa57:
  do {
    uVar4 = *(undefined8 *)(param_2 + -0x10 + param_1 * 2);
    uVar5 = *(undefined8 *)(param_2 + -8 + param_1 * 2);
    uVar7 = CONCAT44((int)(short)((ulonglong)uVar4 >> 0x10),(int)(short)uVar4);
    uVar9 = CONCAT44((int)(short)((ulonglong)uVar4 >> 0x30),(int)(short)((ulonglong)uVar4 >> 0x20));
    uVar6 = CONCAT44((int)(short)((ulonglong)uVar5 >> 0x10),(int)(short)uVar5);
    uVar8 = CONCAT44((int)(short)((ulonglong)uVar5 >> 0x30),(int)(short)((ulonglong)uVar5 >> 0x20));
    uVar4 = PackedIntToFloatingDwordConv(uVar7,uVar7);
    uVar5 = PackedIntToFloatingDwordConv(uVar9,uVar9);
    uVar7 = PackedIntToFloatingDwordConv(uVar6,uVar6);
    uVar9 = PackedIntToFloatingDwordConv(uVar8,uVar8);
    *(undefined8 *)(param_3 + -0x20 + param_1 * 4) = uVar4;
    *(undefined8 *)(param_3 + -0x18 + param_1 * 4) = uVar5;
    *(undefined8 *)(param_3 + -0x10 + param_1 * 4) = uVar7;
    *(undefined8 *)(param_3 + -8 + param_1 * 4) = uVar9;
    uVar2 = param_1 - 8;
    bVar1 = 7 < (int)param_1;
    param_1 = uVar2;
  } while (uVar2 != 0 && bVar1);
  goto LAB_0065aabc;
}


// ==== 0x65aad0 FUN_0065aad0

void FUN_0065aad0(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar3 = CONCAT44(param_2,param_2);
  do {
    if ((param_1 & 7) == 0) goto LAB_0065ab13;
    uVar4 = PackedFloatingMUL((ulonglong)*(uint *)(param_3 + -4 + param_1 * 4),uVar3);
    uVar4 = PackedFloatingADD(uVar4,(ulonglong)*(uint *)(param_4 + -4 + param_1 * 4));
    *(int *)(param_4 + -4 + param_1 * 4) = (int)uVar4;
    param_1 = param_1 - 1;
  } while (param_1 != 0);
LAB_0065ab68:
  FastExitMediaState();
  return;
LAB_0065ab13:
  do {
    uVar4 = PackedFloatingMUL(*(undefined8 *)(param_3 + -0x20 + param_1 * 4),uVar3);
    uVar5 = PackedFloatingMUL(*(undefined8 *)(param_3 + -0x18 + param_1 * 4),uVar3);
    uVar6 = PackedFloatingMUL(*(undefined8 *)(param_3 + -0x10 + param_1 * 4),uVar3);
    uVar7 = PackedFloatingMUL(*(undefined8 *)(param_3 + -8 + param_1 * 4),uVar3);
    uVar4 = PackedFloatingADD(uVar4,*(undefined8 *)(param_4 + -0x20 + param_1 * 4));
    *(undefined8 *)(param_4 + -0x20 + param_1 * 4) = uVar4;
    uVar4 = PackedFloatingADD(uVar5,*(undefined8 *)(param_4 + -0x18 + param_1 * 4));
    *(undefined8 *)(param_4 + -0x18 + param_1 * 4) = uVar4;
    uVar4 = PackedFloatingADD(uVar6,*(undefined8 *)(param_4 + -0x10 + param_1 * 4));
    *(undefined8 *)(param_4 + -0x10 + param_1 * 4) = uVar4;
    uVar4 = PackedFloatingADD(uVar7,*(undefined8 *)(param_4 + -8 + param_1 * 4));
    *(undefined8 *)(param_4 + -8 + param_1 * 4) = uVar4;
    uVar2 = param_1 - 8;
    bVar1 = 7 < (int)param_1;
    param_1 = uVar2;
  } while (uVar2 != 0 && bVar1);
  goto LAB_0065ab68;
}


// ==== 0x65ab70 FUN_0065ab70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065ab70(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  
  if (in_EAX < 1) {
    fVar1 = 0.0;
    in_EAX = -in_EAX;
    fVar2 = _K_ONE / (float)param_4;
  }
  else {
    fVar2 = -1.0 / (float)param_4;
    fVar1 = _K_ONE;
  }
  iVar5 = param_4 - in_EAX;
  iVar8 = in_EAX;
  if (3 < iVar5) {
    iVar7 = in_EAX + 3;
    pfVar3 = (float *)(param_3 + 4);
    pfVar4 = (float *)(param_1 + 8 + in_EAX * 4);
    pfVar6 = (float *)(param_1 + 0xc);
    do {
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 4;
      pfVar3[-1] = fVar1 * pfVar4[-2] + (_K_ONE - fVar1) * pfVar6[-3];
      fVar1 = fVar1 + fVar2;
      *pfVar3 = fVar1 * pfVar4[-1] +
                (_K_ONE - fVar1) * *(float *)((param_1 - param_3) + -0x10 + (int)(pfVar3 + 4));
      fVar1 = fVar1 + fVar2;
      pfVar3[1] = fVar1 * *pfVar4 + (_K_ONE - fVar1) * pfVar6[-1];
      fVar1 = fVar1 + fVar2;
      pfVar3[2] = fVar1 * pfVar4[1] + (_K_ONE - fVar1) * *pfVar6;
      fVar1 = fVar1 + fVar2;
      pfVar3 = pfVar3 + 4;
      pfVar4 = pfVar4 + 4;
      pfVar6 = pfVar6 + 4;
    } while (iVar7 < param_4);
  }
  if (iVar8 < param_4) {
    pfVar3 = (float *)(param_3 + (iVar8 - in_EAX) * 4);
    do {
      iVar8 = iVar8 + 1;
      *pfVar3 = fVar1 * *(float *)(param_1 + -4 + iVar8 * 4) +
                (_K_ONE - fVar1) * *(float *)((int)pfVar3 + (param_1 - param_3));
      fVar1 = fVar1 + fVar2;
      pfVar3 = pfVar3 + 1;
    } while (iVar8 < param_4);
  }
  iVar8 = 0;
  if (3 < in_EAX) {
    iVar7 = 3;
    pfVar3 = (float *)(param_3 + 4 + iVar5 * 4);
    pfVar4 = (float *)(param_2 + 8);
    pfVar6 = (float *)(param_1 + 0xc + iVar5 * 4);
    do {
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 4;
      pfVar3[-1] = fVar1 * pfVar4[-2] + (_K_ONE - fVar1) * pfVar6[-3];
      fVar1 = fVar1 + fVar2;
      *pfVar3 = fVar1 * pfVar4[-1] +
                (_K_ONE - fVar1) * *(float *)((int)pfVar3 + (param_1 - param_3));
      fVar1 = fVar1 + fVar2;
      pfVar3[1] = fVar1 * *pfVar4 + (_K_ONE - fVar1) * pfVar6[-1];
      fVar1 = fVar1 + fVar2;
      pfVar3[2] = fVar1 * pfVar4[1] + (_K_ONE - fVar1) * *pfVar6;
      fVar1 = fVar1 + fVar2;
      pfVar3 = pfVar3 + 4;
      pfVar4 = pfVar4 + 4;
      pfVar6 = pfVar6 + 4;
    } while (iVar7 < in_EAX);
  }
  if (iVar8 < in_EAX) {
    pfVar3 = (float *)(param_3 + ((iVar8 - in_EAX) + param_4) * 4);
    do {
      iVar8 = iVar8 + 1;
      *pfVar3 = fVar1 * *(float *)(param_2 + -4 + iVar8 * 4) +
                (_K_ONE - fVar1) * *(float *)((int)pfVar3 + (param_1 - param_3));
      fVar1 = fVar1 + fVar2;
      pfVar3 = pfVar3 + 1;
    } while (iVar8 < in_EAX);
  }
  return;
}


// ==== 0x65ada0 FUN_0065ada0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0065ada0(int param_1,float param_2)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 *unaff_EBX;
  float *unaff_ESI;
  
  fVar2 = param_2 * (float)param_1;
  pbVar1 = (byte *)*unaff_EBX;
  iVar6 = param_1 / 2 + (uint)*pbVar1;
  fVar3 = ((float)param_1 + *unaff_ESI) - fVar2;
  if (param_2 < _K_ONE) {
    fVar2 = ((float)(param_1 * 2 - iVar6) + *unaff_ESI) - (fVar2 + fVar2);
    fVar5 = fVar3;
    if (fVar3 < 0.0) {
      fVar5 = -fVar3;
    }
    fVar4 = fVar2;
    if (fVar2 < 0.0) {
      fVar4 = -fVar2;
    }
    if (fVar5 < fVar4) {
      *unaff_EBX = pbVar1 + 1;
      *unaff_ESI = fVar3;
      return 0;
    }
    *unaff_EBX = pbVar1 + 2;
    *unaff_ESI = fVar2;
    return -iVar6;
  }
  fVar2 = ((float)(iVar6 + param_1) + *unaff_ESI) - fVar2;
  fVar5 = fVar3;
  if (fVar3 < 0.0) {
    fVar5 = -fVar3;
  }
  fVar4 = fVar2;
  if (fVar2 < 0.0) {
    fVar4 = -fVar2;
  }
  if (fVar5 < fVar4) {
    *unaff_EBX = pbVar1 + 1;
    *unaff_ESI = fVar3;
    return 0;
  }
  *unaff_EBX = pbVar1 + 1;
  *unaff_ESI = fVar2;
  return iVar6;
}


// ==== 0x65aeb0 FUN_0065aeb0

void FUN_0065aeb0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (*(int *)(unaff_EBX + 0x34) < 1) {
    puVar1 = (undefined4 *)*param_1;
    puVar4 = puVar1 + *(int *)(unaff_EBX + 0x2c);
  }
  else {
    puVar4 = (undefined4 *)*param_1;
    puVar1 = (undefined4 *)(unaff_EBX + 0x40);
  }
  if (param_2 == 0) {
    puVar5 = (undefined4 *)(unaff_EBX + 0x838);
    for (uVar2 = *(uint *)(unaff_EBX + 0x2c) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar1;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(int *)(unaff_EBX + 0x30) = *(int *)(unaff_EBX + 0x30) - *(int *)(unaff_EBX + 0x2c);
    *(int *)(unaff_EBX + 0x38) = *(int *)(unaff_EBX + 0x2c);
    *param_1 = (int)puVar4;
    *(undefined4 *)(unaff_EBX + 0x34) = 0;
    *(undefined4 *)(unaff_EBX + 0x3c) = 0;
    return;
  }
  if (0 < param_2) {
    puVar5 = puVar1;
    puVar6 = (undefined4 *)(unaff_EBX + 0x838);
    for (iVar3 = param_2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_0065ab70(puVar1,puVar4,unaff_EBX + 0x838 + param_2 * 4,*(undefined4 *)(unaff_EBX + 0x2c));
    *(int *)(unaff_EBX + 0x38) = *(int *)(unaff_EBX + 0x2c) + param_2;
    *(int *)(unaff_EBX + 0x30) = *(int *)(unaff_EBX + 0x30) - *(int *)(unaff_EBX + 0x2c);
    *param_1 = (int)puVar4;
    *(undefined4 *)(unaff_EBX + 0x34) = 0;
    *(undefined4 *)(unaff_EBX + 0x3c) = 0;
    return;
  }
  FUN_0065ab70(puVar1,puVar4,unaff_EBX + 0x838,*(undefined4 *)(unaff_EBX + 0x2c));
  puVar1 = puVar4 + -param_2;
  puVar5 = (undefined4 *)(unaff_EBX + 0x838 + *(int *)(unaff_EBX + 0x2c) * 4);
  for (uVar2 = *(int *)(unaff_EBX + 0x2c) + param_2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar1;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  iVar3 = *(int *)(unaff_EBX + 0x2c);
  *(int *)(unaff_EBX + 0x38) = iVar3 * 2 + param_2;
  *(int *)(unaff_EBX + 0x30) = *(int *)(unaff_EBX + 0x30) + iVar3 * -2;
  *param_1 = (int)(puVar4 + iVar3);
  *(undefined4 *)(unaff_EBX + 0x34) = 0;
  *(undefined4 *)(unaff_EBX + 0x3c) = 0;
  return;
}


// ==== 0x65afe0 FUN_0065afe0

void __fastcall FUN_0065afe0(undefined4 param_1,int param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *param_3;
  if ((int)*(uint *)(param_2 + 0x38) < (int)*param_3) {
    uVar1 = *(uint *)(param_2 + 0x38);
  }
  puVar4 = (undefined4 *)(param_2 + 0x838 + *(int *)(param_2 + 0x3c) * 4);
  puVar5 = (undefined4 *)*param_4;
  for (uVar2 = uVar1 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *(uint *)(param_2 + 0x3c) = *(int *)(param_2 + 0x3c) + uVar1;
  *(uint *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) - uVar1;
  *param_3 = *param_3 - uVar1;
  *param_4 = *param_4 + uVar1 * 4;
  return;
}


// ==== 0x65b040 FUN_0065b040

int FUN_0065b040(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x38) < param_2) {
    iVar6 = param_2 - *(int *)(param_1 + 0x38);
    iVar5 = *(int *)(param_1 + 0x30);
    iVar3 = 0;
    iVar2 = 0;
    param_2 = 0;
    if (0 < iVar6) {
      iVar1 = *(int *)(param_1 + 0x2c);
      do {
        if (iVar5 < iVar1) break;
        iVar3 = iVar1 * 2;
        if (iVar5 < iVar3) {
          iVar2 = 0;
          iVar3 = iVar1;
          iVar4 = iVar1;
        }
        else {
          iVar2 = FUN_0065ada0(iVar1,*(undefined4 *)(param_1 + 0x24));
          if (iVar2 < 0) {
            iVar4 = iVar2 + iVar3;
          }
          else {
            iVar4 = iVar1 + iVar2;
            iVar3 = iVar1;
          }
        }
        param_2 = param_2 + iVar3;
        iVar5 = iVar5 - iVar3;
        if (iVar6 <= iVar4) {
          iVar6 = 0;
          break;
        }
        iVar6 = iVar6 - iVar4;
      } while (0 < iVar6);
      iVar3 = param_2;
      if (0 < iVar2) {
        iVar3 = param_2 + iVar1;
      }
      if (0 < iVar6) {
        if (iVar5 < iVar6) {
          iVar3 = iVar3 + iVar5;
        }
        else {
          iVar3 = iVar3 + iVar6;
        }
      }
    }
    if (*(int *)(param_1 + 0x34) < iVar3) {
      return iVar3 - *(int *)(param_1 + 0x34);
    }
  }
  return 0;
}


// ==== 0x65b130 FUN_0065b130

int FUN_0065b130(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_4;
  
  iVar1 = param_1;
  param_1 = FUN_0065afe0(&param_2,&param_4);
  if ((param_2 != 0) && (local_4 = 0, 0 < (int)param_2)) {
    do {
      iVar3 = *(int *)(iVar1 + 0x2c);
      if (*(int *)(iVar1 + 0x30) < iVar3) break;
      if (*(int *)(iVar1 + 0x30) < iVar3 * 2) {
        local_4 = 0;
      }
      else {
        local_4 = FUN_0065ada0(iVar3,*(undefined4 *)(iVar1 + 0x24));
      }
      FUN_0065aeb0(&param_3,local_4);
      uVar4 = *(uint *)(iVar1 + 0x38);
      if ((int)param_2 <= (int)*(uint *)(iVar1 + 0x38)) {
        uVar4 = param_2;
      }
      puVar5 = (undefined4 *)(iVar1 + 0x838 + *(int *)(iVar1 + 0x3c) * 4);
      puVar6 = param_4;
      for (uVar2 = uVar4 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      param_4 = param_4 + uVar4;
      *(uint *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x3c) + uVar4;
      param_2 = param_2 - uVar4;
      param_1 = param_1 + uVar4;
      *(uint *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) - uVar4;
    } while (0 < (int)param_2);
    if (0 < local_4) {
      puVar5 = param_3;
      puVar6 = (undefined4 *)(iVar1 + 0x40);
      for (uVar4 = *(uint *)(iVar1 + 0x2c) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x2c);
      param_3 = param_3 + *(int *)(iVar1 + 0x2c);
    }
    if (0 < (int)param_2) {
      uVar4 = *(uint *)(iVar1 + 0x30);
      uVar2 = uVar4;
      if ((int)param_2 <= (int)uVar4) {
        uVar4 = param_2;
        uVar2 = param_2;
      }
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_4 = *param_3;
        param_3 = param_3 + 1;
        param_4 = param_4 + 1;
      }
      param_1 = param_1 + uVar2;
      *(uint *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) - uVar2;
    }
  }
  return param_1;
}


// ==== 0x65b290 FUN_0065b290

void FUN_0065b290(int param_1,int param_2)

{
  float fVar1;
  
  fVar1 = (float)param_2 * 0.00024414062;
  *(float *)(param_1 + 0x24) = fVar1;
  if (fVar1 < 0.5) {
    *(undefined4 *)(param_1 + 0x24) = 0x3f000000;
    return;
  }
  if (2.0 < fVar1) {
    *(undefined4 *)(param_1 + 0x24) = 0x40000000;
  }
  return;
}


// ==== 0x65b2d0 FUN_0065b2d0

int FUN_0065b2d0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 8))
                      (*(undefined4 **)(param_1 + 8),200,param_4,param_3,
                       *(undefined1 *)(param_1 + 0x1a));
    return iVar1;
  }
  iVar1 = FUN_0065b040(param_1,param_2);
  if ((-1 < *(int *)(param_1 + 0x20)) &&
     (iVar2 = FUN_00655660(*(int *)(param_1 + 0x20)), iVar2 < iVar1)) {
    return 0;
  }
  if (((iVar1 < 1) ||
      (iVar1 = (*(code *)**(undefined4 **)(param_1 + 8))
                         (*(undefined4 **)(param_1 + 8),iVar1,param_4,param_3,
                          *(undefined1 *)(param_1 + 0x1a)), 0 < iVar1)) &&
     (iVar2 = FUN_0065b130(param_1,param_2,param_3,param_4), iVar1 = param_2, iVar2 < param_2)) {
    FUN_00654cd0(param_4 + iVar2 * 4,(param_2 - iVar2) * 4);
  }
  return iVar1;
}


// ==== 0x65b380 FUN_0065b380

undefined4 FUN_0065b380(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = FUN_0065b2d0;
  param_1[1] = 0;
  if (param_3 < 0) {
    param_1[8] = 0xffffffff;
  }
  else {
    uVar1 = FUN_00659960(param_3);
    uVar1 = FUN_00660820(uVar1);
    param_1[8] = uVar1;
  }
  param_1[7] = param_2 + 6;
  param_1[9] = 0x3f800000;
  param_1[10] = 0;
  param_1[0xb] = (uint)*(byte *)(param_2 + 1) << 1;
  uVar1 = SNDI_getb(param_2 + 2,4);
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0xc] = uVar1;
  return 0;
}


// ==== 0x65b3f0 FUN_0065b3f0

int FUN_0065b3f0(int param_1,int param_2,float *param_3,undefined2 *param_4)

{
  undefined4 *puVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 == (undefined4 *)0x0) ||
     (iVar3 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     0 < iVar3)) {
    pfVar2 = param_3;
    while (iVar3 = param_2, pfVar2 < param_3 + param_2) {
      *pfVar2 = *pfVar2 + 12582912.0;
      uVar4 = (uint)*pfVar2 & 0xfffff;
      if ((0x7fff < uVar4) && (uVar4 < 0xf8000)) {
        uVar4 = (-(uint)(uVar4 < 0x80000) & 0xffff) - 0x8000;
      }
      *param_4 = (short)uVar4;
      param_4 = param_4 + 1;
      pfVar2 = pfVar2 + 1;
    }
  }
  return iVar3;
}


// ==== 0x65b470 FUN_0065b470

void FUN_0065b470(undefined4 *param_1)

{
  *param_1 = FUN_0065b3f0;
  param_1[1] = 0;
  return;
}


// ==== 0x65b490 FUN_0065b490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b490(void)

{
  _DAT_00716498 = FUN_00659250;
  _DAT_007164f8 = 0x2c;
  _DAT_007164a0 = FUN_00660a80;
  _DAT_00716500 = 0x3c;
  _DAT_0071649c = FUN_006593b0;
  _DAT_007164fc = 0x30;
  _DAT_007164a4 = FUN_00659250;
  _DAT_00716504 = 0x2c;
  _DAT_007164ac = FUN_00660a80;
  _DAT_0071650c = 0x3c;
  _DAT_007164a8 = FUN_006593b0;
  _DAT_00716508 = 0x30;
  return;
}


// ==== 0x65b500 FUN_0065b500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b500(void)

{
  _DAT_0071648c = FUN_006594e0;
  _DAT_007164ec = 0x2c;
  _DAT_007164f0 = 0x54;
  _DAT_00716490 = FUN_00659740;
  _DAT_00716494 = FUN_00660c60;
  _DAT_007164f4 = 0x3c;
  return;
}


// ==== 0x65b540 FUN_0065b540

void FUN_0065b540(void)

{
  DAT_00716480 = FUN_006598a0;
  DAT_007164e0 = 0x2c;
  DAT_00716484 = FUN_00660e90;
  DAT_007164e4 = 0x30;
  DAT_00716488 = FUN_00660dd0;
  DAT_007164e8 = 0x34;
  return;
}


// ==== 0x65b580 FUN_0065b580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b580(void)

{
  FUN_00660ed0();
  _DAT_00716474 = FUN_006598a0;
  _DAT_007164d4 = 0x2c;
  _DAT_00716478 = FUN_00660e90;
  _DAT_007164d8 = 0x30;
  _DAT_0071647c = FUN_00660dd0;
  _DAT_007164dc = 0x34;
  return;
}


// ==== 0x65b5d0 FUN_0065b5d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b5d0(undefined4 param_1)

{
  _DAT_007172f0 = param_1;
  return;
}


// ==== 0x65b5e0 FUN_0065b5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b5e0(undefined4 param_1)

{
  _DAT_007172f8 = param_1;
  return;
}


// ==== 0x65b5f0 FUN_0065b5f0

/* WARNING: Removing unreachable block (ram,0x0065b6e6) */
/* WARNING: Removing unreachable block (ram,0x0065b6a3) */
/* WARNING: Removing unreachable block (ram,0x0065b66f) */

ulonglong FUN_0065b5f0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar5;
  undefined1 auStackY_f0 [20];
  _OSVERSIONINFOA local_b8;
  int local_24;
  undefined1 local_20 [16];
  undefined4 local_10;
  
  local_24 = 0;
  local_b8.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_b8);
  puVar4 = (undefined1 *)0x1;
  if ((local_b8.dwPlatformId == 1) && (local_b8.dwMinorVersion == 0)) {
    local_24 = 1;
  }
  local_10 = 1;
  uVar5 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xffffff30,0x20) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
          (uint)((int)auStackY_f0 < 0) * 0x80 |
          (uint)(&stack0x00000000 == (undefined1 *)0xf0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)auStackY_f0 & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0xffffff30 < (undefined1 *)0x20) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar3 = uVar5 ^ 0x200000;
  if (((uint)((uVar3 & 0x4000) != 0) * 0x4000 | (uint)((uVar3 & 0x800) != 0) * 0x800 |
       (uint)((uVar3 & 0x200) != 0) * 0x200 | (uint)((uVar3 & 0x100) != 0) * 0x100 |
       (uint)((uVar3 & 0x80) != 0) * 0x80 | (uint)((uVar3 & 0x40) != 0) * 0x40 |
       (uint)((uVar3 & 0x10) != 0) * 0x10 | (uint)((uVar3 & 4) != 0) * 4 | (uint)((uVar3 & 1) != 0)
       | (uint)((uVar3 & 0x200000) != 0) * 0x200000 | (uint)((uVar3 & 0x40000) != 0) * 0x40000) ==
      uVar5) {
    local_10 = 1;
  }
  else {
    piVar1 = (int *)cpuid_basic_info(0);
    if (*piVar1 == 0) {
      return 0x100000001;
    }
    puVar4 = local_20;
    iVar2 = cpuid_Version_info(1);
    if (((*(uint *)(iVar2 + 8) & 0x2000000) != 0) && (local_24 == 0)) {
      local_10 = 3;
    }
    iVar2 = cpuid(0x80000001);
    if (*(int *)(iVar2 + 8) < 0) {
      return CONCAT44(puVar4,local_10) | 4;
    }
  }
  return CONCAT44(puVar4,local_10);
}


// ==== 0x65b730 FUN_0065b730

ulonglong __fastcall
FUN_0065b730(undefined4 param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            byte *param_5,int param_6,undefined2 *param_7)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined2 *puVar18;
  int iVar19;
  int iVar20;
  
  if (param_4 == (undefined2 *)0x2) {
    iVar7 = (int)param_3 * 2;
    bVar2 = *param_5;
    bVar3 = param_5[1];
    iVar11 = iVar7;
    do {
      iVar8 = *(int *)((uint)bVar3 * iVar7 + param_6 + -4 + iVar11);
      uVar4 = *(uint *)((uint)bVar2 * iVar7 + param_6 + -4 + iVar11);
      *(uint *)(param_7 + iVar11 + -4) = iVar8 << 0x10 | uVar4 & 0xffff;
      *(uint *)(param_7 + iVar11 + -2) =
           CONCAT22((short)((uint)iVar8 >> 0x10),(short)(uVar4 >> 0x10));
      iVar8 = iVar11 + -4;
      bVar5 = 3 < iVar11;
      iVar11 = iVar8;
    } while (iVar8 != 0 && bVar5);
    return CONCAT44(param_2,2);
  }
  if (param_4 == (undefined2 *)0x4) {
    puVar9 = (undefined2 *)(param_6 + (uint)param_5[1] * (int)param_3 * 2);
    puVar6 = (undefined2 *)((uint)param_5[3] * (int)param_3);
    param_2 = param_3;
    if (0 < (int)param_3) {
      iVar7 = (param_6 + (uint)*param_5 * (int)param_3 * 2) - (int)puVar9;
      iVar8 = (param_6 + (uint)param_5[2] * (int)param_3 * 2) - (int)puVar9;
      iVar11 = (param_6 + (int)((uint)param_5[3] * (int)param_3) * 2) - (int)puVar9;
      param_4 = param_3;
      do {
        *param_7 = *(undefined2 *)(iVar7 + (int)puVar9);
        param_7[1] = *puVar9;
        param_7[2] = *(undefined2 *)(iVar8 + (int)puVar9);
        param_7[3] = *(undefined2 *)(iVar11 + (int)puVar9);
        param_7 = param_7 + 4;
        puVar9 = puVar9 + 1;
        param_4 = (undefined2 *)((int)param_4 + -1);
      } while (param_4 != (undefined2 *)0x0);
      return ZEXT48(param_7);
    }
  }
  else {
    puVar6 = param_4;
    if (param_4 == (undefined2 *)0x6) {
      iVar11 = param_6 + (uint)*param_5 * (int)param_3 * 2;
      iVar7 = param_6 + (uint)param_5[1] * (int)param_3 * 2;
      iVar8 = param_6 + (uint)param_5[2] * (int)param_3 * 2;
      iVar1 = param_6 + (uint)param_5[3] * (int)param_3 * 2;
      puVar9 = (undefined2 *)(param_6 + (uint)param_5[4] * (int)param_3 * 2);
      param_2 = (undefined2 *)(param_6 + (uint)param_5[5] * (int)param_3 * 2);
      puVar6 = param_3;
      if (0 < (int)param_3) {
        iVar12 = (int)puVar9 - iVar7;
        iVar13 = (int)param_2 - iVar7;
        puVar10 = (undefined2 *)(iVar7 + 2);
        iVar14 = (int)puVar9 - iVar8;
        iVar15 = (int)param_2 - iVar8;
        iVar16 = (int)puVar9 - iVar1;
        iVar17 = (int)param_2 - iVar1;
        iVar19 = iVar11 - (int)puVar9;
        iVar20 = (int)param_2 - (int)puVar9;
        puVar18 = (undefined2 *)(iVar1 + 6);
        param_2 = (undefined2 *)(iVar8 + 4);
        puVar6 = param_7 + 2;
        param_4 = (undefined2 *)(((int)param_3 - 1U >> 2) + 1);
        do {
          puVar6[-2] = *(undefined2 *)(iVar19 + (int)puVar9);
          puVar6[-1] = puVar10[-1];
          *puVar6 = param_2[-2];
          puVar6[1] = puVar18[-3];
          puVar6[2] = *puVar9;
          puVar6[3] = *(undefined2 *)(iVar20 + (int)puVar9);
          puVar6[4] = *(undefined2 *)((iVar11 - iVar7) + (int)puVar10);
          puVar6[5] = *puVar10;
          puVar6[6] = *(undefined2 *)((iVar8 - iVar7) + (int)puVar10);
          puVar6[7] = *(undefined2 *)((iVar1 - iVar7) + (int)puVar10);
          puVar6[8] = *(undefined2 *)(iVar12 + (int)puVar10);
          puVar6[9] = *(undefined2 *)(iVar13 + (int)puVar10);
          puVar6[10] = *(undefined2 *)((int)param_2 + (iVar11 - iVar8));
          puVar6[0xb] = puVar10[1];
          puVar6[0xc] = *param_2;
          puVar6[0xd] = *(undefined2 *)((int)param_2 + (iVar1 - iVar8));
          puVar6[0xe] = *(undefined2 *)((int)param_2 + iVar14);
          puVar6[0xf] = *(undefined2 *)((int)param_2 + iVar15);
          puVar6[0x10] = *(undefined2 *)((int)puVar18 + (iVar11 - iVar1));
          puVar6[0x11] = puVar10[2];
          puVar6[0x12] = param_2[1];
          puVar6[0x13] = *puVar18;
          puVar6[0x14] = *(undefined2 *)((int)puVar18 + iVar16);
          puVar6[0x15] = *(undefined2 *)((int)puVar18 + iVar17);
          puVar6 = puVar6 + 0x18;
          puVar10 = puVar10 + 4;
          puVar9 = puVar9 + 4;
          param_2 = param_2 + 4;
          puVar18 = puVar18 + 4;
          param_4 = (undefined2 *)((int)param_4 + -1);
        } while (param_4 != (undefined2 *)0x0);
      }
    }
  }
  return CONCAT44(param_2,puVar6);
}


// ==== 0x65ba20 FUN_0065ba20

void FUN_0065ba20(int param_1,int param_2,float *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = -(param_2 >> 6 & 0x3ffU);
  iVar1 = FUN_006527a0(iVar2 + 0x400);
  iVar2 = FUN_006527a0(iVar2 + 0x500);
  iVar3 = FUN_006527a0(param_1 >> 6);
  iVar4 = FUN_006527a0((param_1 >> 6) + 0x100);
  *param_3 = (float)iVar3 * (float)iVar2 * 1.5258789e-05;
  param_3[1] = (float)iVar1 * -1.0;
  param_3[2] = (float)iVar4 * (float)iVar2 * 1.5258789e-05;
  return;
}


// ==== 0x65bab0 FUN_0065bab0

void FUN_0065bab0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = param_1 * 0x60 + DAT_0071666c;
  if (0x40000 < param_2) {
    param_2 = 0x40000;
  }
  if (*(int *)(iVar2 + 0x50) == 0) {
    iVar1 = FUN_00650fd0(0x3c);
    *(int *)(iVar2 + 0x50) = iVar1;
    bVar3 = 0x31 < DAT_0071646e;
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined2 *)(*(int *)(iVar2 + 0x50) + 0x18) = 0xa0;
    *(undefined1 *)(*(int *)(iVar2 + 0x50) + 0x1a) = 0;
    FUN_00661120(*(undefined4 *)(iVar2 + 0x50),DAT_00713eeb,bVar3);
    FUN_006577e0(iVar2 + 0x40,*(undefined4 *)(iVar2 + 0x50));
  }
  FUN_00660f00(*(undefined4 *)(iVar2 + 0x50),param_2);
  return;
}


// ==== 0x65bb50 FUN_0065bb50

void FUN_0065bb50(int param_1)

{
  if (*(int *)(param_1 * 0x60 + DAT_0071666c + 0x4c) != 0) {
    FUN_0065b290();
    return;
  }
  return;
}


// ==== 0x65bb80 FUN_0065bb80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065bb80(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  iVar2 = param_1 * 0x60 + DAT_0071666c;
  if (param_2 < _K_ONE) {
    if (*(int *)(iVar2 + 0x58) == 0) {
      iVar1 = FUN_00650fd0(0x28);
      *(int *)(iVar2 + 0x58) = iVar1;
      *(undefined4 *)(iVar1 + 4) = 0;
      *(undefined2 *)(*(int *)(iVar2 + 0x58) + 0x18) = 0x28;
      *(undefined1 *)(*(int *)(iVar2 + 0x58) + 0x1a) = 0;
      FUN_00659f30(*(undefined4 *)(iVar2 + 0x58));
      FUN_006577e0(iVar2 + 0x40,*(undefined4 *)(iVar2 + 0x58));
    }
    local_8 = (uint)DAT_00713d9a << 8;
    local_c = (int)ROUND((float)DAT_00713d9a * param_2) << 7;
    local_4 = 0x100;
    FUN_00659f60(*(undefined4 *)(iVar2 + 0x58),&local_c);
    return;
  }
  if (*(int *)(iVar2 + 0x58) != 0) {
    FUN_00657820(iVar2 + 0x40,*(int *)(iVar2 + 0x58));
    FUN_006510d0(*(undefined4 *)(iVar2 + 0x58));
    *(undefined4 *)(iVar2 + 0x58) = 0;
  }
  return;
}


// ==== 0x65bc70 FUN_0065bc70

void FUN_0065bc70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  int local_4;
  
  iVar2 = param_1 * 0x60 + DAT_0071666c;
  if (0 < param_2) {
    if (*(int *)(iVar2 + 0x5c) == 0) {
      iVar1 = FUN_00650fd0(0x58);
      *(int *)(iVar2 + 0x5c) = iVar1;
      *(undefined4 *)(iVar1 + 4) = 0;
      *(undefined2 *)(*(int *)(iVar2 + 0x5c) + 0x18) = 0x50;
      *(undefined1 *)(*(int *)(iVar2 + 0x5c) + 0x1a) = 0;
      FUN_0065bdb0(*(undefined4 *)(iVar2 + 0x5c));
      FUN_006577e0(iVar2 + 0x40,*(undefined4 *)(iVar2 + 0x5c));
    }
    local_4 = (uint)DAT_00713d9a << 8;
    local_8 = param_2 << 8;
    FUN_0065bde0(*(undefined4 *)(iVar2 + 0x5c),&local_8);
    return;
  }
  if (*(int *)(iVar2 + 0x5c) != 0) {
    FUN_00657820(iVar2 + 0x40,*(int *)(iVar2 + 0x5c));
    FUN_006510d0(*(undefined4 *)(iVar2 + 0x5c));
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  return;
}


// ==== 0x65bd30 FUN_0065bd30

undefined4 FUN_0065bd30(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 * 0x60 + DAT_0071666c + 0x44);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0065bd50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xffffffff;
}


// ==== 0x65bd60 FUN_0065bd60

int FUN_0065bd60(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 != (undefined4 *)0x0) &&
     (param_2 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     param_2 < 1)) {
    return param_2;
  }
  FUN_00661210(param_1 + 0x1c,param_2,param_3,param_4);
  return param_2;
}


// ==== 0x65bdb0 FUN_0065bdb0

undefined4 FUN_0065bdb0(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = 0;
  *param_1 = FUN_0065bd60;
  FUN_006611f0(param_1 + 7);
  return 0;
}


// ==== 0x65bde0 FUN_0065bde0

void FUN_0065bde0(int param_1,int *param_2)

{
  *(float *)(param_1 + 0x50) = (float)(*param_2 >> 7) / (float)(param_2[1] >> 8);
  FUN_00661460();
  return;
}


// ==== 0x65be20 FUN_0065be20

int FUN_0065be20(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 *param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = 0;
  iVar2 = 0;
  local_14 = 1;
  local_4 = 0;
  if (param_2 == 8) {
    iVar2 = 1;
  }
  else if (param_2 == 9) {
    iVar2 = 0;
    local_14 = 0;
  }
  else if (param_2 == 10) {
    iVar2 = 2;
  }
  else if (param_2 == 4) {
    iVar2 = 3;
  }
  else if (param_2 == 0x16) {
    iVar2 = 4;
  }
  else if (param_2 == 0x10) {
    iVar2 = 5;
  }
  else if (param_2 == 0x17) {
    iVar2 = 6;
  }
  else if (param_2 == 0x40) {
    iVar2 = 7;
  }
  iVar3 = 0;
  if (param_1 == 0) {
    iVar3 = 2;
  }
  else if (0 < param_4) {
    iVar3 = 1;
  }
  iVar2 = (iVar3 + iVar2 * 3) * 4;
  if (*(int *)(&DAT_00716474 + iVar2) != 0) {
    iVar1 = FUN_00650fd0(*(undefined4 *)(&DAT_007164d4 + iVar2));
    *(undefined1 *)(iVar1 + 0x1a) = 0;
    *(undefined4 *)(iVar1 + 4) = 0;
    local_c = (uint)DAT_00713eeb;
    local_8 = param_8;
    local_10 = param_7;
    local_24 = param_5;
    local_2c[0] = param_1;
    local_20 = param_6;
    local_1c = param_3;
    local_18 = param_4;
    (**(code **)(&DAT_00716474 + iVar2))(iVar1,local_2c);
    *param_9 = local_4;
  }
  return iVar1;
}


// ==== 0x65bf50 FUN_0065bf50

uint FUN_0065bf50(void)

{
  uint uVar1;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar2;
  undefined1 auStack_2c [32];
  
  uVar2 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffff4,0x20) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)auStack_2c < 0) * 0x80
          | (uint)(&stack0x00000000 == (undefined1 *)0x2c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)auStack_2c & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0xfffffff4 < (undefined1 *)0x20) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar1 = uVar2 ^ 0x200000;
  return ((uint)((uVar1 & 0x4000) != 0) * 0x4000 | (uint)((uVar1 & 0x800) != 0) * 0x800 |
          (uint)((uVar1 & 0x200) != 0) * 0x200 | (uint)((uVar1 & 0x100) != 0) * 0x100 |
          (uint)((uVar1 & 0x80) != 0) * 0x80 | (uint)((uVar1 & 0x40) != 0) * 0x40 |
          (uint)((uVar1 & 0x10) != 0) * 0x10 | (uint)((uVar1 & 4) != 0) * 4 |
          (uint)((uVar1 & 1) != 0) | (uint)((uVar1 & 0x200000) != 0) * 0x200000 |
         (uint)((uVar1 & 0x40000) != 0) * 0x40000) ^ uVar2;
}


// ==== 0x65bf6d FUN_0065bf6d

undefined8 __fastcall
FUN_0065bf6d(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_4 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_4 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_4 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_4 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_4 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_4 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_4 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_4 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_4 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_4 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_4 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_4 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_4 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_4 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_4 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_4 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_4);
  }
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *param_3 = *puVar1;
  param_3[1] = uVar4;
  param_3[2] = uVar2;
  param_3[3] = uVar3;
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x65bfa0 SNDPLATFORM_playtimbre

/* [canon] audio med (ghidra) docs/re/sound.md */

void SNDPLATFORM_playtimbre
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int aiStack_30 [12];
  
  aiStack_30[7] = 0;
  aiStack_30[1] = 0;
  aiStack_30[8] = 0;
  aiStack_30[2] = 0;
  cVar1 = *(char *)(param_1 + 3);
  iVar3 = 0;
  aiStack_30[9] = 0;
  aiStack_30[3] = 0;
  aiStack_30[10] = 0;
  aiStack_30[4] = 0;
  aiStack_30[6] = 0;
  aiStack_30[0xb] = 0;
  aiStack_30[0] = 0;
  aiStack_30[5] = 0;
  if (0 < cVar1) {
    iVar2 = *(int *)(param_1 + 0x68);
    piVar4 = (int *)(param_1 + 0x80);
    do {
      aiStack_30[iVar3 + 6] = piVar4[-6] + param_2;
      aiStack_30[iVar3] = *piVar4 + iVar2 + param_2;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < cVar1);
  }
  FUN_00651540(param_3,*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),0,0,param_6,
               param_7,aiStack_30 + 6,aiStack_30,param_1 + 0x98,*(undefined4 *)(param_1 + 200),
               (int)*(char *)(param_1 + 2));
  return;
}


// ==== 0x65c060 SNDI_pantoazimuth

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined2 SNDI_pantoazimuth(int param_1)

{
  return *(undefined2 *)(param_1 * 2 + 0x6ea690);
}


// ==== 0x65c070 FUN_0065c070

int FUN_0065c070(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0x10001) {
    if (param_1 < 0) {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0x10000;
  }
  uVar1 = iSNDrandom();
  return (int)(((uVar1 & 0x7fff) - 0x4000) * param_1) >> 0xe;
}


// ==== 0x65c0b0 SNDover__is_sound_finished_

/* [canon] audio med (ghidra) docs/re/sound.md */

uint SNDover__is_sound_finished_(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = SNDVOICEI_get__validate_handle____voice_index_(param_1);
  return (uint)(iVar1 < 0);
}


// ==== 0x65c0e0 FUN_0065c0e0

void FUN_0065c0e0(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    iVar1 = 0;
    do {
      if ((param_1[1] & 3) == 1) {
        *(undefined4 *)(param_3 + iVar1 * 4) = 0xc0000000;
        uVar4 = (uint)param_1[1] >> 2;
        iVar5 = param_1[2] + -2;
      }
      else if ((param_1[1] & 3) == 3) {
        *(undefined4 *)(param_3 + iVar1 * 4) = 0x40000000;
        uVar4 = (uint)param_1[1] >> 2;
        iVar5 = param_1[2] + -2;
      }
      else {
        *(undefined4 *)(param_3 + iVar1 * 4) = 0;
        uVar4 = (uint)param_1[1] >> 1;
        iVar5 = param_1[2] + -1;
      }
      param_1[1] = uVar4;
      param_1[2] = iVar5;
      if (iVar5 < 8) {
        param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar5 & 0x1f) | param_1[1];
        *param_1 = (byte *)*param_1 + 1;
        param_1[2] = iVar5 + 8;
      }
      iVar1 = iVar1 + param_4;
    } while (iVar1 < 0x6c);
    return;
  }
  iVar1 = 0;
  iVar5 = 0;
  param_2 = 0;
  do {
    uVar4 = (uint)(byte)(&DAT_006ea8b8)[iVar1 * 0x100 + (param_1[1] & 0xff)];
    iVar2 = uVar4 * 0xc;
    iVar1 = *(int *)(&DAT_006eaab8 + iVar2);
    iVar3 = *(int *)(&DAT_006eaabc + iVar2);
    param_1[2] = param_1[2] - iVar3;
    uVar6 = (uint)param_1[1] >> ((byte)iVar3 & 0x1f);
    iVar3 = param_1[2];
    param_1[1] = uVar6;
    if (iVar3 < 8) {
      param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar3 & 0x1f) | uVar6;
      *param_1 = (byte *)*param_1 + 1;
      param_1[2] = iVar3 + 8;
      iVar5 = param_2;
    }
    if (uVar4 < 4) {
      if (uVar4 < 2) {
        param_2 = 7;
        while( true ) {
          uVar6 = param_1[1] & DAT_006ea794;
          iVar3 = param_1[2];
          uVar4 = (uint)param_1[1] >> 1;
          iVar2 = iVar3 + -1;
          param_1[1] = uVar4;
          param_1[2] = iVar2;
          if (iVar2 < 8) {
            param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar2 & 0x1f) | uVar4;
            *param_1 = (byte *)*param_1 + 1;
            param_1[2] = iVar3 + 7;
          }
          if (uVar6 != 1) break;
          param_2 = param_2 + 1;
        }
        uVar6 = param_1[1] & DAT_006ea794;
        iVar3 = param_1[2];
        uVar4 = (uint)param_1[1] >> 1;
        iVar2 = iVar3 + -1;
        param_1[1] = uVar4;
        param_1[2] = iVar2;
        if (iVar2 < 8) {
          param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar2 & 0x1f) | uVar4;
          *param_1 = (byte *)*param_1 + 1;
          param_1[2] = iVar3 + 7;
        }
        if (uVar6 == 1) {
          *(float *)(param_3 + iVar5 * 4) = (float)param_2;
        }
        else {
          *(float *)(param_3 + iVar5 * 4) = (float)-param_2;
        }
        goto LAB_0065c2a0;
      }
      uVar6 = param_1[1] & DAT_006ea7a8;
      iVar3 = param_1[2];
      iVar2 = iVar3 + -6;
      uVar4 = (uint)param_1[1] >> 6;
      param_1[1] = uVar4;
      param_1[2] = iVar2;
      if (iVar2 < 8) {
        param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar2 & 0x1f) | uVar4;
        *param_1 = (byte *)*param_1 + 1;
        param_1[2] = iVar3 + 2;
      }
      iVar3 = uVar6 + 7;
      if (0x6c < iVar3 * param_4 + iVar5) {
        iVar3 = (0x6c - iVar5) / param_4;
      }
      if (0 < iVar3) {
        do {
          *(undefined4 *)(param_3 + iVar5 * 4) = 0;
          iVar5 = iVar5 + param_4;
          iVar3 = iVar3 + -1;
          param_2 = iVar5;
        } while (iVar3 != 0);
      }
    }
    else {
      *(undefined4 *)(param_3 + iVar5 * 4) = *(undefined4 *)(&DAT_006eaac0 + iVar2);
LAB_0065c2a0:
      iVar5 = iVar5 + param_4;
      param_2 = iVar5;
    }
    if (0x6b < iVar5) {
      return;
    }
  } while( true );
}


// ==== 0x65c340 FUN_0065c340

void FUN_0065c340(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int unaff_EBX;
  int iVar6;
  float local_60 [12];
  float local_30 [12];
  
  iVar6 = 10;
  do {
    iVar2 = iVar6 + -1;
    local_60[iVar6 + 1] = *(float *)(param_1 + 4 + iVar2 * 4);
    iVar6 = iVar2;
  } while (-1 < iVar2);
  iVar6 = 0;
  local_60[0] = 1.0;
  do {
    local_60[0] = -(local_60[0xb] * *(float *)(param_1 + 0x2c));
    pfVar3 = (float *)(param_1 + 0x28);
    iVar2 = 10;
    do {
      iVar4 = iVar2 + -1;
      local_60[0] = local_60[0] - local_60[iVar2] * *pfVar3;
      *(float *)((int)pfVar3 + (int)local_60 + (4 - param_1)) =
           local_60[0] * *pfVar3 + local_60[iVar2];
      pfVar3 = pfVar3 + -1;
      iVar2 = iVar4;
    } while (-1 < iVar4);
    iVar2 = 0;
    local_60[iVar6 + 0xc] = local_60[0];
    if (3 < iVar6) {
      iVar4 = 3;
      pfVar3 = (float *)(unaff_EBX + 8);
      pfVar5 = local_60 + iVar6 + 10;
      do {
        iVar4 = iVar4 + 4;
        iVar2 = iVar2 + 4;
        local_60[0] = (((local_60[0] - pfVar5[1] * pfVar3[-2]) - pfVar3[-1] * *pfVar5) -
                      pfVar5[-1] * *pfVar3) - pfVar5[-2] * pfVar3[1];
        pfVar3 = pfVar3 + 4;
        pfVar5 = pfVar5 + -4;
      } while (iVar4 < iVar6);
    }
    if (iVar2 < iVar6) {
      pfVar3 = local_60 + (iVar6 - iVar2) + 0xb;
      do {
        iVar4 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        fVar1 = *pfVar3;
        pfVar3 = pfVar3 + -1;
        local_60[0] = local_60[0] - *(float *)(unaff_EBX + iVar4) * fVar1;
      } while (iVar2 < iVar6);
    }
    iVar2 = iVar6 * 4;
    iVar6 = iVar6 + 1;
    *(float *)(unaff_EBX + iVar2) = local_60[0];
  } while (iVar6 < 0xc);
  return;
}


// ==== 0x65c440 FUN_0065c440

void FUN_0065c440(int param_1)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  float *pfVar4;
  float *pfVar5;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar5 = (float *)(unaff_ESI + 0x684 + in_EAX * 4);
  FUN_0065c340(unaff_ESI + 0x114);
  iVar3 = 0;
  if (3 < param_1) {
    iVar2 = 3;
    pfVar4 = pfVar5;
    do {
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x150) +
              local_14 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x14c) +
              local_18 * *(float *)(unaff_ESI + 0x15c) +
              local_8 * *(float *)(unaff_ESI + 0x16c) +
              local_4 * *(float *)(unaff_ESI + 0x170) +
              local_2c * *(float *)(unaff_ESI + 0x148) +
              local_1c * *(float *)(unaff_ESI + 0x158) +
              local_c * *(float *)(unaff_ESI + 0x168) +
              local_30 * *(float *)(unaff_ESI + 0x144) +
              local_20 * *(float *)(unaff_ESI + 0x154) + local_10 * *(float *)(unaff_ESI + 0x164) +
              *pfVar4;
      *(float *)(unaff_ESI + 0x170) = fVar1;
      *pfVar4 = fVar1;
      fVar1 = local_20 * *(float *)(unaff_ESI + 0x150) +
              local_10 * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x14c) +
              local_14 * *(float *)(unaff_ESI + 0x15c) +
              local_4 * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x148) +
              local_18 * *(float *)(unaff_ESI + 0x158) +
              local_8 * *(float *)(unaff_ESI + 0x168) +
              local_2c * *(float *)(unaff_ESI + 0x144) +
              local_1c * *(float *)(unaff_ESI + 0x154) + local_c * *(float *)(unaff_ESI + 0x164) +
              pfVar4[1];
      *(float *)(unaff_ESI + 0x16c) = fVar1;
      pfVar4[1] = fVar1;
      fVar1 = local_1c * *(float *)(unaff_ESI + 0x150) +
              local_c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x16c) +
              local_2c * *(float *)(unaff_ESI + 0x170) +
              local_20 * *(float *)(unaff_ESI + 0x14c) +
              local_10 * *(float *)(unaff_ESI + 0x15c) +
              local_24 * *(float *)(unaff_ESI + 0x148) +
              local_14 * *(float *)(unaff_ESI + 0x158) +
              local_4 * *(float *)(unaff_ESI + 0x168) +
              local_28 * *(float *)(unaff_ESI + 0x144) +
              local_18 * *(float *)(unaff_ESI + 0x154) + local_8 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[2];
      *(float *)(unaff_ESI + 0x168) = fVar1;
      pfVar4[2] = fVar1;
      fVar1 = local_18 * *(float *)(unaff_ESI + 0x150) +
              local_8 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x170) +
              local_1c * *(float *)(unaff_ESI + 0x14c) +
              local_c * *(float *)(unaff_ESI + 0x15c) +
              local_30 * *(float *)(unaff_ESI + 0x168) +
              local_20 * *(float *)(unaff_ESI + 0x148) +
              local_10 * *(float *)(unaff_ESI + 0x158) +
              local_24 * *(float *)(unaff_ESI + 0x144) +
              local_14 * *(float *)(unaff_ESI + 0x154) + local_4 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[3];
      *(float *)(unaff_ESI + 0x164) = fVar1;
      pfVar4[3] = fVar1;
      fVar1 = local_14 * *(float *)(unaff_ESI + 0x150) +
              local_4 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x16c) +
              local_24 * *(float *)(unaff_ESI + 0x170) +
              local_18 * *(float *)(unaff_ESI + 0x14c) +
              local_8 * *(float *)(unaff_ESI + 0x15c) +
              local_2c * *(float *)(unaff_ESI + 0x168) +
              local_1c * *(float *)(unaff_ESI + 0x148) +
              local_c * *(float *)(unaff_ESI + 0x158) +
              local_30 * *(float *)(unaff_ESI + 0x164) +
              local_20 * *(float *)(unaff_ESI + 0x144) + local_10 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[4];
      *(float *)(unaff_ESI + 0x160) = fVar1;
      pfVar4[4] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x160) +
              local_10 * *(float *)(unaff_ESI + 0x150) +
              local_24 * *(float *)(unaff_ESI + 0x16c) +
              local_20 * *(float *)(unaff_ESI + 0x170) +
              local_14 * *(float *)(unaff_ESI + 0x14c) +
              local_4 * *(float *)(unaff_ESI + 0x15c) +
              local_28 * *(float *)(unaff_ESI + 0x168) +
              local_18 * *(float *)(unaff_ESI + 0x148) +
              local_8 * *(float *)(unaff_ESI + 0x158) +
              local_2c * *(float *)(unaff_ESI + 0x164) +
              local_1c * *(float *)(unaff_ESI + 0x144) + local_c * *(float *)(unaff_ESI + 0x154) +
              pfVar4[5];
      *(float *)(unaff_ESI + 0x15c) = fVar1;
      pfVar4[5] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x160) +
              local_c * *(float *)(unaff_ESI + 0x150) +
              local_30 * *(float *)(unaff_ESI + 0x15c) +
              local_20 * *(float *)(unaff_ESI + 0x16c) +
              local_1c * *(float *)(unaff_ESI + 0x170) +
              local_10 * *(float *)(unaff_ESI + 0x14c) +
              local_24 * *(float *)(unaff_ESI + 0x168) +
              local_14 * *(float *)(unaff_ESI + 0x148) +
              local_4 * *(float *)(unaff_ESI + 0x158) +
              local_28 * *(float *)(unaff_ESI + 0x164) +
              local_18 * *(float *)(unaff_ESI + 0x144) + local_8 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[6];
      *(float *)(unaff_ESI + 0x158) = fVar1;
      pfVar4[6] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x160) +
              local_8 * *(float *)(unaff_ESI + 0x150) +
              local_2c * *(float *)(unaff_ESI + 0x15c) +
              local_1c * *(float *)(unaff_ESI + 0x16c) +
              local_18 * *(float *)(unaff_ESI + 0x170) +
              local_c * *(float *)(unaff_ESI + 0x14c) +
              local_30 * *(float *)(unaff_ESI + 0x158) +
              local_20 * *(float *)(unaff_ESI + 0x168) +
              local_10 * *(float *)(unaff_ESI + 0x148) +
              local_24 * *(float *)(unaff_ESI + 0x164) +
              local_14 * *(float *)(unaff_ESI + 0x144) + local_4 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[7];
      *(float *)(unaff_ESI + 0x154) = fVar1;
      pfVar4[7] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x160) +
              local_4 * *(float *)(unaff_ESI + 0x150) +
              local_28 * *(float *)(unaff_ESI + 0x15c) +
              local_18 * *(float *)(unaff_ESI + 0x16c) +
              local_14 * *(float *)(unaff_ESI + 0x170) +
              local_8 * *(float *)(unaff_ESI + 0x14c) +
              local_2c * *(float *)(unaff_ESI + 0x158) +
              local_1c * *(float *)(unaff_ESI + 0x168) +
              local_c * *(float *)(unaff_ESI + 0x148) +
              local_30 * *(float *)(unaff_ESI + 0x154) +
              local_20 * *(float *)(unaff_ESI + 0x164) + local_10 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[8];
      *(float *)(unaff_ESI + 0x150) = fVar1;
      pfVar4[8] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x150) +
              local_20 * *(float *)(unaff_ESI + 0x160) +
              local_24 * *(float *)(unaff_ESI + 0x15c) +
              local_14 * *(float *)(unaff_ESI + 0x16c) +
              local_10 * *(float *)(unaff_ESI + 0x170) +
              local_4 * *(float *)(unaff_ESI + 0x14c) +
              local_28 * *(float *)(unaff_ESI + 0x158) +
              local_18 * *(float *)(unaff_ESI + 0x168) +
              local_8 * *(float *)(unaff_ESI + 0x148) +
              local_2c * *(float *)(unaff_ESI + 0x154) +
              local_1c * *(float *)(unaff_ESI + 0x164) + local_c * *(float *)(unaff_ESI + 0x144) +
              pfVar4[9];
      *(float *)(unaff_ESI + 0x14c) = fVar1;
      pfVar4[9] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x150) +
              local_1c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x14c) +
              local_20 * *(float *)(unaff_ESI + 0x15c) +
              local_10 * *(float *)(unaff_ESI + 0x16c) +
              local_c * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x158) +
              local_14 * *(float *)(unaff_ESI + 0x168) +
              local_4 * *(float *)(unaff_ESI + 0x148) +
              local_28 * *(float *)(unaff_ESI + 0x154) +
              local_18 * *(float *)(unaff_ESI + 0x164) + local_8 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[10];
      *(float *)(unaff_ESI + 0x148) = fVar1;
      pfVar4[10] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x150) +
              local_18 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x14c) +
              local_1c * *(float *)(unaff_ESI + 0x15c) +
              local_c * *(float *)(unaff_ESI + 0x16c) +
              local_8 * *(float *)(unaff_ESI + 0x170) +
              local_30 * *(float *)(unaff_ESI + 0x148) +
              local_20 * *(float *)(unaff_ESI + 0x158) +
              local_10 * *(float *)(unaff_ESI + 0x168) +
              local_24 * *(float *)(unaff_ESI + 0x154) +
              local_14 * *(float *)(unaff_ESI + 0x164) + local_4 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0xb];
      *(float *)(unaff_ESI + 0x144) = fVar1;
      pfVar4[0xb] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x150) +
              local_14 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x14c) +
              local_18 * *(float *)(unaff_ESI + 0x15c) +
              local_8 * *(float *)(unaff_ESI + 0x16c) +
              local_4 * *(float *)(unaff_ESI + 0x170) +
              local_2c * *(float *)(unaff_ESI + 0x148) +
              local_1c * *(float *)(unaff_ESI + 0x158) +
              local_c * *(float *)(unaff_ESI + 0x168) +
              local_30 * *(float *)(unaff_ESI + 0x144) +
              local_20 * *(float *)(unaff_ESI + 0x154) + local_10 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0xc];
      *(float *)(unaff_ESI + 0x170) = fVar1;
      pfVar4[0xc] = fVar1;
      fVar1 = local_20 * *(float *)(unaff_ESI + 0x150) +
              local_10 * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x14c) +
              local_14 * *(float *)(unaff_ESI + 0x15c) +
              local_4 * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x148) +
              local_18 * *(float *)(unaff_ESI + 0x158) +
              local_8 * *(float *)(unaff_ESI + 0x168) +
              local_2c * *(float *)(unaff_ESI + 0x144) +
              local_1c * *(float *)(unaff_ESI + 0x154) + local_c * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0xd];
      *(float *)(unaff_ESI + 0x16c) = fVar1;
      pfVar4[0xd] = fVar1;
      fVar1 = local_1c * *(float *)(unaff_ESI + 0x150) +
              local_c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x16c) +
              local_2c * *(float *)(unaff_ESI + 0x170) +
              local_20 * *(float *)(unaff_ESI + 0x14c) +
              local_10 * *(float *)(unaff_ESI + 0x15c) +
              local_24 * *(float *)(unaff_ESI + 0x148) +
              local_14 * *(float *)(unaff_ESI + 0x158) +
              local_4 * *(float *)(unaff_ESI + 0x168) +
              local_28 * *(float *)(unaff_ESI + 0x144) +
              local_18 * *(float *)(unaff_ESI + 0x154) + local_8 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0xe];
      *(float *)(unaff_ESI + 0x168) = fVar1;
      pfVar4[0xe] = fVar1;
      fVar1 = local_18 * *(float *)(unaff_ESI + 0x150) +
              local_8 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x170) +
              local_1c * *(float *)(unaff_ESI + 0x14c) +
              local_c * *(float *)(unaff_ESI + 0x15c) +
              local_30 * *(float *)(unaff_ESI + 0x168) +
              local_20 * *(float *)(unaff_ESI + 0x148) +
              local_10 * *(float *)(unaff_ESI + 0x158) +
              local_24 * *(float *)(unaff_ESI + 0x144) +
              local_14 * *(float *)(unaff_ESI + 0x154) + local_4 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0xf];
      *(float *)(unaff_ESI + 0x164) = fVar1;
      pfVar4[0xf] = fVar1;
      fVar1 = local_14 * *(float *)(unaff_ESI + 0x150) +
              local_4 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x16c) +
              local_24 * *(float *)(unaff_ESI + 0x170) +
              local_18 * *(float *)(unaff_ESI + 0x14c) +
              local_8 * *(float *)(unaff_ESI + 0x15c) +
              local_2c * *(float *)(unaff_ESI + 0x168) +
              local_1c * *(float *)(unaff_ESI + 0x148) +
              local_c * *(float *)(unaff_ESI + 0x158) +
              local_30 * *(float *)(unaff_ESI + 0x164) +
              local_20 * *(float *)(unaff_ESI + 0x144) + local_10 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x10];
      *(float *)(unaff_ESI + 0x160) = fVar1;
      pfVar4[0x10] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x160) +
              local_10 * *(float *)(unaff_ESI + 0x150) +
              local_24 * *(float *)(unaff_ESI + 0x16c) +
              local_20 * *(float *)(unaff_ESI + 0x170) +
              local_14 * *(float *)(unaff_ESI + 0x14c) +
              local_4 * *(float *)(unaff_ESI + 0x15c) +
              local_28 * *(float *)(unaff_ESI + 0x168) +
              local_18 * *(float *)(unaff_ESI + 0x148) +
              local_8 * *(float *)(unaff_ESI + 0x158) +
              local_2c * *(float *)(unaff_ESI + 0x164) +
              local_1c * *(float *)(unaff_ESI + 0x144) + local_c * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x11];
      *(float *)(unaff_ESI + 0x15c) = fVar1;
      pfVar4[0x11] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x160) +
              local_c * *(float *)(unaff_ESI + 0x150) +
              local_30 * *(float *)(unaff_ESI + 0x15c) +
              local_20 * *(float *)(unaff_ESI + 0x16c) +
              local_1c * *(float *)(unaff_ESI + 0x170) +
              local_10 * *(float *)(unaff_ESI + 0x14c) +
              local_24 * *(float *)(unaff_ESI + 0x168) +
              local_14 * *(float *)(unaff_ESI + 0x148) +
              local_4 * *(float *)(unaff_ESI + 0x158) +
              local_28 * *(float *)(unaff_ESI + 0x164) +
              local_18 * *(float *)(unaff_ESI + 0x144) + local_8 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x12];
      *(float *)(unaff_ESI + 0x158) = fVar1;
      pfVar4[0x12] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x160) +
              local_8 * *(float *)(unaff_ESI + 0x150) +
              local_2c * *(float *)(unaff_ESI + 0x15c) +
              local_1c * *(float *)(unaff_ESI + 0x16c) +
              local_18 * *(float *)(unaff_ESI + 0x170) +
              local_c * *(float *)(unaff_ESI + 0x14c) +
              local_30 * *(float *)(unaff_ESI + 0x158) +
              local_20 * *(float *)(unaff_ESI + 0x168) +
              local_10 * *(float *)(unaff_ESI + 0x148) +
              local_24 * *(float *)(unaff_ESI + 0x164) +
              local_14 * *(float *)(unaff_ESI + 0x144) + local_4 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x13];
      *(float *)(unaff_ESI + 0x154) = fVar1;
      pfVar4[0x13] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x160) +
              local_4 * *(float *)(unaff_ESI + 0x150) +
              local_28 * *(float *)(unaff_ESI + 0x15c) +
              local_18 * *(float *)(unaff_ESI + 0x16c) +
              local_14 * *(float *)(unaff_ESI + 0x170) +
              local_8 * *(float *)(unaff_ESI + 0x14c) +
              local_2c * *(float *)(unaff_ESI + 0x158) +
              local_1c * *(float *)(unaff_ESI + 0x168) +
              local_c * *(float *)(unaff_ESI + 0x148) +
              local_30 * *(float *)(unaff_ESI + 0x154) +
              local_20 * *(float *)(unaff_ESI + 0x164) + local_10 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x14];
      *(float *)(unaff_ESI + 0x150) = fVar1;
      pfVar4[0x14] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x150) +
              local_20 * *(float *)(unaff_ESI + 0x160) +
              local_24 * *(float *)(unaff_ESI + 0x15c) +
              local_14 * *(float *)(unaff_ESI + 0x16c) +
              local_10 * *(float *)(unaff_ESI + 0x170) +
              local_4 * *(float *)(unaff_ESI + 0x14c) +
              local_28 * *(float *)(unaff_ESI + 0x158) +
              local_18 * *(float *)(unaff_ESI + 0x168) +
              local_8 * *(float *)(unaff_ESI + 0x148) +
              local_2c * *(float *)(unaff_ESI + 0x154) +
              local_1c * *(float *)(unaff_ESI + 0x164) + local_c * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x15];
      *(float *)(unaff_ESI + 0x14c) = fVar1;
      pfVar4[0x15] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x150) +
              local_1c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x14c) +
              local_20 * *(float *)(unaff_ESI + 0x15c) +
              local_10 * *(float *)(unaff_ESI + 0x16c) +
              local_c * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x158) +
              local_14 * *(float *)(unaff_ESI + 0x168) +
              local_4 * *(float *)(unaff_ESI + 0x148) +
              local_28 * *(float *)(unaff_ESI + 0x154) +
              local_18 * *(float *)(unaff_ESI + 0x164) + local_8 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x16];
      *(float *)(unaff_ESI + 0x148) = fVar1;
      pfVar4[0x16] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x150) +
              local_18 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x14c) +
              local_1c * *(float *)(unaff_ESI + 0x15c) +
              local_c * *(float *)(unaff_ESI + 0x16c) +
              local_8 * *(float *)(unaff_ESI + 0x170) +
              local_30 * *(float *)(unaff_ESI + 0x148) +
              local_20 * *(float *)(unaff_ESI + 0x158) +
              local_10 * *(float *)(unaff_ESI + 0x168) +
              local_24 * *(float *)(unaff_ESI + 0x154) +
              local_14 * *(float *)(unaff_ESI + 0x164) + local_4 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x17];
      *(float *)(unaff_ESI + 0x144) = fVar1;
      pfVar4[0x17] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x150) +
              local_14 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x14c) +
              local_18 * *(float *)(unaff_ESI + 0x15c) +
              local_8 * *(float *)(unaff_ESI + 0x16c) +
              local_4 * *(float *)(unaff_ESI + 0x170) +
              local_2c * *(float *)(unaff_ESI + 0x148) +
              local_1c * *(float *)(unaff_ESI + 0x158) +
              local_c * *(float *)(unaff_ESI + 0x168) +
              local_30 * *(float *)(unaff_ESI + 0x144) +
              local_20 * *(float *)(unaff_ESI + 0x154) + local_10 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x18];
      *(float *)(unaff_ESI + 0x170) = fVar1;
      pfVar4[0x18] = fVar1;
      fVar1 = local_20 * *(float *)(unaff_ESI + 0x150) +
              local_10 * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x14c) +
              local_14 * *(float *)(unaff_ESI + 0x15c) +
              local_4 * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x148) +
              local_18 * *(float *)(unaff_ESI + 0x158) +
              local_8 * *(float *)(unaff_ESI + 0x168) +
              local_2c * *(float *)(unaff_ESI + 0x144) +
              local_1c * *(float *)(unaff_ESI + 0x154) + local_c * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x19];
      *(float *)(unaff_ESI + 0x16c) = fVar1;
      pfVar4[0x19] = fVar1;
      fVar1 = local_1c * *(float *)(unaff_ESI + 0x150) +
              local_c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x16c) +
              local_2c * *(float *)(unaff_ESI + 0x170) +
              local_20 * *(float *)(unaff_ESI + 0x14c) +
              local_10 * *(float *)(unaff_ESI + 0x15c) +
              local_24 * *(float *)(unaff_ESI + 0x148) +
              local_14 * *(float *)(unaff_ESI + 0x158) +
              local_4 * *(float *)(unaff_ESI + 0x168) +
              local_28 * *(float *)(unaff_ESI + 0x144) +
              local_18 * *(float *)(unaff_ESI + 0x154) + local_8 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x1a];
      *(float *)(unaff_ESI + 0x168) = fVar1;
      pfVar4[0x1a] = fVar1;
      fVar1 = local_18 * *(float *)(unaff_ESI + 0x150) +
              local_8 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x170) +
              local_1c * *(float *)(unaff_ESI + 0x14c) +
              local_c * *(float *)(unaff_ESI + 0x15c) +
              local_30 * *(float *)(unaff_ESI + 0x168) +
              local_20 * *(float *)(unaff_ESI + 0x148) +
              local_10 * *(float *)(unaff_ESI + 0x158) +
              local_24 * *(float *)(unaff_ESI + 0x144) +
              local_14 * *(float *)(unaff_ESI + 0x154) + local_4 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x1b];
      *(float *)(unaff_ESI + 0x164) = fVar1;
      pfVar4[0x1b] = fVar1;
      fVar1 = local_14 * *(float *)(unaff_ESI + 0x150) +
              local_4 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x16c) +
              local_24 * *(float *)(unaff_ESI + 0x170) +
              local_18 * *(float *)(unaff_ESI + 0x14c) +
              local_8 * *(float *)(unaff_ESI + 0x15c) +
              local_2c * *(float *)(unaff_ESI + 0x168) +
              local_1c * *(float *)(unaff_ESI + 0x148) +
              local_c * *(float *)(unaff_ESI + 0x158) +
              local_30 * *(float *)(unaff_ESI + 0x164) +
              local_20 * *(float *)(unaff_ESI + 0x144) + local_10 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x1c];
      *(float *)(unaff_ESI + 0x160) = fVar1;
      pfVar4[0x1c] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x160) +
              local_10 * *(float *)(unaff_ESI + 0x150) +
              local_24 * *(float *)(unaff_ESI + 0x16c) +
              local_20 * *(float *)(unaff_ESI + 0x170) +
              local_14 * *(float *)(unaff_ESI + 0x14c) +
              local_4 * *(float *)(unaff_ESI + 0x15c) +
              local_28 * *(float *)(unaff_ESI + 0x168) +
              local_18 * *(float *)(unaff_ESI + 0x148) +
              local_8 * *(float *)(unaff_ESI + 0x158) +
              local_2c * *(float *)(unaff_ESI + 0x164) +
              local_1c * *(float *)(unaff_ESI + 0x144) + local_c * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x1d];
      *(float *)(unaff_ESI + 0x15c) = fVar1;
      pfVar4[0x1d] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x160) +
              local_c * *(float *)(unaff_ESI + 0x150) +
              local_30 * *(float *)(unaff_ESI + 0x15c) +
              local_20 * *(float *)(unaff_ESI + 0x16c) +
              local_1c * *(float *)(unaff_ESI + 0x170) +
              local_10 * *(float *)(unaff_ESI + 0x14c) +
              local_24 * *(float *)(unaff_ESI + 0x168) +
              local_14 * *(float *)(unaff_ESI + 0x148) +
              local_4 * *(float *)(unaff_ESI + 0x158) +
              local_28 * *(float *)(unaff_ESI + 0x164) +
              local_18 * *(float *)(unaff_ESI + 0x144) + local_8 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x1e];
      *(float *)(unaff_ESI + 0x158) = fVar1;
      pfVar4[0x1e] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x160) +
              local_8 * *(float *)(unaff_ESI + 0x150) +
              local_2c * *(float *)(unaff_ESI + 0x15c) +
              local_1c * *(float *)(unaff_ESI + 0x16c) +
              local_18 * *(float *)(unaff_ESI + 0x170) +
              local_c * *(float *)(unaff_ESI + 0x14c) +
              local_30 * *(float *)(unaff_ESI + 0x158) +
              local_20 * *(float *)(unaff_ESI + 0x168) +
              local_10 * *(float *)(unaff_ESI + 0x148) +
              local_24 * *(float *)(unaff_ESI + 0x164) +
              local_14 * *(float *)(unaff_ESI + 0x144) + local_4 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x1f];
      *(float *)(unaff_ESI + 0x154) = fVar1;
      pfVar4[0x1f] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x160) +
              local_4 * *(float *)(unaff_ESI + 0x150) +
              local_28 * *(float *)(unaff_ESI + 0x15c) +
              local_18 * *(float *)(unaff_ESI + 0x16c) +
              local_14 * *(float *)(unaff_ESI + 0x170) +
              local_8 * *(float *)(unaff_ESI + 0x14c) +
              local_2c * *(float *)(unaff_ESI + 0x158) +
              local_1c * *(float *)(unaff_ESI + 0x168) +
              local_c * *(float *)(unaff_ESI + 0x148) +
              local_30 * *(float *)(unaff_ESI + 0x154) +
              local_20 * *(float *)(unaff_ESI + 0x164) + local_10 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x20];
      *(float *)(unaff_ESI + 0x150) = fVar1;
      pfVar4[0x20] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x150) +
              local_20 * *(float *)(unaff_ESI + 0x160) +
              local_24 * *(float *)(unaff_ESI + 0x15c) +
              local_14 * *(float *)(unaff_ESI + 0x16c) +
              local_10 * *(float *)(unaff_ESI + 0x170) +
              local_4 * *(float *)(unaff_ESI + 0x14c) +
              local_28 * *(float *)(unaff_ESI + 0x158) +
              local_18 * *(float *)(unaff_ESI + 0x168) +
              local_8 * *(float *)(unaff_ESI + 0x148) +
              local_2c * *(float *)(unaff_ESI + 0x154) +
              local_1c * *(float *)(unaff_ESI + 0x164) + local_c * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x21];
      *(float *)(unaff_ESI + 0x14c) = fVar1;
      pfVar4[0x21] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x150) +
              local_1c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x14c) +
              local_20 * *(float *)(unaff_ESI + 0x15c) +
              local_10 * *(float *)(unaff_ESI + 0x16c) +
              local_c * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x158) +
              local_14 * *(float *)(unaff_ESI + 0x168) +
              local_4 * *(float *)(unaff_ESI + 0x148) +
              local_28 * *(float *)(unaff_ESI + 0x154) +
              local_18 * *(float *)(unaff_ESI + 0x164) + local_8 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x22];
      *(float *)(unaff_ESI + 0x148) = fVar1;
      pfVar4[0x22] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x150) +
              local_18 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x14c) +
              local_1c * *(float *)(unaff_ESI + 0x15c) +
              local_c * *(float *)(unaff_ESI + 0x16c) +
              local_8 * *(float *)(unaff_ESI + 0x170) +
              local_30 * *(float *)(unaff_ESI + 0x148) +
              local_20 * *(float *)(unaff_ESI + 0x158) +
              local_10 * *(float *)(unaff_ESI + 0x168) +
              local_24 * *(float *)(unaff_ESI + 0x154) +
              local_14 * *(float *)(unaff_ESI + 0x164) + local_4 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x23];
      *(float *)(unaff_ESI + 0x144) = fVar1;
      pfVar4[0x23] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x150) +
              local_14 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x14c) +
              local_18 * *(float *)(unaff_ESI + 0x15c) +
              local_8 * *(float *)(unaff_ESI + 0x16c) +
              local_4 * *(float *)(unaff_ESI + 0x170) +
              local_2c * *(float *)(unaff_ESI + 0x148) +
              local_1c * *(float *)(unaff_ESI + 0x158) +
              local_c * *(float *)(unaff_ESI + 0x168) +
              local_30 * *(float *)(unaff_ESI + 0x144) +
              local_20 * *(float *)(unaff_ESI + 0x154) + local_10 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x24];
      *(float *)(unaff_ESI + 0x170) = fVar1;
      pfVar4[0x24] = fVar1;
      fVar1 = local_20 * *(float *)(unaff_ESI + 0x150) +
              local_10 * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x14c) +
              local_14 * *(float *)(unaff_ESI + 0x15c) +
              local_4 * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x148) +
              local_18 * *(float *)(unaff_ESI + 0x158) +
              local_8 * *(float *)(unaff_ESI + 0x168) +
              local_2c * *(float *)(unaff_ESI + 0x144) +
              local_1c * *(float *)(unaff_ESI + 0x154) + local_c * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x25];
      *(float *)(unaff_ESI + 0x16c) = fVar1;
      pfVar4[0x25] = fVar1;
      fVar1 = local_1c * *(float *)(unaff_ESI + 0x150) +
              local_c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x16c) +
              local_2c * *(float *)(unaff_ESI + 0x170) +
              local_20 * *(float *)(unaff_ESI + 0x14c) +
              local_10 * *(float *)(unaff_ESI + 0x15c) +
              local_24 * *(float *)(unaff_ESI + 0x148) +
              local_14 * *(float *)(unaff_ESI + 0x158) +
              local_4 * *(float *)(unaff_ESI + 0x168) +
              local_28 * *(float *)(unaff_ESI + 0x144) +
              local_18 * *(float *)(unaff_ESI + 0x154) + local_8 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x26];
      *(float *)(unaff_ESI + 0x168) = fVar1;
      pfVar4[0x26] = fVar1;
      fVar1 = local_18 * *(float *)(unaff_ESI + 0x150) +
              local_8 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x170) +
              local_1c * *(float *)(unaff_ESI + 0x14c) +
              local_c * *(float *)(unaff_ESI + 0x15c) +
              local_30 * *(float *)(unaff_ESI + 0x168) +
              local_20 * *(float *)(unaff_ESI + 0x148) +
              local_10 * *(float *)(unaff_ESI + 0x158) +
              local_24 * *(float *)(unaff_ESI + 0x144) +
              local_14 * *(float *)(unaff_ESI + 0x154) + local_4 * *(float *)(unaff_ESI + 0x164) +
              pfVar4[0x27];
      *(float *)(unaff_ESI + 0x164) = fVar1;
      pfVar4[0x27] = fVar1;
      fVar1 = local_14 * *(float *)(unaff_ESI + 0x150) +
              local_4 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x16c) +
              local_24 * *(float *)(unaff_ESI + 0x170) +
              local_18 * *(float *)(unaff_ESI + 0x14c) +
              local_8 * *(float *)(unaff_ESI + 0x15c) +
              local_2c * *(float *)(unaff_ESI + 0x168) +
              local_1c * *(float *)(unaff_ESI + 0x148) +
              local_c * *(float *)(unaff_ESI + 0x158) +
              local_30 * *(float *)(unaff_ESI + 0x164) +
              local_20 * *(float *)(unaff_ESI + 0x144) + local_10 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x28];
      *(float *)(unaff_ESI + 0x160) = fVar1;
      pfVar4[0x28] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x160) +
              local_10 * *(float *)(unaff_ESI + 0x150) +
              local_24 * *(float *)(unaff_ESI + 0x16c) +
              local_20 * *(float *)(unaff_ESI + 0x170) +
              local_14 * *(float *)(unaff_ESI + 0x14c) +
              local_4 * *(float *)(unaff_ESI + 0x15c) +
              local_28 * *(float *)(unaff_ESI + 0x168) +
              local_18 * *(float *)(unaff_ESI + 0x148) +
              local_8 * *(float *)(unaff_ESI + 0x158) +
              local_2c * *(float *)(unaff_ESI + 0x164) +
              local_1c * *(float *)(unaff_ESI + 0x144) + local_c * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x29];
      *(float *)(unaff_ESI + 0x15c) = fVar1;
      pfVar4[0x29] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x160) +
              local_c * *(float *)(unaff_ESI + 0x150) +
              local_30 * *(float *)(unaff_ESI + 0x15c) +
              local_20 * *(float *)(unaff_ESI + 0x16c) +
              local_1c * *(float *)(unaff_ESI + 0x170) +
              local_10 * *(float *)(unaff_ESI + 0x14c) +
              local_24 * *(float *)(unaff_ESI + 0x168) +
              local_14 * *(float *)(unaff_ESI + 0x148) +
              local_4 * *(float *)(unaff_ESI + 0x158) +
              local_28 * *(float *)(unaff_ESI + 0x164) +
              local_18 * *(float *)(unaff_ESI + 0x144) + local_8 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x2a];
      *(float *)(unaff_ESI + 0x158) = fVar1;
      pfVar4[0x2a] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x160) +
              local_8 * *(float *)(unaff_ESI + 0x150) +
              local_2c * *(float *)(unaff_ESI + 0x15c) +
              local_1c * *(float *)(unaff_ESI + 0x16c) +
              local_18 * *(float *)(unaff_ESI + 0x170) +
              local_c * *(float *)(unaff_ESI + 0x14c) +
              local_30 * *(float *)(unaff_ESI + 0x158) +
              local_20 * *(float *)(unaff_ESI + 0x168) +
              local_10 * *(float *)(unaff_ESI + 0x148) +
              local_24 * *(float *)(unaff_ESI + 0x164) +
              local_14 * *(float *)(unaff_ESI + 0x144) + local_4 * *(float *)(unaff_ESI + 0x154) +
              pfVar4[0x2b];
      *(float *)(unaff_ESI + 0x154) = fVar1;
      pfVar4[0x2b] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x160) +
              local_4 * *(float *)(unaff_ESI + 0x150) +
              local_28 * *(float *)(unaff_ESI + 0x15c) +
              local_18 * *(float *)(unaff_ESI + 0x16c) +
              local_14 * *(float *)(unaff_ESI + 0x170) +
              local_8 * *(float *)(unaff_ESI + 0x14c) +
              local_2c * *(float *)(unaff_ESI + 0x158) +
              local_1c * *(float *)(unaff_ESI + 0x168) +
              local_c * *(float *)(unaff_ESI + 0x148) +
              local_30 * *(float *)(unaff_ESI + 0x154) +
              local_20 * *(float *)(unaff_ESI + 0x164) + local_10 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x2c];
      *(float *)(unaff_ESI + 0x150) = fVar1;
      pfVar4[0x2c] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x150) +
              local_20 * *(float *)(unaff_ESI + 0x160) +
              local_24 * *(float *)(unaff_ESI + 0x15c) +
              local_14 * *(float *)(unaff_ESI + 0x16c) +
              local_10 * *(float *)(unaff_ESI + 0x170) +
              local_4 * *(float *)(unaff_ESI + 0x14c) +
              local_28 * *(float *)(unaff_ESI + 0x158) +
              local_18 * *(float *)(unaff_ESI + 0x168) +
              local_8 * *(float *)(unaff_ESI + 0x148) +
              local_2c * *(float *)(unaff_ESI + 0x154) +
              local_1c * *(float *)(unaff_ESI + 0x164) + local_c * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x2d];
      *(float *)(unaff_ESI + 0x14c) = fVar1;
      pfVar4[0x2d] = fVar1;
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 4;
      pfVar5 = pfVar4 + 0x30;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x150) +
              local_1c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x14c) +
              local_20 * *(float *)(unaff_ESI + 0x15c) +
              local_10 * *(float *)(unaff_ESI + 0x16c) +
              local_c * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x158) +
              local_14 * *(float *)(unaff_ESI + 0x168) +
              local_4 * *(float *)(unaff_ESI + 0x148) +
              local_28 * *(float *)(unaff_ESI + 0x154) +
              local_18 * *(float *)(unaff_ESI + 0x164) + local_8 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x2e];
      *(float *)(unaff_ESI + 0x148) = fVar1;
      pfVar4[0x2e] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x150) +
              local_18 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x14c) +
              local_1c * *(float *)(unaff_ESI + 0x15c) +
              local_c * *(float *)(unaff_ESI + 0x16c) +
              local_8 * *(float *)(unaff_ESI + 0x170) +
              local_30 * *(float *)(unaff_ESI + 0x148) +
              local_20 * *(float *)(unaff_ESI + 0x158) +
              local_10 * *(float *)(unaff_ESI + 0x168) +
              local_24 * *(float *)(unaff_ESI + 0x154) +
              local_14 * *(float *)(unaff_ESI + 0x164) + local_4 * *(float *)(unaff_ESI + 0x144) +
              pfVar4[0x2f];
      *(float *)(unaff_ESI + 0x144) = fVar1;
      pfVar4[0x2f] = fVar1;
      pfVar4 = pfVar5;
    } while (iVar2 < param_1);
  }
  if (iVar3 < param_1) {
    param_1 = param_1 - iVar3;
    do {
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x150) +
              local_14 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x14c) +
              local_18 * *(float *)(unaff_ESI + 0x15c) +
              local_8 * *(float *)(unaff_ESI + 0x16c) +
              local_4 * *(float *)(unaff_ESI + 0x170) +
              local_2c * *(float *)(unaff_ESI + 0x148) +
              local_1c * *(float *)(unaff_ESI + 0x158) +
              local_c * *(float *)(unaff_ESI + 0x168) +
              local_30 * *(float *)(unaff_ESI + 0x144) +
              local_20 * *(float *)(unaff_ESI + 0x154) + local_10 * *(float *)(unaff_ESI + 0x164) +
              *pfVar5;
      *(float *)(unaff_ESI + 0x170) = fVar1;
      *pfVar5 = fVar1;
      fVar1 = local_20 * *(float *)(unaff_ESI + 0x150) +
              local_10 * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x14c) +
              local_14 * *(float *)(unaff_ESI + 0x15c) +
              local_4 * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x148) +
              local_18 * *(float *)(unaff_ESI + 0x158) +
              local_8 * *(float *)(unaff_ESI + 0x168) +
              local_2c * *(float *)(unaff_ESI + 0x144) +
              local_1c * *(float *)(unaff_ESI + 0x154) + local_c * *(float *)(unaff_ESI + 0x164) +
              pfVar5[1];
      *(float *)(unaff_ESI + 0x16c) = fVar1;
      pfVar5[1] = fVar1;
      fVar1 = local_1c * *(float *)(unaff_ESI + 0x150) +
              local_c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x16c) +
              local_2c * *(float *)(unaff_ESI + 0x170) +
              local_20 * *(float *)(unaff_ESI + 0x14c) +
              local_10 * *(float *)(unaff_ESI + 0x15c) +
              local_24 * *(float *)(unaff_ESI + 0x148) +
              local_14 * *(float *)(unaff_ESI + 0x158) +
              local_4 * *(float *)(unaff_ESI + 0x168) +
              local_28 * *(float *)(unaff_ESI + 0x144) +
              local_18 * *(float *)(unaff_ESI + 0x154) + local_8 * *(float *)(unaff_ESI + 0x164) +
              pfVar5[2];
      *(float *)(unaff_ESI + 0x168) = fVar1;
      pfVar5[2] = fVar1;
      fVar1 = local_18 * *(float *)(unaff_ESI + 0x150) +
              local_8 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x16c) +
              local_28 * *(float *)(unaff_ESI + 0x170) +
              local_1c * *(float *)(unaff_ESI + 0x14c) +
              local_c * *(float *)(unaff_ESI + 0x15c) +
              local_30 * *(float *)(unaff_ESI + 0x168) +
              local_20 * *(float *)(unaff_ESI + 0x148) +
              local_10 * *(float *)(unaff_ESI + 0x158) +
              local_24 * *(float *)(unaff_ESI + 0x144) +
              local_14 * *(float *)(unaff_ESI + 0x154) + local_4 * *(float *)(unaff_ESI + 0x164) +
              pfVar5[3];
      *(float *)(unaff_ESI + 0x164) = fVar1;
      pfVar5[3] = fVar1;
      fVar1 = local_14 * *(float *)(unaff_ESI + 0x150) +
              local_4 * *(float *)(unaff_ESI + 0x160) +
              local_28 * *(float *)(unaff_ESI + 0x16c) +
              local_24 * *(float *)(unaff_ESI + 0x170) +
              local_18 * *(float *)(unaff_ESI + 0x14c) +
              local_8 * *(float *)(unaff_ESI + 0x15c) +
              local_2c * *(float *)(unaff_ESI + 0x168) +
              local_1c * *(float *)(unaff_ESI + 0x148) +
              local_c * *(float *)(unaff_ESI + 0x158) +
              local_30 * *(float *)(unaff_ESI + 0x164) +
              local_20 * *(float *)(unaff_ESI + 0x144) + local_10 * *(float *)(unaff_ESI + 0x154) +
              pfVar5[4];
      *(float *)(unaff_ESI + 0x160) = fVar1;
      pfVar5[4] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x160) +
              local_10 * *(float *)(unaff_ESI + 0x150) +
              local_24 * *(float *)(unaff_ESI + 0x16c) +
              local_20 * *(float *)(unaff_ESI + 0x170) +
              local_14 * *(float *)(unaff_ESI + 0x14c) +
              local_4 * *(float *)(unaff_ESI + 0x15c) +
              local_28 * *(float *)(unaff_ESI + 0x168) +
              local_18 * *(float *)(unaff_ESI + 0x148) +
              local_8 * *(float *)(unaff_ESI + 0x158) +
              local_2c * *(float *)(unaff_ESI + 0x164) +
              local_1c * *(float *)(unaff_ESI + 0x144) + local_c * *(float *)(unaff_ESI + 0x154) +
              pfVar5[5];
      *(float *)(unaff_ESI + 0x15c) = fVar1;
      pfVar5[5] = fVar1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x160) +
              local_c * *(float *)(unaff_ESI + 0x150) +
              local_30 * *(float *)(unaff_ESI + 0x15c) +
              local_20 * *(float *)(unaff_ESI + 0x16c) +
              local_1c * *(float *)(unaff_ESI + 0x170) +
              local_10 * *(float *)(unaff_ESI + 0x14c) +
              local_24 * *(float *)(unaff_ESI + 0x168) +
              local_14 * *(float *)(unaff_ESI + 0x148) +
              local_4 * *(float *)(unaff_ESI + 0x158) +
              local_28 * *(float *)(unaff_ESI + 0x164) +
              local_18 * *(float *)(unaff_ESI + 0x144) + local_8 * *(float *)(unaff_ESI + 0x154) +
              pfVar5[6];
      *(float *)(unaff_ESI + 0x158) = fVar1;
      pfVar5[6] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x160) +
              local_8 * *(float *)(unaff_ESI + 0x150) +
              local_2c * *(float *)(unaff_ESI + 0x15c) +
              local_1c * *(float *)(unaff_ESI + 0x16c) +
              local_18 * *(float *)(unaff_ESI + 0x170) +
              local_c * *(float *)(unaff_ESI + 0x14c) +
              local_30 * *(float *)(unaff_ESI + 0x158) +
              local_20 * *(float *)(unaff_ESI + 0x168) +
              local_10 * *(float *)(unaff_ESI + 0x148) +
              local_24 * *(float *)(unaff_ESI + 0x164) +
              local_14 * *(float *)(unaff_ESI + 0x144) + local_4 * *(float *)(unaff_ESI + 0x154) +
              pfVar5[7];
      *(float *)(unaff_ESI + 0x154) = fVar1;
      pfVar5[7] = fVar1;
      fVar1 = local_24 * *(float *)(unaff_ESI + 0x160) +
              local_4 * *(float *)(unaff_ESI + 0x150) +
              local_28 * *(float *)(unaff_ESI + 0x15c) +
              local_18 * *(float *)(unaff_ESI + 0x16c) +
              local_14 * *(float *)(unaff_ESI + 0x170) +
              local_8 * *(float *)(unaff_ESI + 0x14c) +
              local_2c * *(float *)(unaff_ESI + 0x158) +
              local_1c * *(float *)(unaff_ESI + 0x168) +
              local_c * *(float *)(unaff_ESI + 0x148) +
              local_30 * *(float *)(unaff_ESI + 0x154) +
              local_20 * *(float *)(unaff_ESI + 0x164) + local_10 * *(float *)(unaff_ESI + 0x144) +
              pfVar5[8];
      *(float *)(unaff_ESI + 0x150) = fVar1;
      pfVar5[8] = fVar1;
      fVar1 = local_30 * *(float *)(unaff_ESI + 0x150) +
              local_20 * *(float *)(unaff_ESI + 0x160) +
              local_24 * *(float *)(unaff_ESI + 0x15c) +
              local_14 * *(float *)(unaff_ESI + 0x16c) +
              local_10 * *(float *)(unaff_ESI + 0x170) +
              local_4 * *(float *)(unaff_ESI + 0x14c) +
              local_28 * *(float *)(unaff_ESI + 0x158) +
              local_18 * *(float *)(unaff_ESI + 0x168) +
              local_8 * *(float *)(unaff_ESI + 0x148) +
              local_2c * *(float *)(unaff_ESI + 0x154) +
              local_1c * *(float *)(unaff_ESI + 0x164) + local_c * *(float *)(unaff_ESI + 0x144) +
              pfVar5[9];
      *(float *)(unaff_ESI + 0x14c) = fVar1;
      pfVar5[9] = fVar1;
      param_1 = param_1 + -1;
      fVar1 = local_2c * *(float *)(unaff_ESI + 0x150) +
              local_1c * *(float *)(unaff_ESI + 0x160) +
              local_30 * *(float *)(unaff_ESI + 0x14c) +
              local_20 * *(float *)(unaff_ESI + 0x15c) +
              local_10 * *(float *)(unaff_ESI + 0x16c) +
              local_c * *(float *)(unaff_ESI + 0x170) +
              local_24 * *(float *)(unaff_ESI + 0x158) +
              local_14 * *(float *)(unaff_ESI + 0x168) +
              local_4 * *(float *)(unaff_ESI + 0x148) +
              local_28 * *(float *)(unaff_ESI + 0x154) +
              local_18 * *(float *)(unaff_ESI + 0x164) + local_8 * *(float *)(unaff_ESI + 0x144) +
              pfVar5[10];
      *(float *)(unaff_ESI + 0x148) = fVar1;
      pfVar5[10] = fVar1;
      fVar1 = local_28 * *(float *)(unaff_ESI + 0x150) +
              local_18 * *(float *)(unaff_ESI + 0x160) +
              local_2c * *(float *)(unaff_ESI + 0x14c) +
              local_1c * *(float *)(unaff_ESI + 0x15c) +
              local_c * *(float *)(unaff_ESI + 0x16c) +
              local_8 * *(float *)(unaff_ESI + 0x170) +
              local_30 * *(float *)(unaff_ESI + 0x148) +
              local_20 * *(float *)(unaff_ESI + 0x158) +
              local_10 * *(float *)(unaff_ESI + 0x168) +
              local_24 * *(float *)(unaff_ESI + 0x154) +
              local_14 * *(float *)(unaff_ESI + 0x164) + local_4 * *(float *)(unaff_ESI + 0x144) +
              pfVar5[0xb];
      *(float *)(unaff_ESI + 0x144) = fVar1;
      pfVar5[0xb] = fVar1;
      pfVar5 = pfVar5 + 0xc;
    } while (param_1 != 0);
  }
  return;
}


// ==== 0x65e920 FUN_0065e920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065e920(byte *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  float fVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  param_2[2] = 8;
  *param_2 = param_1 + 1;
  bVar1 = *param_1;
  param_2[1] = (uint)bVar1;
  uVar7 = DAT_006ea794;
  if (param_3 != 0) {
    param_2[1] = (uint)(bVar1 >> 1);
    param_2[2] = 7;
    param_2[1] = param_2[1] | (uint)param_1[1] << 7;
    uVar2 = param_2[1];
    param_2[3] = bVar1 & uVar7;
    *param_2 = param_1 + 2;
    param_2[2] = 0xf;
    uVar7 = DAT_006ea7a0;
    param_2[1] = uVar2 >> 4;
    param_2[4] = 0x20 - (uVar2 & uVar7);
    uVar7 = param_2[1];
    param_2[2] = 0xb;
    uVar2 = DAT_006ea7a0;
    param_2[1] = uVar7 >> 4;
    param_2[2] = 7;
    iVar6 = (uVar7 & uVar2) + 1;
    param_2[1] = param_2[1] | (uint)param_1[2] << 7;
    *param_2 = param_1 + 3;
    fVar3 = (float)iVar6;
    param_2[2] = 0xf;
    if (iVar6 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    param_2[5] = fVar3 * K_ONE;
    uVar7 = param_2[1] & DAT_006ea7a8;
    fVar3 = (float)(int)uVar7;
    param_2[1] = (uint)param_2[1] >> 6;
    param_2[2] = 9;
    if ((int)uVar7 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    iVar6 = 0x3f;
    pfVar4 = (float *)(param_2 + 6);
    do {
      iVar6 = iVar6 + -1;
      *pfVar4 = (fVar3 * 0.001 + 1.04) * pfVar4[-1];
      pfVar4 = pfVar4 + 1;
    } while (iVar6 != 0);
    puVar5 = param_2 + 0x51;
    iVar6 = 0xc;
    do {
      puVar5[-0xc] = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar5 = param_2 + 0x5d;
    for (iVar6 = 0x144; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== 0x65ea70 FUN_0065ea70

void FUN_0065ea70(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  float local_220 [2];
  float *local_218;
  float local_214 [4];
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8 [2];
  uint local_1e0;
  int local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  float local_1c8;
  undefined1 local_1c4 [4];
  undefined4 local_1c0 [5];
  float afStack_1ac [102];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = param_1[2];
  iVar7 = iVar4 + -6;
  uVar5 = (uint)param_1[1] >> 6;
  uVar1 = param_1[1] & DAT_006ea7a8;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 2;
  }
  iVar4 = param_1[2];
  local_1e0 = (uint)((int)uVar1 < (int)param_1[4]);
  iVar7 = iVar4 + -6;
  local_214[1] = (*(float *)(&DAT_006ea7b8 + uVar1 * 4) - (float)param_1[0x45]) * 0.25;
  uVar5 = (uint)param_1[1] >> 6;
  uVar1 = param_1[1] & DAT_006ea7a8;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 2;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -6;
  local_214[2] = (*(float *)(&DAT_006ea7b8 + uVar1 * 4) - (float)param_1[0x46]) * 0.25;
  uVar5 = (uint)param_1[1] >> 6;
  uVar1 = param_1[1] & DAT_006ea7a8;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 2;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -6;
  local_214[3] = (*(float *)(&DAT_006ea7b8 + uVar1 * 4) - (float)param_1[0x47]) * 0.25;
  uVar5 = (uint)param_1[1] >> 6;
  uVar1 = param_1[1] & DAT_006ea7a8;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 2;
  }
  iVar4 = param_1[2];
  uVar5 = param_1[1] & DAT_006ea7a4;
  iVar7 = iVar4 + -5;
  local_204 = (*(float *)(&DAT_006ea7b8 + uVar1 * 4) - (float)param_1[0x48]) * 0.25;
  uVar1 = (uint)param_1[1] >> 5;
  param_1[1] = uVar1;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar1;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_200 = (*(float *)(&DAT_006ea7f8 + uVar5 * 4) - (float)param_1[0x49]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1fc = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4a]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1f8 = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4b]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1f4 = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4c]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1f0 = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4d]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1ec = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4e]) * 0.25;
  uVar5 = (uint)param_1[1] >> 5;
  uVar1 = param_1[1] & DAT_006ea7a4;
  param_1[1] = uVar5;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  iVar4 = param_1[2];
  iVar7 = iVar4 + -5;
  local_1e8[0] = (*(float *)(&DAT_006ea7f8 + uVar1 * 4) - (float)param_1[0x4f]) * 0.25;
  uVar5 = param_1[1] & DAT_006ea7a4;
  uVar1 = (uint)param_1[1] >> 5;
  param_1[1] = uVar1;
  param_1[2] = iVar7;
  if (iVar7 < 8) {
    param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar1;
    *param_1 = (byte *)*param_1 + 1;
    param_1[2] = iVar4 + 3;
  }
  local_218 = (float *)(param_1 + 0x1a2);
  local_214[0] = 3.0268e-43;
  local_1e8[1] = (*(float *)(&DAT_006ea7f8 + uVar5 * 4) - (float)param_1[0x50]) * 0.25;
  do {
    iVar4 = param_1[2];
    iVar7 = iVar4 + -8;
    uVar5 = (uint)param_1[1] >> 8;
    uVar1 = param_1[1] & DAT_006ea7b0;
    param_1[1] = uVar5;
    param_1[2] = iVar7;
    if (iVar7 < 8) {
      param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar7 & 0x1f) | uVar5;
      *param_1 = (byte *)*param_1 + 1;
      param_1[2] = iVar4;
    }
    iVar4 = param_1[2];
    iVar7 = (int)local_214[0] - uVar1;
    iVar8 = iVar4 + -4;
    uVar5 = (uint)param_1[1] >> 4;
    uVar1 = param_1[1] & DAT_006ea7a0;
    param_1[1] = uVar5;
    param_1[2] = iVar8;
    if (iVar8 < 8) {
      param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar8 & 0x1f) | uVar5;
      *param_1 = (byte *)*param_1 + 1;
      param_1[2] = iVar4 + 4;
    }
    local_220[1] = (float)(int)uVar1;
    if ((int)uVar1 < 0) {
      local_220[1] = local_220[1] + 4.2949673e+09;
    }
    local_220[1] = local_220[1] * 0.06666667;
    iVar4 = param_1[2];
    iVar8 = iVar4 + -6;
    uVar1 = (uint)param_1[1] >> 6;
    uVar5 = param_1[1] & DAT_006ea7a8;
    param_1[1] = uVar1;
    param_1[2] = iVar8;
    if (iVar8 < 8) {
      param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar8 & 0x1f) | uVar1;
      *param_1 = (byte *)*param_1 + 1;
      param_1[2] = iVar4 + 2;
    }
    local_220[0] = (float)param_1[uVar5 + 5];
    local_1dc = iVar7;
    if (param_1[3] == 0) {
      FUN_0065c0e0(param_1,local_1e0,local_1c4,1);
    }
    else {
      iVar4 = param_1[2];
      uVar1 = (uint)param_1[1] >> 1;
      uVar5 = param_1[1] & DAT_006ea794;
      iVar8 = iVar4 + -1;
      param_1[1] = uVar1;
      param_1[2] = iVar8;
      if (iVar8 < 8) {
        param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar8 & 0x1f) | uVar1;
        *param_1 = (byte *)*param_1 + 1;
        param_1[2] = iVar4 + 7;
      }
      uVar9 = param_1[1] & DAT_006ea794;
      iVar4 = param_1[2];
      uVar1 = (uint)param_1[1] >> 1;
      iVar8 = iVar4 + -1;
      param_1[1] = uVar1;
      param_1[2] = iVar8;
      if (iVar8 < 8) {
        param_1[1] = (uint)*(byte *)*param_1 << ((byte)iVar8 & 0x1f) | uVar1;
        *param_1 = (byte *)*param_1 + 1;
        param_1[2] = iVar4 + 7;
      }
      FUN_0065c0e0(param_1,local_1e0,local_1c4 + uVar5 * 4,2);
      puVar2 = local_1c0 + -uVar5;
      if (uVar9 == 0) {
        local_1d8 = 0;
        local_14 = 0;
        local_1d4 = 0;
        local_10 = 0;
        local_1d0 = 0;
        local_1cc = 0;
        local_c = 0;
        local_8 = 0;
        local_1c8 = 0.0;
        local_4 = 0;
        iVar4 = 0x36;
        pfVar3 = afStack_1ac + -uVar5;
        do {
          iVar4 = iVar4 + -1;
          pfVar3[-5] = (pfVar3[-6] + pfVar3[-4]) * 0.59738594 +
                       ((pfVar3[-10] + *pfVar3) * 0.01803268 -
                       (pfVar3[-8] + pfVar3[-2]) * 0.11459156);
          pfVar3 = pfVar3 + 2;
        } while (iVar4 != 0);
        local_220[0] = local_220[0] * 0.5;
      }
      else {
        iVar4 = 0x36;
        do {
          *puVar2 = 0;
          puVar2 = puVar2 + 2;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    iVar4 = 0;
    pfVar3 = local_218;
    pfVar6 = (float *)(param_1 + iVar7 + 0x5e);
    do {
      iVar7 = iVar4 + 9;
      local_218 = pfVar3 + 9;
      pfVar3[-1] = local_220[1] * pfVar6[-1] + local_220[0] * local_1e8[iVar7];
      *pfVar3 = local_220[1] * *pfVar6 + local_220[0] * local_1e8[iVar4 + 10];
      pfVar3[1] = local_220[1] * pfVar6[1] + local_220[0] * local_1e8[iVar4 + 0xb];
      pfVar3[2] = local_220[1] * pfVar6[2] + local_220[0] * local_1e8[iVar4 + 0xc];
      pfVar3[3] = local_220[1] * pfVar6[3] + local_220[0] * local_1e8[iVar4 + 0xd];
      pfVar3[4] = local_220[1] * pfVar6[4] + local_220[0] * local_1e8[iVar4 + 0xe];
      pfVar3[5] = local_220[1] * pfVar6[5] + local_220[0] * local_1e8[iVar4 + 0xf];
      pfVar3[6] = local_220[1] * pfVar6[6] + local_220[0] * local_1e8[iVar4 + 0x10];
      pfVar3[7] = local_220[1] * pfVar6[7] + local_220[0] * *(float *)(local_1c4 + iVar7 * 4 + -4);
      iVar4 = iVar7;
      pfVar3 = local_218;
      pfVar6 = pfVar6 + 9;
    } while (iVar7 < 0x6c);
    local_214[0] = (float)((int)local_214[0] + 0x6c);
  } while ((int)local_214[0] < 0x288);
  puVar2 = param_1 + 0x20d;
  puVar10 = param_1 + 0x5d;
  for (iVar4 = 0x144; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar10 = puVar10 + 1;
  }
  pfVar3 = (float *)(param_1 + 0x46);
  iVar4 = 0;
  do {
    iVar7 = iVar4 + 6;
    pfVar3[-1] = local_214[iVar4 + 1] + pfVar3[-1];
    *pfVar3 = *(float *)(&stack0xfffffddc + iVar7 * 4) + *pfVar3;
    pfVar3[1] = local_220[iVar7] + pfVar3[1];
    pfVar3[2] = local_220[iVar4 + 7] + pfVar3[2];
    pfVar3[3] = (float)(&local_218)[iVar7] + pfVar3[3];
    pfVar3[4] = local_214[iVar7] + pfVar3[4];
    pfVar3 = pfVar3 + 6;
    iVar4 = iVar7;
  } while (iVar7 < 0xc);
  FUN_0065c440(1);
  pfVar3 = (float *)(param_1 + 0x46);
  iVar4 = 0;
  do {
    iVar7 = iVar4 + 6;
    pfVar3[-1] = local_214[iVar4 + 1] + pfVar3[-1];
    *pfVar3 = *(float *)(&stack0xfffffddc + iVar7 * 4) + *pfVar3;
    pfVar3[1] = local_220[iVar7] + pfVar3[1];
    pfVar3[2] = local_220[iVar4 + 7] + pfVar3[2];
    pfVar3[3] = (float)(&local_218)[iVar7] + pfVar3[3];
    pfVar3[4] = local_214[iVar7] + pfVar3[4];
    pfVar3 = pfVar3 + 6;
    iVar4 = iVar7;
  } while (iVar7 < 0xc);
  FUN_0065c440(1);
  pfVar3 = (float *)(param_1 + 0x46);
  iVar4 = 0;
  do {
    iVar7 = iVar4 + 6;
    pfVar3[-1] = local_214[iVar4 + 1] + pfVar3[-1];
    *pfVar3 = *(float *)(&stack0xfffffddc + iVar7 * 4) + *pfVar3;
    pfVar3[1] = local_220[iVar7] + pfVar3[1];
    pfVar3[2] = local_220[iVar4 + 7] + pfVar3[2];
    pfVar3[3] = (float)(&local_218)[iVar7] + pfVar3[3];
    pfVar3[4] = local_214[iVar7] + pfVar3[4];
    pfVar3 = pfVar3 + 6;
    iVar4 = iVar7;
  } while (iVar7 < 0xc);
  FUN_0065c440(1);
  pfVar3 = (float *)(param_1 + 0x46);
  iVar4 = 0;
  do {
    iVar7 = iVar4 + 6;
    pfVar3[-1] = local_214[iVar4 + 1] + pfVar3[-1];
    *pfVar3 = *(float *)(&stack0xfffffddc + iVar7 * 4) + *pfVar3;
    pfVar3[1] = local_220[iVar7] + pfVar3[1];
    pfVar3[2] = local_220[iVar4 + 7] + pfVar3[2];
    pfVar3[3] = (float)(&local_218)[iVar7] + pfVar3[3];
    pfVar3[4] = local_214[iVar7] + pfVar3[4];
    pfVar3 = pfVar3 + 6;
    iVar4 = iVar7;
  } while (iVar7 < 0xc);
  FUN_0065c440(0x21);
  return;
}


// ==== 0x65f310 FUN_0065f310

void __fastcall FUN_0065f310(int param_1)

{
  *(undefined4 *)(param_1 + 0xd44) = 0;
  *(undefined4 *)(param_1 + 0xd54) = 0;
  *(undefined4 *)(param_1 + 0xd58) = 0;
  *(undefined2 *)(param_1 + 0xd50) = 0;
  *(undefined2 *)(param_1 + 0xd52) = 0;
  *(undefined4 *)(param_1 + 0xd5c) = 0;
  *(undefined4 *)(param_1 + 0xd60) = 0;
  *(undefined4 *)(param_1 + 0xd64) = 1;
  return;
}


// ==== 0x65f350 FUN_0065f350

undefined4 __thiscall FUN_0065f350(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_2 != (char *)0x0) && (*(int *)(param_1 + 0xd54) == 0)) {
    *(undefined4 *)(param_1 + 0xd54) = param_4;
    *(undefined4 *)(param_1 + 0xd58) = param_3;
    *(undefined4 *)(param_1 + 0xd44) = 0;
    *(char **)(param_1 + 0xd48) = param_2;
    if (*(int *)(param_1 + 0xd64) == 1) {
      *(uint *)(param_1 + 0xd60) = (uint)(*param_2 == -0x12);
      FUN_0065e920(param_2 + 1,param_1,*(undefined4 *)(param_1 + 0xd5c));
      return 0;
    }
    FUN_0065e920(param_2,param_1,*(undefined4 *)(param_1 + 0xd5c));
    return 0;
  }
  return 0xffffffff;
}


// ==== 0x65f3d0 FUN_0065f3d0

void __thiscall FUN_0065f3d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0xd5c);
  uVar2 = *(undefined4 *)(param_1 + 0xd44);
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = uVar2;
  param_2[2] = uVar1;
  return;
}


// ==== 0x65f400 FUN_0065f400

void __thiscall FUN_0065f400(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 0xd5c) = param_2[2];
  *(undefined4 *)(param_1 + 0xd44) = param_2[1];
  return;
}


// ==== 0x65f420 FUN_0065f420

void __thiscall FUN_0065f420(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xd64) = param_2;
  return;
}


// ==== 0x65f430 FUN_0065f430

void __thiscall FUN_0065f430(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  short sVar7;
  int *piVar8;
  
  iVar1 = param_1[0x355];
  iVar4 = param_1[0x351];
  if (iVar1 != 0) {
    param_1[0x353] = *param_2;
    if (iVar1 <= param_3) {
      param_3 = iVar1;
    }
    iVar1 = param_3;
    if (0 < param_3) {
      while( true ) {
        if (iVar1 < iVar4) {
          iVar4 = iVar1;
        }
        piVar5 = param_1 + (0x351 - param_1[0x351]);
        piVar8 = (int *)param_1[0x353];
        for (iVar3 = iVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar8 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar8 = piVar8 + 1;
        }
        iVar1 = iVar1 - iVar4;
        param_1[0x353] = param_1[0x353] + iVar4 * 4;
        param_1[0x351] = param_1[0x351] - iVar4;
        if (iVar1 < 1) break;
        FUN_0065ea70(param_1);
        iVar4 = 0x1b0;
        param_1[0x351] = 0x1b0;
        if (param_1[0x359] == 1) {
          puVar2 = (undefined1 *)*param_1;
          param_1[0x352] = (int)(puVar2 + -1);
          if (param_1[0x358] != 0) {
            *(undefined1 *)((int)param_1 + 0xd52) = *puVar2;
            *(undefined1 *)((int)param_1 + 0xd53) = puVar2[-1];
            *(undefined1 *)(param_1 + 0x354) = puVar2[2];
            *(undefined1 *)((int)param_1 + 0xd51) = puVar2[1];
            iVar3 = param_1[0x352] + 4 + (short)param_1[0x354] * 2;
            *param_1 = iVar3;
            puVar2 = puVar2 + 3;
            param_1[0x352] = iVar3;
            sVar7 = 0;
            *param_1 = iVar3 + 1;
            pfVar6 = (float *)(param_1 + *(short *)((int)param_1 + 0xd52) + 0x1a1);
            if (0 < (short)param_1[0x354]) {
              do {
                param_2._0_2_ = CONCAT11(*puVar2,puVar2[1]);
                puVar2 = puVar2 + 2;
                sVar7 = sVar7 + 1;
                *pfVar6 = (float)(int)(short)param_2;
                pfVar6 = pfVar6 + 1;
              } while (sVar7 < (short)param_1[0x354]);
            }
            param_1[0x358] = 0;
          }
          if (*(char *)param_1[0x352] == -0x12) {
            param_1[0x358] = 1;
          }
          param_1[2] = 8;
          param_1[1] = (uint)*(byte *)*param_1;
          *param_1 = (int)((byte *)*param_1 + 1);
        }
      }
    }
    param_1[0x355] = param_1[0x355] - param_3;
    return;
  }
  return;
}


// ==== 0x65f5f0 FUN_0065f5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f5f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0065f5f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_007172f0)();
  return;
}


// ==== 0x65f600 FUN_0065f600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f600(void)

{
                    /* WARNING: Could not recover jumptable at 0x0065f600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_007172f8)();
  return;
}


// ==== 0x65f610 FUN_0065f610

undefined4 __thiscall FUN_0065f610(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_2 != 0) && (*(int *)(param_1 + 8) == 0)) {
    *(undefined4 *)(param_1 + 8) = param_4;
    *(int *)(param_1 + 0xa0) = param_2;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    return 0;
  }
  return 0xffffffff;
}


// ==== 0x65f640 FUN_0065f640

int __thiscall FUN_0065f640(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  iVar5 = param_1[2];
  iVar6 = 0;
  local_10 = 0;
  param_1[0x29] = *param_2;
  if (iVar5 != 0) {
    if (param_3 < iVar5) {
      iVar5 = param_3;
    }
    iVar4 = param_1[1];
    if (iVar4 != 0) {
      local_10 = iVar4;
      if (iVar5 < iVar4) {
        local_10 = iVar5;
      }
      if (3 < local_10) {
        iVar4 = 3;
        do {
          *(undefined4 *)param_1[0x29] = *(undefined4 *)param_1[4];
          iVar1 = param_1[0x29];
          iVar2 = param_1[4];
          param_1[4] = (undefined4 *)(iVar2 + 4);
          param_1[0x29] = (undefined4 *)(iVar1 + 4);
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
          iVar1 = param_1[0x29];
          iVar2 = param_1[4];
          param_1[4] = (undefined4 *)(iVar2 + 4);
          param_1[0x29] = (undefined4 *)(iVar1 + 4);
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
          iVar1 = param_1[0x29];
          iVar2 = param_1[4];
          param_1[0x29] = (undefined4 *)(iVar1 + 4);
          param_1[4] = (undefined4 *)(iVar2 + 4);
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
          iVar4 = iVar4 + 4;
          iVar6 = iVar6 + 4;
          param_1[0x29] = param_1[0x29] + 4;
          param_1[4] = param_1[4] + 4;
        } while (iVar4 < local_10);
      }
      if (iVar6 < local_10) {
        iVar6 = local_10 - iVar6;
        do {
          *(undefined4 *)param_1[0x29] = *(undefined4 *)param_1[4];
          iVar6 = iVar6 + -1;
          param_1[0x29] = param_1[0x29] + 4;
          param_1[4] = param_1[4] + 4;
        } while (iVar6 != 0);
      }
      param_1[2] = param_1[2] - local_10;
      param_1[1] = param_1[1] - local_10;
      iVar5 = iVar5 - local_10;
    }
    iVar4 = (iVar5 / 0x1c) * 0x1c;
    iVar6 = iVar5 % 0x1c;
    param_1[0x25] = iVar4;
    if (0 < iVar4) {
      (*(code *)*param_1)(param_1 + 0x25);
      local_10 = local_10 + iVar4;
      param_1[2] = param_1[2] + (iVar5 / 0x1c) * -0x1c;
    }
    if (0 < iVar6) {
      iVar5 = param_1[0x29];
      param_1[0x29] = param_1 + 9;
      param_1[0x25] = iVar6;
      (*(code *)*param_1)(param_1 + 0x25);
      param_1[2] = param_1[2] - iVar6;
      param_1[4] = param_1[0x29] + param_1[0x25] * 4;
      iVar4 = 0;
      param_1[1] = -param_1[0x25];
      param_1[0x29] = param_1[0x29] + -0x70;
      if (3 < iVar6) {
        param_3 = 3;
        param_2 = (undefined4 *)0x8;
        puVar3 = (undefined4 *)(iVar5 + 8);
        do {
          puVar3[-2] = *(undefined4 *)((int)puVar3 + param_1[0x29] + -iVar5 + -8);
          puVar3[-1] = *(undefined4 *)((int)puVar3 + param_1[0x29] + -iVar5 + -4);
          *puVar3 = *(undefined4 *)(param_1[0x29] + (int)param_2);
          puVar3[1] = *(undefined4 *)((int)puVar3 + param_1[0x29] + (4 - iVar5));
          param_3 = param_3 + 4;
          param_2 = (undefined4 *)((int)param_2 + 0x10);
          iVar4 = iVar4 + 4;
          puVar3 = puVar3 + 4;
        } while (param_3 < iVar6);
      }
      for (; iVar4 < iVar6; iVar4 = iVar4 + 1) {
        *(undefined4 *)(iVar5 + iVar4 * 4) = *(undefined4 *)(param_1[0x29] + iVar4 * 4);
      }
      local_10 = local_10 + iVar6;
    }
    if ((int)param_1[2] < 1) {
      param_1[1] = 0;
    }
    return local_10;
  }
  return 0;
}


// ==== 0x65f8e0 FUN_0065f8e0

void __thiscall FUN_0065f8e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x9c);
  *param_2 = *(undefined4 *)(param_1 + 0x98);
  param_2[1] = uVar1;
  return;
}


// ==== 0x65f910 FUN_0065f910

void __thiscall FUN_0065f910(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x98) = *param_2;
  *(undefined4 *)(param_1 + 0x9c) = param_2[1];
  return;
}


// ==== 0x65f930 FUN_0065f930

void FUN_0065f930(int param_1)

{
  undefined2 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  pcVar2 = *(char **)(param_1 + 0xc);
  if (*pcVar2 == -0x12) {
    *(char **)(param_1 + 0xc) = pcVar2 + 1;
    uVar1 = *(undefined2 *)(pcVar2 + 1);
    param_1._0_2_ = CONCAT11((char)uVar1,(char)((ushort)uVar1 >> 8));
    *(char **)(iVar3 + 0xc) = pcVar2 + 3;
    *(float *)(iVar3 + 4) = (float)(int)(short)param_1;
    param_1._0_2_ =
         CONCAT11((char)*(undefined2 *)(pcVar2 + 3),(char)((ushort)*(undefined2 *)(pcVar2 + 3) >> 8)
                 );
    *(char **)(iVar3 + 0xc) = pcVar2 + 5;
    iVar4 = 0x1c;
    *(float *)(iVar3 + 8) = (float)(int)(short)param_1;
    do {
      param_1._0_2_ =
           CONCAT11((char)**(undefined2 **)(iVar3 + 0xc),
                    (char)((ushort)**(undefined2 **)(iVar3 + 0xc) >> 8));
      **(float **)(iVar3 + 0x10) = (float)(int)(short)param_1;
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 4;
      iVar4 = iVar4 + -1;
      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 2;
    } while (iVar4 != 0);
  }
  return;
}


// ==== 0x65f9d0 FUN_0065f9d0

undefined8 __fastcall FUN_0065f9d0(int param_1,uint param_2,int *param_3)

{
  float fVar1;
  bool bVar2;
  undefined4 in_EAX;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  bool bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar9;
  float fVar10;
  float fVar11;
  
  bVar8 = false;
  pbVar7 = (byte *)param_3[3];
  fVar11 = (float)param_3[1];
  fVar10 = (float)param_3[2];
  uVar4 = param_2;
  iVar5 = param_3[4];
  while (0 < *param_3) {
    *param_3 = *param_3 + -0x1c;
    if (*pbVar7 == 0xee) {
      uVar9 = (uint)(in_NT & 1) * 0x4000 | (uint)bVar8 * 0x400 | (uint)(in_IF & 1) * 0x200 |
              (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4 |
              (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
              (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
      FUN_0065f930(param_3,uVar9,pbVar7,param_3,iVar5,&stack0xffffffe4,unaff_EBX,uVar4,param_1,0xee)
      ;
      in_NT = (uVar9 & 0x4000) != 0;
      bVar8 = (uVar9 & 0x400) != 0;
      in_IF = (uVar9 & 0x200) != 0;
      in_TF = (uVar9 & 0x100) != 0;
      in_AF = (uVar9 & 0x10) != 0;
      in_ID = (uVar9 & 0x200000) != 0;
      in_AC = (uVar9 & 0x40000) != 0;
      in_VIP = 0;
      in_VIF = 0;
      fVar11 = (float)param_3[1];
      fVar10 = (float)param_3[2];
      pbVar7 = (byte *)param_3[3];
      iVar5 = param_3[4];
    }
    else {
      uVar9 = (uint)(*pbVar7 >> 4);
      unaff_EBX = (*pbVar7 & 0xf) * 0x40;
      pbVar7 = pbVar7 + 0xf;
      iVar6 = iVar5 + 0x70;
      iVar3 = -0xe;
      do {
        fVar1 = *(float *)(&DAT_006eac28 + uVar9 * 4);
        fVar10 = fVar11 * *(float *)(&DAT_006eac18 + uVar9 * 4) +
                 *(float *)(&DAT_006eac38 + (uint)(pbVar7[iVar3] >> 4) * 4 + unaff_EBX) +
                 fVar10 * *(float *)(&DAT_006eac28 + uVar9 * 4);
        *(float *)(iVar6 + iVar3 * 8) = fVar10;
        uVar4 = pbVar7[iVar3] & 0xffffff0f;
        fVar11 = fVar10 * *(float *)(&DAT_006eac18 + uVar9 * 4) +
                 *(float *)(&DAT_006eac38 + uVar4 * 4 + unaff_EBX) + fVar11 * fVar1;
        *(float *)(iVar5 + 0x74 + iVar3 * 8) = fVar11;
        param_1 = iVar3 + 1;
        bVar2 = iVar3 < -1;
        iVar3 = param_1;
      } while (bVar2);
      param_3[1] = (int)fVar11;
      param_3[2] = (int)fVar10;
      param_3[4] = iVar6;
      param_3[3] = (int)pbVar7;
      iVar5 = iVar6;
    }
  }
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x65fad0 FUN_0065fad0

undefined8 __fastcall FUN_0065fad0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  bool bVar4;
  undefined4 in_EAX;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  bool bVar14;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar15;
  
  bVar14 = false;
  puVar11 = &stack0xfffffffc;
  iVar9 = param_3[4];
  iVar7 = param_3[2];
  *(int *)(iVar9 + -4) = param_3[1];
  *(int *)(iVar9 + -8) = iVar7;
  uVar8 = 0;
  pbVar12 = (byte *)param_3[3];
  while (0 < *param_3) {
    *param_3 = *param_3 + -0x1c;
    if (*pbVar12 == 0xee) {
      uVar15 = (uint)(in_NT & 1) * 0x4000 | (uint)bVar14 * 0x400 | (uint)(in_IF & 1) * 0x200 |
               (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4 |
               (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
               (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
      FUN_0065f930(param_3,uVar15,pbVar12,param_3,puVar11,&stack0xffffffd8,iVar9,uVar8,iVar7,0xee);
      in_NT = (uVar15 & 0x4000) != 0;
      bVar14 = (uVar15 & 0x400) != 0;
      in_IF = (uVar15 & 0x200) != 0;
      in_TF = (uVar15 & 0x100) != 0;
      in_AF = (uVar15 & 0x10) != 0;
      in_ID = (uVar15 & 0x200000) != 0;
      in_AC = (uVar15 & 0x40000) != 0;
      in_VIP = 0;
      in_VIF = 0;
      param_3 = *(int **)(puVar11 + 8);
      iVar9 = param_3[4];
      iVar7 = param_3[2];
      *(int *)(iVar9 + -4) = param_3[1];
      *(int *)(iVar9 + -8) = iVar7;
      uVar8 = 0;
      pbVar12 = (byte *)param_3[3];
    }
    else {
      fVar1 = *(float *)(&DAT_006eac28 + (uint)(*pbVar12 >> 4) * 4);
      fVar2 = *(float *)(&DAT_006eac18 + (uint)(*pbVar12 >> 4) * 4);
      uVar8 = (uint)(pbVar12[1] >> 4);
      iVar10 = iVar9 + 0x70;
      iVar5 = (*pbVar12 & 0xf) * 0x40;
      pbVar13 = pbVar12 + 0xf;
      iVar6 = -0xe;
      do {
        bVar3 = pbVar13[iVar6];
        *(float *)(iVar10 + iVar6 * 8) =
             *(float *)(iVar9 + 0x6c + iVar6 * 8) * fVar2 +
             *(float *)(&DAT_006eac38 + uVar8 * 4 + iVar5) +
             *(float *)(iVar9 + 0x68 + iVar6 * 8) * fVar1;
        uVar8 = (uint)(pbVar12[iVar6 + 0x10] >> 4);
        *(float *)(iVar9 + 0x74 + iVar6 * 8) =
             *(float *)(iVar10 + iVar6 * 8) * fVar2 +
             *(float *)(&DAT_006eac38 + (bVar3 & 0xffffff0f) * 4 + iVar5) +
             *(float *)(iVar9 + 0x6c + iVar6 * 8) * fVar1;
        iVar7 = iVar6 + 1;
        bVar4 = iVar6 < -1;
        iVar6 = iVar7;
      } while (bVar4);
      param_3[1] = *(int *)(iVar9 + 0x6c);
      param_3[2] = *(int *)(iVar9 + 0x68);
      param_3[4] = iVar10;
      param_3[3] = (int)pbVar13;
      iVar9 = iVar10;
      pbVar12 = pbVar13;
    }
  }
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x65fbd0 FUN_0065fbd0

void __fastcall FUN_0065fbd0(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  if ((DAT_007172f4 & 2) != 0) {
    *param_1 = FUN_0065f9d0;
    return;
  }
  *param_1 = FUN_0065fad0;
  return;
}


// ==== 0x65fc00 FUN_0065fc00

undefined8 __fastcall
FUN_0065fc00(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 in_EAX;
  uint uVar5;
  
  do {
    if ((param_3 & 3) == 0) goto LAB_0065fc2f;
    *(undefined4 *)(param_5 + -4 + param_3 * 4) =
         *(undefined4 *)(&DAT_00717300 + (uint)*(byte *)((param_3 - 1) + param_4) * 4);
    param_3 = param_3 - 1;
  } while (param_3 != 0);
LAB_0065fc70:
  return CONCAT44(param_2,in_EAX);
LAB_0065fc2f:
  do {
    uVar3 = *(undefined4 *)(&DAT_00717300 + (uint)*(byte *)((param_3 - 3) + param_4) * 4);
    bVar1 = *(byte *)((param_3 - 2) + param_4);
    bVar2 = *(byte *)((param_3 - 1) + param_4);
    *(undefined4 *)(param_5 + -0x10 + param_3 * 4) =
         *(undefined4 *)(&DAT_00717300 + (uint)*(byte *)((param_3 - 4) + param_4) * 4);
    *(undefined4 *)(param_5 + -0xc + param_3 * 4) = uVar3;
    uVar3 = *(undefined4 *)(&DAT_00717300 + (uint)bVar2 * 4);
    *(undefined4 *)(param_5 + -8 + param_3 * 4) = *(undefined4 *)(&DAT_00717300 + (uint)bVar1 * 4);
    *(undefined4 *)(param_5 + -4 + param_3 * 4) = uVar3;
    uVar5 = param_3 - 4;
    bVar4 = 3 < (int)param_3;
    param_3 = uVar5;
  } while (uVar5 != 0 && bVar4);
  goto LAB_0065fc70;
}


// ==== 0x65fc80 FUN_0065fc80

void FUN_0065fc80(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x60 + DAT_0071666c;
  puVar1 = (undefined4 *)FUN_00650fd0(param_3[1]);
  (*(code *)param_3[3])(puVar1,*param_3,param_2);
  *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(param_3 + 2);
  *puVar1 = param_3[4];
  puVar1[1] = param_3[5];
  *(undefined1 *)((int)puVar1 + 0x1a) = 0;
  FUN_006577e0(iVar2 + 0x40,puVar1);
  return;
}


// ==== 0x65fce0 SNDI_getb

/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDI_getb(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = param_2; iVar2 != 0; iVar2 = iVar2 + -1) {
    iVar1 = iVar1 * 0x100 + (uint)*param_1;
    param_1 = param_1 + 1;
  }
  if (param_2 == 1) {
    if (0x7f < iVar1) {
      return iVar1 + -0x100;
    }
  }
  else if (param_2 == 2) {
    if (0x7fff < iVar1) {
      return iVar1 + -0x10000;
    }
  }
  else if ((param_2 == 3) && (0x7fffff < iVar1)) {
    iVar1 = iVar1 + -0x1000000;
  }
  return iVar1;
}


// ==== 0x65fd40 FUN_0065fd40

void FUN_0065fd40(float *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  
  fVar1 = *param_1;
  iVar3 = param_2 * -4;
  do {
    fVar1 = param_1[2] * *(float *)(iVar3 + param_3 + param_2 * 4) + fVar1 * param_1[1];
    *(float *)(iVar3 + param_4 + param_2 * 4) = fVar1;
    bVar2 = iVar3 < -4;
    iVar3 = iVar3 + 4;
  } while (bVar2);
  *param_1 = fVar1;
  return;
}


// ==== 0x65fd80 FUN_0065fd80

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


// ==== 0x65fdb0 FUN_0065fdb0

void FUN_0065fdb0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = FUN_0065fd80;
  param_1[1] = 0;
  param_1[7] = param_2;
  return;
}


// ==== 0x65fdd0 FUN_0065fdd0

undefined4 FUN_0065fdd0(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}


// ==== 0x65fdf0 FUN_0065fdf0

uint FUN_0065fdf0(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(short *)(param_1 + 0x24) != 0) {
    *(undefined2 *)(param_1 + 0x24) = 0;
    *(undefined2 *)(param_1 + 0x26) = 1;
  }
  if (*(int *)(param_1 + 0x20) < (int)param_2) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_006510d0(*(int *)(param_1 + 0x1c));
    }
    uVar1 = FUN_00650fd0(param_2 * 4);
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    *(uint *)(param_1 + 0x20) = param_2;
  }
  if (*(short *)(param_1 + 0x26) == 0) {
    puVar4 = *(undefined4 **)(param_1 + 0x1c);
    for (uVar2 = param_2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_4 = *puVar4;
      puVar4 = puVar4 + 1;
      param_4 = param_4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)param_4 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_4 = (undefined4 *)((int)param_4 + 1);
    }
    *(undefined2 *)(param_1 + 0x24) = 1;
    uVar2 = param_2;
  }
  else {
    uVar2 = (*(code *)**(undefined4 **)(param_1 + 8))
                      (*(undefined4 **)(param_1 + 8),param_2,param_4,param_3,1);
    if (0 < (int)uVar2) {
      puVar4 = param_3;
      for (uVar2 = param_2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_4 = *puVar4;
        puVar4 = puVar4 + 1;
        param_4 = param_4 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)param_4 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        param_4 = (undefined4 *)((int)param_4 + 1);
      }
      puVar4 = *(undefined4 **)(param_1 + 0x1c);
      for (uVar2 = param_2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *param_3;
        param_3 = param_3 + 1;
        puVar4 = puVar4 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar4 = *(undefined1 *)param_3;
        param_3 = (undefined4 *)((int)param_3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      *(undefined2 *)(param_1 + 0x26) = 0;
      return param_2;
    }
  }
  return uVar2;
}


// ==== 0x65fed0 FUN_0065fed0

undefined4 FUN_0065fed0(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = FUN_00660030;
  *param_1 = FUN_0065fdf0;
  param_1[8] = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  *(undefined2 *)((int)param_1 + 0x26) = 1;
  return 0;
}


// ==== 0x65ff10 FUN_0065ff10

int FUN_0065ff10(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x20) < param_2) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_006510d0(*(int *)(param_1 + 0x1c));
    }
    *(int *)(param_1 + 0x20) = param_2;
    uVar2 = FUN_00650fd0(param_2 * 4);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
  }
  iVar3 = (*(code *)**(undefined4 **)(param_1 + 8))
                    (*(undefined4 **)(param_1 + 8),param_2,param_3,param_4,1);
  if ((0 < iVar3) &&
     (iVar3 = (*(code *)**(undefined4 **)(param_1 + 0xc))
                        (*(undefined4 **)(param_1 + 0xc),param_2,param_3,
                         *(undefined4 *)(param_1 + 0x1c),2), 0 < iVar3)) {
    iVar5 = 0;
    if (3 < param_2) {
      param_1 = 3;
      iVar3 = 8;
      pfVar4 = (float *)(param_4 + 8);
      do {
        iVar5 = iVar5 + 4;
        iVar3 = iVar3 + 0x10;
        pfVar4[-2] = *(float *)((int)pfVar4 + *(int *)(iVar1 + 0x1c) + -param_4 + -8) + pfVar4[-2];
        pfVar4[-1] = *(float *)((int)pfVar4 + *(int *)(iVar1 + 0x1c) + -param_4 + -4) + pfVar4[-1];
        *pfVar4 = *(float *)(*(int *)(iVar1 + 0x1c) + -0x10 + iVar3) + *pfVar4;
        param_1 = param_1 + 4;
        pfVar4[1] = *(float *)((*(int *)(iVar1 + 0x1c) - param_4) + -0xc + (int)(pfVar4 + 4)) +
                    pfVar4[1];
        pfVar4 = pfVar4 + 4;
      } while (param_1 < param_2);
    }
    while (iVar3 = param_2, iVar5 < param_2) {
      iVar3 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      *(float *)(param_4 + -4 + iVar5 * 4) =
           *(float *)(*(int *)(iVar1 + 0x1c) + iVar3) + *(float *)(param_4 + -4 + iVar5 * 4);
    }
  }
  return iVar3;
}


// ==== 0x660000 FUN_00660000

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


// ==== 0x66002c FUN_0066002c

void FUN_0066002c(void)

{
  return;
}


// ==== 0x660030 FUN_00660030

void FUN_00660030(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_006510d0();
    return;
  }
  return;
}


// ==== 0x660050 FUN_00660050

undefined4 FUN_00660050(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = FUN_00660030;
  *param_1 = FUN_0065ff10;
  param_1[7] = 0;
  param_1[8] = 0;
  return 0;
}


// ==== 0x660080 FUN_00660080

void FUN_00660080(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  
  if (param_4 < param_4 + param_2) {
    pfVar5 = (float *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24) * 4);
    pfVar6 = (float *)(param_3 + 8);
    pfVar7 = param_4;
    do {
      pfVar8 = pfVar7 + 4;
      fVar1 = *(float *)(param_1 + 0x2c) * *pfVar5 + pfVar6[-2] + 1e-20;
      fVar2 = *(float *)(param_1 + 0x2c) * pfVar5[1] + pfVar6[-1] + 1e-20;
      fVar3 = *(float *)(param_1 + 0x2c) * pfVar5[2] + *pfVar6 + 1e-20;
      fVar4 = pfVar5[3] * *(float *)(param_1 + 0x2c) + pfVar6[1] + 1e-20;
      *pfVar7 = fVar1 * *(float *)(param_1 + 0x30) + *pfVar5;
      pfVar7[1] = fVar2 * *(float *)(param_1 + 0x30) + pfVar5[1];
      *(float *)((int)param_4 + (-0x10 - param_3) + (int)(pfVar6 + 4)) =
           fVar3 * *(float *)(param_1 + 0x30) + pfVar5[2];
      pfVar7[3] = fVar4 * *(float *)(param_1 + 0x30) + pfVar5[3];
      pfVar5[2] = fVar3;
      *pfVar5 = fVar1;
      pfVar5[3] = fVar4;
      pfVar5[1] = fVar2;
      pfVar5 = pfVar5 + 4;
      pfVar6 = pfVar6 + 4;
      pfVar7 = pfVar8;
    } while (pfVar8 < param_4 + param_2);
  }
  return;
}


// ==== 0x660160 FUN_00660160

int FUN_00660160(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  iVar2 = param_2;
  if ((puVar1 == (undefined4 *)0x0) ||
     (iVar3 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     0 < iVar3)) {
    for (; iVar3 = param_2, 0 < iVar2; iVar2 = iVar2 - iVar3) {
      if (*(int *)(param_1 + 0x28) <= *(int *)(param_1 + 0x24)) {
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      iVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
      }
      FUN_00660080(param_1,iVar3,param_3,param_4);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + iVar3;
      param_4 = param_4 + iVar3 * 4;
      param_3 = param_3 + iVar3 * 4;
    }
  }
  return iVar3;
}


// ==== 0x6601f0 FUN_006601f0

void FUN_006601f0(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_006510d0(*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// ==== 0x660220 FUN_00660220

undefined4 FUN_00660220(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = FUN_006601f0;
  *param_1 = FUN_00660160;
  param_1[8] = 0;
  param_1[7] = 0;
  return 0;
}


// ==== 0x660250 FUN_00660250

void FUN_00660250(int param_1,int *param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = *param_2;
  iVar4 = param_2[2];
  iVar1 = param_2[1];
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_006510d0(*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  fVar2 = (float)(iVar3 >> 1) * 0.007874016;
  *(float *)(param_1 + 0x2c) = fVar2;
  *(float *)(param_1 + 0x30) = -fVar2;
  iVar3 = FUN_006616e0(iVar1 >> 8,iVar4 >> 8);
  *(int *)(param_1 + 0x28) = iVar3;
  iVar4 = FUN_00650fd0(iVar3 * 4 + 0x10);
  *(int *)(param_1 + 0x20) = iVar4;
  uVar5 = iVar4 + 0xfU & 0xfffffff0;
  *(uint *)(param_1 + 0x1c) = uVar5;
  FUN_00654cd0(uVar5,iVar3 * 4);
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// ==== 0x6602e0 FUN_006602e0

int FUN_006602e0(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 == (undefined4 *)0x0) ||
     (iVar2 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     0 < iVar2)) {
    iVar5 = 0;
    if (3 < param_2) {
      iVar2 = 3;
      pfVar3 = (float *)(param_4 + 4);
      pfVar4 = (float *)(param_3 + 0xc);
      do {
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + 4;
        pfVar3[-1] = pfVar4[-3] * *(float *)(param_1 + 0x1c);
        *pfVar3 = *(float *)((int)pfVar3 + (param_3 - param_4)) * *(float *)(param_1 + 0x1c);
        pfVar3[1] = pfVar4[-1] * *(float *)(param_1 + 0x1c);
        pfVar3[2] = *(float *)(param_1 + 0x1c) * *pfVar4;
        pfVar3 = pfVar3 + 4;
        pfVar4 = pfVar4 + 4;
      } while (iVar2 < param_2);
    }
    iVar2 = param_2;
    if (iVar5 < param_2) {
      param_2 = param_2 - iVar5;
      pfVar3 = (float *)(param_4 + iVar5 * 4);
      do {
        param_2 = param_2 + -1;
        *pfVar3 = *(float *)((int)pfVar3 + (param_3 - param_4)) * *(float *)(param_1 + 0x1c);
        pfVar3 = pfVar3 + 1;
      } while (param_2 != 0);
    }
  }
  return iVar2;
}


// ==== 0x660390 FUN_00660390

undefined4 FUN_00660390(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = 0;
  *param_1 = FUN_006602e0;
  param_1[7] = 0;
  return 0;
}


// ==== 0x6603c0 FUN_006603c0

void FUN_006603c0(int param_1,int *param_2)

{
  *(float *)(param_1 + 0x1c) = (float)*param_2 * 0.00390625;
  return;
}


// ==== 0x6603e0 FUN_006603e0

void FUN_006603e0(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  
  if ((((float)*(int *)(param_1 + 0x1c) * 0.63661975 <= *(float *)(param_1 + 0x24)) ||
      (*(float *)(param_1 + 0x20) <= 0.0)) ||
     ((float)(*(int *)(param_1 + 0x1c) >> 1) <= *(float *)(param_1 + 0x20))) {
    if (0 < param_2) {
      param_3 = param_3 - (int)param_4;
      do {
        *param_4 = *(undefined4 *)((int)param_4 + param_3);
        param_4 = param_4 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  else {
    iVar6 = 0;
    if (3 < param_2) {
      pfVar4 = (float *)(param_4 + 1);
      pfVar5 = (float *)(param_3 + 0xc);
      iVar7 = 3;
      do {
        fVar2 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x28);
        pfVar4[-1] = ((fVar2 + fVar2) * *(float *)(param_1 + 0x38) +
                     (pfVar5[-3] + 1e-20) * *(float *)(param_1 + 0x30)) -
                     *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x28) *
                     *(float *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
        fVar2 = pfVar4[-1];
        *(float *)(param_1 + 0x38) = fVar2;
        fVar3 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x28);
        *pfVar4 = ((fVar3 + fVar3) * fVar2 +
                  (*(float *)((int)pfVar4 + (param_3 - (int)param_4)) + 1e-20) *
                  *(float *)(param_1 + 0x30)) -
                  *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x28) *
                  *(float *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
        fVar2 = *pfVar4;
        *(float *)(param_1 + 0x38) = fVar2;
        fVar3 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x28);
        pfVar4[1] = ((fVar3 + fVar3) * fVar2 + (pfVar5[-1] + 1e-20) * *(float *)(param_1 + 0x30)) -
                    *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x28) *
                    *(float *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
        fVar2 = pfVar4[1];
        *(float *)(param_1 + 0x38) = fVar2;
        fVar3 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x28);
        pfVar4[2] = ((*pfVar5 + 1e-20) * *(float *)(param_1 + 0x30) + (fVar3 + fVar3) * fVar2) -
                    *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x28) *
                    *(float *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
        pfVar1 = pfVar4 + 2;
        iVar7 = iVar7 + 4;
        iVar6 = iVar6 + 4;
        pfVar4 = pfVar4 + 4;
        pfVar5 = pfVar5 + 4;
        *(float *)(param_1 + 0x38) = *pfVar1;
      } while (iVar7 < param_2);
    }
    if (iVar6 < param_2) {
      param_2 = param_2 - iVar6;
      pfVar4 = (float *)(param_4 + iVar6);
      do {
        param_2 = param_2 + -1;
        fVar2 = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x28);
        *pfVar4 = ((fVar2 + fVar2) * *(float *)(param_1 + 0x38) +
                  (*(float *)((int)pfVar4 + (param_3 - (int)param_4)) + 1e-20) *
                  *(float *)(param_1 + 0x30)) -
                  *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x28) *
                  *(float *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
        *(float *)(param_1 + 0x38) = *pfVar4;
        pfVar4 = pfVar4 + 1;
      } while (param_2 != 0);
      return;
    }
  }
  return;
}


// ==== 0x6605c0 FUN_006605c0

int FUN_006605c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 != (undefined4 *)0x0) &&
     (param_2 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     param_2 < 1)) {
    return param_2;
  }
  FUN_006603e0(param_1,param_2,param_3,param_4);
  return param_2;
}


// ==== 0x660610 FUN_00660610

undefined4 FUN_00660610(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = 0;
  *param_1 = FUN_006605c0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return 0;
}


// ==== 0x660640 FUN_00660640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00660640(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  
  iVar1 = param_2[3];
  iVar2 = *param_2;
  iVar3 = param_2[2];
  iVar4 = param_2[1];
  *(float *)(param_1 + 0x20) = (float)(iVar2 >> 8);
  *(int *)(param_1 + 0x1c) = iVar4 >> 8;
  *(float *)(param_1 + 0x24) = (float)(iVar3 >> 8);
  fVar6 = (float)(iVar4 >> 8);
  fVar5 = _K_ONE - ((float)(iVar3 >> 8) * 3.1415927) / fVar6;
  *(float *)(param_1 + 0x28) = fVar5;
  fVar7 = (float10)FUN_006590b0(((float)(iVar2 >> 8) * 6.2831855) / fVar6);
  fVar7 = (((float10)*(float *)(param_1 + 0x28) + (float10)*(float *)(param_1 + 0x28)) /
          ((float10)(fVar5 * fVar5) + (float10)_K_ONE)) * fVar7;
  *(float *)(param_1 + 0x2c) = (float)fVar7;
  fVar7 = (float10)FUN_00661700((float)-(fVar7 * fVar7));
  *(float *)(param_1 + 0x30) =
       (float)(((float10)_K_ONE - (float10)(fVar5 * fVar5)) * fVar7 *
              (float10)((float)iVar1 * 0.00390625));
  return;
}


// ==== 0x660700 FUN_00660700

void FUN_00660700(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[2];
  iVar2 = param_2[1];
  *(float *)(param_1 + 0x50) = (float)(*param_2 >> 7) / (float)(iVar1 >> 8);
  *(float *)(param_1 + 0x54) = (float)(iVar2 >> 7) / (float)(iVar1 >> 8);
  FUN_00661460();
  return;
}


// ==== 0x660760 FUN_00660760

int FUN_00660760(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 != (undefined4 *)0x0) &&
     (iVar2 = (*(code *)*puVar1)(puVar1,param_2,param_4,param_3,*(undefined1 *)(param_1 + 0x1a)),
     iVar2 < 1)) {
    return iVar2;
  }
  FUN_00661210(param_1 + 0x1c,param_2,param_3,param_4);
  return param_2;
}


// ==== 0x6607b0 FUN_006607b0

undefined4 FUN_006607b0(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  param_1[1] = 0;
  *param_1 = FUN_00660760;
  FUN_006611f0(param_1 + 7);
  return 0;
}


// ==== 0x6607e0 FUN_006607e0

void FUN_006607e0(int param_1,int *param_2)

{
  *(float *)(param_1 + 0x54) =
       ((float)(*param_2 >> 8) + (float)(*param_2 >> 8)) / (float)(param_2[1] >> 8);
  FUN_00661460();
  return;
}


// ==== 0x660820 FUN_00660820

int FUN_00660820(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_00713db6 != 0) {
    do {
      if (((undefined4 *)(&DAT_007163dc)[iVar2] != (undefined4 *)0x0) &&
         (iVar1 = SNDVOICEI_get__validate_handle____voice_index_
                            (*(undefined4 *)(&DAT_007163dc)[iVar2]), iVar1 == param_1)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)DAT_00713db6);
  }
  return -1;
}


// ==== 0x660870 FUN_00660870

int FUN_00660870(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar1 = param_1;
  iVar3 = 0;
  iVar5 = param_2;
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_00655830(*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(param_1 + 0x38),
                 *(int *)(param_1 + 0x28));
    *(undefined4 *)(iVar1 + 0x28) = 0;
    iVar5 = param_2;
  }
  while( true ) {
    while( true ) {
      if (iVar5 < 1) {
        return iVar3;
      }
      iVar2 = FUN_0065f430(&param_4,iVar5);
      *(short *)(iVar1 + 0x2c) = *(short *)(iVar1 + 0x2c) + (short)iVar2;
      param_4 = param_4 + iVar2 * 4;
      param_2 = iVar3 + iVar2;
      *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + iVar2;
      if (iVar2 < iVar5) break;
      iVar5 = iVar5 - iVar2;
      iVar3 = param_2;
    }
    iVar5 = iVar5 - iVar2;
    iVar3 = FUN_006556d0(*(undefined4 *)(iVar1 + 0x24),*(undefined1 *)(iVar1 + 0x38),
                         (int *)(iVar1 + 0x20),&param_1);
    *(int *)(iVar1 + 0x1c) = iVar3;
    if (iVar3 == 0) break;
    *(undefined2 *)(iVar1 + 0x2c) = 0;
    if (*(int *)(iVar1 + 0x30) < 2) {
      if (param_1 == 0) {
        puVar4 = (undefined4 *)FUN_0065f3d0(auStack_30);
        uStack_3c = *puVar4;
        uStack_38 = puVar4[1];
        uStack_34 = 1;
        FUN_0065f400(&uStack_3c,0);
        uVar7 = 0;
      }
      else {
        puVar4 = (undefined4 *)FUN_0065f3d0(auStack_24);
        uStack_3c = *puVar4;
        uStack_38 = puVar4[1];
        uStack_34 = 0;
        FUN_0065f400(&uStack_3c,0);
        uVar7 = 0;
      }
    }
    else {
      bVar6 = param_1 != 0;
      if (bVar6) {
        puVar4 = (undefined4 *)FUN_0065f3d0(auStack_c);
        uStack_3c = *puVar4;
        uStack_38 = puVar4[1];
      }
      else {
        puVar4 = (undefined4 *)FUN_0065f3d0(auStack_18);
        uStack_3c = *puVar4;
        uStack_38 = 0;
      }
      uStack_34 = (uint)!bVar6;
      FUN_0065f400(&uStack_3c,0);
      uVar7 = 1;
    }
    FUN_0065f420(uVar7);
    iVar3 = *(int *)(iVar1 + 0x20);
    FUN_0065f350(*(int *)(iVar1 + 0x1c) + 1,iVar3 * 4,iVar3);
    iVar3 = param_2;
  }
  if ((0 < iVar5) && (*(int *)(iVar1 + 0x28) != 0)) {
    FUN_00654cd0(param_4,iVar5 * 4);
  }
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return param_2;
}


// ==== 0x660a60 FUN_00660a60

void FUN_00660a60(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_0065f600();
    return;
  }
  return;
}


// ==== 0x660a80 FUN_00660a80

void FUN_00660a80(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  *param_1 = FUN_00660870;
  uVar2 = FUN_00659960(*(undefined4 *)(param_2 + 0x1c));
  uVar2 = FUN_00660820(uVar2);
  param_1[9] = uVar2;
  uVar1 = FUN_00659990(*(undefined4 *)(param_2 + 0x1c));
  *(undefined1 *)(param_1 + 0xe) = uVar1;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  param_1[0xc] = *(undefined4 *)(param_2 + 0x24);
  param_1[8] = *(undefined4 *)(param_2 + 0xc);
  param_1[1] = FUN_00660a60;
  iVar3 = FUN_0065f5f0(0xd68);
  if (iVar3 != 0) {
    uVar2 = FUN_0065f310();
    param_1[10] = 0;
    param_1[0xd] = uVar2;
    return;
  }
  param_1[10] = 0;
  param_1[0xd] = 0;
  return;
}


// ==== 0x660b00 FUN_00660b00

int FUN_00660b00(int param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  undefined1 auStack_c [4];
  float fStack_8;
  float fStack_4;
  
  iVar4 = 0;
  bVar1 = false;
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00655830(*(undefined4 *)(param_1 + 0x30),*(undefined1 *)(param_1 + 0x38),
                 *(int *)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (param_2 < 1) {
    return 0;
  }
  do {
    iVar2 = FUN_0065f640(&param_4,param_2);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar2;
    param_4 = param_4 + iVar2 * 4;
    iVar4 = iVar4 + iVar2;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + iVar2;
    if (iVar2 < param_2) {
      param_2 = param_2 - iVar2;
      psVar3 = (short *)FUN_006556d0(*(undefined4 *)(param_1 + 0x30),*(undefined1 *)(param_1 + 0x38)
                                     ,(int *)(param_1 + 0x24),auStack_c);
      *(short **)(param_1 + 0x20) = psVar3;
      if (psVar3 == (short *)0x0) {
        if (param_2 < 1) {
          return iVar4;
        }
        if (*(int *)(param_1 + 0x34) == 0) {
          return iVar4;
        }
        FUN_00654cd0(param_4,param_2 * 4);
        return iVar4;
      }
      if (*(int *)(param_1 + 0x2c) < 2) {
        bVar1 = true;
LAB_00660bb1:
        fStack_8 = (float)(int)*psVar3;
        fStack_4 = (float)(int)psVar3[1];
        FUN_0065f910(&fStack_8);
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 4;
      }
      else if (bVar1) goto LAB_00660bb1;
      iVar2 = *(int *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x28) = 0;
      FUN_0065f610(*(undefined4 *)(param_1 + 0x20),iVar2 * 4,iVar2);
    }
    else {
      param_2 = param_2 - iVar2;
    }
    if (param_2 < 1) {
      return iVar4;
    }
  } while( true );
}


// ==== 0x660c40 FUN_00660c40

void FUN_00660c40(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_0065f600();
    return;
  }
  return;
}


// ==== 0x660c60 FUN_00660c60

void FUN_00660c60(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  *param_1 = FUN_00660b00;
  param_1[1] = FUN_00660c40;
  uVar2 = FUN_00659960(*(undefined4 *)(param_2 + 0x1c));
  uVar2 = FUN_00660820(uVar2);
  param_1[0xc] = uVar2;
  uVar1 = FUN_00659990(*(undefined4 *)(param_2 + 0x1c));
  *(undefined1 *)(param_1 + 0xe) = uVar1;
  param_1[0xb] = *(undefined4 *)(param_2 + 0x24);
  param_1[8] = 0;
  param_1[9] = *(undefined4 *)(param_2 + 0xc);
  param_1[10] = 0;
  param_1[0xd] = 0;
  iVar3 = FUN_0065f5f0(0xa8);
  if (iVar3 != 0) {
    uVar2 = FUN_0065fbd0();
    param_1[7] = uVar2;
    return;
  }
  param_1[7] = 0;
  return;
}


// ==== 0x660ce0 FUN_00660ce0

int FUN_00660ce0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_4;
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00655830(*(undefined4 *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x31),
                 *(int *)(param_1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  iVar3 = param_2;
  if (0 < param_2) {
    do {
      if (*(int *)(iVar1 + 0x20) <= *(int *)(iVar1 + 0x24)) {
        iVar2 = FUN_006556d0(*(undefined4 *)(iVar1 + 0x28),*(undefined1 *)(iVar1 + 0x31),&param_4,
                             &param_1);
        *(int *)(iVar1 + 0x1c) = iVar2;
        if (iVar2 == 0) {
          if (*(int *)(iVar1 + 0x2c) != 0) {
            FUN_00654cd0(iVar4,iVar3 * 4);
          }
          break;
        }
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(int *)(iVar1 + 0x20) = param_4;
      }
      iVar2 = *(int *)(iVar1 + 0x24);
      iVar5 = *(int *)(iVar1 + 0x20) - iVar2;
      if (iVar3 < iVar5) {
        iVar5 = iVar3;
      }
      if (*(char *)(iVar1 + 0x30) == '\0') {
        FUN_0065fc00(iVar5,*(int *)(iVar1 + 0x1c) + iVar2,iVar4);
      }
      else {
        (*DAT_00716674)(iVar5,*(int *)(iVar1 + 0x1c) + iVar2 * 2);
      }
      iVar3 = iVar3 - iVar5;
      iVar2 = *(int *)(iVar1 + 0x2c) + iVar5;
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + iVar5;
      iVar4 = iVar4 + iVar5 * 4;
      *(int *)(iVar1 + 0x2c) = iVar2;
      if (iVar3 < 1) {
        return iVar2;
      }
    } while( true );
  }
  return *(int *)(iVar1 + 0x2c);
}


// ==== 0x660dd0 FUN_00660dd0

void FUN_00660dd0(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  *param_1 = FUN_00660ce0;
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


// ==== 0x660e20 FUN_00660e20

undefined4 FUN_00660e20(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  while (0 < param_2) {
    iVar1 = *(int *)(param_1 + 0x20);
    iVar3 = (*(int *)(param_1 + 0x28) - iVar1) + 1;
    if (param_2 < iVar3) {
      iVar3 = param_2;
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
      FUN_0065fc00(iVar3,*(int *)(param_1 + 0x1c) + iVar1,param_4);
    }
    else {
      (*DAT_00716674)(iVar3,*(int *)(param_1 + 0x1c) + iVar1 * 2);
    }
    uVar2 = *(int *)(param_1 + 0x20) + iVar3;
    param_2 = param_2 - iVar3;
    *(uint *)(param_1 + 0x20) = uVar2;
    param_4 = param_4 + iVar3 * 4;
    if (*(uint *)(param_1 + 0x28) < uVar2) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
    }
  }
  return 1;
}


// ==== 0x660e90 FUN_00660e90

void FUN_00660e90(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = FUN_00660e20;
  param_1[7] = *param_2;
  param_1[8] = 0;
  param_1[9] = param_2[4];
  param_1[10] = param_2[5];
  param_1[0xb] = param_2[6];
  param_2[10] = FUN_006591c0;
  return;
}


// ==== 0x660ed0 FUN_00660ed0

void FUN_00660ed0(void)

{
  float fVar1;
  uint uVar2;
  uint local_4;
  
  local_4 = 0xffffff80;
  do {
    fVar1 = (float)(int)local_4;
    uVar2 = local_4 & 0xff;
    local_4 = local_4 + 1;
    *(float *)(&DAT_00717300 + uVar2 * 4) = fVar1 * 256.0;
  } while ((int)local_4 < 0x80);
  return;
}


// ==== 0x660f00 FUN_00660f00

void FUN_00660f00(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}


// ==== 0x660f10 FUN_00660f10

uint FUN_00660f10(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar7 = param_4;
  puVar8 = param_3;
  iVar3 = param_2;
  param_3 = (undefined4 *)param_2;
  if (*(int *)(param_1 + 0x1c) != 0x10000) {
    uVar5 = *(int *)(param_1 + 0x1c) * param_2 + *(int *)(param_1 + 0x20) >> 0x10;
    if (*(short *)(param_1 + 0x28) == 0) {
      uVar5 = uVar5 + (4 - *(short *)(param_1 + 0x2a));
      iVar6 = 0;
      if (0 < *(short *)(param_1 + 0x2a)) {
        do {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(short *)(param_1 + 0x2a));
      }
    }
    else {
      *puVar8 = *(undefined4 *)(param_1 + 0x2c);
      puVar8[1] = *(undefined4 *)(param_1 + 0x30);
      puVar8[2] = *(undefined4 *)(param_1 + 0x34);
      puVar8[3] = *(undefined4 *)(param_1 + 0x38);
      puVar8 = puVar8 + 4;
    }
    if (((0 < (int)uVar5) && (puVar7 = *(undefined4 **)(param_1 + 8), puVar7 != (undefined4 *)0x0))
       && (iVar6 = (*(code *)*puVar7)(puVar7,uVar5,param_4,puVar8,*(undefined1 *)(param_1 + 0x1a)),
          iVar6 < 1)) {
      if (*(short *)(param_1 + 0x28) == 0) {
        *(undefined2 *)(param_1 + 0x28) = 1;
      }
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
      return iVar6;
    }
    if (*(short *)(param_1 + 0x28) == 0) {
      *(undefined2 *)(param_1 + 0x28) = 1;
    }
    else {
      puVar8 = puVar8 + *(short *)(param_1 + 0x2a) + -4;
    }
    param_2 = *(int *)(param_1 + 0x20) << 0x10;
    param_3 = (undefined4 *)0x0;
    (**(code **)(param_1 + 0x24))
              (iVar3,puVar8,param_4,&param_3,&param_2,*(uint *)(param_1 + 0x1c) >> 0x10,
               *(uint *)(param_1 + 0x1c) << 0x10);
    *(uint *)(param_1 + 0x20) = (int)param_3 << 0x10 | param_2 >> 0x10;
    iVar6 = ((uint)param_3 & 0xffff) - (int)*(short *)(param_1 + 0x2a);
    *(undefined4 *)(param_1 + 0x2c) = puVar8[iVar6];
    *(undefined4 *)(param_1 + 0x30) = puVar8[iVar6 + 1];
    *(undefined4 *)(param_1 + 0x34) = puVar8[iVar6 + 2];
    uVar2 = puVar8[iVar6 + 3];
    *(undefined2 *)(param_1 + 0x22) = 0;
    *(undefined4 *)(param_1 + 0x38) = uVar2;
    return iVar3;
  }
  param_4 = (undefined4 *)param_2;
  if (*(short *)(param_1 + 0x28) == 0) {
    iVar6 = (param_2 - (int)*(short *)(param_1 + 0x2a)) + 4;
  }
  else {
    iVar4 = 0;
    iVar6 = param_2;
    if (-(int)*(short *)(param_1 + 0x2a) != -4 && -1 < -(int)*(short *)(param_1 + 0x2a) + 4) {
      do {
        *puVar7 = *(undefined4 *)(param_1 + 0x2c + (*(short *)(param_1 + 0x2a) + iVar4) * 4);
        puVar7 = puVar7 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4 - *(short *)(param_1 + 0x2a));
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    param_2 = (*(code *)*puVar1)(puVar1,iVar6,puVar8,puVar7,*(undefined1 *)(param_1 + 0x1a));
  }
  if (0 < (int)param_2) {
    if (*(short *)(param_1 + 0x28) == 0) {
      iVar6 = iVar3 - *(short *)(param_1 + 0x2a);
      *(undefined2 *)(param_1 + 0x28) = 1;
    }
    else {
      iVar6 = iVar3 + -4;
    }
    puVar7 = puVar7 + iVar6;
    *(undefined4 *)(param_1 + 0x2c) = *puVar7;
    *(undefined4 *)(param_1 + 0x30) = puVar7[1];
    *(undefined4 *)(param_1 + 0x34) = puVar7[2];
    *(undefined4 *)(param_1 + 0x38) = puVar7[3];
    return iVar3;
  }
  if (*(short *)(param_1 + 0x28) == 0) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return param_2;
}


