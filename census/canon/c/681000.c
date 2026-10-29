// ==== 0x681043 FUN_00681043

undefined4 FUN_00681043(void)

{
  return 1;
}


// ==== 0x681047 FUN_00681047

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00681047(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x68104f;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x40);
  iVar4 = *(int *)(unaff_EBP + -0x48);
  *(int *)(puVar6 + -4) = iVar4 * 2;
  *(undefined4 *)(puVar6 + -8) = 0x681068;
  pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(int *)(puVar6 + -4) = iVar4;
    *(void **)(puVar6 + -8) = pvVar2;
    *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(puVar6 + -0x14) = 1;
    *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar5 = puVar6 + -0x1c;
    *(undefined4 *)(puVar6 + -0x1c) = 0x681089;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                                *(LPCSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),
                                *(LPWSTR *)(puVar6 + -8),*(int *)(puVar6 + -4));
    puVar6 = puVar5;
    if (iVar3 != 0) {
      *(int *)(puVar5 + -4) = iVar4;
      *(void **)(puVar5 + -8) = pvVar2;
      *(undefined4 *)(puVar5 + -0xc) = uVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x44);
      *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x1c;
      *(undefined4 *)(puVar5 + -0x1c) = 0x68109f;
      iVar4 = CompareStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                             *(PCNZWCH *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                             *(PCNZWCH *)(puVar5 + -8),*(int *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x28) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      *(void **)(puVar6 + -4) = pvVar2;
      *(undefined4 *)(puVar6 + -8) = 0x6810ae;
      _free(*(void **)(puVar6 + -4));
    }
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x44);
    *(undefined4 *)(puVar6 + -8) = 0x6810bd;
    _free(*(void **)(puVar6 + -4));
  }
  *(undefined4 *)(unaff_EBP + -0x60) = 0x681182;
  *(undefined4 *)(unaff_EBP + -100) = 0x681187;
  return *(undefined4 *)(unaff_EBP + -0x28);
}


// ==== 0x681188 findenv

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2003 Release */

int __cdecl findenv(uchar *param_1)

{
  int iVar1;
  int *piVar2;
  size_t unaff_EDI;
  
  piVar2 = DAT_00717aa8;
  while( true ) {
    if ((uchar *)*piVar2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_00717aa8 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*piVar2,unaff_EDI);
    if ((iVar1 == 0) &&
       ((*(char *)(unaff_EDI + *piVar2) == '=' || (*(char *)(unaff_EDI + *piVar2) == '\0')))) break;
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_00717aa8 >> 2;
}


// ==== 0x6811d5 copy_environ

/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 2003 Release */

undefined4 * __cdecl copy_environ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  int *unaff_EDI;
  
  iVar5 = 0;
  if (unaff_EDI != (int *)0x0) {
    iVar1 = *unaff_EDI;
    piVar2 = unaff_EDI;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    pcVar4 = (char *)*unaff_EDI;
    puVar6 = puVar3;
    while (pcVar4 != (char *)0x0) {
      pcVar4 = __strdup(pcVar4);
      *puVar6 = pcVar4;
      puVar6 = puVar6 + 1;
      unaff_EDI = unaff_EDI + 1;
      pcVar4 = (char *)*unaff_EDI;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}


// ==== 0x681236 FUN_00681236

undefined4 FUN_00681236(uchar *param_1,int param_2)

{
  uchar *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  LPCSTR lpName;
  BOOL BVar5;
  int *piVar6;
  bool bVar7;
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == (uchar *)0x0) {
    return 0xffffffff;
  }
  puVar1 = __mbschr(param_1,0x3d);
  if (puVar1 == (uchar *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = puVar1[1] == '\0';
  if (DAT_00717aa8 == DAT_00717aac) {
    DAT_00717aa8 = (int *)copy_environ();
  }
  if (DAT_00717aa8 == (int *)0x0) {
    if ((param_2 != 0) && (DAT_00717ab0 != (undefined4 *)0x0)) {
      iVar2 = FUN_00679330();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      goto LAB_006812e0;
    }
    if (!bVar7) {
      DAT_00717aa8 = _malloc(4);
      if (DAT_00717aa8 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_00717aa8 = 0;
      if (DAT_00717ab0 == (undefined4 *)0x0) {
        DAT_00717ab0 = _malloc(4);
        if (DAT_00717ab0 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_00717ab0 = 0;
      }
      goto LAB_006812e0;
    }
LAB_006813e4:
    local_c = 0;
  }
  else {
LAB_006812e0:
    piVar3 = DAT_00717aa8;
    iVar2 = findenv(param_1);
    if ((iVar2 < 0) || (*piVar3 == 0)) {
      if (bVar7) {
        _free(param_1);
        goto LAB_006813e4;
      }
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      piVar3 = _realloc(piVar3,iVar2 * 4 + 8);
      if (piVar3 == (int *)0x0) {
        return 0xffffffff;
      }
      (piVar3 + iVar2)[1] = 0;
      piVar3[iVar2] = (int)param_1;
LAB_0068136a:
      DAT_00717aa8 = piVar3;
    }
    else {
      piVar6 = piVar3 + iVar2;
      _free((void *)*piVar6);
      if (bVar7) {
        for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
          *piVar6 = piVar6[1];
          iVar2 = iVar2 + 1;
        }
        piVar3 = _realloc(piVar3,iVar2 << 2);
        if (piVar3 != (int *)0x0) goto LAB_0068136a;
      }
      else {
        *piVar6 = (int)param_1;
      }
    }
    if (param_2 != 0) {
      sVar4 = _strlen((char *)param_1);
      lpName = _malloc(sVar4 + 2);
      if (lpName != (LPCSTR)0x0) {
        _strcpy(lpName,param_1);
        puVar1[(int)lpName - (int)param_1] = '\0';
        BVar5 = SetEnvironmentVariableA
                          (lpName,(LPCSTR)(~-(uint)bVar7 &
                                          (uint)(puVar1 + ((int)lpName - (int)param_1) + 1)));
        if (BVar5 == 0) {
          local_c = 0xffffffff;
        }
        _free(lpName);
      }
    }
    if (bVar7) {
      _free(param_1);
    }
  }
  return local_c;
}


// ==== 0x6813eb __ZeroTail

/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 2003 Release */

undefined4 __ZeroTail(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_2 / 0x20;
  uVar1 = *(uint *)(param_1 + iVar2 * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f));
  while( true ) {
    if (uVar1 != 0) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) break;
    uVar1 = *(uint *)(param_1 + iVar2 * 4);
  }
  return 1;
}


// ==== 0x68141d __IncMan

/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 2003 Release */

void __IncMan(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = ___addl(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (undefined4 *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = ___addl(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}


// ==== 0x68146a __RoundMan

/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 2003 Release */

undefined4 __RoundMan(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = param_2 / 0x20;
  bVar4 = 0x1f - (char)(param_2 % 0x20);
  if (((*(uint *)(param_1 + iVar2 * 4) & 1 << (bVar4 & 0x1f)) != 0) &&
     (iVar3 = __ZeroTail(param_1,param_2), iVar3 == 0)) {
    local_8 = __IncMan(param_1,param_2 + -1);
  }
  puVar1 = (uint *)(param_1 + iVar2 * 4);
  *puVar1 = *puVar1 & -1 << (bVar4 & 0x1f);
  iVar2 = iVar2 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar3 = 3 - iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}


// ==== 0x6814dc __CopyMan

/* Library Function - Single Match
    __CopyMan
   
   Library: Visual Studio 2003 Release */

void __CopyMan(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 3;
  param_1 = param_1 - (int)param_2;
  do {
    *(undefined4 *)(param_1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== 0x6814f7 __IsZeroMan

/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 2003 Release */

undefined4 __IsZeroMan(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return 1;
}


// ==== 0x681510 __ShrMan

/* Library Function - Single Match
    __ShrMan
   
   Library: Visual Studio 2003 Release */

void __ShrMan(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint local_8;
  
  bVar3 = (byte)(param_2 % 0x20);
  iVar2 = 0;
  local_8 = 0;
  do {
    uVar1 = *(uint *)(param_1 + iVar2 * 4);
    *(uint *)(param_1 + iVar2 * 4) = uVar1 >> (bVar3 & 0x1f) | local_8;
    local_8 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = 2;
  puVar4 = (undefined4 *)(param_1 + (2 - param_2 / 0x20) * 4);
  do {
    if (iVar2 < param_2 / 0x20) {
      *(undefined4 *)(param_1 + iVar2 * 4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + iVar2 * 4) = *puVar4;
    }
    iVar2 = iVar2 + -1;
    puVar4 = puVar4 + -1;
  } while (-1 < iVar2);
  return;
}


// ==== 0x68158b __ld12cvt

/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 2003 Release */

undefined4 __ld12cvt(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 local_1c [12];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  local_8 = (uint)*param_1 << 0x10;
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan();
    if (iVar2 != 0) {
LAB_006816a3:
      uVar3 = 0;
      goto LAB_006816a5;
    }
    local_10 = 0;
    local_c = 0;
  }
  else {
    __CopyMan(local_1c,&local_10);
    iVar2 = __RoundMan(&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      local_10 = 0;
      local_c = 0;
    }
    else {
      if (iVar2 < iVar5) {
        if (*param_3 <= iVar5) {
          local_c = 0;
          local_8 = 0;
          local_10 = 0x80000000;
          __ShrMan(&local_10,param_3[3]);
          iVar5 = param_3[5] + *param_3;
          uVar3 = 1;
          goto LAB_006816a5;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar5 = param_3[5] + iVar5;
        __ShrMan(&local_10,param_3[3]);
        goto LAB_006816a3;
      }
      __CopyMan(&local_10,local_1c);
      __ShrMan(&local_10,iVar2 - iVar5);
      __RoundMan(&local_10,param_3[2]);
      __ShrMan(&local_10,param_3[3] + 1);
    }
  }
  iVar5 = 0;
  uVar3 = 2;
LAB_006816a5:
  local_10 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar3;
}


// ==== 0x6816e3 FID_conflict:__ld12tod

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 2003 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt(_Ifp,_D,&DAT_006ec200);
  return IVar1;
}


// ==== 0x6816f9 FID_conflict:__ld12tod

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 2003 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt(_Ifp,_D,&DAT_006ec218);
  return IVar1;
}


// ==== 0x68170f FUN_0068170f

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0068170f(_CRT_DOUBLE *param_1,undefined4 param_2)

{
  uint unaff_retaddr;
  _LDBL12 local_18;
  undefined1 local_c [4];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  FUN_00681af5(&local_18,local_c,param_2,0,0,0,0);
  FID_conflict___ld12tod(&local_18,param_1);
  return;
}


// ==== 0x681752 FUN_00681752

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00681752(_CRT_DOUBLE *param_1,undefined4 param_2)

{
  uint unaff_retaddr;
  _LDBL12 local_18;
  undefined1 local_c [4];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  FUN_00681af5(&local_18,local_c,param_2,0,0,0,0);
  FID_conflict___ld12tod(&local_18,param_1);
  return;
}


// ==== 0x681795 __fptostr

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __fptostr(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *_Dst;
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char cVar4;
  
  _Dst = param_1;
  pcVar3 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar1 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar4 = *pcVar3;
      if (cVar4 == '\0') {
        cVar4 = '0';
      }
      else {
        pcVar3 = pcVar3 + 1;
      }
      *pcVar1 = cVar4;
      pcVar1 = pcVar1 + 1;
      param_1 = (char *)((int)param_1 + -1);
    } while (param_1 != (char *)0x0);
  }
  *pcVar1 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar3)) {
    while (pcVar1 = pcVar1 + -1, *pcVar1 == '9') {
      *pcVar1 = '0';
    }
    *pcVar1 = *pcVar1 + '\x01';
  }
  if (*_Dst == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar2 = _strlen(_Str);
    _memmove(_Dst,_Str,sVar2 + 1);
  }
  return;
}


// ==== 0x68180c ___dtold

/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 2003 Release */

void ___dtold(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  local_8 = 0x80000000;
  uVar3 = uVar1 >> 4;
  uVar4 = uVar3 & 0x7ff;
  uVar2 = *param_2;
  if ((uVar3 & 0x7ff) == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    uVar4 = uVar4 + 0x3c01;
    local_8 = 0;
  }
  else if (uVar4 == 0x7ff) {
    uVar4 = 0x7fff;
  }
  else {
    uVar4 = uVar4 + 0x3c00;
  }
  param_1[1] = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  *param_1 = uVar2 << 0xb;
  while (local_8 == 0) {
    uVar2 = param_1[1];
    uVar4 = uVar4 - 1;
    param_1[1] = uVar2 << 1 | *param_1 >> 0x1f;
    *param_1 = *param_1 * 2;
    local_8 = uVar2 << 1 & 0x80000000;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | uVar4;
  return;
}


// ==== 0x6818c6 __fltout2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int * __fltout2(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint unaff_retaddr;
  short local_30;
  char local_2e;
  undefined1 local_2c [24];
  undefined4 local_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  ___dtold(&local_14,&param_1);
  iVar3 = FUN_00682466(local_14,uStack_10,uStack_c,0x11,0,&local_30);
  iVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2e;
  param_3[1] = (int)local_30;
  _strcpy(param_4,local_2c);
  piVar1[3] = iVar2;
  return piVar1;
}


// ==== 0x681938 FUN_00681938

void FUN_00681938(void)

{
  __amsg_exit(2);
  return;
}


// ==== 0x681941 FUN_00681941

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00681941(int param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  uint unaff_retaddr;
  undefined4 uVar2;
  uint local_94;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  
  local_14 = DAT_006eb720 ^ unaff_retaddr;
  local_94 = (uint)*param_3;
  iVar1 = *param_2;
  if (iVar1 == 1) {
LAB_0068199c:
    uVar2 = 8;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else if (iVar1 == 3) {
    uVar2 = 0x11;
  }
  else if (iVar1 == 4) {
    uVar2 = 0x12;
  }
  else {
    if (iVar1 == 5) goto LAB_0068199c;
    if (iVar1 == 7) {
      *param_2 = 1;
      goto LAB_006819f8;
    }
    if (iVar1 != 8) goto LAB_006819f8;
    uVar2 = 0x10;
  }
  iVar1 = FUN_0067aba0(uVar2,param_2 + 6,local_94);
  if (iVar1 == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_60 = *(undefined8 *)(param_2 + 4);
      local_50 = local_50 & 0xffffffe3 | 3;
    }
    else {
      local_50 = local_50 & 0xfffffffe;
    }
    __raise_exc(local_90,&local_94,uVar2,param_1,param_2 + 2,param_2 + 6);
  }
LAB_006819f8:
  __ctrlfp(local_94,0xffff);
  if (((*param_2 != 8) && (DAT_006ec230 == 0)) && (iVar1 = FUN_0067ef25(param_2), iVar1 != 0)) {
    return;
  }
  FID_conflict___set_errno_from_matherr(*param_2);
  return;
}


// ==== 0x681a3f FUN_00681a3f

int FUN_00681a3f(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
  }
  if ((DAT_00717ef4 != (_func_int *)0x0) && (iVar2 = _ValidateExecute(DAT_00717ef4), iVar2 != 0)) {
    iVar2 = (*DAT_00717ef4)(param_1);
    return iVar2;
  }
  return 0;
}


// ==== 0x681a85 FUN_00681a85

undefined4 FUN_00681a85(void)

{
  DAT_00717ef4 = SetUnhandledExceptionFilter(FUN_00681a3f);
  return 0;
}


// ==== 0x681a98 FUN_00681a98

void FUN_00681a98(void)

{
  SetUnhandledExceptionFilter(DAT_00717ef4);
  return;
}


// ==== 0x681aa5 FID_conflict:_ValidateRead

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 2003 Release */

bool FID_conflict__ValidateRead(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


// ==== 0x681ac1 FID_conflict:_ValidateRead

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 2003 Release */

bool FID_conflict__ValidateRead(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}


// ==== 0x681add _ValidateExecute

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 2003 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== 0x681af5 FUN_00681af5

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00681af5(undefined2 *param_1,int *param_2,byte *param_3,undefined4 param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint unaff_retaddr;
  char local_5c [23];
  char local_45;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined4 local_3a;
  ushort local_36;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  char *local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = 0;
  pcVar5 = local_5c;
  local_30 = 0;
  local_20 = 1;
  local_10 = 0;
  local_18 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_14 = 0;
  local_1c = 0;
  for (pbVar6 = param_3;
      (((bVar3 = *pbVar6, bVar3 == 0x20 || (bVar3 == 9)) || (bVar3 == 10)) ||
      (local_c = pcVar5, bVar3 == 0xd)); pbVar6 = pbVar6 + 1) {
  }
LAB_00681b4f:
  bVar3 = *pbVar6;
  pbVar7 = pbVar6 + 1;
  switch(iVar1) {
  case 0:
    if (('0' < (char)bVar3) && ((char)bVar3 < ':')) {
LAB_00681b6c:
      iVar1 = 3;
      goto LAB_00681d8d;
    }
    if (bVar3 == DAT_006ec184) {
LAB_00681b7b:
      iVar1 = 5;
      pbVar6 = pbVar7;
      goto LAB_00681b4f;
    }
    if (bVar3 == 0x2b) {
      local_30 = 0;
      iVar1 = 2;
      pbVar6 = pbVar7;
      goto LAB_00681b4f;
    }
    if (bVar3 == 0x2d) {
      iVar1 = 2;
      local_30 = 0x8000;
      pbVar6 = pbVar7;
      goto LAB_00681b4f;
    }
    if (bVar3 != 0x30) {
      local_c = pcVar5;
      goto LAB_00681d4b;
    }
    break;
  case 1:
    iVar1 = 1;
    local_18 = 1;
    if (('0' < (char)bVar3) && ((char)bVar3 < ':')) goto LAB_00681b6c;
    if (bVar3 == DAT_006ec184) goto LAB_00681bcd;
    if ((bVar3 == 0x2b) || (bVar3 == 0x2d)) goto LAB_00681c0e;
    pbVar6 = pbVar7;
    if (bVar3 != 0x30) goto LAB_00681be7;
    goto LAB_00681b4f;
  case 2:
    if (('0' < (char)bVar3) && ((char)bVar3 < ':')) goto LAB_00681b6c;
    if (bVar3 == DAT_006ec184) goto LAB_00681b7b;
    pbVar6 = param_3;
    if (bVar3 != 0x30) goto LAB_00681d48;
    break;
  case 3:
    local_18 = 1;
    while (iVar1 = _isdigit((uint)bVar3), iVar1 != 0) {
      if (local_10 < 0x19) {
        local_10 = local_10 + 1;
        *pcVar5 = bVar3 - 0x30;
        pcVar5 = pcVar5 + 1;
      }
      else {
        local_14 = local_14 + 1;
      }
      bVar3 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    }
    if (bVar3 != DAT_006ec184) goto LAB_00681cbd;
LAB_00681bcd:
    iVar1 = 4;
    pbVar6 = pbVar7;
    goto LAB_00681b4f;
  case 4:
    local_18 = 1;
    local_2c = 1;
    if (local_10 == 0) {
      while (bVar3 == 0x30) {
        local_14 = local_14 + -1;
        bVar3 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      }
    }
    while (iVar1 = _isdigit((uint)bVar3), iVar1 != 0) {
      if (local_10 < 0x19) {
        local_10 = local_10 + 1;
        *pcVar5 = bVar3 - 0x30;
        pcVar5 = pcVar5 + 1;
        local_14 = local_14 + -1;
      }
      bVar3 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    }
LAB_00681cbd:
    if ((bVar3 == 0x2b) || (bVar3 == 0x2d)) {
LAB_00681c0e:
      iVar1 = 0xb;
      pbVar6 = pbVar7 + -1;
    }
    else {
LAB_00681be7:
      if (((char)bVar3 < 'D') ||
         (('E' < (char)bVar3 && (((char)bVar3 < 'd' || ('e' < (char)bVar3)))))) {
LAB_00681d47:
        pbVar6 = pbVar7 + -1;
        goto LAB_00681d48;
      }
      iVar1 = 6;
      pbVar6 = pbVar7;
    }
    goto LAB_00681b4f;
  case 5:
    local_2c = 1;
    iVar1 = _isdigit((uint)bVar3);
    pbVar6 = param_3;
    if (iVar1 != 0) {
      iVar1 = 4;
      goto LAB_00681d8d;
    }
    goto LAB_00681d48;
  case 6:
    pbVar6 = pbVar6 + -1;
    param_3 = pbVar6;
    if (((char)bVar3 < '1') || ('9' < (char)bVar3)) {
      if (bVar3 == 0x2b) goto LAB_00681dc2;
      if (bVar3 == 0x2d) goto LAB_00681db6;
      if (bVar3 != 0x30) goto LAB_00681ddc;
      goto LAB_00681d25;
    }
LAB_00681d8b:
    iVar1 = 9;
LAB_00681d8d:
    pbVar6 = pbVar7 + -1;
    goto LAB_00681b4f;
  case 7:
    if (('0' < (char)bVar3) && ((char)bVar3 < ':')) goto LAB_00681d8b;
    pbVar6 = param_3;
    if (bVar3 != 0x30) goto LAB_00681d48;
LAB_00681d25:
    iVar1 = 8;
    pbVar6 = pbVar7;
    goto LAB_00681b4f;
  case 8:
    local_28 = 1;
    while (bVar3 == 0x30) {
      bVar3 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    }
    if (('0' < (char)bVar3) && ((char)bVar3 < ':')) goto LAB_00681d8b;
    goto LAB_00681d47;
  case 9:
    local_28 = 1;
    iVar1 = 0;
    local_c = pcVar5;
    goto LAB_00681e09;
  default:
    goto switchD_00681b5b_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      param_3 = pbVar6;
      if (bVar3 == 0x2b) {
LAB_00681dc2:
        iVar1 = 7;
        pbVar6 = pbVar7;
      }
      else {
        if (bVar3 != 0x2d) {
LAB_00681ddc:
          local_c = pcVar5;
          goto LAB_00681d4b;
        }
LAB_00681db6:
        local_20 = -1;
        iVar1 = 7;
        pbVar6 = pbVar7;
      }
      goto LAB_00681b4f;
    }
    iVar1 = 10;
    pbVar7 = pbVar6;
switchD_00681b5b_caseD_a:
    pbVar6 = pbVar7;
    if (iVar1 != 10) goto LAB_00681b4f;
LAB_00681d48:
    local_c = pcVar5;
    goto LAB_00681d4b;
  }
  iVar1 = 1;
  pbVar6 = pbVar7;
  goto LAB_00681b4f;
LAB_00681e09:
  iVar2 = _isdigit((uint)bVar3);
  if (iVar2 == 0) goto LAB_00681e2c;
  iVar1 = (char)bVar3 + -0x30 + iVar1 * 10;
  if (0x1450 < iVar1) {
    iVar1 = 0x1451;
    goto LAB_00681e2c;
  }
  bVar3 = *pbVar7;
  pbVar7 = pbVar7 + 1;
  goto LAB_00681e09;
LAB_00681e2c:
  while( true ) {
    local_24 = iVar1;
    iVar1 = _isdigit((uint)bVar3);
    if (iVar1 == 0) break;
    bVar3 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    iVar1 = local_24;
  }
  pbVar6 = pbVar7 + -1;
LAB_00681d4b:
  *param_2 = (int)pbVar6;
  if (local_18 == 0) {
    local_1c = 4;
  }
  else {
    pcVar5 = local_c;
    if (0x18 < local_10) {
      if ('\x04' < local_45) {
        local_45 = local_45 + '\x01';
      }
      pcVar5 = local_c + -1;
      local_14 = local_14 + 1;
      local_10 = 0x18;
    }
    if (local_10 != 0) {
      while (pcVar5 = pcVar5 + -1, *pcVar5 == '\0') {
        local_10 = local_10 - 1;
        local_14 = local_14 + 1;
      }
      FUN_00682382(local_5c,local_10,&local_40);
      iVar1 = local_24;
      if (local_20 < 0) {
        iVar1 = -local_24;
      }
      iVar1 = iVar1 + local_14;
      if (local_28 == 0) {
        iVar1 = iVar1 + param_5;
      }
      if (local_2c == 0) {
        iVar1 = iVar1 - param_6;
      }
      if (0x1450 < iVar1) {
        uVar4 = 0;
        local_36 = 0x7fff;
        local_3a = 0x80000000;
        local_40 = 0;
        local_1c = 2;
        goto LAB_00681ed9;
      }
      if (-0x1451 < iVar1) {
        FUN_00682932(&local_40,iVar1,param_4);
        uVar4 = CONCAT22(uStack_3c,uStack_3e);
        goto LAB_00681ed9;
      }
      local_1c = 1;
    }
  }
  local_40 = 0;
  local_36 = 0;
  local_3a = 0;
  uVar4 = 0;
LAB_00681ed9:
  *(undefined4 *)(param_1 + 1) = uVar4;
  *(undefined4 *)(param_1 + 3) = local_3a;
  param_1[5] = local_36 | (ushort)local_30;
  *param_1 = local_40;
  return local_1c;
}


// ==== 0x681f2f FUN_00681f2f

float10 FUN_00681f2f(double param_1)

{
  return (float10)ROUND(param_1);
}


// ==== 0x681f42 FUN_00681f42

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00681f42(int param_1,_locale_t param_2,LPCWSTR param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  size_t _Size;
  DWORD DVar3;
  LPSTR _LpLCData;
  char *_Source;
  char *_Dest;
  int iVar4;
  byte *pbVar5;
  uint unaff_retaddr;
  char local_88 [128];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    pbVar5 = &DAT_00717ef8;
    iVar4 = ___crtGetLocaleInfoW(param_2,param_3,&DAT_00717ef8,4,0);
    if (iVar4 != 0) {
      *param_4 = '\0';
      do {
        bVar1 = *pbVar5;
        iVar4 = _isdigit((uint)bVar1);
        if (iVar4 == 0) {
          return 0;
        }
        pbVar5 = pbVar5 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
      } while ((int)pbVar5 < 0x717f00);
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_88;
  bVar2 = false;
  _Size = ___crtGetLocaleInfoA(param_2,param_3,(LCTYPE)local_88,(LPSTR)0x80,0);
  if (_Size == 0) {
    DVar3 = GetLastError();
    if (DVar3 != 0x7a) {
      return 0xffffffff;
    }
    _LpLCData = (LPSTR)___crtGetLocaleInfoA(param_2,param_3,0,(LPSTR)0x0,0);
    if (_LpLCData == (LPSTR)0x0) {
      return 0xffffffff;
    }
    _Source = _malloc((size_t)_LpLCData);
    if (_Source == (char *)0x0) {
      return 0xffffffff;
    }
    bVar2 = true;
    _Size = ___crtGetLocaleInfoA(param_2,param_3,(LCTYPE)_Source,_LpLCData,0);
    if (_Size == 0) goto LAB_00681ff1;
  }
  _Dest = _malloc(_Size);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,_Size);
    if (bVar2) {
      _free(_Source);
    }
    return 0;
  }
  if (!bVar2) {
    return 0xffffffff;
  }
LAB_00681ff1:
  _free(_Source);
  return 0xffffffff;
}


// ==== 0x682073 __strnicmp

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cdecl __strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  int iVar4;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (_MaxCount == 0) {
    iVar3 = 0;
  }
  else if (ptVar2->lc_category[0].wlocale == (wchar_t *)0x0) {
    iVar3 = ___ascii_strnicmp(_Str1,_Str2,_MaxCount);
  }
  else {
    do {
      iVar3 = FUN_00671395(ptVar2,*_Str1);
      _Str1 = _Str1 + 1;
      iVar4 = FUN_00671395(ptVar2,*_Str2);
      _Str2 = _Str2 + 1;
      _MaxCount = _MaxCount - 1;
      if ((_MaxCount == 0) || (iVar3 == 0)) break;
    } while (iVar3 == iVar4);
    iVar3 = iVar3 - iVar4;
  }
  return iVar3;
}


// ==== 0x6820f2 FUN_006820f2

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_006820f2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  HANDLE hFile;
  BOOL BVar5;
  DWORD *pDVar6;
  DWORD DVar7;
  int iVar8;
  uint unaff_retaddr;
  undefined1 local_1010 [4096];
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar8 = 0;
  local_c = __lseek_lk(param_1,0,1);
  if ((local_c == -1) || (iVar1 = __lseek_lk(param_1,0,2), iVar1 == -1)) {
    iVar8 = -1;
  }
  else {
    iVar1 = param_2 - iVar1;
    if (iVar1 < 1) {
      if (iVar1 < 0) {
        __lseek_lk(param_1,param_2,0);
        hFile = (HANDLE)__get_osfhandle(param_1);
        BVar5 = SetEndOfFile(hFile);
        iVar8 = (BVar5 != 0) - 1;
        if (iVar8 == -1) {
          puVar4 = (undefined4 *)__errno();
          *puVar4 = 0xd;
          pDVar6 = (DWORD *)___doserrno();
          DVar7 = GetLastError();
          *pDVar6 = DVar7;
        }
      }
    }
    else {
      _memset(local_1010,0,0x1000);
      local_10 = FUN_00682c91(param_1,0x8000);
      do {
        iVar2 = 0x1000;
        if (iVar1 < 0x1000) {
          iVar2 = iVar1;
        }
        iVar2 = FUN_00677fc7(param_1,local_1010,iVar2);
        if (iVar2 == -1) {
          piVar3 = (int *)___doserrno();
          if (*piVar3 == 5) {
            puVar4 = (undefined4 *)__errno();
            *puVar4 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        iVar1 = iVar1 - iVar2;
      } while (0 < iVar1);
      FUN_00682c91(param_1,local_10);
    }
    __lseek_lk(param_1,local_c,0);
  }
  return iVar8;
}


// ==== 0x68222d __mbschr

/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 2003 Release */

uchar * __cdecl __mbschr(uchar *_Str,uint _Ch)

{
  byte bVar1;
  byte bVar2;
  _ptiddata p_Var3;
  pthreadmbcinfo ptVar4;
  uchar *puVar5;
  byte *pbVar6;
  uint uVar7;
  
  p_Var3 = __getptd();
  ptVar4 = p_Var3->_tpxcptinfoptrs;
  if (ptVar4 != DAT_00792fc4) {
    ptVar4 = ___updatetmbcinfo();
  }
  if (ptVar4->ismbcodepage == 0) {
    puVar5 = (uchar *)_strchr();
    return puVar5;
  }
  while( true ) {
    bVar2 = *_Str;
    uVar7 = (uint)bVar2;
    if (bVar2 == 0) break;
    if ((ptVar4->mbctype[uVar7 + 5] & 4) == 0) {
      pbVar6 = _Str;
      if (_Ch == uVar7) break;
    }
    else {
      bVar1 = _Str[1];
      if (bVar1 == 0) {
        return (uchar *)0x0;
      }
      pbVar6 = _Str + 1;
      if (_Ch == CONCAT11(bVar2,bVar1)) {
        return _Str;
      }
    }
    _Str = pbVar6 + 1;
  }
  return (uchar *)(~-(uint)(_Ch != uVar7) & (uint)_Str);
}


// ==== 0x6822a8 ___addl

/* Library Function - Single Match
    ___addl
   
   Library: Visual Studio 2003 Release */

undefined4 ___addl(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1 + param_2;
  uVar2 = 0;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}


// ==== 0x6822c9 ___add_12

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void ___add_12(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = ___addl(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = ___addl(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = ___addl(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  ___addl(param_1[2],param_2[2],param_1 + 2);
  return;
}


// ==== 0x682327 ___shl_12

/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 2003 Release */

void ___shl_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}


// ==== 0x682355 ___shr_12

/* Library Function - Single Match
    ___shr_12
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void ___shr_12(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}


// ==== 0x682382 FUN_00682382

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00682382(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint unaff_retaddr;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  puVar1 = param_3;
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  local_c = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_18 = *puVar1;
      local_14 = puVar1[1];
      local_10 = puVar1[2];
      ___shl_12(puVar1);
      ___shl_12(puVar1);
      ___add_12(puVar1,&local_18);
      ___shl_12(puVar1);
      local_18 = (uint)*param_1;
      local_14 = 0;
      local_10 = 0;
      ___add_12(puVar1,&local_18);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  if (puVar1[2] == 0) {
    do {
      local_c = local_c + 0xfff0;
      uVar2 = puVar1[1] >> 0x10;
      puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
      *puVar1 = *puVar1 << 0x10;
    } while (uVar2 == 0);
    puVar1[2] = uVar2;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    ___shl_12(puVar1);
    local_c = local_c + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_c;
  return;
}


// ==== 0x682466 FUN_00682466

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00682466(int param_1,uint param_2,short *param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  char cVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  short sVar6;
  int iVar7;
  uint unaff_retaddr;
  char *pcVar8;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 uStack_18;
  undefined2 local_16;
  undefined2 uStack_14;
  undefined1 local_12;
  char cStack_11;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar3 = (uint)param_3 & 0x7fff;
  local_28 = 0xcc;
  local_27 = 0xcc;
  local_26 = 0xcc;
  local_25 = 0xcc;
  local_24 = 0xcc;
  local_23 = 0xcc;
  local_22 = 0xcc;
  local_21 = 0xcc;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xfb;
  local_1d = 0x3f;
  local_c = 1;
  if (((uint)param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar3 == 0) && (param_2 == 0)) && (param_1 == 0)) {
LAB_006825df:
    *(undefined1 *)(param_6 + 2) = 0x30;
LAB_006826e5:
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 5) = 0;
    *(undefined1 *)(param_6 + 1) = 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    local_c = 1;
  }
  else {
    if ((short)uVar3 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if ((((uint)param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_00682555;
          pcVar8 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_00682555:
            pcVar8 = "1#QNAN";
            goto LAB_0068255a;
          }
          pcVar8 = "1#IND";
        }
        _strcpy(param_6 + 2,pcVar8);
        *(undefined1 *)((int)param_6 + 3) = 5;
      }
      else {
        pcVar8 = "1#SNAN";
LAB_0068255a:
        _strcpy(param_6 + 2,pcVar8);
        *(undefined1 *)((int)param_6 + 3) = 6;
      }
      return 0;
    }
    local_1c = 0;
    local_1a = (undefined2)param_1;
    uStack_18 = (undefined2)((uint)param_1 >> 0x10);
    sVar6 = (short)(((uVar3 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar3 * 0x4d10 >>
                   0x10);
    local_12 = (undefined1)uVar3;
    cStack_11 = (char)(uVar3 >> 8);
    local_16 = (undefined2)param_2;
    uStack_14 = (undefined2)(param_2 >> 0x10);
    FUN_00682932(&local_1c,-(int)sVar6,1);
    if (0x3ffe < CONCAT11(cStack_11,local_12)) {
      sVar6 = sVar6 + 1;
      FUN_006826fa(&local_1c,&local_28);
    }
    *param_6 = sVar6;
    if (((param_5 & 1) != 0) && (param_4 = param_4 + sVar6, param_4 < 1)) goto LAB_006825df;
    if (0x15 < param_4) {
      param_4 = 0x15;
    }
    iVar7 = CONCAT11(cStack_11,local_12) - 0x3ffe;
    local_12 = 0;
    cStack_11 = '\0';
    param_3 = (short *)0x8;
    do {
      ___shl_12(&local_1c);
      param_3 = (short *)((int)param_3 + -1);
    } while (param_3 != (short *)0x0);
    if (iVar7 < 0) {
      for (uVar3 = -iVar7 & 0xff; uVar3 != 0; uVar3 = uVar3 - 1) {
        ___shr_12(&local_1c);
      }
    }
    local_10 = param_4 + 1;
    psVar4 = param_6 + 2;
    param_3 = psVar4;
    if (0 < local_10) {
      do {
        local_34 = CONCAT22(local_1a,local_1c);
        uStack_30 = CONCAT22(local_16,uStack_18);
        uStack_2c = CONCAT13(cStack_11,CONCAT12(local_12,uStack_14));
        ___shl_12(&local_1c);
        ___shl_12(&local_1c);
        ___add_12(&local_1c,&local_34);
        ___shl_12(&local_1c);
        cVar2 = cStack_11;
        cStack_11 = '\0';
        psVar4 = (short *)((int)param_3 + 1);
        local_10 = local_10 + -1;
        *(char *)param_3 = cVar2 + '0';
        param_3 = psVar4;
      } while (local_10 != 0);
    }
    psVar5 = psVar4 + -1;
    psVar1 = param_6 + 2;
    if (*(char *)((int)psVar4 + -1) < '5') {
      for (; (psVar1 <= psVar5 && ((char)*psVar5 == '0')); psVar5 = (short *)((int)psVar5 + -1)) {
      }
      if (psVar5 < psVar1) {
        *(char *)psVar1 = '0';
        goto LAB_006826e5;
      }
    }
    else {
      for (; (psVar1 <= psVar5 && ((char)*psVar5 == '9')); psVar5 = (short *)((int)psVar5 + -1)) {
        *(char *)psVar5 = '0';
      }
      if (psVar5 < psVar1) {
        psVar5 = (short *)((int)psVar5 + 1);
        *param_6 = *param_6 + 1;
      }
      *(char *)psVar5 = (char)*psVar5 + '\x01';
    }
    cVar2 = ((char)psVar5 - (char)param_6) + -3;
    *(char *)((int)param_6 + 3) = cVar2;
    *(undefined1 *)(cVar2 + 4 + (int)param_6) = 0;
  }
  return local_c;
}


// ==== 0x6826fa FUN_006826fa

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006826fa(int *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  ushort uVar10;
  uint unaff_retaddr;
  byte local_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  short local_28;
  undefined2 uStack_26;
  undefined2 local_24;
  undefined1 uStack_22;
  byte bStack_21;
  int local_20;
  int local_1c;
  int local_18;
  ushort *local_14;
  ushort *local_10;
  short *local_c;
  uint local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  local_1c = 0;
  local_2c = 0;
  uStack_2b = 0;
  uStack_2a = 0;
  local_28 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  bStack_21 = 0;
  uVar8 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar6 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar3 = uVar8 + uVar6;
  if (((uVar6 < 0x7fff) && (uVar8 < 0x7fff)) && (uVar3 < 0xbffe)) {
    if (uVar3 < 0x3fc0) goto LAB_006827aa;
    if (uVar6 == 0) {
      uVar3 = uVar3 + 1;
      uVar6 = 0;
      if ((((param_1[2] & 0x7fffffffU) != 0) || (param_1[1] != 0)) || (*param_1 != 0))
      goto LAB_00682794;
    }
    else {
LAB_00682794:
      if (((uVar8 == 0) && (uVar3 = uVar3 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
         ((param_2[1] == 0 && (*param_2 == 0)))) {
LAB_006827aa:
        param_1[2] = 0;
        param_1[1] = 0;
        *param_1 = 0;
        return;
      }
      local_18 = 0;
      local_c = &local_28;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_10 = (ushort *)(local_18 * 2 + (int)param_1);
          local_14 = (ushort *)(piVar5 + 2);
          local_20 = (int)param_2;
          do {
            iVar7 = ___addl(*(undefined4 *)(local_c + -2),(uint)*local_14 * (uint)*local_10,
                            local_c + -2);
            if (iVar7 != 0) {
              *local_c = *local_c + 1;
            }
            local_10 = local_10 + 1;
            local_14 = local_14 + -1;
            local_20 = local_20 + -1;
          } while (local_20 != 0);
        }
        local_c = local_c + 1;
        local_18 = local_18 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1._0_2_ = uVar3 + 0xc002;
      if ((short)(ushort)param_1 < 1) {
LAB_0068285e:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          uVar9 = (uint)(ushort)-(ushort)param_1;
          param_1._0_2_ = 0;
          do {
            if ((local_2c & 1) != 0) {
              local_1c = local_1c + 1;
            }
            ___shr_12(&local_2c);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
          if (local_1c != 0) {
            local_2c = local_2c | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_21 & 0x80) != 0) break;
          ___shl_12(&local_2c);
          param_1._0_2_ = (ushort)param_1 - 1;
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_0068285e;
      }
      if ((0x8000 < CONCAT11(uStack_2b,local_2c)) ||
         (sVar1 = CONCAT11(bStack_21,uStack_22), iVar2 = CONCAT22(local_24,uStack_26),
         iVar7 = CONCAT22(local_28,uStack_2a),
         (CONCAT22(uStack_2a,CONCAT11(uStack_2b,local_2c)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_28,uStack_2a) == -1) {
          iVar7 = 0;
          if (CONCAT22(local_24,uStack_26) == -1) {
            if (CONCAT11(bStack_21,uStack_22) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar1 = -0x8000;
              iVar2 = 0;
              iVar7 = 0;
            }
            else {
              sVar1 = CONCAT11(bStack_21,uStack_22) + 1;
              iVar2 = 0;
              iVar7 = 0;
            }
          }
          else {
            sVar1 = CONCAT11(bStack_21,uStack_22);
            iVar2 = CONCAT22(local_24,uStack_26) + 1;
          }
        }
        else {
          iVar7 = CONCAT22(local_28,uStack_2a) + 1;
          sVar1 = CONCAT11(bStack_21,uStack_22);
          iVar2 = CONCAT22(local_24,uStack_26);
        }
      }
      local_28 = (short)((uint)iVar7 >> 0x10);
      uStack_2a = (undefined2)iVar7;
      local_24 = (undefined2)((uint)iVar2 >> 0x10);
      uStack_26 = (undefined2)iVar2;
      bStack_21 = (byte)((ushort)sVar1 >> 8);
      uStack_22 = (undefined1)sVar1;
      if (0x7ffe < (ushort)param_1) goto LAB_00682907;
      *(undefined2 *)piVar4 = uStack_2a;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_26,local_28);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_21,CONCAT12(uStack_22,local_24));
      uVar6 = (ushort)param_1 | uVar10;
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_00682907:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar10 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}


// ==== 0x682932 FUN_00682932

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00682932(undefined2 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint unaff_retaddr;
  ushort local_14;
  undefined4 local_12;
  undefined2 uStack_e;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar3 = 0x6ec1e0;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x6ec340;
    }
    if (param_3 == 0) {
      *param_1 = 0;
    }
    while (param_2 != 0) {
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      iVar3 = iVar3 + 0x54;
      param_2 = uVar1;
      if (uVar2 != 0) {
        puVar4 = (ushort *)(iVar3 + uVar2 * 0xc);
        if (0x7fff < *puVar4) {
          local_14 = (ushort)*(undefined4 *)puVar4;
          local_12._0_2_ = (undefined2)((uint)*(undefined4 *)puVar4 >> 0x10);
          local_12._2_2_ = (undefined2)*(undefined4 *)(puVar4 + 2);
          uStack_e = (undefined2)((uint)*(undefined4 *)(puVar4 + 2) >> 0x10);
          uStack_c = *(undefined4 *)(puVar4 + 4);
          local_12 = CONCAT22(local_12._2_2_,(undefined2)local_12) + -1;
          puVar4 = &local_14;
        }
        FUN_006826fa(param_1,puVar4);
      }
    }
  }
  return;
}


// ==== 0x6829be ___crtGetLocaleInfoW

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetLocaleInfoW
   
   Library: Visual Studio 2003 Release */

int ___crtGetLocaleInfoW(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 uStackY_4c;
  int local_20;
  
  if (DAT_00717f04 == 0) {
    uStackY_4c = 0x6829e1;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00717f04 = 2;
      }
    }
    else {
      DAT_00717f04 = 1;
    }
  }
  if (DAT_00717f04 == 1) {
    uStackY_4c = 0x682a1d;
    iVar3 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar3;
  }
  if ((DAT_00717f04 == 2) || (DAT_00717f04 == 0)) {
    local_20 = 0;
    bVar2 = false;
    if (param_5 == 0) {
      param_5 = DAT_00717ea0;
    }
    uStackY_4c = 0x682a4c;
    iVar3 = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = &stack0xffffffc8 + iVar1;
      if (&stack0xffffffc8 == puVar5) {
        *(int *)(&stack0xffffffc4 + iVar1) = iVar3;
        *(undefined4 *)(&stack0xffffffc0 + iVar1) = 0x682a99;
        puVar6 = _malloc(*(size_t *)(&stack0xffffffc4 + iVar1));
        if (puVar6 == (void *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(&stack0xffffffc4 + iVar1) = iVar3;
      *(undefined1 **)(&stack0xffffffc0 + iVar1) = puVar6;
      *(LCTYPE *)(&stack0xffffffbc + iVar1) = param_2;
      *(LCID *)(&stack0xffffffb8 + iVar1) = param_1;
      puVar7 = (undefined1 *)((int)&uStackY_4c + iVar1);
      *(undefined4 *)((int)&uStackY_4c + iVar1) = 0x682ab3;
      iVar3 = GetLocaleInfoA(*(LCID *)(&stack0xffffffb8 + iVar1),
                             *(LCTYPE *)(&stack0xffffffbc + iVar1),
                             *(LPSTR *)(&stack0xffffffc0 + iVar1),*(int *)(&stack0xffffffc4 + iVar1)
                            );
      puVar5 = puVar7;
      if (iVar3 != 0) {
        if (param_4 == 0) {
          *(undefined4 *)(puVar7 + -4) = 0;
          *(undefined4 *)(puVar7 + -8) = 0;
        }
        else {
          *(int *)(puVar7 + -4) = param_4;
          *(LPWSTR *)(puVar7 + -8) = param_3;
        }
        *(undefined4 *)(puVar7 + -0xc) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x10) = puVar6;
        *(undefined4 *)(puVar7 + -0x14) = 1;
        *(int *)(puVar7 + -0x18) = param_5;
        puVar5 = puVar7 + -0x1c;
        *(undefined4 *)(puVar7 + -0x1c) = 0x682ad3;
        local_20 = MultiByteToWideChar(*(UINT *)(puVar7 + -0x18),*(DWORD *)(puVar7 + -0x14),
                                       *(LPCSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPWSTR *)(puVar7 + -8),*(int *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x682ae1;
        _free(*(void **)(puVar5 + -4));
        return local_20;
      }
      return local_20;
    }
  }
  return 0;
}


// ==== 0x682a76 FUN_00682a76

undefined4 FUN_00682a76(void)

{
  return 1;
}


// ==== 0x682a7a FUN_00682a7a

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00682a7a(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x682a82;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(iVar3 + -8) = 0x682a99;
  pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
    *(void **)(iVar3 + -8) = pvVar2;
    *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = (undefined1 *)(iVar3 + -0x14);
    *(undefined4 *)(iVar3 + -0x14) = 0x682ab3;
    iVar3 = GetLocaleInfoA(*(LCID *)(iVar3 + -0x10),*(LCTYPE *)(iVar3 + -0xc),*(LPSTR *)(iVar3 + -8)
                           ,*(int *)(iVar3 + -4));
    puVar5 = puVar4;
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar4 + -4) = 0;
        *(undefined4 *)(puVar4 + -8) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar4 + -0xc) = 0xffffffff;
      *(void **)(puVar4 + -0x10) = pvVar2;
      *(undefined4 *)(puVar4 + -0x14) = 1;
      *(undefined4 *)(puVar4 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar5 = puVar4 + -0x1c;
      *(undefined4 *)(puVar4 + -0x1c) = 0x682ad3;
      iVar3 = MultiByteToWideChar(*(UINT *)(puVar4 + -0x18),*(DWORD *)(puVar4 + -0x14),
                                  *(LPCSTR *)(puVar4 + -0x10),*(int *)(puVar4 + -0xc),
                                  *(LPWSTR *)(puVar4 + -8),*(int *)(puVar4 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar3;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(void **)(puVar5 + -4) = pvVar2;
      *(undefined4 *)(puVar5 + -8) = 0x682ae1;
      _free(*(void **)(puVar5 + -4));
    }
    uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x682aed;
  return uVar1;
}


// ==== 0x682aee ___crtGetLocaleInfoA

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetLocaleInfoA
   
   Library: Visual Studio 2003 Release */

int __cdecl
___crtGetLocaleInfoA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,LCTYPE _LCType,LPSTR _LpLCData,int _CchData)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 uStackY_4c;
  int local_20;
  
  if (DAT_00717f08 == 0) {
    uStackY_4c = 0x682b11;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00717f08 = 2;
      }
    }
    else {
      DAT_00717f08 = 1;
    }
  }
  if ((DAT_00717f08 == 2) || (DAT_00717f08 == 0)) {
    uStackY_4c = 0x682c25;
    iVar3 = GetLocaleInfoA((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPSTR)_LCType,(int)_LpLCData);
    return iVar3;
  }
  if (DAT_00717f08 == 1) {
    local_20 = 0;
    bVar2 = false;
    if (_CchData == 0) {
      _CchData = DAT_00717ea0;
    }
    uStackY_4c = 0x682b6e;
    iVar3 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPWSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = &stack0xffffffc8 + iVar1;
      if (&stack0xffffffc8 == puVar5) {
        *(int *)(&stack0xffffffc4 + iVar1) = iVar3 * 2;
        *(undefined4 *)(&stack0xffffffc0 + iVar1) = 0x682bc1;
        puVar6 = _malloc(*(size_t *)(&stack0xffffffc4 + iVar1));
        if (puVar6 == (void *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(&stack0xffffffc4 + iVar1) = iVar3;
      *(undefined1 **)(&stack0xffffffc0 + iVar1) = puVar6;
      *(LPCWSTR *)(&stack0xffffffbc + iVar1) = _LocaleName;
      *(_locale_t *)(&stack0xffffffb8 + iVar1) = _Plocinfo;
      puVar7 = (undefined1 *)((int)&uStackY_4c + iVar1);
      *(undefined4 *)((int)&uStackY_4c + iVar1) = 0x682bdd;
      iVar3 = GetLocaleInfoW(*(LCID *)(&stack0xffffffb8 + iVar1),
                             *(LCTYPE *)(&stack0xffffffbc + iVar1),
                             *(LPWSTR *)(&stack0xffffffc0 + iVar1),
                             *(int *)(&stack0xffffffc4 + iVar1));
      puVar5 = puVar7;
      if (iVar3 != 0) {
        *(undefined4 *)(puVar7 + -4) = 0;
        *(undefined4 *)(puVar7 + -8) = 0;
        if (_LpLCData == (LPSTR)0x0) {
          *(undefined4 *)(puVar7 + -0xc) = 0;
          *(undefined4 *)(puVar7 + -0x10) = 0;
        }
        else {
          *(LPSTR *)(puVar7 + -0xc) = _LpLCData;
          *(LCTYPE *)(puVar7 + -0x10) = _LCType;
        }
        *(undefined4 *)(puVar7 + -0x14) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x18) = puVar6;
        *(undefined4 *)(puVar7 + -0x1c) = 0;
        *(int *)(puVar7 + -0x20) = _CchData;
        puVar5 = puVar7 + -0x24;
        *(undefined4 *)(puVar7 + -0x24) = 0x682bff;
        local_20 = WideCharToMultiByte(*(UINT *)(puVar7 + -0x20),*(DWORD *)(puVar7 + -0x1c),
                                       *(LPCWSTR *)(puVar7 + -0x18),*(int *)(puVar7 + -0x14),
                                       *(LPSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPCSTR *)(puVar7 + -8),*(LPBOOL *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x682c0d;
        _free(*(void **)(puVar5 + -4));
        return local_20;
      }
      return local_20;
    }
  }
  return 0;
}


// ==== 0x682b9d FUN_00682b9d

undefined4 FUN_00682b9d(void)

{
  return 1;
}


// ==== 0x682ba1 FUN_00682ba1

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00682ba1(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar4 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar4 + -4) = 0x682ba9;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x24);
  *(int *)(iVar4 + -4) = iVar1 * 2;
  *(undefined4 *)(iVar4 + -8) = 0x682bc1;
  pvVar3 = _malloc(*(size_t *)(iVar4 + -4));
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(int *)(iVar4 + -4) = iVar1;
    *(void **)(iVar4 + -8) = pvVar3;
    *(undefined4 *)(iVar4 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar4 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar5 = (undefined1 *)(iVar4 + -0x14);
    *(undefined4 *)(iVar4 + -0x14) = 0x682bdd;
    iVar4 = GetLocaleInfoW(*(LCID *)(iVar4 + -0x10),*(LCTYPE *)(iVar4 + -0xc),
                           *(LPWSTR *)(iVar4 + -8),*(int *)(iVar4 + -4));
    puVar6 = puVar5;
    if (iVar4 != 0) {
      *(undefined4 *)(puVar5 + -4) = 0;
      *(undefined4 *)(puVar5 + -8) = 0;
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar5 + -0xc) = 0;
        *(undefined4 *)(puVar5 + -0x10) = 0;
      }
      else {
        *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar5 + -0x14) = 0xffffffff;
      *(void **)(puVar5 + -0x18) = pvVar3;
      *(undefined4 *)(puVar5 + -0x1c) = 0;
      *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar6 = puVar5 + -0x24;
      *(undefined4 *)(puVar5 + -0x24) = 0x682bff;
      iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                  *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                  *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                  *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(void **)(puVar6 + -4) = pvVar3;
      *(undefined4 *)(puVar6 + -8) = 0x682c0d;
      _free(*(void **)(puVar6 + -4));
    }
    uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x682c2d;
  return uVar2;
}


// ==== 0x682c30 ___ascii_strnicmp

/* Library Function - Single Match
    ___ascii_strnicmp
   
   Library: Visual Studio 2003 Release */

int __cdecl ___ascii_strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = 0;
  if (_MaxCount != 0) {
    do {
      bVar2 = *_Str1;
      cVar1 = *_Str2;
      uVar3 = CONCAT11(bVar2,cVar1);
      if (bVar2 == 0) break;
      uVar3 = CONCAT11(bVar2,cVar1);
      uVar4 = (uint)uVar3;
      if (cVar1 == '\0') break;
      _Str1 = _Str1 + 1;
      _Str2 = _Str2 + 1;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar4 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
      }
      uVar3 = (ushort)uVar4;
      bVar2 = (byte)uVar4;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar3 = (ushort)CONCAT31((int3)(uVar4 >> 8),bVar2 + 0x20);
      }
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) goto LAB_00682c81;
      _MaxCount = _MaxCount - 1;
    } while (_MaxCount != 0);
    iVar5 = 0;
    bVar2 = (byte)(uVar3 >> 8);
    bVar6 = bVar2 < (byte)uVar3;
    if (bVar2 != (byte)uVar3) {
LAB_00682c81:
      iVar5 = -1;
      if (!bVar6) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}


// ==== 0x682c91 FUN_00682c91

int FUN_00682c91(uint param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  pbVar1 = (byte *)((&DAT_00793240)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  bVar2 = *pbVar1;
  if (param_2 == 0x8000) {
    bVar4 = bVar2 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      return -1;
    }
    bVar4 = bVar2 | 0x80;
  }
  *pbVar1 = bVar4;
  return (-(uint)((bVar2 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ==== 0x682d00 Process32First

void Process32First(void)

{
                    /* WARNING: Could not recover jumptable at 0x00682d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Process32First();
  return;
}


// ==== 0x682d06 Process32Next

void Process32Next(void)

{
                    /* WARNING: Could not recover jumptable at 0x00682d06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Process32Next();
  return;
}


// ==== 0x682d0c CreateToolhelp32Snapshot

void CreateToolhelp32Snapshot(void)

{
                    /* WARNING: Could not recover jumptable at 0x00682d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateToolhelp32Snapshot();
  return;
}


// ==== 0x682d12 RtlUnwind

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x00682d12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


// ==== 0x682d18 FUN_00682d18

undefined4 FUN_00682d18(uint *param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int local_14;
  uint *local_8;
  
  uVar5 = param_4 * param_5 + param_2;
  if (param_2 < uVar5) {
    param_4 = param_2 + param_3 * 4;
    do {
      local_8 = param_1;
      if (param_2 < param_4) {
        puVar6 = (uint *)(param_2 + 4);
        local_14 = ((param_4 - param_2) - 1 >> 3) + 1;
        do {
          uVar1 = *(uint *)((int)puVar6 + param_5);
          uVar2 = *(uint *)(param_5 + -4 + (int)puVar6);
          uVar3 = *puVar6;
          uVar4 = puVar6[-1];
          *local_8 = ((uVar4 >> 2 & 0xffc03fc0) + (uVar2 >> 2 & 0xffc03fc0) +
                      (uVar1 >> 2 & 0xffc03fc0) + -0x7fff80 + (uVar3 >> 2 & 0xffc03fc0) ^
                     (uVar4 & 0xff00ff) + (uVar2 & 0xff00ff) + (uVar1 & 0xff00ff) + 0x20002 +
                     (uVar3 & 0xff00ff) >> 2) & 0xff00ff ^
                     (uVar4 >> 2 & 0x3fc03fc0) + (uVar2 >> 2 & 0x3fc03fc0) +
                     (uVar1 >> 2 & 0x3fc03fc0) + 0x800080 + (uVar3 >> 2 & 0x3fc03fc0);
          puVar6 = puVar6 + 2;
          local_14 = local_14 + -1;
          local_8 = local_8 + 1;
        } while (local_14 != 0);
      }
      param_1 = (uint *)((int)param_1 + param_6);
      param_4 = param_4 + param_5 * 2;
      param_2 = param_2 + param_5 * 2;
    } while (param_2 < uVar5);
  }
  return 0;
}


// ==== 0x682e40 FUN_00682e40

undefined4
FUN_00682e40(uint *param_1,uint param_2,uint *param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int local_10;
  
  uVar5 = param_4 * param_5 + param_2;
  if (param_2 < uVar5) {
    param_4 = param_2 + (int)param_3 * 4;
    do {
      param_3 = param_1;
      if (param_2 < param_4) {
        local_10 = ((param_4 - param_2) - 1 >> 3) + 1;
        puVar6 = (uint *)(param_2 + 4);
        do {
          puVar2 = (uint *)((int)puVar6 + param_5);
          uVar3 = *puVar6;
          uVar4 = *(uint *)(param_5 + -4 + (int)puVar6);
          puVar1 = puVar6 + -1;
          puVar6 = puVar6 + 2;
          local_10 = local_10 + -1;
          *param_3 = ((*puVar1 & 0xff00ff) + (uVar4 & 0xff00ff) + (*puVar2 & 0xff00ff) + 0x20002 +
                      (uVar3 & 0xff00ff) & 0x3fc03fc |
                     (*puVar1 & 0xff00) + (uVar4 & 0xff00) + (*puVar2 & 0xff00) + 0x200 +
                     (uVar3 & 0xff00) & 0x3fc00) >> 2;
          param_3 = param_3 + 1;
        } while (local_10 != 0);
      }
      param_1 = (uint *)((int)param_1 + param_6);
      param_4 = param_4 + param_5 * 2;
      param_2 = param_2 + param_5 * 2;
    } while (param_2 < uVar5);
  }
  return 0;
}


// ==== 0x682f2a FUN_00682f2a

undefined4
FUN_00682f2a(undefined8 *param_1,undefined8 *param_2,uint param_3,int param_4,int param_5,
            int param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  if ((param_3 & 3) == 0) {
    puVar13 = (undefined8 *)(param_4 * param_5 + (int)param_2);
    for (; (int)param_2 < (int)puVar13; param_2 = (undefined8 *)((int)param_2 + param_5 * 2)) {
      puVar14 = (undefined8 *)((int)param_2 + param_5);
      puVar11 = param_1;
      puVar15 = param_2;
      while ((int)puVar15 < (int)((int)param_2 + param_3 * 4)) {
        uVar16 = *puVar15;
        uVar17 = *puVar14;
        uVar1 = puVar15[1];
        uVar2 = puVar14[1];
        puVar15 = puVar15 + 2;
        puVar14 = puVar14 + 2;
        uVar16 = psraw(CONCAT26((ushort)(byte)((ulonglong)uVar16 >> 0x18) +
                                (ushort)(byte)((ulonglong)uVar16 >> 0x38) +
                                (ushort)(byte)((ulonglong)uVar17 >> 0x18) +
                                (ushort)(byte)((ulonglong)uVar17 >> 0x38) + 2,
                                CONCAT24((ushort)(byte)((ulonglong)uVar16 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar16 >> 0x30) +
                                         (ushort)(byte)((ulonglong)uVar17 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar17 >> 0x30) + 2,
                                         CONCAT22((ushort)(byte)((ulonglong)uVar16 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar16 >> 0x28) +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 0x28) + 2,
                                                  (ushort)(byte)uVar16 +
                                                  (ushort)(byte)((ulonglong)uVar16 >> 0x20) +
                                                  (ushort)(byte)uVar17 +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 0x20) + 2))),2
                      );
        uVar17 = psraw(CONCAT26((ushort)(byte)((ulonglong)uVar1 >> 0x18) +
                                (ushort)(byte)((ulonglong)uVar1 >> 0x38) +
                                (ushort)(byte)((ulonglong)uVar2 >> 0x18) +
                                (ushort)(byte)((ulonglong)uVar2 >> 0x38) + 2,
                                CONCAT24((ushort)(byte)((ulonglong)uVar1 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar1 >> 0x30) +
                                         (ushort)(byte)((ulonglong)uVar2 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar2 >> 0x30) + 2,
                                         CONCAT22((ushort)(byte)((ulonglong)uVar1 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar1 >> 0x28) +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 0x28) + 2,
                                                  (ushort)(byte)uVar1 +
                                                  (ushort)(byte)((ulonglong)uVar1 >> 0x20) +
                                                  (ushort)(byte)uVar2 +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 0x20) + 2))),2)
        ;
        sVar3 = (short)uVar16;
        sVar4 = (short)((ulonglong)uVar16 >> 0x10);
        sVar5 = (short)((ulonglong)uVar16 >> 0x20);
        sVar6 = (short)((ulonglong)uVar16 >> 0x30);
        sVar7 = (short)uVar17;
        sVar8 = (short)((ulonglong)uVar17 >> 0x10);
        sVar9 = (short)((ulonglong)uVar17 >> 0x20);
        sVar10 = (short)((ulonglong)uVar17 >> 0x30);
        *puVar11 = CONCAT17((0 < sVar10) * (sVar10 < 0x100) * (char)((ulonglong)uVar17 >> 0x30) -
                            (0xff < sVar10),
                            CONCAT16((0 < sVar9) * (sVar9 < 0x100) *
                                     (char)((ulonglong)uVar17 >> 0x20) - (0xff < sVar9),
                                     CONCAT15((0 < sVar8) * (sVar8 < 0x100) *
                                              (char)((ulonglong)uVar17 >> 0x10) - (0xff < sVar8),
                                              CONCAT14((0 < sVar7) * (sVar7 < 0x100) * (char)uVar17
                                                       - (0xff < sVar7),
                                                       CONCAT13((0 < sVar6) * (sVar6 < 0x100) *
                                                                (char)((ulonglong)uVar16 >> 0x30) -
                                                                (0xff < sVar6),
                                                                CONCAT12((0 < sVar5) *
                                                                         (sVar5 < 0x100) *
                                                                         (char)((ulonglong)uVar16 >>
                                                                               0x20) -
                                                                         (0xff < sVar5),
                                                                         CONCAT11((0 < sVar4) *
                                                                                  (sVar4 < 0x100) *
                                                                                  (char)((ulonglong)
                                                                                         uVar16 >>
                                                                                        0x10) -
                                                                                  (0xff < sVar4),
                                                                                  (0 < sVar3) *
                                                                                  (sVar3 < 0x100) *
                                                                                  (char)uVar16 -
                                                                                  (0xff < sVar3)))))
                                             )));
        puVar11 = puVar11 + 1;
      }
      param_1 = (undefined8 *)((int)param_1 + param_6);
    }
    uVar12 = 0;
  }
  else {
    uVar12 = FUN_00682d18(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar12;
}


// ==== 0x683042 FUN_00683042

void FUN_00683042(void)

{
  int iVar1;
  
  iVar1 = FUN_005b0506();
  if (iVar1 == 0) {
    PTR_FUN_006ecd04 = FUN_00682d18;
    PTR_FUN_006ecd08 = FUN_00682e40;
  }
  else {
    PTR_FUN_006ecd04 = FUN_00682f2a;
    PTR_FUN_006ecd08 = FUN_00682f2a;
  }
                    /* WARNING: Could not recover jumptable at 0x00683074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006ecd04)();
  return;
}


// ==== 0x68307a FUN_0068307a

void FUN_0068307a(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_005b0506();
  if (iVar1 == 0) {
    PTR_FUN_006ecd04 = FUN_00682d18;
    UNRECOVERED_JUMPTABLE = FUN_00682e40;
  }
  else {
    UNRECOVERED_JUMPTABLE = FUN_00682f2a;
    PTR_FUN_006ecd04 = FUN_00682f2a;
  }
  PTR_FUN_006ecd08 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x006830a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== 0x6830aa Ordinal_1

void Ordinal_1(void)

{
                    /* WARNING: Could not recover jumptable at 0x006830aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_1();
  return;
}


// ==== 0x6830b0 DirectDrawCreate

void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x006830b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}


// ==== 0x6830b6 lineOpen

LONG lineOpen(HLINEAPP hLineApp,DWORD dwDeviceID,LPHLINE lphLine,DWORD dwAPIVersion,
             DWORD dwExtVersion,DWORD_PTR dwCallbackInstance,DWORD dwPrivileges,DWORD dwMediaModes,
             LPLINECALLPARAMS lpCallParams)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineOpen(hLineApp,dwDeviceID,lphLine,dwAPIVersion,dwExtVersion,dwCallbackInstance,
                   dwPrivileges,dwMediaModes,lpCallParams);
  return LVar1;
}


// ==== 0x6830bc lineNegotiateAPIVersion

LONG lineNegotiateAPIVersion
               (HLINEAPP hLineApp,DWORD dwDeviceID,DWORD dwAPILowVersion,DWORD dwAPIHighVersion,
               LPDWORD lpdwAPIVersion,LPLINEEXTENSIONID lpExtensionID)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineNegotiateAPIVersion
                    (hLineApp,dwDeviceID,dwAPILowVersion,dwAPIHighVersion,lpdwAPIVersion,
                     lpExtensionID);
  return LVar1;
}


// ==== 0x6830c2 lineClose

LONG lineClose(HLINE hLine)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineClose(hLine);
  return LVar1;
}


// ==== 0x6830c8 lineGetID

LONG lineGetID(HLINE hLine,DWORD dwAddressID,HCALL hCall,DWORD dwSelect,LPVARSTRING lpDeviceID,
              LPCSTR lpszDeviceClass)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineGetID(hLine,dwAddressID,hCall,dwSelect,lpDeviceID,lpszDeviceClass);
  return LVar1;
}


// ==== 0x6830ce lineMakeCall

LONG lineMakeCall(HLINE hLine,LPHCALL lphCall,LPCSTR lpszDestAddress,DWORD dwCountryCode,
                 LPLINECALLPARAMS lpCallParams)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineMakeCall(hLine,lphCall,lpszDestAddress,dwCountryCode,lpCallParams);
  return LVar1;
}


// ==== 0x6830d4 lineAnswer

LONG lineAnswer(HCALL hCall,LPCSTR lpsUserUserInfo,DWORD dwSize)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineAnswer(hCall,lpsUserUserInfo,dwSize);
  return LVar1;
}


// ==== 0x6830da lineInitialize

LONG lineInitialize(LPHLINEAPP lphLineApp,HINSTANCE hInstance,LINECALLBACK lpfnCallback,
                   LPCSTR lpszAppName,LPDWORD lpdwNumDevs)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineInitialize(lphLineApp,hInstance,lpfnCallback,lpszAppName,lpdwNumDevs);
  return LVar1;
}


// ==== 0x6830e0 lineShutdown

LONG lineShutdown(HLINEAPP hLineApp)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineShutdown(hLineApp);
  return LVar1;
}


// ==== 0x6830e6 lineGetDevCaps

LONG lineGetDevCaps(HLINEAPP hLineApp,DWORD dwDeviceID,DWORD dwAPIVersion,DWORD dwExtVersion,
                   LPLINEDEVCAPS lpLineDevCaps)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = lineGetDevCaps(hLineApp,dwDeviceID,dwAPIVersion,dwExtVersion,lpLineDevCaps);
  return LVar1;
}


// ==== 0x6830ec Netbios

UCHAR Netbios(PNCB pncb)

{
  UCHAR UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006830ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = Netbios(pncb);
  return UVar1;
}


// ==== 0x6831f0 FUN_006831f0

void FUN_006831f0(void)

{
  uint *puVar1;
  uint *unaff_ESI;
  
  if ((unaff_ESI[4] != 0) && (1 < unaff_ESI[5])) {
    (*DAT_006e75f0)(unaff_ESI[5]);
  }
  *unaff_ESI = *unaff_ESI & 0xff;
  unaff_ESI[7] = 0;
  CriticalSection__Enter(&DAT_00717f18);
  puVar1 = unaff_ESI;
  if (DAT_00717f38 != (uint *)0x0) {
    *(uint **)((int)DAT_00717f3c + 4) = unaff_ESI;
    puVar1 = DAT_00717f38;
  }
  DAT_00717f38 = puVar1;
  DAT_00717f3c = unaff_ESI;
  unaff_ESI[1] = 0;
  CriticalSection__Leave(&DAT_00717f18);
  return;
}


// ==== 0x683260 FUN_00683260

void FUN_00683260(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_EAX;
  
  CriticalSection__Enter(&DAT_00717f18);
  pcVar1 = (code *)in_EAX[6];
  iVar2 = in_EAX[4];
  iVar3 = in_EAX[3];
  in_EAX[7] = 0;
  CriticalSection__Leave(&DAT_00717f18);
  if (iVar2 == 0) {
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(*in_EAX);
    }
  }
  else if (iVar3 == 0) {
    FUN_006831f0();
    return;
  }
  return;
}


// ==== 0x6832b0 FUN_006832b0

void FUN_006832b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_00639c00(*(undefined4 *)(param_3 + 0x1c));
  FUN_00683260();
  return;
}


// ==== 0x6832d0 FUN_006832d0

void FUN_006832d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00639c00(*(undefined4 *)(param_3 + 0x1c));
  iVar3 = *(int *)(param_3 + 0x2c) + iVar1;
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + iVar1;
  *(int *)(param_3 + 0x2c) = iVar3;
  if ((iVar1 < 0x2000) || (*(int *)(param_3 + 0x10) != 0)) {
    uVar2 = FUN_0063a690(*(undefined4 *)(param_3 + 0x20),99,param_3);
    *(undefined4 *)(param_3 + 0x1c) = uVar2;
    if (*(int *)(param_3 + 0x1c) == 0) {
      Log_Printf("ASYNCFILE_load[at] - unable to initiate file close\n");
      return;
    }
    FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832b0);
    return;
  }
  iVar4 = *(int *)(param_3 + 0x28) - iVar1;
  iVar1 = *(int *)(param_3 + 0x24) + iVar1;
  *(int *)(param_3 + 0x28) = iVar4;
  *(int *)(param_3 + 0x24) = iVar1;
  if (0x2000 < iVar4) {
    iVar4 = 0x2000;
  }
  uVar2 = FUN_0063a700(*(undefined4 *)(param_3 + 0x20),iVar1,iVar3,iVar4,99,param_3);
  *(undefined4 *)(param_3 + 0x1c) = uVar2;
  if (*(int *)(param_3 + 0x1c) == 0) {
    Log_Printf("ASYNCFILE_load[at] - unable to initiate file read\n");
    return;
  }
  FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832d0);
  return;
}


// ==== 0x6833a0 FUN_006833a0

void FUN_006833a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_00639c00(*(undefined4 *)(param_3 + 0x1c));
  if (*(int *)(param_3 + 0x10) != 0) {
    uVar2 = FUN_0063a690(*(undefined4 *)(param_3 + 0x20),99,param_3);
    *(undefined4 *)(param_3 + 0x1c) = uVar2;
    if (*(int *)(param_3 + 0x1c) == 0) {
      Log_Printf("ASYNCFILE_load - unable to initiate file close\n");
      return;
    }
    FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832b0);
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 0x28);
  *(undefined4 *)(param_3 + 0x28) = uVar2;
  uVar2 = (*DAT_006e75ec)("ASYNCFILEBUF",uVar2,uVar1);
  iVar3 = *(int *)(param_3 + 0x28);
  *(undefined4 *)(param_3 + 0x14) = uVar2;
  *(undefined4 *)(param_3 + 0x2c) = uVar2;
  if (0x2000 < iVar3) {
    iVar3 = 0x2000;
  }
  uVar2 = FUN_0063a700(*(undefined4 *)(param_3 + 0x20),*(undefined4 *)(param_3 + 0x24),uVar2,iVar3,
                       99,param_3);
  *(undefined4 *)(param_3 + 0x1c) = uVar2;
  if (*(int *)(param_3 + 0x1c) == 0) {
    Log_Printf("ASYNCFILE_load - unable to initiate file read\n");
    return;
  }
  FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832d0);
  return;
}


// ==== 0x683460 FUN_00683460

void FUN_00683460(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_00639c00(*(undefined4 *)(param_3 + 0x1c));
  *(int *)(param_3 + 0x20) = iVar1;
  if (iVar1 == 0) {
    FUN_00683260();
    return;
  }
  if (*(int *)(param_3 + 0x10) != 0) {
    uVar2 = FUN_0063a690(iVar1,99,param_3);
    *(undefined4 *)(param_3 + 0x1c) = uVar2;
    if (*(int *)(param_3 + 0x1c) == 0) {
      Log_Printf("ASYNCFILE_load[at] - unable to initiate file close\n");
      return;
    }
    FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832b0);
    return;
  }
  if (*(int *)(param_3 + 0x14) != 0) {
    uVar2 = FUN_0063a800(iVar1,99,param_3);
    *(undefined4 *)(param_3 + 0x1c) = uVar2;
    if (*(int *)(param_3 + 0x1c) == 0) {
      Log_Printf("ASYNCFILE_load - unable to initiate file size get\n");
      return;
    }
    FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006833a0);
    return;
  }
  iVar3 = *(int *)(param_3 + 0x28);
  if (0x2000 < iVar3) {
    iVar3 = 0x2000;
  }
  uVar2 = FUN_0063a700(iVar1,*(undefined4 *)(param_3 + 0x24),*(undefined4 *)(param_3 + 0x2c),iVar3,
                       99,param_3);
  *(undefined4 *)(param_3 + 0x1c) = uVar2;
  if (*(int *)(param_3 + 0x1c) == 0) {
    Log_Printf("ASYNCFILE_loadat - unable to initiate file read\n");
    return;
  }
  FUN_00639f20(*(undefined4 *)(param_3 + 0x1c),FUN_006832d0);
  return;
}


// ==== 0x6836a0 FUN_006836a0

uint FUN_006836a0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  CriticalSection__Enter(&DAT_00717f18);
  if (DAT_00717f38 == (uint *)0x0) {
    puVar2 = (uint *)0x0;
  }
  else {
    puVar2 = DAT_00717f38;
    DAT_00717f38 = (uint *)DAT_00717f38[1];
  }
  CriticalSection__Leave(&DAT_00717f18);
  if (puVar2 == (uint *)0x0) {
    Log_Printf("ASYNCFILE_load - out of async request blocks\n");
    return 0;
  }
  DAT_00717f34 = DAT_00717f34 + 0x100;
  if (DAT_00717f34 == 0) {
    DAT_00717f34 = 0x100;
  }
  *puVar2 = *puVar2 & 0xff | DAT_00717f34;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 1;
  puVar2[6] = 0;
  puVar2[9] = 0;
  puVar2[10] = param_2;
  puVar2[0xb] = 0;
  uVar1 = FUN_0063a5d0(param_1,1,100,puVar2);
  puVar2[7] = uVar1;
  if (puVar2[7] == 0) {
    Log_Printf("ASYNCFILE_load - unable to initiate file open\n");
    return 0;
  }
  FUN_00639f20(puVar2[7],FUN_00683460);
  return *puVar2;
}


// ==== 0x683a60 FUN_00683a60

undefined4 FUN_00683a60(uint param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  CriticalSection__Enter(&DAT_00717f18);
  if ((((int)param_1 < 0x100) || (DAT_00717f40 <= (int)(param_1 & 0xff))) ||
     (iVar1 = (param_1 & 0xff) * 0x30, iVar2 = iVar1 + DAT_00717f44,
     *(uint *)(iVar1 + DAT_00717f44) != param_1)) {
    iVar2 = 0;
  }
  else {
    iVar4 = *(int *)(iVar2 + 0x10);
    iVar3 = *(int *)(iVar2 + 0xc);
    if (iVar4 == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 1;
    }
  }
  CriticalSection__Leave(&DAT_00717f18);
  if ((iVar2 != 0) && (iVar4 == 0)) {
    if (iVar3 != 0) {
      Log_Printf("ASYNCFILE_release - release called more than once for this request\n");
    }
    iVar4 = *(int *)(iVar2 + 0x1c);
    while (iVar4 != 0) {
      FUN_00639d70(*(undefined4 *)(iVar2 + 0x1c));
      iVar4 = *(int *)(iVar2 + 0x1c);
    }
    if (*(int *)(iVar2 + 0x10) == 0) {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 8);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(iVar2 + 8);
      }
      FUN_006831f0();
      return 1;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    FUN_006831f0();
  }
  return 0xffffffff;
}


// ==== 0x683ce0 FUN_00683ce0

int FUN_00683ce0(void)

{
  int iVar1;
  
  iVar1 = FUN_00684843();
  if (iVar1 != 0) {
    __lock(3);
    iVar1 = FID_conflict___getch_lk();
    __unlock(3);
    return iVar1;
  }
  return 0;
}


// ==== 0x683ed0 FUN_00683ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00683ed0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x3a) {
    DAT_00718264 = DAT_00718264 == '\0';
    return 0;
  }
  FUN_00684040(_DAT_0071826c,0x717f48,0x100);
  uVar1 = FUN_006843b0(0x717f48,DAT_00718264,param_1);
  return uVar1;
}


// ==== 0x684040 FUN_00684040

int FUN_00684040(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 100))(param_1);
  if (((iVar1 == -0x7ff8fff4) || (iVar1 == -0x7ff8ffe2)) &&
     (iVar1 = (**(code **)(*param_1 + 0x1c))(param_1), iVar1 == 0)) {
    (**(code **)(*param_1 + 100))(param_1);
  }
  FUN_0063f1b0(0x718278,param_1,param_2);
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_1);
  if ((iVar1 == -0x7ff8fff4) || (iVar1 == -0x7ff8ffe2)) {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    if (iVar1 != 0) goto LAB_006840b7;
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_1);
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_006840b7:
  FUN_0063f1b0(param_1,0x718278,param_2);
  return iVar1;
}


// ==== 0x6843b0 FUN_006843b0

uint FUN_006843b0(int param_1,char param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((*(char *)(param_1 + 0x38) == '\0') && (*(char *)(param_1 + 0xb8) == '\0')) {
    if ((*(char *)(param_1 + 0x1d) == '\0') && (*(char *)(param_1 + 0x9d) == '\0')) {
      if ((*(char *)(param_1 + 0x2a) == '\0') && (*(char *)(param_1 + 0x36) == '\0')) {
        if (param_2 == '\0') {
          iVar1 = 0x6edfa0;
        }
        else {
          iVar1 = 0x6ee060;
        }
      }
      else {
        iVar1 = 0x6ee000;
      }
    }
    else {
      iVar1 = 0x6ee0c0;
    }
  }
  else {
    iVar1 = 0x6ee120;
  }
  uVar2 = (uint)*(byte *)(iVar1 + param_3);
  if (0x7f < uVar2) {
    if (0x8f < uVar2) {
      uVar2 = uVar2 & 0x7f;
    }
    uVar2 = uVar2 << 8;
  }
  return uVar2;
}


// ==== 0x684570 __getextendedkeycode

/* Library Function - Single Match
    __getextendedkeycode
   
   Library: Visual Studio 2003 Release */

char * __getextendedkeycode(int param_1)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((uVar1 & 0x100) == 0) {
    uVar4 = (uint)*(ushort *)(param_1 + 8);
    if ((uVar1 & 3) == 0) {
      if ((uVar1 & 0xc) == 0) {
        if ((uVar1 & 0x10) == 0) {
          pcVar2 = &DAT_006b51c8 + uVar4 * 8;
        }
        else {
          pcVar2 = &DAT_006b51ca + uVar4 * 8;
        }
      }
      else {
        pcVar2 = &DAT_006b51cc + uVar4 * 8;
      }
    }
    else {
      pcVar2 = &DAT_006b51ce + uVar4 * 8;
    }
    if (((*pcVar2 != '\0') && (*pcVar2 != -0x20)) || (pcVar2[1] == '\0')) {
      pcVar2 = (char *)0x0;
    }
  }
  else {
    pcVar2 = (char *)0x0;
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (*(short *)((int)&DAT_006b5150 + uVar4) == *(short *)(param_1 + 8)) {
        if ((uVar1 & 3) != 0) {
          return &UNK_006b5158 + iVar3 * 10;
        }
        if ((uVar1 & 0xc) != 0) {
          return &UNK_006b5156 + iVar3 * 10;
        }
        if ((uVar1 & 0x10) != 0) {
          return &UNK_006b5154 + iVar3 * 10;
        }
        return &UNK_006b5152 + iVar3 * 10;
      }
      uVar4 = uVar4 + 10;
      iVar3 = iVar3 + 1;
    } while (uVar4 < 0x78);
  }
  return pcVar2;
}


// ==== 0x68461d FID_conflict:__getch_lk

/* Library Function - Multiple Matches With Different Base Names
    __getch
    __getch_lk
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict___getch_lk(void)

{
  uint uVar1;
  byte *pbVar2;
  BOOL BVar3;
  _INPUT_RECORD local_20;
  DWORD local_c;
  DWORD local_8;
  
  if (DAT_006ee180 != 0xffffffff) {
    uVar1 = DAT_006ee180 & 0xff;
    DAT_006ee180 = 0xffffffff;
    return uVar1;
  }
  if (DAT_006ee18c == (HANDLE)0xffffffff) {
    return -1;
  }
  if (DAT_006ee18c == (HANDLE)0xfffffffe) {
    ___initconin();
  }
  GetConsoleMode(DAT_006ee18c,&local_c);
  SetConsoleMode(DAT_006ee18c,0);
  do {
    do {
      BVar3 = ReadConsoleInputA(DAT_006ee18c,&local_20,1,&local_8);
      if ((BVar3 == 0) || (local_8 == 0)) {
        uVar1 = 0xffffffff;
        goto LAB_006846be;
      }
    } while ((local_20.EventType != 1) || (local_20.Event.KeyEvent.bKeyDown == 0));
    uVar1 = (uint)(byte)local_20.Event.MouseEvent.dwControlKeyState._2_1_;
    if (uVar1 != 0) goto LAB_006846be;
    pbVar2 = (byte *)__getextendedkeycode(&local_20.Event);
  } while (pbVar2 == (byte *)0x0);
  uVar1 = (uint)*pbVar2;
  DAT_006ee180 = (uint)pbVar2[1];
LAB_006846be:
  SetConsoleMode(DAT_006ee18c,local_c);
  return uVar1;
}


// ==== 0x6846de FUN_006846de

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006846de(void)

{
  uint uVar1;
  uint uVar2;
  BOOL BVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  int aiStackY_50 [3];
  uint uStack_30;
  undefined1 *puStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  
  puStack_8 = &UNK_006b5490;
  uStack_c = 0x6846ea;
  iStack_20 = 0;
  uStack_24 = 0;
  if (DAT_006ee180 != -1) {
    return 1;
  }
  if (DAT_006ee18c == (HANDLE)0xfffffffe) {
    ___initconin();
  }
  if (DAT_006ee18c != (HANDLE)0xffffffff) {
    aiStackY_50[2] = 0x68472a;
    BVar3 = GetNumberOfConsoleInputEvents(DAT_006ee18c,&uStack_28);
    uVar1 = uStack_28;
    if ((BVar3 != 0) && (uStack_28 != 0)) {
      iVar5 = uStack_28 * -0x14;
      psVar4 = (short *)(&stack0xffffffc4 + iVar5);
      puStack_1c = &stack0xffffffc4 + iVar5;
      puStack_2c = &stack0xffffffc4 + iVar5;
      puStack_8 = (undefined *)0xffffffff;
      if (&stack0xffffffc4 == (undefined1 *)(uStack_28 * 0x14)) {
        *(uint *)(&stack0xffffffc0 + iVar5) = uStack_28 * 0x14;
        *(undefined4 *)(&stack0xffffffbc + iVar5) = 0x684784;
        psVar4 = _malloc(*(size_t *)(&stack0xffffffc0 + iVar5));
        if (psVar4 == (short *)0x0) {
          return 0;
        }
        iStack_20 = 1;
      }
      uVar2 = uStack_28;
      *(uint **)(&stack0xffffffc0 + iVar5) = &uStack_30;
      *(uint *)(&stack0xffffffbc + iVar5) = uVar2;
      aiStackY_50[uVar1 * -5 + 2] = (int)psVar4;
      aiStackY_50[uVar1 * -5 + 1] = (int)DAT_006ee18c;
      piVar6 = aiStackY_50 + uVar1 * -5;
      aiStackY_50[uVar1 * -5] = 0x6847ab;
      BVar3 = PeekConsoleInputA((HANDLE)aiStackY_50[uVar1 * -5 + 1],
                                (PINPUT_RECORD)aiStackY_50[uVar1 * -5 + 2],
                                *(DWORD *)(&stack0xffffffbc + iVar5),
                                *(LPDWORD *)(&stack0xffffffc0 + iVar5));
      if (((BVar3 != 0) && (uStack_30 != 0)) && (uStack_30 <= uStack_28)) {
        while (uVar1 = uStack_30, uStack_30 != 0) {
          if ((*psVar4 == 1) && (*(int *)(psVar4 + 2) != 0)) {
            if ((char)psVar4[7] == '\0') {
              *(short **)((int)piVar6 + -4) = psVar4 + 2;
              *(undefined4 *)((int)piVar6 + -8) = 0x6847d6;
              iVar5 = __getextendedkeycode();
              if (iVar5 == 0) goto LAB_006847de;
            }
            uStack_24 = 1;
          }
LAB_006847de:
          psVar4 = psVar4 + 10;
          uStack_30 = uVar1 - 1;
        }
      }
      if (iStack_20 != 0) {
        *(short **)((int)piVar6 + -4) = psVar4;
        *(undefined4 *)((int)piVar6 + -8) = 0x6847f5;
        _free(*(void **)((int)piVar6 + -4));
        return uStack_24;
      }
      return uStack_24;
    }
  }
  return 0;
}


// ==== 0x68475f FUN_0068475f

undefined4 FUN_0068475f(void)

{
  return 1;
}


// ==== 0x684763 FUN_00684763

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Removing unreachable block (ram,0x00684796) */

undefined4 FUN_00684763(void)

{
  short *psVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  uint uVar6;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x68476b;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(iVar3 + -4) = *(int *)(unaff_EBP + -0x24) * 0x14;
  *(undefined4 *)(iVar3 + -8) = 0x684784;
  psVar1 = _malloc(*(size_t *)(iVar3 + -4));
  if (psVar1 == (short *)0x0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
    uVar4 = *(undefined4 *)(unaff_EBP + -0x24);
    *(int *)(iVar3 + -4) = unaff_EBP + -0x2c;
    *(undefined4 *)(iVar3 + -8) = uVar4;
    *(short **)(iVar3 + -0xc) = psVar1;
    *(undefined4 *)(iVar3 + -0x10) = DAT_006ee18c;
    puVar5 = (undefined1 *)(iVar3 + -0x14);
    *(undefined4 *)(iVar3 + -0x14) = 0x6847ab;
    BVar2 = PeekConsoleInputA(*(HANDLE *)(iVar3 + -0x10),*(PINPUT_RECORD *)(iVar3 + -0xc),
                              *(DWORD *)(iVar3 + -8),*(LPDWORD *)(iVar3 + -4));
    if (((BVar2 != 0) && (uVar6 = *(uint *)(unaff_EBP + -0x2c), uVar6 != 0)) &&
       (uVar6 <= *(uint *)(unaff_EBP + -0x24))) {
      while (uVar6 != 0) {
        if ((*psVar1 == 1) && (*(int *)(psVar1 + 2) != 0)) {
          if ((char)psVar1[7] == '\0') {
            *(short **)(puVar5 + -4) = psVar1 + 2;
            *(undefined4 *)(puVar5 + -8) = 0x6847d6;
            iVar3 = __getextendedkeycode();
            if (iVar3 == 0) goto LAB_006847de;
          }
          *(undefined4 *)(unaff_EBP + -0x20) = 1;
        }
LAB_006847de:
        uVar6 = uVar6 - 1;
        *(uint *)(unaff_EBP + -0x2c) = uVar6;
        psVar1 = psVar1 + 10;
      }
    }
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      *(short **)(puVar5 + -4) = psVar1;
      *(undefined4 *)(puVar5 + -8) = 0x6847f5;
      _free(*(void **)(puVar5 + -4));
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x684805;
  return uVar4;
}


// ==== 0x684843 FUN_00684843

undefined4 FUN_00684843(void)

{
  undefined4 uVar1;
  
  __lock(3);
  uVar1 = FUN_006846de();
  __unlock(3);
  return uVar1;
}


// ==== 0x68487c FUN_0068487c

bool FUN_0068487c(void)

{
  int unaff_EBP;
  
  return *(int *)**(undefined4 **)(unaff_EBP + -0x14) == -0x3ffffffb;
}


// ==== 0x684890 FUN_00684890

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00684890(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x68489e;
  return 0;
}


// ==== 0x6848a1 FUN_006848a1

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_006848a1(void)

{
  void *_File;
  int iVar1;
  int _Index;
  undefined4 uStack_20;
  
  uStack_20 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00794360; _Index = _Index + 1) {
    _File = *(void **)(DAT_00793350 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00793350 + _Index * 4);
      if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (*(int *)(iVar1 + 0x1c) != 0)) {
        __fclose_lk(iVar1);
        uStack_20 = uStack_20 + 1;
      }
      FUN_00684917();
    }
  }
  FUN_0068493a();
  return uStack_20;
}


// ==== 0x684914 FUN_00684914

void FUN_00684914(void)

{
  int unaff_EBP;
  
  __unlock_file2(*(int *)(unaff_EBP + -0x20),
                 *(void **)(DAT_00793350 + *(int *)(unaff_EBP + -0x20) * 4));
  return;
}


// ==== 0x684917 FUN_00684917

void FUN_00684917(void)

{
  int unaff_ESI;
  
  __unlock_file2(unaff_ESI,*(void **)(DAT_00793350 + unaff_ESI * 4));
  return;
}


// ==== 0x68493a FUN_0068493a

void FUN_0068493a(void)

{
  __unlock(1);
  return;
}


// ==== 0x684943 ___initconin

/* Library Function - Single Match
    ___initconin
   
   Library: Visual Studio 2003 Release */

void __cdecl ___initconin(void)

{
  DAT_006ee18c = CreateFileA("CONIN$",0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}


// ==== 0x684962 FUN_00684962

void FUN_00684962(void)

{
  if ((DAT_006ee190 != (HANDLE)0xffffffff) && (DAT_006ee190 != (HANDLE)0xfffffffe)) {
    CloseHandle(DAT_006ee190);
  }
  if ((DAT_006ee18c != (HANDLE)0xffffffff) && (DAT_006ee18c != (HANDLE)0xfffffffe)) {
    CloseHandle(DAT_006ee18c);
  }
  return;
}


// ==== 0x6849a0 __allshr

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined8 __fastcall __allshr(byte param_1,int param_2)

{
  uint in_EAX;
  int iVar1;
  
  iVar1 = param_2 >> 0x1f;
  if (0x3f < param_1) {
    return CONCAT44(iVar1,iVar1);
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 >> (param_1 & 0x1f),
                    in_EAX >> (param_1 & 0x1f) | param_2 << 0x20 - (param_1 & 0x1f));
  }
  return CONCAT44(iVar1,param_2 >> (param_1 & 0x1f));
}


// ==== 0x6849d0 __allshl

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

longlong __fastcall __allshl(byte param_1,int param_2)

{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}


// ==== 0x6849f0 FUN_006849f0

void FUN_006849f0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684a00 Unwind@00684a00

void Unwind_00684a00(void)

{
  FUN_0059bc40();
  return;
}


// ==== 0x684a08 FUN_00684a08

void FUN_00684a08(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684a20 Unwind@00684a20

void Unwind_00684a20(void)

{
  FUN_00525be0();
  return;
}


// ==== 0x684a28 Unwind@00684a28

void Unwind_00684a28(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x10) + 0x20;
  }
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684a4f FUN_00684a4f

void FUN_00684a4f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684a60 Unwind@00684a60

void Unwind_00684a60(void)

{
  FUN_00525be0();
  return;
}


// ==== 0x684a68 Unwind@00684a68

void Unwind_00684a68(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 4) == 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 4) + 0x20;
  }
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684a8f FUN_00684a8f

void FUN_00684a8f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684aa0 Unwind@00684aa0

void Unwind_00684aa0(void)

{
  FUN_00525be0();
  return;
}


// ==== 0x684aa8 EAX_CarFX::_EAX_CarFX

/* [canon] audio low (ghidra) docs/re/sound.md */

void EAX_CarFX___EAX_CarFX(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ac0 Unwind@00684ac0

void Unwind_00684ac0(void)

{
  FUN_0052c910();
  return;
}


// ==== 0x684ac8 FUN_00684ac8

void FUN_00684ac8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ae0 Unwind@00684ae0

void Unwind_00684ae0(void)

{
  FUN_005223f0();
  return;
}


// ==== 0x684ae8 Unwind@00684ae8

void Unwind_00684ae8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  else {
    *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -0x10) + 0x20;
  }
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684b0f FUN_00684b0f

void FUN_00684b0f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684b20 Unwind@00684b20

void Unwind_00684b20(void)

{
  FUN_005223f0();
  return;
}


// ==== 0x684b28 Unwind@00684b28

void Unwind_00684b28(void)

{
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684b33 FUN_00684b33

void FUN_00684b33(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684b40 Unwind@00684b40

void Unwind_00684b40(void)

{
  FUN_00594fe0();
  return;
}


// ==== 0x684b48 FUN_00684b48

void FUN_00684b48(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684b60 Unwind@00684b60

void Unwind_00684b60(void)

{
  FUN_00594fe0();
  return;
}


// ==== 0x684b68 FUN_00684b68

void FUN_00684b68(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684b80 Unwind@00684b80

void Unwind_00684b80(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x9c);
  return;
}


// ==== 0x684b8f Unwind@00684b8f

void Unwind_00684b8f(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x1e0);
  return;
}


// ==== 0x684b9e Unwind@00684b9e

void Unwind_00684b9e(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x324);
  return;
}


// ==== 0x684bad Unwind@00684bad

void Unwind_00684bad(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x468);
  return;
}


// ==== 0x684bbc Unwind@00684bbc

void Unwind_00684bbc(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x5ac);
  return;
}


// ==== 0x684bcb Unwind@00684bcb

void Unwind_00684bcb(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x6f0);
  return;
}


// ==== 0x684bda Unwind@00684bda

void Unwind_00684bda(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x83c);
  return;
}


// ==== 0x684be9 Unwind@00684be9

void Unwind_00684be9(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x988);
  return;
}


// ==== 0x684bf8 Unwind@00684bf8

void Unwind_00684bf8(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0xad4);
  return;
}


// ==== 0x684c07 Unwind@00684c07

void Unwind_00684c07(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0xc20);
  return;
}


// ==== 0x684c16 Unwind@00684c16

void Unwind_00684c16(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0xd6c);
  return;
}


// ==== 0x684c25 Unwind@00684c25

void Unwind_00684c25(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0xeb8);
  return;
}


// ==== 0x684c34 Unwind@00684c34

void Unwind_00684c34(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x1004);
  return;
}


// ==== 0x684c43 Unwind@00684c43

void Unwind_00684c43(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x1150);
  return;
}


// ==== 0x684c52 Unwind@00684c52

void Unwind_00684c52(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x129c);
  return;
}


// ==== 0x684c61 Unwind@00684c61

void Unwind_00684c61(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x14) + 0x13e8);
  return;
}


// ==== 0x684c70 FUN_00684c70

void FUN_00684c70(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684c80 Unwind@00684c80

void Unwind_00684c80(void)

{
  FUN_0059bc40();
  return;
}


// ==== 0x684c88 FUN_00684c88

void FUN_00684c88(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ca0 Unwind@00684ca0

void Unwind_00684ca0(void)

{
  FUN_00579480();
  return;
}


// ==== 0x684cab FUN_00684cab

void FUN_00684cab(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684cc0 Unwind@00684cc0

void Unwind_00684cc0(void)

{
  FUN_00594fe0("OnlineSelectableTrack",0);
  return;
}


// ==== 0x684cd3 FUN_00684cd3

void FUN_00684cd3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ce0 Unwind@00684ce0

void Unwind_00684ce0(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x10));
  return;
}


// ==== 0x684ceb FUN_00684ceb

void FUN_00684ceb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684d00 Unwind@00684d00

void Unwind_00684d00(void)

{
  FUN_00538ea0();
  return;
}


// ==== 0x684d08 FUN_00684d08

void FUN_00684d08(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684d20 Unwind@00684d20

void Unwind_00684d20(void)

{
  FUN_00538ea0();
  return;
}


// ==== 0x684d28 FUN_00684d28

void FUN_00684d28(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684d40 Unwind@00684d40

void Unwind_00684d40(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 8));
  return;
}


// ==== 0x684d4b FUN_00684d4b

void FUN_00684d4b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684d60 Unwind@00684d60

void Unwind_00684d60(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 0xc));
  return;
}


// ==== 0x684d6b FUN_00684d6b

void FUN_00684d6b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684d80 Unwind@00684d80

void Unwind_00684d80(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}


// ==== 0x684d8b FUN_00684d8b

void FUN_00684d8b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684da0 Unwind@00684da0

void Unwind_00684da0(void)

{
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684da8 Unwind@00684da8

void Unwind_00684da8(void)

{
  FUN_005841f0();
  return;
}


// ==== 0x684db6 FUN_00684db6

void FUN_00684db6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684dc0 Unwind@00684dc0

void Unwind_00684dc0(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 8));
  return;
}


// ==== 0x684dcb Unwind@00684dcb

void Unwind_00684dcb(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 8));
  return;
}


// ==== 0x684dd6 FUN_00684dd6

void FUN_00684dd6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684de0 Unwind@00684de0

void Unwind_00684de0(void)

{
  FUN_00525be0();
  return;
}


// ==== 0x684de8 Unwind@00684de8

void Unwind_00684de8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x10) + 0x20;
  }
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684e0f FUN_00684e0f

void FUN_00684e0f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684e20 Unwind@00684e20

void Unwind_00684e20(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== 0x684e2b FUN_00684e2b

void FUN_00684e2b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684e40 Unwind@00684e40

void Unwind_00684e40(void)

{
  FUN_00525be0();
  return;
}


// ==== 0x684e48 Unwind@00684e48

void Unwind_00684e48(void)

{
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x684e53 FUN_00684e53

void FUN_00684e53(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684e60 Unwind@00684e60

void Unwind_00684e60(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x684e6b FUN_00684e6b

void FUN_00684e6b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684e80 Unwind@00684e80

void Unwind_00684e80(void)

{
  FUN_00594fe0("EAXSkids",0);
  return;
}


// ==== 0x684e93 FUN_00684e93

void FUN_00684e93(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ea0 Unwind@00684ea0

void Unwind_00684ea0(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x684eab Unwind@00684eab

void Unwind_00684eab(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x684eb6 Unwind@00684eb6

void Unwind_00684eb6(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}


// ==== 0x684ec1 FUN_00684ec1

void FUN_00684ec1(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ed0 Unwind@00684ed0

void Unwind_00684ed0(void)

{
  FENode___FENode();
  return;
}


// ==== 0x684ed8 FUN_00684ed8

void FUN_00684ed8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684ef0 Unwind@00684ef0

void Unwind_00684ef0(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x684ef8 FUN_00684ef8

void FUN_00684ef8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684f10 Unwind@00684f10

void Unwind_00684f10(void)

{
  FUN_00594fe0();
  return;
}


// ==== 0x684f18 FUN_00684f18

void FUN_00684f18(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684f30 Unwind@00684f30

void Unwind_00684f30(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x684f38 Unwind@00684f38

void Unwind_00684f38(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0xc),0x20,0x100,FUN_004fcab0);
  return;
}


// ==== 0x684f51 FUN_00684f51

void FUN_00684f51(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684f60 Unwind@00684f60

void Unwind_00684f60(void)

{
  FUN_004a9960();
  return;
}


// ==== 0x684f6e FUN_00684f6e

void FUN_00684f6e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684f80 Unwind@00684f80

void Unwind_00684f80(void)

{
  FUN_004a9d60();
  return;
}


// ==== 0x684f8b FUN_00684f8b

void FUN_00684f8b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684fa0 Unwind@00684fa0

void Unwind_00684fa0(void)

{
  FUN_0047b5c0();
  return;
}


// ==== 0x684fab FUN_00684fab

void FUN_00684fab(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684fc0 Unwind@00684fc0

void Unwind_00684fc0(void)

{
  FUN_0044cde0();
  return;
}


// ==== 0x684fc8 FUN_00684fc8

void FUN_00684fc8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x684fe0 Unwind@00684fe0

void Unwind_00684fe0(void)

{
  FUN_0059bc40();
  return;
}


// ==== 0x684fe8 Unwind@00684fe8

void Unwind_00684fe8(void)

{
  int unaff_EBP;
  
  FUN_0044ce00(*(int *)(unaff_EBP + -0x10) + 0x2c);
  return;
}


// ==== 0x684ff5 FUN_00684ff5

void FUN_00684ff5(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685000 Unwind@00685000

void Unwind_00685000(void)

{
  FUN_00594fe0("StyleMoment",0);
  return;
}


// ==== 0x685013 FUN_00685013

void FUN_00685013(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685020 Unwind@00685020

void Unwind_00685020(void)

{
  FUN_00594fe0();
  return;
}


// ==== 0x685028 FUN_00685028

void FUN_00685028(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685040 Unwind@00685040

void Unwind_00685040(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x68504b FUN_0068504b

void FUN_0068504b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685060 Unwind@00685060

void Unwind_00685060(void)

{
  FUN_00418d00();
  return;
}


// ==== 0x68506d Unwind@0068506d

void Unwind_0068506d(void)

{
  FUN_0041c060();
  return;
}


// ==== 0x68507a Unwind@0068507a

void Unwind_0068507a(void)

{
  FUN_0041c060();
  return;
}


// ==== 0x685087 Unwind@00685087

void Unwind_00685087(void)

{
  FUN_0041c060();
  return;
}


// ==== 0x685094 Unwind@00685094

void Unwind_00685094(void)

{
  FUN_0041c060();
  return;
}


// ==== 0x6850a1 Unwind@006850a1

void Unwind_006850a1(void)

{
  FUN_0041c060();
  return;
}


// ==== 0x6850ae FUN_006850ae

void FUN_006850ae(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6850c0 Unwind@006850c0

void Unwind_006850c0(void)

{
  FUN_0058e500();
  return;
}


// ==== 0x6850c8 Unwind@006850c8

void Unwind_006850c8(void)

{
  FUN_0058e500();
  return;
}


// ==== 0x6850d0 FUN_006850d0

void FUN_006850d0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6850e0 Unwind@006850e0

void Unwind_006850e0(void)

{
  FUN_0044a660();
  return;
}


// ==== 0x6850e8 FUN_006850e8

void FUN_006850e8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685100 Unwind@00685100

void Unwind_00685100(void)

{
  FUN_00594fe0("SpaceCadet::mpMoverListArray",0);
  return;
}


// ==== 0x685113 FUN_00685113

void FUN_00685113(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685120 Unwind@00685120

void Unwind_00685120(void)

{
  FUN_00577f00();
  return;
}


// ==== 0x68512b Unwind@0068512b

void Unwind_0068512b(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x685136 FUN_00685136

void FUN_00685136(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685140 Unwind@00685140

void Unwind_00685140(void)

{
  FUN_00577f00();
  return;
}


// ==== 0x68514b FUN_0068514b

void FUN_0068514b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685160 Unwind@00685160

void Unwind_00685160(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x685168 FUN_00685168

void FUN_00685168(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685180 Unwind@00685180

void Unwind_00685180(void)

{
  FUN_00594fe0("OnlineSelectableTrack",0);
  return;
}


// ==== 0x685193 FUN_00685193

void FUN_00685193(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6851a0 Unwind@006851a0

void Unwind_006851a0(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(undefined4 *)(unaff_EBP + -0x20));
  return;
}


// ==== 0x6851aa FUN_006851aa

void FUN_006851aa(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6851c0 Unwind@006851c0

void Unwind_006851c0(void)

{
  FUN_00594fe0("EAXS_MusicStream",0);
  return;
}


// ==== 0x6851d3 Unwind@006851d3

void Unwind_006851d3(void)

{
  FUN_00594fe0("EAXS_AmbStereoStream",0);
  return;
}


// ==== 0x6851e6 Unwind@006851e6

void Unwind_006851e6(void)

{
  FUN_00594fe0("EAXS_AmbMonoStream",0);
  return;
}


// ==== 0x6851f9 Unwind@006851f9

void Unwind_006851f9(void)

{
  FUN_00594fe0("EAXS_TCMStream",0);
  return;
}


// ==== 0x68520c Unwind@0068520c

void Unwind_0068520c(void)

{
  FUN_00594fe0("EAXS_SpeechStream",0);
  return;
}


// ==== 0x68521f FUN_0068521f

void FUN_0068521f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685230 Unwind@00685230

void Unwind_00685230(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 4),0x130,0x2c,NullUpdate_ret);
  return;
}


// ==== 0x685249 FUN_00685249

void FUN_00685249(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685260 Unwind@00685260

void Unwind_00685260(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(unaff_EBP + -0x10) + 0x100),0x220,2,EAXS_3DMixer___EAXS_3DMixer);
  return;
}


// ==== 0x68527b FUN_0068527b

void FUN_0068527b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685290 Unwind@00685290

void Unwind_00685290(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(unaff_EBP + -0x10) + 0x20),0x230,2,EAXS_3DMixer___EAXS_3DMixer);
  return;
}


// ==== 0x6852a9 FUN_006852a9

void FUN_006852a9(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6852c0 Unwind@006852c0

void Unwind_006852c0(void)

{
  EAXS_3DMixer___EAXS_3DMixer();
  return;
}


// ==== 0x6852c8 FUN_006852c8

void FUN_006852c8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6852e0 Unwind@006852e0

void Unwind_006852e0(void)

{
  FUN_005306a0();
  return;
}


// ==== 0x6852e8 FUN_006852e8

void FUN_006852e8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685300 Unwind@00685300

void Unwind_00685300(void)

{
  FUN_00594fe0("EAXSkids",0);
  return;
}


// ==== 0x685313 Unwind@00685313

void Unwind_00685313(void)

{
  FUN_00594fe0("EAXSkids",0);
  return;
}


// ==== 0x685326 FUN_00685326

void FUN_00685326(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685330 Unwind@00685330

void Unwind_00685330(void)

{
  FUN_00594fe0("EAXTurbo",0);
  return;
}


// ==== 0x685343 FUN_00685343

void FUN_00685343(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685350 Unwind@00685350

void Unwind_00685350(void)

{
  FUN_00520f50();
  return;
}


// ==== 0x68535e FUN_0068535e

void FUN_0068535e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685370 Unwind@00685370

void Unwind_00685370(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x68537b FUN_0068537b

void FUN_0068537b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685390 Unwind@00685390

void Unwind_00685390(void)

{
  FUN_00500560();
  return;
}


// ==== 0x685398 FUN_00685398

void FUN_00685398(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6853b0 Unwind@006853b0

void Unwind_006853b0(void)

{
  FENode___FENode();
  return;
}


// ==== 0x6853b8 Unwind@006853b8

void Unwind_006853b8(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x6853c3 Unwind@006853c3

void Unwind_006853c3(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x6853ce Unwind@006853ce

void Unwind_006853ce(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x6853d9 Unwind@006853d9

void Unwind_006853d9(void)

{
  FUN_004ff660();
  return;
}


// ==== 0x6853e6 Unwind@006853e6

void Unwind_006853e6(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x6853f4 FUN_006853f4

void FUN_006853f4(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685400 Unwind@00685400

void Unwind_00685400(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685408 Unwind@00685408

void Unwind_00685408(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685413 Unwind@00685413

void Unwind_00685413(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x68541e FUN_0068541e

void FUN_0068541e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685430 Unwind@00685430

void Unwind_00685430(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685438 FUN_00685438

void FUN_00685438(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685450 Unwind@00685450

void Unwind_00685450(void)

{
  FUN_004fef10();
  return;
}


// ==== 0x685458 FUN_00685458

void FUN_00685458(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685470 Unwind@00685470

void Unwind_00685470(void)

{
  FUN_00500560();
  return;
}


// ==== 0x685478 FUN_00685478

void FUN_00685478(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685490 Unwind@00685490

void Unwind_00685490(void)

{
  FUN_00594fe0("ZonePreview Emitters",0);
  return;
}


// ==== 0x6854a3 FUN_006854a3

void FUN_006854a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6854b0 Unwind@006854b0

void Unwind_006854b0(void)

{
  FUN_0046a980();
  return;
}


// ==== 0x6854b8 FUN_006854b8

void FUN_006854b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6854d0 Unwind@006854d0

void Unwind_006854d0(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x6854db FUN_006854db

void FUN_006854db(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6854f0 Unwind@006854f0

void Unwind_006854f0(void)

{
  FUN_00471dd0();
  return;
}


// ==== 0x6854f8 FUN_006854f8

void FUN_006854f8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685510 Unwind@00685510

void Unwind_00685510(void)

{
  FUN_00424fd0();
  return;
}


// ==== 0x685518 Unwind@00685518

void Unwind_00685518(void)

{
  StringBufPair_Destroy();
  return;
}


// ==== 0x685526 FUN_00685526

void FUN_00685526(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685530 Unwind@00685530

void Unwind_00685530(void)

{
  int unaff_EBP;
  
  FUN_00462250(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x68553a FUN_0068553a

void FUN_0068553a(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685550 Unwind@00685550

void Unwind_00685550(void)

{
  FUN_00594fe0("Smoke Show PreviewComet",0);
  return;
}


// ==== 0x685563 FUN_00685563

void FUN_00685563(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685570 Unwind@00685570

void Unwind_00685570(void)

{
  FUN_00594fe0("ScrollerDatumNode",0);
  return;
}


// ==== 0x685583 FUN_00685583

void FUN_00685583(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685590 Unwind@00685590

void Unwind_00685590(void)

{
  int unaff_EBP;
  
  FUN_004b39d0(*(undefined4 *)(unaff_EBP + -0xb1c),"FERaceEvent");
  return;
}


// ==== 0x6855a5 FUN_006855a5

void FUN_006855a5(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6855b0 Unwind@006855b0

void Unwind_006855b0(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x6855b8 FUN_006855b8

void FUN_006855b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6855d0 Unwind@006855d0

void Unwind_006855d0(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0xe0),0x18,2,ListRef_Release);
  return;
}


// ==== 0x6855e8 FUN_006855e8

void FUN_006855e8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685600 Unwind@00685600

void Unwind_00685600(void)

{
  FUN_00578c70();
  return;
}


// ==== 0x685608 FUN_00685608

void FUN_00685608(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685620 Unwind@00685620

void Unwind_00685620(void)

{
  FUN_00579480();
  return;
}


// ==== 0x68562e FUN_0068562e

void FUN_0068562e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685640 Unwind@00685640

void Unwind_00685640(void)

{
  FUN_00441fa0();
  return;
}


// ==== 0x68564b FUN_0068564b

void FUN_0068564b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685660 Unwind@00685660

void Unwind_00685660(void)

{
  FUN_00574b00();
  return;
}


// ==== 0x685668 FUN_00685668

void FUN_00685668(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685680 Unwind@00685680

void Unwind_00685680(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x68568e Unwind@0068568e

void Unwind_0068568e(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(unaff_EBP + 4) + 0x544),8,0x1d,List_DeleteAllNodes);
  return;
}


// ==== 0x6856a6 Unwind@006856a6

void Unwind_006856a6(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x62c),8,0x1c,FUN_00571560);
  return;
}


// ==== 0x6856be Unwind@006856be

void Unwind_006856be(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0xe6c),0x18,0x78,ListRef_Release)
  ;
  return;
}


// ==== 0x6856d6 Unwind@006856d6

void Unwind_006856d6(void)

{
  IList_FreeNodes_Member2C();
  return;
}


// ==== 0x6856e3 Unwind@006856e3

void Unwind_006856e3(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x19e0),0x68,2,NullUpdate_ret);
  return;
}


// ==== 0x6856fb FUN_006856fb

void FUN_006856fb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685710 Unwind@00685710

void Unwind_00685710(void)

{
  int unaff_EBP;
  
  FUN_00594fe0(*(int *)(unaff_EBP + -0x10) + 4,0,*(uint *)(unaff_EBP + 8) & 7);
  return;
}


// ==== 0x68572c FUN_0068572c

void FUN_0068572c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685740 Unwind@00685740

void Unwind_00685740(void)

{
  FUN_0052c910();
  return;
}


// ==== 0x685748 Unwind@00685748

void Unwind_00685748(void)

{
  FUN_00535530();
  return;
}


// ==== 0x685756 Unwind@00685756

void Unwind_00685756(void)

{
  FUN_00534da0();
  return;
}


// ==== 0x685764 Unwind@00685764

void Unwind_00685764(void)

{
  FUN_00535150();
  return;
}


// ==== 0x685772 Unwind@00685772

void Unwind_00685772(void)

{
  FUN_00527270();
  return;
}


// ==== 0x685780 Unwind@00685780

void Unwind_00685780(void)

{
  FUN_005276c0();
  return;
}


// ==== 0x68578e Unwind@0068578e

void Unwind_0068578e(void)

{
  FUN_005841f0();
  return;
}


// ==== 0x68579c Unwind@0068579c

void Unwind_0068579c(void)

{
  FUN_0052cbd0();
  return;
}


// ==== 0x6857aa Unwind@006857aa

void Unwind_006857aa(void)

{
  FUN_0052a650();
  return;
}


// ==== 0x6857b8 Unwind@006857b8

void Unwind_006857b8(void)

{
  FUN_00525bb0();
  return;
}


// ==== 0x6857c6 Unwind@006857c6

void Unwind_006857c6(void)

{
  FUN_005841f0();
  return;
}


// ==== 0x6857d4 FUN_006857d4

void FUN_006857d4(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6857e0 Unwind@006857e0

void Unwind_006857e0(void)

{
  FUN_0052c910();
  return;
}


// ==== 0x6857e8 Unwind@006857e8

void Unwind_006857e8(void)

{
  FUN_00535530();
  return;
}


// ==== 0x6857f6 Unwind@006857f6

void Unwind_006857f6(void)

{
  FUN_00534da0();
  return;
}


// ==== 0x685804 FUN_00685804

void FUN_00685804(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685810 Unwind@00685810

void Unwind_00685810(void)

{
  FUN_00594fe0("EAXAITunerCar",0);
  return;
}


// ==== 0x685823 Unwind@00685823

void Unwind_00685823(void)

{
  FUN_00594fe0("EAXAITunerCar",0);
  return;
}


// ==== 0x685836 FUN_00685836

void FUN_00685836(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685840 Unwind@00685840

void Unwind_00685840(void)

{
  FUN_00594fe0("EAXTunerCar",0);
  return;
}


// ==== 0x685853 Unwind@00685853

void Unwind_00685853(void)

{
  FUN_00594fe0("EAXTunerCar",0);
  return;
}


// ==== 0x685866 FUN_00685866

void FUN_00685866(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685870 Unwind@00685870

void Unwind_00685870(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685878 Unwind@00685878

void Unwind_00685878(void)

{
  FUN_00500740();
  return;
}


// ==== 0x685883 FUN_00685883

void FUN_00685883(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685890 Unwind@00685890

void Unwind_00685890(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685898 Unwind@00685898

void Unwind_00685898(void)

{
  FUN_00500740();
  return;
}


// ==== 0x6858a3 FUN_006858a3

void FUN_006858a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6858b0 Unwind@006858b0

void Unwind_006858b0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6858b8 FUN_006858b8

void FUN_006858b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6858d0 Unwind@006858d0

void Unwind_006858d0(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x6858d8 Unwind@006858d8

void Unwind_006858d8(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(unaff_EBP + 4) + 0xc),0x18,0x40,FEMessageResponse___FEMessageResponse
            );
  return;
}


// ==== 0x6858ee FUN_006858ee

void FUN_006858ee(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685900 Unwind@00685900

void Unwind_00685900(void)

{
  FUN_004fcb10();
  return;
}


// ==== 0x68590d Unwind@0068590d

void Unwind_0068590d(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x68591b Unwind@0068591b

void Unwind_0068591b(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685929 Unwind@00685929

void Unwind_00685929(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685937 Unwind@00685937

void Unwind_00685937(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685945 Unwind@00685945

void Unwind_00685945(void)

{
  FUN_004fcb10();
  return;
}


// ==== 0x685952 FUN_00685952

void FUN_00685952(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685960 Unwind@00685960

void Unwind_00685960(void)

{
  IList_FreeNodes_Member2C();
  return;
}


// ==== 0x68596b Unwind@0068596b

void Unwind_0068596b(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x50),0x68,0x20,NullUpdate_ret);
  return;
}


// ==== 0x685981 FUN_00685981

void FUN_00685981(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685990 Unwind@00685990

void Unwind_00685990(void)

{
  FUN_004a9d60();
  return;
}


// ==== 0x68599b Unwind@0068599b

void Unwind_0068599b(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0xf954),0xf944,2,FUN_004a9d60);
  return;
}


// ==== 0x6859b6 FUN_006859b6

void FUN_006859b6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6859c0 Unwind@006859c0

void Unwind_006859c0(void)

{
  FUN_00424fd0();
  return;
}


// ==== 0x6859c8 FUN_006859c8

void FUN_006859c8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6859e0 Unwind@006859e0

void Unwind_006859e0(void)

{
  FUN_005a4530();
  return;
}


// ==== 0x6859e8 FUN_006859e8

void FUN_006859e8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685a00 Unwind@00685a00

void Unwind_00685a00(void)

{
  FUN_005794c0();
  return;
}


// ==== 0x685a08 FUN_00685a08

void FUN_00685a08(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685a20 Unwind@00685a20

void Unwind_00685a20(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 0xc));
  return;
}


// ==== 0x685a2b Unwind@00685a2b

void Unwind_00685a2b(void)

{
  int unaff_EBP;
  
  FUN_0053d910(*(undefined4 *)(unaff_EBP + 0xc));
  return;
}


// ==== 0x685a36 FUN_00685a36

void FUN_00685a36(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685a40 Unwind@00685a40

void Unwind_00685a40(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685a48 Unwind@00685a48

void Unwind_00685a48(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(unaff_EBP + 4) + 0xc),0x34,0x20,FEScript___FEScript);
  return;
}


// ==== 0x685a5e FUN_00685a5e

void FUN_00685a5e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685a70 Unwind@00685a70

void Unwind_00685a70(void)

{
  FUN_00500560();
  return;
}


// ==== 0x685a78 Unwind@00685a78

void Unwind_00685a78(void)

{
  FUN_00594fe0();
  return;
}


// ==== 0x685a80 FUN_00685a80

void FUN_00685a80(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685a90 Unwind@00685a90

void Unwind_00685a90(void)

{
  FUN_004fcab0();
  return;
}


// ==== 0x685a98 Unwind@00685a98

void Unwind_00685a98(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685aa3 Unwind@00685aa3

void Unwind_00685aa3(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685aae Unwind@00685aae

void Unwind_00685aae(void)

{
  FUN_00502b70();
  return;
}


// ==== 0x685ab6 FUN_00685ab6

void FUN_00685ab6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685ac0 Unwind@00685ac0

void Unwind_00685ac0(void)

{
  FUN_004fef10();
  return;
}


// ==== 0x685ac8 Unwind@00685ac8

void Unwind_00685ac8(void)

{
  FUN_004ee650();
  return;
}


// ==== 0x685ad3 FUN_00685ad3

void FUN_00685ad3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685ae0 Unwind@00685ae0

void Unwind_00685ae0(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x685aeb FUN_00685aeb

void FUN_00685aeb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685b00 Unwind@00685b00

void Unwind_00685b00(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x685b0b FUN_00685b0b

void FUN_00685b0b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685b20 Unwind@00685b20

void Unwind_00685b20(void)

{
  FUN_00483550();
  return;
}


// ==== 0x685b28 Unwind@00685b28

void Unwind_00685b28(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x685b33 Unwind@00685b33

void Unwind_00685b33(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x685b41 Unwind@00685b41

void Unwind_00685b41(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x685b4f Unwind@00685b4f

void Unwind_00685b4f(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x685b5d FUN_00685b5d

void FUN_00685b5d(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685b70 Unwind@00685b70

void Unwind_00685b70(void)

{
  FUN_00483550();
  return;
}


// ==== 0x685b78 Unwind@00685b78

void Unwind_00685b78(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x685b83 FUN_00685b83

void FUN_00685b83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685b90 Unwind@00685b90

void Unwind_00685b90(void)

{
  FUN_00483550();
  return;
}


// ==== 0x685b98 FUN_00685b98

void FUN_00685b98(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685bb0 Unwind@00685bb0

void Unwind_00685bb0(void)

{
  FUN_0047dc10();
  return;
}


// ==== 0x685bb8 FUN_00685bb8

void FUN_00685bb8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685bd0 Unwind@00685bd0

void Unwind_00685bd0(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x685bd8 Unwind@00685bd8

void Unwind_00685bd8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 4) == 0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + 4) + 8;
  }
  FUN_00474430();
  return;
}


// ==== 0x685bff FUN_00685bff

void FUN_00685bff(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685c10 Unwind@00685c10

void Unwind_00685c10(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x685c18 Unwind@00685c18

void Unwind_00685c18(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 4) == 0) {
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + 4) + 8;
  }
  FUN_00474430();
  return;
}


// ==== 0x685c3f FUN_00685c3f

void FUN_00685c3f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685c50 Unwind@00685c50

void Unwind_00685c50(void)

{
  FUN_0046a410();
  return;
}


// ==== 0x685c58 FUN_00685c58

void FUN_00685c58(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685c70 Unwind@00685c70

void Unwind_00685c70(void)

{
  FUN_004688c0();
  return;
}


// ==== 0x685c78 FUN_00685c78

void FUN_00685c78(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685c90 Unwind@00685c90

void Unwind_00685c90(void)

{
  FUN_004053c0();
  return;
}


// ==== 0x685c98 Unwind@00685c98

void Unwind_00685c98(void)

{
  FUN_00405490();
  return;
}


// ==== 0x685ca3 FUN_00685ca3

void FUN_00685ca3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685cb0 Unwind@00685cb0

void Unwind_00685cb0(void)

{
  FUN_0046a410();
  return;
}


// ==== 0x685cbb FUN_00685cbb

void FUN_00685cbb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685cd0 Unwind@00685cd0

void Unwind_00685cd0(void)

{
  FUN_00594fe0("SND_TROLLEY",0);
  return;
}


// ==== 0x685ce3 Unwind@00685ce3

void Unwind_00685ce3(void)

{
  FUN_00594fe0("SND_TRAIN",0);
  return;
}


// ==== 0x685cf6 Unwind@00685cf6

void Unwind_00685cf6(void)

{
  FUN_00594fe0("SND_PLANE",0);
  return;
}


// ==== 0x685d09 FUN_00685d09

void FUN_00685d09(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685d20 Unwind@00685d20

void Unwind_00685d20(void)

{
  FUN_004fef10();
  return;
}


// ==== 0x685d28 Unwind@00685d28

void Unwind_00685d28(void)

{
  WString_Free();
  return;
}


// ==== 0x685d33 FUN_00685d33

void FUN_00685d33(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685d40 Unwind@00685d40

void Unwind_00685d40(void)

{
  FUN_0046a410();
  return;
}


// ==== 0x685d4b Unwind@00685d4b

void Unwind_00685d4b(void)

{
  FUN_00473460();
  return;
}


// ==== 0x685d59 FUN_00685d59

void FUN_00685d59(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685d70 Unwind@00685d70

void Unwind_00685d70(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x685d78 FUN_00685d78

void FUN_00685d78(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685d90 Unwind@00685d90

void Unwind_00685d90(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x9c);
  return;
}


// ==== 0x685d9f Unwind@00685d9f

void Unwind_00685d9f(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x1e0);
  return;
}


// ==== 0x685dae Unwind@00685dae

void Unwind_00685dae(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x324);
  return;
}


// ==== 0x685dbd Unwind@00685dbd

void Unwind_00685dbd(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x468);
  return;
}


// ==== 0x685dcc Unwind@00685dcc

void Unwind_00685dcc(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x5ac);
  return;
}


// ==== 0x685ddb Unwind@00685ddb

void Unwind_00685ddb(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x6f0);
  return;
}


// ==== 0x685dea Unwind@00685dea

void Unwind_00685dea(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x83c);
  return;
}


// ==== 0x685df9 Unwind@00685df9

void Unwind_00685df9(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x988);
  return;
}


// ==== 0x685e08 Unwind@00685e08

void Unwind_00685e08(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0xad4);
  return;
}


// ==== 0x685e17 Unwind@00685e17

void Unwind_00685e17(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0xc20);
  return;
}


// ==== 0x685e26 Unwind@00685e26

void Unwind_00685e26(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0xd6c);
  return;
}


// ==== 0x685e35 Unwind@00685e35

void Unwind_00685e35(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0xeb8);
  return;
}


// ==== 0x685e44 Unwind@00685e44

void Unwind_00685e44(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x1004);
  return;
}


// ==== 0x685e53 Unwind@00685e53

void Unwind_00685e53(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x1150);
  return;
}


// ==== 0x685e62 Unwind@00685e62

void Unwind_00685e62(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x129c);
  return;
}


// ==== 0x685e71 Unwind@00685e71

void Unwind_00685e71(void)

{
  int unaff_EBP;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(*(int *)(unaff_EBP + -0x10) + 0x13e8);
  return;
}


// ==== 0x685e80 FUN_00685e80

void FUN_00685e80(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685e90 Unwind@00685e90

void Unwind_00685e90(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x150));
  return;
}


// ==== 0x685e9e FUN_00685e9e

void FUN_00685e9e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685eb0 Unwind@00685eb0

void Unwind_00685eb0(void)

{
  FUN_004688c0();
  return;
}


// ==== 0x685ebb Unwind@00685ebb

void Unwind_00685ebb(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x685ecb FUN_00685ecb

void FUN_00685ecb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685ee0 Unwind@00685ee0

void Unwind_00685ee0(void)

{
  FUN_004688c0();
  return;
}


// ==== 0x685ee8 Unwind@00685ee8

void Unwind_00685ee8(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x685ef5 FUN_00685ef5

void FUN_00685ef5(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685f00 Unwind@00685f00

void Unwind_00685f00(void)

{
  FUN_00594fe0("TrackPathCoordinate",0);
  return;
}


// ==== 0x685f13 FUN_00685f13

void FUN_00685f13(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685f20 Unwind@00685f20

void Unwind_00685f20(void)

{
  FUN_00594fe0("Avoidable",0);
  return;
}


// ==== 0x685f33 FUN_00685f33

void FUN_00685f33(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685f40 Unwind@00685f40

void Unwind_00685f40(void)

{
  FUN_005779c0();
  return;
}


// ==== 0x685f48 Unwind@00685f48

void Unwind_00685f48(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x10) + 0x1c;
  }
  FUN_00579600(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== 0x685f71 FUN_00685f71

void FUN_00685f71(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685f80 Unwind@00685f80

void Unwind_00685f80(void)

{
  FUN_00577290();
  return;
}


// ==== 0x685f88 Unwind@00685f88

void Unwind_00685f88(void)

{
  FUN_00576f10();
  return;
}


// ==== 0x685f90 FUN_00685f90

void FUN_00685f90(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685fa0 Unwind@00685fa0

void Unwind_00685fa0(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x685fab Unwind@00685fab

void Unwind_00685fab(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x685fb6 FUN_00685fb6

void FUN_00685fb6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685fc0 Unwind@00685fc0

void Unwind_00685fc0(void)

{
  FUN_00594fe0("EOT Sound Obj",0);
  return;
}


// ==== 0x685fd3 FUN_00685fd3

void FUN_00685fd3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x685fe0 Unwind@00685fe0

void Unwind_00685fe0(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 4));
  return;
}


// ==== 0x685feb FUN_00685feb

void FUN_00685feb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686000 Unwind@00686000

void Unwind_00686000(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68600b FUN_0068600b

void FUN_0068600b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686020 Unwind@00686020

void Unwind_00686020(void)

{
  FUN_00483550();
  return;
}


// ==== 0x68602b FUN_0068602b

void FUN_0068602b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686040 Unwind@00686040

void Unwind_00686040(void)

{
  FUN_0044a170();
  return;
}


// ==== 0x686048 FUN_00686048

void FUN_00686048(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686060 Unwind@00686060

void Unwind_00686060(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68606d FUN_0068606d

void FUN_0068606d(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686080 Unwind@00686080

void Unwind_00686080(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x60));
  return;
}


// ==== 0x68608b FUN_0068608b

void FUN_0068608b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6860a0 Unwind@006860a0

void Unwind_006860a0(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(unaff_EBP + -0x390),0x38,0x10,NullUpdate_ret);
  return;
}


// ==== 0x6860b6 FUN_006860b6

void FUN_006860b6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6860c0 Unwind@006860c0

void Unwind_006860c0(void)

{
  FUN_00594fe0("EAXMixMgr",0);
  return;
}


// ==== 0x6860d3 EAXSND8Wrapper::EAXSND8Wrapper__SEH_unwind_funclet__not_the_ctor_

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXSND8Wrapper__EAXSND8Wrapper__SEH_unwind_funclet__not_the_ctor_(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6860e0 Unwind@006860e0

void Unwind_006860e0(void)

{
  FUN_004f7870();
  return;
}


// ==== 0x6860eb FUN_006860eb

void FUN_006860eb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686100 Unwind@00686100

void Unwind_00686100(void)

{
  FUN_004f7870();
  return;
}


// ==== 0x68610b FUN_0068610b

void FUN_0068610b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686120 Unwind@00686120

void Unwind_00686120(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x68612b FUN_0068612b

void FUN_0068612b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686140 Unwind@00686140

void Unwind_00686140(void)

{
  FUN_00494890();
  return;
}


// ==== 0x68614b FUN_0068614b

void FUN_0068614b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686160 Unwind@00686160

void Unwind_00686160(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(unaff_EBP + -0x650),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x686176 Unwind@00686176

void Unwind_00686176(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(unaff_EBP + -0xc90),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x68618c FUN_0068618c

void FUN_0068618c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6861a0 Unwind@006861a0

void Unwind_006861a0(void)

{
  int unaff_EBP;
  
  FUN_00438a30(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== 0x6861ab FUN_006861ab

void FUN_006861ab(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6861c0 Unwind@006861c0

void Unwind_006861c0(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x6861cb Unwind@006861cb

void Unwind_006861cb(void)

{
  FUN_00490530();
  return;
}


// ==== 0x6861d6 Unwind@006861d6

void Unwind_006861d6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== 0x6861e1 Unwind@006861e1

void Unwind_006861e1(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x6861ec FUN_006861ec

void FUN_006861ec(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686200 Unwind@00686200

void Unwind_00686200(void)

{
  FUN_00594fe0("TerrainEffectEmitters",0);
  return;
}


// ==== 0x686213 FUN_00686213

void FUN_00686213(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686220 Unwind@00686220

void Unwind_00686220(void)

{
  FUN_00594fe0("FernShakerInfoTable",0);
  return;
}


// ==== 0x686233 FUN_00686233

void FUN_00686233(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686240 Unwind@00686240

void Unwind_00686240(void)

{
  FUN_0058ce90();
  return;
}


// ==== 0x68624b Unwind@0068624b

void Unwind_0068624b(void)

{
  FUN_0058ced0();
  return;
}


// ==== 0x686256 Unwind@00686256

void Unwind_00686256(void)

{
  FUN_0058cf10();
  return;
}


// ==== 0x686261 Unwind@00686261

void Unwind_00686261(void)

{
  FUN_0058cf50();
  return;
}


// ==== 0x68626c FUN_0068626c

void FUN_0068626c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686280 Unwind@00686280

void Unwind_00686280(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68628b FUN_0068628b

void FUN_0068628b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6862a0 Unwind@006862a0

void Unwind_006862a0(void)

{
  FUN_00594fe0("FEngRenderer",0);
  return;
}


// ==== 0x6862b3 FUN_006862b3

void FUN_006862b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6862c0 Unwind@006862c0

void Unwind_006862c0(void)

{
  FUN_00594fe0("FEPackageData",0);
  return;
}


// ==== 0x6862d3 FUN_006862d3

void FUN_006862d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6862e0 Unwind@006862e0

void Unwind_006862e0(void)

{
  int unaff_EBP;
  
  FUN_004b39d0(*(undefined4 *)(unaff_EBP + -0xe88));
  return;
}


// ==== 0x6862ee FUN_006862ee

void FUN_006862ee(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686300 Unwind@00686300

void Unwind_00686300(void)

{
  FUN_00483550();
  return;
}


// ==== 0x68630b Unwind@0068630b

void Unwind_0068630b(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x686319 Unwind@00686319

void Unwind_00686319(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x68632a Unwind@0068632a

void Unwind_0068632a(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x68633b Unwind@0068633b

void Unwind_0068633b(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x68634c Unwind@0068634c

void Unwind_0068634c(void)

{
  FUN_00490530();
  return;
}


// ==== 0x68635d Unwind@0068635d

void Unwind_0068635d(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68636d FUN_0068636d

void FUN_0068636d(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686380 Unwind@00686380

void Unwind_00686380(void)

{
  FUN_00483550();
  return;
}


// ==== 0x68638b Unwind@0068638b

void Unwind_0068638b(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x686399 Unwind@00686399

void Unwind_00686399(void)

{
  FUN_005825c0();
  return;
}


// ==== 0x6863a7 Unwind@006863a7

void Unwind_006863a7(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x6863b7 FUN_006863b7

void FUN_006863b7(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6863d0 Unwind@006863d0

void Unwind_006863d0(void)

{
  FUN_00594fe0("VisibleDrivingLine",0);
  return;
}


// ==== 0x6863e3 FUN_006863e3

void FUN_006863e3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6863f0 Unwind@006863f0

void Unwind_006863f0(void)

{
  FUN_00578c70();
  return;
}


// ==== 0x6863f8 Unwind@006863f8

void Unwind_006863f8(void)

{
  FUN_00455510();
  return;
}


// ==== 0x686403 FUN_00686403

void FUN_00686403(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686410 Unwind@00686410

void Unwind_00686410(void)

{
  FUN_00594fe0("AnimationMover",0);
  return;
}


// ==== 0x686423 FUN_00686423

void FUN_00686423(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686430 Unwind@00686430

void Unwind_00686430(void)

{
  FUN_00594fe0("cFEng",0);
  return;
}


// ==== 0x686443 FUN_00686443

void FUN_00686443(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686450 Unwind@00686450

void Unwind_00686450(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x686458 Unwind@00686458

void Unwind_00686458(void)

{
  FUN_00474430();
  return;
}


// ==== 0x686463 Unwind@00686463

void Unwind_00686463(void)

{
  FUN_0046c7a0();
  return;
}


// ==== 0x68646b FUN_0068646b

void FUN_0068646b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686480 Unwind@00686480

void Unwind_00686480(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x686488 Unwind@00686488

void Unwind_00686488(void)

{
  FUN_00474430();
  return;
}


// ==== 0x686493 Unwind@00686493

void Unwind_00686493(void)

{
  FUN_00474060();
  return;
}


// ==== 0x68649b FUN_0068649b

void FUN_0068649b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6864b0 Unwind@006864b0

void Unwind_006864b0(void)

{
  FUN_004667a0();
  return;
}


// ==== 0x6864b8 FUN_006864b8

void FUN_006864b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6864d0 Unwind@006864d0

void Unwind_006864d0(void)

{
  FUN_004667a0();
  return;
}


// ==== 0x6864db FUN_006864db

void FUN_006864db(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6864f0 Unwind@006864f0

void Unwind_006864f0(void)

{
  FUN_0041f6c0();
  return;
}


// ==== 0x6864f8 FUN_006864f8

void FUN_006864f8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686510 Unwind@00686510

void Unwind_00686510(void)

{
  FUN_0041f620();
  return;
}


// ==== 0x686518 FUN_00686518

void FUN_00686518(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686530 Unwind@00686530

void Unwind_00686530(void)

{
  FUN_004250c0();
  return;
}


// ==== 0x686538 FUN_00686538

void FUN_00686538(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686550 Unwind@00686550

void Unwind_00686550(void)

{
  FUN_00424fd0();
  return;
}


// ==== 0x686558 Unwind@00686558

void Unwind_00686558(void)

{
  FUN_00455510();
  return;
}


// ==== 0x686560 FUN_00686560

void FUN_00686560(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686570 Unwind@00686570

void Unwind_00686570(void)

{
  FUN_00455510();
  return;
}


// ==== 0x68657b FUN_0068657b

void FUN_0068657b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686590 Unwind@00686590

void Unwind_00686590(void)

{
  FUN_00455510();
  return;
}


// ==== 0x686598 FUN_00686598

void FUN_00686598(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6865b0 Unwind@006865b0

void Unwind_006865b0(void)

{
  FUN_0044a130();
  return;
}


// ==== 0x6865b8 FUN_006865b8

void FUN_006865b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6865d0 Unwind@006865d0

void Unwind_006865d0(void)

{
  FUN_0044a130();
  return;
}


// ==== 0x6865d8 FUN_006865d8

void FUN_006865d8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6865f0 Unwind@006865f0

void Unwind_006865f0(void)

{
  FUN_0044a130();
  return;
}


// ==== 0x6865f8 FUN_006865f8

void FUN_006865f8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686610 Unwind@00686610

void Unwind_00686610(void)

{
  FUN_0059bc40();
  return;
}


// ==== 0x68661b Unwind@0068661b

void Unwind_0068661b(void)

{
  int unaff_EBP;
  
  FUN_0044ce00(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x2c);
  return;
}


// ==== 0x68662b FUN_0068662b

void FUN_0068662b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686640 Unwind@00686640

void Unwind_00686640(void)

{
  FUN_00447a90();
  return;
}


// ==== 0x686648 FUN_00686648

void FUN_00686648(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686660 Unwind@00686660

void Unwind_00686660(void)

{
  FUN_00594fe0("PhysicsMover",0);
  return;
}


// ==== 0x686673 Unwind@00686673

void Unwind_00686673(void)

{
  FUN_00425120();
  return;
}


// ==== 0x68667b Unwind@0068667b

void Unwind_0068667b(void)

{
  FUN_00594fe0("BeltMover",0);
  return;
}


// ==== 0x68668e FUN_0068668e

void FUN_0068668e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6866a0 Unwind@006866a0

void Unwind_006866a0(void)

{
  FUN_00455250();
  return;
}


// ==== 0x6866a8 Unwind@006866a8

void Unwind_006866a8(void)

{
  FUN_00455250();
  return;
}


// ==== 0x6866b0 FUN_006866b0

void FUN_006866b0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6866c0 Unwind@006866c0

void Unwind_006866c0(void)

{
  FUN_0058a440();
  return;
}


// ==== 0x6866c8 FUN_006866c8

void FUN_006866c8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6866e0 Unwind@006866e0

void Unwind_006866e0(void)

{
  FUN_0044a660();
  return;
}


// ==== 0x6866e8 Unwind@006866e8

void Unwind_006866e8(void)

{
  FUN_00594fe0("PsychoDriver",0);
  return;
}


// ==== 0x6866fb FUN_006866fb

void FUN_006866fb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686710 Unwind@00686710

void Unwind_00686710(void)

{
  FUN_00578e60();
  return;
}


// ==== 0x686718 FUN_00686718

void FUN_00686718(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686730 Unwind@00686730

void Unwind_00686730(void)

{
  FUN_00577ff0();
  return;
}


// ==== 0x686738 Unwind@00686738

void Unwind_00686738(void)

{
  FUN_00577ff0();
  return;
}


// ==== 0x686740 FUN_00686740

void FUN_00686740(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686750 Unwind@00686750

void Unwind_00686750(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x686761 Unwind@00686761

void Unwind_00686761(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x544),8,0x1d,List_DeleteAllNodes)
  ;
  return;
}


// ==== 0x68677c Unwind@0068677c

void Unwind_0068677c(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x62c),8,0x1c,FUN_00571560);
  return;
}


// ==== 0x686797 Unwind@00686797

void Unwind_00686797(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0xe6c),0x18,0x78,ListRef_Release);
  return;
}


// ==== 0x6867b2 Unwind@006867b2

void Unwind_006867b2(void)

{
  IList_FreeNodes_Member2C();
  return;
}


// ==== 0x6867c2 Unwind@006867c2

void Unwind_006867c2(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x19e0),0x68,2,NullUpdate_ret);
  return;
}


// ==== 0x6867dd Unwind@006867dd

void Unwind_006867dd(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator
            ((void *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 8) + 0x1ac0),0xa0,2,NullUpdate_ret);
  return;
}


// ==== 0x6867fb FUN_006867fb

void FUN_006867fb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686810 Unwind@00686810

void Unwind_00686810(void)

{
  FUN_00594fe0("CarRenderInfo",0);
  return;
}


// ==== 0x686823 FUN_00686823

void FUN_00686823(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686830 Unwind@00686830

void Unwind_00686830(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x68683b FUN_0068683b

void FUN_0068683b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686850 Unwind@00686850

void Unwind_00686850(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686858 FUN_00686858

void FUN_00686858(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686863 FUN_00686863

void FUN_00686863(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x686870 Unwind@00686870

void Unwind_00686870(void)

{
  FUN_00483550();
  return;
}


// ==== 0x686878 FUN_00686878

void FUN_00686878(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686890 Unwind@00686890

void Unwind_00686890(void)

{
  int unaff_EBP;
  
  FUN_0045e080(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x68689a Unwind@0068689a

void Unwind_0068689a(void)

{
  int unaff_EBP;
  
  FUN_00460f50(*(int *)(unaff_EBP + 4) + 0x250);
  return;
}


// ==== 0x6868a9 FUN_006868a9

void FUN_006868a9(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6868c0 Unwind@006868c0

void Unwind_006868c0(void)

{
  int unaff_EBP;
  
  FUN_00462250(*(undefined4 *)(unaff_EBP + 4));
  return;
}


// ==== 0x6868ca Unwind@006868ca

void Unwind_006868ca(void)

{
  FUN_00594fe0("DragDriver",0);
  return;
}


// ==== 0x6868dd FUN_006868dd

void FUN_006868dd(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6868f0 Unwind@006868f0

void Unwind_006868f0(void)

{
  FUN_00436fe0();
  return;
}


// ==== 0x6868f8 Unwind@006868f8

void Unwind_006868f8(void)

{
  FUN_005841f0();
  return;
}


// ==== 0x686906 Unwind@00686906

void Unwind_00686906(void)

{
  FUN_00425120();
  return;
}


// ==== 0x68690e FUN_0068690e

void FUN_0068690e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686920 Unwind@00686920

void Unwind_00686920(void)

{
  FUN_00594fe0("RealController",0);
  return;
}


// ==== 0x686933 Unwind@00686933

void Unwind_00686933(void)

{
  FUN_00594fe0("DragController",0);
  return;
}


// ==== 0x686946 Unwind@00686946

void Unwind_00686946(void)

{
  FUN_00594fe0("AIDriver",0);
  return;
}


// ==== 0x686959 Unwind@00686959

void Unwind_00686959(void)

{
  FUN_00594fe0("TrafficController",0);
  return;
}


// ==== 0x68696c FUN_0068696c

void FUN_0068696c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686980 Unwind@00686980

void Unwind_00686980(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68698d Unwind@0068698d

void Unwind_0068698d(void)

{
  FUN_00424ef0();
  return;
}


// ==== 0x686995 Unwind@00686995

void Unwind_00686995(void)

{
  FUN_00594fe0("OnlineCar",0);
  return;
}


// ==== 0x6869a8 FUN_006869a8

void FUN_006869a8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6869c0 FUN_006869c0

void FUN_006869c0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6869d0 Unwind@006869d0

void Unwind_006869d0(void)

{
  FUN_00594fe0(&PTR_DAT_006cae38,0);
  return;
}


// ==== 0x6869e3 FUN_006869e3

void FUN_006869e3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6869f0 Unwind@006869f0

void Unwind_006869f0(void)

{
  FUN_00594fe0(&PTR_DAT_006cae38,0);
  return;
}


// ==== 0x686a03 FUN_00686a03

void FUN_00686a03(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686a10 Unwind@00686a10

void Unwind_00686a10(void)

{
  FUN_004688c0();
  return;
}


// ==== 0x686a18 Unwind@00686a18

void Unwind_00686a18(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x10) + 0x140;
  }
  PhysicsSystem___PhysicsSystem();
  return;
}


// ==== 0x686a41 Unwind@00686a41

void Unwind_00686a41(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x686a4e Unwind@00686a4e

void Unwind_00686a4e(void)

{
  int unaff_EBP;
  
  FUN_00591c90(*(int *)(unaff_EBP + -0x10) + 0x440);
  return;
}


// ==== 0x686a5d Unwind@00686a5d

void Unwind_00686a5d(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686a6b Unwind@00686a6b

void Unwind_00686a6b(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686a79 FUN_00686a79

void FUN_00686a79(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686a90 Unwind@00686a90

void Unwind_00686a90(void)

{
  FUN_004688c0();
  return;
}


// ==== 0x686a98 Unwind@00686a98

void Unwind_00686a98(void)

{
  PhysicsSystem___PhysicsSystem();
  return;
}


// ==== 0x686aa6 Unwind@00686aa6

void Unwind_00686aa6(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x686ab3 Unwind@00686ab3

void Unwind_00686ab3(void)

{
  int unaff_EBP;
  
  FUN_00591c90(*(int *)(unaff_EBP + 4) + 0x440);
  return;
}


// ==== 0x686ac2 Unwind@00686ac2

void Unwind_00686ac2(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686ad0 Unwind@00686ad0

void Unwind_00686ad0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686ade FUN_00686ade

void FUN_00686ade(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686af0 Unwind@00686af0

void Unwind_00686af0(void)

{
  FUN_005950c0();
  return;
}


// ==== 0x686af8 FUN_00686af8

void FUN_00686af8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686b10 Unwind@00686b10

void Unwind_00686b10(void)

{
  FUN_0058ae40();
  return;
}


// ==== 0x686b1b FUN_00686b1b

void FUN_00686b1b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686b30 Unwind@00686b30

void Unwind_00686b30(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x686b38 FUN_00686b38

void FUN_00686b38(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686b50 Unwind@00686b50

void Unwind_00686b50(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686b58 Unwind@00686b58

void Unwind_00686b58(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686b60 FUN_00686b60

void FUN_00686b60(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686b70 Unwind@00686b70

void Unwind_00686b70(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686b7b FUN_00686b7b

void FUN_00686b7b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686b90 Unwind@00686b90

void Unwind_00686b90(void)

{
  FUN_00500560();
  return;
}


// ==== 0x686b98 Unwind@00686b98

void Unwind_00686b98(void)

{
  FUN_00500560();
  return;
}


// ==== 0x686ba0 FUN_00686ba0

void FUN_00686ba0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686bb0 Unwind@00686bb0

void Unwind_00686bb0(void)

{
  FUN_00594fe0("BootFlowManager",0);
  return;
}


// ==== 0x686bc3 FUN_00686bc3

void FUN_00686bc3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686bd0 Unwind@00686bd0

void Unwind_00686bd0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686bdb FUN_00686bdb

void FUN_00686bdb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686bf0 Unwind@00686bf0

void Unwind_00686bf0(void)

{
  FUN_00595090();
  return;
}


// ==== 0x686bf8 FUN_00686bf8

void FUN_00686bf8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686c10 Unwind@00686c10

void Unwind_00686c10(void)

{
  FUN_005779c0();
  return;
}


// ==== 0x686c18 FUN_00686c18

void FUN_00686c18(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686c30 Unwind@00686c30

void Unwind_00686c30(void)

{
  FUN_005779c0();
  return;
}


// ==== 0x686c38 Unwind@00686c38

void Unwind_00686c38(void)

{
  int unaff_EBP;
  
  FUN_00579600(*(int *)(unaff_EBP + 4) + 0x1c);
  return;
}


// ==== 0x686c45 Unwind@00686c45

void Unwind_00686c45(void)

{
  FUN_00576eb0();
  return;
}


// ==== 0x686c4d FUN_00686c4d

void FUN_00686c4d(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686c60 Unwind@00686c60

void Unwind_00686c60(void)

{
  FUN_00594fe0("WorldObject",0);
  return;
}


// ==== 0x686c73 FUN_00686c73

void FUN_00686c73(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686c80 Unwind@00686c80

void Unwind_00686c80(void)

{
  FUN_00500560();
  return;
}


// ==== 0x686c88 FUN_00686c88

void FUN_00686c88(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686ca0 Unwind@00686ca0

void Unwind_00686ca0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686cab Unwind@00686cab

void Unwind_00686cab(void)

{
  PostRaceRewardList___PostRaceRewardList();
  return;
}


// ==== 0x686cb6 FUN_00686cb6

void FUN_00686cb6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686cc0 Unwind@00686cc0

void Unwind_00686cc0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686ccb Unwind@00686ccb

void Unwind_00686ccb(void)

{
  PostRaceRewardList___PostRaceRewardList();
  return;
}


// ==== 0x686cd6 FUN_00686cd6

void FUN_00686cd6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686ce0 Unwind@00686ce0

void Unwind_00686ce0(void)

{
  FUN_00483550();
  return;
}


// ==== 0x686ce8 FUN_00686ce8

void FUN_00686ce8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686d00 Unwind@00686d00

void Unwind_00686d00(void)

{
  FUN_00594fe0("CubicCameraMover(DCC)",0);
  return;
}


// ==== 0x686d16 FUN_00686d16

void FUN_00686d16(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686d20 Unwind@00686d20

void Unwind_00686d20(void)

{
  FUN_00594fe0("DebugWorldCameraMover",0);
  return;
}


// ==== 0x686d36 Unwind@00686d36

void Unwind_00686d36(void)

{
  FUN_00594fe0("ZoneFreezeCameraMover",0);
  return;
}


// ==== 0x686d4c Unwind@00686d4c

void Unwind_00686d4c(void)

{
  FUN_00594fe0("ZonePreviewCameraMover",0);
  return;
}


// ==== 0x686d62 Unwind@00686d62

void Unwind_00686d62(void)

{
  FUN_00594fe0("CubicCameraMover",0);
  return;
}


// ==== 0x686d78 Unwind@00686d78

void Unwind_00686d78(void)

{
  FUN_00594fe0("OrbitCarCameraMover",0);
  return;
}


// ==== 0x686d8e FUN_00686d8e

void FUN_00686d8e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686da0 Unwind@00686da0

void Unwind_00686da0(void)

{
  FUN_00594fe0("CountdownCameraCoordinator",0);
  return;
}


// ==== 0x686db3 FUN_00686db3

void FUN_00686db3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686dc0 Unwind@00686dc0

void Unwind_00686dc0(void)

{
  FUN_00421980();
  return;
}


// ==== 0x686dc8 Unwind@00686dc8

void Unwind_00686dc8(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686dd3 Unwind@00686dd3

void Unwind_00686dd3(void)

{
  int unaff_EBP;
  
  FUN_004219b0(*(int *)(unaff_EBP + 4) + 0x10);
  return;
}


// ==== 0x686de0 Unwind@00686de0

void Unwind_00686de0(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x300),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x686df8 Unwind@00686df8

void Unwind_00686df8(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x940),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x686e10 Unwind@00686e10

void Unwind_00686e10(void)

{
  FUN_00594fe0("TrafficTeleporter",0);
  return;
}


// ==== 0x686e23 FUN_00686e23

void FUN_00686e23(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686e30 Unwind@00686e30

void Unwind_00686e30(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x686e3e FUN_00686e3e

void FUN_00686e3e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686e50 Unwind@00686e50

void Unwind_00686e50(void)

{
  FUN_00578370();
  return;
}


// ==== 0x686e5b FUN_00686e5b

void FUN_00686e5b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686e69 FUN_00686e69

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_00686e69(undefined4 param_1,undefined2 param_2)

{
  undefined1 uVar1;
  undefined1 *unaff_EDI;
  
  uVar1 = in(param_2);
  *unaff_EDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x686e70 Unwind@00686e70

void Unwind_00686e70(void)

{
  FUN_00578370();
  return;
}


// ==== 0x686e78 Unwind@00686e78

void Unwind_00686e78(void)

{
  FUN_00455510();
  return;
}


// ==== 0x686e80 FUN_00686e80

void FUN_00686e80(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686e90 Unwind@00686e90

void Unwind_00686e90(void)

{
  FUN_00594fe0("Trolley",0);
  return;
}


// ==== 0x686ea3 FUN_00686ea3

void FUN_00686ea3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686eb0 Unwind@00686eb0

void Unwind_00686eb0(void)

{
  FUN_00594fe0("NISFlagGirl",0);
  return;
}


// ==== 0x686ec3 FUN_00686ec3

void FUN_00686ec3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686ed0 Unwind@00686ed0

void Unwind_00686ed0(void)

{
  FUN_00594fe0("NISCrowd",0);
  return;
}


// ==== 0x686ee3 FUN_00686ee3

void FUN_00686ee3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686ef0 Unwind@00686ef0

void Unwind_00686ef0(void)

{
  FUN_00594fe0("NISProp",0);
  return;
}


// ==== 0x686f03 FUN_00686f03

void FUN_00686f03(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686f10 Unwind@00686f10

void Unwind_00686f10(void)

{
  FUN_00578370();
  return;
}


// ==== 0x686f18 FUN_00686f18

void FUN_00686f18(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686f30 Unwind@00686f30

void Unwind_00686f30(void)

{
  FUN_00594fe0("CarWorldObject",0);
  return;
}


// ==== 0x686f43 FUN_00686f43

void FUN_00686f43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686f50 Unwind@00686f50

void Unwind_00686f50(void)

{
  FUN_00594fe0("OnlineGameRoomCreateGame",0);
  return;
}


// ==== 0x686f63 FUN_00686f63

void FUN_00686f63(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686f70 Unwind@00686f70

void Unwind_00686f70(void)

{
  FUN_00594fe0("OnlinePingBar",0);
  return;
}


// ==== 0x686f83 FUN_00686f83

void FUN_00686f83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686f90 Unwind@00686f90

void Unwind_00686f90(void)

{
  FUN_004cd350();
  return;
}


// ==== 0x686f98 FUN_00686f98

void FUN_00686f98(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686fb0 Unwind@00686fb0

void Unwind_00686fb0(void)

{
  FUN_004cd350();
  return;
}


// ==== 0x686fb8 FUN_00686fb8

void FUN_00686fb8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686fd0 Unwind@00686fd0

void Unwind_00686fd0(void)

{
  FUN_00594fe0("StatsScreen",0);
  return;
}


// ==== 0x686fe3 FUN_00686fe3

void FUN_00686fe3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x686ff0 Unwind@00686ff0

void Unwind_00686ff0(void)

{
  FUN_00594fe0("MenuBar",0);
  return;
}


// ==== 0x687003 FUN_00687003

void FUN_00687003(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687010 Unwind@00687010

void Unwind_00687010(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687018 Unwind@00687018

void Unwind_00687018(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687020 Unwind@00687020

void Unwind_00687020(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687028 Unwind@00687028

void Unwind_00687028(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687030 Unwind@00687030

void Unwind_00687030(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687038 Unwind@00687038

void Unwind_00687038(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687040 Unwind@00687040

void Unwind_00687040(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687048 FUN_00687048

void FUN_00687048(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687060 Unwind@00687060

void Unwind_00687060(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687068 Unwind@00687068

void Unwind_00687068(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x687073 FUN_00687073

void FUN_00687073(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687080 Unwind@00687080

void Unwind_00687080(void)

{
  FUN_00594fe0("IntroFMVScreen",0);
  return;
}


// ==== 0x687093 FUN_00687093

void FUN_00687093(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6870a0 Unwind@006870a0

void Unwind_006870a0(void)

{
  FUN_00594fe0("DemoDisclaimerScreen",0);
  return;
}


// ==== 0x6870b3 FUN_006870b3

void FUN_006870b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6870c0 Unwind@006870c0

void Unwind_006870c0(void)

{
  FUN_00594fe0("DemoDiscLegalScreen",0);
  return;
}


// ==== 0x6870d3 FUN_006870d3

void FUN_006870d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6870e0 Unwind@006870e0

void Unwind_006870e0(void)

{
  FUN_00594fe0("DisclaimerScreen",0);
  return;
}


// ==== 0x6870f3 FUN_006870f3

void FUN_006870f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687100 Unwind@00687100

void Unwind_00687100(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687108 Unwind@00687108

void Unwind_00687108(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x5c),0x2c,10,FUN_004d7770);
  return;
}


// ==== 0x68711e Unwind@0068711e

void Unwind_0068711e(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x214),0x2c,0x14,FUN_004d7770);
  return;
}


// ==== 0x687136 Unwind@00687136

void Unwind_00687136(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x584),0x2c,0x1e,FUN_004d7770);
  return;
}


// ==== 0x68714e Unwind@0068714e

void Unwind_0068714e(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x68715c FUN_0068715c

void FUN_0068715c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687170 Unwind@00687170

void Unwind_00687170(void)

{
  FUN_00594fe0("ScreenPosMenu",0);
  return;
}


// ==== 0x687183 FUN_00687183

void FUN_00687183(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687190 Unwind@00687190

void Unwind_00687190(void)

{
  FUN_00594fe0("CreditsScreen",0);
  return;
}


// ==== 0x6871a3 FUN_006871a3

void FUN_006871a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6871b0 Unwind@006871b0

void Unwind_006871b0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6871b8 FUN_006871b8

void FUN_006871b8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6871d0 Unwind@006871d0

void Unwind_006871d0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6871d8 Unwind@006871d8

void Unwind_006871d8(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x6871e3 Unwind@006871e3

void Unwind_006871e3(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x6871f1 Unwind@006871f1

void Unwind_006871f1(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x6871ff Unwind@006871ff

void Unwind_006871ff(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x68720d Unwind@0068720d

void Unwind_0068720d(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x68721b Unwind@0068721b

void Unwind_0068721b(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687229 Unwind@00687229

void Unwind_00687229(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687237 Unwind@00687237

void Unwind_00687237(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687245 Unwind@00687245

void Unwind_00687245(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687253 Unwind@00687253

void Unwind_00687253(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687261 Unwind@00687261

void Unwind_00687261(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x68726f Unwind@0068726f

void Unwind_0068726f(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x68727d Unwind@0068727d

void Unwind_0068727d(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x68728b Unwind@0068728b

void Unwind_0068728b(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687299 FUN_00687299

void FUN_00687299(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6872b0 Unwind@006872b0

void Unwind_006872b0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6872b8 Unwind@006872b8

void Unwind_006872b8(void)

{
  FUN_00417560();
  return;
}


// ==== 0x6872c6 FUN_006872c6

void FUN_006872c6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6872d0 Unwind@006872d0

void Unwind_006872d0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6872d8 Unwind@006872d8

void Unwind_006872d8(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x6872e3 Unwind@006872e3

void Unwind_006872e3(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x6872ee FUN_006872ee

void FUN_006872ee(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687300 Unwind@00687300

void Unwind_00687300(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687308 Unwind@00687308

void Unwind_00687308(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x687313 Unwind@00687313

void Unwind_00687313(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x68731e FUN_0068731e

void FUN_0068731e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687330 Unwind@00687330

void Unwind_00687330(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687338 Unwind@00687338

void Unwind_00687338(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687343 FUN_00687343

void FUN_00687343(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687350 Unwind@00687350

void Unwind_00687350(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687358 Unwind@00687358

void Unwind_00687358(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x687363 Unwind@00687363

void Unwind_00687363(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x68736e Unwind@0068736e

void Unwind_0068736e(void)

{
  TournamentTrackList___TournamentTrackList();
  return;
}


// ==== 0x68737c FUN_0068737c

void FUN_0068737c(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687390 Unwind@00687390

void Unwind_00687390(void)

{
  FUN_00594fe0("BackgroundScreen",0);
  return;
}


// ==== 0x6873a3 FUN_006873a3

void FUN_006873a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6873b0 Unwind@006873b0

void Unwind_006873b0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6873b8 Unwind@006873b8

void Unwind_006873b8(void)

{
  ListRef_Release();
  return;
}


// ==== 0x6873c3 Unwind@006873c3

void Unwind_006873c3(void)

{
  FUN_004ae990();
  return;
}


// ==== 0x6873d0 FUN_006873d0

void FUN_006873d0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6873e0 Unwind@006873e0

void Unwind_006873e0(void)

{
  FUN_00594fe0("cPostRaceScreenManager",0);
  return;
}


// ==== 0x6873f3 FUN_006873f3

void FUN_006873f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687400 Unwind@00687400

void Unwind_00687400(void)

{
  FUN_00594fe0("OptionsScreen",0);
  return;
}


// ==== 0x687413 FUN_00687413

void FUN_00687413(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687420 Unwind@00687420

void Unwind_00687420(void)

{
  FUN_0047dc10();
  return;
}


// ==== 0x687428 FUN_00687428

void FUN_00687428(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687440 Unwind@00687440

void Unwind_00687440(void)

{
  FUN_00594fe0("BeltMover",0);
  return;
}


// ==== 0x687456 FUN_00687456

void FUN_00687456(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687460 Unwind@00687460

void Unwind_00687460(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687468 Unwind@00687468

void Unwind_00687468(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x687473 Unwind@00687473

void Unwind_00687473(void)

{
  FUN_00417560();
  return;
}


// ==== 0x687481 FUN_00687481

void FUN_00687481(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687490 Unwind@00687490

void Unwind_00687490(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687498 Unwind@00687498

void Unwind_00687498(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6874a3 Unwind@006874a3

void Unwind_006874a3(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6874ae Unwind@006874ae

void Unwind_006874ae(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6874bc Unwind@006874bc

void Unwind_006874bc(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6874ca FUN_006874ca

void FUN_006874ca(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6874e0 Unwind@006874e0

void Unwind_006874e0(void)

{
  FUN_00594fe0("CustomizeGraphicsConfig",0);
  return;
}


// ==== 0x6874f3 FUN_006874f3

undefined4 FUN_006874f3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4,&FuncInfo_006cf980,0,0,0);
  return uVar1;
}


// ==== 0x687500 Unwind@00687500

void Unwind_00687500(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687508 Unwind@00687508

void Unwind_00687508(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687510 FUN_00687510

void FUN_00687510(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687520 Unwind@00687520

void Unwind_00687520(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687528 FUN_00687528

void FUN_00687528(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687540 Unwind@00687540

void Unwind_00687540(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687548 Unwind@00687548

void Unwind_00687548(void)

{
  FUN_00417560();
  return;
}


// ==== 0x687553 Unwind@00687553

void Unwind_00687553(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68755b Unwind@0068755b

void Unwind_0068755b(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687563 Unwind@00687563

void Unwind_00687563(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68756b Unwind@0068756b

void Unwind_0068756b(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687573 Unwind@00687573

void Unwind_00687573(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68757b Unwind@0068757b

void Unwind_0068757b(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687583 Unwind@00687583

void Unwind_00687583(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68758b Unwind@0068758b

void Unwind_0068758b(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687593 Unwind@00687593

void Unwind_00687593(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68759b Unwind@0068759b

void Unwind_0068759b(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875a3 Unwind@006875a3

void Unwind_006875a3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875ab Unwind@006875ab

void Unwind_006875ab(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875b3 Unwind@006875b3

void Unwind_006875b3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875bb Unwind@006875bb

void Unwind_006875bb(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875c3 Unwind@006875c3

void Unwind_006875c3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875cb Unwind@006875cb

void Unwind_006875cb(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875d3 Unwind@006875d3

void Unwind_006875d3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6875db FUN_006875db

void FUN_006875db(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6875f0 Unwind@006875f0

void Unwind_006875f0(void)

{
  FUN_00594fe0("OnlineNews",0);
  return;
}


// ==== 0x687603 FUN_00687603

void FUN_00687603(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687610 Unwind@00687610

void Unwind_00687610(void)

{
  FUN_00594fe0("OnlineRankingsSelect",0);
  return;
}


// ==== 0x687623 FUN_00687623

void FUN_00687623(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687630 Unwind@00687630

void Unwind_00687630(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687638 Unwind@00687638

void Unwind_00687638(void)

{
  FUN_00417560();
  return;
}


// ==== 0x687643 FUN_00687643

void FUN_00687643(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687650 Unwind@00687650

void Unwind_00687650(void)

{
  FUN_00594fe0("OnlineRankingsBoard",0);
  return;
}


// ==== 0x687663 FUN_00687663

void FUN_00687663(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687670 Unwind@00687670

void Unwind_00687670(void)

{
  FUN_00594fe0("OnlineTooYoung",0);
  return;
}


// ==== 0x687683 FUN_00687683

void FUN_00687683(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687690 Unwind@00687690

void Unwind_00687690(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687698 Unwind@00687698

void Unwind_00687698(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6876a3 FUN_006876a3

void FUN_006876a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6876b0 Unwind@006876b0

void Unwind_006876b0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6876b8 Unwind@006876b8

void Unwind_006876b8(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6876c3 Unwind@006876c3

void Unwind_006876c3(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6876d1 Unwind@006876d1

void Unwind_006876d1(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6876d9 Unwind@006876d9

void Unwind_006876d9(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6876e1 FUN_006876e1

void FUN_006876e1(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6876f0 Unwind@006876f0

void Unwind_006876f0(void)

{
  FUN_00594fe0("OnlineAnotherAccount",0);
  return;
}


// ==== 0x687703 FUN_00687703

void FUN_00687703(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687710 Unwind@00687710

void Unwind_00687710(void)

{
  FUN_0055b5b0();
  return;
}


// ==== 0x687718 Unwind@00687718

void Unwind_00687718(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x687723 Unwind@00687723

void Unwind_00687723(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x687731 Unwind@00687731

void Unwind_00687731(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x68773f FUN_0068773f

void FUN_0068773f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687750 Unwind@00687750

void Unwind_00687750(void)

{
  FUN_0055b5b0();
  return;
}


// ==== 0x687758 Unwind@00687758

void Unwind_00687758(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x687763 Unwind@00687763

void Unwind_00687763(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x687771 Unwind@00687771

void Unwind_00687771(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x68777f Unwind@0068777f

void Unwind_0068777f(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x68778d Unwind@0068778d

void Unwind_0068778d(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687795 Unwind@00687795

void Unwind_00687795(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68779d Unwind@0068779d

void Unwind_0068779d(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6877a5 Unwind@006877a5

void Unwind_006877a5(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6877ad FUN_006877ad

void FUN_006877ad(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6877c0 Unwind@006877c0

void Unwind_006877c0(void)

{
  FUN_00594fe0("OnlineCreateAccountStepOne",0);
  return;
}


// ==== 0x6877d3 FUN_006877d3

void FUN_006877d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6877e0 Unwind@006877e0

void Unwind_006877e0(void)

{
  FUN_00594fe0("OnlineIspConnect",0);
  return;
}


// ==== 0x6877f3 FUN_006877f3

void FUN_006877f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687800 Unwind@00687800

void Unwind_00687800(void)

{
  FUN_00594fe0("OnlineNetworkSelect",0);
  return;
}


// ==== 0x687813 FUN_00687813

void FUN_00687813(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687820 Unwind@00687820

void Unwind_00687820(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687828 Unwind@00687828

void Unwind_00687828(void)

{
  FUN_005567f0();
  return;
}


// ==== 0x687833 FUN_00687833

void FUN_00687833(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687840 Unwind@00687840

void Unwind_00687840(void)

{
  FUN_00594fe0("OnlineGameRoomPLH",0);
  return;
}


// ==== 0x687853 Unwind@00687853

void Unwind_00687853(void)

{
  FUN_00594fe0("OnlineGameRoomPLI",0);
  return;
}


// ==== 0x687866 Unwind@00687866

void Unwind_00687866(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68786e Unwind@0068786e

void Unwind_0068786e(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687876 FUN_00687876

void FUN_00687876(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687880 Unwind@00687880

void Unwind_00687880(void)

{
  FUN_00594fe0("MU_ONLINE_WAITING.fng",0);
  return;
}


// ==== 0x687893 FUN_00687893

void FUN_00687893(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6878a0 Unwind@006878a0

void Unwind_006878a0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6878a8 Unwind@006878a8

void Unwind_006878a8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6878b0 Unwind@006878b0

void Unwind_006878b0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6878b8 Unwind@006878b8

void Unwind_006878b8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6878c0 Unwind@006878c0

void Unwind_006878c0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6878c8 Unwind@006878c8

void Unwind_006878c8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6878d0 FUN_006878d0

void FUN_006878d0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6878e0 Unwind@006878e0

void Unwind_006878e0(void)

{
  FUN_00594fe0("OnlineGameModeSelect",0);
  return;
}


// ==== 0x6878f3 FUN_006878f3

void FUN_006878f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687900 Unwind@00687900

void Unwind_00687900(void)

{
  FUN_00594fe0("MagazineScreenBack",0);
  return;
}


// ==== 0x687913 FUN_00687913

void FUN_00687913(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687920 Unwind@00687920

void Unwind_00687920(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687928 Unwind@00687928

void Unwind_00687928(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687930 Unwind@00687930

void Unwind_00687930(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687938 FUN_00687938

void FUN_00687938(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687950 Unwind@00687950

void Unwind_00687950(void)

{
  FUN_00594fe0("HorizontalBrowserBackScreen",0);
  return;
}


// ==== 0x687963 FUN_00687963

void FUN_00687963(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687970 Unwind@00687970

void Unwind_00687970(void)

{
  FUN_00594fe0("OnlineOKDialog",0);
  return;
}


// ==== 0x687983 FUN_00687983

void FUN_00687983(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687990 Unwind@00687990

void Unwind_00687990(void)

{
  FUN_00594fe0("FEKeyboard",0);
  return;
}


// ==== 0x6879a3 FUN_006879a3

void FUN_006879a3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6879b0 Unwind@006879b0

void Unwind_006879b0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6879b8 Unwind@006879b8

void Unwind_006879b8(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6879c3 FUN_006879c3

void FUN_006879c3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6879d0 Unwind@006879d0

void Unwind_006879d0(void)

{
  FUN_00594fe0("OnlineDialogBox",0);
  return;
}


// ==== 0x6879e3 FUN_006879e3

void FUN_006879e3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6879f0 Unwind@006879f0

void Unwind_006879f0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6879f8 FUN_006879f8

void FUN_006879f8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687a10 Unwind@00687a10

void Unwind_00687a10(void)

{
  FUN_00594fe0("UndergroundNewCareerExtroFMV",0);
  return;
}


// ==== 0x687a23 FUN_00687a23

void FUN_00687a23(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687a30 Unwind@00687a30

void Unwind_00687a30(void)

{
  FUN_00594fe0("UndergroundNewCareerFMV",0);
  return;
}


// ==== 0x687a43 FUN_00687a43

void FUN_00687a43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687a50 Unwind@00687a50

void Unwind_00687a50(void)

{
  FUN_00594fe0("GarageNewVinylScreen",0);
  return;
}


// ==== 0x687a63 FUN_00687a63

void FUN_00687a63(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687a70 Unwind@00687a70

void Unwind_00687a70(void)

{
  FUN_00594fe0("MPChooseGarageScreen",0);
  return;
}


// ==== 0x687a83 FUN_00687a83

void FUN_00687a83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687a90 Unwind@00687a90

void Unwind_00687a90(void)

{
  FUN_00594fe0("PCESRBScreen",0);
  return;
}


// ==== 0x687aa3 FUN_00687aa3

void FUN_00687aa3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ab0 Unwind@00687ab0

void Unwind_00687ab0(void)

{
  FUN_00594fe0("PCDemoDiscMarketingScreen",0);
  return;
}


// ==== 0x687ac3 FUN_00687ac3

void FUN_00687ac3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ad0 Unwind@00687ad0

void Unwind_00687ad0(void)

{
  FUN_00594fe0("CheckForPCDisk",0);
  return;
}


// ==== 0x687ae3 FUN_00687ae3

void FUN_00687ae3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687af0 Unwind@00687af0

void Unwind_00687af0(void)

{
  FUN_00594fe0("LangSelectScreen",0);
  return;
}


// ==== 0x687b03 FUN_00687b03

void FUN_00687b03(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687b10 Unwind@00687b10

void Unwind_00687b10(void)

{
  FUN_00594fe0("THXMovieScreen",0);
  return;
}


// ==== 0x687b23 FUN_00687b23

void FUN_00687b23(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687b30 Unwind@00687b30

void Unwind_00687b30(void)

{
  FUN_00594fe0("PSAMovie",0);
  return;
}


// ==== 0x687b43 FUN_00687b43

void FUN_00687b43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687b50 Unwind@00687b50

void Unwind_00687b50(void)

{
  FUN_00594fe0("EAlogoBumper",0);
  return;
}


// ==== 0x687b63 FUN_00687b63

void FUN_00687b63(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687b70 Unwind@00687b70

void Unwind_00687b70(void)

{
  FUN_00594fe0("InfoDialog",0);
  return;
}


// ==== 0x687b83 FUN_00687b83

void FUN_00687b83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687b90 Unwind@00687b90

void Unwind_00687b90(void)

{
  FUN_00594fe0("OKDialog",0);
  return;
}


// ==== 0x687ba3 FUN_00687ba3

void FUN_00687ba3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687bb0 Unwind@00687bb0

void Unwind_00687bb0(void)

{
  FUN_00594fe0("ConfirmDialog",0);
  return;
}


// ==== 0x687bc3 FUN_00687bc3

void FUN_00687bc3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687bd0 Unwind@00687bd0

void Unwind_00687bd0(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687bd8 Unwind@00687bd8

void Unwind_00687bd8(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687be0 Unwind@00687be0

void Unwind_00687be0(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687be8 FUN_00687be8

void FUN_00687be8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687c00 Unwind@00687c00

void Unwind_00687c00(void)

{
  int unaff_EBP;
  
  NullUpdate_ret(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}


// ==== 0x687c0b FUN_00687c0b

void FUN_00687c0b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687c20 Unwind@00687c20

void Unwind_00687c20(void)

{
  FUN_00594fe0("TrailerScreen",0);
  return;
}


// ==== 0x687c33 FUN_00687c33

void FUN_00687c33(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687c40 Unwind@00687c40

void Unwind_00687c40(void)

{
  FUN_00594fe0("OptionsSelectorMenu",0);
  return;
}


// ==== 0x687c53 FUN_00687c53

void FUN_00687c53(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687c60 Unwind@00687c60

void Unwind_00687c60(void)

{
  FUN_00594fe0("CreateUndergroundTheatreViewer",0);
  return;
}


// ==== 0x687c73 FUN_00687c73

void FUN_00687c73(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687c80 Unwind@00687c80

void Unwind_00687c80(void)

{
  FUN_00594fe0("PauseOptionsSelectorMenu",0);
  return;
}


// ==== 0x687c93 FUN_00687c93

void FUN_00687c93(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ca0 Unwind@00687ca0

void Unwind_00687ca0(void)

{
  FUN_00594fe0("QRLapPopupScreen",0);
  return;
}


// ==== 0x687cb3 FUN_00687cb3

void FUN_00687cb3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687cc0 Unwind@00687cc0

void Unwind_00687cc0(void)

{
  FUN_00594fe0("TrackMapScroller",0);
  return;
}


// ==== 0x687cd3 FUN_00687cd3

void FUN_00687cd3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ce0 Unwind@00687ce0

void Unwind_00687ce0(void)

{
  FUN_00594fe0("UndergroundExplained",0);
  return;
}


// ==== 0x687cf3 FUN_00687cf3

void FUN_00687cf3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687d00 Unwind@00687d00

void Unwind_00687d00(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687d08 Unwind@00687d08

void Unwind_00687d08(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687d13 FUN_00687d13

void FUN_00687d13(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687d20 Unwind@00687d20

void Unwind_00687d20(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687d28 Unwind@00687d28

void Unwind_00687d28(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d30 Unwind@00687d30

void Unwind_00687d30(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d38 FUN_00687d38

void FUN_00687d38(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687d50 Unwind@00687d50

void Unwind_00687d50(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687d58 Unwind@00687d58

void Unwind_00687d58(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d60 Unwind@00687d60

void Unwind_00687d60(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d68 Unwind@00687d68

void Unwind_00687d68(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d70 FUN_00687d70

void FUN_00687d70(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687d80 Unwind@00687d80

void Unwind_00687d80(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687d88 Unwind@00687d88

void Unwind_00687d88(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d90 Unwind@00687d90

void Unwind_00687d90(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687d98 Unwind@00687d98

void Unwind_00687d98(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687da0 Unwind@00687da0

void Unwind_00687da0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687da8 FUN_00687da8

void FUN_00687da8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687dc0 Unwind@00687dc0

void Unwind_00687dc0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687dc8 Unwind@00687dc8

void Unwind_00687dc8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687dd0 Unwind@00687dd0

void Unwind_00687dd0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687dd8 Unwind@00687dd8

void Unwind_00687dd8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687de0 Unwind@00687de0

void Unwind_00687de0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687de8 Unwind@00687de8

void Unwind_00687de8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687df0 Unwind@00687df0

void Unwind_00687df0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687df8 FUN_00687df8

void FUN_00687df8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687e10 Unwind@00687e10

void Unwind_00687e10(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687e18 Unwind@00687e18

void Unwind_00687e18(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e20 FUN_00687e20

void FUN_00687e20(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687e30 Unwind@00687e30

void Unwind_00687e30(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687e38 Unwind@00687e38

void Unwind_00687e38(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e40 Unwind@00687e40

void Unwind_00687e40(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e48 Unwind@00687e48

void Unwind_00687e48(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e50 Unwind@00687e50

void Unwind_00687e50(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e58 Unwind@00687e58

void Unwind_00687e58(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687e60 FUN_00687e60

void FUN_00687e60(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687e70 Unwind@00687e70

void Unwind_00687e70(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687e78 FUN_00687e78

void FUN_00687e78(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687e90 Unwind@00687e90

void Unwind_00687e90(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x687e98 FUN_00687e98

void FUN_00687e98(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687eb0 Unwind@00687eb0

void Unwind_00687eb0(void)

{
  FUN_00594fe0("RewardPopupScreen",0);
  return;
}


// ==== 0x687ec3 FUN_00687ec3

void FUN_00687ec3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ed0 Unwind@00687ed0

void Unwind_00687ed0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687ed8 Unwind@00687ed8

void Unwind_00687ed8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687ee0 Unwind@00687ee0

void Unwind_00687ee0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687ee8 Unwind@00687ee8

void Unwind_00687ee8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687ef0 Unwind@00687ef0

void Unwind_00687ef0(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687ef8 Unwind@00687ef8

void Unwind_00687ef8(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687f00 Unwind@00687f00

void Unwind_00687f00(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687f08 Unwind@00687f08

void Unwind_00687f08(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687f10 Unwind@00687f10

void Unwind_00687f10(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687f18 Unwind@00687f18

void Unwind_00687f18(void)

{
  FUN_00500560();
  return;
}


// ==== 0x687f20 FUN_00687f20

void FUN_00687f20(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687f30 Unwind@00687f30

void Unwind_00687f30(void)

{
  FUN_00594fe0("PreRaceStatsScreen",0);
  return;
}


// ==== 0x687f43 FUN_00687f43

void FUN_00687f43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687f50 Unwind@00687f50

void Unwind_00687f50(void)

{
  FUN_00421980();
  return;
}


// ==== 0x687f58 Unwind@00687f58

void Unwind_00687f58(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x687f63 Unwind@00687f63

void Unwind_00687f63(void)

{
  int unaff_EBP;
  
  FUN_004219b0(*(int *)(unaff_EBP + 4) + 0x10);
  return;
}


// ==== 0x687f70 Unwind@00687f70

void Unwind_00687f70(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x300),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x687f88 Unwind@00687f88

void Unwind_00687f88(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x940),0x50,0x14,NullUpdate_ret);
  return;
}


// ==== 0x687fa0 FUN_00687fa0

void FUN_00687fa0(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687fb0 Unwind@00687fb0

void Unwind_00687fb0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x687fb8 Unwind@00687fb8

void Unwind_00687fb8(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x687fc3 FUN_00687fc3

void FUN_00687fc3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687fd0 Unwind@00687fd0

void Unwind_00687fd0(void)

{
  FUN_00594fe0("GraphicsConfig",0);
  return;
}


// ==== 0x687fe3 FUN_00687fe3

void FUN_00687fe3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x687ff0 Unwind@00687ff0

void Unwind_00687ff0(void)

{
  FUN_00594fe0("ControllerConfigMenu",0);
  return;
}


// ==== 0x688003 FUN_00688003

void FUN_00688003(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688010 Unwind@00688010

void Unwind_00688010(void)

{
  FUN_00589240();
  return;
}


// ==== 0x688018 FUN_00688018

void FUN_00688018(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688030 Unwind@00688030

void Unwind_00688030(void)

{
  FUN_00594fe0("UnlockStatusScreen",0);
  return;
}


// ==== 0x688043 FUN_00688043

void FUN_00688043(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688050 Unwind@00688050

void Unwind_00688050(void)

{
  FUN_00594fe0("OnlinePlayerDetailsBox",0);
  return;
}


// ==== 0x688063 FUN_00688063

void FUN_00688063(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688070 Unwind@00688070

void Unwind_00688070(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688078 Unwind@00688078

void Unwind_00688078(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 4) + 0x78),0x208,4,FUN_0041f140);
  return;
}


// ==== 0x688091 Unwind@00688091

void Unwind_00688091(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688099 Unwind@00688099

void Unwind_00688099(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6880a1 FUN_006880a1

void FUN_006880a1(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6880b0 Unwind@006880b0

void Unwind_006880b0(void)

{
  FUN_00594fe0("OnlineSelectPersona",0);
  return;
}


// ==== 0x6880c3 FUN_006880c3

void FUN_006880c3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6880d0 Unwind@006880d0

void Unwind_006880d0(void)

{
  FUN_0055b5b0();
  return;
}


// ==== 0x6880d8 Unwind@006880d8

void Unwind_006880d8(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6880e3 Unwind@006880e3

void Unwind_006880e3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6880eb FUN_006880eb

void FUN_006880eb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688100 Unwind@00688100

void Unwind_00688100(void)

{
  FUN_00594fe0("OnlineParentalEmailRequired",0);
  return;
}


// ==== 0x688113 FUN_00688113

void FUN_00688113(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688120 Unwind@00688120

void Unwind_00688120(void)

{
  FUN_0055b5b0();
  return;
}


// ==== 0x688128 FUN_00688128

void FUN_00688128(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688140 Unwind@00688140

void Unwind_00688140(void)

{
  FUN_00594fe0("OnlineCreateAccountStepTwo",0);
  return;
}


// ==== 0x688153 FUN_00688153

void FUN_00688153(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688160 Unwind@00688160

void Unwind_00688160(void)

{
  FUN_00594fe0("OnlineNetworkLogin",0);
  return;
}


// ==== 0x688173 FUN_00688173

void FUN_00688173(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688180 Unwind@00688180

void Unwind_00688180(void)

{
  FUN_00594fe0("OnlineGamesRoomDialog",0);
  return;
}


// ==== 0x688193 FUN_00688193

void FUN_00688193(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6881a0 Unwind@006881a0

void Unwind_006881a0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6881a8 Unwind@006881a8

void Unwind_006881a8(void)

{
  FUN_005567f0();
  return;
}


// ==== 0x6881b3 FUN_006881b3

void FUN_006881b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6881c0 Unwind@006881c0

void Unwind_006881c0(void)

{
  FUN_00594fe0("OnlineGameRoomChallenge",0);
  return;
}


// ==== 0x6881d3 FUN_006881d3

void FUN_006881d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6881e0 Unwind@006881e0

void Unwind_006881e0(void)

{
  FUN_00594fe0("DiscErrorScreen",0);
  return;
}


// ==== 0x6881f3 FUN_006881f3

void FUN_006881f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688200 Unwind@00688200

void Unwind_00688200(void)

{
  FUN_00594fe0("UndergroundRankScreen",0);
  return;
}


// ==== 0x688213 FUN_00688213

void FUN_00688213(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688220 Unwind@00688220

void Unwind_00688220(void)

{
  FUN_00594fe0("UndergroundMagazineScreen",0);
  return;
}


// ==== 0x688233 FUN_00688233

void FUN_00688233(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688240 Unwind@00688240

void Unwind_00688240(void)

{
  FUN_00594fe0("SplashScreen",0);
  return;
}


// ==== 0x688253 FUN_00688253

void FUN_00688253(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688260 Unwind@00688260

void Unwind_00688260(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688268 Unwind@00688268

void Unwind_00688268(void)

{
  FUN_00417560();
  return;
}


// ==== 0x688276 FUN_00688276

void FUN_00688276(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688280 Unwind@00688280

void Unwind_00688280(void)

{
  FUN_00594fe0("EATraxScreen",0);
  return;
}


// ==== 0x688293 FUN_00688293

void FUN_00688293(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6882a0 Unwind@006882a0

void Unwind_006882a0(void)

{
  FUN_00594fe0("UndergroundBriefScreen",0);
  return;
}


// ==== 0x6882b3 FUN_006882b3

void FUN_006882b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6882c0 Unwind@006882c0

void Unwind_006882c0(void)

{
  FUN_00594fe0("UndergroundTradeConfirmScreen",0);
  return;
}


// ==== 0x6882d3 FUN_006882d3

void FUN_006882d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6882e0 Unwind@006882e0

void Unwind_006882e0(void)

{
  FUN_004b9270();
  return;
}


// ==== 0x6882e8 FUN_006882e8

void FUN_006882e8(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688300 Unwind@00688300

void Unwind_00688300(void)

{
  FUN_00594fe0("DragRaceTachometer",0);
  return;
}


// ==== 0x688313 Unwind@00688313

void Unwind_00688313(void)

{
  FUN_00594fe0("LeaderBoard",0);
  return;
}


// ==== 0x688326 Unwind@00688326

void Unwind_00688326(void)

{
  FUN_00594fe0("Tachometer",0);
  return;
}


// ==== 0x688339 Unwind@00688339

void Unwind_00688339(void)

{
  FUN_00594fe0("LeaderBoard",0);
  return;
}


// ==== 0x68834c Unwind@0068834c

void Unwind_0068834c(void)

{
  FUN_00594fe0("TurboMeter",0);
  return;
}


// ==== 0x68835f Unwind@0068835f

void Unwind_0068835f(void)

{
  FUN_00594fe0("RacePosition",0);
  return;
}


// ==== 0x688372 Unwind@00688372

void Unwind_00688372(void)

{
  FUN_00594fe0("EngineTempGauge",0);
  return;
}


// ==== 0x688385 Unwind@00688385

void Unwind_00688385(void)

{
  FUN_00594fe0("NitrousGauge",0);
  return;
}


// ==== 0x688398 Unwind@00688398

void Unwind_00688398(void)

{
  FUN_00594fe0("DriftGauge",0);
  return;
}


// ==== 0x6883ab Unwind@006883ab

void Unwind_006883ab(void)

{
  FUN_00594fe0("RaceOverMessage",0);
  return;
}


// ==== 0x6883be Unwind@006883be

void Unwind_006883be(void)

{
  FUN_00594fe0("SmokeShowGauges",0);
  return;
}


// ==== 0x6883d1 Unwind@006883d1

void Unwind_006883d1(void)

{
  FUN_00594fe0("TrackMapWrapper",0);
  return;
}


// ==== 0x6883e4 Unwind@006883e4

void Unwind_006883e4(void)

{
  FUN_00594fe0("LapCounter",0);
  return;
}


// ==== 0x6883f7 Unwind@006883f7

void Unwind_006883f7(void)

{
  FUN_00594fe0("WrongWIndi",0);
  return;
}


// ==== 0x68840a Unwind@0068840a

void Unwind_0068840a(void)

{
  FUN_00594fe0("SplitTime",0);
  return;
}


// ==== 0x68841d Unwind@0068841d

void Unwind_0068841d(void)

{
  FUN_00594fe0("CunningStuntSpread",0);
  return;
}


// ==== 0x688430 Unwind@00688430

void Unwind_00688430(void)

{
  FUN_00594fe0("Coundown",0);
  return;
}


// ==== 0x688443 Unwind@00688443

void Unwind_00688443(void)

{
  FUN_00594fe0("OnlineHUDSupport",0);
  return;
}


// ==== 0x688456 FUN_00688456

void FUN_00688456(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688460 Unwind@00688460

void Unwind_00688460(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688468 Unwind@00688468

void Unwind_00688468(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688473 FUN_00688473

void FUN_00688473(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688480 Unwind@00688480

void Unwind_00688480(void)

{
  FUN_00594fe0("StyleRewardAnimator",0);
  return;
}


// ==== 0x688493 FUN_00688493

void FUN_00688493(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6884a0 Unwind@006884a0

void Unwind_006884a0(void)

{
  FUN_00594fe0("PostRaceStatsScreen",0);
  return;
}


// ==== 0x6884b3 FUN_006884b3

void FUN_006884b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6884c0 Unwind@006884c0

void Unwind_006884c0(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6884cb Unwind@006884cb

void Unwind_006884cb(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6884d3 Unwind@006884d3

void Unwind_006884d3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6884db Unwind@006884db

void Unwind_006884db(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6884e3 Unwind@006884e3

void Unwind_006884e3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6884eb Unwind@006884eb

void Unwind_006884eb(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6884f3 FUN_006884f3

void FUN_006884f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688500 Unwind@00688500

void Unwind_00688500(void)

{
  FUN_00594fe0("PostRaceResultsScreen",0);
  return;
}


// ==== 0x688513 FUN_00688513

void FUN_00688513(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688520 Unwind@00688520

void Unwind_00688520(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688528 __CxxFrameHandler_wrapper

/* [canon] runtime low (ghidra+hopper) docs/re/runtime.md */

void __CxxFrameHandler_wrapper(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688540 Unwind@00688540

void Unwind_00688540(void)

{
  FUN_00594fe0("PostRaceMenuScreen",0);
  return;
}


// ==== 0x688553 FUN_00688553

void FUN_00688553(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688560 Unwind@00688560

void Unwind_00688560(void)

{
  FUN_00594fe0("TrackMap",0);
  return;
}


// ==== 0x688573 FUN_00688573

void FUN_00688573(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688580 Unwind@00688580

void Unwind_00688580(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x68858d Unwind@0068858d

void Unwind_0068858d(void)

{
  FUN_004318b0();
  return;
}


// ==== 0x68859b Unwind@0068859b

void Unwind_0068859b(void)

{
  Player__FreeMember960();
  return;
}


// ==== 0x6885a9 Unwind@006885a9

void Unwind_006885a9(void)

{
  FUN_0043dd10();
  return;
}


// ==== 0x6885b7 Unwind@006885b7

void Unwind_006885b7(void)

{
  FUN_00594fe0("FEngHUD",0);
  return;
}


// ==== 0x6885ca Unwind@006885ca

void Unwind_006885ca(void)

{
  FUN_00594fe0("FEngHUD",0);
  return;
}


// ==== 0x6885dd Unwind@006885dd

void Unwind_006885dd(void)

{
  FUN_00594fe0("FEngHUD",0);
  return;
}


// ==== 0x6885f0 Unwind@006885f0

void Unwind_006885f0(void)

{
  FUN_00594fe0("FEngHUD",0);
  return;
}


// ==== 0x688603 Unwind@00688603

void Unwind_00688603(void)

{
  FUN_00594fe0("FEngHUD",0);
  return;
}


// ==== 0x688616 Unwind@00688616

void Unwind_00688616(void)

{
  FUN_00594fe0("NisManager",0);
  return;
}


// ==== 0x688629 FUN_00688629

void FUN_00688629(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688640 Unwind@00688640

void Unwind_00688640(void)

{
  FUN_00594fe0("Player1",0);
  return;
}


// ==== 0x688653 Unwind@00688653

void Unwind_00688653(void)

{
  FUN_00594fe0("Player2",0);
  return;
}


// ==== 0x688666 FUN_00688666

void FUN_00688666(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688670 Unwind@00688670

void Unwind_00688670(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688678 Unwind@00688678

void Unwind_00688678(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x688683 Unwind@00688683

void Unwind_00688683(void)

{
  FUN_00417560();
  return;
}


// ==== 0x688691 Unwind@00688691

void Unwind_00688691(void)

{
  FUN_00500560();
  return;
}


// ==== 0x68869c Unwind@0068869c

void Unwind_0068869c(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6886a7 FUN_006886a7

void FUN_006886a7(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6886c0 Unwind@006886c0

void Unwind_006886c0(void)

{
  FUN_00594fe0("PCUserProfileScreen",0);
  return;
}


// ==== 0x6886d3 FUN_006886d3

void FUN_006886d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6886e0 Unwind@006886e0

void Unwind_006886e0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6886e8 Unwind@006886e8

void Unwind_006886e8(void)

{
  FUN_0041f140();
  return;
}


// ==== 0x6886f3 FUN_006886f3

void FUN_006886f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688700 Unwind@00688700

void Unwind_00688700(void)

{
  FUN_00594fe0("PCLoadSaveScreen",0);
  return;
}


// ==== 0x688713 FUN_00688713

void FUN_00688713(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688720 Unwind@00688720

void Unwind_00688720(void)

{
  FUN_00594fe0("MapScreenV2",0);
  return;
}


// ==== 0x688733 FUN_00688733

void FUN_00688733(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688740 Unwind@00688740

void Unwind_00688740(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688748 Unwind@00688748

void Unwind_00688748(void)

{
  FUN_005567f0();
  return;
}


// ==== 0x688753 FUN_00688753

void FUN_00688753(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688760 Unwind@00688760

void Unwind_00688760(void)

{
  FUN_00594fe0("OnlineGameRoomCreateGame",0);
  return;
}


// ==== 0x688773 FUN_00688773

void FUN_00688773(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688780 Unwind@00688780

void Unwind_00688780(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688788 Unwind@00688788

void Unwind_00688788(void)

{
  FUN_00594fe0("OnlineGameRoomPL",0);
  return;
}


// ==== 0x68879b FUN_0068879b

void FUN_0068879b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6887b0 Unwind@006887b0

void Unwind_006887b0(void)

{
  FUN_00594fe0("CreateOnlineGameRoom",0);
  return;
}


// ==== 0x6887c3 FUN_006887c3

void FUN_006887c3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6887d0 Unwind@006887d0

void Unwind_006887d0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6887db FUN_006887db

void FUN_006887db(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6887f0 Unwind@006887f0

void Unwind_006887f0(void)

{
  FUN_00594fe0("MagazineScreen",0);
  return;
}


// ==== 0x688803 FUN_00688803

void FUN_00688803(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688810 Unwind@00688810

void Unwind_00688810(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688818 Unwind@00688818

void Unwind_00688818(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688820 FUN_00688820

void FUN_00688820(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688830 Unwind@00688830

void Unwind_00688830(void)

{
  FUN_00594fe0("UndergroundStatsScreen",0);
  return;
}


// ==== 0x688843 FUN_00688843

void FUN_00688843(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688850 Unwind@00688850

void Unwind_00688850(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688858 Unwind@00688858

void Unwind_00688858(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688863 Unwind@00688863

void Unwind_00688863(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x68886e Unwind@0068886e

void Unwind_0068886e(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688876 FUN_00688876

void FUN_00688876(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688880 Unwind@00688880

void Unwind_00688880(void)

{
  FUN_004e2170();
  return;
}


// ==== 0x688888 _not_a_function:_SEH_frame_handler_thunk_

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void _not_a_function__SEH_frame_handler_thunk_(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6888a0 Unwind@006888a0

void Unwind_006888a0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6888a8 Unwind@006888a8

void Unwind_006888a8(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 8) + 0x5c),0x2c,10,FUN_004d7770);
  return;
}


// ==== 0x6888be Unwind@006888be

void Unwind_006888be(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 8) + 0x214),0x2c,0x14,FUN_004d7770);
  return;
}


// ==== 0x6888d6 Unwind@006888d6

void Unwind_006888d6(void)

{
  int unaff_EBP;
  
  eh_vector_destructor_iterator((void *)(*(int *)(unaff_EBP + 8) + 0x584),0x2c,0x1e,FUN_004d7770);
  return;
}


// ==== 0x6888ee Unwind@006888ee

void Unwind_006888ee(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6888fc FUN_006888fc

void FUN_006888fc(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688910 Unwind@00688910

void Unwind_00688910(void)

{
  FUN_00594fe0("ColorPicker",0);
  return;
}


// ==== 0x688923 FUN_00688923

void FUN_00688923(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688930 Unwind@00688930

void Unwind_00688930(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688938 Unwind@00688938

void Unwind_00688938(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688943 Unwind@00688943

void Unwind_00688943(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688951 Unwind@00688951

void Unwind_00688951(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x68895f Unwind@0068895f

void Unwind_0068895f(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x68896d Unwind@0068896d

void Unwind_0068896d(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x68897b Unwind@0068897b

void Unwind_0068897b(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x688989 Unwind@00688989

void Unwind_00688989(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x688997 Unwind@00688997

void Unwind_00688997(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889a5 Unwind@006889a5

void Unwind_006889a5(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889b3 Unwind@006889b3

void Unwind_006889b3(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889c1 Unwind@006889c1

void Unwind_006889c1(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889cf Unwind@006889cf

void Unwind_006889cf(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889dd Unwind@006889dd

void Unwind_006889dd(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889eb Unwind@006889eb

void Unwind_006889eb(void)

{
  ListSlider___ListSlider();
  return;
}


// ==== 0x6889f9 FUN_006889f9

void FUN_006889f9(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688a10 Unwind@00688a10

void Unwind_00688a10(void)

{
  FUN_00594fe0("OptionsMenu",0);
  return;
}


// ==== 0x688a23 FUN_00688a23

void FUN_00688a23(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688a30 Unwind@00688a30

void Unwind_00688a30(void)

{
  FUN_00594fe0("PauseMenu",0);
  return;
}


// ==== 0x688a43 FUN_00688a43

void FUN_00688a43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688a50 Unwind@00688a50

void Unwind_00688a50(void)

{
  FUN_00594fe0("ThumbnailScroller",0);
  return;
}


// ==== 0x688a63 FUN_00688a63

void FUN_00688a63(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688a70 Unwind@00688a70

void Unwind_00688a70(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688a78 Unwind@00688a78

void Unwind_00688a78(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688a83 Unwind@00688a83

void Unwind_00688a83(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688a8e FUN_00688a8e

void FUN_00688a8e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688aa0 Unwind@00688aa0

void Unwind_00688aa0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688aa8 Unwind@00688aa8

void Unwind_00688aa8(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688ab3 Unwind@00688ab3

void Unwind_00688ab3(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688ac1 Unwind@00688ac1

void Unwind_00688ac1(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688acf Unwind@00688acf

void Unwind_00688acf(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688add Unwind@00688add

void Unwind_00688add(void)

{
  FUN_00414ab0();
  return;
}


// ==== 0x688aeb FUN_00688aeb

void FUN_00688aeb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688b00 Unwind@00688b00

void Unwind_00688b00(void)

{
  FUN_00594fe0("PauseOptionsMenu",0);
  return;
}


// ==== 0x688b13 FUN_00688b13

void FUN_00688b13(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688b20 Unwind@00688b20

void Unwind_00688b20(void)

{
  RefArray_DecrementAll();
  return;
}


// ==== 0x688b2d Unwind@00688b2d

void Unwind_00688b2d(void)

{
  FUN_004318b0();
  return;
}


// ==== 0x688b3b Unwind@00688b3b

void Unwind_00688b3b(void)

{
  Player__FreeMember960();
  return;
}


// ==== 0x688b49 Unwind@00688b49

void Unwind_00688b49(void)

{
  FUN_0043dd10();
  return;
}


// ==== 0x688b57 FUN_00688b57

void FUN_00688b57(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688b70 Unwind@00688b70

void Unwind_00688b70(void)

{
  FUN_00594fe0("GaragePresetsScreen",0);
  return;
}


// ==== 0x688b83 FUN_00688b83

void FUN_00688b83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688b90 Unwind@00688b90

void Unwind_00688b90(void)

{
  FUN_00594fe0("UndergroundTradeCarScreen",0);
  return;
}


// ==== 0x688ba3 FUN_00688ba3

void FUN_00688ba3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688bb0 Unwind@00688bb0

void Unwind_00688bb0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688bb8 Unwind@00688bb8

void Unwind_00688bb8(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x688bc3 Unwind@00688bc3

void Unwind_00688bc3(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688bce Unwind@00688bce

void Unwind_00688bce(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x688bdc FUN_00688bdc

void FUN_00688bdc(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688bf0 Unwind@00688bf0

void Unwind_00688bf0(void)

{
  thunk_FUN_00421900();
  return;
}


// ==== 0x688bfb FUN_00688bfb

void FUN_00688bfb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688c10 Unwind@00688c10

void Unwind_00688c10(void)

{
  FUN_004e2170();
  return;
}


// ==== 0x688c18 FUN_00688c18

void FUN_00688c18(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688c30 Unwind@00688c30

void Unwind_00688c30(void)

{
  int unaff_EBP;
  
  NullUpdate_ret(*(undefined4 *)(unaff_EBP + -0x10),"LoadingScreen");
  return;
}


// ==== 0x688c42 FUN_00688c42

void FUN_00688c42(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688c50 Unwind@00688c50

void Unwind_00688c50(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688c58 Unwind@00688c58

void Unwind_00688c58(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688c60 Unwind@00688c60

void Unwind_00688c60(void)

{
  FUN_00500560();
  return;
}


// ==== 0x688c68 FUN_00688c68

void FUN_00688c68(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688c80 Unwind@00688c80

void Unwind_00688c80(void)

{
  FUN_00594fe0("HUDMenu",0);
  return;
}


// ==== 0x688c93 FUN_00688c93

void FUN_00688c93(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688ca0 Unwind@00688ca0

void Unwind_00688ca0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688ca8 Unwind@00688ca8

void Unwind_00688ca8(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688cb3 Unwind@00688cb3

void Unwind_00688cb3(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688cbe FUN_00688cbe

void FUN_00688cbe(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688cd0 Unwind@00688cd0

void Unwind_00688cd0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688cd8 Unwind@00688cd8

void Unwind_00688cd8(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688ce3 Unwind@00688ce3

void Unwind_00688ce3(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688cee FUN_00688cee

void FUN_00688cee(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688d00 Unwind@00688d00

void Unwind_00688d00(void)

{
  DAT_00792fa0 = DAT_00792fa0 & 0xfffffffe;
  return;
}


// ==== 0x688d0e FUN_00688d0e

void FUN_00688d0e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688d20 Unwind@00688d20

void Unwind_00688d20(void)

{
  FUN_00594fe0("tPreRaceScreenManager",0);
  return;
}


// ==== 0x688d33 FUN_00688d33

void FUN_00688d33(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688d40 Unwind@00688d40

void Unwind_00688d40(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688d48 Unwind@00688d48

void Unwind_00688d48(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688d53 Unwind@00688d53

void Unwind_00688d53(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688d5e FUN_00688d5e

void FUN_00688d5e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688d70 Unwind@00688d70

void Unwind_00688d70(void)

{
  FUN_00594fe0("OnlinePlayerCar",0);
  return;
}


// ==== 0x688d83 FUN_00688d83

void FUN_00688d83(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688d90 Unwind@00688d90

void Unwind_00688d90(void)

{
  FUN_00594fe0("OnlineMenu",0);
  return;
}


// ==== 0x688da3 FUN_00688da3

void FUN_00688da3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688db0 Unwind@00688db0

void Unwind_00688db0(void)

{
  FUN_00594fe0("GarageChooseAccessoryCategoryScreen",0);
  return;
}


// ==== 0x688dc3 FUN_00688dc3

void FUN_00688dc3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688dd0 Unwind@00688dd0

void Unwind_00688dd0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688dd8 Unwind@00688dd8

void Unwind_00688dd8(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x688de3 Unwind@00688de3

void Unwind_00688de3(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688dee Unwind@00688dee

void Unwind_00688dee(void)

{
  FUN_00577f30();
  return;
}


// ==== 0x688dfc Unwind@00688dfc

void Unwind_00688dfc(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688e04 FUN_00688e04

void FUN_00688e04(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688e10 Unwind@00688e10

void Unwind_00688e10(void)

{
  FUN_00594fe0("GarageDecalsBrand",0);
  return;
}


// ==== 0x688e23 FUN_00688e23

void FUN_00688e23(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688e30 Unwind@00688e30

void Unwind_00688e30(void)

{
  FUN_00594fe0("GarageDecalLayout",0);
  return;
}


// ==== 0x688e43 FUN_00688e43

void FUN_00688e43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688e50 Unwind@00688e50

void Unwind_00688e50(void)

{
  FUN_00594fe0("GarageDecalsZone",0);
  return;
}


// ==== 0x688e63 FUN_00688e63

void FUN_00688e63(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688e70 Unwind@00688e70

void Unwind_00688e70(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688e78 Unwind@00688e78

void Unwind_00688e78(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x688e83 Unwind@00688e83

void Unwind_00688e83(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688e8e Unwind@00688e8e

void Unwind_00688e8e(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x688e96 FUN_00688e96

void FUN_00688e96(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688ea0 Unwind@00688ea0

void Unwind_00688ea0(void)

{
  FUN_00594fe0("GaragePaintModScreen",0);
  return;
}


// ==== 0x688eb3 FUN_00688eb3

void FUN_00688eb3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688ec0 Unwind@00688ec0

void Unwind_00688ec0(void)

{
  FUN_00594fe0("GaragePerfBrandPackage",0);
  return;
}


// ==== 0x688ed3 FUN_00688ed3

void FUN_00688ed3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688ee0 Unwind@00688ee0

void Unwind_00688ee0(void)

{
  FUN_00594fe0("GaragePerfTuner",0);
  return;
}


// ==== 0x688ef3 FUN_00688ef3

void FUN_00688ef3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688f00 Unwind@00688f00

void Unwind_00688f00(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688f08 Unwind@00688f08

void Unwind_00688f08(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x688f13 Unwind@00688f13

void Unwind_00688f13(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x688f1e FUN_00688f1e

void FUN_00688f1e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688f30 Unwind@00688f30

void Unwind_00688f30(void)

{
  FUN_00594fe0("ChooseGaragePerfPath",0);
  return;
}


// ==== 0x688f43 FUN_00688f43

void FUN_00688f43(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688f50 Unwind@00688f50

void Unwind_00688f50(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688f58 Unwind@00688f58

void Unwind_00688f58(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688f63 Unwind@00688f63

void Unwind_00688f63(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688f71 Unwind@00688f71

void Unwind_00688f71(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688f7f FUN_00688f7f

void FUN_00688f7f(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688f90 Unwind@00688f90

void Unwind_00688f90(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x688f98 Unwind@00688f98

void Unwind_00688f98(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688fa3 Unwind@00688fa3

void Unwind_00688fa3(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688fb1 Unwind@00688fb1

void Unwind_00688fb1(void)

{
  FUN_005041a0();
  return;
}


// ==== 0x688fbf FUN_00688fbf

void FUN_00688fbf(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688fd0 Unwind@00688fd0

void Unwind_00688fd0(void)

{
  FUN_00594fe0("PerfStatsScreen",0);
  return;
}


// ==== 0x688fe3 FUN_00688fe3

void FUN_00688fe3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x688ff0 Unwind@00688ff0

void Unwind_00688ff0(void)

{
  FUN_00594fe0("GaragePartsBrowser",0);
  return;
}


// ==== 0x689003 FUN_00689003

void FUN_00689003(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689010 Unwind@00689010

void Unwind_00689010(void)

{
  FUN_00594fe0("GarageCategoryVisual",0);
  return;
}


// ==== 0x689023 FUN_00689023

void FUN_00689023(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689030 Unwind@00689030

void Unwind_00689030(void)

{
  FUN_00594fe0("GarageChooseVisualCategoryScreen",0);
  return;
}


// ==== 0x689043 FUN_00689043

void FUN_00689043(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689050 Unwind@00689050

void Unwind_00689050(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689058 Unwind@00689058

void Unwind_00689058(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x689063 Unwind@00689063

void Unwind_00689063(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x68906e FUN_0068906e

void FUN_0068906e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689080 Unwind@00689080

void Unwind_00689080(void)

{
  FUN_00594fe0("GarageScreen",0);
  return;
}


// ==== 0x689093 FUN_00689093

void FUN_00689093(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6890a0 Unwind@006890a0

void Unwind_006890a0(void)

{
  FUN_00594fe0("GarageVinylBrowserScreen",0);
  return;
}


// ==== 0x6890b3 FUN_006890b3

void FUN_006890b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6890c0 Unwind@006890c0

void Unwind_006890c0(void)

{
  FUN_00594fe0("GarageVinylGroupScreen",0);
  return;
}


// ==== 0x6890d3 FUN_006890d3

void FUN_006890d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6890e0 Unwind@006890e0

void Unwind_006890e0(void)

{
  FUN_00594fe0("GarageVinylTypeScreen",0);
  return;
}


// ==== 0x6890f3 FUN_006890f3

void FUN_006890f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689100 Unwind@00689100

void Unwind_00689100(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689108 Unwind@00689108

void Unwind_00689108(void)

{
  FUN_004e0650();
  return;
}


// ==== 0x689113 Unwind@00689113

void Unwind_00689113(void)

{
  FUN_004e0650();
  return;
}


// ==== 0x68911e FUN_0068911e

void FUN_0068911e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689130 Unwind@00689130

void Unwind_00689130(void)

{
  FUN_00594fe0("MPCarSelectScreen",0);
  return;
}


// ==== 0x689143 FUN_00689143

void FUN_00689143(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689150 Unwind@00689150

void Unwind_00689150(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689158 Unwind@00689158

void Unwind_00689158(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x689163 Unwind@00689163

void Unwind_00689163(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x68916e FUN_0068916e

void FUN_0068916e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689180 Unwind@00689180

void Unwind_00689180(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689188 Unwind@00689188

void Unwind_00689188(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x689193 Unwind@00689193

void Unwind_00689193(void)

{
  FUN_004c7080();
  return;
}


// ==== 0x68919e Unwind@0068919e

void Unwind_0068919e(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6891a6 Unwind@006891a6

void Unwind_006891a6(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6891ae Unwind@006891ae

void Unwind_006891ae(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6891b6 FUN_006891b6

void FUN_006891b6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6891c0 Unwind@006891c0

void Unwind_006891c0(void)

{
  FUN_00594fe0("MainMenuCarCustomize",0);
  return;
}


// ==== 0x6891d3 FUN_006891d3

void FUN_006891d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6891e0 Unwind@006891e0

void Unwind_006891e0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6891e8 Unwind@006891e8

void Unwind_006891e8(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6891f3 FUN_006891f3

void FUN_006891f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689200 Unwind@00689200

void Unwind_00689200(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689208 Unwind@00689208

void Unwind_00689208(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x689213 Unwind@00689213

void Unwind_00689213(void)

{
  FUN_004f84d0();
  return;
}


// ==== 0x68921e FUN_0068921e

void FUN_0068921e(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689230 Unwind@00689230

void Unwind_00689230(void)

{
  FUN_00594fe0("QRCarSelectScreen",0);
  return;
}


// ==== 0x689243 FUN_00689243

void FUN_00689243(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689250 Unwind@00689250

void Unwind_00689250(void)

{
  FUN_00594fe0("QRTrackSelectScreen",0);
  return;
}


// ==== 0x689263 FUN_00689263

void FUN_00689263(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689270 Unwind@00689270

void Unwind_00689270(void)

{
  FUN_00594fe0("QROptionsScreen",0);
  return;
}


// ==== 0x689283 FUN_00689283

void FUN_00689283(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689290 Unwind@00689290

void Unwind_00689290(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689298 Unwind@00689298

void Unwind_00689298(void)

{
  std__list__clear__free_every_node__head_in_ESI_();
  return;
}


// ==== 0x6892a3 Unwind@006892a3

void Unwind_006892a3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6892ab Unwind@006892ab

void Unwind_006892ab(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6892b3 Unwind@006892b3

void Unwind_006892b3(void)

{
  FUN_00500560();
  return;
}


// ==== 0x6892bb FUN_006892bb

void FUN_006892bb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6892d0 Unwind@006892d0

void Unwind_006892d0(void)

{
  FUN_00594fe0("QRModeSelectScreen",0);
  return;
}


// ==== 0x6892e3 FUN_006892e3

void FUN_006892e3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6892f0 Unwind@006892f0

void Unwind_006892f0(void)

{
  FUN_00594fe0("GameMainMenuScreen",0);
  return;
}


// ==== 0x689303 FUN_00689303

void FUN_00689303(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689310 Unwind@00689310

void Unwind_00689310(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689318 Unwind@00689318

void Unwind_00689318(void)

{
  ListRef_Release();
  return;
}


// ==== 0x689323 Unwind@00689323

void Unwind_00689323(void)

{
  FUN_004ae990();
  return;
}


// ==== 0x689330 Unwind@00689330

void Unwind_00689330(void)

{
  FUN_00594fe0("FrontendRenderingCar",0);
  return;
}


// ==== 0x689343 Unwind@00689343

void Unwind_00689343(void)

{
  FUN_00594fe0("FrontendRenderingCar",0);
  return;
}


// ==== 0x689356 FUN_00689356

void FUN_00689356(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689360 Unwind@00689360

void Unwind_00689360(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x68936b Unwind@0068936b

void Unwind_0068936b(void)

{
  DAT_00792fa0 = DAT_00792fa0 & 0xfffffffe;
  return;
}


// ==== 0x689379 Unwind@00689379

void Unwind_00689379(void)

{
  DAT_00792fa0 = DAT_00792fa0 & 0xfffffffe;
  return;
}


// ==== 0x689387 FUN_00689387

void FUN_00689387(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689391 FUN_00689391

void FUN_00689391(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x6893a0 Unwind@006893a0

void Unwind_006893a0(void)

{
  FUN_00594fe0("GarageDecalsSlot",0);
  return;
}


// ==== 0x6893b3 FUN_006893b3

void FUN_006893b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6893c0 Unwind@006893c0

void Unwind_006893c0(void)

{
  FUN_00594fe0("GarageRimsBrowser",0);
  return;
}


// ==== 0x6893d3 FUN_006893d3

void FUN_006893d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6893e0 Unwind@006893e0

void Unwind_006893e0(void)

{
  FUN_00594fe0("GarageRimsBrandBrowserScreen",0);
  return;
}


// ==== 0x6893f3 FUN_006893f3

void FUN_006893f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689400 Unwind@00689400

void Unwind_00689400(void)

{
  FUN_00594fe0("UndergroundMenuScreen",0);
  return;
}


// ==== 0x689413 FUN_00689413

void FUN_00689413(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689420 Unwind@00689420

void Unwind_00689420(void)

{
  FUN_00594fe0("UndergroundMagazineGiveth",0);
  return;
}


// ==== 0x689433 FUN_00689433

void FUN_00689433(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689440 Unwind@00689440

void Unwind_00689440(void)

{
  FUN_00594fe0("UndergroundSamanthaGiveth",0);
  return;
}


// ==== 0x689453 FUN_00689453

void FUN_00689453(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689460 Unwind@00689460

void Unwind_00689460(void)

{
  FUN_00594fe0("UndergroundJunkmanGiveth",0);
  return;
}


// ==== 0x689473 FUN_00689473

void FUN_00689473(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689480 Unwind@00689480

void Unwind_00689480(void)

{
  FUN_00594fe0("UndergroundMapScreen",0);
  return;
}


// ==== 0x689493 FUN_00689493

void FUN_00689493(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6894a0 Unwind@006894a0

void Unwind_006894a0(void)

{
  FUN_00594fe0("ChooseCareerCarScreen",0);
  return;
}


// ==== 0x6894b3 FUN_006894b3

void FUN_006894b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6894c0 Unwind@006894c0

void Unwind_006894c0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6894c8 Unwind@006894c8

void Unwind_006894c8(void)

{
  DAT_00792fa0 = DAT_00792fa0 & 0xfffffffe;
  return;
}


// ==== 0x6894d6 Unwind@006894d6

void Unwind_006894d6(void)

{
  DAT_00792fa0 = DAT_00792fa0 & 0xfffffffe;
  return;
}


// ==== 0x6894e4 Unwind@006894e4

void Unwind_006894e4(void)

{
  FUN_00594fe0("GarageMainScreen",0);
  return;
}


// ==== 0x6894f7 Unwind@006894f7

void Unwind_006894f7(void)

{
  FUN_00594fe0("GarageMainScreen",0);
  return;
}


// ==== 0x68950a FUN_0068950a

void FUN_0068950a(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689520 Unwind@00689520

void Unwind_00689520(void)

{
  FUN_00594fe0("GarageMainScreen",0);
  return;
}


// ==== 0x689533 FUN_00689533

void FUN_00689533(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689540 Unwind@00689540

void Unwind_00689540(void)

{
  FUN_00594fe0("GarageMainScreen2P",0);
  return;
}


// ==== 0x689553 FUN_00689553

void FUN_00689553(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689560 Unwind@00689560

void Unwind_00689560(void)

{
  FUN_00594fe0("GarageRimsStyleBrowser",0);
  return;
}


// ==== 0x689573 FUN_00689573

void FUN_00689573(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689580 Unwind@00689580

void Unwind_00689580(void)

{
  FUN_00594fe0("TempUserProfile",0);
  return;
}


// ==== 0x689593 FUN_00689593

void FUN_00689593(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6895a0 Unwind@006895a0

void Unwind_006895a0(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x6895a8 Unwind@006895a8

void Unwind_006895a8(void)

{
  FUN_00417560();
  return;
}


// ==== 0x6895b6 FUN_006895b6

void FUN_006895b6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6895c0 Unwind@006895c0

void Unwind_006895c0(void)

{
  FUN_00594fe0("UserProfileScreen",0);
  return;
}


// ==== 0x6895d3 FUN_006895d3

void FUN_006895d3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6895e0 Unwind@006895e0

void Unwind_006895e0(void)

{
  FUN_00594fe0("EAXFrontEnd",0);
  return;
}


// ==== 0x6895f3 FUN_006895f3

void FUN_006895f3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689600 Unwind@00689600

void Unwind_00689600(void)

{
  FUN_005944d0();
  return;
}


// ==== 0x689608 FUN_00689608

void FUN_00689608(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689620 Unwind@00689620

void Unwind_00689620(void)

{
  FUN_00594fe0("EAXS_AmbStereoStream",0);
  return;
}


// ==== 0x689633 FUN_00689633

void FUN_00689633(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689640 Unwind@00689640

void Unwind_00689640(void)

{
  FUN_004f7b50();
  return;
}


// ==== 0x689648 Unwind@00689648

void Unwind_00689648(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689650 Unwind@00689650

void Unwind_00689650(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689658 Unwind@00689658

void Unwind_00689658(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689660 Unwind@00689660

void Unwind_00689660(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689668 Unwind@00689668

void Unwind_00689668(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689670 Unwind@00689670

void Unwind_00689670(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689678 Unwind@00689678

void Unwind_00689678(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689680 Unwind@00689680

void Unwind_00689680(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689688 Unwind@00689688

void Unwind_00689688(void)

{
  FUN_00500560();
  return;
}


// ==== 0x689690 FUN_00689690

void FUN_00689690(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6896a0 Unwind@006896a0

void Unwind_006896a0(void)

{
  FUN_00594fe0("OnlineMembership",0);
  return;
}


// ==== 0x6896b3 FUN_006896b3

void FUN_006896b3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6896c0 Unwind@006896c0

void Unwind_006896c0(void)

{
  FlowMessageList__FreeAll();
  return;
}


// ==== 0x6896cb FUN_006896cb

void FUN_006896cb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6896e0 Unwind@006896e0

void Unwind_006896e0(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== 0x6896eb FUN_006896eb

void FUN_006896eb(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689700 Unwind@00689700

void Unwind_00689700(void)

{
  FUN_00594fe0("cPostRaceScreenMgrInterface",0);
  return;
}


// ==== 0x689713 FUN_00689713

void FUN_00689713(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689720 Unwind@00689720

void Unwind_00689720(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0xc));
  return;
}


// ==== 0x68972b FUN_0068972b

void FUN_0068972b(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689740 Unwind@00689740

void Unwind_00689740(void)

{
  FUN_004219f0();
  return;
}


// ==== 0x689748 FUN_00689748

void FUN_00689748(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689760 Unwind@00689760

void Unwind_00689760(void)

{
  FUN_00594fe0("TimeAroundTrackTable",0);
  return;
}


// ==== 0x689773 FUN_00689773

void FUN_00689773(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x689780 Unwind@00689780

void Unwind_00689780(void)

{
  FUN_00594fe0(&DAT_006cae4c,0);
  return;
}


// ==== 0x689793 Unwind@00689793

void Unwind_00689793(void)

{
  FUN_00594fe0("World",0);
  return;
}


// ==== 0x6897a6 FUN_006897a6

void FUN_006897a6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6897b0 Unwind@006897b0

void Unwind_006897b0(void)

{
  FUN_00594fe0("RaceCoordinator",0);
  return;
}


// ==== 0x6897c3 FUN_006897c3

void FUN_006897c3(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6897d0 Unwind@006897d0

void Unwind_006897d0(void)

{
  FUN_004b39a0();
  return;
}


// ==== 0x6897db Unwind@006897db

void Unwind_006897db(void)

{
  FUN_004b39a0();
  return;
}


// ==== 0x6897e6 FUN_006897e6

void FUN_006897e6(void)

{
  ___CxxFrameHandler();
  return;
}


// ==== 0x6897f0 StaticInit_ParticleEmitter_G78e974_6897f0

/* [canon] assets med (capstone+refs) docs/re/misc.md */

void StaticInit_ParticleEmitter_G78e974_6897f0(void)

{
  bList__bList();
  _atexit(StaticInit_ParticleEmitter_G78e974_696200);
  return;
}


// ==== 0x689810 FUN_00689810

void FUN_00689810(void)

{
  ParticleLists_Init();
  _atexit(FUN_00696210);
  return;
}


// ==== 0x689830 FUN_00689830

void FUN_00689830(void)

{
  ParticleLists_Init();
  _atexit(FUN_00696220);
  return;
}


// ==== 0x689850 FUN_00689850

void FUN_00689850(void)

{
  eh_vector_constructor_iterator(&DAT_0078daa8,0x270,6,FUN_00405bf0,FUN_00405c50);
  _atexit(FUN_00696230);
  return;
}


// ==== 0x689880 FUN_00689880

void FUN_00689880(void)

{
  bList__bList();
  _atexit(FUN_00696250);
  return;
}


// ==== 0x6898a0 FUN_006898a0

void FUN_006898a0(void)

{
  FUN_0047cf30();
  return;
}


// ==== 0x6898b0 FUN_006898b0

void FUN_006898b0(void)

{
  FUN_0047cf30();
  return;
}


// ==== 0x6898c0 FUN_006898c0

void FUN_006898c0(void)

{
  FUN_0047cf30();
  return;
}


// ==== 0x6898d0 FUN_006898d0

void FUN_006898d0(void)

{
  FUN_0047cf30();
  return;
}


// ==== 0x6898e0 FUN_006898e0

void FUN_006898e0(void)

{
  FUN_0047cf30();
  return;
}


// ==== 0x6898f0 FUN_006898f0

void FUN_006898f0(void)

{
  int iVar1;
  
  iVar1 = 6;
  do {
    FUN_0047cf30();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== 0x689920 FUN_00689920

void FUN_00689920(void)

{
  DAT_0078bd40 = 0x4000;
  return;
}


// ==== 0x689930 FUN_00689930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689930(void)

{
  _DAT_0078bca8 = _K_ONE / 1677721.5;
  _DAT_0078bc48 = _DAT_0078bca8 * 10.0;
  _DAT_0078bc4c = _DAT_0078bca8 * 11.0;
  _DAT_0078bc50 = _DAT_0078bca8 * 12.0;
  _DAT_0078bc54 = _DAT_0078bca8 * 13.0;
  _DAT_0078bc58 = _DAT_0078bca8 * 14.0;
  _DAT_0078bc5c = _DAT_0078bca8 * 15.0;
  _DAT_0078bc60 = _DAT_0078bca8 * 16.0;
  _DAT_0078bc64 = _DAT_0078bca8 * 17.0;
  _DAT_0078bc68 = _DAT_0078bca8 * 18.0;
  _DAT_0078bc6c = _DAT_0078bca8 * 19.0;
  _DAT_0078bc70 = _DAT_0078bca8 * 20.0;
  _DAT_0078bc74 = _DAT_0078bca8 * 21.0;
  _DAT_0078bc78 = _DAT_0078bca8 * 22.0;
  _DAT_0078bc7c = _DAT_0078bca8 * 23.0;
  _DAT_0078bc80 = _DAT_0078bca8 * 24.0;
  _DAT_0078bc84 = _DAT_0078bca8 * 25.0;
  _DAT_0078bc88 = _DAT_0078bca8 * 5.0;
  _DAT_0078bc8c = _DAT_0078bca8 * 6.0;
  _DAT_0078bc90 = _DAT_0078bca8 * 7.0;
  _DAT_0078bc94 = _DAT_0078bca8 * fRam006cc7c0;
  _DAT_0078bc98 = _DAT_0078bca8 * 5.0;
  _DAT_0078bc9c = _DAT_0078bca8 * 4.0;
  _DAT_0078bca0 = _DAT_0078bca8 * 3.0;
  _DAT_0078bca4 = _DAT_0078bca8 + _DAT_0078bca8;
  _DAT_0078bcac = _DAT_0078bca8;
  _DAT_0078bcb0 = _DAT_0078bca8 + _DAT_0078bca8;
  _DAT_0078bcb4 = _DAT_0078bca8 * 3.0;
  _DAT_0078bcb8 = _DAT_0078bca8 * 4.0;
  return;
}


// ==== 0x689ab0 FUN_00689ab0

void FUN_00689ab0(void)

{
  bList__bList();
  _atexit(FUN_00696260);
  return;
}


// ==== 0x689ad0 FUN_00689ad0

void FUN_00689ad0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "DEFAULTALPHA";
  DAT_0078a4e0 = -1;
  uVar2 = 0x44;
  do {
    DAT_0078a4e0 = DAT_0078a4e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x689b00 FUN_00689b00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689b00(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "CarSkin GlossMap";
  _DAT_0078aa30 = -1;
  uVar2 = 0x43;
  do {
    _DAT_0078aa30 = _DAT_0078aa30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x689b30 FUN_00689b30

void FUN_00689b30(void)

{
  eh_vector_constructor_iterator
            (&DAT_0078a4e8,0x38,0x10,RenderQueueBuckets_Construct,RenderQueueBuckets_Destruct);
  _atexit(FUN_00696270);
  return;
}


// ==== 0x689b60 FUN_00689b60

void FUN_00689b60(void)

{
  _atexit(FUN_00696290);
  return;
}


// ==== 0x689b70 FUN_00689b70

void FUN_00689b70(void)

{
  _atexit(FUN_006962a0);
  return;
}


// ==== 0x689b80 FUN_00689b80

void FUN_00689b80(void)

{
  Struct_ClearFields8();
  _atexit(FUN_006962b0);
  return;
}


// ==== 0x689ba0 FUN_00689ba0

void FUN_00689ba0(void)

{
  _atexit(FUN_006962c0);
  return;
}


// ==== 0x689bb0 FUN_00689bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bb0(void)

{
  _DAT_0078a46c = 0x40c90fdb;
  return;
}


// ==== 0x689bc0 FUN_00689bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bc0(void)

{
  _DAT_0078a468 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x689be0 FUN_00689be0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689be0(void)

{
  _DAT_0078a460 = 0x401921fb54442d18;
  return;
}


// ==== 0x689bf0 FUN_00689bf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689bf0(void)

{
  _DAT_0078a470 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x689c10 FUN_00689c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c10(void)

{
  _DAT_0078a454 = 0x40c90fdb;
  return;
}


// ==== 0x689c20 FUN_00689c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c20(void)

{
  _DAT_0078a450 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x689c40 FUN_00689c40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c40(void)

{
  _DAT_0078a448 = 0x401921fb54442d18;
  return;
}


// ==== 0x689c50 FUN_00689c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c50(void)

{
  _DAT_0078a458 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x689c70 FUN_00689c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c70(void)

{
  _DAT_0078a444 = 0x40c90fdb;
  return;
}


// ==== 0x689c80 FUN_00689c80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689c80(void)

{
  _DAT_0078a440 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x689ca0 FUN_00689ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689ca0(void)

{
  _DAT_0078a438 = 0x401921fb54442d18;
  return;
}


// ==== 0x689cb0 FUN_00689cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689cb0(void)

{
  _DAT_0078a430 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x689cd0 FUN_00689cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689cd0(void)

{
  _DAT_0078a428 = _K_ONE - 0.92;
  return;
}


// ==== 0x689cf0 FUN_00689cf0

void FUN_00689cf0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0078a3ac;
  iVar2 = 2;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 0xe;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00431df0();
  return;
}


// ==== 0x689d20 FUN_00689d20

void FUN_00689d20(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0077cec4;
  iVar2 = 0x1e;
  do {
    puVar1[-0x734] = 0;
    RideInfo__Init();
    *puVar1 = 0;
    puVar1 = puVar1 + 0x750;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x689d60 FUN_00689d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689d60(void)

{
  _DAT_0077c77c = 0x40c90fdb;
  return;
}


// ==== 0x689d80 FUN_00689d80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689d80(void)

{
  _DAT_0077c778 = 0x3fc90fdb;
  return;
}


// ==== 0x689da0 FUN_00689da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689da0(void)

{
  _DAT_0077c770 = 0x401921fb54442d18;
  return;
}


// ==== 0x689dc0 FUN_00689dc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689dc0(void)

{
  _DAT_0077c780 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x689de0 FUN_00689de0

void FUN_00689de0(void)

{
  FUN_00439aa0();
  _atexit(FUN_006962d0);
  return;
}


// ==== 0x689e00 FUN_00689e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689e00(void)

{
  _DAT_0077c788 = 0x41880000;
  return;
}


// ==== 0x689e20 FUN_00689e20

void FUN_00689e20(void)

{
  eh_vector_constructor_iterator(&DAT_0077b1a0,0x28,4,FUN_0043db80,FUN_0043dc20);
  _atexit(FUN_006962e0);
  return;
}


// ==== 0x689e50 FUN_00689e50

void FUN_00689e50(void)

{
  FUN_00598420();
  _atexit(FUN_00696300);
  return;
}


// ==== 0x689e70 FUN_00689e70

void FUN_00689e70(void)

{
  bList__bList();
  _atexit(FUN_00696310);
  return;
}


// ==== 0x689e90 FUN_00689e90

void FUN_00689e90(void)

{
  FUN_00441270();
  _atexit(FUN_00696320);
  return;
}


// ==== 0x689eb0 FUN_00689eb0

void FUN_00689eb0(void)

{
  FUN_00442b00();
  _atexit(FUN_00696330);
  return;
}


// ==== 0x689ed0 FUN_00689ed0

void FUN_00689ed0(void)

{
  _atexit(FUN_00696340);
  return;
}


// ==== 0x689ee0 FUN_00689ee0

void FUN_00689ee0(void)

{
  FUN_00444340();
  _atexit(FUN_00696350);
  return;
}


// ==== 0x689f00 FUN_00689f00

void FUN_00689f00(void)

{
  bList__bList();
  _atexit(FUN_00696360);
  return;
}


// ==== 0x689f20 FUN_00689f20

void FUN_00689f20(void)

{
  FUN_00446900();
  _atexit(FUN_00696370);
  return;
}


// ==== 0x689f40 StaticInit_CreateResourceFile_G77a924_689f40

/* [canon] assets med (capstone+refs) docs/re/misc.md */

void StaticInit_CreateResourceFile_G77a924_689f40(void)

{
  bList__bList();
  _atexit(StaticInit_CreateResourceFile_G77a924_696380);
  return;
}


// ==== 0x689f60 FUN_00689f60

void FUN_00689f60(void)

{
  _atexit(FUN_00696390);
  return;
}


// ==== 0x689f70 FUN_00689f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689f70(void)

{
  _DAT_0077a8fc = 0xc000;
  return;
}


// ==== 0x689f80 FUN_00689f80

void FUN_00689f80(void)

{
  FUN_004561a0();
  _atexit(FUN_006963a0);
  return;
}


// ==== 0x689fa0 FUN_00689fa0

void FUN_00689fa0(void)

{
  FUN_004561a0();
  _atexit(FUN_006963b0);
  return;
}


// ==== 0x689fc0 FUN_00689fc0

void FUN_00689fc0(void)

{
  _atexit(FUN_006963c0);
  return;
}


// ==== 0x689fd0 FUN_00689fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689fd0(void)

{
  _DAT_0077a4a8 = _DAT_0070067c * _DAT_0070067c;
  return;
}


// ==== 0x689ff0 FUN_00689ff0

void FUN_00689ff0(void)

{
  DAT_0077a4a4 = 0x3dd67750;
  return;
}


// ==== 0x68a000 FUN_0068a000

void FUN_0068a000(void)

{
  bList__bList();
  _atexit(FUN_006963d0);
  return;
}


// ==== 0x68a020 FUN_0068a020

void FUN_0068a020(void)

{
  bList__bList();
  _atexit(FUN_006963e0);
  return;
}


// ==== 0x68a040 StaticInit_CarShape_G779bd8_68a040

/* [canon] assets med (capstone+refs) docs/re/misc.md */

void StaticInit_CarShape_G779bd8_68a040(void)

{
  bList__bList();
  _atexit(StaticInit_CarShape_G779bd8_6963f0);
  return;
}


// ==== 0x68a060 FUN_0068a060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a060(void)

{
  _DAT_00779bd4 = 0x40c90fdb;
  return;
}


// ==== 0x68a070 FUN_0068a070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a070(void)

{
  _DAT_00779bd0 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a090 FUN_0068a090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a090(void)

{
  _DAT_00779bc8 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a0a0 FUN_0068a0a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0a0(void)

{
  _DAT_00779bc0 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a0c0 FUN_0068a0c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0c0(void)

{
  _DAT_00779ad4 = 0x40c90fdb;
  return;
}


// ==== 0x68a0d0 FUN_0068a0d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0d0(void)

{
  _DAT_00779ad0 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a0f0 FUN_0068a0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a0f0(void)

{
  _DAT_00779ac8 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a100 FUN_0068a100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a100(void)

{
  _DAT_00779ac0 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a120 FUN_0068a120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a120(void)

{
  _DAT_00779ab0 = 0x3db2b8c2;
  return;
}


// ==== 0x68a130 FUN_0068a130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a130(void)

{
  _DAT_00779b70 = 0;
  _DAT_00779b74 = 0;
  _DAT_00779b78 = 0x3f490fdb;
  _DAT_00779b7c = 0x3f333333;
  _DAT_00779b80 = 0x3fa78d36;
  _DAT_00779b84 = 0x3f666666;
  _DAT_00779b88 = 0x3fc6d3f2;
  _DAT_00779b8c = 0x3f800000;
  _DAT_00779b90 = 0x3fc90fdb;
  _DAT_00779b94 = 0;
  return;
}


// ==== 0x68a1a0 FUN_0068a1a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a1a0(void)

{
  _DAT_00779ab4 = &DAT_00779b70;
  _DAT_00779ab8 = 5;
  return;
}


// ==== 0x68a1c0 FUN_0068a1c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a1c0(void)

{
  _DAT_00779b98 = 0;
  _DAT_00779b9c = 0;
  _DAT_00779ba0 = 0x3f490fdb;
  _DAT_00779ba4 = 0x3e8ccccd;
  _DAT_00779ba8 = 0x3fa78d36;
  _DAT_00779bac = 0x3f800000;
  _DAT_00779bb0 = 0x3fc6d3f2;
  _DAT_00779bb4 = 0x3f800000;
  _DAT_00779bb8 = 0x3fc90fdb;
  _DAT_00779bbc = 0;
  return;
}


// ==== 0x68a230 FUN_0068a230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a230(void)

{
  _DAT_00779aa8 = &DAT_00779b98;
  _DAT_00779aac = 5;
  return;
}


// ==== 0x68a250 FUN_0068a250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a250(void)

{
  _DAT_00779aa4 = 0x40c90fdb;
  return;
}


// ==== 0x68a260 FUN_0068a260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a260(void)

{
  _DAT_00779aa0 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a280 FUN_0068a280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a280(void)

{
  _DAT_00779a98 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a290 FUN_0068a290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a290(void)

{
  _DAT_00779a90 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a2b0 FUN_0068a2b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2b0(void)

{
  _DAT_00779a7c = 0x40c90fdb;
  return;
}


// ==== 0x68a2c0 FUN_0068a2c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2c0(void)

{
  _DAT_00779a78 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a2e0 FUN_0068a2e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2e0(void)

{
  _DAT_00779a70 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a2f0 FUN_0068a2f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a2f0(void)

{
  _DAT_00779a68 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a310 FUN_0068a310

void FUN_0068a310(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82f0;
  DAT_00779a60 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a60 = DAT_00779a60 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a340 FUN_0068a340

void FUN_0068a340(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82e8;
  DAT_00779a58 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a58 = DAT_00779a58 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a370 FUN_0068a370

void FUN_0068a370(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82e0;
  DAT_00779a88 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a88 = DAT_00779a88 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a3a0 FUN_0068a3a0

void FUN_0068a3a0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82d8;
  DAT_00779a5c = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a5c = DAT_00779a5c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a3d0 FUN_0068a3d0

void FUN_0068a3d0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82d0;
  DAT_00779a64 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a64 = DAT_00779a64 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a400 FUN_0068a400

void FUN_0068a400(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82c8;
  DAT_00779a84 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a84 = DAT_00779a84 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a430 FUN_0068a430

void FUN_0068a430(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82c0;
  DAT_00779a80 = -1;
  uVar2 = 0x42;
  do {
    DAT_00779a80 = DAT_00779a80 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a460 FUN_0068a460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a460(void)

{
  _DAT_00779a54 = 0x40c90fdb;
  return;
}


// ==== 0x68a470 FUN_0068a470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a470(void)

{
  _DAT_00779a50 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a490 FUN_0068a490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a490(void)

{
  _DAT_00779a48 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a4a0 FUN_0068a4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4a0(void)

{
  _DAT_00779a40 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a4c0 FUN_0068a4c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4c0(void)

{
  _DAT_00779a3c = 0x40c90fdb;
  return;
}


// ==== 0x68a4d0 FUN_0068a4d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4d0(void)

{
  _DAT_00779a38 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a4f0 FUN_0068a4f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a4f0(void)

{
  _DAT_00779a30 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a500 FUN_0068a500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a500(void)

{
  _DAT_00779a28 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a520 FUN_0068a520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a520(void)

{
  _DAT_00779a24 = 0x40c90fdb;
  return;
}


// ==== 0x68a530 FUN_0068a530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a530(void)

{
  _DAT_00779a20 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a550 FUN_0068a550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a550(void)

{
  _DAT_00779a18 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a560 FUN_0068a560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a560(void)

{
  _DAT_00779a10 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a580 FUN_0068a580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a580(void)

{
  _DAT_00779a0c = 0x40c90fdb;
  return;
}


// ==== 0x68a590 FUN_0068a590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a590(void)

{
  _DAT_00779a08 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a5b0 FUN_0068a5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5b0(void)

{
  _DAT_00779a00 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a5c0 FUN_0068a5c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5c0(void)

{
  _DAT_007799f8 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a5e0 FUN_0068a5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5e0(void)

{
  _DAT_007799f4 = 0x40c90fdb;
  return;
}


// ==== 0x68a5f0 FUN_0068a5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a5f0(void)

{
  _DAT_007799f0 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a610 FUN_0068a610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a610(void)

{
  _DAT_007799e8 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a620 FUN_0068a620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a620(void)

{
  _DAT_007799e0 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a640 FUN_0068a640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a640(void)

{
  _DAT_007797ec = 0x40c90fdb;
  return;
}


// ==== 0x68a650 FUN_0068a650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a650(void)

{
  _DAT_007797e8 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68a670 FUN_0068a670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a670(void)

{
  _DAT_007797e0 = 0x401921fb54442d18;
  return;
}


// ==== 0x68a680 FUN_0068a680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a680(void)

{
  _DAT_007797d8 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68a6a0 FUN_0068a6a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a6a0(void)

{
  _DAT_007799b0 = 0x904;
  _DAT_007799b4 = 0x907;
  _DAT_007799b8 = 0x906;
  _DAT_007799bc = 0x905;
  _DAT_007799c0 = 0x90e;
  _DAT_007799c4 = 0x91a;
  _DAT_007799c8 = 0x90d;
  _DAT_007799cc = 0x90f;
  return;
}


// ==== 0x68a700 FUN_0068a700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a700(void)

{
  _DAT_00779980 = 0x904;
  _DAT_00779984 = 0x907;
  _DAT_00779988 = 0x906;
  _DAT_0077998c = 0x905;
  _DAT_00779990 = 0x90e;
  _DAT_00779994 = 0x91a;
  _DAT_00779998 = 0x90d;
  _DAT_0077999c = 0x90f;
  return;
}


// ==== 0x68a760 FUN_0068a760

void FUN_0068a760(void)

{
  DAT_007797f4 = 0x904;
  return;
}


// ==== 0x68a770 FUN_0068a770

void FUN_0068a770(void)

{
  DAT_00779958 = 0x922;
  return;
}


// ==== 0x68a780 FUN_0068a780

void FUN_0068a780(void)

{
  DAT_007797d4 = 0x920;
  return;
}


// ==== 0x68a790 FUN_0068a790

void FUN_0068a790(void)

{
  DAT_007797f0 = 0x921;
  return;
}


// ==== 0x68a7a0 FUN_0068a7a0

void FUN_0068a7a0(void)

{
  DAT_00779950 = 0x912;
  return;
}


// ==== 0x68a7b0 FUN_0068a7b0

void FUN_0068a7b0(void)

{
  DAT_0077995c = 0x912;
  return;
}


// ==== 0x68a7c0 FUN_0068a7c0

void FUN_0068a7c0(void)

{
  DAT_007797c8 = 0x912;
  return;
}


// ==== 0x68a7d0 FUN_0068a7d0

void FUN_0068a7d0(void)

{
  DAT_00779954 = 0x916;
  return;
}


// ==== 0x68a7e0 FUN_0068a7e0

void FUN_0068a7e0(void)

{
  DAT_007797cc = 0x912;
  return;
}


// ==== 0x68a7f0 FUN_0068a7f0

void FUN_0068a7f0(void)

{
  DAT_007797d0 = 0x913;
  return;
}


// ==== 0x68a800 FUN_0068a800

void FUN_0068a800(void)

{
  FUN_0047b900();
  _atexit(FUN_00696420);
  return;
}


// ==== 0x68a820 FUN_0068a820

void FUN_0068a820(void)

{
  bList__bList();
  _atexit(FUN_00696430);
  return;
}


// ==== 0x68a840 FUN_0068a840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a840(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0x5a;
  DAT_007799d0 = -1;
  puVar3 = &DAT_006c8240;
  do {
    DAT_007799d0 = DAT_007799d0 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_007799d4 = -1;
  puVar3 = &DAT_006c824c;
  do {
    _DAT_007799d4 = _DAT_007799d4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_007799d8 = -1;
  puVar3 = &DAT_006c8258;
  do {
    _DAT_007799d8 = _DAT_007799d8 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  puVar3 = &DAT_006c8264;
  _DAT_007799dc = -1;
  do {
    _DAT_007799dc = _DAT_007799dc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a8f0 FUN_0068a8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a8f0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0x5a;
  DAT_00779960 = -1;
  puVar3 = &DAT_006c8210;
  do {
    DAT_00779960 = DAT_00779960 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_00779964 = -1;
  puVar3 = &DAT_006c821c;
  do {
    _DAT_00779964 = _DAT_00779964 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_00779968 = -1;
  puVar3 = &DAT_006c8228;
  do {
    _DAT_00779968 = _DAT_00779968 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  puVar3 = &DAT_006c8234;
  _DAT_0077996c = -1;
  do {
    _DAT_0077996c = _DAT_0077996c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68a9a0 FUN_0068a9a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068a9a0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0x5a;
  DAT_007799a0 = -1;
  puVar3 = &DAT_006c81e0;
  do {
    DAT_007799a0 = DAT_007799a0 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_007799a4 = -1;
  puVar3 = &DAT_006c81ec;
  do {
    _DAT_007799a4 = _DAT_007799a4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_007799a8 = -1;
  puVar3 = &DAT_006c81f8;
  do {
    _DAT_007799a8 = _DAT_007799a8 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  puVar3 = &DAT_006c8204;
  _DAT_007799ac = -1;
  do {
    _DAT_007799ac = _DAT_007799ac * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68aa50 FUN_0068aa50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068aa50(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0x5a;
  DAT_00779970 = -1;
  puVar3 = &DAT_006c81b0;
  do {
    DAT_00779970 = DAT_00779970 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_00779974 = -1;
  puVar3 = &DAT_006c81bc;
  do {
    _DAT_00779974 = _DAT_00779974 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  _DAT_00779978 = -1;
  puVar3 = &DAT_006c81c8;
  do {
    _DAT_00779978 = _DAT_00779978 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x5a;
  puVar3 = &DAT_006c81d4;
  _DAT_0077997c = -1;
  do {
    _DAT_0077997c = _DAT_0077997c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68ab00 FUN_0068ab00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab00(void)

{
  _DAT_007797bc = 0x40c90fdb;
  return;
}


// ==== 0x68ab10 FUN_0068ab10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab10(void)

{
  _DAT_007797b8 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68ab30 FUN_0068ab30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab30(void)

{
  _DAT_007797b0 = 0x401921fb54442d18;
  return;
}


// ==== 0x68ab40 FUN_0068ab40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ab40(void)

{
  _DAT_007797a8 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68ab60 StaticInit_Hash_Bip01

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera high (hopper+capstone) docs/re/misc.md */

void StaticInit_Hash_Bip01(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c82f0;
  _DAT_007797a0 = -1;
  uVar2 = 0x42;
  do {
    _DAT_007797a0 = _DAT_007797a0 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68ab90 FUN_0068ab90

void FUN_0068ab90(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_006c81a4;
  DAT_007797c4 = -1;
  uVar2 = 0x52;
  do {
    DAT_007797c4 = DAT_007797c4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68abc0 StaticInit_Hash_SALLY

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera high (hopper+capstone) docs/re/misc.md */

void StaticInit_Hash_SALLY(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "SALLY";
  _DAT_007797c0 = -1;
  uVar2 = 0x53;
  do {
    _DAT_007797c0 = _DAT_007797c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68abf0 FUN_0068abf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068abf0(void)

{
  _DAT_00779794 = 0x40c90fdb;
  return;
}


// ==== 0x68ac00 FUN_0068ac00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac00(void)

{
  _DAT_00779790 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68ac20 FUN_0068ac20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac20(void)

{
  _DAT_00779788 = 0x401921fb54442d18;
  return;
}


// ==== 0x68ac30 FUN_0068ac30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac30(void)

{
  _DAT_00779780 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68ac50 StaticInit_AnimBank_G779798_68ac50

/* [canon] assets med (capstone+refs) docs/re/misc.md */

void StaticInit_AnimBank_G779798_68ac50(void)

{
  bList__bList();
  _atexit(StaticInit_AnimBank_G779798_696440);
  return;
}


// ==== 0x68ac70 FUN_0068ac70

void FUN_0068ac70(void)

{
  DAT_00779720 = 0x2aaa;
  return;
}


// ==== 0x68ac80 FUN_0068ac80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac80(void)

{
  _DAT_0077971c = 0x40c90fdb;
  return;
}


// ==== 0x68ac90 FUN_0068ac90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ac90(void)

{
  _DAT_00779718 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68acb0 FUN_0068acb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068acb0(void)

{
  _DAT_00779710 = 0x401921fb54442d18;
  return;
}


// ==== 0x68acc0 FUN_0068acc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068acc0(void)

{
  _DAT_00779708 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68ace0 FUN_0068ace0

void FUN_0068ace0(void)

{
  bList__bList();
  _atexit(FUN_00696450);
  return;
}


// ==== 0x68ad00 FUN_0068ad00

void FUN_0068ad00(void)

{
  FUN_0047ff30();
  _atexit(FUN_00696460);
  return;
}


// ==== 0x68ad20 FUN_0068ad20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad20(void)

{
  _DAT_007788d4 = 0x40c90fdb;
  return;
}


// ==== 0x68ad30 FUN_0068ad30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad30(void)

{
  _DAT_007788d0 = _K_HALF * 3.1415927;
  return;
}


// ==== 0x68ad50 FUN_0068ad50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad50(void)

{
  _DAT_007788c8 = 0x401921fb54442d18;
  return;
}


// ==== 0x68ad60 FUN_0068ad60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ad60(void)

{
  _DAT_007788c0 = 0x3ff921fb54442d18;
  return;
}


// ==== 0x68ad80 FUN_0068ad80

void FUN_0068ad80(void)

{
  FUN_0048ea30(0xbfc90fdb,0,0x3cf5c28f,0x3dcccccd);
  _atexit(FUN_00696470);
  return;
}


// ==== 0x68adb0 FUN_0068adb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068adb0(void)

{
  _DAT_007788b8 = 0x38e;
  return;
}


// ==== 0x68adc0 FUN_0068adc0

void FUN_0068adc0(void)

{
  DAT_007789e4._0_2_ = 0xbbb;
  return;
}


// ==== 0x68add0 FUN_0068add0

void FUN_0068add0(void)

{
  DAT_007789e0._0_2_ = 0x3555;
  return;
}


// ==== 0x68ade0 FUN_0068ade0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ade0(void)

{
  _DAT_007789e8 = 0x38e;
  return;
}


// ==== 0x68adf0 FUN_0068adf0

void FUN_0068adf0(void)

{
  DAT_007788bc = 0x3555;
  return;
}


// ==== 0x68ae00 FUN_0068ae00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ae00(void)

{
  _DAT_00706788 = DAT_00700b64;
  _DAT_0070678c = 0x3e4ccccd;
  _DAT_00706794 = 0x3d4ccccd;
  _DAT_00706790 = DAT_00700b64 + 0.01;
  return;
}


// ==== 0x68ae40 FUN_0068ae40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ae40(void)

{
  _DAT_0077889c = &DAT_00706780;
  _DAT_007788a0 = 3;
  return;
}


// ==== 0x68ae60 FUN_0068ae60

void FUN_0068ae60(void)

{
  FUN_004a9bc0(&DAT_00748f70);
  _atexit(FUN_00696480);
  return;
}


// ==== 0x68ae80 FUN_0068ae80

void FUN_0068ae80(void)

{
  MiniWorld__MiniWorld(&DAT_00746dd0);
  _atexit(FUN_00696490);
  return;
}


// ==== 0x68aea0 FUN_0068aea0

void FUN_0068aea0(void)

{
  RideInfo__Init();
  return;
}


// ==== 0x68aeb0 FUN_0068aeb0

void FUN_0068aeb0(void)

{
  RideInfo__Init();
  return;
}


// ==== 0x68aec0 FUN_0068aec0

void FUN_0068aec0(void)

{
  bList__bList();
  _atexit(FUN_006964c0);
  return;
}


// ==== 0x68aee0 FUN_0068aee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068aee0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x4b;
  DAT_00746bf8 = -1;
  pcVar3 = "Keyboard.fng";
  do {
    DAT_00746bf8 = DAT_00746bf8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  DAT_00746c14 = -1;
  _DAT_00746bfc = 2;
  _DAT_00746c00 = 3;
  _DAT_00746c04 = 0;
  _DAT_00746c08 = 1;
  _DAT_00746c0c = 0x29;
  _DAT_00746c10 = 0xffffffff;
  pcVar3 = "EA_TRAX_Jukebox.fng";
  do {
    DAT_00746c14 = DAT_00746c14 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746c24 = 1;
  _DAT_00746c30 = -1;
  _DAT_00746c18 = 0x4c;
  _DAT_00746c1c = 0x4c;
  _DAT_00746c20 = 0;
  _DAT_00746c28 = 0x29;
  _DAT_00746c2c = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Alpine.fng";
  do {
    _DAT_00746c30 = _DAT_00746c30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746c4c = -1;
  _DAT_00746c34 = 0x4c;
  _DAT_00746c38 = 0x4c;
  _DAT_00746c3c = 0;
  _DAT_00746c40 = 1;
  _DAT_00746c44 = 0x29;
  _DAT_00746c48 = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Kenwood.fng";
  do {
    _DAT_00746c4c = _DAT_00746c4c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746c68 = -1;
  _DAT_00746c50 = 0x4c;
  _DAT_00746c54 = 0x4c;
  _DAT_00746c58 = 0;
  _DAT_00746c5c = 1;
  _DAT_00746c60 = 0x29;
  _DAT_00746c64 = 0x4d;
  pcVar3 = "EA_TRAX_Jukebox_Audiobahn.fng";
  do {
    _DAT_00746c68 = _DAT_00746c68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746c6c = 0x4c;
  _DAT_00746c70 = 0x4c;
  _DAT_00746c80 = 0x4d;
  _DAT_00746c7c = 0x29;
  _DAT_00746c74 = 0;
  _DAT_00746c78 = 1;
  pcVar3 = "LS_Splash.fng";
  _DAT_00746c84 = -1;
  do {
    _DAT_00746c84 = _DAT_00746c84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746c88 = 0xffffffff;
  _DAT_00746c8c = 0xffffffff;
  _DAT_00746c90 = 0xffffffff;
  _DAT_00746c94 = 0xffffffff;
  _DAT_00746c9c = 0xffffffff;
  _DAT_00746c98 = 0x27;
  return;
}


// ==== 0x68b0f0 FUN_0068b0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068b0f0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x43;
  DAT_00746a98 = -1;
  pcVar3 = "ColorPicker.fng";
  do {
    DAT_00746a98 = DAT_00746a98 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  DAT_00746a9c = -1;
  pcVar3 = "Credits.fng";
  do {
    DAT_00746a9c = DAT_00746a9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746aa0 = -1;
  pcVar3 = "EA_TRAX_Jukebox.fng";
  do {
    _DAT_00746aa0 = _DAT_00746aa0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746aa4 = -1;
  pcVar3 = "EA_TRAX_Jukebox_Alpine.fng";
  do {
    _DAT_00746aa4 = _DAT_00746aa4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746aa8 = -1;
  pcVar3 = "EA_TRAX_Jukebox_Audiobahn.fng";
  do {
    _DAT_00746aa8 = _DAT_00746aa8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_00746aac = -1;
  pcVar3 = "EA_TRAX_Jukebox_Kenwood.fng";
  do {
    _DAT_00746aac = _DAT_00746aac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "GenericDialog.fng";
  _DAT_00746ab0 = -1;
  uVar2 = 0x47;
  do {
    _DAT_00746ab0 = _DAT_00746ab0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  pcVar3 = "LS_DemoLegal.fng";
  _DAT_00746ab4 = -1;
  do {
    _DAT_00746ab4 = _DAT_00746ab4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746ab8 = -1;
  pcVar3 = "LS_Disclaimer.fng";
  do {
    _DAT_00746ab8 = _DAT_00746ab8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746abc = -1;
  pcVar3 = "LS_EAlogo.fng";
  do {
    _DAT_00746abc = _DAT_00746abc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "LS_IntroFMV.fng";
  _DAT_00746ac0 = -1;
  uVar2 = 0x4c;
  do {
    _DAT_00746ac0 = _DAT_00746ac0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  pcVar3 = "LS_LangSelect.fng";
  _DAT_00746ac4 = -1;
  do {
    _DAT_00746ac4 = _DAT_00746ac4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746ac8 = -1;
  pcVar3 = "LS_License.fng";
  do {
    _DAT_00746ac8 = _DAT_00746ac8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746acc = -1;
  pcVar3 = "LS_Splash.fng";
  do {
    _DAT_00746acc = _DAT_00746acc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4c;
  _DAT_00746ad0 = -1;
  pcVar3 = "LS_THXMovie.fng";
  do {
    _DAT_00746ad0 = _DAT_00746ad0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ad4 = -1;
  pcVar3 = "MU_DebugPresetEditor.fng";
  do {
    _DAT_00746ad4 = _DAT_00746ad4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ad8 = -1;
  pcVar3 = "MU_DemoCustomBlurb.fng";
  do {
    _DAT_00746ad8 = _DAT_00746ad8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746adc = -1;
  pcVar3 = "MU_GarageAudioCategory.fng";
  do {
    _DAT_00746adc = _DAT_00746adc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ae0 = -1;
  pcVar3 = "MU_GaragePresets.fng";
  do {
    _DAT_00746ae0 = _DAT_00746ae0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ae4 = -1;
  pcVar3 = "MU_GarageVinylPrompt.fng";
  do {
    _DAT_00746ae4 = _DAT_00746ae4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_HorizontalBrowserBack.fng";
  _DAT_00746ae8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746ae8 = _DAT_00746ae8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Main.fng";
  _DAT_00746aec = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746aec = _DAT_00746aec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Main_PC.fng";
  _DAT_00746af0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746af0 = _DAT_00746af0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_MPLogin.fng";
  _DAT_00746af4 = -1;
  do {
    _DAT_00746af4 = _DAT_00746af4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746af8 = -1;
  pcVar3 = "MU_MultiTrackConfirm.fng";
  do {
    _DAT_00746af8 = _DAT_00746af8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746afc = -1;
  pcVar3 = "MU_Online_AnotherAccount.fng";
  do {
    _DAT_00746afc = _DAT_00746afc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b00 = -1;
  pcVar3 = "MU_Online_AuthenticateDNAS.fng";
  do {
    _DAT_00746b00 = _DAT_00746b00 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b04 = -1;
  pcVar3 = "MU_Online_BestLapTimes.fng";
  do {
    _DAT_00746b04 = _DAT_00746b04 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b08 = -1;
  pcVar3 = "MU_Online_CreateAccount.fng";
  do {
    _DAT_00746b08 = _DAT_00746b08 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b0c = -1;
  pcVar3 = "MU_Online_CreateAccount_StepOne_PC.fng";
  do {
    _DAT_00746b0c = _DAT_00746b0c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b10 = -1;
  pcVar3 = "MU_Online_CreateAccount_StepTwo.fng";
  do {
    _DAT_00746b10 = _DAT_00746b10 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b14 = -1;
  pcVar3 = "MU_OnlineDialogBox.fng";
  do {
    _DAT_00746b14 = _DAT_00746b14 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b18 = -1;
  pcVar3 = "MU_Online_ISPConnect.fng";
  do {
    _DAT_00746b18 = _DAT_00746b18 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Online_NetworkLogin.fng";
  _DAT_00746b1c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b1c = _DAT_00746b1c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_Online_NetworkSelect.fng";
  _DAT_00746b20 = -1;
  do {
    _DAT_00746b20 = _DAT_00746b20 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b24 = -1;
  pcVar3 = "MU_Online_News.fng";
  do {
    _DAT_00746b24 = _DAT_00746b24 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b28 = -1;
  pcVar3 = "MU_Online_ParentalEmailRequired_PC.fng";
  do {
    _DAT_00746b28 = _DAT_00746b28 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b2c = -1;
  pcVar3 = "MU_Online_PlayerLogin.fng";
  do {
    _DAT_00746b2c = _DAT_00746b2c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b30 = -1;
  pcVar3 = "MU_Online_RankingsBoard.fng";
  do {
    _DAT_00746b30 = _DAT_00746b30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b34 = -1;
  pcVar3 = "MU_Online_RankingSelect.fng";
  do {
    _DAT_00746b34 = _DAT_00746b34 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b38 = -1;
  pcVar3 = "MU_Online_TooYoung.fng";
  do {
    _DAT_00746b38 = _DAT_00746b38 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b3c = -1;
  pcVar3 = "MU_Online_WarningDialog.fng";
  do {
    _DAT_00746b3c = _DAT_00746b3c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b40 = -1;
  pcVar3 = "MU_Online4PlayerGameDialogueBox.fng";
  do {
    _DAT_00746b40 = _DAT_00746b40 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b44 = -1;
  pcVar3 = "MU_OnlineGameModeSelect.fng";
  do {
    _DAT_00746b44 = _DAT_00746b44 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b48 = -1;
  pcVar3 = "MU_OnlineGameRoom.fng";
  do {
    _DAT_00746b48 = _DAT_00746b48 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b4c = -1;
  pcVar3 = "MU_OnlineGameRoomChallenge.fng";
  do {
    _DAT_00746b4c = _DAT_00746b4c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b50 = -1;
  pcVar3 = "MU_OnlineGameRoomCreateGame.fng";
  do {
    _DAT_00746b50 = _DAT_00746b50 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b54 = -1;
  pcVar3 = "MU_OnlineGamesRoomDialog.fng";
  do {
    _DAT_00746b54 = _DAT_00746b54 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b58 = -1;
  pcVar3 = "MU_OnlineGenericDialogueBox.fng";
  do {
    _DAT_00746b58 = _DAT_00746b58 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_OnlineMenu.fng";
  _DAT_00746b5c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b5c = _DAT_00746b5c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_OnlineWaiting.fng";
  _DAT_00746b60 = -1;
  do {
    _DAT_00746b60 = _DAT_00746b60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b64 = -1;
  pcVar3 = "MU_OnlineNews.fng";
  do {
    _DAT_00746b64 = _DAT_00746b64 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b68 = -1;
  pcVar3 = "MU_OnlinePlayerDetails.fng";
  do {
    _DAT_00746b68 = _DAT_00746b68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b6c = -1;
  pcVar3 = "MU_OnlineMembership.fng";
  do {
    _DAT_00746b6c = _DAT_00746b6c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b70 = -1;
  pcVar3 = "MU_OnlineRankedGameSelect.fng";
  do {
    _DAT_00746b70 = _DAT_00746b70 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b74 = -1;
  pcVar3 = "MU_Options.fng";
  do {
    _DAT_00746b74 = _DAT_00746b74 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Options_PC.fng";
  _DAT_00746b78 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b78 = _DAT_00746b78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_OptionsController.fng";
  _DAT_00746b7c = -1;
  do {
    _DAT_00746b7c = _DAT_00746b7c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b80 = -1;
  pcVar3 = "MU_OptionsHUD.fng";
  do {
    _DAT_00746b80 = _DAT_00746b80 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_OptionsSelector_PC.fng";
  _DAT_00746b84 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b84 = _DAT_00746b84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_Pause.fng";
  _DAT_00746b88 = -1;
  do {
    _DAT_00746b88 = _DAT_00746b88 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b8c = -1;
  pcVar3 = "MU_PauseOptions.fng";
  do {
    _DAT_00746b8c = _DAT_00746b8c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_PauseOptionsSelector.fng";
  _DAT_00746b90 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b90 = _DAT_00746b90 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_PlayerLogin.fng";
  _DAT_00746b94 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746b94 = _DAT_00746b94 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_QRTransmissionSelect.fng";
  _DAT_00746b98 = -1;
  do {
    _DAT_00746b98 = _DAT_00746b98 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746b9c = -1;
  pcVar3 = "MU_QuickRaceLapPopup.fng";
  do {
    _DAT_00746b9c = _DAT_00746b9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_QuickRaceModeSelect.fng";
  _DAT_00746ba0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746ba0 = _DAT_00746ba0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_QuickRaceOptions.fng";
  _DAT_00746ba4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746ba4 = _DAT_00746ba4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_QuickRaceOptions_PC.fng";
  _DAT_00746ba8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746ba8 = _DAT_00746ba8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_QuickRaceTrackSelect.fng";
  _DAT_00746bac = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bac = _DAT_00746bac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_ScreenPos.fng";
  _DAT_00746bb0 = -1;
  do {
    _DAT_00746bb0 = _DAT_00746bb0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746bb4 = -1;
  pcVar3 = "MU_Tutorial.fng";
  do {
    _DAT_00746bb4 = _DAT_00746bb4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_UG_EventBriefing.fng";
  _DAT_00746bb8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bb8 = _DAT_00746bb8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_UG_MagazineScreen.fng";
  _DAT_00746bbc = -1;
  do {
    _DAT_00746bbc = _DAT_00746bbc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_UG_MapScreen.fng";
  _DAT_00746bc0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bc0 = _DAT_00746bc0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_UG_NewOrLoad.fng";
  _DAT_00746bc4 = -1;
  do {
    _DAT_00746bc4 = _DAT_00746bc4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746bc8 = -1;
  pcVar3 = "MU_UG_RankScreen.fng";
  do {
    _DAT_00746bc8 = _DAT_00746bc8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_UG_StatsScreen.fng";
  _DAT_00746bcc = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bcc = _DAT_00746bcc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_UG_StatusMenu.fng";
  _DAT_00746bd0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bd0 = _DAT_00746bd0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_UG_TheatreScreen.fng";
  _DAT_00746bd4 = -1;
  do {
    _DAT_00746bd4 = _DAT_00746bd4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_UG_UndergroundMenu.fng";
  _DAT_00746bd8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746bd8 = _DAT_00746bd8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "PC_customize_graphics.fng";
  _DAT_00746bdc = -1;
  uVar2 = 0x50;
  do {
    _DAT_00746bdc = _DAT_00746bdc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "PC_graphics.fng";
  _DAT_00746be0 = -1;
  uVar2 = 0x50;
  do {
    _DAT_00746be0 = _DAT_00746be0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00746be4 = -1;
  pcVar3 = "PC_Joypad_Config.fng";
  do {
    _DAT_00746be4 = _DAT_00746be4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00746be8 = -1;
  pcVar3 = "PC_Keyboard_Config.fng";
  do {
    _DAT_00746be8 = _DAT_00746be8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00746bec = -1;
  pcVar3 = "PC_LoadSave.fng";
  do {
    _DAT_00746bec = _DAT_00746bec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00746bf0 = -1;
  pcVar3 = "PC_Wheel_Config.fng";
  do {
    _DAT_00746bf0 = _DAT_00746bf0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "PostRaceMenu.fng";
  _DAT_00746bf4 = -1;
  uVar2 = 0x50;
  do {
    _DAT_00746bf4 = _DAT_00746bf4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68be70 FUN_0068be70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068be70(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "GarageMain.fng";
  DAT_00746ca0 = -1;
  uVar2 = 0x47;
  do {
    DAT_00746ca0 = DAT_00746ca0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "GarageMain_2P.fng";
  DAT_00746ca4 = -1;
  uVar2 = 0x47;
  do {
    DAT_00746ca4 = DAT_00746ca4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Garage.fng";
  _DAT_00746ca8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746ca8 = _DAT_00746ca8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_GarageAccessoriesCategory.fng";
  _DAT_00746cac = -1;
  do {
    _DAT_00746cac = _DAT_00746cac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cb0 = -1;
  pcVar3 = "MU_GarageDecals.fng";
  do {
    _DAT_00746cb0 = _DAT_00746cb0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cb4 = -1;
  pcVar3 = "MU_GarageDecals_Brand.fng";
  do {
    _DAT_00746cb4 = _DAT_00746cb4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cb8 = -1;
  pcVar3 = "MU_GarageDecals_ChooseDecal.fng";
  do {
    _DAT_00746cb8 = _DAT_00746cb8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cbc = -1;
  pcVar3 = "MU_GarageDecals_Size.fng";
  do {
    _DAT_00746cbc = _DAT_00746cbc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cc0 = -1;
  pcVar3 = "MU_GarageDecals_Slot.fng";
  do {
    _DAT_00746cc0 = _DAT_00746cc0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cc4 = -1;
  pcVar3 = "MU_GarageDecals_Zone.fng";
  do {
    _DAT_00746cc4 = _DAT_00746cc4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cc8 = -1;
  pcVar3 = "MU_GarageMenu.fng";
  do {
    _DAT_00746cc8 = _DAT_00746cc8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ccc = -1;
  pcVar3 = "MU_GaragePaintMod.fng";
  do {
    _DAT_00746ccc = _DAT_00746ccc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cd0 = -1;
  pcVar3 = "MU_GaragePartsBrowser.fng";
  do {
    _DAT_00746cd0 = _DAT_00746cd0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cd4 = -1;
  pcVar3 = "MU_GaragePartsCategory.fng";
  do {
    _DAT_00746cd4 = _DAT_00746cd4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cd8 = -1;
  pcVar3 = "MU_GaragePartsCategoryVisual.fng";
  do {
    _DAT_00746cd8 = _DAT_00746cd8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cdc = -1;
  pcVar3 = "MU_GaragePartsChooseVisual.fng";
  do {
    _DAT_00746cdc = _DAT_00746cdc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ce0 = -1;
  pcVar3 = "MU_GaragePerformanceBrand.fng";
  do {
    _DAT_00746ce0 = _DAT_00746ce0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ce4 = -1;
  pcVar3 = "MU_GaragePerformanceTuner.fng";
  do {
    _DAT_00746ce4 = _DAT_00746ce4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746ce8 = -1;
  pcVar3 = "MU_GaragePerformanceV2.fng";
  do {
    _DAT_00746ce8 = _DAT_00746ce8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cec = -1;
  pcVar3 = "MU_GarageRimsBrandBrowser.fng";
  do {
    _DAT_00746cec = _DAT_00746cec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cf0 = -1;
  pcVar3 = "MU_GarageRimsBrowser.fng";
  do {
    _DAT_00746cf0 = _DAT_00746cf0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746cf4 = -1;
  pcVar3 = "MU_GarageRimsStyleBrowser.fng";
  uVar2 = 0x4d;
  do {
    _DAT_00746cf4 = _DAT_00746cf4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cf8 = -1;
  pcVar3 = "MU_GarageVinylBrand.fng";
  do {
    _DAT_00746cf8 = _DAT_00746cf8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746cfc = -1;
  pcVar3 = "MU_GarageVinylBrowser.fng";
  do {
    _DAT_00746cfc = _DAT_00746cfc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d00 = -1;
  pcVar3 = "MU_GarageVinylGroup.fng";
  do {
    _DAT_00746d00 = _DAT_00746d00 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d04 = -1;
  pcVar3 = "MU_GarageVinylLayerV2.fng";
  do {
    _DAT_00746d04 = _DAT_00746d04 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d08 = -1;
  pcVar3 = "MU_MainMenuCarCustomize.fng";
  do {
    _DAT_00746d08 = _DAT_00746d08 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746d0c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746d0c = _DAT_00746d0c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_QuickRaceCarSelect.fng";
  _DAT_00746d10 = -1;
  do {
    _DAT_00746d10 = _DAT_00746d10 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d14 = -1;
  pcVar3 = "MU_QuickRaceLapPopup_PC.fng";
  do {
    _DAT_00746d14 = _DAT_00746d14 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d18 = -1;
  pcVar3 = "MU_GarageAudioCategory.fng";
  do {
    _DAT_00746d18 = _DAT_00746d18 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d1c = -1;
  pcVar3 = "MU_GaragePartsCategoryVisual.fng";
  do {
    _DAT_00746d1c = _DAT_00746d1c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746d20 = -1;
  pcVar3 = "MU_GarageRimsStyleBrowser.fng";
  uVar2 = 0x4d;
  do {
    _DAT_00746d20 = _DAT_00746d20 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d24 = -1;
  pcVar3 = "MU_GarageRimsBrowser.fng";
  do {
    _DAT_00746d24 = _DAT_00746d24 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d28 = -1;
  pcVar3 = "MU_GaragePaintMod.fng";
  do {
    _DAT_00746d28 = _DAT_00746d28 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d2c = -1;
  pcVar3 = "MU_GarageVinylBrand.fng";
  do {
    _DAT_00746d2c = _DAT_00746d2c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d30 = -1;
  pcVar3 = "MU_GarageVinylGroup.fng";
  do {
    _DAT_00746d30 = _DAT_00746d30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d34 = -1;
  pcVar3 = "MU_GarageVinylType.fng";
  do {
    _DAT_00746d34 = _DAT_00746d34 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d38 = -1;
  pcVar3 = "MU_GarageVinylBrowser.fng";
  do {
    _DAT_00746d38 = _DAT_00746d38 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d3c = -1;
  pcVar3 = "MU_GarageDecals.fng";
  do {
    _DAT_00746d3c = _DAT_00746d3c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d40 = -1;
  pcVar3 = "MU_GaragePartsCategory.fng";
  do {
    _DAT_00746d40 = _DAT_00746d40 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d44 = -1;
  pcVar3 = "MU_GaragePartsChooseVisual.fng";
  do {
    _DAT_00746d44 = _DAT_00746d44 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d48 = -1;
  pcVar3 = "MU_GarageVinylLayerV2.fng";
  do {
    _DAT_00746d48 = _DAT_00746d48 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d4c = -1;
  pcVar3 = "MU_GarageDecals_Zone.fng";
  do {
    _DAT_00746d4c = _DAT_00746d4c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d50 = -1;
  pcVar3 = "MU_GarageDecals_Size.fng";
  do {
    _DAT_00746d50 = _DAT_00746d50 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d54 = -1;
  pcVar3 = "MU_GarageDecals_Slot.fng";
  do {
    _DAT_00746d54 = _DAT_00746d54 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d58 = -1;
  pcVar3 = "MU_GarageDecals_Brand.fng";
  do {
    _DAT_00746d58 = _DAT_00746d58 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d5c = -1;
  pcVar3 = "MU_GarageDecals_ChooseDecal.fng";
  do {
    _DAT_00746d5c = _DAT_00746d5c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d60 = -1;
  pcVar3 = "MU_GarageAccessoriesCategory.fng";
  do {
    _DAT_00746d60 = _DAT_00746d60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "GarageMain.fng";
  _DAT_00746d64 = -1;
  uVar2 = 0x47;
  do {
    _DAT_00746d64 = _DAT_00746d64 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "GarageMain_2P.fng";
  _DAT_00746d68 = -1;
  uVar2 = 0x47;
  do {
    _DAT_00746d68 = _DAT_00746d68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_Garage.fng";
  _DAT_00746d6c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746d6c = _DAT_00746d6c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_GarageMenu.fng";
  _DAT_00746d70 = -1;
  do {
    _DAT_00746d70 = _DAT_00746d70 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d74 = -1;
  pcVar3 = "MU_GaragePartsBrowser.fng";
  do {
    _DAT_00746d74 = _DAT_00746d74 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d78 = -1;
  pcVar3 = "MU_GarageRimsBrandBrowser.fng";
  do {
    _DAT_00746d78 = _DAT_00746d78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d7c = -1;
  pcVar3 = "MU_GaragePerformanceTuner.fng";
  do {
    _DAT_00746d7c = _DAT_00746d7c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d80 = -1;
  pcVar3 = "MU_GaragePerformanceBrand.fng";
  do {
    _DAT_00746d80 = _DAT_00746d80 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d84 = -1;
  pcVar3 = "MU_GaragePerformanceV2.fng";
  do {
    _DAT_00746d84 = _DAT_00746d84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746d88 = -1;
  pcVar3 = "MU_QRTransmissionSelect.fng";
  do {
    _DAT_00746d88 = _DAT_00746d88 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_GaragePerformanceCategory.fng";
  _DAT_00746d8c = -1;
  do {
    _DAT_00746d8c = _DAT_00746d8c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c7c0 FUN_0068c7c0

void FUN_0068c7c0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "GenericDialog.fng";
  DAT_007469bc = -1;
  uVar2 = 0x47;
  do {
    DAT_007469bc = DAT_007469bc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c7f0 FUN_0068c7f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c7f0(void)

{
  _DAT_00746a88 = 0xffffffff;
  return;
}


// ==== 0x68c800 FUN_0068c800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c800(void)

{
  _DAT_007469b0 = 0xffffffff;
  return;
}


// ==== 0x68c810 FUN_0068c810

void FUN_0068c810(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x4d;
  DAT_007469b4 = -1;
  pcVar3 = "MU_GaragePerformanceCategory.fng";
  do {
    DAT_007469b4 = DAT_007469b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_GaragePartsChooseVisual.fng";
  DAT_007469b8 = -1;
  do {
    DAT_007469b8 = DAT_007469b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c870 FUN_0068c870

void FUN_0068c870(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x43;
  DAT_00746dcc = -1;
  pcVar3 = "ColorPicker.fng";
  do {
    DAT_00746dcc = DAT_00746dcc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c8a0 FUN_0068c8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c8a0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  DAT_00746db4 = -1;
  pcVar3 = "MU_UG_ChooseCareerCar.fng";
  uVar2 = 0x4d;
  do {
    DAT_00746db4 = DAT_00746db4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  DAT_00746db8 = -1;
  pcVar3 = "MU_MainMenuCarCustomize.fng";
  do {
    DAT_00746db8 = DAT_00746db8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746dbc = -1;
  pcVar3 = "MU_QuickRaceCarSelect.fng";
  do {
    _DAT_00746dbc = _DAT_00746dbc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746dc0 = -1;
  pcVar3 = "MU_QuickRaceLapPopup_PC.fng";
  do {
    _DAT_00746dc0 = _DAT_00746dc0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746dc4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746dc4 = _DAT_00746dc4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746dc8 = -1;
  pcVar3 = "MU_UG_ChooseCareerCar.fng";
  uVar2 = 0x4d;
  do {
    _DAT_00746dc8 = _DAT_00746dc8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c900 FUN_0068c900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0068c900(byte param_1)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  byte unaff_BL;
  bool in_ZF;
  
  pcVar3 = "MU_QuickRaceCarSelect.fng";
  if (!in_ZF) {
    do {
      in_EAX = in_EAX * 0x21 + (uint)param_1;
      param_1 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (param_1 != 0);
  }
  uVar2 = 0x4d;
  _DAT_00746dbc = in_EAX;
  _DAT_00746dc0 = -1;
  pcVar3 = "MU_QuickRaceLapPopup_PC.fng";
  do {
    _DAT_00746dc0 = _DAT_00746dc0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "MU_MultiplayerCarSelect.fng";
  _DAT_00746dc4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00746dc4 = _DAT_00746dc4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746dc8 = -1;
  pcVar3 = "MU_UG_ChooseCareerCar.fng";
  while (unaff_BL != 0) {
    _DAT_00746dc8 = _DAT_00746dc8 * 0x21 + (uint)unaff_BL;
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + 1;
    unaff_BL = *pbVar1;
  }
  return;
}


// ==== 0x68c990 FUN_0068c990

void FUN_0068c990(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x4d;
  DAT_00746a8c = -1;
  pcVar3 = "MU_GaragePerformanceTuner.fng";
  do {
    DAT_00746a8c = DAT_00746a8c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_UG_ChooseCareerCar.fng";
  DAT_00746a90 = -1;
  do {
    DAT_00746a90 = DAT_00746a90 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68c9f0 FUN_0068c9f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c9f0(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar3 = 0x4d;
  DAT_007469c0 = -1;
  pcVar5 = "MU_GarageAccessoriesCategory.fng";
  do {
    DAT_007469c0 = DAT_007469c0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  DAT_007469c8 = -1;
  _DAT_007469c4 = 1;
  pcVar5 = "MU_GarageRimsBrandBrowser.fng";
  do {
    DAT_007469c8 = DAT_007469c8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_007469d0 = -1;
  DAT_007469cc = 2;
  pcVar5 = "MU_GaragePartsCategoryVisual.fng";
  do {
    _DAT_007469d0 = _DAT_007469d0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_007469d8 = -1;
  _DAT_007469d4 = 4;
  pcVar5 = "MU_GaragePaintMod.fng";
  do {
    _DAT_007469d8 = _DAT_007469d8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_007469e0 = -1;
  _DAT_007469dc = 8;
  pcVar5 = "MU_GarageVinylLayerV2.fng";
  do {
    _DAT_007469e0 = _DAT_007469e0 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_007469e8 = -1;
  _DAT_007469e4 = 0x10;
  pcVar5 = "MU_GarageDecals_Zone.fng";
  do {
    _DAT_007469e8 = _DAT_007469e8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_007469ec = 0x20;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  _DAT_007469f0 = -1;
  uVar6 = 0x4d;
  do {
    _DAT_007469f0 = _DAT_007469f0 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_007469f8 = -1;
  bVar2 = 0x4d;
  _DAT_007469f4 = 0x40;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  bVar4 = bVar2;
  do {
    _DAT_007469f8 = _DAT_007469f8 * 0x21 + (uint)bVar4;
    bVar4 = pcVar5[1];
    pcVar5 = pcVar5 + 1;
  } while (bVar4 != 0);
  _DAT_00746a00 = -1;
  _DAT_007469fc = 0x80;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  uVar6 = 0x4d;
  do {
    _DAT_00746a00 = _DAT_00746a00 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a08 = -1;
  _DAT_00746a04 = 0x100;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  do {
    _DAT_00746a08 = _DAT_00746a08 * 0x21 + (uint)bVar2;
    bVar2 = pcVar5[1];
    pcVar5 = pcVar5 + 1;
  } while (bVar2 != 0);
  _DAT_00746a10 = -1;
  _DAT_00746a0c = 0x200;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  uVar6 = 0x4d;
  do {
    _DAT_00746a10 = _DAT_00746a10 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a18 = -1;
  _DAT_00746a14 = 0x400;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  uVar6 = 0x4d;
  do {
    _DAT_00746a18 = _DAT_00746a18 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a20 = -1;
  _DAT_00746a1c = 0x800;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  uVar6 = 0x4d;
  do {
    _DAT_00746a20 = _DAT_00746a20 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a28 = -1;
  _DAT_00746a24 = 0x1000;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  uVar6 = 0x4d;
  do {
    _DAT_00746a28 = _DAT_00746a28 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a30 = -1;
  _DAT_00746a2c = 0x2000;
  pcVar5 = "MU_GaragePerformanceTuner.fng";
  do {
    _DAT_00746a30 = _DAT_00746a30 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a34 = 0x4000;
  pcVar5 = "MU_Garage.fng";
  _DAT_00746a38 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746a38 = _DAT_00746a38 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a3c = 0x8000;
  pcVar5 = "MU_UG_MagazineScreen.fng";
  _DAT_00746a40 = -1;
  do {
    _DAT_00746a40 = _DAT_00746a40 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a44 = 0x10000;
  pcVar5 = "MU_UG_MapScreen.fng";
  _DAT_00746a48 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746a48 = _DAT_00746a48 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a4c = 0x20000;
  pcVar5 = "MU_GaragePerformanceCategory.fng";
  _DAT_00746a50 = -1;
  do {
    _DAT_00746a50 = _DAT_00746a50 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a58 = -1;
  _DAT_00746a54 = 0x40000;
  pcVar5 = "MU_UG_RankScreen.fng";
  do {
    _DAT_00746a58 = _DAT_00746a58 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a5c = 0x80000;
  pcVar5 = "MU_UG_StatsScreen.fng";
  _DAT_00746a60 = -1;
  uVar3 = 0x4d;
  do {
    _DAT_00746a60 = _DAT_00746a60 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a64 = 0x100000;
  pcVar5 = "MU_UG_ChooseCareerCar.fng";
  _DAT_00746a68 = -1;
  uVar6 = 0x4d;
  do {
    _DAT_00746a68 = _DAT_00746a68 * 0x21 + uVar6;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar6 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a70 = -1;
  _DAT_00746a6c = 0x200000;
  pcVar5 = "MU_UG_ChooseCareerCar.fng";
  do {
    _DAT_00746a70 = _DAT_00746a70 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a78 = -1;
  _DAT_00746a74 = 0x400000;
  pcVar5 = "MU_GaragePartsChooseVisual.fng";
  do {
    _DAT_00746a78 = _DAT_00746a78 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  uVar3 = 0x4d;
  _DAT_00746a7c = 0x800000;
  pcVar5 = "MU_UG_TradeCareerCar.fng";
  _DAT_00746a80 = -1;
  do {
    _DAT_00746a80 = _DAT_00746a80 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746a84 = 0x1000000;
  return;
}


// ==== 0x68cec0 FUN_0068cec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068cec0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x32;
  DAT_00746d90 = -1;
  pcVar3 = "2CarImportDialogBot.fng";
  do {
    DAT_00746d90 = DAT_00746d90 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x32;
  DAT_00746d94 = -1;
  pcVar3 = "2CarImportDialogTop.fng";
  do {
    DAT_00746d94 = DAT_00746d94 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  pcVar3 = "GenericDialog.fng";
  _DAT_00746d98 = -1;
  uVar2 = 0x47;
  do {
    _DAT_00746d98 = _DAT_00746d98 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_Online_WarningDialog.fng";
  _DAT_00746d9c = -1;
  do {
    _DAT_00746d9c = _DAT_00746d9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746da0 = -1;
  pcVar3 = "MU_Online4PlayerGameDialogueBox.fng";
  do {
    _DAT_00746da0 = _DAT_00746da0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746da4 = -1;
  pcVar3 = "MU_OnlineChallengSettingsDialogueBox.fng";
  do {
    _DAT_00746da4 = _DAT_00746da4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746da8 = -1;
  pcVar3 = "MU_OnlineGamesRoomDialog.fng";
  do {
    _DAT_00746da8 = _DAT_00746da8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00746dac = -1;
  pcVar3 = "MU_OnlineGenericDialogueBox.fng";
  do {
    _DAT_00746dac = _DAT_00746dac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  pcVar3 = "MU_UG_TradeCarConfirm.fng";
  _DAT_00746db0 = -1;
  do {
    _DAT_00746db0 = _DAT_00746db0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68d030 FUN_0068d030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d030(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  uVar2 = 0x47;
  _DAT_00746974 = -1;
  pcVar3 = "GLOSS";
  do {
    _DAT_00746974 = _DAT_00746974 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_0074697c = -1;
  _DAT_00746978 = 1;
  pcVar3 = "METAL";
  do {
    _DAT_0074697c = _DAT_0074697c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00746984 = -1;
  _DAT_00746980 = 2;
  pcVar3 = "PEARL";
  do {
    _DAT_00746984 = _DAT_00746984 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_0074698c = -1;
  _DAT_00746988 = 3;
  pcVar3 = "CALIPER";
  do {
    _DAT_0074698c = _DAT_0074698c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_00746994 = -1;
  _DAT_00746990 = 4;
  puVar4 = &DAT_006c3cf8;
  do {
    _DAT_00746994 = _DAT_00746994 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x52;
  _DAT_0074699c = -1;
  _DAT_00746998 = 5;
  puVar4 = &DAT_006c3d00;
  do {
    _DAT_0074699c = _DAT_0074699c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_007469a4 = -1;
  _DAT_007469a0 = 6;
  pcVar3 = "MUFFLER";
  do {
    _DAT_007469a4 = _DAT_007469a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_007469a8 = 7;
  puVar4 = &DAT_006c3d0c;
  _DAT_007469ac = -1;
  do {
    _DAT_007469ac = _DAT_007469ac * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68d1c0 FUN_0068d1c0

void FUN_0068d1c0(void)

{
  _atexit(FUN_006964d0);
  return;
}


// ==== 0x68d1d0 FUN_0068d1d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d1d0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x56;
  _DAT_00746918 = -1;
  pcVar3 = "VINYL_GROUP_TEAR";
  do {
    _DAT_00746918 = _DAT_00746918 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074691c = -1;
  pcVar3 = "VINYL_GROUP_TEAR_HOOD";
  do {
    _DAT_0074691c = _DAT_0074691c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746920 = -1;
  pcVar3 = "VINYL_GROUP_STRIPES";
  do {
    _DAT_00746920 = _DAT_00746920 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746924 = -1;
  pcVar3 = "VINYL_GROUP_STRIPES_HOOD";
  do {
    _DAT_00746924 = _DAT_00746924 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746928 = -1;
  pcVar3 = "VINYL_GROUP_SPLASH";
  do {
    _DAT_00746928 = _DAT_00746928 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074692c = -1;
  pcVar3 = "VINYL_GROUP_MODERN";
  do {
    _DAT_0074692c = _DAT_0074692c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746930 = -1;
  pcVar3 = "VINYL_GROUP_MODERN_HOOD";
  do {
    _DAT_00746930 = _DAT_00746930 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746934 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES";
  do {
    _DAT_00746934 = _DAT_00746934 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746938 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES_HOOD";
  do {
    _DAT_00746938 = _DAT_00746938 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074693c = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING";
  do {
    _DAT_0074693c = _DAT_0074693c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746940 = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING_HOOD";
  do {
    _DAT_00746940 = _DAT_00746940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746944 = -1;
  pcVar3 = "VINYL_GROUP_FLAGS";
  do {
    _DAT_00746944 = _DAT_00746944 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746948 = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL";
  do {
    _DAT_00746948 = _DAT_00746948 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074694c = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL_HOOD";
  do {
    _DAT_0074694c = _DAT_0074694c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746950 = -1;
  pcVar3 = "VINYL_GROUP_WILD";
  do {
    _DAT_00746950 = _DAT_00746950 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  DAT_00746954 = -1;
  pcVar3 = "VINYL_GROUP_UNIQUES";
  do {
    DAT_00746954 = DAT_00746954 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746958 = -1;
  pcVar3 = "VINYL_GROUP_AEM";
  do {
    _DAT_00746958 = _DAT_00746958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074695c = -1;
  pcVar3 = "VINYL_GROUP_BODY_VINYL";
  do {
    _DAT_0074695c = _DAT_0074695c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  pcVar3 = "VINYL_GROUP_MANUFACTURAR_LOGO";
  _DAT_00746960 = -1;
  do {
    _DAT_00746960 = _DAT_00746960 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68d300 FUN_0068d300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0068d300(byte param_1,int param_2)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  uVar2 = 0x56;
  _DAT_00746934 = in_EAX;
  _DAT_00746938 = -1;
  pcVar3 = "VINYL_GROUP_FLAMES_HOOD";
  do {
    _DAT_00746938 = _DAT_00746938 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074693c = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING";
  do {
    _DAT_0074693c = _DAT_0074693c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746940 = -1;
  pcVar3 = "VINYL_GROUP_LIGHTNING_HOOD";
  do {
    _DAT_00746940 = _DAT_00746940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746944 = -1;
  pcVar3 = "VINYL_GROUP_FLAGS";
  do {
    _DAT_00746944 = _DAT_00746944 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746948 = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL";
  do {
    _DAT_00746948 = _DAT_00746948 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074694c = -1;
  pcVar3 = "VINYL_GROUP_TRIBAL_HOOD";
  do {
    _DAT_0074694c = _DAT_0074694c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746950 = -1;
  pcVar3 = "VINYL_GROUP_WILD";
  do {
    _DAT_00746950 = _DAT_00746950 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  DAT_00746954 = -1;
  pcVar3 = "VINYL_GROUP_UNIQUES";
  do {
    DAT_00746954 = DAT_00746954 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00746958 = -1;
  pcVar3 = "VINYL_GROUP_AEM";
  do {
    _DAT_00746958 = _DAT_00746958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_0074695c = -1;
  pcVar3 = "VINYL_GROUP_BODY_VINYL";
  do {
    _DAT_0074695c = _DAT_0074695c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  pcVar3 = "VINYL_GROUP_MANUFACTURAR_LOGO";
  _DAT_00746960 = -1;
  do {
    _DAT_00746960 = _DAT_00746960 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68d4d0 FUN_0068d4d0

void FUN_0068d4d0(void)

{
  eh_vector_constructor_iterator(&DAT_00746118,8,0x100,FUN_0049fd90,FUN_0049fda0);
  _atexit(FUN_006964e0);
  return;
}


// ==== 0x68d500 FUN_0068d500

void FUN_0068d500(void)

{
  FUN_004f3d30();
  _atexit(FUN_00696500);
  return;
}


// ==== 0x68d520 FUN_0068d520

void FUN_0068d520(void)

{
  bList__bList();
  _atexit(StaticInit_FEngFont_G7460fc_696510);
  return;
}


// ==== 0x68d540 FUN_0068d540

void FUN_0068d540(void)

{
  FUN_004fcaf0();
  _atexit(FUN_00696520);
  return;
}


// ==== 0x68d560 FUN_0068d560

void FUN_0068d560(void)

{
  FUN_004fcaf0();
  _atexit(FUN_00696530);
  return;
}


// ==== 0x68d580 FUN_0068d580

void FUN_0068d580(void)

{
  FUN_004fcaf0();
  _atexit(FUN_00696540);
  return;
}


// ==== 0x68d5a0 FUN_0068d5a0

void FUN_0068d5a0(void)

{
  FUN_004fcaf0();
  _atexit(FUN_00696550);
  return;
}


// ==== 0x68d5c0 FUN_0068d5c0

void FUN_0068d5c0(void)

{
  FUN_00504220();
  _atexit(StaticInit_GaragePaintModScreen_G744ff0_696560);
  return;
}


// ==== 0x68d5e0 FUN_0068d5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d5e0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x56;
  _DAT_00706668 = -1;
  pcVar3 = "VISUAL_PART_MUFFLERTIP";
  do {
    _DAT_00706668 = _DAT_00706668 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00706670 = 0;
  _DAT_00706678 = 0;
  _DAT_0070668c = 0;
  _DAT_00706694 = 0;
  _DAT_00706698 = 0;
  _DAT_0070666c = "_KIT%02d_EXHAUST";
  _DAT_00706674 = 0xf;
  _DAT_0070667c = 0xa5b28001;
  _DAT_00706680 = 0xc;
  _DAT_00706684 = 0x945e9bc5;
  _DAT_00706688 = "_KIT%02d_WIDE_BODY";
  _DAT_00706690 = 6;
  return;
}


// ==== 0x68d670 FUN_0068d670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068d670(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x57;
  _DAT_00745ee8 = -1;
  pcVar3 = "WINDSHIELD_TINT_L1_BLACK";
  do {
    _DAT_00745ee8 = _DAT_00745ee8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ef4 = -1;
  _DAT_00745eec = 0xfd6bbe9a;
  _DAT_00745ef0 = 0x26e48815;
  pcVar3 = "WINDSHIELD_TINT_L1_GREEN";
  do {
    _DAT_00745ef4 = _DAT_00745ef4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f00 = -1;
  _DAT_00745ef8 = 0xfdc994ae;
  _DAT_00745efc = 0x26e48815;
  pcVar3 = "WINDSHIELD_TINT_L2_BLACK";
  do {
    _DAT_00745f00 = _DAT_00745f00 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f0c = -1;
  _DAT_00745f04 = 0xfd6bbe9a;
  _DAT_00745f08 = 0x580b0de;
  pcVar3 = "WINDSHIELD_TINT_L2_GREEN";
  do {
    _DAT_00745f0c = _DAT_00745f0c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f18 = -1;
  _DAT_00745f10 = 0xfdc994ae;
  _DAT_00745f14 = 0x580b0de;
  pcVar3 = "WINDSHIELD_TINT_L2_BLUE";
  do {
    _DAT_00745f18 = _DAT_00745f18 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f24 = -1;
  _DAT_00745f1c = 0x26b5b305;
  _DAT_00745f20 = 0x580b0de;
  pcVar3 = "WINDSHIELD_TINT_L2_RED";
  do {
    _DAT_00745f24 = _DAT_00745f24 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f30 = -1;
  _DAT_00745f28 = 0xf96a9dd8;
  _DAT_00745f2c = 0x580b0de;
  pcVar3 = "WINDSHIELD_TINT_L3_BLACK";
  do {
    _DAT_00745f30 = _DAT_00745f30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f3c = -1;
  _DAT_00745f34 = 0xfd6bbe9a;
  _DAT_00745f38 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_GREEN";
  do {
    _DAT_00745f3c = _DAT_00745f3c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f48 = -1;
  _DAT_00745f40 = 0xfdc994ae;
  _DAT_00745f44 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_BLUE";
  do {
    _DAT_00745f48 = _DAT_00745f48 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f54 = -1;
  _DAT_00745f4c = 0x26b5b305;
  _DAT_00745f50 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_RED";
  do {
    _DAT_00745f54 = _DAT_00745f54 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f60 = -1;
  _DAT_00745f58 = 0xf96a9dd8;
  _DAT_00745f5c = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_YELLOW";
  do {
    _DAT_00745f60 = _DAT_00745f60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f6c = -1;
  _DAT_00745f64 = 0xe011bc19;
  _DAT_00745f68 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_AQUA";
  do {
    _DAT_00745f6c = _DAT_00745f6c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f78 = -1;
  _DAT_00745f70 = 0x26b53be5;
  _DAT_00745f74 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_GRAPE";
  do {
    _DAT_00745f78 = _DAT_00745f78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f84 = -1;
  _DAT_00745f7c = 0xfdc9850c;
  _DAT_00745f80 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_ORANGE";
  do {
    _DAT_00745f84 = _DAT_00745f84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f90 = -1;
  _DAT_00745f88 = 0xc9a36399;
  _DAT_00745f8c = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_PINK";
  do {
    _DAT_00745f90 = _DAT_00745f90 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745f9c = -1;
  _DAT_00745f94 = 0x26bd52af;
  _DAT_00745f98 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_LIME";
  do {
    _DAT_00745f9c = _DAT_00745f9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745fa8 = -1;
  _DAT_00745fa0 = 0x26bb2104;
  _DAT_00745fa4 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_LAVENDER";
  do {
    _DAT_00745fa8 = _DAT_00745fa8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745fac = 0xf047aae;
  _DAT_00745fb0 = 0xd29d8fff;
  pcVar3 = "WINDSHIELD_TINT_L3_GOLD";
  _DAT_00745fb4 = -1;
  do {
    _DAT_00745fb4 = _DAT_00745fb4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00745fbc = 0xd29d8fff;
  _DAT_00745fb8 = 0x26b87c83;
  return;
}


// ==== 0x68da80 FUN_0068da80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068da80(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x57;
  DAT_00745e50 = -1;
  pcVar3 = "WINDOW_TINT_STOCK";
  do {
    DAT_00745e50 = DAT_00745e50 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  DAT_00745e58 = -1;
  _DAT_00745e54 = 0x3b83203;
  pcVar3 = "WINDSHIELD_TINT_L1_BLACK";
  do {
    DAT_00745e58 = DAT_00745e58 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e60 = -1;
  DAT_00745e5c = 0x89946400;
  pcVar3 = "WINDSHIELD_TINT_L1_GREEN";
  do {
    _DAT_00745e60 = _DAT_00745e60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e68 = -1;
  _DAT_00745e64 = 0x89f23a14;
  pcVar3 = "WINDSHIELD_TINT_L2_BLACK";
  do {
    _DAT_00745e68 = _DAT_00745e68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e70 = -1;
  _DAT_00745e6c = 0xd68ea0c1;
  pcVar3 = "WINDSHIELD_TINT_L2_GREEN";
  do {
    _DAT_00745e70 = _DAT_00745e70 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e78 = -1;
  _DAT_00745e74 = 0xd6ec76d5;
  pcVar3 = "WINDSHIELD_TINT_L2_BLUE";
  do {
    _DAT_00745e78 = _DAT_00745e78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e80 = -1;
  _DAT_00745e7c = 0x8a616c4c;
  pcVar3 = "WINDSHIELD_TINT_L2_RED";
  do {
    _DAT_00745e80 = _DAT_00745e80 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e88 = -1;
  _DAT_00745e84 = 0x8050ca3f;
  pcVar3 = "WINDSHIELD_TINT_L3_BLACK";
  do {
    _DAT_00745e88 = _DAT_00745e88 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e90 = -1;
  _DAT_00745e8c = 0x2388dd82;
  pcVar3 = "WINDSHIELD_TINT_L3_GREEN";
  do {
    _DAT_00745e90 = _DAT_00745e90 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745e98 = -1;
  _DAT_00745e94 = 0x23e6b396;
  pcVar3 = "WINDSHIELD_TINT_L3_BLUE";
  do {
    _DAT_00745e98 = _DAT_00745e98 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ea0 = -1;
  _DAT_00745e9c = 0x8cb694ed;
  pcVar3 = "WINDSHIELD_TINT_L3_RED";
  do {
    _DAT_00745ea0 = _DAT_00745ea0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ea8 = -1;
  _DAT_00745ea4 = 0x8062e2c0;
  pcVar3 = "WINDSHIELD_TINT_L3_YELLOW";
  do {
    _DAT_00745ea8 = _DAT_00745ea8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745eb0 = -1;
  _DAT_00745eac = 0xc9d2b801;
  pcVar3 = "WINDSHIELD_TINT_L3_AQUA";
  do {
    _DAT_00745eb0 = _DAT_00745eb0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745eb8 = -1;
  _DAT_00745eb4 = 0x8cb61dcd;
  pcVar3 = "WINDSHIELD_TINT_L3_GRAPE";
  do {
    _DAT_00745eb8 = _DAT_00745eb8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ec0 = -1;
  _DAT_00745ebc = 0x23e6a3f4;
  pcVar3 = "WINDSHIELD_TINT_L3_ORANGE";
  do {
    _DAT_00745ec0 = _DAT_00745ec0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ec8 = -1;
  _DAT_00745ec4 = 0xb3645f81;
  pcVar3 = "WINDSHIELD_TINT_L3_PINK";
  do {
    _DAT_00745ec8 = _DAT_00745ec8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ed0 = -1;
  _DAT_00745ecc = 0x8cbe3497;
  pcVar3 = "WINDSHIELD_TINT_L3_LIME";
  do {
    _DAT_00745ed0 = _DAT_00745ed0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745ed8 = -1;
  _DAT_00745ed4 = 0x8cbc02ec;
  pcVar3 = "WINDSHIELD_TINT_L3_LAVENDER";
  do {
    _DAT_00745ed8 = _DAT_00745ed8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00745edc = 0x6cf41096;
  pcVar3 = "WINDSHIELD_TINT_L3_GOLD";
  _DAT_00745ee0 = -1;
  do {
    _DAT_00745ee0 = _DAT_00745ee0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00745ee4 = 0x8cb95e6b;
  return;
}


// ==== 0x68de40 FUN_0068de40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068de40(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x4e;
  DAT_00745fc0 = -1;
  pcVar3 = "NEON_NONE";
  do {
    DAT_00745fc0 = DAT_00745fc0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  DAT_00745fc8 = -1;
  _DAT_00745fc4 = 0x3b83203;
  pcVar3 = "NEON_RED";
  do {
    DAT_00745fc8 = DAT_00745fc8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745fd0 = -1;
  DAT_00745fcc = 0x5054a89;
  pcVar3 = "NEON_GREEN";
  do {
    _DAT_00745fd0 = _DAT_00745fd0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745fd8 = -1;
  _DAT_00745fd4 = 0x5ac2319f;
  pcVar3 = "NEON_BLUE";
  do {
    _DAT_00745fd8 = _DAT_00745fd8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745fe0 = -1;
  _DAT_00745fdc = 0xa5a5f5d6;
  pcVar3 = "NEON_ORANGE";
  do {
    _DAT_00745fe0 = _DAT_00745fe0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745fe8 = -1;
  _DAT_00745fe4 = 0xc5af9eaa;
  pcVar3 = "NEON_YELLOW";
  do {
    _DAT_00745fe8 = _DAT_00745fe8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745ff0 = -1;
  _DAT_00745fec = 0xdc1df72a;
  pcVar3 = "NEON_AQUA";
  do {
    _DAT_00745ff0 = _DAT_00745ff0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00745ff8 = -1;
  _DAT_00745ff4 = 0xa5a57eb6;
  pcVar3 = "NEON_WHITE";
  do {
    _DAT_00745ff8 = _DAT_00745ff8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746000 = -1;
  _DAT_00745ffc = 0x5bde50cf;
  pcVar3 = "NEON_GRAPE";
  do {
    _DAT_00746000 = _DAT_00746000 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746008 = -1;
  _DAT_00746004 = 0x5ac221fd;
  pcVar3 = "NEON_PINK";
  do {
    _DAT_00746008 = _DAT_00746008 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746010 = -1;
  _DAT_0074600c = 0xa5ad9580;
  pcVar3 = "NEON_LIME";
  do {
    _DAT_00746010 = _DAT_00746010 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746018 = -1;
  _DAT_00746014 = 0xa5ab63d5;
  pcVar3 = "NEON_LAVENDER";
  do {
    _DAT_00746018 = _DAT_00746018 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746020 = -1;
  _DAT_0074601c = 0x3f0bbdff;
  pcVar3 = "NEON_GOLD";
  do {
    _DAT_00746020 = _DAT_00746020 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746028 = -1;
  _DAT_00746024 = 0xa5a8bf54;
  pcVar3 = "NEON_RED_PULSE";
  do {
    _DAT_00746028 = _DAT_00746028 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746030 = -1;
  _DAT_0074602c = 0x5fb0f3d1;
  pcVar3 = "NEON_GREEN_PULSE";
  do {
    _DAT_00746030 = _DAT_00746030 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746038 = -1;
  _DAT_00746034 = 0x7cc05367;
  pcVar3 = "NEON_BLUE_PULSE";
  do {
    _DAT_00746038 = _DAT_00746038 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746040 = -1;
  _DAT_0074603c = 0x462a24de;
  pcVar3 = "NEON_ORANGE_PULSE";
  do {
    _DAT_00746040 = _DAT_00746040 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746048 = -1;
  _DAT_00746044 = 0x800c1cb2;
  pcVar3 = "NEON_YELLOW_PULSE";
  do {
    _DAT_00746048 = _DAT_00746048 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746050 = -1;
  _DAT_0074604c = 0xb2fad532;
  pcVar3 = "NEON_AQUA_PULSE";
  do {
    _DAT_00746050 = _DAT_00746050 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746058 = -1;
  _DAT_00746054 = 0x54a4d5be;
  pcVar3 = "NEON_WHITE_PULSE";
  do {
    _DAT_00746058 = _DAT_00746058 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746060 = -1;
  _DAT_0074605c = 0x9f231697;
  pcVar3 = "NEON_GRAPE_PULSE";
  do {
    _DAT_00746060 = _DAT_00746060 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746068 = -1;
  _DAT_00746064 = 0x1cd69245;
  pcVar3 = "NEON_PINK_PULSE";
  do {
    _DAT_00746068 = _DAT_00746068 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746070 = -1;
  _DAT_0074606c = 0x79595c08;
  pcVar3 = "NEON_LIME_PULSE";
  do {
    _DAT_00746070 = _DAT_00746070 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00746078 = -1;
  _DAT_00746074 = 0xaf0fd61d;
  pcVar3 = "NEON_LAVENDER_PULSE";
  do {
    _DAT_00746078 = _DAT_00746078 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_0074607c = 0x6ad9a7c7;
  pcVar3 = "NEON_GOLD_PULSE";
  _DAT_00746080 = -1;
  do {
    _DAT_00746080 = _DAT_00746080 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00746084 = 0x1c8994dc;
  return;
}


// ==== 0x68e330 FUN_0068e330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e330(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x44;
  _DAT_00746088 = -1;
  pcVar3 = "DECAL_LEFTDOOR_SLOT1_WIDEBODY";
  do {
    _DAT_00746088 = _DAT_00746088 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074608c = -1;
  pcVar3 = "DECAL_LEFTDOOR_SLOT2_WIDEBODY";
  do {
    _DAT_0074608c = _DAT_0074608c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00746090 = -1;
  pcVar3 = "DECAL_LEFTDOOR_SLOT3_WIDEBODY";
  do {
    _DAT_00746090 = _DAT_00746090 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00746094 = -1;
  pcVar3 = "DECAL_LEFTDOOR_SLOT4_WIDEBODY";
  do {
    _DAT_00746094 = _DAT_00746094 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00746098 = -1;
  pcVar3 = "DECAL_LEFTDOOR_SLOT5_WIDEBODY";
  do {
    _DAT_00746098 = _DAT_00746098 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_LEFTDOOR_SLOT6_WIDEBODY";
  _DAT_0074609c = -1;
  do {
    _DAT_0074609c = _DAT_0074609c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68e430 FUN_0068e430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e430(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0x44;
  _DAT_007460a0 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT1_WIDEBODY";
  do {
    _DAT_007460a0 = _DAT_007460a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007460a4 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT2_WIDEBODY";
  do {
    _DAT_007460a4 = _DAT_007460a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007460a8 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT3_WIDEBODY";
  do {
    _DAT_007460a8 = _DAT_007460a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007460ac = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT4_WIDEBODY";
  do {
    _DAT_007460ac = _DAT_007460ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007460b0 = -1;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT5_WIDEBODY";
  do {
    _DAT_007460b0 = _DAT_007460b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_RIGHTDOOR_SLOT6_WIDEBODY";
  _DAT_007460b4 = -1;
  do {
    _DAT_007460b4 = _DAT_007460b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68e530 FUN_0068e530

void FUN_0068e530(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  puVar3 = &DAT_006b8d20;
  DAT_00744b88 = -1;
  uVar2 = 0x4e;
  do {
    DAT_00744b88 = DAT_00744b88 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68e560 FUN_0068e560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e560(void)

{
  DAT_007066c4 = 0x15;
  _DAT_007066c8 = 0x15;
  _DAT_007066d0 = PTR_s__s_DECAL_REAR_WINDOW_WIDE_MEDIUM_006f88b0;
  _DAT_007066f8 = PTR_s__s_WIDE1_DECAL_LEFT_DOOR_RECT_ME_006f88cc;
  _DAT_007066f0 = PTR_s__s_DECAL_LEFT_DOOR_RECT_MEDIUM_006f88b4;
  _DAT_00706710 = PTR_s__s_DECAL_RIGHT_DOOR_RECT_MEDIUM_006f88b8;
  _DAT_007066fc = PTR_s__s_WIDE2_DECAL_LEFT_DOOR_RECT_ME_006f88dc;
  _DAT_0070671c = PTR_s__s_WIDE2_DECAL_RIGHT_DOOR_RECT_M_006f88e0;
  _DAT_00706718 = PTR_s__s_WIDE1_DECAL_RIGHT_DOOR_RECT_M_006f88d0;
  _DAT_00706734 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_SMALL_006f88c0;
  _DAT_00706730 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_MEDIU_006f88bc;
  _DAT_0070673c = PTR_s__s_WIDE2_DECAL_LEFT_QUARTER_RECT_006f88e4;
  _DAT_00706738 = PTR_s__s_WIDE1_DECAL_LEFT_QUARTER_RECT_006f88d4;
  _DAT_00706754 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_SMAL_006f88c8;
  _DAT_00706750 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_MEDI_006f88c4;
  _DAT_0070675c = PTR_s__s_WIDE2_DECAL_RIGHT_QUARTER_REC_006f88e8;
  _DAT_007066b0 = PTR_s__s_DECAL_FRONT_WINDOW_WIDE_MEDIU_006f88ac;
  _DAT_00706758 = PTR_s__s_WIDE1_DECAL_RIGHT_QUARTER_REC_006f88d8;
  _DAT_00706764 = 0x13;
  _DAT_00706768 = 0x13;
  _DAT_007066b4 = 0;
  _DAT_007066b8 = 0;
  _DAT_007066bc = 0;
  DAT_007066c0 = 1;
  DAT_007066cc = 0x4b;
  _DAT_007066d4 = 0;
  _DAT_007066d8 = 0;
  _DAT_007066dc = 0;
  _DAT_007066e0 = 2;
  _DAT_007066e4 = 0x16;
  _DAT_007066e8 = 0x1a;
  _DAT_007066ec = 0x53;
  _DAT_007066f4 = 0;
  _DAT_00706700 = 3;
  _DAT_00706704 = 0x17;
  _DAT_00706708 = 0x1b;
  _DAT_0070670c = 0x5b;
  _DAT_00706714 = 0;
  _DAT_00706720 = 4;
  _DAT_00706724 = 0x18;
  _DAT_00706728 = 0x1c;
  _DAT_0070672c = 99;
  _DAT_00706740 = 5;
  _DAT_00706744 = 0x19;
  _DAT_00706748 = 0x1d;
  _DAT_0070674c = 0x6b;
  _DAT_00706760 = 6;
  _DAT_0070676c = 0x3b;
  _DAT_00706770 = PTR_s__s_DECAL_HOOD_RECT_MEDIUM_006f88ec;
  _DAT_00706774 = PTR_s__s_DECAL_HOOD_RECT_SMALL_006f88f0;
  _DAT_00706778 = 0;
  _DAT_0070677c = 0;
  return;
}


// ==== 0x68e760 FUN_0068e760

void FUN_0068e760(void)

{
  FUN_00504150();
  _atexit(FUN_00696570);
  return;
}


// ==== 0x68e780 FUN_0068e780

void FUN_0068e780(void)

{
  _atexit(FUN_00696580);
  return;
}


// ==== 0x68e790 FUN_0068e790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e790(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "MAGAZINE_RACE_1";
  _DAT_007449dc = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449dc = _DAT_007449dc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  DAT_007449e0 = 1;
  pcVar3 = "MAGAZINE_RACE_2";
  DAT_007449e4 = -1;
  uVar2 = 0x4d;
  do {
    DAT_007449e4 = DAT_007449e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449e8 = 2;
  pcVar3 = "MAGAZINE_RACE_3";
  _DAT_007449ec = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449ec = _DAT_007449ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449f0 = 3;
  pcVar3 = "MAGAZINE_RACE_4";
  _DAT_007449f4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449f4 = _DAT_007449f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449f8 = 4;
  pcVar3 = "MAGAZINE_RACE_5";
  _DAT_007449fc = -1;
  uVar2 = 0x4d;
  do {
    _DAT_007449fc = _DAT_007449fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a00 = 5;
  pcVar3 = "MAGAZINE_RACE_6";
  _DAT_00744a04 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a04 = _DAT_00744a04 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a08 = 6;
  pcVar3 = "MAGAZINE_RACE_7";
  _DAT_00744a0c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a0c = _DAT_00744a0c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a10 = 7;
  pcVar3 = "MAGAZINE_RACE_8";
  _DAT_00744a14 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a14 = _DAT_00744a14 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a18 = 8;
  pcVar3 = "MAGAZINE_RACE_9";
  _DAT_00744a1c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a1c = _DAT_00744a1c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a20 = 9;
  pcVar3 = "MAGAZINE_RACE_10";
  _DAT_00744a24 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a24 = _DAT_00744a24 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a28 = 10;
  pcVar3 = "MAGAZINE_RACE_11";
  _DAT_00744a2c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a2c = _DAT_00744a2c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a30 = 0xb;
  pcVar3 = "MAGAZINE_TASK_1";
  _DAT_00744a34 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a34 = _DAT_00744a34 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a38 = 0xc;
  pcVar3 = "MAGAZINE_TASK_2";
  _DAT_00744a3c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a3c = _DAT_00744a3c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a40 = 0xd;
  pcVar3 = "MAGAZINE_TASK_3";
  _DAT_00744a44 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a44 = _DAT_00744a44 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a48 = 0xe;
  pcVar3 = "MAGAZINE_TASK_4";
  _DAT_00744a4c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a4c = _DAT_00744a4c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a50 = 0xf;
  pcVar3 = "MAGAZINE_TASK_5";
  _DAT_00744a54 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a54 = _DAT_00744a54 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a58 = 0x10;
  pcVar3 = "MAGAZINE_TASK_6";
  _DAT_00744a5c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a5c = _DAT_00744a5c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a60 = 0x11;
  pcVar3 = "MAGAZINE_TASK_7";
  _DAT_00744a64 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a64 = _DAT_00744a64 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a68 = 0x12;
  pcVar3 = "MAGAZINE_TASK_8";
  _DAT_00744a6c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a6c = _DAT_00744a6c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a70 = 0x13;
  pcVar3 = "MAGAZINE_TASK_9";
  _DAT_00744a74 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a74 = _DAT_00744a74 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a78 = 0x14;
  pcVar3 = "MAGAZINE_TASK_10";
  _DAT_00744a7c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a7c = _DAT_00744a7c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a80 = 0x15;
  pcVar3 = "MAGAZINE_TASK_11";
  _DAT_00744a84 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a84 = _DAT_00744a84 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a88 = 0x16;
  pcVar3 = "MAGAZINE_TASK_12";
  _DAT_00744a8c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a8c = _DAT_00744a8c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a90 = 0x17;
  pcVar3 = "MAGAZINE_TASK_13";
  _DAT_00744a94 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a94 = _DAT_00744a94 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744a98 = 0x18;
  pcVar3 = "MAGAZINE_TASK_14";
  _DAT_00744a9c = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744a9c = _DAT_00744a9c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aa0 = 0x19;
  pcVar3 = "MAGAZINE_TASK_15";
  _DAT_00744aa4 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744aa4 = _DAT_00744aa4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aa8 = 0x1a;
  pcVar3 = "MAGAZINE_TASK_16";
  _DAT_00744aac = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744aac = _DAT_00744aac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  return;
}


// ==== 0x68eca0 FUN_0068eca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068eca0(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = "MAGAZINE_RACE_1";
  DAT_00744ab0 = -1;
  uVar2 = 0x4d;
  do {
    DAT_00744ab0 = DAT_00744ab0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ab4 = 0;
  pcVar3 = "MAGAZINE_RACE_2";
  DAT_00744ab8 = -1;
  uVar2 = 0x4d;
  do {
    DAT_00744ab8 = DAT_00744ab8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  DAT_00744abc = 1;
  pcVar3 = "MAGAZINE_RACE_3";
  _DAT_00744ac0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ac0 = _DAT_00744ac0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ac4 = 2;
  pcVar3 = "MAGAZINE_RACE_4";
  _DAT_00744ac8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ac8 = _DAT_00744ac8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744acc = 3;
  pcVar3 = "MAGAZINE_RACE_5";
  _DAT_00744ad0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ad0 = _DAT_00744ad0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ad4 = 4;
  pcVar3 = "MAGAZINE_RACE_6";
  _DAT_00744ad8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ad8 = _DAT_00744ad8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744adc = 5;
  pcVar3 = "MAGAZINE_RACE_7";
  _DAT_00744ae0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ae0 = _DAT_00744ae0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744ae4 = 6;
  pcVar3 = "MAGAZINE_RACE_8";
  _DAT_00744ae8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744ae8 = _DAT_00744ae8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744aec = 7;
  pcVar3 = "MAGAZINE_RACE_9";
  _DAT_00744af0 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744af0 = _DAT_00744af0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744af4 = 8;
  pcVar3 = "MAGAZINE_RACE_10";
  _DAT_00744af8 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744af8 = _DAT_00744af8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744afc = 9;
  pcVar3 = "MAGAZINE_RACE_11";
  _DAT_00744b00 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b00 = _DAT_00744b00 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b04 = 10;
  pcVar3 = "MAGAZINE_TASK_1";
  _DAT_00744b08 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b08 = _DAT_00744b08 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b0c = 0xb;
  pcVar3 = "MAGAZINE_TASK_2";
  _DAT_00744b10 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b10 = _DAT_00744b10 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b14 = 0xc;
  pcVar3 = "MAGAZINE_TASK_3";
  _DAT_00744b18 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b18 = _DAT_00744b18 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b1c = 0xd;
  pcVar3 = "MAGAZINE_TASK_4";
  _DAT_00744b20 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b20 = _DAT_00744b20 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b24 = 0xe;
  pcVar3 = "MAGAZINE_TASK_5";
  _DAT_00744b28 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b28 = _DAT_00744b28 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b2c = 0xf;
  pcVar3 = "MAGAZINE_TASK_6";
  _DAT_00744b30 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b30 = _DAT_00744b30 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b34 = 0x10;
  pcVar3 = "MAGAZINE_TASK_7";
  _DAT_00744b38 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b38 = _DAT_00744b38 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b3c = 0x11;
  pcVar3 = "MAGAZINE_TASK_8";
  _DAT_00744b40 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b40 = _DAT_00744b40 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b44 = 0x12;
  pcVar3 = "MAGAZINE_TASK_9";
  _DAT_00744b48 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b48 = _DAT_00744b48 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b4c = 0x13;
  pcVar3 = "MAGAZINE_TASK_10";
  _DAT_00744b50 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b50 = _DAT_00744b50 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b54 = 0x14;
  pcVar3 = "MAGAZINE_TASK_11";
  _DAT_00744b58 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b58 = _DAT_00744b58 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b5c = 0x15;
  pcVar3 = "MAGAZINE_TASK_12";
  _DAT_00744b60 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b60 = _DAT_00744b60 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b64 = 0x16;
  pcVar3 = "MAGAZINE_TASK_13";
  _DAT_00744b68 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b68 = _DAT_00744b68 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b6c = 0x17;
  pcVar3 = "MAGAZINE_TASK_14";
  _DAT_00744b70 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b70 = _DAT_00744b70 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b74 = 0x18;
  pcVar3 = "MAGAZINE_TASK_15";
  _DAT_00744b78 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b78 = _DAT_00744b78 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b7c = 0x19;
  pcVar3 = "MAGAZINE_TASK_16";
  _DAT_00744b80 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744b80 = _DAT_00744b80 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744b84 = 0x1a;
  return;
}


// ==== 0x68f1c0 FUN_0068f1c0

void FUN_0068f1c0(void)

{
  FUN_00589260();
  _atexit(FUN_00696590);
  return;
}


// ==== 0x68f1e0 FUN_0068f1e0

void FUN_0068f1e0(void)

{
  _atexit(FUN_006965a0);
  return;
}


// ==== 0x68f1f0 FUN_0068f1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068f1f0(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined *puVar5;
  
  uVar2 = 0x35;
  puVar3 = &DAT_006bf808;
  DAT_00744364 = -1;
  do {
    DAT_00744364 = DAT_00744364 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x35;
  puVar3 = &DAT_006bf810;
  DAT_00744368 = -1;
  do {
    DAT_00744368 = DAT_00744368 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x35;
  puVar3 = &DAT_006bf818;
  DAT_0074436c = -1;
  do {
    DAT_0074436c = DAT_0074436c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_5ZIGEN";
  DAT_00744370 = -1;
  do {
    DAT_00744370 = DAT_00744370 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744374 = &DAT_006bf808;
  DAT_00744378 = 1;
  puVar5 = &DAT_006c8c9c;
  DAT_0074437c = -1;
  uVar2 = 0x41;
  do {
    DAT_0074437c = DAT_0074437c * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  pcVar4 = "ABS_DYNAMICS";
  DAT_00744380 = -1;
  do {
    DAT_00744380 = DAT_00744380 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  pcVar4 = "ABSDYNAMICS";
  DAT_00744384 = -1;
  do {
    DAT_00744384 = DAT_00744384 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_ABS";
  DAT_00744388 = -1;
  do {
    DAT_00744388 = DAT_00744388 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_0074438c = "ABS DYNAMICS";
  _DAT_00744390 = 2;
  puVar3 = &DAT_006bf870;
  _DAT_00744394 = -1;
  do {
    _DAT_00744394 = _DAT_00744394 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  pcVar4 = "ADVANCEDCLUTCH";
  _DAT_00744398 = -1;
  do {
    _DAT_00744398 = _DAT_00744398 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074439c = 0xffffffff;
  pcVar4 = "DECAL_ICON_ACT";
  _DAT_007443a0 = -1;
  do {
    _DAT_007443a0 = _DAT_007443a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_007443a4 = &DAT_006bf870;
  _DAT_007443a8 = 3;
  puVar3 = &DAT_006bf894;
  _DAT_007443ac = -1;
  do {
    _DAT_007443ac = _DAT_007443ac * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007443b0 = 0xffffffff;
  _DAT_007443b4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_AEM";
  _DAT_007443b8 = -1;
  do {
    _DAT_007443b8 = _DAT_007443b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_007443bc = &DAT_006bf894;
  _DAT_007443c0 = 4;
  pcVar4 = "ALPINE";
  _DAT_007443c4 = -1;
  do {
    _DAT_007443c4 = _DAT_007443c4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007443c8 = 0xffffffff;
  _DAT_007443cc = 0xffffffff;
  pcVar4 = "DECAL_ICON_ALPINE";
  _DAT_007443d0 = -1;
  do {
    _DAT_007443d0 = _DAT_007443d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_007443d4 = "ALPINE";
  _DAT_007443d8 = 5;
  puVar3 = &DAT_006bf8c4;
  _DAT_007443dc = -1;
  do {
    _DAT_007443dc = _DAT_007443dc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007443e0 = 0xffffffff;
  _DAT_007443e4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_APEX";
  _DAT_007443e8 = -1;
  do {
    _DAT_007443e8 = _DAT_007443e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_007443ec = &DAT_006bf8c4;
  _DAT_007443f0 = 6;
  puVar3 = &DAT_006bf8dc;
  _DAT_007443f4 = -1;
  do {
    _DAT_007443f4 = _DAT_007443f4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007443f8 = 0xffffffff;
  _DAT_007443fc = 0xffffffff;
  pcVar4 = "DECAL_ICON_APEXI";
  _DAT_00744400 = -1;
  do {
    _DAT_00744400 = _DAT_00744400 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_00744404 = &DAT_006bf8dc;
  _DAT_00744408 = 7;
  pcVar4 = "AROSPEED";
  _DAT_0074440c = -1;
  do {
    _DAT_0074440c = _DAT_0074440c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744410 = 0xffffffff;
  _DAT_00744414 = 0xffffffff;
  pcVar4 = "DECAL_ICON_AROSPEED";
  _DAT_00744418 = -1;
  do {
    _DAT_00744418 = _DAT_00744418 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_0074441c = "AROSPEED";
  _DAT_00744420 = 8;
  pcVar4 = "AUDIOBAHN";
  _DAT_00744424 = -1;
  do {
    _DAT_00744424 = _DAT_00744424 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744428 = 0xffffffff;
  _DAT_0074442c = 0xffffffff;
  pcVar4 = "DECAL_ICON_AUDIOBAHN";
  _DAT_00744430 = -1;
  do {
    _DAT_00744430 = _DAT_00744430 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x42;
  _DAT_00744434 = "AUDIOBAHN";
  _DAT_00744438 = 9;
  puVar3 = &DAT_006bf93c;
  _DAT_0074443c = -1;
  do {
    _DAT_0074443c = _DAT_0074443c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744440 = 0xffffffff;
  _DAT_00744444 = 0xffffffff;
  pcVar4 = "DECAL_ICON_BBS";
  _DAT_00744448 = -1;
  do {
    _DAT_00744448 = _DAT_00744448 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x42;
  _DAT_0074444c = &DAT_006bf93c;
  _DAT_00744450 = 10;
  pcVar4 = "BILSTEIN";
  _DAT_00744454 = -1;
  do {
    _DAT_00744454 = _DAT_00744454 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744458 = 0xffffffff;
  _DAT_0074445c = 0xffffffff;
  pcVar4 = "DECAL_ICON_BILSTEIN";
  _DAT_00744460 = -1;
  do {
    _DAT_00744460 = _DAT_00744460 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x42;
  _DAT_00744464 = "BILSTEIN";
  _DAT_00744468 = 0xb;
  pcVar4 = "BORLA";
  _DAT_0074446c = -1;
  do {
    _DAT_0074446c = _DAT_0074446c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744470 = 0xffffffff;
  _DAT_00744474 = 0xffffffff;
  pcVar4 = "DECAL_ICON_BORLA";
  _DAT_00744478 = -1;
  do {
    _DAT_00744478 = _DAT_00744478 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x42;
  _DAT_0074447c = "BORLA";
  _DAT_00744480 = 0xc;
  pcVar4 = "BREMBO";
  _DAT_00744484 = -1;
  do {
    _DAT_00744484 = _DAT_00744484 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744488 = 0xffffffff;
  _DAT_0074448c = 0xffffffff;
  pcVar4 = "DECAL_ICON_BREMBO";
  _DAT_00744490 = -1;
  do {
    _DAT_00744490 = _DAT_00744490 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744494 = "BREMBO";
  _DAT_00744498 = 0xd;
  pcVar4 = "CLUTCHMASTERS";
  _DAT_0074449c = -1;
  do {
    _DAT_0074449c = _DAT_0074449c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007444a0 = 0xffffffff;
  _DAT_007444a4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_CLUTCHMASTERS";
  _DAT_007444a8 = -1;
  do {
    _DAT_007444a8 = _DAT_007444a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x52;
  _DAT_007444ac = "CLUTCHMASTERS";
  _DAT_007444b0 = 0xe;
  pcVar4 = "RACINGHART";
  _DAT_007444b4 = -1;
  do {
    _DAT_007444b4 = _DAT_007444b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x52;
  pcVar4 = "RACING_HART";
  _DAT_007444b8 = -1;
  do {
    _DAT_007444b8 = _DAT_007444b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x52;
  pcVar4 = "RacingHart";
  _DAT_007444bc = -1;
  do {
    _DAT_007444bc = _DAT_007444bc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_RACINGHART";
  _DAT_007444c0 = -1;
  do {
    _DAT_007444c0 = _DAT_007444c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007444c4 = "RACINGHART";
  _DAT_007444c8 = 0xf;
  puVar3 = &DAT_006bfa10;
  _DAT_007444cc = -1;
  do {
    _DAT_007444cc = _DAT_007444cc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DC_SPORTS";
  _DAT_007444d0 = -1;
  do {
    _DAT_007444d0 = _DAT_007444d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DCSPORTS";
  _DAT_007444d4 = -1;
  do {
    _DAT_007444d4 = _DAT_007444d4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_DC";
  _DAT_007444d8 = -1;
  do {
    _DAT_007444d8 = _DAT_007444d8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007444dc = "DCSPORTS";
  _DAT_007444e0 = 0x10;
  pcVar4 = "EIBACH";
  _DAT_007444e4 = -1;
  do {
    _DAT_007444e4 = _DAT_007444e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  pcVar4 = "EIBACHSPRINGS";
  _DAT_007444e8 = -1;
  do {
    _DAT_007444e8 = _DAT_007444e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007444ec = 0xffffffff;
  pcVar4 = "DECAL_ICON_EIBACH";
  _DAT_007444f0 = -1;
  do {
    _DAT_007444f0 = _DAT_007444f0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007444f4 = "EIBACH";
  _DAT_007444f8 = 0x11;
  puVar3 = &DAT_006bfa68;
  _DAT_007444fc = -1;
  do {
    _DAT_007444fc = _DAT_007444fc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744500 = 0xffffffff;
  _DAT_00744504 = 0xffffffff;
  pcVar4 = "DECAL_ICON_ENKEI";
  _DAT_00744508 = -1;
  do {
    _DAT_00744508 = _DAT_00744508 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_0074450c = &DAT_006bfa68;
  _DAT_00744510 = 0x12;
  pcVar4 = "EXTREMEDIMENSIONS";
  _DAT_00744514 = -1;
  do {
    _DAT_00744514 = _DAT_00744514 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  pcVar4 = "EXTRDIMENSION";
  _DAT_00744518 = -1;
  do {
    _DAT_00744518 = _DAT_00744518 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  pcVar4 = "EXTREMEDIMENSION";
  _DAT_0074451c = -1;
  uVar2 = 0x45;
  do {
    _DAT_0074451c = _DAT_0074451c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_EXTREMEDIMENSIONS";
  _DAT_00744520 = -1;
  do {
    _DAT_00744520 = _DAT_00744520 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x47;
  _DAT_00744524 = "EXTREMEDIMENSIONS";
  _DAT_00744528 = 0x13;
  pcVar4 = "GENERA";
  _DAT_0074452c = -1;
  do {
    _DAT_0074452c = _DAT_0074452c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  puVar3 = &DAT_006bfad0;
  _DAT_00744530 = -1;
  do {
    _DAT_00744530 = _DAT_00744530 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744534 = 0xffffffff;
  pcVar4 = "DECAL_ICON_TYC";
  _DAT_00744538 = -1;
  do {
    _DAT_00744538 = _DAT_00744538 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x47;
  _DAT_0074453c = "GENERA (TYC)";
  _DAT_00744540 = 0x14;
  pcVar4 = "GREDDY";
  _DAT_00744544 = -1;
  do {
    _DAT_00744544 = _DAT_00744544 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744548 = 0xffffffff;
  _DAT_0074454c = 0xffffffff;
  pcVar4 = "DECAL_ICON_GREDDY";
  _DAT_00744550 = -1;
  do {
    _DAT_00744550 = _DAT_00744550 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_00744554 = "GREDDY";
  _DAT_00744558 = 0x15;
  pcVar4 = "HENSHIN";
  _DAT_0074455c = -1;
  do {
    _DAT_0074455c = _DAT_0074455c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  pcVar4 = "HENSHINAUTO";
  _DAT_00744560 = -1;
  do {
    _DAT_00744560 = _DAT_00744560 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744564 = 0xffffffff;
  pcVar4 = "DECAL_ICON_HENSHIN";
  _DAT_00744568 = -1;
  do {
    _DAT_00744568 = _DAT_00744568 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_0074456c = "HENSHIN_AUTO";
  _DAT_00744570 = 0x16;
  puVar3 = &DAT_006bfb48;
  _DAT_00744574 = -1;
  do {
    _DAT_00744574 = _DAT_00744574 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744578 = 0xffffffff;
  _DAT_0074457c = 0xffffffff;
  pcVar4 = "DECAL_ICON_HKS";
  _DAT_00744580 = -1;
  do {
    _DAT_00744580 = _DAT_00744580 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_00744584 = &DAT_006bfb48;
  _DAT_00744588 = 0x17;
  pcVar4 = "HOLLEY";
  _DAT_0074458c = -1;
  do {
    _DAT_0074458c = _DAT_0074458c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  puVar3 = &DAT_006ba7a4;
  _DAT_00744590 = -1;
  do {
    _DAT_00744590 = _DAT_00744590 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744594 = 0xffffffff;
  pcVar4 = "DECAL_ICON_NOS";
  _DAT_00744598 = -1;
  do {
    _DAT_00744598 = _DAT_00744598 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_0074459c = "HOLLEY";
  _DAT_007445a0 = 0x18;
  puVar3 = &DAT_006bfb74;
  _DAT_007445a4 = -1;
  do {
    _DAT_007445a4 = _DAT_007445a4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  pcVar4 = "HPRACING";
  _DAT_007445a8 = -1;
  do {
    _DAT_007445a8 = _DAT_007445a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  pcVar4 = "HP_RACING";
  _DAT_007445ac = -1;
  do {
    _DAT_007445ac = _DAT_007445ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_HPRACING";
  _DAT_007445b0 = -1;
  do {
    _DAT_007445b0 = _DAT_007445b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x48;
  _DAT_007445b4 = &DAT_006bfb74;
  _DAT_007445b8 = 0x19;
  puVar3 = &DAT_006bfba4;
  _DAT_007445bc = -1;
  do {
    _DAT_007445bc = _DAT_007445bc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007445c0 = 0xffffffff;
  _DAT_007445c4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_HANDR";
  _DAT_007445c8 = -1;
  do {
    _DAT_007445c8 = _DAT_007445c8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x49;
  _DAT_007445cc = &DAT_006bfba4;
  _DAT_007445d0 = 0x1a;
  puVar3 = &DAT_006bfbbc;
  _DAT_007445d4 = -1;
  do {
    _DAT_007445d4 = _DAT_007445d4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007445d8 = 0xffffffff;
  _DAT_007445dc = 0xffffffff;
  pcVar4 = "DECAL_ICON_INJEN";
  _DAT_007445e0 = -1;
  do {
    _DAT_007445e0 = _DAT_007445e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  _DAT_007445e4 = &DAT_006bfbbc;
  _DAT_007445e8 = 0x1b;
  pcVar4 = "JACKSONRACING";
  _DAT_007445ec = -1;
  do {
    _DAT_007445ec = _DAT_007445ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar4 = "JACKSON_RACING";
  _DAT_007445f0 = -1;
  do {
    _DAT_007445f0 = _DAT_007445f0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar4 = "JACKSON";
  _DAT_007445f4 = -1;
  do {
    _DAT_007445f4 = _DAT_007445f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = -1;
  do {
    _DAT_007445f8 = _DAT_007445f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar3 = &DAT_006bfc14;
  _DAT_00744604 = -1;
  do {
    _DAT_00744604 = _DAT_00744604 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar4 = "JSPAMERICA";
  _DAT_00744608 = -1;
  do {
    _DAT_00744608 = _DAT_00744608 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074460c = 0xffffffff;
  pcVar4 = "DECAL_ICON_JSP";
  _DAT_00744610 = -1;
  do {
    _DAT_00744610 = _DAT_00744610 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar3 = &DAT_006bfc34;
  _DAT_0074461c = -1;
  do {
    _DAT_0074461c = _DAT_0074461c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744620 = 0xffffffff;
  _DAT_00744624 = 0xffffffff;
  _DAT_00744628 = 0xffffffff;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar4 = "KENWOOD";
  _DAT_00744634 = -1;
  do {
    _DAT_00744634 = _DAT_00744634 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744638 = 0xffffffff;
  _DAT_0074463c = 0xffffffff;
  pcVar4 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = -1;
  do {
    _DAT_00744640 = _DAT_00744640 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar4 = "KEYSTONE";
  _DAT_0074464c = -1;
  do {
    _DAT_0074464c = _DAT_0074464c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744650 = 0xffffffff;
  _DAT_00744654 = 0xffffffff;
  _DAT_00744658 = 0xffffffff;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar3 = &DAT_006bfc60;
  _DAT_00744664 = -1;
  do {
    _DAT_00744664 = _DAT_00744664 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744668 = 0xffffffff;
  _DAT_0074466c = 0xffffffff;
  pcVar4 = "DECAL_ICON_KONI";
  _DAT_00744670 = -1;
  do {
    _DAT_00744670 = _DAT_00744670 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar3 = &DAT_006bfc78;
  _DAT_0074467c = -1;
  do {
    _DAT_0074467c = _DAT_0074467c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744680 = 0xffffffff;
  _DAT_00744684 = 0xffffffff;
  pcVar4 = "DECAL_ICON_KONIG";
  _DAT_00744688 = -1;
  do {
    _DAT_00744688 = _DAT_00744688 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar3 = &DAT_006bfc94;
  _DAT_00744694 = -1;
  do {
    _DAT_00744694 = _DAT_00744694 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  puVar3 = &DAT_006bfc9c;
  _DAT_00744698 = -1;
  do {
    _DAT_00744698 = _DAT_00744698 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074469c = 0xffffffff;
  _DAT_007446a0 = 0xffffffff;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar3 = &DAT_006bfca4;
  _DAT_007446ac = -1;
  do {
    _DAT_007446ac = _DAT_007446ac * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  pcVar4 = "KVRPERFORMANCE";
  _DAT_007446b0 = -1;
  do {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446b4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_KVR";
  _DAT_007446b8 = -1;
  do {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar3 = &DAT_006bfcc8;
  _DAT_007446c4 = -1;
  do {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446c8 = 0xffffffff;
  _DAT_007446cc = 0xffffffff;
  pcVar4 = "DECAL_ICON_KYB";
  _DAT_007446d0 = -1;
  do {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar3 = &DAT_006bfcdc;
  _DAT_007446dc = -1;
  do {
    _DAT_007446dc = _DAT_007446dc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446e0 = 0xffffffff;
  _DAT_007446e4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = -1;
  do {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar4 = "NEUSPEED";
  _DAT_007446f4 = -1;
  do {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446f8 = 0xffffffff;
  _DAT_007446fc = 0xffffffff;
  pcVar4 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = -1;
  do {
    _DAT_00744700 = _DAT_00744700 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar4 = "NITROUS_EXPRESS";
  _DAT_0074470c = -1;
  do {
    _DAT_0074470c = _DAT_0074470c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  puVar3 = &DAT_006bfd24;
  _DAT_00744710 = -1;
  do {
    _DAT_00744710 = _DAT_00744710 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  pcVar4 = "NITROUSEXPRESS";
  _DAT_00744714 = -1;
  do {
    _DAT_00744714 = _DAT_00744714 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_NX";
  _DAT_00744718 = -1;
  do {
    _DAT_00744718 = _DAT_00744718 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4f;
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar3 = &DAT_006bfd48;
  _DAT_00744724 = -1;
  do {
    _DAT_00744724 = _DAT_00744724 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744728 = 0xffffffff;
  _DAT_0074472c = 0xffffffff;
  pcVar4 = "DECAL_ICON_OZ";
  _DAT_00744730 = -1;
  do {
    _DAT_00744730 = _DAT_00744730 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar5 = &DAT_006c0ca0;
  _DAT_0074473c = -1;
  uVar2 = 0x50;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744740 = 0xffffffff;
  _DAT_00744744 = 0xffffffff;
  pcVar4 = "DECAL_ICON_PIAA";
  _DAT_00744748 = -1;
  do {
    _DAT_00744748 = _DAT_00744748 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar4 = "PLASMAGLOW";
  _DAT_00744754 = -1;
  do {
    _DAT_00744754 = _DAT_00744754 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  pcVar4 = "PLASMA_GLOW";
  _DAT_00744758 = -1;
  do {
    _DAT_00744758 = _DAT_00744758 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074475c = 0xffffffff;
  pcVar4 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = -1;
  do {
    _DAT_00744760 = _DAT_00744760 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar4 = "SCORPION";
  _DAT_0074476c = -1;
  uVar2 = 0x53;
  do {
    _DAT_0074476c = _DAT_0074476c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744770 = 0xffffffff;
  _DAT_00744774 = 0xffffffff;
  pcVar4 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = -1;
  do {
    _DAT_00744778 = _DAT_00744778 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar3 = &DAT_006bfdbc;
  _DAT_00744784 = -1;
  do {
    _DAT_00744784 = _DAT_00744784 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744788 = 0xffffffff;
  _DAT_0074478c = 0xffffffff;
  pcVar4 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = -1;
  do {
    _DAT_00744790 = _DAT_00744790 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar4 = "SPARCO";
  _DAT_0074479c = -1;
  uVar2 = 0x53;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447a0 = 0xffffffff;
  _DAT_007447a4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = -1;
  do {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar4 = "STILLEN";
  _DAT_007447b4 = -1;
  do {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447b8 = 0xffffffff;
  _DAT_007447bc = 0xffffffff;
  pcVar4 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = -1;
  do {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar4 = "STREET_GLOW";
  _DAT_007447cc = -1;
  uVar2 = 0x53;
  do {
    _DAT_007447cc = _DAT_007447cc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  pcVar4 = "STREETGLOW";
  _DAT_007447d0 = -1;
  do {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447d4 = 0xffffffff;
  pcVar4 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = -1;
  do {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar4 = "TOUCAN";
  _DAT_007447e4 = -1;
  do {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447e8 = 0xffffffff;
  _DAT_007447ec = 0xffffffff;
  _DAT_007447f0 = 0xffffffff;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar4 = "TOYOTIRES";
  _DAT_007447fc = -1;
  do {
    _DAT_007447fc = _DAT_007447fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  pcVar4 = "TOYO_TIRES";
  _DAT_00744800 = -1;
  do {
    _DAT_00744800 = _DAT_00744800 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  puVar3 = &DAT_006bfe58;
  _DAT_00744804 = -1;
  do {
    _DAT_00744804 = _DAT_00744804 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_TOYO";
  _DAT_00744808 = -1;
  do {
    _DAT_00744808 = _DAT_00744808 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar4 = "TURBONETICS";
  _DAT_00744814 = -1;
  do {
    _DAT_00744814 = _DAT_00744814 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744818 = 0xffffffff;
  _DAT_0074481c = 0xffffffff;
  pcVar4 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = -1;
  do {
    _DAT_00744820 = _DAT_00744820 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar4 = "VENOM";
  _DAT_0074482c = -1;
  do {
    _DAT_0074482c = _DAT_0074482c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744830 = 0xffffffff;
  _DAT_00744834 = 0xffffffff;
  pcVar4 = "VINYL_ICON_VENOM";
  _DAT_00744838 = -1;
  do {
    _DAT_00744838 = _DAT_00744838 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar4 = "WILWOOD";
  _DAT_00744844 = -1;
  do {
    _DAT_00744844 = _DAT_00744844 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar4 = "WILLWOOD";
  _DAT_00744848 = -1;
  do {
    _DAT_00744848 = _DAT_00744848 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074484c = 0xffffffff;
  pcVar4 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = -1;
  do {
    _DAT_00744850 = _DAT_00744850 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar4 = "WOLFRACE";
  _DAT_0074485c = -1;
  do {
    _DAT_0074485c = _DAT_0074485c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar4 = "WOLFRACEWHEELS";
  _DAT_00744860 = -1;
  do {
    _DAT_00744860 = _DAT_00744860 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x59;
  _DAT_00744864 = 0xffffffff;
  _DAT_00744868 = 0xffffffff;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar4 = "YOKOHAMA";
  _DAT_00744874 = -1;
  do {
    _DAT_00744874 = _DAT_00744874 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744878 = 0xffffffff;
  _DAT_0074487c = 0xffffffff;
  pcVar4 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = -1;
  do {
    _DAT_00744880 = _DAT_00744880 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar4 = "ACURA";
  _DAT_0074488c = -1;
  do {
    _DAT_0074488c = _DAT_0074488c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744890 = 0xffffffff;
  _DAT_00744894 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = -1;
  do {
    _DAT_00744898 = _DAT_00744898 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar4 = "DODGE";
  _DAT_007448a4 = -1;
  do {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448a8 = 0xffffffff;
  _DAT_007448ac = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = -1;
  do {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x46;
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar3 = &DAT_006bff64;
  _DAT_007448bc = -1;
  do {
    _DAT_007448bc = _DAT_007448bc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448c0 = 0xffffffff;
  _DAT_007448c4 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = -1;
  do {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar4 = "HONDA";
  _DAT_007448d4 = -1;
  uVar2 = 0x48;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448d8 = 0xffffffff;
  _DAT_007448dc = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = -1;
  do {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar4 = "HYUNDAI";
  _DAT_007448ec = -1;
  uVar2 = 0x48;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448f0 = 0xffffffff;
  _DAT_007448f4 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = -1;
  do {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar4 = "MITSUBISHI";
  _DAT_00744904 = -1;
  uVar2 = 0x4d;
  do {
    _DAT_00744904 = _DAT_00744904 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744908 = 0xffffffff;
  _DAT_0074490c = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = -1;
  do {
    _DAT_00744910 = _DAT_00744910 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar3 = &DAT_006bfff8;
  _DAT_0074491c = -1;
  do {
    _DAT_0074491c = _DAT_0074491c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744920 = 0xffffffff;
  _DAT_00744924 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = -1;
  do {
    _DAT_00744928 = _DAT_00744928 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar4 = "NISSAN";
  _DAT_00744934 = -1;
  do {
    _DAT_00744934 = _DAT_00744934 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744938 = 0xffffffff;
  _DAT_0074493c = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = -1;
  do {
    _DAT_00744940 = _DAT_00744940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar4 = "PEUGEOT";
  _DAT_0074494c = -1;
  do {
    _DAT_0074494c = _DAT_0074494c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744950 = 0xffffffff;
  _DAT_00744954 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = -1;
  do {
    _DAT_00744958 = _DAT_00744958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar3 = &DAT_006c0070;
  _DAT_00744964 = -1;
  do {
    _DAT_00744964 = _DAT_00744964 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744968 = 0xffffffff;
  _DAT_0074496c = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = -1;
  do {
    _DAT_00744970 = _DAT_00744970 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar4 = "VOLKSWAGEN";
  _DAT_0074497c = -1;
  do {
    _DAT_0074497c = _DAT_0074497c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744980 = 0xffffffff;
  _DAT_00744984 = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = -1;
  do {
    _DAT_00744988 = _DAT_00744988 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar3 = &DAT_006c00c8;
  _DAT_00744994 = -1;
  do {
    _DAT_00744994 = _DAT_00744994 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744998 = 0xffffffff;
  _DAT_0074499c = 0xffffffff;
  pcVar4 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = -1;
  do {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar4 = "EUROLITE";
  _DAT_007449ac = -1;
  do {
    _DAT_007449ac = _DAT_007449ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007449b0 = 0xffffffff;
  _DAT_007449b4 = 0xffffffff;
  _DAT_007449b8 = -1;
  pcVar4 = "DECAL_ICON_EUROLITE";
  do {
    _DAT_007449b8 = _DAT_007449b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449bc = "EUROLITE";
  return;
}


// ==== 0x690000 FUN_00690000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690000(byte param_1,int param_2)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  int unaff_EDI;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  uVar2 = 0x4a;
  _DAT_007445ec = in_EAX;
  pcVar3 = "JACKSON_RACING";
  _DAT_007445f0 = unaff_EDI;
  do {
    _DAT_007445f0 = _DAT_007445f0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar3 = "JACKSON";
  _DAT_007445f4 = unaff_EDI;
  do {
    _DAT_007445f4 = _DAT_007445f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = unaff_EDI;
  do {
    _DAT_007445f8 = _DAT_007445f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar4 = &DAT_006bfc14;
  _DAT_00744604 = unaff_EDI;
  do {
    _DAT_00744604 = _DAT_00744604 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar3 = "JSPAMERICA";
  _DAT_00744608 = unaff_EDI;
  do {
    _DAT_00744608 = _DAT_00744608 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074460c = unaff_EDI;
  pcVar3 = "DECAL_ICON_JSP";
  _DAT_00744610 = unaff_EDI;
  do {
    _DAT_00744610 = _DAT_00744610 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar4 = &DAT_006bfc34;
  _DAT_0074461c = unaff_EDI;
  do {
    _DAT_0074461c = _DAT_0074461c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744620 = unaff_EDI;
  _DAT_00744624 = unaff_EDI;
  _DAT_00744628 = unaff_EDI;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar3 = "KENWOOD";
  _DAT_00744634 = unaff_EDI;
  do {
    _DAT_00744634 = _DAT_00744634 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744638 = unaff_EDI;
  _DAT_0074463c = unaff_EDI;
  pcVar3 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = unaff_EDI;
  do {
    _DAT_00744640 = _DAT_00744640 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar3 = "KEYSTONE";
  _DAT_0074464c = unaff_EDI;
  do {
    _DAT_0074464c = _DAT_0074464c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar4 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  do {
    _DAT_00744664 = _DAT_00744664 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar3 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  do {
    _DAT_00744670 = _DAT_00744670 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar4 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  do {
    _DAT_0074467c = _DAT_0074467c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar3 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  do {
    _DAT_00744688 = _DAT_00744688 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar4 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  do {
    _DAT_00744694 = _DAT_00744694 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  puVar4 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  do {
    _DAT_00744698 = _DAT_00744698 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar4 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  do {
    _DAT_007446ac = _DAT_007446ac * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  pcVar3 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  do {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446b4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  do {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar4 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  do {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar3 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  do {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar4 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  do {
    _DAT_007446dc = _DAT_007446dc * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  do {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar3 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  do {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar3 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  do {
    _DAT_00744700 = _DAT_00744700 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar3 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  do {
    _DAT_0074470c = _DAT_0074470c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  puVar4 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  do {
    _DAT_00744710 = _DAT_00744710 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  pcVar3 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  do {
    _DAT_00744714 = _DAT_00744714 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  do {
    _DAT_00744718 = _DAT_00744718 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4f;
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar4 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  do {
    _DAT_00744724 = _DAT_00744724 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar3 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  do {
    _DAT_00744730 = _DAT_00744730 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar5 = &DAT_006c0ca0;
  uVar2 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar3 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  do {
    _DAT_00744748 = _DAT_00744748 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar3 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  do {
    _DAT_00744754 = _DAT_00744754 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  pcVar3 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  do {
    _DAT_00744758 = _DAT_00744758 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074475c = unaff_EDI;
  pcVar3 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  do {
    _DAT_00744760 = _DAT_00744760 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar3 = "SCORPION";
  uVar2 = 0x53;
  _DAT_0074476c = unaff_EDI;
  do {
    _DAT_0074476c = _DAT_0074476c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar3 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  do {
    _DAT_00744778 = _DAT_00744778 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar4 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  do {
    _DAT_00744784 = _DAT_00744784 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar3 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  do {
    _DAT_00744790 = _DAT_00744790 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar3 = "SPARCO";
  uVar2 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  do {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar3 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  do {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar3 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  do {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar3 = "STREET_GLOW";
  uVar2 = 0x53;
  _DAT_007447cc = unaff_EDI;
  do {
    _DAT_007447cc = _DAT_007447cc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  pcVar3 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  do {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447d4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  do {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar3 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  do {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar3 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  do {
    _DAT_007447fc = _DAT_007447fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  pcVar3 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  do {
    _DAT_00744800 = _DAT_00744800 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  puVar4 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  do {
    _DAT_00744804 = _DAT_00744804 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  do {
    _DAT_00744808 = _DAT_00744808 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar3 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  do {
    _DAT_00744814 = _DAT_00744814 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar3 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  do {
    _DAT_00744820 = _DAT_00744820 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar3 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  do {
    _DAT_0074482c = _DAT_0074482c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar3 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  do {
    _DAT_00744838 = _DAT_00744838 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar3 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  do {
    _DAT_00744844 = _DAT_00744844 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar3 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  do {
    _DAT_00744848 = _DAT_00744848 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074484c = unaff_EDI;
  pcVar3 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  do {
    _DAT_00744850 = _DAT_00744850 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar3 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  do {
    _DAT_0074485c = _DAT_0074485c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar3 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  do {
    _DAT_00744860 = _DAT_00744860 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x59;
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar3 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  do {
    _DAT_00744874 = _DAT_00744874 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar3 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  do {
    _DAT_00744880 = _DAT_00744880 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar3 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  do {
    _DAT_0074488c = _DAT_0074488c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  do {
    _DAT_00744898 = _DAT_00744898 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar3 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  do {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  do {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x46;
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar4 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  do {
    _DAT_007448bc = _DAT_007448bc * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  do {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar3 = "HONDA";
  uVar2 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  do {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar3 = "HYUNDAI";
  uVar2 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  do {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar3 = "MITSUBISHI";
  uVar2 = 0x4d;
  _DAT_00744904 = unaff_EDI;
  do {
    _DAT_00744904 = _DAT_00744904 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  do {
    _DAT_00744910 = _DAT_00744910 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar4 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  do {
    _DAT_0074491c = _DAT_0074491c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  do {
    _DAT_00744928 = _DAT_00744928 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar3 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  do {
    _DAT_00744934 = _DAT_00744934 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  do {
    _DAT_00744940 = _DAT_00744940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar3 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  do {
    _DAT_0074494c = _DAT_0074494c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  do {
    _DAT_00744958 = _DAT_00744958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar4 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  do {
    _DAT_00744964 = _DAT_00744964 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  do {
    _DAT_00744970 = _DAT_00744970 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar3 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  do {
    _DAT_0074497c = _DAT_0074497c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  do {
    _DAT_00744988 = _DAT_00744988 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar4 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  do {
    _DAT_00744994 = _DAT_00744994 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  do {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar3 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  do {
    _DAT_007449ac = _DAT_007449ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_EUROLITE";
  do {
    unaff_EDI = unaff_EDI * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


// ==== 0x690068 FUN_00690068

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690068(byte param_1)

{
  byte *pbVar1;
  undefined4 in_EAX;
  uint uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  int unaff_EDI;
  bool in_ZF;
  
  _DAT_007445f4 = in_EAX;
  pcVar3 = "DECAL_ICON_JACKSON";
  _DAT_007445f8 = unaff_EDI;
  if (!in_ZF) {
    do {
      _DAT_007445f8 = _DAT_007445f8 * 0x21 + (uint)param_1;
      param_1 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (param_1 != 0);
  }
  uVar2 = 0x4a;
  _DAT_007445fc = "JACKSONRACING";
  _DAT_00744600 = 0x1c;
  puVar4 = &DAT_006bfc14;
  _DAT_00744604 = unaff_EDI;
  do {
    _DAT_00744604 = _DAT_00744604 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4a;
  pcVar3 = "JSPAMERICA";
  _DAT_00744608 = unaff_EDI;
  do {
    _DAT_00744608 = _DAT_00744608 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074460c = unaff_EDI;
  pcVar3 = "DECAL_ICON_JSP";
  _DAT_00744610 = unaff_EDI;
  do {
    _DAT_00744610 = _DAT_00744610 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744614 = &DAT_006bfc14;
  _DAT_00744618 = 0x1d;
  puVar4 = &DAT_006bfc34;
  _DAT_0074461c = unaff_EDI;
  do {
    _DAT_0074461c = _DAT_0074461c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744620 = unaff_EDI;
  _DAT_00744624 = unaff_EDI;
  _DAT_00744628 = unaff_EDI;
  _DAT_0074462c = &DAT_006bfc34;
  _DAT_00744630 = 0x1e;
  pcVar3 = "KENWOOD";
  _DAT_00744634 = unaff_EDI;
  do {
    _DAT_00744634 = _DAT_00744634 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744638 = unaff_EDI;
  _DAT_0074463c = unaff_EDI;
  pcVar3 = "DECAL_ICON_KENWOOD";
  _DAT_00744640 = unaff_EDI;
  do {
    _DAT_00744640 = _DAT_00744640 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744644 = "KENWOOD";
  _DAT_00744648 = 0x1f;
  pcVar3 = "KEYSTONE";
  _DAT_0074464c = unaff_EDI;
  do {
    _DAT_0074464c = _DAT_0074464c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar4 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  do {
    _DAT_00744664 = _DAT_00744664 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar3 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  do {
    _DAT_00744670 = _DAT_00744670 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar4 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  do {
    _DAT_0074467c = _DAT_0074467c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar3 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  do {
    _DAT_00744688 = _DAT_00744688 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar4 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  do {
    _DAT_00744694 = _DAT_00744694 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  puVar4 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  do {
    _DAT_00744698 = _DAT_00744698 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar4 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  do {
    _DAT_007446ac = _DAT_007446ac * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  pcVar3 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  do {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446b4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  do {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar4 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  do {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar3 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  do {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar4 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  do {
    _DAT_007446dc = _DAT_007446dc * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  do {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar3 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  do {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar3 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  do {
    _DAT_00744700 = _DAT_00744700 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar3 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  do {
    _DAT_0074470c = _DAT_0074470c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  puVar4 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  do {
    _DAT_00744710 = _DAT_00744710 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  pcVar3 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  do {
    _DAT_00744714 = _DAT_00744714 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  do {
    _DAT_00744718 = _DAT_00744718 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4f;
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar4 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  do {
    _DAT_00744724 = _DAT_00744724 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar3 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  do {
    _DAT_00744730 = _DAT_00744730 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar5 = &DAT_006c0ca0;
  uVar2 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar3 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  do {
    _DAT_00744748 = _DAT_00744748 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar3 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  do {
    _DAT_00744754 = _DAT_00744754 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  pcVar3 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  do {
    _DAT_00744758 = _DAT_00744758 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074475c = unaff_EDI;
  pcVar3 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  do {
    _DAT_00744760 = _DAT_00744760 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar3 = "SCORPION";
  uVar2 = 0x53;
  _DAT_0074476c = unaff_EDI;
  do {
    _DAT_0074476c = _DAT_0074476c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar3 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  do {
    _DAT_00744778 = _DAT_00744778 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar4 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  do {
    _DAT_00744784 = _DAT_00744784 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar3 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  do {
    _DAT_00744790 = _DAT_00744790 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar3 = "SPARCO";
  uVar2 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  do {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar3 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  do {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar3 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  do {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar3 = "STREET_GLOW";
  uVar2 = 0x53;
  _DAT_007447cc = unaff_EDI;
  do {
    _DAT_007447cc = _DAT_007447cc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  pcVar3 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  do {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447d4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  do {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar3 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  do {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar3 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  do {
    _DAT_007447fc = _DAT_007447fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  pcVar3 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  do {
    _DAT_00744800 = _DAT_00744800 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  puVar4 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  do {
    _DAT_00744804 = _DAT_00744804 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar3 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  do {
    _DAT_00744808 = _DAT_00744808 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar3 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  do {
    _DAT_00744814 = _DAT_00744814 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar3 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  do {
    _DAT_00744820 = _DAT_00744820 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar3 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  do {
    _DAT_0074482c = _DAT_0074482c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar3 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  do {
    _DAT_00744838 = _DAT_00744838 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar3 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  do {
    _DAT_00744844 = _DAT_00744844 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar3 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  do {
    _DAT_00744848 = _DAT_00744848 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074484c = unaff_EDI;
  pcVar3 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  do {
    _DAT_00744850 = _DAT_00744850 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar3 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  do {
    _DAT_0074485c = _DAT_0074485c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar3 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  do {
    _DAT_00744860 = _DAT_00744860 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x59;
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar3 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  do {
    _DAT_00744874 = _DAT_00744874 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar3 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  do {
    _DAT_00744880 = _DAT_00744880 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar3 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  do {
    _DAT_0074488c = _DAT_0074488c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  do {
    _DAT_00744898 = _DAT_00744898 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar3 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  do {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  do {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x46;
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar4 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  do {
    _DAT_007448bc = _DAT_007448bc * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  do {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar3 = "HONDA";
  uVar2 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  do {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar3 = "HYUNDAI";
  uVar2 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  do {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar3 = "MITSUBISHI";
  uVar2 = 0x4d;
  _DAT_00744904 = unaff_EDI;
  do {
    _DAT_00744904 = _DAT_00744904 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  do {
    _DAT_00744910 = _DAT_00744910 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar4 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  do {
    _DAT_0074491c = _DAT_0074491c * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  do {
    _DAT_00744928 = _DAT_00744928 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar3 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  do {
    _DAT_00744934 = _DAT_00744934 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  do {
    _DAT_00744940 = _DAT_00744940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar3 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  do {
    _DAT_0074494c = _DAT_0074494c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  do {
    _DAT_00744958 = _DAT_00744958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar4 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  do {
    _DAT_00744964 = _DAT_00744964 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  do {
    _DAT_00744970 = _DAT_00744970 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar3 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  do {
    _DAT_0074497c = _DAT_0074497c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  do {
    _DAT_00744988 = _DAT_00744988 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar4 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  do {
    _DAT_00744994 = _DAT_00744994 * 0x21 + uVar2;
    pbVar1 = puVar4 + 1;
    uVar2 = (uint)*pbVar1;
    puVar4 = puVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar3 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  do {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar3 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  do {
    _DAT_007449ac = _DAT_007449ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar3 = "DECAL_ICON_EUROLITE";
  do {
    unaff_EDI = unaff_EDI * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar3 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar3 = pcVar3 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


// ==== 0x690200 FUN_00690200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00690200(byte param_1,int param_2)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined *puVar5;
  int unaff_EDI;
  
  do {
    in_EAX = in_EAX * 0x21 + (uint)param_1;
    param_1 = *(byte *)(param_2 + 1);
    param_2 = param_2 + 1;
  } while (param_1 != 0);
  uVar2 = 0x4b;
  _DAT_0074464c = in_EAX;
  _DAT_00744650 = unaff_EDI;
  _DAT_00744654 = unaff_EDI;
  _DAT_00744658 = unaff_EDI;
  _DAT_0074465c = "KEYSTONE";
  _DAT_00744660 = 0x20;
  puVar3 = &DAT_006bfc60;
  _DAT_00744664 = unaff_EDI;
  do {
    _DAT_00744664 = _DAT_00744664 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744668 = unaff_EDI;
  _DAT_0074466c = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONI";
  _DAT_00744670 = unaff_EDI;
  do {
    _DAT_00744670 = _DAT_00744670 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_00744674 = &DAT_006bfc60;
  _DAT_00744678 = 0x21;
  puVar3 = &DAT_006bfc78;
  _DAT_0074467c = unaff_EDI;
  do {
    _DAT_0074467c = _DAT_0074467c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744680 = unaff_EDI;
  _DAT_00744684 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KONIG";
  _DAT_00744688 = unaff_EDI;
  do {
    _DAT_00744688 = _DAT_00744688 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074468c = &DAT_006bfc78;
  _DAT_00744690 = 0x22;
  puVar3 = &DAT_006bfc94;
  _DAT_00744694 = unaff_EDI;
  do {
    _DAT_00744694 = _DAT_00744694 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  puVar3 = &DAT_006bfc9c;
  _DAT_00744698 = unaff_EDI;
  do {
    _DAT_00744698 = _DAT_00744698 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_0074469c = unaff_EDI;
  _DAT_007446a0 = unaff_EDI;
  _DAT_007446a4 = &DAT_006bfc94;
  _DAT_007446a8 = 0x23;
  puVar3 = &DAT_006bfca4;
  _DAT_007446ac = unaff_EDI;
  do {
    _DAT_007446ac = _DAT_007446ac * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  pcVar4 = "KVRPERFORMANCE";
  _DAT_007446b0 = unaff_EDI;
  do {
    _DAT_007446b0 = _DAT_007446b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_KVR";
  _DAT_007446b8 = unaff_EDI;
  do {
    _DAT_007446b8 = _DAT_007446b8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4b;
  _DAT_007446bc = &DAT_006bfca4;
  _DAT_007446c0 = 0x24;
  puVar3 = &DAT_006bfcc8;
  _DAT_007446c4 = unaff_EDI;
  do {
    _DAT_007446c4 = _DAT_007446c4 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446c8 = unaff_EDI;
  _DAT_007446cc = unaff_EDI;
  pcVar4 = "DECAL_ICON_KYB";
  _DAT_007446d0 = unaff_EDI;
  do {
    _DAT_007446d0 = _DAT_007446d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_007446d4 = &DAT_006bfcc8;
  _DAT_007446d8 = 0x25;
  puVar3 = &DAT_006bfcdc;
  _DAT_007446dc = unaff_EDI;
  do {
    _DAT_007446dc = _DAT_007446dc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446e0 = unaff_EDI;
  _DAT_007446e4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_MOMO";
  _DAT_007446e8 = unaff_EDI;
  do {
    _DAT_007446e8 = _DAT_007446e8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_007446ec = &DAT_006bfcdc;
  _DAT_007446f0 = 0x26;
  pcVar4 = "NEUSPEED";
  _DAT_007446f4 = unaff_EDI;
  do {
    _DAT_007446f4 = _DAT_007446f4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007446f8 = unaff_EDI;
  _DAT_007446fc = unaff_EDI;
  pcVar4 = "DECAL_ICON_NEUSPEED";
  _DAT_00744700 = unaff_EDI;
  do {
    _DAT_00744700 = _DAT_00744700 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_00744704 = "NEUSPEED";
  _DAT_00744708 = 0x27;
  pcVar4 = "NITROUS_EXPRESS";
  _DAT_0074470c = unaff_EDI;
  do {
    _DAT_0074470c = _DAT_0074470c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  puVar3 = &DAT_006bfd24;
  _DAT_00744710 = unaff_EDI;
  do {
    _DAT_00744710 = _DAT_00744710 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  pcVar4 = "NITROUSEXPRESS";
  _DAT_00744714 = unaff_EDI;
  do {
    _DAT_00744714 = _DAT_00744714 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_NX";
  _DAT_00744718 = unaff_EDI;
  do {
    _DAT_00744718 = _DAT_00744718 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4f;
  _DAT_0074471c = "NITROUS_EXPRESS";
  _DAT_00744720 = 0x28;
  puVar3 = &DAT_006bfd48;
  _DAT_00744724 = unaff_EDI;
  do {
    _DAT_00744724 = _DAT_00744724 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744728 = unaff_EDI;
  _DAT_0074472c = unaff_EDI;
  pcVar4 = "DECAL_ICON_OZ";
  _DAT_00744730 = unaff_EDI;
  do {
    _DAT_00744730 = _DAT_00744730 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744734 = &DAT_006bfd48;
  _DAT_00744738 = 0x29;
  puVar5 = &DAT_006c0ca0;
  uVar2 = 0x50;
  _DAT_0074473c = unaff_EDI;
  do {
    _DAT_0074473c = _DAT_0074473c * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744740 = unaff_EDI;
  _DAT_00744744 = unaff_EDI;
  pcVar4 = "DECAL_ICON_PIAA";
  _DAT_00744748 = unaff_EDI;
  do {
    _DAT_00744748 = _DAT_00744748 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_0074474c = &DAT_006c0ca0;
  _DAT_00744750 = 0x2a;
  pcVar4 = "PLASMAGLOW";
  _DAT_00744754 = unaff_EDI;
  do {
    _DAT_00744754 = _DAT_00744754 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  pcVar4 = "PLASMA_GLOW";
  _DAT_00744758 = unaff_EDI;
  do {
    _DAT_00744758 = _DAT_00744758 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074475c = unaff_EDI;
  pcVar4 = "DECAL_ICON_PLASMAGLOW";
  _DAT_00744760 = unaff_EDI;
  do {
    _DAT_00744760 = _DAT_00744760 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744764 = "PLASMAGLOW";
  _DAT_00744768 = 0x2b;
  pcVar4 = "SCORPION";
  uVar2 = 0x53;
  _DAT_0074476c = unaff_EDI;
  do {
    _DAT_0074476c = _DAT_0074476c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744770 = unaff_EDI;
  _DAT_00744774 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SCORPION";
  _DAT_00744778 = unaff_EDI;
  do {
    _DAT_00744778 = _DAT_00744778 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074477c = "SCORPION";
  _DAT_00744780 = 0x2c;
  puVar3 = &DAT_006bfdbc;
  _DAT_00744784 = unaff_EDI;
  do {
    _DAT_00744784 = _DAT_00744784 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744788 = unaff_EDI;
  _DAT_0074478c = unaff_EDI;
  pcVar4 = "DECAL_ICON_SKUNK2";
  _DAT_00744790 = unaff_EDI;
  do {
    _DAT_00744790 = _DAT_00744790 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_00744794 = &DAT_006bfdbc;
  _DAT_00744798 = 0x2d;
  pcVar4 = "SPARCO";
  uVar2 = 0x53;
  _DAT_0074479c = unaff_EDI;
  do {
    _DAT_0074479c = _DAT_0074479c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447a0 = unaff_EDI;
  _DAT_007447a4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_SPARCO";
  _DAT_007447a8 = unaff_EDI;
  do {
    _DAT_007447a8 = _DAT_007447a8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_007447ac = "SPARCO";
  _DAT_007447b0 = 0x2e;
  pcVar4 = "STILLEN";
  _DAT_007447b4 = unaff_EDI;
  do {
    _DAT_007447b4 = _DAT_007447b4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447b8 = unaff_EDI;
  _DAT_007447bc = unaff_EDI;
  pcVar4 = "DECAL_ICON_STILLEN";
  _DAT_007447c0 = unaff_EDI;
  do {
    _DAT_007447c0 = _DAT_007447c0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007447c4 = "STILLEN";
  _DAT_007447c8 = 0x2f;
  pcVar4 = "STREET_GLOW";
  uVar2 = 0x53;
  _DAT_007447cc = unaff_EDI;
  do {
    _DAT_007447cc = _DAT_007447cc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  pcVar4 = "STREETGLOW";
  _DAT_007447d0 = unaff_EDI;
  do {
    _DAT_007447d0 = _DAT_007447d0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007447d4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_STREETGLOW";
  _DAT_007447d8 = unaff_EDI;
  do {
    _DAT_007447d8 = _DAT_007447d8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447dc = "STREETGLOW";
  _DAT_007447e0 = 0x30;
  pcVar4 = "TOUCAN";
  _DAT_007447e4 = unaff_EDI;
  do {
    _DAT_007447e4 = _DAT_007447e4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_007447e8 = unaff_EDI;
  _DAT_007447ec = unaff_EDI;
  _DAT_007447f0 = unaff_EDI;
  _DAT_007447f4 = "TOUCAN";
  _DAT_007447f8 = 0x31;
  pcVar4 = "TOYOTIRES";
  _DAT_007447fc = unaff_EDI;
  do {
    _DAT_007447fc = _DAT_007447fc * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  pcVar4 = "TOYO_TIRES";
  _DAT_00744800 = unaff_EDI;
  do {
    _DAT_00744800 = _DAT_00744800 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  puVar3 = &DAT_006bfe58;
  _DAT_00744804 = unaff_EDI;
  do {
    _DAT_00744804 = _DAT_00744804 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  pcVar4 = "DECAL_ICON_TOYO";
  _DAT_00744808 = unaff_EDI;
  do {
    _DAT_00744808 = _DAT_00744808 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074480c = &DAT_006bfe58;
  _DAT_00744810 = 0x32;
  pcVar4 = "TURBONETICS";
  _DAT_00744814 = unaff_EDI;
  do {
    _DAT_00744814 = _DAT_00744814 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744818 = unaff_EDI;
  _DAT_0074481c = unaff_EDI;
  pcVar4 = "DECAL_ICON_TURBONETICS";
  _DAT_00744820 = unaff_EDI;
  do {
    _DAT_00744820 = _DAT_00744820 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744824 = "TURBONETICS";
  _DAT_00744828 = 0x33;
  pcVar4 = "VENOM";
  _DAT_0074482c = unaff_EDI;
  do {
    _DAT_0074482c = _DAT_0074482c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744830 = unaff_EDI;
  _DAT_00744834 = unaff_EDI;
  pcVar4 = "VINYL_ICON_VENOM";
  _DAT_00744838 = unaff_EDI;
  do {
    _DAT_00744838 = _DAT_00744838 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_0074483c = "VENOM";
  _DAT_00744840 = 0x34;
  pcVar4 = "WILWOOD";
  _DAT_00744844 = unaff_EDI;
  do {
    _DAT_00744844 = _DAT_00744844 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar4 = "WILLWOOD";
  _DAT_00744848 = unaff_EDI;
  do {
    _DAT_00744848 = _DAT_00744848 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074484c = unaff_EDI;
  pcVar4 = "DECAL_ICON_WILWOOD";
  _DAT_00744850 = unaff_EDI;
  do {
    _DAT_00744850 = _DAT_00744850 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  _DAT_00744854 = "WILWOOD";
  _DAT_00744858 = 0x35;
  pcVar4 = "WOLFRACE";
  _DAT_0074485c = unaff_EDI;
  do {
    _DAT_0074485c = _DAT_0074485c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x57;
  pcVar4 = "WOLFRACEWHEELS";
  _DAT_00744860 = unaff_EDI;
  do {
    _DAT_00744860 = _DAT_00744860 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x59;
  _DAT_00744864 = unaff_EDI;
  _DAT_00744868 = unaff_EDI;
  _DAT_0074486c = "WOLFRACE";
  _DAT_00744870 = 0x36;
  pcVar4 = "YOKOHAMA";
  _DAT_00744874 = unaff_EDI;
  do {
    _DAT_00744874 = _DAT_00744874 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_00744878 = unaff_EDI;
  _DAT_0074487c = unaff_EDI;
  pcVar4 = "DECAL_ICON_YOKOHAMA";
  _DAT_00744880 = unaff_EDI;
  do {
    _DAT_00744880 = _DAT_00744880 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x41;
  _DAT_00744884 = "YOKOHAMA";
  _DAT_00744888 = 0x37;
  pcVar4 = "ACURA";
  _DAT_0074488c = unaff_EDI;
  do {
    _DAT_0074488c = _DAT_0074488c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744890 = unaff_EDI;
  _DAT_00744894 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_ACURA";
  _DAT_00744898 = unaff_EDI;
  do {
    _DAT_00744898 = _DAT_00744898 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_0074489c = "ACURA";
  _DAT_007448a0 = 0x38;
  pcVar4 = "DODGE";
  _DAT_007448a4 = unaff_EDI;
  do {
    _DAT_007448a4 = _DAT_007448a4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448a8 = unaff_EDI;
  _DAT_007448ac = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_DODGE";
  _DAT_007448b0 = unaff_EDI;
  do {
    _DAT_007448b0 = _DAT_007448b0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x46;
  _DAT_007448b4 = "DODGE";
  _DAT_007448b8 = 0x39;
  puVar3 = &DAT_006bff64;
  _DAT_007448bc = unaff_EDI;
  do {
    _DAT_007448bc = _DAT_007448bc * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448c0 = unaff_EDI;
  _DAT_007448c4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_FORD";
  _DAT_007448c8 = unaff_EDI;
  do {
    _DAT_007448c8 = _DAT_007448c8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448cc = &DAT_006bff64;
  _DAT_007448d0 = 0x3a;
  pcVar4 = "HONDA";
  uVar2 = 0x48;
  _DAT_007448d4 = unaff_EDI;
  do {
    _DAT_007448d4 = _DAT_007448d4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448d8 = unaff_EDI;
  _DAT_007448dc = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HONDA";
  _DAT_007448e0 = unaff_EDI;
  do {
    _DAT_007448e0 = _DAT_007448e0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448e4 = "HONDA";
  _DAT_007448e8 = 0x3b;
  pcVar4 = "HYUNDAI";
  uVar2 = 0x48;
  _DAT_007448ec = unaff_EDI;
  do {
    _DAT_007448ec = _DAT_007448ec * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_007448f0 = unaff_EDI;
  _DAT_007448f4 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_HYUNDAI";
  _DAT_007448f8 = unaff_EDI;
  do {
    _DAT_007448f8 = _DAT_007448f8 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007448fc = "HYUNDAI";
  _DAT_00744900 = 0x3c;
  pcVar4 = "MITSUBISHI";
  uVar2 = 0x4d;
  _DAT_00744904 = unaff_EDI;
  do {
    _DAT_00744904 = _DAT_00744904 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744908 = unaff_EDI;
  _DAT_0074490c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MITSUBISHI";
  _DAT_00744910 = unaff_EDI;
  do {
    _DAT_00744910 = _DAT_00744910 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4d;
  _DAT_00744914 = "MITSUBISHI";
  _DAT_00744918 = 0x3d;
  puVar3 = &DAT_006bfff8;
  _DAT_0074491c = unaff_EDI;
  do {
    _DAT_0074491c = _DAT_0074491c * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744920 = unaff_EDI;
  _DAT_00744924 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_MAZDA";
  _DAT_00744928 = unaff_EDI;
  do {
    _DAT_00744928 = _DAT_00744928 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x4e;
  _DAT_0074492c = &DAT_006bfff8;
  _DAT_00744930 = 0x3e;
  pcVar4 = "NISSAN";
  _DAT_00744934 = unaff_EDI;
  do {
    _DAT_00744934 = _DAT_00744934 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744938 = unaff_EDI;
  _DAT_0074493c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_NISSAN";
  _DAT_00744940 = unaff_EDI;
  do {
    _DAT_00744940 = _DAT_00744940 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x50;
  _DAT_00744944 = "NISSAN";
  _DAT_00744948 = 0x3f;
  pcVar4 = "PEUGEOT";
  _DAT_0074494c = unaff_EDI;
  do {
    _DAT_0074494c = _DAT_0074494c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744950 = unaff_EDI;
  _DAT_00744954 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_PEUGEOT";
  _DAT_00744958 = unaff_EDI;
  do {
    _DAT_00744958 = _DAT_00744958 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x53;
  _DAT_0074495c = "PEUGEOT";
  _DAT_00744960 = 0x40;
  puVar3 = &DAT_006c0070;
  _DAT_00744964 = unaff_EDI;
  do {
    _DAT_00744964 = _DAT_00744964 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744968 = unaff_EDI;
  _DAT_0074496c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_SUBARU";
  _DAT_00744970 = unaff_EDI;
  do {
    _DAT_00744970 = _DAT_00744970 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x56;
  _DAT_00744974 = &DAT_006c0070;
  _DAT_00744978 = 0x41;
  pcVar4 = "VOLKSWAGEN";
  _DAT_0074497c = unaff_EDI;
  do {
    _DAT_0074497c = _DAT_0074497c * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744980 = unaff_EDI;
  _DAT_00744984 = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_VOLKSWAGEN";
  _DAT_00744988 = unaff_EDI;
  do {
    _DAT_00744988 = _DAT_00744988 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x54;
  _DAT_0074498c = "VOLKSWAGEN";
  _DAT_00744990 = 0x42;
  puVar3 = &DAT_006c00c8;
  _DAT_00744994 = unaff_EDI;
  do {
    _DAT_00744994 = _DAT_00744994 * 0x21 + uVar2;
    pbVar1 = puVar3 + 1;
    uVar2 = (uint)*pbVar1;
    puVar3 = puVar3 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x43;
  _DAT_00744998 = unaff_EDI;
  _DAT_0074499c = unaff_EDI;
  pcVar4 = "CARSELECT_MANUFACTURER_TOYOTA";
  _DAT_007449a0 = unaff_EDI;
  do {
    _DAT_007449a0 = _DAT_007449a0 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x45;
  _DAT_007449a4 = &DAT_006c00c8;
  _DAT_007449a8 = 0x43;
  pcVar4 = "EUROLITE";
  _DAT_007449ac = unaff_EDI;
  do {
    _DAT_007449ac = _DAT_007449ac * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  uVar2 = 0x44;
  _DAT_007449b0 = unaff_EDI;
  _DAT_007449b4 = unaff_EDI;
  pcVar4 = "DECAL_ICON_EUROLITE";
  do {
    unaff_EDI = unaff_EDI * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  _DAT_007449b8 = unaff_EDI;
  _DAT_007449bc = "EUROLITE";
  return;
}


