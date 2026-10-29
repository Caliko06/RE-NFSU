// ==== 0x641390 FUN_00641390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00641390(void)

{
  HWND hWnd;
  BOOL BVar1;
  int iVar2;
  tagMSG local_1c;
  
  hWnd = (HWND)FUN_00640bc0();
  FUN_00641a70(&DAT_0070f6cc);
  _DAT_0070fd74 = 1;
  FUN_00641ac0(&DAT_0070f6cc);
  FUN_00641b10(&DAT_0070f6cc);
  DAT_0070fd78 = 0;
  _DAT_0070fd74 = 0;
  DAT_0070fcc8 = hWnd;
  _DAT_0070fccc = hWnd;
  if (DAT_0070fcd0 == 0) {
    GetClientRect(hWnd,(LPRECT)&local_1c);
    ClientToScreen(hWnd,(LPPOINT)&local_1c);
    _DAT_0070fcd4 = local_1c.hwnd;
    _DAT_0070fcd8 = local_1c.message;
  }
  else {
    SetForegroundWindow(hWnd);
    _DAT_0070fcd4 = (HWND)0x0;
    _DAT_0070fcd8 = 0;
  }
  SetActiveWindow(hWnd);
  DAT_0070f6fc = '\x01';
  while (hWnd == DAT_0070fcc8) {
    BVar1 = GetMessageA(&local_1c,(HWND)0x0,0,0);
    if (BVar1 == 0) {
      if (DAT_0070fdac == (code *)0x0) {
        FUN_0063eea0(FUN_00640030,1,10);
      }
      else {
        (*DAT_0070fdac)();
      }
    }
    else {
      CriticalSection__Enter(&DAT_0070fca0);
      if ((DAT_0070fda4 == 0) && (iVar2 = FUN_006401d0(local_1c.wParam), iVar2 == 0)) {
        TranslateMessage(&local_1c);
      }
      DispatchMessageA(&local_1c);
      CriticalSection__Leave(&DAT_0070fca0);
    }
    if (DAT_0070fd78 != 0) {
      DAT_0070fd78 = 0;
      DestroyWindow(DAT_0070fcc8);
      DAT_0070fcc8 = (HWND)0x0;
    }
    if (DAT_0070fcd0 != 0) {
      if ((DAT_0070f6fc == '\0') || (DAT_0070fcc8 == (HWND)0x0)) {
        BVar1 = IsIconic(DAT_0070fcc8);
        if (BVar1 == 0) {
          SetForegroundWindow(DAT_0070fcc8);
        }
      }
      else {
        ShowCursor(0);
      }
    }
  }
  return;
}


// ==== 0x641a10 FUN_00641a10

void FUN_00641a10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0070fddc != 0) {
    FUN_00643860(param_1,param_2,param_3);
    return;
  }
  if (DAT_0070fde0 != 0) {
    FUN_00643910();
    return;
  }
  if (DAT_0070fdd8 != 0) {
    FUN_006437b0(param_1,param_2,param_3);
    return;
  }
  FUN_006436f0();
  return;
}


// ==== 0x641a70 FUN_00641a70

undefined4 FUN_00641a70(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  if (pvVar1 != (HANDLE)0x0) {
    *(HANDLE *)(param_1 + 4) = pvVar1;
    return 1;
  }
  return 0;
}


// ==== 0x641a90 FUN_00641a90

void FUN_00641a90(int param_1)

{
  SetEvent(*(HANDLE *)(param_1 + 4));
  return;
}


// ==== 0x641ac0 FUN_00641ac0

void FUN_00641ac0(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return;
}


// ==== 0x641b10 FUN_00641b10

void FUN_00641b10(int param_1)

{
  CloseHandle(*(HANDLE *)(param_1 + 4));
  return;
}


// ==== 0x641b20 FUN_00641b20

undefined4 FUN_00641b20(undefined4 param_1)

{
  return param_1;
}


// ==== 0x641b50 FUN_00641b50

undefined4 __fastcall FUN_00641b50(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_ESI;
  
  uVar3 = 0;
  if ((unaff_ESI != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    piVar4 = (int *)param_1[2];
    if (unaff_ESI == piVar4) {
      *param_1 = iVar1 + -1;
      if (unaff_ESI != (int *)param_1[3]) {
        param_1[2] = *unaff_ESI;
        *unaff_ESI = 0;
        param_1[1] = param_1[1] | 1;
        return 1;
      }
      param_1[2] = 0;
      param_1[3] = 0;
      *unaff_ESI = 0;
      param_1[1] = param_1[1] | 1;
      return 1;
    }
    if (*piVar4 != 0) {
      do {
        piVar2 = (int *)*piVar4;
        if (piVar2 == unaff_ESI) break;
        piVar4 = piVar2;
      } while (*piVar2 != 0);
      if (((int *)*piVar4 != (int *)0x0) && ((int *)*piVar4 == unaff_ESI)) {
        *param_1 = iVar1 + -1;
        *piVar4 = *unaff_ESI;
        uVar3 = 1;
        if (unaff_ESI == (int *)param_1[3]) {
          param_1[3] = (int)piVar4;
        }
        *unaff_ESI = 0;
        param_1[1] = param_1[1] | 1;
      }
    }
  }
  return uVar3;
}


// ==== 0x641bf0 FUN_00641bf0

void FUN_00641bf0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  CriticalSection__Init(param_1 + 6);
  *param_1 = 0;
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_2 != 0) {
    param_1[5] = param_3;
    param_1[4] = param_2;
    return;
  }
  param_1[5] = param_3;
  param_1[4] = FUN_00641b20;
  return;
}


// ==== 0x641c40 FUN_00641c40

void FUN_00641c40(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_4 + 0x18);
  puVar3 = param_1 + 6;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_2 != 0) {
    param_1[4] = param_2;
    param_1[5] = param_3;
    return;
  }
  param_1[4] = FUN_00641b20;
  param_1[5] = param_3;
  return;
}


// ==== 0x641c90 FUN_00641c90

void FUN_00641c90(int param_1)

{
  if ((*(byte *)(param_1 + 4) & 2) != 0) {
    FUN_0063f170();
    return;
  }
  return;
}


// ==== 0x641cb0 FUN_00641cb0

void FUN_00641cb0(int *param_1,int *param_2)

{
  CriticalSection__Enter(param_1 + 6);
  if (param_2 != (int *)0x0) {
    *param_2 = param_1[2];
    param_1[2] = (int)param_2;
    *param_1 = *param_1 + 1;
    if (*param_2 == 0) {
      param_1[3] = (int)param_2;
    }
    param_1[1] = param_1[1] | 1;
  }
  CriticalSection__Leave(param_1 + 6);
  return;
}


// ==== 0x641cf0 FUN_00641cf0

void FUN_00641cf0(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  CriticalSection__Enter(param_1 + 6);
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)param_1[3];
    *param_2 = 0;
    *param_1 = *param_1 + 1;
    param_1[3] = (int)param_2;
    if (puVar1 == (undefined4 *)0x0) {
      param_1[2] = (int)param_2;
    }
    else {
      *puVar1 = param_2;
    }
    param_1[1] = param_1[1] | 1;
  }
  CriticalSection__Leave(param_1 + 6);
  return;
}


// ==== 0x641d40 FUN_00641d40

int * FUN_00641d40(int *param_1)

{
  int *piVar1;
  
  CriticalSection__Enter(param_1 + 6);
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    if (piVar1 == (int *)param_1[3]) {
      param_1[3] = 0;
      param_1[2] = 0;
    }
    else {
      param_1[2] = *piVar1;
    }
    *param_1 = *param_1 + -1;
    *piVar1 = 0;
  }
  param_1[1] = param_1[1] | 1;
  CriticalSection__Leave(param_1 + 6);
  return piVar1;
}


// ==== 0x641e00 FUN_00641e00

void FUN_00641e00(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  CriticalSection__Enter(param_1 + 6);
  if (param_2 != (undefined4 *)0x0) {
    uVar4 = (*(code *)param_1[4])(param_2,param_1[5]);
    *param_1 = *param_1 + 1;
    puVar3 = (undefined4 *)param_1[2];
    puVar2 = (undefined4 *)0x0;
    while ((puVar1 = puVar3, puVar1 != (undefined4 *)0x0 &&
           (uVar5 = (*(code *)param_1[4])(puVar1,param_1[5]), uVar5 < uVar4))) {
      puVar3 = (undefined4 *)*puVar1;
      puVar2 = puVar1;
    }
    *param_2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
      param_1[2] = (int)param_2;
    }
    else {
      *puVar2 = param_2;
    }
    if (puVar1 == (undefined4 *)0x0) {
      param_1[3] = (int)param_2;
    }
    param_1[1] = param_1[1] | 1;
  }
  CriticalSection__Leave(param_1 + 6);
  return;
}


// ==== 0x641e90 FUN_00641e90

undefined4 FUN_00641e90(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  CriticalSection__Enter(param_1 + 0x18);
  if (param_2 != 0) {
    uVar1 = FUN_00641b50();
  }
  CriticalSection__Leave(param_1 + 0x18);
  return uVar1;
}


// ==== 0x641fb0 FUN_00641fb0

undefined4 * FUN_00641fb0(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  CriticalSection__Enter(param_1 + 0x18);
  puVar1 = *(undefined4 **)(param_1 + 8);
  while (((puVar1 != (undefined4 *)0x0 && (param_2 != (code *)0x0)) &&
         (iVar2 = (*param_2)(puVar1,param_3), iVar2 == 0))) {
    puVar1 = (undefined4 *)*puVar1;
  }
  CriticalSection__Leave(param_1 + 0x18);
  return puVar1;
}


// ==== 0x6420d0 FUN_006420d0

int * FUN_006420d0(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_1 + 0x18;
  CriticalSection__Enter(iVar1);
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 != (int *)0x0) {
    while ((param_2 != (code *)0x0 && (iVar2 = (*param_2)(piVar3,param_3), iVar2 == 0))) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) {
        CriticalSection__Leave(iVar1);
        return (int *)0x0;
      }
    }
    if ((piVar3 != (int *)0x0) && (iVar2 = FUN_00641b50(), iVar2 == 0)) {
      piVar3 = (int *)0x0;
    }
  }
  CriticalSection__Leave(iVar1);
  return piVar3;
}


// ==== 0x642150 FUN_00642150

undefined4 * FUN_00642150(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  CriticalSection__Enter(param_1 + 0x18);
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    if (param_2 != 0) {
      puVar2 = (undefined4 *)*puVar2;
      while ((puVar2 != (undefined4 *)0x0 && (param_2 = param_2 + -1, param_2 != 0))) {
        puVar2 = (undefined4 *)*puVar2;
      }
    }
    if ((puVar2 == (undefined4 *)0x0) || (iVar1 = FUN_00641b50(), iVar1 != 0)) goto LAB_006421a0;
  }
  puVar2 = (undefined4 *)0x0;
LAB_006421a0:
  CriticalSection__Leave(param_1 + 0x18);
  return puVar2;
}


// ==== 0x642210 FUN_00642210

int * FUN_00642210(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = param_1 + 0x18;
  CriticalSection__Enter(iVar1);
  piVar4 = *(int **)(param_1 + 8);
  if (piVar4 != (int *)0x0) {
    while (uVar2 = (**(code **)(param_1 + 0x10))(piVar4,*(undefined4 *)(param_1 + 0x14)),
          uVar2 < param_2) {
      piVar4 = (int *)*piVar4;
      if (piVar4 == (int *)0x0) {
        CriticalSection__Leave(iVar1);
        return (int *)0x0;
      }
    }
    if (((piVar4 != (int *)0x0) &&
        (uVar2 = (**(code **)(param_1 + 0x10))(piVar4,*(undefined4 *)(param_1 + 0x14)),
        uVar2 == param_2)) && (iVar3 = FUN_00641b50(), iVar3 != 0)) goto LAB_00642275;
  }
  piVar4 = (int *)0x0;
LAB_00642275:
  CriticalSection__Leave(iVar1);
  return piVar4;
}


// ==== 0x642290 FUN_00642290

int FUN_00642290(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_4;
  
  iVar1 = param_1 + 0x18;
  local_4 = 0;
  CriticalSection__Enter(iVar1);
  uVar2 = *(uint *)(param_1 + 4);
  *(uint *)(param_1 + 4) = uVar2 & 0xfffffffe;
  CriticalSection__Leave(iVar1);
  puVar3 = *(undefined4 **)(param_1 + 8);
  while ((puVar3 != (undefined4 *)0x0 && ((*(byte *)(param_1 + 4) & 1) == 0))) {
    iVar4 = (*param_2)(puVar3,param_3);
    if (iVar4 == 0) {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    puVar3 = (undefined4 *)*puVar3;
    local_4 = local_4 + 1;
  }
  CriticalSection__Enter(iVar1);
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    local_4 = -1;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | uVar2 & 1;
  CriticalSection__Leave(iVar1);
  return local_4;
}


// ==== 0x642330 FUN_00642330

undefined4 FUN_00642330(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  CriticalSection__Enter(param_1 + 0x18);
  uVar1 = FUN_00642290(param_1,param_2,param_3);
  CriticalSection__Leave(param_1 + 0x18);
  return uVar1;
}


// ==== 0x642360 FUN_00642360

undefined4 FUN_00642360(int param_1)

{
  CriticalSection__Enter(param_1 + 0x18);
  return 0;
}


// ==== 0x642380 FUN_00642380

void FUN_00642380(int param_1)

{
  CriticalSection__Leave(param_1 + 0x18);
  return;
}


// ==== 0x642450 Log_Printf

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void Log_Printf(int param_1)

{
  undefined1 local_200 [512];
  
  if (param_1 == 0) {
    local_200[0] = 0;
  }
  else {
    _vsprintf(local_200,param_1,&stack0x00000008);
  }
  (*(code *)PTR_Error_Printf_006e76ac)(&DAT_006cc568,local_200);
  return;
}


// ==== 0x6424a0 Error_Printf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void Error_Printf(int param_1)

{
  undefined1 local_200 [512];
  
  if (param_1 == 0) {
    local_200[0] = 0;
  }
  else {
    _vsprintf(local_200,param_1,&stack0x00000008);
  }
  FUN_00642e60(2,"ERROR: %s",local_200);
  if (DAT_0070fe30 != 0) {
    FUN_00642e60(2,"FILE %s LINE %d\n",DAT_0070fe30,DAT_0070fe34);
  }
  FUN_00642540();
  return;
}


// ==== 0x64252b FUN_0064252b

void FUN_0064252b(void)

{
  undefined4 *unaff_ESI;
  char in_SF;
  char in_OF;
  
  while (in_OF == in_SF) {
    if ((code *)*unaff_ESI != (code *)0x0) {
      (*(code *)*unaff_ESI)();
    }
    *unaff_ESI = 0;
    in_SF = (int)(unaff_ESI + -0x1c3f8f) < 0;
    in_OF = SBORROW4((int)(unaff_ESI + -1),0x70fe38);
    unaff_ESI = unaff_ESI + -1;
  }
  return;
}


// ==== 0x64252e FUN_0064252e

void FUN_0064252e(void)

{
  undefined4 in_EAX;
  
  out(0x5e,in_EAX);
  return;
}


// ==== 0x64252f FUN_0064252f

void FUN_0064252f(void)

{
  return;
}


// ==== 0x642530 FUN_00642530

void FUN_00642530(void)

{
  return;
}


// ==== 0x64253d FUN_0064253d

/* WARNING: Control flow encountered bad instruction data */

void FUN_0064253d(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x642540 FUN_00642540

void FUN_00642540(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_retaddr;
  
  puVar3 = &DAT_0070ff34;
  do {
    if ((code *)*puVar3 != (code *)0x0) {
      (*(code *)*puVar3)();
    }
    *puVar3 = 0;
    puVar3 = puVar3 + -1;
  } while (0x70fe37 < (int)puVar3);
  FUN_006720ea(0);
  piVar1 = &DAT_0070fe38;
  do {
    if (*piVar1 == unaff_retaddr) {
      return;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x70ff38);
  iVar2 = 0;
  do {
    if ((&DAT_0070fe38)[iVar2] == 0) {
      (&DAT_0070fe38)[iVar2] = unaff_retaddr;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  return;
}


// ==== 0x642570 FUN_00642570

void FUN_00642570(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_0070fe38;
  do {
    if (*piVar1 == param_1) {
      return;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x70ff38);
  iVar2 = 0;
  do {
    if ((&DAT_0070fe38)[iVar2] == 0) {
      (&DAT_0070fe38)[iVar2] = param_1;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  return;
}


// ==== 0x642774 FUN_00642774

void FUN_00642774(void)

{
  return;
}


// ==== 0x6427d0 FUN_006427d0

int __thiscall FUN_006427d0(char *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  if (*param_1 != '\0') {
    param_2 = param_2 - (int)param_1;
    do {
      cVar2 = param_1[param_2];
      if (cVar2 == '\0') {
        return iVar4;
      }
      cVar3 = *param_1;
      if ((cVar3 < 'A') || ('Z' < cVar3)) {
        iVar6 = (int)cVar3;
      }
      else {
        iVar6 = cVar3 + 0x20;
      }
      if ((cVar2 < 'A') || ('Z' < cVar2)) {
        iVar5 = (int)cVar2;
      }
      else {
        iVar5 = cVar2 + 0x20;
      }
      if (iVar6 != iVar5) {
        return iVar4;
      }
      pcVar1 = param_1 + 1;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (*pcVar1 != '\0');
  }
  return iVar4;
}


// ==== 0x642830 FUN_00642830

void FUN_00642830(int param_1)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *unaff_EDI;
  
  uVar4 = 0;
  pcVar5 = unaff_EDI;
  while( true ) {
    pcVar2 = unaff_EDI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar3 = in_EAX - 1U;
    if ((uint)((int)pcVar2 - (int)(unaff_EDI + 1)) < in_EAX - 1U) {
      pcVar2 = unaff_EDI;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar3 = (int)pcVar2 - (int)(unaff_EDI + 1);
    }
    if (uVar3 < uVar4) break;
    cVar1 = *pcVar5;
    if ((cVar1 < 'A') || ('Z' < cVar1)) {
      pcVar5[param_1 - (int)unaff_EDI] = cVar1;
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    else {
      pcVar5[param_1 - (int)unaff_EDI] = cVar1 + ' ';
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  *(undefined1 *)(uVar4 + param_1) = 0;
  return;
}


// ==== 0x6428a0 FUN_006428a0

int FUN_006428a0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = -1;
  iVar2 = 0;
  iVar5 = 0;
  uVar4 = 0;
  do {
    if (*(int *)((int)&DAT_006e80d0 + uVar4) != 0) {
      iVar1 = FUN_006427d0(param_1);
      if (iVar2 < iVar1) {
        iVar2 = iVar1;
        iVar3 = iVar5;
      }
    }
    uVar4 = uVar4 + 0xc;
    iVar5 = iVar5 + 1;
  } while (uVar4 < 0x60);
  return iVar3;
}


// ==== 0x6428e0 FUN_006428e0

uint FUN_006428e0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0xffffffff;
  iVar4 = 0;
  uVar3 = 0;
  do {
    if ((&PTR_DAT_006e7eb0)[uVar3 * 2] != (undefined *)0x0) {
      iVar1 = FUN_006427d0(param_1);
      if (iVar4 < iVar1) {
        uVar2 = uVar3;
        iVar4 = iVar1;
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  return uVar2;
}


// ==== 0x642920 FUN_00642920

void FUN_00642920(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_104;
  undefined1 local_102;
  undefined1 local_100 [256];
  
  local_104 = 0x2c20;
  local_102 = 0;
  FUN_00642830(local_100);
  pcVar1 = (char *)FUN_00674b68(local_100,&local_104);
  do {
    if (pcVar1 == (char *)0x0) {
      return;
    }
    if (*pcVar1 == '-') {
      iVar2 = FUN_006428a0(pcVar1 + 1);
      if (-1 < iVar2) {
        uVar3 = *(uint *)(&DAT_006e80d8 + iVar2 * 0xc) & 0xfffffffe;
LAB_006429ab:
        *(uint *)(&DAT_006e80d8 + iVar2 * 0xc) = uVar3;
      }
    }
    else {
      iVar2 = FUN_006428a0(pcVar1);
      if (-1 < iVar2) {
        uVar3 = *(uint *)(&DAT_006e80d8 + iVar2 * 0xc) | 1;
        goto LAB_006429ab;
      }
    }
    pcVar1 = (char *)FUN_00674b68(0,&local_104);
  } while( true );
}


// ==== 0x6429d0 FUN_006429d0

void FUN_006429d0(void)

{
  char *pcVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  local_104 = 0x3b2c20;
  FUN_00642830(local_100);
  pcVar1 = (char *)FUN_00674b68(local_100,&local_104);
  while (pcVar1 != (char *)0x0) {
    if ((*pcVar1 == '-') || (*pcVar1 == '!')) {
      uVar5 = 0xffffffff;
      iVar2 = 0;
      uVar6 = 0;
      do {
        if (((&PTR_DAT_006e7eb0)[uVar6 * 2] != (undefined *)0x0) &&
           (iVar4 = FUN_006427d0(pcVar1 + 1), iVar2 < iVar4)) {
          uVar5 = uVar6;
          iVar2 = iVar4;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0x40);
      if (-1 < (int)uVar5) {
        if (uVar5 == 0) {
          puVar3 = &DAT_006e7eb4;
          do {
            *puVar3 = *puVar3 & 0xfffffffe;
            puVar3 = puVar3 + 2;
          } while ((int)puVar3 < 0x6e80b4);
        }
        else if (uVar5 == 1) {
          puVar3 = &DAT_006e7ebc;
          do {
            if ((puVar3[-2] & 2) != 0) {
              puVar3[-2] = puVar3[-2] & 0xfffffffe;
            }
            if ((*puVar3 & 2) != 0) {
              *puVar3 = *puVar3 & 0xfffffffe;
            }
            if ((puVar3[2] & 2) != 0) {
              puVar3[2] = puVar3[2] & 0xfffffffe;
            }
            if ((puVar3[4] & 2) != 0) {
              puVar3[4] = puVar3[4] & 0xfffffffe;
            }
            if ((puVar3[6] & 2) != 0) {
              puVar3[6] = puVar3[6] & 0xfffffffe;
            }
            if ((puVar3[8] & 2) != 0) {
              puVar3[8] = puVar3[8] & 0xfffffffe;
            }
            if ((puVar3[10] & 2) != 0) {
              puVar3[10] = puVar3[10] & 0xfffffffe;
            }
            if ((puVar3[0xc] & 2) != 0) {
              puVar3[0xc] = puVar3[0xc] & 0xfffffffe;
            }
            puVar3 = puVar3 + 0x10;
          } while ((int)puVar3 < 0x6e80bc);
        }
        else {
          (&DAT_006e7eb4)[uVar5 * 2] = (&DAT_006e7eb4)[uVar5 * 2] & 0xfffffffe;
        }
      }
    }
    else {
      iVar2 = FUN_006428e0(pcVar1);
      if (-1 < iVar2) {
        if (iVar2 == 0) {
          puVar3 = &DAT_006e7eb4;
          do {
            *puVar3 = *puVar3 | 1;
            puVar3 = puVar3 + 2;
          } while ((int)puVar3 < 0x6e80b4);
        }
        else if (iVar2 == 1) {
          puVar3 = &DAT_006e7ebc;
          do {
            if ((puVar3[-2] & 2) != 0) {
              puVar3[-2] = puVar3[-2] | 1;
            }
            if ((*puVar3 & 2) != 0) {
              *puVar3 = *puVar3 | 1;
            }
            if ((puVar3[2] & 2) != 0) {
              puVar3[2] = puVar3[2] | 1;
            }
            if ((puVar3[4] & 2) != 0) {
              puVar3[4] = puVar3[4] | 1;
            }
            if ((puVar3[6] & 2) != 0) {
              puVar3[6] = puVar3[6] | 1;
            }
            if ((puVar3[8] & 2) != 0) {
              puVar3[8] = puVar3[8] | 1;
            }
            if ((puVar3[10] & 2) != 0) {
              puVar3[10] = puVar3[10] | 1;
            }
            if ((puVar3[0xc] & 2) != 0) {
              puVar3[0xc] = puVar3[0xc] | 1;
            }
            puVar3 = puVar3 + 0x10;
          } while ((int)puVar3 < 0x6e80bc);
        }
        else {
          (&DAT_006e7eb4)[iVar2 * 2] = (&DAT_006e7eb4)[iVar2 * 2] | 1;
        }
      }
    }
    pcVar1 = (char *)FUN_00674b68(0,&local_104);
  }
  return;
}


// ==== 0x642cb0 FUN_00642cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642cb0(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  if (DAT_0070ff38 == 0) {
    _DAT_006e80d8 = _DAT_006e80d8 & 0xfffffffe;
    _DAT_006e80e4 = _DAT_006e80e4 & 0xfffffffe;
    DAT_006e80f0 = DAT_006e80f0 & 0xfffffffe;
    DAT_006e80fc = DAT_006e80fc & 0xfffffffe;
    DAT_006e8108 = DAT_006e8108 & 0xfffffffe;
    DAT_006e8114 = DAT_006e8114 & 0xfffffffe;
    DAT_006e8120 = DAT_006e8120 & 0xfffffffe;
    DAT_006e812c = DAT_006e812c & 0xfffffffe;
    DAT_0070ff38 = 1;
    puVar1 = &DAT_006e7eb4;
    do {
      *puVar1 = *puVar1 & 0xfffffffe;
      puVar1 = puVar1 + 2;
    } while ((int)puVar1 < 0x6e80b4);
    puVar2 = &DAT_006e8104;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 3;
    } while ((int)puVar2 < 0x6e8134);
    puVar1 = &DAT_006e7f24;
    do {
      puVar1[-1] = 0;
      *puVar1 = *puVar1 & 0xfffffffd;
      puVar1 = puVar1 + 2;
    } while ((int)puVar1 < 0x6e80b4);
    DAT_006e7ec4 = DAT_006e7ec4 | 1;
    pcVar3 = _getenv("PRINT_CHANNEL");
    if (pcVar3 != (char *)0x0) {
      FUN_006429d0();
    }
    if (PTR_FUN_006e80e0 != (undefined *)0x0) {
      if (DAT_0070ff38 == 0) {
        FUN_00642cb0();
      }
      _DAT_006e80e4 = _DAT_006e80e4 | 1;
      pcVar3 = _getenv("PRINT_DEVICE");
      if (pcVar3 != (char *)0x0) {
        FUN_00642920(pcVar3);
      }
    }
  }
  return;
}


// ==== 0x642de0 FUN_00642de0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00642de0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined1 local_2000 [8188];
  undefined4 uStack_4;
  
  uStack_4 = 0x642dea;
  if (DAT_0070ff38 == 0) {
    FUN_00642cb0();
  }
  if ((*(byte *)(&DAT_006e7eb4 + param_1 * 2) & 1) != 0) {
    _vsprintf(local_2000,param_2,param_3);
    puVar1 = &DAT_006e80d4;
    do {
      if (((*(byte *)(puVar1 + 1) & 1) != 0) && ((code *)*puVar1 != (code *)0x0)) {
        (*(code *)*puVar1)(param_1,local_2000);
      }
      puVar1 = puVar1 + 3;
    } while ((int)puVar1 < 0x6e8134);
  }
  return;
}


// ==== 0x642e60 FUN_00642e60

void FUN_00642e60(undefined4 param_1,undefined4 param_2)

{
  FUN_00642de0(param_1,param_2,&stack0x0000000c);
  return;
}


// ==== 0x642e80 FUN_00642e80

void FUN_00642e80(undefined4 param_1)

{
  FUN_00642de0(2,param_1,&stack0x00000008);
  return;
}


// ==== 0x642fb0 FUN_00642fb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642fb0(void)

{
  undefined4 *puVar1;
  
  do {
    if (_DAT_0070ff6c != 0) {
      return;
    }
    FUN_00641ac0(&DAT_0070ff3c);
    CriticalSection__Enter(0x70ff44);
    puVar1 = (undefined4 *)0x70ff70;
    do {
      if ((code *)*puVar1 == (code *)0x0) break;
      (*(code *)*puVar1)();
      puVar1 = puVar1 + 1;
    } while ((int)puVar1 < 0x70ff90);
    CriticalSection__Leave(0x70ff44);
  } while( true );
}


// ==== 0x643010 FUN_00643010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00643010(void)

{
  char cVar1;
  
  if (_DAT_0070ff94 != 0) {
    _DAT_0070ff6c = 1;
    FUN_00641a90(&DAT_0070ff3c);
    cVar1 = FUN_0063e600(0x70ff60);
    if (cVar1 == '\0') {
      FUN_0063e7e0(0x70ff60,0);
    }
    FUN_0063e580(0x70ff60);
    FUN_00641b10(&DAT_0070ff3c);
    DAT_0070ff90 = 0;
    FUN_0063f170(0x70ff44);
    _DAT_0070ff94 = 0;
  }
  return;
}


// ==== 0x643090 FUN_00643090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00643090(void)

{
  char cVar1;
  
  FUN_00642570(FUN_00643010);
  CriticalSection__Init(0x70ff44);
  _DAT_0070ff94 = 1;
  _DAT_0070ff6c = 0;
  FUN_00641a70(&DAT_0070ff3c);
  DAT_0070ff90 = 1;
  CriticalSection__Enter(0x70ff44);
  cVar1 = FUN_0063e8b0(0x70ff60,FUN_00642fb0,0,0,1);
  if (cVar1 == '\0') {
    FUN_0063f170();
    _DAT_0070ff94 = 0;
    Log_Printf("wininittimer - FAILED TO CREATE SECONDARY TIMER`S THREAD.\n");
    return;
  }
  CriticalSection__Leave(0x70ff44);
  return;
}


// ==== 0x643125 FUN_00643125

void FUN_00643125(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (in_EAX == 0) {
    FUN_00643090();
  }
  CriticalSection__Enter(0x70ff44);
  iVar2 = 0;
  iVar3 = -1;
  do {
    iVar1 = *(int *)(iVar2 * 4 + 0x70ff70);
    if (((iVar1 != 0) || (iVar4 = iVar2, -1 < iVar3)) && (iVar4 = iVar3, iVar1 == param_1))
    goto CriticalSection__Leave;
    iVar2 = iVar2 + 1;
    iVar3 = iVar4;
  } while (iVar2 < 8);
  if (iVar4 != -1) {
    *(int *)(iVar4 * 4 + 0x70ff70) = param_1;
  }
CriticalSection__Leave:
  LeaveCriticalSection((LPCRITICAL_SECTION)0x70ff48);
  return;
}


// ==== 0x643225 FUN_00643225

void FUN_00643225(void)

{
  return;
}


// ==== 0x64322e FUN_0064322e

void FUN_0064322e(void)

{
  return;
}


// ==== 0x643230 FUN_00643230

void FUN_00643230(void)

{
  if (DAT_0070ff90 != 0) {
    FUN_00641a90(&DAT_0070ff3c);
  }
  return;
}


// ==== 0x643250 FUN_00643250

undefined8 FUN_00643250(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar1 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar2 = *(undefined2 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar2;
      param_1 = (undefined4 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar3;
      param_1 = param_1 + 1;
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    param_2 = param_2 + 8;
    param_1 = param_1 + 8;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_2 = param_2 + 2;
    param_1 = param_1 + 2;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar3;
    param_1 = param_1 + 1;
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar2 = *(undefined2 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar2;
    param_1 = (undefined4 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar1;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}


// ==== 0x643350 FUN_00643350

undefined8 FUN_00643350(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  
  if (((uint)param_1 & 7) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar4 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar4;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar5 = *(undefined2 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar5;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar6 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = uVar6;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar6 = *(undefined4 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 4);
    *(undefined4 *)param_1 = uVar6;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar5 = *(undefined2 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar5;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar4 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar4;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}


// ==== 0x643440 FUN_00643440

undefined8 FUN_00643440(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (((uint)param_1 & 0x1f) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar2 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar3 = *(undefined2 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar3;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar4 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = uVar4;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
    if ((((uint)param_1 & 8) != 0) && (7 < (int)param_3)) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 - 8;
    }
    if ((((uint)param_1 & 0x10) != 0) && (0xf < (int)param_3)) {
      uVar4 = *(undefined4 *)param_2;
      uVar5 = *(undefined4 *)((int)param_2 + 4);
      uVar6 = *(undefined4 *)(param_2 + 1);
      uVar7 = *(undefined4 *)((int)param_2 + 0xc);
      param_2 = param_2 + 2;
      *(undefined4 *)param_1 = uVar4;
      *(undefined4 *)((int)param_1 + 4) = uVar5;
      *(undefined4 *)(param_1 + 1) = uVar6;
      *(undefined4 *)((int)param_1 + 0xc) = uVar7;
      param_1 = param_1 + 2;
      param_3 = param_3 - 0x10;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    uVar4 = *(undefined4 *)((int)param_2 + 4);
    uVar5 = *(undefined4 *)(param_2 + 1);
    uVar6 = *(undefined4 *)((int)param_2 + 0xc);
    uVar7 = *(undefined4 *)(param_2 + 2);
    uVar8 = *(undefined4 *)((int)param_2 + 0x14);
    uVar9 = *(undefined4 *)(param_2 + 3);
    uVar10 = *(undefined4 *)((int)param_2 + 0x1c);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)((int)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar5;
    *(undefined4 *)((int)param_1 + 0xc) = uVar6;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((int)param_1 + 0x14) = uVar8;
    *(undefined4 *)(param_1 + 3) = uVar9;
    *(undefined4 *)((int)param_1 + 0x1c) = uVar10;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar4 = *(undefined4 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 4);
    *(undefined4 *)param_1 = uVar4;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar3 = *(undefined2 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar3;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar2 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}


// ==== 0x643550 FUN_00643550

undefined8 FUN_00643550(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  
  if (((uint)param_1 & 7) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar7 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar7;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar8 = *(undefined2 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar8;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar9 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = uVar9;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x80)) {
    uVar4 = param_2[4];
    uVar5 = param_2[8];
    uVar6 = param_2[0xc];
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    uVar1 = param_2[5];
    uVar2 = param_2[6];
    uVar3 = param_2[7];
    param_1[4] = uVar4;
    param_1[5] = uVar1;
    param_1[6] = uVar2;
    param_1[7] = uVar3;
    uVar4 = param_2[9];
    uVar1 = param_2[10];
    uVar2 = param_2[0xb];
    param_1[8] = uVar5;
    param_1[9] = uVar4;
    param_1[10] = uVar1;
    param_1[0xb] = uVar2;
    uVar4 = param_2[0xd];
    uVar5 = param_2[0xe];
    uVar1 = param_2[0xf];
    param_1[0xc] = uVar6;
    param_1[0xd] = uVar4;
    param_1[0xe] = uVar5;
    param_1[0xf] = uVar1;
    param_2 = param_2 + 0x10;
    param_1 = param_1 + 0x10;
    param_3 = param_3 - 0x80;
  }
  while (-1 < (int)(param_3 - 0x20)) {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar4;
    param_1[2] = uVar5;
    param_1[3] = uVar6;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar9 = *(undefined4 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 4);
    *(undefined4 *)param_1 = uVar9;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar8 = *(undefined2 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar8;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar7 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar7;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}


// ==== 0x6436f0 FUN_006436f0

undefined4 * FUN_006436f0(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined4 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = param_2;
    param_1[1] = param_2;
    param_1[2] = param_2;
    param_1[3] = param_2;
    param_1[4] = param_2;
    param_1[5] = param_2;
    param_1[6] = param_2;
    param_1[7] = param_2;
    param_1 = param_1 + 8;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = param_2;
    param_1[1] = param_2;
    param_1 = param_1 + 2;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined4 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return param_1;
}


// ==== 0x6437b0 FUN_006437b0

undefined8 * FUN_006437b0(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  uVar1 = CONCAT44(param_2,param_2);
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = uVar1;
    param_1[1] = uVar1;
    param_1[2] = uVar1;
    param_1[3] = uVar1;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *(undefined4 *)param_1 = param_2;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return param_1;
}


// ==== 0x643860 FUN_00643860

undefined8 * FUN_00643860(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  uVar1 = CONCAT44(param_2,param_2);
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = uVar1;
    param_1[1] = uVar1;
    param_1[2] = uVar1;
    param_1[3] = uVar1;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *(undefined4 *)param_1 = param_2;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return param_1;
}


// ==== 0x643910 FUN_00643910

undefined8 * FUN_00643910(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  if (((uint)param_1 & 0x1f) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
    if ((((uint)param_1 & 8) != 0) && (7 < (int)param_3)) {
      *param_1 = CONCAT44(param_2,param_2);
      param_1 = param_1 + 1;
      param_3 = param_3 - 8;
    }
    if ((((uint)param_1 & 0x10) != 0) && (0xf < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      *(undefined4 *)((int)param_1 + 4) = param_2;
      *(undefined4 *)(param_1 + 1) = param_2;
      *(undefined4 *)((int)param_1 + 0xc) = param_2;
      param_1 = param_1 + 2;
      param_3 = param_3 - 0x10;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *(undefined4 *)param_1 = param_2;
    *(undefined4 *)((int)param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 1) = param_2;
    *(undefined4 *)((int)param_1 + 0xc) = param_2;
    *(undefined4 *)(param_1 + 2) = param_2;
    *(undefined4 *)((int)param_1 + 0x14) = param_2;
    *(undefined4 *)(param_1 + 3) = param_2;
    *(undefined4 *)((int)param_1 + 0x1c) = param_2;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = CONCAT44(param_2,param_2);
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *(undefined4 *)param_1 = param_2;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return param_1;
}


// ==== 0x6439f2 FUN_006439f2

void FUN_006439f2(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x6439f8 FUN_006439f8

void FUN_006439f8(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x643a00 FUN_00643a00

uint FUN_00643a00(void)

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
  undefined1 auStack_28 [32];
  
  uVar2 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffff8,0x20) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)auStack_28 < 0) * 0x80
          | (uint)(&stack0x00000000 == (undefined1 *)0x28) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)auStack_28 & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0xfffffff8 < (undefined1 *)0x20) | (uint)(in_ID & 1) * 0x200000 |
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


// ==== 0x643a1b FUN_00643a1b

void FUN_00643a1b(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_2 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_2 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_2 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_2 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_2 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_2 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_2 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_2 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_2 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_2 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_2 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_2 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_2 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_2 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_2);
  }
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *param_1 = *puVar1;
  param_1[1] = uVar4;
  param_1[2] = uVar3;
  param_1[3] = uVar2;
  return;
}


// ==== 0x643a39 FUN_00643a39

undefined4 FUN_00643a39(void)

{
  return 1;
}


// ==== 0x643a60 FUN_00643a60

char * FUN_00643a60(void)

{
  if (DAT_006e76a8 == 0) {
    if (DAT_0070fdec == 0) {
      if (DAT_0070fdf0 != 0) {
        PTR_s_Pentium_006e80c0 = s_Cyrix_006a91f0;
        return "Cyrix";
      }
      if (DAT_0070fdf8 != 0) {
        PTR_s_Pentium_006e80c0 = s_WinChip_006a91e8;
      }
    }
    else {
      PTR_s_Pentium_006e80c0 = &DAT_006a9220;
      if ((((DAT_0070fdf4 != 0) && (PTR_s_Pentium_006e80c0 = &DAT_006a9218, DAT_006e76a0 != 0)) &&
          (PTR_s_Pentium_006e80c0 = s_Athlon_006a9210, DAT_0070fde0 != 0)) &&
         (PTR_s_Pentium_006e80c0 = s_AthlonXP_006a9204, 1 < DAT_006e769c)) {
        PTR_s_Pentium_006e80c0 = s_AthlonMP_006a91f8;
        return "AthlonMP";
      }
    }
  }
  else {
    PTR_s_Pentium_006e80c0 = s_Pentium_006a91e0;
    if (((DAT_006e76a0 != 0) && (PTR_s_Pentium_006e80c0 = s_PentiumPro_006a9248, DAT_0070fdd8 != 0))
       && (PTR_s_Pentium_006e80c0 = s_Pentium2_006a923c, DAT_0070fde0 != 0)) {
      PTR_s_Pentium_006e80c0 = s_Pentium3_006a9230;
    }
    if (DAT_0070fde4 != 0) {
      PTR_s_Pentium_006e80c0 = s_Pentium4_006a9224;
      return "Pentium4";
    }
  }
  return PTR_s_Pentium_006e80c0;
}


// ==== 0x643b60 FUN_00643b60

void FUN_00643b60(int param_1,uint param_2)

{
  byte bVk;
  ushort uVar1;
  DWORD dwFlags;
  DWORD dwFlags_00;
  
  dwFlags_00 = 0;
  dwFlags = 2;
  if (param_1 == 0) {
    bVk = 0x14;
    param_1._0_1_ = ':';
  }
  else if (param_1 == 1) {
    bVk = 0x90;
    param_1._0_1_ = 'E';
    dwFlags_00 = 1;
    dwFlags = 3;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    bVk = 0x91;
    param_1._0_1_ = 'F';
  }
  uVar1 = GetKeyState((uint)bVk);
  if ((uVar1 & 1) != param_2) {
    keybd_event(bVk,(BYTE)param_1,dwFlags_00,0);
    keybd_event(bVk,(BYTE)param_1,dwFlags,0);
  }
  return;
}


// ==== 0x643c20 FUN_00643c20

void FUN_00643c20(void)

{
  _printf_67147f("%s");
  return;
}


// ==== 0x643c30 FUN_00643c30

void FUN_00643c30(undefined4 param_1,LPCSTR param_2)

{
  OutputDebugStringA(param_2);
  return;
}


// ==== 0x643c70 FUN_00643c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00643c70(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  BOOL BVar3;
  DWORD DStack_4;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (_DAT_006e80c8 != (HANDLE)0xffffffff) {
    BVar3 = WriteFile(_DAT_006e80c8,param_2,(int)pcVar2 - (int)(param_2 + 1),&DStack_4,
                      (LPOVERLAPPED)0x0);
    if ((BVar3 == 0) || (DStack_4 != (int)pcVar2 - (int)(param_2 + 1))) {
      OutputDebugStringA("PRINTFILE_print: write failed.\n");
    }
  }
  return;
}


// ==== 0x643d60 FUN_00643d60

undefined4 FUN_00643d60(void)

{
  return 0;
}


// ==== 0x643d70 FUN_00643d70

void FUN_00643d70(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == param_3) {
    puVar2 = &DAT_0070ffa0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  FUN_00643ecc();
  FUN_00643ecc();
  FUN_00643ecc();
  FUN_00643ecc();
  return;
}


// ==== 0x643e50 FUN_00643e50

void FUN_00643e50(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_1;
  fVar2 = param_2[1];
  fVar3 = *param_1;
  fVar4 = param_2[2];
  fVar5 = param_1[1];
  fVar6 = param_2[5];
  fVar7 = param_1[1];
  fVar8 = param_2[6];
  fVar9 = param_1[2];
  fVar10 = param_2[9];
  fVar11 = param_1[2];
  fVar12 = param_2[10];
  fVar13 = param_2[0xd];
  fVar14 = param_2[0xe];
  *param_3 = param_1[2] * param_2[8] + param_1[1] * param_2[4] + *param_1 * *param_2 + param_2[0xc];
  param_3[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2 + fVar13;
  param_3[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4 + fVar14;
  return;
}


// ==== 0x643ec0 FUN_00643ec0

void FUN_00643ec0(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_1;
  fVar2 = param_2[3];
  fVar3 = *param_1;
  fVar4 = param_2[2];
  fVar5 = *param_1;
  fVar6 = param_2[1];
  fVar7 = param_1[1];
  fVar8 = param_2[6];
  fVar9 = param_1[1];
  fVar10 = param_2[5];
  fVar11 = param_1[1];
  fVar12 = param_2[7];
  fVar13 = param_1[2];
  fVar14 = param_2[10];
  fVar15 = param_1[2];
  fVar16 = param_2[9];
  fVar17 = param_1[2];
  fVar18 = param_2[0xb];
  fVar19 = param_1[3];
  fVar20 = param_2[0xe];
  fVar21 = param_1[3];
  fVar22 = param_2[0xd];
  fVar23 = param_1[3];
  fVar24 = param_2[0xf];
  *param_3 = param_1[3] * param_2[0xc] +
             param_1[2] * param_2[8] + param_1[1] * param_2[4] + *param_1 * *param_2;
  param_3[1] = fVar21 * fVar22 + fVar15 * fVar16 + fVar9 * fVar10 + fVar5 * fVar6;
  param_3[2] = fVar19 * fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar3 * fVar4;
  param_3[3] = fVar23 * fVar24 + fVar17 * fVar18 + fVar11 * fVar12 + fVar1 * fVar2;
  return;
}


// ==== 0x643ecc FUN_00643ecc

void __fastcall FUN_00643ecc(float *param_1,float *param_2)

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
  float *in_EAX;
  
  fVar1 = *in_EAX;
  fVar2 = param_1[3];
  fVar3 = *in_EAX;
  fVar4 = param_1[2];
  fVar5 = *in_EAX;
  fVar6 = param_1[1];
  fVar7 = in_EAX[1];
  fVar8 = param_1[6];
  fVar9 = in_EAX[1];
  fVar10 = param_1[5];
  fVar11 = in_EAX[1];
  fVar12 = param_1[7];
  fVar13 = in_EAX[2];
  fVar14 = param_1[10];
  fVar15 = in_EAX[2];
  fVar16 = param_1[9];
  fVar17 = in_EAX[2];
  fVar18 = param_1[0xb];
  fVar19 = in_EAX[3];
  fVar20 = param_1[0xe];
  fVar21 = in_EAX[3];
  fVar22 = param_1[0xd];
  fVar23 = in_EAX[3];
  fVar24 = param_1[0xf];
  *param_2 = in_EAX[3] * param_1[0xc] +
             in_EAX[2] * param_1[8] + in_EAX[1] * param_1[4] + *in_EAX * *param_1;
  param_2[1] = fVar21 * fVar22 + fVar15 * fVar16 + fVar9 * fVar10 + fVar5 * fVar6;
  param_2[2] = fVar19 * fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar3 * fVar4;
  param_2[3] = fVar23 * fVar24 + fVar17 * fVar18 + fVar11 * fVar12 + fVar1 * fVar2;
  return;
}


// ==== 0x6446f0 FUN_006446f0

float * FUN_006446f0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_1[1];
  fVar2 = param_2[1];
  fVar3 = param_1[2];
  fVar4 = param_2[2];
  *param_3 = *param_1 + *param_2;
  param_3[1] = fVar1 + fVar2;
  param_3[2] = fVar3 + fVar4;
  return param_1 + 3;
}


// ==== 0x64471d FUN_0064471d

float * FUN_0064471d(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_1[1];
  fVar2 = param_2[1];
  fVar3 = param_1[2];
  fVar4 = param_2[2];
  *param_3 = *param_1 - *param_2;
  param_3[1] = fVar1 - fVar2;
  param_3[2] = fVar3 - fVar4;
  return param_1 + 3;
}


// ==== 0x64474a FUN_0064474a

float10 FUN_0064474a(float *param_1,float *param_2)

{
  return (float10)*param_1 * (float10)*param_2 + (float10)param_1[1] * (float10)param_2[1] +
         (float10)param_1[2] * (float10)param_2[2];
}


// ==== 0x64476e FUN_0064476e

float * FUN_0064476e(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = param_1[2];
  fVar2 = *param_2;
  fVar3 = *param_1;
  fVar4 = param_2[1];
  fVar5 = *param_1;
  fVar6 = param_2[2];
  fVar7 = param_1[1];
  fVar8 = *param_2;
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = fVar1 * fVar2 - fVar5 * fVar6;
  param_3[2] = fVar3 * fVar4 - fVar7 * fVar8;
  return param_1 + 3;
}


// ==== 0x644910 FUN_00644910

uint FUN_00644910(byte *param_1,undefined4 *param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar3 = 0;
  if (param_1 != (byte *)0x0) {
    pbVar4 = param_1 + 2;
    if ((*param_1 & 1) != 0) {
      pbVar4 = param_1 + 5;
    }
    uVar3 = (uint)CONCAT21(CONCAT11(*pbVar4,pbVar4[1]),pbVar4[2]);
    pbVar4 = pbVar4 + 3;
    if (param_2 != (undefined4 *)0x0) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              bVar2 = *pbVar4;
              uVar6 = (uint)bVar2;
              pbVar5 = pbVar4 + 1;
              if ((char)bVar2 < '\0') break;
              pbVar4 = pbVar4 + (uVar6 & 3) + 2;
            }
            if ((bVar2 & 0x40) != 0) break;
            pbVar4 = pbVar4 + (*pbVar5 >> 6) + 3;
          }
          if ((bVar2 & 0x20) != 0) break;
          pbVar4 = pbVar4 + (uVar6 & 3) + 4;
        }
        uVar1 = (bVar2 & 0x1f) * 4 + 4;
        if (0x70 < uVar1) break;
        pbVar4 = pbVar5 + uVar1;
      }
      *param_2 = pbVar5 + ((uVar6 & 3) - (int)param_1);
    }
  }
  return uVar3;
}


// ==== 0x6449c0 FUN_006449c0

int __thiscall
FUN_006449c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  FUN_00645da0(0);
  CallNTimes(param_1 + 0x78,0xc,2,FUN_00648bff);
  FUN_00644b88(param_2,0,param_3,0,0,0,0,0,param_4,param_5);
  return param_1;
}


// ==== 0x644a16 FUN_00644a16

int __thiscall
FUN_00644a16(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  FUN_00645da0(0);
  CallNTimes(param_1 + 0x78,0xc,2,FUN_00648bff);
  FUN_00644b88(param_2,0,param_3,0,param_4,0,param_5,0,param_6,param_7);
  return param_1;
}


// ==== 0x644a70 FUN_00644a70

int __thiscall
FUN_00644a70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_00645da0(0);
  CallNTimes(param_1 + 0x78,0xc,2,FUN_00648bff);
  FUN_00644b88(param_2,0,param_3,param_4,param_5,0,param_6,param_7,param_8,param_9);
  return param_1;
}


// ==== 0x644ace FUN_00644ace

int __thiscall
FUN_00644ace(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_00645da0(0);
  CallNTimes(param_1 + 0x78,0xc,2,FUN_00648bff);
  FUN_00644b88(param_2,param_3,param_4,0,param_5,param_6,param_7,0,param_8,param_9);
  return param_1;
}


// ==== 0x644b2c FUN_00644b2c

int __thiscall
FUN_00644b2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_00645da0(0);
  CallNTimes(param_1 + 0x78,0xc,2,FUN_00648bff);
  FUN_00644b88(param_2,param_3,param_4,0,param_5,param_6,param_7,0,2,param_8);
  return param_1;
}


// ==== 0x644b88 FUN_00644b88

/* WARNING: Removing unreachable block (ram,0x00644c7d) */

void __thiscall
FUN_00644b88(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0064f810();
  if (iVar2 == 0) {
    param_11 = 1;
  }
  FUN_00641a10(param_1,0,0x94);
  param_1[6] = param_10;
  param_1[7] = param_11;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0;
  param_1[0x11] = 0;
  param_1[0x17] = 0;
  param_1[0x19] = 0;
  *param_1 = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[3] = param_2;
  param_1[4] = param_6;
  param_1[0x24] = 0;
  cVar1 = FUN_00645dc0();
  if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x3e4,
                 "!\"you must fill in the RCMP::rcmp_sys struct first!!!\"");
  }
  if (param_6 == 0) {
    *(undefined1 *)(param_1 + 5) = 0;
    uVar3 = FUN_00645e00("AV::VideoStreamBuffer",param_4,0,0,DAT_00712028);
    param_1[1] = uVar3;
    param_1[2] = 0;
    uVar3 = FUN_004124f0(2,3,2,param_1[1],param_4);
    param_1[0xc] = uVar3;
    uVar3 = SNDSTRM_GetEntry(param_1[0xc],2);
    param_1[0xd] = uVar3;
    NullUpdate_ret(param_1[0xd],0x98,0x34);
    NullUpdate_ret(param_1[0xc],0x98,0x34);
    StrmDef_SetEntry(param_1[0xc],1,0xff,0x4d,1);
    StrmDef_SetEntry(param_1[0xc],3,0,0,0xfffffffe);
    if (param_1[7] == 0) {
      StrmDef_SetEntry(param_1[0xc],2,0xffff,0x4353,2);
    }
    else {
      StrmDef_SetEntry(param_1[0xc],2,0xffff,0x4353,0xffffffff);
    }
    if (param_1[6] == 1) {
      uVar3 = FUN_006836a0(param_2,DAT_00712028);
      param_1[9] = uVar3;
      if (param_1[9] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x451,
                     "m_AyncVideoFileHandle != 0");
      }
    }
    else if (param_1[6] == 0) {
      uVar3 = FUN_00412930(param_1[0xc],param_2,param_5,0);
      param_1[0xe] = uVar3;
      if (param_1[0xe] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x45a,
                     "m_VideoStreamRequestID != 0");
      }
    }
    else {
      if (param_1[6] != 2) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x467,
                     "!\"bad LoadMode\"");
      }
      uVar3 = FUN_004129f0(param_1[0xc],param_1[3],param_3,0);
      param_1[0xe] = uVar3;
      if (param_1[0xe] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x463,
                     "m_VideoStreamRequestID != 0");
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 5) = 1;
    uVar3 = FUN_00645e00("AV::VideoStreamBuffer",param_4,0,0,DAT_00712028);
    param_1[1] = uVar3;
    uVar3 = FUN_00645e00("AV::AudioStreamBuffer",param_8,0,0,DAT_00712028);
    param_1[2] = uVar3;
    uVar3 = FUN_004124f0(2,2,1,param_1[1],param_4);
    param_1[0xc] = uVar3;
    uVar3 = FUN_004124f0(2,2,1,param_1[2],param_8);
    param_1[0xd] = uVar3;
    NullUpdate_ret(param_1[0xd],0x98,0x34);
    NullUpdate_ret(param_1[0xc],0x98,0x34);
    StrmDef_SetEntry(param_1[0xc],1,0xff,0x4d,1);
    StrmDef_SetEntry(param_1[0xc],2,0,0,0xfffffffe);
    if (param_1[7] == 0) {
      StrmDef_SetEntry(param_1[0xd],1,0xffff,0x4353,1);
    }
    else {
      StrmDef_SetEntry(param_1[0xd],1,0xffff,0x4353,0xffffffff);
    }
    StrmDef_SetEntry(param_1[0xd],2,0,0,0xfffffffe);
    if (param_1[6] == 1) {
      uVar3 = FUN_006836a0(param_6,DAT_00712028);
      param_1[0xb] = uVar3;
      uVar3 = FUN_006836a0(param_2,DAT_00712028);
      param_1[9] = uVar3;
      if (param_1[9] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x411,
                     "m_AyncVideoFileHandle != 0");
      }
      if (param_1[0xb] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x412,
                     "m_AyncAudioFileHandle != 0");
      }
    }
    else if (param_1[6] == 0) {
      uVar3 = FUN_00412930(param_1[0xd],param_6,param_9,0);
      param_1[0xf] = uVar3;
      uVar3 = FUN_00412930(param_1[0xc],param_2,param_5,0);
      param_1[0xe] = uVar3;
      if (param_1[0xe] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x41d,
                     "m_VideoStreamRequestID != 0");
      }
      if (param_1[0xf] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x41e,
                     "m_AudioStreamRequestID != 0");
      }
    }
    else {
      if (param_1[6] != 2) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x42d,
                     "!\"bad LoadMode\"");
      }
      uVar3 = FUN_004129f0(param_1[0xc],param_1[3],param_3,0);
      param_1[0xe] = uVar3;
      uVar3 = FUN_004129f0(param_1[0xd],param_1[4],param_7,0);
      param_1[0xf] = uVar3;
      if (param_1[0xe] == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x429,
                     "m_VideoStreamRequestID != 0");
      }
    }
  }
  return;
}


// ==== 0x6451c6 FUN_006451c6

void __thiscall FUN_006451c6(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}


// ==== 0x6451dc FUN_006451dc

void __fastcall FUN_006451dc(int *param_1)

{
  if (param_1[0x19] != 0) {
    if ((undefined4 *)param_1[0x19] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x19])(1);
    }
    param_1[0x19] = 0;
  }
  if (*param_1 != 0) {
    if (*param_1 != 0) {
      FUN_00645e30(1);
    }
    *param_1 = 0;
  }
  if (param_1[0x17] != 0) {
    if (param_1[0x17] != 0) {
      FUN_00645e60(1);
    }
    param_1[0x17] = 0;
  }
  FUN_00412810(param_1[0xc]);
  param_1[0xc] = 0;
  if ((char)param_1[5] != '\0') {
    FUN_00412810(param_1[0xd]);
    param_1[0xd] = 0;
  }
  if (param_1[8] != 0) {
    FUN_0064538b(param_1[8]);
    param_1[8] = 0;
  }
  if (param_1[10] != 0) {
    FUN_0064538b(param_1[10]);
    param_1[10] = 0;
  }
  if (param_1[1] != 0) {
    FUN_005a4510(param_1[1]);
    param_1[1] = 0;
  }
  if (param_1[2] != 0) {
    FUN_005a4510(param_1[2]);
    param_1[2] = 0;
  }
  FUN_005b5e6c(param_1 + 0x1e,0xc,2,FUN_006497d0);
  FUN_006497d0();
  return;
}


// ==== 0x64538b FUN_0064538b

void FUN_0064538b(undefined4 param_1)

{
  undefined4 local_2c [2];
  code *local_24;
  
  local_2c[0] = 0x28;
  FUN_0063aba0(local_2c);
  (*local_24)(param_1);
  return;
}


// ==== 0x6453b2 FUN_006453b2

int __thiscall FUN_006453b2(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 local_24 [32];
  
  NullUpdate_ret(param_1[0xd],0x97,0x33);
  NullUpdate_ret(param_1[0xc],0x97,0x33);
  if (param_1[9] != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Please Wait for video data to finish loading...\n");
  }
  if (param_1[0xb] != 0) {
    if ((char)param_1[5] != '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x520,
                   "m_SndFromDifferentFile==1");
    }
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Please Wait for audio data to finish loading...\n");
  }
  if ((char)param_1[5] == '\0') {
    param_1[0xf] = param_1[0xe];
  }
  if (param_1[7] == 0) {
    iVar2 = FUN_00645f00(0x14);
    if (iVar2 == 0) {
      local_38 = 0;
    }
    else {
      local_38 = FUN_00646100(param_1[0xd],param_1[0xf]);
    }
    *param_1 = local_38;
    if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x535,&DAT_006a943c);
    }
    iVar2 = FUN_00647b90();
    param_1[0x15] = (uint)(-1 < iVar2);
  }
  else {
    param_1[0x15] = 0;
  }
  param_1[0x19] = 0;
  cVar1 = FUN_00645dc0();
  if (cVar1 != '\0') {
    FUN_00645eb0(param_1);
    FUN_00648c5f(param_1 + 0x18,FUN_00645d22,FUN_00645d7a,param_2);
    iVar2 = FUN_00645ed0(0x1c);
    if (iVar2 == 0) {
      local_3c = 0;
    }
    else {
      local_3c = FUN_0064894b(local_24);
    }
    param_1[0x19] = local_3c;
    if (param_1[0x19] == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x54f,"m_pdecoder");
    }
    FUN_006497d0();
  }
  iVar2 = FUN_00648ac8(0);
  param_1[0x1d] = iVar2;
  iVar2 = FUN_00645f30(0x18);
  if (iVar2 == 0) {
    local_40 = 0;
  }
  else {
    local_40 = FUN_00645f60();
  }
  param_1[0x17] = local_40;
  if (param_1[0x17] == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x558,"m_MSTimer");
  }
  iVar2 = FUN_00645fa0();
  param_1[0x13] = iVar2;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x10] = param_3;
  if (*param_1 != 0) {
    FUN_0064629f();
  }
  FUN_00645860(0x1000);
  return param_1[0x1d];
}


// ==== 0x645732 FUN_00645732

undefined4 __thiscall FUN_00645732(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x48) = param_2;
  uVar1 = _ftol_nocw();
  uVar1 = FUN_00648ac8(uVar1);
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  uVar1 = FUN_00648a58();
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  return *(undefined4 *)(param_1 + 0x74);
}


// ==== 0x64577c FUN_0064577c

undefined4 __fastcall FUN_0064577c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 0x74) == 0) {
    uVar1 = _ftol_nocw();
    uVar1 = FUN_00646564(uVar1);
  }
  else {
    uVar1 = FUN_00646564(*(undefined4 *)(param_1 + 0x44));
  }
  return uVar1;
}


// ==== 0x6457c8 FUN_006457c8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_006457c8(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint3 uVar5;
  int iVar4;
  float10 fVar6;
  
  iVar3 = FUN_0064595f();
  iVar4 = *(int *)(param_1 + 0x40);
  fVar6 = (float10)FUN_00648a8e();
  *(float *)(param_1 + 0x48) = (float)(fVar6 * (float10)0.001 * (float10)(uint)(iVar3 + iVar4));
  fVar2 = (float)*(uint *)(param_1 + 0x44) + _K_ONE;
  fVar1 = *(float *)(param_1 + 0x48);
  uVar5 = (uint3)(CONCAT22((short)((uint)param_1 >> 0x10),
                           (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                           (ushort)(fVar2 == fVar1) << 0xe) >> 8);
  if (fVar2 < fVar1 || (fVar2 == fVar1) != 0) {
    iVar4 = CONCAT31(uVar5,1);
  }
  else {
    iVar4 = (uint)uVar5 << 8;
  }
  return iVar4;
}


// ==== 0x64583f FUN_0064583f

undefined4 __fastcall FUN_0064583f(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0064635f();
  }
  return uVar1;
}


// ==== 0x645860 FUN_00645860

undefined4 __thiscall FUN_00645860(int *param_1,uint param_2)

{
  if (0x4000 < param_2) {
    param_2 = 0x4000;
  }
  if (param_1[0x17] == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x617,
                 "!\"SetSpeed can not be called before AV_PLAYER::GetFirstFrame\"");
  }
  if (*param_1 != 0) {
    FUN_0064623d(param_2);
  }
  FUN_00646050(param_2);
  return 0;
}


// ==== 0x6458e3 FUN_006458e3

void FUN_006458e3(void)

{
  FUN_00645860(0);
  return;
}


// ==== 0x6458f8 FUN_006458f8

void FUN_006458f8(void)

{
  FUN_00645860(0x1000);
  return;
}


// ==== 0x645910 FUN_00645910

/* WARNING: Removing unreachable block (ram,0x00645945) */

undefined4 __thiscall FUN_00645910(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x65e,
                 "!\"You can set Volume if you are not using sound\"");
  }
  uVar1 = FUN_006462fd(param_2);
  return uVar1;
}


// ==== 0x64595f FUN_0064595f

int __fastcall FUN_0064595f(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_38;
  int local_30;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined1 local_20 [4];
  int local_1c;
  int local_c;
  
  local_c = FUN_00645fa0();
  local_30 = local_c - *(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_0064e520();
    uVar1 = FUN_00647b90(local_2c);
    FUN_0064fa60(uVar1);
    FUN_0064f900(local_28,local_20);
    SNDSYS_leavecritical();
    iVar2 = FUN_0064f8e0();
    local_1c = local_1c - iVar2;
    if (*(int *)(param_1 + 0x50) < local_1c) {
      *(int *)(param_1 + 0x50) = local_1c;
      *(int *)(param_1 + 0x58) =
           (*(int *)(param_1 + 0x58) -
           ((int)(*(int *)(param_1 + 0x58) + (*(int *)(param_1 + 0x58) >> 0x1f & 7U)) >> 3)) +
           (local_1c - local_30);
      if (-*(int *)(param_1 + 0x58) < *(int *)(param_1 + 0x58)) {
        local_38 = *(int *)(param_1 + 0x58);
      }
      else {
        local_38 = -*(int *)(param_1 + 0x58);
      }
      if (0x108 < local_38) {
        *(int *)(param_1 + 0x4c) =
             *(int *)(param_1 + 0x4c) -
             ((int)(*(int *)(param_1 + 0x58) + (*(int *)(param_1 + 0x58) >> 0x1f & 7U)) >> 3);
        *(undefined4 *)(param_1 + 0x58) = 0;
        local_30 = local_c - *(int *)(param_1 + 0x4c);
      }
    }
  }
  return local_30;
}


// ==== 0x645a77 FUN_00645a77

void __thiscall FUN_00645a77(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_1c;
  undefined1 local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = FUN_006460d0();
  *param_3 = 0;
  while( true ) {
    local_10 = FUN_00412e30(local_8);
    FUN_0063f0a0(0);
    if (local_10 != 0) break;
    cVar1 = FUN_00412fb0(local_8);
    if (cVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_00642e80("done\n");
    }
  }
  uVar2 = FUN_00645c59(local_10,4);
  cVar1 = FUN_00649d50(uVar2);
  if (cVar1 != '\0') {
    local_c = 2;
  }
  if (local_c == 0) {
    local_18 = 0;
    local_1c = uVar2;
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Bad STREAM_release %s\n",&local_1c);
  }
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
  if (1 < *(int *)(param_1 + 0x90)) {
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  local_14 = param_1 + 0x78 + *(int *)(param_1 + 0x90) * 0xc;
  *param_3 = local_14;
  FUN_00645eb0(local_10);
  if (local_c == 2) {
    uVar2 = FUN_00645ce0(local_10 + 4,4);
    FUN_00646090(uVar2);
    FUN_00646070(local_10);
  }
  else {
    uVar2 = FUN_00645ce0(local_10 + 4,4);
    FUN_00646090(uVar2);
    FUN_00646070(local_10 + 8);
  }
  cVar1 = FUN_006460b0();
  if ((cVar1 == '\0') && (local_c == 2)) {
    uVar2 = CreateObject();
    iVar3 = FUN_006489c9(uVar2,local_14);
    if (iVar3 != 2) {
      FUN_00648a0b();
                    /* WARNING: Subroutine does not return */
      FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avplayer.cpp",0x766,
                   "!\"This file is not a MAD file\"");
    }
  }
  return;
}


// ==== 0x645c59 FUN_00645c59

uint FUN_00645c59(byte *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)CONCAT11(*param_1,param_1[1]);
  }
  else if (param_2 == 3) {
    uVar1 = (uint)*param_1 << 0x10 | (uint)param_1[1] << 8 | (uint)param_1[2];
  }
  else if (param_2 == 4) {
    uVar1 = (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[2] << 8 |
            (uint)param_1[3];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x645ce0 FUN_00645ce0

uint FUN_00645ce0(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)(byte)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)(ushort)*param_1;
  }
  else if (param_2 == 3) {
    uVar1 = *param_1 & 0xffffff;
  }
  else if (param_2 == 4) {
    uVar1 = *param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x645d22 FUN_00645d22

void __thiscall
FUN_00645d22(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_006460f0(param_1);
  FUN_00645a77(param_2,param_4);
  return;
}


// ==== 0x645d45 FUN_00645d45

void __fastcall FUN_00645d45(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_006460f0(param_1);
  uVar2 = FUN_006460d0(param_1,uVar1);
  FUN_00412ee0(uVar2,uVar1);
  return;
}


// ==== 0x645d7a FUN_00645d7a

void __thiscall
FUN_00645d7a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_006460f0(param_1);
  FUN_00645d45(param_4);
  return;
}


// ==== 0x645da0 FUN_00645da0

undefined4 * __thiscall FUN_00645da0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


// ==== 0x645dc0 FUN_00645dc0

undefined1 __fastcall FUN_00645dc0(int param_1)

{
  undefined1 local_c;
  
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 8) == 0)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}


// ==== 0x645e00 FUN_00645e00

void __thiscall
FUN_00645e00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  (**(code **)(param_1 + 4))(param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== 0x645e30 FUN_00645e30

undefined4 __thiscall FUN_00645e30(undefined4 param_1,uint param_2)

{
  FUN_006461ff();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x645e60 FUN_00645e60

undefined4 __thiscall FUN_00645e60(undefined4 param_1,uint param_2)

{
  FUN_006497d0();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x645e90 FUN_00645e90

void FUN_00645e90(undefined4 param_1)

{
  FUN_005a4510(param_1);
  return;
}


// ==== 0x645eb0 FUN_00645eb0

void __thiscall FUN_00645eb0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== 0x645ed0 FUN_00645ed0

void FUN_00645ed0(undefined4 param_1)

{
  FUN_005a44e0("RCMP::DECODER",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x645f00 FUN_00645f00

void FUN_00645f00(undefined4 param_1)

{
  FUN_005a44e0("RCMP::AUDIO_PLAYER",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x645f30 FUN_00645f30

void FUN_00645f30(undefined4 param_1)

{
  FUN_005a44e0("RCMP::AV_MS_TIMER",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x645f60 FUN_00645f60

DWORD * __fastcall FUN_00645f60(DWORD *param_1)

{
  DWORD DVar1;
  
  param_1[2] = 0;
  param_1[3] = 0;
  DVar1 = timeGetTime();
  *param_1 = DVar1;
  param_1[4] = 0x1000;
  return param_1;
}


// ==== 0x645fa0 FUN_00645fa0

undefined4 __fastcall FUN_00645fa0(int param_1)

{
  FUN_00645fc0();
  return *(undefined4 *)(param_1 + 8);
}


// ==== 0x645fc0 FUN_00645fc0

void __fastcall FUN_00645fc0(DWORD *param_1)

{
  uint uVar1;
  DWORD DVar2;
  undefined8 uVar3;
  
  DVar2 = timeGetTime();
  if (param_1[4] == 0x1000) {
    uVar1 = param_1[2];
    param_1[2] = uVar1 + (DVar2 - *param_1);
    param_1[3] = param_1[3] + (uint)CARRY4(uVar1,DVar2 - *param_1);
  }
  else {
    uVar3 = __aulldiv((ulonglong)param_1[4] * (ulonglong)(DVar2 - *param_1),0x1000,0);
    uVar1 = param_1[2];
    param_1[2] = uVar1 + (uint)uVar3;
    param_1[3] = param_1[3] + (int)((ulonglong)uVar3 >> 0x20) + (uint)CARRY4(uVar1,(uint)uVar3);
  }
  *param_1 = DVar2;
  return;
}


// ==== 0x646050 FUN_00646050

void __thiscall FUN_00646050(int param_1,undefined4 param_2)

{
  FUN_00645fc0();
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}


// ==== 0x646070 FUN_00646070

void __thiscall FUN_00646070(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


// ==== 0x646090 FUN_00646090

void __thiscall FUN_00646090(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


// ==== 0x6460b0 FUN_006460b0

bool __fastcall FUN_006460b0(int param_1)

{
  return *(int *)(param_1 + 0x18) != 0;
}


// ==== 0x6460d0 FUN_006460d0

undefined4 __fastcall FUN_006460d0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}


// ==== 0x6460f0 FUN_006460f0

undefined4 __fastcall FUN_006460f0(undefined4 *param_1)

{
  return *param_1;
}


// ==== 0x646100 FUN_00646100

undefined4 * __thiscall FUN_00646100(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 local_2c [24];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = FUN_0064f810();
  if (iVar2 != 0) {
    param_1[4] = 0xffffffff;
    param_1[1] = 0;
    param_1[3] = 0xffffffff;
    local_14 = 1;
    local_c = 0x1e;
    local_8 = 0xffffffff;
    SNDplaysetdef(local_2c);
    local_10 = FUN_0064fb80(1,0x1e);
    uVar4 = FUN_00645e00("AV::audiobuff",local_10,0,0,DAT_00712028);
    param_1[1] = uVar4;
    uVar4 = FUN_0064fb50(param_2,local_2c,1,0x1e,param_1[1],local_10);
    param_1[3] = uVar4;
    uVar4 = FUN_0064fb30(param_1[3],0xffffffff,param_3);
    param_1[4] = uVar4;
    *param_1 = 0x3f800000;
    return param_1;
  }
  iVar2 = FUN_0064f810();
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/audioplayer.cpp",0x19,
                 "SNDSYS_inited()");
  }
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined4 *)(*pcVar1)();
  return puVar3;
}


// ==== 0x6461ff FUN_006461ff

void __fastcall FUN_006461ff(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    SNDSTRMI_service(*(undefined4 *)(param_1 + 0xc));
    FUN_005a4510(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


// ==== 0x64623d FUN_0064623d

undefined4 __thiscall FUN_0064623d(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0064f810();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/audioplayer.cpp",0x55,
                 "SNDSYS_inited()");
  }
  if (*(int *)(param_1 + 0xc) == -1) {
    uVar2 = 0;
  }
  else {
    FUN_0064e520();
    uVar2 = FUN_00650cb0(*(undefined4 *)(param_1 + 0xc),param_2);
    SNDSYS_leavecritical();
  }
  return uVar2;
}


// ==== 0x64629f FUN_0064629f

undefined4 __fastcall FUN_0064629f(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0064f810();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/audioplayer.cpp",0x65,
                 "SNDSYS_inited()");
  }
  if (*(int *)(param_1 + 0x10) == -1) {
    uVar2 = 0;
  }
  else {
    FUN_0064e520();
    uVar2 = FUN_00650d00(*(undefined4 *)(param_1 + 0x10),0);
    SNDSYS_leavecritical();
  }
  return uVar2;
}


// ==== 0x6462fd FUN_006462fd

undefined4 __thiscall FUN_006462fd(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0064f810();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/audioplayer.cpp",0x77,
                 "SNDSYS_inited()");
  }
  if (*(int *)(param_1 + 0xc) == -1) {
    uVar2 = 0;
  }
  else {
    FUN_0064e520();
    uVar2 = FUN_00650f40(*(undefined4 *)(param_1 + 0xc),param_2);
    SNDSYS_leavecritical();
  }
  return uVar2;
}


// ==== 0x64635f FUN_0064635f

uint __fastcall FUN_0064635f(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined1 local_14 [8];
  int local_c;
  
  FUN_0064e520(param_1);
  uVar1 = FUN_00647b90(local_20);
  iVar2 = FUN_0064fa60(uVar1);
  if (iVar2 < 0) {
    uVar3 = SNDSYS_leavecritical();
    uVar3 = uVar3 & 0xffffff00;
  }
  else {
    iVar2 = FUN_0064f900(local_1c,local_14);
    if (iVar2 < 0) {
      uVar3 = SNDSYS_leavecritical();
      uVar3 = uVar3 & 0xffffff00;
    }
    else {
      SNDSYS_leavecritical();
      uVar3 = (uint)(local_c == 0);
    }
  }
  return uVar3;
}


// ==== 0x6463c0 FUN_006463c0

undefined4 * __fastcall FUN_006463c0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


// ==== 0x6463e1 FUN_006463e1

void __fastcall FUN_006463e1(int *param_1)

{
  if (*param_1 != 0) {
    if (*param_1 != 0) {
      FUN_00647ab0(3);
    }
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}


// ==== 0x646433 FUN_00646433

void __thiscall
FUN_00646433(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *local_18;
  uint local_8;
  
  local_18 = (int *)FUN_00647b20(param_2 * 0x34 + 4);
  if (local_18 == (int *)0x0) {
    local_18 = (int *)0x0;
  }
  else {
    *local_18 = param_2;
    CallNTimes(local_18 + 1,0x34,param_2,FUN_006478e3);
    local_18 = local_18 + 1;
  }
  *param_1 = (int)local_18;
  param_1[1] = param_2;
  if (param_1[1] != 0) {
    FUN_006479f1(0);
  }
  for (local_8 = 0; local_8 < (uint)param_1[1]; local_8 = local_8 + 1) {
    FUN_00647984(param_3);
    FUN_00647999(param_4);
    FUN_006479af(param_5);
    FUN_006479c5(param_6);
    FUN_006479db(local_8);
  }
  return;
}


// ==== 0x64653d FUN_0064653d

int __thiscall FUN_0064653d(int *param_1,uint param_2)

{
  int iVar1;
  
  if ((uint)param_1[1] < param_2) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 0x34 + *param_1;
  }
  return iVar1;
}


// ==== 0x646564 FUN_00646564

int __thiscall FUN_00646564(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_8;
  
  if (param_1[1] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1;
    local_14 = -1;
    iVar1 = local_14;
    local_8 = param_1[1];
    while (local_14 = iVar1, 1 < local_8 - local_14) {
      iVar3 = (local_8 + local_14) / 2;
      uVar4 = FUN_00647b50();
      iVar1 = iVar3;
      if (param_2 <= uVar4) {
        iVar1 = local_14;
        local_8 = iVar3;
      }
    }
    if (local_8 == 1 || local_8 + -1 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_8 + -1;
    }
    if (local_1c < param_1[1] + -1) {
      if (local_8 == 1 || local_8 + -1 < 0) {
        local_20 = 0;
      }
      else {
        local_20 = local_8 + -1;
      }
      local_24 = local_20;
    }
    else {
      local_24 = param_1[1] + -1;
    }
    iVar2 = local_24 * 0x34 + iVar2;
  }
  return iVar2;
}


// ==== 0x64663e FUN_0064663e

undefined4 __fastcall FUN_0064663e(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ==== 0x64664f FUN_0064664f

void __thiscall FUN_0064664f(int *param_1,int param_2,uint param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint local_1c8;
  int *local_18c;
  int local_17c;
  uint local_178;
  int local_174;
  int local_170;
  uint local_16c;
  int local_168;
  int local_164;
  uint local_160;
  int local_15c;
  int local_158;
  int local_154;
  uint local_150;
  int local_14c;
  int local_148;
  undefined4 local_144;
  int local_140;
  int local_13c;
  undefined4 local_138;
  int local_134;
  int local_130;
  undefined4 local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  undefined4 local_10c;
  int local_108;
  int local_104;
  undefined4 local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  undefined4 local_f0;
  int local_ec;
  undefined4 local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  undefined1 local_c5;
  int local_c4;
  int local_c0;
  int local_bc;
  size_t local_b8 [13];
  int local_84;
  char local_7d;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined1 local_65;
  int local_64;
  int local_60;
  char *local_5c [13];
  undefined1 local_25;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_18 = param_2;
  local_cc = -1;
  local_24 = 0;
  local_c5 = 9;
  local_65 = 10;
  local_20 = -1;
  local_74 = -1;
  local_84 = -1;
  local_8 = -1;
  local_7c = -1;
  local_78 = -1;
  local_70 = -1;
  local_14 = -1;
  local_c0 = -1;
  local_c4 = -1;
  local_10 = -1;
  local_6c = -1;
  local_60 = -1;
  local_5c[0] = "FRAME";
  local_5c[1] = "STRINGID";
  local_5c[2] = "X";
  local_5c[3] = "Y";
  local_5c[4] = "WIDTH";
  local_5c[5] = "HEIGHT";
  local_5c[6] = "JUSTIFY_X";
  local_5c[7] = "JUSTIFY_Y";
  local_5c[8] = "SHAPE";
  local_5c[9] = "A";
  local_5c[10] = "R";
  local_5c[0xb] = "G";
  local_5c[0xc] = "B";
  for (local_1c = 0; local_1c < 0xd; local_1c = local_1c + 1) {
    sVar1 = _strlen(local_5c[local_1c]);
    local_b8[local_1c] = sVar1;
  }
  local_7d = '\x01';
  local_25 = 0;
  for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
    if (((*(char *)(local_18 + local_1c) == '\t') || (local_7d == '\x01')) &&
       (local_7d = '\0', local_cc == -1)) {
      local_d8 = param_3 - local_1c;
      local_d4 = local_18 + local_1c;
      FUN_00647742(&local_d4,&local_d8,local_5c,local_b8,0xd,&local_bc);
      if (local_bc != -1) {
        local_cc = local_24;
      }
    }
    if (*(char *)(local_18 + local_1c) == '\n') {
      local_24 = local_24 + 1;
      local_7d = '\x01';
    }
  }
  if (local_cc == -1) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    iVar2 = (local_24 - local_cc) + -1;
    local_24 = iVar2;
    local_18c = (int *)FUN_00647b20(iVar2 * 0x34 + 4);
    if (local_18c == (int *)0x0) {
      local_18c = (int *)0x0;
    }
    else {
      *local_18c = iVar2;
      CallNTimes(local_18c + 1,0x34,iVar2,FUN_006478e3);
      local_18c = local_18c + 1;
    }
    *param_1 = (int)local_18c;
    param_1[1] = local_24;
    local_64 = 0;
    local_c = 0;
    for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
      if (*(char *)(local_18 + local_1c) == '\n') {
        local_c = local_c + 1;
      }
      if (local_cc == local_c) break;
    }
    local_7d = '\x01';
    for (; local_1c < param_3; local_1c = local_1c + 1) {
      if ((*(char *)(local_18 + local_1c) == '\t') || (local_7d == '\x01')) {
        local_7d = '\0';
        local_e0 = param_3 - local_1c;
        local_dc = local_18 + local_1c;
        FUN_00647742(&local_dc,&local_e0,local_5c,local_b8,0xd,&local_bc);
        switch(local_bc) {
        case 0:
          local_20 = local_64;
          break;
        case 1:
          local_74 = local_64;
          break;
        case 2:
          local_14 = local_64;
          break;
        case 3:
          local_c0 = local_64;
          break;
        case 4:
          local_84 = local_64;
          break;
        case 5:
          local_8 = local_64;
          break;
        case 6:
          local_7c = local_64;
          break;
        case 7:
          local_78 = local_64;
          break;
        case 8:
          local_70 = local_64;
          break;
        case 9:
          local_c4 = local_64;
          break;
        case 10:
          local_10 = local_64;
          break;
        case 0xb:
          local_6c = local_64;
          break;
        case 0xc:
          local_60 = local_64;
        }
        local_64 = local_64 + 1;
      }
      if (*(char *)(local_18 + local_1c) == '\n') {
        local_7d = '\x01';
        local_1c = local_1c + 1;
        break;
      }
    }
    local_64 = 0;
    local_c = 0;
    while (local_1c < param_3) {
      if ((*(char *)(local_18 + local_1c) == '\t') || (local_7d == '\x01')) {
        if (local_7d != '\x01') {
          local_1c = local_1c + 1;
        }
        for (local_d0 = 0;
            ((local_1c + local_d0 < param_3 && (*(char *)(local_18 + local_1c + local_d0) != '\t'))
            && (*(char *)(local_18 + local_1c + local_d0) != '\n')); local_d0 = local_d0 + 1) {
        }
        if (local_1c + local_d0 != param_3) {
          local_25 = *(undefined1 *)(local_18 + local_1c + local_d0);
          *(undefined1 *)(local_18 + local_1c + local_d0) = 0;
        }
        local_7d = '\0';
        if (local_64 == local_20) {
          local_ec = param_3 - local_1c;
          local_e4 = local_18 + local_1c;
          local_e8 = FUN_00647b50();
          FUN_00647669(&local_e4,&local_ec,&local_e8);
          FUN_006479f1(local_e8);
        }
        else if (local_64 == local_74) {
          local_f8 = param_3 - local_1c;
          local_f4 = local_18 + local_1c;
          local_f0 = FUN_00647bb0();
          FUN_00647669(&local_f4,&local_f8,&local_f0);
          FUN_006479db(local_f0);
        }
        else if (local_64 == local_84) {
          local_104 = param_3 - local_1c;
          local_fc = local_18 + local_1c;
          local_100 = FUN_00647b70();
          FUN_00647669(&local_fc,&local_104,&local_100);
          FUN_006479af(local_100);
        }
        else if (local_64 == local_8) {
          local_110 = param_3 - local_1c;
          local_108 = local_18 + local_1c;
          local_10c = FUN_00647b90();
          FUN_00647669(&local_108,&local_110,&local_10c);
          FUN_006479c5(local_10c);
        }
        else if (local_64 == local_7c) {
          local_11c = param_3 - local_1c;
          local_114 = local_18 + local_1c;
          local_118 = FUN_006474d4(local_114,local_11c);
          if (local_118 == -1) {
            uVar3 = FUN_00647c50();
            FUN_00647a07(uVar3);
          }
          else {
            FUN_00647a07(local_118);
          }
        }
        else if (local_64 == local_78) {
          local_128 = param_3 - local_1c;
          local_120 = local_18 + local_1c;
          local_124 = FUN_006474d4(local_120,local_128);
          if (local_124 == -1) {
            uVar3 = FUN_00647c70();
            FUN_00647a1d(uVar3);
          }
          else {
            FUN_00647a1d(local_124);
          }
        }
        else if (local_64 == local_70) {
          local_134 = param_3 - local_1c;
          local_130 = local_18 + local_1c;
          local_12c = FUN_00647c90();
          FUN_00647669(&local_130,&local_134,&local_12c);
          FUN_00647a33(local_12c);
        }
        else if (local_64 == local_14) {
          local_140 = param_3 - local_1c;
          local_13c = local_18 + local_1c;
          local_138 = FUN_006460f0();
          FUN_00647669(&local_13c,&local_140,&local_138);
          FUN_00647984(local_138);
        }
        else if (local_64 == local_c0) {
          local_14c = param_3 - local_1c;
          local_148 = local_18 + local_1c;
          local_144 = FUN_00649910();
          FUN_00647669(&local_148,&local_14c,&local_144);
          FUN_00647999(local_144);
        }
        else if (local_64 == local_c4) {
          local_158 = param_3 - local_1c;
          local_154 = local_18 + local_1c;
          local_150 = FUN_00647bd0();
          local_150 = local_150 & 0xff;
          FUN_00647669(&local_154,&local_158,&local_150);
          FUN_00647a49(local_150);
        }
        else if (local_64 == local_10) {
          local_164 = param_3 - local_1c;
          local_15c = local_18 + local_1c;
          local_160 = FUN_00647bf0();
          local_160 = local_160 & 0xff;
          FUN_00647669(&local_15c,&local_164,&local_160);
          FUN_00647a5f(local_160);
        }
        else if (local_64 == local_6c) {
          local_170 = param_3 - local_1c;
          local_168 = local_18 + local_1c;
          local_16c = FUN_00647c10();
          local_16c = local_16c & 0xff;
          FUN_00647669(&local_168,&local_170,&local_16c);
          FUN_00647a75(local_16c);
        }
        else if (local_64 == local_60) {
          local_17c = param_3 - local_1c;
          local_174 = local_18 + local_1c;
          local_178 = FUN_00647c30();
          local_178 = local_178 & 0xff;
          FUN_00647669(&local_174,&local_17c,&local_178);
          FUN_00647a8b(local_178);
        }
        local_64 = local_64 + 1;
        if (local_1c + local_d0 != param_3) {
          *(undefined1 *)(local_18 + local_1c + local_d0) = local_25;
        }
      }
      else {
        if (*(char *)(local_18 + local_1c) == '\n') {
          local_64 = 0;
          uVar4 = local_c + 1;
          if ((param_1[1] < (int)uVar4) && ((int)uVar4 <= param_1[1])) {
            local_c = uVar4;
                    /* WARNING: Subroutine does not return */
            FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/av/cmn/avsubtitle.cpp",0x22b,
                         "CurRow>((INT32)mNumberOfSubtitle) && \"parser error\"");
          }
          local_7d = '\x01';
          local_1c8 = uVar4;
          if (param_1[1] - 1U <= uVar4) {
            local_1c8 = param_1[1] - 1;
          }
          puVar5 = (undefined4 *)(*param_1 + local_c * 0x34);
          puVar6 = (undefined4 *)(*param_1 + local_1c8 * 0x34);
          for (iVar2 = 0xd; local_c = uVar4, iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
        }
        local_1c = local_1c + 1;
      }
    }
  }
  return;
}


// ==== 0x6474d4 FUN_006474d4

undefined4 FUN_006474d4(int param_1,uint param_2)

{
  int iVar1;
  uint local_40;
  undefined4 local_3c [5];
  undefined1 local_26;
  undefined1 local_25;
  uint local_24;
  undefined4 local_20;
  undefined1 local_19;
  char *local_18 [5];
  
  local_26 = 9;
  local_19 = 0xd;
  local_25 = 9;
  for (local_24 = 0; local_24 < param_2; local_24 = local_24 + 1) {
    if ((*(char *)(param_1 + local_24) == '\t') || (*(char *)(param_1 + local_24) == '\r')) {
      local_25 = *(undefined1 *)(param_1 + local_24);
      *(undefined1 *)(param_1 + local_24) = 0;
      break;
    }
  }
  local_18[0] = "RIGHT";
  local_18[1] = "TOP";
  local_18[2] = "CENTER";
  local_18[3] = "LEFT";
  local_18[4] = "BOTTOM";
  local_3c[0] = 0;
  local_3c[1] = 1;
  local_3c[2] = 2;
  local_3c[3] = 3;
  local_3c[4] = 4;
  local_20 = 0xffffffff;
  local_40 = 0;
  do {
    if (4 < local_40) {
LAB_006475bf:
      if (local_24 != param_2) {
        *(undefined1 *)(param_1 + local_24) = local_25;
      }
      return local_20;
    }
    iVar1 = FUN_006475d9(local_18[local_40],param_1);
    if (iVar1 == 0) {
      local_20 = local_3c[local_40];
      goto LAB_006475bf;
    }
    local_40 = local_40 + 1;
  } while( true );
}


// ==== 0x6475d9 FUN_006475d9

int FUN_006475d9(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  for (local_8 = 0; (*(char *)(param_1 + local_8) != '\0' && (*(char *)(param_2 + local_8) != '\0'))
      ; local_8 = local_8 + 1) {
    iVar1 = _tolower((int)*(char *)(param_1 + local_8));
    iVar2 = _tolower((int)*(char *)(param_2 + local_8));
    if (iVar1 - iVar2 != 0) {
      return iVar1 - iVar2;
    }
  }
  return (int)*(char *)(param_1 + local_8) - (int)*(char *)(param_2 + local_8);
}


// ==== 0x647669 FUN_00647669

bool FUN_00647669(int *param_1,uint *param_2,long *param_3)

{
  char *pcVar1;
  long lVar2;
  undefined1 local_15;
  uint local_14;
  char *local_8;
  
  local_15 = 9;
  local_14 = 0;
  do {
    if (*param_2 <= local_14) {
LAB_006476e3:
      lVar2 = _strtol((char *)*param_1,&local_8,10);
      *param_2 = *param_2 - ((int)local_8 - *param_1);
      if (local_14 != *param_2) {
        *(undefined1 *)(*param_1 + local_14) = local_15;
      }
      pcVar1 = (char *)*param_1;
      if (local_8 != pcVar1) {
        *param_3 = lVar2;
      }
      return local_8 != pcVar1;
    }
    if ((*(char *)(*param_1 + local_14) == '\t') || (*(char *)(*param_1 + local_14) == '\n')) {
      local_15 = *(undefined1 *)(*param_1 + local_14);
      *(undefined1 *)(*param_1 + local_14) = 0;
      goto LAB_006476e3;
    }
    local_14 = local_14 + 1;
  } while( true );
}


// ==== 0x647742 FUN_00647742

void FUN_00647742(int *param_1,uint *param_2,int param_3,int param_4,uint param_5,uint *param_6)

{
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_14 = *param_1;
  local_8 = 0;
  local_c = 0;
  if (local_14 == 0) {
    *param_1 = 0;
    *param_2 = 0;
    *param_6 = 0xffffffff;
  }
  else {
    FUN_00647885(&local_14,param_2);
    for (local_10 = 0; local_10 < *param_2; local_10 = local_10 + 1) {
      for (local_8 = 0; local_8 < param_5; local_8 = local_8 + 1) {
        for (local_c = 0;
            ((local_c < *(uint *)(param_4 + local_8 * 4) && (local_10 + local_c < *param_2)) &&
            (*(char *)(*(int *)(param_3 + local_8 * 4) + local_c) ==
             *(char *)(local_14 + local_10 + local_c))); local_c = local_c + 1) {
        }
        if (local_c == *(uint *)(param_4 + local_8 * 4)) {
          *param_1 = local_14 + local_10 + local_c;
          *param_2 = *param_2 - (local_10 + local_c);
          *param_6 = local_8;
          return;
        }
      }
    }
    *param_1 = 0;
    *param_2 = 0;
    *param_6 = 0xffffffff;
  }
  return;
}


// ==== 0x647885 FUN_00647885

void FUN_00647885(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar1 = *param_1;
  for (local_8 = 0; local_8 < *param_2; local_8 = local_8 + 1) {
    iVar2 = _isspace((int)*(char *)(iVar1 + local_8));
    if (iVar2 == 0) break;
  }
  *param_1 = iVar1 + local_8;
  *param_2 = *param_2 - local_8;
  return;
}


// ==== 0x6478e3 FUN_006478e3

undefined4 * __fastcall FUN_006478e3(undefined4 *param_1)

{
  *param_1 = 0x20;
  param_1[1] = 0x15e;
  param_1[2] = 600;
  param_1[3] = 0x32;
  param_1[4] = 0xffffffff;
  param_1[5] = 0xffffffff;
  *(undefined1 *)(param_1 + 9) = 0xff;
  *(undefined1 *)((int)param_1 + 0x25) = 0xff;
  *(undefined1 *)((int)param_1 + 0x26) = 0xff;
  *(undefined1 *)((int)param_1 + 0x27) = 0xff;
  param_1[6] = 2;
  param_1[7] = 2;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return param_1;
}


// ==== 0x647984 FUN_00647984

void __thiscall FUN_00647984(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== 0x647999 FUN_00647999

void __thiscall FUN_00647999(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


// ==== 0x6479af FUN_006479af

void __thiscall FUN_006479af(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


// ==== 0x6479c5 FUN_006479c5

void __thiscall FUN_006479c5(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}


// ==== 0x6479db FUN_006479db

void __thiscall FUN_006479db(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}


// ==== 0x6479f1 FUN_006479f1

void __thiscall FUN_006479f1(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ==== 0x647a07 FUN_00647a07

void __thiscall FUN_00647a07(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}


// ==== 0x647a1d FUN_00647a1d

void __thiscall FUN_00647a1d(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}


// ==== 0x647a33 FUN_00647a33

void __thiscall FUN_00647a33(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}


// ==== 0x647a49 FUN_00647a49

void __thiscall FUN_00647a49(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x24) = param_2;
  return;
}


// ==== 0x647a5f FUN_00647a5f

void __thiscall FUN_00647a5f(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x25) = param_2;
  return;
}


// ==== 0x647a75 FUN_00647a75

void __thiscall FUN_00647a75(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x26) = param_2;
  return;
}


// ==== 0x647a8b FUN_00647a8b

void __thiscall FUN_00647a8b(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x27) = param_2;
  return;
}


// ==== 0x647ab0 FUN_00647ab0

int __thiscall FUN_00647ab0(int param_1,uint param_2)

{
  if ((param_2 & 2) == 0) {
    FUN_006497d0();
    if ((param_2 & 1) != 0) {
      FUN_00645e90(param_1);
    }
  }
  else {
    FUN_005b5e6c(param_1,0x34,*(undefined4 *)(param_1 + -4),FUN_006497d0);
    if ((param_2 & 1) != 0) {
      FUN_00645e90(param_1 + -4);
    }
    param_1 = param_1 + -4;
  }
  return param_1;
}


// ==== 0x647b20 FUN_00647b20

void FUN_00647b20(undefined4 param_1)

{
  FUN_005a44e0("RCMP::AV_SUBTITLE",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x647b50 FUN_00647b50

undefined4 __fastcall FUN_00647b50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}


// ==== 0x647b70 FUN_00647b70

undefined4 __fastcall FUN_00647b70(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== 0x647b90 FUN_00647b90

undefined4 __fastcall FUN_00647b90(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== 0x647bb0 FUN_00647bb0

undefined4 __fastcall FUN_00647bb0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


// ==== 0x647bd0 FUN_00647bd0

undefined1 __fastcall FUN_00647bd0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x24);
}


// ==== 0x647bf0 FUN_00647bf0

undefined1 __fastcall FUN_00647bf0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x25);
}


// ==== 0x647c10 FUN_00647c10

undefined1 __fastcall FUN_00647c10(int param_1)

{
  return *(undefined1 *)(param_1 + 0x26);
}


// ==== 0x647c30 FUN_00647c30

undefined1 __fastcall FUN_00647c30(int param_1)

{
  return *(undefined1 *)(param_1 + 0x27);
}


// ==== 0x647c50 FUN_00647c50

undefined4 __fastcall FUN_00647c50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}


// ==== 0x647c70 FUN_00647c70

undefined4 __fastcall FUN_00647c70(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}


// ==== 0x647c90 FUN_00647c90

undefined4 __fastcall FUN_00647c90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}


// ==== 0x647cb0 FUN_00647cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00647cb0(int param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6,uint param_7,
            uint param_8,uint param_9)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  int local_28;
  int local_24;
  int local_18;
  undefined *local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (DAT_0070fdd8 == 0) {
    uVar1 = 0;
  }
  else if (param_9 < 8) {
    if ((param_4 & 1) == 0) {
      if (param_9 == 1) {
        if ((param_8 & 7) != 0) {
          return 3;
        }
        local_c = param_7;
        if ((param_7 & 7) != 0) {
          if ((param_7 & 3) != 0) {
            return 4;
          }
          local_c = param_7 + 4;
          param_5 = param_5 - 1;
        }
      }
      else {
        if ((param_8 & 3) != 0) {
          return 3;
        }
        local_c = param_7;
        if ((param_7 & 3) != 0) {
          if ((param_7 & 1) != 0) {
            return 4;
          }
          local_c = param_7 + 2;
          param_5 = param_5 - 1;
        }
      }
      param_5 = param_5 & 0xfffffffe;
      if ((param_9 == 7) && (0x400 < (int)param_5)) {
        uVar1 = 5;
      }
      else if (((int)param_5 < 2) || (param_6 < 1)) {
        uVar1 = 0;
      }
      else {
        local_8 = param_1;
        local_24 = param_2;
        local_18 = param_3;
        iVar2 = (int)param_4 >> 1;
        if (((param_9 == 0) || (param_9 == 2)) || (param_9 == 3)) {
          local_28 = param_5 << 1;
        }
        else {
          local_28 = param_5 << 2;
        }
        switch(param_9) {
        case 0:
          for (local_10 = 0; (int)local_10 < param_6; local_10 = local_10 + 1) {
            FUN_006481be(local_8,local_24,local_18,local_c,local_c + local_28);
            local_8 = local_8 + param_4;
            if ((local_10 & 1) != 0) {
              local_24 = local_24 + iVar2;
              local_18 = local_18 + iVar2;
            }
            local_c = local_c + param_8;
          }
          break;
        case 1:
          FUN_00648517(0);
          for (local_10 = 0; (int)local_10 < param_6; local_10 = local_10 + 1) {
            FUN_00648208(local_8,local_24,local_18,local_c,local_c + local_28);
            local_8 = local_8 + param_4;
            if ((local_10 & 1) != 0) {
              local_24 = local_24 + iVar2;
              local_18 = local_18 + iVar2;
            }
            local_c = local_c + param_8;
          }
          FUN_006481b7();
          break;
        case 2:
        case 3:
          FUN_006485e9(param_9 & 1);
          for (local_10 = 0; (int)local_10 < param_6; local_10 = local_10 + 1) {
            FUN_00648272(local_8,local_24,local_18,local_c,local_c + local_28);
            local_8 = local_8 + param_4;
            if ((local_10 & 1) != 0) {
              local_24 = local_24 + iVar2;
              local_18 = local_18 + iVar2;
            }
            local_c = local_c + param_8;
            DAT_00711008 = DAT_00711008 ^ _DAT_00710ff8;
            DAT_0071100c = DAT_0071100c ^ _DAT_00710ffc;
          }
          FUN_006481b7();
          break;
        case 4:
        case 5:
          FUN_006485e9(param_9 & 1);
          for (local_10 = 0; (int)local_10 < param_6; local_10 = local_10 + 1) {
            FUN_00648318(local_8,local_24,local_18,local_c,local_c + local_28);
            local_8 = local_8 + param_4;
            if ((local_10 & 1) != 0) {
              local_24 = local_24 + iVar2;
              local_18 = local_18 + iVar2;
            }
            local_c = local_c + param_8;
            DAT_00711008 = DAT_00711008 ^ _DAT_00710ff8;
            DAT_0071100c = DAT_0071100c ^ _DAT_00710ffc;
          }
          FUN_006481b7();
          break;
        case 6:
        case 7:
          FUN_006485e9(param_9 & 1);
          puVar4 = &DAT_0070fff0;
          local_14 = &DAT_00711010;
          FUN_00648208(param_1,param_2,param_3,&DAT_0070fff0,&DAT_0070fff0 + local_28);
          for (local_10 = 0; puVar5 = puVar4, (int)local_10 < param_6; local_10 = local_10 + 1) {
            FUN_00648208(local_8,local_24,local_18,local_14,local_14 + local_28);
            FUN_006483e9(puVar5,local_c,local_c + local_28);
            iVar3 = local_c + param_8;
            DAT_00711008 = DAT_00711008 ^ _DAT_00710ff8;
            DAT_0071100c = DAT_0071100c ^ _DAT_00710ffc;
            FUN_0064846b(puVar5,local_14,iVar3,iVar3 + local_28);
            local_c = iVar3 + param_8;
            DAT_00711008 = DAT_00711008 ^ _DAT_00710ff8;
            DAT_0071100c = DAT_0071100c ^ _DAT_00710ffc;
            local_8 = local_8 + param_4;
            if ((local_10 & 1) != 0) {
              local_24 = local_24 + iVar2;
              local_18 = local_18 + iVar2;
            }
            puVar4 = local_14;
            local_14 = puVar5;
          }
          FUN_006481b7(param_9,puVar5);
        }
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== 0x6481b7 FUN_006481b7

void FUN_006481b7(void)

{
  return;
}


// ==== 0x6481be FUN_006481be

void FUN_006481be(byte *param_1,byte *param_2,undefined1 *param_3,int *param_4,int *param_5)

{
  byte *pbVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  
  do {
    uVar2 = *param_3;
    param_3 = param_3 + 1;
    pbVar1 = param_1 + 1;
    bVar3 = *param_2;
    param_2 = param_2 + 1;
    bVar4 = *param_1;
    param_1 = param_1 + 2;
    *param_4 = ((uint)CONCAT11(uVar2,*pbVar1) * 0x100 + (uint)bVar3) * 0x100 + (uint)bVar4;
    param_4 = param_4 + 1;
  } while (param_4 != param_5);
  return;
}


// ==== 0x648208 FUN_00648208

undefined4
FUN_00648208(byte *param_1,byte *param_2,byte *param_3,undefined8 *param_4,undefined8 *param_5)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  undefined8 *puVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  
  do {
    bVar4 = *param_2;
    param_2 = param_2 + 1;
    bVar5 = *param_3;
    param_3 = param_3 + 1;
    uVar2 = *(undefined8 *)(&DAT_006e8930 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e9130 + (uint)bVar5 * 4);
    bVar4 = *param_1;
    sVar11 = (short)uVar2 + (short)uVar3;
    sVar12 = (short)((ulonglong)uVar2 >> 0x10) + (short)((ulonglong)uVar3 >> 0x10);
    sVar13 = (short)((ulonglong)uVar2 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20);
    sVar14 = (short)((ulonglong)uVar2 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30);
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    uVar2 = *(undefined8 *)(&DAT_006e8130 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e8130 + (uint)*pbVar1 * 4);
    sVar7 = (short)uVar2 + sVar11;
    sVar8 = (short)((ulonglong)uVar2 >> 0x10) + sVar12;
    sVar9 = (short)((ulonglong)uVar2 >> 0x20) + sVar13;
    sVar10 = (short)((ulonglong)uVar2 >> 0x30) + sVar14;
    sVar11 = (short)uVar3 + sVar11;
    sVar12 = (short)((ulonglong)uVar3 >> 0x10) + sVar12;
    sVar13 = (short)((ulonglong)uVar3 >> 0x20) + sVar13;
    sVar14 = (short)((ulonglong)uVar3 >> 0x30) + sVar14;
    puVar6 = param_4 + 1;
    *param_4 = CONCAT17((0 < sVar14) * (sVar14 < 0x100) * (char)sVar14 - (0xff < sVar14),
                        CONCAT16((0 < sVar13) * (sVar13 < 0x100) * (char)sVar13 - (0xff < sVar13),
                                 CONCAT15((0 < sVar12) * (sVar12 < 0x100) * (char)sVar12 -
                                          (0xff < sVar12),
                                          CONCAT14((0 < sVar11) * (sVar11 < 0x100) * (char)sVar11 -
                                                   (0xff < sVar11),
                                                   CONCAT13((0 < sVar10) * (sVar10 < 0x100) *
                                                            (char)sVar10 - (0xff < sVar10),
                                                            CONCAT12((0 < sVar9) * (sVar9 < 0x100) *
                                                                     (char)sVar9 - (0xff < sVar9),
                                                                     CONCAT11((0 < sVar8) *
                                                                              (sVar8 < 0x100) *
                                                                              (char)sVar8 -
                                                                              (0xff < sVar8),
                                                                              (0 < sVar7) *
                                                                              (sVar7 < 0x100) *
                                                                              (char)sVar7 -
                                                                              (0xff < sVar7))))))));
    param_4 = puVar6;
  } while (puVar6 != param_5);
  return 0;
}


// ==== 0x648272 FUN_00648272

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00648272(byte *param_1,byte *param_2,byte *param_3,uint *param_4,uint *param_5)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint *puVar10;
  short sVar11;
  short sVar14;
  short sVar15;
  short sVar16;
  ulonglong uVar12;
  ulonglong uVar13;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  
  uVar9 = _DAT_00711008;
  uVar8 = DAT_00711000;
  uVar7 = DAT_0070ffe8;
  uVar6 = DAT_0070ffe0;
  do {
    bVar4 = *param_2;
    param_2 = param_2 + 1;
    bVar5 = *param_3;
    param_3 = param_3 + 1;
    uVar2 = *(undefined8 *)(&DAT_006e8930 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e9130 + (uint)bVar5 * 4);
    bVar4 = *param_1;
    sVar17 = (short)uVar2 + (short)uVar3;
    sVar18 = (short)((ulonglong)uVar2 >> 0x10) + (short)((ulonglong)uVar3 >> 0x10);
    sVar19 = (short)((ulonglong)uVar2 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20);
    sVar20 = (short)((ulonglong)uVar2 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30);
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    uVar2 = *(undefined8 *)(&DAT_006e8130 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e8130 + (uint)*pbVar1 * 4);
    sVar11 = (short)uVar2 + sVar17;
    sVar14 = (short)((ulonglong)uVar2 >> 0x10) + sVar18;
    sVar15 = (short)((ulonglong)uVar2 >> 0x20) + sVar19;
    sVar16 = (short)((ulonglong)uVar2 >> 0x30) + sVar20;
    sVar17 = (short)uVar3 + sVar17;
    sVar18 = (short)((ulonglong)uVar3 >> 0x10) + sVar18;
    sVar19 = (short)((ulonglong)uVar3 >> 0x20) + sVar19;
    sVar20 = (short)((ulonglong)uVar3 >> 0x30) + sVar20;
    puVar10 = param_4 + 1;
    uVar12 = paddusb(CONCAT17((0 < sVar20) * (sVar20 < 0x100) * (char)sVar20 - (0xff < sVar20),
                              CONCAT16((0 < sVar19) * (sVar19 < 0x100) * (char)sVar19 -
                                       (0xff < sVar19),
                                       CONCAT15((0 < sVar18) * (sVar18 < 0x100) * (char)sVar18 -
                                                (0xff < sVar18),
                                                CONCAT14((0 < sVar17) * (sVar17 < 0x100) *
                                                         (char)sVar17 - (0xff < sVar17),
                                                         CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                                  (char)sVar16 - (0xff < sVar16),
                                                                  CONCAT12((0 < sVar15) *
                                                                           (sVar15 < 0x100) *
                                                                           (char)sVar15 -
                                                                           (0xff < sVar15),
                                                                           CONCAT11((0 < sVar14) *
                                                                                    (sVar14 < 0x100)
                                                                                    * (char)sVar14 -
                                                                                    (0xff < sVar14),
                                                                                    (0 < sVar11) *
                                                                                    (sVar11 < 0x100)
                                                                                    * (char)sVar11 -
                                                                                    (0xff < sVar11))
                                                                          )))))),uVar9);
    uVar13 = pmaddwd(uVar12 & uVar6,uVar7);
    uVar13 = uVar13 | CONCAT44((uint)((uVar12 & uVar8) >> 0x2b),(uint)(uVar12 & uVar8) >> 0xb);
    *param_4 = (uint)(uVar13 >> 0x10) | (uint)uVar13;
    param_4 = puVar10;
  } while (puVar10 != param_5);
  return 0;
}


// ==== 0x648318 FUN_00648318

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00648318(byte *param_1,byte *param_2,byte *param_3,uint *param_4,uint *param_5)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint *puVar10;
  short sVar11;
  short sVar14;
  short sVar15;
  short sVar16;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar17;
  ulonglong uVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  short sVar22;
  
  uVar9 = _DAT_00711008;
  uVar8 = DAT_00711000;
  uVar7 = DAT_0070ffe8;
  uVar6 = DAT_0070ffe0;
  do {
    bVar4 = *param_2;
    param_2 = param_2 + 1;
    bVar5 = *param_3;
    param_3 = param_3 + 1;
    uVar2 = *(undefined8 *)(&DAT_006e8930 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e9130 + (uint)bVar5 * 4);
    bVar4 = *param_1;
    sVar19 = (short)uVar2 + (short)uVar3;
    sVar20 = (short)((ulonglong)uVar2 >> 0x10) + (short)((ulonglong)uVar3 >> 0x10);
    sVar21 = (short)((ulonglong)uVar2 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20);
    sVar22 = (short)((ulonglong)uVar2 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30);
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    uVar2 = *(undefined8 *)(&DAT_006e8130 + (uint)bVar4 * 4);
    uVar3 = *(undefined8 *)(&DAT_006e8130 + (uint)*pbVar1 * 4);
    sVar11 = (short)uVar2 + sVar19;
    sVar14 = (short)((ulonglong)uVar2 >> 0x10) + sVar20;
    sVar15 = (short)((ulonglong)uVar2 >> 0x20) + sVar21;
    sVar16 = (short)((ulonglong)uVar2 >> 0x30) + sVar22;
    sVar19 = (short)uVar3 + sVar19;
    sVar20 = (short)((ulonglong)uVar3 >> 0x10) + sVar20;
    sVar21 = (short)((ulonglong)uVar3 >> 0x20) + sVar21;
    sVar22 = (short)((ulonglong)uVar3 >> 0x30) + sVar22;
    puVar10 = param_4 + 2;
    uVar12 = paddusb(CONCAT17((0 < sVar16) * (sVar16 < 0x100) * (char)sVar16 - (0xff < sVar16),
                              CONCAT16((0 < sVar15) * (sVar15 < 0x100) * (char)sVar15 -
                                       (0xff < sVar15),
                                       CONCAT15((0 < sVar14) * (sVar14 < 0x100) * (char)sVar14 -
                                                (0xff < sVar14),
                                                CONCAT14((0 < sVar11) * (sVar11 < 0x100) *
                                                         (char)sVar11 - (0xff < sVar11),
                                                         CONCAT13((0 < sVar16) * (sVar16 < 0x100) *
                                                                  (char)sVar16 - (0xff < sVar16),
                                                                  CONCAT12((0 < sVar15) *
                                                                           (sVar15 < 0x100) *
                                                                           (char)sVar15 -
                                                                           (0xff < sVar15),
                                                                           CONCAT11((0 < sVar14) *
                                                                                    (sVar14 < 0x100)
                                                                                    * (char)sVar14 -
                                                                                    (0xff < sVar14),
                                                                                    (0 < sVar11) *
                                                                                    (sVar11 < 0x100)
                                                                                    * (char)sVar11 -
                                                                                    (0xff < sVar11))
                                                                          )))))),uVar9);
    uVar17 = paddusb(CONCAT17((0 < sVar22) * (sVar22 < 0x100) * (char)sVar22 - (0xff < sVar22),
                              CONCAT16((0 < sVar21) * (sVar21 < 0x100) * (char)sVar21 -
                                       (0xff < sVar21),
                                       CONCAT15((0 < sVar20) * (sVar20 < 0x100) * (char)sVar20 -
                                                (0xff < sVar20),
                                                CONCAT14((0 < sVar19) * (sVar19 < 0x100) *
                                                         (char)sVar19 - (0xff < sVar19),
                                                         CONCAT13((0 < sVar22) * (sVar22 < 0x100) *
                                                                  (char)sVar22 - (0xff < sVar22),
                                                                  CONCAT12((0 < sVar21) *
                                                                           (sVar21 < 0x100) *
                                                                           (char)sVar21 -
                                                                           (0xff < sVar21),
                                                                           CONCAT11((0 < sVar20) *
                                                                                    (sVar20 < 0x100)
                                                                                    * (char)sVar20 -
                                                                                    (0xff < sVar20),
                                                                                    (0 < sVar19) *
                                                                                    (sVar19 < 0x100)
                                                                                    * (char)sVar19 -
                                                                                    (0xff < sVar19))
                                                                          )))))),uVar9);
    uVar13 = pmaddwd(uVar12 & uVar6,uVar7);
    uVar18 = pmaddwd(uVar17 & uVar6,uVar7);
    uVar12 = uVar12 & uVar8;
    uVar17 = uVar17 & uVar8;
    uVar13 = uVar13 | CONCAT44((uint)(uVar12 >> 0x2b),(uint)uVar12 >> 0xb);
    uVar18 = uVar18 | CONCAT44((uint)(uVar17 >> 0x2b),(uint)uVar17 >> 0xb);
    *param_4 = (uint)(uVar13 >> 0x10) | (uint)uVar13;
    param_4[1] = (uint)(uVar18 >> 0x10) | (uint)uVar18;
    param_4 = puVar10;
  } while (puVar10 != param_5);
  return 0;
}


// ==== 0x6483e9 FUN_006483e9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006483e9(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  uVar6 = _DAT_00711008;
  uVar5 = DAT_00711000;
  uVar4 = DAT_0070ffe8;
  uVar3 = DAT_0070ffe0;
  uVar2 = DAT_006e9930;
  uVar8 = *param_1 >> 1 & DAT_006e9930;
  do {
    uVar1 = *param_1;
    uVar10 = uVar1 >> 1 & uVar2;
    param_1 = param_1 + 1;
    uVar8 = paddusb(CONCAT44(uVar1,CONCAT13((char)(uVar8 >> 0x18) + (char)(uVar10 >> 0x18),
                                            CONCAT12((char)(uVar8 >> 0x10) + (char)(uVar10 >> 0x10),
                                                     CONCAT11((char)(uVar8 >> 8) +
                                                              (char)(uVar10 >> 8),
                                                              (char)uVar8 + (char)uVar10)))),uVar6);
    uVar9 = pmaddwd(uVar8 & uVar3,uVar4);
    puVar7 = param_2 + 1;
    uVar9 = uVar9 | CONCAT44((uint)((uVar8 & uVar5) >> 0x2b),(uint)(uVar8 & uVar5) >> 0xb);
    *param_2 = (uint)uVar9 | (uint)(uVar9 >> 0x10);
    param_2 = puVar7;
    uVar8 = uVar10;
  } while (puVar7 != param_3);
  return;
}


// ==== 0x64846b FUN_0064846b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064846b(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar5 = _DAT_00711008;
  uVar4 = DAT_00711000;
  uVar3 = DAT_0070ffe8;
  uVar2 = DAT_0070ffe0;
  uVar1 = DAT_006e9930;
  uVar7 = *param_1 >> 1 & DAT_006e9930;
  uVar8 = *param_2 >> 1 & DAT_006e9930;
  uVar7 = (ulonglong)
          CONCAT13((char)(uVar7 >> 0x18) + (char)(uVar8 >> 0x18),
                   CONCAT12((char)(uVar7 >> 0x10) + (char)(uVar8 >> 0x10),
                            CONCAT11((char)(uVar7 >> 8) + (char)(uVar8 >> 8),
                                     (char)uVar7 + (char)uVar8)));
  do {
    uVar8 = *param_1 >> 1 & uVar1;
    uVar10 = *param_2 >> 1 & uVar1;
    param_1 = param_1 + 1;
    uVar9 = CONCAT13((char)(uVar10 >> 0x18) + (char)(uVar8 >> 0x18),
                     CONCAT12((char)(uVar10 >> 0x10) + (char)(uVar8 >> 0x10),
                              CONCAT11((char)(uVar10 >> 8) + (char)(uVar8 >> 8),
                                       (char)uVar10 + (char)uVar8)));
    param_2 = param_2 + 1;
    uVar10 = uVar9 >> 1 & uVar1;
    uVar7 = paddusb(CONCAT44(uVar9,CONCAT13((char)(uVar7 >> 0x18) + (char)(uVar10 >> 0x18),
                                            CONCAT12((char)(uVar7 >> 0x10) + (char)(uVar10 >> 0x10),
                                                     CONCAT11((char)(uVar7 >> 8) +
                                                              (char)(uVar10 >> 8),
                                                              (char)uVar7 + (char)uVar10)))),uVar5);
    uVar8 = pmaddwd(uVar7 & uVar2,uVar3);
    puVar6 = param_3 + 1;
    uVar8 = uVar8 | CONCAT44((uint)((uVar7 & uVar4) >> 0x2b),(uint)(uVar7 & uVar4) >> 0xb);
    *param_3 = (uint)uVar8 | (uint)(uVar8 >> 0x10);
    param_3 = puVar6;
    uVar7 = uVar10;
  } while (puVar6 != param_4);
  return;
}


// ==== 0x648517 FUN_00648517

void FUN_00648517(int param_1)

{
  undefined2 uVar1;
  int local_8;
  
  if (DAT_00712018 != param_1) {
    for (local_8 = 0; local_8 < 0xff; local_8 = local_8 + 1) {
      uVar1 = (&DAT_006e8130)[local_8 * 4];
      (&DAT_006e8130)[local_8 * 4] = (&DAT_006e8132)[local_8 * 4];
      (&DAT_006e8132)[local_8 * 4] = uVar1;
      uVar1 = (&DAT_006e8930)[local_8 * 4];
      (&DAT_006e8930)[local_8 * 4] = (&DAT_006e8932)[local_8 * 4];
      (&DAT_006e8932)[local_8 * 4] = uVar1;
      uVar1 = (&DAT_006e9130)[local_8 * 4];
      (&DAT_006e9130)[local_8 * 4] = (&DAT_006e9132)[local_8 * 4];
      (&DAT_006e9132)[local_8 * 4] = uVar1;
    }
    DAT_00712018 = param_1;
  }
  return;
}


// ==== 0x6485e9 FUN_006485e9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006485e9(int param_1)

{
  FUN_00648517(1);
  if (param_1 == 0) {
    DAT_00711008 = 0x40404;
    _DAT_00710ff8 = 0x60606;
    _DAT_00710ffc = 0x60606;
    DAT_0070ffe0._0_4_ = 0x1f800f8;
    DAT_0070ffe0._4_4_ = 0x1f800f8;
    DAT_0070ffe8._0_4_ = 0x800004;
    DAT_0070ffe8._4_4_ = 0x800004;
  }
  else {
    DAT_00711008 = 0x40402;
    _DAT_00710ff8 = 0x60603;
    _DAT_00710ffc = 0x60603;
    DAT_0070ffe0._0_4_ = 0xf800fc;
    DAT_0070ffe0._4_4_ = 0xf800fc;
    DAT_0070ffe8._0_4_ = 0x1000008;
    DAT_0070ffe8._4_4_ = 0x1000008;
  }
  DAT_0071100c = 0;
  DAT_00711000._4_4_ = 0xf800;
  DAT_00711000._0_4_ = 0xf800;
  return;
}


// ==== 0x6486e2 FUN_006486e2

void FUN_006486e2(void)

{
  undefined2 uVar1;
  undefined2 *local_18;
  undefined2 *local_10;
  undefined2 *local_c;
  int local_8;
  
  local_18 = &DAT_006e8130;
  local_c = &DAT_006e8930;
  local_10 = &DAT_006e9130;
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *local_18 = (undefined2)local_8;
    local_18[1] = (undefined2)local_8;
    local_18[2] = (undefined2)local_8;
    local_18[3] = 0xff;
    local_18 = local_18 + 4;
    uVar1 = FUN_00648887((float)(local_8 + -0x80) * 1.772);
    *local_c = uVar1;
    uVar1 = FUN_00648887((float)(local_8 + -0x80) * -0.3441);
    local_c[1] = uVar1;
    local_c[2] = 0;
    local_c[3] = 0;
    local_c = local_c + 4;
    *local_10 = 0;
    uVar1 = FUN_00648887((float)(local_8 + -0x80) * -0.7141);
    local_10[1] = uVar1;
    uVar1 = FUN_00648887((float)(local_8 + -0x80) * 1.402);
    local_10[2] = uVar1;
    local_10[3] = 0;
    local_10 = local_10 + 4;
  }
  DAT_00712018 = 0;
  return;
}


// ==== 0x648887 FUN_00648887

undefined4 FUN_00648887(float param_1)

{
  undefined4 uVar1;
  
  if (param_1 <= 0.0) {
    if (0.0 <= param_1) {
      uVar1 = 0;
    }
    else {
      uVar1 = _ftol_nocw();
    }
  }
  else {
    uVar1 = _ftol_nocw();
  }
  return uVar1;
}


// ==== 0x6488d0 FUN_006488d0

void __fastcall FUN_006488d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a9794;
  return;
}


// ==== 0x6488f0 FUN_006488f0

void * __thiscall FUN_006488f0(void *param_1,uint param_2)

{
  FUN_006488d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x648920 CGlobalUtils

/* Library Function - Single Match
    public: __thiscall CGlobalUtils::CGlobalUtils(void)
   
   Library: Visual Studio 2010 Debug */

CGlobalUtils * __thiscall CGlobalUtils::CGlobalUtils(CGlobalUtils *this)

{
  *(undefined ***)this = &PTR_FUN_006a9794;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}


// ==== 0x64894b FUN_0064894b

undefined4 * __thiscall FUN_0064894b(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = &PTR_FUN_006a9798;
  COleDataObject::COleDataObject((COleDataObject *)(param_1 + 2));
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  param_1[6] = 0;
  param_1[1] = 0;
  return param_1;
}


// ==== 0x6489a2 FUN_006489a2

void __fastcall FUN_006489a2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a9798;
  FUN_00648a0b();
  FUN_006497d0();
  return;
}


// ==== 0x6489c9 FUN_006489c9

undefined4 __thiscall FUN_006489c9(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 4))(param_1,param_3);
  return uVar1;
}


// ==== 0x648a0b FUN_00648a0b

void __fastcall FUN_00648a0b(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


// ==== 0x648a58 FUN_00648a58

void __fastcall FUN_00648a58(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Please choose a codec during the first data call back\n");
  }
  (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
  return;
}


// ==== 0x648a8e FUN_00648a8e

void __fastcall FUN_00648a8e(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Please choose a codec during the first data call back\n");
  }
  (**(code **)(**(int **)(param_1 + 0x18) + 0x10))();
  return;
}


// ==== 0x648ac8 FUN_00648ac8

void __thiscall FUN_00648ac8(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x18) == 0) && (*(int *)(param_1 + 4) == 0)) {
    puVar1 = (undefined4 *)FUN_00648cd0(param_1 + 4);
    iVar2 = FUN_00648cd0(param_1,*puVar1);
    (**(code **)(iVar2 + 4))();
  }
  if (*(int *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("Please choose a codec during the first data call back\n");
  }
  (**(code **)(**(int **)(param_1 + 0x18) + 8))(param_2);
  return;
}


// ==== 0x648b3a FUN_00648b3a

void __thiscall FUN_00648b3a(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/decoder/cmn/rcmpbase.cpp",0x6b,
                 "m_codec != NULL");
  }
  (**(code **)(**(int **)(param_1 + 0x18) + 0x14))(param_2);
  return;
}


// ==== 0x648b7f FUN_00648b7f

undefined4 __fastcall FUN_00648b7f(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 4) == 0) {
    puVar1 = (undefined4 *)FUN_00648cd0(&local_8);
    iVar2 = FUN_00648cd0(param_1,*puVar1);
    (**(code **)(iVar2 + 4))();
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return local_8;
}


// ==== 0x648bd1 FUN_00648bd1

void __thiscall FUN_00648bd1(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_00648cd0(param_2,param_1);
  iVar2 = FUN_00648cd0(param_1,*puVar1);
  (**(code **)(iVar2 + 8))();
  return;
}


// ==== 0x648bff FUN_00648bff

undefined4 * __fastcall FUN_00648bff(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return param_1;
}


// ==== 0x648c2a COleDataObject

/* Library Function - Single Match
    public: __thiscall COleDataObject::COleDataObject(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

COleDataObject * __thiscall COleDataObject::COleDataObject(COleDataObject *this)

{
  *(undefined4 *)(this + 0xc) = 2;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}


// ==== 0x648c5f FUN_00648c5f

undefined4 * __thiscall
FUN_00648c5f(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  param_1[3] = param_5;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  return param_1;
}


// ==== 0x648ca0 FUN_00648ca0

undefined4 __thiscall FUN_00648ca0(undefined4 param_1,uint param_2)

{
  FUN_006489a2();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x648cd0 FUN_00648cd0

int __fastcall FUN_00648cd0(int param_1)

{
  return param_1 + 8;
}


// ==== 0x648cf0 FUN_00648cf0

void __fastcall FUN_00648cf0(int param_1)

{
  *(code **)(param_1 + 4) = NullUpdate_ret;
  *(code **)(param_1 + 8) = FUN_00447030;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== 0x648d20 FUN_00648d20

undefined4 * __thiscall FUN_00648d20(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  FUN_006497c0();
  FUN_00649a00();
  param_1[4] = 0;
  *param_1 = 1;
  uVar1 = FUN_005a44e0("MAD_FRAME::m_Shape",((uint)(param_2 * 3 * param_3) >> 1) + 0x10,0,0x10,
                       DAT_00712028);
  param_1[1] = uVar1;
  FUN_00641a10(param_1[1],0,0x10);
  *(uint *)param_1[1] = *(uint *)param_1[1] & 0xffffff00 | 0x6c;
  *(undefined2 *)(param_1[1] + 4) = (undefined2)param_2;
  *(undefined2 *)(param_1[1] + 6) = (undefined2)param_3;
  return param_1;
}


// ==== 0x648dd5 FUN_00648dd5

void __fastcall FUN_00648dd5(int param_1)

{
  if (0 < *(int *)(param_1 + 0x10)) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80(" RCMP:: Warning: in ~MAD_FRAME() m_ReferenceCount >= 1 \n");
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_005a4510(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + 8;
  }
  FUN_00649a50(param_1);
  FUN_006497d0();
  return;
}


// ==== 0x648e44 _AFX_EDIT_STATE

/* Library Function - Single Match
    public: __thiscall _AFX_EDIT_STATE::_AFX_EDIT_STATE(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_AFX_EDIT_STATE * __thiscall _AFX_EDIT_STATE::_AFX_EDIT_STATE(_AFX_EDIT_STATE *this)

{
  FUN_00649810();
  *(undefined ***)this = &PTR_FUN_006a9854;
  FUN_00649b00();
  FUN_00649b00();
  *(undefined4 *)(this + 0xc) = 1;
  return this;
}


// ==== 0x648e83 FUN_00648e83

void __fastcall FUN_00648e83(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_006a9854;
  while (iVar1 = FUN_00649880(), iVar1 == 0) {
    iVar1 = FUN_00649cd0();
    if (iVar1 != 0) {
      FUN_006498e0(1);
    }
  }
  while (iVar1 = FUN_00649880(), iVar1 == 0) {
    iVar1 = FUN_00649cd0();
    if (iVar1 != 0) {
      FUN_006498e0(1);
    }
  }
  FUN_006498a0();
  FUN_006498a0();
  FUN_00649860();
  return;
}


// ==== 0x648f39 FUN_00648f39

undefined4 __thiscall FUN_00648f39(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return 2;
}


// ==== 0x648f68 FUN_00648f68

void FUN_00648f68(int param_1)

{
  undefined4 local_c;
  
  FUN_00649a70();
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = param_1 + 8;
  }
  FUN_00649c20(local_c);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}


// ==== 0x648fb8 FUN_00648fb8

undefined4 __fastcall FUN_00648fb8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}


// ==== 0x648fc9 FUN_00648fc9

float10 __fastcall FUN_00648fc9(int param_1)

{
  return (float10)*(float *)(param_1 + 4);
}


// ==== 0x648fda FUN_00648fda

void __thiscall FUN_00648fda(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00648b7f();
  *param_2 = uVar1;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return;
}


// ==== 0x649006 FUN_00649006

void FUN_00649006(int param_1)

{
  if (param_1 != 0) {
    FUN_00648bd1(param_1);
  }
  return;
}


// ==== 0x649028 FUN_00649028

int __thiscall FUN_00649028(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint _NewValue;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_3c;
  int local_2c;
  int local_1c;
  int local_18;
  int local_c;
  int local_8;
  
  iVar1 = FUN_00649910();
  local_2c = 0;
  local_c = 0;
  local_8 = 0;
  if (param_1[6] != 0) {
    uVar2 = FUN_005a4520();
    local_2c = FUN_00649443(uVar2);
    local_c = local_2c + param_1[4] * param_1[5];
    iVar3 = param_1[4] * 5 * param_1[5];
    local_8 = local_2c + ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2);
  }
  if (param_1[3] != 0) {
    iVar3 = FUN_00649401(iVar1 + 0xc,4);
    param_1[2] = iVar3;
    param_1[1] = (int)(1000.0 / ((float)param_1[2] / 65535.0));
    iVar3 = FUN_00649401(iVar1 + 0x10,2);
    param_1[4] = iVar3;
    iVar3 = FUN_00649401(iVar1 + 0x12,2);
    param_1[5] = iVar3;
    iVar3 = FUN_00648cd0();
    iVar3 = *(int *)(iVar3 + 0xc);
    for (local_18 = 0; local_18 < iVar3 + 1; local_18 = local_18 + 1) {
      FUN_00649930(param_1[4],param_1[5]);
    }
    param_1[3] = 0;
  }
  _NewValue = __control87(0,0);
  __control87(0x10000,0x30000);
  iVar3 = FUN_00649469(param_2);
  if (iVar3 == 0x4d41446b) {
    if (param_1[6] != 0) {
      (**(code **)(*param_1 + 0x14))(param_1[6]);
    }
    param_1[6] = 0;
    local_1c = FUN_00649628();
    FUN_00649d90(iVar1 + 0x18,0,(int)*(char *)(iVar1 + 0x15));
  }
  else {
    iVar3 = FUN_00649469(param_2);
    if (iVar3 == 0x4d41446d) {
      local_1c = FUN_00649628();
      FUN_00649d90(iVar1 + 0x18,1,(int)*(char *)(iVar1 + 0x15));
    }
    else {
      iVar3 = FUN_00649469(param_2);
      if (iVar3 != 0x4d414465) {
                    /* WARNING: Subroutine does not return */
        FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/decoder/cmn/rcmp_mad_codec.cpp",0xe0,
                     &DAT_006ca910);
      }
      local_1c = FUN_00649697();
      FUN_00649d90(iVar1 + 0x18,1,(int)*(char *)(iVar1 + 0x15));
    }
  }
  uVar2 = FUN_005a4520();
  iVar4 = FUN_00649443(uVar2);
  iVar1 = param_1[4];
  iVar3 = param_1[5];
  iVar5 = param_1[4] * 5 * param_1[5];
  for (local_18 = 0; local_18 < param_1[5]; local_18 = local_18 + 0x10) {
    for (local_3c = 0; local_3c < param_1[4]; local_3c = local_3c + 0x10) {
      iVar6 = local_18 * param_1[4] + local_3c;
      iVar7 = ((int)(local_18 * param_1[4] + (local_18 * param_1[4] >> 0x1f & 3U)) >> 2) +
              local_3c / 2;
      FUN_0064a28a(local_2c + iVar6,local_c + iVar7,local_8 + iVar7,iVar4 + iVar6,
                   iVar4 + iVar1 * iVar3 + iVar7,
                   iVar4 + ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + iVar7,param_1[4]);
    }
  }
  __control87(_NewValue,0xfffff);
  iVar1 = FUN_00649469(param_2);
  if (iVar1 == 0x4d41446d) {
    if (param_1[6] != 0) {
      (**(code **)(*param_1 + 0x14))(param_1[6]);
    }
    param_1[6] = local_1c;
  }
  else {
    iVar1 = FUN_00649469(param_2);
    if (iVar1 == 0x4d41446b) {
      param_1[6] = local_1c;
    }
  }
  return local_1c;
}


// ==== 0x649401 FUN_00649401

uint FUN_00649401(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)(byte)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)(ushort)*param_1;
  }
  else if (param_2 == 3) {
    uVar1 = *param_1 & 0xffffff;
  }
  else if (param_2 == 4) {
    uVar1 = *param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x649443 FUN_00649443

int FUN_00649443(int param_1)

{
  if ((*(uint *)(param_1 + 0xc) >> 0xc & 1) == 0) {
    param_1 = param_1 + 0x10;
  }
  else {
    param_1 = param_1 + *(int *)(param_1 + 0x10);
  }
  return param_1;
}


// ==== 0x649469 FUN_00649469

undefined4 __thiscall FUN_00649469(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x4d41446b;
  }
  else {
    uVar1 = FUN_00649910(param_1);
    uVar1 = FUN_00649497(uVar1,4);
  }
  return uVar1;
}


// ==== 0x649497 FUN_00649497

uint FUN_00649497(byte *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)CONCAT11(*param_1,param_1[1]);
  }
  else if (param_2 == 3) {
    uVar1 = (uint)*param_1 << 0x10 | (uint)param_1[1] << 8 | (uint)param_1[2];
  }
  else if (param_2 == 4) {
    uVar1 = (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[2] << 8 |
            (uint)param_1[3];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x64951e FUN_0064951e

undefined4 __thiscall FUN_0064951e(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  int local_8;
  
  FUN_00648fda(&local_8);
  if (param_1[3] == 0) {
    param_2 = param_2 - param_1[7];
    if (param_2 < 3) {
      if (0 < param_2) {
        for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
          iVar1 = FUN_00649469(local_8);
          if (iVar1 == 0x4d414465) {
            FUN_00649006(local_8);
            FUN_00648fda(&local_8);
          }
        }
      }
    }
    else {
      do {
        FUN_00649006(local_8);
        FUN_00648fda(&local_8);
        iVar1 = FUN_00649469(local_8);
      } while (iVar1 != 0x4d41446b);
    }
  }
  if (local_8 == 0) {
    if (param_1[6] != 0) {
      (**(code **)(*param_1 + 0x14))(param_1[6]);
      param_1[6] = 0;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00649028(local_8);
    FUN_00649006(local_8);
  }
  return uVar2;
}


// ==== 0x649628 FUN_00649628

int FUN_00649628(void)

{
  int iVar1;
  int local_10;
  
  iVar1 = FUN_00649880();
  if (iVar1 == 0) {
    iVar1 = FUN_00649cd0();
    if (iVar1 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = iVar1 + 8;
    }
    FUN_00649c20(local_10);
    *(undefined4 *)(iVar1 + 0x10) = 2;
  }
  else {
    Log_Printf(
              "MAD_CODEC_INTERNAL::CreateIorP() out of frames did you call CODEC::ReleaseFrame( FRAME *Frame )\n"
              );
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x649697 FUN_00649697

int FUN_00649697(void)

{
  int iVar1;
  int local_10;
  
  iVar1 = FUN_00649880();
  if (iVar1 == 0) {
    iVar1 = FUN_00649cd0();
    if (iVar1 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = iVar1 + 8;
    }
    FUN_00649c20(local_10);
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  else {
    Log_Printf(
              "MAD_CODEC_INTERNAL::CreateB() out of frames did you call CODEC::ReleaseFrame( FRAME *Frame )\n"
              );
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x649706 FUN_00649706

void FUN_00649706(int param_1)

{
  int local_10;
  
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  if (*(int *)(param_1 + 0x10) < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00642e80("RCMP_ASSERT in %s at %d \n %s\n","src/decoder/cmn/rcmp_mad_codec.cpp",0x163,
                 "Frame->m_ReferenceCount >= 0");
  }
  if (*(int *)(param_1 + 0x10) < 1) {
    FUN_00649a70();
    if (param_1 == 0) {
      local_10 = 0;
    }
    else {
      local_10 = param_1 + 8;
    }
    FUN_00649c20(local_10);
  }
  return;
}


// ==== 0x64978b CreateObject

/* Library Function - Multiple Matches With Same Base Name
    public: static class CNoTrackObject * __cdecl CProcessLocal<class
   COccManager>::CreateObject(void)
    public: static class CNoTrackObject * __cdecl CProcessLocal<class
   _AFX_SOCK_STATE>::CreateObject(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 CreateObject(void)

{
  _AFX_EDIT_STATE *this;
  undefined4 local_c;
  
  this = (_AFX_EDIT_STATE *)FUN_006499d0(0x34);
  if (this == (_AFX_EDIT_STATE *)0x0) {
    local_c = 0;
  }
  else {
    local_c = _AFX_EDIT_STATE::_AFX_EDIT_STATE(this);
  }
  return local_c;
}


// ==== 0x6497c0 FUN_006497c0

undefined4 __fastcall FUN_006497c0(undefined4 param_1)

{
  return param_1;
}


// ==== 0x6497d0 FUN_006497d0

void FUN_006497d0(void)

{
  return;
}


// ==== 0x6497e0 FUN_006497e0

undefined4 __thiscall FUN_006497e0(undefined4 param_1,uint param_2)

{
  FUN_00648e83();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x649810 FUN_00649810

undefined4 * __fastcall FUN_00649810(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a986c;
  return param_1;
}


// ==== 0x649830 FUN_00649830

undefined4 __thiscall FUN_00649830(undefined4 param_1,uint param_2)

{
  FUN_00649860();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x649860 FUN_00649860

void __fastcall FUN_00649860(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a986c;
  return;
}


// ==== 0x649880 FUN_00649880

bool __fastcall FUN_00649880(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_006460f0();
  return iVar1 == param_1;
}


// ==== 0x6498a0 FUN_006498a0

void __fastcall FUN_006498a0(undefined4 param_1)

{
  FUN_00649a50(param_1);
  return;
}


// ==== 0x6498c0 FUN_006498c0

void __fastcall FUN_006498c0(undefined4 *param_1)

{
  *param_1 = 7;
  param_1[1] = 7;
  return;
}


// ==== 0x6498e0 FUN_006498e0

undefined4 __thiscall FUN_006498e0(undefined4 param_1,uint param_2)

{
  FUN_00648dd5();
  if ((param_2 & 1) != 0) {
    FUN_00645e90(param_1);
  }
  return param_1;
}


// ==== 0x649910 FUN_00649910

undefined4 __fastcall FUN_00649910(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ==== 0x649930 FUN_00649930

void FUN_00649930(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = FUN_006499a0(0x14);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_00648d20(param_1,param_2);
  }
  if (local_10 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = local_10 + 8;
  }
  FUN_00649b70(local_14);
  return;
}


// ==== 0x6499a0 FUN_006499a0

void FUN_006499a0(undefined4 param_1)

{
  FUN_005a44e0("RCMP::MAD_FRAME",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x6499d0 FUN_006499d0

void FUN_006499d0(undefined4 param_1)

{
  FUN_005a44e0("RCMP::MAD_CODEC_INTERNAL",param_1,0,0,DAT_00712028);
  return;
}


// ==== 0x649a00 FUN_00649a00

undefined4 __fastcall FUN_00649a00(undefined4 param_1)

{
  FUN_00649a20();
  return param_1;
}


// ==== 0x649a20 FUN_00649a20

undefined4 * __fastcall FUN_00649a20(undefined4 *param_1)

{
  *param_1 = 3;
  param_1[1] = 3;
  return param_1;
}


// ==== 0x649a50 FUN_00649a50

void __fastcall FUN_00649a50(undefined4 param_1)

{
  FUN_006498c0(param_1);
  return;
}


// ==== 0x649a70 FUN_00649a70

int FUN_00649a70(void)

{
  undefined4 local_10;
  
  local_10 = FUN_00649ab0();
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -8;
  }
  return local_10;
}


// ==== 0x649ab0 FUN_00649ab0

int * __fastcall FUN_00649ab0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  *param_1 = 0xb;
  param_1[1] = 0xb;
  return param_1;
}


// ==== 0x649b00 FUN_00649b00

undefined4 __fastcall FUN_00649b00(undefined4 param_1)

{
  FUN_00649b20();
  FUN_00649b50();
  return param_1;
}


// ==== 0x649b20 FUN_00649b20

int __fastcall FUN_00649b20(int param_1)

{
  FUN_00649a20();
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  return param_1;
}


// ==== 0x649b50 FUN_00649b50

void __fastcall FUN_00649b50(int param_1)

{
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  return;
}


// ==== 0x649b70 FUN_00649b70

int FUN_00649b70(undefined4 param_1)

{
  undefined4 local_10;
  
  local_10 = FUN_00649bb0(param_1);
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -8;
  }
  return local_10;
}


// ==== 0x649bb0 FUN_00649bb0

void __fastcall FUN_00649bb0(undefined4 param_1)

{
  FUN_00649bd0(param_1);
  return;
}


// ==== 0x649bd0 FUN_00649bd0

int * __thiscall FUN_00649bd0(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_2 = (int)param_1;
  *(int **)(iVar1 + 4) = param_1;
  param_1[1] = (int)param_2;
  *param_1 = iVar1;
  return param_1;
}


// ==== 0x649c20 FUN_00649c20

int FUN_00649c20(undefined4 param_1)

{
  undefined4 local_10;
  
  local_10 = FUN_00649c60(param_1);
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -8;
  }
  return local_10;
}


// ==== 0x649c60 FUN_00649c60

void __fastcall FUN_00649c60(undefined4 param_1)

{
  FUN_00649c80(param_1);
  return;
}


// ==== 0x649c80 FUN_00649c80

int * __thiscall FUN_00649c80(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_2 + 4);
  *piVar1 = (int)param_1;
  *(int **)(param_2 + 4) = param_1;
  param_1[1] = (int)piVar1;
  *param_1 = param_2;
  return param_1;
}


// ==== 0x649cd0 FUN_00649cd0

int FUN_00649cd0(void)

{
  undefined4 local_10;
  
  local_10 = FUN_00649d10();
  if (local_10 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = local_10 + -8;
  }
  return local_10;
}


// ==== 0x649d10 FUN_00649d10

void __fastcall FUN_00649d10(undefined4 param_1)

{
  FUN_00649d30(param_1);
  FUN_00649ab0();
  return;
}


// ==== 0x649d30 FUN_00649d30

void __fastcall FUN_00649d30(undefined4 param_1)

{
  FUN_006460f0(param_1);
  return;
}


// ==== 0x649d50 FUN_00649d50

undefined4 FUN_00649d50(int param_1)

{
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 0;
    }
    if (*(int *)(&DAT_006a99bc + local_8 * 4) == param_1) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// ==== 0x649d90 FUN_00649d90

void FUN_00649d90(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_8;
  
  if (DAT_00713440 == 0) {
    FUN_00649eae();
  }
  iVar1 = FUN_00649e59(param_1,2);
  uVar2 = FUN_00649e59(param_1 + 2,2);
  DAT_00712c38 = iVar1 << 0x10 | uVar2;
  DAT_00712030 = 0x20;
  DAT_00713a48 = param_1 + 4;
  DAT_00713444 = param_2;
  DAT_00712438 = FUN_00649e9b(0x80000,DAT_006e9938);
  for (local_8 = 1; local_8 < 0x40; local_8 = local_8 + 1) {
    uVar3 = FUN_00649e9b(param_3 * (&DAT_006aa7b8)[local_8] * 0x2000,(&DAT_006e9938)[local_8]);
    (&DAT_00712438)[local_8] = uVar3;
  }
  return;
}


// ==== 0x649e59 FUN_00649e59

uint FUN_00649e59(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)(byte)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)(ushort)*param_1;
  }
  else if (param_2 == 3) {
    uVar1 = *param_1 & 0xffffff;
  }
  else if (param_2 == 4) {
    uVar1 = *param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x649e9b FUN_00649e9b

int FUN_00649e9b(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)((longlong)param_1 * (longlong)param_2);
  return (uVar1 >> 0x10) +
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) * 0x10000 +
         (uint)((uVar1 >> 0xf & 1) != 0);
}


// ==== 0x649eae FUN_00649eae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00649eae(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_20;
  char local_18;
  uint local_c;
  
  for (local_c = 0xffffff00; (int)local_c < 0xff; local_c = local_c + 1) {
    local_18 = (char)local_c;
    if ((int)local_c < -0x80) {
      local_18 = -0x80;
    }
    else if (0x7f < (int)local_c) {
      local_18 = '\x7f';
    }
    (&DAT_00713848)[local_c & 0x1ff] = local_18 + -0x80;
  }
  _DAT_00712c40 = 0xf;
  for (local_c = 1; (int)local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00712c40 + local_c * 4) = 0x1f;
  }
  for (local_c = 0; (int)local_c < 8; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00712c60 + local_c * 4) = 0x2f;
  }
  for (local_c = 0; (int)local_c < 0x80; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00713040 + local_c * 4) = 0x3f;
  }
  for (local_c = 1; (int)local_c < 0x5f; local_c = local_c + 1) {
    uVar1 = *(uint *)(&UNK_006a99c8 + local_c * 0x10);
    uVar2 = *(uint *)(&UNK_006a99cc + local_c * 0x10);
    uVar3 = *(uint *)(&UNK_006a99d4 + local_c * 0x10);
    if ((uVar3 & 0xfc00) == 0) {
      for (local_20 = 0; local_20 < 1 << (8U - ((char)uVar1 + -6) & 0x1f); local_20 = local_20 + 1)
      {
        *(uint *)(&DAT_00713448 + (((int)uVar3 >> 2) + local_20) * 4) =
             uVar2 << 0x16 | (uVar2 & 0xfc00) << 6 | uVar1 - 6;
      }
    }
    else {
      for (local_20 = 0; local_20 < 1 << (9U - (char)uVar1 & 0x1f); local_20 = local_20 + 1) {
        *(uint *)(&DAT_00712c40 + (((int)uVar3 >> 7) + local_20) * 4) =
             uVar2 << 0x16 | (uVar2 & 0xfc00) << 6 | uVar1;
      }
    }
  }
  for (local_c = 0; (int)local_c < 0x80; local_c = local_c + 1) {
    iVar4 = *(int *)(&DAT_006a9fb8 + local_c * 0x10);
    uVar1 = *(uint *)(&DAT_006a9fbc + local_c * 0x10);
    uVar2 = *(uint *)(&DAT_006a9fc4 + local_c * 0x10);
    if ((uVar2 & 0x8000) == 0) {
      for (local_20 = 0; local_20 < 1 << (8U - ((char)iVar4 + -1) & 0x1f); local_20 = local_20 + 1)
      {
        *(uint *)(&DAT_00712738 + (((int)uVar2 >> 7) + local_20) * 4) =
             uVar1 << 0x16 | (uVar1 & 0xfc00) << 6 | iVar4 - 1U;
      }
    }
    else {
      for (local_20 = 0; local_20 < 1 << (8U - ((char)iVar4 + '\x02') & 0x1f);
          local_20 = local_20 + 1) {
        *(uint *)(&DAT_00713448 + (((int)uVar2 >> 10) + local_20) * 4) =
             uVar1 << 0x16 | (uVar1 & 0xfc00) << 6 | iVar4 + 2U;
      }
    }
  }
  for (local_c = 0; (int)local_c < 0x20; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00712b38 + local_c * 4) = 1;
  }
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    *(uint *)(&DAT_00712bb8 + local_c * 4) = (local_c + 1) * 0x400000 | 6;
    *(uint *)(&DAT_00712bf8 + local_c * 4) = (local_c + -0x10) * 0x400000 | 6;
  }
  DAT_00713440 = 1;
  return;
}


// ==== 0x64a28a FUN_0064a28a

void FUN_0064a28a(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_10;
  
  iVar1 = param_7 >> 1;
  if (DAT_00713444 == 0) {
    local_10 = 0;
  }
  else if ((DAT_00712c38 & 0xc0000000) == 0) {
    local_10 = 0;
    FUN_0064a5ee(2);
  }
  else {
    if ((DAT_00712c38 & 0x80000000) == 0) {
      local_10 = DAT_00712c38 >> 0x18;
      FUN_0064a5ee(8);
    }
    else {
      local_10 = 0x3ff;
      FUN_0064a5ee(1);
    }
    iVar3 = FUN_0064a662();
    iVar2 = FUN_0064a662(iVar3);
    param_1 = param_1 + iVar2 * param_7 + iVar3;
    param_2 = param_2 + (iVar2 >> 1) * iVar1 + (iVar3 >> 1);
    param_3 = param_3 + (iVar2 >> 1) * iVar1 + (iVar3 >> 1);
  }
  if ((local_10 & 1) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712038,0x10);
    }
    else {
      FUN_0064abc0(&DAT_00712038,0x10);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a71f(param_1,param_7,&DAT_00712038,iVar3 * 2 + -0x80);
  }
  if ((local_10 & 2) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712058,0x10);
    }
    else {
      FUN_0064abc0(&DAT_00712058,0x10);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a71f(param_1 + 8,param_7,&DAT_00712058,iVar3 * 2 + -0x80);
  }
  if ((local_10 & 4) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712238,0x10);
    }
    else {
      FUN_0064abc0(&DAT_00712238,0x10);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a71f(param_1 + param_7 * 8,param_7,&DAT_00712238,iVar3 * 2 + -0x80);
  }
  if ((local_10 & 8) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712258,0x10);
    }
    else {
      FUN_0064abc0(&DAT_00712258,0x10);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a71f(param_1 + 8 + param_7 * 8,param_7,&DAT_00712258,iVar3 * 2 + -0x80);
  }
  if ((local_10 & 0x10) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712538,8);
    }
    else {
      FUN_0064abc0(&DAT_00712538,8);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a7f0(param_2,iVar1,&DAT_00712538,iVar3 * 2 + -0x80);
  }
  if ((local_10 & 0x20) == 0) {
    iVar3 = FUN_0064b110();
    if (iVar3 == 1) {
      FUN_0064a694(&DAT_00712638,8);
    }
    else {
      FUN_0064abc0(&DAT_00712638,8);
    }
  }
  else {
    iVar3 = FUN_0064a662();
    FUN_0064a7f0(param_3,iVar1,&DAT_00712638,iVar3 * 2 + -0x80);
  }
  FUN_0064a8c1(&DAT_00712038,param_4,param_7);
  FUN_0064aaa5(&DAT_00712538,param_5,iVar1);
  FUN_0064aaa5(&DAT_00712638,param_6,iVar1);
  return;
}


// ==== 0x64a5ee FUN_0064a5ee

void FUN_0064a5ee(int param_1)

{
  int iVar1;
  
  DAT_00712c38 = DAT_00712c38 << ((byte)param_1 & 0x1f);
  DAT_00712030 = DAT_00712030 - param_1;
  if (DAT_00712030 < 0x10) {
    iVar1 = FUN_00649e59(DAT_00713a48,2);
    DAT_00712c38 = DAT_00712c38 | iVar1 << (0x10U - (char)DAT_00712030 & 0x1f);
    DAT_00712030 = DAT_00712030 + 0x10;
    DAT_00713a48 = DAT_00713a48 + 2;
  }
  return;
}


// ==== 0x64a662 FUN_0064a662

int FUN_0064a662(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(&DAT_00712b38 + (DAT_00712c38 >> 0x1a) * 4);
  FUN_0064a5ee(uVar1 & 0xff);
  return (int)uVar1 >> 0x16;
}


// ==== 0x64a694 FUN_0064a694

void FUN_0064a694(undefined4 *param_1,int param_2)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    *param_1 = DAT_00713b50;
    param_1[1] = DAT_00713b50;
    param_1[2] = DAT_00713b50;
    param_1[3] = DAT_00713b50;
    param_1[4] = DAT_00713b50;
    param_1[5] = DAT_00713b50;
    param_1[6] = DAT_00713b50;
    param_1[7] = DAT_00713b50;
    param_1 = param_1 + param_2;
  }
  return;
}


// ==== 0x64a71f FUN_0064a71f

void FUN_0064a71f(byte *param_1,int param_2,int *param_3,int param_4)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    *param_3 = ((uint)*param_1 + param_4) * 0x10000;
    param_3[1] = ((uint)param_1[1] + param_4) * 0x10000;
    param_3[2] = ((uint)param_1[2] + param_4) * 0x10000;
    param_3[3] = ((uint)param_1[3] + param_4) * 0x10000;
    param_3[4] = ((uint)param_1[4] + param_4) * 0x10000;
    param_3[5] = ((uint)param_1[5] + param_4) * 0x10000;
    param_3[6] = ((uint)param_1[6] + param_4) * 0x10000;
    param_3[7] = ((uint)param_1[7] + param_4) * 0x10000;
    param_1 = param_1 + param_2;
    param_3 = param_3 + 0x10;
  }
  return;
}


// ==== 0x64a7f0 FUN_0064a7f0

void FUN_0064a7f0(byte *param_1,int param_2,int *param_3,int param_4)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    *param_3 = ((uint)*param_1 + param_4) * 0x10000;
    param_3[1] = ((uint)param_1[1] + param_4) * 0x10000;
    param_3[2] = ((uint)param_1[2] + param_4) * 0x10000;
    param_3[3] = ((uint)param_1[3] + param_4) * 0x10000;
    param_3[4] = ((uint)param_1[4] + param_4) * 0x10000;
    param_3[5] = ((uint)param_1[5] + param_4) * 0x10000;
    param_3[6] = ((uint)param_1[6] + param_4) * 0x10000;
    param_3[7] = ((uint)param_1[7] + param_4) * 0x10000;
    param_1 = param_1 + param_2;
    param_3 = param_3 + 8;
  }
  return;
}


// ==== 0x64a8c1 FUN_0064a8c1

void FUN_0064a8c1(int *param_1,undefined1 *param_2,int param_3)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    *param_2 = (&DAT_00713848)[*param_1 >> 0x10 & 0x1ff];
    param_2[1] = (&DAT_00713848)[param_1[1] >> 0x10 & 0x1ff];
    param_2[2] = (&DAT_00713848)[param_1[2] >> 0x10 & 0x1ff];
    param_2[3] = (&DAT_00713848)[param_1[3] >> 0x10 & 0x1ff];
    param_2[4] = (&DAT_00713848)[param_1[4] >> 0x10 & 0x1ff];
    param_2[5] = (&DAT_00713848)[param_1[5] >> 0x10 & 0x1ff];
    param_2[6] = (&DAT_00713848)[param_1[6] >> 0x10 & 0x1ff];
    param_2[7] = (&DAT_00713848)[param_1[7] >> 0x10 & 0x1ff];
    param_2[8] = (&DAT_00713848)[param_1[8] >> 0x10 & 0x1ff];
    param_2[9] = (&DAT_00713848)[param_1[9] >> 0x10 & 0x1ff];
    param_2[10] = (&DAT_00713848)[param_1[10] >> 0x10 & 0x1ff];
    param_2[0xb] = (&DAT_00713848)[param_1[0xb] >> 0x10 & 0x1ff];
    param_2[0xc] = (&DAT_00713848)[param_1[0xc] >> 0x10 & 0x1ff];
    param_2[0xd] = (&DAT_00713848)[param_1[0xd] >> 0x10 & 0x1ff];
    param_2[0xe] = (&DAT_00713848)[param_1[0xe] >> 0x10 & 0x1ff];
    param_2[0xf] = (&DAT_00713848)[param_1[0xf] >> 0x10 & 0x1ff];
    param_1 = param_1 + 0x10;
    param_2 = param_2 + param_3;
  }
  return;
}


// ==== 0x64aaa5 FUN_0064aaa5

void FUN_0064aaa5(int *param_1,undefined1 *param_2,int param_3)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    *param_2 = (&DAT_00713848)[*param_1 >> 0x10 & 0x1ff];
    param_2[1] = (&DAT_00713848)[param_1[1] >> 0x10 & 0x1ff];
    param_2[2] = (&DAT_00713848)[param_1[2] >> 0x10 & 0x1ff];
    param_2[3] = (&DAT_00713848)[param_1[3] >> 0x10 & 0x1ff];
    param_2[4] = (&DAT_00713848)[param_1[4] >> 0x10 & 0x1ff];
    param_2[5] = (&DAT_00713848)[param_1[5] >> 0x10 & 0x1ff];
    param_2[6] = (&DAT_00713848)[param_1[6] >> 0x10 & 0x1ff];
    param_2[7] = (&DAT_00713848)[param_1[7] >> 0x10 & 0x1ff];
    param_1 = param_1 + 8;
    param_2 = param_2 + param_3;
  }
  return;
}


// ==== 0x64abc0 FUN_0064abc0

void FUN_0064abc0(int param_1,int param_2)

{
  FUN_0064ad18(&DAT_00713b50,&DAT_00713a50);
  FUN_0064ad18(&DAT_00713b70,&DAT_00713a54);
  FUN_0064ad18(&DAT_00713b90,&DAT_00713a58);
  FUN_0064ad18(&DAT_00713bb0,&DAT_00713a5c);
  FUN_0064ad18(&DAT_00713bd0,&DAT_00713a60);
  FUN_0064ad18(&DAT_00713bf0,&DAT_00713a64);
  FUN_0064ad18(&DAT_00713c10,&DAT_00713a68);
  FUN_0064ad18(&DAT_00713c30,&DAT_00713a6c);
  FUN_0064af67(&DAT_00713a50,param_1);
  FUN_0064af67(&DAT_00713a70,param_1 + param_2 * 4);
  FUN_0064af67(&DAT_00713a90,param_1 + param_2 * 8);
  FUN_0064af67(&DAT_00713ab0,param_1 + param_2 * 0xc);
  FUN_0064af67(&DAT_00713ad0,param_1 + param_2 * 0x10);
  FUN_0064af67(&DAT_00713af0,param_1 + param_2 * 0x14);
  FUN_0064af67(&DAT_00713b10,param_1 + param_2 * 0x18);
  FUN_0064af67(&DAT_00713b30,param_1 + param_2 * 0x1c);
  return;
}


// ==== 0x64ad18 FUN_0064ad18

void FUN_0064ad18(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if ((((((param_1[1] == 0 && param_1[2] == 0) && param_1[3] == 0) && param_1[4] == 0) &&
       param_1[5] == 0) && param_1[6] == 0) && param_1[7] == 0) {
    *param_2 = *param_1;
    param_2[8] = *param_1;
    param_2[0x10] = *param_1;
    param_2[0x18] = *param_1;
    param_2[0x20] = *param_1;
    param_2[0x28] = *param_1;
    param_2[0x30] = *param_1;
    param_2[0x38] = *param_1;
  }
  else {
    iVar2 = param_1[5] - param_1[3];
    iVar5 = param_1[1];
    iVar1 = param_1[7];
    iVar7 = (param_1[1] + param_1[7]) - (param_1[5] + param_1[3]);
    iVar9 = param_1[5] + param_1[3] + param_1[1] + param_1[7];
    iVar3 = FUN_0064af54(iVar2 + (iVar5 - iVar1),0x61f8,iVar9,iVar2,iVar7);
    iVar4 = FUN_0064af54(iVar2,0x8a8c);
    iVar4 = iVar4 + iVar3;
    iVar7 = FUN_0064af54(iVar7,0xb505);
    iVar5 = FUN_0064af54(iVar5 - iVar1,0x14e7b);
    iVar9 = iVar9 + (iVar5 - iVar3);
    iVar10 = (iVar5 - iVar3) + iVar7;
    iVar7 = iVar7 + iVar4;
    iVar5 = *param_1;
    iVar1 = param_1[4];
    iVar2 = *param_1;
    iVar3 = param_1[4];
    iVar6 = FUN_0064af54(param_1[2] - param_1[6],0xb505);
    iVar11 = param_1[2] + param_1[6] + iVar6;
    iVar8 = (iVar5 + iVar1) - iVar11;
    iVar11 = iVar5 + iVar1 + iVar11;
    iVar5 = (iVar2 - iVar3) - iVar6;
    iVar6 = (iVar2 - iVar3) + iVar6;
    *param_2 = iVar11 + iVar9;
    param_2[8] = iVar6 + iVar10;
    param_2[0x10] = iVar5 + iVar7;
    param_2[0x18] = iVar8 + iVar4;
    param_2[0x20] = iVar8 - iVar4;
    param_2[0x28] = iVar5 - iVar7;
    param_2[0x30] = iVar6 - iVar10;
    param_2[0x38] = iVar11 - iVar9;
  }
  return;
}


// ==== 0x64af54 FUN_0064af54

int FUN_0064af54(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)((longlong)param_1 * (longlong)param_2);
  return (uVar1 >> 0x10) +
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) * 0x10000 +
         (uint)((uVar1 >> 0xf & 1) != 0);
}


// ==== 0x64af67 FUN_0064af67

void FUN_0064af67(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = param_1[5] - param_1[3];
  iVar5 = param_1[1];
  iVar1 = param_1[7];
  iVar2 = (param_1[1] + param_1[7]) - (param_1[5] + param_1[3]);
  iVar8 = param_1[5] + param_1[3] + param_1[1] + param_1[7];
  iVar3 = FUN_0064af54(iVar11 + (iVar5 - iVar1),0x61f8,iVar8,iVar11,iVar2);
  iVar11 = FUN_0064af54(iVar11,0x8a8c);
  iVar11 = iVar11 + iVar3;
  iVar4 = FUN_0064af54(iVar2,0xb505);
  iVar5 = FUN_0064af54(iVar5 - iVar1,0x14e7b);
  iVar8 = iVar8 + (iVar5 - iVar3);
  iVar9 = (iVar5 - iVar3) + iVar4;
  iVar4 = iVar4 + iVar11;
  iVar5 = *param_1;
  iVar1 = param_1[4];
  iVar2 = *param_1;
  iVar3 = param_1[4];
  iVar6 = FUN_0064af54(param_1[2] - param_1[6],0xb505);
  iVar10 = param_1[2] + param_1[6] + iVar6;
  iVar7 = (iVar5 + iVar1) - iVar10;
  iVar10 = iVar5 + iVar1 + iVar10;
  iVar5 = (iVar2 - iVar3) - iVar6;
  iVar6 = (iVar2 - iVar3) + iVar6;
  *param_2 = iVar10 + iVar8;
  param_2[1] = iVar6 + iVar9;
  param_2[2] = iVar5 + iVar4;
  param_2[3] = iVar7 + iVar11;
  param_2[4] = iVar7 - iVar11;
  param_2[5] = iVar5 - iVar4;
  param_2[6] = iVar6 - iVar9;
  param_2[7] = iVar10 - iVar8;
  return;
}


// ==== 0x64b110 FUN_0064b110

int FUN_0064b110(void)

{
  undefined4 *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  DAT_00713b50 = ((int)DAT_00712c38 >> 0x18) * DAT_00712438;
  FUN_0064b2c7(8);
  local_18 = &DAT_00713b54;
  for (local_8 = 0; local_8 < 9; local_8 = local_8 + 1) {
    *local_18 = 0;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    local_18[4] = 0;
    local_18[5] = 0;
    local_18[6] = 0;
    local_18 = local_18 + 7;
  }
  local_c = 1;
  do {
    local_14 = *(uint *)(&DAT_00712c40 + (DAT_00712c38 >> 0x17) * 4);
    local_10 = local_14 & 0xff;
    if (9 < local_10) {
      if ((local_14 & 0x20) == 0) {
        if ((local_14 & 0x10) == 0) {
          FUN_0064b2c7(9);
          local_14 = *(uint *)(&DAT_00712738 + (DAT_00712c38 >> 0x18) * 4);
        }
        else {
          FUN_0064b2c7(6);
          local_14 = *(uint *)(&DAT_00713448 + (DAT_00712c38 >> 0x18) * 4);
        }
        local_10 = local_14 & 0xff;
      }
      else {
        if ((local_14 & 0x10) != 0) {
          FUN_0064b2c7(2);
          return local_c;
        }
        FUN_0064b2c7(6);
        local_14 = DAT_00712c38;
        local_10 = 0x10;
      }
    }
    FUN_0064b2c7(local_10);
    local_c = local_c + ((int)local_14 >> 0x10 & 0x3fU);
    (&DAT_00713b50)[*(int *)(&DAT_006aa8b8 + local_c * 4)] =
         ((int)local_14 >> 0x16) * (&DAT_00712438)[*(int *)(&DAT_006aa8b8 + local_c * 4)];
    local_c = local_c + 1;
  } while( true );
}


// ==== 0x64b2c7 FUN_0064b2c7

void FUN_0064b2c7(int param_1)

{
  int iVar1;
  
  DAT_00712c38 = DAT_00712c38 << ((byte)param_1 & 0x1f);
  DAT_00712030 = DAT_00712030 - param_1;
  if (DAT_00712030 < 0x10) {
    iVar1 = FUN_0064b33b(DAT_00713a48,2);
    DAT_00712c38 = DAT_00712c38 | iVar1 << (0x10U - (char)DAT_00712030 & 0x1f);
    DAT_00712030 = DAT_00712030 + 0x10;
    DAT_00713a48 = DAT_00713a48 + 2;
  }
  return;
}


// ==== 0x64b33b FUN_0064b33b

uint FUN_0064b33b(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = (uint)(byte)*param_1;
  }
  else if (param_2 == 2) {
    uVar1 = (uint)(ushort)*param_1;
  }
  else if (param_2 == 3) {
    uVar1 = *param_1 & 0xffffff;
  }
  else if (param_2 == 4) {
    uVar1 = *param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x64b380 FUN_0064b380

void __thiscall FUN_0064b380(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 == (int *)*param_1) {
    *param_1 = *(int *)*param_1;
  }
  piVar1 = (int *)param_2[1];
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar1;
  }
  return;
}


// ==== 0x64b4c0 FUN_0064b4c0

void __thiscall FUN_0064b4c0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])(param_2,puVar1[3]);
  }
  return;
}


// ==== 0x64b500 FUN_0064b500

undefined4 FUN_0064b500(undefined4 param_1)

{
  DAT_00713c54 = param_1;
  return 0;
}


// ==== 0x64b510 Csis::System::GetAllocator

/* [canon] audio high (ghidra) docs/re/sound.md */

uint Csis__System__GetAllocator(int *param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00713c54 != 0;
  *param_1 = DAT_00713c54;
  return bVar1 - 1 & 0xfffffffa;
}


// ==== 0x64b530 FUN_0064b530

undefined4 FUN_0064b530(void)

{
  DAT_00713c50 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  DAT_00713c60 = 0;
  DAT_00713c58 = 1;
  return 0;
}


// ==== 0x64b560 FUN_0064b560

undefined4 FUN_0064b560(void)

{
  CloseHandle(DAT_00713c50);
  DAT_00713c58 = 0;
  return 0;
}


// ==== 0x64b580 Mutex::Lock

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 Mutex__Lock(void)

{
  WaitForSingleObject(DAT_00713c50,0xffffffff);
  return 0;
}


// ==== 0x64b5a0 Mutex::Unlock

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 Mutex__Unlock(void)

{
  ReleaseMutex(DAT_00713c50);
  return 0;
}


// ==== 0x64b5c0 FUN_0064b5c0

undefined4 FUN_0064b5c0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  *(int *)(param_1 + 0x14) = param_1 + 0x28;
  iVar4 = param_1 + 0x28 + (uint)*(ushort *)(param_1 + 10) * 0xc;
  *(int *)(param_1 + 0x18) = iVar4;
  sVar3 = DAT_00713c5c;
  iVar5 = 0;
  *(uint *)(param_1 + 0x1c) = iVar4 + (uint)*(ushort *)(param_1 + 0xc) * 0xc;
  if (*(ushort *)(param_1 + 10) != 0) {
    iVar4 = 0;
    do {
      sVar3 = sVar3 + 1;
      *(int *)(iVar4 + 4 + *(int *)(param_1 + 0x14)) =
           *(int *)(iVar4 + 4 + *(int *)(param_1 + 0x14)) + param_1;
      if (sVar3 < 0) {
        sVar3 = 1;
      }
      *(short *)(iVar4 + 10 + *(int *)(param_1 + 0x14)) = sVar3;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc;
      DAT_00713c5c = sVar3;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 10));
  }
  iVar4 = 0;
  if (*(short *)(param_1 + 0xc) != 0) {
    iVar5 = 0;
    do {
      sVar3 = sVar3 + 1;
      *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar5) =
           *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar5) + param_1;
      if (sVar3 < 0) {
        sVar3 = 1;
      }
      *(short *)(*(int *)(param_1 + 0x18) + 10 + iVar5) = sVar3;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xc;
      DAT_00713c5c = sVar3;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0xc));
  }
  iVar4 = 0;
  if (*(short *)(param_1 + 0xe) != 0) {
    iVar5 = 0;
    do {
      sVar3 = sVar3 + 1;
      *(int *)(iVar5 + 8 + *(int *)(param_1 + 0x1c)) =
           *(int *)(iVar5 + 8 + *(int *)(param_1 + 0x1c)) + param_1;
      if (sVar3 < 0) {
        sVar3 = 1;
      }
      *(short *)(iVar5 + 0xe + *(int *)(param_1 + 0x1c)) = sVar3;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
      DAT_00713c5c = sVar3;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0xe));
  }
  piVar2 = (int *)(param_1 + 0x20);
  *piVar2 = (int)DAT_00713c60;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (DAT_00713c60 != (int *)0x0) {
    puVar1 = (undefined4 *)((int)DAT_00713c60 + 4);
    DAT_00713c60 = piVar2;
    *puVar1 = piVar2;
    piVar2 = DAT_00713c60;
  }
  DAT_00713c60 = piVar2;
  return 0;
}


// ==== 0x64b6e0 FUN_0064b6e0

undefined4 FUN_0064b6e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(param_1 + 10);
  if (uVar4 != 0) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x14) + 8);
    do {
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0xc);
  if (uVar4 != 0) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x18) + 8);
    do {
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0xe);
  if (uVar4 != 0) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc);
    do {
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 4;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  piVar1 = (int *)(param_1 + 0x20);
  if (piVar1 == DAT_00713c60) {
    DAT_00713c60 = (int *)*DAT_00713c60;
  }
  piVar2 = *(int **)(param_1 + 0x24);
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar1;
  }
  if (*piVar1 != 0) {
    *(int **)(*piVar1 + 4) = piVar2;
  }
  return 0;
}


// ==== 0x64b7d0 Csis::Class::GetRefCount

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall Csis__Class__GetRefCount(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 4);
  return 0;
}


// ==== 0x64b810 Csis::Class::SetMemberDataFast

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 __thiscall Csis__Class__SetMemberDataFast(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])(param_2,puVar1[3]);
  }
  return 0;
}


// ==== 0x64b840 FUN_0064b840

undefined4 __thiscall FUN_0064b840(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = iVar1;
  param_2[1] = 0;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *(int **)(param_1 + 0xc) = param_2;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return 0;
}


// ==== 0x64b870 FUN_0064b870

undefined4 __thiscall FUN_0064b870(int param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 == *(int **)(param_1 + 0xc)) {
    *(int *)(param_1 + 0xc) = **(int **)(param_1 + 0xc);
  }
  piVar1 = (int *)param_2[1];
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar1;
  }
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)(*DAT_00713c54 + 4))(param_1);
  }
  return 0;
}


// ==== 0x64b8b0 FUN_0064b8b0

undefined4 __thiscall FUN_0064b8b0(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *param_2 = iVar1;
  param_2[1] = 0;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *(int **)(param_1 + 8) = param_2;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return 0;
}


// ==== 0x64b8e0 FUN_0064b8e0

undefined4 __thiscall FUN_0064b8e0(int param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 == *(int **)(param_1 + 8)) {
    *(int *)(param_1 + 8) = **(int **)(param_1 + 8);
  }
  piVar1 = (int *)param_2[1];
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar1;
  }
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)(*DAT_00713c54 + 4))(param_1);
  }
  return 0;
}


// ==== 0x64b920 FUN_0064b920

void __thiscall FUN_0064b920(undefined4 param_1,undefined4 param_2)

{
  Csis__ClassHandle__SetFast(param_1,param_2,0,0x14,10);
  return;
}


// ==== 0x64b970 FUN_0064b970

void __thiscall FUN_0064b970(undefined4 param_1,undefined4 param_2)

{
  Csis__ClassHandle__SetFast(param_1,param_2,0,0x18,0xc);
  return;
}


// ==== 0x64b9c0 FUN_0064b9c0

void __thiscall FUN_0064b9c0(undefined4 param_1,undefined4 param_2)

{
  FUN_0064c490(param_1,param_2,0,0x1c,0xe);
  return;
}


// ==== 0x64ba10 FUN_0064ba10

int FUN_0064ba10(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      (*(code *)piVar2[2])(param_2,piVar2[3]);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    return 0;
  }
  return -4;
}


// ==== 0x64ba70 FUN_0064ba70

int FUN_0064ba70(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  iVar1 = *piVar2;
  *param_2 = iVar1;
  param_2[1] = 0;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *piVar2 = (int)param_2;
  return 0;
}


// ==== 0x64bac0 FUN_0064bac0

int FUN_0064bac0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  if (param_2 == (int *)*piVar2) {
    *piVar2 = *(int *)*piVar2;
  }
  piVar2 = (int *)param_2[1];
  if (piVar2 != (int *)0x0) {
    *piVar2 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar2;
  }
  return 0;
}


// ==== 0x64bb20 Csis::Class::CreateInstanceFast

/* [canon] audio high (ghidra) docs/re/sound.md */

int Csis__Class__CreateInstanceFast(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_retaddr;
  
  *param_3 = 0;
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    return -6;
  }
  if (iVar1 != puVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  piVar3 = (int *)(**(code **)*DAT_00713c54)(0x10,4,0xffffffff);
  if (piVar3 != (int *)0x0) {
    *piVar3 = (int)puVar2;
    puVar2 = (undefined4 *)*puVar2;
    piVar3[1] = 1;
    piVar3[2] = 0;
    piVar3[3] = 0;
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      (*(code *)puVar2[2])(piVar3,unaff_ESI,puVar2[3]);
    }
    FUN_0064b4c0(unaff_ESI);
    *unaff_retaddr = piVar3;
    return 0;
  }
  return -1;
}


// ==== 0x64bbd0 FUN_0064bbd0

undefined4 __fastcall FUN_0064bbd0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  WaitForSingleObject(DAT_00713c50,0xffffffff);
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  while (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar3;
    (*(code *)puVar3[2])(param_1,puVar3[3]);
    puVar3 = puVar2;
  }
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)(*DAT_00713c54 + 4))(param_1);
  }
  ReleaseMutex(DAT_00713c50);
  return 0;
}


// ==== 0x64bc30 FUN_0064bc30

undefined4 __thiscall FUN_0064bc30(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  WaitForSingleObject(DAT_00713c50,0xffffffff);
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])(param_2,puVar1[3]);
  }
  ReleaseMutex(DAT_00713c50);
  return 0;
}


// ==== 0x64bc80 FUN_0064bc80

int FUN_0064bc80(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  iVar1 = *piVar2;
  *param_2 = iVar1;
  param_2[1] = 0;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *piVar2 = (int)param_2;
  return 0;
}


// ==== 0x64bcd0 FUN_0064bcd0

int FUN_0064bcd0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[2]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  if (param_2 == (int *)*piVar2) {
    *piVar2 = *(int *)*piVar2;
  }
  piVar2 = (int *)param_2[1];
  if (piVar2 != (int *)0x0) {
    *piVar2 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar2;
  }
  return 0;
}


// ==== 0x64be90 FUN_0064be90

int FUN_0064be90(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    return -6;
  }
  if (iVar1 != puVar2[3]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  if (*param_2 != puVar2[1]) {
    puVar3 = (undefined4 *)*puVar2;
    puVar2[1] = *param_2;
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      (*(code *)puVar3[2])(puVar2 + 1,puVar3[3]);
    }
  }
  return 0;
}


// ==== 0x64bf00 FUN_0064bf00

int FUN_0064bf00(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[3]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  iVar1 = *piVar2;
  *param_2 = iVar1;
  param_2[1] = 0;
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  iVar1 = param_2[3];
  *piVar2 = (int)param_2;
  (*(code *)param_2[2])(piVar2 + 1,iVar1);
  return 0;
}


// ==== 0x64bf60 FUN_0064bf60

int FUN_0064bf60(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -6;
  }
  if (iVar1 != piVar2[3]) {
    param_1[1] = -3;
    *param_1 = 0;
    return -3;
  }
  if (param_2 == (int *)*piVar2) {
    *piVar2 = *(int *)*piVar2;
  }
  piVar2 = (int *)param_2[1];
  if (piVar2 != (int *)0x0) {
    *piVar2 = *param_2;
  }
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = piVar2;
  }
  return 0;
}


// ==== 0x64c000 Csis::ClassHandle::Set

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall Csis__ClassHandle__Set(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  WaitForSingleObject(DAT_00713c50,0xffffffff);
  uVar1 = Csis__ClassHandle__SetFast(param_1,param_2,0,0x18,0xc);
  ReleaseMutex(DAT_00713c50);
  return uVar1;
}


// ==== 0x64c1a0 Csis::Class::CreateInstance

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 Csis__Class__CreateInstance(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  WaitForSingleObject(DAT_00713c50,0xffffffff);
  uVar1 = Csis__Class__CreateInstanceFast(param_1,param_2,param_3);
  ReleaseMutex(DAT_00713c50);
  return uVar1;
}


// ==== 0x64c380 Csis::ClassHandle::SetFast

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4
Csis__ClassHandle__SetFast
          (int *param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  bVar3 = false;
  do {
    if (DAT_00713c60 != (int *)0x0) {
      piVar7 = DAT_00713c60;
      do {
        iVar2 = *(int *)((int)piVar7 + param_4 + -0x20);
        uVar4 = (uint)*(ushort *)((int)piVar7 + param_5 + -0x20);
        if ((((short)piVar7[-4] == *(short *)(param_2 + 1)) || (bVar3)) && (iVar8 = 0, uVar4 != 0))
        {
          puVar10 = (undefined4 *)(iVar2 + 4);
          do {
            if (*(short *)((int)param_2 + 6) == *(short *)(puVar10 + 1)) {
              pbVar9 = (byte *)*puVar10;
              pbVar5 = (byte *)*param_2;
              do {
                bVar1 = *pbVar5;
                bVar11 = bVar1 < *pbVar9;
                if (bVar1 != *pbVar9) {
LAB_0064c424:
                  iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                  goto LAB_0064c429;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar5[1];
                bVar11 = bVar1 < pbVar9[1];
                if (bVar1 != pbVar9[1]) goto LAB_0064c424;
                pbVar5 = pbVar5 + 2;
                pbVar9 = pbVar9 + 2;
              } while (bVar1 != 0);
              iVar6 = 0;
LAB_0064c429:
              if (iVar6 == 0) {
                iVar2 = iVar2 + iVar8 * 0xc;
                *param_1 = iVar2;
                param_1[1] = *(int *)(iVar2 + 8);
                return 0;
              }
            }
            iVar8 = iVar8 + 1;
            puVar10 = puVar10 + 3;
          } while (iVar8 < (int)uVar4);
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
    }
    if (bVar3) {
      return 0xfffffffb;
    }
    bVar3 = true;
  } while( true );
}


// ==== 0x64c490 FUN_0064c490

undefined4 FUN_0064c490(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  bVar3 = false;
  do {
    if (DAT_00713c60 != (int *)0x0) {
      piVar7 = DAT_00713c60;
      do {
        iVar2 = *(int *)((int)piVar7 + param_4 + -0x20);
        uVar4 = (uint)*(ushort *)((int)piVar7 + param_5 + -0x20);
        if ((((short)piVar7[-4] == *(short *)(param_2 + 1)) || (bVar3)) && (iVar8 = 0, uVar4 != 0))
        {
          puVar10 = (undefined4 *)(iVar2 + 8);
          do {
            if (*(short *)((int)param_2 + 6) == *(short *)(puVar10 + 1)) {
              pbVar9 = (byte *)*puVar10;
              pbVar5 = (byte *)*param_2;
              do {
                bVar1 = *pbVar5;
                bVar11 = bVar1 < *pbVar9;
                if (bVar1 != *pbVar9) {
LAB_0064c534:
                  iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                  goto LAB_0064c539;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar5[1];
                bVar11 = bVar1 < pbVar9[1];
                if (bVar1 != pbVar9[1]) goto LAB_0064c534;
                pbVar5 = pbVar5 + 2;
                pbVar9 = pbVar9 + 2;
              } while (bVar1 != 0);
              iVar6 = 0;
LAB_0064c539:
              if (iVar6 == 0) {
                iVar6 = *(int *)(iVar2 + 0xc + iVar8 * 0x10);
                *param_1 = iVar2 + iVar8 * 0x10;
                param_1[1] = iVar6;
                return 0;
              }
            }
            iVar8 = iVar8 + 1;
            puVar10 = puVar10 + 4;
          } while (iVar8 < (int)uVar4);
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
    }
    if (bVar3) {
      return 0xfffffffb;
    }
    bVar3 = true;
  } while( true );
}


// ==== 0x64c5a0 FUN_0064c5a0

void FUN_0064c5a0(undefined4 param_1)

{
  (&DAT_00713f08)[DAT_00713ee7] = param_1;
  DAT_00713ee7 = DAT_00713ee7 + '\x01';
  return;
}


// ==== 0x64c5c0 FUN_0064c5c0

void FUN_0064c5c0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_00713ee7) {
    while ((&DAT_00713f08)[iVar1] != param_1) {
      iVar1 = iVar1 + 1;
      if (DAT_00713ee7 <= iVar1) {
        return;
      }
    }
    DAT_00713ee7 = DAT_00713ee7 + -1;
    if (iVar1 < DAT_00713ee7) {
      do {
        (&DAT_00713f08)[iVar1] = (&DAT_00713f0c)[iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_00713ee7);
    }
  }
  return;
}


// ==== 0x64c620 FUN_0064c620

void FUN_0064c620(void)

{
  int iVar1;
  
  if ((DAT_00713ee4 != '\0') && (iVar1 = 0, '\0' < DAT_00713ee7)) {
    do {
      (*(code *)(&DAT_00713f08)[iVar1])();
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00713ee7);
  }
  return;
}


// ==== 0x64c650 FUN_0064c650

undefined4 FUN_0064c650(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return uVar1;
}


// ==== 0x64c660 FUN_0064c660

undefined4 FUN_0064c660(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}


// ==== 0x64c670 FUN_0064c670

undefined4 FUN_0064c670(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}


// ==== 0x64c680 FUN_0064c680

undefined4 FUN_0064c680(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}


// ==== 0x64c690 FUN_0064c690

undefined4 FUN_0064c690(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[3] != 0) {
    piVar3 = (int *)param_1[1];
    piVar2 = *(int **)(*param_1 + 0x38);
    if (piVar3 == piVar2) {
      *(int *)(*param_1 + 0x38) = *piVar2;
    }
    if ((int *)piVar3[1] != (int *)0x0) {
      *(int *)piVar3[1] = *piVar3;
    }
    if (*piVar3 != 0) {
      *(int *)(*piVar3 + 4) = piVar3[1];
    }
    iVar5 = param_1[1];
    piVar3 = (int *)(iVar5 + 8);
    if (piVar3 == DAT_00713c70) {
      DAT_00713c70 = (int *)*DAT_00713c70;
    }
    if (*(int **)(iVar5 + 0xc) != (int *)0x0) {
      **(int **)(iVar5 + 0xc) = *piVar3;
    }
    if (*piVar3 != 0) {
      *(undefined4 *)(*piVar3 + 4) = *(undefined4 *)(iVar5 + 0xc);
    }
    iVar4 = param_1[1];
    iVar5 = iVar4 + 0x18;
    if (*(char *)(*param_1 + 0x25) != '\0') {
      FUN_0064b870(iVar5);
      iVar5 = iVar4 + 0x2c;
    }
    iVar4 = 0;
    if (*(short *)(*param_1 + 0x20) != 0) {
      do {
        FUN_0064bf60(iVar5,iVar5 + 8);
        iVar5 = iVar5 + 0x1c;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(ushort *)(*param_1 + 0x20));
    }
    if (*(char *)(*param_1 + 0x26) != '\0') {
      FUN_0064b8e0(iVar5);
      iVar5 = iVar5 + 0x14 + (uint)*(byte *)(iVar5 + 0x10) * 4;
    }
    iVar4 = 0;
    if (*(short *)(*param_1 + 0x22) != 0) {
      do {
        FUN_0064bac0(iVar5,iVar5 + 8);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x1c + (uint)*(byte *)(iVar5 + 0x18) * 4;
      } while (iVar4 < (int)(uint)*(ushort *)(*param_1 + 0x22));
    }
    iVar5 = 0;
    piVar3 = (int *)(*param_1 + 0x3c);
    if (*(char *)(*param_1 + 0x24) != '\0') {
      do {
        iVar4 = *piVar3;
        cVar1 = *(char *)(iVar4 + 0x10 + param_1[1]);
        piVar3 = piVar3 + 1;
        if (-1 < cVar1) {
          (**(code **)(&DAT_006e9aa8 + cVar1 * 4))(iVar4 + param_1[1]);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)*(byte *)(*param_1 + 0x24));
    }
    iVar5 = 0;
    if (*(char *)(*param_1 + 0x27) != '\0') {
      do {
        iVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        if (*(int *)(iVar4 + param_1[1] + 8) != 0) {
          FUN_0064bbd0();
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)*(byte *)(*param_1 + 0x27));
    }
    *(short *)(*param_1 + 0x1c) = *(short *)(*param_1 + 0x1c) + -1;
    FUN_006510d0(param_1[1]);
  }
  return 0;
}


// ==== 0x64c800 FUN_0064c800

undefined4 FUN_0064c800(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  if (*(char *)(param_1 + 8) == '\0') {
    piVar4 = (int *)(param_1 + 0xc);
  }
  else {
    iVar5 = 0;
    piVar4 = (int *)(param_1 + 0xc + (uint)*(byte *)(param_1 + 9) * 8);
    piVar6 = piVar4;
    if (*(byte *)(param_1 + 9) != 0) {
      do {
        piVar6 = piVar6 + 1;
        iVar3 = *(int *)(param_1 + 0xc + iVar5 * 8);
        iVar1 = *piVar6;
        iVar2 = *(int *)(param_1 + 0x10 + iVar5 * 8);
        if ((iVar3 <= iVar1) && (iVar3 = iVar1, iVar2 < iVar1)) {
          iVar3 = iVar2;
        }
        *piVar6 = iVar3;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)*(byte *)(param_1 + 9));
    }
  }
  if (*piVar4 != 0) {
    FUN_0064ba10(param_1,piVar4 + 1);
  }
  return 0;
}


// ==== 0x64c870 FUN_0064c870

int * FUN_0064c870(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  
  piVar9 = param_1;
  cVar1 = (char)param_1[3];
  piVar5 = (int *)0x0;
  if (cVar1 == '\0') {
    piVar7 = param_1 + 4;
  }
  else {
    piVar5 = param_1 + 4;
    piVar7 = piVar5 + (uint)*(byte *)((int)param_1 + 0xd) * 2;
  }
  if (piVar7[1] == 0) {
    piVar6 = param_1 + 2;
    piVar8 = piVar6;
    if (*piVar7 == 0) {
      if (param_1[2] != 0) {
        if ((cVar1 != '\0') && (iVar3 = 0, *(char *)((int)param_1 + 0xd) != '\0')) {
          piVar9 = piVar7 + 2;
          do {
            iVar4 = piVar5[iVar3 * 2];
            iVar2 = *piVar9;
            if ((iVar4 <= iVar2) && (iVar4 = iVar2, piVar5[iVar3 * 2 + 1] < iVar2)) {
              iVar4 = piVar5[iVar3 * 2 + 1];
            }
            *piVar9 = iVar4;
            iVar3 = iVar3 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar3 < (int)(uint)*(byte *)((int)param_1 + 0xd));
        }
        param_1 = piVar6;
        Csis__Class__SetMemberDataFast(piVar7 + 2);
        piVar6 = param_1;
        piVar8 = param_1;
      }
    }
    else if (param_1[2] == 0) {
      if ((cVar1 != '\0') && (iVar3 = 0, *(char *)((int)param_1 + 0xd) != '\0')) {
        piVar8 = piVar7 + 2;
        do {
          iVar4 = piVar5[iVar3 * 2];
          iVar2 = *piVar8;
          if ((iVar4 <= iVar2) && (iVar4 = iVar2, piVar5[iVar3 * 2 + 1] < iVar2)) {
            iVar4 = piVar5[iVar3 * 2 + 1];
          }
          *piVar8 = iVar4;
          iVar3 = iVar3 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar3 < (int)(uint)*(byte *)((int)param_1 + 0xd));
      }
      param_1 = piVar6;
      iVar3 = Csis__Class__CreateInstanceFast(piVar9,piVar7 + 2,piVar6);
      piVar6 = param_1;
      piVar8 = param_1;
      if (iVar3 < 0) {
        *param_1 = 0;
      }
    }
  }
  else {
    piVar6 = param_1 + 2;
    piVar8 = param_1;
    if (param_1[2] != 0) {
      FUN_0064bbd0();
      *piVar6 = 0;
      piVar8 = param_1;
    }
  }
  param_1 = piVar8;
  if (*piVar6 == 0) {
    return (int *)0x0;
  }
  Csis__Class__GetRefCount(&param_1);
  return param_1;
}


// ==== 0x64c9b0 FUN_0064c9b0

undefined4 FUN_0064c9b0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x10) != iVar2) {
    piVar1 = (int *)(param_1 + 0xc);
    *(int *)(param_1 + 0x10) = iVar2;
    if (iVar2 < *(int *)(param_1 + 8)) {
      param_1 = *(int *)(param_1 + 8);
      FUN_0064be90(iVar3,&param_1);
      return 0;
    }
    param_1 = *piVar1;
    if (iVar2 <= *piVar1) {
      param_1 = iVar2;
    }
    FUN_0064be90(iVar3,&param_1);
  }
  return 0;
}


// ==== 0x64ca00 FUN_0064ca00

int FUN_0064ca00(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[5];
  iVar1 = *param_1;
  if ((iVar2 < iVar1) || (param_1[1] < iVar2)) {
    if (0 < param_1[4]) {
      iVar2 = param_1[2] + (int)(char)param_1[3];
      param_1[2] = iVar2;
      if (param_1[1] < iVar2) {
        param_1[2] = iVar1;
        return iVar1;
      }
      if (iVar2 < iVar1) {
        param_1[2] = param_1[1];
      }
    }
    iVar2 = param_1[2];
  }
  return iVar2;
}


// ==== 0x64ca50 FUN_0064ca50

int FUN_0064ca50(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1[3] == 0) {
    return param_1[2];
  }
  uVar1 = iSNDrandom();
  iVar2 = *param_1 + uVar1 % (uint)param_1[1];
  param_1[2] = iVar2;
  return iVar2;
}


// ==== 0x64ca80 FUN_0064ca80

int FUN_0064ca80(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)((uint)*param_1 + (int)param_1) == 0) {
    return *(int *)(param_1 + 6);
  }
  uVar3 = (uint)param_1[4];
  uVar1 = iSNDrandom();
  iVar2 = uVar1 % (((uint)param_1[5] - (int)*(char *)((int)param_1 + 3)) - uVar3) + uVar3;
  if ((char)param_1[1] == '\x01') {
    *(uint *)(param_1 + 6) = (uint)*(byte *)(iVar2 + 0x10 + (int)param_1);
    *(undefined1 *)(iVar2 + 0x10 + (int)param_1) = *(undefined1 *)(uVar3 + 0x10 + (int)param_1);
    *(char *)(param_1[4] + 0x10 + (int)param_1) = (char)param_1[6];
  }
  else {
    *(uint *)(param_1 + 6) = (uint)param_1[iVar2 + 8];
    param_1[iVar2 + 8] = param_1[uVar3 + 8];
    param_1[param_1[4] + 8] = param_1[6];
  }
  iVar2 = *(int *)(param_1 + 6);
  param_1[4] = param_1[4] + 1;
  *(int *)(param_1 + 6) = iVar2 + *(int *)(param_1 + 2);
  iVar2 = iVar2 + *(int *)(param_1 + 2);
  if (param_1[5] <= param_1[4]) {
    *(undefined1 *)((int)param_1 + 3) = 1;
    param_1[4] = 0;
    return iVar2;
  }
  *(undefined1 *)((int)param_1 + 3) = 0;
  return iVar2;
}


// ==== 0x64cb30 FUN_0064cb30

int FUN_0064cb30(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[4] != 0) {
    uVar3 = 0;
    uVar1 = iSNDrandom();
    iVar2 = 0;
    if (0 < param_1[2]) {
      while (uVar3 = uVar3 + (int)*(char *)(*param_1 + 0x10 + iVar2), uVar3 <= uVar1 % 100) {
        iVar2 = iVar2 + 1;
        if (param_1[2] <= iVar2) {
          return param_1[3];
        }
      }
      param_1[3] = param_1[1] + iVar2;
    }
  }
  return param_1[3];
}


// ==== 0x64cb90 FUN_0064cb90

undefined4 FUN_0064cb90(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[5];
  if ((iVar1 < *param_1) || (param_1[1] < iVar1)) {
    if ((param_1[2] <= iVar1) && (iVar1 <= param_1[3])) {
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  else if ((char)param_1[4] == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)((int)param_1 + 0x11) = 1;
    return 1;
  }
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  return 0;
}


// ==== 0x64cbd0 FUN_0064cbd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0064cbd0(float *param_1)

{
  if (param_1[2] == 0.0) {
    if (*param_1 < 0.0) goto LAB_0064cc17;
  }
  else {
    *param_1 = 0.0;
  }
  if ((float)(int)param_1[3] < *param_1 != ((float)(int)param_1[3] == *param_1)) {
    *param_1 = -1.0;
    *(undefined1 *)(param_1 + 1) = 1;
    return 1;
  }
  *param_1 = _DAT_00713ca0 + *param_1;
LAB_0064cc17:
  *(undefined1 *)(param_1 + 1) = 0;
  return 0;
}


// ==== 0x64cc20 FUN_0064cc20

undefined4 FUN_0064cc20(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((char)param_1[1] != '\0') {
    while (*(int *)((int)param_1 + iVar1 * 4 + (uint)*param_1) == 0) {
      iVar1 = iVar1 + 1;
      if ((int)(uint)(byte)param_1[1] <= iVar1) {
        return *(undefined4 *)(param_1 + 2);
      }
    }
    *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_1 + iVar1 * 2 + 4);
  }
  return *(undefined4 *)(param_1 + 2);
}


// ==== 0x64cc60 FUN_0064cc60

undefined4 FUN_0064cc60(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1;
  iVar2 = 0;
  if (bVar1 != 0) {
    do {
      param_1 = param_1 + 4;
      if (*(int *)param_1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)bVar1);
  }
  return 0;
}


// ==== 0x64cc90 FUN_0064cc90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064cc90(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x18 + (uint)*(byte *)(param_1 + 3) * 8);
  *(float *)(param_1 + 4) = fVar1;
  fVar1 = (*(float *)(param_1 + 0x1c + (uint)*(byte *)(param_1 + 3) * 8) - *(float *)(param_1 + 0xc)
          ) / fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 8) = fVar1 * _DAT_00713ca0;
  return;
}


// ==== 0x64ccc0 FUN_0064ccc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0064ccc0(ushort *param_1)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  ushort *extraout_EDX;
  undefined1 *puVar4;
  
  iVar3 = *(int *)((uint)*param_1 + (int)param_1);
  puVar4 = (undefined1 *)((uint)*param_1 + (int)param_1);
  if ((iVar3 == 1) && ((char)param_1[1] == '\0')) {
    *(undefined1 *)((int)param_1 + 3) = 0;
    *(float *)(param_1 + 6) = *(float *)(param_1 + 10);
    *(float *)(param_1 + 2) = *(float *)(param_1 + 0xc);
    fVar1 = (*(float *)(param_1 + 0xe) - *(float *)(param_1 + 10)) / *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 4) = fVar1;
    *(float *)(param_1 + 4) = fVar1 * _DAT_00713ca0;
    goto LAB_0064cda7;
  }
  if (((iVar3 == 3) && ((char)param_1[1] != '\x03')) &&
     ((short)(ushort)*(byte *)((int)param_1 + 3) < (short)param_1[9])) {
    bVar2 = (byte)param_1[9];
    *(byte *)((int)param_1 + 3) = bVar2;
    fVar1 = *(float *)(param_1 + (uint)bVar2 * 4 + 0xc);
    *(float *)(param_1 + 2) = fVar1;
    fVar1 = (*(float *)(param_1 + (uint)bVar2 * 4 + 0xe) - *(float *)(param_1 + 6)) / fVar1;
    *(float *)(param_1 + 4) = fVar1;
    *(float *)(param_1 + 4) = fVar1 * _DAT_00713ca0;
    goto LAB_0064cda7;
  }
  if ((iVar3 == 1) || (iVar3 == 3)) {
    bVar2 = *(byte *)((int)param_1 + 3);
    if ((byte)param_1[8] <= bVar2) goto LAB_0064cd9a;
    fVar1 = *(float *)(param_1 + 2) - _DAT_00713ca0;
    *(float *)(param_1 + 2) = fVar1;
    if (fVar1 < 0.0 == (fVar1 == 0.0)) {
      *(float *)(param_1 + 6) = *(float *)(param_1 + 4) + *(float *)(param_1 + 6);
      goto LAB_0064cda7;
    }
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_1 + (uint)bVar2 * 4 + 0xe);
    *(byte *)((int)param_1 + 3) = bVar2 + 1;
    if ((byte)(bVar2 + 1) < (byte)param_1[8]) {
      FUN_0064cc90(param_1);
      param_1 = extraout_EDX;
      goto LAB_0064cda7;
    }
  }
  else {
LAB_0064cd9a:
    if (iVar3 == 2) goto LAB_0064cda7;
  }
  param_1[6] = 0;
  param_1[7] = 0;
LAB_0064cda7:
  *(undefined1 *)(param_1 + 1) = *puVar4;
  return (int)ROUND(*(float *)(param_1 + 6));
}


// ==== 0x64cdd0 FUN_0064cdd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0064cdd0(undefined4 *param_1)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1[3];
  if (iVar8 != param_1[1]) {
    pcVar3 = (char *)*param_1;
    param_1[1] = iVar8;
    iVar4 = *(int *)(pcVar3 + 4);
    iVar7 = iVar4;
    if ((iVar4 <= iVar8) && (iVar7 = iVar8, *(int *)(pcVar3 + 8) < iVar8)) {
      iVar7 = *(int *)(pcVar3 + 8);
    }
    iVar7 = iVar7 - iVar4;
    if (*(int *)(pcVar3 + 0xc) == 0x3f800000) {
      if (*pcVar3 == '\x02') {
        sVar2 = *(short *)(pcVar3 + iVar7 * 2 + 0x10);
        param_1[2] = (int)sVar2;
        return (int)sVar2;
      }
      if (*pcVar3 != '\x01') {
        iVar8 = *(int *)(pcVar3 + iVar7 * 4 + 0x10);
        param_1[2] = iVar8;
        return iVar8;
      }
      cVar1 = pcVar3[iVar7 + 0x10];
      param_1[2] = (int)cVar1;
      return (int)cVar1;
    }
    iVar4 = (int)ROUND((float)iVar7 * *(float *)(pcVar3 + 0xc) - _K_HALF);
    iVar8 = iVar4 + 1;
    if ((int)(uint)*(ushort *)(pcVar3 + 2) <= iVar8) {
      iVar8 = *(ushort *)(pcVar3 + 2) - 1;
    }
    if (*pcVar3 == '\x02') {
      fVar5 = (float)(int)*(short *)(pcVar3 + iVar4 * 2 + 0x10);
      fVar6 = (float)(int)*(short *)(pcVar3 + iVar8 * 2 + 0x10);
    }
    else if (*pcVar3 == '\x01') {
      fVar5 = (float)(int)pcVar3[iVar4 + 0x10];
      fVar6 = (float)(int)pcVar3[iVar8 + 0x10];
    }
    else {
      fVar5 = (float)*(int *)(pcVar3 + iVar4 * 4 + 0x10);
      fVar6 = (float)*(int *)(pcVar3 + iVar8 * 4 + 0x10);
    }
    param_1[2] = (int)ROUND((fVar6 - fVar5) *
                            ((float)iVar7 * *(float *)(pcVar3 + 0xc) - (float)iVar4) + fVar5);
  }
  return param_1[2];
}


// ==== 0x64cef0 FUN_0064cef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0064cef0(ushort *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(*param_1 + 4 + (int)param_1);
  puVar3 = (undefined4 *)((uint)*param_1 + (int)param_1);
  if (iVar4 != *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 4) = iVar4;
    if ((int)puVar3[1] < 0) {
      puVar3[1] = 0;
    }
    iVar4 = (int)ROUND((float)(int)puVar3[1] / _DAT_00713ca0);
    if ((int)(uint)param_1[1] <= iVar4) {
      iVar4 = param_1[1] - 1;
    }
    param_1[2] = param_1[3] + (short)iVar4;
  }
  uVar1 = param_1[1];
  if (uVar1 <= param_1[2]) {
    param_1[2] = param_1[2] - uVar1;
  }
  if (uVar1 <= param_1[3]) {
    param_1[3] = 0;
  }
  *(undefined4 *)(param_1 + (uint)param_1[2] * 2 + 6) = *puVar3;
  uVar2 = *(undefined4 *)(param_1 + (uint)param_1[3] * 2 + 6);
  param_1[2] = param_1[2] + 1;
  param_1[3] = param_1[3] + 1;
  return uVar2;
}


// ==== 0x64cf90 FUN_0064cf90

undefined4 FUN_0064cf90(byte *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((0 < iVar1) && (iVar1 <= (int)(uint)*param_1)) {
    return *(undefined4 *)(param_1 + iVar1 * 4 + 4);
  }
  return 0;
}


// ==== 0x64cfb0 FUN_0064cfb0

undefined4 FUN_0064cfb0(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = param_1 + *(short *)(param_1 + 2) * 4 + 8;
  pbVar1[0] = 0;
  pbVar1[1] = 0;
  pbVar1[2] = 0;
  pbVar1[3] = 0;
  iVar2 = *(int *)(param_1 + 4);
  if ((0 < iVar2) && (iVar2 <= (int)(uint)*param_1)) {
    *(undefined4 *)(param_1 + iVar2 * 4 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_1 + 4);
  }
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== 0x64cff0 FUN_0064cff0

void FUN_0064cff0(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (1 < *param_1) {
    pbVar2 = param_1 + 8;
    iVar3 = *param_1 - 1;
    do {
      if (*(int *)pbVar2 < iVar1) {
        iVar1 = *(int *)pbVar2;
      }
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== 0x64d020 FUN_0064d020

int FUN_0064d020(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_1[1] <= *param_1) {
    iVar1 = param_1[1];
  }
  return iVar1;
}


// ==== 0x64d030 FUN_0064d030

void FUN_0064d030(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (1 < *param_1) {
    pbVar2 = param_1 + 8;
    iVar3 = *param_1 - 1;
    do {
      if (iVar1 < *(int *)pbVar2) {
        iVar1 = *(int *)pbVar2;
      }
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== 0x64d060 FUN_0064d060

int FUN_0064d060(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*param_1 <= param_1[1]) {
    iVar1 = param_1[1];
  }
  return iVar1;
}


// ==== 0x64d070 FUN_0064d070

int FUN_0064d070(byte *param_1)

{
  float fVar1;
  byte *pbVar2;
  int iVar3;
  
  fVar1 = (float)*(int *)(param_1 + 8);
  if (1 < *param_1) {
    pbVar2 = param_1 + 0xc;
    iVar3 = *param_1 - 1;
    do {
      fVar1 = fVar1 * (float)*(int *)pbVar2;
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return (int)ROUND(fVar1 * *(float *)(param_1 + 4));
}


// ==== 0x64d0b0 FUN_0064d0b0

int FUN_0064d0b0(float *param_1)

{
  return (int)ROUND((float)(int)param_1[2] * (float)(int)param_1[1] * *param_1);
}


// ==== 0x64d0d0 FUN_0064d0d0

int FUN_0064d0d0(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (1 < *param_1) {
    pbVar2 = param_1 + 8;
    iVar3 = *param_1 - 1;
    do {
      iVar1 = iVar1 + *(int *)pbVar2;
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}


// ==== 0x64d0f0 FUN_0064d0f0

int FUN_0064d0f0(int *param_1)

{
  return param_1[1] + *param_1;
}


// ==== 0x64d100 FUN_0064d100

int FUN_0064d100(int *param_1)

{
  return *param_1 - param_1[1];
}


// ==== 0x64d110 FUN_0064d110

int FUN_0064d110(int *param_1)

{
  return param_1[1] * *param_1;
}


// ==== 0x64d120 FUN_0064d120

int FUN_0064d120(int *param_1)

{
  if (param_1[1] != 0) {
    return *param_1 / param_1[1];
  }
  return 0;
}


// ==== 0x64d140 FUN_0064d140

int FUN_0064d140(int *param_1)

{
  if (param_1[1] != 0) {
    return *param_1 % param_1[1];
  }
  return 0;
}


// ==== 0x64d160 FUN_0064d160

void FUN_0064d160(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(short *)(param_1 * 0x8c + 0x8a + DAT_00713f48) = (short)param_2;
  SNDPLATFORM_setpitch(param_1);
  return;
}


// ==== 0x64d1a0 FUN_0064d1a0

void FUN_0064d1a0(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  *(short *)(param_1 * 0x8c + 0x6a + DAT_00713f48) = (short)param_2;
  FUN_006512c0();
  return;
}


// ==== 0x64d1e0 FUN_0064d1e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064d1e0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 * 0x8c + DAT_00713f48;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  iVar5 = 0;
  *(float *)(iVar4 + 0x38) = (float)param_2 * 3.051851e-05;
  *(float *)(iVar4 + 0x48) = (float)param_2 * 3.051851e-05 * _DAT_006e9bc8;
  if (*(char *)(iVar4 + 0x23) != '\0') {
    psVar3 = (short *)(iVar4 + 4);
    do {
      sVar1 = *psVar3;
      iVar2 = sVar1 * 0x8c + DAT_00713f48;
      *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar4 + 0x38);
      *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(iVar4 + 0x48);
      Snd__Hal__SetVol__SNDPLATFORM_setvol_((int)sVar1);
      iVar5 = iVar5 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(iVar4 + 0x23));
  }
  return;
}


// ==== 0x64d280 FUN_0064d280

void FUN_0064d280(int param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x8c + DAT_00713f48;
  if (*(char *)(iVar1 + 0x23) == '\x01') {
    *(undefined2 *)(iVar1 + 0x1c) = param_2;
    FUN_006513b0(param_1);
  }
  return;
}


// ==== 0x64d2b0 FUN_0064d2b0

void FUN_0064d2b0(int param_1,int param_2)

{
  if (param_2 < -0x4000) {
    param_2 = -0x4000;
  }
  else if (0x3fff < param_2) {
    param_2 = 0x3fff;
  }
  *(short *)(param_1 * 0x8c + 0x1e + DAT_00713f48) = (short)param_2;
  FUN_006513b0(param_1);
  return;
}


// ==== 0x64d300 FUN_0064d300

void FUN_0064d300(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(char *)(param_1 * 0x8c + 0x61 + DAT_00713f48) = (char)((uint)param_2 >> 8);
  SNDI_calcfxlevel(0,param_1);
  SNDPLATFORM_setfxlevel__map__SNDstop_(param_1,0);
  return;
}


// ==== 0x64d350 FUN_0064d350

void FUN_0064d350(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_006514e0();
    return;
  }
  FUN_006514e0();
  return;
}


// ==== 0x64d380 FUN_0064d380

void FUN_0064d380(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00651510();
    return;
  }
  FUN_00651510();
  return;
}


// ==== 0x64d3b0 FUN_0064d3b0

void FUN_0064d3b0(int param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 * 0x8c + DAT_00713f48;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  iVar4 = 0;
  if (*(char *)(iVar3 + 0x23) != '\0') {
    psVar2 = (short *)(iVar3 + 4);
    do {
      sVar1 = *psVar2;
      *(char *)(sVar1 * 0x8c + 0x5f + DAT_00713f48) = (char)((uint)param_2 >> 8);
      FUN_00651fa0((int)sVar1);
      iVar4 = iVar4 + 1;
      psVar2 = psVar2 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(iVar3 + 0x23));
  }
  return;
}


// ==== 0x64d420 FUN_0064d420

void FUN_0064d420(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    *(undefined2 *)(param_1 + 0xc) = 0xffff;
    return;
  }
  *(short *)(param_1 + 0xc) = (short)param_2;
  return;
}


// ==== 0x64d450 FUN_0064d450

void FUN_0064d450(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    *(undefined2 *)(param_1 + 0xe) = 0xffff;
    return;
  }
  *(short *)(param_1 + 0xe) = (short)param_2;
  return;
}


// ==== 0x64d480 FUN_0064d480

void FUN_0064d480(undefined1 *param_1,int param_2)

{
  if (param_2 < 0) {
    *param_1 = 0;
    return;
  }
  if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *param_1 = (char)((uint)param_2 >> 8);
  return;
}


// ==== 0x64d4b0 FUN_0064d4b0

void FUN_0064d4b0(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 8) = param_2;
  return;
}


// ==== 0x64d4c0 FUN_0064d4c0

void FUN_0064d4c0(int param_1,int param_2)

{
  if (param_2 < -0x4000) {
    param_2 = -0x4000;
  }
  else if (0x3fff < param_2) {
    *(undefined2 *)(param_1 + 10) = 0x3fff;
    return;
  }
  *(short *)(param_1 + 10) = (short)param_2;
  return;
}


// ==== 0x64d4f0 FUN_0064d4f0

void FUN_0064d4f0(int param_1,int param_2)

{
  if (param_2 < 0) {
    *(undefined1 *)(param_1 + 5) = 0;
    return;
  }
  if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(char *)(param_1 + 5) = (char)((uint)param_2 >> 8);
  return;
}


// ==== 0x64d520 FUN_0064d520

void FUN_0064d520(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    *(undefined2 *)(param_1 + 0x14) = 0xffff;
    return;
  }
  *(short *)(param_1 + 0x14) = (short)param_2;
  return;
}


// ==== 0x64d550 FUN_0064d550

void FUN_0064d550(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xffff < param_2) {
    *(undefined2 *)(param_1 + 0x16) = 0xffff;
    return;
  }
  *(short *)(param_1 + 0x16) = (short)param_2;
  return;
}


// ==== 0x64d580 FUN_0064d580

void FUN_0064d580(int param_1,int param_2)

{
  if (param_2 < 0) {
    *(undefined1 *)(param_1 + 4) = 0;
    return;
  }
  if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(char *)(param_1 + 4) = (char)((uint)param_2 >> 8);
  return;
}


// ==== 0x64d5b0 FUN_0064d5b0

void FUN_0064d5b0(int *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined1 auStack_18 [5];
  undefined1 uStack_13;
  
  SNDplaysetdef(auStack_18);
  iVar2 = 0;
  uStack_13 = 0;
  pbVar1 = (byte *)(param_1 + 7);
  if (*(char *)((int)param_1 + 0xe) != '\0') {
    do {
      (*(code *)(&PTR_FUN_006e9a68)[*pbVar1])(auStack_18,*(undefined4 *)(pbVar1 + 8));
      *(undefined4 *)(pbVar1 + 4) = *(undefined4 *)(pbVar1 + 8);
      pbVar1 = pbVar1 + 0xc;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)((int)param_1 + 0xe));
  }
  FUN_00651fd0(*(undefined4 *)(*param_1 + 0x40),*(undefined4 *)(param_2 + 4),auStack_18);
  return;
}


// ==== 0x64d630 FUN_0064d630

int FUN_0064d630(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_4;
  
  uStack_4 = *(undefined4 *)(param_1 + 8);
  if (DAT_00713ee4 != '\0') {
    iVar1 = SNDVOICEI_get__validate_handle____voice_index_(uStack_4);
    if (-1 < iVar1) {
      uStack_4 = 0xffffffff;
      iVar2 = iSNDpatchkey(iVar1,&uStack_4);
      while (iVar2 != 0) {
        FUN_00651f30(uStack_4);
        iVar2 = iSNDpatchkey(iVar1,&uStack_4);
      }
    }
    return iVar1;
  }
  return -10;
}


// ==== 0x64d640 FUN_0064d640

void FUN_0064d640(undefined4 param_1)

{
  SNDvol__map__SNDSYSI_100hzserver_(param_1,0);
  SNDpitchmult(param_1,0);
  return;
}


// ==== 0x64d660 FUN_0064d660

void FUN_0064d660(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0x1000;
  uVar5 = 0x7fff;
  iVar2 = SNDVOICEI_get__validate_handle____voice_index_(*(undefined4 *)(param_1 + 8));
  if (iVar2 < 0) {
    return;
  }
  iVar4 = 0;
  pcVar3 = (char *)(param_1 + 0x1c);
  if (*(char *)(param_1 + 0xe) != '\0') {
    do {
      if (*pcVar3 == '\0') {
        iVar6 = *(int *)(pcVar3 + 8);
        *(int *)(pcVar3 + 4) = iVar6;
      }
      else if (*pcVar3 == '\x02') {
        uVar5 = *(undefined4 *)(pcVar3 + 8);
        *(undefined4 *)(pcVar3 + 4) = uVar5;
      }
      pcVar3 = pcVar3 + 0xc;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0xe));
    if (iVar6 < 0) {
      uVar1 = 0;
      goto LAB_0064d6cc;
    }
    uVar1 = 0xffff;
    if (0xffff < iVar6) goto LAB_0064d6cc;
  }
  uVar1 = (undefined2)iVar6;
LAB_0064d6cc:
  *(undefined2 *)(iVar2 * 0x8c + 0x8a + DAT_00713f48) = uVar1;
  SNDPLATFORM_setpitch(iVar2);
  FUN_0064d1e0(iVar2,uVar5);
  return;
}


// ==== 0x64d700 FUN_0064d700

undefined4 FUN_0064d700(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined1 *)(param_1 + 0x10) = 0xff;
  if (*(char *)(param_1 + 0xf) != '\0') {
    puVar1 = (undefined4 *)(param_1 + 0x1c + (uint)*(byte *)(param_1 + 0xe) * 0xc);
    puVar1[1] = 0;
    *puVar1 = 0;
  }
  return 0;
}


// ==== 0x64d730 FUN_0064d730

undefined4 FUN_0064d730(int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  iVar4 = SNDVOICEI_get__validate_handle____voice_index_(*(undefined4 *)(param_1 + 8));
  iVar5 = 0;
  pbVar6 = (byte *)(param_1 + 0x1c);
  if (iVar4 < 0) {
    *(undefined1 *)(param_1 + 0x10) = 0xff;
    if (*(char *)(param_1 + 0xf) != '\0') {
      puVar1 = (undefined4 *)(param_1 + 0x1c + (uint)*(byte *)(param_1 + 0xe) * 0xc);
      puVar1[1] = 0;
      *puVar1 = 0;
    }
    return 0;
  }
  if (*(char *)(param_1 + 0xe) != '\0') {
    do {
      if (*(int *)(pbVar6 + 8) != *(int *)(pbVar6 + 4)) {
        (*(code *)(&PTR_FUN_006e9a38)[*pbVar6])(iVar4,*(int *)(pbVar6 + 8));
        *(int *)(pbVar6 + 4) = *(int *)(pbVar6 + 8);
      }
      pbVar6 = pbVar6 + 0xc;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0xe));
  }
  if (*(char *)(param_1 + 0xf) != '\0') {
    iVar5 = iVar4 * 0x8c + DAT_00713f48;
    fVar2 = 1000.0 / (float)*(ushort *)(iVar4 * 0x8c + 0x20 + DAT_00713f48);
    iVar4 = FUN_00652770(iVar4);
    *(int *)(pbVar6 + 4) = (int)ROUND((float)iVar4 * fVar2);
    if (*(int *)(iVar5 + 0x18) < 1) {
      iVar4 = *(int *)(iVar5 + 0x14) - iVar4;
      fVar3 = (float)iVar4;
      if (iVar4 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      *(int *)pbVar6 = (int)ROUND(fVar3 * fVar2);
      return 1;
    }
    pbVar6[0] = 0;
    pbVar6[1] = 0;
    pbVar6[2] = 0;
    pbVar6[3] = 0;
  }
  return 1;
}


// ==== 0x64d860 FUN_0064d860

int FUN_0064d860(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x18);
  if (iVar4 < 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 2;
    if (iVar4 < 3) {
      iVar5 = iVar4;
    }
  }
  if (iVar5 != *(char *)(param_1 + 0xc)) {
    cVar2 = *(char *)(param_1 + 0x10);
    if (iVar5 == 0) {
      if (-1 < cVar2) {
        (**(code **)(&DAT_006e9aa8 + cVar2 * 4))(param_1);
        FUN_0064d700(param_1);
      }
    }
    else if (iVar5 == 1) {
      if (cVar2 < '\0') {
        if ((*(char *)(param_1 + 0xc) != '\x02') || (*(char *)(param_1 + 0xd) != '\x01')) {
          iVar4 = *(int *)(param_1 + 0x14);
          iVar3 = **(int **)(param_1 + 4);
          if (iVar4 < iVar3) {
            if (iVar4 < 0) {
              iVar4 = 0;
            }
          }
          else {
            iVar4 = iVar3 + -1;
          }
          piVar1 = *(int **)(param_1 + 4) + iVar4 * 3 + 1;
          cVar2 = (char)*piVar1;
          *(char *)(param_1 + 0x10) = cVar2;
          iVar4 = (**(code **)(&DAT_006e9a98 + cVar2 * 4))(param_1,piVar1);
          *(int *)(param_1 + 8) = iVar4;
          if (iVar4 < 0) {
            FUN_0064d700(param_1);
          }
        }
      }
      else {
        (**(code **)(&DAT_006e9ac8 + cVar2 * 4))(param_1);
      }
    }
    else if (-1 < cVar2) {
      (**(code **)(&DAT_006e9ab8 + cVar2 * 4))(*(undefined4 *)(param_1 + 8));
    }
    *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)(param_1 + 0xc);
    *(char *)(param_1 + 0xc) = (char)iVar5;
  }
  if ((iVar5 == 1) && (-1 < *(char *)(param_1 + 0x10))) {
    iVar5 = (**(code **)(&DAT_006e9ad8 + *(char *)(param_1 + 0x10) * 4))(param_1);
  }
  if (-1 < *(char *)(param_1 + 0x10)) {
    return iVar5;
  }
  return 0;
}


// ==== 0x64d960 FUN_0064d960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0064d960(char *param_1)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar6 = param_1;
  if (0 < *(int *)(param_1 + 8)) {
    fVar5 = _DAT_00713ca0 / (float)*(int *)(param_1 + 8);
    fVar4 = (float)*(int *)(param_1 + 0xc);
    if (_K_ONE <= *(float *)(param_1 + 4)) {
      fVar2 = *(float *)(param_1 + 4);
      do {
        fVar2 = fVar2 - _K_ONE;
      } while (_K_ONE <= fVar2);
      *(float *)(param_1 + 4) = fVar2;
    }
    cVar3 = *param_1;
    if (cVar3 == '\0') {
      iVar7 = FUN_006527a0((int)ROUND(*(float *)(param_1 + 4) * 1024.0));
      param_1 = (char *)((float)iVar7 * fVar4 * 1.5258789e-05);
    }
    else if (cVar3 == '\x01') {
      pfVar1 = (float *)(param_1 + 4);
      param_1 = (char *)fVar4;
      if (*pfVar1 < 0.5) {
        param_1 = (char *)0x0;
      }
    }
    else if (cVar3 == '\x02') {
      param_1 = (char *)(fVar4 * *(float *)(param_1 + 4));
    }
    else {
      if (0.5 <= *(float *)(param_1 + 4)) {
        fVar2 = _K_ONE - *(float *)(param_1 + 4);
      }
      else {
        fVar2 = *(float *)(param_1 + 4);
      }
      param_1 = (char *)(fVar4 * fVar2 + fVar4 * fVar2);
    }
    *(float *)(pcVar6 + 4) = fVar5 + *(float *)(pcVar6 + 4);
    return (int)ROUND((float)param_1);
  }
  return 0;
}


// ==== 0x64da70 FUN_0064da70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_0064da70(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = param_1[6];
  fVar3 = (float)(int)fVar1;
  if (fVar3 == *param_1) {
    return fVar1;
  }
  if ((fVar1 != param_1[2]) || (param_1[4] != param_1[3])) {
    fVar2 = param_1[4];
    param_1[2] = fVar1;
    param_1[3] = fVar2;
    if ((int)fVar2 < 1) {
      *param_1 = (float)(int)fVar1;
      return fVar1;
    }
    param_1[1] = fVar3 - *param_1;
    param_1[1] = ((fVar3 - *param_1) / (float)(int)fVar2) * _DAT_00713ca0 * 0.00024414062;
  }
  fVar2 = (float)(int)param_1[5] * param_1[1] + *param_1;
  *param_1 = fVar2;
  if (param_1[1] < 0.0) {
    if (fVar3 <= fVar2) goto LAB_0064daff;
  }
  else if (fVar2 <= fVar3) goto LAB_0064daff;
  *param_1 = (float)(int)fVar1;
LAB_0064daff:
  return (float)(int)ROUND(*param_1);
}


// ==== 0x64db20 FUN_0064db20

int FUN_0064db20(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  if (1 < *param_1) {
    pbVar2 = param_1 + 0xc;
    iVar3 = *param_1 - 1;
    do {
      iVar1 = iVar1 + *(int *)pbVar2;
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (*(int *)(param_1 + 4) < iVar1) {
    iVar1 = *(int *)(param_1 + 4);
  }
  return iVar1;
}


// ==== 0x64db50 FUN_0064db50

int FUN_0064db50(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] - param_1[2];
  if (param_1[1] - param_1[2] < *param_1) {
    iVar1 = *param_1;
  }
  return iVar1;
}


// ==== 0x64db70 FUN_0064db70

int FUN_0064db70(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2] * param_1[1];
  iVar1 = *param_1;
  if (iVar2 - iVar1 != 0 && iVar1 <= iVar2) {
    iVar2 = iVar1;
  }
  return iVar2;
}


// ==== 0x64db90 FUN_0064db90

undefined1 FUN_0064db90(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(param_1 + 0x19) = 0;
  return uVar1;
}


// ==== 0x64dba0 FUN_0064dba0

void FUN_0064dba0(undefined4 *param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x18) = *param_1;
  return;
}


// ==== 0x64dbb0 FUN_0064dbb0

void FUN_0064dbb0(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x10) = 1;
  return;
}


// ==== 0x64dbc0 FUN_0064dbc0

void FUN_0064dbc0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (*(char *)(param_2 + 0x10) != '\0') {
    puVar2 = (undefined4 *)(param_2 + 0x14);
    do {
      *puVar2 = *(undefined4 *)(param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(param_2 + 0x10));
  }
  return;
}


// ==== 0x64dbf0 FUN_0064dbf0

void FUN_0064dbf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (*(char *)(param_2 + 0x18) != '\0') {
    puVar2 = (undefined4 *)(param_2 + 0x1c);
    do {
      *puVar2 = *(undefined4 *)(param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(param_2 + 0x18));
  }
  *(undefined1 *)(param_2 + 0x19) = 1;
  return;
}


// ==== 0x64dc20 FUN_0064dc20

void FUN_0064dc20(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  FUN_0064e520();
  if (*(short *)(param_3 + 0x1e) <= *(short *)(param_3 + 0x1c)) {
    SNDSYS_leavecritical();
    return;
  }
  puVar1 = (undefined4 *)FUN_00650fd0(*(undefined4 *)(param_3 + 0x30));
  if (puVar1 != (undefined4 *)0x0) {
    uVar3 = *(uint *)(param_3 + 0x30);
    puVar5 = *(undefined4 **)(param_3 + 0x2c);
    puVar6 = puVar1;
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    piVar4 = (int *)(*(int *)(param_3 + 0x34) + (int)puVar1);
    *piVar4 = param_3;
    piVar4[1] = (int)puVar1;
    piVar4[2] = param_1;
    *puVar1 = *(undefined4 *)(param_3 + 0x38);
    puVar1[1] = 0;
    if (*(int *)(param_3 + 0x38) != 0) {
      *(undefined4 **)(*(int *)(param_3 + 0x38) + 4) = puVar1;
    }
    *(undefined4 **)(param_3 + 0x38) = puVar1;
    puVar1[4] = *(undefined4 *)(param_3 + 0x28);
    puVar5 = puVar1 + 6;
    puVar1[5] = puVar5;
    piVar4 = puVar1 + 2;
    *piVar4 = (int)DAT_00713c70;
    puVar1[3] = 0;
    if (DAT_00713c70 != (int *)0x0) {
      *(int **)((int)DAT_00713c70 + 4) = piVar4;
    }
    DAT_00713c70 = piVar4;
    if (*(char *)(param_3 + 0x25) != '\0') {
      puVar1[8] = FUN_0064dbb0;
      puVar1[9] = puVar5;
      FUN_0064b840(puVar5);
      puVar5 = puVar1 + 0xb;
    }
    iVar7 = 0;
    if (*(short *)(param_3 + 0x20) != 0) {
      do {
        puVar5[4] = FUN_0064dba0;
        puVar5[5] = puVar5;
        FUN_0064bf00(puVar5,puVar5 + 2);
        puVar5 = puVar5 + 7;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)*(ushort *)(param_3 + 0x20));
    }
    if (*(char *)(param_3 + 0x26) != '\0') {
      puVar5[2] = FUN_0064dbc0;
      puVar5[3] = puVar5;
      FUN_0064b8b0(puVar5);
      puVar5 = puVar5 + *(byte *)(puVar5 + 4) + 5;
    }
    iVar7 = 0;
    if (*(short *)(param_3 + 0x22) != 0) {
      do {
        puVar5[4] = FUN_0064dbf0;
        puVar5[5] = puVar5;
        FUN_0064ba70(puVar5,puVar5 + 2);
        iVar7 = iVar7 + 1;
        puVar5 = puVar5 + *(byte *)(puVar5 + 6) + 7;
      } while (iVar7 < (int)(uint)*(ushort *)(param_3 + 0x22));
    }
    *(short *)(param_3 + 0x1c) = *(short *)(param_3 + 0x1c) + 1;
    SNDSYS_leavecritical();
    return;
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x64dd70 SNDAEMS_removemodulebank

/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __thiscall SNDAEMS_removemodulebank(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  if (DAT_00713c9c != (code *)0x0) {
    (*DAT_00713c9c)(param_1);
  }
  FUN_0064e520();
  piVar4 = DAT_00713c74 + -0x14;
  while( true ) {
    if (piVar4 == (int *)0x0) {
      SNDSYS_leavecritical();
      return 0xfffffff8;
    }
    if (param_2 == piVar4[0xf]) break;
    piVar4 = (int *)(piVar4[0x14] + -0x50);
  }
  iVar6 = piVar4[7] + (int)piVar4;
  iVar7 = 0;
  if (*(short *)((int)piVar4 + 10) != 0) {
    do {
      FUN_0064bcd0(iVar6 + 4,iVar6 + 0xc);
      puVar2 = *(undefined4 **)(iVar6 + 0x38);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        iVar3 = *(int *)(iVar6 + 0x34) + (int)puVar2;
        *(undefined4 *)(iVar3 + 0xc) = 1;
        FUN_0064c690(iVar3);
        puVar2 = puVar1;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x3c + ((uint)*(byte *)(iVar6 + 0x27) + (uint)*(byte *)(iVar6 + 0x24)) * 4;
    } while (iVar7 < (int)(uint)*(ushort *)((int)piVar4 + 10));
  }
  if (piVar4[0x12] != 0) {
    FUN_006510d0(piVar4[0x12]);
  }
  if (-1 < piVar4[0x10]) {
    SNDbankremove(piVar4[0x10]);
  }
  if (-1 < piVar4[0x11]) {
    SNDbankremove(piVar4[0x11]);
  }
  piVar5 = piVar4 + 0x14;
  if (piVar5 == DAT_00713c74) {
    DAT_00713c74 = (int *)*DAT_00713c74;
  }
  if ((int *)piVar4[0x15] != (int *)0x0) {
    *(int *)piVar4[0x15] = *piVar5;
  }
  if (*piVar5 != 0) {
    *(int *)(*piVar5 + 4) = piVar4[0x15];
  }
  if (DAT_00713c74 == (int *)0x0) {
    if ((undefined4 **)DAT_00713ca8 == &DAT_00713c7c) {
      DAT_00713ca8 = DAT_00713c7c;
    }
    if (DAT_00713c80 != (undefined4 *)0x0) {
      *DAT_00713c80 = DAT_00713c7c;
    }
    if (DAT_00713c7c != (undefined4 *)0x0) {
      DAT_00713c7c[1] = DAT_00713c80;
    }
  }
  SNDSYS_leavecritical();
  return 0;
}


// ==== 0x64dee0 SNDAEMSI_createmodulebankhandle

/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDAEMSI_createmodulebankhandle(void)

{
  DAT_00713c64 = DAT_00713c64 + 1;
  if (DAT_00713c64 < 0) {
    DAT_00713c64 = 1;
    return 1;
  }
  return DAT_00713c64;
}


// ==== 0x64df00 FUN_0064df00

void FUN_0064df00(void)

{
  FUN_0064e520();
  while (DAT_00713c74 != 0) {
    SNDAEMS_removemodulebank(*(undefined4 *)(DAT_00713c74 + -0x14));
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x64df30 FUN_0064df30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064df30(int param_1,int *param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  int local_8;
  undefined2 local_4;
  undefined2 local_2;
  
  DAT_00713f30 = FUN_0064df00;
  FUN_0064e520();
  iVar8 = 0;
  piVar9 = (int *)(param_1 + 0x50);
  bVar10 = DAT_00713c74 == (int *)0x0;
  *piVar9 = (int)DAT_00713c74;
  *(undefined4 *)(param_1 + 0x54) = 0;
  if (DAT_00713c74 != (int *)0x0) {
    *(int **)((int)DAT_00713c74 + 4) = piVar9;
  }
  iVar6 = 0;
  piVar5 = param_2;
  DAT_00713c74 = piVar9;
  if (0 < *param_2) {
    do {
      iVar7 = piVar5[1];
      puVar3 = (undefined4 *)(iVar7 + param_1);
      *puVar3 = (&PTR_FUN_006e9ae8)[*(int *)(iVar7 + param_1)] + (-4 - (int)puVar3);
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar6 < *param_2);
  }
  iVar6 = *(int *)(param_1 + 0x30);
  piVar5 = (int *)((int)param_2 + (*(int *)(param_1 + 0x34) - iVar6));
  iVar7 = 0;
  piVar9 = piVar5;
  if (0 < *(int *)((int)param_2 + (*(int *)(param_1 + 0x34) - iVar6))) {
    do {
      iVar2 = piVar9[1];
      *(int *)(iVar2 + param_1) = *(int *)(iVar2 + param_1) + param_1;
      iVar7 = iVar7 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar7 < *piVar5);
  }
  piVar9 = (int *)((int)param_2 + (*(int *)(param_1 + 0x38) - iVar6));
  if (0 < *piVar9) {
    piVar5 = piVar9 + 1;
    do {
      local_4 = *(undefined2 *)((int)param_2 + (piVar5[1] - iVar6));
      iVar7 = piVar5[1] - iVar6;
      local_2 = *(undefined2 *)((int)param_2 + iVar7 + 2);
      local_8 = (int)param_2 + iVar7 + 4;
      if ((char)piVar5[2] == '\0') {
        FUN_0064b9c0(&local_8);
      }
      else if ((char)piVar5[2] == '\x01') {
        FUN_0064b970(&local_8);
      }
      else {
        FUN_0064b920(&local_8);
      }
      iVar8 = iVar8 + 1;
      piVar5 = piVar5 + 3;
    } while (iVar8 < *piVar9);
  }
  iVar6 = 0;
  iVar8 = *(int *)(param_1 + 0x1c) + param_1;
  if (*(short *)(param_1 + 10) != 0) {
    do {
      *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + param_1;
      *(int *)(iVar8 + 0x2c) = *(int *)(iVar8 + 0x2c) + param_1;
      *(code **)(iVar8 + 0x14) = FUN_0064dc20;
      *(int *)(iVar8 + 0x18) = iVar8;
      FUN_0064bc80(iVar8 + 4,iVar8 + 0xc);
      iVar7 = 0;
      if (*(char *)(iVar8 + 0x24) != '\0') {
        do {
          *(int *)(*(int *)(iVar8 + 0x3c + iVar7 * 4) + *(int *)(iVar8 + 0x2c)) = param_1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(byte *)(iVar8 + 0x24));
      }
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 0x3c + ((uint)*(byte *)(iVar8 + 0x27) + (uint)*(byte *)(iVar8 + 0x24)) * 4;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 10));
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  else {
    pcVar4 = param_3;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)FUN_00650fd0(pcVar4 + (1 - (int)(param_3 + 1)));
    *(char **)(param_1 + 0x48) = pcVar4;
    do {
      cVar1 = *param_3;
      param_3 = param_3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    *(undefined4 *)(param_1 + 0x4c) = param_4;
  }
  if (bVar10) {
    _DAT_00713c84 = FUN_00652960;
    DAT_00713c7c = DAT_00713ca8;
    DAT_00713c80 = 0;
    if (DAT_00713ca8 != (undefined4 *)0x0) {
      DAT_00713ca8[1] = &DAT_00713c7c;
    }
    DAT_00713ca8 = &DAT_00713c7c;
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x64e160 SNDAEMS_addmodulebank

/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDAEMS_addmodulebank(undefined4 *param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  if (DAT_00713c98 != (code *)0x0) {
    (*DAT_00713c98)();
  }
  uVar1 = SNDAEMSI_createmodulebankhandle();
  param_1[0xf] = uVar1;
  if (((param_1[8] == 0) ||
      (iVar2 = SNDbankadd(param_1 + 0x10,(undefined1 *)(param_1[8] + (int)param_1)), local_c = iVar2
      , -1 < iVar2)) &&
     ((param_1[10] == 0 ||
      (iVar2 = SNDbankadd(param_1 + 0x11,(undefined1 *)(param_1[10] + (int)param_1)),
      local_8 = iVar2, -1 < iVar2)))) {
    iVar2 = param_1[6];
    if (local_c == 7) {
      iVar3 = FUN_00652a00(param_1[0x10]);
    }
    else {
      iVar3 = param_1[9];
    }
    if (local_8 == 7) {
      iVar4 = FUN_00652a00(param_1[0x11]);
    }
    else {
      iVar4 = param_1[0xb];
    }
    puVar5 = (undefined4 *)(*param_4)(param_1,iVar4 + iVar2 + iVar3,param_1[5]);
    if (puVar5 != (undefined4 *)0x0) {
      puVar8 = param_1;
      if (puVar5 != param_1) {
        uVar7 = param_1[6];
        puVar9 = puVar5;
        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        puVar8 = puVar5;
        if (local_c != 0) {
          FUN_006529a0((undefined1 *)(puVar5[6] + (int)puVar5),puVar5[0x10]);
        }
      }
      if ((0 < local_8) && ((puVar5 != param_1 || (local_c == 7)))) {
        FUN_006529a0((undefined1 *)((int)puVar5 + iVar2 + iVar3),puVar8[0x11]);
      }
      FUN_0064df30(puVar8,(undefined1 *)(puVar8[0xc] + (int)param_1),param_2,param_3);
      return puVar8[0xf];
    }
    iVar2 = -6;
  }
  if (0 < local_c) {
    SNDbankremove(param_1[0x10]);
  }
  if (0 < local_8) {
    SNDbankremove(param_1[0x11]);
  }
  return iVar2;
}


// ==== 0x64e2f0 FUN_0064e2f0

void FUN_0064e2f0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = DAT_00713ca4;
  puVar2 = DAT_00713ca8;
  if (DAT_00713ca4 != DAT_00713cac) {
    while (DAT_00713cac = iVar3, puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      (*(code *)puVar2[2])(puVar2[3]);
      iVar3 = DAT_00713cac;
      puVar2 = puVar1;
    }
  }
  return;
}


// ==== 0x64e330 SNDSYSI_100hzserver__map_name_SNDvol_is_wrong_

/* [canon] audio high (ghidra) docs/re/sound.md */

void SNDSYSI_100hzserver__map_name_SNDvol_is_wrong_(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  int local_4;
  
  DAT_00713eec = DAT_00713eec + 1;
  NullUpdate_ret();
  iVar7 = 0;
  if ('\0' < DAT_00713ee6) {
    do {
      (*(code *)(&DAT_00713ef0)[iVar7])();
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_00713ee6);
  }
  iVar7 = 0;
  if (0 < DAT_00713ee8) {
    local_4 = 0;
    do {
      piVar8 = (int *)(local_4 + DAT_00713f48);
      if (*(char *)(local_4 + 0x69 + DAT_00713f48) == '\x01') {
        if ((-1 < *piVar8) && (piVar8[0x1f] != 0)) {
          bVar5 = (char)piVar8[0x1a] + 1;
          *(byte *)(piVar8 + 0x1a) = bVar5;
          if (*(byte *)((int)piVar8 + 0x66) <= bVar5) {
            *(undefined1 *)(piVar8 + 0x1a) = 0;
          }
          *(undefined2 *)((int)piVar8 + 0x86) = 0;
          iSNDcalcpitch(iVar7);
          SNDPLATFORM_setpitch(iVar7);
        }
        bVar4 = false;
        if (piVar8[0x1e] != 0) {
          bVar5 = *(char *)((int)piVar8 + 0x67) + 1;
          *(byte *)((int)piVar8 + 0x67) = bVar5;
          bVar4 = true;
          if (*(byte *)((int)piVar8 + 0x65) <= bVar5) {
            *(undefined1 *)((int)piVar8 + 0x67) = 0;
          }
        }
        if ((float)piVar8[0xc] != 0.0) {
          bVar4 = true;
          fVar3 = (float)piVar8[0xe] + (float)piVar8[0xc];
          piVar8[0xe] = (int)fVar3;
          fVar1 = (float)piVar8[0xd];
          if (0.0 <= (float)piVar8[0xc]) {
            if (fVar3 >= fVar1) {
              piVar8[0xe] = piVar8[0xd];
              goto LAB_0064e434;
            }
          }
          else if (fVar3 < fVar1 != (fVar3 == fVar1)) {
            piVar8[0xe] = piVar8[0xd];
LAB_0064e434:
            piVar8[0xc] = 0;
          }
          if ((float)piVar8[0xe] < 0.0) {
            SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
                      (*piVar8);
            goto LAB_0064e4cd;
          }
        }
        iVar2 = piVar8[0x11];
        piVar8[0x11] = iVar2 + -1;
        if (piVar8[0xf] != 0) {
          piVar8[0x10] = piVar8[0x10] + piVar8[0xf];
          bVar4 = true;
        }
        if (iVar2 + -1 == 0) {
          cVar6 = *(char *)((int)piVar8 + 0x5d) + '\x01';
          *(char *)((int)piVar8 + 0x5d) = cVar6;
          if ((char)piVar8[0x17] <= cVar6) {
            SNDI_stophandle__loops_patch_voices_of_a_handle__0x651f30_kill__map__SNDSYS_entercritical_
                      (*piVar8);
            goto LAB_0064e4cd;
          }
          iVar2 = *(int *)(piVar8[0x1b] + cVar6 * 8);
          piVar8[0x11] = iVar2;
          if (iVar2 < 0) {
            piVar8[0x11] = 0x7fffffff;
          }
          piVar8[0xf] = (*(int *)(piVar8[0x1b] + cVar6 * 8 + 4) * 0x10000 - piVar8[0x10]) /
                        piVar8[0x11];
        }
        if (bVar4) {
          iSNDcalcvol(iVar7);
          Snd__Hal__SetVol__SNDPLATFORM_setvol_(iVar7);
        }
      }
LAB_0064e4cd:
      iVar7 = iVar7 + 1;
      local_4 = local_4 + 0x8c;
    } while (iVar7 < DAT_00713ee8);
  }
  return;
}


// ==== 0x64e500 thunk_FUN_00652d80

void thunk_FUN_00652d80(void)

{
  WaitForSingleObject(DAT_0071402c,0xffffffff);
  return;
}


// ==== 0x64e510 thunk_FUN_00652d90

void thunk_FUN_00652d90(void)

{
  FUN_00652d90();
  return;
}


// ==== 0x64e520 FUN_0064e520

void FUN_0064e520(void)

{
  (*(code *)PTR_thunk_FUN_00652d80_006e9b8c)();
  DAT_00713ee5 = DAT_00713ee5 + '\x01';
  return;
}


// ==== 0x64e540 SNDSYS_leavecritical

/* [canon] audio high (ghidra) docs/re/sound.md */

void SNDSYS_leavecritical(void)

{
  DAT_00713ee5 = DAT_00713ee5 + -1;
                    /* WARNING: Could not recover jumptable at 0x0064e54c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_thunk_FUN_00652d90_006e9b90)();
  return;
}


// ==== 0x64e560 FUN_0064e560

undefined4 FUN_0064e560(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 0;
  case 0xffffffed:
    return 0xffffffff;
  case 0xffffffee:
    return 0xfffffff9;
  default:
    return 0xfffffffa;
  case 0xfffffff1:
    return 0xfffffff8;
  case 0xfffffff2:
    return 0xfffffffc;
  case 0xfffffff6:
    return 0xfffffff7;
  case 0xfffffff7:
  case 0xfffffffa:
    return 0xfffffffe;
  case 0xfffffff8:
    return 0xfffffff6;
  case 0xfffffff9:
    return 0xfffffff5;
  }
}


// ==== 0x64e5f0 FUN_0064e5f0

undefined4 FUN_0064e5f0(undefined2 param_1)

{
  undefined1 local_d4 [40];
  undefined2 local_ac;
  
  FUN_0064f4b0(local_d4);
  local_ac = param_1;
  FUN_0064f530(local_d4);
  return 0;
}


// ==== 0x64e620 FUN_0064e620

undefined4 FUN_0064e620(float param_1)

{
  undefined1 local_d4 [52];
  float local_a0;
  
  if (0.0 <= param_1) {
    param_1 = 1000.0 / param_1;
  }
  FUN_0064f4b0(local_d4);
  local_a0 = param_1;
  FUN_0064f530(local_d4);
  return 0;
}


// ==== 0x64e680 FUN_0064e680

undefined4 FUN_0064e680(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_d4 [212];
  
  *param_2 = 0;
  iVar1 = FUN_00651c10(local_d4,&DAT_00713cb4);
  if (iVar1 < 0) {
    uVar2 = FUN_0064e560(iVar1);
    return uVar2;
  }
  if ((&DAT_00713cb4)[param_1] == '\x01') {
    *param_2 = 1;
  }
  return 0;
}


// ==== 0x64e6e0 FUN_0064e6e0

undefined4 FUN_0064e6e0(undefined4 param_1)

{
  char local_1;
  
  FUN_0064e680(param_1,&local_1);
  if (local_1 == '\0') {
    return 0xfffffffb;
  }
  DAT_006e9b94 = param_1;
  return 0;
}


// ==== 0x64e710 FUN_0064e710

undefined4 FUN_0064e710(int param_1,int param_2)

{
  undefined1 local_d4 [42];
  undefined2 local_aa;
  
  FUN_0064f4b0(local_d4);
  if (0xffff < param_2) {
    param_2 = 0xffff;
  }
  if (param_1 != 0) {
    return 0xfffffffb;
  }
  local_aa = (undefined2)param_2;
  FUN_0064f530(local_d4);
  return 0;
}


// ==== 0x64e780 FUN_0064e780

undefined4 FUN_0064e780(int param_1,undefined4 param_2)

{
  undefined1 local_d4 [46];
  undefined1 local_a6;
  
  FUN_0064f4b0(local_d4);
  if (param_1 == 0) {
    local_a6 = (undefined1)param_2;
  }
  else {
    if (param_1 != 3) {
      return 0xfffffffb;
    }
    DAT_00713cc4 = param_2;
  }
  FUN_0064f530(local_d4);
  return 0;
}


// ==== 0x64e7f0 FUN_0064e7f0

undefined4 FUN_0064e7f0(void)

{
  return 0xfffffffb;
}


// ==== 0x64e800 FUN_0064e800

undefined4 FUN_0064e800(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_d4 [49];
  undefined1 local_a3;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_88;
  undefined2 local_86;
  undefined2 local_84;
  undefined2 local_82;
  
  uVar1 = FUN_0064f4b0(local_d4);
  iVar2 = FUN_0064e560(uVar1);
  if (-1 < iVar2) {
    if (DAT_00713cc4 < 1) {
      local_88 = 1;
      local_86 = 0x24;
    }
    else {
      local_88 = 3;
      local_86 = 0x31;
      local_84 = 0x32;
      local_82 = 0x24;
      local_a3 = (undefined1)DAT_00713cc4;
    }
    switch(DAT_006e9b94) {
    case 0:
      local_8d = 1;
      break;
    case 1:
      local_8d = 2;
      break;
    case 2:
      local_8d = 4;
      break;
    case 3:
      local_8d = 5;
      local_8c = 1;
    }
    FUN_0064f530(local_d4);
    SNDSYSI_init(DAT_00713cc0,DAT_00713cb0,param_1);
    return 0;
  }
  uVar1 = FUN_0064e560(iVar2);
  return uVar1;
}


// ==== 0x64e8e0 FUN_0064e8e0

undefined4 FUN_0064e8e0(void)

{
  SNDSYS_shutdown__map__SNDSYS_restore_();
  DAT_00713cc0 = 0;
  return 0;
}


// ==== 0x64e900 FUN_0064e900

undefined4 FUN_0064e900(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    return 0xfffffffb;
  }
  DAT_00713cc0 = param_2;
  DAT_00713cb0 = param_3;
  return 0;
}


// ==== 0x64e930 FUN_0064e930

undefined4 FUN_0064e930(int param_1,uint *param_2)

{
  undefined1 local_d4 [46];
  byte local_a6;
  byte local_a3;
  
  FUN_0064f4b0(local_d4);
  if (param_1 == 0) {
    *param_2 = (uint)local_a6;
    return 0;
  }
  if (param_1 != 3) {
    return 0xfffffffb;
  }
  if (DAT_00713ee4 == '\x01') {
    *param_2 = (uint)local_a3;
    return 0;
  }
  *param_2 = DAT_00713cc4;
  return 0;
}


// ==== 0x64e9c0 Mutex::Lock

void Mutex__Lock(void)

{
  Mutex__Lock();
  return;
}


// ==== 0x64e9d0 Mutex::Unlock

void Mutex__Unlock(void)

{
  Mutex__Unlock();
  return;
}


// ==== 0x64e9e0 FUN_0064e9e0

undefined4 FUN_0064e9e0(void)

{
  if ((code *)PTR_thunk_FUN_00652d80_006e9b8c != Mutex__Lock) {
    PTR_thunk_FUN_00652d80_006e9b8c = Mutex__Lock;
    PTR_thunk_FUN_00652d90_006e9b90 = Mutex__Unlock;
  }
  return 0;
}


// ==== 0x64ea10 FUN_0064ea10

undefined4 FUN_0064ea10(void)

{
  FUN_00652db0();
  return 0;
}


// ==== 0x64ea20 FUN_0064ea20

int FUN_0064ea20(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = DAT_00713c94;
  if ((DAT_00713c94 != (int *)0x0) &&
     (DAT_00713c94 = (int *)*DAT_00713c94, DAT_00713c94 != (int *)0x0)) {
    DAT_00713c94[1] = 0;
  }
  if (piVar5 != (int *)0x0) {
    *piVar5 = (int)DAT_00713c90;
    piVar5[1] = 0;
    if (DAT_00713c90 != (int *)0x0) {
      DAT_00713c90[1] = (int)piVar5;
    }
    DAT_00713c90 = piVar5;
LAB_0064eaad:
    iVar2 = (piVar5[2] & 0x3fffffffU) + 0x80;
    piVar5[2] = iVar2;
    iVar6 = DAT_00713eec;
    piVar5[3] = param_1;
    piVar5[4] = iVar6;
    return iVar2;
  }
  uVar3 = 0xffffffff;
  iVar6 = param_1 + -1;
  piVar1 = DAT_00713c90;
  if (DAT_00713c90 != (int *)0x0) {
    do {
      iVar2 = piVar1[3];
      if (iVar2 < iVar6) {
        uVar4 = piVar1[4];
        iVar6 = iVar2;
LAB_0064ea8c:
        uVar3 = uVar4;
        piVar5 = piVar1;
      }
      else if ((iVar2 == iVar6) && (uVar4 = piVar1[4], uVar4 < uVar3)) goto LAB_0064ea8c;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (piVar5 != (int *)0x0) {
      FUN_006504e0(piVar5[6]);
      goto LAB_0064eaad;
    }
  }
  return -9;
}


// ==== 0x64ead0 FUN_0064ead0

void FUN_0064ead0(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00650cb0();
    return;
  }
  FUN_00650cb0();
  return;
}


// ==== 0x64eb00 FUN_0064eb00

void FUN_0064eb00(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00652df0();
    return;
  }
  FUN_00652df0();
  return;
}


// ==== 0x64eb30 FUN_0064eb30

void FUN_0064eb30(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  FUN_00650d90(param_1,0xffffffff,(float)param_2 * 3.051851e-05);
  return;
}


// ==== 0x64eb70 FUN_0064eb70

void FUN_0064eb70(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00650020(param_1);
  FUN_00652e40(param_1,param_2,(int)*(short *)(iVar1 + 0x11a));
  return;
}


// ==== 0x64eba0 FUN_0064eba0

void FUN_0064eba0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < -0x4000) {
    param_2 = -0x4000;
  }
  else if (0x3fff < param_2) {
    param_2 = 0x3fff;
  }
  iVar1 = FUN_00650020(param_1);
  FUN_00652e40(param_1,*(undefined2 *)(iVar1 + 0x118),param_2);
  return;
}


// ==== 0x64ebf0 FUN_0064ebf0

void FUN_0064ebf0(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00652ea0(param_1,0,0);
    return;
  }
  if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  FUN_00652ea0(param_1,0,param_2 >> 8);
  return;
}


// ==== 0x64ec30 FUN_0064ec30

void FUN_0064ec30(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00652ef0();
    return;
  }
  FUN_00652ef0();
  return;
}


// ==== 0x64ec60 FUN_0064ec60

void FUN_0064ec60(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00652f40();
    return;
  }
  FUN_00652f40();
  return;
}


// ==== 0x64ec90 FUN_0064ec90

void FUN_0064ec90(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    FUN_00652f90();
    return;
  }
  FUN_00652f90();
  return;
}


// ==== 0x64ecc0 FUN_0064ecc0

uint FUN_0064ecc0(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int aiStack_30 [12];
  
  uVar2 = FUN_0064ea20(*(undefined1 *)((int)param_2 + 1));
  iVar6 = 0;
  if (-1 < (int)uVar2) {
    uVar3 = (uVar2 & 0x7f) * 0x60 + DAT_00713c8c;
    aiStack_30[3] = 0;
    aiStack_30[4] = 0;
    aiStack_30[5] = 0;
    aiStack_30[6] = 0xffff;
    aiStack_30[7] = 0;
    uVar3 = (uVar2 != *(uint *)(uVar3 + 8)) - 1 & uVar3;
    *(int **)(uVar3 + 0x24) = param_2;
    *(undefined4 *)(uVar3 + 0x28) = *(undefined4 *)(*param_1 + 0x48);
    aiStack_30[0] = 0x1000;
    aiStack_30[1] = 0x1000;
    *(undefined4 *)(uVar3 + 0x2c) = *(undefined4 *)(*param_1 + 0x4c);
    *(undefined1 *)(uVar3 + 0x14) = 0;
    aiStack_30[2] = 0x7fff;
    aiStack_30[8] = 0x7fff;
    pbVar5 = (byte *)(param_1 + 7);
    for (uVar4 = (uint)*(byte *)((int)param_1 + 0xe); uVar4 != 0; uVar4 = uVar4 - 1) {
      aiStack_30[*pbVar5] = *(int *)(pbVar5 + 8);
      pbVar5 = pbVar5 + 0xc;
    }
    param_2 = (int *)(uVar3 + 0x30);
    do {
      iVar1 = *(int *)((int)aiStack_30 + iVar6);
      if (*param_2 != iVar1) {
        (**(code **)((int)&PTR_FUN_006e9b98 + iVar6))(*(undefined4 *)(uVar3 + 0x18),iVar1);
        *param_2 = iVar1;
      }
      iVar6 = iVar6 + 4;
      param_2 = param_2 + 1;
    } while (iVar6 < 0x24);
    if (*(char *)((int)param_1 + 0xf) != '\0') {
      pbVar5[4] = 0;
      pbVar5[5] = 0;
      pbVar5[6] = 0;
      pbVar5[7] = 0;
      pbVar5[0] = 0xff;
      pbVar5[1] = 0xff;
      pbVar5[2] = 0xff;
      pbVar5[3] = 0x7f;
    }
  }
  return uVar2;
}


// ==== 0x64edf0 FUN_0064edf0

void FUN_0064edf0(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_1 & 0x7f) * 0x60;
  iVar2 = iVar1 + DAT_00713c8c;
  if (param_1 == *(uint *)(iVar1 + 8 + DAT_00713c8c)) {
    FUN_00650d90(*(undefined4 *)(iVar2 + 0x18),0xffffffff,0);
    FUN_00650cb0(*(undefined4 *)(iVar2 + 0x18),0);
  }
  return;
}


// ==== 0x64ee30 FUN_0064ee30

void FUN_0064ee30(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (*(uint *)(param_1 + 8) & 0x7f) * 0x60;
  iVar4 = iVar3 + DAT_00713c8c;
  if (*(uint *)(param_1 + 8) == *(uint *)(iVar3 + 8 + DAT_00713c8c)) {
    iVar3 = 0;
    pbVar2 = (byte *)(param_1 + 0x1c);
    if (*(char *)(param_1 + 0xe) != '\0') {
      do {
        bVar1 = *pbVar2;
        if ((bVar1 == 0) || (bVar1 == 2)) {
          *(undefined4 *)(iVar4 + 0x30 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar2 + 8);
        }
        pbVar2 = pbVar2 + 0xc;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0xe));
    }
    iVar3 = *(int *)(iVar4 + 0x30);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0xffff < iVar3) {
      iVar3 = 0xffff;
    }
    FUN_00650cb0(*(undefined4 *)(iVar4 + 0x18),iVar3);
    param_1 = *(int *)(iVar4 + 0x38);
    if (param_1 < 0) {
      param_1 = 0;
    }
    else if (0x7fff < param_1) {
      param_1 = 0x7fff;
    }
    FUN_00650d90(*(undefined4 *)(iVar4 + 0x18),0xffffffff,(float)param_1 * 3.051851e-05);
  }
  return;
}


// ==== 0x64eef0 FUN_0064eef0

undefined4 FUN_0064eef0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  
  iVar6 = (*(uint *)(param_1 + 8) & 0x7f) * 0x60;
  puVar7 = (undefined4 *)(iVar6 + DAT_00713c8c);
  puVar3 = DAT_00713c94;
  if (*(uint *)(param_1 + 8) == *(uint *)(iVar6 + 8 + DAT_00713c8c)) {
    iVar6 = FUN_00650020(puVar7[6]);
    if (((*(char *)(puVar7 + 5) != '\x01') || (*(int *)(iVar6 + 0x148) != 0)) ||
       (*(char *)puVar7[9] != '\x01')) {
      iVar5 = 0;
      pbVar8 = (byte *)(param_1 + 0x1c);
      if (*(char *)(param_1 + 0xe) != '\0') {
        do {
          if (puVar7[*pbVar8 + 0xc] != *(int *)(pbVar8 + 8)) {
            (*(code *)(&PTR_FUN_006e9b98)[*pbVar8])(puVar7[6],*(int *)(pbVar8 + 8));
            puVar7[*pbVar8 + 0xc] = *(int *)(pbVar8 + 8);
          }
          pbVar8 = pbVar8 + 0xc;
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0xe));
      }
      if (*(char *)(param_1 + 0xf) != '\0') {
        if (*(char *)(puVar7 + 5) == '\x01') {
          iVar5 = *(int *)(iVar6 + 0x140);
          if ((*(ushort *)(iVar6 + 0x38) != 0) &&
             (fVar1 = 1000.0 / (float)*(ushort *)(iVar6 + 0x38), iVar5 != 0)) {
            if (puVar7[7] != *(int *)(iVar5 + 0xc)) {
              iVar6 = *(int *)(iVar5 + 0x18) - *(int *)(iVar5 + 0x14);
              fVar2 = (float)iVar6;
              if (iVar6 < 0) {
                fVar2 = fVar2 + 4.2949673e+09;
              }
              *(int *)pbVar8 = (int)ROUND(fVar2 * fVar1);
              iVar6 = puVar7[8] + *(int *)(iVar5 + 0x14);
              fVar2 = (float)iVar6;
              if (iVar6 < 0) {
                fVar2 = fVar2 + 4.2949673e+09;
              }
              *(int *)(pbVar8 + 4) = (int)ROUND(fVar2 * fVar1);
              return 1;
            }
            puVar7[8] = *(int *)(iVar5 + 0x18);
            fVar2 = (float)*(int *)(iVar5 + 0x14);
            if (*(int *)(iVar5 + 0x14) < 0) {
              fVar2 = fVar2 + 4.2949673e+09;
            }
            *(int *)(pbVar8 + 4) = (int)ROUND(fVar2 * fVar1);
            return 1;
          }
        }
        else {
          pbVar8[4] = 0;
          pbVar8[5] = 0;
          pbVar8[6] = 0;
          pbVar8[7] = 0;
          pbVar8[0] = 0xff;
          pbVar8[1] = 0xff;
          pbVar8[2] = 0xff;
          pbVar8[3] = 0x7f;
        }
      }
      return 1;
    }
    FUN_0064b380(puVar7);
    *puVar7 = DAT_00713c94;
    puVar7[1] = 0;
    puVar3 = puVar7;
    if (DAT_00713c94 != (undefined4 *)0x0) {
      *(undefined4 **)((int)DAT_00713c94 + 4) = puVar7;
    }
  }
  DAT_00713c94 = puVar3;
  uVar4 = FUN_0064d700(param_1);
  return uVar4;
}


// ==== 0x64f0e0 FUN_0064f0e0

void FUN_0064f0e0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  DAT_00713c7a = 1;
  FUN_0064e520();
  for (puVar1 = DAT_00713c90; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if (*(char *)(puVar1 + 5) == '\0') {
      puVar1[7] = 0xffffffff;
      puVar1[8] = 0;
      if (*(char *)puVar1[9] == '\x01') {
        SNDSYS_leavecritical();
        FUN_006504b0(puVar1[6],0,puVar1[10],*(int *)(puVar1[9] + 4) + puVar1[0xb]);
      }
      else {
        SNDSYS_leavecritical();
        uVar2 = FUN_006504b0(puVar1[6],1000,puVar1[10],*(int *)(puVar1[9] + 4) + puVar1[0xb]);
        puVar1[7] = uVar2;
      }
      FUN_0064e520();
      *(undefined1 *)(puVar1 + 5) = 1;
    }
    if (((*(char *)(puVar1 + 5) == '\x01') && (*(char *)puVar1[9] == '\x02')) &&
       (iVar3 = FUN_00650020(puVar1[6]), 0 < *(int *)(iVar3 + 0x154))) {
      SNDSYS_leavecritical();
      FUN_006504b0(puVar1[6],0,puVar1[10],*(int *)(puVar1[9] + 8) + puVar1[0xb]);
      FUN_0064e520();
    }
  }
  DAT_00713c7a = 0;
  for (; '\0' < DAT_00713c79; DAT_00713c79 = DAT_00713c79 + -1) {
    FUN_00652960(DAT_00713c88);
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x64f210 FUN_0064f210

undefined4 FUN_0064f210(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00713ee4 != '\0') {
    if (DAT_00713c8c != 0) {
      FUN_0064c5c0(FUN_0064f0e0);
      iVar2 = 0;
      if (DAT_00713c78 != 0) {
        iVar1 = 0;
        do {
          SNDSTRMI_service(*(undefined4 *)(iVar1 + 0x18 + DAT_00713c8c));
          iVar2 = iVar2 + 1;
          iVar1 = iVar1 + 0x60;
        } while (iVar2 < (int)(uint)DAT_00713c78);
      }
      DAT_00713c94 = 0;
      DAT_00713c90 = 0;
      DAT_00713c8c = 0;
    }
    return 0;
  }
  return 0xfffffff6;
}


// ==== 0x64f290 FUN_0064f290

void FUN_0064f290(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(uint *)(param_1 + 8) & 0x7f) * 0x60;
  piVar2 = (int *)(iVar1 + DAT_00713c8c);
  if (*(uint *)(param_1 + 8) == *(uint *)(iVar1 + 8 + DAT_00713c8c)) {
    FUN_006504e0(piVar2[6]);
    if (piVar2 == DAT_00713c90) {
      DAT_00713c90 = (int *)*DAT_00713c90;
    }
    if ((int *)piVar2[1] != (int *)0x0) {
      *(int *)piVar2[1] = *piVar2;
    }
    if (*piVar2 != 0) {
      *(int *)(*piVar2 + 4) = piVar2[1];
    }
    *piVar2 = (int)DAT_00713c94;
    piVar2[1] = 0;
    if (DAT_00713c94 != (int *)0x0) {
      DAT_00713c94[1] = (int)piVar2;
    }
    DAT_00713c94 = piVar2;
    if (*(char *)(param_1 + 0xc) == '\x02') {
      FUN_0064ee30(param_1);
    }
  }
  return;
}


// ==== 0x64f320 SNDAEMS_streaminit

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDAEMS_streaminit(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  undefined1 local_18 [5];
  undefined1 local_13;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  FUN_0064f210();
  _DAT_006e9a9c = FUN_0064ecc0;
  _DAT_006e9aa0 = FUN_0064ecc0;
  _DAT_006e9aac = FUN_0064f290;
  _DAT_006e9ab0 = FUN_0064f290;
  _DAT_006e9abc = FUN_0064edf0;
  _DAT_006e9ac0 = FUN_0064edf0;
  _DAT_006e9acc = FUN_0064ee30;
  _DAT_006e9ad0 = FUN_0064ee30;
  DAT_00713f34 = FUN_0064f210;
  _DAT_006e9adc = FUN_0064eef0;
  _DAT_006e9ae0 = FUN_0064eef0;
  FUN_0064e520();
  DAT_00713c8c = param_1;
  param_1 = param_1 + param_3 * 0x60;
  DAT_00713c78 = (undefined1)param_3;
  SNDplaysetdef(local_18);
  iVar3 = 0;
  local_13 = 0;
  uVar4 = (param_2 + param_3 * -0x60) / param_3 & 0x7ffffffc;
  if (0 < param_3) {
    local_1c = 0;
    do {
      piVar1 = (int *)(local_1c + DAT_00713c8c);
      *piVar1 = (int)DAT_00713c94;
      piVar1[1] = 0;
      if (DAT_00713c94 != (int *)0x0) {
        *(int **)((int)DAT_00713c94 + 4) = piVar1;
      }
      DAT_00713c94 = piVar1;
      iVar2 = FUN_00650c80(local_18,3,0x2d,param_1,uVar4);
      piVar1[6] = iVar2;
      param_1 = param_1 + uVar4;
      piVar1[0xe] = 0x7fff;
      piVar1[0x14] = 0x7fff;
      piVar1[0xc] = 0x1000;
      piVar1[0xd] = 0x1000;
      piVar1[2] = iVar3;
      iVar3 = iVar3 + 1;
      local_1c = local_1c + 0x60;
      piVar1[0xf] = 0;
      piVar1[0x10] = 0;
      piVar1[0x11] = 0;
      piVar1[0x12] = 0xffff;
      piVar1[0x13] = 0;
    } while (iVar3 < param_3);
  }
  FUN_0064c5a0(FUN_0064f0e0);
  SNDSYS_leavecritical();
  iVar3 = SNDSTRM_overhead(3,0x2d);
  return uVar4 - iVar3;
}


// ==== 0x64f4b0 FUN_0064f4b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0064f4b0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_00713ce4 == 0) {
    DAT_00713d98 = 0x10;
    DAT_00713dbb = 0x5a;
    DAT_00713dac = 1;
    DAT_00713da8 = 0;
    _DAT_00713da4 = 0xbf800000;
    puVar3 = &DAT_00713d90;
    puVar4 = &DAT_00713e44;
    for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar2 = FUN_00651a40();
    if (iVar2 != 1) {
      DAT_00713ce8 = FUN_00651c40();
    }
    DAT_00713ce4 = 1;
  }
  uVar1 = DAT_00713ce8;
  puVar3 = (undefined4 *)&DAT_00713d70;
  for (iVar2 = 0x35; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return uVar1;
}


// ==== 0x64f530 FUN_0064f530

undefined4 FUN_0064f530(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_1 + 0x20);
  puVar3 = &DAT_00713d90;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(param_1 + 0xc0);
  puVar3 = &DAT_00713e30;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00651c60();
  puVar2 = &DAT_00713d90;
  puVar3 = &DAT_00713e44;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return 0;
}


// ==== 0x64f580 SNDSYSI_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDSYSI_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  s_SNDAUTHOR__Adamchan__Thursday_04_006ea010[0] = 'S';
  if (DAT_00713ee4 != '\0') {
    return 0;
  }
  FUN_00654cd0(param_1,param_2);
  FUN_00650f60(param_1,param_2);
  if (DAT_00713ee8 == 0) {
    iVar1 = FUN_0064f4b0(&DAT_00713d70);
    if (iVar1 < 0) {
      return iVar1;
    }
    FUN_0064f530(&DAT_00713d70);
  }
  FUN_00651150(DAT_00713d94);
  FUN_00652d50();
  DAT_00713ee4 = 1;
  FUN_0064e520();
  DAT_00713f48 = FUN_00650fd0(DAT_00713ee8 * 0x8c);
  DAT_00713f4c = FUN_00650fd0((uint)DAT_00713d98 << 3);
  SNDSYS_leavecritical();
  DAT_00713eec = 0;
  _DAT_006e9bc8 = 0x3f800000;
  DAT_00713eea = 0;
  DAT_00713ee6 = 0;
  DAT_00713ee7 = 0;
  iVar1 = FUN_00654b50();
  if (iVar1 < 0) {
    FUN_00654180();
    FUN_00652d70();
    DAT_00713ee4 = 0;
    return iVar1;
  }
  DAT_00713cdc = DAT_00713db8 + DAT_00713db7;
  if (DAT_00713cdc == '\x01') {
    DAT_00713ce0 = 0;
  }
  else {
    if (DAT_00713cdc == '\x02') {
      DAT_00713ce0 = 1;
      DAT_00713cc8 = 0x42b40000;
      DAT_00713ccc = 0x43870000;
      goto LAB_0064f72e;
    }
    if (DAT_00713cdc == '\x04') {
      DAT_00713ce0 = 2;
      DAT_00713cc8 = 0x42340000;
      DAT_00713ccc = 0x43070000;
      DAT_00713cd0 = 0x43610000;
      _DAT_00713cd4 = 0x439d8000;
      goto LAB_0064f72e;
    }
    if (DAT_00713cdc != '\x06') goto LAB_0064f72e;
    DAT_00713ce0 = 3;
    DAT_00713ccc = 0x42340000;
    DAT_00713cd0 = 0x43070000;
    _DAT_00713cd4 = 0x43610000;
    _DAT_00713cd8 = 0x439d8000;
  }
  DAT_00713cc8 = 0;
LAB_0064f72e:
  if (DAT_00713db7 == '\x02') {
    _DAT_00713f88 = 0xc000;
    _DAT_00713f8a = 0x4000;
  }
  else {
    _DAT_00713f88 = 0xe000;
    _DAT_00713f8a = 0x2000;
  }
  _DAT_00713f94 = DAT_00713e04;
  _DAT_00713f96 = DAT_00713e00;
  _DAT_00713f98 = DAT_00713e02;
  _DAT_00713fa0 = 0xe000;
  _DAT_00713fa2 = 0x2000;
  _DAT_00713fa4 = 0xa000;
  _DAT_00713fa6 = 0x6000;
  _DAT_00713fac = 0xe000;
  _DAT_00713fae = 0;
  _DAT_00713fb0 = 0x2000;
  _DAT_00713fb2 = 0xa000;
  _DAT_00713fb4 = 0x6000;
  _DAT_00713fb8 = 0xe000;
  _DAT_00713fba = 0;
  _DAT_00713fbc = 0x2000;
  _DAT_00713fbe = 0xa000;
  _DAT_00713fc0 = 0x6000;
  _DAT_00713fc2 = 0;
  FUN_00652fd0();
  return 0;
}


// ==== 0x64f810 FUN_0064f810

int FUN_0064f810(void)

{
  return (int)DAT_00713ee4;
}


// ==== 0x64f820 SNDSYS_shutdown__map:_SNDSYS_restore_

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDSYS_shutdown__map__SNDSYS_restore_(void)

{
  undefined4 uVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff2;
  }
  FUN_00654f00(0,0,0,0xffffffff,0xffffffff);
  if (DAT_00713f30 != (code *)0x0) {
    (*DAT_00713f30)();
  }
  if (DAT_00713f34 != (code *)0x0) {
    (*DAT_00713f34)();
  }
  if (DAT_00713f38 != (code *)0x0) {
    (*DAT_00713f38)();
  }
  if (DAT_00713f44 != (code *)0x0) {
    (*DAT_00713f44)();
  }
  if (DAT_00713f40 != (code *)0x0) {
    (*DAT_00713f40)();
  }
  FUN_00653420();
  FUN_00654de0();
  if (DAT_00713f3c != (code *)0x0) {
    (*DAT_00713f3c)(0xffffffff);
  }
  FUN_00654180();
  FUN_0064e520();
  FUN_006510d0(DAT_00713f48);
  FUN_006510d0(DAT_00713f4c);
  SNDSYS_leavecritical();
  uVar1 = SNDMEMI_usage_percent__map__SNDMEMI_restore_();
  DAT_00713ee4 = 0;
  FUN_00652d70();
  return uVar1;
}


// ==== 0x64f8e0 FUN_0064f8e0

undefined4 FUN_0064f8e0(void)

{
  undefined4 uVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0;
  }
  uVar1 = FUN_00654fe0();
  return uVar1;
}


// ==== 0x64f900 FUN_0064f900

undefined4 FUN_0064f900(uint param_1,undefined4 *param_2)

{
  ushort uVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = param_2;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  if (-1 < (int)param_1) {
    iVar5 = FUN_00650020(param_1 & 0xff);
    if (iVar5 != 0) {
      iVar6 = FUN_00655000(param_1);
      if (iVar6 == 0) {
        *param_2 = 3;
        return 0;
      }
      if (*(char *)(iVar6 + 0x24) == '\0') {
        *param_2 = 0;
        return 0;
      }
      if (*(int *)(iVar5 + 0x140) == iVar6) {
        *param_2 = 2;
        uVar1 = *(ushort *)(iVar5 + 0x38);
      }
      else {
        *param_2 = 1;
        uVar1 = *(ushort *)(iVar5 + 0x3c);
      }
      param_2 = (undefined4 *)(uint)uVar1;
      fVar2 = 1000.0 / (float)(int)param_2;
      fVar3 = (float)*(int *)(iVar6 + 0x14);
      if (*(int *)(iVar6 + 0x14) < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      puVar4[1] = (int)ROUND(fVar3 * fVar2);
      iVar5 = *(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14);
      fVar3 = (float)iVar5;
      if (iVar5 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      puVar4[2] = (int)ROUND(fVar3 * fVar2);
      fVar3 = (float)*(int *)(iVar6 + 0x1c);
      if (*(int *)(iVar6 + 0x1c) < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      puVar4[3] = (int)ROUND(fVar3 * fVar2);
      return 0;
    }
  }
  return 0xfffffff8;
}


// ==== 0x64fa60 FUN_0064fa60

undefined4 FUN_0064fa60(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  puVar1 = (undefined4 *)FUN_00650020(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = puVar1[0x52];
    *param_2 = iVar2;
    if ((iVar2 != 0) && (param_2[1] = *(int *)(puVar1[0x50] + 0xc), *(short *)(puVar1 + 0xe) != 0))
    {
      iVar2 = FUN_00655660(puVar1[2]);
      uVar3 = (uint)(iVar2 * 1000) / (uint)*(ushort *)(puVar1 + 0xe);
      param_2[2] = uVar3;
      if ((uVar3 == 0) && (iVar2 = FUN_00655000(param_2[1]), *(int *)(iVar2 + 0x10) != 0)) {
        uVar3 = FUN_00412f70(*puVar1);
        if (4000000 < uVar3) {
          uVar3 = 4000000;
        }
        param_2[2] = (uVar3 * 1000) / *(uint *)(iVar2 + 0x10);
      }
    }
    return 0;
  }
  return 0xfffffff8;
}


// ==== 0x64fb30 FUN_0064fb30

void FUN_0064fb30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  SNDSTRMI_queue(param_1,param_2,0,param_3,2);
  return;
}


// ==== 0x64fb50 FUN_0064fb50

void FUN_0064fb50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  SNDSTRMI_create(param_2,param_3,param_4,param_5,param_6,param_1,1);
  return;
}


// ==== 0x64fb80 FUN_0064fb80

int FUN_0064fb80(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00655040(param_2);
  return iVar1 + 0x234 + param_1 * 0x28;
}


// ==== 0x64fba0 SNDSTRM_overhead

/* [canon] audio med (ghidra) docs/re/sound.md */

int SNDSTRM_overhead(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00655040(param_2);
  iVar2 = SNDSTRM_OverheadBytes(param_1 + 2,1,1);
  return iVar2 + iVar1 + 0x234 + param_1 * 0x28;
}


// ==== 0x64fbd0 SNDplaysetdef

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDplaysetdef(undefined1 *param_1)

{
  *(undefined2 *)(param_1 + 0xc) = 0x1000;
  *(undefined2 *)(param_1 + 0xe) = 0x1000;
  *(undefined2 *)(param_1 + 0x10) = 0x1000;
  param_1[2] = 0x3c;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0xffff;
  *(undefined2 *)(param_1 + 0x16) = 0;
  param_1[3] = 0x7f;
  *param_1 = 0x7f;
  param_1[4] = 0x7f;
  param_1[1] = 0x40;
  param_1[5] = 0x7f;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  return 0;
}


// ==== 0x64fc20 FUN_0064fc20

void FUN_0064fc20(int param_1)

{
  int *piVar1;
  
  if (*(float *)(param_1 + 0x17c) != 0.0) {
    piVar1 = (int *)(param_1 + 0x168);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 0x16c) != (int *)0x0) {
      **(int **)(param_1 + 0x16c) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x16c);
    }
  }
  if (*(float *)(param_1 + 0x1a0) != 0.0) {
    piVar1 = (int *)(param_1 + 0x18c);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 400) != (int *)0x0) {
      **(int **)(param_1 + 400) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 400);
    }
  }
  if (*(float *)(param_1 + 0x1c4) != 0.0) {
    piVar1 = (int *)(param_1 + 0x1b0);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 0x1b4) != (int *)0x0) {
      **(int **)(param_1 + 0x1b4) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x1b4);
    }
  }
  if (*(float *)(param_1 + 0x1e8) != 0.0) {
    piVar1 = (int *)(param_1 + 0x1d4);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 0x1d8) != (int *)0x0) {
      **(int **)(param_1 + 0x1d8) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x1d8);
    }
  }
  if (*(float *)(param_1 + 0x20c) != 0.0) {
    piVar1 = (int *)(param_1 + 0x1f8);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 0x1fc) != (int *)0x0) {
      **(int **)(param_1 + 0x1fc) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x1fc);
    }
  }
  if (*(float *)(param_1 + 0x230) != 0.0) {
    piVar1 = (int *)(param_1 + 0x21c);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_1 + 0x220) != (int *)0x0) {
      **(int **)(param_1 + 0x220) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x220);
    }
  }
  return;
}


// ==== 0x64fdc0 SNDSTRMI_startstream

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void SNDSTRMI_startstream(int param_1)

{
  float *pfVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  uVar5 = SNDPKTPLAY_start(*(undefined4 *)(param_1 + 8),param_1 + 0x38,param_1 + 0x40,
                           param_1 + 0x110);
  *(undefined4 *)(param_1 + 4) = uVar5;
  iVar6 = SNDVOICEI_get__validate_handle____voice_index_(*(undefined4 *)(param_1 + 4));
  uVar9 = 0;
  if (*(char *)(param_1 + 0x3a) != '\0') {
    iVar8 = iVar6 * 0x8c + 4;
    do {
      sVar3 = *(short *)(iVar8 + DAT_00713f48);
      iVar7 = sVar3 * 0x8c + DAT_00713f48;
      fVar2 = *(float *)(param_1 + 0x164 +
                        *(char *)(uVar9 + 0x6aa9be + (uint)*(byte *)(param_1 + 0x3a) * 6) * 0x24);
      *(float *)(iVar7 + 0x38) = fVar2;
      *(float *)(iVar7 + 0x48) = fVar2 * _DAT_006e9bc8;
      Snd__Hal__SetVol__SNDPLATFORM_setvol_((int)sVar3);
      uVar9 = uVar9 + 1;
      iVar8 = iVar8 + 2;
    } while (uVar9 < *(byte *)(param_1 + 0x3a));
  }
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar9 = (uint)*(byte *)(param_1 + 0x3a);
    iVar8 = DAT_00713ce0 * 6;
    uVar10 = 0;
    if (uVar9 != 0) {
      iVar6 = iVar6 * 0x8c + 4;
      do {
        sVar3 = *(short *)(DAT_00713f48 + iVar6);
        iVar7 = sVar3 * 0x8c + DAT_00713f48;
        pfVar1 = (float *)(param_1 + 0x15c +
                          *(char *)(uVar10 + 0x6aa9be + (uint)*(byte *)(param_1 + 0x3a) * 6) * 0x24)
        ;
        if (*pfVar1 == -1e+06) {
          *(ushort *)(iVar7 + 0x1c) =
               (ushort)(byte)(&DAT_006aaa32)[uVar10 + (uVar9 + iVar8) * 6] << 8;
        }
        else {
          sVar4 = (short)(int)ROUND(*pfVar1 * 182.04445);
          *(short *)(iVar7 + 0x1c) = sVar4;
          if (*(char *)(pfVar1 + 1) == '\0') {
            *(ushort *)(iVar7 + 0x1c) =
                 (ushort)(byte)(&DAT_006aaac2)[uVar10 + uVar9 * 6] * 0x100 + sVar4;
          }
        }
        FUN_006513b0((int)sVar3);
        uVar10 = uVar10 + 1;
        iVar6 = iVar6 + 2;
      } while (uVar10 < *(byte *)(param_1 + 0x3a));
    }
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    FUN_006559d0(*(undefined4 *)(param_1 + 4),param_1 + 0x128);
  }
  if (*(char *)(param_1 + 0x13) != '\0') {
    FUN_00655960(*(undefined4 *)(param_1 + 4),param_1 + 0x14);
  }
  *(undefined1 *)(param_1 + 0x10) = 1;
  return;
}


// ==== 0x64ff90 FUN_0064ff90

int FUN_0064ff90(ushort *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *(char *)((int)param_1 + 3);
  iVar2 = (uint)*param_1 * (uint)(byte)param_1[1];
  iVar3 = 0;
  if (cVar1 == '\n') {
    iVar3 = 0x88;
  }
  else {
    if (cVar1 == '\x04') {
      return iVar2 * 0x33 >> 8;
    }
    if (cVar1 == '\x16') {
      return iVar2 * 0x66 >> 8;
    }
    if (cVar1 == '\t') {
      return iVar2 * 0x100 >> 8;
    }
    if (cVar1 == '\b') {
      return iVar2 * 0x200 >> 8;
    }
    if ((cVar1 == '\x10') || (cVar1 == '\x17')) {
      return (uint)(byte)param_1[1] * 8;
    }
  }
  return iVar2 * iVar3 >> 8;
}


// ==== 0x650020 FUN_00650020

undefined4 FUN_00650020(int param_1)

{
  if ((param_1 < (int)(uint)DAT_00713db6) && (-1 < param_1)) {
    return (&DAT_00713cf0)[param_1];
  }
  return 0;
}


// ==== 0x650040 FUN_00650040

void FUN_00650040(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_00713cf0)[param_1 & 0xff];
  iVar2 = FUN_00655000(param_1);
  FUN_00655b40(iVar1 + 0x140,iVar2);
  FUN_00655ab0(iVar1 + 0x14c,iVar2);
  if (*(int *)(iVar1 + 0x158) == iVar2) {
    *(undefined4 *)(iVar1 + 0x158) = 0;
  }
  return;
}


// ==== 0x6500a0 FUN_006500a0

void FUN_006500a0(int param_1)

{
  undefined4 uStack00000008;
  
  uStack00000008 = *(undefined4 *)(param_1 + -4);
  FUN_00412ee0();
  return;
}


// ==== 0x6500d0 FUN_006500d0

void FUN_006500d0(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_3 + 0x140);
  iVar4 = 1;
  while( true ) {
    uVar3 = param_2;
    uVar5 = 0;
    if (*(uint *)(iVar2 + 0x1c) < param_2) {
      uVar5 = param_2 - *(int *)(iVar2 + 0x1c);
      uVar3 = param_2 - uVar5;
    }
    param_2 = uVar5;
    *(uint *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + uVar3;
    *(uint *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) - uVar3;
    if (*(uint *)(iVar2 + 0x18) <= *(uint *)(iVar2 + 0x14)) {
      iVar1 = (&DAT_00713cf0)[*(uint *)(iVar2 + 0xc) & 0xff];
      iVar2 = FUN_00655000(*(uint *)(iVar2 + 0xc));
      FUN_00655b40(iVar1 + 0x140,iVar2);
      FUN_00655ab0(iVar1 + 0x14c,iVar2);
      if (*(int *)(iVar1 + 0x158) == iVar2) {
        *(undefined4 *)(iVar1 + 0x158) = 0;
      }
    }
    if (param_2 == 0) break;
    iVar2 = *(int *)(param_3 + 0x140);
    iVar4 = iVar4 + 1;
    if (200 < iVar4) {
      FUN_00650040(*(undefined4 *)(iVar2 + 0xc));
      return;
    }
  }
  return;
}


// ==== 0x6501a0 SNDSTRMI_parseheader

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 SNDSTRMI_parseheader(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c [7];
  
  puVar1 = (undefined4 *)(&DAT_00713cf0)[param_1];
  if ((undefined4 *)puVar1[0x56] == (undefined4 *)0x0) {
    puVar1[0x56] = puVar1[0x50];
  }
  else {
    puVar1[0x56] = *(undefined4 *)puVar1[0x56];
  }
  iVar3 = puVar1[0x56];
  SNDI_patchtohdr(0,param_2 + 8,puVar1 + 0xf,puVar1 + 0x2a,local_1c,iVar3 + 0x25);
  piVar5 = puVar1 + 0x3c;
  *(undefined4 *)(iVar3 + 0x18) = local_1c[0];
  *(undefined1 *)(iVar3 + 0x24) = 0;
  iVar4 = *piVar5;
  while (iVar4 != 0) {
    local_30 = 3;
    local_2c = *piVar5;
    local_28 = piVar5[4];
    local_20 = *(undefined4 *)(iVar3 + 0xc);
    iVar4 = 0;
    *piVar5 = 0;
    piVar5[4] = 0;
    piVar5 = piVar5 + 1;
    if ('\0' < DAT_00713eea) {
      do {
        (*(code *)(&DAT_00713f20)[iVar4])(&local_30);
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_00713eea);
    }
    iVar4 = *piVar5;
  }
  FUN_00412ee0(*puVar1,param_2);
  piVar5 = puVar1 + 0xf;
  uVar2 = FUN_0064ff90(piVar5);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  if (puVar1[0xe] == *piVar5) {
    iVar3 = 0x1a;
    bVar10 = true;
    piVar6 = puVar1 + 0x10;
    piVar8 = puVar1 + 0x2a;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *piVar6 == *piVar8;
      piVar6 = piVar6 + 1;
      piVar8 = piVar8 + 1;
    } while (bVar10);
    if ((bVar10) && (puVar1[0x30] == 0)) goto LAB_006502e8;
  }
  if (*(short *)(puVar1 + 0xe) != 0) {
    *(undefined1 *)(puVar1 + 4) = 2;
    return 0;
  }
  iVar3 = *piVar5;
  puVar7 = puVar1 + 0x2a;
  puVar9 = puVar1 + 0x10;
  for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar1[0xe] = iVar3;
  puVar1[0x30] = 0;
LAB_006502e8:
  if (*(char *)(puVar1 + 4) != '\x01') {
    SNDSTRMI_startstream(puVar1);
    *(undefined1 *)(puVar1 + 4) = 1;
  }
  return 0;
}


// ==== 0x650310 FUN_00650310

undefined4 FUN_00650310(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_1[0x56];
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    if (*(int *)(iVar1 + 0x20) < 0) {
      return 1;
    }
    if (*(int *)(iVar1 + 0x20) == 0) {
      return 0;
    }
    uVar2 = FUN_00412f70(*param_1);
    if (4000000 < uVar2) {
      uVar2 = 4000000;
    }
    if (((uVar2 * 1000) / *(uint *)(iVar1 + 0x10) < *(uint *)(iVar1 + 0x20)) &&
       (iVar3 = FUN_00412f90(*param_1), iVar3 != 2)) {
      if (0 < (int)param_1[0x55]) {
        return 1;
      }
      iVar3 = FUN_00412f90(*param_1);
      if (iVar3 != 0) {
        return 1;
      }
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
  }
  return 0;
}


// ==== 0x6503a0 SNDSTRMI_queue

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4
SNDSTRMI_queue(uint param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  if ((((int)(uint)DAT_00713db6 <= (int)param_1) || ((int)param_1 < 0)) ||
     (puVar1 = (undefined4 *)(&DAT_00713cf0)[param_1], puVar1 == (undefined4 *)0x0)) {
    return 0xfffffff8;
  }
  if (puVar1[0x55] == 0) {
    return 0xfffffff3;
  }
  if (param_5 == 0) {
    param_4 = FUN_00412930(*puVar1,param_3,param_4,0x6c454353);
  }
  else if (param_5 == 1) {
    param_4 = FUN_004129f0(*puVar1,param_3,0,0x6c454353);
  }
  if (param_4 != 0) {
    FUN_0064e520();
    iVar3 = FUN_00655b10(puVar1 + 0x53);
    FUN_00654cd0(iVar3,0x28);
    FUN_00655ae0(puVar1 + 0x50,iVar3);
    *(int *)(iVar3 + 8) = param_4;
    puVar1[3] = puVar1[3] + 0x100;
    if ((int)puVar1[3] < 0) {
      puVar1[3] = 0;
    }
    *(uint *)(iVar3 + 0xc) = puVar1[3] | param_1;
    *(undefined4 *)(iVar3 + 0x20) = param_2;
    uVar2 = *(undefined4 *)(iVar3 + 0xc);
    SNDSYS_leavecritical();
    return uVar2;
  }
  return 0xffffffff;
}


// ==== 0x6504b0 FUN_006504b0

undefined4 FUN_006504b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  uVar1 = SNDSTRMI_queue(param_1,param_2,param_3,param_4,0);
  return uVar1;
}


// ==== 0x6504e0 FUN_006504e0

undefined4 FUN_006504e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  FUN_0064e520();
  if (((param_1 < (int)(uint)DAT_00713db6) && (-1 < param_1)) &&
     (puVar1 = (undefined4 *)(&DAT_00713cf0)[param_1], puVar1 != (undefined4 *)0x0)) {
    if (-1 < (int)puVar1[1]) {
      FUN_006558f0(puVar1[2]);
    }
    puVar1[1] = 0xffffffff;
    if (*(char *)((int)puVar1 + 0x11) == '\0') {
      FUN_00412cd0(*puVar1);
    }
    puVar2 = puVar1 + 0x30;
    if ((puVar1[0x30] != 0) && (iVar3 = 0, *(char *)((int)puVar1 + 0x3e) != '\0')) {
      do {
        FUN_006510d0(*puVar2);
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)(uint)*(byte *)((int)puVar1 + 0x3e));
    }
    while( true ) {
      iVar3 = FUN_00655b10(puVar1 + 0x50);
      if (iVar3 == 0) break;
      FUN_00655ab0(puVar1 + 0x53,iVar3);
    }
    puVar1[0x56] = 0;
    *(undefined1 *)(puVar1 + 4) = 0;
    FUN_00654cd0(puVar1 + 0xe,4);
    FUN_00654cd0(puVar1 + 0xf,4);
    FUN_00654cd0(puVar1 + 0x10,0x68);
    FUN_00654cd0(puVar1 + 0x2a,0x68);
    SNDSYS_leavecritical();
    return 0;
  }
  SNDSYS_leavecritical();
  return 0xfffffff8;
}


// ==== 0x6505f0 FUN_006505f0

void FUN_006505f0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_2c;
  undefined1 local_24 [4];
  uint local_20;
  int local_18 [6];
  
  iVar1 = param_1[0x56];
  if (*(char *)(iVar1 + 0x25) == '\0') {
    local_2c = param_2[2];
  }
  else {
    uVar2 = param_2[2];
    local_2c._0_2_ = CONCAT11((char)((uint)uVar2 >> 0x10),(char)((uint)uVar2 >> 0x18));
    local_2c = CONCAT22(CONCAT11((char)uVar2,(char)((uint)uVar2 >> 8)),(undefined2)local_2c);
  }
  local_20 = local_20 ^ (local_20 ^ local_2c) & 0x7fffffff;
  uVar4 = (uint)*(byte *)((int)param_1 + 0x3a);
  iVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*(char *)(iVar1 + 0x25) == '\0') {
        local_2c = *(int *)((int)param_2 + (int)local_18 + iVar3 * 4 + (0xc - (int)local_18));
      }
      else {
        uVar2 = *(undefined4 *)((int)param_2 + (int)local_18 + iVar3 * 4 + (0xc - (int)local_18));
        local_2c._0_2_ = CONCAT11((char)((uint)uVar2 >> 0x10),(char)((uint)uVar2 >> 0x18));
        local_2c = CONCAT13((char)uVar2,CONCAT12((char)((uint)uVar2 >> 8),(undefined2)local_2c));
      }
      local_18[iVar3] = (int)param_2 + local_2c + uVar4 * 4 + 0xc;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar4);
  }
  if ((local_20 & 0x7fffffff) != 0) {
    *(undefined4 **)(local_18[0] + -4) = param_2;
    *param_2 = *(undefined4 *)(iVar1 + 0xc);
    *(uint *)(iVar1 + 0x1c) = (local_20 & 0x7fffffff) + *(int *)(iVar1 + 0x1c);
    local_20 = (uint)*(byte *)(iVar1 + 0x24) << 0x1f | local_20 & 0x7fffffff;
    FUN_00655500(param_1[2],local_24);
    *(undefined1 *)(iVar1 + 0x24) = 1;
    return;
  }
  FUN_00412ee0(*param_1,param_2);
  return;
}


// ==== 0x650730 SNDSTRMI_parsechunk

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall SNDSTRMI_parsechunk(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  FUN_0064e520(param_1);
  iVar9 = 0;
  if (DAT_00713db6 != 0) {
    piVar6 = &DAT_00713cf0;
    do {
      puVar1 = (undefined4 *)*piVar6;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1[0x52] != 0)) {
        if (*(char *)(puVar1 + 4) == '\x02') {
          iVar4 = FUN_00655660(puVar1[2]);
          if (0 < iVar4) goto LAB_0065084f;
          uVar2 = puVar1[2];
          puVar1[0xe] = puVar1[0xf];
          puVar7 = puVar1 + 0x2a;
          puVar8 = puVar1 + 0x10;
          for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar1[0x30] = 0;
          FUN_006558f0(uVar2);
          SNDSTRMI_startstream(puVar1);
        }
        iVar4 = FUN_00650310(puVar1);
        if (iVar4 == 0) {
          if (*(char *)(puVar1 + 4) == '\x01') {
            iVar4 = FUN_00655610(puVar1[2]);
            if (iVar4 < 1) goto LAB_0065084f;
          }
          else {
            iVar4 = 8;
          }
          bVar3 = false;
          do {
            iVar4 = iVar4 + -1;
            piVar5 = (int *)FUN_00412e30(*puVar1);
            if (piVar5 == (int *)0x0) {
              if (!bVar3) break;
            }
            else if (*piVar5 == 0x6c444353) {
              FUN_006505f0((undefined4 *)*piVar6);
              bVar3 = true;
            }
            else {
              if (*piVar5 == 0x6c484353) {
                SNDSTRMI_parseheader(iVar9,piVar5);
                break;
              }
              FUN_00412ee0(*(undefined4 *)*piVar6);
              bVar3 = true;
            }
          } while (0 < iVar4);
        }
      }
LAB_0065084f:
      iVar9 = iVar9 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar9 < (int)(uint)DAT_00713db6);
  }
  SNDSYS_leavecritical();
  return;
}


// ==== 0x650880 SNDSTRMI_service

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDSTRMI_service(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  FUN_0064e520();
  if (((param_1 < (int)(uint)DAT_00713db6) && (-1 < param_1)) &&
     (puVar2 = (undefined4 *)(&DAT_00713cf0)[param_1], puVar2 != (undefined4 *)0x0)) {
    FUN_006504e0(param_1);
    FUN_0064fc20(puVar2);
    iVar5 = 0;
    iVar4 = 0;
    if (DAT_00713db6 != 0) {
      do {
        if ((&DAT_00713cf0)[iVar4] != 0) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)DAT_00713db6);
      if (iVar5 == 1) {
        FUN_0064c5c0(SNDSTRMI_parsechunk);
        DAT_00713f44 = 0;
      }
    }
    FUN_00655690(puVar2[2]);
    uVar3 = *puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x11);
    (&DAT_00713cf0)[param_1] = 0;
    SNDSYS_leavecritical();
    if (cVar1 == '\0') {
      FUN_00412810(uVar3);
    }
    return 0;
  }
  SNDSYS_leavecritical();
  return 0xfffffff8;
}


// ==== 0x650950 SNDSTRMI_service_all__map:_numcreated_

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 SNDSTRMI_service_all__map__numcreated_(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00713db6 != 0) {
    do {
      SNDSTRMI_service(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)DAT_00713db6);
  }
  return 0;
}


// ==== 0x650980 SNDSTRMI_create

/* [canon] audio high (ghidra) docs/re/sound.md */

int SNDSTRMI_create(int *param_1,int param_2,undefined4 param_3,int *param_4,int param_5,int param_6
                   ,int param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *local_10;
  int local_8;
  
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  FUN_0064e520();
  iVar2 = 0;
  if (DAT_00713db6 != 0) {
    do {
      if ((&DAT_00713cf0)[iVar2] == 0) {
        local_10 = param_4 + 0x8d;
        FUN_00654cd0(param_4,0x234);
        piVar6 = local_10 + param_2 * 10;
        iVar3 = FUN_00655040(param_3);
        FUN_00655aa0(param_4 + 0x50);
        FUN_00655aa0(param_4 + 0x53);
        if (0 < param_2) {
          local_8 = param_2;
          do {
            FUN_00655ab0(param_4 + 0x53,local_10);
            local_10 = local_10 + 10;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
        uVar4 = FUN_00655040(param_3);
        iVar5 = FUN_00655060(FUN_006500a0,FUN_006500d0,param_4,piVar6,uVar4);
        param_4[2] = iVar5;
        if (param_4[2] < 0) {
          SNDSYS_leavecritical();
          return param_4[2];
        }
        if (param_7 == 0) {
          iVar3 = FUN_004124f0(param_2 + 2,1,1,(int)piVar6 + iVar3,
                               (param_5 + param_2 * -0x28 + -0x234) - iVar3);
          if (iVar3 == 0) {
            FUN_00655690(param_4[2]);
            SNDSYS_leavecritical();
            return -9;
          }
          *param_4 = iVar3;
          *(undefined1 *)((int)param_4 + 0x11) = 0;
        }
        else {
          *param_4 = param_6;
          *(undefined1 *)((int)param_4 + 0x11) = 1;
        }
        iVar5 = 0;
        param_4[3] = 0;
        param_4[1] = -1;
        piVar6 = param_1;
        piVar7 = param_4 + 0x44;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar7 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar7 = piVar7 + 1;
        }
        iVar3 = *param_1;
        *(undefined1 *)((int)param_4 + 0x161) = 0;
        *(undefined1 *)(param_4 + 0x58) = 0;
        param_4[0x57] = -0x368bdc00;
        *(undefined1 *)((int)param_4 + 0x185) = 1;
        *(undefined1 *)(param_4 + 0x61) = 0;
        fVar1 = (float)(int)(char)iVar3 * 0.007874016;
        param_4[0x60] = -0x368bdc00;
        *(undefined1 *)((int)param_4 + 0x1a9) = 2;
        param_4[0x59] = (int)fVar1;
        *(undefined1 *)(param_4 + 0x6a) = 0;
        param_4[0x62] = (int)fVar1;
        param_4[0x69] = -0x368bdc00;
        param_4[0x6b] = (int)fVar1;
        param_4[0x72] = -0x368bdc00;
        param_4[0x74] = (int)fVar1;
        *(undefined1 *)((int)param_4 + 0x1cd) = 3;
        *(undefined1 *)(param_4 + 0x73) = 0;
        param_4[0x7d] = (int)fVar1;
        *(undefined1 *)((int)param_4 + 0x1f1) = 4;
        param_4[0x86] = (int)fVar1;
        *(undefined1 *)(param_4 + 0x7c) = 0;
        param_4[0x7b] = -0x368bdc00;
        param_4[0x84] = -0x368bdc00;
        *(undefined1 *)((int)param_4 + 0x215) = 5;
        *(undefined1 *)(param_4 + 0x85) = 0;
        *(undefined1 *)((int)param_4 + 0x12) = 1;
        *(undefined1 *)((int)param_4 + 0x13) = 0;
        iVar3 = 0;
        if (DAT_00713db6 != 0) {
          do {
            if ((&DAT_00713cf0)[iVar3] != 0) {
              iVar5 = iVar5 + 1;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)(uint)DAT_00713db6);
          if (iVar5 != 0) goto LAB_00650c1c;
        }
        FUN_0064c5a0(SNDSTRMI_parsechunk);
        DAT_00713f44 = SNDSTRMI_service_all__map__numcreated_;
LAB_00650c1c:
        (&DAT_00713cf0)[iVar2] = param_4;
        if (param_7 == 0) {
          iVar3 = FUN_00412fe0(*param_4);
          FUN_00656000(iVar2,iVar3 / 3);
        }
        param_4[0x30] = 0;
        FUN_006504e0(iVar2);
        SNDSYS_leavecritical();
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)DAT_00713db6);
  }
  SNDSYS_leavecritical();
  return -9;
}


// ==== 0x650c80 FUN_00650c80

void FUN_00650c80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  SNDSTRMI_create(param_1,param_2,param_3,param_4,param_5,0,0);
  return;
}


// ==== 0x650cb0 FUN_00650cb0

undefined4 FUN_00650cb0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar1 = FUN_00650020(param_1);
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  if (0x4000 < param_2) {
    param_2 = 0x4000;
  }
  *(short *)(iVar1 + 0x11c) = (short)param_2;
  SNDpitchmult(*(undefined4 *)(iVar1 + 4),param_2);
  return 0;
}


// ==== 0x650d00 FUN_00650d00

undefined4 FUN_00650d00(undefined4 param_1,short param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xfffffff8;
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  FUN_0064e520();
  iVar1 = FUN_00655000(param_1);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x20) = (int)param_2;
    uVar2 = 0;
  }
  SNDSYS_leavecritical();
  return uVar2;
}


// ==== 0x650d40 FUN_00650d40

void __fastcall FUN_00650d40(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  
  *(undefined4 *)(param_2 + 8) = param_3;
  if (*(float *)(param_2 + 0x20) != 0.0) {
    piVar1 = (int *)(param_2 + 0xc);
    if (piVar1 == DAT_00713ca8) {
      DAT_00713ca8 = (int *)*DAT_00713ca8;
    }
    if (*(int **)(param_2 + 0x10) != (int *)0x0) {
      **(int **)(param_2 + 0x10) = *piVar1;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  return;
}


// ==== 0x650d90 FUN_00650d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00650d90(undefined4 param_1,int param_2,float param_3)

{
  float fVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  
  if (DAT_00713ee4 == '\0') {
    return 0xfffffff6;
  }
  iVar4 = FUN_00650020(param_1);
  if (iVar4 != 0) {
    if (param_2 == -1) {
      iVar7 = 6;
      do {
        FUN_00650d40(param_3);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    else {
      FUN_00650d40(param_3);
    }
    iVar4 = SNDVOICEI_get__validate_handle____voice_index_(*(undefined4 *)(iVar4 + 4));
    if (-1 < iVar4) {
      iVar7 = iVar4 * 0x8c;
      if (param_2 == -1) {
        iVar8 = iVar7 + DAT_00713f48;
        bVar3 = false;
        iVar6 = 0;
        if (*(char *)(iVar7 + 0x23 + DAT_00713f48) != '\0') {
          psVar9 = (short *)(iVar8 + 4);
          do {
            sVar2 = *psVar9;
            iVar7 = sVar2 * 0x8c;
            iVar5 = iVar7 + DAT_00713f48;
            if (*(float *)(iVar7 + 0x38 + DAT_00713f48) != param_3) {
              *(float *)(iVar5 + 0x38) = param_3;
              bVar3 = true;
              *(float *)(iVar5 + 0x48) = _DAT_006e9bc8 * param_3;
              Snd__Hal__SetVol__SNDPLATFORM_setvol_((int)sVar2);
            }
            iVar6 = iVar6 + 1;
            psVar9 = psVar9 + 1;
          } while (iVar6 < (int)(uint)*(byte *)(iVar8 + 0x23));
          if ((bVar3) && (0 < *(short *)(iVar8 + 0x62))) {
            SNDPLATFORM_setfxlevel__map__SNDstop_(iVar4,0);
            return 0;
          }
        }
      }
      else {
        iVar6 = iVar7 + DAT_00713f48;
        if ((char)(&DAT_006aa9e2)[(uint)*(byte *)(iVar7 + 0x23 + DAT_00713f48) * 6 + param_2] !=
            -0x80) {
          iVar8 = (int)*(short *)(iVar6 + 4 +
                                 (char)(&DAT_006aa9e2)
                                       [(uint)*(byte *)(iVar7 + 0x23 + DAT_00713f48) * 6 + param_2]
                                 * 2);
          iVar7 = iVar8 * 0x8c;
          fVar1 = *(float *)(iVar7 + 0x38 + DAT_00713f48);
          iVar7 = iVar7 + DAT_00713f48;
          *(undefined4 *)(iVar7 + 0x30) = 0;
          if (fVar1 != param_3) {
            *(float *)(iVar7 + 0x38) = param_3;
            *(float *)(iVar7 + 0x48) = _DAT_006e9bc8 * param_3;
            Snd__Hal__SetVol__SNDPLATFORM_setvol_(iVar8);
            if (0 < *(short *)(iVar6 + 0x62)) {
              SNDPLATFORM_setfxlevel__map__SNDstop_(iVar4,0);
            }
          }
        }
      }
    }
    return 0;
  }
  return 0xfffffff8;
}


// ==== 0x650f40 FUN_00650f40

void FUN_00650f40(undefined4 param_1,int param_2)

{
  FUN_00650d90(param_1,0xffffffff,(float)param_2 * 0.007874016);
  return;
}


// ==== 0x650f60 FUN_00650f60

void FUN_00650f60(uint *param_1,uint param_2)

{
  DAT_00713f78 = param_1;
  param_1[2] = param_2;
  DAT_00713f78[1] = (int)param_1 + (param_2 - 8);
  *DAT_00713f78 = (uint)(param_1 + 6);
  *DAT_00713f78 = *DAT_00713f78 + 0xf;
  *DAT_00713f78 = *DAT_00713f78 & 0xfffffff0;
  DAT_00713f78[3] = param_2 - 0x2f;
  DAT_00713f78[4] = param_2 - 0xf;
  return;
}


// ==== 0x650fc0 SNDMEMI_usage_percent__map:_SNDMEMI_restore_

int SNDMEMI_usage_percent__map__SNDMEMI_restore_(void)

{
  if (DAT_00713ee4 == '\0') {
    return -10;
  }
  return ((*(int *)(DAT_00713f78 + 8) - *(int *)(DAT_00713f78 + 0x10)) * 100) /
         *(int *)(DAT_00713f78 + 8);
}


// ==== 0x650fd0 FUN_00650fd0

int FUN_00650fd0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0xfU & 0xfffffff0;
  iVar3 = 0;
  if (DAT_00713f78[5] == 0) {
    iVar5 = DAT_00713f78[3];
    iVar4 = 0;
  }
  else {
    iVar3 = 0;
    if (DAT_00713f78[5] < 0) {
      piVar2 = (int *)DAT_00713f78[1];
      do {
        if (iVar3 == 0) {
          iVar5 = *piVar2;
          iVar4 = 0;
        }
        else {
          iVar4 = piVar2[iVar3 * 2 + 3] + piVar2[iVar3 * 2 + 2];
          iVar5 = piVar2[iVar3 * 2] - iVar4;
        }
        if ((uint)DAT_00713f78[3] < (uint)(iVar5 + iVar4)) {
          iVar5 = DAT_00713f78[3] - iVar4;
        }
        if ((int)uVar6 <= iVar5) {
          for (iVar5 = DAT_00713f78[5]; iVar5 < iVar3; iVar5 = iVar5 + 1) {
            puVar1 = (undefined4 *)(DAT_00713f78[1] + iVar5 * 8);
            *puVar1 = *(undefined4 *)(DAT_00713f78[1] + 8 + iVar5 * 8);
            puVar1[1] = puVar1[3];
          }
          goto LAB_0065108d;
        }
        iVar3 = iVar3 + -1;
      } while (DAT_00713f78[5] < iVar3);
    }
    iVar4 = *(int *)(DAT_00713f78[1] + iVar3 * 8 + 0xc) + *(int *)(DAT_00713f78[1] + 8 + iVar3 * 8);
    iVar5 = DAT_00713f78[3] - iVar4;
  }
  if (iVar5 < (int)uVar6) {
    return 0;
  }
LAB_0065108d:
  piVar2 = (int *)(DAT_00713f78[1] + iVar3 * 8);
  *piVar2 = iVar4;
  piVar2[1] = uVar6;
  DAT_00713f78[5] = DAT_00713f78[5] + -1;
  DAT_00713f78[3] = DAT_00713f78[3] + -8;
  iVar3 = *DAT_00713f78;
  iVar5 = (DAT_00713f78[3] - iVar4) - uVar6;
  if (iVar5 < DAT_00713f78[4]) {
    DAT_00713f78[4] = iVar5;
  }
  return iVar3 + iVar4;
}


