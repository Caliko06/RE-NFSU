// ==== 0x671007 FUN_00671007

void FUN_00671007(void)

{
  FUN_00671fa9();
  return;
}


// ==== 0x67100d _atexit

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


// ==== 0x67101f _sprintf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 _sprintf(char *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  FILE local_24;
  
  local_24._cnt = 0x7fffffff;
  local_24._flag = 0x42;
  local_24._base = param_1;
  local_24._ptr = param_1;
  uVar1 = FUN_0067604e(&local_24,param_2,&stack0x0000000c);
  if (param_1 != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return uVar1;
}


// ==== 0x671077 _vsprintf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 _vsprintf(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  FILE local_24;
  
  local_24._cnt = 0x7fffffff;
  local_24._flag = 0x42;
  local_24._base = param_1;
  local_24._ptr = param_1;
  uVar1 = FUN_0067604e(&local_24,param_2,param_3);
  if (param_1 != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return uVar1;
}


// ==== 0x6710ce _sscanf

/* Library Function - Single Match
    _sscanf
   
   Library: Visual Studio 2003 Release */

int __cdecl _sscanf(char *_Src,char *_Format,...)

{
  int iVar1;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_18 = 0x49;
  local_1c = _Src;
  local_24 = _Src;
  local_20 = _strlen(_Src);
  iVar1 = FUN_006767f9(&local_24,_Format,&stack0x0000000c);
  return iVar1;
}


// ==== 0x671102 _free

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl _free(void *_Memory)

{
  int iVar1;
  
  if (_Memory != (void *)0x0) {
    if (DAT_00793220 == 3) {
      __lock(4);
      iVar1 = ___sbh_find_block(_Memory);
      if (iVar1 != 0) {
        ___sbh_free_block(iVar1,_Memory);
      }
      FUN_00671155();
      if (iVar1 != 0) {
        return;
      }
    }
    HeapFree(DAT_0079321c,0,_Memory);
  }
  return;
}


// ==== 0x671155 FUN_00671155

void FUN_00671155(void)

{
  __unlock(4);
  return;
}


// ==== 0x671173 __heap_alloc

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl __heap_alloc(size_t _Size)

{
  void *pvVar1;
  LPVOID pvVar2;
  
  if ((DAT_00793220 == 3) && (_Size <= DAT_0079320c)) {
    __lock(4);
    pvVar1 = (void *)___sbh_alloc_block(_Size);
    FUN_006711e5();
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
  }
  if (_Size == 0) {
    _Size = 1;
  }
  if (DAT_00793220 != 1) {
    _Size = _Size + 0xf & 0xfffffff0;
  }
  pvVar2 = HeapAlloc(DAT_0079321c,0,_Size);
  return pvVar2;
}


// ==== 0x6711e2 FUN_006711e2

void FUN_006711e2(void)

{
  __unlock(4);
  return;
}


// ==== 0x6711e5 FUN_006711e5

void FUN_006711e5(void)

{
  __unlock(4);
  return;
}


// ==== 0x6711ee __nh_malloc

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = __heap_alloc(_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ==== 0x67121a _malloc

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00717d74);
  return pvVar1;
}


// ==== 0x67122c __flush

/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 2003 Release */

int __cdecl __flush(FILE *_File)

{
  uint uVar1;
  int iVar2;
  uint _MaxCharCount;
  
  iVar2 = 0;
  if ((((byte)_File->_flag & 3) == 2) && ((_File->_flag & 0x108U) != 0)) {
    _MaxCharCount = (int)_File->_ptr - (int)_File->_base;
    if (0 < (int)_MaxCharCount) {
      uVar1 = __write(_File->_file,_File->_base,_MaxCharCount);
      if (uVar1 == _MaxCharCount) {
        if ((char)_File->_flag < '\0') {
          _File->_flag = _File->_flag & 0xfffffffd;
        }
      }
      else {
        _File->_flag = _File->_flag | 0x20;
        iVar2 = -1;
      }
    }
  }
  _File->_cnt = 0;
  _File->_ptr = _File->_base;
  return iVar2;
}


// ==== 0x671289 __fflush_lk

/* Library Function - Single Match
    __fflush_lk
   
   Library: Visual Studio 2003 Release */

int __fflush_lk(FILE *param_1)

{
  int iVar1;
  
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((param_1->_flag & 0x4000) != 0) {
    iVar1 = __commit(param_1->_file);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}


// ==== 0x6712b7 flsall

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2003 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  int iVar1;
  int _Index;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_24 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00794360; _Index = _Index + 1) {
    _File = *(void **)(DAT_00793350 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00793350 + _Index * 4);
      if ((*(uint *)(iVar1 + 0xc) & 0x83) != 0) {
        if (param_1 == 1) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 != -1) {
            local_20 = local_20 + 1;
          }
        }
        else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 == -1) {
            local_24 = -1;
          }
        }
      }
      FUN_00671357();
    }
  }
  FUN_00671383();
  if (param_1 != 1) {
    local_20 = local_24;
  }
  return local_20;
}


// ==== 0x671352 FUN_00671352

void FUN_00671352(void)

{
  int unaff_EBP;
  
  __unlock_file2(*(int *)(unaff_EBP + -0x24),
                 *(void **)(DAT_00793350 + *(int *)(unaff_EBP + -0x24) * 4));
  return;
}


// ==== 0x671357 FUN_00671357

void FUN_00671357(void)

{
  int unaff_ESI;
  
  __unlock_file2(unaff_ESI,*(void **)(DAT_00793350 + unaff_ESI * 4));
  return;
}


// ==== 0x671383 FUN_00671383

void FUN_00671383(void)

{
  __unlock(1);
  return;
}


// ==== 0x67138c __flushall

/* Library Function - Single Match
    __flushall
   
   Library: Visual Studio 2003 Release */

int __cdecl __flushall(void)

{
  int iVar1;
  
  iVar1 = flsall(1);
  return iVar1;
}


// ==== 0x671395 FUN_00671395

uint FUN_00671395(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  LPCSTR _LpSrcStr;
  int iVar3;
  BOOL unaff_EDI;
  undefined4 local_8;
  
  uVar1 = param_2;
  iVar3 = param_1;
  if ((*(int *)(param_1 + 0x14) == 0) || ((*(int *)(param_1 + 0x24) != 0 && (param_2 < 0x80)))) {
    if ((0x40 < (int)param_2) && ((int)param_2 < 0x5b)) {
      return param_2 + 0x20;
    }
  }
  else {
    if (param_2 < 0x100) {
      if (*(int *)(param_1 + 0x28) < 2) {
        uVar2 = *(byte *)(*(int *)(param_1 + 0x48) + param_2 * 2) & 1;
      }
      else {
        uVar2 = _isctype(param_1,param_2,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((*(byte *)(*(int *)(iVar3 + 0x48) + 1 + ((int)uVar1 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      _LpSrcStr = (LPCSTR)0x1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      _LpSrcStr = (LPCSTR)0x2;
    }
    iVar3 = ___crtLCMapStringA(*(_locale_t *)(iVar3 + 0x14),(LPCWSTR)0x100,(DWORD)&param_1,_LpSrcStr
                               ,(int)&local_8,(LPSTR)0x3,*(int *)(iVar3 + 4),1,unaff_EDI);
    if (iVar3 != 0) {
      if (iVar3 != 1) {
        return (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
      }
      return local_8 & 0xff;
    }
  }
  return uVar1;
}


// ==== 0x67145d _tolower

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cdecl _tolower(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = FUN_00671395(ptVar2,_C);
  return iVar3;
}


// ==== 0x67147f _printf_67147f

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _printf_67147f(char *_Format,...)

{
  int _Flag;
  int iVar1;
  
  __lock_file2(1,&DAT_006eb1e0);
  _Flag = __stbuf((FILE *)&DAT_006eb1e0);
  iVar1 = FUN_0067604e(&DAT_006eb1e0,_Format,&stack0x00000008);
  __ftbuf(_Flag,(FILE *)&DAT_006eb1e0);
  FUN_006714da();
  return iVar1;
}


// ==== 0x6714d5 FUN_006714d5

void FUN_006714d5(void)

{
  __unlock_file2(1,&DAT_006eb1e0);
  return;
}


// ==== 0x6714da FUN_006714da

void FUN_006714da(void)

{
  void *unaff_ESI;
  
  __unlock_file2(1,unaff_ESI);
  return;
}


// ==== 0x6714e5 __fsopen

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl __fsopen(char *_Filename,char *_Mode,int _ShFlag)

{
  FILE *pFVar1;
  undefined4 *puVar2;
  
  pFVar1 = __getstream();
  if (pFVar1 == (FILE *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x18;
    pFVar1 = (FILE *)0x0;
  }
  else {
    pFVar1 = __openfile(_Filename,_Mode,_ShFlag,pFVar1);
    FUN_00671537();
  }
  return pFVar1;
}


// ==== 0x671537 FUN_00671537

void FUN_00671537(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + -0x1c));
  return;
}


// ==== 0x671541 _fopen

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void _fopen(char *param_1,char *param_2)

{
  __fsopen(param_1,param_2,0x40);
  return;
}


// ==== 0x671554 __fread_lk

/* Library Function - Single Match
    __fread_lk
   
   Library: Visual Studio 2003 Release */

uint __fread_lk(undefined1 *param_1,uint param_2,uint param_3,FILE *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint _Size;
  uint local_8;
  
  uVar4 = param_2 * param_3;
  if (uVar4 == 0) {
    param_3 = 0;
  }
  else {
    puVar3 = param_1;
    param_1 = (undefined1 *)uVar4;
    if ((param_4->_flag & 0x10c) == 0) {
      local_8 = 0x1000;
    }
    else {
      local_8 = param_4->_bufsiz;
    }
    do {
      if (((param_4->_flag & 0x10c) == 0) || (uVar1 = param_4->_cnt, uVar1 == 0)) {
        if (param_1 < local_8) {
          iVar2 = __filbuf(param_4);
          if (iVar2 == -1) goto LAB_0067162b;
          *puVar3 = (char)iVar2;
          local_8 = param_4->_bufsiz;
          puVar3 = puVar3 + 1;
          param_1 = (undefined1 *)((int)param_1 - 1);
        }
        else {
          uVar1 = (uint)param_1;
          if (local_8 != 0) {
            uVar1 = (int)param_1 - (uint)param_1 % local_8;
          }
          iVar2 = __read(param_4->_file,puVar3,uVar1);
          if (iVar2 == 0) {
            param_4->_flag = param_4->_flag | 0x10;
LAB_0067162b:
            return (uVar4 - (int)param_1) / param_2;
          }
          if (iVar2 == -1) {
            param_4->_flag = param_4->_flag | 0x20;
            goto LAB_0067162b;
          }
          param_1 = (undefined1 *)((int)param_1 - iVar2);
          puVar3 = puVar3 + iVar2;
        }
      }
      else {
        _Size = (uint)param_1;
        if (uVar1 <= param_1) {
          _Size = uVar1;
        }
        _memcpy(puVar3,param_4->_ptr,_Size);
        param_1 = (undefined1 *)((int)param_1 - _Size);
        param_4->_cnt = param_4->_cnt - _Size;
        param_4->_ptr = param_4->_ptr + _Size;
        puVar3 = puVar3 + _Size;
      }
    } while (param_1 != (undefined1 *)0x0);
  }
  return param_3;
}


// ==== 0x67163d _fread

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  __lock_file(_File);
  sVar1 = __fread_lk(_DstBuf,_ElementSize,_Count,_File);
  FUN_0067167f();
  return sVar1;
}


// ==== 0x67167f FUN_0067167f

void FUN_0067167f(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0x14));
  return;
}


// ==== 0x671689 _isalpha

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _isalpha(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,0x103);
    return iVar3;
  }
  return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x103;
}


// ==== 0x6716c8 _isdigit

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _isdigit(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,4);
    return iVar3;
  }
  return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 4;
}


// ==== 0x671702 _isxdigit

/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 2003 Release */

int __cdecl _isxdigit(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,0x80);
    return iVar3;
  }
  return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x80;
}


// ==== 0x671741 _isspace

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _isspace(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,8);
    return iVar3;
  }
  return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 8;
}


// ==== 0x67177b _isalnum

/* Library Function - Single Match
    _isalnum
   
   Library: Visual Studio 2003 Release */

int __cdecl _isalnum(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,0x107);
    return iVar3;
  }
  return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x107;
}


// ==== 0x6717ba _isgraph

/* Library Function - Single Match
    _isgraph
   
   Library: Visual Studio 2003 Release */

int __cdecl _isgraph(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  if (1 < (int)ptVar2->lc_category[1].refcount) {
    iVar3 = _isctype(ptVar2,_C,0x117);
    return iVar3;
  }
  return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x117;
}


// ==== 0x6717f9 FUN_006717f9

undefined4 FUN_006717f9(void)

{
  size_t sVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  sVar1 = 0x14;
  if (DAT_00794360 == 0) {
    sVar1 = 0x200;
  }
  else if (0x13 < (int)DAT_00794360) goto LAB_00671818;
  DAT_00794360 = sVar1;
LAB_00671818:
  DAT_00793350 = _calloc(DAT_00794360,4);
  if (DAT_00793350 == (void *)0x0) {
    DAT_00794360 = 0x14;
    DAT_00793350 = _calloc(0x14,4);
    if (DAT_00793350 == (void *)0x0) {
      return 0x1a;
    }
  }
  iVar4 = 0;
  ppuVar2 = &PTR_DAT_006eb1c0;
  do {
    *(undefined ***)(iVar4 + (int)DAT_00793350) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar4 = iVar4 + 4;
  } while ((int)ppuVar2 < 0x6eb440);
  uVar3 = 0;
  puVar5 = &DAT_006eb1d0;
  do {
    iVar4 = *(int *)((&DAT_00793240)[(int)uVar3 >> 5] + (uVar3 & 0x1f) * 0x24);
    if ((iVar4 == -1) || (iVar4 == 0)) {
      *puVar5 = 0xffffffff;
    }
    puVar5 = puVar5 + 8;
    uVar3 = uVar3 + 1;
  } while ((int)puVar5 < 0x6eb230);
  return 0;
}


// ==== 0x6718a2 ___endstdio

/* Library Function - Single Match
    ___endstdio
   
   Library: Visual Studio 2003 Release */

void ___endstdio(void)

{
  __flushall();
  if (DAT_00717ac0 != '\0') {
    __fcloseall();
    return;
  }
  return;
}


// ==== 0x6718b6 __lock_file

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __lock_file(FILE *_File)

{
  if (((FILE *)0x6eb1bf < _File) && (_File < (FILE *)0x6eb421)) {
    __lock(((int)(_File + -0x3758e) >> 5) + 0x10);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


// ==== 0x6718e5 __lock_file2

/* Library Function - Single Match
    __lock_file2
   
   Library: Visual Studio 2003 Release */

void __cdecl __lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __lock(_Index + 0x10);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== 0x671908 __unlock_file

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)0x6eb1bf < _File) && (_File < (FILE *)0x6eb421)) {
    __unlock(((int)(_File + -0x3758e) >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


// ==== 0x671937 __unlock_file2

/* Library Function - Single Match
    __unlock_file2
   
   Library: Visual Studio 2003 Release */

void __cdecl __unlock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __unlock(_Index + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== 0x67195a __fwrite_lk

/* Library Function - Single Match
    __fwrite_lk
   
   Library: Visual Studio 2003 Release */

uint __fwrite_lk(char *param_1,uint param_2,uint param_3,FILE *param_4)

{
  uint uVar1;
  int iVar2;
  uint _Size;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = param_2 * param_3;
  if (uVar5 == 0) {
    param_3 = 0;
  }
  else {
    uVar4 = uVar5;
    if ((param_4->_flag & 0x10c) == 0) {
      local_8 = 0x1000;
    }
    else {
      local_8 = param_4->_bufsiz;
    }
    do {
      uVar3 = param_4->_flag & 0x108;
      if ((uVar3 == 0) || (uVar1 = param_4->_cnt, uVar1 == 0)) {
        if (local_8 <= uVar4) {
          if ((uVar3 != 0) && (iVar2 = __flush(param_4), iVar2 != 0)) {
LAB_00671a4f:
            return (uVar5 - uVar4) / param_2;
          }
          uVar3 = uVar4;
          if (local_8 != 0) {
            uVar3 = uVar4 - uVar4 % local_8;
          }
          _Size = __write(param_4->_file,param_1,uVar3);
          if ((_Size == 0xffffffff) || (uVar4 = uVar4 - _Size, _Size < uVar3)) {
            param_4->_flag = param_4->_flag | 0x20;
            goto LAB_00671a4f;
          }
          goto LAB_00671a0f;
        }
        iVar2 = __flsbuf((int)*param_1,param_4);
        if (iVar2 == -1) goto LAB_00671a4f;
        param_1 = param_1 + 1;
        local_8 = param_4->_bufsiz;
        uVar4 = uVar4 - 1;
        if ((int)local_8 < 1) {
          local_8 = 1;
        }
      }
      else {
        _Size = uVar4;
        if (uVar1 <= uVar4) {
          _Size = uVar1;
        }
        _memcpy(param_4->_ptr,param_1,_Size);
        param_4->_cnt = param_4->_cnt - _Size;
        param_4->_ptr = param_4->_ptr + _Size;
        uVar4 = uVar4 - _Size;
LAB_00671a0f:
        param_1 = param_1 + _Size;
      }
    } while (uVar4 != 0);
  }
  return param_3;
}


// ==== 0x671a61 _fwrite

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  __lock_file(_File);
  sVar1 = __fwrite_lk(_Str,_Size,_Count,_File);
  FUN_00671aa3();
  return sVar1;
}


// ==== 0x671aa3 FUN_00671aa3

void FUN_00671aa3(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0x14));
  return;
}


// ==== 0x671aad FUN_00671aad

uint FUN_00671aad(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  LPCSTR _LpSrcStr;
  int iVar3;
  BOOL unaff_ESI;
  undefined4 local_8;
  
  uVar1 = param_2;
  iVar3 = param_1;
  if ((*(int *)(param_1 + 0x14) == 0) || ((*(int *)(param_1 + 0x24) != 0 && (param_2 < 0x80)))) {
    if ((0x60 < (int)param_2) && ((int)param_2 < 0x7b)) {
      return param_2 - 0x20;
    }
  }
  else {
    if (param_2 < 0x100) {
      if (*(int *)(param_1 + 0x28) < 2) {
        uVar2 = *(byte *)(*(int *)(param_1 + 0x48) + param_2 * 2) & 2;
      }
      else {
        uVar2 = _isctype(param_1,param_2,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((*(byte *)(*(int *)(iVar3 + 0x48) + 1 + ((int)uVar1 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      _LpSrcStr = (LPCSTR)0x1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      _LpSrcStr = (LPCSTR)0x2;
    }
    iVar3 = ___crtLCMapStringA(*(_locale_t *)(iVar3 + 0x14),(LPCWSTR)0x200,(DWORD)&param_1,_LpSrcStr
                               ,(int)&local_8,(LPSTR)0x3,*(int *)(iVar3 + 4),1,unaff_ESI);
    if (iVar3 != 0) {
      if (iVar3 != 1) {
        return (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
      }
      return local_8 & 0xff;
    }
  }
  return uVar1;
}


// ==== 0x671b76 FUN_00671b76

void FUN_00671b76(undefined4 param_1)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  FUN_00671aad(ptVar2,param_1);
  return;
}


// ==== 0x671b98 __ftell_lk

/* Library Function - Single Match
    __ftell_lk
   
   Library: Visual Studio 2003 Release */

int __ftell_lk(uint *param_1)

{
  uint _FileHandle;
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  puVar3 = param_1;
  _FileHandle = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  local_8 = __lseek(_FileHandle,0,1);
  if (local_8 < 0) {
LAB_00671c35:
    local_c = -1;
  }
  else {
    uVar1 = param_1[3];
    if ((uVar1 & 0x108) == 0) {
      return local_8 - param_1[1];
    }
    pcVar5 = (char *)*param_1;
    pcVar7 = (char *)param_1[2];
    local_c = (int)pcVar5 - (int)pcVar7;
    if ((uVar1 & 3) == 0) {
      if (-1 < (char)uVar1) {
        puVar4 = (undefined4 *)__errno();
        *puVar4 = 0x16;
        goto LAB_00671c35;
      }
    }
    else if (((*(byte *)((&DAT_00793240)[(int)_FileHandle >> 5] + 4 + (_FileHandle & 0x1f) * 0x24) &
              0x80) != 0) && (pcVar8 = pcVar7, pcVar7 < pcVar5)) {
      do {
        if (*pcVar8 == '\n') {
          local_c = local_c + 1;
        }
        pcVar8 = pcVar8 + 1;
      } while (pcVar8 < (char *)*param_1);
    }
    if (local_8 != 0) {
      if ((param_1[3] & 1) != 0) {
        if (param_1[1] == 0) {
          local_c = 0;
        }
        else {
          pcVar5 = pcVar5 + (param_1[1] - (int)pcVar7);
          iVar9 = (_FileHandle & 0x1f) * 0x24;
          if ((*(byte *)(iVar9 + 4 + (&DAT_00793240)[(int)_FileHandle >> 5]) & 0x80) != 0) {
            lVar6 = __lseek(_FileHandle,0,2);
            if (lVar6 == local_8) {
              pcVar7 = (char *)param_1[2];
              pcVar8 = pcVar7 + (int)pcVar5;
              param_1 = (uint *)pcVar5;
              for (; pcVar7 < pcVar8; pcVar7 = pcVar7 + 1) {
                if (*pcVar7 == '\n') {
                  param_1 = (uint *)((int)param_1 + 1);
                }
              }
              bVar2 = *(byte *)((int)puVar3 + 0xd) & 0x20;
            }
            else {
              __lseek(_FileHandle,local_8,0);
              pcVar7 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((param_1[3] & 8) == 0)) ||
                 ((param_1[3] & 0x400) != 0)) {
                pcVar7 = (char *)param_1[6];
              }
              bVar2 = *(byte *)(iVar9 + 4 + (&DAT_00793240)[(int)_FileHandle >> 5]) & 4;
              param_1 = (uint *)pcVar7;
            }
            pcVar5 = (char *)param_1;
            if (bVar2 != 0) {
              pcVar5 = (char *)((int)param_1 + 1);
            }
          }
          param_1 = (uint *)pcVar5;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}


// ==== 0x671cfa _ftell

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ftell
   
   Library: Visual Studio 2003 Release */

long __cdecl _ftell(FILE *_File)

{
  long lVar1;
  
  __lock_file(_File);
  lVar1 = __ftell_lk(_File);
  FUN_00671d31();
  return lVar1;
}


// ==== 0x671d31 FUN_00671d31

void FUN_00671d31(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== 0x671d3b __fseek_lk

/* Library Function - Single Match
    __fseek_lk
   
   Library: Visual Studio 2003 Release */

int __fseek_lk(FILE *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  
  if (((param_1->_flag & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1->_flag = param_1->_flag & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = __ftell_lk(param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    __flush(param_1);
    uVar1 = param_1->_flag;
    if ((char)uVar1 < '\0') {
      param_1->_flag = uVar1 & 0xfffffffc;
    }
    else if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
      param_1->_bufsiz = 0x200;
    }
    lVar3 = __lseek(param_1->_file,param_2,param_3);
    iVar2 = (lVar3 != -1) - 1;
  }
  return iVar2;
}


// ==== 0x671dca _fseek

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 2003 Release */

int __cdecl _fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;
  
  __lock_file(_File);
  iVar1 = __fseek_lk(_File,_Offset,_Origin);
  FUN_00671e09();
  return iVar1;
}


// ==== 0x671e09 FUN_00671e09

void FUN_00671e09(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== 0x671e13 __getenv_lk

/* Library Function - Single Match
    __getenv_lk
   
   Library: Visual Studio 2003 Release */

int __getenv_lk(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (DAT_00793340 == 0) {
    return 0;
  }
  if (((DAT_00717aa8 != (int *)0x0) ||
      (((DAT_00717ab0 != 0 && (iVar1 = FUN_00679330(), iVar1 == 0)) && (DAT_00717aa8 != (int *)0x0))
      )) && (piVar3 = DAT_00717aa8, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}


// ==== 0x671e94 _getenv

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

char * __cdecl _getenv(char *_VarName)

{
  char *pcVar1;
  
  __lock(7);
  pcVar1 = (char *)__getenv_lk(_VarName);
  FUN_00671eca();
  return pcVar1;
}


// ==== 0x671eca FUN_00671eca

void FUN_00671eca(void)

{
  __unlock(7);
  return;
}


// ==== 0x671ed3 __fclose_lk

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

int __fclose_lk(FILE *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if ((param_1->_flag & 0x83) != 0) {
    iVar2 = __flush(param_1);
    __freebuf(param_1);
    iVar1 = __close(param_1->_file);
    if (iVar1 < 0) {
      iVar2 = -1;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      _free(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return iVar2;
}


// ==== 0x671f1f _fclose

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _fclose(FILE *_File)

{
  int local_20;
  
  local_20 = -1;
  if ((_File->_flag & 0x40) == 0) {
    __lock_file(_File);
    local_20 = __fclose_lk(_File);
    FUN_00671f68();
  }
  else {
    _File->_flag = 0;
  }
  return local_20;
}


// ==== 0x671f65 FUN_00671f65

void FUN_00671f65(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== 0x671f68 FUN_00671f68

void FUN_00671f68(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}


// ==== 0x671f70 ___crtExitProcess

/* Library Function - Single Match
    ___crtExitProcess
   
   Library: Visual Studio 2003 Release */

void __cdecl ___crtExitProcess(int param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("mscoree.dll");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"CorExitProcess");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


// ==== 0x671fa0 FUN_00671fa0

void FUN_00671fa0(void)

{
  __lock(8);
  return;
}


// ==== 0x671fa9 FUN_00671fa9

void FUN_00671fa9(void)

{
  __unlock(8);
  return;
}


// ==== 0x671fb2 FUN_00671fb2

int FUN_00671fb2(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (PTR_FUN_006eb458 != (undefined *)0x0) {
    (*(code *)PTR_FUN_006eb458)();
  }
  iVar1 = 0;
  puVar2 = &DAT_006d4a4c;
  do {
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((code *)*puVar2 != (code *)0x0) {
      iVar1 = (*(code *)*puVar2)();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 < &DAT_006d4a64);
  if (iVar1 == 0) {
    _atexit(FUN_00675856);
    puVar2 = &DAT_006d4000;
    do {
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)();
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 < &DAT_006d4a48);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x672017 __cexit_doexit

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __cexit_doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  bool bVar2;
  UINT uExitCode;
  
  __lock(8);
  if (DAT_00717ac8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00717ac4 = 1;
  DAT_00717ac0 = (undefined1)param_3;
  if (param_2 == 0) {
    if (DAT_00793348 != (undefined4 *)0x0) {
      DAT_00793344 = DAT_00793344 + -1;
      bVar2 = DAT_00793344 < DAT_00793348;
      while (!bVar2) {
        if ((code *)*DAT_00793344 != (code *)0x0) {
          (*(code *)*DAT_00793344)();
        }
        DAT_00793344 = DAT_00793344 + -1;
        bVar2 = DAT_00793344 < DAT_00793348;
      }
    }
    puVar1 = &DAT_006d4a68;
    do {
      if ((code *)*puVar1 != (code *)0x0) {
        (*(code *)*puVar1)();
      }
      puVar1 = puVar1 + 1;
    } while (puVar1 < &DAT_006d4a78);
  }
  puVar1 = &DAT_006d4a7c;
  do {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
    puVar1 = puVar1 + 1;
  } while (puVar1 < &DAT_006d4a84);
  if (param_3 == 0) {
    DAT_00717ac8 = 1;
    ___crtExitProcess(param_1);
  }
  else {
    __unlock(8);
  }
  return;
}


// ==== 0x6720ea FUN_006720ea

void FUN_006720ea(undefined4 param_1)

{
  __cexit_doexit(param_1,0,0);
  return;
}


// ==== 0x6720fb __exit

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __exit(int _Code)

{
  __cexit_doexit(_Code,1,0);
  return;
}


// ==== 0x67210c FUN_0067210c

void FUN_0067210c(void)

{
  __cexit_doexit(0,0,1);
  return;
}


// ==== 0x67211b FUN_0067211b

void FUN_0067211b(void)

{
  __cexit_doexit(0,1,1);
  return;
}


// ==== 0x67212a __ArrayUnwind

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2003 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  return;
}


// ==== 0x672159 FUN_00672159

undefined4 FUN_00672159(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + -0x1c);
  if (**(int **)(unaff_EBP + -0x20) != -0x1f928c9d) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    return *(undefined4 *)(unaff_EBP + -0x24);
  }
  terminate();
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}


// ==== 0x67217d FUN_0067217d

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067217d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x672156;
  return;
}


// ==== 0x672188 eh_vector_destructor_iterator

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void eh_vector_destructor_iterator
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  FUN_006721d0();
  return;
}


// ==== 0x6721d0 FUN_006721d0

void FUN_006721d0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== 0x6721e8 eh_vector_constructor_iterator

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void eh_vector_constructor_iterator
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  void *unaff_EDI;
  undefined4 local_24;
  
  for (local_24 = 0; local_24 < param_3; local_24 = local_24 + 1) {
    (*param_4)(unaff_EDI);
  }
  FUN_00672232();
  return;
}


// ==== 0x672232 FUN_00672232

void FUN_00672232(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x20),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== 0x67224a __abstract_cw

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

uint __abstract_cw(void)

{
  uint uVar1;
  ushort uVar2;
  ushort unaff_BX;
  
  uVar1 = 0;
  if ((unaff_BX & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((unaff_BX & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((unaff_BX & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((unaff_BX & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((unaff_BX & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((unaff_BX & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = unaff_BX & 0xc00;
  if ((unaff_BX & 0xc00) != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((unaff_BX & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((unaff_BX & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((unaff_BX & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}


// ==== 0x6722dc __hw_cw

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 2003 Release */

uint __hw_cw(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  
  uVar1 = (uint)((unaff_EBX & 0x10) != 0);
  if ((unaff_EBX & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((unaff_EBX & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((unaff_EBX & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((unaff_EBX & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((unaff_EBX & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = unaff_EBX & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((unaff_EBX & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((unaff_EBX & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((unaff_EBX & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}


// ==== 0x67236a __control87

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 2003 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __abstract_cw();
  __hw_cw();
  return uVar1 & ~_Mask | _NewValue & _Mask;
}


// ==== 0x67239c __controlfp

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 2003 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== 0x6723c0 _strncpy

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x0067240c;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00672453;
        goto LAB_006724c9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x006724c5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_006724c9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00672453;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x006724c5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x006724c5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x006724c5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0067240c:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_00672453:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== 0x6724e4 FUN_006724e4

char FUN_006724e4(byte *param_1)

{
  return ((*(byte *)((int)&DAT_00792fe0 + *param_1 + 1) & 4) != 0) + '\x01';
}


// ==== 0x6724fa FUN_006724fa

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006724fa(undefined4 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  DWORD DVar5;
  DWORD DVar6;
  undefined8 uVar7;
  uint unaff_retaddr;
  _TIME_ZONE_INFORMATION local_bc;
  _FILETIME local_10;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  FUN_00679ecd();
  *(short *)((int)param_1 + 6) = (short)(DAT_006ebc00 / 0x3c);
  GetSystemTimeAsFileTime(&local_10);
  DVar6 = local_10.dwHighDateTime;
  DVar5 = local_10.dwLowDateTime;
  iVar2 = __aulldiv(local_10.dwLowDateTime,local_10.dwHighDateTime,600000000,0);
  if (iVar2 != DAT_00717acc) {
    DVar3 = GetTimeZoneInformation(&local_bc);
    DVar5 = local_10.dwLowDateTime;
    DVar6 = local_10.dwHighDateTime;
    DAT_00717acc = iVar2;
    if (DVar3 == 0xffffffff) {
      _DAT_006eb440 = 0xffffffff;
    }
    else if (((DVar3 == 2) && (local_bc.DaylightDate.wMonth != 0)) && (local_bc.DaylightBias != 0))
    {
      _DAT_006eb440 = 1;
    }
    else {
      _DAT_006eb440 = 0;
    }
  }
  *(undefined2 *)(param_1 + 2) = DAT_006eb440;
  uVar7 = __aulldiv(DVar5,DVar6,10000,0);
  uVar1 = __aullrem(uVar7,1000,0);
  *(undefined2 *)(param_1 + 1) = uVar1;
  uVar4 = __aulldiv(DVar5 + 0x2ac18000,DVar6 + 0xfe624e21 + (uint)(0xd53e7fff < DVar5),10000000,0);
  *param_1 = uVar4;
  return;
}


// ==== 0x6725f7 FUN_006725f7

undefined4 FUN_006725f7(LPCSTR param_1)

{
  BOOL BVar1;
  ulong uVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
  }
  else {
    uVar2 = 0;
  }
  if (uVar2 != 0) {
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  return 0;
}


// ==== 0x672621 thunk_FUN_006725f7

undefined4 thunk_FUN_006725f7(LPCSTR param_1)

{
  BOOL BVar1;
  ulong uVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
  }
  else {
    uVar2 = 0;
  }
  if (uVar2 != 0) {
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  return 0;
}


// ==== 0x672626 FUN_00672626

void FUN_00672626(void)

{
  __amsg_exit(0x19);
  return;
}


// ==== 0x672630 _memmove

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _memmove(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar3 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = _Size >> 2;
      uVar2 = _Size & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_006727eb_caseD_2;
        case 3:
          goto switchD_006727eb_caseD_3;
        }
        goto switchD_006727eb_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_006727eb_caseD_0;
      case 1:
        goto switchD_006727eb_caseD_1;
      case 2:
        goto switchD_006727eb_caseD_2;
      case 3:
        goto switchD_006727eb_caseD_3;
      default:
        uVar1 = _Size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_006727eb_caseD_2;
            case 3:
              goto switchD_006727eb_caseD_3;
            }
            goto switchD_006727eb_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_006727eb_caseD_2;
            case 3:
              goto switchD_006727eb_caseD_3;
            }
            goto switchD_006727eb_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_006727eb_caseD_2;
            case 3:
              goto switchD_006727eb_caseD_3;
            }
            goto switchD_006727eb_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_006727eb_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return _Dst;
    case 2:
switchD_006727eb_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return _Dst;
    case 3:
switchD_006727eb_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return _Dst;
    }
switchD_006727eb_caseD_0:
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar1 = _Size >> 2;
    uVar2 = _Size & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_00672665_caseD_2;
      case 3:
        goto switchD_00672665_caseD_3;
      }
      goto switchD_00672665_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_00672665_caseD_0;
    case 1:
      goto switchD_00672665_caseD_1;
    case 2:
      goto switchD_00672665_caseD_2;
    case 3:
      goto switchD_00672665_caseD_3;
    default:
      uVar1 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar3 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00672665_caseD_2;
          case 3:
            goto switchD_00672665_caseD_3;
          }
          goto switchD_00672665_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar3 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00672665_caseD_2;
          case 3:
            goto switchD_00672665_caseD_3;
          }
          goto switchD_00672665_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        _Src = (void *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00672665_caseD_2;
          case 3:
            goto switchD_00672665_caseD_3;
          }
          goto switchD_00672665_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)_Src + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)_Src + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)_Src + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)_Src + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)_Src + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)_Src + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)_Src + (uVar1 - 1) * 4);
    _Src = (void *)((int)_Src + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00672665_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    return _Dst;
  case 2:
switchD_00672665_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_00672665_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_00672665_caseD_0:
  return _Dst;
}


// ==== 0x672970 FUN_00672970

uint * FUN_00672970(uint *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  
  cVar3 = *param_2;
  if (cVar3 == '\0') {
    return param_1;
  }
  if (param_2[1] == '\0') {
    while (((uint)param_1 & 3) != 0) {
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar5 = *param_1;
        uVar9 = uVar5 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar7 = uVar5 ^ 0xffffffff ^ uVar5 + 0x7efefeff;
        puVar10 = param_1 + 1;
        if (((uVar9 ^ 0xffffffff ^ uVar9 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar10;
        if ((uVar7 & 0x81010100) != 0) {
          if ((uVar7 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar5 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 8);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 1);
      }
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 0x10);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 2);
      }
      if (cVar6 == '\0') break;
      cVar6 = (char)(uVar5 >> 0x18);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar10;
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    cVar6 = (char)*param_1;
    do {
      while (puVar10 = param_1, param_1 = (uint *)((int)puVar10 + 1), cVar6 != cVar3) {
        if (cVar6 == '\0') {
          return (uint *)0x0;
        }
        cVar6 = *(char *)param_1;
      }
      cVar6 = *(char *)param_1;
      pcVar8 = param_2;
      puVar4 = puVar10;
    } while (cVar6 != param_2[1]);
    do {
      if (pcVar8[2] == '\0') {
        return puVar10;
      }
      if (*(char *)((int)puVar4 + 2) != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') {
        return puVar10;
      }
      pcVar2 = (char *)((int)puVar4 + 3);
      pcVar8 = pcVar8 + 2;
      puVar4 = (uint *)((int)puVar4 + 2);
    } while (*pcVar1 == *pcVar2);
  } while( true );
}


// ==== 0x6729f6 FUN_006729f6

void FUN_006729f6(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x672a10 _strchr

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

uint * _strchr(uint *param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)param_1 & 3) != 0) {
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    param_1 = (uint *)((int)param_1 + 1);
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}


// ==== 0x672ad0 shortsort

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __cdecl shortsort(undefined1 *param_1,int param_2,code *param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *in_EAX;
  int iVar3;
  undefined1 *puVar4;
  
  for (; puVar2 = param_1, puVar4 = param_1, param_1 < in_EAX; in_EAX = in_EAX + -param_2) {
    while (puVar4 = puVar4 + param_2, puVar4 <= in_EAX) {
      iVar3 = (*param_3)(puVar4,puVar2);
      if (0 < iVar3) {
        puVar2 = puVar4;
      }
    }
    if ((puVar2 != in_EAX) && (param_2 != 0)) {
      puVar4 = in_EAX;
      iVar3 = param_2;
      do {
        uVar1 = puVar4[(int)puVar2 - (int)in_EAX];
        puVar4[(int)puVar2 - (int)in_EAX] = *puVar4;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}


// ==== 0x672b40 _qsort

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void _qsort(undefined1 *param_1,uint param_2,uint param_3,code *param_4)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *local_100;
  undefined1 *local_fc;
  int local_f8;
  uint uStack_f4;
  undefined4 auStack_f0 [30];
  undefined4 auStack_78 [30];
  
  if ((param_2 < 2) || (param_3 == 0)) {
    return;
  }
  local_f8 = 0;
  local_100 = param_1;
  local_fc = param_1 + (param_2 - 1) * param_3;
LAB_00672b85:
  while (uVar2 = (uint)((int)local_fc - (int)local_100) / param_3 + 1, 8 < uVar2) {
    puVar3 = local_100 + (uVar2 >> 1) * param_3;
    iVar4 = (*param_4)(local_100,puVar3);
    if ((0 < iVar4) && (local_100 != puVar3)) {
      puVar5 = puVar3;
      uVar2 = param_3;
      do {
        uVar1 = puVar5[(int)local_100 - (int)puVar3];
        puVar5[(int)local_100 - (int)puVar3] = *puVar5;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    iVar4 = (*param_4)(local_100,local_fc);
    if ((0 < iVar4) && (local_100 != local_fc)) {
      puVar5 = local_fc;
      uVar2 = param_3;
      do {
        uVar1 = puVar5[(int)local_100 - (int)local_fc];
        puVar5[(int)local_100 - (int)local_fc] = *puVar5;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    iVar4 = (*param_4)(puVar3,local_fc);
    puVar5 = local_100;
    puVar7 = local_fc;
    if ((0 < iVar4) && (puVar3 != local_fc)) {
      puVar6 = local_fc;
      uVar2 = param_3;
      do {
        uVar1 = puVar6[(int)puVar3 - (int)local_fc];
        puVar6[(int)puVar3 - (int)local_fc] = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
LAB_00672c70:
    if (puVar5 < puVar3) {
      do {
        puVar5 = puVar5 + param_3;
        if (puVar3 <= puVar5) goto LAB_00672c90;
        iVar4 = (*param_4)(puVar5,puVar3);
      } while (iVar4 < 1);
      if (puVar3 <= puVar5) goto LAB_00672c90;
    }
    else {
LAB_00672c90:
      do {
        puVar5 = puVar5 + param_3;
        if (local_fc < puVar5) break;
        iVar4 = (*param_4)(puVar5,puVar3);
      } while (iVar4 < 1);
    }
    do {
      puVar7 = puVar7 + -param_3;
      if (puVar7 <= puVar3) break;
      iVar4 = (*param_4)(puVar7,puVar3);
    } while (0 < iVar4);
    if (puVar5 <= puVar7) {
      if (puVar5 != puVar7) {
        uStack_f4 = param_3;
        puVar6 = puVar7;
        do {
          uVar1 = puVar6[(int)puVar5 - (int)puVar7];
          puVar6[(int)puVar5 - (int)puVar7] = *puVar6;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
          uStack_f4 = uStack_f4 - 1;
        } while (uStack_f4 != 0);
      }
      if (puVar3 == puVar7) {
        puVar3 = puVar5;
      }
      goto LAB_00672c70;
    }
    puVar7 = puVar7 + param_3;
    if (puVar3 < puVar7) {
      do {
        puVar7 = puVar7 + -param_3;
        if (puVar7 <= puVar3) goto LAB_00672d30;
        iVar4 = (*param_4)(puVar7,puVar3);
      } while (iVar4 == 0);
      if (puVar7 <= puVar3) goto LAB_00672d30;
    }
    else {
LAB_00672d30:
      do {
        puVar7 = puVar7 + -param_3;
        if (puVar7 <= local_100) break;
        iVar4 = (*param_4)(puVar7,puVar3);
      } while (iVar4 == 0);
    }
    if ((int)puVar7 - (int)local_100 < (int)local_fc - (int)puVar5) goto LAB_00672d8b;
    if (local_100 < puVar7) {
      auStack_f0[local_f8] = local_100;
      auStack_78[local_f8] = puVar7;
      local_f8 = local_f8 + 1;
    }
    local_100 = puVar5;
    if (local_fc <= puVar5) goto LAB_00672ba7;
  }
  shortsort(local_100,param_3,param_4);
  goto LAB_00672ba7;
LAB_00672d8b:
  if (puVar5 < local_fc) {
    auStack_f0[local_f8] = puVar5;
    auStack_78[local_f8] = local_fc;
    local_f8 = local_f8 + 1;
  }
  local_fc = puVar7;
  if (puVar7 <= local_100) {
LAB_00672ba7:
    local_f8 = local_f8 + -1;
    if (local_f8 < 0) {
      return;
    }
    local_100 = (undefined1 *)auStack_f0[local_f8];
    local_fc = (undefined1 *)auStack_78[local_f8];
  }
  goto LAB_00672b85;
}


// ==== 0x672dd0 FUN_00672dd0

void FUN_00672dd0(void)

{
  PTR_FUN_006ebcb0 = __cfltcvt;
  PTR_FUN_006ebcb4 = FUN_00679fb1;
  PTR_FUN_006ebcb8 = __fassign;
  PTR_FUN_006ebcbc = __forcdecpt;
  PTR_FUN_006ebcc0 = FUN_00679ffc;
  PTR_FUN_006ebcc4 = __cfltcvt;
  return;
}


// ==== 0x672e08 FUN_00672e08

void FUN_00672e08(void)

{
  FUN_00672dd0();
  DAT_00717ad4 = __ms_p5_mp_test_fdiv();
  FUN_00679546();
  return;
}


// ==== 0x672e20 FUN_00672e20

void FUN_00672e20(void)

{
  float10 in_ST0;
  
  FUN_0067a6b8((double)in_ST0);
  FUN_00672e3d();
  return;
}


// ==== 0x672e3d FUN_00672e3d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00672e3d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_006ebcd0, param_1 != 0)) {
      fVar1 = (float10)FUN_0067a65c();
    }
LAB_00672ecc:
    if (DAT_00717ad0 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0067a645();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);
    }
    else {
      fVar1 = _DAT_006ebcd0;
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_00672ecc;
      if ((param_2 & 0x80000000) == 0) {
        fVar1 = (float10)0;
      }
      else {
        fVar1 = (float10)3.141592653589793;
      }
    }
    if (DAT_00717ad0 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}


// ==== 0x672eeb _finite

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

bool _finite(undefined4 param_1,undefined4 param_2)

{
  return (param_2._2_2_ & 0x7ff0) != 0x7ff0;
}


// ==== 0x672f00 __isnan

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl __isnan(double _X)

{
  if ((((_X._6_2_ & 0x7ff8) != 0x7ff0) ||
      ((((ulonglong)_X & 0x7ffff00000000) == 0 && (_X._0_4_ == 0)))) &&
     ((_X._6_2_ & 0x7ff8) != 0x7ff8)) {
    return 0;
  }
  return 1;
}


// ==== 0x672f2e FUN_00672f2e

int FUN_00672f2e(int param_1,uint param_2)

{
  int iVar1;
  int iStack_8;
  
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar1 = __sptype();
    if (iVar1 == 1) {
      return 0x200;
    }
    if (iVar1 == 2) {
      iStack_8 = 4;
    }
    else {
      if (iVar1 != 3) {
        return 1;
      }
      iStack_8 = 2;
    }
    return iStack_8;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff90) + 0x80;
  }
  if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == 0.0) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffffe0) + 0x40;
  }
  return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff08) + 0x100;
}


// ==== 0x672fc8 __ftol

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== 0x672fef _JumpToContinuation

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x00673018. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== 0x67301f FID_conflict:_CallMemberFunction1

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 2003 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00673024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== 0x673026 _UnwindNestedFrames

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 2003 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x67304f,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ==== 0x673078 ___CxxFrameHandler

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4
___CxxFrameHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ==== 0x6730ae FUN_006730ae

void FUN_006730ae(undefined4 param_1,int param_2,undefined4 param_3)

{
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),param_2,0);
  return;
}


// ==== 0x6730d2 FUN_006730d2

undefined4 FUN_006730d2(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 4) & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x0067313a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(param_2 + 0x18))();
  return uVar1;
}


// ==== 0x673143 _GetRangeOfTrysToCheck

/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 2003 Release */

_s_TryBlockMapEntry * __cdecl
_GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  TryBlockMapEntry *pTVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1->nTryBlocks;
  pTVar2 = param_1->pTryBlockMap;
  uVar5 = uVar1;
  uVar4 = uVar1;
  while (uVar3 = uVar5, -1 < param_2) {
    if (uVar1 == 0xffffffff) {
      _inconsistency();
    }
    uVar1 = uVar1 - 1;
    if (((pTVar2[uVar1].tryHigh < param_3) && (param_3 <= pTVar2[uVar1].catchHigh)) ||
       (uVar5 = uVar3, uVar1 == -1)) {
      param_2 = param_2 + -1;
      uVar5 = uVar1;
      uVar4 = uVar3;
    }
  }
  uVar1 = uVar1 + 1;
  *param_4 = uVar1;
  *param_5 = uVar4;
  if ((param_1->nTryBlocks < uVar4) || (uVar4 < uVar1)) {
    _inconsistency();
  }
  return pTVar2 + uVar1;
}


// ==== 0x6731bd FUN_006731bd

undefined4 * FUN_006731bd(undefined4 *param_1,undefined4 param_2)

{
  _ptiddata p_Var1;
  
  *param_1 = param_2;
  p_Var1 = __getptd();
  param_1[1] = p_Var1->_purecall;
  p_Var1 = __getptd();
  p_Var1->_purecall = param_1;
  return param_1;
}


// ==== 0x6731e5 FUN_006731e5

undefined4 FUN_006731e5(int param_1)

{
  _ptiddata p_Var1;
  int *piVar2;
  
  p_Var1 = __getptd();
  piVar2 = p_Var1->_purecall;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    if (*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[1];
  }
  return 0;
}


// ==== 0x673206 _FindAndUnlinkFrame

/* Library Function - Single Match
    void __cdecl _FindAndUnlinkFrame(struct FrameInfo *)
   
   Library: Visual Studio 2003 Release */

void __cdecl _FindAndUnlinkFrame(FrameInfo *param_1)

{
  FrameInfo *pFVar1;
  _ptiddata p_Var2;
  FrameInfo *pFVar3;
  
  p_Var2 = __getptd();
  if (param_1 == p_Var2->_purecall) {
    p_Var2 = __getptd();
    p_Var2->_purecall = *(void **)(param_1 + 4);
    return;
  }
  p_Var2 = __getptd();
  pFVar1 = p_Var2->_purecall;
  do {
    pFVar3 = pFVar1;
    if (*(int *)(pFVar3 + 4) == 0) {
      _inconsistency();
      return;
    }
    pFVar1 = *(FrameInfo **)(pFVar3 + 4);
  } while (param_1 != *(FrameInfo **)(pFVar3 + 4));
  *(undefined4 *)(pFVar3 + 4) = *(undefined4 *)(param_1 + 4);
  return;
}


// ==== 0x673252 FUN_00673252

undefined4
FUN_00673252(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_8 = param_4 + 1;
  local_14 = FUN_006730ae;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}


// ==== 0x6732a3 FUN_006732a3

undefined4
FUN_006732a3(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  _ptiddata p_Var1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffc4;
  local_28 = FUN_006730d2;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x673326;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  p_Var1 = __getptd();
  (*(code *)p_Var1->_NLG_dwCode)(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}


// ==== 0x673354 __global_unwind2

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x67336c,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== 0x673374 FUN_00673374

undefined4 FUN_00673374(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}


// ==== 0x673396 __local_unwind2

/* Library Function - Single Match
    __local_unwind2
   
   Library: Visual Studio 2003 Release */

void __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  pcStack_18 = FUN_00673374;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0067342a(0x101);
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== 0x6733fe __abnormal_termination

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(code **)((int)ExceptionList + 4) == FUN_00673374) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ==== 0x673421 __NLG_Notify1

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_006eb480 = param_1;
  DAT_006eb47c = in_EAX;
  DAT_006eb484 = unaff_EBP;
  return;
}


// ==== 0x67342a FUN_0067342a

void FUN_0067342a(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_006eb480 = *(undefined4 *)(unaff_EBP + 8);
  DAT_006eb47c = in_EAX;
  DAT_006eb484 = unaff_EBP;
  return;
}


// ==== 0x673444 FUN_00673444

void FUN_00673444(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ==== 0x673463 _atof

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

double __cdecl _atof(char *_String)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined1 local_1c [24];
  
  while( true ) {
    iVar1 = _isspace((uint)(byte)*_String);
    if (iVar1 == 0) break;
    _String = _String + 1;
  }
  iVar3 = iVar1;
  sVar2 = _strlen(_String);
  iVar1 = FUN_0067b91c(local_1c,_String,sVar2,iVar1,iVar3);
  return *(double *)(iVar1 + 0x10);
}


// ==== 0x6734a0 __chkstk

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __chkstk(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  if (in_EAX < 0x1000) {
    *(undefined4 *)(&stack0x00000000 + -in_EAX) = unaff_retaddr;
    return;
  }
  puVar1 = &stack0x00000004;
  do {
    puVar1 = puVar1 + -0x1000;
    in_EAX = in_EAX - 0x1000;
  } while (0xfff < in_EAX);
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}


// ==== 0x6734dd _vsnprintf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 _vsnprintf(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  FILE local_24;
  
  local_24._cnt = param_2;
  local_24._flag = 0x42;
  local_24._base = param_1;
  local_24._ptr = param_1;
  uVar1 = FUN_0067604e(&local_24,param_3,param_4);
  if (param_1 != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return uVar1;
}


// ==== 0x673533 _snprintf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

undefined4 _snprintf(char *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  FILE local_24;
  
  local_24._cnt = param_2;
  local_24._flag = 0x42;
  local_24._base = param_1;
  local_24._ptr = param_1;
  uVar1 = FUN_0067604e(&local_24,param_3,&stack0x00000010);
  if (param_1 != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return uVar1;
}


// ==== 0x673590 FUN_00673590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00673590(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if ((DAT_00792fb8 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    uVar6 = (ulonglong)(0x433 - (uVar2 >> 0x14 & 0x7ff));
    if ((uVar1 & 0x800) == 0) {
      if (uVar1 < 0x3ff) {
        return (float10)0;
      }
      if (uVar1 < 0x433) {
        return (float10)(double)(((ulonglong)param_1 >> uVar6) << uVar6);
      }
    }
    else {
      dVar5 = (double)(((ulonglong)param_1 >> uVar6) << uVar6);
      if (uVar1 < 0xbff) {
        return (float10)(double)((-(ulonglong)(param_1 < -0.0) | (ulonglong)DAT_006abf80) &
                                0xbff0000000000000);
      }
      if (uVar1 < 0xc33) {
        return (float10)(dVar5 - (double)(-(ulonglong)(param_1 < dVar5) & 0x3ff0000000000000));
      }
    }
    if (NAN(param_1)) {
      FUN_0067b9b7(&param_1,&param_1,&param_1,0x3ed);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp(DAT_006ebe34,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar5 = (double)CONCAT26(param_1._6_2_,param_1._0_6_) + 1.0;
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 8;
  }
  else {
    fVar4 = (float10)FUN_00681f2f((int)param_1._0_6_,
                                  (int)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20));
    dVar5 = (double)fVar4;
    if ((dVar5 == (double)CONCAT26(param_1._6_2_,param_1._0_6_)) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar5;
    }
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 0x10;
  }
  fVar4 = (float10)FUN_0067af08(uVar7,0xb,uVar8,dVar5,uVar2);
                    /* WARNING: Read-only address (ram,0x006abf80) is written */
  return fVar4;
}


// ==== 0x6736b1 FUN_006736b1

void FUN_006736b1(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x6736b7 FUN_006736b7

void FUN_006736b7(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x6736c0 FUN_006736c0

float10 FUN_006736c0(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if ((DAT_00792fb8 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    uVar6 = (ulonglong)(0x433 - (uVar2 >> 0x14 & 0x7ff));
    if ((uVar1 & 0x800) == 0) {
      dVar5 = (double)(((ulonglong)param_1 >> uVar6) << uVar6);
      if (uVar1 < 0x3ff) {
        return (float10)(double)(-(ulonglong)(0.0 < param_1) & 0x3ff0000000000000);
      }
      if (uVar1 < 0x433) {
        return (float10)(dVar5 + (double)(-(ulonglong)(dVar5 < param_1) & 0x3ff0000000000000));
      }
    }
    else {
      if (uVar1 < 0xbff) {
        return (float10)-0.0;
      }
      if (uVar1 < 0xc33) {
        return (float10)(double)(((ulonglong)param_1 >> uVar6) << uVar6);
      }
    }
    if (NAN(param_1)) {
      FUN_0067b9b7(&param_1,&param_1,&param_1,0x3ec);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp(DAT_006ebe38,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar5 = (double)CONCAT26(param_1._6_2_,param_1._0_6_) + 1.0;
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 8;
  }
  else {
    fVar4 = (float10)FUN_00681f2f((int)param_1._0_6_,
                                  (int)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20));
    dVar5 = (double)fVar4;
    if ((dVar5 == (double)CONCAT26(param_1._6_2_,param_1._0_6_)) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar5;
    }
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 0x10;
  }
  fVar4 = (float10)FUN_0067af08(uVar7,0xc,uVar8,dVar5,uVar2);
  return fVar4;
}


// ==== 0x6737f8 FUN_006737f8

void FUN_006737f8(void)

{
  __cintrindisp1();
  return;
}


// ==== 0x673802 FUN_00673802

void FUN_00673802(void)

{
  __cintrindisp1();
  return;
}


// ==== 0x673809 FUN_00673809

void FUN_00673809(void)

{
  __cintrindisp1();
  return;
}


// ==== 0x67381a FUN_0067381a

void FUN_0067381a(void)

{
  __cintrindisp2();
  return;
}


// ==== 0x673824 FUN_00673824

float10 FUN_00673824(void)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  float10 in_ST1;
  float10 extraout_ST1;
  
  do {
    if (DAT_00717ad4 == 1) {
      in_ST1 = (float10)FUN_0067cc0c();
      in_ST0 = extraout_ST1;
    }
    else {
      in_ST1 = in_ST1 - (float10)(unkint10)(in_ST1 / in_ST0) * in_ST0;
    }
  } while ((in_FPUStatusWord & 0x400) != 0);
  return in_ST1;
}


// ==== 0x673842 FUN_00673842

void FUN_00673842(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x673848 FUN_00673848

void FUN_00673848(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x673890 FUN_00673890

void FUN_00673890(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_00792fb8 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_0067cf90();
    return;
  }
  FUN_006738ed((double)in_ST1,(double)in_ST0);
  return;
}


// ==== 0x6738ed FUN_006738ed

undefined4 FUN_006738ed(int param_1,uint param_2,int param_3,uint param_4)

{
  uint in_EAX;
  uint uVar1;
  undefined4 uVar2;
  byte extraout_CL;
  char extraout_CL_00;
  uint extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  int extraout_ECX_01;
  bool bVar4;
  short in_FPUControlWord;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 fVar6;
  unkbyte10 in_ST7;
  undefined1 local_78 [20];
  undefined4 uStack_64;
  undefined1 auStack_e [10];
  short local_4;
  undefined2 uStack_2;
  
  _local_4 = CONCAT22((short)(in_EAX >> 0x10),in_FPUControlWord);
  uVar1 = in_EAX;
  if (in_FPUControlWord != 0x27f) {
    auStack_e._6_4_ = 0x673901;
    in_EAX = FUN_0067a645();
    uVar1 = extraout_ECX;
  }
  bVar4 = (uVar1 & 0x7ff00000) == 0x7ff00000;
  if (bVar4) {
    if ((in_EAX & 0xfffff) == 0 && param_3 == 0) {
      auStack_e._6_4_ = 0x6739ca;
      fVar5 = (float10)__fload_withFB();
      iVar3 = extraout_ECX_01;
      fVar6 = extraout_ST1_01;
      goto LAB_006739ca;
    }
    auStack_e._6_4_ = 0x67398d;
    fVar5 = (float10)__fload_withFB();
    if ((param_4 & 0x80000) == 0) {
      iVar3 = extraout_ECX_00 + 1;
      fVar6 = extraout_ST1_00;
      goto LAB_006739ca;
    }
LAB_00673997:
    uVar2 = 1;
  }
  else {
    auStack_e._6_4_ = 0x67391c;
    uVar1 = __fload_withFB();
    if (!bVar4) {
      if (((uVar1 & 0x7ff00000) != 0) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
        fVar5 = extraout_ST0;
        if ((param_2 & 0x80000000) != 0) {
          auStack_e._6_4_ = 0x673a94;
          fVar5 = (float10)FUN_00673ab2();
          fVar5 = -fVar5;
          if (extraout_CL_00 == '\0') {
            uVar2 = 1;
            goto LAB_00673965;
          }
        }
        log2(fVar5);
        auStack_e._6_4_ = 0x673941;
        uVar2 = FUN_0067a630();
        if (DAT_00717ad0 != 0) {
          return uVar2;
        }
        uVar2 = FUN_0067a719();
        return uVar2;
      }
      if ((param_4 & 0x7fffffff) == 0 && param_3 == 0) {
        uVar2 = FUN_0067a6ce();
        return uVar2;
      }
      auStack_e._6_4_ = 0x673a4c;
      uVar2 = FUN_00673ab2();
      if ((param_4 & 0x80000000) == 0) {
        if ((param_2._3_1_ >> 7 & extraout_CL) == 0) {
          return uVar2;
        }
        uVar2 = FUN_0067a6ce();
        return uVar2;
      }
      uVar2 = 2;
      goto LAB_00673965;
    }
    iVar3 = 0;
    fVar5 = extraout_ST0;
    fVar6 = extraout_ST1;
LAB_006739ca:
    if (((param_2 & 0x7ff00000) == 0x7ff00000) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
      if ((param_2 & 0x80000) != 0) goto LAB_00673997;
    }
    else if (iVar3 == 0) {
      uStack_64 = 0x6739f8;
      auStack_e = (undefined1  [10])in_ST7;
      iVar3 = __powhlp((double)fVar5,(double)fVar6,local_78);
      if (iVar3 == 0) {
        return 0;
      }
      uVar2 = 1;
      goto LAB_00673965;
    }
    uVar2 = 7;
  }
LAB_00673965:
  if (DAT_00717ad0 != 0) {
    return uVar2;
  }
  auStack_e._6_4_ = 0x673982;
  uVar2 = FUN_0067a5d0();
  return uVar2;
}


// ==== 0x673ab2 FUN_00673ab2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00673ab2(void)

{
  float10 in_ST0;
  
  if (ROUND(in_ST0) == in_ST0) {
    return;
  }
  return;
}


// ==== 0x673b1c FUN_00673b1c

void FUN_00673b1c(void)

{
  ushort in_FPUControlWord;
  
  if ((DAT_00792fb8 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_0067dec0();
    return;
  }
  __cintrindisp1();
  return;
}


// ==== 0x673b70 FUN_00673b70

void FUN_00673b70(void)

{
  float10 in_ST0;
  
  FUN_0067a6b8((double)in_ST0);
  FUN_00673b8d();
  return;
}


// ==== 0x673b8d FUN_00673b8d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00673b8d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_006ebcd0, param_1 != 0)) {
      fVar1 = (float10)FUN_0067a65c();
    }
LAB_00673c1c:
    if (DAT_00717ad0 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0067a645();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(in_ST0,SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)));
    }
    else {
      fVar1 = _DAT_006ebcd0;
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_00673c1c;
      fVar1 = _DAT_006ebcda;
      if ((param_2 & 0x80000000) != 0) {
        fVar1 = -_DAT_006ebcda;
      }
    }
    if (DAT_00717ad0 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}


// ==== 0x673c3b __stricmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl __stricmp(char *_Str1,char *_Str2)

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
  if (ptVar2->lc_category[0].wlocale == (wchar_t *)0x0) {
    iVar3 = ___ascii_stricmp(_Str1,_Str2);
  }
  else {
    do {
      iVar3 = FUN_00671395(ptVar2,*_Str1);
      _Str1 = _Str1 + 1;
      iVar4 = FUN_00671395(ptVar2,*_Str2);
      _Str2 = _Str2 + 1;
      if (iVar3 == 0) break;
    } while (iVar3 == iVar4);
    iVar3 = iVar3 - iVar4;
  }
  return iVar3;
}


// ==== 0x673ca4 __strdup

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

char * __cdecl __strdup(char *_Src)

{
  size_t sVar1;
  void *pvVar2;
  char *pcVar3;
  
  if (_Src != (char *)0x0) {
    sVar1 = _strlen(_Src);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      pcVar3 = (char *)_strcpy(pvVar2,_Src);
      return pcVar3;
    }
  }
  return (char *)0x0;
}


// ==== 0x673ccf FUN_00673ccf

void FUN_00673ccf(void *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((*(int *)((int)param_1 + 0x3c) != DAT_00717e60) && (*(int *)((int)param_1 + 0x3c) != 0)) &&
     (**(int **)((int)param_1 + 0x2c) == 0)) {
    piVar1 = *(int **)((int)param_1 + 0x34);
    if (((piVar1 != (int *)0x0) && (*piVar1 == 0)) && (piVar1 != DAT_00792fac)) {
      _free(piVar1);
      ___free_lconv_mon(*(undefined4 *)((int)param_1 + 0x3c));
    }
    piVar1 = *(int **)((int)param_1 + 0x30);
    if (((piVar1 != (int *)0x0) && (*piVar1 == 0)) && (piVar1 != DAT_00792fb4)) {
      _free(piVar1);
      ___free_lconv_num(*(undefined4 *)((int)param_1 + 0x3c));
    }
    _free(*(void **)((int)param_1 + 0x2c));
    _free(*(void **)((int)param_1 + 0x3c));
  }
  piVar1 = *(int **)((int)param_1 + 0x40);
  if (((piVar1 != DAT_00792fa8) && (piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
    _free(piVar1);
    _free(*(void **)((int)param_1 + 0x44));
  }
  iVar2 = *(int *)((int)param_1 + 0x50);
  if (((iVar2 != DAT_00717e5c) && (iVar2 != 0)) && (*(int *)(iVar2 + 0xb4) == 0)) {
    ___free_lc_time(iVar2);
    _free(*(void **)((int)param_1 + 0x50));
  }
  _free(param_1);
  return;
}


// ==== 0x673d99 FUN_00673d99

int FUN_00673d99(void)

{
  int *piVar1;
  int *piVar2;
  _ptiddata p_Var3;
  
  p_Var3 = __getptd();
  piVar1 = (int *)p_Var3->_tfpecode;
  if (piVar1 != (int *)PTR_DAT_006eb554) {
    if (piVar1 != (int *)0x0) {
      piVar2 = (int *)piVar1[0xb];
      *piVar1 = *piVar1 + -1;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0xd];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0xc];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0x10];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      *(int *)(piVar1[0x13] + 0xb4) = *(int *)(piVar1[0x13] + 0xb4) + -1;
    }
    p_Var3->_tfpecode = (int)PTR_DAT_006eb554;
    *(int *)PTR_DAT_006eb554 = *(int *)PTR_DAT_006eb554 + 1;
    piVar2 = *(int **)(PTR_DAT_006eb554 + 0x2c);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    piVar2 = *(int **)(PTR_DAT_006eb554 + 0x34);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    piVar2 = *(int **)(PTR_DAT_006eb554 + 0x30);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    piVar2 = *(int **)(PTR_DAT_006eb554 + 0x40);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    *(int *)(*(int *)(PTR_DAT_006eb554 + 0x4c) + 0xb4) =
         *(int *)(*(int *)(PTR_DAT_006eb554 + 0x4c) + 0xb4) + 1;
    if (((piVar1 != (int *)0x0) && (*piVar1 == 0)) && (piVar1 != &DAT_006eb500)) {
      FUN_00673ccf(piVar1);
    }
  }
  return p_Var3->_tfpecode;
}


// ==== 0x673e5b __strcats

/* Library Function - Single Match
    __strcats
   
   Library: Visual Studio 2003 Release */

void __strcats(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (0 < param_2) {
    puVar1 = &param_2;
    iVar2 = param_2;
    do {
      puVar1 = puVar1 + 1;
      _strcat(param_1,*puVar1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x673e7f FUN_00673e7f

undefined4 FUN_00673e7f(char *param_1,char *param_2)

{
  char cVar1;
  size_t _Count;
  char *_Str;
  char *_Dest;
  
  _Str = param_2;
  _memset(param_1,0,0x90);
  if (*param_2 != '\0') {
    if ((*param_2 != '.') || (param_2[1] == '\0')) {
      param_2 = (char *)0x0;
      do {
        _Count = _strcspn(_Str,"_.,");
        if (_Count == 0) {
          return 0xffffffff;
        }
        cVar1 = _Str[_Count];
        if (param_2 == (char *)0x0) {
          if (0x3f < _Count) {
            return 0xffffffff;
          }
          _Dest = param_1;
          if (cVar1 == '.') {
            return 0xffffffff;
          }
        }
        else if (param_2 == (char *)0x1) {
          if (0x3f < _Count) {
            return 0xffffffff;
          }
          if (cVar1 == '_') {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x40;
        }
        else {
          if (param_2 != (char *)0x2) {
            return 0xffffffff;
          }
          if (0xf < _Count) {
            return 0xffffffff;
          }
          if ((cVar1 != '\0') && (cVar1 != ',')) {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x80;
        }
        _strncpy(_Dest,_Str,_Count);
        if ((cVar1 == ',') || (cVar1 == '\0')) {
          return 0;
        }
        param_2 = (char *)((int)param_2 + 1);
        _Str = _Str + _Count + 1;
      } while( true );
    }
    _strcpy(param_1 + 0x80,param_2 + 1);
  }
  return 0;
}


// ==== 0x673f51 ___lc_lctostr

/* Library Function - Single Match
    ___lc_lctostr
   
   Library: Visual Studio 2003 Release */

void ___lc_lctostr(undefined4 param_1,int param_2)

{
  _strcpy(param_1,param_2);
  if (*(char *)(param_2 + 0x40) != '\0') {
    __strcats(param_1,2,&DAT_006b7e1c,(char *)(param_2 + 0x40));
  }
  if (*(char *)(param_2 + 0x80) != '\0') {
    __strcats(param_1,2,&DAT_006bd5a0,(char *)(param_2 + 0x80));
  }
  return;
}


// ==== 0x673f9f ___updatetlocinfo

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetlocinfo
   
   Library: Visual Studio 2003 Release */

pthreadlocinfo __cdecl ___updatetlocinfo(void)

{
  pthreadlocinfo ptVar1;
  
  __lock(0xc);
  ptVar1 = (pthreadlocinfo)FUN_00673d99();
  FUN_00673fd1();
  return ptVar1;
}


// ==== 0x673fd1 FUN_00673fd1

void FUN_00673fd1(void)

{
  __unlock(0xc);
  return;
}


// ==== 0x673fda FUN_00673fda

undefined1 * FUN_00673fda(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  bVar1 = true;
  if (DAT_006eb694 == (undefined1 *)0x0) {
    DAT_006eb694 = _malloc(0x351);
    if (DAT_006eb694 == (undefined1 *)0x0) {
      return (undefined1 *)0x0;
    }
  }
  *DAT_006eb694 = 0;
  __strcats(DAT_006eb694,3,PTR_s_LC_COLLATE_006eb69c,&DAT_006ac1bc,PTR_DAT_006eb6a0);
  ppuVar3 = &PTR_DAT_006eb6a0;
  do {
    _strcat(DAT_006eb694,&DAT_006a0438);
    ppuVar4 = ppuVar3 + 3;
    iVar2 = _strcmp(*ppuVar3,*ppuVar4);
    if (iVar2 != 0) {
      bVar1 = false;
    }
    __strcats(DAT_006eb694,3,ppuVar3[2],&DAT_006ac1bc,*ppuVar4);
    ppuVar3 = ppuVar4;
  } while ((int)ppuVar4 < 0x6eb6d0);
  if (!bVar1) {
    return DAT_006eb694;
  }
  _free(DAT_006eb694);
  DAT_006eb694 = (undefined1 *)0x0;
  return PTR_DAT_006eb6ac;
}


// ==== 0x674099 FUN_00674099

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00674099(char *param_1,undefined *param_2,undefined2 *param_3,undefined4 *param_4)

{
  int iVar1;
  BOOL BVar2;
  uint unaff_retaddr;
  undefined1 local_98 [144];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (param_1 == (char *)0x0) {
    param_2 = (undefined *)0x0;
  }
  else if ((*param_1 == 'C') && (param_1[1] == '\0')) {
    param_2[1] = 0;
    *param_2 = 0x43;
    if (param_3 != (undefined2 *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    iVar1 = _strcmp(&DAT_006eb608,param_1);
    if ((iVar1 != 0) && (iVar1 = _strcmp(&DAT_006eb580,param_1), iVar1 != 0)) {
      iVar1 = FUN_00673e7f(local_98,param_1);
      if ((iVar1 != 0) ||
         (BVar2 = ___get_qualified_locale
                            ((LPLC_STRINGS)local_98,(UINT *)&DAT_00717ad8,(LPLC_STRINGS)local_98),
         BVar2 == 0)) {
        return (undefined *)0x0;
      }
      _DAT_00717ae0 = (uint)DAT_00717adc;
      ___lc_lctostr(&DAT_006eb608,local_98);
      if (*param_1 == '\0') {
        param_1 = &DAT_006eb608;
      }
      _strcpy(&DAT_006eb580,param_1);
    }
    if (param_3 != (undefined2 *)0x0) {
      _memcpy(param_3,&DAT_00717ad8,6);
    }
    if (param_4 != (undefined4 *)0x0) {
      _memcpy(param_4,&DAT_00717ae0,4);
    }
    _strcpy(param_2,&DAT_006eb608);
    param_2 = &DAT_006eb608;
  }
  return param_2;
}


// ==== 0x6741c5 FUN_006741c5

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006741c5(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  int *piVar7;
  BOOL BVar8;
  int unaff_ESI;
  uint unaff_retaddr;
  undefined1 local_1c4 [256];
  char local_c4 [132];
  undefined1 local_40 [8];
  int local_38;
  ushort local_30 [4];
  uint local_28;
  int local_20;
  LPWORD local_1c;
  void *local_18;
  undefined *local_14;
  LPWORD local_10;
  undefined *local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar4 = FUN_00674099(param_1,local_c4,local_30,&local_10);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = _strcmp(local_c4,(char *)(&DAT_006eb694)[unaff_ESI * 3]);
  if (iVar4 == 0) {
LAB_006743cb:
    uVar6 = (&DAT_006eb694)[unaff_ESI * 3];
  }
  else {
    sVar5 = _strlen(local_c4);
    local_18 = _malloc(sVar5 + 1);
    if (local_18 != (void *)0x0) {
      local_14 = (undefined *)(&DAT_006eb694)[unaff_ESI * 3];
      puVar1 = &DAT_00717e88 + unaff_ESI;
      local_28 = *puVar1;
      local_c = &DAT_00717eac + unaff_ESI * 6;
      _memcpy(local_40,local_c,6);
      local_1c = DAT_00717ea0;
      uVar6 = _strcpy(local_18,local_c4);
      (&DAT_006eb694)[unaff_ESI * 3] = uVar6;
      *puVar1 = (uint)local_30[0];
      _memcpy(local_c,local_30,6);
      uVar3 = DAT_006ec170;
      if (unaff_ESI == 2) {
        local_c = (undefined *)0x0;
        DAT_00717ea0 = local_10;
        local_20 = DAT_006eb57c;
        piVar7 = (int *)&DAT_006eb558;
        iVar4 = DAT_006eb578;
        do {
          if (local_10 == (LPWORD)*piVar7) {
            DAT_006eb558 = (&DAT_006eb558)[(int)local_c * 2];
            DAT_006eb55c = (&DAT_006eb55c)[(int)local_c * 2];
            (&DAT_006eb558)[(int)local_c * 2] = (LPWORD)iVar4;
            (&DAT_006eb55c)[(int)local_c * 2] = local_20;
            break;
          }
          local_38 = *piVar7;
          local_c = local_c + 1;
          *piVar7 = iVar4;
          iVar2 = piVar7[1];
          piVar7[1] = local_20;
          piVar7 = piVar7 + 2;
          iVar4 = local_38;
          local_20 = iVar2;
        } while ((int)piVar7 < 0x6eb580);
        uVar3 = DAT_006eb55c;
        if (local_c == (undefined *)0x5) {
          BVar8 = ___crtGetStringTypeA
                            ((_locale_t)0x1,0x6ac0e8,(LPCSTR)0x7f,(int)local_1c4,local_10,
                             DAT_00717e90,1);
          if (BVar8 == 0) {
            DAT_006eb55c = 0;
          }
          else {
            iVar4 = _memcmp(local_1c4,&DAT_006abfe8,0xfe);
            DAT_006eb55c = (uint)(iVar4 == 0);
          }
          DAT_006eb558 = DAT_00717ea0;
          uVar3 = DAT_006eb55c;
        }
      }
      DAT_006ec170 = uVar3;
      if (unaff_ESI == 1) {
        DAT_00717ea4 = local_10;
      }
      iVar4 = (**(code **)(&DAT_006eb698 + unaff_ESI * 0xc))();
      if (iVar4 == 0) {
        if (local_14 != &DAT_006eb4f8) {
          _free(local_14);
        }
        goto LAB_006743cb;
      }
      (&DAT_006eb694)[unaff_ESI * 3] = local_14;
      _free(local_18);
      *puVar1 = local_28;
      DAT_00717ea0 = local_1c;
    }
    uVar6 = 0;
  }
  return uVar6;
}


// ==== 0x6743e3 FUN_006743e3

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_006743e3(char *param_1,int param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  uint unaff_retaddr;
  char local_98 [132];
  int local_14;
  size_t local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (param_2 != 0) {
    if (param_1 == (char *)0x0) {
      return (&DAT_006eb694)[param_2 * 3];
    }
    uVar1 = FUN_006741c5(param_1);
    return uVar1;
  }
  local_10 = 1;
  local_c = 0;
  if (param_1 != (char *)0x0) {
    if (((*param_1 == 'L') && (param_1[1] == 'C')) && (param_1[2] == '_')) {
      do {
        pcVar2 = _strpbrk(param_1,"=;");
        if (((pcVar2 == (char *)0x0) || (local_10 = (int)pcVar2 - (int)param_1, local_10 == 0)) ||
           (*pcVar2 == ';')) {
          return 0;
        }
        local_14 = 1;
        ppuVar6 = &PTR_s_LC_COLLATE_006eb69c;
        do {
          iVar3 = _strncmp(*ppuVar6,param_1,local_10);
          if ((iVar3 == 0) && (sVar4 = _strlen(*ppuVar6), local_10 == sVar4)) break;
          local_14 = local_14 + 1;
          ppuVar6 = ppuVar6 + 3;
        } while ((int)ppuVar6 < 0x6eb6cd);
        pcVar2 = pcVar2 + 1;
        sVar4 = _strcspn(pcVar2,";");
        if ((sVar4 == 0) && (*pcVar2 != ';')) {
          return 0;
        }
        if (local_14 < 6) {
          _strncpy(local_98,pcVar2,sVar4);
          local_98[sVar4] = '\0';
          iVar3 = FUN_006741c5(local_98);
          if (iVar3 != 0) {
            local_c = local_c + 1;
          }
        }
      } while ((pcVar2[sVar4] != '\0') && (param_1 = pcVar2 + sVar4 + 1, *param_1 != '\0'));
      if (local_c == 0) {
        return 0;
      }
    }
    else {
      iVar3 = FUN_00674099(param_1,local_98,0,0,0);
      if (iVar3 == 0) {
        return 0;
      }
      puVar5 = &DAT_006eb694;
      do {
        if ((void **)puVar5 != &DAT_006eb694) {
          iVar3 = _strcmp(local_98,(char *)*puVar5);
          if ((iVar3 == 0) || (iVar3 = FUN_006741c5(local_98), iVar3 != 0)) {
            local_c = local_c + 1;
          }
          else {
            local_10 = 0;
          }
        }
        puVar5 = puVar5 + 3;
      } while ((int)puVar5 < 0x6eb6d1);
      if (local_10 != 0) {
        uVar1 = FUN_00673fda();
        _free(DAT_006eb694);
        DAT_006eb694 = (void *)0x0;
        return uVar1;
      }
      if (local_c == 0) {
        return 0;
      }
    }
  }
  uVar1 = FUN_00673fda();
  return uVar1;
}


// ==== 0x6745c2 _setlocale

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _setlocale
   
   Library: Visual Studio 2003 Release */

char * __cdecl _setlocale(int _Category,char *_Locale)

{
  undefined4 *_Memory;
  int iVar1;
  char *local_24;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006ac1c8;
  uStack_c = 0x6745ce;
  if ((_Category < 0) || (5 < _Category)) {
    local_24 = (char *)0x0;
  }
  else {
    __lock(0xc);
    local_8 = (undefined *)0x0;
    if (_Locale == (char *)0x0) {
      local_24 = (char *)FUN_006743e3();
      __local_unwind2(local_14,0xffffffff);
    }
    else {
      _Memory = _malloc(0x54);
      if (_Memory == (undefined4 *)0x0) {
        local_24 = (char *)0x0;
      }
      else {
        local_24 = (char *)FUN_006743e3();
        if (local_24 != (char *)0x0) {
          *_Memory = 0;
          _Memory[1] = DAT_00717ea0;
          _Memory[2] = DAT_00717ea4;
          for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
            _Memory[iVar1 + 3] = (&DAT_00717e88)[iVar1];
          }
          _Memory[9] = DAT_006ec170;
          _Memory[10] = DAT_006ec180;
          _Memory[0xb] = DAT_00792fb0;
          _Memory[0xc] = DAT_00792fb4;
          _Memory[0xd] = DAT_00792fac;
          _Memory[0xe] = PTR_PTR_006ec16c;
          _Memory[0xf] = DAT_00717e60;
          _Memory[0x10] = DAT_00792fa8;
          _Memory[0x11] = DAT_00792fa4;
          _Memory[0x12] = PTR_DAT_006ec130;
          _Memory[0x13] = PTR_PTR_006ec070;
          _Memory[0x14] = DAT_00717e5c;
          if ((*(int *)PTR_DAT_006eb554 == 0) && ((undefined4 *)PTR_DAT_006eb554 != &DAT_006eb500))
          {
            FUN_00673ccf(PTR_DAT_006eb554);
          }
          PTR_DAT_006eb554 = (undefined *)_Memory;
          FUN_00673d99();
        }
      }
      if ((local_24 == (char *)0x0) && (_Memory != (undefined4 *)0x0)) {
        _free(_Memory);
      }
      local_8 = (undefined *)0xffffffff;
      FUN_0067470b();
    }
  }
  return local_24;
}


// ==== 0x67470b FUN_0067470b

void FUN_0067470b(void)

{
  __unlock(0xc);
  return;
}


// ==== 0x674724 FUN_00674724

undefined4 FUN_00674724(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  int iVar3;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar2 = &stack0xfffffffc;
  if ((*(uint *)(param_1 + 4) & 6) == 0) {
    iStack_c = param_1;
    uStack_8 = param_3;
    *(int **)(param_2 + -4) = &iStack_c;
    iVar1 = *(int *)(param_2 + 8);
    for (iVar3 = *(int *)(param_2 + 0xc); iVar3 != -1; iVar3 = *(int *)(iVar1 + iVar3 * 0xc)) {
      if (*(int *)(iVar1 + 4 + iVar3 * 0xc) != 0) {
        iVar1 = (**(code **)(iVar1 + 4 + iVar3 * 0xc))();
        param_2 = *(int *)(puVar2 + 0xc);
        if (iVar1 != 0) {
          if (iVar1 < 0) {
            return 0;
          }
          iVar1 = *(int *)(param_2 + 8);
          __global_unwind2(param_2);
          puVar2 = (undefined1 *)(param_2 + 0x10);
          __local_unwind2(param_2,iVar3);
          FUN_0067342a(1);
          *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar1 + extraout_ECX * 4);
          (**(code **)(iVar1 + 8 + extraout_ECX * 4))();
        }
      }
      iVar1 = *(int *)(param_2 + 8);
    }
  }
  else {
    __local_unwind2(param_2,0xffffffff,&stack0xfffffffc,&stack0xfffffffc);
  }
  return 1;
}


// ==== 0x6747e1 FUN_006747e1

void FUN_006747e1(int param_1)

{
  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}


// ==== 0x674800 _strncmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


// ==== 0x674839 _vfprintf_674839

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _vfprintf_674839(FILE *_File,wchar_t *_Format,va_list _ArgList)

{
  int _Flag;
  int iVar1;
  
  __lock_file(_File);
  _Flag = __stbuf(_File);
  iVar1 = FUN_0067604e(_File,_Format,_ArgList);
  __ftbuf(_Flag,_File);
  FUN_0067488c();
  return iVar1;
}


// ==== 0x67488c FUN_0067488c

void FUN_0067488c(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + -0x1c));
  return;
}


// ==== 0x674898 _ftol_nocw

/* [canon] render V (C) docs/re/blur.md */

ulonglong _ftol_nocw(void)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uVar1 = (ulonglong)ROUND(in_ST0);
  local_20 = (uint)uVar1;
  uStack_1c = (float)(uVar1 >> 0x20);
  fVar3 = (float)in_ST0;
  if ((local_20 != 0) || (fVar3 = uStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
    if ((int)fVar3 < 0) {
      uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
    }
    else {
      uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
      uVar1 = CONCAT44((int)uStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
    }
  }
  return uVar1;
}


// ==== 0x67490d _bsearch

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl
_bsearch(void *_Key,void *_Base,size_t _NumOfElements,size_t _SizeOfElements,
        _PtFuncCompare *_PtFuncCompare)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  
  pvVar5 = (void *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
  if (_Base <= pvVar5) {
    do {
      uVar4 = _NumOfElements >> 1;
      if (uVar4 == 0) {
        if (_NumOfElements == 0) {
          return (void *)0x0;
        }
        iVar3 = (*_PtFuncCompare)(_Key,_Base);
        return (void *)(~-(uint)(iVar3 != 0) & (uint)_Base);
      }
      uVar1 = uVar4;
      if ((_NumOfElements & 1) == 0) {
        uVar1 = uVar4 - 1;
      }
      pvVar2 = (void *)(uVar1 * _SizeOfElements + (int)_Base);
      iVar3 = (*_PtFuncCompare)(_Key,pvVar2);
      if (iVar3 == 0) {
        return pvVar2;
      }
      if (iVar3 < 0) {
        pvVar5 = (void *)((int)pvVar2 - _SizeOfElements);
        if ((_NumOfElements & 1) == 0) {
          uVar4 = uVar4 - 1;
        }
      }
      else {
        _Base = (void *)((int)pvVar2 + _SizeOfElements);
      }
      _NumOfElements = uVar4;
    } while (_Base <= pvVar5);
  }
  return (void *)0x0;
}


// ==== 0x674999 FUN_00674999

void FUN_00674999(DWORD param_1)

{
  _ptiddata p_Var1;
  
  if (PTR_FUN_006eb460 != (undefined *)0x0) {
    (*(code *)PTR_FUN_006eb460)();
  }
  p_Var1 = __getptd();
  if (p_Var1 == (_ptiddata)0x0) {
    __amsg_exit(0x10);
  }
  FUN_0067593c(p_Var1);
                    /* WARNING: Subroutine does not return */
  ExitThread(param_1);
}


// ==== 0x6749ca FUN_006749ca

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_006749ca(DWORD *param_1)

{
  DWORD *pDVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 uVar4;
  
  pDVar1 = TlsGetValue(DAT_006eb864);
  if (pDVar1 == (DWORD *)0x0) {
    BVar2 = TlsSetValue(DAT_006eb864,param_1);
    if (BVar2 == 0) {
      __amsg_exit(0x10);
    }
    DVar3 = GetCurrentThreadId();
    *param_1 = DVar3;
    pDVar1 = param_1;
  }
  else {
    pDVar1[0x13] = param_1[0x13];
    pDVar1[0x14] = param_1[0x14];
    _free(param_1);
  }
  if (PTR_FUN_006eb45c != (undefined *)0x0) {
    (*(code *)PTR_FUN_006eb45c)();
  }
  uVar4 = (*(code *)pDVar1[0x13])(pDVar1[0x14]);
  FUN_00674999(uVar4);
  return 0;
}


// ==== 0x674a4e FUN_00674a4e

void FUN_00674a4e(void)

{
  ulong _ExceptionNum;
  int unaff_EBP;
  
  _ExceptionNum = (*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14))->ExceptionRecord->ExceptionCode;
  *(ulong *)(unaff_EBP + -0x1c) = _ExceptionNum;
  __XcptFilter(_ExceptionNum,*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14));
  return;
}


// ==== 0x674a62 FUN_00674a62

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00674a62(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x1c);
                    /* WARNING: Subroutine does not return */
  *(undefined **)(iVar1 + -8) = &UNK_00674a6d;
  __exit(*(int *)(iVar1 + -4));
}


// ==== 0x674a6e __beginthreadex

/* Library Function - Single Match
    __beginthreadex
   
   Library: Visual Studio 2003 Release */

uintptr_t __cdecl
__beginthreadex(void *_Security,uint _StackSize,_StartAddress *_StartAddress,void *_ArgList,
               uint _InitFlag,uint *_ThrdAddr)

{
  _StartAddress *p_Var1;
  undefined4 *puVar2;
  _ptiddata _Ptd;
  _StartAddress **lpThreadId;
  HANDLE pvVar3;
  DWORD DVar4;
  pthreadlocinfo unaff_ESI;
  
  p_Var1 = _StartAddress;
  DVar4 = 0;
  if (_StartAddress == (_StartAddress *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
  }
  else {
    _Ptd = _calloc(1,0x88);
    if (_Ptd != (_ptiddata)0x0) {
      __initptd(_Ptd,unaff_ESI);
      _Ptd->_thandle = 0xffffffff;
      *(void **)(_Ptd->_con_ch_buf + 4) = _ArgList;
      *(_StartAddress **)_Ptd->_con_ch_buf = p_Var1;
      lpThreadId = (_StartAddress **)_ThrdAddr;
      if (_ThrdAddr == (uint *)0x0) {
        lpThreadId = &_StartAddress;
      }
      pvVar3 = CreateThread(_Security,_StackSize,FUN_006749ca,_Ptd,_InitFlag,(LPDWORD)lpThreadId);
      if (pvVar3 != (HANDLE)0x0) {
        return (uintptr_t)pvVar3;
      }
      DVar4 = GetLastError();
    }
    _free(_Ptd);
    if (DVar4 != 0) {
      __dosmaperr(DVar4);
    }
  }
  return 0;
}


// ==== 0x674b00 __aulldiv

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;
  
  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}


// ==== 0x674b68 FUN_00674b68

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_00674b68(byte *param_1,byte *param_2)

{
  byte bVar1;
  _ptiddata p_Var2;
  int iVar3;
  byte *pbVar4;
  uint unaff_retaddr;
  byte local_28 [32];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  p_Var2 = __getptd();
  pbVar4 = local_28;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  do {
    bVar1 = *param_2;
    local_28[bVar1 >> 3] = local_28[bVar1 >> 3] | '\x01' << (bVar1 & 7);
    param_2 = param_2 + 1;
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)p_Var2->_token;
  }
  for (; (bVar1 = *param_1, pbVar4 = param_1, (local_28[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0
         && (bVar1 != 0)); param_1 = param_1 + 1) {
  }
  do {
    if (*pbVar4 == 0) {
LAB_00674c03:
      p_Var2->_token = (char *)pbVar4;
      return -(uint)(param_1 != pbVar4) & (uint)param_1;
    }
    if ((local_28[*pbVar4 >> 3] & (byte)(1 << (*pbVar4 & 7))) != 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar4 + 1;
      goto LAB_00674c03;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}


// ==== 0x674c30 _strlen

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_00674c60;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00674c93:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00674c60:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_00674c93;
}


// ==== 0x674cbb strtoxl

/* Library Function - Single Match
    _strtoxl
   
   Library: Visual Studio 2003 Release */

uint __cdecl strtoxl(byte *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  uint local_8;
  
  p_Var2 = __getptd();
  ptVar3 = (pthreadlocinfo)p_Var2->_tfpecode;
  if (ptVar3 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar3 = ___updatetlocinfo();
  }
  local_8 = 0;
  bVar8 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    pbVar9 = pbVar1 + 1;
    if ((int)ptVar3->lc_category[1].refcount < 2) {
      uVar4 = *(byte *)((int)ptVar3->lc_category[3].refcount + (uint)bVar8 * 2) & 8;
    }
    else {
      uVar4 = _isctype(ptVar3,(uint)bVar8,8);
    }
    if (uVar4 == 0) break;
    bVar8 = *pbVar9;
    pbVar1 = pbVar9;
  }
  if (bVar8 == 0x2d) {
    param_4 = param_4 | 2;
LAB_00674d22:
    bVar8 = *pbVar9;
    pbVar9 = pbVar1 + 2;
  }
  else if (bVar8 == 0x2b) goto LAB_00674d22;
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar8 != 0x30) {
      param_3 = 10;
      goto LAB_00674d85;
    }
    if ((*pbVar9 != 0x78) && (*pbVar9 != 0x58)) {
      param_3 = 8;
      goto LAB_00674d85;
    }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (bVar8 == 0x30)) && ((*pbVar9 == 0x78 || (*pbVar9 == 0x58)))) {
    bVar8 = pbVar9[1];
    pbVar9 = pbVar9 + 2;
  }
LAB_00674d85:
  uVar4 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    if ((*(ushort *)(PTR_DAT_006ec130 + (uint)bVar8 * 2) & 4) == 0) {
      if ((*(ushort *)(PTR_DAT_006ec130 + (uint)bVar8 * 2) & 0x103) == 0) {
LAB_00674df1:
        pbVar9 = pbVar9 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            pbVar9 = param_1;
          }
          local_8 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < local_8)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_8)))))))) {
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            local_8 = ((param_4 & 2) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = pbVar9;
        }
        if ((param_4 & 2) == 0) {
          return local_8;
        }
        return -local_8;
      }
      if (((char)bVar8 < 'a') || ('z' < (char)bVar8)) {
        iVar7 = (int)(char)bVar8;
      }
      else {
        iVar7 = (char)bVar8 + -0x20;
      }
      uVar6 = iVar7 - 0x37;
    }
    else {
      uVar6 = (int)(char)bVar8 - 0x30;
    }
    if (param_3 <= uVar6) goto LAB_00674df1;
    if ((local_8 < uVar4) ||
       ((local_8 == uVar4 && (uVar6 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_8 = local_8 * param_3 + uVar6;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar8 = *pbVar9;
    pbVar9 = pbVar9 + 1;
  } while( true );
}


// ==== 0x674e7a _strtol

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

long __cdecl _strtol(char *_Str,char **_EndPtr,int _Radix)

{
  long lVar1;
  
  lVar1 = strtoxl(_Str,_EndPtr,_Radix,0);
  return lVar1;
}


// ==== 0x674e91 report_failure

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* Library Function - Single Match
    _report_failure
   
   Library: Visual Studio 2003 Release */

void __cdecl report_failure(void)

{
  FUN_0067ff4b(1,0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(3);
}


// ==== 0x674eae FUN_00674eae

undefined4 FUN_00674eae(void)

{
  return 1;
}


// ==== 0x674eb2 FUN_00674eb2

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00674eb2(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 3;
                    /* WARNING: Subroutine does not return */
  *(undefined **)(iVar1 + -8) = &UNK_00674ec1;
  ExitProcess(*(UINT *)(iVar1 + -4));
}


// ==== 0x674ec2 __security_check_cookie

/* WARNING: This is an inlined function */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __fastcall __security_check_cookie(uintptr_t _StackCookie)

{
  if (_StackCookie == DAT_006eb720) {
    return;
  }
  report_failure();
  return;
}


// ==== 0x674ed0 FID_conflict:__time32

/* Library Function - Multiple Matches With Different Base Names
    __time32
    _time
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

__time32_t __cdecl FID_conflict___time32(__time32_t *_Time)

{
  __time32_t _Var1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  _Var1 = __aulldiv(local_c.dwLowDateTime + 0x2ac18000,
                    local_c.dwHighDateTime + 0xfe624e21 + (uint)(0xd53e7fff < local_c.dwLowDateTime)
                    ,10000000,0);
  if (_Time != (__time32_t *)0x0) {
    *_Time = _Var1;
  }
  return _Var1;
}


// ==== 0x674f09 __NMSG_WRITE

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __NMSG_WRITE(DWORD param_1)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  size_t sVar4;
  size_t sVar5;
  HANDLE hFile;
  CHAR *pCVar6;
  CHAR *pCVar7;
  int iVar8;
  CHAR *_Dest;
  uint unaff_retaddr;
  undefined4 uStackY_14c;
  UINT aUStackY_148 [3];
  undefined1 auStackY_13c [4];
  undefined4 uStackY_138;
  undefined4 uStackY_134;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR local_110 [260];
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar2 = 0;
  do {
    if (param_1 == (&DAT_006eb728)[uVar2 * 2]) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x12);
  iVar8 = uVar2 * 8;
  if (param_1 == (&DAT_006eb728)[uVar2 * 2]) {
    if ((DAT_00717a7c == 1) || ((DAT_00717a7c == 0 && (DAT_006eb1b8 == 1)))) {
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &param_1;
      sVar4 = _strlen(*(char **)(iVar8 + 0x6eb72c));
      lpBuffer = *(LPCVOID *)(iVar8 + 0x6eb72c);
      uStackY_134 = 0x675063;
      hFile = GetStdHandle(0xfffffff4);
      uStackY_134 = 0x67506a;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      local_c = 0;
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_110,0x104);
      if (DVar3 == 0) {
        _strcpy();
      }
      _Dest = local_110;
      sVar4 = _strlen(local_110);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(local_110);
        _Dest = (CHAR *)((int)&uStackY_14c + sVar4 + 1);
        _strncpy(_Dest,"...",3);
      }
      sVar4 = _strlen(_Dest);
      sVar5 = _strlen(*(char **)(iVar8 + 0x6eb72c));
      iVar1 = -(sVar4 + sVar5 + 0x1f & 0xfffffffc);
      *(char **)(local_110 + iVar1 + -0x10) = "Runtime Error!\n\nProgram: ";
      *(CHAR **)(local_110 + iVar1 + -0x14) = local_110 + iVar1 + -0xc;
      pCVar6 = local_110 + iVar1 + -0x18;
      pCVar6[0] = '\x12';
      pCVar6[1] = 'P';
      pCVar6[2] = 'g';
      pCVar6[3] = '\0';
      _strcpy();
      *(CHAR **)(local_110 + iVar1 + -0x18) = _Dest;
      *(CHAR **)(local_110 + iVar1 + -0x1c) = local_110 + iVar1 + -0xc;
      pCVar7 = local_110 + iVar1 + -0x20;
      pCVar7[0] = '\x19';
      pCVar7[1] = 'P';
      pCVar7[2] = 'g';
      pCVar7[3] = '\0';
      _strcat();
      *(undefined **)(local_110 + iVar1 + -0x20) = &DAT_006b8a50;
      *(CHAR **)((int)&uStackY_134 + iVar1) = local_110 + iVar1 + -0xc;
      *(undefined4 *)((int)&uStackY_138 + iVar1) = 0x675024;
      _strcat();
      *(undefined4 *)((int)&uStackY_138 + iVar1) = *(undefined4 *)(iVar8 + 0x6eb72c);
      *(CHAR **)(auStackY_13c + iVar1) = local_110 + iVar1 + -0xc;
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 8) = 0x675030;
      _strcat();
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 8) = 0x12010;
      *(char **)((int)aUStackY_148 + iVar1 + 4) = "Microsoft Visual C++ Runtime Library";
      *(CHAR **)((int)aUStackY_148 + iVar1) = local_110 + iVar1 + -0xc;
      *(undefined4 *)((int)&uStackY_14c + iVar1) = 0x675040;
      ___crtMessageBoxA(*(LPCSTR *)((int)aUStackY_148 + iVar1),
                        *(LPCSTR *)((int)aUStackY_148 + iVar1 + 4),
                        *(UINT *)((int)aUStackY_148 + iVar1 + 8));
    }
  }
  return;
}


// ==== 0x675080 __FF_MSGBANNER

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00717a7c == 1) || ((DAT_00717a7c == 0 && (DAT_006eb1b8 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00717b08 != (code *)0x0) {
      (*DAT_00717b08)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== 0x6750b9 __XcptFilter

/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2003 Release */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  ulong *puVar1;
  code *pcVar2;
  void *pvVar3;
  ulong uVar4;
  void *pvVar5;
  _ptiddata p_Var6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  
  p_Var6 = __getptd();
  puVar1 = p_Var6->_initaddr;
  puVar9 = puVar1;
  do {
    if (*puVar9 == _ExceptionNum) break;
    puVar9 = puVar9 + 3;
  } while (puVar9 < puVar1 + DAT_006eb83c * 3);
  if ((puVar1 + DAT_006eb83c * 3 <= puVar9) || (*puVar9 != _ExceptionNum)) {
    puVar9 = (ulong *)0x0;
  }
  if ((puVar9 == (ulong *)0x0) || (pcVar2 = (code *)puVar9[2], pcVar2 == (code *)0x0)) {
    iVar7 = UnhandledExceptionFilter(_ExceptionPtr);
  }
  else if (pcVar2 == (code *)0x5) {
    puVar9[2] = 0;
    iVar7 = 1;
  }
  else {
    if (pcVar2 != (code *)0x1) {
      pvVar3 = p_Var6->_initarg;
      p_Var6->_initarg = _ExceptionPtr;
      if (puVar9[1] == 8) {
        if (DAT_006eb830 < DAT_006eb834 + DAT_006eb830) {
          iVar8 = DAT_006eb830 * 0xc;
          iVar7 = DAT_006eb830;
          do {
            *(undefined4 *)(iVar8 + 8 + (int)p_Var6->_initaddr) = 0;
            iVar7 = iVar7 + 1;
            iVar8 = iVar8 + 0xc;
          } while (iVar7 < DAT_006eb834 + DAT_006eb830);
        }
        uVar4 = *puVar9;
        pvVar5 = p_Var6->_pxcptacttab;
        if (uVar4 == 0xc000008e) {
          p_Var6->_pxcptacttab = (void *)0x83;
        }
        else if (uVar4 == 0xc0000090) {
          p_Var6->_pxcptacttab = (void *)0x81;
        }
        else if (uVar4 == 0xc0000091) {
          p_Var6->_pxcptacttab = (void *)0x84;
        }
        else if (uVar4 == 0xc0000093) {
          p_Var6->_pxcptacttab = (void *)0x85;
        }
        else if (uVar4 == 0xc000008d) {
          p_Var6->_pxcptacttab = (void *)0x82;
        }
        else if (uVar4 == 0xc000008f) {
          p_Var6->_pxcptacttab = (void *)0x86;
        }
        else if (uVar4 == 0xc0000092) {
          p_Var6->_pxcptacttab = (void *)0x8a;
        }
        (*pcVar2)(8,p_Var6->_pxcptacttab);
        p_Var6->_pxcptacttab = pvVar5;
      }
      else {
        puVar9[2] = 0;
        (*pcVar2)(puVar9[1]);
      }
      p_Var6->_initarg = pvVar3;
    }
    iVar7 = -1;
  }
  return iVar7;
}


// ==== 0x67521d __setenvp

/* Library Function - Single Match
    __setenvp
   
   Library: Visual Studio 2003 Release */

int __cdecl __setenvp(void)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  
  if (DAT_0079334c == 0) {
    ___initmbctable();
  }
  iVar5 = 0;
  pcVar4 = DAT_00717a74;
  if (DAT_00717a74 != (char *)0x0) {
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + sVar2 + 1) {
      if (*pcVar4 != '=') {
        iVar5 = iVar5 + 1;
      }
      sVar2 = _strlen(pcVar4);
    }
    puVar1 = _malloc(iVar5 * 4 + 4);
    pcVar4 = DAT_00717a74;
    DAT_00717aa8 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      do {
        if (*pcVar4 == '\0') {
          _free(DAT_00717a74);
          DAT_00717a74 = (char *)0x0;
          *puVar1 = 0;
          DAT_00793340 = 1;
          return 0;
        }
        sVar2 = _strlen(pcVar4);
        if (*pcVar4 != '=') {
          pvVar3 = _malloc(sVar2 + 1);
          *puVar1 = pvVar3;
          if (pvVar3 == (void *)0x0) {
            _free(DAT_00717aa8);
            DAT_00717aa8 = (undefined4 *)0x0;
            return -1;
          }
          _strcpy(pvVar3,pcVar4);
          puVar1 = puVar1 + 1;
        }
        pcVar4 = pcVar4 + sVar2 + 1;
      } while( true );
    }
  }
  return -1;
}


// ==== 0x6752e4 FUN_006752e4

void __thiscall FUN_006752e4(byte *param_1,undefined4 *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  byte *in_EAX;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  int *unaff_ESI;
  
  bVar1 = false;
  *unaff_ESI = 0;
  *param_3 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
    param_2 = param_2 + 1;
  }
  do {
    if (*in_EAX == 0x22) {
      bVar1 = !bVar1;
      pbVar3 = in_EAX + 1;
      bVar5 = 0x22;
    }
    else {
      *unaff_ESI = *unaff_ESI + 1;
      if (param_1 != (byte *)0x0) {
        *param_1 = *in_EAX;
        param_1 = param_1 + 1;
      }
      bVar5 = *in_EAX;
      pbVar3 = in_EAX + 1;
      if ((*(byte *)((int)&DAT_00792fe0 + bVar5 + 1) & 4) != 0) {
        *unaff_ESI = *unaff_ESI + 1;
        if (param_1 != (byte *)0x0) {
          *param_1 = *pbVar3;
          param_1 = param_1 + 1;
        }
        pbVar3 = in_EAX + 2;
      }
      if (bVar5 == 0) {
        pbVar3 = pbVar3 + -1;
        goto LAB_0067535d;
      }
    }
    in_EAX = pbVar3;
  } while ((bVar1) || ((bVar5 != 0x20 && (bVar5 != 9))));
  if (param_1 != (byte *)0x0) {
    param_1[-1] = 0;
  }
LAB_0067535d:
  bVar1 = false;
  while (*pbVar3 != 0) {
    for (; (*pbVar3 == 0x20 || (*pbVar3 == 9)); pbVar3 = pbVar3 + 1) {
    }
    if (*pbVar3 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
      param_2 = param_2 + 1;
    }
    *param_3 = *param_3 + 1;
    while( true ) {
      bVar2 = true;
      uVar6 = 0;
      for (; *pbVar3 == 0x5c; pbVar3 = pbVar3 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar3 == 0x22) {
        pbVar4 = pbVar3;
        if ((uVar6 & 1) == 0) {
          if ((!bVar1) || (pbVar4 = pbVar3 + 1, *pbVar4 != 0x22)) {
            bVar2 = false;
            pbVar4 = pbVar3;
          }
          bVar1 = !bVar1;
        }
        uVar6 = uVar6 >> 1;
        pbVar3 = pbVar4;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_1 != (byte *)0x0) {
          *param_1 = 0x5c;
          param_1 = param_1 + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      bVar5 = *pbVar3;
      if ((bVar5 == 0) || ((!bVar1 && ((bVar5 == 0x20 || (bVar5 == 9)))))) break;
      if (bVar2) {
        if (param_1 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_00792fe0 + bVar5 + 1) & 4) != 0) {
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_00792fe0 + bVar5 + 1) & 4) != 0) {
            *param_1 = bVar5;
            param_1 = param_1 + 1;
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
          *param_1 = *pbVar3;
          param_1 = param_1 + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      pbVar3 = pbVar3 + 1;
    }
    if (param_1 != (byte *)0x0) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
    *unaff_ESI = *unaff_ESI + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_3 = *param_3 + 1;
  return;
}


// ==== 0x675450 FUN_00675450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00675450(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = param_1;
  if (DAT_0079334c == 0) {
    ___initmbctable();
  }
  DAT_00717c14 = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_00717b10,0x104);
  _DAT_00717ab8 = &DAT_00717b10;
  FUN_006752e4(0,&local_8);
  pvVar1 = _malloc(param_1 + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_006752e4(pvVar1,&local_8);
    DAT_00717a9c = local_8 + -1;
    uVar2 = 0;
    DAT_00717aa0 = pvVar1;
  }
  return uVar2;
}


// ==== 0x6754f2 ___crtGetEnvironmentStringsA

/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 2003 Release */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char cVar1;
  WCHAR WVar2;
  DWORD DVar3;
  WCHAR *pWVar4;
  int iVar6;
  size_t _Size;
  LPSTR lpMultiByteStr;
  LPCH _Src;
  char *pcVar7;
  void *_Dst;
  LPWCH lpWideCharStr;
  LPSTR local_8;
  WCHAR *pWVar5;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  if (DAT_00717c18 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_00717c18 = 1;
      goto LAB_00675540;
    }
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_00717c18 = 2;
    }
  }
  if (DAT_00717c18 != 1) {
    if ((DAT_00717c18 != 2) && (DAT_00717c18 != 0)) {
      return (LPVOID)0x0;
    }
    _Src = GetEnvironmentStrings();
    if (_Src == (LPCH)0x0) {
      return (LPVOID)0x0;
    }
    cVar1 = *_Src;
    pcVar7 = _Src;
    while (cVar1 != '\0') {
      do {
        pcVar8 = pcVar7;
        pcVar7 = pcVar8 + 1;
      } while (*pcVar7 != '\0');
      pcVar7 = pcVar8 + 2;
      cVar1 = *pcVar7;
    }
    _Dst = _malloc((size_t)(pcVar7 + (1 - (int)_Src)));
    if (_Dst == (void *)0x0) {
      _Dst = (void *)0x0;
    }
    else {
      _memcpy(_Dst,_Src,(size_t)(pcVar7 + (1 - (int)_Src)));
    }
    FreeEnvironmentStringsA(_Src);
    return _Dst;
  }
LAB_00675540:
  if ((lpWideCharStr == (LPWCH)0x0) &&
     (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
    return (LPVOID)0x0;
  }
  WVar2 = *lpWideCharStr;
  pWVar4 = lpWideCharStr;
  while (WVar2 != L'\0') {
    do {
      pWVar5 = pWVar4;
      pWVar4 = pWVar5 + 1;
    } while (*pWVar4 != L'\0');
    pWVar4 = pWVar5 + 2;
    WVar2 = *pWVar4;
  }
  iVar6 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
  _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  local_8 = (LPSTR)0x0;
  if (((_Size != 0) && (lpMultiByteStr = _malloc(_Size), lpMultiByteStr != (LPSTR)0x0)) &&
     (iVar6 = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                  (LPBOOL)0x0), local_8 = lpMultiByteStr, iVar6 == 0)) {
    _free(lpMultiByteStr);
    local_8 = (LPSTR)0x0;
  }
  FreeEnvironmentStringsW(lpWideCharStr);
  return local_8;
}


// ==== 0x675614 FUN_00675614

undefined4 FUN_00675614(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  DWORD DVar6;
  int iVar7;
  HANDLE hFile;
  int iVar8;
  uint uVar9;
  UINT *pUVar10;
  UINT UVar11;
  UINT UVar12;
  byte *local_48;
  _STARTUPINFOA local_44;
  
  puVar3 = _malloc(0x480);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    DAT_00793224 = 0x20;
    DAT_00793240 = puVar3;
    for (; puVar3 < DAT_00793240 + 0x120; puVar3 = puVar3 + 9) {
      *(undefined1 *)(puVar3 + 1) = 0;
      *puVar3 = 0xffffffff;
      puVar3[2] = 0;
      *(undefined1 *)((int)puVar3 + 5) = 10;
    }
    GetStartupInfoA(&local_44);
    if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
      UVar11 = *(UINT *)local_44.lpReserved2;
      pUVar10 = (UINT *)((int)local_44.lpReserved2 + 4);
      local_48 = (byte *)(UVar11 + (int)pUVar10);
      if (0x7ff < (int)UVar11) {
        UVar11 = 0x800;
      }
      UVar12 = UVar11;
      if ((int)DAT_00793224 < (int)UVar11) {
        puVar3 = &DAT_00793244;
        do {
          puVar5 = _malloc(0x480);
          UVar12 = DAT_00793224;
          if (puVar5 == (undefined4 *)0x0) break;
          DAT_00793224 = DAT_00793224 + 0x20;
          *puVar3 = puVar5;
          puVar2 = puVar5;
          for (; puVar5 < puVar2 + 0x120; puVar5 = puVar5 + 9) {
            *(undefined1 *)(puVar5 + 1) = 0;
            *puVar5 = 0xffffffff;
            puVar5[2] = 0;
            *(undefined1 *)((int)puVar5 + 5) = 10;
            puVar2 = (undefined4 *)*puVar3;
          }
          puVar3 = puVar3 + 1;
          UVar12 = UVar11;
        } while ((int)DAT_00793224 < (int)UVar11);
      }
      uVar9 = 0;
      if (0 < (int)UVar12) {
        do {
          if (((*(HANDLE *)local_48 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
             (((*pUVar10 & 8) != 0 || (DVar6 = GetFileType(*(HANDLE *)local_48), DVar6 != 0)))) {
            puVar3 = (undefined4 *)((int)(&DAT_00793240)[(int)uVar9 >> 5] + (uVar9 & 0x1f) * 0x24);
            *puVar3 = *(undefined4 *)local_48;
            *(byte *)(puVar3 + 1) = (byte)*pUVar10;
            iVar7 = ___crtInitCritSecAndSpinCount(puVar3 + 3,4000);
            if (iVar7 == 0) {
              return 0xffffffff;
            }
            puVar3[2] = puVar3[2] + 1;
          }
          local_48 = local_48 + 4;
          uVar9 = uVar9 + 1;
          pUVar10 = (UINT *)((int)pUVar10 + 1);
        } while ((int)uVar9 < (int)UVar12);
      }
    }
    iVar7 = 0;
    do {
      piVar1 = DAT_00793240 + iVar7 * 9;
      if (*piVar1 == -1) {
        *(undefined1 *)(piVar1 + 1) = 0x81;
        if (iVar7 == 0) {
          DVar6 = 0xfffffff6;
        }
        else {
          DVar6 = 0xfffffff5 - (iVar7 != 1);
        }
        hFile = GetStdHandle(DVar6);
        if ((hFile == (HANDLE)0xffffffff) || (DVar6 = GetFileType(hFile), DVar6 == 0)) {
          *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x40;
        }
        else {
          *piVar1 = (int)hFile;
          if ((DVar6 & 0xff) == 2) {
            *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x40;
          }
          else if ((DVar6 & 0xff) == 3) {
            *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 8;
          }
          iVar8 = ___crtInitCritSecAndSpinCount(piVar1 + 3,4000);
          if (iVar8 == 0) {
            return 0xffffffff;
          }
          piVar1[2] = piVar1[2] + 1;
        }
      }
      else {
        *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x80;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 3);
    SetHandleCount(DAT_00793224);
    uVar4 = 0;
  }
  return uVar4;
}


// ==== 0x675812 FUN_00675812

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_00675812(void)

{
  undefined4 *local_20;
  
  for (local_20 = &DAT_006cce94; local_20 < &DAT_006cce94; local_20 = local_20 + 1) {
    if ((code *)*local_20 != (code *)0x0) {
      (*(code *)*local_20)();
    }
  }
  return;
}


// ==== 0x67583f FUN_0067583f

undefined4 FUN_0067583f(void)

{
  return 1;
}


// ==== 0x675843 FUN_00675843

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00675843(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (&UNK_006cce93 < *(undefined **)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x67583d;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x675855;
  return;
}


// ==== 0x675856 FUN_00675856

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_00675856(void)

{
  undefined4 *puStack_20;
  
  for (puStack_20 = &DAT_006cce9c; puStack_20 < &DAT_006cce9c; puStack_20 = puStack_20 + 1) {
    if ((code *)*puStack_20 != (code *)0x0) {
      (*(code *)*puStack_20)();
    }
  }
  return;
}


// ==== 0x675883 FUN_00675883

undefined4 FUN_00675883(void)

{
  return 1;
}


// ==== 0x675887 FUN_00675887

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00675887(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (&UNK_006cce9b < *(undefined **)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x675881;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x675899;
  return;
}


// ==== 0x67589a FUN_0067589a

void FUN_0067589a(void)

{
  __mtdeletelocks();
  if (DAT_006eb864 != 0xffffffff) {
    TlsFree(DAT_006eb864);
    DAT_006eb864 = 0xffffffff;
  }
  return;
}


// ==== 0x6758b8 __initptd

/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 2003 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  _Ptd->_initaddr = &DAT_006eb7b8;
  _Ptd->_holdrand = 1;
  return;
}


// ==== 0x6758cb __getptd

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

_ptiddata __cdecl __getptd(void)

{
  DWORD dwErrCode;
  _ptiddata lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_006eb864);
  if (lpTlsValue == (_ptiddata)0x0) {
    lpTlsValue = _calloc(1,0x88);
    if (lpTlsValue != (_ptiddata)0x0) {
      BVar1 = TlsSetValue(DAT_006eb864,lpTlsValue);
      if (BVar1 != 0) {
        lpTlsValue->_initaddr = &DAT_006eb7b8;
        lpTlsValue->_holdrand = 1;
        DVar2 = GetCurrentThreadId();
        lpTlsValue->_thandle = 0xffffffff;
        lpTlsValue->_tid = DVar2;
        goto LAB_00675930;
      }
    }
    __amsg_exit(0x10);
  }
LAB_00675930:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


// ==== 0x67593c FUN_0067593c

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_0067593c(LPVOID param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_006eb864 != 0xffffffff) {
    if ((param_1 != (void *)0x0) || (param_1 = TlsGetValue(DAT_006eb864), param_1 != (LPVOID)0x0)) {
      if (*(void **)((int)param_1 + 0x24) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x24));
      }
      if (*(void **)((int)param_1 + 0x2c) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x2c));
      }
      if (*(void **)((int)param_1 + 0x34) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x34));
      }
      if (*(void **)((int)param_1 + 0x3c) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x3c));
      }
      if (*(void **)((int)param_1 + 0x44) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x44));
      }
      if (*(void **)((int)param_1 + 0x48) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x48));
      }
      if (*(undefined **)((int)param_1 + 0x54) != &DAT_006eb7b8) {
        _free(*(undefined **)((int)param_1 + 0x54));
      }
      __lock(0xd);
      piVar1 = *(int **)((int)param_1 + 0x60);
      if (((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) &&
         (piVar1 != DAT_00792fc4)) {
        _free(piVar1);
      }
      FUN_00675a92();
      __lock(0xc);
      piVar1 = *(int **)((int)param_1 + 100);
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + -1;
        piVar2 = (int *)piVar1[0xb];
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + -1;
        }
        piVar2 = (int *)piVar1[0xd];
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + -1;
        }
        piVar2 = (int *)piVar1[0xc];
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + -1;
        }
        piVar2 = (int *)piVar1[0x10];
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + -1;
        }
        *(int *)(piVar1[0x13] + 0xb4) = *(int *)(piVar1[0x13] + 0xb4) + -1;
        if (((piVar1 != (int *)PTR_DAT_006eb554) && (piVar1 != &DAT_006eb500)) && (*piVar1 == 0)) {
          FUN_00673ccf(piVar1);
        }
      }
      FUN_00675a9e();
      _free(param_1);
    }
    TlsSetValue(DAT_006eb864,(LPVOID)0x0);
    return;
  }
  return;
}


// ==== 0x675a8f FUN_00675a8f

void FUN_00675a8f(void)

{
  __unlock(0xd);
  return;
}


// ==== 0x675a92 FUN_00675a92

void FUN_00675a92(void)

{
  __unlock(0xd);
  return;
}


// ==== 0x675a9b FUN_00675a9b

void FUN_00675a9b(void)

{
  __unlock(0xc);
  return;
}


// ==== 0x675a9e FUN_00675a9e

void FUN_00675a9e(void)

{
  __unlock(0xc);
  return;
}


// ==== 0x675aa7 FUN_00675aa7

undefined4 FUN_00675aa7(void)

{
  int iVar1;
  DWORD *lpTlsValue;
  BOOL BVar2;
  DWORD DVar3;
  
  iVar1 = __mtinitlocks();
  if (iVar1 != 0) {
    DAT_006eb864 = TlsAlloc();
    if (DAT_006eb864 != 0xffffffff) {
      lpTlsValue = _calloc(1,0x88);
      if (lpTlsValue != (DWORD *)0x0) {
        BVar2 = TlsSetValue(DAT_006eb864,lpTlsValue);
        if (BVar2 != 0) {
          lpTlsValue[0x15] = (DWORD)&DAT_006eb7b8;
          lpTlsValue[5] = 1;
          DVar3 = GetCurrentThreadId();
          lpTlsValue[1] = 0xffffffff;
          *lpTlsValue = DVar3;
          return 1;
        }
      }
      FUN_0067589a();
      return 0;
    }
  }
  FUN_0067589a();
  return 0;
}


// ==== 0x675b16 ___heap_select

/* Library Function - Single Match
    ___heap_select
   
   Library: Visual Studio 2003 Release */

undefined4 ___heap_select(void)

{
  if ((DAT_00717a88 == 2) && (4 < DAT_00717a94)) {
    return 1;
  }
  return 3;
}


// ==== 0x675b30 __heap_init

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cdecl __heap_init(void)

{
  int iVar1;
  int in_stack_00000004;
  
  DAT_0079321c = HeapCreate((uint)(in_stack_00000004 == 0),0x1000,0);
  if (DAT_0079321c == (HANDLE)0x0) {
    return 0;
  }
  DAT_00793220 = ___heap_select();
  if ((DAT_00793220 == 3) && (iVar1 = ___sbh_heap_init(0x3f8), iVar1 == 0)) {
    HeapDestroy(DAT_0079321c);
    return 0;
  }
  return 1;
}


// ==== 0x675b84 __SEH_prolog

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __SEH_prolog(undefined4 param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  undefined4 auStack_18 [4];
  undefined1 local_8 [8];
  
  param_2 = -param_2;
  *(undefined4 *)((int)auStack_18 + param_2 + 0xc) = unaff_EBX;
  *(undefined4 *)((int)auStack_18 + param_2 + 8) = unaff_ESI;
  *(undefined4 *)((int)auStack_18 + param_2 + 4) = unaff_EDI;
  *(undefined4 *)((int)auStack_18 + param_2) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}


// ==== 0x675bbf __SEH_epilog

/* WARNING: This is an inlined function */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __SEH_epilog(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}


// ==== 0x675bd0 _isctype

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

uint __thiscall _isctype(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  LPCSTR _LpSrcStr;
  BOOL BVar1;
  uint local_8;
  
  if (param_3 + 1U < 0x101) {
    param_3._2_2_ = *(ushort *)(*(int *)(param_2 + 0x48) + param_3 * 2);
  }
  else {
    if ((*(byte *)(*(int *)(param_2 + 0x48) + 1 + (param_3 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)param_1 >> 8),(char)param_3) & 0xffff00ff;
      _LpSrcStr = (LPCSTR)0x1;
    }
    else {
      local_8 = CONCAT31(CONCAT21((short)((uint)param_1 >> 0x10),(char)param_3),
                         (char)((uint)param_3 >> 8)) & 0xff00ffff;
      _LpSrcStr = (LPCSTR)0x2;
    }
    BVar1 = ___crtGetStringTypeA
                      ((_locale_t)0x1,(DWORD)&local_8,_LpSrcStr,(int)&param_3 + 2,
                       *(LPWORD *)(param_2 + 4),*(int *)(param_2 + 0x14),1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_3._2_2_ & param_4;
}


// ==== 0x675c50 __allmul

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}


// ==== 0x675c84 _realloc

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  LPVOID pvVar4;
  int local_24;
  void *local_20;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
  }
  else {
    if (_NewSize == 0) {
      _free(_Memory);
    }
    else if (DAT_00793220 == 3) {
      do {
        local_20 = (void *)0x0;
        if (_NewSize < 0xffffffe1) {
          __lock(4);
          local_24 = ___sbh_find_block(_Memory);
          if (local_24 != 0) {
            if (_NewSize <= DAT_0079320c) {
              iVar2 = ___sbh_resize_block(local_24,_Memory,_NewSize);
              if (iVar2 == 0) {
                local_20 = (void *)___sbh_alloc_block(_NewSize);
                if (local_20 != (void *)0x0) {
                  uVar3 = *(int *)((int)_Memory + -4) - 1;
                  if (_NewSize <= uVar3) {
                    uVar3 = _NewSize;
                  }
                  _memcpy(local_20,_Memory,uVar3);
                  local_24 = ___sbh_find_block(_Memory);
                  ___sbh_free_block(local_24,_Memory);
                }
              }
              else {
                local_20 = _Memory;
              }
            }
            if (local_20 == (void *)0x0) {
              if (_NewSize == 0) {
                _NewSize = 1;
              }
              _NewSize = _NewSize + 0xf & 0xfffffff0;
              local_20 = HeapAlloc(DAT_0079321c,0,_NewSize);
              if (local_20 != (LPVOID)0x0) {
                uVar3 = *(int *)((int)_Memory + -4) - 1;
                if (_NewSize <= uVar3) {
                  uVar3 = _NewSize;
                }
                _memcpy(local_20,_Memory,uVar3);
                ___sbh_free_block(local_24,_Memory);
              }
            }
          }
          FUN_00675dec();
          if (local_24 == 0) {
            if (_NewSize == 0) {
              _NewSize = 1;
            }
            _NewSize = _NewSize + 0xf & 0xfffffff0;
            local_20 = HeapReAlloc(DAT_0079321c,0,_Memory,_NewSize);
          }
        }
        if (local_20 != (void *)0x0) {
          return local_20;
        }
        if (DAT_00717d74 == 0) {
          return (void *)0x0;
        }
        iVar2 = __callnewh(_NewSize);
      } while (iVar2 != 0);
    }
    else {
      do {
        pvVar4 = (LPVOID)0x0;
        if (_NewSize < 0xffffffe1) {
          if (_NewSize == 0) {
            _NewSize = 1;
          }
          pvVar4 = HeapReAlloc(DAT_0079321c,0,_Memory,_NewSize);
        }
        if (pvVar4 != (LPVOID)0x0) {
          return pvVar4;
        }
        if (DAT_00717d74 == 0) {
          return (void *)0x0;
        }
        iVar2 = __callnewh(_NewSize);
      } while (iVar2 != 0);
    }
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


// ==== 0x675de4 FUN_00675de4

void FUN_00675de4(void)

{
  __unlock(4);
  return;
}


// ==== 0x675dec FUN_00675dec

void FUN_00675dec(void)

{
  __unlock(4);
  return;
}


// ==== 0x675e31 __msize

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 2003 Release */

size_t __cdecl __msize(void *_Memory)

{
  int iVar1;
  SIZE_T SVar2;
  size_t local_24;
  
  if (DAT_00793220 == 3) {
    __lock(4);
    iVar1 = ___sbh_find_block(_Memory);
    if (iVar1 != 0) {
      local_24 = *(int *)((int)_Memory + -4) - 9;
    }
    FUN_00675e9e();
    if (iVar1 != 0) {
      return local_24;
    }
  }
  SVar2 = HeapSize(DAT_0079321c,0,_Memory);
  return SVar2;
}


// ==== 0x675e9b FUN_00675e9b

void FUN_00675e9b(void)

{
  __unlock(4);
  return;
}


// ==== 0x675e9e FUN_00675e9e

void FUN_00675e9e(void)

{
  __unlock(4);
  return;
}


// ==== 0x675ea7 __flsbuf

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl __flsbuf(int _Ch,FILE *_File)

{
  uint uVar1;
  uint _FileHandle;
  char *_Buf;
  char *pcVar2;
  FILE *_File_00;
  int iVar3;
  undefined *puVar4;
  FILE *_MaxCharCount;
  
  _File_00 = _File;
  uVar1 = _File->_flag;
  _FileHandle = _File->_file;
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_00675fb3:
    _File->_flag = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      _File->_cnt = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_00675fb3;
      _File->_ptr = _File->_base;
      _File->_flag = uVar1 & 0xfffffffe;
    }
    uVar1 = _File->_flag;
    _File->_cnt = 0;
    _File = (FILE *)0x0;
    _File_00->_flag = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((_File_00 != (FILE *)&DAT_006eb1e0 && (_File_00 != (FILE *)&DAT_006eb200)) ||
        (iVar3 = __isatty(_FileHandle), iVar3 == 0)))) {
      __getbuf(_File_00);
    }
    if ((_File_00->_flag & 0x108) == 0) {
      _MaxCharCount = (FILE *)0x1;
      _File = (FILE *)__write(_FileHandle,&_Ch,1);
    }
    else {
      _Buf = _File_00->_base;
      pcVar2 = _File_00->_ptr;
      _File_00->_ptr = _Buf + 1;
      _MaxCharCount = (FILE *)(pcVar2 + -(int)_Buf);
      _File_00->_cnt = _File_00->_bufsiz + -1;
      if ((int)_MaxCharCount < 1) {
        if (_FileHandle == 0xffffffff) {
          puVar4 = &DAT_006eb840;
        }
        else {
          puVar4 = (undefined *)
                   ((&DAT_00793240)[(int)_FileHandle >> 5] + (_FileHandle & 0x1f) * 0x24);
        }
        if ((puVar4[4] & 0x20) != 0) {
          __lseek(_FileHandle,0,2);
        }
      }
      else {
        _File = (FILE *)__write(_FileHandle,_Buf,(uint)_MaxCharCount);
      }
      *_File_00->_base = (char)_Ch;
    }
    if (_File == _MaxCharCount) {
      return _Ch & 0xff;
    }
    _File_00->_flag = _File_00->_flag | 0x20;
  }
  return -1;
}


// ==== 0x675fc0 write_char

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __cdecl write_char(void)

{
  int *piVar1;
  byte in_AL;
  uint uVar2;
  FILE *in_ECX;
  int *unaff_ESI;
  
  if (((in_ECX->_flag & 0x40) == 0) || (in_ECX->_base != (char *)0x0)) {
    piVar1 = &in_ECX->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = __flsbuf((int)(char)in_AL,in_ECX);
    }
    else {
      *in_ECX->_ptr = in_AL;
      in_ECX->_ptr = in_ECX->_ptr + 1;
      uVar2 = (uint)in_AL;
    }
    if (uVar2 == 0xffffffff) {
      *unaff_ESI = -1;
      return;
    }
  }
  *unaff_ESI = *unaff_ESI + 1;
  return;
}


// ==== 0x675ff3 write_multi_char

/* Library Function - Single Match
    _write_multi_char
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __cdecl write_multi_char(undefined4 param_1,int param_2)

{
  int *in_EAX;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    write_char();
  } while (*in_EAX != -1);
  return;
}


// ==== 0x676017 write_string

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 2003 Release */

void __cdecl write_string(int param_1)

{
  int *in_EAX;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EDI + 0xc) & 0x40) == 0) || (*(int *)(unaff_EDI + 8) != 0)) {
    do {
      if (param_1 < 1) {
        return;
      }
      param_1 = param_1 + -1;
      write_char();
    } while (*in_EAX != -1);
  }
  else {
    *in_EAX = *in_EAX + param_1;
  }
  return;
}


// ==== 0x67604e FUN_0067604e

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int FUN_0067604e(undefined4 param_1,byte *param_2,wchar_t *param_3)

{
  byte bVar1;
  short *psVar2;
  byte *pbVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int extraout_ECX;
  byte bVar8;
  size_t sVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  bool bVar12;
  longlong lVar13;
  uint unaff_retaddr;
  wchar_t local_258 [255];
  undefined2 local_59;
  undefined4 local_50;
  undefined4 local_4c;
  size_t local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  wchar_t *local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20;
  char local_1f;
  int local_1c;
  size_t local_18;
  wchar_t *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  local_18 = 0;
  local_1c = 0;
  local_30 = (wchar_t *)0x0;
  bVar8 = *param_2;
  local_3c = 0;
  pbVar3 = param_2;
  pwVar11 = param_3;
  do {
    if ((bVar8 == 0) || (param_2 = pbVar3 + 1, local_1c < 0)) {
      return local_1c;
    }
    if (((char)bVar8 < ' ') || ('x' < (char)bVar8)) {
      uVar5 = 0;
    }
    else {
      uVar5 = (int)(char)(&DAT_006ac5a8)[(char)bVar8] & 0xf;
    }
    iVar7 = uVar5 * 8 + local_3c;
    local_3c = (int)(char)(&DAT_006ac5c8)[iVar7] >> 4;
    param_3 = pwVar11;
    switch((int)(char)(&DAT_006ac5c8)[iVar7] >> 4) {
    case 0:
switchD_006760c8_caseD_0:
      local_2c = 0;
      if ((PTR_DAT_006ec130[(uint)bVar8 * 2 + 1] & 0x80) != 0) {
        write_char();
        param_2 = pbVar3 + 2;
      }
      write_char();
      break;
    case 1:
      local_10 = -1;
      local_40 = 0;
      local_38 = 0;
      local_28 = 0;
      local_24 = 0;
      local_c = 0;
      local_2c = 0;
      break;
    case 2:
      if (bVar8 == 0x20) {
        local_c = local_c | 2;
      }
      else if (bVar8 == 0x23) {
        local_c = local_c | 0x80;
      }
      else if (bVar8 == 0x2b) {
        local_c = local_c | 1;
      }
      else if (bVar8 == 0x2d) {
        local_c = local_c | 4;
      }
      else if (bVar8 == 0x30) {
        local_c = local_c | 8;
      }
      break;
    case 3:
      if (bVar8 == 0x2a) {
        local_28 = *(int *)pwVar11;
        param_3 = pwVar11 + 2;
        if (local_28 < 0) {
          local_c = local_c | 4;
          local_28 = -local_28;
        }
      }
      else {
        local_28 = (char)bVar8 + -0x30 + local_28 * 10;
      }
      break;
    case 4:
      local_10 = 0;
      break;
    case 5:
      if (bVar8 == 0x2a) {
        local_10 = *(int *)pwVar11;
        param_3 = pwVar11 + 2;
        if (local_10 < 0) {
          local_10 = -1;
        }
      }
      else {
        local_10 = (char)bVar8 + -0x30 + local_10 * 10;
      }
      break;
    case 6:
      if (bVar8 == 0x49) {
        bVar1 = *param_2;
        if ((bVar1 == 0x36) && (pbVar3[2] == 0x34)) {
          param_2 = pbVar3 + 3;
          local_c = local_c | 0x8000;
        }
        else if ((bVar1 == 0x33) && (pbVar3[2] == 0x32)) {
          param_2 = pbVar3 + 3;
          local_c = local_c & 0xffff7fff;
        }
        else if (((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
                 ((bVar1 != 0x75 && (bVar1 != 0x78)))) && (bVar1 != 0x58)) {
          local_3c = 0;
          goto switchD_006760c8_caseD_0;
        }
      }
      else if (bVar8 == 0x68) {
        local_c = local_c | 0x20;
      }
      else if (bVar8 == 0x6c) {
        local_c = local_c | 0x10;
      }
      else if (bVar8 == 0x77) {
        local_c = local_c | 0x800;
      }
      break;
    case 7:
      if ((char)bVar8 < 'h') {
        if ((char)bVar8 < 'e') {
          if ((char)bVar8 < 'Y') {
            if (bVar8 != 0x58) {
              if (bVar8 == 0x43) {
                if ((local_c & 0x830) == 0) {
                  local_c = local_c | 0x800;
                }
                goto LAB_0067634a;
              }
              if ((bVar8 != 0x45) && (bVar8 != 0x47)) {
                if (bVar8 == 0x53) {
                  if ((local_c & 0x830) == 0) {
                    local_c = local_c | 0x800;
                  }
                  goto LAB_006762d0;
                }
                goto LAB_006766a1;
              }
              local_40 = 1;
              bVar8 = bVar8 + 0x20;
              goto LAB_0067631b;
            }
LAB_00676559:
            local_34 = 7;
LAB_0067655c:
            local_18 = 0x10;
            if ((local_c & 0x80) != 0) {
              local_20 = 0x30;
              local_1f = (char)local_34 + 'Q';
              local_24 = 2;
            }
            goto LAB_00676398;
          }
          if (bVar8 == 0x5a) {
            param_3 = pwVar11 + 2;
            psVar2 = *(short **)pwVar11;
            pwVar11 = (wchar_t *)PTR_DAT_006eb870;
            pwVar4 = (wchar_t *)PTR_DAT_006eb870;
            if ((psVar2 == (short *)0x0) ||
               (local_14 = *(wchar_t **)(psVar2 + 2), pwVar4 = (wchar_t *)PTR_DAT_006eb870,
               local_14 == (wchar_t *)0x0)) goto LAB_006764cd;
            local_18 = (size_t)*psVar2;
            if ((local_c & 0x800) == 0) {
              local_2c = 0;
            }
            else {
              local_18 = (int)local_18 / 2;
              local_2c = 1;
            }
          }
          else if (bVar8 == 99) {
LAB_0067634a:
            if ((local_c & 0x810) == 0) {
              local_258[0]._0_1_ = (char)*pwVar11;
              local_18 = 1;
            }
            else {
              local_18 = _wctomb((char *)local_258,*pwVar11);
              if ((int)local_18 < 0) {
                local_38 = 1;
              }
            }
            param_3 = pwVar11 + 2;
            local_14 = local_258;
          }
          else if (bVar8 == 100) goto LAB_0067638d;
        }
        else {
LAB_0067631b:
          local_c = local_c | 0x40;
          pwVar10 = local_258;
          pwVar4 = local_258;
          if (local_10 < 0) {
            local_10 = 6;
          }
          else if (local_10 == 0) {
            if (bVar8 == 0x67) {
              local_10 = 1;
            }
          }
          else {
            if (0x200 < local_10) {
              local_10 = 0x200;
            }
            if ((0xa3 < local_10) &&
               (local_14 = local_258, local_30 = _malloc(local_10 + 0x15d), pwVar10 = local_30,
               pwVar4 = local_30, local_30 == (wchar_t *)0x0)) {
              local_10 = 0xa3;
              pwVar10 = local_258;
              pwVar4 = local_14;
            }
          }
          local_14 = pwVar4;
          local_50 = *(undefined4 *)pwVar11;
          param_3 = pwVar11 + 4;
          local_4c = *(undefined4 *)(pwVar11 + 2);
          (*(code *)PTR_FUN_006ebcb0)(&local_50,pwVar10,(int)(char)bVar8,local_10,local_40);
          uVar5 = local_c & 0x80;
          if ((uVar5 != 0) && (local_10 == 0)) {
            (*(code *)PTR_FUN_006ebcbc)(pwVar10);
          }
          if ((bVar8 == 0x67) && (uVar5 == 0)) {
            (*(code *)PTR_FUN_006ebcb4)(pwVar10);
          }
          pwVar11 = pwVar10;
          pwVar4 = local_14;
          if ((char)*pwVar10 == '-') {
            local_c = local_c | 0x100;
            pwVar11 = (wchar_t *)((int)pwVar10 + 1);
            pwVar4 = (wchar_t *)((int)pwVar10 + 1);
          }
LAB_006764cd:
          local_14 = pwVar4;
          local_18 = _strlen((char *)pwVar11);
        }
LAB_006766a1:
        uVar5 = local_c;
        if (local_38 == 0) {
          if ((local_c & 0x40) != 0) {
            if ((local_c & 0x100) == 0) {
              if ((local_c & 1) == 0) {
                if ((local_c & 2) == 0) goto LAB_006766d9;
                local_20 = 0x20;
              }
              else {
                local_20 = 0x2b;
              }
            }
            else {
              local_20 = 0x2d;
            }
            local_24 = 1;
          }
LAB_006766d9:
          iVar7 = (local_28 - local_24) - local_18;
          if ((local_c & 0xc) == 0) {
            write_multi_char(0x20,iVar7,param_1);
          }
          write_string(local_24);
          if (((uVar5 & 8) != 0) && ((uVar5 & 4) == 0)) {
            write_multi_char(0x30,iVar7,param_1);
          }
          if ((local_2c == 0) || ((int)local_18 < 1)) {
            write_string(local_18);
          }
          else {
            local_44 = local_18;
            pwVar11 = local_14;
            do {
              local_44 = local_44 - 1;
              iVar6 = _wctomb((char *)((int)&local_59 + 1),*pwVar11);
              pwVar11 = pwVar11 + 1;
              if (iVar6 < 1) break;
              write_string(iVar6);
            } while (local_44 != 0);
          }
          if ((local_c & 4) != 0) {
            write_multi_char(0x20,iVar7,param_1);
          }
        }
      }
      else {
        if (bVar8 == 0x69) {
LAB_0067638d:
          local_c = local_c | 0x40;
LAB_00676391:
          local_18 = 10;
LAB_00676398:
          if ((local_c & 0x8000) == 0) {
            param_3 = pwVar11 + 2;
            if ((local_c & 0x20) == 0) {
              uVar5 = *(uint *)pwVar11;
              if ((local_c & 0x40) == 0) {
                iVar7 = 0;
                goto LAB_006765f1;
              }
            }
            else if ((local_c & 0x40) == 0) {
              uVar5 = (uint)(ushort)*pwVar11;
            }
            else {
              uVar5 = (uint)*pwVar11;
            }
            iVar7 = (int)uVar5 >> 0x1f;
          }
          else {
            uVar5 = *(uint *)pwVar11;
            iVar7 = *(int *)(pwVar11 + 2);
            param_3 = pwVar11 + 4;
          }
LAB_006765f1:
          if ((((local_c & 0x40) != 0) && (iVar7 < 1)) && (iVar7 < 0)) {
            bVar12 = uVar5 != 0;
            uVar5 = -uVar5;
            iVar7 = -(iVar7 + (uint)bVar12);
            local_c = local_c | 0x100;
          }
          if ((local_c & 0x8000) == 0) {
            iVar7 = 0;
          }
          lVar13 = CONCAT44(iVar7,uVar5);
          if (local_10 < 0) {
            local_10 = 1;
          }
          else {
            local_c = local_c & 0xfffffff7;
            if (0x200 < local_10) {
              local_10 = 0x200;
            }
          }
          if (uVar5 == 0 && iVar7 == 0) {
            local_24 = 0;
          }
          pwVar11 = &local_59;
          while( true ) {
            iVar7 = local_10;
            sVar9 = (size_t)lVar13;
            local_10 = local_10 + -1;
            if ((iVar7 < 1) && (lVar13 == 0)) break;
            lVar13 = __aulldvrm(lVar13,local_18,(int)local_18 >> 0x1f);
            iVar7 = extraout_ECX + 0x30;
            local_44 = sVar9;
            if (0x39 < iVar7) {
              iVar7 = iVar7 + local_34;
            }
            *(char *)pwVar11 = (char)iVar7;
            pwVar11 = (wchar_t *)((int)pwVar11 + -1);
          }
          local_18 = (int)&local_59 + -(int)pwVar11;
          local_14 = (wchar_t *)((int)pwVar11 + 1);
          if (((local_c & 0x200) != 0) && ((*(char *)((int)pwVar11 + 1) != '0' || (local_18 == 0))))
          {
            *(char *)pwVar11 = '0';
            local_18 = (int)&local_59 + -(int)pwVar11 + 1;
            local_14 = pwVar11;
          }
          goto LAB_006766a1;
        }
        if (bVar8 != 0x6e) {
          if (bVar8 == 0x6f) {
            local_18 = 8;
            if ((local_c & 0x80) != 0) {
              local_c = local_c | 0x200;
            }
            goto LAB_00676398;
          }
          if (bVar8 == 0x70) {
            local_10 = 8;
            goto LAB_00676559;
          }
          if (bVar8 == 0x73) {
LAB_006762d0:
            iVar7 = local_10;
            if (local_10 == -1) {
              iVar7 = 0x7fffffff;
            }
            param_3 = pwVar11 + 2;
            local_14 = *(wchar_t **)pwVar11;
            if ((local_c & 0x810) == 0) {
              pwVar11 = local_14;
              if (local_14 == (wchar_t *)0x0) {
                pwVar11 = (wchar_t *)PTR_DAT_006eb870;
                local_14 = (wchar_t *)PTR_DAT_006eb870;
              }
              for (; (iVar7 != 0 && (iVar7 = iVar7 + -1, (char)*pwVar11 != '\0'));
                  pwVar11 = (wchar_t *)((int)pwVar11 + 1)) {
              }
              local_18 = (int)pwVar11 - (int)local_14;
            }
            else {
              if (local_14 == (wchar_t *)0x0) {
                local_14 = (wchar_t *)PTR_DAT_006eb874;
              }
              local_2c = 1;
              for (pwVar11 = local_14; (iVar7 != 0 && (iVar7 = iVar7 + -1, *pwVar11 != L'\0'));
                  pwVar11 = pwVar11 + 1) {
              }
              local_18 = (int)pwVar11 - (int)local_14 >> 1;
            }
            goto LAB_006766a1;
          }
          if (bVar8 != 0x75) {
            if (bVar8 != 0x78) goto LAB_006766a1;
            local_34 = 0x27;
            goto LAB_0067655c;
          }
          goto LAB_00676391;
        }
        param_3 = pwVar11 + 2;
        if ((local_c & 0x20) == 0) {
          **(int **)pwVar11 = local_1c;
        }
        else {
          *(undefined2 *)*(int **)pwVar11 = (undefined2)local_1c;
        }
        local_38 = 1;
      }
      if (local_30 != (wchar_t *)0x0) {
        _free(local_30);
        local_30 = (wchar_t *)0x0;
      }
    }
    bVar8 = *param_2;
    pbVar3 = param_2;
    pwVar11 = param_3;
  } while( true );
}


// ==== 0x6767e3 __inc

/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 2003 Release */

uint __fastcall __inc(undefined4 param_1,FILE *param_2)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = &param_2->_cnt;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *param_2->_ptr;
    param_2->_ptr = param_2->_ptr + 1;
    return (uint)bVar2;
  }
  uVar3 = __filbuf(param_2);
  return uVar3;
}


// ==== 0x6767f9 FUN_006767f9

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_006767f9(FILE *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  wchar_t *pwVar8;
  byte *pbVar9;
  char *pcVar10;
  char *pcVar11;
  wchar_t *pwVar12;
  uint uVar13;
  byte *pbVar14;
  bool bVar15;
  longlong lVar16;
  uint unaff_retaddr;
  wchar_t local_1dc [2];
  byte local_1d8;
  undefined1 local_1d7;
  uint local_1d4;
  byte *local_1d0;
  char local_1cc;
  char local_1cb [351];
  uint local_6c;
  wchar_t *local_68;
  undefined4 *local_64;
  undefined8 local_60;
  int local_58;
  char local_53;
  char local_52;
  char local_51;
  char local_50;
  char local_4f;
  char local_4e;
  byte local_4d;
  int local_4c;
  int local_48;
  int local_44;
  byte local_3d;
  int local_3c;
  int local_38;
  int local_34;
  char local_2d;
  uint local_2c;
  int local_28;
  undefined1 *local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006ac638;
  uStack_c = 0x676808;
  local_20 = DAT_006eb720 ^ unaff_retaddr;
  local_24 = (undefined1 *)0x0;
  local_28 = 0;
  local_2c = 0;
  local_2d = '\0';
  local_34 = 0;
  local_38 = 0;
LAB_00676827:
  do {
    lVar16 = local_60;
    if (*param_2 == 0) {
LAB_00677266:
      if (local_28 == 1) {
        local_60 = lVar16;
        _free(local_24);
      }
      if (((local_2c == 0xffffffff) && (local_38 == 0)) && (local_2d == '\0')) {
        local_38 = -1;
      }
      return local_38;
    }
    iVar3 = _isspace((uint)*param_2);
    if (iVar3 == 0) {
      if (*param_2 == 0x25) {
        iVar3 = 0;
        local_3c = 0;
        local_3d = 0;
        local_44 = 0;
        local_48 = 0;
        local_4c = 0;
        local_4d = 0;
        local_4e = '\0';
        local_4f = '\0';
        local_50 = '\0';
        local_51 = '\0';
        local_52 = '\0';
        local_53 = '\x01';
        local_58 = 0;
        pbVar14 = param_2;
        do {
          pbVar9 = pbVar14 + 1;
          uVar7 = (uint)*pbVar9;
          iVar4 = _isdigit(uVar7);
          param_2 = pbVar9;
          if (iVar4 == 0) {
            if (uVar7 < 0x4f) {
              if (uVar7 != 0x4e) {
                if (uVar7 == 0x2a) {
                  local_4f = local_4f + '\x01';
                }
                else if (uVar7 != 0x46) {
                  if (uVar7 == 0x49) {
                    bVar6 = pbVar14[2];
                    if ((bVar6 == 0x36) && (pbVar14[3] == 0x34)) {
                      local_58 = local_58 + 1;
                      local_60 = 0;
                      param_2 = pbVar14 + 3;
                    }
                    else if (((bVar6 != 0x33) || (param_2 = pbVar14 + 3, *param_2 != 0x32)) &&
                            ((((param_2 = pbVar9, bVar6 != 100 && (bVar6 != 0x69)) &&
                              (bVar6 != 0x6f)) && ((bVar6 != 0x78 && (bVar6 != 0x58))))))
                    goto LAB_00676968;
                  }
                  else if (uVar7 == 0x4c) {
                    local_53 = local_53 + '\x01';
                  }
                  else {
LAB_00676968:
                    local_50 = local_50 + '\x01';
                    param_2 = pbVar9;
                  }
                }
              }
            }
            else if (uVar7 == 0x68) {
              local_53 = local_53 + -1;
              local_52 = local_52 + -1;
            }
            else {
              if (uVar7 == 0x6c) {
                local_53 = local_53 + '\x01';
              }
              else if (uVar7 != 0x77) goto LAB_00676968;
              local_52 = local_52 + '\x01';
            }
          }
          else {
            local_48 = local_48 + 1;
            iVar3 = (uVar7 - 0x30) + iVar3 * 10;
          }
          pbVar14 = param_2;
        } while (local_50 == '\0');
        if (local_4f == '\0') {
          local_64 = param_3;
          local_68 = (wchar_t *)*param_3;
          param_3 = param_3 + 1;
        }
        pwVar8 = local_68;
        local_50 = '\0';
        if (local_52 == '\0') {
          if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
            local_52 = '\x01';
          }
          else {
            local_52 = -1;
          }
        }
        uVar13 = *param_2 | 0x20;
        local_6c = uVar13;
        local_4c = iVar3;
        uVar7 = local_2c;
        lVar16 = local_60;
        if (uVar13 != 0x6e) {
          if ((uVar13 == 99) || (uVar13 == 0x7b)) {
            local_34 = local_34 + 1;
            uVar7 = __inc();
            lVar16 = local_60;
          }
          else {
            do {
              local_34 = local_34 + 1;
              uVar7 = __inc();
              iVar3 = _isspace(uVar7);
              lVar16 = local_60;
            } while (iVar3 != 0);
          }
        }
        local_2c = uVar7;
        uVar7 = local_2c;
        if ((local_48 != 0) && (local_4c == 0)) {
LAB_00677236:
          if (uVar7 != 0xffffffff) {
            local_60 = lVar16;
            FID_conflict__ungetc(local_2c,param_1);
            lVar16 = local_60;
          }
          goto LAB_00677266;
        }
        local_60 = lVar16;
        if (uVar13 < 0x70) {
          if (uVar13 == 0x6f) {
LAB_00676fa8:
            if (local_2c == 0x2d) {
              local_4e = '\x01';
            }
            else if (local_2c != 0x2b) goto LAB_00676fd9;
            local_4c = local_4c + -1;
            if ((local_4c == 0) && (local_48 != 0)) {
              local_50 = '\x01';
            }
            else {
              local_34 = local_34 + 1;
              local_2c = __inc();
            }
            goto LAB_00676fd9;
          }
          if (uVar13 != 99) {
            if (uVar13 == 100) goto LAB_00676fa8;
            if (uVar13 < 0x65) {
LAB_00676c5b:
              if (*param_2 != local_2c) goto LAB_00677236;
              local_2d = local_2d + -1;
              if (local_4f == '\0') {
                param_3 = local_64;
              }
              goto LAB_006771da;
            }
            if (0x67 < uVar13) {
              if (uVar13 == 0x69) {
                uVar13 = 100;
                goto LAB_00676a72;
              }
              if (uVar13 != 0x6e) goto LAB_00676c5b;
              iVar3 = local_34;
              if (local_4f != '\0') goto LAB_006771da;
              goto LAB_006771ba;
            }
            pcVar10 = &local_1cc;
            if (local_2c == 0x2d) {
              local_1cc = '-';
              pcVar10 = local_1cb;
LAB_00676aa8:
              local_4c = local_4c + -1;
              local_34 = local_34 + 1;
              local_2c = __inc();
              lVar16 = local_60;
            }
            else if (local_2c == 0x2b) goto LAB_00676aa8;
            local_60 = lVar16;
            if ((local_48 == 0) || (0x15d < local_4c)) {
              local_4c = 0x15d;
            }
            while( true ) {
              uVar7 = local_2c;
              iVar3 = _isdigit(local_2c);
              if ((iVar3 == 0) ||
                 (iVar3 = local_4c + -1, bVar15 = local_4c == 0, local_4c = iVar3, bVar15)) break;
              local_44 = local_44 + 1;
              *pcVar10 = (char)uVar7;
              pcVar10 = pcVar10 + 1;
              local_34 = local_34 + 1;
              local_2c = __inc();
            }
            if ((DAT_006ec184 == (char)uVar7) &&
               (iVar3 = local_4c + -1, bVar15 = local_4c != 0, local_4c = iVar3, bVar15)) {
              local_34 = local_34 + 1;
              uVar7 = __inc();
              *pcVar10 = DAT_006ec184;
              while( true ) {
                pcVar10 = pcVar10 + 1;
                local_2c = uVar7;
                iVar3 = _isdigit(uVar7);
                if ((iVar3 == 0) ||
                   (iVar3 = local_4c + -1, bVar15 = local_4c == 0, local_4c = iVar3, bVar15)) break;
                local_44 = local_44 + 1;
                *pcVar10 = (char)uVar7;
                local_34 = local_34 + 1;
                uVar7 = __inc();
              }
            }
            pcVar11 = pcVar10;
            if ((local_44 != 0) &&
               (((uVar7 == 0x65 || (uVar7 == 0x45)) &&
                (iVar3 = local_4c + -1, bVar15 = local_4c != 0, local_4c = iVar3, bVar15)))) {
              *pcVar10 = 'e';
              pcVar11 = pcVar10 + 1;
              local_34 = local_34 + 1;
              uVar7 = __inc();
              local_2c = uVar7;
              if (uVar7 == 0x2d) {
                *pcVar11 = '-';
                pcVar11 = pcVar10 + 2;
LAB_00676b92:
                bVar15 = local_4c != 0;
                local_4c = local_4c + -1;
                if (bVar15) goto LAB_00676bb1;
                local_4c = 0;
              }
              else if (uVar7 == 0x2b) goto LAB_00676b92;
              while( true ) {
                iVar3 = _isdigit(uVar7);
                if ((iVar3 == 0) ||
                   (iVar3 = local_4c + -1, bVar15 = local_4c == 0, local_4c = iVar3, bVar15)) break;
                local_44 = local_44 + 1;
                *pcVar11 = (char)uVar7;
                pcVar11 = pcVar11 + 1;
LAB_00676bb1:
                local_34 = local_34 + 1;
                uVar7 = __inc();
                local_2c = uVar7;
              }
            }
            local_34 = local_34 + -1;
            lVar16 = local_60;
            if (uVar7 != 0xffffffff) {
              FID_conflict__ungetc(uVar7,param_1);
              lVar16 = local_60;
            }
            if (local_44 != 0) {
              if (local_4f == '\0') {
                local_38 = local_38 + 1;
                local_60 = lVar16;
                *pcVar11 = '\0';
                (*(code *)PTR_FUN_006ebcb8)(local_53 + -1,local_68,&local_1cc);
                lVar16 = local_60;
              }
              goto LAB_006771da;
            }
            goto LAB_00677266;
          }
          if (local_48 == 0) {
            local_48 = 1;
            local_4c = local_4c + 1;
          }
LAB_00676c22:
          if ('\0' < local_52) {
            local_51 = '\x01';
          }
LAB_00676dad:
          local_34 = local_34 + -1;
          pwVar12 = pwVar8;
          if (local_2c != 0xffffffff) {
            FID_conflict__ungetc(local_2c,param_1);
          }
          while( true ) {
            if ((local_48 != 0) &&
               (iVar3 = local_4c + -1, bVar15 = local_4c == 0, local_4c = iVar3, lVar16 = local_60,
               bVar15)) goto LAB_00676f6b;
            local_34 = local_34 + 1;
            local_2c = __inc();
            if ((local_2c == 0xffffffff) ||
               ((bVar6 = (byte)local_2c, uVar13 != 99 &&
                (((uVar13 != 0x73 ||
                  (((8 < (int)local_2c && ((int)local_2c < 0xe)) || (local_2c == 0x20)))) &&
                 ((uVar13 != 0x7b ||
                  (uVar13 = local_6c,
                  ((int)(char)(local_24[(int)local_2c >> 3] ^ local_4d) & 1 << (bVar6 & 7)) == 0))))
                )))) break;
            if (local_4f == '\0') {
              if (local_51 == '\0') {
                *(byte *)pwVar8 = bVar6;
                pwVar8 = (wchar_t *)((int)pwVar8 + 1);
                local_68 = pwVar8;
              }
              else {
                local_1d8 = bVar6;
                if ((PTR_DAT_006ec130[(local_2c & 0xff) * 2 + 1] & 0x80) != 0) {
                  local_34 = local_34 + 1;
                  local_1d7 = __inc();
                }
                _mbtowc(local_1dc,(char *)&local_1d8,DAT_006ec180);
                *pwVar8 = local_1dc[0];
                pwVar8 = pwVar8 + 1;
                local_68 = pwVar8;
              }
            }
            else {
              pwVar12 = (wchar_t *)((int)pwVar12 + 1);
            }
          }
          local_34 = local_34 + -1;
          lVar16 = local_60;
          if (local_2c != 0xffffffff) {
            FID_conflict__ungetc(local_2c,param_1);
            lVar16 = local_60;
          }
LAB_00676f6b:
          if (pwVar12 == pwVar8) goto LAB_00677266;
          if ((local_4f == '\0') && (local_38 = local_38 + 1, local_6c != 99)) {
            if (local_51 == '\0') {
              *(byte *)local_68 = 0;
            }
            else {
              *local_68 = L'\0';
            }
          }
        }
        else {
          if (uVar13 == 0x70) {
            local_53 = '\x01';
            goto LAB_00676fa8;
          }
          if (uVar13 == 0x73) goto LAB_00676c22;
          if (uVar13 == 0x75) goto LAB_00676fa8;
          if (uVar13 != 0x78) {
            if (uVar13 != 0x7b) goto LAB_00676c5b;
            if ('\0' < local_52) {
              local_51 = '\x01';
            }
            pbVar9 = param_2 + 1;
            pbVar14 = pbVar9;
            if (*pbVar9 == 0x5e) {
              pbVar14 = param_2 + 2;
              local_4d = 0xff;
            }
            if (local_24 == (undefined1 *)0x0) {
              local_1c = &stack0xfffffe18;
              local_24 = &stack0xfffffe18;
              local_8 = (undefined *)0xffffffff;
            }
            puVar2 = local_24;
            local_1d0 = pbVar14;
            _memset(local_24,0,0x20);
            bVar6 = local_3d;
            if ((local_6c == 0x7b) && (*pbVar14 == 0x5d)) {
              puVar2[0xb] = 0x20;
              pbVar14 = pbVar14 + 1;
              bVar6 = 0x5d;
            }
            while (bVar5 = *pbVar14, bVar5 != 0x5d) {
              if (((bVar5 == 0x2d) && (bVar6 != 0)) && (bVar1 = pbVar14[1], bVar1 != 0x5d)) {
                bVar5 = bVar1;
                if (bVar6 < bVar1) {
                  bVar5 = bVar6;
                  bVar6 = bVar1;
                }
                if (bVar5 <= bVar6) {
                  uVar7 = (uint)bVar5;
                  local_1d4 = (uint)(byte)((bVar6 - bVar5) + 1);
                  do {
                    puVar2[uVar7 >> 3] = puVar2[uVar7 >> 3] | '\x01' << ((byte)uVar7 & 7);
                    uVar7 = uVar7 + 1;
                    local_1d4 = local_1d4 - 1;
                  } while (local_1d4 != 0);
                }
                pbVar14 = pbVar14 + 2;
                bVar6 = 0;
              }
              else {
                local_3d = bVar5;
                puVar2[bVar5 >> 3] = puVar2[bVar5 >> 3] | '\x01' << (bVar5 & 7);
                pbVar14 = pbVar14 + 1;
                bVar6 = local_3d;
              }
            }
            pwVar8 = local_68;
            uVar13 = local_6c;
            param_2 = pbVar9;
            if (local_6c == 0x7b) {
              param_2 = pbVar14;
            }
            goto LAB_00676dad;
          }
LAB_00676a72:
          if (local_2c == 0x2d) {
            local_4e = '\x01';
LAB_00676ea6:
            local_4c = local_4c + -1;
            if ((local_4c == 0) && (local_48 != 0)) {
              local_50 = '\x01';
            }
            else {
              local_34 = local_34 + 1;
              local_2c = __inc();
              lVar16 = local_60;
            }
          }
          else if (local_2c == 0x2b) goto LAB_00676ea6;
          local_60 = lVar16;
          if (local_2c == 0x30) {
            local_34 = local_34 + 1;
            local_2c = __inc();
            if (((char)local_2c == 'x') || ((char)local_2c == 'X')) {
              local_34 = local_34 + 1;
              local_2c = __inc();
              if ((local_48 != 0) && (local_4c = local_4c + -2, local_4c < 1)) {
                local_50 = local_50 + '\x01';
              }
              uVar13 = 0x78;
            }
            else {
              local_44 = 1;
              if (uVar13 == 0x78) {
                local_34 = local_34 + -1;
                if (local_2c != 0xffffffff) {
                  FID_conflict__ungetc(local_2c,param_1);
                }
                local_2c = 0x30;
              }
              else {
                if ((local_48 != 0) && (local_4c = local_4c + -1, local_4c == 0)) {
                  local_50 = local_50 + '\x01';
                }
                uVar13 = 0x6f;
              }
            }
          }
LAB_00676fd9:
          uVar7 = local_2c;
          lVar16 = local_60;
          if (local_58 == 0) {
            while (local_50 == '\0') {
              local_60 = lVar16;
              if ((uVar13 == 0x78) || (uVar13 == 0x70)) {
                iVar3 = _isxdigit(uVar7);
                if (iVar3 != 0) {
                  local_3c = local_3c << 4;
                  iVar3 = _isdigit(uVar7);
                  if (iVar3 == 0) {
                    uVar7 = (uVar7 & 0xffffffdf) - 7;
                  }
                  goto LAB_0067713f;
                }
LAB_0067713c:
                local_50 = local_50 + '\x01';
              }
              else {
                iVar3 = _isdigit(uVar7);
                if (iVar3 == 0) goto LAB_0067713c;
                if (uVar13 == 0x6f) {
                  if (0x37 < (int)uVar7) goto LAB_0067713c;
                  local_3c = local_3c << 3;
                }
                else {
                  local_3c = local_3c * 10;
                }
              }
LAB_0067713f:
              lVar16 = local_60;
              if (local_50 == '\0') {
                local_44 = local_44 + 1;
                local_3c = local_3c + -0x30 + uVar7;
                if ((local_48 == 0) || (local_4c = local_4c + -1, local_4c != 0)) {
                  local_34 = local_34 + 1;
                  uVar7 = __inc();
                  lVar16 = local_60;
                }
                else {
                  local_50 = '\x01';
                }
              }
              else {
                local_34 = local_34 + -1;
                if (uVar7 != 0xffffffff) {
                  FID_conflict__ungetc(uVar7,param_1);
                  lVar16 = local_60;
                }
              }
            }
            local_2c = uVar7;
            if (local_4e != '\0') {
              local_3c = -local_3c;
            }
          }
          else {
            while (local_50 == '\0') {
              local_60 = lVar16;
              if ((uVar13 == 0x78) || (uVar13 == 0x70)) {
                iVar3 = _isxdigit(uVar7);
                if (iVar3 != 0) {
                  local_60 = local_60 << 4;
                  iVar3 = _isdigit(uVar7);
                  if (iVar3 == 0) {
                    uVar7 = (uVar7 & 0xffffffdf) - 7;
                  }
                  goto LAB_0067706c;
                }
LAB_00677069:
                local_50 = local_50 + '\x01';
              }
              else {
                iVar3 = _isdigit(uVar7);
                if (iVar3 == 0) goto LAB_00677069;
                if (uVar13 == 0x6f) {
                  if (0x37 < (int)uVar7) goto LAB_00677069;
                  local_60 = local_60 << 3;
                }
                else {
                  lVar16 = __allmul(local_60,10,0);
                  local_60 = lVar16;
                }
              }
LAB_0067706c:
              if (local_50 == '\0') {
                local_44 = local_44 + 1;
                if ((local_48 == 0) || (local_4c = local_4c + -1, local_4c != 0)) {
                  local_34 = local_34 + 1;
                  local_60 = local_60 + (int)(uVar7 - 0x30);
                  uVar7 = __inc();
                  lVar16 = local_60;
                }
                else {
                  local_50 = '\x01';
                  lVar16 = local_60 + (int)(uVar7 - 0x30);
                }
              }
              else {
                local_34 = local_34 + -1;
                lVar16 = local_60;
                if (uVar7 != 0xffffffff) {
                  FID_conflict__ungetc(uVar7,param_1);
                  lVar16 = local_60;
                }
              }
            }
            local_60._4_4_ = (int)((ulonglong)lVar16 >> 0x20);
            local_60._0_4_ = (int)lVar16;
            local_2c = uVar7;
            if (local_4e != '\0') {
              lVar16 = CONCAT44(-(local_60._4_4_ + (uint)((int)local_60 != 0)),-(int)local_60);
            }
          }
          if (uVar13 == 0x46) {
            local_44 = 0;
          }
          if (local_44 == 0) goto LAB_00677266;
          if (local_4f == '\0') {
            local_38 = local_38 + 1;
            iVar3 = local_3c;
            pwVar8 = local_68;
LAB_006771ba:
            if (local_58 == 0) {
              if (local_53 == '\0') {
                *pwVar8 = (wchar_t)iVar3;
              }
              else {
                *(int *)pwVar8 = iVar3;
              }
            }
            else {
              *(longlong *)pwVar8 = lVar16;
            }
          }
        }
LAB_006771da:
        local_2d = local_2d + '\x01';
        pbVar14 = param_2 + 1;
        local_60 = lVar16;
      }
      else {
        local_34 = local_34 + 1;
        uVar7 = __inc();
        local_2c = uVar7;
        lVar16 = local_60;
        if (*param_2 != uVar7) goto LAB_00677236;
        pbVar14 = param_2 + 1;
        if ((PTR_DAT_006ec130[(uVar7 & 0xff) * 2 + 1] & 0x80) != 0) {
          local_34 = local_34 + 1;
          uVar13 = __inc();
          if (param_2[1] != uVar13) {
            lVar16 = local_60;
            if (uVar13 != 0xffffffff) {
              FID_conflict__ungetc(uVar13,param_1);
              lVar16 = local_60;
            }
            goto LAB_00677236;
          }
          local_34 = local_34 + -1;
          pbVar14 = param_2 + 2;
        }
      }
      param_2 = pbVar14;
      if ((local_2c == 0xffffffff) &&
         ((lVar16 = local_60, *param_2 != 0x25 || (param_2[1] != 0x6e)))) goto LAB_00677266;
      goto LAB_00676827;
    }
    local_34 = local_34 + -1;
    do {
      local_34 = local_34 + 1;
      iVar3 = __inc();
      iVar4 = _isspace(iVar3);
    } while (iVar4 != 0);
    if (iVar3 != -1) {
      FID_conflict__ungetc(iVar3,param_1);
    }
    do {
      param_2 = param_2 + 1;
      iVar3 = _isspace((uint)*param_2);
    } while (iVar3 != 0);
  } while( true );
}


// ==== 0x676cce FUN_00676cce

undefined4 FUN_00676cce(void)

{
  return 1;
}


// ==== 0x676cd2 FUN_00676cd2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_00676cd2(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  void *pvVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  byte bVar16;
  uint uVar17;
  undefined1 *puVar18;
  byte *pbVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  int unaff_EBP;
  byte *pbVar23;
  char *pcVar24;
  char *pcVar25;
  byte *pbVar26;
  undefined8 uVar27;
  
  puVar21 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar21 + -4) = 0x676cda;
  FUN_0068041c();
  *(undefined4 *)(puVar21 + -4) = 0x20;
  *(undefined4 *)(puVar21 + -8) = 0x676ce1;
  pvVar12 = _malloc(*(size_t *)(puVar21 + -4));
  *(void **)(unaff_EBP + -0x20) = pvVar12;
  if (pvVar12 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00677266:
    if (*(int *)(unaff_EBP + -0x24) == 1) {
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(puVar21 + -8) = 0x677274;
      _free(*(void **)(puVar21 + -4));
    }
    iVar14 = *(int *)(unaff_EBP + -0x34);
    if (((*(int *)(unaff_EBP + -0x28) == -1) && (iVar14 == 0)) &&
       (*(char *)(unaff_EBP + -0x29) == '\0')) {
      iVar14 = -1;
    }
    *(undefined4 *)(unaff_EBP + -0x1e8) = 0x67729b;
    *(undefined4 *)(unaff_EBP + -0x1ec) = 0x6772a0;
    return iVar14;
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar26 = *(byte **)(unaff_EBP + -0x1cc);
  puVar18 = *(undefined1 **)(unaff_EBP + -0x20);
  puVar22 = puVar21;
LAB_00676d06:
  *(undefined4 *)(puVar22 + -4) = 0x20;
  *(undefined4 *)(puVar22 + -8) = 0;
  *(undefined1 **)(puVar22 + -0xc) = puVar18;
  *(undefined4 *)(puVar22 + -0x10) = 0x676d10;
  _memset(*(void **)(puVar22 + -0xc),*(int *)(puVar22 + -8),*(size_t *)(puVar22 + -4));
  if (*(int *)(unaff_EBP + -0x68) != 0x7b) goto LAB_00676d8d;
  if (*pbVar26 != 0x5d) goto LAB_00676d8d;
  bVar16 = 0x5d;
  pbVar26 = pbVar26 + 1;
  puVar18[0xb] = 0x20;
  while (bVar15 = *pbVar26, bVar15 != 0x5d) {
    if (((bVar15 == 0x2d) && (bVar16 != 0)) && (bVar4 = pbVar26[1], bVar4 != 0x5d)) {
      pbVar26 = pbVar26 + 2;
      bVar15 = bVar4;
      if (bVar16 < bVar4) {
        bVar15 = bVar16;
        bVar16 = bVar4;
      }
      if (bVar15 <= bVar16) {
        uVar17 = (uint)bVar15;
        *(uint *)(unaff_EBP + -0x1d0) = (uint)(byte)((bVar16 - bVar15) + 1);
        do {
          puVar18[uVar17 >> 3] = puVar18[uVar17 >> 3] | '\x01' << ((byte)uVar17 & 7);
          uVar17 = uVar17 + 1;
          piVar1 = (int *)(unaff_EBP + -0x1d0);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      bVar16 = 0;
    }
    else {
      *(byte *)(unaff_EBP + -0x39) = bVar15;
      puVar18[bVar15 >> 3] = puVar18[bVar15 >> 3] | '\x01' << (bVar15 & 7);
      pbVar26 = pbVar26 + 1;
LAB_00676d8d:
      bVar16 = *(byte *)(unaff_EBP + -0x39);
    }
  }
  pbVar19 = *(byte **)(unaff_EBP + -100);
  if (*(int *)(unaff_EBP + -0x68) == 0x7b) {
    *(byte **)(unaff_EBP + 0xc) = pbVar26;
  }
  uVar17 = *(uint *)(unaff_EBP + -0x68);
  puVar21 = puVar22;
LAB_00676dad:
  *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
  pbVar26 = pbVar19;
  if (*(int *)(unaff_EBP + -0x28) != -1) {
    *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(puVar21 + -0xc) = 0x676dc3;
    FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
  }
  do {
    if ((*(int *)(unaff_EBP + -0x44) != 0) &&
       (iVar14 = *(int *)(unaff_EBP + -0x48),
       *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar14 == 0))
    goto LAB_00676f6b;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    *(undefined4 *)(puVar21 + -4) = 0x676de4;
    uVar13 = __inc();
    *(uint *)(unaff_EBP + -0x28) = uVar13;
    if (uVar13 == 0xffffffff) break;
    bVar16 = (byte)uVar13;
    if ((uVar17 != 99) &&
       (((uVar17 != 0x73 || ((8 < (int)uVar13 && ((int)uVar13 < 0xe)))) || (uVar13 == 0x20)))) {
      if ((uVar17 != 0x7b) ||
         (((int)(char)(*(byte *)(((int)uVar13 >> 3) + *(int *)(unaff_EBP + -0x20)) ^
                      *(byte *)(unaff_EBP + -0x49)) & 1 << (bVar16 & 7)) == 0)) break;
      uVar17 = *(uint *)(unaff_EBP + -0x68);
    }
    if (*(char *)(unaff_EBP + -0x4b) == '\0') {
      if (*(char *)(unaff_EBP + -0x4d) == '\0') {
        *pbVar19 = bVar16;
        pbVar19 = pbVar19 + 1;
      }
      else {
        *(byte *)(unaff_EBP + -0x1d4) = bVar16;
        if ((PTR_DAT_006ec130[(uVar13 & 0xff) * 2 + 1] & 0x80) != 0) {
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676e6e;
          uVar8 = __inc();
          *(undefined1 *)(unaff_EBP + -0x1d3) = uVar8;
        }
        *(undefined4 *)(puVar21 + -4) = DAT_006ec180;
        *(int *)(puVar21 + -8) = unaff_EBP + -0x1d4;
        *(int *)(puVar21 + -0xc) = unaff_EBP + -0x1d8;
        *(undefined4 *)(puVar21 + -0x10) = 0x676e8d;
        _mbtowc(*(wchar_t **)(puVar21 + -0xc),*(char **)(puVar21 + -8),*(size_t *)(puVar21 + -4));
        *(undefined2 *)pbVar19 = *(undefined2 *)(unaff_EBP + -0x1d8);
        pbVar19 = pbVar19 + 2;
      }
      *(byte **)(unaff_EBP + -100) = pbVar19;
    }
    else {
      pbVar26 = pbVar26 + 1;
    }
  } while( true );
  *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
  if (uVar13 != 0xffffffff) {
    *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
    *(uint *)(puVar21 + -8) = uVar13;
    *(undefined4 *)(puVar21 + -0xc) = 0x676f69;
    FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
  }
LAB_00676f6b:
  if (pbVar26 == pbVar19) goto LAB_00677266;
  if ((*(char *)(unaff_EBP + -0x4b) == '\0') &&
     (*(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1,
     *(int *)(unaff_EBP + -0x68) != 99)) {
    if (*(char *)(unaff_EBP + -0x4d) == '\0') {
      *(undefined1 *)*(undefined2 **)(unaff_EBP + -100) = 0;
    }
    else {
      **(undefined2 **)(unaff_EBP + -100) = 0;
    }
  }
LAB_006771da:
  *(char *)(unaff_EBP + -0x29) = *(char *)(unaff_EBP + -0x29) + '\x01';
  *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
  while( true ) {
    if ((*(int *)(unaff_EBP + -0x28) == -1) &&
       ((**(char **)(unaff_EBP + 0xc) != '%' || ((*(char **)(unaff_EBP + 0xc))[1] != 'n'))))
    goto LAB_00677266;
    while( true ) {
      if (**(byte **)(unaff_EBP + 0xc) == 0) goto LAB_00677266;
      *(uint *)(puVar21 + -4) = (uint)**(byte **)(unaff_EBP + 0xc);
      *(undefined4 *)(puVar21 + -8) = 0x67683d;
      iVar14 = _isspace(*(int *)(puVar21 + -4));
      if (iVar14 == 0) break;
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      do {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676850;
        iVar14 = __inc();
        *(int *)(puVar21 + -4) = iVar14;
        *(undefined4 *)(puVar21 + -8) = 0x676858;
        iVar9 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar9 != 0);
      if (iVar14 != -1) {
        *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
        *(int *)(puVar21 + -8) = iVar14;
        *(undefined4 *)(puVar21 + -0xc) = 0x67686b;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      do {
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
        *(uint *)(puVar21 + -4) = (uint)**(byte **)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar21 + -8) = 0x67687c;
        iVar14 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar14 != 0);
    }
    pbVar26 = *(byte **)(unaff_EBP + 0xc);
    if (*pbVar26 == 0x25) break;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    *(undefined4 *)(puVar21 + -4) = 0x6771ed;
    uVar17 = __inc();
    *(uint *)(unaff_EBP + -0x28) = uVar17;
    bVar16 = *pbVar26;
    *(byte **)(unaff_EBP + 0xc) = pbVar26 + 1;
    if (bVar16 != uVar17) goto LAB_00677236;
    if ((PTR_DAT_006ec130[(uVar17 & 0xff) * 2 + 1] & 0x80) != 0) {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x677218;
      uVar13 = __inc();
      bVar16 = pbVar26[1];
      *(byte **)(unaff_EBP + 0xc) = pbVar26 + 2;
      if (bVar16 != uVar13) {
        if (uVar13 != 0xffffffff) {
          *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
          *(uint *)(puVar21 + -8) = uVar13;
          *(undefined4 *)(puVar21 + -0xc) = 0x677231;
          FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
        }
        goto LAB_00677236;
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
    }
  }
  iVar14 = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined1 *)(unaff_EBP + -0x39) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined1 *)(unaff_EBP + -0x49) = 0;
  *(undefined1 *)(unaff_EBP + -0x4a) = 0;
  *(undefined1 *)(unaff_EBP + -0x4b) = 0;
  *(undefined1 *)(unaff_EBP + -0x4c) = 0;
  *(undefined1 *)(unaff_EBP + -0x4d) = 0;
  *(undefined1 *)(unaff_EBP + -0x4e) = 0;
  *(undefined1 *)(unaff_EBP + -0x4f) = 1;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  do {
    pbVar19 = pbVar26 + 1;
    uVar17 = (uint)*pbVar19;
    *(uint *)(puVar21 + -4) = uVar17;
    *(undefined4 *)(puVar21 + -8) = 0x6768cd;
    iVar9 = _isdigit(*(int *)(puVar21 + -4));
    pbVar23 = pbVar19;
    if (iVar9 == 0) {
      if (uVar17 < 0x4f) {
        if (uVar17 != 0x4e) {
          if (uVar17 == 0x2a) {
            *(char *)(unaff_EBP + -0x4b) = *(char *)(unaff_EBP + -0x4b) + '\x01';
          }
          else if (uVar17 != 0x46) {
            if (uVar17 == 0x49) {
              bVar16 = pbVar26[2];
              if ((bVar16 == 0x36) && (pbVar26[3] == 0x34)) {
                *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x54) + 1;
                *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                *(undefined4 *)(unaff_EBP + -0x58) = 0;
                pbVar23 = pbVar26 + 3;
              }
              else if (((bVar16 != 0x33) || (pbVar23 = pbVar26 + 3, *pbVar23 != 0x32)) &&
                      ((((pbVar23 = pbVar19, bVar16 != 100 && (bVar16 != 0x69)) && (bVar16 != 0x6f))
                       && ((bVar16 != 0x78 && (bVar16 != 0x58)))))) goto LAB_00676968;
            }
            else if (uVar17 == 0x4c) {
              *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + '\x01';
            }
            else {
LAB_00676968:
              *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
              pbVar23 = pbVar19;
            }
          }
        }
      }
      else if (uVar17 == 0x68) {
        *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + -1;
        *(char *)(unaff_EBP + -0x4e) = *(char *)(unaff_EBP + -0x4e) + -1;
      }
      else {
        if (uVar17 == 0x6c) {
          *(char *)(unaff_EBP + -0x4f) = *(char *)(unaff_EBP + -0x4f) + '\x01';
        }
        else if (uVar17 != 0x77) goto LAB_00676968;
        *(char *)(unaff_EBP + -0x4e) = *(char *)(unaff_EBP + -0x4e) + '\x01';
      }
    }
    else {
      *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + 1;
      iVar14 = (uVar17 - 0x30) + iVar14 * 10;
    }
    pbVar26 = pbVar23;
  } while (*(char *)(unaff_EBP + -0x4c) == '\0');
  *(int *)(unaff_EBP + -0x48) = iVar14;
  *(byte **)(unaff_EBP + 0xc) = pbVar23;
  if (*(char *)(unaff_EBP + -0x4b) == '\0') {
    puVar5 = *(undefined4 **)(unaff_EBP + 0x10);
    *(undefined4 **)(unaff_EBP + -0x60) = puVar5;
    *(undefined4 **)(unaff_EBP + 0x10) = puVar5 + 1;
    pbVar19 = (byte *)*puVar5;
    *(byte **)(unaff_EBP + -100) = pbVar19;
  }
  else {
    pbVar19 = *(byte **)(unaff_EBP + -100);
  }
  *(undefined1 *)(unaff_EBP + -0x4c) = 0;
  if (*(char *)(unaff_EBP + -0x4e) == '\0') {
    if ((*pbVar23 == 0x53) || (*pbVar23 == 0x43)) {
      *(undefined1 *)(unaff_EBP + -0x4e) = 1;
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x4e) = 0xff;
    }
  }
  uVar17 = *pbVar23 | 0x20;
  *(uint *)(unaff_EBP + -0x68) = uVar17;
  if (uVar17 == 0x6e) {
LAB_006769fd:
    uVar10 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    if ((uVar17 != 99) && (uVar17 != 0x7b)) {
      do {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x6769ed;
        uVar10 = __inc();
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(undefined4 *)(puVar21 + -8) = 0x6769f5;
        iVar14 = _isspace(*(int *)(puVar21 + -4));
      } while (iVar14 != 0);
      *(undefined4 *)(unaff_EBP + -0x28) = uVar10;
      goto LAB_006769fd;
    }
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
    uVar10 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(puVar21 + -4) = 0x676a6a;
    uVar11 = __inc();
    *(undefined4 *)(unaff_EBP + -0x28) = uVar11;
  }
  iVar14 = *(int *)(unaff_EBP + -0x44);
  if ((iVar14 != 0) && (*(int *)(unaff_EBP + -0x48) == 0)) {
LAB_00676c66:
    uVar17 = *(uint *)(unaff_EBP + -0x28);
LAB_00677236:
    if (uVar17 != 0xffffffff) {
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(unaff_EBP + 8);
      *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -0x28);
      *(undefined4 *)(puVar21 + -0xc) = 0x677243;
      FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
    }
    goto LAB_00677266;
  }
  if (0x6f < uVar17) {
    if (uVar17 == 0x70) {
      *(undefined1 *)(unaff_EBP + -0x4f) = 1;
      goto LAB_00676fa8;
    }
    if (uVar17 == 0x73) goto LAB_00676c22;
    if (uVar17 == 0x75) goto LAB_00676fa8;
    if (uVar17 != 0x78) {
      if (uVar17 != 0x7b) goto LAB_00676c5b;
      if ('\0' < *(char *)(unaff_EBP + -0x4e)) {
        *(undefined1 *)(unaff_EBP + -0x4d) = 1;
      }
      iVar14 = *(int *)(unaff_EBP + 0xc);
      pbVar26 = (byte *)(iVar14 + 1);
      *(byte **)(unaff_EBP + 0xc) = pbVar26;
      *(byte **)(unaff_EBP + -0x1cc) = pbVar26;
      if (*pbVar26 == 0x5e) {
        pbVar26 = (byte *)(iVar14 + 2);
        *(byte **)(unaff_EBP + -0x1cc) = pbVar26;
        *(undefined1 *)(unaff_EBP + -0x49) = 0xff;
      }
      puVar18 = *(undefined1 **)(unaff_EBP + -0x20);
      puVar22 = puVar21;
      if (puVar18 == (undefined1 *)0x0) {
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(puVar21 + -4) = 0x20;
        iVar14 = *(int *)(puVar21 + -4);
        *(undefined4 *)(puVar21 + -4) = 0x676cc0;
        iVar14 = -iVar14;
        puVar22 = puVar21 + iVar14;
        puVar18 = puVar21 + iVar14;
        *(int *)(unaff_EBP + -0x18) = (int)puVar21 + iVar14;
        *(int *)(unaff_EBP + -0x20) = (int)puVar21 + iVar14;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      goto LAB_00676d06;
    }
LAB_00676a72:
    uVar13 = *(uint *)(unaff_EBP + -0x28);
    if (uVar13 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x4a) = 1;
LAB_00676ea6:
      piVar1 = (int *)(unaff_EBP + -0x48);
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar14 != 0)) {
        *(undefined1 *)(unaff_EBP + -0x4c) = 1;
      }
      else {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676ebf;
        uVar13 = __inc();
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
    }
    else if (uVar13 == 0x2b) goto LAB_00676ea6;
    if (uVar13 == 0x30) {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x676ed7;
      uVar13 = __inc();
      *(uint *)(unaff_EBP + -0x28) = uVar13;
      if (((char)uVar13 == 'x') || ((char)uVar13 == 'X')) {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676f2b;
        uVar13 = __inc();
        *(uint *)(unaff_EBP + -0x28) = uVar13;
        if ((*(int *)(unaff_EBP + -0x44) != 0) &&
           (*(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -2,
           *(int *)(unaff_EBP + -0x48) < 1)) {
          *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
        }
        *(undefined4 *)(puVar21 + -4) = 0x78;
LAB_00676f02:
        uVar17 = *(uint *)(puVar21 + -4);
        goto LAB_00676fd9;
      }
      *(undefined4 *)(unaff_EBP + -0x40) = 1;
      if (uVar17 != 0x78) {
        if (*(int *)(unaff_EBP + -0x44) != 0) {
          piVar1 = (int *)(unaff_EBP + -0x48);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
        }
        *(undefined4 *)(puVar21 + -4) = 0x6f;
        goto LAB_00676f02;
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      if (uVar13 != 0xffffffff) {
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(uint *)(puVar21 + -8) = uVar13;
        *(undefined4 *)(puVar21 + -0xc) = 0x676f17;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      *(undefined4 *)(puVar21 + -4) = 0x30;
      uVar13 = *(uint *)(puVar21 + -4);
      goto LAB_00676fd6;
    }
LAB_00676fd9:
    if (*(int *)(unaff_EBP + -0x54) == 0) {
      if (*(char *)(unaff_EBP + -0x4c) == '\0') {
        do {
          if ((uVar17 == 0x78) || (uVar17 == 0x70)) {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x677120;
            iVar14 = _isxdigit(*(int *)(puVar21 + -4));
            if (iVar14 != 0) {
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) << 4;
              *(uint *)(puVar21 + -4) = uVar13;
              *(undefined4 *)(puVar21 + -8) = 0x67712f;
              iVar14 = _isdigit(*(int *)(puVar21 + -4));
              if (iVar14 == 0) {
                uVar13 = (uVar13 & 0xffffffdf) - 7;
              }
              goto LAB_0067713f;
            }
LAB_0067713c:
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
          else {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x6770f8;
            iVar14 = _isdigit(*(int *)(puVar21 + -4));
            if (iVar14 == 0) goto LAB_0067713c;
            if (uVar17 == 0x6f) {
              if (0x37 < (int)uVar13) goto LAB_0067713c;
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) << 3;
            }
            else {
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) * 10;
            }
          }
LAB_0067713f:
          if (*(char *)(unaff_EBP + -0x4c) == '\0') {
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
            *(uint *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + -0x30 + uVar13;
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x48);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x4c) = 1;
                goto LAB_00677182;
              }
            }
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(undefined4 *)(puVar21 + -4) = 0x67716d;
            uVar13 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
            if (uVar13 != 0xffffffff) {
              *(undefined4 *)(puVar21 + -4) = uVar10;
              *(uint *)(puVar21 + -8) = uVar13;
              *(undefined4 *)(puVar21 + -0xc) = 0x677180;
              FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
            }
          }
LAB_00677182:
        } while (*(char *)(unaff_EBP + -0x4c) == '\0');
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
      if (*(char *)(unaff_EBP + -0x4a) != '\0') {
        *(int *)(unaff_EBP + -0x38) = -*(int *)(unaff_EBP + -0x38);
      }
    }
    else {
      if (*(char *)(unaff_EBP + -0x4c) == '\0') {
        do {
          if ((uVar17 == 0x78) || (uVar17 == 0x70)) {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x67703e;
            iVar14 = _isxdigit(*(int *)(puVar21 + -4));
            if (iVar14 != 0) {
              uVar6 = *(uint *)(unaff_EBP + -0x5c);
              *(uint *)(unaff_EBP + -0x5c) = uVar6 << 4;
              *(uint *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) << 4 | uVar6 >> 0x1c;
              *(uint *)(puVar21 + -4) = uVar13;
              *(undefined4 *)(puVar21 + -8) = 0x67705c;
              iVar14 = _isdigit(*(int *)(puVar21 + -4));
              if (iVar14 == 0) {
                uVar13 = (uVar13 & 0xffffffdf) - 7;
              }
              goto LAB_0067706c;
            }
LAB_00677069:
            *(char *)(unaff_EBP + -0x4c) = *(char *)(unaff_EBP + -0x4c) + '\x01';
          }
          else {
            *(uint *)(puVar21 + -4) = uVar13;
            *(undefined4 *)(puVar21 + -8) = 0x676ffd;
            iVar14 = _isdigit(*(int *)(puVar21 + -4));
            if (iVar14 == 0) goto LAB_00677069;
            if (uVar17 == 0x6f) {
              if (0x37 < (int)uVar13) goto LAB_00677069;
              uVar6 = *(uint *)(unaff_EBP + -0x5c);
              *(uint *)(unaff_EBP + -0x5c) = uVar6 << 3;
              *(uint *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) << 3 | uVar6 >> 0x1d;
            }
            else {
              *(undefined4 *)(puVar21 + -4) = 0;
              *(undefined4 *)(puVar21 + -8) = 10;
              *(undefined4 *)(puVar21 + -0xc) = *(undefined4 *)(unaff_EBP + -0x58);
              *(undefined4 *)(puVar21 + -0x10) = *(undefined4 *)(unaff_EBP + -0x5c);
              *(undefined4 *)(puVar21 + -0x14) = 0x677030;
              uVar27 = __allmul();
              *(undefined8 *)(unaff_EBP + -0x5c) = uVar27;
            }
          }
LAB_0067706c:
          if (*(char *)(unaff_EBP + -0x4c) == '\0') {
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
            uVar6 = uVar13 - 0x30;
            puVar2 = (uint *)(unaff_EBP + -0x5c);
            uVar3 = *puVar2;
            *puVar2 = *puVar2 + uVar6;
            *(int *)(unaff_EBP + -0x58) =
                 *(int *)(unaff_EBP + -0x58) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar3,uVar6);
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x48);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x4c) = 1;
                goto LAB_006770af;
              }
            }
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(undefined4 *)(puVar21 + -4) = 0x67709a;
            uVar13 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
            if (uVar13 != 0xffffffff) {
              *(undefined4 *)(puVar21 + -4) = uVar10;
              *(uint *)(puVar21 + -8) = uVar13;
              *(undefined4 *)(puVar21 + -0xc) = 0x6770ad;
              FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
            }
          }
LAB_006770af:
        } while (*(char *)(unaff_EBP + -0x4c) == '\0');
        *(uint *)(unaff_EBP + -0x28) = uVar13;
      }
      if (*(char *)(unaff_EBP + -0x4a) != '\0') {
        iVar14 = *(int *)(unaff_EBP + -0x5c);
        *(int *)(unaff_EBP + -0x5c) = -iVar14;
        *(uint *)(unaff_EBP + -0x58) = -(*(int *)(unaff_EBP + -0x58) + (uint)(iVar14 != 0));
      }
    }
    if (uVar17 == 0x46) {
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
    }
    if (*(int *)(unaff_EBP + -0x40) == 0) goto LAB_00677266;
    if (*(char *)(unaff_EBP + -0x4b) == '\0') {
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1;
      pbVar19 = *(byte **)(unaff_EBP + -100);
      uVar10 = *(undefined4 *)(unaff_EBP + -0x38);
LAB_006771ba:
      if (*(int *)(unaff_EBP + -0x54) == 0) {
        if (*(char *)(unaff_EBP + -0x4f) == '\0') {
          *(short *)pbVar19 = (short)uVar10;
        }
        else {
          *(undefined4 *)pbVar19 = uVar10;
        }
      }
      else {
        *(undefined4 *)pbVar19 = *(undefined4 *)(unaff_EBP + -0x5c);
        *(undefined4 *)(pbVar19 + 4) = *(undefined4 *)(unaff_EBP + -0x58);
      }
    }
    goto LAB_006771da;
  }
  if (uVar17 == 0x6f) {
LAB_00676fa8:
    uVar13 = *(uint *)(unaff_EBP + -0x28);
    if (uVar13 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x4a) = 1;
    }
    else if (uVar13 != 0x2b) goto LAB_00676fd9;
    piVar1 = (int *)(unaff_EBP + -0x48);
    *piVar1 = *piVar1 + -1;
    if ((*piVar1 == 0) && (iVar14 != 0)) {
      *(undefined1 *)(unaff_EBP + -0x4c) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      *(undefined4 *)(puVar21 + -4) = 0x676fd4;
      uVar13 = __inc();
LAB_00676fd6:
      *(uint *)(unaff_EBP + -0x28) = uVar13;
    }
    goto LAB_00676fd9;
  }
  if (uVar17 != 99) {
    if (uVar17 == 100) goto LAB_00676fa8;
    if (uVar17 < 0x65) {
LAB_00676c5b:
      if ((uint)**(byte **)(unaff_EBP + 0xc) != *(uint *)(unaff_EBP + -0x28)) goto LAB_00676c66;
      *(char *)(unaff_EBP + -0x29) = *(char *)(unaff_EBP + -0x29) + -1;
      if (*(char *)(unaff_EBP + -0x4b) == '\0') {
        *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(unaff_EBP + -0x60);
      }
    }
    else if (uVar17 < 0x68) {
      pcVar24 = (char *)(unaff_EBP + -0x1c8);
      iVar14 = *(int *)(unaff_EBP + -0x28);
      if (iVar14 == 0x2d) {
        *(undefined1 *)(unaff_EBP + -0x1c8) = 0x2d;
        pcVar24 = (char *)(unaff_EBP + -0x1c7);
LAB_00676aa8:
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        uVar10 = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(puVar21 + -4) = 0x676ab8;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
      }
      else {
        if (iVar14 == 0x2b) goto LAB_00676aa8;
        uVar10 = *(undefined4 *)(unaff_EBP + 8);
      }
      if ((*(int *)(unaff_EBP + -0x44) == 0) || (0x15d < *(int *)(unaff_EBP + -0x48))) {
        *(undefined4 *)(unaff_EBP + -0x48) = 0x15d;
      }
      while( true ) {
        *(int *)(puVar21 + -4) = iVar14;
        *(undefined4 *)(puVar21 + -8) = 0x676aff;
        iVar9 = _isdigit(*(int *)(puVar21 + -4));
        if ((iVar9 == 0) ||
           (iVar9 = *(int *)(unaff_EBP + -0x48),
           *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
        *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
        *pcVar24 = (char)iVar14;
        pcVar24 = pcVar24 + 1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676af4;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
      }
      if ((DAT_006ec184 == (char)iVar14) &&
         (iVar9 = *(int *)(unaff_EBP + -0x48),
         *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 != 0)) {
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676b20;
        iVar14 = __inc();
        *pcVar24 = DAT_006ec184;
        while( true ) {
          pcVar24 = pcVar24 + 1;
          *(int *)(puVar21 + -4) = iVar14;
          *(int *)(unaff_EBP + -0x28) = iVar14;
          *(undefined4 *)(puVar21 + -8) = 0x676b51;
          iVar9 = _isdigit(*(int *)(puVar21 + -4));
          if ((iVar9 == 0) ||
             (iVar9 = *(int *)(unaff_EBP + -0x48),
             *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
          *pcVar24 = (char)iVar14;
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676b46;
          iVar14 = __inc();
        }
      }
      pcVar25 = pcVar24;
      if ((*(int *)(unaff_EBP + -0x40) != 0) &&
         (((iVar14 == 0x65 || (iVar14 == 0x45)) &&
          (iVar9 = *(int *)(unaff_EBP + -0x48),
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 != 0)))) {
        *pcVar24 = 'e';
        pcVar25 = pcVar24 + 1;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(puVar21 + -4) = 0x676b7e;
        iVar14 = __inc();
        *(int *)(unaff_EBP + -0x28) = iVar14;
        if (iVar14 == 0x2d) {
          *pcVar25 = '-';
          pcVar25 = pcVar24 + 2;
LAB_00676b92:
          iVar9 = *(int *)(unaff_EBP + -0x48);
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1;
          if (iVar9 != 0) goto LAB_00676bb1;
          *(undefined4 *)(unaff_EBP + -0x48) = 0;
        }
        else if (iVar14 == 0x2b) goto LAB_00676b92;
        while( true ) {
          *(int *)(puVar21 + -4) = iVar14;
          *(undefined4 *)(puVar21 + -8) = 0x676bc6;
          iVar9 = _isdigit(*(int *)(puVar21 + -4));
          if ((iVar9 == 0) ||
             (iVar9 = *(int *)(unaff_EBP + -0x48),
             *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + -1, iVar9 == 0)) break;
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
          *pcVar25 = (char)iVar14;
          pcVar25 = pcVar25 + 1;
LAB_00676bb1:
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
          *(undefined4 *)(puVar21 + -4) = 0x676bbb;
          iVar14 = __inc();
          *(int *)(unaff_EBP + -0x28) = iVar14;
        }
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
      if (iVar14 != -1) {
        *(undefined4 *)(puVar21 + -4) = uVar10;
        *(int *)(puVar21 + -8) = iVar14;
        *(undefined4 *)(puVar21 + -0xc) = 0x676bda;
        FID_conflict__ungetc(*(int *)(puVar21 + -8),*(FILE **)(puVar21 + -4));
      }
      if (*(int *)(unaff_EBP + -0x40) == 0) goto LAB_00677266;
      if (*(char *)(unaff_EBP + -0x4b) == '\0') {
        *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 1;
        *pcVar25 = '\0';
        *(int *)(puVar21 + -4) = unaff_EBP + -0x1c8;
        *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(unaff_EBP + -100);
        *(int *)(puVar21 + -0xc) = *(char *)(unaff_EBP + -0x4f) + -1;
        puVar7 = PTR_FUN_006ebcb8;
        puVar20 = puVar21 + -0x10;
        *(undefined4 *)(puVar21 + -0x10) = 0x676c0c;
        (*(code *)puVar7)();
        puVar21 = puVar20 + 0xc;
      }
    }
    else {
      if (uVar17 == 0x69) {
        *(undefined4 *)(puVar21 + -4) = 100;
        uVar17 = *(uint *)(puVar21 + -4);
        goto LAB_00676a72;
      }
      if (uVar17 != 0x6e) goto LAB_00676c5b;
      uVar10 = *(undefined4 *)(unaff_EBP + -0x30);
      if (*(char *)(unaff_EBP + -0x4b) == '\0') goto LAB_006771ba;
    }
    goto LAB_006771da;
  }
  if (iVar14 == 0) {
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + 1;
  }
LAB_00676c22:
  if ('\0' < *(char *)(unaff_EBP + -0x4e)) {
    *(undefined1 *)(unaff_EBP + -0x4d) = 1;
  }
  goto LAB_00676dad;
}


// ==== 0x6772a1 __mtinitlocks

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 2003 Release */

int __cdecl __mtinitlocks(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_00717c20;
  do {
    if ((&DAT_006eb87c)[iVar2 * 2] == 1) {
      (&DAT_006eb878)[iVar2 * 2] = puVar3;
      puVar3 = puVar3 + 0x18;
      iVar1 = ___crtInitCritSecAndSpinCount((&DAT_006eb878)[iVar2 * 2],4000);
      if (iVar1 == 0) {
        (&DAT_006eb878)[iVar2 * 2] = 0;
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x24);
  return 1;
}


// ==== 0x6772ea __mtdeletelocks

/* Library Function - Single Match
    __mtdeletelocks
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  
  puVar1 = &DAT_006eb878;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)*puVar1;
    if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (puVar1[1] != 1)) {
      DeleteCriticalSection(lpCriticalSection);
      _free(lpCriticalSection);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x6eb998);
  puVar1 = &DAT_006eb878;
  do {
    if (((LPCRITICAL_SECTION)*puVar1 != (LPCRITICAL_SECTION)0x0) && (puVar1[1] == 1)) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*puVar1);
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x6eb998);
  return;
}


// ==== 0x67733f __unlock

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __unlock(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_006eb878)[param_1 * 2]);
  return;
}


// ==== 0x677354 __mtinitlocknum

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined4 __mtinitlocknum(int param_1)

{
  int *piVar1;
  void *_Memory;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = &DAT_006eb878 + param_1 * 2;
  if (*piVar1 != 0) {
    return 1;
  }
  _Memory = _malloc(0x18);
  if (_Memory == (void *)0x0) {
LAB_0067737b:
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0xc;
    uVar3 = 0;
  }
  else {
    __lock(10);
    if (*piVar1 == 0) {
      iVar4 = ___crtInitCritSecAndSpinCount(_Memory,4000);
      if (iVar4 == 0) {
        _free(_Memory);
        __unlock(10);
        goto LAB_0067737b;
      }
      *piVar1 = (int)_Memory;
    }
    else {
      _free(_Memory);
    }
    __unlock(10);
    uVar3 = 1;
  }
  return uVar3;
}


// ==== 0x6773d3 __lock

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __lock(int _File)

{
  int iVar1;
  
  if ((&DAT_006eb878)[_File * 2] == 0) {
    iVar1 = __mtinitlocknum(_File);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_006eb878)[_File * 2]);
  return;
}


// ==== 0x677404 ___sbh_heap_init

/* Library Function - Single Match
    ___sbh_heap_init
   
   Library: Visual Studio 2003 Release */

undefined4 ___sbh_heap_init(undefined4 param_1)

{
  DAT_00793208 = HeapAlloc(DAT_0079321c,0,0x140);
  if (DAT_00793208 == (LPVOID)0x0) {
    return 0;
  }
  DAT_00793200 = 0;
  DAT_00793204 = 0;
  DAT_00793210 = DAT_00793208;
  DAT_0079320c = param_1;
  DAT_00793214 = 0x10;
  return 1;
}


// ==== 0x67744c ___sbh_find_block

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 2003 Release */

uint ___sbh_find_block(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00793208;
  while( true ) {
    if (DAT_00793208 + DAT_00793204 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ==== 0x677477 ___sbh_free_block

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 2003 Release */

void ___sbh_free_block(uint *param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;
  
  uVar6 = param_1[4];
  puVar12 = (uint *)(param_2 + -4);
  uVar14 = param_2 - param_1[3] >> 0xf;
  piVar4 = (int *)(uVar14 * 0x204 + 0x144 + uVar6);
  local_8 = *puVar12 - 1;
  if ((local_8 & 1) == 0) {
    puVar10 = (uint *)(local_8 + (int)puVar12);
    uVar13 = *puVar10;
    uVar7 = *(uint *)(param_2 + -8);
    if ((uVar13 & 1) == 0) {
      uVar9 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (puVar10[1] == puVar10[2]) {
        if (uVar9 < 0x20) {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            *param_1 = *param_1 & uVar9;
          }
        }
        else {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            param_1[1] = param_1[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar13;
      *(uint *)(puVar10[2] + 4) = puVar10[1];
      *(uint *)(puVar10[1] + 8) = puVar10[2];
    }
    puVar10 = (uint *)(((int)local_8 >> 4) + -1);
    if ((uint *)0x3f < puVar10) {
      puVar10 = (uint *)0x3f;
    }
    puVar11 = param_1;
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) + -1);
      if ((uint *)0x3f < puVar11) {
        puVar11 = (uint *)0x3f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) + -1);
      if ((uint *)0x3f < puVar10) {
        puVar10 = (uint *)0x3f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              *param_1 = *param_1 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              param_1[1] = param_1[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      piVar1 = piVar4 + (int)puVar10 * 2;
      uVar13 = piVar1[1];
      puVar12[2] = (uint)piVar1;
      puVar12[1] = uVar13;
      piVar1[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar5 = *(char *)((int)puVar10 + uVar6 + 4);
        *(char *)((int)puVar10 + uVar6 + 4) = cVar5 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar5 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar5 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      if (DAT_00793200 != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_00793218 * 0x8000 + DAT_00793200[3]),0x8000,0x4000);
        DAT_00793200[2] = DAT_00793200[2] | 0x80000000U >> ((byte)DAT_00793218 & 0x1f);
        *(undefined4 *)(DAT_00793200[4] + 0xc4 + DAT_00793218 * 4) = 0;
        *(char *)(DAT_00793200[4] + 0x43) = *(char *)(DAT_00793200[4] + 0x43) + -1;
        if (*(char *)(DAT_00793200[4] + 0x43) == '\0') {
          DAT_00793200[1] = DAT_00793200[1] & 0xfffffffe;
        }
        if (DAT_00793200[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_00793200[3],0,0x8000);
          HeapFree(DAT_0079321c,0,(LPVOID)DAT_00793200[4]);
          _memmove(DAT_00793200,DAT_00793200 + 5,
                   (DAT_00793204 * 0x14 - (int)DAT_00793200) + -0x14 + DAT_00793208);
          DAT_00793204 = DAT_00793204 + -1;
          if (DAT_00793200 < param_1) {
            param_1 = param_1 + -5;
          }
          DAT_00793210 = DAT_00793208;
        }
      }
      DAT_00793200 = param_1;
      DAT_00793218 = uVar14;
    }
  }
  return;
}


// ==== 0x67778f ___sbh_alloc_new_region

/* Library Function - Single Match
    ___sbh_alloc_new_region
   
   Library: Visual Studio 2003 Release */

undefined4 * ___sbh_alloc_new_region(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_00793204 == DAT_00793214) {
    pvVar2 = HeapReAlloc(DAT_0079321c,0,DAT_00793208,(DAT_00793214 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_00793214 = DAT_00793214 + 0x10;
    DAT_00793208 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_00793208 + DAT_00793204 * 0x14);
  pvVar2 = HeapAlloc(DAT_0079321c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_00793204 = DAT_00793204 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0079321c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ==== 0x677846 ___sbh_alloc_new_group

/* Library Function - Single Match
    ___sbh_alloc_new_group
   
   Library: Visual Studio 2003 Release */

int ___sbh_alloc_new_group(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPVOID pvVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  LPVOID lpAddress;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar8 = 0;
  for (iVar3 = *(int *)(param_1 + 8); -1 < iVar3; iVar3 = iVar3 << 1) {
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8 * 0x204 + 0x144 + iVar2;
  iVar7 = 0x3f;
  iVar4 = iVar3;
  do {
    *(int *)(iVar4 + 8) = iVar4;
    *(int *)(iVar4 + 4) = iVar4;
    iVar4 = iVar4 + 8;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  lpAddress = (LPVOID)(iVar8 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar5 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar5 == (LPVOID)0x0) {
    iVar8 = -1;
  }
  else {
    if (lpAddress <= (LPVOID)((int)lpAddress + 0x7000U)) {
      piVar6 = (int *)((int)lpAddress + 0x10);
      iVar7 = ((uint)((int)((int)lpAddress + 0x7000U) - (int)lpAddress) >> 0xc) + 1;
      do {
        piVar6[-2] = -1;
        piVar6[0x3fb] = -1;
        *piVar6 = (int)(piVar6 + 0x3ff);
        piVar6[-1] = 0xff0;
        piVar6[1] = (int)(piVar6 + -0x401);
        piVar6[0x3fa] = 0xff0;
        piVar6 = piVar6 + 0x400;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(iVar3 + 0x1fc) = (int)lpAddress + 0xc;
    *(int *)((int)lpAddress + 0x14) = iVar3 + 0x1f8;
    *(int *)(iVar3 + 0x200) = (int)lpAddress + 0x700c;
    *(int *)((int)lpAddress + 0x7010) = iVar3 + 0x1f8;
    *(undefined4 *)(iVar2 + 0x44 + iVar8 * 4) = 0;
    *(undefined4 *)(iVar2 + 0xc4 + iVar8 * 4) = 1;
    cVar1 = *(char *)(iVar2 + 0x43);
    *(char *)(iVar2 + 0x43) = cVar1 + '\x01';
    if (cVar1 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar8 & 0x1f));
  }
  return iVar8;
}


// ==== 0x67794c ___sbh_resize_block

/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 2003 Release */

undefined4 ___sbh_resize_block(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar8 = param_1[4];
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar5 = uVar10 * 0x204 + 0x144 + uVar8;
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  param_3 = *(int *)(param_2 + -4) + -1;
  puVar9 = (uint *)(*(int *)(param_2 + -4) + -5 + param_2);
  uVar13 = *puVar9;
  if (param_3 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + param_3) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (puVar9[1] == puVar9[2]) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(uint *)(puVar9[2] + 4) = puVar9[1];
    *(uint *)(puVar9[1] + 8) = puVar9[2];
    iVar6 = uVar13 + (param_3 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar3 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar5 = iVar5 + uVar13 * 8;
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar5 + 4);
      *(int *)(iVar3 + 8) = iVar5;
      *(int *)(iVar5 + 4) = iVar3;
      *(int *)(*(int *)(iVar3 + 4) + 8) = iVar3;
      if (*(int *)(iVar3 + 4) == *(int *)(iVar3 + 8)) {
        cVar7 = *(char *)(uVar13 + 4 + uVar8);
        *(char *)(uVar13 + 4 + uVar8) = cVar7 + '\x01';
        if (uVar13 < 0x20) {
          if (cVar7 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> ((byte)uVar13 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar7 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar13 - 0x20 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          uVar13 = uVar13 - 0x20;
        }
        *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar13 & 0x1f);
      }
      piVar4 = (int *)(param_2 + -4 + uVar12);
      *piVar4 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar4) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < param_3) {
    param_3 = param_3 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar4 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar4[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (puVar9[1] == puVar9[2]) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(uint *)(puVar9[2] + 4) = puVar9[1];
      *(uint *)(puVar9[1] + 8) = puVar9[2];
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar5 = iVar5 + uVar11 * 8;
    iVar6 = *(int *)(iVar5 + 4);
    piVar4[2] = iVar5;
    piVar4[1] = iVar6;
    *(int **)(iVar5 + 4) = piVar4;
    *(int **)(piVar4[1] + 8) = piVar4;
    if (piVar4[1] == piVar4[2]) {
      cVar7 = *(char *)(uVar11 + 4 + uVar8);
      *(char *)(uVar11 + 4 + uVar8) = cVar7 + '\x01';
      if (uVar11 < 0x20) {
        if (cVar7 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> ((byte)uVar11 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar7 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        uVar11 = uVar11 - 0x20;
      }
      *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar11 & 0x1f);
    }
    *piVar4 = param_3;
    *(int *)(param_3 + -4 + (int)piVar4) = param_3;
  }
  return 1;
}


// ==== 0x677c2b ___sbh_alloc_block

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 2003 Release */

int * ___sbh_alloc_block(uint *param_1)

{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint local_c;
  int local_8;
  
  uVar8 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar9 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  puVar10 = DAT_00793208 + DAT_00793204 * 5;
  bVar7 = (byte)iVar9;
  param_1 = DAT_00793210;
  if (iVar9 < 0x20) {
    uVar15 = 0xffffffff >> (bVar7 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    uVar15 = 0;
    local_c = 0xffffffff >> (bVar7 - 0x20 & 0x1f);
  }
  for (; (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar15) == 0));
      param_1 = param_1 + 5) {
  }
  puVar13 = DAT_00793208;
  if (param_1 == puVar10) {
    for (; (puVar13 < DAT_00793210 && ((puVar13[1] & local_c) == 0 && (*puVar13 & uVar15) == 0));
        puVar13 = puVar13 + 5) {
    }
    param_1 = puVar13;
    if (puVar13 == DAT_00793210) {
      for (; (puVar13 < puVar10 && (puVar13[2] == 0)); puVar13 = puVar13 + 5) {
      }
      puVar14 = DAT_00793208;
      param_1 = puVar13;
      if (puVar13 == puVar10) {
        for (; (puVar14 < DAT_00793210 && (puVar14[2] == 0)); puVar14 = puVar14 + 5) {
        }
        param_1 = puVar14;
        if ((puVar14 == DAT_00793210) &&
           (param_1 = (uint *)___sbh_alloc_new_region(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      uVar6 = ___sbh_alloc_new_group(param_1);
      *(undefined4 *)param_1[4] = uVar6;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar5 = (int *)param_1[4];
  local_8 = *piVar5;
  if ((local_8 == -1) ||
     ((piVar5[local_8 + 0x31] & local_c) == 0 && (piVar5[local_8 + 0x11] & uVar15) == 0)) {
    local_8 = 0;
    puVar10 = (uint *)(piVar5 + 0x11);
    if ((piVar5[0x31] & local_c) == 0 && (*puVar10 & uVar15) == 0) {
      do {
        puVar13 = puVar10 + 0x21;
        local_8 = local_8 + 1;
        puVar10 = puVar10 + 1;
      } while ((*puVar13 & local_c) == 0 && (*puVar10 & uVar15) == 0);
    }
  }
  piVar3 = piVar5 + local_8 * 0x81 + 0x51;
  iVar9 = 0;
  uVar15 = piVar5[local_8 + 0x11] & uVar15;
  if (uVar15 == 0) {
    uVar15 = piVar5[local_8 + 0x31] & local_c;
    iVar9 = 0x20;
  }
  for (; -1 < (int)uVar15; uVar15 = uVar15 << 1) {
    iVar9 = iVar9 + 1;
  }
  piVar12 = (int *)piVar3[iVar9 * 2 + 1];
  iVar11 = *piVar12 - uVar8;
  iVar16 = (iVar11 >> 4) + -1;
  if (0x3f < iVar16) {
    iVar16 = 0x3f;
  }
  DAT_00793210 = param_1;
  if (iVar16 != iVar9) {
    if (piVar12[1] == piVar12[2]) {
      if (iVar9 < 0x20) {
        pcVar2 = (char *)((int)piVar5 + iVar9 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar9 & 0x1f));
        piVar5[local_8 + 0x11] = uVar15 & piVar5[local_8 + 0x11];
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *param_1 = *param_1 & uVar15;
        }
      }
      else {
        pcVar2 = (char *)((int)piVar5 + iVar9 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar9 - 0x20 & 0x1f));
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] & uVar15;
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          param_1[1] = param_1[1] & uVar15;
        }
      }
    }
    *(int *)(piVar12[2] + 4) = piVar12[1];
    *(int *)(piVar12[1] + 8) = piVar12[2];
    if (iVar11 == 0) goto LAB_00677ee4;
    piVar1 = piVar3 + iVar16 * 2;
    iVar9 = piVar1[1];
    piVar12[2] = (int)piVar1;
    piVar12[1] = iVar9;
    piVar1[1] = (int)piVar12;
    *(int **)(piVar12[1] + 8) = piVar12;
    if (piVar12[1] == piVar12[2]) {
      cVar4 = *(char *)(iVar16 + 4 + (int)piVar5);
      *(char *)(iVar16 + 4 + (int)piVar5) = cVar4 + '\x01';
      bVar7 = (byte)iVar16;
      if (iVar16 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar7 & 0x1f);
        }
        piVar5[local_8 + 0x11] = piVar5[local_8 + 0x11] | 0x80000000U >> (bVar7 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
        }
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar11 != 0) {
    *piVar12 = iVar11;
    *(int *)(iVar11 + -4 + (int)piVar12) = iVar11;
  }
LAB_00677ee4:
  piVar12 = (int *)((int)piVar12 + iVar11);
  *piVar12 = uVar8 + 1;
  *(uint *)((int)piVar12 + (uVar8 - 4)) = uVar8 + 1;
  iVar9 = *piVar3;
  *piVar3 = iVar9 + 1;
  if (((iVar9 == 0) && (param_1 == DAT_00793200)) && (local_8 == DAT_00793218)) {
    DAT_00793200 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar12 + 1;
}


// ==== 0x677f27 __callnewh

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_00717d70 != (code *)0x0) {
    iVar1 = (*DAT_00717d70)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x677f42 __errno

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int * __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


// ==== 0x677f4b ___doserrno

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

ulong * ___doserrno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


// ==== 0x677f54 __dosmaperr

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __dosmaperr(ulong param_1)

{
  _ptiddata p_Var1;
  uint uVar2;
  
  p_Var1 = __getptd();
  p_Var1->_tdoserrno = param_1;
  uVar2 = 0;
  do {
    if (param_1 == (&DAT_006eb998)[uVar2 * 2]) {
      p_Var1 = __getptd();
      p_Var1->_terrno = *(int *)(uVar2 * 8 + 0x6eb99c);
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x2d);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    p_Var1 = __getptd();
    p_Var1->_terrno = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    p_Var1 = __getptd();
    p_Var1->_terrno = 8;
    return;
  }
  p_Var1 = __getptd();
  p_Var1->_terrno = 0x16;
  return;
}


// ==== 0x677fc7 FUN_00677fc7

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00677fc7(uint param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  BOOL BVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint unaff_retaddr;
  char local_424 [1028];
  DWORD local_20;
  int local_1c;
  DWORD local_18;
  char *local_14;
  int local_10;
  ulong local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  local_18 = 0;
  local_1c = 0;
  if (param_3 == 0) {
    return 0;
  }
  piVar1 = &DAT_00793240 + ((int)param_1 >> 5);
  iVar8 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)(*piVar1 + 4 + iVar8) & 0x20) != 0) {
    __lseeki64_lk(param_1,0,0,2);
  }
  if ((*(byte *)((undefined4 *)(*piVar1 + iVar8) + 1) & 0x80) == 0) {
    BVar5 = WriteFile(*(HANDLE *)(*piVar1 + iVar8),param_2,param_3,&local_20,(LPOVERLAPPED)0x0);
    if (BVar5 == 0) {
      local_c = GetLastError();
    }
    else {
      local_c = 0;
      local_18 = local_20;
    }
LAB_006780c9:
    if (local_18 != 0) {
      return local_18 - local_1c;
    }
    if (local_c != 0) {
      if (local_c == 5) {
        puVar6 = (undefined4 *)__errno();
        *puVar6 = 9;
        puVar6 = (undefined4 *)___doserrno();
        *puVar6 = 5;
        return -1;
      }
      __dosmaperr(local_c);
      return -1;
    }
  }
  else {
    local_14 = param_2;
    local_c = 0;
    if (param_3 != 0) {
      do {
        uVar7 = (int)local_14 - (int)param_2;
        pcVar4 = local_424;
        local_10 = 0;
        do {
          if (param_3 <= uVar7) break;
          pcVar2 = local_14 + 1;
          cVar3 = *local_14;
          uVar7 = uVar7 + 1;
          local_14 = pcVar2;
          if (cVar3 == '\n') {
            local_1c = local_1c + 1;
            *pcVar4 = '\r';
            pcVar4 = pcVar4 + 1;
            local_10 = local_10 + 1;
          }
          *pcVar4 = cVar3;
          pcVar4 = pcVar4 + 1;
          local_10 = local_10 + 1;
        } while (local_10 < 0x400);
        BVar5 = WriteFile(*(HANDLE *)(*piVar1 + iVar8),local_424,(int)pcVar4 - (int)local_424,
                          &local_20,(LPOVERLAPPED)0x0);
        if (BVar5 == 0) {
          local_c = GetLastError();
          goto LAB_006780c9;
        }
        local_18 = local_18 + local_20;
        if (((int)local_20 < (int)pcVar4 - (int)local_424) ||
           (param_3 <= (uint)((int)local_14 - (int)param_2))) goto LAB_006780c9;
      } while( true );
    }
  }
  if (((*(byte *)(*piVar1 + 4 + iVar8) & 0x40) != 0) && (*param_2 == '\x1a')) {
    return 0;
  }
  puVar6 = (undefined4 *)__errno();
  *puVar6 = 0x1c;
  puVar6 = (undefined4 *)___doserrno();
  *puVar6 = 0;
  return -1;
}


// ==== 0x67816c __write

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 2003 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00793224) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      FUN_006806ac(_FileHandle);
      if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 9;
        puVar1 = (undefined4 *)___doserrno();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = FUN_00677fc7(_FileHandle,_Buf,_MaxCharCount);
      }
      FUN_006781f3();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 9;
  puVar1 = (undefined4 *)___doserrno();
  *puVar1 = 0;
  return -1;
}


// ==== 0x6781f0 FUN_006781f0

void FUN_006781f0(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}


// ==== 0x6781f3 FUN_006781f3

void FUN_006781f3(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== 0x678217 __commit

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 2003 Release */

int __cdecl __commit(int _FileHandle)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD *pDVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD local_20;
  
  if (DAT_00793224 <= (uint)_FileHandle) {
LAB_006782bf:
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 9;
    return -1;
  }
  iVar4 = (_FileHandle & 0x1fU) * 0x24;
  if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar4) & 1) == 0) goto LAB_006782bf;
  FUN_006806ac(_FileHandle);
  if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      local_20 = GetLastError();
    }
    else {
      local_20 = 0;
    }
    if (local_20 == 0) goto LAB_006782a6;
    pDVar2 = (DWORD *)___doserrno();
    *pDVar2 = local_20;
  }
  puVar3 = (undefined4 *)__errno();
  *puVar3 = 9;
  local_20 = 0xffffffff;
LAB_006782a6:
  FUN_006782b7();
  return local_20;
}


// ==== 0x6782b4 FUN_006782b4

void FUN_006782b4(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}


// ==== 0x6782b7 FUN_006782b7

void FUN_006782b7(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== 0x6782d3 ___crtLCMapStringA

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 2003 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  size_t _Size;
  LPCSTR pCVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  LPSTR lpDestStr;
  undefined4 uStackY_74;
  uint local_4c;
  LPCSTR local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  
  if (DAT_00717d78 == 0) {
    uStackY_74 = 0x678300;
    iVar3 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00717d78 = 2;
      }
    }
    else {
      DAT_00717d78 = 1;
    }
  }
  pcVar5 = (char *)_DwMapFlag;
  pCVar9 = _LpSrcStr;
  if (0 < (int)_LpSrcStr) {
    do {
      pCVar9 = pCVar9 + -1;
      if (*pcVar5 == '\0') goto LAB_00678339;
      pcVar5 = pcVar5 + 1;
    } while (pCVar9 != (LPCSTR)0x0);
    pCVar9 = (LPCSTR)0xffffffff;
LAB_00678339:
    _LpSrcStr = _LpSrcStr + (-1 - (int)pCVar9);
  }
  if ((DAT_00717d78 != 2) && (DAT_00717d78 != 0)) {
    if (DAT_00717d78 == 1) {
      iVar3 = 0;
      bVar2 = false;
      bVar1 = false;
      if (_CchDest == 0) {
        _CchDest = DAT_00717ea0;
      }
      uStackY_74 = 0x678399;
      iVar6 = MultiByteToWideChar(_CchDest,(uint)(_Code_page != 0) * 8 + 1,(LPCSTR)_DwMapFlag,
                                  (int)_LpSrcStr,(LPWSTR)0x0,0);
      if (iVar6 != 0) {
        puVar7 = (undefined1 *)(iVar6 * 2 + 3U & 0xfffffffc);
        iVar8 = -(int)puVar7;
        local_30 = &stack0xffffffa8 + iVar8;
        if (&stack0xffffffa8 == puVar7) {
          *(int *)(&stack0xffffffa4 + iVar8) = iVar6 * 2;
          *(undefined4 *)(&stack0xffffffa0 + iVar8) = 0x6783f2;
          local_30 = _malloc(*(size_t *)(&stack0xffffffa4 + iVar8));
          if (local_30 == (void *)0x0) {
            return 0;
          }
          bVar2 = true;
        }
        *(int *)(&stack0xffffffa4 + iVar8) = iVar6;
        *(undefined1 **)(&stack0xffffffa0 + iVar8) = local_30;
        *(LPCSTR *)(&stack0xffffff9c + iVar8) = _LpSrcStr;
        *(DWORD *)(&stack0xffffff98 + iVar8) = _DwMapFlag;
        *(undefined4 *)(&stack0xffffff94 + iVar8) = 1;
        *(int *)(&stack0xffffff90 + iVar8) = _CchDest;
        puVar10 = (undefined1 *)((int)&uStackY_74 + iVar8);
        *(undefined4 *)((int)&uStackY_74 + iVar8) = 0x67841a;
        iVar8 = MultiByteToWideChar(*(UINT *)(&stack0xffffff90 + iVar8),
                                    *(DWORD *)(&stack0xffffff94 + iVar8),
                                    *(LPCSTR *)(&stack0xffffff98 + iVar8),
                                    *(int *)(&stack0xffffff9c + iVar8),
                                    *(LPWSTR *)(&stack0xffffffa0 + iVar8),
                                    *(int *)(&stack0xffffffa4 + iVar8));
        puVar7 = puVar10;
        if (iVar8 != 0) {
          *(undefined4 *)(puVar10 + -4) = 0;
          *(undefined4 *)(puVar10 + -8) = 0;
          *(int *)(puVar10 + -0xc) = iVar6;
          *(undefined1 **)(puVar10 + -0x10) = local_30;
          *(LPCWSTR *)(puVar10 + -0x14) = _LocaleName;
          *(_locale_t *)(puVar10 + -0x18) = _Plocinfo;
          puVar11 = puVar10 + -0x1c;
          *(undefined4 *)(puVar10 + -0x1c) = 0x678434;
          iVar3 = LCMapStringW(*(LCID *)(puVar10 + -0x18),*(DWORD *)(puVar10 + -0x14),
                               *(LPCWSTR *)(puVar10 + -0x10),*(int *)(puVar10 + -0xc),
                               *(LPWSTR *)(puVar10 + -8),*(int *)(puVar10 + -4));
          puVar7 = puVar11;
          if (iVar3 != 0) {
            if (((uint)_LocaleName & 0x400) == 0) {
              puVar7 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
              *(undefined4 *)(puVar11 + -4) = 0x678489;
              iVar8 = -(int)puVar7;
              local_34 = puVar11 + iVar8;
              if (puVar11 == puVar7) {
                *(int *)(puVar11 + iVar8 + -4) = iVar3 * 2;
                *(undefined4 *)(puVar11 + iVar8 + -8) = 0x6784c0;
                local_34 = _malloc(*(size_t *)(puVar11 + iVar8 + -4));
                puVar7 = puVar11 + iVar8;
                if (local_34 == (undefined1 *)0x0) goto LAB_00678508;
                bVar1 = true;
              }
              *(int *)(puVar11 + iVar8 + -4) = iVar3;
              *(undefined1 **)(puVar11 + iVar8 + -8) = local_34;
              *(int *)(puVar11 + iVar8 + -0xc) = iVar6;
              *(undefined1 **)(puVar11 + iVar8 + -0x10) = local_30;
              *(LPCWSTR *)(puVar11 + iVar8 + -0x14) = _LocaleName;
              *(_locale_t *)(puVar11 + iVar8 + -0x18) = _Plocinfo;
              puVar13 = puVar11 + iVar8 + -0x1c;
              *(undefined4 *)(puVar11 + iVar8 + -0x1c) = 0x6784e3;
              iVar6 = LCMapStringW(*(LCID *)(puVar11 + iVar8 + -0x18),
                                   *(DWORD *)(puVar11 + iVar8 + -0x14),
                                   *(LPCWSTR *)(puVar11 + iVar8 + -0x10),
                                   *(int *)(puVar11 + iVar8 + -0xc),
                                   *(LPWSTR *)(puVar11 + iVar8 + -8),*(int *)(puVar11 + iVar8 + -4))
              ;
              puVar7 = puVar13;
              if (iVar6 != 0) {
                *(undefined4 *)(puVar13 + -4) = 0;
                *(undefined4 *)(puVar13 + -8) = 0;
                if (_LpDestStr == (LPSTR)0x0) {
                  *(undefined4 *)(puVar13 + -0xc) = 0;
                  *(undefined4 *)(puVar13 + -0x10) = 0;
                }
                else {
                  *(LPSTR *)(puVar13 + -0xc) = _LpDestStr;
                  *(int *)(puVar13 + -0x10) = _CchSrc;
                }
                *(int *)(puVar13 + -0x14) = iVar3;
                *(undefined1 **)(puVar13 + -0x18) = local_34;
                *(undefined4 *)(puVar13 + -0x1c) = 0;
                *(int *)(puVar13 + -0x20) = _CchDest;
                puVar7 = puVar13 + -0x24;
                *(undefined4 *)(puVar13 + -0x24) = 0x678506;
                iVar3 = WideCharToMultiByte(*(UINT *)(puVar13 + -0x20),*(DWORD *)(puVar13 + -0x1c),
                                            *(LPCWSTR *)(puVar13 + -0x18),*(int *)(puVar13 + -0x14),
                                            *(LPSTR *)(puVar13 + -0x10),*(int *)(puVar13 + -0xc),
                                            *(LPCSTR *)(puVar13 + -8),*(LPBOOL *)(puVar13 + -4));
              }
            }
            else if ((_LpDestStr != (LPSTR)0x0) && (iVar3 <= (int)_LpDestStr)) {
              *(LPSTR *)(puVar11 + -4) = _LpDestStr;
              *(int *)(puVar11 + -8) = _CchSrc;
              *(int *)(puVar11 + -0xc) = iVar6;
              *(undefined1 **)(puVar11 + -0x10) = local_30;
              *(LPCWSTR *)(puVar11 + -0x14) = _LocaleName;
              *(_locale_t *)(puVar11 + -0x18) = _Plocinfo;
              puVar12 = puVar11 + -0x1c;
              *(undefined4 *)(puVar11 + -0x1c) = 0x67846f;
              LCMapStringW(*(LCID *)(puVar11 + -0x18),*(DWORD *)(puVar11 + -0x14),
                           *(LPCWSTR *)(puVar11 + -0x10),*(int *)(puVar11 + -0xc),
                           *(LPWSTR *)(puVar11 + -8),*(int *)(puVar11 + -4));
              puVar7 = puVar12;
            }
          }
        }
LAB_00678508:
        if (bVar1) {
          *(undefined1 **)(puVar7 + -4) = local_34;
          *(undefined4 *)(puVar7 + -8) = 0x678515;
          _free(*(void **)(puVar7 + -4));
        }
        if (bVar2) {
          *(undefined1 **)(puVar7 + -4) = local_30;
          *(undefined4 *)(puVar7 + -8) = 0x678523;
          _free(*(void **)(puVar7 + -4));
          return iVar3;
        }
        return iVar3;
      }
    }
    return 0;
  }
  local_38 = (LPCSTR)0x0;
  lpDestStr = (LPSTR)0x0;
  bVar1 = false;
  if (_Plocinfo == (_locale_t)0x0) {
    _Plocinfo = DAT_00717e90;
  }
  if (_CchDest == 0) {
    _CchDest = DAT_00717ea0;
  }
  iVar3 = FUN_0068088e();
  if (iVar3 == -1) {
    return 0;
  }
  if (iVar3 == _CchDest) {
    uStackY_74 = 0x678674;
    local_4c = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                            (LPSTR)_CchSrc,(int)_LpDestStr);
    goto LAB_00678676;
  }
  uStackY_74 = 0x678580;
  local_38 = (LPCSTR)FUN_006808d7();
  if (local_38 == (LPCSTR)0x0) {
    return 0;
  }
  uStackY_74 = 0x67859c;
  _Size = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,local_38,(int)_LpSrcStr,(LPSTR)0x0,0);
  if (_Size != 0) {
    lpDestStr = &stack0xffffffa8;
    _memset(&stack0xffffffa8,0,_Size);
    if (&stack0x00000000 == (undefined1 *)0x58) {
      lpDestStr = _malloc(_Size);
      if (lpDestStr != (LPSTR)0x0) {
        _memset(lpDestStr,0,_Size);
        bVar1 = true;
        goto LAB_00678607;
      }
    }
    else {
LAB_00678607:
      uStackY_74 = 0x67861d;
      iVar3 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,local_38,(int)_LpSrcStr,lpDestStr,
                           _Size);
      if (iVar3 != 0) {
        uStackY_74 = 0x67863e;
        iVar3 = FUN_006808d7();
        local_4c = (uint)(iVar3 != 0);
        goto LAB_0067864e;
      }
    }
    local_4c = 0;
  }
LAB_0067864e:
  if (bVar1) {
    _free(lpDestStr);
  }
LAB_00678676:
  if (local_38 != (LPCSTR)0x0) {
    _free(local_38);
    return local_4c;
  }
  return local_4c;
}


// ==== 0x6783c9 FUN_006783c9

undefined4 FUN_006783c9(void)

{
  return 1;
}


// ==== 0x6783cd FUN_006783cd

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_006783cd(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x6783d5;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x1c);
  iVar1 = *(int *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x2c) == 0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x6783f2;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x2c) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar4 = 0;
      goto LAB_00678686;
    }
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(undefined4 *)(iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar5 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x67841a;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar9 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    *(int *)(puVar5 + -0xc) = iVar1;
    *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    puVar6 = puVar5 + -0x1c;
    *(undefined4 *)(puVar5 + -0x1c) = 0x678434;
    iVar4 = LCMapStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                         *(LPCWSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                         *(LPWSTR *)(puVar5 + -8),*(int *)(puVar5 + -4));
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    puVar9 = puVar6;
    if (iVar4 != 0) {
      if ((*(byte *)(unaff_EBP + 0xd) & 4) == 0) {
        *(undefined4 *)(unaff_EBP + -4) = 2;
        *(undefined4 *)(puVar6 + -4) = 0x678489;
        iVar3 = -(iVar4 * 2 + 3U & 0xfffffffc);
        *(int *)(unaff_EBP + -0x18) = (int)puVar6 + iVar3;
        *(int *)(unaff_EBP + -0x30) = (int)puVar6 + iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + -0x30) == 0) {
          *(int *)(puVar6 + iVar3 + -4) = iVar4 * 2;
          *(undefined4 *)(puVar6 + iVar3 + -8) = 0x6784c0;
          pvVar2 = _malloc(*(size_t *)(puVar6 + iVar3 + -4));
          *(void **)(unaff_EBP + -0x30) = pvVar2;
          puVar9 = puVar6 + iVar3;
          if (pvVar2 == (void *)0x0) goto LAB_00678508;
          *(undefined4 *)(unaff_EBP + -0x24) = 1;
        }
        *(int *)(puVar6 + iVar3 + -4) = iVar4;
        *(undefined4 *)(puVar6 + iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x30);
        *(int *)(puVar6 + iVar3 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(undefined4 *)(puVar6 + iVar3 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar8 = puVar6 + iVar3 + -0x1c;
        *(undefined4 *)(puVar6 + iVar3 + -0x1c) = 0x6784e3;
        iVar3 = LCMapStringW(*(LCID *)(puVar6 + iVar3 + -0x18),*(DWORD *)(puVar6 + iVar3 + -0x14),
                             *(LPCWSTR *)(puVar6 + iVar3 + -0x10),*(int *)(puVar6 + iVar3 + -0xc),
                             *(LPWSTR *)(puVar6 + iVar3 + -8),*(int *)(puVar6 + iVar3 + -4));
        puVar9 = puVar8;
        if (iVar3 != 0) {
          *(undefined4 *)(puVar8 + -4) = 0;
          *(undefined4 *)(puVar8 + -8) = 0;
          if (*(int *)(unaff_EBP + 0x1c) == 0) {
            *(undefined4 *)(puVar8 + -0xc) = 0;
            *(undefined4 *)(puVar8 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
            *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
          }
          *(int *)(puVar8 + -0x14) = iVar4;
          *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + -0x30);
          *(undefined4 *)(puVar8 + -0x1c) = 0;
          *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
          puVar9 = puVar8 + -0x24;
          *(undefined4 *)(puVar8 + -0x24) = 0x678506;
          iVar4 = WideCharToMultiByte(*(UINT *)(puVar8 + -0x20),*(DWORD *)(puVar8 + -0x1c),
                                      *(LPCWSTR *)(puVar8 + -0x18),*(int *)(puVar8 + -0x14),
                                      *(LPSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                      *(LPCSTR *)(puVar8 + -8),*(LPBOOL *)(puVar8 + -4));
        }
      }
      else if ((*(int *)(unaff_EBP + 0x1c) != 0) && (iVar4 <= *(int *)(unaff_EBP + 0x1c))) {
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + 0x1c);
        *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + 0x18);
        *(int *)(puVar6 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar7 = puVar6 + -0x1c;
        *(undefined4 *)(puVar6 + -0x1c) = 0x67846f;
        LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                     *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8),
                     *(int *)(puVar6 + -4));
        puVar9 = puVar7;
      }
    }
  }
LAB_00678508:
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar9 + -8) = 0x678515;
    _free(*(void **)(puVar9 + -4));
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar9 + -8) = 0x678523;
    _free(*(void **)(puVar9 + -4));
  }
LAB_00678686:
  *(undefined4 *)(unaff_EBP + -0x58) = 0x67868e;
  return iVar4;
}


// ==== 0x678497 FUN_00678497

undefined4 FUN_00678497(void)

{
  return 1;
}


// ==== 0x67849b FUN_0067849b

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_0067849b(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x6784a3;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x1c);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x30) == 0) {
    *(int *)(puVar6 + -4) = iVar4 * 2;
    *(undefined4 *)(puVar6 + -8) = 0x6784c0;
    pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
    *(void **)(unaff_EBP + -0x30) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_00678508;
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
  }
  *(int *)(puVar6 + -4) = iVar4;
  *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + -0x30);
  *(undefined4 *)(puVar6 + -0xc) = uVar1;
  *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = puVar6 + -0x1c;
  *(undefined4 *)(puVar6 + -0x1c) = 0x6784e3;
  iVar3 = LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                       *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8)
                       ,*(int *)(puVar6 + -4));
  puVar6 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    if (*(int *)(unaff_EBP + 0x1c) == 0) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
      *(undefined4 *)(puVar5 + -0x10) = 0;
    }
    else {
      *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    }
    *(int *)(puVar5 + -0x14) = iVar4;
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar5 + -0x1c) = 0;
    *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar6 = puVar5 + -0x24;
    *(undefined4 *)(puVar5 + -0x24) = 0x678506;
    iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
  }
LAB_00678508:
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(puVar6 + -8) = 0x678515;
    _free(*(void **)(puVar6 + -4));
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(puVar6 + -8) = 0x678523;
    _free(*(void **)(puVar6 + -4));
  }
  *(undefined4 *)(unaff_EBP + -0x58) = 0x67868e;
  return iVar4;
}


// ==== 0x6785cc FUN_006785cc

undefined4 FUN_006785cc(void)

{
  return 1;
}


// ==== 0x6785d0 FUN_006785d0

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

bool FUN_006785d0(void)

{
  undefined1 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  int unaff_EBP;
  bool bVar5;
  
  puVar1 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar1 + -4) = 0x6785d8;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x40);
  *(undefined4 *)(puVar1 + -8) = 0x6785ec;
  pvVar2 = _malloc(*(size_t *)(puVar1 + -4));
  puVar4 = puVar1;
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x40);
    *(undefined4 *)(puVar1 + -8) = 0;
    *(void **)(puVar1 + -0xc) = pvVar2;
    *(undefined4 *)(puVar1 + -0x10) = 0x6785fd;
    _memset(*(void **)(puVar1 + -0xc),*(int *)(puVar1 + -8),*(size_t *)(puVar1 + -4));
    *(undefined4 *)(unaff_EBP + -0x38) = 1;
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x40);
    *(void **)(puVar1 + -8) = pvVar2;
    *(undefined4 *)(puVar1 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined4 *)(puVar1 + -0x10) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 *)(puVar1 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(puVar1 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = puVar1 + -0x1c;
    *(undefined4 *)(puVar1 + -0x1c) = 0x67861d;
    iVar3 = LCMapStringA(*(LCID *)(puVar1 + -0x18),*(DWORD *)(puVar1 + -0x14),
                         *(LPCSTR *)(puVar1 + -0x10),*(int *)(puVar1 + -0xc),*(LPSTR *)(puVar1 + -8)
                         ,*(int *)(puVar1 + -4));
    *(int *)(unaff_EBP + -0x40) = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(unaff_EBP + 0x18);
      *(int *)(puVar4 + -0xc) = unaff_EBP + -0x40;
      *(void **)(puVar4 + -0x10) = pvVar2;
      *(undefined4 *)(puVar4 + -0x14) = *(undefined4 *)(unaff_EBP + 0x20);
      *(undefined4 *)(puVar4 + -0x18) = *(undefined4 *)(unaff_EBP + -0x3c);
      *(undefined4 *)(puVar4 + -0x1c) = 0x67863e;
      iVar3 = FUN_006808d7();
      bVar5 = iVar3 != 0;
      goto LAB_0067864e;
    }
  }
  bVar5 = false;
LAB_0067864e:
  if (*(int *)(unaff_EBP + -0x38) != 0) {
    *(void **)(puVar4 + -4) = pvVar2;
    *(undefined4 *)(puVar4 + -8) = 0x678659;
    _free(*(void **)(puVar4 + -4));
  }
  if (*(int *)(unaff_EBP + -0x34) != 0) {
    *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 *)(puVar4 + -8) = 0x678683;
    _free(*(void **)(puVar4 + -4));
  }
  *(undefined4 *)(unaff_EBP + -0x58) = 0x67868e;
  return bVar5;
}


// ==== 0x67868f __stbuf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __stbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl __stbuf(FILE *_File)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = __isatty(_File->_file);
  if (iVar3 == 0) {
    return 0;
  }
  if (_File == (FILE *)&DAT_006eb1e0) {
    iVar3 = 0;
  }
  else {
    if (_File != (FILE *)&DAT_006eb200) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_00717a80 = _DAT_00717a80 + 1;
  if ((_File->_flag & 0x10c) != 0) {
    return 0;
  }
  piVar1 = &DAT_00717d7c + iVar3;
  if (*piVar1 == 0) {
    pvVar4 = _malloc(0x1000);
    *piVar1 = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      _File->_base = (char *)&_File->_charbuf;
      _File->_ptr = (char *)&_File->_charbuf;
      _File->_bufsiz = 2;
      _File->_cnt = 2;
      goto LAB_00678706;
    }
  }
  pcVar2 = (char *)*piVar1;
  _File->_base = pcVar2;
  _File->_ptr = pcVar2;
  _File->_bufsiz = 0x1000;
  _File->_cnt = 0x1000;
LAB_00678706:
  *(ushort *)&_File->_flag = (ushort)_File->_flag | 0x1102;
  return 1;
}


// ==== 0x678717 __ftbuf

/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __ftbuf(int _Flag,FILE *_File)

{
  byte *pbVar1;
  
  if ((_Flag != 0) && ((_File->_flag & 0x1000) != 0)) {
    __flush(_File);
    pbVar1 = (byte *)((int)&_File->_flag + 1);
    *pbVar1 = *pbVar1 & 0xee;
    _File->_bufsiz = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
  }
  return;
}


// ==== 0x678741 __openfile

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __openfile
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl __openfile(char *_Filename,char *_Mode,int _ShFlag,FILE *_File)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint _OpenFlag;
  uint uVar6;
  
  cVar1 = *_Mode;
  bVar4 = false;
  bVar3 = false;
  if (cVar1 == 'a') {
    _OpenFlag = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      _OpenFlag = 0;
      uVar6 = DAT_00717eec | 1;
      goto LAB_00678782;
    }
    if (cVar1 != 'w') {
      return (FILE *)0x0;
    }
    _OpenFlag = 0x301;
  }
  uVar6 = DAT_00717eec | 2;
LAB_00678782:
  bVar2 = true;
LAB_00678861:
  _Mode = _Mode + 1;
  cVar1 = *_Mode;
  if ((cVar1 == '\0') || (!bVar2)) {
    iVar5 = __sopen(_Filename,_OpenFlag,_ShFlag,0x1a4);
    if (iVar5 < 0) {
      return (FILE *)0x0;
    }
    _DAT_00717a80 = _DAT_00717a80 + 1;
    _File->_flag = uVar6;
    _File->_cnt = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_tmpfname = (char *)0x0;
    _File->_file = iVar5;
    return _File;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((_OpenFlag & 0x1000) == 0) {
        _OpenFlag = _OpenFlag | 0x1000;
        goto LAB_00678861;
      }
    }
    else if (cVar1 == '+') {
      if ((_OpenFlag & 2) == 0) {
        _OpenFlag = _OpenFlag & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_00678861;
      }
    }
    else if (cVar1 == 'D') {
      if ((_OpenFlag & 0x40) == 0) {
        _OpenFlag = _OpenFlag | 0x40;
        goto LAB_00678861;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        _OpenFlag = _OpenFlag | 0x10;
        goto LAB_00678861;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      _OpenFlag = _OpenFlag | 0x20;
      goto LAB_00678861;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((_OpenFlag & 0xc000) != 0) goto LAB_00678843;
      _OpenFlag = _OpenFlag | 0x8000;
      goto LAB_00678861;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_00678861;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((_OpenFlag & 0xc000) != 0)) goto LAB_00678843;
        _OpenFlag = _OpenFlag | 0x4000;
        goto LAB_00678861;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_00678861;
      }
    }
  }
LAB_00678843:
  bVar2 = false;
  goto LAB_00678861;
}


// ==== 0x6788a9 __getstream

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl __getstream(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  FILE *pFVar4;
  FILE *_File;
  
  pFVar4 = (FILE *)0x0;
  __lock(1);
  iVar3 = 0;
  do {
    _File = pFVar4;
    if (DAT_00794360 <= iVar3) {
LAB_00678998:
      if (_File != (FILE *)0x0) {
        _File->_cnt = 0;
        _File->_flag = 0;
        _File->_base = (char *)0x0;
        _File->_ptr = (char *)0x0;
        _File->_tmpfname = (char *)0x0;
        _File->_file = -1;
      }
      FUN_006789c2();
      return _File;
    }
    iVar1 = *(int *)(DAT_00793350 + iVar3 * 4);
    if (iVar1 == 0) {
      iVar3 = iVar3 * 4;
      pvVar2 = _malloc(0x38);
      *(void **)(iVar3 + DAT_00793350) = pvVar2;
      if (*(int *)(iVar3 + DAT_00793350) != 0) {
        iVar1 = ___crtInitCritSecAndSpinCount(*(int *)(iVar3 + DAT_00793350) + 0x20,4000);
        if (iVar1 == 0) {
          _free(*(void **)(iVar3 + DAT_00793350));
          *(undefined4 *)(iVar3 + DAT_00793350) = 0;
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00793350) + 0x20));
          _File = *(FILE **)(iVar3 + DAT_00793350);
        }
      }
      goto LAB_00678998;
    }
    if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
      if (((2 < iVar3) && (iVar3 < 0x14)) && (iVar1 = __mtinitlocknum(iVar3 + 0x10), iVar1 == 0))
      goto LAB_00678998;
      __lock_file2(iVar3,*(void **)(DAT_00793350 + iVar3 * 4));
      _File = *(FILE **)(DAT_00793350 + iVar3 * 4);
      if ((_File->_flag & 0x83) == 0) goto LAB_00678998;
      __unlock_file2(iVar3,_File);
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


// ==== 0x6789bf FUN_006789bf

void FUN_006789bf(void)

{
  __unlock(1);
  return;
}


// ==== 0x6789c2 FUN_006789c2

void FUN_006789c2(void)

{
  __unlock(1);
  return;
}


// ==== 0x6789cb __filbuf

/* Library Function - Single Match
    __filbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl __filbuf(FILE *_File)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = _File->_flag;
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      _File->_flag = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        __getbuf(_File);
      }
      else {
        _File->_ptr = _File->_base;
      }
      iVar3 = __read(_File->_file,_File->_base,_File->_bufsiz);
      _File->_cnt = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((_File->_flag & 0x82U) == 0) {
          uVar2 = _File->_file;
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_006eb840;
          }
          else {
            puVar4 = (undefined *)((&DAT_00793240)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            _File->_flag = _File->_flag | 0x2000;
          }
        }
        if (((_File->_bufsiz == 0x200) && ((_File->_flag & 8U) != 0)) &&
           ((_File->_flag & 0x400U) == 0)) {
          _File->_bufsiz = 0x1000;
        }
        _File->_cnt = iVar3 + -1;
        bVar1 = *_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
        return (uint)bVar1;
      }
      _File->_flag = _File->_flag | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      _File->_cnt = 0;
    }
    else {
      _File->_flag = uVar2 | 0x20;
    }
  }
  return -1;
}


// ==== 0x678aac FUN_00678aac

int FUN_00678aac(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  char cVar4;
  byte bVar5;
  BOOL BVar6;
  DWORD DVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iVar10;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_00793240 + ((int)param_1 >> 5);
    iVar10 = (param_1 & 0x1f) * 0x24;
    bVar5 = *(byte *)(*piVar1 + iVar10 + 4);
    if ((bVar5 & 2) == 0) {
      pcVar9 = param_2;
      if (((bVar5 & 0x48) != 0) && (cVar4 = *(char *)(*piVar1 + iVar10 + 5), cVar4 != '\n')) {
        param_3 = (char *)((int)param_3 - 1);
        *param_2 = cVar4;
        pcVar9 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar10) = 10;
      }
      BVar6 = ReadFile(*(HANDLE *)(*piVar1 + iVar10),pcVar9,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        DVar7 = GetLastError();
        if (DVar7 == 5) {
          puVar8 = (undefined4 *)__errno();
          *puVar8 = 9;
          puVar8 = (undefined4 *)___doserrno();
          *puVar8 = 5;
        }
        else {
          if (DVar7 == 0x6d) {
            return 0;
          }
          __dosmaperr(DVar7);
        }
        return -1;
      }
      pbVar2 = (byte *)(*piVar1 + 4 + iVar10);
      bVar5 = *pbVar2;
      if (-1 < (char)bVar5) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar5 = bVar5 & 0xfb;
      }
      else {
        bVar5 = bVar5 | 4;
      }
      *pbVar2 = bVar5;
      local_c = param_2 + (int)local_c + local_10;
      param_3 = param_2;
      pcVar9 = param_2;
      if (param_2 < local_c) {
        do {
          cVar4 = *param_3;
          if (cVar4 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar10);
            bVar5 = *pbVar2;
            if ((bVar5 & 0x40) == 0) {
              *pbVar2 = bVar5 | 2;
            }
            break;
          }
          if (cVar4 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                pcVar3 = param_3 + 2;
                goto LAB_00678c2b;
              }
LAB_00678c45:
              param_3 = param_3 + 1;
              *pcVar9 = '\r';
            }
            else {
              pcVar3 = param_3 + 1;
              BVar6 = ReadFile(*(HANDLE *)(*piVar1 + iVar10),&local_5,1,&local_10,(LPOVERLAPPED)0x0)
              ;
              if (((BVar6 == 0) && (DVar7 = GetLastError(), DVar7 != 0)) || (local_10 == 0))
              goto LAB_00678c45;
              if ((*(byte *)(*piVar1 + 4 + iVar10) & 0x48) == 0) {
                if ((pcVar9 == param_2) && (local_5 == '\n')) goto LAB_00678c2b;
                __lseek_lk(param_1,0xffffffff,1);
                if (local_5 == '\n') goto LAB_00678c49;
                goto LAB_00678c45;
              }
              if (local_5 == '\n') {
LAB_00678c2b:
                param_3 = pcVar3;
                *pcVar9 = '\n';
              }
              else {
                *pcVar9 = '\r';
                *(char *)(*piVar1 + 5 + iVar10) = local_5;
                param_3 = pcVar3;
              }
            }
            pcVar9 = pcVar9 + 1;
            pcVar3 = param_3;
          }
          else {
            *pcVar9 = cVar4;
            pcVar9 = pcVar9 + 1;
            pcVar3 = param_3 + 1;
          }
LAB_00678c49:
          param_3 = pcVar3;
        } while (param_3 < local_c);
      }
      return (int)pcVar9 - (int)param_2;
    }
  }
  return 0;
}


// ==== 0x678c79 __read

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __read
   
   Library: Visual Studio 2003 Release */

int __cdecl __read(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00793224) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      FUN_006806ac(_FileHandle);
      if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 9;
        puVar1 = (undefined4 *)___doserrno();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = FUN_00678aac(_FileHandle,_DstBuf,_MaxCharCount);
      }
      FUN_00678d00();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 9;
  puVar1 = (undefined4 *)___doserrno();
  *puVar1 = 0;
  return -1;
}


// ==== 0x678cfd FUN_00678cfd

void FUN_00678cfd(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}


// ==== 0x678d00 FUN_00678d00

void FUN_00678d00(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== 0x678d30 _memcpy

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _memcpy(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar3 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = _Size >> 2;
      uVar2 = _Size & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_00678eeb_caseD_2;
        case 3:
          goto switchD_00678eeb_caseD_3;
        }
        goto switchD_00678eeb_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_00678eeb_caseD_0;
      case 1:
        goto switchD_00678eeb_caseD_1;
      case 2:
        goto switchD_00678eeb_caseD_2;
      case 3:
        goto switchD_00678eeb_caseD_3;
      default:
        uVar1 = _Size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00678eeb_caseD_2;
            case 3:
              goto switchD_00678eeb_caseD_3;
            }
            goto switchD_00678eeb_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00678eeb_caseD_2;
            case 3:
              goto switchD_00678eeb_caseD_3;
            }
            goto switchD_00678eeb_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00678eeb_caseD_2;
            case 3:
              goto switchD_00678eeb_caseD_3;
            }
            goto switchD_00678eeb_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_00678eeb_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return _Dst;
    case 2:
switchD_00678eeb_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return _Dst;
    case 3:
switchD_00678eeb_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return _Dst;
    }
switchD_00678eeb_caseD_0:
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar1 = _Size >> 2;
    uVar2 = _Size & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_00678d65_caseD_2;
      case 3:
        goto switchD_00678d65_caseD_3;
      }
      goto switchD_00678d65_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_00678d65_caseD_0;
    case 1:
      goto switchD_00678d65_caseD_1;
    case 2:
      goto switchD_00678d65_caseD_2;
    case 3:
      goto switchD_00678d65_caseD_3;
    default:
      uVar1 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar3 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00678d65_caseD_2;
          case 3:
            goto switchD_00678d65_caseD_3;
          }
          goto switchD_00678d65_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar3 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00678d65_caseD_2;
          case 3:
            goto switchD_00678d65_caseD_3;
          }
          goto switchD_00678d65_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        _Src = (void *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00678d65_caseD_2;
          case 3:
            goto switchD_00678d65_caseD_3;
          }
          goto switchD_00678d65_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)_Src + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)_Src + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)_Src + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)_Src + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)_Src + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)_Src + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)_Src + (uVar1 - 1) * 4);
    _Src = (void *)((int)_Src + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00678d65_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    return _Dst;
  case 2:
switchD_00678d65_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_00678d65_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_00678d65_caseD_0:
  return _Dst;
}


// ==== 0x67906d _calloc

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _calloc(size_t _Count,size_t _Size)

{
  int iVar1;
  uint _Size_00;
  uint dwBytes;
  void *_Dst;
  
  _Size_00 = _Count * _Size;
  dwBytes = _Size_00;
  if (_Size_00 == 0) {
    dwBytes = 1;
  }
  do {
    _Dst = (void *)0x0;
    if (dwBytes < 0xffffffe1) {
      if ((DAT_00793220 == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, _Size_00 <= DAT_0079320c)) {
        __lock(4);
        _Dst = (void *)___sbh_alloc_block(_Size_00);
        FUN_00679117();
        if (_Dst != (void *)0x0) {
          _memset(_Dst,0,_Size_00);
          goto LAB_006790e2;
        }
      }
      else {
LAB_006790e2:
        if (_Dst != (void *)0x0) {
          return _Dst;
        }
      }
      _Dst = HeapAlloc(DAT_0079321c,8,dwBytes);
    }
    if (_Dst != (void *)0x0) {
      return _Dst;
    }
    if (DAT_00717d74 == 0) {
      return (void *)0x0;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== 0x679114 FUN_00679114

void FUN_00679114(void)

{
  __unlock(4);
  return;
}


// ==== 0x679117 FUN_00679117

void FUN_00679117(void)

{
  __unlock(4);
  return;
}


// ==== 0x679128 __fcloseall

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 2003 Release */

int __cdecl __fcloseall(void)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_20;
  
  local_20 = 0;
  __lock(1);
  for (iVar3 = 3; iVar3 < DAT_00794360; iVar3 = iVar3 + 1) {
    iVar2 = iVar3 * 4;
    _File = *(FILE **)(iVar2 + DAT_00793350);
    if (_File != (FILE *)0x0) {
      if ((_File->_flag & 0x83) != 0) {
        iVar1 = _fclose(_File);
        if (iVar1 != -1) {
          local_20 = local_20 + 1;
        }
      }
      if (0x13 < iVar3) {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar2 + DAT_00793350) + 0x20));
        _free(*(void **)(iVar2 + DAT_00793350));
        *(undefined4 *)(iVar2 + DAT_00793350) = 0;
      }
    }
  }
  FUN_006791ba();
  return local_20;
}


// ==== 0x6791ba FUN_006791ba

void FUN_006791ba(void)

{
  __unlock(1);
  return;
}


// ==== 0x6791c3 __lseek_lk

/* Library Function - Single Match
    __lseek_lk
   
   Library: Visual Studio 2003 Release */

DWORD __lseek_lk(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  undefined4 *puVar2;
  DWORD DVar3;
  ulong uVar4;
  
  hFile = (HANDLE)__get_osfhandle(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 9;
    return 0xffffffff;
  }
  DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
  if (DVar3 == 0xffffffff) {
    uVar4 = GetLastError();
  }
  else {
    uVar4 = 0;
  }
  if (uVar4 == 0) {
    pbVar1 = (byte *)((&DAT_00793240)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  else {
    __dosmaperr(uVar4);
    DVar3 = 0xffffffff;
  }
  return DVar3;
}


// ==== 0x679237 __lseek

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 2003 Release */

long __cdecl __lseek(int _FileHandle,long _Offset,int _Origin)

{
  undefined4 *puVar1;
  int iVar2;
  long local_20;
  
  if ((uint)_FileHandle < DAT_00793224) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      FUN_006806ac(_FileHandle);
      if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 9;
        puVar1 = (undefined4 *)___doserrno();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = __lseek_lk(_FileHandle,_Offset,_Origin);
      }
      FUN_006792be();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 9;
  puVar1 = (undefined4 *)___doserrno();
  *puVar1 = 0;
  return -1;
}


// ==== 0x6792bb FUN_006792bb

void FUN_006792bb(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}


// ==== 0x6792be FUN_006792be

void FUN_006792be(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== 0x6792e2 __mbsnbicoll

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  _ptiddata p_Var1;
  pthreadmbcinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = p_Var1->_tpxcptinfoptrs;
  if (ptVar2 != DAT_00792fc4) {
    ptVar2 = ___updatetmbcinfo();
  }
  if (_MaxCount == 0) {
    return 0;
  }
  iVar3 = FUN_00680dfe(*(undefined4 *)ptVar2->mbulinfo,1,_Str1,_MaxCount,_Str2,_MaxCount,
                       ptVar2->mbcodepage);
  if (iVar3 == 0) {
    return 0x7fffffff;
  }
  return iVar3 + -2;
}


// ==== 0x679330 FUN_00679330

undefined4 FUN_00679330(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  LPSTR lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_00717ab0;
  puVar2 = DAT_00717ab0;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(0,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (LPSTR)0x0)) ||
       (iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*puVar2,-1,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_00681236(lpMultiByteStr,0);
    puVar2 = puVar2 + 1;
    lpWideCharStr = (LPCWSTR)*puVar2;
  }
  return 0xffffffff;
}


// ==== 0x67939b FUN_0067939b

undefined4 FUN_0067939b(uint param_1)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = __get_osfhandle(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_006793e9;
    }
    hObject = (HANDLE)__get_osfhandle(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_006793eb;
    }
  }
LAB_006793e9:
  DVar4 = 0;
LAB_006793eb:
  __free_osfhnd(param_1);
  *(undefined1 *)((&DAT_00793240)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    __dosmaperr(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ==== 0x67941e __close

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 2003 Release */

int __cdecl __close(int _FileHandle)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00793224) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      FUN_006806ac(_FileHandle);
      if ((*(byte *)((&DAT_00793240)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)__errno();
        *puVar1 = 9;
        local_20 = -1;
      }
      else {
        local_20 = FUN_0067939b(_FileHandle);
      }
      FUN_00679495();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 9;
  puVar1 = (undefined4 *)___doserrno();
  *puVar1 = 0;
  return -1;
}


// ==== 0x679492 FUN_00679492

void FUN_00679492(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}


// ==== 0x679495 FUN_00679495

void FUN_00679495(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== 0x6794b9 __freebuf

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    _free(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


// ==== 0x6794e4 terminate

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* Library Function - Single Match
    void __cdecl terminate(void)
   
   Library: Visual Studio 2003 Release */

void __cdecl terminate(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->ptlocinfo != (pthreadlocinfo)0x0) {
    p_Var1 = __getptd();
    (*(code *)p_Var1->ptlocinfo)();
  }
  FUN_0067fc40();
  return;
}


// ==== 0x679509 FUN_00679509

undefined4 FUN_00679509(void)

{
  return 1;
}


// ==== 0x67950d FUN_0067950d

void FUN_0067950d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0067fc40();
  return;
}


// ==== 0x679519 _inconsistency

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __cdecl _inconsistency(void)

{
  if (PTR_terminate_006ebb00 != (undefined *)0x0) {
    (*(code *)PTR_terminate_006ebb00)();
  }
  terminate();
  return;
}


// ==== 0x679536 FUN_00679536

undefined4 FUN_00679536(void)

{
  return 1;
}


// ==== 0x67953a FUN_0067953a

void FUN_0067953a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  terminate();
  return;
}


// ==== 0x679546 FUN_00679546

void FUN_00679546(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== 0x679558 siglookup

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 2003 Release */

void __cdecl siglookup(void)

{
  uint uVar1;
  uint in_EDX;
  int unaff_ESI;
  
  uVar1 = in_EDX;
  do {
    if (*(int *)(uVar1 + 4) == unaff_ESI) {
      return;
    }
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < in_EDX + DAT_006eb83c * 0xc);
  return;
}


// ==== 0x679586 _raise

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2003 Release */

int __cdecl _raise(int _SigNum)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  void *local_30;
  void *local_2c;
  _ptiddata local_28;
  
  bVar1 = false;
  if (_SigNum == 2) {
    puVar3 = &DAT_00717d84;
    pcVar4 = DAT_00717d84;
LAB_00679613:
    bVar1 = true;
  }
  else {
    if (((_SigNum != 4) && (_SigNum != 8)) && (_SigNum != 0xb)) {
      if (_SigNum == 0xf) {
        puVar3 = &DAT_00717d90;
        pcVar4 = DAT_00717d90;
      }
      else if (_SigNum == 0x15) {
        puVar3 = &DAT_00717d88;
        pcVar4 = DAT_00717d88;
      }
      else {
        if (_SigNum != 0x16) {
          return -1;
        }
        puVar3 = &DAT_00717d8c;
        pcVar4 = DAT_00717d8c;
      }
      goto LAB_00679613;
    }
    local_28 = __getptd();
    iVar2 = siglookup();
    puVar3 = (undefined4 *)(iVar2 + 8);
    pcVar4 = (code *)*puVar3;
  }
  if (pcVar4 == (code *)0x1) {
    return 0;
  }
  if (pcVar4 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (bVar1) {
    __lock(0);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_2c = local_28->_initarg;
    local_28->_initarg = (void *)0x0;
    if (_SigNum == 8) {
      local_30 = local_28->_pxcptacttab;
      local_28->_pxcptacttab = (void *)0x8c;
      goto LAB_00679672;
    }
  }
  else {
LAB_00679672:
    iVar2 = DAT_006eb830;
    if (_SigNum == 8) {
      for (; iVar2 < DAT_006eb834 + DAT_006eb830; iVar2 = iVar2 + 1) {
        *(undefined4 *)((int)local_28->_initaddr + iVar2 * 0xc + 8) = 0;
      }
      goto LAB_006796a0;
    }
  }
  *puVar3 = 0;
LAB_006796a0:
  FUN_006796c1();
  if (_SigNum == 8) {
    (*pcVar4)(8,local_28->_pxcptacttab);
  }
  else {
    (*pcVar4)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  local_28->_initarg = local_2c;
  if (_SigNum == 8) {
    local_28->_pxcptacttab = local_30;
  }
  return 0;
}


// ==== 0x6796b9 FUN_006796b9

void FUN_006796b9(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    __unlock(0);
  }
  return;
}


// ==== 0x6796c1 FUN_006796c1

void __fastcall FUN_006796c1(int param_1)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != param_1) {
    __unlock(param_1);
  }
  return;
}


// ==== 0x6796ff FUN_006796ff

undefined4 FUN_006796ff(void)

{
  int in_EAX;
  
  if (in_EAX == 0x3a4) {
    return 0x411;
  }
  if (in_EAX == 0x3a8) {
    return 0x804;
  }
  if (in_EAX == 0x3b5) {
    return 0x412;
  }
  if (in_EAX != 0x3b6) {
    return 0;
  }
  return 0x404;
}


// ==== 0x67972e setSBCS

/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 2003 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00792fe0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_007930e4 = 0;
  DAT_00792fc8 = 0;
  DAT_00792fc0 = 0;
  DAT_007930f0 = 0;
  DAT_007930f4 = 0;
  DAT_007930f8 = 0;
  return;
}


// ==== 0x679757 FUN_00679757

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00679757(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  BYTE *pBVar8;
  undefined4 *puVar9;
  uint unaff_retaddr;
  _locale_t _BError;
  ushort local_51c [256];
  undefined1 local_31c [256];
  undefined1 local_21c [256];
  undefined4 local_11c [64];
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  BVar2 = GetCPInfo((UINT)DAT_007930e4,&local_1c);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      *(char *)((int)local_11c + uVar3) = (char)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_11c[0]._0_1_ = 0x20;
    if (local_1c.LeadByte[0] != 0) {
      pBVar8 = local_1c.LeadByte + 1;
      do {
        uVar3 = (uint)local_1c.LeadByte[0];
        if (uVar3 <= *pBVar8) {
          uVar6 = (*pBVar8 - uVar3) + 1;
          puVar9 = (undefined4 *)((int)local_11c + uVar3);
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar9 = 0x20202020;
            puVar9 = puVar9 + 1;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar9 = 0x20;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
        local_1c.LeadByte[0] = pBVar8[1];
        pBVar8 = pBVar8 + 2;
      } while (local_1c.LeadByte[0] != 0);
    }
    BVar2 = 1;
    ___crtGetStringTypeA
              ((_locale_t)0x1,(DWORD)local_11c,(LPCSTR)0x100,(int)local_51c,DAT_007930e4,
               (int)DAT_00792fc0,0);
    _BError = DAT_00792fc0;
    ___crtLCMapStringA(DAT_00792fc0,(LPCWSTR)0x100,(DWORD)local_11c,(LPCSTR)0x100,(int)local_21c,
                       (LPSTR)0x100,(int)DAT_007930e4,0,BVar2);
    ___crtLCMapStringA(DAT_00792fc0,(LPCWSTR)0x200,(DWORD)local_11c,(LPCSTR)0x100,(int)local_31c,
                       (LPSTR)0x100,(int)DAT_007930e4,0,(BOOL)_BError);
    uVar3 = 0;
    do {
      if ((local_51c[uVar3] & 1) == 0) {
        if ((local_51c[uVar3] & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_00792fe0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar4 = local_31c[uVar3];
          goto LAB_0067986c;
        }
        (&DAT_00793100)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00792fe0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar4 = local_21c[uVar3];
LAB_0067986c:
        (&DAT_00793100)[uVar3] = uVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_00792fe0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar5 = (char)uVar3 + -0x20;
          goto LAB_006798af;
        }
        (&DAT_00793100)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00792fe0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar5 = (char)uVar3 + ' ';
LAB_006798af:
        (&DAT_00793100)[uVar3] = cVar5;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ==== 0x6798e9 ___updatetmbcinfo

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetmbcinfo
   
   Library: Visual Studio 2003 Release */

pthreadmbcinfo __cdecl ___updatetmbcinfo(void)

{
  _ptiddata p_Var1;
  pthreadmbcinfo _Memory;
  
  __lock(0xd);
  p_Var1 = __getptd();
  _Memory = p_Var1->_tpxcptinfoptrs;
  if (_Memory != DAT_00792fc4) {
    if ((_Memory != (pthreadmbcinfo)0x0) &&
       (_Memory->refcount = _Memory->refcount + -1, _Memory->refcount == 0)) {
      _free(_Memory);
    }
    p_Var1->_tpxcptinfoptrs = DAT_00792fc4;
    _Memory = DAT_00792fc4;
    DAT_00792fc4->refcount = DAT_00792fc4->refcount + 1;
  }
  FUN_0067994f();
  return _Memory;
}


// ==== 0x67994c FUN_0067994c

void FUN_0067994c(void)

{
  __unlock(0xd);
  return;
}


// ==== 0x67994f FUN_0067994f

void FUN_0067994f(void)

{
  __unlock(0xd);
  return;
}


// ==== 0x679958 FUN_00679958

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00679958(UINT param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  BOOL BVar6;
  BYTE *pBVar7;
  int iVar8;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint unaff_retaddr;
  _cpinfo local_20;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (param_1 != 0) {
    iVar9 = 0;
    uVar5 = 0;
    do {
      if (*(UINT *)((int)&DAT_006ebb10 + uVar5) == param_1) {
        puVar12 = &DAT_00792fe0;
        for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
        }
        local_c = 0;
        *(undefined1 *)puVar12 = 0;
        pbVar10 = (byte *)(iVar9 * 0x30 + 0x6ebb20);
        do {
          bVar4 = *pbVar10;
          pbVar11 = pbVar10;
          while ((bVar4 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
            uVar5 = (uint)bVar4;
            if (uVar5 <= bVar3) {
              bVar4 = (&DAT_006ebb08)[local_c];
              do {
                pbVar2 = (byte *)((int)&DAT_00792fe0 + uVar5 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar5 = uVar5 + 1;
              } while (uVar5 <= bVar3);
            }
            pbVar11 = pbVar11 + 2;
            bVar4 = *pbVar11;
          }
          local_c = local_c + 1;
          pbVar10 = pbVar10 + 8;
        } while (local_c < 4);
        DAT_007930e4 = param_1;
        DAT_00792fc8 = 1;
        DAT_00792fc0 = FUN_006796ff();
        DAT_007930f0 = *(undefined4 *)(&DAT_006ebb14 + extraout_ECX);
        DAT_007930f4 = *(undefined4 *)(&DAT_006ebb18 + extraout_ECX);
        DAT_007930f8 = *(undefined4 *)(&DAT_006ebb1c + extraout_ECX);
        goto LAB_00679ad2;
      }
      uVar5 = uVar5 + 0x30;
      iVar9 = iVar9 + 1;
    } while (uVar5 < 0xf0);
    BVar6 = GetCPInfo(param_1,&local_20);
    if (BVar6 == 1) {
      puVar12 = &DAT_00792fe0;
      for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined1 *)puVar12 = 0;
      DAT_007930e4 = param_1;
      DAT_00792fc0 = 0;
      if (local_20.MaxCharSize < 2) {
        DAT_00792fc8 = 0;
      }
      else {
        if (local_20.LeadByte[0] != '\0') {
          pBVar7 = local_20.LeadByte + 1;
          do {
            bVar4 = *pBVar7;
            if (bVar4 == 0) break;
            for (uVar5 = (uint)pBVar7[-1]; uVar5 <= bVar4; uVar5 = uVar5 + 1) {
              pbVar10 = (byte *)((int)&DAT_00792fe0 + uVar5 + 1);
              *pbVar10 = *pbVar10 | 4;
            }
            pBVar1 = pBVar7 + 1;
            pBVar7 = pBVar7 + 2;
          } while (*pBVar1 != 0);
        }
        uVar5 = 1;
        do {
          pbVar10 = (byte *)((int)&DAT_00792fe0 + uVar5 + 1);
          *pbVar10 = *pbVar10 | 8;
          uVar5 = uVar5 + 1;
        } while (uVar5 < 0xff);
        DAT_00792fc0 = FUN_006796ff();
        DAT_00792fc8 = extraout_ECX_00;
      }
      DAT_007930f0 = 0;
      DAT_007930f4 = 0;
      DAT_007930f8 = 0;
      goto LAB_00679ad2;
    }
    if (DAT_00717d98 == 0) {
      return 0xffffffff;
    }
  }
  setSBCS();
LAB_00679ad2:
  FUN_00679757();
  return 0;
}


// ==== 0x679aee __setmbcp

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 2003 Release */

int __cdecl __setmbcp(int _CodePage)

{
  int *_Memory;
  int iVar1;
  int local_20;
  
  local_20 = -1;
  __lock(0xd);
  DAT_00717d98 = 0;
  if (_CodePage == -2) {
    DAT_00717d98 = 1;
    _CodePage = GetOEMCP();
  }
  else if (_CodePage == -3) {
    DAT_00717d98 = 1;
    _CodePage = GetACP();
  }
  else if (_CodePage == -4) {
    DAT_00717d98 = 1;
    _CodePage = DAT_00717ea0;
  }
  if (_CodePage == DAT_007930e4) {
    local_20 = 0;
  }
  else {
    if ((DAT_00792fc4 == (int *)0x0) || (_Memory = DAT_00792fc4, *DAT_00792fc4 != 0)) {
      _Memory = _malloc(0x220);
    }
    if ((_Memory != (int *)0x0) && (local_20 = FUN_00679958(_CodePage), local_20 == 0)) {
      *_Memory = 0;
      _Memory[1] = DAT_007930e4;
      _Memory[2] = DAT_00792fc8;
      _Memory[3] = DAT_00792fc0;
      for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
        *(undefined2 *)((int)_Memory + iVar1 * 2 + 0x10) =
             *(undefined2 *)((int)&DAT_007930f0 + iVar1 * 2);
      }
      for (iVar1 = 0; iVar1 < 0x101; iVar1 = iVar1 + 1) {
        *(undefined1 *)(iVar1 + 0x1c + (int)_Memory) = *(undefined1 *)((int)&DAT_00792fe0 + iVar1);
      }
      for (iVar1 = 0; DAT_00792fc4 = _Memory, iVar1 < 0x100; iVar1 = iVar1 + 1) {
        *(undefined1 *)(iVar1 + 0x11d + (int)_Memory) = (&DAT_00793100)[iVar1];
      }
    }
    if ((local_20 == -1) && (_Memory != DAT_00792fc4)) {
      _free(_Memory);
    }
  }
  FUN_00679c35();
  return local_20;
}


// ==== 0x679c35 FUN_00679c35

void FUN_00679c35(void)

{
  __unlock(0xd);
  return;
}


// ==== 0x679c3e ___initmbctable

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 2003 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_0079334c == 0) {
    __setmbcp(-3);
    DAT_0079334c = 1;
  }
  return 0;
}


// ==== 0x679c5c FUN_00679c5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00679c5c(void)

{
  char cVar1;
  char cVar2;
  UINT CodePage;
  char *_Str1;
  int iVar3;
  size_t sVar4;
  long lVar5;
  DWORD DVar6;
  char *_Str;
  int local_8;
  
  __lock(7);
  CodePage = DAT_00717ea0;
  _DAT_006ebca4 = 0xffffffff;
  _DAT_006ebc98 = 0xffffffff;
  _DAT_00717e4c = 0;
  _Str1 = (char *)__getenv_lk(&DAT_006ac77c);
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_00717e50 != (char *)0x0) {
      _free(DAT_00717e50);
      DAT_00717e50 = (char *)0x0;
    }
    __unlock(7);
    DVar6 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00717da0);
    if (DVar6 == 0xffffffff) {
      return;
    }
    DAT_006ebc00 = DAT_00717da0 * 0x3c;
    _DAT_00717e4c = 1;
    if (DAT_00717de6 != 0) {
      DAT_006ebc00 = DAT_006ebc00 + DAT_00717df4 * 0x3c;
    }
    if ((DAT_00717e3a == 0) || (DAT_00717e48 == 0)) {
      _DAT_006ebc04 = 0;
      _DAT_006ebc08 = 0;
    }
    else {
      _DAT_006ebc08 = (DAT_00717e48 - DAT_00717df4) * 0x3c;
      _DAT_006ebc04 = 1;
    }
    iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00717da4,-1,PTR_DAT_006ebc90,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar3 == 0) || (local_8 != 0)) {
      *PTR_DAT_006ebc90 = 0;
    }
    else {
      PTR_DAT_006ebc90[0x3f] = 0;
    }
    iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00717df8,-1,PTR_DAT_006ebc94,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar3 != 0) && (local_8 == 0)) {
      PTR_DAT_006ebc94[0x3f] = 0;
      return;
    }
LAB_00679ec1:
    *PTR_DAT_006ebc94 = 0;
  }
  else {
    if (DAT_00717e50 == (char *)0x0) {
LAB_00679cdc:
      sVar4 = _strlen(_Str1);
      DAT_00717e50 = _malloc(sVar4 + 1);
      if (DAT_00717e50 != (char *)0x0) {
        _strcpy(DAT_00717e50,_Str1);
        __unlock(7);
        _strncpy(PTR_DAT_006ebc90,_Str1,3);
        _Str = _Str1 + 3;
        PTR_DAT_006ebc90[3] = 0;
        cVar1 = *_Str;
        if (cVar1 == '-') {
          _Str = _Str1 + 4;
        }
        lVar5 = _atol(_Str);
        DAT_006ebc00 = lVar5 * 0xe10;
        for (; (cVar2 = *_Str, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':')))); _Str = _Str + 1) {
        }
        if (*_Str == ':') {
          _Str = _Str + 1;
          lVar5 = _atol(_Str);
          DAT_006ebc00 = DAT_006ebc00 + lVar5 * 0x3c;
          for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
          }
          if (*_Str == ':') {
            _Str = _Str + 1;
            lVar5 = _atol(_Str);
            DAT_006ebc00 = DAT_006ebc00 + lVar5;
            for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_006ebc00 = -DAT_006ebc00;
        }
        _DAT_006ebc04 = (int)*_Str;
        if (_DAT_006ebc04 != 0) {
          _strncpy(PTR_DAT_006ebc94,_Str,3);
          PTR_DAT_006ebc94[3] = 0;
          return;
        }
        goto LAB_00679ec1;
      }
    }
    else {
      iVar3 = _strcmp(_Str1,DAT_00717e50);
      if (iVar3 != 0) {
        if (DAT_00717e50 != (char *)0x0) {
          _free(DAT_00717e50);
        }
        goto LAB_00679cdc;
      }
    }
    __unlock(7);
  }
  return;
}


// ==== 0x679ecd FUN_00679ecd

void FUN_00679ecd(void)

{
  if (DAT_00717e54 == 0) {
    __lock(6);
    if (DAT_00717e54 == 0) {
      FUN_00679c5c();
      DAT_00717e54 = DAT_00717e54 + 1;
    }
    __unlock(6);
  }
  return;
}


// ==== 0x679f00 __aullrem

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = param_1;
  uVar9 = param_4;
  uVar10 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}


// ==== 0x679f75 __forcdecpt

/* Library Function - Single Match
    __forcdecpt
   
   Library: Visual Studio 2003 Release */

void __cdecl __forcdecpt(char *_Buf)

{
  char cVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = _tolower((int)*_Buf);
  bVar4 = iVar3 == 0x65;
  while (!bVar4) {
    _Buf = _Buf + 1;
    iVar3 = _isdigit((int)*_Buf);
    bVar4 = iVar3 == 0;
  }
  cVar2 = *_Buf;
  *_Buf = DAT_006ec184;
  do {
    _Buf = _Buf + 1;
    cVar1 = *_Buf;
    *_Buf = cVar2;
    cVar2 = cVar1;
  } while (*_Buf != '\0');
  return;
}


// ==== 0x679fb1 FUN_00679fb1

void FUN_00679fb1(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; (*param_1 != '\0' && (*param_1 != DAT_006ec184)); param_1 = param_1 + 1) {
  }
  if (*param_1 != '\0') {
    do {
      param_1 = param_1 + 1;
      cVar1 = *param_1;
      pcVar2 = param_1;
      if ((cVar1 == '\0') || (cVar1 == 'e')) break;
    } while (cVar1 != 'E');
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + -1;
    } while (*pcVar2 == '0');
    if (*pcVar2 == DAT_006ec184) {
      pcVar2 = pcVar3 + -2;
    }
    do {
      cVar1 = *param_1;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x679ffc FUN_00679ffc

undefined4 FUN_00679ffc(double *param_1)

{
  if (0.0 <= *param_1) {
    return 1;
  }
  return 0;
}


// ==== 0x67a016 __fassign

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (flag != 0) {
    FUN_0068170f(&local_c);
    *(undefined4 *)argument = local_c;
    *(undefined4 *)(argument + 4) = local_8;
    return;
  }
  FUN_00681752(&flag,number);
  *(int *)argument = flag;
  return;
}


// ==== 0x67a054 __shift

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __shift(void)

{
  char *in_EAX;
  size_t sVar1;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    sVar1 = _strlen(in_EAX);
    _memmove(in_EAX + unaff_EDI,in_EAX,sVar1 + 1);
  }
  return;
}


// ==== 0x67a071 __cftoe2

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cftoe2(int param_1,int param_2,char param_3)

{
  int *in_EAX;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *unaff_EBX;
  
  if (param_3 != '\0') {
    __shift();
  }
  if (*in_EAX == 0x2d) {
    *unaff_EBX = 0x2d;
    unaff_EBX = unaff_EBX + 1;
  }
  puVar1 = unaff_EBX;
  if (0 < param_1) {
    puVar1 = unaff_EBX + 1;
    *unaff_EBX = *puVar1;
    *puVar1 = DAT_006ec184;
  }
  puVar1 = (undefined1 *)_strcpy(puVar1 + param_1 + (uint)(param_3 == '\0'),"e+000");
  if (param_2 != 0) {
    *puVar1 = 0x45;
  }
  if (*(char *)in_EAX[3] != '0') {
    iVar2 = in_EAX[1] + -1;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      puVar1[1] = 0x2d;
    }
    if (99 < iVar2) {
      iVar3 = iVar2 / 100;
      iVar2 = iVar2 % 100;
      puVar1[2] = puVar1[2] + (char)iVar3;
    }
    if (9 < iVar2) {
      iVar3 = iVar2 / 10;
      iVar2 = iVar2 % 10;
      puVar1[3] = puVar1[3] + (char)iVar3;
    }
    puVar1[4] = puVar1[4] + (char)iVar2;
  }
  return;
}


// ==== 0x67a11f __cftoe

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cftoe(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint unaff_retaddr;
  undefined1 local_30 [24];
  int local_18 [4];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  __fltout2(*param_1,param_1[1],local_18,local_30);
  __fptostr((uint)(0 < param_3) + param_2 + (uint)(local_18[0] == 0x2d),param_3 + 1,local_18);
  __cftoe2(param_3,param_4,0);
  return param_2;
}


// ==== 0x67a193 FUN_0067a193

undefined1 * FUN_0067a193(undefined1 *param_1,size_t param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  undefined1 *puVar3;
  size_t sVar4;
  
  iVar1 = in_EAX[1];
  if ((param_3 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *in_EAX;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = 0x30;
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = 0;
  }
  puVar3 = param_1;
  if (*in_EAX == 0x2d) {
    *param_1 = 0x2d;
    puVar3 = param_1 + 1;
  }
  if (in_EAX[1] < 1) {
    __shift();
    *puVar3 = 0x30;
    puVar3 = puVar3 + 1;
  }
  else {
    puVar3 = puVar3 + in_EAX[1];
  }
  if (0 < (int)param_2) {
    __shift();
    *puVar3 = DAT_006ec184;
    if (in_EAX[1] < 0) {
      sVar4 = -in_EAX[1];
      if ((param_3 != '\0') || ((int)sVar4 <= (int)param_2)) {
        param_2 = sVar4;
      }
      __shift();
      _memset(puVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}


// ==== 0x67a22f __cftof

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cftof(undefined4 *param_1,int param_2,int param_3)

{
  uint unaff_retaddr;
  undefined1 local_30 [24];
  int local_18;
  int local_14;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  __fltout2(*param_1,param_1[1],&local_18,local_30);
  __fptostr((uint)(local_18 == 0x2d) + param_2,local_14 + param_3,&local_18);
  FUN_0067a193(param_2,param_3,0);
  return param_2;
}


// ==== 0x67a297 __cftog

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cftog(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint unaff_retaddr;
  undefined1 local_30 [24];
  int local_18;
  int local_14;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  __fltout2(*param_1,param_1[1],&local_18,local_30);
  iVar2 = local_14 + -1;
  pcVar1 = (char *)((uint)(local_18 == 0x2d) + param_2);
  __fptostr(pcVar1,param_3,&local_18);
  local_14 = local_14 + -1;
  if ((local_14 < -4) || (param_3 <= local_14)) {
    __cftoe2(param_3,param_4,1);
  }
  else {
    if (iVar2 < local_14) {
      do {
        pcVar3 = pcVar1;
        pcVar1 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_0067a193(param_2,param_3,1);
  }
  return;
}


// ==== 0x67a337 __cfltcvt

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t eVar1;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    eVar1 = __cftoe(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      eVar1 = __cftof(arg,buffer,format);
      return eVar1;
    }
    eVar1 = __cftog(arg,buffer,format,precision);
  }
  return eVar1;
}


// ==== 0x67a388 __ms_p5_test_fdiv

/* WARNING: Removing unreachable block (ram,0x0067a3bf) */
/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 2003 Release */

undefined4 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== 0x67a3c8 __ms_p5_mp_test_fdiv

/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 2003 Release */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  __ms_p5_test_fdiv();
  return;
}


// ==== 0x67a400 __trandisp1

/* Library Function - Single Match
    __trandisp1
   
   Library: Visual Studio */

void __fastcall __trandisp1(undefined4 param_1,int param_2)

{
  float10 fVar1;
  byte bVar2;
  undefined2 uVar3;
  int unaff_EBP;
  float10 in_ST0;
  
  if (*(char *)(param_2 + 0xe) == '\x05') {
    uVar3 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar3 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar3;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = param_2;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  bVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x0067a465. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)(&DAT_006ebcec)[(byte)((bVar2 & 7) << 1 | (char)bVar2 < '\0')] + 0x10
              ))();
  return;
}


// ==== 0x67a467 __trandisp2

/* Library Function - Single Match
    __trandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __fastcall __trandisp2(undefined4 param_1,int param_2)

{
  float10 fVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  int unaff_EBP;
  float10 in_ST0;
  float10 in_ST1;
  
  if (*(char *)(param_2 + 0xe) == '\x05') {
    uVar4 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar4 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar4;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = param_2;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST1) << 8 | (ushort)(in_ST1 < fVar1) << 9 | (ushort)(in_ST1 != fVar1) << 10 |
       (ushort)(in_ST1 == fVar1) << 0xe;
  bVar3 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  cVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x0067a4f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)((&DAT_006ebcec)[(byte)(cVar2 << 1 | cVar2 < '\0') & 0xf] |
                               (&DAT_006ebcec)[(byte)((bVar3 & 7) << 1 | (char)bVar3 < '\0')] << 2)
              + 0x10))();
  return;
}


// ==== 0x67a4fc FUN_0067a4fc

void FUN_0067a4fc(void)

{
  return;
}


// ==== 0x67a504 FUN_0067a504

float10 FUN_0067a504(void)

{
  return (float10)0;
}


// ==== 0x67a50d FUN_0067a50d

float10 FUN_0067a50d(void)

{
  return (float10)1;
}


// ==== 0x67a512 FUN_0067a512

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0067a512(void)

{
  int unaff_EBP;
  unkbyte10 in_ST0;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
    return *(float10 *)(unaff_EBP + -0x9e);
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
  return *(float10 *)(unaff_EBP + -0x9e) + (float10)_DAT_006ebce4;
}


// ==== 0x67a53d FUN_0067a53d

float10 FUN_0067a53d(void)

{
  int unaff_EBP;
  float10 in_ST0;
  unkbyte10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) == 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
  }
  return *(float10 *)(unaff_EBP + -0x9e) + in_ST0;
}


// ==== 0x67a53f FUN_0067a53f

float10 FUN_0067a53f(void)

{
  int unaff_EBP;
  unkbyte10 in_ST0;
  float10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) == 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
  }
  return *(float10 *)(unaff_EBP + -0x9e) + in_ST1;
}


// ==== 0x67a567 FUN_0067a567

float10 FUN_0067a567(void)

{
  float10 fVar1;
  int unaff_EBP;
  unkbyte10 in_ST0;
  float10 fVar2;
  float10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  fVar1 = *(float10 *)(unaff_EBP + -0x9e);
  fVar2 = fVar1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(float10 *)(unaff_EBP + -0x9e) = in_ST1;
    fVar2 = *(float10 *)(unaff_EBP + -0x9e);
    in_ST1 = fVar1;
    if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
      *(undefined1 *)(unaff_EBP + -0x90) = 7;
      goto LAB_0067a5a3;
    }
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
LAB_0067a5a3:
  return fVar2 + in_ST1;
}


// ==== 0x67a5a6 FUN_0067a5a6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

unkbyte10 FUN_0067a5a6(void)

{
  int unaff_EBP;
  unkbyte10 Var1;
  
  Var1 = _DAT_006ebcd0;
  if (*(char *)(unaff_EBP + -0x90) < '\x01') {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  return Var1;
}


// ==== 0x67a5d0 FUN_0067a5d0

float10 __fastcall
FUN_0067a5d0(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float10 in_ST0;
  undefined1 local_24 [8];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  double dStack_c;
  
  local_14 = param_7;
  local_10 = param_8;
  dStack_c = (double)in_ST0;
  uStack_1c = param_5;
  uStack_18 = param_6;
  FUN_00681941(param_2,local_24,&param_3);
  return (float10)dStack_c;
}


// ==== 0x67a5e7 __startOneArgErrorHandling

/* Library Function - Single Match
    __startOneArgErrorHandling
   
   Library: Visual Studio */

float10 __fastcall
__startOneArgErrorHandling
          (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  float10 in_ST0;
  undefined1 local_24 [8];
  undefined4 local_1c;
  undefined4 local_18;
  double local_c;
  
  local_c = (double)in_ST0;
  local_1c = param_5;
  local_18 = param_6;
  FUN_00681941(param_2,local_24,&param_3);
  return (float10)local_c;
}


// ==== 0x67a630 FUN_0067a630

unkbyte10 FUN_0067a630(void)

{
  float10 in_ST0;
  float10 fVar1;
  unkbyte10 Var2;
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  Var2 = fscale((float10)1 + fVar1,ROUND(in_ST0));
  return Var2;
}


// ==== 0x67a645 FUN_0067a645

void FUN_0067a645(void)

{
  return;
}


// ==== 0x67a65c FUN_0067a65c

undefined4 FUN_0067a65c(void)

{
  uint in_EAX;
  
  if ((in_EAX & 0x80000) != 0) {
    return 7;
  }
  return 1;
}


// ==== 0x67a675 __fload_withFB

/* Library Function - Single Match
    __fload_withFB
   
   Library: Visual Studio */

uint __fastcall __fload_withFB(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 4) & 0x7ff00000;
  if (uVar1 != 0x7ff00000) {
    return uVar1;
  }
  return *(uint *)(param_2 + 4);
}


// ==== 0x67a6b8 FUN_0067a6b8

uint FUN_0067a6b8(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}


// ==== 0x67a6ce FUN_0067a6ce

void FUN_0067a6ce(void)

{
  return;
}


// ==== 0x67a6db __math_exit

/* Library Function - Single Match
    __math_exit
   
   Library: Visual Studio */

void __math_exit(void)

{
  ushort in_FPUStatusWord;
  ushort unaff_retaddr;
  
  if (((unaff_retaddr != 0x27f) && ((unaff_retaddr & 0x20) != 0)) &&
     ((in_FPUStatusWord & 0x20) != 0)) {
    __startOneArgErrorHandling();
    return;
  }
  return;
}


// ==== 0x67a719 FUN_0067a719

void __fastcall FUN_0067a719(undefined4 param_1,int param_2)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)1536.0);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)-1536.0);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_0067a5d0();
    return;
  }
  __startOneArgErrorHandling();
  return;
}


// ==== 0x67a7bc __set_exp

/* Library Function - Single Match
    __set_exp
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

float10 __set_exp(undefined8 param_1,short param_2)

{
  undefined8 local_c;
  
  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(undefined6)param_1);
  return (float10)local_c;
}


// ==== 0x67a7e6 __sptype

/* Library Function - Single Match
    __sptype
   
   Library: Visual Studio 2003 Release */

undefined4 __sptype(int param_1,uint param_2)

{
  undefined4 uStack_8;
  
  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    uStack_8 = 3;
  }
  else {
    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {
      return 0;
    }
    uStack_8 = 4;
  }
  return uStack_8;
}


// ==== 0x67a841 FUN_0067a841

float10 __thiscall FUN_0067a841(undefined4 param_1,uint param_2,uint param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int extraout_EDX;
  float10 fVar3;
  
  if ((double)CONCAT17(param_3._3_1_,CONCAT16(param_3._2_1_,CONCAT24((ushort)param_3,param_2))) ==
      0.0) {
    fVar3 = (float10)0;
    iVar2 = 0;
  }
  else if (((param_3 & 0x7ff00000) == 0) && (((param_3 & 0xfffff) != 0 || (param_2 != 0)))) {
    if (0.0 <= (double)CONCAT17(param_3._3_1_,
                                CONCAT16(param_3._2_1_,CONCAT24((ushort)param_3,param_2)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    while ((param_3._2_1_ & 0x10) == 0) {
      iVar2 = CONCAT13(param_3._3_1_,CONCAT12(param_3._2_1_,(ushort)param_3)) << 1;
      param_3._0_2_ = (ushort)iVar2;
      param_3._2_1_ = (byte)((uint)iVar2 >> 0x10);
      param_3._3_1_ = (byte)((uint)iVar2 >> 0x18);
      if ((param_2 & 0x80000000) != 0) {
        param_3._0_2_ = (ushort)param_3 | 1;
      }
      param_2 = param_2 << 1;
    }
    if (bVar1) {
      param_3._3_1_ = param_3._3_1_ | 0x80;
    }
    fVar3 = (float10)__set_exp(CONCAT17(param_3._3_1_,
                                        CONCAT16(param_3._2_1_,CONCAT24((ushort)param_3,param_2))) &
                               0xffefffffffffffff,0,param_1,param_1);
    iVar2 = extraout_EDX;
  }
  else {
    fVar3 = (float10)__set_exp(CONCAT17(param_3._3_1_,
                                        CONCAT16(param_3._2_1_,CONCAT24((ushort)param_3,param_2))),0
                               ,param_1,param_1);
    iVar2 = ((param_3 >> 0x10 & 0x7ff0) >> 4) - 0x3fe;
  }
  *param_4 = iVar2;
  return (float10)(double)fVar3;
}


// ==== 0x67a8fb __raise_exc

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void __raise_exc(uint *param_1,uint *param_2,uint param_3,int param_4,undefined8 *param_5,
                undefined8 *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = param_3;
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    param_1[1] = param_1[1] | 1;
    param_3 = 0xc000008f;
  }
  if ((uVar4 & 2) != 0) {
    param_1[1] = param_1[1] | 2;
    param_3 = 0xc0000093;
  }
  if ((uVar4 & 1) != 0) {
    param_1[1] = param_1[1] | 4;
    param_3 = 0xc0000091;
  }
  if ((uVar4 & 4) != 0) {
    param_1[1] = param_1[1] | 8;
    param_3 = 0xc000008e;
  }
  if ((uVar4 & 8) != 0) {
    param_1[1] = param_1[1] | 0x10;
    param_3 = 0xc0000090;
  }
  param_1[2] = param_1[2] ^ (~(*param_2 << 4) ^ param_1[2]) & 0x10;
  param_1[2] = param_1[2] ^ (~(*param_2 << 1) ^ param_1[2]) & 8;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 1) ^ param_1[2]) & 4;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 3) ^ param_1[2]) & 2;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 5) ^ param_1[2]) & 1;
  bVar3 = FUN_0067afc6();
  puVar2 = param_6;
  if ((bVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((bVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((bVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((bVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((bVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar4 = *puVar1 & 0xc00;
  if (uVar4 == 0) {
    *param_1 = *param_1 & 0xfffffffc;
  }
  else {
    if (uVar4 == 0x400) {
      uVar4 = *param_1 & 0xfffffffd | 1;
    }
    else {
      if (uVar4 != 0x800) {
        if (uVar4 == 0xc00) {
          *param_1 = *param_1 | 3;
        }
        goto LAB_0067aa58;
      }
      uVar4 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar4;
  }
LAB_0067aa58:
  uVar4 = *puVar1 & 0x300;
  if (uVar4 == 0) {
    uVar4 = *param_1 & 0xffffffeb | 8;
LAB_0067aa8e:
    *param_1 = uVar4;
  }
  else {
    if (uVar4 == 0x200) {
      uVar4 = *param_1 & 0xffffffe7 | 4;
      goto LAB_0067aa8e;
    }
    if (uVar4 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = *param_1 ^ (param_4 << 5 ^ *param_1) & 0x1ffe0;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 4) = *param_5;
  param_1[0x18] = param_1[0x18] | 1;
  param_1[0x18] = param_1[0x18] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 0x14) = *param_6;
  FUN_0067afd3();
  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);
  if ((param_1[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((param_1[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((param_1[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((param_1[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((param_1[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  uVar4 = *param_1 & 3;
  if (uVar4 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  else {
    if (uVar4 == 1) {
      uVar4 = *puVar1 & 0xfffff7ff | 0x400;
    }
    else {
      if (uVar4 != 2) {
        if (uVar4 == 3) {
          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;
        }
        goto LAB_0067ab67;
      }
      uVar4 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar4;
  }
LAB_0067ab67:
  uVar4 = *param_1 >> 2 & 7;
  if (uVar4 == 0) {
    uVar4 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar4 != 1) {
      if (uVar4 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_0067ab96;
    }
    uVar4 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar4;
LAB_0067ab96:
  *puVar2 = *(undefined8 *)(param_1 + 0x14);
  return;
}


// ==== 0x67aba0 FUN_0067aba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0067aba0(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  float10 fVar5;
  undefined8 local_14;
  int local_c;
  uint local_8;
  
  uVar3 = param_1 & 0x1f;
  bVar2 = true;
  local_8 = uVar3;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_0067b005(1);
    uVar3 = param_1 & 0x17;
    goto LAB_0067ada0;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_0067b005(4);
    uVar3 = param_1 & 0x1b;
    goto LAB_0067ada0;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar4 = (param_1 & 0x10) != 0;
      if (*param_2 != 0.0) {
        fVar5 = (float10)FUN_0067a841(*param_2,&local_c);
        dVar1 = (double)fVar5;
        local_c = local_c + -0x600;
        if (local_c < -0x432) {
          local_14 = dVar1 * 0.0;
          bVar4 = bVar2;
        }
        else {
          local_14 = (double)((ulonglong)dVar1 & 0xfffffffffffff | 0x10000000000000);
          if (local_c < -0x3fd) {
            local_c = -0x3fd - local_c;
            do {
              if ((((ulonglong)local_14 & 1) != 0) && (!bVar4)) {
                bVar4 = bVar2;
              }
              uVar3 = (uint)local_14 >> 1;
              if (((ulonglong)local_14 & 0x100000000) != 0) {
                local_14._3_1_ = (byte)((ulonglong)local_14 >> 0x18) >> 1;
                local_14._0_3_ = (undefined3)uVar3;
                local_14._0_4_ = CONCAT13(local_14._3_1_,(undefined3)local_14) | 0x80000000;
                uVar3 = (uint)local_14;
              }
              local_14._0_4_ = uVar3;
              local_14 = (double)CONCAT44(local_14._4_4_ >> 1,(uint)local_14);
              local_c = local_c + -1;
            } while (local_c != 0);
          }
          if (dVar1 < 0.0) {
            local_14 = -local_14;
          }
        }
        *param_2 = local_14;
        bVar2 = bVar4;
      }
      if (bVar2) {
        FUN_0067b005(0x10);
      }
      uVar3 = local_8 & 0xfffffffd;
      local_8 = uVar3;
    }
    goto LAB_0067ada0;
  }
  FUN_0067b005(8);
  uVar3 = param_3 & 0xc00;
  dVar1 = _DAT_006ebd00;
  if (uVar3 == 0) {
    if (*param_2 <= 0.0) {
      dVar1 = -_DAT_006ebd00;
    }
LAB_0067acbe:
    *param_2 = dVar1;
  }
  else {
    if (uVar3 == 0x400) {
      dVar1 = _DAT_006ebd10;
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_006ebd00;
      }
      goto LAB_0067acbe;
    }
    if (uVar3 == 0x800) {
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_006ebd10;
      }
      goto LAB_0067acbe;
    }
    if (uVar3 == 0xc00) {
      dVar1 = _DAT_006ebd10;
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_006ebd10;
      }
      goto LAB_0067acbe;
    }
  }
  uVar3 = param_1 & 0x1e;
LAB_0067ada0:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_0067b005(0x20);
    uVar3 = uVar3 & 0xffffffef;
  }
  return uVar3 == 0;
}


// ==== 0x67adc2 FID_conflict:__set_errno_from_matherr

/* Library Function - Multiple Matches With Different Base Names
    __set_errno
    __set_errno_from_matherr
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

errno_t __cdecl FID_conflict___set_errno_from_matherr(int _Value)

{
  undefined4 *puVar1;
  
  if (_Value == 1) {
    _Value = __errno();
    *(undefined4 *)_Value = 0x21;
  }
  else if ((1 < _Value) && (_Value < 4)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x22;
    return (errno_t)puVar1;
  }
  return _Value;
}


// ==== 0x67adea __errcode

/* Library Function - Single Match
    __errcode
   
   Library: Visual Studio 2003 Release */

int __errcode(byte param_1)

{
  undefined4 uStack_4;
  
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 8) != 0) {
      return 1;
    }
    if ((param_1 & 4) == 0) {
      if ((param_1 & 1) == 0) {
        return (param_1 & 2) << 1;
      }
      uStack_4 = 3;
    }
    else {
      uStack_4 = 2;
    }
  }
  else {
    uStack_4 = 5;
  }
  return uStack_4;
}


// ==== 0x67ae17 __umatherr

/* Library Function - Single Match
    __umatherr
   
   Library: Visual Studio 2003 Release */

float10 __umatherr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  iVar1 = 0;
  do {
    if ((&DAT_006ebd28)[iVar1 * 2] == param_2) {
      local_20 = *(int *)(iVar1 * 8 + 0x6ebd2c);
      goto LAB_0067ae33;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1d);
  local_20 = 0;
LAB_0067ae33:
  if (local_20 != 0) {
    local_1c = param_3;
    local_18 = param_4;
    local_14 = param_5;
    local_10 = param_6;
    local_c = param_7;
    local_24 = param_1;
    uStack_8 = param_8;
    __ctrlfp(param_9,0xffff);
    iVar1 = FUN_0067ef25(&local_24);
    if (iVar1 == 0) {
      FID_conflict___set_errno_from_matherr(param_1);
    }
    return (float10)(double)CONCAT44(uStack_8,local_c);
  }
  __ctrlfp(param_9,0xffff);
  FID_conflict___set_errno_from_matherr(param_1);
  return (float10)(double)CONCAT44(param_8,param_7);
}


// ==== 0x67aeb5 __handle_qnan1

/* Library Function - Single Match
    __handle_qnan1
   
   Library: Visual Studio 2003 Release */

float10 __handle_qnan1(undefined4 param_1,double param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_006ec230 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,0,param_2,param_3);
    return fVar2;
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0x21;
  __ctrlfp();
  return (float10)param_2;
}


// ==== 0x67af08 FUN_0067af08

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

float10 FUN_0067af08(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_0067aba0(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    __raise_exc();
  }
  iVar1 = __errcode(param_1);
  if ((DAT_006ec230 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)__umatherr(iVar1,param_2,param_3,0,param_4,param_5);
  }
  else {
    FID_conflict___set_errno_from_matherr(iVar1);
    __ctrlfp();
    fVar2 = (float10)param_4;
  }
  return fVar2;
}


// ==== 0x67afc6 FUN_0067afc6

int FUN_0067afc6(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== 0x67afd3 FUN_0067afd3

int FUN_0067afd3(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== 0x67afe1 __ctrlfp

/* Library Function - Single Match
    __ctrlfp
   
   Library: Visual Studio 2003 Release */

int __ctrlfp(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}


// ==== 0x67b005 FUN_0067b005

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0067b005(void)

{
  return;
}


// ==== 0x67b05e TypeMatch

/* Library Function - Single Match
    int __cdecl TypeMatch(struct _s_HandlerType const *,struct _s_CatchableType const *,struct
   _s_ThrowInfo const *)
   
   Library: Visual Studio 2003 Release */

int __cdecl TypeMatch(_s_HandlerType *param_1,_s_CatchableType *param_2,_s_ThrowInfo *param_3)

{
  int iVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  iVar1 = *(int *)(unaff_ESI + 4);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 8) != '\0')) {
    if ((iVar1 != *(int *)(unaff_EDI + 4)) &&
       (iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(unaff_EDI + 4) + 8)), iVar1 != 0)) {
      return 0;
    }
    if (((((*unaff_EDI & 2) != 0) && ((*unaff_ESI & 8) == 0)) ||
        (((param_1->adjectives & 1) != 0 && ((*unaff_ESI & 1) == 0)))) ||
       (((param_1->adjectives & 2) != 0 && ((*unaff_ESI & 2) == 0)))) {
      return 0;
    }
  }
  return 1;
}


// ==== 0x67b0ad FUN_0067b0ad

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */

undefined4 FUN_0067b0ad(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  _ptiddata p_Var2;
  
  if (*(int *)*in_EAX != -0x1f928c9d) {
    return 0;
  }
  p_Var2 = __getptd();
  p_Var2->_translator = (void *)0x0;
  p_Var2 = __getptd();
  if (p_Var2->ptlocinfo != (pthreadlocinfo)0x0) {
    p_Var2 = __getptd();
    (*(code *)p_Var2->ptlocinfo)();
  }
  uVar1 = FUN_0067fc40();
  return uVar1;
}


// ==== 0x67b0cb ___FrameUnwindToState

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 2003 Release */

void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  _ptiddata p_Var1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  p_Var1 = __getptd();
  p_Var1->_translator = (void *)((int)p_Var1->_translator + 1);
  while (iVar4 != param_4) {
    if ((iVar4 < 0) || (*(int *)(param_3 + 4) <= iVar4)) {
      _inconsistency();
    }
    iVar2 = iVar4 * 8;
    piVar3 = (int *)(*(int *)(param_3 + 8) + iVar2);
    iVar4 = *piVar3;
    if (piVar3[1] != 0) {
      *(int *)(param_1 + 8) = iVar4;
      __CallSettingFrame_12(*(undefined4 *)(*(int *)(param_3 + 8) + 4 + iVar2),param_1,0x103);
    }
  }
  FUN_0067b17e();
  if (iVar4 != param_4) {
    _inconsistency();
  }
  *(int *)(param_1 + 8) = iVar4;
  return;
}


// ==== 0x67b13e FUN_0067b13e

void FUN_0067b13e(void)

{
  FUN_0067b0ad();
  return;
}


// ==== 0x67b147 FUN_0067b147

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067b147(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBP;
  int iVar6;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 0x10);
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar6 = *(int *)(unaff_EBP + -0x20);
  while (*(int *)(unaff_EBP + -0x1c) = iVar6, iVar6 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar6 < 0) || (*(int *)(iVar2 + 4) <= iVar6)) {
      *(undefined4 *)(iVar1 + -4) = 0x67b107;
      _inconsistency();
    }
    iVar4 = iVar6 * 8;
    piVar5 = (int *)(*(int *)(iVar2 + 8) + iVar4);
    iVar6 = *piVar5;
    *(int *)(unaff_EBP + -0x20) = iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (piVar5[1] != 0) {
      *(int *)(iVar3 + 8) = iVar6;
      *(undefined4 *)(iVar1 + -4) = 0x103;
      *(int *)(iVar1 + -8) = iVar3;
      *(undefined4 *)(iVar1 + -0xc) = *(undefined4 *)(*(int *)(iVar2 + 8) + 4 + iVar4);
      *(undefined4 *)(iVar1 + -0x10) = 0x67b138;
      __CallSettingFrame_12();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 0x67b165;
  FUN_0067b17e();
  if (iVar6 != *(int *)(unaff_EBP + 0x14)) {
    *(undefined4 *)(iVar1 + -4) = 0x67b16f;
    _inconsistency();
  }
  *(int *)(iVar3 + 8) = iVar6;
  *(undefined4 *)(iVar1 + -4) = 0x67b177;
  return;
}


// ==== 0x67b178 FUN_0067b178

void FUN_0067b178(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < (int)p_Var1->_translator) {
    p_Var1 = __getptd();
    p_Var1->_translator = (void *)((int)p_Var1->_translator + -1);
  }
  return;
}


// ==== 0x67b17e FUN_0067b17e

void FUN_0067b17e(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < (int)p_Var1->_translator) {
    p_Var1 = __getptd();
    p_Var1->_translator = (void *)((int)p_Var1->_translator + -1);
  }
  return;
}


// ==== 0x67b199 ___DestructExceptionObject

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2003 Release */

void ___DestructExceptionObject(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 4), iVar1 != 0)) {
    FID_conflict__CallMemberFunction1(*(undefined4 *)(param_1 + 0x18),iVar1);
  }
  return;
}


// ==== 0x67b1cd FUN_0067b1cd

bool FUN_0067b1cd(void)

{
  int unaff_EBP;
  
  return *(char *)(unaff_EBP + 0xc) != '\0';
}


// ==== 0x67b1d6 FUN_0067b1d6

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067b1d6(void)

{
  pthreadlocinfo ptVar1;
  int iVar2;
  int iVar3;
  _ptiddata p_Var4;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar2 + -4) = 8;
  *(undefined **)(iVar2 + -8) = &DAT_006ac6f0;
  *(undefined4 *)(iVar2 + -0xc) = 0x6794f0;
  iVar3 = -*(int *)(iVar2 + -4);
  *(int *)(iVar2 + -4) = unaff_EBP;
  *(undefined4 *)(iVar2 + iVar3 + -0x20) = unaff_EDI;
  *(undefined4 *)(iVar2 + iVar3 + -0x1c) = unaff_ESI;
  *(undefined4 *)(iVar2 + iVar3 + -0x18) = unaff_EBX;
  *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x6794f5;
  p_Var4 = __getptd();
  if (p_Var4->ptlocinfo != (pthreadlocinfo)0x0) {
    *(undefined4 *)(iVar2 + -8) = 0;
    *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x679504;
    p_Var4 = __getptd();
    ptVar1 = p_Var4->ptlocinfo;
    *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x679507;
    (*(code *)ptVar1)();
    *(undefined4 *)(iVar2 + -8) = 0xffffffff;
  }
  FUN_0067fc40();
  return;
}


// ==== 0x67b1de FUN_0067b1de

int __fastcall FUN_0067b1de(int *param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *param_1 + in_EAX;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + in_EAX) + param_1[2]) + iVar1;
  }
  return iVar2;
}


// ==== 0x67b1fb FUN_0067b1fb

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_0067b1fb(undefined4 param_1,void *param_2,int param_3,void *param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  _ptiddata p_Var1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006ac868;
  uStack_c = 0x67b207;
  local_24 = 0;
  local_28 = *(undefined4 *)(param_3 + -4);
  local_20 = param_1;
  FUN_006731bd(local_30,*(undefined4 *)((int)param_2 + 0x18));
  __getptd();
  __getptd();
  p_Var1 = __getptd();
  p_Var1->_terminate = param_2;
  p_Var1 = __getptd();
  p_Var1->_unexpected = param_4;
  local_8 = (undefined *)0x1;
  local_20 = FUN_00673252(param_3,param_5,param_1,param_6,param_7);
  local_8 = (undefined *)0xffffffff;
  FUN_0067b33e();
  return local_20;
}


// ==== 0x67b280 FUN_0067b280

undefined4 FUN_0067b280(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x3c) = **(undefined4 **)(unaff_EBP + -0x14);
  if ((((**(int **)(unaff_EBP + -0x3c) != -0x1f928c9d) ||
       (*(int *)(*(int *)(unaff_EBP + -0x3c) + 0x10) != 3)) ||
      (*(int *)(*(int *)(unaff_EBP + -0x3c) + 0x14) != 0x19930520)) ||
     (iVar1 = *(int *)(*(int *)(unaff_EBP + -0x3c) + 0x1c), *(undefined4 *)(unaff_EBP + -0x40) = 1,
     iVar1 != 0)) {
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
  }
  return *(undefined4 *)(unaff_EBP + -0x40);
}


// ==== 0x67b2c3 FUN_0067b2c3

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0067b2c3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  iVar3 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar3 + 8);
  iVar4 = *(int *)(unaff_EBP + 0xc);
  iVar7 = *(int *)(iVar4 + 8);
  *(int *)(unaff_EBP + -0x48) = iVar7;
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar3 + 0x10);
  uVar8 = 0;
  do {
    *(uint *)(unaff_EBP + -0x50) = uVar8;
    if (*(uint *)(iVar3 + 0xc) <= uVar8) {
LAB_0067b30c:
      *(int *)(iVar2 + -4) = iVar7;
      *(int *)(iVar2 + -8) = iVar3;
      *(undefined4 *)(iVar2 + -0xc) = 0;
      *(int *)(iVar2 + -0x10) = iVar4;
      *(undefined4 *)(iVar2 + -0x14) = 0x67b317;
      ___FrameUnwindToState();
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(iVar2 + -4) = 0x67b32c;
      FUN_0067b33e();
      uVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
      *(undefined4 *)(iVar2 + -4) = 0x67b334;
      return uVar6;
    }
    iVar1 = *(int *)(unaff_EBP + -0x4c) + uVar8 * 0x14;
    iVar5 = *(int *)(iVar1 + 4);
    if ((iVar5 < iVar7) && (iVar7 <= *(int *)(iVar1 + 8))) {
      iVar5 = iVar5 + 1;
      *(int *)(unaff_EBP + -0x48) = iVar5;
      iVar7 = *(int *)(*(int *)(unaff_EBP + -0x44) + iVar5 * 8);
      *(int *)(unaff_EBP + -0x48) = iVar7;
      goto LAB_0067b30c;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}


// ==== 0x67b300 FUN_0067b300

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_0067b300(void)

{
  int in_EAX;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x48) = in_EAX;
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + in_EAX * 8);
  ___FrameUnwindToState();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0067b33e();
  return *(undefined4 *)(unaff_EBP + -0x1c);
}


// ==== 0x67b338 FUN_0067b338

void FUN_0067b338(void)

{
  int *piVar1;
  _ptiddata p_Var2;
  int iVar3;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  _FindAndUnlinkFrame(*(FrameInfo **)(unaff_EBP + -0x30));
  p_Var2 = __getptd();
  p_Var2->_terminate = *(void **)(unaff_EBP + -0x34);
  p_Var2 = __getptd();
  p_Var2->_unexpected = *(void **)(unaff_EBP + -0x38);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x20) == 0 && (*(int *)(unaff_EBP + -0x1c) != 0)))) {
    iVar3 = FUN_006731e5(piVar1[6]);
    if (iVar3 != 0) {
      iVar3 = __abnormal_termination();
      ___DestructExceptionObject(piVar1,iVar3);
    }
  }
  return;
}


// ==== 0x67b33e FUN_0067b33e

void FUN_0067b33e(void)

{
  _ptiddata p_Var1;
  int iVar2;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  _FindAndUnlinkFrame(*(FrameInfo **)(unaff_EBP + -0x30));
  p_Var1 = __getptd();
  p_Var1->_terminate = *(void **)(unaff_EBP + -0x34);
  p_Var1 = __getptd();
  p_Var1->_unexpected = *(void **)(unaff_EBP + -0x38);
  if ((((*unaff_ESI == -0x1f928c9d) && (unaff_ESI[4] == 3)) && (unaff_ESI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x20) == 0 && (*(int *)(unaff_EBP + -0x1c) != 0)))) {
    iVar2 = FUN_006731e5(unaff_ESI[6]);
    if (iVar2 != 0) {
      __abnormal_termination();
      ___DestructExceptionObject();
    }
  }
  return;
}


// ==== 0x67b3a2 BuildCatchObject

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __cdecl BuildCatchObject(struct EHExceptionRecord *,void *,struct _s_HandlerType const
   *,struct _s_CatchableType const *)
   
   Library: Visual Studio 2003 Release */

void __cdecl
BuildCatchObject(EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
                _s_CatchableType *param_4)

{
  int iVar1;
  void *_Src;
  undefined4 uVar2;
  byte *in_ECX;
  int *in_EDX;
  size_t _Size;
  
  if (*(int *)((int)param_2 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)((int)param_2 + 4) + 8) == '\0') {
    return;
  }
  if ((*(int *)((int)param_2 + 8) == 0) && ((*(byte *)((int)param_2 + 3) & 0x80) == 0)) {
    return;
  }
  if (-1 < (int)*(uint *)param_2) {
    in_EDX = (int *)(*(int *)((int)param_2 + 8) + 0xc + (int)in_EDX);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  if ((*(uint *)param_2 & 8) == 0) {
    if ((*in_ECX & 1) == 0) {
      if (*(int *)(in_ECX + 0x18) == 0) {
        iVar1 = FID_conflict__ValidateRead(uVar2,1);
        if ((iVar1 != 0) && (iVar1 = FID_conflict__ValidateRead(in_EDX,1), iVar1 != 0)) {
          _Size = *(size_t *)(in_ECX + 0x14);
          _Src = (void *)FUN_0067b1de();
          _memmove(in_EDX,_Src,_Size);
          return;
        }
      }
      else {
        iVar1 = FID_conflict__ValidateRead(uVar2,1);
        if (((iVar1 != 0) && (iVar1 = FID_conflict__ValidateRead(in_EDX,1), iVar1 != 0)) &&
           (iVar1 = _ValidateExecute(*(_func_int **)(in_ECX + 0x18)), iVar1 != 0)) {
          if ((*in_ECX & 4) != 0) {
            uVar2 = FUN_0067b1de(1);
            FID_conflict__CallMemberFunction1(in_EDX,*(undefined4 *)(in_ECX + 0x18),uVar2);
            return;
          }
          uVar2 = FUN_0067b1de();
          FID_conflict__CallMemberFunction1(in_EDX,*(undefined4 *)(in_ECX + 0x18),uVar2);
          return;
        }
      }
    }
    else {
      iVar1 = FID_conflict__ValidateRead(uVar2,1);
      if ((iVar1 != 0) && (iVar1 = FID_conflict__ValidateRead(in_EDX,1), iVar1 != 0)) {
        _memmove(in_EDX,*(void **)(param_1 + 0x18),*(size_t *)(in_ECX + 0x14));
        if (*(int *)(in_ECX + 0x14) != 4) {
          return;
        }
        if (*in_EDX == 0) {
          return;
        }
        goto LAB_0067b41b;
      }
    }
  }
  else {
    iVar1 = FID_conflict__ValidateRead(uVar2,1);
    if ((iVar1 != 0) && (iVar1 = FID_conflict__ValidateRead(in_EDX,1), iVar1 != 0)) {
      *in_EDX = *(int *)(param_1 + 0x18);
LAB_0067b41b:
      iVar1 = FUN_0067b1de();
      *in_EDX = iVar1;
      return;
    }
  }
  _inconsistency();
  return;
}


// ==== 0x67b512 FUN_0067b512

undefined4 FUN_0067b512(void)

{
  return 1;
}


// ==== 0x67b516 FUN_0067b516

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067b516(void)

{
  pthreadlocinfo ptVar1;
  int iVar2;
  int iVar3;
  _ptiddata p_Var4;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar2 + -4) = 8;
  *(undefined **)(iVar2 + -8) = &DAT_006ac6f0;
  *(undefined4 *)(iVar2 + -0xc) = 0x6794f0;
  iVar3 = -*(int *)(iVar2 + -4);
  *(int *)(iVar2 + -4) = unaff_EBP;
  *(undefined4 *)(iVar2 + iVar3 + -0x20) = unaff_EDI;
  *(undefined4 *)(iVar2 + iVar3 + -0x1c) = unaff_ESI;
  *(undefined4 *)(iVar2 + iVar3 + -0x18) = unaff_EBX;
  *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x6794f5;
  p_Var4 = __getptd();
  if (p_Var4->ptlocinfo != (pthreadlocinfo)0x0) {
    *(undefined4 *)(iVar2 + -8) = 0;
    *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x679504;
    p_Var4 = __getptd();
    ptVar1 = p_Var4->ptlocinfo;
    *(undefined4 *)(iVar2 + iVar3 + -0x24) = 0x679507;
    (*(code *)ptVar1)();
    *(undefined4 *)(iVar2 + -8) = 0xffffffff;
  }
  FUN_0067fc40();
  return;
}


// ==== 0x67b51e CatchIt

/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *,unsigned char)
   
   Library: Visual Studio 2003 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10,uchar param_11)

{
  void *pvVar1;
  int in_ECX;
  void *unaff_EBX;
  _s_HandlerType *unaff_EBP;
  _s_HandlerType *unaff_ESI;
  int unaff_EDI;
  _s_CatchableType *unaff_retaddr;
  
  if (in_ECX != 0) {
    BuildCatchObject(param_1,unaff_EBX,unaff_EBP,unaff_retaddr);
  }
  if (param_6 == (_s_HandlerType *)0x0) {
    param_6 = unaff_ESI;
  }
  _UnwindNestedFrames((EHRegistrationNode *)param_6,param_1);
  ___FrameUnwindToState();
  unaff_ESI->dispCatchObj = *(int *)(unaff_EDI + 4) + 1;
  pvVar1 = (void *)FUN_0067b1fb(param_1);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,(EHRegistrationNode *)unaff_ESI);
  }
  return;
}


// ==== 0x67b585 FUN_0067b585

void FUN_0067b585(EHExceptionRecord *param_1,undefined4 param_2,EHRegistrationNode *param_3,
                 _CONTEXT *param_4,_s_FuncInfo *param_5,int param_6,_s_FuncInfo *param_7,
                 _s_HandlerType *param_8)

{
  TypeDescriptor *pTVar1;
  _ptiddata p_Var2;
  int iVar3;
  _s_TryBlockMapEntry *p_Var4;
  _s_TryBlockMapEntry *unaff_EBX;
  EHRegistrationNode *unaff_ESI;
  int unaff_EDI;
  uint extraout_var;
  uint uVar5;
  uint local_8;
  
  if ((*(int *)param_1 != -0x7ffffffd) &&
     (((p_Var2 = __getptd(), uVar5 = extraout_var, p_Var2->_NLG_dwCode == 0 ||
       (iVar3 = FUN_006732a3(param_1,param_2,param_3,param_4,param_5,param_7,param_8), iVar3 == 0))
      && (p_Var4 = _GetRangeOfTrysToCheck
                             (param_5,(int)param_7,param_6,&local_8,(uint *)&stack0xfffffff4),
         local_8 < uVar5)))) {
    do {
      if (((p_Var4->tryLow <= param_6) && (param_6 <= p_Var4->tryHigh)) &&
         ((pTVar1 = p_Var4->pHandlerArray[p_Var4->nCatches + -1].pType,
          pTVar1 == (TypeDescriptor *)0x0 || ((char)pTVar1[1].hash == '\0')))) {
        CatchIt(param_1,param_3,param_4,param_5,param_7,param_8,(_s_CatchableType *)0x1,unaff_EBX,
                unaff_EDI,unaff_ESI,(uchar)uVar5);
      }
      local_8 = local_8 + 1;
      p_Var4 = p_Var4 + 1;
    } while (local_8 < uVar5);
  }
  return;
}


// ==== 0x67b645 FUN_0067b645

void FUN_0067b645(EHExceptionRecord *param_1,int param_2,EHRegistrationNode *param_3,
                 _CONTEXT *param_4,_s_FuncInfo *param_5,char param_6,_s_FuncInfo *param_7,
                 _s_HandlerType *param_8)

{
  _ptiddata p_Var1;
  int iVar2;
  _s_TryBlockMapEntry *p_Var3;
  EHRegistrationNode *unaff_EBX;
  _s_ThrowInfo *unaff_ESI;
  _s_TryBlockMapEntry *unaff_EDI;
  uchar uVar4;
  uint local_24;
  _s_CatchableType *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  uint local_c;
  _s_TryBlockMapEntry *local_8;
  
  local_1c = *(int *)(param_2 + 8);
  local_20 = (_s_CatchableType *)((uint)local_20 & 0xffffff00);
  if ((local_1c < -1) || (param_5->maxState <= local_1c)) {
    _inconsistency();
  }
  if (*(int *)param_1 == -0x1f928c9d) {
    if (((*(int *)(param_1 + 0x10) == 3) && (*(int *)(param_1 + 0x14) == 0x19930520)) &&
       (*(int *)(param_1 + 0x1c) == 0)) {
      p_Var1 = __getptd();
      if (p_Var1->_terminate == (void *)0x0) {
        return;
      }
      p_Var1 = __getptd();
      param_1 = p_Var1->_terminate;
      p_Var1 = __getptd();
      param_3 = p_Var1->_unexpected;
      local_20 = (_s_CatchableType *)CONCAT31(local_20._1_3_,1);
      iVar2 = FID_conflict__ValidateRead(param_1,1);
      if (iVar2 == 0) {
        _inconsistency();
      }
      if (*(int *)param_1 != -0x1f928c9d) goto LAB_0067b7fc;
      if (((*(int *)(param_1 + 0x10) == 3) && (*(int *)(param_1 + 0x14) == 0x19930520)) &&
         (*(int *)(param_1 + 0x1c) == 0)) {
        _inconsistency();
      }
    }
    iVar2 = local_1c;
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       (*(int *)(param_1 + 0x14) == 0x19930520)) {
      p_Var3 = _GetRangeOfTrysToCheck(param_5,(int)param_7,local_1c,&local_c,&local_24);
      local_8 = p_Var3;
      if (local_c < local_24) {
        do {
          if ((p_Var3->tryLow <= iVar2) && (iVar2 <= p_Var3->tryHigh)) {
            local_8 = p_Var3;
            for (local_18 = p_Var3->nCatches; 0 < local_18; local_18 = local_18 + -1) {
              local_10 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
              for (local_14 = *local_10; local_10 = local_10 + 1, 0 < local_14;
                  local_14 = local_14 + -1) {
                uVar4 = (uchar)*local_10;
                iVar2 = TypeMatch(*(_s_HandlerType **)(param_1 + 0x1c),(_s_CatchableType *)unaff_EDI
                                  ,unaff_ESI);
                p_Var3 = local_8;
                if (iVar2 != 0) {
                  CatchIt(param_1,param_3,param_4,param_5,param_7,param_8,local_20,unaff_EDI,
                          (int)unaff_ESI,unaff_EBX,uVar4);
                  goto LAB_0067b7cf;
                }
              }
            }
          }
LAB_0067b7cf:
          local_c = local_c + 1;
          p_Var3 = p_Var3 + 1;
          iVar2 = local_1c;
          local_8 = p_Var3;
        } while (local_c < local_24);
      }
      if (param_6 == '\0') {
        return;
      }
      ___DestructExceptionObject(param_1,1);
      return;
    }
  }
LAB_0067b7fc:
  if (param_6 == '\0') {
    FUN_0067b585(param_1,param_2,param_3,param_4,param_5,local_1c,param_7,param_8);
    return;
  }
  terminate();
  return;
}


// ==== 0x67b827 ___InternalCxxFrameHandler

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined4
___InternalCxxFrameHandler
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
          int param_6,undefined4 param_7,uint param_8)

{
  undefined4 uVar1;
  
  if ((*param_5 & 0x1fffffff) != 0x19930520) {
    _inconsistency();
  }
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((*param_1 == -0x1f928c9d) && (0x19930520 < (uint)param_1[5])) &&
         (*(code **)(param_1[7] + 8) != (code *)0x0)) {
        uVar1 = (**(code **)(param_1[7] + 8))
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8 & 0xff);
        return uVar1;
      }
      FUN_0067b645(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
  }
  return 1;
}


// ==== 0x67b8d0 __CallSettingFrame@12

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 2003 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}


// ==== 0x67b91c FUN_0067b91c

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067b91c(uint *param_1,int param_2)

{
  uint uVar1;
  INTRNCVT_STATUS IVar2;
  uint uVar3;
  uint unaff_retaddr;
  _LDBL12 local_20;
  _CRT_DOUBLE local_14;
  int local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar3 = 0;
  uVar1 = FUN_00681af5(&local_20,&local_c,param_2,0,0,0,0);
  if ((uVar1 & 4) == 0) {
    IVar2 = FID_conflict___ld12tod(&local_20,&local_14);
    if (((uVar1 & 2) != 0) || (IVar2 == INTRNCVT_OVERFLOW)) {
      uVar3 = 0x80;
    }
    if (((uVar1 & 1) != 0) || (IVar2 == INTRNCVT_UNDERFLOW)) {
      uVar3 = uVar3 | 0x100;
    }
  }
  else {
    uVar3 = 0x200;
    local_14.x._0_4_ = 0;
    local_14.x._4_4_ = 0;
  }
  *param_1 = uVar3;
  param_1[1] = local_c - param_2;
  param_1[4] = local_14.x._0_4_;
  param_1[5] = local_14.x._4_4_;
  return;
}


// ==== 0x67b9b7 FUN_0067b9b7

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067b9b7(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint unaff_retaddr;
  undefined4 local_28;
  undefined **local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (0xa1 < param_4) {
    if (param_4 < 0x3eb) {
      if (param_4 != 0x3ea) {
        if (param_4 == 0xa2) {
          local_28 = 4;
          goto LAB_0067bb6c;
        }
        if (param_4 == 0xa6) {
          local_28 = 3;
          local_24 = (undefined **)0x6ac8f8;
        }
        else {
          if (param_4 != 0xaa) {
            if (param_4 == 0xab) {
              local_24 = (undefined **)&DAT_0069ed58;
              goto LAB_0067bc05;
            }
            if (param_4 == 1000) {
              local_24 = (undefined **)&DAT_0069ed68;
            }
            else {
              if (param_4 != 0x3e9) {
                return;
              }
              local_24 = (undefined **)0x69ed60;
            }
            goto LAB_0067bbfb;
          }
          local_28 = 2;
          local_24 = (undefined **)&DAT_0069ed58;
        }
        goto LAB_0067bb73;
      }
      local_24 = &PTR_DAT_0069edf0;
    }
    else if (param_4 == 0x3eb) {
      local_24 = (undefined **)&DAT_0069ee58;
    }
    else if (param_4 == 0x3ec) {
      local_24 = (undefined **)&DAT_0069ee44;
    }
    else if (param_4 == 0x3ed) {
      local_24 = (undefined **)0x69edcc;
    }
    else {
      if (param_4 == 0x3ee) goto LAB_0067bbd3;
      if (param_4 != 0x3ef) {
        return;
      }
      local_24 = (undefined **)&DAT_0069ed50;
    }
LAB_0067bbfb:
    *param_3 = *param_1;
    goto LAB_0067bc05;
  }
  if (param_4 == 0xa1) {
    local_28 = 3;
LAB_0067bb6c:
    local_24 = (undefined **)&DAT_0069ede8;
    goto LAB_0067bb73;
  }
  if (param_4 < 0x19) {
    if (param_4 == 0x18) {
      local_28 = 3;
      goto LAB_0067ba64;
    }
    if (param_4 == 2) {
      local_28 = 2;
      local_24 = (undefined **)&DAT_0069ed68;
    }
    else {
      if (param_4 == 3) {
        local_24 = (undefined **)&DAT_0069ed68;
LAB_0067bc05:
        local_20 = *param_1;
        local_28 = 1;
        local_18 = *param_2;
        local_10 = *param_3;
        iVar1 = (*(code *)PTR_FUN_006ebe30)(&local_28);
        if (iVar1 == 0) {
          puVar2 = (undefined4 *)__errno();
          *puVar2 = 0x21;
        }
        goto LAB_0067bc38;
      }
      if (param_4 == 8) {
        local_28 = 2;
        local_24 = (undefined **)0x69ed60;
      }
      else {
        if (param_4 == 9) {
          local_24 = (undefined **)0x69ed60;
          goto LAB_0067bc05;
        }
        if (param_4 != 0xe) {
          if (param_4 != 0xf) {
            return;
          }
          local_24 = &PTR_DAT_0069edf0;
          goto LAB_0067bab1;
        }
        local_28 = 3;
        local_24 = &PTR_DAT_0069edf0;
      }
    }
  }
  else {
    if (param_4 == 0x19) {
      local_24 = &PTR_DAT_0069ed30;
LAB_0067bab1:
      local_20 = *param_1;
      local_18 = *param_2;
      local_10 = *param_3;
      local_28 = 4;
      (*(code *)PTR_FUN_006ebe30)(&local_28);
      goto LAB_0067bc38;
    }
    if (param_4 == 0x1a) {
      *param_3 = 0x3ff0000000000000;
      return;
    }
    if (param_4 != 0x1b) {
      if (param_4 != 0x1c) {
        if (param_4 != 0x1d) {
          return;
        }
        local_24 = &PTR_DAT_0069ed30;
        goto LAB_0067bbfb;
      }
LAB_0067bbd3:
      local_24 = &PTR_DAT_0069ed30;
      goto LAB_0067bc05;
    }
    local_28 = 2;
LAB_0067ba64:
    local_24 = &PTR_DAT_0069ed30;
  }
LAB_0067bb73:
  local_20 = *param_1;
  local_18 = *param_2;
  local_10 = *param_3;
  iVar1 = (*(code *)PTR_FUN_006ebe30)(&local_28);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x22;
  }
LAB_0067bc38:
  *param_3 = local_10;
  return;
}


// ==== 0x67bc4b FUN_0067bc4b

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_0067bc4b(void)

{
  return 1;
}


// ==== 0x67bc6c FUN_0067bc6c

undefined4 FUN_0067bc6c(void)

{
  return 1;
}


// ==== 0x67bc70 FUN_0067bc70

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0067bc70(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x67bc7f;
  return uVar1;
}


// ==== 0x67bc80 FUN_0067bc80

/* WARNING: Removing unreachable block (ram,0x0067bca1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0067bc80(void)

{
  uint uVar1;
  int iVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar3;
  uint local_8;
  
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,4) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_8 < 0) * 0x80 |
          (uint)(&stack0x00000000 == (undefined1 *)0x8) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)&local_8 & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0xfffffffc < (undefined1 *)0x4) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar1 = uVar3 ^ 0x200000;
  local_8 = 0;
  if (((uint)((uVar1 & 0x4000) != 0) * 0x4000 | (uint)((uVar1 & 0x800) != 0) * 0x800 |
       (uint)((uVar1 & 0x200) != 0) * 0x200 | (uint)((uVar1 & 0x100) != 0) * 0x100 |
       (uint)((uVar1 & 0x80) != 0) * 0x80 | (uint)((uVar1 & 0x40) != 0) * 0x40 |
       (uint)((uVar1 & 0x10) != 0) * 0x10 | (uint)((uVar1 & 4) != 0) * 4 | (uint)((uVar1 & 1) != 0)
       | (uint)((uVar1 & 0x200000) != 0) * 0x200000 | (uint)((uVar1 & 0x40000) != 0) * 0x40000) !=
      uVar3) {
    iVar2 = cpuid_Version_info(1);
    local_8 = *(uint *)(iVar2 + 8);
  }
  _DAT_00792fbc = 0;
  DAT_00792fb8 = 0;
  if (((local_8 & 0x4000000) != 0) && (iVar2 = FUN_0067bc4b(), iVar2 != 0)) {
    _DAT_00792fbc = 1;
    DAT_00792fb8 = 1;
  }
  return 0;
}


// ==== 0x67bf80 __cintrindisp2

/* Library Function - Single Match
    __cintrindisp2
   
   Library: Visual Studio */

void __cintrindisp2(void)

{
  __trandisp2();
  FUN_0067c04a();
  return;
}


// ==== 0x67bfbe __cintrindisp1

/* Library Function - Single Match
    __cintrindisp1
   
   Library: Visual Studio */

void __cintrindisp1(void)

{
  __trandisp1();
  FUN_0067c04a();
  return;
}


// ==== 0x67bffb __ctrandisp2

/* Library Function - Single Match
    __ctrandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __ctrandisp2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __fload(param_1,param_2);
  __fload(param_3,param_4);
  __trandisp2();
  FUN_0067c043();
  return;
}


// ==== 0x67c043 FUN_0067c043

void FUN_0067c043(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  *(byte *)(unaff_EBP + -0x2c8) = *(byte *)(unaff_EBP + -0x2c8) & 0xfe;
  if (DAT_00717ad0 != 0) {
    return;
  }
  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if (cVar1 == -1) {
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
    }
    else {
      if (cVar1 != -2) {
        if (cVar1 == '\0') {
          return;
        }
        *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
        goto LAB_0067c12f;
      }
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
      if (uVar2 == 0) {
        *(undefined4 *)(unaff_EBP + -0x8e) = 4;
        in_ST0 = (float10)fscale(in_ST0,(float10)1536.0);
        if (ABS(in_ST0) < (float10)2.2250738585072014e-308) {
          in_ST0 = in_ST0 * (float10)0.0;
        }
        goto LAB_0067c12f;
      }
    }
    if (uVar2 == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)-1536.0);
      if ((float10)1.7976931348623157e+308 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)INFINITY;
      }
      goto LAB_0067c12f;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0067c12f:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_00681941((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,unaff_EBP + -0xa4
              );
  return;
}


// ==== 0x67c04a FUN_0067c04a

void FUN_0067c04a(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  if (DAT_00717ad0 != 0) {
    return;
  }
  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if (cVar1 == -1) {
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
    }
    else {
      if (cVar1 != -2) {
        if (cVar1 == '\0') {
          return;
        }
        *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
        goto LAB_0067c12f;
      }
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
      if (uVar2 == 0) {
        *(undefined4 *)(unaff_EBP + -0x8e) = 4;
        in_ST0 = (float10)fscale(in_ST0,(float10)1536.0);
        if (ABS(in_ST0) < (float10)2.2250738585072014e-308) {
          in_ST0 = in_ST0 * (float10)0.0;
        }
        goto LAB_0067c12f;
      }
    }
    if (uVar2 == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)-1536.0);
      if ((float10)1.7976931348623157e+308 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)INFINITY;
      }
      goto LAB_0067c12f;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0067c12f:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_00681941((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,unaff_EBP + -0xa4
              );
  return;
}


// ==== 0x67c191 __ctrandisp1

/* Library Function - Single Match
    __ctrandisp1
   
   Library: Visual Studio */

void __ctrandisp1(undefined4 param_1,undefined4 param_2)

{
  __fload(param_1,param_2);
  __trandisp1();
  FUN_0067c043();
  return;
}


// ==== 0x67c1c4 __fload

/* Library Function - Single Match
    __fload
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

float10 __fload(uint param_1,int param_2)

{
  float10 fVar1;
  
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    fVar1 = (float10)CONCAT28(param_2._2_2_ | 0x7fff,
                              CONCAT44(param_2 << 0xb | param_1 >> 0x15,param_1));
  }
  else {
    fVar1 = (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  }
  return fVar1;
}


// ==== 0x67c200 __fdiv_x87_ld

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime low (ghidra+hopper) docs/re/runtime.md */

uint __fdiv_x87_ld(int param_1,uint param_2,ushort param_3,undefined4 param_4,uint param_5,
                  uint param_6)

{
  float10 fVar1;
  uint uVar2;
  float10 fVar3;
  
  fVar1 = (float10)CONCAT28(param_3,CONCAT44(param_2,param_1));
  while (!CARRY4(param_2,param_2)) {
    if (param_1 == 0 && param_2 == 0) {
      return 0;
    }
    if ((param_3 & 0x7fff) != 0) {
      return param_3 & 0x7fff;
    }
    uVar2 = param_6 & 0x7fff;
    if (uVar2 == 0) {
      if (CARRY4(param_5,param_5)) {
        return param_5 * 2;
      }
    }
    else if ((uVar2 == 0x7fff) || (uVar2 = param_5 * 2, !CARRY4(param_5,param_5))) {
      return uVar2;
    }
    fVar3 = fVar1 * (float10)_DAT_006ebec8;
    param_1 = SUB104(fVar3,0);
    param_3 = (ushort)((unkuint10)fVar3 >> 0x40);
    param_2 = (uint)((unkuint10)fVar3 >> 0x20);
  }
  uVar2 = param_2 * 2 ^ 0xe000000;
  if ((uVar2 & 0xe000000) != 0) {
    return uVar2;
  }
  uVar2 = (param_2 & 0x7fffffff) >> 0x1b;
  if (*(char *)(uVar2 + 0x6ebeb0) != '\0') {
    if (((param_3 & 0x7fff) != 0) && ((param_3 & 0x7fff) != 0x7fff)) {
      if ((param_6 & 0x7fff) != 1) {
        return param_6 & 0x7fff;
      }
      return 1;
    }
    return param_3 & 0x7fff;
  }
  return uVar2;
}


// ==== 0x67ca06 FUN_0067ca06

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0067ca06(undefined4 param_1,uint param_2,ushort param_3)

{
  undefined4 in_EAX;
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 in_stack_0000001c;
  undefined2 uStack00000020;
  undefined2 uStack00000022;
  ushort in_stack_00000024;
  
  if ((((((CONCAT22(param_3,param_2._2_2_) ^ 0x700) & 0x700) == 0) &&
       ((&DAT_006ebecc)[(param_2._2_2_ & 0x7800) >> 0xb] != '\0')) && ((param_3 & 0x7fff) != 0x7fff)
      ) && ((((in_stack_00000024 & 0x7fff) != 0 && ((in_stack_00000024 & 0x7fff) != 0x7fff)) &&
            (((_uStack00000020 & 0x7fffffff) == 0 && ((param_2 & 0x7fffffff) == 0)))))) {
    if ((ushort)((param_3 & 0x7fff) + 0x3f) < (in_stack_00000024 & 0x7fff)) {
      iVar1 = ((in_stack_00000024 & 0x7fff) - (param_3 & 0x7fff) & 0x3f | 0x20) + 1;
      fVar3 = ABS((float10)CONCAT28(in_stack_00000024 & 0x7fff | param_3 & 0x8000,
                                    CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1))));
      fVar2 = ABS((float10)CONCAT28(in_stack_00000024,
                                    CONCAT26(uStack00000022,
                                             CONCAT24(uStack00000020,in_stack_0000001c))));
      do {
        if (fVar3 <= fVar2) {
          fVar2 = fVar2 - fVar3;
        }
        fVar3 = fVar3 * (float10)_DAT_006ebefc;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    else {
      while (-1 < (int)((in_stack_00000024 & 0x7fff) - ((param_3 & 0x7fff) + 10))) {
        fVar2 = (float10)CONCAT28(in_stack_00000024,
                                  CONCAT26(uStack00000022,CONCAT24(uStack00000020,in_stack_0000001c)
                                          ));
        fVar3 = (float10)CONCAT28((in_stack_00000024 & 0x7fff) -
                                  ((in_stack_00000024 & 0x7fff) - param_3 & 7 | 4) |
                                  param_3 & 0x8000,
                                  CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)));
        fVar2 = fVar2 - (float10)(unkint10)(fVar2 / fVar3) * fVar3;
        in_stack_0000001c = SUB104(fVar2,0);
        uStack00000020 = (undefined2)((unkuint10)fVar2 >> 0x20);
        uStack00000022 = (undefined2)((unkuint10)fVar2 >> 0x30);
        in_stack_00000024 = (ushort)((unkuint10)fVar2 >> 0x40);
      }
    }
  }
  return in_EAX;
}


// ==== 0x67cc0c FUN_0067cc0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0067cc0c(void)

{
  float10 in_ST0;
  float10 fVar1;
  float10 in_ST1;
  
  if (((uint)((unkuint10)in_ST1 >> 0x30) & 0x7fff0000) != 0) {
    fVar1 = (float10)FUN_0067ca06();
    return fVar1;
  }
  if (SUB104(in_ST1,0) != 0 || (int)((unkuint10)in_ST1 >> 0x20) != 0) {
    fVar1 = (float10)FUN_0067ca06(in_ST1 * (float10)_DAT_006ebee4);
    return fVar1;
  }
  return in_ST0 - (float10)(unkint10)(in_ST0 / in_ST1) * in_ST1;
}


// ==== 0x67cf90 FUN_0067cf90

void FUN_0067cf90(void)

{
  float10 in_ST0;
  float10 in_ST1;
  
  FUN_0067cfa9((double)in_ST1,(double)in_ST0);
  return;
}


// ==== 0x67cfa9 FUN_0067cfa9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0067cfa9(double param_1,int param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  ushort uVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  longlong lVar21;
  ulonglong uVar22;
  ulonglong in_XMM2_Qb;
  undefined1 auVar23 [16];
  longlong lVar26;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 in_XMM3 [16];
  undefined1 auVar27 [16];
  ulonglong uVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  undefined1 local_c [4];
  
  dVar13 = (double)((ulonglong)param_1 >> 0x2c);
  uVar11 = (ushort)((ulonglong)param_1 >> 0x30);
  uVar3 = (SUB82(dVar13,0) & 0xff) + 1 & 0x1fe;
  dVar35 = (double)((ulonglong)param_1 & 0xfffffffffffff | 0x3ff0000000000000) *
           *(double *)(&DAT_006ac940 + uVar3 * 4);
  dVar31 = *(double *)(&DAT_006ac940 + uVar3 * 4);
  dVar14 = *(double *)(&DAT_006acd50 + uVar3 * 8);
  dVar33 = *(double *)(&UNK_006acd58 + uVar3 * 8);
  uVar7 = 0x7fef - uVar11;
  uVar3 = SUB84(param_1,0);
  uVar9 = (uint)((ulonglong)param_1 >> 0x20);
  dVar32 = param_1;
  if ((uVar11 - 0x10 | uVar7) < 0x80000000) {
    uVar7 = 0;
    uVar8 = 0x3fe7f;
LAB_0067d026:
    uVar4 = ((ushort)((ulonglong)dVar35 >> 0x26) & 0xff) + 1 & 0x1fe;
    dVar29 = (double)((ulonglong)dVar32 & 0xfffffffffffff | DAT_006b01e0);
    dVar15 = (double)((ulonglong)dVar29 & 0xfffffffff8000000);
    in_XMM3._8_8_ = in_XMM3._8_8_ >> 0x1f;
    dVar29 = dVar29 - dVar15;
    uVar5 = ((ushort)((ulonglong)(dVar35 * *(double *)(&DAT_006ad560 + uVar4 * 4)) >> 0x1f) & 0x1ff)
            + 1 & 0x3fe;
    dVar30 = dVar31 * *(double *)(&DAT_006ad560 + uVar4 * 4) *
             *(double *)(&DAT_006ae180 + uVar5 * 4);
    dVar35 = dVar35 * *(double *)(&DAT_006ad560 + uVar4 * 4) *
             *(double *)(&DAT_006ae180 + uVar5 * 4);
    dVar32 = dVar14 + *(double *)(&DAT_006ad970 + uVar4 * 8) +
             (double)(int)((longlong)dVar13 - (ulonglong)uVar8 >> 8) +
             *(double *)(&DAT_006ae990 + uVar5 * 8);
    dVar34 = dVar33 + *(double *)(&DAT_006ad978 + uVar4 * 8) +
             *(double *)(&DAT_006ae998 + uVar5 * 8);
    dVar14 = (double)((ulonglong)dVar30 & 0xfffffffff8000000);
    dVar30 = dVar30 - dVar14;
    dVar36 = dVar35 + -1.442694902420044;
    dVar33 = dVar32 + dVar36;
    dVar31 = (double)CONCAT44(param_3,param_2);
    uVar2 = (ushort)(param_3 >> 0x10);
    dVar32 = dVar32 - dVar33;
    in_XMM3._0_8_ = 0xfffffffff8000000;
    uVar4 = (uint)(ushort)((ulonglong)dVar33 >> 0x30);
    dVar14 = (((dVar35 - dVar14 * dVar15) - dVar15 * dVar30) - dVar14 * dVar29) - dVar29 * dVar30;
    dVar35 = dVar36 - dVar14;
    dVar13 = dVar33 - dVar14;
    uVar8 = uVar2 & 0x7ff0;
    if (uVar8 < 0x7ff0) {
      iVar6 = (uVar8 - 0x3ff0) + (uVar4 & 0x7ff0);
      if ((0x40a0U - iVar6 | iVar6 - 0x3c70U) < 0x80000000) {
LAB_0067d178:
        dVar15 = (double)((ulonglong)dVar31 & 0xfffffffff8000000);
        dVar29 = (double)((ulonglong)dVar13 & 0xfffffffff8000000);
        dVar14 = (dVar32 + dVar36) - (dVar14 - (dVar33 - dVar13));
        dVar33 = dVar15 * dVar29 * 128.0;
        uVar3 = (uint)ROUND(dVar33);
        dVar31 = dVar15 * (dVar13 - dVar29) + dVar29 * (dVar31 - dVar15) +
                 (dVar13 - dVar29) * (dVar31 - dVar15);
        if (0 < (int)(0x1ff7f - uVar3 | uVar3 + 0x1e1ff)) {
          iVar6 = (uVar3 & 0x7f) * 0x10;
          auVar16._0_8_ = (double)((ulonglong)((uVar7 + uVar3 & 0xffffff80) + 0x1ff80) << 0x2d);
          auVar16._8_4_ = 0;
          auVar16._12_4_ = (int)((ulonglong)auVar16._0_8_ >> 0x20);
          dVar32 = *(double *)(&DAT_006af9c0 + iVar6) * auVar16._0_8_;
          dVar31 = (dVar33 - ((dVar33 + 6755399441055744.0) - 6755399441055744.0)) * 0.0078125 +
                   dVar31 + ((dVar35 * 0.16015105075297303 + dVar35 * dVar35 * -0.08325619496072671)
                             * dVar35 * dVar35 +
                             dVar35 * 9.597935033233511e-08 + dVar35 * dVar35 * -0.3465736568077919
                            + dVar34 + dVar14) * (double)CONCAT44(param_3,param_2);
          return (float10)(dVar31 * dVar31 * dVar32 *
                           (dVar31 * 0.0013333558146428443 + 0.009618129107628477) * dVar31 * dVar31
                           + *(double *)(&UNK_006af9c8 + iVar6) * auVar16._8_8_ +
                           (dVar31 * 0.055504108664821576 + 0.2402265069591007) * dVar31 * dVar31 *
                           dVar32 + dVar31 * 0.6931471805599453 * dVar32 + dVar32);
        }
        if ((int)uVar3 < 1) {
          if ((int)uVar3 < -0x3fdff) {
LAB_0067da0a:
            _local_c = (double)((ulonglong)uVar7 << 0x2d);
            uVar10 = 0x19;
            goto LAB_0067d7b1;
          }
          uVar7 = uVar7 + 0x80;
          uVar9 = (uVar3 & 0xffffff80) + 0x3fe80;
          uVar11 = 0;
        }
        else {
          if (0x3ffff < uVar3) goto LAB_0067da2d;
          uVar7 = uVar7 + 0x3ff00;
          uVar9 = uVar3 - 0x80 & 0xffffff80;
          uVar11 = 0x3ff0;
        }
        iVar6 = (uVar3 & 0x7f) * 0x10;
        uVar3 = ((int)-(uVar9 - 0x1ff80) >> 7) + 2;
        auVar20._0_8_ = (double)((ulonglong)uVar9 << 0x2d);
        auVar20._8_4_ = 0;
        auVar20._12_4_ = (int)((ulonglong)auVar20._0_8_ >> 0x20);
        dVar32 = *(double *)(&DAT_006af9c0 + iVar6) * auVar20._0_8_;
        dVar31 = (dVar33 - ((dVar33 + 6755399441055744.0) - 6755399441055744.0)) * 0.0078125 +
                 dVar31 + ((dVar35 * 0.16015105075297303 + dVar35 * dVar35 * -0.08325619496072671) *
                           dVar35 * dVar35 +
                           dVar35 * 9.597935033233511e-08 + dVar35 * dVar35 * -0.3465736568077919 +
                          dVar34 + dVar14) * (double)CONCAT44(param_3,param_2);
        _local_c = (double)((ulonglong)uVar7 << 0x2d);
        uVar28 = (ulonglong)(uVar3 + (uVar3 & 0x20));
        dVar14 = (double)(-1L << uVar28 & (ulonglong)dVar32);
        dVar31 = dVar31 * dVar31 * dVar32 *
                 (dVar31 * 0.0013333558146428443 + 0.009618129107628477) * dVar31 * dVar31 +
                 *(double *)(&UNK_006af9c8 + iVar6) * auVar20._8_8_ +
                 (dVar31 * 0.055504108664821576 + 0.2402265069591007) * dVar31 * dVar31 * dVar32 +
                 dVar31 * 0.6931471805599453 * dVar32;
        dVar33 = (double)((ulonglong)(dVar14 + dVar31) & -1L << uVar28);
        dVar31 = dVar31 + (dVar14 - dVar33) + (dVar32 - dVar14);
        if ((int)(uVar9 - 0x1ff80) < 1) {
          _local_c = dVar31 * _local_c + dVar33 * _local_c;
          _local_c = _local_c + (double)((ulonglong)uVar11 << 0x30) * _local_c;
          uVar10 = 0x18;
          if ((((ushort)((ulonglong)_local_c >> 0x30) & 0x7ff0) != 0x7ff0) &&
             (uVar10 = 0x19, ((ulonglong)_local_c & 0x7ff0000000000000) != 0)) {
            return (float10)_local_c;
          }
        }
        else {
          _local_c = (dVar31 + dVar33) * _local_c;
          _local_c = _local_c + (double)((ulonglong)uVar11 << 0x30) * _local_c;
          uVar10 = 0x18;
          if ((((ushort)((ulonglong)_local_c >> 0x30) & 0x7ff0) != 0x7ff0) &&
             (uVar10 = 0x19, ((ulonglong)_local_c & 0x7ff0000000000000) != 0)) {
            return (float10)_local_c;
          }
        }
      }
      else {
        dVar33 = dVar31 * dVar13;
        uVar3 = (ushort)((ulonglong)dVar33 >> 0x30) & 0x7ff0;
        uVar9 = uVar3 - 0x3c70;
        if ((0x40a0 - uVar3 | uVar9) < 0x80000000) goto LAB_0067d178;
        if (0x7fffffff < uVar9) {
          return (float10)(double)((ulonglong)(uVar7 | 0x1ff80) << 0x2d);
        }
        if (((uVar2 ^ (uVar11 & 0x7ff0) + 0xc010) & 0x8000) != 0) goto LAB_0067da0a;
LAB_0067da2d:
        uVar10 = 0x18;
        if (uVar7 == 0) {
          _local_c = INFINITY;
        }
        else {
          _local_c = -INFINITY;
        }
      }
      goto LAB_0067d7b1;
    }
    _local_c = (double)CONCAT44(param_3,param_2);
    auVar23._8_8_ = in_XMM2_Qb;
    auVar23._0_8_ = _local_c;
    bVar12 = uVar3 != 0;
    uVar3 = uVar4;
    if (bVar12) goto LAB_0067d6bc;
    if (uVar9 == 0x3ff00000) goto LAB_0067d79a;
    uVar3 = uVar9;
    if (uVar9 != 0xbff00000) goto LAB_0067d6bc;
    auVar18._0_4_ = -(uint)((int)((ulonglong)_local_c & 0xfffffffffffff) == 0);
    auVar18._4_4_ = -(uint)((int)(((ulonglong)_local_c & 0xfffffffffffff) >> 0x20) == 0);
    auVar18._8_4_ = -(uint)((int)(in_XMM3._8_8_ & in_XMM2_Qb) == 0);
    auVar18._12_4_ = -(uint)((int)((in_XMM3._8_8_ & in_XMM2_Qb) >> 0x20) == 0);
    if ((ushort)((ushort)(SUB161(auVar18 >> 7,0) & 1) | (ushort)(SUB161(auVar18 >> 0xf,0) & 1) << 1
                 | (ushort)(SUB161(auVar18 >> 0x17,0) & 1) << 2 |
                 (ushort)(SUB161(auVar18 >> 0x1f,0) & 1) << 3 |
                 (ushort)(SUB161(auVar18 >> 0x27,0) & 1) << 4 |
                 (ushort)(SUB161(auVar18 >> 0x2f,0) & 1) << 5 |
                 (ushort)(SUB161(auVar18 >> 0x37,0) & 1) << 6 |
                 (ushort)(SUB161(auVar18 >> 0x3f,0) & 1) << 7 |
                 (ushort)(SUB161(auVar18 >> 0x47,0) & 1) << 8 |
                 (ushort)(SUB161(auVar18 >> 0x4f,0) & 1) << 9 |
                 (ushort)(SUB161(auVar18 >> 0x57,0) & 1) << 10 |
                 (ushort)(SUB161(auVar18 >> 0x5f,0) & 1) << 0xb |
                 (ushort)((byte)(auVar18._12_4_ >> 7) & 1) << 0xc |
                 (ushort)((byte)(auVar18._12_4_ >> 0xf) & 1) << 0xd |
                 (ushort)((byte)(auVar18._12_4_ >> 0x17) & 1) << 0xe |
                (ushort)(byte)(auVar18._12_4_ >> 0x1f) << 0xf) == 0xff) {
      return (float10)1;
    }
  }
  else {
    auVar23._4_4_ = param_3;
    auVar23._0_4_ = param_2;
    in_XMM3._0_8_ = 0x7fffffffffffffff;
    auVar23._8_8_ = in_XMM2_Qb;
    uVar8 = param_3 & 0x7fffffff;
    if (uVar8 < 0x7ff00000) {
      if (param_2 == 0 && uVar8 == 0) {
        _local_c = 1.0;
        uVar10 = 0x1a;
        if (uVar3 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          uVar10 = 0x1d;
          if (((uVar9 & 0x7fffffff) < 0x7ff00001) &&
             (((uVar9 & 0x7fffffff) < 0x7ff00000 || (uVar3 == 0)))) {
            return (float10)1.0;
          }
        }
        goto LAB_0067d7b1;
      }
      if ((int)uVar7 < 0) {
        auVar27._8_8_ = in_XMM3._8_8_ << 0x34;
        auVar27._0_8_ = 0xfff0000000000000;
        iVar6 = (uVar8 >> 0x14) - 0x3f3;
        in_XMM3 = (undefined1  [16])0x0;
        uVar28 = (ulonglong)
                 CONCAT22((ushort)(-1 < iVar6) * (short)((uint)iVar6 >> 0x10),
                          (ushort)(-1 < (short)iVar6) * (short)iVar6);
        lVar21 = SUB168(auVar23 | auVar27,0) << uVar28;
        lVar26 = SUB168(auVar23 | auVar27,8) << uVar28;
        auVar24._0_4_ = -(uint)((int)lVar21 == 0);
        auVar24._4_4_ = -(uint)((int)((ulonglong)lVar21 >> 0x20) == 0);
        auVar24._8_4_ = -(uint)((int)lVar26 == 0);
        auVar24._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0);
        bVar1 = SUB161(auVar24 >> 7,0) & 1 | (SUB161(auVar24 >> 0xf,0) & 1) << 1 |
                (SUB161(auVar24 >> 0x17,0) & 1) << 2 | (SUB161(auVar24 >> 0x1f,0) & 1) << 3 |
                (SUB161(auVar24 >> 0x27,0) & 1) << 4 | (SUB161(auVar24 >> 0x2f,0) & 1) << 5 |
                (SUB161(auVar24 >> 0x37,0) & 1) << 6 | SUB161(auVar24 >> 0x3f,0) << 7;
        uVar8 = 0x7fef - uVar7 & 0x7fff;
        uVar28 = auVar24._8_8_;
        if (0x7fef < uVar8) {
          auVar17._0_4_ = -(uint)((int)((ulonglong)param_1 & 0xfffffffffffff) == 0);
          auVar17._4_4_ = -(uint)((int)(((ulonglong)param_1 & 0xfffffffffffff) >> 0x20) == 0);
          auVar17._8_4_ = 0xffffffff;
          auVar17._12_4_ = 0xffffffff;
          if ((byte)(SUB161(auVar17 >> 7,0) & 1 | (SUB161(auVar17 >> 0xf,0) & 1) << 1 |
                     (SUB161(auVar17 >> 0x17,0) & 1) << 2 | (SUB161(auVar17 >> 0x1f,0) & 1) << 3 |
                     (SUB161(auVar17 >> 0x27,0) & 1) << 4 | (SUB161(auVar17 >> 0x2f,0) & 1) << 5 |
                     (SUB161(auVar17 >> 0x37,0) & 1) << 6 | SUB161(auVar17 >> 0x3f,0) << 7) == 0xff)
          {
            if (((ulonglong)param_1 & 0x8000000000000000) != 0) {
              if ((bVar1 != 0xff) ||
                 (uVar22 = (ulonglong)(((param_3 & 0x7fffffff) >> 0x14) - 0x3f4),
                 lVar21 = CONCAT44(param_3,param_2) << uVar22, lVar26 = uVar28 << uVar22,
                 auVar25._0_4_ = -(uint)((int)lVar21 == 0),
                 auVar25._4_4_ = -(uint)((int)((ulonglong)lVar21 >> 0x20) == 0),
                 auVar25._8_4_ = -(uint)((int)lVar26 == 0),
                 auVar25._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0),
                 (byte)(SUB161(auVar25 >> 7,0) & 1 | (SUB161(auVar25 >> 0xf,0) & 1) << 1 |
                        (SUB161(auVar25 >> 0x17,0) & 1) << 2 | (SUB161(auVar25 >> 0x1f,0) & 1) << 3
                        | (SUB161(auVar25 >> 0x27,0) & 1) << 4 |
                        (SUB161(auVar25 >> 0x2f,0) & 1) << 5 | (SUB161(auVar25 >> 0x37,0) & 1) << 6
                       | SUB161(auVar25 >> 0x3f,0) << 7) == 0xff)) {
                if ((param_3 & 0x80000000) != 0) {
                  return (float10)0;
                }
                goto LAB_0067d72e;
              }
              if ((param_3 & 0x80000000) == 0) {
                return (float10)-INFINITY;
              }
              goto LAB_0067d5c9;
            }
            if ((param_3 & 0x80000000) != 0) {
              return (float10)0;
            }
            goto LAB_0067d72e;
          }
          goto LAB_0067d60f;
        }
        if (bVar1 == 0xff) {
          uVar22 = (ulonglong)(((param_3 & 0x7fffffff) >> 0x14) - 0x3f4);
          in_XMM3 = ZEXT816(0x8000000000000000);
          lVar21 = CONCAT44(param_3,param_2) << uVar22;
          lVar26 = uVar28 << uVar22;
          auVar23._0_4_ = -(uint)((int)lVar21 == 0);
          auVar23._4_4_ = -(uint)((int)((ulonglong)lVar21 >> 0x20) == in_XMM3._4_4_);
          auVar23._8_4_ = -(uint)((int)lVar26 == 0);
          auVar23._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0);
          uVar7 = (ushort)((ushort)(SUB161(auVar23 >> 7,0) & 1) |
                           (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |
                           (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |
                           (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |
                           (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |
                           (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |
                           (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |
                          (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7) + 0x3ff01 & 0x40000;
          if (0xf < uVar8) {
            uVar8 = 0xbfe7f;
            in_XMM3 = ZEXT816(0xfffffffffffff);
            in_XMM2_Qb = auVar23._8_8_;
            goto LAB_0067d026;
          }
          goto LAB_0067d444;
        }
        uVar22 = (ulonglong)param_1 >> 0x20;
        in_XMM2_Qb = uVar28 >> 0x20;
        uVar7 = 0;
        uVar8 = 0;
        if (uVar3 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          _local_c = -NAN;
          uVar10 = 0x1c;
          goto LAB_0067d7b1;
        }
LAB_0067d4ca:
        dVar32 = dVar13;
        if ((uVar8 & 0x7fffffff) == 0) {
          if ((param_3 & 0x80000000) == 0) {
            if ((uVar8 & uVar7 << 0xd) == 0) {
              return (float10)0;
            }
LAB_0067d5c9:
            return (float10)-0.0;
          }
          _local_c = (double)((ulonglong)(uVar8 & uVar7 << 0xd | 0x7ff00000) << 0x20);
          uVar10 = 0x1b;
          goto LAB_0067d7b1;
        }
      }
      else {
        uVar7 = 0;
LAB_0067d444:
        dVar35 = 2.225073858507201e-308;
        in_XMM2_Qb = auVar23._8_8_;
        uVar22 = 0x3ff0000000000000;
        dVar13 = param_1 * 1.8446744073709552e+19;
        uVar8 = uVar9;
        dVar32 = dVar13;
        if (uVar3 == 0) goto LAB_0067d4ca;
      }
      dVar13 = (double)((ulonglong)ABS(dVar32) >> 0x2c);
      uVar8 = (SUB82(dVar13,0) & 0xff) + 1 & 0x1fe;
      dVar35 = (double)((ulonglong)dVar35 & (ulonglong)dVar32 | uVar22) *
               *(double *)(&DAT_006ac940 + uVar8 * 4);
      dVar31 = *(double *)(&DAT_006ac940 + uVar8 * 4);
      dVar14 = *(double *)(&DAT_006acd50 + uVar8 * 8);
      dVar33 = *(double *)(&UNK_006acd58 + uVar8 * 8);
      uVar8 = 0x43e7f;
      goto LAB_0067d026;
    }
    uVar7 = uVar9;
    if ((0x7fefffff < (uVar9 & 0x7fffffff)) && ((0x7ff00000 < (uVar9 & 0x7fffffff) || (uVar3 != 0)))
       ) {
LAB_0067d60f:
      _local_c = param_1 + param_1;
      uVar10 = 0x3ee;
      goto LAB_0067d7b1;
    }
LAB_0067d6bc:
    _local_c = auVar23._0_8_;
    uVar28 = in_XMM3._8_8_ & auVar23._8_8_;
    auVar19._0_4_ = -(uint)((int)((ulonglong)_local_c & 0xfffffffffffff) == 0);
    auVar19._4_4_ = -(uint)((int)(((ulonglong)_local_c & 0xfffffffffffff) >> 0x20) == 0);
    auVar19._8_4_ = -(uint)((int)uVar28 == 0);
    auVar19._12_4_ = -(uint)((int)(uVar28 >> 0x20) == 0);
    if ((byte)(SUB161(auVar19 >> 7,0) & 1 | (SUB161(auVar19 >> 0xf,0) & 1) << 1 |
               (SUB161(auVar19 >> 0x17,0) & 1) << 2 | (SUB161(auVar19 >> 0x1f,0) & 1) << 3 |
               (SUB161(auVar19 >> 0x27,0) & 1) << 4 | (SUB161(auVar19 >> 0x2f,0) & 1) << 5 |
               (SUB161(auVar19 >> 0x37,0) & 1) << 6 | SUB161(auVar19 >> 0x3f,0) << 7) == 0xff) {
      if (uVar3 != 0 || uVar7 != 0xbff00000) {
        if ((auVar23._6_2_ & 0x8000) == 0) {
          if ((uVar11 & 0x7ff0) < 0x3ff0) {
            return (float10)0;
          }
        }
        else if (0x3fef < (uVar11 & 0x7ff0)) {
          return (float10)0;
        }
LAB_0067d72e:
        return (float10)INFINITY;
      }
LAB_0067d79a:
      _local_c = (double)CONCAT44(param_3,param_2) + -NAN;
      uVar10 = 0x1c;
      goto LAB_0067d7b1;
    }
  }
  _local_c = _local_c + _local_c;
  uVar10 = 0x3ee;
LAB_0067d7b1:
  FUN_0067b9b7(&param_1,&param_2,local_c,uVar10);
  return (float10)_local_c;
}


// ==== 0x67dce7 FUN_0067dce7

undefined4 __thiscall FUN_0067dce7(undefined4 param_1,double param_2)

{
  uint uVar1;
  float10 fVar2;
  
  uVar1 = FUN_00672f2e(param_2,param_1,param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = (float10)FUN_00681f2f(param_2);
    if ((double)fVar2 == param_2) {
      param_2 = param_2 / 2.0;
      fVar2 = (float10)FUN_00681f2f();
      if (fVar2 == (float10)param_2) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x67dd51 __powhlp

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __powhlp
   
   Library: Visual Studio 2003 Release */

undefined4 __powhlp(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  uVar4 = 0;
  if (dVar1 < 0.0) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_006ebd00;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) goto LAB_0067ddfc;
    if (1.0 < dVar1) goto LAB_0067deac;
    if (1.0 <= dVar1) goto LAB_0067ddaf;
  }
  else {
    if ((param_3._4_4_ == -0x100000) && (param_3._0_4_ == 0)) {
      if (1.0 < dVar1) {
        dVar2 = 0.0;
        goto LAB_0067deac;
      }
      if (dVar1 < 1.0) goto LAB_0067deac;
LAB_0067ddaf:
      uVar4 = 1;
      dVar2 = _DAT_006ebd08;
      goto LAB_0067deac;
    }
LAB_0067ddfc:
    if (param_2 != 0x7ff00000) {
      if (param_2 != -0x100000) {
        return 0;
      }
      if (param_1 != 0) {
        return 0;
      }
      iVar3 = FUN_0067dce7(param_3);
      if (param_3 <= 0.0) {
        if (0.0 <= param_3) {
          dVar2 = 1.0;
        }
        else {
          dVar2 = _DAT_006ebd20;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
        }
      }
      else {
        dVar2 = _DAT_006ebd00;
        if (iVar3 == 1) {
          dVar2 = -_DAT_006ebd00;
        }
      }
      goto LAB_0067deac;
    }
    if (param_1 != 0) {
      return 0;
    }
    if (0.0 < param_3) goto LAB_0067deac;
    if (0.0 <= param_3) {
      dVar2 = 1.0;
      goto LAB_0067deac;
    }
  }
  dVar2 = 0.0;
LAB_0067deac:
  *param_4 = dVar2;
  return uVar4;
}


// ==== 0x67dec0 FUN_0067dec0

void FUN_0067dec0(void)

{
  float10 in_ST0;
  
  FUN_0067dede((double)in_ST0);
  return;
}


// ==== 0x67dede FUN_0067dede

float10 FUN_0067dede(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double in_XMM0_Qa;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined2 uStack_c;
  undefined6 uStack_a;
  undefined2 uStack_4;
  
  uVar1 = (ushort)((ulonglong)in_XMM0_Qa >> 0x30) & 0x7fff;
  if ((0x408f - uVar1 | uVar1 - 0x3c90) < 0x80000000) {
    dVar5 = in_XMM0_Qa * 92.33248261689366 + 6755399441055744.0;
    dVar6 = (in_XMM0_Qa * 92.33248261689366 + 6755399441055744.0) - 6755399441055744.0;
    uVar1 = SUB84(dVar5,0);
    iVar2 = (uVar1 & 0x3f) * 0x10;
    dVar4 = (in_XMM0_Qa - (dVar5 - 6755399441055744.0) * 0.010830424696223417) -
            (dVar5 - 6755399441055744.0) * 2.572804622327669e-14;
    dVar6 = (in_XMM0_Qa - dVar6 * 0.010830424696223417) - dVar6 * 2.572804622327669e-14;
    dVar5 = (double)(*(ulonglong *)(&UNK_006b0328 + iVar2) |
                    ((ulonglong)dVar5 & 0xffffffc0) + 0xffc0 << 0x2e);
    dVar4 = dVar6 * dVar6 * (dVar6 * 0.16666666669815094 + 0.4999999999995663) +
            dVar4 + *(double *)(&DAT_006b0320 + iVar2) +
            dVar4 * dVar4 * dVar4 * dVar4 * (dVar4 * 0.008332168270616733 + 0.04166672086872847);
    if (((int)uVar1 >> 6) + 0x37eU < 0x77d) {
      return (float10)(dVar4 * dVar5 + dVar5);
    }
    dVar6 = (double)(*(ulonglong *)(&UNK_006b0328 + iVar2) & 0xfffffffffffff |
                    (ulonglong)(((int)uVar1 >> 7) + 0x3ff) << 0x34);
    uStack_4 = (undefined2)((ulonglong)dVar6 >> 0x30);
    in_XMM0_Qa = (double)((ulonglong)((((int)uVar1 >> 6) - ((int)uVar1 >> 7)) + 0x3ff) << 0x34) *
                 (dVar6 + dVar4 * dVar6);
    if (((ushort)((ulonglong)in_XMM0_Qa >> 0x30) & 0x7ff0) < 0x7ff0) {
      if (((ulonglong)in_XMM0_Qa & 0x7ff0000000000000) != 0) goto LAB_0067e0d2;
      uVar3 = 0xf;
    }
    else {
      uVar3 = 0xe;
    }
  }
  else {
    uVar1 = param_2 & 0x7fffffff;
    if (uVar1 < 0x40900000) {
      return (float10)((double)CONCAT44(param_2,param_1) + 1.0);
    }
    if (uVar1 < 0x7ff00000) {
      if (param_2 < 0x80000000) {
        in_XMM0_Qa = INFINITY;
        uVar3 = 0xe;
      }
      else {
        in_XMM0_Qa = 0.0;
        uVar3 = 0xf;
      }
    }
    else {
      if ((uVar1 < 0x7ff00001) && (param_1 == 0)) {
        if (param_2 != 0x7ff00000) {
          return (float10)0.0;
        }
        return (float10)INFINITY;
      }
      uVar3 = 0x3ea;
    }
  }
  uStack_c = SUB82(in_XMM0_Qa,0);
  uStack_a = (undefined6)((ulonglong)in_XMM0_Qa >> 0x10);
  FUN_0067b9b7(&param_1,&param_1,(short)&uStack_c,uVar3);
  in_XMM0_Qa = (double)CONCAT62(uStack_a,uStack_c);
LAB_0067e0d2:
  return (float10)in_XMM0_Qa;
}


// ==== 0x67e180 ___ascii_stricmp

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

int __cdecl ___ascii_stricmp(char *_Str1,char *_Str2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = 0xff;
  do {
    do {
      cVar4 = '\0';
      if (bVar3 == 0) goto LAB_0067e1c6;
      bVar3 = *_Str2;
      _Str2 = _Str2 + 1;
      bVar2 = *_Str1;
      _Str1 = _Str1 + 1;
    } while (bVar2 == bVar3);
    bVar1 = bVar3 + 0xbf + (-((byte)(bVar3 + 0xbf) < 0x1a) & 0x20U) + 0x41;
    bVar2 = bVar2 + 0xbf;
    bVar3 = bVar2 + (-(bVar2 < 0x1a) & 0x20U) + 0x41;
  } while (bVar3 == bVar1);
  cVar4 = (bVar3 < bVar1) * -2 + '\x01';
LAB_0067e1c6:
  return (int)cVar4;
}


// ==== 0x67e1d0 _strcpy

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

uint * _strcpy(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0067e2c0;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0067e2c0:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


// ==== 0x67e1e0 _strcat

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

uint * _strcat(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0067e200;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0067e233;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0067e24f;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0067e200:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0067e24f;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0067e24f;
    }
  }
LAB_0067e233:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0067e24f:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0067e2c0:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_0067e2c0;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== 0x67e2c8 __get_lc_time

/* Library Function - Single Match
    __get_lc_time
   
   Library: Visual Studio 2003 Release */

uint __get_lc_time(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  int unaff_ESI;
  
  uVar1 = DAT_00717eca;
  uVar46 = (uint)DAT_00717ecc;
  if (unaff_ESI == 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_00681f42(1,DAT_00717eca,0x31,unaff_ESI + 4);
  uVar3 = FUN_00681f42(1,uVar1,0x32,unaff_ESI + 8);
  uVar4 = FUN_00681f42(1,uVar1,0x33,unaff_ESI + 0xc);
  uVar5 = FUN_00681f42(1,uVar1,0x34,unaff_ESI + 0x10);
  uVar6 = FUN_00681f42(1,uVar1,0x35,unaff_ESI + 0x14);
  uVar7 = FUN_00681f42(1,uVar1,0x36,unaff_ESI + 0x18);
  uVar8 = FUN_00681f42(1,uVar1,0x37);
  uVar9 = FUN_00681f42(1,uVar1,0x2a,unaff_ESI + 0x20);
  uVar10 = FUN_00681f42(1,uVar1,0x2b,unaff_ESI + 0x24);
  uVar11 = FUN_00681f42(1,uVar1,0x2c,unaff_ESI + 0x28);
  uVar12 = FUN_00681f42(1,uVar1,0x2d,unaff_ESI + 0x2c);
  uVar13 = FUN_00681f42(1,uVar1,0x2e,unaff_ESI + 0x30);
  uVar14 = FUN_00681f42(1,uVar1,0x2f,unaff_ESI + 0x34);
  uVar15 = FUN_00681f42(1,uVar1,0x30,unaff_ESI + 0x1c);
  uVar16 = FUN_00681f42(1,uVar1,0x44,unaff_ESI + 0x38);
  uVar17 = FUN_00681f42(1,uVar1,0x45,unaff_ESI + 0x3c);
  uVar18 = FUN_00681f42(1,uVar1,0x46,unaff_ESI + 0x40);
  uVar19 = FUN_00681f42(1,uVar1,0x47,unaff_ESI + 0x44);
  uVar20 = FUN_00681f42(1,uVar1,0x48,unaff_ESI + 0x48);
  uVar21 = FUN_00681f42(1,uVar1,0x49,unaff_ESI + 0x4c);
  uVar22 = FUN_00681f42(1,uVar1,0x4a,unaff_ESI + 0x50);
  uVar23 = FUN_00681f42(1,uVar1,0x4b,unaff_ESI + 0x54);
  uVar24 = FUN_00681f42(1,uVar1,0x4c,unaff_ESI + 0x58);
  uVar25 = FUN_00681f42(1,uVar1,0x4d,unaff_ESI + 0x5c);
  uVar26 = FUN_00681f42(1,uVar1,0x4e,unaff_ESI + 0x60);
  uVar27 = FUN_00681f42(1,uVar1,0x4f,unaff_ESI + 100);
  uVar28 = FUN_00681f42(1,uVar1,0x38,unaff_ESI + 0x68);
  uVar29 = FUN_00681f42(1,uVar1,0x39,unaff_ESI + 0x6c);
  uVar30 = FUN_00681f42(1,uVar1,0x3a,unaff_ESI + 0x70);
  uVar31 = FUN_00681f42(1,uVar1,0x3b,unaff_ESI + 0x74);
  uVar32 = FUN_00681f42(1,uVar1,0x3c,unaff_ESI + 0x78);
  uVar33 = FUN_00681f42(1,uVar1,0x3d,unaff_ESI + 0x7c);
  uVar34 = FUN_00681f42(1,uVar1,0x3e,unaff_ESI + 0x80);
  uVar35 = FUN_00681f42(1,uVar1,0x3f,unaff_ESI + 0x84);
  uVar36 = FUN_00681f42(1,uVar1,0x40,unaff_ESI + 0x88);
  uVar37 = FUN_00681f42(1,uVar1,0x41,unaff_ESI + 0x8c);
  uVar38 = FUN_00681f42(1,uVar1,0x42,unaff_ESI + 0x90);
  uVar39 = FUN_00681f42(1,uVar1,0x43,unaff_ESI + 0x94);
  uVar40 = FUN_00681f42(1,uVar1,0x28,unaff_ESI + 0x98);
  uVar41 = FUN_00681f42(1,uVar1,0x29,unaff_ESI + 0x9c);
  uVar42 = FUN_00681f42(1,uVar46,0x1f,unaff_ESI + 0xa0);
  uVar43 = FUN_00681f42(1,uVar46,0x20,unaff_ESI + 0xa4);
  uVar44 = FUN_00681f42(1,uVar46,0x1003,unaff_ESI + 0xa8);
  uVar45 = FUN_00681f42(0,uVar46,0x1009,unaff_ESI + 0xb0);
  *(uint *)(unaff_ESI + 0xac) = uVar46;
  return uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
         uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 | uVar22 |
         uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 | uVar32 |
         uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 | uVar42 |
         uVar43 | uVar44 | uVar45;
}


// ==== 0x67e62f ___free_lc_time

/* Library Function - Single Match
    ___free_lc_time
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void ___free_lc_time(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    _free((void *)param_1[1]);
    _free((void *)param_1[2]);
    _free((void *)param_1[3]);
    _free((void *)param_1[4]);
    _free((void *)param_1[5]);
    _free((void *)param_1[6]);
    _free((void *)*param_1);
    _free((void *)param_1[8]);
    _free((void *)param_1[9]);
    _free((void *)param_1[10]);
    _free((void *)param_1[0xb]);
    _free((void *)param_1[0xc]);
    _free((void *)param_1[0xd]);
    _free((void *)param_1[7]);
    _free((void *)param_1[0xe]);
    _free((void *)param_1[0xf]);
    _free((void *)param_1[0x10]);
    _free((void *)param_1[0x11]);
    _free((void *)param_1[0x12]);
    _free((void *)param_1[0x13]);
    _free((void *)param_1[0x14]);
    _free((void *)param_1[0x15]);
    _free((void *)param_1[0x16]);
    _free((void *)param_1[0x17]);
    _free((void *)param_1[0x18]);
    _free((void *)param_1[0x19]);
    _free((void *)param_1[0x1a]);
    _free((void *)param_1[0x1b]);
    _free((void *)param_1[0x1c]);
    _free((void *)param_1[0x1d]);
    _free((void *)param_1[0x1e]);
    _free((void *)param_1[0x1f]);
    _free((void *)param_1[0x20]);
    _free((void *)param_1[0x21]);
    _free((void *)param_1[0x22]);
    _free((void *)param_1[0x23]);
    _free((void *)param_1[0x24]);
    _free((void *)param_1[0x25]);
    _free((void *)param_1[0x26]);
    _free((void *)param_1[0x27]);
    _free((void *)param_1[0x28]);
    _free((void *)param_1[0x29]);
    _free((void *)param_1[0x2a]);
  }
  return;
}


// ==== 0x67e7bf FUN_0067e7bf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0067e7bf(void)

{
  undefined *_Memory;
  int iVar1;
  
  if (_DAT_00717e9c == 0) {
    PTR_PTR_006ec070 = (undefined *)&PTR_PTR_006ec078;
    DAT_00717e5c = (undefined *)0x0;
    return 0;
  }
  _Memory = _calloc(1,0xb8);
  if (_Memory != (undefined *)0x0) {
    iVar1 = __get_lc_time();
    if (iVar1 == 0) {
      PTR_PTR_006ec070 = _Memory;
      DAT_00717e5c = _Memory;
      return 0;
    }
    ___free_lc_time(_Memory);
    _free(_Memory);
  }
  return 1;
}


// ==== 0x67e81e ___free_lconv_num

/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2003 Release */

void ___free_lconv_num(undefined4 *param_1)

{
  undefined *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined *)*param_1;
    if ((puVar1 != *(undefined **)PTR_PTR_006ec16c) && (puVar1 != PTR_DAT_006ec13c)) {
      _free(puVar1);
    }
    puVar1 = (undefined *)param_1[1];
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 4)) && (puVar1 != PTR_DAT_006ec140)) {
      _free(puVar1);
    }
    puVar1 = (undefined *)param_1[2];
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 8)) && (puVar1 != PTR_DAT_006ec144)) {
      _free(puVar1);
    }
  }
  return;
}


// ==== 0x67e87d ___init_numeric

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 2003 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int *_Memory;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined **_Memory_00;
  undefined4 *puVar8;
  char *pcVar9;
  undefined **ppuVar10;
  
  if ((DAT_00717e98 == 0) && (DAT_00717e94 == 0)) {
    if (((DAT_00792fb0 != (int *)0x0) && (*DAT_00792fb0 == 0)) &&
       (DAT_00792fb0 != *(int **)(PTR_DAT_006eb554 + 0x2c))) {
      _free(DAT_00792fb0);
      _free(DAT_00717e60);
    }
    DAT_00792fb4 = (undefined4 *)0x0;
    DAT_00792fb0 = (int *)0x0;
    _Memory_00 = &PTR_DAT_006ec13c;
    DAT_00717e60 = (undefined **)0x0;
    ppuVar10 = DAT_00717e60;
    _Memory = DAT_00792fb0;
LAB_0067ea2a:
    DAT_00792fb0 = _Memory;
    DAT_00717e60 = ppuVar10;
    DAT_006ec184 = **_Memory_00;
    _DAT_006ec188 = 1;
    iVar7 = 0;
    PTR_PTR_006ec16c = (undefined *)_Memory_00;
  }
  else {
    _Memory_00 = _calloc(1,0x30);
    if (_Memory_00 != (undefined **)0x0) {
      puVar8 = (undefined4 *)PTR_PTR_006ec16c;
      ppuVar10 = _Memory_00;
      for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppuVar10 = (undefined *)*puVar8;
        puVar8 = puVar8 + 1;
        ppuVar10 = ppuVar10 + 1;
      }
      _Memory = _malloc(4);
      if (_Memory != (int *)0x0) {
        *_Memory = 0;
        if (DAT_00717e98 == 0) {
          DAT_00792fb4 = (undefined4 *)0x0;
          *_Memory_00 = PTR_DAT_006ec13c;
          _Memory_00[1] = PTR_DAT_006ec140;
          _Memory_00[2] = PTR_DAT_006ec144;
        }
        else {
          DAT_00792fb4 = _malloc(4);
          if (DAT_00792fb4 == (undefined4 *)0x0) {
            iVar7 = 1;
LAB_0067e988:
            _free(_Memory_00);
            _free(_Memory);
            return iVar7;
          }
          *DAT_00792fb4 = 0;
          uVar3 = DAT_00717ec6;
          iVar7 = FUN_00681f42(1,DAT_00717ec6,0xe,_Memory_00);
          iVar4 = FUN_00681f42(1,uVar3,0xf,_Memory_00 + 1);
          iVar5 = FUN_00681f42(1,uVar3,0x10,_Memory_00 + 2);
          if (iVar5 != 0 || (iVar7 != 0 || iVar4 != 0)) {
            ___free_lconv_num(_Memory_00);
            iVar7 = -1;
            goto LAB_0067e988;
          }
          pcVar6 = _Memory_00[2];
          while (*pcVar6 != '\0') {
            cVar2 = *pcVar6;
            if ((cVar2 < '0') || ('9' < cVar2)) {
              pcVar9 = pcVar6;
              if (cVar2 != ';') goto LAB_0067e9b4;
              do {
                pcVar1 = pcVar9 + 1;
                *pcVar9 = *pcVar1;
                pcVar9 = pcVar1;
              } while (*pcVar1 != '\0');
            }
            else {
              *pcVar6 = cVar2 + -0x30;
LAB_0067e9b4:
              pcVar6 = pcVar6 + 1;
            }
          }
        }
        ppuVar10 = _Memory_00;
        if (((DAT_00792fb0 != (int *)0x0) && (*DAT_00792fb0 == 0)) &&
           (DAT_00792fb0 != *(int **)(PTR_DAT_006eb554 + 0x2c))) {
          _free(DAT_00792fb0);
          _free(DAT_00717e60);
        }
        goto LAB_0067ea2a;
      }
      _free(_Memory_00);
    }
    iVar7 = 1;
  }
  return iVar7;
}


// ==== 0x67ea4a ___free_lconv_mon

/* Library Function - Single Match
    ___free_lconv_mon
   
   Library: Visual Studio 2003 Release */

void ___free_lconv_mon(int param_1)

{
  undefined *puVar1;
  
  if (param_1 != 0) {
    puVar1 = *(undefined **)(param_1 + 0xc);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0xc)) && (puVar1 != PTR_DAT_006ec148)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x10);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x10)) && (puVar1 != PTR_DAT_006ec14c)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x14);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x14)) && (puVar1 != PTR_DAT_006ec150)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x18);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x18)) && (puVar1 != PTR_DAT_006ec154)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x1c);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x1c)) && (puVar1 != PTR_DAT_006ec158)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x20);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x20)) && (puVar1 != PTR_DAT_006ec15c)) {
      _free(puVar1);
    }
    puVar1 = *(undefined **)(param_1 + 0x24);
    if ((puVar1 != *(undefined **)(PTR_PTR_006ec16c + 0x24)) && (puVar1 != PTR_DAT_006ec160)) {
      _free(puVar1);
    }
  }
  return;
}


// ==== 0x67eb23 ___init_monetary

/* Library Function - Single Match
    ___init_monetary
   
   Library: Visual Studio 2003 Release */

int __cdecl ___init_monetary(threadlocinfo *_LocInfo)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  char *pcVar20;
  undefined **ppuVar21;
  undefined4 *puVar22;
  
  if ((DAT_00717e94 == 0) && (DAT_00717e98 == 0)) {
    DAT_00792fac = (undefined4 *)0x0;
    DAT_00792fb0 = (undefined4 *)0x0;
    PTR_PTR_006ec16c = (undefined *)&PTR_DAT_006ec13c;
    DAT_00717e60 = (undefined4 *)0x0;
LAB_0067ed5b:
    iVar19 = 0;
  }
  else {
    _Memory = _calloc(1,0x30);
    if (_Memory != (undefined4 *)0x0) {
      _Memory_00 = _malloc(4);
      if (_Memory_00 == (undefined4 *)0x0) {
        _free(_Memory);
      }
      else {
        *_Memory_00 = 0;
        if (DAT_00717e94 == 0) {
          ppuVar21 = &PTR_DAT_006ec13c;
          puVar22 = _Memory;
          for (iVar19 = 0xc; iVar19 != 0; iVar19 = iVar19 + -1) {
            *puVar22 = *ppuVar21;
            ppuVar21 = ppuVar21 + 1;
            puVar22 = puVar22 + 1;
          }
          DAT_00792fac = (undefined4 *)0x0;
LAB_0067ed28:
          *_Memory = *(undefined4 *)PTR_PTR_006ec16c;
          _Memory[1] = *(undefined4 *)(PTR_PTR_006ec16c + 4);
          _Memory[2] = *(undefined4 *)(PTR_PTR_006ec16c + 8);
          PTR_PTR_006ec16c = (undefined *)_Memory;
          DAT_00717e60 = _Memory;
          DAT_00792fb0 = _Memory_00;
          goto LAB_0067ed5b;
        }
        DAT_00792fac = _malloc(4);
        if (DAT_00792fac == (undefined4 *)0x0) {
          _free(_Memory);
          _free(_Memory_00);
        }
        else {
          *DAT_00792fac = 0;
          uVar3 = DAT_00717ec0;
          iVar19 = FUN_00681f42(1,DAT_00717ec0,0x15,_Memory + 3);
          iVar4 = FUN_00681f42(1,uVar3,0x14,_Memory + 4);
          iVar5 = FUN_00681f42(1,uVar3,0x16,_Memory + 5);
          iVar6 = FUN_00681f42(1,uVar3,0x17,_Memory + 6);
          iVar7 = FUN_00681f42(1,uVar3,0x18,_Memory + 7);
          iVar8 = FUN_00681f42(1,uVar3,0x50,_Memory + 8);
          iVar9 = FUN_00681f42(1,uVar3,0x51,_Memory + 9);
          iVar10 = FUN_00681f42(0,uVar3,0x1a,_Memory + 10);
          iVar11 = FUN_00681f42(0,uVar3,0x19,(int)_Memory + 0x29);
          iVar12 = FUN_00681f42(0,uVar3,0x54,(int)_Memory + 0x2a);
          iVar13 = FUN_00681f42(0,uVar3,0x55,(int)_Memory + 0x2b);
          iVar14 = FUN_00681f42(0,uVar3,0x56,_Memory + 0xb);
          iVar15 = FUN_00681f42(0,uVar3,0x57,(int)_Memory + 0x2d);
          iVar16 = FUN_00681f42(0,uVar3,0x52,(int)_Memory + 0x2e);
          iVar17 = FUN_00681f42(0,uVar3,0x53,(int)_Memory + 0x2f);
          if (iVar17 == 0 &&
              (((((((((((((iVar19 == 0 && iVar4 == 0) && iVar5 == 0) && iVar6 == 0) && iVar7 == 0)
                      && iVar8 == 0) && iVar9 == 0) && iVar10 == 0) && iVar11 == 0) && iVar12 == 0)
                 && iVar13 == 0) && iVar14 == 0) && iVar15 == 0) && iVar16 == 0)) {
            pcVar18 = (char *)_Memory[7];
            while (*pcVar18 != '\0') {
              cVar2 = *pcVar18;
              if ((cVar2 < '0') || ('9' < cVar2)) {
                pcVar20 = pcVar18;
                if (cVar2 != ';') goto LAB_0067ecf6;
                do {
                  pcVar1 = pcVar20 + 1;
                  *pcVar20 = *pcVar1;
                  pcVar20 = pcVar1;
                } while (*pcVar1 != '\0');
              }
              else {
                *pcVar18 = cVar2 + -0x30;
LAB_0067ecf6:
                pcVar18 = pcVar18 + 1;
              }
            }
            goto LAB_0067ed28;
          }
          ___free_lconv_mon(_Memory);
          _free(_Memory);
          _free(_Memory_00);
        }
      }
    }
    iVar19 = 1;
  }
  return iVar19;
}


// ==== 0x67ed62 FUN_0067ed62

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0067ed62(void)

{
  BYTE *pBVar1;
  undefined2 *_CchSrc;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *_Memory;
  BOOL BVar5;
  BYTE *pBVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  uint unaff_retaddr;
  _cpinfo local_28;
  undefined4 *local_14;
  undefined2 *local_10;
  void *local_c;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar9 = 0;
  local_c = (void *)0x0;
  if (DAT_00717e90 == 0) {
    PTR_DAT_006ec130 = &DAT_006b08a2;
    DAT_00792fa4 = (undefined2 *)0x0;
    DAT_00792fa8 = (undefined4 *)0x0;
    return 0;
  }
  if ((DAT_00717ea0 != 0) ||
     (iVar3 = FUN_00681f42(0,DAT_00717eb8,0x1004,&DAT_00717ea0), _Memory = local_10, iVar3 == 0)) {
    puVar4 = _malloc(4);
    local_14 = puVar4;
    _Memory = _malloc(0x202);
    local_10 = _Memory;
    local_c = _malloc(0x101);
    if ((puVar4 != (undefined4 *)0x0) &&
       ((_Memory != (undefined2 *)0x0 && (local_c != (void *)0x0)))) {
      *puVar4 = 0;
      iVar3 = 0;
      do {
        *(char *)(iVar3 + (int)local_c) = (char)iVar3;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x100);
      BVar5 = GetCPInfo(DAT_00717ea0,&local_28);
      if ((BVar5 != 0) && (local_28.MaxCharSize < 6)) {
        DAT_006ec180 = local_28.MaxCharSize & 0xffff;
        if ((1 < DAT_006ec180) && (local_28.LeadByte[0] != '\0')) {
          pBVar6 = local_28.LeadByte + 1;
          do {
            bVar2 = *pBVar6;
            if (bVar2 == 0) break;
            for (uVar7 = (uint)pBVar6[-1]; (int)uVar7 <= (int)(uint)bVar2; uVar7 = uVar7 + 1) {
              *(undefined1 *)(uVar7 + (int)local_c) = 0;
              bVar2 = *pBVar6;
            }
            pBVar1 = pBVar6 + 1;
            pBVar6 = pBVar6 + 2;
          } while (*pBVar1 != 0);
        }
        _CchSrc = _Memory + 1;
        BVar5 = ___crtGetStringTypeA
                          ((_locale_t)0x1,(DWORD)local_c,(LPCSTR)0x100,(int)_CchSrc,(LPWORD)0x0,0,0)
        ;
        if (BVar5 != 0) {
          *_Memory = 0;
          if ((1 < (int)DAT_006ec180) && (local_28.LeadByte[0] != '\0')) {
            pBVar6 = local_28.LeadByte + 1;
            do {
              if (*pBVar6 == 0) break;
              uVar7 = (uint)pBVar6[-1];
              if (uVar7 <= *pBVar6) {
                puVar8 = _Memory + uVar7 + 1;
                do {
                  *puVar8 = 0x8000;
                  uVar7 = uVar7 + 1;
                  puVar8 = puVar8 + 1;
                  _Memory = local_10;
                } while ((int)uVar7 <= (int)(uint)*pBVar6);
              }
              pBVar1 = pBVar6 + 1;
              pBVar6 = pBVar6 + 2;
            } while (*pBVar1 != 0);
          }
          DAT_00792fa8 = local_14;
          PTR_DAT_006ec130 = (undefined *)_CchSrc;
          DAT_00792fa4 = _Memory;
          goto LAB_0067eed8;
        }
      }
    }
  }
  _free(local_14);
  _free(_Memory);
  uVar9 = 1;
LAB_0067eed8:
  _free(local_c);
  return uVar9;
}


// ==== 0x67ef25 FUN_0067ef25

undefined4 FUN_0067ef25(void)

{
  return 0;
}


// ==== 0x67ef30 _strcspn

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}


// ==== 0x67ef80 _memset

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}


// ==== 0x67efe0 _strcmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_0067f024;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0067eff0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0067f024;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0067f024;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0067eff0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_0067f024:
  return (uint)bVar5 * -2 + 1;
}


// ==== 0x67f068 _TranslateName

/* Library Function - Single Match
    _TranslateName
   
   Library: Visual Studio 2003 Release */

bool _TranslateName(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = 0;
  iVar2 = 1;
  if (-1 < param_2) {
    do {
      bVar5 = iVar2 == 0;
      iVar2 = 0;
      if (bVar5) break;
      iVar4 = (param_2 + iVar3) / 2;
      puVar1 = (undefined4 *)(param_1 + iVar4 * 8);
      iVar2 = __stricmp((char *)*param_3,(char *)*puVar1);
      if (iVar2 == 0) {
        *param_3 = puVar1 + 1;
      }
      else if (iVar2 < 0) {
        param_2 = iVar4 + -1;
      }
      else {
        iVar3 = iVar4 + 1;
      }
    } while (iVar3 <= param_2);
  }
  return iVar2 == 0;
}


// ==== 0x67f0c8 _GetLcidFromDefault

/* Library Function - Single Match
    _GetLcidFromDefault
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromDefault(void)

{
  DAT_00717e64._0_2_ = (ushort)DAT_00717e64 | 0x104;
  DAT_00717e6c = GetUserDefaultLCID();
  DAT_00717e68 = DAT_00717e6c;
  return;
}


// ==== 0x67f0e2 FUN_0067f0e2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0067f0e2(char *param_1)

{
  int iVar1;
  uint unaff_retaddr;
  undefined4 uVar2;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = _strcmp(param_1,"ACP"), iVar1 == 0)) {
    uVar2 = 0x1004;
  }
  else {
    iVar1 = _strcmp(param_1,"OCP");
    if (iVar1 != 0) goto LAB_0067f149;
    uVar2 = 0xb;
  }
  iVar1 = (*DAT_00717e84)(DAT_00717e6c,uVar2,local_10,8);
  if (iVar1 == 0) {
    return;
  }
  param_1 = local_10;
LAB_0067f149:
  _atol(param_1);
  return;
}


// ==== 0x67f15e FUN_0067f15e

undefined4 FUN_0067f15e(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == *(short *)((int)&DAT_006b129c + uVar1)) {
      return 0;
    }
    uVar1 = uVar1 + 2;
  } while (uVar1 < 0x14);
  return 1;
}


// ==== 0x67f17c FUN_0067f17c

int FUN_0067f17c(uint param_1,LCTYPE param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *_Source;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0x1a;
  do {
    iVar1 = (iVar2 + iVar3) / 2;
    if (param_1 == *(uint *)(&UNK_006b0cb0 + iVar1 * 0x2c)) {
      if (param_2 == 1) {
        _Source = &DAT_006b0cb4 + iVar1 * 0x2c;
      }
      else if (param_2 == 3) {
        _Source = &DAT_006b0cc0 + iVar1 * 0x2c;
      }
      else if (param_2 == 7) {
        _Source = &DAT_006b0cc8 + iVar1 * 0x2c;
      }
      else if (param_2 == 0xb) {
        _Source = &DAT_006b0ccc + iVar1 * 0x2c;
      }
      else if (param_2 == 0x1001) {
        _Source = *(char **)(&UNK_006b0cbc + iVar1 * 0x2c);
      }
      else if (param_2 == 0x1002) {
        _Source = *(char **)(&UNK_006b0cc4 + iVar1 * 0x2c);
      }
      else {
        if (param_2 != 0x1004) break;
        _Source = &DAT_006b0cd4 + iVar1 * 0x2c;
      }
      if ((_Source != (char *)0x0) && (0 < param_4)) {
        _strncpy(param_3,_Source,param_4 - 1);
        param_3[param_4 + -1] = '\0';
        return 1;
      }
      break;
    }
    if (param_1 < *(uint *)(&UNK_006b0cb0 + iVar1 * 0x2c)) {
      iVar2 = iVar1 + -1;
    }
    else {
      iVar3 = iVar1 + 1;
    }
  } while (iVar3 <= iVar2);
  iVar2 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
  return iVar2;
}


// ==== 0x67f25f _LcidFromHexString

/* Library Function - Single Match
    _LcidFromHexString
   
   Library: Visual Studio 2003 Release */

int __fastcall _LcidFromHexString(undefined4 param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = 0;
  while (cVar2 = *param_2, cVar2 != '\0') {
    param_2 = param_2 + 1;
    if ((cVar2 < 'a') || ('f' < cVar2)) {
      if (('@' < cVar2) && (cVar2 < 'G')) {
        cVar2 = cVar2 + -7;
      }
    }
    else {
      cVar2 = cVar2 + -0x27;
    }
    iVar1 = (iVar1 + 0xffffffd) * 0x10 + (int)cVar2;
  }
  return iVar1;
}


// ==== 0x67f294 _GetPrimaryLen

/* Library Function - Single Match
    _GetPrimaryLen
   
   Library: Visual Studio 2003 Release */

int __fastcall _GetPrimaryLen(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    if (((cVar1 < 'A') || ('Z' < cVar1)) && ((cVar1 < 'a' || ('z' < cVar1)))) break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ==== 0x67f2b1 FUN_0067f2b1

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0067f2b1(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint unaff_retaddr;
  char local_80 [120];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00717e84)(uVar1,(-(uint)(DAT_00717e74 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00717e64 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = __stricmp(DAT_00717e78,local_80);
    if (iVar2 == 0) {
      iVar2 = FUN_0067f15e(uVar1);
      if (iVar2 != 0) {
        DAT_00717e64 = DAT_00717e64 | 4;
        DAT_00717e68 = uVar1;
        DAT_00717e6c = uVar1;
      }
    }
    uVar3 = ~(DAT_00717e64 >> 2) & 1;
  }
  return uVar3;
}


// ==== 0x67f34b FUN_0067f34b

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0067f34b(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  size_t sVar4;
  undefined4 uVar5;
  uint unaff_retaddr;
  undefined1 local_80 [120];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = (*DAT_00717e84)(param_1 & 0x3ff | 0x400,1,local_80,0x78);
  if (iVar1 == 0) {
LAB_0067f3ae:
    uVar5 = 0;
  }
  else {
    uVar2 = _LcidFromHexString();
    if ((param_1 != uVar2) && (param_2 != 0)) {
      sVar3 = _strlen(DAT_00717e80);
      sVar4 = _GetPrimaryLen();
      if (sVar4 == sVar3) goto LAB_0067f3ae;
    }
    uVar5 = 1;
  }
  return uVar5;
}


// ==== 0x67f3c2 FUN_0067f3c2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0067f3c2(void)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  uint unaff_retaddr;
  undefined4 uVar4;
  char local_80 [120];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00717e84)(iVar1,(-(uint)(DAT_00717e74 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00717e64 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00717e78,local_80);
  if (iVar2 == 0) {
    iVar2 = (*DAT_00717e84)(iVar1,(-(uint)(DAT_00717e70 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
    if (iVar2 == 0) {
      DAT_00717e64 = 0;
      return 1;
    }
    iVar2 = __stricmp(DAT_00717e80,local_80);
    if (iVar2 == 0) {
      DAT_00717e64 = DAT_00717e64 | 0x304;
      DAT_00717e68 = iVar1;
      DAT_00717e6c = iVar1;
    }
    else if ((DAT_00717e64 & 2) == 0) {
      if ((DAT_00717e7c == 0) ||
         (iVar2 = __strnicmp(DAT_00717e80,local_80,DAT_00717e7c), iVar2 != 0)) {
        if (((DAT_00717e64 & 1) == 0) && (iVar2 = FUN_0067f15e(iVar1), iVar2 != 0)) {
          DAT_00717e64 = DAT_00717e64 | 1;
          DAT_00717e6c = iVar1;
        }
      }
      else {
        DAT_00717e64 = DAT_00717e64 | 2;
        DAT_00717e6c = iVar1;
        sVar3 = _strlen(DAT_00717e80);
        if (sVar3 == DAT_00717e7c) {
          DAT_00717e68 = iVar1;
        }
      }
    }
  }
  if ((DAT_00717e64 & 0x300) == 0x300) goto LAB_0067f5c3;
  iVar2 = (*DAT_00717e84)(iVar1,(-(uint)(DAT_00717e70 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00717e64 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00717e80,local_80);
  if (iVar2 == 0) {
    DAT_00717e64 = DAT_00717e64 | 0x200;
    if (((DAT_00717e70 == 0) && (DAT_00717e7c != 0)) &&
       (sVar3 = _strlen(DAT_00717e80), sVar3 == DAT_00717e7c)) {
      uVar4 = 1;
      goto LAB_0067f5a2;
    }
  }
  else {
    if (((DAT_00717e70 != 0) || (DAT_00717e7c == 0)) ||
       (iVar2 = __strnicmp(DAT_00717e80,local_80,DAT_00717e7c), iVar2 != 0)) goto LAB_0067f5c3;
    uVar4 = 0;
LAB_0067f5a2:
    iVar2 = FUN_0067f34b(iVar1,uVar4);
    if (iVar2 == 0) goto LAB_0067f5c3;
  }
  DAT_00717e64 = DAT_00717e64 | 0x100;
  if (DAT_00717e68 == 0) {
    DAT_00717e68 = iVar1;
  }
LAB_0067f5c3:
  return ~(DAT_00717e64 >> 2) & 1;
}


// ==== 0x67f5e2 FUN_0067f5e2

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0067f5e2(void)

{
  undefined4 uVar1;
  int iVar2;
  uint unaff_retaddr;
  undefined4 uVar3;
  char local_80 [120];
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00717e84)(uVar1,(-(uint)(DAT_00717e70 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00717e64 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00717e80,local_80);
  if (iVar2 == 0) {
    if (DAT_00717e70 == 0) {
      uVar3 = 1;
      goto LAB_0067f677;
    }
  }
  else {
    if (((DAT_00717e70 != 0) || (DAT_00717e7c == 0)) ||
       (iVar2 = __strnicmp(DAT_00717e80,local_80,DAT_00717e7c), iVar2 != 0)) goto LAB_0067f696;
    uVar3 = 0;
LAB_0067f677:
    iVar2 = FUN_0067f34b(uVar1,uVar3);
    if (iVar2 == 0) goto LAB_0067f696;
  }
  DAT_00717e64 = DAT_00717e64 | 4;
  DAT_00717e68 = uVar1;
  DAT_00717e6c = uVar1;
LAB_0067f696:
  return ~(DAT_00717e64 >> 2) & 1;
}


// ==== 0x67f6b3 _GetLcidFromCountry

/* Library Function - Single Match
    _GetLcidFromCountry
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromCountry(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00717e78);
  DAT_00717e74 = (uint)(sVar1 == 3);
  EnumSystemLocalesA(FUN_0067f2b1,1);
  if ((DAT_00717e64 & 4) == 0) {
    DAT_00717e64 = 0;
  }
  return;
}


// ==== 0x67f6ea _GetLcidFromLangCountry

/* Library Function - Single Match
    _GetLcidFromLangCountry
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLangCountry(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00717e80);
  DAT_00717e70 = (uint)(sVar1 == 3);
  sVar1 = _strlen(DAT_00717e78);
  DAT_00717e74 = (uint)(sVar1 == 3);
  DAT_00717e68 = 0;
  if (DAT_00717e70 == 0) {
    DAT_00717e7c = _GetPrimaryLen();
  }
  else {
    DAT_00717e7c = 2;
  }
  EnumSystemLocalesA(FUN_0067f3c2,1);
  if ((((DAT_00717e64 & 0x100) == 0) || ((DAT_00717e64 & 0x200) == 0)) || ((DAT_00717e64 & 7) == 0))
  {
    DAT_00717e64 = 0;
  }
  return;
}


// ==== 0x67f770 _GetLcidFromLanguage

/* Library Function - Single Match
    _GetLcidFromLanguage
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLanguage(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00717e80);
  DAT_00717e70 = (uint)(sVar1 == 3);
  if (sVar1 == 3) {
    DAT_00717e7c = 2;
  }
  else {
    DAT_00717e7c = _GetPrimaryLen();
  }
  EnumSystemLocalesA(FUN_0067f5e2,1);
  if ((DAT_00717e64 & 4) == 0) {
    DAT_00717e64 = 0;
  }
  return;
}


// ==== 0x67f7c5 ___get_qualified_locale

/* Library Function - Single Match
    ___get_qualified_locale
   
   Library: Visual Studio 2003 Release */

BOOL __cdecl ___get_qualified_locale(LPLC_STRINGS _LpInStr,UINT *_LpCodePage,LPLC_STRINGS _LpOutStr)

{
  LCID LVar1;
  undefined2 uVar2;
  int iVar3;
  uint _Value;
  BOOL BVar4;
  
  if (DAT_00717e84 == (code *)0x0) {
    if (DAT_00717a88 == 2) {
      DAT_00717e84 = GetLocaleInfoA_exref;
    }
    else {
      DAT_00717e84 = FUN_0067f17c;
    }
  }
  if (_LpInStr == (LPLC_STRINGS)0x0) {
LAB_0067f89f:
    _GetLcidFromDefault();
LAB_0067f8a4:
    if (DAT_00717e64 == 0) {
      return 0;
    }
  }
  else {
    DAT_00717e78 = _LpInStr->szLanguage + 0x20;
    DAT_00717e80 = _LpInStr;
    if ((DAT_00717e78 != (wchar_t *)0x0) && ((char)*DAT_00717e78 != '\0')) {
      _TranslateName(&PTR_s_america_006b12b0,0x16,&DAT_00717e78);
    }
    DAT_00717e64 = 0;
    if ((DAT_00717e80 == (LPLC_STRINGS)0x0) || ((char)DAT_00717e80->szLanguage[0] == '\0')) {
      if ((DAT_00717e78 == (wchar_t *)0x0) || ((char)*DAT_00717e78 == '\0')) goto LAB_0067f89f;
      _GetLcidFromCountry();
      goto LAB_0067f8a4;
    }
    if ((DAT_00717e78 == (wchar_t *)0x0) || ((char)*DAT_00717e78 == '\0')) {
      _GetLcidFromLanguage();
    }
    else {
      _GetLcidFromLangCountry();
    }
    if (DAT_00717e64 == 0) {
      iVar3 = _TranslateName(&PTR_s_american_006b1460,0x40,&DAT_00717e80);
      if (iVar3 != 0) {
        if ((DAT_00717e78 == (wchar_t *)0x0) || ((char)*DAT_00717e78 == '\0')) {
          _GetLcidFromLanguage();
        }
        else {
          _GetLcidFromLangCountry();
        }
      }
      goto LAB_0067f8a4;
    }
  }
  _Value = FUN_0067f0e2();
  if (((_Value == 0) || (BVar4 = IsValidCodePage(_Value & 0xffff), BVar4 == 0)) ||
     (BVar4 = IsValidLocale(DAT_00717e68,1), LVar1 = DAT_00717e68, BVar4 == 0)) {
LAB_0067f974:
    BVar4 = 0;
  }
  else {
    if (_LpCodePage != (UINT *)0x0) {
      uVar2 = (undefined2)DAT_00717e6c;
      *(short *)_LpCodePage = (short)DAT_00717e68;
      *(undefined2 *)((int)_LpCodePage + 2) = uVar2;
      *(short *)(_LpCodePage + 1) = (short)_Value;
    }
    if (_LpOutStr != (LPLC_STRINGS)0x0) {
      if ((short)*_LpCodePage == 0x814) {
        _strcpy(_LpOutStr,"Norwegian-Nynorsk");
      }
      else {
        iVar3 = (*DAT_00717e84)(LVar1,0x1001,_LpOutStr,0x40);
        if (iVar3 == 0) goto LAB_0067f974;
      }
      iVar3 = (*DAT_00717e84)(DAT_00717e6c,0x1002,_LpOutStr->szLanguage + 0x20,0x40);
      if (iVar3 == 0) goto LAB_0067f974;
      __itoa(_Value,(char *)_LpOutStr->szCountry,10);
    }
    BVar4 = 1;
  }
  return BVar4;
}


// ==== 0x67f980 _memcmp

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;
  
  if (_Size != 0) {
    if ((((uint)_Buf1 | (uint)_Buf2) & 3) == 0) {
      uVar2 = _Size & 3;
      uVar5 = _Size >> 2;
      bVar9 = false;
      puVar7 = _Buf1;
      puVar8 = _Buf2;
      if (uVar5 != 0) {
        do {
          _Buf1 = puVar7;
          _Buf2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          _Buf2 = puVar8 + 1;
          _Buf1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = _Buf1;
          puVar8 = _Buf2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)_Buf1 + -4);
          uVar5 = *(uint *)((int)_Buf2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_0067fa00;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_0067fa00:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_0067fa00;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_0067fa00;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_0067f9b3;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_0067fa00;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_0067f9b3:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_0067fa00;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ==== 0x67fa38 ___crtGetStringTypeA

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 2003 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  int iVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  LPWORD pWVar8;
  undefined1 *puVar9;
  void *_Memory;
  undefined4 uStackY_58;
  BOOL local_24;
  WORD local_20 [2];
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006b1a98;
  uStack_c = 0x67fa44;
  _Memory = (void *)0x0;
  if (DAT_00717ea8 == 0) {
    BVar3 = GetStringTypeW(1,L"",1,local_20);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00717ea8 = 2;
      }
    }
    else {
      DAT_00717ea8 = 1;
    }
  }
  if ((DAT_00717ea8 == 2) || (DAT_00717ea8 == 0)) {
    if (_Code_page == 0) {
      _Code_page = DAT_00717e90;
    }
    if (_LpCharType == (LPWORD)0x0) {
      _LpCharType = DAT_00717ea0;
    }
    pWVar8 = (LPWORD)FUN_0068088e();
    if (pWVar8 != (LPWORD)0xffffffff) {
      if (pWVar8 != _LpCharType) {
        uStackY_58 = 0x67fbbb;
        _Memory = (void *)FUN_006808d7();
        _DWInfoType = (DWORD)_Memory;
        if (_Memory == (void *)0x0) {
          return 0;
        }
      }
      BVar3 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                             (LPWORD)_CchSrc);
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return BVar3;
      }
      return BVar3;
    }
  }
  else if (DAT_00717ea8 == 1) {
    local_24 = 0;
    bVar2 = false;
    if (_LpCharType == (LPWORD)0x0) {
      _LpCharType = DAT_00717ea0;
    }
    uStackY_58 = 0x67fad6;
    iVar5 = MultiByteToWideChar((UINT)_LpCharType,(uint)(_BError != 0) * 8 + 1,(LPCSTR)_DWInfoType,
                                (int)_LpSrcStr,(LPWSTR)0x0,0);
    if (iVar5 != 0) {
      local_8 = (undefined *)0x0;
      puVar6 = (undefined1 *)(iVar5 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar6;
      puVar7 = &stack0xffffffc4 + iVar1;
      local_1c = &stack0xffffffc4 + iVar1;
      *(int *)((int)local_20 + iVar1 + -0x20) = iVar5 * 2;
      *(undefined4 *)(&stack0xffffffbc + iVar1) = 0;
      *(undefined1 **)(&stack0xffffffb8 + iVar1) = &stack0xffffffc4 + iVar1;
      *(undefined4 *)(&stack0xffffffb4 + iVar1) = 0x67fb08;
      _memset(*(void **)(&stack0xffffffb8 + iVar1),*(int *)(&stack0xffffffbc + iVar1),
              *(size_t *)((int)local_20 + iVar1 + -0x20));
      local_8 = (undefined *)0xffffffff;
      if (&stack0xffffffc4 == puVar6) {
        *(int *)((int)local_20 + iVar1 + -0x20) = iVar5;
        *(undefined4 *)(&stack0xffffffbc + iVar1) = 2;
        *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0x67fb32;
        puVar7 = _calloc(*(size_t *)(&stack0xffffffbc + iVar1),
                         *(size_t *)((int)local_20 + iVar1 + -0x20));
        if (puVar7 == (void *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)((int)local_20 + iVar1 + -0x20) = iVar5;
      *(undefined1 **)(&stack0xffffffbc + iVar1) = puVar7;
      *(LPCSTR *)(&stack0xffffffb8 + iVar1) = _LpSrcStr;
      *(DWORD *)(&stack0xffffffb4 + iVar1) = _DWInfoType;
      *(undefined4 *)(&stack0xffffffb0 + iVar1) = 1;
      *(LPWORD *)(&stack0xffffffac + iVar1) = _LpCharType;
      puVar9 = (undefined1 *)((int)&uStackY_58 + iVar1);
      *(undefined4 *)((int)&uStackY_58 + iVar1) = 0x67fb54;
      iVar5 = MultiByteToWideChar(*(UINT *)(&stack0xffffffac + iVar1),
                                  *(DWORD *)(&stack0xffffffb0 + iVar1),
                                  *(LPCSTR *)(&stack0xffffffb4 + iVar1),
                                  *(int *)(&stack0xffffffb8 + iVar1),
                                  *(LPWSTR *)(&stack0xffffffbc + iVar1),
                                  *(int *)((int)local_20 + iVar1 + -0x20));
      puVar6 = puVar9;
      if (iVar5 != 0) {
        *(int *)(puVar9 + -4) = _CchSrc;
        *(int *)(puVar9 + -8) = iVar5;
        *(undefined1 **)(puVar9 + -0xc) = puVar7;
        *(_locale_t *)(puVar9 + -0x10) = _Plocinfo;
        puVar6 = puVar9 + -0x14;
        *(undefined4 *)(puVar9 + -0x14) = 0x67fb66;
        local_24 = GetStringTypeW(*(DWORD *)(puVar9 + -0x10),*(LPCWSTR *)(puVar9 + -0xc),
                                  *(int *)(puVar9 + -8),*(LPWORD *)(puVar9 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar6 + -4) = puVar7;
        *(undefined4 *)(puVar6 + -8) = 0x67fb75;
        _free(*(void **)(puVar6 + -4));
        return local_24;
      }
      return local_24;
    }
  }
  return 0;
}


// ==== 0x67fb11 FUN_0067fb11

undefined4 FUN_0067fb11(void)

{
  return 1;
}


// ==== 0x67fb15 FUN_0067fb15

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0067fb15(void)

{
  void *pvVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar2 + -4) = 0x67fb1d;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(iVar2 + -4) = uVar4;
  *(undefined4 *)(iVar2 + -8) = 2;
  *(undefined4 *)(iVar2 + -0xc) = 0x67fb32;
  pvVar1 = _calloc(*(size_t *)(iVar2 + -8),*(size_t *)(iVar2 + -4));
  if (pvVar1 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(undefined4 *)(iVar2 + -4) = uVar4;
    *(void **)(iVar2 + -8) = pvVar1;
    *(undefined4 *)(iVar2 + -0xc) = *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar2 + -0x14) = 1;
    *(undefined4 *)(iVar2 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
    puVar5 = (undefined1 *)(iVar2 + -0x1c);
    *(undefined4 *)(iVar2 + -0x1c) = 0x67fb54;
    iVar2 = MultiByteToWideChar(*(UINT *)(iVar2 + -0x18),*(DWORD *)(iVar2 + -0x14),
                                *(LPCSTR *)(iVar2 + -0x10),*(int *)(iVar2 + -0xc),
                                *(LPWSTR *)(iVar2 + -8),*(int *)(iVar2 + -4));
    puVar6 = puVar5;
    if (iVar2 != 0) {
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
      *(int *)(puVar5 + -8) = iVar2;
      *(void **)(puVar5 + -0xc) = pvVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x14;
      *(undefined4 *)(puVar5 + -0x14) = 0x67fb66;
      BVar3 = GetStringTypeW(*(DWORD *)(puVar5 + -0x10),*(LPCWSTR *)(puVar5 + -0xc),
                             *(int *)(puVar5 + -8),*(LPWORD *)(puVar5 + -4));
      *(BOOL *)(unaff_EBP + -0x20) = BVar3;
    }
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      *(void **)(puVar6 + -4) = pvVar1;
      *(undefined4 *)(puVar6 + -8) = 0x67fb75;
      _free(*(void **)(puVar6 + -4));
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x67fbf1;
  return uVar4;
}


// ==== 0x67fc00 _strpbrk

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}


// ==== 0x67fc40 FUN_0067fc40

void FUN_0067fc40(void)

{
  __NMSG_WRITE(10);
  _raise(0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ==== 0x67fc58 ___crtMessageBoxA

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 2003 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  int iVar2;
  undefined1 local_14 [8];
  byte local_c;
  undefined1 local_8 [4];
  
  iVar2 = 0;
  if (DAT_00717ed0 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if ((hModule == (HMODULE)0x0) ||
       (DAT_00717ed0 = GetProcAddress(hModule,"MessageBoxA"), DAT_00717ed0 == (FARPROC)0x0)) {
      return 0;
    }
    DAT_00717ed4 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_00717ed8 = GetProcAddress(hModule,"GetLastActivePopup");
    if ((DAT_00717a88 == 2) &&
       (DAT_00717ee0 = GetProcAddress(hModule,"GetUserObjectInformationA"),
       DAT_00717ee0 != (FARPROC)0x0)) {
      DAT_00717edc = GetProcAddress(hModule,"GetProcessWindowStation");
    }
  }
  if ((DAT_00717edc == (FARPROC)0x0) ||
     (((iVar1 = (*DAT_00717edc)(), iVar1 != 0 &&
       (iVar1 = (*DAT_00717ee0)(iVar1,1,local_14,0xc,local_8), iVar1 != 0)) && ((local_c & 1) != 0))
     )) {
    if (((DAT_00717ed4 != (FARPROC)0x0) && (iVar2 = (*DAT_00717ed4)(), iVar2 != 0)) &&
       (DAT_00717ed8 != (FARPROC)0x0)) {
      iVar2 = (*DAT_00717ed8)(iVar2);
    }
  }
  else if (DAT_00717a94 < 4) {
    _UType = _UType | 0x40000;
  }
  else {
    _UType = _UType | 0x200000;
  }
  iVar2 = (*DAT_00717ed0)(iVar2,_LpText,_LpCaption,_UType);
  return iVar2;
}


// ==== 0x67fd51 FUN_0067fd51

void __thiscall FUN_0067fd51(char *param_1,uint param_2,int param_3)

{
  ulonglong uVar1;
  char *pcVar2;
  uint in_EAX;
  char *pcVar3;
  char cVar4;
  
  pcVar2 = param_1;
  if (param_3 != 0) {
    *param_1 = '-';
    param_1 = param_1 + 1;
    in_EAX = -in_EAX;
    pcVar2 = param_1;
  }
  do {
    pcVar3 = pcVar2;
    uVar1 = (ulonglong)in_EAX;
    in_EAX = in_EAX / param_2;
    cVar4 = (char)(uVar1 % (ulonglong)param_2);
    if ((uint)(uVar1 % (ulonglong)param_2) < 10) {
      cVar4 = cVar4 + '0';
    }
    else {
      cVar4 = cVar4 + 'W';
    }
    *pcVar3 = cVar4;
    pcVar2 = pcVar3 + 1;
  } while (in_EAX != 0);
  pcVar3[1] = '\0';
  do {
    cVar4 = *pcVar3;
    *pcVar3 = *param_1;
    pcVar3 = pcVar3 + -1;
    *param_1 = cVar4;
    param_1 = param_1 + 1;
  } while (param_1 < pcVar3);
  return;
}


// ==== 0x67fd8f __itoa

/* Library Function - Single Match
    __itoa
   
   Library: Visual Studio 2003 Release */

char * __cdecl __itoa(int _Value,char *_Dest,int _Radix)

{
  undefined4 uVar1;
  
  if ((_Radix == 10) && (_Value < 0)) {
    uVar1 = 1;
    _Radix = 10;
  }
  else {
    uVar1 = 0;
  }
  FUN_0067fd51(_Radix,uVar1);
  return _Dest;
}


// ==== 0x67fef5 FUN_0067fef5

void FUN_0067fef5(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  LARGE_INTEGER local_14;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  DVar1 = GetCurrentProcessId();
  DVar2 = GetCurrentThreadId();
  DVar3 = GetTickCount();
  QueryPerformanceCounter(&local_14);
  DAT_006eb720 = local_c.dwHighDateTime ^ local_c.dwLowDateTime ^ DVar1 ^ DVar2 ^ DVar3 ^
                 local_14.s.HighPart ^ local_14.s.LowPart;
  if (DAT_006eb720 == 0) {
    DAT_006eb720 = 0xbb40e64e;
  }
  return;
}


// ==== 0x67ff4b FUN_0067ff4b

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_0067ff4b(int param_1)

{
  DWORD DVar1;
  size_t sVar2;
  char *_Dest;
  uint unaff_retaddr;
  CHAR local_12c [260];
  undefined1 local_28;
  char *local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006b1cb0;
  uStack_c = 0x67ff5a;
  local_20 = DAT_006eb720 ^ unaff_retaddr;
  if (DAT_00717ee4 == (code *)0x0) {
    if (param_1 == 1) {
      local_24 = 
      "A buffer overrun has been detected which has corrupted the program\'s\ninternal state.  The program cannot safely continue execution and must\nnow be terminated.\n"
      ;
    }
    else {
      local_24 = 
      "A security error of unknown cause has been detected which has\ncorrupted the program\'s internal state.  The program cannot safely\ncontinue execution and must now be terminated.\n"
      ;
    }
    local_28 = 0;
    DVar1 = GetModuleFileNameA((HMODULE)0x0,local_12c,0x104);
    if (DVar1 == 0) {
      _strcpy();
    }
    _Dest = local_12c;
    sVar2 = _strlen(local_12c);
    if (0x3c < sVar2 + 0xb) {
      sVar2 = _strlen(local_12c);
      _Dest = &stack0xfffffea3 + sVar2;
      _strncpy(_Dest,"...",3);
    }
    _strlen(_Dest);
    local_1c = &stack0xfffffec8;
    _strcpy();
    _strcat();
    _strcat();
    _strcat();
    _strcat(&stack0xfffffec8);
    _strcat(&stack0xfffffec8,local_24);
    ___crtMessageBoxA(&stack0xfffffec8,"Microsoft Visual C++ Runtime Library",0x12010);
  }
  else {
    local_8 = (undefined *)0x0;
    (*DAT_00717ee4)();
    local_8 = (undefined *)0xffffffff;
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ==== 0x67ff86 FUN_0067ff86

undefined4 FUN_0067ff86(void)

{
  return 1;
}


// ==== 0x67ff8a FUN_0067ff8a

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0067ff8a(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 3;
                    /* WARNING: Subroutine does not return */
  *(undefined **)(iVar1 + -8) = &UNK_00680094;
  __exit(*(int *)(iVar1 + -4));
}


// ==== 0x68005e FUN_0068005e

void FUN_0068005e(void)

{
  LPCSTR unaff_ESI;
  
  _strcat();
  _strcat();
  _strcat();
  _strcat();
  ___crtMessageBoxA(unaff_ESI,"Microsoft Visual C++ Runtime Library",0x12010);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ==== 0x68006b FUN_0068006b

void FUN_0068006b(void)

{
  LPCSTR unaff_ESI;
  
  _strcat();
  _strcat();
  ___crtMessageBoxA(unaff_ESI,"Microsoft Visual C++ Runtime Library",0x12010);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


// ==== 0x680095 ___crtInitCritSecNoSpinCount@8

/* Library Function - Single Match
    ___crtInitCritSecNoSpinCount@8
   
   Library: Visual Studio 2003 Release */

undefined4 ___crtInitCritSecNoSpinCount_8(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return 1;
}


// ==== 0x6800a5 ___crtInitCritSecAndSpinCount

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void ___crtInitCritSecAndSpinCount(undefined4 param_1,undefined4 param_2)

{
  HMODULE hModule;
  
  if (DAT_00717ee8 == (code *)0x0) {
    if (DAT_00717a88 != 1) {
      hModule = GetModuleHandleA("kernel32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_00717ee8 = GetProcAddress(hModule,"InitializeCriticalSectionAndSpinCount");
        if (DAT_00717ee8 != (FARPROC)0x0) goto LAB_006800f1;
      }
    }
    DAT_00717ee8 = ___crtInitCritSecNoSpinCount_8;
  }
LAB_006800f1:
  (*DAT_00717ee8)(param_1,param_2);
  return;
}


// ==== 0x680102 FUN_00680102

undefined4 FUN_00680102(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)**(undefined4 **)(unaff_EBP + -0x14);
  return 1;
}


// ==== 0x680110 FUN_00680110

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00680110(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(unaff_EBP + -0x18);
  puVar2 = puVar1;
  if (*(int *)(unaff_EBP + -0x20) == -0x3fffffe9) {
    *(undefined4 *)(puVar1 + -4) = 8;
    puVar2 = puVar1 + -8;
    *(undefined4 *)(puVar1 + -8) = 0x680124;
    SetLastError(*(DWORD *)(puVar1 + -4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(puVar2 + -4) = 0x68012f;
  return 0;
}


// ==== 0x680130 __getbuf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_00717a80 = _DAT_00717a80 + 1;
  pcVar1 = _malloc(0x1000);
  _File->_base = pcVar1;
  if (pcVar1 == (char *)0x0) {
    _File->_flag = _File->_flag | 4;
    _File->_base = (char *)&_File->_charbuf;
    _File->_bufsiz = 2;
  }
  else {
    _File->_flag = _File->_flag | 8;
    _File->_bufsiz = 0x1000;
  }
  _File->_cnt = 0;
  _File->_ptr = _File->_base;
  return;
}


// ==== 0x680174 __isatty

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2003 Release */

int __cdecl __isatty(int _FileHandle)

{
  if (DAT_00793224 <= (uint)_FileHandle) {
    return 0;
  }
  return (int)*(char *)((&DAT_00793240)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x24) & 0x40
  ;
}


// ==== 0x68019e ___wctomb_mt

/* Library Function - Single Match
    ___wctomb_mt
   
   Library: Visual Studio 2003 Release */

int ___wctomb_mt(int param_1,LPSTR param_2,WCHAR param_3)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpMultiByteStr = param_2;
  if (param_2 == (LPSTR)0x0) {
    iVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      if ((ushort)param_3 < 0x100) {
        *param_2 = (CHAR)param_3;
        return 1;
      }
    }
    else {
      param_2 = (LPSTR)0x0;
      iVar1 = WideCharToMultiByte(*(UINT *)(param_1 + 4),0,&param_3,1,lpMultiByteStr,
                                  *(int *)(param_1 + 0x28),(LPCSTR)0x0,(LPBOOL)&param_2);
      if ((iVar1 != 0) && (param_2 == (LPSTR)0x0)) {
        return iVar1;
      }
    }
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x2a;
    iVar1 = -1;
  }
  return iVar1;
}


// ==== 0x6801fe _wctomb

/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 2003 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  undefined2 in_stack_0000000a;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___wctomb_mt(ptVar2,_MbCh,__WCh);
  return iVar3;
}


// ==== 0x680230 __aulldvrm

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined8 __aulldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;
  
  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}


// ==== 0x6802c5 FID_conflict:_ungetc

/* Library Function - Multiple Matches With Different Base Names
    __ungetc_lk
    _ungetc
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__ungetc(int _Ch,FILE *_File)

{
  uint uVar1;
  char *pcVar2;
  
  if (_Ch != -1) {
    uVar1 = _File->_flag;
    if (((uVar1 & 1) != 0) || (((char)uVar1 < '\0' && ((uVar1 & 2) == 0)))) {
      if (_File->_base == (char *)0x0) {
        __getbuf(_File);
      }
      if (_File->_ptr == _File->_base) {
        if (_File->_cnt != 0) {
          return -1;
        }
        _File->_ptr = _File->_ptr + 1;
      }
      _File->_ptr = _File->_ptr + -1;
      pcVar2 = _File->_ptr;
      if ((_File->_flag & 0x40) == 0) {
        *pcVar2 = (char)_Ch;
      }
      else if (*pcVar2 != (char)_Ch) {
        _File->_ptr = pcVar2 + 1;
        return -1;
      }
      _File->_cnt = _File->_cnt + 1;
      _File->_flag = _File->_flag & 0xffffffefU | 1;
      return _Ch & 0xff;
    }
  }
  return -1;
}


// ==== 0x680331 ___mbtowc_mt

/* Library Function - Single Match
    ___mbtowc_mt
   
   Library: Visual Studio 2003 Release */

undefined4 ___mbtowc_mt(int param_1,LPWSTR param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_3 != (byte *)0x0) && (param_4 != 0)) {
    bVar1 = *param_3;
    if (bVar1 != 0) {
      if (*(int *)(param_1 + 0x14) == 0) {
        if (param_2 != (LPWSTR)0x0) {
          *param_2 = (ushort)bVar1;
        }
        return 1;
      }
      if ((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,1,param_2,
                                    (uint)(param_2 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        iVar2 = *(int *)(param_1 + 0x28);
        if ((((1 < iVar2) && (iVar2 <= (int)param_4)) &&
            (iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,iVar2,param_2,
                                         (uint)(param_2 != (LPWSTR)0x0)), iVar2 != 0)) ||
           ((*(uint *)(param_1 + 0x28) <= param_4 && (param_3[1] != 0)))) {
          return *(undefined4 *)(param_1 + 0x28);
        }
      }
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_2 != (LPWSTR)0x0) {
      *param_2 = L'\0';
    }
  }
  return 0;
}


// ==== 0x6803f1 _mbtowc

/* Library Function - Single Match
    _mbtowc
   
   Library: Visual Studio 2003 Release */

int __cdecl _mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___mbtowc_mt(ptVar2,_DstCh,_SrcCh,_SrcSizeInBytes);
  return iVar3;
}


// ==== 0x68041c FUN_0068041c

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

BOOL FUN_0068041c(void)

{
  SIZE_T SVar1;
  BOOL BVar2;
  LPCVOID lpAddress;
  PVOID lpAddress_00;
  undefined4 uStack_5c;
  _SYSTEM_INFO local_4c;
  _MEMORY_BASIC_INFORMATION local_28;
  DWORD local_c;
  SIZE_T local_8;
  
  uStack_5c = 0x68042d;
  SVar1 = VirtualQuery(&uStack_5c,&local_28,0x1c);
  if (SVar1 != 0) {
    GetSystemInfo(&local_4c);
    lpAddress_00 = (PVOID)((~(local_4c.dwPageSize - 1) & (uint)&uStack_5c) - local_4c.dwPageSize);
    local_8 = local_4c.dwPageSize;
    if ((LPVOID)((-(uint)(DAT_00717a88 != 1) & 0xffff1000) + 0x11000 + (int)local_28.AllocationBase)
        <= lpAddress_00) {
      lpAddress = local_28.AllocationBase;
      if (DAT_00717a88 != 1) {
        do {
          SVar1 = VirtualQuery(lpAddress,&local_28,0x1c);
          if (SVar1 == 0) {
            return 0;
          }
          lpAddress = (LPCVOID)((int)lpAddress + local_28.RegionSize);
        } while ((local_28.State & 0x1000) == 0);
        if ((local_28.Protect._1_1_ & 1) != 0) {
          return 1;
        }
        if (lpAddress_00 < local_28.BaseAddress) {
          return 0;
        }
        VirtualAlloc(local_28.BaseAddress,local_8,0x1000,4);
        lpAddress_00 = local_28.BaseAddress;
      }
      BVar2 = VirtualProtect(lpAddress_00,local_8,(-(uint)(DAT_00717a88 != 1) & 0x103) + 1,&local_c)
      ;
      return BVar2;
    }
  }
  return 0;
}


// ==== 0x6804ed __lseeki64_lk

/* Library Function - Single Match
    __lseeki64_lk
   
   Library: Visual Studio 2003 Release */

undefined8 __lseeki64_lk(uint param_1,LONG param_2,LONG param_3,DWORD param_4)

{
  byte *pbVar1;
  HANDLE hFile;
  undefined4 *puVar2;
  DWORD DVar3;
  DWORD DVar4;
  LONG local_8;
  
  local_8 = param_3;
  hFile = (HANDLE)__get_osfhandle(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 9;
LAB_00680547:
    DVar4 = 0xffffffff;
    local_8 = -1;
  }
  else {
    DVar4 = SetFilePointer(hFile,param_2,&local_8,param_4);
    if (DVar4 == 0xffffffff) {
      DVar3 = GetLastError();
      if (DVar3 != 0) {
        __dosmaperr(DVar3);
        goto LAB_00680547;
      }
    }
    pbVar1 = (byte *)((&DAT_00793240)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  return CONCAT44(local_8,DVar4);
}


// ==== 0x680570 __set_osfhnd

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00793224) {
    iVar2 = (param_1 & 0x1fU) * 0x24;
    if (*(int *)(iVar2 + (&DAT_00793240)[param_1 >> 5]) == -1) {
      if (DAT_006eb1b8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_006805c9;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)param_2);
      }
LAB_006805c9:
      *(intptr_t *)(iVar2 + (&DAT_00793240)[param_1 >> 5]) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 9;
  puVar1 = (undefined4 *)___doserrno();
  *puVar1 = 0;
  return -1;
}


// ==== 0x6805ec __free_osfhnd

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00793224) {
    iVar3 = (param_1 & 0x1fU) * 0x24;
    piVar1 = (int *)((&DAT_00793240)[param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_006eb1b8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00680648;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00680648:
      *(undefined4 *)(iVar3 + (&DAT_00793240)[param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 9;
  puVar2 = (undefined4 *)___doserrno();
  *puVar2 = 0;
  return -1;
}


// ==== 0x68066b __get_osfhandle

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2003 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  undefined4 *puVar2;
  
  if (((uint)_FileHandle < DAT_00793224) &&
     (piVar1 = (intptr_t *)((&DAT_00793240)[_FileHandle >> 5] + (_FileHandle & 0x1fU) * 0x24),
     (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  puVar2 = (undefined4 *)__errno();
  *puVar2 = 9;
  puVar2 = (undefined4 *)___doserrno();
  *puVar2 = 0;
  return -1;
}


// ==== 0x6806ac FUN_006806ac

undefined4 FUN_006806ac(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 & 0x1f) * 0x24;
  iVar2 = (&DAT_00793240)[(int)param_1 >> 5] + iVar3;
  if (*(int *)(iVar2 + 8) == 0) {
    __lock(10);
    if (*(int *)(iVar2 + 8) == 0) {
      iVar1 = ___crtInitCritSecAndSpinCount(iVar2 + 0xc,4000);
      if (iVar1 == 0) {
        __unlock(10);
        return 0;
      }
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    }
    __unlock(10);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00793240)[(int)param_1 >> 5] + 0xc + iVar3));
  return 1;
}


// ==== 0x68071f __unlock_fhandle

/* Library Function - Single Match
    __unlock_fhandle
   
   Library: Visual Studio 2003 Release */

void __cdecl __unlock_fhandle(int _Filehandle)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00793240)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x24));
  return;
}


// ==== 0x680741 FUN_00680741

int FUN_00680741(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  int local_4;
  
  iVar4 = -1;
  iVar2 = __mtinitlocknum(0xb);
  if (iVar2 != 0) {
    __lock(0xb);
    local_8 = 0;
    local_4 = 0;
    piVar5 = &DAT_00793240;
    while (puVar3 = (undefined4 *)*piVar5, puVar1 = puVar3, puVar3 != (undefined4 *)0x0) {
      for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
        if ((*(byte *)(puVar3 + 1) & 1) == 0) {
          if (puVar3[2] == 0) {
            __lock(10);
            if (puVar3[2] == 0) {
              iVar2 = ___crtInitCritSecAndSpinCount(puVar3 + 3,4000);
              if (iVar2 == 0) {
                __unlock(10);
                goto LAB_0068087a;
              }
              puVar3[2] = puVar3[2] + 1;
            }
            __unlock(10);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
          if ((*(byte *)(puVar3 + 1) & 1) == 0) {
            *puVar3 = 0xffffffff;
            iVar4 = ((int)puVar3 - *piVar5) / 0x24 + local_4;
            if (iVar4 != -1) goto LAB_0068087d;
            break;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
        }
        puVar1 = (undefined4 *)*piVar5;
      }
      local_4 = local_4 + 0x20;
      local_8 = local_8 + 1;
      piVar5 = piVar5 + 1;
      if (0x79333f < (int)piVar5) goto LAB_0068087d;
    }
    puVar3 = _malloc(0x480);
    if (puVar3 != (undefined4 *)0x0) {
      DAT_00793224 = DAT_00793224 + 0x20;
      (&DAT_00793240)[local_8] = puVar3;
      puVar1 = puVar3;
      for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
        *(undefined1 *)(puVar3 + 1) = 0;
        *puVar3 = 0xffffffff;
        puVar3[2] = 0;
        *(undefined1 *)((int)puVar3 + 5) = 10;
        puVar1 = (undefined4 *)(&DAT_00793240)[local_8];
      }
      iVar4 = local_8 << 5;
      iVar2 = FUN_006806ac(iVar4);
      if (iVar2 == 0) {
LAB_0068087a:
        iVar4 = -1;
      }
    }
LAB_0068087d:
    __unlock(0xb);
  }
  return iVar4;
}


// ==== 0x68088e FUN_0068088e

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long FUN_0068088e(LCID param_1)

{
  int iVar1;
  long lVar2;
  uint unaff_retaddr;
  CHAR local_10 [6];
  undefined1 local_a;
  uint local_8;
  
  local_8 = DAT_006eb720 ^ unaff_retaddr;
  local_a = 0;
  iVar1 = GetLocaleInfoA(param_1,0x1004,local_10,6);
  if (iVar1 == 0) {
    lVar2 = -1;
  }
  else {
    lVar2 = _atol(local_10);
  }
  return lVar2;
}


// ==== 0x6808d7 FUN_006808d7

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

LPSTR FUN_006808d7(UINT param_1,UINT param_2,char *param_3,size_t *param_4,LPSTR param_5,int param_6
                  )

{
  BOOL BVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  uint unaff_retaddr;
  LPCWSTR local_4c;
  size_t local_48;
  _cpinfo local_44;
  int local_30;
  size_t local_2c;
  int local_28;
  LPSTR local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006b1cf8;
  uStack_c = 0x6808e3;
  local_20 = DAT_006eb720 ^ unaff_retaddr;
  local_24 = (LPSTR)0x0;
  local_28 = 0;
  sVar4 = *param_4;
  local_30 = 0;
  local_2c = sVar4;
  if (param_1 != param_2) {
    BVar1 = GetCPInfo(param_1,&local_44);
    if ((((BVar1 != 0) && (local_44.MaxCharSize == 1)) &&
        (BVar1 = GetCPInfo(param_2,&local_44), BVar1 != 0)) && (local_44.MaxCharSize == 1)) {
      local_30 = 1;
    }
    if ((local_30 != 0) && (local_48 = sVar4, sVar4 == 0xffffffff)) {
      sVar2 = _strlen(param_3);
      local_48 = sVar2 + 1;
    }
    if ((local_30 == 0) &&
       (local_48 = MultiByteToWideChar(param_1,1,param_3,sVar4,(LPWSTR)0x0,0), local_48 == 0)) {
      return (LPSTR)0x0;
    }
    local_8 = (undefined *)0x0;
    local_1c = &stack0xffffffa8;
    local_4c = (LPCWSTR)&stack0xffffffa8;
    _memset(&stack0xffffffa8,0,local_48 * 2);
    local_8 = (undefined *)0xffffffff;
    if (&stack0x00000000 == (undefined1 *)0x58) {
      local_4c = _calloc(2,local_48);
      if (local_4c == (LPCWSTR)0x0) {
        return (LPSTR)0x0;
      }
      local_28 = 1;
    }
    iVar3 = MultiByteToWideChar(param_1,1,param_3,local_2c,local_4c,local_48);
    if (iVar3 != 0) {
      if (param_5 == (LPSTR)0x0) {
        if (((local_30 != 0) ||
            (local_48 = WideCharToMultiByte(param_2,0,local_4c,local_48,(LPSTR)0x0,0,(LPCSTR)0x0,
                                            (LPBOOL)0x0), local_48 != 0)) &&
           (local_24 = _calloc(1,local_48), local_24 != (LPSTR)0x0)) {
          sVar4 = WideCharToMultiByte(param_2,0,local_4c,local_48,local_24,local_48,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (sVar4 == 0) {
            _free(local_24);
            local_24 = (LPSTR)0x0;
          }
          else if (local_2c != 0xffffffff) {
            *param_4 = sVar4;
          }
        }
      }
      else {
        iVar3 = WideCharToMultiByte(param_2,0,local_4c,local_48,param_5,param_6,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar3 != 0) {
          local_24 = param_5;
        }
      }
    }
  }
  if (local_28 != 0) {
    _free(local_4c);
  }
  return local_24;
}


// ==== 0x6809ac FUN_006809ac

undefined4 FUN_006809ac(void)

{
  return 1;
}


// ==== 0x6809b0 FUN_006809b0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_006809b0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x6809b8;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x44);
  *(int *)(iVar3 + -4) = iVar4;
  *(undefined4 *)(iVar3 + -8) = 2;
  *(undefined4 *)(iVar3 + -0xc) = 0x6809cf;
  pvVar1 = _calloc(*(size_t *)(iVar3 + -8),*(size_t *)(iVar3 + -4));
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
    goto LAB_00680a92;
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 1;
  *(int *)(iVar3 + -4) = iVar4;
  *(void **)(iVar3 + -8) = pvVar1;
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  puVar6 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x6809f8;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar9 = puVar6;
  if (iVar3 != 0) {
    if (*(int *)(unaff_EBP + 0x18) == 0) {
      puVar8 = puVar6;
      if (*(int *)(unaff_EBP + -0x2c) == 0) {
        *(undefined4 *)(puVar6 + -4) = 0;
        *(undefined4 *)(puVar6 + -8) = 0;
        *(undefined4 *)(puVar6 + -0xc) = 0;
        *(undefined4 *)(puVar6 + -0x10) = 0;
        *(int *)(puVar6 + -0x14) = iVar4;
        *(void **)(puVar6 + -0x18) = pvVar1;
        *(undefined4 *)(puVar6 + -0x1c) = 0;
        *(undefined4 *)(puVar6 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
        puVar8 = puVar6 + -0x24;
        *(undefined4 *)(puVar6 + -0x24) = 0x680a3a;
        iVar4 = WideCharToMultiByte(*(UINT *)(puVar6 + -0x20),*(DWORD *)(puVar6 + -0x1c),
                                    *(LPCWSTR *)(puVar6 + -0x18),*(int *)(puVar6 + -0x14),
                                    *(LPSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),
                                    *(LPCSTR *)(puVar6 + -8),*(LPBOOL *)(puVar6 + -4));
        puVar9 = puVar8;
        if (iVar4 == 0) goto LAB_00680a83;
      }
      *(int *)(puVar8 + -4) = iVar4;
      *(undefined4 *)(puVar8 + -8) = 1;
      *(undefined4 *)(puVar8 + -0xc) = 0x680a48;
      pvVar5 = _calloc(*(size_t *)(puVar8 + -8),*(size_t *)(puVar8 + -4));
      *(void **)(unaff_EBP + -0x20) = pvVar5;
      puVar9 = puVar8;
      if (pvVar5 != (void *)0x0) {
        *(undefined4 *)(puVar8 + -4) = 0;
        *(undefined4 *)(puVar8 + -8) = 0;
        *(int *)(puVar8 + -0xc) = iVar4;
        *(void **)(puVar8 + -0x10) = pvVar5;
        *(int *)(puVar8 + -0x14) = iVar4;
        *(void **)(puVar8 + -0x18) = pvVar1;
        *(undefined4 *)(puVar8 + -0x1c) = 0;
        *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
        puVar9 = puVar8 + -0x24;
        *(undefined4 *)(puVar8 + -0x24) = 0x680a61;
        iVar3 = WideCharToMultiByte(*(UINT *)(puVar8 + -0x20),*(DWORD *)(puVar8 + -0x1c),
                                    *(LPCWSTR *)(puVar8 + -0x18),*(int *)(puVar8 + -0x14),
                                    *(LPSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                    *(LPCSTR *)(puVar8 + -8),*(LPBOOL *)(puVar8 + -4));
        if (iVar3 == 0) {
          *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
          *(undefined4 *)(puVar9 + -8) = 0x680a6d;
          _free(*(void **)(puVar9 + -4));
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
        }
        else if (*(int *)(unaff_EBP + -0x28) != -1) {
          **(int **)(unaff_EBP + 0x14) = iVar3;
        }
      }
    }
    else {
      *(undefined4 *)(puVar6 + -4) = 0;
      *(undefined4 *)(puVar6 + -8) = 0;
      *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
      *(int *)(puVar6 + -0x14) = iVar4;
      *(void **)(puVar6 + -0x18) = pvVar1;
      *(undefined4 *)(puVar6 + -0x1c) = 0;
      *(undefined4 *)(puVar6 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
      puVar7 = puVar6 + -0x24;
      *(undefined4 *)(puVar6 + -0x24) = 0x680a19;
      iVar3 = WideCharToMultiByte(*(UINT *)(puVar6 + -0x20),*(DWORD *)(puVar6 + -0x1c),
                                  *(LPCWSTR *)(puVar6 + -0x18),*(int *)(puVar6 + -0x14),
                                  *(LPSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),
                                  *(LPCSTR *)(puVar6 + -8),*(LPBOOL *)(puVar6 + -4));
      puVar9 = puVar7;
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 0x18);
      }
    }
  }
LAB_00680a83:
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    *(void **)(puVar9 + -4) = pvVar1;
    *(undefined4 *)(puVar9 + -8) = 0x680a8e;
    _free(*(void **)(puVar9 + -4));
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0x20);
LAB_00680a92:
  *(undefined4 *)(unaff_EBP + -0x58) = 0x680aa0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0x680aa5;
  return uVar2;
}


// ==== 0x680aa6 FUN_00680aa6

uint __thiscall
FUN_00680aa6(int param_1,undefined4 *param_2,uint *param_3,LPCSTR param_4,uint param_5,byte param_6)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  HANDLE hFile;
  int *piVar5;
  int iVar6;
  DWORD DVar7;
  int iVar8;
  bool bVar9;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  uint local_c;
  char local_6;
  byte local_5;
  
  bVar9 = -1 < (char)param_5;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar9) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar9;
  if (((param_5 & 0x8000) == 0) && (((param_5 & 0x4000) != 0 || (DAT_00717f00 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar3 = param_5 & 3;
  if (uVar3 == 0) {
    local_14 = 0x80000000;
  }
  else if (uVar3 == 1) {
    local_14 = 0x40000000;
  }
  else {
    if (uVar3 != 2) goto LAB_00680b2d;
    local_14 = 0xc0000000;
  }
  if (param_1 == 0x10) {
    local_c = 0;
  }
  else if (param_1 == 0x20) {
    local_c = 1;
  }
  else if (param_1 == 0x30) {
    local_c = 2;
  }
  else {
    if (param_1 != 0x40) {
LAB_00680b2d:
      puVar4 = (undefined4 *)__errno();
      *puVar4 = 0x16;
      puVar4 = (undefined4 *)___doserrno();
      *puVar4 = 0;
      return 0xffffffff;
    }
    local_c = 3;
  }
  uVar3 = param_5 & 0x700;
  if (uVar3 < 0x401) {
    if ((uVar3 == 0x400) || (uVar3 == 0)) {
      local_10 = 3;
    }
    else if (uVar3 == 0x100) {
      local_10 = 4;
    }
    else {
      if (uVar3 == 0x200) goto LAB_00680bd4;
      if (uVar3 != 0x300) goto LAB_00680bba;
      local_10 = 2;
    }
  }
  else {
    if (uVar3 != 0x500) {
      if (uVar3 == 0x600) {
LAB_00680bd4:
        local_10 = 5;
        goto LAB_00680be4;
      }
      if (uVar3 != 0x700) {
LAB_00680bba:
        puVar4 = (undefined4 *)__errno();
        *puVar4 = 0x16;
        puVar4 = (undefined4 *)___doserrno();
        *puVar4 = 0;
        return 0xffffffff;
      }
    }
    local_10 = 1;
  }
LAB_00680be4:
  DVar7 = 0x80;
  if (((param_5 & 0x100) != 0) && (-1 < (char)(~(byte)DAT_00717a84 & param_6))) {
    DVar7 = 1;
  }
  if ((param_5 & 0x40) != 0) {
    local_14 = CONCAT13(local_14._3_1_,0x10000);
    DVar7 = DVar7 | 0x4000000;
    if (DAT_00717a88 == 2) {
      local_c = local_c | 4;
    }
  }
  if ((param_5 & 0x1000) != 0) {
    DVar7 = DVar7 | 0x100;
  }
  if ((param_5 & 0x20) == 0) {
    if ((param_5 & 0x10) != 0) {
      DVar7 = DVar7 | 0x10000000;
    }
  }
  else {
    DVar7 = DVar7 | 0x8000000;
  }
  uVar3 = FUN_00680741();
  if (uVar3 == 0xffffffff) {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = 0x18;
    puVar4 = (undefined4 *)___doserrno();
    *puVar4 = 0;
  }
  else {
    *param_2 = 1;
    *param_3 = uVar3;
    hFile = CreateFileA(param_4,local_14,local_c,&local_20,local_10,DVar7,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      DVar7 = GetFileType(hFile);
      if (DVar7 != 0) {
        if (DVar7 == 2) {
          local_5 = local_5 | 0x40;
        }
        else if (DVar7 == 3) {
          local_5 = local_5 | 8;
        }
        __set_osfhnd(uVar3,(intptr_t)hFile);
        bVar2 = local_5 | 1;
        iVar8 = (uVar3 & 0x1f) * 0x24;
        local_5 = local_5 & 0x48;
        *(byte *)(iVar8 + 4 + (&DAT_00793240)[(int)uVar3 >> 5]) = bVar2;
        if (((local_5 == 0) && ((char)bVar2 < '\0')) && ((param_5 & 2) != 0)) {
          local_14 = __lseek_lk(uVar3,0xffffffff,2);
          if (local_14 == -1) {
            piVar5 = (int *)___doserrno();
            if (*piVar5 == 0x83) goto LAB_00680d26;
          }
          else {
            local_6 = '\0';
            iVar6 = FUN_00678aac(uVar3,&local_6,1);
            if ((((iVar6 != 0) || (local_6 != '\x1a')) ||
                (iVar6 = FUN_006820f2(uVar3,local_14), iVar6 != -1)) &&
               (iVar6 = __lseek_lk(uVar3,0,0), iVar6 != -1)) goto LAB_00680d26;
          }
          FUN_0067939b(uVar3);
          return 0xffffffff;
        }
LAB_00680d26:
        if (local_5 != 0) {
          return uVar3;
        }
        if ((param_5 & 8) == 0) {
          return uVar3;
        }
        pbVar1 = (byte *)(iVar8 + 4 + (&DAT_00793240)[(int)uVar3 >> 5]);
        *pbVar1 = *pbVar1 | 0x20;
        return uVar3;
      }
      CloseHandle(hFile);
    }
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
  }
  return 0xffffffff;
}


// ==== 0x680d8d __sopen

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __sopen
   
   Library: Visual Studio 2003 Release */

int __cdecl __sopen(char *_Filename,int _OpenFlag,int _ShareFlag,...)

{
  int iVar1;
  undefined4 in_stack_00000010;
  undefined1 local_24 [4];
  undefined4 local_20 [5];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x680d99;
  local_20[0] = 0;
  local_8 = 0;
  iVar1 = FUN_00680aa6(local_20,local_24,_Filename,_OpenFlag,in_stack_00000010);
  local_8 = 0xffffffff;
  FUN_00680dd2();
  return iVar1;
}


// ==== 0x680dd2 FUN_00680dd2

void FUN_00680dd2(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    __unlock_fhandle(*(int *)(unaff_EBP + -0x20));
  }
  return;
}


// ==== 0x680de2 _strncnt

/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _strncnt(char *_String,size_t _Cnt)

{
  char *pcVar1;
  char *in_EAX;
  
  pcVar1 = _String;
  for (; (pcVar1 != (char *)0x0 && (*in_EAX != '\0')); in_EAX = in_EAX + 1) {
    pcVar1 = pcVar1 + -1;
  }
  return (size_t)(_String + (-1 - (int)(pcVar1 + -1)));
}


// ==== 0x680dfe FUN_00680dfe

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

int FUN_00680dfe(LCID param_1,DWORD param_2,byte *param_3,char *param_4,byte *param_5,char *param_6,
                UINT param_7)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  UINT UVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  size_t unaff_EDI;
  byte *_Memory;
  uint unaff_retaddr;
  undefined4 uStackY_7c;
  byte *local_54;
  _cpinfo local_40;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_006b1d18;
  uStack_c = 0x680e0a;
  local_20 = DAT_006eb720 ^ unaff_retaddr;
  _Memory = (byte *)0x0;
  if (DAT_00717ef0 == 0) {
    uStackY_7c = 0x680e33;
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 == 0x78) {
        DAT_00717ef0 = 2;
      }
    }
    else {
      DAT_00717ef0 = 1;
    }
  }
  if (0 < (int)param_4) {
    param_4 = (char *)_strncnt(param_4,unaff_EDI);
  }
  if (0 < (int)param_6) {
    param_6 = (char *)_strncnt(param_6,unaff_EDI);
  }
  if ((DAT_00717ef0 == 2) || (DAT_00717ef0 == 0)) {
    local_54 = (byte *)0x0;
    if (param_1 == 0) {
      param_1 = DAT_00717e90;
    }
    if (param_7 == 0) {
      param_7 = DAT_00717ea0;
    }
    UVar11 = FUN_0068088e();
    if (UVar11 != 0xffffffff) {
      if (UVar11 == param_7) {
LAB_00681144:
        uStackY_7c = 0x68115c;
        iVar1 = CompareStringA(param_1,param_2,(PCNZCH)param_3,(int)param_4,(PCNZCH)param_5,
                               (int)param_6);
        if (_Memory != (byte *)0x0) {
          _free(_Memory);
          _free(local_54);
          return iVar1;
        }
        return iVar1;
      }
      uStackY_7c = 0x68110d;
      _Memory = (byte *)FUN_006808d7();
      if (_Memory != (byte *)0x0) {
        uStackY_7c = 0x681128;
        param_5 = (byte *)FUN_006808d7();
        param_3 = _Memory;
        local_54 = param_5;
        if (param_5 != (byte *)0x0) goto LAB_00681144;
        _free(_Memory);
      }
    }
  }
  else if (DAT_00717ef0 == 1) {
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    if (param_7 == 0) {
      param_7 = DAT_00717ea0;
    }
    if ((param_4 == (char *)0x0) || (param_6 == (char *)0x0)) {
      if (param_4 == param_6) {
        return 2;
      }
      if (1 < (int)param_6) {
        return 1;
      }
      if (1 < (int)param_4) {
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        return 0;
      }
      if (0 < (int)param_4) {
        if (local_40.MaxCharSize < 2) {
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        return 3;
      }
      if (0 < (int)param_6) {
        if (local_40.MaxCharSize < 2) {
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        if (local_40.LeadByte[0] != 0) {
          while( true ) {
            if (pBVar4[1] == 0) {
              return 1;
            }
            if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) break;
            pBVar4 = pBVar4 + 2;
            if (*pBVar4 == 0) {
              return 1;
            }
          }
          return 2;
        }
        return 1;
      }
    }
    uStackY_7c = 0x680f7d;
    iVar1 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,(int)param_4,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      puVar5 = (undefined1 *)(iVar1 * 2 + 3U & 0xfffffffc);
      iVar7 = -(int)puVar5;
      puVar6 = &stack0xffffffa0 + iVar7;
      local_1c = &stack0xffffffa0 + iVar7;
      local_8 = (undefined *)0xffffffff;
      if (&stack0xffffffa0 == puVar5) {
        *(int *)(&stack0xffffff9c + iVar7) = iVar1 * 2;
        *(undefined4 *)(&stack0xffffff98 + iVar7) = 0x680fd5;
        puVar6 = _malloc(*(size_t *)(&stack0xffffff9c + iVar7));
        if (puVar6 == (undefined1 *)0x0) {
          return 0;
        }
        local_24 = 1;
      }
      *(int *)(&stack0xffffff9c + iVar7) = iVar1;
      *(undefined1 **)(&stack0xffffff98 + iVar7) = puVar6;
      *(char **)(&stack0xffffff94 + iVar7) = param_4;
      *(byte **)(&stack0xffffff90 + iVar7) = param_3;
      *(undefined4 *)(&stack0xffffff8c + iVar7) = 1;
      *(UINT *)(&stack0xffffff88 + iVar7) = param_7;
      puVar12 = (undefined1 *)((int)&uStackY_7c + iVar7);
      *(undefined4 *)((int)&uStackY_7c + iVar7) = 0x680ff6;
      iVar7 = MultiByteToWideChar(*(UINT *)(&stack0xffffff88 + iVar7),
                                  *(DWORD *)(&stack0xffffff8c + iVar7),
                                  *(LPCSTR *)(&stack0xffffff90 + iVar7),
                                  *(int *)(&stack0xffffff94 + iVar7),
                                  *(LPWSTR *)(&stack0xffffff98 + iVar7),
                                  *(int *)(&stack0xffffff9c + iVar7));
      puVar5 = puVar12;
      if (iVar7 != 0) {
        *(undefined4 *)(puVar12 + -4) = 0;
        *(undefined4 *)(puVar12 + -8) = 0;
        *(char **)(puVar12 + -0xc) = param_6;
        *(byte **)(puVar12 + -0x10) = param_5;
        *(undefined4 *)(puVar12 + -0x14) = 9;
        *(UINT *)(puVar12 + -0x18) = param_7;
        puVar13 = puVar12 + -0x1c;
        *(undefined4 *)(puVar12 + -0x1c) = 0x681013;
        iVar7 = MultiByteToWideChar(*(UINT *)(puVar12 + -0x18),*(DWORD *)(puVar12 + -0x14),
                                    *(LPCSTR *)(puVar12 + -0x10),*(int *)(puVar12 + -0xc),
                                    *(LPWSTR *)(puVar12 + -8),*(int *)(puVar12 + -4));
        puVar5 = puVar13;
        if (iVar7 != 0) {
          puVar8 = (undefined1 *)(iVar7 * 2 + 3U & 0xfffffffc);
          *(undefined4 *)(puVar13 + -4) = 0x681035;
          iVar10 = -(int)puVar8;
          puVar9 = puVar13 + iVar10;
          puVar5 = puVar13 + iVar10;
          local_1c = puVar13 + iVar10;
          local_8 = (undefined *)0xffffffff;
          if (puVar13 == puVar8) {
            sRamfffffffc = iVar7 * 2;
            uRamfffffff8 = 0x681068;
            puVar9 = _malloc(sRamfffffffc);
            if (puVar9 == (undefined1 *)0x0) goto LAB_006810af;
            local_28 = 1;
          }
          *(int *)(puVar13 + iVar10 + -4) = iVar7;
          *(undefined1 **)(puVar13 + iVar10 + -8) = puVar9;
          *(char **)(puVar13 + iVar10 + -0xc) = param_6;
          *(byte **)(puVar13 + iVar10 + -0x10) = param_5;
          *(undefined4 *)(puVar13 + iVar10 + -0x14) = 1;
          *(UINT *)(puVar13 + iVar10 + -0x18) = param_7;
          puVar14 = puVar13 + iVar10 + -0x1c;
          *(undefined4 *)(puVar13 + iVar10 + -0x1c) = 0x681089;
          iVar10 = MultiByteToWideChar(*(UINT *)(puVar13 + iVar10 + -0x18),
                                       *(DWORD *)(puVar13 + iVar10 + -0x14),
                                       *(LPCSTR *)(puVar13 + iVar10 + -0x10),
                                       *(int *)(puVar13 + iVar10 + -0xc),
                                       *(LPWSTR *)(puVar13 + iVar10 + -8),
                                       *(int *)(puVar13 + iVar10 + -4));
          puVar5 = puVar14;
          if (iVar10 != 0) {
            *(int *)(puVar14 + -4) = iVar7;
            *(undefined1 **)(puVar14 + -8) = puVar9;
            *(int *)(puVar14 + -0xc) = iVar1;
            *(undefined1 **)(puVar14 + -0x10) = puVar6;
            *(DWORD *)(puVar14 + -0x14) = param_2;
            *(LCID *)(puVar14 + -0x18) = param_1;
            puVar5 = puVar14 + -0x1c;
            *(undefined4 *)(puVar14 + -0x1c) = 0x68109f;
            local_2c = CompareStringW(*(LCID *)(puVar14 + -0x18),*(DWORD *)(puVar14 + -0x14),
                                      *(PCNZWCH *)(puVar14 + -0x10),*(int *)(puVar14 + -0xc),
                                      *(PCNZWCH *)(puVar14 + -8),*(int *)(puVar14 + -4));
          }
          if (local_28 != 0) {
            *(undefined1 **)(puVar5 + -4) = puVar9;
            *(undefined4 *)(puVar5 + -8) = 0x6810ae;
            _free(*(void **)(puVar5 + -4));
          }
        }
      }
LAB_006810af:
      if (local_24 != 0) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x6810bd;
        _free(*(void **)(puVar5 + -4));
        return local_2c;
      }
      return local_2c;
    }
  }
  return 0;
}


// ==== 0x680fa9 FUN_00680fa9

undefined4 FUN_00680fa9(void)

{
  return 1;
}


// ==== 0x680fad FUN_00680fad

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

undefined4 FUN_00680fad(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x680fb5;
  FUN_0068041c();
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x40);
  pvVar2 = *(void **)(unaff_EBP + -0x44);
  if (pvVar2 == (void *)0x0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x680fd5;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x44) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      uVar7 = 0;
      goto LAB_00681174;
    }
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(void **)(iVar3 + -8) = pvVar2;
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar8 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x680ff6;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar11 = puVar8;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar8 + -4) = 0;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(puVar8 + -0x14) = 9;
    *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar9 = puVar8 + -0x1c;
    *(undefined4 *)(puVar8 + -0x1c) = 0x681013;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar8 + -0x18),*(DWORD *)(puVar8 + -0x14),
                                *(LPCSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                *(LPWSTR *)(puVar8 + -8),*(int *)(puVar8 + -4));
    *(int *)(unaff_EBP + -0x48) = iVar3;
    puVar11 = puVar9;
    if (iVar3 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 1;
      puVar4 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      *(undefined4 *)(puVar9 + -4) = 0x681035;
      iVar6 = -(int)puVar4;
      puVar5 = puVar9 + iVar6;
      puVar11 = puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x18) = (int)puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x4c) = (int)puVar9 + iVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (puVar9 == puVar4) {
        sRamfffffffc = iVar3 * 2;
        uRamfffffff8 = 0x681068;
        puVar5 = _malloc(sRamfffffffc);
        if (puVar5 == (undefined1 *)0x0) goto LAB_006810af;
        *(undefined4 *)(unaff_EBP + -0x24) = 1;
      }
      *(int *)(puVar9 + iVar6 + -4) = iVar3;
      *(undefined1 **)(puVar9 + iVar6 + -8) = puVar5;
      *(undefined4 *)(puVar9 + iVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar9 + iVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
      *(undefined4 *)(puVar9 + iVar6 + -0x14) = 1;
      *(undefined4 *)(puVar9 + iVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
      puVar10 = puVar9 + iVar6 + -0x1c;
      *(undefined4 *)(puVar9 + iVar6 + -0x1c) = 0x681089;
      iVar6 = MultiByteToWideChar(*(UINT *)(puVar9 + iVar6 + -0x18),
                                  *(DWORD *)(puVar9 + iVar6 + -0x14),
                                  *(LPCSTR *)(puVar9 + iVar6 + -0x10),
                                  *(int *)(puVar9 + iVar6 + -0xc),*(LPWSTR *)(puVar9 + iVar6 + -8),
                                  *(int *)(puVar9 + iVar6 + -4));
      puVar11 = puVar10;
      if (iVar6 != 0) {
        *(int *)(puVar10 + -4) = iVar3;
        *(undefined1 **)(puVar10 + -8) = puVar5;
        *(int *)(puVar10 + -0xc) = iVar1;
        *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(unaff_EBP + -0x44);
        *(undefined4 *)(puVar10 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar10 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar11 = puVar10 + -0x1c;
        *(undefined4 *)(puVar10 + -0x1c) = 0x68109f;
        iVar3 = CompareStringW(*(LCID *)(puVar10 + -0x18),*(DWORD *)(puVar10 + -0x14),
                               *(PCNZWCH *)(puVar10 + -0x10),*(int *)(puVar10 + -0xc),
                               *(PCNZWCH *)(puVar10 + -8),*(int *)(puVar10 + -4));
        *(int *)(unaff_EBP + -0x28) = iVar3;
      }
      if (*(int *)(unaff_EBP + -0x24) != 0) {
        *(undefined1 **)(puVar11 + -4) = puVar5;
        *(undefined4 *)(puVar11 + -8) = 0x6810ae;
        _free(*(void **)(puVar11 + -4));
      }
    }
  }
LAB_006810af:
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(unaff_EBP + -0x44);
    *(undefined4 *)(puVar11 + -8) = 0x6810bd;
    _free(*(void **)(puVar11 + -4));
  }
  uVar7 = *(undefined4 *)(unaff_EBP + -0x28);
LAB_00681174:
  *(undefined4 *)(unaff_EBP + -0x60) = 0x681182;
  *(undefined4 *)(unaff_EBP + -100) = 0x681187;
  return uVar7;
}


