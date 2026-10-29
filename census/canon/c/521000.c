// ==== 0x521010 EAXAemsManager::BindCollisionClassHandles

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

uint EAXAemsManager__BindCollisionClassHandles(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_IMPACT_WORLD_006f8170);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_IMPACT_SMOKABLE_006f8178);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_SCRAPE_WORLD_006f8180);
  uVar4 = Csis__ClassHandle__Set(&PTR_s_SCRAPE_SMOKABLE_006f8188);
  return uVar4 | uVar1 | uVar2 | uVar3;
}


// ==== 0x521060 FUN_00521060

uint FUN_00521060(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_PlayCommonSample_006f8190);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_006f8198);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_loop_006f81a0);
  uVar4 = Csis__ClassHandle__Set(&PTR_s_FEDriveOn_006f81a8);
  return uVar4 | uVar1 | uVar2 | uVar3;
}


// ==== 0x5210b0 EAXAemsManager::BindAmbientClassHandles

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

uint EAXAemsManager__BindAmbientClassHandles(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_FX_ROADNOISE_006f81b8);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_FX_WIND_006f81c8);
  return uVar3 | uVar1 | uVar2;
}


// ==== 0x5210f0 EAXAemsManager::BindStreamClassHandles

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

uint EAXAemsManager__BindStreamClassHandles(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_MUSIC_STREAM_006f2210);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_AMBIENT_STEREO_STREAM_006f2218);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_AMBIENT_MONO_STREAM_006f2220);
  uVar4 = Csis__ClassHandle__Set(&PTR_s_TCAR_MONO_STREAM_006f2228);
  uVar5 = Csis__ClassHandle__Set(&PTR_s_SPEECH_STREAM_006f2230);
  return uVar5 | uVar1 | uVar2 | uVar3 | uVar4;
}


// ==== 0x521150 FUN_00521150

void * __thiscall FUN_00521150(void *param_1,byte param_2)

{
  FUN_00521170();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x521170 FUN_00521170

void __fastcall FUN_00521170(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bf4a4;
  if (param_1[1] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[1]);
    }
    _free((void *)param_1[1]);
    param_1[1] = 0;
  }
  if (param_1[2] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[2]);
    }
    _free((void *)param_1[2]);
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[3]);
    }
    _free((void *)param_1[3]);
    param_1[3] = 0;
  }
  if (param_1[4] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[4]);
    }
    _free((void *)param_1[4]);
    param_1[4] = 0;
  }
  if (param_1[5] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[5]);
    }
    _free((void *)param_1[5]);
    param_1[5] = 0;
  }
  if (param_1[6] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[6]);
    }
    _free((void *)param_1[6]);
    param_1[6] = 0;
  }
  if (param_1[7] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[7]);
    }
    _free((void *)param_1[7]);
    param_1[7] = 0;
  }
  if (param_1[8] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[8]);
    }
    _free((void *)param_1[8]);
    param_1[8] = 0;
  }
  if (param_1[9] != 0) {
    if (DAT_00735674 != '\0') {
      FUN_0064b6e0(param_1[9]);
    }
    _free((void *)param_1[9]);
    param_1[9] = 0;
  }
  return;
}


// ==== 0x5212e0 EAXAemsManager::Initialize

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXAemsManager__Initialize(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  
  DAT_0072cfd0 = param_1;
  puVar2 = (undefined4 *)(param_1 + 0x200);
  iVar1 = 0;
  do {
    *puVar2 = 0;
    *(undefined4 *)((int)&DAT_0072d190 + iVar1) = 0;
    *(undefined4 *)((int)&DAT_0072cfd8 + iVar1) = 0;
    iVar1 = iVar1 + 4;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x1b8);
  puVar2 = &DAT_0072ce54;
  do {
    puVar2[-1] = 0xffffffff;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0;
    puVar2 = puVar2 + 3;
  } while ((int)puVar2 < 0x72cfd4);
  *(undefined4 *)(param_1 + 0x580) = 0x10;
  *(undefined4 *)(param_1 + 0x584) = 0x10;
  *(undefined4 *)(param_1 + 0x588) = 0x10;
  *(undefined4 *)(param_1 + 0x59c) = 0x36;
  *(undefined4 *)(param_1 + 0x5a0) = 0x36;
  bVar8 = DAT_006f1dd8 == 1;
  *(undefined4 *)(param_1 + 0x570) = 0;
  *(undefined4 *)(param_1 + 0x574) = 2;
  *(undefined4 *)(param_1 + 0x578) = 0xc;
  *(undefined4 *)(param_1 + 0x57c) = 0xc;
  *(undefined4 *)(param_1 + 0x58c) = 0x12;
  *(undefined4 *)(param_1 + 0x590) = 0x21;
  *(undefined4 *)(param_1 + 0x594) = 0x30;
  *(undefined4 *)(param_1 + 0x598) = 0x33;
  *(undefined4 *)(param_1 + 0x5a4) = 0x46;
  *(undefined4 *)(param_1 + 0x5a8) = 0x5a;
  if (bVar8) {
    EAXAemsManager__ResetLoadQueue(param_1);
    iVar1 = param_1 + 0x5bc;
    iVar3 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\Global_.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 4) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,1);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\NFSU_Streams.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0xc) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,2);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\ENGINE_EVTSYS.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0x14) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,3);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\COLLISION_EVTS.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0x18) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,4);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\EVTSYS_FE.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0x1c) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,5);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\EVTSYS_TURBO.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0x20) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,6);
    DAT_00735678 = DAT_00735678 + 1;
    iVar3 = 0;
    DAT_00735674 = 0;
    cVar5 = 's';
    do {
      *(char *)(iVar1 + iVar3) = cVar5;
      cVar5 = (&DAT_006bf589)[iVar3];
      iVar3 = iVar3 + 1;
    } while (cVar5 != '\0');
    cVar5 = 'E';
    pcVar7 = "Evt_Sys\\EVTSYS_ENVIRO.csi";
    do {
      *(char *)(iVar3 + iVar1) = cVar5;
      cVar5 = pcVar7[1];
      iVar3 = iVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar5 != '\0');
    *(undefined1 *)(iVar3 + iVar1) = 0;
    iVar3 = bOpenFile(iVar1,1,1);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
      FUN_00594d40();
    }
    pvVar4 = _malloc(uVar6);
    *(void **)(param_1 + 0x24) = pvVar4;
    DAT_0073567c = 1;
    FUN_0058aba0(pvVar4,iVar1,0,uVar6,FUN_00521ab0,7);
    DAT_00735678 = DAT_00735678 + 1;
    DAT_00735674 = 0;
  }
  return;
}


// ==== 0x521850 FUN_00521850

void FUN_00521850(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = EAXAemsManager__AreAllBanksLoaded(in_EAX);
  if (iVar1 == 0) {
    FUN_005219c0(in_EAX);
  }
  else if (DAT_0073568c != (code *)0x0) {
    (*DAT_0073568c)(DAT_00735690);
    DAT_0073568c = (code *)0x0;
    DAT_00735690 = 0;
    EAXAemsManager__BindStreamClassHandles();
    EAXAemsManager__BindFXClassHandles();
    EAXAemsManager__BindCarClassHandles();
    EAXAemsManager__BindCollisionClassHandles();
    EAXAemsManager__BindAmbientClassHandles();
    Csis__ClassHandle__Set(&PTR_s_FX_TURBO_01_006f81b0);
    FUN_00521060();
    return;
  }
  return;
}


// ==== 0x5218c0 EAXAemsManager::ResetLoadQueue

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void EAXAemsManager__ResetLoadQueue(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x5b0) = 0;
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  *(undefined4 *)(param_1 + 0x5ac) = 0;
  iVar6 = param_1 + 0xe7c;
  DAT_00735678 = 0;
  puVar3 = &DAT_0072ce54;
  iVar4 = param_1 + -0x6b7ea4;
  do {
    puVar3[-1] = 0xffffffff;
    *puVar3 = 0xffffffff;
    puVar3[1] = 0;
    iVar1 = 0;
    cVar2 = 'N';
    do {
      (&DAT_006b8d20)[iVar4 + iVar1] = cVar2;
      cVar2 = (&DAT_006b8d21)[iVar1];
      iVar1 = iVar1 + 1;
    } while (cVar2 != '\0');
    cVar2 = 'N';
    puVar5 = &DAT_006b8d20;
    do {
      *(char *)(iVar6 + iVar1) = cVar2;
      cVar2 = puVar5[1];
      iVar1 = iVar1 + 1;
      puVar5 = puVar5 + 1;
    } while (cVar2 != '\0');
    *(undefined1 *)(iVar6 + iVar1) = 0;
    puVar3 = puVar3 + 3;
    iVar6 = iVar6 + 0x40;
    iVar4 = iVar4 + 0x40;
  } while ((int)puVar3 < 0x72cfd4);
  _DAT_0073569c = 0;
  *(undefined4 *)(param_1 + 0x5b8) = 0;
  DAT_006f870c = 0;
  return;
}


// ==== 0x521980 EAXAemsManager::AreAllBanksLoaded

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

undefined4 EAXAemsManager__AreAllBanksLoaded(void)

{
  int *piVar1;
  
  if (DAT_00735678 == 0) {
    piVar1 = &DAT_0072ce58;
    while (((*piVar1 != 1 && (*piVar1 != 2)) && (piVar1[-1] != 1))) {
      piVar1 = piVar1 + 3;
      if (0x72cfd7 < (int)piVar1) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x5219c0 FUN_005219c0

int FUN_005219c0(void)

{
  int *piVar1;
  int iVar2;
  
  if ((DAT_00735678 == 0) && ((DAT_006f8710 != '\0' || (DAT_007356a4 != '\0')))) {
    iVar2 = 0;
    piVar1 = &DAT_0072ce58;
    do {
      if (*piVar1 == 2) {
        FUN_00565ce0();
        (&DAT_0072cfd8)[(&DAT_0072ce50)[iVar2 * 3]] = 0;
        (&DAT_0072ce58)[iVar2 * 3] = 0;
        return 0;
      }
      piVar1 = piVar1 + 3;
      iVar2 = iVar2 + 1;
    } while ((int)piVar1 < 0x72cfd8);
    piVar1 = &DAT_0072ce58;
    do {
      if (*piVar1 == 1) {
        return 0;
      }
      piVar1 = piVar1 + 3;
    } while ((int)piVar1 < 0x72cfd8);
    iVar2 = 0;
    piVar1 = &DAT_0072ce54;
    do {
      if (*piVar1 == 1) {
        DAT_006f8708 = (&DAT_0072ce50)[iVar2 * 3];
        DAT_006f870c = iVar2;
        (&DAT_0072ce58)[iVar2 * 3] = 1;
        (&DAT_0072ce54)[iVar2 * 3] = 0xffffffff;
        EAXAemsManager__StartSlotBankLoad();
        if (iVar2 < 0x20) {
          DAT_00735694 = 0;
        }
        return iVar2;
      }
      piVar1 = piVar1 + 3;
      iVar2 = iVar2 + 1;
    } while ((int)piVar1 < 0x72cfd4);
    return iVar2;
  }
  return 0;
}


// ==== 0x521ab0 FUN_00521ab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00521ab0(int param_1)

{
  undefined4 uVar1;
  
  DAT_00735678 = DAT_00735678 + -1;
  if (7 < param_1) {
    if (8 < param_1) {
      (&DAT_0072ce54)[param_1 * 3 + -0x1b] = 1;
      _DAT_0073569c = _DAT_0073569c + 1;
    }
    return;
  }
  DAT_00735698 = 0;
  switch(param_1) {
  case 1:
    DAT_00735698 = 0;
    break;
  case 2:
    DAT_00735698 = 1;
    break;
  case 3:
    DAT_00735698 = 2;
    break;
  case 4:
    DAT_00735698 = 3;
    break;
  case 5:
    DAT_00735698 = 4;
    break;
  case 6:
    DAT_00735698 = 5;
    break;
  case 7:
    DAT_00735698 = 6;
  }
  if (DAT_006f1dd8 == 1) {
    uVar1 = EAXAemsManager__GetCurrentBankHandle();
    FUN_0064b5c0(uVar1);
    DAT_00735674 = 1;
  }
  _DAT_00735680 = _DAT_00735680 | 1;
  return;
}


// ==== 0x521b90 FUN_00521b90

void FUN_00521b90(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *unaff_EDI;
  undefined4 local_f0 [6];
  char *local_d8;
  char local_c8;
  char local_c7 [199];
  
  uVar2 = FUN_0063a5d0();
  iVar3 = FUN_00639d70(uVar2);
  uVar2 = FUN_00639c00(uVar2);
  if (iVar3 == 1) {
    FUN_0063c2c0(uVar2,100);
    return;
  }
  local_f0[0] = 0x28;
  FUN_0063aba0(local_f0);
  if (local_d8 != (char *)0x0) {
    local_c8 = *local_d8;
    if (*local_d8 != '\0') {
      pcVar4 = &local_c8;
      do {
        cVar1 = pcVar4[(int)(local_d8 + (1 - (int)&local_c8))];
        pcVar4 = pcVar4 + 1;
        *pcVar4 = cVar1;
      } while (cVar1 != '\0');
    }
    bStrCat2();
    uVar2 = FUN_0063a5d0(&local_c8,1,100,0);
    iVar3 = FUN_00639d70(uVar2);
    uVar2 = FUN_00639c00(uVar2);
    if (iVar3 == 1) {
      FUN_0063c2c0(uVar2,100);
      *unaff_EDI = local_c8;
      if (local_c8 != '\0') {
        iVar3 = -(int)unaff_EDI;
        do {
          cVar1 = unaff_EDI[(int)(local_c7 + iVar3)];
          unaff_EDI = unaff_EDI + 1;
          *unaff_EDI = cVar1;
        } while (cVar1 != '\0');
      }
    }
  }
  return;
}


// ==== 0x521c80 EAXAemsManager::SetCurrentBankPath__bank_name_resolver_

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXAemsManager__SetCurrentBankPath__bank_name_resolver_(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined1 *puVar5;
  
  *(undefined4 *)(in_EAX + 0x34) = 0;
  switch(*(undefined4 *)(in_EAX + 0x38)) {
  case 0:
    *(undefined **)(in_EAX + 0x2c) = (&PTR_s_FE_COMMON_MB_006f7f60)[*(int *)(in_EAX + 0x3c)];
    if (*(int *)(in_EAX + 0x3c) == 0) {
      *(undefined **)(in_EAX + 0x30) = PTR_s_Global__006f7ef8;
    }
    else {
      *(undefined **)(in_EAX + 0x30) = PTR_DAT_006f7ef4;
    }
    break;
  case 1:
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_s_STRM_Music_UG0_MB_006f7f10)[*(int *)(in_EAX + 0x3c) * 2];
    *(undefined **)(in_EAX + 0x34) =
         (&PTR_s_STRM_Music_UG0_MB_006f7f14)[*(int *)(in_EAX + 0x3c) * 2];
    break;
  default:
    *(undefined4 *)(in_EAX + 0x2c) = 0;
    break;
  case 3:
    *(undefined **)(in_EAX + 0x2c) = (&PTR_s_ENV_COMMON_MB_006f7f68)[*(int *)(in_EAX + 0x3c)];
    *(undefined **)(in_EAX + 0x30) = PTR_s_IG_GLOBAL__006f7efc;
    break;
  case 6:
    *(undefined **)(in_EAX + 0x2c) = (&PTR_s_IMPACT_MB_006f7f78)[*(int *)(in_EAX + 0x3c) * 2];
    *(undefined **)(in_EAX + 0x30) = PTR_s_IG_GLOBAL__006f7efc;
    break;
  case 7:
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_s_SKID_PAV_MB_006f7f88)[*(int *)(in_EAX + 0x3c) * 5 + *(int *)(in_EAX + 0x40)];
    if (*(int *)(in_EAX + 0x3c) == 2) {
      *(undefined **)(in_EAX + 0x30) = PTR_s_IG_GLOBAL__006f7efc;
    }
    else {
      *(undefined **)(in_EAX + 0x30) = PTR_s_Skids__006f7f04;
    }
    break;
  case 8:
    iVar1 = *(int *)(in_EAX + 0x3c);
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_s_nitrous_00_mb_006f7fc4)[iVar1 + *(int *)(in_EAX + 0x40) + iVar1 * 4];
    if ((iVar1 == 1) || (iVar1 == 2)) {
      *(undefined **)(in_EAX + 0x30) =
           (&PTR_s_Car_0_Eng_UG_0__006f7eb0)[*(int *)(in_EAX + 0x40) + iVar1 * 4];
    }
    else {
      *(undefined **)(in_EAX + 0x30) = PTR_DAT_006f7f00;
    }
    break;
  case 10:
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_DAT_006f80e0)[*(int *)(in_EAX + 0x40) + *(int *)(in_EAX + 0x3c)];
    break;
  case 0xc:
    iVar1 = *(int *)(in_EAX + 0x40) + *(int *)(in_EAX + 0x3c) * 4;
    *(undefined **)(in_EAX + 0x2c) = (&PTR_s_C0U0_M0_ENG_MB_006f8000)[iVar1];
    *(undefined **)(in_EAX + 0x30) = (&PTR_s_Car_0_Eng_UG_0__006f7eb0)[iVar1];
    break;
  case 0xd:
    iVar1 = *(int *)(in_EAX + 0x3c);
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_s_C0U0_M0_EXH_MB_006f8040)[iVar1 + *(int *)(in_EAX + 0x40) + iVar1 * 4];
    *(undefined **)(in_EAX + 0x30) =
         (&PTR_s_Car_0_Eng_UG_0__006f7eb0)[*(int *)(in_EAX + 0x40) + iVar1 * 4];
    break;
  case 0xe:
    *(undefined **)(in_EAX + 0x2c) =
         (&PTR_s_TURBO_00_MB_006f8090)[*(int *)(in_EAX + 0x3c) * 5 + *(int *)(in_EAX + 0x40)];
    *(undefined **)(in_EAX + 0x30) = PTR_s_TURBO__006f7f08;
  }
  if (*(int *)(in_EAX + 0x34) != 0) {
    bStrCat2(&DAT_006bf4dc);
    bStrCat2(in_EAX + 0x5bc);
    bStrCat2(&DAT_006bf4c4);
    bStrCat2(in_EAX + 0x5bc);
    FUN_00521b90();
    return;
  }
  uVar2 = bStrCat2(&DAT_006bf4dc);
  bStrCat2(uVar2);
  bStrCat2(in_EAX + 0x63c);
  iVar1 = *(int *)(in_EAX + 0x5b8) * 0x40 + 0xe7c + in_EAX;
  iVar3 = 0;
  cVar4 = 'N';
  do {
    *(char *)(iVar1 + iVar3) = cVar4;
    cVar4 = (&DAT_006b8d21)[iVar3];
    iVar3 = iVar3 + 1;
  } while (cVar4 != '\0');
  cVar4 = 'N';
  puVar5 = &DAT_006b8d20;
  do {
    *(char *)(iVar3 + iVar1) = cVar4;
    cVar4 = puVar5[1];
    iVar3 = iVar3 + 1;
    puVar5 = puVar5 + 1;
  } while (cVar4 != '\0');
  *(undefined1 *)(iVar3 + iVar1) = 0;
  return;
}


// ==== 0x521f80 EAXAemsManager::SetCurrentFullBankIndex

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXAemsManager__SetCurrentFullBankIndex(int param_1,int param_2)

{
  int in_EAX;
  
  *(int *)(in_EAX + 0x38) = param_1;
  *(int *)(in_EAX + 0x3c) = param_2;
  if (param_1 == 0xc) {
    DAT_00735684 = *(int *)(in_EAX + 0x5a0) + *(int *)(in_EAX + 0x40) + param_2 * 4;
    return;
  }
  if (param_1 == 0xd) {
    DAT_00735684 = *(int *)(in_EAX + 0x5a4) + *(int *)(in_EAX + 0x40) + param_2 * 5;
    return;
  }
  if (param_1 == 8) {
    DAT_00735684 = *(int *)(in_EAX + 0x590) + *(int *)(in_EAX + 0x40) + param_2 * 5;
    return;
  }
  if (param_1 == 7) {
    DAT_00735684 = *(int *)(in_EAX + 0x58c) + *(int *)(in_EAX + 0x40) + param_2 * 5;
    return;
  }
  DAT_00735684 = *(int *)(in_EAX + 0x570 + param_1 * 4) + param_2;
  return;
}


// ==== 0x522020 EAXAemsManager::LoadAemsBank

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4
EAXAemsManager__LoadAemsBank(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (DAT_006f1dd8 != 1) {
    return 0;
  }
  *(undefined4 *)(unaff_ESI + 0x40) = param_1;
  EAXAemsManager__SetCurrentFullBankIndex();
  EAXAemsManager__SetCurrentBankPath__bank_name_resolver_();
  if (*(int *)(unaff_ESI + 0x2c) != 0) {
    iVar2 = *(int *)(unaff_ESI + 0x200 + DAT_00735684 * 4);
    if (iVar2 != 0) {
      *(int *)(unaff_ESI + 0x200 + DAT_00735684 * 4) = iVar2 + 1;
      *(int *)(unaff_ESI + 0x5b0) = *(int *)(unaff_ESI + 0x5b0) + 1;
      return 0;
    }
    *(undefined4 *)(unaff_ESI + 0x200 + DAT_00735684 * 4) = 1;
    iVar2 = FUN_00594d90();
    if (-1 < iVar2) {
      param_4 = param_4 - *(int *)(unaff_ESI + 0x5b0);
      iVar1 = param_4 * 3 + -0x1b;
      DAT_00735694 = 1;
      (&DAT_0072ce50)[iVar1] = DAT_00735684;
      (&DAT_0072ce54)[iVar1] = 0;
      uVar3 = FUN_00565b60(iVar2,0,0,8);
      (&DAT_0072cfd8)[DAT_00735684] = uVar3;
      DAT_0073567c = 1;
      FUN_0058aba0(uVar3,*(int *)(unaff_ESI + 0x5b8) * 0x40 + 0x67c + unaff_ESI,0,iVar2,FUN_00521ab0
                   ,param_4);
      DAT_00735678 = DAT_00735678 + 1;
      *(int *)(unaff_ESI + 0x5b8) = *(int *)(unaff_ESI + 0x5b8) + 1;
      return 0;
    }
  }
  return 0xffffffff;
}


// ==== 0x522140 FUN_00522140

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


// ==== 0x522220 FUN_00522220

void FUN_00522220(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if (DAT_006f1dd8 == 1) {
    *(undefined4 *)(unaff_ESI + 0x40) = param_1;
    EAXAemsManager__SetCurrentFullBankIndex();
    iVar2 = DAT_00735684;
    iVar1 = *(int *)(unaff_ESI + 0x200 + DAT_00735684 * 4);
    if (iVar1 < 2) {
      *(undefined4 *)(unaff_ESI + 0x200 + DAT_00735684 * 4) = 0;
      if (0 < iVar1) {
        SNDAEMS_removemodulebank(*(undefined4 *)(DAT_0072cfd0 + 0x48 + iVar2 * 4));
        FUN_00522280();
        return;
      }
    }
    else {
      *(int *)(unaff_ESI + 0x200 + DAT_00735684 * 4) = iVar1 + -1;
    }
  }
  return;
}


// ==== 0x522280 FUN_00522280

void FUN_00522280(void)

{
  int iVar1;
  
  iVar1 = DAT_00735684;
  if ((&DAT_0072d190)[DAT_00735684] != 0) {
    if ((&DAT_0072d190)[DAT_00735684] == (&DAT_0072cfd8)[DAT_00735684]) {
      (&DAT_0072cfd8)[DAT_00735684] = 0;
    }
    FUN_00565ce0();
    iVar1 = DAT_00735684;
    (&DAT_0072d190)[DAT_00735684] = 0;
  }
  if ((&DAT_0072cfd8)[iVar1] != 0) {
    FUN_00565ce0();
    (&DAT_0072cfd8)[DAT_00735684] = 0;
  }
  return;
}


// ==== 0x5222e0 EAXAemsManager::GetCurrentBankHandle

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

undefined4 EAXAemsManager__GetCurrentBankHandle(void)

{
  int in_EAX;
  
  switch(DAT_00735698) {
  case 0:
    return *(undefined4 *)(in_EAX + 4);
  case 1:
    return *(undefined4 *)(in_EAX + 0xc);
  case 2:
    return *(undefined4 *)(in_EAX + 0x14);
  case 3:
    return *(undefined4 *)(in_EAX + 0x18);
  case 4:
    return *(undefined4 *)(in_EAX + 0x1c);
  case 5:
    return *(undefined4 *)(in_EAX + 0x20);
  case 6:
    return *(undefined4 *)(in_EAX + 0x24);
  default:
    return 0;
  }
}


// ==== 0x522330 EAXAemsManager::StartSlotBankLoad

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void EAXAemsManager__StartSlotBankLoad(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_0072cfd0;
  if (DAT_006f1dd8 == 1) {
    iVar3 = DAT_006f870c * 0x40 + 0xe7c + DAT_0072cfd0;
    DAT_006f8710 = 0;
    if ((*(char *)(DAT_006f870c * 0x40 + 0xe7c + DAT_0072cfd0) == 'N') || (iVar3 == 0)) {
      uVar2 = (&DAT_0072cfd8)[DAT_006f8708];
      iVar3 = 0;
    }
    else {
      uVar2 = (&DAT_0072cfd8)[DAT_006f8708];
      *(undefined4 *)(DAT_0072cfd0 + 0x28) = 0;
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
    uVar2 = SNDAEMS_addmodulebank(uVar2,iVar3,0,FUN_00522140);
    DAT_006f8710 = 1;
    *(undefined4 *)(DAT_0072cfd0 + 0x48 + DAT_006f8708 * 4) = uVar2;
  }
  return;
}


// ==== 0x5223d0 EAXMod::_scalar_deleting_destructor_

/* [canon] audio high (ghidra-canon) docs/re/sound.md */

undefined4 * __thiscall EAXMod___scalar_deleting_destructor_(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5223f0 FUN_005223f0

void __fastcall FUN_005223f0(undefined4 *param_1)

{
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  return;
}


// ==== 0x522400 FUN_00522400

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


// ==== 0x522440 EAXMod::Pause__guard_only:_SND_enter_leave_critical_

/* [canon] audio low (ghidra) docs/re/sound.md */

void EAXMod__Pause__guard_only__SND_enter_leave_critical_(int param_1)

{
  if ((DAT_006f1dd8 != 0) && (param_1 != 0)) {
    FUN_0064e520();
    SNDSYS_leavecritical();
  }
  return;
}


// ==== 0x522460 FUN_00522460

void FUN_00522460(int param_1)

{
  if ((DAT_006f1dd8 != 0) && (param_1 != 0)) {
    FUN_0064e520();
    SNDSYS_leavecritical();
  }
  return;
}


// ==== 0x522480 Csis_CreatePlayCommonSample

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall Csis_CreatePlayCommonSample(int param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x4b < in_EAX) {
    in_EAX = 0x4b;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0xffff < unaff_EBX) {
    unaff_EBX = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  iVar2 = Csis__Class__CreateInstance(&DAT_00744210,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_PlayCommonSample_006f8190);
    Csis__Class__CreateInstance(&DAT_00744210,piVar1);
  }
  return;
}


// ==== 0x522520 Csis_CreatePlayFrontEndSample

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall Csis_CreatePlayFrontEndSample(int param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x4b < in_EAX) {
    in_EAX = 0x4b;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0xffff < unaff_EBX) {
    unaff_EBX = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  iVar2 = Csis__Class__CreateInstance(&DAT_00744200,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_006f8198);
    Csis__Class__CreateInstance(&DAT_00744200,piVar1);
  }
  return;
}


// ==== 0x5225c0 EAXS_3DMixer::UpdateMasterVolume__virtual__base_

/* [canon] audio med (ghidra) docs/re/sound.md */

int __fastcall EAXS_3DMixer__UpdateMasterVolume__virtual__base_(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xbc);
  if (iVar2 != 0) {
    iVar1 = EAXSound__GetMasterVolume();
    iVar2 = iVar1 * **(int **)(iVar2 + 0x60) >> 0xf;
    *(int *)(param_1 + 0xa4) = iVar2;
    *(int *)(param_1 + 0xa8) = iVar2;
    return iVar2;
  }
  return 0;
}


// ==== 0x522600 FUN_00522600

undefined4 * FUN_00522600(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684b33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[3] = 0;
  param_1[4] = 0;
  local_4 = 0;
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  *puVar1 = &PTR_FUN_006bf3c4;
  local_4 = CONCAT31(local_4._1_3_,1);
  *param_1 = &PTR_FUN_006bf3f0;
  eh_vector_constructor_iterator(param_1 + 0xab,0x7c,6,FUN_00532600,NullUpdate_ret);
  local_14 = param_1 + 0x167;
  local_18 = param_1 + 0x165;
  puVar1 = param_1 + 199;
  puVar4 = param_1 + 0xa5;
  local_10 = 2;
  do {
    iVar5 = 0;
    do {
      *puVar4 = 0;
      puVar1[1] = 0;
      puVar1[-0x1c] = 0;
      *puVar1 = 0;
      puVar1[-1] = 0;
      iVar3 = 0;
      puVar2 = puVar1 + -0xf;
      do {
        puVar2[-6] = 0;
        *puVar2 = 0;
        puVar2[-0xc] = 0;
        *(undefined1 *)((int)puVar1 + iVar3 + -0x24) = 0;
        puVar2[8] = 0;
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < 6);
      *(undefined1 *)(puVar1 + 2) = 0;
      FUN_00532670(0x3f800000,0x3f800000,100,0);
      *(undefined4 *)(extraout_ECX + 0x74) = 0x3f800000;
      *(undefined1 *)((int)local_18 + iVar5) = 0;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
      puVar1 = puVar1 + 0x1f;
    } while (iVar5 < 3);
    *local_14 = 0xffffffff;
    local_14 = local_14 + 1;
    local_18 = (undefined4 *)((int)local_18 + 3);
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x522730 FUN_00522730

void * __thiscall FUN_00522730(void *param_1,byte param_2)

{
  EAXFrontEnd___EAXFrontEnd();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x522750 EAXFrontEnd::_EAXFrontEnd

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXFrontEnd___EAXFrontEnd(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684b0f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bf3f0;
  param_1[8] = &PTR_FUN_006bf3c4;
  local_4 = 1;
  eh_vector_destructor_iterator(param_1 + 0xab,0x7c,6,NullUpdate_ret);
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  ExceptionList = local_c;
  return;
}


// ==== 0x5227c0 FUN_005227c0

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


// ==== 0x522870 FUN_00522870

undefined4 __fastcall FUN_00522870(void *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *unaff_ESI;
  int iVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_00684ec1;
  local_c = ExceptionList;
  if (DAT_006f1dd8 == 0) {
    return 0xffffffff;
  }
  iVar6 = *(int *)(DAT_007356ac + 0x3a8c);
  ExceptionList = &local_c;
  (**(code **)(*(int *)((int)param_1 + 0x20) + 0x28))(0,0);
  puVar4 = puStack_4;
  iVar6 = *(int *)((int)param_1 + 0x70) * (iVar6 * 0x7fff >> 0xf) >> 0xf;
  PTR_s_CSISSOUND_006f8714 = s_SND__FE_FrontEnd_006bf464;
  if ((int)puStack_4 + 0x12 < 0x27) {
    puVar3 = (undefined4 *)FUN_005256f0(0x14);
    puStack_4 = puVar3;
    if (puVar4 == (undefined4 *)0x12) {
      local_c = (void *)0x0;
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar4 = puVar3 + 1;
        *puVar4 = 0x12;
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        else if (0x7fff < iVar6) {
          iVar6 = 0x7fff;
        }
        puVar3[2] = iVar6;
        puVar3[3] = 0x1000;
        puVar3[4] = 0;
        iVar6 = Csis__Class__CreateInstance(&DAT_00744208,puVar4,puVar3);
        if (iVar6 < 0) {
          Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_loop_006f81a0);
          Csis__Class__CreateInstance(&DAT_00744208,puVar4,puVar3);
          unaff_ESI[0xa4] = (int)puVar3;
          ExceptionList = param_1;
          return 0;
        }
      }
      unaff_ESI[0xa4] = (int)puVar3;
    }
    else {
      local_c = (void *)0x1;
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        if ((int)puVar4 < 0) {
          puVar4 = (undefined4 *)0x0;
        }
        else if (0x4b < (int)puVar4) {
          puVar4 = (undefined4 *)0x4b;
        }
        puVar1 = puVar3 + 1;
        *puVar1 = puVar4;
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        else if (0x7fff < iVar6) {
          iVar6 = 0x7fff;
        }
        puVar3[2] = iVar6;
        puVar3[3] = 0x1000;
        puVar3[4] = 0;
        iVar6 = Csis__Class__CreateInstance(&DAT_00744208,puVar1,puVar3);
        if (iVar6 < 0) {
          Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_loop_006f81a0);
          Csis__Class__CreateInstance(&DAT_00744208,puVar1,puVar3);
          unaff_ESI[0xa3] = (int)puVar3;
          ExceptionList = param_1;
          return 0;
        }
      }
      unaff_ESI[0xa3] = (int)puVar3;
    }
  }
  else {
    Csis__System__GetAllocator(&puStack_4);
    Mutex__Lock();
    piVar5 = (int *)(**(code **)*puStack_4)(0x14,4,0xffffffff);
    Mutex__Unlock();
    local_c = (void *)0x2;
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      if ((int)puVar4 < 0) {
        puVar4 = (undefined4 *)0x0;
      }
      else if (0x4b < (int)puVar4) {
        puVar4 = (undefined4 *)0x4b;
      }
      piVar2 = piVar5 + 1;
      *piVar2 = (int)puVar4;
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      else if (0x7fff < iVar6) {
        iVar6 = 0x7fff;
      }
      piVar5[2] = iVar6;
      piVar5[3] = 0x1000;
      piVar5[4] = 0;
      iVar6 = Csis__Class__CreateInstance(&DAT_00744200,piVar2,piVar5);
      if (iVar6 < 0) {
        Csis__ClassHandle__Set(&PTR_s_PlayFrontEndSample_006f8198);
        Csis__Class__CreateInstance(&DAT_00744200,piVar2,piVar5);
      }
    }
    local_c = (void *)0xffffffff;
    unaff_ESI[0xa2] = (int)piVar5;
    if (piVar5 != (int *)0x0) {
      if (*piVar5 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&stack0xffffffe4);
      Mutex__Lock();
      (**(code **)(*unaff_ESI + 4))(piVar5);
      Mutex__Unlock();
    }
    unaff_ESI[0xa2] = 0;
  }
  ExceptionList = param_1;
  return 0;
}


// ==== 0x522b40 FUN_00522b40

undefined4 __thiscall FUN_00522b40(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_00684e6b;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (param_2 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    (**(code **)(param_1[8] + 0x28))(0,0);
    PTR_s_CSISSOUND_006f8714 = s_SND__FE_FrontEnd_006bf464;
    Csis__System__GetAllocator(&puStack_4);
    Mutex__Lock();
    iVar1 = (**(code **)*puStack_4)(0x14,4,0xffffffff);
    Mutex__Unlock();
    puStack_4 = (undefined4 *)0x0;
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)Csis_CreatePlayFrontEndSample();
      param_1 = local_10;
    }
    puStack_4 = (undefined4 *)0xffffffff;
    param_1[0xa2] = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_10);
      Mutex__Lock();
      (**(code **)(*local_10 + 4))(piVar2);
      Mutex__Unlock();
    }
    param_1[0xa2] = 0;
  }
  ExceptionList = local_c;
  return 0xffffffff;
}


// ==== 0x522c60 FUN_00522c60

void __fastcall FUN_00522c60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iStack00000004;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  char *pcStack_4;
  
  iStack_c = param_1 + 0x594;
  pcVar5 = (char *)(param_1 + 0x324);
  iStack_10 = 0;
  piVar4 = (int *)(param_1 + 0x294);
  iStack00000004 = param_1;
  do {
    iVar3 = 0;
    do {
      pcStack_4 = pcVar5;
      FUN_005326f0(0x3e23d70a);
      if ((int *)*piVar4 != (int *)0x0) {
        iStack_8 = 0;
        if (*(int *)*piVar4 == 0) {
LAB_00522cf8:
          if ((*(char *)(iStack_c + iVar3) == '\0') || (*pcVar5 == '\0')) {
            iVar2 = (&DAT_006f4f5c)[iVar3];
            (**(code **)(*(int *)(iStack00000004 + 0x20) + 0x28))(0,0);
            iVar1 = DAT_007356a8;
            iStack_8 = *(int *)(iStack00000004 + 0x70) * iVar2 >> 0xf;
            iVar2 = _ftol_nocw();
            if (*(char *)(iVar1 + 0x84) == '\0') {
              if (iVar2 < 0) {
                iVar2 = 0;
              }
              else if (0x7fff < iVar2) {
                iVar2 = 0x7fff;
              }
              *(int *)(*piVar4 + 8) = iVar2;
              *(undefined4 *)(*piVar4 + 0xc) = 0x1000;
              *(undefined4 *)(*piVar4 + 0x10) = 0;
              if (*(int *)*piVar4 != 0) {
                FUN_0064bc30((int *)*piVar4 + 1);
              }
            }
            else {
              *(undefined4 *)(*piVar4 + 8) = 0;
              *(undefined4 *)(*piVar4 + 0xc) = 0;
              *(undefined4 *)(*piVar4 + 0x10) = 0;
              if (*(int *)*piVar4 != 0) {
                FUN_0064bc30((int *)*piVar4 + 1);
              }
            }
            goto LAB_00522db9;
          }
        }
        else {
          Csis__Class__GetRefCount(&iStack_8);
          if (iStack_8 != 1) goto LAB_00522cf8;
        }
        FUN_00522ff0(iStack00000004,iVar3,iStack_10);
      }
LAB_00522db9:
      iVar3 = iVar3 + 1;
      pcVar5 = pcStack_4 + 0x7c;
      piVar4 = piVar4 + 1;
    } while (iVar3 < 3);
    iStack_10 = iStack_10 + 1;
    iStack_c = iStack_c + 3;
    if (1 < iStack_10) {
      return;
    }
  } while( true );
}


// ==== 0x522c70 EAXFrontEnd::GetEventPointer

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

undefined * EAXFrontEnd__GetEventPointer(int param_1)

{
  if (param_1 < 0x17) {
    return &DAT_006f8550 + param_1 * 0x14;
  }
  return (undefined *)0x0;
}


// ==== 0x522e00 FUN_00522e00

undefined4 FUN_00522e00(void)

{
  int iVar1;
  
  iVar1 = FUN_00520320(DAT_007356a8);
  switch(*(undefined4 *)(&DAT_006f8100 + iVar1 * 4)) {
  case 0:
    return 3;
  case 1:
    return 9;
  default:
    return 0;
  case 3:
    return 6;
  }
}


// ==== 0x522e50 EAXFrontEnd::PlayDriveOnSnd

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXFrontEnd__PlayDriveOnSnd(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = param_3;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d6b;
  local_c = ExceptionList;
  if (0x52 < (int)param_2) {
    iVar1 = (int)param_2 + -0x53;
    iVar5 = param_3 + -1;
    ExceptionList = &local_c;
    iVar4 = FUN_00522e00(param_4);
    iVar4 = iVar4 + iVar1;
    if (iVar1 == 0) {
      PTR_s_CSISSOUND_006f8714 = s_SND__FE_DriveIdle_006bf450;
    }
    else if (iVar1 == 1) {
      PTR_s_CSISSOUND_006f8714 = s_SND__FE_DriveON_006bf440;
    }
    else if (iVar1 == 2) {
      PTR_s_CSISSOUND_006f8714 = s_SND__FE_DriveOff_006bf42c;
    }
    FUN_00522ff0(param_1,iVar1,iVar5);
    Csis__System__GetAllocator(&param_2);
    Mutex__Lock();
    iVar5 = (**(code **)*param_2)(0x14,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0x32 < iVar4) {
        iVar4 = 0x32;
      }
      piVar2 = (int *)(iVar5 + 4);
      *piVar2 = iVar4;
      *(undefined4 *)(iVar5 + 8) = 0;
      *(undefined4 *)(iVar5 + 0xc) = 0;
      *(undefined4 *)(iVar5 + 0x10) = 0;
      param_3 = iVar5;
      iVar4 = Csis__Class__CreateInstance(&DAT_007441f8,piVar2,iVar5);
      if (iVar4 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FEDriveOn_006f81a8);
        Csis__Class__CreateInstance(&DAT_007441f8,piVar2,iVar5);
      }
    }
    iVar4 = iVar3 + 0x36;
    *(int *)(param_1 + (iVar4 + iVar1 + iVar4 * 2) * 4) = iVar5;
    *(undefined1 *)(iVar1 + (iVar3 + 0x1db) * 3 + param_1) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x522f90 FUN_00522f90

void __fastcall FUN_00522f90(int param_1,int param_2)

{
  int in_EAX;
  
  if ((0x52 < param_2) && (*(int *)(param_1 + (param_2 + -0x53 + (in_EAX + 0x36) * 3) * 4) != 0)) {
    *(undefined1 *)(param_2 + -0x53 + (in_EAX + 0x1db) * 3 + param_1) = 1;
    FUN_00532640();
    FUN_00532670(0x3f800000,0,300,0);
    *(undefined4 *)((param_2 + -0x53 + (in_EAX + -1) * 3) * 0x7c + param_1 + 800) = 0x3f800000;
  }
  return;
}


// ==== 0x522ff0 FUN_00522ff0

void FUN_00522ff0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int unaff_retaddr;
  
  piVar3 = param_3;
  iVar1 = param_2 + ((int)param_3 + 0x37) * 3;
  piVar2 = *(int **)(param_1 + iVar1 * 4);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&param_3);
    Mutex__Lock();
    (**(code **)(*param_3 + 4))(piVar2);
    Mutex__Unlock();
    *(undefined4 *)(param_1 + iVar1 * 4) = 0;
    *(undefined1 *)(param_2 + (int)(piVar3 + 0x77) * 3 + unaff_retaddr) = 0;
  }
  return;
}


// ==== 0x523060 FUN_00523060

void FUN_00523060(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = 0;
    do {
      FUN_00522ff0(param_1,iVar1,iVar2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}


// ==== 0x523090 FUN_00523090

void * __thiscall FUN_00523090(void *param_1,byte param_2)

{
  EAXCommon___EAXCommon();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5230b0 EAXCommon::_EAXCommon

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXCommon___EAXCommon(undefined4 *param_1)

{
  param_1[8] = &PTR_FUN_006bf36c;
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  return;
}


// ==== 0x5230d0 FUN_005230d0

void __fastcall FUN_005230d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x20) + 0x10))(&DAT_006f43b0);
  iVar2 = *(int *)(param_1 + 0xdc);
  if (iVar2 != 0) {
    iVar1 = EAXSound__GetMasterVolume();
    iVar2 = iVar1 * **(int **)(iVar2 + 0x60) >> 0xf;
    *(int *)(param_1 + 0xc4) = iVar2;
    *(int *)(param_1 + 200) = iVar2;
  }
  return;
}


// ==== 0x523120 FUN_00523120

undefined4 __fastcall FUN_00523120(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *unaff_ESI;
  int iVar4;
  void *unaff_EDI;
  int *piStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (DAT_0073566c == 0)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*(int *)(param_1 + 0x20) + 0x28))(0,0);
    iVar4 = (*(int *)(param_1 + 0x70) * 0x7fff >> 0xf) * *(int *)(DAT_007356ac + 0x3a8c) >> 0xf;
    PTR_s_CSISSOUND_006f8714 = s_SND__FE_Common_006bf41c;
    Csis__System__GetAllocator(&stack0xffffffe4);
    Mutex__Lock();
    piVar2 = (int *)(**(code **)*unaff_ESI)(0x14,4,0xffffffff);
    Mutex__Unlock();
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      if ((int)piStack_10 < 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = piStack_10;
        if (0x4b < (int)piStack_10) {
          piVar3 = (int *)0x4b;
        }
      }
      piVar1 = piVar2 + 1;
      *piVar1 = (int)piVar3;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0x7fff < iVar4) {
        iVar4 = 0x7fff;
      }
      piVar2[2] = iVar4;
      piVar2[3] = 0x1000;
      piVar2[4] = 0;
      iVar4 = Csis__Class__CreateInstance(&DAT_00744210,piVar1,piVar2);
      if (iVar4 < 0) {
        Csis__ClassHandle__Set(&PTR_s_PlayCommonSample_006f8190);
        Csis__Class__CreateInstance(&DAT_00744210,piVar1,piVar2);
      }
    }
    *(int **)(param_1 + 0x24c) = piVar2;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_10);
      Mutex__Lock();
      (**(code **)(*piStack_10 + 4))(piVar2);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x24c) = 0;
    ExceptionList = unaff_EDI;
    return 0;
  }
  return 0xffffffff;
}


// ==== 0x5232b0 FUN_005232b0

undefined4 __thiscall FUN_005232b0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_00684e6b;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (param_2 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    (**(code **)(param_1[8] + 0x28))(0,0);
    PTR_s_CSISSOUND_006f8714 = s_SND__FE_Common_006bf41c;
    Csis__System__GetAllocator(&puStack_4);
    Mutex__Lock();
    iVar1 = (**(code **)*puStack_4)(0x14,4,0xffffffff);
    Mutex__Unlock();
    puStack_4 = (undefined4 *)0x0;
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)Csis_CreatePlayCommonSample();
      param_1 = local_10;
    }
    puStack_4 = (undefined4 *)0xffffffff;
    param_1[0x93] = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_10);
      Mutex__Lock();
      (**(code **)(*local_10 + 4))(piVar2);
      Mutex__Unlock();
    }
    param_1[0x93] = 0;
  }
  ExceptionList = local_c;
  return 0xffffffff;
}


// ==== 0x5233d0 EAXCommon::GetEventPointer

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

undefined * EAXCommon__GetEventPointer(int param_1)

{
  if (param_1 < 8) {
    return &DAT_006f84c0 + param_1 * 0x14;
  }
  return (undefined *)0x0;
}


// ==== 0x5233f0 FUN_005233f0

void FUN_005233f0(void)

{
  FUN_00522730();
  return;
}


// ==== 0x523400 FUN_00523400

void FUN_00523400(void)

{
  FUN_00523090();
  return;
}


// ==== 0x523410 FUN_00523410

undefined4 __fastcall FUN_00523410(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1efc);
}


// ==== 0x523420 FUN_00523420

void FUN_00523420(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00525c10(unaff_ESI);
  unaff_ESI[0x5d8] = 0;
  unaff_ESI[0x7ec] = 0;
  unaff_ESI[0x7ed] = 0;
  *(undefined1 *)(unaff_ESI + 0x7eb) = 0;
  unaff_ESI[0x7f1] = 0;
  *(undefined1 *)(unaff_ESI + 0x7f4) = 0;
  *unaff_ESI = &PTR_FUN_006bf2c0;
  unaff_ESI[8] = &PTR_FUN_006bf290;
  return;
}


// ==== 0x523460 FUN_00523460

void * __thiscall FUN_00523460(void *param_1,byte param_2)

{
  FUN_00523480();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x523480 FUN_00523480

void __fastcall FUN_00523480(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bf2c0;
  param_1[8] = &PTR_FUN_006bf290;
  FUN_00526190();
  return;
}


// ==== 0x5234a0 EAXAITunerCar::Destroy

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__Destroy(int param_1)

{
  EAXTunerCar__Destroy();
  if (*(undefined4 **)(param_1 + 0x1fa0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x1fa0))(1);
  }
  return;
}


// ==== 0x5234c0 EAXAITunerCar::Initialize

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXAITunerCar__Initialize(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  bool bVar2;
  float fVar3;
  
  EAXTunerCar__Initialize(param_2,param_3);
  bVar2 = DAT_007000e4 != 100.0;
  DAT_00735668 = (DAT_00735668 + 500) % 2000;
  *(int *)(param_1 + 0x1fd4) = DAT_00735668;
  fVar3 = DAT_007000e4;
  if (bVar2) {
    *(undefined4 *)(param_1 + 0x1f80) = 0x43200000;
    *(float *)(param_1 + 0x1f1c) = fVar3;
    return;
  }
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x3e0);
  *(undefined4 *)(param_1 + 0x1f80) = 0x43200000;
  *(undefined4 *)(param_1 + 0x1f1c) = uVar1;
  return;
}


// ==== 0x523540 EAXAITunerCar::HasFX

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined1 __thiscall EAXAITunerCar__HasFX(int param_1,int param_2)

{
  if (param_2 == 6) {
    return 0;
  }
  switch(param_2) {
  case 0:
  case 3:
  case 5:
    break;
  case 1:
    return *(undefined1 *)(param_1 + 0x12b0);
  case 2:
    return 1;
  case 4:
    if (-1 < *(int *)(param_1 + 0x1efc)) {
      return 1;
    }
  default:
    return 0;
  }
  if (1 < *(int *)(param_1 + 0x1efc)) {
    return 1;
  }
  return 0;
}


// ==== 0x523560 EAXAITunerCar::RotationUpdate

/* [canon] audio low (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__RotationUpdate(int param_1)

{
  *(int *)(param_1 + 0x2ac) = (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x3c);
  return;
}


// ==== 0x523580 EAXAITunerCar::UpdateMasterVolume

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall EAXAITunerCar__UpdateMasterVolume(int param_1)

{
  if (*(int *)(param_1 + 0x1f80) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x1f80) + 0x20) + 0x24))();
  }
  EAXTunerCar__UpdateMasterVolume();
  return;
}


// ==== 0x5235a0 EAXAITunerCar::UpdateEngineVol

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__UpdateEngineVol(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = param_1 + 0x8e;
  *piVar1 = (int)*(short *)(param_1[0x7c3] + 10);
  piVar2 = param_1 + 0x8f;
  *piVar2 = (int)*(short *)(param_1[0x7c3] + 0xc);
  if ((char)param_1[0x741] == '\0') {
    FUN_005326f0(param_1[0x91]);
    iVar4 = *piVar1;
    iVar3 = _ftol_nocw();
    iVar5 = *piVar2;
    *piVar1 = iVar3 + iVar4;
    iVar4 = _ftol_nocw();
    *piVar2 = iVar4 + iVar5;
  }
  iVar4 = param_1[0x639];
  if (iVar4 != 0) {
    *piVar2 = *piVar2 + iVar4;
    *piVar1 = *piVar1 + iVar4;
  }
  *piVar2 = (&DAT_006f7220)[param_1[0xab] / 2] * *piVar2 >> 0xf;
  iVar4 = (&DAT_006f7220)[(0x400 - param_1[0xab]) / 2] * *piVar1 >> 0xf;
  *piVar1 = iVar4;
  if (((float)param_1[0x637] != 0.0) && (0 < *piVar2 - iVar4)) {
    iVar5 = _ftol_nocw();
    *piVar1 = iVar5 + iVar4;
  }
  (**(code **)(*param_1 + 0x38))(piVar1,10);
  (**(code **)(*param_1 + 0x38))(piVar2,10);
  return;
}


// ==== 0x5236c0 EAXAITunerCar::SFXMessage__thunk_to_EAXTunerCar::SFXMessage_0x526af0_

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall
EAXAITunerCar__SFXMessage__thunk_to_EAXTunerCar__SFXMessage_0x526af0_
          (int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    iVar1 = param_1[0x746];
    param_1[0x747] = iVar1;
    iVar2 = *(int *)(param_1[0x8d] + 0x3d8);
    param_1[0x746] = iVar2;
    if (iVar1 < iVar2) {
      (**(code **)(*param_1 + 0x8c))();
      return 0;
    }
    (**(code **)(*param_1 + 0x90))();
  }
  else if (param_2 == 5) {
    EAXTunerCar__BottomOutPlay(param_3);
    return 0;
  }
  return 0;
}


// ==== 0x5236d0 FUN_005236d0

void __fastcall FUN_005236d0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1760) != 0) {
    iVar1 = *(int *)(param_1 + 0x238);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x24) = iVar1;
    iVar1 = *(int *)(param_1 + 0x23c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x28) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x14) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x18) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x1c) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x20) = iVar1;
    iVar1 = *(int *)(param_1 + 0x6c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x10000 < iVar1) {
      iVar1 = 0x10000;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x48) = iVar1;
    iVar1 = *(int *)(param_1 + 0x2ac);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x44) = iVar1;
    iVar1 = _ftol_nocw();
    iVar1 = iVar1 + -0x3fff + *(int *)(param_1 + 0x1fd4);
    if (iVar1 < -0x3fff) {
      iVar1 = -0x3fff;
    }
    else if (0x3fff < iVar1) {
      iVar1 = 0x3fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x4c) = iVar1;
    if (**(int **)(param_1 + 0x1760) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x1760) + 1);
    }
  }
  return;
}


// ==== 0x523890 EAXAITunerCar::InitializeSkids

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXAITunerCar__InitializeSkids(int param_1)

{
  void *pvVar1;
  int *piVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684e93;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x240);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)EAXSkids__EAXSkids(pvVar1);
  }
  pvVar1 = (void *)0x0;
  *(int **)(param_1 + 0x1fa0) = piVar2;
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 4))(param_1);
  (**(code **)(*(int *)(*(int *)(param_1 + 0x1fa0) + 0x20) + 0x10))(&DAT_006f4420);
  ExceptionList = pvVar1;
  return;
}


// ==== 0x523910 EAXAITunerCar::UpdateTireSounds__not_EAXTires_

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__UpdateTireSounds__not_EAXTires_(int param_1)

{
  if (*(int *)(param_1 + 0x1fa0) != 0) {
    FUN_0052db90();
    FUN_0052dc70();
    FUN_0052cf80();
    EAXTires__GenerateRoadNoise();
    EAXTires__GenerateSkidNoise();
    FUN_0052ce40();
    FUN_00527ca0(*(undefined4 *)(param_1 + 0x14a4),*(undefined4 *)(param_1 + 0x14a8),0,
                 *(undefined4 *)(param_1 + 0x12dc));
  }
  return;
}


// ==== 0x523990 EAXAITunerCar::BeginUpShift

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__BeginUpShift(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x1e50) = 0;
  *(undefined4 *)(param_1 + 0x1a3c) = 0;
  *(undefined4 *)(param_1 + 0x1a40) = 0;
  *(undefined4 *)(param_1 + 0x1d14) = 0;
  FUN_00584310(*(undefined4 *)(param_1 + 0x1f8c));
  uVar1 = *(undefined4 *)(param_1 + 0x1f8c);
  *(undefined4 *)(param_1 + 0x1d14) = 1;
  FUN_00532640();
  FUN_00532670(uVar1,0,0x32,0);
  *(undefined4 *)(param_1 + 0x1c84) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x1f1c);
  FUN_00532640();
  FUN_00532670(uVar1,uVar1,300,0);
  *(undefined4 *)(param_1 + 0x1c08) = uVar1;
  *(undefined4 *)(param_1 + 0x1d0c) = *(undefined4 *)(param_1 + 0x1f1c);
  FUN_00529100(param_1 + 0x1d24,1,0,0x1000,*(undefined4 *)(param_1 + 0x6c));
  return;
}


// ==== 0x523a70 EAXAITunerCar::BeginDownShift

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__BeginDownShift(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x1e50) = 0;
  *(undefined4 *)(param_1 + 0x1a3c) = 0;
  *(undefined4 *)(param_1 + 0x1a40) = 0;
  *(undefined4 *)(param_1 + 0x1d14) = 0;
  FUN_00584310(*(undefined4 *)(param_1 + 0x1f8c));
  uVar1 = *(undefined4 *)(param_1 + 0x1f8c);
  *(undefined4 *)(param_1 + 0x1d14) = 3;
  *(undefined4 *)(param_1 + 0x1d0c) = *(undefined4 *)(param_1 + 0x1f1c);
  FUN_00532640();
  FUN_00532670(uVar1,0,0x32,0);
  *(undefined4 *)(param_1 + 0x1c84) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x1f1c);
  FUN_00532640();
  FUN_00532670(uVar1,uVar1,300,0);
  *(undefined4 *)(param_1 + 0x1c08) = uVar1;
  return;
}


// ==== 0x523b30 EAXAITunerCar::UpdateTorque

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXAITunerCar__UpdateTorque(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 0x1d14)) {
  case 1:
  case 3:
    FUN_005326f0(param_2);
    uVar2 = *(undefined4 *)(param_1 + 0x1c84);
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1c44 + *(int *)(param_1 + 0x1c80) * 4) =
         *(undefined4 *)(param_1 + 0x1f90);
    FUN_005326f0(param_2);
    uVar2 = *(undefined4 *)(param_1 + 0x1c84);
    break;
  case 4:
  case 5:
    FUN_005326f0(param_2);
    *(undefined4 *)(param_1 + 0x1f88) = *(undefined4 *)(param_1 + 0x1c84);
    FUN_00584310(*(undefined4 *)(param_1 + 0x1c84));
    goto LAB_00523be3;
  default:
    if (*(char *)(param_1 + 0x1f10) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x42c80000;
    }
    piVar1 = (int *)FUN_00584270(uVar2);
    (**(code **)(*piVar1 + 4))();
    uVar2 = *(undefined4 *)(param_1 + 0x1f34);
  }
  *(undefined4 *)(param_1 + 0x1f88) = uVar2;
LAB_00523be3:
  FUN_00584270(*(float *)(param_1 + 0x1f90) - *(float *)(param_1 + 0x1f34));
  *(undefined4 *)(param_1 + 0x1f8c) = *(undefined4 *)(param_1 + 0x1f88);
  return;
}


// ==== 0x523c30 EAXAITunerCar::UpdateEngineInputs

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall EAXAITunerCar__UpdateEngineInputs(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(param_1 + 0x1f90) = *(undefined4 *)(iVar1 + 0x3ec);
  piVar4 = DAT_0073619c;
  fVar3 = *(float *)(*(int *)(iVar1 + 0x30) + 0x1dc) * 100.0;
  *(float *)(param_1 + 0x1f78) = fVar3;
  iVar2 = *piVar4;
  if ((iVar2 == 2) || (iVar2 == 3)) {
    if (*(float *)(param_1 + 0x1f8c) <= 30.0) {
LAB_00523ce6:
      *(undefined1 *)(param_1 + 0x1f10) = 0;
      *(undefined4 *)(param_1 + 0x1f14) = *(undefined4 *)(param_1 + 0x240);
      goto LAB_00523d6a;
    }
  }
  else {
    if (iVar2 == 4) {
      if ((_K_HALF <= *(float *)(*(int *)(iVar1 + 0x30) + 0x1e4)) ||
         (_K_HALF <= *(float *)(*(int *)(iVar1 + 0x30) + 0x1e0))) {
LAB_00523cab:
        fVar3 = *(float *)(param_1 + 0x1fa8) - *(float *)(param_1 + 0x244);
        *(undefined4 *)(param_1 + 0x1fa4) = 0x3f000000;
        *(float *)(param_1 + 0x1fa8) = fVar3;
        if ((*(char *)(param_1 + 0x1f10) == '\0') || (0.0 <= fVar3)) goto LAB_00523d6a;
        goto LAB_00523ce6;
      }
    }
    else if (fVar3 <= 30.0) goto LAB_00523cab;
    fVar3 = *(float *)(param_1 + 0x1fa4) - *(float *)(param_1 + 0x244);
    *(undefined4 *)(param_1 + 0x1fa8) = 0x3f000000;
    *(float *)(param_1 + 0x1fa4) = fVar3;
    if ((*(char *)(param_1 + 0x1f10) != '\0') || (0.0 <= fVar3)) goto LAB_00523d6a;
  }
  *(undefined1 *)(param_1 + 0x1f10) = 1;
  *(undefined4 *)(param_1 + 0x1f18) = *(undefined4 *)(param_1 + 0x240);
LAB_00523d6a:
  if (*(float *)(param_1 + 0x1f90) <= *(float *)(param_1 + 0x1f80)) {
    if (*(float *)(param_1 + 0x1f90) < 0.0) {
      *(undefined4 *)(param_1 + 0x1f90) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1f90) = *(undefined4 *)(param_1 + 0x1f80);
  }
  *(float *)(param_1 + 0x1f90) =
       (*(float *)(param_1 + 0x1f90) / *(float *)(param_1 + 0x1f80)) * 100.0;
  fVar3 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar3 = *(float *)(iVar1 + 0x3e0);
  }
  *(float *)(param_1 + 0x1f20) = (fVar3 / *(float *)(param_1 + 0x1f24)) * 10000.0;
  if (*(char *)(param_1 + 0x12b0) != '\0') {
    if (*(char *)(param_1 + 0x1f10) != '\0') {
      *(undefined4 *)(param_1 + 0x1278) = 0x3fb0a3d7;
      return;
    }
    *(undefined4 *)(param_1 + 0x1278) = 0;
  }
  return;
}


// ==== 0x523e20 EAXAITunerCar::UpdateRPM

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

void EAXAITunerCar__UpdateRPM(void)

{
  EAXTunerCar__UpdateRPM();
  return;
}


// ==== 0x523e30 EAXAITunerCar::UpdateGearShiftState__map_names_are_swapped_with_0x529530_

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall
EAXAITunerCar__UpdateGearShiftState__map_names_are_swapped_with_0x529530_(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined4 uVar4;
  
  if ((*(float *)(param_1 + 0x1d50) < *(float *)(param_1 + 0x240)) &&
     (*(char *)(param_1 + 0x1d48) != '\0')) {
    FUN_00529100(param_1 + 0x1d24,*(undefined4 *)(param_1 + 0x1d4c),0,0x1000,
                 *(undefined4 *)(param_1 + 0x6c));
    *(undefined1 *)(param_1 + 0x1d48) = 0;
  }
  switch(*(undefined4 *)(param_1 + 0x1d14)) {
  case 1:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 2;
      FUN_00532610((float)(int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x18) +
                   *(float *)(param_1 + 0x1f20),*(undefined4 *)(param_1 + 0x1f20),
                   (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x1a));
      FUN_00532610(*(undefined4 *)(param_1 + 0x1f8c),*(undefined4 *)(param_1 + 0x1f90),10);
      FUN_00532610(*(undefined4 *)(*(int *)(param_1 + 0x1f0c) + 0x20),0,
                   (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x1c));
      FUN_00529970();
      cVar1 = EAXTunerCar__ShouldUpShiftDynLd();
      if (cVar1 != '\0') {
        FUN_0052a0a0();
      }
      EAXShifting__PlayEngageSnd(param_1 + 0x1d24);
      return;
    }
    break;
  case 2:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 0;
      FUN_00584310(*(undefined4 *)(param_1 + 0x1c84));
      return;
    }
    break;
  case 3:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 4;
      FUN_00532640();
      FUN_00532670(*(undefined4 *)(param_1 + 0x1f1c),
                   (float)(int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x2c) +
                   *(float *)(param_1 + 0x1f20),(int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x2e),3
                  );
      FUN_00532610(*(undefined4 *)(param_1 + 0x1f8c),DAT_006f80f4,DAT_006f80f8);
      cVar1 = FUN_00529f80();
      if (cVar1 != '\0') {
        FUN_0052a2c0();
        return;
      }
    }
    break;
  case 4:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 5;
      FUN_00532640();
      FUN_00532670(*(undefined4 *)(param_1 + 0x1f1c),
                   *(float *)(param_1 + 0x1f1c) -
                   (float)(int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x30),
                   (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x32),2);
      FUN_00532610(DAT_006f80f4,0,DAT_006f80f8);
      return;
    }
    break;
  case 5:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 6;
      fVar3 = (float10)FUN_00532640();
      uVar4 = 0;
      bClampF((float)ABS(fVar3),0,0x44480000,0);
      uVar2 = _ftol_nocw();
      FUN_00532670(*(undefined4 *)(param_1 + 0x1f1c),*(undefined4 *)(param_1 + 0x1f20),uVar2,uVar4);
      FUN_00584310(*(undefined4 *)(param_1 + 0x1f90));
      return;
    }
    break;
  case 6:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      EAXTunerCar__CleanUpShiftFX();
    }
  }
  return;
}


// ==== 0x524130 EAXAITunerCar::UpdateTurboFX

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXAITunerCar__UpdateTurboFX(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 unaff_retaddr;
  
  if (((param_1[0x49d] != 0) && (cVar2 = (**(code **)(*param_1 + 0x60))(1), cVar2 != '\0')) &&
     (*(char *)(param_1[0x49d] + 0xc) != '\0')) {
    EAXTurbo__UpdateBlowOff(unaff_retaddr);
    EAXTurbo__UpdateSpool(unaff_retaddr);
    iVar1 = param_1[0x4a9];
    if (iVar1 == 0) {
      if (_DAT_006f80ec < (float)param_1[0x7e3]) {
        param_1[0x4a9] = 1;
      }
    }
    else if (iVar1 == 1) {
      if ((float)param_1[0x7e3] < _DAT_006f80ec) {
        param_1[0x4a9] = 2;
        EAXTurbo__PlayBlowoff(param_1[0x49d],0,0,0xfff,param_1[0x1b],param_1[0xab]);
        *(undefined4 *)(param_1[0x49d] + 0x2c0) = 0;
        EAXTurbo__UpdateSpool(unaff_retaddr);
        return;
      }
    }
    else if ((iVar1 == 2) && (cVar2 = EAXTurbo__IsBlowOffDone(), cVar2 != '\0')) {
      param_1[0x4a9] = 0;
      return;
    }
  }
  return;
}


// ==== 0x524143 FUN_00524143

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524143(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int unaff_ESI;
  
  cVar2 = (**(code **)(in_EAX + 0x60))(1);
  if ((cVar2 != '\0') && (*(char *)(*(int *)(unaff_ESI + 0x1274) + 0xc) != '\0')) {
    EAXTurbo__UpdateBlowOff(param_1);
    EAXTurbo__UpdateSpool(param_1);
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
        EAXTurbo__UpdateSpool(param_1);
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


// ==== 0x524145 FUN_00524145

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524145(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int unaff_ESI;
  
  cVar2 = (**(code **)(in_EAX + 0x60))();
  if ((cVar2 != '\0') && (*(char *)(*(int *)(unaff_ESI + 0x1274) + 0xc) != '\0')) {
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


// ==== 0x524148 FUN_00524148

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


// ==== 0x524200 FUN_00524200

void FUN_00524200(void)

{
  undefined4 unaff_EDI;
  
  EAXTurbo__UpdateSpool(unaff_EDI);
  return;
}


// ==== 0x524240 EAXAITunerCar::UpdateNIS

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXAITunerCar__UpdateNIS(float param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float *pfVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST1;
  
  if (*DAT_0073619c != 2) {
    if (*DAT_0073619c != 3) {
      return;
    }
    fVar9 = (float10)Countdown__GetSecondsRemaining();
    if (fVar9 <= (float10)_DAT_006f81d0) {
      fVar9 = (float10)Countdown__GetSecondsRemaining();
      if ((float10)_DAT_006f81d0 <= fVar9) {
        return;
      }
      if (*(char *)(unaff_EDI + 0x1fd0) != '\0') {
        return;
      }
      fVar9 = (float10)FUN_00524740(*(undefined4 *)(unaff_EDI + 0x1fc8),
                                    *(undefined4 *)(unaff_EDI + 0x1f20),0x43960000,0x43960000);
      *(float *)(unaff_EDI + 0x1fc8) = (float)fVar9;
      fVar10 = (float10)FUN_00524740(*(undefined4 *)(unaff_EDI + 0x1fcc),
                                     *(undefined4 *)(unaff_EDI + 0x1f90),0x41200000,0x41200000);
      *(float *)(unaff_EDI + 0x1fcc) = (float)fVar10;
      *(float *)(unaff_EDI + 0x1f8c) = (float)fVar10;
      *(float *)(unaff_EDI + 0x1f1c) = (float)fVar9;
      if (400.0 <= ABS((float)fVar9 - *(float *)(unaff_EDI + 0x1f20))) {
        return;
      }
      *(undefined1 *)(unaff_EDI + 0x1fd0) = 1;
      return;
    }
  }
  fVar4 = param_1 + *(float *)(unaff_EDI + 0x1fc4);
  *(float *)(unaff_EDI + 0x1fc4) = fVar4;
  if (*(char *)(unaff_EDI + 0x1fac) == '\0') {
    param_1 = *(float *)(unaff_EDI + 0x1fb0) - param_1;
    *(float *)(unaff_EDI + 0x1fb0) = param_1;
    if (param_1 < 0.0) {
      *(undefined1 *)(unaff_EDI + 0x1fac) = 1;
      *(undefined4 *)(unaff_EDI + 0x1fb4) = 0;
      uVar5 = DAT_006f227c & 1;
      uVar6 = DAT_006f227c ^ 0x1d872b41;
      uVar7 = uVar6 >> 5 ^ uVar6;
      DAT_006f227c = uVar7 << 0x1b ^ uVar7 ^ uVar6;
      *(undefined4 *)(unaff_EDI + 0x1fc0) = 1;
      *(undefined4 **)(unaff_EDI + 0x1fb8) = &DAT_006f81d8 + uVar5 * 0x5d;
      *(undefined4 **)(unaff_EDI + 0x1fbc) = &DAT_006f81e4 + uVar5 * 0x5d;
      uVar1 = (&DAT_006f81dc)[uVar5 * 0x5d];
      uVar2 = (&DAT_006f81e0)[uVar5 * 0x5d];
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      *(undefined4 *)(unaff_EDI + 0x1fc8) = uVar1;
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      *(undefined4 *)(unaff_EDI + 0x1fcc) = uVar2;
    }
  }
  else {
    pfVar3 = *(float **)(unaff_EDI + 0x1fbc);
    param_1 = param_1 + *(float *)(unaff_EDI + 0x1fb4);
    *(float *)(unaff_EDI + 0x1fb4) = param_1;
    if (*pfVar3 < param_1) {
      iVar8 = *(int *)(unaff_EDI + 0x1fc0) + 1;
      *(float **)(unaff_EDI + 0x1fb8) = pfVar3;
      *(int *)(unaff_EDI + 0x1fc0) = iVar8;
      *(float **)(unaff_EDI + 0x1fbc) = pfVar3 + 3;
      if (0x1e < iVar8) {
        bClampF(fVar4 / 2.1,0x3f800000,0x40400000);
        fVar9 = (float10)Random_NextFloat(0x3fa66666);
        *(undefined1 *)(unaff_EDI + 0x1fac) = 0;
        *(float *)(unaff_EDI + 0x1fb0) = (float)(fVar9 / extraout_ST1 + (float10)0.5);
      }
    }
    if (*(char *)(unaff_EDI + 0x1fac) != '\0') {
      uVar1 = *(undefined4 *)(*(int *)(unaff_EDI + 0x1fb8) + 4);
      uVar2 = *(undefined4 *)(*(int *)(unaff_EDI + 0x1fb8) + 8);
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      *(undefined4 *)(unaff_EDI + 0x1fc8) = uVar1;
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      *(undefined4 *)(unaff_EDI + 0x1fcc) = uVar2;
    }
  }
  *(undefined4 *)(unaff_EDI + 0x1f1c) = *(undefined4 *)(unaff_EDI + 0x1fc8);
  *(undefined4 *)(unaff_EDI + 0x1f8c) = *(undefined4 *)(unaff_EDI + 0x1fcc);
  return;
}


// ==== 0x524620 EAXAITunerCar::Update

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXAITunerCar__Update(int *param_1,float param_2)

{
  if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
    param_1[0x91] = (int)param_2;
    param_1[0x90] = (int)(param_2 + (float)param_1[0x90]);
  }
  else {
    param_1[0x91] = 0;
  }
  (**(code **)(*param_1 + 100))(param_2);
  (**(code **)(*param_1 + 0x68))(param_2);
  EAXAITunerCar__UpdateNIS(param_2);
  (**(code **)(param_1[8] + 0x28))(param_1[0x8d] + 0x60,param_1[0x8d] + 0x90);
  (**(code **)(*param_1 + 0x9c))();
  (**(code **)(*param_1 + 0x98))(param_2);
  (**(code **)(*param_1 + 0x70))();
  FUN_0052db90();
  FUN_0052dc70();
  FUN_0052cf80();
  EAXTires__GenerateRoadNoise();
  EAXTires__GenerateSkidNoise();
  FUN_0052ce40();
  (**(code **)(*param_1 + 0x9c))();
  (**(code **)(*param_1 + 0x88))(param_2);
  EAXTunerCar__UpdateNitrous(param_2);
  (**(code **)(*param_1 + 0x74))(param_2);
  (**(code **)(*param_1 + 0x7c))(param_2);
  EAXNitrous__Update();
  (**(code **)(*param_1 + 0x80))(param_2);
  if (DAT_006f1dd8 == 1) {
    (**(code **)(*param_1 + 0x84))();
  }
  return;
}


// ==== 0x524740 FUN_00524740

float10 FUN_00524740(float param_1,float param_2,float param_3,float param_4)

{
  float10 fVar1;
  
  fVar1 = (float10)param_1 + (float10)param_3;
  if (((float10)param_2 <= fVar1) &&
     (fVar1 = (float10)param_1 - (float10)param_4, fVar1 <= (float10)param_2)) {
    fVar1 = (float10)param_2;
  }
  return fVar1;
}


// ==== 0x524780 FUN_00524780

void FUN_00524780(void)

{
  FUN_00523460();
  return;
}


// ==== 0x524790 Csis_CreateRoadNoiseSample

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall Csis_CreateRoadNoiseSample(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0xf < in_EAX) {
    in_EAX = 0xf;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EDI < 0) {
    unaff_EDI = 0;
  }
  else if (0xffff < unaff_EDI) {
    unaff_EDI = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EDI;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (2 < param_3) {
    param_3 = 2;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0x7f < param_4) {
    param_4 = 0x7f;
  }
  *(int *)(unaff_ESI + 0x18) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_00744230,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_FX_ROADNOISE_006f81b8);
    Csis__Class__CreateInstance(&DAT_00744230,piVar1);
  }
  return;
}


// ==== 0x524870 Csis_CreateEnvStaticSample

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void __fastcall Csis_CreateEnvStaticSample(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x32 < in_EAX) {
    in_EAX = 0x32;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fa0 < param_2) {
    param_2 = 0x1fa0;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (2 < param_4) {
    param_4 = 2;
  }
  *(int *)(unaff_ESI + 0x14) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_00744220,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
    Csis__Class__CreateInstance(&DAT_00744220,piVar1);
  }
  return;
}


// ==== 0x524930 EAXTrafficCar::SFXMessage__default_stub__returns_0_

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 EAXTrafficCar__SFXMessage__default_stub__returns_0_(void)

{
  return 0;
}


// ==== 0x524940 FUN_00524940

undefined4 FUN_00524940(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x16:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x1e:
  case 0x1f:
  case 0x20:
    return 1;
  default:
    return 0;
  }
}


// ==== 0x524970 FUN_00524970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524970(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  unaff_ESI[0x8d] = 0;
  *(undefined1 *)(unaff_ESI + 0x92) = 0;
  unaff_ESI[0x8c] = 0;
  unaff_ESI[0x90] = 0;
  unaff_ESI[0x91] = 0;
  *unaff_ESI = &PTR_FUN_006bf150;
  *puVar1 = &PTR_FUN_006bf124;
  FUN_00532640();
  DAT_0078eae8 = DAT_0078eae8 + 1 & 0x80000001;
  *(undefined1 *)(unaff_ESI + 0xbc) = 1;
  if ((int)DAT_0078eae8 < 0) {
    DAT_0078eae8 = (DAT_0078eae8 - 1 | 0xfffffffe) + 1;
  }
  *(undefined1 *)((int)unaff_ESI + 0x31e) = 1;
  unaff_ESI[200] = 0;
  unaff_ESI[0xc9] = 0;
  unaff_ESI[0xc0] = 0;
  unaff_ESI[0xc1] = 0;
  unaff_ESI[0xc5] = 0;
  unaff_ESI[0xc3] = 0;
  *(undefined1 *)(unaff_ESI + 199) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x31d) = 0;
  *(undefined1 *)(unaff_ESI + 0xbd) = 0;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  unaff_ESI[0xbb] = 0x3f800000;
  unaff_ESI[0xbe] = 0;
  unaff_ESI[0xbf] = 0;
  _DAT_0073565c = 0;
  return;
}


// ==== 0x524a50 FUN_00524a50

void * __thiscall FUN_00524a50(void *param_1,byte param_2)

{
  FUN_00524a70(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x524a70 FUN_00524a70

void __thiscall FUN_00524a70(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ac8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_2 = &PTR_FUN_006bf150;
  param_2[8] = &PTR_FUN_006bf124;
  piVar1 = (int *)param_2[0xc0];
  local_4 = 0;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    (**(code **)(*local_10 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_2[0xc1];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    (**(code **)(*local_10 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_2[0xc9];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    (**(code **)(*local_10 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_2[0xc9] = 0;
  param_2[8] = &PTR_FUN_006be7d8;
  param_2[8] = &PTR_FUN_006be7c4;
  *param_2 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x524b80 FUN_00524b80

void __thiscall FUN_00524b80(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 0x234) = param_2;
    *(undefined4 *)(param_1 + 0x264) = param_3;
    *(undefined4 *)(param_1 + 0x230) = 0;
  }
  return;
}


// ==== 0x524bb0 EAXTrafficCar::IsPlayerCarInRange

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined2 EAXTrafficCar__IsPlayerCarInRange(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int in_EAX;
  int iVar8;
  float10 fVar9;
  float local_30;
  float local_20;
  float local_1c;
  
  iVar3 = *(int *)(in_EAX + 0x234);
  iVar8 = EAX_NearestListenerToPoint();
  fVar1 = *(float *)(iVar3 + 100);
  fVar2 = *(float *)(iVar3 + 0x68);
  fVar4 = *(float *)(iVar8 + 0x60) - *(float *)(iVar3 + 0x60);
  fVar5 = *(float *)(iVar8 + 100) - fVar1;
  fVar6 = *(float *)(iVar8 + 0x68) - fVar2;
  if (30.0 < SQRT(fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5)) {
    return 0;
  }
  bNormalize3();
  bNormalize3();
  cVar7 = DAT_0078a344;
  iVar3 = DAT_007361a8;
  fVar1 = fVar2 * fVar2 + local_20 * local_30 + local_1c * fVar1;
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    fVar9 = (float10)FUN_00564b10();
    if ((float10)fVar1 < fVar9) {
      return 0;
    }
  }
  else {
    fVar9 = (float10)FUN_00564b10();
    if ((float10)fVar1 < fVar9) {
      return 0;
    }
  }
  bNormalize3();
  if ((cVar7 == '\0') && (iVar3 == 0)) {
    fVar9 = (float10)FUN_00564b10();
    if (fVar9 < (float10)(fVar2 * fVar2 + local_20 * local_20 + local_1c * local_1c)) {
      return 0;
    }
  }
  return 1;
}


// ==== 0x524da0 FUN_00524da0

int FUN_00524da0(float param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *unaff_EBX;
  int *piVar6;
  
  iVar5 = 0;
  if (0 < *(int *)(DAT_0073619c + 0x24)) {
    piVar6 = (int *)(DAT_007361f8 + 0x28);
    do {
      iVar1 = *piVar6;
      if (((iVar1 != 0) && (*(int *)(*(int *)(iVar1 + 0x14) + 4) == 1)) &&
         (*(char *)(*(int *)(iVar1 + 0x14) + 0x734) == '\0')) {
        fVar2 = *(float *)(iVar1 + 0x60) - *unaff_EBX;
        fVar3 = *(float *)(iVar1 + 100) - unaff_EBX[1];
        fVar4 = *(float *)(iVar1 + 0x68) - unaff_EBX[2];
        if (SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4) < param_1) {
          return iVar1;
        }
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar5 < *(int *)(DAT_0073619c + 0x24));
  }
  return 0;
}


// ==== 0x524e40 FUN_00524e40

uint FUN_00524e40(float param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = DAT_0073619c;
  if (0 < *(int *)(DAT_0073619c + 0x24)) {
    piVar2 = (int *)(DAT_007361f8 + 0x28);
    do {
      uVar1 = *(uint *)(*piVar2 + 0x14);
      if ((*(int *)(uVar1 + 4) == 1) && (*(char *)(uVar1 + 0x734) == '\0')) {
        if (param_1 < *(float *)(*piVar2 + 0x3d0)) {
          return 1;
        }
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < *(int *)(DAT_0073619c + 0x24));
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x524ea0 FUN_00524ea0

void __fastcall FUN_00524ea0(int param_1)

{
  if ((*(char *)(param_1 + 0x31c) != '\0') && (*(char *)(param_1 + 0x2f4) == '\0')) {
    *(undefined1 *)(param_1 + 0x2f4) = 1;
    FUN_00532640();
    FUN_00532670(0x3f800000,0,0x96,0);
    *(undefined4 *)(param_1 + 0x2ec) = 0x3f800000;
  }
  return;
}


// ==== 0x524ef0 FUN_00524ef0

void FUN_00524ef0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x2f4) = 1;
  FUN_00532640();
  FUN_00532670(0x3f800000,0,0x96,0);
  *(undefined4 *)(in_EAX + 0x2ec) = 0x3f800000;
  return;
}


// ==== 0x524f30 FUN_00524f30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524f30(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *unaff_EBP;
  int unaff_EDI;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar4 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684e6b;
  pvStack_c = ExceptionList;
  piVar2 = *(int **)(unaff_EDI + 0x300);
  ExceptionList = &pvStack_c;
  if (piVar2 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    if (*piVar2 != 0) {
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&param_1);
    Mutex__Lock();
    (**(code **)(*param_1 + 4))(piVar2);
    Mutex__Unlock();
  }
  *(undefined4 *)(unaff_EDI + 0x300) = 0;
  Csis__System__GetAllocator(&local_10);
  Mutex__Lock();
  iVar3 = (**(code **)*local_10)(0x18,4,0xffffffff);
  Mutex__Unlock();
  local_10 = (undefined4 *)0x0;
  pcStack_8 = (code *)iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    if ((int)piVar4 < 0) {
      piVar4 = (int *)0x0;
    }
    else if (0x32 < (int)piVar4) {
      piVar4 = (int *)0x32;
    }
    puVar1 = (undefined4 *)(iVar3 + 4);
    *puVar1 = piVar4;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0x1000;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    iVar5 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
    if (iVar5 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
    }
  }
  _DAT_0073565c = *(undefined4 *)(unaff_EDI + 0x240);
  *(int *)(unaff_EDI + 0x300) = iVar3;
  *(undefined4 *)(unaff_EDI + 0x310) = _DAT_0073565c;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  *(undefined4 *)(unaff_EDI + 0x2ec) = 0x3f800000;
  *(undefined1 *)(unaff_EDI + 0x2f4) = 0;
  ExceptionList = unaff_EBP;
  return;
}


// ==== 0x525080 FUN_00525080

void FUN_00525080(void)

{
  int *piVar1;
  int unaff_ESI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_ESI + 0x300);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  *(undefined4 *)(unaff_ESI + 0x300) = 0;
  *(undefined1 *)(unaff_ESI + 0x31c) = 0;
  *(undefined1 *)(unaff_ESI + 0x31d) = 0;
  *(undefined1 *)(unaff_ESI + 0x2f4) = 0;
  *(undefined4 *)(unaff_ESI + 0x314) = *(undefined4 *)(unaff_ESI + 0x240);
  return;
}


// ==== 0x5250f0 FUN_005250f0

/* WARNING: Removing unreachable block (ram,0x0052517e) */
/* WARNING: Removing unreachable block (ram,0x00525173) */

void FUN_005250f0(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 local_4;
  
  iVar1 = in_EAX[0x1b];
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
  *(int *)(in_EAX[0xc0] + 0x10) = iVar1;
  iVar1 = _ftol_nocw();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x1fa0 < iVar1) {
    iVar1 = 0x1fa0;
  }
  *(int *)(in_EAX[0xc0] + 0xc) = iVar1;
  local_4 = _ftol_nocw();
  (**(code **)(*in_EAX + 0x38))(&local_4);
  *(undefined4 *)(in_EAX[0xc0] + 8) = 9;
  if (*(int *)in_EAX[0xc0] != 0) {
    FUN_0064bc30((int *)in_EAX[0xc0] + 1);
  }
  return;
}


// ==== 0x5251a0 FUN_005251a0

void __thiscall FUN_005251a0(int param_1,int *param_2)

{
  *param_2 = *(int *)(param_1 + 0x70) * *param_2 >> 0xf;
  FUN_00536c20(DAT_007356ac);
  return;
}


// ==== 0x5251d0 EAXTrafficCar::IsHonking

/* [canon] audio med (ghidra) docs/re/sound.md */

bool __fastcall EAXTrafficCar__IsHonking(int param_1)

{
  return *(int *)(param_1 + 0x300) != 0;
}


// ==== 0x5251e0 EAXTrafficCar::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXTrafficCar__Update(int param_1,float param_2)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
    *(float *)(param_1 + 0x244) = param_2;
    *(float *)(param_1 + 0x240) = param_2 + *(float *)(param_1 + 0x240);
  }
  else {
    *(undefined4 *)(param_1 + 0x244) = 0;
  }
  if (DAT_006f1dd8 != 0) {
    (**(code **)(*(int *)(param_1 + 0x20) + 0x28))
              (*(int *)(param_1 + 0x234) + 0x60,*(int *)(param_1 + 0x234) + 0x90);
    EAXTrafficCar__UpdateDriveBy(param_2);
    FUN_005326f0(param_2);
    if (*(int *)(param_1 + 0x300) == 0) {
      if (((*(float *)(param_1 + 0x314) + 3.0 < *(float *)(param_1 + 0x240)) &&
          (*(float *)(param_1 + 800) + 3.0 < *(float *)(param_1 + 0x240))) &&
         (*(char *)(param_1 + 0x31e) != '\0')) {
        cVar1 = FUN_00524e40(0x41c80000);
        if (cVar1 != '\0') {
          cVar1 = EAXTrafficCar__IsPlayerCarInRange();
          if (cVar1 != '\0') {
            fVar3 = (float10)FUN_00564a80(0x3f800000);
            if ((fVar3 < (float10)0.3) || (_DAT_0073565c + 5.0 < *(float *)(param_1 + 0x240))) {
              iVar2 = EAX_NearestListenerToPoint();
              *(int *)(param_1 + 0x2f8) = iVar2;
              if ((iVar2 != 0) && (*(int *)(iVar2 + 0x878) != 0)) {
                *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(*(int *)(iVar2 + 0x878) + 0x264);
              }
              cVar1 = FUN_00524940();
              if (cVar1 == '\0') {
                iVar2 = RandomInt(2);
                iVar2 = iVar2 + 5;
              }
              else {
                iVar2 = 7;
              }
              FUN_00524f30(iVar2);
              *(undefined1 *)(param_1 + 0x31d) = 1;
              fVar3 = (float10)FUN_00564a80(0x40333333);
              *(float *)(param_1 + 0x308) = (float)(fVar3 + (float10)1.2);
            }
            else {
              *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x240);
            }
          }
        }
      }
    }
    else if ((((*(float *)(param_1 + 0x240) <
                *(float *)(param_1 + 0x310) + *(float *)(param_1 + 0x308)) &&
              (*(char *)(param_1 + 0x31d) != '\0')) || (*(char *)(param_1 + 0x31c) != '\0')) ||
            (*(char *)(param_1 + 0x2f4) != '\0')) {
      FUN_005250f0();
    }
    else {
      FUN_00524ef0();
    }
    if ((*(char *)(param_1 + 0x2f4) != '\0') && (*(char *)(param_1 + 0x2f0) != '\0')) {
      FUN_00525080();
    }
  }
  return;
}


// ==== 0x525410 EAXTrafficCar::GetPlayerSpeedRelativeToUs

/* [canon] audio high (ghidra) docs/re/sound.md */

float10 EAXTrafficCar__GetPlayerSpeedRelativeToUs(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  iVar1 = *(int *)(in_EAX + 0x234);
  iVar2 = EAX_NearestListenerToPoint();
  if (iVar2 == 0) {
    return (float10)0.0;
  }
  fVar3 = (float10)*(float *)(iVar2 + 0x70) - (float10)*(float *)(iVar1 + 0x70);
  fVar4 = (float10)*(float *)(iVar2 + 0x74) - (float10)*(float *)(iVar1 + 0x74);
  return SQRT(fVar4 * fVar4 + fVar3 * fVar3);
}


// ==== 0x525480 EAXTrafficCar::UpdateDriveBy

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTrafficCar__UpdateDriveBy(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  undefined4 uVar5;
  int *local_14;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  piVar3 = (int *)param_1[0xc1];
  ExceptionList = &local_c;
  fVar4 = (float10)EAXTrafficCar__GetPlayerSpeedRelativeToUs();
  if (piVar3 == (int *)0x0) {
    local_14 = (int *)(float)fVar4;
    iVar1 = FUN_00524da0(0x40a00000);
    if (((iVar1 != 0) && ((float10)25.0 < fVar4)) &&
       ((float)param_1[0xc3] + 3.0 < (float)param_1[0x90])) {
      bClampF(((float)local_14 - 25.0) / 75.0,0,0x3f800000);
      _ftol_nocw();
      iVar1 = DAT_006f4f04;
      local_14 = (int *)(DAT_006f4f00 - DAT_006f4f04);
      piVar3 = param_1 + 0xc6;
      iVar2 = _ftol_nocw();
      *piVar3 = iVar2 + iVar1;
      (**(code **)(*param_1 + 0x38))(piVar3,9);
      *piVar3 = *(int *)(DAT_007356ac + 0x3e1c) * *piVar3 >> 0xf;
      RandomInt(3);
      iVar1 = FUN_005256f0(0x18);
      iVar2 = 0;
      local_c = (void *)0x0;
      if (iVar1 != 0) {
        iVar1 = param_1[0x1b];
        uVar5 = 0;
        RandomInt(3,iVar1,0);
        iVar2 = Csis_CreateEnvStaticSample(iVar1,uVar5);
      }
      param_1[0xc1] = iVar2;
      param_1[0xc3] = param_1[0x90];
      ExceptionList = local_14;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (fVar4 <= (float10)25.0) {
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    local_10 = local_14;
  }
  else {
    local_14 = (int *)0x0;
    if ((*piVar3 == 0) || (Csis__Class__GetRefCount(&local_14), local_14 != (int *)0x1)) {
      if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
        ExceptionList = local_c;
        return;
      }
      *(undefined4 *)(param_1[0xc1] + 8) = 0;
      if (*(int *)param_1[0xc1] == 0) {
        ExceptionList = local_c;
        return;
      }
      FUN_0064bc30((int *)param_1[0xc1] + 1);
      ExceptionList = local_c;
      return;
    }
    piVar3 = (int *)param_1[0xc1];
    if (piVar3 == (int *)0x0) goto LAB_00525679;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
  }
  (**(code **)(*local_10 + 4))(piVar3);
  Mutex__Unlock();
LAB_00525679:
  param_1[0xc1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x5256e0 FUN_005256e0

void FUN_005256e0(void)

{
  FUN_00524a50();
  return;
}


// ==== 0x5256f0 FUN_005256f0

undefined4 FUN_005256f0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *local_4;
  
  Csis__System__GetAllocator(&local_4);
  Mutex__Lock();
  uVar1 = (**(code **)*local_4)(param_1,4,0xffffffff);
  Mutex__Unlock();
  return uVar1;
}


// ==== 0x525730 FUN_00525730

void __fastcall FUN_00525730(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (2 < in_EAX) {
    in_EAX = 2;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (1 < param_4) {
    param_4 = 1;
  }
  *(int *)(unaff_ESI + 0x14) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d7fc,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_FX_NITROUS_01_006f2238);
    Csis__Class__CreateInstance(&DAT_0073d7fc,piVar1);
  }
  return;
}


// ==== 0x5257f0 FUN_005257f0

void __fastcall FUN_005257f0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (2 < in_EAX) {
    in_EAX = 2;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EDI < 0) {
    unaff_EDI = 0;
  }
  else if (0xffff < unaff_EDI) {
    unaff_EDI = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EDI;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (2 < param_3) {
    param_3 = 2;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (1 < param_4) {
    param_4 = 1;
  }
  *(int *)(unaff_ESI + 0x18) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d804,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_FX_SHIFTING_01_006f2240);
    Csis__Class__CreateInstance(&DAT_0073d804,piVar1);
  }
  return;
}


// ==== 0x5258d0 FUN_005258d0

void __fastcall
FUN_005258d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (9 < in_EAX) {
    in_EAX = 9;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x1fff < param_2) {
    param_2 = 0x1fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EDI < 0) {
    unaff_EDI = 0;
  }
  else if (0xffff < unaff_EDI) {
    unaff_EDI = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EDI;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x400 < param_3) {
    param_3 = 0x400;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (10000 < param_4) {
    param_4 = 10000;
  }
  *(int *)(unaff_ESI + 0x18) = param_4;
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (0xfa < param_5) {
    param_5 = 0xfa;
  }
  *(int *)(unaff_ESI + 0x1c) = param_5;
  if (param_6 < 0) {
    param_6 = 0;
  }
  else if (1 < param_6) {
    param_6 = 1;
  }
  *(int *)(unaff_ESI + 0x20) = param_6;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d80c,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_FX_SPARKCHATTER_006f2248);
    Csis__Class__CreateInstance(&DAT_0073d80c,piVar1);
  }
  return;
}


// ==== 0x5259e0 FUN_005259e0

void __fastcall FUN_005259e0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x7fff < in_EAX) {
    in_EAX = 0x7fff;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (9000 < param_1) {
    param_1 = 9000;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x32 < param_3) {
    param_3 = 0x32;
  }
  *(int *)(unaff_ESI + 0x10) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0x7f < param_4) {
    param_4 = 0x7f;
  }
  *(int *)(unaff_ESI + 0x14) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_007441d8,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_IMPACT_WORLD_006f8170);
    Csis__Class__CreateInstance(&DAT_007441d8,piVar1);
  }
  return;
}


// ==== 0x525aa0 FUN_00525aa0

void __fastcall FUN_00525aa0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (5 < in_EAX) {
    in_EAX = 5;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x7fff < param_1) {
    param_1 = 0x7fff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x2000 < param_2) {
    param_2 = 0x2000;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EDI < 0) {
    unaff_EDI = 0;
  }
  else if (0xffff < unaff_EDI) {
    unaff_EDI = 0xffff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EDI;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x400 < param_3) {
    param_3 = 0x400;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (10000 < param_4) {
    param_4 = 10000;
  }
  *(int *)(unaff_ESI + 0x18) = param_4;
  iVar2 = Csis__Class__CreateInstance(&DAT_00744218,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_FX_TURBO_01_006f81b0);
    Csis__Class__CreateInstance(&DAT_00744218,piVar1);
  }
  return;
}


// ==== 0x525b80 FUN_00525b80

void FUN_00525b80(void)

{
  undefined4 *in_EAX;
  
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[10] = 0;
  in_EAX[9] = 0;
  in_EAX[2] = 0;
  *in_EAX = 0;
  in_EAX[1] = 0;
  return;
}


// ==== 0x525bb0 FUN_00525bb0

void __fastcall FUN_00525bb0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bef4c;
  return;
}


// ==== 0x525bc0 FUN_00525bc0

undefined4 * __thiscall FUN_00525bc0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006bef4c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x525be0 FUN_00525be0

void __fastcall FUN_00525be0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bee78;
  return;
}


// ==== 0x525bf0 FUN_00525bf0

undefined4 * __thiscall FUN_00525bf0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006bee78;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x525c10 FUN_00525c10

undefined4 * FUN_00525c10(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int extraout_EDX_05;
  int extraout_EDX_06;
  int extraout_EDX_07;
  int extraout_EDX_08;
  int extraout_EDX_09;
  int extraout_EDX_10;
  int extraout_EDX_11;
  int extraout_EDX_12;
  int extraout_EDX_13;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685804;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[3] = 0;
  param_1[4] = 0;
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  param_1[0x8d] = 0;
  *(undefined1 *)(param_1 + 0x92) = 0;
  param_1[0x8c] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  *puVar1 = &PTR_FUN_006bee80;
  *param_1 = &PTR_FUN_006beeb0;
  local_4 = 0;
  param_1[0xb4] = &PTR_FUN_006be3c0;
  eh_vector_constructor_iterator(param_1 + 0xf4,0x220,2,FUN_00535520,EAXS_3DMixer___EAXS_3DMixer);
  param_1[0xb9] = 0;
  *(undefined1 *)(param_1 + 0xb8) = 0;
  param_1[0xf1] = 0;
  local_4._0_1_ = 1;
  FUN_00534a20();
  param_1[0x204] = &PTR_FUN_006be3b0;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00534a20();
  param_1[0x328] = &PTR_FUN_006be310;
  *(undefined1 *)(param_1 + 0x452) = 0;
  param_1[0x453] = 0;
  param_1[0x450] = 0;
  param_1[0x451] = 0;
  param_1[0x44f] = &PTR_FUN_006befbc;
  param_1[0x454] = 0;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x478) = 0;
  param_1[0x479] = 0;
  param_1[0x476] = 0;
  param_1[0x477] = 0;
  param_1[0x475] = &PTR_FUN_006bee70;
  param_1[0x47a] = 0;
  param_1[0x47b] = 0;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_00 + 0x78) = 1;
  param_1[0x4a3] = param_1 + 0x4a4;
  *(undefined1 *)(param_1 + 0x4a0) = 4;
  *(undefined1 *)((int)param_1 + 0x1281) = 3;
  *(undefined1 *)((int)param_1 + 0x1282) = 0;
  *(undefined1 *)((int)param_1 + 0x1283) = 0;
  param_1[0x49f] = &PTR_FUN_006b9694;
  param_1[0x4a1] = 0;
  param_1[0x4a2] = 0;
  param_1[0x4a4] = 0;
  param_1[0x4a5] = 0;
  param_1[0x4a6] = 0;
  FUN_0052c990();
  FUN_0052a5e0();
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_01 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_02 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_03 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_04 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_05 + 0x78) = 1;
  param_1[0x67d] = &PTR_FUN_006bef4c;
  puVar1 = param_1 + 0x67f;
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1 = puVar1 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 0x696) = 4;
  *(undefined1 *)((int)param_1 + 0x1a59) = 3;
  *(undefined1 *)((int)param_1 + 0x1a5a) = 0;
  *(undefined1 *)((int)param_1 + 0x1a5b) = 0;
  param_1[0x695] = &PTR_FUN_006b9694;
  param_1[0x697] = 0;
  param_1[0x698] = 0;
  param_1[0x699] = param_1 + 0x69a;
  param_1[0x69a] = 0;
  param_1[0x69b] = 0;
  param_1[0x69c] = 0;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_06 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_07 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_08 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_09 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_10 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x74c) = 0;
  param_1[0x74d] = 0;
  param_1[0x74a] = 0;
  param_1[0x74b] = 0;
  param_1[0x749] = &PTR_EAXShifting___scalar_deleting_destructor__006bee64;
  param_1[0x74e] = 0;
  param_1[0x74f] = 0;
  param_1[0x750] = 0;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_11 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_12 + 0x78) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX_13 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x7cb) = 4;
  *(undefined1 *)((int)param_1 + 0x1f2d) = 10;
  *(undefined1 *)((int)param_1 + 0x1f2e) = 0;
  *(undefined1 *)((int)param_1 + 0x1f2f) = 0;
  param_1[0x7ca] = &PTR_FUN_006b9694;
  param_1[0x7cc] = 0;
  param_1[0x7cd] = 0;
  param_1[0x7ce] = param_1 + 1999;
  puVar1 = _malloc(0x28);
  param_1[0x7ce] = puVar1;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  param_1[0x7d8] = param_1 + 0x7d9;
  *(undefined1 *)(param_1 + 0x7d5) = 4;
  *(undefined1 *)((int)param_1 + 0x1f55) = 5;
  *(undefined1 *)((int)param_1 + 0x1f56) = 0;
  *(undefined1 *)((int)param_1 + 0x1f57) = 0;
  param_1[0x7d4] = &PTR_FUN_006b9694;
  param_1[0x7d6] = 0;
  param_1[0x7d7] = 0;
  param_1[0x7d9] = 0;
  param_1[0x7da] = 0;
  param_1[0x7db] = 0;
  param_1[0x7dc] = 0;
  param_1[0x7dd] = 0;
  FUN_00584310(0);
  FUN_00584310(0);
  FUN_00584310(0);
  param_1[0x44d] = 0;
  param_1[0x745] = 0;
  param_1[0x4a9] = 0;
  param_1[0x794] = 0;
  param_1[0x63a] = 0;
  param_1[0x638] = 0;
  param_1[0x639] = 0;
  param_1[0x637] = 0;
  param_1[0x795] = 0;
  param_1[0x796] = 0;
  param_1[0x797] = 0;
  param_1[0x798] = 0;
  param_1[0x799] = 0;
  param_1[0x79a] = 0;
  param_1[0x79b] = 0;
  param_1[0x79c] = 0;
  param_1[0x79d] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x63c] = 0;
  param_1[0x744] = 0;
  *(undefined1 *)(param_1 + 0x752) = 0;
  param_1[0x753] = 1;
  param_1[0x754] = 0;
  param_1[0x742] = 0;
  *(undefined1 *)(param_1 + 0x7c4) = 0;
  *(undefined1 *)(param_1 + 0x63d) = 0;
  param_1[0x67c] = 0;
  param_1[0xad] = 0;
  param_1[0x7c2] = 0;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  param_1[0x472] = 0x3f800000;
  FUN_00532640();
  FUN_00532670(0,0,1,0);
  param_1[0x49b] = 0;
  param_1[0x5d8] = 0;
  param_1[0x5d9] = 0;
  param_1[0xab] = 0;
  param_1[0x5d6] = 0;
  param_1[0x5d7] = 0;
  param_1[0x49d] = 0;
  param_1[0x68f] = 0;
  param_1[0x690] = 0;
  param_1[0x691] = 0;
  param_1[0x692] = 0;
  param_1[0x693] = 0;
  param_1[0x694] = 0;
  *(undefined1 *)(param_1 + 0x6a1) = 0;
  param_1[0x6e3] = 0;
  FUN_00584310(0);
  *(undefined1 *)(param_1 + 0x6a3) = 0;
  param_1[0x6e4] = 0;
  *(undefined1 *)(param_1 + 0x6e2) = 0;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  param_1[0x6e0] = 0x3f800000;
  param_1[0x6a2] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb2] = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  param_1[0x5d4] = 0;
  *(undefined1 *)(param_1 + 0xaa) = 0;
  param_1[0xa9] = 0;
  *(undefined1 *)(param_1 + 0xa8) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x526170 FUN_00526170

void * __thiscall FUN_00526170(void *param_1,byte param_2)

{
  FUN_00526190();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x526190 FUN_00526190

void __fastcall FUN_00526190(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_006857d4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006beeb0;
  param_1[8] = &PTR_FUN_006bee80;
  local_4 = 10;
  param_1[0x7d4] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x7d8] != param_1 + 0x7d9) {
    _free((undefined4 *)param_1[0x7d8]);
  }
  param_1[0x7d4] = &PTR_FUN_006c7d78;
  param_1[0x7ca] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x7ce] != param_1 + 1999) {
    _free((undefined4 *)param_1[0x7ce]);
  }
  param_1[0x7ca] = &PTR_FUN_006c7d78;
  EAXShifting___EAXShifting();
  param_1[0x695] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x699] != param_1 + 0x69a) {
    _free((undefined4 *)param_1[0x699]);
  }
  param_1[0x695] = &PTR_FUN_006c7d78;
  param_1[0x67d] = &PTR_FUN_006bef4c;
  local_4 = CONCAT31(local_4._1_3_,7);
  FUN_0052a650();
  FUN_0052cbd0();
  param_1[0x49f] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x4a3] != param_1 + 0x4a4) {
    _free((undefined4 *)param_1[0x4a3]);
  }
  param_1[0x49f] = &PTR_FUN_006c7d78;
  local_4._0_1_ = 4;
  FUN_005276c0();
  local_4._0_1_ = 3;
  FUN_00527270();
  local_4._0_1_ = 2;
  param_1[0x328] = &PTR_FUN_006be310;
  FUN_00534ab0();
  local_4._0_1_ = 1;
  param_1[0x204] = &PTR_FUN_006be3b0;
  FUN_00534ab0();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00535530();
  param_1[8] = &PTR_FUN_006be7d8;
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  ExceptionList = local_c;
  return;
}


// ==== 0x526320 EAXTunerCar::ProcessSoundSphere

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall
EAXTunerCar__ProcessSoundSphere
          (int param_1,undefined4 param_2,int param_3,undefined4 *param_4,float param_5)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  
  if (*DAT_0073619c == 4) {
    *(undefined4 *)(param_1 + 0x260) = 0x416028f6;
    uVar2 = param_4[1];
    uVar3 = param_4[2];
    *(undefined4 *)(param_1 + 0x250) = *param_4;
    *(undefined4 *)(param_1 + 0x254) = uVar2;
    *(undefined4 *)(param_1 + 600) = uVar3;
    iVar5 = *(int *)(param_1 + 0x234);
    if (iVar5 != 0) {
      pcVar8 = "INTERSECTION";
      iVar6 = -1;
      uVar4 = 0x49;
      do {
        iVar6 = iVar6 * 0x21 + uVar4;
        pbVar1 = (byte *)(pcVar8 + 1);
        uVar4 = (uint)*pbVar1;
        pcVar8 = pcVar8 + 1;
      } while (*pbVar1 != 0);
      if (param_3 == iVar6) {
        if (((13.99 < param_5) &&
            (iVar5 = (**(code **)(**(int **)(iVar5 + 0x2c) + 0x18))(0), iVar5 != 0)) &&
           (iVar5 != -0xc)) {
          EAXS_WindNoise__SetupSoundSphere(*(undefined4 *)(*(int *)(param_1 + 0x234) + 0x3d4));
          return;
        }
      }
      else {
        iVar6 = bStringHash();
        if (param_3 == iVar6) {
          piVar7 = (int *)(param_1 + 0x810);
        }
        else {
          iVar6 = bStringHash();
          if (param_3 != iVar6) {
            return;
          }
          piVar7 = (int *)(param_1 + 0xca0);
        }
        (**(code **)(*piVar7 + 8))
                  (param_4,*(undefined4 *)(iVar5 + 0x3d4),*(undefined4 *)(param_1 + 0x1ef8));
      }
    }
  }
  return;
}


// ==== 0x526420 EAXTunerCar::Initialize

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXTunerCar__Initialize(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int *piVar7;
  int extraout_ECX;
  int iVar8;
  int **ppiVar9;
  float10 fVar10;
  undefined8 uVar11;
  int *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00685343;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 != 0) {
    ExceptionList = &local_c;
    param_1[0x8d] = param_2;
    param_1[0x99] = param_3;
    param_1[0x8c] = 0;
  }
  uVar11 = FUN_00520320(DAT_007356a8);
  iVar8 = (int)((ulonglong)uVar11 >> 0x20);
  param_1[0x7bd] = *(int *)(&DAT_006f8100 + (int)uVar11 * 4);
  if (DAT_00734658 == 0) {
    param_1[0x7bf] = *(int *)(iVar8 + 0x20);
  }
  else {
    param_1[0x7bf] = 3;
  }
  iVar4 = *(int *)(param_2 + 0xc);
  param_1[0x7c2] = iVar4 + 0x9c0;
  iVar1 = param_1[0x7bf];
  param_1[0x7c3] = iVar1 * 100 + 0x9c0 + iVar4;
  iVar4 = *(int *)(extraout_ECX + 0x68);
  iVar2 = *(int *)(extraout_ECX + 0x6c);
  if ((((iVar4 != 0) && (iVar2 != 0)) &&
      ((*(int *)(iVar4 + 8) != param_1[0x7bd] || (*(int *)(iVar4 + 4) != iVar1)))) &&
     ((*(int *)(iVar2 + 8) != param_1[0x7bd] || (*(int *)(iVar2 + 4) != iVar1)))) {
    if (DAT_0078eae4 == '\0') {
      param_1[0x7bd] = *(int *)(iVar4 + 8);
      iVar4 = *(int *)(iVar4 + 4);
    }
    else {
      param_1[0x7bd] = *(int *)(iVar2 + 8);
      iVar4 = *(int *)(iVar2 + 4);
    }
    DAT_0078eae4 = DAT_0078eae4 == '\0';
    param_1[0x7bf] = iVar4;
  }
  param_1[0x7c0] = *(int *)(iVar8 + 0x28);
  iVar4 = param_1[0x7bf] + -2;
  param_1[0x7c1] = *(int *)(iVar8 + 0x24);
  param_1[0x755] = iVar4;
  if (iVar4 < 1) {
    iVar8 = 0;
  }
  else {
    iVar8 = iVar4;
    if (1 < iVar4) {
      iVar8 = 1;
    }
  }
  param_1[0x755] = iVar8;
  param_1[0x474] = iVar4;
  if (iVar4 < 1) {
    iVar4 = 0;
  }
  else if (1 < iVar4) {
    iVar4 = 1;
  }
  param_1[0x474] = iVar4;
  puVar5 = _malloc(0x28);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar5 + 1) = 4;
    *(undefined1 *)((int)puVar5 + 5) = 5;
    *(undefined1 *)((int)puVar5 + 6) = 0;
    *(undefined1 *)((int)puVar5 + 7) = 0;
    *puVar5 = &PTR_FUN_006b9694;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = puVar5 + 5;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    puVar5[8] = 0;
    puVar5[9] = 0;
  }
  param_1[0x67c] = (int)puVar5;
  FUN_00584310(0);
  param_1[0x9c] = 0x454e4000;
  param_1[0x9d] = 0x454e4000;
  param_1[0x9e] = 0x454e4000;
  param_1[0x9f] = 0x45516000;
  param_1[0xa0] = 0x45548000;
  param_1[0xa1] = 0x4557a000;
  param_1[0xa2] = 0x455ac000;
  param_1[0xa3] = 0x455de000;
  param_1[0xa4] = 0x45610000;
  fVar10 = (float10)Float9_Max_Off10();
  param_1[0x7e0] = (int)(float)fVar10;
  iVar8 = *(int *)(param_2 + 0x10);
  if (*(char *)(iVar8 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  param_1[0x7c9] = *(int *)(iVar8 + 600);
  param_1[0x49e] = 0;
  param_1[0x747] = *(int *)(param_1[0x8d] + 0x3d8);
  param_1[0x746] = *(int *)(param_1[0x8d] + 0x3d8);
  param_1[0x68e] = 0;
  param_1[0x67e] = (int)param_1;
  EAXTires__CreateTires();
  iVar8 = DAT_007356a8;
  if (DAT_006f1dd8 == 1) {
    local_14 = param_1[0x7bf];
    local_18 = param_1[0x99];
    local_10 = param_1[0x7bd];
    local_1c = 0;
    local_1b = 0;
    local_20 = param_1;
    ppiVar9 = &local_20;
    puVar5 = (undefined4 *)(DAT_007356a8 + 0xc + param_1[0x99] * 0x14);
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *ppiVar9;
      ppiVar9 = ppiVar9 + 1;
      puVar5 = puVar5 + 1;
    }
    *(int *)(iVar8 + 0x60) = *(int *)(iVar8 + 0x60) + 1;
    (**(code **)(*param_1 + 0x78))();
    param_1[0x49d] = 0;
    if (*(char *)(*(int *)(param_1[0x8d] + 0x10) + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    fVar10 = (float10)Float9_Max_Off34();
    *(bool *)(param_1 + 0x4ac) = (float10)0.0 < fVar10;
    if ((float10)0.0 < fVar10) {
      pvVar6 = _malloc(0x350);
      uStack_4 = 0;
      if (pvVar6 == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_005281f0(pvVar6);
      }
      param_1[0x49d] = (int)piVar7;
      uStack_4 = 0xffffffff;
      (**(code **)(*piVar7 + 4))(param_1,param_1[0x7c1]);
      fVar10 = (float10)Float9_Max_Off34();
      param_1[0x4ab] = (int)(float)(fVar10 * (float10)4.0);
    }
    if (*(int *)(*(int *)(param_1[0x8d] + 0x14) + 4) != 2) {
      FUN_005355d0(param_1 + 0xb4,param_1);
      (**(code **)(param_1[0x204] + 4))(param_1);
      (**(code **)(param_1[0x328] + 4))(param_1);
      (**(code **)(param_1[0x540] + 4))(param_1,0);
    }
    (**(code **)(param_1[0x475] + 4))(param_1,param_1[0x7bf]);
    cVar3 = (**(code **)(*param_1 + 0x60))(2);
    if (cVar3 == '\0') {
      *(undefined1 *)(param_1 + 0x478) = 0;
    }
    (**(code **)(param_1[0x44f] + 4))(param_1,param_1[0x7bf]);
    cVar3 = (**(code **)(*param_1 + 0x60))(0);
    if (cVar3 == '\0') {
      *(undefined1 *)(param_1 + 0x452) = 0;
    }
    (**(code **)(param_1[0x749] + 4))(param_1,param_1[0x7bf]);
    cVar3 = (**(code **)(*param_1 + 0x60))(6);
    if (cVar3 == '\0') {
      *(undefined1 *)(param_1 + 0x74c) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x526880 EAXTunerCar::Destroy

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__Destroy(int *param_1)

{
  int *piVar1;
  int *local_4;
  
  piVar1 = (int *)param_1[0x5d8];
  local_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0x5d9];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  if ((undefined4 *)param_1[0x5d6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x5d6])(1);
  }
  if ((undefined4 *)param_1[0x5d7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x5d7])(1);
  }
  if ((undefined4 *)param_1[0x49d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x49d])(1);
  }
  if ((undefined4 *)param_1[0x67c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x67c])(1);
  }
  EAXTunerCar__DestroyReflection();
  piVar1 = (int *)param_1[0x6e4];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x6e4] = 0;
  }
  piVar1 = (int *)param_1[0xae];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0xaf];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0x5d4];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    return;
  }
  return;
}


// ==== 0x526a30 EAXTunerCar::Start

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio low (ghidra) docs/re/sound.md */

void EAXTunerCar__Start(void)

{
  _DAT_00735644 = _DAT_00735644 + 1;
  return;
}


// ==== 0x526a40 EAXTunerCar::HasFX

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined1 __thiscall EAXTunerCar__HasFX(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
  case 3:
  case 5:
    break;
  case 1:
    return *(undefined1 *)(param_1 + 0x12b0);
  case 2:
  case 6:
    return 1;
  case 4:
    if (-1 < *(int *)(param_1 + 0x1efc)) {
      return 1;
    }
  default:
    return 0;
  }
  if (1 < *(int *)(param_1 + 0x1efc)) {
    return 1;
  }
  return 0;
}


// ==== 0x526aa0 FUN_00526aa0

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


// ==== 0x526af0 EAXTunerCar::SFXMessage

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall EAXTunerCar__SFXMessage(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    iVar1 = param_1[0x746];
    param_1[0x747] = iVar1;
    iVar2 = *(int *)(param_1[0x8d] + 0x3d8);
    param_1[0x746] = iVar2;
    if (iVar1 < iVar2) {
      (**(code **)(*param_1 + 0x8c))();
      return 0;
    }
    (**(code **)(*param_1 + 0x90))();
  }
  else if (param_2 == 5) {
    EAXTunerCar__BottomOutPlay(param_3);
    return 0;
  }
  return 0;
}


// ==== 0x526b50 EAXTunerCar::LandJumpPlay

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__LandJumpPlay(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 *local_18 [2];
  int iStack_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    local_18[0] = DAT_006f4ed0;
    ExceptionList = &local_c;
    (**(code **)(*unaff_EDI + 0x38))(local_18,10);
    uVar2 = DAT_006f227c ^ 0x1d872b41;
    uVar5 = uVar2 >> 5 ^ uVar2;
    DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar2;
    piVar1 = (int *)unaff_EDI[0xaf];
    PTR_s_CSISSOUND_006f8714 = s_Jump_Landing_006bf0ec;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&stack0xffffffe4);
      Mutex__Lock();
      (**(code **)(*unaff_ESI + 4))(piVar1);
      Mutex__Unlock();
    }
    unaff_EDI[0xaf] = 0;
    Csis__System__GetAllocator(local_18);
    Mutex__Lock();
    iVar3 = (**(code **)*local_18[0])(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iStack_10 = iVar3;
      uVar4 = _ftol_nocw();
      iVar3 = FUN_005259e0(0xc,uVar4);
    }
    unaff_EDI[0xaf] = iVar3;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x526c70 EAXTunerCar::BottomOutPlay

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__BottomOutPlay(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *unaff_EDI;
  undefined4 *local_18;
  int *local_14;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  piVar1 = (int *)unaff_EDI[0xae];
  ExceptionList = &pvStack_c;
  if (piVar1 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    if (*piVar1 != 0) {
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  if (DAT_006f1dd8 != 0) {
    local_18 = DAT_006f4ec8;
    (**(code **)(*unaff_EDI + 0x38))(&local_18,10);
    uVar6 = DAT_006f227c % 3;
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar2 = uVar5 >> 5 ^ uVar5;
    PTR_s_CSISSOUND_006f8714 = s_Bottom_Out_006bf0e0;
    DAT_006f227c = uVar2 << 0x1b ^ uVar2 ^ uVar5;
    Csis__System__GetAllocator(&local_18);
    Mutex__Lock();
    iVar3 = (**(code **)*local_18)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iStack_10 = iVar3;
      uVar4 = _ftol_nocw();
      iVar3 = FUN_005259e0(uVar6,uVar4);
    }
    unaff_EDI[0xae] = iVar3;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x526da1 FUN_00526da1

void __fastcall FUN_00526da1(undefined4 param_1,undefined4 param_2)

{
  FUN_00536ee8(param_2);
  return;
}


// ==== 0x526db0 EAXTunerCar::BottomOutUpdate

/* WARNING: Removing unreachable block (ram,0x0052702e) */
/* WARNING: Removing unreachable block (ram,0x00527038) */
/* WARNING: Removing unreachable block (ram,0x0052703e) */
/* WARNING: Removing unreachable block (ram,0x00527043) */
/* WARNING: Removing unreachable block (ram,0x00527064) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__BottomOutUpdate(void)

{
  int *piVar1;
  int *in_EAX;
  float fVar2;
  int extraout_EDX;
  int iVar3;
  int extraout_EDX_00;
  int unaff_EBX;
  int iVar4;
  float10 fVar5;
  float local_8;
  int *local_4;
  
  if ((*(int *)(*(int *)(in_EAX[0x8d] + 0x14) + 4) == 1) &&
     (*(char *)(*(int *)(in_EAX[0x8d] + 0x14) + 0x734) == '\0')) {
    fVar5 = (float10)Car__GetWheelFlagFraction();
    if (fVar5 == (float10)0.0) {
      if ((char)in_EAX[0xb1] == '\0') {
        *(undefined1 *)(in_EAX + 0xb1) = 1;
        in_EAX[0xb2] = 0;
      }
      in_EAX[0xb2] = (int)((float)in_EAX[0x91] + (float)in_EAX[0xb2]);
    }
    if ((((*(char *)(extraout_EDX + 0x350) != '\0') && (*(char *)(extraout_EDX + 0x351) != '\0')) &&
        ((char)in_EAX[0xb1] != '\0')) &&
       ((0.1 < (float)in_EAX[0xb2] && (local_8 = 0.0, *(int *)(extraout_EDX + 0x28) == 1)))) {
      iVar4 = 0;
      iVar3 = 0x28;
      do {
        _DAT_00705900 =
             ABS(*(float *)(*(int *)(*(int *)(in_EAX[0x8d] + 0x34) + iVar3) + 0x1c) /
                 *(float *)(*(int *)(in_EAX[0x8d] + 0x20) + 0x184 + iVar4));
        EAX_linear_ramp_evaluate__not_SetCsisName_();
        local_8 = _DAT_00705904 + local_8;
        iVar3 = extraout_EDX_00 + 4;
        iVar4 = iVar4 + 0x20;
      } while (iVar3 < 0x30);
      EAXTunerCar__LandJumpPlay(local_8 * _K_HALF);
      in_EAX[0xb2] = 0;
      *(undefined1 *)(in_EAX + 0xb1) = 0;
    }
    fVar5 = (float10)Car__GetWheelFlagFraction();
    if ((fVar5 == (float10)_K_ONE) && ((char)in_EAX[0xb1] != '\0')) {
      in_EAX[0xb2] = 0;
      *(undefined1 *)(in_EAX + 0xb1) = 0;
    }
  }
  if (in_EAX[0xae] != 0) {
    local_8 = DAT_006f4ec8;
    (**(code **)(*in_EAX + 0x38))(&local_8,7);
    if ((int)local_8 < 0) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = local_8;
      if (0x7fff < (int)local_8) {
        fVar2 = 4.59163e-41;
      }
    }
    *(float *)(in_EAX[0xae] + 4) = fVar2;
    if (*(int *)in_EAX[0xae] != 0) {
      FUN_0064bc30((int *)in_EAX[0xae] + 1);
    }
    local_4 = (int *)0x0;
    if ((*(int *)in_EAX[0xae] != 0) && (Csis__Class__GetRefCount(&local_4), local_4 == (int *)0x1))
    {
      piVar1 = (int *)in_EAX[0xae];
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&local_4);
        Mutex__Lock();
        (**(code **)(*local_4 + 4))(piVar1);
        Mutex__Unlock();
      }
      in_EAX[0xae] = 0;
    }
  }
  if (in_EAX[0xaf] != 0) {
    local_4 = DAT_006f4ed0;
    (**(code **)(*in_EAX + 0x38))(&local_4,7);
    if (unaff_EBX < 0) {
      unaff_EBX = 0;
    }
    else if (0x7fff < unaff_EBX) {
      unaff_EBX = 0x7fff;
    }
    *(int *)(in_EAX[0xaf] + 4) = unaff_EBX;
    if (*(int *)in_EAX[0xaf] != 0) {
      FUN_0064bc30((int *)in_EAX[0xaf] + 1);
    }
    if (*(int *)in_EAX[0xaf] != 0) {
      Csis__Class__GetRefCount(&stack0xfffffff0);
    }
  }
  return;
}


// ==== 0x527080 EAXTunerCar::UpdateTorque

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXTunerCar__UpdateTorque(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 0x1d14)) {
  case 1:
  case 3:
    FUN_005326f0(param_2);
    uVar2 = *(undefined4 *)(param_1 + 0x1c84);
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1c44 + *(int *)(param_1 + 0x1c80) * 4) =
         *(undefined4 *)(param_1 + 0x1f90);
    FUN_005326f0(param_2);
    uVar2 = *(undefined4 *)(param_1 + 0x1c84);
    break;
  case 4:
  case 5:
    FUN_005326f0(param_2);
    *(undefined4 *)(param_1 + 0x1f88) = *(undefined4 *)(param_1 + 0x1c84);
    FUN_00584310(*(undefined4 *)(param_1 + 0x1c84));
    goto LAB_0052713c;
  default:
    if (*(int *)(param_1 + 0x1d18) == 1) {
      uVar2 = *(undefined4 *)(param_1 + 0x1f78);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x1f78);
    }
    piVar1 = (int *)FUN_00584270(uVar2);
    (**(code **)(*piVar1 + 4))();
    uVar2 = *(undefined4 *)(param_1 + 0x1f34);
  }
  *(undefined4 *)(param_1 + 0x1f88) = uVar2;
LAB_0052713c:
  FUN_00584270(*(float *)(param_1 + 0x1f90) - *(float *)(param_1 + 0x1f34));
  *(undefined4 *)(param_1 + 0x1f8c) = *(undefined4 *)(param_1 + 0x1f88);
  return;
}


// ==== 0x527180 EAXTunerCar::UpdateRPM

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXTunerCar__UpdateRPM(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x1d14)) {
  case 1:
    break;
  case 2:
  case 6:
    *(undefined4 *)(param_1 + 0x1bc8 + *(int *)(param_1 + 0x1c04) * 4) =
         *(undefined4 *)(param_1 + 0x1f20);
    FUN_005326f0(param_2);
    uVar1 = *(undefined4 *)(param_1 + 0x1c08);
    goto LAB_005271e3;
  case 3:
  case 4:
  case 5:
    break;
  default:
    uVar1 = *(undefined4 *)(param_1 + 0x1f20);
    goto LAB_005271e3;
  }
  FUN_005326f0(param_2);
  uVar1 = *(undefined4 *)(param_1 + 0x1c08);
LAB_005271e3:
  *(undefined4 *)(param_1 + 0x1f1c) = uVar1;
  *(float *)(param_1 + 0x1f1c) = *(float *)(param_1 + 0x1f1c) - *(float *)(param_1 + 0x196c);
  return;
}


// ==== 0x527220 FUN_00527220

void __thiscall FUN_00527220(int param_1,int param_2,int param_3)

{
  *(int *)(param_1 + 0x10) = param_3;
  *(int *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 0xc) = 1;
  *(int *)(param_1 + 8) = param_3 * 100 + *(int *)(param_2 + 0x1f08);
  return;
}


// ==== 0x527250 FUN_00527250

void * __thiscall FUN_00527250(void *param_1,byte param_2)

{
  FUN_00527270();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x527270 FUN_00527270

void __fastcall FUN_00527270(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = EAX_CarFX___EAX_CarFX;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006befbc;
  piVar1 = (int *)param_1[5];
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    local_10 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[5] = 0;
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = local_c;
  return;
}


// ==== 0x5272f0 FUN_005272f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005272f0(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int *in_stack_00000014;
  undefined4 uVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684e6b;
  local_c = ExceptionList;
  if (((char)param_1[3] != '\0') && (*(char *)(DAT_007356a8 + 0x84) == '\0')) {
    _DAT_00705938 = *(undefined4 *)(param_1[1] + 0x1f1c);
    ExceptionList = &local_c;
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    if (DAT_00705940 != '\0') {
      EAX_linear_ramp_evaluate__not_SetCsisName_();
    }
    if (DAT_006f1dd8 == 1) {
      (**(code **)(*(int *)piVar1[1] + 0x38))(&stack0x0000000c,1);
      piVar4 = (int *)piVar1[5];
      PTR_s_CSISSOUND_006f8714 = s_SparkChatter_006bf0d0;
      if (piVar4 != (int *)0x0) {
        if (*piVar4 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_1);
        Mutex__Lock();
        (**(code **)(*param_1 + 4))(piVar4);
        Mutex__Unlock();
      }
      piVar1[5] = 0;
      param_1 = (int *)FUN_005256f0(0x24);
      uStack_4 = 0;
      if (param_1 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        uVar5 = 0;
        uVar2 = _ftol_nocw(0);
        uVar3 = _ftol_nocw(uVar2);
        piVar4 = (int *)FUN_005258d0(in_stack_00000014,uVar3,uVar2,uVar5);
      }
      uStack_4 = 0xffffffff;
      piVar1[5] = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        if (*piVar4 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&stack0x00000014);
        Mutex__Lock();
        (**(code **)(*in_stack_00000014 + 4))(piVar4);
        Mutex__Unlock();
      }
      piVar1[5] = 0;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x527480 CameraMover::VelocityNoise

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (M+C) docs/re/camera.md */

void CameraMover__VelocityNoise(int *param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  
  cVar2 = (**(code **)(*param_1 + 0x60))(0);
  if ((cVar2 != '\0') && ((char)param_1[0x452] != '\0')) {
    FUN_005326f0(param_1);
    if (((char)param_1[0x7c4] != '\0') || ((float)param_1[0x7c7] <= 2000.0)) {
      param_1[0x44d] = 0;
      param_1[0x44e] = 0;
    }
    else {
      iVar3 = param_1[0x44d];
      if (iVar3 == 0) {
        param_1[0x44d] = 1;
        fVar4 = (float10)FUN_00564a80(0x3fb9999a);
        param_1[0x44c] = (int)(float)(fVar4 + (float10)0.05 + (float10)0.2);
        return;
      }
      if (iVar3 == 2) {
        _DAT_00705954 = param_1[0x7c7];
        param_1[0x44d] = 1;
        EAX_linear_ramp_evaluate__not_SetCsisName_();
        fVar5 = (float10)FUN_00564a80(0x3f800000);
        fVar4 = (float10)_DAT_00705958;
        param_1[0x44e] = 0;
        param_1[0x44c] =
             (int)(float)((((float10)1.5 - (float10)0.05) * fVar5 + (float10)0.05) * fVar4);
        return;
      }
      if ((iVar3 == 1) &&
         (fVar1 = (float)param_1[0x44c], param_1[0x44c] = (int)(fVar1 - (float)param_1),
         fVar1 - (float)param_1 < 0.0)) {
        RandomInt(*(int *)(&DAT_006b6600 + param_1[0x474] * 4) -
                  *(int *)(&DAT_006b65f8 + param_1[0x474] * 4));
        iVar3 = _ftol_nocw();
        param_1[0x44e] = iVar3;
        DAT_0078eae0 = (DAT_0078eae0 + 1) % 5;
        param_1[0x44d] = 2;
        FUN_005272f0(param_1 + 0x44f,DAT_0078eae0,param_1[0x44e],0x1000,param_1[0xab]);
        FUN_00532610(0x3ecccccd,0x3f800000,*(undefined4 *)(&DAT_006b6610 + param_1[0x474] * 4));
        return;
      }
    }
  }
  return;
}


// ==== 0x5276a0 FUN_005276a0

void * __thiscall FUN_005276a0(void *param_1,byte param_2)

{
  FUN_005276c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5276c0 FUN_005276c0

void __fastcall FUN_005276c0(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = EAX_CarFX___EAX_CarFX;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bee70;
  piVar1 = (int *)param_1[5];
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    local_10 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
    param_1[5] = 0;
  }
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = local_c;
  return;
}


// ==== 0x527740 EAXNitrous::Play

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall EAXNitrous__Play(int param_1)

{
  undefined4 uVar1;
  undefined4 in_stack_00000010;
  int local_14;
  int iStack_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((*(char *)(param_1 + 0xc) != '\0') && (DAT_006f1dd8 == 1)) {
    local_14 = (int)*(short *)(*(int *)(param_1 + 8) + 6);
    ExceptionList = &local_c;
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(&local_14,2);
    *(int *)(param_1 + 0x20) = local_14;
    EAXNitrous__Destroy();
    PTR_s_CSISSOUND_006f8714 = s_SND__Nitrous_006bf0c0;
    iStack_10 = FUN_005256f0(0x18);
    uVar1 = 0;
    uStack_4 = 0;
    if (iStack_10 != 0) {
      uVar1 = FUN_00525730(in_stack_00000010,0);
    }
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5277f0 EAXNitrous::Stop

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXNitrous__Stop(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


// ==== 0x527810 EAXNitrous::Destroy

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXNitrous__Destroy(void)

{
  int *piVar1;
  int unaff_EDI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_EDI + 0x14);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    *(undefined4 *)(unaff_EDI + 0x14) = 0;
  }
  return;
}


// ==== 0x527850 EAXNitrous::Update

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXNitrous__Update(void)

{
  int in_EAX;
  int unaff_EDI;
  int local_8;
  int local_4;
  
  if (*(int **)(in_EAX + 0x14) != (int *)0x0) {
    local_8 = 0;
    if (**(int **)(in_EAX + 0x14) != 0) {
      Csis__Class__GetRefCount(&local_8);
      if ((local_8 == 1) && (*(int *)(in_EAX + 0x18) == 0)) {
        EAXNitrous__Destroy();
        return;
      }
    }
    local_4 = (int)*(short *)(*(int *)(in_EAX + 8) + 6);
    (**(code **)(**(int **)(in_EAX + 4) + 0x38))(&local_4,2);
    if (unaff_EDI < 0) {
      unaff_EDI = 0;
    }
    else if (0x7fff < unaff_EDI) {
      unaff_EDI = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x14) + 8) = unaff_EDI;
    if (**(int **)(in_EAX + 0x14) != 0) {
      FUN_0064bc30(*(int **)(in_EAX + 0x14) + 1);
    }
  }
  return;
}


// ==== 0x5278e0 EAXTunerCar::UpdateNitrous

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__UpdateNitrous(void)

{
  char cVar1;
  int *unaff_EDI;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*unaff_EDI + 0x60))(2);
  if ((cVar1 != '\0') && ((char)unaff_EDI[0x478] != '\0')) {
    FUN_005326f0(unaff_retaddr);
    if (unaff_EDI[0x47b] == 0) {
      cVar1 = CarState__IsNitrousOn();
      if (cVar1 != '\0') {
        EAXNitrous__Play(0,0,0x1000,unaff_EDI[0xab]);
        EAXMixMgr__SetMixType(DAT_007356ac,5,0xbf800000,unaff_EDI[0x99]);
        FUN_00532610(0,0x3f800000,400);
      }
    }
    else if ((unaff_EDI[0x47b] == 1) && (cVar1 = CarState__IsNitrousOn(), cVar1 == '\0')) {
      EAXNitrous__Stop();
      EAXMixMgr__EndMixType(DAT_007356ac,5,unaff_EDI[0x99]);
      FUN_00532610(unaff_EDI[0x49b],0,1000);
      return;
    }
  }
  return;
}


// ==== 0x5279d0 EAXSkids::EAXSkids

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 * EAXSkids__EAXSkids(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684e53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_4 = 0;
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  local_4 = CONCAT31(local_4._1_3_,1);
  *param_1 = &PTR_FUN_006befb4;
  *puVar1 = &PTR_FUN_006bef88;
  param_1[0x8c] = 0;
  FUN_00527af0(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x527a40 FUN_00527a40

void * __thiscall FUN_00527a40(void *param_1,byte param_2)

{
  FUN_00527a60(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x527a60 FUN_00527a60

void FUN_00527a60(undefined4 *param_1)

{
  int *piVar1;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684a8f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006befb4;
  param_1[8] = &PTR_FUN_006bef88;
  piVar1 = (int *)param_1[0x8c];
  local_4 = 1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    (**(code **)(*local_10 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = local_c;
  return;
}


// ==== 0x527af0 FUN_00527af0

/* WARNING: Removing unreachable block (ram,0x00527bd8) */

void FUN_00527af0(int param_1)

{
  int *piVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *local_14;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684e2b;
  local_c = ExceptionList;
  bVar2 = 1;
  if (DAT_006f1dd8 == 1) {
    if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
      bVar2 = 0;
    }
    piVar3 = *(int **)(param_1 + 0x230);
    uVar4 = (uint)bVar2;
    PTR_s_CSISSOUND_006f8714 = s_SND__Skid_006bf0b4;
    ExceptionList = &local_c;
    if (piVar3 != (int *)0x0) {
      ExceptionList = &local_c;
      if (*piVar3 != 0) {
        ExceptionList = &local_c;
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_14);
      Mutex__Lock();
      (**(code **)(*local_14 + 4))(piVar3);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x230) = 0;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    piVar3 = (int *)(**(code **)*local_10)(0x3c,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar1 = piVar3 + 1;
      *piVar1 = 0;
      piVar3[2] = 0;
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0;
      piVar3[7] = 0;
      if (3 < bVar2) {
        uVar4 = 3;
      }
      piVar3[8] = uVar4;
      piVar3[9] = 0x1000;
      piVar3[10] = 0x1000;
      piVar3[0xb] = 0x1000;
      piVar3[0xc] = 0;
      piVar3[0xd] = 0;
      piVar3[0xe] = 0;
      local_14 = piVar3;
      iVar5 = Csis__Class__CreateInstance(&DAT_0073d7f4,piVar1,piVar3);
      if (iVar5 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FX_SKID_006f2250);
        Csis__Class__CreateInstance(&DAT_0073d7f4,piVar1,piVar3);
      }
    }
    *(int **)(param_1 + 0x230) = piVar3;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x527c60 FUN_00527c60

void __fastcall FUN_00527c60(int *param_1,int param_2)

{
  if ((DAT_007361f0 != (int *)0x0) && (*DAT_007361f0 == 8)) {
    *param_1 = 0;
    return;
  }
  *param_1 = *(int *)(param_2 + 0x70) * *param_1 >> 0xf;
  FUN_00536c20(DAT_007356ac);
  return;
}


// ==== 0x527ca0 FUN_00527ca0

void __fastcall FUN_00527ca0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_retaddr;
  
  if ((DAT_006f1dd8 != 0) && (*(int *)(in_EAX + 0x230) != 0)) {
    iVar1 = *(int *)(in_EAX + 4);
    (**(code **)(*(int *)(in_EAX + 0x20) + 0x28))(param_2,0);
    iVar1 = *(int *)(&DAT_006f4ee8 + (*(int *)(iVar1 + 0x12f8) + *(int *)(iVar1 + 0x12f4) * 2) * 4);
    iVar3 = iVar1 * DAT_006f4ee4 >> 0xf;
    iVar2 = iVar1 * DAT_006f4edc >> 0xf;
    iVar1 = iVar1 * DAT_006f4ee0 >> 0xf;
    FUN_00527c60(4);
    FUN_00527c60(4);
    FUN_00527c60(4);
    switch(param_4) {
    case 8:
    case 9:
    case 0xe:
    case 0xf:
    case 0x16:
      iVar2 = DAT_006f7eac * iVar2 >> 0xf;
      iVar3 = DAT_006f7eac * iVar3 >> 0xf;
      iVar1 = DAT_006f7eac * iVar1 >> 0xf;
      break;
    default:
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 4) = iVar2;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0x7fff < iVar3) {
      iVar3 = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 8) = iVar3;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0xc) = iVar1;
    if (unaff_EBX < 0) {
      unaff_EBX = 0;
    }
    else if (0x400 < unaff_EBX) {
      unaff_EBX = 0x400;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x10) = unaff_EBX;
    if (param_3 < 0) {
      param_3 = 0;
    }
    else if (0x400 < param_3) {
      param_3 = 0x400;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x14) = param_3;
    if (unaff_retaddr < 0) {
      unaff_retaddr = 0;
    }
    else if (0x3ff < unaff_retaddr) {
      unaff_retaddr = 0x3ff;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x18) = unaff_retaddr;
    iVar1 = *(int *)(in_EAX + 0x6c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0xffff < iVar1) {
      iVar1 = 0xffff;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x1c) = iVar1;
    if (1.0 <= *(float *)(*(int *)(*(int *)(in_EAX + 4) + 0x234) + 0x3d0)) {
      CarState__GetYaw();
    }
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0xb4 < iVar1) {
      iVar1 = 0xb4;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x30) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (1000 < iVar1) {
      iVar1 = 1000;
    }
    *(int *)(*(int *)(in_EAX + 0x230) + 0x34) = iVar1;
    if (**(int **)(in_EAX + 0x230) != 0) {
      FUN_0064bc30(*(int **)(in_EAX + 0x230) + 1);
    }
  }
  return;
}


// ==== 0x527f30 FUN_00527f30

void __fastcall FUN_00527f30(void *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685326;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x240);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = EAXSkids__EAXSkids(pvVar1);
  }
  *(undefined4 *)((int)param_1 + 0x1758) = uVar2;
  pvVar1 = _malloc(0x240);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = EAXSkids__EAXSkids(pvVar1);
  }
  *(undefined4 *)((int)param_1 + 0x175c) = uVar2;
  local_4 = 0xffffffff;
  (**(code **)(**(int **)((int)param_1 + 0x1758) + 4))
            (param_1,*(undefined4 *)((int)param_1 + 0x1efc));
  pvVar1 = param_1;
  (**(code **)(**(int **)((int)param_1 + 0x175c) + 4))
            (param_1,*(undefined4 *)((int)param_1 + 0x1efc));
  (**(code **)(*(int *)(*(int *)((int)param_1 + 0x1758) + 0x20) + 0x10))(&DAT_006f4420);
  (**(code **)(*(int *)(*(int *)((int)param_1 + 0x175c) + 0x20) + 0x10))(&DAT_006f4420);
  ExceptionList = pvVar1;
  return;
}


// ==== 0x528010 FUN_00528010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00528010(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined *puVar5;
  char local_28 [40];
  
  local_28[0] = '|';
  iVar1 = 0;
  do {
    cVar4 = (&DAT_006bf0b1)[iVar1];
    local_28[iVar1 + 1] = cVar4;
    iVar1 = iVar1 + 1;
  } while (cVar4 != '\0');
  iVar1 = _ftol_nocw();
  if (0 < iVar1) {
    iVar1 = (iVar1 - 1U >> 1) + 1;
    do {
      iVar2 = 0;
      cVar4 = local_28[0];
      while (cVar4 != '\0') {
        local_28[iVar2] = cVar4;
        iVar3 = iVar2 + 1;
        iVar2 = iVar2 + 1;
        cVar4 = local_28[iVar3];
      }
      cVar4 = '|';
      puVar5 = &DAT_006bf0b0;
      do {
        iVar3 = iVar2;
        local_28[iVar3] = cVar4;
        cVar4 = puVar5[1];
        puVar5 = puVar5 + 1;
        iVar2 = iVar3 + 1;
      } while (cVar4 != '\0');
      iVar1 = iVar1 + -1;
      local_28[iVar3 + 1] = '\0';
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x5280d0 FUN_005280d0

void __fastcall FUN_005280d0(int param_1)

{
  if ((*(int *)(param_1 + 0x1758) != 0) && (*(int *)(param_1 + 0x175c) != 0)) {
    FUN_00527ca0(*(undefined4 *)(param_1 + 0x1498),*(undefined4 *)(param_1 + 0x149c),
                 *(undefined4 *)(param_1 + 0x14a4),*(undefined4 *)(param_1 + 0x12dc));
    FUN_00527ca0(*(undefined4 *)(param_1 + 0x14a4),*(undefined4 *)(param_1 + 0x14a8),
                 *(undefined4 *)(param_1 + 0x1498),*(undefined4 *)(param_1 + 0x12d8));
    if (DAT_0073563c != '\0') {
      FUN_00528010(0xffffff9c,0xffffff9c,&DAT_006c9ae4,*(undefined4 *)(param_1 + 0x1494));
      FUN_00528010(0xffffff9c,0xffffffab,&DAT_006bf0ac,*(undefined4 *)(param_1 + 0x1498));
      FUN_00528010(0xffffff9c,0xffffffba,&DAT_006bf0a8,*(undefined4 *)(param_1 + 0x149c));
      FUN_00528010(0xffffff9c,100,&DAT_006bf0a4,*(undefined4 *)(param_1 + 0x14a0));
      FUN_00528010(0xffffff9c,0x73,&DAT_006bf0a0,*(undefined4 *)(param_1 + 0x14a4));
      FUN_00528010(0xffffff9c,0x82,&DAT_006bf09c,*(undefined4 *)(param_1 + 0x14a8));
    }
  }
  return;
}


// ==== 0x5281f0 FUN_005281f0

undefined4 * FUN_005281f0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684e53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_4 = 0;
  EAXS_3DMixer__EAXS_3DMixer();
  local_4 = CONCAT31(local_4._1_3_,1);
  *param_1 = &PTR_FUN_006bee5c;
  param_1[8] = &PTR_FUN_006bee30;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  FUN_00532640();
  iVar2 = DAT_007356a8;
  *(undefined1 *)(extraout_EDX_00 + 0x78) = 1;
  param_1[0x8e] = 0;
  param_1[0x8d] = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0xb3) = 0;
  param_1[0xaf] = 0;
  param_1[0x37] = &DAT_006f42d0;
  param_1[0x89] = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(param_1[8] + 0x24))();
  iVar2 = param_1[0x37];
  if (iVar2 != 0) {
    iVar1 = EAXSound__GetMasterVolume();
    iVar2 = iVar1 * **(int **)(iVar2 + 0x60) >> 0xf;
    param_1[0x31] = iVar2;
    param_1[0x32] = iVar2;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5282e0 FUN_005282e0

void * __thiscall FUN_005282e0(void *param_1,byte param_2)

{
  EAXTurbo___EAXTurbo();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x528300 EAXTurbo::_EAXTurbo

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXTurbo___EAXTurbo(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684a4f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006bee5c;
  param_1[8] = &PTR_FUN_006bee30;
  piVar1 = (int *)param_1[0x8e];
  local_4 = 1;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
    DAT_00735648 = DAT_00735648 + -1;
    param_1[0x8e] = 0;
  }
  piVar1 = (int *)param_1[0x8d];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
    DAT_0073564c = DAT_0073564c + -1;
    param_1[0x8d] = 0;
  }
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x5283f0 EAXTurbo::AdjustVolume

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXTurbo__AdjustVolume(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  piVar2 = DAT_007361f0;
  if ((DAT_007361f0 != (int *)0x0) && (*DAT_007361f0 == 8)) {
    *in_EAX = 0;
    return;
  }
  *in_EAX = *(int *)(param_3 + 0x70) * *in_EAX >> 0xf;
  if (param_2 < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *in_EAX = 0;
    }
    if ((piVar2 != (int *)0x0) && ((iVar1 = *piVar2, iVar1 == 1 || (iVar1 == 7)))) {
      *in_EAX = 0;
    }
    *in_EAX = *(int *)(param_2 * 0xd10 + 0x398 + DAT_007356ac) * *in_EAX >> 0xf;
  }
  return;
}


// ==== 0x528470 EAXTurbo::PlayBlowoff

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 EAXTurbo__PlayBlowoff(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 in_stack_00000018;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d4b;
  local_c = ExceptionList;
  if ((*(char *)(param_1 + 0xc) != '\0') && (DAT_006f1dd8 == 1)) {
    piVar1 = *(int **)(param_1 + 0x238);
    ExceptionList = &local_c;
    if (piVar1 != (int *)0x0) {
      ExceptionList = &local_c;
      if (*piVar1 != 0) {
        ExceptionList = &local_c;
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_10);
      Mutex__Lock();
      (**(code **)(*local_10 + 4))(piVar1);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x238) = 0;
    uVar2 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x2b8) = uVar2;
    if (0.75 < *(float *)(param_1 + 0x2c4)) {
      uVar3 = DAT_006f227c ^ 0x1d872b41;
      uVar4 = uVar3 >> 5 ^ uVar3;
      DAT_006f227c = uVar4 << 0x1b ^ uVar4 ^ uVar3;
    }
    (**(code **)(*(int *)(param_1 + 0x20) + 0x28))(*(int *)(*(int *)(param_1 + 4) + 0x234) + 0x60,0)
    ;
    EAXTurbo__AdjustVolume(param_1,3);
    PTR_s_CSISSOUND_006f8714 = s_SND__Turbo_006bf090;
    iVar5 = FUN_005256f0(0x1c);
    uStack_4 = 0;
    if (iVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = _ftol_nocw();
      uVar2 = FUN_00525aa0(in_stack_00000018,uVar2);
    }
    *(undefined4 *)(param_1 + 0x238) = uVar2;
    *(undefined4 *)(param_1 + 700) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x240);
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x528610 EAXTurbo::IsBlowOffDone

/* [canon] audio high (ghidra) docs/re/sound.md */

bool EAXTurbo__IsBlowOffDone(void)

{
  int in_EAX;
  int local_4;
  
  if (*(int **)(in_EAX + 0x238) == (int *)0x0) {
    return true;
  }
  local_4 = 0;
  if (**(int **)(in_EAX + 0x238) != 0) {
    Csis__Class__GetRefCount(&local_4);
  }
  return local_4 == 1;
}


// ==== 0x528650 EAXTurbo::UpdateBlowOff

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTurbo__UpdateBlowOff(void)

{
  char cVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0x238) != 0) && (*(char *)(in_EAX + 0xc) != '\0')) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *(undefined4 *)(*(int *)(in_EAX + 0x238) + 8) = 0;
    }
    if (**(int **)(in_EAX + 0x238) != 0) {
      FUN_0064bc30(*(int **)(in_EAX + 0x238) + 1);
    }
    cVar1 = EAXTurbo__IsBlowOffDone();
    if (cVar1 != '\0') {
      EAXTurbo__StopBlowOff();
    }
  }
  return;
}


// ==== 0x5286b0 EAXTurbo::StopBlowOff

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTurbo__StopBlowOff(void)

{
  int *piVar1;
  int unaff_EDI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_EDI + 0x238);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    *(undefined4 *)(unaff_EDI + 0x238) = 0;
  }
  return;
}


// ==== 0x528700 EAXTurbo::PlaySpl__spool_loop_

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 EAXTurbo__PlaySpl__spool_loop_(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined4 in_stack_00000014;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if (DAT_006f1dd8 == 1) {
    ExceptionList = &local_c;
    (**(code **)(*(int *)(unaff_EBX + 0x20) + 0x28))
              (*(int *)(*(int *)(unaff_EBX + 4) + 0x234) + 0x60,0);
    EAXTurbo__AdjustVolume(unaff_EBX,3);
    piVar1 = *(int **)(unaff_EBX + 0x234);
    PTR_s_CSISSOUND_006f8714 = s_SND_Turbo_Spool_006bf080;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&stack0xffffffe4);
      Mutex__Lock();
      (**(code **)(*unaff_EDI + 4))(piVar1);
      Mutex__Unlock();
    }
    *(undefined4 *)(unaff_EBX + 0x234) = 0;
    Csis__System__GetAllocator(&stack0xffffffe8);
    Mutex__Lock();
    iVar2 = (**(code **)*unaff_ESI)(0x1c,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = _ftol_nocw();
      uVar3 = FUN_00525aa0(in_stack_00000014,uVar3);
    }
    *(undefined4 *)(unaff_EBX + 0x234) = uVar3;
    DAT_0073564c = DAT_0073564c + 1;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x528830 EAXTurbo::UpdateSpool

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 EAXTurbo__UpdateSpool(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  float10 extraout_ST0;
  float10 fVar6;
  
  if (*(char *)(in_EAX + 0xc) != '\0') {
    if (*(int *)(in_EAX + 0x234) == 0) {
      EAXTurbo__PlaySpl__spool_loop_(0,0,0,0,0);
      return 0;
    }
    if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
      if (*(float *)(*(int *)(in_EAX + 4) + 0x1278) <= 0.01) {
        fVar1 = *(float *)(in_EAX + 0x2c0) - 0.5;
      }
      else {
        fVar1 = *(float *)(*(int *)(in_EAX + 4) + 0x1278) + *(float *)(in_EAX + 0x2c0);
      }
      *(float *)(in_EAX + 0x2c0) = fVar1;
    }
    fVar1 = *(float *)(in_EAX + 0x2c0);
    iVar4 = *(int *)(in_EAX + 8);
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    if (*(float *)(iVar4 + 0x10) < fVar1) {
      fVar1 = *(float *)(iVar4 + 0x10);
    }
    *(float *)(in_EAX + 0x2c0) = fVar1;
    iVar3 = _ftol_nocw();
    fVar1 = (float)(iVar3 + -1000) * 0.01;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    else if (_K_ONE < fVar1) {
      fVar1 = _K_ONE;
    }
    fVar2 = (_K_ONE - 0.4) * fVar1 + 0.4;
    fVar1 = fVar2 * *(float *)(iVar4 + 0x10);
    fVar6 = extraout_ST0;
    if (extraout_ST0 <= (float10)0.0) {
      fVar6 = (float10)0.0;
    }
    if ((float10)fVar1 < fVar6) {
      fVar6 = (float10)fVar1;
    }
    *(float *)(in_EAX + 0x2c0) = (float)fVar6;
    if ((fVar6 == (float10)fVar2 * (float10)*(float *)(iVar4 + 0x10)) &&
       (*(char *)(in_EAX + 0x2cc) == '\0')) {
      *(undefined1 *)(in_EAX + 0x2cc) = 1;
      FUN_00532640();
      FUN_00532670(0,0,1000,0);
      FUN_00532670(0,0x4399999a,2000,0);
    }
    else if ((fVar6 != (float10)*(float *)(iVar4 + 0x10)) && (*(char *)(in_EAX + 0x2cc) != '\0')) {
      *(undefined1 *)(in_EAX + 0x2cc) = 0;
    }
    *(float *)(in_EAX + 0x2c4) =
         *(float *)(in_EAX + 0x2c0) / *(float *)(*(int *)(in_EAX + 8) + 0x10);
    _ftol_nocw();
    (**(code **)(*(int *)(in_EAX + 0x20) + 0x28))(*(int *)(*(int *)(in_EAX + 4) + 0x234) + 0x60,0);
    EAXTurbo__AdjustVolume(in_EAX,3);
    if (*(char *)(in_EAX + 0x2cc) != '\0') {
      FUN_005326f0(fVar2);
      iVar4 = _ftol_nocw();
      unaff_ESI = (&DAT_006f7220)[iVar4] * unaff_ESI >> 0xf;
    }
    iVar4 = *(int *)(*(int *)(in_EAX + 4) + 0x6c);
    iVar3 = *(int *)(*(int *)(in_EAX + 4) + 0x2ac);
    if (unaff_ESI < 0) {
      unaff_ESI = 0;
    }
    else if (0x7fff < unaff_ESI) {
      unaff_ESI = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x234) + 8) = unaff_ESI;
    iVar5 = _ftol_nocw();
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0x2000 < iVar5) {
      iVar5 = 0x2000;
    }
    *(int *)(*(int *)(in_EAX + 0x234) + 0xc) = iVar5;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (0xffff < iVar4) {
      iVar4 = 0xffff;
    }
    *(int *)(*(int *)(in_EAX + 0x234) + 0x10) = iVar4;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0x400 < iVar3) {
      iVar3 = 0x400;
    }
    *(int *)(*(int *)(in_EAX + 0x234) + 0x14) = iVar3;
    if (**(int **)(in_EAX + 0x234) != 0) {
      FUN_0064bc30(*(int **)(in_EAX + 0x234) + 1);
    }
  }
  return 0;
}


// ==== 0x528b60 EAXTunerCar::UpdateTurboFX

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__UpdateTurboFX(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 unaff_retaddr;
  
  if (((param_1[0x49d] != 0) && (cVar2 = (**(code **)(*param_1 + 0x60))(1), cVar2 != '\0')) &&
     (*(char *)(param_1[0x49d] + 0xc) != '\0')) {
    EAXTurbo__UpdateBlowOff(unaff_retaddr);
    EAXTurbo__UpdateSpool(unaff_retaddr);
    iVar1 = param_1[0x4a9];
    if (iVar1 == 0) {
      if (_DAT_006f80ec < (float)param_1[0x7e3]) {
        param_1[0x4a9] = 1;
      }
    }
    else if (iVar1 == 1) {
      if (0.2 < (float)param_1[0x4a2]) {
        param_1[0x4a9] = 2;
        EAXTurbo__PlayBlowoff(param_1[0x49d],0,0,0xfff,param_1[0x1b],param_1[0xab]);
        *(undefined4 *)(param_1[0x49d] + 0x2c0) = 0;
        EAXTurbo__UpdateSpool(unaff_retaddr);
        return;
      }
    }
    else if ((iVar1 == 2) && (cVar2 = EAXTurbo__IsBlowOffDone(), cVar2 != '\0')) {
      param_1[0x4a9] = 0;
      return;
    }
  }
  return;
}


// ==== 0x528c70 EAXShifting::_scalar_deleting_destructor_

/* [canon] audio high (ghidra) docs/re/sound.md */

void * __thiscall EAXShifting___scalar_deleting_destructor_(void *param_1,byte param_2)

{
  EAXShifting___EAXShifting();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x528c90 EAXShifting::_EAXShifting

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXShifting___EAXShifting(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = EAX_CarFX___EAX_CarFX;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_EAXShifting___scalar_deleting_destructor__006bee64;
  piVar1 = (int *)param_1[5];
  local_4 = 0;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[6];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[7];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x528d70 EAXShifting::PlayDisengageSnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXShifting__PlayDisengageSnd(int param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iStack_14;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (fVar2 = *(float *)(*(int *)(param_1 + 4) + 0x1f1c), 7000.0 <= fVar2))
  {
    piVar4 = *(int **)(param_1 + 0x1c);
    ExceptionList = &local_c;
    if (piVar4 != (int *)0x0) {
      ExceptionList = &local_c;
      if (*piVar4 != 0) {
        ExceptionList = &local_c;
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_10);
      Mutex__Lock();
      (**(code **)(*local_10 + 4))(piVar4);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    _DAT_007058e4 = fVar2;
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    iVar3 = _ftol_nocw();
    iStack_14 = iVar3 * DAT_006f4ef8 >> 0xf;
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(&iStack_14,5);
    PTR_s_CSISSOUND_006f8714 = s_SND_ShiftDisEngage_006bf06c;
    Csis__System__GetAllocator(&puStack_4);
    Mutex__Lock();
    piVar4 = (int *)(**(code **)*puStack_4)(0x1c,4,0xffffffff);
    Mutex__Unlock();
    puStack_4 = (undefined4 *)0x0;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar1 = piVar4 + 1;
      *piVar1 = 1;
      if (iStack_14 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iStack_14;
        if (0x7fff < iStack_14) {
          iVar3 = 0x7fff;
        }
      }
      piVar4[2] = iVar3;
      piVar4[3] = 0x1000;
      piVar4[4] = 0;
      piVar4[5] = 1;
      piVar4[6] = 0;
      local_10 = piVar4;
      iVar3 = Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
      if (iVar3 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FX_SHIFTING_01_006f2240);
        Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
      }
    }
    *(int **)(param_1 + 0x1c) = piVar4;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x528f00 EAXShifting::Update

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXShifting__Update(int param_1)

{
  if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8) = 0;
      if (**(int **)(param_1 + 0x1c) != 0) {
        FUN_0064bc30(*(int **)(param_1 + 0x1c) + 1);
      }
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x18) + 8) = 0;
      if (**(int **)(param_1 + 0x18) != 0) {
        FUN_0064bc30(*(int **)(param_1 + 0x18) + 1);
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 0;
      if (**(int **)(param_1 + 0x14) != 0) {
        FUN_0064bc30(*(int **)(param_1 + 0x14) + 1);
      }
    }
  }
  return;
}


// ==== 0x528f80 EAXShifting::PlayEngageSnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXShifting__PlayEngageSnd(int param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iStack_14;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (fVar2 = *(float *)(*(int *)(param_1 + 4) + 0x1d0c), 7000.0 <= fVar2))
  {
    piVar4 = *(int **)(param_1 + 0x18);
    ExceptionList = &local_c;
    if (piVar4 != (int *)0x0) {
      ExceptionList = &local_c;
      if (*piVar4 != 0) {
        ExceptionList = &local_c;
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_10);
      Mutex__Lock();
      (**(code **)(*local_10 + 4))(piVar4);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    _DAT_007058e4 = fVar2;
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    iVar3 = _ftol_nocw();
    iStack_14 = iVar3 * DAT_006f4ef8 >> 0xf;
    (**(code **)(**(int **)(param_1 + 4) + 0x38))(&iStack_14,5);
    PTR_s_CSISSOUND_006f8714 = s_SND_ShiftDisengage_006bf058;
    Csis__System__GetAllocator(&puStack_4);
    Mutex__Lock();
    piVar4 = (int *)(**(code **)*puStack_4)(0x1c,4,0xffffffff);
    Mutex__Unlock();
    puStack_4 = (undefined4 *)0x0;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar1 = piVar4 + 1;
      *piVar1 = 0;
      if (iStack_14 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iStack_14;
        if (0x7fff < iStack_14) {
          iVar3 = 0x7fff;
        }
      }
      piVar4[2] = iVar3;
      piVar4[3] = 0x1000;
      piVar4[4] = 0;
      piVar4[5] = 0;
      piVar4[6] = 0;
      local_10 = piVar4;
      iVar3 = Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
      if (iVar3 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FX_SHIFTING_01_006f2240);
        Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
      }
    }
    *(int **)(param_1 + 0x18) = piVar4;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x529100 FUN_00529100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00529100(float param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piStack_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar2 = (int)param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if (*(char *)((int)param_1 + 0xc) != '\0') {
    piVar1 = *(int **)((int)param_1 + 4);
    iVar5 = *(short *)(*(int *)((int)param_1 + 8) + 8) * 0x7fff >> 0xf;
    ExceptionList = &local_c;
    param_1 = (float)iVar5;
    iVar3 = _ftol_nocw();
    param_1 = ((float)iVar3 - 1500.0) / 6500.0;
    iVar3 = _ftol_nocw();
    param_1 = (float)((&DAT_006f7220)[iVar3] * iVar5 >> 0xf);
    if (DAT_006f1dd8 == 1) {
      (**(code **)(*piVar1 + 0x38))(&param_1,1);
      piVar1 = *(int **)(iVar2 + 0x14);
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_10);
        Mutex__Lock();
        (**(code **)(*piStack_10 + 4))(piVar1);
        Mutex__Unlock();
        *(undefined4 *)(iVar2 + 0x14) = 0;
      }
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x2b0);
      PTR_s_CSISSOUND_006f8714 = s_SND__Shift_006bf04c;
      piStack_10 = (int *)FUN_005256f0(0x1c);
      uStack_4 = 0;
      if (piStack_10 == (int *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_005257f0(0,iVar3 == 2);
      }
      *(undefined4 *)(iVar2 + 0x14) = uVar4;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5292b0 EAXTunerCar::BeginUpShift

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__BeginUpShift(int param_1)

{
  float fVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0x1e50) = 0;
  *(undefined4 *)(param_1 + 0x1a3c) = 0;
  *(undefined4 *)(param_1 + 0x1a40) = 0;
  *(undefined4 *)(param_1 + 0x1d14) = 0;
  FUN_00584310(*(undefined4 *)(param_1 + 0x1f8c));
  if (3000.0 <= *(float *)(param_1 + 0x1f1c)) {
    uVar4 = *(undefined4 *)(param_1 + 0x1f8c);
    *(undefined4 *)(param_1 + 0x1d10) = *(undefined4 *)(param_1 + 0x240);
    *(undefined4 *)(param_1 + 0x1d14) = 1;
    *(undefined4 *)(param_1 + 0x1d0c) = *(undefined4 *)(param_1 + 0x1f1c);
    FUN_00532640();
    FUN_00532670(uVar4,0,0x32,0);
    *(undefined4 *)(param_1 + 0x1c84) = uVar4;
    sVar2 = *(short *)(*(int *)(param_1 + 0x1f0c) + 0x16);
    sVar3 = *(short *)(*(int *)(param_1 + 0x1f0c) + 0x14);
    uVar4 = *(undefined4 *)(param_1 + 0x1d0c);
    fVar1 = *(float *)(param_1 + 0x1d0c);
    FUN_00532640();
    FUN_00532670(uVar4,fVar1 - (float)(int)sVar3,(int)sVar2,0);
    *(undefined4 *)(param_1 + 0x1c08) = uVar4;
    fVar1 = *(float *)(*(int *)(param_1 + 0x1f0c) + 0x24);
    *(undefined1 *)(param_1 + 0x1d48) = 1;
    *(undefined4 *)(param_1 + 0x1d4c) = 1;
    *(float *)(param_1 + 0x1d50) = fVar1 + *(float *)(param_1 + 0x240);
    EAXShifting__PlayDisengageSnd(param_1 + 0x1d24);
  }
  return;
}


// ==== 0x5293e0 FUN_005293e0

void __fastcall FUN_005293e0(int param_1)

{
  float fVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x1d18) != 1) {
    *(undefined1 *)(param_1 + 0x1d20) = 0;
    *(undefined4 *)(param_1 + 0x1e50) = 0;
    *(undefined4 *)(param_1 + 0x1a3c) = 0;
    *(undefined4 *)(param_1 + 0x1a40) = 0;
    *(undefined4 *)(param_1 + 0x1d14) = 0;
    FUN_00584310(*(undefined4 *)(param_1 + 0x1f8c));
    uVar4 = *(undefined4 *)(param_1 + 0x1f8c);
    *(undefined4 *)(param_1 + 0x1d0c) = *(undefined4 *)(param_1 + 0x1f1c);
    *(undefined4 *)(param_1 + 0x1d14) = 3;
    *(undefined4 *)(param_1 + 0x1d10) = *(undefined4 *)(param_1 + 0x240);
    FUN_00532640();
    FUN_00532670(uVar4,0,0x32,0);
    *(undefined4 *)(param_1 + 0x1c84) = uVar4;
    sVar2 = *(short *)(*(int *)(param_1 + 0x1f0c) + 0x28);
    sVar3 = *(short *)(*(int *)(param_1 + 0x1f0c) + 0x2a);
    uVar4 = *(undefined4 *)(param_1 + 0x1d0c);
    fVar1 = *(float *)(param_1 + 0x1d0c);
    FUN_00532640();
    FUN_00532670(uVar4,fVar1 - (float)(int)sVar2,(int)sVar3,0);
    *(undefined4 *)(param_1 + 0x1c08) = uVar4;
    fVar1 = *(float *)(*(int *)(param_1 + 0x1f0c) + 0x38);
    *(undefined1 *)(param_1 + 0x1d48) = 1;
    *(undefined4 *)(param_1 + 0x1d4c) = 2;
    *(float *)(param_1 + 0x1d50) = fVar1 + *(float *)(param_1 + 0x240);
  }
  return;
}


// ==== 0x529500 FUN_00529500

void __thiscall FUN_00529500(int *param_1,undefined4 param_2)

{
  EAXTunerCar__BeginDownShift(param_2);
  (**(code **)(*param_1 + 0x98))(param_2);
  (**(code **)(param_1[0x749] + 8))();
  return;
}


// ==== 0x529530 EAXTunerCar::UpdateGearShiftState__map_names_swapped_with_0x523e30_

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__UpdateGearShiftState__map_names_swapped_with_0x523e30_(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  undefined4 auStack_6c [6];
  undefined4 uStack_54;
  int iStack_50;
  float fStack_4c;
  float fStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 auStack_2c [9];
  undefined4 uStack_8;
  
  if ((*(float *)(param_1 + 0x1d50) < *(float *)(param_1 + 0x240)) &&
     (*(char *)(param_1 + 0x1d48) != '\0')) {
    iStack_40 = *(undefined4 *)(param_1 + 0x6c);
    fStack_4c = *(float *)(param_1 + 0x1d4c);
    iStack_44 = 0x1000;
    fStack_48 = 0.0;
    iStack_50 = param_1 + 0x1d24;
    uStack_54 = 0x529573;
    FUN_00529100();
    *(undefined1 *)(param_1 + 0x1d48) = 0;
  }
  switch(*(undefined4 *)(param_1 + 0x1d14)) {
  case 1:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      iStack_44 = *(undefined4 *)(param_1 + 0x1f20);
      *(undefined4 *)(param_1 + 0x1d14) = 2;
      iStack_40 = (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x1a);
      fStack_48 = (float)(int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x18) +
                  *(float *)(param_1 + 0x1f20);
      fStack_4c = 7.58427e-39;
      FUN_00532610();
      iStack_44 = *(undefined4 *)(param_1 + 0x1f90);
      fStack_48 = *(float *)(param_1 + 0x1f8c);
      iStack_40 = 10;
      fStack_4c = 7.584312e-39;
      FUN_00532610();
      iStack_40 = (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x1c);
      fStack_48 = *(float *)(*(int *)(param_1 + 0x1f0c) + 0x20);
      iStack_44 = 0;
      fStack_4c = 7.584351e-39;
      FUN_00532610();
      iStack_40 = 0x52961f;
      FUN_00525b80();
      iStack_40 = *(undefined4 *)(param_1 + 0x264);
      auStack_2c[0] = 1;
      auStack_2c[2] = 1;
      puVar4 = &DAT_007366f0;
      puVar5 = auStack_2c + 3;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      uStack_8 = DAT_006f80f0;
      puVar4 = auStack_2c;
      puVar5 = auStack_6c;
      for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      EAXMixMgr__ReceiveTrigger(DAT_007356ac);
      iStack_40 = 0x52966f;
      FUN_00529970();
      iStack_40 = 0x529676;
      cVar1 = EAXTunerCar__ShouldUpShiftDynLd();
      if (cVar1 != '\0') {
        iStack_40 = 0x529681;
        FUN_0052a0a0();
      }
      iStack_40 = param_1 + 0x1d24;
      iStack_44 = 0x52968d;
      EAXShifting__PlayEngageSnd();
      return;
    }
    break;
  case 2:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      iStack_40 = *(undefined4 *)(param_1 + 0x1c84);
      *(undefined4 *)(param_1 + 0x1d14) = 0;
      iStack_44 = 0x5296c3;
      FUN_00584310();
      return;
    }
    break;
  case 3:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 4;
      iStack_40 = 0x5296f1;
      FUN_00532640();
      iVar3 = *(int *)(param_1 + 0x1f0c);
      iVar2 = (int)*(short *)(iVar3 + 0x2e);
      if (*(int *)(param_1 + 0x1d18) < 3) {
        iStack_40 = 0x529717;
        iVar2 = _ftol_nocw();
      }
      iStack_40 = 3;
      fStack_48 = (float)(int)*(short *)(iVar3 + 0x2c) + *(float *)(param_1 + 0x1f20);
      fStack_4c = *(float *)(param_1 + 0x1f1c);
      iStack_50 = 0x529743;
      iStack_44 = iVar2;
      FUN_00532670();
      fStack_48 = *(float *)(param_1 + 0x1f8c);
      iStack_40 = DAT_006f80f8;
      iStack_44 = DAT_006f80f4;
      fStack_4c = 7.584821e-39;
      FUN_00532610();
      iStack_40 = 0x52976c;
      cVar1 = FUN_00529f80();
      if (cVar1 != '\0') {
        iStack_40 = 0x52977b;
        FUN_0052a2c0();
        return;
      }
    }
    break;
  case 4:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 5;
      iStack_40 = 0x5297a9;
      FUN_00532640();
      iVar3 = *(int *)(param_1 + 0x1f0c);
      iVar2 = (int)*(short *)(iVar3 + 0x32);
      if (*(int *)(param_1 + 0x1d18) < 3) {
        iStack_40 = 0x5297cf;
        iVar2 = _ftol_nocw();
      }
      fStack_4c = *(float *)(param_1 + 0x1f1c);
      iStack_40 = 2;
      fStack_48 = *(float *)(param_1 + 0x1f1c) - (float)(int)*(short *)(iVar3 + 0x30);
      iStack_50 = 0x5297f6;
      iStack_44 = iVar2;
      FUN_00532670();
      iStack_40 = DAT_006f80f8;
      iStack_44 = 0;
      fStack_48 = (float)DAT_006f80f4;
      fStack_4c = 7.58506e-39;
      FUN_00532610();
      return;
    }
    break;
  case 5:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      *(undefined4 *)(param_1 + 0x1d14) = 6;
      iStack_40 = 0x529853;
      fVar6 = (float10)FUN_00532640();
      iStack_40 = 0;
      iStack_44 = 0x44480000;
      fStack_48 = 0.0;
      fStack_4c = (float)ABS(fVar6);
      iStack_50 = 0x529867;
      bClampF();
      iStack_44 = 0x52986f;
      iStack_44 = _ftol_nocw();
      fStack_4c = *(float *)(param_1 + 0x1f1c);
      fStack_48 = *(float *)(param_1 + 0x1f20);
      iStack_50 = 0x529885;
      FUN_00532670();
      iStack_40 = *(undefined4 *)(param_1 + 0x1f90);
      iStack_44 = 0x529897;
      FUN_00584310();
      return;
    }
    break;
  case 6:
    if (*(char *)(param_1 + 0x1c0c) != '\0') {
      iStack_40 = 0x5298b1;
      EAXTunerCar__CleanUpShiftFX();
    }
  }
  return;
}


// ==== 0x5298e0 EAXTunerCar::BeginDownShift

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTunerCar__BeginDownShift(undefined4 param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[0x794] != 0) {
    FUN_005326f0(param_1);
    FUN_005326f0(param_1);
    if ((char)unaff_ESI[0x774] != '\0') {
      EAXTunerCar__CleanUpShiftFX();
      return;
    }
    iVar1 = _ftol_nocw();
    unaff_ESI[0x693] = iVar1;
    unaff_ESI[0x694] = 0x96;
    iVar1 = _ftol_nocw();
    unaff_ESI[0x68f] = iVar1;
    (**(code **)(*unaff_ESI + 0x38))(unaff_ESI + 0x68f,1);
    unaff_ESI[0x690] = *(int *)(&DAT_006b6630 + unaff_ESI[0x755] * 4);
  }
  return;
}


// ==== 0x529970 FUN_00529970

void FUN_00529970(void)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int *in_EAX;
  
  cVar3 = (**(code **)(*in_EAX + 0x60))(3);
  if ((cVar3 != '\0') && (in_EAX[0x746] < 5)) {
    in_EAX[0x794] = 1;
    FUN_00532640();
    FUN_00532670(0x41b80000,0,1000,0);
    in_EAX[0x773] = 0x41b80000;
    iVar1 = *(int *)(&DAT_006b6628 + in_EAX[0x755] * 4);
    uVar2 = *(undefined4 *)(&DAT_006b6638 + in_EAX[0x755] * 4);
    FUN_00532640();
    FUN_00532670((float)iVar1,0,uVar2,0);
    in_EAX[0x792] = (int)(float)iVar1;
  }
  return;
}


// ==== 0x529a00 EAXTunerCar::CleanUpShiftFX

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTunerCar__CleanUpShiftFX(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x1e50) = 0;
  *(undefined4 *)(in_EAX + 0x1a3c) = 0;
  *(undefined4 *)(in_EAX + 0x1a40) = 0;
  *(undefined4 *)(in_EAX + 0x1d14) = 0;
  FUN_00584310(*(undefined4 *)(in_EAX + 0x1f8c));
  return;
}


// ==== 0x529a30 FUN_00529a30

void FUN_00529a30(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX[0x5d8] != 0) {
    iVar1 = in_EAX[0x694];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(in_EAX[0x5d8] + 0x38) = iVar1;
    iVar1 = in_EAX[0x693];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(in_EAX[0x5d8] + 0x34) = iVar1;
    iVar1 = in_EAX[0x691];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(in_EAX[0x5d8] + 0x2c) = iVar1;
    iVar1 = in_EAX[0x692];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(in_EAX[0x5d8] + 0x30) = iVar1;
    (**(code **)(*in_EAX + 0x38))(in_EAX + 0x68f,1);
    iVar1 = in_EAX[0x68f];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(in_EAX[0x5d8] + 0x3c) = iVar1;
    iVar1 = in_EAX[0x690];
    if (iVar1 < 0) {
      *(undefined4 *)(in_EAX[0x5d8] + 0x40) = 0;
      return;
    }
    if (0x1000 < iVar1) {
      iVar1 = 0x1000;
    }
    *(int *)(in_EAX[0x5d8] + 0x40) = iVar1;
  }
  return;
}


// ==== 0x529b20 EAXTunerCar::IsEngineFinishedLoading

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __fastcall EAXTunerCar__IsEngineFinishedLoading(int param_1)

{
  int iStack_4;
  
  if (*(int **)(param_1 + 0x1760) != (int *)0x0) {
    iStack_4 = 0;
    if (**(int **)(param_1 + 0x1760) != 0) {
      Csis__Class__GetRefCount(&iStack_4);
      if (5 < iStack_4) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x529b60 EAXTunerCar::InitializeEngine

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__InitializeEngine(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *unaff_EBX;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684e2b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  Csis__System__GetAllocator(&local_10);
  Mutex__Lock();
  piVar2 = (int *)(**(code **)*local_10)(0x50,4,0xffffffff);
  Mutex__Unlock();
  local_10 = (undefined4 *)0x0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1ef4);
    iVar5 = *(int *)(param_1 + 0x264);
    iVar4 = *(int *)(param_1 + 0x1efc);
    piVar1 = piVar2 + 1;
    *piVar1 = 0;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (7 < iVar3) {
      iVar3 = 7;
    }
    piVar2[2] = iVar3;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (4 < iVar4) {
      iVar4 = 4;
    }
    piVar2[3] = iVar4;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (3 < iVar5) {
      iVar5 = 3;
    }
    piVar2[4] = iVar5;
    piVar2[5] = 0;
    piVar2[6] = 0;
    piVar2[7] = 0;
    piVar2[8] = 0;
    piVar2[9] = 0;
    piVar2[10] = 0;
    piVar2[0xb] = 0;
    piVar2[0xc] = 0;
    piVar2[0xd] = 0;
    piVar2[0xe] = 0;
    piVar2[0xf] = 0;
    piVar2[0x10] = 0;
    piVar2[0x11] = 0;
    piVar2[0x12] = 0;
    piVar2[0x13] = 0;
    iVar3 = Csis__Class__CreateInstance(&DAT_007441c8,piVar1,piVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_PLAYER_CAR_006f8158);
      Csis__Class__CreateInstance(&DAT_007441c8,piVar1,piVar2);
    }
  }
  *(int **)(param_1 + 0x1760) = piVar2;
  local_10 = (undefined4 *)0xffffffff;
  if (*piVar2 == 0) {
    _DAT_00735650 = 0;
    ExceptionList = unaff_EBX;
    return;
  }
  Csis__Class__GetRefCount(&stack0xffffffe0);
  _DAT_00735650 = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x529cd0 FUN_00529cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00529cd0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_1[0x8e] = (int)*(short *)(param_1[0x7c3] + 10);
  iVar5 = (int)*(short *)(param_1[0x7c3] + 0xc);
  piVar1 = param_1 + 0x8e;
  piVar2 = param_1 + 0x8f;
  *piVar2 = iVar5;
  *piVar2 = (&DAT_006f7220)[param_1[0xab] / 2] * iVar5 >> 0xf;
  *piVar1 = (&DAT_006f7220)[(0x400 - param_1[0xab]) / 2] * *piVar1 >> 0xf;
  iVar5 = param_1[0x639];
  if (iVar5 != 0) {
    *piVar2 = *piVar2 + iVar5;
    *piVar1 = *piVar1 + iVar5;
  }
  if ((float)param_1[0x637] != 0.0) {
    if (param_1[0xac] == 2) {
      if (0 < *piVar1 - *piVar2) {
        iVar3 = _ftol_nocw();
        iVar5 = *piVar1;
        *piVar1 = iVar5 + iVar3;
        if (iVar5 + iVar3 != 0) {
          iVar5 = _ftol_nocw();
          *piVar2 = iVar5;
        }
      }
    }
    else {
      iVar5 = *piVar1;
      if (0 < *piVar2 - iVar5) {
        iVar3 = _ftol_nocw();
        *piVar1 = iVar3 + iVar5;
      }
    }
  }
  if ((char)param_1[0x741] == '\0') {
    FUN_005326f0(param_1[0x91]);
    iVar5 = *piVar1;
    iVar4 = _ftol_nocw();
    iVar3 = *piVar2;
    *piVar1 = iVar4 + iVar5;
    iVar5 = _ftol_nocw();
    *piVar2 = iVar5 + iVar3;
  }
  if ((((*(int *)(*(int *)(param_1[0x8d] + 0x14) + 4) == 1) &&
       (*(char *)(*(int *)(param_1[0x8d] + 0x14) + 0x734) == '\0')) && (param_1[0xac] != 2)) &&
     ((float)param_1[0x472] < _K_ONE)) {
    iVar5 = _ftol_nocw();
    *piVar1 = iVar5;
    iVar5 = _ftol_nocw();
    *piVar2 = iVar5;
  }
  (**(code **)(*param_1 + 0x38))(piVar1,1);
  (**(code **)(*param_1 + 0x38))(piVar2,1);
  return;
}


// ==== 0x529ea0 FUN_00529ea0

void __fastcall FUN_00529ea0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18e8);
  if (iVar1 == 0) {
    FUN_0052a260();
    return;
  }
  if (iVar1 == 2) {
    cVar2 = EAXTunerCar__ShouldUpShiftDynLd();
    if (cVar2 == '\0') {
      FUN_0052a0f0();
    }
    goto LAB_00529f17;
  }
  if (iVar1 != 3) {
    if (iVar1 == 5) {
      if (*(char *)(param_1 + 0x17e0) != '\0') {
        *(undefined4 *)(param_1 + 0x18e8) = 0;
      }
      goto LAB_00529f17;
    }
    cVar2 = FUN_00529fb0();
    if (cVar2 != '\0') {
      FUN_0052a190(1);
      goto LAB_00529f17;
    }
  }
  cVar2 = FUN_0052a000();
  if (cVar2 != '\0') {
    FUN_0052a260();
  }
LAB_00529f17:
  FUN_005326f0(*(undefined4 *)(param_1 + 0x244));
  *(undefined4 *)(param_1 + 0x18dc) = *(undefined4 *)(param_1 + 0x17dc);
  uVar3 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x18e4) = uVar3;
  return;
}


// ==== 0x529f50 EAXTunerCar::ShouldUpShiftDynLd

/* [canon] audio low (ghidra) docs/re/sound.md */

uint EAXTunerCar__ShouldUpShiftDynLd(void)

{
  float fVar1;
  float fVar2;
  uint in_EAX;
  
  if (*(int *)(in_EAX + 0x18e8) != 2) {
    fVar1 = *(float *)(in_EAX + 0x1f1c);
    fVar2 = *(float *)(&DAT_006b6644 + *(int *)(in_EAX + 0x1d18) * 4);
    in_EAX = CONCAT22((short)((uint)*(int *)(in_EAX + 0x1d18) >> 0x10),
                      (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                      (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 >= fVar2) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x529f80 FUN_00529f80

uint FUN_00529f80(void)

{
  float fVar1;
  uint in_EAX;
  
  if (*(int *)(in_EAX + 0x18e8) != 5) {
    fVar1 = *(float *)(in_EAX + 0x18dc);
    in_EAX = CONCAT22((short)(in_EAX >> 0x10),
                      (ushort)(fVar1 < 0.65) << 8 | (ushort)NAN(fVar1) << 10 |
                      (ushort)(fVar1 == 0.65) << 0xe);
    if (fVar1 < 0.65 || (fVar1 == 0.65) != 0) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x529fb0 FUN_00529fb0

uint __fastcall FUN_00529fb0(int param_1)

{
  float fVar1;
  float fVar2;
  uint in_EAX;
  undefined2 uVar3;
  
  if (*(int *)(param_1 + 0x18e8) != 3) {
    fVar1 = *(float *)(param_1 + 0x1f1c);
    fVar2 = *(float *)(&DAT_006b6644 + *(int *)(param_1 + 0x1d18) * 4);
    uVar3 = (undefined2)((uint)*(int *)(param_1 + 0x1d18) >> 0x10);
    in_EAX = CONCAT22(uVar3,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                            | (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 < fVar2) {
LAB_00529ff6:
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
    in_EAX = CONCAT31((int3)(in_EAX >> 8),*(char *)(param_1 + 0x1f10));
    if (*(char *)(param_1 + 0x1f10) == '\0') {
      fVar2 = *(float *)(param_1 + 0x1f14) + 0.5;
      fVar1 = *(float *)(param_1 + 0x240);
      in_EAX = CONCAT22(uVar3,(ushort)(fVar2 < fVar1) << 8 |
                              (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                              (ushort)(fVar2 == fVar1) << 0xe);
      if (fVar2 < fVar1) goto LAB_00529ff6;
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x52a000 FUN_0052a000

uint __fastcall FUN_0052a000(int param_1)

{
  float fVar1;
  float fVar2;
  uint in_EAX;
  
  if (*(int *)(param_1 + 0x18e8) != 1) {
    fVar1 = *(float *)(param_1 + 0x1f1c);
    fVar2 = *(float *)(&DAT_006b6644 + *(int *)(param_1 + 0x1d18) * 4);
    in_EAX = CONCAT22((short)((uint)*(int *)(param_1 + 0x1d18) >> 0x10),
                      (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                      (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 >= fVar2) {
      return CONCAT31((int3)(in_EAX >> 8),*(char *)(param_1 + 0x1f10) != '\0');
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x52a040 FUN_0052a040

float10 __fastcall FUN_0052a040(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  if (*(int *)(param_2 + 0x1d18) == 1) {
    iVar2 = *(int *)(*(int *)(param_2 + 0x234) + 0x20);
    fVar1 = *(float *)(iVar2 + 0x1d8);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_2 + 0x234) + 0x20);
    fVar1 = *(float *)(iVar2 + 0x1d0 + *(int *)(param_2 + 0x1d18) * 4);
  }
  fVar3 = ABS((float10)fVar1);
  if (fVar3 < (float10)0.01) {
    fVar3 = (float10)*(float *)(iVar2 + 0x1d8);
  }
  return ((float10)*(float *)(*(int *)(param_2 + 0x1f0c) + 0x40) / fVar3) * (float10)1000.0;
}


// ==== 0x52a0a0 FUN_0052a0a0

void FUN_0052a0a0(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x18dc);
  *(undefined4 *)(in_EAX + 0x18e8) = 2;
  FUN_00532640();
  FUN_00532670(uVar1,uVar1,0,0);
  *(undefined4 *)(in_EAX + 0x17dc) = uVar1;
  return;
}


// ==== 0x52a0f0 FUN_0052a0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052a0f0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int extraout_EDX;
  undefined4 uVar2;
  undefined4 local_4;
  
  *(undefined4 *)(param_2 + 0x18e8) = 1;
  local_4 = *(float *)(param_2 + 0x18dc) - *(float *)(*(int *)(param_2 + 0x1f0c) + 0x44);
  if (local_4 <= 0.0) {
    local_4 = 0.0;
  }
  else if (_K_ONE < local_4) {
    local_4 = 1.0;
  }
  FUN_0052a040();
  FUN_00532640();
  uVar2 = 0;
  uVar1 = _ftol_nocw(0);
  FUN_00532670(local_4,0x3f800000,uVar1,uVar2);
  *(float *)(extraout_EDX + 0x17dc) = local_4;
  return;
}


// ==== 0x52a190 FUN_0052a190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052a190(char param_1)

{
  int in_EAX;
  undefined4 uVar1;
  
  *(undefined4 *)(in_EAX + 0x18e8) = 3;
  if ((*(float *)(in_EAX + 0x18dc) <= 0.7) || (param_1 == '\0')) {
    _param_1 = *(float *)(in_EAX + 0x18dc);
  }
  else {
    _param_1 = *(float *)(in_EAX + 0x18dc) - 0.1;
  }
  if (_param_1 <= 0.0) {
    _param_1 = 0.0;
  }
  else if (_K_ONE < _param_1) {
    _param_1 = 1.0;
  }
  uVar1 = _ftol_nocw();
  FUN_00532640();
  FUN_00532670(_param_1,0,uVar1,0);
  *(float *)(in_EAX + 0x17dc) = _param_1;
  return;
}


// ==== 0x52a260 FUN_0052a260

void __fastcall FUN_0052a260(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_EDX;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_2 + 0x18dc);
  *(undefined4 *)(param_2 + 0x18e8) = 1;
  FUN_0052a040();
  FUN_00532640();
  uVar3 = 0;
  uVar2 = _ftol_nocw(0);
  FUN_00532670(uVar1,0x3f800000,uVar2,uVar3);
  *(undefined4 *)(extraout_EDX + 0x17dc) = uVar1;
  return;
}


// ==== 0x52a2c0 FUN_0052a2c0

void FUN_0052a2c0(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x18dc);
  *(undefined4 *)(in_EAX + 0x18e8) = 5;
  FUN_00532640();
  FUN_00532670(uVar1,0x3f266666,DAT_006f80f8,0);
  *(undefined4 *)(in_EAX + 0x17dc) = uVar1;
  return;
}


// ==== 0x52a310 EAXTunerCar::BreakingEffectUpdate

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__BreakingEffectUpdate(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *unaff_ESI;
  int *unaff_EDI;
  int iStack_14;
  int *piStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (unaff_ESI[0x5d4] == 0) {
    ExceptionList = &pvStack_c;
    cVar2 = EAXTunerCar__ShouldDoBreakingEffect();
    if (cVar2 != '\0') {
      piVar1 = unaff_ESI + 0x5d5;
      PTR_s_CSISSOUND_006f8714 = s_SND__Breaking_Effect_006bf034;
      *piVar1 = DAT_006f4ecc;
      (**(code **)(*unaff_ESI + 0x38))(piVar1,8);
      _DAT_0070591c = *(float *)(unaff_ESI[0x8d] + 0x3d4) * 2.237;
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      iVar3 = _ftol_nocw();
      piVar4 = (int *)unaff_ESI[0x5d4];
      if (piVar4 != (int *)0x0) {
        if (*piVar4 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&stack0xffffffe4);
        Mutex__Lock();
        (**(code **)(*unaff_EDI + 4))(piVar4);
        Mutex__Unlock();
      }
      unaff_ESI[0x5d4] = 0;
      Csis__System__GetAllocator(&stack0xffffffe4);
      Mutex__Lock();
      piVar4 = (int *)(**(code **)*unaff_EDI)(0x1c,4,0xffffffff);
      Mutex__Unlock();
      uStack_4 = 0;
      piStack_10 = piVar4;
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        iVar5 = *piVar1;
        piVar1 = piVar4 + 1;
        *piVar1 = 0;
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        else if (0x7fff < iVar5) {
          iVar5 = 0x7fff;
        }
        piVar4[2] = iVar5;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        else if (0x1fff < iVar3) {
          iVar3 = 0x1fff;
        }
        piVar4[3] = iVar3;
        piVar4[4] = 0;
        piVar4[5] = 0;
        piVar4[6] = 0;
        iVar3 = Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
        if (iVar3 < 0) {
          Csis__ClassHandle__Set(&PTR_s_FX_SHIFTING_01_006f2240);
          Csis__Class__CreateInstance(&DAT_0073d804,piVar1,piVar4);
        }
      }
      uStack_4 = 0xffffffff;
      unaff_ESI[0x5d4] = (int)piVar4;
    }
  }
  if (unaff_ESI[0x5d4] != 0) {
    iVar3 = unaff_ESI[0x1b];
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0xffff < iVar3) {
      iVar3 = 0xffff;
    }
    *(int *)(unaff_ESI[0x5d4] + 0x10) = iVar3;
    piVar1 = unaff_ESI + 0x5d5;
    *piVar1 = DAT_006f4ecc;
    (**(code **)(*unaff_ESI + 0x38))(piVar1,8);
    iVar3 = *piVar1;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0x7fff < iVar3) {
      iVar3 = 0x7fff;
    }
    *(int *)(unaff_ESI[0x5d4] + 8) = iVar3;
    if (*(int *)unaff_ESI[0x5d4] != 0) {
      FUN_0064bc30((int *)unaff_ESI[0x5d4] + 1);
    }
    iStack_14 = 0;
    if (*(int *)unaff_ESI[0x5d4] != 0) {
      Csis__Class__GetRefCount(&iStack_14);
      if (iStack_14 == 1) {
        piVar1 = (int *)unaff_ESI[0x5d4];
        if (piVar1 != (int *)0x0) {
          if (*piVar1 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&piStack_10);
          Mutex__Lock();
          (**(code **)(*piStack_10 + 4))(piVar1);
          Mutex__Unlock();
        }
        unaff_ESI[0x5d4] = 0;
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x52a580 EAXTunerCar::ShouldDoBreakingEffect

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 EAXTunerCar__ShouldDoBreakingEffect(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  undefined2 uVar5;
  undefined4 uVar4;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x234) + 0x30);
  uVar5 = (undefined2)((uint)iVar1 >> 0x10);
  fVar3 = *(float *)(iVar1 + 0x1e4);
  if (*(float *)(iVar1 + 0x1e4) <= *(float *)(iVar1 + 0x1e0)) {
    fVar3 = *(float *)(iVar1 + 0x1e0);
  }
  fVar2 = *(float *)(*(int *)(in_EAX + 0x234) + 0x3d4) * 2.237;
  uVar4 = CONCAT22(uVar5,(ushort)(fVar2 < 20.0) << 8 | (ushort)NAN(fVar2) << 10 |
                         (ushort)(fVar2 == 20.0) << 0xe);
  if ((fVar2 >= 20.0) &&
     (uVar4 = CONCAT22(uVar5,(ushort)(fVar3 < _K_HALF) << 8 |
                             (ushort)(NAN(fVar3) || NAN(_K_HALF)) << 10 |
                             (ushort)(fVar3 == _K_HALF) << 0xe), fVar3 >= _K_HALF)) {
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  }
  return uVar4;
}


// ==== 0x52a5e0 FUN_0052a5e0

void FUN_0052a5e0(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 3) = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  *puVar1 = &PTR_FUN_006bef50;
  unaff_ESI[0x8d] = 0;
  unaff_ESI[0x8c] = 0;
  unaff_ESI[0x8f] = 0;
  unaff_ESI[0x8e] = 0;
  unaff_ESI[0x92] = 0xffffffff;
  unaff_ESI[0x93] = 0xffffffff;
  *unaff_ESI = &PTR_FUN_006bef7c;
  return;
}


// ==== 0x52a630 FUN_0052a630

void * __thiscall FUN_0052a630(void *param_1,byte param_2)

{
  FUN_0052a650();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52a650 FUN_0052a650

void __fastcall FUN_0052a650(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684e0f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006bef7c;
  param_1[8] = &PTR_FUN_006bef50;
  piVar1 = (int *)param_1[0x8d];
  local_4 = 1;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0x8c];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0x8f];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  piVar1 = (int *)param_1[0x8e];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_FUN_006bee78;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x52a780 FUN_0052a780

void __thiscall FUN_0052a780(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_007361f0;
  if ((DAT_007361f0 != (int *)0x0) && (*DAT_007361f0 == 8)) {
    *param_2 = 0;
    return;
  }
  *param_2 = *(int *)(param_1 + 0x70) * *param_2 >> 0xf;
  if (param_4 < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *param_2 = 0;
    }
    if ((piVar2 != (int *)0x0) && ((iVar1 = *piVar2, iVar1 == 1 || (iVar1 == 7)))) {
      *param_2 = 0;
    }
    *param_2 = *(int *)(param_4 * 0xd10 + 0x988 + DAT_007356ac) * *param_2 >> 0xf;
  }
  return;
}


// ==== 0x52a810 FUN_0052a810

void __thiscall FUN_0052a810(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x10) = param_3;
  *(int *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 0xc) = 1;
  *(int *)(param_1 + 8) = param_3 * 100 + *(int *)(param_2 + 0x1f08);
  iVar2 = DAT_007356a8;
  *(undefined **)(param_1 + 0xdc) = &DAT_006f4490;
  *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*(int *)(param_1 + 0x20) + 0x24))();
  iVar2 = *(int *)(param_1 + 0xdc);
  if (iVar2 != 0) {
    iVar1 = EAXSound__GetMasterVolume();
    iVar2 = iVar1 * **(int **)(iVar2 + 0x60) >> 0xf;
    *(int *)(param_1 + 0xc4) = iVar2;
    *(int *)(param_1 + 200) = iVar2;
  }
  return;
}


// ==== 0x52a890 EAXRoadNoise::Update

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXRoadNoise__Update(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  int *piVar5;
  int iVar6;
  int unaff_EBX;
  undefined4 unaff_EBP;
  int *piVar7;
  int iVar8;
  char cVar9;
  int local_10;
  int local_c;
  int *local_8;
  int *local_4;
  
  if ((DAT_006f1dd8 != 0) && ((char)in_EAX[3] != '\0')) {
    iVar8 = in_EAX[1];
    iVar4 = *(int *)(iVar8 + 0x234);
    bVar1 = true;
    if ((*(char *)(iVar4 + 0x350) == '\0') && (*(char *)(iVar4 + 0x353) == '\0')) {
      bVar1 = false;
    }
    bVar2 = true;
    if ((*(char *)(iVar4 + 0x351) == '\0') && (*(char *)(iVar4 + 0x352) == '\0')) {
      bVar2 = false;
    }
    local_c = iVar8;
    if (*(char *)(iVar8 + 0x12e8) != '\0') {
      iVar4 = FUN_0052cea0();
      in_EAX[0x93] = iVar4;
      if ((iVar4 == 5) && (in_EAX[0x92] == 5)) {
        in_EAX[0x93] = 6;
      }
      piVar5 = (int *)FUN_0052cf20();
      iVar4 = *(int *)(iVar8 + 0x12e0);
      if ((iVar4 == 1) || ((iVar4 != 0xb && (iVar4 != 0x10)))) {
        piVar7 = (int *)0xffffffff;
      }
      else {
        piVar7 = (int *)0x1;
      }
      local_4 = piVar5;
      if (in_EAX[0x93] == -1) {
        piVar5 = (int *)in_EAX[0x8d];
        if (piVar5 != (int *)0x0) {
          if (*piVar5 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&local_8);
          Mutex__Lock();
          (**(code **)(*local_8 + 4))(piVar5);
          Mutex__Unlock();
        }
        in_EAX[0x8d] = 0;
        piVar5 = local_4;
      }
      else {
        EAXRoadNoise__Play(in_EAX,1);
        EAXRoadNoise__SendEnvelopeToMixer(in_EAX);
      }
      if ((bVar1) &&
         ((piVar7 != (int *)0xffffffff || (piVar7 = piVar5, piVar5 != (int *)0xffffffff)))) {
        EAXRoadNoise__PlayTransition(in_EAX,piVar7,1);
      }
    }
    if (*(char *)(iVar8 + 0x12e9) != '\0') {
      iVar4 = FUN_0052cea0();
      iVar8 = local_c;
      in_EAX[0x92] = iVar4;
      if ((in_EAX[0x92] == 5) && (in_EAX[0x93] == 5)) {
        in_EAX[0x92] = 6;
      }
      iVar4 = FUN_0052cf20();
      iVar8 = *(int *)(iVar8 + 0x12e4);
      if ((iVar8 == 1) || ((iVar8 != 0xb && (iVar8 != 0x10)))) {
        iVar8 = -1;
      }
      else {
        iVar8 = 1;
      }
      if (in_EAX[0x92] == -1) {
        piVar5 = (int *)in_EAX[0x8c];
        if (piVar5 != (int *)0x0) {
          if (*piVar5 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&local_4);
          Mutex__Lock();
          (**(code **)(*local_4 + 4))(piVar5);
          Mutex__Unlock();
        }
        in_EAX[0x8c] = 0;
      }
      else {
        EAXRoadNoise__Play(in_EAX,0);
        EAXRoadNoise__SendEnvelopeToMixer(in_EAX);
      }
      if ((bVar2) && ((iVar8 != -1 || (iVar8 = iVar4, iVar4 != -1)))) {
        EAXRoadNoise__PlayTransition(in_EAX,iVar8,0);
      }
    }
    iVar3 = local_c;
    EAXS_3DMixer__Update3DMix(local_c + 0x14e0,0);
    local_10 = *(int *)(&DAT_006f4ea8 + in_EAX[0x93] * 4) * *(int *)(iVar3 + 0x14b0) >> 0xf;
    iVar8 = *(int *)(in_EAX[1] + 0x264);
    iVar4 = *(int *)(iVar3 + 0x14b8);
    cVar9 = '\0';
    piVar5 = &local_10;
    (**(code **)(*in_EAX + 8))();
    iVar6 = *(int *)(DAT_007356ac + 0x3e18) * unaff_EBX >> 0xf;
    if (*(int *)(in_EAX[1] + 0x2b0) == 2) {
      iVar6 = iVar6 * 8000 >> 0xf;
    }
    if ((char)((uint)unaff_EBP >> 0x10) == '\0') {
      iVar6 = 0;
    }
    if (in_EAX[0x8d] != 0) {
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      else if (0x7fff < iVar6) {
        iVar6 = 0x7fff;
      }
      *(int *)(in_EAX[0x8d] + 8) = iVar6;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0x1fff < iVar4) {
        iVar4 = 0x1fff;
      }
      *(int *)(in_EAX[0x8d] + 0xc) = iVar4;
      iVar4 = in_EAX[0x1b];
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0xffff < iVar4) {
        iVar4 = 0xffff;
      }
      *(int *)(in_EAX[0x8d] + 0x10) = iVar4;
      if (*(int *)in_EAX[0x8d] != 0) {
        FUN_0064bc30((int *)in_EAX[0x8d] + 1);
      }
    }
    if (in_EAX[0x8f] != 0) {
      iVar4 = in_EAX[0x90] * in_EAX[0x1c] >> 0xf;
      (**(code **)(*in_EAX + 8))(&stack0xffffffe8,8,*(undefined4 *)(in_EAX[1] + 0x264));
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0x7fff < iVar4) {
        iVar4 = 0x7fff;
      }
      *(int *)(in_EAX[0x8f] + 8) = iVar4;
      if (*(int *)in_EAX[0x8f] != 0) {
        FUN_0064bc30((int *)in_EAX[0x8f] + 1);
      }
    }
    EAXS_3DMixer__Update3DMix(iVar3 + 0x14f0,0);
    (**(code **)(*in_EAX + 8))(&stack0xffffffe4,8,*(undefined4 *)(in_EAX[1] + 0x264));
    iVar4 = *(int *)(iVar3 + 0x14b4);
    iVar8 = *(int *)(DAT_007356ac + 0x3e18) * iVar8 >> 0xf;
    if (*(int *)(in_EAX[1] + 0x2b0) == 2) {
      iVar8 = iVar8 * 8000 >> 0xf;
    }
    if (cVar9 == '\0') {
      iVar8 = 0;
    }
    if (in_EAX[0x8c] != 0) {
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (0x7fff < iVar8) {
        iVar8 = 0x7fff;
      }
      *(int *)(in_EAX[0x8c] + 8) = iVar8;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0x1fff < iVar4) {
        iVar4 = 0x1fff;
      }
      *(int *)(in_EAX[0x8c] + 0xc) = iVar4;
      iVar8 = in_EAX[0x1b];
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (0xffff < iVar8) {
        iVar8 = 0xffff;
      }
      *(int *)(in_EAX[0x8c] + 0x10) = iVar8;
      if (*(int *)in_EAX[0x8c] != 0) {
        FUN_0064bc30((int *)in_EAX[0x8c] + 1);
      }
    }
    if (in_EAX[0x8e] != 0) {
      (**(code **)(*in_EAX + 8))(&stack0xffffffdc,8,*(undefined4 *)(in_EAX[1] + 0x264));
      if ((int)piVar5 < 0) {
        piVar5 = (int *)0x0;
      }
      else if (0x7fff < (int)piVar5) {
        piVar5 = (int *)0x7fff;
      }
      *(int **)(in_EAX[0x8e] + 8) = piVar5;
      if (*(int *)in_EAX[0x8e] != 0) {
        FUN_0064bc30((int *)in_EAX[0x8e] + 1);
      }
    }
    if ((*(int *)(iVar3 + 0x12d8) == 8) || (*(int *)(iVar3 + 0x12d8) == 9)) {
      *(undefined4 *)(in_EAX[0x8d] + 0x18) = 1;
    }
    if ((*(int *)(iVar3 + 0x12dc) == 8) || (*(int *)(iVar3 + 0x12dc) == 9)) {
      *(undefined4 *)(in_EAX[0x8c] + 0x18) = 1;
    }
  }
  return;
}


// ==== 0x52adf0 EAXRoadNoise::PlayTransition

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXRoadNoise__PlayTransition(int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00685a36;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && ((char)param_1[3] != '\0')) {
    _DAT_007058ac = (int *)(*(float *)(*(int *)(param_1[1] + 0x234) + 0x3d4) * 2.237);
    ExceptionList = &local_c;
    local_10 = _DAT_007058ac;
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    iVar3 = _ftol_nocw();
    switch(param_2) {
    case 0:
    case 1:
      iVar4 = 12000;
      break;
    case 2:
    case 3:
      iVar4 = 0x5fb4;
      break;
    default:
      iVar4 = 0x7fff;
    }
    iVar3 = iVar4 * iVar3 >> 0xf;
    _DAT_007058c8 = local_10;
    param_1 = (int *)iVar3;
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    _ftol_nocw();
    if ((char)param_3 == '\0') {
      piVar2[0x91] = iVar3;
      EAXS_3DMixer__Update3DMix(piVar2[1] + 0x14f0,0);
      (**(code **)(*piVar2 + 8))(&param_1,8,*(undefined4 *)(piVar2[1] + 0x264));
      piVar1 = (int *)piVar2[0x8e];
      PTR_s_CSISSOUND_006f8714 = s_Right_Road_Noise_Transition_006beffc;
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&local_10);
        Mutex__Lock();
        (**(code **)(*local_10 + 4))(piVar1);
        Mutex__Unlock();
      }
      param_3 = (int *)FUN_005256f0(0x1c);
      uStack_4 = 1;
      if (param_3 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = Csis_CreateRoadNoiseSample(1,0);
      }
      piVar2[0x8e] = iVar3;
    }
    else {
      piVar2[0x90] = iVar3;
      EAXS_3DMixer__Update3DMix(piVar2[1] + 0x14e0,0);
      (**(code **)(*piVar2 + 8))(&param_1,8,*(undefined4 *)(piVar2[1] + 0x264));
      piVar1 = (int *)piVar2[0x8f];
      PTR_s_CSISSOUND_006f8714 = s_Left_Road_Noise_Transition_006bf018;
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_3);
        Mutex__Lock();
        (**(code **)(*param_3 + 4))(piVar1);
        Mutex__Unlock();
      }
      param_3 = (int *)FUN_005256f0(0x1c);
      uStack_4 = 0;
      if (param_3 == (int *)0x0) {
        piVar2[0x8f] = 0;
      }
      else {
        iVar3 = Csis_CreateRoadNoiseSample(1,0);
        piVar2[0x8f] = iVar3;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x52b040 EAXRoadNoise::SendEnvelopeToMixer

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXRoadNoise__SendEnvelopeToMixer(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_64 [11];
  undefined4 uStack_38;
  undefined4 local_2c [6];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c[2] = 0;
  local_2c[1] = 0;
  local_2c[0] = 8;
  local_2c[3] = 1;
  local_8 = 0x42200000;
  local_4 = 0;
  local_2c[4] = 0;
  uStack_38 = 0x52b081;
  local_2c[5] = _ftol_nocw();
  uStack_38 = 0x52b096;
  local_14 = _ftol_nocw();
  uStack_38 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x264);
  local_10 = 0;
  local_c = 0;
  puVar2 = local_2c;
  puVar3 = auStack_64;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  EAXMixMgr__ReceiveTrigger(DAT_007356ac);
  return;
}


// ==== 0x52b0e0 EAXRoadNoise::Play

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXRoadNoise__Play(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar2 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684dd6;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && ((char)param_2[3] != '\0')) {
    if ((char)param_3 == '\0') {
      piVar1 = (int *)param_2[0x8c];
      PTR_s_CSISSOUND_006f8714 = s_Right_Road_Noise_006befd8;
      ExceptionList = &local_c;
      if (piVar1 != (int *)0x0) {
        ExceptionList = &local_c;
        if (*piVar1 != 0) {
          ExceptionList = &local_c;
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_2);
        Mutex__Lock();
        (**(code **)(*param_2 + 4))(piVar1);
        Mutex__Unlock();
      }
      iVar3 = FUN_005256f0(0x1c);
      uStack_4 = 1;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        if (param_1 < 0) {
          param_1 = 0;
        }
        else if (0xf < param_1) {
          param_1 = 0xf;
        }
        piVar1 = (int *)(iVar3 + 4);
        *piVar1 = param_1;
        *(undefined4 *)(iVar3 + 8) = 0;
        *(undefined4 *)(iVar3 + 0xc) = 0x1000;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(undefined4 *)(iVar3 + 0x14) = 0;
        *(undefined4 *)(iVar3 + 0x18) = 0;
        param_3 = (int *)iVar3;
        iVar4 = Csis__Class__CreateInstance(&DAT_00744230,piVar1,iVar3);
        if (iVar4 < 0) {
          Csis__ClassHandle__Set(&PTR_s_FX_ROADNOISE_006f81b8);
          Csis__Class__CreateInstance(&DAT_00744230,piVar1,iVar3);
        }
      }
      piVar2[0x8c] = iVar3;
    }
    else {
      piVar1 = (int *)param_2[0x8d];
      PTR_s_CSISSOUND_006f8714 = s_Left_Road_Noise_006befec;
      ExceptionList = &local_c;
      if (piVar1 != (int *)0x0) {
        ExceptionList = &local_c;
        if (*piVar1 != 0) {
          ExceptionList = &local_c;
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&param_3);
        Mutex__Lock();
        (**(code **)(*param_3 + 4))(piVar1);
        Mutex__Unlock();
      }
      iVar3 = FUN_005256f0(0x1c);
      uStack_4 = 0;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        if (param_1 < 0) {
          param_1 = 0;
        }
        else if (0xf < param_1) {
          param_1 = 0xf;
        }
        piVar1 = (int *)(iVar3 + 4);
        *piVar1 = param_1;
        *(undefined4 *)(iVar3 + 8) = 0;
        *(undefined4 *)(iVar3 + 0xc) = 0x1000;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(undefined4 *)(iVar3 + 0x14) = 0;
        *(undefined4 *)(iVar3 + 0x18) = 0;
        param_3 = (int *)iVar3;
        iVar4 = Csis__Class__CreateInstance(&DAT_00744230,piVar1,iVar3);
        if (iVar4 < 0) {
          Csis__ClassHandle__Set(&PTR_s_FX_ROADNOISE_006f81b8);
          Csis__Class__CreateInstance(&DAT_00744230,piVar1,iVar3);
          piVar2[0x8d] = iVar3;
          ExceptionList = local_c;
          return;
        }
      }
      piVar2[0x8d] = iVar3;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x52b2d0 EAXTunerCar::Refl_Update

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTunerCar__Refl_Update(undefined4 param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_1c [8];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (((*(int *)(DAT_007356a8 + 0xa0) == 0) ||
      (iVar1 = *(int *)(*(int *)(DAT_007356a8 + 0xa0) + 4), iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x188) != 1)) {
    FUN_00584270(*(undefined4 *)(in_EAX + 0x1f1c));
    if (DAT_0073563d != '\0') {
      DAT_0073563d = '\0';
      if (*(char *)(in_EAX + 0x1a84) == '\0') {
        EAXTunerCar__InitializeReflection();
        *(undefined1 *)(in_EAX + 0x1a8c) = 1;
      }
      else {
        EAXTunerCar__DestroyReflection();
        *(undefined1 *)(in_EAX + 0x1a8c) = 0;
      }
    }
    if (*(char *)(in_EAX + 0x1a8c) != '\0') {
      *(undefined4 *)(in_EAX + 0x1a7c) = 900;
      FUN_0052bc50(param_1);
      return;
    }
    iVar1 = *(int *)(in_EAX + 0x234);
    do {
      iVar5 = ZoneManager__FindFromTypeMask(&DAT_007372b0,iVar1 + 0x60,0x20);
      if (iVar5 == 0) {
        if (*(char *)(in_EAX + 0x1a84) != '\0') {
          if ((*(int *)(in_EAX + 0x1a88) == 1) &&
             (cVar4 = EAXTunerCar__ShouldPlayTunnelWoosh(), cVar4 != '\0')) {
            FUN_0052b8c0();
          }
          EAXTunerCar__DestroyReflection();
        }
        goto LAB_0052b4cd;
      }
    } while ((*(float *)(iVar5 + 0x14) != 0.0) &&
            (*(float *)(iVar5 + 0x14) < *(float *)(*(int *)(in_EAX + 0x234) + 0x68)));
    if (*(char *)(in_EAX + 0x1a84) == '\0') {
      *(undefined4 *)(in_EAX + 0x1a88) = *(undefined4 *)(iVar5 + 0x7c);
      cVar4 = EAXTunerCar__ShouldPlayTunnelWoosh();
      if (cVar4 != '\0') {
        FUN_0052b760();
      }
      EAXTunerCar__InitializeReflection();
    }
    local_8 = *(float *)(DAT_00740500 + 0x50);
    local_14 = *(float *)(DAT_00740500 + 0x54);
    local_10 = -local_8;
    local_c = -local_14;
    TrackPathZone__GetIntercept(iVar5,local_1c,*(int *)(in_EAX + 0x234) + 0x60);
    TrackPathZone__GetIntercept(iVar5,&local_14,*(int *)(in_EAX + 0x234) + 0x60);
    fVar2 = *(float *)(*(int *)(in_EAX + 0x234) + 0x60) - local_14;
    fVar3 = *(float *)(*(int *)(in_EAX + 0x234) + 100) - local_10;
    local_8 = SQRT(fVar2 * fVar2 + fVar3 * fVar3);
    if (*(char *)(in_EAX + 0x1a8c) == '\0') {
      uVar6 = _ftol_nocw();
      *(undefined4 *)(in_EAX + 0x1a7c) = uVar6;
    }
LAB_0052b4cd:
    EAXTunerCar__UpdateTunnelWoosh(param_1);
    if (*(char *)(in_EAX + 0x1a84) != '\0') {
      FUN_0052bc50(param_1);
    }
  }
  return;
}


// ==== 0x52b500 EAXTunerCar::Create_Reflection

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__Create_Reflection(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  piVar3 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684e6b;
  local_c = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    piVar2 = (int *)param_1[0x6e3];
    ExceptionList = &local_c;
    if (piVar2 != (int *)0x0) {
      ExceptionList = &local_c;
      if (*piVar2 != 0) {
        ExceptionList = &local_c;
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_1);
      Mutex__Lock();
      (**(code **)(*param_1 + 4))(piVar2);
      Mutex__Unlock();
    }
    piVar3[0x6e3] = 0;
    PTR_s_CSISSOUND_006f8714 = s_TUNNEL_Reflections_006befc4;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    iVar4 = (**(code **)*local_10)(0x50,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar5 = piVar3[0x7bd];
      iVar7 = piVar3[0x99];
      iVar6 = piVar3[0x7bf];
      puVar1 = (undefined4 *)(iVar4 + 4);
      *puVar1 = 0;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      else if (7 < iVar5) {
        iVar5 = 7;
      }
      *(int *)(iVar4 + 8) = iVar5;
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      else if (4 < iVar6) {
        iVar6 = 4;
      }
      *(int *)(iVar4 + 0xc) = iVar6;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      else if (3 < iVar7) {
        iVar7 = 3;
      }
      *(int *)(iVar4 + 0x10) = iVar7;
      *(undefined4 *)(iVar4 + 0x14) = 0;
      *(undefined4 *)(iVar4 + 0x18) = 0;
      *(undefined4 *)(iVar4 + 0x1c) = 0;
      *(undefined4 *)(iVar4 + 0x20) = 0;
      *(undefined4 *)(iVar4 + 0x24) = 0;
      *(undefined4 *)(iVar4 + 0x28) = 0;
      *(undefined4 *)(iVar4 + 0x2c) = 0;
      *(undefined4 *)(iVar4 + 0x30) = 0;
      *(undefined4 *)(iVar4 + 0x34) = 0;
      *(undefined4 *)(iVar4 + 0x38) = 0;
      *(undefined4 *)(iVar4 + 0x3c) = 0;
      *(undefined4 *)(iVar4 + 0x40) = 0;
      *(undefined4 *)(iVar4 + 0x44) = 0;
      *(undefined4 *)(iVar4 + 0x48) = 0;
      *(undefined4 *)(iVar4 + 0x4c) = 0;
      param_1 = (int *)iVar4;
      iVar5 = Csis__Class__CreateInstance(&DAT_007441c8,puVar1,iVar4);
      if (iVar5 < 0) {
        Csis__ClassHandle__Set(&PTR_s_PLAYER_CAR_006f8158);
        Csis__Class__CreateInstance(&DAT_007441c8,puVar1,iVar4);
      }
    }
    piVar3[0x6e3] = iVar4;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x52b690 EAXTunerCar::DestroyReflection

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__DestroyReflection(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EDI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_EDI + 0x1b8c);
  *(undefined1 *)(unaff_EDI + 0x1a84) = 0;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  uVar2 = DAT_007356ac;
  *(undefined4 *)(unaff_EDI + 0x1b8c) = 0;
  EAXMixMgr__EndMixType(uVar2,4,*(undefined4 *)(unaff_EDI + 0x264));
  return;
}


// ==== 0x52b700 EAXTunerCar::InitializeReflection

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTunerCar__InitializeReflection(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x1a84) == '\0') {
    FUN_00532640();
    FUN_00532670(0,0x3f800000,500,0);
    uVar1 = DAT_007356ac;
    *(undefined4 *)(unaff_ESI + 0x1b04) = 0;
    *(undefined1 *)(unaff_ESI + 0x1a84) = 1;
    EAXMixMgr__SetMixType(uVar1,4,0xbf800000,*(undefined4 *)(unaff_ESI + 0x264));
    EAXTunerCar__Create_Reflection(unaff_ESI);
  }
  return;
}


// ==== 0x52b760 FUN_0052b760

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052b760(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *unaff_EBX;
  void *unaff_ESI;
  undefined4 local_18 [3];
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (param_1[0x6e4] != 0) {
    ExceptionList = &pvStack_c;
    EAXTunerCar__DestroyTunnelWoosh();
  }
  local_18[0] = DAT_006f4f40;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  param_1[0x6e0] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x6e2) = 0;
  _DAT_00705970 = *(float *)(param_1[0x8d] + 0x3d4) * 2.237;
  EAX_linear_ramp_evaluate__not_SetCsisName_();
  puVar3 = local_18;
  (**(code **)(*param_1 + 0x38))(puVar3,9);
  Csis__System__GetAllocator(&stack0xffffffe4);
  Mutex__Lock();
  iVar2 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
  Mutex__Unlock();
  local_18[0] = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 0xb;
    if ((int)puVar3 < 0) {
      puVar3 = (undefined4 *)0x0;
    }
    else if (0x7fff < (int)puVar3) {
      puVar3 = (undefined4 *)0x7fff;
    }
    *(undefined4 **)(iVar2 + 8) = puVar3;
    *(undefined4 *)(iVar2 + 0xc) = 0x1000;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    iVar4 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar4 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0x6e4] = iVar2;
    ExceptionList = unaff_ESI;
    return;
  }
  param_1[0x6e4] = 0;
  ExceptionList = unaff_ESI;
  return;
}


// ==== 0x52b8c0 FUN_0052b8c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052b8c0(int *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  undefined4 local_18 [3];
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (param_1[0x6e4] != 0) {
    ExceptionList = &pvStack_c;
    EAXTunerCar__DestroyTunnelWoosh();
  }
  local_18[0] = DAT_006f4f40;
  FUN_00532640();
  FUN_00532670(0x3f800000,0x3f800000,1,0);
  param_1[0x6e0] = 0x3f800000;
  _DAT_00705970 = *(float *)(param_1[0x8d] + 0x3d4) * 2.237;
  EAX_linear_ramp_evaluate__not_SetCsisName_();
  puVar4 = local_18;
  *(undefined1 *)(param_1 + 0x6e2) = 0;
  (**(code **)(*param_1 + 0x38))(puVar4,9);
  if (DAT_00705978 != '\0') {
    EAX_linear_ramp_evaluate__not_SetCsisName_();
  }
  pvVar2 = (void *)_ftol_nocw();
  Csis__System__GetAllocator(&stack0xffffffe4);
  Mutex__Lock();
  iVar3 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
  Mutex__Unlock();
  local_18[0] = 0;
  if (iVar3 != 0) {
    puVar1 = (undefined4 *)(iVar3 + 4);
    *puVar1 = 0xc;
    if ((int)puVar4 < 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else if (0x7fff < (int)puVar4) {
      puVar4 = (undefined4 *)0x7fff;
    }
    *(undefined4 **)(iVar3 + 8) = puVar4;
    *(undefined4 *)(iVar3 + 0xc) = 0x1000;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    iVar5 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
    if (iVar5 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
    }
    param_1[0x6e4] = iVar3;
    ExceptionList = pvVar2;
    return;
  }
  param_1[0x6e4] = 0;
  ExceptionList = pvVar2;
  return;
}


// ==== 0x52ba50 EAXTunerCar::UpdateTunnelWoosh

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTunerCar__UpdateTunnelWoosh(undefined4 param_1)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_4;
  
  if (in_EAX[0x6e4] != 0) {
    cVar1 = EAXTunerCar__ShouldPlayTunnelWoosh();
    if (cVar1 == '\0') {
      FUN_00532640();
      FUN_00532670(0x3f800000,0,0x96,0);
      in_EAX[0x6e0] = 0x3f800000;
      *(undefined1 *)(in_EAX + 0x6e2) = 0;
    }
    FUN_005326f0(param_1);
    piVar4 = &local_4;
    local_4 = DAT_006f4f40;
    (**(code **)(*in_EAX + 0x38))(piVar4,9);
    iVar2 = _ftol_nocw();
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar2;
      if (0x7fff < iVar2) {
        iVar3 = 0x7fff;
      }
    }
    *(int *)(in_EAX[0x6e4] + 8) = iVar3;
    if (*(int *)in_EAX[0x6e4] != 0) {
      FUN_0064bc30((int *)in_EAX[0x6e4] + 1);
    }
    local_4 = 0;
    if (*(int *)in_EAX[0x6e4] != 0) {
      Csis__Class__GetRefCount(&local_4);
      if (local_4 == 1) {
        EAXTunerCar__DestroyTunnelWoosh(piVar4,iVar2);
      }
    }
  }
  return;
}


// ==== 0x52bb40 EAXTunerCar::DestroyTunnelWoosh

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__DestroyTunnelWoosh(void)

{
  int *piVar1;
  int unaff_EDI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_EDI + 0x1b90);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    *(undefined4 *)(unaff_EDI + 0x1b90) = 0;
  }
  return;
}


// ==== 0x52bb90 EAXTunerCar::ShouldPlayTunnelWoosh

/* [canon] audio med (ghidra) docs/re/sound.md */

uint EAXTunerCar__ShouldPlayTunnelWoosh(void)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int unaff_EDI;
  float fStack_3c;
  float fStack_38;
  float local_30;
  float fStack_24;
  
  iVar2 = *(int *)(unaff_EDI + 0x234);
  fVar1 = *(float *)(iVar2 + 0x3d4) * 2.237;
  if (fVar1 < 45.0) {
    return (uint)(ushort)((ushort)(fVar1 < 45.0) << 8 | (ushort)NAN(fVar1) << 10 |
                         (ushort)(fVar1 == 45.0) << 0xe);
  }
  bNormalize3();
  iVar2 = (**(code **)(**(int **)(iVar2 + 0x2c) + 0x18))(0);
  uVar3 = 0;
  if (iVar2 != 0) {
    bNormalize2();
    fVar1 = fStack_3c * fStack_24 + fStack_38 * local_30;
    uVar3 = (uint)(ushort)((ushort)(fVar1 < 0.8) << 8 | (ushort)NAN(fVar1) << 10 |
                          (ushort)(fVar1 == 0.8) << 0xe);
    if (fVar1 < 0.8) {
      return uVar3;
    }
  }
  return CONCAT31((int3)(uVar3 >> 8),*(int *)(unaff_EDI + 0x1a88) == 1);
}


// ==== 0x52bc50 FUN_0052bc50

void FUN_0052bc50(undefined4 param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 0x2b4) == 0) {
    *(undefined4 *)(in_EAX + 0x1a80) = 0;
  }
  else if (*(int *)(in_EAX + 0x2b0) == 2) {
    *(int *)(in_EAX + 0x1a80) = *(int *)(in_EAX + 0x238) * DAT_006f4ed8 >> 0xf;
  }
  else {
    *(int *)(in_EAX + 0x1a80) = *(int *)(in_EAX + 0x23c) * DAT_006f4ed8 >> 0xf;
  }
  if ((DAT_006f1dd8 != 0) && (*(int *)(in_EAX + 0x1b8c) != 0)) {
    FUN_005326f0(param_1);
    uVar1 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x1a80) = uVar1;
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *(undefined4 *)(in_EAX + 0x1a80) = 0;
    }
    iVar2 = *(int *)(in_EAX + 0x1a80);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*(int *)(in_EAX + 0x1b8c) + 0x28) = iVar2;
    iVar2 = _ftol_nocw();
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x400 < iVar2) {
      iVar2 = 0x400;
    }
    *(int *)(*(int *)(in_EAX + 0x1b8c) + 0x18) = iVar2;
    *(undefined4 *)(*(int *)(in_EAX + 0x1b8c) + 0x20) = 0x400;
    iVar2 = *(int *)(in_EAX + 0x2ac);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x400 < iVar2) {
      iVar2 = 0x400;
    }
    *(int *)(*(int *)(in_EAX + 0x1b8c) + 0x44) = iVar2;
    iVar2 = _ftol_nocw();
    iVar2 = 0xbfff - iVar2;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x10000 < iVar2) {
      iVar2 = 0x10000;
    }
    *(int *)(*(int *)(in_EAX + 0x1b8c) + 0x48) = iVar2;
    iVar2 = _ftol_nocw();
    iVar2 = iVar2 + -300;
    if (iVar2 < -0x3fff) {
      iVar2 = -0x3fff;
    }
    else if (0x3fff < iVar2) {
      iVar2 = 0x3fff;
    }
    *(int *)(*(int *)(in_EAX + 0x1b8c) + 0x4c) = iVar2;
    if (**(int **)(in_EAX + 0x1b8c) != 0) {
      FUN_0064bc30(*(int **)(in_EAX + 0x1b8c) + 1);
    }
  }
  return;
}


// ==== 0x52be40 FUN_0052be40

void FUN_0052be40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x234) + 0x28) != 1) {
    puVar2 = (undefined4 *)(param_1 + 8);
    iVar3 = 4;
    do {
      puVar2[1] = *puVar2;
      *puVar2 = 0;
      puVar2 = puVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  iVar3 = 0x38;
  puVar2 = (undefined4 *)(param_1 + 8);
  do {
    iVar1 = *(int *)(param_1 + 4);
    bMatrixCopy();
    iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x234) + 0x34) + iVar3);
    local_5c = *(undefined4 *)(iVar1 + 0x124);
    local_60 = *(undefined4 *)(iVar1 + 0x120);
    local_58 = *(undefined4 *)(iVar1 + 0x128);
    D3DXVec3Transform(&local_60,&local_60,local_50);
    puVar2[1] = *puVar2;
    *puVar2 = local_58;
    iVar3 = iVar3 + 4;
    puVar2 = puVar2 + 3;
  } while (iVar3 < 0x48);
  return;
}


// ==== 0x52bf10 FUN_0052bf10

void FUN_0052bf10(void)

{
  int unaff_ESI;
  
  FUN_0052be40(unaff_ESI + 0x19f4);
  if (*(char *)(unaff_ESI + 0x18f4) != '\0') {
    FUN_005326f0(*(undefined4 *)(unaff_ESI + 0x244));
    FUN_005326f0(*(undefined4 *)(unaff_ESI + 0x244));
    if ((*(char *)(unaff_ESI + 0x1970) != '\0') && (*(char *)(unaff_ESI + 0x19ec) != '\0')) {
      *(undefined1 *)(unaff_ESI + 0x18f4) = 0;
    }
  }
  return;
}


// ==== 0x52bf70 FUN_0052bf70

void __fastcall FUN_0052bf70(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1760) != 0) {
    iVar1 = *(int *)(param_1 + 0x238);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x24) = iVar1;
    iVar1 = *(int *)(param_1 + 0x23c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x28) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x14) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x18) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x1c) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x20) = iVar1;
    iVar1 = *(int *)(param_1 + 0x2ac);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x400 < iVar1) {
      iVar1 = 0x400;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x44) = iVar1;
    iVar1 = *(int *)(param_1 + 0x6c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x10000 < iVar1) {
      iVar1 = 0x10000;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x48) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < -0x3fff) {
      iVar1 = -0x3fff;
    }
    else if (0x3fff < iVar1) {
      iVar1 = 0x3fff;
    }
    *(int *)(*(int *)(param_1 + 0x1760) + 0x4c) = iVar1;
    if (**(int **)(param_1 + 0x1760) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x1760) + 1);
    }
  }
  return;
}


// ==== 0x52c140 FUN_0052c140

void __fastcall FUN_0052c140(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(param_1 + 0x220);
  *(uint *)(param_1 + 0x2ac) = uVar1;
  if (0x7fff < uVar1) {
    *(uint *)(param_1 + 0x2ac) = 0xffff - uVar1;
  }
  iVar2 = (int)(*(int *)(param_1 + 0x2ac) + (*(int *)(param_1 + 0x2ac) >> 0x1f & 0x1fU)) >> 5;
  *(int *)(param_1 + 0x2ac) = iVar2;
  if (*(int *)(param_1 + 0x2b4) != 0) {
    if (*(int *)(param_1 + 0x2b0) == 2) {
      iVar2 = (int)*(short *)(*(int *)(param_1 + 0x1f0c) + 0x3e);
    }
    else {
      iVar2 = *(short *)(*(int *)(param_1 + 0x1f0c) + 0x3c) + iVar2;
    }
    *(int *)(param_1 + 0x2ac) = iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x2ac);
  if (iVar2 < 1) {
    *(undefined4 *)(param_1 + 0x2ac) = 0;
    return;
  }
  if (0x400 < iVar2) {
    iVar2 = 0x400;
  }
  *(int *)(param_1 + 0x2ac) = iVar2;
  return;
}


// ==== 0x52c1d0 EAXTunerCar::MixUpdate

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTunerCar__MixUpdate(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  uVar2 = DAT_007356ac;
  if ((((*(float *)(unaff_ESI + 0x1f18) <= *(float *)(unaff_ESI + 0x1f14)) ||
       (*(float *)(unaff_ESI + 0x240) <= *(float *)(unaff_ESI + 0x1f18) + 6.0)) ||
      (*(float *)(unaff_ESI + 0x240) <= *(float *)(unaff_ESI + 0x1d10) + 6.0)) ||
     (((*(float *)(unaff_ESI + 0x1f1c) <= 6000.0 || (*(int *)(unaff_ESI + 0x1d18) < 6)) ||
      (*(float *)(*(int *)(unaff_ESI + 0x234) + 0x3d4) * 2.237 <= 150.0)))) {
    EAXMixMgr__EndMixType(DAT_007356ac,10,*(undefined4 *)(unaff_ESI + 0x264));
  }
  else {
    EAXMixMgr__SetMixType(DAT_007356ac,10,0xbf800000,*(undefined4 *)(unaff_ESI + 0x264));
  }
  if ((*(float *)(*(int *)(unaff_ESI + 0x234) + 0x3d4) * 2.237 < 6.0) &&
     (*(char *)(unaff_ESI + 0x2a8) == '\0')) {
    *(undefined1 *)(unaff_ESI + 0x2a8) = 1;
    *(undefined4 *)(unaff_ESI + 0x2a4) = *(undefined4 *)(unaff_ESI + 0x240);
  }
  if ((6.0 < *(float *)(*(int *)(unaff_ESI + 0x234) + 0x3d4) * 2.237) &&
     (*(char *)(unaff_ESI + 0x2a8) == '\x01')) {
    *(undefined1 *)(unaff_ESI + 0x2a8) = 0;
  }
  if (((*(char *)(unaff_ESI + 0x2a8) == '\0') ||
      (*(float *)(unaff_ESI + 0x240) <= *(float *)(unaff_ESI + 0x2a4) + 3.0)) ||
     ((float)*(int *)(DAT_0073619c + 0x14) * 0.00025 <= 3.0)) {
    EAXMixMgr__EndMixType(uVar2,0xb,*(undefined4 *)(unaff_ESI + 0x264));
  }
  else {
    EAXMixMgr__SetMixType(uVar2,0xb,0xbf800000,*(undefined4 *)(unaff_ESI + 0x264));
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x234) + 0x18);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0x60);
    if ((iVar1 != 6) && (iVar1 != 7)) {
      EAXMixMgr__EndMixType(uVar2,7,*(undefined4 *)(unaff_ESI + 0x264));
      return;
    }
    EAXMixMgr__SetMixType(uVar2,7,0xbf800000,*(undefined4 *)(unaff_ESI + 0x264));
  }
  return;
}


// ==== 0x52c3a0 EAXTunerCar::UpdateCarPhysics

/* [canon] audio low (ghidra) docs/re/sound.md */

void __fastcall EAXTunerCar__UpdateCarPhysics(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x234) + 0x18);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x27c) != 0)) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0x27c) + 0xc);
    if ((iVar2 == 1) || (iVar2 == 0x11)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x2b4) = uVar3;
    *(int *)(param_1 + 0x2b0) = (int)*(char *)(iVar1 + 0x24);
    return;
  }
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  return;
}


// ==== 0x52c3f0 FUN_0052c3f0

void FUN_0052c3f0(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x234);
  *(undefined4 *)(unaff_ESI + 0x1f90) = *(undefined4 *)(iVar2 + 0x3ec);
  fVar1 = *(float *)(*(int *)(iVar2 + 0x30) + 0x1dc) * 100.0;
  *(float *)(unaff_ESI + 0x1f78) = fVar1;
  if (fVar1 <= 30.0) {
    if (*(char *)(unaff_ESI + 0x1f10) != '\0') {
      *(undefined1 *)(unaff_ESI + 0x1f10) = 0;
      *(undefined4 *)(unaff_ESI + 0x1f14) = *(undefined4 *)(unaff_ESI + 0x240);
    }
  }
  else if (*(char *)(unaff_ESI + 0x1f10) == '\0') {
    *(undefined1 *)(unaff_ESI + 0x1f10) = 1;
    *(undefined4 *)(unaff_ESI + 0x1f18) = *(undefined4 *)(unaff_ESI + 0x240);
  }
  if (*(float *)(unaff_ESI + 0x1f90) <= *(float *)(unaff_ESI + 0x1f80)) {
    if (*(float *)(unaff_ESI + 0x1f90) < 0.0) {
      *(undefined4 *)(unaff_ESI + 0x1f90) = 0;
    }
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x1f90) = *(undefined4 *)(unaff_ESI + 0x1f80);
  }
  *(float *)(unaff_ESI + 0x1f90) =
       (*(float *)(unaff_ESI + 0x1f90) / *(float *)(unaff_ESI + 0x1f80)) * 100.0;
  fVar1 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar1 = *(float *)(iVar2 + 0x3e0);
  }
  *(float *)(unaff_ESI + 0x1f20) = (fVar1 / *(float *)(unaff_ESI + 0x1f24)) * 10000.0;
  if (*(char *)(unaff_ESI + 0x12b0) != '\0') {
    if (*(int *)(iVar2 + 0x28) == 1) {
      fVar1 = *(float *)(*(int *)(*(int *)(iVar2 + 0x34) + 0x48) + 0xa4);
    }
    else {
      fVar1 = 0.0;
    }
    FUN_00584270(*(float *)(unaff_ESI + 0x1278) - fVar1 / *(float *)(unaff_ESI + 0x12ac));
    if (*(int *)(*(int *)(unaff_ESI + 0x234) + 0x28) == 1) {
      *(float *)(unaff_ESI + 0x1278) =
           *(float *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x234) + 0x34) + 0x48) + 0xa4) /
           *(float *)(unaff_ESI + 0x12ac);
      return;
    }
    *(float *)(unaff_ESI + 0x1278) = 0.0 / *(float *)(unaff_ESI + 0x12ac);
  }
  return;
}


// ==== 0x52c560 EAXTunerCar::UpdateMasterVolume

/* [canon] audio high (ghidra) docs/re/sound.md */

int __fastcall EAXTunerCar__UpdateMasterVolume(int param_1)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x7f0) + 0xc))();
  (**(code **)(*(int *)(param_1 + 0xc80) + 0xc))();
  if (*(int *)(param_1 + 0x1738) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x1738) + 0x20) + 0x24))();
  }
  if (*(int *)(param_1 + 0x173c) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x173c) + 0x20) + 0x24))();
  }
  (**(code **)(*(int *)(param_1 + 0x3b0) + 0x24))();
  (**(code **)(*(int *)(param_1 + 0x5d0) + 0x24))();
  (**(code **)(*(int *)(param_1 + 0x1500) + 0x24))();
  if (*(int *)(param_1 + 0x1254) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x1254) + 0x20) + 0x24))();
  }
  iVar2 = *(int *)(param_1 + 0xbc);
  if (iVar2 != 0) {
    iVar1 = EAXSound__GetMasterVolume();
    iVar2 = iVar1 * **(int **)(iVar2 + 0x60) >> 0xf;
    *(int *)(param_1 + 0xa4) = iVar2;
    *(int *)(param_1 + 0xa8) = iVar2;
    return iVar2;
  }
  return 0;
}


// ==== 0x52c620 EAXTunerCar::Update

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXTunerCar__Update(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  DAT_00735658 = 1;
  if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
    param_1[0x91] = (int)param_2;
    param_1[0x90] = (int)(param_2 + (float)param_1[0x90]);
  }
  else {
    param_1[0x91] = 0;
  }
  if ((char)param_1[0xa8] != '\0') {
    *(undefined1 *)(param_1 + 0xa8) = 0;
  }
  if ((char)param_1[0x92] == '\x01') {
    (**(code **)(*param_1 + 0x40))();
  }
  (**(code **)(*param_1 + 0x6c))();
  if ((param_1[0xad] == 0) || (param_1[0xac] != 2)) {
    pfVar4 = (float *)(param_1[0x8d] + 0x90);
    pfVar3 = (float *)(param_1[0x8d] + 0x60);
  }
  else {
    iVar1 = *(int *)(param_1[0x8d] + 0x18);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x27c) != 0)) {
      iVar2 = *(int *)(*(int *)(iVar1 + 0x27c) + 0x1c);
      iVar1 = *(int *)(*(int *)(iVar1 + 0x27c) + 0x1c);
      fStack_1c = *(float *)(iVar1 + 0x54);
      fStack_20 = *(float *)(iVar1 + 0x50);
      fStack_18 = *(float *)(iVar1 + 0x58);
      fStack_30 = fStack_20 + *(float *)(iVar2 + 0x40);
      fStack_2c = fStack_1c + *(float *)(iVar2 + 0x44);
      fStack_28 = fStack_18 + *(float *)(iVar2 + 0x48);
    }
    pfVar4 = &fStack_20;
    pfVar3 = &fStack_30;
  }
  (**(code **)(param_1[8] + 0x28))(pfVar3,pfVar4);
  param_1[0x68f] = 0;
  param_1[0x690] = 0;
  param_1[0x691] = 0;
  param_1[0x692] = 0;
  param_1[0x693] = 0;
  param_1[0x694] = 0;
  param_1[0x63b] = 0;
  FUN_0052c3f0();
  (**(code **)(*param_1 + 0x94))(param_2);
  (**(code **)(*param_1 + 100))(param_2);
  FUN_0052bf10();
  (**(code **)(*param_1 + 0x68))(param_2);
  iVar1 = param_1[0x8d];
  param_1[0x7e5] =
       (int)(*(float *)(iVar1 + 0x80) * *(float *)(iVar1 + 0x90) +
            *(float *)(iVar1 + 0x94) * *(float *)(iVar1 + 0x84) +
            *(float *)(iVar1 + 0x98) * *(float *)(iVar1 + 0x88));
  CameraMover__VelocityNoise(param_1,param_2);
  EAXTunerCar__UpdateNitrous(param_2);
  (**(code **)(*param_1 + 0x74))(param_2);
  FUN_0052db90();
  FUN_0052dc70();
  FUN_0052cf80();
  EAXTires__GenerateRoadNoise();
  EAXTires__GenerateSkidNoise();
  FUN_0052ce40();
  (**(code **)(*param_1 + 0x7c))(param_2);
  (**(code **)(*param_1 + 0x88))(param_2);
  (**(code **)(*param_1 + 0x70))();
  EAXTunerCar__MixUpdate();
  EAXS_WindNoise__Update();
  EAXS_WindNoise__UpdateChannels__map__EAXS_VerticalCylinder__Update_(param_1 + 0x204);
  EAXRoadNoise__Update(param_2);
  EAXTunerCar__Refl_Update(param_2);
  EAXTunerCar__BottomOutUpdate();
  EAXTunerCar__BreakingEffectUpdate(param_2);
  (**(code **)(*param_1 + 0x80))(param_2);
  FUN_00529a30();
  EAXNitrous__Update();
  if (DAT_006f1dd8 == 1) {
    (**(code **)(*param_1 + 0x84))();
  }
  return;
}


// ==== 0x52c8b0 FUN_0052c8b0

void FUN_0052c8b0(void)

{
  FUN_00527a40();
  return;
}


// ==== 0x52c8c0 FUN_0052c8c0

void FUN_0052c8c0(void)

{
  FUN_0052a630();
  return;
}


// ==== 0x52c8d0 FUN_0052c8d0

void FUN_0052c8d0(void)

{
  FUN_00526170();
  return;
}


// ==== 0x52c8e0 FUN_0052c8e0

void FUN_0052c8e0(void)

{
  FUN_005282e0();
  return;
}


// ==== 0x52c8f0 FUN_0052c8f0

void * __thiscall FUN_0052c8f0(void *param_1,byte param_2)

{
  FUN_0052c910();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52c910 FUN_0052c910

void __fastcall FUN_0052c910(undefined4 *param_1)

{
  param_1[8] = &PTR_FUN_006be7d8;
  param_1[8] = &PTR_FUN_006be7c4;
  *param_1 = &PTR_EAXMod___scalar_deleting_destructor__006bf478;
  return;
}


// ==== 0x52c930 EAXCar::UpdateSoundSphere

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXCar__UpdateSoundSphere(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *(int *)(param_1 + 0x234);
  fVar2 = *(float *)(iVar1 + 0x60) - *(float *)(param_1 + 0x250);
  fVar4 = *(float *)(iVar1 + 100) - *(float *)(param_1 + 0x254);
  fVar3 = *(float *)(iVar1 + 0x68) - *(float *)(param_1 + 600);
  if (*(float *)(param_1 + 0x260) < SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3)) {
    *(undefined1 *)(param_1 + 0x248) = 0;
  }
  return;
}


// ==== 0x52c990 FUN_0052c990

void FUN_0052c990(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006be7d4;
  *(undefined1 *)(in_EAX + 0x39) = 4;
  *(undefined1 *)((int)in_EAX + 0xe6) = 0;
  *(undefined1 *)((int)in_EAX + 0xe7) = 0;
  in_EAX[0x3a] = 0;
  in_EAX[0x3b] = 0;
  in_EAX[0x3c] = in_EAX + 0x3d;
  *(undefined1 *)((int)in_EAX + 0xe5) = 5;
  in_EAX[0x38] = &PTR_FUN_006b9694;
  in_EAX[0x3d] = 0;
  in_EAX[0x3e] = 0;
  in_EAX[0x3f] = 0;
  in_EAX[0x40] = 0;
  in_EAX[0x41] = 0;
  *(undefined1 *)(in_EAX + 0x43) = 4;
  *(undefined1 *)((int)in_EAX + 0x10d) = 5;
  *(undefined1 *)((int)in_EAX + 0x10e) = 0;
  *(undefined1 *)((int)in_EAX + 0x10f) = 0;
  in_EAX[0x42] = &PTR_FUN_006b9694;
  in_EAX[0x44] = 0;
  in_EAX[0x45] = 0;
  in_EAX[0x46] = in_EAX + 0x47;
  in_EAX[0x47] = 0;
  in_EAX[0x48] = 0;
  in_EAX[0x49] = 0;
  in_EAX[0x4a] = 0;
  in_EAX[0x4b] = 0;
  *(undefined1 *)(in_EAX + 0x4d) = 4;
  *(undefined1 *)((int)in_EAX + 0x135) = 5;
  *(undefined1 *)((int)in_EAX + 0x136) = 0;
  *(undefined1 *)((int)in_EAX + 0x137) = 0;
  in_EAX[0x4c] = &PTR_FUN_006b9694;
  in_EAX[0x4e] = 0;
  in_EAX[0x4f] = 0;
  in_EAX[0x50] = in_EAX + 0x51;
  in_EAX[0x51] = 0;
  in_EAX[0x52] = 0;
  in_EAX[0x53] = 0;
  in_EAX[0x54] = 0;
  in_EAX[0x55] = 0;
  *(undefined1 *)(in_EAX + 0x57) = 4;
  *(undefined1 *)((int)in_EAX + 0x15d) = 5;
  *(undefined1 *)((int)in_EAX + 0x15e) = 0;
  *(undefined1 *)((int)in_EAX + 0x15f) = 0;
  in_EAX[0x56] = &PTR_FUN_006b9694;
  in_EAX[0x58] = 0;
  in_EAX[0x59] = 0;
  in_EAX[0x5a] = in_EAX + 0x5b;
  in_EAX[0x5b] = 0;
  in_EAX[0x5c] = 0;
  in_EAX[0x5d] = 0;
  in_EAX[0x5e] = 0;
  in_EAX[0x5f] = 0;
  *(undefined1 *)(in_EAX + 0x61) = 4;
  *(undefined1 *)((int)in_EAX + 0x185) = 5;
  *(undefined1 *)((int)in_EAX + 0x186) = 0;
  *(undefined1 *)((int)in_EAX + 0x187) = 0;
  in_EAX[0x60] = &PTR_FUN_006b9694;
  in_EAX[0x62] = 0;
  in_EAX[99] = 0;
  in_EAX[100] = in_EAX + 0x65;
  in_EAX[0x65] = 0;
  in_EAX[0x66] = 0;
  in_EAX[0x67] = 0;
  in_EAX[0x68] = 0;
  in_EAX[0x69] = 0;
  *(undefined1 *)(in_EAX + 0x6b) = 4;
  *(undefined1 *)((int)in_EAX + 0x1ad) = 5;
  *(undefined1 *)((int)in_EAX + 0x1ae) = 0;
  in_EAX[0x6a] = &PTR_FUN_006b9694;
  *(undefined1 *)((int)in_EAX + 0x1af) = 0;
  in_EAX[0x6c] = 0;
  in_EAX[0x6d] = 0;
  in_EAX[0x6e] = in_EAX + 0x6f;
  in_EAX[0x6f] = 0;
  in_EAX[0x70] = 0;
  in_EAX[0x71] = 0;
  in_EAX[0x72] = 0;
  in_EAX[0x73] = 0;
  in_EAX[0x32] = 0;
  in_EAX[0x33] = 0;
  in_EAX[0x34] = 0;
  in_EAX[0x35] = 0;
  in_EAX[0x36] = 0;
  in_EAX[0x37] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  *(undefined1 *)(in_EAX + 10) = 0;
  *(undefined1 *)((int)in_EAX + 0x29) = 0;
  in_EAX[0x7f] = 0;
  in_EAX[0x80] = 0;
  in_EAX[0x81] = 0;
  in_EAX[0x82] = 0;
  in_EAX[0x83] = 0;
  in_EAX[0x84] = 0;
  in_EAX[0x85] = 0;
  in_EAX[0x86] = 0;
  return;
}


// ==== 0x52cbb0 FUN_0052cbb0

void * __thiscall FUN_0052cbb0(void *param_1,byte param_2)

{
  FUN_0052cbd0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52cbd0 FUN_0052cbd0

void __fastcall FUN_0052cbd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be7d4;
  param_1[0x6a] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x6e] != param_1 + 0x6f) {
    _free((undefined4 *)param_1[0x6e]);
  }
  param_1[0x6a] = &PTR_FUN_006c7d78;
  param_1[0x60] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[100] != param_1 + 0x65) {
    _free((undefined4 *)param_1[100]);
  }
  param_1[0x60] = &PTR_FUN_006c7d78;
  param_1[0x56] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x5a] != param_1 + 0x5b) {
    _free((undefined4 *)param_1[0x5a]);
  }
  param_1[0x56] = &PTR_FUN_006c7d78;
  param_1[0x4c] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x50] != param_1 + 0x51) {
    _free((undefined4 *)param_1[0x50]);
  }
  param_1[0x4c] = &PTR_FUN_006c7d78;
  param_1[0x42] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x46] != param_1 + 0x47) {
    _free((undefined4 *)param_1[0x46]);
  }
  param_1[0x42] = &PTR_FUN_006c7d78;
  param_1[0x38] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x3c] != param_1 + 0x3d) {
    _free((undefined4 *)param_1[0x3c]);
  }
  param_1[0x38] = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x52ccd0 EAXTires::CreateTires

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXTires__CreateTires(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  *(int *)(unaff_ESI + 0x10) = in_EAX;
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x234) + 0x14) + 4)
  ;
  iVar1 = *(int *)(*(int *)(*(int *)(in_EAX + 0x234) + 0x14) + 0x34);
  *(int *)(unaff_ESI + 0x3c) = iVar1;
  *(uint *)(unaff_ESI + 0x34) = (uint)(1 < iVar1);
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x38) = 1;
  }
  iVar1 = *(int *)(unaff_ESI + 0x34) * 4;
  _DAT_00705870 = *(float *)(&DAT_006b65c0 + iVar1);
  _DAT_00705864 = 0;
  _DAT_0070586c = *(float *)(&DAT_006b65b0 + iVar1);
  _DAT_00705868 = 0x3f800000;
  if (ABS(_DAT_00705870 - _DAT_0070586c) < 1e-06) {
    _DAT_00705870 = _DAT_00705870 + 1e-06;
  }
  DAT_00705874 = 0;
  _DAT_00705878 = 0;
  _DAT_0070588c = (float)(&DAT_006b65b8)[*(int *)(unaff_ESI + 0x34)];
  _DAT_00705880 = 0;
  _DAT_00705888 = (float)(&DAT_006b65a8)[*(int *)(unaff_ESI + 0x34)];
  _DAT_00705884 = 0x3f800000;
  if (ABS(_DAT_0070588c - _DAT_00705888) < 1e-06) {
    _DAT_0070588c = _DAT_0070588c + 1e-06;
  }
  DAT_00705890 = 0;
  _DAT_00705894 = 0;
  FUN_00584310(0);
  FUN_00584310(0);
  FUN_00584310(0);
  FUN_00584310(0);
  FUN_00584310(0);
  FUN_00584310(0);
  return;
}


// ==== 0x52ce40 FUN_0052ce40

void FUN_0052ce40(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + 0x234);
  iVar3 = *(int *)(iVar1 + 0x358);
  iVar4 = *(int *)(iVar1 + 0x354);
  if (iVar3 != *(int *)(iVar1 + 0x35c)) {
    iVar3 = *(int *)(in_EAX + 0x1c);
  }
  if (iVar4 != *(int *)(iVar1 + 0x360)) {
    iVar4 = *(int *)(in_EAX + 0x18);
  }
  iVar1 = *(int *)(in_EAX + 0x18);
  iVar2 = *(int *)(in_EAX + 0x1c);
  *(int *)(in_EAX + 0x18) = iVar4;
  *(bool *)(in_EAX + 0x28) = iVar4 != iVar1;
  *(int *)(in_EAX + 0x24) = iVar2;
  *(int *)(in_EAX + 0x1c) = iVar3;
  *(bool *)(in_EAX + 0x29) = iVar3 != iVar2;
  *(int *)(in_EAX + 0x20) = iVar1;
  return;
}


// ==== 0x52cea0 FUN_0052cea0

undefined4 FUN_0052cea0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
  case 3:
    return 5;
  case 2:
  case 0xd:
    return 4;
  default:
    return 0xffffffff;
  case 7:
  case 0x19:
  case 0x1a:
    return 7;
  case 8:
  case 10:
  case 0xf:
    return 0;
  case 0xb:
  case 0xc:
    return 2;
  case 0xe:
    return 3;
  case 0x10:
    return 1;
  }
}


// ==== 0x52cf20 FUN_0052cf20

undefined4 FUN_0052cf20(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  switch(in_EAX) {
  case 0xb:
  case 0x10:
    return 0;
  case 0xe:
    iVar1 = RandomInt(2);
    if (iVar1 == 0) {
      return 2;
    }
    if (iVar1 == 1) {
      return 3;
    }
  }
  return 0xffffffff;
}


// ==== 0x52cf80 FUN_0052cf80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052cf80(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  iVar4 = 4;
  pfVar3 = (float *)(param_1 + 0x9c);
  do {
    *pfVar3 = pfVar3[4] * 0.047;
    if (2.5 < pfVar3[4] * 0.047) {
      *pfVar3 = 2.5;
    }
    pfVar3 = pfVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fVar1 = (*(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0xa0)) * _K_HALF;
  *(float *)(param_1 + 0xbc) = fVar1;
  fVar2 = (*(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x9c)) * _K_HALF;
  *(float *)(param_1 + 0xc0) = fVar2;
  *(float *)(param_1 + 0xc4) = (fVar2 + fVar1) * _K_HALF;
  return;
}


// ==== 0x52d010 EAXTires::GenerateSkidNoise

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTires__GenerateSkidNoise(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  bool bVar11;
  float10 fVar12;
  float10 extraout_ST1;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64;
  undefined1 local_50 [76];
  
  fVar1 = *(float *)(*(int *)(in_EAX + 0x10) + 0x244);
  iVar6 = *(int *)(*(int *)(in_EAX + 0x10) + 0x234);
  local_6c = *(undefined4 *)(in_EAX + 0x210);
  local_68 = *(undefined4 *)(in_EAX + 0x20c);
  local_70 = *(undefined4 *)(in_EAX + 0x214);
  local_74 = *(int *)(in_EAX + 0x218);
  if (*(float *)(in_EAX + 0x60) <= 0.0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = *(float *)(&DAT_006b64b8 + (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4)
            * *(float *)(in_EAX + 0x60);
  }
  *(float *)(in_EAX + 200) = fVar2;
  if (*(float *)(in_EAX + 0x68) <= 0.0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = *(float *)(&DAT_006b64b8 + (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4)
            * *(float *)(in_EAX + 0x68);
  }
  *(float *)(in_EAX + 0xcc) = fVar3;
  iVar8 = (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4;
  fVar4 = *(float *)(&DAT_006b64d8 + iVar8);
  if (*(float *)(&DAT_006b64d8 + iVar8) < fVar2) {
    fVar4 = fVar2;
  }
  if (*(float *)(&DAT_006b64c8 + iVar8) < fVar4) {
    fVar4 = *(float *)(&DAT_006b64c8 + iVar8);
  }
  *(float *)(in_EAX + 200) = fVar4;
  if (fVar3 <= *(float *)(&DAT_006b64d8 + iVar8)) {
    fVar3 = *(float *)(&DAT_006b64d8 + iVar8);
  }
  if (*(float *)(&DAT_006b64c8 + iVar8) < fVar3) {
    fVar3 = *(float *)(&DAT_006b64c8 + iVar8);
  }
  *(float *)(in_EAX + 0xcc) = fVar3;
  local_64 = iVar6;
  FUN_00584270(fVar4);
  FUN_00584270(*(undefined4 *)(in_EAX + 0xcc));
  iVar8 = (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x1d4) = uVar5;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x1e0) = uVar5;
  if (ABS(*(float *)(iVar6 + 0x3d4)) <= _K_HALF) {
LAB_0052d225:
    *(undefined4 *)(in_EAX + 0x204) = 0;
  }
  else {
    if ((*(float *)(in_EAX + 0x90) <= *(float *)(&DAT_006b6518 + iVar8)) &&
       (*(float *)(in_EAX + 0x94) <= *(float *)(&DAT_006b6518 + iVar8))) {
      *(undefined4 *)(in_EAX + 0x1fc) = 0;
      goto LAB_0052d225;
    }
    fVar2 = fVar1 + *(float *)(in_EAX + 0x1fc);
    *(float *)(in_EAX + 0x1fc) = fVar2;
    if (fVar2 <= *(float *)(&DAT_006b6528 + iVar8)) goto LAB_0052d225;
    uVar5 = _ftol_nocw();
    *(undefined4 *)(in_EAX + 0x204) = uVar5;
  }
  if (_K_HALF < ABS(*(float *)(iVar6 + 0x3d4))) {
    if ((*(float *)(&DAT_006b6518 + iVar8) < *(float *)(in_EAX + 0x8c)) ||
       (*(float *)(&DAT_006b6518 + iVar8) < *(float *)(in_EAX + 0x98))) {
      fVar1 = fVar1 + *(float *)(in_EAX + 0x200);
      *(float *)(in_EAX + 0x200) = fVar1;
      if (*(float *)(&DAT_006b6528 + iVar8) < fVar1) {
        uVar5 = _ftol_nocw();
        *(undefined4 *)(in_EAX + 0x208) = uVar5;
        goto LAB_0052d286;
      }
    }
    else {
      *(undefined4 *)(in_EAX + 0x200) = 0;
    }
  }
  *(undefined4 *)(in_EAX + 0x208) = 0;
LAB_0052d286:
  local_8c = *(undefined4 *)(iVar6 + 0x84);
  local_90 = *(undefined4 *)(iVar6 + 0x80);
  local_88 = *(undefined4 *)(iVar6 + 0x88);
  bMatrixCopy();
  D3DXVec3Transform(&local_90,iVar6 + 0x80,local_50);
  bNormalize3();
  if (1.0 <= *(float *)(iVar6 + 0x3d0)) {
    fVar12 = (float10)CarState__GetYaw();
  }
  else {
    fVar12 = (float10)0.0;
  }
  if (1.0 <= *(float *)(iVar6 + 0x3d0)) {
    CarState__GetYaw();
  }
  puVar9 = &DAT_00705880;
  if (*(int *)(in_EAX + 0x38) != 0) {
    puVar9 = &DAT_00705864;
  }
  *(float *)(puVar9 + 0x10) = (float)ABS(fVar12);
  EAX_linear_ramp_evaluate__not_SetCsisName_();
  iVar10 = (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4;
  iVar8 = _ftol_nocw();
  *(int *)(in_EAX + 0x20c) = iVar8;
  iVar6 = *(int *)(&DAT_006b6538 + iVar10) + local_74;
  if ((*(int *)(&DAT_006b6538 + iVar10) + local_74 < iVar8) ||
     (iVar6 = local_74 - *(int *)(&DAT_006b6548 + iVar10),
     iVar8 < local_74 - *(int *)(&DAT_006b6548 + iVar10))) {
    iVar8 = iVar6;
  }
  *(int *)(in_EAX + 0x20c) = iVar8;
  iVar8 = _ftol_nocw();
  *(int *)(in_EAX + 0x210) = iVar8;
  iVar6 = *(int *)(&DAT_006b6538 + iVar10) + iStack_78;
  if ((iVar8 <= *(int *)(&DAT_006b6538 + iVar10) + iStack_78) &&
     (iVar6 = iStack_78 - *(int *)(&DAT_006b6548 + iVar10),
     iStack_78 - *(int *)(&DAT_006b6548 + iVar10) <= iVar8)) {
    iVar6 = iVar8;
  }
  *(int *)(in_EAX + 0x210) = iVar6;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x1d8) = uVar5;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x1e4) = uVar5;
  if (0.0 <= *(float *)(in_EAX + 0x60)) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = ABS(*(float *)(&DAT_006b64e8 + iVar10) * *(float *)(in_EAX + 100));
  }
  *(float *)(in_EAX + 0xd8) = fVar1;
  if (0.0 <= *(float *)(in_EAX + 0x68)) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = ABS(*(float *)(&DAT_006b64e8 + iVar10) * *(float *)(in_EAX + 0x6c));
  }
  *(float *)(in_EAX + 0xdc) = fVar2;
  fVar3 = *(float *)(&DAT_006b6508 + iVar10);
  if (*(float *)(&DAT_006b6508 + iVar10) < fVar1) {
    fVar3 = fVar1;
  }
  if (*(float *)(&DAT_006b64f8 + iVar10) < fVar3) {
    fVar3 = *(float *)(&DAT_006b64f8 + iVar10);
  }
  *(float *)(in_EAX + 0xd8) = fVar3;
  if (fVar2 <= *(float *)(&DAT_006b6508 + iVar10)) {
    fVar2 = *(float *)(&DAT_006b6508 + iVar10);
  }
  if (*(float *)(&DAT_006b64f8 + iVar10) < fVar2) {
    fVar2 = *(float *)(&DAT_006b64f8 + iVar10);
  }
  *(float *)(in_EAX + 0xdc) = fVar2;
  iVar6 = _ftol_nocw();
  iVar8 = _ftol_nocw();
  FUN_00584270((float)iVar8);
  FUN_00584270((float)iVar6);
  _ftol_nocw();
  _ftol_nocw();
  iVar6 = (*(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x38) * 2) * 4;
  uVar5 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x214) = uVar5;
  uVar7 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x218) = uVar7;
  if (extraout_ST1 <= (float10)0.15) {
    *(undefined4 *)(in_EAX + 0x214) = 0;
    *(undefined4 *)(in_EAX + 0x218) = 0;
  }
  else {
    *(undefined4 *)(in_EAX + 0x214) = uVar5;
    *(undefined4 *)(in_EAX + 0x218) = uVar7;
  }
  iVar8 = *(int *)(in_EAX + 0x214);
  iVar10 = *(int *)(&DAT_006b6558 + iVar6) + iStack_7c;
  if ((*(int *)(&DAT_006b6558 + iVar6) + iStack_7c < iVar8) ||
     (iVar10 = iStack_7c - *(int *)(&DAT_006b6568 + iVar6),
     iVar8 < iStack_7c - *(int *)(&DAT_006b6568 + iVar6))) {
    iVar8 = iVar10;
  }
  *(int *)(in_EAX + 0x214) = iVar8;
  iVar8 = *(int *)(in_EAX + 0x218);
  iVar10 = *(int *)(&DAT_006b6558 + iVar6) + iStack_80;
  if ((iVar8 <= *(int *)(&DAT_006b6558 + iVar6) + iStack_80) &&
     (iVar10 = iStack_80 - *(int *)(&DAT_006b6568 + iVar6),
     iStack_80 - *(int *)(&DAT_006b6568 + iVar6) <= iVar8)) {
    iVar10 = iVar8;
  }
  *(int *)(in_EAX + 0x218) = iVar10;
  iVar6 = _ftol_nocw();
  iVar8 = _ftol_nocw();
  *(int *)(in_EAX + 0x1dc) = iVar6 + iVar8;
  iVar6 = _ftol_nocw();
  iVar8 = _ftol_nocw();
  bVar11 = DAT_0073563c != '\0';
  *(int *)(in_EAX + 0x1e8) = iVar6 + iVar8;
  if ((bVar11) && (*(char *)(DAT_007356a8 + 0x84) == '\0')) {
    FUN_005327f0(0,0x3f800000,*(undefined4 *)(&DAT_006b65b0 + *(int *)(in_EAX + 0x34) * 4),
                 *(undefined4 *)(&DAT_006b65c0 + *(int *)(in_EAX + 0x34) * 4));
    FUN_005327f0(0,0x3f800000,(&DAT_006b65a8)[*(int *)(in_EAX + 0x34)],
                 (&DAT_006b65b8)[*(int *)(in_EAX + 0x34)]);
  }
  return;
}


// ==== 0x52d8b0 EAXTires::GenerateRoadNoise

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXTires__GenerateRoadNoise(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar4 = 0.0;
  fVar5 = 0.0;
  fVar6 = 0.0;
  if (*(int *)(unaff_ESI + 0x14) == 1) {
    fVar6 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0x10) + 0x234) + 0x3d4) * 2.237;
    LinearTable__Lookup11(&PTR_DAT_00705840,fVar6);
    iVar2 = _ftol_nocw(fVar4,fVar5);
    _DAT_00705858 = fVar6;
    fVar5 = (float)(iVar2 * 0x7fff >> 0xf);
    fVar4 = SQRT(*(float *)(unaff_ESI + 0x60) * *(float *)(unaff_ESI + 0x60) +
                 *(float *)(unaff_ESI + 100) * *(float *)(unaff_ESI + 100)) * 0.01;
    if (0.15 < fVar4) {
      fVar4 = 0.15;
    }
    fVar4 = (_K_ONE + 0.1) * (fVar4 + _K_ONE) * fVar5;
    fVar6 = SQRT(*(float *)(unaff_ESI + 0x68) * *(float *)(unaff_ESI + 0x68) +
                 *(float *)(unaff_ESI + 0x6c) * *(float *)(unaff_ESI + 0x6c)) * 0.01;
    if (0.15 < fVar6) {
      fVar6 = 0.15;
    }
    fVar1 = (*(float *)(unaff_ESI + 0x98) + *(float *)(unaff_ESI + 0x8c)) * _K_HALF * 1.0 * 0.1;
    if (0.1 < fVar1) {
      fVar1 = 0.1;
    }
    fVar5 = (fVar1 + _K_ONE) * (fVar6 + _K_ONE) * fVar5;
    if (32000.0 < fVar5) {
      fVar5 = 32000.0;
    }
    if (32000.0 < fVar4) {
      fVar4 = 32000.0;
    }
    EAX_linear_ramp_evaluate__not_SetCsisName_(fVar4,fVar5);
    fVar6 = SQRT(*(float *)(unaff_ESI + 0x68) * *(float *)(unaff_ESI + 0x68) +
                 *(float *)(unaff_ESI + 0x6c) * *(float *)(unaff_ESI + 0x6c)) * 0.01;
    if (0.2 < fVar6) {
      fVar6 = 0.2;
    }
    fVar1 = (*(float *)(unaff_ESI + 0x98) + *(float *)(unaff_ESI + 0x8c)) * _K_HALF * 1.0 * 0.15;
    if (0.15 < fVar1) {
      fVar1 = 0.15;
    }
    fVar6 = (fVar1 + _K_ONE) * (fVar6 + _K_ONE) * _DAT_0070585c;
    if (6000.0 < fVar6) {
      fVar6 = 6000.0;
    }
  }
  uVar3 = _ftol_nocw(fVar4,fVar5,fVar6);
  *(undefined4 *)(unaff_ESI + 0x1f0) = uVar3;
  uVar3 = _ftol_nocw();
  *(undefined4 *)(unaff_ESI + 0x1ec) = uVar3;
  uVar3 = _ftol_nocw();
  *(undefined4 *)(unaff_ESI + 0x1f8) = uVar3;
  uVar3 = _ftol_nocw();
  *(undefined4 *)(unaff_ESI + 500) = uVar3;
  return;
}


// ==== 0x52db90 FUN_0052db90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052db90(undefined4 param_1)

{
  int extraout_EDX;
  int extraout_EDX_00;
  int unaff_ESI;
  float10 fVar1;
  float fVar2;
  
  fVar1 = (float10)FUN_00564b10(param_1);
  fVar2 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10();
  *(float *)(unaff_ESI + 0x220) =
       (float)(((float10)fVar2 * (float10)*(float *)(extraout_EDX + 0x90) -
               fVar1 * (float10)*(float *)(extraout_EDX + 0x94)) * (float10)_DAT_006f8154 +
              (float10)*(float *)(extraout_EDX + 0x60));
  *(float *)(unaff_ESI + 0x224) =
       (float)(((float10)fVar2 * (float10)*(float *)(extraout_EDX + 0x94) +
               fVar1 * (float10)*(float *)(extraout_EDX + 0x90)) * (float10)_DAT_006f8154 +
              (float10)*(float *)(extraout_EDX + 100));
  *(float *)(unaff_ESI + 0x228) = *(float *)(extraout_EDX + 0x68) + *(float *)(extraout_EDX + 0x98);
  fVar1 = (float10)FUN_00564b10();
  fVar2 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10();
  *(float *)(unaff_ESI + 0x230) =
       (float)(((float10)fVar2 * (float10)*(float *)(extraout_EDX_00 + 0x90) -
               fVar1 * (float10)*(float *)(extraout_EDX_00 + 0x94)) * (float10)_DAT_006f8154 +
              (float10)*(float *)(extraout_EDX_00 + 0x60));
  *(float *)(unaff_ESI + 0x234) =
       (float)(((float10)fVar2 * (float10)*(float *)(extraout_EDX_00 + 0x94) +
               fVar1 * (float10)*(float *)(extraout_EDX_00 + 0x90)) * (float10)_DAT_006f8154 +
              (float10)*(float *)(extraout_EDX_00 + 100));
  *(float *)(unaff_ESI + 0x238) =
       *(float *)(extraout_EDX_00 + 0x68) + *(float *)(extraout_EDX_00 + 0x98);
  return;
}


// ==== 0x52dc70 FUN_0052dc70

void FUN_0052dc70(void)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  
  iVar3 = 0;
  *(undefined4 *)(in_EAX + 0x80) = 0;
  *(undefined4 *)(in_EAX + 0x84) = 0;
  *(undefined4 *)(in_EAX + 0x78) = 0;
  *(undefined4 *)(in_EAX + 0x7c) = 0;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 100) = 0;
  *(undefined4 *)(in_EAX + 0x68) = 0;
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  *(undefined4 *)(in_EAX + 0x88) = 0;
  *(undefined4 *)(in_EAX + 0x1d0) = 0;
  pfVar2 = (float *)(in_EAX + 0x40);
  pfVar4 = (float *)(in_EAX + 0x8c);
  do {
    fVar1 = ABS(*(float *)((int)pfVar4 +
                          *(int *)(*(int *)(in_EAX + 0x10) + 0x234) + (0x264 - in_EAX)));
    pfVar4[8] = fVar1;
    *(float *)(in_EAX + 0x88) = fVar1 + *(float *)(in_EAX + 0x88);
    *pfVar4 = ABS(*(float *)(*(int *)(*(int *)(in_EAX + 0x10) + 0x234) + (0x308 - in_EAX) +
                            (int)pfVar4));
    iVar5 = *(int *)(*(int *)(in_EAX + 0x10) + 0x234) + (-0x40 - in_EAX);
    fVar1 = *(float *)(iVar5 + 0x374 + (int)pfVar2);
    pfVar2[1] = *(float *)(iVar5 + 0x378 + (int)pfVar2);
    *pfVar2 = fVar1;
    fVar1 = pfVar2[1];
    *(float *)(in_EAX + 0x80) = *(float *)(in_EAX + 0x80) + *pfVar2;
    *(float *)(in_EAX + 0x84) = fVar1 + *(float *)(in_EAX + 0x84);
    iVar5 = *(int *)(*(int *)(in_EAX + 0x10) + 0x234);
    if (iVar3 < 2) {
      if (*(char *)(iVar5 + 0x350 + iVar3) != '\0') {
        *(int *)(in_EAX + 0x1d0) = *(int *)(in_EAX + 0x1d0) + 1;
        fVar1 = pfVar2[1];
        *(float *)(in_EAX + 0x70) = *(float *)(in_EAX + 0x70) + *pfVar2;
        *(float *)(in_EAX + 0x74) = fVar1 + *(float *)(in_EAX + 0x74);
      }
    }
    else if (*(char *)(iVar5 + 0x350 + iVar3) != '\0') {
      *(int *)(in_EAX + 0x1d0) = *(int *)(in_EAX + 0x1d0) + 1;
      fVar1 = pfVar2[1];
      *(float *)(in_EAX + 0x78) = *(float *)(in_EAX + 0x78) + *pfVar2;
      *(float *)(in_EAX + 0x7c) = fVar1 + *(float *)(in_EAX + 0x7c);
    }
    if ((iVar3 < 1) || (2 < iVar3)) {
      if (*(char *)(*(int *)(*(int *)(in_EAX + 0x10) + 0x234) + 0x350 + iVar3) != '\0') {
        fVar1 = pfVar2[1];
        *(float *)(in_EAX + 0x68) = *(float *)(in_EAX + 0x68) + *pfVar2;
        *(float *)(in_EAX + 0x6c) = fVar1 + *(float *)(in_EAX + 0x6c);
      }
    }
    else if (*(char *)(*(int *)(*(int *)(in_EAX + 0x10) + 0x234) + 0x350 + iVar3) != '\0') {
      fVar1 = pfVar2[1];
      *(float *)(in_EAX + 0x60) = *(float *)(in_EAX + 0x60) + *pfVar2;
      *(float *)(in_EAX + 100) = fVar1 + *(float *)(in_EAX + 100);
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 1;
    pfVar2 = pfVar2 + 2;
  } while (iVar3 < 4);
  *(float *)(in_EAX + 0x88) = *(float *)(in_EAX + 0x88) * 0.25;
  return;
}


// ==== 0x52de30 FUN_0052de30

void FUN_0052de30(void)

{
  FUN_0052c8f0();
  return;
}


// ==== 0x52de40 FUN_0052de40

undefined4 * __thiscall FUN_0052de40(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006be7c4;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52de60 EAXS_SoundShape::GetDistanceRolloff

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

int EAXS_SoundShape__GetDistanceRolloff(float param_1)

{
  float fVar1;
  int iVar2;
  sbyte sVar3;
  
  sVar3 = 0;
  if ((((((param_1 - 0.5) + (param_1 - 0.5) < 0.0) &&
        (sVar3 = 1, fVar1 = (param_1 - 0.25) * 4.0, fVar1 < 0.0 != (fVar1 == 0.0))) &&
       (sVar3 = 2, fVar1 = (param_1 - 0.125) * 8.0, fVar1 < 0.0 != (fVar1 == 0.0))) &&
      ((((sVar3 = 3, fVar1 = (param_1 - 0.0625) * 16.0, fVar1 < 0.0 != (fVar1 == 0.0) &&
         (sVar3 = 4, fVar1 = (param_1 - 0.03125) * 32.0, fVar1 < 0.0 != (fVar1 == 0.0))) &&
        ((sVar3 = 5, fVar1 = (param_1 - 0.015625) * 64.0, fVar1 < 0.0 != (fVar1 == 0.0) &&
         ((sVar3 = 6, fVar1 = (param_1 - 0.0078125) * 128.0, fVar1 < 0.0 != (fVar1 == 0.0) &&
          (sVar3 = 7, fVar1 = (param_1 - 0.00390625) * 256.0, fVar1 < 0.0 != (fVar1 == 0.0))))))) &&
       (sVar3 = 8, fVar1 = (param_1 - 0.001953125) * 512.0, fVar1 < 0.0 != (fVar1 == 0.0))))) &&
     (((sVar3 = 9, fVar1 = (param_1 - 0.0009765625) * 1024.0, fVar1 < 0.0 != (fVar1 == 0.0) &&
       (sVar3 = 10, fVar1 = (param_1 - 0.00048828125) * 2048.0, fVar1 < 0.0 != (fVar1 == 0.0))) &&
      (sVar3 = 0xb, (param_1 - 0.00024414062) * 4096.0 < 0.0)))) {
    sVar3 = 0xf;
  }
  iVar2 = _ftol_nocw();
  return *(int *)(&DAT_006f7e1c + iVar2 * 4) >> sVar3;
}


// ==== 0x52e060 EAXS_SoundShape::GetCurveOutput

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

int __thiscall EAXS_SoundShape__GetCurveOutput(int *param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float10 extraout_ST0;
  
  param_1[7] = (int)(param_3 * 511.9999);
  if (511.5 < param_3 * 511.9999) {
    return 0;
  }
  iVar2 = _ftol_nocw();
  param_1[8] = iVar2;
  param_1[6] = (int)(float)(extraout_ST0 - (float10)iVar2);
  if (iVar2 == 0x1ff) {
    param_1[6] = 0;
  }
  param_1[5] = 0;
  param_1[10] = 0x7fff;
  switch(param_2) {
  case 0:
    iVar2 = _ftol_nocw();
    return iVar2;
  case 1:
    param_1[10] = (&DAT_006f7220)[iVar2];
    if (((float)param_1[6] <= 0.0) || (0x1fe < iVar2)) goto LAB_0052e317;
    fVar1 = (float)(int)((&DAT_006f7220)[iVar2 + 1U & 0x1ff] - (&DAT_006f7220)[iVar2]);
    break;
  case 2:
    iVar4 = (int)((&DAT_006f7220)[iVar2] * (&DAT_006f7220)[iVar2]) >> 0xf;
    param_1[10] = iVar4;
    param_1[0xb] = iVar4;
    if ((0.0 < (float)param_1[6]) && (iVar2 < 0x1ff)) {
      param_1[0xb] = (int)((&DAT_006f7220)[iVar2 + 1U & 0x1ff] * (&DAT_006f7220)[iVar2 + 1U & 0x1ff]
                          ) >> 0xf;
    }
    fVar1 = (float)(param_1[0xb] - param_1[10]);
    break;
  case 3:
    iVar4 = (&DAT_006f7a1c)[-iVar2];
    param_1[10] = 0x7fff - iVar4;
    param_1[0xb] = 0x7fff - iVar4;
    if ((0.0 < (float)param_1[6]) && (iVar2 < 0x1ff)) {
      param_1[0xb] = 0x7fff - (&DAT_006f7a1c)[-(iVar2 + 1U & 0x1ff)];
    }
    fVar1 = (float)(param_1[0xb] - param_1[10]);
    break;
  case 4:
    iVar4 = (int)((&DAT_006f7220)[iVar2] * (&DAT_006f7220)[iVar2]) >> 0xf;
    param_1[10] = iVar4;
    param_1[0xb] = iVar4;
    if ((0.0 < (float)param_1[6]) && (iVar2 < 0x1ff)) {
      param_1[0xb] = (int)((&DAT_006f7220)[iVar2 + 1U & 0x1ff] * (&DAT_006f7220)[iVar2 + 1U & 0x1ff]
                          ) >> 0xf;
    }
    fVar1 = (float)(param_1[0xb] - param_1[10]);
    break;
  case 5:
    iVar4 = (0x7fff - (&DAT_006f7a1c)[-iVar2]) * (&DAT_006f7220)[iVar2] >> 0xf;
    param_1[10] = iVar4;
    param_1[0xb] = iVar4;
    if ((0.0 < (float)param_1[6]) && (iVar2 < 0x1ff)) {
      uVar3 = iVar2 + 1U & 0x1ff;
      param_1[0xb] = (0x7fff - (&DAT_006f7a1c)[-uVar3]) * (&DAT_006f7220)[uVar3] >> 0xf;
    }
    fVar1 = (float)(param_1[0xb] - param_1[10]);
    break;
  case 6:
    iVar2 = (&DAT_006f7220)[param_1[8]];
    iVar4 = (**(code **)(*param_1 + 8))(_K_ONE - param_3);
    iVar2 = iVar4 + (iVar2 * iVar2 >> 0xf) >> 1;
    param_1[10] = iVar2;
    param_1[0xb] = iVar2;
LAB_0052e317:
    param_1[5] = 0;
    goto switchD_0052e0c4_default;
  case 7:
    param_3 = _K_ONE - param_3;
    param_1[5] = 0;
    iVar2 = (**(code **)(*param_1 + 8))(param_3);
    return iVar2;
  case 8:
    iVar2 = (**(code **)(*param_1 + 8))(param_3);
    return 0x7fff - iVar2;
  default:
    goto switchD_0052e0c4_default;
  }
  param_1[5] = (int)fVar1;
switchD_0052e0c4_default:
  iVar2 = _ftol_nocw();
  param_1[9] = iVar2;
  iVar2 = param_1[10] + iVar2;
  if (0x7fff < iVar2) {
    iVar2 = 0x7fff;
  }
  return iVar2;
}


// ==== 0x52e380 EAXS_SoundShape::GetAzimShapeOutput

/* [canon] audio med (ghidra) docs/re/sound.md */

void __thiscall
EAXS_SoundShape__GetAzimShapeOutput(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*param_1 + 4))(param_2,*param_4);
  param_1[1] = iVar1;
  param_1[2] = 0x7fff;
  if (param_3 != 0) {
    iVar1 = (**(code **)(*param_1 + 4))(unaff_retaddr,param_4[1]);
    param_1[2] = iVar1;
  }
  iVar1 = ((param_3 * -2 + 0x7fff) * param_1[1] >> 0xf) + (param_1[2] * param_3 * 2 >> 0xf);
  param_1[3] = iVar1;
  param_1[4] = iVar1;
  return;
}


// ==== 0x52e3f0 EAXS_3DMixer::EAXS_3DMixer

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXS_3DMixer__EAXS_3DMixer(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape_____006be798;
  in_EAX[0x2f] = 0;
  in_EAX[0x38] = 0;
  in_EAX[0x39] = 0;
  in_EAX[0x3a] = 0;
  in_EAX[0x3c] = 0;
  in_EAX[0x3e] = 0;
  in_EAX[0x3d] = 0x3f800000;
  in_EAX[0x2a] = 0x7fff;
  in_EAX[0x2e] = 0x3f800000;
  in_EAX[0x16] = 0x4e38;
  in_EAX[0x17] = 0xb1c7;
  in_EAX[0x81] = 0;
  in_EAX[0x33] = 0;
  return;
}


// ==== 0x52e460 EAXS_3DMixer::_EAXS_3DMixer

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXS_3DMixer___EAXS_3DMixer(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be7c4;
  return;
}


// ==== 0x52e470 EAXS_3DMixer::Init3DMix

/* [canon] audio med (ghidra) docs/re/sound.md */

void __thiscall EAXS_3DMixer__Init3DMix(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_007356a8;
  param_1[0x2f] = param_2;
  param_1[0x81] = *(int *)(*(int *)(iVar1 + 0xa0) + 4);
  (**(code **)(*param_1 + 0x24))();
  return;
}


// ==== 0x52e4a0 EAXS_3DMixer::Setup3DMix

/* [canon] audio med (ghidra) docs/re/sound.md */

void __thiscall EAXS_3DMixer__Setup3DMix(int param_1,int param_2)

{
  if ((*(char *)(*(int *)(DAT_007356a8 + 0xa0) + 0x10) != '\0') && (*(int *)(param_1 + 0x204) != 0))
  {
    if (param_2 != 0) {
      *(int *)(param_1 + 0xbc) = param_2;
    }
    *(undefined4 *)(param_1 + 0xcc) = 0;
    FUN_0052e540();
    if (*(int *)(*(int *)(param_1 + 0x204) + 0x188) == 1) {
      *(undefined4 *)(param_1 + 0x84) = 0xbf800000;
      FUN_0052e540();
      if ((*(float *)(param_1 + 0x84) < *(float *)(param_1 + 0x80)) &&
         (0.0 <= *(float *)(param_1 + 0x84))) {
        *(undefined4 *)(param_1 + 0xcc) = 1;
      }
    }
  }
  return;
}


// ==== 0x52e540 FUN_0052e540

void __fastcall FUN_0052e540(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar6 = (param_1 + 0x12) * 0x10;
  puVar7 = (undefined4 *)(iVar6 + in_EAX);
  uVar1 = puVar7[2];
  puVar8 = (undefined4 *)((param_1 + 0x14) * 0x10 + in_EAX);
  uVar2 = *puVar7;
  puVar8[1] = *(undefined4 *)(iVar6 + 4 + in_EAX);
  *puVar8 = uVar2;
  puVar8[2] = uVar1;
  if (*(int *)(*(int *)(in_EAX + 0x204) + 0x60 + param_1 * 4) != 0) {
    *(undefined4 *)(in_EAX + 0x98 + param_1 * 4) = *(undefined4 *)(in_EAX + 0x90 + param_1 * 4);
    iVar6 = *(int *)(*(int *)(in_EAX + 0x204) + 0x60 + *(int *)(in_EAX + 0xcc) * 4);
    if (iVar6 == 0) {
      *(undefined4 *)(in_EAX + 0x90 + param_1 * 4) = 0x3f800000;
    }
    else {
      fVar3 = *(float *)(iVar6 + 0x40) - *(float *)(in_EAX + 0xe0);
      fVar4 = *(float *)(iVar6 + 0x44) - *(float *)(in_EAX + 0xe4);
      fVar5 = *(float *)(iVar6 + 0x48) - *(float *)(in_EAX + 0xe8);
      *(float *)(in_EAX + 0x90 + param_1 * 4) = SQRT(fVar4 * fVar4 + fVar3 * fVar3 + fVar5 * fVar5);
    }
    uVar1 = *(undefined4 *)(iVar6 + 0x44);
    uVar2 = *(undefined4 *)(iVar6 + 0x48);
    *puVar7 = *(undefined4 *)(iVar6 + 0x40);
    puVar7[1] = uVar1;
    puVar7[2] = uVar2;
  }
  if (*(int *)(*(int *)(in_EAX + 0x204) + 0x168 + param_1 * 4) != 0) {
    *(undefined4 *)(in_EAX + 0x88 + param_1 * 4) = *(undefined4 *)(in_EAX + 0x80 + param_1 * 4);
    iVar6 = *(int *)(*(int *)(in_EAX + 0x204) + 0x168 + param_1 * 4);
    fVar3 = *(float *)(iVar6 + 0x60) - *(float *)(in_EAX + 0xe0);
    fVar5 = *(float *)(iVar6 + 100) - *(float *)(in_EAX + 0xe4);
    fVar4 = *(float *)(iVar6 + 0x68) - *(float *)(in_EAX + 0xe8);
    *(float *)(in_EAX + 0x80 + param_1 * 4) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3);
    iVar6 = *(int *)(*(int *)(in_EAX + 0x204) + 0x168 + param_1 * 4);
    uVar1 = *(undefined4 *)(iVar6 + 100);
    uVar2 = *(undefined4 *)(iVar6 + 0x68);
    *puVar7 = *(undefined4 *)(iVar6 + 0x60);
    puVar7[1] = uVar1;
    puVar7[2] = uVar2;
  }
  return;
}


// ==== 0x52e680 FUN_0052e680

void FUN_0052e680(void)

{
  int in_EAX;
  
  if (*(int *)(*(int *)(in_EAX + 0x204) + 0x168 + *(int *)(in_EAX + 0xcc) * 4) != 0) {
    FUN_0052e6d0(*(int *)(in_EAX + 0xcc));
  }
  if (*(int *)(*(int *)(in_EAX + 0x204) + 0x188) == 1) {
    FUN_0052e6d0(*(int *)(in_EAX + 0xcc) - 1U & 1);
  }
  return;
}


// ==== 0x52e6d0 FUN_0052e6d0

void FUN_0052e6d0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  
  iVar6 = *(int *)(*(int *)(unaff_ESI + 0x204) + 0x168 + param_1 * 4);
  fVar1 = *(float *)(iVar6 + 100);
  fVar4 = *(float *)(iVar6 + 0x68);
  *(float *)(unaff_ESI + 0x180) = *(float *)(unaff_ESI + 0xe0) - *(float *)(iVar6 + 0x60);
  *(float *)(unaff_ESI + 0x184) = *(float *)(unaff_ESI + 0xe4) - fVar1;
  *(float *)(unaff_ESI + 0x188) = *(float *)(unaff_ESI + 0xe8) - fVar4;
  iVar6 = *(int *)(*(int *)(unaff_ESI + 0x204) + 0x168 + param_1 * 4);
  uVar2 = *(undefined4 *)(iVar6 + 100);
  uVar3 = *(undefined4 *)(iVar6 + 0x68);
  *(undefined4 *)(unaff_ESI + 0x1a0) = *(undefined4 *)(iVar6 + 0x60);
  *(undefined4 *)(unaff_ESI + 0x1a4) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1a8) = uVar3;
  iVar6 = *(int *)(*(int *)(unaff_ESI + 0x204) + 0x168 + param_1 * 4);
  uVar2 = *(undefined4 *)(iVar6 + 0x94);
  uVar3 = *(undefined4 *)(iVar6 + 0x98);
  *(undefined4 *)(unaff_ESI + 0x1c0) = *(undefined4 *)(iVar6 + 0x90);
  *(undefined4 *)(unaff_ESI + 0x1c4) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1c8) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x188) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c8) = 0;
  bNormalize3();
  bNormalize3();
  iVar6 = Atan2ToAngle16(*(undefined4 *)(unaff_ESI + 0x1b0),*(undefined4 *)(unaff_ESI + 0x1b4));
  iVar7 = Atan2ToAngle16(*(undefined4 *)(unaff_ESI + 400),*(undefined4 *)(unaff_ESI + 0x194));
  *(uint *)(unaff_ESI + 0x60 + param_1 * 4) = iVar6 - iVar7 & 0xffff;
  iVar6 = *(int *)(*(int *)(unaff_ESI + 0x204) + 0x60 + param_1 * 4);
  fVar4 = *(float *)(iVar6 + 0x48);
  fVar1 = *(float *)(iVar6 + 0x44);
  *(float *)(unaff_ESI + 0x180) = *(float *)(unaff_ESI + 0xe0) - *(float *)(iVar6 + 0x40);
  *(float *)(unaff_ESI + 0x184) = *(float *)(unaff_ESI + 0xe4) - fVar1;
  *(float *)(unaff_ESI + 0x188) = *(float *)(unaff_ESI + 0xe8) - fVar4;
  uVar2 = *(undefined4 *)(iVar6 + 0x44);
  uVar3 = *(undefined4 *)(iVar6 + 0x48);
  *(undefined4 *)(unaff_ESI + 0x1a0) = *(undefined4 *)(iVar6 + 0x40);
  *(undefined4 *)(unaff_ESI + 0x1a4) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1a8) = uVar3;
  uVar2 = *(undefined4 *)(iVar6 + 0x54);
  uVar3 = *(undefined4 *)(iVar6 + 0x58);
  *(undefined4 *)(unaff_ESI + 0x1c0) = *(undefined4 *)(iVar6 + 0x50);
  *(undefined4 *)(unaff_ESI + 0x1c4) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1c8) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x188) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c8) = 0;
  bNormalize3();
  bNormalize3();
  uVar5 = Atan2ToAngle16(*(undefined4 *)(unaff_ESI + 0x1b0),*(undefined4 *)(unaff_ESI + 0x1b4));
  iVar6 = Atan2ToAngle16(*(undefined4 *)(unaff_ESI + 400),*(undefined4 *)(unaff_ESI + 0x194));
  *(uint *)(unaff_ESI + 0x68 + param_1 * 4) = (uint)uVar5 - iVar6 & 0xffff;
  return;
}


// ==== 0x52e8c0 FUN_0052e8c0

short FUN_0052e8c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  int unaff_ESI;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar3 = *(int *)(*(int *)(unaff_ESI + 0x204) + 0x60 + *(int *)(unaff_ESI + 0xcc) * 4);
  if (*(int *)(unaff_ESI + 0xd0) == 0) {
    uVar1 = *(undefined4 *)(iVar3 + 0x54);
    uVar2 = *(undefined4 *)(iVar3 + 0x58);
    *(undefined4 *)(unaff_ESI + 0xf0) = *(undefined4 *)(iVar3 + 0x50);
    *(undefined4 *)(unaff_ESI + 0xf4) = uVar1;
    *(undefined4 *)(unaff_ESI + 0xf8) = uVar2;
    *(int *)(unaff_ESI + 0xd0) = iVar3 + 0x50;
  }
  bNormalize3(*(float *)(unaff_ESI + 0xe0) - *(float *)(iVar3 + 0x40),
              *(float *)(unaff_ESI + 0xe4) - *(float *)(iVar3 + 0x44),
              *(float *)(unaff_ESI + 0xe8) - *(float *)(iVar3 + 0x48));
  bNormalize3(local_20,local_1c,0);
  fVar5 = local_20;
  fVar6 = local_1c;
  fVar7 = local_18;
  bNormalize3(local_20,local_1c,local_18);
  sVar4 = FUN_00564cd0(local_18 * fVar7 + fVar5 * local_20 + fVar6 * local_1c);
  *(short *)(unaff_ESI + 0x200) = 0x4000 - sVar4;
  return 0x4000 - sVar4;
}


// ==== 0x52ea00 EAXS_3DMixer::Update3DMix

/* [canon] audio high (ghidra) docs/re/sound.md */

int __thiscall EAXS_3DMixer__Update3DMix(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1[0x81] == 0) && (*(int *)(DAT_007356a8 + 0xa0) != 0)) {
    param_1[0x81] = *(int *)(*(int *)(DAT_007356a8 + 0xa0) + 4);
  }
  if (param_2 != (int *)0x0) {
    iVar2 = param_2[1];
    iVar3 = param_2[2];
    param_1[0x38] = *param_2;
    param_1[0x39] = iVar2;
    param_1[0x3a] = iVar3;
  }
  piVar1 = param_1 + 0x3c;
  if (param_3 == (int *)0x0) {
    *piVar1 = 0;
    param_1[0x3d] = 0;
    param_1[0x3e] = 0;
  }
  else {
    iVar2 = param_3[1];
    iVar3 = param_3[2];
    *piVar1 = *param_3;
    param_1[0x3d] = iVar2;
    param_1[0x3e] = iVar3;
  }
  param_1[0x34] = (int)piVar1;
  (**(code **)(*param_1 + 0x14))(param_1[0x2f]);
  if (*(int *)(param_1[0x2f] + 0x14) != 4) {
    if ((param_1[0x81] != 0) && (*DAT_0073619c != 0)) {
      FUN_0052e680();
      if (0.0 <= *(float *)(param_1[0x2f] + 100)) {
        FUN_0052f030();
      }
      FUN_0052f0c0();
      FUN_0052ec60();
      param_1[0x14] = param_1[0x2a] * param_1[0x15] >> 0xf;
      FUN_0052e8c0();
      DAT_00735658 = 0;
      param_1[0x40] = param_1[0x38];
      param_1[0x41] = param_1[0x39];
      param_1[0x42] = param_1[0x3a];
      param_1[0x44] = *piVar1;
      param_1[0x45] = param_1[0x3d];
      param_1[0x46] = param_1[0x3e];
      return param_1[0x14];
    }
    return 0;
  }
  *(undefined2 *)(param_1 + 0x80) = 0;
  param_1[0x13] = 0;
  param_1[0x14] = param_1[0x2a];
  DAT_00735658 = 0;
  return param_1[0x2a];
}


// ==== 0x52eb70 FUN_0052eb70

void __fastcall FUN_0052eb70(ushort param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xac) = 0;
  *(ushort *)(in_EAX + 0xb0) = param_1;
  if (0xbfff < param_1) {
    *(undefined4 *)(in_EAX + 0xac) = 3;
    *(ushort *)(in_EAX + 0xb0) = param_1 + 0x4000;
    return;
  }
  if (0x7fff < param_1) {
    *(undefined4 *)(in_EAX + 0xac) = 2;
    *(ushort *)(in_EAX + 0xb0) = param_1 + 0x8000;
    return;
  }
  if (0x3fff < param_1) {
    *(undefined4 *)(in_EAX + 0xac) = 1;
    *(ushort *)(in_EAX + 0xb0) = param_1 + 0xc000;
  }
  return;
}


// ==== 0x52ebe0 EAXS_3DMixer::IsInsideMinDistance

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __fastcall EAXS_3DMixer__IsInsideMinDistance(int *param_1)

{
  float10 fVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  float10 fVar3;
  
  uVar2 = 0;
  if (param_1[0x2f] != 0) {
    fVar3 = (float10)(**(code **)(*param_1 + 0x20))();
    fVar1 = (float10)0.0;
    uVar2 = CONCAT22(extraout_var,
                     (ushort)(fVar3 < fVar1) << 8 | (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                     (ushort)(fVar3 == fVar1) << 0xe);
    if (fVar3 >= fVar1) {
      fVar3 = (float10)(**(code **)(*param_1 + 0x20))();
      fVar1 = (float10)*(float *)(param_1[0x2f] + 0x58);
      uVar2 = CONCAT22((short)((uint)param_1[0x2f] >> 0x10),
                       (ushort)(fVar3 < fVar1) << 8 | (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                       (ushort)(fVar3 == fVar1) << 0xe);
      if (fVar3 < fVar1) {
        return CONCAT31((int3)((uint)uVar2 >> 8),1);
      }
    }
  }
  return uVar2;
}


// ==== 0x52ec20 EAXS_3DMixer::GetDistanceToRefObj

/* [canon] audio high (ghidra) docs/re/sound.md */

float10 __fastcall EAXS_3DMixer__GetDistanceToRefObj(int param_1)

{
  if (*(int **)(param_1 + 0xbc) == (int *)0x0) {
    return (float10)-1.0;
  }
  if (2 < **(int **)(param_1 + 0xbc)) {
    return (float10)*(float *)(param_1 + 0x80 + *(int *)(param_1 + 0xcc) * 4);
  }
  return (float10)*(float *)(param_1 + 0x90 + *(int *)(param_1 + 0xcc) * 4);
}


// ==== 0x52ec60 FUN_0052ec60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052ec60(undefined4 param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  uint uVar7;
  int *unaff_ESI;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST1;
  
  if ((*(int *)(unaff_ESI[0x2f] + 4) == 1) || (*(int *)(unaff_ESI[0x2f] + 4) == 2)) {
    FUN_0052eb70(param_1);
  }
  iVar6 = unaff_ESI[0x33];
  if (*(int *)unaff_ESI[0x2f] < 2) {
    iVar5 = unaff_ESI[iVar6 + 0x24];
  }
  else {
    iVar5 = unaff_ESI[iVar6 + 0x20];
  }
  unaff_ESI[0x28] = iVar5;
  switch(*(int *)unaff_ESI[0x2f]) {
  case 1:
    fVar8 = (float10)FUN_00564b10();
    unaff_ESI[extraout_EDX * 2 + 0x1c] =
         (int)(float)(fVar8 * (float10)(float)unaff_ESI[extraout_EDX + 0x24]);
    fVar8 = (float10)FUN_00564b10();
    unaff_ESI[extraout_EDX_00 * 2 + 0x1d] =
         (int)(float)(fVar8 * (float10)(float)unaff_ESI[extraout_EDX_00 + 0x24]);
    goto LAB_0052ed77;
  case 2:
    unaff_ESI[iVar6 * 2 + 0x1c] = unaff_ESI[iVar6 + 0x24];
    iVar6 = unaff_ESI[0x33];
    iVar5 = unaff_ESI[iVar6 + 0x24];
    break;
  case 3:
    fVar8 = (float10)FUN_00564b10();
    unaff_ESI[extraout_EDX_01 * 2 + 0x1c] =
         (int)(float)(fVar8 * (float10)(float)unaff_ESI[extraout_EDX_01 + 0x20]);
    fVar8 = (float10)FUN_00564b10();
    unaff_ESI[extraout_EDX_02 * 2 + 0x1d] =
         (int)(float)(fVar8 * (float10)(float)unaff_ESI[extraout_EDX_02 + 0x20]);
    goto LAB_0052ed77;
  case 4:
    unaff_ESI[iVar6 * 2 + 0x1c] = unaff_ESI[iVar6 + 0x20];
    iVar6 = unaff_ESI[0x33];
    iVar5 = unaff_ESI[iVar6 + 0x20];
    break;
  default:
    unaff_ESI[0x15] = 0x7fff;
    return;
  }
  unaff_ESI[iVar6 * 2 + 0x1d] = iVar5;
LAB_0052ed77:
  iVar6 = unaff_ESI[0x2b];
  iVar5 = unaff_ESI[0x2f];
  iVar2 = unaff_ESI[0x33];
  fVar3 = (float)unaff_ESI[iVar2 * 2 + 0x1c] - *(float *)(iVar5 + 0x38 + iVar6 * 8);
  uVar7 = iVar6 + 1U & 3;
  fVar4 = (float)unaff_ESI[iVar2 * 2 + 0x1d] - *(float *)(iVar5 + 0x38 + uVar7 * 8);
  if (*(int *)(iVar5 + 0x28 + iVar6 * 4) == 0) {
    if (0.0 <= fVar3) {
      unaff_ESI[iVar2 * 2 + 0x1c] =
           (int)(fVar3 / (*(float *)(iVar5 + 0x3c + iVar6 * 8) -
                         *(float *)(iVar5 + 0x38 + iVar6 * 8)));
    }
    else {
      unaff_ESI[iVar2 * 2 + 0x1c] = 0;
    }
    if (0.0 <= fVar4) {
      unaff_ESI[unaff_ESI[0x33] * 2 + 0x1d] =
           (int)(fVar4 / (*(float *)(unaff_ESI[0x2f] + 0x3c + uVar7 * 8) -
                         *(float *)(unaff_ESI[0x2f] + 0x38 + uVar7 * 8)));
    }
    else {
      unaff_ESI[unaff_ESI[0x33] * 2 + 0x1d] = 0;
    }
  }
  else {
    if (0.0 <= fVar3) {
      if (*(float *)(iVar5 + 0x3c + iVar6 * 8) < (float)unaff_ESI[iVar2 * 2 + 0x1c]) {
        unaff_ESI[iVar2 * 2 + 0x1c] = *(int *)(iVar5 + 0x3c + iVar6 * 8);
        unaff_ESI[0x15] = 0;
        return;
      }
      unaff_ESI[iVar2 * 2 + 0x1c] =
           (int)(*(float *)(iVar5 + 0x38 + iVar6 * 8) / (float)unaff_ESI[iVar2 * 2 + 0x1c]);
    }
    else {
      unaff_ESI[iVar2 * 2 + 0x1c] = 0;
    }
    if (fVar4 < 0.0) {
      pfVar1 = (float *)(unaff_ESI + unaff_ESI[0x33] * 2 + 0x1d);
      iVar6 = unaff_ESI[0x2f];
      if (*(float *)(iVar6 + 0x3c + uVar7 * 8) < (float)unaff_ESI[unaff_ESI[0x33] * 2 + 0x1d]) {
        *pfVar1 = *(float *)(iVar6 + 0x3c + uVar7 * 8);
        unaff_ESI[0x15] = 0;
        return;
      }
      *pfVar1 = *(float *)(iVar6 + 0x38 + uVar7 * 8) / *pfVar1;
    }
  }
  if (_K_ONE < (float)unaff_ESI[unaff_ESI[0x33] * 2 + 0x1c]) {
    unaff_ESI[unaff_ESI[0x33] * 2 + 0x1c] = 0x3f800000;
  }
  if (_K_ONE < (float)unaff_ESI[unaff_ESI[0x33] * 2 + 0x1d]) {
    unaff_ESI[unaff_ESI[0x33] * 2 + 0x1d] = 0x3f800000;
  }
  iVar5 = EAXS_SoundShape__GetAzimShapeOutput
                    (*(undefined4 *)(unaff_ESI[0x2f] + 0x18 + unaff_ESI[0x2b] * 4),
                     *(undefined4 *)(unaff_ESI[0x2f] + 0x18 + uVar7 * 4),
                     unaff_ESI + unaff_ESI[0x33] * 2 + 0x1c,(short)unaff_ESI[0x2c]);
  iVar6 = unaff_ESI[0x81];
  unaff_ESI[0x15] = iVar5;
  if (*(int *)(iVar6 + 0x188) == 1) {
    iVar2 = unaff_ESI[0x33];
    uVar7 = iVar2 - 1U & 1;
    if (*(int *)(iVar6 + 0x158 + uVar7 * 4) < *(int *)(iVar6 + 0x158 + iVar2 * 4)) {
      fVar3 = ABS(*(float *)(iVar6 + (uVar7 + 0x40 + iVar2 * 2) * 4));
      if (70.0 < fVar3) {
        fVar3 = 70.0;
      }
      if (35.0 < fVar3) {
        fVar3 = ((fVar3 - 35.0) / 35.0) * _DAT_006f7ea8 * 511.9999;
        unaff_ESI[7] = (int)fVar3;
        if (fVar3 <= 511.5) {
          iVar6 = _ftol_nocw();
          unaff_ESI[8] = iVar6;
          unaff_ESI[6] = (int)(float)(extraout_ST0 - (float10)iVar6);
          if (iVar6 == 0x1ff) {
            unaff_ESI[6] = 0;
          }
          fVar8 = (float10)_K_ONE;
          unaff_ESI[10] = 0x7fff;
          unaff_ESI[5] = 0;
          iVar6 = (**(code **)(*unaff_ESI + 8))((float)(fVar8 - extraout_ST1));
          unaff_ESI[0x15] = iVar6 * iVar5 >> 0xf;
          return;
        }
        unaff_ESI[0x15] = 0;
        return;
      }
    }
  }
  return;
}


// ==== 0x52f030 FUN_0052f030

void __fastcall FUN_0052f030(int param_1)

{
  int iVar1;
  float fVar2;
  
  *(undefined4 *)(param_1 + 0xb8) = 0x3f800000;
  if (*(float *)(*(int *)(param_1 + 0x204) + 0x178) == 0.0) {
LAB_0052f054:
    *(undefined4 *)(param_1 + 0xb8) = 0x3f800000;
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xbc) + 8);
  if (iVar1 == 1) {
    fVar2 = *(float *)(param_1 + 0x90 + *(int *)(param_1 + 0xcc) * 4) -
            *(float *)(param_1 + 0x98 + *(int *)(param_1 + 0xcc) * 4);
  }
  else {
    if (iVar1 != 2) goto LAB_0052f054;
    fVar2 = *(float *)(param_1 + 0x80 + *(int *)(param_1 + 0xcc) * 4) -
            *(float *)(param_1 + 0x88 + *(int *)(param_1 + 0xcc) * 4);
  }
  *(float *)(param_1 + 0xb8) =
       343.0 / ((fVar2 / *(float *)(*(int *)(param_1 + 0x204) + 0x178)) *
                *(float *)(*(int *)(param_1 + 0xbc) + 100) * 1000.0 + 343.0);
  return;
}


// ==== 0x52f0c0 FUN_0052f0c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052f0c0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  float local_c;
  
  *(undefined4 *)(unaff_ESI + 0x44 + *(int *)(unaff_ESI + 0xcc) * 4) = 0;
  if (*(int *)(*(int *)(unaff_ESI + 0x204) + 0x188) == 1) {
    iVar4 = *(int *)(unaff_ESI + 0xcc);
    local_c = ABS(*(float *)(*(int *)(unaff_ESI + 0x204) + ((iVar4 - 1U & 1) + 0x40 + iVar4 * 2) * 4
                            ));
    if (70.0 < local_c) {
      local_c = 70.0;
    }
    if (35.0 <= local_c) {
      if (local_c < 70.0 == (local_c == 70.0)) goto LAB_0052f244;
      *(float *)(unaff_ESI + 0xb4) = (local_c - 35.0) / 35.0;
    }
    uVar2 = _ftol_nocw();
    *(undefined4 *)(unaff_ESI + 0x44 + iVar4 * 4) = uVar2;
  }
LAB_0052f244:
  iVar4 = *(int *)(*(int *)(unaff_ESI + 0xbc) + 4);
  if (iVar4 == 1) {
    iVar4 = *(int *)(unaff_ESI + 0xcc);
    iVar3 = *(int *)(unaff_ESI + 0x68 + iVar4 * 4);
  }
  else {
    if (iVar4 != 2) {
      iVar3 = 0;
      goto LAB_0052f271;
    }
    iVar4 = *(int *)(unaff_ESI + 0xcc);
    iVar3 = *(int *)(unaff_ESI + 0x60 + iVar4 * 4);
  }
  iVar3 = iVar3 + *(int *)(unaff_ESI + 0x44 + iVar4 * 4);
LAB_0052f271:
  *(short *)(unaff_ESI + 0x202) = (short)iVar3;
  if (0xffff < iVar3) {
    *(short *)(unaff_ESI + 0x202) = (short)(iVar3 + 1U);
    *(uint *)(unaff_ESI + 0x4c) = iVar3 + 1U & 0xffff;
    return;
  }
  if (-1 < iVar3) {
    *(uint *)(unaff_ESI + 0x4c) = (uint)*(ushort *)(unaff_ESI + 0x202);
    return;
  }
  uVar1 = (short)iVar3 - 1;
  *(ushort *)(unaff_ESI + 0x202) = uVar1;
  *(uint *)(unaff_ESI + 0x4c) = (uint)uVar1;
  return;
}


// ==== 0x52f2c0 FUN_0052f2c0

void __fastcall FUN_0052f2c0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x7fff < in_EAX) {
    in_EAX = 0x7fff;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (9000 < param_1) {
    param_1 = 9000;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x32 < unaff_EBX) {
    unaff_EBX = 0x32;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_007441e8,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_IMPACT_SMOKABLE_006f8178);
    Csis__Class__CreateInstance(&DAT_007441e8,piVar1);
  }
  return;
}


// ==== 0x52f380 FUN_0052f380

void __fastcall FUN_0052f380(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x7fff < in_EAX) {
    in_EAX = 0x7fff;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (9000 < param_1) {
    param_1 = 9000;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x10 < unaff_EBX) {
    unaff_EBX = 0x10;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_007441e0,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_SCRAPE_WORLD_006f8180);
    Csis__Class__CreateInstance(&DAT_007441e0,piVar1);
  }
  return;
}


// ==== 0x52f440 FUN_0052f440

void __fastcall FUN_0052f440(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (0x7fff < in_EAX) {
    in_EAX = 0x7fff;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (9000 < param_1) {
    param_1 = 9000;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x10 < unaff_EBX) {
    unaff_EBX = 0x10;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_007441f0,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_SCRAPE_SMOKABLE_006f8188);
    Csis__Class__CreateInstance(&DAT_007441f0,piVar1);
  }
  return;
}


// ==== 0x52f500 FUN_0052f500

undefined4 __fastcall FUN_0052f500(int param_1)

{
  return *(undefined4 *)(param_1 + 0x240);
}


// ==== 0x52f510 FUN_0052f510

undefined4 FUN_0052f510(void)

{
  return 5;
}


// ==== 0x52f520 FUN_0052f520

void FUN_0052f520(void)

{
  undefined4 *in_EAX;
  
  FUN_00530570();
  in_EAX[0xd8] = 0;
  in_EAX[0xd9] = 0;
  *in_EAX = &PTR_FUN_006be640;
  return;
}


// ==== 0x52f540 FUN_0052f540

void __fastcall FUN_0052f540(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be640;
  FUN_005306a0();
  return;
}


// ==== 0x52f550 FUN_0052f550

void * __thiscall FUN_0052f550(void *param_1,byte param_2)

{
  FUN_0052f540();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52f570 FUN_0052f570

void FUN_0052f570(void)

{
  undefined4 *in_EAX;
  
  FUN_00530570();
  *in_EAX = &PTR_FUN_006be520;
  return;
}


// ==== 0x52f590 FUN_0052f590

void __fastcall FUN_0052f590(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be520;
  FUN_005306a0();
  return;
}


// ==== 0x52f5a0 FUN_0052f5a0

void * __thiscall FUN_0052f5a0(void *param_1,byte param_2)

{
  FUN_0052f590();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52f5c0 FUN_0052f5c0

/* WARNING: Switch with 1 destination removed at 0x0052f5c5 : 28 cases all go to same destination */

undefined4 FUN_0052f5c0(void)

{
  return 0x7fff;
}


// ==== 0x52f650 FUN_0052f650

byte FUN_0052f650(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  byte bVar7;
  
  cVar3 = Collision__IsPlayerInvolved();
  bVar7 = cVar3 != '\0';
  iVar1 = *(int *)(unaff_EDI + 100);
  iVar2 = *(int *)(iVar1 + 600);
  cVar3 = *(char *)(iVar2 + 0x15);
  if ((cVar3 == '\x01') || (*(char *)(*(int *)(iVar1 + 0x25c) + 0x15) == '\x01')) {
    bVar7 = bVar7 | 2;
  }
  cVar4 = Collision__IsWallInvolved();
  if (cVar4 != '\0') {
    bVar7 = bVar7 | 4;
  }
  if ((cVar3 == '\0') && (*(char *)(*(int *)(iVar1 + 0x25c) + 0x15) == '\0')) {
    bVar7 = bVar7 | 8;
  }
  iVar5 = 0;
  iVar6 = 0;
  if (cVar3 == '\0') {
    iVar5 = *(int *)(iVar2 + 0x140);
  }
  if (*(char *)(*(int *)(iVar1 + 0x25c) + 0x15) == '\0') {
    iVar6 = *(int *)(*(int *)(iVar1 + 0x25c) + 0x140);
  }
  if ((iVar5 != 0) || (iVar6 != 0)) {
    bVar7 = bVar7 | 0x10;
  }
  return bVar7;
}


// ==== 0x52f6f0 FUN_0052f6f0

undefined4 FUN_0052f6f0(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  
  iVar3 = *(int *)(*(int *)(in_EAX + 100) + 600);
  cVar1 = *(char *)(iVar3 + 0x15);
  if (cVar1 != '\x01') {
    iVar4 = *(int *)(*(int *)(in_EAX + 100) + 0x25c);
    cVar2 = *(char *)(iVar4 + 0x15);
    if (cVar2 != '\x01') {
      iVar6 = 0;
      iVar5 = 0;
      if (cVar1 == '\0') {
        iVar6 = *(int *)(iVar3 + 0x140);
      }
      if (cVar2 == '\0') {
        iVar5 = *(int *)(iVar4 + 0x140);
      }
      if ((iVar6 != 0) && (iVar5 != 0)) {
        return 1;
      }
      return 0;
    }
  }
  return 2;
}


// ==== 0x52f750 FUN_0052f750

undefined4 FUN_0052f750(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 10:
  case 0xc:
  case 0xe:
    return 0;
  default:
    return 1;
  }
}


// ==== 0x52f7b0 FUN_0052f7b0

int FUN_0052f7b0(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  switch(in_EAX) {
  case 0:
  case 7:
  case 8:
  case 0xd:
  case 0xe:
    DAT_0078ead8 = DAT_0078ead8 + 1;
    if (2 < DAT_0078ead8) {
      DAT_0078ead8 = 0;
    }
    return DAT_0078ead8 + 0xd;
  case 1:
    iVar1 = DAT_0078eac8 + 1;
    DAT_0078eac8 = iVar1;
    if (2 < iVar1) {
      DAT_0078eac8 = 0;
      return 0;
    }
    break;
  case 2:
    DAT_0078eac0 = DAT_0078eac0 + 1;
    if (1 < DAT_0078eac0) {
      DAT_0078eac0 = 0;
    }
    return DAT_0078eac0 + 0xb;
  case 3:
    DAT_0078eadc = DAT_0078eadc + 1;
    if (0 < DAT_0078eadc) {
      DAT_0078eadc = 0;
    }
    return DAT_0078eadc + 0x1c;
  case 4:
    DAT_0078ead0 = DAT_0078ead0 + 1;
    if (2 < DAT_0078ead0) {
      DAT_0078ead0 = 0;
    }
    return DAT_0078ead0 + 3;
  case 5:
    DAT_0078eac4 = DAT_0078eac4 + 1;
    if (2 < DAT_0078eac4) {
      DAT_0078eac4 = 0;
    }
    return DAT_0078eac4 + 0x16;
  case 6:
    DAT_0078eabc = DAT_0078eabc + 1;
    if (1 < DAT_0078eabc) {
      DAT_0078eabc = 0;
    }
    return DAT_0078eabc + 6;
  case 9:
  case 10:
  case 0xb:
    DAT_0078ead4 = DAT_0078ead4 + 1;
    if (2 < DAT_0078ead4) {
      DAT_0078ead4 = 0;
    }
    return DAT_0078ead4 + 0x10;
  case 0xc:
    DAT_0078eacc = DAT_0078eacc + 1;
    if (2 < DAT_0078eacc) {
      DAT_0078eacc = 0;
    }
    return DAT_0078eacc + 8;
  case 0xf:
    DAT_0078eab4 = DAT_0078eab4 + 1;
    if (2 < DAT_0078eab4) {
      DAT_0078eab4 = 0;
    }
    return DAT_0078eab4 + 0x19;
  case 0x10:
    DAT_0078eab8 = DAT_0078eab8 + 1;
    if (2 < DAT_0078eab8) {
      DAT_0078eab8 = 0;
    }
    return DAT_0078eab8 + 0x13;
  default:
    iVar1 = 8;
  }
  return iVar1;
}


// ==== 0x52f940 EAXCollision::EAXCollision

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXCollision__EAXCollision(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006be5a4;
  puVar1 = unaff_ESI + 1;
  *puVar1 = puVar1;
  unaff_ESI[2] = puVar1;
  puVar1 = unaff_ESI + 9;
  *puVar1 = puVar1;
  unaff_ESI[10] = puVar1;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  *(undefined1 *)(unaff_ESI + 0xf) = 1;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[3] = 0;
  FUN_00530340(unaff_ESI);
  return;
}


// ==== 0x52f990 FUN_0052f990

void * __thiscall FUN_0052f990(void *param_1,byte param_2)

{
  EAXCollision___EAXCollision();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x52f9b0 EAXCollision::_EAXCollision

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXCollision___EAXCollision(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pvStack_c = ExceptionList;
  pcStack_8 = FUN_00686b7b;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006be5a4;
  piVar1 = (int *)param_1[9];
  local_4 = 0;
  while (piVar1 != param_1 + 9) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -0x84 != (int *)0x0) {
      (**(code **)piVar1[-0x84])(1);
    }
    piVar1 = (int *)param_1[9];
  }
  local_4 = 0xffffffff;
  FUN_00421900();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x52fa30 FUN_0052fa30

void FUN_0052fa30(void)

{
  int in_EAX;
  int *piVar1;
  int *piVar2;
  
  if (*(int *)(in_EAX + 0x24) == 0) goto LAB_0052fa46;
  piVar2 = (int *)(*(int *)(in_EAX + 0x24) + -0x210);
  while( true ) {
    if (in_EAX == -0x24) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(in_EAX + -0x1ec);
    }
    if (piVar2 == piVar1) break;
    (**(code **)(*piVar2 + 0x24))();
    if (piVar2[0x84] == 0) {
LAB_0052fa46:
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[0x84] + -0x210);
    }
  }
  return;
}


// ==== 0x52fa80 FUN_0052fa80

void __fastcall FUN_0052fa80(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DAT_00735628 = 0;
  DAT_0073562c = 0;
  DAT_00735630 = 0;
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x24) + -0x210);
  }
  while( true ) {
    if (param_1 == -0x24) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)(param_1 + -0x1ec);
    }
    if (puVar3 == puVar4) break;
    if (puVar3[0x84] == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)(puVar3[0x84] + -0x210);
    }
    iVar1 = puVar3[0x84];
    piVar2 = (int *)puVar3[0x85];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    DAT_00735618 = DAT_00735618 + -1;
    (**(code **)*puVar3)(1);
    puVar3 = puVar4;
  }
  return;
}


// ==== 0x52fb00 FUN_0052fb00

void FUN_0052fb00(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  int unaff_EDI;
  
  HudWidget__RegisterObject(in_EAX);
  iVar2 = DAT_00735630;
  iVar3 = 0;
  for (puVar1 = *(undefined4 **)(unaff_EDI + 4);
      (puVar1 != (undefined4 *)(unaff_EDI + 4) && (iVar3 = iVar3 + 1, puVar1 != (undefined4 *)0x0));
      puVar1 = (undefined4 *)*puVar1) {
  }
  *(int *)(unaff_EDI + 0xc) = iVar3;
  if (iVar2 < iVar3) {
    DAT_00735630 = iVar3;
  }
  return;
}


// ==== 0x52fb30 FUN_0052fb30

undefined4 FUN_0052fb30(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)*in_EAX;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return 0;
    }
    if (unaff_EDI == puVar1[2]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}


// ==== 0x52fb60 FUN_0052fb60

/* WARNING: Removing unreachable block (ram,0x0052ff63) */
/* WARNING: Removing unreachable block (ram,0x0052ff68) */

void FUN_0052fb60(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  void **ppvVar6;
  int *******pppppppiVar7;
  int ******ppppppiVar8;
  int *******pppppppiVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int ******ppppppiVar13;
  int ******ppppppiVar14;
  bool bVar15;
  int ******local_20;
  int ******local_1c;
  int ******local_18;
  int ******local_14;
  int ******local_10;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686b60;
  if (*(int *)(param_1 + 0xc) == 0) {
    return;
  }
  local_c = ExceptionList;
  if (DAT_006f7e94 + 1 <= *(int *)(param_1 + 0xc) + DAT_00735624) {
    puVar1 = (undefined4 *)(param_1 + 4);
    puVar2 = (undefined4 *)*puVar1;
    local_20 = (int ******)&local_1c;
    local_18 = (int ******)&local_1c;
    local_14 = (int ******)&local_14;
    local_10 = (int ******)&local_14;
    local_4 = 1;
    ppvVar6 = &local_c;
    local_1c = local_20;
    for (; ExceptionList = ppvVar6, puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      ppppppiVar14 = (int ******)puVar2[2];
      if (((uint)ppppppiVar14[0xd1] & 1) != 0) {
        if (DAT_007349b4 == 0) {
          FUN_005649f0();
        }
        pppppppiVar7 = (int *******)FUN_00567160();
        if (pppppppiVar7 == (int *******)0x0) {
          pppppppiVar7 = (int *******)0x0;
        }
        else {
          pppppppiVar7[2] = ppppppiVar14;
        }
        *local_18 = (int *****)pppppppiVar7;
        pppppppiVar7[1] = local_18;
        *pppppppiVar7 = (int ******)&local_1c;
        local_20 = local_1c;
        local_18 = (int ******)pppppppiVar7;
      }
      ppvVar6 = ExceptionList;
    }
    piVar12 = (int *)*puVar1;
    while (ppppppiVar14 = (int ******)0x0, piVar12 != (int *)(param_1 + 4)) {
      pppppppiVar7 = (int *******)NullUpdate_ret();
      do {
        ppppppiVar13 = (int ******)piVar12[2];
        for (pppppppiVar9 = (int *******)local_20; pppppppiVar9 != pppppppiVar7;
            pppppppiVar9 = (int *******)*pppppppiVar9) {
          if (ppppppiVar13 == pppppppiVar9[2]) goto LAB_0052fc94;
        }
        if ((ppppppiVar14 == (int ******)0x0) ||
           ((float)ppppppiVar13[0xc0] < (float)ppppppiVar14[0xc0])) {
          ppppppiVar14 = ppppppiVar13;
        }
LAB_0052fc94:
        piVar12 = (int *)*piVar12;
      } while (piVar12 != (int *)(param_1 + 4));
      if (ppppppiVar14 == (int ******)0x0) break;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      pppppppiVar7 = (int *******)FUN_00567160();
      if (pppppppiVar7 == (int *******)0x0) {
        pppppppiVar7 = (int *******)0x0;
      }
      else {
        pppppppiVar7[2] = ppppppiVar14;
      }
      *local_18 = (int *****)pppppppiVar7;
      pppppppiVar7[1] = local_18;
      *pppppppiVar7 = (int ******)&local_1c;
      local_20 = local_1c;
      local_18 = (int ******)pppppppiVar7;
    }
    piVar12 = (int *)(param_1 + 0x24);
    if (*(int *)(param_1 + 0x24) == 0) goto LAB_0052fd03;
    ppppppiVar14 = (int ******)(*(int *)(param_1 + 0x24) + -0x210);
    while( true ) {
      if (piVar12 == (int *)0x0) {
        ppppppiVar13 = (int ******)0x0;
      }
      else {
        ppppppiVar13 = (int ******)(param_1 + -0x1ec);
      }
      if (ppppppiVar14 == ppppppiVar13) break;
      if (((uint)ppppppiVar14[0xd1] & 1) != 0) {
        if (DAT_007349b4 == 0) {
          FUN_005649f0();
        }
        pppppppiVar7 = (int *******)FUN_00567160();
        if (pppppppiVar7 == (int *******)0x0) {
          pppppppiVar7 = (int *******)0x0;
        }
        else {
          pppppppiVar7[2] = ppppppiVar14;
        }
        *local_10 = (int *****)pppppppiVar7;
        pppppppiVar7[1] = local_10;
        *pppppppiVar7 = (int ******)&local_14;
        local_20 = local_1c;
        local_10 = (int ******)pppppppiVar7;
      }
      if (ppppppiVar14[0x84] == (int *****)0x0) {
LAB_0052fd03:
        ppppppiVar14 = (int ******)0x0;
      }
      else {
        ppppppiVar14 = (int ******)(ppppppiVar14[0x84] + -0x84);
      }
    }
    if (*piVar12 == 0) {
      ppppppiVar14 = (int ******)0x0;
    }
    else {
      ppppppiVar14 = (int ******)(*piVar12 + -0x210);
    }
    do {
      ppppppiVar13 = (int ******)0x0;
      while( true ) {
        pppppppiVar7 = (int *******)local_14;
        if (piVar12 == (int *)0x0) {
          ppppppiVar8 = (int ******)0x0;
        }
        else {
          ppppppiVar8 = (int ******)(param_1 + -0x1ec);
        }
        if (ppppppiVar14 == ppppppiVar8) break;
        pppppppiVar9 = (int *******)NullUpdate_ret();
        for (; pppppppiVar7 != pppppppiVar9; pppppppiVar7 = (int *******)*pppppppiVar7) {
          if (ppppppiVar14 == pppppppiVar7[2]) goto LAB_0052fdd4;
        }
        if ((ppppppiVar13 == (int ******)0x0) ||
           ((float)ppppppiVar14[0xc0] < (float)ppppppiVar13[0xc0])) {
          ppppppiVar13 = ppppppiVar14;
        }
LAB_0052fdd4:
        if (ppppppiVar14[0x84] == (int *****)0x0) {
          ppppppiVar14 = (int ******)0x0;
        }
        else {
          ppppppiVar14 = (int ******)(ppppppiVar14[0x84] + -0x84);
        }
      }
      if (ppppppiVar13 == (int ******)0x0) goto LAB_0052fe32;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      pppppppiVar7 = (int *******)FUN_00567160();
      if (pppppppiVar7 == (int *******)0x0) {
        pppppppiVar7 = (int *******)0x0;
      }
      else {
        pppppppiVar7[2] = ppppppiVar13;
      }
      *local_10 = (int *****)pppppppiVar7;
      pppppppiVar7[1] = local_10;
      *pppppppiVar7 = (int ******)&local_14;
      local_20 = local_1c;
      local_10 = (int ******)pppppppiVar7;
    } while( true );
  }
  ExceptionList = &local_c;
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)(param_1 + 4);
      puVar1 = (undefined4 *)*puVar1) {
    (**(code **)(*(int *)puVar1[2] + 0x50))();
  }
LAB_0052feee:
  piVar12 = (int *)(param_1 + 4);
  piVar3 = *(int **)(param_1 + 4);
  iVar10 = DAT_007349b4;
  while (piVar3 != piVar12) {
    piVar3 = (int *)*piVar12;
    iVar11 = *piVar3;
    piVar4 = (int *)piVar3[1];
    *piVar4 = iVar11;
    *(int **)(iVar11 + 4) = piVar4;
    iVar11 = *(int *)(iVar10 + 0x18);
    *piVar3 = *(int *)(iVar10 + 0x10);
    *(int **)(iVar10 + 0x10) = piVar3;
    iVar11 = iVar11 + -1;
    bVar15 = DAT_007349b8 != 0;
    *(int *)(iVar10 + 0x18) = iVar11;
    if (bVar15) {
      if (iVar11 == 0) {
        SlotPool__Destroy();
        iVar10 = 0;
        DAT_007349b4 = 0;
      }
      else {
        DAT_007349b8 = 1;
      }
    }
    piVar3 = (int *)*piVar12;
  }
  for (piVar3 = (int *)*piVar12; piVar3 != piVar12; piVar3 = (int *)*piVar3) {
  }
  *piVar12 = (int)piVar12;
  *(int **)(param_1 + 8) = piVar12;
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = local_c;
  return;
LAB_0052fe32:
  bVar5 = true;
  bVar15 = false;
  pppppppiVar7 = (int *******)local_10;
  do {
    ppppppiVar14 = (int ******)local_20[2];
    ppppppiVar13 = pppppppiVar7[2];
    if (((uint)ppppppiVar14[0xd1] & 1) == 0) {
      if (((uint)ppppppiVar13[0xd1] & 1) == 0) {
        if ((float)ppppppiVar14[0xc0] < (float)ppppppiVar13[0xc0]) goto LAB_0052fe78;
      }
      else {
        bVar5 = false;
      }
LAB_0052fe96:
      if (!bVar15) break;
    }
    else {
      if (((uint)ppppppiVar13[0xd1] & 1) != 0) goto LAB_0052fe96;
LAB_0052fe78:
      (*(code *)(*ppppppiVar13)[0x1f])();
      *(undefined1 *)((int)ppppppiVar13 + 0x34e) = 0;
      (*(code *)(*ppppppiVar14)[0x14])();
      bVar15 = true;
    }
    if (pppppppiVar7 == (int *******)local_14) break;
    local_20 = (int ******)*local_20;
    pppppppiVar7 = (int *******)pppppppiVar7[1];
    pppppppiVar9 = (int *******)NullUpdate_ret();
    if (((int *******)local_20 == pppppppiVar9) || (!bVar5)) break;
  } while( true );
  local_4 = local_4 & 0xffffff00;
  FUN_00421900();
  local_4 = 0xffffffff;
  FUN_00421900();
  goto LAB_0052feee;
}


// ==== 0x52ff90 FUN_0052ff90

void __thiscall FUN_0052ff90(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  
  FUN_0052fb60(param_1);
  puVar1 = (undefined4 *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(*(int *)(param_1 + 0x24) + -0x210);
  }
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)(param_1 + -0x1ec);
    }
    if (piVar5 == piVar6) break;
    (**(code **)(*piVar5 + 0x5c))(param_2);
    if (((*(char *)((int)piVar5 + 0x34e) == '\0') && ((char)piVar5[0xd4] == '\0')) &&
       (*(char *)((int)piVar5 + 0x351) != '\0')) {
      if (piVar5[0x84] == 0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)(piVar5[0x84] + -0x210);
      }
      piVar2 = (int *)piVar5[0x85];
      iVar3 = piVar5[0x84];
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
      DAT_00735618 = DAT_00735618 + -1;
      (**(code **)*piVar5)(1);
      piVar5 = piVar6;
    }
    else if (piVar5[0x84] == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(piVar5[0x84] + -0x210);
    }
  }
  if (DAT_00735628 < DAT_00735620) {
    DAT_00735628 = DAT_00735620;
  }
  if (DAT_0073562c < DAT_00735624) {
    DAT_0073562c = DAT_00735624;
  }
  if (DAT_00735624 + DAT_00735620 == 0) {
    for (puVar4 = (undefined4 *)*puVar1; (puVar4 != puVar1 && (puVar4 != (undefined4 *)0x0));
        puVar4 = (undefined4 *)*puVar4) {
    }
  }
  return;
}


// ==== 0x530090 FUN_00530090

void __fastcall FUN_00530090(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  if (DAT_006f1dd8 != 0) {
    if (*(int *)(param_1 + 0x24) == 0) goto LAB_005300ac;
    piVar3 = (int *)(*(int *)(param_1 + 0x24) + -0x210);
    while( true ) {
      if (param_1 == -0x24) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)(param_1 + -0x1ec);
      }
      if (piVar3 == piVar2) {
        return;
      }
      if (piVar3[0x87] == param_2) break;
      if (piVar3[0x84] == 0) {
LAB_005300ac:
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(piVar3[0x84] + -0x210);
      }
    }
    if (((char)piVar3[0xd4] == '\0') && (cVar1 = (**(code **)(*piVar3 + 0x48))(), cVar1 != '\0')) {
      *(undefined1 *)((int)piVar3 + 0x21b) = 1;
    }
  }
  return;
}


// ==== 0x530100 FUN_00530100

void __fastcall FUN_00530100(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  
  if (DAT_006f1dd8 == 0) {
    return;
  }
  if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
    return;
  }
  iVar3 = *(int *)(param_2 + 0x24);
  if ((iVar3 != 0) && (iVar3 != 0x210)) {
    while( true ) {
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + -0x210;
      }
      if (param_2 + 0x24 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_2 + -0x1ec;
      }
      if (iVar3 == iVar6) break;
      if (*(int *)(iVar3 + 0x21c) == param_3) {
        return;
      }
      iVar3 = *(int *)(iVar3 + 0x210);
    }
  }
  iVar3 = FUN_0052f6f0();
  if (iVar3 == 0) {
LAB_00530189:
    pvVar4 = _malloc(0x360);
    if (pvVar4 == (void *)0x0) {
LAB_005301e5:
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0052f570();
    }
  }
  else {
    if (iVar3 != 1) {
      if (iVar3 == 2) {
        pvVar4 = _malloc(0x370);
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
          puVar7 = &DAT_006f4810;
        }
        else {
          piVar5 = (int *)FUN_00532370();
          puVar7 = &DAT_006f4810;
        }
        goto LAB_005301ec;
      }
      goto LAB_00530189;
    }
    pvVar4 = _malloc(0x370);
    if (pvVar4 == (void *)0x0) goto LAB_005301e5;
    piVar5 = (int *)FUN_0052f520();
  }
  puVar7 = &DAT_006f47a0;
LAB_005301ec:
  (**(code **)(*piVar5 + 0x10))(puVar7);
  (**(code **)(*piVar5 + 0x24))();
  piVar5[0x87] = param_3;
  piVar2 = *(int **)(param_2 + 0x28);
  piVar1 = piVar5 + 0x84;
  *piVar2 = (int)piVar1;
  *(int **)(param_2 + 0x28) = piVar1;
  piVar5[0x85] = (int)piVar2;
  iVar3 = DAT_0073561c;
  *piVar1 = param_2 + 0x24;
  DAT_00735618 = DAT_00735618 + 1;
  if (iVar3 < DAT_00735618) {
    DAT_0073561c = DAT_00735618;
  }
  return;
}


// ==== 0x530240 FUN_00530240

void __fastcall FUN_00530240(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int unaff_ESI;
  int *piVar4;
  
  if (DAT_006f1dd8 != 0) {
    piVar1 = (int *)(unaff_ESI + 0x24);
    for (piVar4 = *(int **)(unaff_ESI + 0x24); (piVar4 != piVar1 && (piVar4 != (int *)0x0));
        piVar4 = (int *)*piVar4) {
    }
    if (*piVar1 == 0) goto LAB_00530270;
    piVar4 = (int *)(*piVar1 + -0x210);
    while( true ) {
      if (piVar1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(unaff_ESI + -0x1ec);
      }
      if (piVar4 == piVar3) {
        return;
      }
      if ((piVar4[0x87] == param_2) && (*(char *)((int)piVar4 + 0x351) == '\0')) break;
      if (piVar4[0x84] == 0) {
LAB_00530270:
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(piVar4[0x84] + -0x210);
      }
    }
    if ((char)piVar4[0x86] == '\0') {
      (**(code **)(*piVar4 + 0x2c))(param_2);
    }
    if ((*(char *)((int)piVar4 + 0x34e) == '\0') && (cVar2 = FUN_0052fb30(unaff_ESI), cVar2 == '\0')
       ) {
      cVar2 = (**(code **)(*piVar4 + 0x44))();
      if (cVar2 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x005302ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar4 + 0x4c))();
        return;
      }
      FUN_0052fb00();
    }
  }
  return;
}


// ==== 0x5302f0 FUN_005302f0

void __fastcall FUN_005302f0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if (DAT_006f1dd8 != 0) {
    iVar1 = *(int *)(param_2 + 0x24);
    while( true ) {
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + -0x210;
      }
      if (param_2 == -0x24) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_2 + -0x1ec;
      }
      if (iVar1 == iVar2) break;
      if (*(int *)(iVar1 + 0x21c) == unaff_ESI) {
        FUN_005307e0();
        return;
      }
      iVar1 = *(int *)(iVar1 + 0x210);
    }
  }
  return;
}


// ==== 0x530340 FUN_00530340

/* WARNING: Removing unreachable block (ram,0x005304d6) */
/* WARNING: Removing unreachable block (ram,0x005303f8) */
/* WARNING: Removing unreachable block (ram,0x00530387) */
/* WARNING: Removing unreachable block (ram,0x00530467) */
/* WARNING: Removing unreachable block (ram,0x00530547) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00530340(void)

{
  _DAT_0073676c = 0;
  _DAT_00736774 = 0;
  _DAT_00736770 = 0x3f800000;
  _DAT_00736778 = 0x40400000;
  _DAT_00736788 = 0;
  _DAT_00736780 = 0;
  _DAT_00736790 = 0x40a00000;
  _DAT_0073678c = 0x3f800000;
  _DAT_0073677c = 0;
  _DAT_00736794 = 0x41700000;
  _DAT_007367a4 = 0;
  _DAT_0073679c = 0;
  _DAT_007367ac = 0;
  _DAT_00736798 = 0;
  _DAT_007367a8 = 0x3f800000;
  _DAT_007367b0 = 0x40400000;
  _DAT_007367c0 = 0;
  _DAT_007367b8 = 0;
  _DAT_007367c8 = 0;
  _DAT_007367b4 = 0;
  _DAT_007367c4 = 0x3f800000;
  _DAT_007367cc = 0x42200000;
  _DAT_007367dc = 0;
  _DAT_007367d4 = 0;
  _DAT_007367e4 = 0;
  _DAT_007367e0 = 0x3f800000;
  _DAT_007367d0 = 0;
  _DAT_007367e8 = 0x40400000;
  _DAT_007367ec = 0;
  _DAT_007367f0 = 0;
  return;
}


// ==== 0x530570 FUN_00530570

void FUN_00530570(void)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_EDX;
  undefined4 *unaff_ESI;
  
  EAXS_3DMixer__EAXS_3DMixer();
  *unaff_ESI = &PTR_FUN_006be5b8;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  *(undefined1 *)(unaff_ESI + 0xb4) = 4;
  *(undefined1 *)((int)unaff_ESI + 0x2d1) = 0xc;
  *(undefined1 *)((int)unaff_ESI + 0x2d2) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x2d3) = 0;
  unaff_ESI[0xb3] = &PTR_FUN_006b9694;
  unaff_ESI[0xb5] = 0;
  unaff_ESI[0xb6] = 0;
  unaff_ESI[0xb7] = unaff_ESI + 0xb8;
  puVar1 = _malloc(0x30);
  unaff_ESI[0xb7] = puVar1;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  unaff_ESI[0xc9] = 0;
  unaff_ESI[0xca] = 0;
  *(undefined1 *)((int)unaff_ESI + 0x34e) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x34f) = 0;
  *(undefined1 *)(unaff_ESI + 0xd4) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x219) = 0;
  *(undefined1 *)(unaff_ESI + 0xbd) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x351) = 0;
  unaff_ESI[0x90] = 0;
  unaff_ESI[0x91] = 0;
  *(undefined1 *)(unaff_ESI + 0xd3) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x34d) = 0;
  *(undefined1 *)(unaff_ESI + 0x86) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x21a) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x21b) = 0;
  unaff_ESI[0x8c] = 0x3f800000;
  unaff_ESI[0x8d] = 0;
  unaff_ESI[0x8e] = 0;
  unaff_ESI[0x92] = 0;
  unaff_ESI[0x93] = 0;
  FUN_00584310(0);
  unaff_ESI[0xcc] = 0;
  unaff_ESI[0xcb] = 0;
  return;
}


// ==== 0x530680 FUN_00530680

void * __thiscall FUN_00530680(void *param_1,byte param_2)

{
  FUN_005306a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5306a0 FUN_005306a0

void __fastcall FUN_005306a0(int *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684db6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = (int)&PTR_FUN_006be5b8;
  local_4 = 1;
  if (param_1[0xc9] != 0) {
    FUN_00530e20();
    *(undefined1 *)((int)param_1 + 0x34e) = 0;
  }
  if (param_1[0xca] != 0) {
    (**(code **)(*param_1 + 0x80))();
    *(undefined1 *)(param_1 + 0xd4) = 0;
  }
  param_1[0xb3] = (int)&PTR_FUN_006b9694;
  if ((int *)param_1[0xb7] != param_1 + 0xb8) {
    _free((int *)param_1[0xb7]);
  }
  param_1[0xb3] = (int)&PTR_FUN_006c7d78;
  *param_1 = (int)&PTR_FUN_006be7c4;
  ExceptionList = local_c;
  return;
}


// ==== 0x530740 stSoundCollision::AdjustVolume

/* [canon] audio med (ghidra) docs/re/sound.md */

void stSoundCollision__AdjustVolume(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *unaff_ESI;
  
  *unaff_ESI = *(int *)(in_EAX + 0x50) * *unaff_ESI >> 0xf;
  iVar1 = *(int *)(in_EAX + 0x32c);
  iVar3 = DAT_007356b0;
  if ((iVar1 != 0) &&
     (((iVar2 = *(int *)(*(int *)(iVar1 + 0x14) + 4), iVar2 == 1 || (iVar2 == 2)) &&
      (*(int *)(iVar1 + 0x878) != 0)))) {
    iVar3 = *(int *)(*(int *)(iVar1 + 0x878) + 0x264);
    if (iVar3 < 1) {
      iVar3 = 0;
    }
    else if (3 < iVar3) {
      iVar3 = 3;
    }
  }
  if (iVar3 < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *unaff_ESI = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      *unaff_ESI = 0;
    }
    *unaff_ESI = *(int *)(iVar3 * 0xd10 + 0x858 + DAT_007356ac) * *unaff_ESI >> 0xf;
  }
  return;
}


// ==== 0x5307e0 FUN_005307e0

void FUN_005307e0(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x351) == '\0') {
    *(undefined1 *)(in_EAX + 0x351) = 1;
    *(undefined4 *)(in_EAX + 0x21c) = 0;
    if (*(char *)(in_EAX + 0x350) != '\0') {
      *(undefined1 *)(in_EAX + 0x2f4) = 1;
      FUN_00532640();
      FUN_00532670(0x3f800000,0,0x85,0);
      *(undefined4 *)(in_EAX + 0x2c4) = 0x3f800000;
    }
  }
  return;
}


// ==== 0x530840 FUN_00530840

void __fastcall FUN_00530840(int *param_1)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar4 = param_1[0x87];
  iVar3 = *(int *)(iVar4 + 0x24);
  iVar1 = *(int *)(iVar4 + 0x28);
  param_1[0x88] = *(int *)(iVar4 + 0x20);
  param_1[0x89] = iVar3;
  param_1[0x8a] = iVar1;
  iVar4 = param_1[0x87];
  iVar3 = *(int *)(iVar4 + 0x74);
  iVar1 = *(int *)(iVar4 + 0x78);
  param_1[0x8c] = *(int *)(iVar4 + 0x70);
  param_1[0x8d] = iVar3;
  param_1[0x8e] = iVar1;
  iVar3 = FUN_0052f6f0();
  param_1[0xcf] = iVar3;
  iVar3 = (**(code **)(*param_1 + 0x60))();
  param_1[0xd0] = iVar3;
  iVar3 = FUN_0052f650();
  param_1[0xd1] = iVar3;
  fVar6 = (float10)FUN_00421400();
  param_1[0xc0] = (int)(float)fVar6;
  iVar3 = param_1[0x87];
  *(undefined1 *)((int)param_1 + 0x34e) = 0;
  *(undefined1 *)(param_1 + 0xd4) = 0;
  iVar1 = *(int *)(iVar3 + 100);
  if ((*(char *)(*(int *)(iVar1 + 600) + 0x15) == '\x01') ||
     (*(char *)(*(int *)(iVar1 + 0x25c) + 0x15) == '\x01')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  *(undefined1 *)((int)param_1 + 0x34d) = uVar2;
  uVar2 = Collision__IsPlayerInvolved();
  *(undefined1 *)(param_1 + 0xd3) = uVar2;
  param_1[0xd2] = DAT_0078eab0;
  DAT_0078eab0 = DAT_0078eab0 + 1;
  param_1[0xbe] = (int)&DAT_007367a4;
  param_1[0xbf] = (int)&DAT_007367c0;
  *(undefined1 *)(param_1 + 0x86) = 1;
  if ((param_1[0xd1] & 0x10U) == 0) goto LAB_00530a27;
  iVar3 = *(int *)(iVar3 + 100);
  iVar1 = *(int *)(iVar3 + 600);
  iVar5 = 0;
  iVar4 = 0;
  if (*(char *)(iVar1 + 0x15) == '\0') {
    iVar4 = *(int *)(iVar1 + 0x140);
  }
  iVar3 = *(int *)(iVar3 + 0x25c);
  if (*(char *)(iVar3 + 0x15) == '\0') {
    iVar5 = *(int *)(iVar3 + 0x140);
  }
  iVar3 = iVar5;
  if ((iVar4 == 0) || (iVar3 = iVar4, iVar5 == 0)) {
LAB_00530a09:
    param_1[0xcb] = iVar3;
  }
  else if ((param_1[0xd1] & 1U) == 0) {
    if (*(float *)(iVar5 + 0x3d4) * 2.237 < *(float *)(iVar4 + 0x3d4) * 2.237) goto LAB_00530a09;
    param_1[0xcb] = iVar5;
  }
  else if (*(int *)(*(int *)(iVar4 + 0x14) + 4) == 1) {
    if ((*(int *)(*(int *)(iVar5 + 0x14) + 4) != 1) ||
       (*(float *)(iVar4 + 0x3d4) * 2.237 <= *(float *)(iVar5 + 0x3d4) * 2.237)) goto LAB_00530a09;
    param_1[0xcb] = iVar5;
  }
  else {
    param_1[0xcb] = iVar5;
  }
  param_1[0xcc] = (int)(*(float *)(param_1[0xcb] + 0x3d4) * 2.237);
LAB_00530a27:
  param_1[0x90] = *(int *)(&DAT_006f4f08 + param_1[0xd0] * 4);
  (**(code **)(*param_1 + 0x38))();
  return;
}


// ==== 0x530a50 stSoundCollision::UpdateQueue

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall stSoundCollision__UpdateQueue(int *param_1,undefined4 param_2)

{
  if ((char)param_1[0x86] != '\0') {
    if (*(char *)((int)param_1 + 0x21b) != '\0') {
      stSoundCollision__BeginScrape();
      *(undefined1 *)((int)param_1 + 0x21b) = 0;
    }
    if (*(char *)((int)param_1 + 0x351) == '\0') {
      if ((float)(DAT_0073ad34 - *(int *)(param_1[0x87] + 0xc)) * 0.00025 < _DAT_007000d8) {
        stSoundCollision__CalcCollisionPositionData();
      }
      else {
        FUN_005307e0();
      }
    }
    if (((DAT_006f1dd8 != 0) && (*(char *)((int)param_1 + 0x34e) != '\0')) && (param_1[0xc9] != 0))
    {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        param_1[0xc1] = 0;
      }
      (**(code **)(*param_1 + 0x6c))();
    }
    stSoundCollision__UpdateScrapeParams(param_2);
    if (*(char *)((int)param_1 + 0x351) != '\0') {
      FUN_00530b30(param_2);
    }
  }
  return;
}


// ==== 0x530b30 FUN_00530b30

void FUN_00530b30(void)

{
  char cVar1;
  int *unaff_ESI;
  
  cVar1 = (**(code **)(*unaff_ESI + 0x74))();
  if (cVar1 == '\0') {
    (**(code **)(*unaff_ESI + 0x7c))();
    *(undefined1 *)((int)unaff_ESI + 0x34e) = 0;
  }
  if (((char)unaff_ESI[0xbd] != '\0') && ((char)unaff_ESI[0xb2] != '\0')) {
    (**(code **)(*unaff_ESI + 0x80))();
    *(undefined1 *)(unaff_ESI + 0xd4) = 0;
  }
  return;
}


// ==== 0x530b80 FUN_00530b80

void __fastcall FUN_00530b80(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((param_1[0xc9] == 0) && (DAT_006f1dd8 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    puVar1 = (undefined4 *)(**(code **)*local_10)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      local_10 = puVar1;
      uVar2 = FUN_005259e0(param_1[0xcd],param_1[199]);
    }
    param_1[0xc9] = uVar2;
    DAT_00735624 = DAT_00735624 + 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x530c30 FUN_00530c30

void __fastcall FUN_00530c30(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((param_1[0xca] == 0) && (DAT_006f1dd8 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    puVar1 = (undefined4 *)(**(code **)*local_10)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      local_10 = puVar1;
      uVar2 = FUN_0052f380(param_1[200]);
    }
    param_1[0xca] = uVar2;
    DAT_00735620 = DAT_00735620 + 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x530ce0 FUN_00530ce0

void __fastcall FUN_00530ce0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x324);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 0x30c);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    piVar1[3] = iVar2;
    iVar2 = *(int *)(param_1 + 0x31c);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7f < iVar2) {
      iVar2 = 0x7f;
    }
    piVar1[5] = iVar2;
    iVar2 = *(int *)(param_1 + 0x304);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    piVar1[1] = iVar2;
    iVar2 = *(int *)(param_1 + 0x314);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (9000 < iVar2) {
      iVar2 = 9000;
    }
    piVar1[2] = iVar2;
    if (*piVar1 != 0) {
      FUN_0064bc30(piVar1 + 1);
    }
  }
  return;
}


// ==== 0x530d80 FUN_00530d80

void __fastcall FUN_00530d80(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x328);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 0x310);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    piVar1[3] = iVar2;
    iVar2 = *(int *)(param_1 + 800);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7f < iVar2) {
      iVar2 = 0x7f;
    }
    piVar1[5] = iVar2;
    iVar2 = *(int *)(param_1 + 0x308);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    piVar1[1] = iVar2;
    iVar2 = *(int *)(param_1 + 0x318);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (9000 < iVar2) {
      iVar2 = 9000;
    }
    piVar1[2] = iVar2;
    if (*piVar1 != 0) {
      FUN_0064bc30(piVar1 + 1);
    }
  }
  return;
}


// ==== 0x530e20 FUN_00530e20

void __fastcall FUN_00530e20(int *param_1)

{
  int *piVar1;
  int *local_4;
  
  piVar1 = (int *)param_1[0xc9];
  if (piVar1 != (int *)0x0) {
    local_4 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    DAT_00735624 = DAT_00735624 + -1;
    param_1[0xc9] = 0;
  }
  return;
}


// ==== 0x530e80 stSoundCollision::UpdateScrapeParams

/* [canon] audio med (ghidra) docs/re/sound.md */

void stSoundCollision__UpdateScrapeParams(int param_1)

{
  int *unaff_EDI;
  
  if ((DAT_006f1dd8 != 0) && ((char)unaff_EDI[0xd4] != '\0')) {
    FUN_005326f0(param_1);
    FUN_00584270((float)unaff_EDI[0x13]);
    param_1 = unaff_EDI[0x91];
    if ((char)unaff_EDI[0xbd] != '\0') {
      param_1 = _ftol_nocw();
    }
    stSoundCollision__AdjustVolume();
    (**(code **)(*unaff_EDI + 0x34))();
    unaff_EDI[0xc2] = param_1;
    unaff_EDI[200] = unaff_EDI[0x93];
    (**(code **)(*unaff_EDI + 0x70))();
  }
  return;
}


// ==== 0x530f20 stSoundCollision::CalcCollisionPositionData

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall stSoundCollision__CalcCollisionPositionData(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  
  iVar1 = *(int *)(param_1 + 0x21c);
  local_30 = *(undefined4 *)(iVar1 + 0x30);
  local_2c = *(undefined4 *)(iVar1 + 0x34);
  local_28 = *(undefined4 *)(iVar1 + 0x38);
  *(undefined4 *)(param_1 + 0x220) = local_30;
  *(undefined4 *)(param_1 + 0x224) = local_2c;
  *(undefined4 *)(param_1 + 0x228) = local_28;
  local_18 = local_28;
  EAXS_3DMixer__Update3DMix(&local_30,0);
  return;
}


// ==== 0x530f80 FUN_00530f80

void __fastcall FUN_00530f80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float afStack_1c [4];
  undefined4 uStack_c;
  float fStack_8;
  char cStack_4;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x60);
  iVar1 = *(int *)(param_1 + 0x340);
  pfVar4 = *(float **)(param_1 + 0x2f8);
  pfVar5 = afStack_1c;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  afStack_1c[3] = afStack_1c[3] * *(float *)(&DAT_006b6450 + iVar1 * 4);
  if (ABS(afStack_1c[3] - afStack_1c[2]) < 1e-06) {
    afStack_1c[3] = afStack_1c[3] + 1e-06;
  }
  fStack_8 = afStack_1c[0];
  uStack_c = uVar2;
  EAX_linear_ramp_evaluate__not_SetCsisName_();
  if (cStack_4 != '\0') {
    EAX_linear_ramp_evaluate__not_SetCsisName_();
  }
  uVar2 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x248) = uVar2;
  return;
}


