// ==== 0x401000 FUN_00401000

void __fastcall FUN_00401000(undefined4 param_1)

{
  FUN_00565b60(param_1,0,0);
  return;
}


// ==== 0x401010 ScratchAlloc16

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int ScratchAlloc16(void)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  
  uVar2 = in_EAX + 0xfU & 0xfffffff0;
  uVar1 = DAT_007355b4 + uVar2;
  if (DAT_007355b8 <= uVar1) {
    DAT_007355c4 = 1;
    DAT_007355c8 = DAT_007355c8 + uVar2;
    return 0;
  }
  iVar3 = DAT_007355b4;
  DAT_007355b4 = uVar1;
  return iVar3;
}


// ==== 0x401050 ScratchAlloc64xN

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

int ScratchAlloc64xN(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  
  uVar1 = DAT_007355b4 + in_EAX * 0x40;
  if (DAT_007355b8 <= uVar1) {
    DAT_007355c4 = 1;
    DAT_007355c8 = DAT_007355c8 + in_EAX * 0x40;
    return 0;
  }
  iVar2 = DAT_007355b4;
  DAT_007355b4 = uVar1;
  return iVar2;
}


// ==== 0x4010a0 CallNTimes

/* [canon] runtime low (ghidra+hopper) docs/re/runtime.md */

void CallNTimes(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  if (-1 < param_3 + -1) {
    do {
      (*param_4)();
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== 0x4010d0 FUN_004010d0

undefined4 FUN_004010d0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


// ==== 0x4010e0 SetSpecialCameraFlag

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render I (C) docs/re/blur.md */

undefined4 SetSpecialCameraFlag(byte param_1,int param_2)

{
  if (*(int *)(&DAT_00740464 + param_2 * 0x60) == 1) {
    _gSpecialCameraActive = (uint)param_1;
  }
  return 0;
}


// ==== 0x401110 FUN_00401110

void FUN_00401110(void)

{
  FUN_00564860();
  if (DAT_007349b0 == 0) {
    DAT_007301d4 = &DAT_007301f8;
    bInitMemoryPool(0,"Main Pool");
    DAT_007349b0 = 1;
  }
  FUN_0063e850();
  FUN_0063ec20(100);
  FUN_00401980();
  FUN_0041c3c0();
  return;
}


// ==== 0x401160 FUN_00401160

void FUN_00401160(undefined4 param_1,undefined4 param_2)

{
  FUN_00565b60(param_2,0,0,0);
  return;
}


// ==== 0x401180 FUN_00401180

undefined4 FUN_00401180(void)

{
  FUN_00565ce0();
  return 1;
}


// ==== 0x401190 FUN_00401190

undefined4 FUN_00401190(void)

{
  undefined **ppuVar1;
  BYTE BVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  BYTE *pBVar8;
  char *lpSubKey;
  DWORD local_11c;
  HKEY local_118;
  DWORD local_114;
  BYTE local_110 [268];
  
  if (DAT_00734998 == 0) {
    lpSubKey = "Software\\EA Games\\Need For Speed Underground";
  }
  else {
    lpSubKey = "Software\\EA Games\\NFS Underground";
  }
  LVar3 = RegOpenKeyExA((HKEY)0x80000002,lpSubKey,0,0x20019,&local_118);
  if (LVar3 != 0) {
    RegCloseKey(local_118);
    return 0;
  }
  pBVar8 = local_110;
  for (iVar6 = 0x41; iVar6 != 0; iVar6 = iVar6 + -1) {
    pBVar8[0] = '\0';
    pBVar8[1] = '\0';
    pBVar8[2] = '\0';
    pBVar8[3] = '\0';
    pBVar8 = pBVar8 + 4;
  }
  local_114 = 1;
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"Install Dir",(LPDWORD)0x0,&local_114,local_110,&local_11c);
  if ((LVar3 == 0) &&
     (DVar4 = GetLongPathNameA((LPCSTR)local_110,(LPSTR)local_110,0x104), DVar4 != 0)) {
    iVar6 = 0;
    do {
      BVar2 = local_110[iVar6];
      (&DAT_007184dc)[iVar6] = BVar2;
      iVar6 = iVar6 + 1;
    } while (BVar2 != '\0');
  }
  pBVar8 = local_110;
  for (iVar6 = 0x41; iVar6 != 0; iVar6 = iVar6 + -1) {
    pBVar8[0] = '\0';
    pBVar8[1] = '\0';
    pBVar8[2] = '\0';
    pBVar8[3] = '\0';
    pBVar8 = pBVar8 + 4;
  }
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"CD Drive",(LPDWORD)0x0,&local_114,local_110,&local_11c);
  if (LVar3 == 0) {
    DVar4 = GetLongPathNameA((LPCSTR)local_110,(LPSTR)local_110,0x104);
    GetLastError();
    if (DVar4 != 0) {
      iVar6 = 0;
      do {
        BVar2 = local_110[iVar6];
        (&DAT_007183d8)[iVar6] = BVar2;
        iVar6 = iVar6 + 1;
      } while (BVar2 != '\0');
    }
  }
  iVar6 = 0;
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"CacheSize",(LPDWORD)0x0,&local_114,local_110,&local_11c);
  if (LVar3 == 0) {
    DAT_007185e0 = _atoi((char *)local_110);
    DAT_007185e4 = DAT_007185e0 >> 0x1f;
  }
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"SwapSize",(LPDWORD)0x0,&local_114,local_110,&local_11c);
  if (LVar3 == 0) {
    DAT_007185e8 = _atoi((char *)local_110);
    DAT_007185ec = DAT_007185e8 >> 0x1f;
  }
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"Language",(LPDWORD)0x0,&local_114,local_110,&local_11c);
  if (LVar3 == 0) {
    if (PTR_s_English_US_00704310 != (undefined *)0x0) {
      ppuVar7 = &PTR_s_English_US_00704310;
      do {
        iVar5 = __stricmp((char *)local_110,*ppuVar7);
        if (iVar5 == 0) {
          DAT_0070430c = (&DAT_00704314)[iVar6 * 3];
          break;
        }
        ppuVar1 = ppuVar7 + 3;
        ppuVar7 = ppuVar7 + 3;
        iVar6 = iVar6 + 1;
      } while (*ppuVar1 != (undefined *)0x0);
    }
  }
  else {
    DAT_0070430c = 0;
  }
  local_11c = 0x104;
  LVar3 = RegQueryValueExA(local_118,"StreamingInstall",(LPDWORD)0x0,&local_114,local_110,&local_11c
                          );
  if (LVar3 != 0) {
    DAT_007363b4 = 1;
    RegCloseKey(local_118);
    return 1;
  }
  iVar6 = __stricmp((char *)local_110,"off");
  DAT_007363b4 = iVar6 != 0;
  RegCloseKey(local_118);
  return 1;
}


// ==== 0x401430 FUN_00401430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401430(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  code **ppcVar4;
  code *local_28 [4];
  int local_18;
  int local_14;
  undefined1 *local_10;
  int local_8;
  int local_4;
  
  ppcVar4 = local_28;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar4 = (code *)0x0;
    ppcVar4 = ppcVar4 + 1;
  }
  local_28[0] = (code *)0x28;
  local_28[1] = FUN_00401160;
  local_28[2] = FUN_00401180;
  pcVar1 = &DAT_007183d8;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  if (pcVar2 != &DAT_007183d8) {
    pcVar1 = &DAT_007184dc;
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    if (pcVar2 != &DAT_007184dc) {
      if (DAT_007185e0 == 0 && DAT_007185e4 == 0) {
        DAT_007185e0 = 1;
        DAT_007185e4 = 0;
      }
      if (DAT_007185e8 == 0 && DAT_007185ec == 0) {
        DAT_007185e8 = 1;
        DAT_007185ec = 0;
      }
      local_10 = &DAT_007183d8;
      local_28[3] = (code *)&DAT_007184dc;
      local_18 = DAT_007185e0;
      local_14 = DAT_007185e4;
      local_8 = DAT_007185e8;
      local_4 = DAT_007185ec;
    }
  }
  FUN_0063abd0(local_28);
  _DAT_0078eb9c = 1;
  return;
}


// ==== 0x401520 DiscCheck_ModalFrameLoop

/* [canon] render med (hopper+ghidra+capstone) docs/re/render.md */

undefined4 __fastcall DiscCheck_ModalFrameLoop(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  if (DAT_0073636c != (int *)0x0) {
    cVar1 = FUN_00411ab0(param_1);
    if (cVar1 == '\0') {
      if (DAT_00735788 == 0) {
        FEManager__ShowPackage();
      }
      else {
        FEManager__PushPackageChecked(0xee,0xff);
      }
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,0);
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,0);
      do {
        if (DAT_00736124 != 0) break;
        if (DAT_0073636c != (int *)0x0) {
          (**(code **)(*DAT_0073636c + 0xa4))(DAT_0073636c);
          FUN_004fa0f0();
          (**(code **)(*DAT_0073636c + 0xa8))(DAT_0073636c);
          iVar2 = (**(code **)(*DAT_0073636c + 0x44))(DAT_0073636c,0,0,0,0);
          if (iVar2 == -0x7789f798) {
            iVar2 = (**(code **)(*DAT_0073636c + 0xc))(DAT_0073636c);
            if (iVar2 == -0x7789f797) {
              Device_HandleLost();
            }
          }
          (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,7,0,0x3f800000,0);
        }
        FEManager__Update();
        Input__DropUnpluggedWheels();
        Input__AssignNewWheels();
        Input__SelectActionMapForGameState();
        DAT_00736514 = 0;
        DAT_00736515 = 0;
        EZWheel__Poll();
        DAT_0073650c = 1;
        InputEvents__Update();
        FUN_004130d0(&DAT_00706498,0);
        cVar1 = FUN_00411ab0();
        FUN_00411030();
      } while (cVar1 == '\0');
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,1);
      cVar1 = '\0';
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
      if (cVar1 != '\0') {
        FUN_004f6240();
        return 0;
      }
      FUN_004f63a0("DiscErrorPC.fng");
    }
  }
  return 0;
}


// ==== 0x4016e0 FUN_004016e0

undefined4 FUN_004016e0(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  int *piStack_b0;
  int *piStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int *piStack_98;
  int *piStack_94;
  int *piStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  int *piStack_84;
  undefined4 uStack_80;
  undefined4 **ppuStack_7c;
  undefined4 *puStack_78;
  undefined4 *puStack_74;
  undefined4 *puStack_70;
  undefined4 *puStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  undefined4 local_50 [19];
  
  if (DAT_0073636c == (int *)0x0) {
    return 0;
  }
  puStack_64 = (undefined4 *)0x4016fd;
  RenderState_ResetDefaults();
  puStack_64 = (undefined4 *)0x0;
  puStack_68 = (undefined4 *)0x401709;
  SceneRTSelect();
  puStack_64 = (undefined4 *)0x401718;
  Effect_Select();
  puStack_68 = DAT_00740460;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_50[0xd] = 0;
  local_50[0xe] = 0;
  local_50[0] = 0x3f800000;
  local_50[5] = 0x3f800000;
  local_50[10] = 0x3f800000;
  local_50[0xf] = 0x3f800000;
  puVar3 = local_50;
  puVar4 = DAT_00740460;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puStack_64 = puStack_68 + 0x10;
  puStack_6c = puStack_68 + 0x20;
  puStack_70 = (undefined4 *)0x40178a;
  D3DXMatrixMultiply();
  puStack_70 = DAT_00740460 + 0x10;
  puStack_74 = DAT_00740460;
  puStack_78 = DAT_00740460 + 0x20;
  puVar3 = (undefined4 *)&stack0xffffffa4;
  puVar4 = puStack_70;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  ppuStack_7c = (undefined4 **)0x4017ac;
  D3DXMatrixMultiply();
  ppuStack_7c = &puStack_68;
  uStack_80 = 0x4017b8;
  Device_SetWorldMatrix();
  ppuStack_7c = (undefined4 **)0x0;
  uStack_80 = 7;
  piStack_84 = DAT_0073636c;
  uStack_88 = 0x4017cc;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_88 = 0;
  uStack_8c = 0xe;
  piStack_90 = DAT_0073636c;
  piStack_94 = (int *)0x4017dd;
  (**(code **)(*DAT_0073636c + 0xe4))();
  piStack_94 = DAT_0073636c;
  piStack_98 = (int *)0x4017eb;
  (**(code **)(*DAT_0073636c + 0xa4))();
  if (DAT_006f9228 != 0) {
    if (DAT_0073578c != 0) {
      piStack_98 = (int *)0x401803;
      FUN_004f5e90();
    }
    if ((DAT_006f9228 != 0) && (DAT_0073578c != 0)) {
      puVar1 = (undefined1 *)(DAT_0073578c + 4);
      *puVar1 = 1;
      piStack_98 = (int *)0x401824;
      FUN_004f0390();
      *puVar1 = 0;
      piStack_98 = (int *)DAT_007064a0;
      uStack_9c = DAT_0070649c;
      uStack_a0 = 0x401839;
      FEng__RenderPackages();
    }
  }
  piStack_98 = DAT_0073636c;
  uStack_9c = 0x40184a;
  (**(code **)(*DAT_0073636c + 0xa8))();
  uStack_9c = 0;
  uStack_a0 = 0;
  uStack_a4 = 0;
  uStack_a8 = 0;
  piStack_ac = DAT_0073636c;
  piStack_b0 = (int *)0x40185d;
  iVar2 = (**(code **)(*DAT_0073636c + 0x44))();
  if (iVar2 == -0x7789f798) {
    piStack_b0 = DAT_0073636c;
    uStack_b4 = 0x40186f;
    iVar2 = (**(code **)(*DAT_0073636c + 0xc))();
    if (iVar2 == -0x7789f797) {
      piStack_b0 = (int *)0x40187b;
      Device_HandleLost();
    }
  }
  piStack_b0 = (int *)0x0;
  uStack_b4 = 0x3f800000;
  uStack_b8 = 0;
  uStack_bc = 7;
  uStack_c0 = 0;
  uStack_c4 = 0;
  (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c);
  if (DAT_0073640c != (undefined4 *)0x0) {
    if (DAT_0073640c == &DAT_0071abb8) goto LAB_004018fa;
    (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
    (*(code *)DAT_0073640c[0x37])();
  }
  DAT_0073640c = &DAT_0071abb8;
  (*DAT_0071ac90)();
  (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
  (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,&uStack_c4,0);
LAB_004018fa:
  FEManager__Update();
  Input__DropUnpluggedWheels();
  Input__AssignNewWheels();
  Input__SelectActionMapForGameState();
  DAT_00736514 = 0;
  DAT_00736515 = 0;
  EZWheel__Poll();
  DAT_0073650c = 1;
  InputEvents__Update();
  FUN_004130d0(&DAT_00706498,0);
  FUN_00411030();
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,1);
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
  return 0;
}


// ==== 0x401980 FUN_00401980

void FUN_00401980(void)

{
  SetErrorMode(1);
  DAT_007184dc = 0;
  DAT_007183d8 = 0;
  DAT_007185e0 = 0;
  DAT_007185e4 = 0;
  DAT_007185e8 = 0;
  DAT_007185ec = 0;
  FUN_00401190();
  DAT_0070108f = DAT_007183d8;
  FUN_00401430();
  FileSystem_Create(0x10,0x100,0x30);
  FUN_004119d0();
  DAT_007363b4 = 0;
  DAT_007183d8 = DAT_0070108f;
  DAT_007183d9 = 0x5c;
  DAT_007183da = 0x5c;
  DAT_007183db = 0;
  return;
}


// ==== 0x401a10 FUN_00401a10

bool FUN_00401a10(void)

{
  char cVar1;
  HANDLE hObject;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_228 [4];
  char acStack_218 [260];
  char acStack_114 [264];
  char *pcStack_c;
  int iStack_8;
  
  puVar5 = local_228;
  for (iVar4 = 0x49; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar4 = 3;
  hObject = (HANDLE)CreateToolhelp32Snapshot(2,0);
  while( true ) {
    if (hObject == (HANDLE)0xffffffff) {
      return false;
    }
    iVar6 = 0;
    iVar2 = Process32First(hObject,&stack0xfffffdcc);
    while (iVar2 != 0) {
      pcVar3 = _strrchr(acStack_218,0x5c);
      if (pcVar3 == (char *)0x0) {
        iVar2 = 0;
        do {
          pcVar3 = acStack_218 + iVar2;
          acStack_114[iVar2] = *pcVar3;
          iVar2 = iVar2 + 1;
        } while (*pcVar3 != '\0');
      }
      else {
        pcVar3 = pcVar3 + 1;
        iVar2 = -(int)pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3[(int)(acStack_114 + iVar2)] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      iVar2 = __stricmp(pcStack_c,acStack_114);
      if (iVar2 == 0) {
        iVar6 = iVar6 + 1;
      }
      iVar2 = Process32Next(hObject,&stack0xfffffdc4);
    }
    CloseHandle(hObject);
    iVar4 = iVar4 + -1;
    if ((iVar6 <= iStack_8) || (iVar4 < 0)) break;
    Sleep(1000);
    hObject = (HANDLE)CreateToolhelp32Snapshot(2,0);
  }
  return iStack_8 < iVar6;
}


// ==== 0x401b30 GetSkuString

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

char * GetSkuString(void)

{
  switch(DAT_00734998) {
  case 0:
    return "14705";
  case 1:
    switch(DAT_006ee6f0) {
    case 0:
      return "EAE08004144";
    case 1:
      return "EAF08004144";
    case 2:
      return "EAD08004144";
    case 3:
      return "EAI08004144";
    case 4:
      return "EAS08004144";
    case 5:
      return "EAH08004144";
    case 6:
      return "EAN08004144";
    }
    break;
  case 2:
    return "SKU_KOREA";
  case 3:
    return "EMW-4139";
  case 4:
    return "SKU_TAIWAN";
  }
  return (char *)0x0;
}


// ==== 0x401bd0 bList::IsEmpty

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

bool bList__IsEmpty(void)

{
  int *in_EAX;
  
  return (int *)*in_EAX == in_EAX;
}


// ==== 0x401be0 bList::RemoveHead

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void bList__RemoveHead(void)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  iVar1 = *(int *)*in_EAX;
  piVar2 = (int *)((int *)*in_EAX)[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}


// ==== 0x401bf0 FUN_00401bf0

int __fastcall FUN_00401bf0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = (undefined4 *)*param_2;
      (puVar1 != param_2 && (iVar2 = iVar2 + 1, puVar1 != (undefined4 *)0x0));
      puVar1 = (undefined4 *)*puVar1) {
  }
  return iVar2;
}


// ==== 0x401c10 bDegreesToAngle16

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

int bDegreesToAngle16(void)

{
  int iVar1;
  
  iVar1 = _ftol_nocw();
  return iVar1 / 0x168;
}


// ==== 0x401c40 bMax_float

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

float10 bMax_float(float param_1,float param_2)

{
  if (param_2 < param_1) {
    return (float10)param_1;
  }
  return (float10)param_2;
}


// ==== 0x401c60 bMin

/* [canon] runtime high (ghidra-canon) docs/re/runtime.md */

float10 bMin(float param_1,float param_2)

{
  if (param_1 < param_2) {
    return (float10)param_1;
  }
  return (float10)param_2;
}


// ==== 0x401c79 FUN_00401c79

float10 __thiscall FUN_00401c79(float param_1,float param_2)

{
  float10 fVar1;
  float unaff_retaddr;
  
  Thunk_JumpViaRetAddrTable();
  if (unaff_retaddr < param_1) {
    unaff_retaddr = param_1;
  }
  fVar1 = (float10)unaff_retaddr;
  if ((float10)param_2 < fVar1) {
    fVar1 = (float10)param_2;
  }
  return fVar1;
}


// ==== 0x401c80 bClampF

/* [canon] runtime high (ghidra-canon) docs/re/runtime.md */

float10 bClampF(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  
  if (param_2 < param_1) {
    param_2 = param_1;
  }
  fVar1 = (float10)param_2;
  if ((float10)param_3 < fVar1) {
    fVar1 = (float10)param_3;
  }
  return fVar1;
}


// ==== 0x401cb0 bVector4Copy

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __fastcall bVector4Copy(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar2 = param_1[3];
  uVar1 = param_1[2];
  uVar3 = *param_1;
  in_EAX[1] = param_1[1];
  *in_EAX = uVar3;
  in_EAX[3] = uVar2;
  in_EAX[2] = uVar1;
  return;
}


// ==== 0x401cd0 bMatrixCopy_b

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __fastcall bMatrixCopy_b(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar2 = param_1[3];
  uVar1 = param_1[2];
  uVar3 = *param_1;
  in_EAX[1] = param_1[1];
  *in_EAX = uVar3;
  in_EAX[2] = uVar1;
  in_EAX[3] = uVar2;
  uVar2 = param_1[7];
  uVar1 = param_1[6];
  uVar3 = param_1[4];
  in_EAX[5] = param_1[5];
  in_EAX[4] = uVar3;
  in_EAX[6] = uVar1;
  in_EAX[7] = uVar2;
  uVar2 = param_1[0xb];
  uVar1 = param_1[10];
  uVar3 = param_1[8];
  in_EAX[9] = param_1[9];
  in_EAX[8] = uVar3;
  in_EAX[10] = uVar1;
  in_EAX[0xb] = uVar2;
  uVar2 = param_1[0xf];
  uVar1 = param_1[0xe];
  uVar3 = param_1[0xc];
  in_EAX[0xd] = param_1[0xd];
  in_EAX[0xc] = uVar3;
  in_EAX[0xf] = uVar2;
  in_EAX[0xe] = uVar1;
  return;
}


// ==== 0x401d60 FUN_00401d60

uint __fastcall FUN_00401d60(int param_1)

{
  int in_EAX;
  
  return param_1 + 7 + in_EAX & ~(param_1 - 1U);
}


// ==== 0x401d70 GameFlow::IsInFrontEnd

/* [canon] canon high (capstone) docs/re/gameflow.md */

bool __fastcall GameFlow__IsInFrontEnd(int param_1)

{
  return *(int *)(param_1 + 0x1c) == 3;
}


// ==== 0x401d80 FUN_00401d80

undefined4 __fastcall FUN_00401d80(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x28 + param_1 * 4);
}


// ==== 0x401d90 FUN_00401d90

int __fastcall FUN_00401d90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0x2e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_00736538 = DAT_00736538 + 1;
  return param_1;
}


// ==== 0x401db0 FUN_00401db0

void FUN_00401db0(void)

{
  DAT_00736538 = DAT_00736538 + -1;
  return;
}


// ==== 0x401dc0 Node_SetNameAndHash

/* [canon] runtime med (ghidra-canon) docs/re/car.md */

void Node_SetNameAndHash(void)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte *in_EAX;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  int unaff_EDI;
  
  iVar4 = -1;
  bVar2 = *in_EAX;
  pbVar6 = in_EAX;
  while (bVar2 != 0) {
    iVar4 = iVar4 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    bVar2 = *pbVar1;
  }
  *(int *)(unaff_EDI + 8) = iVar4;
  pcVar5 = (char *)(unaff_EDI + 0x80);
  iVar4 = 0x3f;
  iVar7 = (int)in_EAX - (int)pcVar5;
  do {
    cVar3 = pcVar5[iVar7];
    iVar4 = iVar4 + -1;
    *pcVar5 = cVar3;
    if (cVar3 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar4 != 0);
  *(undefined1 *)(unaff_EDI + 0xbf) = 0;
  return;
}


// ==== 0x401e10 FUN_00401e10

void FUN_00401e10(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 8) = 0;
  List_ReleaseAllToPool();
  return;
}


// ==== 0x401e23 Thunk_JumpViaRetAddrTable

/* [canon] runtime low (ghidra-canon) docs/re/car.md */

void Thunk_JumpViaRetAddrTable(void)

{
  int unaff_retaddr;
  
                    /* WARNING: Could not recover jumptable at 0x00401e2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_retaddr + 0x1ddb))();
  return;
}


// ==== 0x401e50 QuadBuffers_Create

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void QuadBuffers_Create(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  
  param_1[0x1f] = 0;
  piVar4 = DAT_0073636c;
  iVar2 = 0x1e;
  puVar3 = param_1;
  do {
    uStack_14 = 0;
    puStack_18 = puVar3;
    (**(code **)(*piVar4 + 0x68))(piVar4,DAT_0071abc0 * 0x4b0,0x208,0,0);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uStack_14 = 0;
  param_1 = param_1 + 0x1e;
  puStack_18 = param_1;
  (**(code **)(*piVar4 + 0x6c))(piVar4,0xe10,0,0x65,1);
  puStack_18 = (undefined4 *)0x0;
  (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,0,0,&puStack_18,0);
  sVar1 = 1;
  iVar2 = 300;
  do {
    *(short *)piVar4 = sVar1 + 2;
    *(short *)((int)piVar4 + 2) = sVar1 + -1;
    *(short *)(piVar4 + 1) = sVar1;
    *(short *)((int)piVar4 + 6) = sVar1;
    *(short *)(piVar4 + 2) = sVar1 + 1;
    *(short *)((int)piVar4 + 10) = sVar1 + 2;
    piVar4 = piVar4 + 3;
    sVar1 = sVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1);
  return;
}


// ==== 0x401f30 Random_NextFloatSeeded

/* WARNING: Removing unreachable block (ram,0x00401f5b) */
/* [canon] runtime med (ghidra-canon) docs/re/car.md */

float10 __fastcall Random_NextFloatSeeded(undefined4 param_1,uint *param_2,float param_3)

{
  uint uVar1;
  
  uVar1 = *param_2 << 0x11 ^ *param_2;
  uVar1 = uVar1 ^ uVar1 >> 0xd;
  uVar1 = uVar1 ^ uVar1 << 5;
  *param_2 = uVar1;
  return (float10)(uVar1 & 0x7fffffff) * (float10)4.656613e-10 * (float10)param_3;
}


// ==== 0x401f70 Matrix4_Determinant

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

float10 Matrix4_Determinant(void)

{
  float *in_EAX;
  
  return (float10)in_EAX[0xf] * (float10)in_EAX[10] * (float10)*in_EAX * (float10)in_EAX[5] +
         (((((float10)in_EAX[9] * (float10)in_EAX[4] * (float10)in_EAX[2] +
            (float10)in_EAX[6] * (float10)in_EAX[8] * (float10)in_EAX[1]) * (float10)in_EAX[0xf] +
           (((((float10)in_EAX[4] * (float10)in_EAX[0xb] * (float10)in_EAX[1] +
              (float10)in_EAX[9] * (float10)in_EAX[7] * (float10)*in_EAX) * (float10)in_EAX[0xe] +
             ((((float10)in_EAX[0xd] * (float10)in_EAX[0xb] * (float10)in_EAX[6] * (float10)*in_EAX
               + (float10)in_EAX[8] * (float10)in_EAX[0xe] * (float10)in_EAX[3] * (float10)in_EAX[5]
                 + (((((float10)in_EAX[7] * (float10)in_EAX[2] * (float10)in_EAX[8] +
                      (float10)in_EAX[4] * (float10)in_EAX[3] * (float10)in_EAX[10]) *
                      (float10)in_EAX[0xd] +
                     (((((float10)in_EAX[2] * (float10)in_EAX[0xb] * (float10)in_EAX[5] +
                        (float10)in_EAX[7] * (float10)in_EAX[10] * (float10)in_EAX[1]) *
                        (float10)in_EAX[0xc] +
                       (((float10)in_EAX[6] * (float10)in_EAX[3] *
                         (float10)in_EAX[9] * (float10)in_EAX[0xc] -
                        (float10)in_EAX[7] * (float10)in_EAX[2] *
                        (float10)in_EAX[9] * (float10)in_EAX[0xc]) -
                       (float10)in_EAX[3] * (float10)in_EAX[0xc] * (float10)in_EAX[10] *
                       (float10)in_EAX[5])) -
                      (float10)in_EAX[6] * (float10)in_EAX[0xb] * (float10)in_EAX[0xc] *
                      (float10)in_EAX[1]) -
                     (float10)in_EAX[0xd] * (float10)in_EAX[6] * (float10)in_EAX[3] *
                     (float10)in_EAX[8])) -
                    (float10)in_EAX[0xd] * (float10)in_EAX[7] * (float10)*in_EAX *
                    (float10)in_EAX[10]) -
                   (float10)in_EAX[4] * (float10)in_EAX[2] *
                   (float10)in_EAX[0xd] * (float10)in_EAX[0xb])) -
              (float10)in_EAX[8] * (float10)in_EAX[0xe] * (float10)in_EAX[7] * (float10)in_EAX[1]) -
             (float10)in_EAX[9] * (float10)in_EAX[4] * (float10)in_EAX[3] * (float10)in_EAX[0xe])) -
            (float10)in_EAX[0xb] * (float10)in_EAX[0xe] * (float10)*in_EAX * (float10)in_EAX[5]) -
           (float10)in_EAX[2] * (float10)in_EAX[8] * (float10)in_EAX[0xf] * (float10)in_EAX[5])) -
          (float10)in_EAX[9] * (float10)in_EAX[6] * (float10)in_EAX[0xf] * (float10)*in_EAX) -
         (float10)in_EAX[0xf] * (float10)in_EAX[10] * (float10)in_EAX[4] * (float10)in_EAX[1]);
}


// ==== 0x4020b0 Matrix4_Invert

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void Matrix4_Invert(void)

{
  float *pfVar1;
  float *extraout_ECX;
  float10 extraout_ST0;
  float10 fVar2;
  
  pfVar1 = (float *)Matrix4_Determinant();
  fVar2 = (float10)_K_ONE / extraout_ST0;
  *extraout_ECX =
       (float)(((float10)pfVar1[5] * (float10)pfVar1[0xf] * (float10)pfVar1[10] +
               ((((float10)pfVar1[9] * (float10)pfVar1[0xe] * (float10)pfVar1[7] +
                 ((float10)pfVar1[0xb] * (float10)pfVar1[0xd] * (float10)pfVar1[6] -
                 (float10)pfVar1[0xd] * (float10)pfVar1[10] * (float10)pfVar1[7])) -
                (float10)pfVar1[5] * (float10)pfVar1[0xb] * (float10)pfVar1[0xe]) -
               (float10)pfVar1[9] * (float10)pfVar1[0xf] * (float10)pfVar1[6])) * fVar2);
  extraout_ECX[1] =
       (float)((((float10)pfVar1[0xb] * (float10)pfVar1[0xe] * (float10)pfVar1[1] +
                (float10)pfVar1[9] * (float10)pfVar1[0xf] * (float10)pfVar1[2] +
                (((float10)pfVar1[0xd] * (float10)pfVar1[10] * (float10)pfVar1[3] -
                 (float10)pfVar1[0xb] * (float10)pfVar1[0xd] * (float10)pfVar1[2]) -
                (float10)pfVar1[9] * (float10)pfVar1[0xe] * (float10)pfVar1[3])) -
               (float10)pfVar1[1] * (float10)pfVar1[0xf] * (float10)pfVar1[10]) * fVar2);
  extraout_ECX[2] =
       (float)(((float10)pfVar1[1] * (float10)pfVar1[0xf] * (float10)pfVar1[6] +
               ((((float10)pfVar1[5] * (float10)pfVar1[0xe] * (float10)pfVar1[3] +
                 ((float10)pfVar1[0xd] * (float10)pfVar1[7] * (float10)pfVar1[2] -
                 (float10)pfVar1[0xd] * (float10)pfVar1[6] * (float10)pfVar1[3])) -
                (float10)pfVar1[0xe] * (float10)pfVar1[1] * (float10)pfVar1[7]) -
               (float10)pfVar1[5] * (float10)pfVar1[0xf] * (float10)pfVar1[2])) * fVar2);
  extraout_ECX[3] =
       (float)((((float10)pfVar1[1] * (float10)pfVar1[10] * (float10)pfVar1[7] +
                (float10)pfVar1[5] * (float10)pfVar1[0xb] * (float10)pfVar1[2] +
                (((float10)pfVar1[9] * (float10)pfVar1[6] * (float10)pfVar1[3] -
                 (float10)pfVar1[9] * (float10)pfVar1[7] * (float10)pfVar1[2]) -
                (float10)pfVar1[5] * (float10)pfVar1[10] * (float10)pfVar1[3])) -
               (float10)pfVar1[0xb] * (float10)pfVar1[1] * (float10)pfVar1[6]) * fVar2);
  extraout_ECX[4] =
       (float)((((float10)pfVar1[8] * (float10)pfVar1[0xf] * (float10)pfVar1[6] +
                (float10)pfVar1[4] * (float10)pfVar1[0xb] * (float10)pfVar1[0xe] +
                (((float10)pfVar1[0xc] * (float10)pfVar1[10] * (float10)pfVar1[7] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[0xb] * (float10)pfVar1[6]) -
                (float10)pfVar1[8] * (float10)pfVar1[0xe] * (float10)pfVar1[7])) -
               (float10)pfVar1[4] * (float10)pfVar1[0xf] * (float10)pfVar1[10]) * fVar2);
  extraout_ECX[5] =
       (float)(((float10)*pfVar1 * (float10)pfVar1[0xf] * (float10)pfVar1[10] +
               ((((float10)pfVar1[8] * (float10)pfVar1[0xe] * (float10)pfVar1[3] +
                 ((float10)pfVar1[0xc] * (float10)pfVar1[0xb] * (float10)pfVar1[2] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[10] * (float10)pfVar1[3])) -
                (float10)pfVar1[0xb] * (float10)pfVar1[0xe] * (float10)*pfVar1) -
               (float10)pfVar1[8] * (float10)pfVar1[0xf] * (float10)pfVar1[2])) * fVar2);
  extraout_ECX[6] =
       (float)((((float10)pfVar1[0xe] * (float10)*pfVar1 * (float10)pfVar1[7] +
                (float10)pfVar1[4] * (float10)pfVar1[0xf] * (float10)pfVar1[2] +
                (((float10)pfVar1[0xc] * (float10)pfVar1[6] * (float10)pfVar1[3] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[7] * (float10)pfVar1[2]) -
                (float10)pfVar1[4] * (float10)pfVar1[0xe] * (float10)pfVar1[3])) -
               (float10)*pfVar1 * (float10)pfVar1[0xf] * (float10)pfVar1[6]) * fVar2);
  extraout_ECX[7] =
       (float)(((float10)pfVar1[0xb] * (float10)*pfVar1 * (float10)pfVar1[6] +
               ((((float10)pfVar1[4] * (float10)pfVar1[10] * (float10)pfVar1[3] +
                 ((float10)pfVar1[8] * (float10)pfVar1[7] * (float10)pfVar1[2] -
                 (float10)pfVar1[8] * (float10)pfVar1[6] * (float10)pfVar1[3])) -
                (float10)*pfVar1 * (float10)pfVar1[10] * (float10)pfVar1[7]) -
               (float10)pfVar1[4] * (float10)pfVar1[0xb] * (float10)pfVar1[2])) * fVar2);
  extraout_ECX[8] =
       (float)(((float10)pfVar1[4] * (float10)pfVar1[9] * (float10)pfVar1[0xf] +
               ((((float10)pfVar1[8] * (float10)pfVar1[0xd] * (float10)pfVar1[7] +
                 ((float10)pfVar1[5] * (float10)pfVar1[0xc] * (float10)pfVar1[0xb] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[9] * (float10)pfVar1[7])) -
                (float10)pfVar1[4] * (float10)pfVar1[0xb] * (float10)pfVar1[0xd]) -
               (float10)pfVar1[5] * (float10)pfVar1[8] * (float10)pfVar1[0xf])) * fVar2);
  extraout_ECX[9] =
       (float)((((float10)pfVar1[8] * (float10)pfVar1[1] * (float10)pfVar1[0xf] +
                (float10)pfVar1[0xb] * (float10)pfVar1[0xd] * (float10)*pfVar1 +
                (((float10)pfVar1[0xc] * (float10)pfVar1[9] * (float10)pfVar1[3] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[0xb] * (float10)pfVar1[1]) -
                (float10)pfVar1[8] * (float10)pfVar1[0xd] * (float10)pfVar1[3])) -
               (float10)pfVar1[9] * (float10)*pfVar1 * (float10)pfVar1[0xf]) * fVar2);
  extraout_ECX[10] =
       (float)(((float10)pfVar1[5] * (float10)*pfVar1 * (float10)pfVar1[0xf] +
               ((((float10)pfVar1[4] * (float10)pfVar1[0xd] * (float10)pfVar1[3] +
                 ((float10)pfVar1[0xc] * (float10)pfVar1[1] * (float10)pfVar1[7] -
                 (float10)pfVar1[5] * (float10)pfVar1[0xc] * (float10)pfVar1[3])) -
                (float10)pfVar1[0xd] * (float10)*pfVar1 * (float10)pfVar1[7]) -
               (float10)pfVar1[4] * (float10)pfVar1[1] * (float10)pfVar1[0xf])) * fVar2);
  extraout_ECX[0xb] =
       (float)((((float10)pfVar1[4] * (float10)pfVar1[0xb] * (float10)pfVar1[1] +
                (float10)pfVar1[9] * (float10)*pfVar1 * (float10)pfVar1[7] +
                (((float10)pfVar1[5] * (float10)pfVar1[8] * (float10)pfVar1[3] -
                 (float10)pfVar1[8] * (float10)pfVar1[1] * (float10)pfVar1[7]) -
                (float10)pfVar1[4] * (float10)pfVar1[9] * (float10)pfVar1[3])) -
               (float10)pfVar1[5] * (float10)pfVar1[0xb] * (float10)*pfVar1) * fVar2);
  extraout_ECX[0xc] =
       (float)((((float10)pfVar1[4] * (float10)pfVar1[0xd] * (float10)pfVar1[10] +
                (float10)pfVar1[5] * (float10)pfVar1[8] * (float10)pfVar1[0xe] +
                (((float10)pfVar1[0xc] * (float10)pfVar1[9] * (float10)pfVar1[6] -
                 (float10)pfVar1[5] * (float10)pfVar1[0xc] * (float10)pfVar1[10]) -
                (float10)pfVar1[8] * (float10)pfVar1[0xd] * (float10)pfVar1[6])) -
               (float10)pfVar1[4] * (float10)pfVar1[9] * (float10)pfVar1[0xe]) * fVar2);
  extraout_ECX[0xd] =
       (float)(((float10)pfVar1[9] * (float10)pfVar1[0xe] * (float10)*pfVar1 +
               ((((float10)pfVar1[8] * (float10)pfVar1[0xd] * (float10)pfVar1[2] +
                 ((float10)pfVar1[0xc] * (float10)pfVar1[1] * (float10)pfVar1[10] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[9] * (float10)pfVar1[2])) -
                (float10)pfVar1[0xd] * (float10)*pfVar1 * (float10)pfVar1[10]) -
               (float10)pfVar1[8] * (float10)pfVar1[0xe] * (float10)pfVar1[1])) * fVar2);
  extraout_ECX[0xe] =
       (float)((((float10)pfVar1[4] * (float10)pfVar1[0xe] * (float10)pfVar1[1] +
                (float10)pfVar1[0xd] * (float10)*pfVar1 * (float10)pfVar1[6] +
                (((float10)pfVar1[5] * (float10)pfVar1[0xc] * (float10)pfVar1[2] -
                 (float10)pfVar1[0xc] * (float10)pfVar1[1] * (float10)pfVar1[6]) -
                (float10)pfVar1[4] * (float10)pfVar1[0xd] * (float10)pfVar1[2])) -
               (float10)pfVar1[5] * (float10)pfVar1[0xe] * (float10)*pfVar1) * fVar2);
  extraout_ECX[0xf] =
       (float)(((float10)pfVar1[5] * (float10)*pfVar1 * (float10)pfVar1[10] +
               ((((float10)pfVar1[4] * (float10)pfVar1[9] * (float10)pfVar1[2] +
                 ((float10)pfVar1[8] * (float10)pfVar1[1] * (float10)pfVar1[6] -
                 (float10)pfVar1[5] * (float10)pfVar1[8] * (float10)pfVar1[2])) -
                (float10)pfVar1[9] * (float10)*pfVar1 * (float10)pfVar1[6]) -
               (float10)pfVar1[4] * (float10)pfVar1[1] * (float10)pfVar1[10])) * fVar2);
  return;
}


// ==== 0x402500 Spline_BuildCubicBasis

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void Spline_BuildCubicBasis
               (undefined4 param_1,undefined4 param_2,float param_3,float param_4,float param_5,
               float param_6)

{
  undefined1 *puStack_15c;
  undefined4 *puStack_158;
  undefined1 *puStack_154;
  float local_150;
  float local_14c;
  float local_148;
  undefined4 local_144;
  float local_140;
  float local_13c;
  float local_138;
  undefined4 local_134;
  float local_130;
  float local_12c;
  float local_128;
  undefined4 local_124;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
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
  undefined1 local_90 [40];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [88];
  
  local_14c = param_3 * param_3;
  local_148 = param_3;
  local_150 = param_3 * local_14c;
  local_138 = param_4;
  local_118 = param_6;
  local_110 = 0x40000000;
  local_10c = 0xc0000000;
  local_13c = param_4 * param_4;
  local_108 = 0x3f800000;
  local_104 = 0x3f800000;
  local_100 = 0xc0400000;
  local_140 = param_4 * local_13c;
  local_fc = 0x40400000;
  local_f8 = 0xc0000000;
  local_f4 = 0xbf800000;
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 0x3f800000;
  local_e4 = 0;
  local_12c = param_5 * param_5;
  local_e0 = 0x3f800000;
  local_dc = 0;
  local_d8 = 0;
  local_130 = param_5 * local_12c;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0x3f800000;
  local_c0 = 0x3f800000;
  local_bc = 0x3f800000;
  local_11c = param_6 * param_6;
  local_b8 = 0x3f800000;
  local_b4 = 0x3f800000;
  local_b0 = 0;
  local_120 = param_6 * local_11c;
  local_ac = 0;
  local_a8 = 0x3f800000;
  local_a4 = 0;
  local_a0 = 0x40400000;
  local_9c = 0x40000000;
  local_98 = 0x3f800000;
  local_94 = 0;
  local_144 = 0x3f800000;
  local_134 = 0x3f800000;
  local_128 = param_5;
  local_124 = 0x3f800000;
  local_114 = 0x3f800000;
  puStack_154 = (undefined1 *)0x4026d4;
  Matrix4_Invert();
  puStack_154 = local_90;
  puStack_158 = &local_d0;
  puStack_15c = (undefined1 *)&local_150;
  D3DXMatrixMultiply();
  D3DXMatrixMultiply(auStack_5c,&local_11c,&puStack_15c);
  D3DXMatrixMultiply(param_1,auStack_68,param_2);
  return;
}


// ==== 0x402720 FUN_00402720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402720(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  DAT_0073652c = (undefined4 *)FUN_00566dc0(0x20,"AcidParticleSlotPool",0);
  if ((DAT_0073652c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0073652c;
    puVar2 = DAT_0073652c;
    DAT_0073652c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar2;
    *DAT_0073652c = &DAT_0073d818;
  }
  DAT_00736530 = (undefined4 *)FUN_00566dc0(0x1c,"AcidActiveGroupSlotPool",0);
  if ((DAT_00736530 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00736530;
    puVar2 = DAT_00736530;
    DAT_00736530[1] = DAT_0073d81c;
    DAT_0073d81c = puVar2;
    *DAT_00736530 = &DAT_0073d818;
  }
  _DAT_00736534 = (undefined4 *)FUN_00566dc0(0xc0,"AcidEmitterSlotPool",0);
  if ((_DAT_00736534 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = _DAT_00736534;
    puVar2 = _DAT_00736534;
    _DAT_00736534[1] = DAT_0073d81c;
    DAT_0073d81c = puVar2;
    *_DAT_00736534 = &DAT_0073d818;
  }
  puVar2 = DAT_0073652c;
  uVar1 = DAT_0073652c[5];
  DAT_0073652c[5] = uVar1 & 0xfffffffe;
  puVar2[5] = uVar1 & 0xfffffffc;
  puVar2 = DAT_00736530;
  uVar1 = DAT_00736530[5];
  DAT_00736530[5] = uVar1 & 0xfffffffe;
  puVar2[5] = uVar1 & 0xfffffffc;
  return;
}


// ==== 0x402820 Particle_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 Particle_Load(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *param_1;
  if ((iVar6 == -0x7ffcb000) || (iVar6 == -0x7ffcaff0)) {
    return 1;
  }
  if (iVar6 == 0x35021) {
    uVar2 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar2 + 8) == 4) {
      puVar5 = (undefined4 *)(uVar2 + 0x10);
      puVar1 = DAT_0078e978;
      for (iVar6 = *(int *)(uVar2 + 0xc); DAT_0078e978 = puVar1, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar1 = puVar5;
        DAT_0078e978 = puVar5;
        puVar5[1] = puVar1;
        *puVar5 = &DAT_0078e974;
        uVar3 = Texture_FindByHash(puVar5[3],0,0);
        puVar5[5] = uVar3;
        puVar5 = puVar5 + 0x88;
        puVar1 = DAT_0078e978;
      }
    }
    return 1;
  }
  if (iVar6 == 0x35020) {
    uVar2 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar2 + 8) == 5) {
      iVar6 = uVar2 + 0x10;
      for (iVar4 = *(int *)(uVar2 + 0xc); iVar4 != 0; iVar4 = iVar4 + -1) {
        ParticleEmitter_Bind(iVar6);
        ParticleEmitter_Queue();
        iVar6 = iVar6 + 0xc0;
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x4028f0 Particle_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 Particle_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if ((iVar5 == -0x7ffcb000) || (iVar5 == -0x7ffcaff0)) {
    return 1;
  }
  if (iVar5 == 0x35021) {
    uVar4 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar4 + 8) == 4) {
      piVar3 = (int *)(uVar4 + 0x10);
      for (iVar5 = *(int *)(uVar4 + 0xc); iVar5 != 0; iVar5 = iVar5 + -1) {
        iVar1 = *piVar3;
        piVar2 = (int *)piVar3[1];
        piVar3 = piVar3 + 0x88;
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
      }
    }
    return 1;
  }
  if (iVar5 == 0x35020) {
    uVar4 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar4 + 8) == 5) {
      piVar3 = (int *)(uVar4 + 0x10);
      for (iVar5 = *(int *)(uVar4 + 0xc); iVar5 != 0; iVar5 = iVar5 + -1) {
        iVar1 = *piVar3;
        piVar2 = (int *)piVar3[1];
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
        DAT_0078ea30 = DAT_0078ea30 + -1;
        piVar3 = piVar3 + 0x30;
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x4029a0 Particle_ResolveTextures

/* [canon] render med (ghidra-canon) docs/re/car.md */

void Particle_ResolveTextures(char param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EBX;
  
  puVar2 = DAT_0078e974;
  puVar3 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar3) {
      return;
    }
    uVar1 = puVar2[3];
    iVar4 = puVar2[5];
    if (param_1 == '\0') {
      if (((iVar4 == 0) || (*(int *)(iVar4 + 0x68) != unaff_EBX)) ||
         ((*(int *)(unaff_EBX + 0x70) != 0 &&
          (((iVar4 = *(int *)(*(int *)(unaff_EBX + 0x70) + 0x74), iVar4 != 0 &&
            (iVar4 = BinarySearch_Hash(uVar1,iVar4,0), iVar4 != 0)) && (*(int *)(iVar4 + 4) != 0))))
         )) goto LAB_00402a4a;
      iVar4 = Texture_FindByHash(uVar1,0,0);
    }
    else if (((iVar4 == 0) && (*(int *)(unaff_EBX + 0x70) != 0)) &&
            ((iVar4 = *(int *)(*(int *)(unaff_EBX + 0x70) + 0x74), iVar4 != 0 &&
             ((iVar4 = BinarySearch_Hash(uVar1,iVar4,0), iVar4 != 0 &&
              (iVar4 = *(int *)(iVar4 + 4), iVar4 != 0)))))) {
      *(undefined1 *)(iVar4 + 0x53) = 1;
    }
    else {
LAB_00402a4a:
      iVar4 = puVar2[5];
    }
    puVar2[5] = iVar4;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// ==== 0x402a70 FUN_00402a70

void * FUN_00402a70(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  pvVar1 = _malloc(0xc0);
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    puVar4 = (undefined4 *)((int)pvVar1 + 8);
    for (iVar3 = 0x2e; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    DAT_00736538 = DAT_00736538 + 1;
    Node_SetNameAndHash();
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(int *)((int)pvVar1 + 0x1c) = *(int *)(param_1 + 0x1c);
    }
    bMatrixCopy_b();
    pvVar2 = pvVar1;
  }
  return pvVar2;
}


// ==== 0x402ad0 FUN_00402ad0

void FUN_00402ad0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  
  puVar4 = (undefined4 *)0x0;
  do {
    if (param_1 == 0) {
      return;
    }
    puVar5 = DAT_0078e9e8;
    if (puVar4 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)*puVar4;
    }
    puVar2 = (undefined4 *)NullUpdate_ret();
    puVar4 = puVar5;
    while( true ) {
      if (puVar4 == puVar2) {
        return;
      }
      if ((puVar4[7] != 0) && (*(int *)(puVar4[7] + 0x10) == param_1)) break;
      puVar4 = (undefined4 *)*puVar4;
    }
    piVar3 = (int *)FUN_00402a70(puVar4);
    if (piVar3 != (int *)0x0) {
      piVar1 = *(int **)(unaff_EDI + 4);
      *piVar1 = (int)piVar3;
      *(int **)(unaff_EDI + 4) = piVar3;
      piVar3[1] = (int)piVar1;
      *piVar3 = unaff_EDI;
    }
  } while( true );
}


// ==== 0x402b40 ParticleEmitter_Bind

/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 ParticleEmitter_Bind(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = DAT_0078e974;
  if (unaff_EDI != 0) {
    puVar2 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[2] == unaff_EDI) {
        *(undefined4 **)(param_1 + 0x1c) = puVar1;
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x402b90 ParticleLists_Init

/* [canon] render low (ghidra-canon) docs/re/car.md */

void ParticleLists_Init(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = in_EAX + 8;
  *(int *)in_EAX = in_EAX;
  *(int *)(in_EAX + 4) = in_EAX;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0xc) = iVar1;
  *(undefined4 *)(in_EAX + 0x40) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined1 *)(in_EAX + 0x48) = 0;
  *(undefined1 *)(in_EAX + 0x49) = 0;
  *(undefined1 *)(in_EAX + 0x4a) = 0;
  *(undefined1 *)(in_EAX + 0x4b) = 0;
  *(undefined1 *)(in_EAX + 0x4c) = 0;
  *(undefined1 *)(in_EAX + 0x4d) = 0;
  *(undefined4 *)(in_EAX + 0x50) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0;
  return;
}


// ==== 0x402bd0 ParticleEmitter_Queue

/* WARNING: Removing unreachable block (ram,0x00402c0f) */
/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

void ParticleEmitter_Queue(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *unaff_ESI;
  int unaff_EDI;
  float10 fVar7;
  float10 fVar8;
  
  if (unaff_ESI[9] == 0) {
    uVar5 = DAT_00704304 << 0x11 ^ DAT_00704304;
    uVar5 = uVar5 ^ uVar5 >> 0xd;
    DAT_00704304 = uVar5 ^ uVar5 << 5;
    iVar6 = _ftol_nocw();
    unaff_ESI[9] = iVar6;
  }
  iVar6 = unaff_ESI[7];
  iVar3 = unaff_ESI[4];
  if ((iVar6 != 0) && (iVar3 != 2)) {
    if ((iVar3 == 0) || (iVar3 == 1)) {
      fVar1 = *(float *)(iVar6 + 0x20);
      fVar2 = *(float *)(iVar6 + 0x24);
      if (iVar3 == 0) {
        fVar1 = *(float *)(iVar6 + 0x28);
        fVar2 = *(float *)(iVar6 + 0x2c);
      }
      fVar8 = (float10)fVar1;
      if (fVar8 != (float10)0.0) {
        fVar7 = (float10)Random_NextFloatSeeded((float)((float10)fVar2 * fVar8));
        fVar8 = ((float10)fVar1 - (float10)(float)((float10)fVar2 * fVar8)) + fVar7;
      }
      unaff_ESI[5] = (int)(float)fVar8;
      unaff_ESI[6] = 0;
      iVar6 = *(int *)(unaff_EDI + 8);
      *(undefined4 *)(unaff_EDI + 8) = unaff_ESI;
      *(int **)(iVar6 + 4) = unaff_ESI;
      unaff_ESI[1] = unaff_EDI + 8;
      *unaff_ESI = iVar6;
      *(int *)(unaff_EDI + 0x50) = *(int *)(unaff_EDI + 0x50) + 1;
      return;
    }
    if (iVar3 == 3) goto LAB_00402cce;
  }
  unaff_ESI[4] = 2;
LAB_00402cce:
  puVar4 = *(undefined4 **)(unaff_EDI + 0xc);
  *puVar4 = unaff_ESI;
  *(int **)(unaff_EDI + 0xc) = unaff_ESI;
  *unaff_ESI = unaff_EDI + 8;
  unaff_ESI[1] = (int)puVar4;
  *(int *)(unaff_EDI + 0x50) = *(int *)(unaff_EDI + 0x50) + 1;
  return;
}


// ==== 0x402cf0 FUN_00402cf0

void FUN_00402cf0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = DAT_00736530;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00401e10();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x402d30 FUN_00402d30

/* WARNING: Removing unreachable block (ram,0x00403300) */
/* WARNING: Removing unreachable block (ram,0x0040390a) */
/* WARNING: Removing unreachable block (ram,0x004035a2) */
/* WARNING: Removing unreachable block (ram,0x0040335e) */
/* WARNING: Removing unreachable block (ram,0x00402dec) */
/* WARNING: Removing unreachable block (ram,0x004032a8) */
/* WARNING: Removing unreachable block (ram,0x00403471) */
/* WARNING: Removing unreachable block (ram,0x0040368b) */
/* WARNING: Removing unreachable block (ram,0x004035e3) */
/* WARNING: Removing unreachable block (ram,0x00403138) */
/* WARNING: Removing unreachable block (ram,0x004034be) */
/* WARNING: Removing unreachable block (ram,0x004031ad) */
/* WARNING: Removing unreachable block (ram,0x00403424) */
/* WARNING: Removing unreachable block (ram,0x00403560) */
/* WARNING: Removing unreachable block (ram,0x00403628) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402d30(int param_1,int param_2,float param_3,int param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined4 *puVar6;
  int *piVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  ushort uVar13;
  undefined2 uVar14;
  uint uVar15;
  undefined4 uVar16;
  float *pfVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  undefined4 *puVar21;
  float10 fVar22;
  int *local_238;
  float local_234;
  float local_220;
  float fStack_210;
  float fStack_1fc;
  float fStack_1ec;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  undefined4 local_1b8;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_19c;
  float local_198;
  float local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  undefined4 local_184;
  int local_180;
  float local_17c;
  float fStack_178;
  int local_174;
  float fStack_170;
  int local_16c;
  float local_168;
  float fStack_164;
  undefined1 auStack_15c [60];
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined1 auStack_110 [40];
  undefined1 auStack_e8 [44];
  undefined1 auStack_bc [44];
  undefined1 local_90 [64];
  undefined1 auStack_50 [76];
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 != 0) {
    bVar10 = false;
    iVar20 = 0;
    pfVar17 = (float *)(param_1 + 0x18);
    do {
      if (2 < iVar20) break;
      fVar2 = *(float *)(param_2 + 0x60) - pfVar17[-2];
      fVar5 = *(float *)(param_2 + 100) - pfVar17[-1];
      fVar4 = *(float *)(param_2 + 0x68) - *pfVar17;
      if (SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4) < *(float *)(iVar1 + 0x80)) {
        bVar10 = true;
      }
      iVar20 = iVar20 + 1;
      pfVar17 = pfVar17 + 4;
    } while (!bVar10);
    local_174 = iVar1;
    if (*(int *)(param_2 + 0x24) == 0) {
      uVar15 = DAT_00704304 << 0x11 ^ DAT_00704304;
      uVar15 = uVar15 ^ uVar15 >> 0xd;
      DAT_00704304 = uVar15 ^ uVar15 << 5;
      local_1c4 = (float)(DAT_00704304 & 0x7fffffff);
      uVar16 = _ftol_nocw();
      *(undefined4 *)(param_2 + 0x24) = uVar16;
    }
    iVar20 = DAT_00736530;
    if ((bVar10) && ((*(int *)(param_2 + 0x10) == 1 || (param_3 < 0.0)))) {
      fVar2 = *(float *)(param_2 + 0x14);
      local_234 = param_3;
      if (param_3 < 0.0) {
        local_234 = -param_3;
      }
      else if ((fVar2 != 0.0) && (fVar2 < param_3)) {
        local_234 = fVar2;
      }
      fVar2 = *(float *)(param_2 + 0x18);
      if (fVar2 < local_234) {
        local_238 = *(int **)(param_2 + 0x20);
        if ((((local_238 == (int *)0x0) || (local_238[3] != param_2)) || (local_238[4] != param_4))
           && (*(int *)(DAT_00736530 + 0x18) != *(int *)(DAT_00736530 + 0x2c))) {
          local_238 = *(int **)(DAT_00736530 + 0x10);
          iVar18 = *(int *)(DAT_00736530 + 0x18) + 1;
          if (local_238 == (int *)0x0) {
            local_238 = (int *)0x0;
          }
          else {
            iVar3 = *local_238;
            if (*(int *)(DAT_00736530 + 0x1c) < iVar18) {
              *(int *)(DAT_00736530 + 0x1c) = iVar18;
            }
            *(int *)(iVar20 + 0x18) = iVar18;
            *(int *)(iVar20 + 0x10) = iVar3;
            local_238[4] = param_4;
            local_238[3] = param_2;
            piVar7 = local_238 + 5;
            *piVar7 = (int)piVar7;
            local_238[6] = (int)piVar7;
            local_238[2] = *(int *)(param_2 + 0x1c);
            *(int **)(param_2 + 0x20) = local_238;
          }
          puVar21 = *(undefined4 **)(param_1 + 4);
          *puVar21 = local_238;
          *(int **)(param_1 + 4) = local_238;
          local_238[1] = (int)puVar21;
          *local_238 = param_1;
        }
        if (local_238 != (int *)0x0) {
          local_190 = *(undefined4 *)(iVar1 + 0x68);
          local_184 = *(undefined4 *)(iVar1 + 100);
          local_194 = *(float *)(iVar1 + 0x60);
          local_1cc = *(float *)(iVar1 + 0x78);
          fVar4 = *(float *)(iVar1 + 0x74);
          fVar5 = *(float *)(iVar1 + 0x70);
          bMatrixCopy_b();
          bMatrixCopy_b();
          local_120 = 0;
          local_11c = 0;
          local_118 = 0;
          local_114 = 0x3f800000;
          local_168 = *(float *)(iVar1 + 0x48) * 182.04445 * -0.5;
          local_16c = (int)*(char *)(iVar1 + 0x1d);
          local_180 = (int)*(char *)(iVar1 + 0x18);
          uVar15 = *(uint *)(param_2 + 0x24);
          local_1c8 = *(float *)(iVar1 + 0x44) * *(float *)(iVar1 + 0x40);
          fVar8 = *(float *)(iVar1 + 0x54) * *(float *)(iVar1 + 0x50);
          local_1c4 = *(float *)(iVar1 + 0x30) - *(float *)(iVar1 + 0x34) * *(float *)(iVar1 + 0x30)
          ;
          local_188 = *(float *)(iVar1 + 0x40) - local_1c8;
          fVar9 = *(float *)(iVar1 + 0x50) - fVar8;
          if (fVar2 <= local_234) {
            local_198 = fVar5 * 0.5;
            local_18c = fVar4 * 0.5;
            local_17c = local_1cc * 0.5;
            do {
              local_234 = local_234 - fVar2;
              if (local_180 == 0) {
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                _ftol_nocw();
                FUN_0040b990(auStack_110,&DAT_0078bcc0);
                _ftol_nocw();
                FUN_0040ba40(auStack_110,auStack_110);
                _ftol_nocw();
                FUN_0040b930();
                D3DXMatrixMultiply(auStack_110,auStack_110,auStack_50);
                thunk_FUN_005ac436(&local_16c,auStack_bc,&local_11c);
                local_220 = fStack_170;
              }
              else {
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                _ftol_nocw();
                fVar22 = (float10)FUN_00564b10();
                local_1c0 = (float)fVar22;
                fVar22 = (float10)FUN_00564b10();
                local_1bc = (float)fVar22;
                local_1b8 = 0;
                _ftol_nocw();
                FUN_0040ba40(local_90,&DAT_0078bcc0);
                thunk_FUN_005ac436(&local_1c0,&local_1c0,local_90);
                thunk_FUN_005ac436(&local_1cc,&local_1cc,auStack_15c);
                local_220 = fVar8;
              }
              uVar15 = uVar15 << 0x11 ^ uVar15;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              uVar19 = uVar15 << 0x11 ^ uVar15;
              uVar19 = uVar19 ^ uVar19 >> 0xd;
              uVar19 = uVar19 ^ uVar19 << 5;
              local_1c8 = ((float)(uVar15 & 0x7fffffff) * 4.656613e-10 * fStack_1fc - fStack_1b0) +
                          fStack_1ac;
              uVar15 = uVar19 << 0x11 ^ uVar19;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              local_1c4 = ((float)(uVar19 & 0x7fffffff) * 4.656613e-10 * fStack_1ec - fStack_1a4) +
                          fStack_19c;
              local_1bc = 1.0;
              local_1c0 = ((float)(uVar15 & 0x7fffffff) * 4.656613e-10 * fVar5 - local_194) +
                          fStack_1a8;
              thunk_FUN_005ac436(&local_1c8,&local_1c8,auStack_e8);
              uVar15 = uVar15 << 0x11 ^ uVar15;
              fStack_178 = fStack_1b0;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              fStack_164 = fStack_1ac;
              uVar15 = uVar15 ^ uVar15 << 5;
              fStack_170 = fStack_1a8;
              uVar11 = _ftol_nocw();
              uVar15 = uVar15 << 0x11 ^ uVar15;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              uVar15 = uVar15 << 0x11 ^ uVar15;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              uVar15 = uVar15 << 0x11 ^ uVar15;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              uVar19 = uVar15 & 0x7fffffff;
              if (fVar9 != 0.0) {
                uVar15 = uVar15 << 0x11 ^ uVar15;
                uVar15 = uVar15 ^ uVar15 >> 0xd;
                uVar15 = uVar15 ^ uVar15 << 5;
                fVar2 = (float)(uVar15 & 0x7fffffff) * 4.656613e-10 * fVar8 + fVar9;
                if (fVar2 <= 0.0) {
                  fVar2 = 0.0;
                }
                else if (_K_ONE < fVar2) {
                  fVar2 = _K_ONE;
                }
                if (*(char *)(local_174 + 0x1e) == '\0') {
                  fStack_210 = ((float)uVar19 * 4.656613e-10 * local_1c8 + local_188) * fStack_210 +
                               fVar2 * *(float *)(param_2 + 0x74);
                  bNormalize3();
                  fStack_1fc = fStack_210;
                }
              }
              uVar13 = _ftol_nocw();
              iVar1 = DAT_0073652c;
              uVar13 = uVar13 & 0xfffe;
              if (local_16c != 0) {
                uVar13 = uVar13 | (ushort)uVar15 & 1;
              }
              if (*(int *)(param_2 + 0x28) == 0) {
                if (DAT_00700eb0 < 2) {
                  DAT_0078eb98 = DAT_0078eb98 ^ 1;
                }
                else {
                  DAT_0078eb98 = 0;
                }
                if ((*(int *)(DAT_0073652c + 0x18) != *(int *)(DAT_0073652c + 0x2c)) &&
                   (DAT_0078eb98 == 0)) {
                  puVar21 = *(undefined4 **)(DAT_0073652c + 0x10);
                  iVar20 = *(int *)(DAT_0073652c + 0x18) + 1;
                  if (puVar21 == (undefined4 *)0x0) {
                    puVar21 = (undefined4 *)0x0;
                  }
                  else {
                    uVar16 = *puVar21;
                    if (*(int *)(DAT_0073652c + 0x1c) < iVar20) {
                      *(int *)(DAT_0073652c + 0x1c) = iVar20;
                    }
                    *(int *)(iVar1 + 0x18) = iVar20;
                    *(undefined4 *)(iVar1 + 0x10) = uVar16;
                  }
                  uVar14 = _ftol_nocw();
                  *(undefined2 *)(puVar21 + 2) = uVar14;
                  *(ushort *)((int)puVar21 + 10) = uVar13;
                  uVar14 = _ftol_nocw();
                  *(undefined2 *)(puVar21 + 3) = uVar14;
                  uVar12 = _ftol_nocw();
                  *(undefined1 *)((int)puVar21 + 0xe) = uVar12;
                  puVar21[4] = fStack_178;
                  puVar21[5] = fStack_164;
                  puVar21[6] = fStack_170;
                  uVar12 = _ftol_nocw();
                  *(undefined1 *)(puVar21 + 7) = uVar12;
                  uVar12 = _ftol_nocw();
                  *(undefined1 *)((int)puVar21 + 0x1d) = uVar12;
                  uVar12 = _ftol_nocw();
                  *(undefined1 *)((int)puVar21 + 0x1e) = uVar12;
                  *(undefined1 *)((int)puVar21 + 0x1f) = uVar11;
                  puVar6 = (undefined4 *)local_238[6];
                  *puVar6 = puVar21;
                  local_238[6] = (int)puVar21;
                  puVar21[1] = puVar6;
                  *puVar21 = local_238 + 5;
                }
              }
              uVar15 = uVar15 << 0x11 ^ uVar15;
              uVar15 = uVar15 ^ uVar15 >> 0xd;
              uVar15 = uVar15 ^ uVar15 << 5;
              fVar2 = (float)(uVar15 & 0x7fffffff) * 4.656613e-10 * local_220 + local_1c4;
              if (fVar2 <= 0.0) {
                fVar2 = 0.1;
              }
              else {
                fVar2 = 1.0 / fVar2;
                if (fVar2 <= 240.0) {
                  if (fVar2 < 0.0) {
                    fVar2 = 0.0;
                  }
                }
                else {
                  fVar2 = 240.0;
                }
              }
              iVar20 = DAT_00736530;
            } while (fVar2 <= local_234);
          }
          *(uint *)(param_2 + 0x24) = uVar15;
          if ((int *)local_238[5] == local_238 + 5) {
            iVar1 = *local_238;
            piVar7 = (int *)local_238[1];
            *piVar7 = iVar1;
            *(int **)(iVar1 + 4) = piVar7;
            local_238[3] = 0;
            local_238[2] = 0;
            List_ReleaseAllToPool();
            iVar1 = *(int *)(iVar20 + 0x18);
            *local_238 = *(int *)(iVar20 + 0x10);
            *(int *)(iVar20 + 0x18) = iVar1 + -1;
            *(int **)(iVar20 + 0x10) = local_238;
          }
        }
      }
      if (0.0 <= param_3) {
        *(float *)(param_2 + 0x18) = fVar2 - local_234;
        return;
      }
      *(undefined4 *)(param_2 + 0x18) = 0;
    }
  }
  return;
}


// ==== 0x403a00 FUN_00403a00

void FUN_00403a00(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  
  if (DAT_00740500 != 0) {
    uVar1 = *(undefined4 *)(DAT_00740500 + 0x44);
    uVar2 = *(undefined4 *)(DAT_00740500 + 0x48);
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(DAT_00740500 + 0x40);
    *(undefined4 *)(in_EAX + 0x14) = uVar1;
    *(undefined4 *)(in_EAX + 0x18) = uVar2;
  }
  if (DAT_00740560 != 0) {
    uVar1 = *(undefined4 *)(DAT_00740560 + 0x44);
    uVar2 = *(undefined4 *)(DAT_00740560 + 0x48);
    *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(DAT_00740560 + 0x40);
    *(undefined4 *)(in_EAX + 0x24) = uVar1;
    *(undefined4 *)(in_EAX + 0x28) = uVar2;
  }
  if (DAT_007404a0 != 0) {
    uVar1 = *(undefined4 *)(DAT_007404a0 + 0x44);
    uVar2 = *(undefined4 *)(DAT_007404a0 + 0x48);
    *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(DAT_007404a0 + 0x40);
    *(undefined4 *)(in_EAX + 0x34) = uVar1;
    *(undefined4 *)(in_EAX + 0x38) = uVar2;
  }
  return;
}


// ==== 0x403a60 Particles_UpdateSystem

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render low (hopper) docs/re/render.md */

void Particles_UpdateSystem(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  bool bVar8;
  undefined4 uVar9;
  byte bVar10;
  undefined1 uVar11;
  undefined2 uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_9c;
  float local_90;
  int local_88;
  LARGE_INTEGER local_80;
  LARGE_INTEGER local_78;
  int local_70;
  int local_6c;
  int *local_68;
  int local_64;
  int local_60;
  float local_5c;
  int local_58;
  int local_54;
  int local_50;
  float local_4c;
  undefined4 local_40;
  float local_3c;
  undefined4 local_30;
  float local_2c;
  undefined4 local_20;
  float local_1c;
  
  QueryPerformanceCounter(&local_80);
  local_80.s.LowPart = __allshr();
  local_70 = _ftol_nocw();
  FUN_00403a00();
  bVar8 = false;
  piVar16 = (int *)param_1[2];
  do {
    if (piVar16 == param_1 + 2) break;
    iVar14 = piVar16[4];
    piVar18 = (int *)*piVar16;
    if (iVar14 == 1) {
      FUN_00402d30(param_1,piVar16,param_2,0);
    }
    else if (iVar14 != 0) {
      bVar8 = true;
    }
    if (((float)piVar16[5] != 0.0) && ((iVar14 == 1 || (iVar14 == 0)))) {
      fVar3 = (float)piVar16[5] - param_2;
      if (fVar3 < 0.0 == (fVar3 == 0.0)) {
        piVar16[5] = (int)fVar3;
      }
      else {
        iVar5 = piVar16[7];
        if (iVar14 != 0) {
          fVar1 = *(float *)(iVar5 + 0x28);
          fVar2 = *(float *)(iVar5 + 0x2c);
        }
        else {
          fVar1 = *(float *)(iVar5 + 0x20);
          fVar2 = *(float *)(iVar5 + 0x24);
        }
        uVar15 = (uint)(iVar14 == 0);
        if (fVar1 == 0.0) {
          piVar16[4] = uVar15;
          piVar16[5] = (int)fVar1;
          piVar16[6] = 0;
        }
        else {
          fVar19 = (float10)Random_NextFloatSeeded(fVar2 * fVar1);
          piVar16[4] = uVar15;
          piVar16[6] = 0;
          piVar16[5] = (int)(float)(((float10)fVar1 - (float10)(fVar2 * fVar1)) + fVar19 +
                                   (float10)fVar3);
        }
      }
    }
    piVar16 = piVar18;
  } while (!bVar8);
  puVar6 = DAT_0078e974;
  if (DAT_0077a920 == 3) {
    puVar13 = (undefined4 *)NullUpdate_ret();
    for (; puVar6 != puVar13; puVar6 = (undefined4 *)*puVar6) {
      fVar3 = (float)puVar6[0x24];
      local_40 = puVar6[0x39];
      local_50 = puVar6[0x38];
      local_30 = puVar6[0x3a];
      fVar1 = (float)puVar6[0x25];
      local_20 = puVar6[0x3b];
      fVar2 = (float)puVar6[0x26];
      fVar4 = (float)puVar6[0x27];
      local_4c = (float)puVar6[0x3c] * 182.04445;
      local_3c = (float)puVar6[0x3d] * 182.04445;
      local_2c = (float)puVar6[0x3e] * 182.04445;
      local_1c = (float)puVar6[0x3f] * 182.04445;
      Spline_BuildCubicBasis
                (puVar6 + 0x40,puVar6 + 0x28,fVar3 * 0.33333334,fVar1 * 0.33333334,
                 fVar2 * 0.33333334,fVar4 * 0.33333334);
      Spline_BuildCubicBasis
                (puVar6 + 0x50,&local_50,fVar3 * 0.33333334,fVar1 * 0.33333334,fVar2 * 0.33333334,
                 fVar4 * 0.33333334);
    }
  }
  piVar16 = (int *)*param_1;
  local_78.s.LowPart = NullUpdate_ret();
  if (piVar16 != (int *)local_78.s.LowPart) {
    do {
      iVar14 = piVar16[2];
      piVar18 = (int *)*piVar16;
      local_60 = (1 << (*(byte *)(iVar14 + 0x1a) & 0x1f)) * (1 << (*(byte *)(iVar14 + 0x19) & 0x1f))
                 + -1;
      local_6c = iVar14;
      local_68 = piVar18;
      if (*(char *)(iVar14 + 0x1b) == '\0') {
        local_88 = 0;
      }
      else {
        local_88 = _ftol_nocw();
      }
      local_5c = -*(float *)(iVar14 + 0x84);
      fVar3 = *(float *)(iVar14 + 0x88);
      local_9c = 0.0;
      if (((*(char *)(iVar14 + 0x1e) != '\0') && (piVar16[4] != 0)) &&
         (0.0 < *(float *)(iVar14 + 0x50))) {
        local_9c = param_2 * *(float *)(piVar16[4] + 0x78);
      }
      piVar17 = (int *)piVar16[5];
      if (piVar17 != piVar16 + 5) {
        do {
          piVar7 = (int *)*piVar17;
          iVar14 = (short)piVar17[2] - local_70;
          if (iVar14 < 1) {
            puVar6 = (undefined4 *)piVar17[1];
            *puVar6 = piVar7;
            piVar7[1] = (int)puVar6;
            iVar5 = DAT_0073652c;
            iVar14 = *(int *)(DAT_0073652c + 0x18);
            *piVar17 = *(int *)(DAT_0073652c + 0x10);
            *(int *)(iVar5 + 0x18) = iVar14 + -1;
            *(int **)(iVar5 + 0x10) = piVar17;
          }
          else {
            bVar10 = *(byte *)((int)piVar17 + 0x1f);
            if (local_88 != 0) {
              bVar10 = ((char)((int)(short)piVar17[2] / local_88) - (char)(iVar14 / local_88)) +
                       bVar10 & (byte)local_60;
            }
            local_58 = (int)*(char *)((int)piVar17 + 0x1e);
            local_54 = piVar17[5];
            local_64 = piVar17[4];
            fVar1 = (float)local_58 * 0.007874016 * (float)*(ushort *)(piVar17 + 3) * 0.0078125;
            if (0.0 <= fVar1) {
              fVar2 = -1.0;
            }
            else {
              fVar2 = 1.0;
            }
            local_90 = ((fVar2 * fVar1 * fVar1 * fVar3 + local_5c) * param_2 + fVar1) * param_2 +
                       (float)piVar17[6];
            if (*(char *)(local_6c + 0x1e) != '\0') {
              local_90 = (float)*(byte *)((int)piVar17 + 0xe) * _K_BLUR_MIN_T * local_9c + local_90;
            }
            *(short *)(piVar17 + 2) = (short)iVar14;
            uVar12 = _ftol_nocw();
            piVar17[4] = (int)(float)extraout_ST1;
            *(undefined2 *)(piVar17 + 3) = uVar12;
            piVar17[5] = (int)(float)extraout_ST0;
            piVar17[6] = (int)local_90;
            uVar11 = _ftol_nocw();
            *(undefined1 *)(piVar17 + 7) = uVar11;
            uVar11 = _ftol_nocw();
            *(undefined1 *)((int)piVar17 + 0x1d) = uVar11;
            uVar11 = _ftol_nocw();
            *(byte *)((int)piVar17 + 0x1f) = bVar10;
            *(undefined1 *)((int)piVar17 + 0x1e) = uVar11;
          }
          piVar17 = piVar7;
          piVar18 = local_68;
        } while (piVar7 != piVar16 + 5);
      }
      if ((int *)piVar16[5] == piVar16 + 5) {
        iVar14 = *piVar16;
        piVar17 = (int *)piVar16[1];
        *piVar17 = iVar14;
        *(int **)(iVar14 + 4) = piVar17;
        FUN_00401e10();
        iVar5 = DAT_00736530;
        iVar14 = *(int *)(DAT_00736530 + 0x18);
        *piVar16 = *(int *)(DAT_00736530 + 0x10);
        *(int *)(iVar5 + 0x18) = iVar14 + -1;
        *(int **)(iVar5 + 0x10) = piVar16;
      }
      piVar16 = piVar18;
    } while (piVar18 != (int *)local_78.s.LowPart);
  }
  QueryPerformanceCounter(&local_78);
  uVar9 = DAT_007349c8;
  iVar14 = __allshr();
  local_9c = (float)(iVar14 - local_80._0_4_);
  if ((int)local_9c < 0) {
    local_9c = 0.0;
  }
  param_1[0x17] = (int)((float)(1 << ((byte)uVar9 & 0x1f)) * (float)(int)local_9c * _DAT_007301d0);
  return;
}


// ==== 0x404110 Particles_DrawSystem

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra+capstone) docs/re/render.md */

void Particles_DrawSystem(int *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  float unaff_EDI;
  float fVar14;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  float *pfStack_240;
  float *pfStack_23c;
  undefined4 uStack_238;
  float **ppfStack_234;
  float *pfStack_230;
  int *piStack_22c;
  float *pfStack_228;
  float *pfStack_224;
  undefined4 *puStack_220;
  float *pfStack_21c;
  float *pfStack_218;
  int *piStack_214;
  float *pfStack_210;
  float fStack_20c;
  float *pfStack_208;
  float *pfStack_204;
  undefined *puStack_200;
  float *pfStack_1fc;
  undefined4 *puStack_1f8;
  uint uStack_1f4;
  undefined4 *puVar15;
  float fVar16;
  float fStack_1e4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  int iStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float local_198;
  undefined4 local_194;
  float fStack_184;
  float fStack_17c;
  float fStack_178;
  undefined4 uStack_174;
  int iStack_170;
  int iStack_16c;
  undefined4 *puStack_168;
  float local_164;
  undefined4 *puStack_160;
  undefined4 *puStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  uint uStack_148;
  undefined4 *local_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float *local_130;
  undefined4 local_12c;
  float local_128;
  undefined4 local_120;
  float local_11c;
  undefined4 local_118;
  undefined1 auStack_100 [32];
  float *local_e0;
  undefined4 local_dc;
  undefined4 local_d0;
  float local_cc;
  float local_c0;
  undefined4 local_bc [13];
  int aiStack_88 [33];
  
  if (*(int *)(param_2 + 4) == 1) {
    param_1[0x16] = 0;
    param_1[0x15] = 0;
  }
  piVar7 = (int *)*param_1;
  if (piVar7 != param_1) {
    do {
      if (piVar7 == (int *)0x0) break;
      piVar7 = (int *)*piVar7;
    } while (piVar7 != param_1);
    local_144 = *(undefined4 **)(param_2 + 0x40);
    local_194 = local_144[0xa0];
    uStack_1f4 = 0x40416c;
    bMatrixCopy_b();
    pfVar6 = DAT_0073636c;
    local_128 = local_c0;
    local_118 = local_bc[0];
    local_130 = local_e0;
    local_12c = local_d0;
    local_120 = local_dc;
    local_11c = local_cc;
    if (*(char *)((int)param_1 + 0x4d) == '\0') {
      local_164 = 0.0;
    }
    else {
      local_164 = (float)param_1[0x10];
    }
    uStack_1f4 = 0;
    puStack_1f8 = (undefined4 *)0xe;
    pfStack_1fc = DAT_0073636c;
    local_198 = 0.0;
    puStack_200 = (undefined *)0x4041f0;
    (**(code **)((int)*DAT_0073636c + 0xe4))();
    pcVar12 = "XETT_RoadSDr_SprayA";
    iStack_16c = -1;
    uVar9 = 0x58;
    do {
      iStack_16c = iStack_16c * 0x21 + uVar9;
      pbVar1 = (byte *)(pcVar12 + 1);
      uVar9 = (uint)*pbVar1;
      pcVar12 = pcVar12 + 1;
    } while (*pbVar1 != 0);
    puVar15 = (undefined4 *)*param_1;
    puStack_200 = (undefined *)0x404227;
    puStack_15c = (undefined4 *)NullUpdate_ret();
    if (puVar15 != puStack_15c) {
      do {
        iVar8 = puVar15[2];
        local_144 = (undefined4 *)*puVar15;
        fStack_1c0 = 0.0;
        if (*(int *)(iVar8 + 8) == iStack_16c) goto LAB_00404987;
        fVar16 = (float)puVar15[4];
        if (fVar16 == 0.0) goto LAB_004042e1;
        iVar13 = *(int *)(param_2 + 4);
        if ((1 << ((byte)iVar13 & 0x1f) & *(uint *)((int)fVar16 + 0x534)) == 0) goto LAB_00404987;
        switch(*(undefined4 *)(iVar8 + 0x58)) {
        case 1:
        case 5:
        case 6:
          if ((fStack_1a0 != fVar16) || (*(int *)((int)fStack_150 + 0x284) == 0))
          goto switchD_00404296_caseD_2;
          break;
        case 9:
        case 0xb:
        case 0x1a:
          if (iVar13 != 3) {
joined_r0x004042aa:
            if (fStack_1a0 == fVar16) break;
          }
        default:
switchD_00404296_caseD_2:
LAB_004042e1:
          iVar13 = *(int *)(iVar8 + 0x14);
          fStack_140 = _K_ONE / *(float *)(iVar8 + 0x38);
          if ((iVar13 != 0) && ((iStack_170 == 0 || (puVar15[3] == iStack_170)))) {
            puStack_200 = (undefined *)0x404320;
            Effect_Select();
            puStack_200 = &DAT_0078bcc0;
            pfStack_204 = (float *)0x404330;
            Device_SetWorldMatrix();
            pfStack_208 = (float *)0x40433a;
            pfStack_204 = (float *)iVar13;
            FUN_0040f3d0();
            puStack_200 = (undefined *)0x40434f;
            bMatrixCopy_b();
            puStack_200 = (undefined *)0x404361;
            bMatrixCopy_b();
            bVar2 = *(byte *)(iVar8 + 0x19);
            puStack_160 = (undefined4 *)(int)(char)bVar2;
            puStack_200 = (undefined *)0x2000;
            iVar13 = 0;
            uStack_148 = ~(-1 << (bVar2 & 0x1f));
            local_164 = (float)~(-1 << (*(byte *)(iVar8 + 0x1a) & 0x1f));
            puStack_168 = (undefined4 *)(_K_ONE / (float)(1 << (bVar2 & 0x1f)));
            pfStack_210 = (float *)(&DAT_00718738)[DAT_007187b4];
            pfStack_204 = (float *)&stack0xfffffe10;
            pfStack_208 = (float *)0x0;
            fStack_20c = 0.0;
            fVar16 = _K_ONE / (float)(1 << (*(byte *)(iVar8 + 0x1a) & 0x1f));
            piStack_214 = (int *)0x4043ea;
            (**(code **)((int)*pfStack_210 + 0x2c))();
            puStack_1f8 = *(undefined4 **)((int)puStack_200 + 0x14);
            puStack_168 = (undefined4 *)((int)puStack_200 + 0x14);
            if (puStack_1f8 != puStack_168) {
              do {
                puStack_160 = (undefined4 *)*puStack_1f8;
                pfStack_218 = &fStack_1d0;
                pfStack_21c = &local_c0;
                puStack_200 = (undefined *)
                              (_K_ONE - (float)(int)*(short *)(puStack_1f8 + 2) * 0.0009765625 *
                                        fStack_154);
                fStack_1cc = (float)puStack_1f8[5];
                fStack_1c8 = (float)puStack_1f8[6];
                fStack_1d0 = (float)puStack_1f8[4];
                piStack_214 = (int *)auStack_100;
                fStack_1c4 = 1.0;
                puStack_220 = (undefined4 *)0x404475;
                thunk_FUN_005ac436();
                puStack_200 = (undefined *)(fStack_20c * fStack_20c);
                puStack_220 = local_bc;
                pfStack_224 = &fStack_13c;
                fStack_134 = fStack_20c;
                fStack_178 = fStack_20c * (float)puStack_200;
                pfStack_228 = &local_11c;
                local_130 = (float *)0x3f800000;
                piStack_22c = (int *)0x4044cf;
                fStack_13c = fStack_178;
                fStack_138 = (float)puStack_200;
                thunk_FUN_005ac436();
                fStack_1c0 = local_128 * _K_HALF;
                fStack_138 = fStack_184;
                fStack_1b8 = (float)puStack_168 * fStack_1c0;
                piStack_22c = aiStack_88;
                fStack_134 = fStack_20c;
                pfStack_230 = &fStack_138;
                local_130 = pfStack_218;
                fStack_1b4 = local_164 * fStack_1c0;
                ppfStack_234 = &pfStack_208;
                local_12c = 0x3f800000;
                fStack_1b0 = (float)puStack_160 * fStack_1c0;
                fStack_1c8 = fStack_158 * fStack_1c0;
                fStack_1c4 = fStack_154 * fStack_1c0;
                fStack_1c0 = fStack_1c0 * fStack_150;
                uStack_238 = 0x404574;
                thunk_FUN_005ac436();
                if (unaff_EDI < 0.0) {
                  unaff_EDI = 0.0;
                }
                if ((float)puVar15 < 0.0) {
                  puVar15 = (undefined4 *)0x0;
                }
                if (fVar16 < 0.0) {
                  fVar16 = 0.0;
                }
                if (fStack_1e4 < 0.0) {
                  fStack_1e4 = 0.0;
                }
                if (K_BLUR_MIN_T < unaff_EDI) {
                  unaff_EDI = 255.0;
                }
                if (K_BLUR_MIN_T < (float)puVar15) {
                  puVar15 = (undefined4 *)0x437f0000;
                }
                if (K_BLUR_MIN_T < fVar16) {
                  fVar16 = 255.0;
                }
                if (K_BLUR_MIN_T < fStack_1e4) {
                  fStack_1e4 = 255.0;
                }
                piStack_214 = (int *)0x40464b;
                iVar8 = _ftol_nocw();
                if (iVar8 != 0) {
                  piStack_214 = (int *)0x404661;
                  uVar9 = _ftol_nocw();
                  piStack_214 = (int *)0x40466f;
                  uVar10 = _ftol_nocw();
                  piStack_214 = (int *)0x40467d;
                  uVar11 = _ftol_nocw();
                  fVar14 = (float)(((iVar8 << 8 | uVar9) << 8 | uVar10) << 8 | uVar11);
                  fVar3 = (float)((uint)*(byte *)((int)puStack_1f8 + 0x1f) & (uint)puStack_15c) *
                          fStack_17c;
                  uStack_1f4 = (int)(uint)*(byte *)((int)puStack_1f8 + 0x1f) >>
                               ((byte)uStack_174 & 0x1f) & (uint)fStack_178;
                  fVar5 = (float)(int)uStack_1f4 * (float)pfStack_1fc;
                  fVar4 = fVar3 + fStack_17c;
                  puStack_1f8 = (undefined4 *)(fVar5 + (float)pfStack_1fc);
                  *pfStack_204 = fStack_1b0 + fStack_1a0 + fStack_1d0;
                  pfStack_204[1] = fStack_1ac + fStack_19c + fStack_1cc;
                  pfStack_204[2] = fStack_1a8 + local_198 + fStack_1c8;
                  pfStack_204[3] = fVar14;
                  pfStack_204[4] = fVar3;
                  pfStack_204[5] = fVar5;
                  pfStack_204[6] = (fStack_1d0 - fStack_1a0) + fStack_1b0;
                  pfStack_204[7] = (fStack_1cc - fStack_19c) + fStack_1ac;
                  pfStack_204[8] = (fStack_1c8 - local_198) + fStack_1a8;
                  pfStack_204[9] = fVar14;
                  pfStack_204[10] = fVar4;
                  pfStack_204[0xb] = fVar5;
                  pfStack_204[0xc] = (fStack_1d0 - fStack_1a0) - fStack_1b0;
                  pfStack_204[0xd] = (fStack_1cc - fStack_19c) - fStack_1ac;
                  pfStack_204[0xe] = (fStack_1c8 - local_198) - fStack_1a8;
                  pfStack_204[0xf] = fVar14;
                  pfStack_204[0x10] = fVar4;
                  pfStack_204[0x11] = (float)puStack_1f8;
                  pfStack_204[0x12] = (fStack_1a0 + fStack_1d0) - fStack_1b0;
                  pfStack_204[0x13] = (fStack_19c + fStack_1cc) - fStack_1ac;
                  pfStack_204[0x14] = (local_198 + fStack_1c8) - fStack_1a8;
                  pfStack_204[0x15] = fVar14;
                  pfStack_204[0x16] = fVar3;
                  pfStack_204[0x17] = (float)puStack_1f8;
                  pfStack_204 = pfStack_204 + 0x18;
                  iVar13 = iVar13 + 1;
                  if (iVar13 == 300) {
                    piStack_214 = (int *)(&DAT_00718738)[DAT_007187b4];
                    pfStack_218 = (float *)0x404856;
                    (**(code **)(*piStack_214 + 0x30))();
                    puStack_220 = (undefined4 *)(&DAT_00718738)[DAT_007187b4];
                    pfStack_218 = (float *)0x18;
                    pfStack_21c = (float *)0x0;
                    pfStack_224 = (float *)0x0;
                    pfStack_228 = pfVar6;
                    piStack_22c = (int *)0x404872;
                    (**(code **)((int)*pfVar6 + 400))();
                    piStack_22c = DAT_007187b0;
                    pfStack_230 = pfVar6;
                    ppfStack_234 = (float **)0x404881;
                    (**(code **)((int)*pfVar6 + 0x1a0))();
                    ppfStack_234 = (float **)0x1;
                    uStack_238 = 0x1b;
                    pfStack_23c = pfVar6;
                    pfStack_240 = (float *)0x40488e;
                    (**(code **)((int)*pfVar6 + 0xe4))();
                    pfStack_240 = (float *)0x258;
                    uStack_244 = 0;
                    uStack_248 = 0x4b0;
                    uStack_24c = 0;
                    (**(code **)((int)*pfVar6 + 0x148))(pfVar6,4,0);
                    DAT_007187b4 = (DAT_007187b4 + 1) % 0x1e;
                    (**(code **)(*(int *)(&DAT_00718738)[DAT_007187b4] + 0x2c))
                              ((int *)(&DAT_00718738)[DAT_007187b4],0,0,&uStack_24c,0);
                    iVar13 = 0;
                  }
                }
                puStack_1f8 = puStack_160;
              } while (puStack_160 != puStack_168);
            }
            piStack_214 = (int *)(&DAT_00718738)[DAT_007187b4];
            pfStack_218 = (float *)0x404906;
            (**(code **)(*piStack_214 + 0x30))();
            fVar16 = fStack_1c0;
            if (iVar13 != 0) {
              pfStack_208 = (float *)(&DAT_00718738)[DAT_007187b4];
              puStack_200 = (undefined *)0x18;
              pfStack_204 = (float *)0x0;
              fStack_20c = 0.0;
              pfStack_210 = pfVar6;
              piStack_214 = (int *)0x404926;
              (**(code **)((int)*pfVar6 + 400))();
              piStack_214 = DAT_007187b0;
              pfStack_218 = pfVar6;
              pfStack_21c = (float *)0x404935;
              (**(code **)((int)*pfVar6 + 0x1a0))();
              pfStack_21c = (float *)0x1;
              puStack_220 = (undefined4 *)0x1b;
              pfStack_224 = pfVar6;
              pfStack_228 = (float *)0x404942;
              (**(code **)((int)*pfVar6 + 0xe4))();
              pfStack_228 = (float *)(iVar13 * 2);
              piStack_22c = (int *)0x0;
              pfStack_230 = (float *)(iVar13 * 4);
              ppfStack_234 = (float **)0x0;
              uStack_238 = 0;
              pfStack_23c = (float *)0x4;
              pfStack_240 = pfVar6;
              uStack_244 = 0x40495f;
              (**(code **)((int)*pfVar6 + 0x148))();
              DAT_007187b4 = (DAT_007187b4 + 1) % 0x1e;
              fVar16 = (float)((int)fStack_1c0 + iVar13);
            }
            if (fVar16 != 0.0) {
              iStack_1a4 = iStack_1a4 + (int)fVar16;
            }
          }
          break;
        case 10:
          if (iVar13 != 3) goto joined_r0x004042aa;
        }
LAB_00404987:
        puVar15 = local_144;
      } while (local_144 != puStack_15c);
    }
    puStack_200 = (undefined *)0x1;
    pfStack_204 = (float *)0xe;
    param_1[0x15] = param_1[0x15] + iStack_1a4;
    pfStack_208 = pfVar6;
    fStack_20c = 5.903921e-39;
    (**(code **)((int)*pfVar6 + 0xe4))();
  }
  return;
}


// ==== 0x4049f0 List_DeleteAllNodes

/* [canon] runtime med (ghidra-canon) docs/re/car.md */

void __fastcall List_DeleteAllNodes(int *param_1)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  
  _Memory = (int *)*param_1;
  while (_Memory != param_1) {
    piVar1 = (int *)_Memory[1];
    iVar2 = *_Memory;
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_00401db0();
    _free(_Memory);
    _Memory = (int *)*param_1;
  }
  return;
}


// ==== 0x404a30 FUN_00404a30

void FUN_00404a30(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_00736530;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00401e10();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x404a70 List_ReleaseAllToPool

/* [canon] runtime med (ghidra-canon) docs/re/car.md */

void List_ReleaseAllToPool(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_0073652c;
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x404ab0 FUN_00404ab0

void FUN_00404ab0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 local_400 [1024];
  
  _vsprintf(local_400,param_1,&stack0x00000008);
  if (DAT_0073651c == (code *)0x0) {
    _printf_67147f("FATAL ERROR: ");
    _printf_67147f("%s\n",local_400);
  }
  else {
    iVar2 = (*DAT_0073651c)(local_400);
    if (iVar2 == 0) {
      return;
    }
  }
  FUN_006720ea(1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x404b20 FUN_00404b20

void FUN_00404b20(void)

{
  char *pcVar1;
  char cVar2;
  char *unaff_EDI;
  
  if (unaff_EDI != (char *)0x0) {
    cVar2 = *unaff_EDI;
    while (cVar2 != '\0') {
      cVar2 = FUN_00671b76((int)*unaff_EDI);
      *unaff_EDI = cVar2;
      pcVar1 = unaff_EDI + 1;
      unaff_EDI = unaff_EDI + 1;
      cVar2 = *pcVar1;
    }
  }
  return;
}


// ==== 0x404b50 FUN_00404b50

void FUN_00404b50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_00405350();
  iVar1 = unaff_ESI + 0x3c;
  *(int *)iVar1 = iVar1;
  *(int *)(unaff_ESI + 0x40) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x44) = param_1;
  FUN_00405350(param_2);
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  return;
}


// ==== 0x404b90 FUN_00404b90

void FUN_00404b90(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  int unaff_ESI;
  
  pvVar2 = _malloc(0x30);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00405350(&DAT_006cc568,param_1);
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 0x40);
  *puVar1 = piVar3;
  *(int **)(unaff_ESI + 0x40) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_ESI + 0x3c;
  *(int *)(unaff_ESI + 0x38) = *(int *)(unaff_ESI + 0x38) + 1;
  return;
}


// ==== 0x404bd0 FUN_00404bd0

int __thiscall FUN_00404bd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  FILE *_File;
  size_t sVar2;
  void *_DstBuf;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685ca3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00405350(param_2);
  iVar1 = param_1 + 0x30;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0x34) = iVar1;
  local_4 = 1;
  _File = (FILE *)_fopen(param_2,&DAT_006c16ac);
  if (_File == (FILE *)0x0) {
    FUN_00404ab0("Could not open [%s] with params [%s]",param_2,&DAT_006c16ac);
  }
  _fseek(_File,0,2);
  sVar2 = _ftell(_File);
  _fseek(_File,0,0);
  _DstBuf = _malloc(sVar2 + 4);
  sVar2 = _fread(_DstBuf,1,sVar2,_File);
  _fclose(_File);
  *(undefined1 *)((int)_DstBuf + sVar2) = 0;
  *(undefined1 *)((int)_DstBuf + sVar2 + 1) = 0;
  *(undefined1 *)((int)_DstBuf + sVar2 + 2) = 0;
  *(undefined1 *)((int)_DstBuf + sVar2 + 3) = 0;
  FUN_00404db0(param_1,_DstBuf,param_3);
  _free(_DstBuf);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x404cc0 FUN_00404cc0

void FUN_00404cc0(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int *_Memory;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 *_Memory_00;
  int *_Memory_01;
  
  piVar1 = (int *)(param_1 + 0x30);
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar3 = *_Memory;
    piVar4 = (int *)_Memory[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    piVar4 = _Memory + 0x15;
    piVar5 = (int *)0x0;
    if ((int *)_Memory[0x14] != piVar4) {
      piVar5 = (int *)_Memory[0x14];
    }
    _Memory[0x14] = (int)piVar4;
    *(undefined1 *)piVar4 = 0;
    if (piVar5 != (int *)0x0) {
      _free(piVar5);
    }
    piVar4 = (int *)_Memory[0xf];
    while (piVar4 != _Memory + 0xf) {
      iVar3 = *piVar4;
      piVar5 = (int *)piVar4[1];
      *piVar5 = iVar3;
      *(int **)(iVar3 + 4) = piVar5;
      piVar5 = piVar4 + 3;
      _Memory_01 = (int *)0x0;
      if ((int *)piVar4[2] != piVar5) {
        _Memory_01 = (int *)piVar4[2];
      }
      piVar4[2] = (int)piVar5;
      *(undefined1 *)piVar5 = 0;
      if (_Memory_01 != (int *)0x0) {
        _free(_Memory_01);
      }
      _free(piVar4);
      piVar4 = (int *)_Memory[0xf];
    }
    piVar4 = _Memory + 5;
    piVar5 = (int *)0x0;
    if ((int *)_Memory[4] != piVar4) {
      piVar5 = (int *)_Memory[4];
    }
    _Memory[4] = (int)piVar4;
    *(undefined1 *)piVar4 = 0;
    if (piVar5 != (int *)0x0) {
      _free(piVar5);
    }
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  puVar2 = (undefined1 *)(param_1 + 0xc);
  _Memory_00 = (undefined1 *)0x0;
  if (*(undefined1 **)(param_1 + 8) != puVar2) {
    _Memory_00 = *(undefined1 **)(param_1 + 8);
  }
  *(undefined1 **)(param_1 + 8) = puVar2;
  *puVar2 = 0;
  if (_Memory_00 != (undefined1 *)0x0) {
    _free(_Memory_00);
  }
  return;
}


// ==== 0x404db0 FUN_00404db0

void FUN_00404db0(int param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  int *****lpFileName;
  int ******ppppppiVar2;
  int ******ppppppiVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  void *pvVar8;
  int *piVar9;
  undefined4 uVar10;
  HANDLE hFindFile;
  char *pcVar11;
  char cVar12;
  uint uVar13;
  int *******pppppppiVar14;
  int iVar15;
  uint local_590;
  int local_58c;
  undefined1 local_584 [48];
  int ******local_554 [4];
  char acStack_541 [1025];
  _WIN32_FIND_DATAA local_140;
  
  uVar13 = 0;
  iVar15 = 0;
  bVar4 = false;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  bVar6 = false;
  local_590 = 0;
  local_58c = 1;
  bVar5 = false;
  cVar7 = '\0';
  do {
    cVar12 = *param_2;
    pcVar11 = param_2 + 1;
    if (cVar12 == '\r') {
      cVar12 = *pcVar11;
      pcVar11 = param_2 + 2;
    }
    param_2 = pcVar11;
    if (cVar12 == '\0') {
      cVar12 = '\n';
LAB_00404e10:
      if (uVar13 != 0) {
        if (param_3 == 0) {
          return;
        }
        uVar10 = FUN_004051a0();
        FUN_00404ab0("Unterminated quotes %s\n",uVar10);
        return;
      }
      local_58c = local_58c + 1;
      bVar5 = false;
LAB_00404e20:
      if (bVar4) {
        if ((uVar13 == 0) &&
           ((((cVar12 == ' ' || (cVar12 == '\n')) ||
             ((cVar12 == '\t' || ((cVar12 == '=' || (cVar12 == ',')))))) ||
            ((cVar12 == '\r' || ((iVar15 != 0 && (acStack_541[iVar15] == ':')))))))) {
          acStack_541[iVar15 + 1] = '\0';
          if (bVar6) {
            FUN_00404b20();
            pvVar8 = _malloc(0x78);
            if (pvVar8 == (void *)0x0) {
              piVar9 = (int *)0x0;
            }
            else {
              piVar9 = (int *)FUN_00404b50(local_58c,*(undefined4 *)(param_1 + 8));
            }
            *(int **)(param_1 + 0x3c) = piVar9;
            *(undefined4 *)(param_1 + 0x38) = 1;
            puVar1 = *(undefined4 **)(param_1 + 0x34);
            *puVar1 = piVar9;
            *(int **)(param_1 + 0x34) = piVar9;
            piVar9[1] = (int)puVar1;
            *piVar9 = param_1 + 0x30;
          }
          else {
            if (*(int *)(param_1 + 0x3c) == 0) {
              if (param_3 == 0) {
                return;
              }
              uVar10 = FUN_004051a0();
              FUN_00404ab0("No command %s\n",uVar10);
              return;
            }
            FUN_00404b90(acStack_541 + 1);
          }
          bVar4 = false;
          iVar15 = 0;
          uVar13 = local_590;
        }
        else if (iVar15 < 0x3ff) {
          acStack_541[iVar15 + 1] = cVar12;
          iVar15 = iVar15 + 1;
          if ((cVar12 != ':') || (bVar6 = true, uVar13 != 0)) goto LAB_00405017;
        }
      }
      else if (((((cVar12 != ' ') && (cVar12 != '\n')) && (cVar12 != '\t')) &&
               ((cVar12 != '=' && (cVar12 != ',')))) && (cVar12 != '\r')) {
        iVar15 = 1;
        acStack_541[1] = cVar12;
        bVar4 = true;
LAB_00405017:
        bVar6 = false;
      }
    }
    else {
      if (cVar12 == '\n') goto LAB_00404e10;
      if (!bVar5) {
        if (cVar12 == '\"') {
          if ((uVar13 == 0) || (*pcVar11 != '\"')) {
            if ((cVar7 == '\"') && ((*(int *)(param_1 + 0x38) != 0 && (iVar15 == 0)))) {
              FUN_00404b90(&DAT_006b9172);
              uVar13 = local_590;
            }
            uVar13 = ~uVar13;
            local_590 = uVar13;
          }
          else if (bVar4) {
            if (iVar15 < 0x3ff) {
              acStack_541[iVar15 + 1] = '\"';
              iVar15 = iVar15 + 1;
              cVar12 = '\"';
              param_2 = pcVar11 + 1;
            }
          }
          else {
            bVar6 = false;
            acStack_541[1] = cVar12;
            iVar15 = 1;
            bVar4 = true;
            param_2 = pcVar11 + 1;
          }
          goto LAB_0040501b;
        }
        if (((cVar12 == '/') && (cVar7 == '/')) && (uVar13 == 0)) {
          iVar15 = iVar15 + -1;
          bVar5 = true;
          if (iVar15 == 0) {
            bVar4 = false;
          }
          goto LAB_0040501b;
        }
        goto LAB_00404e20;
      }
    }
LAB_0040501b:
    cVar7 = cVar12;
    if (param_2[-1] == '\0') {
      for (pppppppiVar14 = *(int ********)(param_1 + 0x30);
          pppppppiVar14 != (int *******)(param_1 + 0x30);
          pppppppiVar14 = (int *******)*pppppppiVar14) {
        iVar15 = __stricmp((char *)pppppppiVar14[4],"INCLUDESCRIPT:");
        if (iVar15 == 0) {
          if (pppppppiVar14[0xe] == (int ******)0x1) {
            lpFileName = pppppppiVar14[0xf][2];
            hFindFile = FindFirstFileA((LPCSTR)lpFileName,&local_140);
            if (hFindFile == (HANDLE)0xffffffff) {
              if (param_3 != 0) {
                FUN_00404ab0("Could not find \'INCLUDESCRIPT:\' file \'%s\' at line %d in %s\n",
                             lpFileName,pppppppiVar14[0x11],pppppppiVar14[0x14]);
              }
            }
            else {
              FindClose(hFindFile);
              FUN_00404bd0(lpFileName,1);
              while ((int *******)local_554[0] != local_554) {
                ppppppiVar2 = (int ******)*local_554[0];
                ppppppiVar3 = (int ******)local_554[0][1];
                *ppppppiVar3 = (int *****)ppppppiVar2;
                ppppppiVar2[1] = (int *****)ppppppiVar3;
                ppppppiVar2 = *pppppppiVar14;
                *pppppppiVar14 = local_554[0];
                ppppppiVar2[1] = (int *****)local_554[0];
                local_554[0][1] = (int *****)pppppppiVar14;
                *local_554[0] = (int *****)ppppppiVar2;
                pppppppiVar14 = (int *******)local_554[0];
              }
              FUN_00404cc0(local_584);
            }
          }
          else if (param_3 != 0) {
            FUN_00404ab0("Expected 1 argument to INCLUDESCRIPT:  at line %d in %s\n",
                         pppppppiVar14[0x11],pppppppiVar14[0x14]);
          }
        }
      }
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
      return;
    }
  } while( true );
}


// ==== 0x4051a0 FUN_004051a0

undefined * FUN_004051a0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x38) != 0) {
    _sprintf(&DAT_0078ee40,"line %d in %s",*(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x44),
             *(undefined4 *)(*(int *)(in_EAX + 0x3c) + 0x50));
    return &DAT_0078ee40;
  }
  _sprintf(&DAT_0078ee40,&DAT_006cc568,*(undefined4 *)(in_EAX + 8));
  return &DAT_0078ee40;
}


// ==== 0x4051f0 FUN_004051f0

undefined4 FUN_004051f0(char *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)(unaff_ESI + 0x30);
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  if (*(undefined4 **)(unaff_ESI + 0x3c) == puVar1) {
    return 0;
  }
  while( true ) {
    if (*(undefined4 **)(unaff_ESI + 0x3c) == (undefined4 *)0x0) {
      *(undefined4 *)(unaff_ESI + 0x3c) = *puVar1;
    }
    else {
      *(undefined4 *)(unaff_ESI + 0x3c) = **(undefined4 **)(unaff_ESI + 0x3c);
    }
    if (*(undefined4 **)(unaff_ESI + 0x3c) == puVar1) break;
    if ((param_1 == (char *)0x0) ||
       (iVar2 = __stricmp((char *)(*(undefined4 **)(unaff_ESI + 0x3c))[4],param_1), iVar2 == 0)) {
      *(undefined4 *)(unaff_ESI + 0x38) = 1;
      *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x3c);
      return *(undefined4 *)(*(int *)(unaff_ESI + 0x3c) + 0x10);
    }
  }
  return 0;
}


// ==== 0x405260 FUN_00405260

long FUN_00405260(void)

{
  undefined4 *puVar1;
  char *_Str;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int unaff_EDI;
  long local_4;
  
  if ((*(int *)(unaff_EDI + 0x3c) == 0) ||
     (*(int *)(unaff_EDI + 0x40) == *(int *)(unaff_EDI + 0x3c) + 0x3c)) {
    uVar2 = FUN_004051a0();
    FUN_00404ab0("Not enough arguments %s\n",uVar2);
  }
  puVar1 = *(undefined4 **)(unaff_EDI + 0x40);
  *(undefined4 *)(unaff_EDI + 0x40) = *puVar1;
  _Str = (char *)puVar1[2];
  if ((*_Str == '0') && (_Str[1] == 'x')) {
    local_4 = 0;
    _sscanf(_Str,"%X",&local_4);
    return local_4;
  }
  iVar3 = _isdigit((int)*_Str);
  if ((iVar3 == 0) && (*_Str != '-')) {
    uVar2 = FUN_004051a0();
    FUN_00404ab0("Expected a number but found %s %s\n",_Str,uVar2);
    return 0;
  }
  lVar4 = _atoi(_Str);
  return lVar4;
}


// ==== 0x405300 FUN_00405300

float10 FUN_00405300(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_ESI;
  float local_4;
  
  if ((*(int *)(unaff_ESI + 0x3c) == 0) ||
     (*(int *)(unaff_ESI + 0x40) == *(int *)(unaff_ESI + 0x3c) + 0x3c)) {
    uVar2 = FUN_004051a0();
    FUN_00404ab0("Not enough arguments %s\n",uVar2);
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 0x40);
  *(undefined4 *)(unaff_ESI + 0x40) = *puVar1;
  _sscanf((char *)puVar1[2],"%f",&local_4);
  return (float10)local_4;
}


// ==== 0x405350 FUN_00405350

void FUN_00405350(char *param_1)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  undefined1 local_800 [2048];
  
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    pcVar2 = param_1;
    while (cVar1 != '\0') {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      if (cVar1 == '%') {
        _vsprintf(local_800,param_1,&stack0x00000008);
        break;
      }
      cVar1 = *pcVar2;
    }
  }
  *(int *)(in_EAX + 8) = in_EAX + 0xc;
  FUN_004053f0();
  return;
}


// ==== 0x4053c0 FUN_004053c0

void __fastcall FUN_004053c0(int param_1)

{
  undefined1 *puVar1;
  undefined1 *_Memory;
  
  puVar1 = (undefined1 *)(param_1 + 0xc);
  _Memory = (undefined1 *)0x0;
  if (*(undefined1 **)(param_1 + 8) != puVar1) {
    _Memory = *(undefined1 **)(param_1 + 8);
  }
  *(undefined1 **)(param_1 + 8) = puVar1;
  *puVar1 = 0;
  if (_Memory != (undefined1 *)0x0) {
    _free(_Memory);
  }
  return;
}


// ==== 0x4053f0 FUN_004053f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004053f0(void)

{
  undefined1 *puVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *_Memory;
  int unaff_ESI;
  char *unaff_EDI;
  
  DAT_00736520 = DAT_00736520 + 1;
  puVar1 = (undefined1 *)(unaff_ESI + 0xc);
  _Memory = (undefined1 *)0x0;
  if (*(undefined1 **)(unaff_ESI + 8) != puVar1) {
    _Memory = *(undefined1 **)(unaff_ESI + 8);
  }
  if (unaff_EDI == (char *)0x0) {
    *(undefined1 **)(unaff_ESI + 8) = puVar1;
    *puVar1 = 0;
  }
  else {
    pcVar3 = unaff_EDI;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if ((int)pcVar3 - (int)(unaff_EDI + 1) < 0x24) {
      _DAT_00736524 = _DAT_00736524 + 1;
      *(undefined1 **)(unaff_ESI + 8) = puVar1;
      iVar4 = (int)puVar1 - (int)unaff_EDI;
      do {
        cVar2 = *unaff_EDI;
        unaff_EDI[iVar4] = cVar2;
        unaff_EDI = unaff_EDI + 1;
      } while (cVar2 != '\0');
    }
    else {
      DAT_00736528 = DAT_00736528 + 1;
      pcVar3 = _malloc(((int)pcVar3 - (int)(unaff_EDI + 1)) + 1);
      *(char **)(unaff_ESI + 8) = pcVar3;
      do {
        cVar2 = *unaff_EDI;
        unaff_EDI = unaff_EDI + 1;
        *pcVar3 = cVar2;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
    }
  }
  if (_Memory != (undefined1 *)0x0) {
    _free(_Memory);
  }
  return;
}


// ==== 0x405490 FUN_00405490

void FUN_00405490(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int *unaff_EDI;
  
  _Memory = (int *)*unaff_EDI;
  while (_Memory != unaff_EDI) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    FUN_004054f0();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4054c0 FUN_004054c0

void FUN_004054c0(void)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  
  _Memory = (int *)*unaff_EDI;
  while (_Memory != unaff_EDI) {
    piVar1 = (int *)_Memory[1];
    iVar2 = *_Memory;
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_004053c0();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4054f0 FUN_004054f0

void FUN_004054f0(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int unaff_ESI;
  
  puVar1 = (undefined1 *)(unaff_ESI + 0x54);
  puVar2 = (undefined1 *)0x0;
  if (*(undefined1 **)(unaff_ESI + 0x50) != puVar1) {
    puVar2 = *(undefined1 **)(unaff_ESI + 0x50);
  }
  *(undefined1 **)(unaff_ESI + 0x50) = puVar1;
  *puVar1 = 0;
  if (puVar2 != (undefined1 *)0x0) {
    _free(puVar2);
  }
  FUN_004054c0();
  puVar1 = (undefined1 *)(unaff_ESI + 0x14);
  puVar2 = (undefined1 *)0x0;
  if (*(undefined1 **)(unaff_ESI + 0x10) != puVar1) {
    puVar2 = *(undefined1 **)(unaff_ESI + 0x10);
  }
  *(undefined1 **)(unaff_ESI + 0x10) = puVar1;
  *puVar1 = 0;
  if (puVar2 != (undefined1 *)0x0) {
    _free(puVar2);
  }
  return;
}


// ==== 0x405550 Ptr_SetNull

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __fastcall Ptr_SetNull(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== 0x405560 FUN_00405560

void __fastcall FUN_00405560(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  *in_EAX = *param_1;
  return;
}


// ==== 0x405570 InputDevice::IsKeyboardType

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

undefined4 InputDevice__IsKeyboardType(void)

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


// ==== 0x4055e0 DegToRad

/* [canon] runtime high (hopper+capstone) docs/re/misc.md */

float10 DegToRad(float param_1)

{
  return (float10)param_1 * (float10)0.017453292;
}


// ==== 0x4055f0 FUN_004055f0

void FUN_004055f0(void)

{
  return;
}


// ==== 0x405600 FUN_00405600

float10 FUN_00405600(float param_1)

{
  return ABS((float10)param_1);
}


// ==== 0x405610 FUN_00405610

void FUN_00405610(void)

{
  _ftol_nocw();
  FUN_00564b10();
  return;
}


// ==== 0x405630 Input::EnumDevicesBySemanticsCallback

/* [canon] input med (capstone) docs/re/hud_input.md */

undefined4 Input__EnumDevicesBySemanticsCallback(int param_1)

{
  if (*(char *)(param_1 + 0x24) == '\x13') {
    InputKeyboard__InitDevice();
  }
  return 1;
}


// ==== 0x405660 Input::Init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void Input__Init(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  pvStack_c = ExceptionList;
  DAT_00736510 = DAT_00736350;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00736350 + 4))(DAT_00736350);
  Input__InitActionFormats();
  puVar2 = &DAT_00719b38;
  (**(code **)(*DAT_00736510 + 0x24))
            (DAT_00736510,0,&DAT_00719b38,Input__EnumDevicesBySemanticsCallback,&DAT_00719b38,0);
  pvVar1 = _malloc(0x2c18);
  if (pvVar1 == (void *)0x0) {
    DAT_00736500 = 0;
  }
  else {
    DAT_00736500 = EZWheel__Create(DAT_00736380);
  }
  _DAT_00719770 = 0xffffffff;
  _DAT_00719774 = 0xffffffff;
  DAT_00719780 = 0xffffffff;
  DAT_00719784 = 0xffffffff;
  _DAT_007187b8 = 0xffffffff;
  _DAT_007187bc = 0xffffffff;
  DAT_00719779 = 0;
  DAT_00719778 = 0;
  DAT_00719788._1_1_ = 0;
  DAT_00719788._0_1_ = 0;
  DAT_007187c1 = 0;
  DAT_007187c0 = 0;
  DAT_0071977b = 0x80;
  DAT_0071977a = 0x80;
  DAT_00719788._3_1_ = 0x80;
  DAT_00719788._2_1_ = 0x80;
  DAT_007187c3 = 0x80;
  DAT_007187c2 = 0x80;
  ExceptionList = puVar2;
  return;
}


// ==== 0x405760 FUN_00405760

void FUN_00405760(void)

{
  void *_Memory;
  
  if (DAT_007187c8 != (int *)0x0) {
    (**(code **)(*DAT_007187c8 + 0x20))(DAT_007187c8);
    (**(code **)(*DAT_007187c8 + 8))(DAT_007187c8);
    DAT_007187c8 = (int *)0x0;
  }
  _Memory = DAT_00736500;
  if (DAT_00736500 != (void *)0x0) {
    FUN_00419cc0(DAT_00736500);
    _free(_Memory);
  }
  if (DAT_00736510 != (int *)0x0) {
    (**(code **)(*DAT_00736510 + 8))(DAT_00736510);
    DAT_00736510 = (int *)0x0;
  }
  return;
}


// ==== 0x4057c0 Input::SelectActionMapForGameState

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void Input__SelectActionMapForGameState(void)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  bVar3 = false;
  if (DAT_007361f0 != (int *)0x0) {
    iVar1 = *DAT_007361f0;
    if (((iVar1 == 0) || (iVar1 == 2)) || (iVar1 == 3)) {
      if (*DAT_0073619c != 2) {
        bVar3 = true;
      }
    }
    else {
      bVar3 = iVar1 == 4;
    }
  }
  if ((DAT_0077a920 == 3) || (!bVar3)) {
    if (DAT_007041c4 == '\0') {
      DAT_007041c4 = '\x01';
      puVar2 = &DAT_0078daa8;
      do {
        InputDevice__SetActionMap(1);
        puVar2 = puVar2 + 0x270;
      } while ((int)puVar2 < 0x78e948);
    }
  }
  else if (DAT_007041c4 != '\0') {
    DAT_007041c4 = 0;
    puVar2 = &DAT_0078daa8;
    do {
      InputDevice__SetActionMap(0);
      puVar2 = puVar2 + 0x270;
    } while ((int)puVar2 < 0x78e948);
    return;
  }
  return;
}


// ==== 0x405860 Input::DropUnpluggedWheels

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void Input__DropUnpluggedWheels(void)

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
      cVar2 = InputDevice__IsKeyboardType();
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


// ==== 0x4058d0 Input::AssignNewWheels

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void Input__AssignNewWheels(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  
  iVar3 = 0;
  do {
    if ((&DAT_0071d89c)[iVar3] != 0) {
      puVar4 = &DAT_0078daa8;
      do {
        if ((iVar3 == *(int *)(puVar4 + 0x130)) &&
           (cVar1 = InputDevice__IsKeyboardType(), cVar1 == '\0')) goto LAB_00405956;
        puVar4 = puVar4 + 0x270;
      } while ((int)puVar4 < 0x78e948);
      iVar5 = 0;
      puVar2 = &DAT_0078dbdc;
      do {
        if (*(int *)(puVar2 + -4) == -1) {
          switch(*puVar2) {
          case 0x13:
            break;
          default:
            if (iVar5 < 6) {
              Input__AssignWheelToSlot();
            }
            goto LAB_00405956;
          }
        }
        puVar2 = puVar2 + 0x270;
        iVar5 = iVar5 + 1;
      } while ((int)puVar2 < 0x78ea7c);
    }
LAB_00405956:
    iVar3 = iVar3 + 1;
    if (1 < iVar3) {
      return;
    }
  } while( true );
}


// ==== 0x405980 Input::GetState

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

undefined4 * __thiscall Input__GetState(int *param_1,int param_2,undefined4 *param_3)

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
        InputDevice__ReadState();
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
          EZWheel__StopEffect(iVar2);
        }
      }
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x2538);
      if ((cVar1 != '\0') && ((&DAT_0071d890)[iVar2] != 0)) {
        cVar1 = FUN_0041bc20(DAT_00736500 + 0x2538);
        if (cVar1 != '\0') {
          EZWheel__StopEffect(iVar2);
        }
      }
      cVar1 = FUN_0041bc20(DAT_00736500 + 0x2498);
      if ((cVar1 != '\0') && ((&DAT_0071d890)[iVar2] != 0)) {
        cVar1 = FUN_0041bc20(DAT_00736500 + 0x2498);
        if (cVar1 != '\0') {
          EZWheel__StopEffect(iVar2);
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


// ==== 0x405bf0 FUN_00405bf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00405bf0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006cc0cc;
  param_1[0x46] = 1;
  param_1[0x4c] = 0xffffffff;
  DAT_007187c8 = 0;
  _DAT_00719790 = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0xffffffff;
  *(undefined1 *)((int)param_1 + 0x13) = 0x80;
  *(undefined1 *)((int)param_1 + 0x12) = 0x80;
  return;
}


// ==== 0x405c30 FUN_00405c30

undefined4 * __thiscall FUN_00405c30(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006cc0cc;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x405c50 FUN_00405c50

void __fastcall FUN_00405c50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006cc0cc;
  return;
}


// ==== 0x405c60 InputKeyboard::InitDevice

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void __fastcall InputKeyboard__InitDevice(int param_1)

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
  InputKeyboard__CopyDefaultActionTables(unaff_EDI);
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


// ==== 0x405d40 FUN_00405d40

void FUN_00405d40(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint in_EAX;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = DAT_007197a4;
  uVar4 = in_EAX >> 8 & 0xffff | (in_EAX & 0xff) << 8;
  uVar5 = 0;
  bVar1 = true;
  if (DAT_007197a4 == 0) {
    return;
  }
  puVar3 = &DAT_007187f0;
  do {
    if (*puVar3 == uVar4) {
      puVar3[-4] = 0;
      puVar3[-3] = 0;
      puVar3[-2] = 0;
      *puVar3 = 0;
      puVar3[-1] = 0;
      puVar3[1] = 0;
    }
    if (puVar3[-8] == param_3) {
      if ((param_2 != 1) || (!bVar1)) {
        (&DAT_007187f4)[uVar5 * 10] = 0x20;
        (&DAT_007187e0)[uVar5 * 10] = *(undefined4 *)(param_1 + 0x11c);
        (&DAT_007187e4)[uVar5 * 10] = *(undefined4 *)(param_1 + 0x120);
        (&DAT_007187e8)[uVar5 * 10] = *(undefined4 *)(param_1 + 0x124);
        (&DAT_007187ec)[uVar5 * 10] = *(undefined4 *)(param_1 + 0x128);
        (&DAT_007187f0)[uVar5 * 10] = uVar4;
        return;
      }
      bVar1 = false;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar3 + 10;
    if (uVar2 <= uVar5) {
      return;
    }
  } while( true );
}


// ==== 0x405e10 FUN_00405e10

void FUN_00405e10(void)

{
  undefined4 unaff_ESI;
  
  if (DAT_007187c8 != (int *)0x0) {
    (**(code **)(*DAT_007187c8 + 0x20))(DAT_007187c8);
    FUN_00405d40(unaff_ESI,0,1);
    FUN_00405d40(unaff_ESI,0,2);
    FUN_00405d40(unaff_ESI,0,3);
    FUN_00405d40(unaff_ESI,0,4);
    FUN_00405d40(unaff_ESI,0,7);
    FUN_00405d40(unaff_ESI,0,8);
    FUN_00405d40(unaff_ESI,0,5);
    FUN_00405d40(unaff_ESI,0,6);
    FUN_00405d40(unaff_ESI,0,10);
    FUN_00405d40(unaff_ESI,0,9);
    FUN_00405d40(unaff_ESI,0,0xc);
    FUN_00405d40(unaff_ESI,0,0xe);
    FUN_00405d40(unaff_ESI,1,1);
    FUN_00405d40(unaff_ESI,1,2);
    FUN_00405d40(unaff_ESI,1,3);
    FUN_00405d40(unaff_ESI,1,4);
    FUN_00405d40(unaff_ESI,1,7);
    FUN_00405d40(unaff_ESI,1,8);
    FUN_00405d40(unaff_ESI,1,5);
    FUN_00405d40(unaff_ESI,1,6);
    FUN_00405d40(unaff_ESI,1,10);
    FUN_00405d40(unaff_ESI,1,9);
    FUN_00405d40(unaff_ESI,1,0xc);
    FUN_00405d40(unaff_ESI,1,0xe);
  }
  InputDevice__SetActionMap(0);
  InputDevice__SetActionMap(1);
  return;
}


// ==== 0x405fa0 InputDevice::GetInstanceGuid

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputDevice__GetInstanceGuid(void)

{
  int *piVar1;
  int in_EAX;
  undefined4 *unaff_ESI;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  
  if (*(int *)(in_EAX + 0x134) != 0x13) {
    piVar1 = (int *)(&DAT_0071d89c)[*(int *)(in_EAX + 0x130)];
    local_244 = 0x244;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x3c))(piVar1,&local_244);
    }
    *unaff_ESI = local_240;
    unaff_ESI[1] = local_23c;
    unaff_ESI[2] = local_238;
    unaff_ESI[3] = local_234;
    return;
  }
  *unaff_ESI = *(undefined4 *)(in_EAX + 0x11c);
  unaff_ESI[1] = *(undefined4 *)(in_EAX + 0x120);
  unaff_ESI[2] = *(undefined4 *)(in_EAX + 0x124);
  unaff_ESI[3] = *(undefined4 *)(in_EAX + 0x128);
  return;
}


// ==== 0x406020 FUN_00406020

uint __thiscall FUN_00406020(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  
  uVar1 = 0;
  piVar5 = &DAT_007041c8;
  uVar4 = 0;
  do {
    iVar3 = 4;
    bVar8 = true;
    piVar6 = (int *)(param_1 + 0x14);
    piVar7 = piVar5;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *piVar6 == *piVar7;
      piVar6 = piVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      puVar2 = (undefined4 *)(&DAT_00704218 + uVar1 * 0x90);
      param_2 = param_2 - (int)param_3;
      iVar3 = 0x10;
      do {
        *(undefined4 *)(param_2 + (int)param_3) = puVar2[-0x10];
        *param_3 = *puVar2;
        puVar2 = puVar2 + 1;
        param_3 = param_3 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
    uVar4 = uVar4 + 0x90;
    uVar1 = uVar1 + 1;
    piVar5 = piVar5 + 0x24;
    if (0x11f < uVar4) {
      return uVar1 & 0xffffff00;
    }
  } while( true );
}


// ==== 0x4060a0 FUN_004060a0

void FUN_004060a0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  uint unaff_EBP;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  bool bVar11;
  undefined4 *puStack_3c0;
  uint uStack_3ac;
  undefined1 auStack_3a0 [16];
  undefined4 auStack_390 [83];
  undefined4 local_244;
  int aiStack_240 [144];
  
  piVar8 = (int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)];
  if (piVar8 == (int *)0x0) {
    return;
  }
  puStack_3c0 = &local_244;
  local_244 = 0x244;
  (**(code **)(*piVar8 + 0x3c))(piVar8);
  puVar9 = (undefined4 *)&stack0xfffffc4c;
  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  (**(code **)(*(int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)] + 0xc))
            ((int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)],&stack0xfffffc4c);
  if (unaff_EBP == 0) goto LAB_00406243;
  auStack_390[0] = 0x13c;
  iVar7 = (**(code **)(*(int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)] + 0x38))
                    ((int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)],auStack_390,0x14,1);
  iVar2 = (**(code **)(*(int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)] + 0x38))
                    ((int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)],auStack_3a0,4,1);
  iVar3 = (**(code **)(*(int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)] + 0x38))
                    ((int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)],&stack0xfffffc50,8,1);
  iVar4 = (**(code **)(*(int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)] + 0x38))
                    ((int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)],&puStack_3c0,0x18,1);
  *(undefined4 *)(param_1 + 0x244) = 0;
  *(undefined4 *)(param_1 + 0x254) = 1;
  *(undefined1 *)(param_1 + 0x264) = 1;
  if (((&DAT_0071d89c)[*(int *)(param_1 + 0x130)] == 0) ||
     ((&DAT_0071d888)[*(int *)(param_1 + 0x130)] == '\0')) {
    iVar7 = 4;
    if (unaff_EBP < 4) {
      *(undefined4 *)(param_1 + 0x250) = 4;
    }
    else {
      bVar11 = true;
      piVar8 = &DAT_00700fe8;
      piVar10 = aiStack_240;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *piVar8 == *piVar10;
        piVar8 = piVar8 + 1;
        piVar10 = piVar10 + 1;
      } while (bVar11);
      *(uint *)(param_1 + 0x250) = (!bVar11 - 1 & 0xfffffff4) + 0x14;
    }
  }
  else if (iVar4 == 0) {
    if ((iVar2 != 0) || (iVar3 == 0)) goto LAB_00406243;
    *(undefined4 *)(param_1 + 0x250) = 0x18;
  }
  else {
    if (((iVar2 != 0) || (iVar7 == 0)) || (iVar3 == 0)) goto LAB_00406243;
    *(undefined4 *)(param_1 + 0x250) = 4;
  }
  *(undefined4 *)(param_1 + 0x260) = 1;
  *(undefined1 *)(param_1 + 0x267) = 1;
  *(undefined1 *)(param_1 + 0x268) = 1;
LAB_00406243:
  puVar9 = (undefined4 *)(param_1 + 0x98);
  iVar7 = 0x10;
  puVar5 = puVar9;
  do {
    puVar5[-0x20] = 0;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar5 = (undefined4 *)(param_1 + 0x18);
  cVar1 = FUN_00406020(puVar5,puVar9);
  if (cVar1 == '\0') {
    if (uStack_3ac < 6) {
      *puVar5 = 6;
      *(undefined4 *)(param_1 + 0x1c) = 5;
      *(undefined4 *)(param_1 + 0x20) = 8;
      *(undefined4 *)(param_1 + 0x24) = 7;
      *(undefined4 *)(param_1 + 0x28) = 9;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 1;
      *puVar5 = 2;
      if (uStack_3ac < 8) {
        *(undefined4 *)(param_1 + 0x20) = 6;
        *(undefined4 *)(param_1 + 0x24) = 5;
        *(undefined4 *)(param_1 + 0x28) = 8;
        *(undefined4 *)(param_1 + 0x2c) = 7;
        *(undefined4 *)(param_1 + 0x30) = 9;
      }
      else {
        *(undefined4 *)(param_1 + 0x20) = 9;
        *(undefined4 *)(param_1 + 0x24) = 10;
        *(undefined4 *)(param_1 + 0x28) = 6;
        *(undefined4 *)(param_1 + 0x2c) = 5;
        *(undefined4 *)(param_1 + 0x30) = 8;
        *(undefined4 *)(param_1 + 0x34) = 7;
        *(undefined4 *)(param_1 + 0x38) = 0xe;
        *(undefined4 *)(param_1 + 0x3c) = 0xc;
      }
    }
    *puVar9 = 0x14;
    *(undefined4 *)(param_1 + 0x9c) = 0x17;
    *(undefined4 *)(param_1 + 0xa0) = 0x18;
    *(undefined4 *)(param_1 + 0xa4) = 0x19;
    *(undefined4 *)(param_1 + 0xa8) = 0x1a;
  }
  puVar6 = (uint *)(param_1 + 0x5c);
  iVar7 = 4;
  do {
    puVar6[-1] = -(uint)(uStack_3ac < 6) & 2;
    *puVar6 = (uint)(uStack_3ac < 6);
    puVar6[1] = 3;
    puVar6[2] = 4;
    puVar6[0x1f] = 0x11;
    puVar6[0x20] = 0x10;
    puVar6[0x21] = 0x12;
    puVar6[0x22] = 0x13;
    puVar6 = puVar6 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return;
}


// ==== 0x4063a0 Input::AssignWheelToSlot

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void Input__AssignWheelToSlot(void)

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
    puVar3 = (undefined4 *)InputDevice__GetInstanceGuid();
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


// ==== 0x4064d0 FUN_004064d0

void FUN_004064d0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x134) != 0x13) {
    puVar1 = (undefined4 *)InputDevice__GetInstanceGuid();
    FUN_0041cda0(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    *(undefined4 *)(unaff_EDI + 0x98) = 0x14;
    *(undefined4 *)(unaff_EDI + 0x9c) = 0x17;
    *(undefined4 *)(unaff_EDI + 0xa0) = 0x18;
    *(undefined4 *)(unaff_EDI + 0xa4) = 0x19;
    *(undefined4 *)(unaff_EDI + 0xa8) = 0x1a;
    puVar1 = (undefined4 *)(unaff_EDI + 0xdc);
    iVar2 = 4;
    do {
      puVar1[-1] = 0x11;
      *puVar1 = 0x10;
      puVar1[1] = 0x12;
      puVar1[2] = 0x13;
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x406580 InputDevice::ReadState

/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

void InputDevice__ReadState(void)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (*(int *)(in_EAX + 0x23c) == 0) {
    InputDevice__ReadButtonsAndAxes();
  }
  else if (*(int *)(in_EAX + 0x134) == 0x13) {
    InputKeyboard__PollRebindCapture(in_EAX);
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


// ==== 0x406680 FUN_00406680

void __fastcall FUN_00406680(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  int *piVar3;
  
  piVar1 = (int *)(in_EAX + 0x244);
  iVar2 = 0;
  piVar3 = piVar1;
  do {
    if (unaff_ESI == *piVar3) {
      *(undefined1 *)(iVar2 + 0x264 + in_EAX) = 0;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 4);
  switch(*(undefined4 *)(in_EAX + 0x23c)) {
  case 1:
    *(int *)(in_EAX + 0x248) = unaff_ESI;
    *(int *)(in_EAX + 600) = param_1;
    if ((*(int *)(in_EAX + 0x24c) == unaff_ESI) && (*(int *)(in_EAX + 0x25c) != param_1)) {
      *(int *)(in_EAX + 0x260) = -param_1;
      *(undefined4 *)(in_EAX + 0x23c) = 0;
      DAT_00736508 = 0;
      *(int *)(in_EAX + 0x250) = unaff_ESI;
      *(undefined1 *)(in_EAX + 0x267) = 1;
      *(undefined1 *)(in_EAX + 0x268) = 1;
      return;
    }
    *(undefined1 *)(in_EAX + 0x265) = 1;
    break;
  case 2:
    *(int *)(in_EAX + 0x24c) = unaff_ESI;
    *(int *)(in_EAX + 0x25c) = param_1;
    if ((unaff_ESI == *(int *)(in_EAX + 0x248)) && (param_1 != *(int *)(in_EAX + 600))) {
      *(int *)(in_EAX + 0x260) = param_1;
      *(undefined4 *)(in_EAX + 0x23c) = 0;
      DAT_00736508 = 0;
      *(int *)(in_EAX + 0x250) = unaff_ESI;
      *(undefined1 *)(in_EAX + 0x267) = 1;
      *(undefined1 *)(in_EAX + 0x268) = 1;
      return;
    }
    *(undefined1 *)(in_EAX + 0x266) = 1;
    break;
  case 3:
    *piVar1 = unaff_ESI;
    *(undefined4 *)(in_EAX + 0x23c) = 0;
    DAT_00736508 = 0;
    *(int *)(in_EAX + 0x254) = -param_1;
    *(undefined1 *)(in_EAX + 0x264) = 1;
    return;
  case 4:
    *piVar1 = unaff_ESI;
    *(undefined4 *)(in_EAX + 0x23c) = 0;
    DAT_00736508 = 0;
    *(int *)(in_EAX + 0x254) = param_1;
    *(undefined1 *)(in_EAX + 0x264) = 1;
    return;
  default:
    goto switchD_004066b4_default;
  }
  *(undefined1 *)(in_EAX + 0x268) = 0;
switchD_004066b4_default:
  *(undefined4 *)(in_EAX + 0x23c) = 0;
  DAT_00736508 = 0;
  return;
}


// ==== 0x4067d0 FUN_004067d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004067d0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = DAT_00736500;
  iVar1 = 0;
  iVar2 = *(int *)(unaff_EDI + 0x130) * 0x110;
  while (((*(byte *)(iVar2 + DAT_00736500 + 0x2254 + iVar1) & 0x80) != 0 ||
         (((&DAT_0071d8d8)[iVar1 + iVar2] & 0x80) == 0))) {
    iVar1 = iVar1 + 1;
    if (0xf < iVar1) {
LAB_00406812:
      iVar1 = 0;
      do {
        if (*(short *)(iVar3 + 0x20 + (*(int *)(unaff_EDI + 0x130) * 0x44 + iVar1) * 4) != -1) {
          FUN_00406c40(iVar1);
          iVar3 = DAT_00736500;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 4);
      iVar1 = *(int *)(unaff_EDI + 0x23c);
      if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) || (iVar1 == 4)) {
        iVar1 = 1000;
        if (*(int *)(unaff_EDI + 0x134) == 0x16) {
          iVar1 = 500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + iVar3) - _DAT_00719a28;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0xc + iVar3) - DAT_00719a34;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 4 + iVar3) - DAT_00719a2c;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x10 + iVar3) - _DAT_00719a38;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 8 + iVar3) - DAT_00719a30;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x14 + iVar3) - DAT_00719a3c;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x18 + iVar3) - _DAT_00719a40;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        iVar2 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x1c + iVar3) - DAT_00719a44;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar1 < iVar2) {
          FUN_00406680();
          iVar3 = DAT_00736500;
        }
        _DAT_00719a28 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + iVar3);
        DAT_00719a34 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0xc + iVar3);
        DAT_00719a2c = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 4 + iVar3);
        _DAT_00719a38 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x10 + iVar3);
        DAT_00719a30 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 8 + iVar3);
        DAT_00719a3c = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x14 + iVar3);
        _DAT_00719a40 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x18 + iVar3);
        DAT_00719a44 = *(int *)(*(int *)(unaff_EDI + 0x130) * 0x110 + 0x1c + iVar3);
      }
      return;
    }
  }
  FUN_00406e10(iVar1);
  goto LAB_00406812;
}


// ==== 0x406b10 InputKeyboard::PollRebindCapture

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputKeyboard__PollRebindCapture(int param_1)

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
          InputKeyboard__ApplyRebind(param_1,uStack_288);
          return;
        }
        *(undefined4 *)(param_1 + 0x23c) = 0;
        DAT_00736508 = 0;
        InputDevice__SetActionMap(0);
        InputDevice__SetActionMap(1);
      }
    }
  }
  return;
}


// ==== 0x406c40 FUN_00406c40

void FUN_00406c40(int param_1)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int unaff_ESI;
  int iVar4;
  
  bVar2 = true;
  if ((*(char *)(unaff_ESI + 0x264) != '\0') &&
     ((*(int *)(unaff_ESI + 0x23c) == 3 || (*(int *)(unaff_ESI + 0x23c) == 4)))) {
    bVar2 = false;
  }
  if (((*(char *)(unaff_ESI + 0x265) != '\0') && (*(char *)(unaff_ESI + 0x268) == '\0')) &&
     (*(int *)(unaff_ESI + 0x23c) == 1)) {
    bVar2 = false;
  }
  if (((*(char *)(unaff_ESI + 0x266) != '\0') && (*(char *)(unaff_ESI + 0x268) == '\0')) &&
     (*(int *)(unaff_ESI + 0x23c) == 2)) {
    bVar2 = false;
  }
  if (((*(char *)(unaff_ESI + 0x267) != '\0') && (*(char *)(unaff_ESI + 0x268) != '\0')) &&
     ((*(int *)(unaff_ESI + 0x23c) == 2 || (*(int *)(unaff_ESI + 0x23c) == 1)))) {
    bVar2 = false;
  }
  piVar3 = (int *)(unaff_ESI + 0x18);
  iVar4 = 0x20;
  do {
    iVar1 = *(int *)(unaff_ESI + 0x23c);
    if (*piVar3 == iVar1) {
      if (((((*(int *)(unaff_ESI + 0x240) == 1) && (bVar2)) && (iVar1 != 4)) &&
          ((iVar1 != 3 && (iVar1 != 1)))) && (iVar1 != 2)) {
        bVar2 = false;
      }
      else {
        *piVar3 = 0;
      }
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = FUN_00406d50(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x58 + (iVar4 + param_1 * 4) * 4) = *(undefined4 *)(unaff_ESI + 0x23c)
  ;
  *(undefined4 *)(unaff_ESI + 0x23c) = 0;
  DAT_00736508 = 0;
  return;
}


// ==== 0x406d50 FUN_00406d50

undefined4 FUN_00406d50(void)

{
  float fVar1;
  int in_EAX;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float)in_EAX;
  if (in_EAX < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  _ftol_nocw(fVar1 * 0.01 * 3.1415927 * 0.0055555557 * 10430.378);
  fVar2 = (float10)FUN_00564b10();
  _ftol_nocw();
  fVar3 = (float10)FUN_00564b10();
  if (ABS(fVar3) < ABS((float10)(float)fVar2)) {
    if (0.0 < (float)fVar2) {
      return 1;
    }
    return 0;
  }
  if ((float10)0.0 < fVar3) {
    return 3;
  }
  return 2;
}


// ==== 0x406e10 FUN_00406e10

void FUN_00406e10(int param_1)

{
  int iVar1;
  bool bVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  
  bVar2 = true;
  if ((*(char *)(in_EAX + 0x264) != '\0') &&
     ((*(int *)(in_EAX + 0x23c) == 3 || (*(int *)(in_EAX + 0x23c) == 4)))) {
    bVar2 = false;
  }
  if (((*(char *)(in_EAX + 0x265) != '\0') && (*(char *)(in_EAX + 0x268) == '\0')) &&
     (*(int *)(in_EAX + 0x23c) == 1)) {
    bVar2 = false;
  }
  if (((*(char *)(in_EAX + 0x266) != '\0') && (*(char *)(in_EAX + 0x268) == '\0')) &&
     (*(int *)(in_EAX + 0x23c) == 2)) {
    bVar2 = false;
  }
  if (((*(char *)(in_EAX + 0x267) != '\0') && (*(char *)(in_EAX + 0x268) != '\0')) &&
     ((*(int *)(in_EAX + 0x23c) == 2 || (*(int *)(in_EAX + 0x23c) == 1)))) {
    bVar2 = false;
  }
  piVar3 = (int *)(in_EAX + 0x18);
  iVar4 = 0x20;
  do {
    iVar1 = *(int *)(in_EAX + 0x23c);
    if (*piVar3 == iVar1) {
      if (((((*(int *)(in_EAX + 0x240) == 1) && (bVar2)) && (iVar1 != 4)) &&
          ((iVar1 != 3 && (iVar1 != 1)))) && (iVar1 != 2)) {
        bVar2 = false;
      }
      else {
        *piVar3 = 0;
      }
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(in_EAX + 0x18 + param_1 * 4) = *(undefined4 *)(in_EAX + 0x23c);
  *(undefined4 *)(in_EAX + 0x23c) = 0;
  DAT_00736508 = 0;
  return;
}


// ==== 0x406f00 InputKeyboard::ApplyRebind

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputKeyboard__ApplyRebind(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8 [2];
  
  iVar4 = 0;
  iVar2 = 0;
  iVar3 = 0;
  local_8[0] = 0;
  local_8[1] = 0;
  if (DAT_007197a4 != 0) {
    piVar1 = &DAT_007187f0;
    local_c = DAT_007197a4;
    do {
      if (*piVar1 == param_2) {
        piVar1[-4] = 0;
        piVar1[-3] = 0;
        piVar1[-2] = 0;
        piVar1[-1] = 0;
        *piVar1 = 0;
        piVar1[1] = 0;
      }
      if ((piVar1[-8] == *(int *)(param_1 + 0x23c)) && (iVar3 < 2)) {
        local_8[iVar3] = (int)(piVar1 + -8);
        iVar3 = iVar3 + 1;
        iVar2 = local_8[1];
        iVar4 = local_8[0];
      }
      piVar1 = piVar1 + 10;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  if (*(int *)(param_1 + 0x240) == 1) {
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x24) = 0x20;
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x11c);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x120);
      *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0x124);
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x128);
      *(int *)(iVar2 + 0x20) = param_2;
    }
  }
  else {
    if (iVar4 == 0) goto LAB_00407073;
    *(undefined4 *)(iVar4 + 0x24) = 0x20;
    *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(param_1 + 0x11c);
    *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(param_1 + 0x120);
    *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(param_1 + 0x124);
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(param_1 + 0x128);
    *(int *)(iVar4 + 0x20) = param_2;
  }
  if ((iVar4 != 0) && (iVar2 != 0)) {
    if (*(int *)(iVar4 + 0x20) == 0) {
      *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
      *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
      *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
      *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
    }
    if (*(int *)(iVar4 + 0x20) == *(int *)(iVar2 + 0x20)) {
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 0;
    }
  }
LAB_00407073:
  *(undefined4 *)(param_1 + 0x23c) = 0;
  DAT_00736508 = 0;
  InputDevice__SetActionMap(0);
  InputDevice__SetActionMap(1);
  return;
}


// ==== 0x4070a0 InputDevice::ReadButtonsAndAxes

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void InputDevice__ReadButtonsAndAxes(void)

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
        _ftol_nocw();
        fVar9 = (float10)FUN_00564b10();
        local_144[0] = (float)fVar9;
        _ftol_nocw();
        fVar9 = (float10)FUN_00564b10();
        fVar1 = (float)fVar9;
        if (local_144[0] < -0.1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (0.1 < local_144[0]) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (fVar1 < -0.1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (0.1 < fVar1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (local_144[0] < -0.1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (0.1 < local_144[0]) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (fVar1 < -0.1) {
          uVar10 = __allshl();
          *(uint *)(unaff_ESI + 8) = *(uint *)(unaff_ESI + 8) & -(int)uVar10 - 1U;
          *(uint *)(unaff_ESI + 0xc) =
               *(uint *)(unaff_ESI + 0xc) & -(int)((ulonglong)uVar10 >> 0x20) - 1U;
        }
        if (0.1 < fVar1) {
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
      cVar2 = _ftol_nocw();
      cVar2 = -0x80 - cVar2 * *(char *)(unaff_ESI + 0x254);
    }
    *(char *)(unaff_ESI + 0x12) = cVar2;
    if ((*(char *)(unaff_ESI + 0x268) != '\0') && (*(char *)(unaff_ESI + 0x267) != '\0')) {
      cVar2 = _ftol_nocw();
      *(char *)(unaff_ESI + 0x13) = '\x7f' - cVar2 * *(char *)(unaff_ESI + 0x260);
      *(undefined1 *)(unaff_ESI + 0x11) = 0;
      *(undefined1 *)(unaff_ESI + 0x10) = 0;
      return;
    }
    cVar2 = '\0';
    if (*(char *)(unaff_ESI + 0x266) != '\0') {
      cVar2 = _ftol_nocw();
      cVar2 = '\x7f' - cVar2 * *(char *)(unaff_ESI + 0x25c);
    }
    cVar3 = '\0';
    if (*(char *)(unaff_ESI + 0x265) != '\0') {
      cVar3 = _ftol_nocw();
      cVar3 = '\x7f' - cVar3 * *(char *)(unaff_ESI + 600);
    }
    *(char *)(unaff_ESI + 0x11) = cVar2;
    *(char *)(unaff_ESI + 0x10) = cVar3;
    *(undefined1 *)(unaff_ESI + 0x13) = 0x80;
  }
  return;
}


// ==== 0x4075e0 Input::InitActionFormats

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void Input__InitActionFormats(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  DAT_00719b4c = 0x5a589134;
  DAT_00719b50 = 0x30914687;
  DAT_00719b38 = 0x148;
  DAT_00719c80 = 0x148;
  DAT_00719b58 = 0x6d21c8c2;
  DAT_00719b3c = 0x28;
  DAT_00719c84 = 0x28;
  _DAT_00719b44 = 0x28;
  DAT_00719ca0 = 0x6d22c8c2;
  DAT_00719c94 = 0x5a589134;
  DAT_00719b5c = 0x1000000;
  DAT_00719ca4 = 0x1000000;
  DAT_00719b54 = 0x9d68236f;
  DAT_00719c98 = 0x30914687;
  DAT_00719b60 = 0x10;
  DAT_00719ca8 = 0x10;
  DAT_00719c9c = 0x9d68236f;
  _DAT_00719b40 = 0xa0;
  _DAT_00719c88 = 0x90;
  _DAT_00719c8c = 0x24;
  _DAT_00719b48 = &DAT_00702c98;
  _DAT_00719c90 = &DAT_007032d8;
  DAT_00719b64 = 0;
  DAT_00719b68 = 0xff;
  pcVar2 = "NFS Underground Game";
  pcVar3 = (char *)&DAT_00719b7c;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  *pcVar3 = *pcVar2;
  _DAT_00719cac = 0;
  _DAT_00719cb0 = 0xff;
  pcVar2 = "NFS Underground Menu";
  pcVar3 = (char *)&DAT_00719cc4;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  *pcVar3 = *pcVar2;
  return;
}


// ==== 0x407760 InputDevice::SetActionMap

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void __thiscall InputDevice__SetActionMap(int param_1,undefined4 param_2)

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
        InputDevice__ReadState();
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


// ==== 0x407800 InputWheel::GetBindingName

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

undefined * InputWheel__GetBindingName(int param_1,int param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  
  puVar7 = &DAT_0078ece8;
  for (iVar4 = 0x4f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  DAT_0078ece8 = 0x13c;
  iVar4 = -1;
  bVar2 = true;
  if ((*(char *)(param_1 + 0x264) != '\0') && ((param_2 == 3 || (param_2 == 4)))) {
    if (param_3 == 0) {
      iVar4 = 0;
    }
    else {
      bVar2 = false;
    }
  }
  iVar8 = iVar4;
  if ((((*(char *)(param_1 + 0x265) != '\0') && (*(char *)(param_1 + 0x268) == '\0')) &&
      (param_2 == 1)) && (iVar8 = param_2, param_3 != 0)) {
    bVar2 = false;
    iVar8 = iVar4;
  }
  iVar4 = iVar8;
  if (((*(char *)(param_1 + 0x266) != '\0') && (*(char *)(param_1 + 0x268) == '\0')) &&
     ((param_2 == 2 && (iVar4 = param_2, param_3 != 0)))) {
    bVar2 = false;
    iVar4 = iVar8;
  }
  if (((*(char *)(param_1 + 0x267) == '\0') || (*(char *)(param_1 + 0x268) == '\0')) ||
     ((param_2 != 2 && (param_2 != 1)))) {
LAB_004078d7:
    if (iVar4 < 0) goto LAB_00407912;
  }
  else {
    if (param_3 != 0) {
      bVar2 = false;
      goto LAB_004078d7;
    }
    iVar4 = 3;
  }
  piVar5 = (int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)];
  if ((piVar5 != (int *)0x0) &&
     (iVar4 = (**(code **)(*piVar5 + 0x38))
                        (piVar5,&DAT_0078ece8,*(undefined4 *)(param_1 + 0x244 + iVar4 * 4),1),
     -1 < iVar4)) {
    return &DAT_0078ed08;
  }
LAB_00407912:
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x18);
  do {
    if (*piVar5 == param_2) {
      if ((param_3 == 1) && (bVar2)) {
        bVar2 = false;
      }
      else {
        piVar6 = (int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)];
        if ((piVar6 != (int *)0x0) &&
           (iVar8 = (**(code **)(*piVar6 + 0x38))(piVar6,&DAT_0078ece8,iVar4 + 0x30,1), -1 < iVar8))
        {
LAB_00407993:
          return &DAT_0078ed08;
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
    if (0xf < iVar4) {
      iVar4 = 0x20;
      piVar5 = (int *)(param_1 + 0x58);
      do {
        iVar8 = 0;
        piVar6 = piVar5;
        do {
          if (*piVar6 == param_2) {
            if ((param_3 == 1) && (bVar2)) {
              bVar2 = false;
            }
            else {
              piVar1 = (int *)(&DAT_0071d89c)[*(int *)(param_1 + 0x130)];
              if ((piVar1 != (int *)0x0) &&
                 (iVar3 = (**(code **)(*piVar1 + 0x38))(piVar1,&DAT_0078ece8,iVar4,1), -1 < iVar3))
              goto LAB_00407993;
            }
          }
          iVar8 = iVar8 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar8 < 4);
        iVar4 = iVar4 + 4;
        piVar5 = piVar5 + 4;
        if (0x2f < iVar4) {
          return &DAT_006b9172;
        }
      } while( true );
    }
  } while( true );
}


// ==== 0x4079f0 InputKeyboard::GetBindingName

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

undefined1 * InputKeyboard__GetBindingName(undefined4 param_1,int param_2,int param_3)

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


// ==== 0x407ab0 FUN_00407ab0

undefined4 FUN_00407ab0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puStack_38;
  undefined4 local_18 [6];
  
  puVar2 = local_18;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_18[0] = 0x18;
  puStack_38 = local_18;
  local_18[2] = *(undefined4 *)(param_1 + 0x18);
  local_18[1] = 0x10;
  local_18[3] = 2;
  local_18[4] = 0xffffff9c;
  local_18[5] = 100;
  (**(code **)(*param_2 + 0x18))(param_2,4);
  (**(code **)(*param_2 + 0x18))(param_2,2,&puStack_38);
  return 1;
}


// ==== 0x407b40 FUN_00407b40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407b40(void)

{
  int in_EAX;
  int *piStack_20;
  undefined *puStack_1c;
  int *piStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  DAT_00736508 = 1;
  if (*(int *)(in_EAX + 0x134) == 0x13) {
    if (DAT_007187c8 != (int *)0x0) {
      piStack_18 = DAT_007187c8;
      puStack_1c = (undefined *)0x407b6c;
      (**(code **)(*DAT_007187c8 + 0x20))();
      puStack_1c = &DAT_006a6fa0;
      piStack_20 = DAT_007187c8;
      (**(code **)(*DAT_007187c8 + 0x2c))();
      piStack_18 = (int *)0x0;
      puStack_1c = (undefined *)0x10;
      uStack_10 = 0x10;
      piStack_20 = (int *)0x14;
      uStack_14 = 0;
      (**(code **)(*DAT_007187c8 + 0x18))(DAT_007187c8,1,&piStack_20);
      (**(code **)(*DAT_007187c8 + 0x10))(DAT_007187c8,FUN_00407ab0,DAT_007187c8,3);
      (**(code **)(*DAT_007187c8 + 0x1c))(DAT_007187c8);
      return;
    }
  }
  else {
    _DAT_00719a28 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + DAT_00736500);
    DAT_00719a34 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 0xc + DAT_00736500);
    DAT_00719a2c = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 4 + DAT_00736500);
    _DAT_00719a38 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 0x10 + DAT_00736500);
    DAT_00719a30 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 8 + DAT_00736500);
    DAT_00719a3c = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 0x14 + DAT_00736500);
    _DAT_00719a40 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 0x18 + DAT_00736500);
    DAT_00719a44 = *(undefined4 *)(*(int *)(in_EAX + 0x130) * 0x110 + 0x1c + DAT_00736500);
  }
  return;
}


// ==== 0x407ca0 InputKeyboard::CopyDefaultActionTables

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputKeyboard__CopyDefaultActionTables(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = &DAT_00702c98;
  puVar5 = &DAT_007187d0;
  for (iVar2 = 400; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar6 = &DAT_007032d8;
  puVar5 = &DAT_00718fa0;
  for (iVar2 = 0x168; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  _DAT_007197a0 = 0xa0;
  DAT_007197a4 = 0x28;
  _DAT_007198e8 = 0x90;
  _DAT_007198ec = 0x24;
  puVar6 = &DAT_007187d0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_0071979c + iVar2) = *(undefined4 *)((int)&DAT_00719b3c + iVar2);
    *(undefined4 *)((int)&DAT_00719798 + iVar2) = *(undefined4 *)((int)&DAT_00719b38 + iVar2);
    *(undefined4 *)((int)&DAT_007197ac + iVar2) = *(undefined4 *)((int)&DAT_00719b4c + iVar2);
    *(undefined4 *)((int)&DAT_007197b0 + iVar2) = *(undefined4 *)((int)&DAT_00719b50 + iVar2);
    *(undefined4 *)((int)&DAT_007197b4 + iVar2) = *(undefined4 *)((int)&DAT_00719b54 + iVar2);
    *(undefined4 *)((int)&DAT_007197b8 + iVar2) = *(undefined4 *)((int)&DAT_00719b58 + iVar2);
    *(undefined4 *)((int)&DAT_007197bc + iVar2) = *(undefined4 *)((int)&DAT_00719b5c + iVar2);
    *(undefined4 *)((int)&DAT_007197c0 + iVar2) = *(undefined4 *)((int)&DAT_00719b60 + iVar2);
    *(undefined4 *)((int)&DAT_007197c4 + iVar2) = *(undefined4 *)((int)&DAT_00719b64 + iVar2);
    *(undefined4 *)((int)&DAT_007197c8 + iVar2) = *(undefined4 *)((int)&DAT_00719b68 + iVar2);
    pcVar3 = (char *)((int)&DAT_00719b7c + iVar2);
    iVar4 = iVar2 - (int)pcVar3;
    *(undefined4 **)((int)&DAT_007197a8 + iVar2) = puVar6;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(&DAT_007197dc + iVar4)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puVar6 = puVar6 + 500;
    iVar2 = iVar2 + 0x148;
  } while ((int)puVar6 < 0x719770);
  return;
}


// ==== 0x407da0 FUN_00407da0

void FUN_00407da0(void)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  piVar2 = (int *)in_EAX[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}


// ==== 0x407db0 Texture::CreateD3D

/* [canon] assets high (Ghidra FUN_00407db0 + capstone) docs/re/assets.md */

void Texture__CreateD3D(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  int unaff_ESI;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *_Memory;
  int local_20;
  
  piVar6 = (int *)*in_EAX;
  piVar1 = piVar6 + 6;
  if (piVar6[6] != 0) {
    Texture__ReleaseD3D();
  }
  pbVar7 = (byte *)in_EAX[0x1c];
  if (((pbVar7 != (byte *)0x0) &&
      (iVar5 = piVar6[5],
      ((int)*(short *)(in_EAX + 0x11) & (int)*(short *)(in_EAX + 0x11) - 1U) == 0)) &&
     (((int)*(short *)((int)in_EAX + 0x46) & (int)*(short *)((int)in_EAX + 0x46) - 1U) == 0)) {
    if (iVar5 == 0x29) {
      iVar5 = in_EAX[0x1d];
      puVar2 = _malloc(in_EAX[0xe] << 2);
      local_20 = 0;
      if ('\0' < *(char *)((int)in_EAX + 0x4e)) {
        do {
          iVar3 = ((int)*(short *)((int)in_EAX + 0x46) >> ((byte)local_20 & 0x1f)) *
                  ((int)*(short *)(in_EAX + 0x11) >> ((byte)local_20 & 0x1f));
          if (0 < iVar3) {
            do {
              *puVar2 = *(undefined4 *)(iVar5 + (uint)*pbVar7 * 4);
              puVar2 = puVar2 + 1;
              pbVar7 = pbVar7 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          local_20 = local_20 + 1;
        } while (local_20 < *(char *)((int)in_EAX + 0x4e));
      }
      iVar5 = 0x15;
      *(undefined1 *)((int)in_EAX + 0x4a) = 0x20;
    }
    if ((DAT_007364f4 == 0) || (*(char *)((int)in_EAX + 0x4e) <= DAT_007364f4)) {
      _Memory = (undefined4 *)0x0;
      puVar15 = (undefined4 *)0x1;
      iVar13 = 0;
      iVar3 = (int)*(short *)((int)in_EAX + 0x46);
      puVar2 = (undefined4 *)(int)*(short *)(in_EAX + 0x11);
      (**(code **)(*DAT_0073636c + 0x5c))
                (DAT_0073636c,puVar2,iVar3,(int)*(char *)((int)in_EAX + 0x4e),0,iVar5,1,piVar1);
    }
    else {
      _Memory = (undefined4 *)0x0;
      puVar15 = (undefined4 *)0x1;
      iVar13 = 0;
      iVar3 = (int)*(short *)((int)in_EAX + 0x46) / (DAT_007364f4 * 2);
      puVar2 = (undefined4 *)((int)*(short *)(in_EAX + 0x11) / (DAT_007364f4 * 2));
      piVar6 = piVar1;
      (**(code **)(*DAT_0073636c + 0x5c))
                (DAT_0073636c,puVar2,iVar3,*(char *)((int)in_EAX + 0x4e) - DAT_007364f4,0,iVar5);
    }
    if (*piVar1 != 0) {
      *DAT_0078daa4 = (int)piVar6;
      piVar1 = piVar6;
      piVar6[1] = (int)DAT_0078daa4;
      DAT_0078daa4 = piVar1;
      iVar5 = DAT_007364f4;
      bVar12 = DAT_007364f4 != 0;
      *piVar6 = (int)&DAT_0078daa0;
      iVar9 = (int)*(char *)((int)in_EAX + 0x4e);
      puVar10 = _Memory;
      if (((bVar12) && (iVar5 < iVar9)) && (0 < iVar5)) {
        iVar9 = iVar9 - iVar5;
        do {
          puVar10 = (undefined4 *)((int)puVar10 + iVar13);
          iVar13 = (int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = 0;
      if (0 < iVar9) {
        puVar16 = (undefined4 *)0x0;
        do {
          iVar13 = 0;
          puVar14 = puVar10;
          (**(code **)(*(int *)*puVar15 + 0x4c))((int *)*puVar15,iVar5,&stack0xffffffd4,0);
          uVar8 = iVar13 >> ((byte)iVar3 & 0x1f);
          puVar11 = puVar16;
          for (uVar4 = uVar8 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar8 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          (**(code **)(*(int *)*puVar2 + 0x50))((int *)*puVar2,iVar5);
          puVar10 = (undefined4 *)((int)puVar14 + uVar8);
          iVar5 = iVar5 + 1;
          puVar16 = (undefined4 *)((int)puVar16 + 2);
        } while (iVar5 < iVar9);
      }
      if (unaff_ESI != 0) {
        _free(_Memory);
      }
    }
  }
  return;
}


// ==== 0x408010 Texture::ReleaseD3D

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Ghidra FUN_00408010) docs/re/assets.md */

void __fastcall Texture__ReleaseD3D(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  param_1 = (int *)*param_1;
  if (DAT_00736550 != 0) {
    QueryPerformanceCounter(&local_8);
    uVar2 = DAT_007349c8;
    iVar3 = __allshr();
    local_10.s.LowPart = iVar3 - _DAT_007364fc;
    if ((int)local_10.s.LowPart < 0) {
      local_10.s.LowPart = 0;
    }
    local_8.s.LowPart =
         (DWORD)((float)(1 << ((byte)uVar2 & 0x1f)) * (float)(int)local_10.s.LowPart * _DAT_007301d0
                * 0.001);
    QueryPerformanceCounter(&local_10);
    _DAT_007364fc = __allshr();
    _DAT_0078eb94 = _DAT_0078eb94 + (float)local_8.s.LowPart;
    if (0.033 < _DAT_0078eb94) {
      _DAT_0078eb94 = 0.0;
      FUN_004016e0(0);
    }
  }
  piVar1 = (int *)param_1[6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    iVar3 = *param_1;
    param_1[6] = 0;
    piVar1 = (int *)param_1[1];
    *piVar1 = iVar3;
    *(int **)(iVar3 + 4) = piVar1;
  }
  return;
}


// ==== 0x408100 RefList_ReleaseAll

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void RefList_ReleaseAll(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if ((int **)DAT_0078daa0 != &DAT_0078daa0) {
    do {
      piVar2 = DAT_0078daa0;
      iVar3 = *DAT_0078daa0;
      piVar1 = (int *)DAT_0078daa0[1];
      *piVar1 = iVar3;
      *(int **)(iVar3 + 4) = piVar1;
      piVar1 = (int *)piVar2[6];
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 8))(piVar1);
        while (iVar3 != 0) {
          iVar3 = (**(code **)(*(int *)piVar2[6] + 8))((int *)piVar2[6]);
        }
        piVar2[6] = 0;
      }
    } while ((int **)DAT_0078daa0 != &DAT_0078daa0);
  }
  DAT_0078daa0 = (int *)&DAT_0078daa0;
  DAT_0078daa4 = &DAT_0078daa0;
  return;
}


// ==== 0x408160 Vec3_Scale

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void __thiscall Vec3_Scale(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *in_EAX = param_2 * *param_1;
  in_EAX[1] = fVar1 * param_2;
  in_EAX[2] = fVar2 * param_2;
  return;
}


// ==== 0x408180 Vec3_ScaleTo

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __thiscall Vec3_ScaleTo(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  in_EAX[2] = param_1[2] * param_2;
  *in_EAX = param_2 * fVar1;
  in_EAX[1] = fVar2 * param_2;
  return;
}


// ==== 0x4081c0 FUN_004081c0

undefined4 FUN_004081c0(void)

{
  if ((DAT_0077a920 == 6) && (*DAT_007361f0 != 1)) {
    return 1;
  }
  return 0;
}


// ==== 0x4081e0 FUN_004081e0

undefined4 FUN_004081e0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x1c);
}


// ==== 0x4081f0 FUN_004081f0

int FUN_004081f0(void)

{
  int in_EAX;
  
  return in_EAX + 0x90;
}


// ==== 0x408200 FUN_00408200

undefined4 FUN_00408200(void)

{
  return DAT_007361c4;
}


// ==== 0x408210 GetPlayerObject

/* [canon] rivals med (hopper+capstone) docs/re/misc.md */

undefined4 GetPlayerObject(void)

{
  int in_EAX;
  
  return (&DAT_007361bc)[in_EAX];
}


// ==== 0x408220 VertexDecls_CreateDefault

/* [canon] render med (hopper+ghidra+capstone) docs/re/render.md */

void VertexDecls_CreateDefault(void)

{
  undefined2 *puStack_54;
  undefined *puStack_50;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  puStack_50 = &DAT_0071a058;
  local_24 = 2;
  local_1c = 2;
  puStack_54 = &local_28;
  local_28 = 0;
  local_26 = 0;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = 0;
  local_1e = 0xc;
  local_1b = 0;
  local_1a = 3;
  local_19 = 0;
  local_18 = 0;
  local_16 = 0x18;
  local_14 = 4;
  local_13 = 0;
  local_12 = 10;
  local_11 = 0;
  local_10 = 0;
  local_e = 0x1c;
  local_c = 1;
  local_b = 0;
  local_a = 5;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  (**(code **)(*DAT_0073636c + 0x158))(DAT_0073636c);
  puStack_54 = (undefined2 *)0x0;
  puStack_50 = (undefined *)0x90003;
  (**(code **)(*DAT_0073636c + 0x158))(DAT_0073636c,&puStack_54,&DAT_0071a078);
  return;
}


// ==== 0x408370 FUN_00408370

void FUN_00408370(void)

{
  if ((undefined4 **)DAT_00740504 != &DAT_00740504) {
    if ((((DAT_00740504 != (undefined4 *)0x0) && (DAT_00740504 != (undefined4 *)0x4)) &&
        ((undefined4 **)DAT_00740564 != &DAT_00740564)) &&
       ((DAT_00740564 != (undefined4 *)0x0 && (DAT_00740564 != (undefined4 *)0x4)))) {
      DAT_007364a0 = 3;
      return;
    }
    if ((undefined4 **)DAT_00740504 != &DAT_00740504) {
      if (((DAT_00740504 != (undefined4 *)0x0) && (DAT_00740504 != (undefined4 *)0x4)) &&
         (((undefined4 **)DAT_007405c4 != &DAT_007405c4 &&
          ((DAT_007405c4 != (undefined4 *)0x0 && (DAT_007405c4 != (undefined4 *)0x4)))))) {
        DAT_007364a0 = 2;
        return;
      }
      if ((((undefined4 **)DAT_00740504 != &DAT_00740504) && (DAT_00740504 != (undefined4 *)0x0)) &&
         (DAT_00740504 != (undefined4 *)0x4)) {
        DAT_007364a0 = 1;
        return;
      }
    }
  }
  DAT_007364a0 = 0;
  return;
}


// ==== 0x408410 Views_UpdateViewCountAndEnables

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra-canon) docs/re/render.md */

void Views_UpdateViewCountAndEnables(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  if (DAT_007364a8 == 0) {
    if (DAT_007364a4 != DAT_007364a0) {
      DAT_007364a4 = DAT_007364a0;
    }
  }
  else if (DAT_007364a4 != DAT_007364a8) {
    DAT_007364a4 = DAT_007364a8;
  }
  if (DAT_007364a0 == 1) {
    if (((undefined4 **)DAT_00740504 == &DAT_00740504) || (DAT_00740504 == (undefined4 *)0x0)) {
      _DAT_0071a8c0 = (undefined4 *)0x0;
    }
    else {
      _DAT_0071a8c0 = DAT_00740504 + -1;
    }
    if ((((((undefined4 **)DAT_00740504 != &DAT_00740504) && (DAT_00740504 != (undefined4 *)0x0)) &&
         (DAT_00740504 != (undefined4 *)0x4)) &&
        (((undefined4 **)DAT_007405c4 != &DAT_007405c4 && (DAT_007405c4 != (undefined4 *)0x0)))) &&
       (DAT_007405c4 != (undefined4 *)0x4)) {
      if (DAT_00740504 == (undefined4 *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = DAT_00740504 + -1;
      }
      cVar6 = (**(code **)(*piVar8 + 0x24))();
      if (cVar6 == '\0') {
        DAT_007364a0 = 2;
      }
    }
  }
  else if (DAT_007364a0 == 2) {
    if ((((undefined4 **)DAT_007405c4 != &DAT_007405c4) && (DAT_007405c4 != (undefined4 *)0x0)) &&
       (DAT_007405c4 != (undefined4 *)0x4)) {
      if (((undefined4 **)DAT_00740504 == &DAT_00740504) || (DAT_00740504 == (undefined4 *)0x0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = DAT_00740504 + -1;
      }
      cVar6 = (**(code **)(*piVar8 + 0x24))();
      if (cVar6 == '\0') goto LAB_004084f7;
    }
    DAT_007364a0 = 1;
  }
LAB_004084f7:
  iVar5 = DAT_00740638;
  iVar4 = DAT_007405d8;
  iVar3 = DAT_00740518;
  uVar2 = DAT_00701038;
  if (DAT_007364a4 == 0) {
    *(undefined4 *)(DAT_00740518 + 0x10) = 0;
    DAT_007404c8 = 0;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    DAT_00740588 = 0;
    *(undefined4 *)(iVar5 + 0x10) = 0;
    DAT_007405e8 = 0;
    DAT_00740768 = 0;
  }
  else {
    if (DAT_007364a4 == 1) {
      *(undefined4 *)(DAT_00740518 + 0x14) = DAT_00701034;
      *(undefined4 *)(iVar3 + 0x18) = uVar2;
      *(undefined4 *)(iVar3 + 0x10) = 1;
      DAT_007404c8 = 1;
      *(undefined4 *)(iVar4 + 0x10) = 0;
      DAT_00740588 = 0;
    }
    else {
      if (DAT_007364a4 != 2) goto LAB_004085b8;
      *(undefined4 *)(DAT_00740518 + 0x14) = DAT_00701034;
      *(undefined4 *)(iVar3 + 0x18) = uVar2;
      *(undefined4 *)(iVar3 + 0x10) = 1;
      DAT_007404c8 = 1;
      *(undefined4 *)(iVar4 + 0x10) = 1;
      DAT_00740588 = 1;
    }
    *(undefined4 *)(iVar5 + 0x14) = 0x140;
    *(undefined4 *)(iVar5 + 0x18) = 0xf0;
    *(undefined4 *)(iVar5 + 0x10) = 1;
    DAT_007405e8 = 1;
    DAT_00740768 = 1;
  }
LAB_004085b8:
  puVar1 = DAT_0073d6d8;
  if (((DAT_0077a920 != 6) || (*DAT_007361f0 == 1)) &&
     ((undefined4 **)DAT_0073d6d8 != &DAT_0073d6d8)) {
    puVar7 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar7; puVar1 = (undefined4 *)*puVar1) {
      if ((puVar1[0x267] == 0) && (puVar1[0x1cc] == 1)) {
        DAT_00740768 = puVar1[2] != 0;
      }
    }
  }
  return;
}


// ==== 0x408610 RVM_LookupTextures

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra) docs/re/render.md */

void RVM_LookupTextures(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  
  puVar4 = &DAT_006cc0c8;
  iVar3 = -1;
  uVar2 = 0x52;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  DAT_007364ac = Texture_FindByHash(iVar3,0,0);
  pcVar5 = "RVM_MASK";
  iVar3 = -1;
  uVar2 = 0x52;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  DAT_007364b0 = Texture_FindByHash(iVar3,0,0);
  pcVar5 = "WHITE16X16_NOALPHA";
  iVar3 = -1;
  uVar2 = 0x57;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _gTexWhite16NoAlpha = Texture_FindByHash(iVar3,0,0);
  return;
}


// ==== 0x4086b0 FUN_004086b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004086b0(undefined4 param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0071a96c;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if (DAT_0073637c != 0) {
    GetWindowRect(DAT_00736380,(LPRECT)&DAT_0071b7a0);
    GetClientRect(DAT_00736380,(LPRECT)0x71b208);
  }
  _DAT_0071a98c = DAT_0073637c;
  _DAT_0071a984 = 1;
  _DAT_0071a990 = 1;
  DAT_0071a96c = param_1;
  DAT_00701034 = param_1;
  DAT_0071a970 = unaff_ESI;
  _DAT_0071a974 = DAT_00702a80;
  _DAT_0071a994 = (-(uint)(DAT_007364b8 != 0) & 5) + 0x4b;
  _DAT_0071a988 = DAT_00736380;
  _DAT_0071a980 = 0;
  DAT_00701038 = unaff_ESI;
  return;
}


// ==== 0x408760 FUN_00408760

void FUN_00408760(void)

{
  undefined4 uVar1;
  
  if ((DAT_00700e70 != 1) && (*(int *)(&DAT_0071b7b0 + DAT_00700e70 * 4) != 0)) {
    uVar1 = 800;
    switch(DAT_00700e70) {
    case 0:
      FUN_004086b0(0x280);
      Device_HandleLost();
      return;
    case 1:
      FUN_004086b0(800);
      Device_HandleLost();
      return;
    case 2:
      FUN_004086b0(0x400);
      Device_HandleLost();
      return;
    case 3:
      FUN_004086b0(0x500);
      Device_HandleLost();
      return;
    case 4:
      uVar1 = 0x500;
    }
    FUN_004086b0(uVar1);
    Device_HandleLost();
    return;
  }
  return;
}


// ==== 0x408830 FUN_00408830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00408830(void)

{
  int nHeight;
  undefined4 *puVar1;
  HWND hWndParent;
  int iVar2;
  HMENU hMenu;
  HINSTANCE hInstance;
  LPVOID lpParam;
  undefined1 auStack_44 [16];
  WNDCLASSEXA WStack_34;
  
  DAT_00736368 = (int *)Direct3DCreate9_Thunk(0x1f);
  Display_ProbeResolutions();
  __controlfp(3,0x8001f);
  _DAT_007364e0 = (undefined4 *)FUN_00566dc0(4,"g_textureHeaderPool",0);
  if (_DAT_007364e0 == (undefined4 *)0x0) {
    _DAT_007364e0 = (undefined4 *)0x0;
  }
  else if (DAT_0073d814 == 1) {
    *DAT_0073d81c = _DAT_007364e0;
    puVar1 = _DAT_007364e0;
    _DAT_007364e0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *_DAT_007364e0 = &DAT_0073d818;
  }
  _DAT_007364e0[5] = _DAT_007364e0[5] & 0xfffffffd;
  _DAT_007364e4 = (undefined4 *)FUN_00566dc0(4,"g_vertexBufferHeaderPool",0);
  if (_DAT_007364e4 == (undefined4 *)0x0) {
    _DAT_007364e4 = (undefined4 *)0x0;
  }
  else if (DAT_0073d814 == 1) {
    *DAT_0073d81c = _DAT_007364e4;
    puVar1 = _DAT_007364e4;
    _DAT_007364e4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *_DAT_007364e4 = &DAT_0073d818;
  }
  _DAT_007364e4[5] = _DAT_007364e4[5] & 0xfffffffd;
  WStack_34.cbSize = 0x30;
  WStack_34.style = 0x40;
  WStack_34.lpfnWndProc = FUN_004110d0;
  WStack_34.cbClsExtra = 0;
  WStack_34.cbWndExtra = 0;
  WStack_34.hInstance = GetModuleHandleA((LPCSTR)0x0);
  WStack_34.hIcon = (HICON)0x0;
  WStack_34.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_34.hbrBackground = (HBRUSH)0x0;
  WStack_34.lpszMenuName = (LPCSTR)0x0;
  WStack_34.lpszClassName = "GameFrame";
  WStack_34.hIconSm = (HICON)0x0;
  RegisterClassExA(&WStack_34);
  nHeight = DAT_00701038;
  iVar2 = DAT_00701034;
  AdjustWindowRect((LPRECT)&stack0xffffffac,0x90080000,0);
  lpParam = (LPVOID)0x0;
  hMenu = (HMENU)0x0;
  hInstance = WStack_34.hInstance;
  hWndParent = GetDesktopWindow();
  DAT_00736380 = CreateWindowExA(0,"GameFrame","NFS Underground",0x90080000,100,100,iVar2,nHeight,
                                 hWndParent,hMenu,hInstance,lpParam);
  UpdateWindow(DAT_00736380);
  SetCursor((HCURSOR)0x0);
  ShowCursor(0);
  SetFocus(DAT_00736380);
  SetForegroundWindow(DAT_00736380);
  GetWindowRect(DAT_00736380,(LPRECT)&DAT_0071b7a0);
  GetClientRect(DAT_00736380,(LPRECT)0x71b208);
  (**(code **)(*DAT_00736368 + 0x20))(DAT_00736368,DAT_00736398,auStack_44);
  DAT_00702a80 = 0x15;
  FUN_004086b0(800);
  iVar2 = (**(code **)(*DAT_00736368 + 0x40))
                    (DAT_00736368,DAT_00736398,1,DAT_00736380,0x40,&DAT_0071a96c,&DAT_0073636c);
  if (iVar2 != 0) {
    (**(code **)(*DAT_00736368 + 0x40))
              (DAT_00736368,DAT_00736398,1,DAT_00736380,0x20,&DAT_0071a96c,&DAT_0073636c);
  }
  ShowWindow(DAT_00736380,1);
  SetWindowLongA(DAT_00736380,-0x10,0x10c00000);
  VertexDecls_CreateDefault();
  Effects_CreateAll();
  DeviceCaps_Init();
  RenderQueue_PoolsCreate();
  DAT_0073645c = (uint)(DAT_00736384 != 0);
  ReflectionCube_Create();
  SceneRTCreate();
  RenderTargetTable_Init();
  BlurCreateRTs();
  QuadBuffers_Create(&DAT_00718738);
  Input__CreateDirectInput8();
  FUN_00413050();
  FUN_00410780();
  return 0;
}


// ==== 0x408b20 RenderState_ResetDefaults

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void RenderState_ResetDefaults(void)

{
  int iVar1;
  int *piStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  int *piStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  int *piStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  int *piStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  int *piStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int *piStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  int *piStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int *piStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int *piStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int *piStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int *piStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int *piStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_10 = 1;
  uStack_14 = 7;
  piStack_18 = DAT_0073636c;
  uStack_1c = 0x408b35;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_1c = 1;
  uStack_20 = 0xe;
  piStack_24 = DAT_0073636c;
  uStack_28 = 0x408b47;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_28 = 4;
  uStack_2c = 0x17;
  piStack_30 = DAT_0073636c;
  uStack_34 = 0x408b59;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_34 = 5;
  uStack_38 = 0x19;
  piStack_3c = DAT_0073636c;
  uStack_40 = 0x408b6b;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_40 = 1;
  uStack_44 = 0x1d;
  piStack_48 = DAT_0073636c;
  uStack_4c = 0x408b7d;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_4c = 0;
  uStack_50 = 0x89;
  piStack_54 = DAT_0073636c;
  uStack_58 = 0x408b93;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_58 = 1;
  uStack_5c = 0x16;
  piStack_60 = DAT_0073636c;
  uStack_64 = 0x408ba5;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_64 = 0;
  uStack_68 = 0x1c;
  piStack_6c = DAT_0073636c;
  uStack_70 = 0x408bb6;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_70 = 0xf;
  uStack_74 = 0xa8;
  piStack_78 = DAT_0073636c;
  uStack_7c = 0x408bcb;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_7c = 2;
  uStack_80 = 6;
  uStack_84 = 0;
  piStack_88 = DAT_0073636c;
  uStack_8c = 0x408bde;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_8c = 2;
  uStack_90 = 6;
  uStack_94 = 1;
  piStack_98 = DAT_0073636c;
  uStack_9c = 0x408bf2;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_9c = 2;
  uStack_a0 = 6;
  uStack_a4 = 2;
  piStack_a8 = DAT_0073636c;
  uStack_ac = 0x408c06;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_ac = 2;
  uStack_b0 = 6;
  uStack_b4 = 3;
  piStack_b8 = DAT_0073636c;
  uStack_bc = 0x408c1a;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_bc = 2;
  uStack_c0 = 5;
  uStack_c4 = 0;
  piStack_c8 = DAT_0073636c;
  uStack_cc = 0x408c2d;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_cc = 2;
  uStack_d0 = 5;
  uStack_d4 = 1;
  piStack_d8 = DAT_0073636c;
  uStack_dc = 0x408c41;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_dc = 2;
  uStack_e0 = 5;
  uStack_e4 = 2;
  piStack_e8 = DAT_0073636c;
  uStack_ec = 0x408c55;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_ec = 2;
  uStack_f0 = 5;
  uStack_f4 = 3;
  piStack_f8 = DAT_0073636c;
  uStack_fc = 0x408c69;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_fc = 1;
  uStack_100 = 7;
  uStack_104 = 0;
  piStack_108 = DAT_0073636c;
  uStack_10c = 0x408c7c;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_10c = 1;
  uStack_110 = 7;
  uStack_114 = 1;
  piStack_118 = DAT_0073636c;
  uStack_11c = 0x408c90;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_11c = 1;
  uStack_120 = 7;
  uStack_124 = 2;
  piStack_128 = DAT_0073636c;
  uStack_12c = 0x408ca4;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_12c = 1;
  uStack_130 = 7;
  uStack_134 = 3;
  piStack_138 = DAT_0073636c;
  (**(code **)(*DAT_0073636c + 0x114))();
  iVar1 = 0;
  do {
    (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,iVar1,1,1);
    (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,iVar1,4,1);
    (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,iVar1,0x18,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  if (DAT_0073640c != (undefined4 *)0x0) {
    if (DAT_0073640c == &DAT_0071abb8) goto LAB_00408d73;
    (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
    (*(code *)DAT_0073640c[0x37])();
  }
  DAT_0073640c = &DAT_0071abb8;
  (*DAT_0071ac90)();
  (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
  (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,&piStack_138,0);
  (**(code **)(*DAT_0071abd0 + 0x104))(DAT_0071abd0,0);
LAB_00408d73:
  _DAT_007070cc = 0xffffffff;
  _DAT_007070c8 = 0xffffffff;
  if (DAT_0073640c == (undefined4 *)0x0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x1b);
  }
  else {
    (**(code **)(*(int *)DAT_0073640c[6] + 0x68))((int *)DAT_0073640c[6],DAT_0073640c[0x31],0);
  }
  _DAT_007070d0 = 0;
  if (DAT_0073640c == (undefined4 *)0x0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xf);
  }
  else {
    (**(code **)(*(int *)DAT_0073640c[6] + 0x68))((int *)DAT_0073640c[6],DAT_0073640c[0x2f],0);
  }
  _DAT_007070c4 = 0;
  if (DAT_0073640c == (undefined4 *)0x0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x18);
    _DAT_007070c0 = 0;
    return;
  }
  (**(code **)(*(int *)DAT_0073640c[6] + 0x68))((int *)DAT_0073640c[6],DAT_0073640c[0x30],0);
  _DAT_007070c0 = 0;
  return;
}


// ==== 0x408e30 FUN_00408e30

void FUN_00408e30(int param_1)

{
  int *unaff_EDI;
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
  
  Atan2ToAngle16(((undefined4 *)*unaff_EDI)[2],*(undefined4 *)*unaff_EDI);
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
  *(int **)(param_1 + 0x80) = unaff_EDI;
  return;
}


// ==== 0x408f00 FUN_00408f00

void FUN_00408f00(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 *puVar3;
  int *piVar4;
  
  cVar2 = DAT_0071db20;
  if (DAT_0071db20 == '\0') {
    *(undefined4 *)(in_EAX + 0x820) = 0;
  }
  if ((((DAT_00702c80 != 0) && (DAT_0077a920 == 6)) && (*DAT_007361f0 != 1)) && (cVar2 == '\0')) {
    puVar3 = &DAT_007404c0;
    do {
      if ((*(char *)(puVar3 + 2) != '\0') && (*(int *)(puVar3[0x16] + 0x10) != 0)) {
        iVar1 = *(int *)(in_EAX + 0x820);
        *(int *)(in_EAX + 0x820) = iVar1 + 1;
        FUN_0053e290(iVar1 * 0xd0 + in_EAX);
      }
      puVar3 = puVar3 + 0x18;
    } while ((int)puVar3 < 0x740581);
    if (DAT_00700e74 != 0) {
      piVar4 = &DAT_00740878;
      do {
        if (((char)piVar4[-0x14] != '\0') && (*(int *)(*piVar4 + 0x10) != 0)) {
          iVar1 = *(int *)(in_EAX + 0x820);
          *(int *)(in_EAX + 0x820) = iVar1 + 1;
          FUN_0053e290(iVar1 * 0xd0 + in_EAX);
        }
        piVar4 = piVar4 + 0x18;
      } while ((int)piVar4 < 0x740a59);
    }
    if (((DAT_00700e90 != 0) && (DAT_007405e8 != '\0')) && (*(int *)(DAT_00740638 + 0x10) != 0)) {
      iVar1 = *(int *)(in_EAX + 0x820);
      *(int *)(in_EAX + 0x820) = iVar1 + 1;
      FUN_0053e290(iVar1 * 0xd0 + in_EAX);
    }
    if ((DAT_00700e80 != 0) && (DAT_00740768 != '\0')) {
      iVar1 = *(int *)(in_EAX + 0x820);
      *(int *)(in_EAX + 0x820) = iVar1 + 1;
      FUN_0053e290(iVar1 * 0xd0 + in_EAX);
    }
  }
  FUN_00446620();
  return;
}


// ==== 0x409090 RenderFrameMain_HeadlightItemCallback

/* [canon] render med (ghidra-canon+hopper) docs/re/render.md */

void RenderFrameMain_HeadlightItemCallback(int param_1)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + 0x2e) = 0x200;
  return;
}


// ==== 0x4090a0 FUN_004090a0

/* WARNING: Removing unreachable block (ram,0x00409131) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004090a0(void)

{
  float fVar1;
  float *unaff_ESI;
  
  FUN_00588f40(0);
  fVar1 = (_K_ONE - _DAT_00737bf0) * _DAT_00737c00;
  fVar1 = fVar1 + fVar1;
  if (fVar1 <= _K_EPS_SPEED) {
    unaff_ESI[2] = 0.0;
    return;
  }
  fVar1 = _K_ONE / fVar1;
  *unaff_ESI = fVar1 * 1.0;
  unaff_ESI[1] = fVar1 * 250.0;
  unaff_ESI[2] = (float)(DAT_00737c04 >> 0x18) * 1.5 * _K_BLUR_MIN_T;
  unaff_ESI[3] = _DAT_00737bf8 * 1.35;
  unaff_ESI[6] = (float)(DAT_00737c04 & 0xff) * _K_BLUR_MIN_T;
  unaff_ESI[5] = (float)(DAT_00737c04 >> 8 & 0xff) * _K_BLUR_MIN_T;
  unaff_ESI[4] = (float)(DAT_00737c04 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
  return;
}


// ==== 0x409180 DrawScreenQuadTextured

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void DrawScreenQuadTextured(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  int **ppiVar5;
  undefined4 *puVar6;
  undefined4 uStack_224;
  int *piStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  int *piStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 *puStack_208;
  undefined4 uStack_204;
  int *piStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  int *piStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  int *piStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  int *piStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  int *piStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  int *piStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  int *piStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  int *piStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  int *piStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  int *piStack_17c;
  int *apiStack_178 [4];
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined1 *puStack_160;
  undefined4 *puStack_15c;
  undefined4 *puStack_158;
  undefined4 *puStack_154;
  undefined1 auStack_13c [4];
  undefined4 *local_138 [22];
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90 [16];
  undefined4 local_50 [19];
  
  local_138[0x12] = (undefined4 *)0xbf800000;
  local_138[0x13] = (undefined4 *)0xbf800000;
  local_138[0x14] = (undefined4 *)0x0;
  local_e0 = 0;
  local_dc = 0x3f800000;
  local_d8 = 0xbf800000;
  local_d4 = 0x3f800000;
  local_d0 = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0x3f800000;
  local_bc = 0x3f800000;
  local_b8 = 0;
  local_b0 = 0x3f800000;
  local_ac = 0;
  local_a8 = 0x3f800000;
  local_a4 = 0xbf800000;
  local_a0 = 0;
  local_98 = 0x3f800000;
  local_94 = 0x3f800000;
  local_138[2] = (undefined4 *)0x3f800000;
  local_138[3] = (undefined4 *)0x0;
  local_138[4] = (undefined4 *)0x0;
  local_138[5] = (undefined4 *)0x0;
  local_138[6] = (undefined4 *)0x0;
  local_138[7] = (undefined4 *)0x3f800000;
  local_138[8] = (undefined4 *)0x0;
  local_138[9] = (undefined4 *)0x0;
  local_138[10] = (undefined4 *)0x0;
  local_138[0xb] = (undefined4 *)0x0;
  local_138[0xc] = (undefined4 *)0x3f800000;
  local_138[0xd] = (undefined4 *)0x0;
  local_138[0xe] = (undefined4 *)0x0;
  local_138[0xf] = (undefined4 *)0x0;
  local_138[0x10] = (undefined4 *)0x0;
  local_138[0x11] = (undefined4 *)0x3f800000;
  local_138[0] = &DAT_00740460 + *(int *)(DAT_00736458 + 4) * 0x18;
  puVar1 = (undefined4 *)*local_138[0];
  puStack_154 = puVar1 + 0x10;
  puVar3 = puVar1;
  puVar6 = local_50;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar3 = puStack_154;
  puVar6 = local_90;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  *puVar1 = 0x3f800000;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0x3f800000;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0x3f800000;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0x3f800000;
  *puStack_154 = 0x3f800000;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  puVar1[0x15] = 0x3f800000;
  puVar1[0x1a] = 0x3f800000;
  puVar1[0x1f] = 0x3f800000;
  puStack_15c = puVar1 + 0x20;
  puVar1[0x14] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  puStack_160 = (undefined1 *)0x4093a2;
  puStack_158 = puVar1;
  local_138[1] = puStack_15c;
  D3DXMatrixMultiply();
  puStack_160 = auStack_13c;
  DAT_007010b8 = 0xffffffff;
  uStack_164 = 0x4093bd;
  Device_SetWorldMatrix();
  puStack_160 = (undefined1 *)0x3;
  uStack_164 = 1;
  uStack_168 = 0;
  apiStack_178[3] = DAT_0073636c;
  apiStack_178[2] = (int *)0x4093d3;
  (**(code **)(*DAT_0073636c + 0x114))();
  apiStack_178[2] = (int *)0x3;
  apiStack_178[1] = (int *)0x2;
  apiStack_178[0] = (int *)0x0;
  piStack_17c = DAT_0073636c;
  uStack_180 = 0x4093e6;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_180 = 3;
  uStack_184 = 1;
  uStack_188 = 1;
  piStack_18c = DAT_0073636c;
  uStack_190 = 0x4093fa;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_190 = 3;
  uStack_194 = 2;
  uStack_198 = 1;
  piStack_19c = DAT_0073636c;
  uStack_1a0 = 0x40940e;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_1a0 = 3;
  uStack_1a4 = 1;
  uStack_1a8 = 2;
  piStack_1ac = DAT_0073636c;
  uStack_1b0 = 0x409422;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_1b0 = 3;
  uStack_1b4 = 2;
  uStack_1b8 = 2;
  piStack_1bc = DAT_0073636c;
  uStack_1c0 = 0x409436;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_1c0 = 3;
  uStack_1c4 = 1;
  uStack_1c8 = 3;
  piStack_1cc = DAT_0073636c;
  uStack_1d0 = 0x40944a;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_1d0 = 3;
  uStack_1d4 = 2;
  uStack_1d8 = 3;
  piStack_1dc = DAT_0073636c;
  uStack_1e0 = 0x40945e;
  (**(code **)(*DAT_0073636c + 0x114))();
  uStack_1e0 = param_1;
  uStack_1e4 = 0;
  piStack_1e8 = DAT_0073636c;
  uStack_1ec = 0x409471;
  (**(code **)(*DAT_0073636c + 0x104))();
  uStack_1ec = 1;
  uStack_1f0 = 0x40947e;
  FUN_00410550();
  uStack_1ec = 0x40948a;
  FUN_00410650();
  uStack_1ec = 0;
  uStack_1f0 = 7;
  piStack_1f4 = DAT_0073636c;
  uStack_1f8 = 0x40949b;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_1f8 = 0;
  uStack_1fc = 0xe;
  piStack_200 = DAT_0073636c;
  uStack_204 = 0x4094ac;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_204 = 0x18;
  puStack_208 = &uStack_1a0;
  uStack_20c = 2;
  uStack_210 = 6;
  piStack_214 = DAT_0073636c;
  uStack_218 = 0x4094c5;
  (**(code **)(*DAT_0073636c + 0x14c))();
  uStack_218 = 1;
  uStack_21c = 0xe;
  piStack_220 = DAT_0073636c;
  uStack_224 = 0x4094d7;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_224 = 1;
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7);
  _DAT_007070cc = 0xffffffff;
  _DAT_007070c8 = 0xffffffff;
  if (DAT_0073640c == 0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x1b);
  }
  else {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xc4),0);
  }
  ppuVar4 = local_138;
  puVar3 = puVar1;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *ppuVar4;
    ppuVar4 = ppuVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  ppiVar5 = apiStack_178;
  puVar3 = puVar1 + 0x10;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *ppiVar5;
    ppiVar5 = ppiVar5 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_007070d0 = 0;
  D3DXMatrixMultiply(uStack_21c,puVar1,puVar1 + 0x10);
  Device_SetWorldMatrix(&uStack_224);
  return;
}


// ==== 0x409580 RenderFrameMain

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+H+C) docs/re/blur.md */

void RenderFrameMain(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_854 [4];
  undefined1 auStack_850 [4];
  undefined1 auStack_84c [2092];
  undefined4 local_20;
  
  DAT_0071db20 = 0;
  _DAT_0071db24 = 0;
  local_20 = 0;
  FUN_00408f00();
  if (DAT_00700e90 != 0) {
    if (DAT_007405e8 == '\0') {
      return;
    }
    if (*(int *)(DAT_00740638 + 0x10) == 0) {
      return;
    }
    SceneRTSelect(1);
    if (1 < DAT_00700e90) {
      WorldSections_QueueForView(&DAT_007405e0);
      RenderFrame_DrawCars();
      DrawShowcaseCarList(&DAT_007405e0,0,1,1,1);
    }
    DrawEmitters(&DAT_00746dd0,&DAT_007405e0);
    FUN_0040ed50();
    Effect_Select();
    if (DAT_00700ea0 != 0) {
      LampFlares_Draw(&DAT_007405e0,2);
      FUN_00570d00(1);
      FUN_00570c70(1);
      Emitters_DrawFlares(&DAT_00746dd0,&DAT_007405e0);
    }
  }
  if (DAT_00700e74 != 0) {
    puVar1 = &DAT_00740820;
    do {
      if ((puVar1[8] != '\0') && (*(int *)(*(int *)(puVar1 + 0x58) + 0x10) != 0)) {
        SceneRTSelect(1);
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,0);
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,0);
        CarOverlays_QueueByView();
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,1);
        Effect_Select();
        FUN_0040ed50();
        if (DAT_00700e78 != 0) {
          WorldSections_QueueForView(puVar1);
        }
        DrawEmitters(&DAT_00746dd0,puVar1);
        FUN_0040ed50();
        Effect_Select();
        if (DAT_00700ea0 != 0) {
          LampFlares_Draw(puVar1,1);
          Emitters_DrawFlares(&DAT_00746dd0,puVar1);
        }
      }
      puVar1 = puVar1 + 0x60;
    } while ((int)puVar1 < 0x740a01);
  }
  FUN_0040ed50();
  if (DAT_00740588 != '\0') {
    SceneRTSelect(1);
    WorldSections_QueueForView(&DAT_00740580);
    DrawRaceCarList(&DAT_00740580);
    FUN_0040ed50();
    if (DAT_00700ea8 != 0) {
      Particles_DrawSystem(gParticleSystemA,&DAT_00740580);
      Particles_DrawSystem(&DAT_0078e9e0,&DAT_00740580);
    }
    if ((DAT_00700ea0 != 0) && (FUN_00570d00(0), DAT_00700ea0 != 0)) {
      LampFlares_Draw(&DAT_00740580,0);
    }
    if (DAT_007364ac != (int *)0x0) {
      Effect_Select();
      DrawScreenQuadTextured(*(undefined4 *)(*DAT_007364ac + 0x18),5,6);
    }
    if (DAT_007364b0 != (int *)0x0) {
      iVar2 = *DAT_007364b0;
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xa8,8);
      DrawScreenQuadTextured(*(undefined4 *)(iVar2 + 0x18),2,1);
    }
    RenderState_ResetDefaults();
  }
  FUN_0040ed50();
  iVar2 = 1;
  do {
    puVar3 = &DAT_00740460 + iVar2 * 0x18;
    if (((&DAT_00740468)[iVar2 * 0x60] != '\0') &&
       (*(int *)(*(int *)(&DAT_007404b8 + iVar2 * 0x60) + 0x10) != 0)) {
      FUN_004090a0();
      SceneRTSelect(DAT_0073645c == 1);
      if (DAT_00700e80 != 0) {
        FUN_004468a0(RenderFrameMain_HeadlightItemCallback);
      }
      if (((DAT_0077a920 == 6) && (*DAT_007361f0 != 1)) ||
         ((DAT_006fb038 != 0 && (DAT_0077a920 == 3)))) {
        CarOverlays_QueueByView();
      }
      if (DAT_0073640c == (undefined4 *)0x0) {
LAB_0040992c:
        DAT_0073640c = &DAT_0071abb8;
        (*DAT_0071ac90)();
        (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
        (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,auStack_84c,0);
        (**(code **)(*DAT_0071abd0 + 0x104))(DAT_0071abd0,0);
      }
      else if (DAT_0073640c != &DAT_0071abb8) {
        (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
        (*(code *)DAT_0073640c[0x37])();
        goto LAB_0040992c;
      }
      FUN_0040ed50();
      WorldSections_QueueForView(puVar3);
      FUN_0040ed50();
      FUN_0058a240();
      RenderWorldModels(puVar3,0);
      if ((DAT_00736384 != 0) && (DAT_0073645c == 1)) {
        FUN_0040ed50();
        if (DAT_00700e98 != 0) {
          SpeedBlurPass();
        }
        RenderState_ResetDefaults();
      }
      DrawRaceCarList(puVar3);
      DrawShowcaseCarList(puVar3,1,0,1,1);
      DrawEmitters(&DAT_00746dd0,puVar3);
      if (iVar2 == 1) {
        if (DAT_0073640c != (undefined4 *)0x0) {
          if (DAT_0073640c == &DAT_0071abb8) goto LAB_00409a55;
          (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
          (*(code *)DAT_0073640c[0x37])();
        }
        DAT_0073640c = &DAT_0071abb8;
        (*DAT_0071ac90)();
        (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
        (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,auStack_854,0);
        (**(code **)(*DAT_0071abd0 + 0x104))(DAT_0071abd0,0);
      }
LAB_00409a55:
      FUN_0040ed50();
      DAT_007187b4 = 0;
      if (DAT_00700ea8 != 0) {
        Particles_DrawSystem(gParticleSystemA,puVar3);
        Particles_DrawSystem(&DAT_0078e9e0,puVar3);
      }
      if (DAT_0073640c == (undefined4 *)0x0) {
LAB_00409aa7:
        DAT_0073640c = &DAT_0071abb8;
        (*DAT_0071ac90)();
        (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
        (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,auStack_850,0);
        (**(code **)(*DAT_0071abd0 + 0x104))(DAT_0071abd0,0);
      }
      else if (DAT_0073640c != &DAT_0071abb8) {
        (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
        (*(code *)DAT_0073640c[0x37])();
        goto LAB_00409aa7;
      }
      if (DAT_00700ea0 != 0) {
        if ((DAT_00700e9c == 0) || (DAT_0073645c != 1)) {
          (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,0);
          LampFlares_Draw(puVar3,0);
          Emitters_DrawFlares(&DAT_00746dd0,puVar3);
          FUN_00570d00(0);
          FUN_00570c70(0);
          (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
        }
        else {
          LightStreakPath();
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (1 < iVar2) {
      return;
    }
  } while( true );
}


// ==== 0x409b70 LightStreakPath

/* [canon] render U (C) docs/re/blur.md */

void LightStreakPath(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 *puStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  undefined1 *puStack_3c;
  undefined4 *puStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (DAT_0073645c == 1) {
    (**(code **)(*DAT_0073636c + 0x94))();
    pcVar3 = "WHITE16X16_NOALPHA";
    piStack_28 = (int *)0xffffffff;
    uVar2 = 0x57;
    do {
      piStack_28 = (int *)((int)piStack_28 * 0x21 + uVar2);
      pbVar1 = (byte *)(pcVar3 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar3 = pcVar3 + 1;
    } while (*pbVar1 != 0);
    uStack_20 = 0;
    uStack_24 = 1;
    uStack_2c = 0x409bbe;
    Texture_FindByHash();
    uStack_20 = 0x8296b4;
    uStack_24 = 0xc1;
    piStack_28 = DAT_0073636c;
    uStack_2c = 0x409bdb;
    (**(code **)(*DAT_0073636c + 0xe4))();
    uStack_2c = 0xe;
    uStack_30 = 1;
    piStack_34 = (int *)0x1;
    puStack_38 = &uStack_20;
    puStack_3c = &stack0xffffffe4;
    piStack_40 = (int *)0x1;
    uStack_20 = 0x1fffffff;
    uStack_44 = 0x409c03;
    BlurComposite();
    uStack_2c = DAT_0071abb0;
    uStack_30 = 0;
    piStack_34 = DAT_0073636c;
    puStack_38 = (undefined4 *)0x409c1d;
    (**(code **)(*DAT_0073636c + 0x94))();
    puStack_38 = (undefined4 *)0x409c29;
    Effect_Select();
    puStack_38 = (undefined4 *)0x1;
    puStack_3c = (undefined1 *)0x7;
    piStack_40 = DAT_0073636c;
    uStack_44 = 0x409c3b;
    (**(code **)(*DAT_0073636c + 0xe4))();
    uStack_44 = 0;
    uStack_48 = 0xe;
    piStack_4c = DAT_0073636c;
    puStack_50 = (undefined4 *)0x409c4c;
    (**(code **)(*DAT_0073636c + 0xe4))();
    puStack_50 = (undefined4 *)0x0;
    LampFlares_Draw(&DAT_007404c0);
    puStack_50 = &DAT_007404c0;
    Emitters_DrawFlares(&DAT_00746dd0);
    puStack_50 = (undefined4 *)0x0;
    FUN_00570d00();
    FUN_00570c70(0);
    puStack_50 = (undefined4 *)0x1;
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe);
    SceneRTSelect(0);
    BlurComposite(1,&DAT_0071aba4,&puStack_50,1,2,2);
  }
  return;
}


// ==== 0x409cd0 Hud::RenderPass

/* [canon] hud med (ghidra+hopper+capstone) docs/re/hud_input.md */

void Hud__RenderPass(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  int **ppiStack_11c;
  int *piStack_118;
  int *piStack_114;
  int *piStack_110;
  int *piStack_10c;
  int *piStack_108;
  int *piStack_104;
  int local_f0 [20];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  
  piStack_104 = (int *)0x409ce7;
  RenderState_ResetDefaults();
  piStack_104 = (int *)0x0;
  piStack_108 = (int *)0x409cfc;
  SceneRTSelect();
  if (DAT_0073640c == (undefined4 *)0x0) {
LAB_00409d27:
    DAT_0073640c = &DAT_0071abb8;
    piStack_104 = (int *)0x409d37;
    (*DAT_0071ac90)();
    piStack_104 = (int *)DAT_0071abbc;
    piStack_108 = DAT_0073636c;
    piStack_10c = (int *)0x409d4c;
    (**(code **)(*DAT_0073636c + 0x15c))();
    piStack_10c = (int *)0x0;
    piStack_110 = (int *)&stack0xffffff04;
    piStack_114 = DAT_0071abd0;
    piStack_118 = (int *)0x409d61;
    (**(code **)(*DAT_0071abd0 + 0x100))();
    piStack_118 = (int *)0x0;
    ppiStack_11c = (int **)DAT_0071abd0;
    uStack_120 = 0x409d71;
    (**(code **)(*DAT_0071abd0 + 0x104))();
  }
  else if (DAT_0073640c != &DAT_0071abb8) {
    piStack_104 = (int *)DAT_0073640c[6];
    piStack_108 = (int *)0x409d1b;
    (**(code **)(*piStack_104 + 0x108))();
    piStack_108 = (int *)0x409d27;
    (*(code *)DAT_0073640c[0x37])();
    goto LAB_00409d27;
  }
  piStack_104 = DAT_00740460 + 0x10;
  piStack_108 = DAT_00740460;
  piStack_10c = DAT_00740460 + 0x20;
  local_f0[0] = 0x3f800000;
  local_f0[1] = 0;
  local_f0[2] = 0;
  local_f0[3] = 0;
  local_f0[4] = 0;
  local_f0[5] = 0x3f800000;
  local_f0[6] = 0;
  local_f0[7] = 0;
  local_f0[8] = 0;
  local_f0[9] = 0;
  local_f0[10] = 0x3f800000;
  local_f0[0xb] = 0;
  local_f0[0xc] = 0;
  local_f0[0xd] = 0;
  local_f0[0xe] = 0;
  local_f0[0xf] = 0x3f800000;
  piVar3 = local_f0;
  piVar4 = DAT_00740460;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  piStack_110 = (int *)0x409e13;
  D3DXMatrixMultiply();
  piStack_110 = DAT_00740460 + 0x10;
  piStack_114 = DAT_00740460;
  piStack_118 = DAT_00740460 + 0x20;
  piVar3 = (int *)&stack0xffffff04;
  piVar4 = piStack_110;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  ppiStack_11c = (int **)0x409e35;
  D3DXMatrixMultiply();
  ppiStack_11c = &piStack_108;
  uStack_120 = 0x409e41;
  Device_SetWorldMatrix();
  ppiStack_11c = (int **)0x0;
  uStack_120 = 0xe;
  piStack_124 = DAT_0073636c;
  uStack_128 = 0x409e55;
  (**(code **)(*DAT_0073636c + 0xe4))();
  uStack_128 = 0;
  uStack_12c = 7;
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c);
  if (param_1 == 0) {
    if ((DAT_006f9228 != 0) && (DAT_0073578c != 0)) {
      puVar1 = (undefined1 *)(DAT_0073578c + 4);
      *puVar1 = 1;
      FUN_004f0390();
      *puVar1 = 0;
      FEng__RenderPackages(DAT_0070649c,DAT_007064a0);
    }
    iVar2 = 0;
    if (0 < DAT_007361c4) {
      do {
        if ((*(int *)((&DAT_007361bc)[iVar2] + 0x534) != 0) && (DAT_006f9228 != 0)) {
          TrackMap__Draw(&DAT_00740460);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_007361c4);
    }
    if (DAT_00740588 != '\0') {
      FUN_0040be70();
      local_f0[8] = 0x43dc0000;
      local_f0[9] = 0x41700000;
      local_f0[0xc] = 0x43480000;
      local_f0[0xd] = 0x41700000;
      local_f0[0x10] = 0x43480000;
      local_f0[0x11] = 0x42be0000;
      uStack_a0 = 0x43dc0000;
      uStack_9c = 0x42be0000;
      (**(code **)(*DAT_0073636c + 0x104))(DAT_0073636c,0,DAT_00736470);
      (**(code **)(*DAT_0073636c + 0x114))(DAT_0073636c,0,1,3);
      (**(code **)(*DAT_0073636c + 0x114))(DAT_0073636c,0,2,3);
      FUN_00410650();
      FUN_00410550(1);
      FUN_0040bef0();
      (**(code **)(*DAT_0073636c + 0x114))(DAT_0073636c,0,1,1);
      (**(code **)(*DAT_0073636c + 0x114))(DAT_0073636c,0,2,1);
    }
  }
  else if ((DAT_006f9228 != 0) && (DAT_0073578c != 0)) {
    FUN_004f5e90();
  }
  if (DAT_0078eb90 != 0) {
    FUN_0040be70();
    uStack_60 = 0x7f7f7f7f;
    uStack_5c = 0x7f7f7f7f;
    uStack_58 = 0x7f7f7f7f;
    uStack_54 = 0x7f7f7f7f;
    local_f0[8] = 0x43000000;
    local_f0[9] = 0;
    local_f0[0xc] = 0x43c00000;
    local_f0[0xd] = 0;
    local_f0[0x10] = 0x43c00000;
    local_f0[0x11] = 0x43800000;
    uStack_a0 = 0x43000000;
    uStack_9c = 0x43800000;
    DAT_00736450 = DAT_0071aa28;
    if (DAT_0078eb8c != '\0') {
      FUN_0040bef0();
    }
    DAT_00736450 = 0;
  }
  if (DAT_0073640c != (undefined4 *)0x0) {
    if (DAT_0073640c == &DAT_0071abb8) goto LAB_0040a106;
    (**(code **)(*(int *)DAT_0073640c[6] + 0x108))((int *)DAT_0073640c[6]);
    (*(code *)DAT_0073640c[0x37])();
  }
  DAT_0073640c = &DAT_0071abb8;
  (*DAT_0071ac90)();
  (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,DAT_0071abbc);
  (**(code **)(*DAT_0071abd0 + 0x100))(DAT_0071abd0,&uStack_12c,0);
LAB_0040a106:
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,7,1);
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
  return;
}


// ==== 0x40a140 FUN_0040a140

void __fastcall FUN_0040a140(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int in_EAX;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar8;
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_78;
  float local_68;
  float local_60;
  undefined1 local_50 [76];
  
  puVar7 = DAT_0073d6d8;
  iVar2 = *(int *)(param_1 + 0x40);
  if (DAT_0077a920 == 3) {
    if (((undefined4 **)DAT_0073d6d8 != &DAT_0073d6d8) &&
       (puVar5 = (undefined4 *)NullUpdate_ret(), puVar7 != puVar5)) {
      do {
        if ((*(int *)(param_1 + 4) + -7 == puVar7[0x1cc]) && (puVar7[0x267] == 0)) {
          local_8c = (float)puVar7[0x1d5];
          local_60 = (float)puVar7[0x1d4] * -0.45;
          local_88 = (float)puVar7[0x1d6];
          local_a0 = (float)puVar7[0x1dc];
          local_68 = local_88 * -0.45;
          local_9c = (float)puVar7[0x1dd];
          local_98 = (float)puVar7[0x1de];
          local_b0 = (float)puVar7[0x1d4];
          local_ac = (float)puVar7[0x1d5];
          local_a8 = (float)puVar7[0x1d6];
          local_78 = local_98 * 0.75;
          local_d0 = local_a0 * 0.75 + local_60 + (float)puVar7[0x1d0];
          local_cc = local_9c * 0.75 + local_8c * -0.45 + (float)puVar7[0x1d1];
          local_c8 = local_78 + local_68 + (float)puVar7[0x1d2];
        }
        puVar7 = (undefined4 *)*puVar7;
      } while (puVar7 != puVar5);
    }
  }
  else if (((DAT_0077a920 == 6) && (*DAT_007361f0 != 1)) && (in_EAX < *(int *)(DAT_007361f8 + 0x1c))
          ) {
    iVar6 = RaceManager__FindRacerByIdIn();
    fVar1 = *(float *)(iVar6 + 0x58);
    iVar6 = RaceManager__FindRacerByIdIn();
    local_ac = *(float *)(iVar6 + 0x94);
    local_b0 = *(float *)(iVar6 + 0x90);
    local_a8 = *(float *)(iVar6 + 0x98);
    iVar6 = RaceManager__FindRacerByIdIn();
    local_bc = *(float *)(iVar6 + 0x94);
    local_b8 = *(float *)(iVar6 + 0x98);
    fVar8 = extraout_ST1;
    iVar6 = RaceManager__FindRacerByIdIn();
    local_9c = *(float *)(iVar6 + 0xb4);
    local_98 = *(float *)(iVar6 + 0xb8);
    local_a0 = *(float *)(iVar6 + 0xb0);
    local_78 = local_98 * 0.75;
    local_d0 = local_a0 * 0.75 + (float)((float10)(float)(extraout_ST0 * (float10)0.0) + fVar8);
    local_cc = (float)((float10)local_9c * (float10)0.75 +
                      (float10)local_bc * (float10)0.0 + extraout_ST1_00);
    local_c8 = local_78 + local_b8 * 0.0 + fVar1;
  }
  local_a8 = local_a8 - 0.1;
  local_c0 = 0;
  local_bc = 0.0;
  local_b8 = 1.0;
  bNormalize3();
  local_90 = local_b0 + local_d0;
  local_8c = local_ac + local_cc;
  local_88 = local_a8 + local_c8;
  Matrix4_BuildLookAt(&local_c0);
  Camera__SetCameraMatrix(iVar2,local_50,0);
  iVar6 = DAT_00735f5c;
  if (DAT_00735f5c == 0) {
    *(undefined4 *)(iVar2 + 0x284) = 0;
    *(undefined4 *)(iVar2 + 0xb4) = 0;
  }
  uVar3 = DAT_00702c90;
  *(undefined4 *)(iVar2 + 0xbc) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0xc0) = uVar3;
  if (iVar6 == 0) {
    uVar4 = _ftol_nocw();
    *(undefined2 *)(iVar2 + 0xc4) = uVar4;
  }
  return;
}


// ==== 0x40a4e0 Device_HandleLost

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void Device_HandleLost(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0071abd0;
  do {
    (**(code **)(*(int *)*puVar1 + 0x110))((int *)*puVar1);
    puVar1 = puVar1 + 0x38;
  } while ((int)puVar1 < 0x71b1f0);
  ReleaseSceneRTs();
  BlurReleaseRTs();
  iVar2 = 0;
  do {
    (**(code **)(**(int **)((int)&DAT_00718738 + iVar2) + 8))(*(int **)((int)&DAT_00718738 + iVar2))
    ;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x78);
  (**(code **)(*DAT_007187b0 + 8))(DAT_007187b0);
  iVar2 = (**(code **)(*DAT_0073636c + 0x40))(DAT_0073636c,&DAT_0071a96c);
  while (iVar2 != 0) {
    iVar2 = (**(code **)(*DAT_0073636c + 0x40))(DAT_0073636c,&DAT_0071a96c);
  }
  SceneRTCreate();
  ReflectionCube_Create();
  RenderTargetTable_Init();
  BlurCreateRTs();
  QuadBuffers_Create(&DAT_00718738);
  RenderState_ResetDefaults();
  FUN_0040ebc0();
  return;
}


// ==== 0x40a580 RenderFrame

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void RenderFrame(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  Views_UpdateViewCountAndEnables();
  iVar1 = 0;
  if (DAT_00700eb4 == 0) {
    DAT_00734608 = 1;
    DAT_0073460c = 1;
  }
  else if (DAT_00700eb4 == 1) {
    DAT_00734608 = 0;
    DAT_0073460c = 0;
  }
  switch(DAT_00700eb0) {
  case 0:
  case 1:
    DAT_00736128 = 2;
    break;
  case 2:
  case 3:
    DAT_00736128 = 0;
  }
  if (((DAT_0077a920 == 6) && (*DAT_007361f0 != 1)) && (DAT_007364f4 = 0, DAT_00734534 == 0)) {
    FUN_00588c00();
  }
  if (DAT_00700e74 != 0) {
    Views_UpdatePerFrame();
  }
  do {
    if (iVar1 == 8) {
      FUN_0040a140();
    }
    if (((&DAT_00740468)[iVar1 * 0x60] != '\0') || (9 < iVar1)) {
      BuildProjection(&DAT_00740460 + iVar1 * 0x18,0,0,0);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  iVar1 = (**(code **)(*DAT_0073636c + 0xc))(DAT_0073636c);
  if (iVar1 == 0) {
    (**(code **)(*DAT_0073636c + 0xa4))(DAT_0073636c);
    Hud__RenderPass(1);
    RenderFrameMain();
    if (DAT_0073645c == 1) {
      uStack_10 = DAT_00736460;
      uStack_c = DAT_0071ab9c;
      BlurComposite(1,&uStack_10,&stack0xffffffe8,0,2,2);
    }
    Hud__RenderPass(0);
    (**(code **)(*DAT_0073636c + 0xa8))(DAT_0073636c);
  }
  if (DAT_0073638c != 0) {
    DAT_0073638c = 0;
  }
  iVar1 = (**(code **)(*DAT_0073636c + 0x44))(DAT_0073636c,0,0,0,0);
  if ((iVar1 == -0x7789f798) &&
     (iVar1 = (**(code **)(*DAT_0073636c + 0xc))(DAT_0073636c), iVar1 == -0x7789f797)) {
    Device_HandleLost();
  }
  if (DAT_0078eb88 != 0) {
    DAT_0078eb88 = 0;
  }
  puVar2 = &DAT_0071b1d8;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if (DAT_0078eb84 != 0) {
    Effects_CreateAll();
    DAT_0078eb84 = 0;
  }
  Particles_UpdateSystem(gParticleSystemA,0x3c888889);
  TexAnim__Update();
  (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,7,0,0x3f800000,0);
  DynamicFrameMemory_Swap();
  FrameLists_Recycle();
  DAT_007364dc = DAT_007364dc + 1;
  DAT_007363e8 = 0;
  DAT_007363ec = 0;
  Input__DropUnpluggedWheels();
  Input__AssignNewWheels();
  Input__SelectActionMapForGameState();
  DAT_00736514 = 0;
  DAT_00736515 = 0;
  EZWheel__Poll();
  DAT_0073650c = 1;
  FUN_004130d0(&DAT_00706498,0);
  FUN_0041e670();
  RenderSetupBlurFlags();
  return;
}


// ==== 0x40a7f0 SetBlurCameraObject

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (C) docs/re/blur.md */

void SetBlurCameraObject(void)

{
  DAT_007404a0 = &DAT_0078d500;
  _DAT_007404b8 = &DAT_0071aa84;
  DAT_00740468 = 1;
  DAT_00740500 = gCameraObj;
  DAT_00740518 = &DAT_0071aa4c;
  DAT_007404c8 = 1;
  DAT_00740560 = &DAT_0078d810;
  _DAT_007407a0 = &DAT_0078ccd0;
  _DAT_007407b8 = &DAT_0071aa30;
  DAT_00740768 = 1;
  _DAT_007405c0 = &DAT_0078cfa0;
  DAT_007405d8 = &DAT_0071aaa0;
  DAT_00740588 = 1;
  DAT_00740638 = &DAT_0071aa68;
  _DAT_00740620 = gCameraObj;
  DAT_007405e8 = 1;
  return;
}


// ==== 0x40a880 NullUpdate_ret

/* [canon] camera V (C) docs/re/camera.md */

void NullUpdate_ret(void)

{
  return;
}


// ==== 0x40a890 SceneRTCreate

/* [canon] render V (G+C) docs/re/blur.md */

void SceneRTCreate(void)

{
  if (DAT_00700e90 == 0) {
    DAT_0071aa28 = (int *)0x0;
    DAT_0071ab68 = 0;
    DAT_0071ab64 = 0;
  }
  else {
    (**(code **)(*DAT_0073636c + 0x5c))(DAT_0073636c,0x140,0xf0,1,1,DAT_00702a94,0,&DAT_0071aa28,0);
    (**(code **)(*DAT_0071aa28 + 0x48))(DAT_0071aa28,0,&DAT_0071ab68);
    (**(code **)(*DAT_0073636c + 0x74))(DAT_0073636c,0x140,0xf0,DAT_00702a98,0,0,0,&DAT_0071ab64,0);
  }
  if (DAT_0073645c == 1) {
    (**(code **)(*DAT_0073636c + 0x5c))
              (DAT_0073636c,DAT_00701034,DAT_00701038,1,1,DAT_00702a80,0,&DAT_00736460,0);
    (**(code **)(*DAT_00736460 + 0x48))(DAT_00736460,0,&DAT_00736464);
    (**(code **)(*DAT_0073636c + 0x94))(DAT_0073636c,0,DAT_00736464);
    (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,1,0,0,0);
  }
  else {
    DAT_00736460 = (int *)0x0;
    (**(code **)(*DAT_0073636c + 0x48))(DAT_0073636c,0,0,0,&DAT_00736464);
  }
  (**(code **)(*DAT_0073636c + 0xa0))(DAT_0073636c,&DAT_00736468);
  (**(code **)(*DAT_0073636c + 0x48))(DAT_0073636c,0,0,0,&DAT_00736374);
  (**(code **)(*DAT_0073636c + 0x5c))
            (DAT_0073636c,DAT_00702a9c,DAT_00702aa0,1,1,DAT_00702a94,0,&DAT_00736470,0);
  (**(code **)(*DAT_00736470 + 0x48))(DAT_00736470,0,&DAT_00736474);
  (**(code **)(*DAT_0073636c + 0x74))
            (DAT_0073636c,DAT_00702a9c,DAT_00702aa0,DAT_00702a98,0,0,0,&DAT_00736478,0);
  return;
}


// ==== 0x40aa20 RenderTargetTable_Init

/* [canon] render med (ghidra+capstone) docs/re/render.md */

void RenderTargetTable_Init(void)

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
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  
  iVar18 = 0;
  uVar13 = DAT_00702a84;
  do {
    (&DAT_0071aa30)[iVar18 * 7] = iVar18;
    uVar12 = DAT_00736478;
    piVar11 = DAT_0073636c;
    uVar10 = DAT_0071ab98;
    uVar9 = DAT_0071ab94;
    uVar8 = DAT_0071ab90;
    uVar7 = DAT_0071ab8c;
    uVar6 = DAT_0071ab88;
    uVar14 = DAT_0071ab84;
    uVar5 = DAT_0071ab80;
    uVar4 = DAT_0071ab7c;
    uVar3 = DAT_0071ab78;
    uVar2 = DAT_0071ab74;
    uVar1 = DAT_0071ab70;
    uVar16 = DAT_0071ab6c;
    uVar17 = DAT_0071ab68;
    uVar15 = DAT_0071ab64;
    switch(iVar18) {
    case 0:
      (&DAT_0071aa38)[iVar18 * 7] = DAT_00736374;
      goto LAB_0040aa55;
    case 1:
      (&DAT_0071aa38)[iVar18 * 7] = DAT_00736464;
LAB_0040aa55:
      (**(code **)(*DAT_0073636c + 0xa0))(DAT_0073636c,&DAT_0071aa3c + iVar18 * 7);
      (&DAT_0071aa34)[iVar18 * 7] = 1;
LAB_0040aa99:
      uVar15 = DAT_00701038;
      (&DAT_0071aa44)[iVar18 * 7] = DAT_00701034;
      uVar13 = DAT_00702a84;
      (&DAT_0071aa48)[iVar18 * 7] = uVar15;
      goto LAB_0040ab92;
    case 2:
      (&DAT_0071aa34)[iVar18 * 7] = 4;
      (&DAT_0071aa44)[iVar18 * 7] = 0x140;
      (&DAT_0071aa48)[iVar18 * 7] = 0xf0;
      goto LAB_0040ab8c;
    case 3:
      (&DAT_0071aa38)[iVar18 * 7] = DAT_00736374;
      (**(code **)(*piVar11 + 0xa0))(piVar11,&DAT_0071aa3c + iVar18 * 7);
      (&DAT_0071aa34)[iVar18 * 7] = 0;
      goto LAB_0040aa99;
    case 4:
      (&DAT_0071aa38)[iVar18 * 7] = DAT_00736474;
      uVar15 = DAT_00702a9c;
      (&DAT_0071aa3c)[iVar18 * 7] = uVar12;
      uVar17 = DAT_00702aa0;
      (&DAT_0071aa34)[iVar18 * 7] = 3;
      (&DAT_0071aa44)[iVar18 * 7] = uVar15;
      (&DAT_0071aa48)[iVar18 * 7] = uVar17;
      goto LAB_0040ab92;
    case 5:
      (&DAT_0071aa34)[iVar18 * 7] = 0xb;
      break;
    case 6:
      (&DAT_0071aa34)[iVar18 * 7] = 0xd;
      uVar14 = uVar6;
      uVar16 = uVar1;
      break;
    case 7:
      (&DAT_0071aa34)[iVar18 * 7] = 0xe;
      uVar14 = uVar7;
      uVar16 = uVar2;
      break;
    case 8:
      (&DAT_0071aa34)[iVar18 * 7] = 0xf;
      uVar14 = uVar8;
      uVar16 = uVar3;
      break;
    case 9:
      (&DAT_0071aa34)[iVar18 * 7] = 10;
      uVar14 = uVar9;
      uVar16 = uVar4;
      break;
    case 10:
      (&DAT_0071aa34)[iVar18 * 7] = 0xc;
      uVar14 = uVar10;
      uVar16 = uVar5;
      break;
    default:
      goto switchD_0040aa46_default;
    }
    (&DAT_0071aa44)[iVar18 * 7] = uVar13;
    (&DAT_0071aa48)[iVar18 * 7] = uVar13;
    uVar15 = uVar14;
    uVar17 = uVar16;
LAB_0040ab8c:
    (&DAT_0071aa38)[iVar18 * 7] = uVar17;
    (&DAT_0071aa3c)[iVar18 * 7] = uVar15;
LAB_0040ab92:
    (&DAT_0071aa40)[iVar18 * 7] = 1;
switchD_0040aa46_default:
    iVar18 = iVar18 + 1;
    if (10 < iVar18) {
      return;
    }
  } while( true );
}


// ==== 0x40abd0 SceneRTSelect

/* [canon] render V (C) docs/re/blur.md */

void SceneRTSelect(void)

{
  int unaff_ESI;
  int *piStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_10;
  
  uStack_1c = 0x40abd8;
  FUN_0040ed50();
  uStack_1c = *(undefined4 *)(unaff_ESI + 8);
  uStack_20 = 0;
  piStack_24 = DAT_0073636c;
  uStack_28 = 0x40abec;
  (**(code **)(*DAT_0073636c + 0x94))();
  uStack_28 = *(undefined4 *)(unaff_ESI + 0xc);
  piStack_2c = DAT_0073636c;
  (**(code **)(*DAT_0073636c + 0x9c))();
  if (iStack_10 != 0) {
    (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,7,0xff000000,0x3f800000,0);
  }
  piStack_24 = *(int **)(unaff_ESI + 0x14);
  uStack_20 = *(undefined4 *)(unaff_ESI + 0x18);
  piStack_2c = (int *)0x0;
  uStack_28 = 0;
  uStack_1c = 0;
  uStack_18 = 0x3f800000;
  (**(code **)(*DAT_0073636c + 0xbc))(DAT_0073636c,&piStack_2c);
  DAT_00736458 = unaff_ESI;
  DAT_0073640c = 0;
  return;
}


// ==== 0x40ac80 RenderViews_InitLists

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+ghidra) docs/re/render.md */

void RenderViews_InitLists(void)

{
  _DAT_007408c0 = &DAT_0078bd70;
  DAT_007408d8 = &DAT_0071aabc;
  DAT_00740888 = 1;
  _DAT_0078bd50 = &DAT_00740880;
  _DAT_00740980 = &DAT_0078c000;
  _DAT_00740998 = &DAT_0071aad8;
  DAT_00740948 = 1;
  _DAT_0078bd54 = &DAT_00740940;
  _DAT_007409e0 = &DAT_0078c290;
  _DAT_007409f8 = &DAT_0071aaf4;
  DAT_007409a8 = 1;
  _DAT_0078bd58 = &DAT_007409a0;
  _DAT_00740a40 = &DAT_0078c520;
  _DAT_00740a58 = &DAT_0071ab10;
  DAT_00740a08 = 1;
  _DAT_0078bd5c = &DAT_00740a00;
  _DAT_00740860 = &DAT_0078c7b0;
  DAT_00740878 = &DAT_0071ab2c;
  DAT_00740828 = 1;
  _DAT_0078bd60 = &DAT_00740820;
  _DAT_00740920 = &DAT_0078ca40;
  _DAT_00740938 = &DAT_0071ab48;
  DAT_007408e8 = 1;
  _DAT_0078bd64 = &DAT_007408e0;
  return;
}


// ==== 0x40ad60 View_BuildMatrices

/* [canon] render med (hopper+ghidra) docs/re/render.md */

void View_BuildMatrices(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  int iVar8;
  undefined *apuStack_1ac [3];
  int iStack_15c;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined1 auStack_e4 [4];
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8 [2];
  undefined1 local_d0 [8];
  undefined4 uStack_c8;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 auStack_98 [20];
  undefined4 local_84;
  undefined4 local_74;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [12];
  undefined4 local_44;
  undefined4 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  apuStack_1ac[2] = &DAT_007064d0;
  local_e0 = 0;
  local_dc = 0;
  local_d8[0] = 0;
  local_f0 = 0x3f800000;
  local_ec = 0;
  local_e8 = 0;
  apuStack_1ac[1] = (undefined *)0x40add3;
  Matrix4_BuildLookAt();
  apuStack_1ac[1] = &DAT_007064d0;
  local_44 = 0;
  local_34 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0x3f800000;
  apuStack_1ac[0] = (undefined *)0x40ae36;
  Matrix4_BuildLookAt();
  local_84 = 0;
  local_74 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0x3f800000;
  apuStack_1ac[2] = (undefined *)0x40ae97;
  bMatrixCopy_b();
  apuStack_1ac[2] = local_50;
  apuStack_1ac[1] = local_d0;
  apuStack_1ac[0] = (undefined *)0x40aeac;
  D3DXMatrixTranspose();
  apuStack_1ac[0] = (undefined *)local_d8;
  D3DXMatrixMultiply(local_d8,auStack_98);
  local_d8[0] = 0;
  uStack_c8 = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  uStack_a8 = 0x3f800000;
  D3DXMatrixTranspose(auStack_e4,auStack_e4);
  uVar3 = DAT_00702aa8;
  uVar2 = DAT_00702aa4;
  iStack_15c = 6;
  piVar4 = (int *)(&DAT_00702ac0 +
                  (DAT_007364dc % *(uint *)(DAT_00700e74 * 4 + 0x702aac) +
                  (DAT_00700e74 * 3 + -3) * 2) * 0x18);
  param_1 = param_1 - (int)piVar4;
  do {
    iVar5 = *(int *)(param_1 + (int)piVar4);
    if (iVar5 != 0) {
      *(bool *)(iVar5 + 8) = *piVar4 != 0;
      iVar8 = *(int *)(iVar5 + 0x40);
      if (iVar8 != 0) {
        puVar1 = *(undefined4 **)(iVar5 + 0x58);
        puVar6 = DAT_00740500;
        ppuVar7 = apuStack_1ac;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppuVar7 = (undefined *)*puVar6;
          puVar6 = puVar6 + 1;
          ppuVar7 = ppuVar7 + 1;
        }
        uStack_14c = 0x3f800000;
        uStack_148 = 0;
        uStack_144 = 0;
        uStack_140 = 0;
        uStack_13c = 0;
        uStack_134 = 0;
        uStack_130 = 0;
        uStack_12c = 0;
        uStack_128 = 0;
        uStack_124 = 0x3f800000;
        uStack_120 = 0;
        uStack_11c = 0;
        uStack_118 = 0;
        uStack_114 = 0;
        uStack_110 = 0x3f800000;
        uStack_138 = 0xbf800000;
        switch(*puVar1) {
        case 5:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          break;
        case 6:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          break;
        case 7:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          FUN_0040b990(apuStack_1ac,apuStack_1ac);
          break;
        case 8:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          FUN_0040b990(apuStack_1ac,apuStack_1ac);
          break;
        case 9:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          break;
        case 10:
          FUN_0040ba40(apuStack_1ac,apuStack_1ac);
          D3DXMatrixMultiply(apuStack_1ac,apuStack_1ac,&uStack_14c);
          break;
        default:
          ppuVar7 = apuStack_1ac;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppuVar7 = (undefined *)0x0;
            ppuVar7 = ppuVar7 + 1;
          }
        }
        Camera__SetCameraMatrix(iVar8,apuStack_1ac,DAT_0073ad38);
        iVar5 = DAT_00735f5c;
        if (DAT_00735f5c == 0) {
          *(undefined4 *)(iVar8 + 0x284) = 0;
          *(undefined4 *)(iVar8 + 0xb4) = 0;
        }
        *(undefined4 *)(iVar8 + 0xbc) = uVar2;
        *(undefined4 *)(iVar8 + 0xc0) = uVar3;
        if (iVar5 == 0) {
          *(undefined2 *)(iVar8 + 0xc4) = DAT_0078bd40;
        }
      }
    }
    piVar4 = piVar4 + 1;
    iStack_15c = iStack_15c + -1;
  } while (iStack_15c != 0);
  return;
}


// ==== 0x40b340 ReflectionCube_Create

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void ReflectionCube_Create(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_00700e74 != 0) {
    (**(code **)(*DAT_0073636c + 100))(DAT_0073636c,DAT_00702a84,1,1,DAT_00702a88,0,&DAT_0073646c,0)
    ;
    iVar1 = 0;
    do {
      (**(code **)(*DAT_0073646c + 0x48))(DAT_0073646c,iVar1,0,&DAT_0071ab6c + iVar1);
      (**(code **)(*DAT_0073646c + 8))(DAT_0073646c);
      (**(code **)(*DAT_0073636c + 0x74))
                (DAT_0073636c,DAT_00702a84,DAT_00702a84,DAT_00702a8c,0,0,0,&DAT_0071ab84 + iVar1,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
    return;
  }
  puVar2 = &DAT_0071ab84;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_0071ab6c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_0073646c = (int *)0x0;
  return;
}


// ==== 0x40b3f0 RenderSetupBlurFlags

/* [canon] render V (G+C) docs/re/blur.md */

void RenderSetupBlurFlags(void)

{
  bool bVar1;
  
  bVar1 = false;
  if ((DAT_00700e98 == 0) && (DAT_00700e9c == 0)) {
    if (DAT_00736384 != 0) {
LAB_0040b415:
      bVar1 = DAT_0073645c == 0;
      DAT_0073645c = (uint)bVar1;
      DAT_00736384 = (uint)bVar1;
      bVar1 = true;
    }
  }
  else if (DAT_00736384 == 0) goto LAB_0040b415;
  if (DAT_00700e90 == 0) {
    if (DAT_0071ab68 != 0) {
LAB_0040b45b:
      bVar1 = true;
    }
  }
  else if (DAT_0071ab68 == 0) goto LAB_0040b45b;
  if (DAT_00700e74 == 0) {
    if (DAT_0073646c != 0) goto LAB_0040b479;
LAB_0040b475:
    if (bVar1) goto LAB_0040b479;
  }
  else {
    if (DAT_0073646c != 0) goto LAB_0040b475;
LAB_0040b479:
    ReleaseSceneRTs();
    SceneRTCreate();
    ReflectionCube_Create();
    RenderTargetTable_Init();
  }
  bVar1 = false;
  if (DAT_00700e9c == 0) {
    if (DAT_0071aba4 != 0) goto LAB_0040b4a9;
  }
  else if (DAT_0071aba4 == 0) {
LAB_0040b4a9:
    bVar1 = true;
  }
  if (DAT_00700e98 == 0) {
    if (DAT_0071ab9c != 0) goto LAB_0040b4c7;
  }
  else if (DAT_0071ab9c == 0) goto LAB_0040b4c7;
  if (!bVar1) {
    return;
  }
LAB_0040b4c7:
  BlurReleaseRTs();
  BlurCreateRTs();
  return;
}


// ==== 0x40b4e0 ReleaseSceneRTs

/* [canon] render I (C) docs/re/blur.md */

void ReleaseSceneRTs(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar2 = &DAT_0071aa3c;
  do {
    puVar2[-3] = iVar4;
    if ((0x71aa3b < (int)puVar2) &&
       (((int)puVar2 < 0x71aa59 || (puVar2 == (undefined4 *)&DAT_0071aa90)))) {
      (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2);
    }
    puVar2 = puVar2 + 7;
    iVar4 = iVar4 + 1;
  } while ((int)puVar2 < 0x71ab70);
  piVar3 = &DAT_0071ab84;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x71ab9c);
  if (DAT_0073646c != (int *)0x0) {
    (**(code **)(*DAT_0073646c + 8))(DAT_0073646c);
  }
  if (DAT_00736460 != (int *)0x0) {
    (**(code **)(*DAT_00736460 + 8))(DAT_00736460);
  }
  if (DAT_00736464 != (int *)0x0) {
    (**(code **)(*DAT_00736464 + 8))(DAT_00736464);
  }
  if (DAT_00736468 != (int *)0x0) {
    (**(code **)(*DAT_00736468 + 8))(DAT_00736468);
  }
  (**(code **)(*DAT_00736374 + 8))(DAT_00736374);
  if (DAT_0071ab64 != (int *)0x0) {
    (**(code **)(*DAT_0071ab64 + 8))(DAT_0071ab64);
  }
  if (DAT_0071ab68 != (int *)0x0) {
    (**(code **)(*DAT_0071ab68 + 8))(DAT_0071ab68);
  }
  if (DAT_0071aa28 != (int *)0x0) {
    (**(code **)(*DAT_0071aa28 + 8))(DAT_0071aa28);
  }
  if (DAT_00736478 != (int *)0x0) {
    (**(code **)(*DAT_00736478 + 8))(DAT_00736478);
  }
  if (DAT_00736474 != (int *)0x0) {
    (**(code **)(*DAT_00736474 + 8))(DAT_00736474);
  }
  if (DAT_00736470 != (int *)0x0) {
    (**(code **)(*DAT_00736470 + 8))(DAT_00736470);
  }
  return;
}


// ==== 0x40b5e0 ViewMatrix_InitIdentity

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra) docs/re/render.md */

void ViewMatrix_InitIdentity(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0078bd00;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _DAT_0078bcc0 = 0x3f800000;
  _DAT_0078bcc4 = 0;
  _DAT_0078bcc8 = 0;
  _DAT_0078bccc = 0;
  _DAT_0078bcd0 = 0;
  _DAT_0078bcd4 = 0x3f800000;
  _DAT_0078bcd8 = 0;
  _DAT_0078bcdc = 0;
  _DAT_0078bce0 = 0;
  _DAT_0078bce4 = 0;
  _DAT_0078bce8 = 0x3f800000;
  _DAT_0078bcec = 0;
  _DAT_0078bcf0 = 0;
  _DAT_0078bcf4 = 0;
  _DAT_0078bcf8 = 0;
  _DAT_0078bcfc = 0x3f800000;
  return;
}


// ==== 0x40b6a0 FUN_0040b6a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b6a0(void)

{
  float fVar1;
  float fVar2;
  float *extraout_EDX;
  float *unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar3 = (float10)FUN_00564b10();
  fVar1 = (float)fVar3;
  fVar3 = (float10)FUN_00564b10();
  fVar4 = (float10)_K_ONE - (float10)fVar1;
  fVar2 = unaff_ESI[2];
  fVar5 = (float10)*unaff_ESI;
  fVar6 = (float10)unaff_ESI[1];
  extraout_EDX[3] = 0.0;
  fVar7 = fVar5 * fVar4;
  extraout_EDX[7] = 0.0;
  extraout_EDX[0xb] = 0.0;
  extraout_EDX[0xc] = 0.0;
  extraout_EDX[0xd] = 0.0;
  extraout_EDX[0xe] = 0.0;
  extraout_EDX[0xf] = 1.0;
  *extraout_EDX = (float)(fVar7 * fVar5 + (float10)fVar1);
  extraout_EDX[1] = (float)(fVar7 * fVar6 - (float10)fVar2 * fVar3);
  extraout_EDX[2] = (float)(fVar6 * fVar3 + (float10)(float)(fVar7 * (float10)fVar2));
  extraout_EDX[4] = (float)((float10)fVar2 * fVar3 + fVar7 * fVar6);
  extraout_EDX[5] = (float)((float10)(float)(fVar6 * fVar4) * fVar6 + (float10)fVar1);
  fVar8 = (float10)(float)(fVar6 * fVar4) * (float10)fVar2;
  extraout_EDX[6] = (float)(fVar8 - fVar5 * fVar3);
  extraout_EDX[8] = (float)(fVar7 * (float10)fVar2) - (float)(fVar6 * fVar3);
  extraout_EDX[9] = (float)(fVar5 * fVar3 + fVar8);
  extraout_EDX[10] = (float)((float10)fVar2 * (float10)fVar2 * fVar4 + (float10)fVar1);
  return;
}


// ==== 0x40b780 Matrix4_BuildLookAt

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void Matrix4_BuildLookAt(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  float *unaff_ESI;
  float *unaff_EDI;
  
  fVar1 = *in_EAX - *unaff_EDI;
  fVar2 = in_EAX[1] - unaff_EDI[1];
  fVar3 = in_EAX[2] - unaff_EDI[2];
  bNormalize3();
  fVar5 = fVar3 * -param_1[1] - -param_1[2] * fVar2;
  fVar6 = -param_1[2] * fVar1 - fVar3 * -*param_1;
  fVar4 = fVar2 * -*param_1 - -param_1[1] * fVar1;
  bNormalize3();
  bNormalize3();
  *unaff_ESI = fVar5;
  unaff_ESI[1] = fVar4 * fVar2 - fVar3 * fVar6;
  unaff_ESI[2] = fVar1;
  unaff_ESI[4] = fVar6;
  unaff_ESI[5] = fVar3 * fVar5 - fVar4 * fVar1;
  unaff_ESI[6] = fVar2;
  unaff_ESI[8] = fVar4;
  unaff_ESI[3] = 0.0;
  unaff_ESI[7] = 0.0;
  unaff_ESI[0xb] = 0.0;
  unaff_ESI[0xc] = 0.0;
  unaff_ESI[0xd] = 0.0;
  unaff_ESI[0xe] = 0.0;
  unaff_ESI[9] = fVar6 * fVar1 - fVar2 * fVar5;
  unaff_ESI[10] = fVar3;
  unaff_ESI[0xf] = 1.0;
  D3DXMatrixMultiply();
  return;
}


// ==== 0x40b930 FUN_0040b930

void __fastcall FUN_0040b930(undefined4 param_1)

{
  float *extraout_EDX;
  float10 fVar1;
  float fVar2;
  
  fVar1 = (float10)FUN_00564b10(param_1);
  fVar2 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10();
  extraout_EDX[1] = (float)fVar1;
  extraout_EDX[4] = (float)-fVar1;
  *extraout_EDX = fVar2;
  extraout_EDX[5] = fVar2;
  extraout_EDX[2] = 0.0;
  extraout_EDX[3] = 0.0;
  extraout_EDX[6] = 0.0;
  extraout_EDX[7] = 0.0;
  extraout_EDX[8] = 0.0;
  extraout_EDX[9] = 0.0;
  extraout_EDX[10] = 1.0;
  extraout_EDX[0xb] = 0.0;
  extraout_EDX[0xc] = 0.0;
  extraout_EDX[0xd] = 0.0;
  extraout_EDX[0xe] = 0.0;
  extraout_EDX[0xf] = 1.0;
  return;
}


// ==== 0x40b990 FUN_0040b990

void FUN_0040b990(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  float10 fVar2;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  fVar1 = (float10)FUN_00564b10();
  fVar2 = (float10)FUN_00564b10();
  local_38 = (float)fVar2;
  local_2c = (float)-fVar2;
  local_50 = 0x3f800000;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_34 = 0;
  local_30 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0x3f800000;
  local_3c = (float)fVar1;
  local_28 = (float)fVar1;
  D3DXMatrixMultiply(param_1,param_2,&local_50);
  return;
}


// ==== 0x40ba40 FUN_0040ba40

void FUN_0040ba40(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  float10 fVar2;
  float local_50 [3];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  fVar1 = (float10)FUN_00564b10();
  fVar2 = (float10)FUN_00564b10();
  local_50[2] = (float)-fVar2;
  local_30 = (float)fVar2;
  local_50[1] = 0.0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0x3f800000;
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0x3f800000;
  local_50[0] = (float)fVar1;
  local_28 = (float)fVar1;
  D3DXMatrixMultiply(param_1,param_2,local_50);
  return;
}


// ==== 0x40baf0 FUN_0040baf0

void FUN_0040baf0(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_50 [76];
  
  FUN_0040b930();
  D3DXMatrixMultiply(param_1,param_2,local_50);
  return;
}


// ==== 0x40bb20 FUN_0040bb20

void FUN_0040bb20(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
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
  
  local_20 = *in_EAX;
  local_1c = in_EAX[1];
  local_18 = in_EAX[2];
  local_50 = 0x3f800000;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0x3f800000;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_24 = 0;
  local_14 = 0x3f800000;
  D3DXMatrixMultiply(param_1,param_2,&local_50);
  return;
}


// ==== 0x40bbc0 FUN_0040bbc0

void __fastcall FUN_0040bbc0(undefined4 param_1,undefined4 *param_2)

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
  in_EAX[0xc] = *param_2;
  in_EAX[0xd] = param_2[1];
  in_EAX[0xe] = param_2[2];
  in_EAX[0xf] = 0x3f800000;
  return;
}


// ==== 0x40bc10 Matrix_InvertRigid

/* [canon] render med (ghidra-canon+capstone) docs/re/render.md */

void Matrix_InvertRigid(void)

{
  D3DXMatrixMultiply();
  return;
}


// ==== 0x40bd40 FUN_0040bd40

void FUN_0040bd40(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int extraout_EDX;
  float *unaff_ESI;
  float local_40;
  float local_3c;
  float local_38;
  float local_24;
  float local_14;
  
  bNormalize3();
  fVar1 = local_3c * *(float *)(extraout_EDX + 0x18) - local_38 * *(float *)(extraout_EDX + 0x14);
  fVar2 = local_38 * *(float *)(extraout_EDX + 0x10) - local_40 * *(float *)(extraout_EDX + 0x18);
  fVar3 = local_40 * *(float *)(extraout_EDX + 0x14) - local_3c * *(float *)(extraout_EDX + 0x10);
  bNormalize3();
  *unaff_ESI = local_40;
  unaff_ESI[1] = local_3c;
  unaff_ESI[2] = local_38;
  unaff_ESI[7] = local_14;
  unaff_ESI[4] = local_38 * fVar2 - fVar3 * local_3c;
  unaff_ESI[6] = local_3c * fVar1 - fVar2 * local_40;
  unaff_ESI[5] = fVar3 * local_40 - local_38 * fVar1;
  unaff_ESI[8] = fVar1;
  unaff_ESI[9] = fVar2;
  unaff_ESI[10] = fVar3;
  unaff_ESI[0xb] = local_24;
  unaff_ESI[3] = 0.0;
  unaff_ESI[7] = 0.0;
  unaff_ESI[0xb] = 0.0;
  unaff_ESI[0xc] = 0.0;
  unaff_ESI[0xd] = 0.0;
  unaff_ESI[0xe] = 0.0;
  unaff_ESI[0xf] = 1.0;
  return;
}


// ==== 0x40be40 FUN_0040be40

void FUN_0040be40(void)

{
  int unaff_ESI;
  
  D3DXMatrixTranspose();
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  return;
}


// ==== 0x40be70 FUN_0040be70

void __fastcall FUN_0040be70(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0x42800000;
  *(undefined4 *)(param_1 + 0x30) = 0x42800000;
  *(undefined4 *)(param_1 + 0x34) = 0x42800000;
  *(undefined4 *)(param_1 + 0x44) = 0x42800000;
  *(undefined4 *)(param_1 + 0x80) = 0x80808080;
  *(undefined4 *)(param_1 + 0x84) = 0x80808080;
  *(undefined4 *)(param_1 + 0x88) = 0x80808080;
  *(undefined4 *)(param_1 + 0x8c) = 0x80808080;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x68) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x6c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x7c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x90) = 0;
  return;
}


// ==== 0x40bef0 FUN_0040bef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040bef0(int param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int unaff_ESI;
  undefined4 uVar3;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  float local_c0;
  float local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_d0 = *(float *)(in_EAX + 0x10) * 0.003125 - _K_ONE;
  local_c8 = 0x3f800000;
  local_a8 = 0x3f800000;
  local_88 = 0x3f800000;
  local_c4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x83),
                                        *(undefined1 *)(in_EAX + 0x80)),
                               *(undefined1 *)(in_EAX + 0x81)),*(undefined1 *)(in_EAX + 0x82));
  local_c0 = *(float *)(in_EAX + 0x50);
  local_bc = *(float *)(in_EAX + 0x54);
  local_b8 = *(undefined4 *)(in_EAX + 0x58);
  local_cc = -(*(float *)(in_EAX + 0x14) * 0.004166667 - _K_ONE);
  local_b0 = *(float *)(in_EAX + 0x20) * 0.003125 - _K_ONE;
  local_a4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x87),
                                        *(undefined1 *)(in_EAX + 0x84)),
                               *(undefined1 *)(in_EAX + 0x85)),*(undefined1 *)(in_EAX + 0x86));
  local_a0 = *(float *)(in_EAX + 0x5c);
  local_9c = *(float *)(in_EAX + 0x60);
  local_98 = *(undefined4 *)(in_EAX + 100);
  local_ac = -(*(float *)(in_EAX + 0x24) * 0.004166667 - _K_ONE);
  local_90 = *(float *)(in_EAX + 0x30) * 0.003125 - _K_ONE;
  local_84 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x8b),
                                        *(undefined1 *)(in_EAX + 0x88)),
                               *(undefined1 *)(in_EAX + 0x89)),*(undefined1 *)(in_EAX + 0x8a));
  local_80 = *(float *)(in_EAX + 0x68);
  local_7c = *(float *)(in_EAX + 0x6c);
  local_8c = -(*(float *)(in_EAX + 0x34) * 0.004166667 - _K_ONE);
  local_78 = *(undefined4 *)(in_EAX + 0x70);
  local_70 = *(float *)(in_EAX + 0x40) * 0.003125 - _K_ONE;
  local_68 = 0x3f800000;
  local_6c = -(*(float *)(in_EAX + 0x44) * 0.004166667 - _K_ONE);
  local_64 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x8f),
                                        *(undefined1 *)(in_EAX + 0x8c)),
                               *(undefined1 *)(in_EAX + 0x8d)),*(undefined1 *)(in_EAX + 0x8e));
  local_60 = *(float *)(in_EAX + 0x74);
  local_5c = *(float *)(in_EAX + 0x78);
  local_58 = *(undefined4 *)(in_EAX + 0x7c);
  local_b4 = local_b8;
  local_94 = local_98;
  local_74 = local_78;
  local_54 = local_58;
  if (param_1 != 0) {
    if (unaff_ESI != 0x61) {
      fVar1 = _K_HALF / (float)(int)*(short *)(param_1 + 0x44);
      local_c0 = local_c0 + fVar1;
      fVar2 = _K_HALF / (float)(int)*(short *)(param_1 + 0x46);
      local_bc = local_bc + fVar2;
      local_a0 = local_a0 - fVar1;
      local_9c = local_9c + fVar2;
      local_80 = local_80 - fVar1;
      local_7c = local_7c - fVar2;
      local_60 = fVar1 + local_60;
      local_5c = local_5c - fVar2;
    }
    FUN_0040f3d0(param_1);
  }
  if (DAT_00736450 != 0) {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x40),DAT_00736450);
  }
  if (unaff_ESI == 0x61) {
    if (*(int *)(DAT_0073640c + 0xc) == 0) {
      (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,0,0x18,0x100);
      uVar3 = 0x20142;
    }
    else {
      (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,0,0x18,0x103);
      uVar3 = 0x10142;
    }
    (**(code **)(*DAT_0073636c + 0x164))(DAT_0073636c,uVar3);
    local_68 = 0x3f800000;
    local_64 = 0;
    local_60 = 0.0;
    local_5c = 0.0;
    local_58 = 0;
    local_54 = 0x3f800000;
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0x3f800000;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0x3f800000;
    (**(code **)(*DAT_0073636c + 0xb0))(DAT_0073636c,0x10,&local_68);
  }
  DAT_007363e8 = 0;
  (**(code **)(*DAT_0073636c + 0x14c))(DAT_0073636c,6,2,&local_d0,0x20);
  if (unaff_ESI == 0x61) {
    (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,0,0x18,2);
  }
  return;
}


// ==== 0x40c300 FUN_0040c300

void FUN_0040c300(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_7c = *(undefined4 *)(in_EAX + 0x14);
  local_80 = *(undefined4 *)(in_EAX + 0x10);
  local_78 = *(undefined4 *)(in_EAX + 0x18);
  local_74 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x83),
                                        *(undefined1 *)(in_EAX + 0x80)),
                               *(undefined1 *)(in_EAX + 0x81)),*(undefined1 *)(in_EAX + 0x82));
  local_6c = *(undefined4 *)(in_EAX + 0x54);
  local_5c = *(undefined4 *)(in_EAX + 0x24);
  local_70 = *(undefined4 *)(in_EAX + 0x50);
  local_60 = *(undefined4 *)(in_EAX + 0x20);
  local_58 = *(undefined4 *)(in_EAX + 0x28);
  local_54 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x87),
                                        *(undefined1 *)(in_EAX + 0x84)),
                               *(undefined1 *)(in_EAX + 0x85)),*(undefined1 *)(in_EAX + 0x86));
  local_4c = *(undefined4 *)(in_EAX + 0x60);
  local_3c = *(undefined4 *)(in_EAX + 0x34);
  local_50 = *(undefined4 *)(in_EAX + 0x5c);
  local_40 = *(undefined4 *)(in_EAX + 0x30);
  local_38 = *(undefined4 *)(in_EAX + 0x38);
  local_34 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x8b),
                                        *(undefined1 *)(in_EAX + 0x88)),
                               *(undefined1 *)(in_EAX + 0x89)),*(undefined1 *)(in_EAX + 0x8a));
  local_2c = *(undefined4 *)(in_EAX + 0x6c);
  local_1c = *(undefined4 *)(in_EAX + 0x44);
  local_30 = *(undefined4 *)(in_EAX + 0x68);
  local_20 = *(undefined4 *)(in_EAX + 0x40);
  local_18 = *(undefined4 *)(in_EAX + 0x48);
  local_14 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x8f),
                                        *(undefined1 *)(in_EAX + 0x8c)),
                               *(undefined1 *)(in_EAX + 0x8d)),*(undefined1 *)(in_EAX + 0x8e));
  local_c = *(undefined4 *)(in_EAX + 0x78);
  local_10 = *(undefined4 *)(in_EAX + 0x74);
  FUN_0040f3d0(param_1);
  Device_SetWorldMatrix(param_2);
  if (DAT_00736450 != 0) {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x40),DAT_00736450);
  }
  DAT_007363e8 = 0;
  (**(code **)(*DAT_0073636c + 0x14c))(DAT_0073636c,6,2,&local_80,0x20);
  return;
}


// ==== 0x40c4b0 LightPack_ChunkDispatch

/* [canon] assets high (hopper+capstone) docs/re/misc.md */

void __fastcall LightPack_ChunkDispatch(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_00702a78;
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x89f23a15) {
    if (uVar1 == 0x89f23a14) {
LAB_0040c55e:
      *(undefined4 *)(param_1 + 0x50) = DAT_00702a58;
      *(undefined4 *)(param_1 + 0x54) = DAT_00702a68;
      return;
    }
    if (uVar1 < 0x3ed70c44) {
      if (uVar1 == 0x3ed70c43) {
LAB_0040c53a:
        *(undefined4 *)(param_1 + 0x50) = DAT_00702a54;
        *(undefined4 *)(param_1 + 0x54) = DAT_00702a64;
        return;
      }
      if (uVar1 < 0x23e6a3f5) {
        if (uVar1 != 0x23e6a3f4) {
          if (uVar1 == 0x12c9453c) goto LAB_0040c53a;
          if (uVar1 != 0x2388dd82) {
            return;
          }
        }
      }
      else if (uVar1 != 0x23e6b396) {
        if (uVar1 != 0x33a26cb6) {
          return;
        }
        goto LAB_0040c50c;
      }
    }
    else if (uVar1 < 0x8050ca40) {
      if (uVar1 == 0x8050ca3f) goto LAB_0040c5e6;
      if (uVar1 == 0x471a1dca) goto LAB_0040c53a;
      if (uVar1 != 0x6cf41096) {
        return;
      }
    }
    else if (uVar1 != 0x8062e2c0) {
      if (uVar1 != 0x89946400) {
        return;
      }
      goto LAB_0040c55e;
    }
  }
  else if (uVar1 < 0x8cbe3498) {
    if (uVar1 != 0x8cbe3497) {
      if (uVar1 < 0x8cb694ee) {
        if (uVar1 != 0x8cb694ed) {
          if (uVar1 == 0x8a616c4c) goto LAB_0040c5e6;
          if (uVar1 != 0x8cb61dcd) {
            return;
          }
        }
      }
      else if ((uVar1 != 0x8cb95e6b) && (uVar1 != 0x8cbc02ec)) {
        return;
      }
    }
  }
  else {
    if (0xc9d2b801 < uVar1) {
      if ((uVar1 != 0xd68ea0c1) && (uVar1 != 0xd6ec76d5)) {
        return;
      }
LAB_0040c5e6:
      *(undefined4 *)(param_1 + 0x50) = DAT_00702a5c;
      *(undefined4 *)(param_1 + 0x54) = DAT_00702a6c;
      return;
    }
    if (uVar1 != 0xc9d2b801) {
      if (uVar1 == 0xa6348ee3) {
LAB_0040c50c:
        *(undefined4 *)(param_1 + 0x50) = DAT_00702a74;
        *(undefined4 *)(param_1 + 0x54) = uVar2;
        return;
      }
      if (uVar1 != 0xb3645f81) {
        return;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x50) = DAT_00702a60;
  *(undefined4 *)(param_1 + 0x54) = DAT_00702a70;
  return;
}


// ==== 0x40c600 eLightMaterialPlatInfo_PoolCreate

/* [canon] render high (hopper+ghidra) docs/re/render.md */

void eLightMaterialPlatInfo_PoolCreate(void)

{
  undefined4 *puVar1;
  
  DAT_0073644c = (undefined4 *)FUN_00566dc0(0x80,"eLightMaterialPlatInfoSlotPool",0);
  if (DAT_0073644c == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_0073644c;
    puVar1 = DAT_0073644c;
    DAT_0073644c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0073644c = &DAT_0073d818;
  }
  return;
}


// ==== 0x40c650 FUN_0040c650

void __thiscall FUN_0040c650(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar1 = param_1[1];
  fVar3 = param_1[3];
  fVar2 = param_1[2];
  *in_EAX = param_2 * *param_1;
  in_EAX[1] = fVar1 * param_2;
  in_EAX[2] = fVar2 * param_2;
  in_EAX[3] = fVar3 * param_2;
  return;
}


// ==== 0x40c690 Mesh_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 Mesh_Load(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 uStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  
  iVar2 = *(int *)(in_EAX + 4);
  piVar1 = (int *)(in_EAX + 8);
  puVar7 = (undefined4 *)0x0;
  do {
    if ((int *)(iVar2 + 8 + in_EAX) <= piVar1) {
      return 1;
    }
    iVar3 = *piVar1;
    if (iVar3 == 0x134900) {
      puVar7 = (undefined4 *)((int)piVar1 + 0x17U & 0xfffffff0);
      *param_1 = puVar7;
      *DAT_0078bc44 = puVar7;
      puVar8 = puVar7;
      puVar7[1] = DAT_0078bc44;
      DAT_0078bc44 = puVar8;
      *puVar7 = &DAT_0078bc40;
    }
    else if (iVar3 == 0x134b02) {
      puVar7 = (undefined4 *)*param_1;
      puVar7[5] = (int)piVar1 + 0x17U & 0xfffffff0;
    }
    else if (iVar3 == 0x134b03) {
      puVar7 = (undefined4 *)*param_1;
      puVar7[6] = (int)piVar1 + 0x17U & 0xfffffff0;
      puVar7[7] = (piVar1[1] - ((int)piVar1 + 0x17U & 0xfffffff0)) + 8 + (int)piVar1;
      uStack_20 = 0x40c730;
      FUN_0040c890();
      if (puVar7[7] != 0) {
        uStack_20 = 0;
        uStack_28 = 1;
        puStack_24 = puVar7 + 8;
        (**(code **)(*DAT_0073636c + 0x6c))(DAT_0073636c,puVar7[7],0,0x65);
        piVar4 = (int *)puVar7[8];
        puVar10 = (undefined4 *)0x0;
        (**(code **)(*piVar4 + 0x2c))(piVar4,0,0,&uStack_28);
        uVar6 = puVar7[7];
        puVar8 = (undefined4 *)puVar7[6];
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        piVar4 = (int *)puVar7[8];
LAB_0040c80a:
        (**(code **)(*piVar4 + 0x30))(piVar4);
      }
    }
    else if (iVar3 == 0x134b01) {
      puVar7[0xb] = 0;
      puVar7 = (undefined4 *)*param_1;
      puVar7[10] = (int)piVar1 + 0x87U & 0xffffff80;
      iVar3 = (piVar1[1] - ((int)piVar1 + 0x87U & 0xffffff80)) + 8 + (int)piVar1;
      puVar7[0xc] = iVar3;
      if (puVar7[0xd] != 0) {
        uStack_20 = 0;
        uStack_28 = 1;
        piVar9 = DAT_0073636c;
        puStack_24 = puVar7 + 0xb;
        (**(code **)(*DAT_0073636c + 0x68))(DAT_0073636c,iVar3,0,0);
        piVar4 = (int *)puVar7[0xb];
        (**(code **)(*piVar4 + 0x2c))(piVar4,0,0,&puStack_24,0);
        uVar6 = puVar7[0xc];
        piVar4 = (int *)puVar7[10];
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *piVar9 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar9 = piVar9 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(char *)piVar9 = (char)*piVar4;
          piVar4 = (int *)((int)piVar4 + 1);
          piVar9 = (int *)((int)piVar9 + 1);
        }
        piVar4 = (int *)puVar7[0xb];
        goto LAB_0040c80a;
      }
    }
    piVar1 = (int *)(piVar1[1] + 8 + (int)piVar1);
  } while( true );
}


// ==== 0x40c840 Mesh_Free

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 Mesh_Free(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  piVar2 = (int *)piVar1[0xb];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    piVar1[0xb] = 0;
  }
  piVar2 = (int *)piVar1[8];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    piVar1[8] = 0;
  }
  iVar3 = *piVar1;
  piVar1 = (int *)piVar1[1];
  *piVar1 = iVar3;
  *(int **)(iVar3 + 4) = piVar1;
  *unaff_EDI = 0;
  return 1;
}


// ==== 0x40c890 FUN_0040c890

void __fastcall FUN_0040c890(int param_1)

{
  int in_EAX;
  int *piVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar1 = (int *)(*(int *)(param_1 + 0x14) + 0x34);
    do {
      *piVar1 = (*piVar1 * 2 - in_EAX) + *(int *)(param_1 + 0x18);
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 0xf;
    } while (iVar3 < *(int *)(param_1 + 0x10));
  }
  iVar3 = 0;
  puVar2 = &DAT_00701440;
  while (((*(uint *)(param_1 + 0xc) & *puVar2) == 0 && (*puVar2 != 0))) {
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + 1;
    if (0x70146f < (int)puVar2) {
      *(undefined **)(param_1 + 0x3c) = &DAT_0071aad8;
      return;
    }
  }
  *(undefined4 **)(param_1 + 0x3c) = &DAT_0071abb8 + *(int *)(iVar3 * 0xc + 0x701444) * 0x38;
  return;
}


// ==== 0x40c910 FUN_0040c910

void FUN_0040c910(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  uint in_EAX;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(param_2 + 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (((in_EAX & 0x200) == 0) || (DAT_00700e80 == 0)) {
      if (DAT_00700e90 == 0) {
        *(undefined **)(iVar2 + 0x38) = &DAT_00706898;
      }
    }
    else if (DAT_00700e90 == 0) {
      *(undefined ***)(iVar2 + 0x38) = &PTR_DAT_00706818;
    }
    else {
      *(undefined ***)(iVar2 + 0x38) = &PTR_DAT_00706798;
    }
    local_10 = *(int **)(iVar2 + 0x3c);
    if (*(int *)(iVar2 + 0x38) != 0) {
      piVar4 = *(int **)(*(int *)(iVar2 + 0x38) + *local_10 * 4);
      if (piVar4 != (int *)0x0) {
        local_10 = piVar4;
      }
      *(undefined4 *)(iVar2 + 0x38) = 0;
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      Solid_BindTextureRefs();
    }
    if ((local_10[4] != 0) && (local_8 = 0, 0 < *(int *)(iVar2 + 0x10))) {
      local_c = 0;
      do {
        iVar6 = *(int *)(iVar2 + 0x14) + local_c;
        if (((((in_EAX & 4) != 0) || ((*(byte *)(iVar6 + 0x38) & 1) != 0)) ||
            (iVar3 = AABB_ClassifyAgainstFrustum(param_1), iVar3 != 0)) &&
           (iVar3 = *(int *)(piVar1[0xb] + 4 + (uint)*(byte *)(iVar6 + 0x1c) * 8),
           *(int *)(iVar3 + 0x24) != DAT_0078a4e0)) {
          uVar5 = 0;
          if (*(byte *)(iVar6 + 0x20) != 0xff) {
            uVar5 = *(undefined4 *)(piVar1[0xf] + 4 + (uint)*(byte *)(iVar6 + 0x20) * 8);
          }
          piVar4 = local_10;
          if (((*local_10 == 1) && (1 < (uint)local_10[3])) && (*(char *)(iVar3 + 0x56) != '\0')) {
            piVar4 = &DAT_0071abb8;
          }
          RenderQueue_GetBucketAlt
                    (iVar6,piVar1,*(undefined4 *)(iVar6 + 0x38),piVar4,param_3,param_4,uVar5,param_5
                    );
        }
        local_8 = local_8 + 1;
        local_c = local_c + 0x3c;
      } while (local_8 < *(int *)(iVar2 + 0x10));
    }
    FUN_0053f500();
  }
  return;
}


// ==== 0x40caa0 FUN_0040caa0

void FUN_0040caa0(undefined4 param_1)

{
  int iVar1;
  undefined4 unaff_EBX;
  int iVar2;
  
  if (DAT_00743c58 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00743c58 + -4;
  }
  iVar1 = Ptr_BaseAdjustMinus4();
  while (iVar2 != iVar1) {
    FUN_0053f9f0(iVar2,unaff_EBX,param_1);
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x40caf0 D3DResourceList_ReleaseAll

/* [canon] render med (ghidra-canon) docs/re/render.md */

void D3DResourceList_ReleaseAll(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if ((int **)DAT_0078bc40 != &DAT_0078bc40) {
    do {
      piVar2 = DAT_0078bc40;
      iVar3 = *DAT_0078bc40;
      piVar1 = (int *)DAT_0078bc40[1];
      *piVar1 = iVar3;
      *(int **)(iVar3 + 4) = piVar1;
      piVar1 = (int *)piVar2[0xb];
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 8))(piVar1);
        while (iVar3 != 0) {
          iVar3 = (**(code **)(*(int *)piVar2[0xb] + 8))((int *)piVar2[0xb]);
        }
        piVar2[0xb] = 0;
      }
      piVar1 = (int *)piVar2[8];
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 8))(piVar1);
        while (iVar3 != 0) {
          iVar3 = (**(code **)(*(int *)piVar2[8] + 8))((int *)piVar2[8]);
        }
        piVar2[8] = 0;
      }
    } while ((int **)DAT_0078bc40 != &DAT_0078bc40);
  }
  return;
}


// ==== 0x40cb70 Ptr_BaseAdjustMinus4

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

int Ptr_BaseAdjustMinus4(void)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    return in_EAX + -4;
  }
  return 0;
}


// ==== 0x40cb80 BlurCreateRTs

/* [canon] render V (G+C) docs/re/blur.md */

void BlurCreateRTs(void)

{
  int *piVar1;
  int iVar2;
  
  DAT_00702a2c = DAT_00701034 / 2;
  DAT_00702a30 = DAT_00701038 / 2;
  if (DAT_00700e98 == 0) {
    DAT_0071ab9c = 0;
    DAT_0071aba8 = 0;
    DAT_0071aba0 = 0;
    DAT_0071abac = 0;
  }
  else {
    iVar2 = 0;
    do {
      (**(code **)(*DAT_0073636c + 0x5c))
                (DAT_0073636c,DAT_00702a2c,DAT_00702a30,1,1,DAT_00702a28,0,
                 (undefined4 *)((int)&DAT_0071ab9c + iVar2),0);
      piVar1 = *(int **)((int)&DAT_0071ab9c + iVar2);
      (**(code **)(*piVar1 + 0x48))(piVar1,0,(undefined4 *)((int)&DAT_0071aba8 + iVar2));
      (**(code **)(*DAT_0073636c + 0x94))
                (DAT_0073636c,0,*(undefined4 *)((int)&DAT_0071aba8 + iVar2));
      (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,1,0,0,0);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 8);
  }
  if (DAT_00700e9c == 0) {
    DAT_0071aba4 = (int *)0x0;
    DAT_0071abb0 = 0;
    return;
  }
  (**(code **)(*DAT_0073636c + 0x5c))
            (DAT_0073636c,DAT_00701034,DAT_00701038,1,1,DAT_00702a34,0,&DAT_0071aba4,0);
  (**(code **)(*DAT_0071aba4 + 0x48))(DAT_0071aba4,0,&DAT_0071abb0);
  (**(code **)(*DAT_0073636c + 0x94))(DAT_0073636c,0,DAT_0071abb0);
  (**(code **)(*DAT_0073636c + 0xac))(DAT_0073636c,0,0,1,0,0,0);
  return;
}


// ==== 0x40cce0 BlurReleaseRTs

/* [canon] render I (C) docs/re/blur.md */

void BlurReleaseRTs(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    piVar1 = *(int **)((int)&DAT_0071aba8 + iVar2);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)((int)&DAT_0071aba8 + iVar2) = 0;
    }
    piVar1 = *(int **)((int)&DAT_0071ab9c + iVar2);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)((int)&DAT_0071ab9c + iVar2) = 0;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 8);
  if (DAT_0071abb0 != (int *)0x0) {
    (**(code **)(*DAT_0071abb0 + 8))(DAT_0071abb0);
  }
  if (DAT_0071aba4 != (int *)0x0) {
    (**(code **)(*DAT_0071aba4 + 8))(DAT_0071aba4);
  }
  return;
}


// ==== 0x40cd40 SpeedBlurPass

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+H+C) docs/re/blur.md */

void SpeedBlurPass(void)

{
  float fVar1;
  uint uVar2;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  float fStack_54;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((float)_K_1_OVER_255_a < ABS(_gBlurSpecialN - (float)_gSpecialCameraActive)) {
    if ((float)_gSpecialCameraActive <= _gBlurSpecialN) {
      _gBlurSpecialN = _gBlurSpecialN - _BLUR_N_DOWN;
    }
    else {
      _gBlurSpecialN = _BLUR_N_UP + _gBlurSpecialN;
    }
  }
  local_20 = *(undefined4 *)(DAT_00740500 + 0x1e0);
  fStack_54 = (float)DAT_00740500;
  local_1c = *(undefined4 *)(DAT_00740500 + 0x1e4);
  local_18 = *(undefined4 *)(DAT_00740500 + 0x1e8);
  puStack_58 = &local_20;
  puStack_5c = &local_20;
  local_14 = 0;
  thunk_FUN_005ac436();
  if (_K_EPS_SPEED < (float)puStack_58) {
    Vec3Normalize();
  }
  fStack_54 = DAT_00702a38;
  if ((float)puStack_58 < DAT_00702a38 == ((float)puStack_58 == DAT_00702a38)) {
    fVar1 = _K_ONE;
    if ((float)puStack_58 < DAT_00702a3c) {
      fVar1 = ((float)puStack_58 - DAT_00702a38) / (DAT_00702a3c - DAT_00702a38);
    }
  }
  else {
    fVar1 = 0.0;
  }
  puStack_58 = (undefined4 *)(_gBlurSpecialN * (float)_K_N_WEIGHT + fVar1);
  if (DAT_00702a40 < (float)puStack_58) {
    puStack_58 = (undefined4 *)DAT_00702a40;
  }
  if (_K_BLUR_MIN_T <= (float)puStack_58) {
    BlurDownsample4Tap(DAT_00736460,4,BlurDownsampleTaps);
    uStack_3c = 0x3e800000;
    uStack_38 = 0x3e800000;
    uStack_34 = 0x3e800000;
    uStack_30 = 0x3e800000;
    BlurStreakPass4Tap(DAT_0071ab9c,4,&uStack_3c);
    BlurStreakPass4Tap(DAT_0071aba0,4,&uStack_3c);
    uVar2 = _ftol_nocw();
    (**(code **)(*DAT_0073636c + 0xe4))
              (DAT_0073636c,0xc1,((uVar2 << 8 | uVar2) << 8 | uVar2) << 8 | uVar2);
    BlurComposite(1,&DAT_0071ab9c,&puStack_5c,1,0xe,0xf);
  }
  return;
}


// ==== 0x40d090 BlurStreakPass4Tap

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+H+C) docs/re/blur.md */

void __thiscall
BlurStreakPass4Tap(int *param_1,undefined4 param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int *piStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined1 **ppuStack_184;
  undefined4 uStack_180;
  int *piStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  int *piStack_170;
  int *piStack_16c;
  float *pfStack_168;
  undefined4 uStack_164;
  int *piStack_160;
  undefined4 uStack_15c;
  int *piStack_158;
  int *piStack_154;
  undefined1 *puStack_150;
  float afStack_12c [67];
  undefined1 local_20 [16];
  undefined4 uStack_10;
  int iStack_c;
  
  puStack_150 = local_20;
  piStack_158 = (int *)0x40d0b3;
  piStack_154 = param_1;
  (**(code **)(*param_1 + 0x30))();
  uStack_15c = 0;
  piStack_160 = DAT_0073636c;
  uStack_164 = 0x40d0c5;
  piStack_158 = param_1;
  (**(code **)(*DAT_0073636c + 0x94))();
  afStack_12c[0] = 0.0;
  afStack_12c[1] = -NAN;
  afStack_12c[10] = 1.0;
  afStack_12c[0xb] = 1.0;
  afStack_12c[0xc] = 0.0;
  afStack_12c[0xd] = -NAN;
  afStack_12c[0x16] = 1.0;
  afStack_12c[0x17] = -1.0;
  afStack_12c[0x18] = 0.0;
  afStack_12c[0x19] = -NAN;
  afStack_12c[0x22] = -1.0;
  afStack_12c[0x23] = -1.0;
  afStack_12c[0x24] = 0.0;
  afStack_12c[0x25] = -NAN;
  puStack_150 = (undefined1 *)0x0;
  do {
    fVar3 = (float)(int)puStack_150;
    puStack_150 = puStack_150 + 1;
    fVar1 = *in_EAX;
    afStack_12c[(int)puStack_150 * 2] = -(fVar3 * fVar1);
    fVar2 = in_EAX[1];
    afStack_12c[(int)puStack_150 * 2 + 1] = -(fVar3 * fVar2);
    fVar4 = _K_ONE - fVar3 * in_EAX[2];
    afStack_12c[(int)puStack_150 * 2 + 0xc] = fVar4;
    afStack_12c[(int)puStack_150 * 2 + 0xd] = -(fVar3 * fVar2);
    afStack_12c[(int)puStack_150 * 2 + 0x18] = fVar4;
    fVar2 = _K_ONE - fVar3 * in_EAX[3];
    afStack_12c[(int)puStack_150 * 2 + 0x19] = fVar2;
    afStack_12c[(int)puStack_150 * 2 + 0x24] = -(fVar3 * fVar1);
    afStack_12c[(int)puStack_150 * 2 + 0x25] = fVar2;
  } while ((int)puStack_150 < 4);
  uStack_164 = 0x40d1c1;
  Effect_Select();
  if (0 < iStack_c) {
    pfVar6 = afStack_12c + 0x2f;
    puVar7 = &DAT_0071b190;
    iVar5 = iStack_c;
    do {
      uStack_164 = uStack_10;
      pfStack_168 = (float *)*puVar7;
      piStack_16c = DAT_0071b110;
      piStack_170 = (int *)0x40d1f9;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      fVar1 = param_4[1];
      fVar2 = param_4[2];
      pfVar6[-1] = *param_4;
      fVar3 = param_4[3];
      *pfVar6 = fVar1;
      pfVar6[1] = fVar2;
      pfVar6[2] = fVar3;
      puVar7 = puVar7 + 1;
      pfVar6 = pfVar6 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (iStack_c < 4) {
    pfVar6 = afStack_12c + iStack_c * 4 + 0x2f;
    puVar7 = &DAT_0071b190 + iStack_c;
    do {
      pfStack_168 = (float *)*puVar7;
      uStack_164 = 0;
      piStack_16c = DAT_0071b110;
      piStack_170 = (int *)0x40d253;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      pfVar6[-1] = 0.0;
      *pfVar6 = 0.0;
      pfVar6[1] = 0.0;
      pfVar6[2] = 0.0;
      puVar7 = puVar7 + 1;
      pfVar6 = pfVar6 + 4;
    } while ((int)puVar7 < 0x71b1a0);
  }
  uStack_164 = 4;
  pfStack_168 = afStack_12c + 0x2e;
  piStack_16c = (int *)DAT_0071b188;
  piStack_170 = DAT_0071b110;
  uStack_174 = 0x40d28e;
  (**(code **)(*DAT_0071b110 + 0x90))();
  _DAT_007070cc = 0xffffffff;
  _DAT_007070c8 = 0xffffffff;
  uStack_174 = 0;
  if (DAT_0073640c == 0) {
    uStack_178 = 0x1b;
    piStack_17c = DAT_0073636c;
    uStack_180 = 0x40d2b4;
    (**(code **)(*DAT_0073636c + 0xe4))();
  }
  else {
    piStack_17c = *(int **)(DAT_0073640c + 0x18);
    uStack_178 = *(undefined4 *)(DAT_0073640c + 0xc4);
    uStack_180 = 0x40d2c6;
    (**(code **)(*piStack_17c + 0x68))();
  }
  uStack_180 = 0x30;
  ppuStack_184 = &puStack_150;
  uStack_188 = 2;
  uStack_18c = 6;
  piStack_190 = DAT_0073636c;
  _DAT_007070d0 = 0;
  DAT_007363e8 = 0;
  (**(code **)(*DAT_0073636c + 0x14c))();
  iVar5 = DAT_00736458;
  FUN_0040ed50();
  (**(code **)(*DAT_0073636c + 0x94))(DAT_0073636c,0,*(undefined4 *)(iVar5 + 8));
  (**(code **)(*DAT_0073636c + 0x9c))(DAT_0073636c,*(undefined4 *)(iVar5 + 0xc));
  ppuStack_184 = *(undefined1 ***)(iVar5 + 0x18);
  uStack_188 = *(undefined4 *)(iVar5 + 0x14);
  piStack_190 = (int *)0x0;
  uStack_18c = 0;
  uStack_180 = 0;
  piStack_17c = (int *)0x3f800000;
  (**(code **)(*DAT_0073636c + 0xbc))(DAT_0073636c,&piStack_190);
  DAT_00736458 = iVar5;
  DAT_0073640c = 0;
  return;
}


// ==== 0x40d370 BlurDownsample4Tap

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+C) docs/re/blur.md */

void BlurDownsample4Tap(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *in_EAX;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  undefined4 uStack_1bc;
  undefined1 *puStack_1b8;
  undefined4 uStack_1b4;
  int *piStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  int *piStack_1a4;
  int *piStack_1a0;
  float *pfStack_19c;
  undefined4 uStack_198;
  int *piStack_194;
  undefined4 uStack_190;
  undefined1 *puStack_18c;
  int *piStack_188;
  float fStack_184;
  float fStack_180;
  undefined1 auStack_17c [4];
  undefined1 *puStack_178;
  float afStack_154 [48];
  undefined1 auStack_94 [12];
  int iStack_88;
  int iStack_84;
  float afStack_80 [24];
  undefined1 local_20 [4];
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int *piStack_10;
  int iStack_c;
  
  puStack_178 = local_20;
  fStack_180 = 5.953358e-39;
  (**(code **)(*in_EAX + 0x30))();
  iVar7 = 0;
  fStack_184 = 0.0;
  piStack_188 = DAT_0073636c;
  puStack_18c = (undefined1 *)0x40d39c;
  (**(code **)(*DAT_0073636c + 0x94))();
  afStack_154[0] = -1.0;
  afStack_154[1] = 1.0;
  afStack_154[2] = 0.0;
  afStack_154[3] = -NAN;
  afStack_154[0xc] = 1.0;
  afStack_154[0xd] = 1.0;
  afStack_154[0xe] = 0.0;
  afStack_154[0xf] = -NAN;
  afStack_154[0x18] = 1.0;
  afStack_154[0x19] = -1.0;
  afStack_154[0x1a] = 0.0;
  afStack_154[0x1b] = -NAN;
  afStack_154[0x24] = -1.0;
  afStack_154[0x25] = -1.0;
  afStack_154[0x26] = 0.0;
  afStack_154[0x27] = -NAN;
  iVar4 = 0;
  do {
    afStack_154[iVar4 * 2 + 4] = 0.0;
    afStack_154[iVar4 * 2 + 5] = 0.0;
    afStack_154[iVar4 * 2 + 0x10] = 1.0;
    afStack_154[iVar4 * 2 + 0x11] = 0.0;
    afStack_154[iVar4 * 2 + 0x1c] = 1.0;
    afStack_154[iVar4 * 2 + 0x1d] = 1.0;
    afStack_154[iVar4 * 2 + 0x28] = 0.0;
    afStack_154[iVar4 * 2 + 0x29] = 1.0;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  puStack_18c = (undefined1 *)0x40d466;
  Effect_Select();
  puStack_18c = auStack_94;
  uStack_190 = 0;
  piStack_194 = piStack_10;
  uStack_198 = 0x40d47c;
  (**(code **)(*piStack_10 + 0x44))();
  fStack_184 = (float)iStack_88;
  if (iStack_88 < 0) {
    fStack_184 = fStack_184 + 4.2949673e+09;
  }
  fStack_184 = _K_ONE / fStack_184;
  fStack_180 = (float)iStack_84;
  if (iStack_84 < 0) {
    fStack_180 = fStack_180 + 4.2949673e+09;
  }
  fStack_180 = _K_ONE / fStack_180;
  iVar4 = iStack_c;
  if (0 < iStack_c) {
    pfVar5 = afStack_80 + 1;
    pfVar8 = (float *)(iStack_14 + 8);
    puVar6 = &DAT_0071b190;
    do {
      uStack_198 = uStack_1c;
      pfStack_19c = (float *)*puVar6;
      piStack_1a0 = DAT_0071b110;
      piStack_1a4 = (int *)0x40d4fa;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      fVar3 = fStack_184 * pfVar8[-1];
      fVar2 = pfVar8[-2];
      *pfVar5 = fVar2;
      iVar4 = iStack_18;
      fVar1 = afStack_154[iVar7 * 2 + 1];
      pfVar5[-1] = fVar2;
      pfVar5[1] = fVar2;
      afStack_154[iVar7 * 2 + 1] = fVar3 + fVar1;
      pfVar5[2] = fVar2;
      iVar7 = iVar7 + 1;
      fVar1 = fStack_180 * *pfVar8;
      puVar6 = puVar6 + 1;
      pfVar5 = pfVar5 + 4;
      pfVar8 = pfVar8 + 3;
      afStack_154[iVar7 * 2] = fVar1 + afStack_154[iVar7 * 2];
      afStack_154[iVar7 * 2 + 0xb] = fVar3 + afStack_154[iVar7 * 2 + 0xb];
      afStack_154[iVar7 * 2 + 0xc] = fVar1 + afStack_154[iVar7 * 2 + 0xc];
      afStack_154[iVar7 * 2 + 0x17] = fVar3 + afStack_154[iVar7 * 2 + 0x17];
      afStack_154[iVar7 * 2 + 0x18] = fVar1 + afStack_154[iVar7 * 2 + 0x18];
      afStack_154[iVar7 * 2 + 0x23] = fVar3 + afStack_154[iVar7 * 2 + 0x23];
      afStack_154[iVar7 * 2 + 0x24] = fVar1 + afStack_154[iVar7 * 2 + 0x24];
    } while (iVar7 < iVar4);
  }
  if (iVar4 < 4) {
    pfVar5 = afStack_80 + iVar4 * 4 + 1;
    puVar6 = &DAT_0071b190 + iVar4;
    do {
      pfStack_19c = (float *)*puVar6;
      uStack_198 = 0;
      piStack_1a0 = DAT_0071b110;
      piStack_1a4 = (int *)0x40d5c9;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      pfVar5[-1] = 0.0;
      *pfVar5 = 0.0;
      pfVar5[1] = 0.0;
      pfVar5[2] = 0.0;
      puVar6 = puVar6 + 1;
      pfVar5 = pfVar5 + 4;
    } while ((int)puVar6 < 0x71b1a0);
  }
  uStack_198 = 4;
  pfStack_19c = afStack_80;
  piStack_1a0 = (int *)DAT_0071b188;
  piStack_1a4 = DAT_0071b110;
  uStack_1a8 = 0x40d601;
  (**(code **)(*DAT_0071b110 + 0x90))();
  _DAT_007070cc = 0xffffffff;
  _DAT_007070c8 = 0xffffffff;
  uStack_1a8 = 0;
  if (DAT_0073640c == 0) {
    uStack_1ac = 0x1b;
    piStack_1b0 = DAT_0073636c;
    uStack_1b4 = 0x40d627;
    (**(code **)(*DAT_0073636c + 0xe4))();
  }
  else {
    piStack_1b0 = *(int **)(DAT_0073640c + 0x18);
    uStack_1ac = *(undefined4 *)(DAT_0073640c + 0xc4);
    uStack_1b4 = 0x40d639;
    (**(code **)(*piStack_1b0 + 0x68))();
  }
  uStack_1b4 = 0x30;
  puStack_1b8 = auStack_17c;
  uStack_1bc = 2;
  _DAT_007070d0 = 0;
  DAT_007363e8 = 0;
  (**(code **)(*DAT_0073636c + 0x14c))(DAT_0073636c,6);
  iVar4 = DAT_00736458;
  FUN_0040ed50();
  (**(code **)(*DAT_0073636c + 0x94))(DAT_0073636c,0,*(undefined4 *)(iVar4 + 8));
  (**(code **)(*DAT_0073636c + 0x9c))(DAT_0073636c,*(undefined4 *)(iVar4 + 0xc));
  piStack_1b0 = *(int **)(iVar4 + 0x18);
  uStack_1b4 = *(undefined4 *)(iVar4 + 0x14);
  uStack_1bc = 0;
  puStack_1b8 = (undefined1 *)0x0;
  uStack_1ac = 0;
  uStack_1a8 = 0x3f800000;
  (**(code **)(*DAT_0073636c + 0xbc))(DAT_0073636c,&uStack_1bc);
  DAT_00736458 = iVar4;
  DAT_0073640c = 0;
  return;
}


// ==== 0x40d6e0 BlurComposite

/* WARNING: Removing unreachable block (ram,0x0040d835) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+C) docs/re/blur.md */

void BlurComposite(int param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  int iVar4;
  byte *pbVar5;
  float *pfVar6;
  undefined4 *puVar7;
  undefined4 uStack_168;
  int *piStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined1 *puStack_158;
  undefined4 uStack_154;
  int *piStack_150;
  undefined4 uStack_14c;
  undefined1 *puStack_148;
  undefined4 uStack_144;
  int *piStack_140;
  int *piStack_13c;
  undefined4 uStack_138;
  int *piStack_134;
  undefined4 auStack_f0 [38];
  undefined1 auStack_58 [24];
  float afStack_40 [16];
  
  if (in_EAX != 0) {
    piStack_134 = DAT_0073636c;
    uStack_138 = 0x40d6ff;
    (**(code **)(*DAT_0073636c + 0x94))();
  }
  auStack_f0[0xb] = 0xffffffff;
  auStack_f0[0x17] = 0xffffffff;
  auStack_f0[0x23] = 0xffffffff;
  auStack_f0[8] = 0x3f800000;
  auStack_f0[9] = 0x3f800000;
  auStack_f0[10] = 0;
  auStack_f0[0x14] = 0x3f800000;
  auStack_f0[0x15] = 0xbf800000;
  auStack_f0[0x16] = 0;
  auStack_f0[0x20] = 0xbf800000;
  auStack_f0[0x21] = 0xbf800000;
  auStack_f0[0x22] = 0;
  iVar4 = 0;
  do {
    auStack_f0[iVar4 * 2] = 0;
    auStack_f0[iVar4 * 2 + 1] = 0;
    auStack_f0[iVar4 * 2 + 0xc] = 0x3f800000;
    auStack_f0[iVar4 * 2 + 0xd] = 0;
    auStack_f0[iVar4 * 2 + 0x18] = 0x3f800000;
    auStack_f0[iVar4 * 2 + 0x19] = 0x3f800000;
    auStack_f0[iVar4 * 2 + 0x24] = 0;
    *(undefined4 *)(auStack_58 + iVar4 * 8 + -4) = 0x3f800000;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  piStack_134 = (int *)0x40d7d9;
  Effect_Select();
  iVar4 = 0;
  if (0 < param_1) {
    pbVar5 = (byte *)(param_3 + 1);
    pfVar6 = afStack_40 + 1;
    do {
      piStack_134 = *(int **)(param_2 + iVar4 * 4);
      uStack_138 = *(undefined4 *)(pbVar5 + ((int)&DAT_0071b18f - param_3));
      piStack_13c = DAT_0071b110;
      piStack_140 = (int *)0x40d821;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      bVar1 = *pbVar5;
      bVar2 = pbVar5[1];
      pfVar6[-1] = (float)(*(uint *)(pbVar5 + -1) & 0xff) * _K_BLUR_MIN_T;
      bVar3 = pbVar5[2];
      iVar4 = iVar4 + 1;
      pbVar5 = pbVar5 + 4;
      *pfVar6 = (float)bVar1 * _K_BLUR_MIN_T;
      pfVar6[1] = (float)bVar2 * _K_BLUR_MIN_T;
      pfVar6[2] = (float)bVar3 * _K_BLUR_MIN_T;
      pfVar6 = pfVar6 + 4;
    } while (iVar4 < param_1);
  }
  if (param_1 < 4) {
    pfVar6 = afStack_40 + param_1 * 4 + 1;
    puVar7 = &DAT_0071b190 + param_1;
    do {
      uStack_138 = *puVar7;
      piStack_134 = (int *)0x0;
      piStack_13c = DAT_0071b110;
      piStack_140 = (int *)0x40d8c9;
      (**(code **)(*DAT_0071b110 + 0xd0))();
      pfVar6[-1] = 0.0;
      *pfVar6 = 0.0;
      pfVar6[1] = 0.0;
      pfVar6[2] = 0.0;
      puVar7 = puVar7 + 1;
      pfVar6 = pfVar6 + 4;
    } while ((int)puVar7 < 0x71b1a0);
  }
  piStack_134 = (int *)param_4;
  uStack_138 = 0x40d8fd;
  FUN_00410550();
  if (DAT_0073640c == 0) {
    piStack_134 = DAT_0073636c;
    uStack_138 = 0x40d91c;
    (**(code **)(*DAT_0073636c + 0xe4))();
  }
  else {
    piStack_134 = *(int **)(DAT_0073640c + 0x18);
    uStack_138 = 0x40d92e;
    (**(code **)(*piStack_134 + 0x68))();
  }
  _DAT_007070c4 = 0;
  uStack_138 = 0;
  if (DAT_0073640c == 0) {
    piStack_13c = (int *)0x18;
    piStack_140 = DAT_0073636c;
    uStack_144 = 0x40d94f;
    (**(code **)(*DAT_0073636c + 0xe4))();
  }
  else {
    piStack_140 = *(int **)(DAT_0073640c + 0x18);
    piStack_13c = *(int **)(DAT_0073640c + 0xc0);
    uStack_144 = 0x40d961;
    (**(code **)(*piStack_140 + 0x68))();
  }
  uStack_144 = 4;
  puStack_148 = auStack_58;
  uStack_14c = DAT_0071b188;
  piStack_150 = DAT_0071b110;
  _DAT_007070c0 = 0;
  uStack_154 = 0x40d986;
  (**(code **)(*DAT_0071b110 + 0x90))();
  uStack_154 = 0x30;
  puStack_158 = &stack0xfffffed8;
  uStack_15c = 2;
  uStack_160 = 6;
  piStack_164 = DAT_0073636c;
  DAT_007363e8 = 0;
  uStack_168 = 0x40d9a5;
  (**(code **)(*DAT_0073636c + 0x14c))();
  iVar4 = DAT_00736458;
  uStack_168 = 0x40d9b0;
  FUN_0040ed50();
  uStack_168 = *(undefined4 *)(iVar4 + 8);
  (**(code **)(*DAT_0073636c + 0x94))(DAT_0073636c,0);
  (**(code **)(*DAT_0073636c + 0x9c))(DAT_0073636c,*(undefined4 *)(iVar4 + 0xc));
  uStack_160 = *(undefined4 *)(iVar4 + 0x14);
  uStack_15c = *(undefined4 *)(iVar4 + 0x18);
  uStack_168 = 0;
  piStack_164 = (int *)0x0;
  puStack_158 = (undefined1 *)0x0;
  uStack_154 = 0x3f800000;
  (**(code **)(*DAT_0073636c + 0xbc))(DAT_0073636c,&uStack_168);
  DAT_00736458 = iVar4;
  DAT_0073640c = 0;
  return;
}


// ==== 0x40da30 AABB_TransformByMatrix

/* [canon] render med (ghidra-canon) docs/re/render.md */

void AABB_TransformByMatrix(float *param_1,float *param_2)

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
  int in_EAX;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  
  fVar1 = *(float *)(in_EAX + 0x30);
  fVar5 = *(float *)(in_EAX + 0x34);
  fVar2 = *(float *)(in_EAX + 0x34);
  fVar6 = *(float *)(in_EAX + 0x30);
  fVar3 = *(float *)(in_EAX + 0x38);
  fVar4 = *(float *)(in_EAX + 0x38);
  pfVar11 = (float *)(in_EAX + 8);
  iVar12 = (int)param_2 - (int)param_1;
  iVar13 = 3;
  pfVar10 = param_1;
  do {
    fVar7 = *pfVar10 * pfVar11[-2];
    fVar8 = *(float *)(iVar12 + (int)pfVar10) * pfVar11[-2];
    fVar9 = fVar7;
    if (fVar7 < fVar8) {
      fVar9 = fVar8;
      fVar8 = fVar7;
    }
    fVar1 = fVar8 + fVar1;
    fVar6 = fVar6 + fVar9;
    fVar8 = *pfVar10 * pfVar11[-1];
    fVar9 = *(float *)(iVar12 + (int)pfVar10) * pfVar11[-1];
    fVar7 = fVar8;
    if (fVar8 < fVar9) {
      fVar7 = fVar9;
      fVar9 = fVar8;
    }
    fVar2 = fVar9 + fVar2;
    fVar5 = fVar7 + fVar5;
    fVar8 = *pfVar10 * *pfVar11;
    fVar9 = *(float *)(iVar12 + (int)pfVar10) * *pfVar11;
    fVar7 = fVar8;
    if (fVar8 < fVar9) {
      fVar7 = fVar9;
      fVar9 = fVar8;
    }
    fVar3 = fVar9 + fVar3;
    pfVar10 = pfVar10 + 1;
    fVar4 = fVar7 + fVar4;
    pfVar11 = pfVar11 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  *param_1 = fVar1;
  param_1[1] = fVar2;
  param_1[2] = fVar3;
  *param_2 = fVar6;
  param_2[1] = fVar5;
  param_2[2] = fVar4;
  return;
}


// ==== 0x40db20 AABB_ClassifyAgainstFrustum

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra-canon) docs/re/runtime.md */

char __fastcall AABB_ClassifyAgainstFrustum(float *param_1,float *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int in_EAX;
  float *pfVar7;
  int iVar8;
  float local_40;
  float local_3c;
  float local_38;
  float local_20;
  float local_1c;
  float local_18;
  
  local_1c = param_2[1];
  local_18 = param_2[2];
  local_20 = *param_2;
  local_40 = *param_1;
  local_3c = param_1[1];
  local_38 = param_1[2];
  if (in_EAX != 0) {
    AABB_TransformByMatrix(&local_20,&local_40);
  }
  bVar6 = false;
  iVar8 = 1;
  fVar3 = (local_40 + local_20) * _K_HALF;
  pfVar7 = (float *)(*param_3 + 0xc4);
  fVar4 = (local_3c + local_1c) * _K_HALF;
  fVar5 = (local_38 + local_18) * _K_HALF;
  do {
    fVar1 = ABS(*pfVar7) * (local_3c - fVar4) +
            ABS(pfVar7[-1]) * (local_40 - fVar3) + ABS(pfVar7[1]) * (local_38 - fVar5);
    fVar2 = fVar4 * *pfVar7 + fVar3 * pfVar7[-1] + fVar5 * pfVar7[1] + pfVar7[2];
    if (fVar2 + fVar1 < 0.0) {
      return '\0';
    }
    if (fVar2 - fVar1 < 0.0) {
      bVar6 = true;
    }
    iVar8 = iVar8 + 1;
    pfVar7 = pfVar7 + 4;
  } while (iVar8 < 7);
  return !bVar6 + '\x01';
}


// ==== 0x40dc60 FUN_0040dc60

undefined4 FUN_0040dc60(void)

{
  int *in_EAX;
  float *pfVar1;
  int iVar2;
  float *unaff_ESI;
  
  iVar2 = 0;
  pfVar1 = (float *)(*in_EAX + 0xc4);
  do {
    if (*pfVar1 * unaff_ESI[1] + pfVar1[-1] * *unaff_ESI + pfVar1[1] * unaff_ESI[2] + pfVar1[2] <=
        0.0) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 4;
  } while (iVar2 < 6);
  return 2;
}


// ==== 0x40dcb0 FUN_0040dcb0

float10 __fastcall FUN_0040dcb0(undefined4 param_1)

{
  float10 fVar1;
  float fVar2;
  
  fVar1 = (float10)FUN_00564b10(param_1);
  fVar2 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10();
  if ((float10)fVar2 / fVar1 != (float10)0.0) {
    return (float10)(DAT_00701034 >> 1) / ((float10)fVar2 / fVar1);
  }
  return (float10)10.0;
}


// ==== 0x40dd00 BuildProjection

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (C) docs/re/camera.md */

void BuildProjection(int param_1,float param_2,float param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  undefined4 extraout_EDX;
  uint uVar5;
  uint uVar6;
  undefined4 *unaff_ESI;
  bool bVar7;
  bool bVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST1;
  float local_c;
  
  iVar4 = *(int *)(param_1 + 0x40);
  if (iVar4 == 0) {
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[0xb] = 0;
    unaff_ESI[0xc] = 0;
    unaff_ESI[0xd] = 0;
    unaff_ESI[0xe] = 0;
    *unaff_ESI = 0x3f800000;
    unaff_ESI[5] = 0x3f800000;
    unaff_ESI[10] = 0x3f800000;
    unaff_ESI[0xf] = 0x3f800000;
    unaff_ESI[0x11] = 0;
    unaff_ESI[0x12] = 0;
    unaff_ESI[0x13] = 0;
    unaff_ESI[0x14] = 0;
    unaff_ESI[0x16] = 0;
    unaff_ESI[0x17] = 0;
    unaff_ESI[0x18] = 0;
    unaff_ESI[0x19] = 0;
    unaff_ESI[0x1b] = 0;
    unaff_ESI[0x1c] = 0;
    unaff_ESI[0x1d] = 0;
    unaff_ESI[0x1e] = 0;
    unaff_ESI[0x10] = 0x3f800000;
    unaff_ESI[0x15] = 0x3f800000;
    unaff_ESI[0x1a] = 0x3f800000;
    unaff_ESI[0x1f] = 0x3f800000;
    return;
  }
  bMatrixCopy_b();
  local_c = *(float *)(iVar4 + 0xbc);
  if (param_2 != 0.0) {
    local_c = param_2;
  }
  if (param_3 != 0.0) {
    local_c = param_3;
  }
  _ftol_nocw();
  _ftol_nocw();
  unaff_ESI[0x10] = 1.0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0x3f800000;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0x3f800000;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0x3f800000;
  fVar3 = (float)(extraout_ST1 / (extraout_ST1 - (float10)local_c));
  fVar9 = (float10)FUN_00564b10();
  fVar10 = (float10)FUN_00564b10();
  unaff_ESI[0x10] = (float)((float10)_K_ONE / ((float10)(float)fVar9 / fVar10));
  fVar9 = (float10)FUN_00564b10();
  fVar10 = (float10)FUN_00564b10();
  unaff_ESI[0x1a] = fVar3;
  unaff_ESI[0x1b] = extraout_EDX;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x15] = (float)-((float10)_K_ONE / ((float10)(float)fVar9 / fVar10));
  unaff_ESI[0x1e] = -(fVar3 * local_c);
  fVar9 = (float10)FUN_0040dcb0();
  *(float *)(param_1 + 0xc) = (float)fVar9;
  pfVar1 = (float *)(unaff_ESI + 0x20);
  unaff_ESI[3] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[0xb] = 0;
  D3DXMatrixMultiply(pfVar1);
  bVar7 = true;
  bVar8 = false;
  uVar5 = 0;
  do {
    if (bVar7 || bVar8) {
      switch(uVar5) {
      default:
        unaff_ESI[0x30] = (float)unaff_ESI[0x23] + *pfVar1;
        unaff_ESI[0x31] = (float)unaff_ESI[0x27] + (float)unaff_ESI[0x24];
        unaff_ESI[0x32] = (float)unaff_ESI[0x2b] + (float)unaff_ESI[0x28];
        unaff_ESI[0x33] = (float)unaff_ESI[0x2f] + (float)unaff_ESI[0x2c];
        break;
      case 1:
        unaff_ESI[0x34] = (float)unaff_ESI[0x23] - *pfVar1;
        unaff_ESI[0x35] = (float)unaff_ESI[0x27] - (float)unaff_ESI[0x24];
        unaff_ESI[0x36] = (float)unaff_ESI[0x2b] - (float)unaff_ESI[0x28];
        unaff_ESI[0x37] = (float)unaff_ESI[0x2f] - (float)unaff_ESI[0x2c];
        break;
      case 2:
        unaff_ESI[0x38] = (float)unaff_ESI[0x23] + (float)unaff_ESI[0x21];
        unaff_ESI[0x39] = (float)unaff_ESI[0x27] + (float)unaff_ESI[0x25];
        unaff_ESI[0x3a] = (float)unaff_ESI[0x2b] + (float)unaff_ESI[0x29];
        unaff_ESI[0x3b] = (float)unaff_ESI[0x2f] + (float)unaff_ESI[0x2d];
        break;
      case 3:
        unaff_ESI[0x3c] = (float)unaff_ESI[0x23] - (float)unaff_ESI[0x21];
        unaff_ESI[0x3d] = (float)unaff_ESI[0x27] - (float)unaff_ESI[0x25];
        unaff_ESI[0x3e] = (float)unaff_ESI[0x2b] - (float)unaff_ESI[0x29];
        unaff_ESI[0x3f] = (float)unaff_ESI[0x2f] - (float)unaff_ESI[0x2d];
        break;
      case 4:
        unaff_ESI[0x40] = unaff_ESI[0x22];
        unaff_ESI[0x41] = unaff_ESI[0x26];
        unaff_ESI[0x42] = unaff_ESI[0x2a];
        unaff_ESI[0x43] = unaff_ESI[0x2e];
        break;
      case 5:
        unaff_ESI[0x44] = (float)unaff_ESI[0x23] - (float)unaff_ESI[0x22];
        unaff_ESI[0x45] = (float)unaff_ESI[0x27] - (float)unaff_ESI[0x26];
        unaff_ESI[0x46] = (float)unaff_ESI[0x2b] - (float)unaff_ESI[0x2a];
        unaff_ESI[0x47] = (float)unaff_ESI[0x2f] - (float)unaff_ESI[0x2e];
      }
    }
    pfVar2 = (float *)(unaff_ESI + (uVar5 + 0xc) * 4);
    uVar6 = uVar5 + 1;
    bVar7 = uVar6 < 5;
    bVar8 = uVar6 == 5;
    fVar3 = _K_ONE / SQRT((float)unaff_ESI[(uVar5 + 0xc) * 4 + 2] *
                          (float)unaff_ESI[(uVar5 + 0xc) * 4 + 2] +
                          pfVar2[1] * pfVar2[1] + *pfVar2 * *pfVar2);
    *pfVar2 = fVar3 * *pfVar2;
    unaff_ESI[uVar5 * 4 + 0x31] = fVar3 * (float)unaff_ESI[uVar5 * 4 + 0x31];
    unaff_ESI[uVar5 * 4 + 0x32] = fVar3 * (float)unaff_ESI[uVar5 * 4 + 0x32];
    unaff_ESI[uVar5 * 4 + 0x33] = fVar3 * (float)unaff_ESI[uVar5 * 4 + 0x33];
    uVar5 = uVar6;
  } while ((int)uVar6 < 6);
  return;
}


// ==== 0x40e180 Effects_CreateAll

/* WARNING: Type propagation algorithm not settling */
/* [canon] render med (ghidra) docs/re/render.md */

void Effects_CreateAll(void)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  int iStack_b8;
  int iStack_b4;
  undefined2 auStack_a0 [2];
  undefined1 auStack_9c [152];
  
  if (DAT_00736410 != (int *)0x0) {
    (**(code **)(*DAT_00736410 + 8))();
  }
  FUN_005af9e5();
  (**(code **)(*DAT_0073636c + 0x1c))();
  (**(code **)(*DAT_00736368 + 0x14))();
  uVar5 = DAT_0071b64c;
  iVar4 = DAT_0071b648;
  iStack_b4 = 0;
  do {
    iVar12 = (&DAT_007010c0)[iStack_b4 * 0x20];
    puVar7 = &DAT_007010c0 + iStack_b4 * 0x20;
    (&DAT_0071abb8)[iStack_b4 * 0x38] = iStack_b4;
    iVar6 = 0;
    iVar10 = 0;
    if (iVar12 != 8) {
      puVar13 = puVar7;
      do {
        iVar2 = puVar13[1];
        auStack_9c[iVar6 * 8] = (&DAT_00701470)[iVar12 * 4];
        auStack_9c[iVar6 * 8 + 2] = (&DAT_00701490)[iVar2 * 4];
        auStack_9c[iVar6 * 8 + 3] = (&DAT_007014b4)[iVar2];
        iVar12 = *(int *)(&DAT_007014c0 + iVar12 * 4);
        *(short *)(auStack_9c + iVar6 * 8 + -2) = (short)iVar10;
        iVar10 = iVar10 + iVar12;
        auStack_a0[iVar6 * 4] = 0;
        auStack_9c[iVar6 * 8 + 1] = 0;
        iVar6 = iVar6 + 1;
        iVar2 = iVar6 * 8 - (int)(auStack_a0 + 1);
        iVar12 = *(int *)(auStack_9c + (int)puVar7 + iVar2 + -2);
        puVar13 = (undefined4 *)(auStack_9c + (int)puVar7 + iVar2 + -2);
      } while (iVar12 != 8);
    }
    auStack_a0[iVar6 * 4] = 0xff;
    *(undefined2 *)(auStack_9c + iVar6 * 8 + -2) = 0;
    auStack_9c[iVar6 * 8] = 0x11;
    auStack_9c[iVar6 * 8 + 1] = 0;
    auStack_9c[iVar6 * 8 + 2] = 0;
    auStack_9c[iVar6 * 8 + 3] = 0;
    (**(code **)(*DAT_0073636c + 0x158))();
    (&DAT_0071abc0)[iStack_b4 * 0x38] = iVar10;
    puVar7 = (undefined4 *)bOpenFile();
    if ((puVar7 == (undefined4 *)0x0) || (iVar12 = puVar7[1], iVar12 < 0)) {
      iVar12 = 0;
    }
    pvVar8 = _malloc(iVar12 + 1);
    FUN_00594dd0();
    if (puVar7 != (undefined4 *)0x0) {
      if ((int)puVar7[7] < 1) {
        if (-1 < (int)puVar7[1]) {
          if (puVar7[4] == 0) {
            FUN_0063c2c0();
          }
          else {
            piVar1 = (int *)(puVar7[4] + 8);
            *piVar1 = *piVar1 + -1;
          }
          puVar7[1] = 0xffffffff;
        }
        iVar10 = DAT_00734484;
        iVar6 = *(int *)(DAT_00734484 + 0x18);
        *puVar7 = *(undefined4 *)(DAT_00734484 + 0x10);
        *(int *)(iVar10 + 0x18) = iVar6 + -1;
        *(undefined4 **)(iVar10 + 0x10) = puVar7;
      }
      else {
        puVar7[5] = 1;
      }
    }
    iVar6 = 0;
    if (0 < iVar12) {
      do {
        *(byte *)(iVar6 + (int)pvVar8) = *(byte *)(iVar6 + (int)pvVar8) ^ 0xaa;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar12);
    }
    *(undefined1 *)(iVar12 + (int)pvVar8) = 0;
    puVar7 = &DAT_0071abd0 + iStack_b4 * 0x38;
    FUN_005afb2f();
    iVar12 = DAT_007070d8;
    (&DAT_0071abc8)[iStack_b4 * 0x38] = 0;
    iStack_b8 = 0;
    if (0 < iVar12) {
      while (iVar12 = (**(code **)(*(int *)*puVar7 + 0x30))(), iVar12 != 0) {
        if ((((iStack_b4 != 2) && (iStack_b4 != 3)) ||
            ((iVar4 != 0x1039 && ((iVar4 != 0x8086 || (uVar5 != 0x2572)))))) || (2 < iStack_b8)) {
          if (iStack_b4 == 1) {
            if ((((iVar4 != 0x10de) || ((0x153 < uVar5 && ((uVar5 < 0x170 || (0x1f0 < uVar5)))))) ||
                (iStack_b8 < 1)) || (2 < iStack_b8)) {
LAB_0040e458:
              pcVar11 = s_WorldViewProj_00701860;
              puVar13 = &DAT_0071abd4 + iStack_b4 * 0x38;
              do {
                uVar9 = (**(code **)(*(int *)*puVar7 + 0x24))();
                *puVar13 = uVar9;
                pcVar11 = pcVar11 + 0x40;
                puVar13 = puVar13 + 1;
              } while ((int)pcVar11 < 0x702420);
              (**(code **)(*(int *)*puVar7 + 0x68))();
              (**(code **)(*(int *)*puVar7 + 0x68))();
              iVar12 = (**(code **)(*(int *)*puVar7 + 0xf4))();
              if (iVar12 == 0) {
                (&DAT_0071abc4)[iStack_b4 * 0x38] = iStack_b8;
                (&DAT_0071abc8)[iStack_b4 * 0x38] = 2;
                (**(code **)(*(int *)*puVar7 + 0xec))();
                if (iStack_b8 < 1) {
                  if (iStack_b8 == 0) {
                    DAT_00736418 = 1;
                  }
                }
                else {
                  DAT_00736414 = 1;
                }
                break;
              }
            }
          }
          else if (((iStack_b4 != 5) && (iStack_b4 != 6)) ||
                  (((iVar4 != 0x102b || (iStack_b8 != 0)) &&
                   (((iStack_b4 != 6 || (iVar4 != 0x1039)) || (iStack_b8 != 0))))))
          goto LAB_0040e458;
        }
        iStack_b8 = iStack_b8 + 1;
        if (DAT_007070d8 <= iStack_b8) break;
      }
    }
    iVar12 = 0;
    do {
      iVar6 = (**(code **)(*(int *)*puVar7 + 0x38))();
      if (iVar6 == 0) break;
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0x10);
    (&DAT_0071abcc)[iStack_b4 * 0x38] = iVar12;
    if ((&DAT_0071abc8)[iStack_b4 * 0x38] != 0) {
      puVar3 = (&PTR_NullUpdate_ret_0070243c)[iStack_b4];
      (&DAT_0071ac90)[iStack_b4 * 0x38] = (&PTR_NullUpdate_ret_00702420)[iStack_b4];
      (&DAT_0071ac94)[iStack_b4 * 0x38] = puVar3;
    }
    iStack_b4 = iStack_b4 + 1;
    if (6 < iStack_b4) {
      RampTexture_Create();
      return;
    }
  } while( true );
}


// ==== 0x40e560 RampTexture_Create

/* [canon] render high (ghidra+capstone) docs/re/render.md */

void RampTexture_Create(void)

{
  int iVar1;
  int iVar2;
  int *piStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  puStack_10 = &DAT_0071abb4;
  uStack_14 = 1;
  uStack_18 = 0x15;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_24 = 1;
  uStack_28 = 0x40;
  piStack_2c = DAT_0073636c;
  (**(code **)(*DAT_0073636c + 0x5c))();
  iVar2 = 0;
  (**(code **)(*DAT_0071abb4 + 0x4c))(DAT_0071abb4,0,&piStack_2c,0,0);
  iVar1 = 0;
  do {
    *(undefined4 *)(iVar1 + iVar2) = 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x84);
  iVar1 = 0x84;
  do {
    *(undefined4 *)(iVar1 + iVar2) = 0xffffffff;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc0);
  *(undefined4 *)(iVar2 + 0xc0) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0xc4) = 0xefefefef;
  *(undefined4 *)(iVar2 + 200) = 0xdfdfdfdf;
  *(undefined4 *)(iVar2 + 0xcc) = 0xcfcfcfcf;
  *(undefined4 *)(iVar2 + 0xd0) = 0xbfbfbfbf;
  *(undefined4 *)(iVar2 + 0xd4) = 0xafafafaf;
  *(undefined4 *)(iVar2 + 0xd8) = 0x9f9f9f9f;
  *(undefined4 *)(iVar2 + 0xdc) = 0x8f8f8f8f;
  *(undefined4 *)(iVar2 + 0xe0) = 0x7f7f7f7f;
  *(undefined4 *)(iVar2 + 0xe4) = 0x6f6f6f6f;
  *(undefined4 *)(iVar2 + 0xe8) = 0x5f5f5f5f;
  *(undefined4 *)(iVar2 + 0xec) = 0x4f4f4f4f;
  *(undefined4 *)(iVar2 + 0xf0) = 0x3f3f3f3f;
  *(undefined4 *)(iVar2 + 0xf4) = 0x2f2f2f2f;
  *(undefined4 *)(iVar2 + 0xf8) = 0x1f1f1f1f;
  *(undefined4 *)(iVar2 + 0xfc) = 0;
  (**(code **)(*DAT_0071abb4 + 0x50))(DAT_0071abb4,0);
  return;
}


// ==== 0x40e6d0 Effect_Select

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void Effect_Select(void)

{
  int in_EAX;
  int unaff_EDI;
  int *piStack_c;
  
  if (DAT_0073640c != 0) {
    if (DAT_0073640c == in_EAX) {
      return;
    }
    piStack_c = *(int **)(DAT_0073640c + 0x18);
    (**(code **)(*piStack_c + 0x108))();
    (**(code **)(DAT_0073640c + 0xdc))();
  }
  piStack_c = (int *)0x40e705;
  DAT_0073640c = in_EAX;
  (**(code **)(in_EAX + 0xd8))();
  piStack_c = *(int **)(in_EAX + 4);
  (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c);
  (**(code **)(**(int **)(in_EAX + 0x18) + 0x100))(*(int **)(in_EAX + 0x18),&piStack_c,0);
  if (unaff_EDI != -1) {
    (**(code **)(**(int **)(in_EAX + 0x18) + 0x104))(*(int **)(in_EAX + 0x18));
  }
  return;
}


// ==== 0x40e740 Effect_BindHeadlightTextures

/* [canon] render med (ghidra-canon) docs/re/render.md */

void Effect_BindHeadlightTextures(void)

{
  byte *pbVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = "HEADLIGHTS";
  iVar4 = -1;
  uVar2 = 0x48;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  piVar3 = (int *)Texture_FindByHash(iVar4,1,0);
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x44),
             *(undefined4 *)(*piVar3 + 0x18));
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x7c),DAT_0071abb4);
  return;
}


// ==== 0x40e7b0 Effect_BindSceneParams

/* [canon] render low (ghidra) docs/re/render.md */

void Effect_BindSceneParams(void)

{
  undefined4 uStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  
  piStack_6c = *(int **)(DAT_0073640c + 0x18);
  uStack_68 = *(undefined4 *)(DAT_0073640c + 0x84);
  uStack_64 = DAT_0071aa28;
  uStack_70 = 0x40e7da;
  (**(code **)(*piStack_6c + 0xd0))();
  uStack_74 = *(undefined4 *)(DAT_0073640c + 0x8c);
  uStack_70 = 0x3dcccccd;
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x78))(*(int **)(DAT_0073640c + 0x18));
  if (*(int *)(DAT_0073640c + 0xc) != 0) {
    uStack_64 = 0;
    uStack_68 = 0x3f000000;
    if (&DAT_00740460 + *(int *)(DAT_00736458 + 4) * 0x18 != (int *)0x0) {
      D3DXMatrixMultiply(&uStack_68,(&DAT_00740460)[*(int *)(DAT_00736458 + 4) * 0x18] + 0x40,
                         &uStack_68);
      piStack_6c = (int *)uStack_68;
      (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x98))
                (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x88),&uStack_74);
    }
  }
  return;
}


// ==== 0x40e900 Effect_BindHeadlightParams

/* [canon] render med (ghidra-canon) docs/re/render.md */

void Effect_BindHeadlightParams(void)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  
  pcVar7 = "HEADLIGHTS";
  piStack_6c = (int *)0xffffffff;
  uVar6 = 0x48;
  do {
    piStack_6c = (int *)((int)piStack_6c * 0x21 + uVar6);
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  uStack_64 = 0;
  uStack_68 = 1;
  uStack_70 = 0x40e92e;
  piVar3 = (int *)Texture_FindByHash();
  piStack_6c = *(int **)(DAT_0073640c + 0x18);
  uStack_64 = *(undefined4 *)(*piVar3 + 0x18);
  uStack_68 = *(undefined4 *)(DAT_0073640c + 0x44);
  uStack_70 = 0x40e94d;
  (**(code **)(*piStack_6c + 0xd0))();
  piStack_78 = *(int **)(DAT_0073640c + 0x18);
  uStack_74 = *(undefined4 *)(DAT_0073640c + 0x7c);
  uStack_70 = DAT_0071abb4;
  uStack_7c = 0x40e96a;
  (**(code **)(*piStack_78 + 0xd0))();
  uStack_80 = *(undefined4 *)(DAT_0073640c + 0x84);
  uStack_7c = DAT_0071aa28;
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))(*(int **)(DAT_0073640c + 0x18));
  iVar2 = DAT_0073640c;
  if (*(int *)(DAT_0073640c + 0xc) == 0) {
    pcVar7 = "HEADLIGHTS";
    iVar4 = -1;
    uVar6 = 0x48;
    do {
      iVar4 = iVar4 * 0x21 + uVar6;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar6 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    piVar5 = (int *)Texture_FindByHash(iVar4,1,0);
    piVar3 = *(int **)(iVar2 + 0x18);
    (**(code **)(*piVar3 + 0xd0))
              (piVar3,*(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(*piVar5 + 0x18));
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x7c),DAT_0071abb4);
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x84),DAT_0071aa28);
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x78))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x8c),0x3dcccccd);
  }
  else {
    uStack_70 = 0;
    piStack_6c = (int *)0x0;
    uStack_68 = 0;
    uStack_64 = 0;
    uStack_74 = 0x3f000000;
    if (&DAT_00740460 + *(int *)(DAT_00736458 + 4) * 0x18 != (int *)0x0) {
      D3DXMatrixMultiply(&uStack_74,(&DAT_00740460)[*(int *)(DAT_00736458 + 4) * 0x18] + 0x40,
                         &uStack_74);
      piStack_78 = (int *)uStack_74;
      uStack_68 = uStack_64;
      (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x98))
                (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x88),&uStack_80);
      return;
    }
  }
  return;
}


// ==== 0x40eb30 Effect_BindReflectionCube

/* [canon] render high (ghidra-canon) docs/re/render.md */

void Effect_BindReflectionCube(void)

{
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xd0))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x80),DAT_0073646c);
  return;
}


// ==== 0x40eb60 TextureStages_DisableTransform

/* [canon] render high (ghidra-canon) docs/re/render.md */

void TextureStages_DisableTransform(void)

{
  (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,0,0x18,0);
  (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,1,0x18,0);
  (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,2,0x18,0);
  (**(code **)(*DAT_0073636c + 0x10c))(DAT_0073636c,3,0x18,0);
  return;
}


// ==== 0x40ebc0 FUN_0040ebc0

void FUN_0040ebc0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  puVar2 = &DAT_0071abd0;
  do {
    (**(code **)(*(int *)*puVar2 + 0x114))((int *)*puVar2);
    pcVar3 = s_WorldViewProj_00701860;
    puVar4 = puVar2;
    do {
      puVar4 = puVar4 + 1;
      uVar1 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,0,pcVar3);
      *puVar4 = uVar1;
      pcVar3 = pcVar3 + 0x40;
    } while ((int)pcVar3 < 0x702420);
    puVar2 = puVar2 + 0x38;
  } while ((int)puVar2 < 0x71b1f0);
  return;
}


// ==== 0x40ec20 FlareAnim_FractionalPhase

/* [canon] render med (ghidra-canon+hopper) docs/re/render.md */

float10 __fastcall FlareAnim_FractionalPhase(int param_1)

{
  int iVar1;
  int unaff_ESI;
  float10 extraout_ST0;
  
  if (*(char *)(unaff_ESI + 0x52) == '\0') {
    return (float10)0.0;
  }
  if (*(char *)(unaff_ESI + 0x52) == '\x02') {
    param_1 = (int)*(short *)(unaff_ESI + 0x58);
    _ftol_nocw(param_1);
  }
  iVar1 = _ftol_nocw(param_1);
  return extraout_ST0 - (float10)iVar1;
}


// ==== 0x40ec90 FlareAnim_FractionalPhase_B

/* [canon] render med (ghidra-canon+hopper) docs/re/render.md */

float10 __fastcall FlareAnim_FractionalPhase_B(int param_1)

{
  int iVar1;
  int unaff_ESI;
  float10 extraout_ST0;
  
  if (*(char *)(unaff_ESI + 0x52) == '\0') {
    return (float10)0.0;
  }
  if (*(char *)(unaff_ESI + 0x52) == '\x02') {
    param_1 = (int)*(short *)(unaff_ESI + 0x58);
    _ftol_nocw(param_1);
  }
  iVar1 = _ftol_nocw(param_1);
  return extraout_ST0 - (float10)iVar1;
}


// ==== 0x40ed00 bTickerToSeconds

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

float10 bTickerToSeconds(void)

{
  int *in_EAX;
  
  return (float10)*in_EAX * (float10)0.00025;
}


// ==== 0x40ed10 FUN_0040ed10

void FUN_0040ed10(void)

{
  FUN_00410700();
  return;
}


// ==== 0x40ed20 RenderQueueBuckets_Construct

/* [canon] render med (ghidra-canon) docs/re/render.md */

void * __fastcall RenderQueueBuckets_Construct(void *param_1)

{
  eh_vector_constructor_iterator(param_1,8,7,IList_InitEmpty_Thunk,FUN_00410740);
  return param_1;
}


// ==== 0x40ed40 RenderQueueBuckets_Destruct

/* [canon] render med (ghidra-canon) docs/re/render.md */

void __fastcall RenderQueueBuckets_Destruct(void *param_1)

{
  eh_vector_destructor_iterator(param_1,8,7,FUN_00410740);
  return;
}


// ==== 0x40ed50 FUN_0040ed50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ed50(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int *local_c;
  undefined4 *local_8;
  
  DAT_0071b1dc = DAT_0071b1dc + 1;
  piVar7 = &DAT_0078a4e8;
  puVar4 = DAT_0073640c;
  do {
    local_8 = &DAT_0071abd0;
    do {
      puVar5 = local_8;
      if ((int *)*piVar7 != piVar7) {
        local_c = piVar7;
        if (local_8 + -6 != puVar4) {
          if (puVar4 != (undefined4 *)0x0) {
            (**(code **)(*(int *)puVar4[6] + 0x108))((int *)puVar4[6]);
            (*(code *)DAT_0073640c[0x37])();
          }
          DAT_0073640c = puVar5 + -6;
          (*(code *)puVar5[0x30])();
          (**(code **)(*DAT_0073636c + 0x15c))(DAT_0073636c,puVar5[-5]);
          (**(code **)(*(int *)*puVar5 + 0x100))((int *)*puVar5,&local_c,0);
          _gStatEffectSwitches = _gStatEffectSwitches + 1;
          puVar4 = DAT_0073640c;
        }
        piVar6 = (int *)*piVar7;
        if (piVar6 != piVar7) {
          do {
            piVar1 = (int *)piVar6[1];
            iVar3 = *piVar6;
            *piVar1 = iVar3;
            *(int **)(iVar3 + 4) = piVar1;
            DAT_0071b1d8 = DAT_0071b1d8 + 1;
            FUN_0040f3d0(piVar6[4]);
            if ((int *)piVar6[6] != piVar6 + 6) {
              do {
                piVar7 = (int *)piVar6[6];
                iVar3 = *piVar7;
                piVar1 = (int *)piVar7[1];
                *piVar1 = iVar3;
                *(int **)(iVar3 + 4) = piVar1;
                Device_SetWorldMatrix(piVar7[9]);
                if (*(int *)(piVar7[6] + 0x44) != 0) {
                  Effect_SetObjectParams();
                }
                if (piVar7[7] != 0) {
                  RenderQueue_ApplyLights(piVar7[9]);
                }
                if (piVar7[8] != 0) {
                  RenderQueue_ApplyMaterialColors();
                }
                if (piVar7[3] == 0) {
                  iVar3 = piVar7[2];
                  if ((piVar7[10] != 0) && ((*(byte *)(piVar7 + 5) & 1) != 0)) {
                    BonePalette_Load(piVar7[10]);
                  }
                  iVar2 = *(int *)piVar7[4];
                  if (*(int *)(iVar2 + 0x2c) != DAT_007363e8) {
                    (**(code **)(*DAT_0073636c + 400))
                              (DAT_0073636c,0,*(int *)(iVar2 + 0x2c),0,DAT_0073640c[2]);
                    DAT_007363e8 = *(int *)(iVar2 + 0x2c);
                    _gStatStreamSourceChanges = _gStatStreamSourceChanges + 1;
                  }
                  if (*(int *)(iVar2 + 0x20) != DAT_007363ec) {
                    (**(code **)(*DAT_0073636c + 0x1a0))(DAT_0073636c,*(int *)(iVar2 + 0x20));
                    DAT_007363ec = *(int *)(iVar2 + 0x20);
                    _gStatIndexBufferChanges = _gStatIndexBufferChanges + 1;
                  }
                  if ((*(int *)(iVar3 + 0xc) != 0) && (*(uint *)(iVar2 + 0x34) < 0xffff)) {
                    iVar3 = piVar7[6];
                    uVar8 = 0;
                    if (*(int *)(iVar3 + 0x14) != 0) {
                      do {
                        (**(code **)(**(int **)(iVar3 + 0x18) + 0x104))
                                  (*(int **)(iVar3 + 0x18),uVar8);
                        (**(code **)(*DAT_0073636c + 0x148))
                                  (DAT_0073636c,4,0,0,*(undefined4 *)(iVar2 + 0x34),
                                   *(int *)(unaff_EBX + 0x34) - *(int *)(iVar2 + 0x18) >> 1,
                                   *(uint *)(unaff_EBX + 0xc) / 3);
                        iVar3 = piVar7[6];
                        uVar8 = uVar8 + 1;
                      } while (uVar8 < *(uint *)(iVar3 + 0x14));
                    }
                    _DAT_0071b1e0 = _DAT_0071b1e0 + 1;
                    DAT_0071b1f0 = DAT_0071b1f0 + *(uint *)(iVar2 + 0x34) / 3;
                  }
                }
                else {
                  piVar1 = (int *)piVar7[2];
                  uVar8 = 0;
                  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,0);
                  iVar3 = piVar7[6];
                  DAT_007363e8 = 0;
                  if (*(int *)(iVar3 + 0x14) != 0) {
                    do {
                      (**(code **)(**(int **)(iVar3 + 0x18) + 0x104))(*(int **)(iVar3 + 0x18),uVar8)
                      ;
                      (**(code **)(*DAT_0073636c + 0x14c))
                                (DAT_0073636c,5,*piVar1 + -2,piVar1 + 1,0x18);
                      iVar3 = piVar7[6];
                      uVar8 = uVar8 + 1;
                    } while (uVar8 < *(uint *)(iVar3 + 0x14));
                  }
                  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
                  iVar2 = DAT_007363b8;
                  _DAT_0071b1e4 = _DAT_0071b1e4 + 1;
                  iVar3 = *(int *)(DAT_007363b8 + 0x18);
                  *piVar1 = *(int *)(DAT_007363b8 + 0x10);
                  *(int *)(iVar2 + 0x18) = iVar3 + -1;
                  *(int **)(iVar2 + 0x10) = piVar1;
                }
                iVar2 = DAT_007363d8;
                iVar3 = *(int *)(DAT_007363d8 + 0x18);
                *piVar7 = *(int *)(DAT_007363d8 + 0x10);
                *(int *)(iVar2 + 0x18) = iVar3 + -1;
                *(int **)(iVar2 + 0x10) = piVar7;
                puVar5 = local_8;
                piVar7 = local_c;
              } while ((int *)piVar6[6] != piVar6 + 6);
            }
            *(undefined4 *)(*(int *)piVar6[4] + 0x1c) = 0;
            FUN_0040ed10();
            iVar2 = DAT_007363d4;
            iVar3 = *(int *)(DAT_007363d4 + 0x18);
            *piVar6 = *(int *)(DAT_007363d4 + 0x10);
            *(int *)(iVar2 + 0x18) = iVar3 + -1;
            *(int **)(iVar2 + 0x10) = piVar6;
            piVar6 = (int *)*piVar7;
            puVar4 = DAT_0073640c;
          } while (piVar6 != piVar7);
        }
      }
      local_8 = puVar5 + 0x38;
      piVar7 = piVar7 + 2;
    } while ((int)local_8 < 0x71b1f0);
  } while ((int)piVar7 < 0x78a868);
  _gRenderQueueCount = 0;
  return;
}


// ==== 0x40f0f0 RenderQueue_GetBucket

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+ghidra) docs/re/render.md */

void RenderQueue_GetBucket(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_EAX;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *unaff_EDI;
  
  iVar1 = *in_EAX;
  if ((*(int *)(iVar1 + 0x1c) == 0) || (*(int **)(*(int *)(iVar1 + 0x1c) + 0x14) != unaff_EDI)) {
    puVar3 = (undefined4 *)FUN_00567160();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar5 = puVar3 + 6;
      *puVar5 = puVar5;
      puVar3[7] = puVar5;
      puVar3[4] = in_EAX;
      puVar3[2] = 0;
      puVar3[3] = 0;
    }
    *(undefined4 **)(iVar1 + 0x1c) = puVar3;
    if ((char)in_EAX[0x15] == '\0') {
      puVar5 = &DAT_0078a4e8 + (*(char *)((int)in_EAX + 0x51) * 7 + *unaff_EDI) * 2;
    }
    else {
      puVar5 = (undefined4 *)(&DAT_0078a6a8 + (*(char *)((int)in_EAX + 0x51) * 7 + *unaff_EDI) * 8);
    }
    puVar2 = (undefined4 *)puVar5[1];
    *puVar2 = puVar3;
    puVar5[1] = puVar3;
    puVar3[1] = puVar2;
    *puVar3 = puVar5;
    _gRenderQueueCount = _gRenderQueueCount + 1;
  }
  iVar1 = *(int *)(iVar1 + 0x1c);
  piVar4 = (int *)FUN_00567160();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = (int)param_1;
    piVar4[5] = param_2;
    piVar4[7] = param_4;
    piVar4[3] = 1;
    piVar4[4] = 0;
    piVar4[8] = param_5;
    piVar4[9] = param_3;
    piVar4[6] = (int)unaff_EDI;
    piVar4[10] = 0;
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x1c);
  *puVar3 = piVar4;
  *(int **)(iVar1 + 0x1c) = piVar4;
  piVar4[1] = (int)puVar3;
  *piVar4 = iVar1 + 0x18;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(int **)(iVar1 + 0x14) = unaff_EDI;
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + *param_1;
  return;
}


// ==== 0x40f1e0 RenderQueue_GetBucketAlt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render low (hopper+ghidra) docs/re/render.md */

void RenderQueue_GetBucketAlt
               (int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,int param_7
               ,int param_8)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_EAX;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar1 = *in_EAX;
  if ((*(int *)(iVar1 + 0x1c) == 0) || (*(int **)(*(int *)(iVar1 + 0x1c) + 0x14) != param_4)) {
    puVar3 = (undefined4 *)FUN_00567160();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar5 = puVar3 + 6;
      *puVar5 = puVar5;
      puVar3[7] = puVar5;
      puVar3[4] = in_EAX;
      puVar3[2] = 0;
      puVar3[3] = 0;
    }
    *(undefined4 **)(iVar1 + 0x1c) = puVar3;
    if ((char)in_EAX[0x15] == '\0') {
      puVar5 = &DAT_0078a4e8 + (*(char *)((int)in_EAX + 0x51) * 7 + *param_4) * 2;
    }
    else {
      puVar5 = (undefined4 *)(&DAT_0078a6a8 + (*(char *)((int)in_EAX + 0x51) * 7 + *param_4) * 8);
    }
    puVar2 = (undefined4 *)puVar5[1];
    *puVar2 = puVar3;
    puVar5[1] = puVar3;
    puVar3[1] = puVar2;
    *puVar3 = puVar5;
    _gRenderQueueCount = _gRenderQueueCount + 1;
  }
  iVar1 = *(int *)(iVar1 + 0x1c);
  piVar4 = (int *)FUN_00567160();
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = param_1;
    piVar4[4] = param_2;
    piVar4[5] = param_3;
    piVar4[7] = param_6;
    piVar4[8] = param_7;
    piVar4[3] = 0;
    piVar4[9] = param_5;
    piVar4[6] = (int)param_4;
    piVar4[10] = param_8;
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x1c);
  *puVar3 = piVar4;
  *(int **)(iVar1 + 0x1c) = piVar4;
  piVar4[1] = (int)puVar3;
  *piVar4 = iVar1 + 0x18;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(int **)(iVar1 + 0x14) = param_4;
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + *(int *)(param_1 + 0xc);
  return;
}


// ==== 0x40f2e0 RenderQueue_PoolsCreate

/* [canon] render high (hopper+ghidra) docs/re/render.md */

void RenderQueue_PoolsCreate(void)

{
  undefined4 *puVar1;
  
  DAT_007364f0 = (undefined4 *)FUN_00566dc0(4,"eAnimTextureSlotPool",0);
  if ((DAT_007364f0 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007364f0;
    puVar1 = DAT_007364f0;
    DAT_007364f0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007364f0 = &DAT_0073d818;
  }
  DAT_007364f0[5] = DAT_007364f0[5] & 0xfffffffd;
  DAT_007363d4 = (undefined4 *)FUN_00566dc0(0x20,"eTextureBucketSlotPool",0);
  if ((DAT_007363d4 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007363d4;
    puVar1 = DAT_007363d4;
    DAT_007363d4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007363d4 = &DAT_0073d818;
  }
  DAT_007363d4[5] = DAT_007363d4[5] & 0xfffffffd;
  DAT_007363d8 = (undefined4 *)FUN_00566dc0(0x2c,"eMeshRender",0);
  if (DAT_007363d8 == (undefined4 *)0x0) {
    uRam00000014 = uRam00000014 & 0xfffffffd;
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007363d8;
    puVar1 = DAT_007363d8;
    DAT_007363d8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007363d8 = &DAT_0073d818;
  }
  DAT_007363d8[5] = DAT_007363d8[5] & 0xfffffffd;
  return;
}


// ==== 0x40f3d0 FUN_0040f3d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040f3d0(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  float10 fVar4;
  int iStack_84;
  float fVar5;
  float fStack_74;
  undefined1 auStack_68 [32];
  float fStack_48;
  float fStack_44;
  
  if ((DAT_00736404 != param_1) || (DAT_00736408 != DAT_0073640c)) {
    iStack_84 = *(int *)(*param_1 + 0x18);
    DAT_00736404 = param_1;
    if (iStack_84 != 0) {
      if (DAT_0073640c == (int *)0x0) {
        (**(code **)(*DAT_0073636c + 0x104))(DAT_0073636c,0);
      }
      else {
        (**(code **)(*(int *)DAT_0073640c[6] + 0xd0))((int *)DAT_0073640c[6],DAT_0073640c[0x10]);
      }
      FUN_00410650();
      if (*(char *)((int)param_1 + 0x56) == '\0') {
        _DAT_007070cc = 0xffffffff;
        _DAT_007070c8 = 0xffffffff;
        if (DAT_0073640c == (int *)0x0) {
          (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x1b);
          _DAT_007070d0 = 0;
        }
        else {
          (**(code **)(*(int *)DAT_0073640c[6] + 0x68))((int *)DAT_0073640c[6],DAT_0073640c[0x31],0)
          ;
          _DAT_007070d0 = 0;
        }
      }
      else {
        FUN_00410550(1);
      }
      if (*(char *)((int)param_1 + 0x56) == '\0') {
        if (*DAT_0073640c == 5) {
          (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x16,1);
        }
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
      }
      else if (*DAT_0073640c == 5) {
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x16,2);
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,1);
      }
      else {
        (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xe,0);
      }
      piVar3 = DAT_0073640c;
      uVar2 = DAT_00701094;
      if (DAT_0073640c[0x34] != 0) {
        fVar5 = 0.0;
        fStack_74 = 0.0;
        if ((DAT_00700ea4 != 0) &&
           (((*DAT_0073640c == 0 || (*DAT_0073640c == 1)) &&
            (*(char *)((int)param_1 + 0x52) != '\0')))) {
          fVar1 = (float)DAT_0073ad34 * 0.00025;
          if (*(char *)((int)param_1 + 0x52) == '\x03') {
            fVar5 = (float)(int)*(short *)((int)param_1 + 0x5e) * -3.0517578e-05;
            fVar4 = (float10)(int)(short)param_1[0x18] * (float10)-3.0517578e-05;
          }
          else if ((_DAT_007363e0 == 0.0) && (_DAT_007363e4 == 0.0)) {
            fVar4 = (float10)FlareAnim_FractionalPhase(fVar1);
            fVar5 = (float)fVar4;
            fVar4 = (float10)FlareAnim_FractionalPhase_B(fVar1);
          }
          else {
            fVar4 = (float10)FUN_00546180(param_1,fVar1,
                                          _DAT_007363e0 / (float)(int)(short)param_1[0x11],
                                          DAT_00701094);
            fVar5 = (float)fVar4;
            fVar4 = (float10)FUN_00546180(param_1,fVar1,
                                          _DAT_007363e4 /
                                          (float)(int)*(short *)((int)param_1 + 0x46),uVar2);
            piVar3 = DAT_0073640c;
          }
          fStack_74 = (float)fVar4;
        }
        FUN_00565020();
        fStack_44 = fStack_74;
        fStack_48 = fVar5;
        (**(code **)(*(int *)piVar3[6] + 0x98))((int *)piVar3[6],piVar3[0x35],auStack_68);
        (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
                  ((int *)DAT_0073640c[6],DAT_0073640c[0x34],&iStack_84);
      }
    }
  }
  return;
}


// ==== 0x40f6e0 FUN_0040f6e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040f6e0(float *param_1)

{
  float fVar1;
  
  fVar1 = _K_ONE;
  if (*param_1 < _K_ONE) {
    fVar1 = *param_1;
  }
  *param_1 = fVar1;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  *param_1 = fVar1;
  fVar1 = _K_ONE;
  if (param_1[1] < _K_ONE) {
    fVar1 = param_1[1];
  }
  param_1[1] = fVar1;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  param_1[1] = fVar1;
  fVar1 = _K_ONE;
  if (param_1[2] < _K_ONE) {
    fVar1 = param_1[2];
  }
  param_1[2] = fVar1;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  param_1[2] = fVar1;
  fVar1 = _K_ONE;
  if (param_1[3] < _K_ONE) {
    fVar1 = param_1[3];
  }
  param_1[3] = fVar1;
  if (fVar1 <= 0.0) {
    param_1[3] = 0.0;
    return;
  }
  param_1[3] = fVar1;
  return;
}


// ==== 0x40f7c0 RenderQueue_ApplyLights

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+ghidra+capstone) docs/re/render.md */

void RenderQueue_ApplyLights(undefined4 param_1)

{
  float fVar1;
  float *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float local_f0 [12];
  float local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined1 local_90 [12];
  undefined1 auStack_84 [12];
  undefined4 local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  
  if ((*DAT_0073640c == 5) && (DAT_0073640c[3] != 0)) {
    fVar1 = _DAT_00701098 * in_EAX[0x4b];
    FUN_0040f6e0();
    iVar2 = _ftol_nocw();
    uVar3 = _ftol_nocw();
    uVar4 = _ftol_nocw();
    uVar5 = _ftol_nocw();
    local_bc = in_EAX[0x14];
    local_b8 = in_EAX[0x18];
    local_b0 = in_EAX[0x11];
    local_ac = in_EAX[0x15];
    local_a0 = in_EAX[0x12];
    local_a8 = in_EAX[0x19];
    local_9c = in_EAX[0x16];
    local_98 = in_EAX[0x1a];
    local_c0 = in_EAX[0x10];
    local_f0[0] = *in_EAX * 0.00390625;
    local_b4 = 0;
    local_a4 = 0;
    local_94 = 0.0;
    local_f0[1] = in_EAX[1] * 0.00390625;
    local_f0[2] = in_EAX[2] * 0.00390625;
    local_f0[4] = in_EAX[4] * 0.00390625;
    local_f0[5] = in_EAX[5] * 0.00390625;
    iVar7 = 0;
    local_f0[6] = in_EAX[6] * 0.00390625;
    local_f0[8] = in_EAX[8] * 0.00390625;
    local_f0[9] = in_EAX[9] * 0.00390625;
    iVar6 = 0;
    local_f0[10] = in_EAX[10] * 0.00390625;
    do {
      local_74 = _DAT_0070109c * *(float *)((int)local_f0 + iVar6);
      local_54 = 0;
      local_50 = 0;
      local_70 = _DAT_0070109c * *(float *)((int)local_f0 + iVar6 + 4);
      local_4c = 0;
      local_6c = _DAT_0070109c * *(float *)((int)local_f0 + iVar6 + 8);
      local_78 = 3;
      local_64 = _DAT_007010a0 * *(float *)((int)local_f0 + iVar6);
      local_60 = _DAT_007010a0 * *(float *)((int)local_f0 + iVar6 + 4);
      local_5c = _DAT_007010a0 * *(float *)((int)local_f0 + iVar6 + 8);
      local_48 = fVar1;
      thunk_FUN_005ac436(local_90,(int)&local_c0 + iVar6,param_1);
      fStack_44 = -local_9c;
      fStack_40 = -local_98;
      fStack_3c = -local_94;
      (**(code **)(*DAT_0073636c + 0xcc))(DAT_0073636c,iVar7,auStack_84);
      (**(code **)(*DAT_0073636c + 0xd4))(DAT_0073636c,iVar7,1);
      iVar6 = iVar6 + 0x10;
      iVar7 = iVar7 + 1;
    } while (iVar6 < 0x30);
    (**(code **)(*(int *)DAT_0073640c[6] + 0x68))
              ((int *)DAT_0073640c[6],DAT_0073640c[0x13],
               ((iVar2 << 8 | uVar3) << 8 | uVar4) << 8 | uVar5);
    return;
  }
  (**(code **)(*(int *)DAT_0073640c[6] + 0x90))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x12],in_EAX + 0x48,10);
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
            ((int *)DAT_0073640c[6],DAT_0073640c[0xf],in_EAX + 0x30);
  return;
}


// ==== 0x40fae0 RenderQueue_ApplyMaterialColors

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra-canon+capstone) docs/re/render.md */

void __fastcall RenderQueue_ApplyMaterialColors(int param_1)

{
  int iVar1;
  int *piVar2;
  uint in_EAX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_18;
  
  local_110 = *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x30);
  local_10c = *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x30);
  local_108 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x30);
  local_104 = *(float *)(param_1 + 0x50);
  local_e0 = *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x40) - local_110;
  local_dc = *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x40) - local_10c;
  local_d8 = *(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x40) - local_108;
  local_d4 = *(float *)(param_1 + 0x54) - local_104;
  local_100 = *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x5c);
  local_fc = *(float *)(param_1 + 100) * *(float *)(param_1 + 0x5c);
  local_f8 = *(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x5c);
  local_c0 = *(float *)(param_1 + 0x70) * *(float *)(param_1 + 0x6c) - local_100;
  local_bc = *(float *)(param_1 + 0x74) * *(float *)(param_1 + 0x6c) - local_fc;
  local_b8 = *(float *)(param_1 + 0x78) * *(float *)(param_1 + 0x6c) - local_f8;
  local_f0 = *(float *)(param_1 + 0x84) * *(float *)(param_1 + 0x80) * _K_HALF;
  local_ec = *(float *)(param_1 + 0x88) * *(float *)(param_1 + 0x80) * _K_HALF;
  local_e8 = *(float *)(param_1 + 0x8c) * *(float *)(param_1 + 0x80) * _K_HALF;
  local_d0 = *(float *)(param_1 + 0x94) * *(float *)(param_1 + 0x90) * _K_HALF - local_f0;
  local_cc = *(float *)(param_1 + 0x98) * *(float *)(param_1 + 0x90) * _K_HALF - local_ec;
  local_c8 = *(float *)(param_1 + 0x9c) * *(float *)(param_1 + 0x90) * _K_HALF - local_e8;
  if (((in_EAX & 0x100) == 0) || (DAT_00700e74 == 0)) {
    local_f0 = 0.0;
    local_ec = 0.0;
    local_e8 = 0.0;
    local_d0 = 0.0;
    local_cc = 0.0;
    local_c8 = 0.0;
  }
  else if (-1 < (char)in_EAX) {
    local_110 = 0.0;
    local_10c = 0.0;
    local_108 = 0.0;
    local_104 = 0.0;
    local_e0 = 0.0;
    local_dc = 0.0;
    local_d8 = 0.0;
    local_d4 = 0.0;
    local_100 = 0.0;
    local_fc = 0.0;
    local_f8 = 0.0;
    local_c0 = 0.0;
    local_bc = 0.0;
    local_b8 = 0.0;
  }
  local_b4 = 0;
  local_c4 = 0;
  local_e4 = 0;
  local_f4 = 0;
  if ((*DAT_0073640c == 5) && (DAT_0073640c[3] != 0)) {
    local_ac = 0x3f800000;
    local_b0 = 0x3f800000;
    local_a0 = 0;
    local_a8 = 0x3f800000;
    local_68 = local_e0 * _K_HALF + local_110;
    local_a4 = 0x3f800000;
    local_98 = 0;
    local_9c = 0;
    local_94 = 0x3f800000;
    local_5c = 0x3f800000;
    local_64 = local_dc * _K_HALF + local_10c;
    local_3c = 0x3f800000;
    local_60 = local_d8 * _K_HALF + local_108;
    local_90 = local_c0 * _K_HALF + local_100;
    local_58 = 0x3f800000;
    local_8c = local_bc * _K_HALF + local_fc;
    local_4c = 0x3f800000;
    local_30 = 0;
    local_54 = 0x3f800000;
    local_88 = local_b8 * _K_HALF + local_f8;
    local_38 = 0;
    local_50 = 0x3f800000;
    local_80 = local_d0 * _K_HALF + local_f0;
    local_34 = 0;
    local_2c = 0x3f800000;
    local_7c = local_cc * _K_HALF + local_ec;
    local_78 = local_c8 * _K_HALF + local_e8;
    local_28 = _DAT_007010a8 * *(float *)(param_1 + 0x58);
    if (local_28 < 0.1) {
      local_28 = 0.1;
    }
    local_48 = local_90;
    local_44 = local_8c;
    local_40 = local_88;
    local_18 = local_60;
    (**(code **)(*DAT_0073636c + 0xc4))(DAT_0073636c,&local_68);
    piVar2 = DAT_0073636c;
    iVar1 = *DAT_0073636c;
    iVar3 = _ftol_nocw();
    uVar4 = _ftol_nocw();
    uVar5 = _ftol_nocw();
    uVar6 = _ftol_nocw();
    (**(code **)(iVar1 + 0xe4))(piVar2,0x3c,((iVar3 << 8 | uVar4) << 8 | uVar5) << 8 | uVar6);
    return;
  }
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x14],&local_110);
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))((int *)DAT_0073640c[6],DAT_0073640c[0x15],&local_ec)
  ;
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x16],&stack0xfffffee8);
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))((int *)DAT_0073640c[6],DAT_0073640c[0x17],&local_e4)
  ;
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x19],&stack0xfffffee0);
  (**(code **)(*(int *)DAT_0073640c[6] + 0x88))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x1a],&local_10c);
  (**(code **)(*(int *)DAT_0073640c[6] + 0x78))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x18],_DAT_007070d4 * *(float *)(param_1 + 0x58));
  (**(code **)(*(int *)DAT_0073640c[6] + 0x78))
            ((int *)DAT_0073640c[6],DAT_0073640c[0x1b],*(undefined4 *)(param_1 + 0x7c));
  return;
}


// ==== 0x4100a0 Effect_SetObjectParams

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render low (ghidra) docs/re/render.md */

void Effect_SetObjectParams(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  float *pfVar4;
  float fStack_138;
  int iStack_134;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  float fStack_dc;
  float afStack_a8 [3];
  undefined1 auStack_9c [12];
  undefined1 local_90 [28];
  undefined1 auStack_74 [112];
  
  iVar1 = *in_EAX;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_f8 = 0x3f800000;
  local_f4 = 0;
  local_e8 = 0;
  local_e4 = 0x3f800000;
  local_f0 = 0x3f000000;
  local_ec = 0x3f000000;
  iStack_134 = iVar1 + 0x80;
  D3DXMatrixMultiply(local_90);
  D3DXMatrixMultiply(auStack_9c,auStack_9c,&stack0xfffffed4);
  if (*(int *)(DAT_0073640c + 0xc) == 0) {
    piVar2 = *(int **)(DAT_0073640c + 0x18);
    uVar3 = *(undefined4 *)(DAT_0073640c + 0x38);
    iVar1 = *piVar2;
    pfVar4 = afStack_a8;
  }
  else {
    Matrix_InvertRigid();
    D3DXMatrixMultiply(&local_e8,iVar1 + 0x80,&fStack_138);
    D3DXMatrixMultiply(&local_f4,auStack_74,&local_f4);
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x98))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x38),&local_100);
    fStack_138 = fStack_dc * 0.005;
    iStack_134 = 0;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0x3f800000;
    pfVar4 = &fStack_138;
    piVar2 = *(int **)(DAT_0073640c + 0x18);
    uVar3 = *(undefined4 *)(DAT_0073640c + 0xb8);
    iVar1 = *piVar2;
  }
  (**(code **)(iVar1 + 0x98))(piVar2,uVar3,pfVar4);
  local_fc = DAT_007010b4;
  local_104 = DAT_007010ac;
  local_100 = DAT_007010b0;
  local_f8 = 0;
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x88))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x70),&local_104);
  return;
}


// ==== 0x4102f0 BonePalette_Load

/* [canon] render med (hopper+ghidra) docs/re/render.md */

void BonePalette_Load(int param_1)

{
  int in_EAX;
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_414;
  undefined1 local_410 [64];
  undefined4 local_3d0 [243];
  
  pbVar1 = (byte *)(in_EAX + 0x22);
  puVar3 = local_3d0;
  local_414 = 2;
  do {
    puVar4 = (undefined4 *)((uint)pbVar1[-1] * 0x40 + param_1);
    puVar5 = puVar3 + -0x10;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)*pbVar1 * 0x40 + param_1);
    puVar5 = puVar3;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[1] * 0x40 + param_1);
    puVar5 = puVar3 + 0x10;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[2] * 0x40 + param_1);
    puVar5 = puVar3 + 0x20;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[3] * 0x40 + param_1);
    puVar5 = puVar3 + 0x30;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[4] * 0x40 + param_1);
    puVar5 = puVar3 + 0x40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[5] * 0x40 + param_1);
    puVar5 = puVar3 + 0x50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)((uint)pbVar1[6] * 0x40 + param_1);
    puVar5 = puVar3 + 0x60;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    pbVar1 = pbVar1 + 8;
    puVar3 = puVar3 + 0x80;
    local_414 = local_414 + -1;
  } while (local_414 != 0);
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0xa0))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0x34),local_410,0x10);
  return;
}


// ==== 0x410400 Device_SetWorldMatrix

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void Device_SetWorldMatrix(undefined *param_1)

{
  int iVar1;
  int unaff_EDI;
  undefined1 local_90 [52];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [76];
  
  DAT_0071b1f4 = DAT_0071b1f4 + 1;
  if (param_1 == &DAT_0078bcc0) {
    _DAT_0071b200 = _DAT_0071b200 + 1;
  }
  if (((param_1 != DAT_0078eb80) || (DAT_0073640c != DAT_0078eb7c)) || (DAT_007010b8 != unaff_EDI))
  {
    iVar1 = (&DAT_00740460)[unaff_EDI * 0x18];
    if (unaff_EDI != DAT_007010b8) {
      if (DAT_00736414 != 0) {
        (**(code **)(*DAT_0073636c + 0xb0))(DAT_0073636c,2,iVar1);
        (**(code **)(*DAT_0073636c + 0xb0))(DAT_0073636c,3,iVar1 + 0x40);
      }
      DAT_0071b1fc = DAT_0071b1fc + 1;
      DAT_007010b8 = unaff_EDI;
    }
    _DAT_0071b1f8 = _DAT_0071b1f8 + 1;
    DAT_0078eb80 = param_1;
    DAT_0078eb7c = DAT_0073640c;
    if ((*DAT_0073640c == 5) && (DAT_00736418 != 0)) {
      D3DXMatrixMultiply(local_90,param_1,iVar1);
      (**(code **)(*(int *)DAT_0073640c[6] + 0x98))
                ((int *)DAT_0073640c[6],DAT_0073640c[9],&stack0xffffff64);
    }
    if (DAT_00736414 != 0) {
      (**(code **)(*DAT_0073636c + 0xb0))(DAT_0073636c,0x100,param_1);
    }
    if (DAT_00736418 != 0) {
      D3DXMatrixMultiply(auStack_50,param_1,iVar1 + 0x80);
      (**(code **)(*(int *)DAT_0073640c[6] + 0x98))
                ((int *)DAT_0073640c[6],DAT_0073640c[7],auStack_5c);
    }
  }
  return;
}


// ==== 0x410550 FUN_00410550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410550(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  if (param_1 == 0) {
    _DAT_007070cc = 0xffffffff;
    _DAT_007070c8 = 0xffffffff;
    if (DAT_0073640c == 0) {
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x1b);
      _DAT_007070d0 = param_1;
      return;
    }
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xc4),0);
    _DAT_007070d0 = 0;
    return;
  }
  if (DAT_0073640c == 0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x1b);
  }
  else {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xc4),1);
  }
  _DAT_007070d0 = param_1;
  if (DAT_0073640c == 0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x13);
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x14);
    _DAT_007070cc = unaff_EDI;
    _DAT_007070c8 = unaff_ESI;
    return;
  }
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 200));
  (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
            (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xcc));
  _DAT_007070cc = unaff_EDI;
  _DAT_007070c8 = unaff_ESI;
  return;
}


// ==== 0x410650 FUN_00410650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410650(void)

{
  undefined4 unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI == 0) {
    if (DAT_0073640c == 0) {
      (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xf);
      _DAT_007070c4 = unaff_EDI;
    }
    else {
      (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
                (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xbc));
      _DAT_007070c4 = 0;
    }
  }
  else if (DAT_0073640c == 0) {
    (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0xf);
    _DAT_007070c4 = unaff_EDI;
  }
  else {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xbc),1);
    _DAT_007070c4 = unaff_EDI;
  }
  if (DAT_0073640c != 0) {
    (**(code **)(**(int **)(DAT_0073640c + 0x18) + 0x68))
              (*(int **)(DAT_0073640c + 0x18),*(undefined4 *)(DAT_0073640c + 0xc0));
    _DAT_007070c0 = unaff_ESI;
    return;
  }
  (**(code **)(*DAT_0073636c + 0xe4))(DAT_0073636c,0x18);
  _DAT_007070c0 = unaff_ESI;
  return;
}


// ==== 0x410700 FUN_00410700

void FUN_00410700(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007363d8;
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x410740 FUN_00410740

void __fastcall FUN_00410740(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = DAT_007363d4;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_0040ed10();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x410780 FUN_00410780

void FUN_00410780(void)

{
  undefined4 *puVar1;
  
  DAT_007363b8 = (undefined4 *)FUN_00566dc0(0x604,"eStripSlotPool",0);
  if (DAT_007363b8 == (undefined4 *)0x0) {
    uRam00000014 = uRam00000014 & 0xfffffffd;
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007363b8;
    puVar1 = DAT_007363b8;
    DAT_007363b8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007363b8 = &DAT_0073d818;
  }
  DAT_007363b8[5] = DAT_007363b8[5] & 0xfffffffd;
  return;
}


// ==== 0x4107e0 FUN_004107e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004107e0(undefined4 param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  DAT_007363bc = FUN_00567160();
  DAT_007363c8 = 0;
  DAT_007363cc = 0;
  DAT_007363d0 = 0;
  DAT_007363c4 = param_1;
  if (in_EAX != (undefined4 *)0x0) {
    puVar2 = &DAT_0078a4a0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar2 = puVar2 + 1;
    }
    return 1;
  }
  DAT_0078a4a0 = 0x3f800000;
  DAT_0078a4a4 = 0;
  _DAT_0078a4a8 = 0;
  _DAT_0078a4ac = 0;
  _DAT_0078a4b0 = 0;
  _DAT_0078a4b4 = 0x3f800000;
  _DAT_0078a4b8 = 0;
  _DAT_0078a4bc = 0;
  _DAT_0078a4c0 = 0;
  _DAT_0078a4c4 = 0;
  _DAT_0078a4c8 = 0x3f800000;
  _DAT_0078a4cc = 0;
  _DAT_0078a4d0 = 0;
  _DAT_0078a4d4 = 0;
  _DAT_0078a4d8 = 0;
  _DAT_0078a4dc = 0x3f800000;
  return 1;
}


// ==== 0x4108d0 ImmBuf_PushColor

/* [canon] render med (ghidra-canon) docs/re/car.md */

void ImmBuf_PushColor(uint param_1)

{
  *(uint *)(DAT_007363bc + 0x10 + DAT_007363d0 * 0x18) =
       (((param_1 >> 0x18) << 8 | param_1 & 0xff) << 8 | param_1 >> 8 & 0xff) << 8 |
       param_1 >> 0x10 & 0xff;
  DAT_007363d0 = DAT_007363d0 + 1;
  return;
}


// ==== 0x410910 ImmBuf_PushTexCoord

/* [canon] render med (ghidra-canon) docs/re/car.md */

void ImmBuf_PushTexCoord(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_007363bc + DAT_007363cc * 0x18;
  *(undefined4 *)(iVar1 + 0x14) = param_1;
  *(undefined4 *)(iVar1 + 0x18) = param_2;
  DAT_007363cc = DAT_007363cc + 1;
  return;
}


// ==== 0x410940 ImmBuf_PushPosition

/* [canon] render med (ghidra-canon) docs/re/car.md */

void __fastcall ImmBuf_PushPosition(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_007363bc + DAT_007363c8 * 0x18;
  *(undefined4 *)(iVar1 + 4) = *param_1;
  *(undefined4 *)(iVar1 + 8) = param_1[1];
  *(undefined4 *)(iVar1 + 0xc) = param_1[2];
  DAT_007363c8 = DAT_007363c8 + 1;
  return;
}


// ==== 0x410970 ImmBuf_PushColor2

/* [canon] render med (ghidra-canon) docs/re/car.md */

void ImmBuf_PushColor2(uint param_1)

{
  *(uint *)(DAT_007363bc + 0x10 + DAT_007363d0 * 0x18) =
       (((param_1 >> 0x18) << 8 | param_1 & 0xff) << 8 | param_1 >> 8 & 0xff) << 8 |
       param_1 >> 0x10 & 0xff;
  DAT_007363d0 = DAT_007363d0 + 1;
  return;
}


// ==== 0x4109c0 RenderQueue_SelectDefaultBucket

/* [canon] render med (ghidra-canon+hopper) docs/re/render.md */

undefined4 RenderQueue_SelectDefaultBucket(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_007363bc;
  *DAT_007363bc = DAT_007363c8;
  RenderQueue_GetBucket(puVar1,0,&DAT_0078a4a0,0,0);
  return 1;
}


// ==== 0x4109f0 FUN_004109f0

void FUN_004109f0(void)

{
  return;
}


// ==== 0x410a00 FUN_00410a00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410a00(void)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)MachinePerformanceScore();
  _DAT_00701088 = (float)fVar2;
  if (DAT_0071daf0 < 0x400) {
    iVar1 = FUN_00411b00();
    if (iVar1 != 0) {
      DAT_007363b5 = 1;
    }
  }
  if (_DAT_00701088 < 0.3) {
    GraphicsQuality_Set();
    return;
  }
  DAT_00700eb4 = 1;
  DAT_00700e70 = 1;
  DAT_00700ea8 = 1;
  DAT_00700ea4 = 1;
  DAT_00700ea0 = 1;
  if (_DAT_00701088 < 0.6) {
    DAT_00736334 = 1;
    DAT_00700e74 = 1;
    DAT_00700e7c = 1;
    DAT_00700e90 = 1;
    DAT_00700eb0 = 1;
    DAT_00700e78 = 0;
    DAT_00700e80 = 0;
    DAT_00700e84 = 0;
    DAT_00700e88 = 0;
    DAT_00700e8c = 0;
    DAT_00700e94 = 0;
    DAT_00700e98 = 0;
    DAT_00700e9c = 0;
    DAT_00700eac = 0;
    RenderOptions_ClampToLimits();
    return;
  }
  DAT_00700eac = 1;
  DAT_00700e94 = 1;
  DAT_00700e8c = 1;
  DAT_00700e88 = 1;
  DAT_00700e84 = 1;
  DAT_00700e80 = 1;
  DAT_00700e78 = 1;
  DAT_00700e90 = 2;
  DAT_00700e7c = 2;
  if (_DAT_00701088 < 0.9) {
    DAT_00736334 = 2;
    DAT_00700e74 = 2;
    DAT_00700e98 = 0;
    DAT_00700e9c = 0;
    DAT_00700eb0 = 3;
    RenderOptions_ClampToLimits();
    return;
  }
  DAT_00700e98 = 1;
  DAT_00700e9c = 1;
  DAT_00736334 = 3;
  DAT_00700e74 = 3;
  DAT_00700eb0 = 3;
  RenderOptions_ClampToLimits();
  return;
}


// ==== 0x410b70 RenderOptions_LimitsFromDeviceCaps

/* [canon] render high (ghidra-canon) docs/re/render.md */

void RenderOptions_LimitsFromDeviceCaps(void)

{
  if ((DAT_0071b648 == 0x8086) && (DAT_0071b64c == 0x2572)) {
    DAT_00701084 = 0;
  }
  if (DAT_0071b024 < 2) {
    DAT_00701040 = 3;
  }
  else {
    DAT_00701040 = 0;
  }
  DAT_00701044 = (uint)(DAT_0071b024 < 2);
  if ((2 < DAT_0071aca4) || (DAT_0070104c = 1, 2 < DAT_0071ae64)) {
    DAT_0070104c = 0;
  }
  if ((DAT_0071af48 == 0) ||
     (((DAT_0071b648 == 0x10de && (0x16f < DAT_0071b64c)) && (DAT_0071b64c < 0x183)))) {
    DAT_00701058 = 0;
  }
  else {
    DAT_00701058 = 1;
  }
  DAT_0070105c = (-(uint)(2 < DAT_0071ad84) & 0xfffffffe) + 2;
  if (DAT_0071b108 == 0) {
    DAT_00701064 = 0;
    DAT_00701068 = 0;
    return;
  }
  DAT_00701064 = 1;
  DAT_00701068 = 1;
  return;
}


// ==== 0x410c50 Display_ProbeResolutions

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra) docs/re/render.md */

void Display_ProbeResolutions(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int iStack_1c;
  
  _DAT_0071b7b0 = 0;
  DAT_0071b7b4 = 0;
  DAT_0071b7b8 = 0;
  DAT_0071b7bc = 0;
  iStack_1c = 0x16;
  DAT_0071b7c0 = 0;
  iVar1 = (**(code **)(*DAT_00736368 + 0x18))(DAT_00736368,0);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(*DAT_00736368 + 0x1c))(DAT_00736368,0,0x16,iVar3,&iStack_1c);
      if (iVar2 == 0) {
        iVar2 = 0;
        do {
          if ((iStack_1c == *(int *)(&DAT_0070100c + iVar2)) &&
             (unaff_EDI == *(int *)(&DAT_00701020 + iVar2))) {
            *(undefined4 *)(&DAT_0071b7b0 + iVar2) = 1;
          }
          iVar2 = iVar2 + 4;
        } while (iVar2 < 0x14);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// ==== 0x410ce0 RenderOptions_ClampToLimits

/* [canon] render high (ghidra-canon) docs/re/render.md */

void RenderOptions_ClampToLimits(void)

{
  int iVar1;
  
  if (DAT_00701040 < DAT_00700e74) {
    DAT_00700e74 = DAT_00701040;
  }
  if (DAT_00701044 < DAT_00700e78) {
    DAT_00700e78 = DAT_00701044;
  }
  if (DAT_00701048 < DAT_00700e7c) {
    DAT_00700e7c = DAT_00701048;
  }
  if (DAT_0070104c < DAT_00700e80) {
    DAT_00700e80 = DAT_0070104c;
  }
  if (DAT_00701050 < DAT_00700e84) {
    DAT_00700e84 = DAT_00701050;
  }
  if (DAT_00701054 < DAT_00700e88) {
    DAT_00700e88 = DAT_00701054;
  }
  if (DAT_00701058 < DAT_00700e8c) {
    DAT_00700e8c = DAT_00701058;
  }
  if (DAT_0070105c < DAT_00700e90) {
    DAT_00700e90 = DAT_0070105c;
  }
  if (DAT_00701060 < DAT_00700e94) {
    DAT_00700e94 = DAT_00701060;
  }
  if (DAT_00701064 < DAT_00700e98) {
    DAT_00700e98 = DAT_00701064;
  }
  if (DAT_00701068 < DAT_00700e9c) {
    DAT_00700e9c = DAT_00701068;
  }
  if (DAT_0070106c < DAT_00700ea0) {
    DAT_00700ea0 = DAT_0070106c;
  }
  if (DAT_00701070 < DAT_00700ea4) {
    DAT_00700ea4 = DAT_00701070;
  }
  if (DAT_00701074 < DAT_00700ea8) {
    DAT_00700ea8 = DAT_00701074;
  }
  if (DAT_00701078 < DAT_00700eac) {
    DAT_00700eac = DAT_00701078;
  }
  if (DAT_0070107c < DAT_00700eb0) {
    DAT_00700eb0 = DAT_0070107c;
  }
  if (DAT_00701080 < DAT_00700eb4) {
    DAT_00700eb4 = DAT_00701080;
  }
  iVar1 = DAT_00700e70;
  if (*(int *)(&DAT_0071b7b0 + DAT_00700e70 * 4) == 0) {
    for (; -1 < iVar1; iVar1 = iVar1 + 1) {
      if (*(int *)(&DAT_0071b7b0 + iVar1 * 4) != 0) {
        DAT_00700e70 = iVar1;
      }
    }
  }
  return;
}


// ==== 0x410e50 DeviceCaps_Init

/* [canon] render high (hopper+ghidra+capstone) docs/re/render.md */

void DeviceCaps_Init(void)

{
  uint uVar1;
  
  if (DAT_00736390 == 0) {
    (**(code **)(*DAT_0073636c + 0x1c))(DAT_0073636c,&DAT_0071b670);
    (**(code **)(*DAT_00736368 + 0x14))(DAT_00736368,DAT_00736398,2,0x71b220);
    RenderOptions_LimitsFromDeviceCaps();
    FUN_00410a00();
    if ((DAT_0071b710 != 0xffffffff) && (uVar1 = 0, DAT_0071b710 != 0)) {
      do {
        (**(code **)(*DAT_0073636c + 0xd4))(DAT_0073636c,uVar1,0);
        uVar1 = uVar1 + 1;
      } while (uVar1 < DAT_0071b710);
    }
  }
  DAT_00736390 = 1;
  return;
}


// ==== 0x410ed0 GraphicsQuality_Set

/* [canon] render high (ghidra+capstone) docs/re/render.md */

void __fastcall GraphicsQuality_Set(undefined4 param_1,int param_2)

{
  DAT_00700ea4 = 1;
  DAT_00700ea0 = 1;
  DAT_00736334 = param_2;
  if (param_2 == 0) {
    DAT_00700e74 = 0;
    DAT_00700e78 = 0;
    DAT_00700e7c = 1;
    DAT_00700e80 = 0;
    DAT_00700e84 = 1;
    DAT_00700e88 = 0;
    DAT_00700e8c = 0;
    DAT_00700e90 = 0;
    DAT_00700e94 = 0;
    DAT_00700e98 = 0;
    DAT_00700e9c = 0;
    DAT_00700ea8 = 0;
    DAT_00700eac = 0;
    DAT_00700e70 = 0;
    DAT_00700eb0 = 1;
    DAT_00700eb4 = 0;
    RenderOptions_ClampToLimits();
    return;
  }
  DAT_00700eb4 = 1;
  DAT_00700e70 = 1;
  DAT_00700ea8 = 1;
  if (param_2 == 1) {
    DAT_00700e74 = 1;
    DAT_00700e78 = 0;
    DAT_00700e7c = 1;
    DAT_00700e80 = 0;
    DAT_00700e84 = 0;
    DAT_00700e88 = 0;
    DAT_00700e8c = 0;
    DAT_00700e90 = 1;
    DAT_00700e94 = 0;
    DAT_00700e98 = 0;
    DAT_00700e9c = 0;
    DAT_00700eac = 0;
    DAT_00700eb0 = 1;
    RenderOptions_ClampToLimits();
    return;
  }
  DAT_00700eac = 1;
  DAT_00700e94 = 1;
  DAT_00700e90 = 2;
  DAT_00700e8c = 1;
  DAT_00700e88 = 1;
  DAT_00700e84 = 1;
  DAT_00700e80 = 1;
  DAT_00700e7c = 2;
  DAT_00700e78 = 1;
  if (param_2 == 2) {
    DAT_00700e74 = 2;
    DAT_00700e98 = 0;
    DAT_00700e9c = 0;
    DAT_00700eb0 = 3;
    RenderOptions_ClampToLimits();
    return;
  }
  DAT_00700e74 = 3;
  DAT_00700e98 = 1;
  DAT_00700e9c = 1;
  DAT_00700eb0 = 3;
  RenderOptions_ClampToLimits();
  return;
}


