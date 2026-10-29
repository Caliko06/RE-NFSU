// ==== 0x571050 DrawRaceCarList

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render V (G+C) docs/re/blur.md */

void DrawRaceCarList(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_218;
  undefined1 local_210 [256];
  undefined1 local_110 [268];
  
  iVar1 = *(int *)(param_1 + 0x40);
  _DAT_0073462c = 0;
  if (DAT_007361f8 != (int *)0x0) {
    piVar7 = (int *)*DAT_007361f8;
    local_218 = 99;
    if (piVar7 != DAT_007361f8) {
      do {
        if ((((*(int **)(iVar1 + 0x280) == piVar7) || ((char)piVar7[0x134] == '\0')) ||
            (iVar5 = FUN_00570b90(param_1), iVar5 != 0)) ||
           (((1 << ((byte)*(undefined4 *)(param_1 + 4) & 0x1f) & piVar7[0x14d]) == 0 ||
            (local_218 < 1)))) {
          if (piVar7[6] != 0) {
            iVar5 = *(int *)(piVar7[6] + 0x18);
            puVar2 = (undefined4 *)(&DAT_007404a4)[iVar5 * 0x18];
            if (((puVar2 != &DAT_007404a4 + iVar5 * 0x18) && (puVar2 != (undefined4 *)0x0)) &&
               (puVar2 != (undefined4 *)0x4)) {
              if ((puVar2 == &DAT_007404a4 + iVar5 * 0x18) || (puVar2 == (undefined4 *)0x0)) {
                piVar6 = (int *)0x0;
              }
              else {
                piVar6 = puVar2 + -1;
              }
              cVar4 = (**(code **)(*piVar6 + 0x24))();
              if (cVar4 == '\0') {
                FUN_00571440(piVar7[0x135],piVar7);
              }
            }
          }
        }
        else {
          iVar5 = piVar7[0x135];
          FUN_00571440(iVar5,piVar7);
          local_218 = local_218 + -1;
          CallNTimes(local_110,0x40,4,FUN_004ad8d0);
          CallNTimes(local_210,0x40,4,FUN_004ad8d0);
          FUN_0042a120(piVar7);
          piVar3 = piVar7 + 0x138;
          piVar6 = piVar7 + 0x148;
          if ((piVar7[0x14c] & 1 << ((byte)*(undefined4 *)(param_1 + 4) & 0x1f)) == 0) {
            piVar3 = piVar7 + 0x24;
            piVar6 = piVar7 + 0x14;
          }
          CarRenderInfo__Render
                    (iVar5,param_1,piVar6,piVar3,local_110,local_210,0,0,0,DAT_0073460c,DAT_00734608
                     ,0);
          if (((DAT_007361bc == 0) ||
              (((iVar5 = DAT_007361bc, *(int *)(param_1 + 4) != *(int *)(DAT_007361bc + 0x18) &&
                ((DAT_007361c0 == 0 ||
                 (iVar5 = DAT_007361c0, *(int *)(param_1 + 4) != *(int *)(DAT_007361c0 + 0x18)))))
               || (iVar5 = *(int *)(iVar5 + 0x60), iVar5 == 0)))) || ((iVar5 != 6 && (iVar5 != 7))))
          {
            FUN_00429ba0(param_1);
          }
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != DAT_007361f8);
    }
  }
  return;
}


// ==== 0x571250 FUN_00571250

void FUN_00571250(void)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_EAX + 0x4d4);
  if ((int *)(iVar4 + 0x19ac) != (int *)0x0) {
    iVar1 = *(int *)(iVar4 + 0x19ac);
    piVar3 = *(int **)(iVar4 + 0x19b0);
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
  }
  if (DAT_006f1d40 != 0) {
    piVar3 = (int *)(iVar4 + 0x19e0);
    iVar4 = DAT_006f1d40;
    do {
      iVar1 = *piVar3;
      piVar2 = (int *)piVar3[1];
      piVar3 = piVar3 + 0x1a;
      iVar4 = iVar4 + -1;
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    } while (iVar4 != 0);
  }
  return;
}


// ==== 0x5712a0 FUN_005712a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005712a0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  float fVar6;
  uint uVar7;
  char *pcVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_2 + 0x4d4);
  puVar1 = (undefined4 *)(iVar4 + 0x19ac);
  pcVar8 = (char *)(iVar4 + 0x19b4);
  iVar12 = (int)"Car Lights" - (int)pcVar8;
  iVar11 = 0x1f;
  do {
    cVar3 = pcVar8[iVar12];
    iVar11 = iVar11 + -1;
    *pcVar8 = cVar3;
    uVar7 = DAT_006f1d40;
    if (cVar3 == '\0') break;
    pcVar8 = pcVar8 + 1;
  } while (iVar11 != 0);
  uVar13 = 0;
  *(undefined1 *)(iVar4 + 0x19d3) = 0;
  *(undefined4 *)(iVar4 + 0x19d4) = 1;
  if (uVar7 != 0) {
    pfVar9 = (float *)FUN_004081f0();
    pfVar10 = (float *)FUN_0041f5e0();
    do {
      piVar2 = (int *)(uVar13 * 0x68 + 0x19e0 + iVar4);
      puVar5 = *(undefined4 **)(iVar4 + 0x19dc);
      *puVar5 = piVar2;
      *(int **)(iVar4 + 0x19dc) = piVar2;
      piVar2[1] = (int)puVar5;
      *piVar2 = iVar4 + 0x19d8;
      piVar2[2] = 0;
      *(undefined1 *)(piVar2 + 3) = 3;
      *(undefined1 *)((int)piVar2 + 0xd) = 2;
      *(undefined1 *)((int)piVar2 + 0xe) = 0;
      *(undefined1 *)((int)piVar2 + 0xf) = 1;
      piVar2[4] = 0;
      piVar2[5] = (&DAT_006f1d34)[uVar13];
      piVar2[9] = (&DAT_006f1d0c)[uVar13];
      fVar6 = _K_ONE;
      if (uVar13 != 0) {
        fVar6 = -1.0;
      }
      piVar2[10] = (int)(fVar6 * *pfVar9);
      fVar6 = _K_ONE;
      if (uVar13 != 0) {
        fVar6 = -1.0;
      }
      piVar2[0xb] = (int)(fVar6 * pfVar9[1]);
      fVar6 = _K_ONE;
      if (uVar13 != 0) {
        fVar6 = -1.0;
      }
      uVar13 = uVar13 + 1;
      piVar2[0xc] = (int)(fVar6 * pfVar9[2]);
      piVar2[6] = (int)(*(float *)(uVar13 * 4 + 0x6f1d28) * (float)piVar2[10] + *pfVar10);
      piVar2[7] = (int)(*(float *)(uVar13 * 4 + 0x6f1d28) * (float)piVar2[0xb] + pfVar10[1]);
      piVar2[8] = (int)(*(float *)(uVar13 * 4 + 0x6f1d28) * (float)piVar2[0xc] + pfVar10[2]);
      piVar2[0xd] = (&DAT_006f1d10)[uVar13];
      piVar2[0xe] = (&DAT_0073464c)[uVar13];
      piVar2[0xf] = (int)(float)*(ushort *)((int)&DAT_006f1d38 + uVar13 * 2 + 2);
      piVar2[0x10] = *(int *)(uVar13 * 4 + 0x6f1d20);
    } while (uVar13 < DAT_006f1d40);
  }
  if (puVar1 != (undefined4 *)0x0) {
    *DAT_00743c14 = puVar1;
    puVar5 = puVar1;
    *(undefined4 **)(iVar4 + 0x19b0) = DAT_00743c14;
    DAT_00743c14 = puVar5;
    *puVar1 = &DAT_00743c10;
  }
  return;
}


// ==== 0x571440 FUN_00571440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571440(undefined4 param_1,int param_2)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  uint uVar6;
  
  uVar3 = DAT_006f1d40;
  uVar6 = 0;
  if (DAT_006f1d40 != 0) {
    pfVar4 = (float *)FUN_004081f0();
    pfVar5 = (float *)FUN_0041f5e0();
    do {
      iVar1 = uVar6 * 0x68 + 0x19e0 + *(int *)(param_2 + 0x4d4);
      *(undefined4 *)(iVar1 + 0x14) = (&DAT_006f1d34)[uVar6];
      *(undefined4 *)(iVar1 + 0x24) = (&DAT_006f1d0c)[uVar6];
      fVar2 = _K_ONE;
      if (uVar6 != 0) {
        fVar2 = -1.0;
      }
      *(float *)(iVar1 + 0x28) = fVar2 * *pfVar4;
      fVar2 = _K_ONE;
      if (uVar6 != 0) {
        fVar2 = -1.0;
      }
      *(float *)(iVar1 + 0x2c) = fVar2 * pfVar4[1];
      fVar2 = _K_ONE;
      if (uVar6 != 0) {
        fVar2 = -1.0;
      }
      uVar6 = uVar6 + 1;
      *(float *)(iVar1 + 0x30) = fVar2 * pfVar4[2];
      *(float *)(iVar1 + 0x18) =
           *(float *)(iVar1 + 0x28) * *(float *)(uVar6 * 4 + 0x6f1d28) + *pfVar5;
      *(float *)(iVar1 + 0x1c) =
           *(float *)(uVar6 * 4 + 0x6f1d28) * *(float *)(iVar1 + 0x2c) + pfVar5[1];
      *(float *)(iVar1 + 0x20) =
           *(float *)(iVar1 + 0x30) * *(float *)(uVar6 * 4 + 0x6f1d28) + pfVar5[2];
      *(undefined4 *)(iVar1 + 0x34) = (&DAT_006f1d10)[uVar6];
      *(undefined4 *)(iVar1 + 0x38) = (&DAT_0073464c)[uVar6];
      *(float *)(iVar1 + 0x3c) = (float)*(ushort *)((int)&DAT_006f1d38 + uVar6 * 2 + 2);
      *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(uVar6 * 4 + 0x6f1d20);
      *(undefined2 *)(iVar1 + 0x44) = 0;
    } while (uVar6 < uVar3);
  }
  return;
}


// ==== 0x571560 FUN_00571560

void __fastcall FUN_00571560(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00734610;
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    piVar1 = (int *)*param_1;
    *param_1 = *piVar1;
    if ((int *)param_1[1] == piVar1) {
      param_1[1] = (int)param_1;
    }
    iVar2 = *(int *)(iVar3 + 0x18);
    *piVar1 = *(undefined4 *)(iVar3 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(int **)(iVar3 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x5715a0 FUN_005715a0

void FUN_005715a0(void)

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
    FUN_0056a0d0();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x5715d0 FUN_005715d0

undefined4 __thiscall FUN_005715d0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *in_EAX;
  int iVar6;
  int *piVar7;
  
  if (*(int *)(param_1 + 8) == 0) {
    iVar6 = Solid_FindInAllLists();
    if (iVar6 == 0) {
      return 0;
    }
    FUN_0053f470();
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
    in_EAX[0xc] = 0;
    in_EAX[0xd] = 0;
    in_EAX[0xe] = 0;
    in_EAX[0xf] = 0x3f800000;
    iVar6 = Sections__FindSectionBySolid(param_2);
    if (iVar6 != 0) {
      Placement__UnpackMatrix();
      uVar1 = *(undefined4 *)(iVar6 + 0x18);
      uVar2 = *(undefined4 *)(iVar6 + 0x10);
      in_EAX[0xd] = *(undefined4 *)(iVar6 + 0x14);
      in_EAX[0xc] = uVar2;
      in_EAX[0xf] = 0x3f800000;
      in_EAX[0xe] = uVar1;
      iVar6 = FUN_00445c60();
      piVar7 = (int *)(iVar6 + 0x24);
      iVar6 = 6;
      do {
        piVar3 = (int *)*piVar7;
        if (piVar3 != (int *)0x0) {
          if ((piVar3[2] != 0) || (piVar3[3] != 0)) {
            iVar4 = *piVar3;
            piVar5 = (int *)piVar3[1];
            *piVar5 = iVar4;
            *(int **)(iVar4 + 4) = piVar5;
          }
          piVar3[3] = 0;
          piVar3[2] = 0;
          piVar3[4] = 0;
          piVar3[5] = 0;
        }
        piVar7 = piVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return 1;
}


// ==== 0x5716b0 FUN_005716b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005716b0(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_0073c1cc;
  iVar1 = DAT_0073c1c8;
  if ((DAT_0073c1d0 != 0) || (DAT_0073c1d4 != 0)) {
    *DAT_0073c1cc = DAT_0073c1c8;
    *(int **)(iVar1 + 4) = piVar2;
  }
  piVar2 = DAT_0073c1b4;
  iVar1 = DAT_0073c1b0;
  DAT_0073c1d4 = 0;
  DAT_0073c1d0 = 0;
  _DAT_0073c1d8 = 0;
  _DAT_0073c1dc = 0;
  _DAT_0073c220 = 0x3f800000;
  _DAT_0073c224 = 0;
  _DAT_0073c228 = 0;
  _DAT_0073c22c = 0;
  _DAT_0073c230 = 0;
  _DAT_0073c234 = 0x3f800000;
  _DAT_0073c238 = 0;
  _DAT_0073c23c = 0;
  _DAT_0073c240 = 0;
  _DAT_0073c244 = 0;
  _DAT_0073c248 = 0x3f800000;
  _DAT_0073c24c = 0;
  _DAT_0073c250 = 0;
  _DAT_0073c254 = 0;
  _DAT_0073c258 = 0;
  _DAT_0073c25c = 0x3f800000;
  if ((DAT_0073c1b8 != 0) || (DAT_0073c1bc != 0)) {
    *DAT_0073c1b4 = DAT_0073c1b0;
    *(int **)(iVar1 + 4) = piVar2;
  }
  DAT_0073c1bc = 0;
  DAT_0073c1b8 = 0;
  _DAT_0073c1c0 = 0;
  _DAT_0073c1c4 = 0;
  _DAT_0073c1e0 = 0x3f800000;
  _DAT_0073c1e4 = 0;
  _DAT_0073c1e8 = 0;
  _DAT_0073c1ec = 0;
  _DAT_0073c1f0 = 0;
  _DAT_0073c1f4 = 0x3f800000;
  _DAT_0073c1f8 = 0;
  _DAT_0073c1fc = 0;
  _DAT_0073c200 = 0;
  _DAT_0073c204 = 0;
  _DAT_0073c208 = 0x3f800000;
  _DAT_0073c20c = 0;
  _DAT_0073c210 = 0;
  _DAT_0073c214 = 0;
  _DAT_0073c218 = 0;
  _DAT_0073c21c = 0x3f800000;
  return;
}


// ==== 0x571870 CarOverlays_QueueByView

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void __fastcall CarOverlays_QueueByView(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 < 1) || (3 < iVar1)) {
    if ((9 < iVar1) && ((iVar1 < 0x10 && (DAT_006f1a78 != 0)))) {
      FUN_0040c910(param_1,&DAT_0073c1b0,&DAT_0073c1e0,0,0);
    }
  }
  else if (DAT_006eef60 != 0) {
    FUN_0040c910(param_1,&DAT_0073c1c8,&DAT_0073c220,0,0);
    return;
  }
  return;
}


// ==== 0x5718d0 FUN_005718d0

void __fastcall FUN_005718d0(int param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  if (-1 < param_1) {
    iVar3 = 0;
    cVar2 = DAT_006f1a18;
    while (cVar2 != '\0') {
      pcVar1 = &DAT_006f1a19 + iVar3;
      iVar3 = iVar3 + 1;
      cVar2 = *pcVar1;
    }
    if (iVar3 + -1 < param_1) {
      param_1 = 0;
      cVar2 = DAT_006f1a18;
      while (cVar2 != '\0') {
        pcVar1 = &DAT_006f1a19 + param_1;
        param_1 = param_1 + 1;
        cVar2 = *pcVar1;
      }
      param_1 = param_1 + -1;
    }
    (&DAT_006f1a18)[param_1] = 0x20;
  }
  return;
}


// ==== 0x571920 FUN_00571920

void FUN_00571920(char param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_00571ea0(0,"bRepeat");
  if (param_1 == '\0') {
    *(undefined4 *)(unaff_EDI + 0x28) = 0;
    FUN_00571c20(unaff_ESI,unaff_EDI + 0x10,4,4,1);
    FUN_00571c20(unaff_ESI,unaff_EDI + 0x24,4,4,1);
    iVar3 = 0;
    if (0 < *(int *)(unaff_EDI + 0x18)) {
      iVar2 = unaff_EDI + 0x4c;
      do {
        FUN_00571c20(unaff_ESI,iVar2 + -4,4,4,1);
        FUN_00571c20(unaff_ESI,iVar2,4,4,1);
        FUN_00571c20(unaff_ESI,iVar2 + 4,4,4,1);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x24;
      } while (iVar3 < *(int *)(unaff_EDI + 0x18));
    }
  }
  else {
    FUN_00571c20(unaff_ESI,unaff_EDI + 8,4,4,1);
    FUN_00571c20(unaff_ESI,unaff_EDI + 0x20,4,4,1);
    iVar3 = 0;
    if (0 < *(int *)(unaff_EDI + 0x18)) {
      iVar2 = unaff_EDI + 0x40;
      do {
        FUN_00571c20(unaff_ESI,iVar2 + -4,4,4,1);
        FUN_00571c20(unaff_ESI,iVar2,4,4,1);
        FUN_00571c20(unaff_ESI,iVar2 + 4,4,4,1);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x24;
      } while (iVar3 < *(int *)(unaff_EDI + 0x18));
    }
  }
  iVar3 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar3 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar3 + 0xc);
  cVar1 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x571a40 FUN_00571a40

void __fastcall FUN_00571a40(char *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int in_EAX;
  char *pcVar4;
  
  cVar2 = *param_1;
  pcVar1 = (char *)(in_EAX + 8);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar4 = pcVar1;
    do {
      cVar2 = pcVar4[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined4 *)(in_EAX + 0x28) = DAT_0073ad34;
  uVar3 = DAT_006f08a4;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  *(undefined4 *)(in_EAX + 0x38) = 0;
  *(undefined1 *)(in_EAX + 0x3c) = 0;
  *(undefined1 *)(in_EAX + 0x3d) = 0;
  *(undefined1 *)(in_EAX + 0x3e) = 0;
  *(undefined1 *)(in_EAX + 0x3f) = 0;
  *(undefined1 *)(in_EAX + 0x41) = 0;
  *(undefined2 *)(in_EAX + 0x42) = 0;
  *(undefined4 *)(in_EAX + 0x48) = 0;
  *(undefined4 *)(in_EAX + 0x14c) = 0;
  *(undefined4 *)(in_EAX + 0x150) = 0;
  *(undefined4 *)(in_EAX + 0x154) = 0;
  *(undefined4 *)(in_EAX + 0x30) = uVar3;
  *(undefined1 *)(in_EAX + 0x40) = 0xff;
  *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  return;
}


// ==== 0x571ab0 FUN_00571ab0

int __fastcall FUN_00571ab0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = -1;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = iVar1 * 0x21 + (uint)*(byte *)(iVar2 + unaff_ESI);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return iVar1;
}


// ==== 0x571ae0 FUN_00571ae0

void FUN_00571ae0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  
  iVar3 = *(int *)(param_1 + 0x150);
  if (iVar3 + param_3 < 0x9400) {
    iVar2 = 0;
    cVar4 = '\0';
    if (0 < param_3) {
      do {
        cVar4 = *(char *)(iVar2 + param_2);
        *(char *)(iVar3 + 0x158 + param_1) = cVar4;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
    }
    if (iVar2 < param_4) {
      cVar5 = '\0';
      if (param_5 != 0) {
        cVar5 = cVar4 >> 7;
      }
      do {
        if (*(char *)(iVar2 + param_2) != cVar5) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_4);
    }
  }
  else if (*(char *)(param_1 + 0x41) == '\0') {
    *(undefined1 *)(param_1 + 0x41) = 1;
    *(int *)(param_1 + 0x150) = iVar3;
    return;
  }
  *(int *)(param_1 + 0x150) = iVar3;
  return;
}


// ==== 0x571ba0 FUN_00571ba0

void __fastcall FUN_00571ba0(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = *(int *)(param_3 + 0x150);
  if (iVar5 + in_EAX <= *(int *)(param_3 + 0x154)) {
    iVar3 = 0;
    cVar4 = '\0';
    if (0 < in_EAX) {
      do {
        cVar4 = *(char *)(iVar5 + 0x158 + param_3);
        iVar5 = iVar5 + 1;
        *(char *)(iVar3 + param_2) = cVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < in_EAX);
    }
    if (iVar3 < param_1) {
      cVar1 = '\0';
      if (param_4 != 0) {
        cVar1 = cVar4 >> 7;
      }
      pcVar6 = (char *)(param_2 + iVar3);
      for (uVar2 = (uint)(param_1 - iVar3) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(uint *)pcVar6 = CONCAT22(CONCAT11(cVar1,cVar1),CONCAT11(cVar1,cVar1));
        pcVar6 = pcVar6 + 4;
      }
      for (uVar2 = param_1 - iVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + 1;
      }
    }
  }
  *(int *)(param_3 + 0x150) = iVar5;
  return;
}


// ==== 0x571c20 FUN_00571c20

void FUN_00571c20(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  char *pcVar2;
  code *pcVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_4;
  
  if (param_4 == -1) {
    param_4 = param_3;
  }
  iVar6 = *(char *)(param_1 + 0x40) * 0x10;
  iVar5 = iVar6 + 0x4c + param_1;
  *(char *)(iVar5 + 10) = *(char *)(iVar6 + 0x56 + param_1) + '\x01';
  if (*(char *)(param_1 + 0x3c) != '\0') {
    FUN_00571ae0(param_1,param_2,param_3,param_4,param_5);
    return;
  }
  if (*(char *)(param_1 + 0x3d) != '\0') {
    FUN_00571ba0(param_1,param_5);
    return;
  }
  if (*(char *)(param_1 + 0x3e) == '\0') {
    if (*(char *)(param_1 + 0x3f) != '\0') {
      sVar4 = FUN_00571ab0(param_1,param_4);
      FUN_00571ba0(param_1,0);
      if ((sVar4 != (short)local_4) && (*(char *)(iVar5 + 0xb) == '\0')) {
        *(undefined1 *)(iVar5 + 0xb) = 1;
        FUN_00571f60();
        iVar5 = (int)*(char *)(param_1 + 0x40);
        iVar6 = iVar5;
        for (; local_4 = iVar5, -1 < iVar5; iVar5 = iVar5 + -1) {
          iVar8 = 0;
          if (-1 < iVar6) {
            puVar7 = (undefined4 *)(param_1 + 0x4c);
            do {
              if ((iVar8 == iVar5) && (puVar7[1] != 0)) {
                FUN_005718d0();
                iVar5 = local_4;
              }
              pcVar2 = (char *)*puVar7;
              iVar6 = 0;
              if (pcVar2 != (char *)0x0) {
                cVar1 = *pcVar2;
                while (cVar1 != '\0') {
                  iVar6 = iVar6 + 1;
                  cVar1 = pcVar2[iVar6];
                }
              }
              iVar6 = (int)*(char *)(param_1 + 0x40);
              iVar8 = iVar8 + 1;
              puVar7 = puVar7 + 4;
            } while (iVar8 <= iVar6);
          }
        }
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    return;
  }
  local_4 = FUN_00571ab0(param_1,param_4);
  FUN_00571ae0(param_1,&local_4,2,2,0);
  return;
}


// ==== 0x571d90 FUN_00571d90

void FUN_00571d90(void)

{
  int in_EAX;
  undefined4 unaff_EDI;
  char local_1;
  
  local_1 = '\0';
  if ((((*(float *)(in_EAX + 0xc) == 0.0) && (*(float *)(in_EAX + 0x1c) == 0.0)) &&
      (*(float *)(in_EAX + 0x2c) == 0.0)) &&
     ((*(int *)(in_EAX + 0x3c) == 0x3f800000 &&
      (((*(float *)(in_EAX + 0x30) != 0.0 || (*(float *)(in_EAX + 0x34) != 0.0)) ||
       (local_1 = '\x01', *(float *)(in_EAX + 0x38) != 0.0)))))) {
    local_1 = '\x02';
  }
  FUN_00571c20(unaff_EDI,&local_1,1,1,1);
  if (local_1 == '\0') {
    FUN_00571c20(unaff_EDI,in_EAX,0x40,0xffffffff,0);
    return;
  }
  FUN_00571c20(unaff_EDI,in_EAX,0xc,0xffffffff,0);
  FUN_00571c20(unaff_EDI,in_EAX + 0x10,0xc,0xffffffff,0);
  FUN_00571c20(unaff_EDI,in_EAX + 0x20,0xc,0xffffffff,0);
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined4 *)(in_EAX + 0x3c) = 0x3f800000;
  if (local_1 == '\x02') {
    FUN_00571c20(unaff_EDI,in_EAX + 0x30,0xc,0xffffffff,0);
    return;
  }
  *(undefined4 *)(in_EAX + 0x30) = 0;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  *(undefined4 *)(in_EAX + 0x38) = 0;
  return;
}


// ==== 0x571ea0 FUN_00571ea0

void __thiscall FUN_00571ea0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x40) == -1) {
    *(undefined2 *)(param_1 + 0x42) = 0;
  }
  cVar2 = *(char *)(param_1 + 0x40) + '\x01';
  *(char *)(param_1 + 0x40) = cVar2;
  puVar1 = (undefined4 *)(cVar2 * 0x10 + 0x4c + param_1);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 0x42);
  *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
  *puVar1 = param_3;
  puVar1[1] = param_2;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  puVar1[3] = *(undefined4 *)(param_1 + 0x150);
  if (((-1 < *(int *)(param_1 + 0x44)) &&
      (*(int *)(param_1 + 0x44) <= (int)*(char *)(param_1 + 0x40))) &&
     (DAT_006f08a4 == *(int *)(param_1 + 0x48))) {
    FUN_00571f60();
    FUN_005718d0();
  }
  return;
}


// ==== 0x571f20 FUN_00571f20

void FUN_00571f20(void)

{
  int iVar1;
  int in_EAX;
  char cVar2;
  
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar1 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x571f60 FUN_00571f60

int __fastcall FUN_00571f60(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar3 = 0;
  iVar5 = 0;
  if (-1 < *(char *)(param_1 + 0x40)) {
    puVar6 = (undefined4 *)(param_1 + 0x4c);
    do {
      if (iVar5 != 0) {
        iVar3 = iVar3 + 1;
      }
      pcVar2 = (char *)*puVar6;
      iVar4 = 0;
      if (pcVar2 != (char *)0x0) {
        cVar1 = *pcVar2;
        while (cVar1 != '\0') {
          iVar4 = iVar4 + 1;
          cVar1 = pcVar2[iVar4];
        }
      }
      iVar3 = iVar3 + iVar4;
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 4;
    } while (iVar5 <= *(char *)(param_1 + 0x40));
  }
  return iVar3;
}


// ==== 0x571fa0 FUN_00571fa0

void FUN_00571fa0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  puVar1 = unaff_ESI + 0x1a;
  *puVar1 = puVar1;
  unaff_ESI[0x1b] = puVar1;
  puVar2 = unaff_ESI + 0x1c;
  *puVar2 = puVar2;
  unaff_ESI[0x1d] = puVar2;
  unaff_ESI[0x14] = 0xffffffff;
  unaff_ESI[0x15] = 0xffffffff;
  unaff_ESI[0x29] = 0xffffffff;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x26] = 0x41700000;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[7] = 9999999;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x24] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x102c] = 0;
  unaff_ESI[0x102d] = 0;
  puVar4 = unaff_ESI + 0x102e;
  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (DAT_0073c17c != '\0') {
    unaff_ESI[0x19] = DAT_0073c1a4;
    DAT_0073c1a4 = 0;
    if ((undefined4 **)DAT_0073c1a8 != &DAT_0073c1a8) {
      puVar4 = (undefined4 *)unaff_ESI[0x1d];
      *DAT_0073c1ac = puVar2;
      DAT_0073c1a8[1] = puVar4;
      *puVar4 = DAT_0073c1a8;
      unaff_ESI[0x1d] = DAT_0073c1ac;
      DAT_0073c1a8 = &DAT_0073c1a8;
      DAT_0073c1ac = &DAT_0073c1a8;
    }
    unaff_ESI[0x1e] = 1;
    iVar3 = 0;
    do {
      puVar2 = _malloc(0x9558);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2[10] = 0;
        puVar2[0xb] = 0;
      }
      puVar4 = (undefined4 *)unaff_ESI[0x1b];
      *puVar4 = puVar2;
      unaff_ESI[0x1b] = puVar2;
      puVar2[1] = puVar4;
      *puVar2 = puVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)unaff_ESI[0x1e]);
  }
  return;
}


// ==== 0x5720f0 FUN_005720f0

void FUN_005720f0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685fb6;
  piVar2 = *(int **)(param_1 + 0x70);
  piVar1 = (int *)(param_1 + 0x70);
  local_4 = 1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2[0xe] == 0) {
      _free(piVar2);
    }
    else {
      *DAT_0073c1ac = (int)piVar2;
      piVar4 = piVar2;
      piVar2[1] = (int)DAT_0073c1ac;
      DAT_0073c1ac = piVar4;
      *piVar2 = (int)&DAT_0073c1a8;
      if (*(int *)(param_1 + 100) != 0) {
        DAT_0073c1a4 = *(int *)(param_1 + 100);
        *(undefined4 *)(param_1 + 100) = 0;
      }
    }
    piVar2 = (int *)*piVar1;
  }
  piVar2 = (int *)(param_1 + 0x68);
  piVar4 = *(int **)(param_1 + 0x68);
  while (piVar4 != piVar2) {
    piVar4 = (int *)*piVar2;
    iVar3 = *piVar4;
    piVar5 = (int *)piVar4[1];
    *piVar5 = iVar3;
    *(int **)(iVar3 + 4) = piVar5;
    _free(piVar4);
    piVar4 = (int *)*piVar2;
  }
  if (*(int *)(param_1 + 100) != 0) {
    FUN_00565ce0();
  }
  piVar4 = (int *)*piVar1;
  while (piVar4 != piVar1) {
    iVar3 = *piVar4;
    piVar5 = (int *)piVar4[1];
    *piVar5 = iVar3;
    *(int **)(iVar3 + 4) = piVar5;
    _free(piVar4);
    piVar4 = (int *)*piVar1;
  }
  piVar1 = (int *)*piVar2;
  while (piVar1 != piVar2) {
    iVar3 = *piVar1;
    piVar4 = (int *)piVar1[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    _free(piVar1);
    piVar1 = (int *)*piVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x5721f0 FUN_005721f0

void FUN_005721f0(void)

{
  int *in_EAX;
  uint uVar1;
  
  if (in_EAX[1] != 0) {
    FUN_00572380();
    if (in_EAX[1] != 0) {
      FUN_00572690();
    }
  }
  if (*in_EAX != 0) {
    if (in_EAX[4] == 0) {
      if (in_EAX[5] != 0) {
        uVar1 = DAT_00734574 & 0x80000003;
        if ((int)uVar1 < 0) {
          uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
        }
        in_EAX[6] = (uint)(uVar1 != 0);
      }
    }
    else {
      in_EAX[6] = 1;
    }
    FUN_00572ac0();
  }
  FUN_005722d0();
  FUN_00572530(in_EAX);
  FUN_005734a0(&DAT_0073c17c);
  return;
}


// ==== 0x572280 FUN_00572280

uint __fastcall FUN_00572280(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  
  uVar1 = *(uint *)(param_1 + 0xac);
  uVar2 = 0;
  if ((uVar1 != 0) && (*(int *)(param_1 + 0xb0 + uVar1 * 4) < unaff_ESI)) {
    uVar2 = uVar1;
  }
  if ((int)uVar2 < *(int *)(param_1 + 0xa8)) {
    piVar3 = (int *)(param_1 + 0xb0 + uVar2 * 4);
    do {
      if (*piVar3 == unaff_ESI) {
        *(uint *)(param_1 + 0xac) = uVar2;
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while ((int)uVar2 < *(int *)(param_1 + 0xa8));
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x5722d0 FUN_005722d0

int * FUN_005722d0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *in_EAX;
  int *piVar4;
  int iVar5;
  
  bVar3 = false;
  piVar4 = (int *)0x0;
  if ((((*in_EAX != 0) && (piVar4 = (int *)in_EAX[6], piVar4 == (int *)0x0)) &&
      (DAT_006f08a4 != in_EAX[0x29])) && (piVar4 = (int *)FUN_00572280(), (char)piVar4 != '\0')) {
    bVar3 = true;
  }
  if (in_EAX[1] != 0) {
    piVar4 = (int *)(DAT_006f08a4 / 0xd3);
    if (DAT_006f08a4 % 0xd3 == 0) {
      bVar3 = true;
    }
    if ((in_EAX[1] != 0) && (piVar4 = (int *)(in_EAX[0x29] + 0x1e), (int)piVar4 < DAT_006f08a4))
    goto LAB_00572339;
  }
  if (!bVar3) {
    return piVar4;
  }
LAB_00572339:
  iVar5 = FUN_00572f20("DUMMY_SNAPSHOT");
  piVar4 = (int *)0x0;
  if ((iVar5 != 0) && (piVar4 = (int *)FUN_00572b50("DUMMY_SNAPSHOT",0), piVar4 != (int *)0x0)) {
    iVar5 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar5;
    *(int **)(iVar5 + 4) = piVar1;
    puVar2 = (undefined4 *)in_EAX[0x1b];
    *puVar2 = piVar4;
    in_EAX[0x1b] = (int)piVar4;
    piVar4[1] = (int)puVar2;
    *piVar4 = (int)(in_EAX + 0x1a);
  }
  return piVar4;
}


// ==== 0x572380 FUN_00572380

void FUN_00572380(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  
  if (DAT_006f08a0 < *(int *)(in_EAX + 0x4c)) {
    return;
  }
  *(int *)(in_EAX + 0x4c) = DAT_006f08a0 + 300;
  if ((*(int *)(in_EAX + 0x8c) == 0) || (*(int *)(in_EAX + 0x8c) < *(int *)(in_EAX + 0x7c)))
  goto LAB_00572510;
  iVar5 = FUN_00572b50("INSTANT_REPLAY",0);
  iVar9 = 0;
  piVar8 = (int *)0x0;
  piVar10 = (int *)0x0;
  if (0 < *(int *)(in_EAX + 0x88)) {
    do {
      if (iVar9 < *(int *)(in_EAX + 0x94)) {
        piVar6 = (int *)FUN_00572b50("HIGHLIGHT_SNAPSHOT",iVar9);
        piVar8 = piVar6;
        if (*(int *)(iVar5 + 0x30) < piVar6[0xd]) break;
        if ((piVar10 == (int *)0x0) ||
           (piVar8 = piVar10, (float)piVar6[0x53] < (float)piVar10[0x53])) {
          piVar8 = piVar6;
        }
      }
      else {
        piVar8 = (int *)0x0;
      }
      iVar9 = iVar9 + 1;
      piVar10 = piVar8;
    } while (iVar9 < *(int *)(in_EAX + 0x88));
  }
  if ((*(float *)(iVar5 + 0x14c) <= 0.0) ||
     ((piVar8 != (int *)0x0 && (*(float *)(iVar5 + 0x14c) <= (float)piVar8[0x53])))) {
    piVar8 = (int *)FUN_00572b50("INSTANT_REPLAY",0);
    if (piVar8 != (int *)0x0) {
      iVar5 = *piVar8;
      piVar10 = (int *)piVar8[1];
      *piVar10 = iVar5;
      *(int **)(iVar5 + 4) = piVar10;
      puVar3 = *(undefined4 **)(in_EAX + 0x6c);
      *puVar3 = piVar8;
      *(int **)(in_EAX + 0x6c) = piVar8;
      piVar8[1] = (int)puVar3;
      *piVar8 = in_EAX + 0x68;
    }
    *(int *)(in_EAX + 0x8c) = *(int *)(in_EAX + 0x8c) + -1;
    goto LAB_00572510;
  }
  if (*(int *)(in_EAX + 0x94) == *(int *)(in_EAX + 0x88)) {
    iVar9 = *piVar8;
    piVar10 = (int *)piVar8[1];
    *piVar10 = iVar9;
    *(int **)(iVar9 + 4) = piVar10;
    puVar3 = *(undefined4 **)(in_EAX + 0x6c);
    *puVar3 = piVar8;
    *(int **)(in_EAX + 0x6c) = piVar8;
    piVar8[1] = (int)puVar3;
    *piVar8 = in_EAX + 0x68;
LAB_00572490:
    *(int *)(in_EAX + 0x94) = *(int *)(in_EAX + 0x94) + -1;
  }
  else if ((piVar8 != (int *)0x0) && (*(int *)(iVar5 + 0x30) < piVar8[0xd])) {
    FUN_00572d60(in_EAX);
    goto LAB_00572490;
  }
  pcVar1 = (char *)(iVar5 + 8);
  *pcVar1 = 'H';
  pcVar7 = pcVar1;
  do {
    cVar2 = pcVar7[(int)("HIGHLIGHT_SNAPSHOT" + (1 - (int)pcVar1))];
    pcVar7 = pcVar7 + 1;
    *pcVar7 = cVar2;
    uVar4 = DAT_006f08a4;
  } while (cVar2 != '\0');
  *(undefined4 *)(iVar5 + 0x2c) = DAT_0073ad34;
  *(undefined4 *)(iVar5 + 0x34) = uVar4;
  *(int *)(in_EAX + 0x8c) = *(int *)(in_EAX + 0x8c) + -1;
  *(int *)(in_EAX + 0x94) = *(int *)(in_EAX + 0x94) + 1;
LAB_00572510:
  iVar5 = FUN_00572f20("INSTANT_REPLAY");
  if (iVar5 != 0) {
    *(int *)(in_EAX + 0x8c) = *(int *)(in_EAX + 0x8c) + 1;
  }
  return;
}


// ==== 0x572530 FUN_00572530

void FUN_00572530(undefined4 param_1)

{
  int iVar1;
  undefined1 local_20 [32];
  
  iVar1 = 0;
  do {
    if (DAT_006f08a4 == (&DAT_006f1a08)[iVar1]) {
      if (-1 < iVar1) {
        FUN_00565da0("CHECKSUM%d",iVar1);
        FUN_00572590(param_1,local_20);
      }
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return;
}


// ==== 0x572590 FUN_00572590

void FUN_00572590(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (param_1[1] == 0) {
    if ((*param_1 != 0) && (param_1[6] == 0)) {
      iVar5 = FUN_00572b50(param_2,0);
      if (iVar5 != 0) {
        *(undefined4 *)(iVar5 + 0x150) = 0;
        *(undefined1 *)(iVar5 + 0x3f) = 1;
        FUN_00572d90(param_1);
        *(undefined1 *)(iVar5 + 0x3f) = 0;
      }
    }
  }
  else {
    iVar5 = FUN_00572b50(param_2,0);
    if (iVar5 != 0) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if ((int *)param_1[0x1a] == param_1 + 0x1a) {
      puVar6 = _malloc(0x9558);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6[10] = 0;
        puVar6[0xb] = 0;
      }
      puVar1 = (undefined4 *)param_1[0x1b];
      *puVar1 = puVar6;
      param_1[0x1b] = (int)puVar6;
      puVar6[1] = puVar1;
      *puVar6 = param_1 + 0x1a;
    }
    piVar2 = (int *)param_1[0x1a];
    if (piVar2 != param_1 + 0x1a) {
      iVar5 = *piVar2;
      piVar3 = (int *)piVar2[1];
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
      piVar3 = (int *)param_1[0x1d];
      *piVar3 = (int)piVar2;
      param_1[0x1d] = (int)piVar2;
      *piVar2 = (int)(param_1 + 0x1c);
      piVar2[1] = (int)piVar3;
      FUN_00571a40();
      piVar2[0x54] = 0;
      *(undefined1 *)((int)piVar2 + 0x3e) = 1;
      FUN_00572d90(param_1);
      *(undefined1 *)((int)piVar2 + 0x3e) = 0;
      piVar2[0x55] = piVar2[0x54];
      return;
    }
  }
  return;
}


// ==== 0x572690 FUN_00572690

void FUN_00572690(void)

{
  int *piVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = *(int *)(in_EAX + 0x90);
  fVar3 = (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x5c)) * 0.00025;
  fVar4 = (float)iVar7 * *(float *)(in_EAX + 0x98);
  if (fVar4 < fVar3 != (fVar4 == fVar3)) {
    while (iVar7 == *(int *)(in_EAX + 0x84)) {
      iVar7 = 0;
      *(float *)(in_EAX + 0x98) = *(float *)(in_EAX + 0x98) + *(float *)(in_EAX + 0x98);
      iVar5 = FUN_00572b50("LAP_SNAPSHOT",0);
      while (iVar5 != 0) {
        iVar7 = iVar7 + 1;
        piVar6 = (int *)FUN_00572b50("LAP_SNAPSHOT",iVar7);
        if (piVar6 != (int *)0x0) {
          iVar5 = *piVar6;
          piVar1 = (int *)piVar6[1];
          *piVar1 = iVar5;
          *(int **)(iVar5 + 4) = piVar1;
          puVar2 = *(undefined4 **)(in_EAX + 0x6c);
          *puVar2 = piVar6;
          *(int **)(in_EAX + 0x6c) = piVar6;
          piVar6[1] = (int)puVar2;
          *piVar6 = in_EAX + 0x68;
          *(int *)(in_EAX + 0x90) = *(int *)(in_EAX + 0x90) + -1;
        }
        iVar5 = FUN_00572b50("LAP_SNAPSHOT",iVar7);
      }
      iVar7 = *(int *)(in_EAX + 0x90);
      if (*(int *)(in_EAX + 0x84) <= iVar7) {
        return;
      }
      fVar3 = (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x5c)) * 0.00025;
      fVar4 = (float)*(int *)(in_EAX + 0x90) * *(float *)(in_EAX + 0x98);
      if (fVar4 < fVar3 == (fVar4 == fVar3)) {
        return;
      }
    }
    iVar7 = FUN_00572f20("LAP_SNAPSHOT");
    if (iVar7 != 0) {
      *(int *)(in_EAX + 0x90) = *(int *)(in_EAX + 0x90) + 1;
    }
  }
  return;
}


// ==== 0x5727b0 FUN_005727b0

void FUN_005727b0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[1] != 0) {
    unaff_ESI[0x15] = DAT_006f08a4 + 1;
    iVar1 = _ftol_nocw();
    unaff_ESI[0x18] = iVar1 + DAT_0073ad34;
    unaff_ESI[1] = 0;
    return;
  }
  if (*unaff_ESI != 0) {
    *unaff_ESI = 0;
    unaff_ESI[6] = 0;
  }
  return;
}


// ==== 0x572800 FUN_00572800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00572800(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x20);
  if (((iVar1 == 0) && (DAT_0073459c != 0)) && (DAT_006f08a4 == *(int *)(in_EAX + 0x1c) + -1)) {
    *(undefined4 *)(in_EAX + 0x20) = 1;
    *(undefined1 *)(in_EAX + 0x2c) = 0xab;
    *(undefined1 *)(in_EAX + 0x2d) = 0;
    *(undefined1 *)(in_EAX + 0x2e) = 0;
    *(undefined1 *)(in_EAX + 0x2f) = 0;
    *(undefined1 *)(in_EAX + 0x30) = 0;
    *(undefined1 *)(in_EAX + 0x31) = 0;
    *(undefined1 *)(in_EAX + 0x32) = 4;
    *(undefined1 *)(in_EAX + 0x33) = 0;
    *(undefined1 *)(in_EAX + 0x34) = 0;
    *(undefined1 *)(in_EAX + 0x35) = 0;
    *(undefined1 *)(in_EAX + 0x36) = 0;
    *(undefined1 *)(in_EAX + 0x37) = 4;
    *(undefined1 *)(in_EAX + 0x38) = 0;
    *(undefined1 *)(in_EAX + 0x39) = 0;
    *(undefined1 *)(in_EAX + 0x3a) = 0;
    *(undefined1 *)(in_EAX + 0x3b) = 0;
    *(undefined1 *)(in_EAX + 0x3c) = 4;
    *(undefined1 *)(in_EAX + 0x3d) = 0;
    *(undefined1 *)(in_EAX + 0x3e) = 0;
    *(undefined1 *)(in_EAX + 0x3f) = 0;
    *(undefined1 *)(in_EAX + 0x40) = 0;
    *(undefined1 *)(in_EAX + 0x41) = 0;
    *(undefined1 *)(in_EAX + 0x42) = 0;
    *(undefined1 *)(in_EAX + 0x43) = 9;
    *(undefined4 *)(in_EAX + 0x24) = 0;
    *(undefined4 *)(in_EAX + 0x28) = 0x18;
    return;
  }
  if (iVar1 == 1) {
    *(undefined4 *)(in_EAX + 0x20) = 2;
    DAT_0073459c = 0;
    return;
  }
  if (iVar1 == 2) {
    if ((DAT_006f08a4 == *(int *)(in_EAX + 0x54)) && (*(int *)(in_EAX + 0x10) != 0)) {
      *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + 0xd3;
      FUN_00572d20();
      FUN_00572d20();
      FUN_00572d20();
      FUN_00572d20();
      DAT_006f1a08 = DAT_006f08a4 + 1;
      DAT_006f1a0c = DAT_006f08a4 + 0x34;
      _DAT_006f1a10 = DAT_006f08a4 + 0x69;
      _DAT_006f1a14 = DAT_006f08a4 + 0x9e;
      *(undefined1 *)(in_EAX + 0x2c) = 0x7b;
      *(undefined1 *)(in_EAX + 0x2d) = 0;
      *(undefined1 *)(in_EAX + 0x2e) = 0;
      *(undefined1 *)(in_EAX + 0x2f) = 0;
      *(undefined1 *)(in_EAX + 0x30) = 0;
      *(undefined1 *)(in_EAX + 0x31) = 0;
      *(undefined1 *)(in_EAX + 0x32) = 0;
      *(undefined1 *)(in_EAX + 0x33) = 0;
      *(undefined1 *)(in_EAX + 0x34) = 0;
      *(undefined1 *)(in_EAX + 0x35) = 0;
      *(undefined1 *)(in_EAX + 0x36) = 0;
      *(undefined1 *)(in_EAX + 0x37) = 0;
      *(undefined1 *)(in_EAX + 0x38) = 9;
      *(undefined4 *)(in_EAX + 0x24) = 0;
      *(undefined4 *)(in_EAX + 0x28) = 0xd;
      *(undefined4 *)(in_EAX + 0x20) = 3;
      return;
    }
  }
  else if ((iVar1 == 3) && (*(int *)(in_EAX + 0x28) <= *(int *)(in_EAX + 0x24))) {
    DAT_0073459c = 1;
    *(undefined4 *)(in_EAX + 0x20) = 0;
  }
  return;
}


// ==== 0x572970 FUN_00572970

void FUN_00572970(float param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_EAX;
  char *pcVar4;
  
  if (*(int *)(in_EAX + 4) != 0) {
    for (puVar3 = *(undefined4 **)(in_EAX + 0x70); puVar3 != (undefined4 *)(in_EAX + 0x70);
        puVar3 = (undefined4 *)*puVar3) {
      pcVar4 = "INSTANT_REPLAY";
      do {
        cVar1 = *(char *)((int)(puVar3 + -0x1b2b62) + (int)pcVar4);
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 == cVar2) {
        puVar3[0x53] = param_1 + (float)puVar3[0x53];
      }
    }
  }
  return;
}


// ==== 0x5729d0 FUN_005729d0

uint FUN_005729d0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    uVar3 = DAT_006f08a4 + 1;
    *(uint *)(unaff_ESI + 0xa0) = uVar3;
    *(undefined4 *)(unaff_ESI + 0x10) = 1;
    return uVar3 & 0xffffff00;
  }
  iVar1 = *(int *)(unaff_ESI + 0x9c);
  uVar3 = FUN_00572b50("HIGHLIGHT_SNAPSHOT",iVar1);
  if (uVar3 == 0) {
    uVar4 = FUN_00572b50("LAP_SNAPSHOT",0);
    uVar3 = uVar4;
    if (uVar4 == 0) {
      *(undefined4 *)(unaff_ESI + 0xa0) = 0;
    }
    else {
      *(undefined4 *)(unaff_ESI + 0xa0) = *(undefined4 *)(unaff_ESI + 0x54);
    }
  }
  else {
    uVar2 = *(undefined4 *)(uVar3 + 0x34);
    iVar1 = iVar1 + 1;
    *(int *)(unaff_ESI + 0x9c) = iVar1;
    *(undefined4 *)(unaff_ESI + 0xa0) = uVar2;
    uVar4 = FUN_00572b50("HIGHLIGHT_SNAPSHOT",iVar1);
    if (uVar4 != 0) goto LAB_00572a5b;
  }
  *(undefined4 *)(unaff_ESI + 0x9c) = 0;
LAB_00572a5b:
  if (uVar3 == 0) {
    return uVar4 & 0xffffff00;
  }
  *(undefined4 *)(uVar3 + 0x150) = 0;
  *(undefined1 *)(uVar3 + 0x3d) = 1;
  FUN_00572d90(unaff_ESI);
  *(undefined1 *)(uVar3 + 0x3d) = 0;
  iVar1 = DAT_006f08a4;
  *(int *)(unaff_ESI + 0xa4) = DAT_006f08a4;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x572a90 FUN_00572a90

void FUN_00572a90(void)

{
  FUN_00494b90();
  return;
}


// ==== 0x572ac0 FUN_00572ac0

void FUN_00572ac0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  if (*(int *)(unaff_EBX + 0x40b0) != 0) {
    iVar3 = *(int *)(unaff_EBX + 0x40b4);
    if (-1 < iVar3) {
      piVar1 = (int *)(iVar3 * 0x10 + 0x40bc + unaff_EBX);
      do {
        if (*piVar1 < DAT_006f08a4) {
          if (-1 < iVar3) goto LAB_00572afc;
          break;
        }
        iVar3 = iVar3 + -1;
        piVar1 = piVar1 + -4;
      } while (-1 < iVar3);
    }
    iVar3 = 0;
LAB_00572afc:
    if (iVar3 < *(int *)(unaff_EBX + 0x40b0)) {
      piVar1 = (int *)(iVar3 * 0x10 + 0x40bc + unaff_EBX);
      iVar2 = DAT_006f08a4;
      do {
        if (iVar2 < *piVar1) break;
        if (*piVar1 == iVar2) {
          FUN_00494b90();
          iVar2 = DAT_006f08a4;
        }
        iVar3 = iVar3 + 1;
        piVar1 = piVar1 + 4;
      } while (iVar3 < *(int *)(unaff_EBX + 0x40b0));
    }
    iVar2 = *(int *)(unaff_EBX + 0x40b0) + -1;
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    *(int *)(unaff_EBX + 0x40b4) = iVar3;
  }
  return;
}


// ==== 0x572b50 FUN_00572b50

undefined4 * FUN_00572b50(char *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_EAX;
  char *pcVar4;
  
  puVar3 = *(undefined4 **)(in_EAX + 0x70);
  do {
    if (puVar3 == (undefined4 *)(in_EAX + 0x70)) {
      return (undefined4 *)0x0;
    }
    pcVar4 = param_1;
    do {
      cVar1 = pcVar4[(int)puVar3 + (8 - (int)param_1)];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      if (param_2 == 0) {
        return puVar3;
      }
      param_2 = param_2 + -1;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x572bb0 FUN_00572bb0

bool FUN_00572bb0(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x30) <= *(int *)(param_2 + 0x30);
}


// ==== 0x572bd0 FUN_00572bd0

void __fastcall FUN_00572bd0(int param_1)

{
  int ***pppiVar1;
  int ***pppiVar2;
  int ****ppppiVar3;
  undefined4 unaff_EDI;
  int ***local_20;
  int ***local_1c;
  void *local_14;
  code *pcStack_10;
  undefined4 local_c;
  
  pcStack_10 = FUN_00685168;
  local_14 = ExceptionList;
  local_20 = (int ***)&local_20;
  local_1c = (int ***)&local_20;
  local_c = 0;
  ExceptionList = &local_14;
  ppppiVar3 = (int ****)FUN_00572b50(unaff_EDI,0);
  while (ppppiVar3 != (int ****)0x0) {
    pppiVar1 = *ppppiVar3;
    pppiVar2 = ppppiVar3[1];
    *pppiVar2 = (int **)pppiVar1;
    pppiVar1[1] = (int **)pppiVar2;
    *local_1c = (int **)ppppiVar3;
    ppppiVar3[1] = local_1c;
    *ppppiVar3 = (int ***)&local_20;
    local_1c = (int ***)ppppiVar3;
    ppppiVar3 = (int ****)FUN_00572b50(unaff_EDI,0);
  }
  bList__Sort(&local_20,FUN_00572bb0);
  if ((int ****)local_20 != &local_20) {
    pppiVar1 = *(int ****)(param_1 + 0x74);
    *local_1c = (int **)(param_1 + 0x70);
    local_20[1] = (int **)pppiVar1;
    *pppiVar1 = (int **)local_20;
    *(int ****)(param_1 + 0x74) = local_1c;
    ExceptionList = local_14;
    return;
  }
  if ((int ****)local_20 != &local_20) {
    do {
      pppiVar1 = (int ***)*local_20;
      pppiVar2 = (int ***)local_20[1];
      *pppiVar2 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar2;
      _free(local_20);
    } while ((int ****)local_20 != &local_20);
  }
  ExceptionList = local_14;
  return;
}


// ==== 0x572cd0 FUN_00572cd0

undefined4 FUN_00572cd0(void)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_EDI;
  
  iVar1 = FUN_00572b50(in_EAX,0);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x150) = 0;
    *(undefined1 *)(iVar1 + 0x3d) = 1;
    FUN_00572d90(unaff_EDI);
    *(undefined1 *)(iVar1 + 0x3d) = 0;
    *(undefined4 *)(unaff_EDI + 0xa4) = DAT_006f08a4;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    return 1;
  }
  return 0;
}


// ==== 0x572d20 FUN_00572d20

undefined4 FUN_00572d20(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 in_EAX;
  int *piVar4;
  int unaff_ESI;
  
  piVar4 = (int *)FUN_00572b50(in_EAX,0);
  if (piVar4 != (int *)0x0) {
    iVar1 = *piVar4;
    piVar2 = (int *)piVar4[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    puVar3 = *(undefined4 **)(unaff_ESI + 0x6c);
    *puVar3 = piVar4;
    *(int **)(unaff_ESI + 0x6c) = piVar4;
    piVar4[1] = (int)puVar3;
    *piVar4 = unaff_ESI + 0x68;
    return 1;
  }
  return 0;
}


// ==== 0x572d60 FUN_00572d60

void FUN_00572d60(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  piVar2 = (int *)in_EAX[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  puVar3 = *(undefined4 **)(param_1 + 0x6c);
  *puVar3 = in_EAX;
  *(int **)(param_1 + 0x6c) = in_EAX;
  in_EAX[1] = (int)puVar3;
  *in_EAX = param_1 + 0x68;
  return;
}


// ==== 0x572d90 FUN_00572d90

void FUN_00572d90(int param_1)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = "REPLAY_MANAGER_STATE";
  do {
    cVar1 = pcVar3[in_EAX + -0x6bbb78];
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    if ((cVar1 == '\0') || (cVar2 == '\0')) break;
  } while (cVar1 == cVar2);
  if (cVar1 == cVar2) {
    FUN_00572e20(param_1);
    return;
  }
  FUN_00431f40(&DAT_0078a2f0);
  if (((*(char *)(in_EAX + 0x3c) == '\0') && (*(char *)(in_EAX + 0x3e) == '\0')) ||
     (DAT_006f08a4 != *(int *)(param_1 + 0x54))) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  FUN_00571920(uVar4);
  FUN_00421e80(DAT_007361f0);
  Profile__SerializeJoystickSection();
  return;
}


// ==== 0x572e20 FUN_00572e20

void FUN_00572e20(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  iVar4 = param_1;
  FUN_00571ea0(0,"ReplayManager");
  FUN_00571c20(unaff_ESI,param_1 + 0x50,4,4,1);
  FUN_00571c20(unaff_ESI,param_1 + 0x54,4,4,1);
  piVar1 = (int *)(param_1 + 0xa8);
  FUN_00571c20(unaff_ESI,piVar1,4,4,1);
  if (0 < *piVar1) {
    param_1 = param_1 + 0xb0;
    iVar3 = 0;
    do {
      FUN_00571c20(unaff_ESI,param_1,4,4,1);
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 4;
    } while (iVar3 < *piVar1);
  }
  piVar1 = (int *)(iVar4 + 0x40b0);
  FUN_00571c20(unaff_ESI,piVar1,4,4,1);
  iVar3 = 0;
  if (0 < *piVar1) {
    iVar4 = iVar4 + 0x40b8;
    do {
      FUN_00571c20(unaff_ESI,iVar4,0x10,0xffffffff,0);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < *piVar1);
  }
  iVar4 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar4 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar4 + 0x58 + unaff_ESI);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x572f20 FUN_00572f20

int * FUN_00572f20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x50) < 0) {
    return (int *)0x0;
  }
  puVar1 = (undefined4 *)(unaff_EDI + 0x68);
  if ((undefined4 *)*(int *)(unaff_EDI + 0x68) == puVar1) {
    piVar5 = _malloc(0x9558);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5[10] = 0;
      piVar5[0xb] = 0;
    }
    puVar2 = *(undefined4 **)(unaff_EDI + 0x6c);
    *puVar2 = piVar5;
    *(int **)(unaff_EDI + 0x6c) = piVar5;
    piVar5[1] = (int)puVar2;
    *piVar5 = (int)puVar1;
  }
  piVar5 = (int *)*puVar1;
  iVar3 = *piVar5;
  piVar4 = (int *)piVar5[1];
  *piVar4 = iVar3;
  *(int **)(iVar3 + 4) = piVar4;
  puVar2 = *(undefined4 **)(unaff_EDI + 0x74);
  *puVar2 = piVar5;
  *(int **)(unaff_EDI + 0x74) = piVar5;
  piVar5[1] = (int)puVar2;
  *piVar5 = unaff_EDI + 0x70;
  FUN_00571a40();
  if ((DAT_006f08a4 == *(int *)(unaff_EDI + 0x54)) && (*(int *)(unaff_EDI + 0xa8) < 0x1000)) {
    *(int *)(unaff_EDI + 0xb0 + *(int *)(unaff_EDI + 0xa8) * 4) = DAT_006f08a4;
    *(int *)(unaff_EDI + 0xa8) = *(int *)(unaff_EDI + 0xa8) + 1;
  }
  *(int *)(unaff_EDI + 0xa4) = DAT_006f08a4;
  piVar5[0x54] = 0;
  *(undefined1 *)(piVar5 + 0xf) = 1;
  FUN_00572d90(unaff_EDI);
  piVar5[0x55] = piVar5[0x54];
  *(undefined1 *)(piVar5 + 0xf) = 0;
  if (*(char *)((int)piVar5 + 0x41) != '\0') {
    iVar3 = *piVar5;
    piVar4 = (int *)piVar5[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    puVar2 = *(undefined4 **)(unaff_EDI + 0x6c);
    *puVar2 = piVar5;
    *(int **)(unaff_EDI + 0x6c) = piVar5;
    piVar5[1] = (int)puVar2;
    *piVar5 = (int)puVar1;
    return (int *)0x0;
  }
  return piVar5;
}


// ==== 0x573010 FUN_00573010

void FUN_00573010(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + 0x150) = 0;
  *(undefined1 *)(unaff_ESI + 0x3d) = 1;
  FUN_00572d90(unaff_EDI);
  *(undefined1 *)(unaff_ESI + 0x3d) = 0;
  *(undefined4 *)(unaff_EDI + 0xa4) = DAT_006f08a4;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  return;
}


// ==== 0x573040 FUN_00573040

void FUN_00573040(void)

{
  undefined1 *puVar1;
  undefined1 *in_EAX;
  
  puVar1 = in_EAX + 0x2c;
  *(undefined1 **)puVar1 = puVar1;
  *(undefined1 **)(in_EAX + 0x30) = puVar1;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  *(undefined4 *)(in_EAX + 4) = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  return;
}


// ==== 0x573150 Chunk39100::Loader

/* [canon] assets high (Hopper sub_573150 + Ghidra make FUN_00573150: H+G agree) docs/re/assets.md
    */

undefined4 Chunk39100__Loader(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = *param_1;
  if (iVar1 == 0x39100) {
    DAT_0073c1a0 = param_1 + 2;
    return 1;
  }
  if (iVar1 == 0x39101) {
    piVar3 = param_1 + 2;
    *DAT_0073c1ac = (int)piVar3;
    piVar2 = piVar3;
    param_1[3] = (int)DAT_0073c1ac;
    DAT_0073c1ac = piVar2;
    *piVar3 = (int)&DAT_0073c1a8;
    param_1[0x10] = 1;
    return 1;
  }
  if (iVar1 == 0x39102) {
    DAT_0073c1a4 = param_1 + 2;
    return 1;
  }
  return 0;
}


// ==== 0x573160 Chunk39100::Unloader

/* [canon] assets high (Hopper sub_573160 + Ghidra make FUN_00573160: H+G agree) docs/re/assets.md
    */

undefined4 Chunk39100__Unloader(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 == 0x39100) {
    DAT_0073c1a0 = 0;
    return 1;
  }
  if (iVar3 != 0x39101) {
    if (iVar3 != 0x39102) {
      return 0;
    }
    DAT_0073c1a4 = 0;
    return 1;
  }
  piVar1 = param_1 + 2;
  iVar3 = 0;
  piVar2 = DAT_0073c1a8;
  if ((int **)DAT_0073c1a8 != &DAT_0073c1a8) {
    do {
      iVar3 = iVar3 + 1;
      if (piVar2 == piVar1) goto LAB_00573121;
      piVar2 = (int *)*piVar2;
    } while ((int **)piVar2 != &DAT_0073c1a8);
  }
  if (piVar1 != (int *)0x0) {
    iVar3 = 0;
  }
LAB_00573121:
  if (iVar3 != 0) {
    iVar3 = *piVar1;
    piVar1 = (int *)param_1[3];
    *piVar1 = iVar3;
    *(int **)(iVar3 + 4) = piVar1;
  }
  return 1;
}


// ==== 0x573170 FUN_00573170

void __fastcall FUN_00573170(undefined1 *param_1)

{
  int in_EAX;
  int iVar1;
  
  if ((in_EAX < 0) || (iVar1 = in_EAX, 0 < in_EAX)) {
    iVar1 = 0;
  }
  if (*(&PTR_s_REPLAY0_BIN_006f1a04)[iVar1] != '\0') {
    if ((in_EAX < 0) || (0 < in_EAX)) {
      in_EAX = 0;
    }
    FUN_00565da0("REPLAY\\%s",(&PTR_s_REPLAY0_BIN_006f1a04)[in_EAX]);
    return;
  }
  *param_1 = 0;
  return;
}


// ==== 0x5731c0 FUN_005731c0

void FUN_005731c0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  undefined1 local_40 [64];
  
  iVar1 = *(int *)(unaff_EDI + 4);
  *(undefined1 *)(unaff_EDI + 1) = 1;
  if ((iVar1 < 0) || (iVar2 = iVar1, 0 < iVar1)) {
    iVar2 = 0;
  }
  if (*(&PTR_s_REPLAY0_BIN_006f1a04)[iVar2] == '\0') {
    local_40[0] = 0;
  }
  else {
    if ((iVar1 < 0) || (0 < iVar1)) {
      iVar1 = 0;
    }
    FUN_00565da0("REPLAY\\%s",(&PTR_s_REPLAY0_BIN_006f1a04)[iVar1]);
  }
  CreateResourceFile(local_40,8,0,0,0);
  ResourceFile__BeginLoading();
  return;
}


// ==== 0x573240 FUN_00573240

void FUN_00573240(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if (*(char *)(param_1 + 2) != '\0') {
    piVar4 = (int *)NullUpdate_ret();
    while (piVar5 = DAT_0077a928, DAT_0077a928 != piVar4) {
      while (piVar5[2] != 8) {
        piVar2 = piVar5 + 1;
        piVar5 = (int *)*piVar2;
        if ((int *)*piVar2 == piVar4) goto LAB_0057327c;
      }
      iVar1 = piVar5[0x24];
      while (iVar1 == 0) {
        ServiceResourceLoading();
        iVar1 = piVar5[0x24];
      }
      iVar1 = *piVar5;
      piVar2 = (int *)piVar5[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      ResourceFile__UnloadChunks();
      iVar3 = DAT_007360f8;
      iVar1 = *(int *)(DAT_007360f8 + 0x18);
      *piVar5 = *(int *)(DAT_007360f8 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar5;
    }
LAB_0057327c:
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return;
}


// ==== 0x5732d0 FUN_005732d0

void FUN_005732d0(int param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}


// ==== 0x5732e0 FUN_005732e0

void FUN_005732e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_007345d0;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  iVar3 = FUN_00572b50("REPLAY_MANAGER_STATE",0);
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x150) = 0;
    *(undefined1 *)(iVar3 + 0x3d) = 1;
    FUN_00572d90(iVar1);
    *(undefined1 *)(iVar3 + 0x3d) = 0;
    *(undefined4 *)(iVar1 + 0xa4) = DAT_006f08a4;
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x10) + 1;
  iVar3 = FUN_00572b50("DEMO_MODE_SNAPSHOT",iVar1);
  uVar2 = DAT_007361f0;
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x10) = iVar1;
    *(int *)(param_1 + 0x14) = iVar3;
    FUN_00421c00(uVar2,0xe,iVar3);
  }
  return;
}


// ==== 0x573370 FUN_00573370

uint FUN_00573370(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint in_EAX;
  int iVar5;
  int iVar6;
  int *piVar7;
  int unaff_EDI;
  
  piVar7 = *(int **)(unaff_EDI + 0x14);
  if ((piVar7 != (int *)0x0) && (in_EAX = DAT_006f08a4, piVar7[0xd] <= (int)DAT_006f08a4)) {
    iVar6 = *(int *)(unaff_EDI + 0x10) + 1;
    *(undefined4 *)(unaff_EDI + 0x14) = 0;
    iVar5 = FUN_00572b50("DEMO_MODE_SNAPSHOT",iVar6);
    uVar4 = DAT_007361f0;
    in_EAX = 0;
    if (iVar5 != 0) {
      *(int *)(unaff_EDI + 0x10) = iVar6;
      *(int *)(unaff_EDI + 0x14) = iVar5;
      in_EAX = FUN_00421c00(uVar4,0xe,iVar5);
    }
    piVar7 = *(int **)(unaff_EDI + 0x14);
    if (piVar7 == (int *)0x0) goto LAB_00573488;
  }
  iVar6 = CONCAT31((int3)(in_EAX >> 8),*(char *)(unaff_EDI + 9));
  if ((*(char *)(unaff_EDI + 9) == '\0') || (piVar7 == (int *)0x0)) goto LAB_0057348d;
  iVar6 = piVar7[0xb];
  if (2.0 <= (float)(iVar6 - piVar7[10]) * 0.00025) {
    iVar5 = _ftol_nocw();
    uVar3 = DAT_006f08a4;
    if (iVar6 - iVar5 < DAT_0073ad34) {
      piVar7[0xb] = DAT_0073ad34;
      piVar7[0xd] = uVar3;
      goto LAB_0057344b;
    }
  }
  else {
    iVar6 = *piVar7;
    piVar1 = (int *)piVar7[1];
    *piVar1 = iVar6;
    *(int **)(iVar6 + 4) = piVar1;
    iVar6 = DAT_007345d0;
    puVar2 = *(undefined4 **)(DAT_007345d0 + 0x6c);
    iVar5 = DAT_007345d0 + 0x68;
    *puVar2 = piVar7;
    *(int **)(iVar6 + 0x6c) = piVar7;
    *piVar7 = iVar5;
    piVar7[1] = (int)puVar2;
    *(int *)(unaff_EDI + 0x10) = *(int *)(unaff_EDI + 0x10) + -1;
LAB_0057344b:
    *(undefined4 *)(unaff_EDI + 0x14) = 0;
  }
  iVar6 = *(int *)(unaff_EDI + 0x14);
  if (iVar6 == 0) {
    iVar6 = *(int *)(unaff_EDI + 0x10) + 1;
    iVar5 = FUN_00572b50("DEMO_MODE_SNAPSHOT",iVar6);
    in_EAX = 0;
    if (iVar5 != 0) {
      *(int *)(unaff_EDI + 0x14) = iVar5;
      uVar4 = DAT_007361f0;
      *(int *)(unaff_EDI + 0x10) = iVar6;
      in_EAX = FUN_00421c00(uVar4,0xe,iVar5);
    }
LAB_00573488:
    return in_EAX & 0xffffff00;
  }
LAB_0057348d:
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


// ==== 0x5734a0 FUN_005734a0

void FUN_005734a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char in_AL;
  undefined4 uVar7;
  int iVar8;
  
  if (in_AL != '\0') {
    if ((*(char *)(param_1 + 8) != '\0') && (*(int *)(param_1 + 0xc) == 0)) {
      FUN_00572d20();
      FUN_00572f20("REPLAY_MANAGER_STATE");
      uVar7 = FUN_00572f20("DEMO_MODE_SNAPSHOT");
      *(undefined4 *)(param_1 + 0xc) = uVar7;
    }
    iVar8 = DAT_007345d0;
    if (((*(char *)(param_1 + 9) != '\0') &&
        (piVar1 = *(int **)(param_1 + 0x14), piVar1 != (int *)0x0)) &&
       (DAT_0073ad34 < piVar1[10] + 12000)) {
      iVar2 = *piVar1;
      piVar3 = (int *)piVar1[1];
      iVar4 = piVar1[0xb];
      iVar5 = piVar1[0xd];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      puVar6 = *(undefined4 **)(iVar8 + 0x6c);
      *puVar6 = piVar1;
      *(int **)(iVar8 + 0x6c) = piVar1;
      piVar1[1] = (int)puVar6;
      *piVar1 = iVar8 + 0x68;
      iVar8 = FUN_00572f20("DEMO_MODE_SNAPSHOT");
      *(int *)(param_1 + 0x14) = iVar8;
      if (iVar8 != 0) {
        *(int *)(iVar8 + 0x2c) = iVar4;
        *(int *)(iVar8 + 0x34) = iVar5;
      }
      FUN_00572bd0();
    }
  }
  uVar7 = DAT_006f08a4;
  iVar8 = *(int *)(param_1 + 0xc);
  if (iVar8 != 0) {
    *(int *)(iVar8 + 0x2c) = DAT_0073ad34;
    *(undefined4 *)(iVar8 + 0x34) = uVar7;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_005737f0();
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_005735a0();
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ==== 0x5735a0 FUN_005735a0

void FUN_005735a0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  
  iVar4 = DAT_007345d0;
  while( true ) {
    piVar5 = (int *)FUN_00572b50("DEMO_MODE_SNAPSHOT",0);
    if (piVar5 == (int *)0x0) break;
    iVar1 = *piVar5;
    piVar2 = (int *)piVar5[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    puVar3 = *(undefined4 **)(iVar4 + 0x6c);
    *puVar3 = piVar5;
    *(int **)(iVar4 + 0x6c) = piVar5;
    piVar5[1] = (int)puVar3;
    *piVar5 = iVar4 + 0x68;
  }
  piVar5 = (int *)FUN_00572b50("REPLAY_MANAGER_STATE",0);
  if (piVar5 != (int *)0x0) {
    iVar1 = *piVar5;
    piVar2 = (int *)piVar5[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    puVar3 = *(undefined4 **)(iVar4 + 0x6c);
    *puVar3 = piVar5;
    *(int **)(iVar4 + 0x6c) = piVar5;
    piVar5[1] = (int)puVar3;
    *piVar5 = iVar4 + 0x68;
  }
  *(undefined1 *)(unaff_EDI + 8) = 0;
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  return;
}


// ==== 0x573620 FUN_00573620

void FUN_00573620(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_48;
  uint local_44;
  undefined1 local_40 [64];
  
  if ((in_EAX < 0) || (iVar5 = in_EAX, 0 < in_EAX)) {
    iVar5 = 0;
  }
  if (*(&PTR_s_REPLAY0_BIN_006f1a04)[iVar5] == '\0') {
    local_40[0] = 0;
  }
  else {
    if ((in_EAX < 0) || (0 < in_EAX)) {
      in_EAX = 0;
    }
    FUN_00565da0("REPLAY\\%s",(&PTR_s_REPLAY0_BIN_006f1a04)[in_EAX]);
  }
  iVar3 = FUN_00572b50(param_2,0);
  iVar5 = 1;
  while (iVar3 != 0) {
    uVar7 = *(int *)(iVar3 + 0x154) + 0x15bU & 0xfffffffc;
    local_48 = 0x39101;
    local_44 = uVar7;
    puVar4 = (undefined4 *)bOpenFile(local_40,1,2);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_0063c290(puVar4[3],puVar4[2],&local_48,8,100);
      iVar6 = puVar4[2] + 8;
      puVar4[2] = iVar6;
      if ((int)puVar4[1] < iVar6) {
        puVar4[1] = iVar6;
      }
      if ((int)puVar4[7] < 1) {
        if (-1 < (int)puVar4[1]) {
          if (puVar4[4] == 0) {
            FUN_0063c2c0(puVar4[3],100);
          }
          else {
            piVar1 = (int *)(puVar4[4] + 8);
            *piVar1 = *piVar1 + -1;
          }
          puVar4[1] = 0xffffffff;
        }
        iVar2 = DAT_00734484;
        iVar6 = *(int *)(DAT_00734484 + 0x18);
        *puVar4 = *(undefined4 *)(DAT_00734484 + 0x10);
        *(int *)(iVar2 + 0x18) = iVar6 + -1;
        *(undefined4 **)(iVar2 + 0x10) = puVar4;
      }
      else {
        puVar4[5] = 1;
      }
    }
    puVar4 = (undefined4 *)bOpenFile(local_40,1,2);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_0063c290(puVar4[3],puVar4[2],iVar3,uVar7,100);
      iVar3 = puVar4[2] + uVar7;
      puVar4[2] = iVar3;
      if ((int)puVar4[1] < iVar3) {
        puVar4[1] = iVar3;
      }
      if ((int)puVar4[7] < 1) {
        if (-1 < (int)puVar4[1]) {
          if (puVar4[4] == 0) {
            FUN_0063c2c0(puVar4[3],100);
          }
          else {
            piVar1 = (int *)(puVar4[4] + 8);
            *piVar1 = *piVar1 + -1;
          }
          puVar4[1] = 0xffffffff;
        }
        iVar6 = DAT_00734484;
        iVar3 = *(int *)(DAT_00734484 + 0x18);
        *puVar4 = *(undefined4 *)(DAT_00734484 + 0x10);
        *(int *)(iVar6 + 0x18) = iVar3 + -1;
        *(undefined4 **)(iVar6 + 0x10) = puVar4;
      }
      else {
        puVar4[5] = 1;
      }
    }
    iVar3 = FUN_00572b50(param_2,iVar5);
    iVar5 = iVar5 + 1;
  }
  return;
}


// ==== 0x5737f0 FUN_005737f0

void FUN_005737f0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_50 [4];
  undefined1 local_40;
  
  iVar2 = FUN_00572b50("DEMO_MODE_SNAPSHOT",0);
  if (iVar2 != 0) {
    iVar2 = FUN_00572b50("REPLAY_MANAGER_STATE",0);
    if (iVar2 != 0) {
      if (*(int *)(in_EAX + 0x18) < 0) {
        *(undefined4 *)(in_EAX + 0x18) = 0;
      }
      FUN_00573170(in_EAX);
      local_a0 = 0;
      local_9c = 0;
      FUN_00594ea0(&local_a0);
      puVar3 = local_50;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      local_50[0] = 8;
      local_50[1] = DAT_0078a2f0;
      local_50[2] = 1;
      local_50[3] = 0;
      local_40 = 0;
      local_98 = 0x39100;
      local_94 = 0x50;
      FUN_00594ef0(&local_98);
      FUN_00594ef0(local_50);
      FUN_00573620(in_EAX,"DEMO_MODE_SNAPSHOT");
      FUN_00573620(in_EAX,"REPLAY_MANAGER_STATE");
      FUN_00573620(in_EAX,"CHECKSUM0");
      FUN_00573620(in_EAX,"CHECKSUM1");
      FUN_00573620(in_EAX,"CHECKSUM2");
      FUN_00573620(in_EAX,"CHECKSUM3");
      iVar2 = *(int *)(DAT_007345d0 + 100);
      iVar1 = *(int *)(iVar2 + 8);
      local_a4 = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 4U & 0xfffffffc;
      local_a8 = 0x39102;
      FUN_00594ef0(&local_a8);
      FUN_00594ef0(iVar2);
    }
  }
  return;
}


// ==== 0x573970 FUN_00573970

void __fastcall FUN_00573970(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 8) = param_1;
  *(undefined4 *)(in_EAX + 0x14) = param_3;
  *(undefined4 *)(in_EAX + 0x10) = param_2;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  return;
}


// ==== 0x573990 FUN_00573990

void FUN_00573990(char param_1)

{
  char *pcVar1;
  int iVar2;
  int *unaff_ESI;
  uint unaff_EDI;
  
  iVar2 = 0;
  if (0 < *unaff_ESI) {
    pcVar1 = (char *)((int)unaff_ESI + 7);
    do {
      if (((byte)pcVar1[-1] == unaff_EDI) && (*pcVar1 == param_1)) {
        pcVar1[-0xffffffff00000003] = '\0';
        pcVar1[-0xffffffff00000002] = '\0';
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0xc;
    } while (iVar2 < *unaff_ESI);
  }
  return;
}


// ==== 0x5739c0 FUN_005739c0

int __fastcall FUN_005739c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685668;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  puVar3 = (undefined4 *)(param_1 + 8);
  local_4 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x14);
  local_14 = 4;
  do {
    CallNTimes(puVar3,8,4,FUN_004ad8d0);
    puVar2[5] = puVar3;
    puVar2[6] = 4;
    *puVar3 = 0;
    puVar2[-2] = 0;
    puVar2[-1] = 0x43000000;
    *puVar2 = 0x43000000;
    puVar2[1] = 0x43000000;
    puVar2[2] = 0x43000000;
    puVar2[3] = 0x437f0000;
    puVar2[4] = 0x437f0000;
    *(undefined1 *)(puVar2 + 7) = 0;
    puVar3 = puVar3 + 0xb;
    puVar2 = puVar2 + 0xb;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  *(undefined4 *)(param_1 + 0x17c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x180) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  puVar3 = (undefined4 *)(param_1 + 0xb8);
  for (iVar1 = 0x2f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x573aa0 FUN_00573aa0

void FUN_00573aa0(void)

{
  FUN_00574b00();
  return;
}


// ==== 0x573ab0 InputEvents::MatchBindings

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

int InputEvents__MatchBindings
              (undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

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
    puVar6 = (undefined4 *)NullUpdate_ret();
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
      puVar6 = (undefined4 *)NullUpdate_ret();
      for (; puVar8 != puVar6; puVar8 = (undefined4 *)*puVar8) {
        uVar7 = InputEvents__FindProfileForDevice(puVar8[2]);
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


// ==== 0x573c30 InputEvents::PostEvent

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputEvents__PostEvent(uint param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(&DAT_0073b260 + (param_1 >> 0x10) * 0x18c);
  piVar2 = (int *)NullUpdate_ret();
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


// ==== 0x573cb0 InputEvents::Update

/* [canon] input med (ghidra+hopper+capstone) docs/re/hud_input.md */

void InputEvents__Update(void)

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
          uVar5 = Input__GetState(iVar11,&local_8);
          iVar4 = InputEvents__MatchBindings(puVar9,uVar5,local_8,&DAT_0073b578);
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
        InputEvents__PostEvent(uVar5,&DAT_0073b578,1);
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
        InputEvents__PostEvent(uVar6 + 0x100,&DAT_0073b578,1);
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
          InputEvents__PostEvent(uVar5,&DAT_0073b578,0);
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


// ==== 0x574020 InputEvents::AddSource

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void InputEvents__AddSource(int param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = in_EAX * 0x18c;
  puVar3 = *(undefined4 **)(&DAT_0073b260 + iVar5);
  puVar1 = (undefined4 *)NullUpdate_ret();
  for (; (puVar3 != puVar1 && (puVar3[2] != param_1)); puVar3 = (undefined4 *)*puVar3) {
  }
  iVar2 = FUN_00567160();
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00573970(param_3);
  }
  puVar1 = *(undefined4 **)(&DAT_0073b264 + iVar5);
  *puVar1 = puVar3;
  *(undefined4 **)(&DAT_0073b264 + iVar5) = puVar3;
  puVar3[1] = puVar1;
  *puVar3 = &DAT_0073b260 + iVar5;
  uVar4 = InputEvents__FindProfileForDevice(puVar3[2]);
  puVar3[3] = uVar4;
  puVar3[7] = 1;
  puVar3[6] = 0;
  return;
}


// ==== 0x5740b0 FUN_005740b0

void FUN_005740b0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int *piVar4;
  
  FUN_00573990(param_1);
  piVar4 = *(int **)(&DAT_0073b260 + in_EAX * 0x18c);
  piVar3 = (int *)NullUpdate_ret();
  if (piVar4 != piVar3) {
    while (piVar4[2] != param_1) {
      piVar4 = (int *)*piVar4;
      if (piVar4 == piVar3) {
        return;
      }
    }
    iVar1 = *piVar4;
    piVar3 = (int *)piVar4[1];
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
    iVar2 = DAT_007345cc;
    iVar1 = *(int *)(DAT_007345cc + 0x18);
    *piVar4 = *(int *)(DAT_007345cc + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(int **)(iVar2 + 0x10) = piVar4;
  }
  return;
}


// ==== 0x574120 FUN_00574120

undefined4 FUN_00574120(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(&DAT_0073b260 + in_EAX * 0x18c);
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return 0;
    }
    if (puVar1[2] == unaff_EDI) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}


// ==== 0x574150 FUN_00574150

void FUN_00574150(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_004218a0(param_1);
  puVar1 = &DAT_006f923c + param_1;
  iVar2 = 0x15;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00414990();
  (&DAT_007306c4)[param_1] = param_3;
  return;
}


// ==== 0x574190 FUN_00574190

void FUN_00574190(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_005740b0(1);
    InputEvents__AddSource(1,FUN_00574150,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}


// ==== 0x5741c0 InputEvents::Init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] input high (ghidra+hopper+capstone) docs/re/hud_input.md */

void InputEvents__Init(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  _DAT_0073b3d8 = 0;
  _DAT_0073b564 = 1;
  puVar2 = (undefined4 *)FUN_00565b60(0x16b0,0,0,0);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[9] = 0xa0;
    puVar2[10] = 0x24;
    puVar2[5] = 0xb;
    puVar2[4] = 0;
    puVar2[2] = 0;
    puVar2[8] = 0;
    puVar2[3] = "EventNodeSlotPool";
    puVar2[0xb] = 0xa0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    SlotPool__BuildFreeList();
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = puVar2;
      puVar1 = puVar2;
      puVar2[1] = DAT_0073d81c;
      DAT_0073d81c = puVar1;
      *puVar2 = &DAT_0073d818;
    }
  }
  DAT_007345cc = puVar2;
  Input__Init();
  iVar5 = 0;
  do {
    (&DAT_007306c4)[iVar5] = 0xff;
    InputEvents__AddSource(1,FUN_00574150,0);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  uVar3 = DAT_006f227c ^ 0x1d872b41;
  uVar4 = uVar3 >> 5 ^ uVar3;
  uRam006f1a00 = DAT_006f227c & 0x7fffffff;
  DAT_006f227c = uVar4 << 0x1b ^ uVar3 ^ uVar4;
                    /* WARNING: Read-only address (ram,0x006f1a00) is written */
  return;
}


// ==== 0x5742b0 Profile::SerializeJoystickSection

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

void Profile__SerializeJoystickSection(void)

{
  int iVar1;
  char cVar2;
  undefined *puVar3;
  int *piVar4;
  int unaff_EDI;
  
  FUN_00571ea0(0,"Joystick");
  FUN_00571c20(unaff_EDI,&DAT_007306c4,2,0xffffffff,0);
  puVar3 = &DAT_0073b260;
  do {
    piVar4 = &DAT_006f1458;
    do {
      FUN_00571c20(unaff_EDI,puVar3 + *piVar4 + 0xb8,1,0xffffffff,0);
      piVar4 = piVar4 + 1;
    } while ((int)piVar4 < 0x6f14b8);
    puVar3 = puVar3 + 0x18c;
  } while ((int)puVar3 < 0x73b578);
  iVar1 = *(char *)(unaff_EDI + 0x40) * 0x10 + 0x4c + unaff_EDI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_EDI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_EDI + 0x40) + -1;
  *(char *)(unaff_EDI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x574343 FUN_00574343

/* WARNING: Control flow encountered bad instruction data */

void FUN_00574343(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x574350 FUN_00574350

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


// ==== 0x574410 FUN_00574410

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


// ==== 0x574450 FUN_00574450

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


// ==== 0x5744b0 FUN_005744b0

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


// ==== 0x574500 FUN_00574500

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


// ==== 0x574549 FUN_00574549

int FUN_00574549(void)

{
  uint uVar1;
  uint unaff_EBX;
  bool in_ZF;
  int in_stack_00000010;
  
  if (in_ZF) {
    unaff_EBX = 0;
  }
  uVar1 = unaff_EBX & 0xff;
  if ((*(uint *)(in_stack_00000010 + 0x18) == uVar1) && (*(int *)(in_stack_00000010 + 0x1c) == 0)) {
    return 0;
  }
  *(uint *)(in_stack_00000010 + 0x18) = uVar1;
  *(undefined4 *)(in_stack_00000010 + 0x1c) = 0;
  return uVar1 * 0x100 + *(int *)(in_stack_00000010 + 8);
}


// ==== 0x574550 FUN_00574550

void __fastcall FUN_00574550(byte param_1)

{
  char *pcVar1;
  int in_EAX;
  int unaff_EBX;
  
  pcVar1 = (char *)(unaff_EBX + -0x80 + in_EAX);
  *pcVar1 = *pcVar1 << (param_1 & 0x1f);
  return;
}


// ==== 0x574553 FUN_00574553

int FUN_00574553(void)

{
  int in_stack_00000010;
  
  if ((*(int *)(in_stack_00000010 + 0x18) == 0xff) && (*(int *)(in_stack_00000010 + 0x1c) == 0)) {
    return 0;
  }
  *(undefined4 *)(in_stack_00000010 + 0x18) = 0xff;
  *(undefined4 *)(in_stack_00000010 + 0x1c) = 0;
  return *(int *)(in_stack_00000010 + 8) + 0xff00;
}


// ==== 0x574590 FUN_00574590

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


// ==== 0x5747b0 FUN_005747b0

uint FUN_005747b0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = (uint)*(byte *)(param_4 + 0x15) * 0x2c;
  uVar4 = (uint)*(byte *)(iVar2 + 0x30 + param_5);
  LinearTable__Lookup11
            (iVar2 + param_5 + 0x28,
             (float)(byte)((byte)(*(uint *)(param_2 + (uint)(*(byte *)(param_4 + 0x12) >> 5) * 4) >>
                                 (*(byte *)(param_4 + 0x12) & 0x1f)) ^ *(byte *)(param_4 + 0x10)));
  uVar3 = _ftol_nocw();
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


// ==== 0x574852 FUN_00574852

int __fastcall FUN_00574852(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(int *)(param_2 + 0x18) = in_EAX;
  return in_EAX * 0x100 + *(int *)(param_2 + 8);
}


// ==== 0x5748c0 FUN_005748c0

int FUN_005748c0(int param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = 0;
  if (0 < DAT_007041c0) {
    piVar2 = &DAT_00704148;
    do {
      if (*piVar2 == unaff_ESI) {
        iVar1 = 0;
        if (((char)piVar2[1] != '\0') && (0 < param_1)) {
          *unaff_EDI = (int)(char)piVar2[1];
          iVar1 = 1;
        }
        if ((*(char *)((int)piVar2 + 5) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 5);
          iVar1 = iVar1 + 1;
        }
        if ((*(char *)((int)piVar2 + 6) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 6);
          iVar1 = iVar1 + 1;
        }
        if ((*(char *)((int)piVar2 + 7) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 7);
          iVar1 = iVar1 + 1;
        }
        if (((char)piVar2[2] != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)(char)piVar2[2];
          iVar1 = iVar1 + 1;
        }
        if ((*(char *)((int)piVar2 + 9) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 9);
          iVar1 = iVar1 + 1;
        }
        if ((*(char *)((int)piVar2 + 10) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 10);
          iVar1 = iVar1 + 1;
        }
        if ((*(char *)((int)piVar2 + 0xb) != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 0xb);
          iVar1 = iVar1 + 1;
        }
        if (((char)piVar2[3] != '\0') && (iVar1 < param_1)) {
          unaff_EDI[iVar1] = (int)(char)piVar2[3];
          iVar1 = iVar1 + 1;
        }
        if (*(char *)((int)piVar2 + 0xd) == '\0') {
          return iVar1;
        }
        if (param_1 <= iVar1) {
          return iVar1;
        }
        unaff_EDI[iVar1] = (int)*(char *)((int)piVar2 + 0xd);
        return iVar1 + 1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 5;
    } while (iVar1 < DAT_007041c0);
  }
  return 0;
}


// ==== 0x5749b0 FUN_005749b0

int FUN_005749b0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_28 [10];
  
  iVar1 = FUN_005748c0(10);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if (local_28[iVar2] == param_1) {
        return param_1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return local_28[0];
}


// ==== 0x574a00 InputEvents::FindProfileForDevice

/* [canon] input med (ghidra+hopper) docs/re/hud_input.md */

undefined * InputEvents__FindProfileForDevice(int param_1)

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


// ==== 0x574a70 FUN_00574a70

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
  *(float *)(param_1 + 8) = 128.0 - (float)bVar1;
  *(float *)(param_1 + 0x10) = (float)bVar1 + 128.0;
  return;
}


// ==== 0x574b00 FUN_00574b00

void FUN_00574b00(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007345cc;
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


// ==== 0x574b40 FUN_00574b40

int FUN_00574b40(float param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  float *pfVar2;
  
  iVar1 = 0;
  if (0 < (int)in_EAX[1]) {
    pfVar2 = (float *)*in_EAX;
    do {
      if (param_1 < *pfVar2) break;
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 2;
    } while (iVar1 < (int)in_EAX[1]);
    if (0 < iVar1) {
      iVar1 = iVar1 + -1;
    }
  }
  return iVar1;
}


// ==== 0x574b70 FUN_00574b70

float10 __thiscall FUN_00574b70(undefined4 *param_1,float param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  pfVar1 = (float *)*param_1;
  if ((param_2 < *pfVar1) || (iVar2 = param_1[1], pfVar1[iVar2 * 2 + -2] <= param_2)) {
    return (float10)0.0;
  }
  iVar3 = FUN_00574b40(param_2);
  if ((-1 < iVar3) && (iVar3 <= iVar2 + -2)) {
    return ((float10)param_2 - (float10)pfVar1[iVar3 * 2]) *
           (((float10)pfVar1[iVar3 * 2 + 3] - (float10)pfVar1[iVar3 * 2 + 1]) /
           ((float10)pfVar1[iVar3 * 2 + 2] - (float10)pfVar1[iVar3 * 2])) +
           (float10)pfVar1[iVar3 * 2 + 1];
  }
  return ((float10)param_2 - (float10)pfVar1[iVar3 * 2]) * (float10)0.0 +
         (float10)pfVar1[iVar3 * 2 + 1];
}


// ==== 0x574bf0 FUN_00574bf0

void __fastcall FUN_00574bf0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined4 *)(param_1 + 0x18);
  do {
    puVar1[-6] = 0;
    puVar1[-3] = 0;
    *puVar1 = 0;
    *(undefined1 *)(param_1 + 0x24 + iVar2) = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 3);
  return;
}


// ==== 0x574c20 FUN_00574c20

undefined4 FUN_00574c20(undefined4 param_1,float param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  int local_8;
  
  local_8 = 0;
  pfVar5 = (float *)(unaff_EDI + 0x18);
  iVar6 = -1;
  do {
    cVar1 = *(char *)(unaff_EDI + 0x24 + local_8);
    iVar7 = iVar6;
    if (cVar1 <= param_3) {
      iVar7 = local_8;
      if (pfVar5[-6] == 0.0) break;
      if (-1 < iVar6) {
        cVar2 = *(char *)(unaff_EDI + 0x24 + iVar6);
        iVar7 = iVar6;
        if (cVar2 < cVar1) goto LAB_00574ca5;
        if (cVar1 == cVar2) {
          FUN_00574b70(*(undefined4 *)(unaff_EDI + 0xc + iVar6 * 4));
          iVar3 = _ftol_nocw();
          FUN_00574b70(pfVar5[-3]);
          iVar4 = _ftol_nocw();
          if (iVar3 < iVar4) goto LAB_00574ca5;
        }
      }
      if ((*(char *)(unaff_EDI + 0x24 + local_8) < param_3) || (iVar7 = iVar6, *pfVar5 < param_2)) {
        iVar7 = local_8;
      }
    }
LAB_00574ca5:
    local_8 = local_8 + 1;
    pfVar5 = pfVar5 + 1;
    iVar6 = iVar7;
  } while (local_8 < 3);
  if (iVar7 < 0) {
    return 0;
  }
  *(float *)(unaff_EDI + 0x18 + iVar7 * 4) = param_2;
  *(undefined4 *)(unaff_EDI + iVar7 * 4) = param_1;
  *(undefined4 *)(unaff_EDI + 0xc + iVar7 * 4) = 0;
  *(char *)(iVar7 + 0x24 + unaff_EDI) = param_3;
  return 1;
}


// ==== 0x574cf0 FUN_00574cf0

undefined4 FUN_00574cf0(float param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x2c) = *(undefined4 *)(unaff_EDI + 0x28);
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  iVar3 = 0;
  pfVar4 = (float *)(unaff_EDI + 0xc);
  do {
    puVar1 = (undefined4 *)pfVar4[-3];
    if (puVar1 != (undefined4 *)0x0) {
      if ((*pfVar4 < *(float *)*puVar1) || (((float *)*puVar1)[puVar1[1] * 2 + -2] <= *pfVar4)) {
        pfVar4[-3] = 0.0;
        *(undefined1 *)(unaff_EDI + 0x24 + iVar3) = 0xff;
      }
      else {
        FUN_00574b70(*pfVar4);
        iVar2 = _ftol_nocw();
        if (iVar2 <= *(int *)(unaff_EDI + 0x28)) {
          iVar2 = *(int *)(unaff_EDI + 0x28);
        }
        *(int *)(unaff_EDI + 0x28) = iVar2;
        *pfVar4 = param_1 / pfVar4[3] + *pfVar4;
      }
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 1;
  } while (iVar3 < 3);
  if (*(int *)(unaff_EDI + 0x28) < 0) {
    *(undefined4 *)(unaff_EDI + 0x28) = 0;
  }
  if (0xff < *(int *)(unaff_EDI + 0x28)) {
    *(undefined4 *)(unaff_EDI + 0x28) = 0xff;
  }
  return CONCAT31((int3)((uint)*(int *)(unaff_EDI + 0x28) >> 8),
                  *(int *)(unaff_EDI + 0x28) != *(int *)(unaff_EDI + 0x2c));
}


// ==== 0x574d90 FUN_00574d90

void __fastcall FUN_00574d90(undefined4 param_1,int param_2,float param_3)

{
  int iVar1;
  float *pfVar2;
  
  if (((((DAT_0077a920 != 6) || (iVar1 = *DAT_007361f0, iVar1 == 1)) || (iVar1 == 7)) ||
      ((iVar1 == 0xb || (iVar1 == 4)))) &&
     ((DAT_006f1d44 != 0 &&
      ((*(char *)(param_2 + 5) != '\0' && (pfVar2 = *(float **)(param_2 + 0xc), *pfVar2 <= param_3))
      )))) {
    if (pfVar2[1] < param_3) {
      param_3 = pfVar2[1];
    }
    if (DAT_0077a920 != 3) {
      FUN_00574c20(*(undefined4 *)(param_2 + 8),
                   (pfVar2[3] - pfVar2[2]) * ((param_3 - *pfVar2) / (pfVar2[1] - *pfVar2)) +
                   pfVar2[2],*(undefined1 *)(param_2 + 4));
    }
  }
  return;
}


// ==== 0x574e30 FUN_00574e30

void __fastcall FUN_00574e30(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x3f800000;
  param_1[7] = 0x41880000;
  return;
}


// ==== 0x574e60 FUN_00574e60

void __thiscall FUN_00574e60(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  fVar3 = *param_1;
  in_EAX[4] = (float)&PTR_DAT_00704570;
  in_EAX[5] = 0.0;
  in_EAX[6] = param_2;
  *in_EAX = fVar3 * -1.0;
  in_EAX[7] = param_3;
  in_EAX[1] = fVar1 * -1.0;
  in_EAX[2] = fVar2 * -1.0;
  return;
}


// ==== 0x574eb0 FUN_00574eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574eb0(void)

{
  if (DAT_007345c8 != 0) {
    DAT_0073b220 = _DAT_00704500 * -1.0;
    DAT_007345c8 = 0;
    DAT_0073b230 = &PTR_DAT_00704570;
    DAT_0073b234 = 0.0;
    DAT_0073b224 = _DAT_00704504 * -1.0;
    _DAT_0073b238 = 0.6;
    DAT_0073b23c = 0x41880000;
    DAT_0073b228 = _DAT_00704508 * -1.0;
  }
  if (DAT_0073b230 != (undefined **)0x0) {
    DAT_0073b234 = DAT_0073457c / _DAT_0073b238 + DAT_0073b234;
    if ((DAT_0073b234 < *(float *)*DAT_0073b230) ||
       (*(float *)((int)*DAT_0073b230 + ((int)DAT_0073b230[1] * 2 + -2) * 4) <= DAT_0073b234)) {
      DAT_0073b230 = (undefined **)0x0;
    }
  }
  if (DAT_0073b250 != (undefined4 *)0x0) {
    DAT_0073b254 = DAT_0073457c / _DAT_0073b258 + DAT_0073b254;
    if (DAT_0073b254 < *(float *)*DAT_0073b250) {
      DAT_0073b250 = (undefined4 *)0x0;
    }
    else if (((float *)*DAT_0073b250)[DAT_0073b250[1] * 2 + -2] <= DAT_0073b254) {
      DAT_0073b250 = (undefined4 *)0x0;
      return;
    }
  }
  return;
}


// ==== 0x574fd0 FUN_00574fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574fd0(void)

{
  DAT_0073b220 = 0;
  DAT_0073b224 = 0;
  DAT_0073b228 = 0;
  DAT_0073b230 = 0;
  DAT_0073b234 = 0;
  _DAT_0073b238 = 0x3f800000;
  DAT_0073b23c = 0x41880000;
  _DAT_0073b240 = 0;
  _DAT_0073b244 = 0;
  _DAT_0073b248 = 0;
  DAT_0073b250 = 0;
  DAT_0073b254 = 0;
  _DAT_0073b258 = 0x3f800000;
  DAT_0073b25c = 0x41880000;
  return;
}


// ==== 0x575040 ApplyCameraShake

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (G+C+M) docs/re/camera.md */

void ApplyCameraShake(int param_1)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  undefined1 auStack_ac [12];
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
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  
  if (*(float *)(DAT_007361f8 + 0x2e0) < _K_ONE) {
    return;
  }
  if (param_1 != 1) {
    if (param_1 == 2) {
      iVar2 = 1;
      goto LAB_0057507b;
    }
    if (param_1 != 3) {
      return;
    }
  }
  iVar2 = 0;
LAB_0057507b:
  uVar1 = _ftol_nocw();
  if (((~uVar1 & 1) == 0) || ((&DAT_0073b230)[iVar2 * 8] == 0)) {
    fVar3 = (float10)0.0;
  }
  else {
    fVar3 = (float10)FUN_00574b70();
  }
  local_60 = (float)(fVar3 * (float10)(float)(&DAT_0073b220)[iVar2 * 8]);
  local_54 = 0;
  local_a0 = 0x3f800000;
  local_9c = 0;
  local_5c = (float)((float10)(float)(&DAT_0073b224)[iVar2 * 8] * fVar3);
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0x3f800000;
  local_58 = (float)((float10)(float)(&DAT_0073b228)[iVar2 * 8] * fVar3);
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0x3f800000;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0x3f800000;
  thunk_FUN_005ac436(&local_70);
  local_70 = 0x3f800000;
  _ftol_nocw();
  FUN_0040b990(auStack_ac,auStack_ac);
  _ftol_nocw();
  FUN_0040ba40(auStack_ac,auStack_ac);
  _ftol_nocw();
  FUN_0040b930();
  D3DXMatrixMultiply(auStack_ac,auStack_ac,&local_5c);
  D3DXMatrixMultiply();
  return;
}


// ==== 0x575200 MaybeCameraShake

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (M+C) docs/re/camera.md */

void __fastcall MaybeCameraShake(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float *in_EAX;
  float10 fVar4;
  float local_38;
  float local_34;
  
  iVar1 = (&DAT_007361b4)[param_1];
  iVar2 = *(int *)(iVar1 + 0x27c);
  if ((((iVar2 == 0) ||
       (((*(int *)(iVar2 + 0xc) != 1 && (*(int *)(iVar2 + 0xc) != 0x11)) ||
        (*(int *)(iVar2 + 0x14) == 0)))) || (*(char *)(iVar1 + 0x24) != '\x03')) &&
     (fVar3 = SQRT(_DAT_00704524 * in_EAX[1] * _DAT_00704524 * in_EAX[1] +
                   _DAT_00704520 * *in_EAX * _DAT_00704520 * *in_EAX +
                   _DAT_00704528 * in_EAX[2] * _DAT_00704528 * in_EAX[2]), 250.0 <= fVar3)) {
    if (600.0 < fVar3) {
      fVar3 = 600.0;
    }
    fVar3 = (fVar3 - 250.0) / 350.0;
    local_38 = fVar3 * 0.08 + 0.08;
    if ((&DAT_0073b230)[param_1 * 8] == 0) {
      fVar4 = (float10)0.0;
    }
    else {
      fVar4 = (float10)FUN_00574b70((&DAT_0073b234)[param_1 * 8]);
    }
    if (fVar4 < (float10)local_38) {
      local_34 = fVar3 * 0.39999998 + 0.3;
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x60) == 7)) {
        local_38 = local_38 * 0.8;
        local_34 = local_34 * _K_BLUR_S_MUL;
      }
      FUN_005673e0(local_38);
      FUN_00574e60(local_34,0x41880000);
      return;
    }
  }
  return;
}


// ==== 0x575390 FUN_00575390

void FUN_00575390(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006caadc;
  return;
}


// ==== 0x5753a0 FUN_005753a0

void * __thiscall FUN_005753a0(void *param_1,byte param_2)

{
  FUN_00575390();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5753c0 FUN_005753c0

void __fastcall FUN_005753c0(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006ba714;
  in_EAX[2] = param_1;
  in_EAX[1] = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x60);
  in_EAX[4] = *(undefined4 *)(param_1 + 100);
  in_EAX[3] = uVar1;
  in_EAX[5] = (float)*(ushort *)(param_1 + 0x3b4) * 9.58738e-05;
  uVar1 = *(undefined4 *)(param_1 + 0x3d4);
  in_EAX[7] = 0;
  in_EAX[6] = uVar1;
  in_EAX[8] = 0;
  return;
}


// ==== 0x575410 FUN_00575410

void __thiscall FUN_00575410(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TrafficMover");
  FUN_00571c20(param_2,param_1 + 0xc,8,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x14,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x18,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x20,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x5754b0 FUN_005754b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_005754b0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  short sVar10;
  float *pfVar11;
  char *pcVar12;
  undefined4 *puVar13;
  int iVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float *local_4c;
  int local_44;
  float fStack_24;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar6 = *(int *)(param_1 + 8);
  iVar14 = *(int *)(iVar6 + 0x20);
  fVar1 = *(float *)(iVar14 + 0xa0);
  fVar7 = -fVar1 + *(float *)(iVar14 + 0x10);
  fVar8 = param_2 * *(float *)(param_1 + 0x18);
  _ftol_nocw();
  fVar15 = (float10)FUN_00564b10();
  fVar2 = (float)fVar15;
  _ftol_nocw();
  fVar15 = (float10)FUN_00564b10();
  fVar16 = (float10)*(ushort *)(*(int *)(iVar6 + 0x30) + 0x1d0) * (float10)9.58738e-05;
  if ((float10)3.14159 < fVar16) {
    fVar16 = fVar16 - (float10)6.28318;
  }
  fVar17 = (float10)fVar7 * (float10)0.01;
  local_1c = fVar2;
  if ((fVar17 <= fVar16) || (fVar16 <= -fVar17)) {
    fVar9 = --fVar1;
    fVar16 = (float10)fVar7 / fVar16;
    fVar1 = (float)(-fVar15 * fVar16 + (float10)(fVar2 * fVar9 + *(float *)(param_1 + 0xc)));
    fVar2 = (float)((float10)fVar2 * fVar16 +
                   (float10)(fVar9 * (float)fVar15 + *(float *)(param_1 + 0x10)));
    _ftol_nocw();
    fVar15 = (float10)FUN_00564b10();
    _ftol_nocw();
    fVar17 = (float10)FUN_00564b10();
    fVar18 = (float10)*(float *)(param_1 + 0xc) - (float10)fVar1;
    fVar19 = (float10)*(float *)(param_1 + 0x10) - (float10)fVar2;
    *(float *)(param_1 + 0xc) = fVar1 + (float)(fVar18 * (float10)(float)fVar15 - fVar19 * fVar17);
    *(float *)(param_1 + 0x10) = fVar2 + (float)(fVar19 * (float10)(float)fVar15 + fVar18 * fVar17);
    *(float *)(param_1 + 0x14) = (float)((float10)fVar8 / fVar16) + *(float *)(param_1 + 0x14);
  }
  else {
    *(float *)(param_1 + 0xc) = fVar2 * fVar8 + *(float *)(param_1 + 0xc);
    *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + (float)fVar15 * fVar8;
  }
  fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x1dc);
  fVar15 = (float10)FUN_00583ea0(*(undefined4 *)(param_1 + 0x18));
  fVar2 = *(float *)(*(int *)(param_1 + 4) + 0x1e4);
  fVar16 = (float10)FUN_00583ea0(*(undefined4 *)(param_1 + 0x18));
  fVar15 = ((float10)(float)(fVar15 * (float10)fVar1 * (float10)param_2) -
           fVar16 * (float10)fVar2 * (float10)param_2) + (float10)*(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x18) = (float)fVar15;
  if ((float10)0.0 <= fVar15) {
    if ((float10)_TeleportSpeedFlip < fVar15) {
      *(undefined4 *)(param_1 + 0x18) = 0x41c4b127;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  iVar6 = *(int *)(param_1 + 8);
  fVar1 = *(float *)(iVar6 + 100);
  fVar7 = *(float *)(iVar6 + 0x60);
  fVar2 = *(float *)(iVar6 + 0x68);
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  local_18 = *(float *)(iVar6 + 0x68);
  *(undefined4 *)(iVar6 + 0x60) = *(undefined4 *)(param_1 + 0xc);
  *(float *)(iVar6 + 0x68) = local_18;
  *(undefined4 *)(iVar6 + 100) = uVar3;
  FUN_004278d0();
  local_20 = *(float *)(iVar6 + 0x60) - fVar7;
  local_1c = *(float *)(iVar6 + 100) - fVar1;
  local_18 = *(float *)(iVar6 + 0x68) - fVar2;
  if (ABS(*(float *)(param_1 + 0x18)) <= _K_EPS_SPEED) {
    fVar7 = 0.0;
    fVar9 = 0.0;
    fVar8 = 0.0;
  }
  else {
    FUN_005673e0(*(undefined4 *)(param_1 + 0x18));
    fVar7 = local_18;
    fVar8 = local_20;
    fVar9 = local_1c;
  }
  *(float *)(iVar6 + 0x70) = fVar8;
  *(float *)(iVar6 + 0x74) = fVar9;
  *(float *)(iVar6 + 0x78) = fVar7;
  sVar5 = *(short *)(iVar6 + 0x3b4);
  *(undefined1 *)(iVar6 + 0x460) = 0;
  *(float *)(iVar6 + 0x3d4) = SQRT(fVar7 * fVar7 + fVar9 * fVar9 + fVar8 * fVar8);
  *(undefined4 *)(iVar6 + 0x3d0) = *(undefined4 *)(param_1 + 0x18);
  sVar10 = _ftol_nocw();
  *(short *)(iVar6 + 0x3b4) = sVar10;
  local_44 = 4;
  *(undefined4 *)(iVar6 + 0xd0) = 0;
  *(undefined4 *)(iVar6 + 0xd4) = 0;
  puVar13 = (undefined4 *)(iVar6 + 0x374);
  *(float *)(iVar6 + 0xd8) = ((float)(int)(short)(sVar10 - sVar5) * 9.5873795e-05) / param_2;
  *(undefined2 *)(iVar6 + 0x3b6) = *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x1d0);
  pcVar12 = (char *)(iVar6 + 0x350);
  local_4c = (float *)(iVar14 + 0x20);
  pfVar11 = (float *)(iVar6 + 0x300);
  do {
    fVar7 = (_K_ONE / *local_4c) * *(float *)(param_1 + 0x18);
    pfVar11[0x10] = 0.0;
    pfVar11[-4] = fVar7;
    *pfVar11 = fVar7 * param_2 + *pfVar11;
    cVar4 = *pcVar12;
    *pcVar12 = '\x01';
    if (cVar4 == '\0') {
      *(int *)(iVar6 + 0x3cc) = *(int *)(iVar6 + 0x3cc) + 1;
    }
    pfVar11[0x15] = 1.4013e-45;
    if ((int)pfVar11[0x19] < 1) {
      pfVar11[0x19] = 1.4013e-45;
    }
    *puVar13 = 0;
    puVar13[1] = 0;
    pfVar11[0x25] = 0.0;
    pfVar11[4] = 0.0;
    *(undefined4 *)(iVar6 + 0x330) = 0;
    *(undefined4 *)(iVar6 + 0x334) = 0;
    *(undefined4 *)(iVar6 + 0x338) = 0;
    *(undefined4 *)(iVar6 + 0x33c) = 0;
    local_4c = local_4c + 0xc;
    pfVar11 = pfVar11 + 1;
    pcVar12 = pcVar12 + 1;
    puVar13 = puVar13 + 2;
    local_44 = local_44 + -1;
  } while (local_44 != 0);
  iVar14 = 0;
  do {
    FUN_00465150((undefined4 *)(iVar6 + 0x40));
    iVar14 = iVar14 + 1;
  } while (iVar14 < 4);
  D3DXVec3Transform(&local_20,*(undefined4 *)(iVar6 + 0x40),iVar6 + 0x90);
  *(float *)(iVar6 + 0x50) = *(float *)(iVar6 + 0x60) - fVar1;
  *(float *)(iVar6 + 0x58) = *(float *)(iVar6 + 0x68) - fStack_24;
  *(float *)(iVar6 + 0x54) = *(float *)(iVar6 + 100) - fVar2;
  FUN_00427a30();
  return (float10)param_2;
}


// ==== 0x575940 NullChunk::Loader

/* [canon] assets high (capstone) docs/re/assets.md */

undefined4 NullChunk__Loader(void)

{
  return 0;
}


// ==== 0x575950 FUN_00575950

undefined4 __fastcall FUN_00575950(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + param_1 * 4);
}


// ==== 0x575960 CompleatCarPhysicsInfo::BuildCarPhysicsInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void CompleatCarPhysicsInfo__BuildCarPhysicsInfo
               (undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = param_2;
  for (iVar1 = 0xac; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00575a10(param_1);
  FUN_00575a90(param_1,param_3);
  FUN_00575b30();
  iVar1 = *(int *)(param_3 + 0x20);
  if ((0 < iVar1) && (iVar1 < 4)) {
    iVar1 = iVar1 + 0x6f;
    param_2[0x9d] = param_1[iVar1 * 4];
    param_2[0x9f] = param_1[iVar1 * 4 + 2];
    param_2[0x9e] = param_1[iVar1 * 4 + 1];
  }
  if (*(int *)(param_3 + 0x4c) != 0) {
    param_2[0x9d] = (float)param_1[0x20b] + (float)param_2[0x9d];
  }
  FUN_00575bc0(param_3);
  FUN_00576360(param_1,param_2,param_3);
  CompleatCarPhysicsInfo__BuildBodyInfo();
  return;
}


// ==== 0x575a10 FUN_00575a10

void __thiscall FUN_00575a10(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((0 < iVar1) && (iVar1 < 4)) {
    puVar2 = (undefined4 *)((iVar1 * 5 + 0x6e) * 0x10 + param_2);
    puVar3 = puVar2;
    puVar4 = (undefined4 *)(in_EAX + 0x170);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = puVar2 + 8;
    puVar4 = (undefined4 *)(in_EAX + 400);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(float *)(in_EAX + 0x18) = *(float *)(in_EAX + 0x18) + (float)puVar2[0x11];
    *(float *)(in_EAX + 0x48) = *(float *)(in_EAX + 0x48) + (float)puVar2[0x11];
    *(float *)(in_EAX + 0x78) = *(float *)(in_EAX + 0x78) + (float)puVar2[0x12];
    *(float *)(in_EAX + 0xa8) = *(float *)(in_EAX + 0xa8) + (float)puVar2[0x12];
    *(float *)(in_EAX + 8) = *(float *)(in_EAX + 8) - (float)puVar2[0x10];
  }
  return;
}


// ==== 0x575a90 FUN_00575a90

void __fastcall FUN_00575a90(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_4 + 0x1c);
  if ((0 < iVar1) && (iVar1 < 4)) {
    puVar3 = (undefined4 *)(iVar1 * 0x40 + 0x570 + param_3);
    puVar2 = puVar3;
    puVar4 = (undefined4 *)(param_2 + 0xd0);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = puVar3 + 8;
    puVar2 = (undefined4 *)(param_2 + 0xf0);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  if (*(int *)(param_4 + 0x48) != 0) {
    *(float *)(param_2 + 0xdc) = *(float *)(param_3 + 0x830) + *(float *)(param_2 + 0xdc);
    *(float *)(param_2 + 0xe0) = *(float *)(param_3 + 0x838) + *(float *)(param_2 + 0xe0);
    *(float *)(param_2 + 0xfc) = *(float *)(param_3 + 0x834) + *(float *)(param_2 + 0xfc);
    *(float *)(param_2 + 0x100) = *(float *)(param_3 + 0x83c) + *(float *)(param_2 + 0x100);
  }
  return;
}


// ==== 0x575b30 FUN_00575b30

void __fastcall FUN_00575b30(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(param_2 + 0x28);
  if ((0 < iVar1) && (iVar1 < 4)) {
    iVar1 = (iVar1 + 0x6c) * 0x10;
    iVar2 = iVar1 + unaff_ESI;
    *(float *)(in_EAX + 0x264) = *(float *)(iVar1 + unaff_ESI) + *(float *)(in_EAX + 0x264);
    *(float *)(in_EAX + 0x268) = *(float *)(iVar2 + 4) + *(float *)(in_EAX + 0x268);
    *(float *)(in_EAX + 0x26c) = *(float *)(iVar2 + 8) + *(float *)(in_EAX + 0x26c);
  }
  iVar1 = *(int *)(param_2 + 0x24);
  if ((0 < iVar1) && (iVar1 < 4)) {
    iVar1 = (iVar1 + 0x69) * 0x10;
    iVar2 = iVar1 + unaff_ESI;
    *(float *)(in_EAX + 0x264) = *(float *)(iVar1 + unaff_ESI) + *(float *)(in_EAX + 0x264);
    *(float *)(in_EAX + 0x268) = *(float *)(iVar2 + 4) + *(float *)(in_EAX + 0x268);
    *(float *)(in_EAX + 0x26c) = *(float *)(iVar2 + 8) + *(float *)(in_EAX + 0x26c);
  }
  return;
}


// ==== 0x575bc0 FUN_00575bc0

void __fastcall FUN_00575bc0(undefined4 param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_3 + 8);
  if ((0 < iVar2) && (iVar2 < 4)) {
    iVar1 = iVar2 * 0x40 + 0x360 + param_2;
    *(float *)(in_EAX + 0x1f0) =
         *(float *)(iVar2 * 0x40 + 0x360 + param_2) + *(float *)(in_EAX + 0x1f0);
    *(float *)(in_EAX + 500) = *(float *)(iVar1 + 4) + *(float *)(in_EAX + 500);
    *(float *)(in_EAX + 0x1f8) = *(float *)(iVar1 + 8) + *(float *)(in_EAX + 0x1f8);
    *(float *)(in_EAX + 0x1fc) = *(float *)(iVar1 + 0xc) + *(float *)(in_EAX + 0x1fc);
    *(float *)(in_EAX + 0x200) = *(float *)(iVar1 + 0x10) + *(float *)(in_EAX + 0x200);
    *(float *)(in_EAX + 0x204) = *(float *)(iVar1 + 0x14) + *(float *)(in_EAX + 0x204);
    *(float *)(in_EAX + 0x208) = *(float *)(iVar1 + 0x18) + *(float *)(in_EAX + 0x208);
    *(float *)(in_EAX + 0x20c) = *(float *)(iVar1 + 0x1c) + *(float *)(in_EAX + 0x20c);
    *(float *)(in_EAX + 0x210) = *(float *)(iVar1 + 0x20) + *(float *)(in_EAX + 0x210);
    *(float *)(in_EAX + 0x214) = *(float *)(iVar1 + 0x24) + *(float *)(in_EAX + 0x214);
    *(float *)(in_EAX + 0x218) = *(float *)(iVar1 + 0x28) + *(float *)(in_EAX + 0x218);
    *(float *)(in_EAX + 0x21c) = *(float *)(iVar1 + 0x2c) + *(float *)(in_EAX + 0x21c);
    *(float *)(in_EAX + 0x220) = *(float *)(iVar1 + 0x30) + *(float *)(in_EAX + 0x220);
    *(float *)(in_EAX + 0x248) = *(float *)(iVar1 + 0x34) + *(float *)(in_EAX + 0x248);
    *(float *)(in_EAX + 0x24c) = *(float *)(iVar1 + 0x38) + *(float *)(in_EAX + 0x24c);
    *(float *)(in_EAX + 0x250) = *(float *)(iVar1 + 0x3c) + *(float *)(in_EAX + 0x250);
  }
  iVar2 = *(int *)(param_3 + 0x14);
  if ((0 < iVar2) && (iVar2 < 4)) {
    iVar1 = iVar2 * 0x40 + 0x420 + param_2;
    *(float *)(in_EAX + 0x1f0) =
         *(float *)(iVar2 * 0x40 + 0x420 + param_2) + *(float *)(in_EAX + 0x1f0);
    *(float *)(in_EAX + 500) = *(float *)(iVar1 + 4) + *(float *)(in_EAX + 500);
    *(float *)(in_EAX + 0x1f8) = *(float *)(iVar1 + 8) + *(float *)(in_EAX + 0x1f8);
    *(float *)(in_EAX + 0x1fc) = *(float *)(iVar1 + 0xc) + *(float *)(in_EAX + 0x1fc);
    *(float *)(in_EAX + 0x200) = *(float *)(iVar1 + 0x10) + *(float *)(in_EAX + 0x200);
    *(float *)(in_EAX + 0x204) = *(float *)(iVar1 + 0x14) + *(float *)(in_EAX + 0x204);
    *(float *)(in_EAX + 0x208) = *(float *)(iVar1 + 0x18) + *(float *)(in_EAX + 0x208);
    *(float *)(in_EAX + 0x20c) = *(float *)(iVar1 + 0x1c) + *(float *)(in_EAX + 0x20c);
    *(float *)(in_EAX + 0x210) = *(float *)(iVar1 + 0x20) + *(float *)(in_EAX + 0x210);
    *(float *)(in_EAX + 0x214) = *(float *)(iVar1 + 0x24) + *(float *)(in_EAX + 0x214);
    *(float *)(in_EAX + 0x218) = *(float *)(iVar1 + 0x28) + *(float *)(in_EAX + 0x218);
    *(float *)(in_EAX + 0x21c) = *(float *)(iVar1 + 0x2c) + *(float *)(in_EAX + 0x21c);
    *(float *)(in_EAX + 0x220) = *(float *)(iVar1 + 0x30) + *(float *)(in_EAX + 0x220);
    *(float *)(in_EAX + 0x248) = *(float *)(iVar1 + 0x34) + *(float *)(in_EAX + 0x248);
    *(float *)(in_EAX + 0x24c) = *(float *)(iVar1 + 0x38) + *(float *)(in_EAX + 0x24c);
    *(float *)(in_EAX + 0x250) = *(float *)(iVar1 + 0x3c) + *(float *)(in_EAX + 0x250);
  }
  iVar2 = *(int *)(param_3 + 0xc);
  if ((0 < iVar2) && (iVar2 < 4)) {
    puVar3 = (undefined4 *)(iVar2 * 0x30 + 0x4f0 + param_2);
    puVar4 = (undefined4 *)(in_EAX + 0x224);
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  *(float *)(in_EAX + 0x200) = *(float *)(in_EAX + 0x224) + *(float *)(in_EAX + 0x200);
  *(float *)(in_EAX + 0x204) = *(float *)(in_EAX + 0x228) + *(float *)(in_EAX + 0x204);
  *(float *)(in_EAX + 0x208) = *(float *)(in_EAX + 0x22c) + *(float *)(in_EAX + 0x208);
  *(float *)(in_EAX + 0x20c) = *(float *)(in_EAX + 0x230) + *(float *)(in_EAX + 0x20c);
  *(float *)(in_EAX + 0x210) = *(float *)(in_EAX + 0x234) + *(float *)(in_EAX + 0x210);
  *(float *)(in_EAX + 0x214) = *(float *)(in_EAX + 0x238) + *(float *)(in_EAX + 0x214);
  *(float *)(in_EAX + 0x218) = *(float *)(in_EAX + 0x23c) + *(float *)(in_EAX + 0x218);
  *(float *)(in_EAX + 0x21c) = *(float *)(in_EAX + 0x240) + *(float *)(in_EAX + 0x21c);
  *(float *)(in_EAX + 0x220) = *(float *)(in_EAX + 0x244) + *(float *)(in_EAX + 0x220);
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x200) = *(float *)(param_2 + 0x840) + *(float *)(in_EAX + 0x200);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x200) = *(float *)(param_2 + 0x864) + *(float *)(in_EAX + 0x200);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x200) = *(float *)(param_2 + 0x888) + *(float *)(in_EAX + 0x200);
    *(float *)(in_EAX + 0x224) = *(float *)(param_2 + 0x888) + *(float *)(in_EAX + 0x224);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x204) = *(float *)(param_2 + 0x844) + *(float *)(in_EAX + 0x204);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x204) = *(float *)(param_2 + 0x868) + *(float *)(in_EAX + 0x204);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x204) = *(float *)(param_2 + 0x88c) + *(float *)(in_EAX + 0x204);
    *(float *)(in_EAX + 0x228) = *(float *)(in_EAX + 0x228) + *(float *)(param_2 + 0x88c);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x208) = *(float *)(param_2 + 0x848) + *(float *)(in_EAX + 0x208);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x208) = *(float *)(param_2 + 0x86c) + *(float *)(in_EAX + 0x208);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x208) = *(float *)(param_2 + 0x890) + *(float *)(in_EAX + 0x208);
    *(float *)(in_EAX + 0x22c) = *(float *)(in_EAX + 0x22c) + *(float *)(param_2 + 0x890);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x20c) = *(float *)(param_2 + 0x84c) + *(float *)(in_EAX + 0x20c);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x20c) = *(float *)(param_2 + 0x870) + *(float *)(in_EAX + 0x20c);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x20c) = *(float *)(param_2 + 0x894) + *(float *)(in_EAX + 0x20c);
    *(float *)(in_EAX + 0x230) = *(float *)(param_2 + 0x894) + *(float *)(in_EAX + 0x230);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x210) = *(float *)(param_2 + 0x850) + *(float *)(in_EAX + 0x210);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x210) = *(float *)(param_2 + 0x874) + *(float *)(in_EAX + 0x210);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x210) = *(float *)(param_2 + 0x898) + *(float *)(in_EAX + 0x210);
    *(float *)(in_EAX + 0x234) = *(float *)(param_2 + 0x898) + *(float *)(in_EAX + 0x234);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x214) = *(float *)(param_2 + 0x854) + *(float *)(in_EAX + 0x214);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x214) = *(float *)(param_2 + 0x878) + *(float *)(in_EAX + 0x214);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x214) = *(float *)(param_2 + 0x89c) + *(float *)(in_EAX + 0x214);
    *(float *)(in_EAX + 0x238) = *(float *)(in_EAX + 0x238) + *(float *)(param_2 + 0x89c);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x218) = *(float *)(param_2 + 0x858) + *(float *)(in_EAX + 0x218);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x218) = *(float *)(param_2 + 0x87c) + *(float *)(in_EAX + 0x218);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x218) = *(float *)(param_2 + 0x8a0) + *(float *)(in_EAX + 0x218);
    *(float *)(in_EAX + 0x23c) = *(float *)(in_EAX + 0x23c) + *(float *)(param_2 + 0x8a0);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x21c) = *(float *)(param_2 + 0x85c) + *(float *)(in_EAX + 0x21c);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x21c) = *(float *)(param_2 + 0x880) + *(float *)(in_EAX + 0x21c);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x21c) = *(float *)(param_2 + 0x8a4) + *(float *)(in_EAX + 0x21c);
    *(float *)(in_EAX + 0x240) = *(float *)(param_2 + 0x8a4) + *(float *)(in_EAX + 0x240);
  }
  if (*(int *)(param_3 + 0x34) != 0) {
    *(float *)(in_EAX + 0x220) = *(float *)(param_2 + 0x860) + *(float *)(in_EAX + 0x220);
  }
  if (*(int *)(param_3 + 0x40) != 0) {
    *(float *)(in_EAX + 0x220) = *(float *)(param_2 + 0x884) + *(float *)(in_EAX + 0x220);
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    *(float *)(in_EAX + 0x220) = *(float *)(param_2 + 0x8a8) + *(float *)(in_EAX + 0x220);
    *(float *)(in_EAX + 0x244) = *(float *)(param_2 + 0x8a8) + *(float *)(in_EAX + 0x244);
  }
  iVar2 = *(int *)(param_3 + 0x10);
  if ((0 < iVar2) && (iVar2 < 4)) {
    iVar2 = (iVar2 + 0x66) * 0x10;
    iVar1 = iVar2 + param_2;
    *(undefined4 *)(in_EAX + 0x2a0) = *(undefined4 *)(iVar2 + param_2);
    *(undefined4 *)(in_EAX + 0x2a4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(in_EAX + 0x2a8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(in_EAX + 0x2ac) = *(undefined4 *)(iVar1 + 0xc);
  }
  if (*(int *)(param_3 + 0x3c) != 0) {
    *(float *)(in_EAX + 0x2ac) = *(float *)(param_2 + 0x828) + *(float *)(in_EAX + 0x2ac);
  }
  return;
}


// ==== 0x576250 CompleatCarPhysicsInfo::BuildBodyInfo

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void CompleatCarPhysicsInfo__BuildBodyInfo(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  int iVar4;
  int unaff_ESI;
  int *unaff_EDI;
  
  iVar4 = *unaff_EDI;
  fVar1 = _K_ONE;
  if ((0 < iVar4) && (iVar4 < 4)) {
    iVar4 = (iVar4 + 0x2a) * 0x10;
    fVar1 = *(float *)(iVar4 + unaff_ESI);
    iVar4 = iVar4 + unaff_ESI;
    *in_EAX = *(float *)(iVar4 + 4) + *in_EAX;
    in_EAX[0x58] = *(float *)(iVar4 + 8);
  }
  if (unaff_EDI[0xb] != 0) {
    fVar1 = fVar1 - *(float *)(unaff_ESI + 0x820);
  }
  in_EAX[0x44] = fVar1 * *(float *)(unaff_ESI + 0x110);
  in_EAX[0x48] = 1.0;
  in_EAX[0x49] = 0.0;
  in_EAX[0x4a] = 0.0;
  in_EAX[0x4b] = 0.0;
  in_EAX[0x4c] = 0.0;
  in_EAX[0x4d] = 1.0;
  in_EAX[0x4e] = 0.0;
  in_EAX[0x4f] = 0.0;
  in_EAX[0x50] = 0.0;
  in_EAX[0x51] = 0.0;
  in_EAX[0x52] = 1.0;
  in_EAX[0x53] = 0.0;
  in_EAX[0x54] = 0.0;
  in_EAX[0x55] = 0.0;
  in_EAX[0x56] = 0.0;
  in_EAX[0x57] = 1.0;
  fVar1 = in_EAX[0x45] * in_EAX[0x45];
  fVar3 = in_EAX[0x46] * in_EAX[0x46];
  fVar2 = in_EAX[0x47] * in_EAX[0x47];
  in_EAX[0x48] = (fVar2 + fVar3) * in_EAX[0x44] * 0.083333336;
  in_EAX[0x4d] = (fVar2 + fVar1) * in_EAX[0x44] * 0.083333336;
  in_EAX[0x52] = (fVar3 + fVar1) * in_EAX[0x44] * 0.083333336;
  return;
}


// ==== 0x576360 FUN_00576360

void FUN_00576360(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_3 + 0x18);
  if ((0 < iVar2) && (iVar2 < 4)) {
    iVar1 = iVar2 * 0x40 + 0x2a0 + param_1;
    *(undefined4 *)(param_2 + 0x1b0) = *(undefined4 *)(iVar2 * 0x40 + 0x2a0 + param_1);
    *(undefined4 *)(param_2 + 0x1b4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(param_2 + 0x1b8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(param_2 + 0x1bc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(param_2 + 0x1c0) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(param_2 + 0x1c4) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(param_2 + 0x1cc) = *(undefined4 *)(iVar1 + 0x1c);
    puVar3 = (undefined4 *)(iVar1 + 0x20);
    puVar5 = (undefined4 *)(param_2 + 0x1d0);
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined4 *)(iVar1 + 0x18) = 0;
    iVar2 = 2;
    pfVar4 = (float *)(iVar1 + 0x28);
    do {
      if (*pfVar4 == 0.0) break;
      iVar2 = iVar2 + 1;
      pfVar4 = pfVar4 + 1;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    } while (iVar2 < 8);
    *(undefined4 *)(param_2 + 0x1c8) = *(undefined4 *)(iVar1 + 0x18);
  }
  if (*(int *)(param_3 + 0x44) != 0) {
    *(undefined4 *)(param_2 + 0x1c0) = *(undefined4 *)(param_1 + 0x824);
  }
  return;
}


// ==== 0x576440 FUN_00576440

uint FUN_00576440(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
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
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  
  puVar6 = &local_2b8;
  for (iVar3 = 0xac; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_2b8 = _ftol_nocw();
  local_2b4 = _ftol_nocw();
  local_2b0 = _ftol_nocw();
  local_2ac = _ftol_nocw();
  local_2a8 = _ftol_nocw();
  local_2a4 = _ftol_nocw();
  local_2a0 = _ftol_nocw();
  local_29c = _ftol_nocw();
  local_298 = _ftol_nocw();
  local_294 = _ftol_nocw();
  local_290 = _ftol_nocw();
  local_28c = _ftol_nocw();
  local_288 = _ftol_nocw();
  local_284 = _ftol_nocw();
  local_280 = _ftol_nocw();
  local_27c = _ftol_nocw();
  local_278 = _ftol_nocw();
  local_274 = _ftol_nocw();
  local_270 = _ftol_nocw();
  local_26c = _ftol_nocw();
  local_268 = _ftol_nocw();
  local_264 = _ftol_nocw();
  local_260 = _ftol_nocw();
  local_25c = _ftol_nocw();
  local_258 = _ftol_nocw();
  local_254 = _ftol_nocw();
  local_250 = _ftol_nocw();
  local_24c = _ftol_nocw();
  local_248 = _ftol_nocw();
  local_244 = _ftol_nocw();
  local_240 = _ftol_nocw();
  local_23c = _ftol_nocw();
  local_238 = _ftol_nocw();
  local_234 = _ftol_nocw();
  local_230 = _ftol_nocw();
  local_22c = _ftol_nocw();
  local_228 = _ftol_nocw();
  local_224 = _ftol_nocw();
  local_220 = _ftol_nocw();
  local_21c = _ftol_nocw();
  local_218 = _ftol_nocw();
  local_214 = _ftol_nocw();
  local_210 = _ftol_nocw();
  local_20c = _ftol_nocw();
  local_208 = _ftol_nocw();
  local_204 = _ftol_nocw();
  local_200 = _ftol_nocw();
  local_1fc = _ftol_nocw();
  local_1f8 = _ftol_nocw();
  local_1f4 = _ftol_nocw();
  local_1f0 = _ftol_nocw();
  local_1ec = _ftol_nocw();
  local_1e8 = _ftol_nocw();
  local_1e4 = _ftol_nocw();
  local_1e0 = _ftol_nocw();
  local_1dc = _ftol_nocw();
  local_1d8 = _ftol_nocw();
  local_1d4 = _ftol_nocw();
  local_1d0 = _ftol_nocw();
  local_1cc = _ftol_nocw();
  local_1c8 = _ftol_nocw();
  local_1c4 = _ftol_nocw();
  local_1c0 = _ftol_nocw();
  local_1bc = _ftol_nocw();
  local_1b8 = _ftol_nocw();
  local_1b4 = _ftol_nocw();
  local_1b0 = _ftol_nocw();
  local_1ac = _ftol_nocw();
  local_1a8 = _ftol_nocw();
  local_1a4 = _ftol_nocw();
  local_1a0 = _ftol_nocw();
  local_19c = _ftol_nocw();
  local_198 = _ftol_nocw();
  local_194 = _ftol_nocw();
  local_190 = _ftol_nocw();
  local_18c = _ftol_nocw();
  local_188 = _ftol_nocw();
  iVar3 = 0x4d;
  local_184 = _ftol_nocw();
  local_2bc = 2;
  do {
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 1] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 2] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 3] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 4] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 5] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 6] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 7] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 8] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 9] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 10] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 0xb] = uVar1;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3 + 0xc] = uVar1;
    iVar3 = iVar3 + 0xd;
    uVar1 = _ftol_nocw();
    (&local_2b8)[iVar3] = uVar1;
    local_2bc = local_2bc + -1;
  } while (local_2bc != 0);
  puVar6 = &local_2b8 + iVar3;
  iVar3 = 4;
  do {
    uVar1 = _ftol_nocw();
    puVar6[1] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[2] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[3] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[4] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[5] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[6] = uVar1;
    uVar1 = _ftol_nocw();
    puVar6[7] = uVar1;
    puVar6 = puVar6 + 8;
    uVar1 = _ftol_nocw();
    iVar3 = iVar3 + -1;
    *puVar6 = uVar1;
  } while (iVar3 != 0);
  uVar7 = 0x2b0;
  uVar2 = 0xffffffff;
  iVar3 = 0x56;
  pbVar4 = (byte *)((int)&local_2b8 + 2);
  do {
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[-2] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[-1] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + (uVar2 >> 0x18 ^ (uint)*pbVar4) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[1] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[2] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[3] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[4] ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
    uVar2 = uVar2 << 8 ^ *(uint *)(&DAT_006b5e80 + ((uint)pbVar4[5] ^ uVar2 >> 0x18) * 4);
    iVar3 = iVar3 + -1;
    pbVar4 = pbVar4 + 8;
  } while (iVar3 != 0);
  do {
    uVar5 = uVar2 >> 0x18 ^ uVar7;
    uVar7 = (int)uVar7 >> 8;
    uVar2 = uVar2 << 8 ^ *(uint *)(&DAT_006b5e80 + (uVar5 & 0xff) * 4);
  } while (uVar7 != 0);
  return ~uVar2;
}


// ==== 0x576e70 FUN_00576e70

undefined4 FUN_00576e70(int param_1,int param_2)

{
  if (*(float *)(param_1 + 0x14) <= *(float *)(param_2 + 0x14)) {
    return 1;
  }
  return 0;
}


// ==== 0x576e90 FUN_00576e90

undefined4 FUN_00576e90(int param_1,int param_2)

{
  if (*(float *)(param_2 + 0x14) <= *(float *)(param_1 + 0x14)) {
    return 1;
  }
  return 0;
}


// ==== 0x576eb0 FUN_00576eb0

void __fastcall FUN_00576eb0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_007306c8;
  iVar1 = *(int *)(DAT_007306c8 + 0x18);
  *param_1 = *(undefined4 *)(DAT_007306c8 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x576ed0 FUN_00576ed0

void __fastcall FUN_00576ed0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba6dc;
  FUN_00577290();
  return;
}


// ==== 0x576ee0 FUN_00576ee0

undefined4 * __thiscall FUN_00576ee0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00576ed0();
  iVar2 = DAT_007306c8;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_007306c8 + 0x18);
    *param_1 = *(undefined4 *)(DAT_007306c8 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x576f10 FUN_00576f10

void __fastcall FUN_00576f10(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_007306cc;
  iVar1 = *(int *)(DAT_007306cc + 0x18);
  *param_1 = *(undefined4 *)(DAT_007306cc + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x576f30 FUN_00576f30

void __fastcall FUN_00576f30(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  
  iVar3 = *(int *)(in_EAX + 0x10);
  iVar4 = *(int *)(iVar3 + 0x10);
  if (iVar4 == 1) {
    FUN_004733a0(param_2);
  }
  else {
    if (iVar4 == 3) {
      FUN_00472aa0();
      return;
    }
    if (iVar4 == 4) {
      uVar1 = *(undefined4 *)(iVar3 + 0x34);
      uVar2 = *(undefined4 *)(iVar3 + 0x38);
      *param_2 = *(undefined4 *)(iVar3 + 0x30);
      param_2[1] = uVar1;
      param_2[2] = uVar2;
      uVar1 = *(undefined4 *)(iVar3 + 0x34);
      uVar2 = *(undefined4 *)(iVar3 + 0x38);
      *param_1 = *(undefined4 *)(iVar3 + 0x30);
      param_1[1] = uVar1;
      param_1[2] = uVar2;
      return;
    }
  }
  return;
}


// ==== 0x576f80 FUN_00576f80

void FUN_00576f80(void)

{
  undefined4 *puVar1;
  
  DAT_007306c8 = (undefined4 *)FUN_00566dc0(0x28,"MobileTopologySlotPool",0);
  if ((DAT_007306c8 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007306c8;
    puVar1 = DAT_007306c8;
    DAT_007306c8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007306c8 = &DAT_0073d818;
  }
  DAT_007306cc = (undefined4 *)FUN_00566dc0(0xd0,"MobileTrackPolygonSlotPool",0);
  if (DAT_007306cc == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007306cc;
    puVar1 = DAT_007306cc;
    DAT_007306cc[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007306cc = &DAT_0073d818;
  }
  return;
}


// ==== 0x577010 FUN_00577010

void FUN_00577010(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0073b14c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_0073b14c + -4;
  }
  iVar1 = Ptr_BaseAdjustMinus4();
  while (iVar2 != iVar1) {
    FUN_005772f0(iVar2);
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  bList__Sort(&DAT_0073b14c,FUN_00576e70);
  return;
}


// ==== 0x577060 FUN_00577060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00577060(undefined1 *param_1,float *param_2,float param_3,int param_4,
                    undefined4 *param_5,undefined4 *param_6,char *param_7)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  char local_41;
  float local_40;
  float local_3c;
  undefined4 local_38;
  int local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  *param_1 = 0;
  iVar4 = DAT_0073b14c;
  if (DAT_0073b14c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_0073b14c + -4;
  }
  local_34 = Ptr_BaseAdjustMinus4();
  while (iVar3 != local_34) {
    if (*(int *)(iVar3 + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 4) + -4;
    }
  }
  local_28 = *param_2;
  local_24 = param_2[1];
  local_30 = param_2[2];
  local_2c = param_2[3];
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = iVar4 + -4;
  }
  if (iVar4 != local_34) {
    do {
      if ((((*(float *)(iVar4 + 0xc) < local_30) && (local_28 < *(float *)(iVar4 + 0x14))) &&
          (*(float *)(iVar4 + 0x10) < local_2c)) && (local_24 < *(float *)(iVar4 + 0x18))) {
        *param_1 = 1;
        local_41 = '\0';
        fVar5 = (float10)FUN_00577370(iVar4,param_4,&local_38,&local_20,&local_41);
        local_40 = (float)fVar5;
        if (local_41 != '\0') {
          local_3c = *(float *)(param_4 + 8) + _K_ONE;
          fVar1 = param_3;
          if (local_3c <= param_3) {
            fVar1 = param_3 - 50000.0;
          }
          fVar2 = local_40;
          if (local_3c <= local_40) {
            fVar2 = local_40 - 50000.0;
          }
          if ((fVar1 < fVar2) || ((param_7 != (char *)0x0 && (*param_7 == '\0')))) {
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = local_38;
            }
            if (param_6 != (undefined4 *)0x0) {
              *param_6 = local_20;
              param_6[1] = local_1c;
              param_6[2] = local_18;
            }
            param_3 = local_40;
            if (param_7 != (char *)0x0) {
              *param_7 = local_41;
            }
          }
        }
      }
      if (*(int *)(iVar4 + 4) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 4) + -4;
      }
    } while (iVar4 != local_34);
  }
  return (float10)param_3;
}


// ==== 0x577210 FUN_00577210

undefined4 * FUN_00577210(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068564b;
  local_c = ExceptionList;
  puVar1 = param_1 + 8;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006ba6d8;
  *puVar1 = puVar1;
  param_1[9] = puVar1;
  local_4 = 0;
  param_1[7] = param_2;
  FUN_00564940(&DAT_0073b14c,FUN_00576e90);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x577270 FUN_00577270

void * __thiscall FUN_00577270(void *param_1,byte param_2)

{
  FUN_00577290();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x577290 FUN_00577290

void __fastcall FUN_00577290(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = param_1 + 8;
  *param_1 = &PTR_FUN_006ba6d8;
  iVar4 = DAT_007306cc;
  piVar1 = (int *)*piVar5;
  while (piVar1 != piVar5) {
    piVar1 = (int *)*piVar5;
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1[3] != 0) {
      *(undefined2 *)(piVar1[3] + 6) = 0xffff;
    }
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*piVar5;
  }
  iVar4 = param_1[1];
  piVar5 = (int *)param_1[2];
  *piVar5 = iVar4;
  *(int **)(iVar4 + 4) = piVar5;
  FUN_00441fa0();
  return;
}


// ==== 0x5772f0 FUN_005772f0

void FUN_005772f0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x20);
  if (piVar5 != (int *)(param_1 + 0x20)) {
    do {
      piVar1 = *(int **)(param_1 + 0x1c);
      uVar3 = (**(code **)(*piVar1 + 0x14))();
      uVar4 = (**(code **)(*piVar1 + 8))(uVar3);
      FUN_00577730(uVar4,uVar3);
      if (piVar5 == *(int **)(param_1 + 0x20)) {
        iVar2 = piVar5[5];
        *(int *)(param_1 + 0x10) = piVar5[6];
        *(int *)(param_1 + 0xc) = iVar2;
        iVar2 = piVar5[7];
        *(int *)(param_1 + 0x18) = piVar5[8];
        *(int *)(param_1 + 0x14) = iVar2;
      }
      else {
        FUN_00567690();
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)(param_1 + 0x20));
  }
  return;
}


// ==== 0x577367 FUN_00577367

undefined4 FUN_00577367(void)

{
  int in_EAX;
  
  return CONCAT31((int3)((uint)(in_EAX + -1) >> 8),(char)(in_EAX + -1) + -0x18);
}


// ==== 0x577370 FUN_00577370

float10 FUN_00577370(int param_1,float *param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined1 *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float fVar3;
  bool bVar4;
  float *pfVar5;
  undefined4 uVar6;
  float10 fVar7;
  
  pfVar5 = param_2;
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  bVar4 = false;
  param_2 = (float *)0x0;
  for (; puVar2 != (undefined4 *)(param_1 + 0x20); puVar2 = (undefined4 *)*puVar2) {
    if (((0.0 < (float)puVar2[0x1e]) &&
        (fVar7 = (float10)TrackPolyBody__EdgeDistanceMax(),
        fVar7 < (float10)0.0 != (fVar7 == (float10)0.0))) &&
       ((fVar3 = -(((*pfVar5 * (float)puVar2[0x1c] + (float)puVar2[0x1d] * pfVar5[1]) -
                   (float)puVar2[0x1f]) / (float)puVar2[0x1e]), !bVar4 || ((float)param_2 < fVar3)))
       ) {
      bVar4 = true;
      if (param_3 != (undefined4 *)0x0) {
        uVar6 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x54))();
        *param_3 = uVar6;
      }
      if (param_4 != (undefined4 *)0x0) {
        uVar6 = puVar2[0x1d];
        uVar1 = puVar2[0x1e];
        *param_4 = puVar2[0x1c];
        param_4[1] = uVar6;
        param_4[2] = uVar1;
      }
      param_2 = (float *)fVar3;
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = 1;
      }
    }
  }
  return (float10)(float)param_2;
}


// ==== 0x577450 FUN_00577450

undefined4 * FUN_00577450(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  void *pvStack_1c;
  code *pcStack_18;
  int local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00685f90;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_00577210(param_1,param_2);
  *param_1 = &PTR_FUN_006ba6dc;
  iVar1 = param_2[4];
  iVar3 = *(int *)(iVar1 + 0x10);
  local_14 = 0;
  if (iVar3 == 1) {
    FUN_004733a0(&local_70);
  }
  else if (iVar3 == 3) {
    FUN_00472aa0();
  }
  else if (iVar3 == 4) {
    local_6c = *(undefined4 *)(iVar1 + 0x34);
    local_70 = *(undefined4 *)(iVar1 + 0x30);
    local_80 = *(undefined4 *)(iVar1 + 0x30);
    local_7c = *(undefined4 *)(iVar1 + 0x34);
    local_78 = *(undefined4 *)(iVar1 + 0x38);
  }
  iVar1 = DAT_007306cc;
  local_60 = local_70;
  local_5c = local_6c;
  local_4c = local_6c;
  local_50 = local_80;
  local_40 = local_80;
  local_3c = local_7c;
  local_2c = local_7c;
  puVar2 = *(undefined4 **)(DAT_007306cc + 0x10);
  local_30 = local_70;
  iVar3 = *(int *)(DAT_007306cc + 0x18) + 1;
  local_58 = local_78;
  local_48 = local_78;
  local_38 = local_78;
  local_28 = local_78;
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = *puVar2;
    if (*(int *)(DAT_007306cc + 0x1c) < iVar3) {
      *(int *)(DAT_007306cc + 0x1c) = iVar3;
    }
    *(undefined4 *)(iVar1 + 0x10) = uVar4;
    *(int *)(iVar1 + 0x18) = iVar3;
  }
  local_14._0_1_ = 1;
  if (puVar2 == (undefined4 *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    uVar4 = (**(code **)(*param_2 + 0x54))();
    piVar5 = (int *)FUN_005775b0(1,uVar4);
  }
  iVar1 = param_1[8];
  param_1[8] = piVar5;
  *(int **)(iVar1 + 4) = piVar5;
  local_14 = (uint)local_14._1_3_ << 8;
  piVar5[1] = (int)(param_1 + 8);
  *piVar5 = iVar1;
  FUN_005772f0(param_1);
  ExceptionList = pvStack_1c;
  return param_1;
}


// ==== 0x5775b0 FUN_005775b0

void FUN_005775b0(char param_1,undefined1 param_2)

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
  int unaff_ESI;
  float *unaff_EDI;
  
  *(undefined1 *)(unaff_ESI + 0xb) = param_2;
  *(undefined1 *)(unaff_ESI + 10) = 0;
  *(undefined1 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  *(float *)(unaff_ESI + 0x80) = *unaff_EDI;
  *(float *)(unaff_ESI + 0x84) = fVar1;
  *(float *)(unaff_ESI + 0x88) = fVar2;
  fVar1 = unaff_EDI[5];
  fVar2 = unaff_EDI[6];
  *(float *)(unaff_ESI + 0x90) = unaff_EDI[4];
  *(float *)(unaff_ESI + 0x94) = fVar1;
  *(float *)(unaff_ESI + 0x98) = fVar2;
  fVar1 = unaff_EDI[9];
  fVar2 = unaff_EDI[10];
  *(float *)(unaff_ESI + 0xa0) = unaff_EDI[8];
  *(float *)(unaff_ESI + 0xa4) = fVar1;
  *(float *)(unaff_ESI + 0xa8) = fVar2;
  *(undefined1 *)(unaff_ESI + 9) = 3;
  if (param_1 == '\0') {
    fVar1 = unaff_EDI[9];
    fVar2 = unaff_EDI[10];
    *(float *)(unaff_ESI + 0xb0) = unaff_EDI[8];
    *(float *)(unaff_ESI + 0xb4) = fVar1;
    *(float *)(unaff_ESI + 0xb8) = fVar2;
  }
  else {
    fVar1 = unaff_EDI[0xd];
    fVar2 = unaff_EDI[0xe];
    *(float *)(unaff_ESI + 0xb0) = unaff_EDI[0xc];
    *(float *)(unaff_ESI + 0xb4) = fVar1;
    *(float *)(unaff_ESI + 0xb8) = fVar2;
    *(undefined1 *)(unaff_ESI + 9) = 4;
  }
  fVar1 = unaff_EDI[4];
  fVar2 = *unaff_EDI;
  fVar3 = unaff_EDI[5];
  fVar4 = unaff_EDI[1];
  fVar5 = unaff_EDI[6];
  fVar6 = unaff_EDI[2];
  fVar7 = unaff_EDI[8];
  fVar8 = *unaff_EDI;
  fVar9 = unaff_EDI[9];
  fVar10 = unaff_EDI[1];
  fVar11 = unaff_EDI[10];
  fVar12 = unaff_EDI[2];
  bNormalize3();
  *(float *)(unaff_ESI + 0xc0) =
       (fVar11 - fVar12) * (fVar3 - fVar4) - (fVar9 - fVar10) * (fVar5 - fVar6);
  *(float *)(unaff_ESI + 0xc4) =
       (fVar5 - fVar6) * (fVar7 - fVar8) - (fVar11 - fVar12) * (fVar1 - fVar2);
  *(float *)(unaff_ESI + 200) =
       (fVar9 - fVar10) * (fVar1 - fVar2) - (fVar7 - fVar8) * (fVar3 - fVar4);
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  fVar3 = *unaff_EDI;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(float *)(unaff_ESI + 0xcc) =
       fVar3 * *(float *)(unaff_ESI + 0xc0) +
       *(float *)(unaff_ESI + 200) * fVar2 + *(float *)(unaff_ESI + 0xc4) * fVar1;
  return;
}


// ==== 0x577730 FUN_00577730

void FUN_00577730(float *param_1,undefined4 param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int unaff_EDI;
  float local_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined1 local_30 [24];
  float fStack_18;
  
  iVar3 = 0;
  if ('\0' < *(char *)(unaff_EDI + 9)) {
    do {
      D3DXVec3Transform(&local_40,(iVar3 + 8) * 0x10 + unaff_EDI,param_2);
      fVar2 = param_1[1];
      fStack_18 = fStack_38 + param_1[2];
      pfVar1 = (float *)((iVar3 + 3) * 0x10 + unaff_EDI);
      *pfVar1 = local_40 + *param_1;
      pfVar1[2] = fStack_18;
      pfVar1[1] = fStack_3c + fVar2;
      if (iVar3 == 0) {
        *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x30);
        *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x34);
        *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x30);
        *(undefined4 *)(unaff_EDI + 0x20) = *(undefined4 *)(unaff_EDI + 0x34);
      }
      else {
        FUN_00567580();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(char *)(unaff_EDI + 9));
  }
  D3DXVec3Transform(local_30,unaff_EDI + 0xc0,param_2);
  *(float *)(unaff_EDI + 0x70) = fStack_3c;
  *(float *)(unaff_EDI + 0x74) = fStack_38;
  *(undefined4 *)(unaff_EDI + 0x78) = uStack_34;
  *(float *)(unaff_EDI + 0x7c) =
       *(float *)(unaff_EDI + 0x70) * *(float *)(unaff_EDI + 0x30) +
       *(float *)(unaff_EDI + 0x74) * *(float *)(unaff_EDI + 0x34) +
       *(float *)(unaff_EDI + 0x78) * *(float *)(unaff_EDI + 0x38);
  return;
}


// ==== 0x577810 FUN_00577810

void __fastcall FUN_00577810(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void **ppvVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068514b;
  piVar1 = *(int **)(param_1 + 0x2c);
  local_4 = 0;
  ppvVar4 = &pvStack_c;
  pvStack_c = ExceptionList;
  while (ExceptionList = ppvVar4, piVar1 != (int *)(param_1 + 0x2c)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    ppvVar4 = ExceptionList;
    piVar1 = *(int **)(param_1 + 0x2c);
  }
  local_4 = 0xffffffff;
  FUN_00577f00();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x577880 FUN_00577880

void FUN_00577880(void)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined8 uVar9;
  
  iVar8 = -1;
  uVar4 = 0x57;
  pcVar6 = "WorldEntity";
  do {
    iVar8 = iVar8 * 0x21 + uVar4;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar4 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  do {
    puVar3 = DAT_0073b138;
    if (iVar8 == DAT_0073b128) {
      puVar5 = &DAT_0073b118;
    }
    else {
      while( true ) {
        if ((undefined4 **)puVar3 == &DAT_0073b138) {
          return;
        }
        uVar9 = FUN_00577d10(iVar8);
        puVar5 = (undefined *)uVar9;
        if (puVar5 != (undefined *)0x0) break;
        puVar3 = (undefined4 *)*(undefined4 *)((ulonglong)uVar9 >> 0x20);
      }
    }
    puVar2 = *(undefined **)(puVar5 + 0x2c);
    if (puVar2 == puVar5 + 0x2c) {
      for (puVar3 = *(undefined4 **)(puVar5 + 0x20); puVar3 != (undefined4 *)(puVar5 + 0x20);
          puVar3 = (undefined4 *)*puVar3) {
        puVar7 = (undefined4 *)FUN_00577eb0();
        if (puVar7 != (undefined4 *)0x0) goto LAB_00577909;
      }
      puVar7 = (undefined4 *)0x0;
    }
    else {
      if (puVar2 == (undefined *)0x0) {
        return;
      }
      puVar7 = (undefined4 *)(puVar2 + -4);
    }
LAB_00577909:
    if (puVar7 == (undefined4 *)0x0) {
      return;
    }
    (**(code **)*puVar7)(1);
  } while( true );
}


// ==== 0x577920 FUN_00577920

int __fastcall FUN_00577920(byte *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  int *piVar4;
  byte *in_EAX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  *param_2 = &PTR_FUN_006ba6b8;
  iVar6 = -1;
  bVar3 = *param_1;
  while (bVar3 != 0) {
    iVar6 = iVar6 * 0x21 + (uint)bVar3;
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    bVar3 = *pbVar1;
  }
  iVar5 = -1;
  bVar3 = *in_EAX;
  while (bVar3 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar3;
    pbVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    bVar3 = *pbVar1;
  }
  param_2[3] = iVar5;
  param_2[4] = iVar6;
  uVar7 = FUN_00577d10(iVar5);
  iVar5 = (int)((ulonglong)uVar7 >> 0x20);
  iVar6 = (int)uVar7;
  *(int *)(iVar5 + 0x18) = iVar6;
  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x1c);
  *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
  iVar6 = *(int *)(iVar5 + 0x18);
  if (*(char *)(iVar6 + 0x18) != '\0') {
    piVar4 = *(int **)(iVar6 + 0x30);
    piVar2 = (int *)(iVar5 + 4);
    *piVar4 = (int)piVar2;
    *(int **)(iVar6 + 0x30) = piVar2;
    *(int **)(iVar5 + 8) = piVar4;
    *piVar2 = iVar6 + 0x2c;
  }
  return iVar5;
}


// ==== 0x5779a0 FUN_005779a0

void * __thiscall FUN_005779a0(void *param_1,byte param_2)

{
  FUN_005779c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5779c0 FUN_005779c0

void __fastcall FUN_005779c0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006ba6b8;
  if (*(char *)(param_1[6] + 0x18) != '\0') {
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  return;
}


// ==== 0x5779e0 FUN_005779e0

void __thiscall FUN_005779e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00577a00(param_1,param_2,param_3,0xffffffff);
  return;
}


// ==== 0x577a00 FUN_00577a00

char * FUN_00577a00(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char local_20 [32];
  
  if (param_2 == (char *)0x0) {
    param_2 = &DAT_007306d0 + DAT_0078ea88 * 0x100;
    DAT_0078ea88 = (DAT_0078ea88 + 1) % 3;
    param_3 = 0x100;
  }
  pcVar2 = *(char **)(*(int *)(param_1 + 0x18) + 0xc);
  iVar4 = 0;
  if (pcVar2 != (char *)0x0) {
    cVar1 = *pcVar2;
    while (cVar1 != '\0') {
      iVar6 = iVar4 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = pcVar2[iVar6];
    }
  }
  if (param_3 <= iVar4) {
    iVar4 = param_3 + -1;
  }
  if (iVar4 != 0) {
    pcVar5 = param_2;
    iVar6 = iVar4;
    do {
      cVar1 = pcVar5[(int)pcVar2 - (int)param_2];
      iVar6 = iVar6 + -1;
      *pcVar5 = cVar1;
      if (cVar1 == '\0') break;
      pcVar5 = pcVar5 + 1;
    } while (iVar6 != 0);
  }
  pcVar2 = param_2 + iVar4;
  if (param_4 == -1) {
    param_4 = *(int *)(param_1 + 0x14);
  }
  FUN_00565da0(&PTR_LAB_0064251e_2_006ba6c8,param_4);
  iVar6 = 0;
  while (local_20[0] != '\0') {
    iVar3 = iVar6 + 1;
    iVar6 = iVar6 + 1;
    local_20[0] = local_20[iVar3];
  }
  if (param_3 - iVar4 <= iVar6) {
    iVar6 = (param_3 - iVar4) + -1;
  }
  if (iVar6 != 0) {
    pcVar5 = pcVar2;
    iVar4 = iVar6;
    do {
      cVar1 = pcVar5[(int)(local_20 + -(int)pcVar2)];
      iVar4 = iVar4 + -1;
      *pcVar5 = cVar1;
      if (cVar1 == '\0') break;
      pcVar5 = pcVar5 + 1;
    } while (iVar4 != 0);
  }
  pcVar2[iVar6] = '\0';
  return param_2;
}


// ==== 0x577b00 FUN_00577b00

int * __thiscall
FUN_00577b00(byte *param_1,int *param_2,byte *param_3,int param_4,undefined1 param_5)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  undefined8 uVar11;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685136;
  local_c = ExceptionList;
  piVar1 = param_2 + 8;
  ExceptionList = &local_c;
  *piVar1 = (int)piVar1;
  param_2[9] = (int)piVar1;
  piVar1 = param_2 + 0xb;
  *piVar1 = (int)piVar1;
  param_2[0xc] = (int)piVar1;
  param_2[3] = (int)param_1;
  bVar3 = *param_1;
  iVar6 = -1;
  local_4 = 1;
  while (bVar3 != 0) {
    iVar6 = iVar6 * 0x21 + (uint)bVar3;
    pbVar2 = param_1 + 1;
    param_1 = param_1 + 1;
    bVar3 = *pbVar2;
  }
  param_2[2] = param_4;
  *(undefined1 *)(param_2 + 6) = param_5;
  param_2[4] = iVar6;
  param_2[10] = 0;
  param_2[7] = 0;
  iVar5 = DAT_007309d0;
  pcVar9 = "WorldEntity";
  iVar8 = -1;
  uVar7 = 0x57;
  do {
    iVar8 = iVar8 * 0x21 + uVar7;
    pbVar2 = (byte *)(pcVar9 + 1);
    uVar7 = (uint)*pbVar2;
    pcVar9 = pcVar9 + 1;
  } while (*pbVar2 != 0);
  if (iVar6 == iVar8) {
    param_2[5] = 0;
  }
  else {
    iVar6 = -1;
    bVar3 = *param_3;
    while (bVar3 != 0) {
      iVar6 = iVar6 * 0x21 + (uint)bVar3;
      pbVar2 = param_3 + 1;
      param_3 = param_3 + 1;
      bVar3 = *pbVar2;
    }
    bVar10 = DAT_007309d0 == 0x55ff33ac;
    param_2[5] = iVar6;
    if (bVar10) {
      uVar11 = FUN_00577d10(iVar6);
      param_2 = (int *)((ulonglong)uVar11 >> 0x20);
      iVar6 = (int)uVar11;
      if (iVar6 != 0) {
        param_2[10] = iVar6;
        puVar4 = *(undefined4 **)(iVar6 + 0x24);
        *puVar4 = param_2;
        *(int **)(iVar6 + 0x24) = param_2;
        param_2[1] = (int)puVar4;
        *param_2 = iVar6 + 0x20;
      }
    }
    else {
      if (iVar5 != 0x55ff33ab) {
        DAT_007309d0 = 0x55ff33ab;
        DAT_007309d4 = 0;
      }
      (&DAT_007309d8)[DAT_007309d4] = param_2;
      DAT_007309d4 = DAT_007309d4 + 1;
    }
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x577c30 FUN_00577c30

void FUN_00577c30(void)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_c;
  int local_8;
  int local_4;
  
  DAT_007309d0 = 0x55ff33ac;
  local_4 = 0;
  local_c = DAT_007309d4;
  iVar3 = DAT_007309d4;
  do {
    if (iVar3 == 0) {
      return;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      local_8 = iVar3 + -1;
      piVar6 = &DAT_007309d8;
      do {
        iVar1 = *(int *)(*piVar6 + 0x14);
        if (iVar1 == DAT_0073b128) {
          uVar9 = CONCAT44(*piVar6,&DAT_0073b118);
LAB_00577c85:
          piVar4 = (int *)((ulonglong)uVar9 >> 0x20);
          iVar3 = (int)uVar9;
          piVar4[10] = iVar3;
          puVar7 = *(undefined4 **)(iVar3 + 0x24);
          *puVar7 = piVar4;
          *(int **)(iVar3 + 0x24) = piVar4;
          *piVar4 = iVar3 + 0x20;
          piVar4[1] = (int)puVar7;
          if (iVar5 < local_8) {
            piVar8 = piVar6;
            piVar4 = piVar6;
            for (iVar3 = local_8 - iVar5; piVar4 = piVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
              *piVar8 = *piVar4;
              piVar8 = piVar8 + 1;
            }
          }
          local_c = local_c + -1;
          local_8 = local_8 + -1;
          iVar3 = local_c;
        }
        else {
          puVar7 = DAT_0073b138;
          if ((undefined4 **)DAT_0073b138 != &DAT_0073b138) {
            do {
              uVar9 = FUN_00577d10(iVar1);
              if ((int)uVar9 != 0) goto LAB_00577c85;
              puVar7 = (undefined4 *)*puVar7;
              iVar3 = local_c;
            } while ((undefined4 **)puVar7 != &DAT_0073b138);
          }
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 < iVar3);
    }
    bVar2 = DAT_007309d4 < local_4;
    local_4 = local_4 + 1;
    if (bVar2) {
      return;
    }
  } while( true );
}


// ==== 0x577d10 FUN_00577d10

int __thiscall FUN_00577d10(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 != *(int *)(param_1 + 0x10)) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x20); puVar1 != (undefined4 *)(param_1 + 0x20);
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = FUN_00577d10(param_2);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    param_1 = 0;
  }
  return param_1;
}


// ==== 0x577d50 FUN_00577d50

int __fastcall FUN_00577d50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(param_2 + 0x2c);
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + -4;
    }
    if (param_2 == -0x2c) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 + 0x28;
    }
    if (iVar1 == iVar2) break;
    if (*(int *)(iVar1 + 0x10) == unaff_ESI) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 0;
}


// ==== 0x577d80 FUN_00577d80

void __fastcall FUN_00577d80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + -4;
    }
    if (param_1 == -0x2c) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_1 + 0x28;
    }
    if (iVar2 == iVar3) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  for (puVar1 = *(undefined4 **)(param_1 + 0x20); puVar1 != (undefined4 *)(param_1 + 0x20);
      puVar1 = (undefined4 *)*puVar1) {
    FUN_00577d80();
  }
  return;
}


// ==== 0x577dd0 FUN_00577dd0

int FUN_00577dd0(void)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_00577d10(in_EAX);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  iVar2 = (int)uVar4;
  if (iVar2 != 0) {
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 4) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar3 + 4) + -4;
      }
      if (*(int *)(iVar3 + 0x18) == -0x2c) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x18) + 0x28;
      }
      if (iVar1 == iVar3) {
        uVar4 = FUN_00577e60(0);
        iVar1 = (int)uVar4;
        if (iVar1 == 0) {
          if ((int)((ulonglong)uVar4 >> 0x20) != iVar2) {
            iVar2 = FUN_00577ed0();
            return iVar2;
          }
          iVar1 = 0;
        }
      }
      return iVar1;
    }
    iVar3 = *(int *)(iVar2 + 0x2c);
    if (iVar3 == iVar2 + 0x2c) {
      iVar2 = FUN_00577e60(0);
      return iVar2;
    }
    if (iVar3 != 0) {
      return iVar3 + -4;
    }
  }
  return 0;
}


// ==== 0x577e60 FUN_00577e60

undefined4 * __thiscall FUN_00577e60(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    param_2 = *(undefined4 **)(param_1 + 0x20);
  }
  else {
    param_2 = (undefined4 *)*param_2;
  }
  do {
    if (param_2 == (undefined4 *)(param_1 + 0x20)) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)param_2[0xb];
    if (puVar1 == param_2 + 0xb) {
      puVar1 = (undefined4 *)FUN_00577e60(0);
LAB_00577e96:
      if (puVar1 != (undefined4 *)0x0) {
        return puVar1;
      }
    }
    else if (puVar1 != (undefined4 *)0x0) {
      puVar1 = puVar1 + -1;
      goto LAB_00577e96;
    }
    param_2 = (undefined4 *)*param_2;
  } while( true );
}


// ==== 0x577eb0 FUN_00577eb0

int __fastcall FUN_00577eb0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 == param_1 + 0x2c) {
    iVar1 = FUN_00577e60(0);
    return iVar1;
  }
  if (iVar1 != 0) {
    return iVar1 + -4;
  }
  return 0;
}


// ==== 0x577ed0 FUN_00577ed0

int FUN_00577ed0(void)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined8 uVar3;
  
  uVar3 = FUN_00577e60(in_EAX);
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  iVar1 = (int)uVar3;
  if (iVar1 == 0) {
    while (iVar2 != unaff_ESI) {
      uVar3 = FUN_00577e60(iVar2);
      iVar2 = (int)((ulonglong)uVar3 >> 0x20);
      if ((int)uVar3 != 0) {
        return (int)uVar3;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x577f00 FUN_00577f00

void FUN_00577f00(void)

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
    FUN_00577810();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x577f30 FUN_00577f30

void FUN_00577f30(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  while (piVar1 != unaff_ESI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x577f60 FUN_00577f60

undefined4 FUN_00577f60(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686c73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x90);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00578060(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x577fd0 FUN_00577fd0

undefined1 FUN_00577fd0(void)

{
  return 1;
}


// ==== 0x577fe0 FUN_00577fe0

undefined4 __fastcall FUN_00577fe0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}


// ==== 0x577ff0 FUN_00577ff0

void __fastcall FUN_00577ff0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0072cbf8;
  iVar1 = *(int *)(DAT_0072cbf8 + 0x18);
  *param_1 = *(undefined4 *)(DAT_0072cbf8 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x578010 FUN_00578010

undefined4 __fastcall FUN_00578010(int param_1)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    pcVar4 = "WorldObject";
    param_1 = -1;
    uVar2 = 0x57;
    do {
      param_1 = param_1 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar4 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar4 = pcVar4 + 1;
    } while (*pbVar1 != 0);
  }
  if (in_EAX == 0) {
    return 0;
  }
  if (param_1 != 0) {
    FUN_00577d10(param_1);
    uVar3 = FUN_00577d50();
    return uVar3;
  }
  uVar3 = FUN_00577d50();
  return uVar3;
}


// ==== 0x578060 FUN_00578060

undefined4 * FUN_00578060(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00686c4d;
  local_1c = ExceptionList;
  uVar5 = *param_2;
  ExceptionList = &local_1c;
  param_1[4] = param_2[1];
  *param_1 = &PTR_FUN_006ba6b8;
  param_1[3] = uVar5;
  iVar4 = FUN_00577d10(uVar5);
  param_1[6] = iVar4;
  param_1[5] = *(undefined4 *)(iVar4 + 0x1c);
  *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
  iVar4 = param_1[6];
  if (*(char *)(iVar4 + 0x18) != '\0') {
    piVar2 = *(int **)(iVar4 + 0x30);
    piVar1 = param_1 + 1;
    *piVar2 = (int)piVar1;
    *(int **)(iVar4 + 0x30) = piVar1;
    param_1[2] = piVar2;
    *piVar1 = iVar4 + 0x2c;
  }
  local_14 = 0;
  uVar5 = FUN_00579380(0);
  param_1[7] = uVar5;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *param_1 = &PTR_FUN_006ba65c;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x14] = 0x3f800000;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0x3f800000;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0x3f800000;
  param_1[0xb] = param_2;
  param_1[0x10] = 0;
  local_14 = CONCAT31(local_14._1_3_,1);
  FUN_00578500(param_2 + 0x14,param_2[0x24] != 0);
  iVar4 = param_1[7];
  bMatrixCopy_b();
  if (*(int *)(iVar4 + 0xe4) == 0) {
    FUN_00579190();
  }
  FUN_00578590();
  iVar4 = DAT_007306c8;
  if ((param_2[0x1a] != 0) && (param_2[2] != 0)) {
    puVar3 = *(undefined4 **)(DAT_007306c8 + 0x10);
    iVar6 = *(int *)(DAT_007306c8 + 0x18) + 1;
    if (puVar3 != (undefined4 *)0x0) {
      uVar5 = *puVar3;
      if (*(int *)(DAT_007306c8 + 0x1c) < iVar6) {
        *(int *)(DAT_007306c8 + 0x1c) = iVar6;
      }
      *(int *)(iVar4 + 0x18) = iVar6;
      *(undefined4 *)(iVar4 + 0x10) = uVar5;
    }
    local_14._0_1_ = 2;
    if (puVar3 == (undefined4 *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00577450(puVar3,param_1[0xd]);
    }
    local_14 = CONCAT31(local_14._1_3_,1);
    param_1[0xe] = uVar5;
  }
  if ((((param_2[0x20] != 0) || (param_2[0x21] != 0)) || (param_2[0x22] != 0)) ||
     ((param_2[0x24] != 0 && (param_2[0x23] != 0)))) {
    FUN_005796b0(param_1 + 7,4,param_2 + 0x20);
  }
  param_1[0xf] = 0;
  if (param_2[0x1b] != 0) {
    uVar5 = FUN_00532d40(param_2[0x1b],param_1);
    param_1[0xf] = uVar5;
  }
  param_1[0x12] = 0;
  if (param_2[0x1d] != 0) {
    FUN_00578660(1);
  }
  *(undefined1 *)(param_1 + 0x11) = 0;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x578290 FUN_00578290

void * __thiscall FUN_00578290(void *param_1,byte param_2)

{
  FUN_00578370();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5782b0 FUN_005782b0

undefined4 * FUN_005782b0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686c18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00577920();
  local_4 = 0;
  uVar1 = FUN_00579380(0);
  param_1[7] = uVar1;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *param_1 = &PTR_FUN_006ba65c;
  param_1[0x14] = 0x3f800000;
  param_1[0x19] = 0x3f800000;
  param_1[0x1e] = 0x3f800000;
  param_1[0x23] = 0x3f800000;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x578370 FUN_00578370

void __fastcall FUN_00578370(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  void *pvStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00685f71;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006ba65c;
  puVar1 = (undefined4 *)param_1[0xc];
  local_4 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00591c90(puVar1);
    iVar4 = DAT_007344c8;
    iVar5 = *(int *)(DAT_007344c8 + 0x18);
    *puVar1 = *(undefined4 *)(DAT_007344c8 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar5 + -1;
    *(undefined4 **)(iVar4 + 0x10) = puVar1;
    param_1[0xc] = 0;
  }
  if (param_1[0xd] != 0) {
    if ((undefined4 *)param_1[0xe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xe])(1);
      param_1[0xe] = 0;
    }
    if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xd])(1);
    }
    param_1[0xd] = 0;
  }
  puVar1 = (undefined4 *)param_1[0xf];
  if (puVar1 != (undefined4 *)0x0) {
    iVar5 = puVar1[0x84];
    piVar2 = (int *)puVar1[0x85];
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    (**(code **)*puVar1)(1);
    param_1[0xf] = 0;
  }
  piVar2 = (int *)param_1[0x12];
  if (piVar2 != (int *)0x0) {
    piVar3 = (int *)piVar2[1];
    iVar5 = *piVar2;
    *piVar3 = iVar5;
    *(int **)(iVar5 + 4) = piVar3;
    iVar5 = FUN_00647b70();
    if ((iVar5 == 4) && ((void *)piVar2[0x74] != (void *)0x0)) {
      _free((void *)piVar2[0x74]);
    }
    _free(piVar2);
    param_1[0x12] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00579600(param_1 + 7);
  *param_1 = &PTR_FUN_006ba6b8;
  if (*(char *)(param_1[6] + 0x18) != '\0') {
    iVar5 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x578490 FUN_00578490

void FUN_00578490(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x40) != 0) {
    piVar1 = *(int **)(unaff_EDI + 0x1c);
    puVar2 = (undefined4 *)piVar1[0x38];
    if (puVar2 != (undefined4 *)0x0) {
      iVar3 = *piVar1;
      piVar4 = (int *)piVar1[1];
      *piVar4 = iVar3;
      *(int **)(iVar3 + 4) = piVar4;
      piVar1[0x38] = 0;
      piVar1 = puVar2 + 0x36;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_00579090();
        *DAT_0073b0e0 = puVar2;
        puVar5 = puVar2;
        puVar2[1] = DAT_0073b0e0;
        DAT_0073b0e0 = puVar5;
        *puVar2 = &DAT_0073b0dc;
      }
    }
  }
  *(int *)(unaff_EDI + 0x40) = param_1;
  if (param_1 != 0) {
    FUN_00579010(*(undefined4 *)(param_1 + 0x1c));
  }
  return;
}


// ==== 0x578500 FUN_00578500

void FUN_00578500(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar3 = DAT_007344c8;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686598;
  local_c = ExceptionList;
  puVar1 = *(undefined4 **)(unaff_EDI + 0x30);
  ExceptionList = &local_c;
  if (puVar1 != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    FUN_00591c90(puVar1);
    iVar2 = *(int *)(iVar3 + 0x18);
    *puVar1 = *(undefined4 *)(iVar3 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar1;
  }
  iVar3 = FUN_00567160();
  local_4 = 0;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00591bf0(*(undefined4 *)(unaff_EDI + 0x1c),param_1,param_2 != 0);
  }
  *(undefined4 *)(unaff_EDI + 0x30) = uVar4;
  ExceptionList = local_c;
  return;
}


// ==== 0x578590 FUN_00578590

void __fastcall FUN_00578590(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00686740;
  local_c = ExceptionList;
  if (unaff_EDI == 0) {
    return;
  }
  ExceptionList = &local_c;
  if (*(undefined4 **)(param_1 + 0x34) != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    (**(code **)**(undefined4 **)(param_1 + 0x34))(1);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  puVar5 = &DAT_006ba6b4;
  iVar4 = -1;
  uVar2 = 0x42;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = puVar5 + 1;
    uVar2 = (uint)*pbVar1;
    puVar5 = puVar5 + 1;
  } while (*pbVar1 != 0);
  if (unaff_EDI == iVar4) {
    if (*(int *)(param_1 + 0x30) == 0) goto LAB_0057863b;
    iVar4 = FUN_00567160();
    uStack_4 = 0;
    if (iVar4 == 0) goto LAB_00578636;
    uVar3 = FUN_00592470(iVar4,param_1,*(undefined4 *)(param_1 + 0x30));
  }
  else {
    iVar4 = FUN_00567160();
    uStack_4 = 1;
    if (iVar4 == 0) {
LAB_00578636:
      uVar3 = 0;
    }
    else {
      uVar3 = WorldObject_ctor(iVar4,param_1,unaff_EDI);
    }
  }
  *(undefined4 *)(param_1 + 0x34) = uVar3;
LAB_0057863b:
  *(undefined4 *)(param_1 + 0x28) = 1;
  if (*(int *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0xc) = 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x578660 FUN_00578660

void FUN_00578660(int param_1)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685f33;
  local_c = ExceptionList;
  _Memory = *(int **)(unaff_EDI + 0x48);
  ExceptionList = &local_c;
  if (_Memory != (int *)0x0) {
    piVar1 = (int *)_Memory[1];
    iVar2 = *_Memory;
    ExceptionList = &local_c;
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    iVar2 = FUN_00647b70();
    if ((iVar2 == 4) && ((void *)_Memory[0x74] != (void *)0x0)) {
      _free((void *)_Memory[0x74]);
    }
    _free(_Memory);
    *(undefined4 *)(unaff_EDI + 0x48) = 0;
  }
  if (param_1 != 0) {
    pvVar3 = _malloc(0x1e0);
    local_4 = 0;
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_0057a420(unaff_EDI);
    }
    *(undefined4 *)(unaff_EDI + 0x48) = uVar4;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x578710 FUN_00578710

int FUN_00578710(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return iVar1 + 0x40;
}


// ==== 0x578730 FUN_00578730

undefined4 * FUN_00578730(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x1c);
  if (*(int *)(iVar2 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x1c);
  uVar1 = *(undefined4 *)(iVar2 + 0x18);
  uVar4 = *(undefined4 *)(iVar2 + 0x10);
  *(undefined4 *)(unaff_ESI + 0x54) = *(undefined4 *)(iVar2 + 0x14);
  *(undefined4 *)(unaff_ESI + 0x50) = uVar4;
  *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x5c) = uVar3;
  iVar2 = *(int *)(unaff_ESI + 0x1c);
  if (*(int *)(iVar2 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x2c);
  uVar1 = *(undefined4 *)(iVar2 + 0x28);
  uVar4 = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(unaff_ESI + 0x60) = uVar4;
  *(undefined4 *)(unaff_ESI + 0x6c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x68) = uVar1;
  iVar2 = *(int *)(unaff_ESI + 0x1c);
  if (*(int *)(iVar2 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x3c);
  uVar1 = *(undefined4 *)(iVar2 + 0x38);
  uVar4 = *(undefined4 *)(iVar2 + 0x30);
  *(undefined4 *)(unaff_ESI + 0x74) = *(undefined4 *)(iVar2 + 0x34);
  *(undefined4 *)(unaff_ESI + 0x78) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x70) = uVar4;
  *(undefined4 *)(unaff_ESI + 0x7c) = uVar3;
  return (undefined4 *)(unaff_ESI + 0x50);
}


// ==== 0x5787e0 WorldObjectCohort::Loader

/* [canon] assets high (Ghidra make FUN_005787e0 (Hopper export lacks it)) docs/re/assets.md */

undefined4 WorldObjectCohort__Loader(int *param_1)

{
  if (*param_1 == 0x3b300) {
    DAT_007345c4 = param_1;
    return 1;
  }
  return 0;
}


// ==== 0x578800 WorldObjectCohort::Unloader

/* [canon] assets high (Ghidra make FUN_00578800) docs/re/assets.md */

undefined4 WorldObjectCohort__Unloader(int *param_1)

{
  if (*param_1 == 0x3b300) {
    DAT_007345c4 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x578820 FUN_00578820

undefined4 FUN_00578820(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int *unaff_ESI;
  
  pcVar5 = "DrawBridge";
  iVar4 = -1;
  uVar2 = 0x44;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  if (*unaff_ESI == iVar4) {
    return 1;
  }
  pcVar5 = "TRSABC_Track_Jump";
  iVar4 = -1;
  uVar2 = 0x54;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  if ((unaff_ESI[1] != iVar4) || (uVar3 = 1, DAT_0078a2fc != 1)) {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x578880 WorldObjectCohort::Launch

/* [canon] assets high (Ghidra make FUN_00578880) docs/re/assets.md */

void WorldObjectCohort__Launch(int param_1,int param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  undefined *puVar11;
  uint uVar12;
  undefined8 uVar13;
  
  uVar12 = ((*(int *)(DAT_007345c4 + 4) - (DAT_007345c4 + 0x17U & 0xfffffff0)) + 8 + DAT_007345c4) /
           0xa0;
  if (uVar12 != 0) {
    puVar4 = (undefined4 *)FUN_00401d60();
    do {
      if ((puVar4[3] == param_1) && (iVar5 = FUN_00578820(), iVar5 == 0)) {
        iVar5 = FUN_00577d10(*puVar4);
        iVar5 = (**(code **)(iVar5 + 8))(puVar4,0);
        if ((iVar5 != 0) && (param_2 != 0)) {
          FUN_00578490(param_2);
        }
      }
      puVar4 = puVar4 + 0x28;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  pcVar9 = "WorldObject";
  iVar5 = -1;
  uVar12 = 0x57;
  do {
    pbVar1 = (byte *)(pcVar9 + 1);
    iVar5 = iVar5 * 0x21 + uVar12;
    pcVar9 = pcVar9 + 1;
    uVar12 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  if (param_2 == 0) {
    if (iVar5 == DAT_0073b128) {
      puVar6 = &DAT_0073b118;
LAB_00578935:
      puVar8 = *(undefined **)(puVar6 + 0x2c);
      if (puVar8 == puVar6 + 0x2c) {
        puVar8 = (undefined *)FUN_00577e60(0);
      }
      else if (puVar8 == (undefined *)0x0) {
        puVar8 = (undefined *)0x0;
      }
      else {
        puVar8 = puVar8 + -4;
      }
joined_r0x0057898c:
      do {
        if (puVar8 == (undefined *)0x0) goto LAB_00578ab7;
        if (((*(int *)(puVar8 + 0x2c) != 0) && (*(int *)(*(int *)(puVar8 + 0x2c) + 0x70) != 0)) &&
           (puVar8[0x44] == '\0')) {
          pcVar9 = "WorldObject";
          iVar10 = -1;
          uVar12 = 0x57;
          do {
            iVar10 = iVar10 * 0x21 + uVar12;
            pbVar1 = (byte *)(pcVar9 + 1);
            uVar12 = (uint)*pbVar1;
            pcVar9 = pcVar9 + 1;
          } while (*pbVar1 != 0);
          if (iVar10 != 0) {
            FUN_00577d10(iVar10);
          }
          uVar7 = FUN_00577d50();
          FUN_00578490(uVar7);
          puVar8[0x44] = 1;
        }
        if (iVar5 == DAT_0073b128) {
          puVar6 = &DAT_0073b118;
        }
        else {
          if ((undefined4 **)DAT_0073b138 == &DAT_0073b138) goto LAB_00578ab7;
          while( true ) {
            uVar13 = FUN_00577d10(iVar5);
            puVar6 = (undefined *)uVar13;
            if (puVar6 != (undefined *)0x0) break;
            if ((undefined4 **)*(undefined4 *)((ulonglong)uVar13 >> 0x20) == &DAT_0073b138)
            goto LAB_00578ab7;
          }
        }
        puVar2 = *(undefined **)(puVar8 + 0x18);
        if (*(int *)(puVar8 + 4) == 0) {
          puVar8 = (undefined *)0x0;
        }
        else {
          puVar8 = (undefined *)(*(int *)(puVar8 + 4) + -4);
        }
        if (puVar2 == (undefined *)0xffffffd4) {
          puVar11 = (undefined *)0x0;
        }
        else {
          puVar11 = puVar2 + 0x28;
        }
        if (puVar8 == puVar11) {
          for (puVar4 = *(undefined4 **)(puVar2 + 0x20); puVar4 != (undefined4 *)(puVar2 + 0x20);
              puVar4 = (undefined4 *)*puVar4) {
            puVar3 = (undefined4 *)puVar4[0xb];
            if (puVar3 == puVar4 + 0xb) {
              uVar13 = FUN_00577e60(0);
LAB_00578a7e:
              puVar4 = (undefined4 *)((ulonglong)uVar13 >> 0x20);
              puVar8 = (undefined *)uVar13;
              if (puVar8 != (undefined *)0x0) goto joined_r0x0057898c;
            }
            else if (puVar3 != (undefined4 *)0x0) {
              uVar13 = CONCAT44(puVar4,puVar3 + -1);
              goto LAB_00578a7e;
            }
          }
          if (puVar2 != puVar6) {
            uVar13 = FUN_00577e60(puVar2);
            puVar8 = (undefined *)uVar13;
            if (puVar8 != (undefined *)0x0) goto joined_r0x0057898c;
            if ((undefined *)((ulonglong)uVar13 >> 0x20) != puVar6) {
              puVar8 = (undefined *)FUN_00577ed0();
              goto joined_r0x0057898c;
            }
          }
          puVar8 = (undefined *)0x0;
        }
      } while( true );
    }
    if ((undefined4 **)DAT_0073b138 != &DAT_0073b138) {
      do {
        uVar13 = FUN_00577d10(iVar5);
        puVar6 = (undefined *)uVar13;
        if (puVar6 != (undefined *)0x0) goto LAB_00578935;
      } while ((undefined4 **)*(undefined4 *)((ulonglong)uVar13 >> 0x20) != &DAT_0073b138);
    }
  }
LAB_00578ab7:
  iVar5 = DAT_0073b144;
  if (DAT_007345c0 != 0) {
    while( true ) {
      if (iVar5 == 0) {
        puVar6 = (undefined *)0x0;
      }
      else {
        puVar6 = (undefined *)(iVar5 + -4);
      }
      if (puVar6 == &DAT_0073b140) break;
      iVar5 = *(int *)(puVar6 + 4);
    }
    puVar4 = DAT_0073b138;
    if ((undefined4 **)DAT_0073b138 != &DAT_0073b138) {
      do {
        FUN_00577d80();
        puVar4 = (undefined4 *)*puVar4;
      } while ((undefined4 **)puVar4 != &DAT_0073b138);
    }
  }
  return;
}


// ==== 0x578b10 FUN_00578b10

void FUN_00578b10(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined *puVar11;
  undefined8 uVar12;
  
  pcVar8 = "WorldObject";
  iVar10 = -1;
  uVar5 = 0x57;
  do {
    iVar10 = iVar10 * 0x21 + uVar5;
    pbVar1 = (byte *)(pcVar8 + 1);
    uVar5 = (uint)*pbVar1;
    pcVar8 = pcVar8 + 1;
  } while (*pbVar1 != 0);
  iVar6 = FUN_00577d10(iVar10);
  if (iVar6 != 0) {
    iVar2 = *(int *)(iVar6 + 0x2c);
    if (iVar2 == iVar6 + 0x2c) {
      puVar7 = (undefined4 *)FUN_00577e60(0);
    }
    else if (iVar2 == 0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)(iVar2 + -4);
    }
    while (puVar4 = puVar7, puVar4 != (undefined4 *)0x0) {
      puVar7 = DAT_0073b138;
      if (iVar10 == DAT_0073b128) {
        puVar11 = &DAT_0073b118;
LAB_00578b7e:
        if (puVar4 == (undefined4 *)0x0) {
          puVar3 = *(undefined **)(puVar11 + 0x2c);
          if (puVar3 == puVar11 + 0x2c) {
            puVar7 = (undefined4 *)FUN_00577e60(0);
          }
          else if (puVar3 == (undefined *)0x0) {
LAB_00578bef:
            puVar7 = (undefined4 *)0x0;
          }
          else {
            puVar7 = (undefined4 *)(puVar3 + -4);
          }
        }
        else {
          if (puVar4[1] == 0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            puVar7 = (undefined4 *)(puVar4[1] + -4);
          }
          if (puVar4[6] == -0x2c) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            puVar9 = (undefined4 *)(puVar4[6] + 0x28);
          }
          if (puVar7 == puVar9) {
            uVar12 = FUN_00577e60(0);
            puVar7 = (undefined4 *)uVar12;
            if (puVar7 == (undefined4 *)0x0) {
              if ((undefined *)((ulonglong)uVar12 >> 0x20) == puVar11) goto LAB_00578bef;
              puVar7 = (undefined4 *)FUN_00577ed0();
            }
          }
        }
      }
      else {
        while ((undefined4 **)puVar7 != &DAT_0073b138) {
          uVar12 = FUN_00577d10(iVar10);
          puVar11 = (undefined *)uVar12;
          if (puVar11 != (undefined *)0x0) goto LAB_00578b7e;
          puVar7 = (undefined4 *)*(undefined4 *)((ulonglong)uVar12 >> 0x20);
        }
        puVar7 = (undefined4 *)0x0;
      }
      if ((puVar4[0xb] != 0) && (*(int *)(puVar4[0xb] + 0xc) == param_1)) {
        (**(code **)*puVar4)(1);
      }
    }
  }
  if (DAT_007345c0 != 0) {
    FUN_00577d80();
    return;
  }
  return;
}


// ==== 0x578c50 FUN_00578c50

void * __thiscall FUN_00578c50(void *param_1,byte param_2)

{
  FUN_00578c70();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x578c70 FUN_00578c70

void __fastcall FUN_00578c70(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)param_1[4];
  *param_1 = &PTR_FUN_006ba644;
  piVar3 = piVar1 + 0x36;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    if (piVar1[0x38] != 0) {
      iVar2 = *piVar1;
      piVar3 = (int *)piVar1[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      piVar1[0x38] = 0;
      FUN_00579140();
    }
    *DAT_0073b0e0 = (int)piVar1;
    piVar3 = piVar1;
    piVar1[1] = (int)DAT_0073b0e0;
    DAT_0073b0e0 = piVar3;
    *piVar1 = (int)&DAT_0073b0dc;
  }
  return;
}


// ==== 0x578cc0 FUN_00578cc0

undefined4 * FUN_00578cc0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686423;
  local_c = ExceptionList;
  switch(param_1) {
  case 1:
    ExceptionList = &local_c;
    puVar2 = _malloc(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_006ba644;
      puVar2[4] = unaff_ESI;
      *(int *)(unaff_ESI + 0xd8) = *(int *)(unaff_ESI + 0xd8) + 1;
      puVar2[3] = 0;
      *puVar2 = &PTR_FUN_006ba63c;
      ExceptionList = local_c;
      return puVar2;
    }
    break;
  case 4:
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x80);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_00579750(pvVar1,unaff_ESI,param_2,unaff_EDI);
      ExceptionList = local_c;
      return puVar2;
    }
    break;
  case 6:
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x18);
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_0057a350(param_2,unaff_EDI);
      ExceptionList = local_c;
      return puVar2;
    }
    break;
  case 7:
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x40);
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_0057c2a0(param_2,unaff_EDI);
      ExceptionList = local_c;
      return puVar2;
    }
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x578de0 FUN_00578de0

void * __thiscall FUN_00578de0(void *param_1,byte param_2)

{
  FUN_00578e00();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x578e00 FUN_00578e00

void __fastcall FUN_00578e00(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba63c;
  FUN_00578c70();
  return;
}


// ==== 0x578e10 FUN_00578e10

void __fastcall FUN_00578e10(int param_1)

{
  int iVar1;
  
  bMatrixCopy_b();
  iVar1 = *(int *)(param_1 + 0x10);
  bMatrixCopy_b();
  if (*(int *)(iVar1 + 0xe4) == 0) {
    FUN_00579190();
  }
  return;
}


// ==== 0x578e60 FUN_00578e60

void __fastcall FUN_00578e60(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_007345bc;
  iVar1 = *(int *)(DAT_007345bc + 0x18);
  *param_1 = *(undefined4 *)(DAT_007345bc + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x578e80 FUN_00578e80

int FUN_00578e80(int param_1,undefined4 param_2)

{
  int iVar1;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  pcStack_18 = FUN_0068562e;
  local_1c = ExceptionList;
  iVar1 = param_1 + 8;
  ExceptionList = &local_1c;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0xc) = iVar1;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 1;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0x3f800000;
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x78) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x8c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  local_14 = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  FUN_00579010(param_2);
  *(undefined4 *)(param_1 + 0xe8) = 0;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x578f80 FUN_00578f80

void FUN_00578f80(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684cab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_005790e0();
  puVar1 = (undefined4 *)param_1[0x38];
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = *param_1;
    piVar3 = (int *)param_1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    param_1[0x38] = 0;
    piVar3 = puVar1 + 0x36;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      FUN_00579090();
      *DAT_0073b0e0 = puVar1;
      puVar4 = puVar1;
      puVar1[1] = DAT_0073b0e0;
      DAT_0073b0e0 = puVar4;
      *puVar1 = &DAT_0073b0dc;
    }
  }
  local_4 = 0xffffffff;
  FUN_00579480();
  ExceptionList = local_c;
  return;
}


// ==== 0x579010 FUN_00579010

void FUN_00579010(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *unaff_ESI;
  
  puVar1 = (undefined4 *)unaff_ESI[0x38];
  if (param_1 != puVar1) {
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = *unaff_ESI;
      piVar3 = (int *)unaff_ESI[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      unaff_ESI[0x38] = 0;
      piVar3 = puVar1 + 0x36;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_00579090();
        *DAT_0073b0e0 = puVar1;
        puVar4 = puVar1;
        puVar1[1] = DAT_0073b0e0;
        DAT_0073b0e0 = puVar4;
        *puVar1 = &DAT_0073b0dc;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)param_1[3];
      *puVar1 = unaff_ESI;
      param_1[3] = unaff_ESI;
      *unaff_ESI = (int)(param_1 + 2);
      unaff_ESI[1] = (int)puVar1;
      unaff_ESI[0x38] = (int)param_1;
      param_1[0x36] = param_1[0x36] + 1;
    }
  }
  return;
}


// ==== 0x579090 FUN_00579090

void FUN_00579090(void)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  if (in_EAX[0x38] != 0) {
    iVar1 = *in_EAX;
    piVar2 = (int *)in_EAX[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    in_EAX[0x38] = 0;
    FUN_00579140();
    return;
  }
  return;
}


// ==== 0x5790c0 FUN_005790c0

void FUN_005790c0(void)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  piVar2 = (int *)in_EAX[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  in_EAX[0x38] = 0;
  FUN_00579140();
  return;
}


// ==== 0x5790e0 FUN_005790e0

void FUN_005790e0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *unaff_ESI;
  
  piVar1 = unaff_ESI + 2;
  piVar2 = (int *)unaff_ESI[2];
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    piVar2[0x38] = 0;
    piVar2 = unaff_ESI + 0x36;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (unaff_ESI[0x38] != 0) {
        FUN_005790c0(unaff_ESI[0x38]);
      }
      *DAT_0073b0e0 = unaff_ESI;
      puVar5 = unaff_ESI;
      unaff_ESI[1] = DAT_0073b0e0;
      DAT_0073b0e0 = puVar5;
      *unaff_ESI = &DAT_0073b0dc;
    }
    piVar2 = (int *)*piVar1;
  }
  return;
}


// ==== 0x579140 FUN_00579140

void __fastcall FUN_00579140(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 0x36;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    if (param_1[0x38] != 0) {
      iVar1 = *param_1;
      piVar2 = (int *)param_1[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      param_1[0x38] = 0;
      FUN_00579140();
    }
    *DAT_0073b0e0 = (int)param_1;
    piVar2 = param_1;
    param_1[1] = (int)DAT_0073b0e0;
    DAT_0073b0e0 = piVar2;
    *param_1 = (int)&DAT_0073b0dc;
  }
  return;
}


// ==== 0x579190 FUN_00579190

void __fastcall FUN_00579190(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xe4) = 1;
  for (; puVar1 != (undefined4 *)(param_1 + 8); puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[0x39] == 0) {
      FUN_00579190();
    }
  }
  return;
}


// ==== 0x5791c0 FUN_005791c0

void __fastcall FUN_005791c0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float unaff_EDI;
  
  iVar6 = *(int *)(param_1 + 0xe0);
  if (iVar6 != 0) {
    if (*(int *)(iVar6 + 0xe4) != 0) {
      FUN_005791c0();
    }
    D3DXMatrixMultiply(param_1 + 0x10);
    iVar7 = *(int *)(param_1 + 0xe0);
    if (*(int *)(iVar7 + 0xe4) != 0) {
      FUN_005791c0();
    }
    D3DXVec3Transform(&stack0xffffffd4,param_1 + 0xa0,iVar7 + 0x10);
    iVar7 = *(int *)(param_1 + 0xe0);
    if (*(int *)(iVar7 + 0xe4) != 0) {
      FUN_005791c0();
    }
    fVar1 = *(float *)(iVar7 + 0x44);
    fVar2 = *(float *)(iVar7 + 0x48);
    fVar3 = *(float *)(iVar7 + 0x40);
    iVar7 = *(int *)(param_1 + 0xe0);
    if (*(int *)(iVar7 + 0xe4) != 0) {
      FUN_005791c0();
    }
    fVar4 = *(float *)(iVar7 + 0x94);
    fVar5 = *(float *)(iVar7 + 0x98);
    *(float *)(param_1 + 0x90) = ((float)(param_1 + 0x50) - fVar3) + *(float *)(iVar7 + 0x90);
    *(float *)(param_1 + 0x98) = fVar5 + (unaff_EDI - fVar2);
    *(float *)(param_1 + 0x94) = fVar4 + ((float)(iVar6 + 0x10) - fVar1);
    *(undefined4 *)(param_1 + 0xe4) = 0;
    return;
  }
  bMatrixCopy_b();
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return;
}


// ==== 0x579310 FUN_00579310

void FUN_00579310(undefined4 param_1)

{
  int unaff_EDI;
  undefined1 local_50 [76];
  
  if (*(int *)(unaff_EDI + 0xe0) == 0) {
    bMatrixCopy_b();
  }
  else {
    if (*(int *)(*(int *)(unaff_EDI + 0xe0) + 0xe4) != 0) {
      FUN_005791c0();
    }
    FUN_00565060();
    D3DXMatrixMultiply(unaff_EDI + 0x50,param_1,local_50);
  }
  if (*(int *)(unaff_EDI + 0xe4) == 0) {
    FUN_00579190();
  }
  return;
}


// ==== 0x579380 FUN_00579380

void __thiscall FUN_00579380(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686718;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00567160(param_1);
  local_4 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00578e80(iVar1,param_2);
  }
  *(int *)(iVar1 + 0xd8) = *(int *)(iVar1 + 0xd8) + 1;
  ExceptionList = local_c;
  return;
}


// ==== 0x5793e0 FUN_005793e0

void FUN_005793e0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar4 = DAT_0073b0dc;
  piVar6 = (int *)NullUpdate_ret();
  while (piVar4 != piVar6) {
    piVar1 = (int *)*piVar4;
    piVar2 = (int *)piVar4[1];
    *piVar2 = (int)piVar1;
    piVar1[1] = (int)piVar2;
    FUN_00578f80(piVar4);
    iVar5 = DAT_007345bc;
    iVar3 = *(int *)(DAT_007345bc + 0x18);
    *piVar4 = *(int *)(DAT_007345bc + 0x10);
    *(int **)(iVar5 + 0x10) = piVar4;
    *(int *)(iVar5 + 0x18) = iVar3 + -1;
    piVar4 = piVar1;
  }
  return;
}


// ==== 0x579430 FUN_00579430

void FUN_00579430(void)

{
  undefined4 *puVar1;
  
  DAT_007345bc = (undefined4 *)FUN_00566dc0(0xf0,"SpaceNodeSlotPool",0);
  if (DAT_007345bc == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007345bc;
    puVar1 = DAT_007345bc;
    DAT_007345bc[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007345bc = &DAT_0073d818;
  }
  return;
}


// ==== 0x579480 FUN_00579480

void __fastcall FUN_00579480(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00578f80(piVar1);
    iVar4 = DAT_007345bc;
    iVar2 = *(int *)(DAT_007345bc + 0x18);
    *piVar1 = *(int *)(DAT_007345bc + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x5794c0 FUN_005794c0

void FUN_005794c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *in_EAX;
  
  piVar1 = (int *)*in_EAX;
  piVar3 = piVar1 + 0x36;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    if (piVar1[0x38] != 0) {
      iVar2 = *piVar1;
      piVar3 = (int *)piVar1[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      piVar1[0x38] = 0;
      FUN_00579140();
    }
    *DAT_0073b0e0 = (int)piVar1;
    piVar3 = piVar1;
    piVar1[1] = (int)DAT_0073b0e0;
    DAT_0073b0e0 = piVar3;
    *piVar1 = (int)&DAT_0073b0dc;
  }
  return;
}


// ==== 0x579510 FUN_00579510

void FUN_00579510(void)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685113;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x44);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 8;
    eh_vector_constructor_iterator(puVar1 + 1,8,8,IList_InitEmpty_Thunk,FUN_00579720);
    DAT_007345b8 = puVar1 + 1;
    ExceptionList = local_c;
    return;
  }
  DAT_007345b8 = (undefined4 *)0x0;
  ExceptionList = local_c;
  return;
}


// ==== 0x579590 IList_InitEmpty_Thunk

/* [canon] runtime high (hopper+capstone) docs/re/misc.md */

undefined4 __fastcall IList_InitEmpty_Thunk(undefined4 param_1)

{
  FUN_00589260();
  return param_1;
}


// ==== 0x5795a0 FUN_005795a0

void FUN_005795a0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = DAT_007345b8;
  do {
    if (*(int *)(iVar4 + iVar2) == 0) goto LAB_005795bc;
    piVar3 = (int *)(*(int *)(iVar4 + iVar2) + -4);
    while( true ) {
      if (iVar4 + iVar2 == 0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = (int *)(iVar4 + iVar2 + -4);
      }
      if (piVar3 == piVar1) break;
      if (piVar3[3] == 0) {
        (**(code **)(*piVar3 + 4))(param_1);
        iVar2 = DAT_007345b8;
      }
      if (piVar3[1] == 0) {
LAB_005795bc:
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(piVar3[1] + -4);
      }
    }
    iVar4 = iVar4 + 8;
  } while (iVar4 < 0x40);
  return;
}


// ==== 0x579600 FUN_00579600

void FUN_00579600(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685a08;
  pvStack_c = ExceptionList;
  iVar1 = param_1[1];
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    piVar3 = *(int **)(iVar1 + 8);
    ExceptionList = &pvStack_c;
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[1])(1);
    }
  }
  piVar3 = (int *)*param_1;
  iVar1 = piVar3[0x36];
  local_4 = 0xffffffff;
  piVar3[0x36] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    if (piVar3[0x38] != 0) {
      iVar1 = *piVar3;
      piVar4 = (int *)piVar3[1];
      *piVar4 = iVar1;
      *(int **)(iVar1 + 4) = piVar4;
      piVar3[0x38] = 0;
      FUN_00579140();
    }
    *DAT_0073b0e0 = (int)piVar3;
    piVar4 = piVar3;
    piVar3[1] = (int)DAT_0073b0e0;
    DAT_0073b0e0 = piVar4;
    *piVar3 = (int)&DAT_0073b0dc;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x5796b0 FUN_005796b0

void FUN_005796b0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 4);
    piVar4 = *(int **)(iVar3 + 8);
    *piVar4 = iVar2;
    *(int **)(iVar2 + 4) = piVar4;
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 4))(1);
    }
  }
  *(int *)(param_1 + 8) = param_2;
  iVar3 = FUN_00578cc0(param_2,param_3);
  *(int *)(param_1 + 4) = iVar3;
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
  if (*(int *)(param_1 + 4) == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(*(int *)(param_1 + 4) + 4);
  }
  iVar3 = *(int *)(DAT_007345b8 + param_2 * 8);
  puVar1 = (undefined4 *)(DAT_007345b8 + param_2 * 8);
  *puVar1 = piVar4;
  *(int **)(iVar3 + 4) = piVar4;
  piVar4[1] = (int)puVar1;
  *piVar4 = iVar3;
  return;
}


// ==== 0x579720 FUN_00579720

void __fastcall FUN_00579720(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  while (piVar1 != param_1) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    piVar1 = (int *)*param_1;
  }
  return;
}


// ==== 0x579750 FUN_00579750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00579750(undefined4 *param_1,int param_2,int *param_3)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  uint uVar10;
  char *pcVar11;
  float10 fVar12;
  uint local_32c;
  int local_328;
  undefined4 *local_324;
  undefined1 local_320 [48];
  undefined1 auStack_2f0 [8];
  float fStack_2e8;
  undefined1 auStack_2e0 [32];
  int aiStack_2c0 [160];
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *pvStack_1c;
  code *pcStack_18;
  int local_14;
  
  pcStack_18 = FUN_00686403;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  *param_1 = &PTR_FUN_006ba644;
  param_1[4] = param_2;
  *(int *)(param_2 + 0xd8) = *(int *)(param_2 + 0xd8) + 1;
  param_1[3] = 0;
  local_14 = 0;
  *param_1 = &PTR_FUN_006ba5d4;
  local_32c = 0;
  param_1[0x18] = 0x47c34f80;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)((int)param_1 + 0x71) = 0;
  *(undefined1 *)((int)param_1 + 0x72) = 0;
  puVar6 = (undefined4 *)FUN_00567160();
  local_14._0_1_ = 1;
  local_324 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    pcVar11 = "DEBUG_CUBE";
    local_328 = -1;
    uVar10 = 0x44;
    do {
      local_328 = local_328 * 0x21 + uVar10;
      pbVar1 = (byte *)(pcVar11 + 1);
      uVar10 = (uint)*pbVar1;
      pcVar11 = pcVar11 + 1;
    } while (*pbVar1 != 0);
    iVar7 = FUN_00567160();
    if (iVar7 == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = FUN_004454d0();
    }
    puVar6[2] = uVar8;
    puVar6[3] = 0;
    puVar6[5] = 1;
    puVar6[6] = 0;
    puVar6[4] = 0;
    puVar6[0x18] = 0;
    *DAT_00737820 = puVar6;
    puVar5 = puVar6;
    puVar6[1] = DAT_00737820;
    DAT_00737820 = puVar5;
    *puVar6 = &DAT_0073781c;
    *(undefined1 *)(puVar6 + 7) = 0;
  }
  local_14 = (uint)local_14._1_3_ << 8;
  param_1[0x1a] = puVar6;
  pvVar9 = _malloc(0x7c);
  if (pvVar9 == (void *)0x0) {
    pvVar9 = (void *)0x0;
  }
  else {
    pvVar9 = (void *)CAnimCtrl__InitFields();
  }
  *(undefined4 *)((int)pvVar9 + 8) = *(undefined4 *)(param_2 + 0xd0);
  fVar3 = (float)param_3[5];
  *(float *)((int)pvVar9 + 0x5c) = fVar3;
  if (fVar3 == 0.0) {
    *(undefined4 *)((int)pvVar9 + 0x5c) = 0x3f800000;
  }
  *(int *)((int)pvVar9 + 0x68) = param_3[7];
  uVar10 = param_3[6];
  if ((uVar10 & 0x10) != 0) {
    local_32c = 0x10;
  }
  if ((uVar10 & 0x20) != 0) {
    local_32c = local_32c | 0x20;
  }
  if ((uVar10 & 0x40) != 0) {
    local_32c = local_32c | 0x40;
  }
  if ((char)uVar10 < '\0') {
    local_32c = local_32c | 0x80;
  }
  if (param_3[4] == 0) {
    local_328 = FUN_005a4d80(DAT_007797c4);
    if (local_328 == 0) goto LAB_0057994f;
    FUN_0047b600(0,0);
    if (local_32c == 0) {
      *(uint *)((int)pvVar9 + 0x34) = *(uint *)((int)pvVar9 + 0x34) | 0x12;
      goto LAB_0057994f;
    }
    uVar10 = local_32c | 2;
  }
  else {
    local_328 = FUN_005a4d80(param_3[4]);
    if (local_328 == 0) goto LAB_0057994f;
    FUN_0047b600(0,0);
    if (DAT_007345b4 != 0) {
      *(uint *)((int)pvVar9 + 0x34) = *(uint *)((int)pvVar9 + 0x34) | 0x11;
      goto LAB_0057994f;
    }
    if (local_32c == 0) {
      *(uint *)((int)pvVar9 + 0x34) = *(uint *)((int)pvVar9 + 0x34) | 0x11;
      goto LAB_0057994f;
    }
    uVar10 = local_32c | 1;
  }
  *(uint *)((int)pvVar9 + 0x34) = *(uint *)((int)pvVar9 + 0x34) | uVar10;
LAB_0057994f:
  if (*param_3 != 0) {
    FUN_0047b220();
  }
  if (param_3[1] != 0) {
    FUN_0047b220();
  }
  if (param_3[2] != 0) {
    FUN_0047b220();
  }
  bVar4 = false;
  if ((param_3[4] != 0) && (param_3[3] != 0)) {
    FUN_0047b220();
    bVar4 = true;
    *(float *)((int)pvVar9 + 0x5c) = *(float *)((int)pvVar9 + 0x5c) * _K_HALF;
  }
  iVar7 = 0;
  if ((*(int *)((int)pvVar9 + 0x78) == 0) || (local_328 == 0)) {
    *(undefined4 *)((int)pvVar9 + 0xc) = 0;
    if (*(void **)((int)pvVar9 + 0x14) != (void *)0x0) {
      _free(*(void **)((int)pvVar9 + 0x14));
      *(undefined4 *)((int)pvVar9 + 0x14) = 0;
    }
    *(undefined4 *)((int)pvVar9 + 0x18) = 0;
    if (*(int *)((int)pvVar9 + 0x1c) != 0) {
      (*(code *)PTR_FUN_006dfaa0)(*(int *)((int)pvVar9 + 0x1c),0x40);
      *(undefined4 *)((int)pvVar9 + 0x1c) = 0;
    }
    *(undefined4 *)((int)pvVar9 + 0x20) = 0;
    FUN_0047b1c0();
    FUN_0047b0b0(pvVar9);
    _free(pvVar9);
    param_1[5] = 0;
  }
  else {
    param_1[5] = pvVar9;
  }
  bMatrixCopy_b();
  if (bVar4) {
    D3DXMatrixMultiply(local_320,local_320,&DAT_00779860);
    D3DXMatrixMultiply(&local_32c,&local_32c,&DAT_007798a0);
    iStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    FUN_00440740();
    fVar12 = (float10)GroundQuery__FindSurfaceBelow(auStack_2e0,auStack_2f0,0,0,0);
    param_1[0x1b] = (float)fVar12;
    fStack_2e8 = (float)fVar12;
    *(undefined1 *)((int)param_1 + 0x72) = 1;
    if (0 < iStack_40) {
      do {
        piVar2 = aiStack_2c0 + iVar7;
        iVar7 = iVar7 + 1;
        *(char *)(*piVar2 + 8) = *(char *)(*piVar2 + 8) + -1;
      } while (iVar7 < iStack_40);
    }
  }
  bMatrixCopy_b();
  ExceptionList = pvStack_1c;
  return param_1;
}


// ==== 0x579b10 FUN_00579b10

void * __thiscall FUN_00579b10(void *param_1,byte param_2)

{
  FUN_00579b30(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x579b30 FUN_00579b30

void FUN_00579b30(undefined4 *param_1)

{
  int iVar1;
  void *_Memory;
  undefined4 *puVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685608;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006ba5d4;
  iVar1 = param_1[5];
  local_4 = 0;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xc) = 0;
    if (*(void **)(iVar1 + 0x14) != (void *)0x0) {
      _free(*(void **)(iVar1 + 0x14));
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    *(undefined4 *)(iVar1 + 0x18) = 0;
    if (*(int *)(iVar1 + 0x1c) != 0) {
      (*(code *)PTR_FUN_006dfaa0)(*(int *)(iVar1 + 0x1c),0x40);
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
    FUN_0047b1c0();
    _Memory = (void *)param_1[5];
    if (_Memory != (void *)0x0) {
      FUN_0047b0b0(_Memory);
      _free(_Memory);
    }
  }
  puVar2 = (undefined4 *)param_1[0x1a];
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00591c90(puVar2);
    iVar3 = DAT_007344c8;
    iVar1 = *(int *)(DAT_007344c8 + 0x18);
    *puVar2 = *(undefined4 *)(DAT_007344c8 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar2;
  }
  local_4 = 0xffffffff;
  FUN_00578c70();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x579c00 FUN_00579c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00579c00(int param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_390;
  float local_38c;
  float fStack_388;
  float local_378;
  float local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  float local_340;
  float local_33c;
  undefined4 local_338;
  undefined4 local_334;
  float local_328;
  undefined1 local_320 [48];
  undefined1 auStack_2f0 [16];
  undefined1 auStack_2e0 [32];
  int aiStack_2c0 [160];
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *local_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_0068628b;
  local_1c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar3 = *(int *)(param_1 + 0x10);
    ExceptionList = &local_1c;
    bMatrixCopy_b();
    iVar3 = *(int *)(iVar3 + 0xe4);
    goto joined_r0x00579f61;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  fVar1 = *(float *)(iVar3 + 0x80);
  local_378 = *(float *)(iVar3 + 0x84);
  local_374 = *(float *)(iVar3 + 0x88);
  ExceptionList = &local_1c;
  CAnimCtrl__AdvanceAnimTime(param_2);
  FUN_0047b3d0();
  iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0x1c);
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 0x34) & 1) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xe8) = 0;
    local_370 = 0x3f800000;
    local_36c = 0;
    local_368 = 0;
    local_364 = 0;
    local_360 = 0;
    local_35c = 0x3f800000;
    local_358 = 0;
    local_354 = 0;
    local_350 = 0;
    local_34c = 0;
    local_348 = 0x3f800000;
    local_344 = 0;
    local_340 = 0.0;
    local_33c = 0.0;
    local_338 = 0;
    local_334 = 0x3f800000;
    D3DXMatrixMultiply(&local_370,iVar3 + 0x40,param_1 + 0x20);
LAB_00579e9d:
    iVar3 = *(int *)(param_1 + 0x10);
    bMatrixCopy_b();
    if (*(int *)(iVar3 + 0xe4) == 0) {
      FUN_00579190();
    }
  }
  else {
    *(int *)(*(int *)(param_1 + 0x10) + 0xe8) = iVar3;
    if (*(char *)(param_1 + 0x71) == '\0') goto LAB_00579e9d;
    bMatrixCopy_b();
    if (0 < DAT_007361c4) {
      iVar4 = 0;
      do {
        if ((*(int **)((&DAT_007361bc)[iVar4] + 0x27c) != (int *)0x0) &&
           (cVar2 = (**(code **)(**(int **)((&DAT_007361bc)[iVar4] + 0x27c) + 0x24))(),
           cVar2 == '\0')) {
          local_390 = 0.0;
          local_38c = 0.75;
          fStack_388 = 0.0;
          D3DXVec3Transform(&local_390,&local_390,&DAT_00779860);
          local_340 = local_340 + local_390;
          local_33c = local_33c + local_38c;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_007361c4);
    }
    D3DXMatrixMultiply(local_320,iVar3 + 0x40,&local_370);
    iStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    FUN_00440740();
    uStack_14 = 0;
    fVar5 = (float10)GroundQuery__FindSurfaceBelow(auStack_2e0,auStack_2f0,0,0,0);
    if (*(char *)(param_1 + 0x72) == '\0') {
      *(float *)(param_1 + 0x6c) = (float)fVar5;
    }
    else {
      *(float *)(param_1 + 0x6c) =
           (float)((float10)0.5 * fVar5 +
                  ((float10)_K_ONE - (float10)0.5) * (float10)*(float *)(param_1 + 0x6c));
    }
    iVar3 = *(int *)(param_1 + 0x10);
    local_338 = *(undefined4 *)(param_1 + 0x6c);
    *(undefined1 *)(param_1 + 0x72) = 1;
    bMatrixCopy_b();
    if (*(int *)(iVar3 + 0xe4) == 0) {
      FUN_00579190();
    }
    iVar3 = 0;
    uStack_14 = 0xffffffff;
    if (0 < iStack_40) {
      do {
        *(char *)(aiStack_2c0[iVar3] + 8) = *(char *)(aiStack_2c0[iVar3] + 8) + -1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iStack_40);
    }
  }
  if (param_2 <= 0.0001) {
    ExceptionList = local_1c;
    return;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  local_328 = *(float *)(iVar3 + 0x88);
  local_390 = *(float *)(iVar3 + 0x80) - fVar1;
  local_38c = *(float *)(iVar3 + 0x84) - local_378;
  param_2 = _K_ONE / param_2;
  fStack_388 = (local_328 - local_374) * param_2;
  *(float *)(iVar3 + 0xa8) = fStack_388;
  *(float *)(iVar3 + 0xa0) = local_390 * param_2;
  *(float *)(iVar3 + 0xa4) = local_38c * param_2;
  iVar3 = *(int *)(iVar3 + 0xe4);
joined_r0x00579f61:
  if (iVar3 == 0) {
    FUN_00579190();
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x579f90 FUN_00579f90

void __thiscall FUN_00579f90(char param_1,float param_2)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  if (iVar1 != 0) {
    if (param_1 != '\0') {
      *(float *)(iVar1 + 100) = DAT_006ffdbc * *(float *)(iVar1 + 0x5c) * param_2;
      return;
    }
    *(float *)(iVar1 + 100) = param_2;
  }
  return;
}


// ==== 0x579fc0 FUN_00579fc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00579fc0(char param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  if (iVar1 == 0) {
    return (float10)0.0;
  }
  if (param_1 != '\0') {
    return (((float10)_K_ONE / (float10)DAT_006ffdbc) / (float10)*(float *)(iVar1 + 0x5c)) *
           (float10)*(float *)(iVar1 + 100);
  }
  return (float10)*(float *)(iVar1 + 100);
}


// ==== 0x579ff0 FUN_00579ff0

float10 FUN_00579ff0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  float10 fVar2;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  fVar2 = (float10)1e+13;
  if ((iVar1 != 0) && (-1 < *(char *)(iVar1 + 0x34))) {
    fVar2 = (float10)FUN_0057a020(*(undefined4 *)(iVar1 + 100),param_1);
  }
  return fVar2;
}


// ==== 0x57a020 FUN_0057a020

float10 FUN_0057a020(float param_1,float param_2)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  if (((iVar1 != 0) && (param_1 <= *(float *)(iVar1 + 0x60))) &&
     (param_2 <= *(float *)(iVar1 + 0x60))) {
    return (((float10)param_2 - (float10)param_1) / (float10)*(float *)(iVar1 + 0x5c)) /
           (float10)DAT_006ffdbc;
  }
  return (float10)9999999.0;
}


// ==== 0x57a070 FUN_0057a070

void FUN_0057a070(int param_1,undefined4 param_2)

{
  undefined4 *unaff_EDI;
  undefined1 local_90 [36];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 local_50 [76];
  
  if (*(int *)(param_1 + 0x14) == 0) {
    unaff_EDI[1] = 0;
    unaff_EDI[2] = 0;
    *unaff_EDI = 0;
    return;
  }
  FUN_0047b500(param_2);
  D3DXMatrixMultiply(local_90,local_50,param_1 + 0x20);
  unaff_EDI[1] = uStack_68;
  unaff_EDI[2] = uStack_64;
  *unaff_EDI = uStack_6c;
  return;
}


// ==== 0x57a0e0 FUN_0057a0e0

float10 __thiscall FUN_0057a0e0(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_50 [24];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0.0;
  local_20 = 0x3f800000;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_0057a070(param_1,param_2);
  local_30 = 0;
  TrackPath__UpdateCursor(&DAT_007372b0,local_50);
  return (float10)local_24;
}


// ==== 0x57a160 FUN_0057a160

void FUN_0057a160(void)

{
  uint *puVar1;
  int in_EAX;
  
  puVar1 = (uint *)(*(int *)(in_EAX + 0x14) + 0x34);
  *puVar1 = *puVar1 & 0xffffff7f;
  return;
}


// ==== 0x57a170 FUN_0057a170

void FUN_0057a170(void)

{
  uint *puVar1;
  int in_EAX;
  
  puVar1 = (uint *)(*(int *)(in_EAX + 0x14) + 0x34);
  *puVar1 = *puVar1 | 0x20;
  return;
}


// ==== 0x57a180 FUN_0057a180

undefined4 FUN_0057a180(void)

{
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0x14) != 0) && (-1 < *(char *)(*(int *)(in_EAX + 0x14) + 0x34))) {
    return 1;
  }
  return 0;
}


// ==== 0x57a1a0 FUN_0057a1a0

void __fastcall FUN_0057a1a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba5a8;
  FUN_00578370();
  return;
}


// ==== 0x57a1b0 FUN_0057a1b0

undefined4 FUN_0057a1b0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057a270(pvVar1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57a220 FUN_0057a220

void * __thiscall FUN_0057a220(void *param_1,byte param_2)

{
  FUN_0057a1a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57a240 FUN_0057a240

void __fastcall FUN_0057a240(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba5a0;
  FUN_00578c70();
  return;
}


// ==== 0x57a250 FUN_0057a250

void * __thiscall FUN_0057a250(void *param_1,byte param_2)

{
  FUN_0057a240();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57a270 FUN_0057a270

undefined4 * __thiscall FUN_0057a270(undefined4 param_1,undefined4 *param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005782b0(param_2,"CarWorldObject");
  param_2[0x24] = param_1;
  local_4 = 0;
  *param_2 = &PTR_FUN_006ba5a8;
  FUN_005796b0(param_2 + 7,6,param_1);
  FUN_00578660(1);
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x57a2e0 FUN_0057a2e0

void __thiscall FUN_0057a2e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00577a00(param_1,param_2,param_3,(int)*(short *)(*(int *)(param_1 + 0x90) + 10));
  return;
}


// ==== 0x57a300 FUN_0057a300

undefined4 __fastcall FUN_0057a300(int param_1)

{
  if ((*(char *)(*(int *)(param_1 + 0x90) + 0x8a8) == '\0') &&
     (*(char *)(*(int *)(param_1 + 0x90) + 0x4d0) != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x57a330 FUN_0057a330

float10 __fastcall FUN_0057a330(int param_1)

{
  return (float10)*(float *)(*(int *)(param_1 + 0x90) + 0x814);
}


// ==== 0x57a340 FUN_0057a340

undefined4 __fastcall FUN_0057a340(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x3c);
}


// ==== 0x57a350 FUN_0057a350

void __thiscall FUN_0057a350(int param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006ba644;
  in_EAX[4] = param_1;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
  in_EAX[3] = 0;
  *in_EAX = &PTR_FUN_006ba5a0;
  in_EAX[5] = param_2;
  return;
}


// ==== 0x57a380 FUN_0057a380

void FUN_0057a380(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  bMatrixCopy_b();
  iVar2 = *(int *)(unaff_ESI + 0x10);
  bMatrixCopy_b();
  if (*(int *)(iVar2 + 0xe4) == 0) {
    FUN_00579190();
  }
  iVar2 = *(int *)(unaff_ESI + 0x14);
  iVar3 = *(int *)(unaff_ESI + 0x10);
  uVar1 = *(undefined4 *)(iVar2 + 0x78);
  uVar4 = *(undefined4 *)(iVar2 + 0x70);
  *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(iVar2 + 0x74);
  *(undefined4 *)(iVar3 + 0xa0) = uVar4;
  *(undefined4 *)(iVar3 + 0xa8) = uVar1;
  if (*(int *)(iVar3 + 0xe4) == 0) {
    FUN_00579190();
  }
  return;
}


// ==== 0x57a410 FUN_0057a410

void FUN_0057a410(void)

{
  FUN_0057a380();
  return;
}


// ==== 0x57a420 FUN_0057a420

void FUN_0057a420(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685f13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  unaff_ESI[0x6d] = 0;
  unaff_ESI[0x6e] = 0;
  puVar4 = unaff_ESI + 4;
  for (iVar3 = 0x70; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  FUN_00458f10(0,0);
  *DAT_0073b080 = unaff_ESI;
  puVar4 = unaff_ESI;
  unaff_ESI[1] = DAT_0073b080;
  DAT_0073b080 = puVar4;
  *unaff_ESI = &DAT_0073b07c;
  unaff_ESI[0x75] = param_1;
  unaff_ESI[0x74] = 0;
  iVar3 = FUN_00647b70();
  if (iVar3 == 4) {
    pvVar1 = _malloc(0x28);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      iVar3 = *(int *)(unaff_ESI[0x75] + 0x1c);
      if (*(int *)(iVar3 + 0xe4) != 0) {
        FUN_005791c0();
      }
      uVar2 = FUN_004440c0(iVar3 + 0x40);
    }
    unaff_ESI[0x74] = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x57a4f0 FUN_0057a4f0

void FUN_0057a4f0(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  
  piVar1 = (int *)in_EAX[1];
  iVar2 = *in_EAX;
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  iVar2 = FUN_00647b70();
  if ((iVar2 == 4) && ((void *)in_EAX[0x74] != (void *)0x0)) {
    _free((void *)in_EAX[0x74]);
  }
  return;
}


// ==== 0x57a530 FUN_0057a530

void FUN_0057a530(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_00647b70();
  if (iVar1 == 6) {
    iVar1 = 0;
    iVar2 = FUN_00647b70();
    if (iVar2 == 6) {
      iVar1 = *(int *)(*(int *)(unaff_EBX + 0x1d4) + 0x90);
    }
    iVar2 = *(int *)(iVar1 + 0x24);
    if (((iVar2 == 3) || (iVar2 == 2)) || (iVar2 == 4)) {
      puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x30) + 0x10);
      puVar4 = (undefined4 *)(unaff_EBX + 0x10);
      for (iVar2 = 0x70; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else {
      FUN_00456d50(unaff_EBX + 0x10);
    }
  }
  else {
    FUN_0045a250(unaff_EBX + 0x10);
  }
  iVar1 = FUN_00647b70();
  if (iVar1 == 4) {
    iVar1 = *(int *)(*(int *)(unaff_EBX + 0x1d4) + 0x1c);
    if (*(int *)(iVar1 + 0xe4) != 0) {
      FUN_005791c0();
    }
    TrackPath__UpdateCursor(&DAT_007372b0,iVar1 + 0x40);
  }
  return;
}


// ==== 0x57a5f0 FUN_0057a5f0

void FUN_0057a5f0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = *(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c);
  if (*(int *)(iVar4 + 0xe4) != 0) {
    FUN_005791c0();
  }
  fVar1 = *(float *)(iVar4 + 0x98);
  fVar2 = *(float *)(iVar4 + 0x94);
  fVar3 = *(float *)(iVar4 + 0x90);
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  FUN_00429c50(SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3));
  return;
}


// ==== 0x57a680 FUN_0057a680

undefined4 FUN_0057a680(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_00647b70();
  if (iVar1 == 6) {
    return *(undefined4 *)(*(int *)(unaff_ESI + 0x1d4) + 0x90);
  }
  return 0;
}


// ==== 0x57a6b0 FUN_0057a6b0

uint FUN_0057a6b0(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_00647b70();
  if (uVar1 == 6) {
    return CONCAT31((int3)((uint)*(int *)(unaff_ESI + 0x1d4) >> 8),
                    *(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x14) + 4) == 1
                   );
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x57a6f0 FUN_0057a6f0

uint FUN_0057a6f0(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  
  uVar2 = FUN_00647b70();
  if (uVar2 == 6) {
    iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x1c);
    return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 != 0);
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x57a720 FUN_0057a720

uint FUN_0057a720(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_00647b70();
  if (uVar1 == 6) {
    return CONCAT31((int3)((uint)*(int *)(unaff_ESI + 0x1d4) >> 8),
                    *(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x14) + 4) == 3
                   );
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x57a760 FUN_0057a760

uint FUN_0057a760(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_00647b70();
  if (uVar1 == 6) {
    return CONCAT31((int3)((uint)*(int *)(unaff_ESI + 0x1d4) >> 8),
                    *(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0xc) + 0xc54)
                    == 1);
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x57a7a0 FUN_0057a7a0

undefined4 FUN_0057a7a0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_00647b70();
  if (iVar1 == 6) {
    return *(undefined4 *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x2c);
  }
  return 0;
}


// ==== 0x57a7d0 FUN_0057a7d0

bool FUN_0057a7d0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_00647b70();
  if (iVar1 != 4) {
    iVar1 = FUN_00647b70();
    if (iVar1 == 6) {
      return 2 < *(int *)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x3cc);
    }
  }
  return true;
}


// ==== 0x57a820 FUN_0057a820

float10 FUN_0057a820(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  
  iVar4 = FUN_00647b70();
  fVar3 = DAT_00700680;
  if ((iVar4 == 6) &&
     (piVar1 = *(int **)(*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) + 0x2c), piVar1 != (int *)0x0)
     ) {
    fVar2 = *(float *)(piVar1[1] + 0x3d4);
    fVar5 = (float10)(**(code **)(*piVar1 + 0x50))();
    fVar5 = fVar5 * (float10)fVar2;
  }
  else {
    fVar5 = (float10)FUN_0044d5f0();
    fVar5 = fVar5 * (float10)2.0;
  }
  if (fVar5 <= (float10)fVar3) {
    fVar5 = (float10)fVar3;
  }
  return fVar5;
}


// ==== 0x57a8a0 FUN_0057a8a0

undefined1 FUN_0057a8a0(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  iVar2 = FUN_00647b70();
  if ((iVar2 == 6) && (*(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x90) != 0)) {
    uVar1 = Car__IsResetGraceActive();
    return uVar1;
  }
  piVar3 = (int *)Obj_GetField34();
  iVar2 = (**(code **)(*piVar3 + 0x68))();
  return iVar2 != 0;
}


// ==== 0x57a8e0 FUN_0057a8e0

float10 __fastcall FUN_0057a8e0(int param_1)

{
  int in_EAX;
  
  if ((-1 < in_EAX) && (in_EAX < 5)) {
    return (float10)*(float *)(param_1 + 0x14);
  }
  if ((10 < in_EAX) && (in_EAX < 0x11)) {
    return (float10)*(float *)(param_1 + -0x14 + in_EAX * 4);
  }
  return (float10)0.0;
}


// ==== 0x57a910 FUN_0057a910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057a910(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  float *pfVar11;
  int *piVar12;
  int *piVar13;
  float10 fVar14;
  float10 fVar15;
  float *pfStack_55c;
  float fStack_558;
  int iStack_554;
  float local_550;
  int *piStack_54c;
  char cStack_545;
  float *local_544;
  float *pfStack_540;
  int iStack_53c;
  undefined4 *puStack_538;
  float *pfStack_534;
  float *pfStack_530;
  float fStack_52c;
  float fStack_528;
  int iStack_524;
  float fStack_520;
  float fStack_51c;
  undefined4 uStack_518;
  float fStack_510;
  float fStack_50c;
  undefined4 uStack_508;
  undefined4 uStack_500;
  undefined4 uStack_4fc;
  undefined4 uStack_4f8;
  undefined4 uStack_4f4;
  undefined4 uStack_4f0;
  undefined4 uStack_4ec;
  undefined4 uStack_4e8;
  undefined4 uStack_4e4;
  undefined4 uStack_4e0;
  undefined4 uStack_4dc;
  undefined4 uStack_4d8;
  undefined4 uStack_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined4 uStack_4c8;
  undefined4 uStack_4c4;
  float fStack_4b8;
  float fStack_4b4;
  undefined4 uStack_4b0;
  float fStack_4ac;
  float fStack_4a8;
  float fStack_4a4;
  float local_4a0;
  float fStack_49c;
  undefined4 uStack_498;
  int iStack_494;
  float fStack_490;
  float fStack_48c;
  float fStack_488;
  float fStack_480;
  float fStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  float fStack_470;
  float fStack_46c;
  undefined4 uStack_468;
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined4 uStack_45c;
  float fStack_458;
  float fStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  float fStack_448;
  float fStack_444;
  undefined1 auStack_43c [28];
  float afStack_420 [16];
  int aiStack_3e0 [16];
  int aiStack_3a0 [225];
  void *local_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_006860b6;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 0xe2) = 0xff;
  if (0 < *(int *)(param_2 + 4)) {
    local_4a0 = *(float *)(*param_1 + 0x814);
    piVar10 = *(int **)(*param_1 + 0x2c);
    local_550 = *(float *)(piVar10[1] + 0x3d4);
    local_544 = DAT_00700680;
    fVar14 = (float10)(**(code **)(*piVar10 + 0x50))();
    if (fVar14 * (float10)local_550 <= (float10)(float)local_544) {
      pfStack_534 = local_544;
    }
    else {
      pfStack_534 = (float *)(float)(fVar14 * (float10)local_550);
    }
    local_550 = *(float *)(*param_1 + 0x3d4);
    fVar14 = (float10)FUN_00456830(*param_1,local_550);
    fStack_49c = (float)fVar14;
    iVar8 = *param_1;
    fStack_490 = *(float *)(iVar8 + 0x70);
    local_550 = *(float *)(iVar8 + 0x78);
    fStack_48c = *(float *)(iVar8 + 0x74);
    fStack_4b4 = *(float *)(iVar8 + 0x60);
    fStack_4a8 = *(float *)(iVar8 + 100);
    iVar9 = *(int *)(iVar8 + 0x10);
    fStack_4a4 = *(float *)(iVar8 + 0x68);
    fStack_488 = local_550;
    if (*(char *)(iVar9 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    iStack_494 = (int)*(char *)(iVar9 + 0x424);
    fStack_528 = 0.0;
    local_550 = 0.0;
    iStack_524 = 0xf;
    iStack_53c = 0;
    FUN_005a6700(&fStack_528,&local_550,param_3);
    puVar6 = (undefined4 *)FUN_005a7340();
    Atan2ToAngle16(*puVar6,puVar6[1]);
    uStack_500 = 0x3f800000;
    uStack_4fc = 0;
    uStack_4f8 = 0;
    uStack_4f4 = 0;
    uStack_4f0 = 0;
    uStack_4ec = 0x3f800000;
    uStack_4e8 = 0;
    uStack_4e4 = 0;
    uStack_4e0 = 0;
    uStack_4dc = 0;
    uStack_4d8 = 0x3f800000;
    uStack_4d4 = 0;
    uStack_4d0 = 0;
    uStack_4cc = 0;
    uStack_4c8 = 0;
    uStack_4c4 = 0x3f800000;
    FUN_0040b930();
    D3DXMatrixMultiply(&uStack_500,&uStack_500,aiStack_3e0);
    D3DXVec3Transform(auStack_43c,&fStack_49c,&fStack_50c);
    pfVar11 = DAT_0073b07c;
    pfStack_540 = (float *)NullUpdate_ret();
    if (pfVar11 != pfStack_540) {
      local_544 = (float *)(param_1 + 8);
      pfStack_530 = (float *)(param_1 + 7);
      do {
        cStack_545 = (int *)pfVar11[0x75] == *(int **)(*param_1 + 0x82c);
        if ((bool)cStack_545) {
          iStack_524 = 0x10;
        }
        cVar5 = (**(code **)(*(int *)pfVar11[0x75] + 0x20))();
        if (((cVar5 != '\0') || (cStack_545 != '\0')) && (iStack_53c < iStack_524)) {
          iVar8 = *(int *)((int)pfVar11[0x75] + 0x1c);
          if (*(int *)(iVar8 + 0xe4) != 0) {
            FUN_005791c0();
          }
          fStack_4ac = *(float *)(iVar8 + 0x48);
          iVar9 = *(int *)((int)pfVar11[0x75] + 0x1c);
          fVar2 = *(float *)(iVar8 + 0x40) - fStack_4b4;
          piStack_54c = (int *)(*(float *)(iVar8 + 0x44) - fStack_4a8);
          fVar1 = fStack_4ac - fStack_4a4;
          if (*(int *)(iVar9 + 0xe4) != 0) {
            FUN_005791c0();
          }
          fStack_4b8 = *(float *)(iVar9 + 0x98);
          fVar3 = *(float *)(iVar9 + 0x90) - fStack_490;
          iVar8 = *param_1;
          fVar4 = *(float *)(iVar9 + 0x94) - fStack_48c;
          fVar2 = SQRT(fVar2 * fVar2 + (float)piStack_54c * (float)piStack_54c + fVar1 * fVar1);
          fStack_558 = SQRT(fVar3 * fVar3 +
                            fVar4 * fVar4 + (fStack_4b8 - fStack_488) * (fStack_4b8 - fStack_488));
          pfVar7 = (float *)FUN_00578730();
          if (*pfVar7 * *(float *)(iVar8 + 0x90) + pfVar7[1] * *(float *)(iVar8 + 0x94) < 0.0) {
            fStack_558 = -fStack_558;
          }
          iVar8 = FUN_00647b70();
          if (iVar8 == 4) {
            fVar14 = (float10)*(float *)((int)pfVar11[0x74] + 0x14);
          }
          else {
            fVar14 = (float10)(**(code **)(*(int *)pfVar11[0x75] + 0x24))();
          }
          fVar14 = fVar14 - (float10)local_4a0;
          if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
            if ((float10)DAT_007372b0 * (float10)-0.5 <= fVar14) {
              if ((float10)DAT_007372b0 * (float10)_K_HALF < fVar14) {
                fVar14 = fVar14 - (float10)DAT_007372b0;
              }
            }
            else {
              fVar14 = fVar14 + (float10)DAT_007372b0;
            }
          }
          if (((fVar2 < (float)pfStack_534 != (fVar2 == (float)pfStack_534)) ||
              (cVar5 = FUN_004569b0(*param_1,fVar2,fStack_558,fStack_49c,0), cVar5 != '\0')) &&
             ((float)ABS(fVar14) <= (float)pfStack_534 * 3.0)) {
            fStack_52c = 0.0;
            if (*(int *)(*(int *)((int)pfVar11[0x75] + 0x1c) + 0xe4) != 0) {
              FUN_005791c0();
            }
            if (*(int *)(*(int *)((int)pfVar11[0x75] + 0x1c) + 0xe4) != 0) {
              FUN_005791c0();
            }
            FUN_005a6760(param_2,pfVar11,&fStack_52c,&puStack_538);
            fVar2 = fStack_52c;
            puStack_538 = (undefined4 *)FUN_005a67d0(fStack_52c,0);
            piStack_54c = *(int **)(param_2 + 8 + (int)puStack_538 * 4);
            fVar14 = (float10)FUN_005a74f0(piStack_54c,fVar2,iStack_494);
            *pfStack_530 = (float)fVar14;
            fStack_558 = 1.54143e-44;
            pfStack_55c = local_544;
            iStack_554 = 6;
            do {
              if (*(int *)(*(int *)((int)pfVar11[0x75] + 0x1c) + 0xe4) != 0) {
                FUN_005791c0();
              }
              iVar8 = *(int *)((int)pfVar11[0x75] + 0x1c);
              if (*(int *)(iVar8 + 0xe4) != 0) {
                FUN_005791c0();
              }
              FUN_00578730();
              fVar14 = (float10)FUN_005a7390(iVar8 + 0x40,fStack_558);
              pfVar7 = local_544;
              *pfStack_55c = (float)fVar14;
              pfStack_55c = pfStack_55c + 1;
              fStack_558 = (float)((int)fStack_558 + 1);
              iStack_554 = iStack_554 + -1;
            } while (iStack_554 != 0);
            local_544[-2] = fStack_52c;
            local_544[6] = (float)puStack_538;
            cVar5 = (char)piStack_54c[0x17];
            if ((cVar5 == -1) || (*(short *)((int)piStack_54c + 0x5e) == -1)) {
LAB_0057af45:
              puVar6 = (undefined4 *)0x0;
            }
            else {
              if (cVar5 < 0) {
                iVar8 = 0;
              }
              else {
                iVar8 = (&DAT_0077af30)[cVar5];
              }
              iVar8 = *(short *)((int)piStack_54c + 0x5e) * 0x88 + 0x27c + iVar8;
              if (iVar8 == 0) goto LAB_0057af45;
              puVar6 = (undefined4 *)(**(code **)(*piStack_54c + 0x14))(iVar8);
            }
            Atan2ToAngle16(*puVar6,puVar6[1]);
            uStack_500 = 0x3f800000;
            uStack_4fc = 0;
            uStack_4f8 = 0;
            uStack_4f4 = 0;
            uStack_4f0 = 0;
            uStack_4ec = 0x3f800000;
            uStack_4e8 = 0;
            uStack_4e4 = 0;
            uStack_4e0 = 0;
            uStack_4dc = 0;
            uStack_4d8 = 0x3f800000;
            uStack_4d4 = 0;
            uStack_4d0 = 0;
            uStack_4cc = 0;
            uStack_4c8 = 0;
            uStack_4c4 = 0x3f800000;
            fVar14 = (float10)FUN_00564b10();
            fVar15 = (float10)FUN_00564b10();
            fStack_47c = (float)fVar15;
            fStack_470 = (float)-fVar15;
            uStack_478 = 0;
            uStack_474 = 0;
            uStack_468 = 0;
            uStack_464 = 0;
            uStack_460 = 0;
            uStack_45c = 0;
            fStack_458 = 1.0;
            fStack_454 = 0.0;
            uStack_450 = 0;
            uStack_44c = 0;
            fStack_448 = 0.0;
            fStack_444 = 1.0;
            fStack_480 = (float)fVar14;
            fStack_46c = (float)fVar14;
            D3DXMatrixMultiply(&uStack_500,&uStack_500,&fStack_480);
            iVar8 = *(int *)((int)pfVar11[0x75] + 0x1c);
            if (*(int *)(iVar8 + 0xe4) != 0) {
              FUN_005791c0();
            }
            D3DXVec3Transform(&uStack_44c,iVar8 + 0x90,&fStack_50c);
            pfVar7[-6] = fStack_458 - fStack_448;
            pfVar7[-5] = fStack_454 - fStack_444;
            iVar8 = (**(code **)(*(int *)pfVar11[0x75] + 0x28))();
            if (iVar8 == 0) {
              fStack_510 = 0.0;
              fStack_50c = 0.0;
              uStack_508 = 0;
              fStack_520 = 0.0;
              fStack_51c = 0.0;
              uStack_518 = 0;
            }
            else {
              iVar8 = *(int *)(iVar8 + 0x10);
              iVar9 = *(int *)(iVar8 + 0x10);
              if (iVar9 == 1) {
                FUN_004733a0(&fStack_510);
              }
              else if (iVar9 == 3) {
                FUN_00472aa0();
              }
              else if (iVar9 == 4) {
                fStack_510 = *(float *)(iVar8 + 0x30);
                uStack_518 = *(undefined4 *)(iVar8 + 0x38);
                fStack_50c = *(float *)(iVar8 + 0x34);
                fStack_520 = *(float *)(iVar8 + 0x30);
                fStack_51c = *(float *)(iVar8 + 0x34);
                uStack_508 = uStack_518;
                uStack_4b0 = uStack_518;
                uStack_498 = uStack_518;
              }
            }
            fVar2 = (fStack_51c - fStack_50c) * _K_HALF;
            piStack_54c = (int *)CONCAT22(piStack_54c._2_2_,*(undefined2 *)(*param_1 + 0x3b4));
            fVar1 = (fStack_520 - fStack_510) * _K_HALF;
            puStack_538 = (undefined4 *)FUN_00578730();
            iVar8 = FUN_00578730();
            Atan2ToAngle16(*puStack_538,*(undefined4 *)(iVar8 + 4));
            fVar14 = (float10)FUN_00564b10();
            fVar14 = fVar14 * fVar14;
            fVar15 = (float10)_K_ONE;
            iStack_53c = iStack_53c + 1;
            pfStack_530 = pfStack_530 + 0xe;
            pfVar7[7] = (float)pfVar11;
            local_544 = pfVar7 + 0xe;
            pfVar7[-4] = (float)(fVar14 * (float10)fVar2 + (float10)fVar1 * (fVar15 - fVar14));
            pfVar7[-3] = (float)((fVar15 - fVar14) * (float10)fVar2 + fVar14 * (float10)fVar1);
          }
        }
        pfVar11 = (float *)*pfVar11;
      } while (pfVar11 != pfStack_540);
    }
    param_1[1] = iStack_53c;
    eh_vector_constructor_iterator(aiStack_3a0,0x38,0x10,FUN_0044a300,NullUpdate_ret);
    iVar8 = param_1[1];
    piVar10 = param_1 + 2;
    piVar12 = aiStack_3a0;
    for (iVar9 = 0xe0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar12 = *piVar10;
      piVar10 = piVar10 + 1;
      piVar12 = piVar12 + 1;
    }
    iVar9 = 0;
    if (0 < iVar8) {
      piVar10 = aiStack_3a0;
      do {
        fVar2 = (float)piVar10[4] - fStack_528;
        aiStack_3e0[iVar9] = (int)piVar10;
        if ((param_3 < 0) || (4 < param_3)) {
          if ((param_3 < 0xb) || (0x10 < param_3)) {
            fVar1 = 0.0;
          }
          else {
            fVar1 = (float)piVar10[param_3 + -5];
          }
        }
        else {
          fVar1 = (float)piVar10[5];
        }
        pfStack_540 = (float *)(fVar2 * fVar2 + (fVar1 - local_550) * (fVar1 - local_550));
        afStack_420[iVar9] = (float)pfStack_540;
        if (fVar2 < 0.0) {
          afStack_420[iVar9] = (float)pfStack_540 * -1.0;
        }
        iVar9 = iVar9 + 1;
        piVar10 = piVar10 + 0xe;
      } while (iVar9 < iVar8);
    }
    if (0 < param_1[1]) {
      fVar2 = (float)param_1[1];
      pfStack_540 = (float *)(param_1[1] + -1);
      local_550 = fVar2;
      do {
        iVar8 = 0;
        if (0 < (int)pfStack_540) {
          do {
            if (afStack_420[iVar8] < afStack_420[iVar8 + 1]) {
              fVar1 = afStack_420[iVar8];
              iVar9 = aiStack_3e0[iVar8 + 1];
              aiStack_3e0[iVar8 + 1] = aiStack_3e0[iVar8];
              fVar3 = afStack_420[iVar8 + 1];
              afStack_420[iVar8 + 1] = fVar1;
              aiStack_3e0[iVar8] = iVar9;
              afStack_420[iVar8] = fVar3;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < (int)fVar2 + -1);
        }
        local_550 = (float)((int)local_550 + -1);
      } while (local_550 != 0.0);
    }
    iVar8 = 0;
    if (0 < param_1[1]) {
      piVar10 = param_1 + 0xf;
      do {
        piVar12 = (int *)aiStack_3e0[iVar8];
        piVar13 = piVar10 + -0xd;
        for (iVar9 = 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
          *piVar13 = *piVar12;
          piVar12 = piVar12 + 1;
          piVar13 = piVar13 + 1;
        }
        if (*(int *)(*piVar10 + 0x1d4) == *(int *)(*param_1 + 0x82c)) {
          *(char *)(param_1 + 0xe2) = (char)iVar8;
        }
        iVar8 = iVar8 + 1;
        piVar10 = piVar10 + 0xe;
      } while (iVar8 < param_1[1]);
    }
    uStack_14 = 0xffffffff;
    eh_vector_destructor_iterator(aiStack_3a0,0x38,0x10,NullUpdate_ret);
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x57b480 FUN_0057b480

float10 __fastcall FUN_0057b480(int param_1,int param_2)

{
  int in_EAX;
  float10 fVar1;
  
  param_1 = *(char *)(param_1 + 0x388) * 0x38 + 8 + param_1;
  if ((in_EAX < 0) || (4 < in_EAX)) {
    if ((in_EAX < 0xb) || (0x10 < in_EAX)) {
      fVar1 = (float10)0.0;
    }
    else {
      fVar1 = (float10)*(float *)(param_2 + -0x14 + in_EAX * 4);
    }
  }
  else {
    fVar1 = (float10)*(float *)(param_2 + 0x14);
  }
  if ((-1 < in_EAX) && (in_EAX < 5)) {
    return fVar1 - (float10)*(float *)(param_1 + 0x14);
  }
  if ((10 < in_EAX) && (in_EAX < 0x11)) {
    return fVar1 - (float10)*(float *)(param_1 + -0x14 + in_EAX * 4);
  }
  return fVar1 - (float10)0.0;
}


// ==== 0x57b4e0 FUN_0057b4e0

int __thiscall FUN_0057b4e0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    piVar2 = (int *)(param_1 + 0x3c);
    do {
      if (*(int *)(*piVar2 + 0x1d4) == *(int *)(param_2 + 0x82c)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xe;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return -1;
}


// ==== 0x57b520 FUN_0057b520

int FUN_0057b520(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 4)) {
    piVar2 = (int *)(unaff_ESI + 0x3c);
    do {
      if (*piVar2 == unaff_EDI) {
        if (iVar1 == -1) {
          return 0;
        }
        return iVar1 * 0x38 + 8 + unaff_ESI;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xe;
    } while (iVar1 < *(int *)(unaff_ESI + 4));
  }
  return 0;
}


// ==== 0x57b550 FUN_0057b550

int FUN_0057b550(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 4)) {
    piVar2 = (int *)(unaff_ESI + 0x3c);
    do {
      if (*(int *)(*piVar2 + 0x1d4) == unaff_EDI) {
        if (iVar1 == -1) {
          return 0;
        }
        return iVar1 * 0x38 + 8 + unaff_ESI;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xe;
    } while (iVar1 < *(int *)(unaff_ESI + 4));
  }
  return 0;
}


// ==== 0x57b590 FUN_0057b590

void FUN_0057b590(void)

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
    FUN_0057a4f0();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x57b5c0 FUN_0057b5c0

void __fastcall FUN_0057b5c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba464;
  FUN_00578370();
  return;
}


// ==== 0x57b5d0 FUN_0057b5d0

undefined4 FUN_0057b5d0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x90);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057c240(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b640 FUN_0057b640

void * __thiscall FUN_0057b640(void *param_1,byte param_2)

{
  FUN_0057b5c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57b660 FUN_0057b660

undefined4 FUN_0057b660(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057bdd0(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b6d0 FUN_0057b6d0

undefined4 FUN_0057b6d0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xe0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057bf90(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b740 FUN_0057b740

undefined4 FUN_0057b740(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x90);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057b9f0(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b7b0 FUN_0057b7b0

undefined4 * FUN_0057b7b0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x90);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00578060(puVar1,param_1,0);
    *puVar1 = &PTR_FUN_006ba3b4;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x57b810 FUN_0057b810

undefined4 FUN_0057b810(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686ee3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057bb10(pvVar1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b880 FUN_0057b880

undefined4 FUN_0057b880(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x90);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057bcf0(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x57b8f0 FUN_0057b8f0

undefined4 * FUN_0057b8f0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x90);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00578060(puVar1,param_1,0);
    *puVar1 = &PTR_FUN_006ba4bc;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x57b950 FUN_0057b950

void __fastcall FUN_0057b950(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba490;
  FUN_00578370();
  return;
}


// ==== 0x57b960 FUN_0057b960

undefined4 * FUN_0057b960(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686ea3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x90);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00578060(puVar1,param_1,0);
    *puVar1 = &PTR_FUN_006ba490;
    *(undefined4 *)(puVar1[0xc] + 0x18) = 1;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x57b9d0 FUN_0057b9d0

void * __thiscall FUN_0057b9d0(void *param_1,byte param_2)

{
  FUN_0057b950();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57b9f0 FUN_0057b9f0

undefined4 * FUN_0057b9f0(undefined4 *param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686e80;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005782b0(param_1,"Barrel");
  iVar2 = param_1[7];
  local_4 = 0;
  *param_1 = &PTR_FUN_006ba3e0;
  iVar3 = FUN_00567160();
  local_4 = CONCAT31(local_4._1_3_,1);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    pcVar6 = "SMOKEBOMB";
    iVar3 = -1;
    uVar5 = 0x53;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar1 != 0);
    uVar4 = FUN_00591b80(iVar3,0);
  }
  iVar3 = DAT_007361f8;
  param_1[0xc] = uVar4;
  iVar3 = *(int *)(iVar3 + 0x28);
  *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(iVar3 + 0x60);
  *(undefined4 *)(iVar2 + 0x84) = *(undefined4 *)(iVar3 + 100);
  *(undefined4 *)(iVar2 + 0x88) = *(undefined4 *)(iVar3 + 0x68);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x57bab0 FUN_0057bab0

void * __thiscall FUN_0057bab0(void *param_1,byte param_2)

{
  FUN_0057bad0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bad0 FUN_0057bad0

void __fastcall FUN_0057bad0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba3e0;
  FUN_00578370();
  return;
}


// ==== 0x57bae0 FUN_0057bae0

void * __thiscall FUN_0057bae0(void *param_1,byte param_2)

{
  FUN_0057bb00();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bb00 FUN_0057bb00

void __fastcall FUN_0057bb00(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba3b4;
  FUN_00578370();
  return;
}


// ==== 0x57bb10 FUN_0057bb10

undefined4 * FUN_0057bb10(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  
  FUN_00578060(param_1,in_EAX,0);
  *param_1 = &PTR_FUN_006ba388;
  puVar1 = param_1 + 0x24;
  *puVar1 = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  iVar2 = *(int *)(param_1[0xc] + 8);
  iVar3 = *(int *)(param_1[0xc] + 0xc);
  if (iVar2 != 0) {
    iVar8 = *(int *)(iVar2 + 0xc);
    if ((iVar8 != 0) && (iVar4 = FUN_00567c70(), **(int **)(iVar8 + 0x2c) == iVar4)) {
      uVar5 = DAT_006f227c ^ 0x1d872b41;
      uVar6 = uVar5 >> 5 ^ uVar5;
      uVar9 = DAT_006f227c & 1;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar5;
      if (uVar9 != 0) {
        uVar7 = FUN_00567c70();
        *puVar1 = uVar7;
        iVar8 = FUN_00567c70();
        if (iVar8 != param_1[0x25]) {
          param_1[0x25] = iVar8;
          param_1[0x26] = 0xffffffff;
        }
        *(undefined4 **)(iVar2 + 0x10) = puVar1;
        *(undefined4 *)(iVar2 + 0x14) = 1;
        if (((iVar3 != 0) && (iVar8 = *(int *)(iVar3 + 0xc), iVar8 != 0)) &&
           (iVar4 = FUN_00567c70(), **(int **)(iVar8 + 0x2c) == iVar4)) {
          *(undefined4 **)(iVar3 + 0x10) = puVar1;
          *(undefined4 *)(iVar3 + 0x14) = 1;
        }
      }
    }
    uVar5 = DAT_006f227c;
    iVar8 = *(int *)(iVar2 + 0xc);
    if ((iVar8 != 0) && (iVar4 = FUN_00567c70(), **(int **)(iVar8 + 0x2c) == iVar4)) {
      uVar9 = uVar5 ^ 0x1d872b41;
      uVar6 = uVar9 >> 5 ^ uVar9;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar9;
      if ((uVar5 & 1) != 0) {
        uVar7 = FUN_00567c70();
        *puVar1 = uVar7;
        iVar8 = FUN_00567c70();
        if (iVar8 != param_1[0x25]) {
          param_1[0x25] = iVar8;
          param_1[0x26] = 0xffffffff;
        }
        *(undefined4 **)(iVar2 + 0x10) = puVar1;
        *(undefined4 *)(iVar2 + 0x14) = 1;
        if (((iVar3 != 0) && (iVar2 = *(int *)(iVar3 + 0xc), iVar2 != 0)) &&
           (iVar8 = FUN_00567c70(), **(int **)(iVar2 + 0x2c) == iVar8)) {
          *(undefined4 **)(iVar3 + 0x10) = puVar1;
          *(undefined4 *)(iVar3 + 0x14) = 1;
        }
      }
    }
  }
  *(undefined4 *)(param_1[0xc] + 0x14) = 0;
  return param_1;
}


// ==== 0x57bcc0 FUN_0057bcc0

void * __thiscall FUN_0057bcc0(void *param_1,byte param_2)

{
  FUN_0057bce0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bce0 FUN_0057bce0

void __fastcall FUN_0057bce0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba388;
  FUN_00578370();
  return;
}


// ==== 0x57bcf0 FUN_0057bcf0

undefined4 * FUN_0057bcf0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00578060(param_1,param_2,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_006ba4e8;
  if (param_1[8] != 0) {
    iVar1 = FUN_00647b70();
    if (iVar1 == 4) {
      *(undefined1 *)(param_1[8] + 0x71) = 1;
      ExceptionList = local_c;
      return param_1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x57bd70 FUN_0057bd70

void * __thiscall FUN_0057bd70(void *param_1,byte param_2)

{
  FUN_0057bd90();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bd90 FUN_0057bd90

void __fastcall FUN_0057bd90(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba4e8;
  FUN_00578370();
  return;
}


// ==== 0x57bda0 FUN_0057bda0

void * __thiscall FUN_0057bda0(void *param_1,byte param_2)

{
  FUN_0057bdc0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bdc0 FUN_0057bdc0

void __fastcall FUN_0057bdc0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba4bc;
  FUN_00578370();
  return;
}


// ==== 0x57bdd0 FUN_0057bdd0

undefined4 * FUN_0057bdd0(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined1 local_40 [28];
  int local_24;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00686e5b;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FUN_00578060(param_1,param_2,0);
  *param_1 = &PTR_FUN_006ba438;
  local_14 = 0;
  if (*(int *)(param_1[8] + 0x14) != 0) {
    *(float *)(*(int *)(param_1[8] + 0x14) + 100) = (float)DAT_007345ac * 6.0;
  }
  DAT_007345ac = DAT_007345ac + 1;
  param_1[0x24] = 0;
  pcVar4 = "XO_Train_EngineA_1b_3001";
  iVar5 = -1;
  uVar3 = 0x58;
  do {
    iVar5 = iVar5 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  if (iVar5 != 0) {
    FUN_00577d10(0x24cebc53);
    local_24 = FUN_00577d50();
    if (local_24 != 0) {
      iVar5 = *(int *)(local_24 + 0x20);
      iVar2 = *(int *)(iVar5 + 0x14);
      if (iVar2 != 0) {
        *(float *)(iVar2 + 100) = (float)DAT_007345ac * 6.0;
      }
      FUN_0057a070(iVar5,0x42500000);
      TrackPath__UpdateCursor(&DAT_007372b0,local_40);
      param_1[0x24] = 0;
      *(undefined4 **)(local_24 + 0x98 + *(int *)(local_24 + 0x90) * 4) = param_1;
      *(int *)(local_24 + 0x90) = *(int *)(local_24 + 0x90) + 1;
    }
  }
  *(undefined4 *)(param_1[0xc] + 0x18) = 1;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x57bf50 FUN_0057bf50

void * __thiscall FUN_0057bf50(void *param_1,byte param_2)

{
  FUN_0057bf70();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57bf70 FUN_0057bf70

void __fastcall FUN_0057bf70(undefined4 *param_1)

{
  DAT_007345ac = DAT_007345ac + -1;
  *param_1 = &PTR_FUN_006ba438;
  FUN_00578370();
  return;
}


// ==== 0x57bf90 FUN_0057bf90

undefined4 * FUN_0057bf90(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  undefined8 uVar9;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00578060(param_1,param_2,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_006ba40c;
  param_1[0x25] = 0;
  pcVar7 = "TrainCar";
  iVar8 = -1;
  uVar3 = 0x54;
  do {
    pbVar1 = (byte *)(pcVar7 + 1);
    iVar8 = iVar8 * 0x21 + uVar3;
    pcVar7 = pcVar7 + 1;
    uVar3 = (uint)*pbVar1;
  } while (*pbVar1 != 0);
  param_1[0x24] = 0;
  iVar4 = FUN_00577d10(iVar8);
  if (iVar4 != 0) {
    iVar2 = *(int *)(iVar4 + 0x2c);
    if (iVar2 == iVar4 + 0x2c) {
      puVar6 = (undefined *)FUN_00577e60(0);
    }
    else if (iVar2 == 0) {
      puVar6 = (undefined *)0x0;
    }
    else {
      puVar6 = (undefined *)(iVar2 + -4);
    }
    while (puVar6 != (undefined *)0x0) {
      param_1[param_1[0x24] + 0x26] = puVar6;
      param_1[0x24] = param_1[0x24] + 1;
      if (iVar8 == DAT_0073b128) {
        puVar5 = &DAT_0073b118;
      }
      else {
        if ((undefined4 **)DAT_0073b138 == &DAT_0073b138) break;
        while( true ) {
          uVar9 = FUN_00577d10(iVar8);
          puVar5 = (undefined *)uVar9;
          if (puVar5 != (undefined *)0x0) break;
          if ((undefined4 **)*(undefined4 *)((ulonglong)uVar9 >> 0x20) == &DAT_0073b138)
          goto LAB_0057c09f;
        }
      }
      puVar6 = *(undefined **)(puVar5 + 0x2c);
      if (puVar6 == puVar5 + 0x2c) {
        puVar6 = (undefined *)FUN_00577e60(0);
      }
      else if (puVar6 == (undefined *)0x0) {
        puVar6 = (undefined *)0x0;
      }
      else {
        puVar6 = puVar6 + -4;
      }
    }
  }
LAB_0057c09f:
  if (*(int *)(param_1[8] + 0x14) != 0) {
    *(float *)(*(int *)(param_1[8] + 0x14) + 100) = (float)(int)param_1[0x24] * 6.0;
  }
  *(undefined4 *)(param_1[0xc] + 0x18) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x57c0e0 FUN_0057c0e0

void * __thiscall FUN_0057c0e0(void *param_1,byte param_2)

{
  FUN_0057c100();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57c100 FUN_0057c100

void __fastcall FUN_0057c100(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba40c;
  FUN_00578370();
  return;
}


// ==== 0x57c110 FUN_0057c110

void FUN_0057c110(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  
  puVar11 = (undefined *)0x0;
  pcVar6 = "TrainCar";
  iVar9 = -1;
  uVar5 = 0x54;
  do {
    iVar9 = iVar9 * 0x21 + uVar5;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar5 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  do {
    if (iVar9 == DAT_0073b128) {
      puVar10 = &DAT_0073b118;
    }
    else {
      if ((undefined4 **)DAT_0073b138 == &DAT_0073b138) {
LAB_0057c166:
        if (param_1 != 0) {
          puVar2 = (uint *)(*(int *)(*(int *)(param_1 + 0x20) + 0x14) + 0x34);
          *puVar2 = *puVar2 & 0xffffff7f;
        }
        return;
      }
      while( true ) {
        uVar12 = FUN_00577d10(iVar9);
        puVar10 = (undefined *)uVar12;
        if (puVar10 != (undefined *)0x0) break;
        if ((undefined4 **)*(undefined4 *)((ulonglong)uVar12 >> 0x20) == &DAT_0073b138)
        goto LAB_0057c166;
      }
    }
    if (puVar11 == (undefined *)0x0) {
      puVar11 = *(undefined **)(puVar10 + 0x2c);
      if (puVar11 == puVar10 + 0x2c) {
        for (puVar8 = *(undefined4 **)(puVar10 + 0x20); puVar8 != (undefined4 *)(puVar10 + 0x20);
            puVar8 = (undefined4 *)*puVar8) {
          puVar11 = (undefined *)FUN_00577eb0();
          if (puVar11 != (undefined *)0x0) goto LAB_0057c225;
        }
LAB_0057c221:
        puVar11 = (undefined *)0x0;
      }
      else if (puVar11 == (undefined *)0x0) {
        puVar11 = (undefined *)0x0;
      }
      else {
        puVar11 = puVar11 + -4;
      }
    }
    else {
      puVar3 = *(undefined **)(puVar11 + 0x18);
      if (*(int *)(puVar11 + 4) == 0) {
        puVar11 = (undefined *)0x0;
      }
      else {
        puVar11 = (undefined *)(*(int *)(puVar11 + 4) + -4);
      }
      if (puVar3 == (undefined *)0xffffffd4) {
        puVar7 = (undefined *)0x0;
      }
      else {
        puVar7 = puVar3 + 0x28;
      }
      if (puVar11 == puVar7) {
        for (puVar8 = *(undefined4 **)(puVar3 + 0x20); puVar8 != (undefined4 *)(puVar3 + 0x20);
            puVar8 = (undefined4 *)*puVar8) {
          puVar4 = (undefined4 *)puVar8[0xb];
          if (puVar4 == puVar8 + 0xb) {
            uVar12 = FUN_00577e60(0);
LAB_0057c1d3:
            puVar8 = (undefined4 *)((ulonglong)uVar12 >> 0x20);
            puVar11 = (undefined *)uVar12;
            if (puVar11 != (undefined *)0x0) goto LAB_0057c225;
          }
          else if (puVar4 != (undefined4 *)0x0) {
            uVar12 = CONCAT44(puVar8,puVar4 + -1);
            goto LAB_0057c1d3;
          }
        }
        if (puVar3 == puVar10) goto LAB_0057c221;
        puVar11 = (undefined *)FUN_00577ed0();
      }
    }
LAB_0057c225:
    if (puVar11 == (undefined *)0x0) goto LAB_0057c166;
    puVar2 = (uint *)(*(int *)(*(int *)(puVar11 + 0x20) + 0x14) + 0x34);
    *puVar2 = *puVar2 & 0xffffff7f;
  } while( true );
}


// ==== 0x57c240 FUN_0057c240

undefined4 * FUN_0057c240(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00578060(param_1,param_2,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_006ba464;
  FUN_005796b0(param_1 + 7,7,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x57c2a0 FUN_0057c2a0

void __fastcall FUN_0057c2a0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006ba644;
  in_EAX[4] = param_1;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
  *in_EAX = &PTR_FUN_006ba380;
  in_EAX[3] = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x84);
  uVar2 = *(undefined4 *)(param_1 + 0x88);
  in_EAX[8] = *(undefined4 *)(param_1 + 0x80);
  in_EAX[9] = uVar1;
  in_EAX[10] = uVar2;
  in_EAX[0xc] = 0;
  return;
}


// ==== 0x57c2e0 FUN_0057c2e0

void * __thiscall FUN_0057c2e0(void *param_1,byte param_2)

{
  FUN_0057c300();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x57c300 FUN_0057c300

void __fastcall FUN_0057c300(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006ba380;
  FUN_00578c70();
  return;
}


// ==== 0x57c310 FUN_0057c310

void __fastcall FUN_0057c310(int param_1)

{
  if (6.28318 < *(float *)(param_1 + 0x30)) {
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x30) - 6.28318;
  }
  if (*(float *)(param_1 + 0x30) < -6.28318) {
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x30) + 6.28318;
  }
  return;
}


// ==== 0x57c350 FUN_0057c350

void FUN_0057c350(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar2 = unaff_EDI[4] - *unaff_EDI;
  if (iVar2 < 0x4001) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    iVar2 = 0x4000;
  }
  iVar1 = bOpenFile(unaff_EDI + 9,1,1);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = *unaff_EDI;
  }
  FUN_00594dd0(iVar2);
  FUN_00594d40();
  unaff_EDI[3] = *unaff_EDI;
  unaff_EDI[2] = *unaff_EDI + iVar2;
  return;
}


// ==== 0x57c3b0 FUN_0057c3b0

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


// ==== 0x57c480 FUN_0057c480

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


// ==== 0x57c4f0 FUN_0057c4f0

int __thiscall FUN_0057c4f0(uint *param_1,int param_2)

{
  uint uVar1;
  int in_EAX;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  pbVar2 = (byte *)((param_2 - *(int *)(in_EAX + 0xc)) + 100 + in_EAX);
  param_1[1] = (uint)(*pbVar2 >> 4);
  uVar1 = param_1[1];
  *param_1 = *pbVar2 & 0xf;
  uVar3 = 0;
  if (0 < (int)uVar1) {
    pbVar2 = pbVar2 + uVar1;
    uVar4 = uVar1;
    do {
      uVar3 = uVar3 << 8 | (uint)*pbVar2;
      pbVar2 = pbVar2 + -1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  param_1[2] = uVar3;
  return uVar1 + 1 + param_2;
}


// ==== 0x57c540 FUN_0057c540

void __fastcall FUN_0057c540(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[3];
  if (iVar1 < param_2[4]) {
    iVar2 = iVar1;
    while (iVar2 < *param_2 + 0x20) {
      if ((param_2[2] != 0) && (param_2[2] <= iVar2)) {
        return;
      }
      iVar2 = iVar2 + 1 + (uint)(*(byte *)((iVar2 - iVar1) + 100 + (int)param_2) >> 4);
      if (param_2[4] <= iVar2) {
        return;
      }
    }
  }
  return;
}


// ==== 0x57c580 FUN_0057c580

void FUN_0057c580(void)

{
  if (DAT_0073459c != 0) {
    DAT_007345a4 = 0;
    DAT_0073459c = 0;
  }
  return;
}


// ==== 0x57c5a0 FUN_0057c5a0

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


// ==== 0x57c5f0 FUN_0057c5f0

void FUN_0057c5f0(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0073459c != 0) {
    iVar2 = FUN_0057c5a0(param_2);
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (DAT_0073459c == 0) {
          cVar1 = '\0';
        }
        else {
          cVar1 = FUN_0057c480(8,param_2);
          if ((DAT_007345a4[4] <= *DAT_007345a4) && (DAT_0073459c != 0)) {
            DAT_007345a4 = (int *)0x0;
            DAT_0073459c = 0;
          }
        }
        param_1[iVar3] = cVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    param_1[iVar3] = '\0';
  }
  if (DAT_007345a0 != 0) {
    iVar2 = 0;
    if (param_1 != (char *)0x0) {
      cVar1 = *param_1;
      while (cVar1 != '\0') {
        iVar3 = iVar2 + 1;
        iVar2 = iVar2 + 1;
        cVar1 = param_1[iVar3];
      }
    }
    FUN_0057c3b0(iVar2,0x10,param_2);
    if (0 < iVar2) {
      iVar3 = 0;
      do {
        if (DAT_007345a0 != 0) {
          FUN_0057c3b0((int)param_1[iVar3],8,param_2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
  }
  return;
}


// ==== 0x57c6d0 FUN_0057c6d0

void FUN_0057c6d0(void)

{
  char cVar1;
  char *pcVar2;
  char local_200;
  char local_1ff [511];
  
  pcVar2 = &local_200;
  NullUpdate_ret();
  local_200 = *PTR_s_Change_Unknown_by_Unknown_006f21a8;
  if (*PTR_s_Change_Unknown_by_Unknown_006f21a8 != '\0') {
    do {
      cVar1 = pcVar2[(int)(PTR_s_Change_Unknown_by_Unknown_006f21a8 + (1 - (int)&local_200))];
      pcVar2 = pcVar2 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  FUN_0057c5f0(&local_200,1);
  if (DAT_0073459c != 0) {
    FUN_005687b0();
  }
  FUN_00568f70();
  return;
}


// ==== 0x57c730 FUN_0057c730

void FUN_0057c730(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  *(int *)in_EAX = in_EAX;
  *(int *)(in_EAX + 4) = in_EAX;
  puVar1 = (undefined4 *)(in_EAX + 0x14);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x2c);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x44);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x5c);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x74);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x8c);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0xa4);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0xbc);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0xd4);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0xec);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x104);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(in_EAX + 0x11c);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x57c850 FUN_0057c850

undefined4 FUN_0057c850(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    return 0;
  case 1:
  case 3:
  case 6:
  case 8:
  case 10:
  case 0xd:
    return 1;
  case 0xf:
    return 4;
  case 0x10:
  case 0x12:
    return 3;
  case 0x11:
    return 2;
  }
}


// ==== 0x57c8b0 CarData_Load

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 CarData_Load(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *extraout_ECX;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined8 uVar9;
  int iStack_c;
  uint uStack_4;
  
  iVar6 = *param_1;
  if (iVar6 == 0x34600) {
    uVar8 = (int)param_1 + 0x17U & 0xfffffff0;
    iVar6 = 0;
    DAT_00734588 = uVar8;
    do {
      if (*(int *)(iVar6 * 0xc90 + 0xc54 + uVar8) == 0) {
        FUN_00581d30();
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x23);
    return 1;
  }
  if (iVar6 == 0x34601) {
    DAT_00734590 = param_1 + 2;
    DAT_00734594 = (uint)param_1[1] >> 6;
    return 1;
  }
  if (iVar6 != -0x7ffcb9fe) {
    return 0;
  }
  iVar6 = param_1[3];
  iVar2 = *(int *)(iVar6 + 0x14 + (int)param_1);
  iVar3 = *(int *)((int)param_1 + iVar2 + 0xc + iVar6 + 0x10);
  iVar2 = iVar2 + 8 + iVar6 + 0x10;
  piVar1 = param_1 + 4;
  _DAT_00734584 = (int)param_1 + iVar6 + 0x18;
  param_1[9] = (int)param_1 + iVar2 + 8;
  param_1[0xb] = _DAT_00734584;
  *piVar1 = (int)piVar1;
  param_1[5] = (int)piVar1;
  param_1[7] = (int)param_1 + iVar3 + iVar2 + 0x10;
  uStack_4 = 0;
  if (param_1[8] != 0) {
    iStack_c = 0;
    do {
      piVar4 = (int *)(param_1[7] + iStack_c);
      *piVar4 = *(int *)(param_1[7] + iStack_c) + param_1[0xb];
      if ((short)piVar4[7] != 0) {
        piVar4[5] = param_1[9] + piVar4[5] * 8;
      }
      if (*(short *)((int)piVar4 + 0x1e) != 0) {
        piVar4[6] = param_1[9] + piVar4[6] * 8;
      }
      uVar8 = piVar4[3];
      piVar7 = (int *)0x0;
      iVar6 = *(byte *)((int)piVar4 + 0x11) - 1;
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      else if (2 < iVar6) {
        iVar6 = 2;
      }
      piVar5 = (int *)0x0;
      if ((char)piVar4[4] == '\x1e') {
        if (uVar8 < 0x3797534) {
          if (uVar8 == 0x3797533) {
            piVar7 = &DAT_0073ad84 + iVar6 * 2;
          }
          else if (uVar8 == 0xda27) {
            piVar7 = &DAT_0073adb4 + iVar6 * 2;
          }
          else if (uVar8 == 0x2daab07) {
            piVar7 = &DAT_0073ad54 + iVar6 * 2;
          }
          else {
            if (uVar8 != 0x3437a52) goto LAB_0057cad7;
            piVar7 = &DAT_0073ad6c + iVar6 * 2;
          }
        }
        else if (uVar8 == 0x3e871f1) {
          piVar7 = &DAT_0073ad9c + iVar6 * 2;
        }
        else if (uVar8 == 0x66350f0) {
          piVar7 = &DAT_0073ade4 + iVar6 * 2;
        }
        else {
          if (uVar8 != 0xd6640dff) goto LAB_0057cad7;
          piVar7 = &DAT_0073adcc + iVar6 * 2;
        }
LAB_0057cab9:
        if (piVar7 != (int *)0x0) {
          if (*piVar7 == 0) {
            *piVar7 = (int)piVar4;
          }
          piVar7[1] = piVar7[1] + 1;
        }
        if (piVar5 != (int *)0x0) {
          if (*piVar5 == 0) {
            *piVar5 = (int)piVar4;
          }
          piVar5[1] = piVar5[1] + 1;
        }
      }
      else if ((char)piVar4[4] == '\x1f') {
        uVar9 = FUN_0057c850();
        iVar6 = (int)((ulonglong)uVar9 >> 0x20);
        switch((int)uVar9) {
        case 0:
          piVar7 = (int *)(&DAT_0073ae44 + iVar6 * 8);
          break;
        case 1:
          piVar7 = (int *)(&DAT_0073ae2c + iVar6 * 8);
          break;
        case 2:
          piVar7 = (int *)(&DAT_0073ae14 + iVar6 * 8);
          break;
        case 3:
          piVar7 = &DAT_0073ae5c + iVar6 * 2;
        }
        piVar5 = (int *)(&DAT_0073adfc + iVar6 * 8);
        piVar4 = extraout_ECX;
        goto LAB_0057cab9;
      }
LAB_0057cad7:
      uStack_4 = uStack_4 + 1;
      iStack_c = iStack_c + 0x30;
    } while (uStack_4 < (uint)param_1[8]);
  }
  *DAT_0073ad44 = (int)piVar1;
  piVar4 = piVar1;
  param_1[5] = (int)DAT_0073ad44;
  DAT_0073ad44 = piVar4;
  *piVar1 = (int)&DAT_0073ad40;
  DAT_0073ad48 = DAT_0073ad48 + 1;
  DAT_0073ad4c = DAT_0073ad4c + param_1[8];
  DAT_0073ad50 = DAT_0073ad50 + param_1[1];
  return 1;
}


// ==== 0x57cb70 CarData_Unload

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 CarData_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0x34600) {
    DAT_00734588 = 0;
    return 1;
  }
  if (iVar1 == 0x34601) {
    DAT_00734590 = 0;
    DAT_00734594 = 0;
    return 1;
  }
  if (iVar1 == -0x7ffcb9fe) {
    iVar1 = param_1[4];
    piVar2 = (int *)param_1[5];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    DAT_0073ad48 = DAT_0073ad48 + -1;
    DAT_0073ad4c = DAT_0073ad4c - param_1[8];
    DAT_0073ad50 = DAT_0073ad50 - param_1[1];
    return 1;
  }
  return 0;
}


// ==== 0x57cbf0 FUN_0057cbf0

bool __fastcall FUN_0057cbf0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  piVar1 = piVar2 + *(short *)(param_1 + 0x1c) * 2;
  if (piVar2 == (int *)0x0) {
    return false;
  }
  for (; piVar2 < piVar1; piVar2 = piVar2 + 2) {
    if ((param_2 == 0) || (*piVar2 == param_2)) goto LAB_0057cc21;
  }
  piVar2 = (int *)0x0;
LAB_0057cc21:
  return piVar2 != (int *)0x0;
}


// ==== 0x57cc30 FUN_0057cc30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0057cc30(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  piVar1 = piVar2 + *(short *)(param_1 + 0x1c) * 2;
  if (piVar2 != (int *)0x0) {
    for (; piVar2 < piVar1; piVar2 = piVar2 + 2) {
      if ((param_2 == 0) || (*piVar2 == param_2)) {
        if (piVar2 == (int *)0x0) {
          return param_3;
        }
        return piVar2[1] + _DAT_00734584;
      }
    }
  }
  return param_3;
}


// ==== 0x57cc70 FUN_0057cc70

int __fastcall FUN_0057cc70(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  piVar1 = piVar2 + *(short *)(param_1 + 0x1c) * 2;
  if (piVar2 != (int *)0x0) {
    for (; piVar2 < piVar1; piVar2 = piVar2 + 2) {
      if ((param_2 == 0) || (*piVar2 == param_2)) {
        if (piVar2 == (int *)0x0) {
          return param_3;
        }
        return piVar2[1];
      }
    }
  }
  return param_3;
}


// ==== 0x57ccb0 FUN_0057ccb0

int FUN_0057ccb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)*in_EAX;
  iVar5 = -1;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return -1;
    }
    uVar3 = puVar1[3];
    uVar4 = puVar1[4] * 0x30 + uVar3;
    for (; uVar3 < uVar4; uVar3 = uVar3 + 0x30) {
      iVar5 = iVar5 + 1;
      if ((((unaff_EDI == 0) || (*(int *)(uVar3 + 4) == unaff_EDI)) &&
          ((param_1 == -1 || (*(char *)(uVar3 + 0x10) == param_1)))) &&
         ((param_2 == 0 || (*(int *)(uVar3 + 8) == param_2)))) {
        return iVar5;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x57cd30 FUN_0057cd30

uint __fastcall FUN_0057cd30(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((-1 < param_1) && (param_1 < (int)in_EAX[3])) {
    puVar1 = (undefined4 *)*in_EAX;
    puVar2 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
      uVar3 = puVar1[3];
      uVar4 = puVar1[4] * 0x30 + uVar3;
      for (; uVar3 < uVar4; uVar3 = uVar3 + 0x30) {
        param_1 = param_1 + -1;
        if (param_1 < 0) {
          return uVar3;
        }
      }
    }
  }
  return 0;
}


// ==== 0x57cd80 FUN_0057cd80

undefined4 FUN_0057cd80(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_ESI;
  
  uVar1 = param_2;
  uVar2 = FUN_0057cf20(param_1,param_2,unaff_ESI,0);
  if (uVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar2 = DAT_006f227c % uVar2;
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar3 = uVar5 >> 5 ^ uVar5;
    DAT_006f227c = uVar3 << 0x1b ^ uVar3 ^ uVar5;
    uVar4 = CarPartDatabase__GetCarPart(param_2,unaff_ESI,0,0,in_EAX);
    param_2 = uVar2;
    if (0 < (int)uVar2) {
      do {
        uVar4 = CarPartDatabase__GetCarPart(uVar1,unaff_ESI,0,uVar4,in_EAX);
        param_2 = param_2 - 1;
      } while (param_2 != 0);
      return uVar4;
    }
  }
  return uVar4;
}


// ==== 0x57ce10 CarPartDatabase::GetCarPart

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

uint CarPartDatabase__GetCarPart(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (undefined4 *)*in_EAX;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return 0;
    }
    uVar3 = puVar1[3];
    uVar4 = puVar1[4] * 0x30 + uVar3;
    if (param_4 == 0) {
      if ((param_1 != 0) && (uVar3 = BinarySearch_Hash(param_1,uVar3,4), uVar3 == 0)) {
        return 0;
      }
joined_r0x0057ce74:
      for (; uVar3 < uVar4; uVar3 = uVar3 + 0x30) {
        if ((param_1 != 0) && (*(int *)(uVar3 + 4) != param_1)) {
          return 0;
        }
        if (((param_2 == -1) || (*(char *)(uVar3 + 0x10) == param_2)) &&
           ((param_3 == 0 || (*(int *)(uVar3 + 8) == param_3)))) {
          if (param_5 == 0xffffffff) {
            return uVar3;
          }
          if (*(byte *)(uVar3 + 0x11) == param_5) {
            return uVar3;
          }
        }
      }
    }
    else if ((uVar3 <= param_4) && (param_4 < uVar4)) {
      uVar3 = param_4 + 0x30;
      goto joined_r0x0057ce74;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x57ced0 FUN_0057ced0

undefined4 __thiscall
FUN_0057ced0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0x23) {
    if (param_1 * 0xc90 + DAT_00734588 == 0) {
      return 0;
    }
    uVar1 = FUN_00567c70();
  }
  uVar1 = CarPartDatabase__GetCarPart(uVar1,param_3,param_4,param_5,param_6);
  return uVar1;
}


// ==== 0x57cf20 FUN_0057cf20

int FUN_0057cf20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EDI;
  
  iVar2 = 0;
  for (iVar1 = CarPartDatabase__GetCarPart(param_2,param_3,param_4,0,unaff_EDI); iVar1 != 0;
      iVar1 = CarPartDatabase__GetCarPart(param_2,param_3,param_4,iVar1,unaff_EDI)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ==== 0x57cf70 GetCarTypeInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int __fastcall GetCarTypeInfo(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(DAT_00734588 + 0xd0);
  do {
    if (*piVar2 == param_2) {
      return iVar1 * 0xc90 + DAT_00734588;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x324;
  } while (iVar1 < 0x23);
  return 0;
}


// ==== 0x57cfa0 CarTypeInfo_NextOfUsage

/* [canon] traffic high (H+G) docs/re/traffic.md */

int __fastcall CarTypeInfo_NextOfUsage(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (param_2[2] < 0x23) {
    do {
      iVar1 = param_2[2] * 0xc90 + DAT_00734588;
      param_2[2] = param_2[2] + 1;
      if (((*(int *)(iVar1 + 0xc54) == *param_2) && (*(char *)(iVar1 + 0x40) != '\0')) &&
         (param_2[1] == -1)) {
        if (*(int *)(iVar1 + 0xc54) == 1) {
          return iVar1;
        }
        if ('\0' < *(char *)(iVar1 + 0xd9)) {
          return iVar1;
        }
      }
    } while (param_2[2] < 0x23);
  }
  return 0;
}


// ==== 0x57d000 TrafficCar_PickType

/* [canon] traffic high (H+G+C+file) docs/re/traffic.md */

undefined4 TrafficCar_PickType(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_10;
  
  local_10 = 0.0;
  if (DAT_0078a2f0 < 1000) {
    iVar3 = 4;
    if (DAT_0078a2f0 / 10 != 6) {
      iVar3 = DAT_0078a2f0 / 10 + -1;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar2 = CarTypeInfo_NextOfUsage();
  while (iVar2 != 0) {
    local_10 = *(float *)(iVar2 + 0xc60 + iVar3 * 4) + local_10;
    iVar2 = CarTypeInfo_NextOfUsage();
  }
  if (ABS(local_10) < 0.001 == (ABS(local_10) == 0.001)) {
    fVar4 = (float10)FUN_00564a80(local_10);
    fVar1 = (float)fVar4;
    iVar2 = CarTypeInfo_NextOfUsage();
    while( true ) {
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      fVar1 = fVar1 - *(float *)(iVar2 + 0xc60 + iVar3 * 4);
      if (fVar1 < 0.0 != (fVar1 == 0.0)) break;
      iVar2 = CarTypeInfo_NextOfUsage();
    }
    return *(undefined4 *)(iVar2 + 0xc50);
  }
  return 0xffffffff;
}


// ==== 0x57d100 FUN_0057d100

int FUN_0057d100(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xc54) == 1) {
    return 1;
  }
  return (int)*(char *)(in_EAX + 0xd9);
}


// ==== 0x57d120 FUN_0057d120

int __thiscall FUN_0057d120(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc54) == 1) {
    return (DAT_006ee6f0 != 0) + 1;
  }
  return (int)*(char *)(param_2 % (int)*(char *)(param_1 + 0xd9) + 0xc80 + param_1);
}


// ==== 0x57d160 Ride_Init

/* [canon] traffic med (G) docs/re/traffic.md */

void __fastcall
Ride_Init(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined1 param_4,
         undefined1 param_5)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  *param_2 = in_EAX;
  *(undefined1 *)((int)param_2 + 5) = param_4;
  *(undefined1 *)((int)param_2 + 6) = param_5;
  *(undefined1 *)(param_2 + 1) = 0;
  param_2[0x111] = 0;
  *(undefined1 *)((int)param_2 + 7) = 1;
  *(undefined1 *)((int)param_2 + 0x425) = 0xff;
  puVar2 = param_2 + 0x113;
  for (iVar1 = 0x78; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_2 + 0x18b;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_2 + 0x1a9;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0x1010101;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_2 + 2;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_2[0x10a] = 0;
  param_2[0x10d] = 0;
  param_2[0x10c] = 0;
  param_2[0x110] = 0;
  param_2[0x10f] = 0;
  param_2[0x10e] = 0;
  param_2[0x1c7] = 0;
  *(undefined1 *)(param_2 + 0x109) = 0xff;
  return;
}


// ==== 0x57d200 FUN_0057d200

void FUN_0057d200(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"RideInfo");
  FUN_00571c20(unaff_ESI,in_EAX,1,4,1);
  FUN_00571c20(unaff_ESI,in_EAX + 7,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 5,1,1,1);
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


// ==== 0x57d280 FUN_0057d280

void FUN_0057d280(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = FindPartWithLevel(param_2);
  piVar5 = DAT_0073ad40;
  if (uVar3 == 0) {
    if ((param_2 == 0x12) && (piVar4 = (int *)NullUpdate_ret(), piVar5 != piVar4)) {
      while( true ) {
        iVar1 = piVar5[4];
        iVar2 = piVar5[3];
        uVar3 = BinarySearch_Hash(0x7326cf08,iVar2,4);
        if (uVar3 == 0) break;
        for (; uVar3 < (uint)(iVar1 * 0x30 + iVar2); uVar3 = uVar3 + 0x30) {
          if (*(int *)(uVar3 + 4) != 0x7326cf08) {
            return;
          }
          if (*(char *)(uVar3 + 0x10) == '\x12') goto LAB_0057d31b;
        }
        piVar5 = (int *)*piVar5;
        if (piVar5 == piVar4) {
          return;
        }
      }
    }
  }
  else {
LAB_0057d31b:
    *(uint *)(param_1 + 0x44c + param_2 * 4) = uVar3;
    *(char *)(param_2 + 0x62c + param_1) = *(char *)(param_2 + 0x62c + param_1) + '\x01';
    RideInfo__UpdatePartsEnabled(param_1);
  }
  return;
}


// ==== 0x57d340 FUN_0057d340

void FUN_0057d340(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar4 = param_1;
  local_10 = 0;
  do {
    piVar14 = DAT_0073ad40;
    if ((((local_10 < 0x1f) || (0x22 < local_10)) && (local_10 != 6)) && (local_10 != 0xc)) {
      if (local_10 == 0x10) {
        pcVar8 = "BRAKES";
        iVar13 = -1;
        uVar6 = 0x42;
        do {
          iVar13 = iVar13 * 0x21 + uVar6;
          pbVar11 = (byte *)(pcVar8 + 1);
          uVar6 = (uint)*pbVar11;
          pcVar8 = pcVar8 + 1;
        } while (*pbVar11 != 0);
        piVar5 = (int *)NullUpdate_ret();
        if (piVar14 != piVar5) {
          while( true ) {
            uVar6 = piVar14[3];
            uVar12 = piVar14[4] * 0x30 + uVar6;
            if ((iVar13 != 0) && (uVar6 = BinarySearch_Hash(iVar13,uVar6,4), uVar6 == 0)) break;
            for (; uVar6 < uVar12; uVar6 = uVar6 + 0x30) {
              if ((iVar13 != 0) && (*(int *)(uVar6 + 4) != iVar13)) goto LAB_0057d415;
              if (*(char *)(uVar6 + 0x10) == '\x10') goto LAB_0057d417;
            }
            piVar14 = (int *)*piVar14;
            if (piVar14 == piVar5) break;
          }
        }
LAB_0057d415:
        uVar6 = 0;
LAB_0057d417:
        bVar3 = false;
        while ((uVar6 != 0 && (!bVar3))) {
          if (*(char *)(uVar6 + 0x11) == '\0') {
            bVar3 = true;
          }
          else {
            pcVar8 = "BRAKES";
            iVar13 = -1;
            uVar12 = 0x42;
            do {
              iVar13 = iVar13 * 0x21 + uVar12;
              pbVar11 = (byte *)(pcVar8 + 1);
              uVar12 = (uint)*pbVar11;
              pcVar8 = pcVar8 + 1;
            } while (*pbVar11 != 0);
            uVar6 = CarPartDatabase__GetCarPart(iVar13,0x10,0,uVar6,0xffffffff);
          }
        }
        param_1[0x123] = uVar6;
        *(char *)(param_1 + 399) = (char)param_1[399] + '\x01';
        RideInfo__UpdatePartsEnabled(param_1);
      }
      else {
        FUN_0057d280(param_1,local_10);
      }
    }
    local_10 = local_10 + 1;
  } while (local_10 < 0x78);
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_FRONT_WINDOW_WIDE_MEDIU_006f88ac,
                       *param_1 * 0xc90 + DAT_00734588);
  iVar10 = DAT_00734588;
  iVar13 = *param_1;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d4f0:
    param_1 = (int *)CarPartDatabase__GetCarPart(iVar15,0x14,uVar7,0,0xffffffff);
  }
  else {
    iVar15 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar15 != 0) {
      pbVar11 = (byte *)(iVar15 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d4f0;
    }
    param_1 = (int *)0x0;
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_REAR_WINDOW_WIDE_MEDIUM_006f88b0,iVar13 * 0xc90 + iVar10);
  iVar10 = DAT_00734588;
  iVar13 = *piVar4;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d560:
    local_10 = CarPartDatabase__GetCarPart(iVar15,0x15,uVar7,0,0xffffffff);
  }
  else {
    iVar15 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar15 != 0) {
      pbVar11 = (byte *)(iVar15 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d560;
    }
    local_10 = 0;
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_LEFT_DOOR_RECT_MEDIUM_006f88b4,iVar13 * 0xc90 + iVar10);
  iVar10 = DAT_00734588;
  iVar13 = *piVar4;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d5d0:
    local_c = CarPartDatabase__GetCarPart(iVar15,0x16,uVar7,0,0xffffffff);
  }
  else {
    iVar15 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar15 != 0) {
      pbVar11 = (byte *)(iVar15 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d5d0;
    }
    local_c = 0;
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_RIGHT_DOOR_RECT_MEDIUM_006f88b8,iVar13 * 0xc90 + iVar10);
  iVar10 = DAT_00734588;
  iVar13 = *piVar4;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d640:
    local_8 = CarPartDatabase__GetCarPart(iVar15,0x17,uVar7,0,0xffffffff);
  }
  else {
    iVar15 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar15 != 0) {
      pbVar11 = (byte *)(iVar15 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d640;
    }
    local_8 = 0;
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_LEFT_QUARTER_RECT_MEDIU_006f88bc,iVar13 * 0xc90 + iVar10);
  iVar10 = DAT_00734588;
  iVar13 = *piVar4;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d6b0:
    local_4 = CarPartDatabase__GetCarPart(iVar15,0x18,uVar7,0,0xffffffff);
  }
  else {
    iVar15 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar15 != 0) {
      pbVar11 = (byte *)(iVar15 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d6b0;
    }
    local_4 = 0;
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_RIGHT_QUARTER_RECT_MEDI_006f88c4,iVar13 * 0xc90 + iVar10);
  iVar10 = DAT_00734588;
  iVar13 = *piVar4;
  iVar15 = 0;
  if (iVar13 == 0x23) {
LAB_0057d715:
    iVar15 = CarPartDatabase__GetCarPart(iVar15,0x19,uVar7,0,0xffffffff);
  }
  else {
    iVar9 = iVar13 * 0xc90 + DAT_00734588;
    if (iVar9 != 0) {
      pbVar11 = (byte *)(iVar9 + 0x20);
      iVar15 = -1;
      bVar2 = *pbVar11;
      while (bVar2 != 0) {
        iVar15 = iVar15 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar1;
      }
      goto LAB_0057d715;
    }
  }
  uVar7 = FUN_004f42f0(PTR_s__s_DECAL_HOOD_RECT_MEDIUM_006f88ec,iVar13 * 0xc90 + iVar10);
  iVar13 = 0;
  if (*piVar4 != 0x23) {
    iVar10 = *piVar4 * 0xc90 + DAT_00734588;
    if (iVar10 == 0) goto LAB_0057d78b;
    pbVar11 = (byte *)(iVar10 + 0x20);
    iVar13 = -1;
    bVar2 = *pbVar11;
    while (bVar2 != 0) {
      iVar13 = iVar13 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar11 + 1;
      pbVar11 = pbVar11 + 1;
      bVar2 = *pbVar1;
    }
  }
  iVar13 = CarPartDatabase__GetCarPart(iVar13,0x13,uVar7,0,0xffffffff);
LAB_0057d78b:
  piVar4[0x127] = (int)param_1;
  *(char *)(piVar4 + 400) = (char)piVar4[400] + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[0x128] = local_10;
  *(char *)((int)piVar4 + 0x641) = *(char *)((int)piVar4 + 0x641) + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[0x129] = local_c;
  *(char *)((int)piVar4 + 0x642) = *(char *)((int)piVar4 + 0x642) + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[0x12a] = local_8;
  *(char *)((int)piVar4 + 0x643) = *(char *)((int)piVar4 + 0x643) + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[299] = local_4;
  *(char *)(piVar4 + 0x191) = (char)piVar4[0x191] + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[300] = iVar15;
  *(char *)((int)piVar4 + 0x645) = *(char *)((int)piVar4 + 0x645) + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  piVar4[0x126] = iVar13;
  *(char *)((int)piVar4 + 0x63f) = *(char *)((int)piVar4 + 0x63f) + '\x01';
  RideInfo__UpdatePartsEnabled(piVar4);
  return;
}


// ==== 0x57d860 RideInfo::SyncPartsToPhysicsForAI

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void RideInfo__SyncPartsToPhysicsForAI(int *param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  undefined1 uVar6;
  bool bVar7;
  uint uVar8;
  DWORD *pDVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  LARGE_INTEGER *pLVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  int iVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 *puVar24;
  undefined4 auStackY_f0 [6];
  char *apcStackY_d8 [5];
  int iStackY_c4;
  char *pcStackY_c0;
  int *piStackY_bc;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  uint *local_94;
  int local_90;
  int local_8c;
  char *local_88;
  LARGE_INTEGER local_84 [2];
  uint local_74 [13];
  byte local_40;
  byte local_3f [63];
  
  QueryPerformanceCounter(local_84);
  iVar15 = *param_1 * 0xc90 + DAT_00734588;
  if (iVar15 == 0) {
    return;
  }
  iVar16 = iVar15 + 0x20;
  iVar21 = -1;
  bVar3 = *(byte *)(iVar15 + 0x20);
  while (bVar3 != 0) {
    iVar21 = iVar21 * 0x21 + (uint)bVar3;
    pbVar20 = (byte *)(iVar16 + 1);
    iVar16 = iVar16 + 1;
    bVar3 = *pbVar20;
  }
  piStackY_bc = (int *)param_1[4];
  pcStackY_c0 = (char *)0xc;
  iStackY_c4 = 0x57d8cf;
  iVar16 = FindPartWithLevel();
  if (iVar16 != 0) {
    param_1[0x11f] = iVar16;
    piStackY_bc = param_1;
    *(char *)(param_1 + 0x18e) = (char)param_1[0x18e] + '\x01';
    pcStackY_c0 = (char *)0x57d8f0;
    RideInfo__UpdatePartsEnabled();
  }
  piStackY_bc = (int *)param_1[10];
  pcStackY_c0 = (char *)0x10;
  iStackY_c4 = 0x57d8fd;
  iVar16 = FindPartWithLevel();
  if (iVar16 != 0) {
    param_1[0x123] = iVar16;
    piStackY_bc = param_1;
    *(char *)(param_1 + 399) = (char)param_1[399] + '\x01';
    pcStackY_c0 = (char *)0x57d91e;
    RideInfo__UpdatePartsEnabled();
  }
  iVar16 = 0xb;
  do {
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  piStackY_bc = (int *)0x57d949;
  iVar10 = _ftol_nocw();
  iVar16 = iVar10 + -1;
  if (iVar16 < 1) {
    iVar16 = 0;
  }
  else {
    local_98 = 2;
    if (2 < iVar16) goto LAB_0057d965;
  }
  local_98 = iVar16;
LAB_0057d965:
  piVar17 = &DAT_006f0d64;
  do {
    switch(piVar17[-1]) {
    case 1:
    case 2:
    case 7:
    case 8:
    case 10:
      *piVar17 = param_1[0xc];
      break;
    default:
      *piVar17 = iVar10;
      break;
    case 0xb:
      *piVar17 = param_1[0xb];
      break;
    case 0xf:
      *piVar17 = param_1[4];
      break;
    case 0x11:
      *piVar17 = param_1[9];
    }
    piVar17 = piVar17 + 6;
  } while ((int)piVar17 < 0x6f0f5c);
  local_74[0] = 0;
  local_74[1] = 0;
  local_74[2] = 0;
  local_74[3] = 0;
  bVar7 = false;
  local_9c = 0;
  local_8c = 0;
  local_a0 = 0;
  piVar17 = &DAT_006f0d60;
  do {
    uVar22 = DAT_006f227c % 100;
    iVar10 = (int)(char)(&DAT_006f0d68)[(piVar17[1] + local_a0) * 4];
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar18 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar18 << 0x1b ^ uVar18 ^ uVar11;
    iVar16 = 0;
    if ((int)uVar22 <= iVar10) goto LAB_0057da9a;
    do {
      if (2 < iVar16) break;
      pcVar2 = (char *)(iVar16 + (piVar17[1] + local_a0) * 4 + 0x6f0d69);
      iVar16 = iVar16 + 1;
      iVar10 = iVar10 + *pcVar2;
    } while (iVar10 < (int)uVar22);
    if (iVar16 < 1) goto LAB_0057da9a;
    iVar10 = *piVar17;
    piStackY_bc = (int *)iVar21;
    switch(iVar10) {
    case 6:
      if (2 < iVar16) break;
      goto LAB_0057da9a;
    case 0xd:
    case 0xe:
      break;
    case 0xf:
      piStackY_bc = (int *)-0x5a4d7fff;
      break;
    case 0x11:
      bVar7 = true;
      goto LAB_0057da9a;
    case 0x1e:
      local_9c = iVar16;
      goto LAB_0057da9a;
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
      auStackY_f0[iVar10] = 1;
      goto LAB_0057da9a;
    case 0x29:
      local_8c = iVar16;
      goto LAB_0057da9a;
    case 0x43:
    case 0x4b:
      piStackY_bc = (int *)0x9287;
      break;
    case 0x73:
      piStackY_bc = (int *)0x7c1a7208;
      break;
    case 0x74:
      piStackY_bc = (int *)0x19dd0f;
    }
    pcStackY_c0 = (char *)&DAT_0073ad40;
    iStackY_c4 = 0x57da72;
    iVar16 = FUN_0057cd80();
    if (iVar16 != 0) {
      param_1[iVar10 + 0x113] = iVar16;
      piStackY_bc = param_1;
      *(char *)(iVar10 + 0x62c + (int)param_1) = *(char *)(iVar10 + 0x62c + (int)param_1) + '\x01';
      pcStackY_c0 = (char *)0x57da9a;
      RideInfo__UpdatePartsEnabled();
    }
LAB_0057da9a:
    puVar24 = DAT_0073ad40;
    local_a0 = local_a0 + 6;
    piVar17 = piVar17 + 6;
  } while ((int)piVar17 < 0x6f0f58);
  piStackY_bc = (int *)0x57dac4;
  puVar12 = (undefined4 *)NullUpdate_ret();
  for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
    pcStackY_c0 = (char *)puVar24[3];
    piStackY_bc = (int *)0x4;
    iStackY_c4 = 0x7326cf08;
    uVar18 = puVar24[4] * 0x30 + (int)pcStackY_c0;
    apcStackY_d8[4] = (char *)0x57daf0;
    uVar11 = BinarySearch_Hash();
    if (uVar11 == 0) break;
    if (uVar11 < uVar18) {
      uVar11 = uVar11 & (*(int *)(uVar11 + 4) != 0x7326cf08) - 1;
      goto LAB_0057db08;
    }
  }
  uVar11 = 0;
LAB_0057db08:
  param_1[0x125] = uVar11;
  piStackY_bc = param_1;
  *(char *)((int)param_1 + 0x63e) = *(char *)((int)param_1 + 0x63e) + '\x01';
  pcStackY_c0 = (char *)0x57db29;
  RideInfo__UpdatePartsEnabled();
  uVar11 = param_1[10];
  puVar24 = DAT_0073ad40;
  if (DAT_0073ad40 != puVar12) {
    while( true ) {
      pcStackY_c0 = (char *)puVar24[3];
      piStackY_bc = (int *)0x4;
      iStackY_c4 = 0x52eb02f7;
      uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
      apcStackY_d8[4] = (char *)0x57db60;
      uVar18 = BinarySearch_Hash();
      if (uVar18 == 0) break;
      for (; uVar18 < uVar22; uVar18 = uVar18 + 0x30) {
        if (*(int *)(uVar18 + 4) != 0x52eb02f7) goto LAB_0057db8b;
        if (*(char *)(uVar18 + 0x10) == '\x10') goto joined_r0x0057db91;
      }
      puVar24 = (undefined4 *)*puVar24;
      if (puVar24 == puVar12) break;
    }
  }
LAB_0057db8b:
  uVar18 = 0;
joined_r0x0057db91:
  uVar22 = uVar18;
  if (uVar22 != 0) {
    puVar24 = DAT_0073ad40;
    if (*(byte *)(uVar22 + 0x11) == uVar11) {
      param_1[0x123] = uVar22;
      piStackY_bc = param_1;
      *(char *)(param_1 + 399) = (char)param_1[399] + '\x01';
      pcStackY_c0 = (char *)0x57dc9d;
      RideInfo__UpdatePartsEnabled();
      goto LAB_0057dc9d;
    }
    for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
      uVar19 = puVar24[4] * 0x30 + puVar24[3];
      if (((uint)puVar24[3] <= uVar22) && (uVar8 = uVar22, uVar22 < uVar19)) {
        while (uVar18 = uVar8 + 0x30, uVar18 < uVar19) {
          if (*(int *)(uVar8 + 0x34) != 0x52eb02f7) goto LAB_0057dbfa;
          pcVar2 = (char *)(uVar8 + 0x40);
          uVar8 = uVar18;
          if (*pcVar2 == '\x10') goto joined_r0x0057db91;
        }
      }
    }
LAB_0057dbfa:
    uVar18 = 0;
    goto joined_r0x0057db91;
  }
LAB_0057dc9d:
  if (bVar7) {
    piStackY_bc = (int *)0xa6e1b733;
    pcStackY_c0 = (char *)&DAT_0073ad40;
    iStackY_c4 = 0x57dcc0;
    iVar16 = FUN_0057cd80();
    if (iVar16 != 0) {
      local_84[0]._0_4_ = *(DWORD *)(iVar16 + 8);
      uVar22 = DAT_006f227c % (uint)((int)*(char *)(iVar15 + 0xde) - (int)*(char *)(iVar15 + 0xdd));
      uVar18 = DAT_006f227c ^ 0x1d872b41;
      uVar11 = uVar18 >> 5 ^ uVar18;
      DAT_006f227c = uVar11 << 0x1b ^ uVar18 ^ uVar11;
      cVar4 = *(char *)(iVar15 + 0xdd);
      local_a0 = 0;
      cVar5 = *(char *)(iVar15 + 0xdc);
      do {
        iVar15 = local_a0 + 1;
        apcStackY_d8[4] = "_STYLE%02d_%2d_%2d";
        apcStackY_d8[3] = (char *)0x57dd55;
        iStackY_c4 = iVar15;
        pcStackY_c0 = (char *)((int)cVar4 + uVar22);
        piStackY_bc = (int *)(int)cVar5;
        FUN_00565da0();
        pbVar20 = &local_40;
        uVar23 = local_84[0].s.LowPart;
        bVar3 = local_40;
        while (bVar3 != 0) {
          uVar23 = uVar23 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar20 + 1;
          pbVar20 = pbVar20 + 1;
          bVar3 = *pbVar1;
        }
        puVar24 = DAT_0073ad40;
        if (DAT_0073ad40 != puVar12) {
          while( true ) {
            pcStackY_c0 = (char *)puVar24[3];
            piStackY_bc = (int *)0x4;
            iStackY_c4 = -0x7ccb83f9;
            uVar18 = puVar24[4] * 0x30 + (int)pcStackY_c0;
            apcStackY_d8[4] = (char *)0x57ddb0;
            uVar11 = BinarySearch_Hash();
            if (uVar11 == 0) break;
            for (; uVar11 < uVar18; uVar11 = uVar11 + 0x30) {
              if (*(int *)(uVar11 + 4) != -0x7ccb83f9) goto LAB_0057dde4;
              if ((*(char *)(uVar11 + 0x10) == '\x11') &&
                 ((uVar23 == 0 || (*(DWORD *)(uVar11 + 8) == uVar23)))) goto LAB_0057dde6;
            }
            puVar24 = (undefined4 *)*puVar24;
            if (puVar24 == puVar12) break;
          }
        }
LAB_0057dde4:
        uVar11 = 0;
LAB_0057dde6:
        local_74[local_a0 + 4] = uVar11;
        local_a0 = iVar15;
      } while (iVar15 < 9);
      uVar11 = DAT_006f227c ^ 0x1d872b41;
      uVar18 = uVar11 >> 5 ^ uVar11;
      uVar11 = uVar18 << 0x1b ^ uVar18 ^ uVar11;
      iVar16 = 0;
      for (iVar15 = (DAT_006f227c & 7) + 1; iVar15 != 0; iVar15 = iVar15 + -1) {
        iVar10 = 9;
        do {
          iVar16 = (iVar16 + 1) % 9;
          iVar10 = iVar10 + -1;
          if (iVar10 == 0) break;
        } while (local_74[iVar16 + 4] == 0);
      }
      DAT_006f227c = uVar11;
      if (local_74[iVar16 + 4] != 0) {
        param_1[0x124] = local_74[iVar16 + 4];
        piStackY_bc = param_1;
        *(char *)((int)param_1 + 0x63d) = *(char *)((int)param_1 + 0x63d) + '\x01';
        pcStackY_c0 = (char *)0x57de77;
        RideInfo__UpdatePartsEnabled();
      }
    }
  }
  local_a4 = 0;
  do {
    if (local_74[local_a4] == 0) goto LAB_0057e18a;
    uVar11 = 0;
    local_90 = 0;
    switch(local_a4) {
    case 0:
      uVar18 = DAT_006f227c % 5;
      uVar22 = DAT_006f227c ^ 0x1d872b41;
      uVar11 = uVar22 >> 5 ^ uVar22;
      DAT_006f227c = uVar11 << 0x1b ^ uVar11 ^ uVar22;
      local_90 = 2;
      piStackY_bc = (int *)(uVar18 + 1);
      pcStackY_c0 = "_BODY_%d";
      iStackY_c4 = 0x57def4;
      FUN_00565da0();
      pLVar13 = local_84;
      uVar6 = (undefined1)local_84[0].s.LowPart;
      iVar15 = iVar21;
      while (uVar6 != 0) {
        pDVar9 = &(pLVar13->s).LowPart;
        iVar15 = iVar15 * 0x21 + (uint)(byte)uVar6;
        pLVar13 = (LARGE_INTEGER *)((int)&(pLVar13->s).LowPart + 1);
        uVar6 = *(byte *)((int)pDVar9 + 1);
      }
      puVar24 = DAT_0073ad40;
      if (DAT_0073ad40 != puVar12) {
        while( true ) {
          pcStackY_c0 = (char *)puVar24[3];
          piStackY_bc = (int *)0x4;
          iStackY_c4 = 0x15269aef;
          uVar18 = puVar24[4] * 0x30 + (int)pcStackY_c0;
          apcStackY_d8[4] = (char *)0x57df43;
          uVar11 = BinarySearch_Hash();
          if (uVar11 == 0) break;
          for (; uVar11 < uVar18; uVar11 = uVar11 + 0x30) {
            if (*(int *)(uVar11 + 4) != 0x15269aef) goto LAB_0057df7f;
            if ((*(char *)(uVar11 + 0x10) == '\x1f') &&
               ((iVar15 == 0 || (*(int *)(uVar11 + 8) == iVar15)))) goto switchD_0057deac_default;
          }
          puVar24 = (undefined4 *)*puVar24;
          if (puVar24 == puVar12) break;
        }
      }
LAB_0057df7f:
      uVar11 = 0;
      break;
    case 1:
      uVar11 = *(uint *)(&DAT_0073ae44 + local_98 * 8);
      local_a0 = *(uint *)(&DAT_0073ae48 + local_98 * 8);
      local_90 = 0;
      goto LAB_0057e057;
    case 2:
      if ((param_1[0x11b] != 0) && (*(char *)(param_1[0x11b] + 0x11) == '\0')) {
        uVar11 = *(uint *)(&DAT_0073ae2c + local_98 * 8);
        local_a0 = *(uint *)(&DAT_0073ae30 + local_98 * 8);
        local_90 = 1;
        goto LAB_0057e057;
      }
      break;
    case 3:
      local_90 = 3;
      local_a0 = DAT_0073ae60;
      uVar11 = DAT_0073ae5c;
LAB_0057e057:
      if (local_a0 == 0) break;
      local_a0 = DAT_006f227c % local_a0;
      uVar18 = DAT_006f227c ^ 0x1d872b41;
      uVar22 = uVar18 >> 5 ^ uVar18;
      DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar18;
      goto LAB_0057df87;
    }
switchD_0057deac_default:
    local_a0 = 0;
LAB_0057df87:
    if (uVar11 != 0) {
      bVar3 = *(byte *)(uVar11 + 0x11);
      while (puVar24 = DAT_0073ad40, local_a0 != 0) {
        for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
          pcStackY_c0 = (char *)puVar24[3];
          uVar18 = puVar24[4] * 0x30 + (int)pcStackY_c0;
          if (uVar11 == 0) {
            piStackY_bc = (int *)0x4;
            iStackY_c4 = 0x15269aef;
            apcStackY_d8[4] = (char *)0x57e09d;
            uVar22 = BinarySearch_Hash();
            if (uVar22 == 0) break;
joined_r0x0057e0af:
            for (; uVar22 < uVar18; uVar22 = uVar22 + 0x30) {
              if (*(int *)(uVar22 + 4) != 0x15269aef) goto LAB_0057e0dd;
              if ((*(char *)(uVar22 + 0x10) == '\x1f') &&
                 ((bVar3 == 0xffffffff || ((uint)*(byte *)(uVar22 + 0x11) == (uint)bVar3))))
              goto LAB_0057e0df;
            }
          }
          else if ((pcStackY_c0 <= uVar11) && (uVar11 < uVar18)) {
            uVar22 = uVar11 + 0x30;
            goto joined_r0x0057e0af;
          }
        }
LAB_0057e0dd:
        uVar22 = 0;
LAB_0057e0df:
        if (uVar22 == 0) goto LAB_0057e18a;
        switch(*(undefined1 *)(uVar22 + 0x12)) {
        default:
          iVar15 = 0;
          break;
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
        case 0xd:
          iVar15 = 1;
          break;
        case 0xf:
          iVar15 = 4;
          break;
        case 0x10:
        case 0x12:
          iVar15 = 3;
          break;
        case 0x11:
          iVar15 = 2;
        }
        uVar11 = uVar22;
        if (local_90 == iVar15) {
          local_a0 = local_a0 - 1;
        }
      }
      if (uVar11 != 0) {
        piVar14 = *(int **)(uVar11 + 0x14);
        piVar17 = piVar14 + *(short *)(uVar11 + 0x1c) * 2;
        if (piVar14 != (int *)0x0) {
          for (; piVar14 < piVar17; piVar14 = piVar14 + 2) {
            if (*piVar14 == 0x564b8cb6) {
              if ((piVar14 != (int *)0x0) && (0x10 < piVar14[1])) goto LAB_0057e18a;
              break;
            }
          }
        }
        param_1[local_a4 + 0x132] = uVar11;
        piStackY_bc = param_1;
        *(char *)(local_a4 + 0x64b + (int)param_1) =
             *(char *)(local_a4 + 0x64b + (int)param_1) + '\x01';
        pcStackY_c0 = (char *)0x57e18a;
        RideInfo__UpdatePartsEnabled();
      }
    }
LAB_0057e18a:
    local_a4 = local_a4 + 1;
    if (3 < (int)local_a4) {
      if (local_9c == 1) {
        if (local_98 < 2) {
          iVar15 = 1;
        }
        else {
          iVar15 = local_98;
          if (2 < local_98) {
            iVar15 = 2;
          }
        }
        uVar11 = (&DAT_0073ad70)[iVar15 * 2];
        uVar18 = (&DAT_0073ad6c)[iVar15 * 2];
      }
      else {
        uVar11 = DAT_0073ad98;
        uVar18 = DAT_0073ad94;
        if ((local_9c != 2) && (uVar11 = DAT_0073ad58, uVar18 = DAT_0073ad54, 0 < local_98)) {
          iVar15 = local_98;
          if (2 < local_98) {
            iVar15 = 2;
          }
          uVar11 = (&DAT_0073ad58)[iVar15 * 2];
          uVar18 = (&DAT_0073ad54)[iVar15 * 2];
        }
      }
      uVar19 = DAT_006f227c ^ 0x1d872b41;
      uVar22 = uVar19 >> 5 ^ uVar19;
      uVar11 = DAT_006f227c % uVar11;
      DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar19;
      for (; (uVar18 != 0 && (puVar24 = DAT_0073ad40, uVar11 != 0)); uVar11 = uVar11 - 1) {
        for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
          pcStackY_c0 = (char *)puVar24[3];
          uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
          if (uVar18 == 0) {
            piStackY_bc = (int *)0x4;
            iStackY_c4 = 0x9287;
            apcStackY_d8[4] = (char *)0x57e2a1;
            uVar19 = BinarySearch_Hash();
            if (uVar19 == 0) break;
joined_r0x0057e2af:
            for (; uVar19 < uVar22; uVar19 = uVar19 + 0x30) {
              if (*(int *)(uVar19 + 4) != 0x9287) goto LAB_0057e2cb;
              if (*(char *)(uVar19 + 0x10) == '\x1e') goto LAB_0057e2cd;
            }
          }
          else if ((pcStackY_c0 <= uVar18) && (uVar18 < uVar22)) {
            uVar19 = uVar18 + 0x30;
            goto joined_r0x0057e2af;
          }
        }
LAB_0057e2cb:
        uVar19 = 0;
LAB_0057e2cd:
        uVar18 = uVar19;
      }
      param_1[0x131] = uVar18;
      piStackY_bc = param_1;
      *(char *)((int)param_1 + 0x64a) = *(char *)((int)param_1 + 0x64a) + '\x01';
      pcStackY_c0 = (char *)0x57e301;
      RideInfo__UpdatePartsEnabled();
      local_84[0]._0_4_ = (&DAT_0073ad9c)[local_98 * 2];
      uVar11 = (&DAT_0073ada0)[local_98 * 2];
      if ((local_84[0]._0_4_ != 0) && (uVar11 != 0)) {
        local_88 = (char *)((int)param_1 + 0x656);
        local_94 = (uint *)(param_1 + 0x13d);
        local_a0 = 0x10;
        do {
          local_a4 = DAT_006f227c % uVar11;
          uVar22 = DAT_006f227c ^ 0x1d872b41;
          uVar18 = uVar22 >> 5 ^ uVar22;
          DAT_006f227c = uVar18 << 0x1b ^ uVar18 ^ uVar22;
          uVar23 = local_84[0].s.LowPart;
          do {
            uVar18 = uVar23;
            puVar24 = DAT_0073ad40;
            if (local_a4 == 0) break;
            for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
              pcStackY_c0 = (char *)puVar24[3];
              uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
              if (uVar23 == 0) {
                piStackY_bc = (int *)0x4;
                iStackY_c4 = 0x9287;
                apcStackY_d8[4] = (char *)0x57e3d1;
                uVar18 = BinarySearch_Hash();
                if (uVar18 == 0) break;
joined_r0x0057e3df:
                for (; uVar18 < uVar22; uVar18 = uVar18 + 0x30) {
                  if (*(int *)(uVar18 + 4) != 0x9287) goto LAB_0057e3fc;
                  if (*(char *)(uVar18 + 0x10) == '\x1e') goto LAB_0057e3fe;
                }
              }
              else if ((pcStackY_c0 <= (uint)uVar23) && ((uint)uVar23 < uVar22)) {
                uVar18 = uVar23 + 0x30;
                goto joined_r0x0057e3df;
              }
            }
LAB_0057e3fc:
            uVar18 = 0;
LAB_0057e3fe:
            local_a4 = local_a4 - 1;
            uVar23 = uVar18;
          } while (uVar18 != 0);
          *local_94 = uVar18;
          piStackY_bc = param_1;
          *local_88 = *local_88 + '\x01';
          pcStackY_c0 = (char *)0x57e42e;
          RideInfo__UpdatePartsEnabled();
          local_94 = local_94 + 1;
          local_88 = local_88 + 1;
          local_a0 = local_a0 + -1;
        } while (local_a0 != 0);
      }
      if (((param_1[0x11e] != 0) && (*(char *)(param_1[0x11e] + 0x11) != '\0')) &&
         (&DAT_0073ad54 + local_98 * 2 != (uint *)0x0)) {
        uVar19 = DAT_006f227c ^ 0x1d872b41;
        uVar22 = uVar19 >> 5 ^ uVar19;
        uVar18 = DAT_006f227c % (&DAT_0073ad58)[local_98 * 2];
        uVar11 = (&DAT_0073ad54)[local_98 * 2];
        DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar19;
        for (; (uVar11 != 0 && (puVar24 = DAT_0073ad40, uVar18 != 0)); uVar18 = uVar18 - 1) {
          for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
            pcStackY_c0 = (char *)puVar24[3];
            uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
            if (uVar11 == 0) {
              piStackY_bc = (int *)0x4;
              iStackY_c4 = 0x9287;
              apcStackY_d8[4] = (char *)0x57e501;
              uVar19 = BinarySearch_Hash();
              if (uVar19 == 0) break;
joined_r0x0057e50a:
              for (; uVar19 < uVar22; uVar19 = uVar19 + 0x30) {
                if (*(int *)(uVar19 + 4) != 0x9287) goto LAB_0057e52b;
                if (*(char *)(uVar19 + 0x10) == '\x1e') goto LAB_0057e52d;
              }
            }
            else if ((pcStackY_c0 <= uVar11) && (uVar11 < uVar22)) {
              uVar19 = uVar11 + 0x30;
              goto joined_r0x0057e50a;
            }
          }
LAB_0057e52b:
          uVar19 = 0;
LAB_0057e52d:
          uVar11 = uVar19;
        }
        param_1[0x139] = uVar11;
        *(char *)((int)param_1 + 0x652) = *(char *)((int)param_1 + 0x652) + '\x01';
        pcStackY_c0 = (char *)0x57e561;
        piStackY_bc = param_1;
        RideInfo__UpdatePartsEnabled();
      }
      if ((param_1[0x122] != 0) && (*(char *)(param_1[0x122] + 0x11) != '\0')) {
        uVar19 = DAT_006f227c ^ 0x1d872b41;
        uVar22 = uVar19 >> 5 ^ uVar19;
        uVar18 = DAT_006f227c % (uint)(&DAT_0073ade8)[local_98 * 2];
        uVar11 = (&DAT_0073ade4)[local_98 * 2];
        DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar19;
        for (; (uVar11 != 0 && (puVar24 = DAT_0073ad40, uVar18 != 0)); uVar18 = uVar18 - 1) {
          for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
            pcStackY_c0 = (char *)puVar24[3];
            uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
            if (uVar11 == 0) {
              piStackY_bc = (int *)0x4;
              iStackY_c4 = 0x9287;
              apcStackY_d8[4] = (char *)0x57e605;
              uVar19 = BinarySearch_Hash();
              if (uVar19 == 0) break;
joined_r0x0057e60e:
              for (; uVar19 < uVar22; uVar19 = uVar19 + 0x30) {
                if (*(int *)(uVar19 + 4) != 0x9287) goto LAB_0057e62f;
                if (*(char *)(uVar19 + 0x10) == '\x1e') goto LAB_0057e631;
              }
            }
            else if ((pcStackY_c0 <= uVar11) && (uVar11 < uVar22)) {
              uVar19 = uVar11 + 0x30;
              goto joined_r0x0057e60e;
            }
          }
LAB_0057e62f:
          uVar19 = 0;
LAB_0057e631:
          uVar11 = uVar19;
        }
        param_1[0x13b] = uVar11;
        *(char *)(param_1 + 0x195) = (char)param_1[0x195] + '\x01';
        pcStackY_c0 = (char *)0x57e665;
        piStackY_bc = param_1;
        RideInfo__UpdatePartsEnabled();
      }
      if ((param_1[0x123] != 0) && (*(char *)(param_1[0x123] + 0x11) != '\0')) {
        uVar19 = DAT_006f227c ^ 0x1d872b41;
        uVar22 = uVar19 >> 5 ^ uVar19;
        uVar18 = DAT_006f227c % (uint)(&DAT_0073add0)[local_98 * 2];
        uVar11 = (&DAT_0073adcc)[local_98 * 2];
        DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar19;
        for (; (uVar11 != 0 && (puVar24 = DAT_0073ad40, uVar18 != 0)); uVar18 = uVar18 - 1) {
          for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
            pcStackY_c0 = (char *)puVar24[3];
            uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
            if (uVar11 == 0) {
              piStackY_bc = (int *)0x4;
              iStackY_c4 = 0x9287;
              apcStackY_d8[4] = (char *)0x57e708;
              uVar19 = BinarySearch_Hash();
              if (uVar19 == 0) break;
joined_r0x0057e711:
              for (; uVar19 < uVar22; uVar19 = uVar19 + 0x30) {
                if (*(int *)(uVar19 + 4) != 0x9287) goto LAB_0057e732;
                if (*(char *)(uVar19 + 0x10) == '\x1e') goto LAB_0057e734;
              }
            }
            else if ((pcStackY_c0 <= uVar11) && (uVar11 < uVar22)) {
              uVar19 = uVar11 + 0x30;
              goto joined_r0x0057e711;
            }
          }
LAB_0057e732:
          uVar19 = 0;
LAB_0057e734:
          uVar11 = uVar19;
        }
        param_1[0x13a] = uVar11;
        *(char *)((int)param_1 + 0x653) = *(char *)((int)param_1 + 0x653) + '\x01';
        pcStackY_c0 = (char *)0x57e768;
        piStackY_bc = param_1;
        RideInfo__UpdatePartsEnabled();
      }
      if (((local_8c != 0) && (param_1[0x124] != 0)) && (*(char *)(param_1[0x124] + 0x11) != '\0'))
      {
        local_8c = local_8c + -1;
        if (local_8c < 1) {
          local_8c = 0;
        }
        else if (2 < local_8c) {
          local_8c = 2;
        }
        uVar19 = DAT_006f227c ^ 0x1d872b41;
        uVar22 = uVar19 >> 5 ^ uVar19;
        uVar18 = DAT_006f227c % (uint)(&DAT_0073adb8)[local_8c * 2];
        uVar11 = (&DAT_0073adb4)[local_8c * 2];
        DAT_006f227c = uVar22 << 0x1b ^ uVar22 ^ uVar19;
        for (; (uVar11 != 0 && (puVar24 = DAT_0073ad40, uVar18 != 0)); uVar18 = uVar18 - 1) {
          for (; puVar24 != puVar12; puVar24 = (undefined4 *)*puVar24) {
            pcStackY_c0 = (char *)puVar24[3];
            uVar22 = puVar24[4] * 0x30 + (int)pcStackY_c0;
            if (uVar11 == 0) {
              piStackY_bc = (int *)0x4;
              iStackY_c4 = 0x9287;
              apcStackY_d8[4] = (char *)0x57e835;
              uVar19 = BinarySearch_Hash();
              if (uVar19 == 0) break;
joined_r0x0057e83e:
              for (; uVar19 < uVar22; uVar19 = uVar19 + 0x30) {
                if (*(int *)(uVar19 + 4) != 0x9287) goto LAB_0057e85f;
                if (*(char *)(uVar19 + 0x10) == '\x1e') goto LAB_0057e861;
              }
            }
            else if ((pcStackY_c0 <= uVar11) && (uVar11 < uVar22)) {
              uVar19 = uVar11 + 0x30;
              goto joined_r0x0057e83e;
            }
          }
LAB_0057e85f:
          uVar19 = 0;
LAB_0057e861:
          uVar11 = uVar19;
        }
        param_1[0x13c] = uVar11;
        *(char *)((int)param_1 + 0x655) = *(char *)((int)param_1 + 0x655) + '\x01';
        pcStackY_c0 = (char *)0x57e895;
        piStackY_bc = param_1;
        RideInfo__UpdatePartsEnabled();
      }
      return;
    }
  } while( true );
}


// ==== 0x57e9a0 FUN_0057e9a0

void FUN_0057e9a0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
  puVar6 = DAT_0073ad40;
  puVar1 = (undefined4 *)NullUpdate_ret();
  for (; puVar6 != puVar1; puVar6 = (undefined4 *)*puVar6) {
    uVar3 = puVar6[3];
    uVar2 = puVar6[4] * 0x30 + uVar3;
    for (; uVar3 < uVar2; uVar3 = uVar3 + 0x30) {
      if (*(char *)(uVar3 + 0x10) == '\x1e') goto LAB_0057e9e6;
    }
  }
  uVar3 = 0;
LAB_0057e9e6:
  *(uint *)(param_1 + 0x4c4) = uVar3;
  *(char *)(param_1 + 0x64a) = *(char *)(param_1 + 0x64a) + '\x01';
  RideInfo__UpdatePartsEnabled(param_1);
  pcVar5 = (char *)(param_1 + 0x64b);
  puVar6 = (undefined4 *)(param_1 + 0x4c8);
  iVar4 = 4;
  do {
    *puVar6 = 0;
    *pcVar5 = *pcVar5 + '\x01';
    RideInfo__UpdatePartsEnabled(param_1);
    puVar6 = puVar6 + 1;
    pcVar5 = pcVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


// ==== 0x57ea40 FUN_0057ea40

undefined4 __fastcall FUN_0057ea40(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x44c + param_1 * 4);
}


// ==== 0x57ea50 FUN_0057ea50

undefined4 __fastcall FUN_0057ea50(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_EAX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x44c + param_1 * 4);
  *(undefined4 *)(in_EAX + 0x44c + param_1 * 4) = param_2;
  *(char *)(param_1 + 0x62c + in_EAX) = *(char *)(param_1 + 0x62c + in_EAX) + '\x01';
  RideInfo__UpdatePartsEnabled(in_EAX);
  return uVar1;
}


// ==== 0x57ea80 RideInfo::UpdatePartsEnabled

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void RideInfo__UpdatePartsEnabled(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_84;
  byte local_80;
  byte local_7f [127];
  
  piVar6 = param_1 + 0x1a9;
  for (iVar8 = 0x1e; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar6 = 0x1010101;
    piVar6 = piVar6 + 1;
  }
  local_84 = 0;
LAB_0057eab0:
  iVar8 = param_1[local_84 + 0x113];
  if (iVar8 != 0) {
    piVar6 = *(int **)(iVar8 + 0x14);
    piVar2 = piVar6;
    if (piVar6 != (int *)0x0) {
      for (; piVar2 < piVar6 + *(short *)(iVar8 + 0x1c) * 2; piVar2 = piVar2 + 2) {
        if (*piVar2 == -0x17f5c49e) {
          piVar2 = piVar6 + *(short *)(iVar8 + 0x1c) * 2;
          if ((piVar6 == (int *)0x0) || (piVar2 <= piVar6)) goto LAB_0057eb1f;
          goto LAB_0057eb10;
        }
      }
    }
  }
  goto LAB_0057ebbb;
  while (piVar6 = piVar6 + 2, piVar6 < piVar2) {
LAB_0057eb10:
    if (*piVar6 == -0x17f5c49e) goto joined_r0x0057eb25;
  }
LAB_0057eb1f:
  piVar6 = (int *)0x0;
joined_r0x0057eb25:
  while (piVar6 != (int *)0x0) {
    iVar14 = 0;
    do {
      pbVar11 = (&PTR_DAT_006f0974)[iVar14 * 2];
      iVar12 = -1;
      bVar3 = *pbVar11;
      while (bVar3 != 0) {
        iVar12 = iVar12 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar3 = *pbVar1;
      }
    } while ((iVar12 != piVar6[1]) && (iVar14 = iVar14 + 1, iVar14 < 0x78));
    if (iVar14 != 0x78) {
      *(undefined1 *)(*(int *)(iVar14 * 8 + 0x6f0970) + 0x6a4 + (int)param_1) = 0;
    }
    if (*(int *)(iVar8 + 0x14) == 0) {
LAB_0057ebaf:
      piVar6 = (int *)0x0;
    }
    else {
      do {
        piVar6 = piVar6 + 2;
        if ((int *)(*(int *)(iVar8 + 0x14) + *(short *)(iVar8 + 0x1c) * 8) <= piVar6)
        goto LAB_0057ebaf;
      } while (*piVar6 != -0x17f5c49e);
    }
  }
LAB_0057ebbb:
  if (local_84 == 0x11) {
    uVar7 = 0x43;
    iVar8 = -1;
    pcVar9 = "CALIPER";
    do {
      iVar8 = iVar8 * 0x21 + uVar7;
      pbVar11 = (byte *)(pcVar9 + 1);
      uVar7 = (uint)*pbVar11;
      pcVar9 = pcVar9 + 1;
    } while (*pbVar11 != 0);
    iVar14 = param_1[0x1c7];
    if (((iVar14 == 0) || (*(char *)(iVar14 + 0x10) != '\x1e')) || (*(int *)(iVar14 + 0xc) != iVar8)
       ) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if ((iVar14 != 0) && ((*(char *)(iVar14 + 0x10) == '\x10' || (bVar4)))) {
      *(undefined1 *)((int)param_1 + 0x6b5) = 0;
    }
    goto LAB_0057efc0;
  }
  if (local_84 == 8) {
    if (iVar8 == 0) {
      if (param_1[0x11f] != 0) {
        *(undefined1 *)(param_1 + 0x1ac) = 1;
      }
    }
    else if ((char)param_1[0x1ab] == '\0') {
      if (param_1[0x11f] != 0) {
        *(undefined1 *)(param_1 + 0x1ac) = 1;
      }
    }
    else {
      uVar7 = 0x48;
      iVar8 = -1;
      puVar10 = &DAT_006c3cf8;
      do {
        iVar8 = iVar8 * 0x21 + uVar7;
        pbVar11 = puVar10 + 1;
        uVar7 = (uint)*pbVar11;
        puVar10 = puVar10 + 1;
      } while (*pbVar11 != 0);
      iVar14 = param_1[0x1c7];
      if (((iVar14 == 0) || (*(char *)(iVar14 + 0x10) != '\x1e')) ||
         (*(int *)(iVar14 + 0xc) != iVar8)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (((iVar14 == 0) || (*(char *)(iVar14 + 0x10) != '\f')) ||
         (*(char *)(iVar14 + 0x11) == '\0')) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if ((iVar14 == 0) || ((!bVar5 && (!bVar4)))) {
        if (param_1[0x11f] != 0) {
          *(undefined1 *)(param_1 + 0x1ac) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x1ab) = 0;
        *(undefined1 *)((int)param_1 + 0x6b7) = 0;
        *(undefined1 *)(param_1 + 0x1ac) = 1;
      }
    }
    goto LAB_0057efc0;
  }
  if (local_84 != 6) goto LAB_0057efc0;
  if (iVar8 == 0) {
    *(undefined1 *)((int)param_1 + 0x6a5) = 1;
    *(undefined1 *)((int)param_1 + 0x6a6) = 1;
    *(undefined1 *)((int)param_1 + 0x6ae) = 1;
    *(undefined1 *)((int)param_1 + 0x6a9) = 1;
    *(undefined1 *)((int)param_1 + 0x6aa) = 0;
    puVar10 = (undefined1 *)((int)param_1 + 0x6be);
    iVar8 = 4;
    do {
      puVar10[-4] = 1;
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    goto LAB_0057efc0;
  }
  FUN_00565da0("%s_WIDE%d_",*param_1 * 0xc90 + DAT_00734588,*(undefined1 *)(iVar8 + 0x12));
  iVar8 = -1;
  pbVar11 = &local_80;
  bVar3 = local_80;
  while (bVar3 != 0) {
    iVar8 = iVar8 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar11 + 1;
    pbVar11 = pbVar11 + 1;
    bVar3 = *pbVar1;
  }
  pcVar9 = "DECAL_LEFT_DOOR_RECT_MEDIUM";
  uVar7 = 0x44;
  iVar14 = iVar8;
  do {
    pbVar11 = (byte *)(pcVar9 + 1);
    iVar14 = iVar14 * 0x21 + uVar7;
    pcVar9 = pcVar9 + 1;
    uVar7 = (uint)*pbVar11;
  } while (*pbVar11 != 0);
  iVar12 = *param_1;
  iVar13 = 0;
  if (iVar12 == 0x23) {
LAB_0057ede2:
    iVar14 = CarPartDatabase__GetCarPart(iVar13,0x1a,iVar14,0,0xffffffff);
  }
  else {
    iVar13 = iVar12 * 0xc90 + DAT_00734588;
    if (iVar13 != 0) {
      pbVar11 = (byte *)(iVar13 + 0x20);
      iVar13 = -1;
      bVar3 = *pbVar11;
      while (bVar3 != 0) {
        iVar13 = iVar13 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar3 = *pbVar1;
      }
      goto LAB_0057ede2;
    }
    iVar14 = 0;
  }
  param_1[0x12d] = iVar14;
  pcVar9 = "DECAL_RIGHT_DOOR_RECT_MEDIUM";
  uVar7 = 0x44;
  iVar14 = iVar8;
  do {
    pbVar11 = (byte *)(pcVar9 + 1);
    iVar14 = iVar14 * 0x21 + uVar7;
    pcVar9 = pcVar9 + 1;
    uVar7 = (uint)*pbVar11;
  } while (*pbVar11 != 0);
  iVar13 = 0;
  if (iVar12 == 0x23) {
LAB_0057ee50:
    iVar14 = CarPartDatabase__GetCarPart(iVar13,0x1b,iVar14,0,0xffffffff);
  }
  else {
    iVar13 = iVar12 * 0xc90 + DAT_00734588;
    if (iVar13 != 0) {
      pbVar11 = (byte *)(iVar13 + 0x20);
      iVar13 = -1;
      bVar3 = *pbVar11;
      while (bVar3 != 0) {
        iVar13 = iVar13 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar3 = *pbVar1;
      }
      goto LAB_0057ee50;
    }
    iVar14 = 0;
  }
  param_1[0x12e] = iVar14;
  pcVar9 = "DECAL_LEFT_QUARTER_RECT_MEDIUM";
  uVar7 = 0x44;
  iVar14 = iVar8;
  do {
    pbVar11 = (byte *)(pcVar9 + 1);
    iVar14 = iVar14 * 0x21 + uVar7;
    pcVar9 = pcVar9 + 1;
    uVar7 = (uint)*pbVar11;
  } while (*pbVar11 != 0);
  iVar13 = 0;
  if (iVar12 == 0x23) {
LAB_0057eec0:
    iVar14 = CarPartDatabase__GetCarPart(iVar13,0x1c,iVar14,0,0xffffffff);
  }
  else {
    iVar13 = iVar12 * 0xc90 + DAT_00734588;
    if (iVar13 != 0) {
      pbVar11 = (byte *)(iVar13 + 0x20);
      iVar13 = -1;
      bVar3 = *pbVar11;
      while (bVar3 != 0) {
        iVar13 = iVar13 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar3 = *pbVar1;
      }
      goto LAB_0057eec0;
    }
    iVar14 = 0;
  }
  param_1[0x12f] = iVar14;
  pcVar9 = "DECAL_RIGHT_QUARTER_RECT_MEDIUM";
  uVar7 = 0x44;
  do {
    pbVar11 = (byte *)(pcVar9 + 1);
    iVar8 = iVar8 * 0x21 + uVar7;
    pcVar9 = pcVar9 + 1;
    uVar7 = (uint)*pbVar11;
  } while (*pbVar11 != 0);
  iVar14 = 0;
  if (iVar12 == 0x23) {
LAB_0057ef28:
    iVar8 = CarPartDatabase__GetCarPart(iVar14,0x1d,iVar8,0,0xffffffff);
  }
  else {
    iVar14 = iVar12 * 0xc90 + DAT_00734588;
    if (iVar14 != 0) {
      pbVar11 = (byte *)(iVar14 + 0x20);
      iVar14 = -1;
      bVar3 = *pbVar11;
      while (bVar3 != 0) {
        iVar14 = iVar14 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
        bVar3 = *pbVar1;
      }
      goto LAB_0057ef28;
    }
    iVar8 = 0;
  }
  param_1[0x130] = iVar8;
  *(undefined1 *)((int)param_1 + 0x6a5) = 0;
  *(undefined1 *)((int)param_1 + 0x6a6) = 0;
  *(undefined1 *)((int)param_1 + 0x6ae) = 0;
  *(undefined1 *)((int)param_1 + 0x6a9) = 0;
  *(undefined1 *)((int)param_1 + 0x6aa) = 1;
  puVar10 = (undefined1 *)((int)param_1 + 0x6be);
  iVar8 = 4;
  do {
    puVar10[-4] = 0;
    *puVar10 = 1;
    puVar10 = puVar10 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
LAB_0057efc0:
  local_84 = local_84 + 1;
  if (0x77 < local_84) {
    return;
  }
  goto LAB_0057eab0;
}


// ==== 0x57efe0 FUN_0057efe0

undefined4 FUN_0057efe0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x444);
}


// ==== 0x57eff0 FUN_0057eff0

void __fastcall FUN_0057eff0(undefined4 param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x444) = param_1;
  return;
}


// ==== 0x57f000 FUN_0057f000

undefined4 FUN_0057f000(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x448);
}


// ==== 0x57f010 FUN_0057f010

void __fastcall FUN_0057f010(undefined4 param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x448) = param_1;
  return;
}


// ==== 0x57f020 FUN_0057f020

int FUN_0057f020(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int *in_EAX;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined *puVar7;
  int iVar8;
  
  iVar4 = *in_EAX * 0xc90 + DAT_00734588;
  if (iVar4 != 0) {
    pbVar6 = (byte *)(iVar4 + 0x20);
    iVar4 = -1;
    bVar3 = *pbVar6;
    while (bVar3 != 0) {
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    puVar7 = &DAT_006ba188;
    uVar5 = 0x5f;
    do {
      pbVar6 = puVar7 + 1;
      iVar4 = iVar4 * 0x21 + uVar5;
      puVar7 = puVar7 + 1;
      uVar5 = (uint)*pbVar6;
    } while (*pbVar6 != 0);
    if ((((in_EAX[0x118] != 0) && (iVar8 = in_EAX[0x118], *(char *)((int)in_EAX + 0x6a9) != '\0'))
        || ((in_EAX[0x119] != 0 && (iVar8 = in_EAX[0x119], *(char *)((int)in_EAX + 0x6aa) != '\0')))
        ) && (iVar8 != 0)) {
      puVar7 = &DAT_006b9fc8;
      do {
        pcVar2 = puVar7 + 1;
        puVar7 = puVar7 + 1;
      } while (*pcVar2 != '\0');
      iVar4 = FUN_0057cc70(iVar4);
    }
    return iVar4;
  }
  return 0;
}


// ==== 0x57f0d0 FUN_0057f0d0

int FUN_0057f0d0(void)

{
  byte *pbVar1;
  byte bVar2;
  int *in_EAX;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined *puVar6;
  
  iVar3 = *in_EAX * 0xc90 + DAT_00734588;
  if (iVar3 != 0) {
    pbVar4 = (byte *)(iVar3 + 0x20);
    iVar3 = -1;
    bVar2 = *pbVar4;
    while (bVar2 != 0) {
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar4 + 1;
      pbVar4 = pbVar4 + 1;
      bVar2 = *pbVar1;
    }
    puVar6 = &DAT_006ba188;
    uVar5 = 0x5f;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar4 = puVar6 + 1;
      uVar5 = (uint)*pbVar4;
      puVar6 = puVar6 + 1;
    } while (*pbVar4 != 0);
    return iVar3;
  }
  return 0;
}


// ==== 0x57f130 FUN_0057f130

int FUN_0057f130(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  return in_EAX + 0x60;
}


// ==== 0x57f150 FUN_0057f150

undefined1 FUN_0057f150(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  return *(undefined1 *)(in_EAX + 0x424);
}


// ==== 0x57f170 GetStockPerformanceMeasure

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

float10 GetStockPerformanceMeasure(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return (float10)141.0;
  case 1:
    return (float10)174.0;
  case 2:
    return (float10)190.0;
  case 3:
  case 5:
    return (float10)188.0;
  case 4:
    return (float10)177.0;
  case 6:
  case 0xe:
    return (float10)233.0;
  case 7:
    return (float10)217.0;
  case 8:
    return (float10)315.0;
  case 9:
    return (float10)215.0;
  case 10:
    return (float10)275.0;
  case 0xb:
    return (float10)223.0;
  case 0xc:
    return (float10)193.0;
  case 0xd:
    return (float10)158.0;
  case 0xf:
    return (float10)199.0;
  case 0x10:
    return (float10)253.0;
  case 0x11:
    return (float10)205.0;
  case 0x12:
    return (float10)206.0;
  case 0x13:
    return (float10)340.0;
  default:
    return (float10)0.0;
  }
}


// ==== 0x57f260 RideInfo::GetPerformanceMeasure

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

float10 RideInfo__GetPerformanceMeasure(char param_1)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if (param_1 != '\0') {
    return (((float10)*(float *)(in_EAX + 0x428) - (float10)_DAT_006f0d58) * (float10)10.0) /
           ((float10)_DAT_006f0d5c - (float10)_DAT_006f0d58);
  }
  return (float10)*(float *)(in_EAX + 0x428);
}


// ==== 0x57f2b0 RideInfo::RebuildPhysicsInfo

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void RideInfo__RebuildPhysicsInfo(char param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  float local_c;
  float local_8;
  
  if (*unaff_EDI != -1) {
    unaff_EDI[0xb] = 0;
    unaff_EDI[0xc] = 0;
    iVar9 = *unaff_EDI * 0xc90 + DAT_00734588;
    fVar3 = (float)(unaff_EDI[3] + unaff_EDI[9] + unaff_EDI[2]) * 0.11111111;
    CompleatCarPhysicsInfo__BuildCarPhysicsInfo(iVar9 + 0x110,unaff_EDI + 0x18,unaff_EDI + 2);
    if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
       ((DAT_00735fa0 != 0 || ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))))) {
      iVar5 = unaff_EDI[2];
      iVar4 = SelectDriveClassTuningRow__not_GetUpgradeLevel_();
      fVar1 = *(float *)(iVar4 + 0x34 + iVar5 * 4);
      fVar2 = *(float *)(iVar9 + 0x220);
      iVar4 = SelectDriveClassTuningRow__not_GetUpgradeLevel_();
      unaff_EDI[0x5c] =
           (int)(((float)unaff_EDI[0x5c] - fVar2) * *(float *)(iVar4 + 0x24 + iVar5 * 4) + fVar2);
      unaff_EDI[0x70] =
           (int)(((float)unaff_EDI[0x70] - *(float *)(iVar9 + 0x270)) * fVar1 +
                *(float *)(iVar9 + 0x270));
      iVar5 = SelectDriveClassTuningRow__not_GetUpgradeLevel_();
      fVar1 = *(float *)(iVar5 + 0x14 + unaff_EDI[9] * 4);
      iVar5 = 0;
      do {
        uVar8 = (uint)(0.2 <= (float)unaff_EDI[0x88]);
        if (0.8 < (float)unaff_EDI[0x88]) {
          uVar8 = 2;
        }
        fVar2 = *(float *)(&DAT_006f0fd0 + uVar8 * 0x6c);
        if (iVar5 == 0) {
          fVar2 = _K_ONE - fVar2;
        }
        iVar4 = (iVar5 + 0xf) * 0x20;
        iVar6 = iVar4 + iVar9;
        unaff_EDI[iVar5 * 8 + 0x4f] =
             (int)(((float)unaff_EDI[iVar5 * 8 + 0x4f] - *(float *)(iVar4 + 0xc + iVar9)) * fVar2 *
                   fVar1 + *(float *)(iVar6 + 0xc));
        unaff_EDI[(iVar5 + 10) * 8] =
             (int)(((float)unaff_EDI[iVar5 * 8 + 0x50] - *(float *)(iVar6 + 0x10)) * fVar2 * fVar1 +
                  *(float *)(iVar6 + 0x10));
        uVar8 = (uint)(0.2 <= (float)unaff_EDI[0x88]);
        if (0.8 < (float)unaff_EDI[0x88]) {
          uVar8 = 2;
        }
        fVar2 = *(float *)(&DAT_006f0fd0 + uVar8 * 0x6c);
        if (iVar5 == -1) {
          fVar2 = _K_ONE - fVar2;
        }
        iVar4 = (iVar5 + 0x10) * 0x20;
        iVar7 = iVar4 + iVar9;
        unaff_EDI[iVar5 * 8 + 0x57] =
             (int)(((float)unaff_EDI[iVar5 * 8 + 0x57] - *(float *)(iVar4 + 0xc + iVar9)) * fVar2 *
                   fVar1 + *(float *)(iVar7 + 0xc));
        iVar6 = iVar5 * 8;
        iVar4 = iVar5 + 0xb;
        iVar5 = iVar5 + 2;
        unaff_EDI[iVar4 * 8] =
             (int)(((float)unaff_EDI[iVar6 + 0x58] - *(float *)(iVar7 + 0x10)) * fVar2 * fVar1 +
                  *(float *)(iVar7 + 0x10));
      } while (iVar5 < 2);
      uVar8 = (uint)(0.2 <= (float)unaff_EDI[0x88]);
      if (0.8 < (float)unaff_EDI[0x88]) {
        uVar8 = 2;
      }
      fVar1 = *(float *)(&DAT_006f1004 + uVar8 * 0x6c);
      uVar8 = (uint)(0.2 <= (float)unaff_EDI[0x88]);
      if (0.8 < (float)unaff_EDI[0x88]) {
        uVar8 = 2;
      }
      unaff_EDI[0x88] = *(int *)(&DAT_006f1008 + uVar8 * 0x6c);
    }
    else {
      fVar1 = 1.0;
    }
    unaff_EDI[0xb1] =
         (int)((*(float *)(iVar9 + 2000) + *(float *)(iVar9 + 0x800)) * fVar3 * fVar1 +
              (float)unaff_EDI[0xb1]);
    unaff_EDI[0xb2] =
         (int)((*(float *)(iVar9 + 0x804) + *(float *)(iVar9 + 0x7d4)) * fVar3 * fVar1 +
              (float)unaff_EDI[0xb2]);
    unaff_EDI[0xb3] =
         (int)((*(float *)(iVar9 + 0x808) + *(float *)(iVar9 + 0x7d8)) * fVar3 * fVar1 +
              (float)unaff_EDI[0xb3]);
    iVar9 = _ftol_nocw();
    unaff_EDI[0xc] = iVar9;
    unaff_EDI[0xb] = iVar9;
    MakeAccelerationTable(unaff_EDI + 0x104);
    if (*(int *)(*unaff_EDI * 0xc90 + 0xc54 + DAT_00734588) == 0) {
      local_c = (float)unaff_EDI[0x105];
      local_8 = 0.0;
      if (local_c < (float)unaff_EDI[0x106] != (local_c == (float)unaff_EDI[0x106])) {
        do {
          fVar10 = (float10)FUN_00583ea0(local_c);
          fVar11 = ((float10)local_c * (float10)(float)unaff_EDI[0xb0] * (float10)local_c) /
                   (float10)(float)unaff_EDI[0x5c];
          if (fVar10 < fVar11) break;
          local_8 = (float)((fVar10 - fVar11) * (float10)1.3410819 + (float10)local_8);
          local_c = local_c + 1.3410819;
        } while (local_c < (float)unaff_EDI[0x106] != (local_c == (float)unaff_EDI[0x106]));
      }
      iVar9 = 3;
      do {
        if (*(float *)(&UNK_006b5bd8 + iVar9 * 4) < local_8) {
          *(char *)(unaff_EDI + 0x109) = '\x03' - (char)iVar9;
          break;
        }
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
      unaff_EDI[0x10a] = (int)local_8;
      if (param_1 != '\0') {
        RideInfo__ComputeMiscStats();
        return;
      }
    }
    else {
      *(undefined1 *)(unaff_EDI + 0x109) = 3;
    }
  }
  return;
}


// ==== 0x57f700 RideInfo::MatchPerformance_RideInfo__other______

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void RideInfo__MatchPerformance_RideInfo__other______
               (int param_1,int param_2,int param_3,int param_4,char param_5,float param_6)

{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  
  if (*(char *)(param_2 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar1 = *(float *)(param_2 + 0x428);
  while( true ) {
    if (*(char *)(param_1 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    if (ABS(fVar1 - *(float *)(param_1 + 0x428)) <= param_6) break;
    puVar5 = (undefined4 *)(param_2 + 8);
    puVar10 = (undefined4 *)(param_1 + 8);
    for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar10 = puVar10 + 1;
    }
    RideInfo__RebuildPhysicsInfo(0);
    if (*(char *)(param_1 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    fVar3 = ABS(fVar1 - *(float *)(param_1 + 0x428));
    if (fVar3 < param_6 != (fVar3 == param_6)) break;
    puVar9 = &DAT_006f0f78;
    do {
      if (*(char *)(param_1 + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      if (ABS(fVar1 - *(float *)(param_1 + 0x428)) <= param_6) break;
      iVar7 = 0;
      do {
        if (*(char *)(param_1 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        if (ABS(fVar1 - *(float *)(param_1 + 0x428)) <= param_6) break;
        if ((*puVar9 & 1 << ((byte)iVar7 & 0x1f)) != 0) {
          if (*(char *)(param_1 + 0x424) == -1) {
            RideInfo__RebuildPhysicsInfo(1);
          }
          if (fVar1 <= *(float *)(param_1 + 0x428)) {
            puVar8 = (uint *)(param_1 + 8 + (&DAT_006f0f58)[iVar7] * 4);
            uVar4 = *(int *)(param_1 + 8 + (&DAT_006f0f58)[iVar7] * 4) - 1;
            uVar4 = uVar4 & ((int)uVar4 < 1) - 1;
          }
          else {
            puVar8 = (uint *)(param_1 + 8 + (&DAT_006f0f58)[iVar7] * 4);
            uVar4 = *puVar8 + 1;
            if (2 < (int)uVar4) {
              uVar4 = 3;
            }
          }
          *puVar8 = uVar4;
          RideInfo__RebuildPhysicsInfo(0);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 4);
      if (param_5 != '\0') {
        puVar5 = &DAT_006f0f58;
        do {
          puVar5 = puVar5 + 1;
        } while ((int)puVar5 < 0x6f0f68);
        iVar7 = _ftol_nocw();
        if (iVar7 < 1) {
          iVar7 = 0;
        }
        else if (3 < iVar7) {
          iVar7 = 3;
        }
        piVar6 = &DAT_006f0f68;
        do {
          iVar2 = *piVar6;
          piVar6 = piVar6 + 1;
          *(int *)(param_1 + 8 + iVar2 * 4) = iVar7;
        } while ((int)piVar6 < 0x6f0f78);
        if ((-1 < param_3) && (param_3 < 4)) {
          iVar7 = param_3;
        }
        *(int *)(param_1 + 0x18) = iVar7;
        RideInfo__RebuildPhysicsInfo(0);
      }
      puVar9 = puVar9 + 1;
    } while ((int)puVar9 < 0x6f0fb4);
    if (*(char *)(param_1 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    fVar3 = ABS(fVar1 - *(float *)(param_1 + 0x428));
    if (fVar3 < param_6 != (fVar3 == param_6)) break;
    param_6 = param_6 + param_6;
  }
  RideInfo__ComputeMiscStats(param_1);
  if ((-1 < param_4) && (param_4 < 4)) {
    *(char *)(param_1 + 0x424) = (char)param_4;
  }
  return;
}


// ==== 0x57f970 RideInfo::MatchPerformance_float_target______

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void RideInfo__MatchPerformance_float_target______
               (float param_1,int param_2,char param_3,float param_4)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  float local_4;
  
  local_4 = param_1;
  if (param_3 != '\0') {
    local_4 = (_DAT_006f0d5c - _DAT_006f0d58) * param_1 * 0.1 + _DAT_006f0d58;
  }
  while( true ) {
    if (*(char *)(in_EAX + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    if (ABS(local_4 - *(float *)(in_EAX + 0x428)) <= param_4) break;
    puVar7 = &DAT_006f0f78;
    do {
      if (*(char *)(in_EAX + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      if (ABS(local_4 - *(float *)(in_EAX + 0x428)) <= param_4) break;
      iVar8 = 0;
      do {
        if (*(char *)(in_EAX + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        if (ABS(local_4 - *(float *)(in_EAX + 0x428)) <= param_4) break;
        if ((*puVar7 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
          if (*(char *)(in_EAX + 0x424) == -1) {
            RideInfo__RebuildPhysicsInfo(1);
          }
          if (local_4 <= *(float *)(in_EAX + 0x428)) {
            puVar6 = (uint *)(in_EAX + 8 + (&DAT_006f0f58)[iVar8] * 4);
            uVar3 = *(int *)(in_EAX + 8 + (&DAT_006f0f58)[iVar8] * 4) - 1;
            uVar3 = uVar3 & ((int)uVar3 < 1) - 1;
          }
          else {
            puVar6 = (uint *)(in_EAX + 8 + (&DAT_006f0f58)[iVar8] * 4);
            uVar3 = *puVar6 + 1;
            if (2 < (int)uVar3) {
              uVar3 = 3;
            }
          }
          *puVar6 = uVar3;
          RideInfo__RebuildPhysicsInfo(0);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
      puVar4 = &DAT_006f0f58;
      do {
        puVar4 = puVar4 + 1;
      } while ((int)puVar4 < 0x6f0f68);
      iVar8 = _ftol_nocw();
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      else if (3 < iVar8) {
        iVar8 = 3;
      }
      piVar5 = &DAT_006f0f68;
      do {
        iVar1 = *piVar5;
        piVar5 = piVar5 + 1;
        *(int *)(in_EAX + 8 + iVar1 * 4) = iVar8;
      } while ((int)piVar5 < 0x6f0f78);
      if ((-1 < param_2) && (param_2 < 4)) {
        iVar8 = param_2;
      }
      *(int *)(in_EAX + 0x18) = iVar8;
      RideInfo__RebuildPhysicsInfo(0);
      puVar7 = puVar7 + 1;
    } while ((int)puVar7 < 0x6f0fb4);
    if (*(char *)(in_EAX + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    fVar2 = ABS(local_4 - *(float *)(in_EAX + 0x428));
    if (fVar2 < param_4 != (fVar2 == param_4)) break;
    param_4 = param_4 + param_4;
  }
  RideInfo__ComputeMiscStats(in_EAX);
  return;
}


// ==== 0x57fb80 FUN_0057fb80

void FUN_0057fb80(int *param_1,int *param_2)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int local_14;
  
  iVar5 = *param_2 * 0xc90 + DAT_00734588;
  cVar3 = *(char *)(*param_2 * 0xc90 + DAT_00734588);
  while (cVar3 != '\0') {
    pcVar1 = (char *)(iVar5 + 1);
    iVar5 = iVar5 + 1;
    cVar3 = *pcVar1;
  }
  puVar6 = &DAT_006ba184;
  do {
    pcVar1 = puVar6 + 1;
    puVar6 = puVar6 + 1;
  } while (*pcVar1 != '\0');
  pbVar7 = (byte *)(*param_1 * 0xc90 + DAT_00734588);
  iVar5 = -1;
  bVar4 = *pbVar7;
  pbVar13 = pbVar7;
  while (bVar4 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar4;
    pbVar2 = pbVar13 + 1;
    pbVar13 = pbVar13 + 1;
    bVar4 = *pbVar2;
  }
  local_14 = 0;
  do {
    uVar10 = param_2[local_14 + 0x113];
    uVar18 = 0;
    bVar19 = false;
    if (uVar10 == 0) goto LAB_005800c9;
    switch(local_14) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 0xc:
    case 0x12:
    case 0x23:
    case 0x24:
    case 0x3a:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x59:
    case 0x5a:
    case 0x61:
    case 0x62:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
      goto switchD_0057fc4b_caseD_0;
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xd:
    case 0xe:
      uVar15 = CarPartDatabase__GetCarPart(iVar5,local_14,0,0,0xffffffff);
      while ((uVar15 != 0 && (!bVar19))) {
        if ((*(char *)(uVar15 + 0x12) == *(char *)(uVar10 + 0x12)) &&
           (*(char *)(uVar15 + 0x11) == *(char *)(uVar10 + 0x11))) {
          bVar19 = true;
          uVar18 = uVar15;
        }
        else {
          uVar15 = CarPartDatabase__GetCarPart(iVar5,local_14,0,uVar15,0xffffffff);
          bVar19 = false;
        }
      }
      break;
    case 0xb:
      iVar8 = *param_1;
      bVar20 = false;
      if (((-1 < iVar8) && (((iVar8 < 2 || (iVar8 == 5)) && (iVar8 = *param_2, iVar8 != 0)))) &&
         ((iVar8 != 1 && (iVar8 != 5)))) {
        bVar20 = true;
      }
      uVar15 = CarPartDatabase__GetCarPart(iVar5,0xb,0,0,0xffffffff);
      while ((uVar15 != 0 && (!bVar19))) {
        if (bVar20) {
          bVar19 = *(char *)(uVar15 + 0x12) == '\x01';
        }
        else {
          bVar19 = *(char *)(uVar15 + 0x12) == *(char *)(uVar10 + 0x12);
        }
        if ((bVar19) && (*(char *)(uVar15 + 0x11) == *(char *)(uVar10 + 0x11))) {
          bVar19 = true;
          uVar18 = uVar15;
        }
        else {
          uVar15 = CarPartDatabase__GetCarPart(iVar5,0xb,0,uVar15,0xffffffff);
          bVar19 = false;
        }
      }
      break;
    case 0xf:
    case 0x11:
      if (*(char *)(uVar10 + 0x11) != '\0') goto switchD_0057fc4b_caseD_1e;
      uVar10 = CarPartDatabase__GetCarPart(iVar5,local_14,0,0,0xffffffff);
      if (uVar10 != 0) {
        uVar18 = uVar10;
      }
      break;
    case 0x10:
      uVar10 = param_1[10];
      iVar8 = FUN_00567c70();
      piVar16 = DAT_0073ad40;
      piVar12 = (int *)NullUpdate_ret();
      if (piVar16 != piVar12) {
        while( true ) {
          uVar18 = piVar16[3];
          uVar15 = piVar16[4] * 0x30 + uVar18;
          if ((iVar8 != 0) && (uVar18 = BinarySearch_Hash(iVar8,uVar18,4), uVar18 == 0)) break;
          for (; uVar18 < uVar15; uVar18 = uVar18 + 0x30) {
            if ((iVar8 != 0) && (*(int *)(uVar18 + 4) != iVar8)) goto LAB_0057fcd0;
            if (*(char *)(uVar18 + 0x10) == '\x10') goto LAB_0057fcd2;
          }
          piVar16 = (int *)*piVar16;
          if (piVar16 == piVar12) break;
        }
      }
LAB_0057fcd0:
      uVar18 = 0;
LAB_0057fcd2:
      for (bVar19 = false; (uVar18 != 0 && (!bVar19)); bVar19 = !bVar19) {
        bVar19 = *(byte *)(uVar18 + 0x11) != uVar10;
        if (bVar19) {
          uVar24 = 0xffffffff;
          uVar23 = 0;
          uVar22 = 0x10;
          uVar9 = FUN_00567c70(0x10,0,uVar18,0xffffffff);
          uVar18 = CarPartDatabase__GetCarPart(uVar9,uVar22,uVar23,uVar18,uVar24);
        }
      }
      break;
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
      bVar19 = *(char *)(uVar10 + 0x12) == '\x01';
      bVar20 = *(char *)(uVar10 + 0x12) != '\x02';
      if (param_2[0x119] == 0) {
        bVar21 = false;
      }
      else {
        bVar21 = *(char *)(param_2[0x119] + 0x12) == '\x02';
      }
      switch(local_14) {
      case 0x13:
        puVar6 = PTR_s__s_DECAL_HOOD_RECT_MEDIUM_006f88ec;
        if (bVar19) {
          puVar6 = PTR_s__s_DECAL_HOOD_RECT_SMALL_006f88f0;
        }
        break;
      case 0x14:
        puVar6 = PTR_s__s_DECAL_FRONT_WINDOW_WIDE_MEDIU_006f88ac;
        break;
      case 0x15:
        puVar6 = PTR_s__s_DECAL_REAR_WINDOW_WIDE_MEDIUM_006f88b0;
        break;
      case 0x16:
        puVar6 = PTR_s__s_DECAL_LEFT_DOOR_RECT_MEDIUM_006f88b4;
        break;
      case 0x17:
        puVar6 = PTR_s__s_DECAL_RIGHT_DOOR_RECT_MEDIUM_006f88b8;
        break;
      case 0x18:
        puVar6 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_MEDIU_006f88bc;
        if ((bVar20) && (bVar19)) {
          puVar6 = PTR_s__s_DECAL_LEFT_QUARTER_RECT_SMALL_006f88c0;
        }
        break;
      case 0x19:
        puVar6 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_MEDI_006f88c4;
        if ((bVar20) && (bVar19)) {
          puVar6 = PTR_s__s_DECAL_RIGHT_QUARTER_RECT_SMAL_006f88c8;
        }
        break;
      case 0x1a:
        if (!bVar20) {
          puVar6 = PTR_s__s_WIDE1_DECAL_LEFT_DOOR_RECT_ME_006f88cc;
          if (bVar21) {
            puVar6 = PTR_s__s_WIDE2_DECAL_LEFT_DOOR_RECT_ME_006f88dc;
          }
          break;
        }
        goto switchD_0057fc4b_default;
      case 0x1b:
        if (!bVar20) {
          puVar6 = PTR_s__s_WIDE1_DECAL_RIGHT_DOOR_RECT_M_006f88d0;
          if (bVar21) {
            puVar6 = PTR_s__s_WIDE2_DECAL_RIGHT_DOOR_RECT_M_006f88e0;
          }
          break;
        }
        goto switchD_0057fc4b_default;
      case 0x1c:
        if (!bVar20) {
          puVar6 = PTR_s__s_WIDE1_DECAL_LEFT_QUARTER_RECT_006f88d4;
          if (bVar21) {
            puVar6 = PTR_s__s_WIDE2_DECAL_LEFT_QUARTER_RECT_006f88e4;
          }
          break;
        }
        goto switchD_0057fc4b_default;
      case 0x1d:
        if (!bVar20) {
          puVar6 = PTR_s__s_WIDE2_DECAL_RIGHT_QUARTER_REC_006f88e8;
          if (!bVar21) {
            puVar6 = PTR_s__s_WIDE1_DECAL_RIGHT_QUARTER_REC_006f88d8;
          }
          break;
        }
      default:
        goto switchD_0057fc4b_default;
      }
      if (puVar6 != (undefined *)0x0) {
        uVar9 = FUN_004f42f0(puVar6,pbVar7);
        uVar10 = CarPartDatabase__GetCarPart(iVar5,local_14,uVar9,0,0xffffffff);
        if (uVar10 != 0) {
          uVar18 = uVar10;
        }
      }
      break;
    case 0x1e:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x4b:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 99:
    case 100:
    case 0x6b:
    case 0x6c:
    case 0x73:
    case 0x74:
switchD_0057fc4b_caseD_1e:
      uVar18 = uVar10;
      break;
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
      if (*(char *)(uVar10 + 0x12) != '\x11') goto switchD_0057fc4b_caseD_1e;
      iVar8 = *(int *)(uVar10 + 8);
      iVar17 = 0;
      iVar11 = bStringHashSeeded();
      if ((((iVar8 == iVar11) || (iVar11 = bStringHashSeeded(), iVar8 == iVar11)) ||
          (iVar11 = bStringHashSeeded(), iVar8 == iVar11)) ||
         ((iVar11 = bStringHashSeeded(), iVar8 == iVar11 ||
          (iVar11 = bStringHashSeeded(), iVar8 == iVar11)))) {
        iVar17 = bStringHashSeeded();
      }
      piVar16 = DAT_0073ad40;
      piVar12 = (int *)NullUpdate_ret();
      for (; uVar10 = uVar18, piVar16 != piVar12; piVar16 = (int *)*piVar16) {
        uVar15 = piVar16[3];
        uVar14 = piVar16[4] * 0x30 + uVar15;
        for (; uVar15 < uVar14; uVar15 = uVar15 + 0x30) {
          if (*(char *)(uVar15 + 0x10) == '\x1f') goto joined_r0x0058006e;
        }
      }
      uVar15 = 0;
joined_r0x0058006e:
      while ((uVar18 = uVar15, uVar18 != 0 && (uVar10 == 0))) {
        if ((*(char *)(uVar18 + 0x12) != '\x11') ||
           (uVar10 = uVar18, uVar15 = uVar18, *(int *)(uVar18 + 8) != iVar17)) {
          uVar15 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar18,0xffffffff);
          uVar10 = 0;
        }
      }
    }
switchD_0057fc4b_default:
    param_1[local_14 + 0x113] = uVar18;
    *(char *)(local_14 + 0x62c + (int)param_1) = *(char *)(local_14 + 0x62c + (int)param_1) + '\x01'
    ;
    RideInfo__UpdatePartsEnabled(param_1);
switchD_0057fc4b_caseD_0:
LAB_005800c9:
    local_14 = local_14 + 1;
    if (0x77 < local_14) {
      return;
    }
  } while( true );
}


// ==== 0x5801b0 RideInfo::GetTopSpeedRating

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

float10 __fastcall RideInfo__GetTopSpeedRating(undefined4 param_1)

{
  float fVar1;
  int unaff_ESI;
  float10 fVar2;
  
  fVar2 = (float10)RideInfo__GetTheoreticalTopSpeed(param_1);
  fVar2 = (((float10)*(float *)(unaff_ESI + 0x30c) * (float10)*(float *)(unaff_ESI + 0x300) -
           (float10)_DAT_006f0d50) / ((float10)DAT_006f0d54 - (float10)_DAT_006f0d50)) *
          (float10)0.175 +
          ((float10)_K_ONE - (float10)0.175) *
          ((fVar2 * (float10)2.237 - (float10)128.0) / ((float10)207.0 - (float10)128.0));
  fVar1 = (float)fVar2;
  if ((float10)0.03 < fVar2) {
    if (_K_ONE < fVar1) {
      fVar1 = _K_ONE;
    }
    return (float10)fVar1;
  }
  return (float10)0.03;
}


// ==== 0x580240 RideInfo::GetTheoreticalTopSpeed

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

float10 RideInfo__GetTheoreticalTopSpeed(void)

{
  float fVar1;
  int in_EAX;
  float10 fVar2;
  undefined4 local_4;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  local_4 = *(float *)(in_EAX + 0x414);
  fVar1 = *(float *)(in_EAX + 0x418);
  if ((!NAN(local_4) && !NAN(fVar1)) && local_4 < fVar1 != (local_4 == fVar1)) {
    do {
      fVar2 = (float10)FUN_00583ea0(local_4);
      if (fVar2 < ((float10)local_4 * (float10)*(float *)(in_EAX + 0x2c0) * (float10)local_4) /
                  (float10)*(float *)(in_EAX + 0x170)) break;
      local_4 = local_4 + 1.3410819;
      fVar1 = *(float *)(in_EAX + 0x418);
    } while ((!NAN(local_4) && !NAN(fVar1)) && local_4 < fVar1 != (local_4 == fVar1));
  }
  return (float10)local_4;
}


// ==== 0x5802c0 RideInfo::GetAccelRating

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

float10 RideInfo__GetAccelRating(void)

{
  float fVar1;
  int in_EAX;
  float10 fVar2;
  float10 fVar3;
  float local_8;
  float local_4;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  local_8 = 0.0;
  local_4 = 0.0;
  do {
    fVar2 = (float10)FUN_00583ea0(local_4);
    fVar3 = ((float10)local_4 * (float10)*(float *)(in_EAX + 0x2c0) * (float10)local_4) /
            (float10)*(float *)(in_EAX + 0x170);
    if (fVar2 < fVar3) break;
    local_8 = (float)((fVar2 - fVar3) * (float10)1.3410819 + (float10)local_8);
    local_4 = local_4 + 1.3410819;
  } while (local_4 < 44.70273);
  fVar1 = (float)*(int *)(in_EAX + 0x20) * 0.33333334 * 0.08 +
          ((*(float *)(in_EAX + 0x30c) * *(float *)(in_EAX + 0x300) - _DAT_006f0d50) /
          (DAT_006f0d54 - _DAT_006f0d50)) * 0.2 + (_K_ONE - 0.28) * ((local_8 - 136.0) / 426.0);
  if (fVar1 <= 0.03) {
    return (float10)0.03;
  }
  if (_K_ONE < fVar1) {
    fVar1 = _K_ONE;
  }
  return (float10)fVar1;
}


// ==== 0x580400 RideInfo::GetHandlingRating

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

float10 RideInfo__GetHandlingRating(void)

{
  float fVar1;
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if (*(float *)(in_EAX + 0x220) <= 0.6) {
    fVar1 = (*(float *)(in_EAX + 0x220) + 0.2) * 1.25;
  }
  else {
    fVar1 = (_K_ONE - *(float *)(in_EAX + 0x220)) * 2.5;
  }
  fVar1 = fVar1 * 0.1 +
          (_K_ONE - (*(float *)(in_EAX + 0x170) - _DAT_006f0d48) / (_DAT_006f0d4c - _DAT_006f0d48))
          * 0.295 + (((*(float *)(in_EAX + 0x1e0) + *(float *)(in_EAX + 0x1d4) +
                      *(float *)(in_EAX + 0x200) + *(float *)(in_EAX + 500)) * 0.5 * 0.5 -
                     _DAT_006f0d30) / (_DAT_006f0d34 - _DAT_006f0d30)) * 0.265 +
                    (((*(float *)(in_EAX + 0x2d4) * 0.65 + *(float *)(in_EAX + 0x2d8) * 0.35) -
                     _DAT_006f0d40) / (_DAT_006f0d44 - _DAT_006f0d40)) * 0.225 +
                    (((*(float *)(in_EAX + 0x140) + *(float *)(in_EAX + 0x13c) +
                      *(float *)(in_EAX + 0x160) + *(float *)(in_EAX + 0x15c)) * _K_HALF * _K_HALF -
                     _DAT_006f0d38) / (_DAT_006f0d3c - _DAT_006f0d38)) * 0.255;
  if (0.03 < fVar1) {
    if (_K_ONE < fVar1) {
      fVar1 = _K_ONE;
    }
    return (float10)fVar1;
  }
  return (float10)0.03;
}


// ==== 0x580590 RideInfo::ComputeMiscStats

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void RideInfo__ComputeMiscStats(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  bool local_7d;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined1 local_48 [8];
  float local_40 [16];
  
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined4 *)(param_1 + 0x430) = 0;
  local_78 = *(float *)(param_1 + 0x250);
  if (local_78 < *(float *)(param_1 + 600)) {
    do {
      fVar10 = (float10)FUN_00583ea0(local_78);
      fVar10 = fVar10 * (float10)local_78 * (float10)0.14044943;
      if ((float10)*(float *)(param_1 + 0x430) < fVar10) {
        *(float *)(param_1 + 0x430) = (float)fVar10;
        *(float *)(param_1 + 0x434) = local_78;
      }
      local_78 = local_78 + 50.0;
    } while (local_78 < *(float *)(param_1 + 600));
  }
  fVar4 = *(float *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x438) = 0;
  *(undefined4 *)(param_1 + 0x440) = 0;
  *(undefined4 *)(param_1 + 0x43c) = 0;
  fVar1 = *(float *)(param_1 + 0x220);
  fVar5 = _K_ONE - fVar1;
  fVar2 = *(float *)(param_1 + 0xe0);
  fVar3 = *(float *)(param_1 + 0x80);
  local_7c = 0.0;
  local_74 = 0.0;
  local_70 = 0.0;
  bVar7 = 1;
  local_78 = 1.0;
  fVar6 = fVar1 * *(float *)(param_1 + 0x21c) + fVar5 * *(float *)(param_1 + 0x218);
  FUN_0046d1c0(param_1 + 0x210,local_48);
  fVar1 = _K_ONE / (fVar5 * fVar3 + fVar1 * fVar2);
  local_7d = false;
  pfVar9 = local_40;
  pfVar8 = (float *)(param_1 + 0x238);
  do {
    fVar2 = fVar1 * local_7c * *pfVar8 * fVar6 * 9.549304;
    if ((local_7d) || (DAT_006fff30 + *pfVar9 < fVar2 == (DAT_006fff30 + *pfVar9 == fVar2))) {
      local_7d = false;
      fVar10 = (float10)FUN_00583ea0(fVar2);
      fVar10 = (fVar10 * (float10)*pfVar8 * (float10)fVar6 * (float10)fVar1) / (float10)fVar4;
    }
    else {
      local_7d = true;
      local_78 = (float)(&DAT_00700034)[bVar7 - 1 & 2] * 0.016666668 + local_78;
      if (local_78 < 0.0 == (local_78 == 0.0)) {
        local_7d = _K_ONE <= local_78;
        if (local_7d) {
          pfVar9 = pfVar9 + 1;
          local_78 = 1.0;
          bVar7 = 1;
          pfVar8 = pfVar8 + 1;
        }
        local_7d = !local_7d;
        fVar10 = (float10)0.0;
      }
      else {
        fVar10 = (float10)0.0;
        local_78 = 0.0;
        bVar7 = 0;
      }
    }
    local_74 = local_74 + 0.016666668;
    fVar10 = (fVar10 - ((float10)local_7c * (float10)*(float *)(param_1 + 0x2c0) * (float10)local_7c
                       ) / (float10)*(float *)(param_1 + 0x170)) * (float10)0.016666668;
    local_70 = (float)(((float10)_K_HALF * fVar10 + (float10)local_7c) * (float10)0.016666668 +
                      (float10)local_70);
    local_7c = (float)(fVar10 + (float10)local_7c);
    if ((*(float *)(param_1 + 0x438) == 0.0) && (60.0 <= local_7c * 2.237)) {
      *(float *)(param_1 + 0x438) = local_74 * 1.2;
    }
    if ((*(float *)(param_1 + 0x43c) == 0.0) && (400.5 <= local_70)) {
      *(float *)(param_1 + 0x43c) = local_74;
      *(float *)(param_1 + 0x440) = local_7c;
    }
  } while (((*(float *)(param_1 + 0x438) == 0.0) || (*(float *)(param_1 + 0x43c) == 0.0)) ||
          (*(float *)(param_1 + 0x440) == 0.0));
  return;
}


// ==== 0x5808e0 FUN_005808e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005808e0(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (*(char *)(in_EAX + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar1 = *(float *)(in_EAX + 0x428) - _DAT_006f0d58;
  fVar2 = _DAT_006f0d5c - _DAT_006f0d58;
  if (*(char *)(unaff_ESI + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar1 = ((*(float *)(unaff_ESI + 0x428) - _DAT_006f0d58) * 10.0) / (_DAT_006f0d5c - _DAT_006f0d58)
          - (fVar1 * 10.0) / fVar2;
  if (fVar1 < -2.5) {
    return 0xfffffffe;
  }
  if (fVar1 < -0.5) {
    return 0xffffffff;
  }
  if (fVar1 < _K_HALF) {
    return 0;
  }
  uVar3 = 1;
  if (2.5 <= fVar1) {
    uVar3 = 2;
  }
  return uVar3;
}


// ==== 0x5809c0 DriverInfo::DriverInfo

/* [canon] traffic med (G) docs/re/traffic.md */

void DriverInfo__DriverInfo
               (undefined1 param_1,undefined4 param_2,undefined4 param_3,int param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  char cVar1;
  char *pcVar2;
  undefined1 *unaff_ESI;
  int iVar3;
  
  RideInfo__Init();
  unaff_ESI[1] = param_1;
  *unaff_ESI = 0;
  unaff_ESI[3] = param_7;
  *(undefined4 *)(unaff_ESI + 4) = param_2;
  RideInfo__operator_(unaff_ESI + 0x10,param_3);
  unaff_ESI[0x735] = param_5;
  pcVar2 = unaff_ESI + 0x73c;
  unaff_ESI[0x736] = param_6;
  unaff_ESI[0x734] = 0;
  *(undefined4 *)(unaff_ESI + 0x738) = 0;
  iVar3 = 0x10;
  param_4 = param_4 - (int)pcVar2;
  do {
    cVar1 = pcVar2[param_4];
    iVar3 = iVar3 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    pcVar2 = pcVar2 + 1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x580a40 FUN_00580a40

void FUN_00580a40(void)

{
  int iVar1;
  int in_EAX;
  char cVar2;
  int unaff_EDI;
  
  FUN_00571ea0(0,"DriverInfo");
  FUN_00571c20(in_EAX,unaff_EDI,1,1,1);
  FUN_00571c20(in_EAX,unaff_EDI + 1,1,1,1);
  FUN_00571c20(in_EAX,unaff_EDI + 0x735,1,1,1);
  FUN_00571c20(in_EAX,unaff_EDI + 3,1,1,1);
  FUN_00571c20(in_EAX,unaff_EDI + 4,1,4,1);
  FUN_00571c20(in_EAX,unaff_EDI + 0x738,4,0xffffffff,0);
  FUN_0057d200();
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar1 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x580af0 FUN_00580af0

int FUN_00580af0(void)

{
  int in_EAX;
  
  return in_EAX + 0x73c;
}


// ==== 0x580b00 GetUsedCarTextureInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GetUsedCarTextureInfo(int *param_1,int *param_2,int *param_3)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  byte *pbVar14;
  int iVar15;
  char *pcVar16;
  undefined *puVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int *piVar21;
  bool bVar22;
  int local_58;
  int local_54;
  int local_50;
  byte local_40;
  byte local_3f [63];
  
  iVar11 = *param_2 * 0xc90 + 0x20 + DAT_00734588;
  piVar21 = param_1;
  for (iVar13 = 0x11d; iVar13 != 0; iVar13 = iVar13 + -1) {
    *piVar21 = 0;
    piVar21 = piVar21 + 1;
  }
  FUN_00565da0("%s_SKIN1",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar13 = iVar13 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  param_1[0xf2] = iVar13;
  FUN_00565da0("%s_SKIN1B",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar13 = iVar13 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  param_1[0xf3] = iVar13;
  pcVar16 = "GLOBAL_SKIN1";
  iVar13 = -1;
  uVar19 = 0x47;
  do {
    iVar13 = iVar13 * 0x21 + uVar19;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar19 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xf4] = iVar13;
  iVar13 = param_2[0x124];
  if (iVar13 == 0) {
    param_1[0xf5] = 0;
  }
  else {
    piVar4 = *(int **)(iVar13 + 0x14);
    piVar21 = piVar4 + *(short *)(iVar13 + 0x1c) * 2;
    if (piVar4 != (int *)0x0) {
      for (; piVar4 < piVar21; piVar4 = piVar4 + 2) {
        if (*piVar4 == 0x10c98090) {
          if (piVar4 != (int *)0x0) {
            iVar13 = piVar4[1];
            goto LAB_00580c01;
          }
          break;
        }
      }
    }
    iVar13 = 0;
LAB_00580c01:
    puVar17 = &DAT_006ba148;
    uVar19 = 0x5f;
    do {
      iVar13 = iVar13 * 0x21 + uVar19;
      pbVar14 = puVar17 + 1;
      uVar19 = (uint)*pbVar14;
      puVar17 = puVar17 + 1;
    } while (*pbVar14 != 0);
    param_1[0xf5] = iVar13;
  }
  if (param_2[0x111] == 0) {
    param_1[0x106] = param_1[0xf2];
    param_1[0x109] = 0;
  }
  else {
    param_1[0x106] = param_2[0x111];
    param_1[0x109] = param_2[0x112];
  }
  iVar13 = param_1[0x106];
  param_1[0x107] = 0;
  param_1[0x108] = iVar13;
  if (param_2[0x111] == 0) {
    bVar22 = iVar13 != 0;
    if (bVar22) {
      *param_1 = iVar13;
    }
    uVar19 = (uint)bVar22;
    iVar13 = param_1[0x107];
    if (iVar13 != 0) {
      iVar5 = 0;
      if (uVar19 != 0) {
        do {
          if (param_1[iVar5] == iVar13) {
            uVar8 = 0;
            goto LAB_00580cc6;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)uVar19);
      }
      uVar8 = uVar19;
      if (bVar22 < 0x78) {
        param_1[uVar19] = iVar13;
        uVar8 = 1;
      }
LAB_00580cc6:
      uVar19 = uVar19 + uVar8;
    }
  }
  else {
    *param_1 = param_2[0x111];
    uVar19 = 1;
  }
  iVar13 = param_2[0x112];
  if (iVar13 != 0) {
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) goto LAB_00580ceb;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
LAB_00580ce2:
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
    goto LAB_00580d14;
  }
  iVar13 = param_1[0x109];
  if (iVar13 != 0) {
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) goto LAB_00580ceb;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
    goto LAB_00580ce2;
  }
LAB_00580d16:
  iVar6 = GetTempCarSkinTextures(param_1 + 0x78,0x78,param_2);
  iVar13 = param_2[0x121];
  iVar5 = param_2[0x120];
  FUN_00565da0("%s_HEADLIGHT",iVar11);
  iVar7 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar7 = iVar7 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  FUN_00565da0("%s_BRAKELIGHT",iVar11);
  local_58 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    local_58 = local_58 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  if (iVar5 != 0) {
    piVar4 = *(int **)(iVar5 + 0x14);
    piVar21 = piVar4 + *(short *)(iVar5 + 0x1c) * 2;
    if (piVar4 != (int *)0x0) {
      for (; piVar4 < piVar21; piVar4 = piVar4 + 2) {
        if (*piVar4 == 0x10c98090) {
          if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
            iVar7 = CarPart__GetNameAttribute();
          }
          break;
        }
      }
    }
  }
  if (iVar13 != 0) {
    piVar4 = *(int **)(iVar13 + 0x14);
    piVar21 = piVar4 + *(short *)(iVar13 + 0x1c) * 2;
    if (piVar4 != (int *)0x0) {
      for (; piVar4 < piVar21; piVar4 = piVar4 + 2) {
        if (*piVar4 == 0x10c98090) {
          if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
            local_58 = CarPart__GetNameAttribute();
          }
          break;
        }
      }
    }
  }
  puVar17 = &DAT_006ba120;
  uVar8 = 0x5f;
  iVar13 = iVar7;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_1[0xf8] = iVar13;
  pcVar16 = "_RIGHT";
  uVar8 = 0x5f;
  iVar13 = iVar7;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xf9] = iVar13;
  pcVar16 = "_GLASS_LEFT";
  uVar8 = 0x5f;
  iVar13 = iVar7;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xfd] = iVar13;
  pcVar16 = "_GLASS_RIGHT";
  uVar8 = 0x5f;
  iVar13 = iVar7;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xfe] = iVar13;
  puVar17 = &DAT_006ba120;
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_1[0xfa] = iVar13;
  pcVar16 = "_RIGHT";
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xfb] = iVar13;
  pcVar16 = "_CENTRE";
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xfc] = iVar13;
  pcVar16 = "_GLASS_LEFT";
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0xff] = iVar13;
  pcVar16 = "_GLASS_RIGHT";
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x100] = iVar13;
  pcVar16 = "_GLASS_CENTRE";
  uVar8 = 0x5f;
  iVar13 = local_58;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x101] = iVar13;
  param_1[0x102] = 0;
  puVar17 = &DAT_006ba0dc;
  uVar8 = 0x5f;
  iVar13 = iVar7;
  do {
    pbVar14 = puVar17 + 1;
    iVar13 = iVar13 * 0x21 + uVar8;
    puVar17 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
  } while (*pbVar14 != 0);
  param_1[0x10b] = iVar13;
  puVar17 = &DAT_006ba0d8;
  uVar8 = 0x5f;
  iVar5 = iVar7;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_1[0x10c] = iVar5;
  pcVar16 = "_DAMAGE0";
  uVar8 = 0x5f;
  iVar5 = iVar7;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x10d] = iVar5;
  pcVar16 = "_GLASS_OFF";
  uVar8 = 0x5f;
  iVar5 = iVar7;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x10e] = iVar5;
  pcVar16 = "_GLASS_ON";
  uVar8 = 0x5f;
  iVar5 = iVar7;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x10f] = iVar5;
  pcVar16 = "_GLASS_DAMAGE0";
  uVar8 = 0x5f;
  do {
    iVar7 = iVar7 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x110] = iVar7;
  puVar17 = &DAT_006ba0dc;
  uVar8 = 0x5f;
  iVar5 = local_58;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_1[0x111] = iVar5;
  puVar17 = &DAT_006ba0d8;
  uVar8 = 0x5f;
  iVar5 = local_58;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_1[0x112] = iVar5;
  pcVar16 = "_DAMAGE0";
  uVar8 = 0x5f;
  iVar5 = local_58;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x113] = iVar5;
  pcVar16 = "_GLASS_OFF";
  uVar8 = 0x5f;
  iVar5 = local_58;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x114] = iVar5;
  pcVar16 = "_GLASS_ON";
  uVar8 = 0x5f;
  iVar5 = local_58;
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  param_1[0x115] = iVar5;
  pcVar16 = "_GLASS_DAMAGE0";
  uVar8 = 0x5f;
  do {
    local_58 = local_58 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  uVar8 = 0;
  param_1[0x116] = local_58;
  param_1[0x117] = 0;
  param_1[0x118] = 0;
  param_1[0x119] = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581143;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581143:
  iVar13 = param_1[0x10c];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581174;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581174:
  iVar13 = param_1[0x10d];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_005811a5;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_005811a5:
  iVar13 = param_1[0x10e];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_005811d6;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_005811d6:
  iVar13 = param_1[0x10f];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581207;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581207:
  iVar13 = param_1[0x110];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_0058123f;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_0058123f:
  iVar13 = param_1[0x111];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581270;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581270:
  iVar13 = param_1[0x112];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_005812a1;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_005812a1:
  iVar13 = param_1[0x113];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_005812d2;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_005812d2:
  iVar13 = param_1[0x114];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581303;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581303:
  iVar13 = param_1[0x115];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581334;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581334:
  iVar13 = param_1[0x116];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_00581365;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_00581365:
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_INTERIOR",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    pbVar1 = pbVar14 + 1;
    iVar13 = iVar13 * 0x21 + (uint)bVar3;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  FUN_00565da0("%s_BADGING",iVar11);
  iVar5 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  FUN_00565da0("%s_BADGING_EU",iVar11);
  iVar7 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    pbVar1 = pbVar14 + 1;
    iVar7 = iVar7 * 0x21 + (uint)bVar3;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  FUN_00565da0("%s_LICENSE_PLATE",iVar11);
  iVar9 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar9 = iVar9 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  param_1[0x105] = iVar9;
  uVar8 = 0;
  param_1[0xf6] = iVar5;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_0058147f;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_0058147f:
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar5 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar5) {
          uVar8 = 0;
          goto LAB_005814af;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar5;
      uVar8 = 1;
    }
  }
LAB_005814af:
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar7 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar7) {
          uVar8 = 0;
          goto LAB_005814df;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar7;
      uVar8 = 1;
    }
  }
LAB_005814df:
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_SIDELIGHT",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  if (local_40 == 0) {
LAB_0058152a:
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) {
          uVar8 = 0;
          goto LAB_00581553;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
  else {
    do {
      iVar13 = iVar13 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar14 + 1;
      pbVar14 = pbVar14 + 1;
      bVar3 = *pbVar1;
    } while (*pbVar1 != 0);
    if (iVar13 != 0) goto LAB_0058152a;
    uVar8 = 0;
  }
LAB_00581553:
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_DOOR_HANDLE",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  if (local_40 == 0) {
LAB_0058158e:
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) goto LAB_0058158a;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
  else {
    do {
      iVar13 = iVar13 * 0x21 + (uint)bVar3;
      bVar3 = pbVar14[1];
      pbVar14 = pbVar14 + 1;
    } while (bVar3 != 0);
    if (iVar13 != 0) goto LAB_0058158e;
LAB_0058158a:
    uVar8 = 0;
  }
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_LOGO",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  if (local_40 == 0) {
LAB_005815ea:
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) goto LAB_005815e6;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
  else {
    do {
      iVar13 = iVar13 * 0x21 + (uint)bVar3;
      bVar3 = pbVar14[1];
      pbVar14 = pbVar14 + 1;
    } while (bVar3 != 0);
    if (iVar13 != 0) goto LAB_005815ea;
LAB_005815e6:
    uVar8 = 0;
  }
  uVar19 = uVar19 + uVar8;
  puVar10 = &DAT_006bdcf8;
  if (param_3 == (int *)0x0) {
    puVar10 = &DAT_006bdcfc;
  }
  FUN_00565da0("%s_SHADOW%s",iVar11,puVar10);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar13 = iVar13 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  param_1[0x11c] = iVar13;
  if (iVar13 == 0) {
LAB_0058165f:
    uVar8 = 0;
  }
  else {
    iVar5 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar5] == iVar13) goto LAB_0058165f;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_NEON",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  if (local_40 != 0) {
    do {
      iVar13 = iVar13 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar14 + 1;
      pbVar14 = pbVar14 + 1;
      bVar3 = *pbVar1;
    } while (*pbVar1 != 0);
    if (iVar13 == 0) {
LAB_005816c4:
      uVar8 = 0;
      goto LAB_005816ed;
    }
  }
  iVar5 = 0;
  if (uVar19 != 0) {
    do {
      if (param_1[iVar5] == iVar13) goto LAB_005816c4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar19);
  }
  uVar8 = uVar19;
  if (uVar19 < 0x78) {
    param_1[uVar19] = iVar13;
    uVar8 = 1;
  }
LAB_005816ed:
  uVar19 = uVar19 + uVar8;
  FUN_00565da0("%s_TIRE",iVar11);
  iVar13 = -1;
  pbVar14 = &local_40;
  bVar3 = local_40;
  while (bVar3 != 0) {
    iVar13 = iVar13 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    bVar3 = *pbVar1;
  }
  param_1[0x103] = iVar13;
  FUN_00565da0("%s_WHEEL_BLUR",iVar11);
  iVar11 = -1;
  pbVar14 = &local_40;
  while (local_40 != 0) {
    iVar11 = iVar11 * 0x21 + (uint)local_40;
    pbVar1 = pbVar14 + 1;
    pbVar14 = pbVar14 + 1;
    local_40 = *pbVar1;
  }
  iVar13 = param_1[0x103];
  param_1[0x104] = iVar11;
  param_1[0x11b] = iVar11;
  uVar8 = 0;
  param_1[0x11a] = iVar13;
  if (iVar13 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar13) {
          uVar8 = 0;
          goto LAB_005817a5;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar13;
      uVar8 = 1;
    }
  }
LAB_005817a5:
  iVar11 = param_1[0x11b];
  uVar19 = uVar19 + uVar8;
  uVar8 = 0;
  if (iVar11 != 0) {
    if (uVar19 != 0) {
      do {
        if (param_1[uVar8] == iVar11) {
          uVar8 = 0;
          goto LAB_005817d6;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar11;
      uVar8 = 1;
    }
  }
LAB_005817d6:
  uVar19 = uVar19 + uVar8;
  if (((param_3 != (int *)0x0) && (param_2[0x11f] != 0)) &&
     (iVar11 = CarPart__GetNameAttribute(), iVar11 != 0)) {
    iVar13 = 0;
    if (uVar19 != 0) {
      do {
        if (param_1[iVar13] == iVar11) {
          uVar8 = 0;
          goto LAB_0058181f;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)uVar19);
    }
    uVar8 = uVar19;
    if (uVar19 < 0x78) {
      param_1[uVar19] = iVar11;
      uVar8 = 1;
    }
LAB_0058181f:
    uVar19 = uVar19 + uVar8;
  }
  puVar17 = &DAT_006bbc5c;
  iVar11 = -1;
  uVar8 = 0x53;
  do {
    iVar11 = iVar11 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  puVar17 = &DAT_006bbc54;
  iVar13 = -1;
  uVar8 = 0x53;
  do {
    iVar13 = iVar13 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  puVar17 = &DAT_006bbc4c;
  do {
    pcVar16 = puVar17 + 1;
    puVar17 = puVar17 + 1;
  } while (*pcVar16 != '\0');
  pcVar16 = "MEDIUM";
  do {
    pcVar2 = pcVar16 + 1;
    pcVar16 = pcVar16 + 1;
  } while (*pcVar2 != '\0');
  pcVar16 = "LARGE";
  do {
    pcVar2 = pcVar16 + 1;
    pcVar16 = pcVar16 + 1;
  } while (*pcVar2 != '\0');
  uVar8 = 0x53;
  iVar5 = -1;
  pcVar16 = "SQUARE";
  do {
    iVar5 = iVar5 * 0x21 + uVar8;
    pbVar14 = (byte *)(pcVar16 + 1);
    uVar8 = (uint)*pbVar14;
    pcVar16 = pcVar16 + 1;
  } while (*pbVar14 != 0);
  puVar17 = &DAT_006bbc3c;
  iVar7 = -1;
  uVar8 = 0x52;
  do {
    iVar7 = iVar7 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  puVar17 = &DAT_006bbc34;
  iVar9 = -1;
  uVar8 = 0x57;
  do {
    iVar9 = iVar9 * 0x21 + uVar8;
    pbVar14 = puVar17 + 1;
    uVar8 = (uint)*pbVar14;
    puVar17 = puVar17 + 1;
  } while (*pbVar14 != 0);
  param_3 = param_2 + 0x14e;
  local_50 = 7;
  param_2 = param_2 + 0x126;
  do {
    iVar18 = *param_2;
    if (iVar18 != 0) {
      iVar20 = (int)*(short *)(iVar18 + 0x1c);
      piVar21 = *(int **)(iVar18 + 0x14);
      piVar4 = piVar21;
      if (piVar21 != (int *)0x0) {
        for (; piVar4 < piVar21 + iVar20 * 2; piVar4 = piVar4 + 2) {
          if ((iVar11 == 0) || (*piVar4 == iVar11)) {
            if ((piVar4 != (int *)0x0) && (piVar4 = piVar21, piVar21 != (int *)0x0))
            goto joined_r0x0058197c;
            break;
          }
        }
      }
    }
LAB_00581ae7:
    param_2 = param_2 + 1;
    param_3 = param_3 + 8;
    local_50 = local_50 + -1;
    if (local_50 == 0) {
      param_1[0xf0] = uVar19;
      param_1[0xf1] = iVar6;
      return;
    }
  } while( true );
LAB_00580ceb:
  uVar8 = 0;
LAB_00580d14:
  uVar19 = uVar19 + uVar8;
  goto LAB_00580d16;
joined_r0x0058197c:
  if (piVar4 < piVar21 + iVar20 * 2) {
    if ((iVar13 != 0) && (*piVar4 != iVar13)) goto code_r0x0058198e;
    if (piVar4 != (int *)0x0) {
      piVar4 = piVar21;
      if (piVar21 != (int *)0x0) {
        for (; ((piVar4 < piVar21 + iVar20 * 2 && (iVar11 != 0)) && (*piVar4 != iVar11));
            piVar4 = piVar4 + 2) {
        }
      }
      piVar4 = piVar21 + iVar20 * 2;
      if (piVar21 == (int *)0x0) {
LAB_005819e4:
        iVar18 = 0;
      }
      else {
        while( true ) {
          if (piVar4 <= piVar21) goto LAB_005819e4;
          if ((iVar13 == 0) || (*piVar21 == iVar13)) break;
          piVar21 = piVar21 + 2;
        }
        if (piVar21 == (int *)0x0) goto LAB_005819e4;
        iVar18 = piVar21[1];
      }
      local_54 = 8;
      piVar21 = param_3;
      do {
        iVar20 = *piVar21;
        if (iVar20 != 0) {
          puVar17 = &DAT_006bd3bc;
          iVar15 = -1;
          uVar8 = 0x4e;
          do {
            iVar15 = iVar15 * 0x21 + uVar8;
            pbVar14 = puVar17 + 1;
            uVar8 = (uint)*pbVar14;
            puVar17 = puVar17 + 1;
          } while (*pbVar14 != 0);
          piVar12 = *(int **)(iVar20 + 0x14);
          piVar4 = piVar12 + *(short *)(iVar20 + 0x1c) * 2;
          if (piVar12 != (int *)0x0) {
            for (; piVar12 < piVar4; piVar12 = piVar12 + 2) {
              if ((iVar15 == 0) || (*piVar12 == iVar15)) {
                if (piVar12 != (int *)0x0) {
                  iVar20 = piVar12[1];
                  goto LAB_00581a39;
                }
                break;
              }
            }
          }
          iVar20 = 0;
LAB_00581a39:
          if (iVar18 == iVar5) {
            pcVar16 = "_SQUARE";
            uVar8 = 0x5f;
            do {
              iVar20 = iVar20 * 0x21 + uVar8;
              pbVar14 = (byte *)(pcVar16 + 1);
              uVar8 = (uint)*pbVar14;
              pcVar16 = pcVar16 + 1;
            } while (*pbVar14 != 0);
          }
          else if (iVar18 == iVar7) {
            pcVar16 = "_RECT";
            uVar8 = 0x5f;
            do {
              iVar20 = iVar20 * 0x21 + uVar8;
              pbVar14 = (byte *)(pcVar16 + 1);
              uVar8 = (uint)*pbVar14;
              pcVar16 = pcVar16 + 1;
            } while (*pbVar14 != 0);
          }
          else if (iVar18 == iVar9) {
            puVar17 = &DAT_006bbc1c;
            uVar8 = 0x5f;
            do {
              iVar20 = iVar20 * 0x21 + uVar8;
              pbVar14 = puVar17 + 1;
              uVar8 = (uint)*pbVar14;
              puVar17 = puVar17 + 1;
            } while (*pbVar14 != 0);
          }
          if (iVar20 == 0) {
LAB_00581aaa:
            uVar8 = 0;
          }
          else {
            iVar15 = 0;
            if (0 < (int)uVar19) {
              do {
                if (param_1[iVar15] == iVar20) goto LAB_00581aaa;
                iVar15 = iVar15 + 1;
              } while (iVar15 < (int)uVar19);
            }
            uVar8 = uVar19;
            if ((int)uVar19 < 0x78) {
              param_1[uVar19] = iVar20;
              uVar8 = 1;
            }
          }
          uVar19 = uVar19 + uVar8;
        }
        piVar21 = piVar21 + 1;
        local_54 = local_54 + -1;
      } while (local_54 != 0);
    }
  }
  goto LAB_00581ae7;
code_r0x0058198e:
  piVar4 = piVar4 + 2;
  goto joined_r0x0058197c;
}


