// ==== 0x5a1100 Career::OpenAvailableEvents

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

void __fastcall Career__OpenAvailableEvents(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  char cVar3;
  int *piVar4;
  uint *puVar5;
  char *pcVar6;
  int extraout_EDX;
  int *piVar7;
  uint uVar8;
  
  piVar7 = &DAT_00733ffc;
  uVar8 = 2;
  do {
    if (((uVar8 - 2 < 0x100) && (piVar7[-1] != 0)) ||
       ((*(int *)(param_2 + 0x88b0) != 0 &&
        ((piVar4 = (int *)(*(int *)(param_2 + 0x88b0) + 0x58a0), piVar4 != (int *)0x0 &&
         (uVar8 - 2 == *piVar4)))))) {
      if (((uVar8 - 2 < 0x100) && (piVar7[-1] != 0)) ||
         (((*(int *)(param_2 + 0x88b0) != 0 &&
           (piVar4 = (int *)(*(int *)(param_2 + 0x88b0) + 0x58a0), piVar4 != (int *)0x0)) &&
          (uVar8 - 2 == *piVar4)))) {
        pcVar6 = (char *)(uVar8 + 0x34a + param_2);
      }
      else {
        pcVar6 = (char *)0x0;
      }
      if (*pcVar6 == '\x01') {
        *pcVar6 = '\0';
      }
    }
    if (((uVar8 - 1 < 0x100) && (*piVar7 != 0)) ||
       ((*(int *)(param_2 + 0x88b0) != 0 &&
        ((piVar4 = (int *)(*(int *)(param_2 + 0x88b0) + 0x58a0), piVar4 != (int *)0x0 &&
         (uVar8 - 1 == *piVar4)))))) {
      if (((uVar8 - 1 < 0x100) && (*piVar7 != 0)) ||
         (((*(int *)(param_2 + 0x88b0) != 0 &&
           (piVar4 = (int *)(*(int *)(param_2 + 0x88b0) + 0x58a0), piVar4 != (int *)0x0)) &&
          (uVar8 - 1 == *piVar4)))) {
        pcVar6 = (char *)(uVar8 + 0x34b + param_2);
      }
      else {
        pcVar6 = (char *)0x0;
      }
      if (*pcVar6 == '\x01') {
        *pcVar6 = '\0';
      }
    }
    if (((uVar8 < 0x100) && (piVar7[1] != 0)) ||
       ((*(int *)(param_2 + 0x88b0) != 0 &&
        ((puVar5 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0 &&
         (uVar8 == *puVar5)))))) {
      if (((uVar8 < 0x100) && (piVar7[1] != 0)) ||
         (((*(int *)(param_2 + 0x88b0) != 0 &&
           (puVar5 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0)) &&
          (uVar8 == *puVar5)))) {
        pcVar6 = (char *)(uVar8 + 0x34c + param_2);
      }
      else {
        pcVar6 = (char *)0x0;
      }
      if (*pcVar6 == '\x01') {
        *pcVar6 = '\0';
      }
    }
    uVar1 = uVar8 + 1;
    if (((uVar1 < 0x100) && (piVar7[2] != 0)) ||
       ((*(int *)(param_2 + 0x88b0) != 0 &&
        ((puVar5 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0 &&
         (uVar1 == *puVar5)))))) {
      if (((uVar1 < 0x100) && (piVar7[2] != 0)) ||
         (((*(int *)(param_2 + 0x88b0) != 0 &&
           (puVar5 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0)) &&
          (uVar1 == *puVar5)))) {
        pcVar6 = (char *)(uVar8 + 0x34d + param_2);
      }
      else {
        pcVar6 = (char *)0x0;
      }
      if (*pcVar6 == '\x01') {
        *pcVar6 = '\0';
      }
    }
    uVar1 = uVar8 + 2;
    piVar7 = piVar7 + 4;
    uVar8 = uVar8 + 4;
  } while (uVar1 < 0x100);
  uVar8 = 0;
  do {
    puVar5 = (uint *)(&DAT_00733ff8)[uVar8];
    if (((puVar5 != (uint *)0x0) ||
        (((*(int *)(param_2 + 0x88b0) != 0 &&
          (puVar5 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0)) &&
         (uVar8 == *puVar5)))) &&
       ((cVar3 = Career__ArePrerequisitesDone(), param_2 = extraout_EDX, cVar3 != '\0' &&
        ((((uVar1 = *puVar5, uVar1 < 0x100 && ((&DAT_00733ff8)[uVar1] != 0)) ||
          ((*(int *)(extraout_EDX + 0x88b0) != 0 &&
           ((puVar5 = (uint *)(*(int *)(extraout_EDX + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0 &&
            (uVar1 == *puVar5)))))) &&
         (puVar2 = (undefined1 *)(uVar1 + 0x34c + extraout_EDX), puVar2 != (undefined1 *)0x0)))))) {
      *puVar2 = 1;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x100);
  return;
}


// ==== 0x5a1340 Career::GetUrlRank

/* [canon] canon high (ghidra+hopper) docs/re/canon.md */

int Career__GetUrlRank(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  char *pcVar5;
  int unaff_EBX;
  short sVar6;
  uint uVar7;
  int *local_8;
  int local_4;
  
  local_4 = 0;
  sVar6 = 100;
  local_8 = &DAT_00733ffc;
  uVar7 = 2;
  do {
    uVar1 = uVar7 - 2;
    if ((((uVar1 < 0x100) && (iVar2 = local_8[-1], iVar2 != 0)) && (*(int *)(iVar2 + 4) == 6)) &&
       (*(short *)(iVar2 + 0x34) == param_1)) {
      if ((iVar2 == 0) &&
         (((*(int *)(unaff_EBX + 0x88b0) == 0 ||
           (piVar3 = (int *)(*(int *)(unaff_EBX + 0x88b0) + 0x58a0), piVar3 == (int *)0x0)) ||
          (uVar7 - 2 != *piVar3)))) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(uVar7 + 0x34a + unaff_EBX);
      }
      if (*pcVar5 == '\x02') {
        if (*(short *)(iVar2 + 0x36) < sVar6) {
          sVar6 = *(short *)(iVar2 + 0x36);
          local_4 = iVar2;
        }
      }
    }
    if (((uVar7 - 1 < 0x100) && (iVar2 = *local_8, iVar2 != 0)) &&
       ((*(int *)(iVar2 + 4) == 6 && (*(short *)(iVar2 + 0x34) == param_1)))) {
      if ((iVar2 == 0) &&
         (((*(int *)(unaff_EBX + 0x88b0) == 0 ||
           (piVar3 = (int *)(*(int *)(unaff_EBX + 0x88b0) + 0x58a0), piVar3 == (int *)0x0)) ||
          (uVar7 - 1 != *piVar3)))) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(unaff_EBX + 0x34d + uVar1);
      }
      if (*pcVar5 == '\x02') {
        if (*(short *)(iVar2 + 0x36) < sVar6) {
          sVar6 = *(short *)(iVar2 + 0x36);
          local_4 = iVar2;
        }
      }
    }
    if (((uVar7 < 0x100) && (iVar2 = local_8[1], iVar2 != 0)) &&
       ((*(int *)(iVar2 + 4) == 6 && (*(short *)(iVar2 + 0x34) == param_1)))) {
      if ((iVar2 == 0) &&
         (((*(int *)(unaff_EBX + 0x88b0) == 0 ||
           (puVar4 = (uint *)(*(int *)(unaff_EBX + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0)) ||
          (uVar7 != *puVar4)))) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(unaff_EBX + 0x34e + uVar1);
      }
      if (*pcVar5 == '\x02') {
        if (*(short *)(iVar2 + 0x36) < sVar6) {
          sVar6 = *(short *)(iVar2 + 0x36);
          local_4 = iVar2;
        }
      }
    }
    if ((((uVar7 + 1 < 0x100) && (iVar2 = local_8[2], iVar2 != 0)) && (*(int *)(iVar2 + 4) == 6)) &&
       (*(short *)(iVar2 + 0x34) == param_1)) {
      if ((iVar2 == 0) &&
         (((*(int *)(unaff_EBX + 0x88b0) == 0 ||
           (puVar4 = (uint *)(*(int *)(unaff_EBX + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0)) ||
          (uVar7 + 1 != *puVar4)))) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(unaff_EBX + 0x34f + uVar1);
      }
      if (*pcVar5 == '\x02') {
        if (*(short *)(iVar2 + 0x36) < sVar6) {
          sVar6 = *(short *)(iVar2 + 0x36);
          local_4 = iVar2;
        }
      }
    }
    local_8 = local_8 + 4;
    uVar1 = uVar7 + 2;
    uVar7 = uVar7 + 4;
  } while (uVar1 < 0x100);
  if (local_4 != 0) {
    return (int)*(short *)(local_4 + 0x36);
  }
  return -1;
}


// ==== 0x5a1520 Career::GetCash

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 Career__GetCash(int param_1)

{
  if (((DAT_0073494c == 0) && (DAT_00735ec1 == '\0')) && (DAT_0073440c == '\0')) {
    return *(undefined4 *)(param_1 + 0x1374);
  }
  return 1000000000;
}


// ==== 0x5a1550 Career::IsUpgradeUnlocked

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

uint Career__IsUpgradeUnlocked(int param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint unaff_EDI;
  
  iVar3 = DAT_0073494c;
  if ((DAT_0073494c != 0) || (iVar3 = 0, DAT_00735ec1 != '\0')) {
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  uVar4 = 0;
  do {
    puVar2 = (uint *)(&DAT_00733ff8)[uVar4];
    if ((puVar2 != (uint *)0x0) ||
       (((puVar2 = *(uint **)(param_1 + 0x88b0), puVar2 != (uint *)0x0 &&
         (puVar2 = puVar2 + 0x1628, puVar2 != (uint *)0x0)) && (uVar4 == *puVar2)))) {
      puVar1 = puVar2 + 0x1d;
      iVar3 = 0;
      if (0 < (int)*puVar1) {
        puVar2 = puVar2 + 0x10;
        do {
          if (((puVar2[-2] == 0) && (puVar2[-1] == param_2)) && (*puVar2 == unaff_EDI)) {
            if (((0xff < uVar4) || ((&DAT_00733ff8)[uVar4] == 0)) &&
               ((*(int *)(param_1 + 0x88b0) == 0 ||
                ((puVar2 = (uint *)(*(int *)(param_1 + 0x88b0) + 0x58a0), puVar2 == (uint *)0x0 ||
                 (uVar4 != *puVar2)))))) {
              return (uint)(cRam00000000 == '\x02');
            }
            return CONCAT31((int3)(uVar4 + 0x34c + param_1 >> 8),
                            *(char *)(uVar4 + 0x34c + param_1) == '\x02');
          }
          iVar3 = iVar3 + 1;
          puVar2 = puVar2 + 3;
        } while (iVar3 < (int)*puVar1);
      }
    }
    uVar4 = uVar4 + 1;
    if (0xff < uVar4) {
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
  } while( true );
}


// ==== 0x5a1630 Career::IsCarUnlocked

/* [canon] canon high (ghidra) docs/re/canon.md */

uint Career__IsCarUnlocked(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int unaff_EBX;
  uint uVar4;
  uint unaff_EDI;
  
  iVar3 = DAT_0073494c;
  if ((DAT_0073494c != 0) || (iVar3 = 0, DAT_00735ec1 != '\0')) {
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  uVar4 = 0;
  do {
    puVar2 = (uint *)(&DAT_00733ff8)[uVar4];
    if ((puVar2 != (uint *)0x0) ||
       (((puVar2 = *(uint **)(unaff_EBX + 0x88b0), puVar2 != (uint *)0x0 &&
         (puVar2 = puVar2 + 0x1628, puVar2 != (uint *)0x0)) && (uVar4 == *puVar2)))) {
      puVar1 = puVar2 + 0x1d;
      iVar3 = 0;
      if (0 < (int)*puVar1) {
        puVar2 = puVar2 + 0xe;
        do {
          if ((*puVar2 == 2) && (puVar2[1] == unaff_EDI)) {
            if (((0xff < uVar4) || ((&DAT_00733ff8)[uVar4] == 0)) &&
               (((*(int *)(unaff_EBX + 0x88b0) == 0 ||
                 (puVar2 = (uint *)(*(int *)(unaff_EBX + 0x88b0) + 0x58a0), puVar2 == (uint *)0x0))
                || (uVar4 != *puVar2)))) {
              return (uint)(cRam00000000 == '\x02');
            }
            return CONCAT31((int3)(uVar4 + 0x34c + unaff_EBX >> 8),
                            *(char *)(uVar4 + 0x34c + unaff_EBX) == '\x02');
          }
          iVar3 = iVar3 + 1;
          puVar2 = puVar2 + 3;
        } while (iVar3 < (int)*puVar1);
      }
    }
    uVar4 = uVar4 + 1;
    if (0xff < uVar4) {
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
  } while( true );
}


// ==== 0x5a16f0 Career::IsTrackUnlocked

/* [canon] canon high (ghidra) docs/re/canon.md */

uint Career__IsTrackUnlocked(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint unaff_EBX;
  uint uVar4;
  uint unaff_EDI;
  
  iVar3 = DAT_0073494c;
  if ((DAT_0073494c != 0) || (iVar3 = 0, DAT_00735ec1 != '\0')) {
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  uVar4 = 0;
  do {
    puVar2 = (uint *)(&DAT_00733ff8)[uVar4];
    if ((puVar2 != (uint *)0x0) ||
       (((puVar2 = *(uint **)(param_1 + 0x88b0), puVar2 != (uint *)0x0 &&
         (puVar2 = puVar2 + 0x1628, puVar2 != (uint *)0x0)) && (uVar4 == *puVar2)))) {
      puVar1 = puVar2 + 0x1d;
      iVar3 = 0;
      if (0 < (int)*puVar1) {
        puVar2 = puVar2 + 0x10;
        do {
          if (((puVar2[-2] == 3) && (puVar2[-1] == unaff_EBX)) && (*puVar2 == unaff_EDI)) {
            if (((0xff < uVar4) || ((&DAT_00733ff8)[uVar4] == 0)) &&
               ((*(int *)(param_1 + 0x88b0) == 0 ||
                ((puVar2 = (uint *)(*(int *)(param_1 + 0x88b0) + 0x58a0), puVar2 == (uint *)0x0 ||
                 (uVar4 != *puVar2)))))) {
              return (uint)(cRam00000000 == '\x02');
            }
            return CONCAT31((int3)(uVar4 + 0x34c + param_1 >> 8),
                            *(char *)(uVar4 + 0x34c + param_1) == '\x02');
          }
          iVar3 = iVar3 + 1;
          puVar2 = puVar2 + 3;
        } while (iVar3 < (int)*puVar1);
      }
    }
    uVar4 = uVar4 + 1;
    if (0xff < uVar4) {
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
  } while( true );
}


// ==== 0x5a17d0 FUN_005a17d0

int __fastcall FUN_005a17d0(uint param_1,int param_2)

{
  uint *puVar1;
  
  if (((0xff < param_1) || ((&DAT_00733ff8)[param_1] == 0)) &&
     ((*(int *)(param_2 + 0x88b0) == 0 ||
      ((puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 == (uint *)0x0 ||
       (param_1 != *puVar1)))))) {
    return 0;
  }
  return param_1 + 0x34c + param_2;
}


// ==== 0x5a1810 FUN_005a1810

uint * __thiscall FUN_005a1810(uint param_1,int param_2)

{
  uint *puVar1;
  
  if (((0xff < param_1) || (puVar1 = (uint *)(&DAT_00733ff8)[param_1], puVar1 == (uint *)0x0)) &&
     ((*(int *)(param_2 + 0x88b0) == 0 ||
      ((puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 == (uint *)0x0 ||
       (param_1 != *puVar1)))))) {
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}


// ==== 0x5a1850 Career::OpenNextCashEvent

/* [canon] canon high (ghidra) docs/re/canon.md */

void Career__OpenNextCashEvent(void)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  char *pcVar5;
  uint uVar6;
  int *piVar7;
  int unaff_EDI;
  
  uVar6 = 0;
  do {
    puVar2 = (uint *)(&DAT_00733ff8)[uVar6];
    if (((puVar2 != (uint *)0x0) ||
        (((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          (puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0)) &&
         (uVar6 == *puVar2)))) && (puVar2[1] == 8)) {
      if (((uVar6 < 0x100) && ((&DAT_00733ff8)[uVar6] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
           (uVar6 == *puVar2)))))) {
        pcVar5 = (char *)(uVar6 + 0x34c + unaff_EDI);
      }
      else {
        pcVar5 = (char *)0x0;
      }
      if (*pcVar5 == '\0') goto LAB_005a1b01;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x100);
  piVar7 = &DAT_00733ffc;
  uVar6 = 2;
  do {
    if ((((uVar6 - 2 < 0x100) && (piVar3 = (int *)piVar7[-1], piVar3 != (int *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((piVar3 = (int *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), piVar3 != (int *)0x0 &&
          (uVar6 - 2 == *piVar3)))))) && (piVar3[1] == 8)) {
      if (((uVar6 - 2 < 0x100) && (piVar7[-1] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((piVar3 = (int *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), piVar3 != (int *)0x0 &&
           (uVar6 - 2 == *piVar3)))))) {
        puVar4 = (undefined1 *)(uVar6 + 0x34a + unaff_EDI);
      }
      else {
        puVar4 = (undefined1 *)0x0;
      }
      *puVar4 = 0;
    }
    if ((((uVar6 - 1 < 0x100) && (piVar3 = (int *)*piVar7, piVar3 != (int *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((piVar3 = (int *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), piVar3 != (int *)0x0 &&
          (uVar6 - 1 == *piVar3)))))) && (piVar3[1] == 8)) {
      if (((uVar6 - 1 < 0x100) && (*piVar7 != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((piVar3 = (int *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), piVar3 != (int *)0x0 &&
           (uVar6 - 1 == *piVar3)))))) {
        puVar4 = (undefined1 *)(uVar6 + 0x34b + unaff_EDI);
      }
      else {
        puVar4 = (undefined1 *)0x0;
      }
      *puVar4 = 0;
    }
    if ((((uVar6 < 0x100) && (puVar2 = (uint *)piVar7[1], puVar2 != (uint *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
          (uVar6 == *puVar2)))))) && (puVar2[1] == 8)) {
      if (((uVar6 < 0x100) && (piVar7[1] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
           (uVar6 == *puVar2)))))) {
        puVar4 = (undefined1 *)(uVar6 + 0x34c + unaff_EDI);
      }
      else {
        puVar4 = (undefined1 *)0x0;
      }
      *puVar4 = 0;
    }
    uVar1 = uVar6 + 1;
    if ((((uVar1 < 0x100) && (puVar2 = (uint *)piVar7[2], puVar2 != (uint *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
          (uVar1 == *puVar2)))))) && (puVar2[1] == 8)) {
      if (((uVar1 < 0x100) && (piVar7[2] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
           (uVar1 == *puVar2)))))) {
        puVar4 = (undefined1 *)(uVar6 + 0x34d + unaff_EDI);
      }
      else {
        puVar4 = (undefined1 *)0x0;
      }
      *puVar4 = 0;
    }
    uVar1 = uVar6 + 2;
    piVar7 = piVar7 + 4;
    uVar6 = uVar6 + 4;
  } while (uVar1 < 0x100);
  uVar6 = 0;
  do {
    puVar2 = (uint *)(&DAT_00733ff8)[uVar6];
    if (((puVar2 != (uint *)0x0) ||
        (((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          (puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0)) &&
         (uVar6 == *puVar2)))) && (puVar2[1] == 8)) {
      if (((uVar6 < 0x100) && ((&DAT_00733ff8)[uVar6] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar2 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
           (uVar6 == *puVar2)))))) {
        pcVar5 = (char *)(uVar6 + 0x34c + unaff_EDI);
      }
      else {
        pcVar5 = (char *)0x0;
      }
      if (*pcVar5 == '\0') {
LAB_005a1b01:
        *pcVar5 = '\x01';
        return;
      }
    }
    uVar6 = uVar6 + 1;
    if (0xff < uVar6) {
      return;
    }
  } while( true );
}


// ==== 0x5a1b10 Career::ScaleCashEvent

/* [canon] canon med (ghidra) docs/re/canon.md */

void __fastcall Career__ScaleCashEvent(undefined4 param_1,int param_2)

{
  uint *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    puVar1 = (uint *)(&DAT_00733ff8)[uVar3];
    if (((puVar1 != (uint *)0x0) ||
        (((*(int *)(param_2 + 0x88b0) != 0 &&
          (puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0)) &&
         (uVar3 == *puVar1)))) && (puVar1[1] != 8)) {
      if (((uVar3 < 0x100) && ((&DAT_00733ff8)[uVar3] != 0)) ||
         ((*(int *)(param_2 + 0x88b0) != 0 &&
          ((puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
           (uVar3 == *puVar1)))))) {
        pcVar2 = (char *)(uVar3 + 0x34c + param_2);
      }
      else {
        pcVar2 = (char *)0x0;
      }
      uVar4 = uVar3;
      if (*pcVar2 == '\x01') break;
    }
    uVar3 = uVar3 + 1;
    uVar4 = 0xffffffff;
  } while (uVar3 < 0x100);
  uVar3 = 0;
  do {
    puVar1 = (uint *)(&DAT_00733ff8)[uVar3];
    if (((puVar1 != (uint *)0x0) ||
        (((*(int *)(param_2 + 0x88b0) != 0 &&
          (puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0)) &&
         (uVar3 == *puVar1)))) && (puVar1[1] == 8)) {
      if (((uVar3 < 0x100) && ((&DAT_00733ff8)[uVar3] != 0)) ||
         ((*(int *)(param_2 + 0x88b0) != 0 &&
          ((puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
           (uVar3 == *puVar1)))))) {
        pcVar2 = (char *)(uVar3 + 0x34c + param_2);
      }
      else {
        pcVar2 = (char *)0x0;
      }
      if (*pcVar2 == '\x01') {
        if (uVar3 == 0xffffffff) {
          return;
        }
        if (uVar4 == 0xffffffff) {
          return;
        }
        if (((0xff < uVar3) || (puVar1 = (uint *)(&DAT_00733ff8)[uVar3], puVar1 == (uint *)0x0)) &&
           ((*(int *)(param_2 + 0x88b0) == 0 ||
            ((puVar1 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar1 == (uint *)0x0 ||
             (uVar3 != *puVar1)))))) {
          puVar1 = (uint *)0x0;
        }
        if ((int)uVar4 < 1) {
          if ((int)uVar4 < 0x32) goto LAB_005a1d2c;
        }
        else if ((int)uVar4 < 0x32) {
          *(undefined2 *)((int)puVar1 + 0xe6) = 2;
          *(undefined2 *)(puVar1 + 0x47) = 2;
          puVar1[10] = 0x43610000;
          puVar1[0xb] = 0x43960000;
          puVar1[0xc] = 0x43bb8000;
          *(undefined2 *)(puVar1 + 0x39) = 1;
          *(undefined2 *)(puVar1 + 0x3a) = 3;
          *(undefined2 *)(puVar1 + 0x40) = 1;
          *(undefined2 *)((int)puVar1 + 0x102) = 3;
          *(undefined2 *)(puVar1 + 0x41) = 4;
          *(undefined2 *)((int)puVar1 + 0x11e) = 3;
          *(undefined2 *)(puVar1 + 0x48) = 4;
          return;
        }
        if ((int)uVar4 < 0x4e) {
          *(undefined2 *)(puVar1 + 0x40) = 2;
          *(undefined2 *)(puVar1 + 0x47) = 2;
          puVar1[10] = 0x44034000;
          puVar1[0xb] = 0x442f0000;
          puVar1[0xc] = 0x444e4000;
          *(undefined2 *)(puVar1 + 0x3a) = 5;
          *(undefined2 *)((int)puVar1 + 0x102) = 3;
          *(undefined2 *)(puVar1 + 0x41) = 4;
          *(undefined2 *)((int)puVar1 + 0x11e) = 3;
          *(undefined2 *)(puVar1 + 0x48) = 4;
          *(undefined2 *)(puVar1 + 0x39) = 3;
          *(undefined2 *)((int)puVar1 + 0xe6) = 4;
          return;
        }
LAB_005a1d2c:
        if ((0x4c < (int)uVar4) && ((int)uVar4 < 0x72)) {
          puVar1[10] = 0x450ca000;
          puVar1[0xb] = 0x453b8000;
          puVar1[0xc] = 0x456a6000;
          *(undefined2 *)(puVar1 + 0x3a) = 5;
          *(undefined2 *)(puVar1 + 0x40) = 3;
          *(undefined2 *)((int)puVar1 + 0x102) = 4;
          *(undefined2 *)(puVar1 + 0x41) = 5;
          *(undefined2 *)(puVar1 + 0x47) = 4;
          *(undefined2 *)((int)puVar1 + 0x11e) = 5;
          *(undefined2 *)(puVar1 + 0x48) = 6;
          *(undefined2 *)(puVar1 + 0x39) = 3;
          *(undefined2 *)((int)puVar1 + 0xe6) = 4;
        }
        return;
      }
    }
    uVar3 = uVar3 + 1;
    if (0xff < uVar3) {
      return;
    }
  } while( true );
}


// ==== 0x5a1da0 Career::CountFinishedEvents

/* [canon] canon med (ghidra) docs/re/canon.md */

int Career__CountFinishedEvents(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  uint uVar5;
  int unaff_EDI;
  
  uVar5 = 0;
  iVar2 = 0;
  do {
    puVar3 = (uint *)(&DAT_00733ff8)[uVar5];
    if (((puVar3 != (uint *)0x0) ||
        (((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          (puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0)) &&
         (uVar5 == *puVar3)))) && (puVar3[1] != 8)) {
      if (((uVar5 < 0x100) && ((&DAT_00733ff8)[uVar5] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
           (uVar5 == *puVar3)))))) {
        pcVar4 = (char *)(uVar5 + 0x34c + unaff_EDI);
      }
      else {
        pcVar4 = (char *)0x0;
      }
      if ((*pcVar4 == '\x02') || (*pcVar4 == '\x04')) {
        iVar2 = iVar2 + 1;
      }
    }
    uVar1 = uVar5 + 1;
    if ((((uVar1 < 0x100) && (puVar3 = (uint *)(&DAT_00733ffc)[uVar5], puVar3 != (uint *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
          (uVar1 == *puVar3)))))) && (puVar3[1] != 8)) {
      if (((uVar1 < 0x100) && ((&DAT_00733ffc)[uVar5] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
           (uVar1 == *puVar3)))))) {
        pcVar4 = (char *)(uVar5 + 0x34d + unaff_EDI);
      }
      else {
        pcVar4 = (char *)0x0;
      }
      if ((*pcVar4 == '\x02') || (*pcVar4 == '\x04')) {
        iVar2 = iVar2 + 1;
      }
    }
    uVar1 = uVar5 + 2;
    if ((((uVar1 < 0x100) && (puVar3 = (uint *)(&DAT_00734000)[uVar5], puVar3 != (uint *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
          (uVar1 == *puVar3)))))) && (puVar3[1] != 8)) {
      if (((uVar1 < 0x100) && ((&DAT_00734000)[uVar5] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
           (uVar1 == *puVar3)))))) {
        pcVar4 = (char *)(uVar5 + 0x34e + unaff_EDI);
      }
      else {
        pcVar4 = (char *)0x0;
      }
      if ((*pcVar4 == '\x02') || (*pcVar4 == '\x04')) {
        iVar2 = iVar2 + 1;
      }
    }
    uVar1 = uVar5 + 3;
    if ((((uVar1 < 0x100) && (puVar3 = (uint *)(&DAT_00734004)[uVar5], puVar3 != (uint *)0x0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
          (uVar1 == *puVar3)))))) && (puVar3[1] != 8)) {
      if (((uVar1 < 0x100) && ((&DAT_00734004)[uVar5] != 0)) ||
         ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
          ((puVar3 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar3 != (uint *)0x0 &&
           (uVar1 == *puVar3)))))) {
        pcVar4 = (char *)(uVar5 + 0x34f + unaff_EDI);
      }
      else {
        pcVar4 = (char *)0x0;
      }
      if ((*pcVar4 == '\x02') || (*pcVar4 == '\x04')) {
        iVar2 = iVar2 + 1;
      }
    }
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x100);
  return iVar2;
}


// ==== 0x5a1fa0 FECareerManager::AreAllUnlockedPhysicsUpgradesPurchased

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

uint FECareerManager__AreAllUnlockedPhysicsUpgradesPurchased(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_EBX;
  int iVar4;
  int local_734;
  undefined1 local_730 [1836];
  
  RideInfo__Init();
  FECarConfig__BuildRide(unaff_EBX,0,local_730);
  local_734 = 0;
  do {
    if ((local_734 != 9) && (local_734 != 10)) {
      iVar1 = FUN_005a0350();
      iVar4 = 0;
      do {
        uVar2 = Career__IsUpgradeUnlocked(unaff_EBX,iVar1);
        if (((char)uVar2 != '\0') &&
           (uVar3 = CONCAT31((int3)((uint)uVar2 >> 8),DAT_00735ec1), DAT_00735ec1 == '\0')) {
          if ((iVar1 < 0) || (0x18 < iVar1)) {
LAB_005a201b:
            return uVar3 & 0xffffff00;
          }
          uVar3 = 0;
          while (*(int *)(iVar1 * 0x90 + 0x450 + unaff_EBX + uVar3 * 4) != iVar4) {
            uVar3 = uVar3 + 1;
            if (0x23 < (int)uVar3) goto LAB_005a201b;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
    local_734 = local_734 + 1;
    if (10 < local_734) {
      return CONCAT31((int3)((uint)local_734 >> 8),1);
    }
  } while( true );
}


// ==== 0x5a2040 Career::IsPlayerStuck

/* [canon] canon med (ghidra) docs/re/canon.md */

uint Career__IsPlayerStuck(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_734;
  undefined1 local_730 [1836];
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    puVar1 = (uint *)(&DAT_00733ff8)[uVar3];
    if (((puVar1 != (uint *)0x0) ||
        (((*(int *)(param_1 + 0x88b0) != 0 &&
          (puVar1 = (uint *)(*(int *)(param_1 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0)) &&
         (uVar3 == *puVar1)))) && (puVar1[1] != 1)) {
      if (((uVar3 < 0x100) && ((&DAT_00733ff8)[uVar3] != 0)) ||
         ((*(int *)(param_1 + 0x88b0) != 0 &&
          ((puVar1 = (uint *)(*(int *)(param_1 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
           (uVar3 == *puVar1)))))) {
        puVar1 = (uint *)(uVar3 + 0x34c + param_1);
      }
      else {
        puVar1 = (uint *)0x0;
      }
      if ((char)*puVar1 == '\x01') goto LAB_005a214b;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  uVar3 = 0;
  do {
    puVar1 = (uint *)(&DAT_00733ff8)[uVar3];
    if (((puVar1 != (uint *)0x0) ||
        (((puVar1 = *(uint **)(param_1 + 0x88b0), puVar1 != (uint *)0x0 &&
          (puVar1 = puVar1 + 0x1628, puVar1 != (uint *)0x0)) && (uVar3 == *puVar1)))) &&
       (puVar1[1] == 1)) {
      if (((uVar3 < 0x100) && ((&DAT_00733ff8)[uVar3] != 0)) ||
         ((*(int *)(param_1 + 0x88b0) != 0 &&
          ((puVar1 = (uint *)(*(int *)(param_1 + 0x88b0) + 0x58a0), puVar1 != (uint *)0x0 &&
           (uVar3 == *puVar1)))))) {
        puVar1 = (uint *)(uVar3 + 0x34c + param_1);
      }
      else {
        puVar1 = (uint *)0x0;
      }
      if ((char)*puVar1 == '\x01') {
        RideInfo__Init();
        puVar1 = (uint *)FECarConfig__BuildRide(param_1,0,local_730);
        local_734 = 0;
        do {
          if ((iVar4 != 9) && (iVar4 != 10)) {
            uVar3 = FUN_005a0350();
            iVar5 = 0;
            do {
              puVar1 = (uint *)Career__IsUpgradeUnlocked(param_1,uVar3);
              if (((char)puVar1 != '\0') &&
                 (puVar1 = (uint *)CONCAT31((int3)((uint)puVar1 >> 8),DAT_00735ec1),
                 DAT_00735ec1 == '\0')) {
                if ((-1 < (int)uVar3) && ((int)uVar3 < 0x19)) {
                  puVar1 = (uint *)0x0;
                  do {
                    if (*(int *)(uVar3 * 0x90 + 0x450 + param_1 + (int)puVar1 * 4) == iVar5)
                    goto LAB_005a21fe;
                    puVar1 = (uint *)((int)puVar1 + 1);
                  } while ((int)puVar1 < 0x24);
                }
                if (uVar3 < 0x20) {
                  iVar2 = (&DAT_00733f78)[uVar3];
                }
                else {
                  iVar2 = 0;
                }
                switch(iVar5) {
                default:
                  puVar1 = (uint *)0x0;
                  break;
                case 1:
                  puVar1 = *(uint **)(iVar2 + 4);
                  break;
                case 2:
                  puVar1 = *(uint **)(iVar2 + 8);
                  break;
                case 3:
                  puVar1 = *(uint **)(iVar2 + 0xc);
                }
                local_734 = local_734 + (int)puVar1;
              }
LAB_005a21fe:
              iVar5 = iVar5 + 1;
            } while (iVar5 < 4);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0xb);
        if (local_734 != 0) {
          if (((DAT_0073494c == 0) && (DAT_00735ec1 == '\0')) && (DAT_0073440c == '\0')) {
            puVar1 = *(uint **)(param_1 + 0x1374);
          }
          else {
            puVar1 = (uint *)0x3b9aca00;
          }
          if ((int)puVar1 < local_734) {
            return CONCAT31((int3)((uint)puVar1 >> 8),1);
          }
        }
LAB_005a214b:
        return (uint)puVar1 & 0xffffff00;
      }
    }
    uVar3 = uVar3 + 1;
    if (0xff < uVar3) goto LAB_005a214b;
  } while( true );
}


// ==== 0x5a2270 Career::RefreshOpenEvents

/* [canon] canon high (ghidra) docs/re/canon.md */

void Career__RefreshOpenEvents(uint *param_1)

{
  char cVar1;
  int in_EAX;
  uint *puVar2;
  char *pcVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint local_30 [12];
  
  Career__OpenAvailableEvents();
  puVar5 = local_30;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
  }
  cVar1 = Career__IsPlayerStuck(in_EAX);
  if (cVar1 != '\0') {
    Career__OpenNextCashEvent(local_30);
    Career__ScaleCashEvent();
  }
  uVar6 = 0;
  do {
    puVar5 = (uint *)(&DAT_00733ff8)[uVar6];
    if ((puVar5 != (uint *)0x0) ||
       (((*(int *)(in_EAX + 0x88b0) != 0 &&
         (puVar5 = (uint *)(*(int *)(in_EAX + 0x88b0) + 0x58a0), puVar5 != (uint *)0x0)) &&
        (uVar6 == *puVar5)))) {
      if (((uVar6 < 0x100) && ((&DAT_00733ff8)[uVar6] != 0)) ||
         ((*(int *)(in_EAX + 0x88b0) != 0 &&
          ((puVar2 = (uint *)(*(int *)(in_EAX + 0x88b0) + 0x58a0), puVar2 != (uint *)0x0 &&
           (uVar6 == *puVar2)))))) {
        pcVar3 = (char *)(uVar6 + 0x34c + in_EAX);
      }
      else {
        pcVar3 = (char *)0x0;
      }
      if (*pcVar3 == '\x01') {
        iVar4 = 0;
        do {
          if (local_30[iVar4] == 0xffffffff) {
            local_30[iVar4] = *puVar5;
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0xc);
      }
    }
    uVar6 = uVar6 + 1;
    if (0xff < uVar6) {
      puVar5 = local_30;
      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_1 = *puVar5;
        puVar5 = puVar5 + 1;
        param_1 = param_1 + 1;
      }
      return;
    }
  } while( true );
}


// ==== 0x5a2350 Career::CreateRaceObject

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (ghidra) docs/re/canon.md */

int __thiscall Career__CreateRaceObject(uint param_1,int param_2)

{
  char cVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int local_b0c;
  int local_b00;
  int local_afc;
  int local_af8;
  int local_af4;
  undefined1 local_af0 [2788];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006855a5;
  local_c = ExceptionList;
  if (((param_1 < 0x100) && (puVar8 = (uint *)(&DAT_00733ff8)[param_1], puVar8 != (uint *)0x0)) ||
     ((*(int *)(param_2 + 0x88b0) != 0 &&
      ((puVar8 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar8 != (uint *)0x0 &&
       (param_1 == *puVar8)))))) {
    _DAT_00735ec8 = 1;
    local_4 = 0;
    if (DAT_00735ec4 == 0) {
      iVar5 = 0;
      ExceptionList = &local_c;
    }
    else {
      ExceptionList = &local_c;
      iVar5 = FUN_005a2930();
    }
    local_4 = 0xffffffff;
    if (((int)param_1 < 0) || (0xff < (int)param_1)) {
      *(undefined4 *)(iVar5 + 0x58a0) = 0xffffffff;
    }
    else if (param_1 < 0x100) {
      puVar9 = (undefined4 *)(&DAT_00733ff8)[param_1];
      puVar11 = (undefined4 *)(iVar5 + 0x58a0);
      for (iVar7 = 0x53; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    else {
      puVar9 = (undefined4 *)0x0;
      puVar11 = (undefined4 *)(iVar5 + 0x58a0);
      for (iVar7 = 0x53; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    iVar7 = 8;
    do {
      FUN_00438860();
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar7 = 0;
    if (0 < (int)puVar8[0x26]) {
      pcVar10 = (char *)((int)puVar8 + 0x7a);
      do {
        cVar1 = *pcVar10;
        sVar3 = *(short *)(pcVar10 + -2);
        cVar2 = pcVar10[1];
        iVar4 = *(int *)(iVar5 + 0x5868);
        if (iVar4 < 8) {
          *(int *)(iVar5 + 0x5868) = iVar4 + 1;
          if (((iVar4 < 0) || (iVar4 + 1 <= iVar4)) || (7 < iVar4)) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)(iVar4 * 0xb0c + 4 + iVar5);
          }
          *piVar6 = (int)sVar3;
          piVar6[1] = (int)cVar2;
          piVar6[2] = (int)cVar1;
          piVar6[3] = local_b0c;
          piVar6[4] = 0;
          piVar6[5] = 1;
          piVar6[6] = local_b00;
          piVar6[7] = local_afc;
          piVar6[8] = local_af8;
          piVar6[9] = local_af4;
          FUN_0059ffd0(piVar6 + 10,local_af0);
        }
        iVar7 = iVar7 + 1;
        pcVar10 = pcVar10 + 4;
      } while (iVar7 < (int)puVar8[0x26]);
    }
  }
  else {
    iVar5 = 0;
  }
  ExceptionList = local_c;
  return iVar5;
}


// ==== 0x5a2540 FUN_005a2540

void FUN_005a2540(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = unaff_ESI * 0xc90 + DAT_00734588;
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xc7c);
    *(int *)(in_EAX + 0x1374) = *(int *)(in_EAX + 0x1374) - iVar1;
    *(int *)(in_EAX + 0x137c) = *(int *)(in_EAX + 0x137c) + iVar1;
  }
  FUN_004f42f0("CAREER_CAR");
  FUN_004acb90();
  *(undefined2 *)(in_EAX + 0x1384) = 1;
  return;
}


// ==== 0x5a25a0 FUN_005a25a0

void __fastcall FUN_005a25a0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_005a0350();
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  uVar1 = (uint)uVar4;
  if (uVar1 < 0x20) {
    iVar2 = (&DAT_00733f78)[uVar1];
  }
  else {
    iVar2 = 0;
  }
  switch(param_1) {
  default:
    iVar2 = 0;
    break;
  case 1:
    iVar2 = *(int *)(iVar2 + 4);
    break;
  case 2:
    iVar2 = *(int *)(iVar2 + 8);
    break;
  case 3:
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  *(int *)(iVar3 + 0x1374) = *(int *)(iVar3 + 0x1374) - iVar2;
  *(int *)(iVar3 + 0x137c) = *(int *)(iVar3 + 0x137c) + iVar2;
  if (((uVar1 != 8) && (uVar1 != 5)) && (uVar1 != 0xffffffff)) {
    FUN_005a34a0();
  }
  return;
}


// ==== 0x5a2620 FUN_005a2620

void FUN_005a2620(void)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = MapCarPartIDToCareerUpgrade();
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  if ((uint)uVar3 < 0x20) {
    iVar1 = (&DAT_00733f78)[(uint)uVar3];
  }
  else {
    iVar1 = 0;
  }
  switch(*(undefined1 *)(extraout_ECX + 0x11)) {
  default:
    iVar1 = 0;
    break;
  case 1:
    iVar1 = *(int *)(iVar1 + 4);
    break;
  case 2:
    iVar1 = *(int *)(iVar1 + 8);
    break;
  case 3:
    iVar1 = *(int *)(iVar1 + 0xc);
  }
  *(int *)(iVar2 + 0x1374) = *(int *)(iVar2 + 0x1374) - iVar1;
  *(int *)(iVar2 + 0x137c) = *(int *)(iVar2 + 0x137c) + iVar1;
  FUN_005a34d0(iVar2 + 0x44c);
  return;
}


// ==== 0x5a2690 Career::GetLastWonEventTextRow

/* [canon] canon low (ghidra) docs/re/canon.md */

int Career__GetLastWonEventTextRow(undefined4 param_1)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int unaff_EDI;
  bool bVar7;
  
  uVar3 = 0;
  uVar5 = 0xffffffff;
  bVar7 = true;
  do {
    if ((((bVar7) && ((&DAT_00733ff8)[uVar3] != 0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 != (uint *)0x0 &&
          (uVar3 == *puVar4)))))) &&
       (pcVar2 = (char *)(uVar3 + 0x34c + unaff_EDI), pcVar2 != (char *)0x0)) {
      if (((0xff < uVar3) || (puVar4 = (uint *)(&DAT_00733ff8)[uVar3], puVar4 == (uint *)0x0)) &&
         ((*(int *)(unaff_EDI + 0x88b0) == 0 ||
          ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0 ||
           (uVar3 != *puVar4)))))) {
        puVar4 = (uint *)0x0;
      }
      if (((puVar4[1] != 8) && (*pcVar2 == '\x02')) && ((int)uVar5 < (int)uVar3)) {
        uVar5 = uVar3;
      }
    }
    uVar1 = uVar3 + 1;
    if ((((uVar1 < 0x100) && ((&DAT_00733ffc)[uVar3] != 0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 != (uint *)0x0 &&
          (uVar1 == *puVar4)))))) &&
       (pcVar2 = (char *)(uVar3 + 0x34d + unaff_EDI), pcVar2 != (char *)0x0)) {
      if (((0xff < uVar1) || (puVar4 = (uint *)(&DAT_00733ffc)[uVar3], puVar4 == (uint *)0x0)) &&
         ((*(int *)(unaff_EDI + 0x88b0) == 0 ||
          ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0 ||
           (uVar1 != *puVar4)))))) {
        puVar4 = (uint *)0x0;
      }
      if (((puVar4[1] != 8) && (*pcVar2 == '\x02')) && ((int)uVar5 < (int)uVar1)) {
        uVar5 = uVar1;
      }
    }
    uVar1 = uVar3 + 2;
    if ((((uVar1 < 0x100) && ((&DAT_00734000)[uVar3] != 0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 != (uint *)0x0 &&
          (uVar1 == *puVar4)))))) &&
       (pcVar2 = (char *)(uVar3 + 0x34e + unaff_EDI), pcVar2 != (char *)0x0)) {
      if (((0xff < uVar1) || (puVar4 = (uint *)(&DAT_00734000)[uVar3], puVar4 == (uint *)0x0)) &&
         ((*(int *)(unaff_EDI + 0x88b0) == 0 ||
          ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0 ||
           (uVar1 != *puVar4)))))) {
        puVar4 = (uint *)0x0;
      }
      if (((puVar4[1] != 8) && (*pcVar2 == '\x02')) && ((int)uVar5 < (int)uVar1)) {
        uVar5 = uVar1;
      }
    }
    uVar1 = uVar3 + 3;
    if ((((uVar1 < 0x100) && ((&DAT_00734004)[uVar3] != 0)) ||
        ((*(int *)(unaff_EDI + 0x88b0) != 0 &&
         ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 != (uint *)0x0 &&
          (uVar1 == *puVar4)))))) &&
       (pcVar2 = (char *)(uVar3 + 0x34f + unaff_EDI), pcVar2 != (char *)0x0)) {
      if (((0xff < uVar1) || (puVar4 = (uint *)(&DAT_00734004)[uVar3], puVar4 == (uint *)0x0)) &&
         ((*(int *)(unaff_EDI + 0x88b0) == 0 ||
          ((puVar4 = (uint *)(*(int *)(unaff_EDI + 0x88b0) + 0x58a0), puVar4 == (uint *)0x0 ||
           (uVar1 != *puVar4)))))) {
        puVar4 = (uint *)0x0;
      }
      if (((puVar4[1] != 8) && (*pcVar2 == '\x02')) && ((int)uVar5 < (int)uVar1)) {
        uVar5 = uVar1;
      }
    }
    uVar3 = uVar3 + 4;
    bVar7 = uVar3 < 0x100;
  } while ((int)uVar3 < 0x100);
  if (uVar5 == 0x71) {
    uVar5 = 0x70;
  }
  else if (uVar5 == 0xffffffff) {
    return 0;
  }
  iVar6 = uVar5 * 0x2c + DAT_00734414;
  switch(param_1) {
  case 0:
    return iVar6 + 4;
  case 1:
    return iVar6 + 0x22;
  case 2:
    return iVar6 + 0xe;
  case 3:
    return iVar6 + 0x18;
  default:
    return 0;
  }
}


// ==== 0x5a28f0 FUN_005a28f0

undefined4 FUN_005a28f0(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(in_EAX + 0xb08)) {
    piVar2 = (int *)(in_EAX + 0x2c);
    do {
      if (*piVar2 == unaff_EDI) {
        return *(undefined4 *)(iVar1 * 0x15c + in_EAX + 0x28);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x57;
    } while (iVar1 < *(int *)(in_EAX + 0xb08));
  }
  return uRam00000000;
}


// ==== 0x5a2930 FUN_005a2930

void FUN_005a2930(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = &PTR_FUN_006b7f7c;
  puVar2 = unaff_EDI + 0xb;
  iVar1 = 8;
  do {
    puVar2[-6] = 0;
    CallNTimes(puVar2,0x15c,8,FUN_00438860);
    puVar2 = puVar2 + 0x2c3;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  eh_vector_constructor_iterator(unaff_EDI + 0x161b,0xc,4,FUN_004b3990,FUN_004b39a0);
  unaff_EDI[0x161a] = 0;
  unaff_EDI[0x1619] = unaff_EDI + 1;
  unaff_EDI[0x1627] = 0;
  *(undefined1 *)(unaff_EDI + 0x167b) = 0;
  unaff_EDI[0x1628] = 0xffffffff;
  return;
}


// ==== 0x5a29b0 FUN_005a29b0

undefined4 FUN_005a29b0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x58a0);
}


// ==== 0x5a29c0 FUN_005a29c0

int __fastcall FUN_005a29c0(int *param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *local_c;
  int local_8;
  
  iVar5 = 0;
  if ((in_EAX < 0) || (param_1[0x1627] <= in_EAX)) {
    local_c = (int *)0x0;
  }
  else {
    local_c = param_1 + in_EAX * 3 + 0x161b;
  }
  local_8 = 0;
  if (local_c != (int *)0x0) {
    iVar1 = param_1[0x161a];
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((((-1 < iVar2) && (iVar2 < iVar1)) && (iVar2 < 8)) &&
           ((param_1 != (int *)0xfffffffc && ((param_1[6] == 3 || (param_1[6] == 4)))))) {
          iVar5 = param_1[0x2c3];
          iVar3 = 0;
          if (0 < iVar5) {
            piVar4 = param_1 + 0xc;
            do {
              if (*piVar4 == local_c[1]) {
                piVar4 = param_1 + iVar3 * 0x57 + 0xb;
                goto LAB_005a2a68;
              }
              iVar3 = iVar3 + 1;
              piVar4 = piVar4 + 0x57;
            } while (iVar3 < iVar5);
          }
          piVar4 = (int *)0x0;
LAB_005a2a68:
          iVar5 = *piVar4;
          if (iVar5 == 0) {
            iVar5 = 1;
          }
          iVar5 = local_8 + *(int *)(&DAT_006ee3c4 + iVar5 * 4);
          local_8 = iVar5;
        }
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 0x2c3;
      } while (iVar2 < iVar1);
    }
  }
  return iVar5;
}


// ==== 0x5a2ab0 FUN_005a2ab0

undefined4 FUN_005a2ab0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_44;
  undefined4 auStack_38 [14];
  
  local_44 = *(int *)(param_1 + 0x589c);
  iVar5 = 0;
  if (0 < local_44) {
    puVar4 = auStack_38;
    param_1 = param_1 + 0x586c;
    do {
      puVar4 = puVar4 + 3;
      if ((iVar5 < 0) || (iVar2 = param_1, local_44 <= iVar5)) {
        iVar2 = 0;
      }
      *puVar4 = *(undefined4 *)(iVar2 + 4);
      puVar4[-1] = iVar5;
      uVar3 = FUN_005a29c0();
      puVar4[1] = uVar3;
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 0xc;
    } while (iVar5 < local_44);
    if (0 < local_44) {
      iVar5 = local_44 + -1;
      do {
        if (0 < iVar5) {
          puVar4 = auStack_38 + 2;
          param_1 = iVar5;
          do {
            if ((int)puVar4[2] < (int)puVar4[5]) {
              uVar3 = *puVar4;
              uVar1 = puVar4[1];
              auStack_38[1] = puVar4[2];
              *puVar4 = puVar4[3];
              puVar4[3] = uVar3;
              puVar4[1] = puVar4[4];
              puVar4[4] = uVar1;
              puVar4[2] = puVar4[5];
              puVar4[5] = auStack_38[1];
            }
            puVar4 = puVar4 + 3;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        local_44 = local_44 + -1;
      } while (local_44 != 0);
    }
  }
  return auStack_38[param_2 * 3];
}


// ==== 0x5a2ba0 FUN_005a2ba0

uint FUN_005a2ba0(void)

{
  int *in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = (**(code **)(*in_EAX + 4))();
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  iVar3 = in_EAX[0x1619];
  iVar2 = 0;
  if (0 < *(int *)(iVar3 + 0xb08)) {
    piVar4 = (int *)(iVar3 + 0x2c);
    do {
      if (*piVar4 == 0) {
        iVar3 = iVar2 * 0x15c + iVar3 + 0x28;
        return CONCAT31((int3)((uint)iVar3 >> 8),*(int *)(iVar3 + 8) == 1);
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 0x57;
    } while (iVar2 < *(int *)(iVar3 + 0xb08));
  }
  return (uint)(iRam00000008 == 1);
}


// ==== 0x5a2c00 FUN_005a2c00

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


// ==== 0x5a2c40 FUN_005a2c40

void __fastcall FUN_005a2c40(int *param_1)

{
  (**(code **)(*param_1 + 0x24))();
  (**(code **)(*param_1 + 0x28))();
  return;
}


// ==== 0x5a2c60 FUN_005a2c60

void __fastcall FUN_005a2c60(int param_1)

{
  char cVar1;
  
  cVar1 = Race__DidPlayerWin(param_1,0);
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x59ec) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x5864) + 0x14) = 2;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x5864) + 0x14) = 2;
  return;
}


// ==== 0x5a2ca0 FUN_005a2ca0

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


// ==== 0x5a2d70 FUN_005a2d70

void FUN_005a2d70(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  int local_8;
  
  iVar4 = *(int *)(in_EAX + 0x589c);
  iVar1 = *(int *)(in_EAX + 0x5864);
  iVar6 = 0;
  local_8 = 0;
  local_14 = 1;
  if (0 < iVar4) {
    iVar8 = in_EAX + 0x586c;
    do {
      if ((iVar6 < 0) || (iVar7 = iVar8, iVar4 <= iVar6)) {
        iVar7 = 0;
      }
      if (*(int *)(iVar7 + 8) == 1) {
        iVar2 = 0;
        if (0 < *(int *)(iVar1 + 0xb08)) {
          piVar3 = (int *)(iVar1 + 0x2c);
          do {
            if (*piVar3 == *(int *)(iVar7 + 4)) {
              piVar3 = (int *)(iVar2 * 0x15c + iVar1 + 0x28);
              goto LAB_005a2df5;
            }
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 0x57;
          } while (iVar2 < *(int *)(iVar1 + 0xb08));
        }
        piVar3 = (int *)0x0;
LAB_005a2df5:
        if (local_14 < *piVar3) {
          local_14 = *piVar3;
          local_8 = iVar7;
        }
      }
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 0xc;
    } while (iVar6 < iVar4);
    if (local_8 != 0) {
      *(undefined4 *)(local_8 + 8) = 2;
      iVar4 = 0;
      if (0 < DAT_0078a41c) {
        pcVar5 = (char *)(DAT_0078a418 + 1);
        while (*(int *)(local_8 + 4) != (int)*pcVar5) {
          iVar4 = iVar4 + 1;
          pcVar5 = pcVar5 + 0x750;
          if (DAT_0078a41c <= iVar4) {
            return;
          }
        }
        pcVar5 = (char *)(iVar4 * 0x750 + DAT_0078a418);
        if ((pcVar5 != (char *)0x0) && (*pcVar5 < '\x01')) {
          *pcVar5 = (char)local_14;
          if (*(int *)(pcVar5 + 4) == 1) {
            DAT_0078a320 = DAT_0078a320 + -1;
          }
          else if (*(int *)(pcVar5 + 4) == 2) {
            DAT_0078a324 = DAT_0078a324 + -1;
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== 0x5a2eb0 FUN_005a2eb0

void __fastcall FUN_005a2eb0(int *param_1)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 0x1c))();
  if (param_1[0x1629] == 7) {
    FUN_005a2d70();
  }
  if (param_1[0x1619] != 0) {
    piVar1 = (int *)(param_1[0x1619] + 0xb0c);
    param_1[0x1619] = -(uint)(piVar1 < param_1 + param_1[0x161a] * 0x2c3 + 1) & (uint)piVar1;
    return;
  }
  param_1[0x1619] = 0;
  return;
}


// ==== 0x5a2f00 FUN_005a2f00

void __fastcall FUN_005a2f00(int *param_1)

{
  (**(code **)(*param_1 + 0x1c))();
                    /* WARNING: Could not recover jumptable at 0x005a2f0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x20))();
  return;
}


// ==== 0x5a2f10 Race::DidPlayerWin

/* [canon] canon high (ghidra) docs/re/canon.md */

bool Race__DidPlayerWin(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 0x59ec) != '\0') {
    return true;
  }
  iVar5 = 0;
  iVar1 = *(int *)(param_1 + 0x5868);
  if (param_2 == '\0') {
    if (0 < iVar1) {
      iVar6 = param_1 + 4;
      do {
        if (((iVar5 < 0) || (iVar1 <= iVar5)) || (iVar3 = iVar6, 7 < iVar5)) {
          iVar3 = 0;
        }
        if ((*(int *)(iVar3 + 0x14) != 4) && (*(int *)(iVar3 + 0x14) != 3)) {
          return false;
        }
        iVar2 = 0;
        if (0 < *(int *)(iVar3 + 0xb08)) {
          piVar4 = (int *)(iVar3 + 0x2c);
          do {
            if (*piVar4 == 0) {
              iVar3 = iVar2 * 0x15c + iVar3 + 0x28;
              goto LAB_005a2ff8;
            }
            iVar2 = iVar2 + 1;
            piVar4 = piVar4 + 0x57;
          } while (iVar2 < *(int *)(iVar3 + 0xb08));
        }
        iVar3 = 0;
LAB_005a2ff8:
        if (*(int *)(iVar3 + 8) != 1) {
          return false;
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0xb0c;
      } while (iVar5 < iVar1);
    }
  }
  else if (0 < iVar1) {
    iVar6 = param_1 + 4;
    do {
      if (((iVar5 < 0) || (iVar1 <= iVar5)) || (iVar3 = iVar6, 7 < iVar5)) {
        iVar3 = 0;
      }
      if (*(int *)(iVar3 + 0x14) != 4) {
        return false;
      }
      iVar2 = 0;
      if (0 < *(int *)(iVar3 + 0xb08)) {
        piVar4 = (int *)(iVar3 + 0x2c);
        do {
          if (*piVar4 == 0) {
            iVar3 = iVar2 * 0x15c + iVar3 + 0x28;
            goto LAB_005a2f84;
          }
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 0x57;
        } while (iVar2 < *(int *)(iVar3 + 0xb08));
      }
      iVar3 = 0;
LAB_005a2f84:
      if (*(int *)(iVar3 + 8) != 1) {
        return false;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0xb0c;
    } while (iVar5 < iVar1);
  }
  if (*(int *)(param_1 + 0x58a4) == 1) {
    iVar1 = FUN_005a2ab0(param_1,1);
    return (bool)('\x01' - (iVar1 != 0));
  }
  if (*(int *)(param_1 + 0x58a8) == 4) {
    iVar1 = *(int *)(param_1 + 0x5864);
    iVar5 = 0;
    if (0 < *(int *)(iVar1 + 0xb08)) {
      piVar4 = (int *)(iVar1 + 0x2c);
      do {
        if (*piVar4 == DAT_0078a410) {
          iVar1 = iVar5 * 0x15c + iVar1 + 0x28;
          goto LAB_005a3081;
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0x57;
      } while (iVar5 < *(int *)(iVar1 + 0xb08));
    }
    iVar1 = 0;
LAB_005a3081:
    iVar1 = *(int *)(iVar1 + 0x10);
    if ((iVar1 != 0) && (iVar1 != 0x7fffffff)) {
      return iVar1 < DAT_0078a310;
    }
  }
  else {
    if (*(int *)(param_1 + 0x58a4) == 7) {
      iVar5 = iVar1 + -1;
      if (((iVar5 < 0) || (iVar1 <= iVar5)) || (7 < iVar5)) {
        param_1 = 0;
      }
      else {
        param_1 = iVar5 * 0xb0c + 4 + param_1;
      }
      iVar1 = 0;
      piVar4 = (int *)(param_1 + 0x28);
      if (0 < *(int *)(param_1 + 0xb08)) {
        do {
          if (*piVar4 == 1) {
            return ((int *)(param_1 + 0x28))[iVar1 * 0x57 + 1] == 0;
          }
          iVar1 = iVar1 + 1;
          piVar4 = piVar4 + 0x57;
        } while (iVar1 < *(int *)(param_1 + 0xb08));
      }
      return iRam00000004 == 0;
    }
    iVar5 = 0;
    if (0 < iVar1) {
      param_1 = param_1 + 4;
      do {
        if (((iVar5 < 0) || (iVar1 <= iVar5)) || (iVar6 = param_1, 7 < iVar5)) {
          iVar6 = 0;
        }
        iVar3 = 0;
        piVar4 = (int *)(iVar6 + 0x28);
        if (*(int *)(iVar6 + 0xb08) < 1) {
          return false;
        }
        while (*piVar4 != 1) {
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 0x57;
          if (*(int *)(iVar6 + 0xb08) <= iVar3) {
            return false;
          }
        }
        piVar4 = (int *)(iVar6 + 0x28) + iVar3 * 0x57;
        if (piVar4 == (int *)0x0) {
          return false;
        }
        if (piVar4[1] != 0) {
          return false;
        }
        iVar5 = iVar5 + 1;
        param_1 = param_1 + 0xb0c;
      } while (iVar5 < iVar1);
    }
  }
  return true;
}


// ==== 0x5a31a0 FUN_005a31a0

void __fastcall FUN_005a31a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x5864);
  if (*(int *)(iVar1 + 0x14) == 3) {
    *(undefined4 *)(iVar1 + 0x14) = 4;
    FUN_0059ffd0(iVar1 + 0x28,&DAT_00777cd0);
    iVar1 = *(int *)(param_1 + 0x5864);
    iVar4 = iVar1 + 0x28;
    if (*(int *)(param_1 + 0x58a8) == 3) {
      puVar5 = (undefined4 *)(*(int *)(iVar1 + 0xb08) * 0x15c + iVar4);
      uVar2 = RaceManager__GetRacerRank(100);
      *puVar5 = uVar2;
      puVar5[1] = 100;
      iVar3 = *(int *)(iVar1 + 0xb08) + 1;
      *(int *)(iVar1 + 0xb08) = iVar3;
      puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
      uVar2 = RaceManager__GetRacerRank(0x65);
      *puVar5 = uVar2;
      puVar5[1] = 0x65;
      iVar3 = *(int *)(iVar1 + 0xb08) + 1;
      *(int *)(iVar1 + 0xb08) = iVar3;
      puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
      uVar2 = RaceManager__GetRacerRank(0x66);
      *puVar5 = uVar2;
      puVar5[1] = 0x66;
      *(int *)(iVar1 + 0xb08) = *(int *)(iVar1 + 0xb08) + 1;
    }
  }
  return;
}


// ==== 0x5a3260 FUN_005a3260

void __fastcall FUN_005a3260(int param_1)

{
  char cVar1;
  
  cVar1 = Race__DidPlayerWin(param_1,1);
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x59ec) = 1;
  }
  return;
}


// ==== 0x5a3280 FUN_005a3280

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
    uVar2 = RaceManager__GetRacerRank(100);
    *puVar5 = uVar2;
    puVar5[1] = 100;
    iVar3 = *(int *)(iVar1 + 0xb08) + 1;
    *(int *)(iVar1 + 0xb08) = iVar3;
    puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
    uVar2 = RaceManager__GetRacerRank(0x65);
    *puVar5 = uVar2;
    puVar5[1] = 0x65;
    iVar3 = *(int *)(iVar1 + 0xb08) + 1;
    *(int *)(iVar1 + 0xb08) = iVar3;
    puVar5 = (undefined4 *)(iVar3 * 0x15c + iVar4);
    uVar2 = RaceManager__GetRacerRank(0x66);
    *puVar5 = uVar2;
    puVar5[1] = 0x66;
    *(int *)(iVar1 + 0xb08) = *(int *)(iVar1 + 0xb08) + 1;
  }
  return;
}


// ==== 0x5a3340 FUN_005a3340

uint __fastcall FUN_005a3340(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5868);
  uVar2 = 0;
  if (0 < iVar1) {
    param_1 = param_1 + 4;
    do {
      if ((((int)uVar2 < 0) || (iVar1 <= (int)uVar2)) || (iVar3 = param_1, 7 < (int)uVar2)) {
        iVar3 = 0;
      }
      if (*(int *)(iVar3 + 0x14) < 3) {
        return uVar2 & 0xffffff00;
      }
      uVar2 = uVar2 + 1;
      param_1 = param_1 + 0xb0c;
    } while ((int)uVar2 < iVar1);
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== 0x5a3380 FUN_005a3380

void FUN_005a3380(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int unaff_EDI;
  undefined4 local_b00;
  undefined4 local_af4;
  undefined4 local_af0;
  undefined4 local_aec;
  undefined4 local_ae8;
  undefined1 local_ae4 [2788];
  
  iVar5 = RaceOptions_Get();
  iVar7 = 8;
  do {
    FUN_00438860();
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0;
  if (0 < *(int *)(iVar5 + 0x20)) {
    puVar8 = (undefined4 *)(iVar5 + 0x28);
    do {
      uVar1 = puVar8[-1];
      uVar2 = *puVar8;
      uVar3 = puVar8[1];
      iVar4 = *(int *)(unaff_EDI + 0x5868);
      if (iVar4 < 8) {
        *(int *)(unaff_EDI + 0x5868) = iVar4 + 1;
        if (((iVar4 < 0) || (iVar4 + 1 <= iVar4)) || (7 < iVar4)) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          puVar6 = (undefined4 *)(iVar4 * 0xb0c + 4 + unaff_EDI);
        }
        *puVar6 = uVar1;
        puVar6[1] = uVar2;
        puVar6[2] = uVar3;
        puVar6[3] = local_b00;
        puVar6[4] = 0;
        puVar6[5] = 1;
        puVar6[6] = local_af4;
        puVar6[7] = local_af0;
        puVar6[8] = local_aec;
        puVar6[9] = local_ae8;
        FUN_0059ffd0(puVar6 + 10,local_ae4);
      }
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 3;
    } while (iVar7 < *(int *)(iVar5 + 0x20));
  }
  *(undefined4 *)(unaff_EDI + 0x58a0) = 0xfffffffe;
  *(undefined4 *)(unaff_EDI + 0x58a4) = 1;
  return;
}


// ==== 0x5a34a0 FUN_005a34a0

void __fastcall FUN_005a34a0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if ((-1 < in_EAX) && (in_EAX < 0x19)) {
    param_1 = in_EAX * 0x90 + 4 + param_1;
    iVar2 = 0;
    while ((iVar1 = *(int *)(param_1 + iVar2 * 4), iVar1 != 0 && (iVar1 != unaff_ESI))) {
      iVar2 = iVar2 + 1;
      if (0x23 < iVar2) {
        return;
      }
    }
    *(int *)(param_1 + iVar2 * 4) = unaff_ESI;
  }
  return;
}


// ==== 0x5a34d0 FUN_005a34d0

void FUN_005a34d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int extraout_ECX;
  int iVar3;
  
  uVar1 = MapCarPartIDToCareerUpgrade();
  if (uVar1 != 0xffffffff) {
    switch(uVar1) {
    case 3:
      uVar2 = CarPart__GetNameAttribute();
      break;
    default:
      uVar2 = *(uint *)(extraout_ECX + 8);
      break;
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xf:
      uVar2 = (uint)CONCAT11(*(undefined1 *)(extraout_ECX + 0x11),
                             *(undefined1 *)(extraout_ECX + 0x12)) << 8 | uVar1;
    }
    if ((-1 < (int)uVar1) && ((int)uVar1 < 0x19)) {
      param_1 = uVar1 * 0x90 + 4 + param_1;
      iVar3 = 0;
      while ((uVar1 = *(uint *)(param_1 + iVar3 * 4), uVar1 != 0 && (uVar1 != uVar2))) {
        iVar3 = iVar3 + 1;
        if (0x23 < iVar3) {
          return;
        }
      }
      *(uint *)(param_1 + iVar3 * 4) = uVar2;
    }
  }
  return;
}


// ==== 0x5a3570 PartStore::HasPart

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 __thiscall PartStore__HasPart(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  
  if (DAT_00735ec1 != '\0') {
    return 1;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = MapCarPartIDToCareerUpgrade();
  if (iVar1 == -1) {
    return 0;
  }
  if (*(char *)(extraout_ECX + 0x11) == '\0') {
    return 1;
  }
  switch(iVar1) {
  case 3:
    CarPart__GetNameAttribute();
    uVar2 = PartStore__Has(param_2);
    return uVar2;
  default:
    uVar2 = PartStore__Has(param_2);
    return uVar2;
  case 5:
  case 6:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xf:
    uVar2 = PartStore__Has(param_2);
    return uVar2;
  }
}


// ==== 0x5a3630 PartStore::Has

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 __fastcall PartStore__Has(undefined4 param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_00735ec1 != '\0') {
    return 1;
  }
  if ((-1 < in_EAX) && (in_EAX < 0x19)) {
    iVar1 = 0;
    do {
      if (*(int *)(in_EAX * 0x90 + 4 + param_3 + iVar1 * 4) == param_2) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x24);
  }
  return 0;
}


// ==== 0x5a3670 FUN_005a3670

undefined4 FUN_005a3670(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined8 uVar3;
  
  uVar3 = FUN_005a0350();
  iVar1 = (int)uVar3;
  if (((iVar1 != 8) && (iVar1 != 5)) && (iVar1 != -1)) {
    if ((int)((ulonglong)uVar3 >> 0x20) == 0) {
      return 1;
    }
    uVar2 = PartStore__Has(extraout_ECX);
    return uVar2;
  }
  return 0;
}


// ==== 0x5a36a0 CharacterRoster::Loader

/* [canon] assets high (Hopper sub_5a36a0 + Ghidra make FUN_005a36a0: H+G agree) docs/re/assets.md
    */

undefined4 CharacterRoster__Loader(int *param_1)

{
  if (*param_1 == 0x34a03) {
    DAT_00734410 = param_1 + 2;
    DAT_00734414 = param_1 + 0xc2;
    return 1;
  }
  return 0;
}


// ==== 0x5a36d0 CharacterRoster::Unloader

/* [canon] assets high (Hopper sub_5a36d0 + Ghidra make FUN_005a36d0: H+G agree) docs/re/assets.md
    */

bool CharacterRoster__Unloader(int *param_1)

{
  if (*param_1 == 0x34a03) {
    DAT_00734410 = 0;
    DAT_00734414 = 0;
  }
  return *param_1 == 0x34a03;
}


// ==== 0x5a36f0 FUN_005a36f0

undefined4 FUN_005a36f0(void)

{
  int in_EAX;
  
  if (((*(uint *)(in_EAX + 0x18) & 0xfffffe) == 0) && ((*(uint *)(in_EAX + 0x14) & 0xc0000000) == 0)
     ) {
    return 0;
  }
  return 1;
}


// ==== 0x5a3710 FUN_005a3710

undefined4 FUN_005a3710(void)

{
  int in_EAX;
  
  if (((*(uint *)(in_EAX + 8) & 0x77c7e38f) == 0) && ((*(uint *)(in_EAX + 0xc) & 0xfffffc7f) == 0))
  {
    return 0;
  }
  return 1;
}


// ==== 0x5a3730 FUN_005a3730

undefined4 FUN_005a3730(void)

{
  int in_EAX;
  
  if (((*(uint *)(in_EAX + 8) & 0x88381c70) == 0) && ((*(uint *)(in_EAX + 0xc) & 0x380) == 0)) {
    return 0;
  }
  return 1;
}


// ==== 0x5a3750 UnlockTeller::GetVinylUnlockBits

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

int UnlockTeller__GetVinylUnlockBits(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_007373a8)[iVar1 * 2] == in_EAX) {
      return 1 << ((&DAT_007373ad)[iVar1 * 8] & 0x1f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x55);
  return 0;
}


// ==== 0x5a3780 UnlockTeller::SetSingleVinylNewlyStyleUnlocked

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void UnlockTeller__SetSingleVinylNewlyStyleUnlocked(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int unaff_ESI;
  int unaff_EDI;
  
  bVar2 = false;
  pcVar5 = &DAT_007373ac;
  do {
    if (0x737653 < (int)pcVar5) {
      return;
    }
    if (*(int *)(pcVar5 + -4) == unaff_EDI) {
      cVar1 = *pcVar5;
      if (cVar1 == '\0') {
        bVar2 = true;
        iVar3 = 0;
        do {
          if ((&DAT_007373a8)[iVar3 * 2] == unaff_EDI) {
            *(uint *)(unaff_ESI + 0x10) =
                 *(uint *)(unaff_ESI + 0x10) | 1 << ((&DAT_007373ad)[iVar3 * 8] & 0x1f);
            goto LAB_005a3834;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x55);
        *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 0x10);
      }
      else if (cVar1 == '\x01') {
        iVar3 = 0;
        do {
          bVar2 = true;
          if ((&DAT_007373a8)[iVar3 * 2] == unaff_EDI) {
            *(uint *)(unaff_ESI + 0x14) =
                 *(uint *)(unaff_ESI + 0x14) | 1 << ((&DAT_007373ad)[iVar3 * 8] & 0x1f);
            goto LAB_005a3834;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x55);
        *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x14);
      }
      else if (cVar1 == '\x02') {
        bVar2 = true;
        uVar4 = UnlockTeller__GetVinylUnlockBits(unaff_ESI);
        *(uint *)(unaff_ESI + 0x18) = *(uint *)(unaff_ESI + 0x18) | uVar4;
      }
    }
LAB_005a3834:
    pcVar5 = pcVar5 + 8;
    if (bVar2) {
      return;
    }
  } while( true );
}


// ==== 0x5a3850 UnlockTeller::SetVinylGroupNewlyStyleUnlocked

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void UnlockTeller__SetVinylGroupNewlyStyleUnlocked(byte param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  char cVar5;
  int unaff_ESI;
  int unaff_EDI;
  
  cVar5 = '\0';
  puVar4 = &DAT_006b8150;
  uVar2 = 0x54;
  iVar3 = -1;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  if (unaff_ESI != iVar3) {
    puVar4 = &DAT_006b8148;
    iVar3 = -1;
    uVar2 = 0x54;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = puVar4 + 1;
      uVar2 = (uint)*pbVar1;
      puVar4 = puVar4 + 1;
    } while (*pbVar1 != 0);
    if (unaff_ESI != iVar3) {
      puVar4 = &DAT_006b8140;
      iVar3 = -1;
      uVar2 = 0x54;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = puVar4 + 1;
        uVar2 = (uint)*pbVar1;
        puVar4 = puVar4 + 1;
      } while (*pbVar1 != 0);
      if (unaff_ESI != iVar3) {
        iVar3 = FUN_00567c70();
        if (((unaff_ESI == iVar3) || (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) ||
           (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
          cVar5 = '\x01';
        }
        else {
          iVar3 = FUN_00567c70();
          if (((unaff_ESI == iVar3) || (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) ||
             (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
            cVar5 = '\x02';
          }
          else {
            iVar3 = FUN_00567c70();
            if ((unaff_ESI == iVar3) || (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
              cVar5 = '\x03';
            }
            else {
              iVar3 = FUN_00567c70();
              if ((unaff_ESI == iVar3) ||
                 ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                  (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                cVar5 = '\x04';
              }
              else {
                iVar3 = FUN_00567c70();
                if ((unaff_ESI == iVar3) ||
                   ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                    (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                  cVar5 = '\x05';
                }
                else {
                  iVar3 = FUN_00567c70();
                  if ((unaff_ESI == iVar3) ||
                     ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                      (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                    cVar5 = '\x06';
                  }
                  else {
                    iVar3 = FUN_00567c70();
                    if ((unaff_ESI == iVar3) ||
                       ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                        (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                      cVar5 = '\a';
                    }
                    else {
                      iVar3 = FUN_00567c70();
                      if ((unaff_ESI == iVar3) ||
                         ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                          (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                        cVar5 = '\b';
                      }
                      else {
                        iVar3 = FUN_00567c70();
                        if ((unaff_ESI == iVar3) ||
                           ((iVar3 = FUN_00567c70(), unaff_ESI == iVar3 ||
                            (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)))) {
                          cVar5 = '\t';
                        }
                        else {
                          iVar3 = FUN_00567c70();
                          if (unaff_ESI != iVar3) {
                            iVar3 = FUN_00567c70();
                            if (((unaff_ESI == iVar3) ||
                                (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) ||
                               (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
                              cVar5 = '\v';
                            }
                            else {
                              iVar3 = FUN_00567c70();
                              if (((unaff_ESI == iVar3) ||
                                  (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) ||
                                 (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
                                cVar5 = '\f';
                              }
                              else {
                                iVar3 = FUN_00567c70();
                                if (((unaff_ESI == iVar3) ||
                                    (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) ||
                                   (iVar3 = FUN_00567c70(), unaff_ESI == iVar3)) {
                                  cVar5 = '\r';
                                }
                                else {
                                  iVar3 = FUN_00567c70();
                                  if (((unaff_ESI != iVar3) &&
                                      (iVar3 = FUN_00567c70(), unaff_ESI != iVar3)) &&
                                     (iVar3 = FUN_00567c70(), unaff_ESI != iVar3))
                                  goto LAB_005a3aab;
                                  cVar5 = '\x0e';
                                }
                              }
                            }
                            *(uint *)(unaff_EDI + 0xc) =
                                 *(uint *)(unaff_EDI + 0xc) |
                                 1 << ((cVar5 + -0xb) * '\x03' + param_1 & 0x1f);
                            return;
                          }
                          cVar5 = '\n';
                          if (1 < param_1) {
                            return;
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
        goto LAB_005a3aab;
      }
    }
  }
  cVar5 = '\0';
LAB_005a3aab:
  *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 1 << (cVar5 * '\x03' + param_1 & 0x1f);
  return;
}


// ==== 0x5a3c00 FUN_005a3c00

uint FUN_005a3c00(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined3 uVar4;
  byte *pbVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *local_8;
  uint local_4;
  
  local_4 = 0;
  local_8 = DAT_00734588;
  while( true ) {
    iVar3 = -1;
    bVar2 = *local_8;
    pbVar5 = local_8;
    while (bVar2 != 0) {
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    puVar7 = &DAT_006c3454;
    uVar6 = 0x5f;
    iVar9 = iVar3;
    do {
      iVar9 = iVar9 * 0x21 + uVar6;
      pbVar5 = puVar7 + 1;
      uVar6 = (uint)*pbVar5;
      puVar7 = puVar7 + 1;
    } while (*pbVar5 != 0);
    puVar7 = &DAT_006c344c;
    uVar6 = 0x5f;
    iVar8 = iVar3;
    do {
      iVar8 = iVar8 * 0x21 + uVar6;
      pbVar5 = puVar7 + 1;
      uVar6 = (uint)*pbVar5;
      puVar7 = puVar7 + 1;
    } while (*pbVar5 != 0);
    puVar7 = &DAT_006c3444;
    uVar6 = 0x5f;
    iVar11 = iVar3;
    do {
      iVar11 = iVar11 * 0x21 + uVar6;
      pbVar5 = puVar7 + 1;
      uVar6 = (uint)*pbVar5;
      puVar7 = puVar7 + 1;
    } while (*pbVar5 != 0);
    puVar7 = &DAT_006c343c;
    uVar6 = 0x5f;
    iVar10 = iVar3;
    do {
      iVar10 = iVar10 * 0x21 + uVar6;
      pbVar5 = puVar7 + 1;
      uVar6 = (uint)*pbVar5;
      puVar7 = puVar7 + 1;
    } while (*pbVar5 != 0);
    puVar7 = &DAT_006c3434;
    uVar6 = 0x5f;
    do {
      iVar3 = iVar3 * 0x21 + uVar6;
      pbVar5 = puVar7 + 1;
      uVar6 = (uint)*pbVar5;
      puVar7 = puVar7 + 1;
    } while (*pbVar5 != 0);
    uVar4 = (undefined3)((uint)iVar3 >> 8);
    if (param_1 == iVar9) {
      return CONCAT31(uVar4,1);
    }
    if (param_1 == iVar8) {
      return CONCAT31(uVar4,2);
    }
    if (param_1 == iVar11) break;
    if (param_1 == iVar10) {
      return CONCAT31(uVar4,4);
    }
    if (param_1 == iVar3) {
      return CONCAT31(uVar4,5);
    }
    local_4 = local_4 + 1;
    local_8 = local_8 + 0xc90;
    if (0x22 < (int)local_4) {
      return local_4 & 0xffffff00;
    }
  }
  return CONCAT31(uVar4,3);
}


// ==== 0x5a3d50 FUN_005a3d50

uint FUN_005a3d50(void)

{
  byte *pbVar1;
  char cVar2;
  uint in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int unaff_EDI;
  
  uVar3 = FUN_005a3c00();
  cVar2 = (char)uVar3;
  if (cVar2 != '\0') {
    uVar3 = 0;
    if (cVar2 == '\x01') {
      pcVar6 = "ALLCARS_BODY_1";
      uVar3 = 0xffffffff;
      uVar4 = 0x41;
      do {
        uVar3 = uVar3 * 0x21 + uVar4;
        pbVar1 = (byte *)(pcVar6 + 1);
        uVar4 = (uint)*pbVar1;
        pcVar6 = pcVar6 + 1;
        in_EAX = uVar3;
      } while (*pbVar1 != 0);
    }
    else if ((((cVar2 == '\x02') || (cVar2 == '\x03')) || (cVar2 == '\x04')) ||
            (in_EAX = uVar3, cVar2 == '\x05')) {
      uVar3 = FUN_00567c70();
      in_EAX = uVar3;
    }
  }
  pcVar6 = &DAT_007373ac;
  do {
    if (*(uint *)(pcVar6 + -4) == in_EAX) {
      cVar2 = *pcVar6;
      uVar3 = CONCAT31((int3)(uVar3 >> 8),cVar2);
      if (cVar2 == '\0') {
        iVar5 = 0;
        do {
          if ((&DAT_007373a8)[iVar5 * 2] == in_EAX) {
            return (uint)((*(uint *)(unaff_EDI + 0x10) & 1 << ((&DAT_007373ad)[iVar5 * 8] & 0x1f))
                         != 0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x55);
        return 0;
      }
      if (cVar2 == '\x01') {
        iVar5 = 0;
        do {
          if ((&DAT_007373a8)[iVar5 * 2] == in_EAX) {
            return (uint)((*(uint *)(unaff_EDI + 0x14) & 1 << ((&DAT_007373ad)[iVar5 * 8] & 0x1f))
                         != 0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x55);
        return 0;
      }
      if (cVar2 == '\x02') {
        iVar5 = 0;
        do {
          if ((&DAT_007373a8)[iVar5 * 2] == in_EAX) {
            return (uint)((*(uint *)(unaff_EDI + 0x18) & 1 << ((&DAT_007373ad)[iVar5 * 8] & 0x1f))
                         != 0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x55);
        return 0;
      }
    }
    pcVar6 = pcVar6 + 8;
    if (0x737653 < (int)pcVar6) {
      return uVar3 & 0xffffff00;
    }
  } while( true );
}


// ==== 0x5a3eb0 FUN_005a3eb0

uint __fastcall FUN_005a3eb0(undefined4 param_1,char param_2)

{
  byte bVar1;
  uint in_EAX;
  int unaff_ESI;
  
  bVar1 = (byte)in_EAX;
  if (bVar1 == 10) {
    if (param_2 == '\x03') {
      return in_EAX & 0xffffff00;
    }
  }
  else if (10 < bVar1) {
    return (uint)((*(uint *)(unaff_ESI + 0xc) & 1 << ((bVar1 - 0xb) * '\x03' + param_2 & 0x1f)) != 0
                 );
  }
  return (uint)((*(uint *)(unaff_ESI + 8) & 1 << (bVar1 * '\x03' + param_2 & 0x1f)) != 0);
}


// ==== 0x5a3f00 Career::BuildRewardSummary

/* [canon] canon high (ghidra) docs/re/canon.md */

void Career__BuildRewardSummary(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  uint uVar3;
  int *piVar4;
  bool bVar5;
  
  puVar2 = param_1;
  in_EAX[1] = 0;
  *in_EAX = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    *in_EAX = *param_1;
    piVar4 = param_1 + 0x1d;
    param_1 = (undefined4 *)0x0;
    if (0 < *piVar4) {
      piVar4 = puVar2 + 0xf;
      do {
        if ((piVar4 == (int *)0x4) || (piVar4[-1] != 0)) goto switchD_005a3fba_default;
        bVar5 = piVar4[1] == 4;
        iVar1 = *piVar4;
        if ((iVar1 < 0x10) || ((0x18 < iVar1 || (bVar5)))) {
          if ((-1 < iVar1) && (iVar1 < 0x10)) {
            uVar3 = in_EAX[1] | 2;
            goto LAB_005a3f74;
          }
        }
        else {
          uVar3 = in_EAX[1] | 1;
LAB_005a3f74:
          in_EAX[1] = uVar3;
        }
        switch(*piVar4) {
        case 5:
        case 8:
        case 9:
        case 0xb:
        case 0xc:
        case 0xd:
          in_EAX[1] = in_EAX[1] | 8;
        }
        switch(*piVar4) {
        case 2:
        case 4:
        case 6:
        case 10:
        case 0xe:
          in_EAX[1] = in_EAX[1] | 0x10;
        }
        switch(*piVar4) {
        case 0:
          uVar3 = in_EAX[1] | 0x20;
          break;
        case 1:
          uVar3 = in_EAX[1] | 0x40;
          break;
        case 2:
          uVar3 = in_EAX[1] | 0x80;
          break;
        case 3:
          uVar3 = in_EAX[1] | 0x100;
          break;
        case 4:
          uVar3 = in_EAX[1] | 0x200;
          break;
        case 5:
          uVar3 = in_EAX[1] | 0x400;
          break;
        case 6:
          uVar3 = in_EAX[1] | 0x800;
          break;
        case 7:
          uVar3 = in_EAX[1] | 0x1000;
          break;
        case 8:
          uVar3 = in_EAX[1] | 0x2000;
          break;
        case 9:
          uVar3 = in_EAX[1] | 0x4000;
          break;
        case 10:
          uVar3 = in_EAX[1] | 0x8000;
          break;
        case 0xb:
          uVar3 = in_EAX[1] | 0x10000;
          break;
        case 0xc:
          uVar3 = in_EAX[1] | 0x20000;
          break;
        case 0xd:
          uVar3 = in_EAX[1] | 0x40000;
          break;
        case 0xe:
          uVar3 = in_EAX[1] | 0x80000;
          break;
        case 0xf:
          uVar3 = in_EAX[1] | 0x100000;
          break;
        case 0x10:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x200000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x11:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x400000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x12:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x800000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x13:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x1000000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x14:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x2000000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x15:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x4000000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x16:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x8000000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x17:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x10000000;
            break;
          }
          goto switchD_005a3fba_default;
        case 0x18:
          if (!bVar5) {
            uVar3 = in_EAX[1] | 0x20000000;
            break;
          }
        default:
          goto switchD_005a3fba_default;
        }
        in_EAX[1] = uVar3;
switchD_005a3fba_default:
        param_1 = (undefined4 *)((int)param_1 + 1);
        piVar4 = piVar4 + 3;
      } while ((int)param_1 < (int)puVar2[0x1d]);
    }
  }
  return;
}


// ==== 0x5a41e0 FUN_005a41e0

undefined1 __fastcall FUN_005a41e0(undefined4 param_1)

{
  undefined1 uVar1;
  
  switch(param_1) {
  case 1:
    uVar1 = FUN_00504180(0x4000,0);
    return uVar1;
  case 2:
    uVar1 = FUN_00504180(0x10000,0);
    return uVar1;
  default:
    return 0;
  case 6:
    uVar1 = FUN_00504180(0x100000,0);
    return uVar1;
  case 7:
    uVar1 = FUN_00504180(0x40000,0);
    return uVar1;
  case 8:
    uVar1 = FUN_00504180(0x20000,0);
    return uVar1;
  case 10:
    uVar1 = FUN_00504180(0x400,0);
    return uVar1;
  case 0xb:
    uVar1 = FUN_00504180(0x2000,0);
    return uVar1;
  case 0xd:
    uVar1 = FUN_00504180(0x800,0);
    return uVar1;
  case 0xe:
    uVar1 = FUN_00504180(0x8000,0);
    return uVar1;
  case 0xf:
    uVar1 = FUN_00504180(0x80,0);
    return uVar1;
  case 0x11:
    uVar1 = FUN_00504180(0x100,0);
    return uVar1;
  case 0x1f:
    uVar1 = FUN_00504180(0x1000,0);
    return uVar1;
  case 0x3a:
    uVar1 = FUN_00504180(0x40,0);
    return uVar1;
  case 0x73:
    uVar1 = FUN_00504180(0x200,0);
    return uVar1;
  case 0x74:
    uVar1 = FUN_00504180(0x80000,0);
    return uVar1;
  }
}


// ==== 0x5a4370 FUN_005a4370

undefined1 __fastcall FUN_005a4370(undefined4 param_1)

{
  undefined1 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = FUN_00504180(0x200000,0);
    return uVar1;
  case 1:
    uVar1 = FUN_00504180(0x4000000,0);
    return uVar1;
  case 2:
    uVar1 = FUN_00504180(0x800000,0);
    return uVar1;
  case 3:
    uVar1 = FUN_00504180(0x8000000,0);
    return uVar1;
  case 4:
    uVar1 = FUN_00504180(0x20000000,0);
    return uVar1;
  case 5:
    uVar1 = FUN_00504180(0x10000000,0);
    return uVar1;
  case 6:
    uVar1 = FUN_00504180(0x1000000,0);
    return uVar1;
  case 7:
    uVar1 = FUN_00504180(0x2000000,0);
    return uVar1;
  case 8:
    uVar1 = FUN_00504180(0x400000,0);
    return uVar1;
  default:
    return 0;
  }
}


// ==== 0x5a4420 UnlockTeller::GetNewlyUnlockedPartLevel

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int UnlockTeller__GetNewlyUnlockedPartLevel(void)

{
  char cVar1;
  uint *in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = MapCarPartIDToCareerUpgrade();
  cVar1 = FUN_005a41e0();
  if (cVar1 != '\0') {
    if (*in_EAX < 0x100) {
      iVar3 = (&DAT_00733ff8)[*in_EAX];
    }
    else {
      iVar3 = 0;
    }
    iVar5 = 0;
    if (0 < *(int *)(iVar3 + 0x74)) {
      piVar4 = (int *)(iVar3 + 0x38);
      do {
        if ((*piVar4 == 0) && (piVar4[1] == iVar2)) {
          return piVar4[2];
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 3;
      } while (iVar5 < *(int *)(iVar3 + 0x74));
    }
  }
  return -1;
}


// ==== 0x5a4480 FUN_005a4480

int FUN_005a4480(void)

{
  char cVar1;
  uint *in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = FUN_005a0350();
  cVar1 = FUN_005a4370();
  if (cVar1 != '\0') {
    if (*in_EAX < 0x100) {
      iVar3 = (&DAT_00733ff8)[*in_EAX];
    }
    else {
      iVar3 = 0;
    }
    iVar5 = 0;
    if (0 < *(int *)(iVar3 + 0x74)) {
      piVar4 = (int *)(iVar3 + 0x38);
      do {
        if ((*piVar4 == 0) && (piVar4[1] == iVar2)) {
          return piVar4[2];
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 3;
      } while (iVar5 < *(int *)(iVar3 + 0x74));
    }
  }
  return -1;
}


// ==== 0x5a44e0 FUN_005a44e0

void __thiscall
FUN_005a44e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  (**(code **)(param_1 + 4))(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5a4510 FUN_005a4510

void __thiscall FUN_005a4510(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 8))(param_2);
  return;
}


// ==== 0x5a4520 FUN_005a4520

undefined4 __fastcall FUN_005a4520(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ==== 0x5a4530 FUN_005a4530

void FUN_005a4530(void)

{
  (*DAT_00712024)();
  return;
}


// ==== 0x5a4540 FUN_005a4540

void FUN_005a4540(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x10) = 0;
  *(undefined1 *)(in_EAX + 0x11) = 0;
  *(undefined1 *)(in_EAX + 0x12) = 0;
  *(undefined1 *)(in_EAX + 0x13) = 0;
  *(undefined1 *)(in_EAX + 0x17) = 0;
  *(undefined1 *)(in_EAX + 0x18) = 0;
  *(undefined1 *)(in_EAX + 0x19) = 0;
  *(undefined1 *)(in_EAX + 0x16) = 0;
  *(undefined1 *)(in_EAX + 0x14) = 0;
  *(undefined1 *)(in_EAX + 0x1a) = 0;
  *(undefined1 *)(in_EAX + 0x1b) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined1 *)(in_EAX + 0x15) = 1;
  *(undefined1 *)(in_EAX + 0x1c) = 1;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined4 *)(in_EAX + 4) = 0;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined1 *)(in_EAX + 0x30) = 0;
  return;
}


// ==== 0x5a4590 FUN_005a4590

void __fastcall FUN_005a4590(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piStack_4;
  
  iVar2 = param_1[10];
  piStack_4 = param_1;
  if (iVar2 != 0) {
    FUN_006451dc();
    (*DAT_00712024)(iVar2);
    param_1[10] = 0;
  }
  if ((((0x12 < *param_1) && (*param_1 < 0x21)) && (DAT_006f1dd8 != 0)) &&
     ((*(int *)(DAT_007356a8 + 0x104) != 0 &&
      (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar1 != (int *)0x0)))) {
    (**(code **)(*piVar1 + 0x98))(0,0xffffffff);
  }
  if (*param_1 == 2) {
    piVar1 = *(int **)(DAT_007356a8 + 0x8c);
    iVar2 = DAT_007356a8;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_4);
      Mutex__Lock();
      (**(code **)(*piStack_4 + 4))(piVar1);
      Mutex__Unlock();
      iVar2 = DAT_007356a8;
      *(undefined4 *)(DAT_007356a8 + 0x8c) = 0;
    }
    *(undefined4 *)(iVar2 + 0x90) = 0;
  }
  Texture__ReleaseD3D();
  DAT_0073634c = 0;
  if (DAT_00736348 != 0) {
    FUN_00638880(DAT_00736348);
  }
  DAT_00736348 = 0;
  return;
}


// ==== 0x5a4670 FUN_005a4670

undefined4 __thiscall FUN_005a4670(char *param_1,undefined1 param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_ESI;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006859e8;
  pvStack_c = ExceptionList;
  cVar2 = *param_1;
  pcVar1 = (char *)(unaff_ESI + 0x31);
  ExceptionList = &pvStack_c;
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined1 *)(unaff_ESI + 0x10) = 0;
  *(undefined1 *)(unaff_ESI + 0x11) = 0;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  *(undefined1 *)(unaff_ESI + 0x13) = 0;
  *(undefined1 *)(unaff_ESI + 0x17) = 0;
  *(undefined1 *)(unaff_ESI + 0x18) = 0;
  *(undefined1 *)(unaff_ESI + 0x19) = 1;
  *(undefined1 *)(unaff_ESI + 0x1a) = 0;
  *(undefined1 *)(unaff_ESI + 0x1b) = 1;
  *(undefined1 *)(unaff_ESI + 0x14) = 0;
  *(undefined1 *)(unaff_ESI + 0x16) = 1;
  *(undefined1 *)(unaff_ESI + 0x15) = 0;
  *(char **)(unaff_ESI + 0x20) = pcVar1;
  *(undefined1 *)(unaff_ESI + 0x1c) = param_2;
  iVar4 = (*DAT_00712020)(&DAT_006b9172,0x94,0,0,DAT_00712028);
  uStack_4 = 0;
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00644a16(*(undefined4 *)(unaff_ESI + 0x20),0x100000,
                         *(undefined4 *)(unaff_ESI + 0x24),0x32000,0,0);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x28) = uVar5;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined1 *)(unaff_ESI + 0x30) = 1;
  FUN_005a4750(unaff_ESI);
  ExceptionList = pvStack_c;
  return 1;
}


// ==== 0x5a4750 FUN_005a4750

undefined4 FUN_005a4750(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char local_105;
  undefined1 local_100 [256];
  
  if (DAT_0078ea84 != 0) {
    return 0;
  }
  DAT_0078ea84 = 1;
  local_105 = '\0';
  bVar1 = false;
  FUN_0063fc90();
  rdtsc();
  FUN_0063f0a0(0);
  FUN_0063e5c0(0);
  if (*(char *)(param_1 + 0x30) == '\0') {
    if (*(int *)(param_1 + 0x2c) != 0) {
      cVar2 = FUN_006457c8();
      if (cVar2 == '\0') {
        bVar1 = true;
      }
      else {
        FUN_00648b3a(*(undefined4 *)(param_1 + 0x2c));
        uVar3 = FUN_00645732(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x48));
        *(undefined4 *)(param_1 + 0x2c) = uVar3;
        bVar1 = false;
      }
      goto LAB_005a487a;
    }
  }
  else {
    uVar3 = FUN_006453b2(2,((DAT_006f0880 == 0) * '\x04' + '\x10') * '\x02');
    *(undefined4 *)(param_1 + 0x2c) = uVar3;
    *(undefined1 *)(param_1 + 0x30) = 0;
    if (((DAT_006f1dd8 != 0) && (*(char *)(param_1 + 0x19) != '\0')) && (DAT_007356a8 != 0)) {
      uVar3 = FUN_005a4cf0(param_1);
      FUN_00645910(uVar3);
    }
    FUN_00413310(&DAT_00737320);
LAB_005a487a:
    if (*(int *)(param_1 + 0x2c) != 0) {
      if (*(char *)(param_1 + 0x11) != '\0') {
        DAT_0078ea80 = DAT_0078ea80 + 1;
        FUN_00565da0("d:\\decodercapture%04d.fss",DAT_0078ea80);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4);
        uVar4 = FUN_00638dd0(uVar3);
        FUN_0063cdd0(local_100,uVar3,uVar4);
      }
      goto LAB_005a48e2;
    }
  }
  bVar1 = true;
  local_105 = FUN_0064583f();
LAB_005a48e2:
  if ((*(int *)(param_1 + 0x2c) != 0) && (!bVar1)) {
    FUN_00413270(DAT_00733f68,&DAT_00737320,*(undefined4 *)(*(int *)(param_1 + 0x2c) + 4));
  }
  DAT_0078ea84 = 0;
  if (local_105 == '\0') {
    DAT_0078ea84 = 0;
    return 0;
  }
  return 1;
}


// ==== 0x5a4930 FUN_005a4930

undefined4 FUN_005a4930(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_00565b60(param_2,0,0,0x2000);
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[2] = uVar2;
    puVar3[3] = uVar2;
  }
  *DAT_007373a0 = puVar3;
  puVar1 = puVar3;
  puVar3[1] = DAT_007373a0;
  DAT_007373a0 = puVar1;
  *puVar3 = &DAT_0073739c;
  return uVar2;
}


// ==== 0x5a4980 FUN_005a4980

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


// ==== 0x5a49f0 FUN_005a49f0

undefined4 FUN_005a49f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *_Memory;
  
  piVar1 = DAT_0073739c;
  piVar3 = (int *)NullUpdate_ret();
  do {
    _Memory = (int *)0x0;
    if (piVar1 == piVar3) {
LAB_005a4a2c:
      FUN_00565ce0();
      if (_Memory != (int *)0x0) {
        _free(_Memory);
      }
      return 1;
    }
    if (param_1 == piVar1[3]) {
      iVar2 = *piVar1;
      piVar3 = (int *)piVar1[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      _Memory = piVar1;
      goto LAB_005a4a2c;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}


// ==== 0x5a4a50 FUN_005a4a50

void FUN_005a4a50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  void *pvVar2;
  
  if (DAT_0073496c == 0) {
    DAT_00733f74 = 1;
    DAT_00733f70 = 0;
    FUN_00648cf0();
    DAT_00712020 = FUN_005a4980;
    DAT_00712024 = FUN_005a49f0;
    FUN_00638ee0(FUN_005a4930,FUN_005a4980,FUN_005a49f0);
    pvVar2 = _malloc(0x134);
    if (pvVar2 == (void *)0x0) {
      DAT_00733f6c = (undefined4 *)0x0;
    }
    else {
      DAT_00733f6c = (undefined4 *)FUN_005a4540();
    }
    *DAT_00733f6c = param_3;
    FUN_005a4670(param_2);
    if (((DAT_006f1dd8 != 0) && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
       (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xa0))();
    }
    if (DAT_007363b4 != '\0') {
      SuspendThread(DAT_0070f460);
    }
  }
  return;
}


// ==== 0x5a4b20 FUN_005a4b20

void FUN_005a4b20(void)

{
  char cVar1;
  int iVar2;
  void *_Memory;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char local_100 [256];
  
  if ((DAT_00733f74 != 0) && (DAT_00733f6c != (void *)0x0)) {
    if (DAT_0078e954 < DAT_0073ad3c) {
      DAT_0078e954 = DAT_0073ad3c;
    }
    cVar3 = FUN_005a4750(DAT_00733f6c);
    uVar4 = (uint)(cVar3 != '\0');
    if (DAT_0073459c != 0) {
      uVar4 = FUN_0057c480(4,7);
      if (DAT_007345a4[4] <= *DAT_007345a4) {
        FUN_0057c580();
      }
      if ((uVar4 != 0) && ((cVar3 != '\0') == 0)) {
        do {
          cVar3 = FUN_005a4750(DAT_00733f6c);
        } while (cVar3 == '\0');
      }
    }
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(uVar4,4,7);
    }
    _Memory = DAT_00733f6c;
    if (uVar4 != 0) {
      iVar2 = *(int *)((int)DAT_00733f6c + 0x20);
      cVar3 = *(char *)((int)DAT_00733f6c + 0x1c);
      iVar6 = 0x100;
      pcVar5 = local_100;
      do {
        cVar1 = pcVar5[iVar2 - (int)local_100];
        iVar6 = iVar6 + -1;
        *pcVar5 = cVar1;
        if (cVar1 == '\0') break;
        pcVar5 = pcVar5 + 1;
      } while (iVar6 != 0);
      DAT_00733f74 = 0;
      FUN_005a4590();
      _free(_Memory);
      DAT_00733f6c = (void *)0x0;
      _free(DAT_00733f68);
      DAT_00733f68 = (void *)0x0;
      FEManager__BroadcastMessage(0xc3960eb9);
      if ((cVar3 != '\0') && (DAT_00733f70 == 0)) {
        FUN_005a4a50(local_100,cVar3,0xffffffff);
      }
    }
  }
  return;
}


// ==== 0x5a4c80 FUN_005a4c80

void FUN_005a4c80(void)

{
  void *_Memory;
  
  _Memory = DAT_00733f6c;
  if ((DAT_00733f6c != (void *)0x0) && (*(char *)((int)DAT_00733f6c + 0x30) == '\0')) {
    DAT_00733f74 = 0;
    FUN_005a4590();
    _free(_Memory);
    DAT_00733f6c = (void *)0x0;
    _free(DAT_00733f68);
    DAT_00733f68 = (void *)0x0;
  }
  if (DAT_007363b4 != '\0') {
    ResumeThread(DAT_0070f460);
  }
  return;
}


// ==== 0x5a4cf0 FUN_005a4cf0

undefined4 FUN_005a4cf0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  LARGE_INTEGER local_8;
  
  iVar1 = *param_1;
  uVar3 = 0x7f;
  if ((-1 < iVar1) && (iVar1 < 0x2b)) {
    uVar3 = _ftol_nocw();
  }
  if (iVar1 == 1) {
    FUN_00520ae0();
  }
  iVar1 = DAT_007356a8;
  if (*param_1 == 2) {
    QueryPerformanceCounter(&local_8);
    uVar2 = __allshr();
    *(undefined4 *)(iVar1 + 0x94) = uVar2;
    *(undefined4 *)(iVar1 + 0x90) = 2;
  }
  return uVar3;
}


// ==== 0x5a4d80 FUN_005a4d80

undefined4 * FUN_005a4d80(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  
  puVar3 = DAT_00737300;
  puVar4 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar3 == puVar4) {
      return (undefined4 *)0x0;
    }
    pbVar5 = (byte *)puVar3[3];
    iVar6 = -1;
    bVar2 = *pbVar5;
    while (bVar2 != 0) {
      iVar6 = iVar6 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (iVar6 == param_1) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  return puVar3;
}


// ==== 0x5a4de0 AnimSkeleton_Load

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export block; live
   Ghidra decompile + capstone) docs/re/assets.md */

undefined4 AnimSkeleton_Load(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (*param_1 == 0xe34009) {
    puVar3 = _malloc(0x24);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[8] = 0;
    }
    uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
    iVar1 = (param_1[1] - uVar6) + 8 + (int)param_1;
    iVar4 = (*(code *)PTR_FUN_006dfa9c)(0x2c,"EAGL::DynamicLoader CAnimSkeleton");
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0061eee0(uVar6,iVar1,0);
    }
    puVar3[6] = uVar5;
    puVar3[7] = iVar1;
    puVar3[5] = 1;
    FUN_0047b6d0();
    *DAT_00737304 = puVar3;
    puVar2 = puVar3;
    puVar3[1] = DAT_00737304;
    DAT_00737304 = puVar2;
    *puVar3 = &DAT_00737300;
    return 1;
  }
  return 0;
}


// ==== 0x5a4e90 AnimSkeleton_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 AnimSkeleton_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  if (*param_1 != 0xe34009) {
    return 0;
  }
  if ((int **)DAT_00737300 != &DAT_00737300) {
    do {
      piVar2 = DAT_00737300;
      iVar1 = DAT_00737300[6];
      DAT_00737300[2] = 0;
      piVar2[3] = 0;
      piVar2[4] = 0;
      piVar2[5] = 0;
      if (iVar1 != 0) {
        FUN_0061ef30();
        (*(code *)PTR_FUN_006dfaa0)(iVar1,0x2c);
        piVar2[6] = 0;
      }
      piVar2[8] = 0;
      _Memory = DAT_00737300;
      iVar1 = *DAT_00737300;
      piVar2 = (int *)DAT_00737300[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      _free(_Memory);
    } while ((int **)DAT_00737300 != &DAT_00737300);
  }
  return 1;
}


// ==== 0x5a4f10 FUN_005a4f10

undefined4 * __thiscall FUN_005a4f10(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_005a4f40();
  iVar2 = DAT_00733f64;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f64 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x5a4f40 FUN_005a4f40

void __fastcall FUN_005a4f40(undefined4 *param_1)

{
  void *_Memory;
  int *piVar1;
  int iVar2;
  
  _Memory = (void *)param_1[0x2a];
  *param_1 = &PTR_FUN_006b7efc;
  if (_Memory != (void *)0x0) {
    if (*(char *)((int)_Memory + 0x19) != '\0') {
      _free(*(void **)((int)_Memory + 0x20));
    }
    _free(_Memory);
  }
  piVar1 = param_1 + 2;
  iVar2 = 0x28;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x5a4f90 FUN_005a4f90

void FUN_005a4f90(void)

{
  int iVar1;
  char cVar2;
  int *unaff_EBX;
  int unaff_ESI;
  int *piVar3;
  char local_15;
  int iStack_14;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006866b0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00571ea0(0,"FuturePointsPtr");
  piVar3 = (int *)*unaff_EBX;
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    if (piVar3 != (int *)0x0) {
      (**(code **)*piVar3)(1);
    }
    piVar3 = (int *)0x0;
  }
  local_15 = piVar3 != (int *)0x0;
  FUN_00571c20(unaff_ESI,&local_15,1,1,1);
  if (local_15 == '\0') goto LAB_005a507a;
  if (piVar3 != (int *)0x0) {
    iStack_14 = (**(code **)(*piVar3 + 4))();
  }
  FUN_00571c20(unaff_ESI,&iStack_14,1,4,1);
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    if (iStack_14 == 0) {
      iStack_10 = FUN_00567160();
      uStack_4 = 0;
      if (iStack_10 == 0) {
LAB_005a5069:
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)FUN_00455270();
      }
    }
    else if (iStack_14 == 1) {
      iStack_10 = FUN_00567160();
      uStack_4 = 1;
      if (iStack_10 == 0) goto LAB_005a5069;
      piVar3 = (int *)FUN_00455390();
    }
    *unaff_EBX = (int)piVar3;
  }
  if (piVar3 != (int *)0x0) {
    FUN_005a50c0();
  }
LAB_005a507a:
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x5a50c0 FUN_005a50c0

void FUN_005a50c0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  char cVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = 0;
  FUN_00571ea0(0,"FuturePoints");
  if ((*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') &&
     (iVar2 = *(int *)(unaff_EDI + 0xa8), iVar2 != 0)) {
    *(undefined1 *)(iVar2 + 0x18) = 1;
    *(undefined2 *)(iVar2 + 0x1e) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  FUN_00571c20(in_EAX,unaff_EDI + 0xb8,4,4,0);
  FUN_00571c20(in_EAX,unaff_EDI + 0xbc,1,1,0);
  FUN_00571c20(in_EAX,unaff_EDI + 0xc0,4,4,0);
  piVar1 = (int *)(unaff_EDI + 4);
  FUN_00571c20(in_EAX,piVar1,4,4,0);
  FUN_00571c20(in_EAX,unaff_EDI + 0xac,4,4,0);
  if (0 < *piVar1) {
    do {
      FUN_005a70f0();
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar1);
  }
  FUN_00571c20(in_EAX,unaff_EDI + 0xb0,1,1,0);
  iVar4 = 0;
  do {
    FUN_00571c20(in_EAX,unaff_EDI + 0xb1 + iVar4,1,1,0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar4 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar4 + 0x58 + in_EAX);
  cVar3 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5a51f0 FUN_005a51f0

int * FUN_005a51f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *local_8;
  int iStack_4;
  
  local_8 = (int *)0x0;
  (**(code **)(*param_1 + 4))();
  FUN_00457060(&local_8);
  piVar2 = local_8;
  local_8[0x2e] = param_1[0x2e];
  *(char *)(local_8 + 0x2f) = (char)param_1[0x2f];
  local_8[0x30] = param_1[0x30];
  iVar4 = param_1[0x2b];
  local_8[0x2b] = iVar4;
  *(char *)(local_8 + 0x2c) = (char)param_1[0x2c];
  *(undefined1 *)((int)local_8 + 0xb1) = *(undefined1 *)((int)param_1 + 0xb1);
  *(undefined1 *)((int)local_8 + 0xb2) = *(undefined1 *)((int)param_1 + 0xb2);
  *(undefined1 *)((int)local_8 + 0xb3) = *(undefined1 *)((int)param_1 + 0xb3);
  *(char *)(local_8 + 0x2d) = (char)param_1[0x2d];
  iVar4 = CONCAT31((int3)((uint)iVar4 >> 8),*(undefined1 *)((int)param_1 + 0xb5));
  *(undefined1 *)((int)local_8 + 0xb5) = *(undefined1 *)((int)param_1 + 0xb5);
  *(undefined1 *)((int)local_8 + 0xb6) = *(undefined1 *)((int)param_1 + 0xb6);
  iStack_4 = 0;
  if (0 < param_1[1]) {
    local_8 = param_1 + 2;
    do {
      iVar1 = *local_8;
      FUN_005a5510(piVar2,(int)*(char *)(iVar1 + 0x5c),iVar1 + 4,iVar1 + 8,
                   *(undefined4 *)(iVar1 + 0x58),
                   CONCAT31((int3)((uint)iVar4 >> 8),*(char *)(iVar1 + 0x60) != '\0'));
      iVar4 = piVar2[piVar2[1] + 1];
      *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
      puVar5 = (undefined4 *)(iVar1 + 0x40);
      puVar6 = (undefined4 *)(iVar4 + 0x40);
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
      puVar5 = (undefined4 *)(iVar1 + 0x24);
      puVar6 = (undefined4 *)(iVar4 + 0x24);
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar4 = param_1[1];
      iStack_4 = iStack_4 + 1;
      local_8 = local_8 + 1;
    } while (iStack_4 < iVar4);
  }
  return piVar2;
}


// ==== 0x5a5340 FUN_005a5340

void FUN_005a5340(void)

{
  int iVar1;
  int unaff_ESI;
  int *piVar2;
  
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 0xac) = 0xffffffff;
  if (*(int *)(unaff_ESI + 0xa8) != 0) {
    FUN_0059cb20();
  }
  piVar2 = (int *)(unaff_ESI + 8);
  iVar1 = 0x28;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(unaff_ESI + 0xb8) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0xc0) = 0xffffffff;
  *(undefined1 *)(unaff_ESI + 0xbc) = 0;
  *(undefined1 *)(unaff_ESI + 0xb0) = 1;
  *(undefined4 *)(unaff_ESI + 0xb1) = 0x1010101;
  *(undefined2 *)(unaff_ESI + 0xb5) = 0x101;
  return;
}


// ==== 0x5a53c0 RoadPath_Step

/* WARNING: Removing unreachable block (ram,0x005a545c) */
/* WARNING: Removing unreachable block (ram,0x005a5475) */
/* [canon] traffic high (G+file) docs/re/traffic.md */

int RoadPath_Step(int *param_1,int *param_2,int *param_3,int *param_4,undefined1 *param_5)

{
  char cVar1;
  char extraout_AL;
  int iVar2;
  int iVar3;
  uint3 uVar4;
  uint3 extraout_var;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  do {
    iVar2 = 0;
    do {
      if (*(char *)(*param_3 + 0x81 + iVar2) == -1) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    if (iVar2 <= iVar5) {
      (**(code **)(*param_1 + 0x28))(param_4,*param_2);
      uVar4 = extraout_var;
      if (extraout_AL != '\0') {
        iVar5 = *param_2;
        *param_3 = *param_4 * 0x88 + 0x27c + iVar5;
        *(undefined1 *)param_3 = 0;
        return CONCAT31((int3)((uint)iVar5 >> 8),1);
      }
LAB_005a54d6:
      return (uint)uVar4 << 8;
    }
    uVar6 = (uint)*(byte *)(*param_3 + 0x81 + iVar5);
    if (uVar6 == 0xff) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar6 * 0x20 + DAT_00736150;
    }
    iVar3 = (**(code **)(*param_1 + 4))();
    uVar4 = (uint3)((uint)-iVar3 >> 8);
    if ((*(char *)(iVar2 + 0xb) == '\x03') &&
       ((*(char *)(iVar2 + 0xd) == '\x01') != (bool)('\x01' - (iVar3 != 0)))) goto LAB_005a54d6;
    cVar1 = RoadPath_LinkAccepted(iVar2);
    if (cVar1 != '\0') {
      *param_2 = (&DAT_0077af30)[*(byte *)(iVar2 + 9)];
      iVar5 = (uint)*(ushort *)(iVar2 + 4) * 0x88 + 0x27c + (&DAT_0077af30)[*(byte *)(iVar2 + 9)];
      *param_3 = iVar5;
      *param_4 = ((iVar5 - *param_2) + -0x27c) / 0x88;
      *param_5 = 1;
      return 1;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


// ==== 0x5a5510 FUN_005a5510

void FUN_005a5510(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined1 param_5)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (&DAT_0077af30)[(int)param_2];
  }
  iVar1 = (**(code **)(*param_1 + 0x2c))(in_EAX * 0x88 + 0x27c + iVar1);
  param_1[param_1[1] + 2] = iVar1;
  iVar1 = param_1[param_1[1] + 2];
  *(undefined4 *)(iVar1 + 0x58) = param_4;
  *(short *)(iVar1 + 0x5e) = (short)in_EAX;
  *(char *)(iVar1 + 0x5c) = (char)param_2;
  *(undefined1 *)(iVar1 + 0x60) = param_5;
  *(undefined4 *)(iVar1 + 4) = *param_2;
  puVar3 = (undefined4 *)(iVar1 + 8);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = param_1[1];
  if (0 < iVar1) {
    *(int *)(param_1[iVar1 + 2] + 0x68) = param_1[iVar1 + 1];
    *(int *)(param_1[param_1[1] + 1] + 0x6c) = param_1[param_1[1] + 2];
  }
  param_1[1] = param_1[1] + 1;
  return;
}


// ==== 0x5a55b0 FUN_005a55b0

void FUN_005a55b0(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *local_4;
  
  *(undefined4 *)(in_EAX + 0xb8) = 0xffffffff;
  *(undefined1 *)(in_EAX + 0xbc) = 0;
  *(undefined4 *)(in_EAX + 0xc0) = 0xffffffff;
  *(undefined1 *)(in_EAX + 0xb0) = 1;
  *(undefined4 *)(in_EAX + 0xb1) = 0x1010101;
  *(undefined2 *)(in_EAX + 0xb5) = 0x101;
  uVar6 = ((int)*(uint *)(in_EAX + 0xac) < 1) - 1 & *(uint *)(in_EAX + 0xac);
  if (*(int *)(in_EAX + 4) <= (int)uVar6) {
    return;
  }
  local_4 = (int *)(in_EAX + 4 + uVar6 * 4);
LAB_005a5610:
  iVar5 = local_4[1];
  cVar1 = *(char *)(iVar5 + 0x5c);
  if (((cVar1 == -1) || (*(short *)(iVar5 + 0x5e) == -1)) || (cVar1 < 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = (&DAT_0077af30)[cVar1];
  }
  iVar7 = (int)cVar1;
  if ((cVar1 == -1) || (*(short *)(iVar5 + 0x5e) == -1)) {
    iVar2 = 0;
  }
  else {
    if (iVar7 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[iVar7];
    }
    iVar2 = *(short *)(iVar5 + 0x5e) * 0x88 + 0x27c + iVar2;
  }
  if ((uVar6 == 0) || (iVar7 != *(char *)(*local_4 + 0x5c))) {
    FUN_005a6000(uVar4);
  }
  if (((*(uint *)(iVar2 + 0x84) & 0x1f00000) != 0x1f00000) && (*(int *)(in_EAX + 0xb8) == -1)) {
    *(uint *)(in_EAX + 0xb8) = uVar6;
  }
  iVar5 = 0;
  do {
    iVar7 = 0;
    do {
      if (*(char *)(iVar7 + 0x81 + iVar2) == -1) break;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
    if ((iVar7 <= iVar5) || (*(int *)(in_EAX + 0xc0) != -1)) break;
    uVar3 = (uint)*(byte *)(iVar5 + 0x81 + iVar2);
    if (uVar3 == 0xff) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar3 * 0x20 + DAT_00736150;
    }
    if (*(char *)(iVar7 + 0xb) == '\t') {
      *(uint *)(in_EAX + 0xc0) = uVar6;
    }
    if (*(char *)(iVar7 + 0x10) != '\0') {
      *(undefined1 *)(in_EAX + 0xbc) = 1;
    }
    iVar5 = iVar5 + 1;
  } while( true );
  uVar6 = uVar6 + 1;
  local_4 = local_4 + 1;
  if (*(int *)(in_EAX + 4) <= (int)uVar6) {
    return;
  }
  goto LAB_005a5610;
}


// ==== 0x5a5730 FUN_005a5730

void FUN_005a5730(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  float10 fVar4;
  
  iVar2 = (int)param_2;
  iVar3 = FUN_005a5ef0(in_EAX,param_1);
  param_2 = 0.0;
  if (iVar3 == -1) {
    FUN_005a5340();
  }
  else {
    iVar1 = *(int *)(in_EAX + 8 + iVar3 * 4);
    (**(code **)(**(int **)(iVar2 + 0x2c) + 0x24))();
    FUN_005a6080(iVar2);
    param_2 = *(float *)(iVar1 + 0x58);
    *(int *)(in_EAX + 0xac) = iVar3;
  }
  if (*param_1 != 0) {
    if (*(int *)(in_EAX + 4) == 0) {
      FUN_005a57f0(in_EAX);
    }
    else {
      fVar4 = (float10)FUN_00458b90();
      FUN_005a58d0(in_EAX,(float)(fVar4 + (float10)param_2));
    }
    FUN_005a55b0(iVar2);
    FUN_005a5c30(in_EAX);
  }
  return;
}


// ==== 0x5a57f0 FUN_005a57f0

void FUN_005a57f0(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  int unaff_EDI;
  float10 fVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = param_1;
  param_1 = 0.0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (*in_EAX == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = (int)*(short *)(*in_EAX + 10);
  }
  FUN_005a5510(uVar2,iVar3,&param_1,&local_18,0,0);
  fVar1 = *(float *)((*(int **)(unaff_EDI + 0x2c))[1] + 0x3d4);
  param_1 = DAT_00700680;
  fVar4 = (float10)(**(code **)(**(int **)(unaff_EDI + 0x2c) + 0x50))();
  fVar4 = fVar4 * (float10)fVar1;
  if ((float10)param_1 < fVar4) {
    param_1 = (float)fVar4;
  }
  FUN_005a58d0(uVar2,param_1);
  return;
}


// ==== 0x5a58d0 FUN_005a58d0

void FUN_005a58d0(int *param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  float unaff_EBX;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  float fVar8;
  float10 fVar9;
  float local_48;
  float local_44;
  int local_40;
  int iStack_3c;
  uint local_38;
  float local_34;
  int local_30;
  float local_2c;
  int local_28;
  int iStack_24;
  int local_20;
  undefined4 local_1c;
  float local_18 [5];
  float fStack_4;
  
  local_1c = *(undefined4 *)(in_EAX + 0x2c);
  iVar4 = *(int *)(in_EAX + 0x10);
  if (*(char *)(iVar4 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar1 = param_1[param_1[1] + 1];
  local_20 = (int)*(char *)(iVar4 + 0x424);
  cVar3 = *(char *)(iVar1 + 0x5c);
  if (((cVar3 == -1) || (*(short *)(iVar1 + 0x5e) == -1)) || (cVar3 < 0)) {
    local_30 = 0;
  }
  else {
    local_30 = (&DAT_0077af30)[cVar3];
  }
  local_34 = *(float *)(iVar1 + 0x58);
  fVar9 = (float10)local_34;
  local_28 = (int)*(short *)(iVar1 + 0x5e);
  cVar3 = *(char *)(iVar1 + 0x5c);
  local_38 = local_38 & 0xffffff00;
  if ((cVar3 == -1) || (*(short *)(iVar1 + 0x5e) == -1)) {
    fVar5 = 0.0;
  }
  else {
    if (cVar3 < 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (&DAT_0077af30)[cVar3];
    }
    fVar5 = (float)(*(short *)(iVar1 + 0x5e) * 0x88 + 0x27c + iVar4);
  }
  local_48 = *(float *)(iVar1 + 4);
  local_40 = 0;
  pfVar6 = (float *)(iVar1 + 8);
  pfVar7 = local_18;
  for (iVar4 = 6; local_44 = fVar5, iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar7 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    pfVar7 = pfVar7 + 1;
  }
  do {
    uVar2 = local_1c;
    if ((fVar9 < (float10)param_2 == (fVar9 == (float10)param_2)) && (9 < param_1[1])) {
      return;
    }
    if (0x27 < param_1[1]) {
      return;
    }
    local_2c = fVar5;
    cVar3 = RoadPath_Step(param_1,&local_30,&local_44,&local_28,&local_38,local_1c);
    fVar8 = local_44;
    if (cVar3 == '\0') {
      return;
    }
    if ((char)local_38 == '\0') {
      fVar9 = (float10)(**(code **)(*param_1 + 0x24))(fVar5);
      fVar5 = local_48;
      if (unaff_EBX <= 0.0) {
        unaff_EBX = (float)fVar9 * 0.04 + unaff_EBX;
        if (0.0 <= unaff_EBX) goto LAB_005a5b2c;
      }
      else {
        unaff_EBX = unaff_EBX - (float)fVar9 * 0.04;
        if (unaff_EBX <= 0.0) {
LAB_005a5b2c:
          unaff_EBX = 0.0;
        }
      }
      (**(code **)(*param_1 + 0x34))(&stack0xffffffb4,iStack_24,local_48);
      iVar4 = 0;
      pfVar6 = local_18;
      do {
        fVar8 = *pfVar6;
        if (fVar8 <= 0.0) {
          fVar8 = (float)param_1 * 0.04 + fVar8;
          if (0.0 <= fVar8) goto LAB_005a5b99;
        }
        else {
          fVar8 = fVar8 - (float)param_1 * 0.04;
          if (fVar8 <= 0.0) {
LAB_005a5b99:
            fVar8 = 0.0;
          }
        }
        iVar1 = *param_1;
        *pfVar6 = fVar8;
        (**(code **)(iVar1 + 0x34))(pfVar6,iVar4 + 0xb,fVar5);
        iVar4 = iVar4 + 1;
        pfVar6 = pfVar6 + 1;
      } while (iVar4 < 6);
    }
    else {
      fVar9 = (float10)(**(code **)(*param_1 + 0x10))(fVar5,local_44);
      fStack_4 = (float)fVar9;
      if (fVar9 < (float10)0.1) {
        do {
          cVar3 = RoadPath_Step(param_1,&local_38,&stack0xffffffb4,&local_30,&fStack_4,uVar2);
          if (cVar3 == '\0') {
            return;
          }
          fVar9 = (float10)(**(code **)(*param_1 + 0x10))(fVar5,unaff_EBX);
          fStack_4 = (float)fVar9;
          local_48 = (float)((int)local_48 + 1);
          if (100 < (int)local_48) {
            return;
          }
          fVar8 = unaff_EBX;
        } while (fStack_4 < 0.1);
      }
      iVar4 = local_28;
      FUN_005a5f80(fVar8,fVar5);
      (**(code **)(*param_1 + 0x34))(&stack0xffffffb0,iVar4,fVar8);
      iStack_3c = 0xb;
      pfVar6 = local_18;
      iStack_24 = 6;
      do {
        fVar9 = (float10)FUN_005a5f80(fVar8,local_2c);
        iVar1 = iStack_3c;
        iVar4 = *param_1;
        *pfVar6 = (float)(fVar9 + (float10)*pfVar6);
        (**(code **)(iVar4 + 0x34))(pfVar6,iStack_3c,fVar8);
        iStack_3c = iVar1 + 1;
        pfVar6 = pfVar6 + 1;
        iStack_24 = iStack_24 + -1;
      } while (iStack_24 != 0);
      iStack_24 = 0;
      fVar5 = fVar8;
    }
    local_34 = (float)param_1 + local_34;
    fVar9 = (float10)FUN_005a5510(param_1,(int)*(short *)(local_30 + 10),&local_48,local_18,local_34
                                  ,local_38);
    local_40 = local_40 + 1;
    if (100 < local_40) {
      return;
    }
  } while( true );
}


// ==== 0x5a5c30 FUN_005a5c30

void FUN_005a5c30(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  float unaff_EBX;
  int iVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  float10 fVar13;
  float10 fVar14;
  undefined4 uVar15;
  float fStack_28;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  int iStack_4;
  
  iVar7 = *(int *)(in_EAX + 0x10);
  if (*(char *)(iVar7 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar11 = (int)*(char *)(iVar7 + 0x424);
  uVar15 = 1;
  uVar6 = FUN_0041f5e0(1);
  iVar7 = FUN_005a6150(param_1,uVar6,uVar15);
  if (iVar7 != -1) {
    FUN_005a6860(iVar11,0xbf800000);
  }
  piVar8 = *(int **)(param_1 + 4 + *(int *)(param_1 + 4) * 4);
  (**(code **)(*piVar8 + 8))(iVar11);
  fVar13 = (float10)(**(code **)(*piVar8 + 0xc))(iVar11);
  piVar8[0xf] = (int)(float)fVar13;
  piVar8[8] = iStack_4;
  iVar7 = 0xb;
  pfVar10 = (float *)(piVar8 + 0x10);
  iStack_4 = 6;
  do {
    (**(code **)(*piVar8 + 8))(iVar7);
    fVar13 = (float10)(**(code **)(*piVar8 + 0xc))(iVar7);
    *pfVar10 = (float)fVar13;
    pfVar10[-7] = fStack_18;
    pfVar10 = pfVar10 + 1;
    iVar7 = iVar7 + 1;
    iStack_4 = iStack_4 + -1;
  } while (iStack_4 != 0);
  iVar7 = *(int *)(param_1 + 4) + -2;
  if (-1 < iVar7) {
    piVar8 = (int *)(param_1 + 0xc + iVar7 * 4);
    fStack_18 = (float)(*(int *)(param_1 + 4) + -1);
    while( true ) {
      iVar7 = *piVar8;
      piVar3 = (int *)piVar8[-1];
      fVar13 = (float10)(**(code **)(*piVar3 + 8))(uStack_14);
      fVar1 = (float)fVar13;
      fVar14 = (float10)(**(code **)(*piVar3 + 0xc))(uStack_14);
      fVar13 = (float10)unaff_EBX;
      fStack_1c = fVar1;
      if (fStack_28 < -0.12 != (fStack_28 == -0.12)) {
        if ((-4.0 < unaff_EBX) && (15.0 <= (float)(fVar14 - fVar13))) {
          unaff_EBX = 0.0;
        }
        fStack_1c = fVar1 * 3.0;
      }
      fVar2 = fVar1;
      if (0.12 <= fStack_28) {
        if ((fVar14 < (float10)4.0) && (15.0 <= (float)(fVar14 - fVar13))) {
          fVar14 = (float10)0.0;
        }
        fVar2 = fVar1 * 3.0;
      }
      fVar2 = *(float *)(iVar7 + 0x20) - fVar2;
      fVar4 = *(float *)(iVar7 + 0x3c);
      if (fVar2 < unaff_EBX) {
        fVar2 = unaff_EBX;
      }
      piVar3[8] = (int)fVar2;
      fVar4 = fVar4 + fStack_1c;
      if ((float10)fVar4 <= fVar14) {
        fVar14 = (float10)fVar4;
      }
      piVar3[0xf] = (int)(float)fVar14;
      pfVar12 = (float *)(iVar7 + 0x24);
      iVar9 = 0xb;
      pfVar10 = (float *)(piVar3 + 0x10);
      iVar11 = 6;
      do {
        (**(code **)(*piVar3 + 8))(iVar9);
        fVar13 = (float10)(**(code **)(*piVar3 + 0xc))(iVar9);
        fVar2 = pfVar12[7];
        fVar5 = *pfVar12 - fVar1;
        if (*pfVar12 - fVar1 < fVar4) {
          fVar5 = fVar4;
        }
        *(float *)(((int)piVar3 - iVar7) + (int)pfVar12) = fVar5;
        fVar5 = fVar2 + fVar1;
        if ((float)fVar13 < fVar2 + fVar1) {
          fVar5 = (float)fVar13;
        }
        *pfVar10 = fVar5;
        pfVar12 = pfVar12 + 1;
        pfVar10 = pfVar10 + 1;
        iVar9 = iVar9 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      piVar8 = piVar8 + -1;
      fStack_18 = (float)((int)fStack_18 + -1);
      if (fStack_18 == 0.0) break;
      unaff_EBX = 0.0;
    }
  }
  return;
}


// ==== 0x5a5ef0 FUN_005a5ef0

int FUN_005a5ef0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *param_2;
  iVar2 = -1;
  if (iVar1 != 0) {
    if (0 < *(int *)(param_1 + 4)) {
      piVar3 = (int *)(param_1 + 8);
      iVar2 = 0;
      while (((short)*(char *)(*piVar3 + 0x5c) != *(short *)(iVar1 + 10) ||
             ((int)*(short *)(*piVar3 + 0x5e) != ((param_2[1] - iVar1) + -0x27c) / 0x88))) {
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
        if (*(int *)(param_1 + 4) <= iVar2) {
          return -1;
        }
      }
    }
  }
  return iVar2;
}


// ==== 0x5a5f80 FUN_005a5f80

float10 FUN_005a5f80(undefined4 param_1,int param_2)

{
  int iVar1;
  int *unaff_ESI;
  float10 fVar2;
  undefined1 *puVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_24 [32];
  
  iVar1 = (**(code **)(*unaff_ESI + 8))();
  puVar3 = auStack_24;
  (**(code **)(*unaff_ESI + 0x1c))
            (param_2,puVar3,0,
             (float)((int)*(short *)(param_2 + 0x3c + iVar1 * 2) << 8) * 1.5258789e-05);
  fVar2 = (float10)(**(code **)(*unaff_ESI + 0x14))(param_1,auStack_34);
  return fVar2 - (float10)(float)puVar3;
}


// ==== 0x5a6000 FUN_005a6000

int FUN_005a6000(int param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  
  iVar2 = *(int *)(in_EAX + 0x10);
  if (*(char *)(iVar2 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  cVar1 = *(char *)(iVar2 + 0x424);
  iVar2 = (**(code **)(*unaff_ESI + 4))();
  iVar2 = (iVar2 * 5 + 1 + (int)cVar1) * 0x34;
  if ((*(char *)(iVar2 + param_1) == '\0') && (*(char *)(iVar2 + param_1 + 1) == '\0')) {
    *(undefined1 *)(unaff_ESI + 0x2c) = 0;
  }
  iVar2 = 0;
  do {
    iVar3 = (**(code **)(*unaff_ESI + 8))(iVar2 + 0xb);
    if (*(char *)(iVar3 + 0x265 + param_1) == '\0') {
      *(undefined1 *)(iVar2 + 0xb1 + (int)unaff_ESI) = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return iVar3 + 0x265 + param_1;
}


// ==== 0x5a6080 FUN_005a6080

void FUN_005a6080(void)

{
  float fVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_ESI + 4) <= unaff_EDI) {
    return;
  }
  fVar1 = *(float *)(*(int *)(unaff_ESI + 8 + unaff_EDI * 4) + 0x58);
  if (0 < unaff_EDI) {
    piVar4 = (int *)(unaff_ESI + 8);
    iVar6 = unaff_EDI;
    do {
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
      }
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = 0;
  if (0 < *(int *)(unaff_ESI + 4) - unaff_EDI) {
    piVar4 = (int *)(unaff_ESI + 8);
    piVar3 = (int *)(unaff_ESI + 8 + unaff_EDI * 4);
    do {
      iVar5 = *piVar3;
      *piVar4 = iVar5;
      iVar6 = iVar6 + 1;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
      *(float *)(iVar5 + 0x58) = *(float *)(iVar5 + 0x58) - fVar1;
    } while (iVar6 < *(int *)(unaff_ESI + 4) - unaff_EDI);
  }
  iVar6 = 0;
  *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) - unaff_EDI;
  if (0 < unaff_EDI) {
    do {
      iVar5 = *(int *)(unaff_ESI + 4) + iVar6;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(unaff_ESI + 8 + iVar5 * 4) = 0;
    } while (iVar6 < unaff_EDI);
  }
  if (*(int *)(unaff_ESI + 8) == 0) {
    *(undefined4 *)(unaff_ESI + 0xac) = 0xffffffff;
    FUN_005a55b0();
    return;
  }
  *(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x68) = 0;
  uVar2 = *(int *)(unaff_ESI + 0xac) - unaff_EDI;
  *(uint *)(unaff_ESI + 0xac) = uVar2 & ((int)uVar2 < 1) - 1;
  FUN_005a55b0();
  return;
}


// ==== 0x5a6150 FUN_005a6150

int FUN_005a6150(float param_1,float *param_2,uint param_3)

{
  char cVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  int in_EAX;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  int local_8;
  
  iVar4 = (int)param_1;
  local_8 = -1;
  param_1 = 1e+14;
  if (in_EAX < 1) {
    in_EAX = 0;
  }
  if (*(int *)(iVar4 + 4) <= in_EAX) {
    return -1;
  }
  do {
    piVar2 = *(int **)(iVar4 + 8 + in_EAX * 4);
    cVar1 = (char)piVar2[0x17];
    if ((cVar1 == -1) || (*(short *)((int)piVar2 + 0x5e) == -1)) {
      pfVar5 = (float *)0x0;
    }
    else {
      if (cVar1 < 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = (&DAT_0077af30)[cVar1];
      }
      pfVar5 = (float *)(*(short *)((int)piVar2 + 0x5e) * 0x88 + 0x27c + iVar6);
    }
    fVar3 = SQRT((*pfVar5 - *param_2) * (*pfVar5 - *param_2) +
                 (pfVar5[1] - param_2[1]) * (pfVar5[1] - param_2[1]));
    if ((param_3 & 1) == 0) {
LAB_005a624a:
      if ((param_3 & 2) != 0) {
        cVar1 = (char)piVar2[0x17];
        fVar7 = (float10)0.0;
        if ((cVar1 != -1) && (*(short *)((int)piVar2 + 0x5e) != -1)) {
          if (cVar1 < 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = (&DAT_0077af30)[cVar1];
          }
          iVar6 = *(short *)((int)piVar2 + 0x5e) * 0x88 + 0x27c + iVar6;
          if (iVar6 != 0) {
            fVar7 = (float10)(**(code **)(*piVar2 + 0x20))(iVar6,param_2);
            fVar7 = fVar7 + (float10)(float)piVar2[0x16];
          }
        }
        if (fVar7 <= (float10)(float)piVar2[0x16]) goto LAB_005a62c5;
      }
      if (fVar3 < param_1) {
        param_1 = fVar3;
        local_8 = in_EAX;
      }
    }
    else {
      fVar7 = (float10)0.0;
      if ((cVar1 != -1) && (*(short *)((int)piVar2 + 0x5e) != -1)) {
        if (cVar1 < 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = (&DAT_0077af30)[cVar1];
        }
        iVar6 = *(short *)((int)piVar2 + 0x5e) * 0x88 + 0x27c + iVar6;
        if (iVar6 != 0) {
          fVar7 = (float10)(**(code **)(*piVar2 + 0x20))(iVar6,param_2);
          fVar7 = fVar7 + (float10)(float)piVar2[0x16];
        }
      }
      if (fVar7 < (float10)(float)piVar2[0x16]) goto LAB_005a624a;
    }
LAB_005a62c5:
    iVar6 = _ftol_nocw();
    if (0 < -2 - iVar6) {
      in_EAX = in_EAX + (-2 - iVar6);
    }
    in_EAX = in_EAX + 1;
    if (*(int *)(iVar4 + 4) <= in_EAX) {
      return local_8;
    }
  } while( true );
}


// ==== 0x5a6310 FUN_005a6310

void __fastcall
FUN_005a6310(uint param_1,int param_2,int param_3,char *param_4,float param_5,float param_6,
            int param_7,char param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int in_EAX;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_34;
  uint local_2c;
  undefined1 local_20 [28];
  
  iVar1 = *(char *)(in_EAX + 0x388) * 0x38 + 8 + in_EAX;
  uVar7 = *(int *)(param_3 + 4) - 1;
  local_2c = ((int)param_1 < 1) - 1 & param_1;
  if ((int)uVar7 < (int)local_2c) {
    local_2c = uVar7;
  }
  uVar8 = param_2 - 2U;
  if ((int)(param_2 - 2U) <= (int)local_2c) {
    uVar8 = local_2c;
  }
  if ((int)uVar7 < (int)uVar8) {
    uVar8 = uVar7;
  }
  fVar2 = *(float *)(*(int *)(param_3 + 8 + local_2c * 4) + 0x58);
  piVar9 = (int *)(param_3 + 8 + local_2c * 4);
  if (0 < (int)((uVar8 - local_2c) + 1)) {
    fVar4 = *(float *)(*(int *)(param_3 + 8 + uVar8 * 4) + 0x58) - fVar2;
    local_34 = 0.0;
    fVar5 = ABS(fVar4);
    if (fVar5 < 0.001 == (fVar5 == 0.001)) {
      local_34 = (param_6 - param_5) / fVar4;
    }
    else {
      param_5 = param_6;
    }
    if ((int)local_2c <= (int)uVar8) {
      while (*param_4 < '\x14') {
        iVar3 = *piVar9;
        local_50 = (*(float *)(iVar3 + 0x58) - fVar2) * local_34 + param_5;
        if (param_6 <= param_5) {
          if (local_50 <= param_6) {
            local_50 = param_6;
          }
        }
        else if (param_6 <= local_50) {
          local_50 = param_6;
        }
        if ((param_7 < 0) || (4 < param_7)) {
          if ((param_7 < 0xb) || (0x10 < param_7)) {
            local_4c = 0.0;
          }
          else {
            local_4c = *(float *)(iVar3 + -8 + param_7 * 4);
          }
        }
        else {
          local_4c = *(float *)(iVar3 + 0x20);
        }
        local_4c = local_4c + *(float *)(iVar1 + 8);
        if ((param_7 < 0) || (4 < param_7)) {
          if ((param_7 < 0xb) || (0x10 < param_7)) {
            local_44 = 0.0;
          }
          else {
            local_44 = *(float *)(iVar3 + 0x14 + param_7 * 4);
          }
        }
        else {
          local_44 = *(float *)(iVar3 + 0x3c);
        }
        local_44 = local_44 - *(float *)(iVar1 + 8);
        if (param_8 != '\0') {
          local_4c = DAT_00700638 + local_4c;
          local_44 = local_44 - DAT_00700638;
        }
        if (0.0 <= local_4c) {
          local_4c = 0.0;
        }
        if (local_44 <= 0.0) {
          local_44 = 0.0;
        }
        if (local_50 <= local_4c) {
          local_48 = local_4c;
        }
        else {
          local_48 = local_50;
        }
        if (local_48 <= local_44) {
          local_44 = local_48;
        }
        FUN_005a7270(local_20,*(float *)(iVar3 + 0x58),local_44,param_7);
        FUN_004594d0((int)*(char *)(*piVar9 + 0x5c),*(undefined2 *)(*piVar9 + 0x5e),param_7,1);
        if ((param_4[0x1b1] == '\0') && (local_44 == local_50)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        param_4[0x1b1] = cVar6;
        local_2c = local_2c + 1;
        piVar9 = piVar9 + 1;
        if ((int)uVar8 < (int)local_2c) {
          return;
        }
      }
    }
  }
  return;
}


// ==== 0x5a65b0 FUN_005a65b0

int FUN_005a65b0(undefined4 param_1,float *param_2,float *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  float10 fVar7;
  
  if (*(int *)(in_EAX + 4) < 1) {
    *param_2 = 0.0;
    *param_3 = 0.0;
    return 0;
  }
  piVar5 = (int *)(in_EAX + 8);
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 4)) {
    do {
      piVar2 = (int *)*piVar5;
      fVar6 = (float10)0.0;
      cVar1 = (char)piVar2[0x17];
      if ((cVar1 != -1) && (*(short *)((int)piVar2 + 0x5e) != -1)) {
        if (cVar1 < 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (&DAT_0077af30)[cVar1];
        }
        iVar3 = *(short *)((int)piVar2 + 0x5e) * 0x88 + 0x27c + iVar3;
        if (iVar3 != 0) {
          fVar6 = (float10)(**(code **)(*piVar2 + 0x20))(iVar3,param_1);
          fVar6 = fVar6 + (float10)(float)piVar2[0x16];
        }
      }
      if (fVar6 < (float10)(float)piVar2[0x16]) {
        fVar6 = (float10)FUN_005a7560(param_1);
        goto LAB_005a66ca;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < *(int *)(in_EAX + 4));
  }
  fVar6 = (float10)0.0;
  piVar5 = *(int **)(in_EAX + 4 + *(int *)(in_EAX + 4) * 4);
  cVar1 = (char)piVar5[0x17];
  iVar4 = *(int *)(in_EAX + 4) + -1;
  if ((cVar1 != -1) && (*(short *)((int)piVar5 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (&DAT_0077af30)[cVar1];
    }
    iVar3 = *(short *)((int)piVar5 + 0x5e) * 0x88 + 0x27c + iVar3;
    if (iVar3 != 0) {
      fVar6 = (float10)(**(code **)(*piVar5 + 0x20))(iVar3,param_1);
      fVar6 = fVar6 + (float10)(float)piVar5[0x16];
    }
  }
LAB_005a66ca:
  fVar7 = (float10)FUN_005a7390(param_1,param_4);
  *param_2 = (float)fVar6;
  *param_3 = (float)fVar7;
  return iVar4;
}


// ==== 0x5a6700 FUN_005a6700

undefined4 __thiscall
FUN_005a6700(int param_1,undefined4 *param_2,float *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  int local_4;
  
  uVar1 = param_4;
  param_4 = 0;
  local_4 = param_1;
  uVar2 = FUN_005a65b0(param_1 + 0x60,&param_4,&local_4,uVar1);
  fVar3 = (float10)FUN_005a7390(param_1 + 0x60,uVar1);
  *param_2 = param_4;
  *param_3 = (float)fVar3;
  return uVar2;
}


// ==== 0x5a6760 FUN_005a6760

int FUN_005a6760(int param_1,int param_2,undefined4 *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EDI;
  float10 fVar3;
  
  iVar1 = param_1;
  iVar2 = *(int *)(*(int *)(param_2 + 0x1d4) + 0x1c);
  param_2 = 0;
  if (*(int *)(iVar2 + 0xe4) != 0) {
    FUN_005791c0();
  }
  iVar2 = FUN_005a65b0(iVar2 + 0x40,&param_2,&param_1,unaff_EDI);
  fVar3 = (float10)FUN_005a74f0(*(undefined4 *)(iVar1 + 8 + iVar2 * 4),param_2,unaff_EDI);
  *param_3 = param_2;
  *param_4 = (float)fVar3;
  return iVar2;
}


// ==== 0x5a67d0 FUN_005a67d0

int __thiscall FUN_005a67d0(int param_1,float param_2,uint param_3)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  float local_4;
  
  iVar3 = -1;
  local_4 = 99999.0;
  if (in_EAX < *(int *)(param_1 + 4)) {
    piVar4 = (int *)(param_1 + 8 + in_EAX * 4);
    do {
      iVar1 = *piVar4;
      if (((((param_3 & 1) == 0) || (param_2 <= *(float *)(iVar1 + 0x58))) &&
          (((param_3 & 2) == 0 ||
           (*(float *)(iVar1 + 0x58) < param_2 != (*(float *)(iVar1 + 0x58) == param_2))))) &&
         ((fVar2 = ABS(*(float *)(iVar1 + 0x58) - param_2), iVar3 == -1 || (fVar2 < local_4)))) {
        iVar3 = in_EAX;
        local_4 = fVar2;
      }
      in_EAX = in_EAX + 1;
      piVar4 = piVar4 + 1;
    } while (in_EAX < *(int *)(param_1 + 4));
  }
  return iVar3;
}


// ==== 0x5a6860 FUN_005a6860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_005a6860(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  float local_40;
  float local_3c;
  float local_30;
  float local_2c;
  float local_20;
  float local_1c;
  
  iVar1 = *(int *)(in_EAX + 4);
  iVar6 = iVar1 - param_1;
  if (iVar6 < 2) {
    return (float10)0.0;
  }
  local_40 = *(float *)(in_EAX + 8 + param_1 * 4);
  piVar9 = (int *)(in_EAX + 8 + param_1 * 4);
  if (0.0 <= param_3) {
    while ((iVar8 = -1, param_1 < iVar1 &&
           (iVar8 = param_1,
           *(float *)(*piVar9 + 0x58) - *(float *)((int)local_40 + 0x58) < param_3 * _K_HALF))) {
      param_1 = param_1 + 1;
      piVar9 = piVar9 + 1;
    }
    iVar7 = iVar8 + 1;
    if (iVar7 < iVar1) {
      piVar9 = (int *)(in_EAX + 8 + iVar7 * 4);
      do {
        if (param_3 <= *(float *)(*piVar9 + 0x58) - *(float *)((int)local_40 + 0x58)) {
          if (iVar7 != -1) goto LAB_005a6922;
          break;
        }
        iVar7 = iVar7 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar7 < iVar1);
    }
  }
  iVar8 = iVar6 / 2;
  iVar7 = iVar1 + -1;
LAB_005a6922:
  iVar1 = *(int *)(in_EAX + 8 + iVar8 * 4);
  iVar6 = *(int *)(in_EAX + 8 + iVar7 * 4);
  FUN_005a7270(&local_40,*(undefined4 *)((int)local_40 + 0x58),0,param_2);
  FUN_005a7270(&local_30,*(undefined4 *)(iVar1 + 0x58),0,param_2);
  FUN_005a7270(&local_20,*(undefined4 *)(iVar6 + 0x58),0,param_2);
  local_40 = local_40 - local_30;
  local_3c = local_3c - local_2c;
  local_30 = local_30 - local_20;
  local_2c = local_2c - local_1c;
  fVar2 = SQRT(local_3c * local_3c + local_40 * local_40);
  if (fVar2 == 0.0) {
    local_3c = 0.0;
    fVar2 = _K_ONE;
  }
  else {
    fVar2 = _K_ONE / fVar2;
    local_3c = fVar2 * local_3c;
    fVar2 = fVar2 * local_40;
  }
  fVar3 = SQRT(local_2c * local_2c + local_30 * local_30);
  if (fVar3 == 0.0) {
    local_2c = 0.0;
    fVar3 = _K_ONE;
  }
  else {
    fVar3 = _K_ONE / fVar3;
    local_2c = fVar3 * local_2c;
    fVar3 = fVar3 * local_30;
  }
  fVar5 = local_3c * 0.0 - local_2c * 0.0;
  fVar4 = fVar3 * 0.0 - fVar2 * 0.0;
  fVar2 = local_2c * fVar2 - local_3c * fVar3;
  fVar3 = SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4);
  if (0.0 <= fVar2) {
    return (float10)fVar3;
  }
  return -(float10)fVar3;
}


// ==== 0x5a6b00 FUN_005a6b00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005a6b00(float param_1)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  undefined4 unaff_EBX;
  int *piVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  iVar3 = 0;
  if (0 < *(int *)(in_EAX + 4)) {
    piVar4 = (int *)(in_EAX + 8);
    while (*(float *)(*piVar4 + 0x58) <= param_1) {
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
      if (*(int *)(in_EAX + 4) <= iVar3) {
        fVar5 = (float10)FUN_005a7690();
        return fVar5;
      }
    }
    if (iVar3 == 0) {
      fVar5 = (float10)FUN_005a7690();
      return fVar5;
    }
    if (iVar3 != -1) {
      iVar1 = *(int *)(in_EAX + 8 + iVar3 * 4);
      fVar2 = (*(float *)(iVar1 + 0x58) - param_1) /
              (*(float *)(iVar1 + 0x58) - *(float *)(*(int *)(in_EAX + 4 + iVar3 * 4) + 0x58));
      fVar5 = (float10)FUN_005a7690(unaff_EBX);
      fVar6 = (float10)_K_ONE;
      fVar7 = (float10)FUN_005a7690(unaff_EBX);
      return fVar7 * (float10)fVar2 + (float10)(float)((fVar6 - (float10)fVar2) * fVar5);
    }
  }
  fVar5 = (float10)FUN_005a7690();
  return fVar5;
}


// ==== 0x5a6bc0 FUN_005a6bc0

float10 FUN_005a6bc0(float param_1,float param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  float fStack_4;
  
  iVar4 = (int)param_1;
  *param_3 = 0x47c34f80;
  piVar6 = (int *)((int)param_1 + 4);
  param_1 = 99999.0;
  if (in_EAX < *piVar6 + -1) {
    piVar6 = (int *)(iVar4 + 0xc + in_EAX * 4);
    do {
      piVar2 = (int *)piVar6[-1];
      piVar3 = (int *)*piVar6;
      if (param_2 < (float)piVar2[0x16]) break;
      cVar1 = (char)piVar3[0x17];
      if ((cVar1 == -1) || (*(short *)((int)piVar3 + 0x5e) == -1)) {
LAB_005a6c4a:
        fStack_4 = 0.0;
      }
      else {
        if (cVar1 < 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = (&DAT_0077af30)[cVar1];
        }
        iVar5 = *(short *)((int)piVar3 + 0x5e) * 0x88 + 0x27c + iVar5;
        if (iVar5 == 0) goto LAB_005a6c4a;
        fVar7 = (float10)(**(code **)(*piVar3 + 0x18))(iVar5);
        fStack_4 = (float)fVar7;
      }
      cVar1 = (char)piVar2[0x17];
      if ((cVar1 == -1) || (*(short *)((int)piVar2 + 0x5e) == -1)) {
LAB_005a6c93:
        fVar7 = (float10)0.0;
      }
      else {
        if (cVar1 < 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = (&DAT_0077af30)[cVar1];
        }
        iVar5 = *(short *)((int)piVar2 + 0x5e) * 0x88 + 0x27c + iVar5;
        if (iVar5 == 0) goto LAB_005a6c93;
        fVar7 = (float10)(**(code **)(*piVar2 + 0x18))(iVar5);
      }
      if ((float10)fStack_4 - fVar7 < (float10)param_1) {
        param_1 = (float)((float10)fStack_4 - fVar7);
        *param_3 = piVar2[0x16];
      }
      in_EAX = in_EAX + 1;
      piVar6 = piVar6 + 1;
    } while (in_EAX < *(int *)(iVar4 + 4) + -1);
  }
  return (float10)param_1;
}


// ==== 0x5a6ce0 FUN_005a6ce0

undefined4 FUN_005a6ce0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = FUN_005a67d0(param_1,1);
  iVar2 = 0;
  if (iVar1 != -1) {
    iVar2 = *(int *)(unaff_ESI + 4) - iVar1;
  }
  if ((*(char *)(unaff_ESI + 0xbc) != '\0') && (iVar2 < 2)) {
    return 1;
  }
  return 0;
}


// ==== 0x5a6d20 FUN_005a6d20

/* WARNING: Removing unreachable block (ram,0x005a6dd5) */

int __fastcall FUN_005a6d20(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
  iVar6 = *(int *)(param_1 + 8 + in_EAX * 4);
  cVar1 = *(char *)(iVar6 + 0x5c);
  local_4 = 0;
  if ((cVar1 == -1) || (sVar2 = *(short *)(iVar6 + 0x5e), sVar2 == -1)) {
    iVar6 = 0;
  }
  else {
    if (cVar1 < 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (&DAT_0077af30)[cVar1];
    }
    iVar6 = sVar2 * 0x88 + 0x27c + iVar6;
  }
  if ((*(int *)(param_1 + 4) + -1 <= in_EAX) ||
     (iVar3 = *(int *)(param_1 + 0xc + in_EAX * 4), *(char *)(iVar3 + 0x60) == '\0')) {
    return 0;
  }
  iVar8 = 0;
  do {
    iVar4 = 0;
    do {
      if (*(char *)(iVar4 + 0x81 + iVar6) == -1) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    if (iVar4 <= iVar8) {
      return local_4;
    }
    if (local_4 != 0) {
      return local_4;
    }
    uVar5 = (uint)*(byte *)(iVar8 + 0x81 + iVar6);
    if (uVar5 == 0xff) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar5 * 0x20 + DAT_00736150;
    }
    cVar1 = *(char *)(iVar3 + 0x5c);
    if (((cVar1 == -1) || (*(short *)(iVar3 + 0x5e) == -1)) || (cVar1 < 0)) {
      iVar7 = 0;
    }
    else {
      iVar7 = (&DAT_0077af30)[cVar1];
    }
    if ((&DAT_0077af30)[*(byte *)(iVar4 + 9)] == iVar7) {
      local_4 = iVar4;
    }
    iVar8 = iVar8 + 1;
  } while( true );
}


// ==== 0x5a6e10 FUN_005a6e10

float10 FUN_005a6e10(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float10 fVar6;
  
  if (param_1[0x2e] == -1) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_1[param_1[0x2e] + 2];
  }
  Node_GetIntersection();
  if (iVar5 != 0) {
    fVar1 = *(float *)(iVar5 + 0x58);
    fVar2 = *(float *)(param_2 + 0x10);
    fVar3 = *(float *)(param_2 + 0xc);
    uVar4 = (**(code **)(*param_1 + 4))();
    fVar6 = (float10)FUN_005aab20(uVar4);
    return ((((float10)fVar1 - fVar6) - (float10)12.0) - (float10)fVar2) - (float10)fVar3;
  }
  return (float10)999999.0;
}


// ==== 0x5a6ea0 FUN_005a6ea0

int __fastcall FUN_005a6ea0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = 0x10;
  do {
    if ((iVar2 < 0) || (4 < iVar2)) {
      if ((10 < iVar2) && (iVar2 < 0x11)) {
        cVar3 = *(char *)(iVar2 + 0xa6 + param_2);
        goto LAB_005a6ed2;
      }
    }
    else {
      cVar3 = *(char *)(param_2 + 0xb0);
LAB_005a6ed2:
      if (cVar3 != '\0') {
        return iVar2;
      }
    }
    iVar1 = iVar2 + -0xc;
    iVar2 = iVar2 + -1;
    if (iVar1 < 0) {
      return 0xff;
    }
  } while( true );
}


// ==== 0x5a6ef0 FUN_005a6ef0

void __thiscall FUN_005a6ef0(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  float10 fVar2;
  float10 fVar3;
  
  bVar1 = true;
  if (param_1 < *(int *)(param_2 + 4) + -1) {
    do {
      if (!bVar1) {
        return;
      }
      fVar2 = (float10)FUN_005a7690(param_3);
      fVar3 = (float10)FUN_005a7690(param_3);
      bVar1 = fVar3 < (float10)(float)fVar2 != (fVar3 == (float10)(float)fVar2);
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)(param_2 + 4) + -1);
  }
  return;
}


// ==== 0x5a6f50 FUN_005a6f50

bool FUN_005a6f50(int *param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x15) == '\0') {
    iVar1 = *param_1;
    *param_1 = iVar1 + 1;
    return iVar1 + 1 < (int)*(short *)(param_2 + 0x10);
  }
  *param_1 = *param_1 + -1;
  return -1 < *param_1;
}


// ==== 0x5a6f80 FUN_005a6f80

void __thiscall FUN_005a6f80(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float unaff_retaddr;
  
  iVar4 = (**(code **)(*param_1 + 8))(param_3);
  if ((param_3 < 0) || (4 < param_3)) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = 3.0;
  }
  fVar3 = (float)((int)*(short *)(param_3 + 0x3c + iVar4 * 2) << 8) * 1.5258789e-05;
  fVar2 = fVar1 - (*(float *)(param_3 + 0x24) + fVar3);
  fVar1 = (*(float *)(param_3 + 0x28) - fVar3) - fVar1;
  if (fVar2 < unaff_retaddr) {
    fVar2 = unaff_retaddr;
  }
  if (fVar2 <= fVar1) {
    *param_2 = fVar2;
    return;
  }
  *param_2 = fVar1;
  return;
}


// ==== 0x5a7020 FUN_005a7020

bool FUN_005a7020(int *param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x15) == '\0') {
    *param_1 = *param_1 + -1;
    return -1 < *param_1;
  }
  iVar1 = *param_1;
  *param_1 = iVar1 + 1;
  return iVar1 + 1 < (int)*(short *)(param_2 + 0x10);
}


// ==== 0x5a7050 FUN_005a7050

void __thiscall FUN_005a7050(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float unaff_retaddr;
  
  iVar4 = (**(code **)(*param_1 + 8))(param_3);
  if ((param_3 < 0) || (4 < param_3)) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = 3.0;
  }
  fVar3 = (float)((int)*(short *)(param_3 + 0x3c + iVar4 * 2) << 8) * 1.5258789e-05;
  fVar2 = fVar1 - (*(float *)(param_3 + 0x28) + fVar3);
  fVar1 = (*(float *)(param_3 + 0x24) - fVar3) - fVar1;
  if (fVar2 < unaff_retaddr) {
    fVar2 = unaff_retaddr;
  }
  if (fVar2 <= fVar1) {
    *param_2 = fVar2;
    return;
  }
  *param_2 = fVar1;
  return;
}


// ==== 0x5a70f0 FUN_005a70f0

void FUN_005a70f0(void)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  FUN_00571ea0(0,"FuturePoint");
  FUN_00571c20(unaff_ESI,in_EAX + 0x5c,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x5e,2,2,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x58,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x60,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 4,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x20,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x3c,4,0xffffffff,0);
  iVar3 = in_EAX + 0x24;
  iVar2 = 6;
  do {
    FUN_00571c20(unaff_ESI,iVar3 + -0x1c,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,iVar3,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,iVar3 + 0x1c,4,0xffffffff,0);
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar2 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar2 + 0x58 + unaff_ESI);
  cVar1 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5a71f0 FUN_005a71f0

float10 __fastcall FUN_005a71f0(int param_1,int param_2,float param_3)

{
  if (param_3 <= 0.0) {
    if ((-1 < param_1) && (param_1 < 5)) {
      return (float10)*(float *)(param_2 + 0x20) - (float10)param_3;
    }
    if ((10 < param_1) && (param_1 < 0x11)) {
      return (float10)*(float *)(param_2 + -8 + param_1 * 4) - (float10)param_3;
    }
    return (float10)0.0 - (float10)param_3;
  }
  if ((-1 < param_1) && (param_1 < 5)) {
    return (float10)param_3 - (float10)*(float *)(param_2 + 0x3c);
  }
  if ((10 < param_1) && (param_1 < 0x11)) {
    return (float10)param_3 - (float10)*(float *)(param_2 + 0x14 + param_1 * 4);
  }
  return (float10)param_3 - (float10)0.0;
}


// ==== 0x5a7270 FUN_005a7270

void FUN_005a7270(undefined4 *param_1,float param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  undefined4 unaff_retaddr;
  
  cVar2 = (char)unaff_ESI[0x17];
  if ((cVar2 != -1) && (*(short *)((int)unaff_ESI + 0x5e) != -1)) {
    if (cVar2 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (&DAT_0077af30)[cVar2];
    }
    iVar3 = *(short *)((int)unaff_ESI + 0x5e) * 0x88 + 0x27c + iVar3;
    if (iVar3 != 0) {
      iVar4 = (**(code **)(*unaff_ESI + 0x10))(param_4);
      if ((param_4 < 0) || (4 < param_4)) {
        if ((param_4 < 0xb) || (0x10 < param_4)) {
          fVar1 = 0.0;
        }
        else {
          fVar1 = (float)unaff_ESI[param_4 + -9];
        }
      }
      else {
        fVar1 = (float)unaff_ESI[1];
      }
      (**(code **)(*unaff_ESI + 0x2c))
                (iVar3,unaff_retaddr,(float)param_1 - (float)unaff_ESI[0x16],
                 (float)((int)*(short *)(iVar3 + 0x3c + iVar4 * 2) << 8) * 1.5258789e-05 + fVar1 +
                 param_2);
      return;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== 0x5a7340 FUN_005a7340

undefined4 __fastcall FUN_005a7340(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = (char)param_1[0x17];
  if ((cVar1 != -1) && (*(short *)((int)param_1 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    iVar2 = *(short *)((int)param_1 + 0x5e) * 0x88 + 0x27c + iVar2;
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*param_1 + 0x14))(iVar2);
      return uVar3;
    }
  }
  return 0;
}


// ==== 0x5a7390 FUN_005a7390

float10 __thiscall FUN_005a7390(float param_1,float param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  float10 fVar4;
  
  cVar1 = (char)unaff_ESI[0x17];
  fVar4 = (float10)0.0;
  if ((cVar1 != -1) && (*(short *)((int)unaff_ESI + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    iVar2 = *(short *)((int)unaff_ESI + 0x5e) * 0x88 + 0x27c + iVar2;
    if (iVar2 != 0) {
      iVar3 = iVar2;
      fVar4 = (float10)(**(code **)(*unaff_ESI + 0x28))(iVar2);
      iVar3 = (**(code **)(*unaff_ESI + 0x10))(param_3,iVar3,param_2,(float)fVar4);
      fVar4 = (float10)param_2 -
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
              (float10)param_1);
    }
  }
  return fVar4;
}


// ==== 0x5a7450 FUN_005a7450

float10 __fastcall FUN_005a7450(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float unaff_ESI;
  float10 fVar4;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)0.0;
  if ((cVar1 != -1) && (*(short *)((int)param_1 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    iVar2 = *(short *)((int)param_1 + 0x5e) * 0x88 + 0x27c + iVar2;
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*param_1 + 0x10))();
      fVar4 = -((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
               (float10)unaff_ESI);
    }
  }
  return fVar4;
}


// ==== 0x5a74f0 FUN_005a74f0

void FUN_005a74f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_EAX;
  
  if (*(int *)(*(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  FUN_00578730();
  FUN_005a7390(iVar1 + 0x40,param_3);
  return;
}


// ==== 0x5a7560 FUN_005a7560

float10 FUN_005a7560(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  float10 fVar3;
  
  cVar1 = (char)unaff_ESI[0x17];
  fVar3 = (float10)0.0;
  if ((cVar1 != -1) && (*(short *)((int)unaff_ESI + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    iVar2 = *(short *)((int)unaff_ESI + 0x5e) * 0x88 + 0x27c + iVar2;
    if (iVar2 != 0) {
      fVar3 = (float10)(**(code **)(*unaff_ESI + 0x20))(iVar2,param_1);
      fVar3 = fVar3 + (float10)(float)unaff_ESI[0x16];
    }
  }
  return fVar3;
}


// ==== 0x5a75c0 FUN_005a75c0

undefined4 FUN_005a75c0(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  int unaff_retaddr;
  
  if ((unaff_ESI < 0) || (bVar3 = true, 4 < unaff_ESI)) {
    bVar3 = false;
  }
  if ((unaff_ESI < 0xb) || (0x10 < unaff_ESI)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((!bVar3) && (!bVar2)) {
    return 0;
  }
  iVar4 = (**(code **)(*unaff_EDI + 0x10))();
  cVar1 = (char)unaff_EDI[0x17];
  if (((cVar1 == -1) || (*(short *)((int)unaff_EDI + 0x5e) == -1)) || (cVar1 < 0)) {
    iVar6 = 0;
  }
  else {
    iVar6 = (&DAT_0077af30)[cVar1];
  }
  if ((char)((uint)unaff_EBX >> 0x18) == '\0') {
    if (!bVar2) goto LAB_005a764a;
    cVar1 = *(char *)(iVar4 + iVar6 + 0x265);
  }
  else {
    pcVar5 = (char *)((iVar4 + 1) * 0x34 + iVar6);
    if (*pcVar5 != '\0') goto LAB_005a764a;
    cVar1 = pcVar5[1];
  }
  if (cVar1 == '\0') {
    return 0;
  }
LAB_005a764a:
  if ((*(int *)(unaff_retaddr + 0x24) != 2) && (bVar2)) {
    if ((unaff_ESI < 0) || (4 < unaff_ESI)) {
      if (unaff_ESI < 0xb) {
        return 0;
      }
      if (0x10 < unaff_ESI) {
        return 0;
      }
      cVar1 = *(char *)(unaff_EDI[0x19] + unaff_ESI + 0xa6);
    }
    else {
      cVar1 = *(char *)(unaff_EDI[0x19] + 0xb0);
    }
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}


// ==== 0x5a7690 FUN_005a7690

float10 __thiscall FUN_005a7690(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = (char)param_1[0x17];
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
      return (float10)((uint)*(byte *)(iVar3 + 0x6a + iVar2) << 0x10) * (float10)1.5258789e-05;
    }
  }
  return (float10)0.0;
}


// ==== 0x5a7700 FUN_005a7700

undefined4 FUN_005a7700(int param_1,int param_2)

{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  bool bVar4;
  int in_EAX;
  
  if (((in_EAX < 0) || (4 < in_EAX)) && ((in_EAX < 0xb || (0x10 < in_EAX)))) {
    return 0;
  }
  cVar3 = FUN_005a75c0(param_2);
  if (cVar3 != '\0') {
    if ((param_1 < 0xb) || (0x10 < param_1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((in_EAX < 0xb) || (0x10 < in_EAX)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (((!bVar2) || (!bVar4)) ||
       ((*(short *)(DAT_00736174 + 0x6c) != 0x4b6 && (*(short *)(DAT_00736174 + 0x6c) != 0x4be)))) {
      return 1;
    }
    uVar1 = *(undefined4 *)(param_2 + 0x814);
    (**(code **)(**(int **)(param_2 + 0x2c) + 0x40))();
    if (in_EAX < param_1) {
      if (param_1 < in_EAX + 1) {
        return 1;
      }
      while( true ) {
        param_1 = param_1 + -1;
        cVar3 = FUN_005a7820(uVar1);
        if (cVar3 == '\0') break;
        if (param_1 < in_EAX + 1) {
          return 1;
        }
      }
    }
    else {
      do {
        if (in_EAX + -1 < param_1) {
          return 1;
        }
        param_1 = param_1 + 1;
        cVar3 = FUN_005a7820(uVar1);
      } while (cVar3 != '\0');
    }
  }
  return 0;
}


// ==== 0x5a7820 FUN_005a7820

undefined4 __fastcall FUN_005a7820(undefined4 param_1,int param_2,float param_3)

{
  int in_EAX;
  int *piVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX == 0x4b6) {
    piVar1 = &DAT_006ee1e8;
    do {
      if (((piVar1[4] == param_2) && (*piVar1 == unaff_EDI)) &&
         ((piVar1[1] == unaff_ESI &&
          (((float)piVar1[2] < param_3 != ((float)piVar1[2] == param_3) &&
           (param_3 <= (float)piVar1[3])))))) {
        return 0;
      }
      piVar1 = piVar1 + 5;
    } while ((int)piVar1 < 0x6ee2d8);
  }
  else if (in_EAX == 0x4be) {
    piVar1 = &DAT_006ee2d8;
    while ((((piVar1[4] != param_2 || (*piVar1 != unaff_EDI)) || (piVar1[1] != unaff_ESI)) ||
           (((float)piVar1[2] < param_3 == ((float)piVar1[2] == param_3) ||
            ((float)piVar1[3] < param_3))))) {
      piVar1 = piVar1 + 5;
      if (0x6ee3c7 < (int)piVar1) {
        return 1;
      }
    }
    return 0;
  }
  return 1;
}


// ==== 0x5a78b0 FUN_005a78b0

float10 __thiscall FUN_005a78b0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float unaff_retaddr;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)0.0;
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
      fVar4 = (float10)*(float *)(iVar2 + 0x28) -
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
              (float10)unaff_retaddr);
    }
  }
  return fVar4;
}


// ==== 0x5a7960 FUN_005a7960

float10 __thiscall FUN_005a7960(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float unaff_retaddr;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)0.0;
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
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
              (float10)unaff_retaddr);
    }
  }
  return fVar4;
}


// ==== 0x5a7a10 FUN_005a7a10

float10 __thiscall FUN_005a7a10(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float unaff_retaddr;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)0.0;
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
      fVar4 = (float10)*(float *)(iVar2 + 0x24) -
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
              (float10)unaff_retaddr);
    }
  }
  return fVar4;
}


// ==== 0x5a7ac0 FUN_005a7ac0

float10 __thiscall FUN_005a7ac0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float unaff_retaddr;
  
  cVar1 = (char)param_1[0x17];
  fVar4 = (float10)0.0;
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
      fVar4 = -(float10)*(float *)(iVar2 + 0x28) -
              ((float10)((int)*(short *)(iVar2 + 0x3c + iVar3 * 2) << 8) * (float10)1.5258789e-05 +
              (float10)unaff_retaddr);
    }
  }
  return fVar4;
}


// ==== 0x5a7b70 FUN_005a7b70

void __fastcall FUN_005a7b70(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  DAT_006ee1e4 = param_3;
  DAT_00732324 = param_2;
  DAT_00732328 = param_1;
  DAT_00733730 = in_EAX;
  if (0 < (int)param_3) {
    puVar5 = &DAT_00731f20;
    for (uVar2 = param_3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    puVar5 = &DAT_00731b20;
    for (uVar2 = param_3 & 0x3fffffff; piVar4 = (int *)&DAT_00732338, uVar2 != 0; uVar2 = uVar2 - 1)
    {
      *puVar5 = (int)(0x10000 / (longlong)(int)param_3);
      puVar5 = puVar5 + 1;
    }
    do {
      iVar1 = (iVar3 << 0xc) / (int)param_3;
      iVar3 = iVar3 + 1;
      piVar4[1] = iVar1;
      *piVar4 = iVar1;
      piVar4[-1] = iVar1;
      piVar4[-2] = iVar1;
      piVar4 = piVar4 + 5;
    } while (iVar3 < (int)param_3);
  }
  return;
}


// ==== 0x5a7bf0 FUN_005a7bf0

void FUN_005a7bf0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = DAT_006ee1e4;
  iVar3 = 0;
  if (0 < DAT_006ee1e4) {
    piVar4 = &DAT_00732340;
    piVar2 = (int *)&DAT_00732334;
    do {
      piVar2[-1] = piVar2[-1] >> 4;
      *piVar2 = *piVar2 >> 4;
      piVar2[1] = piVar2[1] >> 4;
      piVar2[2] = piVar2[2] >> 4;
      *piVar4 = iVar3;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 5;
      piVar4 = piVar4 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}


// ==== 0x5a7c30 FUN_005a7c30

void FUN_005a7c30(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_c;
  int local_8;
  
  iVar7 = 0;
  local_c = 0;
  local_8 = 0;
  if (0 < DAT_006ee1e4) {
    piVar5 = (int *)&DAT_00732348;
    iVar2 = 0;
    do {
      iVar4 = piVar5[-5];
      iVar1 = iVar2 + 1;
      iVar6 = iVar2;
      piVar8 = piVar5;
      for (iVar3 = iVar1; iVar3 < DAT_006ee1e4; iVar3 = iVar3 + 1) {
        if (*piVar8 < iVar4) {
          iVar6 = iVar3;
          iVar4 = *piVar8;
        }
        piVar8 = piVar8 + 5;
        iVar7 = local_c;
      }
      iVar3 = iVar6 * 0x14;
      if (iVar2 != iVar6) {
        iVar7 = *(int *)(&DAT_00732330 + iVar3);
        *(int *)(&DAT_00732330 + iVar3) = piVar5[-6];
        piVar5[-6] = iVar7;
        iVar7 = *(int *)(&DAT_00732334 + iVar3);
        *(int *)(&DAT_00732334 + iVar3) = piVar5[-5];
        piVar5[-5] = iVar7;
        iVar7 = *(int *)(&DAT_00732338 + iVar3);
        *(int *)(&DAT_00732338 + iVar3) = piVar5[-4];
        piVar5[-4] = iVar7;
        iVar7 = *(int *)(&DAT_0073233c + iVar3);
        *(int *)(&DAT_0073233c + iVar3) = piVar5[-3];
        piVar5[-3] = iVar7;
        iVar7 = (&DAT_00732340)[iVar6 * 5];
        (&DAT_00732340)[iVar6 * 5] = piVar5[-2];
        piVar5[-2] = iVar7;
        iVar7 = local_c;
      }
      if (iVar4 != iVar7) {
        iVar3 = iVar7 + 1;
        (&DAT_007316a0)[iVar7] = local_8 + iVar2 >> 1;
        iVar7 = iVar4;
        local_c = iVar4;
        local_8 = iVar2;
        if (iVar3 < iVar4) {
          piVar8 = &DAT_007316a0 + iVar3;
          for (iVar4 = iVar4 - iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar8 = iVar2;
            piVar8 = piVar8 + 1;
          }
        }
      }
      piVar5 = piVar5 + 5;
      iVar2 = iVar1;
    } while (iVar1 < DAT_006ee1e4);
  }
  iVar1 = DAT_006ee1e4;
  iVar2 = iVar7 + 1;
  (&DAT_007316a0)[iVar7] = DAT_006ee1e4 + -1 + local_8 >> 1;
  if (iVar2 < 0x100) {
    piVar5 = &DAT_007316a0 + iVar2;
    for (iVar7 = 0x100 - iVar2; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar5 = iVar1 + -1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}


// ==== 0x5a7d60 FUN_005a7d60

undefined4 FUN_005a7d60(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  iVar3 = 1000;
  iVar4 = (&DAT_007316a0)[param_2];
  iVar6 = (&DAT_007316a0)[param_2] + -1;
  do {
    iVar5 = iVar6;
    if (iVar4 < DAT_006ee1e4) {
      iVar6 = iVar4 * 0x14;
      iVar1 = *(int *)(&DAT_00732334 + iVar4 * 0x14) - param_2;
      iVar7 = DAT_006ee1e4;
      if (iVar1 < iVar3) {
        iVar7 = iVar4 + 1;
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        iVar2 = *(int *)(&DAT_00732330 + iVar6) - param_1;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 + iVar2 < iVar3) {
          iVar8 = *(int *)(&DAT_00732338 + iVar6) - param_3;
          if (iVar8 < 0) {
            iVar8 = -iVar8;
          }
          iVar8 = iVar1 + iVar2 + iVar8;
          if (iVar8 < iVar3) {
            iVar6 = *(int *)(&DAT_0073233c + iVar6) - param_4;
            if (iVar6 < 0) {
              iVar6 = -iVar6;
            }
            iVar8 = iVar8 + iVar6;
            if (iVar8 < iVar3) {
              local_4 = (&DAT_00732340)[iVar4 * 5];
              iVar3 = iVar8;
            }
          }
        }
      }
    }
    else {
      iVar7 = iVar4;
      if (iVar5 < 0) {
        return local_4;
      }
    }
    iVar1 = iVar5 * 0x14;
    iVar2 = param_2 - *(int *)(&DAT_00732334 + iVar5 * 0x14);
    iVar4 = iVar7;
    if (iVar2 < iVar3) {
      iVar6 = iVar5 + -1;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      iVar7 = *(int *)(&DAT_00732330 + iVar1) - param_1;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if (iVar2 + iVar7 < iVar3) {
        iVar8 = *(int *)(&DAT_00732338 + iVar1) - param_3;
        if (iVar8 < 0) {
          iVar8 = -iVar8;
        }
        iVar8 = iVar2 + iVar7 + iVar8;
        if (iVar8 < iVar3) {
          iVar7 = *(int *)(&DAT_0073233c + iVar1) - param_4;
          if (iVar7 < 0) {
            iVar7 = -iVar7;
          }
          iVar8 = iVar8 + iVar7;
          if (iVar8 < iVar3) {
            local_4 = (&DAT_00732340)[iVar5 * 5];
            iVar3 = iVar8;
          }
        }
      }
    }
    else {
      iVar6 = -1;
    }
  } while( true );
}


// ==== 0x5a7e70 FUN_005a7e70

int FUN_005a7e70(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = 0x7fffffff;
  iVar8 = 0;
  local_c = 0x7fffffff;
  local_8 = -1;
  local_4 = -1;
  iVar2 = -1;
  if (0 < DAT_006ee1e4) {
    piVar6 = (int *)&DAT_00732338;
    iVar7 = 0;
    do {
      iVar2 = piVar6[-2] - param_1;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      iVar3 = piVar6[-1] - param_2;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      iVar4 = *piVar6 - param_3;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar5 = piVar6[1] - param_4;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      iVar5 = iVar2 + iVar3 + iVar4 + iVar5;
      if (iVar5 < local_c) {
        local_c = iVar5;
        local_8 = iVar8;
      }
      iVar5 = iVar5 - (*(int *)((int)&DAT_00731f20 + iVar7) >> 0xc);
      if (iVar5 < iVar1) {
        iVar1 = iVar5;
        local_4 = iVar8;
      }
      iVar2 = *(int *)((int)&DAT_00731b20 + iVar7) >> 10;
      *(int *)((int)&DAT_00731f20 + iVar7) = iVar2 * 0x400 + *(int *)((int)&DAT_00731f20 + iVar7);
      iVar3 = DAT_006ee1e4;
      *(int *)((int)&DAT_00731b20 + iVar7) = *(int *)((int)&DAT_00731b20 + iVar7) - iVar2;
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 1;
      piVar6 = piVar6 + 5;
      iVar2 = local_8;
    } while (iVar8 < iVar3);
  }
  (&DAT_00731b20)[iVar2] = (&DAT_00731b20)[iVar2] + 0x40;
  (&DAT_00731f20)[iVar2] = (&DAT_00731f20)[iVar2] + -0x10000;
  return local_4;
}


// ==== 0x5a7f70 FUN_005a7f70

void __fastcall FUN_005a7f70(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = in_EAX * 0x14;
  iVar2 = (*(int *)(&DAT_00732330 + in_EAX * 0x14) - param_2) * unaff_EDI;
  *(int *)(&DAT_00732330 + iVar1) =
       *(int *)(&DAT_00732330 + in_EAX * 0x14) - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  iVar2 = (*(int *)(&DAT_00732334 + iVar1) - param_3) * unaff_EDI;
  *(int *)(&DAT_00732334 + iVar1) =
       *(int *)(&DAT_00732334 + iVar1) - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  iVar2 = (*(int *)(&DAT_00732338 + iVar1) - param_4) * unaff_EDI;
  *(int *)(&DAT_00732338 + iVar1) =
       *(int *)(&DAT_00732338 + iVar1) - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  iVar2 = (*(int *)(&DAT_0073233c + iVar1) - param_5) * unaff_EDI;
  *(int *)(&DAT_0073233c + iVar1) =
       *(int *)(&DAT_0073233c + iVar1) - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10);
  return;
}


// ==== 0x5a8000 FUN_005a8000

void __thiscall FUN_005a8000(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  local_10 = in_EAX - param_1;
  if (local_10 < -1) {
    local_10 = -1;
  }
  local_8 = param_1 + in_EAX;
  if (DAT_006ee1e4 < local_8) {
    local_8 = DAT_006ee1e4;
  }
  iVar3 = in_EAX + 1;
  iVar1 = in_EAX + -1;
  local_4 = &DAT_00731aa0;
  piVar4 = (int *)(&DAT_00732338 + iVar1 * 0x14);
  piVar5 = (int *)(&DAT_00732338 + iVar3 * 0x14);
  local_c = iVar1;
  while ((iVar3 < local_8 || (local_10 < iVar1))) {
    local_4 = local_4 + 1;
    iVar2 = *local_4;
    if (iVar3 < local_8) {
      iVar1 = (piVar5[-2] - param_2) * iVar2;
      piVar5[-2] = piVar5[-2] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (piVar5[-1] - param_3) * iVar2;
      piVar5[-1] = piVar5[-1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (*piVar5 - param_4) * iVar2;
      *piVar5 = *piVar5 - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (piVar5[1] - param_5) * iVar2;
      piVar5[1] = piVar5[1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 5;
      iVar1 = local_c;
    }
    if (local_10 < iVar1) {
      iVar1 = (piVar4[-2] - param_2) * iVar2;
      piVar4[-2] = piVar4[-2] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (piVar4[-1] - param_3) * iVar2;
      piVar4[-1] = piVar4[-1] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar1 = (*piVar4 - param_4) * iVar2;
      *piVar4 = *piVar4 - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffffU)) >> 0x12);
      iVar2 = (piVar4[1] - param_5) * iVar2;
      iVar1 = local_c + -1;
      piVar4[1] = piVar4[1] - ((int)(iVar2 + (iVar2 >> 0x1f & 0x3ffffU)) >> 0x12);
      piVar4 = piVar4 + -5;
      local_c = iVar1;
    }
  }
  return;
}


// ==== 0x5a81b0 FUN_005a81b0

int FUN_005a81b0(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  
  DAT_00732320 = (DAT_00732324 + -1) / 3 + 0x1e;
  pbVar1 = DAT_00733730 + DAT_00732328;
  iVar3 = DAT_00732328 / (DAT_00732324 << 2);
  local_2c = DAT_00733730;
  if (iVar3 < 0x65) {
    local_18 = 1;
  }
  else {
    local_18 = iVar3 / 100;
  }
  local_14 = (DAT_006ee1e4 >> 3) << 6;
  iVar5 = local_14 >> 6;
  local_24 = 0x400;
  if (iVar5 < 2) {
    iVar5 = 0;
  }
  iVar6 = 0;
  if (0 < iVar5) {
    do {
      (&DAT_00731aa0)[iVar6] = ((iVar5 * iVar5 - iVar6 * iVar6) * 0x100) / (iVar5 * iVar5) << 10;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  iVar6 = DAT_00732328 / 499;
  if (DAT_00732328 % 499 == 0) {
    iVar6 = DAT_00732328 / 0x1eb;
    if (DAT_00732328 % 0x1eb == 0) {
      iVar6 = DAT_00732328 / 0x1e7;
      local_28 = (-(uint)(DAT_00732328 % 0x1e7 != 0) & 0xffffffc0) + 0x7dc;
    }
    else {
      local_28 = 0x7ac;
    }
  }
  else {
    local_28 = 0x7cc;
  }
  local_1c = 0;
  if (0 < iVar3) {
    do {
      bVar2 = *local_2c;
      iVar6 = (uint)local_2c[3] << 4;
      iVar7 = (uint)local_2c[2] << 4;
      iVar4 = (uint)local_2c[1] << 4;
      FUN_005a7e70((uint)bVar2 << 4,iVar4,iVar7,iVar6);
      FUN_005a7f70(iVar4,iVar7,iVar6);
      if (iVar5 != 0) {
        FUN_005a8000((uint)bVar2 << 4,iVar4,iVar7,iVar6);
      }
      for (local_2c = local_2c + local_28; pbVar1 <= local_2c; local_2c = local_2c + -DAT_00732328)
      {
      }
      local_1c = local_1c + 1;
      iVar6 = local_1c / local_18;
      if (local_1c % local_18 == 0) {
        local_24 = local_24 - local_24 / DAT_00732320;
        iVar6 = (int)((longlong)local_14 * 0x77777777);
        iVar5 = (int)((ulonglong)((longlong)local_14 * 0x77777777) >> 0x20) - local_14;
        local_14 = local_14 + ((iVar5 >> 4) - (iVar5 >> 0x1f));
        iVar5 = local_14 >> 6;
        if (iVar5 < 2) {
          iVar5 = 0;
        }
        iVar4 = 0;
        if (0 < iVar5) {
          do {
            iVar6 = (((iVar5 * iVar5 - iVar4 * iVar4) * 0x100) / (iVar5 * iVar5)) * local_24;
            (&DAT_00731aa0)[iVar4] = iVar6;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar5);
        }
      }
    } while (local_1c < iVar3);
  }
  return iVar6;
}


// ==== 0x5a8400 FUN_005a8400

undefined1 FUN_005a8400(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int *piVar4;
  
  switch(*(undefined4 *)(*in_EAX + 0x24)) {
  case 0x530b82b0:
    iVar3 = 0x6f;
    piVar4 = &DAT_00733738;
    break;
  case 0x530b82b1:
    iVar3 = 0x6f;
    piVar4 = &DAT_007338f4;
    do {
      if (iVar3 == 0) {
        return 1;
      }
      iVar3 = iVar3 + -1;
      iVar2 = *in_EAX;
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      in_EAX = in_EAX + 1;
    } while (iVar1 == iVar2);
    return 0;
  case 0x530b82b2:
    iVar3 = 0x6f;
    piVar4 = &DAT_00733ab0;
    do {
      if (iVar3 == 0) {
        return 1;
      }
      iVar3 = iVar3 + -1;
      iVar2 = *in_EAX;
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      in_EAX = in_EAX + 1;
    } while (iVar1 == iVar2);
    return 0;
  case 0x530b82b3:
    iVar3 = 0x6f;
    piVar4 = &DAT_00733c6c;
    do {
      if (iVar3 == 0) {
        return 1;
      }
      iVar3 = iVar3 + -1;
      iVar2 = *in_EAX;
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      in_EAX = in_EAX + 1;
    } while (iVar1 == iVar2);
    return 0;
  default:
    return 0;
  }
  do {
    if (iVar3 == 0) {
      return 1;
    }
    iVar3 = iVar3 + -1;
    iVar2 = *in_EAX;
    iVar1 = *piVar4;
    piVar4 = piVar4 + 1;
    in_EAX = in_EAX + 1;
  } while (iVar1 == iVar2);
  return 0;
}


// ==== 0x5a8490 FUN_005a8490

void FUN_005a8490(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  
  switch(*(undefined4 *)(*in_EAX + 0x24)) {
  case 0x530b82b0:
    piVar2 = &DAT_00733738;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar2 = piVar2 + 1;
    }
    return;
  case 0x530b82b1:
    piVar2 = &DAT_007338f4;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar2 = piVar2 + 1;
    }
    return;
  case 0x530b82b2:
    piVar2 = &DAT_00733ab0;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar2 = piVar2 + 1;
    }
    return;
  case 0x530b82b3:
    piVar2 = &DAT_00733c6c;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar2 = piVar2 + 1;
    }
  }
  return;
}


// ==== 0x5a8500 FUN_005a8500

void FUN_005a8500(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  switch(in_EAX) {
  case 0x530b82b0:
    puVar2 = &DAT_00733738;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return;
  case 0x530b82b1:
    puVar2 = &DAT_007338f4;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return;
  case 0x530b82b2:
    puVar2 = &DAT_00733ab0;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return;
  case 0x530b82b3:
    puVar2 = &DAT_00733c6c;
    for (iVar1 = 0x6f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}


// ==== 0x5a8570 FUN_005a8570

undefined4 FUN_005a8570(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar1 = _ftol_nocw();
  uVar2 = _ftol_nocw();
  uVar3 = _ftol_nocw();
  uVar4 = _ftol_nocw();
  return CONCAT13(uVar4,CONCAT21(CONCAT11(uVar1,uVar2),uVar3));
}


// ==== 0x5a8640 FUN_005a8640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a8640(undefined4 param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  iVar4 = 0;
  uVar3 = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  if (3 < param_3) {
    pfVar5 = (float *)(param_2 + 8);
    local_8 = 3;
    do {
      if (_K_BLUR_MIN_T < pfVar5[-2]) {
        iVar1 = _ftol_nocw();
        local_18 = local_18 + iVar1;
        iVar1 = _ftol_nocw();
        local_14 = local_14 + iVar1;
        iVar1 = _ftol_nocw();
        local_10 = local_10 + iVar1;
        if (param_4 == '\0') {
          iVar1 = _ftol_nocw();
          uVar3 = uVar3 + iVar1;
        }
        else {
          uVar2 = _ftol_nocw();
          if ((int)uVar3 < (int)(uVar2 & 0xff)) {
            uVar3 = uVar2 & 0xff;
          }
        }
      }
      if (_K_BLUR_MIN_T < pfVar5[-1]) {
        iVar1 = _ftol_nocw();
        local_18 = local_18 + iVar1;
        iVar1 = _ftol_nocw();
        local_14 = local_14 + iVar1;
        iVar1 = _ftol_nocw();
        local_10 = local_10 + iVar1;
        if (param_4 == '\0') {
          iVar1 = _ftol_nocw();
          uVar3 = uVar3 + iVar1;
        }
        else {
          uVar2 = _ftol_nocw();
          if ((int)uVar3 < (int)(uVar2 & 0xff)) {
            uVar3 = uVar2 & 0xff;
          }
        }
      }
      if (_K_BLUR_MIN_T < *pfVar5) {
        iVar1 = _ftol_nocw();
        local_18 = local_18 + iVar1;
        iVar1 = _ftol_nocw();
        local_14 = local_14 + iVar1;
        iVar1 = _ftol_nocw();
        local_10 = local_10 + iVar1;
        if (param_4 == '\0') {
          iVar1 = _ftol_nocw();
          uVar3 = uVar3 + iVar1;
        }
        else {
          uVar2 = _ftol_nocw();
          if ((int)uVar3 < (int)(uVar2 & 0xff)) {
            uVar3 = uVar2 & 0xff;
          }
        }
      }
      if (_K_BLUR_MIN_T < pfVar5[1]) {
        iVar1 = _ftol_nocw();
        local_18 = local_18 + iVar1;
        iVar1 = _ftol_nocw();
        local_14 = local_14 + iVar1;
        iVar1 = _ftol_nocw();
        local_10 = local_10 + iVar1;
        if (param_4 == '\0') {
          iVar1 = _ftol_nocw();
          uVar3 = uVar3 + iVar1;
        }
        else {
          uVar2 = _ftol_nocw();
          if ((int)uVar3 < (int)(uVar2 & 0xff)) {
            uVar3 = uVar2 & 0xff;
          }
        }
      }
      local_8 = local_8 + 4;
      iVar4 = iVar4 + 4;
      pfVar5 = pfVar5 + 4;
    } while (local_8 < param_3);
  }
  for (; iVar4 < param_3; iVar4 = iVar4 + 1) {
    if (_K_BLUR_MIN_T < *(float *)(param_2 + iVar4 * 4)) {
      iVar1 = _ftol_nocw();
      local_18 = local_18 + iVar1;
      iVar1 = _ftol_nocw();
      local_14 = local_14 + iVar1;
      iVar1 = _ftol_nocw();
      local_10 = local_10 + iVar1;
      if (param_4 == '\0') {
        iVar1 = _ftol_nocw();
        uVar3 = uVar3 + iVar1;
      }
      else {
        uVar2 = _ftol_nocw();
        if ((int)uVar3 < (int)(uVar2 & 0xff)) {
          uVar3 = uVar2 & 0xff;
        }
      }
    }
  }
  local_c._2_2_ = 0xff;
  if (local_18 < 0x100) {
    local_c._2_2_ = (ushort)local_18 & 0xff;
  }
  local_c = CONCAT22(local_c._2_2_,0xff00);
  if (local_14 < 0x100) {
    local_c = (uint)CONCAT21(local_c._2_2_,(char)local_14) << 8;
  }
  local_c = CONCAT31(local_c._1_3_,0xff);
  if (local_10 < 0x100) {
    local_c = CONCAT31(local_c._1_3_,(char)local_10);
  }
  local_c = CONCAT13(0xff,(undefined3)local_c);
  if ((int)uVar3 < 0x100) {
    local_c = CONCAT13((char)uVar3,(undefined3)local_c);
  }
  return local_c;
}


// ==== 0x5a8a50 FUN_005a8a50

/* WARNING: Removing unreachable block (ram,0x005a8d86) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a8a50(int *param_1)

{
  short sVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int *piVar10;
  float *pfVar11;
  int unaff_EBP;
  float *pfVar12;
  uint uVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined1 *puVar16;
  int *piVar17;
  int *piStack_58;
  int iStack_3c;
  int *piStack_30;
  float afStack_24 [2];
  int *local_1c;
  undefined4 local_18 [2];
  undefined4 uStack_10;
  
  iVar7 = param_1[1];
  pfVar2 = (float *)param_1[0x6e];
  piVar17 = (int *)*param_1;
  piVar14 = param_1 + 2;
  if ((piVar17 == (int *)0x0) || (*(char *)((int)piVar17 + 0x4a) != ' ')) {
    return 0;
  }
  piStack_58 = (int *)0x0;
  local_1c = piVar14;
  (**(code **)(**(int **)(*piVar17 + 0x18) + 0x4c))(*(int **)(*piVar17 + 0x18),0,local_18,0);
  iVar9 = piVar17[0x11];
  sVar1 = *(short *)((int)piVar17 + 0x46);
  piVar6 = param_1;
  if (DAT_00733f4c == 0) {
    puVar15 = &DAT_00733e28;
    for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    afStack_24[0] = -1.9921875;
    afStack_24[1] = -0.503891;
    local_1c = (int *)0xbf0000ff;
    local_18[0] = 0xbfff00ff;
    if (pfVar2 < pfVar2 + (int)sVar1 * (int)(short)iVar9) {
      iVar7 = 0;
      pfVar8 = pfVar2;
      do {
        iVar4 = 0;
        do {
          if (*pfVar8 == afStack_24[iVar4]) {
            iVar3 = (&DAT_00733f50)[iVar4];
            (&DAT_00733e28)[iVar4 * 0x10 + iVar3] = iVar7 >> 2;
            (&DAT_00733f50)[iVar4] = iVar3 + 1;
            piVar6 = (int *)uStack_10;
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 4);
        pfVar8 = pfVar8 + 1;
        iVar7 = iVar7 + 4;
      } while (pfVar8 < pfVar2 + (int)sVar1 * (int)(short)iVar9);
    }
    piVar17 = (int *)0x0;
    DAT_00733f4c = 1;
    iVar7 = unaff_EBP;
  }
  uStack_10._3_1_ = (undefined1)((uint)iVar7 >> 0x18);
  uStack_10._0_3_ = CONCAT12((char)iVar7,(short)iVar7);
  *piVar14 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + 0xb),(char)*piVar14),
                               *(undefined1 *)((int)param_1 + 9)),*(undefined1 *)((int)param_1 + 10)
                     );
  param_1[3] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + 0xf),(char)param_1[3]),
                                 *(undefined1 *)((int)param_1 + 0xd)),
                        *(undefined1 *)((int)param_1 + 0xe));
  param_1[4] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + 0x13),(char)param_1[4]),
                                 *(undefined1 *)((int)param_1 + 0x11)),
                        *(undefined1 *)((int)param_1 + 0x12));
  uStack_10 = (uint *)CONCAT31(uStack_10._1_3_,(char)((uint)unaff_EBP >> 0x10));
  iVar7 = (int)sVar1 * (int)(short)iVar9;
  param_1[5] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + 0x17),(char)param_1[5]),
                                 *(undefined1 *)((int)param_1 + 0x15)),
                        *(undefined1 *)((int)param_1 + 0x16));
  if (pfVar2 < pfVar2 + iVar7) {
    pfVar8 = pfVar2;
    for (iVar9 = ((uint)((int)(pfVar2 + iVar7) + (-1 - (int)pfVar2)) >> 2) + 1; iVar9 != 0;
        iVar9 = iVar9 + -1) {
      *pfVar8 = (float)uStack_10;
      pfVar8 = pfVar8 + 1;
    }
    piVar17 = (int *)0x0;
  }
  if (0 < iStack_3c) {
    puVar16 = (undefined1 *)((int)piVar6 + 0x3d);
    do {
      if (*(int *)(puVar16 + -0x25) != 0) {
        if (*(int *)(puVar16 + -5) != 0) {
          *(uint *)(puVar16 + -1) =
               CONCAT31(CONCAT21(CONCAT11(puVar16[2],puVar16[-1]),*puVar16),puVar16[1]);
          *(uint *)(puVar16 + 3) =
               CONCAT31(CONCAT21(CONCAT11(puVar16[6],puVar16[3]),puVar16[4]),puVar16[5]);
          *(uint *)(puVar16 + 7) =
               CONCAT31(CONCAT21(CONCAT11(puVar16[10],puVar16[7]),puVar16[8]),puVar16[9]);
          *(uint *)(puVar16 + 0xb) =
               CONCAT31(CONCAT21(CONCAT11(puVar16[0xe],puVar16[0xb]),puVar16[0xc]),puVar16[0xd]);
        }
        pfVar11 = *(float **)(puVar16 + -0x19);
        uStack_10 = *(uint **)(puVar16 + -0x11);
        pfVar8 = pfVar11 + iVar7;
        pfVar12 = pfVar2;
        for (; pfVar11 < pfVar8; pfVar11 = pfVar11 + 1) {
          fVar5 = *pfVar11;
          uVar13 = *uStack_10 & 0xff;
          if ((*(int *)(puVar16 + -5) != 0) && (uVar13 != 0)) {
            afStack_24[0] = (float)((uint)fVar5 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
            afStack_24[1] = (float)((uint)fVar5 >> 8 & 0xff) * _K_BLUR_MIN_T;
            local_18[0] = 0;
            local_1c = (int *)((float)((uint)fVar5 & 0xff) * _K_BLUR_MIN_T);
            fVar5 = (float)FUN_005a8640(puVar16 + -1,afStack_24,3,1);
          }
          if (uVar13 < 0x80) {
            if (uVar13 != 0) {
              fVar5 = (float)FUN_005a8640(&stack0xffffffac,&stack0xffffffb4,2,0);
              goto LAB_005a8dea;
            }
          }
          else {
LAB_005a8dea:
            *pfVar12 = fVar5;
          }
          uStack_10 = uStack_10 + 1;
          pfVar12 = pfVar12 + 1;
          piVar14 = piStack_30;
        }
      }
      puVar16 = puVar16 + 0x34;
      iStack_3c = iStack_3c + -1;
      piVar17 = piStack_58;
    } while (iStack_3c != 0);
  }
  piVar6 = &DAT_00733f50;
  uStack_10 = &DAT_00733e28;
  do {
    iVar7 = 0;
    piVar10 = (int *)uStack_10;
    if (0 < *piVar6) {
      do {
        pfVar2[*piVar10] = *(float *)((int)(piVar14 + -0x1ccfd4) + (int)piVar6);
        iVar7 = iVar7 + 1;
        piVar10 = piVar10 + 1;
      } while (iVar7 < *piVar6);
      piVar17 = (int *)0x0;
    }
    piVar6 = piVar6 + 1;
    uStack_10 = uStack_10 + 0x10;
  } while ((int)piVar6 < 0x733f60);
  (**(code **)(**(int **)(*piVar17 + 0x18) + 0x50))(*(int **)(*piVar17 + 0x18),0);
  return 1;
}


// ==== 0x5a8e90 FUN_005a8e90

/* WARNING: Removing unreachable block (ram,0x005a9230) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a8e90(int *param_1)

{
  byte bVar1;
  short sVar2;
  int *piVar3;
  byte *pbVar4;
  bool bVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  int *piVar13;
  undefined1 uVar14;
  undefined1 *puVar15;
  int *piVar16;
  undefined1 uVar17;
  int iVar18;
  char cVar19;
  int iVar20;
  byte *pbVar21;
  undefined4 *puVar22;
  uint uVar23;
  undefined1 uStack_c5;
  int *piVar24;
  undefined1 uVar25;
  int iStack_b4;
  int iStack_a8;
  int iStack_a0;
  int iStack_9c;
  uint uStack_90;
  float local_8c [3];
  int *local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  undefined4 uStack_70;
  uint auStack_6c [5];
  byte *pbStack_58;
  int aiStack_54 [3];
  undefined1 local_48 [20];
  int aiStack_34 [9];
  int *piStack_10;
  
  local_8c[0] = (float)param_1[1];
  piVar3 = (int *)param_1[0x6e];
  param_1 = (int *)*param_1;
  if (((param_1 == (int *)0x0) || (*(char *)((int)param_1 + 0x4a) != '\b')) || (DAT_007301d4 == 0))
  {
    return 0;
  }
  local_80 = param_1;
  (**(code **)(**(int **)(*param_1 + 0x18) + 0x4c))(*(int **)(*param_1 + 0x18),0,local_48,0);
  puVar22 = (undefined4 *)param_1[0x1d];
  iVar20 = param_1[0x11];
  sVar2 = *(short *)((int)param_1 + 0x46);
  iVar6 = FUN_00565b60(0x200000,0,0,8);
  pbVar7 = pbStack_58 + (int)*(short *)((int)param_1 + 0x46) * (int)(short)param_1[0x11];
  iVar8 = 0;
  iStack_b4 = 0;
  if (0 < iStack_a8) {
    piVar24 = piStack_10 + 0xb;
    do {
      if (piVar24[-5] != 0) {
        aiStack_34[iVar8] = piVar24[-2];
        aiStack_54[iVar8] = *piVar24;
      }
      iVar8 = iVar8 + 1;
      piVar24 = piVar24 + 0xd;
    } while (iVar8 < iStack_a8);
  }
  if (DAT_00733f4c == 0) {
    local_8c[0] = -0.5000152;
    local_8c[1] = -0.503891;
    local_8c[2] = -1.9921875;
    local_80 = (int *)0xbfff00ff;
    auStack_6c[0] = 0xffffffff;
    auStack_6c[1] = 0xffffffff;
    auStack_6c[2] = 0xffffffff;
    auStack_6c[3] = 0xffffffff;
    iVar20 = 0;
    do {
      iVar8 = *(int *)((int)local_8c + iVar20);
      iVar18 = 0;
      piVar24 = puVar22 + 2;
      do {
        if (piVar24[-2] == iVar8) break;
        if (piVar24[-1] == iVar8) {
          iVar18 = iVar18 + 1;
          break;
        }
        if (*piVar24 == iVar8) {
          iVar18 = iVar18 + 2;
          break;
        }
        if (piVar24[1] == iVar8) {
          iVar18 = iVar18 + 3;
          break;
        }
        if (piVar24[2] == iVar8) {
          iVar18 = iVar18 + 4;
          break;
        }
        if (piVar24[3] == iVar8) {
          iVar18 = iVar18 + 5;
          break;
        }
        if (piVar24[4] == iVar8) {
          iVar18 = iVar18 + 6;
          break;
        }
        if (piVar24[5] == iVar8) {
          iVar18 = iVar18 + 7;
          break;
        }
        iVar18 = iVar18 + 8;
        piVar24 = piVar24 + 8;
      } while (iVar18 < 0x100);
      if (iVar18 != 0x100) {
        *(int *)((int)auStack_6c + iVar20) = iVar18;
      }
      iVar20 = iVar20 + 4;
    } while (iVar20 < 0x10);
    puVar11 = &DAT_00733e28;
    for (iVar20 = 0x40; iVar20 != 0; iVar20 = iVar20 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    if (pbStack_58 < pbVar7) {
      iVar20 = 0;
      pbVar21 = pbStack_58;
      do {
        iVar8 = 0;
        do {
          if ((uint)*pbVar21 == auStack_6c[iVar8]) {
            *pbVar21 = (char)iVar8 + 1;
            iVar18 = (&DAT_00733f50)[iVar8];
            (&DAT_00733e28)[iVar8 * 0x10 + iVar18] = iVar20;
            (&DAT_00733f50)[iVar8] = iVar18 + 1;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 4);
        if (iVar8 == 4) {
          *pbVar21 = 0;
        }
        pbVar21 = pbVar21 + 1;
        iVar20 = iVar20 + 1;
      } while (pbVar21 < pbVar7);
    }
    DAT_00733f4c = 1;
  }
  else {
    uVar23 = (int)sVar2 * (int)(short)iVar20;
    pbVar21 = pbStack_58;
    for (uVar9 = uVar23 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      pbVar21[0] = 0;
      pbVar21[1] = 0;
      pbVar21[2] = 0;
      pbVar21[3] = 0;
      pbVar21 = pbVar21 + 4;
    }
    for (uVar23 = uVar23 & 3; uVar23 != 0; uVar23 = uVar23 - 1) {
      *pbVar21 = 0;
      pbVar21 = pbVar21 + 1;
    }
  }
  *puVar22 = iStack_a0;
  puVar22[1] = piStack_10[2];
  puVar22[2] = piStack_10[3];
  puVar22[3] = piStack_10[4];
  puVar22[4] = piStack_10[5];
  piVar16 = piStack_10;
  piVar24 = piStack_10;
  for (pbVar21 = pbStack_58; pbVar21 < pbVar7; pbVar21 = pbVar21 + 1) {
    uStack_90 = puVar22[*pbVar21];
    bVar5 = false;
    iStack_a0 = 5;
    iStack_9c = 0;
    piStack_10 = piVar24;
    if (0 < iStack_a8) {
      piVar24 = piVar16 + 0xc;
      do {
        if (piVar24[-6] != 0) {
          pbVar4 = (byte *)aiStack_34[iStack_9c];
          bVar1 = *pbVar4;
          uVar9 = *(uint *)(piVar24[-2] + (uint)bVar1 * 4);
          uVar23 = *(uint *)(*piVar24 + (uint)*(byte *)aiStack_54[iStack_9c] * 4) & 0xff;
          if ((piVar24[2] != 0) && (uVar23 != 0)) {
            fStack_7c = (float)(uVar9 & 0xff) * _K_BLUR_MIN_T;
            fStack_78 = (float)(uVar9 >> 8 & 0xff) * _K_BLUR_MIN_T;
            uStack_70 = 0;
            fStack_74 = (float)(uVar9 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
            uVar9 = FUN_005a8640(piVar24 + 3,&fStack_7c,3,1);
          }
          if (uVar23 < 0x80) {
            if (uVar23 != 0) {
              local_8c[0] = (float)uVar23 * 0.0078125;
              if (1.0 < local_8c[0]) {
                local_8c[0] = 1.0;
              }
              local_8c[1] = 1.0 - local_8c[0];
              auStack_6c[1] = uStack_90;
              auStack_6c[0] = uVar9;
              uStack_90 = FUN_005a8640(auStack_6c,local_8c,2,0);
              if (bVar5) {
                *(uint *)(iVar6 + -4 + iStack_b4 * 8) = uStack_90;
              }
              else {
                iVar20 = piVar24[-3];
                iVar8 = piVar3[0x11];
                *(uint *)(iVar6 + 4 + iStack_b4 * 8) = uStack_90;
                iStack_b4 = iStack_b4 + 1;
                *(short *)(iVar6 + -8 + iStack_b4 * 8) =
                     (short)(((int)pbVar4 - iVar20) % (int)(short)iVar8);
                *(short *)(iVar6 + -6 + iStack_b4 * 8) =
                     (short)(((int)pbVar4 - iVar20) / (int)(short)iVar8);
              }
              *pbVar21 = 0xff;
              bVar5 = true;
            }
          }
          else {
            *pbVar21 = (char)iStack_a0 + bVar1;
            uStack_90 = uVar9;
            if (bVar5) {
              iStack_b4 = iStack_b4 + -1;
              bVar5 = false;
            }
          }
          piVar16 = piStack_10;
          aiStack_54[iStack_9c] = aiStack_54[iStack_9c] + 1;
          iVar20 = piVar24[1];
          aiStack_34[iStack_9c] = (int)(pbVar4 + 1);
          iStack_a0 = iStack_a0 + iVar20;
        }
        iStack_9c = iStack_9c + 1;
        piVar24 = piVar24 + 0xd;
      } while (iStack_9c < iStack_a8);
    }
    piVar24 = piStack_10;
  }
  iVar20 = 5;
  if (0 < iStack_a8) {
    do {
      piVar16 = piVar24 + 0xd;
      if (piVar24[0xe] == 0) {
        iVar8 = 0;
        if (0 < *piVar16) {
          puVar11 = puVar22 + iVar20;
          do {
            *puVar11 = *(undefined4 *)(piVar24[10] + iVar8 * 4);
            iVar8 = iVar8 + 1;
            puVar11 = puVar11 + 1;
          } while (iVar8 < *piVar16);
        }
      }
      else {
        iVar8 = 0;
        if (0 < *piVar16) {
          uStack_70 = 0;
          puVar11 = puVar22 + iVar20;
          do {
            uVar9 = *(uint *)(piVar24[10] + iVar8 * 4);
            fStack_7c = (float)(uVar9 & 0xff) * _K_BLUR_MIN_T;
            fStack_78 = (float)(uVar9 >> 8 & 0xff) * _K_BLUR_MIN_T;
            fStack_74 = (float)(uVar9 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
            uVar10 = FUN_005a8640(piVar24 + 0xf,&fStack_7c,3,1);
            *puVar11 = uVar10;
            iVar8 = iVar8 + 1;
            puVar11 = puVar11 + 1;
          } while (iVar8 < *piVar16);
        }
      }
      iVar20 = iVar20 + *piVar16;
      iStack_a8 = iStack_a8 + -1;
      piVar24 = piVar16;
    } while (iStack_a8 != 0);
  }
  if (iStack_b4 != 0) {
    iVar8 = 0xff - iVar20;
    if (iStack_b4 < iVar8) {
      iVar8 = 0;
      if (0 < iStack_b4) {
        puVar22 = puVar22 + iVar20;
        puVar11 = (undefined4 *)(iVar6 + 4);
        do {
          pbStack_58
          [(int)*(short *)(puVar11 + -1) +
           (int)*(short *)((int)puVar11 + -2) * (int)(short)piVar3[0x11]] =
               (char)iVar20 + (char)iVar8;
          *puVar22 = *puVar11;
          iVar8 = iVar8 + 1;
          puVar22 = puVar22 + 1;
          puVar11 = puVar11 + 2;
        } while (iVar8 < iStack_b4);
      }
    }
    else {
      if ((int)(-(uint)(DAT_007301d4 != 0) & 0x6300000) < iStack_b4 * 4) {
        iStack_b4 = 0;
      }
      iVar18 = FUN_00565b60(iStack_b4 * 4,0,0,8);
      if (0 < iStack_b4) {
        puVar15 = (undefined1 *)(iVar18 + 2);
        puVar12 = (undefined1 *)(iVar6 + 5);
        iVar18 = iStack_b4;
        do {
          puVar15[-2] = puVar12[-1];
          puVar15[-1] = *puVar12;
          *puVar15 = puVar12[1];
          puVar15[1] = puVar12[2];
          puVar12 = puVar12 + 8;
          puVar15 = puVar15 + 4;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      FUN_005a7b70(iVar8);
      FUN_005a81b0();
      FUN_005a7bf0();
      iVar18 = 0;
      if (0 < iVar8) {
        puVar15 = &DAT_00732334;
        puVar22 = puVar22 + iVar20;
        do {
          if (((int)puVar15 < 0x732334) || (DAT_006ee1e4 <= iVar18)) {
            uVar14 = 0;
            uStack_c5 = 0;
            uVar25 = 0;
            uVar17 = 0;
          }
          else {
            uStack_c5 = *puVar15;
            uVar14 = puVar15[4];
            uVar25 = puVar15[-4];
            uVar17 = puVar15[8];
          }
          puVar15 = puVar15 + 0x14;
          *puVar22 = CONCAT31(CONCAT21(CONCAT11(uVar17,uVar14),uStack_c5),uVar25);
          iVar18 = iVar18 + 1;
          puVar22 = puVar22 + 1;
        } while (iVar18 < iVar8);
      }
      FUN_005a7c30();
      if (0 < iStack_b4) {
        puVar15 = (undefined1 *)(iVar6 + 7);
        do {
          sVar2 = *(short *)(puVar15 + -7);
          iVar6 = (int)*(short *)(puVar15 + -5) * (int)(short)piVar3[0x11];
          if (pbStack_58[sVar2 + iVar6] == 0xff) {
            iVar18 = FUN_005a7d60(*(uint *)(puVar15 + -3) & 0xff,puVar15[-2],puVar15[-1],*puVar15);
            if (iVar18 < iVar8) {
              pbStack_58[sVar2 + iVar6] = (char)iVar20 + (char)iVar18;
            }
            else {
              pbStack_58[sVar2 + iVar6] = 0;
            }
          }
          puVar15 = puVar15 + 8;
          iStack_b4 = iStack_b4 + -1;
        } while (iStack_b4 != 0);
      }
      FUN_00565ce0();
    }
  }
  FUN_00565ce0();
  cVar19 = '\0';
  piVar24 = &DAT_00733e28;
  piVar16 = &DAT_00733f50;
  do {
    iVar20 = 0;
    if (0 < *piVar16) {
      piVar13 = piVar24;
      do {
        pbStack_58[*piVar13] = cVar19 + 1;
        iVar20 = iVar20 + 1;
        piVar13 = piVar13 + 1;
      } while (iVar20 < *piVar16);
    }
    piVar16 = piVar16 + 1;
    piVar24 = piVar24 + 0x10;
    cVar19 = cVar19 + '\x01';
  } while ((int)piVar16 < 0x733f60);
  (**(code **)(**(int **)(*piVar3 + 0x18) + 0x50))(*(int **)(*piVar3 + 0x18),0);
  return 1;
}


// ==== 0x5a96b0 GetDoorLineHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetDoorLineHash(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  char *pcVar8;
  int *unaff_ESI;
  int local_4c [3];
  byte local_40 [64];
  
  iVar4 = *unaff_ESI * 0xc90 + DAT_00734588;
  local_40[0] = *(byte *)(iVar4 + 0x20);
  iVar4 = iVar4 + 0x20;
  bVar6 = local_40[0];
  if (local_40[0] != 0) {
    pbVar7 = local_40;
    do {
      bVar2 = *(byte *)(iVar4 + 1);
      iVar4 = iVar4 + 1;
      pbVar7 = pbVar7 + 1;
      *pbVar7 = bVar2;
      bVar6 = local_40[0];
    } while (bVar2 != 0);
  }
  if (unaff_ESI[0x119] == 0) {
    local_4c[0] = 1;
    local_4c[1] = 2;
    local_4c[2] = 5;
    iVar4 = 0;
    do {
      if ((unaff_ESI[local_4c[iVar4] + 0x113] != 0) &&
         (*(char *)(unaff_ESI[local_4c[iVar4] + 0x113] + 0x11) != '\0')) {
        iVar4 = 0;
        if (bVar6 != 0) {
          pbVar7 = local_40;
          iVar5 = iVar4;
          do {
            local_40[iVar5] = *pbVar7;
            iVar4 = iVar5 + 1;
            iVar3 = iVar5 + 1;
            pbVar7 = local_40 + iVar5 + 1;
            iVar5 = iVar4;
          } while (local_40[iVar3] != 0);
        }
        bVar6 = 0x5f;
        pcVar8 = "_DOORLINE_KIT";
        do {
          local_40[iVar4] = bVar6;
          bVar6 = pcVar8[1];
          iVar4 = iVar4 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar6 != 0);
        goto LAB_005a978d;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    iVar4 = 0;
    if (bVar6 != 0) {
      pbVar7 = local_40;
      iVar5 = iVar4;
      do {
        local_40[iVar5] = *pbVar7;
        iVar4 = iVar5 + 1;
        iVar3 = iVar5 + 1;
        pbVar7 = local_40 + iVar5 + 1;
        iVar5 = iVar4;
      } while (local_40[iVar3] != 0);
    }
    bVar6 = 0x5f;
    pcVar8 = "_DOORLINE";
    do {
      local_40[iVar4] = bVar6;
      bVar6 = pcVar8[1];
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar6 != 0);
  }
  else {
    iVar4 = 0;
    if (bVar6 != 0) {
      pbVar7 = local_40;
      iVar5 = iVar4;
      do {
        local_40[iVar5] = *pbVar7;
        iVar4 = iVar5 + 1;
        iVar3 = iVar5 + 1;
        pbVar7 = local_40 + iVar5 + 1;
        iVar5 = iVar4;
      } while (local_40[iVar3] != 0);
    }
    bVar6 = 0x5f;
    pcVar8 = "_DOORLINE_WIDEBODY";
    do {
      local_40[iVar4] = bVar6;
      bVar6 = pcVar8[1];
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar6 != 0);
  }
LAB_005a978d:
  local_40[iVar4] = 0;
  iVar4 = -1;
  pbVar7 = local_40;
  while (local_40[0] != 0) {
    iVar4 = iVar4 * 0x21 + (uint)local_40[0];
    pbVar1 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    local_40[0] = *pbVar1;
  }
  return iVar4;
}


// ==== 0x5a97f0 GetDoorLineMaskHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetDoorLineMaskHash(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  char *pcVar8;
  int *unaff_ESI;
  int local_4c [3];
  byte local_40 [64];
  
  iVar4 = *unaff_ESI * 0xc90 + DAT_00734588;
  local_40[0] = *(byte *)(iVar4 + 0x20);
  iVar4 = iVar4 + 0x20;
  bVar6 = local_40[0];
  if (local_40[0] != 0) {
    pbVar7 = local_40;
    do {
      bVar2 = *(byte *)(iVar4 + 1);
      iVar4 = iVar4 + 1;
      pbVar7 = pbVar7 + 1;
      *pbVar7 = bVar2;
      bVar6 = local_40[0];
    } while (bVar2 != 0);
  }
  if (unaff_ESI[0x119] == 0) {
    local_4c[0] = 1;
    local_4c[1] = 2;
    local_4c[2] = 5;
    iVar4 = 0;
    do {
      if ((unaff_ESI[local_4c[iVar4] + 0x113] != 0) &&
         (*(char *)(unaff_ESI[local_4c[iVar4] + 0x113] + 0x11) != '\0')) {
        iVar4 = 0;
        if (bVar6 != 0) {
          pbVar7 = local_40;
          iVar5 = iVar4;
          do {
            local_40[iVar5] = *pbVar7;
            iVar4 = iVar5 + 1;
            iVar3 = iVar5 + 1;
            pbVar7 = local_40 + iVar5 + 1;
            iVar5 = iVar4;
          } while (local_40[iVar3] != 0);
        }
        bVar6 = 0x5f;
        pcVar8 = "_DOORLINE_KIT_MASK";
        do {
          local_40[iVar4] = bVar6;
          bVar6 = pcVar8[1];
          iVar4 = iVar4 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar6 != 0);
        goto LAB_005a98cd;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    iVar4 = 0;
    if (bVar6 != 0) {
      pbVar7 = local_40;
      iVar5 = iVar4;
      do {
        local_40[iVar5] = *pbVar7;
        iVar4 = iVar5 + 1;
        iVar3 = iVar5 + 1;
        pbVar7 = local_40 + iVar5 + 1;
        iVar5 = iVar4;
      } while (local_40[iVar3] != 0);
    }
    bVar6 = 0x5f;
    pcVar8 = "_DOORLINE_MASK";
    do {
      local_40[iVar4] = bVar6;
      bVar6 = pcVar8[1];
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar6 != 0);
  }
  else {
    iVar4 = 0;
    if (bVar6 != 0) {
      pbVar7 = local_40;
      iVar5 = iVar4;
      do {
        local_40[iVar5] = *pbVar7;
        iVar4 = iVar5 + 1;
        iVar3 = iVar5 + 1;
        pbVar7 = local_40 + iVar5 + 1;
        iVar5 = iVar4;
      } while (local_40[iVar3] != 0);
    }
    bVar6 = 0x5f;
    pcVar8 = "_DOORLINE_WIDEBODY_MASK";
    do {
      local_40[iVar4] = bVar6;
      bVar6 = pcVar8[1];
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar6 != 0);
  }
LAB_005a98cd:
  local_40[iVar4] = 0;
  iVar4 = -1;
  pbVar7 = local_40;
  while (local_40[0] != 0) {
    iVar4 = iVar4 * 0x21 + (uint)local_40[0];
    pbVar1 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    local_40[0] = *pbVar1;
  }
  return iVar4;
}


// ==== 0x5a9930 GetHoodSpoilerHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetHoodSpoilerHash(void)

{
  byte bVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  byte local_40;
  byte local_3f [63];
  
  iVar3 = in_EAX[0x137];
  iVar2 = in_EAX[0x136];
  pbVar4 = (byte *)(*in_EAX * 0xc90 + DAT_00734588 + 0x20);
  local_40 = *pbVar4;
  if (local_40 != 0) {
    pbVar5 = &local_40;
    do {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
      *pbVar5 = bVar1;
    } while (bVar1 != 0);
  }
  if (iVar2 == 0) {
    if (iVar3 == 0) {
      return 0;
    }
    pcVar6 = "_SPOILER";
  }
  else if (iVar3 == 0) {
    pcVar6 = "_HOOD";
  }
  else {
    pcVar6 = "_HOOD_SPOILER";
  }
  bStrCat2(pcVar6);
  iVar3 = -1;
  pbVar4 = &local_40;
  if (local_40 == 0) {
    return -1;
  }
  do {
    iVar3 = iVar3 * 0x21 + (uint)local_40;
    local_40 = pbVar4[1];
    pbVar4 = pbVar4 + 1;
  } while (local_40 != 0);
  return iVar3;
}


// ==== 0x5a99e0 GetHoodSpoilerMaskHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetHoodSpoilerMaskHash(void)

{
  byte bVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  byte local_40;
  byte local_3f [63];
  
  iVar3 = in_EAX[0x137];
  iVar2 = in_EAX[0x136];
  pbVar4 = (byte *)(*in_EAX * 0xc90 + DAT_00734588 + 0x20);
  local_40 = *pbVar4;
  if (local_40 != 0) {
    pbVar5 = &local_40;
    do {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
      *pbVar5 = bVar1;
    } while (bVar1 != 0);
  }
  if (iVar2 == 0) {
    if (iVar3 == 0) {
      return 0;
    }
    pcVar6 = "_SPOILER_MASK";
  }
  else if (iVar3 == 0) {
    pcVar6 = "_HOOD_MASK";
  }
  else {
    pcVar6 = "_HOOD_SPOILER_MASK";
  }
  bStrCat2(pcVar6);
  iVar3 = -1;
  pbVar4 = &local_40;
  if (local_40 == 0) {
    return -1;
  }
  do {
    iVar3 = iVar3 * 0x21 + (uint)local_40;
    local_40 = pbVar4[1];
    pbVar4 = pbVar4 + 1;
  } while (local_40 != 0);
  return iVar3;
}


// ==== 0x5a9a90 GetWheelTextureHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetWheelTextureHash(void)

{
  byte *pbVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  
  iVar4 = *(int *)(in_EAX + 0x490);
  if (iVar4 == 0) {
    return 0;
  }
  piVar3 = *(int **)(iVar4 + 0x14);
  piVar2 = piVar3 + *(short *)(iVar4 + 0x1c) * 2;
  if (piVar3 != (int *)0x0) {
    for (; piVar3 < piVar2; piVar3 = piVar3 + 2) {
      if (*piVar3 == 0x10c98090) {
        if (piVar3 != (int *)0x0) {
          iVar4 = piVar3[1];
          goto LAB_005a9ac1;
        }
        break;
      }
    }
  }
  iVar4 = 0;
LAB_005a9ac1:
  puVar6 = &DAT_006ba148;
  uVar5 = 0x5f;
  do {
    iVar4 = iVar4 * 0x21 + uVar5;
    pbVar1 = puVar6 + 1;
    uVar5 = (uint)*pbVar1;
    puVar6 = puVar6 + 1;
  } while (*pbVar1 != 0);
  return iVar4;
}


// ==== 0x5a9af0 GetWheelTextureMaskHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int GetWheelTextureMaskHash(void)

{
  byte *pbVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  iVar4 = *(int *)(in_EAX + 0x490);
  if (iVar4 == 0) {
    return 0;
  }
  piVar3 = *(int **)(iVar4 + 0x14);
  piVar2 = piVar3 + *(short *)(iVar4 + 0x1c) * 2;
  if (piVar3 != (int *)0x0) {
    for (; piVar3 < piVar2; piVar3 = piVar3 + 2) {
      if (*piVar3 == 0x10c98090) {
        if (piVar3 != (int *)0x0) {
          iVar4 = piVar3[1];
          goto LAB_005a9b21;
        }
        break;
      }
    }
  }
  iVar4 = 0;
LAB_005a9b21:
  pcVar6 = "_WHEEL_INNER_MASK";
  uVar5 = 0x5f;
  do {
    iVar4 = iVar4 * 0x21 + uVar5;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar5 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  return iVar4;
}


// ==== 0x5a9b50 GetVinylLayerHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int __fastcall GetVinylLayerHash(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int *in_EAX;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  byte local_40;
  byte local_3f [63];
  
  if (in_EAX[param_1 + 0x132] == 0) {
    return 0;
  }
  iVar6 = *in_EAX * 0xc90 + DAT_00734588;
  pcVar7 = "TEXTURE";
  do {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar1 != '\0');
  iVar4 = FUN_0057cc30(0);
  if (iVar4 != 0) {
    local_40 = *(byte *)(iVar6 + 0x20);
    iVar6 = iVar6 + 0x20;
    if (local_40 != 0) {
      pbVar5 = &local_40;
      do {
        bVar3 = *(byte *)(iVar6 + 1);
        iVar6 = iVar6 + 1;
        pbVar5 = pbVar5 + 1;
        *pbVar5 = bVar3;
      } while (bVar3 != 0);
    }
    bStrCat2(&DAT_006b7e1c);
    bStrCat2(iVar4);
    iVar6 = -1;
    pbVar5 = &local_40;
    while (local_40 != 0) {
      iVar6 = iVar6 * 0x21 + (uint)local_40;
      pbVar2 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      local_40 = *pbVar2;
    }
    return iVar6;
  }
  return 0;
}


// ==== 0x5a9c10 GetVinylLayerMaskHash

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int __fastcall GetVinylLayerMaskHash(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int *in_EAX;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  byte local_40;
  byte local_3f [63];
  
  if (in_EAX[param_1 + 0x132] == 0) {
    return 0;
  }
  iVar6 = *in_EAX * 0xc90 + DAT_00734588;
  pcVar7 = "TEXTURE";
  do {
    pcVar1 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar1 != '\0');
  iVar4 = FUN_0057cc30(0);
  if (iVar4 != 0) {
    local_40 = *(byte *)(iVar6 + 0x20);
    iVar6 = iVar6 + 0x20;
    if (local_40 != 0) {
      pbVar5 = &local_40;
      do {
        bVar3 = *(byte *)(iVar6 + 1);
        iVar6 = iVar6 + 1;
        pbVar5 = pbVar5 + 1;
        *pbVar5 = bVar3;
      } while (bVar3 != 0);
    }
    bStrCat2(&DAT_006b7e1c);
    bStrCat2(iVar4);
    bStrCat2(&DAT_006b7e14);
    iVar6 = -1;
    pbVar5 = &local_40;
    while (local_40 != 0) {
      iVar6 = iVar6 * 0x21 + (uint)local_40;
      pbVar2 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      local_40 = *pbVar2;
    }
    return iVar6;
  }
  return 0;
}


// ==== 0x5a9ce0 CompositeSkin

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CompositeSkin(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  undefined *puVar11;
  char *pcVar12;
  int iVar13;
  uint *puVar14;
  int *piVar15;
  bool bVar16;
  undefined4 uVar17;
  int local_3a0;
  int local_39c;
  int *local_38c;
  int local_384 [8];
  undefined1 local_364 [4];
  int iStack_360;
  int local_35c;
  uint local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  int local_344 [104];
  int local_1a4;
  int local_1a0 [104];
  
  if ((*(int *)(param_1 + 0x444) == 0) ||
     (iVar3 = Texture_FindByHash(*(int *)(param_1 + 0x444),0,0), iVar3 == 0)) {
    return 1;
  }
  bVar16 = *(char *)(iVar3 + 0x4a) != ' ';
  if (*(int *)(param_1 + 0x4c4) == 0) {
    return 1;
  }
  uVar17 = 0;
  FUN_00567c70(0);
  iVar4 = FUN_0057cc70(uVar17);
  uVar17 = 0;
  FUN_00567c70(0);
  uVar5 = FUN_0057cc70(uVar17);
  uVar17 = 0;
  FUN_00567c70(0);
  uVar6 = FUN_0057cc70(uVar17);
  uVar17 = 0;
  FUN_00567c70(0);
  uVar7 = FUN_0057cc70(uVar17);
  uVar7 = ((iVar4 << 8 | uVar5) << 8 | uVar6) << 8 | uVar7;
  local_384[0] = 0x25;
  local_384[1] = 0x26;
  local_384[2] = 0x27;
  local_384[3] = 0x28;
  local_3a0 = 0;
  do {
    if (*(int *)(param_1 + 0x44c + *(int *)((int)local_384 + local_3a0) * 4) == 0) {
      *(uint *)((int)local_384 + local_3a0 + 0x10) = uVar7;
    }
    else {
      puVar11 = &DAT_006c7a38;
      do {
        pcVar12 = puVar11 + 1;
        puVar11 = puVar11 + 1;
      } while (*pcVar12 != '\0');
      uVar5 = FUN_0057cc70(0);
      pcVar12 = "GREEN";
      do {
        pcVar1 = pcVar12 + 1;
        pcVar12 = pcVar12 + 1;
      } while (*pcVar1 != '\0');
      uVar6 = FUN_0057cc70(0);
      puVar11 = &DAT_006c7a28;
      do {
        pcVar12 = puVar11 + 1;
        puVar11 = puVar11 + 1;
      } while (*pcVar12 != '\0');
      uVar8 = FUN_0057cc70(0);
      pcVar12 = "GLOSS";
      do {
        pcVar1 = pcVar12 + 1;
        pcVar12 = pcVar12 + 1;
      } while (*pcVar1 != '\0');
      iVar4 = FUN_0057cc70(0);
      *(uint *)((int)local_384 + local_3a0 + 0x10) =
           ((iVar4 << 8 | uVar8) << 8 | uVar6) << 8 | uVar5;
    }
    local_3a0 = local_3a0 + 4;
  } while (local_3a0 < 0x10);
  piVar15 = local_1a0;
  local_39c = 0;
  piVar9 = local_1a0;
  for (iVar4 = 0x68; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  local_3a0 = 0;
  local_38c = piVar15;
  do {
    if ((local_3a0 < 1) || (4 < local_3a0)) {
      if (local_3a0 == 5) {
        iVar4 = GetDoorLineHash();
      }
      else {
        if (local_3a0 != 0) goto LAB_005a9fdb;
        iVar4 = GetHoodSpoilerHash();
      }
      *piVar15 = iVar4;
      piVar15[7] = 0x10;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x4c4 + local_3a0 * 4);
      if (1 < local_3a0) {
        piVar9 = (int *)(param_1 + 0x4c8);
        iVar13 = local_3a0 + -1;
        do {
          if (*piVar9 == iVar4) {
            iVar4 = 0;
          }
          piVar9 = piVar9 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
      }
      if (iVar4 != 0) {
        iVar13 = GetVinylLayerHash();
        *piVar15 = iVar13;
        pcVar12 = "NUMCOLOURS";
        iVar13 = -1;
        uVar5 = 0x4e;
        do {
          iVar13 = iVar13 * 0x21 + uVar5;
          pbVar2 = (byte *)(pcVar12 + 1);
          uVar5 = (uint)*pbVar2;
          pcVar12 = pcVar12 + 1;
        } while (*pbVar2 != 0);
        piVar10 = *(int **)(iVar4 + 0x14);
        piVar9 = piVar10 + *(short *)(iVar4 + 0x1c) * 2;
        if (piVar10 != (int *)0x0) {
          for (; piVar10 < piVar9; piVar10 = piVar10 + 2) {
            if ((iVar13 == 0) || (*piVar10 == iVar13)) {
              if (piVar10 != (int *)0x0) {
                iVar4 = piVar10[1];
                goto LAB_005a9f93;
              }
              break;
            }
          }
        }
        iVar4 = 0;
LAB_005a9f93:
        piVar15[7] = iVar4;
        if (iVar4 == 0) {
          return 0;
        }
      }
    }
LAB_005a9fdb:
    iVar4 = *piVar15;
    if (iVar4 != 0) {
      piVar9 = (int *)Texture_FindByHash(iVar4,0,0);
      piVar15[1] = (int)piVar9;
      if (piVar9 == (int *)0x0) {
        *piVar15 = 0;
      }
      else {
        puVar11 = &DAT_006b7e14;
        uVar5 = 0x5f;
        do {
          iVar4 = iVar4 * 0x21 + uVar5;
          pbVar2 = puVar11 + 1;
          uVar5 = (uint)*pbVar2;
          puVar11 = puVar11 + 1;
        } while (*pbVar2 != 0);
        piVar10 = (int *)Texture_FindByHash(iVar4,0,0);
        piVar15[2] = (int)piVar10;
        if (piVar10 == (int *)0x0) {
          *piVar15 = 0;
        }
        else {
          (**(code **)(**(int **)(*piVar9 + 0x18) + 0x4c))
                    (*(int **)(*piVar9 + 0x18),0,local_364,0,0);
          piVar15[3] = iStack_360;
          if (bVar16) {
            piVar15[4] = piVar9[0x1d];
          }
          if (iStack_360 == 0) {
            *piVar15 = 0;
          }
          else {
            (**(code **)(**(int **)(*piVar10 + 0x18) + 0x4c))
                      (*(int **)(*piVar10 + 0x18),0,local_384,0,0);
            piVar15[5] = local_384[1];
            if (bVar16) {
              piVar15[6] = piVar10[0x1d];
            }
            if (local_384[1] == 0) {
              *piVar15 = 0;
            }
            else {
              if (((0 < local_3a0) && (local_3a0 < 5)) &&
                 (*(int *)(param_1 + 0x4c4 + local_3a0 * 4) != 0)) {
                FUN_00567c70();
                iVar4 = FUN_0057cbf0();
                if (iVar4 != 0) {
                  uVar17 = 0;
                  FUN_00567c70(0);
                  iVar4 = FUN_0057cc70(uVar17);
                  piVar15[8] = iVar4;
                  if (iVar4 != 0) {
                    iVar4 = 0;
                    piVar9 = (int *)((local_3a0 + -1) * 0x10 + 0x4f4 + param_1);
                    puVar14 = (uint *)(piVar15 + 9);
                    do {
                      if (*piVar9 == 0) {
                        *puVar14 = 0xff << ((byte)iVar4 & 0x1f);
                      }
                      else {
                        uVar17 = 0;
                        FUN_00567c70(0);
                        iVar13 = FUN_0057cc70(uVar17);
                        uVar17 = 0;
                        FUN_00567c70(0);
                        uVar5 = FUN_0057cc70(uVar17);
                        uVar17 = 0;
                        FUN_00567c70(0);
                        uVar6 = FUN_0057cc70(uVar17);
                        uVar17 = 0;
                        FUN_00567c70(0);
                        uVar8 = FUN_0057cc70(uVar17);
                        *puVar14 = ((iVar13 << 8 | uVar5) << 8 | uVar6) << 8 | uVar8;
                        piVar15 = local_38c;
                      }
                      piVar9 = piVar9 + 1;
                      iVar4 = iVar4 + 8;
                      puVar14 = puVar14 + 1;
                    } while (iVar4 < 0x20);
                  }
                }
              }
              local_39c = local_39c + 1;
              piVar15 = piVar15 + 0xd;
              local_38c = piVar15;
            }
          }
        }
      }
    }
    local_3a0 = local_3a0 + 1;
    if (7 < local_3a0) {
      CompositeWheel();
      local_358 = uVar7;
      local_354 = local_384[4];
      local_1a4 = local_39c;
      local_350 = local_384[5];
      local_348 = local_384[7];
      local_35c = iVar3;
      local_34c = local_384[6];
      piVar15 = local_1a0;
      piVar9 = local_344;
      for (iVar4 = 0x68; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar9 = *piVar15;
        piVar15 = piVar15 + 1;
        piVar9 = piVar9 + 1;
      }
      uVar17 = 1;
      iVar4 = FUN_005a8400();
      if (iVar4 == 0) {
        FUN_005a8490();
        if (*(char *)(iVar3 + 0x4a) == '\b') {
          uVar17 = FUN_005a8e90(&local_35c);
        }
        else {
          uVar17 = FUN_005a8a50(&local_35c);
        }
      }
      piVar15 = local_1a0 + 1;
      iVar3 = 8;
      do {
        if (piVar15[2] != 0) {
          (**(code **)(**(int **)(*(int *)*piVar15 + 0x18) + 0x50))
                    (*(int **)(*(int *)*piVar15 + 0x18),0);
        }
        if (piVar15[4] != 0) {
          (**(code **)(**(int **)(*(int *)piVar15[1] + 0x18) + 0x50))
                    (*(int **)(*(int *)piVar15[1] + 0x18),0);
        }
        piVar15 = piVar15 + 0xd;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return uVar17;
    }
  } while( true );
}


// ==== 0x5aa2d0 GetTempCarSkinTextures

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

int GetTempCarSkinTextures(int param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  int local_4;
  
  local_8 = (int *)(param_3 + 0x4c8);
  local_4 = 4;
  do {
    if (*local_8 != 0) {
      iVar1 = GetVinylLayerHash();
      iVar2 = GetVinylLayerMaskHash();
      iVar3 = 0;
      if (iVar1 != 0) {
        if (0 < in_EAX) {
          do {
            if (*(int *)(param_1 + iVar3 * 4) == iVar1) {
              iVar3 = 0;
              goto LAB_005aa342;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < in_EAX);
        }
        iVar3 = in_EAX;
        if (in_EAX < param_2) {
          *(int *)(param_1 + in_EAX * 4) = iVar1;
          iVar3 = 1;
        }
      }
LAB_005aa342:
      iVar3 = in_EAX + iVar3;
      if (iVar2 == 0) {
LAB_005aa348:
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
        if (0 < iVar3) {
          do {
            if (*(int *)(param_1 + iVar1 * 4) == iVar2) goto LAB_005aa348;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar3);
        }
        iVar1 = iVar3;
        if (iVar3 < param_2) {
          *(int *)(param_1 + iVar3 * 4) = iVar2;
          iVar1 = 1;
        }
      }
      in_EAX = iVar3 + iVar1;
    }
    local_8 = local_8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  iVar3 = GetDoorLineHash();
  iVar1 = GetDoorLineMaskHash();
  if ((iVar3 != 0) && (iVar1 != 0)) {
    iVar2 = 0;
    if (0 < in_EAX) {
      do {
        if (*(int *)(param_1 + iVar2 * 4) == iVar3) {
          iVar2 = 0;
          goto LAB_005aa3d3;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < in_EAX);
    }
    iVar2 = in_EAX;
    if (in_EAX < param_2) {
      *(int *)(param_1 + in_EAX * 4) = iVar3;
      iVar2 = 1;
    }
LAB_005aa3d3:
    iVar2 = in_EAX + iVar2;
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (*(int *)(param_1 + iVar3 * 4) == iVar1) {
          iVar3 = 0;
          goto LAB_005aa402;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    iVar3 = iVar2;
    if (iVar2 < param_2) {
      *(int *)(param_1 + iVar2 * 4) = iVar1;
      iVar3 = 1;
    }
LAB_005aa402:
    in_EAX = iVar2 + iVar3;
  }
  iVar3 = GetHoodSpoilerHash();
  iVar1 = GetHoodSpoilerMaskHash();
  if ((iVar3 != 0) && (iVar1 != 0)) {
    iVar2 = 0;
    if (0 < in_EAX) {
      do {
        if (*(int *)(param_1 + iVar2 * 4) == iVar3) {
          iVar2 = 0;
          goto LAB_005aa448;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < in_EAX);
    }
    iVar2 = in_EAX;
    if (in_EAX < param_2) {
      *(int *)(param_1 + in_EAX * 4) = iVar3;
      iVar2 = 1;
    }
LAB_005aa448:
    iVar2 = in_EAX + iVar2;
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (*(int *)(param_1 + iVar3 * 4) == iVar1) {
          iVar3 = 0;
          goto LAB_005aa472;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    iVar3 = iVar2;
    if (iVar2 < param_2) {
      *(int *)(param_1 + iVar2 * 4) = iVar1;
      iVar3 = 1;
    }
LAB_005aa472:
    in_EAX = iVar2 + iVar3;
  }
  iVar3 = GetWheelTextureHash();
  iVar1 = GetWheelTextureMaskHash();
  if ((iVar3 != 0) && (iVar1 != 0)) {
    iVar2 = 0;
    if (0 < in_EAX) {
      do {
        if (*(int *)(param_1 + iVar2 * 4) == iVar3) {
          iVar2 = 0;
          goto LAB_005aa4b4;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < in_EAX);
    }
    iVar2 = in_EAX;
    if (in_EAX < param_2) {
      *(int *)(param_1 + in_EAX * 4) = iVar3;
      iVar2 = 1;
    }
LAB_005aa4b4:
    iVar2 = in_EAX + iVar2;
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (*(int *)(param_1 + iVar3 * 4) == iVar1) {
          return iVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    if (param_2 <= iVar2) {
      return iVar2 * 2;
    }
    *(int *)(param_1 + iVar2 * 4) = iVar1;
    in_EAX = iVar2 + 1;
  }
  return in_EAX;
}


// ==== 0x5aa510 FUN_005aa510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005aa510(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  byte *pbVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint *puVar7;
  int iVar8;
  char *pcVar9;
  int unaff_EDI;
  int iVar10;
  int iVar11;
  float fStack_6c;
  undefined1 *puStack_68;
  uint uStack_64;
  int iStack_60;
  int *piStack_5c;
  char *pcStack_58;
  undefined1 *puStack_54;
  char *pcStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [12];
  undefined1 local_20 [28];
  
  piStack_5c = *(int **)(*param_1 + 0x18);
  uStack_4c = 0;
  pcStack_50 = (char *)0x0;
  puStack_54 = local_20;
  pcStack_58 = (char *)0x0;
  iStack_60 = 0x5aa535;
  (**(code **)(*piStack_5c + 0x4c))();
  puVar7 = (uint *)param_1[0x1d];
  iStack_60 = 0;
  uStack_64 = 0;
  puStack_68 = auStack_2c;
  fStack_6c = 0.0;
  (**(code **)(**(int **)(*param_2 + 0x18) + 0x4c))(*(int **)(*param_2 + 0x18));
  iStack_60 = param_2[0x1d];
  (**(code **)(**(int **)(*param_3 + 0x18) + 0x4c))(*(int **)(*param_3 + 0x18),0,auStack_38,0);
  iVar11 = param_3[0x1d];
  iVar10 = 0;
  do {
    iVar8 = 0;
    puStack_68 = (undefined1 *)((float)iVar10 * 0.06666667);
    fStack_6c = _K_ONE - (float)puStack_68;
    do {
      uVar4 = *(uint *)(iVar8 * 4);
      uStack_64 = uVar4;
      iStack_60 = FUN_005a8570(uVar4,param_4);
      uVar5 = FUN_005a8640(&uStack_64,&fStack_6c,2,0);
      *puVar7 = (uVar5 ^ uVar4) & 0xffffff ^ uVar4;
      iVar8 = iVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar8 < 0x10);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0x10);
  sVar3 = *(short *)((int)param_1 + 0x46);
  iVar10 = param_1[0x11];
  if (pcStack_58 < pcStack_58 + (int)sVar3 * (int)(short)iVar10) {
    pcVar6 = pcStack_50;
    pcVar9 = pcStack_58;
    do {
      pbVar1 = (byte *)(pcVar6 + (unaff_EDI - (int)pcStack_50));
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      *pcVar9 = (char)(*(uint *)(iVar11 + (uint)*pbVar1 * 4) >> 4) * '\x10' + cVar2;
      pcVar9 = pcVar9 + 1;
    } while (pcVar9 < pcStack_58 + (int)sVar3 * (int)(short)iVar10);
  }
  (**(code **)(**(int **)(*param_3 + 0x18) + 0x50))(*(int **)(*param_3 + 0x18),0);
  (**(code **)(**(int **)(*param_2 + 0x18) + 0x50))(*(int **)(*param_2 + 0x18),0);
  (**(code **)(**(int **)(*param_1 + 0x18) + 0x50))(*(int **)(*param_1 + 0x18),0);
  return 1;
}


// ==== 0x5aa680 FUN_005aa680

/* WARNING: Removing unreachable block (ram,0x005aa74a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005aa680(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int *unaff_EBP;
  uint *puVar6;
  int *unaff_ESI;
  int unaff_EDI;
  int iVar7;
  uint *puVar8;
  float fStack_64;
  undefined1 *puStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  uint *puStack_50;
  undefined1 *puStack_4c;
  uint *puStack_48;
  undefined4 uStack_44;
  int *piStack_30;
  undefined1 *puStack_2c;
  undefined1 auStack_24 [8];
  int *piStack_1c;
  undefined1 local_18 [12];
  int *piStack_c;
  
  piStack_54 = *(int **)(*param_1 + 0x18);
  uStack_44 = 0;
  puStack_48 = (uint *)0x0;
  puStack_4c = local_18;
  puStack_50 = (uint *)0x0;
  uStack_58 = 0x5aa6c5;
  (**(code **)(*piStack_54 + 0x4c))();
  uStack_58 = 0;
  uStack_5c = 0;
  puStack_60 = auStack_24;
  fStack_64 = 0.0;
  (**(code **)(**(int **)(*piStack_c + 0x18) + 0x4c))(*(int **)(*piStack_c + 0x18));
  (**(code **)(**(int **)(*piStack_1c + 0x18) + 0x4c))
            (*(int **)(*piStack_1c + 0x18),0,&piStack_30,0,0);
  puVar3 = puStack_50 + (int)*(short *)((int)param_1 + 0x46) * (int)(short)param_1[0x11];
  if (puStack_50 < puVar3) {
    iVar4 = unaff_EDI - (int)puStack_48;
    puVar5 = puStack_48;
    puVar6 = puStack_50;
    iVar7 = iVar4;
    puVar8 = puVar3;
    do {
      uVar1 = *(uint *)(iVar4 + (int)puVar5) & 0xff;
      if (uVar1 == 0) {
        uVar2 = *puVar5;
      }
      else {
        uVar2 = *puVar5;
        puStack_2c = (undefined1 *)((float)uVar1 * _K_BLUR_MIN_T);
        uStack_5c = uVar2;
        uStack_58 = FUN_005a8570(uVar2,(((param_4 >> 0x18) << 8 | param_4 & 0xff) << 8 |
                                       param_4 >> 8 & 0xff) << 8 | param_4 >> 0x10 & 0xff);
        fStack_64 = _K_ONE - (float)puStack_2c;
        puStack_60 = puStack_2c;
        iVar4 = iVar7;
        puVar3 = puVar8;
        uVar1 = FUN_005a8640(&uStack_5c,&fStack_64,2,0);
        uVar2 = (uVar1 ^ uVar2) & 0xffffff ^ uVar2;
        param_1 = unaff_EBP;
        iVar7 = iVar4;
        puVar8 = puVar3;
      }
      *puVar6 = uVar2;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    } while (puVar6 < puVar3);
  }
  (**(code **)(**(int **)(*piStack_30 + 0x18) + 0x50))(*(int **)(*piStack_30 + 0x18),0);
  (**(code **)(**(int **)(*unaff_ESI + 0x18) + 0x50))(*(int **)(*unaff_ESI + 0x18),0);
  (**(code **)(**(int **)(*param_1 + 0x18) + 0x50))(*(int **)(*param_1 + 0x18),0);
  return 1;
}


// ==== 0x5aa800 CompositeWheel

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 CompositeWheel(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  iVar1 = Texture_FindByHash(*(undefined4 *)(in_EAX + 0x448),0,0);
  if (iVar1 == 0) {
    return 1;
  }
  bVar9 = *(char *)(iVar1 + 0x4a) != ' ';
  uVar2 = GetWheelTextureHash(0,0);
  iVar3 = Texture_FindByHash(uVar2);
  uVar2 = GetWheelTextureMaskHash(0,0);
  iVar4 = Texture_FindByHash(uVar2);
  if ((iVar3 != 0) && (iVar4 != 0)) {
    uVar8 = 0xffffffff;
    if (*(int *)(in_EAX + 0x4f0) != 0) {
      uVar2 = 0;
      FUN_00567c70(0);
      iVar5 = FUN_0057cc70(uVar2);
      uVar2 = 0;
      FUN_00567c70(0);
      uVar6 = FUN_0057cc70(uVar2);
      uVar2 = 0;
      FUN_00567c70(0);
      uVar7 = FUN_0057cc70(uVar2);
      uVar2 = 0;
      FUN_00567c70(0);
      uVar8 = FUN_0057cc70(uVar2);
      uVar8 = ((iVar5 << 8 | uVar6) << 8 | uVar7) << 8 | uVar8;
    }
    if (bVar9) {
      if (*(char *)(iVar3 + 0x4a) == ' ') {
        return 0;
      }
      if (*(char *)(iVar4 + 0x4a) == ' ') {
        return 0;
      }
    }
    else {
      if (*(char *)(iVar3 + 0x4a) != ' ') {
        return 0;
      }
      if (*(char *)(iVar4 + 0x4a) != ' ') {
        return 0;
      }
    }
    if ((((*(short *)(iVar1 + 0x44) == *(short *)(iVar3 + 0x44)) &&
         (*(short *)(iVar1 + 0x44) == *(short *)(iVar4 + 0x44))) &&
        (*(short *)(iVar1 + 0x46) == *(short *)(iVar3 + 0x46))) &&
       (*(short *)(iVar1 + 0x46) == *(short *)(iVar4 + 0x46))) {
      if (bVar9) {
        uVar2 = FUN_005aa510(iVar1,iVar3,iVar4,uVar8);
        return uVar2;
      }
      uVar2 = FUN_005aa680();
      return uVar2;
    }
  }
  return 0;
}


// ==== 0x5aa970 TrafficIntersection_SavePtr

/* [canon] traffic med (H) docs/re/traffic.md */

void TrafficIntersection_SavePtr(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  int local_4;
  
  iVar1 = DAT_00736158;
  local_4 = -1;
  if ((*(char *)(unaff_ESI + 0x3c) != '\0') && (*unaff_EDI != 0)) {
    local_4 = (*unaff_EDI - DAT_00736158) / 0x170;
  }
  FUN_00571c20(unaff_ESI,&local_4,4,4,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    if ((-1 < local_4) && (local_4 < DAT_0073615c)) {
      *unaff_EDI = local_4 * 0x170 + iVar1;
      return;
    }
    *unaff_EDI = 0;
  }
  return;
}


// ==== 0x5aa9f0 TrafficIntersection_Save

/* [canon] traffic high (H+C) docs/re/traffic.md */

void TrafficIntersection_Save(int param_1)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  
  FUN_00571ea0(0,"TrafficIntersection");
  FUN_00571c20(in_EAX,param_1 + 0xc,1,4,1);
  iVar2 = 0;
  do {
    FUN_00571c20(in_EAX,param_1 + 6 + iVar2,1,1,1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  iVar2 = 0x16;
  do {
    IncomingTrafficCar_Save();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar2 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar2 + 0xc);
  cVar1 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5aaa90 IncomingTrafficCar_Save

/* [canon] traffic high (H+C) docs/re/traffic.md */

void IncomingTrafficCar_Save(void)

{
  int iVar1;
  char *in_EAX;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"IncomingTrafficCar");
  FUN_00571c20(unaff_ESI,in_EAX,1,1,1);
  if (*in_EAX != '\0') {
    FUN_00571c20(unaff_ESI,in_EAX + 4,1,4,1);
    FUN_00571c20(unaff_ESI,in_EAX + 8,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,in_EAX + 0xc,4,0xffffffff,0);
  }
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5aab20 FUN_005aab20

float10 __thiscall FUN_005aab20(int param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int unaff_ESI;
  float10 fVar9;
  
  iVar7 = 0;
  do {
    if (*(char *)(unaff_ESI + 4 + iVar7) == param_1) {
      if (iVar7 != -1) {
        if (param_1 < 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = (&DAT_0077af30)[param_1];
        }
        pfVar1 = (float *)(*(short *)(unaff_ESI + 8 + iVar7 * 2) * 0x88 + 0x27c + iVar8);
        iVar8 = (int)*(char *)((iVar7 == 0) + 4 + unaff_ESI);
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = (&DAT_0077af30)[iVar8];
        }
        iVar7 = *(short *)(unaff_ESI + 8 + (uint)(iVar7 == 0) * 2) * 0x88;
        pfVar2 = (float *)(iVar7 + 0x27c + iVar8);
        fVar3 = -*(float *)(iVar7 + 0x2a0 + iVar8);
        fVar4 = pfVar2[3] * 0.0 + pfVar2[4] * fVar3 + *pfVar2;
        fVar6 = pfVar2[3] * 0.0 + pfVar2[4] * pfVar2[10] + *pfVar2;
        fVar5 = pfVar2[4] * 0.0 + -pfVar2[3] * pfVar2[10] + pfVar2[1];
        fVar9 = (float10)(pfVar2[4] * 0.0 + -pfVar2[3] * fVar3 + pfVar2[1]) - (float10)pfVar1[1];
        if (param_2 == 0) {
          fVar9 = ((float10)fVar4 - (float10)*pfVar1) * (float10)pfVar1[3] +
                  fVar9 * (float10)pfVar1[4];
          fVar3 = (fVar5 - pfVar1[1]) * pfVar1[4];
          fVar4 = (fVar6 - *pfVar1) * pfVar1[3];
        }
        else {
          fVar9 = ((float10)fVar4 - (float10)*pfVar1) * (float10)pfVar1[5] +
                  fVar9 * (float10)pfVar1[6];
          fVar3 = (fVar5 - pfVar1[1]) * pfVar1[6];
          fVar4 = (fVar6 - *pfVar1) * pfVar1[5];
        }
        if ((float10)(fVar4 + fVar3) <= fVar9) {
          fVar9 = (float10)(fVar4 + fVar3);
        }
        return -fVar9;
      }
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  return (float10)0.0;
}


// ==== 0x5aaca0 FUN_005aaca0

uint __fastcall FUN_005aaca0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *unaff_ESI;
  float10 fVar2;
  
  uVar1 = *unaff_ESI - 1;
  switch(uVar1) {
  case 0:
  case 1:
    break;
  default:
switchD_005aaca8_caseD_2:
    return uVar1 & 0xffffff00;
  }
  uVar1 = unaff_ESI[3];
  if (uVar1 != param_2) {
    if (uVar1 == (param_2 == 0)) goto switchD_005aaca8_caseD_2;
    if (param_2 != 0) {
      fVar2 = (float10)FUN_005aae80();
      if ((float10)3.0 <= fVar2) {
        return 1;
      }
      return 0;
    }
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}


// ==== 0x5aad10 FUN_005aad10

undefined4 __fastcall FUN_005aad10(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  if ((*(int *)(*(int *)(in_EAX + 0x14) + 4) != 3) || (*(int *)(*(int *)(param_1 + 0x14) + 4) != 3))
  {
    return 1;
  }
  iVar1 = (*(short *)(in_EAX + 10) + -0x32) * 0x10 + unaff_ESI;
  if ((((*(char *)(iVar1 + 0x10) != '\0') &&
       (iVar2 = (*(short *)(param_1 + 10) + -0x32) * 0x10, iVar3 = iVar2 + unaff_ESI,
       *(char *)(iVar2 + 0x10 + unaff_ESI) != '\0')) && (0.0 <= *(float *)(iVar1 + 0x18))) &&
     ((0.0 <= *(float *)(iVar3 + 0x18) && (*(int *)(iVar1 + 0x14) != *(int *)(iVar3 + 0x14))))) {
    return 1;
  }
  return 0;
}


// ==== 0x5aad90 FUN_005aad90

int __fastcall FUN_005aad90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    if ((short)*(char *)(param_2 + 4 + iVar1) == *(short *)(param_1 + 10)) {
      if (iVar1 == -1) {
        return 0;
      }
      iVar2 = (int)*(char *)((iVar1 == 0) + 4 + param_2);
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (&DAT_0077af30)[iVar2];
      }
      return *(short *)(param_2 + 8 + (uint)(iVar1 == 0) * 2) * 0x88 + 0x27c + iVar2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return 0;
}


// ==== 0x5aadf0 FUN_005aadf0

void __fastcall FUN_005aadf0(int param_1,int param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  short sVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  if (*(int *)(*(int *)(in_EAX + 0x14) + 4) == 3) {
    sVar2 = *(short *)(in_EAX + 10);
    iVar3 = 0;
    do {
      if (*(char *)(param_2 + 4 + iVar3) == param_1) goto LAB_005aae17;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar3 = -1;
LAB_005aae17:
    iVar4 = (sVar2 + -0x32) * 0x10 + param_2;
    *(undefined4 *)(iVar4 + 0x18) = param_3;
    *(undefined1 *)(iVar4 + 0x10) = 1;
    *(float *)(iVar4 + 0x1c) = param_4;
    *(int *)(iVar4 + 0x14) = iVar3;
    if (iVar3 == -1) {
      *(undefined1 *)(iVar4 + 0x10) = 0;
    }
    else {
      iVar4 = (int)*(char *)(iVar3 + 6 + param_2);
      fVar1 = 99999.0;
      if (iVar4 != -1) {
        fVar1 = *(float *)(iVar4 * 0x10 + -0x304 + param_2);
      }
      if (param_4 < fVar1) {
        *(char *)(iVar3 + 6 + param_2) = (char)sVar2;
        return;
      }
    }
  }
  return;
}


// ==== 0x5aae80 FUN_005aae80

float10 __fastcall FUN_005aae80(int param_1)

{
  int in_EAX;
  int iVar1;
  float10 fVar2;
  
  iVar1 = (int)*(char *)(in_EAX + 6 + param_1);
  fVar2 = (float10)99999.0;
  if (iVar1 != -1) {
    fVar2 = (float10)*(float *)(iVar1 * 0x10 + -0x304 + param_1);
  }
  return fVar2;
}


// ==== 0x5aaea0 FUN_005aaea0

void FUN_005aaea0(void)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float unaff_ESI;
  int unaff_EDI;
  
  fVar1 = 999999.0;
  *(undefined1 *)((int)unaff_ESI + 6 + unaff_EDI) = 0xff;
  iVar3 = 0;
  pfVar2 = (float *)(unaff_EDI + 0x1c);
  do {
    if (((*(char *)(pfVar2 + -3) != '\0') && (pfVar2[-2] == unaff_ESI)) && (*pfVar2 < fVar1)) {
      *(char *)((int)unaff_ESI + 6 + unaff_EDI) = (char)iVar3 + '2';
      fVar1 = *pfVar2;
    }
    if (((*(char *)(pfVar2 + 1) != '\0') && (pfVar2[2] == unaff_ESI)) && (pfVar2[4] < fVar1)) {
      *(char *)((int)unaff_ESI + 6 + unaff_EDI) = (char)iVar3 + '3';
      fVar1 = pfVar2[4];
    }
    iVar3 = iVar3 + 2;
    pfVar2 = pfVar2 + 8;
  } while (iVar3 < 0x16);
  return;
}


// ==== 0x5aaf10 Intersection_Update

/* [canon] traffic med (G) docs/re/traffic.md */

void Intersection_Update(void)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int unaff_ESI;
  char local_4 [4];
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  if (iVar1 != -1) {
    local_4[0] = '\0';
    local_4[1] = '\0';
    local_4[2] = '\0';
    local_4[3] = '\0';
    pfVar2 = (float *)(unaff_ESI + 0x18);
    iVar3 = 0xb;
    do {
      if ((*(char *)(pfVar2 + -2) != '\0') && (*pfVar2 < 12.0)) {
        local_4[(int)pfVar2[-1]] = '\x01';
      }
      if ((*(char *)(pfVar2 + 2) != '\0') && (pfVar2[4] < 12.0)) {
        local_4[(int)pfVar2[3]] = '\x01';
      }
      pfVar2 = pfVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (local_4[iVar1] == '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = 0xffffffff;
    }
  }
  return;
}


// ==== 0x5aaf90 FUN_005aaf90

void FUN_005aaf90(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int *unaff_EBX;
  int local_4;
  
  piVar2 = (int *)*unaff_EBX;
  local_4 = -1;
  if ((*(char *)(in_EAX + 0x3c) != '\0') && (piVar2 != (int *)0x0)) {
    local_4 = *piVar2;
  }
  FUN_00571c20(in_EAX,&local_4,4,4,0);
  if (*(char *)(in_EAX + 0x3d) == '\0') {
    *unaff_EBX = (int)piVar2;
    return;
  }
  if ((local_4 != -1) && (iVar1 = 0, piVar2 = DAT_00736160, 0 < DAT_00736164)) {
    do {
      if (*piVar2 == local_4) {
        *unaff_EBX = (int)piVar2;
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x42;
    } while (iVar1 < DAT_00736164);
  }
  *unaff_EBX = 0;
  return;
}


// ==== 0x5ab010 FUN_005ab010

void FUN_005ab010(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"CrossTrafficEmitter");
  FUN_00571c20(unaff_ESI,in_EAX + 0x100,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xe0,0x20,0xffffffff,0);
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0x58 + unaff_ESI);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5ab080 FUN_005ab080

/* WARNING: Removing unreachable block (ram,0x005ab0cf) */
/* WARNING: Removing unreachable block (ram,0x005ab127) */

void __fastcall FUN_005ab080(int param_1)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  
  iVar4 = DAT_007361f8;
  iVar7 = 4;
  pfVar6 = (float *)(param_1 + 0x30);
  do {
    uVar2 = *(uint *)(iVar4 + 0x2d0);
    fVar1 = pfVar6[8];
    uVar8 = uVar2 ^ 0x1d872b41;
    uVar5 = uVar8 >> 5 ^ uVar8;
    *(uint *)(iVar4 + 0x2d0) = uVar5 << 0x1b ^ uVar5 ^ uVar8;
    fVar3 = (float)(uVar2 % 0x7fffffff) * 4.656613e-10 * fVar1;
    pfVar6[0x2c] = ((fVar3 + fVar3) - fVar1) + *pfVar6;
    uVar2 = *(uint *)(iVar4 + 0x2d0);
    fVar1 = pfVar6[9];
    uVar8 = uVar2 ^ 0x1d872b41;
    uVar5 = uVar8 >> 5 ^ uVar8;
    *(uint *)(iVar4 + 0x2d0) = uVar5 << 0x1b ^ uVar5 ^ uVar8;
    iVar7 = iVar7 + -1;
    fVar3 = (float)(uVar2 % 0x7fffffff) * 4.656613e-10 * fVar1;
    pfVar6[0x2d] = ((fVar3 + fVar3) - fVar1) + pfVar6[1];
    pfVar6 = pfVar6 + 2;
  } while (iVar7 != 0);
  return;
}


// ==== 0x5ab160 FUN_005ab160

int FUN_005ab160(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  
  iVar1 = *in_EAX;
  if ((-1 < iVar1) && (iVar2 = (&DAT_0077af30)[iVar1], iVar2 != 0)) {
    if (iVar1 < 0) {
      iVar2 = 0;
    }
    iVar1 = ((int)*(short *)(iVar2 + 0x10) / 2) * 0x88 + 0x27c + iVar2;
    if (DAT_007372b4 != 0) {
      return iVar1;
    }
  }
  return iVar1;
}


// ==== 0x5ab1b0 FUN_005ab1b0

float10 FUN_005ab1b0(void)

{
  float fVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar2 = *in_EAX;
  if ((iVar2 < 0) || (iVar3 = (&DAT_0077af30)[iVar2], iVar3 == 0)) {
    fVar4 = (float10)0.0;
  }
  else {
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    iVar2 = ((int)*(short *)(iVar3 + 0x10) / 2) * 0x88;
    fVar4 = (float10)*(float *)(iVar2 + 0x2a4 + iVar3);
    fVar1 = *(float *)(iVar2 + 0x2a0 + iVar3);
    if (fVar4 < (float10)fVar1) {
      return (float10)fVar1;
    }
  }
  return fVar4;
}


// ==== 0x5ab210 SpawnRecord_GetNode

/* [canon] traffic high (G+H) docs/re/traffic.md */

int __fastcall SpawnRecord_GetNode(undefined4 param_1,int *param_2,char param_3)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  int unaff_EDI;
  
  cVar1 = SpawnRecord_Allowed(unaff_EDI,param_1,in_EAX);
  if (cVar1 == '\0') {
    return 0;
  }
  if (param_3 != '\0') {
    if (*param_2 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[*param_2];
    }
    return *(short *)((int)param_2 + unaff_EDI * 2 + 4) * 0x88 + 0x27c + iVar2;
  }
  iVar2 = *param_2;
  if (unaff_EDI != 0) {
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[iVar2];
    }
    return *(short *)(iVar2 + 0x10) * 0x88 + 500 + iVar2;
  }
  if (-1 < iVar2) {
    return (&DAT_0077af30)[iVar2] + 0x27c;
  }
  return 0x27c;
}


// ==== 0x5ab2b0 FUN_005ab2b0

undefined1 * FUN_005ab2b0(int param_1,uint param_2,int param_3,undefined1 *param_4,char param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  byte local_7;
  byte local_6;
  byte local_5;
  
  if (param_1 == 0) {
    return (undefined1 *)0x0;
  }
  uVar2 = 0;
  puVar3 = (undefined1 *)0x0;
  if (param_2 != 0) {
    if (param_2 == 0) {
      local_6 = 0;
      goto LAB_005ab2f8;
    }
    do {
      local_6 = *(byte *)(param_1 + uVar2);
LAB_005ab2f8:
      if (uVar2 + 1 < param_2) {
        local_5 = *(byte *)(uVar2 + 1 + param_1);
      }
      else {
        local_5 = 0;
      }
      if (uVar2 + 2 < param_2) {
        local_7 = *(byte *)(uVar2 + 2 + param_1);
      }
      else {
        local_7 = 0;
      }
      uVar2 = uVar2 + 3;
      if ((param_3 != 0) && (puVar3 + param_3 + (3 - param_3) <= param_4)) {
        puVar3[param_3] = (&DAT_006b54d0)[local_6 >> 2];
        puVar3[param_3 + 1] = (&DAT_006b54d0)[(uint)(local_5 >> 4) | (local_6 & 3) << 4];
        if (uVar2 == param_2 + 2) {
          uVar1 = 0x3d;
        }
        else {
          uVar1 = (&DAT_006b54d0)[(uint)(local_7 >> 6) | (local_5 & 0xf) << 2];
        }
        puVar3[param_3 + 2] = uVar1;
        if (uVar2 < param_2 + 1) {
          uVar1 = (&DAT_006b54d0)[local_7 & 0x3f];
        }
        else {
          uVar1 = 0x3d;
        }
        puVar3[param_3 + 3] = uVar1;
      }
      puVar3 = puVar3 + 4;
    } while (uVar2 < param_2);
  }
  if (param_5 == '\x01') {
    if ((param_3 != 0) && (puVar3 < param_4)) {
      puVar3[param_3] = 0;
    }
    puVar3 = puVar3 + 1;
  }
  return puVar3;
}


// ==== 0x5ab3e0 FUN_005ab3e0

int FUN_005ab3e0(uint param_1,int param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int unaff_EDI;
  int local_14;
  
  uVar5 = 0;
  if ((unaff_EDI == 0) || (local_14 = 0, (param_1 & 3) != 0)) {
    return 0;
  }
  if (param_1 != 0) {
    do {
      cVar1 = *(char *)(uVar5 + unaff_EDI);
      cVar2 = *(char *)(uVar5 + 1 + unaff_EDI);
      cVar3 = *(char *)(uVar5 + 2 + unaff_EDI);
      cVar4 = *(char *)(uVar5 + 3 + unaff_EDI);
      uVar5 = uVar5 + 4;
      if ((*(int *)(&DAT_006b5510 + cVar1 * 4) == 0xff) && (cVar1 != '=')) {
        return 0;
      }
      if ((*(uint *)(&DAT_006b5510 + cVar2 * 4) == 0xff) && (cVar2 != '=')) {
        return 0;
      }
      iVar6 = (int)cVar3;
      if ((*(int *)(&DAT_006b5510 + iVar6 * 4) == 0xff) && (cVar3 != '=')) {
        return 0;
      }
      if ((*(int *)(&DAT_006b5510 + cVar4 * 4) == 0xff) && (cVar4 != '=')) {
        return 0;
      }
      if (cVar3 == '=') {
        uVar7 = 1;
      }
      else {
        uVar7 = (cVar4 != '=') + 2;
      }
      if ((param_2 != 0) && (local_14 + 2U <= param_3)) {
        if (uVar7 != 0) {
          *(byte *)(local_14 + param_2) =
               (byte)(*(uint *)(&DAT_006b5510 + cVar2 * 4) >> 4) | (&DAT_006b5510)[cVar1 * 4] << 2;
        }
        if (1 < uVar7) {
          *(byte *)(local_14 + 1 + param_2) =
               (byte)(*(uint *)(&DAT_006b5510 + iVar6 * 4) >> 2) | (&DAT_006b5510)[cVar2 * 4] << 4;
        }
        if (2 < uVar7) {
          *(undefined *)(local_14 + 2 + param_2) =
               (&DAT_006b5510)[iVar6 * 4] << 6 | (&DAT_006b5510)[cVar4 * 4];
        }
      }
      local_14 = local_14 + uVar7;
    } while (uVar5 < param_1);
  }
  return local_14;
}


// ==== 0x5ab550 MovieSubtitles::FindByName

/* [canon] assets high (Hopper sub_5ab550) docs/re/assets.md */

uint MovieSubtitles__FindByName(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_00733f3c;
  if (DAT_00733f34 == 0) {
    return 0xffffffff;
  }
  uVar3 = 0;
  if (DAT_00733f3c != 0) {
    do {
      iVar2 = bStrICmp();
      if (iVar2 == 0) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}


// ==== 0x5ab5a0 MovieSubtitles::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_5ab5a0) docs/re/assets.md */

void MovieSubtitles__Update(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  DWORD DVar4;
  
  if (-1 < DAT_00733f30) {
    DVar4 = timeGetTime();
    fVar2 = (float)(int)(DVar4 - _DAT_00733f40);
    if ((int)(DVar4 - _DAT_00733f40) < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    if (DAT_00733f28 + 1 < *(int *)(DAT_00733f34 + DAT_00733f30 * 0x10)) {
      iVar1 = *(int *)(*(int *)(DAT_00733f34 + DAT_00733f30 * 0x10 + 8) + 4 + DAT_00733f28 * 4);
      fVar3 = (float)iVar1;
      if (iVar1 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      if (fVar3 < fVar2 * 0.001) {
        DAT_00733f28 = DAT_00733f28 + 1;
        FUN_004f66f0();
        return;
      }
    }
  }
  return;
}


// ==== 0x5ab640 MovieSubtitles::Loader

/* [canon] assets high (Ghidra make FUN_005ab640 (Hopper export lacks it)) docs/re/assets.md */

undefined4 MovieSubtitles__Loader(int *param_1)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  if (*param_1 == 0x39010) {
    DAT_00733f3c = param_1[2];
    pbVar8 = (byte *)(param_1 + 3);
    DAT_00733f34 = _malloc(DAT_00733f3c << 4);
    uVar9 = 0;
    if (DAT_00733f3c != 0) {
      piVar5 = (int *)((int)DAT_00733f34 + 4);
      do {
        piVar5[-1] = (uint)*pbVar8;
        pbVar8 = pbVar8 + 4;
        piVar5[1] = (int)pbVar8;
        piVar5[2] = (int)(pbVar8 + piVar5[-1] * 4);
        pbVar8 = pbVar8 + piVar5[-1] * 4 + piVar5[-1] * 4;
        iVar6 = 0;
        *piVar5 = (int)pbVar8;
        if (pbVar8 != (byte *)0x0) {
          bVar2 = *pbVar8;
          while (bVar2 != 0) {
            iVar1 = iVar6 + 1;
            iVar6 = iVar6 + 1;
            bVar2 = pbVar8[iVar1];
          }
        }
        pcVar4 = (char *)*piVar5;
        uVar7 = 0;
        if (pcVar4 != (char *)0x0) {
          cVar3 = *pcVar4;
          while (cVar3 != '\0') {
            iVar1 = uVar7 + 1;
            uVar7 = uVar7 + 1;
            cVar3 = pcVar4[iVar1];
          }
        }
        uVar7 = uVar7 & 0x80000003;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
        }
        pbVar8 = pbVar8 + (4 - uVar7) + iVar6;
        uVar9 = uVar9 + 1;
        piVar5 = piVar5 + 4;
      } while (uVar9 < DAT_00733f3c);
    }
    return 1;
  }
  return 0;
}


// ==== 0x5ab700 MovieSubtitles::Unloader

/* [canon] assets high (Hopper sub_5ab700 + Ghidra make FUN_005ab700: H+G agree) docs/re/assets.md
    */

undefined4 MovieSubtitles__Unloader(int *param_1)

{
  if (*param_1 == 0x39010) {
    _free(DAT_00733f34);
    DAT_00733f34 = (void *)0x0;
    return 1;
  }
  return 0;
}


// ==== 0x5ab730 Direct3DCreate9_Thunk

/* [canon] render high (hopper+capstone) docs/re/render.md */

void Direct3DCreate9_Thunk(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ab730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Direct3DCreate9();
  return;
}


// ==== 0x5ab736 FUN_005ab736

undefined4 FUN_005ab736(float param_1,float param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 - param_2;
  if ((NAN(param_1) || -1.1920929e-07 < param_1 == (param_1 == -1.1920929e-07)) ||
     (param_1 < 1.1920929e-07 == (param_1 == 1.1920929e-07))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== 0x5ab766 FUN_005ab766

void FUN_005ab766(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab76d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba4)();
  return;
}


// ==== 0x5ab773 FUN_005ab773

void FUN_005ab773(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(uint *)(param_2 + uVar4 * 4);
      uVar3 = uVar1 & 0x7fffffff;
      uVar2 = (ushort)(uVar1 >> 0x10) & 0x8000;
      if (uVar3 < 0x47fff000) {
        if (uVar3 < 0x38800000) {
          uVar3 = (uVar1 & 0x7fffff | 0x800000) >> (0x71U - (char)(uVar3 >> 0x17) & 0x1f);
          uVar3 = (uVar3 >> 0xd & 1) + 0xfff + uVar3;
        }
        else {
          uVar3 = (uVar3 >> 0xd & 1) + 0xc8000fff + uVar3;
        }
        uVar2 = (ushort)(uVar3 >> 0xd) | uVar2;
      }
      else {
        uVar2 = uVar2 | 0x7fff;
      }
      *(ushort *)(param_1 + uVar4 * 2) = uVar2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  return;
}


// ==== 0x5ab802 FUN_005ab802

void FUN_005ab802(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab809. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba8)();
  return;
}


// ==== 0x5ab80f FUN_005ab80f

int FUN_005ab80f(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)(param_2 + uVar4 * 2);
      uVar2 = (uint)uVar1;
      if ((uVar1 & 0x7c00) == 0) {
        if ((uVar1 & 0x3ff) == 0) {
          uVar2 = (uVar2 & 0xffff8000) << 0x10;
        }
        else {
          iVar5 = -0xe;
          for (uVar3 = uVar2 & 0x3ff; (uVar3 & 0x400) == 0; uVar3 = uVar3 << 1) {
            iVar5 = iVar5 + -1;
          }
          uVar2 = (((uVar2 & 0xffff8080) << 3 | uVar3) & 0xfffffbff) << 0xd |
                  (iVar5 + 0x7f) * 0x800000;
        }
      }
      else {
        uVar2 = ((uVar2 & 0xffff8000) << 3 | uVar2 & 0x3ff) << 0xd |
                ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000;
      }
      *(uint *)(param_1 + uVar4 * 4) = uVar2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  return param_1;
}


// ==== 0x5ab8b4 FUN_005ab8b4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab8b4(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ab8bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b78)();
  return;
}


// ==== 0x5ab8c1 FUN_005ab8c1

void FUN_005ab8c1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b04)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5ab8eb FUN_005ab8eb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab8eb(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = ((fVar2 + fVar2) - fVar1 * 3.0) + _K_ONE;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar3 = fVar1 * 3.0 - (fVar2 + fVar2);
  *param_1 = (fVar2 - fVar1) * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
  param_1[1] = fVar4 * param_2[1] +
               param_6 * param_3[1] + fVar3 * param_4[1] + (fVar2 - fVar1) * param_5[1];
  return;
}


// ==== 0x5ab979 FUN_005ab979

void FUN_005ab979(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b7c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5ab9a3 FUN_005ab9a3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab9a3(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = _K_HALF;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * 2.0 - fVar2) - param_6;
  fVar3 = (fVar2 * 3.0 - fVar1 * 5.0) + 2.0;
  param_6 = (fVar1 * 4.0 - fVar2 * 3.0) + param_6;
  *param_1 = ((fVar2 - fVar1) * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2)
             * _K_HALF;
  param_1[1] = (fVar4 * param_2[1] +
               fVar3 * param_3[1] + param_6 * param_4[1] + (fVar2 - fVar1) * param_5[1]) * fVar5;
  return;
}


// ==== 0x5aba52 FUN_005aba52

void FUN_005aba52(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b80)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5aba81 FUN_005aba81

void FUN_005aba81(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  return;
}


// ==== 0x5abac4 FUN_005abac4

void FUN_005abac4(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abacb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ac0)();
  return;
}


// ==== 0x5abad1 thunk_FUN_005abac4

void thunk_FUN_005abac4(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abad1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ac0)();
  return;
}


// ==== 0x5abad7 FUN_005abad7

void FUN_005abad7(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abae2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bac)();
  return;
}


// ==== 0x5abae8 FUN_005abae8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abae8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abaef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ae4)();
  return;
}


// ==== 0x5abaf5 thunk_FUN_005abae8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005abae8(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abaf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ae4)();
  return;
}


// ==== 0x5abafb FUN_005abafb

void FUN_005abafb(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abb06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bb0)();
  return;
}


// ==== 0x5abb0c FUN_005abb0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abb0c(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abb13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad4)();
  return;
}


// ==== 0x5abb19 thunk_FUN_005abb0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005abb0c(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abb19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad4)();
  return;
}


// ==== 0x5abb1f FUN_005abb1f

void FUN_005abb1f(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abb2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bb4)();
  return;
}


// ==== 0x5abb30 FUN_005abb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abb30(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abb37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4adc)();
  return;
}


// ==== 0x5abb3d thunk_FUN_005abb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005abb30(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abb3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4adc)();
  return;
}


// ==== 0x5abb43 FUN_005abb43

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abb43(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*_DAT_006d4b84)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5abb6d FUN_005abb6d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abb6d(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = ((fVar2 + fVar2) - fVar1 * 3.0) + _K_ONE;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar3 = fVar1 * 3.0 - (fVar2 + fVar2);
  fVar2 = fVar2 - fVar1;
  *param_1 = fVar2 * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
  param_1[1] = fVar4 * param_2[1] + param_6 * param_3[1] + fVar3 * param_4[1] + fVar2 * param_5[1];
  param_1[2] = fVar4 * param_2[2] + param_6 * param_3[2] + fVar3 * param_4[2] + fVar2 * param_5[2];
  return;
}


// ==== 0x5abc1b FUN_005abc1b

void FUN_005abc1b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b88)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5abc45 FUN_005abc45

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abc45(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = _K_HALF;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * 2.0 - fVar2) - param_6;
  fVar3 = (fVar2 * 3.0 - fVar1 * 5.0) + 2.0;
  param_6 = (fVar1 * 4.0 - fVar2 * 3.0) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) * _K_HALF
  ;
  param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1])
               * fVar5;
  param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2])
               * fVar5;
  return;
}


// ==== 0x5abd16 FUN_005abd16

void FUN_005abd16(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b8c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5abd45 FUN_005abd45

void FUN_005abd45(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  param_1[2] = (param_4[2] - param_2[2]) * param_6 + (param_3[2] - param_2[2]) * param_5 +
               param_2[2];
  return;
}


// ==== 0x5abda2 FUN_005abda2

void FUN_005abda2(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abda9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ac4)();
  return;
}


// ==== 0x5abdaf D3DXVec3Transform

/* [canon] render low (capstone) docs/re/render.md */

void D3DXVec3Transform(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abdaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ac4)();
  return;
}


// ==== 0x5abdb5 FUN_005abdb5

void FUN_005abdb5(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[9];
  fVar2 = param_2[2];
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[1];
  fVar6 = *param_2;
  fVar7 = param_3[0xd];
  fVar8 = param_3[10];
  fVar9 = param_2[2];
  fVar10 = param_3[6];
  fVar11 = param_2[1];
  fVar12 = param_3[2];
  fVar13 = *param_2;
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xb];
  fVar16 = param_2[2];
  fVar17 = param_3[7];
  fVar18 = param_2[1];
  fVar19 = param_3[3];
  fVar20 = *param_2;
  fVar21 = param_3[0xf];
  *param_1 = *param_2 * *param_3 + param_3[4] * param_2[1] + param_3[8] * param_2[2] + param_3[0xc];
  param_1[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7;
  param_1[2] = fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14;
  param_1[3] = fVar19 * fVar20 + fVar17 * fVar18 + fVar15 * fVar16 + fVar21;
  return;
}


// ==== 0x5abe40 FUN_005abe40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abe40(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abe4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bb8)();
  return;
}


// ==== 0x5abe51 FUN_005abe51

float * FUN_005abe51(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float *pfVar2;
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
  float *pfVar25;
  
  pfVar25 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    pfVar2 = param_3 + 2;
    fVar3 = *param_3;
    fVar4 = param_5[1];
    fVar5 = *param_3;
    fVar6 = param_5[5];
    fVar7 = param_3[1];
    fVar8 = param_5[9];
    fVar9 = param_3[2];
    fVar10 = param_5[0xd];
    fVar11 = param_3[2];
    fVar12 = param_5[10];
    fVar13 = *param_3;
    fVar14 = param_5[2];
    fVar15 = param_3[1];
    fVar16 = param_5[6];
    fVar17 = param_5[0xe];
    fVar18 = param_5[3];
    fVar19 = *param_3;
    fVar20 = param_5[7];
    fVar21 = param_3[1];
    fVar22 = param_5[0xb];
    fVar23 = param_3[2];
    param_3 = (float *)((int)param_3 + param_4);
    fVar24 = param_5[0xf];
    *pfVar25 = fVar3 * *param_5 + param_5[8] * *pfVar2 + param_5[4] * *pfVar1 + param_5[0xc];
    pfVar25[1] = fVar8 * fVar9 + fVar6 * fVar7 + fVar4 * fVar5 + fVar10;
    pfVar25[2] = fVar15 * fVar16 + fVar13 * fVar14 + fVar11 * fVar12 + fVar17;
    pfVar25[3] = fVar22 * fVar23 + fVar20 * fVar21 + fVar18 * fVar19 + fVar24;
    pfVar25 = (float *)((int)pfVar25 + param_2);
  }
  return param_1;
}


// ==== 0x5abef8 FUN_005abef8

void FUN_005abef8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abeff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ae8)();
  return;
}


// ==== 0x5abf05 thunk_FUN_005abef8

void thunk_FUN_005abef8(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abf05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ae8)();
  return;
}


// ==== 0x5abf0b FUN_005abf0b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abf0b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abf16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bbc)();
  return;
}


// ==== 0x5abf1c thunk_FUN_005abf0b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005abf0b(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abf1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bbc)();
  return;
}


// ==== 0x5abf22 FUN_005abf22

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abf22(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abf29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad8)();
  return;
}


// ==== 0x5abf2f thunk_FUN_005abf22

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005abf22(void)

{
                    /* WARNING: Could not recover jumptable at 0x005abf2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad8)();
  return;
}


// ==== 0x5abf35 FUN_005abf35

void FUN_005abf35(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[9];
  fVar2 = param_2[2];
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[1];
  fVar6 = *param_2;
  fVar7 = param_3[10];
  fVar8 = param_2[2];
  fVar9 = param_3[6];
  fVar10 = param_2[1];
  fVar11 = param_3[2];
  fVar12 = *param_2;
  *param_1 = *param_2 * *param_3 + param_3[4] * param_2[1] + param_3[8] * param_2[2];
  param_1[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  return;
}


// ==== 0x5abf9b FUN_005abf9b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abf9b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005abfa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bc0)();
  return;
}


// ==== 0x5abfac FUN_005abfac

float * FUN_005abfac(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float *pfVar2;
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
  float *pfVar16;
  
  pfVar16 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    pfVar2 = param_3 + 2;
    fVar3 = *param_3;
    fVar4 = param_5[1];
    fVar5 = *param_3;
    fVar6 = param_5[5];
    fVar7 = param_3[1];
    fVar8 = param_5[9];
    fVar9 = param_3[2];
    fVar10 = param_3[2];
    fVar11 = param_5[10];
    fVar12 = *param_3;
    fVar13 = param_5[2];
    fVar14 = param_3[1];
    param_3 = (float *)((int)param_3 + param_4);
    fVar15 = param_5[6];
    *pfVar16 = fVar3 * *param_5 + param_5[8] * *pfVar2 + param_5[4] * *pfVar1;
    pfVar16[1] = fVar8 * fVar9 + fVar6 * fVar7 + fVar4 * fVar5;
    pfVar16[2] = fVar14 * fVar15 + fVar12 * fVar13 + fVar10 * fVar11;
    pfVar16 = (float *)((int)pfVar16 + param_2);
  }
  return param_1;
}


// ==== 0x5ac02a FUN_005ac02a

void FUN_005ac02a(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac035. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4af8)();
  return;
}


// ==== 0x5ac03b FUN_005ac03b

void FUN_005ac03b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac046. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bc8)();
  return;
}


// ==== 0x5ac04c FUN_005ac04c

void FUN_005ac04c(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac057. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4afc)();
  return;
}


// ==== 0x5ac05d FUN_005ac05d

void FUN_005ac05d(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bcc)();
  return;
}


// ==== 0x5ac06e FUN_005ac06e

void FUN_005ac06e(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b00)();
  return;
}


// ==== 0x5ac07b FUN_005ac07b

void FUN_005ac07b(float *param_1,float *param_2,float *param_3,float *param_4)

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
  
  fVar1 = param_4[3];
  fVar2 = param_3[2];
  fVar3 = param_3[3];
  fVar4 = param_4[2];
  fVar26 = param_4[3] * param_3[1] - param_3[3] * param_4[1];
  fVar5 = param_3[1];
  fVar6 = param_4[2];
  fVar7 = param_3[2];
  fVar8 = param_4[1];
  fVar9 = param_3[3];
  fVar10 = *param_4;
  fVar11 = param_4[3];
  fVar12 = *param_3;
  fVar27 = *param_4 * param_3[2] - *param_3 * param_4[2];
  fVar13 = *param_2;
  fVar14 = param_2[2];
  fVar15 = param_2[3];
  fVar16 = *param_3;
  fVar17 = param_4[1];
  fVar18 = *param_4;
  fVar19 = param_3[1];
  fVar20 = *param_2;
  fVar21 = param_2[1];
  fVar22 = param_2[3];
  fVar23 = *param_2;
  fVar24 = param_2[1];
  fVar25 = param_2[2];
  *param_1 = (fVar5 * fVar6 - fVar7 * fVar8) * param_2[3] +
             ((fVar1 * fVar2 - fVar3 * fVar4) * param_2[1] - fVar26 * param_2[2]);
  param_1[1] = fVar27 * fVar15 +
               ((fVar3 * fVar4 - fVar1 * fVar2) * fVar13 -
               (fVar9 * fVar10 - fVar11 * fVar12) * fVar14);
  param_1[2] = (fVar16 * fVar17 - fVar18 * fVar19) * fVar22 +
               (fVar26 * fVar20 - (fVar11 * fVar12 - fVar9 * fVar10) * fVar21);
  param_1[3] = (fVar18 * fVar19 - fVar16 * fVar17) * fVar25 +
               ((fVar7 * fVar8 - fVar5 * fVar6) * fVar23 - fVar27 * fVar24);
  return;
}


// ==== 0x5ac16b FUN_005ac16b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac16b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ae0)();
  return;
}


// ==== 0x5ac178 FUN_005ac178

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac178(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*_DAT_006d4b90)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5ac1a2 FUN_005ac1a2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac1a2(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar3 = ((fVar2 + fVar2) - fVar1 * 3.0) + _K_ONE;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar4 = fVar1 * 3.0 - (fVar2 + fVar2);
  fVar2 = fVar2 - fVar1;
  *param_1 = fVar2 * *param_5 + fVar4 * *param_4 + param_6 * *param_3 + fVar3 * *param_2;
  param_1[1] = fVar3 * param_2[1] + param_6 * param_3[1] + fVar4 * param_4[1] + fVar2 * param_5[1];
  param_1[2] = fVar3 * param_2[2] + param_6 * param_3[2] + fVar4 * param_4[2] + fVar2 * param_5[2];
  param_1[3] = fVar3 * param_2[3] + param_6 * param_3[3] + fVar4 * param_4[3] + fVar2 * param_5[3];
  return;
}


// ==== 0x5ac273 FUN_005ac273

void FUN_005ac273(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b94)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5ac29d FUN_005ac29d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac29d(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = _K_HALF;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * 2.0 - fVar2) - param_6;
  fVar3 = (fVar2 * 3.0 - fVar1 * 5.0) + 2.0;
  param_6 = (fVar1 * 4.0 - fVar2 * 3.0) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) * _K_HALF
  ;
  param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1])
               * fVar5;
  param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2])
               * fVar5;
  param_1[3] = (fVar4 * param_2[3] + fVar3 * param_3[3] + param_6 * param_4[3] + fVar2 * param_5[3])
               * fVar5;
  return;
}


// ==== 0x5ac390 FUN_005ac390

void FUN_005ac390(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b98)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5ac3bf FUN_005ac3bf

void FUN_005ac3bf(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  param_1[2] = (param_4[2] - param_2[2]) * param_6 + (param_3[2] - param_2[2]) * param_5 +
               param_2[2];
  param_1[3] = (param_4[3] - param_2[3]) * param_6 + (param_3[3] - param_2[3]) * param_5 +
               param_2[3];
  return;
}


// ==== 0x5ac436 FUN_005ac436

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac436(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac43d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ac8)();
  return;
}


// ==== 0x5ac443 thunk_FUN_005ac436

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005ac436(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ac443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ac8)();
  return;
}


// ==== 0x5ac449 Vec4TransformInPlace

/* [canon] render I (C) docs/re/blur.md */

void Vec4TransformInPlace(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[0xd];
  fVar2 = param_2[3];
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[1];
  fVar6 = *param_2;
  fVar7 = param_3[9];
  fVar8 = param_2[2];
  fVar9 = param_3[0xe];
  fVar10 = param_2[3];
  fVar11 = param_3[6];
  fVar12 = param_2[1];
  fVar13 = param_3[2];
  fVar14 = *param_2;
  fVar15 = param_3[10];
  fVar16 = param_2[2];
  fVar17 = param_3[0xf];
  fVar18 = param_2[3];
  fVar19 = param_3[7];
  fVar20 = param_2[1];
  fVar21 = param_3[3];
  fVar22 = *param_2;
  fVar23 = param_3[0xb];
  fVar24 = param_2[2];
  *param_1 = *param_2 * *param_3 +
             param_3[8] * param_2[2] + param_3[4] * param_2[1] + param_3[0xc] * param_2[3];
  param_1[1] = fVar7 * fVar8 + fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[2] = fVar15 * fVar16 + fVar13 * fVar14 + fVar11 * fVar12 + fVar9 * fVar10;
  param_1[3] = fVar23 * fVar24 + fVar21 * fVar22 + fVar19 * fVar20 + fVar17 * fVar18;
  return;
}


// ==== 0x5ac4e8 FUN_005ac4e8

void FUN_005ac4e8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac4f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4bc4)();
  return;
}


// ==== 0x5ac4f9 FUN_005ac4f9

float * FUN_005ac4f9(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
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
  float *pfVar29;
  
  pfVar29 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    pfVar2 = param_3 + 2;
    pfVar3 = param_3 + 3;
    fVar4 = *param_3;
    fVar5 = param_5[5];
    fVar6 = param_3[1];
    fVar7 = param_5[0xd];
    fVar8 = param_3[3];
    fVar9 = param_5[9];
    fVar10 = param_3[2];
    fVar11 = *param_3;
    fVar12 = param_5[1];
    fVar13 = param_5[2];
    fVar14 = *param_3;
    fVar15 = param_5[6];
    fVar16 = param_3[1];
    fVar17 = param_5[10];
    fVar18 = param_3[2];
    fVar19 = param_3[3];
    fVar20 = param_5[0xe];
    fVar21 = param_3[3];
    fVar22 = param_5[0xf];
    fVar23 = param_5[3];
    fVar24 = *param_3;
    fVar25 = param_5[7];
    fVar26 = param_3[1];
    fVar27 = param_5[0xb];
    fVar28 = param_3[2];
    param_3 = (float *)((int)param_3 + param_4);
    *pfVar29 = fVar4 * *param_5 +
               *pfVar3 * param_5[0xc] + param_5[8] * *pfVar2 + param_5[4] * *pfVar1;
    pfVar29[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8 + fVar5 * fVar6;
    pfVar29[2] = fVar19 * fVar20 + fVar17 * fVar18 + fVar15 * fVar16 + fVar13 * fVar14;
    pfVar29[3] = fVar27 * fVar28 + fVar25 * fVar26 + fVar23 * fVar24 + fVar21 * fVar22;
    pfVar29 = (float *)((int)pfVar29 + param_2);
  }
  return param_1;
}


// ==== 0x5ac5b8 FUN_005ac5b8

void FUN_005ac5b8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac5bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4aec)();
  return;
}


// ==== 0x5ac5c5 FUN_005ac5c5

void FUN_005ac5c5(void)

{
  return;
}


// ==== 0x5ac68f D3DXMatrixMultiply_Entry

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+capstone) docs/re/render.md */

void D3DXMatrixMultiply_Entry(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac696. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4acc)();
  return;
}


// ==== 0x5ac69c D3DXMatrixMultiply

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (capstone) docs/re/render.md */

void D3DXMatrixMultiply(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ac69c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4acc)();
  return;
}


// ==== 0x5ac6a2 FUN_005ac6a2

void FUN_005ac6a2(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float afStack_44 [16];
  
  if ((param_1 == param_2) || (pfVar2 = param_1, param_1 == param_3)) {
    pfVar2 = afStack_44;
  }
  *pfVar2 = param_3[4] * param_2[1] +
            param_2[2] * param_3[8] + *param_2 * *param_3 + param_2[3] * param_3[0xc];
  pfVar2[1] = param_3[1] * *param_2 +
              param_2[2] * param_3[9] + param_2[3] * param_3[0xd] + param_2[1] * param_3[5];
  pfVar2[2] = param_3[6] * param_2[1] +
              param_2[2] * param_3[10] + param_3[2] * *param_2 + param_2[3] * param_3[0xe];
  pfVar2[3] = param_3[7] * param_2[1] +
              *param_2 * param_3[3] + param_3[0xb] * param_2[2] + param_2[3] * param_3[0xf];
  pfVar2[4] = param_2[6] * param_3[8] +
              param_3[4] * param_2[5] + param_2[4] * *param_3 + param_2[7] * param_3[0xc];
  pfVar2[5] = param_3[1] * param_2[4] +
              param_3[5] * param_2[5] + param_2[7] * param_3[0xd] + param_2[6] * param_3[9];
  pfVar2[6] = param_2[6] * param_3[10] +
              param_3[2] * param_2[4] + param_2[7] * param_3[0xe] + param_3[6] * param_2[5];
  pfVar2[7] = param_2[4] * param_3[3] +
              param_2[6] * param_3[0xb] + param_2[7] * param_3[0xf] + param_3[7] * param_2[5];
  pfVar2[8] = param_2[10] * param_3[8] +
              param_3[4] * param_2[9] + param_2[8] * *param_3 + param_2[0xb] * param_3[0xc];
  pfVar2[9] = param_3[1] * param_2[8] +
              param_3[5] * param_2[9] + param_2[10] * param_3[9] + param_2[0xb] * param_3[0xd];
  pfVar2[10] = param_2[10] * param_3[10] +
               param_2[0xb] * param_3[0xe] + param_3[2] * param_2[8] + param_3[6] * param_2[9];
  pfVar2[0xb] = param_2[8] * param_3[3] +
                param_3[7] * param_2[9] + param_2[10] * param_3[0xb] + param_2[0xb] * param_3[0xf];
  pfVar2[0xc] = param_2[0xe] * param_3[8] +
                param_3[4] * param_2[0xd] + param_2[0xc] * *param_3 + param_2[0xf] * param_3[0xc];
  pfVar2[0xd] = param_3[1] * param_2[0xc] +
                param_3[5] * param_2[0xd] + param_2[0xe] * param_3[9] + param_2[0xf] * param_3[0xd];
  pfVar2[0xe] = param_2[0xe] * param_3[10] +
                param_2[0xf] * param_3[0xe] + param_3[2] * param_2[0xc] + param_3[6] * param_2[0xd];
  pfVar2[0xf] = param_2[0xc] * param_3[3] +
                param_3[7] * param_2[0xd] +
                param_2[0xe] * param_3[0xb] + param_2[0xf] * param_3[0xf];
  if (pfVar2 != param_1) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== 0x5ac8d8 FUN_005ac8d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac8d8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac8df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b54)();
  return;
}


// ==== 0x5ac8e5 D3DXMatrixTranspose

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (capstone) docs/re/render.md */

void D3DXMatrixTranspose(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ac8e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b54)();
  return;
}


// ==== 0x5ac8eb FUN_005ac8eb

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


// ==== 0x5ac958 FUN_005ac958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac958(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ac95f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4ad0)();
  return;
}


// ==== 0x5ac965 FUN_005ac965

void FUN_005ac965(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float afStack_44 [16];
  
  if ((param_1 == param_2) || (pfVar2 = param_1, param_1 == param_3)) {
    pfVar2 = afStack_44;
  }
  *pfVar2 = param_3[4] * param_2[1] +
            param_2[2] * param_3[8] + *param_2 * *param_3 + param_2[3] * param_3[0xc];
  pfVar2[1] = param_3[4] * param_2[5] +
              param_3[8] * param_2[6] + param_3[0xc] * param_2[7] + param_2[4] * *param_3;
  pfVar2[2] = param_2[8] * *param_3 +
              param_3[0xc] * param_2[0xb] + param_2[9] * param_3[4] + param_2[10] * param_3[8];
  pfVar2[3] = param_2[0xe] * param_3[8] +
              *param_3 * param_2[0xc] + param_2[0xf] * param_3[0xc] + param_2[0xd] * param_3[4];
  pfVar2[4] = param_2[1] * param_3[5] +
              param_3[0xd] * param_2[3] + param_3[1] * *param_2 + param_3[9] * param_2[2];
  pfVar2[5] = param_2[4] * param_3[1] +
              param_2[5] * param_3[5] + param_3[9] * param_2[6] + param_3[0xd] * param_2[7];
  pfVar2[6] = param_2[8] * param_3[1] +
              param_3[9] * param_2[10] + param_3[0xd] * param_2[0xb] + param_2[9] * param_3[5];
  pfVar2[7] = param_3[1] * param_2[0xc] +
              param_3[9] * param_2[0xe] + param_3[0xd] * param_2[0xf] + param_2[0xd] * param_3[5];
  pfVar2[8] = param_3[0xe] * param_2[3] +
              param_2[1] * param_3[6] + param_3[2] * *param_2 + param_3[10] * param_2[2];
  pfVar2[9] = param_2[4] * param_3[2] +
              param_2[5] * param_3[6] + param_3[10] * param_2[6] + param_3[0xe] * param_2[7];
  pfVar2[10] = param_2[8] * param_3[2] +
               param_3[10] * param_2[10] + param_3[0xe] * param_2[0xb] + param_2[9] * param_3[6];
  pfVar2[0xb] = param_3[2] * param_2[0xc] +
                param_3[10] * param_2[0xe] + param_3[0xe] * param_2[0xf] + param_2[0xd] * param_3[6]
  ;
  pfVar2[0xc] = param_3[0xf] * param_2[3] +
                param_2[1] * param_3[7] + param_3[3] * *param_2 + param_3[0xb] * param_2[2];
  pfVar2[0xd] = param_2[4] * param_3[3] +
                param_2[5] * param_3[7] + param_3[0xb] * param_2[6] + param_3[0xf] * param_2[7];
  pfVar2[0xe] = param_2[8] * param_3[3] +
                param_3[0xb] * param_2[10] + param_3[0xf] * param_2[0xb] + param_2[9] * param_3[7];
  pfVar2[0xf] = param_3[3] * param_2[0xc] +
                param_3[0xb] * param_2[0xe] +
                param_3[0xf] * param_2[0xf] + param_2[0xd] * param_3[7];
  if (pfVar2 != param_1) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== 0x5acb9b FUN_005acb9b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005acb9b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005acba2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b08)();
  return;
}


// ==== 0x5acba8 thunk_FUN_005acb9b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005acb9b(void)

{
                    /* WARNING: Could not recover jumptable at 0x005acba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b08)();
  return;
}


// ==== 0x5acbae FUN_005acbae

float * FUN_005acbae(float *param_1,float *param_2,float *param_3)

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
  int iVar32;
  float *pfVar33;
  
  fVar3 = param_3[4];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar4 = param_3[5];
  fVar5 = param_3[8];
  fVar6 = param_3[9];
  fVar7 = param_3[0xc];
  fVar19 = fVar4 * fVar1 - fVar3 * fVar2;
  fVar8 = param_3[0xd];
  fVar9 = param_3[0xe];
  fVar10 = param_3[0xf];
  fVar18 = fVar6 * fVar1 - fVar5 * fVar2;
  fVar17 = fVar8 * fVar1 - fVar7 * fVar2;
  fVar20 = fVar6 * fVar3 - fVar5 * fVar4;
  fVar21 = fVar8 * fVar3 - fVar7 * fVar4;
  fVar22 = fVar8 * fVar5 - fVar7 * fVar6;
  fVar1 = param_3[2];
  fVar2 = param_3[3];
  fVar3 = param_3[6];
  fVar4 = param_3[7];
  fVar5 = param_3[10];
  fVar6 = param_3[0xb];
  fVar31 = fVar1 * fVar4 - fVar3 * fVar2;
  fVar30 = fVar1 * fVar6 - fVar5 * fVar2;
  fVar23 = fVar1 * fVar10 - fVar9 * fVar2;
  fVar11 = *param_3;
  fVar12 = param_3[4];
  fVar13 = param_3[8];
  fVar28 = fVar3 * fVar6 - fVar5 * fVar4;
  fVar14 = param_3[9];
  fVar29 = fVar3 * fVar10 - fVar9 * fVar4;
  fVar15 = param_3[0xc];
  fVar26 = fVar5 * fVar10 - fVar9 * fVar6;
  fVar7 = param_3[1];
  fVar8 = param_3[5];
  fVar16 = param_3[0xd];
  fVar27 = (fVar30 * fVar8 - fVar31 * fVar14) - fVar28 * fVar7;
  fVar24 = fVar31 * fVar16 + (fVar29 * fVar7 - fVar23 * fVar8);
  fVar25 = (fVar23 * fVar14 - fVar30 * fVar16) - fVar26 * fVar7;
  fVar7 = fVar28 * fVar16 + (fVar26 * fVar8 - fVar29 * fVar14);
  fVar8 = fVar7 * fVar11 + fVar25 * fVar12 + fVar24 * fVar13 + fVar27 * fVar15;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar8;
  }
  if (fVar8 == 0.0) {
    pfVar33 = (float *)0x0;
  }
  else {
    fVar8 = 1.0 / fVar8;
    iVar32 = _finite((double)fVar8);
    pfVar33 = (float *)0x0;
    if (iVar32 != 0) {
      *param_1 = fVar7 * fVar8;
      param_1[1] = fVar25 * fVar8;
      param_1[2] = fVar24 * fVar8;
      param_1[3] = fVar27 * fVar8;
      param_1[4] = ((fVar29 * fVar13 - fVar28 * fVar15) - fVar26 * fVar12) * fVar8;
      param_1[5] = (fVar30 * fVar15 + (fVar11 * fVar26 - fVar23 * fVar13)) * fVar8;
      param_1[6] = ((fVar23 * fVar12 - fVar31 * fVar15) - fVar29 * fVar11) * fVar8;
      param_1[7] = (fVar31 * fVar13 + (fVar28 * fVar11 - fVar30 * fVar12)) * fVar8;
      param_1[8] = (fVar20 * fVar10 + (fVar22 * fVar4 - fVar21 * fVar6)) * fVar8;
      param_1[9] = ((fVar17 * fVar6 - fVar18 * fVar10) - fVar22 * fVar2) * fVar8;
      param_1[10] = (fVar19 * fVar10 + (fVar21 * fVar2 - fVar17 * fVar4)) * fVar8;
      param_1[0xb] = ((fVar18 * fVar4 - fVar19 * fVar6) - fVar20 * fVar2) * fVar8;
      param_1[0xc] = ((fVar5 * fVar21 - fVar9 * fVar20) - fVar3 * fVar22) * fVar8;
      param_1[0xd] = (fVar9 * fVar18 + (fVar1 * fVar22 - fVar5 * fVar17)) * fVar8;
      param_1[0xe] = ((fVar3 * fVar17 - fVar9 * fVar19) - fVar1 * fVar21) * fVar8;
      param_1[0xf] = (fVar5 * fVar19 + (fVar1 * fVar20 - fVar3 * fVar18)) * fVar8;
      pfVar33 = param_1;
    }
  }
  return pfVar33;
}


// ==== 0x5acf4d FUN_005acf4d

void FUN_005acf4d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b44)(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x5acf7b FUN_005acf7b

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


// ==== 0x5acfd7 FUN_005acfd7

void FUN_005acfd7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b28)(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x5ad005 FUN_005ad005

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


// ==== 0x5ad061 FUN_005ad061

void FUN_005ad061(undefined4 param_1,undefined4 param_2)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b38)(param_1,param_2);
  return;
}


// ==== 0x5ad07d FUN_005ad07d

void FUN_005ad07d(undefined4 *param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)param_2);
  fVar2 = (float10)fsin((float10)param_2);
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[6] = (float)fVar2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = (float)fVar1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = -(float)fVar2;
  param_1[10] = (float)fVar1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}


// ==== 0x5ad0f7 FUN_005ad0f7

void FUN_005ad0f7(undefined4 param_1,undefined4 param_2)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b3c)(param_1,param_2);
  return;
}


// ==== 0x5ad113 FUN_005ad113

void FUN_005ad113(float *param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)param_2);
  fVar2 = (float10)fsin((float10)param_2);
  *param_1 = (float)fVar1;
  param_1[1] = 0.0;
  param_1[2] = -(float)fVar2;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = 1.0;
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = (float)fVar2;
  param_1[9] = 0.0;
  param_1[10] = (float)fVar1;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x5ad18e FUN_005ad18e

void FUN_005ad18e(undefined4 param_1,undefined4 param_2)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b40)(param_1,param_2);
  return;
}


// ==== 0x5ad1aa FUN_005ad1aa

void FUN_005ad1aa(float *param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)param_2);
  fVar2 = (float10)fsin((float10)param_2);
  *param_1 = (float)fVar1;
  param_1[1] = (float)fVar2;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = -(float)fVar2;
  param_1[5] = (float)fVar1;
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  param_1[10] = 1.0;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x5ad226 FUN_005ad226

void FUN_005ad226(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b68)(param_1,param_2,param_3);
  return;
}


// ==== 0x5ad246 FUN_005ad246

void FUN_005ad246(float *param_1,float *param_2,float param_3)

{
  float10 fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float local_20;
  float local_1c;
  float local_18;
  float *local_14;
  float *local_10;
  float local_c;
  float local_8;
  
  local_10 = &local_8;
  local_14 = &local_c;
  fVar1 = (float10)fcos((float10)param_3);
  fVar6 = (float10)fsin((float10)param_3);
  local_8 = (float)fVar1;
  local_c = (float)fVar6;
  fVar2 = 1.0 - local_8;
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = param_2[2];
  thunk_FUN_005abb30(&local_20,&local_20);
  fVar3 = local_1c * local_20 * fVar2;
  fVar4 = local_1c * local_18 * fVar2;
  fVar5 = local_18 * local_20 * fVar2;
  *param_1 = local_20 * local_20 * fVar2 + local_8;
  param_1[1] = fVar3 + local_18 * local_c;
  param_1[2] = fVar5 - local_1c * local_c;
  param_1[3] = 0.0;
  param_1[4] = fVar3 - local_18 * local_c;
  param_1[5] = local_1c * local_1c * fVar2 + local_8;
  param_1[6] = local_20 * local_c + fVar4;
  param_1[7] = 0.0;
  param_1[8] = local_1c * local_c + fVar5;
  param_1[9] = fVar4 - local_20 * local_c;
  param_1[10] = local_18 * local_18 * fVar2 + local_8;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x5ad348 FUN_005ad348

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad348(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad34f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b58)();
  return;
}


// ==== 0x5ad355 thunk_FUN_005ad348

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005ad348(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ad355. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b58)();
  return;
}


// ==== 0x5ad35b FUN_005ad35b

void FUN_005ad35b(float *param_1,float *param_2)

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
  fVar10 = param_2[1] * 2.0;
  fVar11 = param_2[2] * 2.0;
  fVar12 = fVar1 * 2.0 * param_2[3];
  fVar2 = param_2[3];
  fVar3 = param_2[3];
  fVar4 = *param_2;
  fVar5 = *param_2;
  fVar6 = *param_2;
  fVar7 = param_2[1];
  fVar8 = param_2[1];
  fVar9 = param_2[2];
  *param_1 = (1.0 - fVar10 * fVar7) - fVar11 * fVar9;
  param_1[1] = fVar10 * fVar5 + fVar11 * fVar3;
  param_1[2] = fVar11 * fVar6 - fVar10 * fVar2;
  param_1[3] = 0.0;
  param_1[4] = fVar10 * fVar5 - fVar11 * fVar3;
  fVar1 = 1.0 - fVar1 * 2.0 * fVar4;
  param_1[5] = fVar1 - fVar11 * fVar9;
  param_1[6] = fVar11 * fVar8 + fVar12;
  param_1[7] = 0.0;
  param_1[8] = fVar11 * fVar6 + fVar10 * fVar2;
  param_1[9] = fVar11 * fVar8 - fVar12;
  param_1[10] = fVar1 - fVar10 * fVar7;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x5ad43d FUN_005ad43d

void FUN_005ad43d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b60)(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x5ad46b FUN_005ad46b

void FUN_005ad46b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad476. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b5c)();
  return;
}


// ==== 0x5ad47c FUN_005ad47c

void FUN_005ad47c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b64)(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== 0x5ad4a3 FUN_005ad4a3

undefined4 *
FUN_005ad4a3(undefined4 *param_1,undefined4 param_2,float *param_3,int param_4,float *param_5)

{
  undefined1 auStack_58 [8];
  undefined1 local_50 [76];
  
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[5] = param_2;
  param_1[10] = param_2;
  param_1[0xf] = 0x3f800000;
  if (param_4 != 0) {
    thunk_FUN_005ad348(local_50,param_4);
    if (param_3 == (float *)0x0) {
      D3DXMatrixMultiply(param_1,param_1,auStack_58);
    }
    else {
      param_1[0xc] = (float)param_1[0xc] - *param_3;
      param_1[0xd] = (float)param_1[0xd] - param_3[1];
      param_1[0xe] = (float)param_1[0xe] - param_3[2];
      D3DXMatrixMultiply(param_1,param_1,auStack_58);
      param_1[0xc] = *param_3 + (float)param_1[0xc];
      param_1[0xd] = (float)param_1[0xd] + param_3[1];
      param_1[0xe] = param_3[2] + (float)param_1[0xe];
    }
  }
  if (param_5 != (float *)0x0) {
    param_1[0xc] = *param_5 + (float)param_1[0xc];
    param_1[0xd] = param_5[1] + (float)param_1[0xd];
    param_1[0xe] = param_5[2] + (float)param_1[0xe];
  }
  return param_1;
}


// ==== 0x5ad589 FUN_005ad589

void FUN_005ad589(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b2c)();
  return;
}


// ==== 0x5ad596 FUN_005ad596

void FUN_005ad596(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad59d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b30)();
  return;
}


// ==== 0x5ad5a3 FUN_005ad5a3

void FUN_005ad5a3(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad5aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b1c)();
  return;
}


// ==== 0x5ad5b0 FUN_005ad5b0

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


// ==== 0x5ad5e5 FUN_005ad5e5

void FUN_005ad5e5(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad5ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b20)();
  return;
}


// ==== 0x5ad5f2 FUN_005ad5f2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad5f2(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int aiStack_20 [3];
  float afStack_14 [3];
  int iStack_8;
  
  pfVar4 = param_2;
  fVar3 = param_2[5] + *param_2 + param_2[10];
  if (fVar3 <= 0.0) {
    aiStack_20[2] = 0;
    afStack_14[0] = (*param_2 - param_2[5]) - param_2[10];
    aiStack_20[0] = 1;
    aiStack_20[1] = 2;
    afStack_14[1] = (param_2[5] - *param_2) - param_2[10];
    afStack_14[2] = param_2[10] - (param_2[5] + *param_2);
    param_2 = (float *)(uint)(afStack_14[0] < afStack_14[1]);
    if (afStack_14[(int)param_2] < afStack_14[2]) {
      param_2 = (float *)0x2;
    }
    iStack_8 = aiStack_20[(int)param_2];
    fVar3 = SQRT(afStack_14[(int)param_2] + _K_ONE) * _K_HALF;
    param_1[(int)param_2] = fVar3;
    fVar3 = 0.25 / fVar3;
    iVar1 = aiStack_20[iStack_8];
    iVar5 = iVar1 * 4;
    iVar2 = aiStack_20[iStack_8];
    param_1[iStack_8] =
         (pfVar4[(int)param_2 + iStack_8 * 4] + pfVar4[iStack_8 + (int)param_2 * 4]) * fVar3;
    param_1[iVar1] = (pfVar4[(int)param_2 + iVar5] + pfVar4[(int)param_2 * 4 + iVar2]) * fVar3;
    param_1[3] = (pfVar4[iStack_8 * 4 + iVar2] - pfVar4[iVar5 + iStack_8]) * fVar3;
  }
  else {
    fVar3 = SQRT(fVar3 + _K_ONE) * _K_HALF;
    param_1[3] = fVar3;
    fVar3 = 0.25 / fVar3;
    *param_1 = (param_2[6] - param_2[9]) * fVar3;
    param_1[1] = (param_2[8] - param_2[2]) * fVar3;
    param_1[2] = (param_2[1] - param_2[4]) * fVar3;
  }
  return;
}


// ==== 0x5ad726 FUN_005ad726

void FUN_005ad726(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b34)(param_1,param_2,param_3);
  return;
}


// ==== 0x5ad746 FUN_005ad746

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005ad746(float *param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float local_18;
  float local_14;
  float local_10;
  
  thunk_FUN_005abb30(&local_18,param_2);
  fVar2 = (float10)fcos((float10)(param_3 * _K_HALF));
  fVar3 = (float10)fsin((float10)(param_3 * _K_HALF));
  param_1[3] = (float)fVar2;
  fVar1 = (float)fVar3;
  *param_1 = local_18 * fVar1;
  param_1[1] = local_14 * fVar1;
  param_1[2] = local_10 * fVar1;
  return param_1;
}


// ==== 0x5ad7a2 FUN_005ad7a2

void FUN_005ad7a2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b24)(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x5ad7d0 thunk_FUN_005ad7a2

void thunk_FUN_005ad7a2(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ad7d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b24)();
  return;
}


// ==== 0x5ad7d6 FUN_005ad7d6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad7d6(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar3 = (float10)fcos((float10)(param_4 * _K_HALF));
  fVar6 = (float10)fsin((float10)(param_4 * _K_HALF));
  fVar1 = (float)fVar3;
  fVar2 = (float)fVar6;
  fVar3 = (float10)fcos((float10)(param_3 * _K_HALF));
  fVar7 = (float10)fsin((float10)(param_3 * _K_HALF));
  fVar6 = (float10)fcos((float10)(param_2 * _K_HALF));
  fVar8 = (float10)fsin((float10)(param_2 * _K_HALF));
  fVar4 = (float)fVar8 * (float)fVar3;
  fVar5 = (float)fVar6 * (float)fVar7;
  *param_1 = fVar4 * fVar2 + fVar1 * fVar5;
  param_1[1] = fVar4 * fVar1 - fVar5 * fVar2;
  fVar4 = (float)fVar6 * (float)fVar3;
  fVar5 = (float)fVar8 * (float)fVar7;
  param_1[2] = fVar4 * fVar2 - fVar5 * fVar1;
  param_1[3] = fVar4 * fVar1 + fVar5 * fVar2;
  return;
}


// ==== 0x5ad8af FUN_005ad8af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad8af(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad8b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b0c)();
  return;
}


// ==== 0x5ad8bc thunk_FUN_005ad8af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005ad8af(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ad8bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b0c)();
  return;
}


// ==== 0x5ad8c2 FUN_005ad8c2

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


// ==== 0x5ad958 FUN_005ad958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad958(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad95f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b10)();
  return;
}


// ==== 0x5ad965 FUN_005ad965

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad965(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ad96c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b70)();
  return;
}


// ==== 0x5ad972 thunk_FUN_005ad965

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005ad965(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ad972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b70)();
  return;
}


// ==== 0x5ad978 FUN_005ad978

float * FUN_005ad978(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float *extraout_ECX;
  
  fVar1 = param_2[3] * param_2[3] +
          param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (fVar1 <= 1.0842022e-19) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    fVar1 = 0.0;
  }
  else {
    *param_1 = -*param_2;
    param_1[1] = -param_2[1];
    param_1[2] = -param_2[2];
    param_1[3] = param_2[3];
    iVar2 = FUN_005ab736(fVar1,0x3f800000);
    if (iVar2 != 0) {
      return extraout_ECX;
    }
    fVar1 = 1.0 / fVar1;
    *extraout_ECX = fVar1 * *extraout_ECX;
    extraout_ECX[1] = fVar1 * extraout_ECX[1];
    extraout_ECX[2] = fVar1 * extraout_ECX[2];
    fVar1 = fVar1 * extraout_ECX[3];
    param_1 = extraout_ECX;
  }
  param_1[3] = fVar1;
  return param_1;
}


// ==== 0x5ada29 FUN_005ada29

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ada29(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ada30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b9c)();
  return;
}


// ==== 0x5ada36 thunk_FUN_005ada29

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005ada29(void)

{
                    /* WARNING: Could not recover jumptable at 0x005ada36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b9c)();
  return;
}


// ==== 0x5ada3c FUN_005ada3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ada3c(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_2[3] < _K_ONE) {
    fVar3 = (float10)FUN_00672e20();
    fVar4 = (float10)fsin(fVar3);
    iVar2 = FUN_005ab736((float)fVar4,0);
    if (iVar2 == 0) {
      fVar1 = (float)fVar3 / (float)fVar4;
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      goto LAB_005adaad;
    }
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
LAB_005adaad:
  param_1[3] = 0.0;
  return;
}


// ==== 0x5adab7 FUN_005adab7

void FUN_005adab7(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005adabe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba0)();
  return;
}


// ==== 0x5adac4 thunk_FUN_005adab7

void thunk_FUN_005adab7(void)

{
                    /* WARNING: Could not recover jumptable at 0x005adac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4ba0)();
  return;
}


// ==== 0x5adaca FUN_005adaca

float * FUN_005adaca(float *param_1,float *param_2)

{
  float10 fVar1;
  float fVar2;
  int iVar3;
  float *extraout_ECX;
  float10 fVar4;
  
  fVar2 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  fVar4 = (float10)fVar2;
  fVar1 = (float10)fcos(fVar4);
  fVar4 = (float10)fsin(fVar4);
  param_1[3] = (float)fVar1;
  iVar3 = FUN_005ab736((float)fVar4,0);
  if (iVar3 == 0) {
    fVar2 = (float)fVar4 / fVar2;
    *param_1 = fVar2 * *extraout_ECX;
    param_1[1] = fVar2 * extraout_ECX[1];
    param_1[2] = fVar2 * extraout_ECX[2];
  }
  else if (param_1 != extraout_ECX) {
    *param_1 = *extraout_ECX;
    param_1[1] = extraout_ECX[1];
    param_1[2] = extraout_ECX[2];
  }
  return param_1;
}


// ==== 0x5adb00 FUN_005adb00

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


// ==== 0x5adb62 FUN_005adb62

void FUN_005adb62(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b4c)(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x5adb86 thunk_FUN_005adb62

void thunk_FUN_005adb62(void)

{
                    /* WARNING: Could not recover jumptable at 0x005adb86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b4c)();
  return;
}


// ==== 0x5adb8c FUN_005adb8c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005adb8c(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  pfVar2 = param_2;
  fVar3 = (float10)1 - (float10)param_4;
  fVar5 = (float10)param_3[3] * (float10)param_2[3] +
          (float10)param_3[1] * (float10)param_2[1] +
          (float10)param_3[2] * (float10)param_2[2] + (float10)*param_2 * (float10)*param_3;
  if (fVar5 < (float10)0.0) {
    param_2 = (float *)0xbf800000;
  }
  else {
    param_2 = (float *)0x3f800000;
  }
  fVar5 = (float10)(float)param_2 * fVar5;
  if ((float10)1 - fVar5 <= (float10)1.1920929e-07) {
    fVar5 = (float10)param_4;
  }
  else {
    fVar4 = SQRT((float10)_K_ONE - fVar5 * fVar5);
    fVar5 = (float10)fpatan(fVar4,(float10)(float)fVar5);
    fVar1 = (float)((float10)1 / fVar4);
    fVar3 = (float10)fsin((float10)(float)fVar5 * fVar3);
    fVar3 = fVar3 * (float10)fVar1;
    fVar5 = (float10)fsin((float10)(float)fVar5 * (float10)param_4);
    fVar5 = fVar5 * (float10)fVar1;
  }
  fVar5 = fVar5 * (float10)(float)param_2;
  *param_1 = (float)(fVar5 * (float10)*param_3 + fVar3 * (float10)*pfVar2);
  param_1[1] = (float)(fVar3 * (float10)pfVar2[1] + fVar5 * (float10)param_3[1]);
  param_1[2] = (float)(fVar3 * (float10)pfVar2[2] + fVar5 * (float10)param_3[2]);
  param_1[3] = (float)(fVar3 * (float10)pfVar2[3] + fVar5 * (float10)param_3[3]);
  return;
}


// ==== 0x5adc6f FUN_005adc6f

void FUN_005adc6f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*(code *)PTR_FUN_006d4b6c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5adc99 FUN_005adc99

undefined4
FUN_005adc99(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,float param_6)

{
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  thunk_FUN_005adb62(local_24,param_2,param_5,param_6);
  thunk_FUN_005adb62(local_14,param_3,param_4,param_6);
  param_6 = (1.0 - param_6) * param_6;
  thunk_FUN_005adb62(param_1,local_24,local_14,param_6 + param_6);
  return param_1;
}


// ==== 0x5adcf0 FUN_005adcf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005adcf0(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005adcfb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4b74)();
  return;
}


// ==== 0x5add01 FUN_005add01

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005add01(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  D3DXPSGP_Init(1);
  (*_DAT_006d4b50)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x5add30 FUN_005add30

undefined4 *
FUN_005add30(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            float param_5,float param_6)

{
  int iVar1;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  param_5 = param_5 + param_6;
  iVar1 = FUN_005ab736(param_5,0);
  if (iVar1 == 0) {
    thunk_FUN_005adb62(local_24,param_2,param_3,param_5);
    thunk_FUN_005adb62(local_14,param_2,param_4,param_5);
    thunk_FUN_005adb62(param_1,local_24,local_14,param_6 / param_5);
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return param_1;
}


// ==== 0x5addb8 FUN_005addb8

void FUN_005addb8(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005addbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b14)();
  return;
}


// ==== 0x5addc5 thunk_FUN_005addb8

void thunk_FUN_005addb8(void)

{
                    /* WARNING: Could not recover jumptable at 0x005addc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b14)();
  return;
}


// ==== 0x5addcb FUN_005addcb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005addcb(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar2 = FUN_005ab736(fVar1,0x3f800000);
  if (iVar2 == 0) {
    if (fVar1 <= 1.1754944e-38) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      fVar1 = 0.0;
    }
    else {
      fVar1 = _K_ONE / SQRT(fVar1);
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      fVar1 = fVar1 * param_2[3];
    }
    param_1[3] = fVar1;
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return;
}


// ==== 0x5ade6c FUN_005ade6c

void FUN_005ade6c(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ade73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b18)();
  return;
}


// ==== 0x5ade79 FUN_005ade79

float * FUN_005ade79(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = param_3[2] * param_2[2] + param_2[1] * param_3[1] + *param_2 * *param_3;
  fVar2 = fVar1 - (param_2[1] * param_4[1] + param_4[2] * param_2[2] + *param_2 * *param_4);
  if (fVar2 != 0.0) {
    fVar2 = (fVar1 + param_2[3]) / fVar2;
    iVar3 = _finite((double)fVar2);
    if (iVar3 != 0) {
      *param_1 = (*param_4 - *param_3) * fVar2 + *param_3;
      param_1[1] = (param_4[1] - param_3[1]) * fVar2 + param_3[1];
      param_1[2] = (param_4[2] - param_3[2]) * fVar2 + param_3[2];
      return param_1;
    }
  }
  return (float *)0x0;
}


// ==== 0x5adf1b FUN_005adf1b

void FUN_005adf1b(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005adf22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4af0)();
  return;
}


// ==== 0x5adf28 FUN_005adf28

void FUN_005adf28(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  param_1[3] = -(*param_2 * *param_3 + param_2[2] * param_3[2] + param_2[1] * param_3[1]);
  return;
}


// ==== 0x5adf60 FUN_005adf60

void FUN_005adf60(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005adf67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4af4)();
  return;
}


// ==== 0x5adf6d FUN_005adf6d

void FUN_005adf6d(float *param_1,float *param_2,float *param_3,float *param_4)

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
  fVar2 = *param_3;
  fVar3 = param_2[1];
  fVar4 = param_3[1];
  fVar5 = param_2[2];
  fVar6 = param_3[2];
  fVar7 = *param_2;
  fVar8 = *param_4;
  fVar9 = param_2[1];
  fVar10 = param_4[1];
  fVar11 = param_2[2];
  fVar12 = param_4[2];
  *param_1 = (fVar11 - fVar12) * (fVar3 - fVar4) - (fVar9 - fVar10) * (fVar5 - fVar6);
  param_1[1] = (fVar5 - fVar6) * (fVar7 - fVar8) - (fVar11 - fVar12) * (fVar1 - fVar2);
  param_1[2] = (fVar9 - fVar10) * (fVar1 - fVar2) - (fVar7 - fVar8) * (fVar3 - fVar4);
  thunk_FUN_005abb30(param_1,param_1);
  param_1[3] = -(*param_1 * *param_2 + param_1[1] * param_2[1] + param_1[2] * param_2[2]);
  return;
}


// ==== 0x5ae00f FUN_005ae00f

void FUN_005ae00f(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ae016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006d4b48)();
  return;
}


// ==== 0x5ae01c FUN_005ae01c

void FUN_005ae01c(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[9];
  fVar2 = param_2[2];
  fVar3 = param_3[1];
  fVar4 = *param_2;
  fVar5 = param_3[0xd];
  fVar6 = param_2[3];
  fVar7 = param_3[5];
  fVar8 = param_2[1];
  fVar9 = param_3[10];
  fVar10 = param_2[2];
  fVar11 = param_3[2];
  fVar12 = *param_2;
  fVar13 = param_3[0xe];
  fVar14 = param_2[3];
  fVar15 = param_3[6];
  fVar16 = param_2[1];
  fVar17 = param_3[0xb];
  fVar18 = param_2[2];
  fVar19 = param_3[3];
  fVar20 = *param_2;
  fVar21 = param_3[0xf];
  fVar22 = param_2[3];
  fVar23 = param_3[7];
  fVar24 = param_2[1];
  *param_1 = *param_2 * *param_3 +
             param_3[4] * param_2[1] + param_3[0xc] * param_2[3] + param_3[8] * param_2[2];
  param_1[1] = fVar7 * fVar8 + fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[2] = fVar15 * fVar16 + fVar13 * fVar14 + fVar11 * fVar12 + fVar9 * fVar10;
  param_1[3] = fVar23 * fVar24 + fVar21 * fVar22 + fVar19 * fVar20 + fVar17 * fVar18;
  return;
}


// ==== 0x5ae0bb FUN_005ae0bb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ae0bb(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ae0c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bd0)();
  return;
}


// ==== 0x5ae0cc FUN_005ae0cc

float * FUN_005ae0cc(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
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
  float *pfVar29;
  
  pfVar29 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    pfVar2 = param_3 + 3;
    pfVar3 = param_3 + 2;
    fVar4 = *param_3;
    fVar5 = param_3[2];
    fVar6 = param_5[9];
    fVar7 = *param_3;
    fVar8 = param_5[1];
    fVar9 = param_3[1];
    fVar10 = param_5[5];
    fVar11 = param_5[0xd];
    fVar12 = param_3[3];
    fVar13 = param_3[3];
    fVar14 = param_5[0xe];
    fVar15 = param_3[1];
    fVar16 = param_5[6];
    fVar17 = param_5[2];
    fVar18 = *param_3;
    fVar19 = param_3[2];
    fVar20 = param_5[10];
    fVar21 = param_3[2];
    fVar22 = param_5[0xb];
    fVar23 = param_5[3];
    fVar24 = *param_3;
    fVar25 = param_3[1];
    fVar26 = param_5[7];
    fVar27 = param_3[3];
    param_3 = (float *)((int)param_3 + param_4);
    fVar28 = param_5[0xf];
    *pfVar29 = fVar4 * *param_5 +
               *pfVar3 * param_5[8] + param_5[0xc] * *pfVar2 + *pfVar1 * param_5[4];
    pfVar29[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8 + fVar5 * fVar6;
    pfVar29[2] = fVar19 * fVar20 + fVar17 * fVar18 + fVar15 * fVar16 + fVar13 * fVar14;
    pfVar29[3] = fVar27 * fVar28 + fVar25 * fVar26 + fVar23 * fVar24 + fVar21 * fVar22;
    pfVar29 = (float *)((int)pfVar29 + param_2);
  }
  return param_1;
}


// ==== 0x5ae18b FUN_005ae18b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005ae18b(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float10 extraout_ST0;
  float10 fVar16;
  float10 extraout_ST0_00;
  float10 fVar17;
  float10 extraout_ST0_01;
  float10 fVar18;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  
  uVar11 = __ftol();
  fVar16 = (float10)_K_ONE;
  uVar12 = __ftol();
  fVar17 = extraout_ST0_00 - (float10)(int)uVar12;
  uVar12 = uVar12 & 0xff;
  uVar15 = uVar12 + 1 & 0xff;
  fVar4 = (float)(fVar17 - (float10)_K_ONE);
  fVar21 = extraout_ST1;
  uVar13 = __ftol();
  uVar14 = uVar13 & 0xff;
  fVar18 = extraout_ST0_01 - (float10)(int)uVar13;
  uVar13 = uVar14 + 1 & 0xff;
  fVar5 = (float)fVar18;
  fVar6 = (float)(fVar18 - (float10)_K_ONE);
  fVar7 = (float)(((float10)3.0 - (fVar21 + fVar21)) * fVar21 * fVar21);
  fVar8 = (float)(((float10)3.0 - (extraout_ST1_00 + extraout_ST1_00)) * extraout_ST1_00 *
                 extraout_ST1_00);
  iVar1 = (*(int *)(&DAT_00697460 + (*(int *)(&DAT_00697460 + (uVar11 & 0xff) * 4) + uVar12) * 4) +
          uVar14) * 0xc;
  fVar19 = fVar21 * (float10)*(float *)(&DAT_00697c68 + iVar1) +
           extraout_ST1_00 * (float10)*(float *)(&DAT_00697c6c + iVar1) +
           fVar18 * (float10)*(float *)(&DAT_00697c70 + iVar1);
  iVar1 = (*(int *)(&DAT_00697460 +
                   (uVar12 + *(int *)(&DAT_00697460 + ((uVar11 & 0xff) + 1 & 0xff) * 4)) * 4) +
          uVar14) * 0xc;
  iVar2 = (*(int *)(&DAT_00697460 + (*(int *)(&DAT_00697460 + (uVar11 & 0xff) * 4) + uVar15) * 4) +
          uVar14) * 0xc;
  iVar3 = (uVar14 + *(int *)(&DAT_00697460 +
                            (*(int *)(&DAT_00697460 + ((uVar11 & 0xff) + 1 & 0xff) * 4) + uVar15) *
                            4)) * 0xc;
  fVar19 = ((fVar17 * (float10)*(float *)(&DAT_00697c68 + iVar1) +
            extraout_ST1_00 * (float10)*(float *)(&DAT_00697c6c + iVar1) +
            fVar18 * (float10)*(float *)(&DAT_00697c70 + iVar1)) - fVar19) * (float10)fVar7 + fVar19
  ;
  fVar20 = fVar21 * (float10)*(float *)(&DAT_00697c68 + iVar2) +
           (float10)fVar4 * (float10)*(float *)(&DAT_00697c6c + iVar2) +
           fVar18 * (float10)*(float *)(&DAT_00697c70 + iVar2);
  iVar1 = (*(int *)(&DAT_00697460 + (*(int *)(&DAT_00697460 + (uVar11 & 0xff) * 4) + uVar12) * 4) +
          uVar13) * 0xc;
  fVar9 = (float)(((((fVar17 * (float10)*(float *)(&DAT_00697c68 + iVar3) +
                     (float10)fVar4 * (float10)*(float *)(&DAT_00697c6c + iVar3) +
                     fVar18 * (float10)*(float *)(&DAT_00697c70 + iVar3)) - fVar20) * (float10)fVar7
                   + fVar20) - fVar19) * (float10)fVar8 + fVar19);
  fVar18 = fVar21 * (float10)*(float *)(&DAT_00697c68 + iVar1) +
           extraout_ST1_00 * (float10)*(float *)(&DAT_00697c6c + iVar1) +
           (float10)fVar6 * (float10)*(float *)(&DAT_00697c70 + iVar1);
  iVar1 = (*(int *)(&DAT_00697460 +
                   (uVar12 + *(int *)(&DAT_00697460 + ((uVar11 & 0xff) + 1 & 0xff) * 4)) * 4) +
          uVar13) * 0xc;
  iVar2 = (*(int *)(&DAT_00697460 + (*(int *)(&DAT_00697460 + (uVar11 & 0xff) * 4) + uVar15) * 4) +
          uVar13) * 0xc;
  iVar3 = (uVar13 + *(int *)(&DAT_00697460 +
                            (*(int *)(&DAT_00697460 + ((uVar11 & 0xff) + 1 & 0xff) * 4) + uVar15) *
                            4)) * 0xc;
  fVar10 = (float)(((fVar17 * (float10)*(float *)(&DAT_00697c68 + iVar1) +
                    extraout_ST1_00 * (float10)*(float *)(&DAT_00697c6c + iVar1) +
                    (float10)fVar6 * (float10)*(float *)(&DAT_00697c70 + iVar1)) - fVar18) *
                   (float10)fVar7 + fVar18);
  fVar21 = fVar21 * (float10)*(float *)(&DAT_00697c68 + iVar2) +
           (float10)fVar4 * (float10)*(float *)(&DAT_00697c6c + iVar2) +
           (float10)fVar6 * (float10)*(float *)(&DAT_00697c70 + iVar2);
  return (((float10)3.0 - ((float10)fVar5 + (float10)fVar5)) * (float10)fVar5 * (float10)fVar5 *
          (((((((float10)(float)((extraout_ST0 - (float10)(int)uVar11) - fVar16) *
                (float10)*(float *)(&DAT_00697c68 + iVar3) +
               (float10)fVar4 * (float10)*(float *)(&DAT_00697c6c + iVar3) +
               (float10)fVar6 * (float10)*(float *)(&DAT_00697c70 + iVar3)) - fVar21) *
              (float10)fVar7 + fVar21) - (float10)fVar10) * (float10)fVar8 + (float10)fVar10) -
          (float10)fVar9) + (float10)fVar9) * (float10)_K_BLUR_W_MUL;
}


// ==== 0x5ae3f4 FUN_005ae3f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ae3f4(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ae3ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bd4)();
  return;
}


// ==== 0x5ae405 FUN_005ae405

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ae405(void)

{
  D3DXPSGP_Init(1);
                    /* WARNING: Could not recover jumptable at 0x005ae410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_006d4bd8)();
  return;
}


// ==== 0x5ae416 FUN_005ae416

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ae416(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float *extraout_ECX;
  float fVar3;
  
  fVar1 = param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar2 = FUN_005ab736(fVar1,0x3f800000);
  if (iVar2 == 0) {
    if (fVar1 <= 1.1754944e-38) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      return;
    }
    fVar3 = (_K_ONE / SQRT(fVar1)) * extraout_ECX[1];
    *param_1 = (_K_ONE / SQRT(fVar1)) * *extraout_ECX;
  }
  else {
    if (param_1 == extraout_ECX) {
      return;
    }
    *param_1 = *extraout_ECX;
    fVar3 = extraout_ECX[1];
  }
  param_1[1] = fVar3;
  return;
}


// ==== 0x5ae4a0 FUN_005ae4a0

void FUN_005ae4a0(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = param_3[1];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[0xd];
  fVar6 = param_3[2];
  fVar7 = *param_2;
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[0xe];
  fVar11 = param_3[3];
  fVar12 = *param_2;
  fVar13 = param_3[7];
  fVar14 = param_2[1];
  fVar15 = param_3[0xf];
  *param_1 = *param_2 * *param_3 + param_3[4] * param_2[1] + param_3[0xc];
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
  param_1[2] = fVar8 * fVar9 + fVar6 * fVar7 + fVar10;
  param_1[3] = fVar13 * fVar14 + fVar11 * fVar12 + fVar15;
  return;
}


// ==== 0x5ae50b FUN_005ae50b

float * FUN_005ae50b(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
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
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float *pfVar18;
  
  pfVar18 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    fVar2 = *param_3;
    fVar3 = param_5[1];
    fVar4 = *param_3;
    fVar5 = param_5[5];
    fVar6 = param_3[1];
    fVar7 = param_5[0xd];
    fVar8 = param_5[2];
    fVar9 = *param_3;
    fVar10 = param_5[6];
    fVar11 = param_3[1];
    fVar12 = param_5[0xe];
    fVar13 = *param_3;
    fVar14 = param_5[3];
    fVar15 = param_3[1];
    param_3 = (float *)((int)param_3 + param_4);
    fVar16 = param_5[7];
    fVar17 = param_5[0xf];
    *pfVar18 = fVar2 * *param_5 + param_5[4] * *pfVar1 + param_5[0xc];
    pfVar18[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar7;
    pfVar18[2] = fVar10 * fVar11 + fVar8 * fVar9 + fVar12;
    pfVar18[3] = fVar15 * fVar16 + fVar13 * fVar14 + fVar17;
    pfVar18 = (float *)((int)pfVar18 + param_2);
  }
  return param_1;
}


// ==== 0x5ae58e FUN_005ae58e

void FUN_005ae58e(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = param_2[1];
  fVar4 = param_3[5];
  fVar5 = param_3[0xd];
  fVar6 = param_3[0xf] + param_2[1] * param_3[7] + *param_2 * param_3[3];
  *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar5 + fVar3 * fVar4 + fVar1 * fVar2;
  iVar7 = FUN_005ab736(fVar6,0x3f800000);
  if (iVar7 == 0) {
    fVar6 = 1.0 / fVar6;
    *param_1 = fVar6 * *param_1;
    param_1[1] = fVar6 * param_1[1];
  }
  return;
}


// ==== 0x5ae60b FUN_005ae60b

float * FUN_005ae60b(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *extraout_ECX;
  float *pfVar7;
  undefined8 uVar8;
  
  pfVar7 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    fVar1 = param_5[1];
    fVar2 = *param_3;
    fVar3 = param_5[5];
    fVar4 = param_3[1];
    fVar5 = param_5[0xd];
    fVar6 = param_5[7] * param_3[1] + param_5[3] * *param_3 + param_5[0xf];
    *pfVar7 = *param_3 * *param_5 + param_5[4] * param_3[1] + param_5[0xc];
    pfVar7[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
    uVar8 = FUN_005ab736(fVar6,0x3f800000);
    if ((int)uVar8 == 0) {
      fVar6 = 1.0 / fVar6;
      *pfVar7 = fVar6 * *pfVar7;
      pfVar7[1] = fVar6 * pfVar7[1];
    }
    param_3 = (float *)((int)((ulonglong)uVar8 >> 0x20) + param_4);
    pfVar7 = (float *)((int)pfVar7 + param_2);
    param_5 = extraout_ECX;
  }
  return param_1;
}


// ==== 0x5ae6a3 FUN_005ae6a3

void FUN_005ae6a3(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_3[1];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  *param_1 = *param_2 * *param_3 + param_3[4] * param_2[1];
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2;
  return;
}


// ==== 0x5ae6df FUN_005ae6df

float * FUN_005ae6df(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  
  pfVar7 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    pfVar1 = param_3 + 1;
    fVar2 = *param_3;
    fVar3 = param_5[1];
    fVar4 = *param_3;
    fVar5 = param_5[5];
    fVar6 = param_3[1];
    param_3 = (float *)((int)param_3 + param_4);
    *param_1 = fVar2 * *param_5 + param_5[4] * *pfVar1;
    param_1[1] = fVar5 * fVar6 + fVar3 * fVar4;
    param_1 = (float *)((int)param_1 + param_2);
  }
  return pfVar7;
}


// ==== 0x5ae733 FUN_005ae733

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ae733(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar3 = FUN_005ab736(fVar2,0x3f800000);
  if (iVar3 == 0) {
    if (fVar2 <= 1.1754944e-38) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      return;
    }
    fVar2 = _K_ONE / SQRT(fVar2);
    local_10 = fVar2 * *param_2;
    local_c = fVar2 * param_2[1];
    pfVar1 = param_2 + 2;
    param_2 = &local_10;
    local_8 = fVar2 * *pfVar1;
  }
  else if (param_1 == param_2) {
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}


// ==== 0x5ae7d0 FUN_005ae7d0

void FUN_005ae7d0(float *param_1,float *param_2,float *param_3)

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
  int iVar16;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = param_2[1];
  fVar6 = param_3[6];
  fVar7 = param_2[1];
  fVar8 = param_3[5];
  fVar9 = param_2[2];
  fVar10 = param_3[10];
  fVar11 = param_2[2];
  fVar12 = param_3[9];
  fVar13 = param_3[0xd];
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xf] +
           param_2[2] * param_3[0xb] + param_2[1] * param_3[7] + *param_2 * param_3[3];
  *param_1 = param_3[0xc] + param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar13 + fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  param_1[2] = fVar14 + fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  iVar16 = FUN_005ab736(fVar15,0x3f800000);
  if (iVar16 == 0) {
    fVar15 = 1.0 / fVar15;
    *param_1 = fVar15 * *param_1;
    param_1[1] = fVar15 * param_1[1];
    param_1[2] = fVar15 * param_1[2];
  }
  return;
}


// ==== 0x5ae88c FUN_005ae88c

float * FUN_005ae88c(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
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
  float *extraout_ECX;
  float *pfVar16;
  undefined8 uVar17;
  
  pfVar16 = param_1;
  for (; param_6 != 0; param_6 = param_6 + -1) {
    fVar1 = param_5[1];
    fVar2 = *param_3;
    fVar3 = param_5[5];
    fVar4 = param_3[1];
    fVar5 = param_5[9];
    fVar6 = param_3[2];
    fVar7 = param_5[0xd];
    fVar8 = param_3[2];
    fVar9 = param_5[10];
    fVar10 = *param_3;
    fVar11 = param_5[2];
    fVar12 = param_3[1];
    fVar13 = param_5[6];
    fVar14 = param_5[0xe];
    fVar15 = param_5[0xb] * param_3[2] + param_5[7] * param_3[1] + param_5[3] * *param_3 +
             param_5[0xf];
    *pfVar16 = *param_3 * *param_5 + param_5[8] * param_3[2] + param_5[4] * param_3[1] +
               param_5[0xc];
    pfVar16[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7;
    pfVar16[2] = fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14;
    uVar17 = FUN_005ab736(fVar15,0x3f800000);
    if ((int)uVar17 == 0) {
      fVar15 = 1.0 / fVar15;
      *pfVar16 = fVar15 * *pfVar16;
      pfVar16[1] = fVar15 * pfVar16[1];
      pfVar16[2] = fVar15 * pfVar16[2];
    }
    param_3 = (float *)((int)((ulonglong)uVar17 >> 0x20) + param_4);
    pfVar16 = (float *)((int)pfVar16 + param_2);
    param_5 = extraout_ECX;
  }
  return param_1;
}


// ==== 0x5ae96b FUN_005ae96b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005ae96b(float *param_1,undefined4 param_2,int *param_3,undefined4 *param_4,
                    undefined4 *param_5,undefined4 *param_6)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar3 = &local_50;
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_18 = 0;
    local_1c = 0;
    local_20 = 0;
    local_24 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    local_4c = 0;
    local_14 = 0x3f800000;
    local_28 = 0x3f800000;
    local_3c = 0x3f800000;
    local_50 = 0x3f800000;
    break;
  case '\x01':
    puVar3 = param_4;
    break;
  case '\x02':
    puVar3 = param_5;
    break;
  case '\x03':
    param_6 = param_5;
    goto LAB_005aea3c;
  case '\x04':
    puVar3 = param_6;
    break;
  case '\x05':
    goto LAB_005aea3c;
  case '\x06':
    param_4 = param_5;
    goto LAB_005aea3c;
  case '\a':
    D3DXMatrixMultiply(&local_50,param_6,param_5);
    param_6 = &local_50;
LAB_005aea3c:
    D3DXMatrixMultiply(&local_50,param_6,param_4);
  }
  thunk_FUN_005abef8(param_1,param_2,puVar3);
  if (param_3 != (int *)0x0) {
    fVar2 = (float)param_3[2];
    if (param_3[2] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)*param_3;
    if (*param_3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    *param_1 = fVar1 + fVar2 * (*param_1 + _K_ONE) * 0.5;
    fVar2 = (float)param_3[3];
    if (param_3[3] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)param_3[1];
    if (param_3[1] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    param_1[1] = fVar1 + fVar2 * (1.0 - param_1[1]) * 0.5;
    param_1[2] = ((float)param_3[5] - (float)param_3[4]) * param_1[2] + (float)param_3[4];
  }
  return param_1;
}


// ==== 0x5aeaf8 FUN_005aeaf8

void FUN_005aeaf8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
                 undefined4 param_9)

{
  float fVar1;
  undefined4 *puVar2;
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
  float local_50 [6];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  puVar2 = &local_90;
  switch(((param_8 != (undefined4 *)0x0) << 1 | param_7 != (undefined4 *)0x0) << 1 |
         param_6 != (undefined4 *)0x0) {
  case '\0':
    local_58 = 0;
    local_5c = 0;
    local_60 = 0;
    local_64 = 0;
    local_6c = 0;
    local_70 = 0;
    local_74 = 0;
    local_78 = 0;
    local_80 = 0;
    local_84 = 0;
    local_88 = 0;
    local_8c = 0;
    local_54 = 0x3f800000;
    local_68 = 0x3f800000;
    local_7c = 0x3f800000;
    local_90 = 0x3f800000;
    break;
  case '\x01':
    puVar2 = param_6;
    break;
  case '\x02':
    puVar2 = param_7;
    break;
  case '\x03':
    param_8 = param_7;
    goto LAB_005aebcc;
  case '\x04':
    puVar2 = param_8;
    break;
  case '\x05':
    goto LAB_005aebcc;
  case '\x06':
    param_6 = param_7;
    goto LAB_005aebcc;
  case '\a':
    D3DXMatrixMultiply(&local_90,param_8,param_7);
    param_8 = &local_90;
LAB_005aebcc:
    D3DXMatrixMultiply(&local_90,param_8,param_6);
  }
  if (param_5 != (int *)0x0) {
    local_50[0] = (float)param_5[2];
    if (param_5[2] < 0) {
      local_50[0] = local_50[0] + 4.2949673e+09;
    }
    local_50[0] = local_50[0] * 0.5;
    local_50[1] = 0.0;
    local_50[2] = 0.0;
    local_50[3] = 0.0;
    local_50[4] = 0.0;
    fVar1 = (float)param_5[3];
    if (param_5[3] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    local_50[5] = fVar1 * -0.5;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    fStack_28 = (float)param_5[5] - (float)param_5[4];
    uStack_24 = 0;
    fStack_20 = (float)*param_5;
    if (*param_5 < 0) {
      fStack_20 = fStack_20 + 4.2949673e+09;
    }
    fStack_20 = fStack_20 + local_50[0];
    fStack_1c = (float)param_5[1];
    if (param_5[1] < 0) {
      fStack_1c = fStack_1c + 4.2949673e+09;
    }
    iStack_18 = param_5[4];
    fStack_1c = fVar1 * 0.5 + fStack_1c;
    uStack_14 = 0x3f800000;
    D3DXMatrixMultiply(&local_90,puVar2,local_50);
    puVar2 = &local_90;
  }
  thunk_FUN_005abf0b(param_1,param_2,param_3,param_4,puVar2,param_9);
  return;
}


// ==== 0x5aecf8 FUN_005aecf8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005aecf8(float *param_1,float *param_2,int *param_3,undefined4 *param_4,
                    undefined4 *param_5,undefined4 *param_6)

{
  float fVar1;
  float fVar2;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_18 = 0;
    local_1c = 0;
    local_20 = 0;
    local_24 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    local_4c = 0;
    local_14 = 0x3f800000;
    local_28 = 0x3f800000;
    local_3c = 0x3f800000;
    local_50 = 0x3f800000;
    goto switchD_005aed35_default;
  case '\x01':
    param_6 = param_4;
    goto LAB_005aedd3;
  case '\x02':
    param_6 = param_5;
    goto LAB_005aedd3;
  case '\x03':
    param_6 = param_5;
    break;
  case '\x04':
    goto LAB_005aedd3;
  case '\x05':
    break;
  case '\x06':
    param_4 = param_5;
    break;
  case '\a':
    D3DXMatrixMultiply(&local_50,param_6,param_5);
    param_6 = &local_50;
    break;
  default:
    goto switchD_005aed35_default;
  }
  D3DXMatrixMultiply(&local_50,param_6,param_4);
  param_6 = &local_50;
LAB_005aedd3:
  thunk_FUN_005acb9b(&local_50,0,param_6);
switchD_005aed35_default:
  if (param_3 != (int *)0x0) {
    fVar1 = (float)*param_3;
    if (*param_3 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)param_3[2];
    if (param_3[2] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar2 = (*param_2 - fVar1) / fVar2;
    *param_1 = (fVar2 + fVar2) - _K_ONE;
    fVar1 = (float)param_3[1];
    if (param_3[1] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)param_3[3];
    if (param_3[3] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar2 = (param_2[1] - fVar1) / fVar2;
    param_1[1] = -((fVar2 + fVar2) - _K_ONE);
    param_1[2] = (param_2[2] - (float)param_3[4]) / ((float)param_3[5] - (float)param_3[4]);
    param_2 = param_1;
  }
  thunk_FUN_005abef8(param_1,param_2,&local_50);
  return param_1;
}


// ==== 0x5aee9e FUN_005aee9e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aee9e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
                 undefined4 param_9)

{
  float fVar1;
  float fVar2;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
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
  float afStack_50 [6];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  
  switch(((param_8 != (undefined4 *)0x0) << 1 | param_7 != (undefined4 *)0x0) << 1 |
         param_6 != (undefined4 *)0x0) {
  case '\0':
    local_68 = 0;
    local_6c = 0;
    local_70 = 0;
    local_74 = 0;
    local_7c = 0;
    local_80 = 0;
    local_84 = 0;
    local_88 = 0;
    local_90 = 0;
    local_94 = 0;
    local_98 = 0;
    local_9c = 0;
    local_64 = 0x3f800000;
    local_78 = 0x3f800000;
    local_8c = 0x3f800000;
    local_a0 = 0x3f800000;
    goto switchD_005aeede_default;
  case '\x01':
    param_8 = param_6;
    goto LAB_005aef7c;
  case '\x02':
    param_8 = param_7;
    goto LAB_005aef7c;
  case '\x03':
    param_8 = param_7;
    break;
  case '\x04':
    goto LAB_005aef7c;
  case '\x05':
    break;
  case '\x06':
    param_6 = param_7;
    break;
  case '\a':
    D3DXMatrixMultiply(&local_a0,param_8,param_7);
    param_8 = &local_a0;
    break;
  default:
    goto switchD_005aeede_default;
  }
  D3DXMatrixMultiply(&local_a0,param_8,param_6);
  param_8 = &local_a0;
LAB_005aef7c:
  thunk_FUN_005acb9b(&local_a0,0,param_8);
switchD_005aeede_default:
  if (param_5 != (int *)0x0) {
    afStack_50[0] = (float)param_5[2];
    if (param_5[2] < 0) {
      afStack_50[0] = afStack_50[0] + 4.2949673e+09;
    }
    afStack_50[0] = 2.0 / afStack_50[0];
    fVar1 = (float)param_5[3];
    if (param_5[3] < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fStack_28 = _K_ONE / ((float)param_5[5] - (float)param_5[4]);
    afStack_50[1] = 0.0;
    afStack_50[2] = 0.0;
    afStack_50[3] = 0.0;
    afStack_50[4] = 0.0;
    afStack_50[5] = -(2.0 / fVar1);
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_24 = 0;
    fVar2 = (float)*param_5;
    if (*param_5 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fStack_20 = -(fVar2 * afStack_50[0]) - _K_ONE;
    fVar2 = (float)param_5[1];
    if (param_5[1] < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fStack_1c = fVar2 * (2.0 / fVar1) - _K_ONE;
    fStack_18 = -(fStack_28 * (float)param_5[4]);
    uStack_14 = 0x3f800000;
    D3DXMatrixMultiply(&local_a0,&local_a0,afStack_50);
  }
  thunk_FUN_005abf0b(param_1,param_2,param_3,param_4,&local_a0,param_9);
  return;
}


// ==== 0x5af0cf FUN_005af0cf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af0cf(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_2[3] * param_2[3] +
          param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar3 = FUN_005ab736(fVar2,0x3f800000);
  if (iVar3 == 0) {
    if (fVar2 <= 1.1754944e-38) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      param_1[3] = 0.0;
      return;
    }
    fVar2 = _K_ONE / SQRT(fVar2);
    local_14 = fVar2 * *param_2;
    local_10 = fVar2 * param_2[1];
    local_c = fVar2 * param_2[2];
    pfVar1 = param_2 + 3;
    param_2 = &local_14;
    local_8 = fVar2 * *pfVar1;
  }
  else if (param_1 == param_2) {
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== 0x5af185 FUN_005af185

undefined4 FUN_005af185(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_14 [16];
  
  thunk_FUN_005ad7a2(local_14,param_2,param_3,param_4);
  thunk_FUN_005ad348(param_1,local_14);
  return param_1;
}


// ==== 0x5af1be FUN_005af1be

undefined4 *
FUN_005af1be(undefined4 *param_1,float *param_2,int param_3,undefined4 *param_4,float *param_5,
            int param_6,float *param_7)

{
  undefined4 uVar1;
  undefined4 *puStack_ec;
  undefined1 *puStack_e8;
  int iStack_e4;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 local_90 [48];
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [84];
  
  if (param_4 == (undefined4 *)0x0) {
    param_1[0xe] = 0;
    param_1[0xd] = 0;
    param_1[0xc] = 0;
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
    param_1[10] = 0x3f800000;
    param_1[5] = 0x3f800000;
    *param_1 = 0x3f800000;
  }
  else if (param_3 == 0) {
    param_1[0xe] = 0;
    param_1[0xd] = 0;
    param_1[0xc] = 0;
    param_1[0xb] = 0;
    param_1[9] = 0;
    param_1[8] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = *param_4;
    param_1[5] = param_4[1];
    uVar1 = param_4[2];
    param_1[0xf] = 0x3f800000;
    param_1[10] = uVar1;
  }
  else {
    local_98 = 0;
    iStack_e4 = param_3;
    local_9c = 0;
    local_a0 = 0;
    local_a8 = param_4[2];
    puStack_e8 = local_90;
    local_a4 = 0;
    local_ac = 0;
    local_b0 = 0;
    local_b4 = 0;
    local_b8 = 0;
    local_94 = 0x3f800000;
    puStack_ec = (undefined4 *)0x5af250;
    thunk_FUN_005ad348();
    puStack_ec = &local_98;
    if (param_2 == (float *)0x0) {
      D3DXMatrixTranspose(param_1);
      D3DXMatrixMultiply(param_1,param_1,&stack0xffffff20);
      D3DXMatrixMultiply(param_1,param_1,&local_ac);
    }
    else {
      D3DXMatrixTranspose(auStack_58);
      param_1[0xe] = 0;
      param_1[0xd] = 0;
      param_1[0xc] = 0;
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
      param_1[10] = 0x3f800000;
      param_1[5] = 0x3f800000;
      *param_1 = 0x3f800000;
      param_1[0xc] = -*param_2;
      param_1[0xd] = -param_2[1];
      param_1[0xe] = -param_2[2];
      D3DXMatrixMultiply(param_1,param_1,auStack_60);
      D3DXMatrixMultiply(param_1,param_1,&puStack_ec);
      D3DXMatrixMultiply(param_1,param_1,&local_b8);
      param_1[0xc] = (float)param_1[0xc] + *param_2;
      param_1[0xd] = param_2[1] + (float)param_1[0xd];
      param_1[0xe] = (float)param_1[0xe] + param_2[2];
    }
  }
  if (param_6 != 0) {
    iStack_e4 = param_6;
    puStack_e8 = local_90;
    puStack_ec = (undefined4 *)0x5af3f9;
    thunk_FUN_005ad348();
    puStack_ec = &local_98;
    if (param_5 == (float *)0x0) {
      D3DXMatrixMultiply(param_1,param_1);
    }
    else {
      param_1[0xc] = (float)param_1[0xc] - *param_5;
      param_1[0xd] = (float)param_1[0xd] - param_5[1];
      param_1[0xe] = (float)param_1[0xe] - param_5[2];
      D3DXMatrixMultiply(param_1,param_1);
      param_1[0xc] = (float)param_1[0xc] + *param_5;
      param_1[0xd] = (float)param_1[0xd] + param_5[1];
      param_1[0xe] = (float)param_1[0xe] + param_5[2];
    }
  }
  if (param_7 != (float *)0x0) {
    param_1[0xc] = (float)param_1[0xc] + *param_7;
    param_1[0xd] = param_7[1] + (float)param_1[0xd];
    param_1[0xe] = param_7[2] + (float)param_1[0xe];
  }
  return param_1;
}


// ==== 0x5af472 FUN_005af472

void FUN_005af472(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_005addb8(&local_14,param_3);
  fVar1 = local_c * param_2[2] + local_8 * param_2[3] + local_14 * *param_2 + local_10 * param_2[1];
  local_14 = -local_14;
  local_10 = -local_10;
  local_c = -local_c;
  local_8 = -local_8;
  *param_1 = local_14 * *param_2 + fVar1;
  param_1[4] = local_10 * *param_2;
  param_1[8] = local_c * *param_2;
  param_1[0xc] = local_8 * *param_2;
  param_1[1] = local_14 * param_2[1];
  param_1[5] = local_10 * param_2[1] + fVar1;
  param_1[9] = local_c * param_2[1];
  param_1[0xd] = local_8 * param_2[1];
  param_1[2] = local_14 * param_2[2];
  param_1[6] = local_10 * param_2[2];
  param_1[10] = local_c * param_2[2] + fVar1;
  param_1[0xe] = local_8 * param_2[2];
  param_1[3] = local_14 * param_2[3];
  param_1[7] = local_10 * param_2[3];
  param_1[0xb] = local_c * param_2[3];
  param_1[0xf] = local_8 * param_2[3] + fVar1;
  return;
}


// ==== 0x5af54c FUN_005af54c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af54c(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_005addb8(&local_14,param_2);
  fVar4 = _K_ONE;
  fVar1 = local_14 * -2.0;
  fVar3 = local_10 * -2.0;
  fVar2 = local_c * -2.0;
  *param_1 = local_14 * fVar1 + _K_ONE;
  param_1[1] = fVar3 * local_14;
  param_1[2] = fVar2 * local_14;
  param_1[3] = 0.0;
  param_1[4] = local_10 * fVar1;
  param_1[5] = local_10 * fVar3 + fVar4;
  param_1[6] = fVar2 * local_10;
  param_1[7] = 0.0;
  param_1[8] = local_c * fVar1;
  param_1[9] = local_c * fVar3;
  param_1[10] = local_c * fVar2 + fVar4;
  param_1[0xb] = 0.0;
  param_1[0xc] = local_8 * fVar1;
  param_1[0xd] = local_8 * fVar3;
  param_1[0xe] = local_8 * fVar2;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x5af60b FUN_005af60b

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
  fStack_64 = (fStack_94 + fStack_14) * -0.25;
  fStack_60 = fStack_40 * -0.25;
  fStack_5c = fStack_3c * -0.25;
  fStack_58 = (fStack_88 + fStack_8) * -0.25;
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
  fStack_64 = (fStack_94 + fStack_14) * -0.25;
  fStack_60 = fStack_40 * -0.25;
  fStack_5c = fStack_3c * -0.25;
  fStack_58 = (fStack_88 + fStack_8) * -0.25;
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


// ==== 0x5af9e5 FUN_005af9e5

undefined4 FUN_005af9e5(int *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == (int *)0x0) {
    uVar3 = 0x8876086c;
  }
  else {
    pvVar1 = _malloc(0x14);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005b171f();
    }
    if (iVar2 == 0) {
      uVar3 = 0x8007000e;
    }
    else {
      *param_1 = iVar2;
    }
  }
  return uVar3;
}


// ==== 0x5afa23 FUN_005afa23

int FUN_005afa23(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 *param_6,undefined4 *param_7)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *local_8;
  
  piVar4 = (int *)0x0;
  local_8 = (undefined4 *)0x0;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if ((param_1 == 0) || (param_6 == (undefined4 *)0x0)) {
    iVar3 = -0x7789f794;
  }
  else {
    pvVar1 = _malloc(0x130);
    if (pvVar1 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005b9096();
    }
    if (piVar4 == (int *)0x0) {
      iVar3 = -0x7ff8fff2;
    }
    else {
      iVar3 = FUN_005c7b70(param_1,param_2,param_3,param_4);
      if (-1 < iVar3) {
        iVar3 = FUN_005c50ee(piVar4 + 2,param_5,&local_8);
        if (-1 < iVar3) {
          iVar3 = FUN_005b19e6();
          if (iVar3 == 0) {
            iVar3 = FUN_005b9b78(local_8);
            if (iVar3 < 0) goto LAB_005afaf6;
            local_8 = (undefined4 *)0x0;
            iVar2 = FUN_005b19e6();
            if (iVar2 == 0) {
              *param_6 = piVar4;
              (**(code **)(*piVar4 + 4))(piVar4);
              goto LAB_005afaf6;
            }
          }
          iVar3 = -0x7789f4a7;
        }
      }
    }
  }
LAB_005afaf6:
  if ((param_7 != (undefined4 *)0x0) && (piVar4 != (int *)0x0)) {
    FUN_005b197d(param_7);
  }
  if (local_8 != (undefined4 *)0x0) {
    (**(code **)*local_8)(1);
    local_8 = (undefined4 *)0x0;
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return iVar3;
}


// ==== 0x5afb2f FUN_005afb2f

int FUN_005afb2f(int param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 *param_8,int *param_9)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  piVar6 = param_9;
  local_8 = 0;
  local_14 = (int *)0x0;
  local_10 = (int *)0x0;
  local_c = (int *)0x0;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = 0;
  }
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_8 = -0x7789f794;
    goto LAB_005afc77;
  }
  pvVar2 = _malloc(0xbc);
  if (pvVar2 == (void *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    local_10 = (int *)FUN_005d041d();
  }
  piVar7 = local_10;
  uVar5 = param_3;
  if (local_10 == (int *)0x0) {
    local_8 = -0x7ff8fff2;
    goto LAB_005afc84;
  }
  if (param_3 < 4) {
    local_8 = -0x7fffbffb;
    goto LAB_005afc84;
  }
  if (*param_2 == -1) {
    if ((param_8 == (undefined4 *)0x0) ||
       (local_8 = thunk_FUN_005d65b0(param_3,&local_c), piVar6 = param_2, local_8 < 0))
    goto LAB_005afc84;
    piVar3 = (int *)(**(code **)(*local_c + 0xc))(local_c);
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *piVar3 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar3 = piVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; piVar7 = local_10, uVar5 != 0; uVar5 = uVar5 - 1) {
      *(char *)piVar3 = (char)*piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
      piVar3 = (int *)((int)piVar3 + 1);
    }
LAB_005afc40:
    puVar1 = param_8;
    if (param_8 != (undefined4 *)0x0) {
      param_2 = (int *)0x0;
      local_8 = FUN_005d5932(param_1,param_7,local_c,&param_2);
      if (-1 < local_8) {
        *puVar1 = piVar7;
        (**(code **)(*piVar7 + 4))(piVar7);
      }
    }
  }
  else {
    local_8 = FUN_005afa23(param_2,param_3,param_4,param_5,param_6,&local_14,piVar6);
    if (-1 < local_8) {
      if ((piVar6 != (int *)0x0) && (piVar3 = (int *)*piVar6, piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *piVar6 = 0;
      }
      local_8 = (**(code **)(*local_14 + 0xf0))(local_14,param_6,&local_c,piVar6);
      if (-1 < local_8) goto LAB_005afc40;
    }
  }
LAB_005afc77:
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_005afc84:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return local_8;
}


// ==== 0x5afcac FUN_005afcac

void FUN_005afcac(int param_1,int param_2,int param_3,float *param_4,uint param_5,int param_6,
                 int *param_7,int *param_8,uint param_9,undefined4 *param_10,float *param_11,
                 int param_12)

{
  int *piVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  float *pfVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float local_344 [195];
  uint local_38;
  int local_34;
  int local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(param_3 + (int)param_10);
  uVar7 = param_6 - (int)param_10;
  if (param_2 == 0) {
    param_2 = param_1;
  }
  if (param_9 == 1) {
    if (param_5 != 0) {
      param_9 = param_5;
      param_10 = (undefined4 *)((int)param_4 + (int)param_10);
      do {
        local_14 = 0.0;
        local_10 = 0.0;
        local_c = 0.0;
        local_344[0] = 0.0;
        local_344[1] = 0.0;
        local_344[2] = 0.0;
        fVar2 = *param_11;
        while (0.0 <= fVar2) {
          uVar4 = __ftol();
          iVar5 = (uVar4 >> 1) * 2;
          fVar2 = (float)iVar5;
          if (iVar5 < 0) {
            fVar2 = fVar2 + 4.2949673e+09;
          }
          fVar2 = *param_11 - fVar2;
          iVar5 = (uVar4 >> 1) * 0x40;
          thunk_FUN_005abef8(&local_2c,param_3,param_1 + iVar5);
          thunk_FUN_005abf22(&local_20,*param_7,iVar5 + param_2);
          param_11 = param_11 + 1;
          local_2c = local_2c * fVar2;
          local_28 = local_28 * fVar2;
          local_24 = local_24 * fVar2;
          local_20 = local_20 * fVar2;
          local_1c = local_1c * fVar2;
          local_18 = local_18 * fVar2;
          local_14 = local_2c + local_14;
          local_10 = local_28 + local_10;
          local_c = local_24 + local_c;
          local_344[0] = local_20 + local_344[0];
          local_344[1] = local_1c + local_344[1];
          local_344[2] = local_18 + local_344[2];
          fVar2 = *param_11;
        }
        if (param_12 == 0) {
          *param_4 = local_14;
          param_4[1] = local_10;
          param_4[2] = local_c;
          pfVar9 = (float *)*param_8;
          *pfVar9 = local_344[0];
          pfVar9[1] = local_344[1];
          pfVar9[2] = local_344[2];
          puVar10 = local_8;
          puVar11 = param_10;
          for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
        }
        else {
          puVar10 = local_8;
          puVar11 = param_10;
          for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          *param_4 = local_14;
          param_4[1] = local_10;
          param_4[2] = local_c;
          pfVar9 = (float *)*param_8;
          *pfVar9 = local_344[0];
          pfVar9[1] = local_344[1];
          pfVar9[2] = local_344[2];
        }
        *param_8 = *param_8 + param_6;
        param_10 = (undefined4 *)((int)param_10 + param_6);
        local_8 = (undefined4 *)((int)local_8 + param_6);
        param_4 = (float *)((int)param_4 + param_6);
        param_3 = param_3 + param_6;
        *param_7 = *param_7 + param_6;
        param_11 = param_11 + 1;
        param_9 = param_9 + -1;
      } while (param_9 != 0);
    }
  }
  else if (param_5 != 0) {
    local_38 = param_9 * 0xc;
    local_30 = param_5;
    param_10 = (undefined4 *)((int)param_4 + (int)param_10);
    do {
      uVar4 = local_38;
      local_14 = 0.0;
      local_10 = 0.0;
      pfVar9 = local_344;
      for (uVar8 = local_38 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar9 = 0.0;
        pfVar9 = pfVar9 + 1;
      }
      local_c = 0.0;
      fVar2 = *param_11;
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)pfVar9 = 0;
        pfVar9 = (float *)((int)pfVar9 + 1);
      }
      while (0.0 <= fVar2) {
        uVar4 = __ftol();
        iVar5 = (uVar4 >> 1) * 2;
        fVar2 = (float)iVar5;
        if (iVar5 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        fVar2 = *param_11 - fVar2;
        iVar5 = (uVar4 >> 1) * 0x40;
        thunk_FUN_005abef8(&local_20,param_3,param_1 + iVar5);
        local_20 = local_20 * fVar2;
        param_5 = 0;
        local_1c = local_1c * fVar2;
        local_18 = local_18 * fVar2;
        local_14 = local_20 + local_14;
        local_10 = local_1c + local_10;
        local_c = local_18 + local_c;
        if (param_9 != 0) {
          local_34 = iVar5 + param_2;
          pfVar9 = local_344 + 2;
          do {
            thunk_FUN_005abf22(&local_2c,param_7[param_5],local_34);
            local_2c = local_2c * fVar2;
            param_5 = param_5 + 1;
            local_28 = local_28 * fVar2;
            local_24 = local_24 * fVar2;
            pfVar9[-2] = local_2c + pfVar9[-2];
            pfVar9[-1] = local_28 + pfVar9[-1];
            *pfVar9 = local_24 + *pfVar9;
            pfVar9 = pfVar9 + 3;
          } while (param_5 < param_9);
        }
        param_11 = param_11 + 1;
        fVar2 = *param_11;
      }
      if (param_12 == 0) {
        *param_4 = local_14;
        param_4[1] = local_10;
        param_4[2] = local_c;
        if (param_9 != 0) {
          pfVar9 = local_344;
          param_5 = param_9;
          piVar6 = param_8;
          do {
            pfVar3 = (float *)*piVar6;
            *pfVar3 = *pfVar9;
            pfVar3[1] = pfVar9[1];
            pfVar3[2] = pfVar9[2];
            *piVar6 = *piVar6 + param_6;
            piVar1 = (int *)((int)piVar6 + ((int)param_7 - (int)param_8));
            *piVar1 = *piVar1 + param_6;
            pfVar9 = pfVar9 + 3;
            piVar6 = piVar6 + 1;
            param_5 = param_5 - 1;
          } while (param_5 != 0);
        }
        puVar10 = local_8;
        puVar11 = param_10;
        for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
      }
      else {
        puVar10 = local_8;
        puVar11 = param_10;
        for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        *param_4 = local_14;
        param_4[1] = local_10;
        param_4[2] = local_c;
        if (param_9 != 0) {
          pfVar9 = local_344;
          param_5 = param_9;
          piVar6 = param_8;
          do {
            pfVar3 = (float *)*piVar6;
            *pfVar3 = *pfVar9;
            pfVar3[1] = pfVar9[1];
            pfVar3[2] = pfVar9[2];
            *piVar6 = *piVar6 + param_6;
            piVar1 = (int *)(((int)param_7 - (int)param_8) + (int)piVar6);
            *piVar1 = *piVar1 + param_6;
            pfVar9 = pfVar9 + 3;
            piVar6 = piVar6 + 1;
            param_5 = param_5 - 1;
          } while (param_5 != 0);
        }
      }
      param_10 = (undefined4 *)((int)param_10 + param_6);
      local_8 = (undefined4 *)((int)local_8 + param_6);
      param_4 = (float *)((int)param_4 + param_6);
      param_3 = param_3 + param_6;
      param_11 = param_11 + 1;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
  }
  return;
}


// ==== 0x5b00b6 FUN_005b00b6

void FUN_005b00b6(float *param_1,float *param_2,float *param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  *param_5 = *param_1;
  param_5[1] = param_1[1];
  param_5[2] = param_1[2];
  *param_5 = *param_5 - *param_2;
  param_5[1] = param_5[1] - param_2[1];
  fVar3 = param_5[2] - param_2[2];
  param_5[2] = fVar3;
  fVar4 = param_5[1] * param_3[1] + *param_3 * *param_5 + fVar3 * param_3[2];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  param_5[2] = fVar3 - fVar4 * param_3[2];
  fVar1 = (*param_5 - fVar4 * fVar1) * param_4;
  *param_5 = fVar1;
  fVar2 = (param_5[1] - fVar4 * fVar2) * param_4;
  param_5[1] = fVar2;
  param_5[2] = param_4 * param_5[2];
  *param_5 = fVar1 + *param_2;
  param_5[1] = fVar2 + param_2[1];
  param_5[2] = param_2[2] + param_5[2];
  return;
}


// ==== 0x5b0153 FUN_005b0153

void FUN_005b0153(uint param_1,int param_2,uint param_3,float *param_4,float *param_5,float *param_6
                 ,float *param_7,uint param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
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
  FUN_005b00b6(&fStack_34,&fStack_7c,param_1,0x3eaaaaab,&fStack_70);
  FUN_005b00b6(&fStack_10,&fStack_7c,param_1,0x3eaaaaab,&fStack_64);
  FUN_005b00b6(&fStack_7c,&fStack_34,param_1 + 0xc,0x3eaaaaab,&fStack_58);
  FUN_005b00b6(&fStack_7c,&fStack_10,param_1 + 0x18,0x3eaaaaab,&fStack_40);
  FUN_005b00b6(&fStack_10,&fStack_34,param_1 + 0xc,0x3eaaaaab,&fStack_28);
  FUN_005b00b6(&fStack_34,&fStack_10,param_1 + 0x18,0x3eaaaaab,&fStack_1c);
  fStack_94 = fStack_10 + fStack_34 + fStack_7c;
  fStack_90 = fStack_c + fStack_30 + fStack_78;
  param_1 = 0;
  fStack_80 = (fStack_8 + fStack_2c + fStack_74) * 0.166666;
  fStack_4c = (fStack_1c + fStack_28 + fStack_40 + fStack_58 + fStack_70 + fStack_64) * 0.25 -
              fStack_94 * 0.166666;
  fStack_48 = (fStack_18 + fStack_24 + fStack_3c + fStack_54 + fStack_60 + fStack_6c) * 0.25 -
              fStack_90 * 0.166666;
  fStack_44 = (fStack_14 + fStack_20 + fStack_38 + fStack_50 + fStack_5c + fStack_68) * 0.25 -
              fStack_80;
  if (param_3 != 0) {
    do {
      fVar1 = *(float *)(param_1 * 8 + param_2);
      uVar6 = 0;
      fVar2 = *(float *)(param_1 * 8 + 4 + param_2);
      fVar4 = (1.0 - fVar1) - fVar2;
      afStack_bc[0] = fVar2 * fVar2 * fVar2;
      afStack_bc[1] = fVar4 * fVar2 * fVar2 * 3.0;
      afStack_bc[2] = fVar2 * fVar2 * fVar1 * 3.0;
      fVar3 = fVar4 * fVar4;
      afStack_bc[3] = fVar3 * fVar2 * 3.0;
      afStack_bc[4] = fVar4 * fVar2 * fVar1 * 6.0;
      afStack_bc[5] = fVar2 * fVar1 * fVar1 * 3.0;
      afStack_bc[6] = fVar3 * fVar4;
      afStack_bc[7] = fVar3 * fVar1 * 3.0;
      afStack_bc[8] = fVar4 * fVar1 * fVar1 * 3.0;
      afStack_bc[9] = fVar1 * fVar1 * fVar1;
      afStack_1cc[0] = 0.0;
      afStack_1cc[1] = 0.0;
      afStack_1cc[2] = 0.0;
      pfVar5 = &fStack_78;
      do {
        pfVar8 = afStack_bc + uVar6;
        uVar6 = uVar6 + 1;
        afStack_1cc[0] = pfVar5[-1] * *pfVar8 + afStack_1cc[0];
        afStack_1cc[1] = *pfVar8 * *pfVar5 + afStack_1cc[1];
        afStack_1cc[2] = pfVar5[1] * *pfVar8 + afStack_1cc[2];
        pfVar5 = pfVar5 + 3;
      } while (uVar6 < 10);
      if (3 < param_8) {
        pfVar5 = param_6 + 3;
        iVar7 = param_8 - 3;
        do {
          *(float *)((int)pfVar5 + ((int)afStack_1cc - (int)param_6)) =
               fVar4 * *pfVar5 +
               fVar2 * *(float *)((int)pfVar5 + ((int)param_5 - (int)param_6)) +
               fVar1 * *(float *)((int)pfVar5 + ((int)param_7 - (int)param_6));
          pfVar5 = pfVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      pfVar5 = afStack_1cc;
      pfVar8 = param_4;
      for (uVar6 = param_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pfVar8 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar8 = pfVar8 + 1;
      }
      param_1 = param_1 + 1;
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)pfVar8 = *(undefined1 *)pfVar5;
        pfVar5 = (float *)((int)pfVar5 + 1);
        pfVar8 = (float *)((int)pfVar8 + 1);
      }
      param_4 = param_4 + param_8;
    } while (param_1 < param_3);
  }
  return;
}


// ==== 0x5b0171 FUN_005b0171

void FUN_005b0171(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  float *unaff_EBX;
  float *unaff_EBP;
  undefined4 *unaff_ESI;
  float *pfVar11;
  undefined4 *unaff_EDI;
  float10 in_ST0;
  
  *unaff_EDI = *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1];
  unaff_EBP[10] = *unaff_EBX;
  unaff_EBP[0xb] = unaff_EBX[1];
  unaff_EBP[0xc] = unaff_EBX[2];
  pfVar7 = (float *)unaff_EBP[0x1e];
  unaff_EBP[0x13] = *pfVar7;
  unaff_EBP[0x14] = pfVar7[1];
  unaff_EBP[0x15] = pfVar7[2];
  fVar6 = unaff_EBP[0x18];
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + -8,fVar6,(float)in_ST0,unaff_EBP + -5);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + -8,fVar6,0x3eaaaaab,unaff_EBP + -2);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 10,(int)fVar6 + 0xc,0x3eaaaaab,unaff_EBP + 1);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 0x13,(int)fVar6 + 0x18,0x3eaaaaab,unaff_EBP + 7);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + 10,(int)fVar6 + 0xc,0x3eaaaaab,unaff_EBP + 0xd);
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + 0x13,(int)fVar6 + 0x18,0x3eaaaaab,unaff_EBP + 0x10);
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
  unaff_EBP[4] = unaff_EBP[4] * 0.25;
  unaff_EBP[5] = unaff_EBP[5] * 0.25;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar6 = 0.0;
  unaff_EBP[0x18] = 0.0;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * 0.166666;
  unaff_EBP[4] = unaff_EBP[4] - unaff_EBP[-0xe] * 0.166666;
  unaff_EBP[5] = unaff_EBP[5] - unaff_EBP[-0xd] * 0.166666;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * 0.25 - unaff_EBP[-9];
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar6 * 8 + (int)unaff_EBP[0x19]);
      uVar8 = 0;
      fVar6 = *(float *)((int)fVar6 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar4 = (1.0 - fVar1) - fVar6;
      unaff_EBP[-0x18] = fVar6 * fVar6 * fVar6;
      unaff_EBP[0x1d] = fVar4 * fVar6;
      unaff_EBP[-0x17] = fVar4 * fVar6 * fVar6 * 3.0;
      unaff_EBP[-0x16] = fVar6 * fVar6 * fVar1 * 3.0;
      fVar2 = fVar4 * fVar4;
      unaff_EBP[-0x15] = fVar2 * fVar6 * 3.0;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * 6.0;
      unaff_EBP[-0x13] = fVar6 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0x12] = fVar2 * fVar4;
      unaff_EBP[-0x11] = fVar2 * fVar1 * 3.0;
      unaff_EBP[-0x10] = fVar4 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar5 = 0.0;
      pfVar7 = unaff_EBP + -7;
      do {
        pfVar11 = unaff_EBP + (uVar8 - 0x18);
        uVar8 = uVar8 + 1;
        fVar2 = pfVar7[-1] * *pfVar11 + fVar2;
        fVar3 = *pfVar11 * *pfVar7 + fVar3;
        fVar5 = pfVar7[1] * *pfVar11 + fVar5;
        pfVar7 = pfVar7 + 3;
      } while (uVar8 < 10);
      fVar10 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar5;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar10) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar7 = unaff_EBX + 3;
        iVar9 = (int)fVar10 + -3;
        do {
          *(float *)((int)pfVar7 + (int)unaff_EBP + (-0x170 - (int)unaff_EBX)) =
               fVar4 * *pfVar7 +
               fVar6 * *(float *)((int)pfVar7 + ((int)fVar2 - (int)unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar7 + ((int)fVar3 - (int)unaff_EBX));
          pfVar7 = pfVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        fVar10 = unaff_EBP[0x1f];
      }
      pfVar7 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar10 * 4);
      fVar6 = unaff_EBP[0x18];
      pfVar11 = unaff_EBP + -0x5c;
      for (uVar8 = (uint)fVar10 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar7 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        pfVar7 = pfVar7 + 1;
      }
      fVar6 = (float)((int)fVar6 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined1 *)pfVar7 = *(undefined1 *)pfVar11;
        pfVar11 = (float *)((int)pfVar11 + 1);
        pfVar7 = (float *)((int)pfVar7 + 1);
      }
      unaff_EBP[0x18] = fVar6;
    } while ((uint)fVar6 < (uint)fVar1);
  }
  return;
}


// ==== 0x5b0189 FUN_005b0189

void FUN_005b0189(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  int unaff_EBX;
  float *unaff_EBP;
  float *pfVar11;
  
  fVar6 = unaff_EBP[0x18];
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + -8,fVar6);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + -8,fVar6);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 10,(int)fVar6 + 0xc);
  FUN_005b00b6(unaff_EBP + -8,unaff_EBP + 0x13,(int)fVar6 + 0x18);
  FUN_005b00b6(unaff_EBP + 0x13,unaff_EBP + 10,(int)fVar6 + 0xc);
  FUN_005b00b6(unaff_EBP + 10,unaff_EBP + 0x13,(int)fVar6 + 0x18);
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
  unaff_EBP[4] = unaff_EBP[4] * 0.25;
  unaff_EBP[5] = unaff_EBP[5] * 0.25;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar6 = 0.0;
  unaff_EBP[0x18] = 0.0;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * 0.166666;
  unaff_EBP[4] = unaff_EBP[4] - unaff_EBP[-0xe] * 0.166666;
  unaff_EBP[5] = unaff_EBP[5] - unaff_EBP[-0xd] * 0.166666;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * 0.25 - unaff_EBP[-9];
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar6 * 8 + (int)unaff_EBP[0x19]);
      uVar8 = 0;
      fVar6 = *(float *)((int)fVar6 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar4 = (1.0 - fVar1) - fVar6;
      unaff_EBP[-0x18] = fVar6 * fVar6 * fVar6;
      unaff_EBP[0x1d] = fVar4 * fVar6;
      unaff_EBP[-0x17] = fVar4 * fVar6 * fVar6 * 3.0;
      unaff_EBP[-0x16] = fVar6 * fVar6 * fVar1 * 3.0;
      fVar2 = fVar4 * fVar4;
      unaff_EBP[-0x15] = fVar2 * fVar6 * 3.0;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * 6.0;
      unaff_EBP[-0x13] = fVar6 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0x12] = fVar2 * fVar4;
      unaff_EBP[-0x11] = fVar2 * fVar1 * 3.0;
      unaff_EBP[-0x10] = fVar4 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar5 = 0.0;
      pfVar7 = unaff_EBP + -7;
      do {
        pfVar11 = unaff_EBP + (uVar8 - 0x18);
        uVar8 = uVar8 + 1;
        fVar2 = pfVar7[-1] * *pfVar11 + fVar2;
        fVar3 = *pfVar11 * *pfVar7 + fVar3;
        fVar5 = pfVar7[1] * *pfVar11 + fVar5;
        pfVar7 = pfVar7 + 3;
      } while (uVar8 < 10);
      fVar10 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar5;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar10) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar7 = (float *)(unaff_EBX + 0xc);
        iVar9 = (int)fVar10 + -3;
        do {
          *(float *)((int)pfVar7 + (int)unaff_EBP + (-0x170 - unaff_EBX)) =
               fVar4 * *pfVar7 +
               fVar6 * *(float *)((int)pfVar7 + ((int)fVar2 - unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar7 + ((int)fVar3 - unaff_EBX));
          pfVar7 = pfVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        fVar10 = unaff_EBP[0x1f];
      }
      pfVar7 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar10 * 4);
      fVar6 = unaff_EBP[0x18];
      pfVar11 = unaff_EBP + -0x5c;
      for (uVar8 = (uint)fVar10 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar7 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        pfVar7 = pfVar7 + 1;
      }
      fVar6 = (float)((int)fVar6 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined1 *)pfVar7 = *(undefined1 *)pfVar11;
        pfVar11 = (float *)((int)pfVar11 + 1);
        pfVar7 = (float *)((int)pfVar7 + 1);
      }
      unaff_EBP[0x18] = fVar6;
    } while ((uint)fVar6 < (uint)fVar1);
  }
  return;
}


// ==== 0x5b01c7 FUN_005b01c7

void FUN_005b01c7(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  int unaff_EBX;
  float *unaff_EBP;
  int unaff_ESI;
  float *pfVar11;
  
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
  unaff_EBP[4] = unaff_EBP[4] * 0.25;
  unaff_EBP[5] = unaff_EBP[5] * 0.25;
  unaff_EBP[-9] = unaff_EBP[0xc] + unaff_EBP[-6];
  unaff_EBP[-0xe] = unaff_EBP[0x13] + unaff_EBP[10] + unaff_EBP[-8];
  unaff_EBP[-0xd] = unaff_EBP[0x14] + unaff_EBP[0xb] + unaff_EBP[-7];
  fVar6 = 0.0;
  unaff_EBP[0x18] = 0.0;
  unaff_EBP[-9] = (unaff_EBP[0x15] + unaff_EBP[-9]) * 0.166666;
  unaff_EBP[4] = unaff_EBP[4] - unaff_EBP[-0xe] * 0.166666;
  unaff_EBP[5] = unaff_EBP[5] - unaff_EBP[-0xd] * 0.166666;
  unaff_EBP[6] = (unaff_EBP[0x12] + unaff_EBP[6]) * 0.25 - unaff_EBP[-9];
  if (unaff_EBP[0x1a] != 0.0) {
    do {
      fVar1 = *(float *)((int)fVar6 * 8 + (int)unaff_EBP[0x19]);
      uVar8 = 0;
      fVar6 = *(float *)((int)fVar6 * 8 + 4 + (int)unaff_EBP[0x19]);
      fVar4 = (1.0 - fVar1) - fVar6;
      unaff_EBP[-0x18] = fVar6 * fVar6 * fVar6;
      unaff_EBP[0x1d] = fVar4 * fVar6;
      unaff_EBP[-0x17] = fVar4 * fVar6 * fVar6 * 3.0;
      unaff_EBP[-0x16] = fVar6 * fVar6 * fVar1 * 3.0;
      fVar2 = fVar4 * fVar4;
      unaff_EBP[-0x15] = fVar2 * fVar6 * 3.0;
      unaff_EBP[-0x14] = unaff_EBP[0x1d] * fVar1 * 6.0;
      unaff_EBP[-0x13] = fVar6 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0x12] = fVar2 * fVar4;
      unaff_EBP[-0x11] = fVar2 * fVar1 * 3.0;
      unaff_EBP[-0x10] = fVar4 * fVar1 * fVar1 * 3.0;
      unaff_EBP[-0xf] = fVar1 * fVar1 * fVar1;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar5 = 0.0;
      pfVar7 = unaff_EBP + -7;
      do {
        pfVar11 = unaff_EBP + (uVar8 - 0x18);
        uVar8 = uVar8 + 1;
        fVar2 = pfVar7[-1] * *pfVar11 + fVar2;
        fVar3 = *pfVar11 * *pfVar7 + fVar3;
        fVar5 = pfVar7[1] * *pfVar11 + fVar5;
        pfVar7 = pfVar7 + 3;
      } while (uVar8 < 10);
      fVar10 = unaff_EBP[0x1f];
      unaff_EBP[-0x5a] = fVar5;
      unaff_EBP[-0x5b] = fVar3;
      unaff_EBP[-0x5c] = fVar2;
      if (3 < (uint)fVar10) {
        fVar2 = unaff_EBP[0x1c];
        fVar3 = unaff_EBP[0x1e];
        pfVar7 = (float *)(unaff_EBX + 0xc);
        iVar9 = (int)fVar10 + -3;
        do {
          *(float *)((int)pfVar7 + (int)unaff_EBP + (-0x170 - unaff_EBX)) =
               fVar4 * *pfVar7 +
               fVar6 * *(float *)((int)pfVar7 + ((int)fVar2 - unaff_EBX)) +
               fVar1 * *(float *)((int)pfVar7 + ((int)fVar3 - unaff_EBX));
          pfVar7 = pfVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        fVar10 = unaff_EBP[0x1f];
      }
      pfVar7 = (float *)unaff_EBP[0x1b];
      unaff_EBP[0x1b] = (float)((int)unaff_EBP[0x1b] + (int)fVar10 * 4);
      fVar6 = unaff_EBP[0x18];
      pfVar11 = unaff_EBP + -0x5c;
      for (uVar8 = (uint)fVar10 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar7 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        pfVar7 = pfVar7 + 1;
      }
      fVar6 = (float)((int)fVar6 + 1);
      fVar1 = unaff_EBP[0x1a];
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined1 *)pfVar7 = *(undefined1 *)pfVar11;
        pfVar11 = (float *)((int)pfVar11 + 1);
        pfVar7 = (float *)((int)pfVar7 + 1);
      }
      unaff_EBP[0x18] = fVar6;
    } while ((uint)fVar6 < (uint)fVar1);
  }
  return;
}


// ==== 0x5b0484 FUN_005b0484

undefined4 FUN_005b0484(LPBYTE param_1,LPCSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  LVar1 = RegOpenKeyA((HKEY)0x80000002,"Software\\Microsoft\\Direct3D",&local_8);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExA(local_8,param_2,(LPDWORD)0x0,(LPDWORD)&param_3,param_3,
                             (LPDWORD)&stack0x00000010);
    RegCloseKey(local_8);
    if ((LVar1 == 0) && (param_3 == param_1)) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x5b04e1 FUN_005b04e1

/* WARNING: Removing unreachable block (ram,0x005b04ed) */

undefined8 __fastcall FUN_005b04e1(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return CONCAT44(param_2,(uint)((*(uint *)(iVar1 + 8) & 0x800000) != 0));
}


// ==== 0x5b0506 FUN_005b0506

int FUN_005b0506(void)

{
  LSTATUS LVar1;
  int iVar2;
  _union_530 local_38 [8];
  ushort local_18;
  int local_14;
  DWORD local_10 [2];
  HKEY local_8;
  
  LVar1 = RegOpenKeyA((HKEY)0x80000002,"Software\\Microsoft\\Direct3D",&local_8);
  if (LVar1 == 0) {
    local_10[1] = 4;
    LVar1 = RegQueryValueExA(local_8,"DisableMMX",(LPDWORD)0x0,local_10,(LPBYTE)&local_14,
                             local_10 + 1);
    if (((LVar1 == 0) && (local_10[0] == 4)) && (local_14 != 0)) {
      RegCloseKey(local_8);
      DAT_006d4cfc = 0;
      return 0;
    }
    RegCloseKey(local_8);
  }
  if (DAT_006d4cfc < 0) {
    DAT_006d4cfc = 0;
    GetSystemInfo((LPSYSTEM_INFO)&local_38[0].s);
    if (((local_38[0].s.wProcessorArchitecture == 0) && (4 < local_18)) &&
       (iVar2 = FUN_005b04e1(), iVar2 != 0)) {
      DAT_006d4cfc = 1;
    }
  }
  return DAT_006d4cfc;
}


// ==== 0x5b05b6 FUN_005b05b6

/* WARNING: Removing unreachable block (ram,0x005b05e0) */

void FUN_005b05b6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00673444();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  builtin_strncpy((char *)(unaff_EBP + -0x24),"Genu",4);
  builtin_strncpy((char *)(unaff_EBP + -0x20),"ineI",4);
  builtin_strncpy((char *)(unaff_EBP + -0x1c),"ntel",4);
  *(char *)(unaff_EBP + -0x18) = '\0';
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)cpuid_basic_info(0);
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *(undefined4 *)(unaff_EBP + -0x2c) = *puVar1;
  *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  FUN_005b05fc();
  return;
}


// ==== 0x5b05f0 Catch@005b05f0

code * Catch_005b05f0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x14);
  return FUN_005b0602;
}


// ==== 0x5b05fc FUN_005b05fc

/* WARNING: Removing unreachable block (ram,0x005b0617) */

undefined4 FUN_005b05fc(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x2c) == 0) {
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  else {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
    uVar2 = puVar1[2];
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar1;
    *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
    if ((*(uint *)(unaff_EBP + -0x28) & 0x2000000) != 0) {
      *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 4;
    }
    if ((*(uint *)(unaff_EBP + -0x28) & 0x4000000) != 0) {
      *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 8;
    }
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}


// ==== 0x5b0602 FUN_005b0602

undefined4 FUN_005b0602(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x3c);
}


// ==== 0x5b065b D3DXPSGP_Init

/* [canon] render med (hopper+capstone) docs/re/render.md */

int D3DXPSGP_Init(int param_1)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int local_8;
  
  if (param_1 == 0) {
    DAT_006d4d00 = 0xffff;
    ppuVar4 = &PTR_FUN_006d4be0;
    ppuVar5 = &PTR_FUN_006d4ac0;
    for (iVar3 = 0x47; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar5 = *ppuVar4;
      ppuVar4 = ppuVar4 + 1;
      ppuVar5 = ppuVar5 + 1;
    }
  }
  else if (DAT_006d4d00 == 0xffff) {
    DAT_006d4d00 = 0;
    ppuVar4 = &PTR_FUN_006d4be0;
    ppuVar5 = &PTR_FUN_006d4ac0;
    for (iVar3 = 0x47; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar5 = *ppuVar4;
      ppuVar4 = ppuVar4 + 1;
      ppuVar5 = ppuVar5 + 1;
    }
    FUN_005d70ce(&PTR_FUN_006d4ac0);
    iVar3 = FUN_005b0484(4,"DisablePSGP",&param_1,4);
    if (iVar3 == 0) {
      param_1 = 0;
    }
    iVar3 = FUN_005b0484(4,"DisableD3DXPSGP",&local_8,4);
    if (iVar3 != 0) {
      param_1 = local_8;
    }
    if (param_1 != 1) {
      if ((param_1 == 2) || (BVar1 = IsProcessorFeaturePresent(7), BVar1 == 0)) {
        uVar2 = FUN_005b05b6();
        if ((uVar2 & 8) == 0) {
          BVar1 = IsProcessorFeaturePresent(6);
          if (BVar1 != 0) {
            FUN_005d662e(&PTR_FUN_006d4ac0);
            DAT_006d4d00 = 3;
          }
        }
        else {
          FUN_005d679c(&PTR_FUN_006d4ac0);
          DAT_006d4d00 = 2;
        }
      }
      else {
        FUN_005d69e4(&PTR_FUN_006d4ac0);
        DAT_006d4d00 = 1;
      }
    }
  }
  return DAT_006d4d00;
}


// ==== 0x5b0757 FUN_005b0757

void * __thiscall FUN_005b0757(void *param_1,byte param_2)

{
  FUN_005b07b2();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b0773 FUN_005b0773

void __fastcall FUN_005b0773(int param_1)

{
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    _free(*(void **)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return;
}


// ==== 0x5b079c FUN_005b079c

void __fastcall FUN_005b079c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *puVar1 = 0;
  *(undefined4 **)(param_1 + 0x1c) = puVar1;
  *(undefined4 **)(param_1 + 0x18) = puVar1;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ==== 0x5b07b2 FUN_005b07b2

void __fastcall FUN_005b07b2(int param_1)

{
  int iVar1;
  
  while (*(int *)(param_1 + 0x20) != 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(iVar1 + 0x20) = 0;
    FUN_005b0757(1);
  }
  FUN_005b0773();
  return;
}


// ==== 0x5b07da FUN_005b07da

int FUN_005b07da(int param_1,int *param_2,int param_3,int *param_4,undefined4 *param_5)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  byte *local_18;
  byte *local_14;
  byte *local_10;
  byte *local_c;
  
  piVar6 = param_4;
  piVar2 = (int *)*param_4;
  piVar3 = (int *)*param_2;
  if (((piVar3[1] == piVar2[1]) && (iVar7 = *piVar3, iVar7 == *piVar2)) && (piVar3[4] == piVar2[4]))
  {
    if (*(int *)(piVar3[2] + param_1) == 0) {
      local_14 = (byte *)0x0;
    }
    else {
      local_14 = (byte *)((int *)(piVar3[2] + param_1) + 1);
    }
    if (*(int *)(piVar2[2] + param_3) == 0) {
      local_c = (byte *)0x0;
    }
    else {
      local_c = (byte *)((int *)(piVar2[2] + param_3) + 1);
    }
    if (*(int *)(piVar3[3] + param_1) == 0) {
      local_18 = (byte *)0x0;
    }
    else {
      local_18 = (byte *)((int *)(piVar3[3] + param_1) + 1);
    }
    if (*(int *)(piVar2[3] + param_3) == 0) {
      local_10 = (byte *)0x0;
    }
    else {
      local_10 = (byte *)((int *)(piVar2[3] + param_3) + 1);
    }
    if (local_14 != (byte *)0x0) {
      if (local_c == (byte *)0x0) {
        return -0x7fffbffb;
      }
      do {
        bVar1 = *local_14;
        bVar8 = bVar1 < *local_c;
        if (bVar1 != *local_c) {
LAB_005b08b8:
          local_c = (byte *)((1 - (uint)bVar8) - (uint)(bVar8 != 0));
          goto joined_r0x005b08bf;
        }
        if (bVar1 == 0) break;
        bVar1 = local_14[1];
        bVar8 = bVar1 < local_c[1];
        if (bVar1 != local_c[1]) goto LAB_005b08b8;
        local_14 = local_14 + 2;
        local_c = local_c + 2;
      } while (bVar1 != 0);
      local_c = (byte *)0x0;
    }
joined_r0x005b08bf:
    if (local_c == (byte *)0x0) {
      if (local_18 != (byte *)0x0) {
        if (local_10 == (byte *)0x0) {
          return -0x7fffbffb;
        }
        do {
          bVar1 = *local_18;
          bVar8 = bVar1 < *local_10;
          if (bVar1 != *local_10) {
LAB_005b08fe:
            local_10 = (byte *)((1 - (uint)bVar8) - (uint)(bVar8 != 0));
            goto joined_r0x005b0905;
          }
          if (bVar1 == 0) break;
          bVar1 = local_18[1];
          bVar8 = bVar1 < local_10[1];
          if (bVar1 != local_10[1]) goto LAB_005b08fe;
          local_18 = local_18 + 2;
          local_10 = local_10 + 2;
        } while (bVar1 != 0);
        local_10 = (byte *)0x0;
      }
joined_r0x005b0905:
      if ((local_10 == (byte *)0x0) && (iVar4 = piVar3[1], -1 < iVar4)) {
        if (iVar4 < 4) {
          if ((piVar3[5] == piVar2[5]) && (piVar3[6] == piVar2[6])) {
            *param_2 = (int)(piVar3 + 7);
            *param_4 = *param_4 + 0x1c;
            return 0;
          }
        }
        else {
          if (iVar4 == 4) {
            if ((4 < iVar7) && ((iVar7 < 10 || ((0xe < iVar7 && (iVar7 < 0x11)))))) {
              *param_5 = 1;
            }
            *param_2 = *param_2 + 0x14;
            *param_4 = *param_4 + 0x14;
            return 0;
          }
          if ((iVar4 == 5) && (uVar5 = piVar3[5], uVar5 == piVar2[5])) {
            param_4 = (int *)0x0;
            *param_2 = (int)(piVar3 + 6);
            *piVar6 = *piVar6 + 0x18;
            if (uVar5 == 0) {
              return 0;
            }
            do {
              iVar7 = FUN_005b07da(param_1,param_2,param_3,piVar6,param_5);
              if (iVar7 < 0) {
                return iVar7;
              }
              param_4 = (int *)((int)param_4 + 1);
            } while (param_4 < uVar5);
            return iVar7;
          }
        }
      }
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5b09cb FUN_005b09cb

void FUN_005b09cb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  *param_5 = 0;
  FUN_005b07da(param_1,&param_2,param_3,&param_4,param_5);
  return;
}


// ==== 0x5b09ec FUN_005b09ec

void * __thiscall FUN_005b09ec(void *param_1,byte param_2)

{
  FUN_005b0773();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b0a08 FUN_005b0a08

void __fastcall FUN_005b0a08(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006994e8;
  if ((void *)param_1[2] != (void *)0x0) {
    _free((void *)param_1[2]);
    param_1[2] = 0;
  }
  if (param_1[4] != 0) {
    FUN_005b0757(1);
    param_1[4] = 0;
  }
  return;
}


// ==== 0x5b0a37 FUN_005b0a37

void * __thiscall FUN_005b0a37(void *param_1,byte param_2)

{
  FUN_005b0a08();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b0a53 FUN_005b0a53

undefined4 FUN_005b0a53(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_006a08c8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = &DAT_006abe14;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== 0x5b0a97 FUN_005b0a97

int FUN_005b0a97(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  piVar6 = param_5;
  piVar5 = param_4;
  piVar4 = param_3;
  piVar10 = (int *)*param_2;
  iVar2 = piVar10[1];
  local_14 = *piVar10;
  local_8 = 0;
  local_c = 1;
  if (piVar10[4] != 0) {
    local_c = piVar10[4];
  }
  if (*(int *)(piVar10[2] + param_1) == 0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(piVar10[2] + param_1) + 1;
  }
  if (*(int *)(piVar10[3] + param_1) == 0) {
    local_10 = (int *)0x0;
  }
  else {
    local_10 = (int *)(piVar10[3] + param_1) + 1;
  }
  pcVar1 = (char *)((int)piVar9 + 1);
  piVar10 = piVar9;
  do {
    iVar8 = *piVar10;
    piVar10 = (int *)((int)piVar10 + 1);
  } while ((char)iVar8 != '\0');
  cVar3 = (char)piVar9;
  do {
    iVar8 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar8 != '\0');
  iVar8 = 0;
  if (local_10 != (int *)0x0) {
    piVar11 = local_10;
    do {
      iVar8 = *piVar11;
      piVar11 = (int *)((int)piVar11 + 1);
    } while ((char)iVar8 != '\0');
    piVar7 = local_10;
    do {
      iVar8 = *piVar7;
      piVar7 = (int *)((int)piVar7 + 1);
    } while ((char)iVar8 != '\0');
    iVar8 = (uint)((((char)piVar7 - ((char)local_10 + '\x01')) + 1U & 3) != 0) +
            ((uint)((int)piVar11 + (1 - (int)((int)local_10 + 1))) >> 2);
  }
  *param_5 = (((uint)((int)piVar10 + (1 - (int)pcVar1)) >> 2) +
             iVar8 + (uint)((((char)piVar9 - (cVar3 + '\x01')) + 1U & 3) != 0)) * 4 + 8;
  *param_4 = 0;
  *param_3 = 0;
  if (-1 < iVar2) {
    if (iVar2 < 4) {
      *param_4 = *(int *)(*param_2 + 0x18) * *(int *)(*param_2 + 0x14) * local_c;
      *param_3 = 0x1c;
      if (((local_14 == 1) || (local_14 == 2)) || (local_14 == 3)) {
        *param_4 = *param_4 << 2;
        *param_2 = *param_2 + 0x1c;
        return 0;
      }
    }
    else if (iVar2 == 4) {
      *param_3 = 0x14;
      if ((3 < local_14) && ((local_14 < 10 || ((0xe < local_14 && (local_14 < 0x11)))))) {
        *param_4 = local_c << 2;
        *param_2 = *param_2 + 0x14;
        return 0;
      }
    }
    else if (iVar2 == 5) {
      local_18 = *(uint *)(*param_2 + 0x14);
      param_5 = (int *)0x0;
      *param_2 = *param_2 + 0x18;
      *param_3 = 0x18;
      if (local_18 != 0) {
        local_1c = 5;
        do {
          local_8 = FUN_005b0a97(param_1,param_2,&param_3,&param_4,&local_1c);
          if (local_8 < 0) {
            return local_8;
          }
          *piVar5 = *piVar5 + (int)param_4;
          *piVar4 = *piVar4 + (int)param_3;
          *piVar6 = *piVar6 + local_1c;
          param_5 = (int *)((int)param_5 + 1);
        } while (param_5 < local_18);
      }
      *piVar5 = *piVar5 * local_c;
      return local_8;
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5b0c4b FUN_005b0c4b

int FUN_005b0c4b(int param_1,int *param_2,int *param_3,int param_4,int *param_5,int *param_6,
                int *param_7,int *param_8)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *local_10;
  int *local_c;
  int local_8;
  
  piVar3 = param_5;
  *(undefined4 *)(*param_6 + 4) = *(undefined4 *)(*param_2 + 4);
  *(undefined4 *)*param_6 = *(undefined4 *)*param_2;
  *(undefined4 *)(*param_6 + 0x10) = *(undefined4 *)(*param_2 + 0x10);
  *(int *)(*param_6 + 8) = *param_5;
  piVar8 = (int *)*param_2;
  iVar4 = piVar8[1];
  iVar6 = *piVar8;
  local_8 = 0;
  param_5 = (int *)0x1;
  if (piVar8[4] != 0) {
    param_5 = (int *)piVar8[4];
  }
  if (*(int *)(piVar8[2] + param_1) == 0) {
    local_c = (int *)0x0;
  }
  else {
    local_c = (int *)(piVar8[2] + param_1) + 1;
  }
  if (*(int *)(piVar8[3] + param_1) == 0) {
    local_10 = (int *)0x0;
  }
  else {
    local_10 = (int *)(piVar8[3] + param_1) + 1;
  }
  piVar8 = local_c;
  do {
    iVar2 = *piVar8;
    piVar8 = (int *)((int)piVar8 + 1);
  } while ((char)iVar2 != '\0');
  pcVar1 = (char *)((int)piVar8 + (1 - (int)((int)local_c + 1)));
  *(char **)(param_4 + *piVar3) = pcVar1;
  *piVar3 = *piVar3 + 4;
  piVar8 = (int *)(*piVar3 + param_4);
  for (uVar5 = (uint)pcVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar8 = *local_c;
    local_c = local_c + 1;
    piVar8 = piVar8 + 1;
  }
  for (uVar5 = (uint)pcVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)piVar8 = (char)*local_c;
    local_c = (int *)((int)local_c + 1);
    piVar8 = (int *)((int)piVar8 + 1);
  }
  *piVar3 = *piVar3 + ((uint)(((uint)pcVar1 & 3) != 0) + ((uint)pcVar1 >> 2)) * 4;
  *(int *)(*param_6 + 0xc) = *piVar3;
  if (local_10 == (int *)0x0) {
    *(undefined4 *)(param_4 + *piVar3) = 0;
    *piVar3 = *piVar3 + 4;
  }
  else {
    piVar8 = local_10;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    pcVar1 = (char *)((int)piVar8 + (1 - (int)((int)local_10 + 1)));
    *(char **)(param_4 + *piVar3) = pcVar1;
    *piVar3 = *piVar3 + 4;
    piVar8 = (int *)(*piVar3 + param_4);
    for (uVar5 = (uint)pcVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar8 = *local_10;
      local_10 = local_10 + 1;
      piVar8 = piVar8 + 1;
    }
    for (uVar5 = (uint)pcVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(char *)piVar8 = (char)*local_10;
      local_10 = (int *)((int)local_10 + 1);
      piVar8 = (int *)((int)piVar8 + 1);
    }
    *piVar3 = *piVar3 + ((uint)(((uint)pcVar1 & 3) != 0) + ((uint)pcVar1 >> 2)) * 4;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      *(undefined4 *)(*param_6 + 0x14) = *(undefined4 *)(*param_2 + 0x14);
      *(undefined4 *)(*param_6 + 0x18) = *(undefined4 *)(*param_2 + 0x18);
      uVar5 = *(int *)(*param_2 + 0x18) * *(int *)(*param_2 + 0x14) * (int)param_5;
      if (((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) {
        iVar4 = uVar5 * 4;
        puVar7 = (undefined4 *)*param_3;
        puVar9 = (undefined4 *)*param_7;
        for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        *param_3 = *param_3 + iVar4;
        *param_7 = *param_7 + iVar4;
        *param_2 = *param_2 + 0x1c;
        *param_6 = *param_6 + 0x1c;
        return 0;
      }
    }
    else if (iVar4 == 4) {
      if ((3 < iVar6) && ((iVar6 < 10 || ((0xe < iVar6 && (iVar6 < 0x11)))))) {
        if (param_5 != (int *)0x0) {
          param_4 = (int)param_5;
          do {
            *(int *)*param_7 = *param_8;
            *param_8 = *param_8 + 1;
            *param_3 = *param_3 + 4;
            *param_7 = *param_7 + 4;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
        *param_2 = *param_2 + 0x14;
        *param_6 = *param_6 + 0x14;
        return 0;
      }
    }
    else if (iVar4 == 5) {
      *(undefined4 *)(*param_6 + 0x14) = *(undefined4 *)(*param_2 + 0x14);
      uVar5 = *(uint *)(*param_2 + 0x14);
      *param_2 = *param_2 + 0x18;
      *param_6 = *param_6 + 0x18;
      iVar4 = *param_2;
      iVar6 = *param_6;
      do {
        if (param_5 == (int *)0x0) {
          return local_8;
        }
        local_10 = (int *)0x0;
        *param_2 = iVar4;
        *param_6 = iVar6;
        if (uVar5 != 0) {
          do {
            local_8 = FUN_005b0c4b(param_1,param_2,param_3,param_4,piVar3,param_6,param_7,param_8);
            if (local_8 < 0) {
              return local_8;
            }
            local_10 = (int *)((int)local_10 + 1);
          } while (local_10 < uVar5);
        }
        param_5 = (int *)((int)param_5 + -1);
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5b0eda FUN_005b0eda

void FUN_005b0eda(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,undefined4 *param_8)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_8;
  iVar1 = param_4;
  param_4 = param_5 + param_4 + param_6;
  *param_8 = 0;
  param_8 = (undefined4 *)(param_4 + param_7);
  FUN_005b0c4b(param_1,&param_2,&param_3,iVar1,&param_5,&param_4,&param_8,puVar2);
  return;
}


// ==== 0x5b0f1d FUN_005b0f1d

int FUN_005b0f1d(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint local_c;
  int local_8;
  
  piVar5 = param_1;
  local_8 = 0;
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  iVar3 = piVar1[1];
  param_1 = (int *)0x1;
  if (piVar1[4] != 0) {
    param_1 = (int *)piVar1[4];
  }
  if (-1 < iVar3) {
    if (iVar3 < 4) {
      if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
        *param_2 = *param_2 + piVar1[6] * piVar1[5] * (int)param_1 * 4;
        *piVar5 = *piVar5 + 0x1c;
        return 0;
      }
    }
    else if (iVar3 == 4) {
      if ((3 < iVar2) && ((iVar2 < 10 || ((0xe < iVar2 && (iVar2 < 0x11)))))) {
        for (; param_1 != (int *)0x0; param_1 = (int *)((int)param_1 + -1)) {
          *(undefined4 *)*param_3 = *(undefined4 *)*param_2;
          *param_3 = *param_3 + 4;
          *param_2 = *param_2 + 4;
        }
        *piVar5 = *piVar5 + 0x14;
        return 0;
      }
    }
    else if (iVar3 == 5) {
      uVar4 = piVar1[5];
      *piVar5 = (int)(piVar1 + 6);
      do {
        if (param_1 == (int *)0x0) {
          return local_8;
        }
        local_c = 0;
        *piVar5 = (int)(piVar1 + 6);
        if (uVar4 != 0) {
          do {
            local_8 = FUN_005b0f1d(piVar5,param_2,param_3);
            if (local_8 < 0) {
              return local_8;
            }
            local_c = local_c + 1;
          } while (local_c < uVar4);
        }
        param_1 = (int *)((int)param_1 + -1);
      } while( true );
    }
  }
  return -0x7fffbffb;
}


