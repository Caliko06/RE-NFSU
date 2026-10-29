// ==== 0x411030 FUN_00411030

WPARAM FUN_00411030(void)

{
  int iVar1;
  tagMSG local_1c;
  
  PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  if (local_1c.message == 0x12) {
    DAT_00736124 = 1;
    ShowCursor(1);
    return local_1c.wParam;
  }
  if ((DAT_00735e78 == '\0') && (DAT_00736378 == 0)) {
    iVar1 = GetMessageA(&local_1c,(HWND)0x0,0,0);
  }
  else {
    iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  }
  if (iVar1 != 0) {
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
  }
  return local_1c.wParam;
}


// ==== 0x4110d0 FUN_004110d0

LRESULT FUN_004110d0(HWND param_1,uint param_2,HWND param_3,LPARAM param_4)

{
  LRESULT LVar1;
  HWND extraout_EDX;
  bool bVar2;
  
  if (0x102 < param_2) {
    if (param_2 < 0x20b) {
      if (param_2 == 0x20a) {
        return 0;
      }
      switch(param_2) {
      case 0x200:
        return 0;
      case 0x201:
        SetCapture(param_1);
        return 0;
      case 0x202:
      case 0x205:
        ReleaseCapture();
        return 0;
      case 0x204:
        SetCapture(param_1);
        return 0;
      }
    }
    else {
      if (param_2 == 0x30f) {
        return 0;
      }
      if ((param_2 == 0x311) && (param_1 != param_3)) {
        return 0;
      }
    }
    goto switchD_00411110_caseD_3;
  }
  if (param_2 == 0x102) {
    DAT_007363b1 = param_3._0_1_;
    TextEntry_HandleChar();
    return 0;
  }
  if (param_2 < 0x11) {
    if (param_2 == 0x10) {
switchD_00411110_caseD_2:
      DAT_00736124 = 1;
      PostQuitMessage(0);
      return 0;
    }
    switch(param_2) {
    case 2:
      goto switchD_00411110_caseD_2;
    case 5:
      PostMessageA(param_1,0xf,0,0);
      return 0;
    case 6:
      bVar2 = (short)param_3 == 0;
      if ((DAT_007356a8 != 0) && (bVar2 != (bool)DAT_007363b6)) {
        if (bVar2) {
          EAXSound__EnterPauseMenu();
          DAT_007363b6 = bVar2;
        }
        else {
          FUN_0051eee0(DAT_007356a8);
          DAT_007363b6 = bVar2;
        }
      }
      break;
    case 0xf:
      BeginPaint(param_1,(LPPAINTSTRUCT)&DAT_0078f5e0);
      EndPaint(param_1,(PAINTSTRUCT *)&DAT_0078f5e0);
      return 0;
    }
switchD_00411110_caseD_3:
    LVar1 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
    return LVar1;
  }
  if (param_2 == 0x1c) {
    DAT_00736378 = param_3;
    goto switchD_00411110_caseD_3;
  }
  if (param_2 != 0x100) {
    if (param_2 == 0x101) {
      if (param_3 != (HWND)0x11) {
        return 0;
      }
      DAT_0071b66c = 0;
      return 0;
    }
    goto switchD_00411110_caseD_3;
  }
  switch(param_3) {
  case (HWND)0x23:
    break;
  case (HWND)0x24:
    break;
  case (HWND)0x25:
    break;
  default:
    goto switchD_004111fc_caseD_26;
  case (HWND)0x27:
  }
  Cursor_MoveClamped();
  param_3 = extraout_EDX;
switchD_004111fc_caseD_26:
  if ((DAT_0071b66c == 0) && (param_3 == (HWND)0x11)) {
    DAT_0071b66c = 1;
    return 0;
  }
  return 0;
}


// ==== 0x411340 TextEntry_HandleChar

/* [canon] input med (ghidra-canon) docs/re/runtime.md */

void TextEntry_HandleChar(void)

{
  int iVar1;
  char in_AL;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if ((DAT_007363a8 != 0) && ((DAT_007363b0 == '\0' || (DAT_007363b0 = '\0', in_AL != '\r')))) {
    switch(in_AL) {
    case '\b':
      if (DAT_007363a4 != 0) {
        pcVar3 = _malloc(DAT_007363ac);
        iVar1 = DAT_0073639c;
        pcVar4 = (char *)(DAT_0073639c + DAT_007363a4);
        iVar6 = (int)pcVar3 - (int)pcVar4;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar6] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        DAT_007363a0 = DAT_007363a0 - 1;
        DAT_007363a4 = DAT_007363a4 + -1;
        iVar1 = iVar1 + DAT_007363a4;
        pcVar4 = pcVar3;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar1 - (int)pcVar3] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        _free(pcVar3);
        return;
      }
      break;
    case '\t':
    case '\r':
      DAT_0070108d = '\n';
      if (DAT_007363a0 < DAT_007363ac) {
        pcVar5 = _malloc(DAT_007363ac);
        iVar1 = DAT_0073639c;
        pcVar4 = (char *)(DAT_0073639c + DAT_007363a4);
        pcVar3 = pcVar4;
        do {
          cVar2 = *pcVar3;
          pcVar3[(int)pcVar5 - (int)pcVar4] = cVar2;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        *pcVar4 = '\n';
        DAT_007363a0 = DAT_007363a0 + 1;
        DAT_007363a4 = DAT_007363a4 + 1;
        iVar1 = iVar1 + DAT_007363a4;
        DAT_0070108d = 10;
        pcVar4 = pcVar5;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar1 - (int)pcVar5] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        _free(pcVar5);
        return;
      }
      break;
    case '\n':
      break;
    default:
      DAT_0070108d = in_AL;
      if (((((('`' < in_AL) && (in_AL < '{')) || (('@' < in_AL && (in_AL < '[')))) ||
           ((('/' < in_AL && (in_AL < ':')) ||
            ((DAT_0070108e == '\0' &&
             ((((in_AL == '_' || (in_AL == '@')) || (in_AL == '.')) || (in_AL == '-')))))))) ||
          ((DAT_007363b3 == '\x01' && (cVar2 = Char_IsAllowedSymbol(), cVar2 != '\0')))) &&
         (DAT_007363b1 = 0, DAT_007363a0 < DAT_007363ac)) {
        pcVar3 = _malloc(DAT_007363ac);
        pcVar5 = (char *)(DAT_0073639c + DAT_007363a4);
        pcVar4 = pcVar5;
        do {
          cVar2 = *pcVar4;
          pcVar4[(int)pcVar3 - (int)pcVar5] = cVar2;
          iVar1 = DAT_0073639c;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        *pcVar5 = in_AL;
        DAT_007363a0 = DAT_007363a0 + 1;
        DAT_007363a4 = DAT_007363a4 + 1;
        iVar1 = iVar1 + DAT_007363a4;
        pcVar4 = pcVar3;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar1 - (int)pcVar3] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        _free(pcVar3);
      }
      break;
    case '\x1b':
      DAT_0070108d = '\0';
      if (DAT_007363a0 < DAT_007363ac) {
        pcVar5 = _malloc(DAT_007363ac);
        iVar1 = DAT_0073639c;
        pcVar4 = (char *)(DAT_0073639c + DAT_007363a4);
        pcVar3 = pcVar4;
        do {
          cVar2 = *pcVar3;
          pcVar3[(int)pcVar5 - (int)pcVar4] = cVar2;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        *pcVar4 = '\0';
        DAT_007363a0 = DAT_007363a0 + 1;
        DAT_007363a4 = DAT_007363a4 + 1;
        iVar1 = iVar1 + DAT_007363a4;
        pcVar4 = pcVar5;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar1 - (int)pcVar5] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        _free(pcVar5);
        return;
      }
    }
  }
  return;
}


// ==== 0x4115f0 Char_IsAllowedSymbol

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

uint __fastcall Char_IsAllowedSymbol(char param_1)

{
  uint uVar1;
  char local_38 [56];
  
  local_38[0] = ' ';
  local_38[1] = 0x2e;
  local_38[2] = 0x2c;
  local_38[3] = 0x5f;
  local_38[4] = 0x40;
  local_38[5] = 0x2d;
  local_38[6] = 0x60;
  local_38[7] = 0x3d;
  local_38[8] = 0x5b;
  local_38[9] = 0x5d;
  local_38[10] = 0x5c;
  local_38[0xb] = 0x3b;
  local_38[0xc] = 0x27;
  local_38[0xd] = 0x2f;
  local_38[0xe] = 0x3c;
  local_38[0xf] = 0x3e;
  local_38[0x10] = 0x3f;
  local_38[0x11] = 0x3a;
  local_38[0x12] = 0x22;
  local_38[0x13] = 0x7b;
  local_38[0x14] = 0x7d;
  local_38[0x15] = 0x7c;
  local_38[0x16] = 0x2b;
  local_38[0x17] = 0x28;
  local_38[0x18] = 0x29;
  local_38[0x19] = 0x2a;
  local_38[0x1a] = 0x26;
  local_38[0x1b] = 0x25;
  local_38[0x1c] = 0x23;
  local_38[0x1d] = 0x21;
  local_38[0x1e] = 0x7e;
  local_38[0x1f] = 0xe5;
  local_38[0x20] = 0xe4;
  local_38[0x21] = 0xe0;
  local_38[0x22] = 0xe2;
  local_38[0x23] = 0xeb;
  local_38[0x24] = 0xe8;
  local_38[0x25] = 0xe9;
  local_38[0x26] = 0xea;
  local_38[0x27] = 0xef;
  local_38[0x28] = 0xee;
  local_38[0x29] = 0xf6;
  local_38[0x2a] = 0xf4;
  local_38[0x2b] = 0xfc;
  local_38[0x2c] = 0xf9;
  local_38[0x2d] = 0xfb;
  local_38[0x2e] = 0xe7;
  local_38[0x2f] = 0x9c;
  local_38[0x30] = 0xf2;
  local_38[0x31] = 0xec;
  local_38[0x32] = 0xc5;
  local_38[0x33] = 0xc4;
  local_38[0x34] = 0xd6;
  local_38[0x35] = 0xdc;
  local_38[0x36] = 0xa7;
  uVar1 = 0;
  do {
    if (local_38[uVar1] == param_1) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x37);
  return uVar1 & 0xffffff00;
}


// ==== 0x411720 Cursor_MoveClamped

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void __fastcall Cursor_MoveClamped(int param_1)

{
  uint uVar1;
  
  if (DAT_007363a8 != 0) {
    uVar1 = DAT_007363a4 + param_1;
    if ((int)DAT_007363a0 <= (int)(DAT_007363a4 + param_1)) {
      uVar1 = DAT_007363a0;
    }
    DAT_007363a4 = uVar1 & ((int)uVar1 < 1) - 1;
  }
  return;
}


// ==== 0x411750 FUN_00411750

void __fastcall FUN_00411750(undefined4 param_1,undefined1 param_2,char param_3)

{
  int iVar1;
  char cVar2;
  char *in_EAX;
  
  DAT_007363ac = param_1;
  DAT_007363b0 = param_2;
  DAT_0073639c = in_EAX;
  DAT_007363a8 = 1;
  if (param_3 != '\0') {
    *in_EAX = '\0';
    DAT_007363a0 = 0;
    DAT_007363a4 = 0;
    return;
  }
  DAT_007363a4 = 0;
  if (in_EAX != (char *)0x0) {
    cVar2 = *in_EAX;
    while (cVar2 != '\0') {
      iVar1 = DAT_007363a4 + 1;
      DAT_007363a4 = DAT_007363a4 + 1;
      cVar2 = in_EAX[iVar1];
    }
  }
  DAT_007363a0 = DAT_007363a4;
  return;
}


// ==== 0x4117b0 FUN_004117b0

undefined4 FUN_004117b0(void)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = DAT_0073639c;
  if (DAT_0070108d == '\n') {
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    pcVar1 = DAT_0073639c;
    if (pcVar2[-1] == '\n') {
      do {
        pcVar2 = pcVar1;
        pcVar1 = pcVar2 + 1;
      } while (*pcVar2 != '\0');
      pcVar2[-1] = '\0';
    }
    return 1;
  }
  if (DAT_0070108d != '\0') {
    return 0;
  }
  if (DAT_007363a8 != 0) {
    *DAT_0073639c = '\0';
    DAT_007363a0 = 0;
    DAT_007363a4 = 0;
  }
  return 0xffffffff;
}


// ==== 0x411830 FUN_00411830

void FUN_00411830(void)

{
  int iVar1;
  int iVar2;
  
  FUN_0041c3d0();
  DestroyWindow(DAT_00736380);
  iVar1 = DAT_007356a8;
  iVar2 = *(int *)(DAT_007356a8 + 0x104);
  if (iVar2 != 0) {
    *(undefined4 *)(DAT_007356a8 + 0xac) = *(undefined4 *)(iVar2 + 0x1c4);
    if (DAT_006f1dd8 != 0) {
      *(undefined4 *)(iVar2 + 0x1c4) = 4;
      FUN_00537cc0();
    }
    *(undefined1 *)(iVar1 + 0x9c) = 1;
  }
  FUN_0063f0a0(0);
  FUN_0063e5c0(0);
  FUN_0051d080();
  FUN_0063f0a0(0);
  FUN_0063e5c0(0);
  FUN_00405760();
  RefList_ReleaseAll();
  D3DResourceList_ReleaseAll();
  iVar2 = 0;
  do {
    (**(code **)(**(int **)((int)&DAT_00718738 + iVar2) + 8))(*(int **)((int)&DAT_00718738 + iVar2))
    ;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x78);
  (**(code **)(*DAT_007187b0 + 8))(DAT_007187b0);
  ReleaseSceneRTs();
  BlurReleaseRTs();
  (**(code **)(*DAT_0073636c + 8))(DAT_0073636c);
  (**(code **)(*DAT_00736368 + 8))(DAT_00736368);
  FUN_00594bd0();
  return;
}


// ==== 0x411910 FUN_00411910

undefined4 FUN_00411910(undefined1 param_1)

{
  undefined1 uVar1;
  char *pcVar2;
  undefined1 *_Memory;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  _Memory = _malloc(0x400);
  uVar1 = DAT_0070108f;
  uVar4 = 0;
  if (_Memory == (undefined1 *)0x0) {
    return 0;
  }
  DAT_0070108f = 0;
  *_Memory = param_1;
  _Memory[1] = 0x3a;
  _Memory[2] = 0x5c;
  _Memory[3] = 0;
  pcVar2 = _Memory + -1;
  do {
    pcVar5 = pcVar2;
    pcVar2 = pcVar5 + 1;
  } while (pcVar5[1] != '\0');
  builtin_strncpy(pcVar5 + 1,"tracks\\racer.bin",0x11);
  iVar3 = bOpenFile(_Memory,0,1);
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 4);
    FUN_00594d40();
    if (iVar3 != -1) {
      uVar4 = 1;
    }
  }
  DAT_0070108f = uVar1;
  _free(_Memory);
  return uVar4;
}


// ==== 0x4119d0 FUN_004119d0

undefined4 FUN_004119d0(void)

{
  return 0x2e;
}


// ==== 0x411ab0 FUN_00411ab0

void FUN_00411ab0(void)

{
  char cVar1;
  
  if (DAT_007070bc != 0) {
    FUN_004119d0();
    DAT_007070bc = 1;
    return;
  }
  cVar1 = FUN_00411910(DAT_0070108f);
  if (cVar1 != '\0') {
    DAT_007070bc = 0;
    return;
  }
  DAT_007070bc = 1;
  return;
}


// ==== 0x411b00 FUN_00411b00

undefined4 FUN_00411b00(void)

{
  BOOL BVar1;
  int iVar2;
  _OSVERSIONINFOA *p_Var3;
  _OSVERSIONINFOA local_a8;
  
  p_Var3 = &local_a8;
  for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var3->dwOSVersionInfoSize = 0;
    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;
  }
  local_a8.dwOSVersionInfoSize = 0x9c;
  BVar1 = GetVersionExA(&local_a8);
  if (BVar1 == 0) {
    local_a8.dwOSVersionInfoSize = 0x94;
    BVar1 = GetVersionExA(&local_a8);
    if (BVar1 == 0) {
      return 0;
    }
  }
  if (local_a8.dwPlatformId != 1) {
    return 0;
  }
  return 1;
}


// ==== 0x411b70 FUN_00411b70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411b70(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  CriticalSection__Enter(unaff_ESI + 4);
  iVar1 = *(int *)(unaff_ESI + 100);
  param_1 = iVar1 - param_1;
  *(int *)(unaff_ESI + 100) = param_1;
  CriticalSection__Leave(unaff_ESI + 4);
  if (((*(int *)(unaff_ESI + 0x54) <= iVar1) && (param_1 < *(int *)(unaff_ESI + 0x54))) &&
     (*(undefined4 *)(unaff_ESI + 0x60) = 1, *(int *)(unaff_ESI + 0x48) == 1)) {
    DAT_0071b7c8 = DAT_0071b7c8 + 1;
    _DAT_00736354 = FUN_005648c0();
    FUN_0063a020(*(undefined4 *)(unaff_ESI + 400),*(undefined4 *)(unaff_ESI + 0x50));
  }
  return;
}


// ==== 0x411be0 SNDSTRM_AllocRequest

/* [canon] audio med (hopper+capstone) docs/re/misc.md */

uint * SNDSTRM_AllocRequest(void)

{
  int iVar1;
  uint *puVar2;
  int unaff_EDI;
  
  iVar1 = unaff_EDI + 4;
  CriticalSection__Enter(iVar1);
  puVar2 = *(uint **)(unaff_EDI + 0x80);
  if (puVar2 == (uint *)0x0) {
    CriticalSection__Leave(iVar1);
    return (uint *)0x0;
  }
  *(uint *)(unaff_EDI + 0x80) = puVar2[3];
  DAT_0071b7c4 = DAT_0071b7c4 + 0x100;
  if (DAT_0071b7c4 == 0) {
    DAT_0071b7c4 = 0x100;
  }
  *puVar2 = *puVar2 & 0xff | DAT_0071b7c4;
  CriticalSection__Leave(iVar1);
  return puVar2;
}


// ==== 0x411c50 SNDSTRM_PushRequest

/* [canon] audio med (hopper+capstone) docs/re/misc.md */

void SNDSTRM_PushRequest(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = unaff_EDI + 4;
  *(undefined4 *)(unaff_ESI + 4) = 1;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  CriticalSection__Enter(iVar1);
  if (*(int *)(unaff_EDI + 0x7c) == 0) {
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *(int *)(unaff_EDI + 0x74) = unaff_ESI;
    *(int *)(unaff_EDI + 0x78) = unaff_ESI;
    *(int *)(unaff_EDI + 0x7c) = unaff_ESI;
    CriticalSection__Leave(iVar1);
    return;
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_EDI + 0x7c);
  *(int *)(*(int *)(unaff_EDI + 0x7c) + 0xc) = unaff_ESI;
  *(int *)(unaff_EDI + 0x7c) = unaff_ESI;
  CriticalSection__Leave(iVar1);
  return;
}


// ==== 0x411ca0 FUN_00411ca0

void __fastcall FUN_00411ca0(int param_1)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == *(int *)(param_1 + 0x74)) {
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(in_EAX + 0xc);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 8) + 0xc) = *(undefined4 *)(in_EAX + 0xc);
  }
  if (in_EAX == *(int *)(param_1 + 0x7c)) {
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(in_EAX + 8);
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8) = *(undefined4 *)(in_EAX + 8);
  }
  if (in_EAX == *(int *)(param_1 + 0x78)) {
    iVar1 = *(int *)(in_EAX + 0xc);
    if (iVar1 == 0) {
      iVar1 = *(int *)(in_EAX + 8);
    }
    *(int *)(param_1 + 0x78) = iVar1;
  }
  *(undefined4 *)(in_EAX + 4) = 0;
  *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0x80);
  *(int *)(param_1 + 0x80) = in_EAX;
  return;
}


// ==== 0x411d00 FUN_00411d00

undefined4 FUN_00411d00(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int in_EAX;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  iVar1 = *(int *)(in_EAX + 0x78);
  if (*(int *)(in_EAX + 0x70) - *(int *)(in_EAX + 0x6c) < 8) {
    return 0;
  }
  do {
    puVar2 = *(uint **)(in_EAX + 0x6c);
    uVar8 = puVar2[1];
    if ((uVar8 & 0xff000000) != 0) {
      uVar8 = 8;
      *puVar2 = *(uint *)(iVar1 + 0x120);
      puVar2[1] = 8;
    }
    if (*(uint *)(in_EAX + 0x70) < *(uint *)(in_EAX + 0x6c) + uVar8) {
      return 0;
    }
    if (*puVar2 == *(uint *)(iVar1 + 0x120)) {
      uVar4 = *(uint *)(in_EAX + 0x6c) & 0x3f;
      uVar8 = (uVar4 + 0x3f + uVar8 & 0xffffffc0) - uVar4;
    }
    iVar6 = 0;
    if (0 < *(int *)(in_EAX + 0x2c)) {
      puVar5 = *(uint **)(in_EAX + 0x28);
      do {
        if ((*puVar5 & *puVar2) == puVar5[1]) {
          uVar4 = puVar5[2];
          if ((int)uVar4 < 0) goto LAB_00411da3;
          puVar2[1] = uVar4 << 0x18 | uVar8;
          CriticalSection__Enter(in_EAX + 4);
          bVar9 = *(int *)(iVar1 + 4) == 4;
          if (!bVar9) {
            iVar6 = uVar4 * 0x10 + -0x10 + *(int *)(in_EAX + 0x30);
            uVar7 = *(int *)(iVar6 + 8) + uVar8;
            *(uint *)(iVar6 + 8) = uVar7;
            if (uVar7 == uVar8) {
              *(uint **)(iVar6 + 0xc) = puVar2;
            }
            *(uint *)(in_EAX + 0x6c) = *(int *)(in_EAX + 0x6c) + uVar8;
            iVar3 = *(int *)(in_EAX + 100);
            iVar6 = iVar3 + uVar8;
            *(int *)(in_EAX + 100) = iVar6;
            if ((iVar3 < *(int *)(in_EAX + 0x54)) && (*(int *)(in_EAX + 0x54) <= iVar6)) {
              *(undefined4 *)(in_EAX + 0x60) = 0;
            }
          }
          goto LAB_00411e3e;
        }
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 3;
      } while (iVar6 < *(int *)(in_EAX + 0x2c));
    }
    uVar4 = 0xfffffffe;
LAB_00411da3:
    CriticalSection__Enter(in_EAX + 4);
    bVar9 = *(int *)(iVar1 + 4) == 4;
    if (!bVar9) {
      *puVar2 = 0xfffffffe;
      *(int *)(in_EAX + 0x6c) = *(int *)(in_EAX + 0x6c) + uVar8;
    }
LAB_00411e3e:
    CriticalSection__Leave(in_EAX + 4);
    if (bVar9) {
      if (*puVar2 == *(uint *)(iVar1 + 0x120)) {
        return 0;
      }
      uVar7 = *(uint *)(in_EAX + 0x6c) & 0x3f;
      puVar2[1] = (uVar7 + 0x3f + uVar8 & 0xffffffc0) - uVar7 | uVar4 << 0x18;
      return 0;
    }
    if (*puVar2 == *(uint *)(iVar1 + 0x120)) {
      return 1;
    }
    if (*(int *)(in_EAX + 0x70) - *(int *)(in_EAX + 0x6c) < 8) {
      return 0;
    }
  } while( true );
}


// ==== 0x411ec0 FUN_00411ec0

void FUN_00411ec0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00639c00(*(undefined4 *)(param_3 + 400));
  *(int *)(param_3 + 0x188) = iVar1;
  if (iVar1 != 0) {
    FUN_00412160(param_3,*(undefined4 *)(param_3 + 0x50));
  }
  return;
}


// ==== 0x411ef0 FUN_00411ef0

void FUN_00411ef0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  FUN_00639c00(*(undefined4 *)(param_3 + 400));
  iVar1 = FUN_0063a5d0(param_3 + 0x84,1,*(undefined4 *)(param_3 + 0x50),param_3);
  *(int *)(param_3 + 400) = iVar1;
  if (iVar1 != 0) {
    FUN_00639f20(iVar1,FUN_00411ec0);
  }
  return;
}


// ==== 0x411f40 FUN_00411f40

void FUN_00411f40(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_3 + 0x78);
  DAT_00736360 = 0;
  DAT_00736361 = 0;
  if (*(int *)(iVar1 + 0x10) == 1) {
    iVar3 = *(int *)(param_3 + 0x194);
    bVar2 = *(int *)(iVar1 + 0x11c) <= *(int *)(param_3 + 0x18c) + iVar3;
  }
  else {
    iVar3 = FUN_00639c00(*(undefined4 *)(param_3 + 400));
    bVar2 = iVar3 < *(int *)(param_3 + 0x194);
  }
  *(int *)(param_3 + 0x18c) = *(int *)(param_3 + 0x18c) + iVar3;
  *(int *)(param_3 + 0x70) = *(int *)(param_3 + 0x70) + iVar3;
  iVar3 = FUN_00411d00();
  if (*(int *)(iVar1 + 4) == 4) {
    FUN_00412020(*(undefined4 *)(param_3 + 0x50));
    return;
  }
  if ((!bVar2) && (iVar3 == 0)) {
    FUN_00412160(param_3,*(int *)(param_3 + 0x50) + -1);
    return;
  }
  CriticalSection__Enter(param_3 + 4);
  if (*(int *)(iVar1 + 4) != 4) {
    *(undefined4 *)(iVar1 + 4) = 3;
  }
  CriticalSection__Leave(param_3 + 4);
  FUN_00412020(*(undefined4 *)(param_3 + 0x50));
  return;
}


// ==== 0x412020 FUN_00412020

void FUN_00412020(undefined4 param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  
  iVar6 = 0;
  CriticalSection__Enter(unaff_ESI + 4);
  iVar5 = *(int *)(unaff_ESI + 0x78);
  bVar8 = true;
  if (iVar5 == 0) {
LAB_00412092:
    *(undefined4 *)(unaff_ESI + 0x48) = 0;
  }
  else {
    if (*(int *)(iVar5 + 4) != 1) {
      if (*(int *)(iVar5 + 0xc) == 0) goto LAB_00412092;
      *(int *)(unaff_ESI + 0x78) = *(int *)(iVar5 + 0xc);
    }
    iVar6 = *(int *)(unaff_ESI + 0x78);
    bVar8 = false;
    *(undefined4 *)(iVar6 + 0x124) = *(undefined4 *)(unaff_ESI + 0x6c);
    *(undefined4 *)(iVar6 + 4) = 2;
  }
  CriticalSection__Leave(unaff_ESI + 4);
  if (!bVar8) {
    *(undefined4 *)(unaff_ESI + 0x70) = *(undefined4 *)(unaff_ESI + 0x6c);
    if (*(int *)(iVar6 + 0x10) == 1) {
      *(undefined4 *)(unaff_ESI + 0x18c) = 0;
    }
    else {
      pbVar3 = (byte *)(iVar6 + 0x14);
      pbVar1 = (byte *)(unaff_ESI + 0x84);
      *(undefined4 *)(unaff_ESI + 0x18c) = *(undefined4 *)(iVar6 + 0x11c);
      pbVar4 = pbVar3;
      pbVar7 = pbVar1;
      do {
        bVar2 = *pbVar4;
        bVar8 = bVar2 < *pbVar7;
        if (bVar2 != *pbVar7) {
LAB_004120d8:
          iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_004120dd;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar8 = bVar2 < pbVar7[1];
        if (bVar2 != pbVar7[1]) goto LAB_004120d8;
        pbVar4 = pbVar4 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_004120dd:
      if (iVar5 != 0) {
        iVar5 = (int)pbVar1 - (int)pbVar3;
        do {
          bVar2 = *pbVar3;
          pbVar3[iVar5] = bVar2;
          pbVar3 = pbVar3 + 1;
        } while (bVar2 != 0);
        if (*(int *)(unaff_ESI + 0x188) == 0) {
          iVar5 = FUN_0063a5d0(pbVar1,1,param_1);
          *(int *)(unaff_ESI + 400) = iVar5;
          if (iVar5 == 0) {
            return;
          }
          FUN_00639f20(iVar5,FUN_00411ec0);
          return;
        }
        iVar5 = FUN_0063a690(*(int *)(unaff_ESI + 0x188),param_1);
        *(int *)(unaff_ESI + 400) = iVar5;
        if (iVar5 == 0) {
          return;
        }
        FUN_00639f20(iVar5,FUN_00411ef0);
        return;
      }
    }
    FUN_00412160();
  }
  return;
}


// ==== 0x412160 FUN_00412160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00412160(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x68) != *(int *)(param_1 + 0x6c)) {
    do {
      piVar1 = *(int **)(param_1 + 0x68);
      if (*piVar1 == -1) {
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x3c);
      }
      else {
        if (*piVar1 != -2) break;
        *(int *)(param_1 + 0x68) = piVar1[1] + (int)piVar1;
      }
    } while (*(int *)(param_1 + 0x68) != *(int *)(param_1 + 0x6c));
  }
  CriticalSection__Enter(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x74);
  iVar8 = *(int *)(iVar3 + 0xc);
  while ((iVar8 != 0 && (iVar8 = *(int *)(iVar3 + 0xc), *(int *)(iVar8 + 4) != 1))) {
    uVar4 = *(uint *)(param_1 + 0x68);
    uVar7 = *(int *)(iVar8 + 0x124) - 1;
    if (*(uint *)(param_1 + 0x70) < uVar4) {
      if (uVar4 <= uVar7) break;
LAB_004121d5:
      if (uVar7 < *(uint *)(param_1 + 0x70)) break;
    }
    else if (uVar4 <= uVar7) goto LAB_004121d5;
    if (iVar3 == *(int *)(param_1 + 0x74)) {
      *(int *)(param_1 + 0x74) = iVar8;
    }
    else {
      *(int *)(*(int *)(iVar3 + 8) + 0xc) = iVar8;
    }
    if (iVar3 == *(int *)(param_1 + 0x7c)) {
      *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar3 + 8);
    }
    else {
      *(undefined4 *)(*(int *)(iVar3 + 0xc) + 8) = *(undefined4 *)(iVar3 + 8);
    }
    if (iVar3 == *(int *)(param_1 + 0x78)) {
      iVar8 = *(int *)(iVar3 + 0xc);
      if (iVar8 == 0) {
        iVar8 = *(int *)(iVar3 + 8);
      }
      *(int *)(param_1 + 0x78) = iVar8;
    }
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0x80);
    *(int *)(param_1 + 0x80) = iVar3;
    iVar3 = *(int *)(param_1 + 0x74);
    iVar8 = *(int *)(iVar3 + 0xc);
  }
  CriticalSection__Leave(param_1 + 4);
  uVar4 = *(uint *)(param_1 + 0x68);
  uVar7 = *(uint *)(param_1 + 0x70);
  if (uVar7 < uVar4) {
    iVar3 = (uVar4 - uVar7) + -0x41;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0x40) - uVar7) + -0x40;
    if (iVar3 < *(int *)(param_1 + 0x198)) {
      uVar7 = uVar7 - *(int *)(param_1 + 0x6c);
      iVar3 = *(int *)(*(int *)(param_1 + 0x78) + 0x10);
      if (iVar3 == 1) {
        if ((int)(uVar4 - *(int *)(param_1 + 0x3c)) < (int)(uVar7 + 1)) {
          *(undefined4 *)(param_1 + 0x48) = 2;
          return;
        }
      }
      else if ((int)((uVar4 - *(int *)(param_1 + 0x3c)) + -0x40) < (int)(uVar7 + 1))
      goto LAB_0041232a;
      uVar4 = uVar7 & 0x8000003f;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xffffffc0) + 1;
      }
      if ((uVar4 == 0) || (iVar3 == 1)) {
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
      }
      else {
        *(uint *)(param_1 + 0x3c) = (*(int *)(param_1 + 0x38) - uVar4) + 0x40;
      }
      FUN_0063f1b0(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x6c),uVar7);
      puVar2 = *(undefined4 **)(param_1 + 0x6c);
      *puVar2 = 0xffffffff;
      puVar2[1] = 8;
      iVar8 = *(int *)(param_1 + 0x3c);
      iVar3 = iVar8 + uVar7;
      *(int *)(param_1 + 0x6c) = iVar8;
      *(int *)(param_1 + 0x70) = iVar3;
      if (**(int **)(param_1 + 0x68) == -1) {
        *(int *)(param_1 + 0x68) = iVar8;
        iVar3 = (*(int *)(param_1 + 0x40) - iVar3) + -0x40;
      }
      else {
        iVar3 = (int)*(int **)(param_1 + 0x68) + (-1 - iVar3);
      }
    }
  }
  if (((*(int *)(param_1 + 0x60) == 0) && (param_2 != *(int *)(param_1 + 0x50))) &&
     (DAT_0077aadc != '\0')) {
    DAT_00736362 = 1;
  }
  else {
    DAT_00736362 = 0;
    if ((*(int *)(param_1 + 0x60) == 0) || (DAT_0077aadc == '\0')) {
      DAT_00736361 = 0;
    }
    else {
      if (iVar3 < *(int *)(param_1 + 0x58)) goto LAB_0041232a;
      FUN_005648c0();
      FUN_005648c0();
      _DAT_0073635c = FUN_005648c0();
      DAT_00736361 = 1;
    }
    if (*(int *)(param_1 + 0x58) <= iVar3) {
      iVar8 = *(int *)(param_1 + 0x78);
      if (*(int *)(iVar8 + 0x10) == 1) {
        if (*(int *)(iVar8 + 0x11c) < *(int *)(param_1 + 0x18c) + iVar3) {
          *(int *)(param_1 + 0x194) = *(int *)(iVar8 + 0x11c) - *(int *)(param_1 + 0x18c);
        }
        else {
          *(int *)(param_1 + 0x194) = iVar3;
        }
        FUN_0063f1b0(*(undefined4 *)(param_1 + 0x70),*(undefined4 *)(iVar8 + 0x118),
                     *(undefined4 *)(param_1 + 0x194));
        *(int *)(iVar8 + 0x118) = *(int *)(iVar8 + 0x118) + *(int *)(param_1 + 0x194);
        FUN_00411f40(0,0,param_1);
        return;
      }
      if (iVar3 < 0x20001) {
        iVar8 = *(int *)(param_1 + 0x5c);
        *(int *)(param_1 + 0x194) = iVar3;
        if (iVar3 == *(int *)(param_1 + 0x1a4)) {
          *(int *)(param_1 + 0x194) = iVar3;
        }
        else {
          iVar9 = *(int *)(param_1 + 0x198) * (iVar3 / *(int *)(param_1 + 0x198));
          if ((iVar9 < iVar3) &&
             (iVar5 = iVar8 * (iVar3 / iVar8), iVar9 - iVar5 != 0 && iVar5 <= iVar9)) {
            *(int *)(param_1 + 0x194) = iVar9;
          }
          else {
            *(int *)(param_1 + 0x194) = iVar8 * (iVar3 / iVar8);
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x194) = 0x20000;
      }
      iVar3 = FUN_0063a700(*(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x18c),
                           *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x194),param_2,
                           param_1);
      *(int *)(param_1 + 400) = iVar3;
      if (iVar3 != 0) {
        if (DAT_0071b7c8 < 1) {
          DAT_0071b7c8 = 0;
        }
        else {
          FUN_005648c0();
          DAT_0071b7c8 = DAT_0071b7c8 + -1;
        }
        FUN_005648c0();
        _DAT_00736358 = FUN_005648c0();
        uVar6 = FUN_005648c0();
        *(undefined4 *)(param_1 + 0x1a8) = uVar6;
        DAT_00736360 = 1;
        FUN_00639f20(*(undefined4 *)(param_1 + 400),FUN_00411f40);
      }
      return;
    }
  }
LAB_0041232a:
  *(undefined4 *)(param_1 + 0x48) = 2;
  return;
}


// ==== 0x4124d0 SNDSTRM_OverheadBytes

/* [canon] audio high (hopper+capstone) docs/re/misc.md */

int SNDSTRM_OverheadBytes(int param_1,int param_2,int param_3)

{
  return param_1 * 0x128 + (param_2 * 3 + 0x7b) * 4 + param_3 * 0x10;
}


// ==== 0x4124f0 FUN_004124f0

undefined4 FUN_004124f0(int param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = param_5 - (param_3 * 0x10 + (param_2 * 3 + 0x7b) * 4 + param_1 * 0x128);
  if ((((iVar7 < 0x1800) || (param_1 < 2)) || (0x100 < param_1)) ||
     (((param_2 < 1 || (0x10 < param_2)) || ((param_3 < 1 || (param_2 < param_3)))))) {
    return 0;
  }
  *param_4 = 0x4d525453;
  CriticalSection__Init(param_4 + 1);
  puVar5 = param_4 + 0x6b;
  puVar1 = puVar5 + param_1 * 0x4a;
  param_4[9] = param_1;
  param_4[10] = puVar1;
  param_4[0xc] = puVar1 + param_2 * 3;
  uVar2 = (uint)(puVar1 + param_2 * 3 + param_3 * 4) & 0xffffffc0;
  param_4[0xd] = param_3;
  iVar3 = uVar2 + 0x40;
  uVar6 = 0x8000;
  param_4[8] = puVar5;
  param_4[0xb] = param_2;
  param_4[0xe] = iVar3;
  param_4[0xf] = iVar3;
  if (iVar7 < 0x8000) {
    param_4[0x10] = uVar2 + 0x4080;
    param_4[0x11] = uVar2 + 0x4080;
    uVar6 = 0x1000;
    param_4[0x66] = 0x2000;
    param_4[0x16] = 0x1000;
    param_4[0x69] = 0x4000;
  }
  else {
    if (iVar7 < 0x10000) {
      param_4[0x10] = uVar2 + 0x8080;
      param_4[0x11] = uVar2 + 0x8080;
      param_4[0x66] = 0x4000;
      param_4[0x16] = 0x2000;
      param_4[0x17] = 0x2000;
      param_4[0x69] = 0x8000;
      goto LAB_004126b7;
    }
    if (iVar7 < 0x18000) {
      param_4[0x66] = 0x8000;
      uVar6 = 0x4000;
      param_5 = uVar2 + 0x10080;
      param_4[0x16] = 0x4000;
      param_4[0x69] = 0x10000;
    }
    else {
      if (iVar7 < 0x20000) {
        param_4[0x10] = uVar2 + 0x18080;
        param_4[0x11] = uVar2 + 0x18080;
        param_4[0x66] = 0x8000;
        param_4[0x16] = 0x8000;
        param_4[0x69] = 0x18000;
        goto LAB_004126b4;
      }
      if (iVar7 < 0x21000) {
        param_5 = uVar2 + 0x20080;
        param_4[0x66] = 0x10000;
        param_4[0x16] = 0x8000;
        param_4[0x69] = 0x20000;
      }
      else {
        param_5 = param_5 + (int)param_4;
        param_4[0x66] = 0x20000;
        param_4[0x16] = 0x10000;
        param_4[0x69] = 0xffffffff;
      }
    }
    param_4[0x10] = param_5;
    param_4[0x11] = param_5;
  }
LAB_004126b4:
  param_4[0x17] = uVar6;
LAB_004126b7:
  param_4[0x1a] = iVar3;
  param_4[0x1b] = iVar3;
  param_4[0x1c] = iVar3;
  param_4[0x12] = 0;
  param_4[0x13] = 0x96;
  param_4[0x14] = 0x32;
  param_4[0x15] = 0;
  param_4[0x18] = 0;
  param_4[0x19] = 0;
  param_4[0x1d] = 0;
  param_4[0x1e] = 0;
  param_4[0x1f] = 0;
  param_4[0x20] = puVar5;
  FUN_0063f210(param_4 + 0x21,0x104);
  iVar7 = 0;
  param_4[0x62] = 0;
  param_4[0x67] = 0;
  if (0 < param_1) {
    iVar3 = 0;
    do {
      piVar4 = (int *)(param_4[8] + iVar3);
      *piVar4 = iVar7;
      piVar4[1] = 0;
      piVar4[3] = iVar3 + 0x128 + param_4[8];
      iVar7 = iVar7 + 1;
      iVar3 = iVar3 + 0x128;
    } while (iVar7 < param_1);
  }
  *(undefined4 *)(param_1 * 0x128 + -0x11c + param_4[8]) = 0;
  if (0 < param_2) {
    iVar7 = 0;
    do {
      puVar5 = (undefined4 *)(param_4[10] + iVar7);
      iVar7 = iVar7 + 0xc;
      param_2 = param_2 + -1;
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 1;
    } while (param_2 != 0);
  }
  iVar7 = 0;
  if (0 < param_3) {
    iVar3 = 0;
    do {
      puVar5 = (undefined4 *)(param_4[0xc] + iVar3);
      iVar7 = iVar7 + 1;
      iVar3 = iVar3 + 0x10;
      *puVar5 = param_4;
      puVar5[1] = iVar7;
      puVar5[2] = 0;
    } while (iVar7 < param_3);
  }
  return param_4[0xc];
}


// ==== 0x4127a0 StrmDef_SetEntry

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void StrmDef_SetEntry(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  
  if ((((((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) &&
        (0 < param_2)) && (param_2 <= param_1[0xb])) &&
      ((((param_2 != param_1[0xb] || (param_3 == 0 && param_4 == 0)) &&
        ((0 < param_5 || ((param_5 == -1 || (param_5 == -2)))))) && (param_5 <= param_1[0xd])))) &&
     (param_1[0x12] == 0)) {
    piVar1 = (int *)(param_1[10] + -0xc + param_2 * 0xc);
    *piVar1 = param_3;
    piVar1[1] = param_4;
    piVar1[2] = param_5;
  }
  return;
}


// ==== 0x412810 FUN_00412810

void FUN_00412810(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  if ((param_1 != (undefined4 *)0x0) && (piVar1 = (int *)*param_1, *piVar1 == 0x4d525453)) {
    FUN_00412cd0(param_1);
    iVar2 = piVar1[0x12];
    while (iVar2 == 1) {
      cVar3 = FUN_0063e600(0);
      if (cVar3 != '\0') {
        FUN_0063f0a0(0);
      }
      FUN_0063e5c0(0);
      iVar2 = piVar1[0x12];
    }
    *piVar1 = 0;
    FUN_0063f170(piVar1 + 1);
    if (piVar1[0x62] != 0) {
      FUN_0063c2c0(piVar1[0x62],100);
    }
  }
  return;
}


// ==== 0x412890 FUN_00412890

void FUN_00412890(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iStack00000008;
  
  if ((param_1 != (int *)0x0) && (piVar1 = (int *)*param_1, *piVar1 == 0x4d525453)) {
    iVar2 = piVar1[0x15];
    piVar1[0x15] = piVar1[0x16];
    uVar3 = (uint)(piVar1[0x19] < 0x6000);
    if ((piVar1[0x19] < iVar2 != uVar3) &&
       (((param_1 = (int *)*param_1, *param_1 == 0x4d525453 && (param_1[0x18] = uVar3, uVar3 != 0))
        && (param_1[0x12] == 1)))) {
      iStack00000008 = param_1[0x14];
      FUN_0063a020();
      return;
    }
  }
  return;
}


// ==== 0x412900 SNDSTRM_GetEntry

/* [canon] audio med (hopper+capstone) docs/re/misc.md */

int SNDSTRM_GetEntry(int *param_1,int param_2)

{
  if ((((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) &&
      (0 < param_2)) && (param_2 <= param_1[0xd])) {
    return param_1[0xc] + -0x10 + param_2 * 0x10;
  }
  return 0;
}


// ==== 0x412930 FUN_00412930

undefined4 FUN_00412930(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) {
    puVar2 = (undefined4 *)SNDSTRM_AllocRequest();
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    param_1[0x6a] = 0;
    puVar2[4] = 0;
    _strncpy((char *)(puVar2 + 5),param_2,0x103);
    puVar2[0x47] = param_3;
    puVar2[0x48] = param_4;
    param_1[0x67] = 0;
    SNDSTRM_PushRequest();
    CriticalSection__Enter(param_1 + 1);
    iVar1 = param_1[0x12];
    if (iVar1 == 0) {
      param_1[0x12] = 1;
    }
    CriticalSection__Leave(param_1 + 1);
    if (iVar1 == 0) {
      if (param_1[0x18] != 0) {
        FUN_00412020(param_1[0x14]);
        return *puVar2;
      }
      FUN_00412020(param_1[0x13]);
    }
    return *puVar2;
  }
  return 0;
}


// ==== 0x4129f0 FUN_004129f0

undefined4 FUN_004129f0(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if ((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) {
    puVar3 = (undefined4 *)SNDSTRM_AllocRequest();
    if (puVar3 != (undefined4 *)0x0) {
      if (param_3 == 0) {
        param_3 = 0;
        iVar2 = *param_2;
        piVar4 = param_2;
        while (iVar2 != param_4) {
          piVar1 = piVar4 + 1;
          piVar4 = (int *)((int)piVar4 + *piVar1);
          param_3 = param_3 + *piVar1;
          iVar2 = *piVar4;
        }
        param_3 = param_3 + piVar4[1];
      }
      puVar3[0x48] = param_4;
      puVar3[4] = 1;
      puVar3[0x46] = param_2;
      puVar3[0x47] = param_3;
      SNDSTRM_PushRequest();
      CriticalSection__Enter(param_1 + 1);
      iVar2 = param_1[0x12];
      if (iVar2 == 0) {
        param_1[0x12] = 1;
      }
      CriticalSection__Leave(param_1 + 1);
      if (iVar2 == 0) {
        FUN_00412020(0);
      }
      return *puVar3;
    }
    return 0;
  }
  return 0;
}


// ==== 0x412aa0 FUN_00412aa0

void __fastcall FUN_00412aa0(uint param_1)

{
  int *piVar1;
  bool bVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int *local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  local_18 = (int *)0x0;
  local_14 = (int *)0x0;
  if ((in_EAX != (int *)0x0) && (piVar1 = (int *)*in_EAX, *piVar1 == 0x4d525453)) {
    CriticalSection__Enter(piVar1 + 1);
    if (((int)(param_1 & 0xff) < piVar1[9]) &&
       (((iVar3 = (param_1 & 0xff) * 0x128, iVar4 = iVar3 + piVar1[8],
         param_1 == *(uint *)(iVar3 + piVar1[8]) && (iVar3 = *(int *)(iVar4 + 4), iVar3 != 0)) &&
        (iVar3 != 4)))) {
      bVar2 = true;
      if (iVar3 == 1) {
        FUN_00411ca0();
      }
      else {
        *(undefined4 *)(iVar4 + 4) = 4;
        local_c = (int *)piVar1[0x1a];
        local_18 = local_c;
        if (iVar4 != piVar1[0x1d]) {
          local_18 = *(int **)(iVar4 + 0x124);
        }
        iVar3 = *(int *)(iVar4 + 0xc);
        if ((iVar3 == 0) || (*(int *)(iVar3 + 4) == 1)) {
          local_14 = (int *)piVar1[0x1b];
          bVar2 = false;
        }
        else {
          local_14 = *(int **)(iVar3 + 0x124);
          bVar2 = false;
        }
      }
    }
    else {
      bVar2 = true;
    }
    CriticalSection__Leave(piVar1 + 1);
    if ((!bVar2) && (local_8 = 0, 0 < piVar1[0xd])) {
      local_10 = 0;
      do {
        iVar3 = piVar1[0xc] + local_10;
        if (0 < *(int *)(piVar1[0xc] + 8 + local_10)) {
          piVar6 = *(int **)(iVar3 + 0xc);
          if (local_18 < local_c) {
            if (piVar6 < local_c) goto joined_r0x00412be3;
LAB_00412be5:
            iVar4 = *(int *)(iVar3 + 4);
            piVar6 = local_18;
            while (piVar6 != local_14) {
              if (*piVar6 == -1) {
                piVar6 = (int *)piVar1[0xf];
              }
              else {
                uVar7 = piVar6[1] & 0xffffff;
                if ((piVar6[1] & 0xff000000U) == iVar4 << 0x18) {
                  CriticalSection__Enter(piVar1 + 1);
                  *(uint *)(iVar3 + 8) = *(int *)(iVar3 + 8) - uVar7;
                  CriticalSection__Leave(piVar1 + 1);
                  FUN_00411b70(uVar7);
                  *piVar6 = -2;
                  piVar6[1] = uVar7;
                }
                piVar6 = (int *)((int)piVar6 + uVar7);
              }
            }
          }
          else {
            if (local_c <= piVar6) {
joined_r0x00412be3:
              if (piVar6 < local_18) goto LAB_00412be5;
            }
            if (local_14 < local_18) goto joined_r0x00412c69;
            if (local_18 <= piVar6) {
              do {
                if (local_14 <= piVar6) break;
                do {
                  uVar5 = FUN_00412e30(iVar3);
                  FUN_00412ee0(iVar3,uVar5);
                  if (*(int *)(iVar3 + 8) < 1) goto LAB_00412c9c;
                  piVar6 = *(int **)(iVar3 + 0xc);
                  if (local_18 <= local_14) {
                    if (piVar6 < local_18) goto LAB_00412c9c;
                    break;
                  }
joined_r0x00412c69:
                } while (local_18 <= piVar6);
              } while( true );
            }
          }
        }
LAB_00412c9c:
        local_8 = local_8 + 1;
        local_10 = local_10 + 0x10;
      } while (local_8 < piVar1[0xd]);
    }
  }
  return;
}


// ==== 0x412cd0 FUN_00412cd0

void FUN_00412cd0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) &&
     (iVar1 = param_1[0x1f], iVar1 != 0)) {
    while ((*(int *)(iVar1 + 4) == 1 || (*(int *)(iVar1 + 4) == 2))) {
      FUN_00412aa0();
      iVar1 = param_1[0x1f];
    }
    if (param_1[0x1d] != param_1[0x1e]) {
      do {
        iVar1 = param_1[0x1d];
        if (iVar1 == param_1[0x1d]) {
          param_1[0x1d] = *(int *)(iVar1 + 0xc);
        }
        else {
          *(int *)(*(int *)(iVar1 + 8) + 0xc) = *(int *)(iVar1 + 0xc);
        }
        if (iVar1 == param_1[0x1f]) {
          param_1[0x1f] = *(int *)(iVar1 + 8);
        }
        else {
          *(int *)(*(int *)(iVar1 + 0xc) + 8) = *(int *)(iVar1 + 8);
        }
        if (iVar1 == param_1[0x1e]) {
          iVar3 = *(int *)(iVar1 + 0xc);
          if (iVar3 == 0) {
            iVar3 = *(int *)(iVar1 + 8);
          }
          param_1[0x1e] = iVar3;
        }
        *(undefined4 *)(iVar1 + 4) = 0;
        *(int *)(iVar1 + 0xc) = param_1[0x20];
        param_1[0x20] = iVar1;
      } while (param_1[0x1d] != param_1[0x1e]);
    }
    *(undefined4 *)(param_1[0x1e] + 4) = 4;
    iVar1 = 0;
    if (0 < param_1[0xd]) {
      iVar3 = 0;
      do {
        *(undefined4 *)(param_1[0xc] + 8 + iVar3) = 0;
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x10;
      } while (iVar1 < param_1[0xd]);
    }
    FUN_00411b70(param_1[0x19]);
    piVar2 = (int *)param_1[0x1a];
    if (piVar2 != (int *)param_1[0x1b]) {
      do {
        if (*piVar2 == -1) {
          piVar2 = (int *)param_1[0xf];
        }
        else {
          uVar4 = piVar2[1] & 0xffffff;
          *piVar2 = -2;
          piVar2[1] = uVar4;
          piVar2 = (int *)((int)piVar2 + uVar4);
        }
      } while (piVar2 != (int *)param_1[0x1b]);
    }
    if (param_1[0x12] == 2) {
      if (piVar2 == (int *)param_1[0xf]) {
        param_1[0x1b] = param_1[0xe];
        param_1[0xf] = param_1[0xe];
        param_1[0x12] = 0;
        return;
      }
      iVar1 = 0x40 - (param_1[0x1b] & 0x3fU);
      if (iVar1 == 0x40) {
        iVar1 = 0;
      }
      *(uint *)((param_1[0x1b] - uVar4) + 4) = iVar1 + uVar4;
      param_1[0x1b] = param_1[0x1b] + iVar1;
      param_1[0x12] = 0;
    }
  }
  return;
}


// ==== 0x412e30 FUN_00412e30

int FUN_00412e30(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (((param_1 != (int *)0x0) && (piVar1 = (int *)*param_1, *piVar1 == 0x4d525453)) &&
     (param_1[2] != 0)) {
    iVar2 = param_1[3];
    uVar5 = *(uint *)(iVar2 + 4) & 0xffffff;
    *(uint *)(iVar2 + 4) = uVar5;
    CriticalSection__Enter(piVar1 + 1);
    iVar3 = param_1[2];
    param_1[2] = iVar3 - uVar5;
    CriticalSection__Leave(piVar1 + 1);
    if (0 < (int)(iVar3 - uVar5)) {
      piVar4 = (int *)(uVar5 + iVar2);
      uVar5 = piVar4[1];
      while ((uVar5 & 0xff000000) != param_1[1] << 0x18) {
        if (*piVar4 == -1) {
          piVar4 = (int *)piVar1[0xf];
        }
        else {
          piVar4 = (int *)((int)piVar4 + (uVar5 & 0xffffff));
        }
        uVar5 = piVar4[1];
      }
      param_1[3] = (int)piVar4;
    }
    return iVar2;
  }
  return 0;
}


// ==== 0x412ee0 FUN_00412ee0

void FUN_00412ee0(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) &&
      ((int *)param_1[0xf] <= param_2)) &&
     ((param_2 <= (int *)(param_1[0x10] + -8) && (*param_2 != -2)))) {
    *param_2 = -2;
    FUN_00411b70(param_2[1]);
    CriticalSection__Enter(param_1 + 1);
    iVar1 = param_1[0x12];
    if (iVar1 == 2) {
      param_1[0x12] = 1;
    }
    CriticalSection__Leave(param_1 + 1);
    if (iVar1 == 2) {
      if (param_1[0x18] != 0) {
        FUN_00412160(param_1,param_1[0x14]);
        return;
      }
      FUN_00412160(param_1,param_1[0x13]);
    }
  }
  return;
}


// ==== 0x412f70 FUN_00412f70

undefined4 FUN_00412f70(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (*(int *)*param_1 == 0x4d525453)) {
    return param_1[2];
  }
  return 0;
}


// ==== 0x412f90 FUN_00412f90

int FUN_00412f90(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*(int *)*param_1 == 0x4d525453)) {
    return ((int *)*param_1)[0x12];
  }
  return 0;
}


// ==== 0x412fb0 FUN_00412fb0

uint FUN_00412fb0(int *param_1)

{
  int *in_EAX;
  
  if ((param_1 == (int *)0x0) || (in_EAX = (int *)*param_1, *in_EAX != 0x4d525453)) {
    return (uint)in_EAX & 0xffffff00;
  }
  if ((in_EAX[0x12] == 0) && (param_1[2] == 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x412fe0 FUN_00412fe0

int FUN_00412fe0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, *param_1 == 0x4d525453)) {
    return param_1[0x10] - param_1[0xe];
  }
  return 0;
}


// ==== 0x413000 Input::CreateDirectInput8

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void Input__CreateDirectInput8(void)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  if (DAT_00736350 != (int *)0x0) {
    (**(code **)(*DAT_00736350 + 8))(DAT_00736350);
    DAT_00736350 = (int *)0x0;
  }
  uVar6 = 0;
  puVar5 = &DAT_00736350;
  puVar4 = &DAT_006a6f90;
  uVar3 = 0x800;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  iVar2 = DirectInput8Create(pHVar1,uVar3,puVar4,puVar5,uVar6);
  if (iVar2 < 0) {
    DAT_00736350 = (int *)0x0;
  }
  return;
}


// ==== 0x413050 FUN_00413050

void FUN_00413050(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  
  if (DAT_00736350 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00736350 + 0xc))(DAT_00736350,&DAT_006a6ee0);
    if (iVar2 < 0) {
      *in_EAX = 0;
    }
    iVar2 = (**(code **)(*(int *)*in_EAX + 0x2c))((int *)*in_EAX,&DAT_006a6fb8);
    piVar1 = (int *)*in_EAX;
    if (iVar2 < 0) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x20))(piVar1);
      }
      piVar1 = (int *)*in_EAX;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *in_EAX = 0;
        return;
      }
    }
    else {
      (**(code **)(*piVar1 + 0x34))(piVar1,DAT_00736380,5);
      SetCursorPos(200,200);
      (**(code **)(*(int *)*in_EAX + 0x1c))((int *)*in_EAX);
    }
  }
  return;
}


// ==== 0x4130d0 FUN_004130d0

undefined4 FUN_004130d0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_EBX;
  byte local_14 [20];
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    local_14[0] = 0;
    local_14[1] = 0;
    local_14[2] = 0;
    local_14[3] = 0;
    local_14[4] = 0;
    local_14[5] = 0;
    local_14[6] = 0;
    local_14[7] = 0;
    local_14[8] = 0;
    local_14[9] = 0;
    local_14[10] = 0;
    local_14[0xb] = 0;
    local_14[0xc] = 0;
    local_14[0xd] = 0;
    local_14[0xe] = 0;
    local_14[0xf] = 0;
    local_14[0x10] = 0;
    local_14[0x11] = 0;
    local_14[0x12] = 0;
    local_14[0x13] = 0;
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if (iVar2 < 0) {
      iVar2 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1);
      if (iVar2 == -0x7ff8ffe2) {
        do {
          iVar2 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1);
        } while (iVar2 == -0x7ff8ffe2);
        return 0;
      }
    }
    else {
      param_1[1] = param_1[1] + 0x14;
      param_1[2] = (int)(local_14 + param_1[2]);
      param_1[5] = unaff_EBX;
      param_1[3] = 0x14;
      param_1[4] = (int)local_14;
      *(bool *)((int)param_1 + 0x1a) = (local_14[0] >> 7 & *(byte *)(param_1 + 6) == 0) != 0;
      *(bool *)((int)param_1 + 0x19) = (*(byte *)(param_1 + 6) & -1 < (char)local_14[0]) != 0;
      *(byte *)(param_1 + 6) = local_14[0] >> 7;
      FUN_004131a0(param_1);
    }
  }
  return 0;
}


// ==== 0x4131a0 FUN_004131a0

void FUN_004131a0(void)

{
  int *unaff_ESI;
  int *unaff_EDI;
  tagRECT local_10;
  
  GetClientRect(DAT_00736380,&local_10);
  if ((*unaff_ESI <= local_10.right) &&
     (local_10.right = local_10.left, local_10.left <= *unaff_ESI)) {
    if ((local_10.bottom < *unaff_EDI) ||
       (local_10.bottom = local_10.top, *unaff_EDI < local_10.top)) {
      *unaff_EDI = local_10.bottom;
    }
    return;
  }
  *unaff_ESI = local_10.right;
  return;
}


// ==== 0x4131f0 Struct_ClearFields8

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void Struct_ClearFields8(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  return;
}


// ==== 0x413210 FUN_00413210

void __fastcall FUN_00413210(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*(uint *)(in_EAX + 0xc) & 0x1000) == 0) {
    iVar4 = in_EAX + 0x10;
  }
  else {
    iVar4 = *(int *)(in_EAX + 0x10) + in_EAX;
  }
  iVar3 = (int)*(short *)(in_EAX + 6);
  iVar1 = (int)*(short *)(in_EAX + 4);
  iVar2 = iVar1 * iVar3 + iVar4;
  FUN_00647cb0(iVar4,iVar2,(iVar1 / 2) * (iVar3 / 2) + iVar2,iVar1,iVar1,iVar3,param_3,
               iVar1 * DAT_00701008,param_2);
  return;
}


// ==== 0x413270 FUN_00413270

void FUN_00413270(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 local_8 [8];
  
  if (DAT_00736348 != 0) {
    puVar5 = (undefined4 *)0x0;
    (**(code **)(*DAT_0078a494 + 0x4c))(DAT_0078a494,0,local_8,0,0);
    if ((*(uint *)(DAT_00736348 + 0xc) & 0x1000) == 0) {
      iVar1 = DAT_00736348 + 0x10;
    }
    else {
      iVar1 = *(int *)(DAT_00736348 + 0x10) + DAT_00736348;
    }
    FUN_00413210(iVar1);
    if ((*(uint *)(DAT_00736348 + 0xc) & 0x1000) == 0) {
      puVar4 = (undefined4 *)(DAT_00736348 + 0x10);
    }
    else {
      puVar4 = (undefined4 *)(*(int *)(DAT_00736348 + 0x10) + DAT_00736348);
    }
    uVar3 = *(uint *)(unaff_ESI + 0x40);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    (**(code **)(*DAT_0078a494 + 0x50))(DAT_0078a494,0);
  }
  return;
}


// ==== 0x413310 FUN_00413310

void __thiscall FUN_00413310(int param_1,int *param_2)

{
  byte *pbVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  char *pcVar14;
  bool bVar15;
  byte bVar7;
  
  iVar4 = DAT_00736348;
  bVar15 = DAT_00736348 == 0;
  *param_2 = (int)&DAT_0078a47c;
  DAT_0073634c = param_2;
  if (bVar15) {
    DAT_00736348 = SHP_FormatName((int)*(short *)(param_1 + 4),(int)*(short *)(param_1 + 6),0x20,0,0
                                  ,0x400,0,0x40);
    FUN_006486e2();
    iVar4 = DAT_00736348;
  }
  if ((*(uint *)(iVar4 + 0xc) & 0x1000) == 0) {
    iVar8 = iVar4 + 0x10;
  }
  else {
    iVar8 = *(int *)(iVar4 + 0x10) + iVar4;
  }
  sVar2 = *(short *)(iVar4 + 4);
  iVar11 = (int)sVar2;
  sVar3 = *(short *)(iVar4 + 6);
  iVar4 = (int)sVar3;
  bVar5 = 0;
  if (1 < iVar11) {
    bVar5 = 0;
    do {
      bVar5 = bVar5 + 1;
    } while (1 << (bVar5 & 0x1f) < iVar11);
  }
  bVar7 = 0;
  bVar6 = 0;
  if (1 < iVar4) {
    do {
      bVar6 = bVar7 + 1;
      bVar7 = bVar6;
    } while (1 << (bVar6 & 0x1f) < iVar4);
  }
  piVar12 = (int *)"MovieTexture";
  piVar13 = param_2 + 3;
  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar13 = *piVar12;
    piVar12 = piVar12 + 1;
    piVar13 = piVar13 + 1;
  }
  iVar4 = iVar4 * iVar11 * 4;
  *(undefined1 *)((int)param_2 + 0x23) = 0;
  pcVar14 = "MovieTexture";
  iVar11 = -1;
  uVar10 = 0x4d;
  do {
    iVar11 = iVar11 * 0x21 + uVar10;
    pbVar1 = (byte *)(pcVar14 + 1);
    uVar10 = (uint)*pbVar1;
    pcVar14 = pcVar14 + 1;
  } while (*pbVar1 != 0);
  param_2[0x10] = iVar4;
  param_2[0xe] = iVar4;
  *(short *)(param_2 + 0x11) = sVar2;
  *(byte *)(param_2 + 0x12) = bVar5;
  *(short *)((int)param_2 + 0x46) = sVar3;
  *(undefined2 *)((int)param_2 + 0x62) = 0x100;
  *(undefined2 *)(param_2 + 0x19) = 0x100;
  iVar4 = *param_2;
  param_2[9] = iVar11;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xf] = 0;
  *(undefined1 *)((int)param_2 + 0x4a) = 0x20;
  *(undefined1 *)((int)param_2 + 0x4b) = 0;
  *(undefined2 *)(param_2 + 0x13) = 0;
  *(undefined1 *)((int)param_2 + 0x4e) = 1;
  *(byte *)((int)param_2 + 0x49) = bVar6;
  *(undefined1 *)(param_2 + 0x15) = 0;
  *(undefined1 *)((int)param_2 + 0x55) = 0;
  *(undefined1 *)((int)param_2 + 0x56) = 0;
  *(undefined1 *)((int)param_2 + 0x51) = 0;
  *(undefined1 *)((int)param_2 + 0x4f) = 0;
  *(undefined1 *)((int)param_2 + 0x57) = 0;
  *(undefined1 *)((int)param_2 + 0x52) = 0;
  *(undefined2 *)((int)param_2 + 0x5e) = 0;
  *(undefined2 *)(param_2 + 0x18) = 0;
  param_2[0x1a] = 0;
  param_2[0x1b] = (int)param_2;
  param_2[0x1c] = iVar8;
  param_2[0x1d] = 0;
  param_2[0x1e] = 1;
  *(undefined4 *)(iVar4 + 0x14) = 0x15;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  FUN_0063f7c0();
  FUN_0063fc80();
  Texture__CreateD3D();
  return;
}


// ==== 0x4134a0 bMalloc_regarg

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void bMalloc_regarg(void)

{
  size_t in_EAX;
  
  _malloc(in_EAX);
  return;
}


// ==== 0x4134b0 FEScreen::MessageStub

/* [canon] hud med (capstone) docs/re/gameflow.md */

undefined4 FEScreen__MessageStub(undefined4 param_1)

{
  return param_1;
}


// ==== 0x4134c0 FUN_004134c0

undefined4 FUN_004134c0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0xc);
}


// ==== 0x4134d0 FEng_FindObjectByHash

/* [canon] canon med (hopper+capstone) docs/re/misc.md */

int FEng_FindObjectByHash(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (((((unaff_EDI != 0) && (iVar2 = FUN_004f65d0(), iVar2 != 0)) &&
       (iVar2 = FUN_004ffb70(), iVar2 != 0)) ||
      ((DAT_0073578c != 0 && (iVar2 = FUN_004ef050(uVar1), iVar2 != 0)))) &&
     (*(int *)(iVar2 + 0x18) == 2)) {
    return iVar2;
  }
  return 0;
}


// ==== 0x413520 FUN_00413520

void FUN_00413520(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar2 = 0;
    FEng__HashName(0);
    FUN_004f5f80(iVar1,uVar2);
  }
  return;
}


// ==== 0x413550 Screen_PC_Controller_Config::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_Controller_Config__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688003;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_Controller_Config__Screen_PC_Controller_Config(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4135b0 Screen_PC_Controller_Config::Screen_PC_Controller_Config

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_PC_Controller_Config__Screen_PC_Controller_Config(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006cbf14;
  _DAT_00777cc0 = 4;
  local_4 = 0;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd3b);
    }
  }
  DAT_0071b7cc = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd3c);
    }
  }
  DAT_0071b7d0 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd3d);
    }
  }
  _DAT_0071b7d4 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd3e);
    }
  }
  _DAT_0071b7d8 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd3f);
    }
  }
  _DAT_0071b7dc = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xcaaccd40);
    }
  }
  _DAT_0071b7e0 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xdbeeae54);
    }
  }
  DAT_0071b7e4 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x200030ea);
    }
  }
  _DAT_0071b7e8 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xc2998e98);
    }
  }
  _DAT_0071b7ec = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x4b2b49a7);
    }
  }
  _DAT_0071b7f0 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x4d807248);
    }
  }
  _DAT_0071b7f4 = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x4fd59ae9);
    }
  }
  _DAT_0071b7f8 = iVar3;
  iVar4 = FEng__HashName();
  iVar3 = (&DAT_0071b7e4)[DAT_00736344];
  for (iVar6 = *(int *)(iVar3 + 0x4c); (iVar6 != 0 && (*(int *)(iVar6 + 0x30) != iVar4));
      iVar6 = *(int *)(iVar6 + 4)) {
  }
  *(int *)(iVar3 + 0x54) = iVar6;
  if (iVar6 != 0) {
    FUN_004ff030(iVar3);
  }
  *(undefined4 *)(*(int *)(iVar3 + 0x54) + 0x10) = 0;
  ControlsScreen__SetAllBindingLabels();
  *(undefined1 *)(param_1 + 0x20) = 0;
  FUN_00413a70(param_1,0);
  pcVar5 = PTR_s_PC_JoyPad_Config_fng_00700ffc;
  do {
    cVar1 = pcVar5[param_1[3] - (int)PTR_s_PC_JoyPad_Config_fng_00700ffc];
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    if ((cVar1 == '\0') || (cVar2 == '\0')) break;
  } while (cVar1 == cVar2);
  if (cVar1 == cVar2) {
    if (DAT_0073578c == 0) goto LAB_004139b3;
    uVar7 = 0;
  }
  else {
    if (DAT_0073578c == 0) goto LAB_004139b3;
    uVar7 = 1;
  }
  FUN_004f5f80(DAT_0073578c,uVar7);
LAB_004139b3:
  iVar6 = DAT_0073578c;
  iVar3 = param_1[3];
  uVar7 = FEng__HashName();
  if (((((iVar3 == 0) || (iVar3 = FUN_004f65d0(), iVar6 = DAT_0073578c, iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar3 == 0)) &&
      ((iVar6 == 0 || (iVar3 = FUN_004ef050(uVar7), iVar3 == 0)))) || (*(int *)(iVar3 + 0x18) != 2))
  {
    iVar3 = 0;
  }
  param_1[0x23] = iVar3;
  *(undefined1 *)(param_1 + 0x22) = 0;
  DAT_00736340 = DAT_00736340 + 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x413a30 FUN_00413a30

void * __thiscall FUN_00413a30(void *param_1,byte param_2)

{
  FUN_00413a50();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x413a50 FUN_00413a50

void __fastcall FUN_00413a50(undefined4 *param_1)

{
  DAT_00736340 = DAT_00736340 + -1;
  *param_1 = &PTR_FUN_006cbf14;
  FUN_004f7b50();
  return;
}


// ==== 0x413a70 FUN_00413a70

void FUN_00413a70(int param_1,char param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int *piVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 uVar12;
  int iVar13;
  bool bVar14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  undefined1 *local_4;
  
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  if (*(char *)(param_1 + 0x80) != '\0') {
    *(undefined4 *)(&DAT_0078dce4 + (&DAT_0071b808)[DAT_00736344 * 3] * 0x270) = 0;
    DAT_00736508 = 0;
    iVar3 = FUN_004f65d0();
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x1c) = 0xff;
    }
    *(undefined1 *)(param_1 + 0x80) = 0;
  }
  iVar3 = 0;
  puVar7 = &DAT_0071b800;
  local_10 = 0;
  local_8 = 0;
  local_c = &DAT_0071b800;
  local_4 = &DAT_0078dbdc;
  do {
    if (*(int *)(local_4 + -4) != -1) {
      switch(*local_4) {
      case 0x13:
        iVar4 = 1;
        break;
      case 0x14:
      case 0x15:
        iVar4 = 3;
        break;
      case 0x16:
        iVar4 = 2;
        break;
      default:
        iVar4 = 0;
      }
      if (iVar4 == 2) {
        uVar12 = 0x697d0d66;
        uVar5 = 2;
      }
      else if (iVar4 == 3) {
        uVar12 = 0x7b557ab8;
        uVar5 = 1;
        *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      }
      else {
        uVar12 = 0x9024d262;
        uVar5 = 0;
      }
      *puVar7 = uVar5;
      uVar5 = (&DAT_0071b7cc)[iVar3];
      puVar7[2] = local_8;
      puVar7[1] = uVar5;
      uVar5 = *(undefined4 *)((&DAT_0071b7e4)[iVar3] + 0x10);
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
         (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar3 = FUN_004ef050(uVar5);
          goto LAB_00413baa;
        }
      }
      else {
LAB_00413baa:
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) == 2)) {
          *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
          puVar7 = DAT_00735710;
          bVar14 = DAT_00735710 != (undefined4 *)0x0;
          *(undefined4 *)(iVar3 + 0x5c) = uVar12;
          if (bVar14) {
            (**(code **)*puVar7)(iVar3);
          }
          *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
        }
      }
      iVar3 = local_10 + 1;
      puVar7 = local_c + 3;
      local_10 = iVar3;
      local_c = puVar7;
    }
    local_4 = local_4 + 0x270;
    local_8 = local_8 + 1;
  } while ((int)local_4 < 0x78ea7c);
  *(int *)(param_1 + 0x9c) = iVar3;
  iVar4 = DAT_0073578c;
  if (((param_2 == '\0') && (DAT_00736344 < iVar3)) ||
     (DAT_00736344 = -1, *(char *)(param_1 + 0x80) != '\0')) {
LAB_00413c8d:
    if (DAT_0073578c != 0) {
      FUN_004f5ed0(DAT_0073578c);
    }
  }
  else {
    DAT_00736344 = 0;
    if (DAT_0073578c != 0) {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar4 + 8),*(int *)(iVar3 + 0x18));
      }
      goto LAB_00413c8d;
    }
  }
  pcVar8 = "keyboard_config_title";
  iVar3 = -1;
  bVar2 = 0x6b;
  do {
    if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
      bVar2 = bVar2 - 0x20;
    }
    uVar10 = (uint)bVar2;
    bVar2 = pcVar8[1];
    iVar3 = iVar3 * 0x21 + uVar10;
    pcVar8 = pcVar8 + 1;
  } while (bVar2 != 0);
  iVar4 = DAT_0073578c;
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_00413d4e:
    if ((iVar4 != 0) && (iVar6 = FUN_004ef050(iVar3), iVar6 != 0)) {
LAB_00413d61:
      if (*(int *)(iVar6 + 0x18) == 2) goto LAB_00413d6d;
    }
  }
  else {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00413d37:
      if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 == 0))
      goto LAB_00413d4e;
      goto LAB_00413d61;
    }
    if (DAT_0073578c != 0) {
      iVar13 = *(int *)(DAT_0073578c + 8);
      if ((iVar13 == 0) ||
         ((iVar6 = FUN_004fd1e0(iVar13 + 0xdc), iVar6 == 0 &&
          (iVar6 = FUN_004fd1e0(iVar13 + 0xec), iVar6 == 0)))) goto LAB_00413d4e;
      goto LAB_00413d37;
    }
  }
  iVar6 = 0;
LAB_00413d6d:
  uVar5 = *(undefined4 *)(&DAT_007070b0 + (&DAT_0071b800)[DAT_00736344 * 3] * 4);
  if (iVar6 != 0) {
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
    puVar7 = DAT_00735710;
    bVar14 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar6 + 0x5c) = uVar5;
    if (bVar14) {
      (**(code **)*puVar7)(iVar6);
    }
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (DAT_00736504 < 6) {
    _param_2 = DAT_00736504 * 4;
    do {
      pbVar11 = *(byte **)(*(int *)((int)&DAT_0071b7cc + _param_2) + 0x14);
      iVar3 = -1;
      if (pbVar11 != (byte *)0x0) {
        bVar2 = *pbVar11;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar1 = pbVar11 + 1;
          pbVar11 = pbVar11 + 1;
          bVar2 = *pbVar1;
        }
      }
      if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
         (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
        iVar6 = *(int *)(iVar4 + 0x88);
        iVar13 = 0;
        if (iVar6 != 0) {
          piVar9 = *(int **)(iVar4 + 0x84);
          do {
            if (*(int *)(*piVar9 + 0x10) == iVar3) {
              iVar13 = *piVar9;
            }
            piVar9 = piVar9 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          if (iVar13 != 0) {
            *(uint *)(iVar13 + 0x1c) = *(uint *)(iVar13 + 0x1c) | 0x4000000;
          }
        }
      }
      uVar5 = *(undefined4 *)(*(int *)((int)&DAT_0071b7e4 + _param_2) + 0x10);
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00413ed2:
        if (DAT_0073578c != 0) {
          FUN_004ef050(uVar5);
        }
      }
      else {
        iVar3 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
          if (DAT_0073578c != 0) {
            iVar4 = *(int *)(DAT_0073578c + 8);
            if ((iVar4 == 0) ||
               ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
                (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_00413ed2;
            goto LAB_00413ec1;
          }
        }
        else {
LAB_00413ec1:
          if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar3 == 0)) goto LAB_00413ed2;
        }
      }
      FEObject__SetFormattedText(&DAT_006b9172);
      pcVar8 = "disabled";
      iVar3 = -1;
      bVar2 = 100;
      do {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar3 = iVar3 * 0x21 + (uint)bVar2;
        bVar2 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (bVar2 != 0);
      iVar4 = *(int *)((int)&DAT_0071b7cc + _param_2);
      for (iVar6 = *(int *)(iVar4 + 0x4c); (iVar6 != 0 && (*(int *)(iVar6 + 0x30) != iVar3));
          iVar6 = *(int *)(iVar6 + 4)) {
      }
      *(int *)(iVar4 + 0x54) = iVar6;
      if (iVar6 != 0) {
        FUN_004ff030(iVar4);
      }
      *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
      pcVar8 = "disabled";
      iVar3 = -1;
      bVar2 = 100;
      do {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar3 = iVar3 * 0x21 + (uint)bVar2;
        bVar2 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (bVar2 != 0);
      iVar4 = *(int *)((int)&DAT_0071b7e4 + _param_2);
      for (iVar6 = *(int *)(iVar4 + 0x4c); (iVar6 != 0 && (*(int *)(iVar6 + 0x30) != iVar3));
          iVar6 = *(int *)(iVar6 + 4)) {
      }
      *(int *)(iVar4 + 0x54) = iVar6;
      if (iVar6 != 0) {
        FUN_004ff030(iVar4);
      }
      _param_2 = _param_2 + 4;
      *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0x10) = 0;
    } while (_param_2 < 0x18);
  }
  return;
}


// ==== 0x413fe0 FUN_00413fe0

void __fastcall FUN_00413fe0(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x90);
  iVar1 = 0;
  do {
    if (*(int *)((&DAT_0071b7cc)[iVar1] + 0x10) == param_2) goto LAB_00414005;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = -1;
LAB_00414005:
  *(int *)(param_1 + 0x90) = iVar1;
  return;
}


// ==== 0x414010 FUN_00414010

void FUN_00414010(void)

{
  uint in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  uVar3 = 0;
  if (in_EAX < 0x863a1227) {
    if (in_EAX == 0x863a1226) {
      uVar2 = 5;
      goto LAB_004141df;
    }
    if (in_EAX < 0x4890bd64) {
      if (in_EAX == 0x4890bd63) {
        uVar2 = 1;
      }
      else if (in_EAX < 0x3309a5f2) {
        if (in_EAX == 0x3309a5f1) {
          uVar2 = 8;
          goto LAB_004141df;
        }
        if (in_EAX == 0x1c0af2a2) {
          uVar2 = 8;
        }
        else {
          if (in_EAX != 0x22a3bab9) {
            if (in_EAX != 0x29b105f2) {
              return;
            }
            uVar2 = 10;
            goto LAB_004141df;
          }
          uVar2 = 6;
        }
      }
      else if (in_EAX == 0x34fb3a90) {
        uVar2 = 0xe;
      }
      else {
        if (in_EAX != 0x42e9cf4f) {
          return;
        }
        uVar2 = 7;
      }
    }
    else if (in_EAX < 0x7d3f26af) {
      if (in_EAX == 0x7d3f26ae) {
        uVar2 = 4;
        goto LAB_004141df;
      }
      if (in_EAX == 0x5a0a56e3) {
        uVar2 = 10;
      }
      else {
        if (in_EAX != 0x6c00828b) {
          if (in_EAX != 0x7cd293a8) {
            return;
          }
          uVar2 = 3;
          goto LAB_004141df;
        }
        uVar2 = 0xc;
      }
    }
    else {
      if (in_EAX != 0x836d9ef3) {
        if (in_EAX != 0x844010f3) {
          return;
        }
        uVar2 = 0xd;
        goto LAB_004141df;
      }
      uVar2 = 9;
    }
  }
  else if (in_EAX < 0xe9dac113) {
    if (in_EAX == 0xe9dac112) {
      uVar2 = 2;
    }
    else {
      if (0xc9a3969f < in_EAX) {
        if (in_EAX == 0xd6830a02) {
          uVar2 = 9;
        }
        else {
          if (in_EAX != 0xdfd37c48) {
            return;
          }
          uVar2 = 6;
        }
        goto LAB_004141df;
      }
      if (in_EAX == 0xc9a3969f) {
        uVar2 = 4;
      }
      else {
        if (in_EAX != 0x94882624) {
          if (in_EAX == 0x95cb1a5f) {
            uVar2 = 0xe;
          }
          else {
            if (in_EAX != 0xb558279a) {
              return;
            }
            uVar2 = 0xc;
          }
          goto LAB_004141df;
        }
        uVar2 = 0xd;
      }
    }
  }
  else if (in_EAX < 0xfbc62a1a) {
    if (in_EAX != 0xfbc62a19) {
      if (in_EAX == 0xf0b31861) {
        uVar2 = 2;
      }
      else {
        if (in_EAX != 0xf53f735e) {
          return;
        }
        uVar2 = 7;
      }
      goto LAB_004141df;
    }
    uVar2 = 3;
  }
  else {
    if (in_EAX != 0xfd074017) {
      if (in_EAX != 0xfe6bcc72) {
        return;
      }
      uVar2 = 1;
      goto LAB_004141df;
    }
    uVar2 = 5;
  }
  uVar3 = 1;
LAB_004141df:
  *(uint *)(unaff_ESI + 0x84) = in_EAX;
  iVar1 = DAT_00736344;
  *(undefined1 *)(unaff_ESI + 0x80) = 1;
  iVar1 = (&DAT_0071b808)[iVar1 * 3];
  *(undefined4 *)(&DAT_0078dce4 + iVar1 * 0x270) = uVar2;
  *(undefined4 *)(&DAT_0078dce8 + iVar1 * 0x270) = uVar3;
  FUN_00407b40();
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  return;
}


// ==== 0x414230 FUN_00414230

void __fastcall FUN_00414230(int param_1)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if (param_1 == -0x6edfbf62) {
    iVar2 = *(int *)(in_EAX + 0x10);
    if (iVar2 == -0x355332c5) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar2 = FUN_004ef050(0xcaaccd3d);
      if (iVar2 == 0) {
        return;
      }
      bVar1 = ~(byte)((uint)*(undefined4 *)(iVar2 + 0x1c) >> 0x1a) & 1;
LAB_004142ec:
      if (bVar1 == 0) {
        return;
      }
      if (DAT_0073578c == 0) {
        return;
      }
      FUN_004f5ed0(DAT_0073578c);
      return;
    }
    if (iVar2 == -0x355332c4) {
LAB_004142c3:
      if (DAT_0073578c == 0) {
        return;
      }
      FUN_004f5ed0(DAT_0073578c);
      return;
    }
    if (iVar2 != -0x355332c3) {
      return;
    }
    bVar1 = FUN_004f6510(*(undefined4 *)(unaff_ESI + 0xc));
  }
  else {
    if (param_1 != -0x4a68e40f) {
      return;
    }
    iVar2 = *(int *)(in_EAX + 0x10);
    if (iVar2 != -0x355332c5) {
      if (iVar2 != -0x355332c4) {
        if (iVar2 != -0x355332c3) {
          return;
        }
        goto LAB_004142c3;
      }
      bVar1 = FUN_004f6510(*(undefined4 *)(unaff_ESI + 0xc));
      goto LAB_004142ec;
    }
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(0xcaaccd3c);
    if (iVar2 == 0) {
      return;
    }
    bVar1 = ~(byte)((uint)*(undefined4 *)(iVar2 + 0x1c) >> 0x1a) & 1;
  }
  if ((bVar1 != 0) && (DAT_0073578c != 0)) {
    FUN_004f5ed0(DAT_0073578c);
  }
  return;
}


// ==== 0x414350 FUN_00414350

void __thiscall FUN_00414350(int param_1,uint param_2,int param_3)

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
  
  if (param_2 < 0xb5971bf2) {
    if (param_2 == 0xb5971bf1) {
LAB_00414452:
      FUN_00414230();
      return;
    }
    if (param_2 < 0x9120409f) {
      if (param_2 == 0x9120409e) goto LAB_00414452;
      if (param_2 == 0xc407210) {
        iVar1 = FUN_00413fe0();
        if (-1 < iVar1) {
          FUN_00414620();
          return;
        }
        FUN_00414010();
LAB_004143e2:
        FEString__SetLabelHash();
        FEObject__SetScript("FadeIn",1);
        return;
      }
      if (param_2 == 0x911ab364) {
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else if (((param_2 == 0xabc08912) && (*(int *)(param_1 + 0x8c) != 0)) && (param_3 != 0)) {
      iVar1 = FUN_00413fe0();
      if (iVar1 != *(int *)(param_1 + 0x94)) {
        Screen_PC_Controller_Config__GetObjectMessageHash(param_1);
        goto LAB_004143e2;
      }
    }
  }
  else if (param_2 == 0xc519bfbf) {
    if ((*(char *)(param_1 + 0x88) == '\0') && (*(char *)(param_1 + 0x80) == '\0')) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0xf581cb6d;
      uStack_1c = 0xefedcba0;
      uStack_20 = 0x639;
      uStack_14 = 0;
      uStack_18 = 0x541389e5;
      uStack_10 = 0;
      uStack_c = 0xb8a7c6cc;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    }
  }
  else if (param_2 == 0xc98356ba) {
    if (*(char *)(param_1 + 0x88) != '\0') {
      iVar1 = FUN_004f65d0();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0xff;
      }
      *(undefined1 *)(param_1 + 0x88) = 0;
      FEString__SetLabelHash();
      FEObject__SetScript("FadeIn",1);
    }
    if ((*(char *)(param_1 + 0x80) != '\0') &&
       (iVar1 = *(int *)(&DAT_0078dce4 + (&DAT_0071b808)[DAT_00736344 * 3] * 0x270),
       *(bool *)(param_1 + 0x80) = iVar1 != 0, iVar1 == 0)) {
      ControlsScreen__SetAllBindingLabels();
      FUN_004f64b0(*(undefined4 *)(param_1 + 0xc));
      *(undefined1 *)(param_1 + 0x88) = 1;
      return;
    }
  }
  else if (param_2 == 0xefedcba0) {
    FUN_00414930(param_1);
    return;
  }
  return;
}


// ==== 0x414441 FUN_00414441

void FUN_00414441(void)

{
  undefined4 unaff_EBP;
  bool in_ZF;
  
  if (!in_ZF) {
    Screen_PC_Controller_Config__GetObjectMessageHash(unaff_EBP);
    FEString__SetLabelHash();
    FEObject__SetScript("FadeIn",1);
    return;
  }
  return;
}


// ==== 0x4145c0 Screen_PC_Controller_Config::GetObjectMessageHash

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined4 Screen_PC_Controller_Config__GetObjectMessageHash(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = 0;
  if (0 < DAT_00736504) {
    piVar2 = &DAT_0071b800;
    do {
      if (*(int *)(piVar2[1] + 0x10) == unaff_EDI) {
        iVar1 = *piVar2;
        if (iVar1 == 0) {
          return 0x632935cb;
        }
        if (iVar1 == 1) {
          return 0x50baa921;
        }
        if (iVar1 == 2) {
          return 0x73abfc4f;
        }
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar3 < DAT_00736504);
  }
  return 0x8b0d1500;
}


// ==== 0x414620 FUN_00414620

void __fastcall FUN_00414620(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if ((((*(char *)(in_EAX + 0x80) == '\0') && (DAT_00736344 != param_1)) &&
      (DAT_00736344 = param_1, DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x414680 ControlsScreen::SetAllBindingLabels

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void ControlsScreen__SetAllBindingLabels(void)

{
  ControlsScreen__SetBindingLabel(0xe,0);
  ControlsScreen__SetBindingLabel(0xd,0);
  ControlsScreen__SetBindingLabel(0xc,0);
  ControlsScreen__SetBindingLabel(10,0);
  ControlsScreen__SetBindingLabel(9,0);
  ControlsScreen__SetBindingLabel(8,0);
  ControlsScreen__SetBindingLabel(7,0);
  ControlsScreen__SetBindingLabel(6,0);
  ControlsScreen__SetBindingLabel(5,0);
  ControlsScreen__SetBindingLabel(2,0);
  ControlsScreen__SetBindingLabel(1,0);
  ControlsScreen__SetBindingLabel(4,0);
  ControlsScreen__SetBindingLabel(3,0);
  ControlsScreen__SetBindingLabel(0xe,1);
  ControlsScreen__SetBindingLabel(0xd,1);
  ControlsScreen__SetBindingLabel(0xc,1);
  ControlsScreen__SetBindingLabel(10,1);
  ControlsScreen__SetBindingLabel(9,1);
  ControlsScreen__SetBindingLabel(8,1);
  ControlsScreen__SetBindingLabel(7,1);
  ControlsScreen__SetBindingLabel(6,1);
  ControlsScreen__SetBindingLabel(5,1);
  ControlsScreen__SetBindingLabel(2,1);
  ControlsScreen__SetBindingLabel(1,1);
  ControlsScreen__SetBindingLabel(4,1);
  ControlsScreen__SetBindingLabel(3,1);
  return;
}


// ==== 0x414830 ControlsScreen::SetBindingLabel

/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

void __thiscall
ControlsScreen__SetBindingLabel(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  LPCSTR lpMultiByteStr;
  int iVar2;
  WCHAR *pWVar3;
  WCHAR local_30 [24];
  
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(param_1);
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 2)) {
    if (*(int *)(&DAT_0078dbdc + (&DAT_0071b808)[DAT_00736344 * 3] * 0x270) == 0x13) {
      lpMultiByteStr =
           (LPCSTR)InputKeyboard__GetBindingName
                             (&DAT_0078daa8 + (&DAT_0071b808)[DAT_00736344 * 3] * 0x270,param_2,
                              param_3);
    }
    else {
      lpMultiByteStr =
           (LPCSTR)InputWheel__GetBindingName
                             (&DAT_0078daa8 + (&DAT_0071b808)[DAT_00736344 * 3] * 0x270,param_2,
                              param_3);
    }
    pWVar3 = local_30;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      pWVar3[0] = L'\0';
      pWVar3[1] = L'\0';
      pWVar3 = pWVar3 + 2;
    }
    *pWVar3 = L'\0';
    MultiByteToWideChar(0,0,lpMultiByteStr,-1,local_30,0x17);
    iVar2 = FUN_006724e4(lpMultiByteStr);
    if (iVar2 != 0) {
      WString_Assign();
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400002;
      return;
    }
    FEObject__SetFormattedText(&DAT_006cbf24);
  }
  return;
}


// ==== 0x414930 FUN_00414930

void FUN_00414930(void)

{
  int iVar1;
  char cVar2;
  
  Input__InitActionFormats();
  iVar1 = (&DAT_0071b808)[DAT_00736344 * 3];
  if ((&DAT_0078dbd8)[iVar1 * 0x9c] != -1) {
    cVar2 = InputDevice__IsKeyboardType();
    if (cVar2 != '\0') {
      FUN_00405e10();
      ControlsScreen__SetAllBindingLabels();
      return;
    }
    FUN_004060a0(&DAT_0078daa8 + iVar1 * 0x270);
    ControlsScreen__SetAllBindingLabels();
  }
  return;
}


// ==== 0x414990 FUN_00414990

void FUN_00414990(void)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_s_PC_Keyboard_Config_fng_00700ff8;
  while( true ) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) break;
    ppuVar2 = ppuVar2 + 1;
    if (0x701003 < (int)ppuVar2) {
      return;
    }
  }
  FUN_00413a70(*(int *)(iVar1 + 0x14),1);
  return;
}


// ==== 0x4149d0 FEng_FindObjectByHash2

/* [canon] canon med (hopper+capstone) docs/re/misc.md */

int FEng_FindObjectByHash2(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (((unaff_EDI != 0) && (iVar2 = FUN_004f65d0(), iVar2 != 0)) &&
     (iVar2 = FUN_004ffb70(), iVar2 != 0)) {
    return iVar2;
  }
  if (DAT_0073578c == 0) {
    return 0;
  }
  iVar2 = FUN_004ef050(uVar1);
  return iVar2;
}


// ==== 0x414a10 FUN_00414a10

void FUN_00414a10(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (unaff_EDI != 0) {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_00414a55;
    }
  }
  if (DAT_0073578c != 0) {
    uVar1 = FUN_004ef050(uVar1);
    FEObject__SetInvisible(uVar1);
    return;
  }
  iVar2 = 0;
LAB_00414a55:
  FEObject__SetInvisible(iVar2);
  return;
}


// ==== 0x414a60 FUN_00414a60

void FUN_00414a60(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (unaff_EDI != 0) {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_00414aa5;
    }
  }
  if (DAT_0073578c != 0) {
    uVar1 = FUN_004ef050(uVar1);
    FEObject__SetVisible(uVar1);
    return;
  }
  iVar2 = 0;
LAB_00414aa5:
  FEObject__SetVisible(iVar2);
  return;
}


// ==== 0x414ab0 FUN_00414ab0

void __fastcall FUN_00414ab0(undefined4 *param_1)

{
  *param_1 = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  return;
}


// ==== 0x414ac0 Slider::StepUp

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Slider__StepUp(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x1c);
  *(float *)(param_1 + 0x1c) = fVar1;
  if (*(float *)(param_1 + 0x14) < fVar1) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  }
  if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18)) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  }
  return;
}


// ==== 0x414af0 Slider::StepDown

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Slider__StepDown(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x24);
  *(float *)(param_1 + 0x1c) = fVar1;
  if (*(float *)(param_1 + 0x14) < fVar1) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  }
  if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18)) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  }
  return;
}


// ==== 0x414b20 Slider::scalar_deleting_destructor

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 * __thiscall Slider__scalar_deleting_destructor(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x414b40 ListSlider::_ListSlider

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall ListSlider___ListSlider(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 0xc;
  *param_1 = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  *param_1 = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  return;
}


// ==== 0x414b80 ListSlider::scalar_deleting_destructor

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void * __thiscall ListSlider__scalar_deleting_destructor(void *param_1,byte param_2)

{
  ListSlider___ListSlider();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x414ba0 FUN_00414ba0

void FUN_00414ba0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006cbe64;
  ListSlider___ListSlider();
  FUN_004f7b50();
  return;
}


// ==== 0x414bc0 FUN_00414bc0

void * __thiscall FUN_00414bc0(void *param_1,byte param_2)

{
  FUN_00414ba0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x414be0 Screen_PC_Graphics::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_Graphics__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xb8);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_Graphics__Screen_PC_Graphics(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x414c40 Screen_PC_Graphics::Screen_PC_Graphics

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 * Screen_PC_Graphics__Screen_PC_Graphics(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687fc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  piVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006cbe64;
  puVar4 = param_1 + 0x1c;
  param_1[0x11] = &DAT_006b9172;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *piVar1 = (int)&PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar4 = puVar4;
  param_1[0x1d] = puVar4;
  param_1[0x1e] = 0;
  _DAT_00777cc0 = 4;
  local_30 = param_1[3];
  param_1[0x20] = 0;
  local_14 = (void *)(float)DAT_00736334;
  local_4 = 1;
  local_2c = "CardetailSliderBase_1";
  local_24 = "CardetailText_1";
  local_28 = "CardetailSlider_1_";
  local_20 = 3;
  local_10 = 0x3f800000;
  local_1c = 0x3f800000;
  local_18 = 0x40400000;
  (**(code **)(*piVar1 + 0x14))(&local_30);
  (**(code **)(*piVar1 + 0xc))(1);
  puVar4 = param_1 + 0x21;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (param_1[3] == 0) {
LAB_00414d54:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x806de7a6);
    }
  }
  else {
    iVar3 = FUN_004f65d0();
    if (iVar3 == 0) goto LAB_00414d54;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_00414d54;
  }
  param_1[0x21] = iVar3;
  if (param_1[3] == 0) {
LAB_00414d98:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xb0eca02e);
    }
  }
  else {
    iVar3 = FUN_004f65d0();
    if (iVar3 == 0) goto LAB_00414d98;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_00414d98;
  }
  param_1[0x22] = iVar3;
  if (param_1[3] == 0) {
LAB_00414ddc:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x7e7c23b9);
    }
  }
  else {
    iVar3 = FUN_004f65d0();
    if (iVar3 == 0) goto LAB_00414ddc;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_00414ddc;
  }
  param_1[0x23] = iVar3;
  if (param_1[3] != 0) {
    iVar3 = FUN_004f65d0();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_00414e3c;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(0x80720ff);
  }
LAB_00414e3c:
  param_1[0x24] = iVar3;
  param_1[0x1f] = DAT_00700e70;
  iVar3 = DAT_00736334 + 1;
  param_1[0x17] = (float)iVar3;
  if ((float)param_1[0x15] < (float)iVar3) {
    param_1[0x17] = param_1[0x15];
  }
  if ((float)param_1[0x17] < (float)param_1[0x16]) {
    param_1[0x17] = param_1[0x16];
  }
  (**(code **)(*piVar1 + 0x10))();
  FUN_004151c0();
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
  param_1[0x2d] = iVar3;
  ExceptionList = local_14;
  return param_1;
}


// ==== 0x414f00 FUN_00414f00

void FUN_00414f00(void)

{
  int in_EAX;
  int iVar1;
  
  *(undefined4 *)(in_EAX + 0x7c) = DAT_00700e70;
  iVar1 = DAT_00736334 + 1;
  *(float *)(in_EAX + 0x5c) = (float)iVar1;
  if (*(float *)(in_EAX + 0x54) < (float)iVar1) {
    *(undefined4 *)(in_EAX + 0x5c) = *(undefined4 *)(in_EAX + 0x54);
  }
  if (*(float *)(in_EAX + 0x5c) < *(float *)(in_EAX + 0x58)) {
    *(undefined4 *)(in_EAX + 0x5c) = *(undefined4 *)(in_EAX + 0x58);
  }
  (**(code **)(*(int *)(in_EAX + 0x40) + 0x10))();
  FUN_004151c0();
  return;
}


// ==== 0x414f60 FUN_00414f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00414f60(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_2 < 0xb5971bf2) {
    if ((param_2 != 0xb5971bf1) && (param_2 != 0xc407210)) {
      if (param_2 == 0x911ab364) {
        DAT_00700e70 = *(undefined4 *)(param_1 + 0x7c);
        _DAT_00736394 = _ftol_nocw();
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x9120409e) {
        return;
      }
    }
    uVar1 = *(uint *)(param_3 + 0x10);
    if (uVar1 < 0xcbbd95e3) {
      if (uVar1 == 0xcbbd95e2) {
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_24 = 0xf581cb6d;
        uStack_1c = 0xe5707304;
        uStack_20 = 0x639;
        uStack_14 = 0x33120188;
        uStack_18 = 0x541389e5;
        uStack_10 = 1;
        uStack_c = 0xb8a7c6cc;
        FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (uVar1 == 0x823ce9ac) {
        FUN_00415120();
        return;
      }
      if ((uVar1 == 0xa936c3a2) && (param_2 == 0xc407210)) {
        FUN_004f63e0(0xff);
        return;
      }
    }
    else if (uVar1 == 0xf81c7981) {
      Screen_PC_Customize_Graphics__AdjustSlider0();
      _ftol_nocw();
      GraphicsQuality_Set();
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
      FEManager__PushPackageChecked(0x32,0);
    }
    FUN_00415300(param_1);
  }
  else if (param_2 == 0xe5707304) {
    FUN_00410a00();
    FUN_00414f00();
    return;
  }
  return;
}


// ==== 0x415001 FUN_00415001

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415001(void)

{
  undefined4 in_EAX;
  
  _DAT_00736394 = in_EAX;
  FUN_004f6360();
  return;
}


// ==== 0x415120 FUN_00415120

void __fastcall FUN_00415120(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  
  if (in_EAX == -0x6edfbf62) {
    piVar1 = (int *)(param_1 + 0x7c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      *(undefined4 *)(param_1 + 0x7c) = 4;
    }
    if (*(int *)(&DAT_0071b7b0 + *(int *)(param_1 + 0x7c) * 4) == 0) {
      do {
        piVar1 = (int *)(param_1 + 0x7c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + 0x7c) = 4;
        }
      } while (*(int *)(&DAT_0071b7b0 + *(int *)(param_1 + 0x7c) * 4) == 0);
      FUN_004151c0();
      return;
    }
  }
  else if (in_EAX == -0x4a68e40f) {
    iVar2 = *(int *)(param_1 + 0x7c) + 1;
    *(int *)(param_1 + 0x7c) = iVar2;
    if (4 < iVar2) {
      *(undefined4 *)(param_1 + 0x7c) = 0;
    }
    iVar2 = *(int *)(&DAT_0071b7b0 + *(int *)(param_1 + 0x7c) * 4);
    while (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x7c) + 1;
      *(int *)(param_1 + 0x7c) = iVar2;
      if (4 < iVar2) {
        *(undefined4 *)(param_1 + 0x7c) = 0;
      }
      iVar2 = *(int *)(&DAT_0071b7b0 + *(int *)(param_1 + 0x7c) * 4);
    }
  }
  FUN_004151c0();
  return;
}


// ==== 0x4151c0 FUN_004151c0

void FUN_004151c0(void)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int extraout_EDX;
  int unaff_EBX;
  int iVar7;
  byte local_20;
  byte local_1f [31];
  
  iVar4 = 0;
  do {
    iVar1 = iVar4 + 1;
    bSPrintf_regdst(0x20,"Res_%02d",iVar1);
    iVar7 = -1;
    pbVar5 = &local_20;
    bVar3 = local_20;
    if (iVar4 == *(int *)(unaff_EBX + 0x7c)) {
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar7 = iVar7 * 0x21 + (uint)bVar3;
        pbVar2 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        bVar3 = *pbVar2;
      }
      if (((((*(int *)(unaff_EBX + 0xc) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
           (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
          ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(iVar7), iVar4 != 0)))) &&
         (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar4 + 0x18) == 5)) {
        uVar6 = *(undefined4 *)(iVar4 + 0x60);
        iVar4 = *(int *)(iVar4 + 0x5c);
        if (0 < iVar4) {
          do {
            FEObject__SetVisible(uVar6);
            uVar6 = *(undefined4 *)(extraout_EDX + 4);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
    }
    else {
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar2 = pbVar5 + 1;
        iVar7 = iVar7 * 0x21 + (uint)bVar3;
        pbVar5 = pbVar5 + 1;
        bVar3 = *pbVar2;
      }
      if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar7);
        }
      }
      FEObject__SetInvisible(iVar4);
    }
    iVar4 = iVar1;
  } while (iVar1 < 5);
  return;
}


// ==== 0x415300 FUN_00415300

void FUN_00415300(int param_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int local_8;
  
  piVar6 = (int *)(param_1 + 0x84);
  local_8 = 0xc;
  do {
    if (((*piVar6 != 0) && (DAT_007064b2 != '\0')) &&
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 != '\0')) {
      uVar1 = *(uint *)(*piVar6 + 0x10);
      if (uVar1 < 0x806de7a7) {
        if (uVar1 == 0x806de7a6) {
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
             (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
            if (DAT_0073578c == 0) goto LAB_004153fd;
            iVar5 = FUN_004ef050(0xf81c7981);
          }
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar6,*(undefined4 *)(param_1 + 0xb4),iVar5,0);
          }
        }
        else if (uVar1 == 0x80720ff) {
          uVar3 = *(undefined4 *)(param_1 + 0xb4);
          uVar4 = FUN_004f6670();
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xb5971bf1,*piVar6,uVar3,uVar4,0);
          }
        }
        else if (uVar1 == 0x7e7c23b9) {
          uVar3 = FUN_004f6670();
          FUN_004f6540(0x9120409e,uVar3);
        }
      }
      else if (uVar1 == 0xb0eca02e) {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FUN_004f65d0(), iVar5 == 0)) ||
           (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
          if (DAT_0073578c == 0) goto LAB_004153fd;
          iVar5 = FUN_004ef050(0xf81c7981);
        }
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0x9120409e,*piVar6,*(undefined4 *)(param_1 + 0xb4),iVar5,0);
        }
      }
    }
LAB_004153fd:
    piVar6 = piVar6 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x415510 FUN_00415510

void FUN_00415510(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if ((((unaff_ESI == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
      (iVar1 = FUN_004ffb70(), iVar1 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(unaff_EDI);
    FUN_004f75b0();
    return;
  }
  FUN_004f75b0();
  return;
}


// ==== 0x415550 Screen_PC_Customize_Graphics::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_Customize_Graphics__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006874f3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x2b8);
  uStack_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_Customize_Graphics__Screen_PC_Customize_Graphics(pvVar1,param_1);
    ExceptionList = pvStack_c;
    return uVar2;
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== 0x415551 FUN_00415551

void FUN_00415551(void)

{
  int in_EAX;
  
                    /* WARNING: Could not recover jumptable at 0x00415551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EAX + -0xd))();
  return;
}


// ==== 0x4155b0 Screen_PC_Customize_Graphics::Screen_PC_Customize_Graphics

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

int Screen_PC_Customize_Graphics__Screen_PC_Customize_Graphics
              (undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006874ca;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  piVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006cbcfc;
  puVar7 = param_1 + 0x1c;
  param_1[0x11] = &DAT_006b9172;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *piVar1 = (int)&PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar7 = puVar7;
  param_1[0x1d] = puVar7;
  param_1[0x1e] = 0;
  piVar2 = param_1 + 0x1f;
  puVar7 = param_1 + 0x2b;
  param_1[0x20] = &DAT_006b9172;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  *piVar2 = (int)&PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar7 = puVar7;
  param_1[0x2c] = puVar7;
  param_1[0x2d] = 0;
  piVar6 = param_1 + 0x2e;
  puVar7 = param_1 + 0x3a;
  param_1[0x2f] = &DAT_006b9172;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  *piVar6 = (int)&PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  *puVar7 = puVar7;
  param_1[0x3b] = puVar7;
  param_1[0x3c] = 0;
  param_1[0x3e] = &DAT_006b9172;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x3d] = &PTR_ListSlider__scalar_deleting_destructor_006cbe88;
  puVar7 = param_1 + 0x49;
  *puVar7 = puVar7;
  param_1[0x4a] = puVar7;
  param_1[0x4b] = 0;
  local_18 = (float)DAT_00701040;
  _DAT_00777cc0 = 4;
  local_30 = (char *)param_1[3];
  local_4 = 4;
  local_2c = "CarenvmapSliderBase_1";
  local_24 = "CarenvmapSliderBase";
  local_28 = "CarenvmapSlider_1_";
  local_20 = 4.2039e-45;
  local_10 = 0x3f800000;
  local_14 = 0;
  local_1c = 0.0;
  (**(code **)(*piVar1 + 0x14))(&local_30);
  local_1c = (float)DAT_0070105c;
  local_30 = "reflect_freq_SliderBase_1";
  local_28 = "reflect_freq_SliderBase";
  local_2c = "reflect_freq_Slider_1_";
  local_24 = (char *)0x2;
  local_14 = 0x3f800000;
  local_18 = 0.0;
  local_20 = 0.0;
  (**(code **)(*piVar2 + 0x14))(&stack0xffffffcc);
  local_20 = (float)DAT_0070107c;
  local_2c = "WorldGeometrySliderBase";
  local_30 = "WorldGeometrySlider_1_";
  local_28 = (char *)0x3;
  local_18 = 1.0;
  local_1c = 0.0;
  local_24 = (char *)0x0;
  (**(code **)(*piVar6 + 0x14))(&stack0xffffffc8);
  local_24 = (char *)(float)DAT_00701048;
  local_30 = "car_shadow_SliderBase";
  local_2c = (void *)0x3;
  local_1c = 1.0;
  local_20 = 0.0;
  local_28 = (char *)0x0;
  (**(code **)(*(int *)(pcStack_8 + 0xf4) + 0x14))(&stack0xffffffc4);
  (**(code **)(*piVar1 + 0xc))(1);
  (**(code **)(*piVar2 + 0xc))(1);
  (**(code **)(*piVar6 + 0xc))(1);
  (**(code **)(*(int *)((int)local_18 + 0xf4) + 0xc))(1);
  (**(code **)(*piVar1 + 0x10))();
  (**(code **)(*piVar2 + 0x10))();
  (**(code **)(*piVar6 + 0x10))();
  (**(code **)(*(int *)((int)local_1c + 0xf4) + 0x10))();
  fVar4 = local_1c;
  puVar7 = (undefined4 *)((int)local_1c + 0x130);
  for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
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
  *(int *)((int)fVar4 + 0x2b0) = iVar5;
  *(undefined1 *)((int)fVar4 + 0x2b4) = 0;
  ExceptionList = local_2c;
  return (int)fVar4;
}


// ==== 0x415910 FUN_00415910

void * __thiscall FUN_00415910(void *param_1,byte param_2)

{
  FUN_00415930();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x415930 FUN_00415930

void FUN_00415930(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006cbcfc;
  RenderOptions_ClampToLimits();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  ListSlider___ListSlider();
  FUN_004f7b50();
  return;
}


// ==== 0x415970 FUN_00415970

void __thiscall FUN_00415970(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 < 0x9120409f) {
    if ((param_2 != 0x9120409e) && (param_2 != 0xc407210)) {
      if (param_2 == 0x361759de) {
        FUN_004160b0();
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      Screen_PC_Customize_Graphics__ApplyOptionsToGlobals();
      FUN_004f6430(*(undefined4 *)(param_1 + 0xc));
      iVar2 = FUN_004f65d0();
      if (iVar2 == 0) {
        return;
      }
      iVar2 = FUN_004f65d0();
      if (iVar2 == 0) {
        return;
      }
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004164d0();
    FUN_00415c60();
    return;
  }
  uVar1 = *(uint *)(param_3 + 0x10);
  if (uVar1 < 0xdf815d73) {
    if (uVar1 == 0xdf815d72) {
      Screen_PC_Customize_Graphics__AdjustSlider3();
      return;
    }
    if (uVar1 == 0x72e05b95) {
      Screen_PC_Customize_Graphics__AdjustSlider0();
      return;
    }
    if (uVar1 == 0x76c8daca) {
      Screen_PC_Customize_Graphics__AdjustSlider2();
      return;
    }
  }
  else if (uVar1 == 0xff2e6b0d) {
    Screen_PC_Customize_Graphics__AdjustSlider1();
    return;
  }
  if (param_2 == 0x9120409e) {
    Screen_PC_Customize_Graphics__ToggleOption(1);
    FUN_004169b0();
    return;
  }
  if (param_2 != 0xb5971bf1) {
    return;
  }
  Screen_PC_Customize_Graphics__ToggleOption(0);
  FUN_004169b0();
  return;
}


// ==== 0x415aa0 Screen_PC_Customize_Graphics::AdjustSlider3

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_PC_Customize_Graphics__AdjustSlider3(int param_1)

{
  float fVar1;
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    fVar1 = *(float *)(param_1 + 0x110) - *(float *)(param_1 + 0x118);
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_00415b06;
    fVar1 = *(float *)(param_1 + 0x118) + *(float *)(param_1 + 0x110);
  }
  *(float *)(param_1 + 0x110) = fVar1;
  if (*(float *)(param_1 + 0x108) < fVar1) {
    *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0x108);
  }
  if (*(float *)(param_1 + 0x110) < *(float *)(param_1 + 0x10c)) {
    *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0x10c);
  }
LAB_00415b06:
                    /* WARNING: Could not recover jumptable at 0x00415b12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0xf4) + 0x10))();
  return;
}


// ==== 0x415b20 Screen_PC_Customize_Graphics::AdjustSlider2

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_PC_Customize_Graphics__AdjustSlider2(int param_1)

{
  float fVar1;
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    fVar1 = *(float *)(param_1 + 0xd4) - *(float *)(param_1 + 0xdc);
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_00415b86;
    fVar1 = *(float *)(param_1 + 0xdc) + *(float *)(param_1 + 0xd4);
  }
  *(float *)(param_1 + 0xd4) = fVar1;
  if (*(float *)(param_1 + 0xcc) < fVar1) {
    *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xcc);
  }
  if (*(float *)(param_1 + 0xd4) < *(float *)(param_1 + 0xd0)) {
    *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xd0);
  }
LAB_00415b86:
                    /* WARNING: Could not recover jumptable at 0x00415b92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0xb8) + 0x10))();
  return;
}


// ==== 0x415ba0 Screen_PC_Customize_Graphics::AdjustSlider0

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_PC_Customize_Graphics__AdjustSlider0(int param_1)

{
  float fVar1;
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    fVar1 = *(float *)(param_1 + 0x5c) - *(float *)(param_1 + 100);
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_00415be2;
    fVar1 = *(float *)(param_1 + 100) + *(float *)(param_1 + 0x5c);
  }
  *(float *)(param_1 + 0x5c) = fVar1;
  if (*(float *)(param_1 + 0x54) < fVar1) {
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x54);
  }
  if (*(float *)(param_1 + 0x5c) < *(float *)(param_1 + 0x58)) {
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x58);
  }
LAB_00415be2:
                    /* WARNING: Could not recover jumptable at 0x00415be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x40) + 0x10))();
  return;
}


// ==== 0x415bf0 Screen_PC_Customize_Graphics::AdjustSlider1

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_PC_Customize_Graphics__AdjustSlider1(int param_1)

{
  float fVar1;
  int in_EAX;
  
  if (in_EAX == -0x6edfbf62) {
    fVar1 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xa0);
  }
  else {
    if (in_EAX != -0x4a68e40f) goto LAB_00415c56;
    fVar1 = *(float *)(param_1 + 0xa0) + *(float *)(param_1 + 0x98);
  }
  *(float *)(param_1 + 0x98) = fVar1;
  if (*(float *)(param_1 + 0x90) < fVar1) {
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x90);
  }
  if (*(float *)(param_1 + 0x98) < *(float *)(param_1 + 0x94)) {
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x94);
  }
LAB_00415c56:
                    /* WARNING: Could not recover jumptable at 0x00415c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x7c) + 0x10))();
  return;
}


// ==== 0x415c60 FUN_00415c60

void FUN_00415c60(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = 0;
  do {
    if (((*(int *)(unaff_EBX + 0x130 + iVar5 * 4) != 0) && (DAT_007064b2 != '\0')) &&
       (cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
       cVar2 != '\0')) {
      uVar1 = *(uint *)(*(int *)(unaff_EBX + 0x130 + iVar5 * 4) + 0x10);
      if (uVar1 < 0x9f6badfe) {
        if (uVar1 == 0x9f6badfd) {
          if (DAT_00701058 != 0) {
            uVar4 = *(undefined4 *)(unaff_EBX + 0x2b0);
            uVar6 = FUN_004f6670();
            if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
              FUN_004f0700(0xb5971bf1,*(undefined4 *)(unaff_EBX + 0x130 + iVar5 * 4),uVar4,uVar6,0);
            }
          }
        }
        else {
          if (0x4eac79b9 < uVar1) {
            if (uVar1 < 0x7dba07dc) {
              iVar3 = DAT_0070106c;
              if ((uVar1 == 0x7dba07db) ||
                 ((iVar3 = DAT_00701060, uVar1 == 0x71fd7547 ||
                  (iVar3 = DAT_00701070, uVar1 == 0x73eda200)))) goto LAB_00415f2a;
              iVar3 = DAT_0070104c;
              if (uVar1 != 0x73fc2fe5) goto LAB_00415f78;
            }
            else {
              iVar3 = DAT_00701044;
              if (uVar1 != 0x8b088614) {
                iVar3 = DAT_00701074;
                if ((uVar1 != 0x8d8ae227) && (iVar3 = DAT_00701048, uVar1 != 0x8fe84e38))
                goto LAB_00415f78;
                goto LAB_00415f2a;
              }
            }
            goto LAB_00415f4a;
          }
          iVar3 = DAT_0070107c;
          if (uVar1 == 0x4eac79b9) goto LAB_00415f4a;
          if (uVar1 < 0x25cd4d64) {
            iVar3 = DAT_0070105c;
            if ((((uVar1 == 0x25cd4d63) || (iVar3 = DAT_00701074, uVar1 == 0x3ffe4e1)) ||
                (iVar3 = DAT_00701058, uVar1 == 0x15e0b0b7)) ||
               (iVar3 = DAT_00701064, uVar1 == 0x1a471f70)) goto LAB_00415f4a;
          }
          else {
            iVar3 = DAT_00701080;
            if ((uVar1 == 0x2df9a3cd) || (iVar3 = DAT_00701068, uVar1 == 0x3820a0d1))
            goto LAB_00415f2a;
            iVar3 = DAT_00701040;
            if (uVar1 == 0x4b853ca2) goto LAB_00415f4a;
          }
        }
      }
      else if (uVar1 < 0xbb833bd2) {
        iVar3 = DAT_0070107c;
        if (uVar1 != 0xbb833bd1) {
          if (uVar1 < 0xae95a38c) {
            iVar3 = DAT_00701068;
            if (uVar1 == 0xae95a38b) goto LAB_00415f4a;
            iVar3 = DAT_00701064;
            if (uVar1 != 0xa3d21cb6) {
              iVar3 = DAT_00701080;
              if (uVar1 == 0xa46ea687) goto LAB_00415f4a;
              iVar3 = DAT_00701044;
              if (uVar1 != 0xa611a8cc) goto LAB_00415f78;
            }
          }
          else {
            iVar3 = DAT_0070105c;
            if (uVar1 != 0xaf584aa9) {
              iVar3 = DAT_00701048;
              if (uVar1 == 0xafb3d900) goto LAB_00415f4a;
              iVar3 = DAT_00701040;
              if (uVar1 != 0xbb6ac59a) goto LAB_00415f78;
            }
          }
        }
LAB_00415f2a:
        if (iVar3 != 0) {
          uVar4 = FUN_004f6670();
          uVar6 = 0xb5971bf1;
          goto LAB_00415f63;
        }
      }
      else {
        if (uVar1 < 0xf08e374f) {
          iVar3 = DAT_0070105c;
          if (uVar1 == 0xf08e374e) goto LAB_00415f2a;
          if (((uVar1 != 0xe1fdd3f7) && (iVar3 = DAT_00701060, uVar1 != 0xe8727801)) &&
             (iVar3 = DAT_00701070, uVar1 != 0xea62a4ba)) goto LAB_00415f78;
        }
        else {
          iVar3 = DAT_0070106c;
          if (uVar1 != 0xf42f0a95) {
            iVar3 = DAT_0070104c;
            if (uVar1 != 0xfd872d2b) goto LAB_00415f78;
            goto LAB_00415f2a;
          }
        }
LAB_00415f4a:
        if (iVar3 != 0) {
          uVar4 = FUN_004f6670();
          uVar6 = 0x9120409e;
LAB_00415f63:
          FUN_004f6540(uVar6,uVar4);
        }
      }
    }
LAB_00415f78:
    iVar5 = iVar5 + 1;
    if (0x1f < iVar5) {
      return;
    }
  } while( true );
}


// ==== 0x415f90 FUN_00415f90

void FUN_00415f90(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  
  if ((-1 < param_4) && (param_4 < 0x20)) {
    if (in_EAX < param_3) {
      param_3 = in_EAX;
    }
    if (in_EAX == 0) {
      if (DAT_0073578c != 0) {
        FUN_004f5f80(DAT_0073578c,0);
      }
      uVar1 = FUN_004f65d0();
      uVar2 = FUN_004f6670();
      uVar3 = FUN_004f6670();
      if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
        FUN_004f0700(0x317ecc0e,uVar3,uVar1,uVar2,0);
      }
    }
    else if (*(char *)(unaff_EBX + 0x2b4) == '\0') {
      if (DAT_0073578c != 0) {
        FUN_004f5ed0(DAT_0073578c);
      }
      *(undefined1 *)(unaff_EBX + 0x2b4) = 1;
    }
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
      if (DAT_0073578c == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(param_1);
      }
    }
    *(int *)(unaff_EBX + 0x130 + param_4 * 4) = iVar4;
    *(undefined4 *)(unaff_EBX + 0x1b0 + param_4 * 4) = param_2;
    *(int *)(unaff_EBX + 0x230 + param_4 * 4) = param_3;
  }
  return;
}


// ==== 0x4160b0 FUN_004160b0

void FUN_004160b0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x2b4) = 0;
  FUN_00415f90(0xbb6ac59a,0x72e05b95,DAT_00700e74,0);
  FUN_00415f90(0x4b853ca2,0x72e05b95,DAT_00700e74,1);
  FUN_00415f90(0xa611a8cc,0x40f25307,DAT_00700e78,2);
  FUN_00415f90(0x8b088614,0x40f25307,DAT_00700e78,3);
  FUN_00415f90(0x8fe84e38,0xdf815d72,DAT_00700e7c,4);
  FUN_00415f90(0xafb3d900,0xdf815d72,DAT_00700e7c,5);
  FUN_00415f90(0xfd872d2b,0x9e8ca9d6,DAT_00700e80,6);
  FUN_00415f90(0x73fc2fe5,0x9e8ca9d6,DAT_00700e80,7);
  FUN_00415f90(0xa46ea687,0x1f86c18,DAT_00700eb4,0x18);
  FUN_00415f90(0x2df9a3cd,0x1f86c18,DAT_00700eb4,0x19);
  FUN_00415f90(0x4eac79b9,0x76c8daca,DAT_00700eb0,0x1a);
  FUN_00415f90(0xbb833bd1,0x76c8daca,DAT_00700eb0,0x1b);
  FUN_00415f90(0x9f6badfd,0x99278529,DAT_00700e8c,8);
  FUN_00415f90(0x15e0b0b7,0x99278529,DAT_00700e8c,9);
  FUN_00415f90(0xf08e374e,0xff2e6b0d,DAT_00700e90,10);
  FUN_00415f90(0xe1fdd3f7,0xff2e6b0d,DAT_00700e90,0xb);
  FUN_00415f90(0x3820a0d1,0x8c99b2fd,DAT_00700e9c,0xc);
  FUN_00415f90(0xae95a38b,0x8c99b2fd,DAT_00700e9c,0xd);
  FUN_00415f90(0x7dba07db,0x9b9cf87,DAT_00700ea0,0xe);
  FUN_00415f90(0xf42f0a95,0x9b9cf87,DAT_00700ea0,0xf);
  FUN_00415f90(0x71fd7547,0x5d2af1f3,DAT_00700e94,0x10);
  FUN_00415f90(0xe8727801,0x5d2af1f3,DAT_00700e94,0x11);
  FUN_00415f90(0x73eda200,0xd9869c6c,DAT_00700ea4,0x12);
  FUN_00415f90(0xea62a4ba,0xd9869c6c,DAT_00700ea4,0x13);
  FUN_00415f90(0x8d8ae227,0x8df2a852,DAT_00700ea8,0x14);
  FUN_00415f90(0x3ffe4e1,0x8df2a852,DAT_00700ea8,0x15);
  FUN_00415f90(0xa3d21cb6,0xae5c3f41,DAT_00700e98,0x16);
  FUN_00415f90(0x1a471f70,0xae5c3f41,DAT_00700e98,0x17);
  *(float *)(in_EAX + 0x5c) = (float)*(int *)(in_EAX + 0x230);
  if (*(float *)(in_EAX + 0x54) < (float)*(int *)(in_EAX + 0x230)) {
    *(undefined4 *)(in_EAX + 0x5c) = *(undefined4 *)(in_EAX + 0x54);
  }
  if (*(float *)(in_EAX + 0x5c) < *(float *)(in_EAX + 0x58)) {
    *(undefined4 *)(in_EAX + 0x5c) = *(undefined4 *)(in_EAX + 0x58);
  }
  *(float *)(in_EAX + 0x98) = (float)*(int *)(in_EAX + 600);
  if (*(float *)(in_EAX + 0x90) < (float)*(int *)(in_EAX + 600)) {
    *(undefined4 *)(in_EAX + 0x98) = *(undefined4 *)(in_EAX + 0x90);
  }
  if (*(float *)(in_EAX + 0x98) < *(float *)(in_EAX + 0x94)) {
    *(undefined4 *)(in_EAX + 0x98) = *(undefined4 *)(in_EAX + 0x94);
  }
  *(float *)(in_EAX + 0xd4) = (float)*(int *)(in_EAX + 0x298);
  if (*(float *)(in_EAX + 0xcc) < (float)*(int *)(in_EAX + 0x298)) {
    *(undefined4 *)(in_EAX + 0xd4) = *(undefined4 *)(in_EAX + 0xcc);
  }
  if (*(float *)(in_EAX + 0xd4) < *(float *)(in_EAX + 0xd0)) {
    *(undefined4 *)(in_EAX + 0xd4) = *(undefined4 *)(in_EAX + 0xd0);
  }
  *(float *)(in_EAX + 0x110) = (float)*(int *)(in_EAX + 0x240);
  if (*(float *)(in_EAX + 0x108) < (float)*(int *)(in_EAX + 0x240)) {
    *(undefined4 *)(in_EAX + 0x110) = *(undefined4 *)(in_EAX + 0x108);
  }
  if (*(float *)(in_EAX + 0x110) < *(float *)(in_EAX + 0x10c)) {
    *(undefined4 *)(in_EAX + 0x110) = *(undefined4 *)(in_EAX + 0x10c);
  }
  (**(code **)(*(int *)(in_EAX + 0x40) + 0x10))();
  (**(code **)(*(int *)(in_EAX + 0x7c) + 0x10))();
  (**(code **)(*(int *)(in_EAX + 0xf4) + 0x10))();
  (**(code **)(*(int *)(in_EAX + 0xb8) + 0x10))();
  FUN_004169b0();
  FUN_004164d0();
  return;
}


// ==== 0x4164d0 FUN_004164d0

void FUN_004164d0(void)

{
  uint uVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = 0;
  iVar4 = DAT_0073578c;
  do {
    uVar1 = *(uint *)(unaff_EBX + 0x1b0 + iVar3 * 4);
    if (uVar1 < 0x8df2a853) {
      if (uVar1 == 0x8df2a852) {
        if (DAT_00701074 == 0) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
            iVar4 = DAT_0073578c;
          }
          if ((((*(int *)(unaff_EBX + 0xc) == 0) ||
               (iVar2 = FUN_004f65d0(), iVar4 = DAT_0073578c, iVar2 == 0)) ||
              (iVar2 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar2 == 0)) && (iVar4 != 0)) {
            uVar5 = 0x8d118bb;
            goto LAB_0041680b;
          }
          goto LAB_004168cc;
        }
      }
      else if (uVar1 < 0x71ad06d6) {
        if (uVar1 == 0x71ad06d5) {
joined_r0x00416839:
          if (DAT_0070105c == 0) {
            if (iVar4 != 0) {
              FUN_004f5f80(iVar4,0);
            }
            goto LAB_00416858;
          }
        }
        else if (uVar1 == 0x9b9cf87) {
          if (DAT_0070106c == 0) {
            if (iVar4 != 0) {
              FUN_004f5f80(iVar4,0);
            }
            goto LAB_00416858;
          }
        }
        else if (uVar1 == 0x40f25307) {
          if (DAT_00701044 == 0) {
            if (iVar4 != 0) {
              FUN_004f5f80(iVar4,0);
            }
            goto LAB_00416858;
          }
        }
        else if ((uVar1 == 0x5d2af1f3) && (DAT_00701060 == 0)) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
          }
LAB_00416858:
          FUN_00415510(0xff404040);
          iVar4 = DAT_0073578c;
        }
      }
      else if (uVar1 == 0x72e05b95) {
        if (DAT_00701040 == 0) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
          }
          FUN_00415510(0xff404040);
          iVar4 = DAT_0073578c;
        }
      }
      else if ((uVar1 == 0x8c99b2fd) && (DAT_00701068 == 0)) {
        if (iVar4 != 0) {
          FUN_004f5f80(iVar4,0);
        }
        FUN_00415510(0xff404040);
        iVar4 = DAT_0073578c;
      }
    }
    else if (uVar1 < 0xd9869c6d) {
      if (uVar1 == 0xd9869c6c) {
        if (DAT_00701070 == 0) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
            iVar4 = DAT_0073578c;
          }
          if ((((*(int *)(unaff_EBX + 0xc) == 0) ||
               (iVar2 = FUN_004f65d0(), iVar4 = DAT_0073578c, iVar2 == 0)) ||
              (iVar2 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar2 == 0)) && (iVar4 != 0)) {
            uVar5 = 0x178ff475;
LAB_0041680b:
            FUN_004ef050(uVar5);
            iVar4 = DAT_0073578c;
          }
LAB_004168cc:
          FUN_004f75b0(0xff404040);
        }
      }
      else if (uVar1 == 0x99278529) {
        if (DAT_00701058 == 0) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
          }
          FUN_00415510(0xff404040);
          iVar4 = DAT_0073578c;
        }
      }
      else if (uVar1 == 0x9e8ca9d6) {
        if (DAT_0070104c == 0) {
          if (iVar4 != 0) {
            FUN_004f5f80(iVar4,0);
          }
          FUN_00415510(0xff404040);
          iVar4 = DAT_0073578c;
        }
      }
      else if ((uVar1 == 0xae5c3f41) && (DAT_00701064 == 0)) {
        if (iVar4 != 0) {
          FUN_004f5f80(iVar4,0);
        }
        FUN_00415510(0xff404040);
        iVar4 = DAT_0073578c;
      }
    }
    else if (uVar1 == 0xdf815d72) {
      if (DAT_00701048 == 0) {
        if (iVar4 != 0) {
          FUN_004f5f80(iVar4,0);
          iVar4 = DAT_0073578c;
        }
        if ((((*(int *)(unaff_EBX + 0xc) == 0) ||
             (iVar2 = FUN_004f65d0(), iVar4 = DAT_0073578c, iVar2 == 0)) ||
            (iVar2 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar2 == 0)) && (iVar4 != 0)) {
          uVar5 = 0xe43d65fb;
          goto LAB_0041680b;
        }
        goto LAB_004168cc;
      }
    }
    else if (uVar1 == 0xff2e6b0d) goto joined_r0x00416839;
    iVar3 = iVar3 + 2;
    if (0x1f < iVar3) {
      return;
    }
  } while( true );
}


// ==== 0x4168f0 FUN_004168f0

void FUN_004168f0(void)

{
  int in_EAX;
  
  bSPrintf_regdst(0x20,"on_option_%02d",in_EAX + 1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"off_option_%02d",in_EAX + 1);
  FUN_00414a10();
  return;
}


// ==== 0x416950 FUN_00416950

void FUN_00416950(void)

{
  int in_EAX;
  
  bSPrintf_regdst(0x20,"on_option_%02d",in_EAX + 1);
  FUN_00414a10();
  bSPrintf_regdst(0x20,"off_option_%02d",in_EAX + 1);
  FUN_00414a60();
  return;
}


// ==== 0x4169b0 FUN_004169b0

void FUN_004169b0(void)

{
  uint uVar1;
  int unaff_EBX;
  uint uVar2;
  int *piVar3;
  bool bVar4;
  
  uVar2 = 0;
  piVar3 = (int *)(unaff_EBX + 0x22c);
  do {
    uVar1 = uVar2 & 0x80000001;
    bVar4 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar4 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar4) {
      if (piVar3[1] == 0) {
        FUN_00416950(unaff_EBX);
      }
      else {
LAB_004169f7:
        FUN_004168f0(unaff_EBX);
      }
    }
    else {
      if (*piVar3 != 0) goto LAB_004169f7;
      FUN_00416950(unaff_EBX);
    }
    uVar2 = uVar2 + 1;
    piVar3 = piVar3 + 1;
    if (0x1f < (int)uVar2) {
      return;
    }
  } while( true );
}


// ==== 0x416a10 Screen_PC_Customize_Graphics::ToggleOption

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_PC_Customize_Graphics__ToggleOption(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  iVar2 = 0;
  piVar3 = (int *)(param_2 + 0x1b0);
  do {
    if (*piVar3 == unaff_ESI) {
      puVar1 = (uint *)(param_2 + 0x230 + iVar2 * 4);
      *puVar1 = *puVar1 ^ 1;
      return;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 0x20);
  return;
}


// ==== 0x416a40 Screen_PC_Customize_Graphics::ApplyOptionsToGlobals

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Screen_PC_Customize_Graphics__ApplyOptionsToGlobals(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar3 = (undefined4 *)(unaff_EDI + 0x230);
  iVar2 = 0x10;
  do {
    uVar1 = puVar3[-0x20];
    if (uVar1 < 0x8c99b2fe) {
      if (uVar1 == 0x8c99b2fd) {
        DAT_00700e9c = *puVar3;
      }
      else if (uVar1 < 0x5d2af1f4) {
        if (uVar1 == 0x5d2af1f3) {
          DAT_00700e94 = *puVar3;
        }
        else if (uVar1 == 0x1f86c18) {
          DAT_00700eb4 = *puVar3;
        }
        else if (uVar1 == 0x9b9cf87) {
          DAT_00700ea0 = *puVar3;
        }
        else if (uVar1 == 0x40f25307) {
          DAT_00700e78 = *puVar3;
        }
      }
      else if (uVar1 == 0x71ad06d5) {
        DAT_00700e90 = *puVar3;
      }
      else if (uVar1 == 0x72e05b95) {
        DAT_00700e74 = _ftol_nocw();
      }
      else if (uVar1 == 0x76c8daca) {
        DAT_00700eb0 = _ftol_nocw();
      }
    }
    else if (uVar1 < 0xae5c3f42) {
      if (uVar1 == 0xae5c3f41) {
        DAT_00700e98 = *puVar3;
      }
      else if (uVar1 == 0x8df2a852) {
        DAT_00700ea8 = *puVar3;
      }
      else if (uVar1 == 0x99278529) {
        DAT_00700e8c = *puVar3;
      }
      else if (uVar1 == 0x9e8ca9d6) {
        DAT_00700e80 = *puVar3;
      }
    }
    else if (uVar1 == 0xd9869c6c) {
      DAT_00700ea4 = *puVar3;
    }
    else if (uVar1 == 0xdf815d72) {
      DAT_00700e7c = _ftol_nocw();
    }
    else if (uVar1 == 0xff2e6b0d) {
      DAT_00700e90 = _ftol_nocw();
    }
    puVar3 = puVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x416bb0 FUN_00416bb0

void FUN_00416bb0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = FEng__HashName();
  if (((in_EAX == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar3 = FUN_004ef050(uVar2);
  }
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) == 2)) {
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar3 + 0x5c) = param_1;
    if (bVar4) {
      (**(code **)*puVar1)(iVar3);
    }
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x416c30 FUN_00416c30

void FUN_00416c30(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006cbcc0;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x1e,0xc,0x20,WString_Free);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x416c90 FUN_00416c90

void * __thiscall FUN_00416c90(void *param_1,byte param_2)

{
  FUN_00416c30(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x416cb0 Screen_PC_LoadSave::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PC_LoadSave__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688713;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x270);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PC_LoadSave__Screen_PC_LoadSave(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x416d10 Screen_PC_LoadSave::Screen_PC_LoadSave

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PC_LoadSave__Screen_PC_LoadSave(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006886f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  iVar1 = 0;
  local_4 = 0;
  *param_1 = &PTR_FUN_006cbcc0;
  FEMenuData__FEMenuData();
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  _DAT_00777cc0 = 4;
  if (DAT_00777b50 == 1) {
    uVar2 = 0x40e8a107;
  }
  else {
    uVar2 = 0xaa3f09d8;
  }
  FUN_00416bb0(uVar2);
  _DAT_0071b868 = FUN_004f66b0();
  _DAT_0071b86c = FUN_004f66b0();
  _DAT_0071b870 = FUN_004f66b0();
  _DAT_0071b874 = FUN_004f66b0();
  _DAT_0071b878 = FUN_004f66b0();
  _DAT_0071b87c = FUN_004f66b0();
  _DAT_0071b880 = FUN_004f66b0();
  _DAT_0071b884 = FUN_004f66b0();
  _DAT_0071b848 = FUN_004f66b0();
  _DAT_0071b84c = FUN_004f66b0();
  _DAT_0071b850 = FUN_004f66b0();
  _DAT_0071b854 = FUN_004f66b0();
  _DAT_0071b858 = FUN_004f66b0();
  _DAT_0071b85c = FUN_004f66b0();
  _DAT_0071b860 = FUN_004f66b0();
  _DAT_0071b864 = FUN_004f66b0();
  do {
    FUN_00416fc0(param_1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x416ee0 Screen_PC_LoadSave::MaskButtonFlags

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

uint __thiscall Screen_PC_LoadSave__MaskButtonFlags(int param_1,uint param_2)

{
  if (*(char *)(param_1 + 0x204) != '\0') {
    param_2 = param_2 & 0xffffffef;
  }
  return param_2;
}


// ==== 0x416f00 FUN_00416f00

void FUN_00416f00(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    if (unaff_EDI == 0) {
      unaff_EDI = FUN_004e6660();
    }
    if (unaff_EDI != 0) {
      FUN_004f8000(unaff_EDI);
      FUN_004e6ac0();
    }
  }
  return;
}


// ==== 0x416f40 FUN_00416f40

void FUN_00416f40(void)

{
  int iVar1;
  int unaff_EDI;
  
  FUN_0041f160(*(undefined4 *)(*(int *)(&DAT_0071b868 + *(int *)(unaff_EDI + 0x54) * 4) + 0x10),0,0,
               0x12);
  *(undefined4 *)(unaff_EDI + 600) = 0xd03dd189;
  *(undefined4 *)(unaff_EDI + 0x260) = 0;
  *(undefined4 *)(unaff_EDI + 0x25c) = 0x34e93258;
  DAT_0070108e = 1;
  FUN_0041f4d0();
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_004f8000(unaff_EDI);
    FUN_004e6ac0();
  }
  *(undefined4 *)(unaff_EDI + 0x5c) = 1;
  return;
}


// ==== 0x416fc0 FUN_00416fc0

void FUN_00416fc0(void)

{
  char cVar1;
  char *pcVar2;
  char local_30 [20];
  char local_1c [28];
  
  Ugd__ReadHeader(local_1c);
  pcVar2 = local_1c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((int)pcVar2 - (int)(local_1c + 1) == 0) {
    builtin_strncpy(local_1c + 8,"----",5);
    builtin_strncpy(local_30 + 8,"----",5);
    builtin_strncpy(local_1c,"--------",8);
    builtin_strncpy(local_30,"--------",8);
  }
  FEObject__SetFormattedText(&DAT_006cc568,local_30,(int)pcVar2 - (int)(local_1c + 1));
  FUN_004f6720(local_1c);
  return;
}


// ==== 0x417060 FUN_00417060

void FUN_00417060(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = Ugd__Write(&DAT_0078a478,unaff_ESI + 0x20c);
  if (iVar1 != 0) {
    Ugd__Write(&DAT_0078a478,"auto");
    FUN_00416fc0(unaff_ESI);
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x59) = 1;
  return;
}


// ==== 0x4170a0 FUN_004170a0

void FUN_004170a0(int param_1)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  local_14 = 0;
  local_24 = 0xa959b6be;
  local_1c = 0x7e9d91db;
  local_20 = 0x39df715;
  local_18 = 0x541389e5;
  local_10 = 1;
  local_c = 0xb8a7c6cc;
  FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x417100 FUN_00417100

void FUN_00417100(int param_1)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  local_14 = 0;
  local_24 = 0xc1ed97cf;
  local_1c = 0x7e99f40c;
  local_20 = 0x39df715;
  local_18 = 0x541389e5;
  local_10 = 1;
  local_c = 0xb8a7c6cc;
  FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x417160 FUN_00417160

void FUN_00417160(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = Ugd__Read(&DAT_0078a478);
  if (iVar1 != 0) {
    Ugd__Write(&DAT_0078a478,"auto");
    FUN_00416fc0(unaff_ESI);
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x58) = 1;
  FUN_00416fc0(unaff_ESI);
  return;
}


// ==== 0x4171a0 FUN_004171a0

void FUN_004171a0(void)

{
  char cVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  cVar1 = SaveSlot__Exists();
  if (cVar1 != '\0') {
    local_8 = 0;
    local_4 = 0;
    local_14 = 0;
    *(undefined4 *)(unaff_ESI + 0x54) = unaff_EDI;
    local_24 = 0xd36620fe;
    local_1c = 0x7e99f40c;
    local_20 = 0x639;
    local_18 = 0x541389e5;
    local_10 = 1;
    local_c = 0xb8a7c6cd;
    FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(unaff_ESI + 0xc));
  }
  return;
}


// ==== 0x417210 FUN_00417210

void __fastcall FUN_00417210(undefined4 param_1)

{
  char cVar1;
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
  
  *(undefined4 *)(in_EAX + 0x54) = param_1;
  cVar1 = SaveSlot__Exists();
  if (cVar1 != '\0') {
    local_8 = 0;
    local_4 = 0;
    local_24 = 0x4e20c880;
    local_1c = 0x7e9d91db;
    local_20 = 0x639;
    local_14 = 0x1234ccc0;
    local_18 = 0x541389e5;
    local_10 = 1;
    local_c = 0xb8a7c6cd;
    FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(in_EAX + 0xc));
    return;
  }
  FUN_00416f40();
  return;
}


// ==== 0x417290 FUN_00417290

void __thiscall
FUN_00417290(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar1 != '\0') {
    return;
  }
  if (param_2 < 0x7e9d91dc) {
    if (param_2 == 0x7e9d91db) {
      *(undefined4 *)(param_1 + 100) = 1;
      return;
    }
    if (param_2 == 0xc407210) {
      switch(*(undefined4 *)(param_3 + 0x10)) {
      case 0xa6bada8e:
        break;
      case 0xa6bada8f:
        break;
      case 0xa6bada90:
        break;
      case 0xa6bada91:
        break;
      case 0xa6bada92:
        break;
      case 0xa6bada93:
        break;
      case 0xa6bada94:
        break;
      case 0xa6bada95:
        break;
      default:
        return;
      }
      if (DAT_00777b50 == 1) {
        FUN_00417210();
        return;
      }
      FUN_004171a0();
      return;
    }
    if (param_2 == 0x1234ccc0) {
      iVar2 = FUN_004f65d0();
      if (iVar2 == 0) {
        return;
      }
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      return;
    }
    if (param_2 != 0x7e99f40c) {
      return;
    }
    FUN_00417160();
    return;
  }
  if (param_2 == 0x911ab364) {
    if (DAT_00777b4c == 1) {
      uVar3 = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      if ((DAT_00777b4c != 8) && (DAT_00777b4c != 0x10)) goto LAB_004173f5;
      uVar3 = *(undefined4 *)(param_1 + 0xc);
    }
    FUN_004f6360(uVar3);
  }
  else if (param_2 != 0xc98356ba) {
    if (param_2 != 0xd03dd189) {
      return;
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 1;
    FUN_00417060();
    FUN_00416f00();
    return;
  }
LAB_004173f5:
  if (*(int *)(param_1 + 100) != 0) {
    FUN_00416f40();
    *(undefined4 *)(param_1 + 100) = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
  }
  if ((*(int *)(param_1 + 0x5c) != 0) && (*(char *)(param_1 + 0x204) == '\0')) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    FUN_00416fc0(param_1);
    FUN_00416f00();
  }
  if (*(char *)(param_1 + 0x59) != '\0') {
    *(undefined1 *)(param_1 + 0x59) = 0;
    FUN_004170a0(param_1);
  }
  if (*(char *)(param_1 + 0x58) != '\0') {
    *(undefined1 *)(param_1 + 0x58) = 0;
    FUN_00417100(param_1);
  }
  return;
}


// ==== 0x417373 FUN_00417373

void FUN_00417373(void)

{
  FUN_004171a0();
  return;
}


// ==== 0x417461 default

void switchD_00417321::default(void)

{
  return;
}


// ==== 0x417490 FUN_00417490

undefined4 FUN_00417490(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 4);
}


// ==== 0x4174a0 FUN_004174a0

void FUN_004174a0(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x20) = 1;
  return;
}


// ==== 0x4174b0 StringList::AddEntry

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void StringList__AddEntry(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685583;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar2 = _malloc(0x88);
  local_4 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    bSPrintf_regdst(0x80,param_2);
    piVar3 = piVar2;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *puVar1 = piVar3;
  *(int **)(param_1 + 0xc) = piVar3;
  *piVar3 = param_1 + 8;
  piVar3[1] = (int)puVar1;
  ExceptionList = local_c;
  return;
}


// ==== 0x417530 FUN_00417530

void FUN_00417530(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = _malloc(0xc);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = param_2;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *puVar1 = piVar2;
  *(int **)(param_1 + 0xc) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = param_1 + 8;
  return;
}


// ==== 0x417560 FUN_00417560

void FUN_00417560(void)

{
  FUN_00494890();
  FUN_00494890();
  return;
}


// ==== 0x417580 FUN_00417580

int __fastcall FUN_00417580(int param_1)

{
  if ((*(int *)(param_1 + 8) != param_1 + 8) && (*(int *)(param_1 + 0x10) != 0)) {
    return *(int *)(*(int *)(param_1 + 0x10) + 8) + 8;
  }
  return 0;
}


// ==== 0x4175a0 FUN_004175a0

void __fastcall FUN_004175a0(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + param_2 * 4) = param_1;
  return;
}


// ==== 0x4175b0 FUN_004175b0

void __fastcall FUN_004175b0(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x2c + param_2 * 4) = param_1;
  return;
}


// ==== 0x4175c0 LinearTable::Init

/* [canon] rivals I (capstone) docs/re/rivals.md */

void __thiscall LinearTable__Init(int param_1,int param_2,float param_3,float param_4)

{
  int *in_EAX;
  
  *in_EAX = param_1;
  in_EAX[1] = (int)param_3;
  in_EAX[2] = (int)param_4;
  in_EAX[4] = param_2;
  in_EAX[3] = (int)((float)(param_1 + -1) / (param_4 - param_3));
  return;
}


// ==== 0x417600 RideInfo::Init

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall RideInfo__Init(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  
  iVar1 = 0;
  do {
    *(undefined4 *)(param_2 + 8 + iVar1 * 4) = 0;
    *(undefined4 *)(param_2 + 0x34 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  *(undefined4 *)(param_2 + 0x170) = 0x3dcccccd;
  *(undefined4 *)(param_2 + 0x174) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x178) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x17c) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x1c0) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x410) = 0x40;
  *(undefined4 *)(param_2 + 0x414) = 0;
  *(undefined4 *)(param_2 + 0x418) = 0x425e38e4;
  *(undefined4 *)(param_2 + 0x41c) = 0x3f9126e9;
  *(undefined4 **)(param_2 + 0x420) = (undefined4 *)(param_2 + 0x310);
  puVar2 = (undefined4 *)(param_2 + 0x310);
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0x40800000;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_2 + 0x40c) = 0;
  Ride_Init(0,0,0);
  return extraout_EDX;
}


// ==== 0x4176a0 Screen_MU_UG_NewOrLoad_PC2::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_UG_NewOrLoad_PC2__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006886d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x28c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_UG_NewOrLoad_PC2__Screen_MU_UG_NewOrLoad_PC2(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x417700 Screen_MU_UG_NewOrLoad_PC2::Screen_MU_UG_NewOrLoad_PC2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_UG_NewOrLoad_PC2__Screen_MU_UG_NewOrLoad_PC2(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined4 *puVar4;
  byte bVar5;
  byte *pbVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  byte local_760;
  byte local_75f [31];
  undefined1 local_740 [1092];
  int local_2fc;
  int local_2f8;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006886a7;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FEScreen__FEScreen(param_1,param_2);
  local_14 = 0;
  *param_1 = &PTR_FUN_006cbc18;
  FEMenuData__FEMenuData();
  puVar4 = param_1 + 0x9b;
  puVar1 = param_1 + 0x9d;
  *puVar4 = puVar4;
  param_1[0x9c] = puVar4;
  *puVar1 = puVar1;
  param_1[0x9e] = puVar1;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  local_14 = CONCAT31(local_14._1_3_,2);
  param_1[0x96] = 0;
  *(undefined1 *)(param_1 + 0x97) = 0;
  param_1[0x98] = 0;
  *(undefined1 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x265) = 1;
  FUN_00417e70(param_1);
  FUN_004181e0(param_1);
  *(undefined1 *)(param_1 + 8) = 1;
  FUN_00565da0("DUMMY_SKIN%d",1);
  iVar8 = -1;
  pbVar6 = &local_760;
  bVar5 = local_760;
  while (bVar5 != 0) {
    iVar8 = iVar8 * 0x21 + (uint)bVar5;
    pbVar2 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    bVar5 = *pbVar2;
  }
  FUN_00565da0("DUMMY_WHEEL%d",1);
  iVar9 = -1;
  pbVar6 = &local_760;
  while (local_760 != 0) {
    pbVar2 = pbVar6 + 1;
    iVar9 = iVar9 * 0x21 + (uint)local_760;
    pbVar6 = pbVar6 + 1;
    local_760 = *pbVar2;
  }
  RideInfo__Init();
  Ride_BuildFromPartDatabase();
  pcVar7 = "FE_SKYLINE";
  do {
    pcVar3 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar3 != '\0');
  PresetRide__ApplyToRide(local_740);
  local_2fc = iVar8;
  local_2f8 = iVar9;
  iVar8 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,local_740);
  _DAT_0072cc80 = 1;
  if (iVar8 != 0) {
    GarageMainScreen__SetRideInfo(iVar8,&DAT_00748850,1);
  }
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar8 == 0) || (*(int *)(iVar8 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  if (((param_1[3] == 0) || (iVar8 = FUN_004f65d0(), iVar8 == 0)) ||
     (iVar8 = FUN_004ffb70(), iVar8 == 0)) {
    if (DAT_0073578c == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_004ef050(0xea9e6302);
    }
  }
  param_1[0x10] = iVar8;
  if (((param_1[3] == 0) || (iVar8 = FUN_004f65d0(), iVar8 == 0)) ||
     (iVar8 = FUN_004ffb70(), iVar8 == 0)) {
    if (DAT_0073578c == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_004ef050(0xaa68bfd7);
    }
  }
  param_1[0x11] = iVar8;
  if (((param_1[3] == 0) || (iVar8 = FUN_004f65d0(), iVar8 == 0)) ||
     (iVar8 = FUN_004ffb70(), iVar8 == 0)) {
    if (DAT_0073578c == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_004ef050(0xaa68bfc6);
    }
  }
  param_1[0x12] = iVar8;
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar8 == 0) || (iVar8 = *(int *)(iVar8 + 0x18), iVar8 == 0)) &&
     (iVar8 = 0, DAT_0073578c != 0)) {
    iVar9 = *(int *)(DAT_0073578c + 8);
    if (iVar9 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_004fd1e0(iVar9 + 0xdc);
      if (iVar8 == 0) {
        iVar8 = FUN_004fd1e0(iVar9 + 0xec);
      }
    }
  }
  param_1[0x13] = iVar8;
  FUN_0041f160(0x38fc835a,0x70355aa6,0,0xc);
  param_1[0x90] = 0xd03dd189;
  param_1[0x92] = 0;
  if (param_1[3] == 0) {
LAB_00417aba:
    if (((DAT_0073578c != 0) && (iVar8 = FUN_004ef050(0x38fc835a), iVar8 != 0)) &&
       (*(int *)(iVar8 + 0x18) == 2)) {
      *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x20;
    }
  }
  else {
    iVar8 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) {
LAB_00417a78:
      local_14._0_1_ = 3;
      FUN_004ffb00(iVar8);
      local_14 = CONCAT31(local_14._1_3_,2);
      goto LAB_00417aba;
    }
    if (DAT_0073578c != 0) {
      if ((*(int *)(DAT_0073578c + 8) == 0) ||
         ((iVar8 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xdc), iVar8 == 0 &&
          (iVar8 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xec), iVar8 == 0))))
      goto LAB_00417aba;
      goto LAB_00417a78;
    }
  }
  pcVar7 = "Description";
  iVar8 = -1;
  bVar5 = 0x44;
  do {
    if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
      bVar5 = bVar5 - 0x20;
    }
    iVar8 = iVar8 * 0x21 + (uint)bVar5;
    bVar5 = pcVar7[1];
    pcVar7 = pcVar7 + 1;
  } while (bVar5 != 0);
  if (param_1[3] == 0) {
LAB_00417bb7:
    if (((DAT_0073578c != 0) && (iVar8 = FUN_004ef050(iVar8), iVar8 != 0)) &&
       (*(int *)(iVar8 + 0x18) == 2)) goto LAB_00417bdb;
  }
  else {
    iVar9 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar9 != 0) && (iVar9 = *(int *)(iVar9 + 0x18), iVar9 != 0)) {
LAB_00417b79:
      local_14._0_1_ = 4;
      FUN_004ffb00(iVar9);
      local_14 = CONCAT31(local_14._1_3_,2);
      goto LAB_00417bb7;
    }
    if (DAT_0073578c != 0) {
      if ((*(int *)(DAT_0073578c + 8) == 0) ||
         ((iVar9 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xdc), iVar9 == 0 &&
          (iVar9 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xec), iVar9 == 0))))
      goto LAB_00417bb7;
      goto LAB_00417b79;
    }
  }
  iVar8 = 0;
LAB_00417bdb:
  param_1[0xa2] = iVar8;
  *(undefined1 *)((int)param_1 + 0x266) = 1;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x417c10 FUN_00417c10

void * __thiscall FUN_00417c10(void *param_1,byte param_2)

{
  FUN_00417c30();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x417c30 FUN_00417c30

void __fastcall FUN_00417c30(undefined4 *param_1)

{
  void *_Memory;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00687481;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006cbc18;
  _Memory = (void *)param_1[0x98];
  local_4 = 2;
  if (_Memory != (void *)0x0) {
    if (*(int *)((int)_Memory + 0xc) != 0) {
      FUN_00565ce0();
    }
    _free(_Memory);
  }
  FUN_00494890();
  FUN_00494890();
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator(param_1 + 0x18,0xc,0x20,WString_Free);
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x417cd0 Screen_MU_UG_NewOrLoad_PC2::MaskButtonFlags

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

uint __thiscall Screen_MU_UG_NewOrLoad_PC2__MaskButtonFlags(int param_1,uint param_2)

{
  if (*(char *)(param_1 + 0x265) == '\0') {
    param_2 = param_2 & 0xfffff7ff;
  }
  return param_2;
}


// ==== 0x417cf0 Screen_MU_UG_NewOrLoad_PC2::UpdateMenubarItems

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

int Screen_MU_UG_NewOrLoad_PC2__UpdateMenubarItems(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte local_20;
  byte local_1f [31];
  
  iVar8 = 0;
  if (*(int *)(param_1 + 0x260) != 0) {
    iVar8 = *(int *)(*(int *)(param_1 + 0x260) + 8);
    if (5 < iVar8) {
      iVar8 = 5;
    }
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        iVar3 = iVar3 + 1;
        bSPrintf_regdst(0x20,"menubar%d",iVar3);
        iVar9 = -1;
        pbVar5 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar5 + 1;
          iVar9 = iVar9 * 0x21 + (uint)bVar2;
          pbVar5 = pbVar5 + 1;
          bVar2 = *pbVar1;
        }
        if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0))
           && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
          iVar7 = *(int *)(iVar4 + 0x88);
          iVar10 = 0;
          if (iVar7 != 0) {
            piVar6 = *(int **)(iVar4 + 0x84);
            do {
              if (*(int *)(*piVar6 + 0x10) == iVar9) {
                iVar10 = *piVar6;
              }
              piVar6 = piVar6 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            if (iVar10 != 0) {
              *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) & 0xfbffffff;
            }
          }
        }
      } while (iVar3 < iVar8);
      if (4 < iVar3) {
        return iVar3;
      }
    }
    iVar3 = iVar3 + 1;
    do {
      bSPrintf_regdst(0x20,"menubar%d",iVar3);
      iVar9 = -1;
      pbVar5 = &local_20;
      bVar2 = local_20;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        pbVar1 = pbVar5 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar2;
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar1;
      }
      iVar8 = *(int *)(param_1 + 0xc);
      if (DAT_0073578c != 0) {
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        iVar8 = 0;
        if ((iVar4 != 0) && (iVar8 = *(int *)(iVar4 + 0x18), iVar8 != 0)) {
          iVar4 = *(int *)(iVar8 + 0x88);
          iVar7 = 0;
          if (iVar4 != 0) {
            piVar6 = *(int **)(iVar8 + 0x84);
            do {
              iVar8 = *piVar6;
              if (*(int *)(iVar8 + 0x10) == iVar9) {
                iVar7 = iVar8;
              }
              piVar6 = piVar6 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            if (iVar7 != 0) {
              *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x4000000;
            }
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  return iVar8;
}


// ==== 0x417e70 FUN_00417e70

/* WARNING: Removing unreachable block (ram,0x00417fd7) */

void FUN_00417e70(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
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
    puVar3 = *(undefined4 **)(param_1 + 0x270);
    *puVar3 = piVar5;
    *(int **)(param_1 + 0x270) = piVar5;
    piVar5[1] = (int)puVar3;
    *piVar5 = param_1 + 0x26c;
    if (*(int *)(param_1 + 0x284) == 0) {
      *(undefined4 *)(param_1 + 0x284) = *(undefined4 *)(param_1 + 0x26c);
    }
    iVar10 = *(int *)(param_1 + 0x270);
    bSPrintf_regdst(0x20,"Player_DATA_0%d",local_50);
    iVar9 = -1;
    pbVar8 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar2 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      bVar4 = *pbVar2;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00417fdb:
      if (DAT_0073578c == 0) goto LAB_00417ff3;
      iVar9 = FUN_004ef050(iVar9);
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00417f9b:
        if (iVar6 != 0) {
          local_4 = 0;
          FUN_004ffb00(iVar6);
          local_4 = 0xffffffff;
        }
        goto LAB_00417fdb;
      }
      if (DAT_0073578c != 0) {
        iVar11 = *(int *)(DAT_0073578c + 8);
        if ((iVar11 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar11 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar11 + 0xec), iVar6 == 0)))) goto LAB_00417fdb;
        goto LAB_00417f9b;
      }
LAB_00417ff3:
      iVar9 = 0;
    }
    piVar5 = _malloc(0xc);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5[2] = iVar9;
    }
    puVar3 = *(undefined4 **)(iVar10 + 0xc);
    *puVar3 = piVar5;
    *(int **)(iVar10 + 0xc) = piVar5;
    *piVar5 = iVar10 + 8;
    piVar5[1] = (int)puVar3;
    bSPrintf_regdst(0x20,"menubar%d",local_50);
    iVar9 = -1;
    pbVar8 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar2 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      bVar4 = *pbVar2;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00418109:
      if (DAT_0073578c == 0) goto LAB_0041811f;
      uVar7 = FUN_004ef050(iVar9);
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004180cb:
        local_4 = 1;
        FUN_004ffb00(iVar6);
        local_4 = 0xffffffff;
        goto LAB_00418109;
      }
      if (DAT_0073578c != 0) {
        iVar11 = *(int *)(DAT_0073578c + 8);
        if ((iVar11 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar11 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar11 + 0xec), iVar6 == 0)))) goto LAB_00418109;
        goto LAB_004180cb;
      }
LAB_0041811f:
      uVar7 = 0;
    }
    *(undefined4 *)(iVar10 + 0x10) = uVar7;
    iVar10 = -1;
    pbVar8 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar2 = pbVar8 + 1;
      iVar10 = iVar10 * 0x21 + (uint)bVar4;
      pbVar8 = pbVar8 + 1;
      bVar4 = *pbVar2;
    }
    if (((DAT_0073578c != 0) && (iVar9 = FEPackageList__FindByName(&DAT_00746104), iVar9 != 0)) &&
       (iVar9 = *(int *)(iVar9 + 0x18), iVar9 != 0)) {
      iVar6 = *(int *)(iVar9 + 0x88);
      iVar11 = 0;
      if (iVar6 != 0) {
        piVar5 = *(int **)(iVar9 + 0x84);
        do {
          if (*(int *)(*piVar5 + 0x10) == iVar10) {
            iVar11 = *piVar5;
          }
          piVar5 = piVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        if (iVar11 != 0) {
          *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) | 0x4000000;
        }
      }
    }
    local_50 = local_50 + 1;
    local_48 = local_48 + -1;
    if (local_48 == 0) {
      ExceptionList = local_c;
      return;
    }
  } while( true );
}


// ==== 0x4181e0 FUN_004181e0

void FUN_004181e0(int param_1)

{
  int iVar1;
  
  FUN_004f9340(param_1 + 0x26c);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    bSPrintf_regdst(0x20,"Player_DATA_0%d",iVar1);
    FUN_004f67f0(&DAT_006b9172);
  } while (iVar1 < 5);
  return;
}


// ==== 0x418230 FUN_00418230

void FUN_00418230(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int unaff_EBX;
  int local_24;
  char local_20 [32];
  
  FUN_004181e0(unaff_EBX);
  if ((*(int *)(unaff_EBX + 0x260) != 0) &&
     (local_24 = 0, 0 < *(int *)(*(int *)(unaff_EBX + 0x260) + 8))) {
    puVar1 = (undefined4 *)(unaff_EBX + 0x274);
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
      puVar3 = *(undefined4 **)(unaff_EBX + 0x278);
      *puVar3 = piVar6;
      *(int **)(unaff_EBX + 0x278) = piVar6;
      piVar6[1] = (int)puVar3;
      *piVar6 = (int)puVar1;
      if (*(int *)(unaff_EBX + 0x280) == 0) {
        *(undefined4 *)(unaff_EBX + 0x280) = *puVar1;
      }
      if (*(int *)(unaff_EBX + 0x27c) == 0) {
        *(undefined4 *)(unaff_EBX + 0x27c) = *puVar1;
      }
      piVar4 = *(int **)(unaff_EBX + 0x260);
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
    } while (local_24 < *(int *)(*(int *)(unaff_EBX + 0x260) + 8));
  }
  FUN_004f9240(unaff_EBX + 0x26c);
  if (*(int *)(unaff_EBX + 0x284) != 0) {
    FUN_004f8dd0(*(int *)(unaff_EBX + 0x284));
  }
  return;
}


// ==== 0x418330 Screen_MU_UG_NewOrLoad_PC2::ContainsProfileName

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

uint Screen_MU_UG_NewOrLoad_PC2__ContainsProfileName(byte *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte bVar3;
  int in_EAX;
  undefined4 *puVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  puVar4 = (undefined4 *)(in_EAX + 0x274);
  puVar1 = (undefined4 *)*puVar4;
  do {
    if (puVar1 == puVar4) {
      return (uint)puVar4 & 0xffffff00;
    }
    for (puVar2 = (undefined4 *)puVar1[2]; puVar2 != puVar1 + 2; puVar2 = (undefined4 *)*puVar2) {
      pbVar7 = (byte *)(puVar2 + 2);
      pbVar6 = param_1;
      do {
        bVar5 = *pbVar7;
        if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
          bVar5 = bVar5 & 0x5f;
        }
        bVar3 = *pbVar6;
        pbVar7 = pbVar7 + 1;
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 & 0x5f;
        }
        pbVar6 = pbVar6 + 1;
      } while (((bVar5 != 0) && (bVar3 != 0)) && (bVar5 == bVar3));
      if (bVar5 == bVar3) {
        return CONCAT31((char)bVar3 >> 7,1);
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x4183b0 FUN_004183b0

void __thiscall
FUN_004183b0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  void *_Memory;
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  cVar1 = FUN_0041f240(param_3,param_4,param_5);
  if (cVar1 != '\0') {
    return;
  }
  if (param_2 < 0x35f8620c) {
    if (param_2 == 0x35f8620b) {
      FUN_004181e0(param_1);
      *(undefined1 *)(param_1 + 0x264) = 1;
      return;
    }
    if (0x12349880 < param_2) {
      if (param_2 == 0x12349990) {
        FUN_00417580();
        cVar1 = Profile__DeleteAndReloadCfg();
        if (cVar1 == '\0') {
          FUN_00418cc0();
        }
        *(undefined1 *)(param_1 + 0x264) = 1;
        return;
      }
      if (param_2 != 0x1234ddd0) {
        return;
      }
      if (*(char *)(param_1 + 0x265) == '\0') {
        return;
      }
      if (*(int *)(param_1 + 0x274) == param_1 + 0x274) {
        return;
      }
      iVar2 = FUN_00417580();
      if (iVar2 == 0) {
        return;
      }
      iVar2 = bStrLen();
      if (iVar2 < 1) {
        return;
      }
      FUN_00418c00();
      FUN_004f63a0("PC_Menubar.fng");
      return;
    }
    if (param_2 == 0x12349880) {
      iVar2 = FUN_004f65d0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0xc407210) {
      if (param_2 == 0x12349660) {
        iVar2 = FUN_004f65d0();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0xff;
        }
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        *(undefined1 *)(param_1 + 0x25c) = 0;
        return;
      }
      if (param_2 != 0x12349770) {
        return;
      }
      FUN_00418230();
      *(undefined1 *)(param_1 + 0x25c) = 1;
      return;
    }
  }
  else {
    if (0xabc08912 < param_2) {
      if (param_2 == 0xc98356ba) {
        Screen_MU_UG_NewOrLoad_PC2__UpdateMenubarItems(param_1);
        FUN_00418ac0();
        if (*(char *)(param_1 + 0x264) != '\0') {
          _Memory = *(void **)(param_1 + 0x260);
          if (_Memory != (void *)0x0) {
            if (*(int *)((int)_Memory + 0xc) != 0) {
              FUN_00565ce0();
            }
            _free(_Memory);
          }
          puVar3 = _malloc(0x10);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            *puVar3 = 0x20;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = 0;
          }
          *(undefined4 **)(param_1 + 0x260) = puVar3;
          ProfileList__Load(&DAT_0078a478);
          if (*(int *)(*(int *)(param_1 + 0x260) + 8) < 1) {
            *(undefined1 *)(param_1 + 0x265) = 0;
            FUN_00418230();
            FUN_004f6c30("HighLight",1);
            if (DAT_0073578c != 0) {
              FUN_004f5ed0(DAT_0073578c);
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x265) = 1;
            FUN_00418230();
            Screen_MU_UG_NewOrLoad_PC2__SelectFirstEntry();
            FUN_004f6c30("UnHighLight",1);
            FUN_004f8dd0(*(undefined4 *)(param_1 + 0x284));
            FUN_004f64b0(*(undefined4 *)(param_1 + 0xc));
          }
          FUN_004c96c0(0x12349770);
          *(undefined1 *)(param_1 + 0x264) = 0;
        }
        cVar1 = FUN_004f6650();
        if ((cVar1 == '\0') && (cVar1 = FUN_004f6650(), cVar1 == '\0')) {
          return;
        }
        *(undefined1 *)(param_1 + 0x266) = 0;
        return;
      }
      if (param_2 != 0xd03dd189) {
        return;
      }
      if ((*(int *)(param_1 + 0x260) != 0) && (0x1d < *(int *)(*(int *)(param_1 + 0x260) + 8))) {
        FUN_004f66b0();
        FUN_00416bb0(0x97a7ed57);
        uStack_c = 0xde02cf84;
        uStack_10 = 0x797e05e6;
        uStack_8 = 0;
        FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      cVar1 = Screen_MU_UG_NewOrLoad_PC2__ContainsProfileName(&DAT_00777b74);
      if (cVar1 != '\0') {
        FUN_004f66b0();
        FUN_00416bb0(0x97a7ed57);
        uStack_c = 0xde02cf84;
        uStack_10 = 0xe4be358d;
        uStack_8 = 0;
        FUN_004dcbe0(&uStack_10,"GenericOKDialog.fng",*(undefined4 *)(param_1 + 0xc));
        return;
      }
      Profile__CreateNew(&DAT_00777b74);
      FUN_004c96c0(0x12349880);
      return;
    }
    if (param_2 == 0xabc08912) {
      FEString__SetLabelHash();
      FEObject__SetScript("FadeIn",1);
      FUN_00418a00(param_3);
      FUN_00416f00();
      return;
    }
    if (param_2 != 0x406415e3) {
      if (param_2 == 0x72619778) {
        if (*(char *)(param_1 + 0x25c) == '\0') {
          return;
        }
        if (*(char *)(param_1 + 0x265) == '\0') {
          return;
        }
        iVar2 = *(int *)(param_1 + 0x27c);
        FUN_004f9060();
        if (iVar2 != *(int *)(param_1 + 0x27c)) {
          return;
        }
        *(undefined1 *)(param_1 + 0x265) = 0;
        FUN_004f6c30("HighLight",1);
        FUN_004f8ec0(*(undefined4 *)(param_1 + 0x284));
        if (DAT_0073578c != 0) {
          FUN_004f5ed0(DAT_0073578c);
        }
        FUN_004f9240(param_1 + 0x26c);
        FUN_00416f00();
        return;
      }
      if (param_2 != 0x911c0a4b) {
        return;
      }
      if (*(char *)(param_1 + 0x25c) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x265) != '\0') {
        FUN_004f9060();
        return;
      }
      if (*(int *)(param_1 + 0x274) == param_1 + 0x274) {
        return;
      }
      *(undefined1 *)(param_1 + 0x265) = 1;
      FUN_004f6c30("UnHighLight",1);
      FUN_004f8dd0(*(undefined4 *)(param_1 + 0x284));
      FUN_004f9240(param_1 + 0x26c);
      FEString__SetLabelHash();
      FEObject__SetScript("FadeIn",1);
      FUN_00416f00();
      return;
    }
  }
  if (*(char *)(param_1 + 0x25c) != '\0') {
    if (*(char *)(param_1 + 0x265) == '\0') {
      FUN_00418be0();
      return;
    }
    if (*(int *)(param_1 + 0x274) != param_1 + 0x274) {
      FUN_00417580();
      Profile__Load();
      *(undefined1 *)(param_1 + 0x25c) = 0;
      FUN_004c96c0(0x12349660);
      return;
    }
  }
  return;
}


// ==== 0x418800 FUN_00418800

void FUN_00418800(void)

{
  return;
}


// ==== 0x4189e0 Screen_MU_UG_NewOrLoad_PC2::SelectFirstEntry

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_MU_UG_NewOrLoad_PC2__SelectFirstEntry(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x26c) != param_2 + 0x26c) {
    *(int *)(param_2 + 0x284) = *(int *)(param_2 + 0x26c);
  }
  return;
}


// ==== 0x418a00 FUN_00418a00

void FUN_00418a00(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int unaff_EDI;
  
  puVar5 = *(undefined4 **)(unaff_EDI + 0x280);
  piVar1 = (int *)(unaff_EDI + 0x26c);
  piVar6 = (int *)*piVar1;
  bVar2 = false;
  if (piVar6 != piVar1) {
    do {
      if (!bVar2) {
        if (piVar6[4] == param_1) {
          *(int **)(unaff_EDI + 0x284) = piVar6;
          bVar2 = true;
        }
        else if (puVar5 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      FUN_004f8ec0(piVar6);
      piVar6 = (int *)*piVar6;
    } while (piVar6 != piVar1);
    if (bVar2) {
      *(undefined4 **)(unaff_EDI + 0x27c) = puVar5;
      FUN_004f8dd0(*(undefined4 *)(unaff_EDI + 0x284));
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x18);
    }
    iVar3 = 0;
    if (iVar4 != 0) {
      iVar3 = *(int *)(iVar4 + 0x80);
    }
  }
  *(bool *)(unaff_EDI + 0x265) = *(int *)(iVar3 + 0x10) != 0x38fc835a;
  FUN_004f9240();
  return;
}


// ==== 0x418ac0 FUN_00418ac0

void FUN_00418ac0(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int unaff_EBX;
  int *piVar4;
  int local_4;
  
  if (*(char *)(unaff_EBX + 0x266) != '\0') {
    piVar4 = (int *)(unaff_EBX + 0x40);
    local_4 = 3;
    do {
      if ((*piVar4 != 0) && (cVar2 = FUN_004f7eb0(unaff_EBX), cVar2 != '\0')) {
        uVar1 = *(undefined4 *)(*piVar4 + 0x10);
        if ((*(int *)(unaff_EBX + 0xc) == 0) ||
           ((iVar3 = FUN_004f65d0(), iVar3 == 0 || (iVar3 = FUN_004ffb70(), iVar3 == 0)))) {
          if (DAT_0073578c != 0) {
            iVar3 = FUN_004ef050(uVar1);
            goto LAB_00418b32;
          }
        }
        else {
LAB_00418b32:
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xc407210,*piVar4,*(undefined4 *)(unaff_EBX + 0x4c),iVar3,0);
          }
        }
        iVar3 = *(int *)(*piVar4 + 0x10);
        if (iVar3 == -0x5597403a) {
          iVar3 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
             (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
            (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x911c0a4b,0,0,*(int *)(iVar3 + 0x18));
          }
        }
        else if (iVar3 == -0x55974029) {
          FUN_004c96c0(0x72619778);
        }
        else if (iVar3 == -0x15619cfe) {
          FUN_004c96c0(0x406415e3);
        }
      }
      piVar4 = piVar4 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}


// ==== 0x418be0 FUN_00418be0

void FUN_00418be0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x244) = 0x97a7ed57;
  DAT_0070108e = 1;
  FUN_0041f4d0();
  return;
}


// ==== 0x418c00 FUN_00418c00

void FUN_00418c00(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  local_108 = 0;
  local_104 = 0;
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  if ((*(int *)(unaff_EDI + 0x274) == unaff_EDI + 0x274) || (*(int *)(unaff_EDI + 0x27c) == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(unaff_EDI + 0x27c) + 8) + 8;
  }
  bSPrintf_regdst(0x100,iVar1,iVar2);
  local_118 = 0x541389e5;
  local_110 = 0x541389e5;
  local_124 = 0x2c8ec31d;
  local_11c = 0x12349990;
  local_120 = 0x639;
  local_114 = 0x12349000;
  local_10c = 0xb8a7c6cd;
  FUN_004dc6e0(&local_124,"GenericDialog.fng",*(undefined4 *)(unaff_EDI + 0xc));
  FUN_004dccc0(local_100);
  return;
}


// ==== 0x418cc0 FUN_00418cc0

void FUN_00418cc0(void)

{
  int in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xde02cf84;
  local_10 = 0xd58384eb;
  local_8 = 0x12349000;
  FUN_004dcbe0(&local_10,"GenericOKDialog.fng",*(undefined4 *)(in_EAX + 0xc));
  return;
}


// ==== 0x418d00 FUN_00418d00

void FUN_00418d00(void)

{
  undefined4 in_EAX;
  
  FUN_004198b0(in_EAX);
  return;
}


// ==== 0x418d10 EZWheel::ReleaseChannel

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__ReleaseChannel(int param_1)

{
  int in_EAX;
  
  (&DAT_0071dac8)[in_EAX * 4] = 0;
  (&DAT_0071dacc)[in_EAX * 4] = 0;
  (&DAT_0071dad0)[in_EAX * 4] = 0;
  (&DAT_0071dad4)[in_EAX * 4] = 0;
  (&DAT_0071d89c)[in_EAX] = 0;
  *(undefined1 *)(in_EAX + 0x220 + param_1) = 0;
  (&DAT_0071d888)[in_EAX] = 0;
  (&DAT_0071d88c)[in_EAX] = 0;
  (&DAT_0071d898)[in_EAX] = 0;
  (&DAT_0071d890)[in_EAX] = 0;
  return;
}


// ==== 0x418d70 EZWheel::ClearChannels

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__ClearChannels(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_0071dac8;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    (&DAT_0071d89c)[iVar1] = 0;
    *(undefined1 *)((int)param_1 + iVar1 + 0x220) = 0;
    (&DAT_0071d888)[iVar1] = 0;
    (&DAT_0071d88c)[iVar1] = 0;
    (&DAT_0071d898)[iVar1] = 0;
    (&DAT_0071d890)[iVar1] = 0;
    puVar2 = puVar2 + 4;
    iVar1 = iVar1 + 1;
  } while ((int)puVar2 < 0x71dae8);
  puVar2 = &DAT_0071d8a8;
  for (iVar1 = 0x88; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar1 = 0x88; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  puVar2 = &DAT_0071b888;
  for (iVar1 = 0x800; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x418e10 EZWheel::CreateDInputAndEnumerate

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void EZWheel__CreateDInputAndEnumerate(void)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  puVar5 = &DAT_00736338;
  puVar4 = &DAT_006a6f90;
  uVar3 = 0x800;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  iVar2 = DirectInput8Create(pHVar1,uVar3,puVar4,puVar5,uVar6);
  if (iVar2 < 0) {
    EZWheel__DebugLog("ERROR: failed to create a DInput object\n");
  }
  iVar2 = (**(code **)(*DAT_00736338 + 0x10))(DAT_00736338,4,EZWheel__EnumDevicesCallback,uVar3,1);
  if (iVar2 < 0) {
    EZWheel__DebugLog("ERROR: could not enumerate devices\n");
  }
  return;
}


// ==== 0x418e70 EZWheel::EnumDevicesCallback

/* [canon] input med (capstone) docs/re/hud_input.md */

undefined4 EZWheel__EnumDevicesCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (&stack0x00000000 != (undefined1 *)0xfffffff8) {
    uVar1 = EZWheel__OpenChannel(&stack0x00000008,param_1);
    return uVar1;
  }
  return 0;
}


// ==== 0x418e90 FUN_00418e90

uint FUN_00418e90(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  
  iVar4 = 0;
  piVar1 = &DAT_00700fd4;
  uVar3 = 0;
  do {
    iVar2 = 4;
    bVar7 = true;
    piVar5 = (int *)(param_1 + 0x14);
    piVar6 = piVar1;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *piVar5 == *piVar6;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      return *(uint *)(iVar4 * 0x14 + 0x700fe4);
    }
    uVar3 = uVar3 + 0x14;
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 5;
    if (0x13 < uVar3) {
      return (uint)*(byte *)(param_1 + 0x24);
    }
  } while( true );
}


// ==== 0x418ee0 EZWheel::OpenChannel

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

undefined4 EZWheel__OpenChannel(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int *piStack_28c;
  char *pcStack_288;
  int iStack_284;
  int *piStack_280;
  undefined *puStack_27c;
  int *piStack_278;
  int *piStack_274;
  int *piStack_270;
  undefined4 *puStack_26c;
  undefined4 local_244;
  int aiStack_240 [132];
  undefined4 uStack_30;
  undefined4 uStack_20;
  int iStack_14;
  int iStack_c;
  
  piVar4 = &DAT_0071d89c;
  do {
    piStack_270 = (int *)*piVar4;
    if (piStack_270 != (int *)0x0) {
      puStack_26c = &local_244;
      local_244 = 0x244;
      piStack_274 = (int *)0x418f2a;
      (**(code **)(*piStack_270 + 0x3c))();
      iVar3 = 4;
      bVar7 = true;
      piVar6 = aiStack_240;
      piVar5 = param_2;
      do {
        piVar5 = piVar5 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *piVar5 == *piVar6;
        piVar6 = piVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        return 1;
      }
    }
    piVar4 = piVar4 + 1;
    if (0x71d8a3 < (int)piVar4) {
      iVar3 = 0;
      while ((&DAT_0071d89c)[iVar3] != 0) {
        iVar3 = iVar3 + 1;
        if (1 < iVar3) {
          return 1;
        }
      }
      puStack_26c = (undefined4 *)0x0;
      puVar1 = &DAT_0071d89c + iVar3;
      piStack_274 = param_2 + 1;
      piStack_278 = DAT_00736338;
      puStack_27c = (undefined *)0x418f93;
      piStack_270 = puVar1;
      iVar2 = (**(code **)(*DAT_00736338 + 0xc))();
      if (iVar2 < 0) {
        piStack_280 = (int *)0x6cbb80;
        iStack_284 = 0x418fa2;
        puStack_27c = (undefined *)iVar3;
        EZWheel__DebugLog();
        (&DAT_0071dac8)[iVar3 * 4] = 0;
        (&DAT_0071dacc)[iVar3 * 4] = 0;
        (&DAT_0071dad0)[iVar3 * 4] = 0;
        (&DAT_0071dad4)[iVar3 * 4] = 0;
        *puVar1 = 0;
        *(undefined1 *)(iVar3 + 0x220 + iStack_c) = 0;
      }
      else {
        piStack_280 = (int *)*puVar1;
        puStack_27c = &DAT_006a6fd0;
        iStack_284 = 0x418ff1;
        iVar2 = (**(code **)(*piStack_280 + 0x2c))();
        if (-1 < iVar2) {
          piStack_28c = (int *)*puVar1;
          iStack_284 = 5;
          pcStack_288 = (char *)DAT_00736380;
          iVar2 = (**(code **)(*piStack_28c + 0x34))();
          if (iVar2 < 0) {
            EZWheel__DebugLog("ERROR: couldn\'t set cooperative level for wheel on channel %d\n",
                              iVar3);
            EZWheel__ReleaseChannel(uStack_20);
            return 1;
          }
          iVar2 = (**(code **)(*(int *)*puVar1 + 0x10))((int *)*puVar1,FUN_00419180,iVar3,0);
          if (-1 < iVar2) {
            (&DAT_0071dac8)[iVar3 * 4] = param_2[5];
            (&DAT_0071dacc)[iVar3 * 4] = param_2[6];
            (&DAT_0071dad0)[iVar3 * 4] = param_2[7];
            (&DAT_0071dad4)[iVar3 * 4] = param_2[8];
            iVar2 = FUN_00418e90(param_2);
            if (iVar2 == 0x14) {
              (&DAT_0071d898)[iVar3] = 1;
            }
            else if (iVar2 == 0x15) {
              (&DAT_0071d88c)[iVar3] = 1;
            }
            else if (iVar2 == 0x16) {
              (&DAT_0071d888)[iVar3] = 1;
            }
            if (((&DAT_0071d888)[iVar3] != '\0') &&
               (iVar2 = (**(code **)(*(int *)*puVar1 + 0x18))((int *)*puVar1,9,&piStack_28c),
               iVar2 < 0)) {
              EZWheel__DebugLog("ERROR: failed to disable autocenter property for device %d. OK if non FF wheel plugged in.\n"
                                ,iVar3);
            }
            return 1;
          }
          EZWheel__DebugLog("ERROR: couldn\'t enumerate objects for wheel on channel %d\n",iVar3);
          EZWheel__ReleaseChannel(uStack_30);
          return 1;
        }
        pcStack_288 = "ERROR: couldn\'t set data format for wheel on channel %d\n";
        piStack_28c = (int *)0x419000;
        iStack_284 = iVar3;
        EZWheel__DebugLog();
        (&DAT_0071dac8)[iVar3 * 4] = 0;
        (&DAT_0071dacc)[iVar3 * 4] = 0;
        (&DAT_0071dad0)[iVar3 * 4] = 0;
        (&DAT_0071dad4)[iVar3 * 4] = 0;
        *puVar1 = 0;
        *(undefined1 *)(iVar3 + 0x220 + iStack_14) = 0;
      }
      (&DAT_0071d888)[iVar3] = 0;
      (&DAT_0071d88c)[iVar3] = 0;
      (&DAT_0071d898)[iVar3] = 0;
      (&DAT_0071d890)[iVar3] = 0;
      return 1;
    }
  } while( true );
}


// ==== 0x419180 FUN_00419180

undefined4 FUN_00419180(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)(&DAT_0071d89c)[param_2];
  if (piVar1 != (int *)0x0) {
    uStack_10 = *(uint *)(param_1 + 0x18);
    if ((uStack_10 & 3) != 0) {
      uStack_18 = 0x18;
      uStack_14 = 0x10;
      uStack_c = 2;
      uStack_8 = 0xffffd8f0;
      uStack_4 = 10000;
      iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,4,&uStack_18);
      if (iVar2 < 0) {
        EZWheel__DebugLog("ERROR: SetProperty failed\n");
        return 0;
      }
    }
    if (((*(byte *)(param_1 + 0x1c) & 1) != 0) && ((&DAT_0071d890)[param_2] + 1 < 3)) {
      (&DAT_0071d890)[param_2] = (&DAT_0071d890)[param_2] + 1;
    }
  }
  return 1;
}


// ==== 0x419220 EZWheel::ReadChannel

/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

int EZWheel__ReadChannel(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 unaff_EBP;
  int iVar4;
  int unaff_ESI;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  int unaff_retaddr;
  
  piVar1 = (int *)(&DAT_0071d89c)[param_2];
  if (piVar1 == (int *)0x0) {
    EZWheel__DebugLog("ERROR: trying to read a wheel on channel %d that doesn\'t have a handle\n",
                      param_2);
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
  if (iVar2 < 0) {
    iVar2 = (**(code **)(*(int *)(&DAT_0071d89c)[param_2] + 0x1c))((int *)(&DAT_0071d89c)[param_2]);
    if (iVar2 < 0) {
      if (iVar2 == -0x7ff8fffb) {
        EZWheel__DebugLog("ERROR: ReadChannel %d: failed to acquire device, error DIERR_OTHERAPPHASPRIO.\n"
                          ,param_2);
        return 0;
      }
      if (iVar2 == -0x7ff8ffeb) {
        EZWheel__DebugLog("ERROR: ReadChannel %d: failed to acquire device, error DIERR_NOTINITIALIZED.\n"
                          ,param_2);
        return 0;
      }
      if (iVar2 == -0x7ff8ffa9) {
        EZWheel__DebugLog("ERROR: ReadChannel %d: failed to acquire device, error DIERR_INVALIDPARAM.\n"
                          ,param_2);
        return 0;
      }
      EZWheel__DebugLog("ERROR: ReadChannel %d: failed to acquire device, error unknown.\n",param_2)
      ;
      return 0;
    }
    if ((&DAT_0071d888)[param_2] != '\0') {
      iVar2 = (**(code **)(*(int *)(&DAT_0071d89c)[param_2] + 0x58))
                        ((int *)(&DAT_0071d89c)[param_2],0x10);
      if (-1 < iVar2) {
        *(undefined1 *)(param_2 + 0x220 + param_1) = 1;
        return 0;
      }
      EZWheel__DebugLog("ERROR: ReadChannel %d: failed to set actuators to ON\n",param_2);
      *(undefined1 *)(param_2 + 0x220 + param_1) = 0;
      return iVar2;
    }
  }
  else {
    if ((*(char *)(param_2 + 0x220 + param_1) == '\0') && ((&DAT_0071d890)[param_2] != 0)) {
      iVar2 = (**(code **)(*(int *)(&DAT_0071d89c)[param_2] + 0x58))
                        ((int *)(&DAT_0071d89c)[param_2],0x10);
      if (iVar2 < 0) {
        EZWheel__DebugLog("ERROR: ReadChannel %d: failed to set actuators to ON\n");
        *(undefined1 *)(param_2 + 0x220 + param_1) = 0;
        return iVar2;
      }
      *(undefined1 *)(param_2 + 0x220 + param_1) = 1;
    }
    iVar4 = param_1 * 0x110;
    piVar1 = (int *)(unaff_retaddr + iVar4);
    piVar5 = &DAT_0071d8a8 + param_1 * 0x44;
    piVar7 = piVar1;
    for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar7 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar7 = piVar7 + 1;
    }
    iVar2 = (**(code **)(*(int *)(&DAT_0071d89c)[param_1] + 0x24))
                      ((int *)(&DAT_0071d89c)[param_1],0x110,&DAT_0071d8a8 + param_1 * 0x44);
    if (iVar2 < 0) {
      EZWheel__DebugLog("ERROR: could not retrieve positional information for wheel on channel %d\n"
                        ,unaff_ESI);
      if (iVar2 == -0x7ff8ffe2) {
        EZWheel__DebugLog("Wheel got unplugged on channel %d!\n",unaff_ESI);
        EZWheel__ReleaseChannel(unaff_EBP);
      }
      return iVar2;
    }
    if (unaff_ESI == 1) {
      iVar2 = 4;
      bVar8 = true;
      piVar5 = &DAT_00700fe8;
      piVar7 = &DAT_0071dad8;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *piVar5 == *piVar7;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      } while (bVar8);
      if ((((bVar8) && (DAT_0071d9b8 == 10000)) && (DAT_0071d9bc == 10000)) &&
         ((DAT_0071d9c0 == 10000 && (DAT_0071d9cc == 10000)))) {
        DAT_0071d9b8 = 0;
        DAT_0071d9bc = 0;
        DAT_0071d9c0 = 0;
        DAT_0071d9cc = 0;
      }
    }
    uVar6 = 0;
    if (DAT_0073633c != '\0') {
      pcVar3 = (char *)(&DAT_0071d8a8 + param_1 * 0x44);
      iVar2 = (int)piVar1 - (int)pcVar3;
      while (*pcVar3 == pcVar3[iVar2]) {
        uVar6 = uVar6 + 1;
        pcVar3 = pcVar3 + 1;
        if (0x10f < uVar6) {
          return 0;
        }
      }
      EZWheel__DebugLog("\nInput changed on channel %d.",unaff_ESI);
      if ((&DAT_0071d8a8)[param_1 * 0x44] != *piVar1) {
        EZWheel__DebugLog("New lX:\t%d",(&DAT_0071d8a8)[param_1 * 0x44]);
      }
      if ((&DAT_0071d8ac)[param_1 * 0x44] != piVar1[1]) {
        EZWheel__DebugLog("New lY:\t%d",(&DAT_0071d8ac)[param_1 * 0x44]);
      }
      if (*(int *)(&DAT_0071d8b0 + iVar4) != piVar1[2]) {
        EZWheel__DebugLog("New lZ:\t%d",*(int *)(&DAT_0071d8b0 + iVar4));
      }
      if (*(int *)(&DAT_0071d8b4 + iVar4) != piVar1[3]) {
        EZWheel__DebugLog("New lRx:\t%d",*(int *)(&DAT_0071d8b4 + iVar4));
      }
      if (*(int *)(&DAT_0071d8b8 + iVar4) != piVar1[4]) {
        EZWheel__DebugLog("New lRy:\t%d",*(int *)(&DAT_0071d8b8 + iVar4));
      }
      if (*(int *)(&DAT_0071d8bc + iVar4) != piVar1[5]) {
        EZWheel__DebugLog("New lRz:\t%d",*(int *)(&DAT_0071d8bc + iVar4));
      }
      if (*(int *)(&DAT_0071d958 + iVar4) != piVar1[0x2c]) {
        EZWheel__DebugLog("New lVX:\t%d",*(int *)(&DAT_0071d958 + iVar4));
      }
      if (*(int *)(&DAT_0071d95c + iVar4) != piVar1[0x2d]) {
        EZWheel__DebugLog("New lVY:\t%d",*(int *)(&DAT_0071d95c + iVar4));
      }
      if (*(int *)(&DAT_0071d960 + iVar4) != piVar1[0x2e]) {
        EZWheel__DebugLog("New lVZ:\t%d",*(int *)(&DAT_0071d960 + iVar4));
      }
      if (*(int *)(&DAT_0071d964 + iVar4) != piVar1[0x2f]) {
        EZWheel__DebugLog("New lVRx:\t%d",*(int *)(&DAT_0071d964 + iVar4));
      }
      if (*(int *)(&DAT_0071d968 + iVar4) != piVar1[0x30]) {
        EZWheel__DebugLog("New lVRy:\t%d",*(int *)(&DAT_0071d968 + iVar4));
      }
      if (*(int *)(&DAT_0071d96c + iVar4) != piVar1[0x31]) {
        EZWheel__DebugLog("New lVRz:\t%d",*(int *)(&DAT_0071d96c + iVar4));
      }
      if (*(int *)(&DAT_0071d978 + iVar4) != piVar1[0x34]) {
        EZWheel__DebugLog("New lAX:\t%d",*(int *)(&DAT_0071d978 + iVar4));
      }
      if (*(int *)(&DAT_0071d97c + iVar4) != piVar1[0x35]) {
        EZWheel__DebugLog("New lAY:\t%d",*(int *)(&DAT_0071d97c + iVar4));
      }
      if (*(int *)(&DAT_0071d980 + iVar4) != piVar1[0x36]) {
        EZWheel__DebugLog("New lAZ:\t%d",*(int *)(&DAT_0071d980 + iVar4));
      }
      if (*(int *)(&DAT_0071d984 + iVar4) != piVar1[0x37]) {
        EZWheel__DebugLog("New lARx:\t%d",*(int *)(&DAT_0071d984 + iVar4));
      }
      if (*(int *)(&DAT_0071d988 + iVar4) != piVar1[0x38]) {
        EZWheel__DebugLog("New lARy:\t%d",*(int *)(&DAT_0071d988 + iVar4));
      }
      if (*(int *)(&DAT_0071d98c + iVar4) != piVar1[0x39]) {
        EZWheel__DebugLog("New lARz:\t%d",*(int *)(&DAT_0071d98c + iVar4));
      }
      if (*(int *)(&DAT_0071d998 + iVar4) != piVar1[0x3c]) {
        EZWheel__DebugLog("New lFX:\t%d",*(int *)(&DAT_0071d998 + iVar4));
      }
      if (*(int *)(&DAT_0071d99c + iVar4) != piVar1[0x3d]) {
        EZWheel__DebugLog("New lFY:\t%d",*(int *)(&DAT_0071d99c + iVar4));
      }
      if (*(int *)(&DAT_0071d9a0 + iVar4) != piVar1[0x3e]) {
        EZWheel__DebugLog("New lFZ:\t%d",*(int *)(&DAT_0071d9a0 + iVar4));
      }
      if (*(int *)(&DAT_0071d9a4 + iVar4) != piVar1[0x3f]) {
        EZWheel__DebugLog("New lFRx:\t%d",*(int *)(&DAT_0071d9a4 + iVar4));
      }
      if (*(int *)(&DAT_0071d9a8 + iVar4) != piVar1[0x40]) {
        EZWheel__DebugLog("New lFRy:\t%d",*(int *)(&DAT_0071d9a8 + iVar4));
      }
      if (*(int *)(&DAT_0071d9ac + iVar4) != piVar1[0x41]) {
        EZWheel__DebugLog("New lFRz:\t%d",*(int *)(&DAT_0071d9ac + iVar4));
      }
      piVar5 = (int *)(&DAT_0071d970 + iVar4);
      iVar2 = 0;
      piVar7 = piVar1 + 0x32;
      do {
        if (*piVar5 != *piVar7) {
          EZWheel__DebugLog("New rglVSlider[%d]:\t%d",iVar2,*piVar5);
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar2 < 2);
      piVar5 = (int *)(&DAT_0071d990 + iVar4);
      iVar2 = 0;
      piVar7 = piVar1 + 0x3a;
      do {
        if (*piVar5 != *piVar7) {
          EZWheel__DebugLog("New rglASlider[%d]:\t%d",iVar2,*piVar5);
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar2 < 2);
      piVar5 = (int *)(&DAT_0071d9b0 + iVar4);
      iVar2 = 0;
      piVar7 = piVar1 + 0x42;
      do {
        if (*piVar5 != *piVar7) {
          EZWheel__DebugLog("New rglFSlider[%d]:\t%d",iVar2,*piVar5);
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar2 < 2);
      piVar7 = (int *)(&DAT_0071d8c0 + iVar4);
      iVar2 = 0;
      piVar5 = piVar1 + 6;
      do {
        if (*piVar7 != *piVar5) {
          EZWheel__DebugLog("New rglSlider[%d]:\t%d",iVar2,*piVar7);
        }
        iVar2 = iVar2 + 1;
        piVar7 = piVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < 2);
      piVar7 = (int *)(&DAT_0071d8c8 + iVar4);
      iVar2 = 0;
      piVar5 = piVar1 + 8;
      do {
        if (*piVar7 != *piVar5) {
          EZWheel__DebugLog("New rgdwPOV[%d]:\t%d",iVar2,*piVar7);
        }
        iVar2 = iVar2 + 1;
        piVar7 = piVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < 4);
      iVar2 = 0;
      do {
        if ((&DAT_0071d8d8)[iVar4 + iVar2] != *(char *)((int)piVar1 + iVar2 + 0x30)) {
          EZWheel__DebugLog("New rgbButtons[%d]:\t%d",iVar2,(&DAT_0071d8d8)[iVar4 + iVar2]);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x80);
    }
  }
  return 0;
}


// ==== 0x4198b0 FUN_004198b0

void FUN_004198b0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = &DAT_0071d89c;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1);
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar2 = 0;
      }
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x71d8a4);
  if (DAT_00736338 != (int *)0x0) {
    (**(code **)(*DAT_00736338 + 8))(DAT_00736338);
    DAT_00736338 = (int *)0x0;
  }
  return;
}


// ==== 0x419900 EZWheel::CreatePeriodicEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall
EZWheel__CreatePeriodicEffect
          (int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
          undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
          undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21,
          undefined4 param_22,undefined4 param_23,undefined4 param_24)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  piVar1 = (int *)(param_1 + 0x10 + (in_EAX + param_2 * 8) * 4);
  iVar3 = 0;
  if (*piVar1 != 0) {
    EZWheel__UnloadEffect(param_2);
  }
  param_3 = (int *)*param_3;
  if (param_3 != (int *)0x0) {
    local_68 = param_12;
    local_6c = param_11;
    local_60 = param_14;
    local_64 = param_13;
    local_58 = param_16;
    local_5c = param_15;
    local_50 = param_18;
    local_54 = param_17;
    local_44 = param_21;
    local_48 = param_20;
    local_3c = param_23;
    local_40 = param_22;
    puVar4 = local_38;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_38[2] = param_5;
    local_28 = param_7;
    local_20 = param_9;
    local_38[1] = param_4;
    local_38[3] = param_6;
    local_18 = &local_6c;
    local_24 = param_8;
    local_10 = &local_4c;
    local_4 = param_19;
    local_1c = param_10;
    local_14 = &local_64;
    local_8 = &local_5c;
    local_4c = 0x14;
    local_38[0] = 0x38;
    local_c = 0x10;
    iVar3 = (**(code **)(*param_3 + 0x48))(param_3,param_24,local_38,piVar1,0);
    if (iVar3 < 0) {
      EZWheel__DebugLog("ERROR: Failed to create periodic effect on channel %d\n",param_2);
      return iVar3;
    }
  }
  iVar2 = -0x7fffbffb;
  if (*piVar1 != 0) {
    iVar2 = iVar3;
  }
  return iVar2;
}


// ==== 0x419ab0 EZWheel::UpdatePeriodicForce

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __fastcall
EZWheel__UpdatePeriodicForce
          (undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
          undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
          undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21,
          undefined4 param_22,undefined4 param_23)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)(param_2 + 0x10 + (in_EAX + param_3 * 8) * 4);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    local_68 = param_12;
    local_6c = param_11;
    local_60 = param_14;
    local_64 = param_13;
    local_58 = param_16;
    local_5c = param_15;
    local_50 = param_18;
    local_54 = param_17;
    local_44 = param_21;
    local_48 = param_20;
    local_3c = param_23;
    local_40 = param_22;
    puVar3 = local_38;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_38[2] = param_5;
    local_28 = param_7;
    local_38[1] = param_4;
    local_20 = param_9;
    local_38[3] = param_6;
    local_24 = param_8;
    local_18 = &local_6c;
    local_10 = &local_4c;
    local_1c = param_10;
    local_14 = &local_64;
    local_4 = param_19;
    local_8 = &local_5c;
    local_4c = 0x14;
    local_38[0] = 0x38;
    local_c = 0x10;
    iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,local_38,0x140);
    if (iVar2 < 0) {
      EZWheel__DebugLog("ERROR: Failed to update periodic force on channel %d\n",param_3);
    }
  }
  return iVar2;
}


// ==== 0x419c20 EZWheel::DebugLog

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__DebugLog(LPCSTR param_1)

{
  CHAR local_100 [256];
  
  wvsprintfA(local_100,param_1,&stack0x00000008);
  OutputDebugStringA(local_100);
  OutputDebugStringA("\r\n");
  return;
}


// ==== 0x419c60 EZWheel::Create

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__Create(void)

{
  int unaff_ESI;
  
  EZWheel__ClearChannels(unaff_ESI + 0x2224);
  EZWheel__CreateDInputAndEnumerate(unaff_ESI + 0x2224);
  FUN_0041ba80();
  FUN_0041ba80();
  FUN_0041ba80();
  FUN_0041ba80();
  FUN_0041ba80();
  EZWheel__ResetState(unaff_ESI);
  EZWheel__BuildSineTable();
  return;
}


// ==== 0x419cc0 FUN_00419cc0

void FUN_00419cc0(int param_1)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_006850ae;
  local_c = ExceptionList;
  local_4 = 5;
  ExceptionList = &local_c;
  FUN_0041b970(param_1);
  local_4._0_1_ = 4;
  FUN_0041bd60();
  local_4._0_1_ = 3;
  FUN_0041bd60();
  local_4._0_1_ = 2;
  FUN_0041bd60();
  local_4._0_1_ = 1;
  FUN_0041bd60();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0041bd60();
  local_4 = 0xffffffff;
  FUN_004198b0(param_1 + 0x2224);
  ExceptionList = local_c;
  return;
}


// ==== 0x419d60 EZWheel::ResetState

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__ResetState(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  uint *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint local_c;
  ushort local_8;
  
  iVar1 = param_1;
  FUN_006724fa(&local_c);
  puVar5 = (undefined1 *)(param_1 + 0x24e8);
  puVar7 = (undefined4 *)(param_1 + 0x24f8);
  param_1 = 8;
  do {
    iVar6 = 2;
    puVar2 = puVar7;
    puVar3 = puVar5;
    do {
      puVar2[-0x14] = 0;
      puVar3[-0x50] = 0;
      *puVar2 = 0;
      *puVar3 = 0;
      puVar2[0x14] = 0;
      puVar3[0x50] = 0;
      puVar2[0x28] = 0;
      puVar3[0xa0] = 0;
      puVar2 = puVar2 + 8;
      puVar3 = puVar3 + 8;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar7 = puVar7 + 1;
    puVar5 = puVar5 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  puVar5 = (undefined1 *)(iVar1 + 0x25da);
  puVar4 = (uint *)(iVar1 + 0x2b98);
  iVar6 = 2;
  puVar7 = (undefined4 *)(iVar1 + 0x25dc);
  do {
    puVar5[-2] = 0;
    *puVar5 = 0;
    puVar5[-0x3ba] = 0;
    puVar4[-2] = local_c;
    *puVar4 = (uint)local_8;
    *puVar7 = 0;
    puVar4 = puVar4 + 1;
    puVar7[1] = 0;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
    *(undefined2 *)(puVar7 + 2) = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 10);
  } while (iVar6 != 0);
  EZWheel__DebugLog("EZ Wheel Wrapper v4.26\n");
  return;
}


// ==== 0x419e40 EZWheel::BuildSineTable

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void EZWheel__BuildSineTable(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 *puVar2;
  int local_4;
  
  local_4 = 0;
  puVar2 = (undefined4 *)(in_EAX + 0x25f0);
  do {
    fsin((float10)local_4 * (float10)3.141592654 * (float10)0.005555555555555556);
    uVar1 = _ftol_nocw();
    local_4 = local_4 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (local_4 < 0x168);
  return;
}


// ==== 0x419ea0 EZWheel::Poll

/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

void EZWheel__Poll(void)

{
  uint uVar1;
  undefined4 *in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if ((DAT_00736340 != 0) &&
     (uVar1 = DAT_0078eb78 & 0x1f, DAT_0078eb78 = DAT_0078eb78 + 1, uVar1 == 0)) {
    iVar2 = (**(code **)(*DAT_00736338 + 0x10))
                      (DAT_00736338,4,EZWheel__EnumDevicesCallback,in_EAX + 0x889,1);
    if (iVar2 < 0) {
      EZWheel__DebugLog("ERROR: could not enumerate devices\n");
    }
  }
  iVar5 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_0071d89c)[iVar5] != 0) {
      iVar3 = EZWheel__ReadChannel(in_EAX + 0x889,iVar5);
      if (iVar3 == -0x7ff8ffe2) {
        iVar3 = 0;
        puVar4 = (undefined4 *)(iVar2 + 0x24a8 + (int)in_EAX);
        do {
          *(undefined1 *)((int)in_EAX + iVar3 + iVar5 * 8 + 0x2498) = 0;
          *puVar4 = 0;
          iVar3 = iVar3 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar3 < 8);
      }
    }
    iVar5 = iVar5 + 1;
    iVar2 = iVar2 + 0x20;
  } while (iVar5 < 2);
  puVar4 = &DAT_0071d8a8;
  for (iVar2 = 0x88; iVar2 != 0; iVar2 = iVar2 + -1) {
    *in_EAX = *puVar4;
    puVar4 = puVar4 + 1;
    in_EAX = in_EAX + 1;
  }
  return;
}


// ==== 0x419f50 FUN_00419f50

void __thiscall FUN_00419f50(int param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  
  switch(param_3) {
  case 0:
    param_1 = param_1 + 0x2498;
    goto LAB_00419f6f;
  case 1:
    param_1 = param_1 + 0x24e8;
    goto LAB_00419f6f;
  case 2:
    param_1 = param_1 + 0x2498;
    goto LAB_00419fc0;
  case 3:
    param_1 = param_1 + 0x24e8;
    goto LAB_00419fc0;
  case 4:
    param_1 = param_1 + 0x2538;
LAB_00419f6f:
    cVar3 = FUN_0041bc20(param_1);
    if (cVar3 != '\0') {
      EZWheel__StopEffect(param_2);
      return;
    }
    break;
  case 5:
    param_1 = param_1 + 0x2538;
LAB_00419fc0:
    cVar3 = FUN_0041bc20(param_1);
    if (cVar3 != '\0') {
      EZWheel__StopEffect(param_2);
      return;
    }
    break;
  case 6:
    cVar3 = FUN_0041bc20(param_1 + 0x2538);
    if (cVar3 != '\0') {
      EZWheel__StopEffect(param_2);
      return;
    }
    break;
  case 7:
    cVar3 = FUN_0041bc20(param_1 + 0x2498);
    if (cVar3 != '\0') {
      EZWheel__StopEffect(param_2);
    }
    if (*(char *)(param_2 + 0x25d8 + param_1) != '\0') {
      FUN_0041a6c0(param_1);
      *(undefined1 *)(param_1 + 0x2499 + param_2 * 8) = 1;
      *(undefined1 *)(param_2 + 0x25d8 + param_1) = 0;
    }
    if (*(char *)(param_2 + 0x25da + param_1) != '\0') {
      FUN_0041a250(param_1,*(undefined4 *)(param_1 + (param_2 * 3 + 0xae9) * 4),
                   *(undefined4 *)(param_1 + 0x2ba8 + param_2 * 0xc));
      *(undefined1 *)(param_1 + 0x2498 + param_2 * 8) = 1;
      *(undefined1 *)(param_2 + 0x25da + param_1) = 0;
      return;
    }
    break;
  case 8:
    cVar3 = FUN_0041bc20(param_1 + 0x2538);
    if (cVar3 != '\0') {
      EZWheel__StopEffect(param_2);
      return;
    }
    break;
  case 9:
    if (*(char *)(param_2 + 0x2220 + param_1) == '\x01') {
      iVar2 = param_1 + param_2 * 10;
      pcVar1 = (char *)(iVar2 + 0x25dc);
      *(undefined1 *)(param_2 + 0x2220 + param_1) = 0;
      if (*pcVar1 == '\x01') {
        FUN_0041a250(param_1,*(undefined4 *)(param_1 + (param_2 * 3 + 0xae9) * 4),
                     *(undefined4 *)(param_1 + 0x2ba8 + param_2 * 0xc));
      }
      if (*(char *)(iVar2 + 0x25dd) == '\x01') {
        FUN_0041a640(param_2,*(undefined4 *)(param_1 + 0x2bb8 + param_2 * 8));
      }
      if (*(char *)(iVar2 + 0x25de) == '\x01') {
        FUN_0041a6c0(param_1);
      }
      if (*(char *)(iVar2 + 0x25e1) == '\x01') {
        FUN_0041ab00(param_1,*(undefined4 *)(param_1 + 0x2be8 + param_2 * 4));
      }
      if (*(char *)(iVar2 + 0x25e2) == '\x01') {
        FUN_0041ad20(param_1,*(undefined4 *)(param_1 + 0x2bf0 + param_2 * 4));
      }
      if (*(char *)(iVar2 + 0x25e3) == '\x01') {
        FUN_0041af40(param_1,*(undefined4 *)(param_1 + 0x2bf8 + param_2 * 4));
      }
      if (*(char *)(param_1 + (param_2 * 5 + 0x12f2) * 2) == '\x01') {
        FUN_0041b210(param_1,*(undefined4 *)(param_1 + param_2 * 0xc + 0x2c00),
                     *(undefined4 *)(param_1 + (param_2 * 3 + 0xb01) * 4),
                     *(undefined4 *)(param_1 + 0x2c08 + param_2 * 0xc));
      }
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      *(undefined4 *)(iVar2 + 0x25e0) = 0;
      *(undefined2 *)(iVar2 + 0x25e4) = 0;
    }
  }
  return;
}


// ==== 0x41a250 FUN_0041a250

void FUN_0041a250(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar2 = param_1 + 0x2498;
  cVar1 = FUN_0041bc20(iVar2);
  if (cVar1 == '\0') {
    if ((&DAT_0071d89c)[unaff_ESI] == 0) {
      EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
      EZWheel__DebugLog("wheel/joystick opened.\n");
    }
    else if ((*(char *)(unaff_ESI + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[unaff_ESI] != 0))
    {
      cVar1 = FUN_0041bc20(iVar2);
      if (cVar1 == '\0') {
        if (*(int *)(unaff_ESI * 0x20 + 0x24a8 + param_1) == 0) {
          iVar3 = EZWheel__CreateConditionEffect
                            (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,
                             0,(&DAT_0071d890)[unaff_ESI],0,4,1,1,in_EAX,param_3,param_3,param_2,
                             param_2,0,0,&DAT_006a6e60);
        }
        else {
          cVar1 = FUN_0041a470(param_2,param_3);
          if (cVar1 != '\0') {
            EZWheel__StartEffect(iVar2,unaff_ESI);
            return;
          }
          iVar3 = EZWheel__UpdateConditionForce
                            (iVar2,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                             (&DAT_0071d890)[unaff_ESI],0,4,1,1,in_EAX,param_3,param_3,param_2,
                             param_2,0,0);
        }
        if (-1 < iVar3) {
          iVar3 = param_1 + unaff_ESI * 0xc;
          *(undefined4 *)(iVar3 + 0x2ba0) = in_EAX;
          *(undefined4 *)(param_1 + (unaff_ESI * 3 + 0xae9) * 4) = param_2;
          *(undefined4 *)(iVar3 + 0x2ba8) = param_3;
        }
        EZWheel__StartEffect(iVar2,unaff_ESI);
        return;
      }
      cVar1 = FUN_0041a470(param_2,param_3);
      if (cVar1 == '\0') {
        iVar2 = EZWheel__UpdateConditionForce
                          (iVar2,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[unaff_ESI],0,4,1,1,in_EAX,param_3,param_3,param_2,param_2
                           ,0,0);
        if (-1 < iVar2) {
          iVar2 = param_1 + unaff_ESI * 0xc;
          *(undefined4 *)(iVar2 + 0x2ba0) = in_EAX;
          *(undefined4 *)(param_1 + (unaff_ESI * 3 + 0xae9) * 4) = param_2;
          *(undefined4 *)(iVar2 + 0x2ba8) = param_3;
          return;
        }
      }
    }
  }
  return;
}


// ==== 0x41a450 FUN_0041a450

void FUN_0041a450(void)

{
  int in_EAX;
  
  if ((&DAT_0071d890)[in_EAX] != 0) {
    FUN_00419f50(in_EAX,0);
  }
  return;
}


// ==== 0x41a470 FUN_0041a470

undefined4 __fastcall FUN_0041a470(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int in_EAX;
  int unaff_EDI;
  
  if (((*(int *)(param_2 + 0x2ba0 + in_EAX * 0xc) == unaff_EDI) &&
      (*(int *)(param_2 + (in_EAX * 3 + 0xae9) * 4) == param_3)) &&
     (*(int *)(param_2 + in_EAX * 0xc + 0x2ba8) == param_4)) {
    return 1;
  }
  return 0;
}


// ==== 0x41a4b0 FUN_0041a4b0

void FUN_0041a4b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((&DAT_0071d89c)[unaff_ESI] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if ((*(char *)(unaff_ESI + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[unaff_ESI] != 0)) {
    iVar2 = param_1 + 0x24e8;
    cVar1 = FUN_0041bc20(iVar2);
    if (cVar1 == '\0') {
      if (*(int *)(unaff_ESI * 0x20 + 0x24f8 + param_1) == 0) {
        iVar3 = EZWheel__CreateConstantEffect
                          (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[unaff_ESI],0,4,1,0,unaff_EDI,0,0,0,0,0,&DAT_006a6ec0);
        if (-1 < iVar3) {
          *(int *)(param_1 + 0x2bb8 + unaff_ESI * 8) = unaff_EDI;
        }
      }
      else if (*(int *)(param_1 + 0x2bb8 + unaff_ESI * 8) != unaff_EDI) {
        iVar3 = EZWheel__UpdateConstantForce
                          (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI]
                           ,0,4,1,0,unaff_EDI,0,0,0,0,0);
        if (-1 < iVar3) {
          *(int *)(param_1 + 0x2bb8 + unaff_ESI * 8) = unaff_EDI;
        }
        EZWheel__StartEffect(iVar2,unaff_ESI);
        return;
      }
      EZWheel__StartEffect(iVar2,unaff_ESI);
      return;
    }
    if (*(int *)(param_1 + 0x2bb8 + unaff_ESI * 8) != unaff_EDI) {
      iVar2 = EZWheel__UpdateConstantForce
                        (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0
                         ,4,1,0,unaff_EDI,0,0,0,0,0);
      if (-1 < iVar2) {
        *(int *)(param_1 + 0x2bb8 + unaff_ESI * 8) = unaff_EDI;
        return;
      }
    }
  }
  return;
}


// ==== 0x41a640 FUN_0041a640

void __fastcall FUN_0041a640(undefined4 param_1)

{
  FUN_0041a4b0(param_1);
  return;
}


// ==== 0x41a680 FUN_0041a680

void __fastcall FUN_0041a680(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (((&DAT_0071d890)[unaff_ESI] != 0) && (cVar1 = FUN_0041bc20(param_1 + 0x24e8), cVar1 != '\0'))
  {
    EZWheel__StopEffect(unaff_ESI);
  }
  return;
}


// ==== 0x41a6c0 FUN_0041a6c0

void FUN_0041a6c0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar3 = param_1 + 0x2498;
  cVar1 = FUN_0041bc20(iVar3);
  if (cVar1 == '\0') {
    if ((&DAT_0071d89c)[unaff_ESI] == 0) {
      EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
      EZWheel__DebugLog("wheel/joystick opened.\n");
    }
    else if ((*(char *)(unaff_ESI + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[unaff_ESI] != 0))
    {
      cVar1 = FUN_0041bc20(iVar3);
      if (cVar1 == '\0') {
        if (*(int *)(unaff_ESI * 0x20 + 0x24ac + param_1) == 0) {
          iVar2 = EZWheel__CreateConditionEffect
                            (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,
                             0,(&DAT_0071d890)[unaff_ESI],0,4,1,0,0,unaff_EDI,unaff_EDI,10000,10000,
                             0,0,&DAT_006a6e50);
          if (-1 < iVar2) {
            *(int *)(param_1 + 0x2bc8 + unaff_ESI * 4) = unaff_EDI;
          }
          EZWheel__StartEffect(iVar3,unaff_ESI);
          return;
        }
        if (*(int *)(param_1 + 0x2bc8 + unaff_ESI * 4) != unaff_EDI) {
          iVar2 = EZWheel__UpdateConditionForce
                            (iVar3,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                             (&DAT_0071d890)[unaff_ESI],0,4,1,0,0,unaff_EDI,unaff_EDI,10000,10000,0,
                             0);
          if (-1 < iVar2) {
            *(int *)(param_1 + 0x2bc8 + unaff_ESI * 4) = unaff_EDI;
          }
          EZWheel__StartEffect(iVar3,unaff_ESI);
          return;
        }
        EZWheel__StartEffect(iVar3,unaff_ESI);
        return;
      }
      if ((*(int *)(param_1 + 0x2bc8 + unaff_ESI * 4) != unaff_EDI) &&
         (iVar3 = EZWheel__UpdateConditionForce
                            (iVar3,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                             (&DAT_0071d890)[unaff_ESI],0,4,1,0,0,unaff_EDI,unaff_EDI,10000,10000,0,
                             0), -1 < iVar3)) {
        *(int *)(param_1 + 0x2bc8 + unaff_ESI * 4) = unaff_EDI;
        return;
      }
    }
  }
  return;
}


// ==== 0x41a8a0 FUN_0041a8a0

void FUN_0041a8a0(void)

{
  int in_EAX;
  
  if ((&DAT_0071d890)[in_EAX] != 0) {
    FUN_00419f50(in_EAX,2);
  }
  return;
}


// ==== 0x41a8c0 FUN_0041a8c0

void FUN_0041a8c0(int param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int local_c;
  ushort local_8;
  
  bVar1 = false;
  FUN_006724fa(&local_c);
  iVar4 = *(int *)(unaff_EDI + 0x2b90 + unaff_ESI * 4);
  iVar3 = local_c - iVar4;
  if (local_c == iVar4) {
    iVar4 = (uint)local_8 - *(int *)(unaff_EDI + 0x2b98 + unaff_ESI * 4);
joined_r0x0041a920:
    if (iVar4 < 0x96) goto LAB_0041a93b;
  }
  else {
    if (iVar3 == 1) {
      iVar4 = ((uint)local_8 - *(int *)(unaff_EDI + 0x2b98 + unaff_ESI * 4)) + 1000;
      goto joined_r0x0041a920;
    }
    if (iVar3 < 2) goto LAB_0041a93b;
  }
  bVar1 = true;
  *(int *)(unaff_EDI + 0x2b90 + unaff_ESI * 4) = local_c;
  *(uint *)(unaff_EDI + 0x2b98 + unaff_ESI * 4) = (uint)local_8;
LAB_0041a93b:
  if ((&DAT_0071d89c)[unaff_ESI] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if (((&DAT_0071d890)[unaff_ESI] != 0) && (bVar1)) {
    iVar4 = unaff_EDI + 0x2538;
    cVar2 = FUN_0041bc20(iVar4);
    if (cVar2 == '\0') {
      if (*(int *)(unaff_ESI * 0x20 + 0x2548 + unaff_EDI) == 0) {
        iVar3 = EZWheel__CreatePeriodicEffect
                          (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,150000,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[unaff_ESI],0,4,1,0,param_1,0,0,75000,0,0,0,0,20000,
                           &DAT_006a6eb0);
        if (-1 < iVar3) {
          *(int *)(unaff_EDI + 0x2be0 + unaff_ESI * 4) = param_1;
        }
      }
      else if (*(int *)(unaff_EDI + 0x2be0 + unaff_ESI * 4) != param_1) {
        iVar3 = EZWheel__UpdatePeriodicForce
                          (unaff_ESI,0x12,150000,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0,4
                           ,1,0,param_1,0,0,75000,0,0,0,0,20000);
        if (-1 < iVar3) {
          *(int *)(unaff_EDI + 0x2be0 + unaff_ESI * 4) = param_1;
        }
        EZWheel__StartEffect(iVar4,unaff_ESI);
        return;
      }
    }
    else if (*(int *)(unaff_EDI + 0x2be0 + unaff_ESI * 4) != param_1) {
      iVar3 = EZWheel__UpdatePeriodicForce
                        (unaff_ESI,0x12,150000,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0,4,1
                         ,0,param_1,0,0,75000,0,0,0,0,20000);
      if (-1 < iVar3) {
        *(int *)(unaff_EDI + 0x2be0 + unaff_ESI * 4) = param_1;
      }
      EZWheel__StartEffect(iVar4,unaff_ESI);
      return;
    }
    EZWheel__StartEffect(iVar4,unaff_ESI);
    return;
  }
  return;
}


// ==== 0x41ab00 FUN_0041ab00

void FUN_0041ab00(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  if ((&DAT_0071d89c)[unaff_ESI] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if ((*(char *)(unaff_ESI + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[unaff_ESI] != 0)) {
    iVar3 = param_1 + 0x2538;
    cVar1 = FUN_0041bc20(iVar3);
    if (cVar1 == '\0') {
      if (*(int *)(unaff_ESI * 0x20 + 0x254c + param_1) == 0) {
        iVar2 = EZWheel__CreatePeriodicEffect
                          (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[unaff_ESI],0,4,1,0,param_2,0,0,65000,0,0,0,0,0,
                           &DAT_006a6ea0);
        if (-1 < iVar2) {
          *(int *)(param_1 + 0x2be8 + unaff_ESI * 4) = param_2;
        }
        EZWheel__StartEffect(iVar3,unaff_ESI);
        return;
      }
      if (*(int *)(param_1 + 0x2be8 + unaff_ESI * 4) == param_2) {
        EZWheel__StartEffect(iVar3,unaff_ESI);
        return;
      }
      iVar2 = EZWheel__UpdatePeriodicForce
                        (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0
                         ,4,1,0,param_2,0,0,65000,0,0,0,0,0);
      if (-1 < iVar2) {
        *(int *)(param_1 + 0x2be8 + unaff_ESI * 4) = param_2;
      }
      EZWheel__StartEffect(iVar3,unaff_ESI);
      return;
    }
    if (*(int *)(param_1 + 0x2be8 + unaff_ESI * 4) != param_2) {
      iVar3 = EZWheel__UpdatePeriodicForce
                        (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0
                         ,4,1,0,param_2,0,0,65000,0,0,0,0,0);
      if (-1 < iVar3) {
        *(int *)(param_1 + 0x2be8 + unaff_ESI * 4) = param_2;
        return;
      }
    }
  }
  return;
}


// ==== 0x41ace0 FUN_0041ace0

void __fastcall FUN_0041ace0(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (((&DAT_0071d890)[unaff_ESI] != 0) && (cVar1 = FUN_0041bc20(param_1 + 0x2538), cVar1 != '\0'))
  {
    EZWheel__StopEffect(unaff_ESI);
  }
  return;
}


// ==== 0x41ad20 FUN_0041ad20

void FUN_0041ad20(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  if ((&DAT_0071d89c)[unaff_ESI] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if ((*(char *)(unaff_ESI + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[unaff_ESI] != 0)) {
    iVar3 = param_1 + 0x2538;
    cVar1 = FUN_0041bc20(iVar3);
    if (cVar1 == '\0') {
      if (*(int *)(unaff_ESI * 0x20 + 0x2550 + param_1) == 0) {
        iVar2 = EZWheel__CreatePeriodicEffect
                          (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[unaff_ESI],0,4,1,0,param_2,0,0,100000,0,0,0,0,0,
                           &DAT_006a6eb0);
        if (-1 < iVar2) {
          *(int *)(param_1 + 0x2bf0 + unaff_ESI * 4) = param_2;
        }
        EZWheel__StartEffect(iVar3,unaff_ESI);
        return;
      }
      if (*(int *)(param_1 + 0x2bf0 + unaff_ESI * 4) == param_2) {
        EZWheel__StartEffect(iVar3,unaff_ESI);
        return;
      }
      iVar2 = EZWheel__UpdatePeriodicForce
                        (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0
                         ,4,1,0,param_2,0,0,100000,0,0,0,0,0);
      if (-1 < iVar2) {
        *(int *)(param_1 + 0x2bf0 + unaff_ESI * 4) = param_2;
      }
      EZWheel__StartEffect(iVar3,unaff_ESI);
      return;
    }
    if (*(int *)(param_1 + 0x2bf0 + unaff_ESI * 4) != param_2) {
      iVar3 = EZWheel__UpdatePeriodicForce
                        (unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[unaff_ESI],0
                         ,4,1,0,param_2,0,0,100000,0,0,0,0,0);
      if (-1 < iVar3) {
        *(int *)(param_1 + 0x2bf0 + unaff_ESI * 4) = param_2;
        return;
      }
    }
  }
  return;
}


// ==== 0x41af00 FUN_0041af00

void __fastcall FUN_0041af00(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (((&DAT_0071d890)[unaff_ESI] != 0) && (cVar1 = FUN_0041bc20(param_1 + 0x2538), cVar1 != '\0'))
  {
    EZWheel__StopEffect(unaff_ESI);
  }
  return;
}


// ==== 0x41af40 FUN_0041af40

void FUN_0041af40(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar2 = param_1 + 0x2498;
  cVar1 = FUN_0041bc20(iVar2);
  if (cVar1 != '\0') {
    if ((&DAT_0071d890)[unaff_ESI] != 0) {
      FUN_00419f50(unaff_ESI,2);
    }
    *(undefined1 *)(param_1 + 0x2499 + unaff_ESI * 8) = 0;
    *(undefined1 *)(unaff_ESI + 0x25d8 + param_1) = 1;
  }
  cVar1 = FUN_0041bc20(iVar2);
  if (cVar1 != '\0') {
    if ((&DAT_0071d890)[unaff_ESI] != 0) {
      FUN_00419f50(unaff_ESI,0);
    }
    *(undefined1 *)(param_1 + 0x2498 + unaff_ESI * 8) = 0;
    *(undefined1 *)(unaff_ESI + 0x25da + param_1) = 1;
  }
  if ((&DAT_0071d89c)[unaff_ESI] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
    return;
  }
  if (*(char *)(unaff_ESI + 0x2220 + param_1) != '\0') {
    return;
  }
  if ((&DAT_0071d890)[unaff_ESI] == 0) {
    return;
  }
  cVar1 = FUN_0041bc20(iVar2);
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + 0x2bf8 + unaff_ESI * 4) == param_2) {
      return;
    }
    iVar2 = EZWheel__UpdateConditionForce
                      (iVar2,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                       (&DAT_0071d890)[unaff_ESI],0,4,1,0,0,-param_2,-param_2,10000,10000,0,0);
    if (iVar2 < 0) {
      return;
    }
    *(int *)(param_1 + 0x2bf8 + unaff_ESI * 4) = param_2;
    return;
  }
  if (*(int *)(unaff_ESI * 0x20 + 0x24b0 + param_1) == 0) {
    iVar3 = EZWheel__CreateConditionEffect
                      (unaff_ESI,&DAT_0071d89c + unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                       (&DAT_0071d890)[unaff_ESI],0,4,1,0,0,-param_2,-param_2,10000,10000,0,0,
                       &DAT_006a6e50);
  }
  else {
    if (*(int *)(param_1 + 0x2bf8 + unaff_ESI * 4) == param_2) goto LAB_0041b0cd;
    iVar3 = EZWheel__UpdateConditionForce
                      (iVar2,unaff_ESI,0x12,0xffffffff,0,10000,0xffffffff,0,
                       (&DAT_0071d890)[unaff_ESI],0,4,1,0,0,-param_2,-param_2,10000,10000,0,0);
  }
  if (-1 < iVar3) {
    *(int *)(param_1 + 0x2bf8 + unaff_ESI * 4) = param_2;
  }
LAB_0041b0cd:
  EZWheel__StartEffect(iVar2,unaff_ESI);
  return;
}


// ==== 0x41b150 FUN_0041b150

void FUN_0041b150(int param_1)

{
  char cVar1;
  int in_EAX;
  
  if ((&DAT_0071d890)[in_EAX] != 0) {
    cVar1 = FUN_0041bc20(param_1 + 0x2498);
    if (cVar1 != '\0') {
      EZWheel__StopEffect(in_EAX);
    }
    if (*(char *)(in_EAX + 0x25d8 + param_1) != '\0') {
      FUN_0041a6c0(param_1);
      *(undefined1 *)(param_1 + 0x2499 + in_EAX * 8) = 1;
      *(undefined1 *)(in_EAX + 0x25d8 + param_1) = 0;
    }
    if (*(char *)(in_EAX + 0x25da + param_1) != '\0') {
      FUN_0041a250(param_1,*(undefined4 *)(param_1 + (in_EAX * 3 + 0xae9) * 4),
                   *(undefined4 *)(param_1 + 0x2ba8 + in_EAX * 0xc));
      *(undefined1 *)(param_1 + 0x2498 + in_EAX * 8) = 1;
      *(undefined1 *)(in_EAX + 0x25da + param_1) = 0;
    }
  }
  return;
}


// ==== 0x41b210 FUN_0041b210

void FUN_0041b210(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  undefined *local_8;
  
  local_8 = (undefined *)0x0;
  if (0x96 < param_4) {
    param_4 = 0x96;
  }
  puVar2 = &DAT_0071d89c + in_EAX;
  if ((&DAT_0071d89c)[in_EAX] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if ((*(char *)(in_EAX + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[in_EAX] != 0)) {
    switch(param_2) {
    case 0:
      local_8 = &DAT_006a6ea0;
      break;
    case 1:
      local_8 = &DAT_006a6eb0;
      break;
    case 2:
      local_8 = &DAT_006a6e90;
      break;
    case 3:
      local_8 = &DAT_006a6e80;
      break;
    case 4:
      local_8 = &DAT_006a6e70;
    }
    iVar1 = param_1 + 0x2538;
    cVar3 = FUN_0041bc20(iVar1);
    if (cVar3 == '\0') {
      if (*(int *)(in_EAX * 0x20 + 0x2554 + param_1) == 0) {
        iVar5 = EZWheel__CreatePeriodicEffect
                          (in_EAX,puVar2,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[in_EAX],0,4,1,0,param_3,0,0,param_4 * 1000,0,0,0,0,0,
                           local_8);
        if (-1 < iVar5) {
          iVar5 = param_1 + in_EAX * 0xc;
          *(int *)(iVar5 + 0x2c00) = param_2;
          *(undefined4 *)(param_1 + (in_EAX * 3 + 0xb01) * 4) = param_3;
          *(int *)(iVar5 + 0x2c08) = param_4;
        }
      }
      else {
        cVar3 = FUN_0041b630(param_3,param_4);
        if (cVar3 == '\0') {
          iVar5 = param_1 + in_EAX * 0xc;
          if (param_2 == *(int *)(iVar5 + 0x2c00)) {
            iVar4 = EZWheel__UpdatePeriodicForce
                              (in_EAX,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[in_EAX],0
                               ,4,1,0,param_3,0,0,param_4 * 1000,0,0,0,0,0);
          }
          else {
            EZWheel__UnloadEffect(in_EAX);
            iVar4 = EZWheel__CreatePeriodicEffect
                              (in_EAX,puVar2,0x12,0xffffffff,0,10000,0xffffffff,0,
                               (&DAT_0071d890)[in_EAX],0,4,1,0,param_3,0,0,param_4 * 1000,0,0,0,0,0,
                               local_8);
          }
          if (-1 < iVar4) {
            *(int *)(iVar5 + 0x2c00) = param_2;
            *(undefined4 *)(param_1 + (in_EAX * 3 + 0xb01) * 4) = param_3;
            *(int *)(iVar5 + 0x2c08) = param_4;
          }
        }
      }
      EZWheel__StartEffect(iVar1,in_EAX);
      return;
    }
    cVar3 = FUN_0041b630(param_3,param_4);
    if (cVar3 == '\0') {
      iVar5 = param_1 + in_EAX * 0xc;
      if (param_2 == *(int *)(iVar5 + 0x2c00)) {
        iVar4 = EZWheel__UpdatePeriodicForce
                          (in_EAX,0x12,0xffffffff,0,10000,0xffffffff,0,(&DAT_0071d890)[in_EAX],0,4,1
                           ,0,param_3,0,0,param_4 * 1000,0,0,0,0,0);
      }
      else {
        EZWheel__UnloadEffect(in_EAX);
        iVar4 = EZWheel__CreatePeriodicEffect
                          (in_EAX,puVar2,0x12,0xffffffff,0,10000,0xffffffff,0,
                           (&DAT_0071d890)[in_EAX],0,4,1,0,param_3,0,0,param_4 * 1000,0,0,0,0,0,
                           local_8);
        EZWheel__StartEffect(iVar1,in_EAX);
      }
      if (-1 < iVar4) {
        *(int *)(iVar5 + 0x2c00) = param_2;
        *(undefined4 *)(param_1 + (in_EAX * 3 + 0xb01) * 4) = param_3;
        *(int *)(iVar5 + 0x2c08) = param_4;
        return;
      }
    }
  }
  return;
}


// ==== 0x41b5f0 FUN_0041b5f0

void __fastcall FUN_0041b5f0(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (((&DAT_0071d890)[unaff_ESI] != 0) && (cVar1 = FUN_0041bc20(param_1 + 0x2538), cVar1 != '\0'))
  {
    EZWheel__StopEffect(unaff_ESI);
  }
  return;
}


// ==== 0x41b630 FUN_0041b630

undefined4 __fastcall FUN_0041b630(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int in_EAX;
  int unaff_EDI;
  
  if (((*(int *)(param_2 + 0x2c00 + in_EAX * 0xc) == unaff_EDI) &&
      (*(int *)(param_2 + (in_EAX * 3 + 0xb01) * 4) == param_3)) &&
     (*(int *)(param_2 + in_EAX * 0xc + 0x2c08) == param_4)) {
    return 1;
  }
  return 0;
}


// ==== 0x41b670 FUN_0041b670

void FUN_0041b670(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  
  if ((&DAT_0071d89c)[in_EAX] == 0) {
    EZWheel__DebugLog("ERROR: trying to play a force on channel %d but no");
    EZWheel__DebugLog("wheel/joystick opened.\n");
  }
  else if ((*(char *)(in_EAX + 0x2220 + param_1) == '\0') && ((&DAT_0071d890)[in_EAX] != 0)) {
    iVar1 = param_1 + 0x2498;
    *(undefined1 *)(in_EAX + 0x2220 + param_1) = 1;
    cVar3 = FUN_0041bc20(iVar1);
    if (cVar3 != '\0') {
      if ((&DAT_0071d890)[in_EAX] != 0) {
        cVar3 = FUN_0041bc20(iVar1);
        if (cVar3 != '\0') {
          EZWheel__StopEffect(in_EAX);
        }
      }
      *(undefined1 *)(param_1 + 0x25dc + in_EAX * 10) = 1;
    }
    cVar3 = FUN_0041bc20(param_1 + 0x24e8);
    if (cVar3 != '\0') {
      FUN_0041a680();
      *(undefined1 *)(param_1 + 0x25dd + in_EAX * 10) = 1;
    }
    cVar3 = FUN_0041bc20(iVar1);
    if (cVar3 != '\0') {
      if ((&DAT_0071d890)[in_EAX] != 0) {
        cVar3 = FUN_0041bc20(iVar1);
        if (cVar3 != '\0') {
          EZWheel__StopEffect(in_EAX);
        }
      }
      *(undefined1 *)(param_1 + 0x25de + in_EAX * 10) = 1;
    }
    iVar2 = param_1 + 0x2538;
    cVar3 = FUN_0041bc20(iVar2);
    if (cVar3 != '\0') {
      FUN_0041ace0();
      *(undefined1 *)(param_1 + 0x25e1 + in_EAX * 10) = 1;
    }
    cVar3 = FUN_0041bc20(iVar2);
    if (cVar3 != '\0') {
      FUN_0041af00();
      *(undefined1 *)(param_1 + 0x25e2 + in_EAX * 10) = 1;
    }
    cVar3 = FUN_0041bc20(iVar1);
    if (cVar3 != '\0') {
      FUN_0041b150(param_1);
      *(undefined1 *)(param_1 + 0x25e3 + in_EAX * 10) = 1;
    }
    cVar3 = FUN_0041bc20(iVar2);
    if (cVar3 != '\0') {
      FUN_0041b5f0();
      *(undefined1 *)(param_1 + (in_EAX * 5 + 0x12f2) * 2) = 1;
      return;
    }
  }
  return;
}


// ==== 0x41b824 FUN_0041b824

void FUN_0041b824(void)

{
  func_0x0041bd37();
  return;
}


// ==== 0x41b830 FUN_0041b830

void FUN_0041b830(int param_1)

{
  char *pcVar1;
  int iVar2;
  int in_EAX;
  
  if (((&DAT_0071d890)[in_EAX] != 0) && (*(char *)(in_EAX + 0x2220 + param_1) == '\x01')) {
    iVar2 = param_1 + in_EAX * 10;
    pcVar1 = (char *)(iVar2 + 0x25dc);
    *(undefined1 *)(in_EAX + 0x2220 + param_1) = 0;
    if (*pcVar1 == '\x01') {
      FUN_0041a250(param_1,*(undefined4 *)(param_1 + (in_EAX * 3 + 0xae9) * 4),
                   *(undefined4 *)(param_1 + 0x2ba8 + in_EAX * 0xc));
    }
    if (*(char *)(iVar2 + 0x25dd) == '\x01') {
      FUN_0041a640(in_EAX,*(undefined4 *)(param_1 + 0x2bb8 + in_EAX * 8));
    }
    if (*(char *)(iVar2 + 0x25de) == '\x01') {
      FUN_0041a6c0(param_1);
    }
    if (*(char *)(iVar2 + 0x25e1) == '\x01') {
      FUN_0041ab00(param_1,*(undefined4 *)(param_1 + 0x2be8 + in_EAX * 4));
    }
    if (*(char *)(iVar2 + 0x25e2) == '\x01') {
      FUN_0041ad20(param_1,*(undefined4 *)(param_1 + 0x2bf0 + in_EAX * 4));
    }
    if (*(char *)(iVar2 + 0x25e3) == '\x01') {
      FUN_0041af40(param_1,*(undefined4 *)(param_1 + 0x2bf8 + in_EAX * 4));
    }
    if (*(char *)(param_1 + (in_EAX * 5 + 0x12f2) * 2) == '\x01') {
      FUN_0041b210(param_1,*(undefined4 *)(param_1 + in_EAX * 0xc + 0x2c00),
                   *(undefined4 *)(param_1 + (in_EAX * 3 + 0xb01) * 4),
                   *(undefined4 *)(param_1 + 0x2c08 + in_EAX * 0xc));
    }
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(iVar2 + 0x25e0) = 0;
    *(undefined2 *)(iVar2 + 0x25e4) = 0;
  }
  return;
}


// ==== 0x41b970 FUN_0041b970

void FUN_0041b970(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = &DAT_0071d89c;
  do {
    if (*piVar3 != 0) {
      iVar2 = EZWheel__GetOverallGain(param_1 + 0x2448);
      if (iVar2 != 100) {
        EZWheel__SetOverallGain(param_1 + 0x2448,piVar3);
      }
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x71d8a4);
  piVar3 = (int *)(param_1 + 0x24f8);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = (int *)(param_1 + 0x2548);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = (int *)(param_1 + 0x2598);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = (int *)(param_1 + 0x24a8);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_004198b0(param_1 + 0x2224);
  return;
}


// ==== 0x41ba80 FUN_0041ba80

void __fastcall FUN_0041ba80(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(param_2 + 0x10);
  iVar3 = 2;
  do {
    iVar1 = 0;
    do {
      *(undefined1 *)(param_2 + iVar1) = 0;
      *puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < 8);
    param_2 = param_2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x41bab0 EZWheel::StartEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall EZWheel__StartEffect(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = in_EAX + param_3 * 8;
  if (*(int *)(param_2 + 0x10 + iVar1 * 4) == 0) {
    EZWheel__DebugLog("ERROR: Trying to start force effect on channel %d but we have an invalid effectid\n"
                      ,param_3);
    iVar3 = 0;
  }
  else {
    iVar3 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1);
    if (-1 < iVar3) {
      piVar2 = *(int **)(param_2 + 0x10 + iVar1 * 4);
      iVar3 = (**(code **)(*piVar2 + 0x1c))(piVar2,1,0);
      if (iVar3 < 0) {
        EZWheel__DebugLog("ERROR: Failed to start force effect on channel %d\n",param_3);
        return iVar3;
      }
      *(undefined1 *)(iVar1 + param_2) = 1;
      return iVar3;
    }
  }
  return iVar3;
}


// ==== 0x41bb30 EZWheel::StopEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall EZWheel__StopEffect(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int unaff_EDI;
  
  iVar1 = in_EAX + param_2 * 8;
  if (*(char *)(iVar1 + unaff_EDI) == '\0') {
    return 0;
  }
  if (*(int *)(unaff_EDI + 0x10 + iVar1 * 4) != 0) {
    (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1);
    piVar2 = *(int **)(unaff_EDI + 0x10 + iVar1 * 4);
    iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2);
    if (iVar3 < 0) {
      EZWheel__DebugLog("ERROR: Failed to stop force effect on channel %d\n",param_2);
      return iVar3;
    }
    *(undefined1 *)(iVar1 + unaff_EDI) = 0;
    return iVar3;
  }
  EZWheel__DebugLog("ERROR: Trying to stop force effect on channel %d but we have an invalid effectid\n"
                    ,param_2);
  return 0;
}


// ==== 0x41bbb0 EZWheel::UnloadEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall EZWheel__UnloadEffect(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int unaff_EDI;
  
  iVar1 = in_EAX + param_2 * 8;
  if (*(int *)(unaff_EDI + 0x10 + iVar1 * 4) == 0) {
    EZWheel__DebugLog("ERROR: Trying to unload force effect on channel %d but we have an invalid effectid\n"
                      ,param_2);
    return 0;
  }
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1);
  piVar2 = *(int **)(unaff_EDI + 0x10 + iVar1 * 4);
  iVar3 = (**(code **)(*piVar2 + 0x2c))(piVar2);
  if (iVar3 < 0) {
    EZWheel__DebugLog("ERROR: Failed to unload force effect on channel %d\n",param_2);
    return iVar3;
  }
  *(undefined1 *)(iVar1 + unaff_EDI) = 0;
  *(undefined4 *)(unaff_EDI + 0x10 + iVar1 * 4) = 0;
  return iVar3;
}


// ==== 0x41bc20 FUN_0041bc20

uint __thiscall FUN_0041bc20(int param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  
  piVar1 = *(int **)(param_2 + 0x10 + (in_EAX + param_1 * 8) * 4);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if (-1 < (int)uVar2) {
      return (uint)(&stack0x00000000 == (undefined1 *)0xfffffffd);
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x41bc60 EZWheel::SetOverallGain

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void __thiscall EZWheel__SetOverallGain(uint param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  if (100 < param_1) {
    param_1 = 100;
  }
  local_4 = (param_1 * 10000) / 100;
  local_14 = 0x14;
  local_10 = 0x10;
  local_c = 0;
  local_8 = 0;
  EZWheel__DebugLog("Setting gain to %d\n",param_1);
  piVar1 = (int *)*param_3;
  if (piVar1 != (int *)0x0) {
    param_3 = (int *)(**(code **)(*piVar1 + 0x18))(piVar1,7,&local_14);
  }
  if ((int)param_3 < 0) {
    EZWheel__DebugLog("ERROR: Failed to set overall force gain\n");
  }
  return;
}


// ==== 0x41bcf0 EZWheel::GetOverallGain

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

uint EZWheel__GetOverallGain(void)

{
  int *piVar1;
  int *in_EAX;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int iStack_4;
  
  piVar1 = (int *)*in_EAX;
  local_14 = 0x14;
  local_10 = 0x10;
  local_c = 0;
  local_8 = 0;
  if (piVar1 != (int *)0x0) {
    local_18 = (**(code **)(*piVar1 + 0x14))(piVar1,7,&local_14);
  }
  if (-1 < local_18) {
    return (uint)(iStack_4 * 100) / 10000;
  }
  EZWheel__DebugLog("ERROR: Failed to get overall force gain\n");
  return 0xffffffff;
}


// ==== 0x41bd60 FUN_0041bd60

void FUN_0041bd60(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(in_EAX + 0x10);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x41bda0 EZWheel::CreateConstantEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall
EZWheel__CreateConstantEffect
          (int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
          undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
          undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  piVar1 = (int *)(param_1 + 0x10 + (in_EAX + param_2 * 8) * 4);
  iVar4 = 0;
  if (*piVar1 != 0) {
    EZWheel__UnloadEffect(param_2);
  }
  piVar2 = (int *)*param_3;
  if (piVar2 != (int *)0x0) {
    local_5c = param_11;
    local_54 = param_13;
    local_58 = param_12;
    param_3 = (int *)param_15;
    local_50 = param_14;
    local_44 = param_18;
    local_48 = param_17;
    local_3c = param_20;
    local_40 = param_19;
    puVar5 = local_38;
    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    local_38[2] = param_5;
    local_28 = param_7;
    local_20 = param_9;
    local_38[1] = param_4;
    local_38[3] = param_6;
    local_18 = &local_5c;
    local_24 = param_8;
    local_10 = &local_4c;
    local_4 = param_16;
    local_1c = param_10;
    local_14 = &local_54;
    local_8 = &param_3;
    local_4c = 0x14;
    local_38[0] = 0x38;
    local_c = 4;
    iVar4 = (**(code **)(*piVar2 + 0x48))(piVar2,param_21,local_38,piVar1,0);
    if (iVar4 < 0) {
      EZWheel__DebugLog("ERROR: Failed to create constant effect on channel %d\n",param_2);
      return iVar4;
    }
  }
  iVar3 = -0x7fffbffb;
  if (*piVar1 != 0) {
    iVar3 = iVar4;
  }
  return iVar3;
}


// ==== 0x41bf20 EZWheel::UpdateConstantForce

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __fastcall
EZWheel__UpdateConstantForce
          (undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
          undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
          undefined4 param_18,undefined4 param_19,undefined4 param_20)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  iVar2 = param_3;
  piVar1 = *(int **)(param_2 + 0x10 + (in_EAX + param_3 * 8) * 4);
  iVar3 = 0;
  if (piVar1 != (int *)0x0) {
    local_5c = param_11;
    local_58 = param_12;
    local_54 = param_13;
    local_50 = param_14;
    param_3 = param_15;
    local_48 = param_17;
    local_44 = param_18;
    local_40 = param_19;
    local_3c = param_20;
    puVar4 = local_38;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_38[2] = param_5;
    local_28 = param_7;
    local_38[1] = param_4;
    local_20 = param_9;
    local_38[3] = param_6;
    local_24 = param_8;
    local_18 = &local_5c;
    local_10 = &local_4c;
    local_1c = param_10;
    local_14 = &local_54;
    local_4 = param_16;
    local_8 = &param_3;
    local_4c = 0x14;
    local_38[0] = 0x38;
    local_c = 4;
    iVar3 = (**(code **)(*piVar1 + 0x18))(piVar1,local_38,0x140);
    if (iVar3 < 0) {
      EZWheel__DebugLog("ERROR: Failed to update constant force on channel %d\n",iVar2);
    }
  }
  return iVar3;
}


// ==== 0x41c060 FUN_0041c060

void FUN_0041c060(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(in_EAX + 0x10);
  iVar2 = 2;
  do {
    iVar4 = 8;
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x41c070 EZWheel::CreateConditionEffect

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int __thiscall
EZWheel__CreateConditionEffect
          (int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10,
          undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,
          undefined4 param_15,undefined4 param_16,undefined4 param_17,undefined4 param_18,
          undefined4 param_19,undefined4 param_20,undefined4 param_21,undefined4 param_22)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
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
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  piVar1 = (int *)(param_1 + 0x10 + (in_EAX + param_2 * 8) * 4);
  iVar3 = 0;
  if (*piVar1 != 0) {
    EZWheel__UnloadEffect(param_2);
  }
  param_3 = (int *)*param_3;
  if (param_3 != (int *)0x0) {
    local_78 = param_11;
    local_74 = param_12;
    local_70 = param_13;
    local_6c = param_14;
    local_68 = param_15;
    local_64 = param_16;
    local_60 = param_17;
    local_5c = param_18;
    local_58 = param_19;
    local_54 = param_20;
    local_4c = 8000;
    local_48 = 8000;
    local_44 = 8000;
    local_40 = 8000;
    puVar4 = local_38;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_38[1] = param_4;
    local_38[3] = param_6;
    local_24 = param_8;
    local_18 = &local_78;
    local_38[2] = param_5;
    local_c = param_10 * 0x18;
    local_28 = param_7;
    local_4 = param_21;
    local_20 = param_9;
    local_14 = &local_70;
    local_8 = &local_68;
    local_50 = 0;
    local_3c = 500;
    local_38[0] = 0x38;
    local_1c = param_10;
    local_10 = 0;
    iVar3 = (**(code **)(*param_3 + 0x48))(param_3,param_22,local_38,piVar1,0);
    if (iVar3 < 0) {
      EZWheel__DebugLog("ERROR: Failed to create condition effect on channel %d\n",local_10);
      return iVar3;
    }
  }
  iVar2 = -0x7fffbffb;
  if (*piVar1 != 0) {
    iVar2 = iVar3;
  }
  return iVar2;
}


// ==== 0x41c240 EZWheel::UpdateConditionForce

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int EZWheel__UpdateConditionForce
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,
              undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
              undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
              undefined4 param_18,undefined4 param_19,undefined4 param_20)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
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
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)(param_1 + 0x10 + (in_EAX + param_2 * 8) * 4);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    local_78 = param_10;
    local_74 = param_11;
    local_70 = param_12;
    local_6c = param_13;
    local_68 = param_14;
    local_64 = param_15;
    local_60 = param_16;
    local_5c = param_17;
    local_58 = param_18;
    local_54 = param_19;
    local_4c = 8000;
    local_48 = 8000;
    local_44 = 8000;
    local_40 = 8000;
    puVar3 = local_38;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_38[1] = param_3;
    local_38[3] = param_5;
    local_24 = param_7;
    local_38[2] = param_4;
    local_18 = &local_78;
    local_28 = param_6;
    local_c = param_9 * 0x18;
    local_20 = param_8;
    local_14 = &local_70;
    local_4 = param_20;
    local_8 = &local_68;
    local_50 = 0;
    local_3c = 500;
    local_38[0] = 0x38;
    local_1c = param_9;
    local_10 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,local_38,0x140);
    if (iVar2 < 0) {
      EZWheel__DebugLog("ERROR: Failed to update condition force on channel %d\n",local_4);
    }
  }
  return iVar2;
}


// ==== 0x41c3c0 FUN_0041c3c0

void FUN_0041c3c0(void)

{
  DAT_00736224 = _malloc(1);
  return;
}


// ==== 0x41c3d0 FUN_0041c3d0

void FUN_0041c3d0(void)

{
  void *_Memory;
  void *_Memory_00;
  
  if (DAT_00736228 != (void *)0x0) {
    Settings__Save();
  }
  _Memory_00 = DAT_00736228;
  _Memory = DAT_00736224;
  if (DAT_00736224 != (void *)0x0) {
    if (DAT_00736228 != (void *)0x0) {
      FUN_00404cc0(DAT_00736228);
      _free(_Memory_00);
    }
    _free(_Memory);
    DAT_00736224 = (void *)0x0;
  }
  return;
}


// ==== 0x41c420 Config::OpenCfgFile

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Config__OpenCfgFile(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  HANDLE hFindFile;
  void *pvVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  _WIN32_FIND_DATAA _Stack_14c;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pvVar4 = DAT_00736228;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00685e9e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00736228 != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_00404cc0(DAT_00736228);
    _free(pvVar4);
    DAT_00736228 = (void *)0x0;
  }
  if (param_1 != (char *)0x0) {
    SHGetFolderPathA(0,0x8023,0,0,&DAT_00736230);
    pcVar3 = (char *)0x73622f;
    do {
      pcVar7 = pcVar3;
      pcVar3 = pcVar7 + 1;
    } while (pcVar7[1] != '\0');
    builtin_strncpy(pcVar7 + 1,"\\NFS Underground\\",0x12);
    CreateDirectoryA(&DAT_00736230,(LPSECURITY_ATTRIBUTES)0x0);
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar7 = (char *)0x73622f;
    do {
      pcVar6 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = param_1;
    for (uVar5 = (uint)((int)pcVar3 - (int)param_1) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = (int)pcVar3 - (int)param_1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    puVar2 = (undefined4 *)0x73622f;
    do {
      puVar8 = puVar2;
      puVar2 = (undefined4 *)((int)puVar8 + 1);
    } while (*(char *)((int)puVar8 + 1) != '\0');
    *(undefined4 *)((int)puVar8 + 1) = 0x6766632e;
    *(undefined1 *)((int)puVar8 + 5) = 0;
    hFindFile = FindFirstFileA(&DAT_00736230,&_Stack_14c);
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
      pvVar4 = _malloc(0x44);
      uStack_4 = 0;
      if (pvVar4 == (void *)0x0) {
        DAT_00736228 = (void *)0x0;
      }
      else {
        DAT_00736228 = (void *)FUN_00404bd0(&DAT_00736230,0);
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x41c590 FUN_0041c590

void FUN_0041c590(int param_1,ushort param_2,undefined4 param_3,undefined4 param_4,char *param_5)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char local_c [12];
  
  pcVar3 = param_5;
  __itoa(param_1,param_5,10);
  pcVar8 = pcVar3 + -1;
  do {
    pcVar7 = pcVar8 + 1;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar7 != '\0');
  pcVar8[0] = '-';
  pcVar8[1] = '\0';
  __itoa((uint)param_2,local_c,10);
  pcVar8 = local_c;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar4 = (int)pcVar8 - (int)local_c;
  pcVar8 = pcVar3 + -1;
  do {
    pcVar7 = pcVar8 + 1;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar7 != '\0');
  pcVar7 = local_c;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  iVar6 = 0;
  do {
    pcVar8 = pcVar3 + -1;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    bVar2 = *(byte *)((int)&param_3 + iVar6);
    pcVar8[0] = '-';
    pcVar8[1] = '\0';
    __itoa((uint)bVar2,local_c,10);
    pcVar8 = local_c;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar8 - (int)local_c;
    pcVar8 = pcVar3 + -1;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = local_c;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    iVar6 = iVar6 + 1;
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
  } while (iVar6 < 8);
  return;
}


// ==== 0x41c680 Settings::Load

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Settings__Load(void)

{
  undefined **ppuVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined **ppuVar9;
  int iVar10;
  undefined2 *puVar11;
  float10 fVar12;
  char local_100 [256];
  
  if ((DAT_00736228 != 0) && (Opt__Read(&DAT_0078a478), PTR_DAT_00700ec4 != (undefined *)0x0)) {
    ppuVar9 = &PTR_DAT_00700ec4;
    iVar10 = DAT_00736228;
    do {
      *(undefined4 *)(iVar10 + 0x3c) = 0;
      *(undefined4 *)(iVar10 + 0x40) = 0;
      pcVar8 = ppuVar9[-1];
      iVar10 = -(int)pcVar8;
      do {
        cVar2 = *pcVar8;
        pcVar8[(int)(local_100 + iVar10)] = cVar2;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      puVar11 = (undefined2 *)&stack0xfffffeff;
      do {
        pcVar8 = (char *)((int)puVar11 + 1);
        puVar11 = (undefined2 *)((int)puVar11 + 1);
      } while (*pcVar8 != '\0');
      *puVar11 = 0x3a;
      iVar6 = FUN_004051f0(local_100);
      iVar5 = DAT_00736228;
      iVar10 = DAT_00736228;
      if (((iVar6 != 0) && (*(int *)(DAT_00736228 + 0x3c) != 0)) &&
         (*(int *)(DAT_00736228 + 0x40) != *(int *)(DAT_00736228 + 0x3c) + 0x3c)) {
        puVar3 = ppuVar9[1];
        if (puVar3 == (undefined *)0x0) {
          uVar7 = FUN_00405260();
          *(undefined4 *)*ppuVar9 = uVar7;
          iVar10 = DAT_00736228;
        }
        else if (puVar3 == (undefined *)0x1) {
          fVar12 = (float10)FUN_00405300();
          *(float *)*ppuVar9 = (float)fVar12;
          iVar10 = DAT_00736228;
        }
        else if (puVar3 == (undefined *)0x2) {
          if ((*(int *)(DAT_00736228 + 0x3c) == 0) ||
             (*(int *)(DAT_00736228 + 0x40) == *(int *)(DAT_00736228 + 0x3c) + 0x3c)) {
            uVar7 = FUN_004051a0();
            FUN_00404ab0("Not enough arguments %s\n",uVar7);
          }
          iVar10 = DAT_00736228;
          puVar4 = *(undefined4 **)(iVar5 + 0x40);
          *(undefined4 *)(iVar5 + 0x40) = *puVar4;
          *ppuVar9 = (undefined *)puVar4[2];
        }
      }
      ppuVar1 = ppuVar9 + 3;
      ppuVar9 = ppuVar9 + 3;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  RenderOptions_ClampToLimits();
  return;
}


// ==== 0x41c7a0 Settings::Save

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Settings__Save(void)

{
  undefined **ppuVar1;
  int iVar2;
  char cVar3;
  FILE *_File;
  char *pcVar4;
  size_t sVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  char local_108 [260];
  
  if (DAT_00736230 != '\0') {
    Opt__Write();
    _File = (FILE *)_fopen(&DAT_00736230);
    if (_File != (FILE *)0x0) {
      if (PTR_DAT_00700ec4 != (undefined *)0x0) {
        ppuVar6 = &PTR_DAT_00700ec4;
        do {
          pcVar4 = ppuVar6[-1];
          iVar2 = -(int)pcVar4;
          do {
            cVar3 = *pcVar4;
            pcVar4[(int)(local_108 + iVar2)] = cVar3;
            pcVar4 = pcVar4 + 1;
          } while (cVar3 != '\0');
          puVar9 = (undefined2 *)&stack0xfffffef7;
          do {
            puVar8 = puVar9;
            puVar9 = (undefined2 *)((int)puVar8 + 1);
          } while (*(char *)((int)puVar8 + 1) != '\0');
          *(undefined2 *)((int)puVar8 + 1) = 0x203a;
          pcVar4 = local_108;
          *(undefined1 *)((int)puVar8 + 3) = 0;
          do {
            cVar3 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar3 != '\0');
          sVar5 = _fwrite(local_108,1,(int)pcVar4 - (int)(local_108 + 1),_File);
          if (sVar5 != (int)pcVar4 - (int)(local_108 + 1)) {
            FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5);
          }
          puVar7 = ppuVar6[1];
          if (puVar7 == (undefined *)0x0) {
            __itoa(*(int *)*ppuVar6,local_108,10);
          }
          else if (puVar7 == (undefined *)0x1) {
            _sprintf(local_108,&DAT_006cc464,(double)*(float *)*ppuVar6);
          }
          else if (puVar7 == (undefined *)0x2) {
            pcVar4 = *ppuVar6;
            iVar2 = -(int)pcVar4;
            do {
              cVar3 = *pcVar4;
              pcVar4[(int)(local_108 + iVar2)] = cVar3;
              pcVar4 = pcVar4 + 1;
            } while (cVar3 != '\0');
          }
          puVar9 = (undefined2 *)&stack0xfffffef7;
          do {
            pcVar4 = (char *)((int)puVar9 + 1);
            puVar9 = (undefined2 *)((int)puVar9 + 1);
          } while (*pcVar4 != '\0');
          pcVar4 = local_108;
          *puVar9 = 10;
          do {
            cVar3 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar3 != '\0');
          sVar5 = _fwrite(local_108,1,(int)pcVar4 - (int)(local_108 + 1),_File);
          if (sVar5 != (int)pcVar4 - (int)(local_108 + 1)) {
            FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5);
          }
          ppuVar1 = ppuVar6 + 3;
          ppuVar6 = ppuVar6 + 3;
        } while (*ppuVar1 != (undefined *)0x0);
      }
      pcVar4 = local_108;
      local_108[0] = '\n';
      local_108[1] = '\0';
      do {
        cVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar3 != '\0');
      sVar5 = _fwrite(local_108,1,(int)pcVar4 - (int)(local_108 + 1),_File);
      if (sVar5 != (int)pcVar4 - (int)(local_108 + 1)) {
        FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5);
      }
      pcVar4 = local_108;
      do {
        cVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar3 != '\0');
      sVar5 = _fwrite(local_108,1,(int)pcVar4 - (int)(local_108 + 1),_File);
      if (sVar5 != (int)pcVar4 - (int)(local_108 + 1)) {
        FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5);
      }
      puVar7 = &DAT_0078daa8;
      do {
        if ((*(int *)(puVar7 + 0x130) != -1) &&
           (cVar3 = InputDevice__IsKeyboardType(), cVar3 == '\0')) {
          FUN_0041c9e0(_File);
        }
        puVar7 = puVar7 + 0x270;
      } while ((int)puVar7 < 0x78e948);
      _fclose(_File);
    }
  }
  return;
}


// ==== 0x41c9e0 FUN_0041c9e0

void FUN_0041c9e0(FILE *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  int *piVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int *local_58;
  undefined1 uStack_45;
  undefined2 local_44;
  undefined1 local_42 [66];
  
  puVar2 = (undefined4 *)InputDevice__GetInstanceGuid();
  FUN_0041c590(*puVar2,puVar2[1],puVar2[2],puVar2[3],&local_44);
  puVar9 = (undefined2 *)&uStack_45;
  do {
    puVar8 = puVar9;
    puVar9 = (undefined2 *)((int)puVar8 + 1);
  } while (*(char *)((int)puVar8 + 1) != '\0');
  *(undefined2 *)((int)puVar8 + 1) = 0x203a;
  pcVar3 = (char *)&local_44;
  *(undefined1 *)((int)puVar8 + 3) = 0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
  if (param_1 == (FILE *)0x0) {
    FUN_00404ab0("NULL file handle passed to FWriteSafe");
  }
  sVar5 = _fwrite(&local_44,1,sVar4,param_1);
  if (sVar5 != sVar4) {
    FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
  }
  iVar6 = 0;
  local_58 = (int *)(param_2 + 0x254);
  local_44 = 0x20;
  do {
    __itoa(local_58[-4],(char *)&local_44,10);
    puVar9 = (undefined2 *)&uStack_45;
    do {
      pcVar3 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar3 != '\0');
    pcVar3 = (char *)&local_44;
    *puVar9 = 0x20;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
    if (param_1 == (FILE *)0x0) {
      FUN_00404ab0("NULL file handle passed to FWriteSafe");
    }
    sVar5 = _fwrite(&local_44,1,sVar4,param_1);
    if (sVar5 != sVar4) {
      FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
    }
    __itoa(*local_58,(char *)&local_44,10);
    puVar9 = (undefined2 *)&uStack_45;
    do {
      pcVar3 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar3 != '\0');
    pcVar3 = (char *)&local_44;
    *puVar9 = 0x20;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
    if (param_1 == (FILE *)0x0) {
      FUN_00404ab0("NULL file handle passed to FWriteSafe");
    }
    sVar5 = _fwrite(&local_44,1,sVar4,param_1);
    if (sVar5 != sVar4) {
      FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
    }
    __itoa((uint)*(byte *)(param_2 + 0x264 + iVar6),(char *)&local_44,10);
    puVar9 = (undefined2 *)&uStack_45;
    do {
      pcVar3 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar3 != '\0');
    *puVar9 = 0x20;
    pcVar3 = (char *)&local_44;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
    if (param_1 == (FILE *)0x0) {
      FUN_00404ab0("NULL file handle passed to FWriteSafe");
    }
    sVar5 = _fwrite(&local_44,1,sVar4,param_1);
    if (sVar5 != sVar4) {
      FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
    }
    iVar6 = iVar6 + 1;
    local_58 = local_58 + 1;
  } while (iVar6 < 4);
  __itoa((uint)*(byte *)(param_2 + 0x268),(char *)&local_44,10);
  puVar9 = (undefined2 *)&uStack_45;
  do {
    pcVar3 = (char *)((int)puVar9 + 1);
    puVar9 = (undefined2 *)((int)puVar9 + 1);
  } while (*pcVar3 != '\0');
  pcVar3 = (char *)&local_44;
  *puVar9 = 0x20;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
  if (param_1 == (FILE *)0x0) {
    FUN_00404ab0("NULL file handle passed to FWriteSafe");
  }
  sVar5 = _fwrite(&local_44,1,sVar4,param_1);
  if (sVar5 != sVar4) {
    FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
  }
  piVar7 = (int *)(param_2 + 0x18);
  iVar6 = 0x20;
  do {
    __itoa(*piVar7,(char *)&local_44,10);
    puVar9 = (undefined2 *)&uStack_45;
    do {
      pcVar3 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar3 != '\0');
    pcVar3 = (char *)&local_44;
    *puVar9 = 0x20;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
    if (param_1 == (FILE *)0x0) {
      FUN_00404ab0("NULL file handle passed to FWriteSafe");
    }
    sVar5 = _fwrite(&local_44,1,sVar4,param_1);
    if (sVar5 != sVar4) {
      FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
    }
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  pcVar3 = (char *)&local_44;
  local_44 = 10;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sVar4 = (int)pcVar3 - ((int)&local_44 + 1);
  if (param_1 == (FILE *)0x0) {
    FUN_00404ab0("NULL file handle passed to FWriteSafe");
  }
  sVar5 = _fwrite(&local_44,1,sVar4,param_1);
  if (sVar5 != sVar4) {
    FUN_00404ab0("FWriteSafe failed.  Only wrote %d of %d bytes",sVar5,sVar4);
  }
  return;
}


// ==== 0x41cda0 FUN_0041cda0

undefined4
FUN_0041cda0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  char local_44 [68];
  
  iVar3 = DAT_00736228;
  if (DAT_00736228 != 0) {
    *(undefined4 *)(DAT_00736228 + 0x3c) = 0;
    *(undefined4 *)(iVar3 + 0x40) = 0;
    FUN_0041c590(param_1,param_2,param_3,param_4,local_44);
    puVar7 = (undefined2 *)&stack0xffffffbb;
    do {
      pcVar1 = (char *)((int)puVar7 + 1);
      puVar7 = (undefined2 *)((int)puVar7 + 1);
    } while (*pcVar1 != '\0');
    *puVar7 = 0x3a;
    iVar3 = FUN_004051f0(local_44);
    if (iVar3 != 0) {
      iVar3 = 0;
      puVar6 = (undefined4 *)(param_5 + 0x254);
      do {
        if (*(int *)(DAT_00736228 + 0x3c) == 0) {
          return 0;
        }
        if (*(int *)(DAT_00736228 + 0x40) == *(int *)(DAT_00736228 + 0x3c) + 0x3c) {
          return 0;
        }
        uVar4 = FUN_00405260();
        iVar2 = DAT_00736228;
        puVar6[-4] = uVar4;
        *(undefined1 *)(iVar3 + 0x264 + param_5) = 1;
        iVar5 = *(int *)(iVar2 + 0x3c);
        if (iVar5 == 0) {
          return 0;
        }
        if (*(int *)(iVar2 + 0x40) == iVar5 + 0x3c) {
          return 0;
        }
        uVar4 = FUN_00405260();
        iVar2 = DAT_00736228;
        *puVar6 = uVar4;
        iVar5 = *(int *)(iVar2 + 0x3c);
        if (iVar5 == 0) {
          return 0;
        }
        if (*(int *)(iVar2 + 0x40) == iVar5 + 0x3c) {
          return 0;
        }
        iVar5 = FUN_00405260();
        *(bool *)(iVar3 + 0x264 + param_5) = iVar5 != 0;
        iVar3 = iVar3 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar3 < 4);
      if ((*(int *)(DAT_00736228 + 0x3c) != 0) &&
         (*(int *)(DAT_00736228 + 0x40) != *(int *)(DAT_00736228 + 0x3c) + 0x3c)) {
        iVar3 = FUN_00405260();
        *(bool *)(param_5 + 0x268) = iVar3 != 0;
        *(bool *)(param_5 + 0x267) = iVar3 != 0;
        *(bool *)(param_5 + 0x266) = iVar3 == 0;
        *(bool *)(param_5 + 0x265) = iVar3 == 0;
        iVar3 = 0;
        puVar6 = (undefined4 *)(param_5 + 0x18);
        while ((*(int *)(DAT_00736228 + 0x3c) != 0 &&
               (*(int *)(DAT_00736228 + 0x40) != *(int *)(DAT_00736228 + 0x3c) + 0x3c))) {
          uVar4 = FUN_00405260();
          *puVar6 = uVar4;
          iVar3 = iVar3 + 1;
          puVar6 = puVar6 + 1;
          if (0x1f < iVar3) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== 0x41cf40 Profile::CreateNew

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

void Profile__CreateNew(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_007588d1 != '\0') {
    Ugd__Write(&DAT_0078a478,"auto");
    Settings__Save();
  }
  Player__Init(1);
  DAT_007677b0 = 0;
  DAT_007677b4 = 1;
  DAT_00758ad4 = 0;
  puVar2 = &DAT_00758ad8;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  CustomizationDB__Init(&DAT_00758c28,DAT_006f1da4);
  FUN_004ac220();
  Career__Reset();
  puVar2 = &DAT_007677b8;
  for (iVar1 = 0x294; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_007677ac = 0;
  Player__Init(1);
  DAT_007677b0 = 1;
  ProfileList__Touch(&DAT_0078a478,param_1);
  Ugd__Write(&DAT_0078a478,"auto");
  Config__OpenCfgFile(param_1);
  FUN_004aa670(0,1);
  Settings__Save();
  return;
}


// ==== 0x41d030 Profile::Load

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

void Profile__Load(void)

{
  undefined4 unaff_ESI;
  undefined *puVar1;
  
  if (DAT_007588d1 != '\0') {
    Ugd__Write(&DAT_0078a478,"auto");
    Settings__Save();
  }
  Player__Init(1);
  ProfileList__Touch(&DAT_0078a478,unaff_ESI);
  Ugd__Read(&DAT_0078a478);
  Config__OpenCfgFile();
  Settings__Load();
  puVar1 = &DAT_0078daa8;
  do {
    if (*(int *)(puVar1 + 0x130) != -1) {
      FUN_004064d0();
    }
    puVar1 = puVar1 + 0x270;
  } while ((int)puVar1 < 0x78e948);
  return;
}


// ==== 0x41d0b0 Profile::DeleteAndReloadCfg

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

bool Profile__DeleteAndReloadCfg(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = Profile__Delete(&DAT_0078a478,in_EAX);
  Config__OpenCfgFile(0);
  return iVar1 != 0;
}


// ==== 0x41d0d0 SaveSlot::Exists

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

bool __fastcall SaveSlot__Exists(undefined4 param_1,undefined4 param_2)

{
  HANDLE hFindFile;
  CHAR local_244 [260];
  _WIN32_FIND_DATAA local_140;
  
  Save__BuildPath(param_2,param_1,local_244);
  hFindFile = FindFirstFileA(local_244,&local_140);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
    return (((byte)local_140.dwFileAttributes & 0x10) != 0) != true;
  }
  return false;
}


// ==== 0x41d140 ProfileList::Load

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 ProfileList__Load(void)

{
  char cVar1;
  FILE *_File;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int *unaff_ESI;
  char *pcVar5;
  int iVar6;
  int iStack_240;
  undefined1 *puStack_23c;
  char cStack_21d;
  char acStack_21c [20];
  undefined1 local_208 [240];
  undefined1 auStack_118 [280];
  
  puStack_23c = local_208;
  iVar4 = 0;
  iStack_240 = 0;
  SHGetFolderPathA(0,0x23,0);
  pcVar3 = &cStack_21d;
  do {
    pcVar5 = pcVar3;
    pcVar3 = pcVar5 + 1;
  } while (pcVar5[1] != '\0');
  builtin_strncpy(pcVar5 + 1,"\\NFS Underground\\",0x12);
  _sprintf(auStack_118,"%s%s%s",acStack_21c,"Profiles",&DAT_006cb138);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc430);
  if (_File == (FILE *)0x0) {
    unaff_ESI[1] = 1;
    iVar4 = FUN_00565b60(*unaff_ESI,0,0,0);
    unaff_ESI[3] = iVar4;
    unaff_ESI[2] = 0;
    return 0;
  }
  _fread(&iStack_240,4,1,_File);
  unaff_ESI[1] = iStack_240 + 1;
  iVar2 = FUN_00565b60(*unaff_ESI * (iStack_240 + 1),0,0,0);
  unaff_ESI[3] = iVar2;
  unaff_ESI[2] = iStack_240;
  if (0 < iStack_240) {
    do {
      _fread(&puStack_23c,0x20,1,_File);
      if (iVar4 < unaff_ESI[1]) {
        iVar2 = *unaff_ESI;
        pcVar3 = (char *)(iVar2 * iVar4 + unaff_ESI[3]);
        if (iVar2 != 0) {
          iVar6 = (int)&puStack_23c - (int)pcVar3;
          do {
            cVar1 = pcVar3[iVar6];
            iVar2 = iVar2 + -1;
            *pcVar3 = cVar1;
            if (cVar1 == '\0') break;
            pcVar3 = pcVar3 + 1;
          } while (iVar2 != 0);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iStack_240);
  }
  _fclose(_File);
  return 1;
}


// ==== 0x41d2a0 ProfileList::Touch

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 ProfileList__Touch(undefined4 param_1,byte *param_2)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  int *_Memory;
  int iVar4;
  int iVar5;
  FILE *_File;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *pcVar12;
  int iVar13;
  char *pcVar14;
  int local_42c;
  char local_408 [235];
  char cStack_31d;
  CHAR aCStack_31c [20];
  undefined1 local_308 [260];
  byte local_204 [236];
  undefined1 auStack_118 [280];
  
  _Memory = _malloc(0x10);
  if (_Memory == (int *)0x0) {
    _Memory = (int *)0x0;
  }
  else {
    *_Memory = 0x20;
    _Memory[1] = 0;
    _Memory[2] = 0;
    _Memory[3] = 0;
  }
  ProfileList__Load(param_1);
  bVar2 = false;
  local_42c = 0;
  if (0 < _Memory[2]) {
    do {
      if (local_42c < _Memory[1]) {
        iVar8 = *_Memory;
        iVar13 = _Memory[3];
        iVar4 = iVar8 * local_42c;
        if (iVar8 != 0) {
          pbVar10 = local_204;
          do {
            bVar7 = pbVar10[(iVar4 + iVar13) - (int)local_204];
            iVar8 = iVar8 + -1;
            *pbVar10 = bVar7;
            if (bVar7 == 0) break;
            pbVar10 = pbVar10 + 1;
          } while (iVar8 != 0);
        }
      }
      pbVar10 = local_204;
      pbVar11 = param_2;
      do {
        bVar7 = *pbVar10;
        if (('`' < (char)bVar7) && ((char)bVar7 < '{')) {
          bVar7 = bVar7 & 0x5f;
        }
        bVar3 = *pbVar11;
        pbVar10 = pbVar10 + 1;
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 & 0x5f;
        }
        pbVar11 = pbVar11 + 1;
      } while (((bVar7 != 0) && (bVar3 != 0)) && (bVar7 == bVar3));
      if (bVar7 == bVar3) {
        bVar2 = true;
        iVar8 = local_42c;
joined_r0x0041d372:
        iVar13 = iVar8;
        if (0 < iVar13) {
          iVar4 = _Memory[1];
          iVar8 = iVar13 + -1;
          if (iVar8 < iVar4) {
            iVar9 = *_Memory;
            iVar6 = _Memory[3];
            iVar5 = iVar9 * iVar8;
            if (iVar9 != 0) {
              pcVar12 = local_408;
              do {
                cVar1 = pcVar12[(iVar5 + iVar6) - (int)local_408];
                iVar9 = iVar9 + -1;
                *pcVar12 = cVar1;
                if (cVar1 == '\0') break;
                pcVar12 = pcVar12 + 1;
              } while (iVar9 != 0);
            }
          }
          if (iVar13 < iVar4) {
            iVar4 = *_Memory;
            pcVar12 = (char *)(iVar4 * iVar13 + _Memory[3]);
            if (iVar4 != 0) {
              iVar13 = -(int)pcVar12;
              do {
                cVar1 = pcVar12[(int)(local_408 + iVar13)];
                iVar4 = iVar4 + -1;
                *pcVar12 = cVar1;
                if (cVar1 == '\0') break;
                pcVar12 = pcVar12 + 1;
              } while (iVar4 != 0);
            }
          }
          goto joined_r0x0041d372;
        }
        if (0 < _Memory[1]) {
          iVar8 = *_Memory;
          pcVar12 = (char *)_Memory[3];
          if (iVar8 != 0) {
            iVar13 = -(int)pcVar12;
            do {
              cVar1 = pcVar12[(int)(local_204 + iVar13)];
              iVar8 = iVar8 + -1;
              *pcVar12 = cVar1;
              if (cVar1 == '\0') break;
              pcVar12 = pcVar12 + 1;
            } while (iVar8 != 0);
          }
        }
      }
      local_42c = local_42c + 1;
    } while (local_42c < _Memory[2]);
    if (bVar2) goto LAB_0041d4e5;
  }
  iVar8 = _Memory[2];
  _Memory[2] = iVar8 + 1;
  iVar13 = iVar8;
  for (; 0 < iVar8; iVar8 = iVar8 + -1) {
    iVar13 = iVar13 + -1;
    iVar4 = _Memory[1];
    if (iVar13 < iVar4) {
      iVar9 = *_Memory;
      iVar6 = _Memory[3];
      iVar5 = iVar9 * iVar13;
      if (iVar9 != 0) {
        pcVar12 = local_408;
        do {
          cVar1 = pcVar12[(iVar5 + iVar6) - (int)local_408];
          iVar9 = iVar9 + -1;
          *pcVar12 = cVar1;
          if (cVar1 == '\0') break;
          pcVar12 = pcVar12 + 1;
        } while (iVar9 != 0);
      }
    }
    if (iVar8 < iVar4) {
      iVar4 = *_Memory;
      pcVar12 = (char *)(iVar4 * iVar8 + _Memory[3]);
      if (iVar4 != 0) {
        iVar9 = -(int)pcVar12;
        do {
          cVar1 = pcVar12[(int)(local_408 + iVar9)];
          iVar4 = iVar4 + -1;
          *pcVar12 = cVar1;
          if (cVar1 == '\0') break;
          pcVar12 = pcVar12 + 1;
        } while (iVar4 != 0);
      }
    }
  }
  if (0 < _Memory[1]) {
    iVar8 = *_Memory;
    pcVar12 = (char *)_Memory[3];
    if (iVar8 != 0) {
      iVar13 = (int)param_2 - (int)pcVar12;
      do {
        cVar1 = pcVar12[iVar13];
        iVar8 = iVar8 + -1;
        *pcVar12 = cVar1;
        if (cVar1 == '\0') break;
        pcVar12 = pcVar12 + 1;
      } while (iVar8 != 0);
    }
  }
LAB_0041d4e5:
  SHGetFolderPathA(0,0x23,0,0,local_308);
  pcVar12 = &cStack_31d;
  do {
    pcVar14 = pcVar12;
    pcVar12 = pcVar14 + 1;
  } while (pcVar14[1] != '\0');
  builtin_strncpy(pcVar14 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(aCStack_31c,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(auStack_118,"%s%s%s",aCStack_31c,"Profiles",&DAT_006cb138);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc3d4);
  if (_File == (FILE *)0x0) {
    if (_Memory[3] != 0) {
      FUN_00565ce0();
    }
    _free(_Memory);
    return 0;
  }
  iVar8 = _Memory[2];
  _fwrite(&stack0xfffffbbc,4,1,_File);
  iVar13 = 0;
  if (0 < iVar8) {
    do {
      if (iVar13 < _Memory[1]) {
        iVar4 = *_Memory;
        iVar9 = _Memory[3];
        iVar6 = iVar4 * iVar13;
        if (iVar4 != 0) {
          pcVar12 = &stack0xfffffbc4;
          do {
            cVar1 = pcVar12[(iVar6 + iVar9) - (int)&stack0xfffffbc4];
            iVar4 = iVar4 + -1;
            *pcVar12 = cVar1;
            if (cVar1 == '\0') break;
            pcVar12 = pcVar12 + 1;
          } while (iVar4 != 0);
        }
      }
      _fwrite(&stack0xfffffbc4,0x20,1,_File);
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar8);
  }
  if (_Memory[3] != 0) {
    FUN_00565ce0();
  }
  _free(_Memory);
  _fclose(_File);
  return 1;
}


// ==== 0x41d650 ProBlob::Write

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 ProBlob__Write(undefined4 param_1,void *param_2)

{
  char *pcVar1;
  size_t in_EAX;
  FILE *_File;
  char *pcVar2;
  undefined1 *puStack_224;
  undefined1 local_208 [240];
  undefined1 auStack_118 [264];
  undefined4 uStack_10;
  
  puStack_224 = local_208;
  SHGetFolderPathA(0,0x23,0,0);
  pcVar1 = &stack0xfffffde3;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(&stack0xfffffde4,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(auStack_118,"%s%s%d%s",&stack0xfffffde4,&DAT_007588c4,0,&DAT_006cb124);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc3d4);
  if (_File != (FILE *)0x0) {
    _fwrite(&stack0xfffffde0,4,1,_File);
    _fwrite(param_2,in_EAX,1,_File);
    puStack_224 = (undefined1 *)Adler32(uStack_10,param_2);
    _fwrite(&puStack_224,4,1,_File);
    _fclose(_File);
    return 1;
  }
  return 0;
}


// ==== 0x41d770 ProBlob::Read

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 ProBlob__Read(undefined4 param_1,void *param_2)

{
  char *pcVar1;
  size_t in_EAX;
  FILE *_File;
  undefined1 *puVar2;
  int unaff_EDI;
  char *pcVar3;
  undefined1 *puStack_224;
  undefined1 local_208 [240];
  undefined1 auStack_118 [264];
  undefined4 uStack_10;
  
  puStack_224 = local_208;
  SHGetFolderPathA(0,0x23,0,0);
  pcVar1 = &stack0xfffffde3;
  do {
    pcVar3 = pcVar1;
    pcVar1 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  builtin_strncpy(pcVar3 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(&stack0xfffffde4,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(auStack_118,"%s%s%d%s",&stack0xfffffde4,&DAT_007588c4,0,&DAT_006cb124);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc430);
  if (_File != (FILE *)0x0) {
    _fread(&stack0xfffffde0,4,1,_File);
    if (unaff_EDI == 1) {
      _fread(param_2,in_EAX,1,_File);
      _fread(&puStack_224,4,1,_File);
      puVar2 = (undefined1 *)Adler32(uStack_10,param_2);
      if (puVar2 == puStack_224) {
        _fclose(_File);
        return 1;
      }
    }
    else {
      _fclose(_File);
    }
  }
  return 0;
}


// ==== 0x41d8a0 Ugd::Write

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 __thiscall Ugd__Write(undefined4 param_1,undefined4 param_2,void *param_3)

{
  char cVar1;
  FILE *_File;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  void *_Str;
  uint uVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined4 local_134;
  undefined1 local_130 [4];
  CHAR local_12c [28];
  char local_110 [12];
  undefined1 local_104 [260];
  
  Save__BuildPath(param_2,param_1,local_104);
  _File = (FILE *)_fopen(local_104,&DAT_006cc3d4);
  if (_File != (FILE *)0x0) {
    local_130 = (undefined1  [4])0x13;
    _fwrite(local_130,4,1,_File);
    GetDateFormatA(0x800,1,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_12c,0xc);
    iVar2 = 0;
    do {
      pcVar3 = local_12c + iVar2;
      local_110[iVar2] = *pcVar3;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
    pcVar3 = (LPCSTR)0x0;
    if ((DAT_00734998 == 4) || (DAT_00734998 == 2)) {
      pcVar3 = "HH\':\'mm";
    }
    GetTimeFormatA(0x800,2,(SYSTEMTIME *)0x0,pcVar3,local_12c,0xc);
    puVar7 = (undefined2 *)(local_130 + 3);
    do {
      pcVar3 = (char *)((int)puVar7 + 1);
      puVar7 = (undefined2 *)((int)puVar7 + 1);
    } while (*pcVar3 != '\0');
    *puVar7 = 0x20;
    pcVar3 = local_110;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar3 - (int)local_110;
    pcVar3 = local_130 + 3;
    do {
      pcVar6 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = local_110;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar3 = pcVar3 + 1;
    }
    _fwrite(param_3,0x12,1,_File);
    _fwrite(local_12c,0x19,1,_File);
    _Str = _malloc(0xf660);
    Ugd__PackBlock(&DAT_007588c4,0xf660);
    _fwrite(_Str,0xf660,1,_File);
    local_134 = Adler32(param_2,_Str);
    _fwrite(&local_134,4,1,_File);
    _free(_Str);
    _fclose(_File);
    return 1;
  }
  return 0;
}


// ==== 0x41da40 Ugd::Read

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 __thiscall Ugd__Read(undefined4 param_1,undefined4 param_2)

{
  FILE *_File;
  void *_DstBuf;
  int iVar1;
  int local_13c;
  int local_138;
  undefined1 local_134 [20];
  undefined1 local_120 [28];
  undefined1 local_104 [260];
  
  Save__BuildPath(param_2,param_1,local_104);
  _File = (FILE *)_fopen(local_104,&DAT_006cc430);
  if (_File != (FILE *)0x0) {
    _fread(&local_13c,4,1,_File);
    if (local_13c == 0x13) {
      _fread(local_134,0x12,1,_File);
      _fread(local_120,0x19,1,_File);
      _DstBuf = _malloc(0xf660);
      _fread(_DstBuf,0xf660,1,_File);
      _fread(&local_138,4,1,_File);
      iVar1 = Adler32(param_2,_DstBuf);
      if (iVar1 != local_138) {
        _fclose(_File);
        _free(_DstBuf);
        return 0;
      }
      _fclose(_File);
      Ugd__UnpackBlock(1);
      _free(_DstBuf);
      return 1;
    }
    _fclose(_File);
  }
  return 0;
}


// ==== 0x41db70 Ugd::ReadHeader

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 __fastcall Ugd__ReadHeader(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  FILE *_File;
  undefined1 *unaff_EDI;
  int local_108;
  undefined1 local_104 [260];
  
  *unaff_EDI = 0;
  *param_3 = 0;
  Save__BuildPath(param_2,param_1,local_104);
  _File = (FILE *)_fopen(local_104,&DAT_006cc430);
  if (_File != (FILE *)0x0) {
    _fread(&local_108,4,1,_File);
    if (local_108 == 0x13) {
      _fread(unaff_EDI,0x12,1,_File);
      _fread(param_3,0x19,1,_File);
      _fclose(_File);
      return 1;
    }
  }
  return 0;
}


// ==== 0x41dc10 Save::BuildPath

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Save__BuildPath(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  int unaff_ESI;
  char *pcVar2;
  CHAR aCStack_118 [8];
  undefined1 *puStack_110;
  undefined1 local_104 [248];
  int iStack_c;
  
  puStack_110 = local_104;
  aCStack_118[4] = '\0';
  aCStack_118[5] = '\0';
  aCStack_118[6] = '\0';
  aCStack_118[7] = '\0';
  aCStack_118[0] = '\0';
  aCStack_118[1] = '\0';
  aCStack_118[2] = '\0';
  aCStack_118[3] = '\0';
  SHGetFolderPathA(0,0x23);
  pcVar1 = &stack0xfffffee7;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(aCStack_118,(LPSECURITY_ATTRIBUTES)0x0);
  if (unaff_ESI == 0) {
    if (iStack_c == -1) {
      _sprintf(param_3,"%s%s%s%s",aCStack_118,&DAT_007588c4,"_autosave");
      return;
    }
  }
  else if (iStack_c == -1) {
    _sprintf(param_3,"%s%s%s%s",aCStack_118);
    return;
  }
  _sprintf(param_3,"%s%s%d%s",aCStack_118);
  return;
}


// ==== 0x41dd10 Adler32

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

int Adler32(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  iVar1 = 1;
  if (0 < unaff_EBX) {
    do {
      iVar1 = (int)((uint)*(byte *)(iVar2 + param_2) + iVar1) % 0xfff1;
      iVar3 = (iVar3 + iVar1) % 0xfff1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < unaff_EBX);
  }
  return iVar3 * 0x10000 + iVar1;
}


// ==== 0x41dd60 Profile::Delete

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

undefined4 Profile__Delete(undefined4 param_1,byte *param_2)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  int *_Memory;
  int iVar4;
  FILE *_File;
  HANDLE pvVar5;
  byte bVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  undefined1 *puVar13;
  int local_474;
  int local_470;
  char acStack_46c [11];
  char cStack_461;
  CHAR aCStack_460 [19];
  char cStack_44d;
  byte local_44c [220];
  CHAR aCStack_370 [20];
  CHAR aCStack_35c [239];
  char cStack_26d;
  CHAR aCStack_26c [20];
  undefined1 auStack_258 [240];
  undefined1 auStack_168 [40];
  undefined1 auStack_140 [320];
  
  _Memory = _malloc(0x10);
  iVar11 = 0;
  if (_Memory == (int *)0x0) {
    _Memory = (int *)0x0;
  }
  else {
    *_Memory = 0x20;
    _Memory[1] = 0;
    _Memory[2] = 0;
    _Memory[3] = 0;
  }
  ProfileList__Load(param_1);
  local_470 = _Memory[2];
  local_474 = -1;
  if (0 < _Memory[2]) {
    do {
      if (iVar11 < _Memory[1]) {
        iVar7 = *_Memory;
        iVar2 = _Memory[3];
        iVar4 = iVar7 * iVar11;
        if (iVar7 != 0) {
          pbVar8 = local_44c;
          do {
            bVar6 = pbVar8[(iVar4 + iVar2) - (int)local_44c];
            iVar7 = iVar7 + -1;
            *pbVar8 = bVar6;
            if (bVar6 == 0) break;
            pbVar8 = pbVar8 + 1;
          } while (iVar7 != 0);
        }
      }
      pbVar8 = local_44c;
      pbVar9 = param_2;
      do {
        bVar6 = *pbVar8;
        if (('`' < (char)bVar6) && ((char)bVar6 < '{')) {
          bVar6 = bVar6 & 0x5f;
        }
        bVar3 = *pbVar9;
        pbVar8 = pbVar8 + 1;
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 & 0x5f;
        }
        pbVar9 = pbVar9 + 1;
      } while (((bVar6 != 0) && (bVar3 != 0)) && (bVar6 == bVar3));
      if (bVar6 == bVar3) {
        local_470 = local_470 + -1;
        local_474 = iVar11;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < _Memory[2]);
    if (local_474 != -1) {
      SHGetFolderPathA(0,0x23,0,0,local_44c);
      pcVar10 = &cStack_44d;
      do {
        pcVar12 = pcVar10;
        pcVar10 = pcVar12 + 1;
      } while (pcVar12[1] != '\0');
      builtin_strncpy(pcVar12 + 1,"\\NFS Underground\\",0x12);
      CreateDirectoryA((LPCSTR)local_44c,(LPSECURITY_ATTRIBUTES)0x0);
      _sprintf(auStack_140,"%s%s%s",local_44c,"Profiles",&DAT_006cb138);
      _File = (FILE *)_fopen(auStack_140,&DAT_006cc3d4);
      if (_File == (FILE *)0x0) {
        if (_Memory[3] != 0) {
          FUN_00565ce0();
        }
        _free(_Memory);
        return 0;
      }
      _fwrite(&local_470,4,1,_File);
      iVar11 = 0;
      if (0 < _Memory[2]) {
        do {
          if (iVar11 != local_474) {
            if (iVar11 < _Memory[1]) {
              iVar7 = *_Memory;
              iVar2 = _Memory[3];
              iVar4 = iVar7 * iVar11;
              if (iVar7 != 0) {
                pcVar10 = acStack_46c;
                do {
                  cVar1 = pcVar10[(iVar4 + iVar2) - (int)acStack_46c];
                  iVar7 = iVar7 + -1;
                  *pcVar10 = cVar1;
                  if (cVar1 == '\0') break;
                  pcVar10 = pcVar10 + 1;
                } while (iVar7 != 0);
              }
            }
            _fwrite(acStack_46c,0x20,1,_File);
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < _Memory[2]);
      }
      if (_Memory[3] != 0) {
        FUN_00565ce0();
      }
      _free(_Memory);
      _fclose(_File);
    }
  }
  iVar11 = -1;
  do {
    Save__BuildPath(param_1,iVar11,local_44c);
    pvVar5 = FindFirstFileA((LPCSTR)local_44c,(LPWIN32_FIND_DATAA)auStack_140);
    if (pvVar5 != (HANDLE)0xffffffff) {
      FindClose(pvVar5);
      iVar7 = thunk_FUN_006725f7(local_44c);
      if (iVar7 == -1) {
        return 0;
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 8);
  SHGetFolderPathA(0,0x23,0,0,local_44c);
  pcVar10 = &cStack_461;
  do {
    pcVar12 = pcVar10;
    pcVar10 = pcVar12 + 1;
  } while (pcVar12[1] != '\0');
  builtin_strncpy(pcVar12 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(aCStack_460,(LPSECURITY_ATTRIBUTES)0x0);
  puVar13 = (undefined1 *)auStack_140._308_4_;
  if ((undefined1 *)auStack_140._308_4_ == (undefined1 *)0x0) {
    puVar13 = &DAT_007588c4;
  }
  _sprintf(aCStack_35c,"%s%s%d%s",aCStack_460,puVar13,0,&DAT_006cb124);
  pvVar5 = FindFirstFileA(aCStack_35c,(LPWIN32_FIND_DATAA)(auStack_168 + 0x14));
  if (pvVar5 != (HANDLE)0xffffffff) {
    FindClose(pvVar5);
    iVar11 = thunk_FUN_006725f7(aCStack_35c);
    if (iVar11 == -1) {
      return 0;
    }
  }
  SHGetFolderPathA(0,0x23,0,0,auStack_258);
  pcVar10 = &cStack_26d;
  do {
    pcVar12 = pcVar10;
    pcVar10 = pcVar12 + 1;
  } while (pcVar12[1] != '\0');
  builtin_strncpy(pcVar12 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(aCStack_26c,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(aCStack_370,"%s%s%s",aCStack_26c,auStack_140._308_4_,&DAT_006cb15c);
  pvVar5 = FindFirstFileA(aCStack_370,(LPWIN32_FIND_DATAA)auStack_168);
  if (pvVar5 != (HANDLE)0xffffffff) {
    FindClose(pvVar5);
    iVar11 = thunk_FUN_006725f7(aCStack_370);
    if (iVar11 == -1) {
      return 0;
    }
  }
  _sprintf(aCStack_370,"%s%s%s",aCStack_26c,auStack_140._308_4_,&DAT_006cb0f0);
  pvVar5 = FindFirstFileA(aCStack_370,(LPWIN32_FIND_DATAA)auStack_168);
  if (pvVar5 != (HANDLE)0xffffffff) {
    FindClose(pvVar5);
    iVar11 = thunk_FUN_006725f7(aCStack_370);
    if (iVar11 == -1) {
      return 0;
    }
  }
  return 1;
}


// ==== 0x41e200 Opt::Write

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Opt__Write(void)

{
  char *pcVar1;
  FILE *_File;
  void *_Str;
  char *pcVar2;
  undefined4 uStack_224;
  undefined4 uStack_220;
  CHAR aCStack_21c [4];
  undefined1 *puStack_218;
  undefined1 local_208 [240];
  undefined1 auStack_118 [264];
  undefined4 uStack_10;
  
  puStack_218 = local_208;
  aCStack_21c[0] = '\0';
  aCStack_21c[1] = '\0';
  aCStack_21c[2] = '\0';
  aCStack_21c[3] = '\0';
  uStack_220 = 0;
  uStack_224 = 0x23;
  SHGetFolderPathA(0);
  pcVar1 = (char *)((int)&uStack_220 + 3);
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(aCStack_21c,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(auStack_118,"%s%s%s",aCStack_21c,&DAT_007588c4,&DAT_006cb0f0);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc3d4);
  if (_File != (FILE *)0x0) {
    uStack_220 = 0x13;
    _fwrite(&uStack_220,4,1,_File);
    _Str = _malloc(0x2e5);
    Opt__Serialize(0x2e5);
    _fwrite(_Str,0x2e5,1,_File);
    uStack_224 = Adler32(uStack_10,_Str);
    _fwrite(&uStack_224,4,1,_File);
    _free(_Str);
    _fclose(_File);
  }
  return;
}


// ==== 0x41e330 Opt::Read

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Opt__Read(void)

{
  char *pcVar1;
  FILE *_File;
  void *_DstBuf;
  int iVar2;
  char *pcVar3;
  int iStack_224;
  undefined4 uStack_220;
  undefined1 local_208 [240];
  undefined1 auStack_118 [264];
  undefined4 uStack_10;
  
  uStack_220 = local_208;
  iStack_224 = 0;
  SHGetFolderPathA(0,0x23,0);
  pcVar1 = (char *)((int)&uStack_220 + 3);
  do {
    pcVar3 = pcVar1;
    pcVar1 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  builtin_strncpy(pcVar3 + 1,"\\NFS Underground\\",0x12);
  CreateDirectoryA(&stack0xfffffde4,(LPSECURITY_ATTRIBUTES)0x0);
  _sprintf(auStack_118,"%s%s%s",&stack0xfffffde4,&DAT_007588c4,&DAT_006cb0f0);
  _File = (FILE *)_fopen(auStack_118,&DAT_006cc430);
  if (_File != (FILE *)0x0) {
    _fread(&uStack_220,4,1,_File);
    if (uStack_220 == (undefined1 *)0x13) {
      _DstBuf = _malloc(0x2e5);
      _fread(_DstBuf,0x2e5,1,_File);
      _fread(&iStack_224,4,1,_File);
      iVar2 = Adler32(uStack_10,_DstBuf);
      if (iVar2 != iStack_224) {
        _fclose(_File);
        _free(_DstBuf);
        return;
      }
      _fclose(_File);
      Opt__Deserialize(1);
      _free(_DstBuf);
      return;
    }
    _fclose(_File);
  }
  return;
}


// ==== 0x41e4a0 FUN_0041e4a0

undefined4 FUN_0041e4a0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x40);
}


// ==== 0x41e4b0 FUN_0041e4b0

undefined4 FUN_0041e4b0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x58);
}


// ==== 0x41e4c0 FUN_0041e4c0

undefined4 FUN_0041e4c0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x10);
}


// ==== 0x41e4d0 FUN_0041e4d0

void FUN_0041e4d0(void)

{
  FEManager__PushPackageChecked(8,0);
  FUN_004f6460("PC_ContextHelp.fng",1);
  FUN_004f6490(1);
  DAT_00736220 = FEng_FindObjectByHash();
  if (DAT_00736220 != 0) {
    FEObject__SetInvisible(DAT_00736220);
  }
  return;
}


// ==== 0x41e540 FUN_0041e540

void FUN_0041e540(float param_1,float param_2)

{
  float10 fVar1;
  float local_c;
  float local_8;
  
  param_2 = param_2 - 20.0;
  param_1 = param_1 + 10.0;
  FUN_004f7000(param_1,param_2);
  FUN_004f6e10(DAT_00736220,&local_8,&local_c);
  if (320.0 < local_8) {
    param_1 = param_1 - (local_8 - 320.0);
  }
  if (240.0 < local_c) {
    param_2 = param_2 - (local_c - 240.0);
  }
  fVar1 = (float10)FUN_00401c40(0xc3700000,param_2);
  FUN_004f7000(param_1,(float)fVar1);
  return;
}


// ==== 0x41e600 FUN_0041e600

void FUN_0041e600(float param_1,float param_2)

{
  FEString__SetLabelHash();
  FUN_0041e540(param_1 - 320.0,param_2 - 240.0);
  FEObject__SetVisible(DAT_00736220);
  return;
}


// ==== 0x41e650 FUN_0041e650

void FUN_0041e650(void)

{
  FEObject__SetInvisible(DAT_00736220);
  return;
}


// ==== 0x41e670 FUN_0041e670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e670(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  undefined1 local_11c [256];
  int local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  char local_5;
  
  if (DAT_00736220 == 0) {
    return;
  }
  local_5 = '\0';
  local_c = FUN_004f6630();
  while ((local_c != 0 && (iVar2 = FUN_004081e0(), iVar2 == 0))) {
    local_c = FUN_00417490();
  }
  if (local_c != 0) {
    local_10 = FUN_0041e4a0();
    FUN_004134c0();
    iVar2 = FUN_004055f0();
    if ((float)iVar2 < _K_ONE) {
      FUN_0041e4c0();
      iVar2 = FUN_004055f0();
      if ((float)iVar2 < _K_ONE) {
        if (_DAT_0078eb74 == 0.0) {
          fVar4 = (float10)bTickerToSeconds();
          _DAT_0078eb74 = (float)(fVar4 + (float10)_K_ONE);
        }
        fVar4 = (float10)bTickerToSeconds();
        if ((float10)_DAT_0078eb74 < fVar4) {
          iVar2 = FUN_00417490();
          local_14 = (float)iVar2;
          iVar2 = FUN_004ee660();
          local_18 = (float)iVar2;
          while (local_10 != 0) {
            local_1c = 0;
            if (*(int *)(local_10 + 0x18) == 2) {
              local_1c = local_10;
            }
            if (((local_1c != 0) && ((*(uint *)(local_1c + 0x1c) & 0x10) != 0)) &&
               (cVar1 = FUN_004f7660(local_14 - 320.0,local_18 - 240.0), cVar1 != '\0')) {
              uVar3 = FUN_0041e4b0();
              _sprintf(local_11c,"PCHELP_%s",uVar3);
              uVar3 = FUN_00567c70();
              FUN_0041e600(local_14,local_18,uVar3);
              local_5 = '\x01';
            }
            local_10 = FUN_00417490();
          }
        }
        goto LAB_0041e84e;
      }
    }
    _DAT_0078eb74 = 0.0;
  }
LAB_0041e84e:
  if (local_5 == '\0') {
    FUN_0041e650();
  }
  return;
}


// ==== 0x41e860 CpuDetect

/* WARNING: Removing unreachable block (ram,0x0041e88b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime high (hopper+capstone) docs/re/misc.md */

float10 CpuDetect(void)

{
  undefined4 *puVar1;
  uint uVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar3;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0x00000000,0x10) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_10 < 0) * 0x80
          | (uint)(&stack0x00000000 == (undefined1 *)0x10) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)&local_10 & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0x00000000 < (undefined1 *)0x10) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar2 = uVar3 ^ 0x200000;
  if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x800) != 0) * 0x800 |
       (uint)((uVar2 & 0x200) != 0) * 0x200 | (uint)((uVar2 & 0x100) != 0) * 0x100 |
       (uint)((uVar2 & 0x80) != 0) * 0x80 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
       (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 | (uint)((uVar2 & 1) != 0)
       | (uint)((uVar2 & 0x200000) != 0) * 0x200000 | (uint)((uVar2 & 0x40000) != 0) * 0x40000) ==
      uVar3) {
LAB_0041e91f:
    return (float10)0.0;
  }
  puVar1 = (undefined4 *)cpuid_basic_info(0);
  local_4 = *puVar1;
  local_10 = puVar1[1];
  local_8 = puVar1[2];
  local_c = puVar1[3];
  if (local_10 == 0x68747541) {
    FUN_0041eae0(0x32);
    FUN_0041ea60();
  }
  else if (local_10 == 0x69727943) {
    DAT_0071dae8 = 1;
    DAT_0071daf0 = 0;
    DAT_0071daf4 = 0;
  }
  else if (local_10 == 0x756e6547) {
    FUN_0041eae0(0x32);
    Cpu_DetectFamily();
  }
  else {
    DAT_0071dae8 = 5;
    DAT_0071daf0 = 0;
    DAT_0071daf4 = 0;
  }
  switch(DAT_0071dae8) {
  case 0:
    goto LAB_0041e91f;
  default:
    return (float10)0.0;
  case 2:
    if ((float10)800.0 <= (float10)CONCAT44(DAT_0071daf4,DAT_0071daf0)) {
      return ((float10)CONCAT44(DAT_0071daf4,DAT_0071daf0) - (float10)800.0) *
             (float10)0.00033333333;
    }
    break;
  case 3:
  case 4:
    if ((float10)800.0 <= (float10)CONCAT44(DAT_0071daf4,DAT_0071daf0)) {
      return ((float10)CONCAT44(DAT_0071daf4,DAT_0071daf0) - (float10)800.0) *
             (float10)0.00041666668;
    }
    break;
  case 5:
    return (float10)_K_ONE;
  }
  return (float10)0.0;
}


// ==== 0x41e9b0 Cpu_DetectFamily

/* WARNING: Removing unreachable block (ram,0x0041e9db) */
/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

uint Cpu_DetectFamily(void)

{
  int iVar1;
  uint uVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar3;
  undefined1 local_c [12];
  
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0x00000000,0xc) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)local_c < 0) * 0x80 |
          (uint)(&stack0x00000000 == (undefined1 *)0xc) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)local_c & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0x00000000 < (undefined1 *)0xc) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar2 = uVar3 ^ 0x200000;
  if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x800) != 0) * 0x800 |
       (uint)((uVar2 & 0x200) != 0) * 0x200 | (uint)((uVar2 & 0x100) != 0) * 0x100 |
       (uint)((uVar2 & 0x80) != 0) * 0x80 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
       (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 | (uint)((uVar2 & 1) != 0)
       | (uint)((uVar2 & 0x200000) != 0) * 0x200000 | (uint)((uVar2 & 0x40000) != 0) * 0x40000) ==
      uVar3) {
    return 0;
  }
  iVar1 = cpuid_Version_info(1);
  uVar3 = *(uint *)(iVar1 + 4) & 0xf;
  uVar2 = uVar3;
  if (0xe < uVar3) {
switchD_0041e9fc_caseD_5:
    DAT_0071dae8 = 5;
    return uVar2;
  }
  uVar2 = (uint)(&switchD_0041e9fc::switchdataD_0041ea50)[uVar3];
  switch(uVar3) {
  case 0:
    DAT_0071dae8 = 0;
    return uVar2;
  default:
    DAT_0071dae8 = 2;
    return uVar2;
  case 5:
  case 0xc:
  case 0xd:
    goto switchD_0041e9fc_caseD_5;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xe:
    DAT_0071dae8 = 3;
    return uVar2;
  }
}


// ==== 0x41ea60 FUN_0041ea60

/* WARNING: Removing unreachable block (ram,0x0041ea8b) */

uint FUN_0041ea60(void)

{
  uint *puVar1;
  uint uVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar3;
  undefined1 local_c [12];
  
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0x00000000,0xc) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)local_c < 0) * 0x80 |
          (uint)(&stack0x00000000 == (undefined1 *)0xc) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)local_c & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0x00000000 < (undefined1 *)0xc) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar2 = uVar3 ^ 0x200000;
  if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x800) != 0) * 0x800 |
       (uint)((uVar2 & 0x200) != 0) * 0x200 | (uint)((uVar2 & 0x100) != 0) * 0x100 |
       (uint)((uVar2 & 0x80) != 0) * 0x80 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
       (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 | (uint)((uVar2 & 1) != 0)
       | (uint)((uVar2 & 0x200000) != 0) * 0x200000 | (uint)((uVar2 & 0x40000) != 0) * 0x40000) ==
      uVar3) {
    return 0;
  }
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = *puVar1 >> 8 & 0xf;
  if (3 < uVar2) {
    if (uVar2 < 6) {
      DAT_0071dae8 = 0;
      return uVar2;
    }
    if (uVar2 == 6) {
      DAT_0071dae8 = 4;
      return 6;
    }
  }
  DAT_0071dae8 = 5;
  return uVar2;
}


// ==== 0x41eae0 FUN_0041eae0

/* WARNING: Removing unreachable block (ram,0x0041eb39) */

undefined8 FUN_0041eae0(DWORD param_1)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  HANDLE hProcess;
  HANDLE hThread;
  DWORD dwPriorityClass;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar4;
  undefined8 uVar5;
  DWORD_PTR local_34;
  ULONG_PTR local_30;
  uint local_2c;
  LARGE_INTEGER local_28;
  LARGE_INTEGER local_20;
  LARGE_INTEGER local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined8 local_8;
  
  uVar2 = param_1 - 1;
  if (param_1 == 0) {
    if ((-1 < DAT_0071daf4) &&
       ((uVar5 = CONCAT44(DAT_0071daf4,DAT_0071daf0), 0 < DAT_0071daf4 ||
        (uVar5 = CONCAT44(DAT_0071daf4,DAT_0071daf0), DAT_0071daf0 != 0)))) {
LAB_0041ecd5:
      DAT_0071daf4 = (int)((ulonglong)uVar5 >> 0x20);
      DAT_0071daf0 = (int)uVar5;
      return uVar5;
    }
  }
  else {
    uVar4 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4(param_1,1) * 0x800 |
            (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)uVar2 < 0) * 0x80 |
            (uint)(uVar2 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
            (uint)((POPCOUNT(uVar2 & 0xff) & 1U) == 0) * 4 | (uint)(param_1 == 0) |
            (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
            (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
    uVar2 = uVar4 ^ 0x200000;
    if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x800) != 0) * 0x800 |
         (uint)((uVar2 & 0x200) != 0) * 0x200 | (uint)((uVar2 & 0x100) != 0) * 0x100 |
         (uint)((uVar2 & 0x80) != 0) * 0x80 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
         (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 |
         (uint)((uVar2 & 1) != 0) | (uint)((uVar2 & 0x200000) != 0) * 0x200000 |
        (uint)((uVar2 & 0x40000) != 0) * 0x40000) != uVar4) {
      iVar1 = cpuid_Version_info(1);
      local_2c = *(uint *)(iVar1 + 8);
      if (((local_2c & 0x10) != 0) && (BVar3 = QueryPerformanceFrequency(&local_18), BVar3 != 0)) {
        hProcess = GetCurrentProcess();
        hThread = GetCurrentThread();
        dwPriorityClass = GetPriorityClass(hProcess);
        local_2c = GetThreadPriority(hThread);
        GetProcessAffinityMask(hProcess,&local_34,&local_30);
        SetPriorityClass(hProcess,0x100);
        SetThreadPriority(hThread,0xf);
        BVar3 = SetProcessAffinityMask(hProcess,1);
        if (BVar3 == 0) {
          cpuid_basic_info(0);
        }
        else if (BVar3 == 1) {
          cpuid_Version_info(1);
        }
        else if (BVar3 == 2) {
          cpuid_cache_tlb_info(2);
        }
        else if (BVar3 == 3) {
          cpuid_serial_info(3);
        }
        else if (BVar3 == 4) {
          cpuid_Deterministic_Cache_Parameters_info(4);
        }
        else if (BVar3 == 5) {
          cpuid_MONITOR_MWAIT_Features_info(5);
        }
        else if (BVar3 == 6) {
          cpuid_Thermal_Power_Management_info(6);
        }
        else if (BVar3 == 7) {
          cpuid_Extended_Feature_Enumeration_info(7);
        }
        else if (BVar3 == 9) {
          cpuid_Direct_Cache_Access_info(9);
        }
        else if (BVar3 == 10) {
          cpuid_Architectural_Performance_Monitoring_info(10);
        }
        else if (BVar3 == 0xb) {
          cpuid_Extended_Topology_info(0xb);
        }
        else if (BVar3 == 0xd) {
          cpuid_Processor_Extended_States_info(0xd);
        }
        else if (BVar3 == 0xf) {
          cpuid_Quality_of_Service_info(0xf);
        }
        else if (BVar3 == -0x7ffffffe) {
          cpuid_brand_part1_info(0x80000002);
        }
        else if (BVar3 == -0x7ffffffd) {
          cpuid_brand_part2_info(0x80000003);
        }
        else if (BVar3 == -0x7ffffffc) {
          cpuid_brand_part3_info(0x80000004);
        }
        else {
          cpuid(BVar3);
        }
        QueryPerformanceCounter(&local_20);
        uVar5 = rdtsc();
        local_8._4_4_ = (uint)((ulonglong)uVar5 >> 0x20);
        local_8._0_4_ = (undefined4)uVar5;
        Sleep(param_1);
        QueryPerformanceCounter(&local_28);
        uVar5 = rdtsc();
        local_c = (undefined4)((ulonglong)uVar5 >> 0x20);
        local_10 = (undefined4)uVar5;
        SetProcessAffinityMask(hProcess,local_34);
        SetThreadPriority(hThread,local_2c);
        SetPriorityClass(hProcess,dwPriorityClass);
        local_8._4_4_ = local_18.s.HighPart & 0x80000000;
        local_8._0_4_ = 0;
        local_8 = _ftol_nocw();
        uVar5 = _ftol_nocw();
        goto LAB_0041ecd5;
      }
    }
  }
  return 0;
}


// ==== 0x41ece0 GpuPerformanceScore

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (ghidra-canon) docs/re/misc.md */

float10 __fastcall GpuPerformanceScore(int param_1)

{
  uint uVar1;
  uint uVar2;
  float10 fVar3;
  
  uVar1 = *(uint *)(param_1 + 0x42c);
  fVar3 = (float10)-1.0;
  uVar2 = *(uint *)(param_1 + 0x428);
  if (uVar2 < 0x104b) {
    switch(uVar2) {
    case 0x1002:
      if ((uVar1 < 0x5144) || (0x5147 < uVar1)) {
        if ((0x514b < uVar1) && (uVar1 < 0x5150)) {
          return (float10)0.4;
        }
        if (0x4c66 < uVar1) {
          if (uVar1 < 0x4e69) {
            if (uVar1 == 0x4e68) {
switchD_0041ee07_caseD_4e44:
              return (float10)0.9;
            }
            switch(uVar1) {
            case 0x4e44:
            case 0x4e45:
            case 0x4e48:
            case 0x4e64:
            case 0x4e65:
              goto switchD_0041ee07_caseD_4e44;
            default:
              goto switchD_0041ed1a_caseD_1003;
            }
          }
          if (uVar1 < 0x5942) {
            if (uVar1 == 0x5941) {
LAB_0041ee52:
              return (float10)0.5;
            }
            if (uVar1 == 0x5157) goto LAB_0041ee3b;
            if (uVar1 != 0x5940) {
              return fVar3;
            }
          }
          else if (uVar1 != 0x5960) {
            if (uVar1 != 0x5961) {
              return fVar3;
            }
            goto LAB_0041ee52;
          }
          return (float10)0.55;
        }
        if (uVar1 == 0x4c66) {
LAB_0041ede0:
          return (float10)0.3;
        }
        if (uVar1 < 0x4173) {
          if (uVar1 == 0x4172) {
switchD_0041ed79_caseD_4152:
            return (float10)0.8;
          }
          switch(uVar1) {
          case 0x4144:
          case 0x4164:
            return (float10)0.7;
          default:
            goto switchD_0041ed1a_caseD_1003;
          case 0x4150:
          case 0x4170:
            goto LAB_0041ed82;
          case 0x4152:
            goto switchD_0041ed79_caseD_4152;
          }
        }
        if (uVar1 < 0x496f) {
          if (uVar1 != 0x496e) {
            if (uVar1 == 0x4242) goto LAB_0041ee3b;
            if (uVar1 != 0x4966) {
              return fVar3;
            }
          }
          return (float10)0.35;
        }
        if (0x4c56 < uVar1) {
          if (uVar1 < 0x4c59) {
LAB_0041ee3b:
            return (float10)0.15;
          }
          if (uVar1 == 0x4c64) goto LAB_0041ede0;
        }
      }
    }
  }
  else if ((uVar2 == 0x10de) && (0x10f < uVar1)) {
    if (0x342 < uVar1) {
      return (float10)_K_ONE;
    }
    if (uVar1 < 0x114) {
      return (float10)0.1;
    }
    if ((0x14f < uVar1) && (uVar1 < 0x154)) {
      return (float10)0.2;
    }
    if ((0x16f < uVar1) && (uVar1 < 0x183)) goto LAB_0041ede0;
    if ((0x19f < uVar1) && (uVar1 < 0x1f1)) {
      return (float10)0.25;
    }
    if ((0x1ff < uVar1) && (uVar1 < 0x204)) goto LAB_0041ee52;
    if ((0x24f < uVar1) && (uVar1 < 0x28a)) {
      return (float10)0.6;
    }
    if ((0x300 < uVar1) && (uVar1 < 0x333)) {
      if (uVar1 < 0x30b) {
LAB_0041ed82:
        return (float10)0.85;
      }
      if (uVar1 < 0x31d) {
        return (float10)0.75;
      }
      if (uVar1 < 0x32e) {
        return (float10)0.65;
      }
      fVar3 = (float10)0.95;
    }
  }
switchD_0041ed1a_caseD_1003:
  return fVar3;
}


// ==== 0x41eff0 MachinePerformanceScore

/* [canon] render med (ghidra-canon) docs/re/render.md */

float10 MachinePerformanceScore(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  fVar4 = (float10)GpuPerformanceScore();
  fVar1 = (float)fVar4;
  fVar4 = (float10)CpuDetect();
  fVar2 = (float)fVar4;
  fVar3 = fVar2;
  if (fVar1 < fVar2) {
    fVar3 = fVar1;
  }
  if (fVar1 <= fVar2) {
    return (float10)fVar3 * (float10)0.8 + (float10)fVar2 * (float10)0.19999999;
  }
  return (float10)fVar3 * (float10)0.8 + (float10)fVar1 * (float10)0.19999999;
}


// ==== 0x41f060 FUN_0041f060

void FUN_0041f060(int param_1)

{
  undefined1 local_800 [2048];
  
  FUN_0059ff40(local_800,0x800);
  WString_Assign();
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400000;
  return;
}


// ==== 0x41f0b0 int_Sub

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void __thiscall int_Sub(int *param_1,int *param_2)

{
  int *in_EAX;
  
  *in_EAX = *param_1 - *param_2;
  return;
}


// ==== 0x41f0c0 FEMenuData::FEMenuData

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined4 * __fastcall FEMenuData__FEMenuData(undefined4 *param_1)

{
  eh_vector_constructor_iterator(param_1 + 4,0xc,0x20,FUN_0041f130,WString_Free);
  param_1[0x80] = 0;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  param_1[3] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x68] = 0;
  *(undefined1 *)(param_1 + 0x67) = 0;
  param_1[0x7c] = 0;
  *(undefined1 *)(param_1 + 0x7f) = 0;
  param_1[0x80] = DAT_0073ad3c;
  *(undefined1 *)((int)param_1 + 0x205) = 0;
  *(undefined1 *)(param_1 + 0x81) = 1;
  return param_1;
}


// ==== 0x41f130 FUN_0041f130

void __fastcall FUN_0041f130(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ==== 0x41f140 FUN_0041f140

void __fastcall FUN_0041f140(int param_1)

{
  eh_vector_destructor_iterator((void *)(param_1 + 0x10),0xc,0x20,WString_Free);
  return;
}


// ==== 0x41f160 FUN_0041f160

void __fastcall
FUN_0041f160(undefined1 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 1) = param_1;
  *unaff_ESI = in_EAX;
  unaff_ESI[100] = 0;
  unaff_ESI[0x65] = 0;
  unaff_ESI[0x7a] = param_2;
  unaff_ESI[0x7b] = param_6;
  if (*(int *)(in_EAX + 0xc) == 0) {
LAB_0041f1a9:
    if (DAT_0073578c != 0) {
      iVar1 = FUN_004ef050(param_3);
      if (iVar1 != 0) goto LAB_0041f1c1;
    }
LAB_0041f1c7:
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004f65d0();
    if (iVar1 == 0) goto LAB_0041f1a9;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_0041f1a9;
LAB_0041f1c1:
    if (*(int *)(iVar1 + 0x18) != 2) goto LAB_0041f1c7;
  }
  unaff_ESI[3] = iVar1;
  *(undefined1 *)((int)unaff_ESI + 5) = 1;
  *(undefined1 *)(unaff_ESI + 0x69) = 0;
  if (*(int *)(*unaff_ESI + 0xc) != 0) {
    iVar1 = FUN_004f65d0();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_0041f215;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(param_4);
  }
LAB_0041f215:
  unaff_ESI[0x7d] = 0;
  unaff_ESI[0x68] = iVar1;
  unaff_ESI[0x80] = DAT_0073ad3c;
  *(undefined1 *)((int)unaff_ESI + 0x205) = 0;
  *(undefined1 *)(unaff_ESI + 0x81) = 1;
  return;
}


// ==== 0x41f240 FUN_0041f240

char __fastcall FUN_0041f240(int param_1)

{
  uint *puVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 local_50;
  
  if (*(char *)(in_EAX + 5) == '\0') {
    return '\0';
  }
  if (param_1 != -0x367ca946) {
    return *(char *)(in_EAX + 0x19c);
  }
  if (*(char *)(in_EAX + 0x19c) == '\0') {
    return '\0';
  }
  iVar2 = FUN_004117b0();
  if (iVar2 == 0) {
    if (*(int *)(in_EAX + 0x1e8) == 0) {
      puVar1 = (uint *)(*(int *)(in_EAX + 0xc) + 0x1c);
      *puVar1 = *puVar1 | 0x20;
      FUN_00416bb0(0);
      if (0.2 < (float)(DAT_0073ad3c - *(int *)(in_EAX + 0x200)) * 0.00025) {
        *(int *)(in_EAX + 0x200) = DAT_0073ad3c;
        *(byte *)(in_EAX + 0x204) = *(byte *)(in_EAX + 0x204) ^ 1;
      }
      puVar5 = &local_50;
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      bStrCpy();
      iVar2 = DAT_007363a4;
      FUN_00567d00();
      iVar3 = bStrLen();
      *(undefined1 *)((int)&local_50 + iVar3 + 1) = 0;
      if (*(char *)(in_EAX + 0x205) != '\0') {
        FUN_004fa0b0(*(undefined4 *)(in_EAX + 0x1ec));
      }
      if (*(char *)(in_EAX + 0x204) == '\0') {
        *(undefined1 *)((int)&local_50 + iVar2) = 0x20;
      }
      else {
        *(undefined1 *)((int)&local_50 + iVar2) = 0x7c;
      }
      iVar2 = bStrLen();
      uVar4 = *(undefined4 *)(in_EAX + 0xc);
      *(undefined1 *)((int)&local_50 + iVar2 + 1) = 0;
      FUN_0041f060(uVar4,&local_50);
      bStrCpy();
      return '\x01';
    }
    FUN_00567d00();
    return '\x01';
  }
  if (*(char *)(in_EAX + 0x1fc) != '\0') {
    *(undefined1 *)(in_EAX + 0x1fc) = 0;
    return '\x01';
  }
  DAT_007363a8 = 0;
  DAT_0070108d = 1;
  *(undefined1 *)(in_EAX + 0x19c) = 0;
  if (iVar2 < 1) {
    if (iVar2 != -1) goto LAB_0041f337;
    FUN_00416bb0(*(undefined4 *)(in_EAX + 500));
    iVar2 = *(int *)(in_EAX + 0x1f8);
joined_r0x0041f32b:
    if (iVar2 == 0) goto LAB_0041f337;
  }
  else {
    iVar2 = bStrLen();
    if (iVar2 < 1) {
      FUN_00416bb0(*(undefined4 *)(in_EAX + 500));
      iVar2 = *(int *)(in_EAX + 0x1f8);
      goto joined_r0x0041f32b;
    }
  }
  FUN_004f6570();
LAB_0041f337:
  puVar5 = &local_50;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (*(char *)(in_EAX + 0x205) == '\0') {
    uVar4 = *(undefined4 *)(in_EAX + 0xc);
    puVar5 = (undefined4 *)&DAT_00777b74;
  }
  else {
    FUN_004fa0b0(*(undefined4 *)(in_EAX + 0x1ec));
    uVar4 = *(undefined4 *)(in_EAX + 0xc);
    puVar5 = &local_50;
  }
  FUN_0041f060(uVar4,puVar5);
  uVar4 = *(undefined4 *)(in_EAX + 0x198);
  iVar2 = FUN_004f65d0();
  if (iVar2 == 0) {
    return '\x01';
  }
  *(undefined4 *)(iVar2 + 0x1c) = uVar4;
  return '\x01';
}


// ==== 0x41f4d0 FUN_0041f4d0

void FUN_0041f4d0(void)

{
  int iVar1;
  int unaff_ESI;
  
  DAT_007363ac = *(undefined4 *)(unaff_ESI + 0x1ec);
  DAT_0073639c = (undefined1 *)(unaff_ESI + 0x1a4);
  *(undefined1 *)(unaff_ESI + 0x19c) = 1;
  *DAT_0073639c = 0;
  *DAT_0073639c = 0;
  DAT_007363a8 = 1;
  DAT_007363b0 = 1;
  DAT_007363a0 = 0;
  DAT_007363a4 = 0;
  iVar1 = FUN_004f65d0();
  *(undefined4 *)(unaff_ESI + 0x198) = *(undefined4 *)(iVar1 + 0x1c);
  iVar1 = FUN_004f65d0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  *(undefined1 *)(unaff_ESI + 0x1fc) = 1;
  return;
}


// ==== 0x41f550 FUN_0041f550

float10 __fastcall FUN_0041f550(float *param_1)

{
  float *in_EAX;
  
  return SQRT(((float10)*param_1 - (float10)*in_EAX) * ((float10)*param_1 - (float10)*in_EAX) +
              ((float10)param_1[1] - (float10)in_EAX[1]) *
              ((float10)param_1[1] - (float10)in_EAX[1]));
}


// ==== 0x41f570 FUN_0041f570

void FUN_0041f570(void)

{
  int iVar1;
  undefined4 *in_EAX;
  int iVar2;
  bool bVar3;
  
  iVar1 = DAT_007349b4;
  iVar2 = *(int *)(DAT_007349b4 + 0x18);
  *in_EAX = *(undefined4 *)(DAT_007349b4 + 0x10);
  *(undefined4 **)(iVar1 + 0x10) = in_EAX;
  iVar2 = iVar2 + -1;
  bVar3 = DAT_007349b8 != 0;
  *(int *)(iVar1 + 0x18) = iVar2;
  if (bVar3) {
    if (iVar2 == 0) {
      SlotPool__Destroy();
      DAT_007349b4 = 0;
      return;
    }
    DAT_007349b8 = 1;
  }
  return;
}


// ==== 0x41f5c0 FUN_0041f5c0

int FUN_0041f5c0(void)

{
  int in_EAX;
  
  return (int)*(short *)(in_EAX + 10);
}


// ==== 0x41f5d0 FUN_0041f5d0

undefined4 FUN_0041f5d0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x2c);
}


// ==== 0x41f5e0 FUN_0041f5e0

int FUN_0041f5e0(void)

{
  int in_EAX;
  
  return in_EAX + 0x60;
}


// ==== 0x41f5f0 FUN_0041f5f0

float10 FUN_0041f5f0(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x814);
}


// ==== 0x41f600 IsDriftMode

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

undefined4 IsDriftMode(void)

{
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x55) == '\0') && (DAT_007361a4 == 0)) {
    return 0;
  }
  return 1;
}


// ==== 0x41f620 FUN_0041f620

void __fastcall FUN_0041f620(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00736088;
  iVar1 = *(int *)(DAT_00736088 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00736088 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x41f640 FUN_0041f640

int FUN_0041f640(void)

{
  int in_EAX;
  
  return (int)*(char *)(in_EAX + 0x3d);
}


// ==== 0x41f650 FUN_0041f650

void FUN_0041f650(void)

{
  undefined4 in_EAX;
  
  FUN_00571ea0(0,in_EAX);
  return;
}


// ==== 0x41f660 FUN_0041f660

void __fastcall FUN_0041f660(undefined4 param_1)

{
  undefined4 in_EAX;
  
  FUN_00571c20(param_1,in_EAX,4,0xffffffff,0);
  return;
}


// ==== 0x41f670 FUN_0041f670

void __fastcall FUN_0041f670(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  
  FUN_00571c20(param_2,param_1,in_EAX,4,0);
  return;
}


// ==== 0x41f680 FUN_0041f680

int __fastcall FUN_0041f680(int param_1)

{
  return *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x24);
}


// ==== 0x41f690 FUN_0041f690

undefined4 __fastcall FUN_0041f690(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x28 + (*(int *)(in_EAX + 0x24) + param_2) * 4);
}


// ==== 0x41f6a0 GameMode::BlocksSpecialCameras

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined4 GameMode__BlocksSpecialCameras(void)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if (((iVar1 != 5) && (iVar1 != 6)) && (iVar1 != 10)) {
    return 0;
  }
  return 1;
}


// ==== 0x41f6c0 FUN_0041f6c0

void __fastcall FUN_0041f6c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00735fe4;
  iVar1 = *(int *)(DAT_00735fe4 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00735fe4 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x41f6e0 FUN_0041f6e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041f6e0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  void *local_c;
  code *pcStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  pcStack_8 = FUN_00686e23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  iVar4 = param_1 + 8;
  *(int *)iVar4 = iVar4;
  *(int *)(param_1 + 0xc) = iVar4;
  iVar4 = param_1 + 0x10;
  *(int *)iVar4 = iVar4;
  *(int *)(param_1 + 0x14) = iVar4;
  local_4 = 2;
  uStack_3 = 0;
  eh_vector_constructor_iterator((void *)(param_1 + 0x300),0x50,0x14,FUN_0045a920,NullUpdate_ret);
  local_4 = 3;
  eh_vector_constructor_iterator((void *)(param_1 + 0x940),0x50,0x14,FUN_0045a920,NullUpdate_ret);
  *(undefined4 *)(param_1 + 0x13f4) = 0;
  *(undefined4 *)(param_1 + 0x13f8) = 0;
  puVar8 = (undefined4 *)(param_1 + 0x1250);
  for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  FUN_00458f10(0,0);
  *(undefined4 *)(param_1 + 0x15b4) = 0;
  *(undefined4 *)(param_1 + 0x15b8) = 0;
  puVar8 = (undefined4 *)(param_1 + 0x1410);
  for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  FUN_00458f10(0,0);
  *(undefined4 *)(param_1 + 0x1774) = 0;
  *(undefined4 *)(param_1 + 0x1778) = 0;
  puVar8 = (undefined4 *)(param_1 + 0x15d0);
  for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  FUN_00458f10(0,0);
  DAT_007361f8 = param_1;
  DAT_0073ad34 = 4000;
  _DAT_006f0898 = 0x3f800000;
  DAT_006f089c = 1;
  DAT_006f08a0 = 1;
  _DAT_00734578 = 0;
  DAT_0073457c = 0;
  _DAT_00734580 = 0;
  DAT_006f08a4 = 0;
  uVar7 = DAT_006f227c % 0x7fffffff;
  uVar5 = DAT_006f227c ^ 0x1d872b41;
  uVar1 = uVar5 >> 5 ^ uVar5;
  DAT_006f227c = uVar1 << 0x1b ^ uVar1 ^ uVar5;
  *(undefined4 *)(param_1 + 0x2f4) = 1;
  *(undefined4 *)(param_1 + 0x2f8) = 1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  *(undefined4 *)(param_1 + 0x2e0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2e4) = 0;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  *(undefined4 *)(param_1 + 0x2e8) = 0;
  *(undefined4 *)(param_1 + 0x2ec) = 0;
  *(undefined4 *)(param_1 + 0x2dc) = 0;
  *(uint *)(param_1 + 0x2d0) = uVar7;
  puVar8 = (undefined4 *)(param_1 + 0x280);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined4 *)(param_1 + 0x2c8) = 0;
  *(undefined4 *)(param_1 + 0x2cc) = 0;
  pvVar2 = _malloc(0x1a0);
  local_4 = 5;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00598440();
  }
  _local_4 = CONCAT31(uStack_3,4);
  *(undefined4 *)(param_1 + 0x2f0) = uVar3;
  FUN_005697b0();
  FUN_0058a000();
  FUN_00589ba0();
  FUN_00593880();
  FUN_00574fd0();
  DAT_00735ee4 = 0;
  StreamBoundaries__DebugDump();
  iVar4 = 0;
  if (0 < DAT_007372c8) {
    iVar6 = 0;
    do {
      *(undefined2 *)(iVar6 + 0x1a + DAT_007372cc) = 0;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0xb4;
    } while (iVar4 < DAT_007372c8);
  }
  Smackables__Init();
  FUN_00598360();
  FUN_00579510();
  WorldObjectCohort__Launch(0,0);
  if (DAT_007345c0 != 0) {
    FUN_00577d80();
  }
  pvVar2 = _malloc(8);
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x1794) = 0;
  }
  else {
    *(void **)pvVar2 = pvVar2;
    *(void **)((int)pvVar2 + 4) = pvVar2;
    *(void **)(param_1 + 0x1794) = pvVar2;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x41f9a0 thunk_FUN_00421900

void thunk_FUN_00421900(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  bool bVar5;
  
  piVar1 = (int *)*unaff_EDI;
  iVar3 = DAT_007349b4;
  while (piVar1 != unaff_EDI) {
    iVar4 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    iVar4 = *(int *)(iVar3 + 0x18);
    *piVar1 = *(int *)(iVar3 + 0x10);
    *(int **)(iVar3 + 0x10) = piVar1;
    iVar4 = iVar4 + -1;
    bVar5 = DAT_007349b8 != 0;
    *(int *)(iVar3 + 0x18) = iVar4;
    if (bVar5) {
      if (iVar4 == 0) {
        SlotPool__Destroy();
        iVar3 = 0;
        DAT_007349b4 = 0;
      }
      else {
        DAT_007349b8 = 1;
      }
    }
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x41f9b0 FUN_0041f9b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f9b0(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687fa0;
  pvStack_c = ExceptionList;
  local_4 = 4;
  ExceptionList = &pvStack_c;
  if (DAT_007301d4 != 0) {
    ExceptionList = &pvStack_c;
    bMemoryPool_Validate(DAT_007301d4,1);
  }
  pvVar1 = DAT_00734460;
  if (DAT_00734460 != (void *)0x0) {
    eh_vector_destructor_iterator(DAT_00734460,8,0xcb,FUN_004049f0);
    _free(pvVar1);
    DAT_00734460 = (void *)0x0;
  }
  if (DAT_00736200 == 0) {
    FUN_004682c0();
  }
  else {
    FUN_00593620();
  }
  FUN_00627bf0();
  FUN_00577880();
  FUN_005793e0();
  if (DAT_007345b8 != (void *)0x0) {
    pvVar1 = (void *)((int)DAT_007345b8 + -4);
    eh_vector_destructor_iterator(DAT_007345b8,8,*(int *)((int)DAT_007345b8 + -4),FUN_00579720);
    _free(pvVar1);
  }
  FUN_00578b10(0);
  (**(code **)(*DAT_0070d364 + 0x34))();
  FUN_00595ea0();
  if (DAT_0073613c != (int *)0x0) {
    if ((DAT_0073613c[2] != 0) || (DAT_0073613c[3] != 0)) {
      iVar2 = *DAT_0073613c;
      piVar3 = (int *)DAT_0073613c[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
    }
    iVar4 = DAT_0073557c;
    DAT_0073613c[3] = 0;
    DAT_0073613c[2] = 0;
    DAT_0073613c[4] = 0;
    DAT_0073613c[5] = 0;
    iVar2 = *(int *)(iVar4 + 0x18);
    *DAT_0073613c = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = DAT_0073613c;
  }
  DAT_0073613c = (int *)0x0;
  FUN_005939d0();
  FUN_00593790();
  if (DAT_00734510 != 0) {
    FUN_0058a050();
    SlotPool__Destroy();
    DAT_00734510 = 0;
  }
  FUN_00589c90();
  SlotPool__Destroy();
  pvVar1 = *(void **)(param_1 + 0x2f0);
  if (pvVar1 != (void *)0x0) {
    FUN_005984d0();
    _free(pvVar1);
  }
  DAT_0073ad34 = 4000;
  _DAT_006f0898 = 0x3f800000;
  DAT_006f089c = 1;
  DAT_006f08a0 = 1;
  _DAT_00734578 = 0;
  DAT_0073457c = 0;
  _DAT_00734580 = 0;
  DAT_006f08a4 = 100000;
  pvVar1 = *(void **)(param_1 + 0x1794);
  DAT_007361f8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004665a0();
    _free(pvVar1);
  }
  local_4._0_1_ = 3;
  eh_vector_destructor_iterator((void *)(param_1 + 0x940),0x50,0x14,NullUpdate_ret);
  local_4._0_1_ = 2;
  eh_vector_destructor_iterator((void *)(param_1 + 0x300),0x50,0x14,NullUpdate_ret);
  FUN_004219b0(param_1 + 0x10);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00421900();
  local_4 = 0xffffffff;
  FUN_00421980();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x41fc00 FUN_0041fc00

void FUN_0041fc00(undefined4 *param_1)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int iVar3;
  int local_8;
  
  iVar1 = (int)param_1;
  FUN_00571ea0(0,"World");
  FUN_00571c20(in_EAX,(int)param_1 + 0x2d0,4,4,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2d4,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2e0,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2e4,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2e8,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2ec,4,4,1);
  FUN_00571c20(in_EAX,(int)param_1 + 0x280,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x290,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2c0,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2c4,4,0xffffffff,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2f4,4,4,0);
  FUN_00571c20(in_EAX,(int)param_1 + 0x2f8,4,4,0);
  if (*(char *)(in_EAX + 0x3d) != '\0') {
    FUN_0058a050();
    FUN_00402cf0(&DAT_0078e9e0);
    FUN_00593980();
    DAT_007183b4 = 1;
    FUN_00574fd0();
  }
  FUN_00585ec0();
  local_8 = 0;
  if (0 < *(int *)((int)param_1 + 0x18)) {
    param_1 = (undefined4 *)((int)param_1 + 0x28);
    do {
      Car_SerializeFields(*param_1);
      local_8 = local_8 + 1;
      param_1 = param_1 + 1;
    } while (local_8 < *(int *)(iVar1 + 0x18));
  }
  if (*(int *)(iVar1 + 0x2f0) != 0) {
    Teleporter_RestoreState(in_EAX);
  }
  if (*(char *)(in_EAX + 0x3d) != '\0') {
    if (DAT_00736200 == 0) {
      FUN_004682c0();
    }
    else {
      FUN_00593620();
    }
  }
  Smackables__SaveState();
  AllTrackPolygonCollisionBodies__Serialize();
  FUN_00571ea0(0,"AllCollisionBodies");
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar1 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0x58 + in_EAX);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  FUN_00467010();
  iVar1 = DAT_0073615c;
  iVar3 = DAT_00736158;
  if (0 < DAT_0073615c) {
    do {
      TrafficIntersection_Save(iVar3);
      iVar1 = iVar1 + -1;
      iVar3 = iVar3 + 0x170;
    } while (iVar1 != 0);
  }
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar1 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0x58 + in_EAX);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x41fe50 FUN_0041fe50

void FUN_0041fe50(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_ESI;
  
  puVar1 = (undefined4 *)*unaff_ESI;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[9] = 0;
  puVar2 = (undefined4 *)NullUpdate_ret();
  for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)(puVar1[5] + 4) == 1) {
      unaff_ESI[unaff_ESI[6] + 10] = puVar1;
      unaff_ESI[6] = unaff_ESI[6] + 1;
    }
  }
  unaff_ESI[7] = unaff_ESI[6];
  for (puVar1 = (undefined4 *)*unaff_ESI; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)(puVar1[5] + 4) == 2) {
      unaff_ESI[unaff_ESI[6] + 10] = puVar1;
      unaff_ESI[6] = unaff_ESI[6] + 1;
    }
  }
  puVar1 = (undefined4 *)*unaff_ESI;
  unaff_ESI[8] = unaff_ESI[6];
  for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if ((*(int *)(puVar1[5] + 4) == 4) || (*(int *)(puVar1[5] + 4) == 5)) {
      unaff_ESI[unaff_ESI[6] + 10] = puVar1;
      unaff_ESI[6] = unaff_ESI[6] + 1;
    }
  }
  unaff_ESI[9] = unaff_ESI[6];
  for (puVar1 = (undefined4 *)*unaff_ESI; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)(puVar1[5] + 4) == 3) {
      unaff_ESI[unaff_ESI[6] + 10] = puVar1;
      unaff_ESI[6] = unaff_ESI[6] + 1;
    }
  }
  iVar3 = 0;
  if (0 < (int)unaff_ESI[6]) {
    piVar4 = unaff_ESI + 10;
    do {
      *(short *)(*piVar4 + 8) = (short)iVar3;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < (int)unaff_ESI[6]);
  }
  for (puVar1 = (undefined4 *)unaff_ESI[2]; puVar1 != unaff_ESI + 2; puVar1 = (undefined4 *)*puVar1)
  {
  }
  return;
}


// ==== 0x41ff50 FUN_0041ff50

int FUN_0041ff50(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(in_EAX + 0x18)) {
    piVar2 = (int *)(in_EAX + 0x28);
    do {
      if (*(short *)(*piVar2 + 10) == unaff_EDI) {
        return *piVar2;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(in_EAX + 0x18));
  }
  return 0;
}


// ==== 0x41ff80 FUN_0041ff80

void FUN_0041ff80(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  int local_4;
  
  local_4 = -1;
  if (*unaff_ESI != 0) {
    local_4 = (int)*(short *)(*unaff_ESI + 10);
  }
  FUN_00571c20(in_EAX,&local_4,1,4,0);
  if (*(char *)(in_EAX + 0x3d) != '\0') {
    if (-1 < local_4) {
      iVar1 = FUN_0041ff50();
      *unaff_ESI = iVar1;
      return;
    }
    *unaff_ESI = 0;
  }
  return;
}


// ==== 0x41ffe0 RaceManager::FindRacerById

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

int RaceManager__FindRacerById(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(DAT_007361f8 + 0x18)) {
    piVar2 = (int *)(DAT_007361f8 + 0x28);
    do {
      if (*(short *)(*piVar2 + 10) == unaff_EDI) {
        return *piVar2;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(DAT_007361f8 + 0x18));
  }
  return 0;
}


// ==== 0x420010 RaceManager::RacerLess

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

bool RaceManager__RacerLess(int param_1,int param_2)

{
  if (*(float *)(param_1 + 0x60) < *(float *)(param_2 + 0x60)) {
    return true;
  }
  if (*(float *)(param_2 + 0x60) < *(float *)(param_1 + 0x60)) {
    return false;
  }
  return *(short *)(param_2 + 10) <= *(short *)(param_1 + 10);
}


// ==== 0x420020 FUN_00420020

bool __fastcall FUN_00420020(int param_1,int param_2)

{
  undefined4 in_EAX;
  
  if ((POPCOUNT((byte)((uint)in_EAX >> 8) & 5) & 1U) != 0) {
    return true;
  }
  if (*(float *)(param_2 + 0x60) < *(float *)(param_1 + 0x60)) {
    return false;
  }
  return *(short *)(param_2 + 10) <= *(short *)(param_1 + 10);
}


// ==== 0x420031 FUN_00420031

bool __fastcall FUN_00420031(int param_1,int param_2)

{
  ushort in_FPUStatusWord;
  
  if ((in_FPUStatusWord & 0x4100) == 0) {
    return false;
  }
  return *(short *)(param_2 + 10) <= *(short *)(param_1 + 10);
}


// ==== 0x420041 FUN_00420041

bool __fastcall FUN_00420041(undefined4 param_1,int param_2)

{
  short in_AX;
  
  return *(short *)(param_2 + 10) <= in_AX;
}


// ==== 0x42004d FUN_0042004d

void __fastcall
FUN_0042004d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_EAX;
  uint uVar1;
  int unaff_EBX;
  
  *(char *)(unaff_EBX + -0x74fbdbb4) = *(char *)(unaff_EBX + -0x74fbdbb4) + (char)param_1;
  uVar1 = in_EAX - 1U & 0xffffff08;
  *(undefined4 *)(uVar1 + 0x2e0) = param_1;
  *(undefined4 *)(uVar1 + 0x2e4) = param_2;
  *(undefined4 *)(uVar1 + 0x2e8) = param_3;
  *(undefined4 *)(uVar1 + 0x2ec) = param_4;
  return;
}


// ==== 0x420050 SlowMoStart

/* [canon] camera I (C) docs/re/camera.md */

void SlowMoStart(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x2e0) = param_1;
  *(undefined4 *)(in_EAX + 0x2e4) = param_2;
  *(undefined4 *)(in_EAX + 0x2e8) = param_3;
  *(undefined4 *)(in_EAX + 0x2ec) = param_4;
  return;
}


// ==== 0x420080 FUN_00420080

void FUN_00420080(void)

{
  DAT_006ffdbc = 0;
  return;
}


// ==== 0x420090 FUN_00420090

void FUN_00420090(void)

{
  DAT_006ffdbc = 0x41f00000;
  return;
}


// ==== 0x4200a0 FUN_004200a0

void FUN_004200a0(void)

{
  float fVar1;
  int unaff_ESI;
  
  if (0.0 < *(float *)(unaff_ESI + 0x2d4)) {
    fVar1 = *(float *)(unaff_ESI + 0x2d4) - DAT_0073ad38;
    *(float *)(unaff_ESI + 0x2d4) = fVar1;
    if (fVar1 < 0.0 != (fVar1 == 0.0)) {
      *(undefined4 *)(unaff_ESI + 0x2d4) = 0;
      if (*(code **)(unaff_ESI + 0x2e8) != (code *)0x0) {
        (**(code **)(unaff_ESI + 0x2e8))(*(undefined4 *)(unaff_ESI + 0x2ec));
        *(undefined4 *)(unaff_ESI + 0x2e8) = 0;
        *(undefined4 *)(unaff_ESI + 0x2ec) = 0;
      }
    }
  }
  return;
}


// ==== 0x420110 FUN_00420110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00420110(int param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  LARGE_INTEGER local_8;
  
  iVar6 = param_1;
  piVar4 = DAT_007345d0;
  piVar8 = piVar4;
  if (*DAT_007345d0 == 0) {
    param_1 = DAT_00734568;
    if (((DAT_007345d0[1] != 0) && (DAT_007345d0[1] != 0)) &&
       (piVar1 = DAT_007345d0 + 0x19, FUN_00594120(DAT_00734568,8), piVar8 = DAT_007345d0,
       *(int *)(*piVar1 + 0x14) * 8 + -0x44 <= *(int *)(*piVar1 + 8))) {
      piVar4[1] = 0;
      piVar8 = DAT_007345d0;
    }
  }
  else if ((*DAT_007345d0 == 0) || (DAT_007345d0[2] != 0)) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00594220(8,1);
    if (*(int *)(piVar4[0x19] + 0x28) != 0) {
      piVar4[2] = 1;
    }
  }
  fVar2 = (float)param_1 * 0.00027777778;
  if (((*piVar8 != 0) && (piVar8[5] == 0)) && (piVar8[4] == 0)) {
    fVar3 = (fVar2 - DAT_0073ad38) + *(float *)(iVar6 + 0x2dc);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    else if (0.03 < fVar3) {
      fVar3 = 0.03;
    }
    *(float *)(iVar6 + 0x2dc) = fVar3;
    if (0.0 < fVar3) {
      iVar7 = FUN_005648c0();
      do {
        QueryPerformanceCounter(&local_8);
        uVar5 = DAT_007349c8;
        param_1 = __allshr();
        param_1 = param_1 - iVar7;
        if (param_1 < 0) {
          param_1 = 0;
        }
      } while ((float)(1 << ((byte)uVar5 & 0x1f)) * (float)param_1 * _DAT_007301d0 * 0.001 < fVar3);
    }
  }
  if (0.0 < *(float *)(iVar6 + 0x2e4)) {
    fVar3 = *(float *)(iVar6 + 0x2e4) - fVar2;
    *(float *)(iVar6 + 0x2e4) = fVar3;
    if (fVar3 < 0.0 != (fVar3 == 0.0)) {
      *(undefined4 *)(iVar6 + 0x2e4) = 0;
      *(undefined4 *)(iVar6 + 0x2e0) = 0x3f800000;
      if (*(code **)(iVar6 + 0x2e8) != (code *)0x0) {
        (**(code **)(iVar6 + 0x2e8))(*(undefined4 *)(iVar6 + 0x2ec));
        *(undefined4 *)(iVar6 + 0x2e8) = 0;
        *(undefined4 *)(iVar6 + 0x2ec) = 0;
      }
    }
  }
  return (float10)fVar2 * (float10)*(float *)(iVar6 + 0x2e0);
}


// ==== 0x420310 FUN_00420310

void FUN_00420310(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int aiStack_2f8 [190];
  
  iVar2 = 0;
  if (DAT_00779c70 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_00779c70 + -4;
  }
  iVar1 = Ptr_BaseAdjustMinus4();
  while (iVar3 != iVar1) {
    if (*(char *)(iVar3 + 0x16) != '\0') {
      aiStack_2f8[iVar2] = iVar3;
      iVar2 = iVar2 + 1;
    }
    if (*(int *)(iVar3 + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 4) + -4;
    }
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      (**(code **)(*(int *)aiStack_2f8[iVar3] + 0x28))(param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// ==== 0x420380 FUN_00420380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420380(int param_1)

{
  char *pcVar1;
  int *piVar2;
  int *****pppppiVar3;
  int *****pppppiVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  int ******ppppppiVar14;
  undefined4 uVar15;
  int iStack_54;
  int iStack_4c;
  LARGE_INTEGER LStack_48;
  int *****pppppiStack_40;
  int *****pppppiStack_3c;
  int ****appppiStack_38 [9];
  void *pvStack_14;
  code *pcStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  pcStack_10 = FUN_00689748;
  pvStack_14 = ExceptionList;
  if (DAT_00779be0 == 0) {
    puVar13 = (undefined4 *)0x0;
  }
  else {
    puVar13 = (undefined4 *)(DAT_00779be0 + -0x250);
  }
  ExceptionList = &pvStack_14;
  puVar8 = (undefined4 *)FUN_00421970();
  while (puVar7 = puVar13, puVar7 != puVar8) {
    if (puVar7[0x94] == 0) {
      puVar13 = (undefined4 *)0x0;
    }
    else {
      puVar13 = (undefined4 *)(puVar7[0x94] + -0x250);
    }
    if (puVar7[0x99] == 0) {
      piVar2 = (int *)puVar7[0x96];
      iVar9 = puVar7[0x97];
      if (((((float)piVar2[9] < *(float *)(iVar9 + 0x2c) ==
             ((float)piVar2[9] == *(float *)(iVar9 + 0x2c))) ||
           ((float)piVar2[0xb] < *(float *)(iVar9 + 0x24))) ||
          ((float)piVar2[10] < *(float *)(iVar9 + 0x30) ==
           ((float)piVar2[10] == *(float *)(iVar9 + 0x30)))) ||
         (((((float)piVar2[0xc] < *(float *)(iVar9 + 0x28) ||
            ((*(char *)((int)piVar2 + 0x1d) == '\0' && (*(char *)(iVar9 + 0x1d) == '\0')))) ||
           (iVar9 = (**(code **)(*piVar2 + 0x50))(), iVar9 == 0)) ||
          (iVar9 = (**(code **)(*(int *)puVar7[0x97] + 0x50))(), iVar9 == 0)))) {
        (**(code **)*puVar7)(1);
      }
    }
  }
  if (DAT_00779c70 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = DAT_00779c70 + -4;
  }
  iVar10 = Ptr_BaseAdjustMinus4();
  while (iVar9 != iVar10) {
    if ((*(char *)(iVar9 + 0x16) != '\0') && (*(char *)(iVar9 + 0x1d) != '\0')) {
      WorldObjects__Broadphase(iVar9);
    }
    if (*(int *)(iVar9 + 4) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar9 + 4) + -4;
    }
  }
  pppppiStack_40 = (int *****)&pppppiStack_40;
  pppppiStack_3c = (int *****)&pppppiStack_40;
  uStack_c = 0;
  if (DAT_00779be0 == 0) {
    puVar13 = (undefined4 *)0x0;
  }
  else {
    puVar13 = (undefined4 *)(DAT_00779be0 + -0x250);
  }
  while (puVar13 != puVar8) {
    puVar13[0x98] = 0;
    FUN_00468060(&pppppiStack_40);
    if (puVar13[0x94] == 0) {
      puVar13 = (undefined4 *)0x0;
    }
    else {
      puVar13 = (undefined4 *)(puVar13[0x94] + -0x250);
    }
  }
  QueryPerformanceCounter(&LStack_48);
  iStack_4c = 0;
  if ((int ******)pppppiStack_40 != &pppppiStack_40) {
    do {
      pppppiVar4 = pppppiStack_40;
      if (DAT_00700e5c <= iStack_4c) break;
      iStack_54 = 0;
      FUN_0046b5e0();
      pppppiVar4[5][0x98] = (int ***)((int)pppppiVar4[5][0x98] + 1);
      pppppiVar3 = (int *****)pppppiVar4[3];
      uVar15 = pppppiVar4[4];
      LStack_48.s.LowPart = uVar15;
      if (*(char *)((int)pppppiVar3 + 0x16) != '\0') {
        Contact__RemoveContacts();
      }
      if (*(char *)(uVar15 + 0x16) != '\0') {
        Contact__RemoveContacts();
      }
      if ((*(char *)((int)pppppiVar3 + 0x15) == '\x01') && ((float)pppppiVar3[0x58] == -1.0)) {
        iStack_54 = Smokeable__BuildChildren(appppiStack_38);
        uVar15 = LStack_48.s.LowPart;
      }
      else if ((*(char *)((int)pppppiVar3 + 0x16) != '\0') &&
              (*(char *)((int)pppppiVar3 + 0x1d) != '\0')) {
        appppiStack_38[0] = (int ****)pppppiVar3;
        iStack_54 = 1;
      }
      if ((*(char *)(uVar15 + 0x15) == '\x01') && ((float)*(int *****)(uVar15 + 0x160) == -1.0)) {
        iVar9 = Smokeable__BuildChildren(appppiStack_38 + iStack_54);
        iStack_54 = iStack_54 + iVar9;
      }
      else if ((*(char *)(uVar15 + 0x16) != '\0') && (*(char *)(uVar15 + 0x1d) != '\0')) {
        appppiStack_38[iStack_54] = (int ****)uVar15;
        iStack_54 = iStack_54 + 1;
      }
      iVar9 = 0;
      if (0 < iStack_54) {
        do {
          WorldObjects__Broadphase(appppiStack_38[iVar9]);
          iVar9 = iVar9 + 1;
        } while (iVar9 < iStack_54);
      }
      if (DAT_00779be0 == 0) {
        puVar13 = (undefined4 *)0x0;
      }
      else {
        puVar13 = (undefined4 *)(DAT_00779be0 + -0x250);
      }
      while (puVar13 != puVar8) {
        iVar9 = 0;
        if (0 < iStack_54) {
          do {
            if ((((int ****)puVar13[0x96] == appppiStack_38[iVar9]) ||
                ((int ****)puVar13[0x97] == appppiStack_38[iVar9])) &&
               ((int)puVar13[0x98] < DAT_00700e60)) {
              FUN_00468060(&pppppiStack_40);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iStack_54);
        }
        if (puVar13[0x94] == 0) {
          puVar13 = (undefined4 *)0x0;
        }
        else {
          puVar13 = (undefined4 *)(puVar13[0x94] + -0x250);
        }
      }
      iStack_4c = iStack_4c + 1;
    } while ((int ******)pppppiStack_40 != &pppppiStack_40);
  }
  iVar9 = DAT_00735fe4;
  if (iStack_4c == DAT_00700e5c) {
    while ((int ******)pppppiStack_40 != &pppppiStack_40) {
      pppppiVar4 = (int *****)*pppppiStack_40;
      pppppiVar3 = (int *****)pppppiStack_40[1];
      *pppppiVar3 = (int ****)pppppiVar4;
      pppppiVar4[1] = (int ****)pppppiVar3;
      iVar10 = *(int *)(iVar9 + 0x18);
      *pppppiStack_40 = (int ****)*(int ******)(iVar9 + 0x10);
      *(int ******)(iVar9 + 0x10) = pppppiStack_40;
      *(int *)(iVar9 + 0x18) = iVar10 + -1;
    }
  }
  puVar13 = *(undefined4 **)(param_1 + 0x10);
  ppppppiVar14 = (int ******)pppppiStack_40;
  while (puVar8 = puVar13, puVar8 != (undefined4 *)(param_1 + 0x10)) {
    LStack_48.s.LowPart = DAT_0073ad34 - puVar8[3];
    puVar13 = (undefined4 *)*puVar8;
    if (_DAT_007000d8 <= (float)(int)LStack_48.s.LowPart * 0.00025) {
      iVar10 = puVar8[0x19];
      piVar2 = *(int **)(iVar10 + 0x264);
      if (piVar2 != (int *)0x0) {
        iVar5 = *piVar2;
        piVar6 = (int *)piVar2[1];
        *piVar6 = iVar5;
        *(int **)(iVar5 + 4) = piVar6;
        if (DAT_006f1dd8 != 0) {
          FUN_005302f0();
        }
        iVar5 = piVar2[0x19];
        iVar12 = *(int *)(iVar5 + 600);
        if (((*(char *)(iVar12 + 0x15) == '\x03') &&
            (ABS(*(float *)(*(int *)(iVar12 + 0x60) + 0x78)) < 0.1)) ||
           ((*(char *)(*(int *)(iVar5 + 0x25c) + 0x15) == '\x03' &&
            (ABS(*(float *)(*(int *)(*(int *)(iVar5 + 0x25c) + 0x60) + 0x78)) < 0.1)))) {
          if (*(char *)(iVar12 + 0x15) == '\x03') {
            iVar12 = *(int *)(iVar5 + 0x25c);
          }
          if (iVar12 != 0) {
            uVar11 = *(int *)(iVar12 + 0x130) - 1;
            *(uint *)(iVar12 + 0x130) = uVar11 & ((int)uVar11 < 0) - 1;
          }
        }
        iVar12 = DAT_00736088;
        iVar5 = *(int *)(DAT_00736088 + 0x18);
        *piVar2 = *(int *)(DAT_00736088 + 0x10);
        *(int *)(iVar12 + 0x18) = iVar5 + -1;
        *(int **)(iVar12 + 0x10) = piVar2;
      }
      *(undefined4 *)(iVar10 + 0x264) = 0;
      DAT_00736004 = DAT_00736004 + -1;
      pcVar1 = (char *)(*(int *)(iVar10 + 600) + 0x1c);
      *pcVar1 = *pcVar1 + -1;
      *(char *)(*(int *)(iVar10 + 0x25c) + 0x1c) = *(char *)(*(int *)(iVar10 + 0x25c) + 0x1c) + -1;
      ppppppiVar14 = (int ******)pppppiStack_40;
    }
  }
  if (ppppppiVar14 != &pppppiStack_40) {
    do {
      pppppiVar4 = *ppppppiVar14;
      pppppiVar3 = ppppppiVar14[1];
      *pppppiVar3 = (int ****)pppppiVar4;
      pppppiVar4[1] = (int ****)pppppiVar3;
      iVar10 = *(int *)(iVar9 + 0x18);
      *ppppppiVar14 = *(int ******)(iVar9 + 0x10);
      *(int *******)(iVar9 + 0x10) = ppppppiVar14;
      *(int *)(iVar9 + 0x18) = iVar10 + -1;
      ppppppiVar14 = (int ******)pppppiStack_40;
    } while ((int ******)pppppiStack_40 != &pppppiStack_40);
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== 0x420890 FUN_00420890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420890(int param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 auStack_80 [32];
  
  iVar6 = DAT_00779c70;
  if (DAT_00779c70 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = DAT_00779c70 + -4;
  }
  iVar4 = Ptr_BaseAdjustMinus4();
  puVar3 = DAT_007377e8;
  while (DAT_007377e8 = puVar3, iVar7 != iVar4) {
    if (*(int *)(iVar7 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar7 + 4) + -4;
    }
    pcVar1 = (char *)(iVar7 + 0x16);
    iVar7 = iVar6;
    iVar6 = DAT_00779c70;
    if (*pcVar1 != '\0') {
      FUN_00468d70(param_2);
      puVar3 = DAT_007377e8;
      iVar6 = DAT_00779c70;
    }
  }
  puVar5 = (undefined4 *)NullUpdate_ret();
  while (puVar3 != puVar5) {
    puVar2 = (undefined4 *)*puVar3;
    puVar3[2] = param_2;
    puVar3[3] = 0;
    puVar3[4] = 0xbf800000;
    if (puVar3[5] == 0) {
      DAT_007313f4 = 0;
    }
    FUN_00592b30(puVar3);
    iVar6 = DAT_00779c70;
    puVar3 = puVar2;
  }
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = iVar6 + -4;
  }
  while (iVar6 != iVar4) {
    if ((*(undefined **)(iVar6 + 0xc) != &DAT_007377f0) && (*(char *)(iVar6 + 0x1a) == '\0')) {
      *(undefined **)(iVar6 + 0xc) = &DAT_007377f0;
    }
    if (*(int *)(iVar6 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 4) + -4;
    }
  }
  _DAT_007377f8 = param_2;
  _DAT_007377fc = 0;
  _DAT_00737800 = 0xbf800000;
  if (DAT_00737804 == 0) {
    DAT_007313f4 = 0;
  }
  FUN_00592c50();
  iVar6 = 0;
  for (puVar3 = DAT_007377e8; puVar3 != puVar5; puVar3 = (undefined4 *)*puVar3) {
    FUN_00592e80();
    auStack_80[iVar6] = puVar3;
    iVar6 = iVar6 + 1;
  }
  iVar7 = 0;
  if (0 < iVar6) {
    do {
      FUN_00593100();
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar6);
  }
  if (DAT_00736204 != 0) {
    if ((undefined4 **)DAT_007377e8 == &DAT_007377e8) goto LAB_00420a80;
    FUN_005936d0();
  }
  if ((undefined4 **)DAT_007377e8 != &DAT_007377e8) {
    do {
      FUN_00592d50();
      puVar3 = DAT_007377e8;
      if (DAT_00736204 != 0) {
        for (; puVar3 != puVar5; puVar3 = (undefined4 *)*puVar3) {
          for (puVar2 = (undefined4 *)puVar3[7]; puVar2 != puVar3 + 7;
              puVar2 = (undefined4 *)*puVar2) {
          }
        }
      }
    } while ((float)DAT_007377e8[3] != (float)DAT_007377e8[2]);
  }
LAB_00420a80:
  FUN_00592d50();
  iVar6 = DAT_00736088;
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  while (puVar5 = puVar3, puVar5 != (undefined4 *)(param_1 + 0x10)) {
    puVar3 = (undefined4 *)*puVar5;
    if (_DAT_007000d8 <= (float)(DAT_0073ad34 - puVar5[3]) * 0.00025) {
      iVar7 = puVar5[0x19];
      puVar5 = *(undefined4 **)(iVar7 + 0x264);
      if (puVar5 != (undefined4 *)0x0) {
        FUN_00465700();
        iVar4 = *(int *)(iVar6 + 0x18);
        *puVar5 = *(undefined4 *)(iVar6 + 0x10);
        *(int *)(iVar6 + 0x18) = iVar4 + -1;
        *(undefined4 **)(iVar6 + 0x10) = puVar5;
      }
      *(undefined4 *)(iVar7 + 0x264) = 0;
      DAT_00736004 = DAT_00736004 + -1;
      pcVar1 = (char *)(*(int *)(iVar7 + 600) + 0x1c);
      *pcVar1 = *pcVar1 + -1;
      pcVar1 = (char *)(*(int *)(iVar7 + 0x25c) + 0x1c);
      *pcVar1 = *pcVar1 + -1;
    }
  }
  DAT_00736204 = 0;
  return;
}


// ==== 0x420b40 FUN_00420b40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420b40(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  float *pfVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  int local_10;
  int local_c;
  int *local_8;
  
  FUN_004211f0();
  _DAT_006f0738 = 0;
  FUN_0042a790();
  FUN_00577010();
  puVar10 = DAT_0073b07c;
  puVar7 = (undefined4 *)NullUpdate_ret();
  for (; puVar10 != puVar7; puVar10 = (undefined4 *)*puVar10) {
    FUN_0057a530();
  }
  iVar13 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    puVar10 = (undefined4 *)(param_1 + 0x288);
    puVar7 = (undefined4 *)(param_1 + 0x2c0);
    do {
      iVar12 = puVar7[-0xa6];
      uVar1 = *(undefined4 *)(iVar12 + 100);
      uVar2 = *(undefined4 *)(iVar12 + 0x68);
      puVar10[-2] = *(undefined4 *)(iVar12 + 0x60);
      iVar13 = iVar13 + 1;
      puVar10[-1] = uVar1;
      *puVar10 = uVar2;
      *puVar7 = *(undefined4 *)(iVar12 + 0x814);
      puVar10 = puVar10 + 4;
      puVar7 = puVar7 + 1;
    } while (iVar13 < *(int *)(param_1 + 0x1c));
  }
  iVar13 = *(int *)(param_1 + 0x1c);
  if (iVar13 < 4) {
    puVar10 = (undefined4 *)(param_1 + 0x2c0 + iVar13 * 4);
    iVar12 = 4 - iVar13;
    puVar7 = (undefined4 *)(iVar13 * 0x10 + 0x288 + param_1);
    do {
      puVar7[-2] = 0x4b18967f;
      puVar7[-1] = 0x4b18967f;
      *puVar7 = 0x4b18967f;
      *puVar10 = 0x4b18967f;
      puVar7 = puVar7 + 4;
      puVar10 = puVar10 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if (((DAT_00736208 != 0) && (0 < DAT_007361c4)) &&
     (iVar13 = *(int *)(DAT_007361bc + 4), DAT_00736208 != *(int *)(iVar13 + 0x24))) {
    FUN_00425fe0();
    if (DAT_00736208 == 1) {
      Car_SetMode();
      piVar11 = *(int **)(iVar13 + 0x30);
      if (piVar11 != (int *)0x0) {
        (**(code **)(*piVar11 + 0x10))(0);
        (**(code **)(*piVar11 + 0x14))();
        (**(code **)(*piVar11 + 0x20))();
        RealDriver__SetManualTransmission();
      }
    }
    else if (DAT_00736208 == 3) {
      Car_SetMode();
    }
  }
  if (*(int *)(param_1 + 0x2f0) != 0) {
    TrafficTeleporter__DoTimestep(param_2);
  }
  iVar13 = *(int *)(param_1 + 0x1c);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x20) != iVar13 && -1 < *(int *)(param_1 + 0x20) - iVar13) {
    do {
      iVar13 = *(int *)(param_1 + 0x28 + (iVar13 + iVar12) * 4);
      fVar14 = (float10)FUN_00426450();
      *(float *)(iVar13 + 0x47c) = (float)fVar14;
      (**(code **)(**(int **)(iVar13 + 0x2c) + 0xc))(param_2);
      iVar13 = *(int *)(param_1 + 0x1c);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x20) - iVar13);
  }
  iVar13 = *(int *)(param_1 + 0x24);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x18) != iVar13 && -1 < *(int *)(param_1 + 0x18) - iVar13) {
    do {
      iVar13 = *(int *)(param_1 + 0x28 + (iVar13 + iVar12) * 4);
      fVar14 = (float10)FUN_00426450();
      *(float *)(iVar13 + 0x47c) = (float)fVar14;
      (**(code **)(**(int **)(iVar13 + 0x2c) + 0xc))(param_2);
      iVar13 = *(int *)(param_1 + 0x24);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x18) - iVar13);
  }
  iVar13 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    local_8 = (int *)(param_1 + 0x28);
    do {
      iVar12 = *local_8;
      fVar14 = (float10)FUN_00426450();
      *(float *)(iVar12 + 0x47c) = (float)fVar14;
      (**(code **)(**(int **)(iVar12 + 0x2c) + 0xc))(param_2);
      iVar13 = iVar13 + 1;
      local_8 = local_8 + 1;
    } while (iVar13 < *(int *)(param_1 + 0x1c));
  }
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    local_8 = (int *)(param_1 + 0x28);
    do {
      if (*(int *)(*local_8 + 0x18) != 0) {
        iVar13 = 0;
        do {
          FUN_00429620();
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    } while (local_c < *(int *)(param_1 + 0x1c));
  }
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    piVar11 = (int *)(param_1 + 0x28);
    do {
      iVar13 = *piVar11;
      (**(code **)(**(int **)(iVar13 + 0x30) + 4))(param_2);
      if (*(int *)(iVar13 + 0x880) != 0) {
        *(int *)(iVar13 + 0x880) = *(int *)(iVar13 + 0x880) + -1;
      }
      local_c = local_c + 1;
      piVar11 = piVar11 + 1;
    } while (local_c < *(int *)(param_1 + 0x18));
  }
  iVar13 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      FUN_004267a0(param_2);
      iVar13 = iVar13 + 1;
    } while (iVar13 < *(int *)(param_1 + 0x18));
  }
  Smackables__CleanupPool();
  if (DAT_00736200 == 0) {
    FUN_00420310(param_1,param_2);
    FUN_00420380(param_1,param_2);
  }
  else {
    FUN_00420890(param_1,param_2);
  }
  iVar13 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      JumpCamTrigger(param_2);
      iVar13 = iVar13 + 1;
    } while (iVar13 < *(int *)(param_1 + 0x18));
  }
  FUN_005795a0(param_2);
  iVar13 = DAT_0073b144;
  if (DAT_0073620c != 0) {
    while( true ) {
      if (iVar13 == 0) {
        puVar8 = (undefined *)0x0;
      }
      else {
        puVar8 = (undefined *)(iVar13 + -4);
      }
      if (puVar8 == &DAT_0073b140) break;
      iVar13 = *(int *)(puVar8 + 4);
    }
    puVar10 = DAT_0073b138;
    if ((undefined4 **)DAT_0073b138 != &DAT_0073b138) {
      do {
        FUN_00577d80();
        puVar10 = (undefined4 *)*puVar10;
      } while ((undefined4 **)puVar10 != &DAT_0073b138);
    }
    DAT_0073620c = 0;
  }
  iVar13 = 0;
  _DAT_006f0738 = 0;
  if (0 < *(int *)(DAT_007361f8 + 0x18)) {
    piVar11 = (int *)(DAT_007361f8 + 0x28);
    do {
      local_c = *piVar11;
      if (*(short *)(local_c + 10) == DAT_006fbf18) goto LAB_00420eed;
      iVar13 = iVar13 + 1;
      piVar11 = piVar11 + 1;
    } while (iVar13 < *(int *)(DAT_007361f8 + 0x18));
  }
  local_c = 0;
LAB_00420eed:
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    local_8 = (int *)(param_1 + 0x28);
    do {
      iVar13 = *local_8;
      if ((DAT_006fbf14 == 0) && (local_c != 0)) {
        pfVar9 = (float *)FUN_0041f5e0();
        fVar4 = *(float *)(iVar13 + 0x60) - *pfVar9;
        fVar6 = *(float *)(iVar13 + 100) - pfVar9[1];
        fVar5 = *(float *)(iVar13 + 0x68) - pfVar9[2];
        if (SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5) < 100.0) {
LAB_00420f74:
          FUN_004281e0();
        }
      }
      else {
        fVar14 = (float10)FUN_00421400();
        if (fVar14 < (float10)100.0) goto LAB_00420f74;
      }
      local_10 = local_10 + 1;
      local_8 = local_8 + 1;
    } while (local_10 < *(int *)(param_1 + 0x18));
  }
  iVar13 = *DAT_007361f0;
  if (((iVar13 != 5) && (iVar13 != 6)) &&
     ((iVar13 != 10 && (local_10 = 0, 0 < *(int *)(param_1 + 0x1c))))) {
    piVar11 = (int *)(param_1 + 0x28);
    do {
      if (*(int *)(*piVar11 + 0x18) != 0) {
        MaybeCameraShake();
      }
      iVar13 = *DAT_007361f0;
      if (((iVar13 != 5) && (iVar13 != 6)) && (iVar13 != 10)) {
        FUN_00429270();
      }
      local_10 = local_10 + 1;
      piVar11 = piVar11 + 1;
    } while (local_10 < *(int *)(param_1 + 0x1c));
  }
  Particles_UpdateSystem(&DAT_0078e9e0,param_2);
  local_8 = (int *)0x0;
  if (0 < *(int *)(param_1 + 0x18)) {
    param_2 = (int *)(param_1 + 0x28);
    do {
      iVar13 = *param_2;
      fVar14 = (float10)FUN_00421400();
      if ((DAT_006fbf14 == 0) && (local_c != 0)) {
        pfVar9 = (float *)FUN_0041f5e0();
        fVar4 = *(float *)(iVar13 + 0x60) - *pfVar9;
        fVar6 = *(float *)(iVar13 + 100) - pfVar9[1];
        fVar5 = *(float *)(iVar13 + 0x68) - pfVar9[2];
        if (((SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5) < 150.0) &&
            (*(int *)(*(int *)(iVar13 + 0x14) + 4) != 3)) && (*(char *)(iVar13 + 0x8a8) == '\0')) {
          cVar3 = *(char *)(iVar13 + 0x4d0);
joined_r0x004210dd:
          if (cVar3 != '\0') {
            FUN_004286a0((float)fVar14);
          }
        }
      }
      else {
        fVar15 = (float10)FUN_00421400();
        if ((fVar15 < (float10)150.0) &&
           ((*(int *)(*(int *)(iVar13 + 0x14) + 4) != 3 && (*(char *)(iVar13 + 0x8a8) == '\0')))) {
          cVar3 = *(char *)(iVar13 + 0x4d0);
          goto joined_r0x004210dd;
        }
      }
      param_2 = param_2 + 1;
      local_8 = (int *)((int)local_8 + 1);
    } while ((int)local_8 < *(int *)(param_1 + 0x18));
  }
  FUN_00589f00();
  FUN_0058e040();
  bList__Sort(param_1,RaceManager__RacerLess);
  iVar13 = 0;
  if (0 < DAT_007361c4) {
    do {
      Player__StartRaceCameras();
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_007361c4);
  }
  FUN_005793e0();
  if (DAT_0073619c != 0) {
    FUN_00435570();
  }
  return;
}


